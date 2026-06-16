package main

import (
	"bufio"
	"flag"
	"fmt"
	"os"
	"path/filepath"
	"regexp"
	"strings"
)

// runExtractV18C extracts individual v18 functions from the v18 .c files
// into per-function .c files in <out>/v18_extracted/<img>/<funcname>.c
//
// Each output file contains the full function definition with inline-asm,
// ready to be compiled as part of v18 reconstruction.
func runExtractV18C(args []string) error {
	fs := flag.NewFlagSet("extractv18c", flag.ContinueOnError)
	var (
		v18Dir string
		outDir string
	)
	fs.StringVar(&v18Dir, "v18-dir", "artifacts/releases/aic8800d80-rebuild-v1-v18", "v18 .c dir")
	fs.StringVar(&outDir, "out", "harness_v19_named/v18_extracted", "output dir")
	if err := fs.Parse(args); err != nil {
		return err
	}

	v18Files, err := filepath.Glob(filepath.Join(v18Dir, "*.reconstructed_v18.c"))
	if err != nil {
		return err
	}

	totalExtracted := 0
	for _, v18File := range v18Files {
		base := filepath.Base(v18File)
		img := strings.TrimSuffix(base, ".reconstructed_v18.c")

		imgOutDir := filepath.Join(outDir, img)
		if err := os.MkdirAll(imgOutDir, 0o755); err != nil {
			return err
		}

		fh, err := os.Open(v18File)
		if err != nil {
			fmt.Fprintf(os.Stderr, "open %s: %v\n", v18File, err)
			continue
		}
		sc := bufio.NewScanner(fh)
		sc.Buffer(make([]byte, 1<<20), 8<<20)

		funcRe := regexp.MustCompile(`^(void|int|unsigned|char|__int8|__int16|__int32|__int64)\s+(\w+)\s*\(`)

		var current string
		var currentBody strings.Builder
		var currentName string
		inFunc := false
		braceDepth := 0

		flush := func() {
			if currentName != "" && current != "" {
				outFile := filepath.Join(imgOutDir, currentName+".c")
				content := "// v18 extracted function: " + currentName + "\n" + current
				if err := os.WriteFile(outFile, []byte(content), 0644); err == nil {
					totalExtracted++
				}
			}
			current = ""
			currentBody.Reset()
			currentName = ""
			inFunc = false
			braceDepth = 0
		}

		for sc.Scan() {
			line := sc.Text()
			trimmed := strings.TrimSpace(line)
			if !inFunc {
				// Check for __attribute__ on its own line
				if strings.HasPrefix(trimmed, "__attribute__") {
					continue
				}
				// Check for function def
				if m := funcRe.FindStringSubmatch(trimmed); m != nil {
					currentName = m[2]
					inFunc = true
					braceDepth = 0
					current = ""
					currentBody.Reset()
				}
			}
			if inFunc {
				current += line + "\n"
				// Track braces
				braceDepth += strings.Count(line, "{")
				braceDepth -= strings.Count(line, "}")
				// End of function: balanced braces and we're past the opening
				if braceDepth == 0 && strings.Contains(current, "{") {
					flush()
				}
			}
		}
		flush() // last one
		fh.Close()
		fmt.Fprintf(os.Stderr, "extractv18c: %s -> %s\n", img, imgOutDir)
	}
	fmt.Fprintf(os.Stderr, "extractv18c: total %d functions extracted\n", totalExtracted)
	return nil
}
