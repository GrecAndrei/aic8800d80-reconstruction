package main

// datasgen — unified-series data segment materialization.
//
// The per-function decompiled C in src/<image>/functions/ references data
// symbols (off_*, dword_*, byte_*, word_*, qword_*) as externs that are
// never defined — so nothing links. datasgen fixes that deterministically:
//
//  1. Collect every referenced data symbol per image from the function files.
//  2. Read the real bytes from inputs/firmware/<image>.bin at
//     addr - 0x100000 (BSS/RAM addresses beyond the image emit zero-init).
//  3. Emit src/<image>/data.c with real definitions + value annotations
//     (in-image pointer, printable ASCII).
//  4. Emit src/include/aic8800d80_mmio.h (all 25,815 REG_* defines) once.
//  5. Write harness_v25/out/<image>_datasym.json (symbol -> value) so the
//     LLM naming pass can name globals later.
//
// No LLM, no r2: pure binary reads + regex over existing C.

import (
	"encoding/json"
	"flag"
	"fmt"
	"os"
	"path/filepath"
	"regexp"
	"sort"
	"strings"

	"aic8800d80/internal/fileio"
)

const dataBase = 0x100000

var dataSymRe = regexp.MustCompile(`\b(off|dword|byte|word|qword|unk|algn|flt|dbl|jpt|loc)_([0-9a-fA-F]{4,8})\b`)

// dataCallRe matches data symbols CALLED as function pointers:
//   off_1001FC()  →  the value at 0x1001FC is a code pointer.
var dataCallRe = regexp.MustCompile(`\b(off|dword|word|byte|unk|loc)_([0-9a-fA-F]{4,8})\s*\(`)

var kindSizes = map[string]int{
	"dword": 4, "off": 4, "unk": 4, "algn": 4,
	"word": 2, "byte": 1, "qword": 8,
	"flt": 4, "dbl": 8, "jpt": 4, "loc": 4,
}

type dataSym struct {
	Kind      string `json:"kind"`
	Addr      int    `json:"addr"`
	Size      int    `json:"size"`
	Value     uint64 `json:"value"`
	InImage   bool   `json:"in_image"`
	IsPtr     bool   `json:"is_ptr"`
	PtrTo     int    `json:"ptr_to,omitempty"`
	Printable bool   `json:"printable,omitempty"`
	Text      string `json:"text,omitempty"`
	Jpt       [64]uint32 `json:"-"`
}

func runDataSgen(args []string) error {
	fs := flag.NewFlagSet("datasgen", flag.ContinueOnError)
	var cf commonFlags
	cf.Register(fs)
	if err := fs.Parse(args); err != nil {
		return err
	}
	if err := cf.Resolve(); err != nil {
		return err
	}
	images, err := cf.SelectedImages()
	if err != nil {
		return err
	}
	// 0. MMIO header (once)
	if err := writeMMIOHeader(filepath.Join(cf.Root, "src", "include", "aic8800d80_mmio.h")); err != nil {
		return err
	}
	for _, img := range images {
		binName := strings.TrimSuffix(img, "_bin")
		srcDir := strings.Replace(binName, "8800d80_", "", 1)
		funcDir := filepath.Join(cf.Root, "src", srcDir, "functions")
		syms, fnPtrs, err := collectDataSymbols(funcDir)
		if err != nil {
			fmt.Fprintf(os.Stderr, "  %s: %v\n", img, err)
			continue
		}
		binPath := filepath.Join(cf.Root, "inputs", "firmware", binName+".bin")
		bin, err := os.ReadFile(binPath)
		if err != nil {
			return fmt.Errorf("read %s: %w", binPath, err)
		}
		rows, err := materialize(syms, bin)
		if err != nil {
			return err
		}
		// 3. data.c
		var b strings.Builder
		b.WriteString("/* Auto-generated data segment for " + img + " */\n")
		b.WriteString("/* Real values from inputs/firmware/" + binName + ".bin at 0x100000 */\n\n")
		b.WriteString("#include <stdint.h>\n\n")
		for _, r := range rows {
			line := annotateLine(r)
			name := fmt.Sprintf("%s_%X", r.Kind, r.Addr)
			if r.Kind == "loc" {
				line = fmt.Sprintf("int %s();", name)
			} else if fnPtrs[name] {
				line = fmt.Sprintf("int (*%s)() = (int (*)())0x%x;  /* fn-ptr */", name, r.Value)
			} else if r.Kind == "flt" {
				line = fmt.Sprintf("static union { uint32_t u; float f; } %s_o = {0x%08xu};\n#define %s (%s_o.f)", name, r.Value, name, name)
			} else if r.Kind == "dbl" {
				line = fmt.Sprintf("static union { uint64_t u; double d; } %s_o = {0x%016xULL};\n#define %s (%s_o.d)", name, r.Value, name, name)
			} else if r.Kind == "jpt" {
				line = jptLine(r, name)
			}
			b.WriteString(line)
			b.WriteString("\n")
		}
		outPath := filepath.Join(cf.Root, "src", srcDir, "data.c")
		if err := os.WriteFile(outPath, []byte(b.String()), 0644); err != nil {
			return err
		}
		// 4. datasym JSON
		outJSON := filepath.Join(cf.Out, img+"_datasym.json")
		if err := fileio.WriteJSON(outJSON, rows); err != nil {
			return err
		}
		cf.VPrintf("  %s: %d data symbols materialized -> %s", img, len(rows), outPath)
	}
	return nil
}

