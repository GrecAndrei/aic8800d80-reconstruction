package main

import (
	"flag"
	"fmt"
	"os"
	"path/filepath"
)

// runStats prints a one-line summary per binary. Useful for quick checks.
func runStats(args []string) error {
	fs := flag.NewFlagSet("stats", flag.ContinueOnError)
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
	for _, img := range images {
		// Count funcs
		funcs, _ := loadFuncs(cf.Out, img)
		// Count clusters
		var c struct{ ClusterCount int `json:"cluster_count"` }
		readJSON(filepath.Join(cf.Out, img+"_clusters.json"), &c)
		// Count callgraph hubs
		var cg struct {
			TopHubs []struct{ Name string `json:"name"` } `json:"top_hubs"`
		}
		readJSON(filepath.Join(cf.Out, img+"_callgraph.json"), &cg)
		topHub := "(none)"
		if len(cg.TopHubs) > 0 {
			topHub = cg.TopHubs[0].Name
		}
		// Count literals
		var m struct{ Total int `json:"total_literals"` }
		readJSON(filepath.Join(cf.Out, img+"_magic.json"), &m)
		fmt.Printf("%-32s funcs=%d clusters=%d top_hub=%s literals=%d\n",
			img, len(funcs), c.ClusterCount, topHub, m.Total)
	}
	return nil
}
var _ = os.Stdin
