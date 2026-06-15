package llm

import "testing"

func TestParseIntHex(t *testing.T) {
	tests := []struct {
		in   string
		want int
	}{
		{"0x18", 24},
		{"0xFF", 255},
		{"0", 0},
		{"42", 42},
		{"-4", -4},
		{"", 0},
		{"junk", 0},
	}
	for _, tc := range tests {
		got := ParseIntHex(tc.in)
		if got != tc.want {
			t.Errorf("ParseIntHex(%q) = %d, want %d", tc.in, got, tc.want)
		}
	}
}
