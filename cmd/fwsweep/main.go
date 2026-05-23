package main

import (
	"bufio"
	"encoding/json"
	"flag"
	"fmt"
	"hash/fnv"
	"os"
	"path/filepath"
	"sort"
	"strconv"
	"strings"
	"time"

	"aic8800d80/internal/pipeline"
)

type unionRecord struct {
	pipeline.MiningTargetRecord
	SeenInRuns  []string `json:"seen_in_runs"`
	SeenCount   int      `json:"seen_count"`
	BestScoreAt string   `json:"best_score_at"`
}

func main() {
	var root string
	var outDir string
	var minStringLen int
	var embeddingModel string
	var queueLimit int
	var thresholdsCSV string
	var runTagPrefix string
	var impactMinScore float64
	var impactMinSeen int
	var actionableTopN int
	var packSize int
	var neighborMax string
	var neighborStep string
	var keepSweeps int
	var keepRuns int
	var unionShards int
	var leanRuns bool

	flag.StringVar(&root, "root", ".", "Workspace root containing firmware blobs")
	flag.StringVar(&outDir, "out", "extraction_out", "Output directory for JSONL artifacts")
	flag.IntVar(&minStringLen, "min-string-len", 4, "Minimum printable ASCII string length")
	flag.StringVar(&embeddingModel, "embedding-model", "", "Optional GGUF embedding model path")
	flag.IntVar(&queueLimit, "queue-limit", 0, "Maximum mining queue entries to emit (0 = no limit)")
	flag.StringVar(&thresholdsCSV, "thresholds", "0.6,0.8,1.0,1.2", "Comma-separated queue min-score sweep values")
	flag.StringVar(&runTagPrefix, "run-tag-prefix", "sweep", "Run tag prefix for namespaced outputs")
	flag.Float64Var(&impactMinScore, "impact-min-score", 2.0, "Minimum score for high-impact frontier output")
	flag.IntVar(&impactMinSeen, "impact-min-seen", 2, "Minimum sweep-run coverage for high-impact frontier output")
	flag.IntVar(&actionableTopN, "actionable-top-n", 200, "Number of top actionable targets to emit")
	flag.IntVar(&packSize, "pack-size", 500, "Targets per shard pack for parallel triage")
	flag.StringVar(&neighborMax, "neighbor-max", "", "Optional FW_MINING_NEIGHBOR_MAX override (e.g. 0x300)")
	flag.StringVar(&neighborStep, "neighbor-step", "", "Optional FW_MINING_NEIGHBOR_STEP override (e.g. 1)")
	flag.IntVar(&keepSweeps, "keep-sweeps", 3, "Keep only newest N sweep groups for this prefix (0 disables cleanup)")
	flag.IntVar(&keepRuns, "keep-runs", 4, "Keep only newest N run directories for this prefix (0 disables cleanup)")
	flag.IntVar(&unionShards, "union-shards", 128, "Shard count for disk-backed union merge (higher = lower peak memory)")
	flag.BoolVar(&leanRuns, "lean-runs", false, "Delete bulky per-run artifacts after sweep aggregation to save disk")
	flag.Parse()

	thresholds, err := parseThresholds(thresholdsCSV)
	if err != nil {
		fmt.Fprintf(os.Stderr, "invalid thresholds: %v\n", err)
		os.Exit(1)
	}

	runBase := time.Now().UTC().Format("20060102T150405Z")
	if strings.TrimSpace(neighborMax) != "" {
		_ = os.Setenv("FW_MINING_NEIGHBOR_MAX", strings.TrimSpace(neighborMax))
	}
	if strings.TrimSpace(neighborStep) != "" {
		_ = os.Setenv("FW_MINING_NEIGHBOR_STEP", strings.TrimSpace(neighborStep))
	}
	runTags := make([]string, 0, len(thresholds))
	perRunCounts := make(map[string]int, len(thresholds))
	for _, th := range thresholds {
		scoreTag := strings.ReplaceAll(strings.TrimRight(strings.TrimRight(fmt.Sprintf("%.2f", th), "0"), "."), ".", "p")
		runTag := fmt.Sprintf("%s_%s_s%s", sanitize(runTagPrefix), runBase, scoreTag)
		runTags = append(runTags, runTag)
		result, err := pipeline.Run(root, outDir, minStringLen, embeddingModel, queueLimit, th, runTag)
		if err != nil {
			fmt.Fprintf(os.Stderr, "pipeline sweep run failed (threshold=%.2f, tag=%s): %v\n", th, runTag, err)
			os.Exit(1)
		}
		perRunCounts[runTag] = result.MiningQueueCount
		fmt.Printf("run complete: threshold=%.2f tag=%s queue=%d\n", th, runTag, result.MiningQueueCount)
	}

	outAbs, err := filepath.Abs(outDir)
	if err != nil {
		fmt.Fprintf(os.Stderr, "resolve out dir: %v\n", err)
		os.Exit(1)
	}

	outRows, err := buildUnionRowsSharded(outAbs, sanitize(runTagPrefix), runBase, runTags, unionShards)
	if err != nil {
		fmt.Fprintf(os.Stderr, "build sharded union: %v\n", err)
		os.Exit(1)
	}
	sort.Slice(outRows, func(i, j int) bool {
		if outRows[i].PriorityScore == outRows[j].PriorityScore {
			if outRows[i].SeenCount == outRows[j].SeenCount {
				return outRows[i].Address < outRows[j].Address
			}
			return outRows[i].SeenCount > outRows[j].SeenCount
		}
		return outRows[i].PriorityScore > outRows[j].PriorityScore
	})

	unionDir := filepath.Join(outAbs, "sweeps")
	if err := os.MkdirAll(unionDir, 0o755); err != nil {
		fmt.Fprintf(os.Stderr, "create sweep dir: %v\n", err)
		os.Exit(1)
	}
	unionPath := filepath.Join(unionDir, fmt.Sprintf("%s_%s_union.jsonl", sanitize(runTagPrefix), runBase))
	if err := writeJSONL(unionPath, outRows); err != nil {
		fmt.Fprintf(os.Stderr, "write union: %v\n", err)
		os.Exit(1)
	}
	highImpact := buildHighImpact(outRows, impactMinScore, impactMinSeen)
	impactPath := filepath.Join(unionDir, fmt.Sprintf("%s_%s_high_impact.jsonl", sanitize(runTagPrefix), runBase))
	if err := writeJSONL(impactPath, highImpact); err != nil {
		fmt.Fprintf(os.Stderr, "write high-impact: %v\n", err)
		os.Exit(1)
	}
	hotspots := buildHotspots(outRows, highImpact)
	hotspotsPath := filepath.Join(unionDir, fmt.Sprintf("%s_%s_hotspots.json", sanitize(runTagPrefix), runBase))
	if err := writeJSON(hotspotsPath, hotspots); err != nil {
		fmt.Fprintf(os.Stderr, "write hotspots: %v\n", err)
		os.Exit(1)
	}
	actionable := buildTopActionable(highImpact, actionableTopN)
	actionablePath := filepath.Join(unionDir, fmt.Sprintf("%s_%s_top_actionable.jsonl", sanitize(runTagPrefix), runBase))
	if err := writeJSONL(actionablePath, actionable); err != nil {
		fmt.Fprintf(os.Stderr, "write actionable: %v\n", err)
		os.Exit(1)
	}
	core, aggressive, experimental := buildTiers(outRows, len(runTags))
	reconStrict, reconAggressive := buildReconLanes(outRows, len(runTags))
	corePath := filepath.Join(unionDir, fmt.Sprintf("%s_%s_tier_core.jsonl", sanitize(runTagPrefix), runBase))
	aggrPath := filepath.Join(unionDir, fmt.Sprintf("%s_%s_tier_aggressive.jsonl", sanitize(runTagPrefix), runBase))
	expPath := filepath.Join(unionDir, fmt.Sprintf("%s_%s_tier_experimental.jsonl", sanitize(runTagPrefix), runBase))
	reconStrictPath := filepath.Join(unionDir, fmt.Sprintf("%s_%s_recon_strict.jsonl", sanitize(runTagPrefix), runBase))
	reconAggPath := filepath.Join(unionDir, fmt.Sprintf("%s_%s_recon_aggressive.jsonl", sanitize(runTagPrefix), runBase))
	if err := writeJSONL(corePath, core); err != nil {
		fmt.Fprintf(os.Stderr, "write core tier: %v\n", err)
		os.Exit(1)
	}
	if err := writeJSONL(aggrPath, aggressive); err != nil {
		fmt.Fprintf(os.Stderr, "write aggressive tier: %v\n", err)
		os.Exit(1)
	}
	if err := writeJSONL(expPath, experimental); err != nil {
		fmt.Fprintf(os.Stderr, "write experimental tier: %v\n", err)
		os.Exit(1)
	}
	if err := writeJSONL(reconStrictPath, reconStrict); err != nil {
		fmt.Fprintf(os.Stderr, "write recon strict lane: %v\n", err)
		os.Exit(1)
	}
	if err := writeJSONL(reconAggPath, reconAggressive); err != nil {
		fmt.Fprintf(os.Stderr, "write recon aggressive lane: %v\n", err)
		os.Exit(1)
	}
	reconUnits := buildReconUnits(reconStrict, reconAggressive, actionable)
	reconUnitsPath := filepath.Join(unionDir, fmt.Sprintf("%s_%s_recon_units.jsonl", sanitize(runTagPrefix), runBase))
	if err := writeJSONL(reconUnitsPath, reconUnits); err != nil {
		fmt.Fprintf(os.Stderr, "write recon units: %v\n", err)
		os.Exit(1)
	}
	reconBatchSummary, err := writeReconBatches(unionDir, sanitize(runTagPrefix), runBase, reconUnits, packSize)
	if err != nil {
		fmt.Fprintf(os.Stderr, "write recon batches: %v\n", err)
		os.Exit(1)
	}
	packSummary, err := writeShardPacks(unionDir, sanitize(runTagPrefix), runBase, aggressive, packSize)
	if err != nil {
		fmt.Fprintf(os.Stderr, "write shard packs: %v\n", err)
		os.Exit(1)
	}

	summary := map[string]any{
		"schema_version": "0.1.0",
		"generated_at":   time.Now().UTC().Format(time.RFC3339),
		"run_base":       runBase,
		"run_tags":       runTags,
		"thresholds":     thresholds,
		"neighbor_max":   strings.TrimSpace(neighborMax),
		"neighbor_step":  strings.TrimSpace(neighborStep),
		"per_run_counts": perRunCounts,
		"union_count":    len(outRows),
		"union_path":     unionPath,
		"high_impact": map[string]any{
			"count":         len(highImpact),
			"path":          impactPath,
			"min_score":     impactMinScore,
			"min_seen_runs": impactMinSeen,
		},
		"hotspots_path": hotspotsPath,
		"top_actionable": map[string]any{
			"count": len(actionable),
			"path":  actionablePath,
		},
		"tiers": map[string]any{
			"core":         map[string]any{"count": len(core), "path": corePath},
			"aggressive":   map[string]any{"count": len(aggressive), "path": aggrPath},
			"experimental": map[string]any{"count": len(experimental), "path": expPath},
		},
		"recon_lanes": map[string]any{
			"strict":     map[string]any{"count": len(reconStrict), "path": reconStrictPath},
			"aggressive": map[string]any{"count": len(reconAggressive), "path": reconAggPath},
		},
		"recon_units": map[string]any{
			"count": len(reconUnits),
			"path":  reconUnitsPath,
		},
		"recon_batches": reconBatchSummary,
		"shard_packs":   packSummary,
	}
	summaryPath := filepath.Join(unionDir, fmt.Sprintf("%s_%s_summary.json", sanitize(runTagPrefix), runBase))
	if err := writeJSON(summaryPath, summary); err != nil {
		fmt.Fprintf(os.Stderr, "write summary: %v\n", err)
		os.Exit(1)
	}
	leanDeleted := 0
	if leanRuns {
		n, leanErr := pruneRunArtifacts(outAbs, runTags)
		if leanErr != nil {
			fmt.Fprintf(os.Stderr, "lean-runs warning: %v\n", leanErr)
		}
		leanDeleted = n
	}
	deletedSweeps, deletedRuns, retentionErr := applyRetention(outAbs, sanitize(runTagPrefix), keepSweeps, keepRuns)
	if retentionErr != nil {
		fmt.Fprintf(os.Stderr, "retention warning: %v\n", retentionErr)
	}

	fmt.Printf("sweep complete.\n")
	fmt.Printf("  runs: %d\n", len(runTags))
	fmt.Printf("  union_count: %d\n", len(outRows))
	fmt.Printf("  high_impact_count: %d\n", len(highImpact))
	fmt.Printf("  top_actionable_count: %d\n", len(actionable))
	fmt.Printf("  tier_core_count: %d\n", len(core))
	fmt.Printf("  tier_aggressive_count: %d\n", len(aggressive))
	fmt.Printf("  tier_experimental_count: %d\n", len(experimental))
	fmt.Printf("  recon_strict_count: %d\n", len(reconStrict))
	fmt.Printf("  recon_aggressive_count: %d\n", len(reconAggressive))
	fmt.Printf("  recon_units_count: %d\n", len(reconUnits))
	fmt.Printf("  recon_batch_count: %v\n", reconBatchSummary["batch_count"])
	fmt.Printf("  shard_pack_count: %v\n", packSummary["pack_count"])
	fmt.Printf("  union_path: %s\n", unionPath)
	fmt.Printf("  high_impact_path: %s\n", impactPath)
	fmt.Printf("  hotspots_path: %s\n", hotspotsPath)
	fmt.Printf("  top_actionable_path: %s\n", actionablePath)
	fmt.Printf("  tier_core_path: %s\n", corePath)
	fmt.Printf("  tier_aggressive_path: %s\n", aggrPath)
	fmt.Printf("  tier_experimental_path: %s\n", expPath)
	fmt.Printf("  recon_strict_path: %s\n", reconStrictPath)
	fmt.Printf("  recon_aggressive_path: %s\n", reconAggPath)
	fmt.Printf("  recon_units_path: %s\n", reconUnitsPath)
	fmt.Printf("  recon_batches_manifest_path: %v\n", reconBatchSummary["manifest_path"])
	fmt.Printf("  shard_manifest_path: %v\n", packSummary["manifest_path"])
	fmt.Printf("  retention_deleted_sweeps: %d\n", deletedSweeps)
	fmt.Printf("  retention_deleted_runs: %d\n", deletedRuns)
	fmt.Printf("  lean_deleted_files: %d\n", leanDeleted)
	fmt.Printf("  summary_path: %s\n", summaryPath)
}

