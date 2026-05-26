package main

import (
	"bufio"
	"compress/gzip"
	"encoding/json"
	"flag"
	"fmt"
	"io"
	"os"
	"path/filepath"
	"sort"
	"strings"
	"time"

	"aic8800d80/internal/fileio"
)

type reconRecord struct {
	SchemaVersion string   `json:"schema_version,omitempty"`
	Image         string   `json:"image"`
	Address       string   `json:"address"`
	Name          string   `json:"name"`
	Role          string   `json:"role"`
	Confidence    float64  `json:"confidence"`
	OutDegree     int      `json:"out_degree"`
	InDegree      int      `json:"in_degree"`
	MessageHits   int      `json:"message_hits"`
	PriorityScore float64  `json:"priority_score"`
	Reasons       []string `json:"reasons"`
	SeenCount     int      `json:"seen_count"`
}

type callEdge struct {
	SchemaVersion string  `json:"schema_version,omitempty"`
	Image         string  `json:"image"`
	SourceAddr    string  `json:"source_addr"`
	TargetAddr    string  `json:"target_addr"`
	SourceName    string  `json:"source_name"`
	TargetName    string  `json:"target_name"`
	Confidence    float64 `json:"confidence"`
}

type clusterSummary struct {
	SchemaVersion    string   `json:"schema_version"`
	ClusterID        string   `json:"cluster_id"`
	Image            string   `json:"image"`
	NodeCount        int      `json:"node_count"`
	EdgeCount        int      `json:"edge_count"`
	AvgPriorityScore float64  `json:"avg_priority_score"`
	MaxPriorityScore float64  `json:"max_priority_score"`
	MessageRelated   int      `json:"message_related_count"`
	TopFunctions     []string `json:"top_functions"`
}

type clusterManifest struct {
	SchemaVersion   string `json:"schema_version"`
	GeneratedAt     string `json:"generated_at"`
	WorksetPath     string `json:"workset_path"`
	CallEdgesPath   string `json:"call_edges_path"`
	NodesInWorkset  int    `json:"nodes_in_workset"`
	EdgesConsidered int    `json:"edges_considered"`
	EdgesMatched    int    `json:"edges_matched"`
	ClusterCount    int    `json:"cluster_count"`
	LargestCluster  int    `json:"largest_cluster"`
	OutputDir       string `json:"output_dir"`
}

type dsu struct {
	parent []int
	rank   []byte
}

func newDSU(n int) *dsu {
	p := make([]int, n)
	r := make([]byte, n)
	for i := range p {
		p[i] = i
	}
	return &dsu{parent: p, rank: r}
}
func (d *dsu) find(x int) int {
	for d.parent[x] != x {
		d.parent[x] = d.parent[d.parent[x]]
		x = d.parent[x]
	}
	return x
}
func (d *dsu) union(a, b int) {
	ra := d.find(a)
	rb := d.find(b)
	if ra == rb {
		return
	}
	if d.rank[ra] < d.rank[rb] {
		d.parent[ra] = rb
		return
	}
	if d.rank[ra] > d.rank[rb] {
		d.parent[rb] = ra
		return
	}
	d.parent[rb] = ra
	d.rank[ra]++
}

