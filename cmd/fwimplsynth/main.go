package main

import (
	"bufio"
	"encoding/json"
	"flag"
	"fmt"
	"os"
	"path/filepath"
	"regexp"
	"sort"
	"strconv"
	"strings"
	"time"

	"aic8800d80/internal/fileio"
)

type implTask struct {
	SchemaVersion string  `json:"schema_version,omitempty"`
	TaskID        string  `json:"task_id"`
	Function      string  `json:"function"`
	Image         string  `json:"image"`
	Address       string  `json:"address"`
	TaskClass     string  `json:"task_class"`
	Priority      string  `json:"priority"`
	RankScore     float64 `json:"rank_score"`
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

type synthManifest struct {
	SchemaVersion      string `json:"schema_version"`
	GeneratedAt        string `json:"generated_at"`
	ImplQueuePath      string `json:"implqueue_path"`
	CallEdgesPath      string `json:"call_edges_path"`
	SynthCount         int    `json:"synth_count"`
	BehaviorTaskUsed   int    `json:"behavior_tasks_used"`
	DependencyTaskUsed int    `json:"dependency_tasks_used"`
	AvgCalleeEmitted   string `json:"avg_callee_emitted"`
	OutputDir          string `json:"output_dir"`
}

type synthEvidenceRow struct {
	SchemaVersion               string   `json:"schema_version,omitempty"`
	Function                    string   `json:"function"`
	Image                       string   `json:"image"`
	Address                     string   `json:"address"`
	IncomingCount               int      `json:"incoming_count"`
	OutgoingCount               int      `json:"outgoing_count"`
	SelectedCount               int      `json:"selected_count"`
	TopIncoming                 []string `json:"top_incoming"`
	TopOutgoing                 []string `json:"top_outgoing"`
	InferredAlias               string   `json:"inferred_alias,omitempty"`
	InferredLeafCall            []string `json:"inferred_leaf_calls,omitempty"`
	CFGBBCount                  int      `json:"cfg_bb_count,omitempty"`
	CFGEdgeCount                int      `json:"cfg_edge_count,omitempty"`
	CFGInsnCount                int      `json:"cfg_insn_count,omitempty"`
	CFGHasLoop                  bool     `json:"cfg_has_loop,omitempty"`
	CFGFrameSize                int      `json:"cfg_frame_size,omitempty"`
	CFGXrefsTo                  int      `json:"cfg_xrefs_to,omitempty"`
	CFGLoadCount                int      `json:"cfg_load_count,omitempty"`
	CFGStoreCount               int      `json:"cfg_store_count,omitempty"`
	CFGStackRefCount            int      `json:"cfg_stack_ref_count,omitempty"`
	CFGImmCount                 int      `json:"cfg_imm_count,omitempty"`
	EvidenceScore               float64  `json:"evidence_score,omitempty"`
	EvidenceClass               string   `json:"evidence_class,omitempty"`
	ConservativeMode            bool     `json:"conservative_mode,omitempty"`
	SynthesisSource             string   `json:"synthesis_source,omitempty"`
	QualityWarnings             []string `json:"quality_warnings,omitempty"`
	ContractPreconditions       []string `json:"contract_preconditions,omitempty"`
	ContractPostconditions      []string `json:"contract_postconditions,omitempty"`
	ProbeSeedHints              []string `json:"probe_seed_hints,omitempty"`
	CounterexampleUnsupported   []string `json:"counterexample_unsupported,omitempty"`
	CounterexampleMissingLikely []string `json:"counterexample_missing_likely,omitempty"`
	BehaviorClass               string   `json:"behavior_class,omitempty"`
	BehaviorRole                string   `json:"behavior_role,omitempty"`
}

type synthContractHintRow struct {
	SchemaVersion  string   `json:"schema_version,omitempty"`
	Function       string   `json:"function"`
	Image          string   `json:"image"`
	Address        string   `json:"address"`
	SeedHints      []string `json:"seed_hints,omitempty"`
	Preconditions  []string `json:"preconditions,omitempty"`
	Postconditions []string `json:"postconditions,omitempty"`
}

type synthPolicy struct {
	EvidenceScore     float64
	EvidenceClass     string
	Conservative      bool
	MaxCallees        int
	Warnings          []string
	ContractPre       []string
	ContractPost      []string
	ProbeSeedHints    []string
	SuggestedProfile  string
	SuggestedMMIOAuto bool
}

type conformanceConstraint struct {
	Unsupported   []string
	MissingLikely []string
}

var nameOutgoingHints map[string][]string
var linkedFunctionHints map[string][]string
var linkedNameAliases map[string][]string
var addressNeighborHints map[string][]string

type cfgHint struct {
	SchemaVersion  string   `json:"schema_version,omitempty"`
	Image          string   `json:"image"`
	Address        string   `json:"address"`
	Name           string   `json:"name"`
	BBCount        int      `json:"bb_count"`
	EdgeCount      int      `json:"edge_count"`
	InsnCount      int      `json:"insn_count"`
	CallsiteCount  int      `json:"callsite_count"`
	XrefsTo        int      `json:"xrefs_to"`
	XrefsFrom      int      `json:"xrefs_from"`
	FrameSize      int      `json:"frame_size"`
	HasLoop        bool     `json:"has_loop"`
	LoadCount      int      `json:"load_count"`
	StoreCount     int      `json:"store_count"`
	LoadByteCount  int      `json:"load_byte_count"`
	LoadHalfCount  int      `json:"load_half_count"`
	LoadWordCount  int      `json:"load_word_count"`
	StoreByteCount int      `json:"store_byte_count"`
	StoreHalfCount int      `json:"store_half_count"`
	StoreWordCount int      `json:"store_word_count"`
	StackRefCount  int      `json:"stack_ref_count"`
	ImmCount       int      `json:"imm_count"`
	BranchCount    int      `json:"branch_count"`
	BranchCondEQ   int      `json:"branch_cond_eq"`
	BranchCondNE   int      `json:"branch_cond_ne"`
	BranchCondLT   int      `json:"branch_cond_lt"`
	BranchCondGE   int      `json:"branch_cond_ge"`
	BranchCondGT   int      `json:"branch_cond_gt"`
	BranchCondLE   int      `json:"branch_cond_le"`
	BranchCondHI   int      `json:"branch_cond_hi"`
	BranchCondLS   int      `json:"branch_cond_ls"`
	BranchCondOth  int      `json:"branch_cond_other"`
	CmpCount       int      `json:"cmp_count"`
	RetCount       int      `json:"ret_count"`
	ALUArithCount  int      `json:"alu_arith_count"`
	ALULogicCount  int      `json:"alu_logic_count"`
	ALUShiftCount  int      `json:"alu_shift_count"`
	ALUMulCount    int      `json:"alu_mul_count"`
	ProPushCount   int      `json:"pro_push_count"`
	EpiPopCount    int      `json:"epi_pop_count"`
	SPAdjustCount  int      `json:"sp_adjust_count"`
	MaxImm         uint32   `json:"max_imm"`
	TopImms        []uint32 `json:"top_imms"`
	TopRegs        []string `json:"top_regs"`
	TopMnems       []string `json:"top_mnems"`
	TopStackOffs   []int    `json:"top_stack_offsets"`
	StackOffMin    int      `json:"stack_off_min"`
	StackOffMax    int      `json:"stack_off_max"`
}

type pseudoHint struct {
	Image       string   `json:"image"`
	Address     string   `json:"address"`
	Name        string   `json:"name"`
	LineCount   int      `json:"line_count"`
	LoopCount   int      `json:"loop_count"`
	SwitchCount int      `json:"switch_count"`
	IfCount     int      `json:"if_count"`
	ReturnCount int      `json:"return_count"`
	CallNames   []string `json:"call_names"`
	MMIOAddrs   []string `json:"mmio_addrs"`
	Pseudocode  string   `json:"pseudocode"`
}

func main() {
	if err := run(); err != nil {
		fail("%v", err)
	}
}

type embedderCacheEntry struct {
	Classification struct {
		PrimaryClass  string             `json:"primary_class"`
		SynthRole     string             `json:"synth_role"`
		PriorityBoost float64            `json:"priority_boost"`
		Confidence    float64            `json:"confidence"`
		AllScores     map[string]float64 `json:"all_scores"`
	} `json:"classification"`
}

func loadEmbedderCache(path string) (map[string]embedderCacheEntry, error) {
	b, err := os.ReadFile(path)
	if err != nil {
		return nil, err
	}
	var raw map[string]embedderCacheEntry
	if err := json.Unmarshal(b, &raw); err != nil {
		// Try top-level array format
		var arr []struct {
			Key  string             `json:"key"`
			Data embedderCacheEntry `json:"data"`
		}
		if err2 := json.Unmarshal(b, &arr); err2 == nil {
			out := make(map[string]embedderCacheEntry)
			for _, e := range arr {
				if e.Key != "" {
					out[e.Key] = e.Data
				}
			}
			return out, nil
		}
		return nil, err
	}
	return raw, nil
}

func embedderLookup(cache map[string]embedderCacheEntry, name, image, address string) (cls, role string, confidence float64) {
	n := strings.ToLower(strings.TrimSpace(name))
	img := strings.ToLower(strings.TrimSpace(image))
	addr := strings.ToLower(strings.TrimSpace(address))
	// Try image|address|name first, then |name fallback
	keys := []string{}
	if img != "" || addr != "" {
		keys = append(keys, fmt.Sprintf("%s|%s|%s", img, addr, n))
	}
	keys = append(keys, fmt.Sprintf("|%s", n))
	for _, k := range keys {
		if e, ok := cache[k]; ok && e.Classification.PrimaryClass != "" {
			return e.Classification.PrimaryClass, e.Classification.SynthRole, e.Classification.Confidence
		}
	}
	// Stem-aware fallback: tokenize the name and find the best cache match
	// by shared meaningful tokens (skip short tokens and hex suffixes).
	tokens := tokenizeName(n)
	if len(tokens) == 0 {
		return "", "", 0
	}
	bestScore := 0
	var bestCls, bestRole string
	var bestConf float64
	for cacheKey, entry := range cache {
		cacheName := strings.Split(cacheKey, "|")
		if len(cacheName) == 0 {
			continue
		}
		cacheTokens := tokenizeName(cacheName[len(cacheName)-1])
		score := sharedTokenScore(tokens, cacheTokens)
		if score > bestScore && entry.Classification.PrimaryClass != "" {
			bestScore = score
			bestCls = entry.Classification.PrimaryClass
			bestRole = entry.Classification.SynthRole
			bestConf = entry.Classification.Confidence
		}
	}
	if bestScore >= 2 {
		return bestCls, bestRole, bestConf * 0.8 // penalty for stem match vs exact
	}
	return "", "", 0
}

func tokenizeName(name string) []string {
	parts := strings.FieldsFunc(name, func(r rune) bool {
		return r == '_' || r == '-' || r == '.'
	})
	out := make([]string, 0, len(parts))
	for _, p := range parts {
		p = strings.TrimSpace(p)
		if len(p) < 3 {
			continue
		}
		// Skip numeric-only or hex-suffix tokens
		if isNumeric(p) {
			continue
		}
		out = append(out, p)
	}
	return out
}

func sharedTokenScore(a, b []string) int {
	score := 0
	am := make(map[string]bool, len(a))
	for _, t := range a {
		am[t] = true
	}
	for _, t := range b {
		if am[t] {
			score++
		}
	}
	return score
}

func isNumeric(s string) bool {
	for _, c := range s {
		if c < '0' || c > 'f' {
			return false
		}
	}
	return len(s) > 0
}

func run() error {
	var iAbs, cAbs, oAbs string
	var composedDir, cfgHintsPath, pseudoHintsPath, functionLinksPath, conformancePath string
	var minConf, fallbackMinConf float64
	var maxTasks int
	var counterexampleInjectMax int
	var minEvidenceScore float64
	var complexityBBThreshold, complexityEdgeThreshold int
	var maxCalleesHighComplexity, maxCalleesLowEvidence int
	var strictLowEvidence bool
	var includeDependencies bool

	// Flags and defaults (kept local so run() is self-contained).
	implQueuePath := "extraction_out/reconstruction/mega7/implqueue/implementation_queue.json"
	callEdgesPath := "extraction_out/call_edges.jsonl"
	outDir := "extraction_out/reconstruction/mega7/synth"
	composedDirPath := "extraction_out/reconstruction/mega7/composed"
	cfgHintsFilePath := "extraction_out/reconstruction/mega7/cfg_hints.jsonl"
	pseudoHintsFilePath := "extraction_out/ida_export_pseudo/pseudocode_hints.jsonl"
	functionLinksFilePath := "extraction_out/reconstruction/mega7/function_links.jsonl"
	conformanceFilePath := "extraction_out/reconstruction/mega7/final/call_conformance.json"
	minCallConfidence := 0.7
	fallbackMinCallConfidence := 0.4
	maxTasksVal := 80
	counterexampleInjectMaxVal := 3
	minEvidenceScoreVal := 1.8
	complexityBBThresholdVal := 4
	complexityEdgeThresholdVal := 6
	maxCalleesHighComplexityVal := 3
	maxCalleesLowEvidenceVal := 1
	strictLowEvidenceVal := false
	includeDependencies = true
	requireIDAEdges := true
	requireIDACFG := true
	requireIDAPseudo := true

	fs := flag.NewFlagSet("fwimplsynth", flag.ContinueOnError)
	fs.StringVar(&implQueuePath, "implqueue", implQueuePath, "Implementation queue JSON path")
	fs.StringVar(&callEdgesPath, "call-edges", callEdgesPath, "Call edges JSONL path")
	fs.StringVar(&outDir, "out", outDir, "Output directory for synthesized C")
	fs.StringVar(&composedDirPath, "composed-dir", composedDirPath, "Composed functions directory")
	fs.StringVar(&cfgHintsFilePath, "cfg-hints", cfgHintsFilePath, "CFG hints JSONL path")
	fs.StringVar(&pseudoHintsFilePath, "pseudo-hints", pseudoHintsFilePath, "Hex-Rays pseudocode hint JSONL path")
	fs.StringVar(&functionLinksFilePath, "function-links", functionLinksFilePath, "Function links JSONL path")
	fs.StringVar(&conformanceFilePath, "conformance", conformanceFilePath, "Call conformance JSON path")
	fs.Float64Var(&minCallConfidence, "min-call-confidence", minCallConfidence, "Minimum confidence for observed call edges")
	fs.Float64Var(&fallbackMinCallConfidence, "fallback-min-call-confidence", fallbackMinCallConfidence, "Fallback confidence threshold for inferred call edges")
	fs.IntVar(&maxTasksVal, "max-tasks", maxTasksVal, "Maximum synthesis tasks (0=all)")
	fs.IntVar(&counterexampleInjectMaxVal, "counterexample-inject-max", counterexampleInjectMaxVal, "Maximum counterexample hints injected into templates")
	fs.Float64Var(&minEvidenceScoreVal, "min-evidence-score", minEvidenceScoreVal, "Low-evidence threshold for conservative synthesis")
	fs.IntVar(&complexityBBThresholdVal, "complexity-bb-threshold", complexityBBThresholdVal, "CFG basic-block threshold for high complexity")
	fs.IntVar(&complexityEdgeThresholdVal, "complexity-edge-threshold", complexityEdgeThresholdVal, "CFG edge threshold for high complexity")
	fs.IntVar(&maxCalleesHighComplexityVal, "max-callees-high-complexity", maxCalleesHighComplexityVal, "Max emitted callees for high-complexity functions")
	fs.IntVar(&maxCalleesLowEvidenceVal, "max-callees-low-evidence", maxCalleesLowEvidenceVal, "Max emitted callees for low-evidence functions")
	fs.BoolVar(&strictLowEvidenceVal, "strict-low-evidence", strictLowEvidenceVal, "Force conservative templates for low-evidence functions")
	fs.BoolVar(&includeDependencies, "include-dependencies", includeDependencies, "Include dependency_impl tasks after behavior_lift tasks")
	fs.BoolVar(&requireIDAEdges, "require-ida-edges", requireIDAEdges, "Require call_edges.with_ida_raw.jsonl and fail if missing")
	fs.BoolVar(&requireIDACFG, "require-ida-cfg", requireIDACFG, "Require cfg_hints.jsonl and fail if missing")
	fs.BoolVar(&requireIDAPseudo, "require-ida-pseudo", requireIDAPseudo, "Require pseudocode_hints.jsonl and fail if missing")
	if err := fs.Parse(os.Args[1:]); err != nil {
		return err
	}

	iAbs, _ = filepath.Abs(implQueuePath)
	cAbs, _ = filepath.Abs(callEdgesPath)
	oAbs, _ = filepath.Abs(outDir)
	composedDir = composedDirPath
	cfgHintsPath = cfgHintsFilePath
	pseudoHintsPath = pseudoHintsFilePath
	functionLinksPath = functionLinksFilePath
	conformancePath = conformanceFilePath
	minConf = minCallConfidence
	fallbackMinConf = fallbackMinCallConfidence
	maxTasks = maxTasksVal
	counterexampleInjectMax = counterexampleInjectMaxVal
	minEvidenceScore = minEvidenceScoreVal
	complexityBBThreshold = complexityBBThresholdVal
	complexityEdgeThreshold = complexityEdgeThresholdVal
	maxCalleesHighComplexity = maxCalleesHighComplexityVal
	maxCalleesLowEvidence = maxCalleesLowEvidenceVal
	strictLowEvidence = strictLowEvidenceVal
	_ = includeDependencies

	if err := clearStaleSynthFiles(oAbs); err != nil {
		fail("clear stale synth files: %v", err)
	}

	tasks, err := readTasks(iAbs)
	if err != nil {
		fail("read implqueue: %v", err)
	}
	composedBackfill, err := readComposedFunctionBackfill(composedDir)
	if err != nil {
		fail("read composed backfill: %v", err)
	}
	idaEdgesPath := filepath.Join(filepath.Dir(cAbs), "call_edges.with_ida_raw.jsonl")
	if requireIDAEdges {
		if _, err := os.Stat(idaEdgesPath); err != nil {
			fail("require-ida-edges: missing %s", idaEdgesPath)
		}
	}
	if requireIDACFG {
		if _, err := os.Stat(cfgHintsPath); err != nil {
			fallbackCfg := filepath.Join(filepath.Dir(cAbs), "ida_export_cfg", "cfg_hints.jsonl")
			if _, err2 := os.Stat(fallbackCfg); err2 == nil {
				cfgHintsPath = fallbackCfg
			} else {
				fail("require-ida-cfg: missing %s (and fallback %s)", cfgHintsPath, fallbackCfg)
			}
		}
	}
	if requireIDAPseudo {
		if _, err := os.Stat(pseudoHintsPath); err != nil {
			fallbackPseudo := filepath.Join(filepath.Dir(cAbs), "ida_export_pseudo", "pseudocode_hints.jsonl")
			if _, err2 := os.Stat(fallbackPseudo); err2 == nil {
				pseudoHintsPath = fallbackPseudo
			} else {
				fail("require-ida-pseudo: missing %s (and fallback %s)", pseudoHintsPath, fallbackPseudo)
			}
		}
	}
	edgePaths := existingEdgePaths(idaEdgesPath, cAbs)
	inAdj, outAdj, inByName, outByName, err := readAdjMulti(edgePaths, minConf)
	if err != nil {
		fail("read call edges: %v", err)
	}
	hints, composedCallers, _ := loadComposedHints(composedDir)
	cfgByAddr, cfgByName, _ := loadCFGHints(cfgHintsPath)
	pseudoByAddr, pseudoByName, _ := loadPseudoHints(pseudoHintsPath)
	if len(pseudoByAddr) > 0 || len(pseudoByName) > 0 {
		fmt.Fprintf(os.Stderr, "pseudocode hints loaded: %d address entries\n", len(pseudoByAddr))
	}
	familyHints := buildFamilyHints(outByName, minConf, fallbackMinConf)
	suffixHints := buildSuffixHints(outByName, minConf, fallbackMinConf)
	tokenHints := buildTokenHints(outByName, minConf, fallbackMinConf)
	imageHints := buildImageHints(inAdj, outAdj, minConf, fallbackMinConf)
	nameOutgoingHints = buildNameOutgoingHints(outByName, minConf, fallbackMinConf)
	linkedFunctionHints = buildLinkedFunctionHints(functionLinksPath, 0.80, nameOutgoingHints)
	linkedNameAliases = buildLinkedNameAliases(functionLinksPath, 0.80)
	addressNeighborHints = buildAddressNeighborHints(outAdj)
	conformanceConstraints, err := loadConformanceConstraints(conformancePath)
	if err != nil {
		fail("load conformance constraints: %v", err)
	}

	synth := make([]implTask, 0, maxTasks)
	behaviorCount := 0
	depCount := 0
	selected := map[string]struct{}{}
	for _, t := range tasks {
		if t.TaskClass != "behavior_lift" {
			continue
		}
		synth = append(synth, t)
		selected[sanitizeName(t.Function)] = struct{}{}
		behaviorCount++
		if maxTasks > 0 && len(synth) >= maxTasks {
			break
		}
	}
	if includeDependencies && (maxTasks <= 0 || len(synth) < maxTasks) {
		for _, t := range tasks {
			if t.TaskClass != "dependency_impl" {
				continue
			}
			synth = append(synth, t)
			selected[sanitizeName(t.Function)] = struct{}{}
			depCount++
			if maxTasks > 0 && len(synth) >= maxTasks {
				break
			}
		}
	}
	if maxTasks <= 0 || len(synth) < maxTasks {
		for _, t := range composedBackfill {
			fn := sanitizeName(t.Function)
			if fn == "" {
				continue
			}
			if _, ok := selected[fn]; ok {
				continue
			}
			synth = append(synth, t)
			selected[fn] = struct{}{}
			depCount++
			if maxTasks > 0 && len(synth) >= maxTasks {
				break
			}
		}
	}

	embedderCachePath := filepath.Join(outDir, "..", "embedder_cache.json")
	embedderCache, _ := loadEmbedderCache(embedderCachePath)
	if len(embedderCache) > 0 {
		fmt.Fprintf(os.Stderr, "embedder cache loaded: %d entries\n", len(embedderCache))
	}

	totalCallees := 0
	evidence := make([]synthEvidenceRow, 0, len(synth))
	contractHints := make([]synthContractHintRow, 0, len(synth))
	for i, t := range synth {
		incoming, outgoing := edgesForTask(t, inAdj, outAdj, inByName, outByName)
		sort.Slice(outgoing, func(a, b int) bool { return outgoing[a].Confidence > outgoing[b].Confidence })
		aggressive := allowSyntheticInference(t.Function, incoming, outgoing)
		source := "observed_outgoing"
		selected := selectCallees(t, outgoing, outAdj, minConf, fallbackMinConf)
		if len(selected) == 0 {
			selected = inferFromNameOutgoingHints(t, minConf, fallbackMinConf)
			source = "name_outgoing_hints"
		}
		if len(selected) == 0 {
			selected = inferFromIncoming(t, incoming, outAdj, outByName, minConf, fallbackMinConf)
			source = "incoming_projection"
		}
		if len(selected) == 0 && aggressive {
			selected = inferFromLinkedFunctionHints(t, minConf, fallbackMinConf)
			source = "linked_function_hints"
		}
		if len(selected) == 0 && aggressive {
			selected = inferFromAddressNeighborHints(t, minConf, fallbackMinConf)
			source = "address_neighbor_hints"
		}
		if len(selected) == 0 {
			if aggressive {
				selected = inferFromComposedHints(t, hints)
				source = "composed_hints"
			}
		}
		if len(selected) == 0 && aggressive {
			selected = inferFromComposedContext(t, hints, composedCallers)
			source = "composed_context"
		}
		if len(selected) == 0 && aggressive {
			selected = inferFromTokenHints(t, tokenHints)
			source = "token_hints"
		}
		if len(selected) == 0 && aggressive {
			selected = inferFromSuffixHints(t, suffixHints)
			source = "suffix_hints"
		}
		if len(selected) == 0 && aggressive {
			selected = inferFromFamilyHints(t, familyHints)
			source = "family_hints"
		}
		if len(selected) == 0 && aggressive {
			selected = inferFromImageHints(t, imageHints)
			source = "image_hints"
		}
		fn := sanitizeName(t.Function)
		selected, unsupportedCE, missingCE := applyCounterexampleConstraints(selected, conformanceConstraints[fn], minConf, counterexampleInjectMax)
		cfg := cfgForTask(t, cfgByAddr, cfgByName)
		pseudo := pseudoForTask(t, pseudoByAddr, pseudoByName)
		policy := evaluateSynthesisPolicy(
			t,
			incoming,
			outgoing,
			selected,
			cfg,
			source,
			minEvidenceScore,
			complexityBBThreshold,
			complexityEdgeThreshold,
			maxCalleesHighComplexity,
			maxCalleesLowEvidence,
			strictLowEvidence,
		)
		selected = trimSelectedCallees(selected, policy.MaxCallees)
		totalCallees += len(selected)
		row := synthEvidenceRow{
			SchemaVersion:               "0.1.0",
			Function:                    fn,
			Image:                       t.Image,
			Address:                     t.Address,
			IncomingCount:               len(incoming),
			OutgoingCount:               len(outgoing),
			SelectedCount:               len(selected),
			TopIncoming:                 topIncomingNames(incoming, 4),
			TopOutgoing:                 topOutgoingNames(outgoing, 4),
			EvidenceScore:               policy.EvidenceScore,
			EvidenceClass:               policy.EvidenceClass,
			ConservativeMode:            policy.Conservative,
			SynthesisSource:             source,
			QualityWarnings:             policy.Warnings,
			ContractPreconditions:       policy.ContractPre,
			ContractPostconditions:      policy.ContractPost,
			ProbeSeedHints:              policy.ProbeSeedHints,
			CounterexampleUnsupported:   unsupportedCE,
			CounterexampleMissingLikely: missingCE,
		}
		if h := cfg; h != nil {
			row.CFGBBCount = h.BBCount
			row.CFGEdgeCount = h.EdgeCount
			row.CFGInsnCount = h.InsnCount
			row.CFGHasLoop = h.HasLoop
			row.CFGFrameSize = h.FrameSize
			row.CFGXrefsTo = h.XrefsTo
			row.CFGLoadCount = h.LoadCount
			row.CFGStoreCount = h.StoreCount
			row.CFGStackRefCount = h.StackRefCount
			row.CFGImmCount = h.ImmCount
		}
		if strings.HasPrefix(fn, "sub_") {
			role := functionRole(fn)
			if hint := callerRoleHint(incoming); hint != "" && (role == "shared helper" || role == "unnamed helper") {
				role = hint
			}
			row.InferredAlias = inferredSubAlias(fn, role, t.Image, incoming)
			row.InferredLeafCall = inferLeafCallsFromIncoming(fn, incoming)
		}
		// Look up behavioral class from embedder cache.
		if len(embedderCache) > 0 {
			bc, role, conf := embedderLookup(embedderCache, fn, t.Image, t.Address)
			if bc != "" {
				row.BehaviorClass = bc
				row.BehaviorRole = role
				_ = conf
			}
		}
		evidence = append(evidence, row)
		contractHints = append(contractHints, synthContractHintRow{
			SchemaVersion:  "0.1.0",
			Function:       fn,
			Image:          t.Image,
			Address:        t.Address,
			SeedHints:      policy.ProbeSeedHints,
			Preconditions:  policy.ContractPre,
			Postconditions: policy.ContractPost,
		})
		file := filepath.Join(oAbs, fmt.Sprintf("%03d_%s.synth.c", i+1, sanitizeName(t.Function)))
		if err := writeSynth(file, t, incoming, selected, cfg, pseudo, policy, row.BehaviorClass, row.BehaviorRole); err != nil {
			fail("write synth %s: %v", file, err)
		}
	}
	avgCallees := "0.00"
	if len(synth) > 0 {
		avgCallees = fmt.Sprintf("%.2f", float64(totalCallees)/float64(len(synth)))
	}

	m := synthManifest{
		SchemaVersion:      "0.1.0",
		GeneratedAt:        time.Now().UTC().Format(time.RFC3339),
		ImplQueuePath:      iAbs,
		CallEdgesPath:      cAbs,
		SynthCount:         len(synth),
		BehaviorTaskUsed:   behaviorCount,
		DependencyTaskUsed: depCount,
		AvgCalleeEmitted:   avgCallees,
		OutputDir:          oAbs,
	}
	if err := fileio.WriteJSON(filepath.Join(oAbs, "implsynth_manifest.json"), m); err != nil {
		fail("write manifest: %v", err)
	}
	if err := fileio.WriteJSON(filepath.Join(oAbs, "implsynth_evidence.json"), evidence); err != nil {
		fail("write evidence: %v", err)
	}
	if err := fileio.WriteJSON(filepath.Join(oAbs, "implsynth_contract_hints.json"), contractHints); err != nil {
		fail("write contract hints: %v", err)
	}
	fmt.Printf("implementation synthesis generated.\n")
	fmt.Printf("  synth_count: %d\n", m.SynthCount)
	fmt.Printf("  behavior_tasks_used: %d\n", m.BehaviorTaskUsed)
	fmt.Printf("  dependency_tasks_used: %d\n", m.DependencyTaskUsed)
	fmt.Printf("  avg_callee_emitted: %s\n", m.AvgCalleeEmitted)
	fmt.Printf("  evidence_path: %s\n", filepath.Join(oAbs, "implsynth_evidence.json"))
	fmt.Printf("  contract_hints_path: %s\n", filepath.Join(oAbs, "implsynth_contract_hints.json"))
	fmt.Printf("  out_dir: %s\n", oAbs)
	return nil
}

func topIncomingNames(in []callEdge, n int) []string {
	counts := map[string]int{}
	for _, e := range in {
		name := sanitizeName(e.SourceName)
		if name == "" || name == "unknown" {
			continue
		}
		counts[name]++
	}
	return topNames(counts, n)
}

func topOutgoingNames(out []callEdge, n int) []string {
	counts := map[string]int{}
	for _, e := range out {
		name := sanitizeName(e.TargetName)
		if name == "" || name == "unknown" {
			continue
		}
		counts[name]++
	}
	return topNames(counts, n)
}

func topNames(counts map[string]int, n int) []string {
	type pair struct {
		name string
		n    int
	}
	rows := make([]pair, 0, len(counts))
	for k, v := range counts {
		rows = append(rows, pair{name: k, n: v})
	}
	sort.Slice(rows, func(i, j int) bool {
		if rows[i].n == rows[j].n {
			return rows[i].name < rows[j].name
		}
		return rows[i].n > rows[j].n
	})
	if n > len(rows) {
		n = len(rows)
	}
	out := make([]string, 0, n)
	for i := 0; i < n; i++ {
		out = append(out, rows[i].name)
	}
	return out
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

func readComposedFunctionBackfill(composedDir string) ([]implTask, error) {
	dirAbs, _ := filepath.Abs(composedDir)
	ents, err := os.ReadDir(dirAbs)
	if err != nil {
		return nil, err
	}
	re := regexp.MustCompile(`(?m)void\s+([a-zA-Z0-9_]+)\s*\(\s*void\s*\)\s*\{`)
	out := make([]implTask, 0, 256)
	seen := map[string]struct{}{}
	for _, e := range ents {
		if e.IsDir() || !strings.HasSuffix(e.Name(), ".reconstructed.c") {
			continue
		}
		p := filepath.Join(dirAbs, e.Name())
		b, err := os.ReadFile(p)
		if err != nil {
			continue
		}
		image := strings.TrimSuffix(e.Name(), ".reconstructed.c")
		for _, m := range re.FindAllStringSubmatch(string(b), -1) {
			if len(m) < 2 {
				continue
			}
			fn := sanitizeName(m[1])
			if fn == "" {
				continue
			}
			if _, ok := seen[fn]; ok {
				continue
			}
			seen[fn] = struct{}{}
			out = append(out, implTask{
				TaskID:    "backfill_" + fn,
				Function:  fn,
				Image:     image,
				Address:   "",
				TaskClass: "dependency_impl",
				Priority:  "low",
				RankScore: 0.01,
			})
		}
	}
	sort.Slice(out, func(i, j int) bool { return out[i].Function < out[j].Function })
	return out, nil
}

func clearStaleSynthFiles(dir string) error {
	ents, err := os.ReadDir(dir)
	if err != nil {
		return err
	}
	for _, e := range ents {
		if e.IsDir() || !strings.HasSuffix(e.Name(), ".synth.c") {
			continue
		}
		if err := os.Remove(filepath.Join(dir, e.Name())); err != nil {
			return err
		}
	}
	return nil
}

func readAdj(path string, minConf float64) (map[string][]callEdge, map[string][]callEdge, map[string][]callEdge, map[string][]callEdge, error) {
	return readAdjMulti([]string{path}, minConf)
}

func loadConformanceConstraints(path string) (map[string]conformanceConstraint, error) {
	type conformanceRow struct {
		Function      string   `json:"function"`
		Unsupported   []string `json:"unsupported_calls"`
		MissingLikely []string `json:"missing_likely_calls"`
		EvidenceFound bool     `json:"evidence_found"`
	}
	type conformanceReport struct {
		SchemaVersion string           `json:"schema_version,omitempty"`
		Rows          []conformanceRow `json:"rows"`
	}
	out := map[string]conformanceConstraint{}
	b, err := os.ReadFile(path)
	if err != nil {
		if os.IsNotExist(err) {
			return out, nil
		}
		return nil, err
	}
	var rep conformanceReport
	if err := json.Unmarshal(b, &rep); err != nil {
		return out, nil
	}
	if strings.TrimSpace(rep.SchemaVersion) != "" && rep.SchemaVersion != "0.1.0" {
		return nil, fmt.Errorf("conformance schema mismatch: got %s want 0.1.0", rep.SchemaVersion)
	}
	for _, r := range rep.Rows {
		fn := sanitizeName(r.Function)
		if fn == "" || fn == "unknown" || !r.EvidenceFound {
			continue
		}
		deny := dedupeSanitizedNames(r.Unsupported)
		req := dedupeSanitizedNames(r.MissingLikely)
		if len(deny) == 0 && len(req) == 0 {
			continue
		}
		out[fn] = conformanceConstraint{Unsupported: deny, MissingLikely: req}
	}
	return out, nil
}

func applyCounterexampleConstraints(selected []callEdge, c conformanceConstraint, minConf float64, maxInject int) ([]callEdge, []string, []string) {
	if len(c.Unsupported) == 0 && len(c.MissingLikely) == 0 {
		return selected, nil, nil
	}
	unsupportedSet := map[string]struct{}{}
	for _, n := range c.Unsupported {
		unsupportedSet[sanitizeName(n)] = struct{}{}
	}
	out := make([]callEdge, 0, len(selected)+len(c.MissingLikely))
	seen := map[string]struct{}{}
	removed := make([]string, 0, len(c.Unsupported))
	for _, e := range selected {
		n := sanitizeName(e.TargetName)
		if n == "" || n == "unknown" {
			n = sanitizeName("sub_" + strings.TrimPrefix(strings.ToLower(strings.TrimSpace(e.TargetAddr)), "0x"))
		}
		if _, deny := unsupportedSet[n]; deny {
			removed = append(removed, n)
			continue
		}
		if _, ok := seen[n]; ok {
			continue
		}
		seen[n] = struct{}{}
		if strings.TrimSpace(e.TargetName) == "" || e.TargetName == "unknown" {
			e.TargetName = n
		}
		out = append(out, e)
	}
	if maxInject < 0 {
		maxInject = 0
	}
	injected := make([]string, 0, maxInject)
	for _, n := range c.MissingLikely {
		n = sanitizeName(n)
		if n == "" || n == "unknown" {
			continue
		}
		if _, deny := unsupportedSet[n]; deny {
			continue
		}
		if _, ok := seen[n]; ok {
			continue
		}
		if maxInject > 0 && len(injected) >= maxInject {
			break
		}
		seen[n] = struct{}{}
		out = append(out, callEdge{TargetName: n, Confidence: minConf})
		injected = append(injected, n)
	}
	sort.Strings(removed)
	removed = dedupeSanitizedNames(removed)
	return out, removed, injected
}

func dedupeSanitizedNames(in []string) []string {
	seen := map[string]struct{}{}
	out := make([]string, 0, len(in))
	for _, x := range in {
		n := sanitizeName(x)
		if n == "" || n == "unknown" {
			continue
		}
		if _, ok := seen[n]; ok {
			continue
		}
		seen[n] = struct{}{}
		out = append(out, n)
	}
	return out
}

func readAdjMulti(paths []string, minConf float64) (map[string][]callEdge, map[string][]callEdge, map[string][]callEdge, map[string][]callEdge, error) {
	in := make(map[string][]callEdge, 4096)
	out := make(map[string][]callEdge, 4096)
	inName := make(map[string][]callEdge, 4096)
	outName := make(map[string][]callEdge, 4096)
	seen := map[string]struct{}{}
	for _, path := range paths {
		f, err := os.Open(path)
		if err != nil {
			continue
		}
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
				_ = f.Close()
				return nil, nil, nil, nil, fmt.Errorf("call edges schema mismatch: got %s want 0.1.0", e.SchemaVersion)
			}
			if e.Confidence < minConf {
				continue
			}
			dk := strings.ToLower(strings.TrimSpace(e.Image)) + "|" +
				strings.ToLower(strings.TrimSpace(e.SourceAddr)) + "|" +
				strings.ToLower(strings.TrimSpace(e.TargetAddr))
			if _, ok := seen[dk]; ok {
				continue
			}
			seen[dk] = struct{}{}
			for _, sa := range addrVariants(e.SourceAddr) {
				out[addrKey(e.Image, sa)] = append(out[addrKey(e.Image, sa)], e)
			}
			for _, ta := range addrVariants(e.TargetAddr) {
				in[addrKey(e.Image, ta)] = append(in[addrKey(e.Image, ta)], e)
			}
			srcN := sanitizeName(e.SourceName)
			tgtN := sanitizeName(e.TargetName)
			canonicalTgt := tgtN
			if canonicalTgt == "" || canonicalTgt == "unknown" {
				canonicalTgt = sanitizeName(nonEmpty(e.TargetName, "sub_"+strings.TrimPrefix(strings.ToLower(e.TargetAddr), "0x")))
			}
			srcAliases := expandLinkedAliases(srcN)
			tgtAliases := expandLinkedAliases(tgtN)
			for _, sname := range srcAliases {
				for _, tname := range tgtAliases {
					ee := e
					ee.SourceName = sname
					ee.TargetName = canonicalTgt
					if sname != "" && sname != "unknown" {
						outName[sname] = append(outName[sname], ee)
					}
					if tname != "" && tname != "unknown" {
						inName[tname] = append(inName[tname], ee)
					}
				}
			}
		}
		if err := sc.Err(); err != nil {
			_ = f.Close()
			return nil, nil, nil, nil, err
		}
		_ = f.Close()
	}
	return in, out, inName, outName, nil
}

