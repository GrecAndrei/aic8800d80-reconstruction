package main

import (
	"os"
	"path/filepath"
	"reflect"
	"strings"
	"testing"
	"time"
)

func TestBuildFWCycleArgs(t *testing.T) {
	args := buildFWCycleArgs(
		"extraction_out/reconstruction/mega7",
		"cycle_auto_foo",
		12,
		320,
		"/tmp/model.gguf",
		[]string{"-gate-harden=true", "-retry-capped-once=false"},
	)
	wantPrefix := []string{
		"run", "./cmd/fwcycle",
		"-run-root", "extraction_out/reconstruction/mega7",
		"-tag", "cycle_auto_foo",
		"-limit", "12",
		"-throttle-probes-on-plateau=false",
		"-auto-impl-max-tasks", "320",
		"-embedder-model", "/tmp/model.gguf",
	}
	if !reflect.DeepEqual(args[:len(wantPrefix)], wantPrefix) {
		t.Fatalf("unexpected arg prefix:\n got %#v\nwant %#v", args[:len(wantPrefix)], wantPrefix)
	}
	if !reflect.DeepEqual(args[len(wantPrefix):], []string{"-gate-harden=true", "-retry-capped-once=false"}) {
		t.Fatalf("unexpected passthrough args: %#v", args[len(wantPrefix):])
	}
}

func TestShouldStop(t *testing.T) {
	stopFile := filepath.Join(t.TempDir(), "stop")
	if shouldStop(stopFile, time.Time{}, 0, 0) {
		t.Fatalf("unexpected stop with no conditions met")
	}
	if err := os.WriteFile(stopFile, []byte("stop"), 0o644); err != nil {
		t.Fatalf("write stop file: %v", err)
	}
	if !shouldStop(stopFile, time.Time{}, 0, 0) {
		t.Fatalf("expected stop due to stop file")
	}
	if !shouldStop("", time.Time{}, 3, 3) {
		t.Fatalf("expected stop due to cycle limit")
	}
	past := time.Now().UTC().Add(-1 * time.Minute)
	if !shouldStop("", past, 0, 0) {
		t.Fatalf("expected stop due to end time")
	}
}

func TestMakeCycleTag(t *testing.T) {
	now := time.Date(2026, 5, 27, 14, 5, 6, 0, time.UTC)
	tag := makeCycleTag("cycle_auto", 7, now)
	if got, want := tag, "cycle_auto_20260527T140506Z_007"; got != want {
		t.Fatalf("unexpected tag: got %q want %q", got, want)
	}
	defaultTag := makeCycleTag("  ", 1, now)
	if !strings.HasPrefix(defaultTag, "cycle_auto_") {
		t.Fatalf("expected default prefix in tag, got %q", defaultTag)
	}
}
