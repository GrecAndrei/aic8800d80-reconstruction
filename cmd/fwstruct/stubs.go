package main

// Helpers shared by the remaining fwstruct subcommands (index/query) and the
// older artifacts. The runX subcommand implementations live in their own
// files (types.go, ivt.go, annotate.go, xref.go, report.go, all.go).

import (
	"encoding/json"
	"flag"
	"fmt"
	"os"
	"path/filepath"
	"sort"
	"strconv"
	"strings"
	"time"
)

// typesReport lists the post-processed C files written to <out>/<img>_types/.
//
// types does 3 mechanical fixes on top of v19 decompiled C:
//  1. Strip MSVC-style types (__int64, _DWORD, _BYTE, __fastcall) and
//     rewrite as standard C (uint64_t, uint32_t, uint8_t, ...).
//  2. Convert __fastcall(a, b, c) parameter syntax to f(a, b, c).
//  3. Strip leading underscores from pseudo-register names (_R0 -> r0).




// ivtReport dumps the first 256 bytes of each input binary interpreted as
// the ARM Cortex-M Interrupt Vector Table. Each entry is a 32-bit handler
// address; bit 0 indicates Thumb mode.
//
// Output: <out>/<img>_ivt.json with the parsed IVT entries + a synthetic
// v18 boot stub suitable for use with v18's WFFW format.



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


// xrefReport reads clusters.json + funcs.jsonl + llm_names.json and joins
// them into "struct -> field -> readers/writers" cross-references.
//
// Each cluster in clusters.json has a list of funcs; we look up each func
// in funcs.jsonl to get its accesses, group accesses by (base_register, offset),
// and emit a per-cluster xref.




// report aggregates the outputs of every other subcommand into one summary.
// Reads *_funcs.jsonl, *_clusters.json, *_callgraph.json, *_initpath.json,
// *_magic.json, *_types.json, *_xref.json, *_ivt.json, *_annotated.json
// (whichever exist) and writes <out>/_report.json + per-image sub-reports.


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


// runAll runs every implemented subcommand in dependency order:
// scan -> structs -> callgraph -> magic -> initpath -> diff -> types ->
// ivt -> annotate -> xref -> report -> names(skip w/o keys)
//
// Each step is run independently; if a step fails, we log it and continue.

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
