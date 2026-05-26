package pipeline

import (
	"os"
	"testing"
)

func TestBuildMiningQueueIncludesUnknownLowConfidence(t *testing.T) {
	funcs := []FunctionRecord{
		{Image: "img.bin", Address: "0x1200", Name: "sub_1200", Role: "unknown", Confidence: 0.4},
	}
	queue := buildMiningQueue(funcs, nil, nil, nil, LearningBundle{}, 0, 0.1)
	if len(queue) != 1 {
		t.Fatalf("expected queue entry, got %d", len(queue))
	}
	if queue[0].PriorityScore <= 0 {
		t.Fatalf("expected positive score, got %f", queue[0].PriorityScore)
	}
}

func TestLoadMiningWeightsFromEnv(t *testing.T) {
	const key = "FW_MINING_SCORE_UNKNOWN_ROLE"
	old := os.Getenv(key)
	t.Cleanup(func() { _ = os.Setenv(key, old) })
	_ = os.Setenv(key, "4.25")
	w := loadMiningWeightsFromEnv()
	if w.UnknownRole != 4.25 {
		t.Fatalf("expected env override, got %f", w.UnknownRole)
	}
}

func TestBuildFamilyConsensus(t *testing.T) {
	funcs := []FunctionRecord{
		{Image: "a.bin", Address: "0x1000", Name: "rx_handle", Role: "transport", Confidence: 0.9},
		{Image: "b.bin", Address: "0x2000", Name: "rx_handle", Role: "transport", Confidence: 0.9},
	}
	links := []FunctionLinkRecord{
		{SourceImage: "a.bin", SourceAddress: "0x1000", SourceName: "rx_handle", TargetImage: "b.bin", TargetAddress: "0x2000", Confidence: 0.91},
	}
	edges := []CallEdgeRecord{
		{Image: "a.bin", SourceName: "rx_handle", TargetName: "ke_evt_schedule", Confidence: 0.9},
		{Image: "b.bin", SourceName: "rx_handle", TargetName: "ke_evt_schedule", Confidence: 0.88},
	}
	schemas := []MessageSchemaRecord{
		{Image: "a.bin", HandlerName: "rx_handle", Family: "rx", Kind: "ind", Confidence: 0.8},
	}
	rows := buildFamilyConsensus(funcs, links, edges, schemas)
	if len(rows) == 0 {
		t.Fatalf("expected consensus rows")
	}
	if rows[0].CanonicalFunction != "rx_handle" {
		t.Fatalf("unexpected canonical function: %s", rows[0].CanonicalFunction)
	}
	if rows[0].ImageCount < 2 {
		t.Fatalf("expected >=2 images in consensus, got %d", rows[0].ImageCount)
	}
}
