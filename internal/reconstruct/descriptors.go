package reconstruct

import (
	"bufio"
	"encoding/json"
	"fmt"
	"math"
	"os"
	"path/filepath"
	"sort"
	"strconv"
	"strings"
	"time"

	"aic8800d80/internal/fileio"
)

type BuildPaths struct {
	CFGHintsPath      string
	PseudoHintsPath   string
	OutcomesPath      string
	SynthEvidencePath string
	EmbedderCachePath string
	FunctionLinksPath string
	ConsensusPath     string
}

type DescriptorArtifacts struct {
	SchemaVersion string               `json:"schema_version"`
	GeneratedAt   string               `json:"generated_at"`
	Descriptors   []FunctionDescriptor `json:"descriptors"`
	MotifMemory   []MotifMemoryEntry   `json:"motif_memory"`
	Summary       DescriptorSummary    `json:"summary"`
}

type DescriptorSummary struct {
	DescriptorCount             int            `json:"descriptor_count"`
	ProbeBackedCount            int            `json:"probe_backed_count"`
	SynthBackedCount            int            `json:"synth_backed_count"`
	MotifBackedCount            int            `json:"motif_backed_count"`
	NeighborBackedCount         int            `json:"neighbor_backed_count,omitempty"`
	ConsensusBackedCount        int            `json:"consensus_backed_count,omitempty"`
	TransferBackedCount         int            `json:"transfer_backed_count,omitempty"`
	HighTransferConfidenceCount int            `json:"high_transfer_confidence_count,omitempty"`
	ClusterCount                int            `json:"cluster_count,omitempty"`
	PhenotypeCounts             map[string]int `json:"phenotype_counts,omitempty"`
	MotifFamilyCounts           map[string]int `json:"motif_family_counts,omitempty"`
	BehaviorRoleCount           map[string]int `json:"behavior_role_counts,omitempty"`
}

type FunctionDescriptor struct {
	SchemaVersion string          `json:"schema_version"`
	Key           string          `json:"key"`
	Name          string          `json:"name"`
	Image         string          `json:"image,omitempty"`
	Address       string          `json:"address,omitempty"`
	CFG           CFGFeatures     `json:"cfg"`
	Pseudo        PseudoFeatures  `json:"pseudo"`
	Probe         ProbeHistory    `json:"probe"`
	Synthesis     SynthesisState  `json:"synthesis"`
	Behavior      BehaviorHints   `json:"behavior"`
	Relations     RelationHints   `json:"relations"`
	Transfer      TransferHints   `json:"transfer"`
	Motif         MotifPrediction `json:"motif"`
	Priority      PriorityHints   `json:"priority"`
}

type CFGFeatures struct {
	BBCount        int      `json:"bb_count,omitempty"`
	EdgeCount      int      `json:"edge_count,omitempty"`
	InsnCount      int      `json:"insn_count,omitempty"`
	CallsiteCount  int      `json:"callsite_count,omitempty"`
	XrefsTo        int      `json:"xrefs_to,omitempty"`
	XrefsFrom      int      `json:"xrefs_from,omitempty"`
	FrameSize      int      `json:"frame_size,omitempty"`
	HasLoop        bool     `json:"has_loop,omitempty"`
	LoadCount      int      `json:"load_count,omitempty"`
	StoreCount     int      `json:"store_count,omitempty"`
	LoadWordCount  int      `json:"load_word_count,omitempty"`
	StoreWordCount int      `json:"store_word_count,omitempty"`
	TopImmediates  []uint32 `json:"top_immediates,omitempty"`
	MaxImmediate   uint32   `json:"max_immediate,omitempty"`
}

type PseudoFeatures struct {
	Available            bool     `json:"available"`
	LineCount            int      `json:"line_count,omitempty"`
	LoopCount            int      `json:"loop_count,omitempty"`
	SwitchCount          int      `json:"switch_count,omitempty"`
	IfCount              int      `json:"if_count,omitempty"`
	ReturnCount          int      `json:"return_count,omitempty"`
	CallCount            int      `json:"call_count,omitempty"`
	MMIOAddrCount        int      `json:"mmio_addr_count,omitempty"`
	PrimaryMMIO          string   `json:"primary_mmio,omitempty"`
	CallNames            []string `json:"call_names,omitempty"`
	HasIRQGuardTokens    bool     `json:"has_irq_guard_tokens,omitempty"`
	HasCallbackTokens    bool     `json:"has_callback_tokens,omitempty"`
	HasDualReturnGate    bool     `json:"has_dual_return_gate,omitempty"`
	HasStateTokens       bool     `json:"has_state_tokens,omitempty"`
	HasQueueTokens       bool     `json:"has_queue_tokens,omitempty"`
	HasDispatchTokens    bool     `json:"has_dispatch_tokens,omitempty"`
	HasTransferTokens    bool     `json:"has_transfer_tokens,omitempty"`
	HasRegisterWriteHint bool     `json:"has_register_write_hint,omitempty"`
}

type ProbeHistory struct {
	Attempts       int     `json:"attempts,omitempty"`
	Returned       int     `json:"returned,omitempty"`
	Capped         int     `json:"capped,omitempty"`
	Fault          int     `json:"fault,omitempty"`
	MissingSymbol  int     `json:"missing_symbol,omitempty"`
	ShallowReturn  int     `json:"shallow_return,omitempty"`
	EvidenceAvg    float64 `json:"evidence_avg,omitempty"`
	MMIOTouchAvg   float64 `json:"mmio_touch_avg,omitempty"`
	HelperTouchAvg float64 `json:"helper_touch_avg,omitempty"`
	MaxBranchDepth int     `json:"max_branch_depth,omitempty"`
	LastSeen       string  `json:"last_seen,omitempty"`
	Phenotype      string  `json:"phenotype,omitempty"`
}

type SynthesisState struct {
	Observed         bool     `json:"observed"`
	EvidenceScore    float64  `json:"evidence_score,omitempty"`
	EvidenceClass    string   `json:"evidence_class,omitempty"`
	ConservativeMode bool     `json:"conservative_mode,omitempty"`
	Source           string   `json:"source,omitempty"`
	TopOutgoing      []string `json:"top_outgoing,omitempty"`
	TopIncoming      []string `json:"top_incoming,omitempty"`
}

type BehaviorHints struct {
	Class      string             `json:"class,omitempty"`
	Role       string             `json:"role,omitempty"`
	Confidence float64            `json:"confidence,omitempty"`
	TopClasses map[string]float64 `json:"top_classes,omitempty"`
}

type RelationHints struct {
	LinkedFunctions   []string       `json:"linked_functions,omitempty"`
	ConsensusRoles    []string       `json:"consensus_roles,omitempty"`
	ConsensusOutgoing []string       `json:"consensus_outgoing,omitempty"`
	EmbedderNeighbors []NeighborHint `json:"embedder_neighbors,omitempty"`
}

type NeighborHint struct {
	Name       string  `json:"name"`
	Image      string  `json:"image,omitempty"`
	Address    string  `json:"address,omitempty"`
	Similarity float64 `json:"similarity"`
	Reason     string  `json:"reason,omitempty"`
}

