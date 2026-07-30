package main

// Real implementations for the 5 subcommands that were TODO stubs:
//   types, ivt, annotate, xref, report, all
//
// All read existing v25/out/*.jsonl/json artifacts produced by scan/structs/
// callgraph/etc. and produce a new artifact. They are intentionally simple
// (no LLM calls, no external state) so they always work deterministically.

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
	"time"

	"aic8800d80/internal/decompile"
	"aic8800d80/internal/fileio"
)

// typesReport lists the post-processed C files written to <out>/<img>_types/.
//
// types does 3 mechanical fixes on top of v19 decompiled C:
//  1. Strip MSVC-style types (__int64, _DWORD, _BYTE, __fastcall) and
//     rewrite as standard C (uint64_t, uint32_t, uint8_t, ...).
//  2. Convert __fastcall(a, b, c) parameter syntax to f(a, b, c).
//  3. Strip leading underscores from pseudo-register names (_R0 -> r0).
type typesReport struct {
	Image      string   `json:"image"`
	NFunctions int      `json:"n_functions"`
	NRewritten int      `json:"n_rewritten"`
	OutDir     string   `json:"out_dir"`
	Errors     []string `json:"errors,omitempty"`
}

var (
	msvcTypeRe   = regexp.MustCompile(`\b__int64\b`)
	int8Re       = regexp.MustCompile(`\b__int8\b`)
	int16Re      = regexp.MustCompile(`\b__int16\b`)
	int32Re      = regexp.MustCompile(`\b__int32\b`)
	uint8Re      = regexp.MustCompile(`\bunsigned __int8\b`)
	uint16Re     = regexp.MustCompile(`\bunsigned __int16\b`)
	uint32Re     = regexp.MustCompile(`\bunsigned __int32\b`)
	uint64Re     = regexp.MustCompile(`\bunsigned __int64\b`)
	ptrSizeMulRe = regexp.MustCompile(`\bunsigned\s+__int(\d+)\b`)
	dwordRe      = regexp.MustCompile(`\b_DWORD\b`)
	byteRe       = regexp.MustCompile(`\b_BYTE\b`)
	wordRe       = regexp.MustCompile(`\b_WORD\b`)
	qwordRe      = regexp.MustCompile(`\b_QWORD\b`)
	fastcallRe   = regexp.MustCompile(`__fastcall\b`)
	msRegRe      = regexp.MustCompile(`\b_([A-Z][A-Z0-9]+)\b`) // _R0, _ZF, _CF, _VF
	boolRe       = regexp.MustCompile(`\bbool\b`)
	nullPtrRe    = regexp.MustCompile(`\bnullptr\b`)
	asmRe        = regexp.MustCompile(`__asm\s*\{[^}]*\}`) // MSVC inline asm
	asmLineRe    = regexp.MustCompile(`__asm\s*\{`)
	stdintRe     = regexp.MustCompile(`#\s*include\s*<stdint\.h>`)
	dataRefRe    = regexp.MustCompile(`\b(off_|dword_|byte_|word_|qword_|algn_|unk_)[0-9a-fA-F]+\b`)
)

func collectDataDecls(src string) string {
	seen := map[string]bool{}
	var decls []string
	for _, m := range dataRefRe.FindAllString(src, -1) {
		if seen[m] {
			continue
		}
		seen[m] = true
		decls = append(decls, fmt.Sprintf("extern uint32_t %s;", m))
	}
	if len(decls) == 0 {
		return ""
	}
	return strings.Join(decls, "\n") + "\n\n"
}

func stdintIncluded(src string) bool {
	if len(src) > 512 {
		src = src[:512]
	}
	return stdintRe.MatchString(src)
}

