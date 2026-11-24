package main

import (
	"strings"
	"testing"
)

func TestRelocateFnPtrData(t *testing.T) {
	units := []fnUnit{
		{Addr: 0x114de8, New: "is_patch_loaded"},
		{Addr: 0x12c9a0, New: "check_status_bit"},
	}
	data := strings.Join([]string{
		"uint32_t dword_100000 = 0x00180000;  /* sram */",
		"uint32_t off_102BF0 = 0x0014c9a1;  /* ptr -> 0x14c9a1 */",
		"uint32_t dword_102BD8 = 0x0014c9a0;  /* even addr stays constant */",
		"uint32_t off_123474 = 0x0015e291;  /* odd non-unit data stays constant */",
		"int (*off_1001FC)() = (int (*)())0x134de9;  /* fn-ptr */",
	}, "\n")

	rewritten, relocs := relocateFnPtrData(data, units)
	for _, want := range []string{
		"uint32_t dword_100000 = 0x00180000;  /* sram */",
		"extern uint32_t off_102BF0;  /* ptr -> 0x14c9a1 */",
		"uint32_t dword_102BD8 = 0x0014c9a0;  /* even addr stays constant */",
		"uint32_t off_123474 = 0x0015e291;  /* odd non-unit data stays constant */",
		"extern int (*off_1001FC)();  /* fn-ptr */",
	} {
		if !strings.Contains(rewritten, want) {
			t.Fatalf("rewritten missing %q:\n%s", want, rewritten)
		}
	}
	if len(relocs) != 2 {
		t.Fatalf("expected 2 relocs, got %d: %v", len(relocs), relocs)
	}
	if relocs[0] != "uint32_t off_102BF0 = (uint32_t)(uintptr_t)&check_status_bit;  /* ptr -> 0x14c9a1 */" {
		t.Fatalf("unexpected relocs[0]: %q", relocs[0])
	}
	if relocs[1] != "int (*off_1001FC)() = (int (*)())&is_patch_loaded;  /* fn-ptr */" {
		t.Fatalf("unexpected relocs[1]: %q", relocs[1])
	}
}

func TestSplitHexEscapes(t *testing.T) {
	cases := []struct {
		in, want string
	}{
		{`printf("\x9Bcurrent %d\n", x);`, `printf("\x9B""current %d\n", x);`},
		{`printf("\x9D\x81DBG: 0x%x\n", x);`, `printf("\x9D\x81""DBG: 0x%x\n", x);`},
		{`printf("\x9B\x87%s\n", x);`, `printf("\x9B\x87%s\n", x);`},
		{`/* ascii "\x9Bc" */ printf("\x9B""ok");`, `/* ascii "\x9Bc" */ printf("\x9B""ok");`},
	}
	for _, tc := range cases {
		if got := splitHexEscapes(tc.in); got != tc.want {
			t.Fatalf("splitHexEscapes(%q) = %q, want %q", tc.in, got, tc.want)
		}
	}
}
