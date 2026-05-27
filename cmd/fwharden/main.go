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

type contractReport struct {
	SchemaVersion string `json:"schema_version"`
	Violations    int    `json:"violations"`
}

type conformanceReport struct {
	SchemaVersion     string  `json:"schema_version,omitempty"`
	EvaluableCount    int     `json:"evaluable_count"`
	AvgConformancePct float64 `json:"avg_conformance_pct"`
	Holdout           struct {
		InSample struct {
			EvaluableCount    int     `json:"evaluable_count"`
			AvgConformancePct float64 `json:"avg_conformance_pct"`
			NonperfectCount   int     `json:"nonperfect_count"`
		} `json:"in_sample"`
		OutSample struct {
			EvaluableCount    int     `json:"evaluable_count"`
			AvgConformancePct float64 `json:"avg_conformance_pct"`
			NonperfectCount   int     `json:"nonperfect_count"`
		} `json:"out_of_sample"`
	} `json:"holdout"`
	Rows []struct {
		EvidenceFound  bool    `json:"evidence_found"`
		ConformancePct float64 `json:"conformance_pct"`
	} `json:"rows"`
}

type cycleProbeSummary struct {
	Probed               int `json:"probed"`
	Returned             int `json:"returned"`
	Capped               int `json:"capped"`
	ShallowReturn        int `json:"shallow_return"`
	NontrivialReturn     int `json:"nontrivial_return"`
	MmioTouchProbes      int `json:"mmio_touch_probes"`
	DeepProbed           int `json:"deep_probed"`
	DeepReturned         int `json:"deep_returned"`
	SelectedDistinctImgs int `json:"selected_distinct_images"`
}

type cycleReport struct {
	ProbeSummary cycleProbeSummary `json:"probe_summary"`
}

type descriptorSummary struct {
	DescriptorCount   int            `json:"descriptor_count"`
	MotifBackedCount  int            `json:"motif_backed_count"`
	PhenotypeCounts   map[string]int `json:"phenotype_counts,omitempty"`
	MotifFamilyCounts map[string]int `json:"motif_family_counts,omitempty"`
}

type qualityRow struct {
	Risk                string `json:"risk"`
	DescriptorPhenotype string `json:"descriptor_phenotype,omitempty"`
	MotifFamily         string `json:"motif_family,omitempty"`
}

func pct(numer int, denom int) float64 {
	if denom <= 0 {
		return 0
	}
	return float64(numer) * 100.0 / float64(denom)
}

