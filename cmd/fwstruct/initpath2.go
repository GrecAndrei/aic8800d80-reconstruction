package main

import (
	"encoding/binary"
	"flag"
	"fmt"
	"os"
	"path/filepath"
	"sort"
	"strings"

	"aic8800d80/internal/fileio"
)

type callgraphReport2 struct {
	Funcs     map[string]any      `json:"funcs"`
	Callers   map[string][]string `json:"callers"`
	Callees   map[string][]string `json:"callees"`
	TopHubs   []topHub2            `json:"top_hubs"`
	Reachable []string            `json:"reachable"`
	Dead      []string            `json:"dead"`
}

type topHub2 struct {
	Name     string `json:"name"`
	NCallers int    `json:"n_callers"`
}

// resolveFuncPtr reads a function pointer from a binary.
// If addr is "off_1001FC", looks at file offset 0x1FC (chip 0x1001FC - 0x100000) and
// returns the function address stored there.
func resolveFuncPtr(fpName string, binData []byte) uint32 {
	if !strings.HasPrefix(fpName, "off_") && !strings.HasPrefix(fpName, "dword_") {
		return 0
	}
	// Extract addr: "off_1001FC" -> 0x1001FC
	hex := strings.TrimPrefix(strings.TrimPrefix(fpName, "off_"), "dword_")
	var addr uint32
	for i := 0; i < len(hex); i++ {
		c := hex[i]
		var d uint32
		switch {
		case c >= '0' && c <= '9':
			d = uint32(c - '0')
		case c >= 'a' && c <= 'f':
			d = uint32(c-'a') + 10
		case c >= 'A' && c <= 'F':
			d = uint32(c-'A') + 10
		default:
			return 0
		}
		addr = addr*16 + d
	}
	// file offset = addr - 0x100000
	if addr < 0x100000 || addr > 0x200000 {
		return 0
	}
	off := int(addr - 0x100000)
	if off+4 > len(binData) {
		return 0
	}
	return binary.LittleEndian.Uint32(binData[off : off+4])
}

// runInitPath2 is initpath that follows function pointers via binary lookup.
func runInitPath2(args []string) error {
	fs := flag.NewFlagSet("initpath2", flag.ContinueOnError)
	var cf commonFlags
	cf.Register(fs)
	var inputsDir string
	fs.StringVar(&inputsDir, "inputs", "", "original WFFW dir (default <root>/inputs/firmware)")
	if err := fs.Parse(args); err != nil {
		return err
	}
	if err := cf.Resolve(); err != nil {
		return err
	}
	if inputsDir == "" {
		inputsDir = filepath.Join(cf.Root, "inputs", "firmware")
	}
	images, err := cf.SelectedImages()
	if err != nil {
		return err
	}
	cf.VPrintf("initpath2: %d images, following function pointers", len(images))

	for _, img := range images {
		// Load call graph
		var cg callgraphReport2
		if err := readJSON(filepath.Join(cf.Out, img+"_callgraph.json"), &cg); err != nil {
			fmt.Fprintf(os.Stderr, "  %s: %v\n", img, err)
			continue
		}
		// Load binary
		// Image name has "_bin" suffix from decompiled; original file doesn't
		binBase := strings.TrimSuffix(img, "_bin")
		binPath := filepath.Join(inputsDir, binBase+".bin")
		binData, err := os.ReadFile(binPath)
		if err != nil {
			fmt.Fprintf(os.Stderr, "  %s: %v\n", img, err)
			continue
		}
		// Load funcs to get name->addr map
		funcs, _ := loadFuncs(cf.Out, img)
		addrToName := map[uint32]string{}
		for _, fn := range funcs {
			addrToName[fn.Address] = fn.Name
		}
		// BFS that follows function pointers
		visited := map[string]int{}
		queue := []string{"start"}
		visited["start"] = 0
		for len(queue) > 0 {
			n := queue[0]
			queue = queue[1:]
			depth := visited[n]
			for _, c := range cg.Callees[n] {
				if _, ok := visited[c]; ok {
					continue
				}
				// If c is off_XXXX or dword_XXXX, resolve to actual function
				if strings.HasPrefix(c, "off_") || strings.HasPrefix(c, "dword_") {
					ptr := resolveFuncPtr(c, binData)
					if ptr != 0 && ptr&1 == 1 { // Thumb
						ptr &^= 1
					}
					if name, ok := addrToName[ptr]; ok {
						// Replace off_XXXX with the actual function name
						if _, ok := visited[name]; !ok {
							visited[name] = depth + 1
							queue = append(queue, name)
						}
					}
					// Mark off_XXXX as visited too
					visited[c] = depth
				} else {
					visited[c] = depth + 1
					queue = append(queue, c)
				}
			}
		}
		// Categorize
		type funcCat2 struct {
			Name     string   `json:"name"`
			Depth    int      `json:"depth"`
			Category string   `json:"category"`
		}
		cats := map[string][]funcCat2{
			"init": {}, "subsystem": {}, "utility": {}, "fptr": {}, "unreachable": {},
		}
		allNames := map[string]bool{}
		for n := range cg.Callees {
			allNames[n] = true
		}
		for n := range cg.Callers {
			allNames[n] = true
		}
		for n := range visited {
			allNames[n] = true
		}
		initDepth := 0
		for name := range allNames {
			depth, ok := visited[name]
			if !ok {
				depth = -1
			}
			cat := "utility"
			if depth < 0 {
				cat = "unreachable"
			} else if strings.HasPrefix(name, "off_") || strings.HasPrefix(name, "dword_") {
				cat = "fptr"
			} else if depth <= 2 {
				cat = "init"
			} else if depth <= 5 {
				cat = "subsystem"
			}
			cats[cat] = append(cats[cat], funcCat2{Name: name, Depth: depth, Category: cat})
			if depth > initDepth {
				initDepth = depth
			}
		}
		for k := range cats {
			sort.Slice(cats[k], func(i, j int) bool {
				if cats[k][i].Depth != cats[k][j].Depth {
					return cats[k][i].Depth < cats[k][j].Depth
				}
				return cats[k][i].Name < cats[k][j].Name
			})
		}
		report := struct {
			Image   string                `json:"image"`
			Total   int                   `json:"total"`
			Reachable int                 `json:"reachable"`
			InitDepth int                 `json:"init_depth_max"`
			ByCategory map[string][]funcCat2 `json:"by_category"`
			ResolvedFptrs []string        `json:"resolved_fptrs"`
		}{
			Image: img, Total: len(allNames), Reachable: len(visited),
			InitDepth: initDepth, ByCategory: cats,
		}
		// Find resolved fptrs and their target addrs
		for n := range visited {
			if strings.HasPrefix(n, "off_") || strings.HasPrefix(n, "dword_") {
				ptr := resolveFuncPtr(n, binData)
				targetName := ""
				if ptr != 0 {
					ptr &^= 1
					if name, ok := addrToName[ptr]; ok {
						targetName = name
					} else {
						targetName = fmt.Sprintf("phantom_0x%x", ptr)
					}
				}
				report.ResolvedFptrs = append(report.ResolvedFptrs, fmt.Sprintf("%s -> %s", n, targetName))
			}
		}
		sort.Strings(report.ResolvedFptrs)
		outPath := filepath.Join(cf.Out, img+"_initpath2.json")
		if err := fileio.WriteJSON(outPath, report); err != nil {
			return err
		}
		cf.VPrintf("  %s: %d funcs, %d reachable, init_depth=%d, %d fptrs resolved", img, report.Total, report.Reachable, report.InitDepth, len(report.ResolvedFptrs))
	}
	return nil
}
