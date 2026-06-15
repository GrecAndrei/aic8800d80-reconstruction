package main

import (
	"encoding/json"
	"flag"
	"fmt"
	"os"
	"path/filepath"
	"sort"
	"strings"

	"aic8800d80/internal/decompile"
	"aic8800d80/internal/fileio"
)

// runDiff compares funcs across binaries at the same address and reports:
//
//   - identical: same code, same name
//   - modified: same address, different code (variant)
//   - added:    in image B but not in image A
//   - removed:  in image A but not in image B
//
// The default comparison pair is fmacfw_h (base) vs fmacfw_u02 (patch).
func runDiff(args []string) error {
	fs := flag.NewFlagSet("diff", flag.ContinueOnError)
	var cf commonFlags
	cf.Register(fs)
	var a, b string
	fs.StringVar(&a, "a", "fmacfw_8800d80_h_u02_bin", "base image")
	fs.StringVar(&b, "b", "fmacfw_8800d80_u02_bin", "patched image")
	if err := fs.Parse(args); err != nil {
		return err
	}
	if err := cf.Resolve(); err != nil {
		return err
	}

	funcsA, err := loadFuncs(cf.Out, a)
	if err != nil {
		return err
	}
	funcsB, err := loadFuncs(cf.Out, b)
	if err != nil {
		return err
	}
	cf.VPrintf("diff: %s (%d) vs %s (%d)", a, len(funcsA), b, len(funcsB))

	// Build addr -> func
	mapA := map[uint32]*decompile.Func{}
	for _, fn := range funcsA {
		mapA[fn.Address] = fn
	}
	mapB := map[uint32]*decompile.Func{}
	for _, fn := range funcsB {
		mapB[fn.Address] = fn
	}

	// Categorize
	type diffEntry struct {
		Address string `json:"address"`
		NameA   string `json:"name_a,omitempty"`
		NameB   string `json:"name_b,omitempty"`
		NLA     int    `json:"n_lines_a,omitempty"`
		NLB     int    `json:"n_lines_b,omitempty"`
		SameCode bool  `json:"same_code"`
	}
	var identical, modified, added, removed []diffEntry
	visitedB := map[uint32]bool{}
	for addr, fa := range mapA {
		fb, ok := mapB[addr]
		if !ok {
			removed = append(removed, diffEntry{
				Address: fmt.Sprintf("0x%x", addr),
				NameA:   fa.Name, NLA: fa.NLines, SameCode: false,
			})
			continue
		}
		visitedB[addr] = true
		// Compare by hash - use string content hash via callee+access fingerprint
		hashA := quickHash(fa)
		hashB := quickHash(fb)
		entry := diffEntry{
			Address: fmt.Sprintf("0x%x", addr),
			NameA:   fa.Name, NameB: fb.Name,
			NLA: fa.NLines, NLB: fb.NLines,
			SameCode: hashA == hashB,
		}
		if hashA == hashB {
			identical = append(identical, entry)
		} else {
			modified = append(modified, entry)
		}
	}
	for addr, fb := range mapB {
		if !visitedB[addr] {
			added = append(added, diffEntry{
				Address: fmt.Sprintf("0x%x", addr),
				NameB:   fb.Name, NLB: fb.NLines, SameCode: false,
			})
		}
	}
	sort.Slice(modified, func(i, j int) bool { return modified[i].Address < modified[j].Address })
	sort.Slice(added, func(i, j int) bool { return added[i].Address < added[j].Address })
	sort.Slice(removed, func(i, j int) bool { return removed[i].Address < removed[j].Address })

	// Categorize modified: by name change vs by code change
	type modType struct {
		SameName   bool `json:"same_name"`
		Count      int  `json:"count"`
	}
	modByNameChange := map[modType]int{}
	for _, m := range modified {
		modByNameChange[modType{SameName: m.NameA == m.NameB, Count: 0}]++
	}
	_ = modByNameChange

	report := struct {
		BaseImage    string       `json:"base_image"`
		PatchImage   string       `json:"patch_image"`
		BaseFuncs    int          `json:"base_funcs"`
		PatchFuncs   int          `json:"patch_funcs"`
		Identical    int          `json:"identical"`
		Modified     int          `json:"modified"`
		Added        int          `json:"added"`
		Removed      int          `json:"removed"`
		IdenticalList []diffEntry `json:"identical_list"`
		ModifiedList  []diffEntry `json:"modified_list"`
		AddedList     []diffEntry `json:"added_list"`
		RemovedList   []diffEntry `json:"removed_list"`
	}{
		BaseImage: a, PatchImage: b,
		BaseFuncs: len(funcsA), PatchFuncs: len(funcsB),
		Identical: len(identical), Modified: len(modified),
		Added: len(added), Removed: len(removed),
		IdenticalList: identical, ModifiedList: modified,
		AddedList: added, RemovedList: removed,
	}
	outPath := filepath.Join(cf.Out, fmt.Sprintf("diff_%s_vs_%s.json", a, b))
	if err := fileio.WriteJSON(outPath, report); err != nil {
		return err
	}

	// Top 30 modified with biggest line-count delta
	type modByDelta struct {
		Entry diffEntry
		Delta int
	}
	var byDelta []modByDelta
	for _, m := range modified {
		d := m.NLB - m.NLA
		if d < 0 {
			d = -d
		}
		byDelta = append(byDelta, modByDelta{m, d})
	}
	sort.Slice(byDelta, func(i, j int) bool { return byDelta[i].Delta > byDelta[j].Delta })
	fmt.Printf("diff: %s vs %s\n", a, b)
	fmt.Printf("  identical: %d\n", len(identical))
	fmt.Printf("  modified:  %d\n", len(modified))
	fmt.Printf("  added:     %d\n", len(added))
	fmt.Printf("  removed:   %d\n", len(removed))
	fmt.Printf("Top 10 modified by line delta:\n")
	for i, m := range byDelta {
		if i >= 10 {
			break
		}
		fmt.Printf("  %s %s -> %s (delta=%d)\n", m.Entry.Address, m.Entry.NameA, m.Entry.NameB, m.Delta)
	}
	return nil
}

func quickHash(fn *decompile.Func) string {
	// Use a stable hash of: callees + access offsets + n_lines
	callees := strings.Join(fn.Callees, ",")
	offs := make([]string, 0, len(fn.Accesses))
	for _, a := range fn.Accesses {
		offs = append(offs, fmt.Sprintf("%s+%x/%d", a.Base, a.Offset, a.Size))
	}
	sort.Strings(offs)
	return fmt.Sprintf("%d|%s|%s", fn.NLines, callees, strings.Join(offs, ","))
}

// silence unused
var _ = os.Stdin
var _ = json.Marshal
