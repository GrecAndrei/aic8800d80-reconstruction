package main

import (
	"os"
	"path/filepath"
	"strings"
	"testing"

	"aic8800d80/internal/reconstruct"
)

func TestFunctionRoleHandlerNormalization(t *testing.T) {
	tests := []struct {
		fn   string
		want string
	}{
		{"mm_key_del_req_handler", "key delete request handler"},
		{"mm_set_arpoffload_en_req_handler", "set arp offload en request handler"},
		{"apm_stop_cac_req_handler", "stop CAC request handler"},
		{"ke_timer_set", "kernel timer set helper"},
	}
	for _, tc := range tests {
		got := functionRole(tc.fn)
		if got != tc.want {
			t.Fatalf("%s: got %q want %q", tc.fn, got, tc.want)
		}
	}
}

func TestWriteSynthUsesNormalizedRoleText(t *testing.T) {
	dir := t.TempDir()
	p := filepath.Join(dir, "x.synth.c")
	task := implTask{
		TaskID:    "test",
		Function:  "mm_key_del_req_handler",
		Image:     "fmacfw_8800d80_h_u02.bin",
		Address:   "0x0",
		TaskClass: "behavior_lift",
		Priority:  "medium",
		RankScore: 1.0,
	}
	if err := writeSynth(p, task, nil, nil, nil, nil, nil, nil, synthPolicy{}, "", ""); err != nil {
		t.Fatalf("writeSynth: %v", err)
	}
	b, err := os.ReadFile(p)
	if err != nil {
		t.Fatalf("read synth: %v", err)
	}
	s := string(b)
	if !strings.Contains(s, "key delete request handler") {
		t.Fatalf("missing normalized role in synth output:\n%s", s)
	}
}

func TestClearStaleSynthFilesCreatesMissingDir(t *testing.T) {
	dir := filepath.Join(t.TempDir(), "synth")
	if err := clearStaleSynthFiles(dir); err != nil {
		t.Fatalf("clearStaleSynthFiles: %v", err)
	}
	if _, err := os.Stat(dir); err != nil {
		t.Fatalf("stat synth dir: %v", err)
	}
}

func TestInferFromPseudoHintsFiltersSelfAndIntrinsics(t *testing.T) {
	task := implTask{Function: "crypto_hw_enable"}
	p := &pseudoHint{CallNames: []string{"crypto_hw_enable", "__disable_irq", "sub_123456", "rf_bus_mark", "HIDWORD"}}
	out := inferFromPseudoHints(task, p, 0.7, 0.4)
	if len(out) != 2 {
		t.Fatalf("expected 2 pseudo-inferred callees, got %d", len(out))
	}
	if out[0].TargetName != "sub_123456" || out[1].TargetName != "rf_bus_mark" {
		t.Fatalf("unexpected pseudo callee names: %#v", out)
	}
}

func TestShouldBypassGenericIncoming(t *testing.T) {
	desc := &reconstruct.FunctionDescriptor{}
	desc.Motif.Family = "register_commit"
	genericOnly := []callEdge{{TargetName: "ke_evt_schedule"}, {TargetName: "msg_parse"}}
	if !shouldBypassGenericIncoming(desc, genericOnly) {
		t.Fatalf("expected bypass for generic-only selected calls")
	}
	mixed := []callEdge{{TargetName: "ke_evt_schedule"}, {TargetName: "rf_bus_write2"}}
	if shouldBypassGenericIncoming(desc, mixed) {
		t.Fatalf("did not expect bypass when non-generic call exists")
	}
}
