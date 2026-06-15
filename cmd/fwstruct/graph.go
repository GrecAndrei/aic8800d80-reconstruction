package main

import (
	"flag"
	"fmt"
	"os"
	"path/filepath"
	"strings"

	"aic8800d80/internal/fileio"
)

// runGraph outputs the call graph as graphviz DOT format.
func runGraph(args []string) error {
	fs := flag.NewFlagSet("graph", flag.ContinueOnError)
	var cf commonFlags
	cf.Register(fs)
	var maxDepth int
	fs.IntVar(&maxDepth, "max-depth", 5, "max BFS depth from start")
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
	cf.VPrintf("graph: %d images, max_depth=%d", len(images), maxDepth)
	for _, img := range images {
		var cg struct {
			Funcs map[string]any `json:"funcs"`
			Callers map[string][]string `json:"callers"`
			Callees map[string][]string `json:"callees"`
			TopHubs []struct{ Name string `json:"name"` } `json:"top_hubs"`
			Reachable []string `json:"reachable"`
		}
		if err := readJSON(filepath.Join(cf.Out, img+"_callgraph.json"), &cg); err != nil {
			fmt.Fprintf(os.Stderr, "  %s: %v\n", img, err)
			continue
		}
		// BFS from start, computing depth
		visited := map[string]int{}
		queue := []string{"start"}
		visited["start"] = 0
		for len(queue) > 0 {
			n := queue[0]
			queue = queue[1:]
			depth := visited[n]
			if depth >= maxDepth {
				continue
			}
			for _, c := range cg.Callees[n] {
				if _, ok := visited[c]; ok {
					continue
				}
				visited[c] = depth + 1
				queue = append(queue, c)
			}
		}
		// Output DOT
		var b strings.Builder
		fmt.Fprintf(&b, "digraph %s {\n", sanitizeDot(img))
		fmt.Fprintf(&b, "  rankdir=LR;\n")
		fmt.Fprintf(&b, "  node [shape=box];\n")
		// Edges: only between reachable nodes
		for n, d := range visited {
			for _, c := range cg.Callees[n] {
				if _, ok := visited[c]; !ok {
					continue
				}
				fmt.Fprintf(&b, "  %q -> %q;\n", sanitizeDot(n), sanitizeDot(c))
			}
			_ = d
		}
		b.WriteString("}\n")
		outPath := filepath.Join(cf.Out, img+"_graph.dot")
		if err := fileio.WriteBytes(outPath, []byte(b.String())); err != nil {
			return err
		}
		cf.VPrintf("  %s: %d nodes -> %s", img, len(visited), outPath)
	}
	return nil
}

func sanitizeDot(s string) string {
	return strings.ReplaceAll(s, "\"", "\\\"")
}
