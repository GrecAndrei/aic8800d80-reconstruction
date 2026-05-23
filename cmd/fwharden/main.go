package main

import (
	"encoding/json"
	"flag"
	"fmt"
	"os"
	"path/filepath"
	"strings"
)

type finalizeManifest struct {
	FileCount             int     `json:"file_count"`
	FunctionCount         int     `json:"function_count"`
	TodoCount             int     `json:"todo_count"`
	ImplementedCount      int     `json:"implemented_count"`
	CompletionPct         float64 `json:"completion_pct"`
	StrongCount           int     `json:"strong_count"`
	FallbackCount         int     `json:"fallback_count"`
	SemanticCompletionPct float64 `json:"semantic_completion_pct"`
}

func main() {
	var finalDir string
	var rebuiltDir string

	flag.StringVar(&finalDir, "final-dir", "extraction_out/reconstruction/mega7/final", "Final reconstruction directory")
	flag.StringVar(&rebuiltDir, "rebuilt-dir", "extraction_out/reconstruction/mega7/rebuilt", "Rebuilt artifacts directory")
	flag.Parse()

	finalAbs, _ := filepath.Abs(finalDir)
	rebuiltAbs, _ := filepath.Abs(rebuiltDir)

	mPath := filepath.Join(finalAbs, "finalize_manifest.json")
	mb, err := os.ReadFile(mPath)
	if err != nil {
		fail("read finalize manifest: %v", err)
	}
	var m finalizeManifest
	if err := json.Unmarshal(mb, &m); err != nil {
		fail("parse finalize manifest: %v", err)
	}

	if m.FunctionCount == 0 || m.FileCount == 0 {
		fail("empty finalize output: functions=%d files=%d", m.FunctionCount, m.FileCount)
	}
	if m.ImplementedCount != m.FunctionCount {
		fail("implemented mismatch: %d/%d", m.ImplementedCount, m.FunctionCount)
	}
	if m.TodoCount != 0 {
		fail("todo_count must be 0, got %d", m.TodoCount)
	}
	if m.FallbackCount != 0 {
		fail("fallback_count must be 0, got %d", m.FallbackCount)
	}
	if m.StrongCount != m.FunctionCount {
		fail("strong_count must equal function_count, got %d/%d", m.StrongCount, m.FunctionCount)
	}
	if m.CompletionPct < 100.0 || m.SemanticCompletionPct < 100.0 {
		fail("completion gates failed: completion=%.3f semantic=%.3f", m.CompletionPct, m.SemanticCompletionPct)
	}

	ents, err := os.ReadDir(finalAbs)
	if err != nil {
		fail("read final dir: %v", err)
	}
	for _, e := range ents {
		if e.IsDir() || !strings.HasSuffix(e.Name(), ".reconstructed.c") {
			continue
		}
		p := filepath.Join(finalAbs, e.Name())
		b, err := os.ReadFile(p)
		if err != nil {
			fail("read %s: %v", p, err)
		}
		s := string(b)
		if strings.Contains(strings.ToLower(s), "todo") {
			fail("unexpected TODO remains in %s", e.Name())
		}
		if strings.Contains(s, "isolated leaf in current mined graph") {
			fail("isolated leaf marker remains in %s", e.Name())
		}
	}

	rebuiltManifest := filepath.Join(rebuiltAbs, "rebuild_manifest.json")
	if _, err := os.Stat(rebuiltManifest); err != nil {
		fail("missing rebuilt manifest at %s", rebuiltManifest)
	}

	fmt.Printf("hardening checks passed.\n")
	fmt.Printf("  final_dir: %s\n", finalAbs)
	fmt.Printf("  rebuilt_dir: %s\n", rebuiltAbs)
	fmt.Printf("  strong_count: %d\n", m.StrongCount)
	fmt.Printf("  function_count: %d\n", m.FunctionCount)
	fmt.Printf("  semantic_completion_pct: %.3f\n", m.SemanticCompletionPct)
}

func fail(format string, args ...any) {
	fmt.Fprintf(os.Stderr, format+"\n", args...)
	os.Exit(1)
}

