package pipeline

import (
	"os"
	"path/filepath"
	"testing"
)

func TestLoadLearningSignalsTraceEnrichment(t *testing.T) {
	root := t.TempDir()
	out := filepath.Join(root, "out")
	runOut := out
	if err := os.MkdirAll(out, 0o755); err != nil {
		t.Fatalf("mkdir out: %v", err)
	}
	outcomes := filepath.Join(out, "smoke_observations.jsonl")
	content := `{"function":"ke_evt_schedule","status":"success","mmio_read_count":4,"mmio_write_count":2,"helper_touch_count":3,"branch_depth_max":2}` + "\n"
	if err := os.WriteFile(outcomes, []byte(content), 0o644); err != nil {
		t.Fatalf("write outcomes: %v", err)
	}
	funcs := []FunctionRecord{{Image: "a.bin", Name: "ke_evt_schedule"}}
	b := loadLearningSignals(root, out, runOut, funcs)
	k := "a.bin|ke_evt_schedule"
	sig, ok := b.ByFunction[k]
	if !ok {
		t.Fatalf("missing learning signal for %s", k)
	}
	if sig.Weight <= 1.3 {
		t.Fatalf("expected trace-enriched weight > base success, got %.3f", sig.Weight)
	}
	st := b.OutcomeByFunction[k]
	if st.TraceMMIO != 6 || st.TraceHelperTouch != 3 || st.TraceBranchDepthMax != 2 {
		t.Fatalf("unexpected trace stats: %#v", st)
	}
}

func TestLoadLearningSignalsOutcomeIdentityByImageAddress(t *testing.T) {
	root := t.TempDir()
	out := filepath.Join(root, "out")
	runOut := out
	if err := os.MkdirAll(out, 0o755); err != nil {
		t.Fatalf("mkdir out: %v", err)
	}
	outcomes := filepath.Join(out, "smoke_observations.jsonl")
	content := `{"image":"img_a.bin","address":"0x1000","function":"shared_fn","status":"success"}` + "\n"
	if err := os.WriteFile(outcomes, []byte(content), 0o644); err != nil {
		t.Fatalf("write outcomes: %v", err)
	}
	funcs := []FunctionRecord{
		{Image: "img_a.bin", Address: "0x1000", Name: "shared_fn"},
		{Image: "img_b.bin", Address: "0x2000", Name: "shared_fn"},
	}
	b := loadLearningSignals(root, out, runOut, funcs)
	if _, ok := b.ByFunction["img_a.bin|shared_fn"]; !ok {
		t.Fatalf("expected signal for img_a target")
	}
	if _, ok := b.ByFunction["img_b.bin|shared_fn"]; ok {
		t.Fatalf("unexpected cross-image signal leakage for img_b target")
	}
}

func TestLoadLearningSignalsCappedDoesNotCountAsSuccess(t *testing.T) {
	root := t.TempDir()
	out := filepath.Join(root, "out")
	runOut := out
	if err := os.MkdirAll(out, 0o755); err != nil {
		t.Fatalf("mkdir out: %v", err)
	}
	outcomes := filepath.Join(out, "smoke_observations.jsonl")
	content := `{"image":"img_a.bin","address":"0x1234","function":"cap_fn","status":"capped","instructions":120}` + "\n"
	if err := os.WriteFile(outcomes, []byte(content), 0o644); err != nil {
		t.Fatalf("write outcomes: %v", err)
	}
	funcs := []FunctionRecord{{Image: "img_a.bin", Address: "0x1234", Name: "cap_fn"}}
	b := loadLearningSignals(root, out, runOut, funcs)
	k := "img_a.bin|cap_fn"
	sig, ok := b.ByFunction[k]
	if !ok {
		t.Fatalf("missing learning signal for %s", k)
	}
	if sig.Reason != "learned_smoke_capped" {
		t.Fatalf("expected capped reason, got %q", sig.Reason)
	}
	st := b.OutcomeByFunction[k]
	if st.Capped != 1 || st.Success != 0 || st.Returned != 0 {
		t.Fatalf("unexpected capped stats: %#v", st)
	}
}
