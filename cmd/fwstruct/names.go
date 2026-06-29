package main

import (
	"context"
	"encoding/json"
	"flag"
	"fmt"
	"os"
	"path/filepath"
	"sort"
	"sync"
	"time"

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
	var keyDir, model string
	var concurrency, maxClusters int
	fs.StringVar(&keyDir, "llm-key-dir", "", "directory of *.key files for LLM API")
	fs.StringVar(&model, "llm-model", llm.Model, "LLM model name")
	fs.IntVar(&concurrency, "concurrency", 4, "parallel LLM calls")
	fs.IntVar(&maxClusters, "max-clusters", 0, "max clusters to name (0 = all)")
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

	// Set up LLM client
	cfg := llm.DefaultConfig()
	cfg.Model = model
	if keyDir != "" {
		if keys, err := llm.LoadKeysFromDir(keyDir); err == nil {
			cfg.Keys = keys
		}
	}
	if len(cfg.Keys) == 0 {
		cfg.Keys = llm.LoadKeysFromEnv()
	}
	if len(cfg.Keys) == 0 {
		return fmt.Errorf("no LLM keys: set AIC8800D80_LLM_KEY_<N> or --llm-key-dir")
	}
	client := llm.New(cfg)
	cf.VPrintf("names: %d keys, model=%s, concurrency=%d", len(cfg.Keys), model, concurrency)

	// Collect all cluster candidates
	type candidate struct {
		image   string
		group   int
		cluster *structs.Cluster
	}
	var candidates []candidate
	clusterReports := map[string]*clusterReport{}
	for _, img := range images {
		var rep clusterReport
		p := filepath.Join(cf.Out, img+"_clusters.json")
		if err := readJSON(p, &rep); err != nil {
			fmt.Fprintf(os.Stderr, "  %s: %v\n", img, err)
			continue
		}
		clusterReports[img] = &rep
		for _, c := range rep.Clusters {
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

	// Run LLM in parallel
	type result struct {
		image    string
		group    int
		proposal *llm.StructProposal
		err      error
	}
	results := make([]result, len(candidates))
	var wg sync.WaitGroup
	sem := make(chan struct{}, concurrency)
	ctx, cancel := context.WithTimeout(context.Background(), 60*time.Minute)
	defer cancel()
	for i, c := range candidates {
		wg.Add(1)
		go func(i int, c candidate) {
			defer wg.Done()
			sem <- struct{}{}
			defer func() { <-sem }()
			in := buildNamingInput(c.image, c.cluster)
			prop, err := llm.NameStruct(ctx, client, in)
			results[i] = result{image: c.image, group: c.group, proposal: prop, err: err}
			if err != nil {
				cf.VPrintf("  %s/%d: %v", c.image, c.group, err)
			} else {
				cf.VPrintf("  %s/%d: %s", c.image, c.group, prop.StructName)
			}
		}(i, c)
	}
	wg.Wait()

	// Aggregate proposals
	allProposals := []map[string]any{}
	perImage := map[string][]map[string]any{}
	for i, r := range results {
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
		allProposals = append(allProposals, entry)
		perImage[r.image] = append(perImage[r.image], entry)
	}
	if err := fileio.WriteJSON(filepath.Join(cf.Out, "proposals.json"), allProposals); err != nil {
		return err
	}
	for img, lst := range perImage {
		if err := fileio.WriteJSON(filepath.Join(cf.Out, img+"_named.json"), lst); err != nil {
			return err
		}
	}
	cf.VPrintf("  done: %d proposals", len(allProposals))
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