func main() {
	var worksetPath string
	var callEdgesPath string
	var outDir string
	var minEdgeConfidence float64
	var topPerCluster int

	flag.StringVar(&worksetPath, "workset", "extraction_out/reconstruction/mega7/recon_workset.jsonl", "Reconstruction workset JSONL")
	flag.StringVar(&callEdgesPath, "call-edges", "extraction_out/call_edges.jsonl", "Call edges JSONL")
	flag.StringVar(&outDir, "out", "extraction_out/reconstruction/mega7/clusters", "Output directory for cluster artifacts")
	flag.Float64Var(&minEdgeConfidence, "min-edge-confidence", 0.70, "Minimum call edge confidence")
	flag.IntVar(&topPerCluster, "top-per-cluster", 12, "Top functions to emit per cluster")
	flag.Parse()

	worksetAbs, err := filepath.Abs(worksetPath)
	if err != nil {
		fail("resolve workset: %v", err)
	}
	callAbs, err := filepath.Abs(callEdgesPath)
	if err != nil {
		fail("resolve call edges: %v", err)
	}
	outAbs, err := filepath.Abs(outDir)
	if err != nil {
		fail("resolve out: %v", err)
	}
	if err := os.MkdirAll(outAbs, 0o755); err != nil {
		fail("mkdir out: %v", err)
	}

	nodes, order, idx, err := readWorkset(worksetAbs)
	if err != nil {
		fail("read workset: %v", err)
	}
	if len(order) == 0 {
		fail("empty workset: %s", worksetAbs)
	}
	d := newDSU(len(order))

	edgesConsidered := 0
	edgesMatched := 0
	edgeCountByRoot := map[int]int{}

	f, closeFn, err := openMaybeGzip(callAbs)
	if err != nil {
		fail("open call edges: %v", err)
	}
	defer closeFn()
	sc := bufio.NewScanner(f)
	sc.Buffer(make([]byte, 4096), 8*1024*1024)
	for sc.Scan() {
		line := strings.TrimSpace(sc.Text())
		if line == "" {
			continue
		}
		var e callEdge
		if err := json.Unmarshal([]byte(line), &e); err != nil {
			continue
		}
		if strings.TrimSpace(e.SchemaVersion) != "" && e.SchemaVersion != "0.1.0" {
			fail("call edges schema mismatch: got %s, want 0.1.0", e.SchemaVersion)
		}
		edgesConsidered++
		if e.Confidence < minEdgeConfidence {
			continue
		}
		srcKey := key(e.Image, e.SourceAddr)
		tgtKey := key(e.Image, e.TargetAddr)
		si, sok := idx[srcKey]
		ti, tok := idx[tgtKey]
		if !sok || !tok {
			continue
		}
		d.union(si, ti)
		edgesMatched++
	}
	if err := sc.Err(); err != nil {
		fail("scan call edges: %v", err)
	}

	memberByRoot := map[int][]reconRecord{}
	for i, k := range order {
		root := d.find(i)
		memberByRoot[root] = append(memberByRoot[root], nodes[k])
	}

	// Recompute edge counts on final root assignment for stability.
	f2, closeFn2, err := openMaybeGzip(callAbs)
	if err != nil {
		fail("open call edges for recount: %v", err)
	}
	defer closeFn2()
	sc2 := bufio.NewScanner(f2)
	sc2.Buffer(make([]byte, 4096), 8*1024*1024)
	for sc2.Scan() {
		line := strings.TrimSpace(sc2.Text())
		if line == "" {
			continue
		}
		var e callEdge
		if err := json.Unmarshal([]byte(line), &e); err != nil {
			continue
		}
		if strings.TrimSpace(e.SchemaVersion) != "" && e.SchemaVersion != "0.1.0" {
			fail("call edges schema mismatch: got %s, want 0.1.0", e.SchemaVersion)
		}
		if e.Confidence < minEdgeConfidence {
			continue
		}
		si, sok := idx[key(e.Image, e.SourceAddr)]
		ti, tok := idx[key(e.Image, e.TargetAddr)]
		if !sok || !tok {
			continue
		}
		rs := d.find(si)
		rt := d.find(ti)
		if rs == rt {
			edgeCountByRoot[rs]++
		}
	}

	clusters := make([]clusterSummary, 0, len(memberByRoot))
	largest := 0
	clusterIdx := 0
	for root, members := range memberByRoot {
		sort.Slice(members, func(i, j int) bool {
			if members[i].PriorityScore == members[j].PriorityScore {
				return members[i].Address < members[j].Address
			}
			return members[i].PriorityScore > members[j].PriorityScore
		})
		if len(members) > largest {
			largest = len(members)
		}
		if len(members) == 0 {
			continue
		}
		clusterIdx++
		sum := 0.0
		maxP := members[0].PriorityScore
		msgCount := 0
		top := make([]string, 0, min(topPerCluster, len(members)))
		for i, m := range members {
			sum += m.PriorityScore
			if m.PriorityScore > maxP {
				maxP = m.PriorityScore
			}
			if m.MessageHits > 0 || hasReason(m.Reasons, "message_path") {
				msgCount++
			}
			if i < topPerCluster {
				name := strings.TrimSpace(m.Name)
				if name == "" {
					name = "sub_" + strings.TrimPrefix(strings.ToLower(m.Address), "0x")
				}
				top = append(top, fmt.Sprintf("%s@%s", name, m.Address))
			}
		}
		clusters = append(clusters, clusterSummary{
			SchemaVersion:    "0.1.0",
			ClusterID:        fmt.Sprintf("cluster_%04d", clusterIdx),
			Image:            members[0].Image,
			NodeCount:        len(members),
			EdgeCount:        edgeCountByRoot[root],
			AvgPriorityScore: round3(sum / float64(len(members))),
			MaxPriorityScore: round3(maxP),
			MessageRelated:   msgCount,
			TopFunctions:     top,
		})
	}

	sort.Slice(clusters, func(i, j int) bool {
		if clusters[i].NodeCount == clusters[j].NodeCount {
			return clusters[i].AvgPriorityScore > clusters[j].AvgPriorityScore
		}
		return clusters[i].NodeCount > clusters[j].NodeCount
	})
	for i := range clusters {
		clusters[i].ClusterID = fmt.Sprintf("cluster_%04d", i+1)
	}

	if err := fileio.WriteJSONL(filepath.Join(outAbs, "recon_clusters.jsonl"), clusters); err != nil {
		fail("write clusters: %v", err)
	}
	manifest := clusterManifest{
		SchemaVersion:   "0.1.0",
		GeneratedAt:     time.Now().UTC().Format(time.RFC3339),
		WorksetPath:     worksetAbs,
		CallEdgesPath:   callAbs,
		NodesInWorkset:  len(order),
		EdgesConsidered: edgesConsidered,
		EdgesMatched:    edgesMatched,
		ClusterCount:    len(clusters),
		LargestCluster:  largest,
		OutputDir:       outAbs,
	}
	if err := fileio.WriteJSON(filepath.Join(outAbs, "cluster_manifest.json"), manifest); err != nil {
		fail("write manifest: %v", err)
	}

	fmt.Printf("cluster reconstruction complete.\n")
	fmt.Printf("  workset_nodes: %d\n", len(order))
	fmt.Printf("  edges_considered: %d\n", edgesConsidered)
	fmt.Printf("  edges_matched: %d\n", edgesMatched)
	fmt.Printf("  clusters: %d\n", len(clusters))
	fmt.Printf("  largest_cluster: %d\n", largest)
	fmt.Printf("  out_dir: %s\n", outAbs)
}

