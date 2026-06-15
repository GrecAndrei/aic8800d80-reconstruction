package main

import (
	"flag"
	"fmt"
	"os"
	"path/filepath"
	"sort"
	"strings"

	"aic8800d80/internal/decompile"
	_ "aic8800d80/internal/fileio"
)

// clusterReportForAnn is the deserialized shape of <img>_clusters.json.
type clusterReportForAnn struct {
	Image       string                       `json:"image"`
	TotalFuncs  int                          `json:"total_funcs"`
	Clustered   int                          `json:"clustered"`
	ClusterCount int                         `json:"cluster_count"`
	Clusters    []*structsClusterLite        `json:"clusters"`
	FuncMap     map[string]int               `json:"func_map"`
}

type structsClusterLite struct {
	ID         int          `json:"id"`
	GroupID    int          `json:"group_id"`
	Image      string       `json:"image"`
	Name       string       `json:"name,omitempty"`
	PrimaryArg string       `json:"primary_arg"`
	Fingerprint []accessKeyLite `json:"fingerprint"`
	FPHash     string       `json:"fp_hash"`
	Funcs      []uint32     `json:"funcs"`
}

type accessKeyLite struct {
	Base   string `json:"base"`
	Offset int    `json:"offset"`
	Size   int    `json:"size"`
}

// runAnnotate emits annotated C files where each function gets a header
// comment with the cluster it belongs to (if any) and the named struct.
func runAnnotate(args []string) error {
	fs := flag.NewFlagSet("annotate", flag.ContinueOnError)
	var cf commonFlags
	cf.Register(fs)
	var namedPath string
	fs.StringVar(&namedPath, "named", "", "<img>_named.json from 'names' subcommand (default: <out>/<img>_named.json)")
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
	cf.VPrintf("annotate: %d images", len(images))

	totalAnnotated := 0
	totalWithStruct := 0
	for _, img := range images {
		// Load cluster map
		var crep clusterReportForAnn
		if err := readJSON(filepath.Join(cf.Out, img+"_clusters.json"), &crep); err != nil {
			fmt.Fprintf(os.Stderr, "  %s: %v\n", img, err)
			continue
		}
		// Group ID -> cluster info
		groups := map[int]*structsClusterLite{}
		for _, c := range crep.Clusters {
			groups[c.GroupID] = c
		}
		// Load LLM named clusters (if any)
		named := map[int]string{}
		if namedPath == "" {
			namedPath = filepath.Join(cf.Out, img+"_named.json")
		}
		var namedList []map[string]any
		if err := readJSON(namedPath, &namedList); err == nil {
			for _, n := range namedList {
				if gid, ok := n["group"].(float64); ok {
					if name, ok := n["struct_name"].(string); ok {
						named[int(gid)] = name
					}
				}
			}
		}
		// Read each decompiled C file, add header
		imgDir := filepath.Join(cf.Decompiled, img)
		outDir := filepath.Join(cf.Out, "annotated", img)
		if err := os.MkdirAll(outDir, 0o755); err != nil {
			return err
		}
		entries, err := os.ReadDir(imgDir)
		if err != nil {
			return err
		}
		nAnn := 0
		nWith := 0
		for _, e := range entries {
			if e.IsDir() || !strings.HasSuffix(e.Name(), ".c") {
				continue
			}
			inPath := filepath.Join(imgDir, e.Name())
			outPath := filepath.Join(outDir, e.Name())
			ann, withStruct := annotateOne(inPath, outPath, groups, named)
			if ann {
				nAnn++
			}
			if withStruct {
				nWith++
			}
		}
		totalAnnotated += nAnn
		totalWithStruct += nWith
		cf.VPrintf("  %s: %d annotated, %d with named struct -> %s", img, nAnn, nWith, outDir)
	}
	fmt.Printf("annotate: %d total annotated, %d with named struct\n", totalAnnotated, totalWithStruct)
	return nil
}

func annotateOne(inPath, outPath string, groups map[int]*structsClusterLite, named map[int]string) (bool, bool) {
	// Parse addr from filename
	base := filepath.Base(inPath)
	// Format: <addr_hex>_<name>.c
	idx := strings.Index(base, "_")
	if idx < 0 {
		return false, false
	}
	addrHex := base[:idx]
	addr := parseHex(addrHex)
	_ = addr

	// Look up cluster for this func
	var gid int
	found := false
	for g, c := range groups {
		for _, faddr := range c.Funcs {
			if faddr == addr {
				gid = g
				found = true
				break
			}
		}
		if found {
			break
		}
	}

	body, err := os.ReadFile(inPath)
	if err != nil {
		return false, false
	}

	annotated := false
	withStruct := false
	var header strings.Builder
	if found {
		annotated = true
		c := groups[gid]
		name := c.Name
		if n, ok := named[gid]; ok && n != "" {
			name = n
			withStruct = true
		}
		fmt.Fprintf(&header, "// v25 annotated: %s @ 0x%x\n", strings.TrimSuffix(base, ".c"), addr)
		fmt.Fprintf(&header, "// Cluster %d, primary_arg=%s, n_funcs=%d\n", gid, c.PrimaryArg, len(c.Funcs))
		if withStruct {
			fmt.Fprintf(&header, "// Struct: %s\n", name)
			// Field list
			parts := []string{}
			for _, k := range c.Fingerprint {
				parts = append(parts, fmt.Sprintf("0x%x:%d", k.Offset, k.Size))
			}
			sort.Strings(parts)
			fmt.Fprintf(&header, "// Fields: %s\n", strings.Join(parts, ", "))
		}
		fmt.Fprintf(&header, "// Original: %s\n", base)
		header.WriteString("//\n")
	}

	out, err := os.Create(outPath)
	if err != nil {
		return false, false
	}
	defer out.Close()
	if annotated {
		out.WriteString(header.String())
	}
	out.Write(body)
	return annotated, withStruct
}

func parseHex(s string) uint32 {
	var v uint32
	for _, c := range s {
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
		v = v*16 + d
	}
	return v
}

// silence unused
var _ = decompile.Func{}