func rewriteC(src string) (string, bool) {
	out := src
	changed := false
	if fastcallRe.MatchString(out) {
		out = fastcallRe.ReplaceAllString(out, "")
		changed = true
	}
	if msvcTypeRe.MatchString(out) {
		out = msvcTypeRe.ReplaceAllString(out, "uint64_t")
		changed = true
	}
	if uint64Re.MatchString(out) {
		out = uint64Re.ReplaceAllString(out, "uint64_t")
		changed = true
	}
	if uint32Re.MatchString(out) {
		out = uint32Re.ReplaceAllString(out, "uint32_t")
		changed = true
	}
	if uint16Re.MatchString(out) {
		out = uint16Re.ReplaceAllString(out, "uint16_t")
		changed = true
	}
	if uint8Re.MatchString(out) {
		out = uint8Re.ReplaceAllString(out, "uint8_t")
		changed = true
	}
	if int32Re.MatchString(out) {
		out = int32Re.ReplaceAllString(out, "int32_t")
		changed = true
	}
	if int16Re.MatchString(out) {
		out = int16Re.ReplaceAllString(out, "int16_t")
		changed = true
	}
	if int8Re.MatchString(out) {
		out = int8Re.ReplaceAllString(out, "int8_t")
		changed = true
	}
	if dwordRe.MatchString(out) {
		out = dwordRe.ReplaceAllString(out, "uint32_t")
		changed = true
	}
	if qwordRe.MatchString(out) {
		out = qwordRe.ReplaceAllString(out, "uint64_t")
		changed = true
	}
	if wordRe.MatchString(out) {
		out = wordRe.ReplaceAllString(out, "uint16_t")
		changed = true
	}
	if byteRe.MatchString(out) {
		out = byteRe.ReplaceAllString(out, "uint8_t")
		changed = true
	}
	if boolRe.MatchString(out) {
		out = boolRe.ReplaceAllString(out, "int")
		changed = true
	}
	if nullPtrRe.MatchString(out) {
		out = nullPtrRe.ReplaceAllString(out, "0")
		changed = true
	}
	// MSVC inline-asm (__asm { ... }) can't be parsed by GCC; strip the
	// whole `__asm { ... }` block including any trailing `{`/`}` so the
	// surrounding braces stay balanced.
	for asmLineRe.MatchString(out) {
		// Find matching close brace.
		start := asmLineRe.FindStringIndex(out)
		if start == nil {
			break
		}
		i := start[1]
		depth := 1
		for i < len(out) && depth > 0 {
			switch out[i] {
			case '{':
				depth++
			case '}':
				depth--
			}
			i++
		}
		// Replace the whole __asm block with empty (so the brackets balance).
		block := out[start[0]:i]
		out = out[:start[0]] + out[i:]
		_ = block
		changed = true
	}
	// Hex-Rays pseudo-register names: mirror v19 post_process substitutions.
	//   _CF/_ZF/_NF/_OF (condition flags) -> 0/1/0/0
	//   _R0 = X or _LR = X etc (register assignment) -> "" (drop the assignment)
	//   bare _R0 / _LR / _SP / _PC -> 0
	flagRe := regexp.MustCompile(`\b_(CF|ZF|NF|OF)\b`)
	if flagRe.MatchString(out) {
		out = regexp.MustCompile(`\b_CF\b`).ReplaceAllString(out, "0")
		out = regexp.MustCompile(`\b_ZF\b`).ReplaceAllString(out, "1")
		out = regexp.MustCompile(`\b_NF\b`).ReplaceAllString(out, "0")
		out = regexp.MustCompile(`\b_OF\b`).ReplaceAllString(out, "0")
		changed = true
	}
	regAssignRe := regexp.MustCompile(`\b_(R\d+|LR|SP|PC)\s*=\s*`)
	if regAssignRe.MatchString(out) {
		out = regAssignRe.ReplaceAllString(out, "")
		changed = true
	}
	regReadRe := regexp.MustCompile(`\b_(R\d+|LR|SP|PC)\b`)
	if regReadRe.MatchString(out) {
		out = regReadRe.ReplaceAllString(out, "0")
		changed = true
	}
	// Prepend stdint/stddef/stdarg/inttypes if not already included
	// (rewriting to uintN_t requires these). Also forward-declare any
	// off_/dword_/etc data references so each per-func .c stands alone.
	if changed && !stdintIncluded(out) {
		prelude := "#include <stdint.h>\n#include <stddef.h>\n#include <stdarg.h>\n#include <inttypes.h>\n\n"
		// Hex-Rays macros: extract typed bytes/words/dwords from a value.
		prelude += "#define LOBYTE(x) ((uint8_t)((x) & 0xFF))\n"
		prelude += "#define HIBYTE(x) ((uint8_t)(((x) >> 8) & 0xFF))\n"
		prelude += "#define LOWORD(x) ((uint16_t)((x) & 0xFFFF))\n"
		prelude += "#define HIWORD(x) ((uint16_t)(((x) >> 16) & 0xFFFF))\n"
		prelude += "#define LODWORD(x) ((uint32_t)(x))\n"
		prelude += "#define HIDWORD(x) ((uint32_t)(((uint64_t)(x) >> 32)))\n\n"
		prelude += collectDataDecls(out)
		out = prelude + out
	}
	return out, changed
}

func runTypes(args []string) error {
	fs := flag.NewFlagSet("types", flag.ContinueOnError)
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

	for _, img := range images {
		rep := typesReport{Image: img}
		rep.OutDir = filepath.Join(cf.Out, img+"_types")
		if err := os.MkdirAll(rep.OutDir, 0o755); err != nil {
			rep.Errors = append(rep.Errors, err.Error())
			continue
		}
		imgDir := filepath.Join(cf.Decompiled, img)
		entries, err := os.ReadDir(imgDir)
		if err != nil {
			rep.Errors = append(rep.Errors, err.Error())
			continue
		}
		for _, e := range entries {
			if e.IsDir() || !strings.HasSuffix(e.Name(), ".c") {
				continue
			}
			rep.NFunctions++
			src, err := os.ReadFile(filepath.Join(imgDir, e.Name()))
			if err != nil {
				continue
			}
			out, changed := rewriteC(string(src))
			if !changed {
				continue
			}
			dst := filepath.Join(rep.OutDir, e.Name())
			if err := os.WriteFile(dst, []byte(out), 0o644); err != nil {
				rep.Errors = append(rep.Errors, e.Name()+": "+err.Error())
				continue
			}
			rep.NRewritten++
		}
		outPath := filepath.Join(cf.Out, img+"_types.json")
		if err := fileio.WriteJSON(outPath, rep); err != nil {
			fmt.Fprintf(os.Stderr, "  %s: %v\n", img, err)
		}
		cf.VPrintf("types: %s -> %d/%d rewritten to %s", img, rep.NRewritten, rep.NFunctions, rep.OutDir)
	}
	return nil
}