type TransferHints struct {
	ClusterKey          string   `json:"cluster_key,omitempty"`
	ClusterSize         int      `json:"cluster_size,omitempty"`
	NeighborCount       int      `json:"neighbor_count,omitempty"`
	NeighborSupport     float64  `json:"neighbor_support,omitempty"`
	TransferConfidence  float64  `json:"transfer_confidence,omitempty"`
	PreferredEmitter    string   `json:"preferred_emitter,omitempty"`
	TopClusterOutgoing  []string `json:"top_cluster_outgoing,omitempty"`
	TopClusterRoles     []string `json:"top_cluster_roles,omitempty"`
	TopClusterPhenotype []string `json:"top_cluster_phenotypes,omitempty"`
	EvidenceSources     []string `json:"evidence_sources,omitempty"`
}

type MotifPrediction struct {
	Family     string             `json:"family,omitempty"`
	Confidence float64            `json:"confidence,omitempty"`
	Source     string             `json:"source,omitempty"`
	Scores     map[string]float64 `json:"scores,omitempty"`
	Reasons    []string           `json:"reasons,omitempty"`
}

type PriorityHints struct {
	RebuildUrgency float64  `json:"rebuild_urgency,omitempty"`
	Reasons        []string `json:"reasons,omitempty"`
}

type MotifMemoryEntry struct {
	SchemaVersion    string   `json:"schema_version"`
	Family           string   `json:"family"`
	SampleCount      int      `json:"sample_count"`
	ProbeAttempts    int      `json:"probe_attempts"`
	ReturnedCount    int      `json:"returned_count"`
	CappedCount      int      `json:"capped_count"`
	FaultCount       int      `json:"fault_count"`
	MissingCount     int      `json:"missing_count"`
	AvgConfidence    float64  `json:"avg_confidence"`
	AvgEvidence      float64  `json:"avg_evidence"`
	SuccessRate      float64  `json:"success_rate"`
	TopOutgoing      []string `json:"top_outgoing,omitempty"`
	TopIncoming      []string `json:"top_incoming,omitempty"`
	TopBehaviorRoles []string `json:"top_behavior_roles,omitempty"`
	TopPhenotypes    []string `json:"top_phenotypes,omitempty"`
	ExampleFunctions []string `json:"example_functions,omitempty"`
}

type DescriptorSet struct {
	Rows   []FunctionDescriptor
	byKey  map[string]*FunctionDescriptor
	byName map[string]*FunctionDescriptor
}

type MotifMemorySet struct {
	Rows  []MotifMemoryEntry
	byFam map[string]*MotifMemoryEntry
}

type exampleEntry struct {
	name       string
	confidence float64
}

type cfgRow struct {
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
	LoadWordCount  int      `json:"load_word_count"`
	StoreWordCount int      `json:"store_word_count"`
	TopImms        []uint32 `json:"top_imms"`
	MaxImm         uint32   `json:"max_imm"`
}