func collectDataSymbols(funcDir string) (map[string]int, map[string]bool, error) {
	entries, err := os.ReadDir(funcDir)
	if err != nil {
		return nil, nil, err
	}
	syms := map[string]int{} // name -> addr
	fnPtrs := map[string]bool{}
	for _, e := range entries {
		if e.IsDir() || !strings.HasSuffix(e.Name(), ".c") {
			continue
		}
		text, err := os.ReadFile(filepath.Join(funcDir, e.Name()))
		if err != nil {
			continue
		}
		for _, m := range dataSymRe.FindAllSubmatch(text, -1) {
			addrHex := string(m[2])
			addr := int(parseHex(addrHex))
			if addr < dataBase || addr >= 0x60000000 {
				continue
			}
			syms[string(m[0])] = addr
		}
		for _, m := range dataCallRe.FindAllSubmatch(text, -1) {
			fnPtrs[fmt.Sprintf("%s_%s", string(m[1]), strings.ToUpper(string(m[2])))] = true
		}
	}
	return syms, fnPtrs, nil
}

func materialize(syms map[string]int, bin []byte) ([]dataSym, error) {
	names := make([]string, 0, len(syms))
	for n := range syms {
		names = append(names, n)
	}
	sort.Strings(names)
	rows := make([]dataSym, 0, len(names))
	seen := map[int]int{} // addr -> size (largest wins for dedup of identical names)
	for _, name := range names {
		addr := syms[name]
		kind := name[:strings.IndexByte(name, '_')]
		size := kindSizes[kind]
		if size == 0 {
			continue
		}
		if prev, ok := seen[addr]; ok && prev >= size {
			continue // same addr already emitted with larger size
		}
		seen[addr] = size
		r := dataSym{Kind: kind, Addr: addr, Size: size}
		off := addr - dataBase
		var buf [8]byte
		n := 0
		if off >= 0 && off+size <= len(bin) {
			n = size
			copy(buf[:], bin[off:off+size])
		} // else: BSS/RAM, zero-init
		for i := 0; i < size; i++ {
			r.Value |= uint64(buf[i]) << (8 * i)
		}
		r.InImage = n == size && off+size <= len(bin)
		if kind == "jpt" && r.InImage {
			for i := 0; i < 64 && off+4*i+4 <= len(bin); i++ {
				r.Jpt[i] = uint32(bin[off+4*i]) | uint32(bin[off+4*i+1])<<8 | uint32(bin[off+4*i+2])<<16 | uint32(bin[off+4*i+3])<<24
			}
		}
		// Pointer classification: value inside the chip memory space
		// (0x100000 image + 0x200000 RAM/BSS upper bound)
		if size >= 4 && r.Value >= dataBase && r.Value < 0x200000 {
			r.IsPtr = true
			r.PtrTo = int(r.Value)
		}
		// Printable ASCII annotation
		if size >= 1 && isPrintable(buf[:n]) {
			var sb strings.Builder
			sb.WriteString(`"`)
			for i := 0; i < n; i++ {
				c := buf[i]
				if c >= 0x20 && c < 0x7f && c != '"' && c != '\\' {
					sb.WriteByte(c)
				} else {
					fmt.Fprintf(&sb, "\\x%02x", c)
				}
			}
			sb.WriteString(`"`)
			r.Printable = true
			r.Text = sb.String()
		}
		rows = append(rows, r)
	}
	return rows, nil
}

