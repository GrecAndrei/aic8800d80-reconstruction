package stats

import (
	"bufio"
	"encoding/json"
	"fmt"
	"os"
	"path/filepath"
	"sort"
	"strings"
	"syscall"
	"time"

	"aic8800d80/internal/fileio"
)

const (
	baseFunctionEstimate = 1313
	historyFileName      = "stats_history.jsonl"
	latestFileName       = "stats_latest.json"
)

type Snapshot struct {
	GeneratedAt   string            `json:"generated_at"`
	OutDir        string            `json:"out_dir"`
	Totals        Totals            `json:"totals"`
	Progress      Progress          `json:"progress"`
	Functions     FunctionStats     `json:"functions"`
	Artifacts     ArtifactStats     `json:"artifacts"`
	Links         LinkStats         `json:"links"`
	Calls         CallStats         `json:"calls"`
	Messages      MessageStats      `json:"messages"`
	StateMachines StateMachineStats `json:"state_machines"`
	MiningQueue   MiningStats       `json:"mining_queue"`
	Patches       PatchStats        `json:"patches"`
	Images        []ImageStats      `json:"images"`
	Top           TopLists          `json:"top"`
	History       []HistoryPoint    `json:"history,omitempty"`
}

type Totals struct {
	Images        int `json:"images"`
	Functions     int `json:"functions"`
	Artifacts     int `json:"artifacts"`
	Links         int `json:"links"`
	Calls         int `json:"calls"`
	Messages      int `json:"messages"`
	StateMachines int `json:"state_machines"`
	Queue         int `json:"queue"`
	Patches       int `json:"patches"`
}

type Progress struct {
	BaseFunctionEstimate  int     `json:"base_function_estimate"`
	BaseNamedFunctions    int     `json:"base_named_functions"`
	BaseCoveragePct       float64 `json:"base_coverage_pct"`
	LinkedSourceFunctions int     `json:"linked_source_functions"`
	LinkCoveragePct       float64 `json:"link_coverage_pct"`
	ReconstructedFuncs    int     `json:"reconstructed_functions"`
	ReconClusterCount     int     `json:"recon_cluster_count"`
	ReconQueueCount       int     `json:"recon_queue_count"`
	ReconFocusCount       int     `json:"recon_focus_count"`
	ReconLiftCount        int     `json:"recon_lift_count"`
	ReconComposeCount     int     `json:"recon_compose_count"`
	ReconImplQueueCount   int     `json:"recon_implqueue_count"`
	ReconImplWorkCount    int     `json:"recon_implwork_count"`
	ReconImplSynthCount   int     `json:"recon_implsynth_count"`
	ReconImplSynthAvgCall float64 `json:"recon_implsynth_avg_callees"`
	ReconImplAppliedCount int     `json:"recon_implapplied_count"`
	ReconFinalizedCount   int     `json:"recon_finalized_count"`
	ReconStrongCount      int     `json:"recon_strong_count"`
	ReconFallbackCount    int     `json:"recon_fallback_count"`
	ReconTodoRemaining    int     `json:"recon_todo_remaining"`
	ReconCompletionPct    float64 `json:"recon_completion_pct"`
	ReconSemanticPct      float64 `json:"recon_semantic_completion_pct"`
	ReconConformancePct   float64 `json:"recon_conformance_pct"`
	ReconConformanceEval  int     `json:"recon_conformance_evaluable"`
	ReconConformanceLow   int     `json:"recon_conformance_nonperfect"`
	PatchMMIOPct          float64 `json:"patch_mmio_pct"`
	DataFreshnessSec      int64   `json:"data_freshness_sec"`
	DiskFreeGB            float64 `json:"disk_free_gb"`
	DiskUsedGB            float64 `json:"disk_used_gb"`
	DiskUsePct            float64 `json:"disk_use_pct"`
}

type CountPair struct {
	Key   string `json:"key"`
	Count int    `json:"count"`
}

type FunctionStats struct {
	AverageConfidence float64     `json:"average_confidence"`
	UnknownRoleCount  int         `json:"unknown_role_count"`
	AliasCount        int         `json:"alias_count"`
	RoleCounts        []CountPair `json:"role_counts"`
	SourceCounts      []CountPair `json:"source_counts"`
	ImageCounts       []CountPair `json:"image_counts"`
	ConfidenceBuckets []CountPair `json:"confidence_buckets"`
	UniqueByImage     []CountPair `json:"unique_by_image"`
}

type ArtifactStats struct {
	TypeCounts         []CountPair `json:"type_counts"`
	ImageCounts        []CountPair `json:"image_counts"`
	UniqueMMIORefs     int         `json:"unique_mmio_refs"`
	UniquePatchTags    int         `json:"unique_patch_tags"`
	VectorFieldEntries int         `json:"vector_field_entries"`
}

