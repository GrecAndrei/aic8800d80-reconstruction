package types

import "testing"

func TestFixFileArrayIndex(t *testing.T) {
	in := `int __fastcall sub_100200(int a1)
{
  a1[1] = 0x1234;
  a1[10] = 0x5678;
  return 0;
}
`
	out, fixes := FixFile(in)
	if len(fixes) != 2 {
		t.Errorf("got %d fixes, want 2", len(fixes))
	}
	if !contains(out, "0x4") {
		t.Error("expected 0x4 in output")
	}
	if !contains(out, "0x28") {
		t.Error("expected 0x28 in output")
	}
}

func contains(s, sub string) bool {
	return len(s) >= len(sub) && indexOf(s, sub) >= 0
}

func indexOf(s, sub string) int {
	for i := 0; i+len(sub) <= len(s); i++ {
		if s[i:i+len(sub)] == sub {
			return i
		}
	}
	return -1
}