type shardEntry struct {
	RunTag string                      `json:"run_tag"`
	Record pipeline.MiningTargetRecord `json:"record"`
}

func buildUnionRowsSharded(outAbs, prefix, runBase string, runTags []string, shardCount int) ([]unionRecord, error) {
	if shardCount < 1 {
		shardCount = 1
	}
	tmpDir := filepath.Join(outAbs, "sweeps", fmt.Sprintf(".tmp_%s_%s", prefix, runBase))
	if err := os.MkdirAll(tmpDir, 0o755); err != nil {
		return nil, err
	}
	defer os.RemoveAll(tmpDir)

	type shardWriter struct {
		file *os.File
		bw   *bufio.Writer
		enc  *json.Encoder
	}
	writers := make([]*shardWriter, shardCount)
	openWriter := func(i int) (*shardWriter, error) {
		if writers[i] != nil {
			return writers[i], nil
		}
		p := filepath.Join(tmpDir, fmt.Sprintf("shard_%04d.jsonl", i))
		f, err := os.Create(p)
		if err != nil {
			return nil, err
		}
		bw := bufio.NewWriterSize(f, 1024*1024)
		w := &shardWriter{file: f, bw: bw, enc: json.NewEncoder(bw)}
		writers[i] = w
		return w, nil
	}

	for _, runTag := range runTags {
		path := filepath.Join(outAbs, "runs", runTag, "mining_queue_full.jsonl")
		if err := streamMiningQueue(path, func(r pipeline.MiningTargetRecord) error {
			k := strings.ToLower(r.Image + "|" + r.Address + "|" + r.Name)
			idx := shardIndex(k, shardCount)
			w, err := openWriter(idx)
			if err != nil {
				return err
			}
			return w.enc.Encode(shardEntry{RunTag: runTag, Record: r})
		}); err != nil {
			return nil, fmt.Errorf("read queue %s: %w", path, err)
		}
	}
	for _, w := range writers {
		if w == nil {
			continue
		}
		if err := w.bw.Flush(); err != nil {
			return nil, err
		}
		if err := w.file.Close(); err != nil {
			return nil, err
		}
	}

	outRows := make([]unionRecord, 0, 4096)
	for i := 0; i < shardCount; i++ {
		p := filepath.Join(tmpDir, fmt.Sprintf("shard_%04d.jsonl", i))
		f, err := os.Open(p)
		if err != nil {
			if os.IsNotExist(err) {
				continue
			}
			return nil, err
		}
		s := bufio.NewScanner(f)
		s.Buffer(make([]byte, 4096), 8*1024*1024)
		union := make(map[string]unionRecord, 4096)
		for s.Scan() {
			line := strings.TrimSpace(s.Text())
			if line == "" {
				continue
			}
			var e shardEntry
			if err := json.Unmarshal([]byte(line), &e); err != nil {
				_ = f.Close()
				return nil, err
			}
			r := e.Record
			key := strings.ToLower(r.Image + "|" + r.Address + "|" + r.Name)
			cur, ok := union[key]
			if !ok {
				union[key] = unionRecord{
					MiningTargetRecord: r,
					SeenInRuns:         []string{e.RunTag},
					SeenCount:          1,
					BestScoreAt:        e.RunTag,
				}
				continue
			}
			if r.PriorityScore > cur.PriorityScore {
				cur.MiningTargetRecord = r
				cur.BestScoreAt = e.RunTag
			}
			if !contains(cur.SeenInRuns, e.RunTag) {
				cur.SeenInRuns = append(cur.SeenInRuns, e.RunTag)
				cur.SeenCount++
			}
			union[key] = cur
		}
		if err := s.Err(); err != nil {
			_ = f.Close()
			return nil, err
		}
		_ = f.Close()
		for _, r := range union {
			sort.Strings(r.SeenInRuns)
			outRows = append(outRows, r)
		}
	}
	return outRows, nil
}

