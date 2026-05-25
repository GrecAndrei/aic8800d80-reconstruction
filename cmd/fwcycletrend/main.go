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
	HasProbeSummary              bool           `json:"-"`
}

type probeSummary struct {
	Probed         int `json:"probed"`
	Success        int `json:"success"`
	Fault          int `json:"fault"`
	MissingSymbol  int `json:"missing_symbol"`
	Retried        int `json:"retried"`
	RetryRecovered int `json:"retry_recovered"`
}

type trendSummary struct {
	RowsConsidered      int     `json:"rows_considered"`
	TotalProbed         int     `json:"total_probed"`
	TotalSuccess        int     `json:"total_success"`
	TotalFault          int     `json:"total_fault"`
	TotalMissing        int     `json:"total_missing"`
	TotalRetried        int     `json:"total_retried"`
	TotalRetryRecovered int     `json:"total_retry_recovered"`
	SuccessRatePct      float64 `json:"success_rate_pct"`
	RetryRecoveryPct    float64 `json:"retry_recovery_pct"`
	DeltaFunctions      int     `json:"delta_functions"`
	DeltaPrefixes       int     `json:"delta_prefixes"`
	DeltaSmokeSuccess   int     `json:"delta_smoke_success"`
}

func main() {
	var runRoot string
	var historyPath string
	var lastN int
	var jsonOut bool
	var minSuccessRate float64
	var maxMissingRate float64
	flag.StringVar(&runRoot, "run-root", "extraction_out/reconstruction/mega7", "Reconstruction run root")
	flag.StringVar(&historyPath, "history", "", "Explicit cycle_history.jsonl path")
	flag.IntVar(&lastN, "last", 12, "How many recent cycles to show")
	flag.BoolVar(&jsonOut, "json", false, "Emit summary as JSON")
	flag.Float64Var(&minSuccessRate, "min-success-rate", 0, "If >0, fail when success rate drops below this percent")
	flag.Float64Var(&maxMissingRate, "max-missing-rate", 0, "If >0, fail when missing-symbol rate rises above this percent")
	flag.Parse()

	if historyPath == "" {
		historyPath = filepath.Join(runRoot, "cycle_history.jsonl")
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

	totalProbed := 0
	totalSuccess := 0
	totalFault := 0
	totalMiss := 0
	totalRetried := 0
	totalRecovered := 0
	sumDFunc := 0
	sumDPref := 0
	sumDSucc := 0

	for _, r := range rows {
		ps := r.ProbeSummary
		if r.HasProbeSummary {
			totalProbed += ps.Probed
			totalSuccess += ps.Success
			totalFault += ps.Fault
			totalMiss += ps.MissingSymbol
			totalRetried += ps.Retried
			totalRecovered += ps.RetryRecovered
		}
		sumDFunc += r.DeltaLearningByFunctionCount
		sumDPref += r.DeltaLearningByPrefixCount
		sumDSucc += r.DeltaLearningSmokeSuccess
	}

	successRate := pct(totalSuccess, totalProbed)
	missingRate := pct(totalMiss, totalProbed)
	recoveryRate := pct(totalRecovered, totalRetried)
	summary := trendSummary{
		RowsConsidered:      len(rows),
		TotalProbed:         totalProbed,
		TotalSuccess:        totalSuccess,
		TotalFault:          totalFault,
		TotalMissing:        totalMiss,
		TotalRetried:        totalRetried,
		TotalRetryRecovered: totalRecovered,
		SuccessRatePct:      successRate,
		RetryRecoveryPct:    recoveryRate,
		DeltaFunctions:      sumDFunc,
		DeltaPrefixes:       sumDPref,
		DeltaSmokeSuccess:   sumDSucc,
	}
	if jsonOut {
		b, _ := json.MarshalIndent(summary, "", "  ")
		fmt.Println(string(b))
	} else {
		fmt.Printf("Cycle Trend (last %d)\n", len(rows))
		fmt.Printf("%-20s %-6s %-6s %-6s %-6s %-6s %-6s %-6s\n",
			"tag", "ok", "fault", "miss", "retry", "dFunc", "dPref", "dSucc")
		for _, r := range rows {
			ps := r.ProbeSummary
			okTxt, faultTxt, missTxt, retryTxt := "n/a", "n/a", "n/a", "n/a"
			if r.HasProbeSummary {
				okTxt = fmt.Sprintf("%d", ps.Success)
				faultTxt = fmt.Sprintf("%d", ps.Fault)
				missTxt = fmt.Sprintf("%d", ps.MissingSymbol)
				retryTxt = fmt.Sprintf("%d", ps.Retried)
			}
			fmt.Printf("%-20s %-6s %-6s %-6s %-6s %-6d %-6d %-6d\n",
				r.Tag, okTxt, faultTxt, missTxt, retryTxt,
				r.DeltaLearningByFunctionCount, r.DeltaLearningByPrefixCount, r.DeltaLearningSmokeSuccess)
		}
		fmt.Printf("\nTotals: probed=%d success=%d fault=%d missing=%d retried=%d recovered=%d\n",
			totalProbed, totalSuccess, totalFault, totalMiss, totalRetried, totalRecovered)
		fmt.Printf("Rates: success=%.1f%% missing=%.1f%% retry_recovery=%.1f%%\n", successRate, missingRate, recoveryRate)
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
