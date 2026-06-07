// Transpiler for Hex-Rays IDA decompiler pseudocode -> synth-pass C body.
//
// The IDA pseudocode uses non-standard C syntax (MEMORY[], _DWORD, HIDWORD,
// BYTE0/1/2/3, __fastcall, __int64, etc.) and is wrapped in
// `int __fastcall sub_XXXXXX(...)` signatures. This file converts the body
// into a valid C function body that compiles under gcc -Wall -Wextra and
// captures the actual control flow, MMIO writes, and call list of the
// decompiled function.
package main

import (
	"fmt"
	"regexp"
	"strings"
)

// transpileIDAPseudocode converts IDA decompiler pseudocode into a C function
// body (without the wrapping signature).
//
// The output is a sequence of statements indented with two spaces. The caller
// is responsible for wrapping it in `void <name>(void) { ... }` and adding
// forward declarations / splice postlude.
//
// `callRename` maps `sub_XXXXXX` names found in the body to friendly helper
// names (e.g. "rf_cmd_wait"); nil leaves them as-is. The returned helper list
// contains the friendly names actually referenced in the emitted body.
func transpileIDAPseudocode(src, friendlyName string, callRename map[string]string) (body string, helpers []string, ok bool) {
	src = strings.TrimSpace(src)
	if src == "" {
		return "", nil, false
	}
	// Rewrite lvalue-side macro assignments: `LOBYTE(x) = y;` -> `x = ((x) & ~0xFFu) | ((y) & 0xFFu);`
	// IDA's LOBYTE on the LHS means "set the low byte of x". A plain macro
	// produces a non-lvalue so the assignment is invalid in C.
	{
		lobAssignRe := regexp.MustCompile(`(?m)^([ \t]*)LOBYTE\(\s*([A-Za-z_][A-Za-z0-9_]*)\s*\)\s*=\s*(.+?);`)
		src = lobAssignRe.ReplaceAllStringFunc(src, func(m string) string {
			sm := lobAssignRe.FindStringSubmatch(m)
			indent, name, rhs := sm[1], sm[2], sm[3]
			// Use uintptr_t so this works when `name` is a pointer (e.g. v1 is
			// a `uint8_t *` and we want to set the low byte of the pointer
			// value, not deref through it).
			return fmt.Sprintf("%s%s = (typeof(%s))(((uintptr_t)(%s) & ~(uintptr_t)0xFFu) | ((uintptr_t)(%s) & 0xFFu));", indent, name, name, name, rhs)
		})
	}
	open := strings.Index(src, "{")
	close := strings.LastIndex(src, "}")
	if open < 0 || close <= open {
		return "", nil, false
	}
	inner := src[open+1 : close]

	// IDA __fastcall signatures look like:
	//   int __fastcall sub_XXXX(int a1, char a2, ...)
	// We strip the parameter list because our synth wrapper is `void fn(void)`.
	// Any param references in the body (a1, a2, ...) would otherwise be
	// undeclared. Prepend zero-init declarations so they compile cleanly.
	sigEnd := open
	sig := src[:sigEnd]
	paramDecls := extractFastcallParamDecls(sig)
	if paramDecls != "" {
		inner = paramDecls + "\n" + inner
	}

	type rw struct {
		re   *regexp.Regexp
		tmpl func(m []string) string
	}
	rws := []rw{
		{regexp.MustCompile(`\bMEMORY\[(0x[0-9A-Fa-f]+)\]\s*\(`), func(m []string) string {
			return "((int (*)(uint32_t))" + m[1] + "U)("
		}},
		{regexp.MustCompile(`\bMEMORY\[(0x[0-9A-Fa-f]+)\]`), func(m []string) string {
			return "*((volatile uint32_t *)" + m[1] + "U)"
		}},
		{regexp.MustCompile(`\*\s*\(\s*_DWORD\s*\*\s*\)\s*\(([^()]*(?:\([^()]*\))*[^()]*)\)`), func(m []string) string {
			return "*((uint32_t *)" + m[1] + ")"
		}},
		{regexp.MustCompile(`\*\s*\(\s*_QWORD\s*\*\s*\)\s*\(([^()]*(?:\([^()]*\))*[^()]*)\)`), func(m []string) string {
			return "*((uint64_t *)" + m[1] + ")"
		}},
		{regexp.MustCompile(`\*\s*\(\s*_WORD\s*\*\s*\)\s*\(([^()]*(?:\([^()]*\))*[^()]*)\)`), func(m []string) string {
			return "*((uint16_t *)" + m[1] + ")"
		}},
		{regexp.MustCompile(`\*\s*\(\s*_BYTE\s*\*\s*\)\s*\(([^()]*(?:\([^()]*\))*[^()]*)\)`), func(m []string) string {
			return "*((uint8_t *)" + m[1] + ")"
		}},
		{regexp.MustCompile(`\(\s*_DWORD\s*\*\s*\)`), func(m []string) string { return "(uint32_t *)" }},
		{regexp.MustCompile(`\(\s*_QWORD\s*\*\s*\)`), func(m []string) string { return "(uint64_t *)" }},
		{regexp.MustCompile(`\(\s*_WORD\s*\*\s*\)`), func(m []string) string { return "(uint16_t *)" }},
		{regexp.MustCompile(`\(\s*_BYTE\s*\*\s*\)`), func(m []string) string { return "(uint8_t *)" }},
		{regexp.MustCompile(`\b_DWORD\b`), func(m []string) string { return "uint32_t" }},
		{regexp.MustCompile(`\b_QWORD\b`), func(m []string) string { return "uint64_t" }},
		{regexp.MustCompile(`\b_WORD\b`), func(m []string) string { return "uint16_t" }},
		{regexp.MustCompile(`\b_BYTE\b`), func(m []string) string { return "uint8_t" }},
		{regexp.MustCompile(`\bunsigned\s+__int64\b`), func(m []string) string { return "uint64_t" }},
		{regexp.MustCompile(`\bunsigned\s+__int32\b`), func(m []string) string { return "uint32_t" }},
		{regexp.MustCompile(`\bunsigned\s+__int16\b`), func(m []string) string { return "uint16_t" }},
		{regexp.MustCompile(`\bunsigned\s+__int8\b`), func(m []string) string { return "uint8_t" }},
		{regexp.MustCompile(`\b__int64\b`), func(m []string) string { return "int64_t" }},
		{regexp.MustCompile(`\b__int32\b`), func(m []string) string { return "int32_t" }},
		{regexp.MustCompile(`\b__int16\b`), func(m []string) string { return "int16_t" }},
		{regexp.MustCompile(`\b__int8\b`), func(m []string) string { return "int8_t" }},
		{regexp.MustCompile(`\bHIDWORD\s*\(([^()]*(?:\([^()]*\)[^()]*)*)\)`), func(m []string) string {
			return "((uint32_t)((" + m[1] + ") >> 32))"
		}},
		{regexp.MustCompile(`\bLODWORD\s*\(([^()]*(?:\([^()]*\)[^()]*)*)\)`), func(m []string) string {
			return "((uint32_t)(" + m[1] + "))"
		}},
		{regexp.MustCompile(`\bBYTE0\s*\(([^()]*(?:\([^()]*\)[^()]*)*)\)`), func(m []string) string {
			return "((uint8_t)((" + m[1] + ") & 0xFFu))"
		}},
		{regexp.MustCompile(`\bBYTE1\s*\(([^()]*(?:\([^()]*\)[^()]*)*)\)`), func(m []string) string {
			return "((uint8_t)(((" + m[1] + ") >> 8) & 0xFFu))"
		}},
		{regexp.MustCompile(`\bBYTE2\s*\(([^()]*(?:\([^()]*\)[^()]*)*)\)`), func(m []string) string {
			return "((uint8_t)(((" + m[1] + ") >> 16) & 0xFFu))"
		}},
		{regexp.MustCompile(`\bBYTE3\s*\(([^()]*(?:\([^()]*\)[^()]*)*)\)`), func(m []string) string {
			return "((uint8_t)(((" + m[1] + ") >> 24) & 0xFFu))"
		}},
		{regexp.MustCompile(`\bWORD0\s*\(([^()]*(?:\([^()]*\)[^()]*)*)\)`), func(m []string) string {
			return "((uint16_t)((" + m[1] + ") & 0xFFFFu))"
		}},
		{regexp.MustCompile(`\bWORD1\s*\(([^()]*(?:\([^()]*\)[^()]*)*)\)`), func(m []string) string {
			return "((uint16_t)(((" + m[1] + ") >> 16) & 0xFFFFu))"
		}},
	}

	cur := inner
	for _, r := range rws {

		cur = r.re.ReplaceAllStringFunc(cur, func(s string) string {
			m := r.re.FindStringSubmatch(s)
			return r.tmpl(m)
		})
	}

	if len(callRename) > 0 {
		subRe := regexp.MustCompile(`\bsub_[0-9A-Fa-f]+\b`)
		cur = subRe.ReplaceAllStringFunc(cur, func(s string) string {
			if v, ok := callRename[s]; ok {
				return v
			}
			return s
		})
	}

	helperSet := map[string]struct{}{}
	calleeRe := regexp.MustCompile(`\b([a-zA-Z_][a-zA-Z0-9_]*)\s*\(`)
	allNames := calleeRe.FindAllStringSubmatch(cur, -1)
	seenFn := map[string]struct{}{friendlyName: {}}
	for _, m := range allNames {
		n := m[1]
		if _, ok := seenFn[n]; ok {
			continue
		}
		seenFn[n] = struct{}{}
		if isCKeyword(n) {
			continue
		}
		helperSet[n] = struct{}{}
	}

	var b strings.Builder
	lines := strings.Split(cur, "\n")
	for _, ln := range lines {
		trimmed := strings.TrimRight(ln, " \t\r")
		if i := strings.Index(trimmed, "//"); i >= 0 {
			rest := strings.TrimSpace(trimmed[i+2:])
			if isRegisterComment(rest) {
				trimmed = strings.TrimRight(trimmed[:i], " \t")
			}
		}
		if strings.TrimSpace(trimmed) == "" {
			b.WriteString("\n")
			continue
		}
		b.WriteString("  ")
		b.WriteString(trimmed)
		b.WriteString("\n")
	}

	returnStrip := regexp.MustCompile(`(?m)^\s*return\s+[^;]+;\s*$`)
	stripped := returnStrip.ReplaceAllStringFunc(b.String(), func(s string) string {
		return "  return;\n"
	})

	stripped = strings.TrimRight(stripped, " \n")
	// Note: we keep a trailing "return;" if present, since C requires
	// void functions to not fall off the end with a value (and
	// "return;" at the end is valid C, not unreachable).
	_ = stripped // placeholder to make the docstring above apply

	helpers = make([]string, 0, len(helperSet))
	for h := range helperSet {
		helpers = append(helpers, h)
	}
	return stripped, helpers, true
}