type LinkStats struct {
	AverageConfidence   float64     `json:"average_confidence"`
	MethodCounts        []CountPair `json:"method_counts"`
	TargetImageCounts   []CountPair `json:"target_image_counts"`
	ConfidenceBuckets   []CountPair `json:"confidence_buckets"`
	UniqueSourceFuncs   int         `json:"unique_source_funcs"`
	UniqueTargetFuncs   int         `json:"unique_target_funcs"`
	HighConfidenceLinks int         `json:"high_confidence_links"`
}

type CallStats struct {
	SourceCounts      []CountPair `json:"source_counts"`
	TargetCounts      []CountPair `json:"target_counts"`
	SourceNameCounts  []CountPair `json:"source_name_counts"`
	TargetNameCounts  []CountPair `json:"target_name_counts"`
	AverageConfidence float64     `json:"average_confidence"`
}

type MessageStats struct {
	FamilyCounts         []CountPair `json:"family_counts"`
	KindCounts           []CountPair `json:"kind_counts"`
	RoleCounts           []CountPair `json:"role_counts"`
	AverageConfidence    float64     `json:"average_confidence"`
	AverageOutgoingCalls float64     `json:"average_outgoing_calls"`
}

type StateMachineStats struct {
	MachineCounts     []CountPair `json:"machine_counts"`
	StateCounts       []CountPair `json:"state_counts"`
	FunctionCounts    []CountPair `json:"function_counts"`
	AverageConfidence float64     `json:"average_confidence"`
}

type MiningStats struct {
	AveragePriority float64     `json:"average_priority"`
	TopReasons      []CountPair `json:"top_reasons"`
	RoleCounts      []CountPair `json:"role_counts"`
	TopTargets      []CountPair `json:"top_targets"`
}

type PatchStats struct {
	SectionCounts []CountPair `json:"section_counts"`
	AddressKinds  []CountPair `json:"address_kinds"`
	ValueKinds    []CountPair `json:"value_kinds"`
	MMIOEntries   int         `json:"mmio_entries"`
	PointerValues int         `json:"pointer_values"`
	AverageConf   float64     `json:"average_confidence"`
}

type ImageStats struct {
	Image            string `json:"image"`
	Size             int64  `json:"size"`
	PrintableStrings int    `json:"printable_strings"`
	LikelyThumb      bool   `json:"likely_thumb"`
	HasVector        bool   `json:"has_vector"`
}

type TopLists struct {
	LinkedFunctions []CountPair `json:"linked_functions"`
	MessageFamilies []CountPair `json:"message_families"`
	StateMachines   []CountPair `json:"state_machines"`
	TopCallSources  []CountPair `json:"top_call_sources"`
	MiningReasons   []CountPair `json:"mining_reasons"`
	PatchSections   []CountPair `json:"patch_sections"`
	FunctionRoles   []CountPair `json:"function_roles"`
	ArtifactTypes   []CountPair `json:"artifact_types"`
}

type HistoryPoint struct {
	Timestamp       string  `json:"timestamp"`
	Images          int     `json:"images"`
	Functions       int     `json:"functions"`
	Artifacts       int     `json:"artifacts"`
	Links           int     `json:"links"`
	Calls           int     `json:"calls"`
	Messages        int     `json:"messages"`
	StateMachines   int     `json:"state_machines"`
	Queue           int     `json:"queue"`
	Patches         int     `json:"patches"`
	BaseCoveragePct float64 `json:"base_coverage_pct"`
	LinkCoveragePct float64 `json:"link_coverage_pct"`
}

func CollectAndPersist(outDir string) (Snapshot, error) {
	snap, err := Collect(outDir)
	if err != nil {
		return Snapshot{}, err
	}
	outAbs, err := filepath.Abs(outDir)
	if err != nil {
		return Snapshot{}, err
	}
	if err := fileio.WriteJSON(filepath.Join(outAbs, latestFileName), snap); err != nil {
		return Snapshot{}, err
	}
	if err := appendHistory(outAbs, snap); err != nil {
		return Snapshot{}, err
	}
	h, _ := ReadHistory(outAbs, 300)
	snap.History = h
	if err := fileio.WriteJSON(filepath.Join(outAbs, latestFileName), snap); err != nil {
		return Snapshot{}, err
	}
	return snap, nil
}

