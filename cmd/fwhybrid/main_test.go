package main

import (
	"strings"
	"testing"
)

func TestDedupePrefersSemanticName(t *testing.T) {
	in := []indexFunc{
		{Image: "img", Address: 0x100200, Name: "sub_100200", NLines: 10},
		{Image: "img", Address: 0x100200, Name: "memset_thunk", NLines: 8},
		{Image: "img", Address: 0x100300, Name: "sub_100300", NLines: 4},
	}
	out := dedupeAndSort(in)
	if len(out) != 2 {
		t.Fatalf("len=%d want 2", len(out))
	}
	if out[0].Name != "memset_thunk" {
		t.Fatalf("first name=%q want memset_thunk", out[0].Name)
	}
}

func TestFunctionSizePrefersHint(t *testing.T) {
	raw := make([]byte, 0x1000)
	funcs := []indexFunc{
		{Address: 0x100200, Name: "a"},
		{Address: 0x100280, Name: "b"},
	}
	size, reasons := functionSize(funcs[0], 0, funcs, raw, map[uint32]int{0x100200: 12})
	if size != 12 {
		t.Fatalf("size=%d want 12", size)
	}
	if len(reasons) != 1 || reasons[0] != "size_from_v19_comment" {
		t.Fatalf("reasons=%v", reasons)
	}
}

func TestFunctionSizeFallsBackToNextFunction(t *testing.T) {
	raw := make([]byte, 0x1000)
	funcs := []indexFunc{
		{Address: 0x100200, Name: "a"},
		{Address: 0x100280, Name: "b"},
	}
	size, reasons := functionSize(funcs[0], 0, funcs, raw, nil)
	if size != 0x80 {
		t.Fatalf("size=%d want 0x80", size)
	}
	if len(reasons) != 1 || reasons[0] != "size_from_next_function" {
		t.Fatalf("reasons=%v", reasons)
	}
}

func TestRawBytesFor(t *testing.T) {
	raw := []byte{0, 1, 2, 3, 4, 5}
	rec := ledgerRecord{Address: "0x100002", Size: 3}
	got, err := rawBytesFor(rec, raw)
	if err != nil {
		t.Fatal(err)
	}
	if string(got) != string([]byte{2, 3, 4}) {
		t.Fatalf("bytes=%v", got)
	}
}

func TestSafeSymbol(t *testing.T) {
	got := safeSymbol("12 bad-name", 0x100200)
	if got != "sub_100200" {
		t.Fatalf("symbol=%q want sub_100200", got)
	}
	got = safeSymbol("mmio-set", 0x100200)
	if got != "mmio_set" {
		t.Fatalf("symbol=%q want mmio_set", got)
	}
}

func TestRealCalleesFiltersParserNoise(t *testing.T) {
	got := realCallees([]string{"self", "while ", "return ", "sub_100500", "sub_100500"}, "self")
	if len(got) != 1 || got[0] != "sub_100500" {
		t.Fatalf("real callees=%v", got)
	}
}

func TestStripCPreludeAndRename(t *testing.T) {
	src := "#include <stdint.h>\n#define X 1\nextern uint32_t off_1;\n\n// fn @ 0x100\nint old_name(int a1) {\n return a1;\n}\n"
	prelude, body := splitCPrelude(src)
	if !strings.Contains(prelude, "extern uint32_t off_1") {
		t.Fatalf("prelude=%q", prelude)
	}
	if body[:2] != "//" {
		t.Fatalf("prelude not stripped: %q", body)
	}
	renamed := renameFirstFunction(body, "new_name")
	if !strings.Contains(renamed, "int new_name(int a1)") {
		t.Fatalf("renamed body=%s", renamed)
	}
}

func TestFindDiffRangesIncludesSizeDelta(t *testing.T) {
	orig := []byte{0, 1, 2, 3}
	rebuilt := []byte{0, 9, 2, 8, 7}
	ranges := findDiffRanges(orig, rebuilt, 10)
	if len(ranges) != 3 {
		t.Fatalf("ranges=%v want 3", ranges)
	}
	if ranges[0].Start != "0x000001" || ranges[0].Length != 1 {
		t.Fatalf("first range=%+v", ranges[0])
	}
	if ranges[2].Kind != "size_delta" || ranges[2].Length != 1 {
		t.Fatalf("delta range=%+v", ranges[2])
	}
	if countDiffRanges(orig, rebuilt) != 3 {
		t.Fatalf("range count mismatch")
	}
}

