package main

import (
	"os"
	"path/filepath"
	"strings"
	"testing"
)

func TestTranspileIDAPseudocodeBasicSyntax(t *testing.T) {
	src := `int __fastcall sub_121118C()
{
  int v0; // r3
  int result; // r0

  v0 = MEMORY[0x185A1C];
  MEMORY[0x40200B14] = v0;
  result = MEMORY[0x1859FC];
  return result;
}`
	body, helpers, ok := transpileIDAPseudocode(src, "rf_bus_mark", nil)
	if !ok {
		t.Fatalf("transpile failed")
	}
	if strings.Contains(body, "MEMORY[") {
		t.Errorf("MEMORY[] should be rewritten: %s", body)
	}
	if !strings.Contains(body, "*((volatile uint32_t *)0x185A1CU)") {
		t.Errorf("expected rewritten MMIO read: %s", body)
	}
	if !strings.Contains(body, "*((volatile uint32_t *)0x40200B14U) = v0") {
		t.Errorf("expected rewritten MMIO write: %s", body)
	}
	if strings.Contains(body, "  return result;") {
		t.Errorf("`return result;` should be stripped to `return;`: %s", body)
	}
	if len(helpers) != 0 {
		t.Errorf("no helpers expected, got %v", helpers)
	}
}

func TestTranspileIDAPseudocodeStripsRegisterComments(t *testing.T) {
	src := `int sub_1()
{
  int v0; // r3
  v0 = 1;
}`
	body, _, _ := transpileIDAPseudocode(src, "fn", nil)
	if strings.Contains(body, "// r3") {
		t.Errorf("register comment should be stripped: %s", body)
	}
}

func TestTranspileIDAPseudocodeRewritesByteMacros(t *testing.T) {
	// Use a non-return context so the BYTE macros survive in the body.
	src := `int sub_1(int a1) { v0 = BYTE0(a1) | (BYTE1(a1) << 8); v0 += 1; }`
	body, _, _ := transpileIDAPseudocode(src, "fn", nil)
	if !strings.Contains(body, "((uint8_t)((a1) & 0xFFu))") {
		t.Errorf("BYTE0 not rewritten: %s", body)
	}
	if !strings.Contains(body, "((uint8_t)(((a1) >> 8) & 0xFFu))") {
		t.Errorf("BYTE1 not rewritten: %s", body)
	}
}

func TestTranspileIDAPseudocodeRenamesSubCalls(t *testing.T) {
	src := `int sub_1() { sub_121118C(); sub_OTHER(); return 0; }`
	rename := map[string]string{
		"sub_121118C": "rf_cmd_wait",
	}
	body, helpers, _ := transpileIDAPseudocode(src, "fn", rename)
	if !strings.Contains(body, "rf_cmd_wait();") {
		t.Errorf("sub_121118C should be renamed: %s", body)
	}
	if strings.Contains(body, "sub_121118C()") {
		t.Errorf("sub_121118C should be gone: %s", body)
	}
	if !strings.Contains(body, "sub_OTHER()") {
		t.Errorf("unmapped sub_OTHER should remain: %s", body)
	}
	if !contains(helpers, "rf_cmd_wait") {
		t.Errorf("rf_cmd_wait should be in helpers: %v", helpers)
	}
}

func TestTranspileIDAPseudocodeHandlesHIDWORD(t *testing.T) {
	// Use a non-return context so the HIDWORD expression survives.
	src := `int sub_1(__int64 a1) { v0 = HIDWORD(a1); v0 += 1; }`
	body, _, _ := transpileIDAPseudocode(src, "fn", nil)
	if !strings.Contains(body, "((uint32_t)((a1) >> 32))") {
		t.Errorf("HIDWORD not rewritten: body=%q", body)
	}
}

func TestTranspileIDAPseudocodeStripsTrailingReturn(t *testing.T) {
	src := `int sub_1() { return 0; }`
	body, _, _ := transpileIDAPseudocode(src, "fn", nil)
	// Body should contain a "return;" (since the original ended with a
	// value-return that we strip). The body is non-empty.
	if !strings.Contains(body, "return;") {
		t.Errorf("expected return; in body: %q", body)
	}
}

func TestTranspileIDAPseudocodePreservesDoWhile(t *testing.T) {
	src := `int sub_1(int v2, int v3) { do { v2 += 8; } while (v2 != v3); return 0; }`
	body, _, _ := transpileIDAPseudocode(src, "fn", nil)
	if !strings.Contains(body, "do") {
		t.Errorf("do-while should be preserved: %s", body)
	}
	if !strings.Contains(body, "while") {
		t.Errorf("while should be preserved: %s", body)
	}
}