func Collect(outDir string) (Snapshot, error) {
	outAbs, err := filepath.Abs(outDir)
	if err != nil {
		return Snapshot{}, err
	}
	snap := Snapshot{GeneratedAt: time.Now().UTC().Format(time.RFC3339), OutDir: outAbs}

	images := readJSONLMaps(filepath.Join(outAbs, "images.jsonl"))
	funcs := readJSONLMaps(filepath.Join(outAbs, "functions.jsonl"))
	arts := readJSONLMaps(filepath.Join(outAbs, "artifacts.jsonl"))
	links := readJSONLMaps(filepath.Join(outAbs, "function_links.jsonl"))
	calls := readJSONLMaps(filepath.Join(outAbs, "call_edges.jsonl"))
	msgs := readJSONLMaps(filepath.Join(outAbs, "message_schema.jsonl"))
	sm := readJSONLMaps(filepath.Join(outAbs, "state_machines.jsonl"))
	queue := readJSONLMaps(filepath.Join(outAbs, "mining_queue.jsonl"))
	patches := readJSONLMaps(filepath.Join(outAbs, "patch_entries.jsonl"))

	snap.Totals = Totals{len(images), len(funcs), len(arts), len(links), len(calls), len(msgs), len(sm), len(queue), len(patches)}

	baseNamed := 0
	srcLinked := map[string]struct{}{}
	fnRole := map[string]int{}
	fnSource := map[string]int{}
	fnImage := map[string]int{}
	aliasCount := 0
	for _, r := range funcs {
		name := str(r["name"])
		if name != "" && !strings.HasPrefix(strings.ToLower(name), "sub_") {
			baseNamed++
		}
		role := keyOrUnknown(str(r["role"]))
		fnRole[role]++
		fnSource[keyOrUnknown(str(r["source"]))]++
		fnImage[keyOrUnknown(str(r["image"]))]++
		if a, ok := r["aliases"].([]any); ok {
			aliasCount += len(a)
		}
	}
	for _, r := range links {
		s := str(r["source_address"])
		if s != "" {
			srcLinked[s] = struct{}{}
		}
	}

	artType := map[string]int{}
	artImg := map[string]int{}
	mmioRefs := map[string]struct{}{}
	patchTags := map[string]struct{}{}
	vectorCount := 0
	for _, r := range arts {
		t := keyOrUnknown(str(r["type"]))
		artType[t]++
		artImg[keyOrUnknown(str(r["image"]))]++
		k := str(r["key"])
		if t == "mmio_ref" && k != "" {
			mmioRefs[k] = struct{}{}
		}
		if t == "patch_tag" && k != "" {
			patchTags[k] = struct{}{}
		}
		if t == "vector_field" {
			vectorCount++
		}
	}

	linkMethods := map[string]int{}
	linkTargets := map[string]int{}
	srcFns := map[string]struct{}{}
	tgtFns := map[string]struct{}{}
	highLinks := 0
	for _, r := range links {
		linkMethods[keyOrUnknown(str(r["method"]))]++
		linkTargets[keyOrUnknown(str(r["target_image"]))]++
		srcFns[keyOrUnknown(str(r["source_image"])+"|"+str(r["source_address"]))] = struct{}{}
		tgtFns[keyOrUnknown(str(r["target_image"])+"|"+str(r["target_address"]))] = struct{}{}
		if flt(r["confidence"]) >= 0.9 {
			highLinks++
		}
	}

	msgFamily := map[string]int{}
	msgKind := map[string]int{}
	msgRole := map[string]int{}
	for _, r := range msgs {
		msgFamily[keyOrUnknown(str(r["family"]))]++
		msgKind[keyOrUnknown(str(r["kind"]))]++
		msgRole[keyOrUnknown(str(r["role"]))]++
	}

	smMachine := map[string]int{}
	smState := map[string]int{}
	smFunc := map[string]int{}
	for _, r := range sm {
		smMachine[keyOrUnknown(str(r["machine"]))]++
		smState[keyOrUnknown(str(r["state"]))]++
		smFunc[keyOrUnknown(str(r["function"]))]++
	}

	queueReasons := map[string]int{}
	queueRoles := map[string]int{}
	queueTargets := map[string]int{}
	prioSum := 0.0
	for _, r := range queue {
		queueRoles[keyOrUnknown(str(r["role"]))]++
		queueTargets[keyOrUnknown(str(r["name"]))]++
		prioSum += flt(r["priority_score"])
		if rr, ok := r["reasons"].([]any); ok {
			for _, v := range rr {
				queueReasons[keyOrUnknown(str(v))]++
			}
		}
	}
	avgPrio := 0.0
	if len(queue) > 0 {
		avgPrio = prioSum / float64(len(queue))
	}

	patchSect := map[string]int{}
	addrKind := map[string]int{}
	valKind := map[string]int{}
	mmio := 0
	ptr := 0
	for _, r := range patches {
		patchSect[keyOrUnknown(str(r["section_tag"]))]++
		ak := keyOrUnknown(str(r["address_kind"]))
		addrKind[ak]++
		vk := keyOrUnknown(str(r["value_kind"]))
		valKind[vk]++
		if ak == "mmio" {
			mmio++
		}
		if vk == "pointer_like" {
			ptr++
		}
	}

	baseCoverage := pct(float64(baseNamed), float64(baseFunctionEstimate))
	linkCoverage := pct(float64(len(srcLinked)), float64(max(1, baseNamed)))
	patchMMIOPct := pct(float64(mmio), float64(max(1, len(patches))))
	freeGB, usedGB, usePct := diskUsage(outAbs)

	reconFuncs, reconClusters, reconQueue, reconFocus, reconLift, reconCompose, reconImplQueue, reconImplWork, reconImplSynth, reconImplSynthAvg, reconImplApplied, reconFinalized, reconStrong, reconFallback, reconTodoRemaining, reconCompletion, reconSemantic, reconConformance, reconConformanceEval, reconConformanceLow := reconstructionProgress(outAbs)
	snap.Progress = Progress{
		BaseFunctionEstimate:  baseFunctionEstimate,
		BaseNamedFunctions:    baseNamed,
		BaseCoveragePct:       round3(baseCoverage),
		LinkedSourceFunctions: len(srcLinked),
		LinkCoveragePct:       round3(linkCoverage),
		ReconstructedFuncs:    reconFuncs,
		ReconClusterCount:     reconClusters,
		ReconQueueCount:       reconQueue,
		ReconFocusCount:       reconFocus,
		ReconLiftCount:        reconLift,
		ReconComposeCount:     reconCompose,
		ReconImplQueueCount:   reconImplQueue,
		ReconImplWorkCount:    reconImplWork,
		ReconImplSynthCount:   reconImplSynth,
		ReconImplSynthAvgCall: round3(reconImplSynthAvg),
		ReconImplAppliedCount: reconImplApplied,
		ReconFinalizedCount:   reconFinalized,
		ReconStrongCount:      reconStrong,
		ReconFallbackCount:    reconFallback,
		ReconTodoRemaining:    reconTodoRemaining,
		ReconCompletionPct:    round3(reconCompletion),
		ReconSemanticPct:      round3(reconSemantic),
		ReconConformancePct:   round3(reconConformance),
		ReconConformanceEval:  reconConformanceEval,
		ReconConformanceLow:   reconConformanceLow,
		PatchMMIOPct:          round3(patchMMIOPct),
		DataFreshnessSec:      dataFreshnessSec(outAbs),
		DiskFreeGB:            round3(freeGB),
		DiskUsedGB:            round3(usedGB),
		DiskUsePct:            round3(usePct),
	}
	snap.Functions = FunctionStats{0, fnRole["unknown"], aliasCount, toPairs(fnRole), toPairs(fnSource), toPairs(fnImage), nil, toPairs(fnImage)}
	snap.Artifacts = ArtifactStats{toPairs(artType), toPairs(artImg), len(mmioRefs), len(patchTags), vectorCount}
	snap.Links = LinkStats{0, toPairs(linkMethods), toPairs(linkTargets), nil, len(srcFns), len(tgtFns), highLinks}
	snap.Calls = CallStats{nil, nil, nil, nil, 0}
	snap.Messages = MessageStats{toPairs(msgFamily), toPairs(msgKind), toPairs(msgRole), 0, 0}
	snap.StateMachines = StateMachineStats{toPairs(smMachine), toPairs(smState), toPairs(smFunc), 0}
	snap.MiningQueue = MiningStats{round3(avgPrio), topNPairs(queueReasons, 25), toPairs(queueRoles), topNPairs(queueTargets, 25)}
	snap.Patches = PatchStats{toPairs(patchSect), toPairs(addrKind), toPairs(valKind), mmio, ptr, 0}

	imgStats := make([]ImageStats, 0, len(images))
	for _, r := range images {
		imgStats = append(imgStats, ImageStats{Image: str(r["image"]), Size: int64(flt(r["size"])), PrintableStrings: int(flt(r["printable_strings"])), LikelyThumb: boolVal(r["likely_thumb"]), HasVector: str(r["vector_initial_sp"]) != "" || str(r["vector_reset_handler"]) != ""})
	}
	sort.Slice(imgStats, func(i, j int) bool { return imgStats[i].Image < imgStats[j].Image })
	snap.Images = imgStats
	snap.Top = TopLists{topNPairs(queueTargets, 25), topNPairs(msgFamily, 25), topNPairs(smMachine, 25), nil, topNPairs(queueReasons, 25), topNPairs(patchSect, 25), topNPairs(fnRole, 25), topNPairs(artType, 25)}
	return snap, nil
}

