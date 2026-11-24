package main

import (
	"os"
	"path/filepath"
	"strings"
	"testing"
)

func TestEmitStringSymbols(t *testing.T) {
	dir := t.TempDir()
	funcDir := filepath.Join(dir, "functions")
	if err := os.MkdirAll(funcDir, 0755); err != nil {
		t.Fatal(err)
	}
	if err := os.WriteFile(filepath.Join(funcDir, "100100_fn.c"), []byte("void f() { g(&aAdjPwr[4], aNewlineZero, a02x); }"), 0644); err != nil {
		t.Fatal(err)
	}
	// Missing file is a graceful no-op
	got, err := emitStringSymbols(funcDir, filepath.Join(dir, "missing.json"), []byte{})
	if err != nil || got != "" {
		t.Fatalf("missing json gave (%q, %v)", got, err)
	}
	strJSON := filepath.Join(dir, "strsyms.json")
	if err := os.WriteFile(strJSON, []byte(`{"aAdjPwr": "0x100004", "aNewlineZero": "0x10000c", "a02x": "0x100004", "aUnused": "0x100004"}`), 0644); err != nil {
		t.Fatal(err)
	}
	bin := append([]byte{0, 0, 0, 0}, []byte("adj_pwr\x00\n\x010hi\x00")...)
	got, err = emitStringSymbols(funcDir, strJSON, bin)
	if err != nil {
		t.Fatal(err)
	}
	if !strings.Contains(got, `const char aAdjPwr[] = "adj_pwr";`) || !strings.Contains(got, `const char a02x[] = "adj_pwr";`) {
		t.Fatalf("missing aAdjPwr/a02x in %q", got)
	}
	// Octal escape \001 ensures trailing '0' is not swallowed like \x010 would be.
	if !strings.Contains(got, `const char aNewlineZero[] = "\n\0010hi";`) {
		t.Fatalf("bad escaping for aNewlineZero in %q", got)
	}
	if strings.Contains(got, "aUnused") {
		t.Fatalf("unreferenced string emitted in %q", got)
	}
}

func TestCollectDataSymbolsDedup(t *testing.T) {
	dir := t.TempDir()
	funcDir := filepath.Join(dir, "functions")
	if err := os.MkdirAll(funcDir, 0755); err != nil {
		t.Fatal(err)
	}
	// Non-_sub_ duplicate sorted before _sub_: plain _sub_ must win so stale dword_ symbols do not shadow off_.
	if err := os.WriteFile(filepath.Join(funcDir, "103478_phy_rf_init.c"), []byte("int f() { return dword_103934; }"), 0644); err != nil {
		t.Fatal(err)
	}
	if err := os.WriteFile(filepath.Join(funcDir, "103478_sub_103478.c"), []byte("int f() { return *(int *)off_103934; }"), 0644); err != nil {
		t.Fatal(err)
	}
	if err := os.WriteFile(filepath.Join(funcDir, "104000_unique_fn.c"), []byte("int g() { return dword_104100; }"), 0644); err != nil {
		t.Fatal(err)
	}
	syms, _, err := collectDataSymbols(funcDir)
	if err != nil {
		t.Fatal(err)
	}
	if _, ok := syms["dword_103934"]; ok {
		t.Fatalf("stale duplicate symbol dword_103934 leaked into %v", syms)
	}
	if syms["off_103934"] != 0x103934 || syms["dword_104100"] != 0x104100 {
		t.Fatalf("expected off_103934 and dword_104100, got %v", syms)
	}
}