func isRegisterComment(s string) bool {
	if s == "" {
		return false
	}
	regs := map[string]bool{
		"r0": true, "r1": true, "r2": true, "r3": true, "r4": true, "r5": true,
		"r6": true, "r7": true, "r8": true, "r9": true, "r10": true, "r11": true,
		"r12": true, "sp": true, "lr": true, "pc": true,
	}
	if regs[s] {
		return true
	}
	for _, p := range []string{"t1", "t2", "t3"} {
		if s == p {
			return true
		}
	}
	if strings.HasPrefix(s, "kr") {
		return true
	}
	return false
}

// isCKeyword returns true when name is a C reserved word. These must never
// be treated as function calls or emitted as forward declarations.
func isCKeyword(name string) bool {
	switch name {
	case "if", "else", "while", "for", "do", "switch", "case", "default",
		"return", "break", "continue", "goto",
		"sizeof", "typedef", "struct", "union", "enum",
		"static", "extern", "auto", "register", "volatile", "const",
		"int", "char", "short", "long", "float", "double", "void", "signed", "unsigned",
		"uint8_t", "uint16_t", "uint32_t", "uint64_t",
		"int8_t", "int16_t", "int32_t", "int64_t",
		"bool", "true", "false", "NULL", "nullptr",
		"LOBYTE", "HIBYTE", "LOWORD", "HIWORD":
		return true
	}
	return false
}

