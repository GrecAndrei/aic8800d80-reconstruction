package main

import (
	"bufio"
	"encoding/json"
	"flag"
	"fmt"
	"os"
	"path/filepath"
	"regexp"
	"sort"
	"strings"
)

// v18Func represents one function extracted from a v18 .c file.
type v18Func struct {
	Name     string
	Body     string
	FirstArg string
}

// parseV18File parses a v18 reconstructed .c file.
// Returns a list of v18Func entries, in order.
func parseV18File(path string) ([]v18Func, error) {
	f, err := os.Open(path)
	if err != nil {
		return nil, err
	}
	defer f.Close()
	sc := bufio.NewScanner(f)
	sc.Buffer(make([]byte, 1<<20), 8<<20)
	var out []v18Func
	var cur v18Func
	var inFunc bool
	for sc.Scan() {
		line := sc.Text()
		trimmed := strings.TrimSpace(line)
		// Match function start
		if strings.HasPrefix(trimmed, "__attribute__") && !inFunc {
			// Next line should be the function definition
			continue
		}
		// Match: void foo(args) {  or  int foo(args) {
		if !inFunc {
			if re := regexp.MustCompile(`^(\w[\w\s\*]*?)\s+(\w+)\s*\(([^)]*)\)\s*\{?$`); re.MatchString(trimmed) {
				m := re.FindStringSubmatch(trimmed)
				cur = v18Func{Name: m[2]}
				// Get first arg type as FirstArg
				args := strings.TrimSpace(m[3])
				if args != "" && args != "void" {
					parts := strings.Split(args, ",")
					first := strings.TrimSpace(parts[0])
					// Extract type (everything before the last word/name)
					toks := strings.Fields(first)
					cur.FirstArg = strings.Join(toks[:len(toks)-1], " ")
				}
				inFunc = true
				cur.Body = line + "\n"
				continue
			}
		}
		// Match function end
		if inFunc && trimmed == "}" {
			cur.Body += line + "\n"
			out = append(out, cur)
			cur = v18Func{}
			inFunc = false
			continue
		}
		if inFunc {
			cur.Body += line + "\n"
		}
	}
	return out, sc.Err()
}

func runExtractV18(args []string) error {
	fs := flag.NewFlagSet("extractv18", flag.ContinueOnError)
	var (
		root       string
		v18Dir     string
		v19Dir     string
		outSummary string
	)
	fs.StringVar(&root, "root", ".", "workspace root")
	fs.StringVar(&v18Dir, "v18-dir", "artifacts/releases/aic8800d80-rebuild-v1-v18", "v18 .c dir")
	fs.StringVar(&v19Dir, "v19-dir", "harness_v19/decompiled", "v19 C dir")
	fs.StringVar(&outSummary, "summary", "harness_v25/out/v18_extract.json", "summary output")
	if err := fs.Parse(args); err != nil {
		return err
	}

	// For each v18 image, find which funcs are not in v19
	type result struct {
		Image    string   `json:"image"`
		V18Total int      `json:"v18_total"`
		V19Total int      `json:"v19_total"`
		Missing  []string `json:"missing"`
	}
	var results []result

	v18Files, err := filepath.Glob(filepath.Join(v18Dir, "*.reconstructed_v18.c"))
	if err != nil {
		return err
	}

	totalMissing := 0
	for _, v18File := range v18Files {
		// Image name from filename: fmacfw_8800d80_h_u02_bin.reconstructed_v18.c -> fmacfw_8800d80_h_u02_bin
		base := filepath.Base(v18File)
		img := strings.TrimSuffix(base, ".reconstructed_v18.c")

		v18Funcs, err := parseV18File(v18File)
		if err != nil {
			fmt.Fprintf(os.Stderr, "parse %s: %v\n", v18File, err)
			continue
		}

		// Get v19 funcs
		imgV19Dir := filepath.Join(v19Dir, img)
		v19Names := make(map[string]bool)
		if entries, err := os.ReadDir(imgV19Dir); err == nil {
			for _, e := range entries {
				if !strings.HasSuffix(e.Name(), ".c") {
					continue
				}
				// Filename is ADDR_NAME.c
				parts := strings.SplitN(strings.TrimSuffix(e.Name(), ".c"), "_", 2)
				if len(parts) == 2 {
					v19Names[parts[1]] = true
				}
			}
		}

		// Find missing
		var missing []string
		for _, fn := range v18Funcs {
			if !v19Names[fn.Name] {
				missing = append(missing, fn.Name)
			}
		}
		sort.Strings(missing)

		results = append(results, result{
			Image:    img,
			V18Total: len(v18Funcs),
			V19Total: len(v19Names),
			Missing:  missing,
		})
		totalMissing += len(missing)
		fmt.Fprintf(os.Stderr, "extractv18: %s: v18=%d, v19=%d, missing=%d\n",
			img, len(v18Funcs), len(v19Names), len(missing))
	}

	// Write summary
	dir := filepath.Dir(outSummary)
	if err := os.MkdirAll(dir, 0755); err != nil {
		return err
	}
	b, _ := json.MarshalIndent(results, "", "  ")
	if err := os.WriteFile(outSummary, b, 0644); err != nil {
		return err
	}
	fmt.Fprintf(os.Stderr, "extractv18: total missing: %d, summary at %s\n", totalMissing, outSummary)
	return nil
}
