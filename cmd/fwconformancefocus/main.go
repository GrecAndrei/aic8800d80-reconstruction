package main

import (
	"encoding/json"
	"flag"
	"fmt"
	"os"
	"path/filepath"
	"sort"

	"aic8800d80/internal/fileio"
)

type row struct {
	File           string   `json:"file"`
	Function       string   `json:"function"`
	EmittedCalls   []string `json:"emitted_calls"`
	EvidenceCalls  []string `json:"evidence_calls"`
	Unsupported    []string `json:"unsupported_calls"`
	MissingLikely  []string `json:"missing_likely_calls"`
	ConformancePct float64  `json:"conformance_pct"`
	EvidenceFound  bool     `json:"evidence_found"`
}

type report struct {
	Rows []row `json:"rows"`
}

func main() {
	var inPath string
	var outPath string
	var maxItems int
	flag.StringVar(&inPath, "in", "extraction_out/reconstruction/mega7/final/call_conformance.json", "Input conformance report")
	flag.StringVar(&outPath, "out", "extraction_out/reconstruction/mega7/final/conformance_focus.json", "Output conformance focus report")
	flag.IntVar(&maxItems, "max", 120, "Maximum rows")
	flag.Parse()

	inAbs, _ := filepath.Abs(inPath)
	outAbs, _ := filepath.Abs(outPath)
	b, err := os.ReadFile(inAbs)
	if err != nil {
		fail("read input: %v", err)
	}
	var r report
	if err := json.Unmarshal(b, &r); err != nil {
		fail("parse input: %v", err)
	}
	focus := make([]row, 0, len(r.Rows))
	for _, x := range r.Rows {
		if !x.EvidenceFound {
			continue
		}
		if x.ConformancePct >= 100.0 {
			continue
		}
		focus = append(focus, x)
	}
	sort.Slice(focus, func(i, j int) bool {
		if focus[i].ConformancePct == focus[j].ConformancePct {
			if len(focus[i].Unsupported) == len(focus[j].Unsupported) {
				if focus[i].File == focus[j].File {
					return focus[i].Function < focus[j].Function
				}
				return focus[i].File < focus[j].File
			}
			return len(focus[i].Unsupported) > len(focus[j].Unsupported)
		}
		return focus[i].ConformancePct < focus[j].ConformancePct
	})
	if maxItems > 0 && len(focus) > maxItems {
		focus = focus[:maxItems]
	}
	if err := fileio.WriteJSON(outAbs, focus); err != nil {
		fail("write output: %v", err)
	}
	fmt.Printf("conformance focus generated.\n")
	fmt.Printf("  input: %s\n", inAbs)
	fmt.Printf("  focus_items: %d\n", len(focus))
	fmt.Printf("  out: %s\n", outAbs)
}

func fail(format string, args ...any) {
	fmt.Fprintf(os.Stderr, format+"\n", args...)
	os.Exit(1)
}