func readWorkset(path string) (map[string]reconRecord, []string, map[string]int, error) {
	f, closeFn, err := openMaybeGzip(path)
	if err != nil {
		return nil, nil, nil, err
	}
	defer closeFn()
	nodes := make(map[string]reconRecord, 131072)
	order := make([]string, 0, 131072)
	idx := make(map[string]int, 131072)
	sc := bufio.NewScanner(f)
	sc.Buffer(make([]byte, 4096), 8*1024*1024)
	for sc.Scan() {
		line := strings.TrimSpace(sc.Text())
		if line == "" {
			continue
		}
		var r reconRecord
		if err := json.Unmarshal([]byte(line), &r); err != nil {
			continue
		}
		if strings.TrimSpace(r.SchemaVersion) != "" && r.SchemaVersion != "0.1.0" {
			return nil, nil, nil, fmt.Errorf("workset schema mismatch: got %s, want 0.1.0", r.SchemaVersion)
		}
		k := key(r.Image, r.Address)
		if _, exists := nodes[k]; exists {
			continue
		}
		nodes[k] = r
		idx[k] = len(order)
		order = append(order, k)
	}
	return nodes, order, idx, sc.Err()
}

func openMaybeGzip(path string) (io.Reader, func() error, error) {
	if f, err := os.Open(path); err == nil {
		return f, f.Close, nil
	}
	if f, err := os.Open(path + ".gz"); err == nil {
		gz, zerr := gzip.NewReader(f)
		if zerr != nil {
			_ = f.Close()
			return nil, nil, zerr
		}
		return gz, func() error {
			_ = gz.Close()
			return f.Close()
		}, nil
	}
	return nil, nil, fmt.Errorf("missing input: %s(.gz)", path)
}

func key(img, addr string) string {
	return strings.TrimSpace(img) + "|" + strings.ToLower(strings.TrimSpace(addr))
}

func hasReason(reasons []string, want string) bool {
	for _, r := range reasons {
		if r == want {
			return true
		}
	}
	return false
}

func round3(v float64) float64 {
	return float64(int(v*1000+0.5)) / 1000
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func fail(format string, args ...any) {
	fmt.Fprintf(os.Stderr, format+"\n", args...)
	os.Exit(1)
}
