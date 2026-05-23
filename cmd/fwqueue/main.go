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
)

type clusterRecord struct {
	ClusterID      string   `json:"cluster_id"`
	Image          string   `json:"image"`
	NodeCount      int      `json:"node_count"`
	EdgeCount      int      `json:"edge_count"`
	AvgPriority    float64  `json:"avg_priority_score"`
	MaxPriority    float64  `json:"max_priority_score"`
	MessageRelated int      `json:"message_related_count"`
	TopFunctions   []string `json:"top_functions"`
}

type reconRecord struct {
	Image         string   `json:"image"`
	Address       string   `json:"address"`
	Name          string   `json:"name"`
	Role          string   `json:"role"`
	Confidence    float64  `json:"confidence"`
	MessageHits   int      `json:"message_hits"`
	PriorityScore float64  `json:"priority_score"`
	Reasons       []string `json:"reasons"`
	SeenCount     int      `json:"seen_count"`
}

type queueItem struct {
	WorkID          string   `json:"work_id"`
	ClusterID       string   `json:"cluster_id"`
	Image           string   `json:"image"`
	TargetAddress   string   `json:"target_address"`
	TargetFunction  string   `json:"target_function"`
	PriorityClass   string   `json:"priority_class"`
	WorkScore       float64  `json:"work_score"`
	EvidenceSummary []string `json:"evidence_summary"`
	Implementation  []string `json:"implementation_steps"`
}

type queueManifest struct {
	SchemaVersion string `json:"schema_version"`
	GeneratedAt   string `json:"generated_at"`
	ClustersPath  string `json:"clusters_path"`
	WorksetPath   string `json:"workset_path"`
	QueueCount    int    `json:"queue_count"`
	CriticalCount int    `json:"critical_count"`
	HighCount     int    `json:"high_count"`
	MediumCount   int    `json:"medium_count"`
	LowCount      int    `json:"low_count"`
	OutputDir     string `json:"output_dir"`
}

func main() {
	var clustersPath string
	var worksetPath string
	var outDir string
	var perCluster int
	var maxItems int

	flag.StringVar(&clustersPath, "clusters", "extraction_out/reconstruction/mega7/clusters/recon_clusters.jsonl", "Input clusters JSONL")
	flag.StringVar(&worksetPath, "workset", "extraction_out/reconstruction/mega7/recon_workset.jsonl", "Input workset JSONL")
	flag.StringVar(&outDir, "out", "extraction_out/reconstruction/mega7/queue", "Output directory for reconstruction queue")
	flag.IntVar(&perCluster, "per-cluster", 2, "Max queue items per cluster")
	flag.IntVar(&maxItems, "max-items", 4000, "Global queue item cap")
	flag.Parse()

	clustersAbs, _ := filepath.Abs(clustersPath)
	worksetAbs, _ := filepath.Abs(worksetPath)
	outAbs, _ := filepath.Abs(outDir)
	if err := os.MkdirAll(outAbs, 0o755); err != nil {
		fail("mkdir out: %v", err)
	}

	clusterRows, err := readClusters(clustersAbs)
	if err != nil {
		fail("read clusters: %v", err)
	}
	worksetRows, err := readWorkset(worksetAbs)
	if err != nil {
		fail("read workset: %v", err)
	}
	if len(clusterRows) == 0 || len(worksetRows) == 0 {
		fail("empty inputs (clusters=%d workset=%d)", len(clusterRows), len(worksetRows))
	}

	byImage := map[string][]reconRecord{}
	for _, r := range worksetRows {
		byImage[r.Image] = append(byImage[r.Image], r)
	}
	for k := range byImage {
		sort.Slice(byImage[k], func(i, j int) bool {
			if byImage[k][i].PriorityScore == byImage[k][j].PriorityScore {
				return byImage[k][i].Address < byImage[k][j].Address
			}
			return byImage[k][i].PriorityScore > byImage[k][j].PriorityScore
		})
	}

	items := make([]queueItem, 0, min(maxItems, len(clusterRows)*perCluster))
	seen := map[string]struct{}{}
	for _, c := range clusterRows {
		cands := byImage[c.Image]
		if len(cands) == 0 {
			continue
		}
		added := 0
		topSet := clusterTopSet(c.TopFunctions)
		for _, r := range cands {
			if _, ok := topSet[strings.ToLower(strings.TrimSpace(r.Address))]; !ok {
				continue
			}
			k := c.ClusterID + "|" + strings.ToLower(r.Address)
			if _, ok := seen[k]; ok {
				continue
			}
			seen[k] = struct{}{}
			score := scoreWork(c, r)
			items = append(items, queueItem{
				WorkID:         fmt.Sprintf("%s_%s", c.ClusterID, strings.TrimPrefix(strings.ToLower(r.Address), "0x")),
				ClusterID:      c.ClusterID,
				Image:          r.Image,
				TargetAddress:  r.Address,
				TargetFunction: nonEmpty(r.Name, "sub_"+strings.TrimPrefix(strings.ToLower(r.Address), "0x")),
				PriorityClass:  priorityClass(score),
				WorkScore:      round3(score),
				EvidenceSummary: []string{
					fmt.Sprintf("cluster_nodes=%d edges=%d", c.NodeCount, c.EdgeCount),
					fmt.Sprintf("seen_count=%d confidence=%.2f", r.SeenCount, r.Confidence),
					fmt.Sprintf("reasons=%s", strings.Join(r.Reasons, ",")),
				},
				Implementation: []string{
					"Recover function prologue/epilogue and calling convention from IDA/callers",
					"Map MMIO/register interactions and side effects",
					"Lift control flow and message/handler paths into C pseudocode",
					"Annotate unresolved callees and queue follow-up dependencies",
				},
			})
			added++
			if added >= perCluster {
				break
			}
			if len(items) >= maxItems {
				break
			}
		}
		if len(items) >= maxItems {
			break
		}
	}

	sort.Slice(items, func(i, j int) bool {
		if items[i].WorkScore == items[j].WorkScore {
			return items[i].WorkID < items[j].WorkID
		}
		return items[i].WorkScore > items[j].WorkScore
	})

	manifest := queueManifest{
		SchemaVersion: "0.1.0",
		GeneratedAt:   time.Now().UTC().Format(time.RFC3339),
		ClustersPath:  clustersAbs,
		WorksetPath:   worksetAbs,
		QueueCount:    len(items),
		OutputDir:     outAbs,
	}
	for _, it := range items {
		switch it.PriorityClass {
		case "critical":
			manifest.CriticalCount++
		case "high":
			manifest.HighCount++
		case "medium":
			manifest.MediumCount++
		default:
			manifest.LowCount++
		}
	}

	if err := writeJSONL(filepath.Join(outAbs, "recon_queue.jsonl"), items); err != nil {
		fail("write queue: %v", err)
	}
	if err := writeJSON(filepath.Join(outAbs, "queue_manifest.json"), manifest); err != nil {
		fail("write manifest: %v", err)
	}

	fmt.Printf("reconstruction queue generated.\n")
	fmt.Printf("  queue_count: %d\n", manifest.QueueCount)
	fmt.Printf("  critical: %d high: %d medium: %d low: %d\n", manifest.CriticalCount, manifest.HighCount, manifest.MediumCount, manifest.LowCount)
	fmt.Printf("  out_dir: %s\n", outAbs)
}

