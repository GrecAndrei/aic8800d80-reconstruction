// Package ivt parses and rewrites ARM Interrupt Vector Tables for v18 WFFW images.
//
// WFFW format (from build_wffw.py):
//   - File offset 0x00-0xFF: IVT + boot header
//   - File offset 0x100+:    code
//   - Chip runtime: file offset + 0x100000
//   - Thumb bit (bit 0 of address) is set for code pointers
//
// The original IVT points to original code (file offset N).
// After v18 replacement (code shifted by 0x100), the IVT must be updated
// to point to file offset N + 0x100 (with Thumb bit preserved).
package ivt

import (
	"encoding/binary"
	"fmt"
)

// Vector names (ARM Cortex-M standard order).
var VectorNames = []string{
	"stack_ptr",      // offset 0x00
	"reset",          // offset 0x04
	"nmi",            // offset 0x08
	"hardfault",      // offset 0x0C
	"memmanage",      // offset 0x10
	"busfault",       // offset 0x14
	"usagefault",     // offset 0x18
	"reserved_1",     // offset 0x1C
	"reserved_2",     // offset 0x20
	"reserved_3",     // offset 0x24
	"reserved_4",     // offset 0x28
	"svcall",         // offset 0x2C
	"debug_mon",      // offset 0x30
	"reserved_5",     // offset 0x34
	"pendsv",         // offset 0x38
	"systick",        // offset 0x3C
	// IRQ vectors follow
}

// Vector is one IVT entry.
type Vector struct {
	Index    int    `json:"index"`
	Name     string `json:"name"`
	Address  uint32 `json:"address"`    // raw value (with Thumb bit)
	CodeAddr uint32 `json:"code_addr"`  // address with Thumb bit cleared
	HasThumb bool   `json:"has_thumb"`
	Source   string `json:"source"`     // "ivt" or "patch" or "header"
}

// ParseIVT reads the IVT from a WFFW binary.
//
// The first 0x100 bytes are expected to contain the IVT.
// The function reads the first 16 standard Cortex-M vectors (0x00-0x3C).
// If a "WFFW" magic is found at offset 0x20-0x24, parses the rest as boot header.
func ParseIVT(data []byte) ([]Vector, error) {
	if len(data) < 0x40 {
		return nil, fmt.Errorf("data too short: %d", len(data))
	}
	var vecs []Vector
	for i := 0; i < 16; i++ {
		off := i * 4
		raw := binary.LittleEndian.Uint32(data[off : off+4])
		thumb := raw&1 != 0
		vec := Vector{
			Index:    i,
			Name:     vectorName(i),
			Address:  raw,
			CodeAddr: raw &^ 1,
			HasThumb: thumb,
			Source:   "ivt",
		}
		vecs = append(vecs, vec)
	}
	return vecs, nil
}

func vectorName(i int) string {
	if i < len(VectorNames) {
		return VectorNames[i]
	}
	return fmt.Sprintf("irq_%d", i-16)
}

// CodeSegment is the chip address range where code lives.
// Anything below 0x100000 or above 0x180000 is not code and won't be shifted.
const CodeSegmentLo = 0x100000
const CodeSegmentHi = 0x180000

// RewriteForV18 produces a patched IVT that points to v18 code.
//
// The v18 code is shifted by IVT_HEADER_SIZE (0x100) compared to original code.
// So for each IVT entry that points to original code, we add IVT_HEADER_SIZE.
//
// This is a simple, mechanical rewrite. It assumes:
//   - v18 code preserves the function layout (no relocations, same size)
//   - Original code is in the 0x100000-0x180000 range
//   - v18 code is in the 0x100100-0x180100 range (shifted by 0x100)
//   - Stack pointer (typically in 0x1a0000+) is NOT modified
func RewriteForV18(vecs []Vector, headerSize uint32) []Vector {
	out := make([]Vector, len(vecs))
	for i, v := range vecs {
		nv := v
		if v.CodeAddr != 0 && v.CodeAddr >= CodeSegmentLo && v.CodeAddr < CodeSegmentHi {
			nv.CodeAddr = v.CodeAddr + headerSize
			nv.Address = nv.CodeAddr
			if v.HasThumb {
				nv.Address |= 1
			}
			nv.Source = "patch_v18"
		}
		out[i] = nv
	}
	return out
}

// ApplyPatch writes the patched IVT back into the binary data.
// Returns the modified data.
func ApplyPatch(data []byte, vecs []Vector) ([]byte, error) {
	if len(data) < len(vecs)*4 {
		return nil, fmt.Errorf("data too short for %d vectors", len(vecs))
	}
	out := make([]byte, len(data))
	copy(out, data)
	for _, v := range vecs {
		if v.Index*4+4 > len(out) {
			continue
		}
		binary.LittleEndian.PutUint32(out[v.Index*4:v.Index*4+4], v.Address)
	}
	return out, nil
}

// Const for the IVT header size.
const HeaderSize = 0x100