func shardIndex(key string, shardCount int) int {
	h := fnv.New32a()
	_, _ = h.Write([]byte(key))
	return int(h.Sum32() % uint32(shardCount))
}

func buildHighImpact(rows []unionRecord, minScore float64, minSeen int) []unionRecord {
	out := make([]unionRecord, 0, len(rows))
	for _, r := range rows {
		if r.PriorityScore < minScore {
			continue
		}
		if r.SeenCount < minSeen {
			continue
		}
		out = append(out, r)
	}
	return out
}

func buildHotspots(all []unionRecord, high []unionRecord) map[string]any {
	roleCounts := map[string]int{}
	reasonCounts := map[string]int{}
	seenCounts := map[int]int{}
	for _, r := range all {
		roleCounts[r.Role]++
		seenCounts[r.SeenCount]++
		for _, reason := range r.Reasons {
			reasonCounts[reason]++
		}
	}
	highRoleCounts := map[string]int{}
	highReasonCounts := map[string]int{}
	for _, r := range high {
		highRoleCounts[r.Role]++
		for _, reason := range r.Reasons {
			highReasonCounts[reason]++
		}
	}
	top := func(m map[string]int, n int) []map[string]any {
		type kv struct {
			k string
			v int
		}
		items := make([]kv, 0, len(m))
		for k, v := range m {
			items = append(items, kv{k: k, v: v})
		}
		sort.Slice(items, func(i, j int) bool {
			if items[i].v == items[j].v {
				return items[i].k < items[j].k
			}
			return items[i].v > items[j].v
		})
		if len(items) > n {
			items = items[:n]
		}
		out := make([]map[string]any, 0, len(items))
		for _, it := range items {
			out = append(out, map[string]any{"key": it.k, "count": it.v})
		}
		return out
	}
	seenHist := make([]map[string]any, 0, len(seenCounts))
	seenKeys := make([]int, 0, len(seenCounts))
	for k := range seenCounts {
		seenKeys = append(seenKeys, k)
	}
	sort.Ints(seenKeys)
	for _, k := range seenKeys {
		seenHist = append(seenHist, map[string]any{"seen_runs": k, "count": seenCounts[k]})
	}
	return map[string]any{
		"schema_version":    "0.1.0",
		"total_targets":     len(all),
		"high_impact_count": len(high),
		"top_roles":         top(roleCounts, 15),
		"top_reasons":       top(reasonCounts, 15),
		"high_top_roles":    top(highRoleCounts, 15),
		"high_top_reasons":  top(highReasonCounts, 15),
		"seen_run_hist":     seenHist,
	}
}

