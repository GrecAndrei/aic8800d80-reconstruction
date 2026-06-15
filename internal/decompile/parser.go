// Package decompile parses v19 Hex-Rays decompiled C output.
//
// The parser extracts from each .c file:
//   - Function name, address
//   - Callee names (function calls)
//   - Access patterns (loads/stores through pointers)
//   - Literals (numeric constants, with context)
//
// The parser is regex-based, not full C parser. This is sufficient for
// Hex-Rays output which is line-oriented pseudo-C.
package decompile

import (
	"bufio"
	"fmt"
	"io/fs"
	"os"
	"path/filepath"
	"regexp"
	"sort"
	"strconv"
	"strings"
)

// Func represents one parsed function.
type Func struct {
	Image    string   `json:"image"`
	Address  uint32   `json:"address"`
	Name     string   `json:"name"`
	NLines   int      `json:"n_lines"`
	NGotos   int      `json:"n_gotos"`
	NReturns int      `json:"n_returns"`
	Callees  []string `json:"callees"`
	Accesses []Access `json:"accesses"`
	Literals []string `json:"literals"`
}

// Access is a load or store through a pointer.
type Access struct {
	Base      string `json:"base"`  // "r0", "r4", "v5", etc
	Offset    int    `json:"offset"` // #8 -> 8
	Size      int    `json:"size"`   // 1, 2, 4
	Direction string `json:"direction"` // "load" | "store"
	LHS       string `json:"lhs,omitempty"`
	Expr      string `json:"expr"`
}

// CalleeRe matches function calls. We accept both named functions and sub_XXXXX.
var calleeRe = regexp.MustCompile(`\b(sub_[0-9a-fA-F]{6,8}|[a-z_][a-zA-Z0-9_]{3,40})\s*\(`)

// hexLitRe matches hex literals like 0x123ABC
var hexLitRe = regexp.MustCompile(`\b0x([0-9a-fA-F]+)\b`)

// intLitRe matches integer literals like 123, 0x123, 0x1A
var intLitRe = regexp.MustCompile(`\b(\d+)[uUlL]*\b`)

// loadRe matches loads: result = *(int *)(v5 + 0x8)  or  v3 = *(_DWORD *)v4
var loadRe = regexp.MustCompile(`\*\s*\(\s*(?:_DWORD|_WORD|_BYTE|int|short|char|unsigned\s+\w+)\s*\*?\s*\)\s*(?:\(\s*([^)]+?)\s*\))?`)

// storeRe matches stores: *(_DWORD *)(v5 + 0x8) = 1  or  *v4 = result
var storeRe = regexp.MustCompile(`\*\s*\(\s*(?:_DWORD|_WORD|_BYTE|int|short|char|unsigned\s+\w+)\s*\*?\s*\)\s*(?:\(\s*([^)]+?)\s*\))?\s*=`)

// baseOffsetRe extracts the (base, offset) from a pointer expression like v5 + 0x8
var baseOffsetRe = regexp.MustCompile(`([a-zA-Z_][a-zA-Z0-9_]*)\s*\+\s*(0x[0-9a-fA-F]+|\d+)`)

// funcDefRe matches function definition lines: <ret-type> <name>(<args>) {
var funcDefRe = regexp.MustCompile(`^[a-zA-Z_*\s]+?\b([a-zA-Z_][a-zA-Z0-9_]*)\s*\([^)]*\)\s*$`)

