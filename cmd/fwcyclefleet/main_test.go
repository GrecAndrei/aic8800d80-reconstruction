package main

import (
	"os"
	"path/filepath"
	"testing"
	"time"
)

func TestBuildWorkerChildArgsAddsSharedSafeDefaults(t *testing.T) {
	profiles := buildWorkerProfiles()
	var profile workerRoleProfile
	for _, p := range profiles {
		if p.Role == "auto_mmio_recovery" {
			profile = p
			break
		}
	}
	if profile.Role == "" {
		t.Fatalf("auto_mmio_recovery profile not found")
	}
	args := buildWorkerChildArgs(profile, nil)
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
	if !joined["-dead-plateau-after=4"] {
		t.Fatalf("missing dead-plateau cutoff arg: %v", args)
	}
	if !joined["-plateau-mode=auto"] {
		t.Fatalf("expected auto diversification for worker 3, got %v", args)
	}
	if !joined["-prefer-phenotype=capped_mmio_wait,capped_low_mmio"] {
		t.Fatalf("expected worker-specific focus args, got %v", args)
	}
}

func TestBuildWorkerProfilesCountAndRoles(t *testing.T) {
	profiles := buildWorkerProfiles()
	if len(profiles) < 16 {
		t.Fatalf("expected at least 16 profiles, got %d", len(profiles))
	}
	if profiles[0].Role != "register_commit_strict" {
		t.Fatalf("unexpected first role: %s", profiles[0].Role)
	}
	if profiles[len(profiles)-1].Role != "frontier_guard" {
		t.Fatalf("unexpected last role: %s", profiles[len(profiles)-1].Role)
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

func TestProvisionWorkerRootCopiesHardeningGateDirs(t *testing.T) {
	tmp := t.TempDir()
	base := filepath.Join(tmp, "base")
	worker := filepath.Join(tmp, "worker")
	for _, dir := range []string{"analysis", "applied", "final", "lift", "rebuilt", filepath.Join("runs", "run_001")} {
		if err := os.MkdirAll(filepath.Join(base, dir), 0o755); err != nil {
			t.Fatalf("mkdir %s: %v", dir, err)
		}
	}
	for rel, body := range map[string]string{
		"applied/apply_contracts.json":        `{"schema_version":"0.1.0","violations":0}`,
		"rebuilt/rebuild_manifest.json":      `{"schema_version":"0.1.0"}`,
		"final/finalize_manifest.json":       `{"file_count":1,"function_count":1}`,
		"runs/run_001/cycle_report.json":     `{"probe_summary":{"probed":1}}`,
		"controller_state.json":              `{}`,
	} {
		if err := os.WriteFile(filepath.Join(base, rel), []byte(body), 0o644); err != nil {
			t.Fatalf("write %s: %v", rel, err)
		}
	}
	if err := provisionWorkerRoot(base, worker, 1); err != nil {
		t.Fatalf("provisionWorkerRoot: %v", err)
	}
	for _, rel := range []string{"applied/apply_contracts.json", "rebuilt/rebuild_manifest.json", "final/finalize_manifest.json", "runs/run_001/cycle_report.json"} {
		if _, err := os.Stat(filepath.Join(worker, rel)); err != nil {
			t.Fatalf("missing provisioned %s: %v", rel, err)
		}
	}
}
