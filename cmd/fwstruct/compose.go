package main

// compose — unified-series main.c composer.
//
// Builds src/<image>/main.c from the REAL per-function bodies in
// src/<image>/functions/ (no empty stubs):
//
//  1. Extract each file's function signature (canonical "// name @ 0xADDR"
//     marker + the text up to the opening brace).
//  2. Apply LLM names from harness_v17/names/{fn}__{img}.json to
//     sub_* functions — both the definition and every call site.
//  3. Emit: mmio/types headers + data.c definitions (datasgen) +
//     forward declarations with real signatures + unknown-callee decls +
//     all bodies in address order.
//
// Deterministic, no LLM.

import (
	"encoding/json"
	"flag"
	"fmt"
	"os"
	"path/filepath"
	"regexp"
	"sort"
	"strings"
)

type fnUnit struct {
	Addr    int
	Orig    string // original function name
	New     string // final name (LLM or original)
	Sig     string // full signature line(s) ending with "{"
	Body    string // everything from "{" to EOF
	HasBody bool
}

var fnMarkerRe = regexp.MustCompile(`(?m)^// (\w+) @ 0x([0-9a-fA-F]+)[^\n]*`)
var sigTailRe = regexp.MustCompile(`(?s)^((?:[A-Za-z_][\w ]*?|\*|\(|\s)+?)\s+(\w+)\s*\((.*)\)\s*\{?\s*$`)

func runCompose(args []string) error {
	fs := flag.NewFlagSet("compose", flag.ContinueOnError)
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
	nameMap := loadNameMap(filepath.Join(cf.Root, "harness_v17", "names"))

	for _, img := range images {
		binName := strings.TrimSuffix(img, "_bin")
		srcDir := strings.Replace(binName, "8800d80_", "", 1)
		funcDir := filepath.Join(cf.Root, "src", srcDir, "functions")
		units, err := readFunctionUnits(funcDir)
		if err != nil {
			fmt.Fprintf(os.Stderr, "  %s: %v\n", img, err)
			continue
		}
		// Apply LLM names + dedup collisions
		imgNames := nameMap[img]
		used := map[string]int{}
		for i := range units {
			u := &units[i]
			n := u.Orig
			if strings.HasPrefix(n, "sub_") && imgNames != nil {
				if nn, ok := imgNames[n]; ok && validCName(nn) {
					n = nn
				}
			}
			if forbiddenCName[n] {
				n += "_fn"
			}
			base := n
			for k := 1; used[n] > 0; k++ {
				n = fmt.Sprintf("%s_%x", base, k)
			}
			used[n]++
			u.New = n
			// Rewrite the function name inside the signature text too
			if n != u.Orig {
				if idx := strings.LastIndex(u.Sig, u.Orig+"("); idx >= 0 {
					u.Sig = u.Sig[:idx] + n + u.Sig[idx+len(u.Orig):]
				}
			}
		}
		// Global rename map: orig -> new (first winner)
		rename := map[string]string{}
		for _, u := range units {
			if u.New != u.Orig {
				if _, ok := rename[u.Orig]; !ok {
					rename[u.Orig] = u.New
				}
			}
		}
		// Precompiled rename regex (built once — O(n), not O(n*m))
		var renameRe *regexp.Regexp
		if len(rename) > 0 {
			names := make([]string, 0, len(rename))
			for n := range rename {
				names = append(names, n)
			}
			sort.Slice(names, func(i, j int) bool { return len(names[i]) > len(names[j]) })
			renameRe = regexp.MustCompile(`\b(` + strings.Join(names, "|") + `)\b`)
		}
		// Rewrite bodies: apply renames + collect callees
		defined := map[string]bool{}
		for _, u := range units {
			defined[u.New] = true
		}
		callees := map[string]bool{}
		for i := range units {
			u := &units[i]
			if renameRe != nil {
				u.Body = renameRe.ReplaceAllStringFunc(u.Body, func(m string) string {
					if nn, ok := rename[m]; ok {
						return nn
					}
					return m
				})
			}
			// Normalize Hex-Rays "unsigned uint64_t" leftovers in bodies
			u.Body = unsignedUintRe.ReplaceAllString(u.Body, "uint${1}_t")
			for _, m := range callRe.FindAllStringSubmatch(u.Body, -1) {
				n := m[1]
				if forbiddenCName[n] || cKeywords[n] || strings.HasPrefix(n, "REG_") {
					continue // header macro / intrinsic / keyword, not a function
				}
				if n == "va_start" || n == "va_end" || n == "va_arg" || n == "va_copy" {
					continue // stdarg macros, not functions
				}
				if isDataSymName(n) {
					continue // data symbol (possibly a fn-ptr in data.c), not a C function
				}
				if !defined[n] {
					callees[n] = true
				}
			}
		}
		var main strings.Builder
		main.WriteString("/* Auto-generated composed reconstruction — unified series */\n")
		main.WriteString("/* image: " + img + " — real bodies from src/" + srcDir + "/functions/ */\n\n")
		main.WriteString("#include <stdint.h>\n")
		main.WriteString("#include <stdarg.h>\n")
		main.WriteString("#include \"aic8800d80_types.h\"\n")
		main.WriteString("#include \"aic8800d80_mmio.h\"\n")
		main.WriteString("#include \"aic8800d80_structs.h\"\n\n")
		// data definitions (from datasgen)
		dataPath := filepath.Join(cf.Root, "src", srcDir, "data.c")
		if db, err := os.ReadFile(dataPath); err == nil {
			main.WriteString("/* --- data segment --- */\n")
			main.WriteString(string(db))
			main.WriteString("\n")
		}
		// forward decls for defined functions
		main.WriteString("/* --- forward declarations --- */\n")
		for _, u := range units {
			main.WriteString(fnDecl(u) + ";\n")
		}
		// unknown callees
		calleeList := make([]string, 0, len(callees))
		for c := range callees {
			calleeList = append(calleeList, c)
		}
		sort.Strings(calleeList)
		if len(calleeList) > 0 {
			main.WriteString("/* --- callees not defined in this image --- */\n")
			for _, c := range calleeList {
				// int() return + unspecified params: call sites with Hex-Rays
				// arg-count artifacts still compile; result is usable.
				main.WriteString("int " + c + "();\n")
			}
		}
		// bodies
		main.WriteString("\n/* --- function bodies --- */\n")
		for _, u := range units {
			main.WriteString("// " + u.New + " @ 0x" + fmt.Sprintf("%x", u.Addr) + "\n")
			main.WriteString(u.Sig + " " + u.Body + "\n\n")
		}
		outPath := filepath.Join(cf.Root, "src", srcDir, "main.c")
		if err := os.WriteFile(outPath, []byte(main.String()), 0644); err != nil {
			return err
		}
		cf.VPrintf("  %s: %d real bodies composed -> %s", img, len(units), outPath)
	}
	return nil
}

