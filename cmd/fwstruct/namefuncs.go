package main

import (
	"context"
	"encoding/json"
	"flag"
	"fmt"
	"os"
	"path/filepath"
	"sort"
	"strings"
	"sync"
	"time"

	"aic8800d80/internal/llm"
)

type LLMName struct {
	Image     string `json:"image"`
	Address   string `json:"address"`
	Name      string `json:"name"`
	Docstring string `json:"docstring"`
}

func loadLLMNames(path string) (map[string]*LLMName, error) {
	b, err := os.ReadFile(path)
	if err != nil {
		if os.IsNotExist(err) {
			return make(map[string]*LLMName), nil
		}
		return nil, err
	}
	out := make(map[string]*LLMName)
	var dict map[string]struct {
		Name      string `json:"name"`
		Docstring string `json:"docstring"`
	}
	if err := json.Unmarshal(b, &dict); err == nil {
		for k, v := range dict {
			parts := strings.SplitN(k, "|", 2)
			if len(parts) != 2 {
				continue
			}
			out[k] = &LLMName{Image: parts[0], Address: parts[1], Name: v.Name, Docstring: v.Docstring}
		}
		return out, nil
	}
	for _, line := range strings.Split(string(b), "\n") {
		line = strings.TrimSpace(line)
		if line == "" {
			continue
		}
		var v struct {
			Key       string `json:"key"`
			Image     string `json:"image"`
			Address   string `json:"address"`
			Name      string `json:"name"`
			Docstring string `json:"docstring"`
		}
		if err := json.Unmarshal([]byte(line), &v); err != nil {
			continue
		}
		key := v.Key
		if key == "" {
			key = v.Image + "|" + v.Address
		}
		out[key] = &LLMName{Image: v.Image, Address: v.Address, Name: v.Name, Docstring: v.Docstring}
	}
	return out, nil
}

// batchNamePrompt asks the LLM to name a batch of N functions.
// Returns JSON: [{"name":"...", "docstring":"..."}, ...]
const batchNamePrompt = "Output JSON only, no markdown, no thinking. For each numbered ARM firmware function below, give a snake_case name. Be concise. Format: [{\"name\":\"...\"},...]\n\n%s"

func nameBatch(ctx context.Context, c *llm.Client, bodies []string) ([]string, error) {
	var sb strings.Builder
	for i, body := range bodies {
		if len(body) > 800 {
			body = body[:800] + "..."
		}
		fmt.Fprintf(&sb, "%d. %s\n\n", i+1, body)
	}
	prompt := fmt.Sprintf(batchNamePrompt, sb.String())
	resp, err := c.Call(ctx,
		"Reply with JSON only, no thinking.",
		prompt,
		true,
	)
	if err != nil {
		return nil, err
	}
	// Find JSON array in response
	if i := strings.Index(resp, "["); i >= 0 {
		if j := strings.LastIndex(resp, "]"); j > i {
			candidate := resp[i : j+1]
			var arr []map[string]string
			if err := json.Unmarshal([]byte(candidate), &arr); err == nil {
				names := make([]string, len(bodies))
				for k, v := range arr {
					if k >= len(names) {
						break
					}
					names[k] = strings.Trim(v["name"], "\" '")
				}
				return names, nil
			}
		}
	}
	return nil, fmt.Errorf("could not parse JSON from response: %s", resp[:min(200, len(resp))])
}

