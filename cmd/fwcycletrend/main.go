package main

import (
	"bufio"
	"encoding/json"
	"flag"
	"fmt"
	"os"
	"path/filepath"
	"sort"
)

type cycleRow struct {
	Tag                          string         `json:"tag"`
	GeneratedAt                  string         `json:"generated_at"`
	DeltaLearningByFunctionCount int            `json:"delta_learning_by_function_count"`
	DeltaLearningByPrefixCount   int            `json:"delta_learning_by_prefix_count"`
	DeltaLearningSmokeSuccess    int            `json:"delta_learning_smoke_success_count"`
	ProbeSummary                 probeSummary   `json:"probe_summary"`
	ReasonCounts                 map[string]int `json:"learning_reason_counts"`
	HardenStatus                 string         `json:"harden_status,omitempty"`
	HasProbeSummary              bool           `json:"-"`
}

type gateHistoryRow struct {
	Tag          string `json:"tag"`
	GeneratedAt  string `json:"generated_at"`
	HardenStatus string `json:"harden_status"`
}

type probeSummary struct {
	Probed               int `json:"probed"`
	Success              int `json:"success"`
	Returned             int `json:"returned"`
	Capped               int `json:"capped"`
	Fault                int `json:"fault"`
	MissingSymbol        int `json:"missing_symbol"`
	Retried              int `json:"retried"`
	RetryRecovered       int `json:"retry_recovered"`
	ShallowReturn        int `json:"shallow_return"`
	NontrivialReturn     int `json:"nontrivial_return"`
	DeepProbed           int `json:"deep_probed"`
	DeepReturned         int `json:"deep_returned"`
	DeepCapped           int `json:"deep_capped"`
	DeepFault            int `json:"deep_fault"`
	MmioTouchProbes      int `json:"mmio_touch_probes"`
	RichTraceProbes      int `json:"rich_trace_probes"`
	SelectedDistinctImgs int `json:"selected_distinct_images"`
}

type trendSummary struct {
	RowsConsidered       int     `json:"rows_considered"`
	TotalProbed          int     `json:"total_probed"`
	TotalSuccess         int     `json:"total_success"`
	TotalFault           int     `json:"total_fault"`
	TotalMissing         int     `json:"total_missing"`
	TotalRetried         int     `json:"total_retried"`
	TotalRetryRecovered  int     `json:"total_retry_recovered"`
	SuccessRatePct       float64 `json:"success_rate_pct"`
	NaturalReturnRatePct float64 `json:"natural_return_rate_pct"`
	CapHitRatePct        float64 `json:"cap_hit_rate_pct"`
	NontrivialRatePct    float64 `json:"nontrivial_rate_pct"`
	MmioTouchRatePct     float64 `json:"mmio_touch_rate_pct"`
	WrapperDominancePct  float64 `json:"wrapper_dominance_pct"`
	DeepReturnRatePct    float64 `json:"deep_return_rate_pct"`
	AvgDistinctImages    float64 `json:"avg_distinct_images"`
	RetryRecoveryPct     float64 `json:"retry_recovery_pct"`
	HardenEvaluated      int     `json:"harden_evaluated"`
	HardenPass           int     `json:"harden_pass"`
	HardenFail           int     `json:"harden_fail"`
	HardenPassRatePct    float64 `json:"harden_pass_rate_pct"`
	DeltaFunctions       int     `json:"delta_functions"`
	DeltaPrefixes        int     `json:"delta_prefixes"`
	DeltaSmokeSuccess    int     `json:"delta_smoke_success"`
}