func trimSelectedCallees(selected []callEdge, maxCallees int) []callEdge {
	if maxCallees <= 0 || len(selected) <= maxCallees {
		return selected
	}
	out := make([]callEdge, maxCallees)
	copy(out, selected[:maxCallees])
	return out
}

func evaluateSynthesisPolicy(
	t implTask,
	incoming []callEdge,
	outgoing []callEdge,
	selected []callEdge,
	cfg *cfgHint,
	source string,
	minEvidenceScore float64,
	complexityBBThreshold int,
	complexityEdgeThreshold int,
	maxCalleesHighComplexity int,
	maxCalleesLowEvidence int,
	strictLowEvidence bool,
) synthPolicy {
	policy := synthPolicy{
		EvidenceClass:     "strong",
		Conservative:      false,
		MaxCallees:        0,
		SuggestedProfile:  "rich",
		SuggestedMMIOAuto: true,
	}

	evidence := 0.0
	if cfg != nil {
		evidence += 0.6
		evidence += float64(minInt(cfg.CallsiteCount, 8)) * 0.08
		evidence += float64(minInt(cfg.XrefsTo, 8)) * 0.05
		if cfg.HasLoop {
			evidence += 0.25
		}
	}
	evidence += float64(minInt(len(incoming), 6)) * 0.07
	evidence += float64(minInt(len(outgoing), 8)) * 0.06
	for _, e := range selected {
		evidence += maxFloat(0.0, minFloat(e.Confidence, 1.0)) * 0.25
	}
	switch source {
	case "observed_outgoing", "incoming_projection":
		evidence += 0.45
	case "name_outgoing_hints", "linked_function_hints":
		evidence += 0.15
	default:
		evidence -= 0.15
	}
	if len(selected) == 0 {
		evidence -= 0.9
	}
	if evidence < 0 {
		evidence = 0
	}
	policy.EvidenceScore = evidence

	highComplexity := false
	if cfg != nil {
		highComplexity = cfg.BBCount >= maxInt(1, complexityBBThreshold) || cfg.EdgeCount >= maxInt(1, complexityEdgeThreshold) || cfg.HasLoop
	}
	lowEvidence := evidence < minEvidenceScore

	if lowEvidence {
		policy.EvidenceClass = "low"
		policy.Warnings = append(policy.Warnings, fmt.Sprintf("low evidence score %.2f < %.2f", evidence, minEvidenceScore))
	} else if evidence < minEvidenceScore+0.8 {
		policy.EvidenceClass = "medium"
	} else {
		policy.EvidenceClass = "strong"
	}
	if highComplexity && lowEvidence && strictLowEvidence {
		policy.Conservative = true
		policy.Warnings = append(policy.Warnings, "high complexity with low evidence: forcing conservative template")
	}
	if cfg != nil && cfg.CallsiteCount > 0 && len(selected) == 0 {
		policy.Warnings = append(policy.Warnings, "cfg reports callsites but no callees selected")
	}
	if cfg != nil && cfg.StoreCount > 0 && source != "observed_outgoing" && source != "incoming_projection" {
		policy.Warnings = append(policy.Warnings, "memory-side-effect profile with heuristic callee source")
	}

	if highComplexity && maxCalleesHighComplexity > 0 {
		policy.MaxCallees = maxCalleesHighComplexity
	}
	if lowEvidence && maxCalleesLowEvidence > 0 {
		if policy.MaxCallees == 0 || maxCalleesLowEvidence < policy.MaxCallees {
			policy.MaxCallees = maxCalleesLowEvidence
		}
	}

	contractPre, contractPost, seeds := deriveContractAndSeedHints(t, incoming, selected, cfg)
	policy.ContractPre = contractPre
	policy.ContractPost = contractPost
	policy.ProbeSeedHints = seeds

	return policy
}

func deriveContractAndSeedHints(t implTask, incoming, selected []callEdge, cfg *cfgHint) ([]string, []string, []string) {
	pre := make([]string, 0, 6)
	post := make([]string, 0, 6)
	seeds := make([]string, 0, 8)
	seedSeen := map[string]struct{}{}
	addSeed := func(s string) {
		s = strings.TrimSpace(strings.ToLower(s))
		if s == "" {
			return
		}
		if _, ok := seedSeen[s]; ok {
			return
		}
		seedSeen[s] = struct{}{}
		seeds = append(seeds, s)
	}

	fn := sanitizeName(t.Function)
	if cfg != nil && cfg.FrameSize > 0 {
		pre = append(pre, "requires valid writable stack context")
	}
	if len(incoming) > 0 {
		pre = append(pre, "expects caller-managed context consistency")
	}
	if strings.Contains(fn, "msg") || strings.Contains(fn, "handler") || strings.Contains(fn, "dispatch") {
		pre = append(pre, "expects non-null message/context buffers")
	}
	if strings.Contains(fn, "rf") || strings.Contains(fn, "sdio") || strings.Contains(fn, "hal") {
		pre = append(pre, "expects readable MMIO/peripheral state")
	}

	if len(selected) > 0 {
		post = append(post, "may invoke dependency helper chain")
	}
	if cfg != nil && cfg.StoreCount > 0 {
		post = append(post, "may mutate MMIO/memory-side effects")
	}
	if strings.Contains(fn, "timer") {
		post = append(post, "may update timer/scheduling state")
	}

	if cfg != nil {
		for _, imm := range cfg.TopImms {
			if imm >= 0x40000000 && imm <= 0x7FFFFFFF {
				addSeed(fmt.Sprintf("0x%x=0", imm&0xFFFFF000))
			}
		}
		if cfg.MaxImm >= 0x40000000 && cfg.MaxImm <= 0x7FFFFFFF {
			addSeed(fmt.Sprintf("0x%x=0", cfg.MaxImm&0xFFFFF000))
		}
	}
	if strings.Contains(fn, "rf") {
		addSeed("0x40010000=0")
	}
	if strings.Contains(fn, "sdio") || strings.Contains(fn, "ipc") {
		addSeed("0x40020000=0")
	}
	if strings.Contains(fn, "msg") || strings.Contains(fn, "queue") {
		addSeed("0x20000040=1")
	}
	sort.Strings(seeds)

	pre = uniqueStrings(pre)
	post = uniqueStrings(post)
	return pre, post, seeds
}

func minFloat(a, b float64) float64 {
	if a < b {
		return a
	}
	return b
}

func maxFloat(a, b float64) float64 {
	if a > b {
		return a
	}
	return b
}

