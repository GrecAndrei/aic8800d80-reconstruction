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

func main() {
	var runRoot string
	var historyPath string
	var lastN int
	flag.StringVar(&runRoot, "run-root", "extraction_out/reconstruction/mega7", "Reconstruction run root")
	flag.StringVar(&historyPath, "history", "", "Explicit cycle_history.jsonl path")
	flag.IntVar(&lastN, "last", 12, "How many recent cycles to show")
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

	fmt.Printf("Cycle Trend (last %d)\n", len(rows))
	fmt.Printf("%-20s %-6s %-6s %-6s %-6s %-6s %-6s %-6s\n",
		"tag", "ok", "fault", "miss", "retry", "dFunc", "dPref", "dSucc")

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
	recoveryRate := pct(totalRecovered, totalRetried)
	fmt.Printf("\nTotals: probed=%d success=%d fault=%d missing=%d retried=%d recovered=%d\n",
		totalProbed, totalSuccess, totalFault, totalMiss, totalRetried, totalRecovered)
	fmt.Printf("Rates: success=%.1f%% retry_recovery=%.1f%%\n", successRate, recoveryRate)
	fmt.Printf("Learning deltas: functions=%d prefixes=%d smoke_success=%d\n", sumDFunc, sumDPref, sumDSucc)
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
