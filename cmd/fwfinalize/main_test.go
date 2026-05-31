package main

import (
	"testing"

	"aic8800d80/internal/reconstruct"
)

func TestPreferExistingFinalize(t *testing.T) {
	tests := []struct {
		name     string
		existing finalizeManifest
		candidate finalizeManifest
		want     bool
	}{
		{
			name:      "prefer existing when strong count regresses",
			existing:  finalizeManifest{FunctionCount: 100, StrongCount: 70, SemanticCompletionPct: 70.0, ImplementedCount: 80, FallbackCount: 20},
			candidate: finalizeManifest{FunctionCount: 100, StrongCount: 65, SemanticCompletionPct: 65.0, ImplementedCount: 82, FallbackCount: 18},
			want:      true,
		},
		{
			name:      "accept candidate when strong count improves",
			existing:  finalizeManifest{FunctionCount: 100, StrongCount: 65, SemanticCompletionPct: 65.0, ImplementedCount: 75, FallbackCount: 25},
			candidate: finalizeManifest{FunctionCount: 100, StrongCount: 70, SemanticCompletionPct: 70.0, ImplementedCount: 80, FallbackCount: 20},
			want:      false,
		},
		{
			name:      "prefer existing on semantic tie-break",
			existing:  finalizeManifest{FunctionCount: 100, StrongCount: 70, SemanticCompletionPct: 70.0, ImplementedCount: 80, FallbackCount: 20},
			candidate: finalizeManifest{FunctionCount: 100, StrongCount: 70, SemanticCompletionPct: 69.9, ImplementedCount: 83, FallbackCount: 17},
			want:      true,
		},
		{
			name:      "do not compare across different function counts",
			existing:  finalizeManifest{FunctionCount: 100, StrongCount: 70, SemanticCompletionPct: 70.0, ImplementedCount: 80, FallbackCount: 20},
			candidate: finalizeManifest{FunctionCount: 120, StrongCount: 70, SemanticCompletionPct: 58.3, ImplementedCount: 80, FallbackCount: 40},
			want:      false,
		},
	}

	for _, tc := range tests {
		t.Run(tc.name, func(t *testing.T) {
			got := preferExistingFinalize(tc.existing, tc.candidate)
			if got != tc.want {
				t.Fatalf("preferExistingFinalize() = %v, want %v", got, tc.want)
			}
		})
	}
}

func TestClassifyQualityAllowsMotifLeafWithoutCalls(t *testing.T) {
	desc := &reconstruct.FunctionDescriptor{}
	desc.Motif.Family = "bounded_poll"
	body := `void rf_hw_timer_init(void) {
  volatile uint32_t *mmio = (volatile uint32_t *)(uintptr_t)0x40000000U;
  uint32_t wait = 64U;
  while (wait-- > 0U) {
    uint32_t status = mmio[0];
    if ((status & 1U) != 0U) {
      break;
    }
  }
}`
	q := classifyQuality("x.c", "rf_hw_timer_init", body, nil, nil, desc, nil)
	if q.Risk == "high" {
		t.Fatalf("expected motif leaf bounded wait to avoid high risk, got %q reasons=%v", q.Risk, q.Reasons)
	}
}
