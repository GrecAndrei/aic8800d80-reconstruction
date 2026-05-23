package main

import (
	"os"
	"path/filepath"
	"strings"
	"testing"
)

func TestApplyBodiesReplacesWithMicroFlow(t *testing.T) {
	src := `void lpm_host_notify_bt(void) {
  // reconstructed leaf: notification helper
  return; // isolated leaf in current mined graph
}
`
	body := `void lpm_host_notify_bt(void) {
  // reconstructed micro-flow: notification helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_msg_alloc();
  ke_evt_schedule();
  // step 3: complete local state transition
}
`
	out, count, _ := applyBodies(src, map[string]string{"lpm_host_notify_bt": body})
	if count != 1 {
		t.Fatalf("expected 1 replacement, got %d", count)
	}
	if !strings.Contains(out, "reconstructed micro-flow") {
		t.Fatalf("expected micro-flow body replacement, got:\n%s", out)
	}
}

func TestLoadSynthBodiesKeepsMicroFlowBody(t *testing.T) {
	dir := t.TempDir()
	p := filepath.Join(dir, "x.synth.c")
	content := `/* meta */
void ke_evt_schedule(void) {
  // reconstructed micro-flow: event scheduler
  // step 2: execute inferred helper chain
  ke_timer_set();
}
`
	if err := os.WriteFile(p, []byte(content), 0o644); err != nil {
		t.Fatalf("write synth: %v", err)
	}
	bodies, err := loadSynthBodies(dir)
	if err != nil {
		t.Fatalf("loadSynthBodies: %v", err)
	}
	got := bodies["ke_evt_schedule"]
	if !strings.Contains(got, "reconstructed micro-flow") {
		t.Fatalf("expected micro-flow kept, got:\n%s", got)
	}
}

func TestRealSynthReplacesPanicLoopFromComposed(t *testing.T) {
	root := filepath.Clean("../../")
	synthDir := filepath.Join(root, "extraction_out/reconstruction/mega7/synth")
	composed := filepath.Join(root, "extraction_out/reconstruction/mega7/composed/fmacfw_8800d80_h_u02_bin.reconstructed.c")
	bodies, err := loadSynthBodies(synthDir)
	if err != nil {
		t.Fatalf("loadSynthBodies: %v", err)
	}
	panicBody := bodies["panic_loop"]
	if !strings.Contains(panicBody, "reconstructed micro-flow") {
		t.Fatalf("expected micro-flow panic body from synth dir")
	}
	src, err := os.ReadFile(composed)
	if err != nil {
		t.Fatalf("read composed: %v", err)
	}
	out, _, _ := applyBodies(string(src), bodies)
	if !strings.Contains(out, "void panic_loop(void) {\n  // reconstructed micro-flow: panic/abort helper") {
		t.Fatalf("panic_loop not replaced with micro-flow in composed apply path")
	}
}