func ReadHistory(outDir string, limit int) ([]HistoryPoint, error) {
	rows, err := readJSONLTyped[HistoryPoint](filepath.Join(outDir, historyFileName))
	if err != nil {
		if os.IsNotExist(err) {
			return nil, nil
		}
		return nil, err
	}
	if limit > 0 && len(rows) > limit {
		rows = rows[len(rows)-limit:]
	}
	return rows, nil
}

func appendHistory(outDir string, snap Snapshot) error {
	p := filepath.Join(outDir, historyFileName)
	lock, err := fileio.AcquireFileLock(p + ".lock")
	if err == nil {
		defer lock.Release()
	}
	f, err := os.OpenFile(p, os.O_CREATE|os.O_APPEND|os.O_WRONLY, 0o644)
	if err != nil {
		return err
	}
	defer f.Close()
	pt := HistoryPoint{Timestamp: snap.GeneratedAt, Images: snap.Totals.Images, Functions: snap.Totals.Functions, Artifacts: snap.Totals.Artifacts, Links: snap.Totals.Links, Calls: snap.Totals.Calls, Messages: snap.Totals.Messages, StateMachines: snap.Totals.StateMachines, Queue: snap.Totals.Queue, Patches: snap.Totals.Patches, BaseCoveragePct: snap.Progress.BaseCoveragePct, LinkCoveragePct: snap.Progress.LinkCoveragePct}
	enc := json.NewEncoder(f)
	return enc.Encode(pt)
}