func buildTopActionable(high []unionRecord, topN int) []unionRecord {
	if topN <= 0 {
		return nil
	}
	rows := append([]unionRecord(nil), high...)
	sort.Slice(rows, func(i, j int) bool {
		scoreI := rows[i].PriorityScore*2.0 + float64(rows[i].SeenCount)*0.4 + float64(rows[i].OutDegree)*0.2 + float64(rows[i].InDegree)*0.15 + float64(rows[i].MessageHits)*0.7
		scoreJ := rows[j].PriorityScore*2.0 + float64(rows[j].SeenCount)*0.4 + float64(rows[j].OutDegree)*0.2 + float64(rows[j].InDegree)*0.15 + float64(rows[j].MessageHits)*0.7
		if scoreI == scoreJ {
			if rows[i].PriorityScore == rows[j].PriorityScore {
				return rows[i].Address < rows[j].Address
			}
			return rows[i].PriorityScore > rows[j].PriorityScore
		}
		return scoreI > scoreJ
	})
	if len(rows) > topN {
		rows = rows[:topN]
	}
	return rows
}

func buildTiers(rows []unionRecord, runCount int) ([]unionRecord, []unionRecord, []unionRecord) {
	core := make([]unionRecord, 0, len(rows)/3)
	aggressive := make([]unionRecord, 0, len(rows)/3)
	experimental := make([]unionRecord, 0, len(rows)/3)
	minCoreSeen := 4
	if runCount <= 1 {
		minCoreSeen = 1
	} else if runCount == 2 {
		minCoreSeen = 2
	} else if runCount == 3 {
		minCoreSeen = 2
	}
	minExpSeen := 2
	if runCount <= 1 {
		minExpSeen = 1
	}
	for _, r := range rows {
		// Core: stable and high signal.
		if r.SeenCount >= minCoreSeen && r.PriorityScore >= 2.0 {
			core = append(core, r)
			continue
		}
		// Experimental: neighborhood-expanded speculative targets.
		if hasReason(r.Reasons, "cross_image_neighborhood") && r.SeenCount <= minExpSeen {
			experimental = append(experimental, r)
			continue
		}
		aggressive = append(aggressive, r)
	}
	return core, aggressive, experimental
}

