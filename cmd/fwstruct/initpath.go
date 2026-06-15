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

// callgraphReport is the deserialized shape of <img>_callgraph.json.
type callgraphReport struct {
	Funcs     map[string]any        `json:"funcs"`
	Callers   map[string][]string   `json:"callers"`
	Callees   map[string][]string   `json:"callees"`
	TopHubs   []topHub              `json:"top_hubs"`
	Reachable []string              `json:"reachable"`
	Dead      []string              `json:"dead"`
}

type topHub struct {
	Name     string `json:"name"`
	NCallers int    `json:"n_callers"`
}

// runInitPath extracts the boot path from start() by BFS through the call graph.
//
// We classify each function as init/handler/utility by:
//   - depth from start: 0-2 = init, 3-5 = subsystem, 6+ = utility
//   - callee count: high = utility
//   - caller count: high = utility (called by many)
//   - unique hub with no callers (besides start chain) = utility
//
// Output: <out>/<img>_initpath.json with the init tree.
func runInitPath(args []string) error {
	fs := flag.NewFlagSet("initpath", flag.ContinueOnError)
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
	cf.VPrintf("initpath: %d images", len(images))

	for _, img := range images {
		var cg callgraphReport
		p := filepath.Join(cf.Out, img+"_callgraph.json")
		if err := readJSON(p, &cg); err != nil {
			fmt.Fprintf(os.Stderr, "  %s: %v\n", img, err)
			continue
		}
		// BFS from start, computing depth
		// Note: start() in v19 calls off_1001FC() which is a function pointer
		// off_XXXX references are not real function calls but indirect calls
		// We still follow them but at the same depth (treat as boundary)
		startName := "start"
		visited := map[string]int{} // name -> depth
		queue := []string{startName}
		visited[startName] = 0
		for len(queue) > 0 {
			n := queue[0]
			queue = queue[1:]
			depth := visited[n]
			for _, c := range cg.Callees[n] {
				if _, ok := visited[c]; ok {
					continue
				}
				// off_XXXX are indirect calls (function pointers) - don't increment depth
				nextDepth := depth + 1
				if strings.HasPrefix(c, "off_") || strings.HasPrefix(c, "dword_") {
					nextDepth = depth
				}
				visited[c] = nextDepth
				queue = append(queue, c)
			}
		}
		// Categorize
		type funcCat struct {
			Name     string   `json:"name"`
			Depth    int      `json:"depth"`
			Category string   `json:"category"`
			Callees  []string `json:"callees"`
		}
		cats := map[string][]funcCat{
			"init":     {},
			"subsystem": {},
			"utility":  {},
		}
		// Get all func names from caller map
		allNames := map[string]bool{}
		for n := range cg.Callees {
			allNames[n] = true
		}
		for n := range cg.Callers {
			allNames[n] = true
		}
		for name := range allNames {
			depth, ok := visited[name]
			if !ok {
				depth = -1
			}
			cat := "utility"
			switch {
			case depth < 0:
				cat = "unreachable"
			case depth <= 2:
				cat = "init"
			case depth <= 5:
				cat = "subsystem"
			default:
				cat = "utility"
			}
			cats[cat] = append(cats[cat], funcCat{
				Name: name, Depth: depth, Category: cat, Callees: cg.Callees[name],
			})
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
			Image   string               `json:"image"`
			Start   string               `json:"start"`
			Total   int                  `json:"total"`
			Reachable int                `json:"reachable"`
			InitDepth int                `json:"init_depth_max"`
			ByCategory map[string][]funcCat `json:"by_category"`
		}{
			Image: img, Start: startName,
			Total: len(allNames), Reachable: len(visited),
			InitDepth: 0,
			ByCategory: cats,
		}
		for _, c := range cats["init"] {
			if c.Depth > report.InitDepth {
				report.InitDepth = c.Depth
			}
		}
		outPath := filepath.Join(cf.Out, img+"_initpath.json")
		if err := fileio.WriteJSON(outPath, report); err != nil {
			return err
		}
		cf.VPrintf("  %s: %d funcs, %d reachable, init_depth=%d", img, report.Total, report.Reachable, report.InitDepth)
	}
	return nil
}

// silence unused
var _ = os.Stdin
var _ = strings.HasPrefix
var _ = json.Marshal
var _ = decompile.Func{}