func readJSONLMaps(path string) []map[string]any {
	rows := []map[string]any{}
	f, err := os.Open(path)
	if err != nil {
		return rows
	}
	defer f.Close()
	s := bufio.NewScanner(f)
	s.Buffer(make([]byte, 1024), 4*1024*1024)
	for s.Scan() {
		line := strings.TrimSpace(s.Text())
		if line == "" {
			continue
		}
		var m map[string]any
		if json.Unmarshal([]byte(line), &m) == nil {
			rows = append(rows, m)
		}
	}
	return rows
}

func readJSONLTyped[T any](path string) ([]T, error) {
	out := []T{}
	f, err := os.Open(path)
	if err != nil {
		return nil, err
	}
	defer f.Close()
	s := bufio.NewScanner(f)
	s.Buffer(make([]byte, 1024), 4*1024*1024)
	for s.Scan() {
		line := strings.TrimSpace(s.Text())
		if line == "" {
			continue
		}
		var t T
		if err := json.Unmarshal([]byte(line), &t); err == nil {
			out = append(out, t)
		}
	}
	return out, s.Err()
}

func toPairs(m map[string]int) []CountPair {
	rows := make([]CountPair, 0, len(m))
	for k, v := range m {
		rows = append(rows, CountPair{Key: k, Count: v})
	}
	sort.Slice(rows, func(i, j int) bool {
		if rows[i].Count == rows[j].Count {
			return rows[i].Key < rows[j].Key
		}
		return rows[i].Count > rows[j].Count
	})
	return rows
}
func topNPairs(m map[string]int, n int) []CountPair {
	p := toPairs(m)
	if len(p) > n {
		return p[:n]
	}
	return p
}

func str(v any) string {
	if v == nil {
		return ""
	}
	if s, ok := v.(string); ok {
		return s
	}
	return fmt.Sprintf("%v", v)
}
func flt(v any) float64 {
	switch t := v.(type) {
	case float64:
		return t
	case int:
		return float64(t)
	case int64:
		return float64(t)
	case json.Number:
		f, _ := t.Float64()
		return f
	default:
		return 0
	}
}
func boolVal(v any) bool { b, ok := v.(bool); return ok && b }
func keyOrUnknown(s string) string {
	s = strings.TrimSpace(s)
	if s == "" {
		return "unknown"
	}
	return s
}
func pct(a, b float64) float64 {
	if b <= 0 {
		return 0
	}
	return (a / b) * 100
}
func round3(v float64) float64 { return float64(int(v*1000+0.5)) / 1000 }
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func dataFreshnessSec(outDir string) int64 {
	entries, err := os.ReadDir(outDir)
	if err != nil {
		return 0
	}
	latest := time.Time{}
	for _, e := range entries {
		if e.IsDir() {
			continue
		}
		st, err := e.Info()
		if err != nil {
			continue
		}
		if st.ModTime().After(latest) {
			latest = st.ModTime()
		}
	}
	if latest.IsZero() {
		return 0
	}
	return int64(time.Since(latest).Seconds())
}

