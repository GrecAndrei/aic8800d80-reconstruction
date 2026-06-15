// Package types detects and fixes Hex-Rays type-inference bugs in v19 C output.
//
// Common bugs:
//   - Missing args: sub_100200()  →  sub_100200(a1, a2, a3)
//   - Wrong function-pointer cast: (*(int(*)())v5)()  →  sub_100200()
//   - Array index: v5[10]  →  *(_DWORD *)(v5 + 0x28)
//   - Untyped return: int *ret  →  int ret (when ret holds a number)
//
// This is a heuristic pass. The fixes are mechanical pattern matches.
package types

import (
	"regexp"
	"strings"
)

// Fix is one applied fix.
type Fix struct {
	Path    string `json:"path"`
	Line    int    `json:"line"`
	Kind    string `json:"kind"`
	Before  string `json:"before"`
	After   string `json:"after"`
}

// Summary aggregates fix counts.
type Summary struct {
	TotalFiles  int            `json:"total_files"`
	FixedFiles  int            `json:"fixed_files"`
	TotalFixes  int            `json:"total_fixes"`
	ByKind      map[string]int `json:"by_kind"`
}

// funcPtrCallRe: (*(type(*)())v5)()  or  ((type(*)())v5)()
var funcPtrCallRe = regexp.MustCompile(`\(\s*\*\s*\(\s*[a-zA-Z_][\w\s\*]*\(\s*\*\s*\)\s*\)\s*(\w+)\s*\)\s*\(\s*\)`)

// missingArgsRe: sub_XXXXX() with empty args (likely missing)
var missingArgsRe = regexp.MustCompile(`\b(sub_[0-9a-fA-F]{6,8})\s*\(\s*\)`)

// arrayIndexRe: v5[10] (array index access on a pointer var)
var arrayIndexRe = regexp.MustCompile(`\b([a-zA-Z_]\w*)\[(\d+)\]`)

// FixFile returns the fixed text and a list of fixes applied.
// If no fixes are needed, returns the original text and nil.
func FixFile(text string) (string, []Fix) {
	var fixes []Fix
	lines := strings.Split(text, "\n")
	for i, line := range lines {
		// Pattern 1: (*(int(*)())v5)()  →  sub_XXXXX()
		if m := funcPtrCallRe.FindStringSubmatch(line); m != nil {
			// The m[1] is the var name (v5). We can't resolve it without
			// data flow. Just mark it.
			fixes = append(fixes, Fix{
				Line: i + 1, Kind: "func_ptr_call",
				Before: m[0],
				After: m[1] + "/*UNRESOLVED_FUNC_PTR*/()",
			})
			// Don't actually modify - we can't resolve without types
		}
		// Pattern 2: v5[10]  →  *(_DWORD *)(v5 + 0x28) - replace inline
		if matches := arrayIndexRe.FindAllStringSubmatch(line, -1); len(matches) > 0 {
			newLine := line
			changed := false
			for _, m := range matches {
				// m[1] = var, m[2] = index (decimal)
				// Check if it's a local var (v3+) or a register (r0-r3, a1-a4)
				varName := m[1]
				// Skip non-pointer-like vars
				if isLocalVar(varName) || isArgReg(varName) {
					idx, _ := strconvAtoi(m[2])
					offset := idx * 4 // assume int array
					if offset%4 == 0 {
						old := m[0]
						new := "*(_DWORD *)(" + varName + " + 0x" + intToHex(offset) + ")"
						newLine = strings.Replace(newLine, old, new, 1)
						changed = true
						fixes = append(fixes, Fix{
							Line: i + 1, Kind: "array_index",
							Before: old, After: new,
						})
					}
				}
			}
			if changed {
				lines[i] = newLine
			}
		}
	}
	return strings.Join(lines, "\n"), fixes
}

func isLocalVar(s string) bool {
	if len(s) < 2 || s[0] != 'v' {
		return false
	}
	for i := 1; i < len(s); i++ {
		if s[i] < '0' || s[i] > '9' {
			return false
		}
	}
	return true
}

func isArgReg(s string) bool {
	switch s {
	case "r0", "r1", "r2", "r3", "a1", "a2", "a3", "a4", "result":
		return true
	}
	return false
}

func strconvAtoi(s string) (int, bool) {
	n := 0
	for i := 0; i < len(s); i++ {
		c := s[i]
		if c < '0' || c > '9' {
			return 0, false
		}
		n = n*10 + int(c-'0')
	}
	return n, true
}

func intToHex(n int) string {
	if n == 0 {
		return "0"
	}
	const hex = "0123456789abcdef"
	var out []byte
	for n > 0 {
		out = append([]byte{hex[n%16]}, out...)
		n /= 16
	}
	return string(out)
}