type pseudoRow struct {
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

type synthEvidenceRow struct {
	Function         string   `json:"function"`
	Image            string   `json:"image"`
	Address          string   `json:"address"`
	TopIncoming      []string `json:"top_incoming"`
	TopOutgoing      []string `json:"top_outgoing"`
	EvidenceScore    float64  `json:"evidence_score"`
	EvidenceClass    string   `json:"evidence_class"`
	ConservativeMode bool     `json:"conservative_mode"`
	SynthesisSource  string   `json:"synthesis_source"`
	BehaviorClass    string   `json:"behavior_class"`
	BehaviorRole     string   `json:"behavior_role"`
	MotifFamily      string   `json:"motif_family"`
	MotifConfidence  float64  `json:"motif_confidence"`
	Phenotype        string   `json:"descriptor_phenotype"`
}

type outcomeRow struct {
	Function         string `json:"function"`
	Image            string `json:"image"`
	Address          string `json:"address"`
	Status           string `json:"status"`
	Instructions     int    `json:"instructions"`
	MMIOReadCount    int    `json:"mmio_read_count"`
	MMIOWriteCount   int    `json:"mmio_write_count"`
	HelperTouchCount int    `json:"helper_touch_count"`
	BranchDepthMax   int    `json:"branch_depth_max"`
	GeneratedAt      string `json:"generated_at"`
}

type embedderCacheEntry struct {
	Emb            []float64 `json:"emb"`
	Classification struct {
		PrimaryClass string             `json:"primary_class"`
		SynthRole    string             `json:"synth_role"`
		Confidence   float64            `json:"confidence"`
		AllScores    map[string]float64 `json:"all_scores"`
	} `json:"classification"`
}

type functionLinkRow struct {
	SourceImage   string  `json:"source_image"`
	SourceAddress string  `json:"source_address"`
	SourceName    string  `json:"source_name"`
	TargetImage   string  `json:"target_image"`
	TargetAddress string  `json:"target_address"`
	Confidence    float64 `json:"confidence"`
}

type consensusRow struct {
	CanonicalFunction   string   `json:"canonical_function"`
	RoleHints           []string `json:"role_hints"`
	TopOutgoingCalls    []string `json:"top_outgoing_calls"`
	MessageFamilies     []string `json:"message_families"`
	MemberImages        []string `json:"member_images"`
	ConsensusConfidence float64  `json:"consensus_confidence"`
}

type embedderVectorRecord struct {
	Name       string
	Image      string
	Address    string
	Class      string
	Role       string
	Vector     []float64
	Descriptor *FunctionDescriptor
}

type transferClusterAcc struct {
	memberCount     int
	neighborCount   int
	neighborSupport float64
	outgoing        map[string]int
	roles           map[string]int
	phenotypes      map[string]int
	evidence        map[string]struct{}
}

func BuildArtifacts(paths BuildPaths) (*DescriptorArtifacts, error) {
	b := newDescriptorBuilder()
	if err := b.loadCFG(paths.CFGHintsPath); err != nil {
		return nil, err
	}
	if err := b.loadPseudo(paths.PseudoHintsPath); err != nil {
		return nil, err
	}
	if err := b.loadOutcomes(paths.OutcomesPath); err != nil {
		return nil, err
	}
	if err := b.loadSynthEvidence(paths.SynthEvidencePath); err != nil {
		return nil, err
	}
	if err := b.loadEmbedderCache(paths.EmbedderCachePath); err != nil {
		return nil, err
	}
	if err := b.loadFunctionLinks(paths.FunctionLinksPath); err != nil {
		return nil, err
	}
	if err := b.loadConsensus(paths.ConsensusPath); err != nil {
		return nil, err
	}
	return b.finalize(), nil
}

func LoadDescriptorSet(path string) (*DescriptorSet, error) {
	if strings.TrimSpace(path) == "" {
		return &DescriptorSet{byKey: map[string]*FunctionDescriptor{}, byName: map[string]*FunctionDescriptor{}}, nil
	}
	b, err := os.ReadFile(path)
	if err != nil {
		if os.IsNotExist(err) {
			return &DescriptorSet{byKey: map[string]*FunctionDescriptor{}, byName: map[string]*FunctionDescriptor{}}, nil
		}
		return nil, err
	}
	var rows []FunctionDescriptor
	if err := json.Unmarshal(b, &rows); err != nil {
		var art DescriptorArtifacts
		if err2 := json.Unmarshal(b, &art); err2 != nil {
			return nil, err
		}
		rows = art.Descriptors
	}
	set := &DescriptorSet{Rows: rows, byKey: map[string]*FunctionDescriptor{}, byName: map[string]*FunctionDescriptor{}}
	for i := range rows {
		row := &rows[i]
		if row.Key != "" {
			set.byKey[row.Key] = row
		}
		if nk := nameKey(row.Name); nk != "" {
			if _, ok := set.byName[nk]; !ok {
				set.byName[nk] = row
			}
		}
	}
	set.Rows = rows
	return set, nil
}

func (s *DescriptorSet) Lookup(name, image, address string) *FunctionDescriptor {
	if s == nil {
		return nil
	}
	if row, ok := s.byKey[identityKey(name, image, address)]; ok {
		return row
	}
	return s.byName[nameKey(name)]
}

func LoadMotifMemorySet(path string) (*MotifMemorySet, error) {
	if strings.TrimSpace(path) == "" {
		return &MotifMemorySet{byFam: map[string]*MotifMemoryEntry{}}, nil
	}
	b, err := os.ReadFile(path)
	if err != nil {
		if os.IsNotExist(err) {
			return &MotifMemorySet{byFam: map[string]*MotifMemoryEntry{}}, nil
		}
		return nil, err
	}
	var rows []MotifMemoryEntry
	if err := json.Unmarshal(b, &rows); err != nil {
		var art DescriptorArtifacts
		if err2 := json.Unmarshal(b, &art); err2 != nil {
			return nil, err
		}
		rows = art.MotifMemory
	}
	set := &MotifMemorySet{Rows: rows, byFam: map[string]*MotifMemoryEntry{}}
	for i := range rows {
		row := &rows[i]
		if row.Family != "" {
			set.byFam[row.Family] = row
		}
	}
	set.Rows = rows
	return set, nil
}

func (m *MotifMemorySet) Lookup(family string) *MotifMemoryEntry {
	if m == nil {
		return nil
	}
	return m.byFam[strings.TrimSpace(strings.ToLower(family))]
}

type descriptorBuilder struct {
	rows    map[string]*FunctionDescriptor
	byName  map[string]*FunctionDescriptor
	vectors []embedderVectorRecord
}

func newDescriptorBuilder() *descriptorBuilder {
	return &descriptorBuilder{rows: map[string]*FunctionDescriptor{}, byName: map[string]*FunctionDescriptor{}}
}

func (b *descriptorBuilder) ensure(name, image, address string) *FunctionDescriptor {
	key := identityKey(name, image, address)
	if key == "" {
		return nil
	}
	if row, ok := b.rows[key]; ok {
		return row
	}
	row := &FunctionDescriptor{
		SchemaVersion: "0.1.0",
		Key:           key,
		Name:          sanitize(name),
		Image:         strings.TrimSpace(image),
		Address:       normalizeAddr(address),
		Motif: MotifPrediction{
			Scores: map[string]float64{},
		},
		Priority: PriorityHints{Reasons: []string{}},
	}
	b.rows[key] = row
	if nk := nameKey(name); nk != "" {
		if _, ok := b.byName[nk]; !ok {
			b.byName[nk] = row
		}
	}
	return row
}

func (b *descriptorBuilder) ensureLoose(name, image, address string) *FunctionDescriptor {
	if row := b.ensure(name, image, address); row != nil {
		return row
	}
	return b.byName[nameKey(name)]
}

func (b *descriptorBuilder) loadCFG(path string) error {
	if strings.TrimSpace(path) == "" {
		return nil
	}
	rows, err := fileio.ReadJSONL[cfgRow](path)
	if err != nil {
		if os.IsNotExist(err) {
			return nil
		}
		return fmt.Errorf("read cfg hints: %w", err)
	}
	for _, src := range rows {
		row := b.ensureLoose(src.Name, src.Image, src.Address)
		if row == nil {
			continue
		}
		row.CFG = CFGFeatures{
			BBCount:        src.BBCount,
			EdgeCount:      src.EdgeCount,
			InsnCount:      src.InsnCount,
			CallsiteCount:  src.CallsiteCount,
			XrefsTo:        src.XrefsTo,
			XrefsFrom:      src.XrefsFrom,
			FrameSize:      src.FrameSize,
			HasLoop:        src.HasLoop,
			LoadCount:      src.LoadCount,
			StoreCount:     src.StoreCount,
			LoadWordCount:  src.LoadWordCount,
			StoreWordCount: src.StoreWordCount,
			TopImmediates:  src.TopImms,
			MaxImmediate:   src.MaxImm,
		}
	}
	return nil
}

func (b *descriptorBuilder) loadPseudo(path string) error {
	if strings.TrimSpace(path) == "" {
		return nil
	}
	rows, err := fileio.ReadJSONL[pseudoRow](path)
	if err != nil {
		if os.IsNotExist(err) {
			return nil
		}
		return fmt.Errorf("read pseudo hints: %w", err)
	}
	for _, src := range rows {
		row := b.ensureLoose(src.Name, src.Image, src.Address)
		if row == nil {
			continue
		}
		text := strings.ToLower(src.Pseudocode)
		row.Pseudo = PseudoFeatures{
			Available:            src.LineCount > 0 || src.LoopCount > 0 || src.SwitchCount > 0 || len(src.CallNames) > 0,
			LineCount:            src.LineCount,
			LoopCount:            src.LoopCount,
			SwitchCount:          src.SwitchCount,
			IfCount:              src.IfCount,
			ReturnCount:          src.ReturnCount,
			CallCount:            len(src.CallNames),
			MMIOAddrCount:        len(src.MMIOAddrs),
			PrimaryMMIO:          firstString(src.MMIOAddrs),
			CallNames:            uniqueStrings(src.CallNames),
			HasIRQGuardTokens:    strings.Contains(text, "disable_irq") && strings.Contains(text, "enable_irq"),
			HasCallbackTokens:    strings.Contains(text, "callback") || strings.Contains(text, "cb") || containsAny(src.CallNames, "callback", "cb"),
			HasDualReturnGate:    strings.Contains(text, "return 1;") && strings.Contains(text, "return 0;"),
			HasStateTokens:       strings.Contains(text, "state") || strings.Contains(text, "phase") || strings.Contains(text, "status"),
			HasQueueTokens:       strings.Contains(text, "queue") || strings.Contains(text, "ring") || strings.Contains(text, "pool"),
			HasDispatchTokens:    strings.Contains(text, "dispatch") || strings.Contains(text, "handler") || src.SwitchCount > 0,
			HasTransferTokens:    strings.Contains(text, "transfer") || strings.Contains(text, "dma") || strings.Contains(text, "copy"),
			HasRegisterWriteHint: strings.Contains(text, "write") || strings.Contains(text, "reg") || strings.Contains(text, "commit"),
		}
	}
	return nil
}

func (b *descriptorBuilder) loadOutcomes(path string) error {
	if strings.TrimSpace(path) == "" {
		return nil
	}
	f, err := os.Open(path)
	if err != nil {
		if os.IsNotExist(err) {
			return nil
		}
		return fmt.Errorf("open outcomes: %w", err)
	}
	defer f.Close()
	s := bufio.NewScanner(f)
	s.Buffer(make([]byte, 1024), 4*1024*1024)
	for s.Scan() {
		line := strings.TrimSpace(s.Text())
		if line == "" {
			continue
		}
		var src outcomeRow
		if err := json.Unmarshal([]byte(line), &src); err != nil {
			return fmt.Errorf("parse outcomes: %w", err)
		}
		row := b.ensureLoose(src.Function, src.Image, src.Address)
		if row == nil {
			continue
		}
		row.Probe.Attempts++
		status := strings.ToLower(strings.TrimSpace(src.Status))
		switch status {
		case "success":
			status = "returned"
		}
		switch status {
		case "returned":
			row.Probe.Returned++
			if src.Instructions >= 0 && src.Instructions < 8 {
				row.Probe.ShallowReturn++
			}
		case "capped":
			row.Probe.Capped++
		case "fault":
			row.Probe.Fault++
		case "missing_symbol":
			row.Probe.MissingSymbol++
		}
		mmio := src.MMIOReadCount + src.MMIOWriteCount
		row.Probe.MMIOTouchAvg += float64(mmio)
		row.Probe.HelperTouchAvg += float64(maxInt(src.HelperTouchCount, 0))
		if src.BranchDepthMax > row.Probe.MaxBranchDepth {
			row.Probe.MaxBranchDepth = src.BranchDepthMax
		}
		evidence := minInt(mmio, 16) + minInt(src.HelperTouchCount, 8)*2 + minInt(src.BranchDepthMax, 6)*2
		if status == "returned" {
			evidence += 6
		} else if status == "capped" {
			evidence += 2
		}
		row.Probe.EvidenceAvg += float64(evidence)
		if src.GeneratedAt != "" && src.GeneratedAt > row.Probe.LastSeen {
			row.Probe.LastSeen = src.GeneratedAt
		}
	}
	if err := s.Err(); err != nil {
		return fmt.Errorf("scan outcomes: %w", err)
	}
	return nil
}

func (b *descriptorBuilder) loadSynthEvidence(path string) error {
	if strings.TrimSpace(path) == "" {
		return nil
	}
	bts, err := os.ReadFile(path)
	if err != nil {
		if os.IsNotExist(err) {
			return nil
		}
		return fmt.Errorf("read synth evidence: %w", err)
	}
	var rows []synthEvidenceRow
	if err := json.Unmarshal(bts, &rows); err != nil {
		return fmt.Errorf("parse synth evidence: %w", err)
	}
	for _, src := range rows {
		row := b.ensureLoose(src.Function, src.Image, src.Address)
		if row == nil {
			continue
		}
		row.Synthesis = SynthesisState{
			Observed:         true,
			EvidenceScore:    src.EvidenceScore,
			EvidenceClass:    strings.TrimSpace(src.EvidenceClass),
			ConservativeMode: src.ConservativeMode,
			Source:           strings.TrimSpace(src.SynthesisSource),
			TopOutgoing:      uniqueStrings(src.TopOutgoing),
			TopIncoming:      uniqueStrings(src.TopIncoming),
		}
		if row.Behavior.Class == "" && src.BehaviorClass != "" {
			row.Behavior.Class = strings.TrimSpace(src.BehaviorClass)
		}
		if row.Behavior.Role == "" && src.BehaviorRole != "" {
			row.Behavior.Role = strings.TrimSpace(src.BehaviorRole)
		}
	}
	return nil
}

func (b *descriptorBuilder) loadEmbedderCache(path string) error {
	if strings.TrimSpace(path) == "" {
		return nil
	}
	bts, err := os.ReadFile(path)
	if err != nil {
		if os.IsNotExist(err) {
			return nil
		}
		return fmt.Errorf("read embedder cache: %w", err)
	}
	var raw map[string]embedderCacheEntry
	if err := json.Unmarshal(bts, &raw); err != nil {
		return nil
	}
	for key, entry := range raw {
		parts := strings.Split(key, "|")
		name := ""
		image := ""
		addr := ""
		if len(parts) >= 3 {
			image = parts[0]
			addr = parts[1]
			name = parts[len(parts)-1]
		} else if len(parts) == 2 {
			name = parts[1]
		} else {
			name = key
		}
		row := b.ensureLoose(name, image, addr)
		if row == nil {
			continue
		}
		if row.Behavior.Class == "" {
			row.Behavior.Class = strings.TrimSpace(entry.Classification.PrimaryClass)
		}
		if row.Behavior.Role == "" {
			row.Behavior.Role = strings.TrimSpace(entry.Classification.SynthRole)
		}
		if row.Behavior.Confidence == 0 {
			row.Behavior.Confidence = entry.Classification.Confidence
		}
		if len(entry.Classification.AllScores) > 0 && len(row.Behavior.TopClasses) == 0 {
			row.Behavior.TopClasses = topScoreMap(entry.Classification.AllScores, 5)
		}
		if len(entry.Emb) > 0 {
			b.vectors = append(b.vectors, embedderVectorRecord{
				Name:       row.Name,
				Image:      row.Image,
				Address:    row.Address,
				Class:      row.Behavior.Class,
				Role:       row.Behavior.Role,
				Vector:     entry.Emb,
				Descriptor: row,
			})
		}
	}
	return nil
}

func (b *descriptorBuilder) loadFunctionLinks(path string) error {
	path = resolveAnalysisPath(path, "function_links.jsonl")
	if strings.TrimSpace(path) == "" {
		return nil
	}
	rows, err := fileio.ReadJSONL[functionLinkRow](path)
	if err != nil {
		if os.IsNotExist(err) {
			return nil
		}
		return fmt.Errorf("read function links: %w", err)
	}
	for _, src := range rows {
		row := b.ensureLoose(src.SourceName, src.SourceImage, src.SourceAddress)
		if row == nil {
			continue
		}
		tgt := b.lookupNameByImageAddr(src.TargetImage, src.TargetAddress)
		if tgt == "" || tgt == row.Name {
			continue
		}
		row.Relations.LinkedFunctions = uniqueStrings(append(row.Relations.LinkedFunctions, tgt))
	}
	return nil
}

func (b *descriptorBuilder) lookupNameByImageAddr(image, address string) string {
	image = strings.TrimSpace(strings.ToLower(image))
	address = normalizeAddr(address)
	for _, row := range b.rows {
		if strings.TrimSpace(strings.ToLower(row.Image)) == image && normalizeAddr(row.Address) == address {
			return row.Name
		}
	}
	return ""
}

func (b *descriptorBuilder) loadConsensus(path string) error {
	path = resolveAnalysisPath(path, "consensus_behavior.jsonl")
	if strings.TrimSpace(path) == "" {
		return nil
	}
	rows, err := fileio.ReadJSONL[consensusRow](path)
	if err != nil {
		if os.IsNotExist(err) {
			return nil
		}
		return fmt.Errorf("read consensus behavior: %w", err)
	}
	for _, src := range rows {
		row := b.ensureLoose(src.CanonicalFunction, "", "")
		if row == nil {
			continue
		}
		row.Relations.ConsensusRoles = uniqueStrings(append(row.Relations.ConsensusRoles, src.RoleHints...))
		row.Relations.ConsensusOutgoing = uniqueStrings(append(row.Relations.ConsensusOutgoing, src.TopOutgoingCalls...))
		if row.Behavior.Role == "" && len(src.RoleHints) > 0 {
			row.Behavior.Role = strings.TrimSpace(src.RoleHints[0])
		}
	}
	return nil
}

func (b *descriptorBuilder) finalize() *DescriptorArtifacts {
	rows := make([]FunctionDescriptor, 0, len(b.rows))
	summary := DescriptorSummary{
		PhenotypeCounts:   map[string]int{},
		MotifFamilyCounts: map[string]int{},
		BehaviorRoleCount: map[string]int{},
	}
	for _, row := range b.rows {
		finalizeProbe(&row.Probe)
		row.Motif = predictMotif(*row)
		row.Relations.EmbedderNeighbors = b.computeEmbedderNeighbors(row)
	}
	summary.ClusterCount = b.computeTransferHints()
	for _, row := range b.rows {
		row.Priority = computePriority(*row)
		rows = append(rows, *row)
		summary.DescriptorCount++
		if row.Probe.Attempts > 0 {
			summary.ProbeBackedCount++
		}
		if row.Synthesis.Observed {
			summary.SynthBackedCount++
		}
		if len(row.Relations.EmbedderNeighbors) > 0 {
			summary.NeighborBackedCount++
		}
		if len(row.Relations.ConsensusRoles) > 0 || len(row.Relations.ConsensusOutgoing) > 0 {
			summary.ConsensusBackedCount++
		}
		if row.Transfer.TransferConfidence > 0 {
			summary.TransferBackedCount++
		}
		if row.Transfer.TransferConfidence >= 0.7 {
			summary.HighTransferConfidenceCount++
		}
		if row.Motif.Family != "" {
			summary.MotifBackedCount++
			summary.MotifFamilyCounts[row.Motif.Family]++
		}
		if row.Probe.Phenotype != "" {
			summary.PhenotypeCounts[row.Probe.Phenotype]++
		}
		if row.Behavior.Role != "" {
			summary.BehaviorRoleCount[row.Behavior.Role]++
		}
	}
	sort.Slice(rows, func(i, j int) bool {
		if rows[i].Priority.RebuildUrgency == rows[j].Priority.RebuildUrgency {
			if rows[i].Image == rows[j].Image {
				return rows[i].Name < rows[j].Name
			}
			return rows[i].Image < rows[j].Image
		}
		return rows[i].Priority.RebuildUrgency > rows[j].Priority.RebuildUrgency
	})
	memory := buildMotifMemory(rows)
	return &DescriptorArtifacts{
		SchemaVersion: "0.1.0",
		GeneratedAt:   nowUTC(),
		Descriptors:   rows,
		MotifMemory:   memory,
		Summary:       summary,
	}
}

func (b *descriptorBuilder) computeTransferHints() int {
	clusters := map[string]*transferClusterAcc{}
	for _, row := range b.rows {
		key := descriptorClusterKey(row)
		if key == "" {
			continue
		}
		acc := clusters[key]
		if acc == nil {
			acc = &transferClusterAcc{
				outgoing:   map[string]int{},
				roles:      map[string]int{},
				phenotypes: map[string]int{},
				evidence:   map[string]struct{}{},
			}
			clusters[key] = acc
		}
		acc.memberCount++
		acc.neighborCount += len(row.Relations.EmbedderNeighbors)
		for _, n := range row.Relations.EmbedderNeighbors {
			acc.neighborSupport += maxFloat(0.0, n.Similarity)
		}
		for _, name := range row.Synthesis.TopOutgoing {
			acc.outgoing[sanitize(name)]++
		}
		for _, name := range row.Relations.ConsensusOutgoing {
			acc.outgoing[sanitize(name)] += 2
		}
		if row.Behavior.Role != "" {
			acc.roles[row.Behavior.Role] += 2
		}
		for _, role := range row.Relations.ConsensusRoles {
			acc.roles[role]++
		}
		if row.Probe.Phenotype != "" {
			acc.phenotypes[row.Probe.Phenotype]++
		}
		if len(row.Relations.EmbedderNeighbors) > 0 {
			acc.evidence["embedder_neighbors"] = struct{}{}
		}
		if len(row.Relations.ConsensusOutgoing) > 0 || len(row.Relations.ConsensusRoles) > 0 {
			acc.evidence["consensus"] = struct{}{}
		}
		if row.Synthesis.Observed {
			acc.evidence["synth_evidence"] = struct{}{}
		}
		if row.Pseudo.Available {
			acc.evidence["pseudocode"] = struct{}{}
		}
	}
	for _, row := range b.rows {
		key := descriptorClusterKey(row)
		if key == "" {
			continue
		}
		acc := clusters[key]
		if acc == nil {
			continue
		}
		avgSupport := 0.0
		if acc.neighborCount > 0 {
			avgSupport = acc.neighborSupport / float64(acc.neighborCount)
		}
		confidence := row.Motif.Confidence * 0.35
		confidence += minFloat(float64(acc.memberCount)*0.08, 0.24)
		confidence += minFloat(avgSupport*0.32, 0.32)
		confidence += minFloat(float64(len(acc.evidence))*0.08, 0.24)
		if row.Synthesis.Observed {
			confidence += 0.1
		}
		if row.Behavior.Confidence > 0 {
			confidence += minFloat(row.Behavior.Confidence*0.18, 0.18)
		}
		row.Transfer = TransferHints{
			ClusterKey:          key,
			ClusterSize:         acc.memberCount,
			NeighborCount:       len(row.Relations.EmbedderNeighbors),
			NeighborSupport:     roundFloat(avgSupport),
			TransferConfidence:  roundFloat(minFloat(confidence, 0.98)),
			TopClusterOutgoing:  topCountKeys(acc.outgoing, 6),
			TopClusterRoles:     topCountKeys(acc.roles, 4),
			TopClusterPhenotype: topCountKeys(acc.phenotypes, 4),
			EvidenceSources:     sortedSetKeys(acc.evidence),
		}
		row.Transfer.PreferredEmitter = preferredEmitterFor(*row)
	}
	return len(clusters)
}

func (b *descriptorBuilder) computeEmbedderNeighbors(row *FunctionDescriptor) []NeighborHint {
	if row == nil || len(b.vectors) == 0 {
		return nil
	}
	var self *embedderVectorRecord
	for i := range b.vectors {
		cand := &b.vectors[i]
		if cand.Descriptor == row {
			self = cand
			break
		}
	}
	if self == nil || len(self.Vector) == 0 {
		return nil
	}
	type candidate struct {
		NeighborHint
	}
	cands := make([]candidate, 0, 16)
	for i := range b.vectors {
		cand := &b.vectors[i]
		if cand.Descriptor == row || len(cand.Vector) == 0 {
			continue
		}
		reason := ""
		if row.Behavior.Class != "" && cand.Class == row.Behavior.Class {
			reason = "same_behavior_class"
		} else if row.Behavior.Role != "" && cand.Role == row.Behavior.Role {
			reason = "same_behavior_role"
		} else if row.Motif.Family != "" && cand.Descriptor != nil && cand.Descriptor.Motif.Family == row.Motif.Family {
			reason = "same_motif_family"
		} else if familyStem(row.Name) != "" && familyStem(cand.Name) == familyStem(row.Name) {
			reason = "same_name_family"
		} else {
			continue
		}
		sim := cosine(self.Vector, cand.Vector)
		if sim < 0.60 {
			continue
		}
		cands = append(cands, candidate{NeighborHint: NeighborHint{Name: cand.Name, Image: cand.Image, Address: cand.Address, Similarity: roundFloat(sim), Reason: reason}})
	}
	sort.Slice(cands, func(i, j int) bool {
		if cands[i].Similarity == cands[j].Similarity {
			return cands[i].Name < cands[j].Name
		}
		return cands[i].Similarity > cands[j].Similarity
	})
	limit := 4
	if len(cands) < limit {
		limit = len(cands)
	}
	out := make([]NeighborHint, 0, limit)
	seen := map[string]struct{}{}
	for _, cand := range cands {
		if _, ok := seen[cand.Name]; ok {
			continue
		}
		seen[cand.Name] = struct{}{}
		out = append(out, cand.NeighborHint)
		if len(out) >= limit {
			break
		}
	}
	return out
}

func finalizeProbe(p *ProbeHistory) {
	if p.Attempts <= 0 {
		return
	}
	den := float64(p.Attempts)
	p.EvidenceAvg /= den
	p.MMIOTouchAvg /= den
	p.HelperTouchAvg /= den
	p.Phenotype = classifyPhenotype(*p)
}

func classifyPhenotype(p ProbeHistory) string {
	if p.Attempts == 0 {
		return "unprobed"
	}
	missingRate := float64(p.MissingSymbol) / float64(p.Attempts)
	capRate := float64(p.Capped) / float64(p.Attempts)
	faultRate := float64(p.Fault) / float64(p.Attempts)
	shallowRate := float64(p.ShallowReturn) / float64(p.Attempts)
	returnRate := float64(p.Returned) / float64(p.Attempts)
	if missingRate >= 0.5 {
		return "missing_symbols"
	}
	if capRate >= 0.45 && p.MMIOTouchAvg >= 2.0 {
		return "capped_mmio_wait"
	}
	if capRate >= 0.45 {
		return "capped_low_mmio"
	}
	if faultRate >= 0.35 {
		return "fault_prone"
	}
	if shallowRate >= 0.5 {
		return "shallow_wrapper"
	}
	if returnRate >= 0.6 && p.EvidenceAvg >= 6.0 && shallowRate < 0.35 {
		return "stable_nontrivial"
	}
	return "mixed"
}

func predictMotif(row FunctionDescriptor) MotifPrediction {
	scores := map[string]float64{}
	reasons := map[string][]string{}
	add := func(family string, score float64, reason string) {
		if score <= 0 {
			return
		}
		scores[family] += score
		if reason != "" {
			reasons[family] = append(reasons[family], reason)
		}
	}
	name := strings.ToLower(row.Name)
	role := strings.ToLower(strings.TrimSpace(row.Behavior.Role))
	cls := strings.ToLower(strings.TrimSpace(row.Behavior.Class))
	p := row.Pseudo
	cfg := row.CFG
	probe := row.Probe
	if p.HasIRQGuardTokens && (cfg.HasLoop || probe.Capped > 0) {
		add("irq_wait_guard", 0.92, "Hex-Rays IRQ disable/enable guard tokens with loop/wait evidence")
	}
	if p.HasCallbackTokens && p.HasDualReturnGate && cfg.CallsiteCount >= 1 {
		add("callback_state_gate", 0.88, "callback tokens plus dual-return gate in pseudocode")
	}
	if p.MMIOAddrCount > 0 && cfg.HasLoop && cfg.LoadCount+cfg.StoreCount >= 6 {
		add("staged_mmio_transfer", 0.78, "MMIO plus loop-heavy read/write profile")
	}
	if strings.Contains(role, "dispatcher") || strings.Contains(cls, "message") || p.HasDispatchTokens && (p.SwitchCount > 0 || cfg.CallsiteCount >= 4) {
		add("dispatcher", 0.76, "dispatch tokens with switch/call fanout")
	}
	if strings.Contains(role, "memory_pool") || p.HasQueueTokens || containsAnyString(name, "queue", "pool", "ring", "list") {
		add("queue_pump", 0.72, "queue/pool/ring evidence in name or pseudocode")
	}
	if strings.Contains(role, "radio_reg_write") || containsAnyString(name, "rf_", "reg_", "write", "commit") || (p.HasRegisterWriteHint && cfg.StoreCount > 0 && p.MMIOAddrCount > 0) {
		add("register_commit", 0.74, "register-write profile with MMIO stores")
	}
	if strings.Contains(role, "state_machine") || (p.SwitchCount > 0 && cfg.HasLoop) || containsAnyString(name, "fsm", "state", "step") {
		add("state_machine", 0.71, "switch/loop state progression evidence")
	}
	if probe.Phenotype == "capped_mmio_wait" {
		add("bounded_poll", 0.68, "cap-dominant MMIO wait phenotype")
		add("staged_mmio_transfer", 0.12, "MMIO wait phenotype reinforces transfer motif")
	}
	if probe.Phenotype == "shallow_wrapper" && (strings.Contains(role, "dispatcher") || p.HasDispatchTokens || p.HasQueueTokens) {
		add("dispatcher", 0.2, "shallow wrapper around dispatch-like body")
		add("queue_pump", 0.16, "wrapper phenotype with queue-like tokens")
	}
	if len(row.Relations.ConsensusOutgoing) > 0 && len(row.Relations.ConsensusRoles) > 0 {
		if containsAnyString(strings.Join(row.Relations.ConsensusRoles, " "), "message", "dispatch", "handler") {
			add("dispatcher", 0.22, "pipeline consensus roles indicate dispatch behavior")
		}
		if containsAnyString(strings.Join(row.Relations.ConsensusRoles, " "), "transport", "dma", "io") {
			add("staged_mmio_transfer", 0.18, "pipeline consensus roles indicate transport or DMA behavior")
		}
	}
	if len(row.Relations.LinkedFunctions) >= 2 && strings.Contains(role, "state") {
		add("state_machine", 0.16, "cross-image function links reinforce stateful cluster")
	}
	bestFamily := ""
	bestScore := 0.0
	for fam, score := range scores {
		if score > bestScore {
			bestFamily = fam
			bestScore = score
		}
	}
	if bestScore < 0.55 {
		bestFamily = ""
	}
	out := MotifPrediction{Scores: roundScores(scores)}
	if bestFamily == "" {
		return out
	}
	out.Family = bestFamily
	out.Confidence = minFloat(bestScore, 0.98)
	out.Source = "descriptor_classifier"
	out.Reasons = uniqueStrings(reasons[bestFamily])
	return out
}

func computePriority(row FunctionDescriptor) PriorityHints {
	urgency := 0.0
	reasons := make([]string, 0, 8)
	probe := row.Probe
	if probe.Attempts == 0 {
		urgency += 1.0
		reasons = append(reasons, "unprobed descriptor still has CFG/pseudocode evidence")
	}
	switch probe.Phenotype {
	case "capped_mmio_wait":
		urgency += 4.5
		reasons = append(reasons, "cap-heavy MMIO wait phenotype")
	case "capped_low_mmio":
		urgency += 3.6
		reasons = append(reasons, "cap-heavy low-MMIO phenotype")
	case "fault_prone":
		urgency += 2.8
		reasons = append(reasons, "fault-prone probe phenotype")
	case "shallow_wrapper":
		urgency += 2.7
		reasons = append(reasons, "wrapper phenotype likely hiding missing semantics")
	case "missing_symbols":
		urgency += 0.6
		reasons = append(reasons, "missing-symbol phenotype is less actionable than a bounded-body failure")
	case "stable_nontrivial":
		urgency -= 1.4
		reasons = append(reasons, "stable nontrivial returns reduce rebuild urgency")
	}
	if row.Motif.Family != "" {
		urgency += row.Motif.Confidence * 2.2
		reasons = append(reasons, fmt.Sprintf("motif %s inferred at %.2f confidence", row.Motif.Family, row.Motif.Confidence))
	}
	if row.Synthesis.ConservativeMode {
		urgency += 0.9
		reasons = append(reasons, "current synth evidence is conservative")
	}
	if row.CFG.HasLoop {
		urgency += 0.5
	}
	urgency += minFloat(float64(row.CFG.CallsiteCount)*0.12, 1.2)
	urgency += minFloat(float64(row.CFG.XrefsTo)*0.05, 0.8)
	if row.Pseudo.Available {
		urgency += 0.5
	}
	if len(row.Relations.EmbedderNeighbors) > 0 {
		urgency += minFloat(float64(len(row.Relations.EmbedderNeighbors))*0.25, 1.0)
		reasons = append(reasons, fmt.Sprintf("embedder neighbors available (%d)", len(row.Relations.EmbedderNeighbors)))
	}
	if len(row.Relations.ConsensusOutgoing) > 0 {
		urgency += minFloat(float64(len(row.Relations.ConsensusOutgoing))*0.08, 0.6)
		reasons = append(reasons, "consensus outgoing calls available")
	}
	if row.Transfer.TransferConfidence > 0 {
		urgency += row.Transfer.TransferConfidence * 1.7
		reasons = append(reasons, fmt.Sprintf("transfer confidence %.2f via %s", row.Transfer.TransferConfidence, nonEmpty(row.Transfer.PreferredEmitter, "cluster hints")))
	}
	if row.Transfer.ClusterSize >= 3 {
		urgency += minFloat(float64(row.Transfer.ClusterSize)*0.15, 0.9)
		reasons = append(reasons, fmt.Sprintf("descriptor cluster size %d", row.Transfer.ClusterSize))
	}
	if urgency < 0 {
		urgency = 0
	}
	return PriorityHints{RebuildUrgency: roundFloat(urgency), Reasons: uniqueStrings(reasons)}
}

func descriptorClusterKey(row *FunctionDescriptor) string {
	if row == nil {
		return ""
	}
	parts := make([]string, 0, 4)
	if fam := sanitize(row.Motif.Family); fam != "" {
		parts = append(parts, "motif="+fam)
	}
	if role := sanitize(row.Behavior.Role); role != "" {
		parts = append(parts, "role="+role)
	}
	if phen := sanitize(row.Probe.Phenotype); phen != "" && phen != "unprobed" {
		parts = append(parts, "phen="+phen)
	}
	if stem := familyStem(row.Name); stem != "" {
		parts = append(parts, "stem="+stem)
	}
	if len(parts) < 2 {
		return ""
	}
	return strings.Join(parts, "|")
}

func preferredEmitterFor(row FunctionDescriptor) string {
	if row.Motif.Family != "" && row.Motif.Confidence >= 0.62 && row.Transfer.TransferConfidence >= 0.55 {
		return "descriptor_motif"
	}
	if row.Pseudo.Available && row.Pseudo.LineCount >= 8 && (row.Pseudo.CallCount > 0 || row.Pseudo.LoopCount > 0 || row.Pseudo.SwitchCount > 0) {
		return "pseudocode_structured"
	}
	if row.Behavior.Role != "" && (row.Behavior.Confidence >= 0.55 || len(row.Relations.ConsensusRoles) > 0) {
		return "behavioral_class"
	}
	if row.Transfer.TransferConfidence >= 0.5 && len(row.Transfer.TopClusterOutgoing) > 0 {
		return "cluster_transfer"
	}
	return "generic"
}

func buildMotifMemory(rows []FunctionDescriptor) []MotifMemoryEntry {
	type acc struct {
		sampleCount   int
		probeAttempts int
		returned      int
		capped        int
		fault         int
		missing       int
		confTotal     float64
		evidenceTotal float64
		outgoing      map[string]int
		incoming      map[string]int
		roles         map[string]int
		phenotypes    map[string]int
		examples      []exampleEntry
	}
	byFamily := map[string]*acc{}
	for _, row := range rows {
		fam := strings.TrimSpace(strings.ToLower(row.Motif.Family))
		if fam == "" {
			continue
		}
		a := byFamily[fam]
		if a == nil {
			a = &acc{outgoing: map[string]int{}, incoming: map[string]int{}, roles: map[string]int{}, phenotypes: map[string]int{}}
			byFamily[fam] = a
		}
		a.sampleCount++
		a.probeAttempts += row.Probe.Attempts
		a.returned += row.Probe.Returned
		a.capped += row.Probe.Capped
		a.fault += row.Probe.Fault
		a.missing += row.Probe.MissingSymbol
		a.confTotal += row.Motif.Confidence
		a.evidenceTotal += row.Synthesis.EvidenceScore
		for _, name := range row.Synthesis.TopOutgoing {
			a.outgoing[sanitize(name)]++
		}
		for _, name := range row.Synthesis.TopIncoming {
			a.incoming[sanitize(name)]++
		}
		if row.Behavior.Role != "" {
			a.roles[row.Behavior.Role]++
		}
		if row.Probe.Phenotype != "" {
			a.phenotypes[row.Probe.Phenotype]++
		}
		a.examples = append(a.examples, exampleEntry{name: row.Name, confidence: row.Motif.Confidence})
	}
	out := make([]MotifMemoryEntry, 0, len(byFamily))
	for fam, a := range byFamily {
		entry := MotifMemoryEntry{
			SchemaVersion:    "0.1.0",
			Family:           fam,
			SampleCount:      a.sampleCount,
			ProbeAttempts:    a.probeAttempts,
			ReturnedCount:    a.returned,
			CappedCount:      a.capped,
			FaultCount:       a.fault,
			MissingCount:     a.missing,
			AvgConfidence:    roundFloat(a.confTotal / float64(maxInt(1, a.sampleCount))),
			AvgEvidence:      roundFloat(a.evidenceTotal / float64(maxInt(1, a.sampleCount))),
			SuccessRate:      roundFloat(100.0 * float64(a.returned) / float64(maxInt(1, a.probeAttempts))),
			TopOutgoing:      topCountKeys(a.outgoing, 6),
			TopIncoming:      topCountKeys(a.incoming, 6),
			TopBehaviorRoles: topCountKeys(a.roles, 4),
			TopPhenotypes:    topCountKeys(a.phenotypes, 4),
			ExampleFunctions: topExamples(a.examples, 6),
		}
		out = append(out, entry)
	}
	sort.Slice(out, func(i, j int) bool {
		if out[i].AvgConfidence == out[j].AvgConfidence {
			return out[i].Family < out[j].Family
		}
		return out[i].AvgConfidence > out[j].AvgConfidence
	})
	return out
}

func identityKey(name, image, address string) string {
	n := sanitize(name)
	if n == "" {
		return ""
	}
	img := strings.ToLower(strings.TrimSpace(image))
	addr := normalizeAddr(address)
	if img != "" || addr != "" {
		return fmt.Sprintf("id|%s|%s|%s", img, addr, n)
	}
	return nameKey(name)
}

func nameKey(name string) string {
	n := sanitize(name)
	if n == "" {
		return ""
	}
	return "name|" + n
}

func sanitize(name string) string {
	return strings.ToLower(strings.TrimSpace(name))
}

func normalizeAddr(value string) string {
	v := strings.TrimSpace(strings.ToLower(value))
	if v == "" {
		return ""
	}
	if !strings.HasPrefix(v, "0x") {
		parsed, err := strconv.ParseUint(v, 0, 64)
		if err != nil {
			return v
		}
		return fmt.Sprintf("0x%x", parsed)
	}
	parsed, err := strconv.ParseUint(v, 0, 64)
	if err != nil {
		return v
	}
	return fmt.Sprintf("0x%x", parsed)
}

func containsAny(values []string, tokens ...string) bool {
	for _, value := range values {
		if containsAnyString(strings.ToLower(value), tokens...) {
			return true
		}
	}
	return false
}

func containsAnyString(value string, tokens ...string) bool {
	for _, token := range tokens {
		if strings.Contains(value, strings.ToLower(token)) {
			return true
		}
	}
	return false
}

func topScoreMap(scores map[string]float64, limit int) map[string]float64 {
	type pair struct {
		name  string
		score float64
	}
	rows := make([]pair, 0, len(scores))
	for name, score := range scores {
		rows = append(rows, pair{name: name, score: score})
	}
	sort.Slice(rows, func(i, j int) bool {
		if rows[i].score == rows[j].score {
			return rows[i].name < rows[j].name
		}
		return rows[i].score > rows[j].score
	})
	if limit > 0 && len(rows) > limit {
		rows = rows[:limit]
	}
	out := map[string]float64{}
	for _, row := range rows {
		out[row.name] = roundFloat(row.score)
	}
	return out
}

func resolveAnalysisPath(path string, base string) string {
	if strings.TrimSpace(path) != "" {
		if _, err := os.Stat(path); err == nil {
			return path
		}
	}
	if base == "" {
		return ""
	}
	matches, _ := filepath.Glob(filepath.Join("extraction_out", "reconstruction", "*", "runs", "*", base))
	if len(matches) == 0 {
		return ""
	}
	sort.Slice(matches, func(i, j int) bool {
		ii, _ := os.Stat(matches[i])
		jj, _ := os.Stat(matches[j])
		if ii == nil || jj == nil {
			return matches[i] < matches[j]
		}
		return ii.ModTime().After(jj.ModTime())
	})
	return matches[0]
}

func cosine(a, b []float64) float64 {
	if len(a) == 0 || len(b) == 0 {
		return 0
	}
	lim := len(a)
	if len(b) < lim {
		lim = len(b)
	}
	dot := 0.0
	magA := 0.0
	magB := 0.0
	for i := 0; i < lim; i++ {
		dot += a[i] * b[i]
		magA += a[i] * a[i]
		magB += b[i] * b[i]
	}
	if magA == 0 || magB == 0 {
		return 0
	}
	return dot / (math.Sqrt(magA) * math.Sqrt(magB))
}

func familyStem(name string) string {
	name = sanitize(name)
	if name == "" {
		return ""
	}
	parts := strings.Split(name, "_")
	if len(parts) == 0 {
		return ""
	}
	if len(parts[0]) >= 2 && parts[0] != "sub" {
		return parts[0]
	}
	if len(parts) >= 2 {
		return parts[1]
	}
	return ""
}

func sortedSetKeys(values map[string]struct{}) []string {
	if len(values) == 0 {
		return nil
	}
	out := make([]string, 0, len(values))
	for value := range values {
		if strings.TrimSpace(value) == "" {
			continue
		}
		out = append(out, value)
	}
	sort.Strings(out)
	return out
}

func nonEmpty(value, fallback string) string {
	if strings.TrimSpace(value) == "" {
		return fallback
	}
	return value
}

func uniqueStrings(values []string) []string {
	seen := map[string]struct{}{}
	out := make([]string, 0, len(values))
	for _, value := range values {
		value = strings.TrimSpace(value)
		if value == "" {
			continue
		}
		key := strings.ToLower(value)
		if _, ok := seen[key]; ok {
			continue
		}
		seen[key] = struct{}{}
		out = append(out, value)
	}
	return out
}

func firstString(values []string) string {
	for _, value := range values {
		if strings.TrimSpace(value) != "" {
			return strings.TrimSpace(value)
		}
	}
	return ""
}

func topCountKeys(counts map[string]int, limit int) []string {
	type pair struct {
		name  string
		count int
	}
	rows := make([]pair, 0, len(counts))
	for name, count := range counts {
		if name == "" || count <= 0 {
			continue
		}
		rows = append(rows, pair{name: name, count: count})
	}
	sort.Slice(rows, func(i, j int) bool {
		if rows[i].count == rows[j].count {
			return rows[i].name < rows[j].name
		}
		return rows[i].count > rows[j].count
	})
	if limit > 0 && len(rows) > limit {
		rows = rows[:limit]
	}
	out := make([]string, 0, len(rows))
	for _, row := range rows {
		out = append(out, row.name)
	}
	return out
}

func topExamples(rows []exampleEntry, limit int) []string {
	sort.Slice(rows, func(i, j int) bool {
		if rows[i].confidence == rows[j].confidence {
			return rows[i].name < rows[j].name
		}
		return rows[i].confidence > rows[j].confidence
	})
	seen := map[string]struct{}{}
	out := make([]string, 0, limit)
	for _, row := range rows {
		if row.name == "" {
			continue
		}
		if _, ok := seen[row.name]; ok {
			continue
		}
		seen[row.name] = struct{}{}
		out = append(out, row.name)
		if limit > 0 && len(out) >= limit {
			break
		}
	}
	return out
}

func roundFloat(v float64) float64 {
	return float64(int(v*1000+0.5)) / 1000.0
}

func roundScores(scores map[string]float64) map[string]float64 {
	out := map[string]float64{}
	for k, v := range scores {
		out[k] = roundFloat(v)
	}
	return out
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

func nowUTC() string {
	return time.Now().UTC().Format(time.RFC3339)
}