func runNameFuncs(args []string) error {
	fs := flag.NewFlagSet("namefuncs", flag.ContinueOnError)
	var cf commonFlags
	cf.Register(fs)
	var (
		llmKeyFile  string
		model       string
		concurrency int
		batchSize   int
		force       bool
	)
	fs.StringVar(&llmKeyFile, "llm-keys", "harness_v15/keys/keys.json", "LLM keys JSON file")
	fs.StringVar(&model, "llm-model", llm.Model, "LLM model name")
	fs.IntVar(&concurrency, "concurrency", 6, "parallel LLM calls")
	fs.IntVar(&batchSize, "batch-size", 10, "functions per LLM call")
	fs.BoolVar(&force, "force", false, "re-name even functions that already have a name")
	if err := fs.Parse(args); err != nil {
		return err
	}
	if err := cf.Resolve(); err != nil {
		return err
	}
	images, err := cf.SelectedImages()
	if err != nil {
		return err
	}
	keys, err := llm.LoadKeysFromJSONConfig(llmKeyFile)
	if err != nil {
		return fmt.Errorf("load keys: %w", err)
	}
	if len(keys) == 0 {
		return fmt.Errorf("no keys in %s", llmKeyFile)
	}
	cfg := llm.DefaultConfig()
	cfg.Keys = keys
	cfg.Model = model
	cfg.MaxTokens = 1500
	cfg.Temperature = 0.0
	client := llm.NewClient(&cfg)

	existing, err := loadLLMNames(filepath.Join(cf.Out, "llm_names.json"))
	if err != nil {
		return err
	}
	fmt.Fprintf(os.Stderr, "namefuncs: loaded %d existing names\n", len(existing))

	type target struct {
		image   string
		address string
		body    string
		key     string
	}
	var targets []target
	for _, img := range images {
		jsonl := filepath.Join(cf.Out, img+"_funcs.jsonl")
		b, err := os.ReadFile(jsonl)
		if err != nil {
			fmt.Fprintf(os.Stderr, "skip %s: %v\n", img, err)
			continue
		}
		decDir := filepath.Join(cf.Root, "harness_v19", "decompiled", img)
		for _, line := range strings.Split(string(b), "\n") {
			line = strings.TrimSpace(line)
			if line == "" {
				continue
			}
			var f struct {
				Name string `json:"name"`
				Addr int    `json:"address"`
			}
			if err := json.Unmarshal([]byte(line), &f); err != nil {
				continue
			}
			if !strings.HasPrefix(f.Name, "sub_") {
				continue
			}
			addrStr := fmt.Sprintf("0x%x", f.Addr)
			key := img + "|" + addrStr
			if !force {
				if e, ok := existing[key]; ok && e.Name != "" && !strings.HasPrefix(e.Name, "sub_") {
					continue
				}
			}
			cfName := fmt.Sprintf("%x_%s.c", f.Addr, f.Name)
			cPath := filepath.Join(decDir, cfName)
			body, err := os.ReadFile(cPath)
			if err != nil {
				fmt.Fprintf(os.Stderr, "  skip %s: %v\n", cPath, err)
				continue
			}
			targets = append(targets, target{image: img, address: addrStr, body: string(body), key: key})
		}
	}
	fmt.Fprintf(os.Stderr, "namefuncs: %d targets to name, batch_size=%d\n", len(targets), batchSize)

	// Build batches
	type batch struct {
		bodies []string
		tgts   []target
	}
	var batches []batch
	for i := 0; i < len(targets); i += batchSize {
		end := i + batchSize
		if end > len(targets) {
			end = len(targets)
		}
		bodies := make([]string, end-i)
		tgts := make([]target, end-i)
		for j := i; j < end; j++ {
			bodies[j-i] = targets[j].body
			tgts[j-i] = targets[j]
		}
		batches = append(batches, batch{bodies: bodies, tgts: tgts})
	}
	fmt.Fprintf(os.Stderr, "namefuncs: %d batches\n", len(batches))

	ctx := context.Background()
	var (
		mu      sync.Mutex
		results = make(map[string]*LLMName)
		wg      sync.WaitGroup
	)
	jobs := make(chan batch)
	for w := 0; w < concurrency; w++ {
		wg.Add(1)
		go func() {
			defer wg.Done()
			for b := range jobs {
				cctx, cancel := context.WithTimeout(ctx, 90*time.Second)
				names, err := nameBatch(cctx, client, b.bodies)
				cancel()
				if err != nil {
					fmt.Fprintf(os.Stderr, "  batch err: %v\n", err)
					continue
				}
				mu.Lock()
				for k, t := range b.tgts {
					if k >= len(names) {
						break
					}
					n := names[k]
					if n == "" {
						continue
					}
					results[t.key] = &LLMName{Image: t.image, Address: t.address, Name: n}
					existing[t.key] = results[t.key]
				}
				mu.Unlock()
				fmt.Fprintf(os.Stderr, "  batch done: %d names\n", len(names))
			}
		}()
	}
	for _, b := range batches {
		jobs <- b
	}
	close(jobs)
	wg.Wait()

	outPath := filepath.Join(cf.Out, "llm_names.json")
	var keys2 []string
	for k := range existing {
		keys2 = append(keys2, k)
	}
	sort.Strings(keys2)
	out := make(map[string]any)
	for _, k := range keys2 {
		v := existing[k]
		out[k] = map[string]string{"name": v.Name, "docstring": v.Docstring}
	}
	b, _ := json.MarshalIndent(out, "", "  ")
	if err := os.WriteFile(outPath, b, 0644); err != nil {
		return err
	}
	fmt.Fprintf(os.Stderr, "namefuncs: wrote %d names to %s\n", len(existing), outPath)
	return nil
}
