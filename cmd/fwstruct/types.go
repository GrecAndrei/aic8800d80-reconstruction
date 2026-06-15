package main

import (
	"bytes"
	"flag"
	"fmt"
	"os"
	"path/filepath"
	"strings"

	"aic8800d80/internal/fileio"
	"aic8800d80/internal/types"
)

// runTypes fixes Hex-Rays type-inference bugs in v19 decompiled C.
//
// Outputs <out>/types_fixed/<img>/*.c with fixes applied.
// Also writes <out>/types_summary.json with the aggregate stats.
func runTypes(args []string) error {
	fs := flag.NewFlagSet("types", flag.ContinueOnError)
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
	cf.VPrintf("types: %d images", len(images))

	summary := types.Summary{
		TotalFiles: 0, FixedFiles: 0, TotalFixes: 0,
		ByKind: map[string]int{},
	}
	for _, img := range images {
		imgDir := filepath.Join(cf.Decompiled, img)
		outDir := filepath.Join(cf.Out, "types_fixed", img)
		if err := os.MkdirAll(outDir, 0o755); err != nil {
			return err
		}
		entries, err := os.ReadDir(imgDir)
		if err != nil {
			return err
		}
		for _, e := range entries {
			if e.IsDir() || !strings.HasSuffix(e.Name(), ".c") {
				continue
			}
			summary.TotalFiles++
			inPath := filepath.Join(imgDir, e.Name())
			outPath := filepath.Join(outDir, e.Name())
			text, err := os.ReadFile(inPath)
			if err != nil {
				continue
			}
			fixed, fixes := types.FixFile(string(text))
			if len(fixes) > 0 {
				summary.FixedFiles++
				summary.TotalFixes += len(fixes)
				if err := os.WriteFile(outPath, []byte(fixed), 0644); err != nil {
					return err
				}
				for _, f := range fixes {
					summary.ByKind[f.Kind]++
				}
			} else {
				// Copy as-is
				if err := os.WriteFile(outPath, text, 0644); err != nil {
					return err
				}
			}
		}
		cf.VPrintf("  %s: %d funcs processed", img, len(entries))
	}
	// Write summary
	sumPath := filepath.Join(cf.Out, "types_summary.json")
	if err := fileio.WriteJSON(sumPath, summary); err != nil {
		return err
	}
	fmt.Printf("types: %d files, %d fixed, %d total fixes\n", summary.TotalFiles, summary.FixedFiles, summary.TotalFixes)
	for k, v := range summary.ByKind {
		fmt.Printf("  %s: %d\n", k, v)
	}
	_ = bytes.Equal
	return nil
}
