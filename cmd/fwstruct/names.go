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

	"aic8800d80/internal/fileio"
	"aic8800d80/internal/llm"
	"aic8800d80/internal/structs"
)

// clusterReport is the deserialized shape of <img>_clusters.json.
type clusterReport struct {
	Image        string             `json:"image"`
	TotalFuncs   int                `json:"total_funcs"`
	Clustered    int                `json:"clustered"`
	ClusterCount int                `json:"cluster_count"`
	Clusters     []*structs.Cluster `json:"clusters"`
	FuncMap      map[string]int     `json:"func_map"`
}

// readJSON is a small helper.
func readJSON(path string, v any) error {
	b, err := os.ReadFile(path)
	if err != nil {
		return err
	}
	return json.Unmarshal(b, v)
}

// runNames sends proposed struct clusters to the LLM for naming.
func runNames(args []string) error {
	fs := flag.NewFlagSet("names", flag.ContinueOnError)
	var cf commonFlags
	cf.Register(fs)
	var keyDir, keysFile, endpoint, model, reasoningEffort string
	var concurrency, maxClusters int
	var skipNamed bool
	fs.StringVar(&keyDir, "llm-key-dir", "", "directory of *.key files for LLM API")
	fs.StringVar(&keysFile, "llm-keys", "", "path to keys.json (default: <root>/harness_v15/keys/keys.json)")
	fs.StringVar(&endpoint, "llm-endpoint", llm.Endpoint, "LLM chat completions endpoint")
	fs.StringVar(&model, "llm-model", llm.Model, "LLM model name")
	fs.StringVar(&reasoningEffort, "llm-reasoning-effort", llm.ReasoningEffort, "LLM reasoning_effort level")
	fs.IntVar(&concurrency, "concurrency", 16, "parallel LLM calls")
	fs.IntVar(&maxClusters, "max-clusters", 0, "max clusters to name (0 = all)")
	fs.BoolVar(&skipNamed, "skip-named", false, "skip clusters that already have a non-placeholder name")
	if err := fs.Parse(args); err != nil {
		return err
	}
	if err := cf.Resolve(); err != nil {
		return err
	}
	setFlags := map[string]bool{}
	fs.Visit(func(f *flag.Flag) { setFlags[f.Name] = true })
	images, err := cf.SelectedImages()
	if err != nil {
		return err
	}

	// Set up LLM client (precedence: --llm-key-dir > env > keys.json)
	cfg := llm.DefaultConfig()
	if keyDir != "" {
		if keys, err := llm.LoadKeysFromDir(keyDir); err == nil {
			cfg.Keys = keys
		}
	}
	if len(cfg.Keys) == 0 {
		cfg.Keys = llm.LoadKeysFromEnv()
	}
	if len(cfg.Keys) == 0 {
		kpath := keysFile
		if kpath == "" {
			kpath = filepath.Join(cf.Root, "harness_v15", "keys", "keys.json")
		}
		if jcfg, err := llm.LoadConfigFromKeysJSON(kpath); err == nil && len(jcfg.Keys) > 0 {
			cfg = jcfg
		}
	}
	if setFlags["llm-endpoint"] {
		cfg.Endpoint = endpoint
	}
	if setFlags["llm-model"] {
		cfg.Model = model
	}
	if setFlags["llm-reasoning-effort"] {
		cfg.ReasoningEffort = reasoningEffort
	}
	if len(cfg.Keys) == 0 {
		cf.VPrintf("names: no LLM keys found, running deterministic struct naming (fingerprint/semantic-root heuristic)")
		return runDeterministicNames(cf, images)
	}
	client := llm.New(cfg)
	cf.VPrintf("names: %d keys, model=%s, effort=%s, concurrency=%d", len(cfg.Keys), cfg.Model, cfg.ReasoningEffort, concurrency)

	// Collect all cluster candidates
	type candidate struct {
		image   string
		group   int
		cluster *structs.Cluster
	}
	var candidates []candidate
	clusterReports := map[string]*clusterReport{}
	existingNamed := map[string]map[int]map[string]any{}
	for _, img := range images {
		var rep clusterReport
		p := filepath.Join(cf.Out, img+"_clusters.json")
		if err := readJSON(p, &rep); err != nil {
			fmt.Fprintf(os.Stderr, "  %s: %v\n", img, err)
			continue
		}
		clusterReports[img] = &rep
		if skipNamed {
			var prev []map[string]any
			if err := readJSON(filepath.Join(cf.Out, img+"_named.json"), &prev); err == nil {
				m := map[int]map[string]any{}
				for _, e := range prev {
					if g, ok := e["group"].(float64); ok {
						m[int(g)] = e
					}
				}
				existingNamed[img] = m
			}
		}
		for _, c := range rep.Clusters {
			if skipNamed && c.Name != "" && !strings.HasPrefix(c.Name, "struct_shape_") {
				continue
			}
			candidates = append(candidates, candidate{image: img, group: c.GroupID, cluster: c})
		}
	}
	if maxClusters > 0 && len(candidates) > maxClusters {
		sort.Slice(candidates, func(i, j int) bool {
			return candidates[i].cluster.Confidence > candidates[j].cluster.Confidence
		})
		candidates = candidates[:maxClusters]
	}
	cf.VPrintf("  %d cluster candidates across %d images", len(candidates), len(images))

	// Run LLM in parallel (no time limits). Warm up the static system prompt
	// cache on candidate[0] before fanning out so parallel workers hit cache.
	type result struct {
		image    string
		group    int
		proposal *llm.StructProposal
		err      error
	}
	results := make([]result, len(candidates))
	ctx := context.Background()
	runOne := func(i int, c candidate) {
		in := buildNamingInput(c.image, c.cluster)
		prop, err := llm.NameStruct(ctx, client, in)
		results[i] = result{image: c.image, group: c.group, proposal: prop, err: err}
		if err != nil {
			cf.VPrintf("  %s/%d: %v", c.image, c.group, err)
		} else {
			cf.VPrintf("  %s/%d: %s", c.image, c.group, prop.StructName)
		}
	}
	startIdx := 0
	if len(candidates) > 1 && concurrency > 1 {
		cf.VPrintf("  warming prompt cache on %s/%d...", candidates[0].image, candidates[0].group)
		runOne(0, candidates[0])
		startIdx = 1
	}
	var wg sync.WaitGroup
	sem := make(chan struct{}, concurrency)
	for i := startIdx; i < len(candidates); i++ {
		c := candidates[i]
		wg.Add(1)
		go func(i int, c candidate) {
			defer wg.Done()
			sem <- struct{}{}
			defer func() { <-sem }()
			runOne(i, c)
		}(i, c)
	}
	wg.Wait()
	if calls, ptok, ctok := client.CacheStats(); calls > 0 {
		pct := 0.0
		if ptok > 0 {
			pct = 100.0 * float64(ctok) / float64(ptok)
		}
		cf.VPrintf("  prompt cache: calls=%d prompt_tokens=%d cached_tokens=%d (%.1f%%)", calls, ptok, ctok, pct)
	}

	// Seed with preserved proposals for skipped already-named clusters so
	// <img>_named.json and proposals.json never drop prior entries.
	byGroup := map[string]map[int]map[string]any{}
	if skipNamed {
		for _, img := range images {
			rep := clusterReports[img]
			prevMap := existingNamed[img]
			if rep == nil {
				continue
			}
			for _, c := range rep.Clusters {
				if c.Name == "" || strings.HasPrefix(c.Name, "struct_shape_") {
					continue
				}
				var entry map[string]any
				if pe, ok := prevMap[c.GroupID]; ok {
					entry = pe
				} else {
					fieldsInfo := []map[string]any{}
					for _, k := range c.Fingerprint {
						fieldsInfo = append(fieldsInfo, map[string]any{
							"name":   fmt.Sprintf("field_0x%x", k.Offset),
							"offset": k.Offset,
							"size":   k.Size,
						})
					}
					entry = map[string]any{
						"image":       img,
						"group":       c.GroupID,
						"primary_arg": c.PrimaryArg,
						"struct_name": c.Name,
						"fields":      fieldsInfo,
					}
				}
				if byGroup[img] == nil {
					byGroup[img] = map[int]map[string]any{}
				}
				byGroup[img][c.GroupID] = entry
			}
		}
	}

	// Aggregate proposals AND update clusters.json in place so the
	// `name` field on each cluster is populated. This is what
	// fwstruct report reads to count "llm_named_structs".
	allProposals := []map[string]any{}
	perImage := map[string][]map[string]any{}
	namedCount := 0
	for i, r := range results {
		rep := clusterReports[r.image]
		if r.err != nil {
			allProposals = append(allProposals, map[string]any{
				"image": r.image, "group": r.group, "error": r.err.Error(),
			})
			continue
		}
		entry := map[string]any{
			"image":       r.image,
			"group":       r.group,
			"primary_arg": candidates[i].cluster.PrimaryArg,
			"struct_name": r.proposal.StructName,
			"fields":      r.proposal.Fields,
		}
		if byGroup[r.image] == nil {
			byGroup[r.image] = map[int]map[string]any{}
		}
		byGroup[r.image][r.group] = entry
		// Update the in-memory cluster's Name field so downstream
		// readers (report) see it without needing a side file.
		if r.proposal.StructName != "" && rep != nil {
			for _, c := range rep.Clusters {
				if c.GroupID == r.group {
					c.Name = r.proposal.StructName
					namedCount++
					break
				}
			}
		}
	}
	for _, img := range images {
		rep := clusterReports[img]
		m := byGroup[img]
		if rep == nil || m == nil {
			continue
		}
		for _, c := range rep.Clusters {
			if e, ok := m[c.GroupID]; ok {
				allProposals = append(allProposals, e)
				perImage[img] = append(perImage[img], e)
			}
		}
	}
	// Re-write each <img>_clusters.json with the LLM-assigned name
	// field populated, and a per-image named proposal list.
	for img, rep := range clusterReports {
		p := filepath.Join(cf.Out, img+"_clusters.json")
		if err := fileio.WriteJSON(p, rep); err != nil {
			fmt.Fprintf(os.Stderr, "  rewrite %s: %v\n", p, err)
		}
	}
	if err := fileio.WriteJSON(filepath.Join(cf.Out, "proposals.json"), allProposals); err != nil {
		return err
	}
	for img, lst := range perImage {
		if err := fileio.WriteJSON(filepath.Join(cf.Out, img+"_named.json"), lst); err != nil {
			return err
		}
	}
	cf.VPrintf("  done: %d proposals, %d clusters named", len(allProposals), namedCount)
	return nil
}

