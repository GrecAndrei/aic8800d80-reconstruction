package pipeline

import (
	"os"
	"path/filepath"
	"strings"
	"testing"
)

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

func TestCheckFirmwareInputs(t *testing.T) {
	root := t.TempDir()
	err := checkFirmwareInputs(root, "fw_a.bin")
	if err == nil || !strings.Contains(err.Error(), "fw_a.bin, "+patchTableFile) {
		t.Fatalf("expected both files reported missing, got %v", err)
	}
	fwDir := filepath.Join(root, "inputs", "firmware")
	if err := os.MkdirAll(fwDir, 0o755); err != nil {
		t.Fatal(err)
	}
	if err := os.WriteFile(filepath.Join(root, "fw_a.bin"), []byte{0}, 0o644); err != nil {
		t.Fatal(err)
	}
	if err := os.WriteFile(filepath.Join(fwDir, patchTableFile), []byte{0}, 0o644); err != nil {
		t.Fatal(err)
	}
	if err := checkFirmwareInputs(root, "fw_a.bin"); err != nil {
		t.Fatalf("expected inputs found, got %v", err)
	}
}