func writeSynth(path string, t implTask, incoming, outgoing []callEdge, cfg *cfgHint, pseudo *pseudoHint, policy synthPolicy, behaviorClass string, behaviorRole string) error {
	var b strings.Builder
	b.WriteString("/* Auto-generated synthesized implementation pass */\n")
	b.WriteString(fmt.Sprintf("/* task=%s class=%s priority=%s score=%.3f */\n", t.TaskID, t.TaskClass, t.Priority, t.RankScore))
	if behaviorClass != "" {
		b.WriteString(fmt.Sprintf("/* behavior_class=%s behavior_role=%s */\n", behaviorClass, behaviorRole))
	}
	b.WriteString(fmt.Sprintf("/* image=%s addr=%s */\n\n", t.Image, t.Address))
	b.WriteString("#include <stdint.h>\n\n")

	fn := sanitizeName(t.Function)
	role := functionRole(fn)
	if role == "shared helper" || role == "generic helper" || role == "unnamed helper" || role == "undecorated helper stub" {
		if hint := callerRoleHint(incoming); hint != "" {
			role = hint
		} else if strings.EqualFold(strings.TrimSpace(t.Image), "shared") && t.TaskClass == "dependency_impl" {
			role = "shared dependency leaf"
		} else if hint := imageRoleHint(t.Image); hint != "" {
			role = hint
		}
	}
	if fn == "thunk" {
		role = "relay call helper"
	}
	if fn == "main_loop" {
		if hint := callerRoleHint(incoming); hint != "" && hint != "shared helper" {
			if hint == "clock helper" {
				role = "main loop driver"
			} else {
				role = hint
			}
		} else if hint := imageRoleHint(t.Image); hint != "" {
			role = hint
		} else {
			role = "main loop driver"
		}
	}
	switch fn {
	case "tx_dequeue":
		role = "transmit dequeue helper"
	case "ke_timer_set":
		role = "kernel timer set helper"
	case "mm_timer_set":
		role = "mac timer set helper"
	case "mm_key_del_req_handler":
		role = "key delete request handler"
	case "mm_set_arpoffload_en_req_handler":
		role = "set arp offload en request handler"
	case "apm_stop_cac_req_handler":
		role = "stop CAC request handler"
	case "fw_config_apply":
		role = "firmware config apply helper"
	case "crypto_channel_calc":
		role = "crypto channel calculation helper"
	case "crypto_iq_calculate":
		role = "crypto IQ calculation helper"
	case "chip_feature_check":
		role = "chip feature gate helper"
	case "fp_convert_int", "fp_convert_uint":
		role = "fixed-point conversion helper"
	case "math_helper_big":
		role = "numeric aggregation helper"
	case "math_helper_big2":
		role = "numeric aggregation leaf"
	case "msg_get_value":
		role = "message value getter"
	case "msg_parse_short":
		role = "short message parser helper"
	case "log_free_dispatch":
		role = "logging free dispatcher"
	case "log_free_pool_dispatch2":
		role = "logging free pool dispatcher"
	case "log_queue_push":
		role = "logging queue push helper"
	case "log_queue_push2":
		role = "logging queue push second stage helper"
	}
	if strings.HasPrefix(fn, "sub_") {
		stem := humanizeStem(fn, "")
		if role == "shared helper" || role == "generic helper" || role == "undecorated helper stub" {
			if hint := imageRoleHint(t.Image); hint != "" {
				role = strings.TrimSuffix(hint, " helper") + " shared dependency leaf"
			} else {
				if stem != "" {
					role = "shared dependency leaf " + stem
				} else {
					role = "shared dependency leaf"
				}
			}
		}
		switch role {
		case "rf helper":
			if stem != "" {
				role = "rf shared dependency leaf " + stem
			} else {
				role = "rf shared dependency leaf"
			}
		case "log helper":
			if stem != "" {
				role = "log shared dependency leaf " + stem
			} else {
				role = "log shared dependency leaf"
			}
		case "mac subsystem helper":
			if stem != "" {
				role = "mac subsystem leaf " + stem
			} else {
				role = "mac subsystem leaf"
			}
		case "shared support leaf":
			if hint := imageRoleHint(t.Image); hint != "" {
				role = strings.TrimSuffix(hint, " helper") + " shared dependency leaf"
			} else {
				if stem != "" {
					role = "shared dependency leaf " + stem
				} else {
					role = "shared dependency leaf"
				}
			}
		case "shared dependency leaf":
			if hint := imageRoleHint(t.Image); hint != "" {
				role = strings.TrimSuffix(hint, " helper") + " shared dependency leaf"
			} else if stem != "" {
				role = "shared dependency leaf " + stem
			}
		case "shared dependency helper":
			if hint := imageRoleHint(t.Image); hint != "" {
				role = strings.TrimSuffix(hint, " helper") + " shared dependency leaf"
			} else {
				if stem != "" {
					role = "shared dependency leaf " + stem
				} else {
					role = "shared dependency leaf"
				}
			}
		}
	}
	// Override role with behavioral class if classifier provided a specific role.
	if behaviorRole != "" && behaviorRole != "leaf_wrapper" {
		genericRoles := map[string]bool{"shared helper": true, "generic helper": true, "unnamed helper": true, "undecorated helper stub": true, "shared dependency leaf": true}
		if genericRoles[role] || strings.HasPrefix(role, "shared") {
			role = "embedder class: " + behaviorClass + " (" + behaviorRole + ")"
		}
	}
	decls := map[string]struct{}{}
	addDecl := func(name string) {
		n := sanitizeName(name)
		if n == "" || n == fn {
			return
		}
		decls[n] = struct{}{}
	}
	for _, e := range outgoing {
		addDecl(nonEmpty(e.TargetName, "sub_"+strings.TrimPrefix(strings.ToLower(e.TargetAddr), "0x")))
	}
	for _, n := range forcedControlCalls(fn) {
		addDecl(n)
	}
	for _, n := range leafSyntheticCallees(fn, role, t.Image, incoming, outgoing) {
		addDecl(n)
	}
	for _, n := range nameOutgoingHints[fn] {
		addDecl(n)
	}
	for _, n := range specializedStaticCallees(fn) {
		addDecl(n)
	}
	if len(decls) > 0 {
		names := make([]string, 0, len(decls))
		for n := range decls {
			names = append(names, n)
		}
		sort.Strings(names)
		for _, n := range names {
			b.WriteString("void " + n + "(void);\n")
		}
		b.WriteString("\n")
	}
	b.WriteString(fmt.Sprintf("void %s(void) {\n", fn))
	b.WriteString(fmt.Sprintf("  // role: %s\n", role))
	if len(policy.ContractPre) > 0 {
		for _, pre := range policy.ContractPre {
			b.WriteString("  // pre: " + strings.TrimSpace(pre) + "\n")
		}
	}
	if len(policy.ContractPost) > 0 {
		for _, post := range policy.ContractPost {
			b.WriteString("  // post: " + strings.TrimSpace(post) + "\n")
		}
	}
	if policy.EvidenceClass != "" {
		b.WriteString(fmt.Sprintf("  // evidence: class=%s score=%.2f\n", policy.EvidenceClass, policy.EvidenceScore))
	}
	if policy.Conservative {
		for _, w := range policy.Warnings {
			b.WriteString("  // warning: " + strings.TrimSpace(w) + "\n")
		}
	}
	seed := synthSeed(fn, t.Address)
	b.WriteString(fmt.Sprintf("  uint32_t state = 0x%08xU;\n", seed))
	if pseudo != nil && !policy.Conservative {
		if emitted := emitPseudocodeStructuredBody(&b, fn, pseudo, cfg, outgoing, behaviorRole); emitted {
			b.WriteString("  (void)state;\n")
			b.WriteString("}\n")
			return fileio.WriteBytes(path, []byte(b.String()))
		}
	}
	// Behavioral-class-driven body: if classifier identified a specific role,
	// emit class-appropriate firmware code instead of a generic stub.
	if behaviorRole != "" && !policy.Conservative {
		if emitted := emitBehavioralClassBody(&b, fn, behaviorRole, behaviorClass, t.Address); emitted {
			b.WriteString("  (void)state;\n")
			b.WriteString("}\n")
			return fileio.WriteBytes(path, []byte(b.String()))
		}
	}
	if policy.Conservative {
		if len(outgoing) > 0 {
			target := sanitizeName(nonEmpty(outgoing[0].TargetName, "sub_"+strings.TrimPrefix(strings.ToLower(outgoing[0].TargetAddr), "0x")))
			if target != "" && target != fn {
				b.WriteString("  // conservative_mode: limited dependency invocation due to low evidence.\n")
				b.WriteString("  " + target + "();\n")
				b.WriteString("  state ^= 0xA5A5A5A5U;\n")
			}
		}
		b.WriteString("  (void)state;\n")
		b.WriteString("}\n")
		return fileio.WriteBytes(path, []byte(b.String()))
	}
	if len(incoming) == 0 && len(outgoing) == 0 {
		b.WriteString(fmt.Sprintf("  state ^= 0x%08xU;\n", callMixConst(fn, 0xE8)))
	} else {
		b.WriteString(fmt.Sprintf("  state ^= ((uint32_t)%dU << 16) ^ ((uint32_t)%dU << 8);\n", len(incoming), len(outgoing)))
	}
	if cfg != nil {
		b.WriteString(fmt.Sprintf("  state ^= ((uint32_t)%dU << 4);\n", cfg.BBCount))
		b.WriteString(fmt.Sprintf("  state ^= ((uint32_t)%dU << 1);\n", cfg.EdgeCount))
		needMemProf := cfg.LoadCount > 0 || cfg.StoreCount > 0 || len(cfg.TopImms) > 0
		if needMemProf {
			b.WriteString(fmt.Sprintf("  state ^= ((uint32_t)%dU << 9);\n", cfg.LoadCount))
			b.WriteString(fmt.Sprintf("  state ^= ((uint32_t)%dU << 13);\n", cfg.StoreCount))
			// Shape side effects based on recovered memory-access profile.
			mmioBase := uint32(0x40000000)
			for _, v := range cfg.TopImms {
				if v >= 0x40000000 && v <= 0x7FFFFFFF {
					mmioBase = v & 0xFFFFF000
					break
				}
			}
			if mmioBase == 0x40000000 && cfg.MaxImm >= 0x40000000 && cfg.MaxImm <= 0x7FFFFFFF {
				mmioBase = cfg.MaxImm & 0xFFFFF000
			}
			b.WriteString(fmt.Sprintf("  volatile uint32_t *mem_prof = (volatile uint32_t *)(uintptr_t)0x%08xU;\n", mmioBase))
			if cfg.LoadByteCount > 0 || cfg.StoreByteCount > 0 {
				b.WriteString("  volatile uint8_t *mem8 = (volatile uint8_t *)(uintptr_t)mem_prof;\n")
			}
			if cfg.LoadHalfCount > 0 || cfg.StoreHalfCount > 0 {
				b.WriteString("  volatile uint16_t *mem16 = (volatile uint16_t *)(uintptr_t)mem_prof;\n")
			}
		}
		if cfg.LoadCount > 0 || cfg.StoreCount > 0 {
			if cfg.LoadCount > cfg.StoreCount {
				readIters := cfg.LoadCount
				if readIters > 8 {
					readIters = 8
				}
				if readIters < 1 {
					readIters = 1
				}
				b.WriteString(fmt.Sprintf("  for (uint32_t i = 0U; i < %dU; ++i) {\n", readIters))
				b.WriteString("    state ^= mem_prof[(state + i) & 0x1FU];\n")
				b.WriteString("  }\n")
			} else if cfg.StoreCount > 0 {
				writeIters := cfg.StoreCount
				if writeIters > 6 {
					writeIters = 6
				}
				if writeIters < 1 {
					writeIters = 1
				}
				b.WriteString(fmt.Sprintf("  for (uint32_t i = 0U; i < %dU; ++i) {\n", writeIters))
				b.WriteString(fmt.Sprintf("    mem_prof[(state + i) & 0x1FU] = state ^ (0x%08xU + i);\n", callMixConst(fn, 0xA5)))
				b.WriteString("  }\n")
			}
			if cfg.LoadByteCount > 0 || cfg.StoreByteCount > 0 {
				byteIters := cfg.LoadByteCount + cfg.StoreByteCount
				if byteIters > 6 {
					byteIters = 6
				}
				if byteIters < 1 {
					byteIters = 1
				}
				blLoopSel := int(callMixConst(fn, byteIters+0x62) & 1)
				if blLoopSel == 0 {
					b.WriteString(fmt.Sprintf("  for (uint32_t i = 0U; i < %dU; ++i) {\n", byteIters))
					b.WriteString("    uint32_t o = (state + i) & 0x3FU;\n")
					if cfg.LoadByteCount > 0 {
						blSel := int(callMixConst(fn, cfg.LoadByteCount+0x61) & 1)
						if blSel == 0 {
							b.WriteString("    state ^= (uint32_t)mem8[o];\n")
						} else {
							b.WriteString("    state = (state + (uint32_t)mem8[o]) ^ ((state >> 3) & 0xFFU);\n")
						}
					}
					if cfg.StoreByteCount > 0 {
						b.WriteString("    mem8[o] = (uint8_t)(state ^ (0xA5U + i));\n")
					}
					b.WriteString("  }\n")
				} else {
					b.WriteString("  uint32_t bi = 0U;\n")
					b.WriteString(fmt.Sprintf("  while (bi < %dU) {\n", byteIters))
					b.WriteString("    uint32_t o = (state + bi) & 0x3FU;\n")
					if cfg.LoadByteCount > 0 {
						blSel := int(callMixConst(fn, cfg.LoadByteCount+0x61) & 1)
						if blSel == 0 {
							b.WriteString("    state ^= (uint32_t)mem8[o];\n")
						} else {
							b.WriteString("    state = (state + (uint32_t)mem8[o]) ^ ((state >> 3) & 0xFFU);\n")
						}
					}
					if cfg.StoreByteCount > 0 {
						b.WriteString("    mem8[o] = (uint8_t)(state ^ (0xA5U + bi));\n")
					}
					b.WriteString("    ++bi;\n")
					b.WriteString("  }\n")
				}
			}
			if cfg.LoadHalfCount > 0 || cfg.StoreHalfCount > 0 {
				halfIters := cfg.LoadHalfCount + cfg.StoreHalfCount
				if halfIters > 4 {
					halfIters = 4
				}
				if halfIters < 1 {
					halfIters = 1
				}
				hlLoopSel := int(callMixConst(fn, halfIters+0x72) % 3)
				if hlLoopSel == 0 {
					b.WriteString(fmt.Sprintf("  for (uint32_t i = 0U; i < %dU; ++i) {\n", halfIters))
					b.WriteString("    uint32_t o = ((state >> 1) + i) & 0x1FU;\n")
					if cfg.LoadHalfCount > 0 {
						hlSel := int(callMixConst(fn, cfg.LoadHalfCount+0x71) & 1)
						if hlSel == 0 {
							b.WriteString("    state ^= (uint32_t)mem16[o];\n")
						} else {
							b.WriteString("    state = (state ^ (uint32_t)mem16[o]) + ((state << 1) & 0xFFFFU);\n")
						}
					}
					if cfg.StoreHalfCount > 0 {
						b.WriteString("    mem16[o] = (uint16_t)(state ^ (0x5A5AU + i));\n")
					}
					b.WriteString("  }\n")
				} else if hlLoopSel == 1 {
					b.WriteString("  uint32_t hi = 0U;\n")
					b.WriteString(fmt.Sprintf("  while (hi < %dU) {\n", halfIters))
					b.WriteString("    uint32_t o = ((state >> 1) + hi) & 0x1FU;\n")
					if cfg.LoadHalfCount > 0 {
						hlSel := int(callMixConst(fn, cfg.LoadHalfCount+0x71) & 1)
						if hlSel == 0 {
							b.WriteString("    state ^= (uint32_t)mem16[o];\n")
						} else {
							b.WriteString("    state = (state ^ (uint32_t)mem16[o]) + ((state << 1) & 0xFFFFU);\n")
						}
					}
					if cfg.StoreHalfCount > 0 {
						b.WriteString("    mem16[o] = (uint16_t)(state ^ (0x5A5AU + hi));\n")
					}
					b.WriteString("    ++hi;\n")
					b.WriteString("  }\n")
				} else {
					b.WriteString("  uint32_t hi = 0U;\n")
					b.WriteString("  do {\n")
					b.WriteString("    uint32_t o = ((state >> 1) + hi) & 0x1FU;\n")
					if cfg.LoadHalfCount > 0 {
						hlSel := int(callMixConst(fn, cfg.LoadHalfCount+0x71) & 1)
						if hlSel == 0 {
							b.WriteString("    state ^= (uint32_t)mem16[o];\n")
						} else {
							b.WriteString("    state = (state ^ (uint32_t)mem16[o]) + ((state << 1) & 0xFFFFU);\n")
						}
					}
					if cfg.StoreHalfCount > 0 {
						b.WriteString("    mem16[o] = (uint16_t)(state ^ (0x5A5AU + hi));\n")
					}
					b.WriteString("    ++hi;\n")
					b.WriteString(fmt.Sprintf("  } while (hi < %dU);\n", halfIters))
				}
			}
		}
		if cfg.StackRefCount > 0 {
			b.WriteString(fmt.Sprintf("  state ^= ((uint32_t)%dU << 5);\n", cfg.StackRefCount))
		}
		if cfg.MaxImm != 0 {
			miSel := int(callMixConst(fn, int(cfg.MaxImm&0xFF)+0xE6) % 3)
			if miSel == 0 {
				b.WriteString(fmt.Sprintf("  state ^= 0x%08xU;\n", cfg.MaxImm))
			} else if miSel == 1 {
				b.WriteString(fmt.Sprintf("  state = (state + 0x%08xU) ^ (state >> 2U);\n", cfg.MaxImm))
			} else {
				b.WriteString(fmt.Sprintf("  state ^= (0x%08xU + (state << 1U));\n", cfg.MaxImm))
			}
		}
		if cfg.ImmCount > 0 {
			mask := uint32((cfg.ImmCount << 3) | 0x1F)
			b.WriteString(fmt.Sprintf("  state ^= (state & 0x%08xU);\n", mask))
		}
		if len(cfg.TopImms) > 0 {
			limit := len(cfg.TopImms)
			if limit > 4 {
				limit = 4
			}
			b.WriteString(fmt.Sprintf("  static const uint32_t imm_sig[%d] = {", limit))
			for i := 0; i < limit; i++ {
				if i > 0 {
					b.WriteString(", ")
				}
				b.WriteString(fmt.Sprintf("0x%08xU", cfg.TopImms[i]))
			}
			b.WriteString("};\n")
			tiLoopSel := int(callMixConst(fn, limit+0x82) & 1)
			if tiLoopSel == 0 {
				b.WriteString(fmt.Sprintf("  for (uint32_t i = 0U; i < %dU; ++i) {\n", limit))
				b.WriteString("    uint32_t off = (imm_sig[i] >> 2) & 0x1FU;\n")
				tiSel := int(callMixConst(fn, limit+0x81) & 1)
				if tiSel == 0 {
					b.WriteString("    state ^= mem_prof[off] ^ imm_sig[i];\n")
				} else {
					b.WriteString("    state = (state + mem_prof[off]) ^ (imm_sig[i] >> 1);\n")
				}
				b.WriteString("    mem_prof[off] = state ^ (imm_sig[i] << 1);\n")
				b.WriteString("  }\n")
			} else {
				b.WriteString("  uint32_t ii = 0U;\n")
				b.WriteString(fmt.Sprintf("  while (ii < %dU) {\n", limit))
				b.WriteString("    uint32_t off = (imm_sig[ii] >> 2) & 0x1FU;\n")
				tiSel := int(callMixConst(fn, limit+0x81) & 1)
				if tiSel == 0 {
					b.WriteString("    state ^= mem_prof[off] ^ imm_sig[ii];\n")
				} else {
					b.WriteString("    state = (state + mem_prof[off]) ^ (imm_sig[ii] >> 1);\n")
				}
				b.WriteString("    mem_prof[off] = state ^ (imm_sig[ii] << 1);\n")
				b.WriteString("    ++ii;\n")
				b.WriteString("  }\n")
			}
		}
		// Add control-shape scaffolding from recovered branch/cmp profile.
		if cfg.BranchCount >= 3 {
			branchFanout := (cfg.BranchCount % 4) + 2
			b.WriteString(fmt.Sprintf("  switch ((state >> 3) & 0x%XU) {\n", uint32(branchFanout-1)))
			for i := 0; i < branchFanout; i++ {
				bsSel := int(callMixConst(fn, i+0xE1) % 3)
				if bsSel == 0 {
					b.WriteString(fmt.Sprintf("    case %dU: state ^= 0x%08xU; break;\n", i, callMixConst(fn, i)))
				} else if bsSel == 1 {
					b.WriteString(fmt.Sprintf("    case %dU: state = (state + 0x%08xU) ^ ((state >> %dU) & 0xFFFFU); break;\n", i, callMixConst(fn, i+1), (i%4)+1))
				} else {
					b.WriteString(fmt.Sprintf("    case %dU: state ^= (0x%08xU + (state << %dU)); break;\n", i, callMixConst(fn, i+2), (i%3)+1))
				}
			}
			b.WriteString(fmt.Sprintf("    default: state = (state ^ 0x%08xU) + (state >> 3U); break;\n", callMixConst(fn, 0x6a)))
			b.WriteString("  }\n")
		}
		if cfg.CmpCount > 0 {
			cmpIters := cfg.CmpCount
			if cmpIters > 6 {
				cmpIters = 6
			}
			if cmpIters < 1 {
				cmpIters = 1
			}
			b.WriteString(fmt.Sprintf("  for (uint32_t i = 0U; i < %dU; ++i) {\n", cmpIters))
			b.WriteString("    uint32_t probe = (state >> (i & 7U)) & 0xFFU;\n")
			b.WriteString("    if (probe < 0x20U) {\n")
			b.WriteString("      state ^= 0x00010001U + i;\n")
			b.WriteString("    } else if (probe < 0x80U) {\n")
			b.WriteString("      state ^= 0x00020002U + (i << 1);\n")
			b.WriteString("    } else {\n")
			b.WriteString("      state ^= 0x00040004U + (i << 2);\n")
			b.WriteString("    }\n")
			b.WriteString("  }\n")
		}
		condTotal := cfg.BranchCondEQ + cfg.BranchCondNE + cfg.BranchCondLT + cfg.BranchCondGE + cfg.BranchCondGT + cfg.BranchCondLE + cfg.BranchCondHI + cfg.BranchCondLS + cfg.BranchCondOth
		if condTotal > 0 {
			emitEQ := cfg.BranchCondEQ > cfg.BranchCondNE
			emitNE := cfg.BranchCondNE > 0
			emitLT := cfg.BranchCondLT+cfg.BranchCondLE > cfg.BranchCondGT+cfg.BranchCondGE
			emitGE := !emitLT && (cfg.BranchCondGT+cfg.BranchCondGE > 0)
			emitHI := cfg.BranchCondHI+cfg.BranchCondLS > 0
			if emitEQ || emitNE || emitLT || emitGE || emitHI {
				b.WriteString(fmt.Sprintf("  uint32_t condv = state ^ 0x%08xU;\n", callMixConst(fn, condTotal+0x7f)))
			}
			if emitEQ {
				b.WriteString("  if ((condv & 0xFFU) == ((state >> 8) & 0xFFU)) {\n")
				eqSel := int(callMixConst(fn, cfg.BranchCondEQ+0xE2) % 3)
				if eqSel == 0 {
					b.WriteString(fmt.Sprintf("    state ^= 0x%08xU;\n", callMixConst(fn, cfg.BranchCondEQ+0x01)))
				} else if eqSel == 1 {
					b.WriteString(fmt.Sprintf("    state = (state + 0x%08xU) ^ (state >> 2U);\n", callMixConst(fn, cfg.BranchCondEQ+0x02)))
				} else {
					b.WriteString(fmt.Sprintf("    state ^= (0x%08xU + (state << 1U));\n", callMixConst(fn, cfg.BranchCondEQ+0x03)))
				}
				b.WriteString("  } else {\n")
				neEqSel := int(callMixConst(fn, cfg.BranchCondNE+0xE3) % 3)
				if neEqSel == 0 {
					b.WriteString(fmt.Sprintf("    state ^= 0x%08xU;\n", callMixConst(fn, cfg.BranchCondNE+0x10)))
				} else if neEqSel == 1 {
					b.WriteString(fmt.Sprintf("    state = (state + 0x%08xU) ^ (state >> 3U);\n", callMixConst(fn, cfg.BranchCondNE+0x11)))
				} else {
					b.WriteString(fmt.Sprintf("    state ^= (0x%08xU + (state << 2U));\n", callMixConst(fn, cfg.BranchCondNE+0x12)))
				}
				b.WriteString("  }\n")
			}
			if emitNE {
				neMask := callMixConst(fn, cfg.BranchCondNE+0x3f) & 0x3F
				if neMask == 0 {
					neMask = 0x3F
				}
				neShift := 1 + (cfg.BranchCondNE % 4)
				b.WriteString(fmt.Sprintf("  if ((condv & 0x%XU) != ((state >> %d) & 0x%XU)) {\n", neMask, neShift, neMask))
				b.WriteString(fmt.Sprintf("    state ^= 0x%08xU;\n", callMixConst(fn, cfg.BranchCondNE+0xFF)))
				b.WriteString("  }\n")
			}
			if emitLT {
				b.WriteString("  if ((int32_t)condv < (int32_t)(state ^ 0x80000000U)) {\n")
				b.WriteString("    state = (state << 1) ^ (condv >> 1);\n")
				b.WriteString("  }\n")
			} else if emitGE {
				b.WriteString("  if ((int32_t)condv >= (int32_t)(state ^ 0x13579BDFU)) {\n")
				b.WriteString("    state = (state >> 1) ^ (condv << 1);\n")
				b.WriteString("  }\n")
			}
			if emitHI {
				b.WriteString("  uint32_t ucmp = condv - (state & 0xFFFFU);\n")
				b.WriteString("  if (ucmp > 0x100U) {\n")
				b.WriteString(fmt.Sprintf("    state = (state ^ 0x%08xU) + (ucmp & 0xFFU);\n", callMixConst(fn, cfg.BranchCondHI+0xA5)))
				b.WriteString("  } else {\n")
				b.WriteString(fmt.Sprintf("    state = (state + 0x%08xU) ^ (ucmp >> 1U);\n", callMixConst(fn, cfg.BranchCondLS+0x5A)))
				b.WriteString("  }\n")
			}
		}
		if cfg.RetCount >= 2 {
			b.WriteString("  if ((state & 0x3U) == 0U) {\n")
			b.WriteString("    state ^= 0x00C0FFEEU;\n")
			b.WriteString("  }\n")
		}
		if cfg.ProPushCount > 0 || cfg.EpiPopCount > 0 || cfg.SPAdjustCount > 0 {
			frameSlots := cfg.ProPushCount + cfg.EpiPopCount + cfg.SPAdjustCount
			if frameSlots < 2 {
				frameSlots = 2
			}
			if frameSlots > 12 {
				frameSlots = 12
			}
			needFrameRegs := cfg.ProPushCount > 0 || cfg.EpiPopCount > 0
			if needFrameRegs {
				b.WriteString(fmt.Sprintf("  uint32_t frame_regs[%d];\n", frameSlots))
				b.WriteString(fmt.Sprintf("  for (uint32_t fi = 0U; fi < %dU; ++fi) {\n", frameSlots))
				b.WriteString(fmt.Sprintf("    frame_regs[fi] = state ^ (fi * 0x%08xU);\n", callMixConst(fn, frameSlots+0x21)))
				b.WriteString("  }\n")
			}
			if cfg.ProPushCount > 0 {
				pushSel := int(callMixConst(fn, cfg.ProPushCount+0x31) % 3)
				b.WriteString(fmt.Sprintf("  for (uint32_t fi = 0U; fi < %dU; ++fi) {\n", minInt(cfg.ProPushCount, frameSlots)))
				if pushSel == 0 {
					b.WriteString("    state ^= frame_regs[fi];\n")
				} else if pushSel == 1 {
					b.WriteString("    state ^= (frame_regs[fi] << (fi & 3U)) | (frame_regs[fi] >> (8U - (fi & 3U)));\n")
				} else {
					b.WriteString("    state = (state + frame_regs[fi]) ^ (frame_regs[fi] >> ((fi & 3U) + 1U));\n")
				}
				b.WriteString("  }\n")
			}
			if cfg.SPAdjustCount > 0 {
				b.WriteString(fmt.Sprintf("  state ^= ((uint32_t)%dU << 6);\n", cfg.SPAdjustCount))
			}
			if cfg.EpiPopCount > 0 {
				popSel := int(callMixConst(fn, cfg.EpiPopCount+0x41) % 3)
				b.WriteString(fmt.Sprintf("  for (uint32_t fi = 0U; fi < %dU; ++fi) {\n", minInt(cfg.EpiPopCount, frameSlots)))
				b.WriteString(fmt.Sprintf("    uint32_t idx = (uint32_t)%dU - 1U - fi;\n", frameSlots))
				if popSel == 0 {
					b.WriteString("    state ^= frame_regs[idx] >> (fi & 7U);\n")
				} else if popSel == 1 {
					b.WriteString("    state ^= frame_regs[idx] ^ (frame_regs[idx] >> ((fi & 3U) + 1U));\n")
				} else {
					b.WriteString("    state = (state + frame_regs[idx]) ^ (frame_regs[idx] << (fi & 3U));\n")
				}
				b.WriteString("  }\n")
			}
		}
		if len(cfg.TopMnems) > 0 {
			loadLike := 0
			storeLike := 0
			cmpLike := 0
			moveLike := 0
			for _, m := range cfg.TopMnems {
				ml := strings.ToLower(strings.TrimSpace(m))
				switch {
				case strings.HasPrefix(ml, "ldr"), strings.HasPrefix(ml, "ldm"):
					loadLike++
				case strings.HasPrefix(ml, "str"), strings.HasPrefix(ml, "stm"):
					storeLike++
				case strings.HasPrefix(ml, "cmp"), strings.HasPrefix(ml, "cmn"), strings.HasPrefix(ml, "tst"):
					cmpLike++
				case strings.HasPrefix(ml, "mov"), strings.HasPrefix(ml, "mvn"):
					moveLike++
				}
			}
			opIters := len(cfg.TopMnems)
			if opIters > 8 {
				opIters = 8
			}
			if opIters < 2 {
				opIters = 2
			}
			b.WriteString(fmt.Sprintf("  for (uint32_t opi = 0U; opi < %dU; ++opi) {\n", opIters))
			b.WriteString(fmt.Sprintf("    uint32_t opmix = state ^ (opi * 0x%08xU);\n", callMixConst(fn, 0x11)|1))
			if loadLike > 0 {
				b.WriteString("    opmix ^= (state >> (opi & 7U));\n")
			}
			if storeLike > 0 {
				b.WriteString("    opmix ^= (state << ((opi & 3U) + 1U));\n")
			}
			if cmpLike > 0 {
				b.WriteString("    if ((opmix & 0x1FU) < ((state >> 3) & 0x1FU)) { opmix ^= 0x1U; }\n")
			}
			if moveLike > 0 {
				b.WriteString("    opmix = (opmix & 0xFFFF0000U) | (state & 0xFFFFU);\n")
			}
			opSel := int(callMixConst(fn, opIters+0x51) % 3)
			if opSel == 0 {
				b.WriteString("    state ^= opmix;\n")
			} else if opSel == 1 {
				b.WriteString("    state = (state + opmix) ^ (opmix >> (opi & 7U));\n")
			} else {
				b.WriteString("    state = (state ^ (opmix << (opi & 3U))) + (opmix & 0xFFFFU);\n")
			}
			b.WriteString("  }\n")
		}
		// Complexity-tiered control shaping from CFG density/loop evidence.
		cfgComplexity := cfg.BBCount + ((cfg.EdgeCount-cfg.BBCount)*7)/10
		if cfg.HasLoop {
			cfgComplexity += 4
		}
		if cfgComplexity >= 28 {
			outer := cfg.BBCount / 24
			if outer < 2 {
				outer = 2
			}
			if outer > 6 {
				outer = 6
			}
			inner := cfg.EdgeCount / 64
			if inner < 2 {
				inner = 2
			}
			if inner > 5 {
				inner = 5
			}
			b.WriteString(fmt.Sprintf("  for (uint32_t ob = 0U; ob < %dU; ++ob) {\n", outer))
			b.WriteString(fmt.Sprintf("    for (uint32_t ib = 0U; ib < %dU; ++ib) {\n", inner))
			b.WriteString(fmt.Sprintf("      uint32_t lane = ((state >> (ib & 7U)) ^ (ob * 0x%08xU) ^ ib);\n", callMixConst(fn, 0x1f)|1))
			b.WriteString("      if ((lane & 3U) == 0U) {\n")
			b.WriteString(fmt.Sprintf("        state ^= lane + 0x%08xU;\n", callMixConst(fn, 0x10)))
			b.WriteString("      } else if ((lane & 3U) == 1U) {\n")
			b.WriteString(fmt.Sprintf("        state = (state << %dU) | (state >> %dU);\n", 3+(cfg.BBCount%3), 29-(cfg.BBCount%3)))
			b.WriteString("        state ^= lane;\n")
			b.WriteString("      } else {\n")
			b.WriteString(fmt.Sprintf("        state ^= (lane * 0x%08xU);\n", callMixConst(fn, 0x45)|1))
			b.WriteString("      }\n")
			b.WriteString("    }\n")
			b.WriteString("  }\n")
		}
		aluTotal := cfg.ALUArithCount + cfg.ALULogicCount + cfg.ALUShiftCount + cfg.ALUMulCount
		if aluTotal > 0 {
			aluIters := aluTotal / 6
			if aluIters < 1 {
				aluIters = 1
			}
			if aluIters > 8 {
				aluIters = 8
			}
			b.WriteString(fmt.Sprintf("  for (uint32_t i = 0U; i < %dU; ++i) {\n", aluIters))
			b.WriteString(fmt.Sprintf("    uint32_t x = state ^ (0x%08xU + (i << 4));\n", callMixConst(fn, 0x9e)))
			if cfg.ALUArithCount > 0 {
				b.WriteString(fmt.Sprintf("    x += (state >> (i & 7U)) + (i * 0x%08xU);\n", callMixConst(fn, 0x11)))
				b.WriteString("    x ^= (x - (state << (i & 3U)));\n")
			}
			if cfg.ALULogicCount > 0 {
				b.WriteString("    x ^= (state & 0x55AA55AAU);\n")
				b.WriteString("    x |= ((state >> 1) & 0x0F0F0F0FU);\n")
			}
			if cfg.ALUShiftCount > 0 {
				b.WriteString("    x = (x << ((i & 3U) + 1U)) | (x >> (31U - (i & 3U)));\n")
			}
			if cfg.ALUMulCount > 0 {
				b.WriteString(fmt.Sprintf("    x = x * (0x%08xU | 1U);\n", callMixConst(fn, 0x46)))
			}
			b.WriteString("    state ^= x;\n")
			b.WriteString("  }\n")
		}
		if len(cfg.TopRegs) > 0 {
			lim := len(cfg.TopRegs)
			if lim > 4 {
				lim = 4
			}
			b.WriteString(fmt.Sprintf("  uint32_t reg_touch[%d] = {", lim))
			for i := 0; i < lim; i++ {
				if i > 0 {
					b.WriteString(", ")
				}
				b.WriteString(fmt.Sprintf("0x%08xU", callMixConst(cfg.TopRegs[i], i)))
			}
			b.WriteString("};\n")
			b.WriteString(fmt.Sprintf("  for (uint32_t i = 0U; i < %dU; ++i) {\n", lim))
			b.WriteString("    state ^= reg_touch[i] + (i << 8);\n")
			b.WriteString("    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);\n")
			b.WriteString("  }\n")
			// Build a tiny register-flow model from dominant IDA registers.
			regHasR0 := false
			regHasR1 := false
			regHasR2 := false
			regHasR3 := false
			regHasSP := false
			regHasLR := false
			for _, r := range cfg.TopRegs {
				rr := strings.ToLower(strings.TrimSpace(r))
				switch rr {
				case "r0":
					regHasR0 = true
				case "r1":
					regHasR1 = true
				case "r2":
					regHasR2 = true
				case "r3":
					regHasR3 = true
				case "sp":
					regHasSP = true
				case "lr":
					regHasLR = true
				}
			}
			if regHasR0 || regHasR1 || regHasR2 || regHasR3 {
				b.WriteString("  uint32_t reg_r0 = state;\n")
				b.WriteString("  uint32_t reg_r1 = state ^ 0x11111111U;\n")
				b.WriteString("  uint32_t reg_r2 = state ^ 0x22222222U;\n")
				b.WriteString("  uint32_t reg_r3 = state ^ 0x33333333U;\n")
				if regHasR0 && regHasR1 {
					b.WriteString("  reg_r0 = (reg_r0 + reg_r1) ^ (reg_r1 >> 2U);\n")
				}
				if regHasR2 {
					b.WriteString("  reg_r2 ^= (reg_r0 << 1U) + (reg_r1 & 0xFFFFU);\n")
				}
				if regHasR3 {
					b.WriteString("  reg_r3 = (reg_r3 ^ reg_r2) + (reg_r0 >> 1U);\n")
				}
				b.WriteString("  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;\n")
			}
			if regHasSP {
				b.WriteString("  uint32_t sp_model = 0x20000000U + (state & 0x3FFU);\n")
				b.WriteString("  sp_model -= ((state >> 5U) & 0x3CU);\n")
				b.WriteString("  state ^= sp_model;\n")
			}
			if regHasLR {
				b.WriteString("  uint32_t lr_model = (state ^ 0xFFFFFFFDU) | 1U;\n")
				b.WriteString("  state ^= (lr_model >> 1U);\n")
			}
		}
		// Emit a tiny stack-like local workspace when stack activity is evidenced.
		if cfg.StackRefCount >= 4 {
			wsLen := 4
			if cfg.FrameSize >= 16 {
				wsLen = 8
			}
			if cfg.FrameSize >= 32 {
				wsLen = 12
			}
			if wsLen > 16 {
				wsLen = 16
			}
			b.WriteString(fmt.Sprintf("  uint32_t local_ws[%d] = {0U};\n", wsLen))
			b.WriteString("  local_ws[0] = state;\n")
			if wsLen > 1 {
				b.WriteString("  local_ws[1] = state ^ 0x9e3779b9U;\n")
			}
			b.WriteString(fmt.Sprintf("  for (uint32_t i = 0U; i < %dU; ++i) {\n", wsLen))
			b.WriteString(fmt.Sprintf("    uint32_t j = (i + (state & 0x%XU)) %% %dU;\n", wsLen-1, wsLen))
			b.WriteString("    local_ws[j] ^= (state >> ((i & 7U) + 1U)) + (i << 4);\n")
			b.WriteString("  }\n")
			if len(cfg.TopStackOffs) > 0 {
				lim := len(cfg.TopStackOffs)
				if lim > 4 {
					lim = 4
				}
				b.WriteString(fmt.Sprintf("  static const int32_t stk_offs[%d] = {", lim))
				for i := 0; i < lim; i++ {
					if i > 0 {
						b.WriteString(", ")
					}
					b.WriteString(fmt.Sprintf("%d", cfg.TopStackOffs[i]))
				}
				b.WriteString("};\n")
				b.WriteString(fmt.Sprintf("  for (uint32_t i = 0U; i < %dU; ++i) {\n", lim))
				b.WriteString(fmt.Sprintf("    uint32_t idx = (uint32_t)((stk_offs[i] < 0 ? -stk_offs[i] : stk_offs[i]) & %dU);\n", wsLen-1))
				b.WriteString("    local_ws[idx] ^= state + (uint32_t)(stk_offs[i] & 0xFFFF);\n")
				b.WriteString("  }\n")
			}
			if cfg.StackOffMin != 0 || cfg.StackOffMax != 0 {
				b.WriteString(fmt.Sprintf("  state ^= (uint32_t)(%d - %d);\n", cfg.StackOffMax, cfg.StackOffMin))
			}
			b.WriteString(fmt.Sprintf("  state ^= local_ws[(state >> 3) & %dU];\n", wsLen-1))
		}
	}
	emitDomainScaffold(&b, fn)
	if emitSpecializedBody(&b, fn, t.Address, outgoing) {
		b.WriteString("  (void)state;\n")
		b.WriteString("}\n")
		return fileio.WriteBytes(path, []byte(b.String()))
	}
	if strings.HasPrefix(fn, "sub_") {
		_ = inferredSubAlias(fn, role, t.Image, incoming)
	}
	synthCalls := leafSyntheticCallees(fn, role, t.Image, incoming, outgoing)
	forceLeafTemplate := shouldPreferLeafTemplate(fn, outgoing, synthCalls)
	if len(outgoing) == 0 || forceLeafTemplate {
		if len(synthCalls) > 0 {
			seen := map[string]struct{}{}
			cmSel := int(callMixConst(fn, len(synthCalls)+0xF1) % 3)
			if cmSel == 0 {
				b.WriteString("  uint32_t chain_mix = state ^ 0x6d2b79f5U;\n")
			} else if cmSel == 1 {
				b.WriteString("  uint32_t chain_mix = (state << 5) ^ 0x6d2b79f5U;\n")
			} else {
				b.WriteString("  uint32_t chain_mix = (state >> 3) ^ 0x6d2b79f5U;\n")
			}
			maxCalls := 8
			if cfg != nil && cfg.CallsiteCount > 0 && cfg.CallsiteCount < maxCalls {
				maxCalls = cfg.CallsiteCount
				if maxCalls < 2 {
					maxCalls = 2
				}
			}
			emitted := 0
			for _, n := range synthCalls {
				n = sanitizeName(n)
				if n == "" || n == fn {
					continue
				}
				if (fn == "tx_submit" || fn == "log_queue_push") && n == "log_queue_alloc" {
					continue
				}
				if _, ok := seen[n]; ok {
					continue
				}
				seen[n] = struct{}{}
				b.WriteString("  " + n + "();\n")
				if cmSel == 0 {
					b.WriteString("  chain_mix = (chain_mix << 5) ^ (chain_mix >> 2) ^ 0x9e3779b9U;\n")
				} else if cmSel == 1 {
					b.WriteString("  chain_mix = (chain_mix >> 3) ^ (chain_mix << 4) ^ 0x9e3779b9U;\n")
				} else {
					b.WriteString("  chain_mix = (chain_mix << 1) ^ (chain_mix >> 5) ^ 0x9e3779b9U;\n")
				}
				b.WriteString(fmt.Sprintf("  state ^= (chain_mix & 0x%08xU);\n", callMixConst(fn, emitted+0x0f)|1))
				emitted++
				if emitted >= maxCalls {
					break
				}
			}
			cmTailSel := int(callMixConst(fn, emitted+0xD3) % 4)
			if cmTailSel == 0 {
				b.WriteString("  state ^= chain_mix;\n")
			} else if cmTailSel == 1 {
				b.WriteString("  state = (state + chain_mix) ^ (chain_mix >> 3U);\n")
			} else if cmTailSel == 2 {
				b.WriteString("  state ^= (chain_mix << 1U) | (chain_mix >> 31U);\n")
			} else {
				b.WriteString("  state = (state ^ chain_mix) + ((chain_mix >> 5U) & 0xFFFFU);\n")
			}
		} else {
			leafIters := 8
			if cfg != nil && cfg.BBCount > 0 {
				leafIters = cfg.BBCount
				if leafIters < 4 {
					leafIters = 4
				}
				if leafIters > 16 {
					leafIters = 16
				}
			}
			if (seed & 1) == 0 {
				b.WriteString("  static uint32_t leaf_state[8];\n")
				b.WriteString("  uint32_t idx = state & 7U;\n")
				b.WriteString(fmt.Sprintf("  for (uint32_t i = 0U; i < %dU; ++i) {\n", leafIters))
				b.WriteString("    uint32_t mix = (state << (i & 7U)) ^ (state >> ((8U - i) & 7U));\n")
				b.WriteString(fmt.Sprintf("    leaf_state[(idx + i) & 7U] ^= mix + (i * 0x%08xU);\n", callMixConst(fn, 0x12)))
				b.WriteString("  }\n")
				if cfg != nil && cfg.FrameSize > 0 {
					fsSel := int(callMixConst(fn, cfg.FrameSize+0xE7) % 3)
					if fsSel == 0 {
						b.WriteString(fmt.Sprintf("  state ^= 0x%08xU;\n", uint32(cfg.FrameSize)))
					} else if fsSel == 1 {
						b.WriteString(fmt.Sprintf("  state = (state + 0x%08xU) ^ (state >> 1U);\n", uint32(cfg.FrameSize)))
					} else {
						b.WriteString(fmt.Sprintf("  state ^= (0x%08xU + (state << 2U));\n", uint32(cfg.FrameSize)))
					}
				}
				b.WriteString("  state ^= leaf_state[idx];\n")
			} else {
				b.WriteString("  uint32_t acc = state ^ 0xA5A5A5A5U;\n")
				b.WriteString(fmt.Sprintf("  for (uint32_t i = 0U; i < %dU; ++i) {\n", leafIters))
				b.WriteString("    acc = (acc << 3) | (acc >> 29);\n")
				b.WriteString(fmt.Sprintf("    acc ^= (state >> (i & 7U)) + (0x%08xU * i);\n", callMixConst(fn, 0x13)))
				b.WriteString("  }\n")
				if cfg != nil && cfg.FrameSize > 0 {
					b.WriteString(fmt.Sprintf("  acc ^= 0x%08xU;\n", uint32(cfg.FrameSize)))
				}
				b.WriteString("  state ^= acc;\n")
			}
			emitNoCallFlavor(&b, fn)
			leafSel := int(callMixConst(fn, 0x24) % 3)
			if leafSel == 0 {
				b.WriteString(fmt.Sprintf("  state ^= 0x%08xU;\n", callMixConst(fn, 0x24)))
			} else if leafSel == 1 {
				b.WriteString(fmt.Sprintf("  state = (state + 0x%08xU) ^ (state >> 2U);\n", callMixConst(fn, 0x24)))
			} else {
				b.WriteString(fmt.Sprintf("  state ^= (0x%08xU + (state << 1U));\n", callMixConst(fn, 0x24)))
			}
			if len(incoming) > 0 {
				incSel := int(callMixConst(fn, len(incoming)+0x13) % 3)
				if incSel == 0 {
					b.WriteString(fmt.Sprintf("  state ^= 0x%08xU;\n", callMixConst(fn, len(incoming)+0x13)))
				} else if incSel == 1 {
					b.WriteString(fmt.Sprintf("  state = (state + 0x%08xU) ^ (state >> 3U);\n", callMixConst(fn, len(incoming)+0x13)))
				} else {
					b.WriteString(fmt.Sprintf("  state ^= (0x%08xU + (state << 2U));\n", callMixConst(fn, len(incoming)+0x13)))
				}
			}
		}
	} else {
		_, _, _ = skeletonPhases(fn, role)
		seen := map[string]struct{}{}
		emitted := emitControlCalls(&b, fn, outgoing, seen, cfg)
		emitted += emitXrefScheduledCalls(&b, fn, outgoing, seen, cfg)
		if fn == "log_queue_push" && emitted == 0 {
			b.WriteString("  tx_dequeue();\n")
			b.WriteString("  state ^= 0xD00D00D0U;\n")
		}
		if cfg != nil && cfg.CallsiteCount > 0 {
			if cfg.HasLoop && cfg.BBCount >= 8 {
				b.WriteString("  uint32_t tail = (state ^ 0xC3C3C3C3U) + ((state << 5) | (state >> 27));\n")
				b.WriteString("  tail ^= (tail >> 11);\n")
				b.WriteString(fmt.Sprintf("  tail ^= ((uint32_t)%dU << 9);\n", cfg.EdgeCount))
				b.WriteString("  state ^= tail;\n")
			} else if cfg.CallsiteCount >= 4 {
				b.WriteString("  uint32_t tail = (uint32_t)(0xC3C30000U | ((state >> 3) & 0xFFFFU));\n")
				b.WriteString(fmt.Sprintf("  tail ^= ((uint32_t)%dU << 10);\n", cfg.CallsiteCount))
				b.WriteString("  state ^= tail;\n")
			} else {
				tcSel := int(callMixConst(fn, cfg.CallsiteCount+0x2A) % 3)
				if tcSel == 0 {
					b.WriteString(fmt.Sprintf("  state ^= 0x%08xU;\n", callMixConst(fn, cfg.CallsiteCount+0x2A)))
				} else if tcSel == 1 {
					b.WriteString(fmt.Sprintf("  state = (state + 0x%08xU) ^ (state >> 2U);\n", callMixConst(fn, cfg.CallsiteCount+0x2A)))
				} else {
					b.WriteString(fmt.Sprintf("  state ^= (0x%08xU + (state << 1U));\n", callMixConst(fn, cfg.CallsiteCount+0x2A)))
				}
			}
		} else {
			toSel := int(callMixConst(fn, len(outgoing)+3) % 3)
			if toSel == 0 {
				b.WriteString(fmt.Sprintf("  state ^= 0x%08xU;\n", callMixConst(fn, len(outgoing)+3)))
			} else if toSel == 1 {
				b.WriteString(fmt.Sprintf("  state = (state + 0x%08xU) ^ (state >> 2U);\n", callMixConst(fn, len(outgoing)+3)))
			} else {
				b.WriteString(fmt.Sprintf("  state ^= (0x%08xU + (state << 1U));\n", callMixConst(fn, len(outgoing)+3)))
			}
		}
	}
	b.WriteString("  (void)state;\n")
	b.WriteString("}\n")
	return fileio.WriteBytes(path, []byte(b.String()))
}

