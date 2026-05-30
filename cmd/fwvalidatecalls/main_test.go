package main

import "testing"

func TestHoldoutBucketDeterministic(t *testing.T) {
	b1 := holdoutBucket("ke_evt_schedule", "fw.c", 5)
	b2 := holdoutBucket("ke_evt_schedule", "fw.c", 5)
	if b1 != b2 {
		t.Fatalf("bucket should be deterministic: %d vs %d", b1, b2)
	}
	if b1 < 0 || b1 >= 5 {
		t.Fatalf("bucket out of range: %d", b1)
	}
}

func TestComputeHoldoutConformance(t *testing.T) {
	rows := []row{
		{File: "a.c", Function: "fn_a", EmittedCalls: []string{"x"}, EvidenceFound: true, ConformancePct: 100.0},
		{File: "a.c", Function: "fn_b", EmittedCalls: []string{"x"}, EvidenceFound: true, ConformancePct: 90.0},
		{File: "b.c", Function: "fn_c", EmittedCalls: []string{"x"}, EvidenceFound: true, ConformancePct: 80.0},
		{File: "b.c", Function: "fn_d", EmittedCalls: nil, EvidenceFound: true, ConformancePct: 100.0}, // not evaluable
	}
	h := computeHoldoutConformance(rows, 5)
	if h.InSample.EvaluableCount+h.OutSample.EvaluableCount != 3 {
		t.Fatalf("expected 3 evaluable rows, got %d", h.InSample.EvaluableCount+h.OutSample.EvaluableCount)
	}
	if h.InSample.AvgConformancePct <= 0 || h.OutSample.AvgConformancePct <= 0 {
		t.Fatalf("expected positive holdout averages: in=%.3f out=%.3f", h.InSample.AvgConformancePct, h.OutSample.AvgConformancePct)
	}
}

func TestLoadComposedEvidenceMissingDir(t *testing.T) {
	missing := t.TempDir() + "/does-not-exist"
	ev, err := loadComposedEvidence(missing)
	if err != nil {
		t.Fatalf("loadComposedEvidence returned error for missing dir: %v", err)
	}
	if len(ev) != 0 {
		t.Fatalf("expected empty evidence map for missing dir, got %d entries", len(ev))
	}
}