func main() {
	var runRoot string
	var historyPath string
	var gateHistoryPath string
	var lastN int
	var jsonOut bool
	var minSuccessRate float64
	var maxMissingRate float64
	var minHardenPassRate float64
	var minNaturalReturnRate float64
	var maxCapHitRate float64
	var minNontrivialRate float64
	var minMmioTouchRate float64
	var minAvgDistinctImages float64
	var maxWrapperDominanceRate float64
	var minDeepReturnRate float64
	flag.StringVar(&runRoot, "run-root", "extraction_out/reconstruction/mega7", "Reconstruction run root")
	flag.StringVar(&historyPath, "history", "", "Explicit cycle_history.jsonl path")
	flag.StringVar(&gateHistoryPath, "gate-history", "", "Explicit cycle_gate_history.jsonl path")
	flag.IntVar(&lastN, "last", 12, "How many recent cycles to show")
	flag.BoolVar(&jsonOut, "json", false, "Emit summary as JSON")
	flag.Float64Var(&minSuccessRate, "min-success-rate", 0, "If >0, fail when success rate drops below this percent")
	flag.Float64Var(&maxMissingRate, "max-missing-rate", 0, "If >0, fail when missing-symbol rate rises above this percent")
	flag.Float64Var(&minHardenPassRate, "min-harden-pass-rate", 0, "If >0, fail when harden pass rate drops below this percent")
	flag.Float64Var(&minNaturalReturnRate, "min-natural-return-rate", 0, "If >0, fail when natural return rate drops below this percent")
	flag.Float64Var(&maxCapHitRate, "max-cap-hit-rate", 0, "If >0, fail when cap-hit rate rises above this percent")
	flag.Float64Var(&minNontrivialRate, "min-nontrivial-rate", 0, "If >0, fail when nontrivial return rate drops below this percent")
	flag.Float64Var(&minMmioTouchRate, "min-mmio-touch-rate", 0, "If >0, fail when MMIO-touch probe rate drops below this percent")
	flag.Float64Var(&minAvgDistinctImages, "min-image-diversity", 0, "If >0, fail when avg distinct selected images per cycle drops below this value")
	flag.Float64Var(&maxWrapperDominanceRate, "max-wrapper-dominance-rate", 0, "If >0, fail when shallow-wrapper dominance rises above this percent")
	flag.Float64Var(&minDeepReturnRate, "min-deep-return-rate", 0, "If >0, fail when deep-pass return rate drops below this percent")
	flag.Parse()

	if historyPath == "" {
		historyPath = filepath.Join(runRoot, "cycle_history.jsonl")
	}
	if gateHistoryPath == "" {
		gateHistoryPath = filepath.Join(runRoot, "cycle_gate_history.jsonl")
	}
	rows, err := readRows(historyPath)
	if err != nil {
		fmt.Fprintf(os.Stderr, "read cycle history: %v\n", err)
		os.Exit(1)
	}
	if len(rows) == 0 {
		fmt.Println("no cycle rows found")
		return
	}
	if lastN <= 0 || lastN > len(rows) {
		lastN = len(rows)
	}
	rows = rows[len(rows)-lastN:]
	if gm, err := readGateHistory(gateHistoryPath); err == nil {
		for i := range rows {
			if st, ok := gm[rows[i].Tag]; ok {
				rows[i].HardenStatus = st
			}
		}
	}

	totalProbed := 0
	totalSuccess := 0
	totalFault := 0
	totalMiss := 0
	totalRetried := 0
	totalRecovered := 0
	totalReturned := 0
	totalCapped := 0
	totalShallow := 0
	totalNontrivial := 0
	totalMmioTouch := 0
	totalDeepProbed := 0
	totalDeepReturned := 0
	totalDistinctImages := 0
	distinctImageRows := 0
	sumDFunc := 0
	sumDPref := 0
	sumDSucc := 0
	hardenEval := 0
	hardenPass := 0
	hardenFail := 0

	for _, r := range rows {
		ps := r.ProbeSummary
		if r.HasProbeSummary {
			totalProbed += ps.Probed
			totalSuccess += ps.Success
			totalReturned += ps.Returned
			totalCapped += ps.Capped
			totalFault += ps.Fault
			totalMiss += ps.MissingSymbol
			totalRetried += ps.Retried
			totalRecovered += ps.RetryRecovered
			totalShallow += ps.ShallowReturn
			totalNontrivial += ps.NontrivialReturn
			totalMmioTouch += ps.MmioTouchProbes
			totalDeepProbed += ps.DeepProbed
			totalDeepReturned += ps.DeepReturned
			if ps.SelectedDistinctImgs > 0 {
				totalDistinctImages += ps.SelectedDistinctImgs
				distinctImageRows++
			}
		}
		sumDFunc += r.DeltaLearningByFunctionCount
		sumDPref += r.DeltaLearningByPrefixCount
		sumDSucc += r.DeltaLearningSmokeSuccess
		if r.HardenStatus != "" {
			hardenEval++
			if r.HardenStatus == "pass" {
				hardenPass++
			} else {
				hardenFail++
			}
		}
	}

	successRate := pct(totalSuccess, totalProbed)
	missingRate := pct(totalMiss, totalProbed)
	naturalReturnRate := pct(totalReturned, totalProbed)
	capHitRate := pct(totalCapped, totalProbed)
	nontrivialRate := pct(totalNontrivial, totalProbed)
	mmioTouchRate := pct(totalMmioTouch, totalProbed)
	wrapperDominanceRate := pct(totalShallow, totalProbed)
	deepReturnRate := pct(totalDeepReturned, totalDeepProbed)
	recoveryRate := pct(totalRecovered, totalRetried)
	hardenPassRate := pct(hardenPass, hardenEval)
	avgDistinctImages := 0.0
	if distinctImageRows > 0 {
		avgDistinctImages = float64(totalDistinctImages) / float64(distinctImageRows)
	}
	summary := trendSummary{
		RowsConsidered:       len(rows),
		TotalProbed:          totalProbed,
		TotalSuccess:         totalSuccess,
		TotalFault:           totalFault,
		TotalMissing:         totalMiss,
		TotalRetried:         totalRetried,
		TotalRetryRecovered:  totalRecovered,
		SuccessRatePct:       successRate,
		NaturalReturnRatePct: naturalReturnRate,
		CapHitRatePct:        capHitRate,
		NontrivialRatePct:    nontrivialRate,
		MmioTouchRatePct:     mmioTouchRate,
		WrapperDominancePct:  wrapperDominanceRate,
		DeepReturnRatePct:    deepReturnRate,
		AvgDistinctImages:    avgDistinctImages,
		RetryRecoveryPct:     recoveryRate,
		HardenEvaluated:      hardenEval,
		HardenPass:           hardenPass,
		HardenFail:           hardenFail,
		HardenPassRatePct:    hardenPassRate,
		DeltaFunctions:       sumDFunc,
		DeltaPrefixes:        sumDPref,
		DeltaSmokeSuccess:    sumDSucc,
	}
	if jsonOut {
		b, _ := json.MarshalIndent(summary, "", "  ")
		fmt.Println(string(b))
	} else {
		fmt.Printf("Cycle Trend (last %d)\n", len(rows))
		fmt.Printf("%-20s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s\n",
			"tag", "ok", "fault", "miss", "retry", "gate", "dFunc", "dPref", "dSucc")
		for _, r := range rows {
			ps := r.ProbeSummary
			okTxt, faultTxt, missTxt, retryTxt := "n/a", "n/a", "n/a", "n/a"
			gateTxt := "n/a"
			if r.HasProbeSummary {
				okTxt = fmt.Sprintf("%d", ps.Success)
				faultTxt = fmt.Sprintf("%d", ps.Fault)
				missTxt = fmt.Sprintf("%d", ps.MissingSymbol)
				retryTxt = fmt.Sprintf("%d", ps.Retried)
			}
			if r.HardenStatus != "" {
				gateTxt = r.HardenStatus
			}
			fmt.Printf("%-20s %-6s %-6s %-6s %-6s %-6s %-6d %-6d %-6d\n",
				r.Tag, okTxt, faultTxt, missTxt, retryTxt, gateTxt,
				r.DeltaLearningByFunctionCount, r.DeltaLearningByPrefixCount, r.DeltaLearningSmokeSuccess)
		}
		fmt.Printf("\nTotals: probed=%d success=%d fault=%d missing=%d retried=%d recovered=%d\n",
			totalProbed, totalSuccess, totalFault, totalMiss, totalRetried, totalRecovered)
		fmt.Printf("Rates: success=%.1f%% natural_return=%.1f%% cap_hit=%.1f%% nontrivial=%.1f%% mmio_touch=%.1f%% wrapper_dominance=%.1f%% deep_return=%.1f%% missing=%.1f%% retry_recovery=%.1f%%\n", successRate, naturalReturnRate, capHitRate, nontrivialRate, mmioTouchRate, wrapperDominanceRate, deepReturnRate, missingRate, recoveryRate)
		fmt.Printf("Behavior: avg_distinct_images=%.2f\n", avgDistinctImages)
		fmt.Printf("Harden: evaluated=%d pass=%d fail=%d pass_rate=%.1f%%\n", hardenEval, hardenPass, hardenFail, hardenPassRate)
		fmt.Printf("Learning deltas: functions=%d prefixes=%d smoke_success=%d\n", sumDFunc, sumDPref, sumDSucc)
	}

	if minSuccessRate > 0 && successRate < minSuccessRate {
		fmt.Fprintf(os.Stderr, "trend gate failed: success rate %.1f%% < %.1f%%\n", successRate, minSuccessRate)
		os.Exit(2)
	}
	if maxMissingRate > 0 && missingRate > maxMissingRate {
		fmt.Fprintf(os.Stderr, "trend gate failed: missing rate %.1f%% > %.1f%%\n", missingRate, maxMissingRate)
		os.Exit(3)
	}
	if minHardenPassRate > 0 && hardenEval > 0 && hardenPassRate < minHardenPassRate {
		fmt.Fprintf(os.Stderr, "trend gate failed: harden pass rate %.1f%% < %.1f%%\n", hardenPassRate, minHardenPassRate)
		os.Exit(4)
	}
	if minNaturalReturnRate > 0 && naturalReturnRate < minNaturalReturnRate {
		fmt.Fprintf(os.Stderr, "trend gate failed: natural return rate %.1f%% < %.1f%%\n", naturalReturnRate, minNaturalReturnRate)
		os.Exit(5)
	}
	if maxCapHitRate > 0 && capHitRate > maxCapHitRate {
		fmt.Fprintf(os.Stderr, "trend gate failed: cap-hit rate %.1f%% > %.1f%%\n", capHitRate, maxCapHitRate)
		os.Exit(6)
	}
	if minNontrivialRate > 0 && nontrivialRate < minNontrivialRate {
		fmt.Fprintf(os.Stderr, "trend gate failed: nontrivial rate %.1f%% < %.1f%%\n", nontrivialRate, minNontrivialRate)
		os.Exit(7)
	}
	if minMmioTouchRate > 0 && mmioTouchRate < minMmioTouchRate {
		fmt.Fprintf(os.Stderr, "trend gate failed: mmio-touch rate %.1f%% < %.1f%%\n", mmioTouchRate, minMmioTouchRate)
		os.Exit(8)
	}
	if minAvgDistinctImages > 0 && avgDistinctImages < minAvgDistinctImages {
		fmt.Fprintf(os.Stderr, "trend gate failed: image diversity %.2f < %.2f\n", avgDistinctImages, minAvgDistinctImages)
		os.Exit(9)
	}
	if maxWrapperDominanceRate > 0 && wrapperDominanceRate > maxWrapperDominanceRate {
		fmt.Fprintf(os.Stderr, "trend gate failed: wrapper dominance %.1f%% > %.1f%%\n", wrapperDominanceRate, maxWrapperDominanceRate)
		os.Exit(10)
	}
	if minDeepReturnRate > 0 && totalDeepProbed > 0 && deepReturnRate < minDeepReturnRate {
		fmt.Fprintf(os.Stderr, "trend gate failed: deep return rate %.1f%% < %.1f%%\n", deepReturnRate, minDeepReturnRate)
		os.Exit(11)
	}
}