func annotateLine(r dataSym) string {
	name := fmt.Sprintf("%s_%X", r.Kind, r.Addr)
	decl := ""
	switch r.Kind {
	case "byte":
		decl = fmt.Sprintf("uint8_t %s = 0x%02x;", name, r.Value)
	case "word":
		decl = fmt.Sprintf("uint16_t %s = 0x%04x;", name, r.Value)
	case "qword":
		decl = fmt.Sprintf("uint64_t %s = 0x%016xULL;", name, r.Value)
	case "jpt":
		return jptLine(r, name)
	default: // dword, off, unk, algn, flt, dbl, loc
		decl = fmt.Sprintf("uint32_t %s = 0x%08x;", name, r.Value)
	}
	var notes []string
	if !r.InImage {
		notes = append(notes, "BSS/RAM (zero-init)")
	}
	if r.IsPtr {
		notes = append(notes, fmt.Sprintf("ptr -> 0x%x", r.PtrTo))
	}
	if r.Printable {
		notes = append(notes, "ascii "+r.Text)
	}
	if len(notes) > 0 {
		decl += "  /* " + strings.Join(notes, ", ") + " */"
	}
	return decl
}

// jptLine emits a jump table as an array of raw dwords from the image.
func jptLine(r dataSym, name string) string {
	var b strings.Builder
	fmt.Fprintf(&b, "uint32_t %s[] = {", name)
	for i := 0; i < 64; i++ {
		if i > 0 {
			b.WriteString(", ")
		}
		fmt.Fprintf(&b, "0x%08x", r.Jpt[i])
	}
	b.WriteString("};")
	return b.String()
}

func isPrintable(b []byte) bool {
	if len(b) == 0 {
		return false
	}
	n := 0
	for _, c := range b {
		if c >= 0x20 && c < 0x7f {
			n++
		}
	}
	return n >= 2 && n >= len(b)/2
}

func writeMMIOHeader(path string) error {
	b, err := os.ReadFile(filepath.Join(filepath.Dir(path), "..", "..", "harness_v19", "mmio_registers.json"))
	if err != nil {
		return fmt.Errorf("mmio_registers.json: %w", err)
	}
	var regs []struct {
		Addr string `json:"addr"`
		Name string `json:"name"`
	}
	if err := json.Unmarshal(b, &regs); err != nil {
		return err
	}
	var sb strings.Builder
	sb.WriteString("/* Auto-generated MMIO register definitions (25,815) from harness_v19/mmio_registers.json */\n")
	sb.WriteString("#ifndef AIC8800D80_MMIO_H\n#define AIC8800D80_MMIO_H\n\n")
	sb.WriteString("#include <stdint.h>\n\n")
	for _, r := range regs {
		addrHex := strings.TrimPrefix(r.Addr, "0x")
		sb.WriteString(fmt.Sprintf("#define %s (*((volatile uint32_t *)0x%s))\n", r.Name, addrHex))
	}
	sb.WriteString("\n#endif /* AIC8800D80_MMIO_H */\n")
	return os.WriteFile(path, []byte(sb.String()), 0644)
}