func buildReconLanes(rows []unionRecord, runCount int) ([]unionRecord, []unionRecord) {
	strict := make([]unionRecord, 0, len(rows)/8)
	aggressive := make([]unionRecord, 0, len(rows)/2)
	minStrictSeen := 3
	minAggSeen := 2
	if runCount <= 1 {
		minStrictSeen = 1
		minAggSeen = 1
	} else if runCount == 2 {
		minStrictSeen = 2
		minAggSeen = 1
	} else if runCount == 3 {
		minStrictSeen = 2
		minAggSeen = 2
	}
	for _, r := range rows {
		// Strict lane: stable targets with non-neighborhood evidence.
		if r.SeenCount >= minStrictSeen && r.PriorityScore >= 1.2 && !hasReason(r.Reasons, "cross_image_neighborhood") {
			strict = append(strict, r)
			continue
		}
		// Aggressive reconstruction lane: stable + cross-image signal.
		if r.SeenCount >= minAggSeen && r.PriorityScore >= 1.0 {
			aggressive = append(aggressive, r)
		}
	}
	return strict, aggressive
}

type reconUnit struct {
	SchemaVersion      string   `json:"schema_version"`
	Image              string   `json:"image"`
	Address            string   `json:"address"`
	Name               string   `json:"name"`
	Role               string   `json:"role"`
	PriorityScore      float64  `json:"priority_score"`
	SeenCount          int      `json:"seen_count"`
	Confidence         float64  `json:"confidence"`
	ReconstructionLane string   `json:"reconstruction_lane"`
	ConfidenceTier     string   `json:"confidence_tier"`
	Actions            []string `json:"actions"`
	Reasons            []string `json:"reasons"`
}

