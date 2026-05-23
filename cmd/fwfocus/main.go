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

type queueItem struct {
	WorkID         string  `json:"work_id"`
	ClusterID      string  `json:"cluster_id"`
	Image          string  `json:"image"`
	TargetAddress  string  `json:"target_address"`
	TargetFunction string  `json:"target_function"`
	PriorityClass  string  `json:"priority_class"`
	WorkScore      float64 `json:"work_score"`
}

type reconRecord struct {
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
	Image      string  `json:"image"`
	SourceAddr string  `json:"source_addr"`
	SourceName string  `json:"source_name"`
	TargetAddr string  `json:"target_addr"`
	TargetName string  `json:"target_name"`
	Confidence float64 `json:"confidence"`
}

type focusBundle struct {
	WorkID          string      `json:"work_id"`
	ClusterID       string      `json:"cluster_id"`
	Image           string      `json:"image"`
	TargetAddress   string      `json:"target_address"`
	TargetFunction  string      `json:"target_function"`
	PriorityClass   string      `json:"priority_class"`
	WorkScore       float64     `json:"work_score"`
	Function        reconRecord `json:"function"`
	IncomingCalls   []callEdge  `json:"incoming_calls"`
	OutgoingCalls   []callEdge  `json:"outgoing_calls"`
	Implementation  []string    `json:"implementation_notes"`
	GeneratedPseudo string      `json:"generated_pseudocode_hint"`
	GeneratedAt     string      `json:"generated_at"`
}

type focusManifest struct {
	SchemaVersion string `json:"schema_version"`
	GeneratedAt   string `json:"generated_at"`
	QueuePath     string `json:"queue_path"`
	WorksetPath   string `json:"workset_path"`
	CallEdgesPath string `json:"call_edges_path"`
	BundleCount   int    `json:"bundle_count"`
	CriticalCount int    `json:"critical_count"`
	HighCount     int    `json:"high_count"`
	OutputDir     string `json:"output_dir"`
}

func main() {
	var queuePath string
	var worksetPath string
	var callEdgesPath string
	var outDir string
	var maxBundles int
	var minCallConfidence float64
	var includeMedium bool
	var seedPerImage int

	flag.StringVar(&queuePath, "queue", "extraction_out/reconstruction/mega7/queue/recon_queue.jsonl", "Queue JSONL path")
	flag.StringVar(&worksetPath, "workset", "extraction_out/reconstruction/mega7/recon_workset.jsonl", "Workset JSONL path")
	flag.StringVar(&callEdgesPath, "call-edges", "extraction_out/call_edges.jsonl", "Call edges JSONL path")
	flag.StringVar(&outDir, "out", "extraction_out/reconstruction/mega7/focus", "Output directory for focused reconstruction bundles")
	flag.IntVar(&maxBundles, "max-bundles", 256, "Maximum critical/high bundles to emit")
	flag.Float64Var(&minCallConfidence, "min-call-confidence", 0.7, "Minimum call edge confidence included in bundles")
	flag.BoolVar(&includeMedium, "include-medium", true, "Allow medium-priority rows after critical/high selection")
	flag.IntVar(&seedPerImage, "seed-per-image", 8, "Minimum selected rows per image when include-medium is enabled")
	flag.Parse()

	queueAbs, _ := filepath.Abs(queuePath)
	worksetAbs, _ := filepath.Abs(worksetPath)
	callAbs, _ := filepath.Abs(callEdgesPath)
	outAbs, _ := filepath.Abs(outDir)
	if err := os.MkdirAll(outAbs, 0o755); err != nil {
		fail("mkdir out: %v", err)
	}

	queueRowsAll, err := readQueueAll(queueAbs)
	if err != nil {
		fail("read queue: %v", err)
	}
	queueRows := selectQueueRows(queueRowsAll, maxBundles, includeMedium, seedPerImage)
	if len(queueRows) == 0 {
		fail("no selected queue rows found")
	}

	worksetIndex, err := readWorksetIndex(worksetAbs)
	if err != nil {
		fail("read workset: %v", err)
	}
	inEdges, outEdges, err := readCallAdj(callAbs, minCallConfidence)
	if err != nil {
		fail("read call edges: %v", err)
	}

	manifest := focusManifest{
		SchemaVersion: "0.1.0",
		GeneratedAt:   time.Now().UTC().Format(time.RFC3339),
		QueuePath:     queueAbs,
		WorksetPath:   worksetAbs,
		CallEdgesPath: callAbs,
		OutputDir:     outAbs,
	}

	indexRows := make([]map[string]any, 0, len(queueRows))
	for _, q := range queueRows {
		k := addrKey(q.Image, q.TargetAddress)
		rec, ok := worksetIndex[k]
		if !ok {
			continue
		}
		b := focusBundle{
			WorkID:         q.WorkID,
			ClusterID:      q.ClusterID,
			Image:          q.Image,
			TargetAddress:  q.TargetAddress,
			TargetFunction: q.TargetFunction,
			PriorityClass:  q.PriorityClass,
			WorkScore:      q.WorkScore,
			Function:       rec,
			IncomingCalls:  inEdges[k],
			OutgoingCalls:  outEdges[k],
			Implementation: buildNotes(q, rec),
			GeneratedPseudo: fmt.Sprintf(
				"void %s(void) { /* recovered from mined evidence; TODO: resolve %d outgoing, %d incoming */ }",
				sanitizeName(nonEmpty(rec.Name, "sub_"+strings.TrimPrefix(strings.ToLower(rec.Address), "0x"))),
				len(outEdges[k]), len(inEdges[k]),
			),
			GeneratedAt: time.Now().UTC().Format(time.RFC3339),
		}
		if q.PriorityClass == "critical" {
			manifest.CriticalCount++
		} else {
			manifest.HighCount++
		}
		manifest.BundleCount++

		base := sanitizeName(q.WorkID)
		if err := writeJSON(filepath.Join(outAbs, base+".bundle.json"), b); err != nil {
			fail("write bundle json %s: %v", base, err)
		}
		if err := writeCStub(filepath.Join(outAbs, base+".focus.c"), b); err != nil {
			fail("write bundle c %s: %v", base, err)
		}
		indexRows = append(indexRows, map[string]any{
			"work_id":          b.WorkID,
			"cluster_id":       b.ClusterID,
			"image":            b.Image,
			"target_address":   b.TargetAddress,
			"target_function":  b.TargetFunction,
			"priority_class":   b.PriorityClass,
			"work_score":       b.WorkScore,
			"incoming_calls":   len(b.IncomingCalls),
			"outgoing_calls":   len(b.OutgoingCalls),
			"bundle_json_path": filepath.Join(outAbs, base+".bundle.json"),
			"bundle_c_path":    filepath.Join(outAbs, base+".focus.c"),
		})
	}

	sort.Slice(indexRows, func(i, j int) bool {
		ai := flt(indexRows[i]["work_score"])
		aj := flt(indexRows[j]["work_score"])
		return ai > aj
	})

	if err := writeJSON(filepath.Join(outAbs, "focus_manifest.json"), manifest); err != nil {
		fail("write manifest: %v", err)
	}
	if err := writeJSON(filepath.Join(outAbs, "focus_index.json"), indexRows); err != nil {
		fail("write index: %v", err)
	}

	fmt.Printf("focused reconstruction generated.\n")
	fmt.Printf("  bundle_count: %d\n", manifest.BundleCount)
	fmt.Printf("  critical_count: %d\n", manifest.CriticalCount)
	fmt.Printf("  high_count: %d\n", manifest.HighCount)
	fmt.Printf("  out_dir: %s\n", outAbs)
}

