package pipeline

import "testing"

func TestMergeFunctionRecordsPrefersHigherConfidence(t *testing.T) {
	base := []FunctionRecord{{Image: "img.bin", Address: "0x1000", Name: "sub_1000", Confidence: 0.55, Tags: []string{"unknown"}}}
	overlay := []FunctionRecord{{Image: "img.bin", Address: "0x1000", Name: "boot_init", Confidence: 0.9, Tags: []string{"kernel"}}}
	out := mergeFunctionRecords(base, overlay)
	if len(out) != 1 {
		t.Fatalf("expected 1 record, got %d", len(out))
	}
	if out[0].Name != "boot_init" {
		t.Fatalf("expected overlay name, got %q", out[0].Name)
	}
	if len(out[0].Aliases) == 0 || out[0].Aliases[0] != "sub_1000" {
		t.Fatalf("expected base alias to be preserved, got %+v", out[0].Aliases)
	}
}

func TestInferMessageRouteSemantic(t *testing.T) {
	action, _, side := inferMessageRouteSemantic("if type <= 0xC calls sub_1234 parse", "0x1234")
	if action != "parse_message" {
		t.Fatalf("expected parse_message action, got %q", action)
	}
	if side == "" {
		t.Fatal("expected side effect text")
	}
}
