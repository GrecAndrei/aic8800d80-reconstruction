package main

import (
	"flag"
	"fmt"
	"os"
	"path/filepath"

	"aic8800d80/internal/fileio"
	"aic8800d80/internal/ivt"
)

// runIVT analyzes and rewrites the IVT of v18 WFFW images.
//
// Steps:
//   1. Read original WFFW (from inputs/firmware)
//   2. Read v18 WFFW (from artifacts/releases/.../wffw_v18/)
//   3. Parse IVT of original
//   4. Compute v18 IVT (add 0x100 to each address)
//   5. Write patched WFFW + report
func runIVT(args []string) error {
	fs := flag.NewFlagSet("ivt", flag.ContinueOnError)
	var cf commonFlags
	var inputsDir, v18Dir string
	cf.Register(fs)
	fs.StringVar(&inputsDir, "inputs", "", "original WFFW dir (default <root>/inputs/firmware)")
	fs.StringVar(&v18Dir, "v18", "", "v18 WFFW dir (default <root>/artifacts/releases/aic8800d80-rebuild-v1/wffw_v18)")
	if err := fs.Parse(args); err != nil {
		return err
	}
	if err := cf.Resolve(); err != nil {
		return err
	}
	if inputsDir == "" {
		inputsDir = filepath.Join(cf.Root, "inputs", "firmware")
	}
	if v18Dir == "" {
		v18Dir = filepath.Join(cf.Root, "artifacts", "releases", "aic8800d80-rebuild-v1", "wffw_v18")
	}
	outDir := filepath.Join(cf.Out, "ivt")
	if err := os.MkdirAll(outDir, 0o755); err != nil {
		return err
	}

	binaries := []struct{ src, v18, name string }{
		{"fmacfw_8800d80_h_u02.bin", "fmacfw_8800d80_h_u02_v18.bin", "fmacfw_h"},
		{"fmacfw_8800d80_u02.bin", "fmacfw_8800d80_u02_v18.bin", "fmacfw_u02"},
		{"fmacfwbt_8800d80_u02.bin", "fmacfwbt_8800d80_u02_v18.bin", "fmacfwbt"},
		{"lmacfw_rf_8800d80_u02.bin", "lmacfw_rf_8800d80_u02_v18.bin", "lmacfw_rf"},
	}
	for _, b := range binaries {
		srcPath := filepath.Join(inputsDir, b.src)
		v18Path := filepath.Join(v18Dir, b.v18)
		srcData, err := os.ReadFile(srcPath)
		if err != nil {
			fmt.Fprintf(os.Stderr, "  %s: %v\n", b.name, err)
			continue
		}
		v18Data, err := os.ReadFile(v18Path)
		if err != nil {
			fmt.Fprintf(os.Stderr, "  %s: v18 not found: %v\n", b.name, err)
			continue
		}
		vecs, err := ivt.ParseIVT(srcData)
		if err != nil {
			fmt.Fprintf(os.Stderr, "  %s: parse: %v\n", b.name, err)
			continue
		}
		patched := ivt.RewriteForV18(vecs, ivt.HeaderSize)
		patchedWFFW, err := ivt.ApplyPatch(v18Data, patched)
		if err != nil {
			fmt.Fprintf(os.Stderr, "  %s: apply: %v\n", b.name, err)
			continue
		}
		// Write patched WFFW
		outBin := filepath.Join(outDir, b.name+"_ivt_v18.bin")
		if err := os.WriteFile(outBin, patchedWFFW, 0644); err != nil {
			return err
		}
		// Write report
		report := struct {
			Image    string      `json:"image"`
			Original []ivt.Vector `json:"original_ivt"`
			Patched  []ivt.Vector `json:"patched_ivt"`
			HeaderSize uint32    `json:"header_size"`
			Output   string      `json:"output"`
		}{
			Image: b.name, Original: vecs, Patched: patched,
			HeaderSize: ivt.HeaderSize, Output: outBin,
		}
		if err := fileio.WriteJSON(filepath.Join(outDir, b.name+"_ivt.json"), report); err != nil {
			return err
		}
		fmt.Printf("  %s: parsed %d vectors, patched %d, written %s\n", b.name, len(vecs), len(patched), outBin)
	}
	return nil
}
