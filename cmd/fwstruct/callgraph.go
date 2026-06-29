package main

import (
	"flag"
	"fmt"
	"os"
	"path/filepath"
	"sort"
	"strings"

	"aic8800d80/internal/decompile"
	"aic8800d80/internal/fileio"
)

// runCallgraph builds a per-image call graph and finds top hubs, dead code,
// and entry points (called from start()).
func runCallgraph(args []string) error {
	fs := flag.NewFlagSet("callgraph", flag.ContinueOnError)
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
	cf.VPrintf("callgraph: %d images", len(images))

	type hub struct {
		Name     string `json:"name"`
		NCallers int    `json:"n_callers"`
	}
	type imageGraph struct {
		Funcs     map[string]any `json:"funcs"`  // name -> {}
		Callers   map[string][]string `json:"callers"`
		Callees   map[string][]string `json:"callees"`
		TopHubs   []hub            `json:"top_hubs"`
		Reachable []string         `json:"reachable"`
		Dead      []string         `json:"dead"`
	}

	for _, img := range images {
		funcs, err := loadFuncs(cf.Out, img)
		if err != nil {
			fmt.Fprintf(os.Stderr, "  %s: %v\n", img, err)
			continue
		}
		// Build name -> func map
		byName := map[string]*decompile.Func{}
		for _, fn := range funcs {
			byName[fn.Name] = fn
		}
		// callers/callees
		callers := map[string]map[string]struct{}{}
		callees := map[string]map[string]struct{}{}
		for _, fn := range funcs {
			callees[fn.Name] = map[string]struct{}{}
			for _, c := range fn.Callees {
				if _, ok := byName[c]; ok || strings.HasPrefix(c, "off_") || strings.HasPrefix(c, "dword_") {
					callees[fn.Name][c] = struct{}{}
					if _, ok := callers[c]; !ok {
						callers[c] = map[string]struct{}{}
					}
					callers[c][fn.Name] = struct{}{}
				}
			}
		}
		// Hubs
		type hubE struct {
			name     string
			nCallers int
		}
		var hubs []hubE
		for name, cs := range callers {
			hubs = append(hubs, hubE{name, len(cs)})
		}
		sort.Slice(hubs, func(i, j int) bool {
			if hubs[i].nCallers != hubs[j].nCallers {
				return hubs[i].nCallers > hubs[j].nCallers
			}
			return hubs[i].name < hubs[j].name
		})
		topHubs := make([]hub, 0, 30)
		for i, h := range hubs {
			if i >= 30 {
				break
			}
			topHubs = append(topHubs, hub{Name: h.name, NCallers: h.nCallers})
		}
		// Reachable from start
		reachable := bfsReachable("start", callees, byName)
		dead := []string{}
		for _, fn := range funcs {
			if _, ok := reachable[fn.Name]; !ok {
				dead = append(dead, fn.Name)
			}
		}
		// Serialize
		gs := imageGraph{
			Funcs:   map[string]any{"count": len(funcs)},
			Callers: stringifyKeys(callers),
			Callees: stringifyKeys(callees),
			TopHubs: topHubs,
		}
		gs.Reachable = sortedKeys(reachable)
		gs.Dead = dead
		outPath := filepath.Join(cf.Out, img+"_callgraph.json")
		if err := fileio.WriteJSON(outPath, gs); err != nil {
			return err
		}
		cf.VPrintf("  %s: %d funcs, %d hubs, %d reachable, %d dead", img, len(funcs), len(hubs), len(reachable), len(dead))
	}
	return nil
}

func stringifyKeys(m map[string]map[string]struct{}) map[string][]string {
	out := make(map[string][]string, len(m))
	for k, vs := range m {
		out[k] = sortedKeys(vs)
	}
	return out
}

func sortedKeys(m map[string]struct{}) []string {
	out := make([]string, 0, len(m))
	for k := range m {
		out = append(out, k)
	}
	sort.Strings(out)
	return out
}

func bfsReachable(start string, callees map[string]map[string]struct{}, byName map[string]*decompile.Func) map[string]struct{} {
	visited := map[string]struct{}{}
	if _, ok := byName[start]; !ok {
		// Try to find start function
		for name := range byName {
			if strings.HasPrefix(name, "start") {
				start = name
				break
			}
		}
	}
	queue := []string{start}
	for len(queue) > 0 {
		n := queue[0]
		queue = queue[1:]
		if _, ok := visited[n]; ok {
			continue
		}
		visited[n] = struct{}{}
		for c := range callees[n] {
			if _, ok := visited[c]; ok {
				continue
			}
			queue = append(queue, c)
		}
	}
	return visited
}
