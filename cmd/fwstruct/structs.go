package main

import (
	"flag"
	"fmt"
	"os"
	"path/filepath"
	"sort"

	"aic8800d80/internal/decompile"
	"aic8800d80/internal/fileio"
	"aic8800d80/internal/structs"
)

// runStructs clusters funcs by access pattern and proposes struct types.
//
// Inputs:  <out>/<img>_funcs.jsonl
// Outputs: <out>/<img>_clusters.json, <out>/structs.h
func runStructs(args []string) error {
	fs := flag.NewFlagSet("structs", flag.ContinueOnError)
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
	cf.VPrintf("structs: %d images", len(images))

	allStructs := map[string]map[string]int{} // struct_name -> field_name -> offset
	allFieldNames := map[string]map[int]string{} // struct_name -> offset -> name
	clusterCount := 0
	funcedCount := 0

	for _, img := range images {
		funcs, err := loadFuncs(cf.Out, img)
		if err != nil {
			fmt.Fprintf(os.Stderr, "  %s: %v\n", img, err)
			continue
		}
		clusters, f2c, n := structs.BuildClusters(img, funcs)
		cf.VPrintf("  %s: %d funcs, %d clusters, %d clustered", img, len(funcs), len(clusters), n)
		clusterCount += len(clusters)
		funcedCount += n

		// Per-image cluster report
		rep := struct {
			Image       string                       `json:"image"`
			TotalFuncs  int                          `json:"total_funcs"`
			Clustered   int                          `json:"clustered"`
			ClusterCount int                         `json:"cluster_count"`
			Clusters    []*structs.Cluster           `json:"clusters"`
			FuncMap     map[string]int               `json:"func_map"`
		}{
			Image: img, TotalFuncs: len(funcs), Clustered: n, ClusterCount: len(clusters),
			Clusters: clusters,
		}
		rep.FuncMap = make(map[string]int, len(f2c))
		for addr, cid := range f2c {
			rep.FuncMap[fmt.Sprintf("%x", addr)] = cid
		}
		outPath := filepath.Join(cf.Out, img+"_clusters.json")
		if err := fileio.WriteJSON(outPath, rep); err != nil {
			return err
		}
	}

	// Aggregate summary
	summary := map[string]any{
		"images": images,
		"total_clusters": clusterCount,
		"total_clustered_funcs": funcedCount,
	}
	if err := fileio.WriteJSON(filepath.Join(cf.Out, "structs_summary.json"), summary); err != nil {
		return err
	}
	cf.VPrintf("summary: %d clusters across %d images, %d funcs clustered", clusterCount, len(images), funcedCount)

	// Touch allStructs to silence unused warning
	_ = allStructs
	_ = allFieldNames
	_ = sort.Strings
	return nil
}

func loadFuncs(outDir, img string) ([]*decompile.Func, error) {
	p := filepath.Join(outDir, img+"_funcs.jsonl")
	return fileio.ReadJSONL[*decompile.Func](p)
}