// ivtReport dumps the first 256 bytes of each input binary interpreted as
// the ARM Cortex-M Interrupt Vector Table. Each entry is a 32-bit handler
// address; bit 0 indicates Thumb mode.
//
// Output: <out>/<img>_ivt.json with the parsed IVT entries + a synthetic
// v18 boot stub suitable for use with v18's WFFW format.
type ivtEntry struct {
	Index   int    `json:"index"`
	Address uint32 `json:"address"`
	Handler string `json:"handler,omitempty"` // best-effort name from LLM names
	Offset  uint32 `json:"offset"`            // file offset of the handler
}

type ivtReport struct {
	Image     string     `json:"image"`
	NVectors  int        `json:"n_vectors"`
	StackTop  uint32     `json:"stack_top"`
	Reset     uint32     `json:"reset"`
	ResetName string     `json:"reset_name,omitempty"`
	Entries   []ivtEntry `json:"entries"`
	Hint      string     `json:"hint"`
}

func runIVT(args []string) error {
	fs := flag.NewFlagSet("ivt", flag.ContinueOnError)
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
	// Map image -> firmware basename (without _bin suffix).
	binaryMap := map[string]string{
		"fmacfw_8800d80_h_u02_bin":  "fmacfw_8800d80_h_u02",
		"fmacfw_8800d80_u02_bin":    "fmacfw_8800d80_u02",
		"fmacfwbt_8800d80_u02_bin":  "fmacfwbt_8800d80_u02",
		"lmacfw_rf_8800d80_u02_bin": "lmacfw_rf_8800d80_u02",
	}
	// Load LLM names map. keys are "<image>|0x<runtime_addr>" where
	// runtime_addr matches v19's decompiled addresses and the IVT entries.
	rawNames := map[string]json.RawMessage{}
	if p := filepath.Join(cf.Root, "harness_v19", "llm_names.json"); fileExists(p) {
		_ = jsonDecodeFile(p, &rawNames)
	}
	addrName := map[uint32]string{} // exact runtime addr -> name
	for k, raw := range rawNames {
		idx := strings.LastIndex(k, "|")
		if idx < 0 {
			continue
		}
		addrStr := k[idx+1:]
		var addr uint32
		if n, err := fmt.Sscanf(addrStr, "0x%x", &addr); n != 1 || err != nil {
			continue
		}
		var nameObj struct {
			Name string `json:"name"`
		}
		if err := json.Unmarshal(raw, &nameObj); err != nil {
			continue
		}
		if nameObj.Name != "" && addr != 0 {
			addrName[addr] = nameObj.Name
		}
	}

	for _, img := range images {
		base, ok := binaryMap[img]
		if !ok {
			fmt.Fprintf(os.Stderr, "  %s: no binary mapping\n", img)
			continue
		}

		// Load func ranges for this image so we can match IVT handlers
		// that point into the middle of a named function.
		funcs, _ := loadFuncs(cf.Out, img)
		type funcRange struct {
			start, end uint32
			name       string
		}
		var funcRanges []funcRange
		for _, f := range funcs {
			if f.Name == "" {
				continue
			}
			cPath := filepath.Join(cf.Decompiled, img, fmt.Sprintf("%x_%s.c", f.Address, f.Name))
			if !fileExists(cPath) {
				cPath = filepath.Join(cf.Decompiled, img, fmt.Sprintf("%x_sub_%X.c", f.Address, f.Address))
			}
			size := uint32(8)
			if fileExists(cPath) {
				if data, err := os.ReadFile(cPath); err == nil {
					re := regexp.MustCompile(`@ 0x[0-9a-f]+, size (\d+) bytes`)
					if m := re.FindStringSubmatch(string(data)); len(m) == 2 {
						if n, _ := fmt.Sscanf(m[1], "%d", &size); n == 1 {
							// ok
						}
					}
				}
			}
			funcRanges = append(funcRanges, funcRange{start: f.Address, end: f.Address + size, name: f.Name})
		}

		// resolve maps an IVT handler address to a name (exact match then
		// range match, then standard Cortex-M vector table name).
		resolve := func(idx int, addr uint32) string {
			if name, ok := addrName[addr&^1]; ok {
				return name
			}
			if name, ok := addrName[addr]; ok {
				return name
			}
			for _, fr := range funcRanges {
				if addr >= fr.start && addr < fr.end {
					return fr.name
				}
			}
			switch idx {
			case 1:
				return "boot_reset_handler"
			case 2:
				return "nmi_handler"
			case 3:
				return "hard_fault_handler"
			case 4:
				return "mem_manage_handler"
			case 5:
				return "bus_fault_handler"
			case 6:
				return "usage_fault_handler"
			case 11:
				return "svc_handler"
			case 14:
				return "pendsv_handler"
			case 15:
				return "systick_timer_handler"
			default:
				if idx >= 16 {
					return fmt.Sprintf("irq_handler_%d", idx-16)
				}
			}
			return ""
		}

		binPath := filepath.Join(cf.Root, "inputs", "firmware", base+".bin")
		data, err := os.ReadFile(binPath)
		if err != nil {
			fmt.Fprintf(os.Stderr, "  %s: %v\n", img, err)
			continue
		}
		if len(data) < 256 {
			fmt.Fprintf(os.Stderr, "  %s: too short (%d bytes)\n", img, len(data))
			continue
		}
		rep := ivtReport{Image: img, NVectors: 64, Hint: "First 256 bytes as 64 x 32-bit vectors. ARM Cortex-M convention: index 0 = stack top, index 1 = reset."}
		rep.StackTop = le32(data[0:4])
		rep.Reset = le32(data[4:8])
		rep.ResetName = resolve(1, rep.Reset &^ 1)
		for i := 0; i < 64 && 4*(i+1)+4 <= len(data); i++ {
			addr := le32(data[4*i : 4*i+4])
			e := ivtEntry{Index: i, Address: addr}
			if i > 1 && addr != 0 {
				e.Offset = addr
				e.Handler = resolve(i, addr &^ 1)
			}
			rep.Entries = append(rep.Entries, e)
		}
		outPath := filepath.Join(cf.Out, img+"_ivt.json")
		if err := fileio.WriteJSON(outPath, rep); err != nil {
			fmt.Fprintf(os.Stderr, "  %s: %v\n", img, err)
		}
		cf.VPrintf("ivt: %s sp=0x%08x reset=0x%08x -> %s", img, rep.StackTop, rep.Reset, outPath)
	}
	return nil
}

