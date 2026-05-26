package main

import (
	"os"
	"path/filepath"
	"testing"
)

func TestReadGateHistoryLatestPerTag(t *testing.T) {
	p := filepath.Join(t.TempDir(), "cycle_gate_history.jsonl")
	data := "" +
		"{\"tag\":\"cycle_a\",\"generated_at\":\"2026-05-26T10:00:00Z\",\"harden_status\":\"fail\"}\n" +
		"{\"tag\":\"cycle_a\",\"generated_at\":\"2026-05-26T10:05:00Z\",\"harden_status\":\"pass\"}\n" +
		"{\"tag\":\"cycle_b\",\"generated_at\":\"2026-05-26T10:01:00Z\",\"harden_status\":\"fail\"}\n"
	if err := os.WriteFile(p, []byte(data), 0o644); err != nil {
		t.Fatalf("write gate history: %v", err)
	}
	m, err := readGateHistory(p)
	if err != nil {
		t.Fatalf("readGateHistory failed: %v", err)
	}
	if m["cycle_a"] != "pass" {
		t.Fatalf("expected latest cycle_a status=pass, got %q", m["cycle_a"])
	}
	if m["cycle_b"] != "fail" {
		t.Fatalf("expected cycle_b status=fail, got %q", m["cycle_b"])
	}
}