// forbiddenCName lists identifiers that collide with macros/functions
// defined in src/include/aic8800d80_types.h.
var forbiddenCName = map[string]bool{
	"LOBYTE": true, "HIBYTE": true, "LOWORD": true, "HIWORD": true,
	"LODWORD": true, "HIDWORD": true, "__PAIR64__": true, "__CFSHL__": true,
	"__clz": true, "__get_CPSR": true, "__disable_irq": true,
	"__enable_irq": true, "__pld": true, "__rev16": true, "__rev": true,
	"__usat": true, "__mcr": true, "__mrc": true, "__cdp": true,
	"__und": true, "__dsb": true, "__isb": true, "__wfi": true,
	"nullptr": true, "BOOL": true, "REG": true, "start": false,
	"__OFADD__": true, "__OFSUB__": true,
}

// cKeywords can never be function names or callees.
var cKeywords = map[string]bool{
	"if": true, "for": true, "while": true, "switch": true, "do": true,
	"return": true, "sizeof": true, "else": true, "goto": true,
	"case": true, "default": true, "break": true, "continue": true,
	"float": true, "double": true, "char": true, "int": true, "void": true,
	"static": true, "extern": true, "typedef": true, "struct": true,
	"union": true, "enum": true, "const": true, "volatile": true,
	"unsigned": true, "signed": true, "long": true, "short": true,
	"uint8_t": true, "uint16_t": true, "uint32_t": true, "uint64_t": true,
	"int8_t": true, "int16_t": true, "int32_t": true, "int64_t": true,
}