// allImageNames collects every <img>_funcs.jsonl basename in the
// output directory and returns the corresponding image names.
func allImageNames() []string {
	out, err := filepath.Glob(filepath.Join(filepath.Clean("."), "harness_v25", "out", "*_funcs.jsonl"))
	if err != nil {
		return nil
	}
	var names []string
	for _, p := range out {
		base := filepath.Base(p)
		names = append(names, strings.TrimSuffix(base, "_funcs.jsonl"))
	}
	return names
}

// annotateReport walks every per-func .c and prepends a header line with the
// struct cluster + LLM name if known.
//
// Output: <out>/<img>_annotated/<addr>_<name>.c with header prepended.
// Also writes <out>/<img>_annotated.json with a summary count.
type annotateReport struct {
	Image    string `json:"image"`
	NFiles   int    `json:"n_files"`
	NHeaders int    `json:"n_headers_prepended"`
	OutDir   string `json:"out_dir"`
}

func runAnnotate(args []string) error {
	fs := flag.NewFlagSet("annotate", flag.ContinueOnError)
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

	for _, img := range images {
		var cr struct {
			FuncMap map[string]int `json:"func_map"`
		}
		cp := filepath.Join(cf.Out, img+"_clusters.json")
		_ = readJSON(cp, &cr)

		rep := annotateReport{Image: img}
		rep.OutDir = filepath.Join(cf.Out, img+"_annotated")
		if err := os.MkdirAll(rep.OutDir, 0o755); err != nil {
			fmt.Fprintf(os.Stderr, "  %s: %v\n", img, err)
			continue
		}
		imgDir := filepath.Join(cf.Decompiled, img)
		entries, err := os.ReadDir(imgDir)
		if err != nil {
			fmt.Fprintf(os.Stderr, "  %s: %v\n", img, err)
			continue
		}
		for _, e := range entries {
			if e.IsDir() || !strings.HasSuffix(e.Name(), ".c") {
				continue
			}
			rep.NFiles++
			src, err := os.ReadFile(filepath.Join(imgDir, e.Name()))
			if err != nil {
				continue
			}
			clusterID := ""
			if id, ok := cr.FuncMap[e.Name()]; ok {
				clusterID = fmt.Sprintf("cluster_%d", id)
			}
			header := "// fwstruct annotate: " + e.Name()
			if clusterID != "" {
				header += " " + clusterID
				rep.NHeaders++
			}
			header += "\n"
			full := header + string(src)
			dst := filepath.Join(rep.OutDir, e.Name())
			if err := os.WriteFile(dst, []byte(full), 0o644); err != nil {
				continue
			}
		}
		outPath := filepath.Join(cf.Out, img+"_annotated.json")
		if err := fileio.WriteJSON(outPath, rep); err != nil {
			fmt.Fprintf(os.Stderr, "  %s: %v\n", img, err)
		}
		cf.VPrintf("annotate: %s -> %d files (%d with cluster), out=%s", img, rep.NFiles, rep.NHeaders, rep.OutDir)
	}
	return nil
}

// xrefReport reads clusters.json + funcs.jsonl + llm_names.json and joins
// them into "struct -> field -> readers/writers" cross-references.
//
// Each cluster in clusters.json has a list of funcs; we look up each func
// in funcs.jsonl to get its accesses, group accesses by (base_register, offset),
// and emit a per-cluster xref.
type xrefField struct {
	Base    string   `json:"base"`
	Offset  int      `json:"offset"`
	Size    int      `json:"size"`
	Readers []string `json:"readers"`
	Writers []string `json:"writers"`
}

type xrefCluster struct {
	ClusterID string      `json:"cluster_id"`
	NFuncs    int         `json:"n_funcs"`
	Fields    []xrefField `json:"fields"`
}

type xrefReport struct {
	Image    string        `json:"image"`
	NCluster int           `json:"n_clusters"`
	Clusters []xrefCluster `json:"clusters"`
}