func diskUsage(path string) (freeGB float64, usedGB float64, usePct float64) {
	var st syscall.Statfs_t
	if err := syscall.Statfs(path, &st); err != nil {
		return 0, 0, 0
	}
	total := float64(st.Blocks) * float64(st.Bsize)
	free := float64(st.Bavail) * float64(st.Bsize)
	if total <= 0 {
		return 0, 0, 0
	}
	used := total - free
	gb := 1024.0 * 1024.0 * 1024.0
	return free / gb, used / gb, (1.0 - (free / total)) * 100.0
}

func reconstructionProgress(outDir string) (reconstructedFunctions int, reconClusters int, reconQueue int, reconFocus int, reconLift int, reconCompose int, reconImplQueue int, reconImplWork int, reconImplSynth int, reconImplSynthAvg float64, reconImplApplied int, reconFinalized int, reconStrong int, reconFallback int, reconTodoRemaining int, reconCompletion float64, reconSemantic float64, reconConformance float64, reconConformanceEval int, reconConformanceLow int) {
	type rebuildManifest struct {
		TotalFunctions int `json:"total_functions"`
	}
	type clusterManifest struct {
		ClusterCount int `json:"cluster_count"`
	}
	type queueManifest struct {
		QueueCount int `json:"queue_count"`
	}
	type focusManifest struct {
		BundleCount int `json:"bundle_count"`
	}
	type liftManifest struct {
		UnitCount int `json:"unit_count"`
	}
	type composeManifest struct {
		UnitCount             int `json:"unit_count"`
		ComposedFunctionCount int `json:"composed_function_count"`
	}
	type implQueueManifest struct {
		TaskCount int `json:"task_count"`
	}
	type implWorkManifest struct {
		WorkfileCount int `json:"workfile_count"`
	}
	type implSynthManifest struct {
		SynthCount       int     `json:"synth_count"`
		AvgCalleeEmitted string  `json:"avg_callee_emitted"`
		AvgCalleeFloat   float64 `json:"avg_callee_emitted_float"`
	}
	type implAppliedManifest struct {
		FunctionsApplied       int `json:"functions_applied"`
		UniqueFunctionsApplied int `json:"unique_functions_applied"`
	}
	type finalizeManifest struct {
		ImplementedCount      int     `json:"implemented_count"`
		StrongCount           int     `json:"strong_count"`
		FallbackCount         int     `json:"fallback_count"`
		TodoCount             int     `json:"todo_count"`
		CompletionPct         float64 `json:"completion_pct"`
		SemanticCompletionPct float64 `json:"semantic_completion_pct"`
	}
	type conformanceReport struct {
		EvaluableCount    int     `json:"evaluable_count"`
		AvgConformancePct float64 `json:"avg_conformance_pct"`
		Rows              []struct {
			EvidenceFound  bool    `json:"evidence_found"`
			ConformancePct float64 `json:"conformance_pct"`
		} `json:"rows"`
	}
	reconDir := filepath.Join(outDir, "reconstruction")
	var bestRebuild string
	var bestCluster string
	var bestQueue string
	var bestFocus string
	var bestLift string
	var bestCompose string
	var bestImplQueue string
	var bestImplWork string
	var bestImplSynth string
	var bestImplApplied string
	var bestFinalize string
	var bestConformance string
	var bestRebuildTime time.Time
	var bestClusterTime time.Time
	var bestQueueTime time.Time
	var bestFocusTime time.Time
	var bestLiftTime time.Time
	var bestComposeTime time.Time
	var bestImplQueueTime time.Time
	var bestImplWorkTime time.Time
	var bestImplSynthTime time.Time
	var bestImplAppliedTime time.Time
	var bestFinalizeTime time.Time
	var bestConformanceTime time.Time
	if cache, ok := loadManifestCache(reconDir); ok {
		bestRebuild = cache.Rebuild
		bestCluster = cache.Cluster
		bestQueue = cache.Queue
		bestFocus = cache.Focus
		bestLift = cache.Lift
		bestCompose = cache.Compose
		bestImplQueue = cache.ImplQueue
		bestImplWork = cache.ImplWork
		bestImplSynth = cache.ImplSynth
		bestImplApplied = cache.ImplApplied
		bestFinalize = cache.Finalize
		bestConformance = cache.Conformance
	} else {
		entries, err := os.ReadDir(reconDir)
		if err != nil {
			return 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		}
		for _, e := range entries {
			if !e.IsDir() {
				continue
			}
			rebuildPath := filepath.Join(reconDir, e.Name(), "rebuilt", "rebuild_manifest.json")
			if st, err := os.Stat(rebuildPath); err == nil && st.ModTime().After(bestRebuildTime) {
				bestRebuildTime = st.ModTime()
				bestRebuild = rebuildPath
			}
			clusterPath := filepath.Join(reconDir, e.Name(), "clusters", "cluster_manifest.json")
			if st, err := os.Stat(clusterPath); err == nil && st.ModTime().After(bestClusterTime) {
				bestClusterTime = st.ModTime()
				bestCluster = clusterPath
			}
			queuePath := filepath.Join(reconDir, e.Name(), "queue", "queue_manifest.json")
			if st, err := os.Stat(queuePath); err == nil && st.ModTime().After(bestQueueTime) {
				bestQueueTime = st.ModTime()
				bestQueue = queuePath
			}
			focusPath := filepath.Join(reconDir, e.Name(), "focus", "focus_manifest.json")
			if st, err := os.Stat(focusPath); err == nil && st.ModTime().After(bestFocusTime) {
				bestFocusTime = st.ModTime()
				bestFocus = focusPath
			}
			liftPath := filepath.Join(reconDir, e.Name(), "lift", "lift_manifest.json")
			if st, err := os.Stat(liftPath); err == nil && st.ModTime().After(bestLiftTime) {
				bestLiftTime = st.ModTime()
				bestLift = liftPath
			}
			composePath := filepath.Join(reconDir, e.Name(), "composed", "compose_manifest.json")
			if st, err := os.Stat(composePath); err == nil && st.ModTime().After(bestComposeTime) {
				bestComposeTime = st.ModTime()
				bestCompose = composePath
			}
			implQueuePath := filepath.Join(reconDir, e.Name(), "implqueue", "implqueue_manifest.json")
			if st, err := os.Stat(implQueuePath); err == nil && st.ModTime().After(bestImplQueueTime) {
				bestImplQueueTime = st.ModTime()
				bestImplQueue = implQueuePath
			}
			implWorkPath := filepath.Join(reconDir, e.Name(), "implwork", "implwork_manifest.json")
			if st, err := os.Stat(implWorkPath); err == nil && st.ModTime().After(bestImplWorkTime) {
				bestImplWorkTime = st.ModTime()
				bestImplWork = implWorkPath
			}
			implSynthPath := filepath.Join(reconDir, e.Name(), "synth", "implsynth_manifest.json")
			if st, err := os.Stat(implSynthPath); err == nil && st.ModTime().After(bestImplSynthTime) {
				bestImplSynthTime = st.ModTime()
				bestImplSynth = implSynthPath
			}
			implAppliedPath := filepath.Join(reconDir, e.Name(), "applied", "applysynth_manifest.json")
			if st, err := os.Stat(implAppliedPath); err == nil && st.ModTime().After(bestImplAppliedTime) {
				bestImplAppliedTime = st.ModTime()
				bestImplApplied = implAppliedPath
			}
			finalizePath := filepath.Join(reconDir, e.Name(), "final", "finalize_manifest.json")
			if st, err := os.Stat(finalizePath); err == nil && st.ModTime().After(bestFinalizeTime) {
				bestFinalizeTime = st.ModTime()
				bestFinalize = finalizePath
			}
			conformancePath := filepath.Join(reconDir, e.Name(), "final", "call_conformance.json")
			if st, err := os.Stat(conformancePath); err == nil && st.ModTime().After(bestConformanceTime) {
				bestConformanceTime = st.ModTime()
				bestConformance = conformancePath
			}
		}
		storeManifestCache(reconDir, manifestCache{
			Rebuild:     bestRebuild,
			Cluster:     bestCluster,
			Queue:       bestQueue,
			Focus:       bestFocus,
			Lift:        bestLift,
			Compose:     bestCompose,
			ImplQueue:   bestImplQueue,
			ImplWork:    bestImplWork,
			ImplSynth:   bestImplSynth,
			ImplApplied: bestImplApplied,
			Finalize:    bestFinalize,
			Conformance: bestConformance,
		})
	}
	if bestRebuild != "" {
		var m rebuildManifest
		if b, err := os.ReadFile(bestRebuild); err == nil && json.Unmarshal(b, &m) == nil {
			reconstructedFunctions = m.TotalFunctions
		}
	}
	if bestCluster != "" {
		var m clusterManifest
		if b, err := os.ReadFile(bestCluster); err == nil && json.Unmarshal(b, &m) == nil {
			reconClusters = m.ClusterCount
		}
	}
	if bestQueue != "" {
		var m queueManifest
		if b, err := os.ReadFile(bestQueue); err == nil && json.Unmarshal(b, &m) == nil {
			reconQueue = m.QueueCount
		}
	}
	if bestFocus != "" {
		var m focusManifest
		if b, err := os.ReadFile(bestFocus); err == nil && json.Unmarshal(b, &m) == nil {
			reconFocus = m.BundleCount
		}
	}
	if bestLift != "" {
		var m liftManifest
		if b, err := os.ReadFile(bestLift); err == nil && json.Unmarshal(b, &m) == nil {
			reconLift = m.UnitCount
		}
	}
	if bestCompose != "" {
		var m composeManifest
		if b, err := os.ReadFile(bestCompose); err == nil && json.Unmarshal(b, &m) == nil {
			if m.ComposedFunctionCount > 0 {
				reconCompose = m.ComposedFunctionCount
			} else {
				reconCompose = m.UnitCount
			}
		}
	}
	if bestImplQueue != "" {
		var m implQueueManifest
		if b, err := os.ReadFile(bestImplQueue); err == nil && json.Unmarshal(b, &m) == nil {
			reconImplQueue = m.TaskCount
		}
	}
	if bestImplWork != "" {
		var m implWorkManifest
		if b, err := os.ReadFile(bestImplWork); err == nil && json.Unmarshal(b, &m) == nil {
			reconImplWork = m.WorkfileCount
		}
	}
	if bestImplSynth != "" {
		var m implSynthManifest
		if b, err := os.ReadFile(bestImplSynth); err == nil && json.Unmarshal(b, &m) == nil {
			reconImplSynth = m.SynthCount
			if m.AvgCalleeFloat > 0 {
				reconImplSynthAvg = m.AvgCalleeFloat
			} else if m.AvgCalleeEmitted != "" {
				var parsed float64
				if _, err := fmt.Sscanf(m.AvgCalleeEmitted, "%f", &parsed); err == nil {
					reconImplSynthAvg = parsed
				}
			}
		}
	}
	if bestImplApplied != "" {
		var m implAppliedManifest
		if b, err := os.ReadFile(bestImplApplied); err == nil && json.Unmarshal(b, &m) == nil {
			if m.UniqueFunctionsApplied > 0 {
				reconImplApplied = m.UniqueFunctionsApplied
			} else {
				reconImplApplied = m.FunctionsApplied
			}
		}
	}
	if bestFinalize != "" {
		var m finalizeManifest
		if b, err := os.ReadFile(bestFinalize); err == nil && json.Unmarshal(b, &m) == nil {
			reconFinalized = m.ImplementedCount
			reconStrong = m.StrongCount
			reconFallback = m.FallbackCount
			reconTodoRemaining = m.TodoCount
			reconCompletion = m.CompletionPct
			reconSemantic = m.SemanticCompletionPct
		}
	}
	if bestConformance != "" {
		var m conformanceReport
		if b, err := os.ReadFile(bestConformance); err == nil && json.Unmarshal(b, &m) == nil {
			reconConformance = m.AvgConformancePct
			reconConformanceEval = m.EvaluableCount
			for _, r := range m.Rows {
				if r.EvidenceFound && r.ConformancePct < 100.0 {
					reconConformanceLow++
				}
			}
		}
	}
	return reconstructedFunctions, reconClusters, reconQueue, reconFocus, reconLift, reconCompose, reconImplQueue, reconImplWork, reconImplSynth, reconImplSynthAvg, reconImplApplied, reconFinalized, reconStrong, reconFallback, reconTodoRemaining, reconCompletion, reconSemantic, reconConformance, reconConformanceEval, reconConformanceLow
}