func readGateHistory(path string) (map[string]string, error) {
	f, err := os.Open(path)
	if err != nil {
		return nil, err
	}
	defer f.Close()
	out := map[string]string{}
	seen := map[string]string{}
	s := bufio.NewScanner(f)
	s.Buffer(make([]byte, 1024), 2*1024*1024)
	for s.Scan() {
		line := s.Bytes()
		var r gateHistoryRow
		if err := json.Unmarshal(line, &r); err != nil {
			continue
		}
		if r.Tag == "" || r.HardenStatus == "" {
			continue
		}
		prevAt := seen[r.Tag]
		if prevAt == "" || prevAt <= r.GeneratedAt {
			seen[r.Tag] = r.GeneratedAt
			out[r.Tag] = r.HardenStatus
		}
	}
	if err := s.Err(); err != nil {
		return nil, err
	}
	return out, nil
}

func readRows(path string) ([]cycleRow, error) {
	f, err := os.Open(path)
	if err != nil {
		return nil, err
	}
	defer f.Close()

	out := make([]cycleRow, 0, 128)
	s := bufio.NewScanner(f)
	s.Buffer(make([]byte, 1024), 2*1024*1024)
	for s.Scan() {
		line := s.Bytes()
		var raw map[string]json.RawMessage
		if err := json.Unmarshal(line, &raw); err != nil {
			continue
		}
		var r cycleRow
		if err := json.Unmarshal(line, &r); err != nil {
			continue
		}
		if r.Tag == "" {
			continue
		}
		_, r.HasProbeSummary = raw["probe_summary"]
		out = append(out, r)
	}
	if err := s.Err(); err != nil {
		return nil, err
	}
	sort.Slice(out, func(i, j int) bool { return out[i].GeneratedAt < out[j].GeneratedAt })
	return out, nil
}

func pct(numer int, denom int) float64 {
	if denom <= 0 {
		return 0
	}
	return float64(numer) * 100.0 / float64(denom)
}
