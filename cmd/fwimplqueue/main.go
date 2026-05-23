package main

import (
	"encoding/json"
	"flag"
	"fmt"
	"os"
	"path/filepath"
	"sort"
	"time"
)

type composeIndexRow struct {
	Function     string  `json:"function"`
	Image        string  `json:"image"`
	Address      string  `json:"address"`
	Priority     string  `json:"priority"`
	WorkScore    float64 `json:"work_score"`
	Kind         string  `json:"kind"` // lifted_unit | dependency_stub
	Incoming     int     `json:"incoming_calls"`
	Outgoing     int     `json:"outgoing_calls"`
	Dependencies int     `json:"dependencies"`
}

type implTask struct {
	TaskID         string   `json:"task_id"`
	Function       string   `json:"function"`
	Image          string   `json:"image"`
	Address        string   `json:"address"`
	TaskClass      string   `json:"task_class"` // behavior_lift | dependency_impl
	Priority       string   `json:"priority"`
	RankScore      float64  `json:"rank_score"`
	Reasons        []string `json:"reasons"`
	Implementation []string `json:"implementation_steps"`
}

type implManifest struct {
	SchemaVersion string `json:"schema_version"`
	GeneratedAt   string `json:"generated_at"`
	ComposeIndex  string `json:"compose_index_path"`
	TaskCount     int    `json:"task_count"`
	BehaviorCount int    `json:"behavior_lift_count"`
	DepImplCount  int    `json:"dependency_impl_count"`
	OutputDir     string `json:"output_dir"`
}

func main() {
	var composeIndexPath string
	var outDir string
	var maxTasks int

	flag.StringVar(&composeIndexPath, "compose-index", "extraction_out/reconstruction/mega7/composed/compose_index.json", "Compose index JSON")
	flag.StringVar(&outDir, "out", "extraction_out/reconstruction/mega7/implqueue", "Output directory")
	flag.IntVar(&maxTasks, "max-tasks", 600, "Maximum implementation tasks")
	flag.Parse()

	idxAbs, _ := filepath.Abs(composeIndexPath)
	outAbs, _ := filepath.Abs(outDir)
	if err := os.MkdirAll(outAbs, 0o755); err != nil {
		fail("mkdir out: %v", err)
	}

	b, err := os.ReadFile(idxAbs)
	if err != nil {
		fail("read compose index: %v", err)
	}
	var rows []composeIndexRow
	if err := json.Unmarshal(b, &rows); err != nil {
		fail("parse compose index: %v", err)
	}
	if len(rows) == 0 {
		fail("compose index empty")
	}

	tasks := make([]implTask, 0, maxTasks)
	for _, r := range rows {
		t, ok := toTask(r)
		if !ok {
			continue
		}
		tasks = append(tasks, t)
	}
	sort.Slice(tasks, func(i, j int) bool {
		if tasks[i].RankScore == tasks[j].RankScore {
			return tasks[i].TaskID < tasks[j].TaskID
		}
		return tasks[i].RankScore > tasks[j].RankScore
	})
	if maxTasks > 0 && len(tasks) > maxTasks {
		tasks = tasks[:maxTasks]
	}
	for i := range tasks {
		tasks[i].TaskID = fmt.Sprintf("impl_%04d_%s", i+1, tasks[i].Function)
	}

	m := implManifest{
		SchemaVersion: "0.1.0",
		GeneratedAt:   time.Now().UTC().Format(time.RFC3339),
		ComposeIndex:  idxAbs,
		TaskCount:     len(tasks),
		OutputDir:     outAbs,
	}
	for _, t := range tasks {
		if t.TaskClass == "behavior_lift" {
			m.BehaviorCount++
		} else {
			m.DepImplCount++
		}
	}

	tb, err := json.MarshalIndent(tasks, "", "  ")
	if err != nil {
		fail("marshal tasks: %v", err)
	}
	if err := os.WriteFile(filepath.Join(outAbs, "implementation_queue.json"), append(tb, '\n'), 0o644); err != nil {
		fail("write queue: %v", err)
	}
	mb, err := json.MarshalIndent(m, "", "  ")
	if err != nil {
		fail("marshal manifest: %v", err)
	}
	if err := os.WriteFile(filepath.Join(outAbs, "implqueue_manifest.json"), append(mb, '\n'), 0o644); err != nil {
		fail("write manifest: %v", err)
	}

	fmt.Printf("implementation queue generated.\n")
	fmt.Printf("  task_count: %d\n", m.TaskCount)
	fmt.Printf("  behavior_lift_count: %d\n", m.BehaviorCount)
	fmt.Printf("  dependency_impl_count: %d\n", m.DepImplCount)
	fmt.Printf("  out_dir: %s\n", outAbs)
}

func toTask(r composeIndexRow) (implTask, bool) {
	if r.Kind == "dependency_stub" {
		return implTask{
			Function:  r.Function,
			Image:     r.Image,
			Address:   r.Address,
			TaskClass: "dependency_impl",
			Priority:  "medium",
			RankScore: 2.0 + float64(r.Outgoing)*0.1 + float64(r.Incoming)*0.1,
			Reasons: []string{
				"called by reconstructed functions",
				"currently unresolved dependency stub",
			},
			Implementation: []string{
				"Locate implementation by xrefs/callers and assign semantic role",
				"Recover side effects and state changes",
				"Replace stub with recovered logic",
			},
		}, true
	}
	// lifted units: prioritize high fanout/fanin and remaining TODO risk.
	score := r.WorkScore + float64(r.Outgoing)*0.2 + float64(r.Incoming)*0.15 + float64(r.Dependencies)*0.1
	priority := r.Priority
	if priority == "" {
		priority = "medium"
	}
	return implTask{
		Function:  r.Function,
		Image:     r.Image,
		Address:   r.Address,
		TaskClass: "behavior_lift",
		Priority:  priority,
		RankScore: score,
		Reasons: []string{
			"lifted scaffold exists but behavior remains partial",
			fmt.Sprintf("incoming=%d outgoing=%d deps=%d", r.Incoming, r.Outgoing, r.Dependencies),
		},
		Implementation: []string{
			"Recover control-flow branches and loop conditions",
			"Infer parameter/return contract from callers/callees",
			"Map MMIO/buffer side effects and annotate invariants",
		},
	}, true
}

func fail(format string, args ...any) {
	fmt.Fprintf(os.Stderr, format+"\n", args...)
	os.Exit(1)
}
