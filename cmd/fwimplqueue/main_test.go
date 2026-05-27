package main

import "testing"

func TestParseFocusFunctions(t *testing.T) {
	focus := parseFocusFunctions(" rf_bus_mark,tx_rate_config ,,RF_BUS_MARK ")
	if len(focus) != 2 {
		t.Fatalf("expected 2 unique focus functions, got %d", len(focus))
	}
	if _, ok := focus["rf_bus_mark"]; !ok {
		t.Fatalf("expected rf_bus_mark to be present")
	}
	if _, ok := focus["tx_rate_config"]; !ok {
		t.Fatalf("expected tx_rate_config to be present")
	}
}

func TestApplyFocusBoost(t *testing.T) {
	task := implTask{
		Function:  "rf_bus_mark",
		Priority:  "medium",
		RankScore: 8.5,
		Reasons:   []string{"baseline"},
	}
	boosted := applyFocusBoost(task, map[string]struct{}{"rf_bus_mark": {}}, 1000)
	if boosted.RankScore != 1008.5 {
		t.Fatalf("expected boosted rank score 1008.5, got %.1f", boosted.RankScore)
	}
	if boosted.Priority != "critical" {
		t.Fatalf("expected critical priority, got %q", boosted.Priority)
	}
	if len(boosted.Reasons) == 0 || boosted.Reasons[0] == "baseline" {
		t.Fatalf("expected focus reason to be prepended, got %#v", boosted.Reasons)
	}
}
