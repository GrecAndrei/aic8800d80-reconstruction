package main

import (
	"encoding/json"
	"flag"
	"fmt"
	"os"
	"path/filepath"
	"sort"
	"strings"
	"time"

	"aic8800d80/internal/fileio"
	"aic8800d80/internal/reconstruct"
)

type composeIndexRow struct {
	SchemaVersion string  `json:"schema_version,omitempty"`
	Function      string  `json:"function"`
	Image         string  `json:"image"`
	Address       string  `json:"address"`
	Priority      string  `json:"priority"`
	WorkScore     float64 `json:"work_score"`
	Kind          string  `json:"kind"` // lifted_unit | dependency_stub
	Incoming      int     `json:"incoming_calls"`
	Outgoing      int     `json:"outgoing_calls"`
	Dependencies  int     `json:"dependencies"`
}

type implTask struct {
	SchemaVersion       string   `json:"schema_version"`
	TaskID              string   `json:"task_id"`
	Function            string   `json:"function"`
	Image               string   `json:"image"`
	Address             string   `json:"address"`
	TaskClass           string   `json:"task_class"` // behavior_lift | dependency_impl
	Priority            string   `json:"priority"`
	RankScore           float64  `json:"rank_score"`
	UrgencyScore        float64  `json:"urgency_score,omitempty"`
	DescriptorPhenotype string   `json:"descriptor_phenotype,omitempty"`
	MotifFamily         string   `json:"motif_family,omitempty"`
	MotifConfidence     float64  `json:"motif_confidence,omitempty"`
	BehaviorRole        string   `json:"behavior_role,omitempty"`
	Reasons             []string `json:"reasons"`
	Implementation      []string `json:"implementation_steps"`
}

type implManifest struct {
	SchemaVersion    string `json:"schema_version"`
	GeneratedAt      string `json:"generated_at"`
	ComposeIndex     string `json:"compose_index_path"`
	SkipTasks        int    `json:"skip_tasks"`
	FocusCount       int    `json:"focus_count"`
	DescriptorCount  int    `json:"descriptor_count"`
	MotifFamilyCount int    `json:"motif_family_count"`
	TaskCount        int    `json:"task_count"`
	BehaviorCount    int    `json:"behavior_lift_count"`
	DepImplCount     int    `json:"dependency_impl_count"`
	OutputDir        string `json:"output_dir"`
}

func main() {
	var composeIndexPath string
	var outDir string
	var maxTasks int
	var skipTasks int
	var focusFunctionsCSV string
	var focusBonus float64
	var descriptorsPath string
	var motifMemoryPath string

	flag.StringVar(&composeIndexPath, "compose-index", "extraction_out/reconstruction/mega7/composed/compose_index.json", "Compose index JSON")
	flag.StringVar(&outDir, "out", "extraction_out/reconstruction/mega7/implqueue", "Output directory")
	flag.IntVar(&maxTasks, "max-tasks", 600, "Maximum implementation tasks")
	flag.IntVar(&skipTasks, "skip-tasks", 0, "Rotate queue start by this many tasks before truncation")
	flag.StringVar(&focusFunctionsCSV, "focus-functions", "", "Comma-separated function names to prioritize in the queue")
	flag.Float64Var(&focusBonus, "focus-bonus", 1000.0, "Rank score bonus applied to focus functions")
	flag.StringVar(&descriptorsPath, "descriptors", "extraction_out/reconstruction/mega7/analysis/function_descriptors.json", "Function descriptor JSON path")
	flag.StringVar(&motifMemoryPath, "motif-memory", "extraction_out/reconstruction/mega7/analysis/motif_recipe_memory.json", "Motif memory JSON path")
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
	focusSet := parseFocusFunctions(focusFunctionsCSV)
	descriptors, err := reconstruct.LoadDescriptorSet(descriptorsPath)
	if err != nil {
		fail("load descriptors: %v", err)
	}
	motifMemory, err := reconstruct.LoadMotifMemorySet(motifMemoryPath)
	if err != nil {
		fail("load motif memory: %v", err)
	}

	tasks := make([]implTask, 0, maxTasks)
	for _, r := range rows {
		if strings.TrimSpace(r.SchemaVersion) != "" && r.SchemaVersion != "0.1.0" {
			fail("compose index schema mismatch: got %s want 0.1.0", r.SchemaVersion)
		}
		t, ok := toTask(r)
		if !ok {
			continue
		}
		t = applyFocusBoost(t, focusSet, focusBonus)
		t = applyDescriptorBoost(t, descriptors.Lookup(t.Function, t.Image, t.Address), motifMemory)
		t.SchemaVersion = "0.1.0"
		tasks = append(tasks, t)
	}
	sort.Slice(tasks, func(i, j int) bool {
		if tasks[i].RankScore == tasks[j].RankScore {
			return tasks[i].TaskID < tasks[j].TaskID
		}
		return tasks[i].RankScore > tasks[j].RankScore
	})
	if len(tasks) > 0 && skipTasks > 0 {
		off := skipTasks % len(tasks)
		tasks = append(tasks[off:], tasks[:off]...)
	}
	if maxTasks > 0 && len(tasks) > maxTasks {
		tasks = tasks[:maxTasks]
	}
	for i := range tasks {
		tasks[i].TaskID = fmt.Sprintf("impl_%04d_%s", i+1, tasks[i].Function)
	}

	m := implManifest{
		SchemaVersion:    "0.1.0",
		GeneratedAt:      time.Now().UTC().Format(time.RFC3339),
		ComposeIndex:     idxAbs,
		SkipTasks:        skipTasks,
		FocusCount:       len(focusSet),
		DescriptorCount:  len(descriptors.Rows),
		MotifFamilyCount: len(motifMemory.Rows),
		TaskCount:        len(tasks),
		OutputDir:        outAbs,
	}
	for _, t := range tasks {
		if t.TaskClass == "behavior_lift" {
			m.BehaviorCount++
		} else {
			m.DepImplCount++
		}
	}

	if err := fileio.WriteJSON(filepath.Join(outAbs, "implementation_queue.json"), tasks); err != nil {
		fail("write queue: %v", err)
	}
	if err := fileio.WriteJSON(filepath.Join(outAbs, "implqueue_manifest.json"), m); err != nil {
		fail("write manifest: %v", err)
	}

	fmt.Printf("implementation queue generated.\n")
	fmt.Printf("  skip_tasks: %d\n", skipTasks)
	fmt.Printf("  task_count: %d\n", m.TaskCount)
	fmt.Printf("  behavior_lift_count: %d\n", m.BehaviorCount)
	fmt.Printf("  dependency_impl_count: %d\n", m.DepImplCount)
	fmt.Printf("  out_dir: %s\n", outAbs)
}