func readQueueAll(path string) ([]queueItem, error) {
	f, closeFn, err := openMaybeGzip(path)
	if err != nil {
		return nil, err
	}
	defer closeFn()
	s := bufio.NewScanner(f)
	s.Buffer(make([]byte, 4096), 8*1024*1024)
	out := make([]queueItem, 0, 4096)
	for s.Scan() {
		line := strings.TrimSpace(s.Text())
		if line == "" {
			continue
		}
		var q queueItem
		if err := json.Unmarshal([]byte(line), &q); err != nil {
			continue
		}
		out = append(out, q)
	}
	return out, s.Err()
}

func selectQueueRows(all []queueItem, maxBundles int, includeMedium bool, seedPerImage int) []queueItem {
	if maxBundles <= 0 {
		maxBundles = len(all)
	}
	selected := make([]queueItem, 0, maxBundles)
	seen := make(map[string]struct{}, maxBundles)
	byImage := map[string]int{}

	addIf := func(q queueItem) bool {
		if len(selected) >= maxBundles {
			return false
		}
		if _, ok := seen[q.WorkID]; ok {
			return false
		}
		seen[q.WorkID] = struct{}{}
		selected = append(selected, q)
		byImage[q.Image]++
		return true
	}

	for _, q := range all {
		if q.PriorityClass == "critical" || q.PriorityClass == "high" {
			if !addIf(q) {
				break
			}
		}
	}

	if !includeMedium || len(selected) >= maxBundles {
		return selected
	}

	if seedPerImage < 0 {
		seedPerImage = 0
	}
	images := map[string]struct{}{}
	for _, q := range all {
		images[q.Image] = struct{}{}
	}

	for img := range images {
		need := seedPerImage - byImage[img]
		if need <= 0 {
			continue
		}
		for _, q := range all {
			if q.Image != img || q.PriorityClass != "medium" {
				continue
			}
			if addIf(q) {
				need--
			}
			if need <= 0 || len(selected) >= maxBundles {
				break
			}
		}
		if len(selected) >= maxBundles {
			break
		}
	}

	for _, q := range all {
		if len(selected) >= maxBundles {
			break
		}
		if q.PriorityClass == "medium" {
			addIf(q)
		}
	}
	return selected
}