func contains(ss []string, s string) bool {
	for _, x := range ss {
		if x == s {
			return true
		}
	}
	return false
}

func TestTryRealPseudocodeFileWritesTranspiledBody(t *testing.T) {
	tmpDir := t.TempDir()
	out := filepath.Join(tmpDir, "rf_state_check.c")

	pseudo := &pseudoHint{
		Image:    "lmacfw_rf_8800d80_u02.bin",
		Address:  "0x1212030",
		Name:     "rf_state_check",
		Pseudocode: `int __fastcall sub_1212030()
{
  int v0; // r0
  v0 = MEMORY[0x40200B14];
  v0 &= 0xFFFFFFFEu;
  MEMORY[0x40200B14] = v0;
  rf_bus_mark(0);
  return 0;
}`,
		CallNames: []string{"rf_bus_mark"},
	}
	task := implTask{
		TaskID:    "backfill_rf_state_check",
		Image:     pseudo.Image,
		Address:   pseudo.Address,
		Function:  "rf_state_check",
		TaskClass: "dependency_impl",
	}

	ok := tryRealPseudocodeFile(out, task, pseudo, nil, nil, "critical", "main loop driver")
	if !ok {
		t.Fatalf("tryRealPseudocodeFile returned false")
	}
	got, err := os.ReadFile(out)
	if err != nil {
		t.Fatalf("read written file: %v", err)
	}
	s := string(got)
	for _, must := range []string{
		"reconstructed_micro_flow: yes",
		"void rf_state_check(void)",
		"*((volatile uint32_t *)0x40200B14U)",
		"v0 &= 0xFFFFFFFEu;",
		"rf_bus_mark(0);",
		"return;",
	} {
		if !strings.Contains(s, must) {
			t.Errorf("expected %q in output, full output:\n%s", must, s)
		}
	}
}

func TestTryRealPseudocodeFileReturnsFalseOnEmptyPseudo(t *testing.T) {
	tmpDir := t.TempDir()
	out := filepath.Join(tmpDir, "x.c")
	pseudo := &pseudoHint{Image: "x", Address: "0x0", Name: "fn", Pseudocode: ""}
	task := implTask{Function: "fn", Image: "x", Address: "0x0", TaskID: "x", TaskClass: "y"}
	if tryRealPseudocodeFile(out, task, pseudo, nil, nil, "", "") {
		t.Fatalf("expected false for empty pseudocode")
	}
}

func TestTryRealPseudocodeFileReturnsFalseOnNilPseudo(t *testing.T) {
	tmpDir := t.TempDir()
	out := filepath.Join(tmpDir, "x.c")
	task := implTask{Function: "fn", Image: "x", Address: "0x0", TaskID: "x", TaskClass: "y"}
	if tryRealPseudocodeFile(out, task, nil, nil, nil, "", "") {
		t.Fatalf("expected false for nil pseudo")
	}
}

func TestRealPseudoEmitterFiresOnFmacfwbtRfHwTimerInit(t *testing.T) {
	// End-to-end test: pseudo entry for fmacfwbt sub_120DE48 (== rf_hw_timer_init
	// at file offset 0xde48). Create a synth task at file offset 0xde48 and verify
	// the new emitter produces a real (transpiled) body, not a template.
	tmpDir := t.TempDir()
	out := filepath.Join(tmpDir, "rf_hw_timer_init.c")

	pseudo := &pseudoHint{
		Image:    "fmacfwbt_8800d80_u02.bin",
		Address:  "0x120de48",
		Name:     "rf_hw_timer_init",
		Pseudocode: `int sub_120DE48()
{
  int result; // r0
  MEMORY[0x4010D000] = 0;
  result = 0;
  return result;
}`,
	}
	task := implTask{
		TaskID:    "backfill_rf_hw_timer_init",
		Image:     pseudo.Image,
		Address:   "0xde48", // file offset; pseudoForTask normalizes to 0x120de48
		Function:  "rf_hw_timer_init",
		TaskClass: "dependency_impl",
	}

	ok := tryRealPseudocodeFile(out, task, pseudo, nil, nil, "timer_callback", "interrupt_handler")
	if !ok {
		t.Fatalf("tryRealPseudocodeFile returned false")
	}
	got, err := os.ReadFile(out)
	if err != nil {
		t.Fatalf("read written file: %v", err)
	}
	s := string(got)
	for _, must := range []string{
		"reconstructed_micro_flow: yes",
		"reconstructed_control: yes",
		"void rf_hw_timer_init(void)",
		"*((volatile uint32_t *)0x4010D000U) = 0;",
	} {
		if !strings.Contains(s, must) {
			t.Errorf("expected %q in output, full output:\n%s", must, s)
		}
	}
}
