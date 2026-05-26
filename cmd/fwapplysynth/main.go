package main

import (
	"flag"
	"fmt"
	"os"
	"path/filepath"
	"regexp"
	"sort"
	"strings"
	"time"

	"aic8800d80/internal/fileio"
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

type applyContractFile struct {
	File                  string   `json:"file"`
	InputFunctionCount    int      `json:"input_function_count"`
	OutputFunctionCount   int      `json:"output_function_count"`
	ReplacedFunctions     []string `json:"replaced_functions"`
	MissingAfterApply     []string `json:"missing_after_apply,omitempty"`
	FunctionCountMismatch bool     `json:"function_count_mismatch"`
}

type applyContractReport struct {
	SchemaVersion string              `json:"schema_version"`
	GeneratedAt   string              `json:"generated_at"`
	FileCount     int                 `json:"file_count"`
	Violations    int                 `json:"violations"`
	Files         []applyContractFile `json:"files"`
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
	contract := applyContractReport{SchemaVersion: "0.1.0", GeneratedAt: time.Now().UTC().Format(time.RFC3339)}
	for _, e := range entries {
		if e.IsDir() || !strings.HasSuffix(e.Name(), ".reconstructed.c") {
			continue
		}
		inPath := filepath.Join(compAbs, e.Name())
		b, err := os.ReadFile(inPath)
		if err != nil {
			fail("read %s: %v", inPath, err)
		}
		inputFns := functionNames(string(b))
		outText, count, funcs := applyBodies(string(b), synthBodies)
		outText = ensureForwardDecls(outText)
		outputFns := functionNames(outText)
		missing := missingFunctions(funcs, outputFns)
		mismatch := len(inputFns) != len(outputFns)
		outPath := filepath.Join(outAbs, e.Name())
		if err := fileio.WriteBytes(outPath, []byte(outText)); err != nil {
			fail("write %s: %v", outPath, err)
		}
		contract.Files = append(contract.Files, applyContractFile{
			File:                  e.Name(),
			InputFunctionCount:    len(inputFns),
			OutputFunctionCount:   len(outputFns),
			ReplacedFunctions:     append([]string(nil), funcs...),
			MissingAfterApply:     missing,
			FunctionCountMismatch: mismatch,
		})
		if mismatch || len(missing) > 0 {
			contract.Violations++
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
	contract.FileCount = len(contract.Files)
	sort.Slice(contract.Files, func(i, j int) bool { return contract.Files[i].File < contract.Files[j].File })
	if err := fileio.WriteJSON(filepath.Join(outAbs, "apply_contracts.json"), contract); err != nil {
		fail("write apply contracts: %v", err)
	}
	if contract.Violations > 0 {
		fail("apply contract checks failed: violations=%d", contract.Violations)
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
	if err := fileio.WriteJSON(indexPath, indexRows); err != nil {
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
	if err := fileio.WriteJSON(filepath.Join(outAbs, "applysynth_manifest.json"), m); err != nil {
		fail("write manifest: %v", err)
	}

	fmt.Printf("synth application complete.\n")
	fmt.Printf("  files_touched: %d\n", touched)
	fmt.Printf("  functions_applied: %d\n", applied)
	fmt.Printf("  unique_functions_applied: %d\n", len(indexRows))
	fmt.Printf("  out_dir: %s\n", outAbs)
}

func functionNames(src string) map[string]struct{} {
	re := regexp.MustCompile(`(?m)^void\s+([a-zA-Z0-9_]+)\s*\(\s*void\s*\)\s*\{`)
	out := map[string]struct{}{}
	for _, m := range re.FindAllStringSubmatch(src, -1) {
		if len(m) != 2 {
			continue
		}
		out[m[1]] = struct{}{}
	}
	return out
}

func missingFunctions(required []string, have map[string]struct{}) []string {
	missing := make([]string, 0)
	for _, fn := range required {
		if _, ok := have[fn]; ok {
			continue
		}
		missing = append(missing, fn)
	}
	sort.Strings(missing)
	return missing
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

func ensureForwardDecls(src string) string {
	const marker = "/* Auto-generated forward declarations for compileability */"
	if strings.Contains(src, marker) {
		blockRe := regexp.MustCompile(`(?s)/\* Auto-generated forward declarations for compileability \*/\n(?:void [a-zA-Z0-9_]+\(\s*void\s*\);\n)+\n`)
		src = blockRe.ReplaceAllString(src, "")
	}
	fnRe := regexp.MustCompile(`(?m)^void\s+([a-zA-Z0-9_]+)\s*\(\s*void\s*\)\s*\{`)
	callRe := regexp.MustCompile(`\b([a-zA-Z_][a-zA-Z0-9_]*)\s*\(\s*\)\s*;`)
	names := map[string]struct{}{}
	for _, m := range fnRe.FindAllStringSubmatch(src, -1) {
		names[m[1]] = struct{}{}
	}
	for _, m := range callRe.FindAllStringSubmatch(src, -1) {
		names[m[1]] = struct{}{}
	}
	if len(names) == 0 {
		return src
	}
	list := make([]string, 0, len(names))
	for n := range names {
		list = append(list, n)
	}
	sort.Strings(list)
	var b strings.Builder
	b.WriteString(marker + "\n")
	for _, n := range list {
		b.WriteString("void " + n + "(void);\n")
	}
	b.WriteString("\n")
	inc := "#include <stdint.h>\n\n"
	if strings.Contains(src, inc) {
		return strings.Replace(src, inc, inc+b.String(), 1)
	}
	return b.String() + src
}

func fail(format string, args ...any) {
	fmt.Fprintf(os.Stderr, format+"\n", args...)
	os.Exit(1)
}