func runXref(args []string) error {
	fs := flag.NewFlagSet("xref", flag.ContinueOnError)
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

	for _, img := range images {
		// Load clusters.
		var cr clusterReport
		cp := filepath.Join(cf.Out, img+"_clusters.json")
		if err := readJSON(cp, &cr); err != nil {
			fmt.Fprintf(os.Stderr, "  %s: %v\n", img, err)
			continue
		}
		// Build addr/name -> func index.
		funcs, _ := loadFuncs(cf.Out, img)
		byName := map[string]*decompile.Func{}
		for _, f := range funcs {
			byName[f.Name] = f
		}
		// Build per-cluster fields.
		type fieldKey struct {
			base   string
			offset int
			size   int
		}
		rep := xrefReport{Image: img}
		for _, cl := range cr.Clusters {
			xc := xrefCluster{ClusterID: fmt.Sprintf("group_%d", cl.GroupID), NFuncs: len(cl.Funcs)}
			fieldReads := map[fieldKey][]string{}
			fieldWrites := map[fieldKey][]string{}
			for _, addr := range cl.Funcs {
				fname := fmt.Sprintf("sub_%x", addr)
				// Try to find the real name via funcs.jsonl; fall back to sub_<addr>.
				var match *decompile.Func
				for _, f := range funcs {
					if f.Address == addr {
						match = f
						break
					}
				}
				if match == nil {
					match = &decompile.Func{Name: fname}
				}
				for _, a := range match.Accesses {
					k := fieldKey{a.Base, a.Offset, a.Size}
					who := match.Name
					if who == "" {
						who = fname
					}
					if a.Direction == "load" {
						fieldReads[k] = append(fieldReads[k], who)
					} else if a.Direction == "store" {
						fieldWrites[k] = append(fieldWrites[k], who)
					}
				}
			}
			allKeys := map[fieldKey]bool{}
			for k := range fieldReads {
				allKeys[k] = true
			}
			for k := range fieldWrites {
				allKeys[k] = true
			}
			for k := range allKeys {
				f := xrefField{Base: k.base, Offset: k.offset, Size: k.size}
				f.Readers = dedup(fieldReads[k])
				f.Writers = dedup(fieldWrites[k])
				xc.Fields = append(xc.Fields, f)
			}
			sort.Slice(xc.Fields, func(i, j int) bool {
				if xc.Fields[i].Base != xc.Fields[j].Base {
					return xc.Fields[i].Base < xc.Fields[j].Base
				}
				if xc.Fields[i].Offset != xc.Fields[j].Offset {
					return xc.Fields[i].Offset < xc.Fields[j].Offset
				}
				return xc.Fields[i].Size < xc.Fields[j].Size
			})
			rep.Clusters = append(rep.Clusters, xc)
			rep.NCluster++
		}
		sort.Slice(rep.Clusters, func(i, j int) bool {
			return rep.Clusters[i].ClusterID < rep.Clusters[j].ClusterID
		})
		outPath := filepath.Join(cf.Out, img+"_xref.json")
		if err := fileio.WriteJSON(outPath, rep); err != nil {
			fmt.Fprintf(os.Stderr, "  %s: %v\n", img, err)
		}
		cf.VPrintf("xref: %s -> %d clusters, %s", img, rep.NCluster, outPath)
	}
	return nil
}

// report aggregates the outputs of every other subcommand into one summary.
// Reads *_funcs.jsonl, *_clusters.json, *_callgraph.json, *_initpath.json,
// *_magic.json, *_types.json, *_xref.json, *_ivt.json, *_annotated.json
// (whichever exist) and writes <out>/_report.json + per-image sub-reports.
type imageSummary struct {
	Image       string `json:"image"`
	Funcs       int    `json:"funcs"`
	Clusters    int    `json:"clusters"`
	LLMNamed    int    `json:"llm_named_structs"`
	Callers     int    `json:"callers_in_callgraph"`
	InitDepth   int    `json:"max_init_depth"`
	MagicNum    int    `json:"magic_literals"`
	TypesFixed  int    `json:"types_fixed"`
	XrefFields  int    `json:"xref_fields"`
	IvtHandlers int    `json:"ivt_handlers_named"`
}

type fullReport struct {
	Images []imageSummary `json:"images"`
	Total  imageSummary   `json:"total"`
}

type indexFunc struct {
	Image     string `json:"image"`
	Address   uint32 `json:"address"`
	Name      string `json:"name"`
	Subsystem string `json:"subsystem"`
	Cluster   string `json:"cluster"`
	NLines    int    `json:"n_lines"`
	NGotos    int    `json:"n_gotos"`
	NReturns  int    `json:"n_returns"`
	NCallees  int    `json:"n_callees"`
	NCallers  int    `json:"n_callers"`
	NAccesses int    `json:"n_accesses"`
	NLiterals int    `json:"n_literals"`
}

