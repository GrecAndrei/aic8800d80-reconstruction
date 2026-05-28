package main

import (
	"os"
	"path/filepath"
	"testing"
	"time"
)

func TestBuildWorkerChildArgsAddsSharedSafeDefaults(t *testing.T) {
	args := buildWorkerChildArgs(3, nil)
	joined := map[string]bool{}
	for _, arg := range args {
		joined[arg] = true
	}
	if !joined["-update-checkpoints=false"] {
		t.Fatalf("missing checkpoint disable arg: %v", args)
	}
	if !joined["-refresh-ida-before-cycle=false"] {
		t.Fatalf("missing refresh-ida-before-cycle disable arg: %v", args)
	}
	if !joined["-refresh-ida-on-zero-probes=false"] {
		t.Fatalf("missing refresh-ida-on-zero-probes disable arg: %v", args)
	}
	if !joined["-plateau-mode=deepen"] {
		t.Fatalf("expected deepen diversification for worker 3, got %v", args)
	}
}

func TestCopyRecentRunsKeepsNewestOnly(t *testing.T) {
	tmp := t.TempDir()
	srcRuns := filepath.Join(tmp, "src", "runs")
	dstRuns := filepath.Join(tmp, "dst", "runs")
	if err := os.MkdirAll(srcRuns, 0o755); err != nil {
		t.Fatalf("mkdir src runs: %v", err)
	}
	for i, name := range []string{"run_a", "run_b", "run_c"} {
		p := filepath.Join(srcRuns, name)
		if err := os.MkdirAll(p, 0o755); err != nil {
			t.Fatalf("mkdir %s: %v", name, err)
		}
		if err := os.WriteFile(filepath.Join(p, "marker.txt"), []byte(name), 0o644); err != nil {
			t.Fatalf("write marker %s: %v", name, err)
		}
		mod := time.Now().Add(time.Duration(i) * time.Minute)
		if err := os.Chtimes(p, mod, mod); err != nil {
			t.Fatalf("chtimes %s: %v", name, err)
		}
	}
	if err := copyRecentRuns(srcRuns, dstRuns, 2); err != nil {
		t.Fatalf("copyRecentRuns: %v", err)
	}
	if _, err := os.Stat(filepath.Join(dstRuns, "run_c", "marker.txt")); err != nil {
		t.Fatalf("expected newest run_c: %v", err)
	}
	if _, err := os.Stat(filepath.Join(dstRuns, "run_b", "marker.txt")); err != nil {
		t.Fatalf("expected second newest run_b: %v", err)
	}
	if _, err := os.Stat(filepath.Join(dstRuns, "run_a")); !os.IsNotExist(err) {
		t.Fatalf("expected oldest run_a to be omitted, err=%v", err)
	}
}