func buildReconUnits(strict []unionRecord, aggressive []unionRecord, actionable []unionRecord) []reconUnit {
	type key struct {
		image string
		addr  string
		name  string
	}
	isActionable := map[key]struct{}{}
	for _, r := range actionable {
		isActionable[key{image: strings.ToLower(r.Image), addr: strings.ToLower(r.Address), name: strings.ToLower(r.Name)}] = struct{}{}
	}

	makeActions := func(r unionRecord, lane string) []string {
		actions := []string{"recover_cfg", "infer_callers_callees", "annotate_mmio_and_constants"}
		if hasReason(r.Reasons, "message_path") {
			actions = append(actions, "recover_message_contract")
		}
		if hasReason(r.Reasons, "cross_image_projection") || hasReason(r.Reasons, "cross_image_projection_hop2") {
			actions = append(actions, "cross_image_symbol_propagation")
		}
		if hasReason(r.Reasons, "cross_image_neighborhood") {
			actions = append(actions, "boundary_validate_with_neighbors")
		}
		if lane == "strict" {
			actions = append(actions, "prototype_recovery", "semantic_rename")
		}
		return dedupeStrings(actions)
	}

	tierOf := func(r unionRecord, lane string) string {
		if lane == "strict" && r.SeenCount >= 2 {
			return "high"
		}
		if r.SeenCount >= 2 {
			return "medium"
		}
		return "exploratory"
	}

	out := make([]reconUnit, 0, len(strict)+len(aggressive))
	seen := map[key]int{}
	appendUnit := func(r unionRecord, lane string) {
		k := key{image: strings.ToLower(r.Image), addr: strings.ToLower(r.Address), name: strings.ToLower(r.Name)}
		unit := reconUnit{
			SchemaVersion:      "0.1.0",
			Image:              r.Image,
			Address:            r.Address,
			Name:               r.Name,
			Role:               r.Role,
			PriorityScore:      r.PriorityScore,
			SeenCount:          r.SeenCount,
			Confidence:         r.Confidence,
			ReconstructionLane: lane,
			ConfidenceTier:     tierOf(r, lane),
			Actions:            makeActions(r, lane),
			Reasons:            r.Reasons,
		}
		if _, ok := isActionable[k]; ok {
			unit.Actions = append(unit.Actions, "implement_behavior_stub")
		}
		unit.Actions = dedupeStrings(unit.Actions)

		if idx, ok := seen[k]; ok {
			if lane == "strict" && out[idx].ReconstructionLane != "strict" {
				out[idx] = unit
			}
			return
		}
		seen[k] = len(out)
		out = append(out, unit)
	}

	for _, r := range aggressive {
		appendUnit(r, "aggressive")
	}
	for _, r := range strict {
		appendUnit(r, "strict")
	}

	sort.Slice(out, func(i, j int) bool {
		if out[i].ReconstructionLane != out[j].ReconstructionLane {
			return out[i].ReconstructionLane < out[j].ReconstructionLane // strict first
		}
		if out[i].PriorityScore == out[j].PriorityScore {
			return out[i].Address < out[j].Address
		}
		return out[i].PriorityScore > out[j].PriorityScore
	})
	return out
}

func writeReconBatches(unionDir string, prefix string, runBase string, units []reconUnit, packSize int) (map[string]any, error) {
	if packSize <= 0 {
		packSize = 500
	}
	batchDir := filepath.Join(unionDir, fmt.Sprintf("%s_%s_recon_batches", prefix, runBase))
	if err := os.MkdirAll(batchDir, 0o755); err != nil {
		return nil, err
	}

	paths := make([]string, 0, (len(units)/packSize)+1)
	for i := 0; i < len(units); i += packSize {
		j := i + packSize
		if j > len(units) {
			j = len(units)
		}
		name := fmt.Sprintf("batch_%04d.jsonl", (i/packSize)+1)
		p := filepath.Join(batchDir, name)
		if err := writeJSONL(p, units[i:j]); err != nil {
			return nil, err
		}
		paths = append(paths, p)
	}

	manifest := map[string]any{
		"schema_version": "0.1.0",
		"generated_at":   time.Now().UTC().Format(time.RFC3339),
		"batch_size":     packSize,
		"batch_count":    len(paths),
		"total_units":    len(units),
		"batch_paths":    paths,
	}
	manifestPath := filepath.Join(batchDir, "manifest.json")
	if err := writeJSON(manifestPath, manifest); err != nil {
		return nil, err
	}
	return map[string]any{
		"batch_size":    packSize,
		"batch_count":   len(paths),
		"total_units":   len(units),
		"batch_dir":     batchDir,
		"manifest_path": manifestPath,
	}, nil
}