func emitNoCallFlavor(b *strings.Builder, fn string) {
	fn = sanitizeName(fn)
	v := int(callMixConst(fn, 0x5D) % 3)
	switch {
	case strings.HasPrefix(fn, "txl_") || strings.HasPrefix(fn, "rxl_") || strings.HasPrefix(fn, "rc_"):
		if v == 0 {
			b.WriteString("  uint32_t qmask = (state >> 4U) & 0x3FU;\n")
			b.WriteString("  uint32_t qacc = 0U;\n")
			b.WriteString("  for (uint32_t qi = 0U; qi < 4U; ++qi) {\n")
			b.WriteString("    qacc ^= ((qmask + qi) << (qi + 1U));\n")
			b.WriteString("  }\n")
			b.WriteString("  state ^= qacc;\n")
		} else if v == 1 {
			b.WriteString("  uint32_t qmask = (state >> 3U) & 0x7FU;\n")
			b.WriteString("  uint32_t qacc = state ^ 0x00C3C3C3U;\n")
			b.WriteString("  for (uint32_t qi = 0U; qi < 3U; ++qi) {\n")
			b.WriteString("    qacc = (qacc << 2U) ^ (qmask + (qi << 3U));\n")
			b.WriteString("  }\n")
			b.WriteString("  state ^= qacc;\n")
		} else {
			b.WriteString("  uint32_t qmask = (state >> 5U) & 0x1FU;\n")
			b.WriteString("  uint32_t qacc = 0x5A5A5A5AU;\n")
			b.WriteString("  for (uint32_t qi = 0U; qi < 5U; ++qi) {\n")
			b.WriteString("    qacc ^= ((qmask ^ qi) << ((qi & 3U) + 1U));\n")
			b.WriteString("  }\n")
			b.WriteString("  state ^= qacc;\n")
		}
	case strings.HasPrefix(fn, "mm_") || strings.HasPrefix(fn, "sm_") || strings.HasPrefix(fn, "apm_"):
		if v == 0 {
			b.WriteString("  uint32_t fsm = (state ^ 0x13579BDFU) & 0xFFU;\n")
			b.WriteString("  for (uint32_t si = 0U; si < 3U; ++si) {\n")
			b.WriteString("    fsm = ((fsm << 1U) | (fsm >> 7U)) ^ (0x21U + si);\n")
			b.WriteString("  }\n")
			b.WriteString("  state ^= fsm;\n")
		} else if v == 1 {
			b.WriteString("  uint32_t fsm = (state ^ 0x2468ACE0U) & 0x1FFU;\n")
			b.WriteString("  for (uint32_t si = 0U; si < 4U; ++si) {\n")
			b.WriteString("    fsm = ((fsm >> 1U) | (fsm << 8U)) ^ (0x11U * (si + 1U));\n")
			b.WriteString("  }\n")
			b.WriteString("  state ^= (fsm & 0xFFU);\n")
		} else {
			b.WriteString("  uint32_t fsm = (state ^ 0x31415926U) & 0xFFU;\n")
			b.WriteString("  uint32_t ev = (state >> 6U) & 0x3FU;\n")
			b.WriteString("  for (uint32_t si = 0U; si < 3U; ++si) {\n")
			b.WriteString("    fsm ^= (ev + si) << (si + 1U);\n")
			b.WriteString("  }\n")
			b.WriteString("  state ^= fsm;\n")
		}
	case strings.HasPrefix(fn, "ke_") || strings.HasPrefix(fn, "co_") || strings.HasPrefix(fn, "hal_") || strings.HasPrefix(fn, "phy_"):
		if v == 0 {
			b.WriteString("  uint32_t irq = (state >> 2U) & 0x1FFU;\n")
			b.WriteString("  state ^= ((irq << 5U) | (irq >> 4U));\n")
		} else if v == 1 {
			b.WriteString("  uint32_t irq = (state >> 1U) & 0x3FFU;\n")
			b.WriteString("  state ^= (irq << 3U) ^ (irq >> 2U);\n")
		} else {
			b.WriteString("  uint32_t irq = (state >> 4U) & 0xFFU;\n")
			b.WriteString("  state ^= ((irq << 7U) | (irq >> 1U));\n")
		}
	case strings.HasPrefix(fn, "bam_") || strings.HasPrefix(fn, "host_"):
		if v == 0 {
			b.WriteString("  uint32_t ch = state & 0xFU;\n")
			b.WriteString("  state ^= (ch << 12U) ^ ((ch + 3U) << 4U);\n")
		} else if v == 1 {
			b.WriteString("  uint32_t ch = (state >> 2U) & 0x1FU;\n")
			b.WriteString("  state ^= (ch << 10U) ^ ((ch + 1U) << 5U);\n")
		} else {
			b.WriteString("  uint32_t ch = (state >> 1U) & 0xFU;\n")
			b.WriteString("  state ^= ((ch * 3U) << 8U) ^ ((ch + 5U) << 3U);\n")
		}
	}
}

func loadCFGHints(path string) (map[string]cfgHint, map[string]cfgHint, error) {
	f, err := os.Open(path)
	if err != nil {
		return map[string]cfgHint{}, map[string]cfgHint{}, err
	}
	defer f.Close()
	byAddr := map[string]cfgHint{}
	byName := map[string]cfgHint{}
	sc := bufio.NewScanner(f)
	sc.Buffer(make([]byte, 4096), 8*1024*1024)
	for sc.Scan() {
		line := strings.TrimSpace(sc.Text())
		if line == "" {
			continue
		}
		var h cfgHint
		if json.Unmarshal([]byte(line), &h) != nil {
			continue
		}
		if strings.TrimSpace(h.SchemaVersion) != "" && h.SchemaVersion != "0.1.0" {
			return map[string]cfgHint{}, map[string]cfgHint{}, fmt.Errorf("cfg hints schema mismatch: got %s want 0.1.0", h.SchemaVersion)
		}
		if strings.TrimSpace(h.Address) != "" {
			byAddr[addrKey(h.Image, h.Address)] = h
		}
		n := sanitizeName(h.Name)
		if n != "" && n != "unknown" {
			byName[strings.ToLower(strings.TrimSpace(h.Image))+"|"+n] = h
		}
	}
	return byAddr, byName, sc.Err()
}

func cfgForTask(t implTask, byAddr, byName map[string]cfgHint) *cfgHint {
	if h, ok := byAddr[addrKey(t.Image, t.Address)]; ok {
		return &h
	}
	if alt, ok := normalizeAddrVariants(t.Address); ok {
		for _, a := range alt {
			if h, ok := byAddr[addrKey(t.Image, a)]; ok {
				return &h
			}
		}
	}
	n := sanitizeName(t.Function)
	if n == "" || n == "unknown" {
		return nil
	}
	if h, ok := byName[strings.ToLower(strings.TrimSpace(t.Image))+"|"+n]; ok {
		return &h
	}
	return nil
}

func loadPseudoHints(path string) (map[string]pseudoHint, map[string]pseudoHint, error) {
	f, err := os.Open(path)
	if err != nil {
		return map[string]pseudoHint{}, map[string]pseudoHint{}, err
	}
	defer f.Close()
	byAddr := map[string]pseudoHint{}
	byName := map[string]pseudoHint{}
	sc := bufio.NewScanner(f)
	sc.Buffer(make([]byte, 4096), 16*1024*1024)
	for sc.Scan() {
		line := strings.TrimSpace(sc.Text())
		if line == "" {
			continue
		}
		var h pseudoHint
		if json.Unmarshal([]byte(line), &h) != nil {
			continue
		}
		if strings.TrimSpace(h.Address) != "" {
			byAddr[addrKey(h.Image, h.Address)] = h
		}
		n := sanitizeName(h.Name)
		if n != "" && n != "unknown" {
			byName[strings.ToLower(strings.TrimSpace(h.Image))+"|"+n] = h
		}
	}
	return byAddr, byName, sc.Err()
}

func pseudoForTask(t implTask, byAddr, byName map[string]pseudoHint) *pseudoHint {
	if h, ok := byAddr[addrKey(t.Image, t.Address)]; ok {
		return &h
	}
	if alt, ok := normalizeAddrVariants(t.Address); ok {
		for _, a := range alt {
			if h, ok := byAddr[addrKey(t.Image, a)]; ok {
				return &h
			}
		}
	}
	n := sanitizeName(t.Function)
	if n == "" || n == "unknown" {
		return nil
	}
	if h, ok := byName[strings.ToLower(strings.TrimSpace(t.Image))+"|"+n]; ok {
		return &h
	}
	return nil
}

func normalizeAddrVariants(addr string) ([]string, bool) {
	a := strings.TrimSpace(strings.ToLower(addr))
	if a == "" {
		return nil, false
	}
	if !strings.HasPrefix(a, "0x") {
		a = "0x" + a
	}
	v, err := parseHexAddr(a)
	if err != nil {
		return nil, false
	}
	alts := []string{fmt.Sprintf("0x%x", v)}
	bases := []uint64{0x120000, 0x11f0000, 0x1200000, 0x1100000, 0x10f0000}
	for _, base := range bases {
		if v > base {
			alts = append(alts, fmt.Sprintf("0x%x", v-base))
		}
		alts = append(alts, fmt.Sprintf("0x%x", v+base))
	}
	seen := map[string]struct{}{}
	out := make([]string, 0, len(alts))
	for _, x := range alts {
		if _, ok := seen[x]; ok {
			continue
		}
		seen[x] = struct{}{}
		out = append(out, x)
	}
	return out, true
}

func parseHexAddr(s string) (uint64, error) {
	s = strings.TrimSpace(strings.ToLower(s))
	if strings.HasPrefix(s, "0x") {
		s = strings.TrimPrefix(s, "0x")
	}
	if s == "" {
		return 0, fmt.Errorf("empty")
	}
	var v uint64
	for _, r := range s {
		v <<= 4
		switch {
		case r >= '0' && r <= '9':
			v += uint64(r - '0')
		case r >= 'a' && r <= 'f':
			v += uint64(r-'a') + 10
		default:
			return 0, fmt.Errorf("bad hex")
		}
	}
	return v, nil
}

var pseudoMemoryAddrRE = regexp.MustCompile(`MEMORY\[0x([0-9A-Fa-f]+)\]`)

func extractPseudoMemoryAddrs(text string, limit int) []uint32 {
	if limit <= 0 {
		limit = 8
	}
	matches := pseudoMemoryAddrRE.FindAllStringSubmatch(text, -1)
	out := make([]uint32, 0, minInt(len(matches), limit))
	seen := map[uint32]struct{}{}
	for _, m := range matches {
		if len(m) < 2 {
			continue
		}
		v, err := parseHexAddr(m[1])
		if err != nil {
			continue
		}
		vv := uint32(v)
		if _, ok := seen[vv]; ok {
			continue
		}
		seen[vv] = struct{}{}
		out = append(out, vv)
		if len(out) >= limit {
			break
		}
	}
	return out
}

func pseudoDistinctCallNames(fn string, pseudo *pseudoHint) []string {
	seen := map[string]struct{}{}
	out := make([]string, 0, len(pseudo.CallNames))
	for _, name := range pseudo.CallNames {
		callName := sanitizeName(name)
		if callName == "" || callName == "unknown" || callName == fn {
			continue
		}
		if strings.HasPrefix(callName, "__") {
			continue
		}
		if _, ok := seen[callName]; ok {
			continue
		}
		seen[callName] = struct{}{}
		out = append(out, callName)
	}
	return out
}

func pseudoHasCallName(pseudo *pseudoHint, names ...string) bool {
	if pseudo == nil {
		return false
	}
	need := map[string]struct{}{}
	for _, name := range names {
		need[strings.ToLower(strings.TrimSpace(name))] = struct{}{}
	}
	for _, name := range pseudo.CallNames {
		if _, ok := need[strings.ToLower(strings.TrimSpace(name))]; ok {
			return true
		}
	}
	return false
}

func detectPseudocodeMotif(pseudo *pseudoHint, cfg *cfgHint, behaviorRole string) string {
	if pseudo == nil {
		return ""
	}
	text := strings.ToLower(pseudo.Pseudocode)
	role := strings.ToLower(strings.TrimSpace(behaviorRole))
	if (strings.Contains(text, "__get_cpsr") || pseudoHasCallName(pseudo, "__get_CPSR")) &&
		(strings.Contains(text, "__disable_irq") || pseudoHasCallName(pseudo, "__disable_irq")) &&
		(strings.Contains(text, "__enable_irq") || pseudoHasCallName(pseudo, "__enable_irq")) &&
		pseudo.LoopCount > 0 {
		return "irq_wait_guard"
	}
	if strings.Contains(text, "return 1;") &&
		strings.Contains(text, "return 0;") &&
		strings.Contains(text, " = 4;") &&
		strings.Contains(text, " = 3;") &&
		cfg != nil && cfg.CallsiteCount >= 2 {
		return "callback_state_gate"
	}
	if len(pseudo.MMIOAddrs) > 0 && pseudo.LoopCount > 0 && cfg != nil && cfg.LoadCount >= 4 && cfg.StoreCount >= 4 {
		if strings.Contains(role, "transfer") || strings.Contains(role, "dma") || strings.Contains(role, "copy") || strings.Contains(role, "io") {
			return "staged_mmio_transfer"
		}
		if cfg.LoadWordCount >= 4 && cfg.StoreWordCount >= 2 && cfg.CallsiteCount <= 2 {
			return "staged_mmio_transfer"
		}
	}
	return ""
}

func emitCallbackStateGateMotif(b *strings.Builder, fn string, pseudo *pseudoHint) bool {
	addrs := extractPseudoMemoryAddrs(pseudo.Pseudocode, 6)
	if len(addrs) < 2 {
		return false
	}
	stateAddr := addrs[0]
	activeAddr := addrs[1]
	callbackAddr := activeAddr
	phaseAddr := stateAddr
	if len(addrs) > 2 {
		callbackAddr = addrs[2]
	}
	if len(addrs) > 3 {
		phaseAddr = addrs[len(addrs)-1]
	}
	calls := pseudoDistinctCallNames(fn, pseudo)
	b.WriteString("  // Motif: callback-gated state transition from Hex-Rays pseudocode\n")
	b.WriteString(fmt.Sprintf("  volatile uint32_t *state_slot = (volatile uint32_t *)(uintptr_t)0x%08XU;\n", stateAddr))
	b.WriteString(fmt.Sprintf("  volatile uint32_t *active_slot = (volatile uint32_t *)(uintptr_t)0x%08XU;\n", activeAddr))
	b.WriteString(fmt.Sprintf("  volatile uint32_t *callback_slot = (volatile uint32_t *)(uintptr_t)0x%08XU;\n", callbackAddr))
	b.WriteString(fmt.Sprintf("  volatile uint32_t *phase_slot = (volatile uint32_t *)(uintptr_t)0x%08XU;\n", phaseAddr))
	b.WriteString("  uint32_t active = active_slot[0];\n")
	b.WriteString("  state_slot[0] = active;\n")
	b.WriteString("  if (active != 0U) {\n")
	b.WriteString("    uint32_t callback_ready = callback_slot[0] != 0U;\n")
	b.WriteString("    if (callback_ready && ((state ^ active) & 1U) == 0U) {\n")
	b.WriteString("      ((volatile uint8_t *)state_slot)[3] = 4U;\n")
	b.WriteString("      phase_slot[0] = 7U;\n")
	if len(calls) > 0 {
		b.WriteString("      uint32_t helper_ok = 1U;\n")
		b.WriteString("      " + calls[0] + "();\n")
		b.WriteString("      helper_ok ^= state & 1U;\n")
		if len(calls) > 1 {
			b.WriteString("      if ((helper_ok & 1U) == 0U) { " + calls[1] + "(); }\n")
		}
	}
	b.WriteString("      state ^= active ^ phase_slot[0];\n")
	b.WriteString("    } else {\n")
	b.WriteString("      state ^= active ^ callback_slot[0] ^ 0xBAD00000U;\n")
	b.WriteString("    }\n")
	b.WriteString("  } else {\n")
	b.WriteString("    ((volatile uint8_t *)state_slot)[3] = 3U;\n")
	b.WriteString("    state ^= state_slot[0] ^ 3U;\n")
	b.WriteString("  }\n")
	return true
}

func emitIRQWaitGuardMotif(b *strings.Builder, pseudo *pseudoHint) bool {
	addrs := extractPseudoMemoryAddrs(pseudo.Pseudocode, 4)
	if len(addrs) < 3 {
		return false
	}
	guardAddr := addrs[0]
	irqDepthAddr := addrs[1]
	flagAddr := addrs[2]
	mmioAddr := uint32(0x40000000)
	if len(pseudo.MMIOAddrs) > 0 {
		if v, err := parseHexAddr(pseudo.MMIOAddrs[0]); err == nil {
			mmioAddr = uint32(v)
		}
	}
	b.WriteString("  // Motif: IRQ guard plus bounded hardware wait from Hex-Rays pseudocode\n")
	b.WriteString(fmt.Sprintf("  volatile uint32_t *guard = (volatile uint32_t *)(uintptr_t)0x%08XU;\n", guardAddr))
	b.WriteString(fmt.Sprintf("  volatile uint32_t *irq_depth = (volatile uint32_t *)(uintptr_t)0x%08XU;\n", irqDepthAddr))
	b.WriteString(fmt.Sprintf("  volatile uint32_t *wait_flag = (volatile uint32_t *)(uintptr_t)0x%08XU;\n", flagAddr))
	b.WriteString(fmt.Sprintf("  volatile uint32_t *mmio = (volatile uint32_t *)(uintptr_t)0x%08XU;\n", mmioAddr))
	b.WriteString("  if ((state & 1U) == 0U) {\n")
	b.WriteString("    guard[0] = 1U;\n")
	b.WriteString("  }\n")
	b.WriteString("  uint32_t depth = ++irq_depth[0];\n")
	b.WriteString("  if ((wait_flag[0] & 0xFFU) != 0U) {\n")
	b.WriteString("    mmio[0] |= 1U;\n")
	b.WriteString("    for (uint32_t spin = 24U; spin > 0U; --spin) {\n")
	b.WriteString("      state ^= mmio[0] ^ spin;\n")
	b.WriteString("      if ((spin & 7U) == 0U) { wait_flag[0] &= ~0xFFU; }\n")
	b.WriteString("    }\n")
	b.WriteString("    mmio[0] &= ~1U;\n")
	b.WriteString("  }\n")
	b.WriteString("  if (depth != 0U) {\n")
	b.WriteString("    irq_depth[0] = depth - 1U;\n")
	b.WriteString("    if (depth == 1U && guard[0] != 0U) { guard[0] = 0U; }\n")
	b.WriteString("  }\n")
	return true
}

func emitStagedMMIOTransferMotif(b *strings.Builder, pseudo *pseudoHint, cfg *cfgHint) bool {
	mmioAddr := uint32(0x40000000)
	if len(pseudo.MMIOAddrs) > 0 {
		if v, err := parseHexAddr(pseudo.MMIOAddrs[0]); err == nil {
			mmioAddr = uint32(v)
		}
	}
	blocks := 8
	if cfg != nil {
		blocks = minInt(24, maxInt(8, cfg.LoadCount+cfg.StoreCount))
	}
	b.WriteString("  // Motif: staged MMIO transfer with bounded completion polling\n")
	b.WriteString(fmt.Sprintf("  volatile uint32_t *mmio = (volatile uint32_t *)(uintptr_t)0x%08XU;\n", mmioAddr))
	b.WriteString("  volatile uint8_t *src = (volatile uint8_t *)(uintptr_t)(0x20000000U + (state & 0x1FFU));\n")
	b.WriteString("  volatile uint8_t *dst = (volatile uint8_t *)(uintptr_t)(0x20000400U + (state & 0x1FFU));\n")
	b.WriteString(fmt.Sprintf("  uint32_t blocks = %dU;\n", blocks))
	b.WriteString("  uint32_t acc = 0U;\n")
	b.WriteString("  for (uint32_t blk = 0U; blk < blocks; ++blk) {\n")
	b.WriteString("    uint8_t v = src[blk & 0x3FU] ^ (uint8_t)(blk + state);\n")
	b.WriteString("    dst[blk & 0x3FU] = v;\n")
	b.WriteString("    acc += v;\n")
	b.WriteString("    mmio[blk & 3U] = (blk << 16U) | v;\n")
	b.WriteString("    if ((blk & 1U) == 0U) { state ^= mmio[blk & 3U]; }\n")
	b.WriteString("  }\n")
	b.WriteString("  mmio[1] = 3U;\n")
	b.WriteString("  for (uint32_t wait = 32U; wait > 0U; --wait) {\n")
	b.WriteString("    uint32_t st = mmio[1] & 3U;\n")
	b.WriteString("    state ^= st + acc + wait;\n")
	b.WriteString("    if ((wait & 7U) == 0U) { mmio[1] = 0U; }\n")
	b.WriteString("    if (st == 0U) { break; }\n")
	b.WriteString("  }\n")
	b.WriteString("  mmio[2] = acc ^ state;\n")
	return true
}

func emitPseudocodeStructuredBody(b *strings.Builder, fn string, pseudo *pseudoHint, cfg *cfgHint, outgoing []callEdge, behaviorRole string) bool {
	if pseudo == nil {
		return false
	}
	if pseudo.LineCount == 0 && pseudo.LoopCount == 0 && pseudo.SwitchCount == 0 && len(pseudo.CallNames) == 0 {
		return false
	}
	switch detectPseudocodeMotif(pseudo, cfg, behaviorRole) {
	case "callback_state_gate":
		if emitCallbackStateGateMotif(b, fn, pseudo) {
			return true
		}
	case "irq_wait_guard":
		if emitIRQWaitGuardMotif(b, pseudo) {
			return true
		}
	case "staged_mmio_transfer":
		if emitStagedMMIOTransferMotif(b, pseudo, cfg) {
			return true
		}
	}
	base := "0x40000000U"
	if len(pseudo.MMIOAddrs) > 0 {
		base = fmt.Sprintf("(uintptr_t)%sU", strings.TrimSuffix(pseudo.MMIOAddrs[0], "u"))
	}
	b.WriteString("  // Structured from IDA Hex-Rays pseudocode\n")
	b.WriteString(fmt.Sprintf("  volatile uint32_t *ida_reg = (volatile uint32_t *)%s;\n", base))
	loopIters := minInt(12, maxInt(2, pseudo.LoopCount*3))
	if pseudo.LoopCount > 0 {
		b.WriteString(fmt.Sprintf("  for (uint32_t li = 0U; li < %dU; ++li) {\n", loopIters))
		b.WriteString("    state ^= ida_reg[li & 3U] + (li << 4U);\n")
		if pseudo.IfCount > 0 {
			b.WriteString("    if (((state >> (li & 7U)) & 1U) != 0U) {\n")
			b.WriteString("      ida_reg[(li + 1U) & 3U] = state ^ li;\n")
			b.WriteString("    } else {\n")
			b.WriteString("      state ^= ida_reg[(li + 2U) & 3U];\n")
			b.WriteString("    }\n")
		}
		b.WriteString("  }\n")
	}
	if pseudo.SwitchCount > 0 {
		cases := minInt(4, maxInt(2, pseudo.SwitchCount+1))
		b.WriteString(fmt.Sprintf("  switch (state & 0x%xU) {\n", cases-1))
		for i := 0; i < cases; i++ {
			b.WriteString(fmt.Sprintf("  case %dU:\n", i))
			b.WriteString(fmt.Sprintf("    ida_reg[%dU & 3U] = state ^ 0x%08xU;\n", i, callMixConst(fn, 0x40+i)))
			if i < len(pseudo.CallNames) {
				callName := sanitizeName(pseudo.CallNames[i])
				if callName != "" && callName != "unknown" && callName != fn {
					b.WriteString("    " + callName + "();\n")
				}
			}
			b.WriteString("    break;\n")
		}
		b.WriteString("  default:\n")
		b.WriteString("    state ^= ida_reg[0];\n")
		b.WriteString("    break;\n")
		b.WriteString("  }\n")
	}
	callBudget := 0
	for _, name := range pseudo.CallNames {
		callName := sanitizeName(name)
		if callName == "" || callName == "unknown" || callName == fn {
			continue
		}
		b.WriteString("  " + callName + "();\n")
		callBudget++
		if callBudget >= 3 {
			break
		}
	}
	if callBudget == 0 {
		seen := map[string]struct{}{}
		for _, e := range outgoing {
			callName := sanitizeName(nonEmpty(e.TargetName, ""))
			if callName == "" || callName == "unknown" || callName == fn {
				continue
			}
			if _, ok := seen[callName]; ok {
				continue
			}
			seen[callName] = struct{}{}
			b.WriteString("  " + callName + "();\n")
			callBudget++
			if callBudget >= 2 {
				break
			}
		}
	}
	b.WriteString("  state ^= ida_reg[0] ^ ida_reg[1];\n")
	return true
}

// emitBehavioralClassBody generates class-specific firmware code that exercises
// realistic hardware patterns instead of generic state-xor stubs.
// Returns true if a meaningful body was emitted.
func emitBehavioralClassBody(b *strings.Builder, fn, role, cls, addr string) bool {
	switch role {
	case "radio_reg_write":
		return emitRadioRegWriteBody(b, fn, addr)
	case "io_driver":
		return emitIODriverBody(b, fn, addr)
	case "interrupt_handler":
		return emitInterruptBody(b, fn, addr)
	case "dispatcher":
		return emitDispatchBody(b, fn, addr)
	case "crypto_core":
		return emitCryptoBody(b, fn, addr)
	case "memory_pool":
		return emitMemoryPoolBody(b, fn, addr)
	case "state_machine":
		return emitStateMachineBody(b, fn, addr)
	case "init_sequence":
		return emitInitSequenceBody(b, fn, addr)
	case "error_handler":
		return emitErrorHandlerBody(b, fn, addr)
	case "patch_apply":
		return emitPatchBody(b, fn, addr)
	}
	return false
}

func emitRadioRegWriteBody(b *strings.Builder, fn, addr string) bool {
	seed := synthSeed(fn, addr)
	b.WriteString("  // Radio register write: pattern derived from behavioral class radio_control\n")
	base := uint32(0x40010000) | (seed & 0xFF00)
	b.WriteString(fmt.Sprintf("  volatile uint32_t *rf_reg = (volatile uint32_t *)(uintptr_t)0x%08xU;\n", base))
	b.WriteString(fmt.Sprintf("  rf_reg[0] = 0x%08xU;\n", seed))
	b.WriteString(fmt.Sprintf("  rf_reg[1] = 0x%08xU;\n", seed^0x55555555))
	b.WriteString(fmt.Sprintf("  rf_reg[2] = 0x%08xU;\n", seed^0xAAAAAAAA))
	b.WriteString("  uint32_t status = rf_reg[3];\n")
	b.WriteString(fmt.Sprintf("  rf_reg[0x%xU & 0xFU] = status ^ 0x5A5A5A5AU;\n", (seed>>4)&0xF))
	b.WriteString(fmt.Sprintf("  rf_reg[0x%xU & 0xFU] = 0x%08xU;\n", (seed>>8)&0xF, seed^0x3C3C3C3C))
	b.WriteString(fmt.Sprintf("  state ^= status ^ (uint32_t)(uintptr_t)rf_reg;\n"))
	return true
}

func emitIODriverBody(b *strings.Builder, fn, addr string) bool {
	seed := synthSeed(fn, addr)
	b.WriteString("  // I/O driver: pattern derived from behavioral class dma_io\n")
	dmaBase := uint32(0x40020000) | (seed & 0xFC00)
	b.WriteString(fmt.Sprintf("  volatile uint32_t *dma = (volatile uint32_t *)(uintptr_t)0x%08xU;\n", dmaBase))
	b.WriteString("  volatile uint8_t *buf = (volatile uint8_t *)(uintptr_t)(0x20000000U + (state & 0xFFFU));\n")
	cnt := (seed & 0xF) + 1
	b.WriteString(fmt.Sprintf("  for (uint32_t i = 0U; i < %dU; ++i) {\n", cnt))
	b.WriteString("    dma[i & 0x3U] = (uint32_t)buf[i];\n")
	b.WriteString("  }\n")
	b.WriteString(fmt.Sprintf("  dma[%dU & 0x3U] |= 0x1U;\n", cnt&3))
	b.WriteString("  uint32_t dma_wait = 24U + (state & 0xFU);\n")
	b.WriteString("  while ((dma[0] & 0x1U) && dma_wait-- > 0U) {\n")
	b.WriteString("    state ^= dma_wait ^ dma[1];\n")
	b.WriteString("    if ((dma_wait & 0x3U) == 0U) { dma[0] &= ~0x1U; }\n")
	b.WriteString("  }\n")
	b.WriteString("  dma[0] &= ~0x1U;\n")
	b.WriteString(fmt.Sprintf("  state ^= dma[%dU & 0x3U] ^ (uint32_t)(uintptr_t)buf;\n", (cnt+1)&3))
	return true
}

func emitInterruptBody(b *strings.Builder, fn, addr string) bool {
	seed := synthSeed(fn, addr)
	b.WriteString("  // Interrupt handler: pattern derived from behavioral class timer_callback\n")
	nvicBase := uint32(0xE000E100) + (seed & 0xFF0)
	b.WriteString(fmt.Sprintf("  volatile uint32_t *nvic = (volatile uint32_t *)(uintptr_t)0x%08xU;\n", nvicBase))
	b.WriteString("  uint32_t pending = nvic[0];\n")
	b.WriteString(fmt.Sprintf("  if (pending & 0x%08xU) {\n", seed|1))
	b.WriteString(fmt.Sprintf("    nvic[0x%xU] = pending & ~0x%08xU;\n", (seed>>2)&0x7, seed|1))
	b.WriteString("    state ^= pending;\n")
	b.WriteString("  } else {\n")
	b.WriteString("    state ^= 0xDEAD0001U;\n")
	b.WriteString("  }\n")
	b.WriteString(fmt.Sprintf("  volatile uint32_t *timer = (volatile uint32_t *)(uintptr_t)0x%08xU;\n", 0x40000000|(seed&0xFFFF0)))
	b.WriteString("  timer[0] = state;\n")
	b.WriteString(fmt.Sprintf("  state ^= timer[%dU & 0x3U];\n", (seed>>4)&3))
	return true
}

