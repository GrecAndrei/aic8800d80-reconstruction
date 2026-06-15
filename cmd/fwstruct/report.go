package main

import (
	"encoding/json"
	"flag"
	"fmt"
	"os"
	"path/filepath"
	"sort"

	"aic8800d80/internal/fileio"
)

// runReport aggregates results from all subcommands into a single summary.
func runReport(args []string) error {
	fs := flag.NewFlagSet("report", flag.ContinueOnError)
	var cf commonFlags
	cf.Register(fs)
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
	cf.VPrintf("report: %d images", len(images))

	report := map[string]any{
		"images": images,
		"per_image": map[string]map[string]any{},
		"totals": map[string]int{},
	}
	perImage := report["per_image"].(map[string]map[string]any)

	for _, img := range images {
		perImage[img] = map[string]any{}
		// Funcs
		funcs, _ := loadFuncs(cf.Out, img)
		perImage[img]["funcs"] = len(funcs)
		// Clusters
		var crep struct {
			ClusterCount int `json:"cluster_count"`
			Clustered    int `json:"clustered"`
		}
		if err := readJSON(filepath.Join(cf.Out, img+"_clusters.json"), &crep); err == nil {
			perImage[img]["clusters"] = crep.ClusterCount
			perImage[img]["clustered_funcs"] = crep.Clustered
		}
		// Call graph
		var cg struct {
			TopHubs []struct {
				Name     string `json:"name"`
				NCallers int    `json:"n_callers"`
			} `json:"top_hubs"`
		}
		if err := readJSON(filepath.Join(cf.Out, img+"_callgraph.json"), &cg); err == nil {
			hubs := []map[string]any{}
			for _, h := range cg.TopHubs {
				hubs = append(hubs, map[string]any{"name": h.Name, "n_callers": h.NCallers})
			}
			perImage[img]["top_hubs"] = hubs[:min(10, len(hubs))]
		}
		// Magic
		var mag struct {
			Total   int            `json:"total_literals"`
			ByCat   map[string]int `json:"by_category"`
		}
		if err := readJSON(filepath.Join(cf.Out, img+"_magic.json"), &mag); err == nil {
			perImage[img]["literals"] = mag.Total
			perImage[img]["literal_categories"] = mag.ByCat
		}
		// Init path
		var ip struct {
			Total     int `json:"total"`
			Reachable int `json:"reachable"`
		}
		if err := readJSON(filepath.Join(cf.Out, img+"_initpath.json"), &ip); err == nil {
			perImage[img]["init_total"] = ip.Total
			perImage[img]["init_reachable"] = ip.Reachable
		}
		// LLM named
		var named []map[string]any
		if err := readJSON(filepath.Join(cf.Out, img+"_named.json"), &named); err == nil {
			perImage[img]["named_structs"] = len(named)
		}
	}

	// Totals
	totals := map[string]int{}
	for _, info := range perImage {
		if v, ok := info["funcs"].(int); ok {
			totals["funcs"] += v
		}
		if v, ok := info["clusters"].(int); ok {
			totals["clusters"] += v
		}
		if v, ok := info["clustered_funcs"].(int); ok {
			totals["clustered_funcs"] += v
		}
		if v, ok := info["literals"].(int); ok {
			totals["literals"] += v
		}
	}
	report["totals"] = totals
	outPath := filepath.Join(cf.Out, "report.json")
	if err := fileio.WriteJSON(outPath, report); err != nil {
		return err
	}

	// Print summary
	fmt.Printf("fwstruct report:\n")
	fmt.Printf("  images: %d\n", len(images))
	for _, img := range images {
		info := perImage[img]
		keys := []string{"funcs", "clusters", "clustered_funcs", "literals", "named_structs", "init_reachable"}
		parts := []string{}
		for _, k := range keys {
			if v, ok := info[k]; ok {
				parts = append(parts, fmt.Sprintf("%s=%v", k, v))
			}
		}
		fmt.Printf("  %s: %s\n", img, joinComma(parts))
	}
	fmt.Printf("  totals: %v\n", totals)
	return nil
}

func joinComma(s []string) string {
	out := ""
	for i, p := range s {
		if i > 0 {
			out += ", "
		}
		out += p
	}
	return out
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// silence unused
var _ = sort.Strings
var _ = os.Stdin
var _ = json.Marshal
