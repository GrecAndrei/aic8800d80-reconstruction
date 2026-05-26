package main

import (
	"bufio"
	"encoding/json"
	"flag"
	"fmt"
	"os"
	"path/filepath"
	"sort"
	"strings"
	"time"

	"aic8800d80/internal/fileio"
)

type implTask struct {
	SchemaVersion  string   `json:"schema_version,omitempty"`
	TaskID         string   `json:"task_id"`
	Function       string   `json:"function"`
	Image          string   `json:"image"`
	Address        string   `json:"address"`
	TaskClass      string   `json:"task_class"`
	Priority       string   `json:"priority"`
	RankScore      float64  `json:"rank_score"`
	Reasons        []string `json:"reasons"`
	Implementation []string `json:"implementation_steps"`
}

type callEdge struct {
	SchemaVersion string  `json:"schema_version,omitempty"`
	Image         string  `json:"image"`
	SourceAddr    string  `json:"source_addr"`
	SourceName    string  `json:"source_name"`
	TargetAddr    string  `json:"target_addr"`
	TargetName    string  `json:"target_name"`
	Confidence    float64 `json:"confidence"`
}

type implWorkManifest struct {
	SchemaVersion string `json:"schema_version"`
	GeneratedAt   string `json:"generated_at"`
	QueuePath     string `json:"queue_path"`
	CallEdgesPath string `json:"call_edges_path"`
	WorkfileCount int    `json:"workfile_count"`
	OutputDir     string `json:"output_dir"`
}

func main() {
	var queuePath string
	var callEdgesPath string
	var outDir string
	var maxTasks int
	var minConf float64

	flag.StringVar(&queuePath, "implqueue", "extraction_out/reconstruction/mega7/implqueue/implementation_queue.json", "Implementation queue JSON")
	flag.StringVar(&callEdgesPath, "call-edges", "extraction_out/call_edges.jsonl", "Call edges JSONL")
	flag.StringVar(&outDir, "out", "extraction_out/reconstruction/mega7/implwork", "Output directory")
	flag.IntVar(&maxTasks, "max-tasks", 120, "Maximum workfiles generated")
	flag.Float64Var(&minConf, "min-call-confidence", 0.7, "Minimum confidence for call evidence")
	flag.Parse()

	qAbs, _ := filepath.Abs(queuePath)
	cAbs, _ := filepath.Abs(callEdgesPath)
	outAbs, _ := filepath.Abs(outDir)
	if err := os.MkdirAll(outAbs, 0o755); err != nil {
		fail("mkdir out: %v", err)
	}

	tasks, err := readTasks(qAbs)
	if err != nil {
		fail("read implqueue: %v", err)
	}
	if len(tasks) == 0 {
		fail("implqueue empty")
	}
	if maxTasks > 0 && len(tasks) > maxTasks {
		tasks = tasks[:maxTasks]
	}

	inAdj, outAdj, err := readAdj(cAbs, minConf)
	if err != nil {
		fail("read call edges: %v", err)
	}

	count := 0
	for i, t := range tasks {
		key := addrKey(t.Image, t.Address)
		outFile := filepath.Join(outAbs, fmt.Sprintf("%03d_%s.c", i+1, sanitizeName(t.Function)))
		if err := writeWorkfile(outFile, t, inAdj[key], outAdj[key]); err != nil {
			fail("write workfile %s: %v", outFile, err)
		}
		count++
	}

	m := implWorkManifest{
		SchemaVersion: "0.1.0",
		GeneratedAt:   time.Now().UTC().Format(time.RFC3339),
		QueuePath:     qAbs,
		CallEdgesPath: cAbs,
		WorkfileCount: count,
		OutputDir:     outAbs,
	}
	if err := fileio.WriteJSON(filepath.Join(outAbs, "implwork_manifest.json"), m); err != nil {
		fail("write manifest: %v", err)
	}

	fmt.Printf("implementation workfiles generated.\n")
	fmt.Printf("  workfile_count: %d\n", count)
	fmt.Printf("  out_dir: %s\n", outAbs)
}

func readTasks(path string) ([]implTask, error) {
	b, err := os.ReadFile(path)
	if err != nil {
		return nil, err
	}
	var t []implTask
	if err := json.Unmarshal(b, &t); err != nil {
		return nil, err
	}
	for _, task := range t {
		if strings.TrimSpace(task.SchemaVersion) != "" && task.SchemaVersion != "0.1.0" {
			return nil, fmt.Errorf("implqueue schema mismatch: got %s want 0.1.0", task.SchemaVersion)
		}
	}
	return t, nil
}