// extractFastcallParamDecls parses the IDA __fastcall signature's parameter
// list and returns a string of zero-init declarations (one per line) that
// matches the names referenced in the body. e.g.
//
//	"int __fastcall sub_XX(int a1, _DWORD *a2)" -> "  int a1 = 0;\n  uint32_t *a2 = 0;\n"
//
// Returns "" when no fastcall params are detected.
func extractFastcallParamDecls(sig string) string {
	fastcallRe := regexp.MustCompile(`__fastcall\s+[a-zA-Z_][a-zA-Z0-9_]*\s*\(([^)]*)\)`)
	m := fastcallRe.FindStringSubmatch(sig)
	if len(m) != 2 {
		return ""
	}
	paramList := strings.TrimSpace(m[1])
	if paramList == "" || paramList == "void" {
		return ""
	}
	parts := strings.Split(paramList, ",")
	var lines []string
	for _, p := range parts {
		p = strings.TrimSpace(p)
		if p == "" {
			continue
		}
		// IDA param: `<type>[*]+ <name>` or `<type> <name>`.
		// We capture the full type string (with pointer stars) and the name.
		// e.g. `_DWORD *a2` -> type=`uint32_t *`, name=`a2`.
		// We replace IDA type names (int, _DWORD, char, ...) with stdint.h
		// types so the declaration is portable.
		toks := strings.Fields(p)
		if len(toks) < 2 {
			continue
		}
		name := toks[len(toks)-1]
		name = strings.TrimLeft(name, "*&")
		if name == "" {
			continue
		}
		// Build the type string from the tokens before the name.
		typeStr := strings.TrimSpace(strings.Join(toks[:len(toks)-1], " "))
		// Count trailing stars attached to the name (e.g. `int **a1` could be
		// tokenized as ["int", "**a1"]; we already split on whitespace so this
		// case is rare. Handle it by scanning the original p for trailing *.)
		// Simple heuristic: if the name token still has leading *, append them
		// to typeStr.
		trailing := strings.TrimRight(p[:len(p)-len(toks[len(toks)-1])], " \t")
		extraStars := strings.Count(toks[len(toks)-1], "*")
		if extraStars > 0 {
			typeStr = strings.TrimSpace(typeStr + " " + strings.Repeat("*", extraStars))
		}
		_ = trailing
		// Map IDA-specific types to stdint.h types.
		typeStr = mapIDAType(typeStr)
		lines = append(lines, "  "+typeStr+" "+name+" = 0;")
	}
	return strings.Join(lines, "\n") + "\n"
}