func readWorksetIndex(path string) (map[string]reconRecord, error) {
	f, closeFn, err := openMaybeGzip(path)
	if err != nil {
		return nil, err
	}
	defer closeFn()
	s := bufio.NewScanner(f)
	s.Buffer(make([]byte, 4096), 8*1024*1024)
	out := make(map[string]reconRecord, 131072)
	for s.Scan() {
		line := strings.TrimSpace(s.Text())
		if line == "" {
			continue
		}
		var r reconRecord
		if err := json.Unmarshal([]byte(line), &r); err != nil {
			continue
		}
		out[addrKey(r.Image, r.Address)] = r
	}
	return out, s.Err()
}

func readCallAdj(path string, minConf float64) (map[string][]callEdge, map[string][]callEdge, error) {
	f, closeFn, err := openMaybeGzip(path)
	if err != nil {
		return nil, nil, err
	}
	defer closeFn()
	in := make(map[string][]callEdge, 4096)
	out := make(map[string][]callEdge, 4096)
	s := bufio.NewScanner(f)
	s.Buffer(make([]byte, 4096), 8*1024*1024)
	for s.Scan() {
		line := strings.TrimSpace(s.Text())
		if line == "" {
			continue
		}
		var e callEdge
		if err := json.Unmarshal([]byte(line), &e); err != nil {
			continue
		}
		if e.Confidence < minConf {
			continue
		}
		sk := addrKey(e.Image, e.SourceAddr)
		tk := addrKey(e.Image, e.TargetAddr)
		out[sk] = append(out[sk], e)
		in[tk] = append(in[tk], e)
	}
	return in, out, s.Err()
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

func buildNotes(q queueItem, r reconRecord) []string {
	notes := []string{
		fmt.Sprintf("priority=%s score=%.3f seen=%d confidence=%.2f", q.PriorityClass, q.WorkScore, r.SeenCount, r.Confidence),
		fmt.Sprintf("role=%s reasons=%s", r.Role, strings.Join(r.Reasons, ",")),
	}
	if r.MessageHits > 0 {
		notes = append(notes, "message-path behavior likely present; inspect dispatch/parsing branches first")
	}
	if r.OutDegree > 0 {
		notes = append(notes, fmt.Sprintf("high fanout observed (%d outgoing); reconstruct side effects before leaf calls", r.OutDegree))
	}
	if r.InDegree > 0 {
		notes = append(notes, fmt.Sprintf("non-trivial fanin (%d incoming); recover call contract and parameter semantics", r.InDegree))
	}
	return notes
}

func writeCStub(path string, b focusBundle) error {
	var sb strings.Builder
	sb.WriteString("/* Auto-generated focused reconstruction bundle */\n")
	sb.WriteString(fmt.Sprintf("/* work_id=%s cluster=%s image=%s addr=%s class=%s score=%.3f */\n\n",
		b.WorkID, b.ClusterID, b.Image, b.TargetAddress, b.PriorityClass, b.WorkScore))
	sb.WriteString("#include <stdint.h>\n\n")
	sb.WriteString(fmt.Sprintf("void %s(void) {\n", sanitizeName(nonEmpty(b.TargetFunction, "sub_"+strings.TrimPrefix(strings.ToLower(b.TargetAddress), "0x")))))
	sb.WriteString("  // TODO: recover exact ABI and argument semantics.\n")
	sb.WriteString(fmt.Sprintf("  // mined evidence: out_degree=%d in_degree=%d message_hits=%d seen_count=%d\n", b.Function.OutDegree, b.Function.InDegree, b.Function.MessageHits, b.Function.SeenCount))
	sb.WriteString(fmt.Sprintf("  // call evidence: incoming=%d outgoing=%d (confidence-filtered)\n", len(b.IncomingCalls), len(b.OutgoingCalls)))
	sb.WriteString("  // TODO: replace placeholder with lifted control/data flow.\n")
	sb.WriteString("}\n")
	return os.WriteFile(path, []byte(sb.String()), 0o644)
}

func addrKey(img, addr string) string {
	return strings.TrimSpace(img) + "|" + strings.ToLower(strings.TrimSpace(addr))
}

func sanitizeName(s string) string {
	s = strings.TrimSpace(strings.ToLower(s))
	if s == "" {
		return "unknown"
	}
	var b strings.Builder
	for _, r := range s {
		if (r >= 'a' && r <= 'z') || (r >= '0' && r <= '9') || r == '_' {
			b.WriteRune(r)
		} else {
			b.WriteByte('_')
		}
	}
	out := strings.Trim(b.String(), "_")
	if out == "" {
		return "unknown"
	}
	return out
}

func nonEmpty(v, fallback string) string {
	if strings.TrimSpace(v) == "" {
		return fallback
	}
	return v
}

func writeJSON(path string, v any) error {
	b, err := json.MarshalIndent(v, "", "  ")
	if err != nil {
		return err
	}
	return os.WriteFile(path, append(b, '\n'), 0o644)
}

func flt(v any) float64 {
	switch t := v.(type) {
	case float64:
		return t
	case int:
		return float64(t)
	default:
		return 0
	}
}

func fail(format string, args ...any) {
	fmt.Fprintf(os.Stderr, format+"\n", args...)
	os.Exit(1)
}
