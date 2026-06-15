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

// runXref computes per-field reader/writer counts for each cluster.
func runXref(args []string) error {
	fs := flag.NewFlagSet("xref", flag.ContinueOnError)
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
	cf.VPrintf("xref: %d images", len(images))

	for _, img := range images {
		funcs, err := loadFuncs(cf.Out, img)
		if err != nil {
			fmt.Fprintf(os.Stderr, "  %s: %v\n", img, err)
			continue
		}
		var crep struct {
			Clusters []*structs.Cluster `json:"clusters"`
		}
		if err := readJSON(filepath.Join(cf.Out, img+"_clusters.json"), &crep); err != nil {
			fmt.Fprintf(os.Stderr, "  %s: %v\n", img, err)
			continue
		}
		type fieldRow struct {
			Name      string   `json:"name"`
			Offset    int      `json:"offset"`
			Size      int      `json:"size"`
			Reads     int      `json:"reads"`
			Writes    int      `json:"writes"`
			ReadFuncs  []uint32 `json:"read_funcs"`
			WriteFuncs []uint32 `json:"write_funcs"`
		}
		type clusterRow struct {
			GroupID    int        `json:"group_id"`
			PrimaryArg string     `json:"primary_arg"`
			Fields     []fieldRow `json:"fields"`
		}
		var rows []clusterRow
		for _, c := range crep.Clusters {
			xref := structs.BuildFieldXref(c, funcs)
			cr := clusterRow{GroupID: c.GroupID, PrimaryArg: c.PrimaryArg}
			// Sort fields by offset
			fieldList := []fieldRow{}
			for _, fa := range xref {
				fieldList = append(fieldList, fieldRow{
					Name: fa.Name, Offset: fa.Offset, Size: fa.Size,
					Reads: fa.Reads, Writes: fa.Writes,
					ReadFuncs: fa.ReadFuncs, WriteFuncs: fa.WriteFuncs,
				})
			}
			sort.Slice(fieldList, func(i, j int) bool { return fieldList[i].Offset < fieldList[j].Offset })
			cr.Fields = fieldList
			rows = append(rows, cr)
		}
		outPath := filepath.Join(cf.Out, img+"_xref.json")
		if err := fileio.WriteJSON(outPath, rows); err != nil {
			return err
		}
		cf.VPrintf("  %s: %d clusters with field xref", img, len(rows))
	}
	return nil
}

// silence unused
var _ = decompile.Func{}