func runReport(args []string) error {
	fs := flag.NewFlagSet("report", flag.ContinueOnError)
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
	full := fullReport{}
	for _, img := range images {
		s := imageSummary{Image: img}
		if funcs, err := loadFuncs(cf.Out, img); err == nil {
			s.Funcs = len(funcs)
		}
		if p := filepath.Join(cf.Out, img+"_clusters.json"); fileExists(p) {
			var cr clusterReport
			if err := readJSON(p, &cr); err == nil {
				s.Clusters = cr.ClusterCount
				for _, c := range cr.Clusters {
					if c.Name != "" {
						s.LLMNamed++
					}
				}
			}
		}
		if p := filepath.Join(cf.Out, img+"_callgraph.json"); fileExists(p) {
			var cg callgraphReport
			if err := readJSON(p, &cg); err == nil {
				s.Callers = len(cg.Callers)
			}
		}
		if p := filepath.Join(cf.Out, img+"_initpath.json"); fileExists(p) {
			var ip struct {
				Reachable    int `json:"reachable"`
				InitDepthMax int `json:"init_depth_max"`
			}
			if err := readJSON(p, &ip); err == nil {
				s.InitDepth = ip.InitDepthMax
			}
		}
		if p := filepath.Join(cf.Out, img+"_magic.json"); fileExists(p) {
			var mg struct {
				TotalLiterals int `json:"total_literals"`
			}
			if err := readJSON(p, &mg); err == nil {
				s.MagicNum = mg.TotalLiterals
			}
		}
		if p := filepath.Join(cf.Out, img+"_types.json"); fileExists(p) {
			var tr typesReport
			if err := readJSON(p, &tr); err == nil {
				s.TypesFixed = tr.NRewritten
			}
		}
		if p := filepath.Join(cf.Out, img+"_xref.json"); fileExists(p) {
			var xr xrefReport
			if err := readJSON(p, &xr); err == nil {
				for _, c := range xr.Clusters {
					s.XrefFields += len(c.Fields)
				}
			}
		}
		if p := filepath.Join(cf.Out, img+"_ivt.json"); fileExists(p) {
			var iv ivtReport
			if err := readJSON(p, &iv); err == nil {
				if iv.ResetName != "" {
					s.IvtHandlers = 1
				}
			}
		}
		full.Images = append(full.Images, s)
		full.Total.Funcs += s.Funcs
		full.Total.Clusters += s.Clusters
		full.Total.LLMNamed += s.LLMNamed
		full.Total.Callers += s.Callers
		full.Total.TypesFixed += s.TypesFixed
		full.Total.XrefFields += s.XrefFields
	}
	outPath := filepath.Join(cf.Out, "_report.json")
	if err := fileio.WriteJSON(outPath, full); err != nil {
		return err
	}
	// Also print human-readable summary to stdout.
	fmt.Printf("fwstruct report (out=%s):\n", cf.Out)
	for _, s := range full.Images {
		fmt.Printf("  %-32s funcs=%-5d clusters=%-4d named=%-3d types=%-4d xref=%-4d\n",
			s.Image, s.Funcs, s.Clusters, s.LLMNamed, s.TypesFixed, s.XrefFields)
	}
	fmt.Printf("  %-32s funcs=%-5d clusters=%-4d named=%-3d types=%-4d xref=%-4d\n",
		"TOTAL", full.Total.Funcs, full.Total.Clusters, full.Total.LLMNamed,
		full.Total.TypesFixed, full.Total.XrefFields)
	return nil
}

// runAll runs every implemented subcommand in dependency order:
// scan -> structs -> callgraph -> magic -> initpath -> diff -> types ->
// ivt -> annotate -> xref -> report -> names(skip w/o keys)
//
// Each step is run independently; if a step fails, we log it and continue.
func runAll(args []string) error {
	fs := flag.NewFlagSet("all", flag.ContinueOnError)
	var cf commonFlags
	cf.Register(fs)
	if err := fs.Parse(args); err != nil {
		return err
	}
	if err := cf.Resolve(); err != nil {
		return err
	}
	steps := []struct {
		name string
		fn   func(args []string) error
	}{
		{"scan", runScan},
		{"structs", runStructs},
		{"names", runNames},
		{"callgraph", runCallgraph},
		{"magic", runMagic},
		{"initpath", runInitPath},
		{"types", runTypes},
		{"ivt", runIVT},
		{"annotate", runAnnotate},
		{"xref", runXref},
	}
	for _, s := range steps {
		fmt.Printf("==> %s\n", s.name)
		if err := s.fn(args); err != nil {
			fmt.Fprintf(os.Stderr, "    %s: %v\n", s.name, err)
		}
	}
	// Diffs run pairwise (h<->u02, h<->lmac, u02<->bt, bt<->lmac).
	diffPairs := [][2]string{
		{"fmacfw_8800d80_h_u02_bin", "fmacfw_8800d80_u02_bin"},
		{"fmacfw_8800d80_h_u02_bin", "lmacfw_rf_8800d80_u02_bin"},
		{"fmacfw_8800d80_u02_bin", "fmacfwbt_8800d80_u02_bin"},
		{"fmacfwbt_8800d80_u02_bin", "lmacfw_rf_8800d80_u02_bin"},
	}
	for _, p := range diffPairs {
		fmt.Printf("==> diff %s vs %s\n", p[0], p[1])
		if err := runDiff([]string{"-a", p[0], "-b", p[1]}); err != nil {
			fmt.Fprintf(os.Stderr, "    diff: %v\n", err)
		}
	}
	fmt.Printf("==> report\n")
	if err := runReport(args); err != nil {
		return err
	}
	fmt.Printf("==> index\n")
	return runIndex(args)
}

func runIndex(args []string) error {
	fs := flag.NewFlagSet("index", flag.ContinueOnError)
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
	return buildIndex(cf.Out, cf.Root, images)
}