func TestCompareFirmwareClassifiesPromotedDiffBytes(t *testing.T) {
	orig := make([]byte, 0x110)
	rebuilt := make([]byte, 0x110)
	copy(rebuilt, orig)
	rebuilt[0x102] = 1
	rebuilt[0x108] = 1
	recs := []ledgerRecord{
		{Address: "0x100102", Size: 4, Mode: "c_candidate"},
		{Address: "0x100108", Size: 2, Mode: "asm_exact"},
	}
	rep := compareFirmware("img", orig, rebuilt, recs, 10)
	if rep.DifferentBytes != 2 {
		t.Fatalf("diff bytes=%d", rep.DifferentBytes)
	}
	if rep.PromotedCDiffBytes != 1 {
		t.Fatalf("promoted diff bytes=%d", rep.PromotedCDiffBytes)
	}
	if rep.NonPromotedDiffBytes != 1 {
		t.Fatalf("non-promoted diff bytes=%d", rep.NonPromotedDiffBytes)
	}
	if !rep.HeaderEqual || rep.HeaderDiffBytes != 0 {
		t.Fatalf("header status equal=%v diff=%d", rep.HeaderEqual, rep.HeaderDiffBytes)
	}
}

func TestEmitSourcePreservesGapsAndCandidateRawBytes(t *testing.T) {
	raw := make([]byte, 0x110)
	for i := range raw {
		raw[i] = byte(i)
	}
	recs := []ledgerRecord{
		{Address: "0x100102", Name: "first", Size: 2, Mode: "asm_exact", VerifyStatus: "byte_exact"},
		{Address: "0x100106", Name: "candidate", Size: 2, Mode: "c_candidate", VerifyStatus: "byte_exact"},
	}
	src, err := emitSource("img", recs, raw)
	if err != nil {
		t.Fatal(err)
	}
	if !strings.Contains(src, ".Lgap_100100") {
		t.Fatalf("missing leading gap emission:\n%s", src)
	}
	if !strings.Contains(src, ".Lgap_100104") {
		t.Fatalf("missing inter-function gap emission:\n%s", src)
	}
	if !strings.Contains(src, ".Ltail_100108") {
		t.Fatalf("missing tail emission:\n%s", src)
	}
	if !strings.Contains(src, "c_candidate is tracked in the ledger; raw bytes stay packaged") {
		t.Fatalf("candidate raw-byte note missing:\n%s", src)
	}
	if strings.Contains(src, "void candidate(") {
		t.Fatalf("unverified c_candidate should not emit C body:\n%s", src)
	}
	if !strings.Contains(src, ".byte 0x06") || !strings.Contains(src, ".byte 0x07") {
		t.Fatalf("candidate raw bytes missing:\n%s", src)
	}
}

func TestFirstByteDiff(t *testing.T) {
	if got := firstByteDiff([]byte{1, 2, 3}, []byte{1, 9, 3}); got != "0x000001" {
		t.Fatalf("first diff=%q", got)
	}
	if got := firstByteDiff([]byte{1, 2}, []byte{1, 2, 3}); got != "size_delta:+1" {
		t.Fatalf("size diff=%q", got)
	}
	if got := firstByteDiff([]byte{1, 2}, []byte{1, 2}); got != "" {
		t.Fatalf("identical diff=%q", got)
	}
}

func TestRewriteAbsoluteExterns(t *testing.T) {
	src := "extern uint32_t off_1006D4;\nextern uint32_t dword_10D7AC;\nint f(void) { return *(uint32_t *)off_1006D4 + dword_10D7AC; }\n"
	got := rewriteAbsoluteExterns(src)
	if !strings.Contains(got, "#define off_1006D4 ((uint32_t)0x001006d4u)") {
		t.Fatalf("off rewrite missing:\n%s", got)
	}
	if !strings.Contains(got, "#define dword_10D7AC ((uint32_t)0x0010d7acu)") {
		t.Fatalf("dword rewrite missing:\n%s", got)
	}
	if strings.Contains(got, "extern uint32_t off_1006D4") {
		t.Fatalf("extern remained:\n%s", got)
	}
}
