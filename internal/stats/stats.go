package stats

import (
	"bufio"
	"bytes"
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
	ReconReports          map[string]bool `json:"recon_reports"`
	BaseFunctionEstimate  int             `json:"base_function_estimate"`
	BaseNamedFunctions    int             `json:"base_named_functions"`
	BaseCoveragePct       float64         `json:"base_coverage_pct"`
	LinkedSourceFunctions int             `json:"linked_source_functions"`
	LinkCoveragePct       float64         `json:"link_coverage_pct"`
	ReconstructedFuncs    int             `json:"reconstructed_functions"`
	ReconClusterCount     int             `json:"recon_cluster_count"`
	ReconQueueCount       int             `json:"recon_queue_count"`
	ReconFocusCount       int             `json:"recon_focus_count"`
	ReconLiftCount        int             `json:"recon_lift_count"`
	ReconComposeCount     int             `json:"recon_compose_count"`
	ReconImplQueueCount   int             `json:"recon_implqueue_count"`
	ReconImplWorkCount    int             `json:"recon_implwork_count"`
	ReconImplSynthCount   int             `json:"recon_implsynth_count"`
	ReconImplSynthAvgCall float64         `json:"recon_implsynth_avg_callees"`
	ReconImplAppliedCount int             `json:"recon_implapplied_count"`
	ReconFinalizedCount   int             `json:"recon_finalized_count"`
	ReconStrongCount      int             `json:"recon_strong_count"`
	ReconFallbackCount    int             `json:"recon_fallback_count"`
	ReconTodoRemaining    int             `json:"recon_todo_remaining"`
	ReconCompletionPct    float64         `json:"recon_completion_pct"`
	ReconSemanticPct      float64         `json:"recon_semantic_completion_pct"`
	ReconConformancePct   float64         `json:"recon_conformance_pct"`
	ReconConformanceEval  int             `json:"recon_conformance_evaluable"`
	ReconConformanceLow   int             `json:"recon_conformance_nonperfect"`
	PatchMMIOPct          float64         `json:"patch_mmio_pct"`
	DataFreshnessSec      *int64          `json:"data_freshness_sec"`
	DiskFreeGB            float64         `json:"disk_free_gb"`
	DiskUsedGB            float64         `json:"disk_used_gb"`
	DiskUsePct            float64         `json:"disk_use_pct"`
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

	var newestInput time.Time
	read := func(name string) []map[string]any {
		path := filepath.Join(outAbs, name)
		if st, err := os.Stat(path); err == nil && st.Mode().IsRegular() && st.ModTime().After(newestInput) {
			newestInput = st.ModTime()
		}
		return readJSONLMaps(path)
	}
	images := read("images.jsonl")
	funcs := read("functions.jsonl")
	arts := read("artifacts.jsonl")
	links := read("function_links.jsonl")
	calls := read("call_edges.jsonl")
	msgs := read("message_schema.jsonl")
	sm := read("state_machines.jsonl")
	queue := read("mining_queue.jsonl")
	patches := read("patch_entries.jsonl")

	snap.Totals = Totals{len(images), len(funcs), len(arts), len(links), len(calls), len(msgs), len(sm), len(queue), len(patches)}

	baseNamed := 0
	srcLinked := map[string]struct{}{}
	fnRole := map[string]int{}
	fnSource := map[string]int{}
	fnImage := map[string]int{}
	aliasCount := 0
	fnConf := make([]float64, 0, len(funcs))
	for _, r := range funcs {
		fnConf = append(fnConf, flt(r["confidence"]))
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
	linkedFns := map[string]int{}
	linkConf := make([]float64, 0, len(links))
	for _, r := range links {
		linkConf = append(linkConf, flt(r["confidence"]))
		linkedFns[funcKey(str(r["source_name"]), str(r["source_image"]), str(r["source_address"]))]++
		linkMethods[keyOrUnknown(str(r["method"]))]++
		linkTargets[keyOrUnknown(str(r["target_image"]))]++
		srcFns[keyOrUnknown(str(r["source_image"])+"|"+str(r["source_address"]))] = struct{}{}
		tgtFns[keyOrUnknown(str(r["target_image"])+"|"+str(r["target_address"]))] = struct{}{}
		if flt(r["confidence"]) >= 0.9 {
			highLinks++
		}
	}

	callSrc := map[string]int{}
	callTgt := map[string]int{}
	callSrcName := map[string]int{}
	callTgtName := map[string]int{}
	callConf := make([]float64, 0, len(calls))
	for _, r := range calls {
		img := str(r["image"])
		callConf = append(callConf, flt(r["confidence"]))
		callSrc[funcKey("", img, str(r["source_addr"]))]++
		callTgt[funcKey("", img, str(r["target_addr"]))]++
		callSrcName[funcKey(str(r["source_name"]), img, str(r["source_addr"]))]++
		callTgtName[funcKey(str(r["target_name"]), img, str(r["target_addr"]))]++
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

	snap.Progress = Progress{
		BaseFunctionEstimate:  baseFunctionEstimate,
		BaseNamedFunctions:    baseNamed,
		BaseCoveragePct:       round3(baseCoverage),
		LinkedSourceFunctions: len(srcLinked),
		LinkCoveragePct:       round3(linkCoverage),
		PatchMMIOPct:          round3(patchMMIOPct),
		DiskFreeGB:            round3(freeGB),
		DiskUsedGB:            round3(usedGB),
		DiskUsePct:            round3(usePct),
	}
	collectReconstructionProgress(outAbs, &snap.Progress)
	if !newestInput.IsZero() {
		age := max(int64(0), int64(time.Since(newestInput)/time.Second))
		snap.Progress.DataFreshnessSec = &age
	}
	snap.Functions = FunctionStats{round3(mean(fnConf)), fnRole["unknown"], aliasCount, toPairs(fnRole), toPairs(fnSource), toPairs(fnImage), confidenceBuckets(fnConf), toPairs(fnImage)}
	snap.Artifacts = ArtifactStats{toPairs(artType), toPairs(artImg), len(mmioRefs), len(patchTags), vectorCount}
	snap.Links = LinkStats{round3(mean(linkConf)), toPairs(linkMethods), toPairs(linkTargets), confidenceBuckets(linkConf), len(srcFns), len(tgtFns), highLinks}
	snap.Calls = CallStats{topNPairs(callSrc, 25), topNPairs(callTgt, 25), topNPairs(callSrcName, 25), topNPairs(callTgtName, 25), round3(mean(callConf))}
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
	snap.Top = TopLists{topNPairs(linkedFns, 25), topNPairs(msgFamily, 25), topNPairs(smMachine, 25), topNPairs(callSrcName, 25), topNPairs(queueReasons, 25), topNPairs(patchSect, 25), topNPairs(fnRole, 25), topNPairs(artType, 25)}
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

// funcKey labels a function by name, falling back to image|address.
func funcKey(name, image, addr string) string {
	if name != "" {
		return name
	}
	if image == "" && addr == "" {
		return "unknown"
	}
	return image + "|" + addr
}

func mean(vals []float64) float64 {
	if len(vals) == 0 {
		return 0
	}
	sum := 0.0
	for _, v := range vals {
		sum += v
	}
	return sum / float64(len(vals))
}

// confidenceBuckets groups [0,1] confidences into fixed 0.2-wide buckets, in bucket order.
func confidenceBuckets(vals []float64) []CountPair {
	if len(vals) == 0 {
		return nil
	}
	labels := []string{"0.0-0.2", "0.2-0.4", "0.4-0.6", "0.6-0.8", "0.8-1.0"}
	counts := make([]int, len(labels))
	for _, v := range vals {
		i := int(v * 5)
		if i < 0 {
			i = 0
		}
		if i >= len(labels) {
			i = len(labels) - 1
		}
		counts[i]++
	}
	rows := make([]CountPair, len(labels))
	for i, l := range labels {
		rows[i] = CountPair{Key: l, Count: counts[i]}
	}
	return rows
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

func collectReconstructionProgress(outDir string, p *Progress) {
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
	p.ReconReports = make(map[string]bool)
	entries, _ := os.ReadDir(reconDir)
	readLatest := func(stage, relativePath string, m any) bool {
		var latest string
		var newest time.Time
		for _, e := range entries {
			if !e.IsDir() {
				continue
			}
			path := filepath.Join(reconDir, e.Name(), relativePath)
			if st, err := os.Stat(path); err == nil && st.Mode().IsRegular() && st.ModTime().After(newest) {
				latest, newest = path, st.ModTime()
			}
		}
		if latest == "" {
			return false
		}
		b, err := os.ReadFile(latest)
		b = bytes.TrimSpace(b)
		if err != nil || len(b) == 0 || b[0] != '{' || json.Unmarshal(b, m) != nil {
			return false
		}
		p.ReconReports[stage] = true
		return true
	}
	var rebuild rebuildManifest
	if readLatest("rebuild", "rebuilt/rebuild_manifest.json", &rebuild) {
		p.ReconstructedFuncs = rebuild.TotalFunctions
	}
	var cluster clusterManifest
	if readLatest("cluster", "clusters/cluster_manifest.json", &cluster) {
		p.ReconClusterCount = cluster.ClusterCount
	}
	var queue queueManifest
	if readLatest("queue", "queue/queue_manifest.json", &queue) {
		p.ReconQueueCount = queue.QueueCount
	}
	var focus focusManifest
	if readLatest("focus", "focus/focus_manifest.json", &focus) {
		p.ReconFocusCount = focus.BundleCount
	}
	var lift liftManifest
	if readLatest("lift", "lift/lift_manifest.json", &lift) {
		p.ReconLiftCount = lift.UnitCount
	}
	var compose composeManifest
	if readLatest("compose", "composed/compose_manifest.json", &compose) {
		p.ReconComposeCount = compose.ComposedFunctionCount
		if p.ReconComposeCount <= 0 {
			p.ReconComposeCount = compose.UnitCount
		}
	}
	var queueImpl implQueueManifest
	if readLatest("implqueue", "implqueue/implqueue_manifest.json", &queueImpl) {
		p.ReconImplQueueCount = queueImpl.TaskCount
	}
	var work implWorkManifest
	if readLatest("implwork", "implwork/implwork_manifest.json", &work) {
		p.ReconImplWorkCount = work.WorkfileCount
	}
	var synth implSynthManifest
	if readLatest("implsynth", "synth/implsynth_manifest.json", &synth) {
		p.ReconImplSynthCount = synth.SynthCount
		avg := synth.AvgCalleeFloat
		if avg <= 0 && synth.AvgCalleeEmitted != "" {
			fmt.Sscanf(synth.AvgCalleeEmitted, "%f", &avg)
		}
		p.ReconImplSynthAvgCall = round3(avg)
	}
	var applied implAppliedManifest
	if readLatest("implapplied", "applied/applysynth_manifest.json", &applied) {
		p.ReconImplAppliedCount = applied.UniqueFunctionsApplied
		if p.ReconImplAppliedCount <= 0 {
			p.ReconImplAppliedCount = applied.FunctionsApplied
		}
	}
	var final finalizeManifest
	if readLatest("finalize", "final/finalize_manifest.json", &final) {
		p.ReconFinalizedCount = final.ImplementedCount
		p.ReconStrongCount = final.StrongCount
		p.ReconFallbackCount = final.FallbackCount
		p.ReconTodoRemaining = final.TodoCount
		p.ReconCompletionPct = round3(final.CompletionPct)
		p.ReconSemanticPct = round3(final.SemanticCompletionPct)
	}
	var conf conformanceReport
	if readLatest("conformance", "final/call_conformance.json", &conf) {
		p.ReconConformancePct = round3(conf.AvgConformancePct)
		p.ReconConformanceEval = conf.EvaluableCount
		for _, r := range conf.Rows {
			if r.EvidenceFound && r.ConformancePct < 100.0 {
				p.ReconConformanceLow++
			}
		}
	}
}
