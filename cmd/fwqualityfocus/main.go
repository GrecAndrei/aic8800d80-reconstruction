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

type functionQuality struct {
	File             string   `json:"file"`
	Function         string   `json:"function"`
	CallCount        int      `json:"call_count"`
	Calls            []string `json:"calls"`
	Risk             string   `json:"risk"`
	Reasons          []string `json:"reasons"`
	TemplateEvidence bool     `json:"template_evidence"`
}

type focusItem struct {
	File      string   `json:"file"`
	Function  string   `json:"function"`
	Risk      string   `json:"risk"`
	Reasons   []string `json:"reasons"`
	Calls     []string `json:"calls"`
	NextSteps []string `json:"next_steps"`
}

func main() {
	var qualityPath string
	var outPath string
	var maxItems int
	flag.StringVar(&qualityPath, "quality", "extraction_out/reconstruction/mega7/final/finalize_quality.json", "Finalize quality report")
	flag.StringVar(&outPath, "out", "extraction_out/reconstruction/mega7/final/quality_focus.json", "Focused triage output")
	flag.IntVar(&maxItems, "max", 120, "Maximum focus items")
	flag.Parse()

	qAbs, _ := filepath.Abs(qualityPath)
	oAbs, _ := filepath.Abs(outPath)
	b, err := os.ReadFile(qAbs)
	if err != nil {
		fail("read quality report: %v", err)
	}
	var rows []functionQuality
	if err := json.Unmarshal(b, &rows); err != nil {
		fail("parse quality report: %v", err)
	}
	items := make([]focusItem, 0, len(rows))
	for _, r := range rows {
		if r.Risk == "low" {
			continue
		}
		items = append(items, focusItem{
			File:      r.File,
			Function:  r.Function,
			Risk:      r.Risk,
			Reasons:   append([]string(nil), r.Reasons...),
			Calls:     append([]string(nil), r.Calls...),
			NextSteps: suggestNextSteps(r),
		})
	}
	sort.Slice(items, func(i, j int) bool {
		ord := map[string]int{"high": 0, "medium": 1, "low": 2}
		if items[i].Risk == items[j].Risk {
			if items[i].File == items[j].File {
				return items[i].Function < items[j].Function
			}
			return items[i].File < items[j].File
		}
		return ord[items[i].Risk] < ord[items[j].Risk]
	})
	if maxItems > 0 && len(items) > maxItems {
		items = items[:maxItems]
	}
	if err := fileio.WriteJSON(oAbs, items); err != nil {
		fail("write focus: %v", err)
	}
	fmt.Printf("quality focus generated.\n")
	fmt.Printf("  quality_report: %s\n", qAbs)
	fmt.Printf("  focus_items: %d\n", len(items))
	fmt.Printf("  out_path: %s\n", oAbs)
}

func suggestNextSteps(r functionQuality) []string {
	steps := []string{
		"Confirm call targets with xrefs in IDA",
		"Recover branch conditions and side effects from decompilation",
		"Replace templated helper chain with evidence-backed calls",
	}
	for _, reason := range r.Reasons {
		if reason == "opaque_sub_function" {
			steps = append([]string{"Rename function from caller/context evidence before behavior lift"}, steps...)
			break
		}
	}
	if len(r.Calls) == 1 && r.Calls[0] == "ke_evt_schedule" {
		steps = append([]string{"Validate whether ke_evt_schedule is real or placeholder dispatch"}, steps...)
	}
	return steps
}

func fail(format string, args ...any) {
	fmt.Fprintf(os.Stderr, format+"\n", args...)
	os.Exit(1)
}
