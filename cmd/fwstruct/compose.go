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
	"strconv"
	"strings"
)

type fnUnit struct {
	Addr       int
	Orig       string // original function name
	PreRename  string // address-derived sub_<HEX> name (unique per address)
	New        string // final name (LLM or original)
	Sig        string // full signature line(s) ending with "{"
	Body       string // everything from "{" to EOF
	HasBody    bool
	IsPlainSub bool // from a plain <hex>_sub_<HEX>.c file (pre-rename decompile)
}

var plainSubFileRe = regexp.MustCompile(`^[0-9a-fA-F]+_sub_[0-9a-fA-F]+\.c$`)

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
		// Global rename map: sub_<ADDR> -> final name (first winner). Keyed on
		// the address-derived name (unique per address), NOT the marker name:
		// the LLM naming pass can give two different functions the same name,
		// and a marker-name-keyed map would rewrite all call sites to the
		// second unit's deduped name, collapsing distinct targets.
		rename := map[string]string{}
		for _, u := range units {
			if u.New != u.PreRename {
				if _, ok := rename[u.PreRename]; !ok {
					rename[u.PreRename] = u.New
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
				if headerIntrinsic[n] {
					continue // static inline defined in aic8800d80_types.h
				}
				if n == "va_start" || n == "va_end" || n == "va_arg" || n == "va_copy" {
					continue // stdarg macros, not functions
				}
				if isDataSymName(n) {
					continue // data symbol (possibly a fn-ptr in data.c), not a C function
				}
				if strings.HasPrefix(n, "loc_") {
					continue // code-label lvalue defined in data.c
				}
				if !defined[n] {
					callees[n] = true
				}
			}
		}
		// Call-site disambiguation for duplicate LLM names. The naming pass can
		// give two distinct functions the same name; the dedup above keeps their
		// DEFINITIONS unique (base + _1) but baked-in call sites keep the base
		// name, so calls that target the second unit would bind to the first.
		// Use the ORIGINAL binary's call edges (chip-space caller -> callee) to
		// rewrite each call site to the address it actually targets. No-op when
		// the call-edge file is absent (e.g. fresh clone without extraction_out/).
		disambiguateCallSites(units, loadCallEdges(
			filepath.Join(cf.Root, "extraction_out", "ida_export_live", binName+".bin.call_edges.jsonl"),
		))
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

// headerIntrinsic lists static inline helpers defined in
// src/include/aic8800d80_types.h (never emit forward decls for them).
var headerIntrinsic = map[string]bool{
	"JUMPOUT": true, "COERCE_FLOAT": true, "COERCE_UINT32": true,
	"__CFADD__": true, "__OFADD__": true, "__OFSUB__": true,
	"bswap32": true, "abs16": true, "abs32": true,
	"vcvts_n_s32_f32": true, "vcvts_n_f32_u32": true,
	"__rev": true, "__rev16": true, "__usat": true,
	"__get_CPSR": true, "__disable_irq": true, "__enable_irq": true,
	"__pld": true, "MEMD": true,
	"SHIBYTE": true, "SLOBYTE": true, "WORD1": true, "WORD2": true,
	"SHIDWORD": true, "__ROR4__": true, "_byteswap_ushort": true,
	"BYTE1": true, "BYTE2": true, "BYTE3": true, "BYTE4": true,
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

// chipFromV14 converts an IDA-export address (v14 base 0x1200000) to chip
// space (base 0x100000). Addresses already in chip space pass through.
func chipFromV14(addr int) int {
	if addr >= 0x1200000 {
		return addr - 0x1100000
	}
	return addr
}

// loadCallEdges reads the IDA call-edge export for one image into
// chip-space caller -> set of callee addresses. Returns nil if the file is
// missing (call-site disambiguation is then a no-op).
func loadCallEdges(path string) map[int]map[int]bool {
	b, err := os.ReadFile(path)
	if err != nil {
		return nil
	}
	out := map[int]map[int]bool{}
	for _, line := range strings.Split(string(b), "\n") {
		line = strings.TrimSpace(line)
		if line == "" {
			continue
		}
		var rec struct {
			SourceAddr string `json:"source_addr"`
			TargetAddr string `json:"target_addr"`
		}
		if json.Unmarshal([]byte(line), &rec) != nil {
			continue
		}
		src, err1 := strconv.ParseInt(strings.TrimPrefix(rec.SourceAddr, "0x"), 16, 64)
		tgt, err2 := strconv.ParseInt(strings.TrimPrefix(rec.TargetAddr, "0x"), 16, 64)
		if err1 != nil || err2 != nil {
			continue
		}
		srcChip := chipFromV14(int(src))
		tgtChip := chipFromV14(int(tgt))
		if out[srcChip] == nil {
			out[srcChip] = map[int]bool{}
		}
		out[srcChip][tgtChip] = true
	}
	return out
}

// disambiguateCallSites rewrites bodies whose call sites reference a name
// that two distinct functions share. For each unit, it resolves which of the
// shared name's addresses the caller actually targets (from the binary call
// edges) and rewrites the base name to the correct deduped definition name.
func disambiguateCallSites(units []fnUnit, callEdges map[int]map[int]bool) {
	if len(callEdges) == 0 {
		return
	}
	// Group definition addresses by original (marker) name.
	origToAddr := map[string][]int{}
	addrToNew := map[int]string{}
	for _, u := range units {
		origToAddr[u.Orig] = append(origToAddr[u.Orig], u.Addr)
		addrToNew[u.Addr] = u.New
	}
	for i := range units {
		u := &units[i]
		for n, addrs := range origToAddr {
			if len(addrs) < 2 {
				continue // name is unambiguous
			}
			if !strings.Contains(u.Body, n) {
				continue // this body does not reference the name
			}
			// Which of the shared name's addresses does this caller hit?
			target := 0
			for _, a := range addrs {
				if callEdges[u.Addr][a] {
					if target != 0 {
						target = -1 // multiple targets — leave the base name
						break
					}
					target = a
				}
			}
			if target > 0 {
				if nn := addrToNew[target]; nn != n {
					// Match a call with arguments `name(args)` or the
					// cast-form `((int (*)())name)(x)` / address context
					// `name)`, but NOT the 0-arg artifact `name()` (the
					// deduped target may be variadic, which a 0-arg call
					// would not compile against).
					re := regexp.MustCompile(`\b(` + regexp.QuoteMeta(n) + `)(?:\s*\([^)]|\))`)
					u.Body = re.ReplaceAllStringFunc(u.Body, func(m string) string {
						return nn + m[len(n):]
					})
				}
			}
		}
	}
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
		u.IsPlainSub = plainSubFileRe.MatchString(e.Name())
		u.PreRename = fmt.Sprintf("sub_%X", u.Addr)
		units = append(units, u)
	}
	sort.Slice(units, func(i, j int) bool { return units[i].Addr < units[j].Addr })
	// Dedupe by address: the naming era left renamed re-decompiles alongside
	// the original sub_<ADDR> files. Keep ONE body per address, preferring
	// the plain sub_<ADDR> unit (pre-rename decompile with data symbols).
	// sort.Slice is NOT stable, so resolve the preference in a second pass.
	kept := make([]fnUnit, 0, len(units))
	addrIdx := map[int]int{}
	for _, u := range units {
		if i, ok := addrIdx[u.Addr]; ok {
			_ = i
			continue
		}
		addrIdx[u.Addr] = len(kept)
		kept = append(kept, u)
	}
	plain := map[int]int{}
	for i, u := range units {
		if u.IsPlainSub {
			plain[u.Addr] = i
		}
	}
	for addr, ui := range plain {
		ki := addrIdx[addr]
		if ki >= 0 && !kept[ki].IsPlainSub {
			kept[ki] = units[ui]
		}
	}
	units = kept
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
