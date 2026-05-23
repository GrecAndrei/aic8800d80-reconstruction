package main

import (
	"compress/gzip"
	"flag"
	"fmt"
	"io"
	"os"
	"path/filepath"
	"strings"
)

func main() {
	var reconDir string
	var deleteOriginal bool
	var includeWorkset bool
	var includeStrict bool
	var includeLogs bool

	flag.StringVar(&reconDir, "recon-dir", "extraction_out/reconstruction/mega7", "Reconstruction directory")
	flag.BoolVar(&deleteOriginal, "delete-original", true, "Delete original files after successful gzip")
	flag.BoolVar(&includeWorkset, "include-workset", false, "Also compact recon_workset.jsonl")
	flag.BoolVar(&includeStrict, "include-strict", false, "Also compact recon_strict.jsonl")
	flag.BoolVar(&includeLogs, "include-logs", false, "Also compact pipeline_*.log files")
	flag.Parse()

	base, err := filepath.Abs(reconDir)
	if err != nil {
		fail("resolve recon dir: %v", err)
	}

	targets := []string{
		filepath.Join(base, "recon_union.jsonl"),
	}
	if includeWorkset {
		targets = append(targets, filepath.Join(base, "recon_workset.jsonl"))
	}
	if includeStrict {
		targets = append(targets, filepath.Join(base, "recon_strict.jsonl"))
	}
	if includeLogs {
		ents, _ := os.ReadDir(base)
		for _, e := range ents {
			if e.IsDir() {
				continue
			}
			if strings.HasPrefix(e.Name(), "pipeline_") && strings.HasSuffix(e.Name(), ".log") {
				targets = append(targets, filepath.Join(base, e.Name()))
			}
		}
	}

	totalBefore := int64(0)
	totalAfter := int64(0)
	processed := 0
	for _, p := range targets {
		st, err := os.Stat(p)
		if err != nil {
			continue
		}
		if st.IsDir() || strings.HasSuffix(p, ".gz") {
			continue
		}
		totalBefore += st.Size()
		gzPath := p + ".gz"
		if err := gzipFile(p, gzPath); err != nil {
			fail("compact %s: %v", p, err)
		}
		gst, err := os.Stat(gzPath)
		if err != nil {
			fail("stat gz %s: %v", gzPath, err)
		}
		totalAfter += gst.Size()
		if deleteOriginal {
			if err := os.Remove(p); err != nil {
				fail("delete %s: %v", p, err)
			}
		}
		processed++
		fmt.Printf("compacted: %s -> %s\n", p, gzPath)
	}

	saved := totalBefore - totalAfter
	fmt.Printf("fwcompact done.\n")
	fmt.Printf("  recon_dir: %s\n", base)
	fmt.Printf("  processed_files: %d\n", processed)
	fmt.Printf("  bytes_before: %d\n", totalBefore)
	fmt.Printf("  bytes_after: %d\n", totalAfter)
	fmt.Printf("  bytes_saved: %d\n", saved)
}

func gzipFile(src, dst string) error {
	in, err := os.Open(src)
	if err != nil {
		return err
	}
	defer in.Close()

	out, err := os.Create(dst)
	if err != nil {
		return err
	}
	defer out.Close()

	zw, err := gzip.NewWriterLevel(out, gzip.BestSpeed)
	if err != nil {
		return err
	}
	defer zw.Close()

	if _, err := io.Copy(zw, in); err != nil {
		return err
	}
	return zw.Close()
}

func fail(format string, args ...any) {
	fmt.Fprintf(os.Stderr, format+"\n", args...)
	os.Exit(1)
}