// ParseFile parses a single .c file into a Func.
func ParseFile(image, path string) (*Func, error) {
	f, err := os.Open(path)
	if err != nil {
		return nil, err
	}
	defer f.Close()

	base := filepath.Base(path)
	// File name format: <addr_hex>_<name>.c
	m := regexp.MustCompile(`^([0-9a-fA-F]+)_(.+?)\.c$`).FindStringSubmatch(base)
	if m == nil {
		return nil, fmt.Errorf("unexpected filename: %s", base)
	}
	addr, err := strconv.ParseUint(m[1], 16, 32)
	if err != nil {
		return nil, fmt.Errorf("parse addr %q: %w", m[1], err)
	}
	name := m[2]

	fn := &Func{
		Image:    image,
		Address:  uint32(addr),
		Name:     name,
		Callees:  []string{},
		Accesses: []Access{},
		Literals: []string{},
	}

	seenCallees := map[string]struct{}{}
	seenLits := map[string]struct{}{}

	sc := bufio.NewScanner(f)
	sc.Buffer(make([]byte, 64*1024), 4*1024*1024)
	for sc.Scan() {
		line := sc.Text()
		// Strip comments
		code := stripComments(line)

		fn.NLines++
		if strings.Contains(code, " goto ") {
			fn.NGotos++
		}
		if strings.HasPrefix(strings.TrimSpace(code), "return ") || strings.Contains(code, " return ") {
			fn.NReturns++
		}

		// Find function name from first def line (skip declarations)
		if fn.Name == name && name == "" {
			if m := funcDefRe.FindStringSubmatch(code); m != nil {
				fn.Name = m[1]
			}
		}

		// Callees
		for _, mc := range calleeRe.FindAllString(code, -1) {
			cn := strings.TrimSuffix(mc, "(")
			if cn == "if" || cn == "for" || cn == "while" || cn == "switch" || cn == "return" || cn == "sizeof" {
				continue
			}
			if _, ok := seenCallees[cn]; !ok {
				seenCallees[cn] = struct{}{}
				fn.Callees = append(fn.Callees, cn)
			}
		}

		// Loads: a load appears on a line that does NOT contain " = " after the deref
		// Stores: a store appears when the deref is on the LHS of " = "
		// Hex-Rays output: "result = *(_DWORD *)v3" (load) vs "*(_DWORD *)v3 = 0x1234" (store)
		// We can disambiguate by checking if there's an " = " after the matched expr.
		seenAccesses := map[string]bool{}
		for _, ml := range loadRe.FindAllString(code, -1) {
			idx := strings.Index(code, ml)
			rest := code[idx+len(ml):]
			if strings.HasPrefix(strings.TrimSpace(rest), "=") {
				continue // it's a store
			}
			a := parseAccess(ml, "load")
			if a != nil {
				fn.Accesses = append(fn.Accesses, *a)
			}
		}

		// Stores
		for _, ms := range storeRe.FindAllString(code, -1) {
			if seenAccesses[ms] { continue }
			seenAccesses[ms] = true
			a := parseAccess(ms, "store")
			if a != nil {
				fn.Accesses = append(fn.Accesses, *a)
			}
		}

		// Literals
		for _, mh := range hexLitRe.FindAllString(code, -1) {
			if _, ok := seenLits[mh]; !ok {
				seenLits[mh] = struct{}{}
				fn.Literals = append(fn.Literals, mh)
			}
		}
		for _, mi := range intLitRe.FindAllString(code, -1) {
			if _, ok := seenLits[mi]; !ok {
				seenLits[mi] = struct{}{}
				fn.Literals = append(fn.Literals, mi)
			}
		}
	}
	if err := sc.Err(); err != nil {
		return nil, err
	}
	sort.Strings(fn.Callees)
	sort.Strings(fn.Literals)
	return fn, nil
}

func stripComments(line string) string {
	// Strip // and /* */
	if i := strings.Index(line, "//"); i >= 0 {
		line = line[:i]
	}
	if i := strings.Index(line, "/*"); i >= 0 {
		if j := strings.Index(line[i:], "*/"); j >= 0 {
			line = line[:i] + line[i+j+2:]
		}
	}
	return line
}

func parseAccess(expr, dir string) *Access {
	a := &Access{Direction: dir, Expr: expr}
	// Type -> size
	switch {
	case strings.Contains(expr, "_BYTE") || strings.Contains(expr, "char"):
		a.Size = 1
	case strings.Contains(expr, "_WORD") || strings.Contains(expr, "short"):
		a.Size = 2
	default:
		a.Size = 4
	}
	// Extract (base, offset)
	if m := baseOffsetRe.FindStringSubmatch(expr); m != nil {
		a.Base = m[1]
		if off, err := strconv.ParseInt(m[2], 0, 32); err == nil {
			a.Offset = int(off)
		}
	} else {
		// Pure base like *v4
		// Pattern: *(_DWORD *)v4
		if m := regexp.MustCompile(`\*\s*\(\s*(?:_DWORD|_WORD|_BYTE|int|short|char)\s*\*\s*\)\s*(\w+)`).FindStringSubmatch(expr); m != nil {
			a.Base = m[1]
			a.Offset = 0
		} else {
			return nil
		}
	}
	return a
}

// ParseDir parses all .c files under <decompiled>/<image>/ and returns funcs.
func ParseDir(decompiled, image string) ([]*Func, error) {
	imgDir := filepath.Join(decompiled, image)
	entries, err := os.ReadDir(imgDir)
	if err != nil {
		return nil, err
	}
	var out []*Func
	for _, e := range entries {
		if e.IsDir() || !strings.HasSuffix(e.Name(), ".c") {
			continue
		}
		fn, err := ParseFile(image, filepath.Join(imgDir, e.Name()))
		if err != nil {
			continue // skip malformed
		}
		out = append(out, fn)
	}
	sort.Slice(out, func(i, j int) bool { return out[i].Address < out[j].Address })
	return out, nil
}

// ParseAllDirs parses every subdirectory under <decompiled> as an image.
func ParseAllDirs(decompiled string) (map[string][]*Func, error) {
	entries, err := os.ReadDir(decompiled)
	if err != nil {
		return nil, err
	}
	out := map[string][]*Func{}
	for _, e := range entries {
		if !e.IsDir() {
			continue
		}
		funcs, err := ParseDir(decompiled, e.Name())
		if err != nil {
			continue
		}
		out[e.Name()] = funcs
	}
	return out, nil
}

// ImageDir is a helper for fs walking.
type ImageDir struct {
	Image string
	FS    fs.FS
}

// CollectImages finds all image directories under <decompiled>.
func CollectImages(decompiled string) []string {
	entries, err := os.ReadDir(decompiled)
	if err != nil {
		return nil
	}
	var out []string
	for _, e := range entries {
		if e.IsDir() {
			out = append(out, e.Name())
		}
	}
	sort.Strings(out)
	return out
}
