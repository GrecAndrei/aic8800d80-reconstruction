package main

import (
	"flag"
	"fmt"
	"os"
	"path/filepath"
	"strings"

	"aic8800d80/internal/fileio"
)

// runMerge combines v19 (decompiled) and v18 (inline-asm) C files
// for a single image into a unified tree. Prefers v19 (decompiled is
// more readable) and falls back to v18 (gives complete coverage).
//
// Output: <out>/<image>/*.c
//   - ADDR_NAME.c   from v19 (decompiled)
//   - v18_NAME.c    from v18 (inline-asm)
func runMerge(args []string) error {
	fs := flag.NewFlagSet("merge", flag.ContinueOnError)
	var (
		v19Dir   string
		v18Dir   string
		outDir   string
		images   string
	)
	fs.StringVar(&v19Dir, "v19", "harness_v19_named/decompiled", "v19 decompiled dir")
	fs.StringVar(&v18Dir, "v18", "harness_v19_named/v18_extracted", "v18 extracted dir")
	fs.StringVar(&outDir, "out", "harness_v19_named/merged", "output dir")
	fs.StringVar(&images, "images", "", "comma-separated image list (default: all)")
	if err := fs.Parse(args); err != nil {
		return err
	}

	// Determine images
	var imgs []string
	if images != "" {
		imgs = strings.Split(images, ",")
	} else {
		entries, err := os.ReadDir(v19Dir)
		if err != nil {
			return err
		}
		for _, e := range entries {
			if e.IsDir() {
				imgs = append(imgs, e.Name())
			}
		}
	}
	for _, img := range imgs {
		// v19 funcs
		imgV19 := filepath.Join(v19Dir, img)
		v19Funcs := make(map[string]bool)
		entries, err := os.ReadDir(imgV19)
		if err != nil {
			fmt.Fprintf(os.Stderr, "skip %s: %v\n", img, err)
			continue
		}
		for _, e := range entries {
			if !strings.HasSuffix(e.Name(), ".c") {
				continue
			}
			parts := strings.SplitN(strings.TrimSuffix(e.Name(), ".c"), "_", 2)
			if len(parts) == 2 {
				v19Funcs[parts[1]] = true
			}
		}
		// Make output dir
		imgOut := filepath.Join(outDir, img)
		if err := os.MkdirAll(imgOut, 0o755); err != nil {
			return err
		}
		// Copy v19 first
		nV19 := 0
		for _, e := range entries {
			if strings.HasSuffix(e.Name(), ".c") {
				src := filepath.Join(imgV19, e.Name())
				dst := filepath.Join(imgOut, e.Name())
				if err := copyFile(src, dst); err == nil {
					nV19++
				}
			}
		}
		// Add v18 for those not in v19
		imgV18 := filepath.Join(v18Dir, img)
		nV18 := 0
		if v18Entries, err := os.ReadDir(imgV18); err == nil {
			for _, e := range v18Entries {
				if !strings.HasSuffix(e.Name(), ".c") {
					continue
				}
				name := strings.TrimSuffix(e.Name(), ".c")
				if !v19Funcs[name] {
					src := filepath.Join(imgV18, e.Name())
					dst := filepath.Join(imgOut, "v18_"+e.Name())
					if err := copyFile(src, dst); err == nil {
						nV18++
					}
				}
			}
		}
		fmt.Fprintf(os.Stderr, "merge: %s: %d v19 + %d v18-only = %d total\n",
			img, nV19, nV18, nV19+nV18)
	}
	return nil
}

func copyFile(src, dst string) error {
	b, err := os.ReadFile(src)
	if err != nil {
		return err
	}
	return os.WriteFile(dst, b, 0644)
}

var _ = fileio.WriteBytes