func readAdj(path string, minConf float64) (map[string][]callEdge, map[string][]callEdge, error) {
	f, err := os.Open(path)
	if err != nil {
		return nil, nil, err
	}
	defer f.Close()
	in := make(map[string][]callEdge, 4096)
	out := make(map[string][]callEdge, 4096)
	sc := bufio.NewScanner(f)
	sc.Buffer(make([]byte, 4096), 8*1024*1024)
	for sc.Scan() {
		line := strings.TrimSpace(sc.Text())
		if line == "" {
			continue
		}
		var e callEdge
		if json.Unmarshal([]byte(line), &e) != nil {
			continue
		}
		if strings.TrimSpace(e.SchemaVersion) != "" && e.SchemaVersion != "0.1.0" {
			return nil, nil, fmt.Errorf("call edges schema mismatch: got %s want 0.1.0", e.SchemaVersion)
		}
		if e.Confidence < minConf {
			continue
		}
		out[addrKey(e.Image, e.SourceAddr)] = append(out[addrKey(e.Image, e.SourceAddr)], e)
		in[addrKey(e.Image, e.TargetAddr)] = append(in[addrKey(e.Image, e.TargetAddr)], e)
	}
	return in, out, sc.Err()
}

func writeWorkfile(path string, t implTask, incoming, outgoing []callEdge) error {
	sort.Slice(incoming, func(i, j int) bool { return incoming[i].Confidence > incoming[j].Confidence })
	sort.Slice(outgoing, func(i, j int) bool { return outgoing[i].Confidence > outgoing[j].Confidence })

	var b strings.Builder
	b.WriteString("/* Auto-generated implementation workfile */\n")
	b.WriteString(fmt.Sprintf("/* task_id=%s class=%s priority=%s score=%.3f */\n", t.TaskID, t.TaskClass, t.Priority, t.RankScore))
	b.WriteString(fmt.Sprintf("/* image=%s addr=%s function=%s */\n\n", t.Image, t.Address, t.Function))
	b.WriteString("#include <stdint.h>\n\n")
	b.WriteString("/* reasons:\n")
	for _, r := range t.Reasons {
		b.WriteString(" * - " + r + "\n")
	}
	b.WriteString(" */\n\n")
	b.WriteString("/* implementation plan:\n")
	for _, s := range t.Implementation {
		b.WriteString(" * - " + s + "\n")
	}
	b.WriteString(" */\n\n")
	if len(incoming) > 0 {
		b.WriteString("/* incoming callers:\n")
		for _, e := range incoming {
			b.WriteString(fmt.Sprintf(" * - %s@%s (conf=%.2f)\n", nonEmpty(e.SourceName, "sub"), e.SourceAddr, e.Confidence))
		}
		b.WriteString(" */\n\n")
	}
	if len(outgoing) > 0 {
		b.WriteString("/* outgoing callees:\n")
		for _, e := range outgoing {
			b.WriteString(fmt.Sprintf(" * - %s@%s (conf=%.2f)\n", nonEmpty(e.TargetName, "sub"), e.TargetAddr, e.Confidence))
		}
		b.WriteString(" */\n\n")
	}

	fn := sanitizeName(t.Function)
	b.WriteString(fmt.Sprintf("void %s(void) {\n", fn))
	b.WriteString("  // TODO(impl): recover exact control/data flow.\n")
	b.WriteString("  // TODO(impl): assign concrete ABI/args/return semantics.\n")
	if len(outgoing) > 0 {
		b.WriteString("  // Scaffolding calls from call-graph evidence:\n")
		seen := map[string]struct{}{}
		for _, e := range outgoing {
			n := sanitizeName(nonEmpty(e.TargetName, "sub_"+strings.TrimPrefix(strings.ToLower(e.TargetAddr), "0x")))
			if n == "" || n == fn {
				continue
			}
			if _, ok := seen[n]; ok {
				continue
			}
			seen[n] = struct{}{}
			b.WriteString("  " + n + "();\n")
		}
	}
	b.WriteString("}\n")

	return fileio.WriteBytes(path, []byte(b.String()))
}

func addrKey(img, addr string) string {
	return strings.ToLower(strings.TrimSpace(img)) + "|" + strings.ToLower(strings.TrimSpace(addr))
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

func fail(format string, args ...any) {
	fmt.Fprintf(os.Stderr, format+"\n", args...)
	os.Exit(1)
}
