package main

import (
	"os/exec"
	"path/filepath"
	"strings"
	"testing"
)

// TestFwstructSmoke runs the fwstruct binary against a small subset of the
// v19 decompiled C and verifies expected output files exist.
func TestFwstructSmoke(t *testing.T) {
	if testing.Short() {
		t.Skip("skipping integration test in short mode")
	}
	// Find repo root by walking up from the test binary
	repo, err := filepath.Abs(".")
	if err != nil {
		t.Fatal(err)
	}
	for !fileExists(filepath.Join(repo, "go.mod")) {
		parent := filepath.Dir(repo)
		if parent == repo {
			t.Fatal("could not find go.mod")
		}
		repo = parent
	}
	// Build fwstruct
	bin := filepath.Join(t.TempDir(), "fwstruct")
	cmd := exec.Command("go", "build", "-o", bin, "./cmd/fwstruct")
	cmd.Dir = repo
	if out, err := cmd.CombinedOutput(); err != nil {
		t.Fatalf("build failed: %v\n%s", err, out)
	}
	outDir := filepath.Join(repo, "harness_v25", "out_test")
	defer exec.Command("rm", "-rf", outDir).Run()
	// Run scan on one image
	run := func(args ...string) {
		t.Helper()
		c := exec.Command(bin, args...)
		c.Dir = repo
		c.Env = append([]string{}, "PATH=/usr/bin:/bin")
		if out, err := c.CombinedOutput(); err != nil {
			t.Fatalf("%v failed: %v\n%s", args, err, out)
		}
	}
	run("scan", "--out", outDir, "--images", "fmacfw_8800d80_h_u02_bin")
	run("structs", "--out", outDir, "--images", "fmacfw_8800d80_h_u02_bin")
	run("callgraph", "--out", outDir, "--images", "fmacfw_8800d80_h_u02_bin")
	run("magic", "--out", outDir, "--images", "fmacfw_8800d80_h_u02_bin")
	// Verify expected files exist
	expected := []string{
		"fmacfw_8800d80_h_u02_bin_funcs.jsonl",
		"fmacfw_8800d80_h_u02_bin_clusters.json",
		"fmacfw_8800d80_h_u02_bin_callgraph.json",
		"fmacfw_8800d80_h_u02_bin_magic.json",
		"structs_summary.json",
	}
	for _, e := range expected {
		p := filepath.Join(outDir, e)
		if !fileExists(p) {
			t.Errorf("expected file not created: %s", p)
		}
	}
	// Verify funcs.jsonl has expected content
	funcs := readFile(t, filepath.Join(outDir, "fmacfw_8800d80_h_u02_bin_funcs.jsonl"))
	if !strings.Contains(funcs, `"name":"start"`) {
		t.Error("funcs.jsonl should contain start function")
	}
}

func fileExists(p string) bool {
	_, err := exec.Command("test", "-f", p).Output()
	return err == nil
}

func readFile(t *testing.T, p string) string {
	t.Helper()
	out, err := exec.Command("cat", p).Output()
	if err != nil {
		t.Fatal(err)
	}
	return string(out)
}