func hasReason(reasons []string, want string) bool {
	for _, r := range reasons {
		if r == want {
			return true
		}
	}
	return false
}

func dedupeStrings(in []string) []string {
	seen := map[string]struct{}{}
	out := make([]string, 0, len(in))
	for _, s := range in {
		if s == "" {
			continue
		}
		if _, ok := seen[s]; ok {
			continue
		}
		seen[s] = struct{}{}
		out = append(out, s)
	}
	return out
}

func writeShardPacks(unionDir string, prefix string, runBase string, rows []unionRecord, packSize int) (map[string]any, error) {
	if packSize <= 0 {
		packSize = 500
	}
	packDir := filepath.Join(unionDir, fmt.Sprintf("%s_%s_packs", prefix, runBase))
	if err := os.MkdirAll(packDir, 0o755); err != nil {
		return nil, err
	}
	packPaths := make([]string, 0, (len(rows)/packSize)+1)
	packStats := make([]map[string]any, 0, (len(rows)/packSize)+1)
	for i := 0; i < len(rows); i += packSize {
		j := i + packSize
		if j > len(rows) {
			j = len(rows)
		}
		packName := fmt.Sprintf("pack_%04d.jsonl", (i/packSize)+1)
		packPath := filepath.Join(packDir, packName)
		if err := writeJSONL(packPath, rows[i:j]); err != nil {
			return nil, err
		}
		packPaths = append(packPaths, packPath)
		sumScore := 0.0
		sumSeen := 0
		maxScore := 0.0
		for _, r := range rows[i:j] {
			sumScore += r.PriorityScore
			sumSeen += r.SeenCount
			if r.PriorityScore > maxScore {
				maxScore = r.PriorityScore
			}
		}
		count := j - i
		avgScore := 0.0
		avgSeen := 0.0
		if count > 0 {
			avgScore = sumScore / float64(count)
			avgSeen = float64(sumSeen) / float64(count)
		}
		priority := avgScore*2.0 + avgSeen*0.5 + maxScore*0.35
		packStats = append(packStats, map[string]any{
			"pack_name":      packName,
			"pack_path":      packPath,
			"target_count":   count,
			"avg_score":      avgScore,
			"max_score":      maxScore,
			"avg_seen_count": avgSeen,
			"priority_score": priority,
		})
	}
	sort.Slice(packStats, func(i, j int) bool {
		pi, _ := packStats[i]["priority_score"].(float64)
		pj, _ := packStats[j]["priority_score"].(float64)
		if pi == pj {
			ni, _ := packStats[i]["pack_name"].(string)
			nj, _ := packStats[j]["pack_name"].(string)
			return ni < nj
		}
		return pi > pj
	})
	manifest := map[string]any{
		"schema_version": "0.1.0",
		"generated_at":   time.Now().UTC().Format(time.RFC3339),
		"pack_size":      packSize,
		"total_targets":  len(rows),
		"pack_count":     len(packPaths),
		"pack_paths":     packPaths,
		"priority_order": packStats,
	}
	manifestPath := filepath.Join(packDir, "manifest.json")
	if err := writeJSON(manifestPath, manifest); err != nil {
		return nil, err
	}
	sample := ""
	if len(packPaths) > 0 {
		sample = packPaths[0]
	}
	return map[string]any{
		"pack_size":     packSize,
		"total_targets": len(rows),
		"pack_count":    len(packPaths),
		"pack_dir":      packDir,
		"manifest_path": manifestPath,
		"sample_pack":   sample,
	}, nil
}

func parseThresholds(in string) ([]float64, error) {
	parts := strings.Split(in, ",")
	out := make([]float64, 0, len(parts))
	for _, p := range parts {
		p = strings.TrimSpace(p)
		if p == "" {
			continue
		}
		v, err := strconv.ParseFloat(p, 64)
		if err != nil {
			return nil, fmt.Errorf("parse %q: %w", p, err)
		}
		if v < 0 {
			return nil, fmt.Errorf("threshold must be >=0: %v", v)
		}
		out = append(out, v)
	}
	if len(out) == 0 {
		return nil, fmt.Errorf("no thresholds supplied")
	}
	sort.Float64s(out)
	dedup := out[:1]
	for i := 1; i < len(out); i++ {
		if out[i] != out[i-1] {
			dedup = append(dedup, out[i])
		}
	}
	return dedup, nil
}

func streamMiningQueue(path string, onRecord func(pipeline.MiningTargetRecord) error) error {
	f, err := os.Open(path)
	if err != nil {
		return err
	}
	defer f.Close()
	s := bufio.NewScanner(f)
	s.Buffer(make([]byte, 4096), 8*1024*1024)
	for s.Scan() {
		line := strings.TrimSpace(s.Text())
		if line == "" {
			continue
		}
		var rec pipeline.MiningTargetRecord
		if err := json.Unmarshal([]byte(line), &rec); err != nil {
			return err
		}
		if err := onRecord(rec); err != nil {
			return err
		}
	}
	if err := s.Err(); err != nil {
		return err
	}
	return nil
}