func applyDescriptorBoost(t implTask, desc *reconstruct.FunctionDescriptor, memory *reconstruct.MotifMemorySet) implTask {
	if desc == nil {
		return t
	}
	t.UrgencyScore = desc.Priority.RebuildUrgency
	t.DescriptorPhenotype = desc.Probe.Phenotype
	t.MotifFamily = desc.Motif.Family
	t.MotifConfidence = desc.Motif.Confidence
	t.BehaviorRole = desc.Behavior.Role
	boost := desc.Priority.RebuildUrgency
	if desc.Behavior.Role != "" {
		t.Reasons = append(t.Reasons, fmt.Sprintf("descriptor behavior role=%s", desc.Behavior.Role))
	}
	if desc.Probe.Phenotype != "" {
		t.Reasons = append(t.Reasons, fmt.Sprintf("descriptor phenotype=%s", desc.Probe.Phenotype))
	}
	if desc.Motif.Family != "" {
		t.Reasons = append(t.Reasons, fmt.Sprintf("descriptor motif=%s (%.2f)", desc.Motif.Family, desc.Motif.Confidence))
	}
	if memory != nil && desc.Motif.Family != "" {
		if fam := memory.Lookup(desc.Motif.Family); fam != nil {
			boost += fam.AvgConfidence + fam.SuccessRate/50.0
			t.Reasons = append(t.Reasons, fmt.Sprintf("motif memory %s success=%.1f%% samples=%d", fam.Family, fam.SuccessRate, fam.SampleCount))
		}
	}
	t.RankScore += boost
	if boost >= 6.0 {
		t.Priority = "critical"
	} else if boost >= 3.0 && (t.Priority == "" || t.Priority == "low" || t.Priority == "medium") {
		t.Priority = "high"
	}
	return t
}

func parseFocusFunctions(csv string) map[string]struct{} {
	out := map[string]struct{}{}
	for _, part := range strings.Split(csv, ",") {
		name := strings.ToLower(strings.TrimSpace(part))
		if name == "" {
			continue
		}
		out[name] = struct{}{}
	}
	return out
}

func applyFocusBoost(t implTask, focusSet map[string]struct{}, focusBonus float64) implTask {
	if len(focusSet) == 0 || focusBonus <= 0 {
		return t
	}
	if _, ok := focusSet[strings.ToLower(strings.TrimSpace(t.Function))]; !ok {
		return t
	}
	t.RankScore += focusBonus
	t.Reasons = append([]string{fmt.Sprintf("prioritized from recent capped smoke outcomes (+%.1f)", focusBonus)}, t.Reasons...)
	if t.Priority == "" || t.Priority == "low" || t.Priority == "medium" {
		t.Priority = "critical"
	}
	return t
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
