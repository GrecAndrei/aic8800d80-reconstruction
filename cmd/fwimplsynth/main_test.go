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

func TestVariantStripCandidates(t *testing.T) {
	tests := []struct {
		in   string
		want []string
	}{
		{"rf_bus_write2", []string{"rf_bus_write"}},
		{"rf_reg_write_core", []string{"rf_reg_write"}},
		{"rf_reg_write_cb", []string{"rf_reg_write"}},
		{"rf_reg_write_wait", []string{"rf_reg_write"}},
		{"rf_mem_read", []string{"rf_mem_write"}},
		{"rf_reg_read", []string{"rf_reg_write"}},
		{"plain", nil},
	}
	for _, tc := range tests {
		got := variantStripCandidates(tc.in)
		if !equalStringSet(got, tc.want) {
			t.Errorf("%s: got %#v want %#v", tc.in, got, tc.want)
		}
	}
}

func TestMotifPairCandidatesForCrypto(t *testing.T) {
	got := motifPairCandidates("crypto_hw_enable", "bounded_poll", "")
	// crypto_hw_enable should propose crypto_hw_disable and crypto_key_load.
	must := []string{"crypto_hw_disable", "crypto_key_load"}
	for _, m := range must {
		if !containsString(got, m) {
			t.Errorf("crypto_hw_enable missing helper %q in %#v", m, got)
		}
	}
	// Self must never be proposed.
	if containsString(got, "crypto_hw_enable") {
		t.Errorf("crypto_hw_enable should not propose itself: %#v", got)
	}
}

func TestMotifPairCandidatesForRfBus(t *testing.T) {
	got := motifPairCandidates("rf_bus_write2", "register_commit", "radio_reg_write")
	must := []string{"rf_bus_write", "rf_bus_reset2"}
	for _, m := range must {
		if !containsString(got, m) {
			t.Errorf("rf_bus_write2 missing helper %q in %#v", m, got)
		}
	}
}

func TestInferNameDerivedHelpersNeighborFirst(t *testing.T) {
	desc := &reconstruct.FunctionDescriptor{}
	desc.Motif.Family = "register_commit"
	desc.Behavior.Role = "radio_reg_write"
	desc.Relations.EmbedderNeighbors = []reconstruct.NeighborHint{
		{Name: "rf_reg_write_core", Image: "fmacfw_8800d80_u02.bin", Address: "0xee40", Similarity: 0.85, Reason: "same_behavior_class"},
		{Name: "rf_reg_write_cb", Image: "lmacfw_rf_8800d80_u02.bin", Address: "0xefb4", Similarity: 0.83, Reason: "same_behavior_class"},
	}
	got := inferNameDerivedHelpers("rf_reg_write_wait", desc, 4)
	if !containsString(got, "rf_reg_write_core") {
		t.Errorf("expected rf_reg_write_core (from neighbor) in %#v", got)
	}
	if !containsString(got, "rf_reg_write") {
		t.Errorf("expected rf_reg_write (from variant strip) in %#v", got)
	}
	if containsString(got, "rf_reg_write_wait") {
		t.Errorf("should not include self: %#v", got)
	}
}

func TestInferNameDerivedHelpersCrypto(t *testing.T) {
	desc := &reconstruct.FunctionDescriptor{}
	desc.Motif.Family = "bounded_poll"
	got := inferNameDerivedHelpers("crypto_hw_disable", desc, 4)
	// crypto_hw_disable should propose crypto_hw_enable (paired sibling)
	// and crypto_key_load (must run before enable).
	if !containsString(got, "crypto_hw_enable") {
		t.Errorf("crypto_hw_disable missing crypto_hw_enable: %#v", got)
	}
	if !containsString(got, "crypto_key_load") {
		t.Errorf("crypto_hw_disable missing crypto_key_load: %#v", got)
	}
}

func TestInferNameDerivedHelpersNoDesc(t *testing.T) {
	// Should still work via variant-strip and explicit pairings.
	got := inferNameDerivedHelpers("rf_bus_write2", nil, 4)
	if !containsString(got, "rf_bus_write") {
		t.Errorf("rf_bus_write2 missing rf_bus_write (variant strip): %#v", got)
	}
}

func TestMergeNameDerivedHelpersDedup(t *testing.T) {
	desc := &reconstruct.FunctionDescriptor{}
	desc.Motif.Family = "register_commit"
	desc.Relations.EmbedderNeighbors = []reconstruct.NeighborHint{
		{Name: "rf_reg_write_core", Image: "x", Address: "0x0", Similarity: 0.9, Reason: "same_behavior_class"},
	}
	existing := []string{"rf_reg_write_core", "rf_reg_write_cb"}
	merged := mergeNameDerivedHelpers(existing, "rf_reg_write_wait", desc, 4)
	// rf_reg_write_core is already in existing, must appear only once.
	count := 0
	for _, h := range merged {
		if h == "rf_reg_write_core" {
			count++
		}
	}
	if count != 1 {
		t.Errorf("expected rf_reg_write_core once, got %d in %#v", count, merged)
	}
	// Should be capped at limit.
	if len(merged) > 4 {
		t.Errorf("merged length %d > limit 4: %#v", len(merged), merged)
	}
}

func containsString(xs []string, want string) bool {
	for _, x := range xs {
		if x == want {
			return true
		}
	}
	return false
}

func equalStringSet(a, b []string) bool {
	if len(a) != len(b) {
		return false
	}
	am := map[string]int{}
	for _, x := range a {
		am[x]++
	}
	for _, x := range b {
		am[x]--
		if am[x] < 0 {
			return false
		}
	}
	return true
}