var unsignedUintRe = regexp.MustCompile(`unsigned uint(8|16|32|64)_t`)

// callRe matches calls to identifiers (post-rename tokens).
var callRe = regexp.MustCompile(`\b([A-Za-z_][A-Za-z0-9_]*)\s*\(`)

// dataSymNameRe matches Hex-Rays data symbol names (off_*, dword_*, ...).
var dataSymNameRe = regexp.MustCompile(`^(off|dword|word|byte|unk|qword|algn)_[0-9A-Fa-f]{4,8}$`)

func isDataSymName(n string) bool {
	return dataSymNameRe.MatchString(n)
}

func fnDecl(u fnUnit) string {
	sig := u.Sig
	if i := strings.LastIndex(sig, "("); i >= 0 {
		return sig[:i] + "(" + strings.TrimSpace(sig[i+1:len(sig)-1]) + ")"
	}
	return "void " + u.New + "()"
}

func validCName(n string) bool {
	if n == "" {
		return false
	}
	for i, c := range n {
		ok := c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (i > 0 && c >= '0' && c <= '9')
		if !ok {
			return false
		}
	}
	return true
}


func readFunctionUnits(funcDir string) ([]fnUnit, error) {
	entries, err := os.ReadDir(funcDir)
	if err != nil {
		return nil, err
	}
	units := make([]fnUnit, 0, len(entries))
	for _, e := range entries {
		if e.IsDir() || !strings.HasSuffix(e.Name(), ".c") {
			continue
		}
		text, err := os.ReadFile(filepath.Join(funcDir, e.Name()))
		if err != nil {
			continue
		}
		u := fnUnit{}
		var addrHex string
		if m := fnMarkerRe.FindSubmatch(text); m != nil {
			u.Orig = string(m[1])
			addrHex = string(m[2])
		}
		u.Addr = int(parseHex(addrHex))
		// signature = text between marker line and first '{' after it
		markerIdx := fnMarkerRe.FindIndex(text)
		braceIdx := -1
		if markerIdx != nil {
			braceIdx = indexByteFrom(text, '{', markerIdx[1])
		}
		if braceIdx < 0 {
			continue
		}
		sigRaw := string(text[markerIdx[1]:braceIdx])
		sigRaw = stripCommentLines(sigRaw)
		sig := strings.Join(strings.Fields(sigRaw), " ")
		sig = strings.ReplaceAll(sig, "__noreturn", "")
		sig = unsignedUintRe.ReplaceAllString(sig, "uint${1}_t")
		sig = strings.Join(strings.Fields(sig), " ")
		u.Sig = strings.TrimRight(sig, " {")
		u.Body = string(text[braceIdx:])
		u.HasBody = true
		units = append(units, u)
	}
	sort.Slice(units, func(i, j int) bool { return units[i].Addr < units[j].Addr })
	return units, nil
}

func indexByteFrom(b []byte, c byte, from int) int {
	for i := from; i < len(b); i++ {
		if b[i] == c {
			return i
		}
	}
	return -1
}

func stripCommentLines(s string) string {
	lines := strings.Split(s, "\n")
	out := make([]string, 0, len(lines))
	for _, l := range lines {
		l = strings.TrimSpace(l)
		if l == "" || strings.HasPrefix(l, "//") {
			continue
		}
		out = append(out, l)
	}
	return strings.Join(out, " ")
}

func loadNameMap(namesDir string) map[string]map[string]string {
	out := map[string]map[string]string{}
	entries, err := os.ReadDir(namesDir)
	if err != nil {
		return out
	}
	for _, e := range entries {
		if e.IsDir() || !strings.HasSuffix(e.Name(), ".json") {
			continue
		}
		b, err := os.ReadFile(filepath.Join(namesDir, e.Name()))
		if err != nil {
			continue
		}
		var rec struct {
			Fn     string `json:"fn"`
			Img    string `json:"img"`
			Status string `json:"status"`
			Name   string `json:"name"`
		}
		if err := json.Unmarshal(b, &rec); err != nil || rec.Status != "ok" || rec.Name == "" {
			continue
		}
		if out[rec.Img] == nil {
			out[rec.Img] = map[string]string{}
		}
		out[rec.Img][rec.Fn] = rec.Name
	}
	return out
}
