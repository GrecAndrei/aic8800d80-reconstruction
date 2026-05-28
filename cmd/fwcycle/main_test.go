package main

import (
	"os"
	"path/filepath"
	"reflect"
	"testing"
	"time"
)

func TestLatestRunTag(t *testing.T) {
	runs := filepath.Join(t.TempDir(), "runs")
	if err := os.MkdirAll(runs, 0o755); err != nil {
		t.Fatalf("mkdir runs: %v", err)
	}
	older := filepath.Join(runs, "cycle_a")
	newer := filepath.Join(runs, "cycle_b")
	if err := os.MkdirAll(older, 0o755); err != nil {
		t.Fatalf("mkdir older: %v", err)
	}
	time.Sleep(5 * time.Millisecond)
	if err := os.MkdirAll(newer, 0o755); err != nil {
		t.Fatalf("mkdir newer: %v", err)
	}
	tag, err := latestRunTag(runs)
	if err != nil {
		t.Fatalf("latestRunTag failed: %v", err)
	}
	if tag != "cycle_b" {
		t.Fatalf("expected cycle_b, got %s", tag)
	}
}

func TestConsecutivePlateauStreak(t *testing.T) {
	history := filepath.Join(t.TempDir(), "cycle_history.jsonl")
	data := "" +
		"{\"delta_learning_smoke_success_count\":2}\n" +
		"{\"delta_learning_smoke_success_count\":0}\n" +
		"{\"delta_learning_smoke_success_count\":-1}\n"
	if err := os.WriteFile(history, []byte(data), 0o644); err != nil {
		t.Fatalf("write history: %v", err)
	}
	streak, err := consecutivePlateauStreak(history, 0)
	if err != nil {
		t.Fatalf("consecutivePlateauStreak failed: %v", err)
	}
	if streak != 2 {
		t.Fatalf("expected streak 2, got %d", streak)
	}
}

func TestClassifyPlateauModeAuto(t *testing.T) {
	report := cycleReport{
		DeltaLearningSmokeSuccessCount: 0,
		LearningReasonCounts: map[string]int{
			"learned_smoke_capped": 4,
		},
		ProbeSummary: probeSummaryCycle{
			Probed:           6,
			Capped:           4,
			Fault:            1,
			MissingSymbol:    0,
			ShallowReturn:    0,
			NontrivialReturn: 1,
			MmioTouchProbes:  0,
		},
	}
	routing, err := classifyPlateau(report, "auto")
	if err != nil {
		t.Fatalf("classifyPlateau failed: %v", err)
	}
	if routing.Mode != "deepen" {
		t.Fatalf("expected deepen mode, got %q", routing.Mode)
	}
}

func TestClassifyPlateauModeForced(t *testing.T) {
	report := cycleReport{}
	routing, err := classifyPlateau(report, "validate")
	if err != nil {
		t.Fatalf("classifyPlateau failed: %v", err)
	}
	if routing.Mode != "validate" {
		t.Fatalf("expected forced validate mode, got %q", routing.Mode)
	}
}

func TestClassifyPlateauEmptyFrontierOverridesToValidate(t *testing.T) {
	report := cycleReport{
		ControllerRecommendedMode: "synthesize",
		ControllerPrimaryAction: map[string]any{
			"name": "synthesize_new_motif_family",
		},
		ProbeSummary: probeSummaryCycle{
			CandidateCount: 0,
			Probed:         0,
			SelectedCount:  0,
		},
	}
	routing, err := classifyPlateau(report, "auto")
	if err != nil {
		t.Fatalf("classifyPlateau failed: %v", err)
	}
	if routing.Mode != "validate" {
		t.Fatalf("expected validate mode for empty frontier, got %q", routing.Mode)
	}
	if routing.PrimaryCause != "empty_frontier" {
		t.Fatalf("expected empty_frontier cause, got %q", routing.PrimaryCause)
	}
}

func TestRecentCappedFunctions(t *testing.T) {
	outcomes := filepath.Join(t.TempDir(), "smoke_observations.jsonl")
	data := "" +
		"{\"function\":\"clock_calc\",\"status\":\"capped\"}\n" +
		"{\"function\":\"rf_bus_mark\",\"status\":\"capped\"}\n" +
		"{\"function\":\"clock_calc\",\"status\":\"capped\"}\n" +
		"{\"function\":\"rf_bus_mark\",\"status\":\"returned\"}\n" +
		"{\"function\":\"tx_rate_config\",\"status\":\"capped\"}\n"
	if err := os.WriteFile(outcomes, []byte(data), 0o644); err != nil {
		t.Fatalf("write outcomes: %v", err)
	}
	focus, err := recentCappedFunctions(outcomes, 4)
	if err != nil {
		t.Fatalf("recentCappedFunctions failed: %v", err)
	}
	want := []string{"clock_calc", "tx_rate_config"}
	if !reflect.DeepEqual(focus, want) {
		t.Fatalf("unexpected focus list: got %#v want %#v", focus, want)
	}
}
