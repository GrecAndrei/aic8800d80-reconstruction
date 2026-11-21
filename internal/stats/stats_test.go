package stats

import (
	"os"
	"path/filepath"
	"testing"
	"time"
)

func TestFreshnessUsesExtractionInputs(t *testing.T) {
	dir := t.TempDir()
	persist := func() *int64 {
		t.Helper()
		s, err := CollectAndPersist(dir)
		if err != nil {
			t.Fatal(err)
		}
		return s.Progress.DataFreshnessSec
	}
	persist()
	if persist() != nil {
		t.Fatal("dashboard history alone must not give the data an age")
	}
	now := time.Now()
	for file, age := range map[string]time.Duration{"images.jsonl": time.Hour, "functions.jsonl": time.Minute} {
		path := filepath.Join(dir, file)
		if err := os.WriteFile(path, []byte("{}\n"), 0o644); err != nil {
			t.Fatal(err)
		}
		if err := os.Chtimes(path, now.Add(-age), now.Add(-age)); err != nil {
			t.Fatal(err)
		}
	}
	for i := 0; i < 2; i++ {
		age := persist()
		if age == nil {
			t.Fatal("no age reported for extraction inputs")
		}
		if *age < 60 || *age > 61+int64(time.Since(now)/time.Second) {
			t.Fatalf("age = %ds, want age of the newer extraction input", *age)
		}
	}
}

func TestReconReportAvailability(t *testing.T) {
	dir := t.TempDir()
	recon := filepath.Join(dir, "reconstruction", "run1", "rebuilt")
	if err := os.MkdirAll(recon, 0o755); err != nil {
		t.Fatal(err)
	}
	check := func(available bool, count int) {
		t.Helper()
		s, err := Collect(dir)
		if err != nil {
			t.Fatal(err)
		}
		if s.Progress.ReconReports["rebuild"] != available || s.Progress.ReconstructedFuncs != count || s.Progress.ReconReports["finalize"] {
			t.Fatalf("reports = %v, functions = %d; want rebuild available=%t, functions=%d, no finalize report", s.Progress.ReconReports, s.Progress.ReconstructedFuncs, available, count)
		}
	}
	check(false, 0)
	for _, tc := range []struct {
		json string
		ok   bool
		n    int
	}{{"invalid", false, 0}, {"null", false, 0}, {`{"total_functions":0}`, true, 0}, {`{"total_functions":42}`, true, 42}} {
		if err := os.WriteFile(filepath.Join(recon, "rebuild_manifest.json"), []byte(tc.json), 0o644); err != nil {
			t.Fatal(err)
		}
		check(tc.ok, tc.n)
	}
}

func TestCollectPanels(t *testing.T) {
	dir := t.TempDir()
	write := func(name, body string) {
		if err := os.WriteFile(filepath.Join(dir, name), []byte(body), 0o644); err != nil {
			t.Fatal(err)
		}
	}
	write("functions.jsonl", `{"name":"a","confidence":0.1}
{"name":"b","confidence":0.95}
{"name":"c","confidence":1.0}
`)
	write("function_links.jsonl", `{"source_image":"img","source_address":"0x1","source_name":"a","confidence":0.5}
{"source_image":"img","source_address":"0x1","source_name":"a","confidence":0.9}
{"source_image":"img","source_address":"0x2","confidence":0.3}
`)
	write("call_edges.jsonl", `{"image":"img","source_addr":"0x1","source_name":"a","target_addr":"0x2","target_name":"b","confidence":0.8}
{"image":"img","source_addr":"0x1","source_name":"a","target_addr":"0x3","confidence":0.6}
{"image":"img","source_addr":"0x4","target_addr":"0x2","target_name":"b","confidence":0.4}
`)
	write("mining_queue.jsonl", `{"name":"queued_fn"}
`)

	snap, err := Collect(dir)
	if err != nil {
		t.Fatal(err)
	}

	wantPairs(t, "top.linked_functions", snap.Top.LinkedFunctions, []CountPair{{"a", 2}, {"img|0x2", 1}})
	wantPairs(t, "top.top_call_sources", snap.Top.TopCallSources, []CountPair{{"a", 2}, {"img|0x4", 1}})
	wantPairs(t, "calls.target_name_counts", snap.Calls.TargetNameCounts, []CountPair{{"b", 2}, {"img|0x3", 1}})
	wantPairs(t, "functions.confidence_buckets", snap.Functions.ConfidenceBuckets,
		[]CountPair{{"0.0-0.2", 1}, {"0.2-0.4", 0}, {"0.4-0.6", 0}, {"0.6-0.8", 0}, {"0.8-1.0", 2}})
	wantPairs(t, "links.confidence_buckets", snap.Links.ConfidenceBuckets,
		[]CountPair{{"0.0-0.2", 0}, {"0.2-0.4", 1}, {"0.4-0.6", 1}, {"0.6-0.8", 0}, {"0.8-1.0", 1}})
	if snap.Calls.AverageConfidence != 0.6 {
		t.Errorf("calls.average_confidence = %v, want 0.6", snap.Calls.AverageConfidence)
	}
}

func wantPairs(t *testing.T, name string, got, want []CountPair) {
	t.Helper()
	if len(got) != len(want) {
		t.Fatalf("%s = %v, want %v", name, got, want)
	}
	for i := range want {
		if got[i] != want[i] {
			t.Fatalf("%s = %v, want %v", name, got, want)
		}
	}
}