// mapIDAType converts an IDA C type token to a stdint.h equivalent.
// Handles `_DWORD`, `_QWORD`, `_WORD`, `_BYTE`, `__int8/16/32/64`,
// `unsigned __int8/16/32/64`, and bare `int`/`char`/`void`.
func mapIDAType(t string) string {
	t = strings.TrimSpace(t)
	// Pointer types keep their stars.
	// Split base and stars.
	stars := strings.TrimLeft(t, "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_ ")
	base := t[:len(t)-len(stars)]
	stars = strings.TrimRight(stars, " ") // in case
	// Re-derive: find where base type ends.
	i := len(t) - 1
	for i >= 0 && (t[i] == '*' || t[i] == ' ') {
		i--
	}
	base = t[:i+1]
	stars = t[i+1:]
	// Normalize base.
	base = strings.TrimSpace(base)
	switch base {
	case "_DWORD":
		base = "uint32_t"
	case "_QWORD":
		base = "uint64_t"
	case "_WORD":
		base = "uint16_t"
	case "_BYTE":
		base = "uint8_t"
	case "__int8":
		base = "int8_t"
	case "__int16":
		base = "int16_t"
	case "__int32":
		base = "int32_t"
	case "__int64":
		base = "int64_t"
	case "int":
		base = "int"
	case "char":
		base = "char"
	case "void":
		base = "void"
	}
	return base + stars
}
