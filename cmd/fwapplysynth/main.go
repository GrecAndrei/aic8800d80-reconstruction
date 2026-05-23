package main

import (
	"encoding/json"
	"flag"
	"fmt"
	"os"
	"path/filepath"
	"regexp"
	"sort"
	"strings"
	"time"
)

type applyManifest struct {
	SchemaVersion          string `json:"schema_version"`
	GeneratedAt            string `json:"generated_at"`
	SynthDir               string `json:"synth_dir"`
	ComposedDir            string `json:"composed_dir"`
	FilesTouched           int    `json:"files_touched"`
	FunctionsApplied       int    `json:"functions_applied"`
	UniqueFunctionsApplied int    `json:"unique_functions_applied"`
	OutputDir              string `json:"output_dir"`
	OutputIndex            string `json:"output_index"`
}

type appliedIndexRow struct {
	Function string   `json:"function"`
	Files    []string `json:"files"`
}

func main() {
	var synthDir string
	var composedDir string
	var outDir string

	flag.StringVar(&synthDir, "synth-dir", "extraction_out/reconstruction/mega7/synth", "Synthesized .synth.c directory")
	flag.StringVar(&composedDir, "composed-dir", "extraction_out/reconstruction/mega7/composed", "Composed reconstruction directory")
	flag.StringVar(&outDir, "out", "extraction_out/reconstruction/mega7/applied", "Output directory for merged reconstruction files")
	flag.Parse()

	synthAbs, _ := filepath.Abs(synthDir)
	compAbs, _ := filepath.Abs(composedDir)
	outAbs, _ := filepath.Abs(outDir)
	if err := os.MkdirAll(outAbs, 0o755); err != nil {
		fail("mkdir out: %v", err)
	}

	synthBodies, err := loadSynthBodies(synthAbs)
	if err != nil {
		fail("load synth bodies: %v", err)
	}
	if len(synthBodies) == 0 {
		fail("no synthesized bodies found in %s", synthAbs)
	}

	entries, err := os.ReadDir(compAbs)
	if err != nil {
		fail("read composed dir: %v", err)
	}
	touched := 0
	applied := 0
	appliedMap := map[string]map[string]struct{}{}
	for _, e := range entries {
		if e.IsDir() || !strings.HasSuffix(e.Name(), ".reconstructed.c") {
			continue
		}
		inPath := filepath.Join(compAbs, e.Name())
		b, err := os.ReadFile(inPath)
		if err != nil {
			fail("read %s: %v", inPath, err)
		}
		outText, count, funcs := applyBodies(string(b), synthBodies)
		outPath := filepath.Join(outAbs, e.Name())
		if err := os.WriteFile(outPath, []byte(outText), 0o644); err != nil {
			fail("write %s: %v", outPath, err)
		}
		if count > 0 {
			touched++
			applied += count
			for _, fn := range funcs {
				if appliedMap[fn] == nil {
					appliedMap[fn] = map[string]struct{}{}
				}
				appliedMap[fn][e.Name()] = struct{}{}
			}
		}
	}
	indexRows := make([]appliedIndexRow, 0, len(appliedMap))
	for fn, filesSet := range appliedMap {
		files := make([]string, 0, len(filesSet))
		for f := range filesSet {
			files = append(files, f)
		}
		sort.Strings(files)
		indexRows = append(indexRows, appliedIndexRow{Function: fn, Files: files})
	}
	sort.Slice(indexRows, func(i, j int) bool { return indexRows[i].Function < indexRows[j].Function })
	indexPath := filepath.Join(outAbs, "applysynth_index.json")
	ib, err := json.MarshalIndent(indexRows, "", "  ")
	if err != nil {
		fail("marshal index: %v", err)
	}
	if err := os.WriteFile(indexPath, append(ib, '\n'), 0o644); err != nil {
		fail("write index: %v", err)
	}

	m := applyManifest{
		SchemaVersion:          "0.1.0",
		GeneratedAt:            time.Now().UTC().Format(time.RFC3339),
		SynthDir:               synthAbs,
		ComposedDir:            compAbs,
		FilesTouched:           touched,
		FunctionsApplied:       applied,
		UniqueFunctionsApplied: len(indexRows),
		OutputDir:              outAbs,
		OutputIndex:            indexPath,
	}
	mb, err := json.MarshalIndent(m, "", "  ")
	if err != nil {
		fail("marshal manifest: %v", err)
	}
	if err := os.WriteFile(filepath.Join(outAbs, "applysynth_manifest.json"), append(mb, '\n'), 0o644); err != nil {
		fail("write manifest: %v", err)
	}

	fmt.Printf("synth application complete.\n")
	fmt.Printf("  files_touched: %d\n", touched)
	fmt.Printf("  functions_applied: %d\n", applied)
	fmt.Printf("  unique_functions_applied: %d\n", len(indexRows))
	fmt.Printf("  out_dir: %s\n", outAbs)
}

func loadSynthBodies(dir string) (map[string]string, error) {
	ents, err := os.ReadDir(dir)
	if err != nil {
		return nil, err
	}
	paths := make([]string, 0, len(ents))
	for _, e := range ents {
		if e.IsDir() || !strings.HasSuffix(e.Name(), ".synth.c") {
			continue
		}
		paths = append(paths, filepath.Join(dir, e.Name()))
	}
	sort.Strings(paths)
	out := map[string]string{}
	for _, p := range paths {
		b, err := os.ReadFile(p)
		if err != nil {
			return nil, err
		}
		fn, body, ok := extractSingleFunction(string(b))
		if !ok {
			continue
		}
		if prev, exists := out[fn]; exists {
			if bodyStrength(body) < bodyStrength(prev) {
				continue
			}
		}
		out[fn] = body
	}
	return out, nil
}

func bodyStrength(body string) int {
	score := 0
	if strings.Contains(body, "reconstructed micro-flow:") {
		score += 100
	}
	if strings.Contains(body, "reconstructed control:") {
		score += 80
	}
	if strings.Contains(body, "isolated leaf in current mined graph") {
		score -= 20
	}
	callRe := regexp.MustCompile(`(?m)^\s*[a-zA-Z_][a-zA-Z0-9_]*\s*\(\s*\)\s*;`)
	score += len(callRe.FindAllString(body, -1)) * 5
	score += len(body)
	return score
}

func extractSingleFunction(src string) (fn string, full string, ok bool) {
	re := regexp.MustCompile(`(?s)void\s+([a-zA-Z0-9_]+)\s*\(\s*void\s*\)\s*\{.*?\n\}`)
	m := re.FindStringSubmatch(src)
	if len(m) != 2 {
		return "", "", false
	}
	return m[1], m[0], true
}

func applyBodies(src string, bodies map[string]string) (string, int, []string) {
	count := 0
	funcs := map[string]struct{}{}
	re := regexp.MustCompile(`(?s)void\s+([a-zA-Z0-9_]+)\s*\(\s*void\s*\)\s*\{.*?\n\}`)
	out := re.ReplaceAllStringFunc(src, func(match string) string {
		m := regexp.MustCompile(`void\s+([a-zA-Z0-9_]+)\s*\(`).FindStringSubmatch(match)
		if len(m) != 2 {
			return match
		}
		fn := m[1]
		if b, ok := bodies[fn]; ok {
			count++
			funcs[fn] = struct{}{}
			return b
		}
		return match
	})
	list := make([]string, 0, len(funcs))
	for fn := range funcs {
		list = append(list, fn)
	}
	sort.Strings(list)
	return out, count, list
}

func fail(format string, args ...any) {
	fmt.Fprintf(os.Stderr, format+"\n", args...)
	os.Exit(1)
}