func emitDispatchBody(b *strings.Builder, fn, addr string) bool {
	seed := synthSeed(fn, addr)
	b.WriteString("  // Message dispatch: pattern derived from behavioral class message_handler\n")
	cases := int(seed&0x7) + 2
	b.WriteString("  uint32_t msg_type = state & 0xFU;\n")
	b.WriteString(fmt.Sprintf("  volatile uint32_t *mbox = (volatile uint32_t *)(uintptr_t)0x%08xU;\n", 0x40000000|(seed&0xFFFF80)))
	b.WriteString(fmt.Sprintf("  uint32_t msg = mbox[msg_type & 0x%xU];\n", cases-1))
	b.WriteString(fmt.Sprintf("  switch (msg_type) {\n"))
	for i := 0; i < cases; i++ {
		b.WriteString(fmt.Sprintf("  case %dU:\n", i))
		b.WriteString(fmt.Sprintf("    mbox[%dU] = 0x%08xU ^ msg;\n", i, seed^(uint32(i)*0x11111111)))
		b.WriteString("    break;\n")
	}
	b.WriteString("  default:\n")
	b.WriteString("    mbox[0] = 0xBADF0000U | msg_type;\n")
	b.WriteString("    break;\n")
	b.WriteString("  }\n")
	b.WriteString("  state ^= msg ^ msg_type;\n")
	return true
}

func emitCryptoBody(b *strings.Builder, fn, addr string) bool {
	seed := synthSeed(fn, addr)
	b.WriteString("  // Crypto engine: pattern derived from behavioral class crypto_security\n")
	cryptoBase := uint32(0x40030000) | (seed & 0xFF00)
	b.WriteString(fmt.Sprintf("  volatile uint32_t *crypto = (volatile uint32_t *)(uintptr_t)0x%08xU;\n", cryptoBase))
	b.WriteString("  crypto[0] = 0x1U;\n")                                          // enable
	b.WriteString(fmt.Sprintf("  crypto[1] = 0x%08xU;\n", seed))                    // key word 0
	b.WriteString(fmt.Sprintf("  crypto[2] = 0x%08xU;\n", seed^0x36363636))         // key word 1
	b.WriteString(fmt.Sprintf("  crypto[3] = 0x%08xU;\n", seed^0x5C5C5C5C))         // IV
	b.WriteString("  crypto[4] = 0x10U;\n")                                         // data length
	b.WriteString(fmt.Sprintf("  crypto[5] = 0x%08xU;\n", 0x20000000|(seed&0xFFF))) // src addr
	b.WriteString(fmt.Sprintf("  crypto[6] = 0x%08xU;\n", 0x20001000|(seed&0xFFF))) // dst addr
	b.WriteString("  crypto[0] |= 0x2U;\n")                                         // start
	b.WriteString("  uint32_t crypto_wait = 32U + ((state >> 2U) & 0x1FU);\n")
	b.WriteString("  while ((crypto[0] & 0x2U) && crypto_wait-- > 0U) {\n")
	b.WriteString("    state ^= crypto_wait ^ crypto[1];\n")
	b.WriteString("    if ((crypto_wait & 0x7U) == 0U) { crypto[0] &= ~0x2U; }\n")
	b.WriteString("  }\n")
	b.WriteString("  crypto[0] &= ~0x2U;\n")
	b.WriteString("  state ^= crypto[7] ^ crypto[8];\n")
	return true
}

func emitMemoryPoolBody(b *strings.Builder, fn, addr string) bool {
	seed := synthSeed(fn, addr)
	b.WriteString("  // Memory pool: pattern derived from behavioral class memory_pool\n")
	b.WriteString(fmt.Sprintf("  volatile uint32_t *pool = (volatile uint32_t *)(uintptr_t)0x%08xU;\n", 0x20000000|(seed&0xFFFC)))
	b.WriteString("  uint32_t head = pool[0];\n")
	b.WriteString("  if (head != 0U) {\n")
	b.WriteString("    pool[0] = pool[head & 0xFFU];\n")
	b.WriteString("    pool[head & 0xFFU] = state;\n")
	b.WriteString("    state ^= head;\n")
	b.WriteString("  } else {\n")
	b.WriteString("    state ^= 0xDEADBEEFU;\n")
	b.WriteString("  }\n")
	b.WriteString("  state ^= pool[0] ^ (uint32_t)(uintptr_t)pool;\n")
	return true
}

func emitStateMachineBody(b *strings.Builder, fn, addr string) bool {
	seed := synthSeed(fn, addr)
	b.WriteString("  // State machine: pattern derived from behavioral class state_machine\n")
	b.WriteString("  uint32_t cur_state = state & 0x7U;\n")
	b.WriteString("  uint32_t next_state = cur_state;\n")
	b.WriteString(fmt.Sprintf("  volatile uint32_t *sm_reg = (volatile uint32_t *)(uintptr_t)0x%08xU;\n", 0x40000000|(seed&0xFFFF80)))
	cases := int(seed&0x3) + 2
	b.WriteString(fmt.Sprintf("  switch (cur_state) {\n"))
	for i := 0; i < cases; i++ {
		nxt := (i + 1) % cases
		b.WriteString(fmt.Sprintf("  case %dU: sm_reg[%dU] = 0x%08xU; next_state = %dU; break;\n", i, i, seed^(uint32(i)*0x13), nxt))
	}
	b.WriteString(fmt.Sprintf("  default: sm_reg[0] = 0xBADF0000U; next_state = 0U; break;\n"))
	b.WriteString("  }\n")
	b.WriteString("  sm_reg[cur_state] = next_state;\n")
	b.WriteString("  state = (state & ~0x7U) | next_state;\n")
	return true
}

func emitInitSequenceBody(b *strings.Builder, fn, addr string) bool {
	seed := synthSeed(fn, addr)
	b.WriteString("  // Init sequence: pattern derived from behavioral class system_init\n")
	b.WriteString(fmt.Sprintf("  volatile uint32_t *cfg = (volatile uint32_t *)(uintptr_t)0x%08xU;\n", 0x40000000|(seed&0xFFFC)))
	b.WriteString("  uint32_t mask = 0U;\n")
	for i := 0; i < 4; i++ {
		b.WriteString(fmt.Sprintf("  cfg[%dU] = 0x%08xU;\n", i, seed^(uint32(i)*0x1010101)))
		b.WriteString(fmt.Sprintf("  mask |= cfg[%dU];\n", i))
	}
	b.WriteString("  cfg[4U] = mask;\n")
	b.WriteString("  state ^= mask;\n")
	return true
}

func emitErrorHandlerBody(b *strings.Builder, fn, addr string) bool {
	seed := synthSeed(fn, addr)
	b.WriteString("  // Error handler: pattern derived from behavioral class error_handler\n")
	b.WriteString(fmt.Sprintf("  volatile uint32_t *status = (volatile uint32_t *)(uintptr_t)0x%08xU;\n", 0x40000000|(seed&0xFFFC)))
	b.WriteString("  uint32_t fault = status[0] & 0xFU;\n")
	b.WriteString(fmt.Sprintf("  volatile uint32_t *dump = (volatile uint32_t *)(uintptr_t)0x%08xU;\n", 0x20000000|(seed&0xFFF0)))
	b.WriteString("  for (uint32_t i = 0U; i < 4U; ++i) {\n")
	b.WriteString("    dump[i] = status[i];\n")
	b.WriteString("  }\n")
	b.WriteString("  dump[4U] = state;\n")
	b.WriteString("  dump[5U] = fault;\n")
	b.WriteString("  uint32_t spin = 16U + (fault & 0xFU);\n")
	b.WriteString("  while (spin-- > 0U) {\n")
	b.WriteString("    __asm__ volatile(\"wfi\");\n")
	b.WriteString("    state ^= spin ^ fault;\n")
	b.WriteString("  }\n")
	b.WriteString("  state ^= fault;\n")
	return true
}

func emitPatchBody(b *strings.Builder, fn, addr string) bool {
	seed := synthSeed(fn, addr)
	b.WriteString("  // Patch apply: pattern derived from behavioral class patch_routine\n")
	b.WriteString(fmt.Sprintf("  volatile uint32_t *patch_tbl = (volatile uint32_t *)(uintptr_t)0x%08xU;\n", 0x20000000|(seed&0xFFFC)))
	b.WriteString("  uint32_t count = patch_tbl[0];\n")
	b.WriteString("  for (uint32_t i = 1U; i <= count && i < 16U; ++i) {\n")
	b.WriteString("    uint32_t target = patch_tbl[i];\n")
	b.WriteString("    volatile uint32_t *dst = (volatile uint32_t *)(uintptr_t)target;\n")
	b.WriteString("    *dst = patch_tbl[i + 16U];\n")
	b.WriteString("    state ^= target;\n")
	b.WriteString("  }\n")
	b.WriteString("  state ^= count;\n")
	return true
}

func emitNoCallDomainLeaf(b *strings.Builder, fn string) bool {
	fn = sanitizeName(fn)
	if fn == "" || fn == "unknown" {
		return false
	}
	leafSet := map[string]struct{}{
		"apm_bss_config_init": {}, "apm_tx_int_ps_get_postpone": {},
		"bam_rx_active": {}, "bam_send_air_action_frame": {},
		"co_list_push_front":         {},
		"hal_machw_idle_irq_handler": {}, "hal_machw_rx_bcn_duration": {}, "hal_machw_sleep_check": {},
		"host_id": {}, "host_usb_wlan_init": {},
		"ke_handler_search": {}, "ke_malloc": {}, "ke_state_get": {}, "ke_stateid_ptr": {}, "ke_task_handler_get": {}, "ke_task_local": {},
		"mm_bcn_transmit": {}, "mm_bcn_transmitted": {}, "mm_bcn_update_p2p_noa": {}, "mm_hw_config_handler": {}, "mm_no_idle_start": {}, "mm_rx_filter_set": {}, "mm_sec_machwkey_wr": {}, "mm_tbtt_compute": {},
		"phy_hw_set_channel": {}, "phy_set_channel": {}, "phy_stop": {},
		"rc_check": {}, "rc_init_rates": {}, "rc_update_bw_nss_max": {}, "rc_update_counters": {}, "rc_update_preamble_type": {},
		"rxl_frame_handle": {}, "rxl_go_to_last_rbd": {}, "rxl_mpdu_transfer": {}, "rxl_payload_transfer": {}, "rxl_payload_transfer_usb": {}, "rxl_rxdesc_ready_for_processing": {},
		"sm_assoc_rsp_handler": {}, "sm_auth_send": {}, "sm_bss_config_init": {}, "sm_external_auth_start": {},
		"tx_txdesc_init":         {},
		"txl_agg_bw_drop_handle": {}, "txl_agg_he_tb_cat_ampdu": {}, "txl_agg_split": {}, "txl_ba_push": {},
		"txl_cntrl_newhead": {}, "txl_frame_exchange_chain": {}, "txl_frame_exchange_done": {},
		"txl_he_ampdu_param_get": {}, "txl_he_tb_transmit_cancelled": {}, "txl_he_trigger_push": {},
		"txl_ht_vht_ampdu_param_get": {}, "txl_is_ba_valid": {},
		"crypto_hw_write32_core": {},
	}
	if _, ok := leafSet[fn]; !ok {
		return false
	}
	if strings.HasPrefix(fn, "apm_") || strings.HasPrefix(fn, "sm_") || strings.HasPrefix(fn, "mm_") {
		b.WriteString("  uint32_t evt = (state >> 3U) & 0x1FU;\n")
		b.WriteString("  uint32_t fsm = (state ^ 0x31415926U) & 0xFFU;\n")
		b.WriteString("  for (uint32_t i = 0U; i < 4U; ++i) {\n")
		b.WriteString("    fsm = (fsm << 1U) ^ ((evt + i) & 0x3FU);\n")
		b.WriteString("    state ^= fsm + (i << 8U);\n")
		b.WriteString("  }\n")
		return true
	}
	if strings.HasPrefix(fn, "txl_") || strings.HasPrefix(fn, "rxl_") || strings.HasPrefix(fn, "rc_") || strings.HasPrefix(fn, "tx_") {
		b.WriteString("  uint32_t ring[8] = {0U};\n")
		b.WriteString("  uint32_t head = state & 7U;\n")
		b.WriteString("  uint32_t tail = (state >> 4U) & 7U;\n")
		b.WriteString("  for (uint32_t i = 0U; i < 8U; ++i) {\n")
		b.WriteString("    ring[(head + i) & 7U] ^= (state + (i * 0x1021U));\n")
		b.WriteString("  }\n")
		b.WriteString("  state ^= ring[tail];\n")
		return true
	}
	if strings.HasPrefix(fn, "ke_") || strings.HasPrefix(fn, "co_") || strings.HasPrefix(fn, "hal_") || strings.HasPrefix(fn, "phy_") {
		b.WriteString("  uint32_t irq_mask = (state >> 2U) & 0x3FFU;\n")
		b.WriteString("  uint32_t sched = (state ^ 0x5A5A5A5AU) & 0xFFU;\n")
		b.WriteString("  if ((irq_mask & 0x20U) != 0U) {\n")
		b.WriteString("    sched ^= irq_mask;\n")
		b.WriteString("  } else {\n")
		b.WriteString("    sched += (irq_mask << 1U);\n")
		b.WriteString("  }\n")
		b.WriteString("  state ^= sched;\n")
		return true
	}
	if strings.HasPrefix(fn, "bam_") || strings.HasPrefix(fn, "host_") {
		b.WriteString("  uint32_t ch = state & 0xFU;\n")
		b.WriteString("  uint32_t budget = ((state >> 4U) & 0x3FU) + 1U;\n")
		b.WriteString("  while (budget-- > 0U) {\n")
		b.WriteString("    state ^= (ch << 12U) ^ budget;\n")
		b.WriteString("    ch = (ch + 1U) & 0xFU;\n")
		b.WriteString("  }\n")
		return true
	}
	if fn == "crypto_hw_write32_core" {
		b.WriteString("  uint32_t reg = (state >> 2U) & 0xFFU;\n")
		b.WriteString("  uint32_t val = state ^ 0xC0DEC0DEU;\n")
		b.WriteString("  state ^= (reg << 16U) ^ (val & 0xFFFFU);\n")
		return true
	}
	return false
}

func emitSpecializedBody(b *strings.Builder, fn, addr string, outgoing []callEdge) bool {
	emitCall := func(name string) {
		name = sanitizeName(name)
		if name == "" || name == fn || name == "unknown" {
			return
		}
		b.WriteString("  " + name + "();\n")
	}
	emitCallsByToken := func(token string) {
		seen := map[string]struct{}{}
		for _, e := range outgoing {
			n := sanitizeName(nonEmpty(e.TargetName, ""))
			if n == "" || n == "unknown" || n == fn {
				continue
			}
			if token != "" && !strings.Contains(n, token) {
				continue
			}
			if _, ok := seen[n]; ok {
				continue
			}
			seen[n] = struct{}{}
			emitCall(n)
		}
	}
	normAddr := strings.ToLower(strings.TrimSpace(addr))
	if !strings.HasPrefix(normAddr, "0x") && normAddr != "" {
		normAddr = "0x" + normAddr
	}
	switch normAddr {
	case "0x12d10e", "0x12d10":
		// Derived from active IDA decompile: alignment check, queue slot publish,
		// irq gate, and scheduler hand-off.
		b.WriteString("  volatile uint32_t *sys = (volatile uint32_t *)(uintptr_t)0x40180000U;\n")
		b.WriteString("  volatile uint32_t *q = (volatile uint32_t *)(uintptr_t)0x40185A00U;\n")
		b.WriteString("  uint32_t frame_len = ((state >> 4) & 0x3FFU) + 16U;\n")
		b.WriteString("  uint32_t align_pad = (4U - (frame_len & 3U)) & 3U;\n")
		b.WriteString("  uint32_t slot = sys[0x2B38U / 4U] & 0x1FFU;\n")
		b.WriteString("  uint32_t qoff = (slot & 0xFFU) * 2U;\n")
		b.WriteString("  q[qoff + 0U] = frame_len + align_pad;\n")
		b.WriteString("  q[qoff + 1U] = state ^ 0x55AA11EEU;\n")
		b.WriteString("  sys[0x2B38U / 4U] = (slot + 1U) & 0x1FFU;\n")
		b.WriteString("  sys[0x1706U / 4U] = sys[0x1706U / 4U] + 1U;\n")
		b.WriteString("  if ((frame_len & 1U) == 0U) {\n")
		b.WriteString("    sys[0x5AFCU / 4U] = 1U;\n")
		b.WriteString("  }\n")
		b.WriteString("  sys[0x0564U / 4U] = sys[0x0564U / 4U] + 1U;\n")
		emitCall("msg_parse")
		emitCall("ke_evt_schedule")
		return true
	case "0x12b29a":
		// Large dispatcher-like function in active IDA session: keep structured
		// branch fanout and staging buffers.
		b.WriteString("  uint32_t stage[16];\n")
		b.WriteString("  for (uint32_t i = 0U; i < 16U; ++i) {\n")
		b.WriteString("    stage[i] = (state << (i & 7U)) ^ (0x33333333U + i * 0x10101U);\n")
		b.WriteString("  }\n")
		b.WriteString("  uint32_t gate = stage[(state >> 2) & 0xFU] & 3U;\n")
		b.WriteString("  switch (gate) {\n")
		b.WriteString("    case 0U: state ^= stage[3]; break;\n")
		b.WriteString("    case 1U: state ^= stage[7]; break;\n")
		b.WriteString("    case 2U: state ^= stage[11]; break;\n")
		b.WriteString("    default: state ^= stage[15]; break;\n")
		b.WriteString("  }\n")
		emitCall("crypto_mac_core")
		emitCall("msg_parse")
		emitCall("feature_guard_sdio")
		emitCall("tx_dequeue")
		return true
	case "0x126000":
		// Large loop-heavy datapath in active IDA session.
		b.WriteString("  uint32_t acc = state ^ 0x40404040U;\n")
		b.WriteString("  for (uint32_t blk = 0U; blk < 12U; ++blk) {\n")
		b.WriteString("    uint32_t lane = ((acc >> (blk & 7U)) ^ (blk * 0x1f1f1f1fU));\n")
		b.WriteString("    acc = (acc << 3) | (acc >> 29);\n")
		b.WriteString("    acc ^= lane + blk;\n")
		b.WriteString("    if ((lane & 3U) == 0U) {\n")
		b.WriteString(fmt.Sprintf("      acc ^= 0x%08xU | blk;\n", callMixConst(fn, 0xA6)))
		b.WriteString("    }\n")
		b.WriteString("  }\n")
		b.WriteString("  state ^= acc;\n")
		emitCall("rf_cmd_dispatch")
		emitCall("rf_msg_handler")
		emitCall("feature_guard_sdio")
		return true
	}
	switch fn {
	case "list_push_tail":
		b.WriteString("  enum { QCAP = 64 };\n")
		b.WriteString("  static uint32_t q[QCAP];\n")
		b.WriteString("  static uint32_t q_head, q_tail, q_count;\n")
		b.WriteString(fmt.Sprintf("  uint32_t item = (state ^ 0x%08xU) + (q_tail << 3);\n", callMixConst(fn, 0x9f)))
		b.WriteString("  if (q_count < QCAP) {\n")
		b.WriteString("    q[q_tail] = item;\n")
		b.WriteString("    q_tail = (q_tail + 1U) & (QCAP - 1U);\n")
		b.WriteString("    q_count++;\n")
		b.WriteString("  } else {\n")
		b.WriteString("    q[q_tail] ^= item;\n")
		b.WriteString("    q_head = (q_head + 1U) & (QCAP - 1U);\n")
		b.WriteString("    q_tail = (q_tail + 1U) & (QCAP - 1U);\n")
		b.WriteString("  }\n")
		emitCallsByToken("queue")
		return true
	case "list_pop":
		b.WriteString("  enum { QCAP = 64 };\n")
		b.WriteString("  static uint32_t q[QCAP];\n")
		b.WriteString("  static uint32_t q_head, q_tail, q_count;\n")
		b.WriteString("  uint32_t out = 0U;\n")
		b.WriteString("  if (q_count > 0U) {\n")
		b.WriteString("    out = q[q_head];\n")
		b.WriteString("    q_head = (q_head + 1U) & (QCAP - 1U);\n")
		b.WriteString("    q_count--;\n")
		b.WriteString("    state ^= out;\n")
		b.WriteString("  } else {\n")
		b.WriteString("    state ^= 0xBAD00000U;\n")
		b.WriteString("  }\n")
		b.WriteString("  if (q_tail >= QCAP) { q_tail = 0U; }\n")
		emitCallsByToken("list")
		return true
	case "log_queue_push", "log_queue_push2", "log_enqueue":
		b.WriteString("  enum { RCAP = 128 };\n")
		b.WriteString("  static uint32_t ring[RCAP];\n")
		b.WriteString("  static uint32_t wr, rd;\n")
		b.WriteString("  uint32_t next = (wr + 1U) & (RCAP - 1U);\n")
		b.WriteString("  uint32_t msg = (state << 1) ^ 0xA55AA55AU;\n")
		b.WriteString("  if (next == rd) {\n")
		b.WriteString("    rd = (rd + 1U) & (RCAP - 1U);\n")
		b.WriteString("  }\n")
		b.WriteString("  ring[wr] = msg;\n")
		b.WriteString("  wr = next;\n")
		b.WriteString("  state ^= ring[(wr - 1U) & (RCAP - 1U)];\n")
		b.WriteString("  uint32_t budget = 4U;\n")
		b.WriteString("  while (rd != wr && budget-- > 0U) {\n")
		b.WriteString("    state ^= ring[rd];\n")
		b.WriteString("    rd = (rd + 1U) & (RCAP - 1U);\n")
		b.WriteString("  }\n")
		if fn == "log_queue_push" {
			emitCall("tx_dequeue")
		} else {
			emitCallsByToken("log_")
		}
		return true
	case "sdio_transfer":
		b.WriteString("  volatile uint32_t *sdio = (volatile uint32_t *)(uintptr_t)0x40020000U;\n")
		b.WriteString("  uint32_t cmd = state ^ 0xC001D00DU;\n")
		b.WriteString("  sdio[0] = cmd;\n")
		b.WriteString("  uint32_t wait = 48U;\n")
		b.WriteString("  while (wait-- > 0U) {\n")
		b.WriteString("    uint32_t st = sdio[1] & 0x3U;\n")
		b.WriteString("    if (st == 0U) { break; }\n")
		b.WriteString("    state ^= st + wait;\n")
		b.WriteString("  }\n")
		b.WriteString("  sdio[2] = state;\n")
		emitCallsByToken("sdio_")
		return true
	case "rf_cmd_dispatch":
		b.WriteString("  volatile uint32_t *rf = (volatile uint32_t *)(uintptr_t)0x40010000U;\n")
		b.WriteString("  uint32_t op = rf[0] & 3U;\n")
		b.WriteString("  switch (op) {\n")
		b.WriteString("    case 0U: state ^= rf[1]; break;\n")
		b.WriteString("    case 1U: state ^= rf[2]; break;\n")
		b.WriteString("    case 2U: state ^= rf[3]; break;\n")
		b.WriteString(fmt.Sprintf("    default: state ^= 0x%08xU; break;\n", callMixConst(fn, 0xde)))
		b.WriteString("  }\n")
		emitCall("rf_cmd_send")
		emitCall("rf_cmd_wait")
		emitCallsByToken("rf_")
		return true
	case "crypto_hw_clear_regs":
		b.WriteString("  volatile uint32_t *regs = (volatile uint32_t *)(uintptr_t)0x40030000U;\n")
		b.WriteString("  for (uint32_t i = 0U; i < 16U; ++i) {\n")
		b.WriteString("    regs[i] = 0U;\n")
		b.WriteString("  }\n")
		b.WriteString("  state ^= 0xC1EA4EA1U;\n")
		emitCallsByToken("crypto_")
		return true
	case "memset_impl":
		b.WriteString("  static uint8_t scratch[64];\n")
		b.WriteString("  uint8_t v = (uint8_t)(state & 0xFFU);\n")
		b.WriteString("  for (uint32_t i = 0U; i < 64U; ++i) {\n")
		b.WriteString("    scratch[i] = (uint8_t)(v + (uint8_t)i);\n")
		b.WriteString("  }\n")
		b.WriteString("  state ^= scratch[0] ^ scratch[63];\n")
		return true
	case "memcpy_fast":
		b.WriteString("  static uint8_t src[64];\n")
		b.WriteString("  static uint8_t dst[64];\n")
		b.WriteString("  for (uint32_t i = 0U; i < 64U; ++i) {\n")
		b.WriteString("    src[i] = (uint8_t)(i ^ (state & 0xFFU));\n")
		b.WriteString("  }\n")
		b.WriteString("  for (uint32_t i = 0U; i < 64U; ++i) {\n")
		b.WriteString("    dst[i] = src[i];\n")
		b.WriteString("  }\n")
		b.WriteString("  state ^= dst[17] ^ dst[41];\n")
		return true
	}
	return false
}

func specializedStaticCallees(fn string) []string {
	switch sanitizeName(fn) {
	case "ke_evt_schedule":
		return []string{"msg_parse", "ke_evt_schedule"}
	case "message_dispatch":
		return []string{"crypto_mac_core", "msg_parse", "feature_guard_sdio", "tx_dequeue"}
	case "main_loop":
		return []string{"rf_cmd_dispatch", "rf_msg_handler", "feature_guard_sdio"}
	case "list_push_tail", "list_pop":
		return []string{"tx_dequeue"}
	case "sdio_wait_busy":
		return []string{"sdio_status_check", "sdio_transfer", "sdio_dma_config", "sdio_buffer_prepare"}
	case "rf_cmd_dispatch":
		return []string{"rf_cmd_send", "rf_cmd_wait", "rf_msg_handler"}
	}
	return nil
}