type manifestCache struct {
	Rebuild     string `json:"rebuild"`
	Cluster     string `json:"cluster"`
	Queue       string `json:"queue"`
	Focus       string `json:"focus"`
	Lift        string `json:"lift"`
	Compose     string `json:"compose"`
	ImplQueue   string `json:"implqueue"`
	ImplWork    string `json:"implwork"`
	ImplSynth   string `json:"implsynth"`
	ImplApplied string `json:"implapplied"`
	Finalize    string `json:"finalize"`
	Conformance string `json:"conformance"`
}

func manifestCachePath(reconDir string) string {
	return filepath.Join(reconDir, "latest_manifests.json")
}

func loadManifestCache(reconDir string) (manifestCache, bool) {
	path := manifestCachePath(reconDir)
	b, err := os.ReadFile(path)
	if err != nil {
		return manifestCache{}, false
	}
	var c manifestCache
	if err := json.Unmarshal(b, &c); err != nil {
		return manifestCache{}, false
	}
	for _, p := range []string{c.Rebuild, c.Cluster, c.Queue, c.Focus, c.Lift, c.Compose, c.ImplQueue, c.ImplWork, c.ImplSynth, c.ImplApplied, c.Finalize, c.Conformance} {
		if strings.TrimSpace(p) == "" {
			continue
		}
		if _, err := os.Stat(p); err != nil {
			return manifestCache{}, false
		}
	}
	return c, true
}

func storeManifestCache(reconDir string, c manifestCache) {
	_ = fileio.WriteJSON(manifestCachePath(reconDir), c)
}
