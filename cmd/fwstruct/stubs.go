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
	"strings"

	"aic8800d80/internal/decompile"
	"aic8800d80/internal/fileio"
)

// typesReport lists the post-processed C files written to <out>/<img>_types/.
//
// types does 3 mechanical fixes on top of v19 decompiled C:
//   1. Strip MSVC-style types (__int64, _DWORD, _BYTE, __fastcall) and
//      rewrite as standard C (uint64_t, uint32_t, uint8_t, ...).
//   2. Convert __fastcall(a, b, c) parameter syntax to f(a, b, c).
//   3. Strip leading underscores from pseudo-register names (_R0 -> r0).
type typesReport struct {
	Image     string   `json:"image"`
	NFunctions int      `json:"n_functions"`
	NRewritten int      `json:"n_rewritten"`
	OutDir    string   `json:"out_dir"`
	Errors    []string `json:"errors,omitempty"`
}

var (
	msvcTypeRe  = regexp.MustCompile(`\b__int64\b`)
	dwordRe     = regexp.MustCompile(`\b_DWORD\b`)
	byteRe      = regexp.MustCompile(`\b_BYTE\b`)
	wordRe      = regexp.MustCompile(`\b_WORD\b`)
	fastcallRe  = regexp.MustCompile(`__fastcall\b`)
	msRegRe     = regexp.MustCompile(`\b_([A-Z][A-Z0-9]+)\b`) // _R0, _ZF, _CF, _VF
)

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
	if dwordRe.MatchString(out) {
		out = dwordRe.ReplaceAllString(out, "uint32_t")
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
	if msRegRe.MatchString(out) {
		out = msRegRe.ReplaceAllString(out, "$1")
		changed = true
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
	Image     string         `json:"image"`
	NVectors  int            `json:"n_vectors"`
	StackTop  uint32         `json:"stack_top"`
	Reset     uint32         `json:"reset"`
	ResetName string         `json:"reset_name,omitempty"`
	Entries   []ivtEntry     `json:"entries"`
	Hint      string         `json:"hint"`
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
		"fmacfw_8800d80_h_u02_bin":   "fmacfw_8800d80_h_u02",
		"fmacfw_8800d80_u02_bin":     "fmacfw_8800d80_u02",
		"fmacfwbt_8800d80_u02_bin":   "fmacfwbt_8800d80_u02",
		"lmacfw_rf_8800d80_u02_bin":  "lmacfw_rf_8800d80_u02",
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
		// range match).
		resolve := func(addr uint32) string {
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
		rep.ResetName = resolve(rep.Reset &^ 1)
		for i := 0; i < 64 && 4*(i+1)+4 <= len(data); i++ {
			addr := le32(data[4*i : 4*i+4])
			e := ivtEntry{Index: i, Address: addr}
			if i > 1 && addr != 0 {
				e.Offset = addr
				e.Handler = resolve(addr&^1)
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
	Image     string `json:"image"`
	NFiles    int    `json:"n_files"`
	NHeaders  int    `json:"n_headers_prepended"`
	OutDir    string `json:"out_dir"`
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
		{"callgraph", runCallgraph},
		{"magic", runMagic},
		{"initpath", runInitPath},
		{"types", runTypes},
		{"ivt", runIVT},
		{"annotate", runAnnotate},
		{"xref", runXref},
		{"report", runReport},
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
	return runReport(args)
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