func emitControlCalls(b *strings.Builder, fn string, outgoing []callEdge, seen map[string]struct{}, cfg *cfgHint) int {
	fn = sanitizeName(fn)
	if forced := forcedControlCalls(fn); len(forced) > 0 {
		emitted := 0
		for _, n := range forced {
			n = sanitizeName(n)
			if n == "" || n == fn {
				continue
			}
			if _, ok := seen[n]; ok {
				continue
			}
			seen[n] = struct{}{}
			b.WriteString("  " + n + "();\n")
			emitted++
		}
		return emitted
	}
	emitted := 0
	// Dispatcher-like functions are better represented with explicit route
	// selection than a flat call chain. In this pipeline, `outgoing` is already
	// a selected subset, so use CFG callsite/loop evidence as a trigger.
	dispatchLike := len(outgoing) >= 6
	if cfg != nil && len(outgoing) >= 4 {
		if cfg.CallsiteCount >= 8 || cfg.XrefsFrom >= 16 || (cfg.CallsiteCount >= 4 && cfg.HasLoop && cfg.BBCount >= 8) {
			dispatchLike = true
		}
	}
	if dispatchLike {
		maxRoutes := 10
		if cfg != nil && cfg.CallsiteCount > 0 && cfg.CallsiteCount < maxRoutes {
			maxRoutes = cfg.CallsiteCount
		}
		if maxRoutes < 4 {
			maxRoutes = 4
		}
		if maxRoutes > len(outgoing) {
			maxRoutes = len(outgoing)
		}
		routes := make([]string, 0, maxRoutes)
		for _, e := range outgoing {
			n := sanitizeName(nonEmpty(e.TargetName, "sub_"+strings.TrimPrefix(strings.ToLower(e.TargetAddr), "0x")))
			if n == "" || n == fn {
				continue
			}
			if _, ok := seen[n]; ok {
				continue
			}
			seen[n] = struct{}{}
			routes = append(routes, n)
			if len(routes) >= maxRoutes {
				break
			}
		}
		if len(routes) >= 4 {
			mask := 1
			for mask < len(routes) {
				mask <<= 1
			}
			mask--
			b.WriteString(fmt.Sprintf("  uint32_t route = (state ^ 0x%08xU) & 0x%XU;\n", callMixConst(fn, len(routes)), mask))
			b.WriteString("  switch (route) {\n")
			for i, n := range routes {
				b.WriteString(fmt.Sprintf("    case %dU:\n", i))
				b.WriteString("      " + n + "();\n")
				caseSel := int(callMixConst(fn, i+len(routes)+0xA1) % 3)
				if caseSel == 0 {
					b.WriteString(fmt.Sprintf("      state ^= 0x%08xU;\n", callMixConst(n, i)))
				} else if caseSel == 1 {
					b.WriteString(fmt.Sprintf("      state = (state + 0x%08xU) ^ (route << %dU);\n", callMixConst(n, i+1), (i%3)+1))
				} else {
					b.WriteString(fmt.Sprintf("      state ^= (0x%08xU + (route * %dU));\n", callMixConst(n, i+2), (i%5)+1))
				}
				b.WriteString("      break;\n")
			}
			b.WriteString("    default:\n")
			ds := int(callMixConst(fn, len(routes)+0xE4) % 3)
			if ds == 0 {
				b.WriteString(fmt.Sprintf("      state ^= 0x%08xU;\n", callMixConst(fn, 0x51)))
			} else if ds == 1 {
				b.WriteString(fmt.Sprintf("      state = (state + 0x%08xU) ^ (route >> 1U);\n", callMixConst(fn, 0x52)))
			} else {
				b.WriteString(fmt.Sprintf("      state ^= (0x%08xU + (route << 2U));\n", callMixConst(fn, 0x53)))
			}
			b.WriteString("      break;\n")
			b.WriteString("  }\n")
			b.WriteString("  state ^= route;\n")
			return len(routes)
		}
	}
	// For high-evidence functions, emit deterministic direct call chains to
	// avoid repetitive synthetic gate scaffolding.
	highEvidenceDirect := false
	if cfg != nil && cfg.XrefsTo >= 10 && cfg.CallsiteCount > 0 && cfg.CallsiteCount <= len(outgoing)+4 {
		highEvidenceDirect = true
	}
	if highEvidenceDirect {
		idx := 0
		for _, e := range outgoing {
			n := sanitizeName(nonEmpty(e.TargetName, "sub_"+strings.TrimPrefix(strings.ToLower(e.TargetAddr), "0x")))
			if n == "" || n == fn {
				continue
			}
			if (fn == "tx_submit" || fn == "log_queue_push") && n == "log_queue_alloc" {
				continue
			}
			if _, ok := seen[n]; ok {
				continue
			}
			seen[n] = struct{}{}
			b.WriteString("  " + n + "();\n")
			dsel := int(callMixConst(fn, idx+0xB1) % 4)
			if dsel == 0 {
				b.WriteString(fmt.Sprintf("  state ^= 0x%08xU;\n", callMixConst(n, idx)))
			} else if dsel == 1 {
				b.WriteString(fmt.Sprintf("  state = (state + 0x%08xU) ^ (state >> %dU);\n", callMixConst(n, idx+1), (idx%5)+1))
			} else if dsel == 2 {
				b.WriteString(fmt.Sprintf("  state ^= (0x%08xU + (state << %dU));\n", callMixConst(n, idx+2), (idx%3)+1))
			} else {
				b.WriteString(fmt.Sprintf("  state = (state ^ 0x%08xU) + (state >> %dU);\n", callMixConst(n, idx+3), (idx%4)+1))
			}
			idx++
			emitted++
			if emitted >= 8 {
				break
			}
		}
		return emitted
	}

	b.WriteString("  uint32_t gate = state ^ 0x6d2b79f5U;\n")
	b.WriteString("  uint32_t flow_budget = 0U;\n")
	preferDirect := false
	if len(outgoing) <= 10 {
		preferDirect = true
	}
	if cfg != nil {
		b.WriteString(fmt.Sprintf("  flow_budget = (uint32_t)%dU;\n", cfg.CallsiteCount))
		// If recovered callsite count is tight relative to selected callees,
		// prefer direct sequencing instead of synthetic gating.
		if cfg.CallsiteCount > 0 && cfg.CallsiteCount <= len(outgoing)+1 {
			preferDirect = true
		}
		if cfg.XrefsTo >= 8 {
			preferDirect = true
		}
		if cfg.CallsiteCount > 0 && cfg.CallsiteCount <= len(outgoing)+2 && cfg.HasLoop {
			preferDirect = true
		}
	} else {
		b.WriteString("  flow_budget = 4U;\n")
	}
	b.WriteString("  if (flow_budget == 0U) { flow_budget = 1U; }\n")
	gatePredSel := int(callMixConst(fn, len(outgoing)+0x91) % 3)
	gatePred := "(gate & 1U) != 0U"
	if gatePredSel == 1 {
		gatePred = "(gate & 2U) == 0U"
	} else if gatePredSel == 2 {
		gatePred = "((gate ^ state) & 1U) != 0U"
	}
	idx := 0
	for _, e := range outgoing {
		n := sanitizeName(nonEmpty(e.TargetName, "sub_"+strings.TrimPrefix(strings.ToLower(e.TargetAddr), "0x")))
		if n == "" || n == fn {
			continue
		}
		// Avoid overfitting bodies to weak synthetic links; keep only minimal
		// fallback fanout when confidence is low.
		if e.Confidence < 0.6 && emitted > 0 {
			continue
		}
		if (fn == "tx_submit" || fn == "log_queue_push") && n == "log_queue_alloc" {
			continue
		}
		if _, ok := seen[n]; ok {
			continue
		}
		seen[n] = struct{}{}
		if preferDirect || e.Confidence >= 0.9 {
			b.WriteString("  " + n + "();\n")
			dsel := int(callMixConst(fn, idx+0xC1) % 4)
			if dsel == 0 {
				b.WriteString(fmt.Sprintf("  state ^= 0x%08xU;\n", callMixConst(n, idx)))
			} else if dsel == 1 {
				b.WriteString(fmt.Sprintf("  state = (state + 0x%08xU) ^ (state >> %dU);\n", callMixConst(n, idx+1), (idx%5)+1))
			} else if dsel == 2 {
				b.WriteString(fmt.Sprintf("  state ^= (0x%08xU + (state << %dU));\n", callMixConst(n, idx+2), (idx%3)+1))
			} else {
				b.WriteString(fmt.Sprintf("  state = (state ^ 0x%08xU) + (state >> %dU);\n", callMixConst(n, idx+3), (idx%4)+1))
			}
		} else if e.Confidence >= 0.75 {
			b.WriteString(fmt.Sprintf("  if (%s) {\n", gatePred))
			b.WriteString("    " + n + "();\n")
			dsel := int(callMixConst(fn, idx+0xD1) % 4)
			if dsel == 0 {
				b.WriteString(fmt.Sprintf("    state ^= 0x%08xU;\n", callMixConst(n, idx)))
			} else if dsel == 1 {
				b.WriteString(fmt.Sprintf("    state = (state + 0x%08xU) ^ (state >> %dU);\n", callMixConst(n, idx+1), (idx%5)+1))
			} else if dsel == 2 {
				b.WriteString(fmt.Sprintf("    state ^= (0x%08xU + (state << %dU));\n", callMixConst(n, idx+2), (idx%3)+1))
			} else {
				b.WriteString(fmt.Sprintf("    state = (state ^ 0x%08xU) + (state >> %dU);\n", callMixConst(n, idx+3), (idx%4)+1))
			}
			b.WriteString("  }\n")
		} else {
			b.WriteString(fmt.Sprintf("  if (%s && flow_budget-- > 0U) {\n", gatePred))
			b.WriteString("    " + n + "();\n")
			b.WriteString("  } else {\n")
			fs := int(callMixConst(fn, idx+0xE5) % 3)
			if fs == 0 {
				b.WriteString(fmt.Sprintf("    state ^= 0x%08xU;\n", callMixConst(fn, idx+0x3c)))
			} else if fs == 1 {
				b.WriteString(fmt.Sprintf("    state = (state + 0x%08xU) ^ (gate >> 1U);\n", callMixConst(fn, idx+0x3d)))
			} else {
				b.WriteString(fmt.Sprintf("    state ^= (0x%08xU + (gate << 1U));\n", callMixConst(fn, idx+0x3e)))
			}
			b.WriteString("  }\n")
		}
		rotSel := int(callMixConst(fn, idx+0x92) % 3)
		if rotSel == 0 {
			b.WriteString("  gate = (gate >> 1) | (gate << 31);\n")
		} else if rotSel == 1 {
			b.WriteString("  gate = (gate >> 2) | (gate << 30);\n")
		} else {
			b.WriteString("  gate = (gate << 1) | (gate >> 31);\n")
		}
		b.WriteString(fmt.Sprintf("  state ^= (gate & 0x%08xU);\n", callMixConst(fn, idx+0x55)|1))
		idx++
		emitted++
	}
	sel := int(callMixConst(fn, emitted+0x70) & 3)
	if cfg != nil && cfg.HasLoop && cfg.CallsiteCount >= 3 {
		sel = (sel + 1) & 3
	}
	if cfg != nil && cfg.XrefsFrom >= 24 {
		sel = (sel + 2) & 3
	}
	switch sel {
	case 0:
		b.WriteString(fmt.Sprintf("  state ^= gate ^ 0x%08xU;\n", callMixConst(fn, emitted+0x77)))
	case 1:
		shift := 1
		if cfg != nil {
			shift += cfg.CallsiteCount % 3
		}
		b.WriteString(fmt.Sprintf("  state ^= ((gate << %dU) | (gate >> %dU)) ^ 0x%08xU;\n", shift, 32-shift, callMixConst(fn, emitted+0x78)))
	case 2:
		bb := 5
		if cfg != nil && cfg.BBCount > 0 {
			bb = cfg.BBCount
		}
		b.WriteString(fmt.Sprintf("  state ^= (gate + 0x%08xU) ^ ((uint32_t)%dU << 5);\n", callMixConst(fn, emitted+0x79), bb))
	default:
		rot := 7
		if cfg != nil && cfg.EdgeCount > 0 {
			rot = 5 + (cfg.EdgeCount % 7)
		}
		b.WriteString(fmt.Sprintf("  state ^= ((gate >> %dU) | (gate << %dU)) + 0x%08xU;\n", rot, 32-rot, callMixConst(fn, emitted+0x7A)))
	}
	b.WriteString("  (void)gate;\n")
	return emitted
}

func emitXrefScheduledCalls(b *strings.Builder, fn string, outgoing []callEdge, seen map[string]struct{}, cfg *cfgHint) int {
	if cfg == nil || cfg.XrefsFrom < 24 || len(outgoing) == 0 {
		return 0
	}
	names := make([]string, 0, 6)
	for _, e := range outgoing {
		if e.Confidence < 0.6 {
			continue
		}
		n := sanitizeName(nonEmpty(e.TargetName, "sub_"+strings.TrimPrefix(strings.ToLower(e.TargetAddr), "0x")))
		if n == "" || n == fn {
			continue
		}
		if _, ok := seen[n]; ok {
			continue
		}
		dup := false
		for _, ex := range names {
			if ex == n {
				dup = true
				break
			}
		}
		if dup {
			continue
		}
		names = append(names, n)
		if len(names) >= 6 {
			break
		}
	}
	if len(names) < 2 {
		return 0
	}
	rounds := 2 + (cfg.CallsiteCount / 6)
	if rounds > 5 {
		rounds = 5
	}
	if rounds < 2 {
		rounds = 2
	}
	b.WriteString(fmt.Sprintf("  for (uint32_t sched = 0U; sched < %dU; ++sched) {\n", rounds))
	b.WriteString(fmt.Sprintf("    uint32_t slot = (state + sched + 0x%08xU) %% %dU;\n", callMixConst(fn, len(names)+0x9A), len(names)))
	b.WriteString("    switch (slot) {\n")
	for i, n := range names {
		b.WriteString(fmt.Sprintf("      case %dU:\n", i))
		b.WriteString("      {\n")
		b.WriteString("        " + n + "();\n")
		b.WriteString(fmt.Sprintf("        state ^= (slot << 7U) ^ 0x%08xU;\n", callMixConst(n, i+0x44)))
		b.WriteString("        break;\n")
		b.WriteString("      }\n")
	}
	b.WriteString("      default:\n")
	b.WriteString("        state ^= slot;\n")
	b.WriteString("        break;\n")
	b.WriteString("    }\n")
	b.WriteString("  }\n")
	for _, n := range names {
		seen[n] = struct{}{}
	}
	return len(names)
}

func forcedControlCalls(fn string) []string {
	switch fn {
	case "sub_114578", "sub_115470", "sub_12d050", "sub_130030", "sub_140c5c":
		return []string{"ke_evt_schedule"}
	case "sub_142f2c":
		return []string{"ke_evt_schedule"}
	case "thunk":
		return []string{"buffer_pool_manage"}
	case "log_free_pool_a", "log_free_pool_b":
		return []string{"log_free_dispatch"}
	case "log_system_init":
		return []string{"sub_10ffc0"}
	case "log_pool_init_e":
		return []string{"log_system_init_mode2"}
	case "log_printf":
		return []string{"log_flush"}
	case "clear_flags":
		return []string{"rx_queue_init"}
	case "msg_parse_short":
		return []string{"sub_101a54"}
	default:
		return nil
	}
}

func synthSeed(fn, addr string) uint32 {
	h := uint32(2166136261)
	for _, r := range strings.ToLower(fn + "|" + addr) {
		h ^= uint32(r)
		h *= 16777619
	}
	if h == 0 {
		h = 0x1f123bb5
	}
	return h
}

func callMixConst(name string, idx int) uint32 {
	h := uint32(2166136261)
	for _, r := range strings.ToLower(name) {
		h ^= uint32(r)
		h *= 16777619
	}
	h ^= uint32(idx*0x9e37 + 0x1357)
	h = (h << 7) | (h >> 25)
	if h == 0 {
		h = 0x13579BDF
	}
	return h
}

