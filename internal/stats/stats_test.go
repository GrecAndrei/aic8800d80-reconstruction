package stats

import (
	"os"
	"path/filepath"
	"testing"
)

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