func writeJSONL[T any](path string, rows []T) error {
	f, err := os.Create(path)
	if err != nil {
		return err
	}
	defer f.Close()
	bw := bufio.NewWriter(f)
	enc := json.NewEncoder(bw)
	for _, row := range rows {
		if err := enc.Encode(row); err != nil {
			return err
		}
	}
	return bw.Flush()
}

func writeJSON(path string, v any) error {
	b, err := json.MarshalIndent(v, "", "  ")
	if err != nil {
		return err
	}
	return os.WriteFile(path, append(b, '\n'), 0o644)
}

func contains(items []string, val string) bool {
	for _, s := range items {
		if s == val {
			return true
		}
	}
	return false
}

func sanitize(in string) string {
	in = strings.TrimSpace(in)
	if in == "" {
		return "sweep"
	}
	var b strings.Builder
	for _, r := range in {
		if (r >= 'a' && r <= 'z') || (r >= 'A' && r <= 'Z') || (r >= '0' && r <= '9') || r == '-' || r == '_' || r == '.' {
			b.WriteRune(r)
		} else {
			b.WriteByte('_')
		}
	}
	out := strings.Trim(strings.TrimSpace(b.String()), "._")
	if out == "" {
		return "sweep"
	}
	return out
}

func applyRetention(outAbs string, prefix string, keepSweeps int, keepRuns int) (deletedSweeps int, deletedRuns int, err error) {
	type entry struct {
		path string
		mod  time.Time
	}
	// Sweep retention by summary groups.
	if keepSweeps > 0 {
		sweepsDir := filepath.Join(outAbs, "sweeps")
		ents, e := os.ReadDir(sweepsDir)
		if e == nil {
			groups := make(map[string]entry)
			for _, ent := range ents {
				if ent.IsDir() {
					continue
				}
				name := ent.Name()
				if !strings.HasPrefix(name, prefix+"_") {
					continue
				}
				i := strings.Index(name[len(prefix)+1:], "_")
				if i < 0 {
					continue
				}
				runBase := name[:len(prefix)+1+i]
				p := filepath.Join(sweepsDir, name)
				st, se := os.Stat(p)
				if se != nil {
					continue
				}
				if old, ok := groups[runBase]; !ok || st.ModTime().After(old.mod) {
					groups[runBase] = entry{path: runBase, mod: st.ModTime()}
				}
			}
			arr := make([]entry, 0, len(groups))
			for _, g := range groups {
				arr = append(arr, g)
			}
			sort.Slice(arr, func(i, j int) bool { return arr[i].mod.After(arr[j].mod) })
			for i := keepSweeps; i < len(arr); i++ {
				base := arr[i].path
				matches, _ := filepath.Glob(filepath.Join(sweepsDir, base+"*"))
				for _, m := range matches {
					_ = os.RemoveAll(m)
				}
				deletedSweeps++
			}
		}
	}
	// Runs retention by prefix.
	if keepRuns > 0 {
		runsDir := filepath.Join(outAbs, "runs")
		ents, e := os.ReadDir(runsDir)
		if e == nil {
			arr := make([]entry, 0, len(ents))
			for _, ent := range ents {
				if !ent.IsDir() {
					continue
				}
				name := ent.Name()
				if !strings.HasPrefix(name, prefix+"_") {
					continue
				}
				p := filepath.Join(runsDir, name)
				st, se := os.Stat(p)
				if se != nil {
					continue
				}
				arr = append(arr, entry{path: p, mod: st.ModTime()})
			}
			sort.Slice(arr, func(i, j int) bool { return arr[i].mod.After(arr[j].mod) })
			for i := keepRuns; i < len(arr); i++ {
				_ = os.RemoveAll(arr[i].path)
				deletedRuns++
			}
		}
	}
	return deletedSweeps, deletedRuns, nil
}

func pruneRunArtifacts(outAbs string, runTags []string) (int, error) {
	// Keep only compact essentials; remove bulky JSONL artifacts once union/recon are finalized.
	removeFiles := []string{
		"artifacts.jsonl",
		"functions.jsonl",
		"function_links.jsonl",
		"call_edges.jsonl",
		"patch_entries.jsonl",
		"message_routes.jsonl",
		"message_schema.jsonl",
		"state_machines.jsonl",
		"images.jsonl",
		"mining_queue_full.jsonl",
		"mining_queue.jsonl",
		"mining_queue_top300.jsonl",
		"stats_history.jsonl",
	}
	deleted := 0
	for _, tag := range runTags {
		runDir := filepath.Join(outAbs, "runs", tag)
		for _, name := range removeFiles {
			p := filepath.Join(runDir, name)
			if err := os.Remove(p); err == nil {
				deleted++
			} else if err != nil && !os.IsNotExist(err) {
				return deleted, err
			}
		}
	}
	return deleted, nil
}