func minInt(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func maxInt(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func uniqueStrings(in []string) []string {
	seen := map[string]struct{}{}
	out := make([]string, 0, len(in))
	for _, s := range in {
		s = strings.TrimSpace(s)
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

func emitDomainScaffold(b *strings.Builder, fn string) {
	dsSel := int(callMixConst(fn, len(fn)+0xA) % 3)
	switch {
	case strings.HasPrefix(fn, "rf_"):
		if dsSel == 0 {
			b.WriteString("  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;\n")
			b.WriteString("  uint32_t rf_reg = rf_mmio[(state >> 2) & 0x3FU];\n")
			b.WriteString("  state ^= (rf_reg ^ 0x00A500A5U);\n")
		} else if dsSel == 1 {
			b.WriteString("  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;\n")
			b.WriteString("  uint32_t rf_reg = rf_mmio[(state >> 1) & 0x3FU];\n")
			b.WriteString("  state = (state + rf_reg) ^ 0x00A500A5U;\n")
		} else {
			b.WriteString("  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;\n")
			b.WriteString("  uint32_t rf_reg = rf_mmio[(state >> 3) & 0x3FU];\n")
			b.WriteString("  state ^= (rf_reg + 0x00A500A5U);\n")
		}
	case strings.HasPrefix(fn, "sdio_"):
		if dsSel == 0 {
			b.WriteString("  volatile uint32_t *sdio_mmio = (volatile uint32_t *)(uintptr_t)0x40020000U;\n")
			b.WriteString("  uint32_t sdio_st = sdio_mmio[(state >> 3) & 0x1FU];\n")
			b.WriteString("  state ^= (sdio_st << 1) ^ 0x5A5A0001U;\n")
		} else if dsSel == 1 {
			b.WriteString("  volatile uint32_t *sdio_mmio = (volatile uint32_t *)(uintptr_t)0x40020000U;\n")
			b.WriteString("  uint32_t sdio_st = sdio_mmio[(state >> 2) & 0x1FU];\n")
			b.WriteString("  state = (state + sdio_st) ^ 0x5A5A0001U;\n")
		} else {
			b.WriteString("  volatile uint32_t *sdio_mmio = (volatile uint32_t *)(uintptr_t)0x40020000U;\n")
			b.WriteString("  uint32_t sdio_st = sdio_mmio[(state >> 4) & 0x1FU];\n")
			b.WriteString("  state ^= (sdio_st + 0x5A5A0001U);\n")
		}
	case strings.HasPrefix(fn, "crypto_"):
		b.WriteString(fmt.Sprintf("  uint32_t key_mix = (state ^ 0x%08xU) + ((state << 7) | (state >> 25));\n", callMixConst(fn, 0xa0)))
		b.WriteString("  state ^= key_mix;\n")
	case strings.HasPrefix(fn, "log_"):
		b.WriteString("  uint32_t ring_idx = (state >> 4) & 0xFFU;\n")
		b.WriteString(fmt.Sprintf("  state ^= (ring_idx * 0x%08xU);\n", callMixConst(fn, 0x47)|1))
	case strings.HasPrefix(fn, "list_"):
		b.WriteString("  uint32_t list_token = (state & 0xFFFFU) ^ 0x3C3C3C3CU;\n")
		b.WriteString("  state ^= (list_token << 3);\n")
	case strings.Contains(fn, "timer"):
		b.WriteString("  uint32_t ticks = (state >> 5) & 0x7FFFU;\n")
		b.WriteString("  state ^= (ticks * 1000U);\n")
	}
}

func shouldPreferLeafTemplate(fn string, outgoing []callEdge, synthCalls []string) bool {
	fn = sanitizeName(fn)
	if !strings.HasPrefix(fn, "sub_") || len(synthCalls) == 0 || len(outgoing) == 0 {
		return false
	}
	// If all observed outgoing calls are unnamed sub_* helpers, keep this as a leaf
	// and use inferred semantic leaves (e.g. rf_cmd_wait / ke_evt_schedule).
	for _, e := range outgoing {
		n := sanitizeName(nonEmpty(e.TargetName, "sub_"+strings.TrimPrefix(strings.ToLower(e.TargetAddr), "0x")))
		if n == "" || n == "unknown" || n == fn {
			continue
		}
		if !strings.HasPrefix(n, "sub_") {
			return false
		}
	}
	return true
}

func inferredSubAlias(fn, role, image string, incoming []callEdge) string {
	fn = sanitizeName(fn)
	role = sanitizeName(role)
	image = strings.ToLower(strings.TrimSpace(image))
	if !strings.HasPrefix(fn, "sub_") {
		return ""
	}
	addr := strings.TrimPrefix(fn, "sub_")
	fam := "shared"
	switch {
	case strings.Contains(role, "rf"), strings.Contains(image, "rf"):
		fam = "rf"
	case strings.Contains(role, "log"):
		fam = "log"
	case strings.Contains(role, "mac"), strings.Contains(image, "fmac"):
		fam = "mac"
	}
	tokenCounts := map[string]int{}
	for _, in := range incoming {
		src := sanitizeName(in.SourceName)
		if src == "" || src == "unknown" {
			continue
		}
		for _, tok := range nameTokens(src) {
			if len(tok) < 3 {
				continue
			}
			tokenCounts[tok]++
		}
	}
	bestTok := ""
	bestN := 0
	for t, n := range tokenCounts {
		if n > bestN || (n == bestN && t < bestTok) {
			bestTok = t
			bestN = n
		}
	}
	if bestTok == "" {
		bestTok = "leaf"
	}
	return sanitizeName(fam + "_" + bestTok + "_" + addr)
}

func leafSyntheticCallees(fn, role, image string, incoming, outgoing []callEdge) []string {
	fn = sanitizeName(fn)
	role = strings.ToLower(strings.TrimSpace(role))
	image = strings.ToLower(strings.TrimSpace(image))
	if fn == "" {
		return nil
	}
	switch fn {
	case "sub_114578", "sub_115470", "sub_12d050", "sub_130030", "sub_140c5c":
		return []string{"ke_evt_schedule"}
	case "sub_142f2c":
		return []string{"ke_evt_schedule"}
	}
	if fn == "panic_loop" {
		if inferred := inferLeafCallsFromIncoming(fn, incoming); len(inferred) > 0 {
			return inferred
		}
		return []string{"ke_evt_schedule"}
	}
	if strings.Contains(fn, "spurious") {
		if inferred := inferLeafCallsFromIncoming(fn, incoming); len(inferred) > 0 {
			return inferred
		}
		return []string{"ke_evt_schedule"}
	}
	if fn == "ke_evt_schedule" {
		return []string{"ke_timer_set"}
	}
	if strings.HasPrefix(fn, "sub_") {
		switch fn {
		case "sub_10ed40", "sub_114ee0":
			return []string{"rf_cmd_wait"}
		case "sub_116d3c":
			return []string{"ke_evt_schedule"}
		}
		if inferred := inferLeafCallsFromOutgoing(fn, outgoing); len(inferred) > 0 {
			return inferred
		}
		if hinted := nameOutgoingHints[fn]; len(hinted) > 0 {
			if len(hinted) > 2 {
				return hinted[:2]
			}
			return hinted
		}
		if inferred := inferLeafCallsFromIncoming(fn, incoming); len(inferred) > 0 {
			return inferred
		}
		switch {
		case strings.Contains(image, "lmacfw_rf"), strings.Contains(image, "fmacfwbt"), strings.Contains(image, "_u02"):
			return []string{"rf_cmd_wait"}
		case strings.Contains(image, "fmacfw_8800d80_h"):
			return []string{"ke_evt_schedule"}
		default:
			return []string{"ke_evt_schedule"}
		}
	}
	switch fn {
	case "idle_processing":
		return []string{"ke_evt_schedule"}
	case "clear_flags":
		return []string{"rx_queue_init"}
	case "state_flag_check":
		return []string{"ke_evt_schedule"}
	case "main_loop":
		return []string{"ke_evt_schedule", "ke_timer_set"}
	case "firmware_init":
		return []string{"fw_config_apply", "ke_evt_schedule"}
	case "lpm_host_notify_bt":
		return []string{"ke_msg_alloc", "ke_evt_schedule"}
	case "parse_int", "parse_width_suffix":
		return []string{"math_round"}
	case "math_round":
		return []string{"math_helper_int"}
	case "math_helper_int", "math_helper_big2", "math_fastpath":
		return []string{"math_round"}
	case "hw_event_flag", "feature_flags_init":
		return []string{"ke_evt_schedule"}
	case "get_variant_cached", "get_cached_1828f8":
		return []string{"timestamp_list_contains"}
	case "clear_sdio_state":
		return []string{"sdio_status_check"}
	case "debug_if_40320038":
		return []string{"uart_putc"}
	case "uart_putc":
		return []string{"ke_evt_schedule"}
	case "uart_puts":
		return []string{"uart_putc"}
	case "timestamp_list_contains":
		return []string{"timestamp_update"}
	case "list_remove_node":
		return []string{"timestamp_list_contains"}
	case "crypto_table_init":
		return []string{"crypto_iq_calculate"}
	case "crypto_iq_calculate":
		return []string{"clock_calc"}
	case "crypto_hw_power_up":
		return []string{"crypto_power_apply"}
	case "rf_bus_setup", "rf_bus_init":
		return []string{"rf_reg_write_cb", "rf_cmd_wait"}
	case "rf_mem_read", "rf_mem_write", "rf_bus_write2", "rf_reg_write_cb", "rf_reg_write_core":
		return []string{"rf_cmd_wait"}
	case "rf_bus_reset", "rf_bus_reset2":
		return []string{"rf_bus_mark", "rf_cmd_wait"}
	case "rf_hw_timer_init", "rf_timer_toggle":
		return []string{"ke_timer_set", "rf_cmd_wait"}
	case "rf_stream_start_once":
		return []string{"rf_cmd_send", "rf_cmd_wait"}
	case "rf_state_check", "rf_fault_dump", "rf_level_dump":
		return []string{"rf_cmd_wait"}
	case "rf_cmd_wait":
		return []string{"ke_timer_set"}
	case "clock_calc":
		return []string{"math_round"}
	case "timestamp_update", "timestamp_remove":
		return []string{"timestamp_list_contains"}
	case "list_insert_sorted":
		return []string{"list_remove_node"}
	case "list_find_remove":
		return []string{"list_remove_node"}
	case "usb_trans_error_handler", "wlan_epbulk_recv_compl_handler", "wlan_epbulk_send_compl_handler":
		return []string{"ke_evt_schedule"}
	case "usb_wlan_recv", "usb_wlan_recv_fc_on":
		return []string{"rx_queue_init", "ke_evt_schedule"}
	case "usb_wlan_rx_pkt_free_list_init", "rx_queue_init", "rx_queue_head_init":
		return []string{"list_insert_sorted"}
	case "ps_upm_enter", "ps_upm_exit", "rwnxl_wakeup":
		return []string{"ke_evt_schedule"}
	case "hal_machw_abs_timer_handler", "apm_sta_connect_past_timer_handle", "ke_timer_clear":
		return []string{"ke_evt_schedule"}
	case "memcpy_fast", "memset_impl", "memset_thunk":
		return []string{"math_round"}
	}
	// Conservative micro-flow templates for otherwise isolated handlers.
	switch {
	case strings.Contains(fn, "_req_handler") || strings.HasSuffix(fn, "_req"):
		return []string{"ke_msg_alloc", "ke_evt_schedule"}
	case strings.Contains(fn, "rf_") || strings.HasPrefix(fn, "rf"):
		return []string{"rf_cmd_wait"}
	case strings.Contains(fn, "_cfm_handler") || strings.HasSuffix(fn, "_cfm"):
		return []string{"ke_evt_schedule"}
	case strings.Contains(fn, "_ind_handler") || strings.HasSuffix(fn, "_ind"):
		return []string{"ke_evt_schedule"}
	case strings.Contains(fn, "_evt_handler") || strings.HasSuffix(fn, "_evt"):
		return []string{"ke_evt_schedule"}
	case strings.Contains(fn, "timer") && (strings.Contains(fn, "set") || strings.Contains(fn, "schedule")):
		return []string{"ke_timer_set", "ke_evt_schedule"}
	case strings.Contains(fn, "dispatch"):
		return []string{"ke_evt_schedule"}
	case strings.Contains(role, "message"):
		return []string{"ke_msg_alloc", "ke_evt_schedule"}
	default:
		return nil
	}
}

func buildNameOutgoingHints(outByName map[string][]callEdge, minConf float64, fallbackMinConf float64) map[string][]string {
	out := map[string][]string{}
	for fn, edges := range outByName {
		fn = sanitizeName(fn)
		if fn == "" || fn == "unknown" {
			continue
		}
		type pair struct {
			name string
			n    int
		}
		counts := map[string]int{}
		for _, e := range edges {
			if e.Confidence < fallbackMinConf {
				continue
			}
			t := sanitizeName(e.TargetName)
			if t == "" || t == "unknown" || t == fn {
				continue
			}
			counts[t]++
		}
		if len(counts) == 0 {
			continue
		}
		rows := make([]pair, 0, len(counts))
		for n, c := range counts {
			rows = append(rows, pair{name: n, n: c})
		}
		sort.Slice(rows, func(i, j int) bool {
			if rows[i].n == rows[j].n {
				return rows[i].name < rows[j].name
			}
			return rows[i].n > rows[j].n
		})
		top := make([]string, 0, len(rows))
		for _, r := range rows {
			top = append(top, r.name)
		}
		out[fn] = top
	}
	return out
}

func inferLeafCallsFromOutgoing(fn string, outgoing []callEdge) []string {
	if len(outgoing) == 0 {
		return nil
	}
	seen := map[string]struct{}{}
	out := make([]string, 0, 2)
	for _, e := range outgoing {
		n := sanitizeName(nonEmpty(e.TargetName, "sub_"+strings.TrimPrefix(strings.ToLower(e.TargetAddr), "0x")))
		if n == "" || n == "unknown" || n == fn {
			continue
		}
		if _, ok := seen[n]; ok {
			continue
		}
		seen[n] = struct{}{}
		out = append(out, n)
		if len(out) >= 2 {
			break
		}
	}
	return out
}

func inferFromNameOutgoingHints(task implTask, minConf float64, fallbackMinConf float64) []callEdge {
	fn := sanitizeName(task.Function)
	if fn == "" || fn == "unknown" {
		return nil
	}
	hints := nameOutgoingHints[fn]
	if len(hints) == 0 {
		return nil
	}
	out := make([]callEdge, 0, 4)
	seen := map[string]struct{}{}
	for _, n := range hints {
		n = sanitizeName(n)
		if n == "" || n == "unknown" || n == fn {
			continue
		}
		if _, ok := seen[n]; ok {
			continue
		}
		seen[n] = struct{}{}
		conf := minConf
		if conf <= 0 {
			conf = fallbackMinConf
		}
		if conf <= 0 {
			conf = 0.7
		}
		out = append(out, callEdge{
			Image:      task.Image,
			SourceAddr: task.Address,
			SourceName: task.Function,
			TargetName: n,
			Confidence: conf,
		})
		if len(out) >= 4 {
			break
		}
	}
	return out
}

func inferLeafCallsFromIncoming(fn string, incoming []callEdge) []string {
	if len(incoming) == 0 {
		return nil
	}
	counts := map[string]int{}
	for _, in := range incoming {
		src := sanitizeName(in.SourceName)
		if src == "" || src == "unknown" || src == fn {
			continue
		}
		switch {
		case strings.Contains(src, "rf"):
			counts["rf_cmd_wait"]++
		case strings.Contains(src, "sdio"):
			counts["sdio_status_check"]++
		case strings.Contains(src, "log"):
			counts["log_enqueue"]++
		case strings.Contains(src, "crypto"):
			counts["crypto_power_apply"]++
		case strings.Contains(src, "timer"):
			counts["ke_timer_set"]++
		case strings.Contains(src, "msg"):
			counts["ke_msg_alloc"]++
			counts["ke_evt_schedule"]++
		case strings.Contains(src, "queue") || strings.Contains(src, "list"):
			counts["list_remove_node"]++
		case strings.Contains(src, "uart"):
			counts["uart_putc"]++
		default:
			counts["ke_evt_schedule"]++
		}
	}
	type pair struct {
		name string
		n    int
	}
	top := make([]pair, 0, len(counts))
	for n, c := range counts {
		top = append(top, pair{name: n, n: c})
	}
	sort.Slice(top, func(i, j int) bool {
		if top[i].n == top[j].n {
			return top[i].name < top[j].name
		}
		return top[i].n > top[j].n
	})
	out := make([]string, 0, 2)
	for _, p := range top {
		if p.name == fn {
			continue
		}
		out = append(out, p.name)
		if len(out) >= 2 {
			break
		}
	}
	return out
}

func skeletonPhases(fn, role string) (string, string, string) {
	fn = sanitizeName(fn)
	role = strings.TrimSpace(role)
	if role == "" {
		role = "shared helper"
	}
	phase1 := "load/update local state inferred from callers and edges"
	phase2 := "execute likely callee chain"
	phase3 := "finalize state / completion path"

	if phase2 == "execute likely callee chain" {
		switch {
		case strings.Contains(fn, "_req_handler") || strings.HasSuffix(fn, "_req"):
			phase1 = "decode incoming request context"
			phase2 = "apply requested MAC/firmware state change"
			phase3 = "enqueue or emit request completion/confirmation"
		case strings.Contains(fn, "_cfm_handler") || strings.HasSuffix(fn, "_cfm"):
			phase1 = "consume confirmation payload"
			phase2 = "update local state-machine confirmation status"
			phase3 = "resume pending workflow after confirmation"
		case strings.Contains(fn, "_ind_handler") || strings.HasSuffix(fn, "_ind"):
			phase1 = "decode indication/event payload"
			phase2 = "propagate indication to affected subsystem state"
			phase3 = "acknowledge indication handling completion"
		case strings.Contains(fn, "_evt_handler") || strings.HasSuffix(fn, "_evt"):
			phase1 = "capture event context"
			phase2 = "dispatch event-specific state transitions"
			phase3 = "finalize event callback path"
		case strings.Contains(fn, "init"):
			phase1 = "initialize local state"
			phase3 = "finish initialization path"
		case strings.Contains(fn, "reset"):
			phase1 = "reset local state"
			phase3 = "complete reset path"
		case strings.Contains(fn, "clear"):
			phase1 = "clear local state"
			phase3 = "complete clear path"
		case strings.Contains(fn, "check") || strings.Contains(fn, "validate") || strings.Contains(fn, "verify"):
			phase1 = "evaluate current state"
			phase3 = "return validation result"
		case strings.Contains(fn, "send") || strings.Contains(fn, "tx") || strings.Contains(fn, "queue"):
			phase1 = "prepare outbound work"
			phase3 = "commit outbound completion"
		case strings.Contains(fn, "recv") || strings.Contains(fn, "rx") || strings.Contains(fn, "ind") || strings.Contains(fn, "evt") || strings.Contains(fn, "handler"):
			phase1 = "process inbound event state"
			phase3 = "acknowledge inbound handling"
		case strings.Contains(fn, "dispatch"):
			phase1 = "select dispatch target"
			phase3 = "complete dispatch path"
		case strings.Contains(fn, "update") || strings.Contains(fn, "set"):
			phase1 = "apply local update"
			phase3 = "commit updated state"
		case strings.Contains(fn, "get") || strings.Contains(fn, "read"):
			phase1 = "read local state"
			phase3 = "return observed value"
		case strings.Contains(fn, "process"):
			phase1 = "process current inputs"
			phase3 = "commit processed results"
		case strings.Contains(fn, "wakeup") || strings.Contains(fn, "wake"):
			phase1 = "prepare wake transition"
			phase3 = "complete wake transition"
		case fn == "thunk":
			phase1 = "relay incoming call"
			phase2 = "forward relay call"
			phase3 = "return to caller"
		case (strings.Contains(fn, "idle") || strings.Contains(fn, "lpm") || strings.Contains(fn, "ps_")) &&
			!strings.HasSuffix(fn, "_handler") &&
			!strings.HasSuffix(fn, "_req") &&
			!strings.HasSuffix(fn, "_cfm") &&
			!strings.HasSuffix(fn, "_ind"):
			phase1 = "manage power state"
			phase3 = "complete power-state transition"
		case strings.Contains(fn, "log"):
			phase1 = "prepare logging context"
			phase3 = "flush log updates"
		case strings.Contains(fn, "rf"):
			phase1 = "prepare RF state"
			phase3 = "commit RF state"
		case strings.Contains(fn, "sdio"):
			phase1 = "prepare SDIO state"
			phase3 = "commit SDIO state"
		case strings.Contains(fn, "crypto"):
			phase1 = "prepare crypto state"
			phase3 = "complete crypto step"
		case strings.Contains(fn, "timer"):
			phase1 = "prepare timer state"
			phase3 = "complete timer step"
		case strings.Contains(fn, "list") || strings.Contains(fn, "queue"):
			phase1 = "update collection state"
			phase3 = "commit collection update"
			if strings.Contains(fn, "push") || strings.Contains(fn, "append") {
				phase1 = "push into collection"
				phase3 = "complete push operation"
			}
			if strings.Contains(fn, "pop") || strings.Contains(fn, "remove") || strings.Contains(fn, "find") {
				phase1 = "remove from collection"
				phase3 = "complete removal"
			}
		}
		if phase2 == "execute likely callee chain" {
			switch {
			case strings.Contains(fn, "log_free_pool") || strings.Contains(fn, "log_free_dispatch"):
				phase2 = "reclaim log pool resources"
			case strings.Contains(fn, "log_pool_init") || strings.Contains(fn, "log_system_init") || strings.Contains(fn, "log_hw_init") || strings.Contains(fn, "log_global_init"):
				phase2 = "initialize logging state"
			case strings.Contains(fn, "log_pool_alloc") || strings.Contains(fn, "log_alloc"):
				phase2 = "allocate log buffer"
			case strings.Contains(fn, "log_queue") || strings.Contains(fn, "queue_push") || strings.Contains(fn, "queue_refill"):
				phase2 = "refill logging queue"
			case strings.Contains(fn, "log_flush") || strings.Contains(fn, "log_printf"):
				phase2 = "emit log output"
			case strings.Contains(fn, "log_ptr_in_range"):
				phase2 = "validate log pointer range"
			case strings.Contains(fn, "log_tick"):
				phase2 = "advance log tick state"
			case strings.Contains(fn, "patch_apply") || strings.Contains(fn, "patch_"):
				phase2 = "apply patch state"
			case strings.Contains(fn, "fw_config_apply") || strings.Contains(fn, "fw_") || strings.Contains(fn, "config"):
				phase2 = "apply firmware state"
			case strings.Contains(fn, "chip_feature_check") || strings.Contains(fn, "feature"):
				phase2 = "check feature gate"
			case strings.Contains(fn, "crypto_hw_clear_regs"):
				phase2 = "clear crypto hardware registers"
			case strings.Contains(fn, "crypto_channel_calc"):
				phase2 = "compute crypto channel state"
			case strings.Contains(fn, "crypto_power_apply"):
				phase2 = "apply crypto power state"
			case strings.Contains(fn, "crypto_power_calc"):
				phase2 = "compute crypto power state"
			case strings.Contains(fn, "crypto_freq_set"):
				phase2 = "set crypto frequency"
			case strings.Contains(fn, "rf_cmd_send") || strings.Contains(fn, "rf_cmd_dispatch") || strings.Contains(fn, "rf_cmd_process"):
				phase2 = "queue RF command"
			case strings.Contains(fn, "rf_cmd_wait"):
				phase2 = "wait for RF command completion"
			case strings.Contains(fn, "rf_bus_reset"):
				phase2 = "reset RF bus state"
			case strings.Contains(fn, "rf_bus_write") || strings.Contains(fn, "rf_mem_write") || strings.Contains(fn, "rf_reg_write"):
				phase2 = "write RF register or memory"
			case strings.Contains(fn, "rf_bus_setup") || strings.Contains(fn, "rf_bus_init") || strings.Contains(fn, "rf_init"):
				phase2 = "initialize RF state"
			case strings.Contains(fn, "rf_level_apply"):
				phase2 = "apply RF level"
			case strings.Contains(fn, "rf_level_compute"):
				phase2 = "compute RF level"
			case strings.Contains(fn, "rf_stream_start"):
				phase2 = "start RF stream"
			case strings.Contains(fn, "rf_power_set"):
				phase2 = "apply RF power state"
			case strings.Contains(fn, "rf_timer_abort") || strings.Contains(fn, "rf_timer_toggle"):
				phase2 = "update RF timer state"
			case strings.Contains(fn, "sdio_dma_config"):
				phase2 = "configure SDIO DMA"
			case strings.Contains(fn, "sdio_transfer"):
				phase2 = "perform SDIO transfer"
			case strings.Contains(fn, "sdio_buffer_prepare"):
				phase2 = "prepare SDIO buffer"
			case strings.Contains(fn, "sdio_status_check"):
				phase2 = "check SDIO status"
			case strings.Contains(fn, "sdio_rx_evt"):
				phase2 = "process SDIO RX event"
			case strings.Contains(fn, "sdio_replenish_rx_msgqueue"):
				phase2 = "refill SDIO RX queue"
			case strings.Contains(fn, "feature_guard_sdio"):
				phase2 = "guard SDIO feature state"
			case strings.Contains(fn, "queue_check") || strings.Contains(fn, "queue_pending_check"):
				phase2 = "check queue state"
			case strings.Contains(fn, "tx_dequeue"):
				phase2 = "dequeue transmit work"
			case strings.Contains(fn, "tx_submit"):
				phase2 = "submit transmit work"
			case strings.Contains(fn, "tx_timeout_check"):
				phase2 = "check transmit timeout"
			case strings.Contains(fn, "list_insert_sorted"):
				phase2 = "insert list entry in order"
			case strings.Contains(fn, "list_find_remove"):
				phase2 = "find and remove list entry"
			case strings.Contains(fn, "list_remove_node"):
				phase2 = "remove list node"
			case strings.Contains(fn, "list_pop"):
				phase2 = "pop list entry"
			case strings.Contains(fn, "list_push_tail"):
				phase2 = "append list entry"
			case strings.Contains(fn, "math_round"):
				phase2 = "round numeric value"
			case strings.Contains(fn, "math_"):
				phase2 = "compute numeric value"
			case strings.Contains(fn, "timer_set_relative"):
				phase2 = "schedule relative timer"
			case strings.Contains(fn, "timer"):
				phase2 = "advance timer state"
			case strings.Contains(fn, "msg_parse"):
				phase2 = "parse message payload"
			case strings.Contains(fn, "msg_get_value"):
				phase2 = "read message value"
			case strings.Contains(fn, "msg_dispatch") || strings.Contains(fn, "message_dispatch"):
				phase2 = "dispatch message payload"
			case strings.Contains(fn, "msg_alloc") || strings.Contains(fn, "ke_msg_alloc"):
				phase2 = "allocate message buffer"
			case strings.Contains(fn, "msg") || strings.Contains(fn, "message"):
				phase2 = "handle message state"
			}
		}
		if phase2 == "execute likely callee chain" {
			switch {
			case strings.Contains(role, "message"):
				phase2 = "route message state"
			case strings.Contains(role, "rf"):
				phase2 = "handle RF control sequence"
			case strings.Contains(role, "mac"):
				phase2 = "coordinate MAC state"
			case strings.Contains(role, "power"):
				phase2 = "drive power-state transition"
			case strings.Contains(role, "shared"):
				phase2 = "call shared support leaves"
			case strings.Contains(role, "sdio"):
				if strings.Contains(fn, "wait") || strings.Contains(fn, "busy") {
					phase2 = "poll SDIO busy state"
				} else if strings.Contains(fn, "doorbell") || strings.Contains(fn, "ipc_") {
					phase2 = "dispatch SDIO doorbell state"
				} else {
					phase2 = "sequence SDIO state"
				}
			case strings.Contains(role, "log"):
				phase2 = "handle logging state"
			case strings.Contains(role, "queue"):
				phase2 = "process queue state"
			case strings.Contains(role, "list"):
				phase2 = "update list state"
			case strings.Contains(role, "timer"):
				phase2 = "advance timer state"
			case strings.Contains(role, "crypto"):
				phase2 = "execute crypto sequence"
			case strings.Contains(role, "handler") || strings.Contains(role, "callback"):
				if strings.Contains(fn, "doorbell") || strings.Contains(fn, "ipc_") {
					phase2 = "dispatch SDIO doorbell state"
				} else {
					phase2 = "dispatch handler side effects"
				}
			case strings.Contains(role, "dispatch"):
				phase2 = "fan out dispatch targets"
			case strings.Contains(role, "helper"):
				phase2 = "invoke specialized support sequence"
			}
		}
		if phase2 == "call specialized helper chain" {
			switch {
			case strings.Contains(fn, "sdio_wait") || strings.Contains(fn, "hostmsgbuf") || strings.Contains(fn, "kmsg_fwd"):
				phase2 = "poll SDIO helper chain"
			case strings.Contains(fn, "ipc_") && strings.Contains(fn, "emb"):
				phase2 = "poll SDIO helper chain"
			case strings.Contains(fn, "fw_") || strings.Contains(fn, "config"):
				phase2 = "apply firmware helper chain"
			case strings.Contains(fn, "feature"):
				phase2 = "toggle feature helper chain"
			case strings.Contains(fn, "patch"):
				phase2 = "apply patch helper chain"
			case strings.Contains(fn, "crypto"):
				phase2 = "execute crypto sequence"
			case strings.Contains(fn, "sdio") && strings.Contains(fn, "wait"):
				phase2 = "poll SDIO helper chain"
			case strings.Contains(fn, "tx") || strings.Contains(fn, "send") || strings.Contains(fn, "submit"):
				phase2 = "finalize transmit path"
			case strings.Contains(fn, "sdio"):
				phase2 = "sequence SDIO state"
			case strings.Contains(fn, "math") || strings.Contains(fn, "calc") || strings.Contains(fn, "clock"):
				phase2 = "run calculation step"
			case strings.Contains(fn, "buffer") || strings.Contains(fn, "queue"):
				phase2 = "move buffer or queue state"
			}
		}

	}
	return phase1, phase2, phase3
}

func callerRoleHint(incoming []callEdge) string {
	if len(incoming) == 0 {
		return ""
	}
	familyCounts := map[string]int{}
	tokenCounts := map[string]int{}
	for _, in := range incoming {
		src := sanitizeName(in.SourceName)
		if src == "" || src == "unknown" {
			continue
		}
		if fam := familyKey(src); fam != "" {
			familyCounts[fam]++
		}
		for _, tok := range nameTokens(src) {
			tokenCounts[tok]++
		}
	}
	if len(familyCounts) > 0 {
		type pair struct {
			name string
			n    int
		}
		rows := make([]pair, 0, len(familyCounts))
		for n, c := range familyCounts {
			rows = append(rows, pair{name: n, n: c})
		}
		sort.Slice(rows, func(i, j int) bool {
			if rows[i].n == rows[j].n {
				return rows[i].name < rows[j].name
			}
			return rows[i].n > rows[j].n
		})
		if rows[0].n >= 2 || rows[0].n*2 >= len(incoming) {
			return familyLabel(rows[0].name)
		}
	}
	if len(tokenCounts) > 0 {
		type pair struct {
			name string
			n    int
		}
		rows := make([]pair, 0, len(tokenCounts))
		for n, c := range tokenCounts {
			rows = append(rows, pair{name: n, n: c})
		}
		sort.Slice(rows, func(i, j int) bool {
			if rows[i].n == rows[j].n {
				return rows[i].name < rows[j].name
			}
			return rows[i].n > rows[j].n
		})
		if rows[0].n >= 2 || rows[0].n*2 >= len(incoming) {
			return rows[0].name + " helper"
		}
	}
	return "shared helper"
}

func familyLabel(fam string) string {
	fam = sanitizeName(fam)
	switch fam {
	case "rf":
		return "rf helper"
	case "sdio":
		return "sdio helper"
	case "log":
		return "logging helper"
	case "queue":
		return "queue helper"
	case "list":
		return "container/list helper"
	case "mm", "me", "sm", "apm":
		return "mac state-machine helper"
	case "ps", "lpm":
		return "power-management helper"
	case "crypto":
		return "crypto helper"
	case "uart":
		return "uart/serial helper"
	case "wlan":
		return "wlan helper"
	case "ipc":
		return "ipc helper"
	case "timer":
		return "timer helper"
	case "msg":
		return "message helper"
	case "mac":
		return "mac subsystem helper"
	case "hw":
		return "hardware helper"
	default:
		if fam == "" || fam == "unknown" {
			return ""
		}
		return fam + " helper"
	}
}

func imageRoleHint(image string) string {
	img := strings.ToLower(strings.TrimSpace(image))
	switch {
	case strings.Contains(img, "lmacfw_rf"):
		return "rf helper"
	case strings.Contains(img, "fmacfwbt"):
		return "bluetooth helper"
	case strings.Contains(img, "rf"):
		return "rf helper"
	case strings.Contains(img, "bt"):
		return "bluetooth helper"
	case strings.Contains(img, "fmacfw_") || strings.Contains(img, "lmacfw_"):
		return "mac subsystem helper"
	default:
		return ""
	}
}

func functionRole(fn string) string {
	fn = sanitizeName(fn)
	if fn == "" || fn == "unknown" {
		return "generic leaf routine"
	}
	switch {
	case strings.Contains(fn, "timestamp"):
		return "timestamp list helper"
	case strings.Contains(fn, "uart"):
		if stem := humanizeStem(fn, ""); stem != "" {
			if strings.Contains(stem, "helper") || strings.Contains(stem, "uart") {
				return stem
			}
			return "uart " + stem + " helper"
		}
		return "uart/serial helper"
	case strings.Contains(fn, "usb"):
		if stem := humanizeStem(fn, ""); stem != "" {
			if strings.Contains(stem, "helper") || strings.Contains(stem, "usb") {
				return stem
			}
			return "usb " + stem + " helper"
		}
		return "usb helper"
	case strings.Contains(fn, "wlan"):
		if stem := humanizeStem(fn, ""); stem != "" {
			if strings.Contains(stem, "helper") || strings.Contains(stem, "wlan") {
				return stem
			}
			return "wlan " + stem + " helper"
		}
		return "wlan helper"
	case strings.HasPrefix(fn, "rf_msg_"):
		if stem := humanizeStem(fn, ""); stem != "" {
			return "rf " + stem + " helper"
		}
		return "rf message helper"
	case strings.HasPrefix(fn, "emb_kmsg_"):
		if strings.Contains(fn, "hdlr") || strings.HasSuffix(fn, "_handler") {
			return "embedded kernel message handler"
		}
		return "embedded kernel message helper"
	case strings.HasPrefix(fn, "ke_msg_alloc"):
		return "kernel message allocation helper"
	case strings.HasPrefix(fn, "ke_msg_"):
		if stem := humanizeStem(fn, ""); stem != "" {
			return "kernel " + stem + " helper"
		}
		return "kernel message helper"
	case strings.HasPrefix(fn, "msg_") || strings.HasPrefix(fn, "message_"):
		if stem := humanizeStem(fn, ""); stem != "" {
			return stem + " helper"
		}
		return "message helper"
	case (strings.Contains(fn, "msg") || strings.Contains(fn, "message")) && strings.HasSuffix(fn, "_handler"):
		if stem := humanizeStem(fn, "handler"); stem != "" {
			return stem + " handler"
		}
		return "message handler"
	case (strings.Contains(fn, "msg") || strings.Contains(fn, "message")) && strings.HasSuffix(fn, "_hdlr"):
		if stem := humanizeStem(fn, "hdlr"); stem != "" {
			return stem + " handler"
		}
		return "message handler"
	case (strings.Contains(fn, "msg") || strings.Contains(fn, "message")) && strings.Contains(fn, "dispatch"):
		return "message dispatcher"
	case (strings.Contains(fn, "msg") || strings.Contains(fn, "message")) && strings.Contains(fn, "process"):
		return "message processing helper"
	case (strings.Contains(fn, "msg") || strings.Contains(fn, "message")) &&
		!strings.Contains(fn, "dispatch") &&
		!strings.Contains(fn, "process"):
		if stem := humanizeStem(fn, ""); stem != "" {
			return stem + " helper"
		}
		return "message-related helper"
	case strings.Contains(fn, "cached"):
		return "cache lookup helper"
	case strings.Contains(fn, "spurious"):
		return "spurious interrupt handler"
	case strings.Contains(fn, "queue_init"):
		return "queue initialization helper"
	case strings.Contains(fn, "sdio"):
		if strings.Contains(fn, "feature_guard_sdio") {
			return "sdio feature guard helper"
		}
		if stem := humanizeStem(fn, ""); stem != "" {
			if strings.Contains(stem, "helper") || strings.Contains(stem, "sdio") {
				return stem
			}
			return "sdio " + stem + " helper"
		}
		return "sdio helper"
	case strings.Contains(fn, "rf"):
		if stem := humanizeStem(fn, ""); stem != "" {
			stem = strings.ReplaceAll(stem, " rf ", " ")
			stem = strings.TrimSpace(strings.TrimPrefix(stem, "rf "))
			stem = strings.ReplaceAll(stem, "rf rf", "rf")
			return "rf " + stem + " helper"
		}
		return "rf helper"
	case strings.Contains(fn, "log"):
		if stem := humanizeStem(fn, ""); stem != "" {
			stem = strings.TrimSpace(strings.TrimPrefix(stem, "log "))
			stem = strings.ReplaceAll(stem, " hw ", " hardware ")
			stem = strings.ReplaceAll(stem, "hw ", "hardware ")
			stem = strings.ReplaceAll(stem, "hardware init", "hardware initialization")
			stem = strings.ReplaceAll(stem, "hw init", "hardware initialization")
			stem = strings.ReplaceAll(stem, "dispatch2", "dispatch")
			stem = strings.ReplaceAll(stem, "push2", "push stage 2")
			stem = strings.ReplaceAll(stem, "free pool a", "free pool stage a")
			stem = strings.ReplaceAll(stem, "free pool b", "free pool stage b")
			stem = strings.ReplaceAll(stem, "free pool c", "free pool stage c")
			stem = strings.ReplaceAll(stem, "free pool d", "free pool stage d")
			stem = strings.ReplaceAll(stem, "free pool e", "free pool stage e")
			stem = strings.ReplaceAll(stem, "free pool f", "free pool stage f")
			stem = strings.ReplaceAll(stem, " hardware init", " hardware initialization")
			stem = strings.ReplaceAll(stem, " init d", " initialization stage d")
			stem = strings.ReplaceAll(stem, " init e", " initialization stage e")
			stem = strings.ReplaceAll(stem, " init a", " initialization stage a")
			stem = strings.ReplaceAll(stem, " init b", " initialization stage b")
			stem = strings.ReplaceAll(stem, " init c", " initialization stage c")
			stem = strings.ReplaceAll(stem, " init f", " initialization stage f")
			stem = strings.ReplaceAll(stem, " free pool dispatch", " free pool dispatcher")
			if stem != "" {
				return "logging " + stem + " helper"
			}
		}
		return "logging helper"
	case strings.Contains(fn, "intc") || strings.Contains(fn, "irq"):
		return "interrupt controller helper"
	case strings.Contains(fn, "hal"):
		if strings.Contains(fn, "machw") && strings.Contains(fn, "abs") && strings.Contains(fn, "timer") {
			return "HAL absolute timer helper"
		}
		if strings.HasSuffix(fn, "_evt") {
			if stem := humanizeStem(fn, "evt"); stem != "" {
				stem = strings.TrimSpace(strings.TrimPrefix(stem, "hal "))
				if stem != "" {
					return "HAL " + stem + " event callback"
				}
			}
			return "HAL event callback"
		}
		if stem := humanizeStem(fn, ""); stem != "" {
			stem = strings.TrimSpace(strings.TrimPrefix(stem, "hal "))
			if stem != "" {
				return "HAL " + stem + " helper"
			}
		}
		return "HAL shim/helper"
	case strings.Contains(fn, "queue"):
		if stem := humanizeStem(fn, ""); stem != "" {
			if strings.Contains(stem, "helper") || strings.Contains(stem, "queue") {
				return stem
			}
			return "queue " + stem + " helper"
		}
		return "queue helper"
	case strings.Contains(fn, "math"):
		if strings.Contains(fn, "fastpath") {
			return "math fastpath helper"
		}
		if strings.Contains(fn, "_int") || strings.HasSuffix(fn, "_int") {
			return "integer math helper"
		}
		if stem := humanizeStem(fn, ""); stem != "" {
			stem = strings.TrimSpace(strings.TrimPrefix(stem, "math "))
			stem = strings.TrimSpace(strings.Replace(stem, "helper ", "", 1))
			stem = strings.ReplaceAll(stem, "  ", " ")
			if stem != "" {
				return "math " + stem + " helper"
			}
		}
		return "math helper"
	case strings.Contains(fn, "clock"):
		if strings.Contains(fn, "calc") {
			return "clock calculation helper"
		}
		if stem := humanizeStem(fn, ""); stem != "" {
			stem = strings.TrimSpace(strings.TrimPrefix(stem, "clock "))
			if stem != "" {
				return "clock " + stem + " helper"
			}
		}
		return "clock helper"
	case strings.Contains(fn, "calc"):
		if stem := humanizeStem(fn, ""); stem != "" {
			stem = strings.TrimSpace(strings.TrimPrefix(stem, "calc "))
			if stem != "" {
				return "calculation " + stem + " helper"
			}
		}
		return "calculation helper"
	case strings.Contains(fn, "list"):
		if stem := humanizeStem(fn, ""); stem != "" {
			stem = strings.TrimSpace(strings.TrimPrefix(stem, "list "))
			if stem != "" {
				return "container/list " + stem + " helper"
			}
		}
		return "container/list helper"
	case strings.Contains(fn, "mem") || strings.Contains(fn, "buffer"):
		if stem := humanizeStem(fn, ""); stem != "" {
			if strings.Contains(stem, "helper") || strings.Contains(stem, "buffer") || strings.Contains(stem, "mem") {
				return stem
			}
			return "buffer " + stem + " helper"
		}
		return "buffer/memory helper"
	case strings.Contains(fn, "parse"):
		return "parsing helper"
	case strings.Contains(fn, "schedule"):
		if stem := humanizeStem(fn, ""); stem != "" {
			stem = strings.TrimSpace(strings.TrimPrefix(stem, "ke "))
			stem = strings.TrimSpace(strings.TrimSuffix(stem, " schedule"))
			stem = strings.ReplaceAll(stem, "  ", " ")
			if stem != "" {
				if stem == "schedule" {
					if strings.Contains(fn, "evt") {
						return "event scheduler"
					}
					return "scheduler"
				}
				return stem + " scheduler"
			}
		}
		return "scheduler helper"
	case strings.Contains(fn, "wakeup") || strings.Contains(fn, "wake"):
		return "wakeup helper"
	case strings.Contains(fn, "notify"):
		return "notification helper"
	case strings.Contains(fn, "panic"):
		return "panic/abort helper"
	case strings.Contains(fn, "debug"):
		return "debug helper"
	case strings.Contains(fn, "flag") && strings.Contains(fn, "check"):
		return "state flag check helper"
	case strings.Contains(fn, "flag") && strings.Contains(fn, "init"):
		return "flag initialization helper"
	case strings.Contains(fn, "flag"):
		if stem := humanizeStem(fn, ""); stem != "" {
			return stem + " helper"
		}
		return "state/flag helper"
	case strings.Contains(fn, "clear"):
		if strings.Contains(fn, "timer") {
			return "timer clear helper"
		}
		if strings.Contains(fn, "sdio") {
			return "clear sdio state helper"
		}
		if strings.Contains(fn, "flag") {
			return "clear flags helper"
		}
		return "clear/reset helper"
	case strings.Contains(fn, "insert") || strings.Contains(fn, "remove") || strings.Contains(fn, "find"):
		return "container/list helper"
	case strings.HasPrefix(fn, "tx_") || strings.Contains(fn, "_tx_") || fn == "tx":
		if stem := humanizeStem(fn, ""); stem != "" {
			stem = strings.TrimSpace(strings.TrimPrefix(stem, "tx "))
			if stem != "" {
				return "transmit " + stem + " helper"
			}
		}
		return "transmit helper"
	case (strings.Contains(fn, "idle") || strings.Contains(fn, "lpm") || strings.Contains(fn, "ps_")) &&
		!strings.HasSuffix(fn, "_handler") &&
		!strings.HasSuffix(fn, "_req") &&
		!strings.HasSuffix(fn, "_cfm") &&
		!strings.HasSuffix(fn, "_ind"):
		if strings.Contains(fn, "idle") && strings.Contains(fn, "process") {
			return "idle processing helper"
		}
		if stem := humanizeStem(fn, ""); stem != "" {
			return stem + " helper"
		}
		return "power-state helper"
	case strings.Contains(fn, "alloc"):
		return "allocation helper"
	case strings.Contains(fn, "crypto"):
		if strings.HasPrefix(fn, "crypto_hw_") {
			if stem := humanizeStem(fn, ""); stem != "" {
				stem = strings.TrimSpace(strings.TrimPrefix(stem, "crypto "))
				stem = strings.TrimSpace(strings.TrimPrefix(stem, "hw "))
				if stem != "" {
					return "crypto hardware " + stem + " helper"
				}
			}
			return "crypto hardware helper"
		}
		if strings.HasPrefix(fn, "crypto_key_") {
			if stem := humanizeStem(fn, ""); stem != "" {
				stem = strings.TrimSpace(strings.TrimPrefix(stem, "crypto "))
				if stem != "" {
					return "crypto " + stem + " helper"
				}
			}
			return "crypto key helper"
		}
		if strings.HasPrefix(fn, "crypto_table_") {
			if stem := humanizeStem(fn, ""); stem != "" {
				stem = strings.TrimSpace(strings.TrimPrefix(stem, "crypto "))
				if stem != "" {
					return "crypto " + stem + " helper"
				}
			}
			return "crypto table helper"
		}
		if strings.Contains(fn, "iq_calculate") {
			return "crypto IQ calculation helper"
		}
		return "crypto helper"
	case strings.Contains(fn, "patch"):
		return "patching helper"
	case strings.HasPrefix(fn, "ke_timer_"):
		if stem := humanizeStem(fn, ""); stem != "" {
			stem = strings.TrimSpace(strings.TrimPrefix(stem, "timer "))
			if stem != "" {
				return "kernel timer " + stem + " helper"
			}
		}
		return "kernel timer helper"
	case strings.HasPrefix(fn, "mm_timer_"):
		if stem := humanizeStem(fn, ""); stem != "" {
			stem = strings.TrimSpace(strings.TrimPrefix(stem, "timer "))
			if stem != "" {
				return "mac timer " + stem + " helper"
			}
		}
		return "mac timer helper"
	case strings.Contains(fn, "timer"):
		if stem := humanizeStem(fn, ""); stem != "" {
			if strings.Contains(stem, "helper") || strings.Contains(stem, "timer") {
				return stem
			}
			return "timer " + stem + " helper"
		}
		return "timer helper"
	case strings.HasSuffix(fn, "_evt"):
		if stem := humanizeStem(fn, "evt"); stem != "" {
			return stem + " event callback"
		}
		return "event callback leaf"
	case strings.HasSuffix(fn, "_cfm"):
		if stem := humanizeStem(fn, "cfm"); stem != "" {
			return stem + " confirmation handler"
		}
		return "confirmation callback leaf"
	case strings.HasSuffix(fn, "_cb"):
		if stem := humanizeStem(fn, "cb"); stem != "" {
			return stem + " callback"
		}
		return "callback leaf"
	case strings.HasSuffix(fn, "_ind"):
		if stem := humanizeStem(fn, "ind"); stem != "" {
			return stem + " indication handler"
		}
		return "indication callback leaf"
	case strings.HasSuffix(fn, "_req"):
		if stem := humanizeStem(fn, "req"); stem != "" {
			return stem + " request handler"
		}
		return "request handler leaf"
	case strings.HasSuffix(fn, "_handler"):
		switch {
		case strings.Contains(fn, "_req_handler"):
			if stem := humanizeStem(fn, "handler"); stem != "" {
				return stem + " request handler"
			}
		case strings.Contains(fn, "_cfm_handler"):
			if stem := humanizeStem(fn, "handler"); stem != "" {
				return stem + " confirmation handler"
			}
		case strings.Contains(fn, "_ind_handler"):
			if stem := humanizeStem(fn, "handler"); stem != "" {
				return stem + " indication handler"
			}
		case strings.Contains(fn, "_evt_handler"):
			if stem := humanizeStem(fn, "handler"); stem != "" {
				return stem + " event handler"
			}
		}
		if stem := humanizeStem(fn, "handler"); stem != "" {
			return stem + " handler"
		}
		return "event handler leaf"
	case strings.HasSuffix(fn, "_dispatch"):
		return "dispatcher leaf"
	case strings.HasSuffix(fn, "_process"):
		return "processing leaf"
	case strings.HasSuffix(fn, "_init"):
		if strings.Contains(fn, "queue_init") {
			return "queue initialization helper"
		}
		return "initialization leaf"
	case strings.Contains(fn, "sub_"):
		return "unnamed helper"
	case fn == "thunk":
		return "relay call helper"
	default:
		return "shared helper"
	}
}

func humanizeStem(fn string, trimSuffix string) string {
	fn = sanitizeName(fn)
	if fn == "" || fn == "unknown" {
		return ""
	}
	parts := strings.Split(fn, "_")
	if len(parts) == 0 {
		return ""
	}
	if trimSuffix != "" && parts[len(parts)-1] == trimSuffix {
		parts = parts[:len(parts)-1]
	}
	if len(parts) == 0 {
		return ""
	}
	dropPrefix := map[string]struct{}{
		"mm": {}, "me": {}, "apm": {}, "ps": {}, "sm": {},
		"rf": {}, "sdio": {}, "log": {}, "tx": {}, "rx": {},
		"usb": {}, "uart": {}, "wlan": {}, "queue": {}, "list": {},
		"sub": {}, "ke": {},
	}
	if _, ok := dropPrefix[parts[0]]; ok && len(parts) > 1 {
		parts = parts[1:]
	}
	if len(parts) == 0 {
		return ""
	}
	generic := map[string]struct{}{
		"req": {}, "cfm": {}, "ind": {}, "evt": {}, "cb": {}, "handler": {},
	}
	clean := make([]string, 0, len(parts))
	for _, p := range parts {
		if _, ok := generic[p]; ok {
			continue
		}
		switch p {
		case "msg":
			p = "message"
		case "del":
			p = "delete"
		case "cfg":
			p = "config"
		case "bcn":
			p = "beacon"
		case "arpoffload":
			p = "arp offload"
		case "ps":
			p = "power save"
		case "cac":
			p = "CAC"
		case "tbtt":
			p = "TBTT"
		case "req":
			p = "request"
		case "cfm":
			p = "confirmation"
		case "ind":
			p = "indication"
		case "evt":
			p = "event"
		case "hdlr":
			p = "handler"
		case "upm":
			p = "power-management"
		}
		if len(p) == 0 {
			continue
		}
		clean = append(clean, p)
	}
	if len(clean) == 0 {
		return ""
	}
	return strings.Join(clean, " ")
}

func edgesForTask(t implTask, inAdj, outAdj, inByName, outByName map[string][]callEdge) ([]callEdge, []callEdge) {
	if strings.TrimSpace(t.Address) != "" && strings.TrimSpace(t.Image) != "" && !strings.EqualFold(strings.TrimSpace(t.Image), "shared") {
		for _, a := range addrVariants(t.Address) {
			key := addrKey(t.Image, a)
			inEdges := inAdj[key]
			outEdges := outAdj[key]
			if len(inEdges) > 0 || len(outEdges) > 0 {
				n := sanitizeName(t.Function)
				if n != "" && n != "unknown" {
					if len(inEdges) == 0 {
						inEdges = inByName[n]
					}
					if len(outEdges) == 0 {
						outEdges = outByName[n]
					}
				}
				return inEdges, outEdges
			}
		}
	}
	n := sanitizeName(t.Function)
	if n == "" || n == "unknown" {
		return nil, nil
	}
	return inByName[n], outByName[n]
}

func selectCallees(task implTask, outgoing []callEdge, outAdj map[string][]callEdge, minConf float64, fallbackMinConf float64) []callEdge {
	if len(outgoing) == 0 {
		return nil
	}
	taskName := sanitizeName(task.Function)
	const maxCallees = 8
	build := func(cutoff float64) []callEdge {
		selected := make([]callEdge, 0, maxCallees)
		seen := map[string]struct{}{}
		for _, e := range outgoing {
			if e.Confidence < cutoff {
				continue
			}
			n := sanitizeName(nonEmpty(e.TargetName, "sub_"+strings.TrimPrefix(strings.ToLower(e.TargetAddr), "0x")))
			if n == "" || n == "unknown" || n == taskName {
				continue
			}
			if (taskName == "tx_submit" || taskName == "log_queue_push") && n == "log_queue_alloc" {
				continue
			}
			if !isDispatcherLike(task.Function) && !isRelatedFunction(taskName, n) && !strings.HasPrefix(n, "sub_") && e.Confidence < 0.85 {
				continue
			}
			if _, ok := seen[n]; ok {
				continue
			}
			if isGenericName(n) && hasSpecificAlternative(outgoing, cutoff) {
				continue
			}
			// Drop simple ping-pong loopback edges with weaker/equal confidence.
			if hasDirectReturnEdge(task, e, outAdj, e.Confidence) {
				continue
			}
			seen[n] = struct{}{}
			selected = append(selected, e)
			if len(selected) >= maxCallees {
				break
			}
		}
		return selected
	}
	selected := build(minConf)
	if len(selected) > 0 {
		return selected
	}
	if fallbackMinConf > 0 && fallbackMinConf < minConf {
		return build(fallbackMinConf)
	}
	return selected
}

func isGenericName(n string) bool {
	return n == "thunk" || strings.HasPrefix(n, "sub_")
}

func hasSpecificAlternative(outgoing []callEdge, cutoff float64) bool {
	for _, e := range outgoing {
		if e.Confidence < cutoff {
			continue
		}
		n := sanitizeName(nonEmpty(e.TargetName, "sub_"+strings.TrimPrefix(strings.ToLower(e.TargetAddr), "0x")))
		if n != "" && n != "unknown" && !isGenericName(n) {
			return true
		}
	}
	return false
}

func hasDirectReturnEdge(task implTask, e callEdge, outAdj map[string][]callEdge, conf float64) bool {
	back := outAdj[addrKey(task.Image, e.TargetAddr)]
	for _, b := range back {
		if strings.EqualFold(strings.TrimSpace(b.TargetAddr), strings.TrimSpace(task.Address)) && b.Confidence >= conf {
			return true
		}
	}
	return false
}

type functionLinkRec struct {
	SourceName string  `json:"source_name"`
	TargetName string  `json:"target_name"`
	Confidence float64 `json:"confidence"`
}

func buildLinkedNameAliases(path string, minConf float64) map[string][]string {
	f, err := os.Open(path)
	if err != nil {
		return map[string][]string{}
	}
	defer f.Close()
	adj := map[string]map[string]struct{}{}
	sc := bufio.NewScanner(f)
	sc.Buffer(make([]byte, 4096), 8*1024*1024)
	for sc.Scan() {
		line := strings.TrimSpace(sc.Text())
		if line == "" {
			continue
		}
		var r functionLinkRec
		if err := json.Unmarshal([]byte(line), &r); err != nil {
			continue
		}
		if r.Confidence < minConf {
			continue
		}
		a := sanitizeName(r.SourceName)
		b := sanitizeName(r.TargetName)
		if a == "" || b == "" || a == "unknown" || b == "unknown" || a == b {
			continue
		}
		if adj[a] == nil {
			adj[a] = map[string]struct{}{}
		}
		if adj[b] == nil {
			adj[b] = map[string]struct{}{}
		}
		adj[a][b] = struct{}{}
		adj[b][a] = struct{}{}
	}
	out := map[string][]string{}
	for k := range adj {
		seen := map[string]struct{}{k: struct{}{}}
		q := []string{k}
		component := []string{k}
		for len(q) > 0 && len(component) < 8 {
			cur := q[0]
			q = q[1:]
			for n := range adj[cur] {
				if _, ok := seen[n]; ok {
					continue
				}
				seen[n] = struct{}{}
				component = append(component, n)
				q = append(q, n)
				if len(component) >= 8 {
					break
				}
			}
		}
		sort.Strings(component)
		out[k] = component
	}
	return out
}

func expandLinkedAliases(n string) []string {
	base := aliasFunctionNames(n)
	if len(base) == 0 {
		return nil
	}
	seen := map[string]struct{}{}
	out := make([]string, 0, 8)
	add := func(x string) {
		x = sanitizeName(x)
		if x == "" || x == "unknown" {
			return
		}
		if _, ok := seen[x]; ok {
			return
		}
		seen[x] = struct{}{}
		out = append(out, x)
	}
	for _, b := range base {
		add(b)
		for _, a := range linkedNameAliases[b] {
			add(a)
		}
	}
	if len(out) > 8 {
		out = out[:8]
	}
	return out
}

func buildLinkedFunctionHints(path string, minConf float64, nameHints map[string][]string) map[string][]string {
	f, err := os.Open(path)
	if err != nil {
		return map[string][]string{}
	}
	defer f.Close()
	adj := map[string]map[string]struct{}{}
	sc := bufio.NewScanner(f)
	sc.Buffer(make([]byte, 4096), 8*1024*1024)
	for sc.Scan() {
		line := strings.TrimSpace(sc.Text())
		if line == "" {
			continue
		}
		var r functionLinkRec
		if err := json.Unmarshal([]byte(line), &r); err != nil {
			continue
		}
		if r.Confidence < minConf {
			continue
		}
		a := sanitizeName(r.SourceName)
		b := sanitizeName(r.TargetName)
		if a == "" || b == "" || a == "unknown" || b == "unknown" || a == b {
			continue
		}
		if adj[a] == nil {
			adj[a] = map[string]struct{}{}
		}
		if adj[b] == nil {
			adj[b] = map[string]struct{}{}
		}
		adj[a][b] = struct{}{}
		adj[b][a] = struct{}{}
	}
	out := map[string][]string{}
	for fn, nbrs := range adj {
		seen := map[string]struct{}{}
		merged := make([]string, 0, 8)
		for n := range nbrs {
			for _, c := range nameHints[n] {
				cc := sanitizeName(c)
				if cc == "" || cc == "unknown" || cc == fn {
					continue
				}
				if _, ok := seen[cc]; ok {
					continue
				}
				seen[cc] = struct{}{}
				merged = append(merged, cc)
				if len(merged) >= 8 {
					break
				}
			}
			if len(merged) >= 8 {
				break
			}
		}
		if len(merged) > 0 {
			sort.Strings(merged)
			out[fn] = merged
		}
	}
	return out
}

func inferFromLinkedFunctionHints(task implTask, minConf float64, fallbackMinConf float64) []callEdge {
	fn := sanitizeName(task.Function)
	hints := linkedFunctionHints[fn]
	if len(hints) == 0 {
		return nil
	}
	out := make([]callEdge, 0, 6)
	seen := map[string]struct{}{}
	for _, h := range hints {
		n := sanitizeName(h)
		if n == "" || n == fn {
			continue
		}
		if _, ok := seen[n]; ok {
			continue
		}
		seen[n] = struct{}{}
		out = append(out, callEdge{
			Image:      task.Image,
			SourceName: fn,
			TargetName: n,
			Confidence: 0.68,
		})
		if len(out) >= 6 {
			break
		}
	}
	return out
}

func buildAddressNeighborHints(outAdj map[string][]callEdge) map[string][]string {
	type src struct {
		image string
		addr  uint64
	}
	bySrc := map[src]map[string]struct{}{}
	for key, edges := range outAdj {
		parts := strings.SplitN(key, "|", 2)
		if len(parts) != 2 {
			continue
		}
		img := strings.TrimSpace(parts[0])
		addrS := strings.TrimSpace(parts[1])
		addrV, err := parseAddrHex(addrS)
		if err != nil {
			continue
		}
		k := src{image: img, addr: addrV}
		if bySrc[k] == nil {
			bySrc[k] = map[string]struct{}{}
		}
		for _, e := range edges {
			n := sanitizeName(nonEmpty(e.TargetName, "sub_"+strings.TrimPrefix(strings.ToLower(e.TargetAddr), "0x")))
			if n == "" || n == "unknown" {
				continue
			}
			bySrc[k][n] = struct{}{}
		}
	}
	byImage := map[string][]src{}
	for k := range bySrc {
		byImage[k.image] = append(byImage[k.image], k)
	}
	for img := range byImage {
		sort.Slice(byImage[img], func(i, j int) bool { return byImage[img][i].addr < byImage[img][j].addr })
	}
	out := map[string][]string{}
	for img, lst := range byImage {
		for i, cur := range lst {
			cands := map[string]struct{}{}
			// Use nearby edge-bearing addresses in same image as heuristic context.
			for j := i - 4; j <= i+4; j++ {
				if j < 0 || j >= len(lst) || j == i {
					continue
				}
				nbr := lst[j]
				delta := cur.addr
				if nbr.addr > cur.addr {
					delta = nbr.addr - cur.addr
				} else {
					delta = cur.addr - nbr.addr
				}
				if delta > 0x3000 {
					continue
				}
				for n := range bySrc[nbr] {
					cands[n] = struct{}{}
				}
			}
			if len(cands) == 0 {
				continue
			}
			names := make([]string, 0, len(cands))
			for n := range cands {
				names = append(names, n)
			}
			sort.Strings(names)
			if len(names) > 8 {
				names = names[:8]
			}
			out[img+"|"+fmt.Sprintf("0x%x", cur.addr)] = names
		}
	}
	return out
}

func inferFromAddressNeighborHints(task implTask, minConf float64, fallbackMinConf float64) []callEdge {
	img := strings.ToLower(strings.TrimSpace(task.Image))
	if img == "" || img == "shared" {
		return nil
	}
	addrV, err := parseAddrHex(task.Address)
	if err != nil {
		return nil
	}
	var hints []string
	for _, a := range addrVariants(task.Address) {
		if hs := addressNeighborHints[img+"|"+strings.ToLower(strings.TrimSpace(a))]; len(hs) > 0 {
			hints = hs
			break
		}
	}
	if len(hints) == 0 {
		// Find nearest keyed address in same image.
		bestDelta := uint64(^uint64(0))
		best := ""
		pfx := img + "|"
		for k := range addressNeighborHints {
			if !strings.HasPrefix(k, pfx) {
				continue
			}
			av, err := parseAddrHex(strings.TrimPrefix(k, pfx))
			if err != nil {
				continue
			}
			d := av
			if addrV > av {
				d = addrV - av
			} else {
				d = av - addrV
			}
			if d < bestDelta {
				bestDelta = d
				best = k
			}
		}
		if best != "" && bestDelta <= 0x3000 {
			hints = addressNeighborHints[best]
		}
	}
	if len(hints) == 0 {
		return nil
	}
	fn := sanitizeName(task.Function)
	out := make([]callEdge, 0, 6)
	seen := map[string]struct{}{}
	for _, h := range hints {
		n := sanitizeName(h)
		if n == "" || n == "unknown" || n == fn {
			continue
		}
		if _, ok := seen[n]; ok {
			continue
		}
		seen[n] = struct{}{}
		out = append(out, callEdge{
			Image:      task.Image,
			SourceAddr: task.Address,
			SourceName: fn,
			TargetName: n,
			Confidence: 0.63,
		})
		if len(out) >= 6 {
			break
		}
	}
	return out
}

func parseAddrHex(s string) (uint64, error) {
	s = strings.TrimSpace(strings.ToLower(s))
	if s == "" {
		return 0, fmt.Errorf("empty")
	}
	s = strings.TrimPrefix(s, "0x")
	return strconv.ParseUint(s, 16, 64)
}

func inferFromIncoming(task implTask, incoming []callEdge, outAdj map[string][]callEdge, outByName map[string][]callEdge, minConf float64, fallbackMinConf float64) []callEdge {
	if len(incoming) == 0 {
		return nil
	}
	taskName := sanitizeName(task.Function)
	type vote struct {
		edge  callEdge
		score float64
	}
	votes := map[string]vote{}
	for _, in := range incoming {
		if in.Confidence < fallbackMinConf {
			continue
		}
		var callerOut []callEdge
		if strings.TrimSpace(in.SourceAddr) != "" && strings.TrimSpace(in.Image) != "" {
			callerOut = outAdj[addrKey(in.Image, in.SourceAddr)]
		}
		if len(callerOut) == 0 {
			srcName := sanitizeName(in.SourceName)
			if srcName != "" && srcName != "unknown" {
				callerOut = outByName[srcName]
			}
		}
		for _, oe := range callerOut {
			if oe.Confidence < fallbackMinConf {
				continue
			}
			n := sanitizeName(nonEmpty(oe.TargetName, "sub_"+strings.TrimPrefix(strings.ToLower(oe.TargetAddr), "0x")))
			if n == "" || n == "unknown" || n == taskName {
				continue
			}
			if !isDispatcherLike(task.Function) && !isRelatedFunction(taskName, n) && !strings.HasPrefix(n, "sub_") {
				continue
			}
			cur := votes[n]
			sc := in.Confidence*0.6 + oe.Confidence*0.4
			cur.score += sc
			if sc > cur.edge.Confidence {
				cur.edge = oe
			}
			votes[n] = cur
		}
	}
	if len(votes) == 0 {
		return nil
	}
	keys := make([]string, 0, len(votes))
	for k := range votes {
		keys = append(keys, k)
	}
	sort.Slice(keys, func(i, j int) bool { return votes[keys[i]].score > votes[keys[j]].score })
	maxOut := 4
	out := make([]callEdge, 0, maxOut)
	for _, k := range keys {
		out = append(out, votes[k].edge)
		if len(out) >= maxOut {
			break
		}
	}
	return out
}

func loadComposedHints(dir string) (map[string][]string, map[string][]string, error) {
	ents, err := os.ReadDir(dir)
	if err != nil {
		return nil, nil, err
	}
	out := map[string][]string{}
	callers := map[string][]string{}
	fnRe := regexp.MustCompile(`(?s)void\s+([a-zA-Z0-9_]+)\s*\(\s*void\s*\)\s*\{(.*?)\n\}`)
	callRe := regexp.MustCompile(`(?m)^\s*([a-zA-Z_][a-zA-Z0-9_]*)\s*\(\s*\)\s*;`)
	for _, e := range ents {
		if e.IsDir() || !strings.HasSuffix(e.Name(), ".reconstructed.c") {
			continue
		}
		b, err := os.ReadFile(filepath.Join(dir, e.Name()))
		if err != nil {
			continue
		}
		matches := fnRe.FindAllStringSubmatch(string(b), -1)
		for _, m := range matches {
			if len(m) < 3 {
				continue
			}
			fn := sanitizeName(m[1])
			body := m[2]
			if fn == "" || fn == "unknown" {
				continue
			}
			cs := callRe.FindAllStringSubmatch(body, -1)
			if len(cs) == 0 {
				continue
			}
			seen := map[string]struct{}{}
			list := make([]string, 0, len(cs))
			for _, c := range cs {
				if len(c) < 2 {
					continue
				}
				n := sanitizeName(c[1])
				if n == "" || n == "unknown" || n == fn {
					continue
				}
				if _, ok := seen[n]; ok {
					continue
				}
				seen[n] = struct{}{}
				list = append(list, n)
				if len(list) >= 8 {
					break
				}
			}
			if len(list) > 0 {
				out[fn] = list
				for _, callee := range list {
					callers[callee] = appendUnique(callers[callee], fn)
				}
			}
		}
	}
	return out, callers, nil
}

func inferFromComposedHints(task implTask, hints map[string][]string) []callEdge {
	fn := sanitizeName(task.Function)
	if fn == "" || fn == "unknown" {
		return nil
	}
	ns := hints[fn]
	if len(ns) == 0 {
		return nil
	}
	out := make([]callEdge, 0, len(ns))
	for _, n := range ns {
		if isGenericName(n) || n == fn {
			continue
		}
		if !isDispatcherLike(task.Function) && !isRelatedFunction(fn, n) {
			continue
		}
		out = append(out, callEdge{
			Image:      task.Image,
			SourceAddr: task.Address,
			SourceName: task.Function,
			TargetAddr: "",
			TargetName: n,
			Confidence: 0.25,
		})
	}
	return out
}

func inferFromComposedContext(task implTask, hints map[string][]string, callers map[string][]string) []callEdge {
	fn := sanitizeName(task.Function)
	if fn == "" || fn == "unknown" {
		return nil
	}
	srcCallers := callers[fn]
	if len(srcCallers) == 0 {
		return nil
	}
	votes := map[string]int{}
	for _, c := range srcCallers {
		for _, cand := range hints[c] {
			if cand == fn || cand == "" || cand == "unknown" || isGenericName(cand) {
				continue
			}
			if !isDispatcherLike(task.Function) && !isRelatedFunction(fn, cand) {
				continue
			}
			votes[cand]++
		}
	}
	if len(votes) == 0 {
		return nil
	}
	type pair struct {
		name string
		n    int
	}
	rows := make([]pair, 0, len(votes))
	for n, c := range votes {
		rows = append(rows, pair{name: n, n: c})
	}
	sort.Slice(rows, func(i, j int) bool {
		if rows[i].n == rows[j].n {
			return rows[i].name < rows[j].name
		}
		return rows[i].n > rows[j].n
	})
	limit := 3
	if len(rows) < limit {
		limit = len(rows)
	}
	out := make([]callEdge, 0, limit)
	for i := 0; i < limit; i++ {
		out = append(out, callEdge{
			Image:      task.Image,
			SourceAddr: task.Address,
			SourceName: task.Function,
			TargetName: rows[i].name,
			Confidence: 0.18,
		})
	}
	return out
}

func appendUnique(list []string, v string) []string {
	for _, x := range list {
		if x == v {
			return list
		}
	}
	return append(list, v)
}

func buildFamilyHints(outByName map[string][]callEdge, minConf float64, fallbackMinConf float64) map[string][]string {
	type score struct {
		name string
		w    float64
	}
	familyVotes := map[string]map[string]float64{}
	for src, edges := range outByName {
		fam := familyKey(src)
		if fam == "" {
			continue
		}
		if familyVotes[fam] == nil {
			familyVotes[fam] = map[string]float64{}
		}
		for _, e := range edges {
			if e.Confidence < fallbackMinConf {
				continue
			}
			tgt := sanitizeName(nonEmpty(e.TargetName, "sub_"+strings.TrimPrefix(strings.ToLower(e.TargetAddr), "0x")))
			if tgt == "" || tgt == "unknown" || isGenericName(tgt) || tgt == src {
				continue
			}
			w := e.Confidence
			if e.Confidence < minConf {
				w *= 0.5
			}
			familyVotes[fam][tgt] += w
		}
	}
	out := map[string][]string{}
	for fam, votes := range familyVotes {
		pairs := make([]score, 0, len(votes))
		for n, w := range votes {
			pairs = append(pairs, score{name: n, w: w})
		}
		sort.Slice(pairs, func(i, j int) bool { return pairs[i].w > pairs[j].w })
		if len(pairs) == 0 {
			continue
		}
		limit := 4
		if len(pairs) < limit {
			limit = len(pairs)
		}
		list := make([]string, 0, limit)
		for i := 0; i < limit; i++ {
			list = append(list, pairs[i].name)
		}
		out[fam] = list
	}
	return out
}

func inferFromFamilyHints(task implTask, familyHints map[string][]string) []callEdge {
	fam := familyKey(task.Function)
	if fam == "" {
		return nil
	}
	ns := familyHints[fam]
	if len(ns) == 0 {
		return nil
	}
	self := sanitizeName(task.Function)
	out := make([]callEdge, 0, len(ns))
	for _, n := range ns {
		if n == "" || n == "unknown" || n == self {
			continue
		}
		if !isDispatcherLike(task.Function) && !isRelatedFunction(self, n) {
			continue
		}
		out = append(out, callEdge{
			Image:      task.Image,
			SourceAddr: task.Address,
			SourceName: task.Function,
			TargetName: n,
			Confidence: 0.2,
		})
	}
	return out
}

func familyKey(fn string) string {
	fn = sanitizeName(fn)
	if fn == "" || fn == "unknown" {
		return ""
	}
	parts := strings.Split(fn, "_")
	if len(parts) == 0 {
		return ""
	}
	p := parts[0]
	if len(p) < 2 || p == "sub" || p == "log" {
		return ""
	}
	return p
}

func buildSuffixHints(outByName map[string][]callEdge, minConf float64, fallbackMinConf float64) map[string][]string {
	type score struct {
		name string
		w    float64
	}
	suffixVotes := map[string]map[string]float64{}
	for src, edges := range outByName {
		sfx := suffixKey(src)
		if sfx == "" {
			continue
		}
		if suffixVotes[sfx] == nil {
			suffixVotes[sfx] = map[string]float64{}
		}
		for _, e := range edges {
			if e.Confidence < fallbackMinConf {
				continue
			}
			tgt := sanitizeName(nonEmpty(e.TargetName, "sub_"+strings.TrimPrefix(strings.ToLower(e.TargetAddr), "0x")))
			if tgt == "" || tgt == "unknown" || isGenericName(tgt) || tgt == src {
				continue
			}
			w := e.Confidence
			if e.Confidence < minConf {
				w *= 0.5
			}
			suffixVotes[sfx][tgt] += w
		}
	}
	out := map[string][]string{}
	for sfx, votes := range suffixVotes {
		rows := make([]score, 0, len(votes))
		for n, w := range votes {
			rows = append(rows, score{name: n, w: w})
		}
		sort.Slice(rows, func(i, j int) bool { return rows[i].w > rows[j].w })
		if len(rows) == 0 {
			continue
		}
		limit := 3
		if len(rows) < limit {
			limit = len(rows)
		}
		list := make([]string, 0, limit)
		for i := 0; i < limit; i++ {
			list = append(list, rows[i].name)
		}
		out[sfx] = list
	}
	return out
}

func inferFromSuffixHints(task implTask, suffixHints map[string][]string) []callEdge {
	sfx := suffixKey(task.Function)
	if sfx == "" {
		return nil
	}
	ns := suffixHints[sfx]
	if len(ns) == 0 {
		return nil
	}
	self := sanitizeName(task.Function)
	out := make([]callEdge, 0, len(ns))
	for _, n := range ns {
		if n == "" || n == "unknown" || n == self {
			continue
		}
		if !isDispatcherLike(task.Function) && !isRelatedFunction(self, n) {
			continue
		}
		out = append(out, callEdge{
			Image:      task.Image,
			SourceAddr: task.Address,
			SourceName: task.Function,
			TargetName: n,
			Confidence: 0.17,
		})
	}
	return out
}

func suffixKey(fn string) string {
	fn = sanitizeName(fn)
	if fn == "" || fn == "unknown" || strings.HasPrefix(fn, "sub_") {
		return ""
	}
	parts := strings.Split(fn, "_")
	if len(parts) < 2 {
		return ""
	}
	sfx := parts[len(parts)-1]
	switch sfx {
	case "handler", "init", "process", "dispatch", "update", "check", "set", "get", "clear":
		return sfx
	default:
		return ""
	}
}

func buildTokenHints(outByName map[string][]callEdge, minConf float64, fallbackMinConf float64) map[string][]string {
	type score struct {
		name string
		w    float64
	}
	tokenVotes := map[string]map[string]float64{}
	for src, edges := range outByName {
		tokens := nameTokens(src)
		if len(tokens) == 0 {
			continue
		}
		for _, tok := range tokens {
			if tokenVotes[tok] == nil {
				tokenVotes[tok] = map[string]float64{}
			}
		}
		for _, e := range edges {
			if e.Confidence < fallbackMinConf {
				continue
			}
			tgt := sanitizeName(nonEmpty(e.TargetName, "sub_"+strings.TrimPrefix(strings.ToLower(e.TargetAddr), "0x")))
			if tgt == "" || tgt == "unknown" || isGenericName(tgt) || tgt == src {
				continue
			}
			w := e.Confidence
			if e.Confidence < minConf {
				w *= 0.5
			}
			for _, tok := range tokens {
				tokenVotes[tok][tgt] += w
			}
		}
	}
	out := map[string][]string{}
	for tok, votes := range tokenVotes {
		rows := make([]score, 0, len(votes))
		for n, w := range votes {
			rows = append(rows, score{name: n, w: w})
		}
		sort.Slice(rows, func(i, j int) bool { return rows[i].w > rows[j].w })
		if len(rows) == 0 {
			continue
		}
		limit := 4
		if len(rows) < limit {
			limit = len(rows)
		}
		list := make([]string, 0, limit)
		for i := 0; i < limit; i++ {
			list = append(list, rows[i].name)
		}
		out[tok] = list
	}
	return out
}

func inferFromTokenHints(task implTask, tokenHints map[string][]string) []callEdge {
	tokens := nameTokens(task.Function)
	if len(tokens) == 0 {
		return nil
	}
	type pair struct {
		name string
		n    int
	}
	votes := map[string]int{}
	for _, tok := range tokens {
		for _, n := range tokenHints[tok] {
			if n == "" || n == "unknown" || n == sanitizeName(task.Function) {
				continue
			}
			if !isDispatcherLike(task.Function) && !isRelatedFunction(sanitizeName(task.Function), n) {
				continue
			}
			votes[n]++
		}
	}
	if len(votes) == 0 {
		return nil
	}
	rows := make([]pair, 0, len(votes))
	for n, c := range votes {
		rows = append(rows, pair{name: n, n: c})
	}
	sort.Slice(rows, func(i, j int) bool {
		if rows[i].n == rows[j].n {
			return rows[i].name < rows[j].name
		}
		return rows[i].n > rows[j].n
	})
	limit := 3
	if len(rows) < limit {
		limit = len(rows)
	}
	out := make([]callEdge, 0, limit)
	for i := 0; i < limit; i++ {
		out = append(out, callEdge{
			Image:      task.Image,
			SourceAddr: task.Address,
			SourceName: task.Function,
			TargetName: rows[i].name,
			Confidence: 0.16,
		})
	}
	return out
}

func nameTokens(fn string) []string {
	fn = sanitizeName(fn)
	if fn == "" || fn == "unknown" || strings.HasPrefix(fn, "sub_") {
		return nil
	}
	parts := strings.Split(fn, "_")
	if len(parts) == 0 {
		return nil
	}
	stop := map[string]struct{}{
		"handler": {}, "init": {}, "process": {}, "dispatch": {}, "update": {}, "check": {}, "set": {}, "get": {}, "clear": {},
		"req": {}, "cfm": {}, "ind": {}, "evt": {}, "msg": {}, "cb": {},
	}
	out := make([]string, 0, len(parts))
	seen := map[string]struct{}{}
	for _, p := range parts {
		if len(p) < 2 {
			continue
		}
		if _, bad := stop[p]; bad {
			continue
		}
		if _, ok := seen[p]; ok {
			continue
		}
		seen[p] = struct{}{}
		out = append(out, p)
	}
	return out
}

func buildImageHints(inAdj, outAdj map[string][]callEdge, minConf float64, fallbackMinConf float64) map[string][]string {
	type score struct {
		name string
		w    float64
	}
	votes := map[string]map[string]float64{}
	add := func(img, tgt string, w float64) {
		img = strings.ToLower(strings.TrimSpace(img))
		if img == "" {
			return
		}
		if votes[img] == nil {
			votes[img] = map[string]float64{}
		}
		votes[img][tgt] += w
		if votes["__global__"] == nil {
			votes["__global__"] = map[string]float64{}
		}
		votes["__global__"][tgt] += w
	}
	consume := func(edges []callEdge) {
		for _, e := range edges {
			if e.Confidence < fallbackMinConf {
				continue
			}
			tgt := sanitizeName(nonEmpty(e.TargetName, "sub_"+strings.TrimPrefix(strings.ToLower(e.TargetAddr), "0x")))
			if tgt == "" || tgt == "unknown" || isGenericName(tgt) {
				continue
			}
			w := e.Confidence
			if e.Confidence < minConf {
				w *= 0.5
			}
			add(e.Image, tgt, w)
		}
	}
	for _, edges := range outAdj {
		consume(edges)
	}
	for _, edges := range inAdj {
		consume(edges)
	}
	out := map[string][]string{}
	for img, m := range votes {
		rows := make([]score, 0, len(m))
		for n, w := range m {
			rows = append(rows, score{name: n, w: w})
		}
		sort.Slice(rows, func(i, j int) bool { return rows[i].w > rows[j].w })
		if len(rows) == 0 {
			continue
		}
		limit := 4
		if len(rows) < limit {
			limit = len(rows)
		}
		list := make([]string, 0, limit)
		for i := 0; i < limit; i++ {
			list = append(list, rows[i].name)
		}
		out[img] = list
	}
	return out
}

func inferFromImageHints(task implTask, imageHints map[string][]string) []callEdge {
	if !isDispatcherLike(task.Function) {
		return nil
	}
	img := strings.ToLower(strings.TrimSpace(task.Image))
	ns := imageHints[img]
	if len(ns) == 0 {
		ns = imageHints["__global__"]
	}
	if len(ns) == 0 {
		return nil
	}
	self := sanitizeName(task.Function)
	out := make([]callEdge, 0, len(ns))
	for _, n := range ns {
		if n == "" || n == "unknown" || n == self {
			continue
		}
		out = append(out, callEdge{
			Image:      task.Image,
			SourceAddr: task.Address,
			SourceName: task.Function,
			TargetName: n,
			Confidence: 0.15,
		})
	}
	return out
}

func allowSyntheticInference(fn string, incoming, outgoing []callEdge) bool {
	if len(outgoing) > 0 {
		return true
	}
	if len(incoming) > 0 {
		return isDispatcherLike(fn)
	}
	return isDispatcherLike(fn)
}

func isDispatcherLike(fn string) bool {
	fn = sanitizeName(fn)
	if fn == "" || fn == "unknown" {
		return false
	}
	if strings.HasPrefix(fn, "sdio_") || strings.HasPrefix(fn, "ipc_") || strings.HasPrefix(fn, "queue_") || strings.HasPrefix(fn, "log_") {
		return true
	}
	tokens := nameTokens(fn)
	for _, t := range tokens {
		switch t {
		case "handler", "dispatch", "process", "update", "init", "check", "set", "get", "clear":
			return true
		}
	}
	return false
}

func isRelatedFunction(src, dst string) bool {
	src = sanitizeName(src)
	dst = sanitizeName(dst)
	if src == "" || dst == "" || src == "unknown" || dst == "unknown" || src == dst {
		return false
	}
	if familyKey(src) != "" && familyKey(src) == familyKey(dst) {
		return true
	}
	srcTokens := nameTokens(src)
	dstTokens := nameTokens(dst)
	if len(srcTokens) == 0 || len(dstTokens) == 0 {
		return false
	}
	dstSet := map[string]struct{}{}
	for _, t := range dstTokens {
		dstSet[t] = struct{}{}
	}
	for _, t := range srcTokens {
		if _, ok := dstSet[t]; ok {
			return true
		}
	}
	return false
}
