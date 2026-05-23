package main

import (
	"os"
	"path/filepath"
	"strings"
	"testing"
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
	if err := writeSynth(p, task, nil, nil); err != nil {
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