func readClusters(path string) ([]clusterRecord, error) {
	f, closeFn, err := openMaybeGzip(path)
	if err != nil {
		return nil, err
	}
	defer closeFn()
	s := bufio.NewScanner(f)
	s.Buffer(make([]byte, 4096), 8*1024*1024)
	out := make([]clusterRecord, 0, 32768)
	for s.Scan() {
		line := strings.TrimSpace(s.Text())
		if line == "" {
			continue
		}
		var r clusterRecord
		if err := json.Unmarshal([]byte(line), &r); err == nil {
			out = append(out, r)
		}
	}
	return out, s.Err()
}

func readWorkset(path string) ([]reconRecord, error) {
	f, closeFn, err := openMaybeGzip(path)
	if err != nil {
		return nil, err
	}
	defer closeFn()
	s := bufio.NewScanner(f)
	s.Buffer(make([]byte, 4096), 8*1024*1024)
	out := make([]reconRecord, 0, 65536)
	for s.Scan() {
		line := strings.TrimSpace(s.Text())
		if line == "" {
			continue
		}
		var r reconRecord
		if err := json.Unmarshal([]byte(line), &r); err == nil {
			out = append(out, r)
		}
	}
	return out, s.Err()
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

func scoreWork(c clusterRecord, r reconRecord) float64 {
	score := r.PriorityScore
	score += float64(min(c.NodeCount, 12)) * 0.15
	score += float64(min(c.EdgeCount, 20)) * 0.08
	score += float64(r.MessageHits) * 0.7
	score += float64(r.SeenCount-1) * 0.25
	if hasReason(r.Reasons, "unknown_role") {
		score += 0.35
	}
	return score
}

func priorityClass(score float64) string {
	switch {
	case score >= 7.5:
		return "critical"
	case score >= 5.5:
		return "high"
	case score >= 3.5:
		return "medium"
	default:
		return "low"
	}
}

func clusterTopSet(top []string) map[string]struct{} {
	out := make(map[string]struct{}, len(top))
	for _, t := range top {
		parts := strings.Split(strings.TrimSpace(t), "@")
		if len(parts) != 2 {
			continue
		}
		addr := strings.ToLower(strings.TrimSpace(parts[1]))
		if addr != "" {
			out[addr] = struct{}{}
		}
	}
	return out
}

func nonEmpty(v, fallback string) string {
	if strings.TrimSpace(v) == "" {
		return fallback
	}
	return v
}

func hasReason(reasons []string, want string) bool {
	for _, r := range reasons {
		if r == want {
			return true
		}
	}
	return false
}

func writeJSON(path string, v any) error {
	b, err := json.MarshalIndent(v, "", "  ")
	if err != nil {
		return err
	}
	return os.WriteFile(path, append(b, '\n'), 0o644)
}

func writeJSONL(path string, rows []queueItem) error {
	f, err := os.Create(path)
	if err != nil {
		return err
	}
	defer f.Close()
	bw := bufio.NewWriterSize(f, 1<<20)
	enc := json.NewEncoder(bw)
	for _, r := range rows {
		if err := enc.Encode(r); err != nil {
			return err
		}
	}
	return bw.Flush()
}

func round3(v float64) float64 { return float64(int(v*1000+0.5)) / 1000 }

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