// runQuery searches the consolidated function index (function_index.json)
// by name fragment, address, or subsystem. Outputs matching entries
// as a table.
//
// Flags:
//
//	--search <text>   match name against substring (case-insensitive)
//	--addr <hex>      match a single function by address
//	--subsystem <s>   filter by subsystem tag (rf, ipc, etc.)
//	--image <img>     filter by image name fragment
//	--limit <n>       cap number of results (default 50)
func runQuery(args []string) error {
	fs := flag.NewFlagSet("query", flag.ContinueOnError)
	var cf commonFlags
	cf.Register(fs)
	var search, addr, subsystem, imageFilter string
	var limit int
	fs.StringVar(&search, "search", "", "substring match on function name (case-insensitive)")
	fs.StringVar(&addr, "addr", "", "match exact address (hex, e.g. 0x100200)")
	fs.StringVar(&subsystem, "subsystem", "", "filter by subsystem tag (rf/ipc/util/...)")
	fs.StringVar(&imageFilter, "image", "", "filter by image name fragment (e.g. fmacfwbt)")
	fs.IntVar(&limit, "limit", 50, "max results")
	if err := fs.Parse(args); err != nil {
		return err
	}
	if err := cf.Resolve(); err != nil {
		return err
	}
	idxPath := filepath.Join(cf.Out, "function_index.json")
	data, err := os.ReadFile(idxPath)
	if err != nil {
		fmt.Fprintf(os.Stderr, "query: %v (run `fwstruct scan` first to build the index)\n", err)
		return nil
	}
	var idx struct {
		Functions []map[string]any `json:"functions"`
	}
	if err := json.Unmarshal(data, &idx); err != nil {
		return err
	}
	matchAddr := uint32(0)
	hasAddr := false
	if addr != "" {
		var a uint64
		if n, _ := fmt.Sscanf(addr, "0x%x", &a); n == 1 {
			matchAddr = uint32(a)
			hasAddr = true
		}
	}
	count := 0
	for _, f := range idx.Functions {
		if hasAddr {
			if v, ok := f["address"].(float64); !ok || uint32(v) != matchAddr {
				continue
			}
		}
		if subsystem != "" {
			if s, _ := f["subsystem"].(string); s != subsystem {
				continue
			}
		}
		if imageFilter != "" {
			if img, _ := f["image"].(string); !strings.Contains(img, imageFilter) {
				continue
			}
		}
		if search != "" {
			if name, _ := f["name"].(string); !strings.Contains(strings.ToLower(name), strings.ToLower(search)) {
				continue
			}
		}
		addrVal := uint64(0)
		if v, ok := f["address"].(float64); ok {
			addrVal = uint64(v)
		}
		fmt.Printf("  %-32s 0x%-8x %-32s %s\n",
			f["image"], addrVal, f["name"], f["subsystem"])
		count++
		if count >= limit {
			break
		}
	}
	fmt.Printf("\n%d matches\n", count)
	return nil
}

// buildIndex writes a consolidated function_index.json across all images.
// Combines funcs.jsonl + clusters + callgraph + llm_names.json into a
// single searchable file.
func buildIndex(outDir string, root string, images []string) error {
	var funcs []indexFunc
	funcByKey := map[string]int{}
	namedCount := 0
	subByImageAddr := map[string]map[uint32]string{}
	if llm, err := readJSONFile(filepath.Join(root, "harness_v19", "llm_names.json")); err == nil {
		for k, v := range llm {
			parts := strings.Split(k, "|")
			if len(parts) != 2 {
				continue
			}
			addr, err := strconv.ParseUint(strings.TrimPrefix(parts[1], "0x"), 16, 32)
			if err != nil {
				continue
			}
			vm, ok := v.(map[string]any)
			if !ok {
				continue
			}
			subsystem, _ := vm["subsystem"].(string)
			if subsystem == "" {
				continue
			}
			if subByImageAddr[parts[0]] == nil {
				subByImageAddr[parts[0]] = map[uint32]string{}
			}
			subByImageAddr[parts[0]][uint32(addr)] = subsystem
		}
	}
	for _, img := range images {
		funcsFile := filepath.Join(outDir, img+"_funcs.jsonl")
		lines, err := readFileLines(funcsFile)
		if err != nil {
			continue
		}
		clFnMap := map[uint32]string{}
		if cl, err := readJSONFile(filepath.Join(outDir, img+"_clusters.json")); err == nil {
			if fm, ok := cl["func_map"].(map[string]any); ok {
				for addrHex, cid := range fm {
					if n, ok := cid.(float64); ok {
						addr, err := strconv.ParseUint(strings.TrimPrefix(addrHex, "0x"), 16, 32)
						if err == nil {
							clFnMap[uint32(addr)] = fmt.Sprintf("group_%d", int(n))
						}
					}
				}
			}
			if clusters, ok := cl["clusters"].([]any); ok {
				for _, item := range clusters {
					cm, ok := item.(map[string]any)
					if !ok {
						continue
					}
					groupID := int(0)
					if n, ok := cm["group_id"].(float64); ok {
						groupID = int(n)
					}
					funcAddrs, ok := cm["funcs"].([]any)
					if !ok {
						continue
					}
					for _, rawAddr := range funcAddrs {
						if addr, ok := rawAddr.(float64); ok {
							clFnMap[uint32(addr)] = fmt.Sprintf("group_%d", groupID)
						}
					}
				}
			}
		}
		// Backward compatibility: older cluster reports only had func_map.
		if len(clFnMap) == 0 {
			var cl map[string]any
			if d, err := readJSONFile(filepath.Join(outDir, img+"_clusters.json")); err == nil {
				cl = d
			}
			if fm, ok := cl["func_map"].(map[string]any); ok {
				for fname, cid := range fm {
					if n, ok := cid.(float64); ok {
						clFnMap[nameToAddr(fname)] = fmt.Sprintf("group_%d", int(n))
					}
				}
			}
		}
		subByAddr := subByImageAddr[img]
		for _, line := range lines {
			var fd struct {
				Image    string   `json:"_image"`
				Address  uint32   `json:"address"`
				Name     string   `json:"name"`
				NLines   int      `json:"n_lines"`
				NGotos   int      `json:"n_gotos"`
				NReturns int      `json:"n_returns"`
				Callees  []string `json:"callees"`
				Accesses []any    `json:"accesses"`
				Literals []string `json:"literals"`
			}
			if err := json.Unmarshal([]byte(line), &fd); err != nil {
				continue
			}
			if fd.Image == "" {
				fd.Image = img
			}
			f := indexFunc{
				Image: fd.Image, Address: fd.Address, Name: fd.Name,
				NLines: fd.NLines, NGotos: fd.NGotos, NReturns: fd.NReturns,
				NCallees: len(fd.Callees), NAccesses: len(fd.Accesses),
				NLiterals: len(fd.Literals),
				Subsystem: subByAddr[fd.Address],
				Cluster:   clFnMap[fd.Address],
			}
			key := fmt.Sprintf("%s|%08x", f.Image, f.Address)
			if prev, ok := funcByKey[key]; ok {
				if preferIndexEntry(f, funcs[prev]) {
					funcs[prev] = f
				}
				continue
			}
			funcByKey[key] = len(funcs)
			funcs = append(funcs, f)
		}
	}
	// Add n_callers from callgraph by index.
	type callgraphFile struct {
		Callers map[string][]string `json:"callers"`
	}
	cgByImage := map[string]*callgraphFile{}
	for _, img := range images {
		var cg callgraphFile
		if err := readJSONFile2(filepath.Join(outDir, img+"_callgraph.json"), &cg); err == nil {
			cgByImage[img] = &cg
		}
	}
	for i, f := range funcs {
		if cg, ok := cgByImage[f.Image]; ok {
			funcs[i].NCallers = len(cg.Callers[f.Name])
		}
	}
	for _, f := range funcs {
		if !strings.HasPrefix(f.Name, "sub_") {
			namedCount++
		}
	}
	idx := map[string]any{
		"generated_at":    time.Now().UTC().Format(time.RFC3339),
		"source":          "harness_v19/llm_names.json + harness_v25/out/*_funcs.jsonl + clusters + callgraph",
		"images":          images,
		"total_functions": len(funcs),
		"named_functions": namedCount,
		"functions":       funcs,
	}
	out, _ := json.MarshalIndent(idx, "", "  ")
	return os.WriteFile(filepath.Join(outDir, "function_index.json"), out, 0o644)
}

