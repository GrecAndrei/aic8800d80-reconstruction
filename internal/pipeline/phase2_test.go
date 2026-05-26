package pipeline

import (
	"bytes"
	"encoding/binary"
	"testing"
)

func TestFindMaskedMatches(t *testing.T) {
	needle := []byte{0x00, 0xF0, 0xAA, 0xBB}
	hay := []byte{0x10, 0x20, 0x00, 0xF4, 0xAA, 0xBB, 0x99}
	mask := []byte{0xFF, 0xF8, 0xFF, 0xFF}
	matches := findMaskedMatches(hay, needle, mask, 2)
	if len(matches) != 1 || matches[0] != 2 {
		t.Fatalf("unexpected masked matches: %+v", matches)
	}
}

func TestParsePatchSections(t *testing.T) {
	buf := bytes.NewBuffer(nil)
	tag := make([]byte, 16)
	copy(tag, []byte("AICBT_TEST"))
	buf.Write(tag)
	_ = binary.Write(buf, binary.LittleEndian, uint32(0x10))
	_ = binary.Write(buf, binary.LittleEndian, uint32(1))
	_ = binary.Write(buf, binary.LittleEndian, uint32(0x40000000))
	_ = binary.Write(buf, binary.LittleEndian, uint32(0x1))
	secs := parsePatchSections(buf.Bytes())
	if len(secs) != 1 {
		t.Fatalf("expected one section, got %d", len(secs))
	}
	if secs[0].Tag != "AICBT_TEST" || secs[0].Count != 1 {
		t.Fatalf("unexpected section: %+v", secs[0])
	}
}
