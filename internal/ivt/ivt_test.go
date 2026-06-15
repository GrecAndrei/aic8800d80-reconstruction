package ivt

import (
	"encoding/binary"
	"testing"
)

func TestParseIVT(t *testing.T) {
	// 16 vectors, each 4 bytes
	data := make([]byte, 0x40)
	// stack pointer: 0x001a0000
	binary.LittleEndian.PutUint32(data[0:], 0x001a0000)
	// reset: 0x001201a9 (with Thumb bit)
	binary.LittleEndian.PutUint32(data[4:], 0x001201a9)
	vecs, err := ParseIVT(data)
	if err != nil {
		t.Fatal(err)
	}
	if len(vecs) != 16 {
		t.Errorf("got %d vecs, want 16", len(vecs))
	}
	if vecs[0].Name != "stack_ptr" {
		t.Errorf("vec[0].Name = %q want stack_ptr", vecs[0].Name)
	}
	if vecs[0].Address != 0x001a0000 {
		t.Errorf("vec[0].Address = %x want 0x001a0000", vecs[0].Address)
	}
	if vecs[1].Name != "reset" {
		t.Errorf("vec[1].Name = %q want reset", vecs[1].Name)
	}
	if vecs[1].Address != 0x001201a9 {
		t.Errorf("vec[1].Address = %x want 0x001201a9", vecs[1].Address)
	}
	if !vecs[1].HasThumb {
		t.Error("vec[1].HasThumb should be true")
	}
	if vecs[1].CodeAddr != 0x001201a8 {
		t.Errorf("vec[1].CodeAddr = %x want 0x001201a8", vecs[1].CodeAddr)
	}
}

func TestRewriteForV18(t *testing.T) {
	data := make([]byte, 0x40)
	binary.LittleEndian.PutUint32(data[0:], 0x001a0000) // stack
	binary.LittleEndian.PutUint32(data[4:], 0x001201a9) // reset
	vecs, _ := ParseIVT(data)
	patched := RewriteForV18(vecs, HeaderSize)
	// Stack should be UNCHANGED (in RAM, not code)
	if patched[0].Address != 0x001a0000 {
		t.Errorf("stack should not be patched, got %x", patched[0].Address)
	}
	// Reset should be shifted by 0x100
	if patched[1].Address != 0x001202a9 {
		t.Errorf("reset should be 0x1202a9, got %x", patched[1].Address)
	}
	if !patched[1].HasThumb {
		t.Error("reset should still have Thumb")
	}
}