func buildNamingInput(image string, c *structs.Cluster) llm.StructProposalInput {
	in := llm.StructProposalInput{
		ClusterID:  c.GroupID,
		Image:      image,
		PrimaryArg: c.PrimaryArg,
	}
	for _, k := range c.Fingerprint {
		in.Fields = append(in.Fields, llm.FieldInput{
			Name:   fmt.Sprintf("field_at_0x%x", k.Offset),
			Offset: k.Offset,
			Size:   k.Size,
		})
	}
	for i, addr := range c.Funcs {
		if i >= 5 {
			break
		}
		in.SampleFuncs = append(in.SampleFuncs, fmt.Sprintf("sub_%x", addr))
	}
	return in
}

func runDeterministicNames(cf commonFlags, images []string) error {
	allProposals := []map[string]any{}
	perImage := map[string][]map[string]any{}
	totalNamed := 0

	for _, img := range images {
		var rep clusterReport
		p := filepath.Join(cf.Out, img+"_clusters.json")
		if err := readJSON(p, &rep); err != nil {
			fmt.Fprintf(os.Stderr, "  %s: %v\n", img, err)
			continue
		}

		fnMap := map[uint32]string{}
		if funcs, err := loadFuncs(cf.Out, img); err == nil {
			for _, fn := range funcs {
				fnMap[fn.Address] = fn.Name
			}
		}

		for _, c := range rep.Clusters {
			var structName string
			for _, addr := range c.Funcs {
				if name, ok := fnMap[addr]; ok && len(name) > 4 && name[:4] != "sub_" {
					parts := strings.Split(name, "_")
					if len(parts) > 1 {
						structName = "struct_" + strings.Join(parts[:len(parts)-1], "_") + "_t"
						break
					}
				}
			}
			if structName == "" {
				structName = fmt.Sprintf("struct_shape_%s_t", c.FPHash)
			}

			c.Name = structName
			c.Fields = make(map[string]int)
			c.FieldSizes = make(map[string]int)

			fieldsInfo := []map[string]any{}
			for _, k := range c.Fingerprint {
				fName := fmt.Sprintf("field_0x%x", k.Offset)
				c.Fields[fName] = k.Offset
				c.FieldSizes[fName] = k.Size
				fieldsInfo = append(fieldsInfo, map[string]any{
					"name":   fName,
					"offset": k.Offset,
					"size":   k.Size,
				})
			}

			entry := map[string]any{
				"image":       img,
				"group":       c.GroupID,
				"primary_arg": c.PrimaryArg,
				"struct_name": structName,
				"fields":      fieldsInfo,
			}
			allProposals = append(allProposals, entry)
			perImage[img] = append(perImage[img], entry)
			totalNamed++
		}

		if err := fileio.WriteJSON(p, &rep); err != nil {
			fmt.Fprintf(os.Stderr, "  rewrite %s: %v\n", p, err)
		}
	}

	if err := fileio.WriteJSON(filepath.Join(cf.Out, "proposals.json"), allProposals); err != nil {
		return err
	}
	for img, lst := range perImage {
		if err := fileio.WriteJSON(filepath.Join(cf.Out, img+"_named.json"), lst); err != nil {
			return err
		}
	}

	cf.VPrintf("  done: %d deterministic proposals, %d clusters named", len(allProposals), totalNamed)
	return nil
}