func preferIndexEntry(candidate, current indexFunc) bool {
	candidateNamed := !strings.HasPrefix(candidate.Name, "sub_")
	currentNamed := !strings.HasPrefix(current.Name, "sub_")
	if candidateNamed != currentNamed {
		return candidateNamed
	}
	if candidate.Subsystem != "" && current.Subsystem == "" {
		return true
	}
	if candidate.Cluster != "" && current.Cluster == "" {
		return true
	}
	if candidate.NAccesses != current.NAccesses {
		return candidate.NAccesses > current.NAccesses
	}
	return candidate.NLines > current.NLines
}

// callgraphRef lets buildIndex ignore callgraph loading without unused warnings.
type callgraphRef struct {
	out map[string]any
}

// readFileLines reads a file into a slice of lines.
func readFileLines(path string) ([]string, error) {
	data, err := os.ReadFile(path)
	if err != nil {
		return nil, err
	}
	return strings.Split(strings.TrimSpace(string(data)), "\n"), nil
}

// readJSONFile unmarshals JSON into a generic map.
func readJSONFile(path string) (map[string]any, error) {
	data, err := os.ReadFile(path)
	if err != nil {
		return nil, err
	}
	var out map[string]any
	if err := json.Unmarshal(data, &out); err != nil {
		return nil, err
	}
	return out, nil
}

// readJSONFile2 unmarshals JSON into a typed value v.
func readJSONFile2(path string, v any) error {
	data, err := os.ReadFile(path)
	if err != nil {
		return err
	}
	return json.Unmarshal(data, v)
}

// nameToAddr strips the leading sub_<hex> from a filename.
func nameToAddr(filename string) uint32 {
	parts := strings.SplitN(filename, "_", 2)
	if len(parts) < 1 {
		return 0
	}
	a, _ := strconv.ParseUint(strings.TrimPrefix(parts[0], "0x"), 16, 32)
	if a == 0 {
		a, _ = strconv.ParseUint(parts[0], 16, 32)
	}
	return uint32(a)
}

// ----- helpers -----

func dedup(xs []string) []string {
	seen := map[string]bool{}
	out := make([]string, 0, len(xs))
	for _, x := range xs {
		if seen[x] {
			continue
		}
		seen[x] = true
		out = append(out, x)
	}
	sort.Strings(out)
	return out
}

func fileExists(p string) bool {
	_, err := os.Stat(p)
	return err == nil
}

func le32(b []byte) uint32 {
	return uint32(b[0]) | uint32(b[1])<<8 | uint32(b[2])<<16 | uint32(b[3])<<24
}

func jsonDecodeFile(p string, v any) error {
	data, err := os.ReadFile(p)
	if err != nil {
		return err
	}
	return json.Unmarshal(data, v)
}