func main() {
	var finalDir string
	var rebuiltDir string
	var strict bool
	var cycleReportPath string
	var minNaturalReturnRate float64
	var maxCapHitRate float64
	var minNontrivialRate float64
	var minMmioTouchRate float64
	var minDistinctImages int
	var maxWrapperDominanceRate float64
	var minDeepReturnRate float64
	var descriptorSummaryPath string
	var qualityPath string
	var minMotifBackedCount int
	var maxCappedMMIOPhenotypes int
	var maxHighRiskFunctions int

	flag.StringVar(&finalDir, "final-dir", "extraction_out/reconstruction/mega7/final", "Final reconstruction directory")
	flag.StringVar(&rebuiltDir, "rebuilt-dir", "extraction_out/reconstruction/mega7/rebuilt", "Rebuilt artifacts directory")
	flag.BoolVar(&strict, "strict", false, "Enable release-level gates (100% completion, no TODOs, no fallbacks)")
	flag.StringVar(&cycleReportPath, "cycle-report", "", "Cycle report path for behavioral-depth gate checks")
	flag.Float64Var(&minNaturalReturnRate, "min-natural-return-rate", 0.0, "Minimum natural-return rate percent")
	flag.Float64Var(&maxCapHitRate, "max-cap-hit-rate", 95.0, "Maximum capped-probe rate percent")
	flag.Float64Var(&minNontrivialRate, "min-nontrivial-rate", 0.0, "Minimum nontrivial-return rate percent")
	flag.Float64Var(&minMmioTouchRate, "min-mmio-touch-rate", 0.0, "Minimum MMIO-touch probe rate percent")
	flag.IntVar(&minDistinctImages, "min-distinct-images", 1, "Minimum distinct images in selected probe set")
	flag.Float64Var(&maxWrapperDominanceRate, "max-wrapper-dominance-rate", 100.0, "Maximum shallow-wrapper dominance percent")
	flag.Float64Var(&minDeepReturnRate, "min-deep-return-rate", 0.0, "Minimum deep-pass return rate percent when deep pass runs")
	flag.StringVar(&descriptorSummaryPath, "descriptor-summary", "extraction_out/reconstruction/mega7/analysis/descriptor_summary.json", "Descriptor summary JSON path")
	flag.StringVar(&qualityPath, "quality", "extraction_out/reconstruction/mega7/final/finalize_quality.json", "Finalize quality JSON path")
	flag.IntVar(&minMotifBackedCount, "min-motif-backed-count", 0, "Minimum descriptor motif-backed function count")
	flag.IntVar(&maxCappedMMIOPhenotypes, "max-capped-mmio-phenotypes", 0, "Maximum allowed capped_mmio_wait descriptor count (0 disables)")
	flag.IntVar(&maxHighRiskFunctions, "max-high-risk-functions", 0, "Maximum allowed high-risk functions in finalize_quality (0 disables)")
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

	// ----- health gates (always active) -----

	if m.FunctionCount == 0 || m.FileCount == 0 {
		fail("empty finalize output: functions=%d files=%d", m.FunctionCount, m.FileCount)
	}

	applyContractPath := filepath.Join(filepath.Dir(finalAbs), "applied", "apply_contracts.json")
	if b, err := os.ReadFile(applyContractPath); err == nil {
		var c contractReport
		if err := json.Unmarshal(b, &c); err != nil {
			fail("parse apply contract report: %v", err)
		}
		if c.Violations != 0 {
			fail("apply contract gate failed: violations=%d", c.Violations)
		}
	} else {
		fail("missing apply contract report: %s", applyContractPath)
	}
	finalizeContractPath := filepath.Join(finalAbs, "finalize_contracts.json")
	if b, err := os.ReadFile(finalizeContractPath); err == nil {
		var c contractReport
		if err := json.Unmarshal(b, &c); err != nil {
			fail("parse finalize contract report: %v", err)
		}
		if c.Violations != 0 {
			fail("finalize contract gate failed: violations=%d", c.Violations)
		}
	} else {
		fail("missing finalize contract report: %s", finalizeContractPath)
	}
	conformancePath := filepath.Join(finalAbs, "call_conformance.json")
	if cb, err := os.ReadFile(conformancePath); err == nil {
		var c conformanceReport
		if err := json.Unmarshal(cb, &c); err != nil {
			fail("parse call conformance report: %v", err)
		}
		low := 0
		for _, r := range c.Rows {
			if r.EvidenceFound && r.ConformancePct < 100.0 {
				low++
			}
		}
		if c.EvaluableCount > 0 {
			if c.AvgConformancePct < 100.0 {
				fail("call conformance gate failed: avg_conformance_pct=%.3f", c.AvgConformancePct)
			}
			if low != 0 {
				fail("call conformance gate failed: nonperfect_functions=%d", low)
			}
			if strings.TrimSpace(c.SchemaVersion) == "" {
				fmt.Fprintf(os.Stderr, "conformance health: holdout skipped (missing schema_version, re-run fwvalidatecalls to enable)\n")
			}
			if c.Holdout.InSample.EvaluableCount > 0 && strings.TrimSpace(c.SchemaVersion) != "" {
				if c.Holdout.InSample.AvgConformancePct < 100.0 || c.Holdout.InSample.NonperfectCount != 0 {
					fail("holdout in-sample gate failed: avg=%.3f nonperfect=%d", c.Holdout.InSample.AvgConformancePct, c.Holdout.InSample.NonperfectCount)
				}
			}
			if c.Holdout.OutSample.EvaluableCount > 0 && strings.TrimSpace(c.SchemaVersion) != "" {
				if c.Holdout.OutSample.AvgConformancePct < 100.0 || c.Holdout.OutSample.NonperfectCount != 0 {
					fail("holdout out-of-sample gate failed: avg=%.3f nonperfect=%d", c.Holdout.OutSample.AvgConformancePct, c.Holdout.OutSample.NonperfectCount)
				}
			}
		}
	}

	rebuiltManifest := filepath.Join(rebuiltAbs, "rebuild_manifest.json")
	if _, err := os.Stat(rebuiltManifest); err != nil {
		fail("missing rebuilt manifest at %s", rebuiltManifest)
	}

	if strings.TrimSpace(cycleReportPath) == "" {
		cycleReportPath = filepath.Join(filepath.Dir(finalAbs), "cycle_report.json")
	}
	if b, err := os.ReadFile(cycleReportPath); err == nil {
		var cr cycleReport
		if err := json.Unmarshal(b, &cr); err != nil {
			fail("parse cycle report: %v", err)
		}
		ps := cr.ProbeSummary
		if ps.Probed > 0 {
			naturalRate := pct(ps.Returned, ps.Probed)
			capRate := pct(ps.Capped, ps.Probed)
			nontrivialRate := pct(ps.NontrivialReturn, ps.Probed)
			mmioRate := pct(ps.MmioTouchProbes, ps.Probed)
			wrapperRate := pct(ps.ShallowReturn, ps.Probed)
			deepRate := pct(ps.DeepReturned, ps.DeepProbed)

			if minNaturalReturnRate > 0 && naturalRate < minNaturalReturnRate {
				fail("behavior gate failed: natural return rate %.1f%% < %.1f%%", naturalRate, minNaturalReturnRate)
			}
			if maxCapHitRate > 0 && capRate > maxCapHitRate {
				fail("behavior gate failed: cap-hit rate %.1f%% > %.1f%%", capRate, maxCapHitRate)
			}
			if minNontrivialRate > 0 && nontrivialRate < minNontrivialRate {
				fail("behavior gate failed: nontrivial rate %.1f%% < %.1f%%", nontrivialRate, minNontrivialRate)
			}
			if minMmioTouchRate > 0 && mmioRate < minMmioTouchRate {
				fail("behavior gate failed: mmio-touch rate %.1f%% < %.1f%%", mmioRate, minMmioTouchRate)
			}
			if minDistinctImages > 0 && ps.SelectedDistinctImgs > 0 && ps.SelectedDistinctImgs < minDistinctImages {
				fail("behavior gate failed: distinct images %d < %d", ps.SelectedDistinctImgs, minDistinctImages)
			}
			if maxWrapperDominanceRate > 0 && wrapperRate > maxWrapperDominanceRate {
				fail("behavior gate failed: wrapper dominance %.1f%% > %.1f%%", wrapperRate, maxWrapperDominanceRate)
			}
			if minDeepReturnRate > 0 && ps.DeepProbed > 0 && deepRate < minDeepReturnRate {
				fail("behavior gate failed: deep return rate %.1f%% < %.1f%%", deepRate, minDeepReturnRate)
			}
		}
	} else {
		fmt.Fprintf(os.Stderr, "behavior health: cycle report not found at %s (skipping behavioral-depth gates)\n", cycleReportPath)
	}
	if b, err := os.ReadFile(descriptorSummaryPath); err == nil {
		var ds descriptorSummary
		if err := json.Unmarshal(b, &ds); err != nil {
			fail("parse descriptor summary: %v", err)
		}
		if minMotifBackedCount > 0 && ds.MotifBackedCount < minMotifBackedCount {
			fail("descriptor gate failed: motif_backed_count %d < %d", ds.MotifBackedCount, minMotifBackedCount)
		}
		if maxCappedMMIOPhenotypes > 0 {
			cappedMMIO := 0
			if ds.PhenotypeCounts != nil {
				cappedMMIO = ds.PhenotypeCounts["capped_mmio_wait"]
			}
			if cappedMMIO > maxCappedMMIOPhenotypes {
				fail("descriptor gate failed: capped_mmio_wait count %d > %d", cappedMMIO, maxCappedMMIOPhenotypes)
			}
		}
	} else if minMotifBackedCount > 0 || maxCappedMMIOPhenotypes > 0 {
		fail("missing descriptor summary: %s", descriptorSummaryPath)
	}
	if b, err := os.ReadFile(qualityPath); err == nil {
		var rows []qualityRow
		if err := json.Unmarshal(b, &rows); err != nil {
			fail("parse quality report: %v", err)
		}
		if maxHighRiskFunctions > 0 {
			high := 0
			for _, row := range rows {
				if row.Risk == "high" {
					high++
				}
			}
			if high > maxHighRiskFunctions {
				fail("quality gate failed: high-risk functions %d > %d", high, maxHighRiskFunctions)
			}
		}
	} else if maxHighRiskFunctions > 0 {
		fail("missing quality report: %s", qualityPath)
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
		if strings.Contains(s, "isolated leaf in current mined graph") {
			fail("isolated leaf marker remains in %s", e.Name())
		}
	}

	// ----- release gates (--strict only) -----

	if strict {
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
		}
	}

	fmt.Printf("hardening checks passed.\n")
	fmt.Printf("  final_dir: %s\n", finalAbs)
	fmt.Printf("  rebuilt_dir: %s\n", rebuiltAbs)
	fmt.Printf("  strong_count: %d\n", m.StrongCount)
	fmt.Printf("  function_count: %d\n", m.FunctionCount)
	fmt.Printf("  semantic_completion_pct: %.3f\n", m.SemanticCompletionPct)
	fmt.Printf("  cycle_report: %s\n", cycleReportPath)
	if strict {
		fmt.Printf("  mode: strict (release gates active)\n")
	} else {
		fmt.Printf("  mode: health (contract + conformance + holdout gates only)\n")
	}
}

func fail(format string, args ...any) {
	fmt.Fprintf(os.Stderr, format+"\n", args...)
	os.Exit(1)
}
