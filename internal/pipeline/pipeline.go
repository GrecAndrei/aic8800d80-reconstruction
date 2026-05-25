package pipeline

import (
	"bufio"
	"crypto/md5"
	"crypto/sha256"
	"encoding/binary"
	"encoding/hex"
	"encoding/json"
	"errors"
	"fmt"
	"io"
	"os"
	"path/filepath"
	"regexp"
	"runtime"
	"sort"
	"strconv"
	"strings"
	"sync"

	"aic8800d80/internal/stats"
)

const schemaVersion = "0.1.0"

type Result struct {
	ImageCount        int `json:"image_count"`
	FunctionCount     int `json:"function_count"`
	ArtifactCount     int `json:"artifact_count"`
	FunctionLinkCount int `json:"function_link_count"`
	PatchEntryCount   int `json:"patch_entry_count"`
	CallEdgeCount     int `json:"call_edge_count"`
	MessageCount      int `json:"message_count"`
	StateMachineCount int `json:"state_machine_count"`
	MessageRouteCount int `json:"message_route_count"`
	MiningQueueCount  int `json:"mining_queue_count"`
}

type MiningQueueDelta struct {
	SchemaVersion string               `json:"schema_version"`
	BaselinePath  string               `json:"baseline_path,omitempty"`
	CurrentPath   string               `json:"current_path"`
	PreviousCount int                  `json:"previous_count"`
	CurrentCount  int                  `json:"current_count"`
	AddedCount    int                  `json:"added_count"`
	RemovedCount  int                  `json:"removed_count"`
	AddedTop      []MiningTargetRecord `json:"added_top"`
	RemovedTop    []MiningTargetRecord `json:"removed_top"`
}

type ImageRecord struct {
	SchemaVersion      string `json:"schema_version"`
	Image              string `json:"image"`
	Path               string `json:"path"`
	Size               int64  `json:"size"`
	SHA256             string `json:"sha256"`
	MD5                string `json:"md5"`
	VectorInitialSP    string `json:"vector_initial_sp,omitempty"`
	VectorResetHandler string `json:"vector_reset_handler,omitempty"`
	LikelyThumb        bool   `json:"likely_thumb"`
	PrintableStrings   int    `json:"printable_strings"`
	Source             string `json:"source"`
}

type FunctionRecord struct {
	SchemaVersion string   `json:"schema_version"`
	Image         string   `json:"image"`
	Address       string   `json:"address"`
	Name          string   `json:"name"`
	Aliases       []string `json:"aliases,omitempty"`
	Role          string   `json:"role"`
	Source        string   `json:"source"`
	Confidence    float64  `json:"confidence"`
	Tags          []string `json:"tags,omitempty"`
}

type ArtifactRecord struct {
	SchemaVersion string  `json:"schema_version"`
	Image         string  `json:"image,omitempty"`
	Type          string  `json:"type"`
	Key           string  `json:"key"`
	Value         string  `json:"value"`
	Context       string  `json:"context,omitempty"`
	Source        string  `json:"source"`
	Confidence    float64 `json:"confidence"`
}

type StateMachineRecord struct {
	SchemaVersion string  `json:"schema_version"`
	Image         string  `json:"image"`
	Function      string  `json:"function"`
	Machine       string  `json:"machine"`
	State         string  `json:"state"`
	Expression    string  `json:"expression"`
	Context       string  `json:"context"`
	Source        string  `json:"source"`
	Confidence    float64 `json:"confidence"`
}

type MessageRouteRecord struct {
	SchemaVersion string  `json:"schema_version"`
	Image         string  `json:"image"`
	Dispatcher    string  `json:"dispatcher"`
	Condition     string  `json:"condition"`
	SubtypeExpr   string  `json:"subtype_expr,omitempty"`
	Action        string  `json:"action"`
	TargetFunc    string  `json:"target_func"`
	TargetAddr    string  `json:"target_addr"`
	SideEffect    string  `json:"side_effect,omitempty"`
	Source        string  `json:"source"`
	Confidence    float64 `json:"confidence"`
	Evidence      string  `json:"evidence"`
}

type symbolDump struct {
	Binary  string `json:"binary"`
	Symbols []struct {
		Offset int    `json:"offset"`
		Name   string `json:"name"`
	} `json:"symbols"`
}

func Run(root string, outDir string, minStringLen int, embeddingModel string, queueLimit int, queueMinScore float64, runTag string) (Result, error) {
	if minStringLen < 1 {
		return Result{}, errors.New("min-string-len must be >= 1")
	}
	if queueMinScore < 0 {
		return Result{}, errors.New("queue-min-score must be >= 0")
	}

	rootAbs, err := filepath.Abs(root)
	if err != nil {
		return Result{}, fmt.Errorf("resolve root: %w", err)
	}

	outAbs, err := filepath.Abs(outDir)
	if err != nil {
		return Result{}, fmt.Errorf("resolve output dir: %w", err)
	}
	if err := os.MkdirAll(outAbs, 0o755); err != nil {
		return Result{}, fmt.Errorf("create output dir: %w", err)
	}
	runOutAbs := outAbs
	if strings.TrimSpace(runTag) != "" {
		runOutAbs = filepath.Join(outAbs, "runs", sanitizePathToken(runTag))
		if err := os.MkdirAll(runOutAbs, 0o755); err != nil {
			return Result{}, fmt.Errorf("create run output dir: %w", err)
		}
	}

	prevQueue, baselinePath := loadBaselineQueue(outAbs, runOutAbs)

	images, patchArtifacts, err := collectImageRecords(rootAbs, minStringLen)
	if err != nil {
		return Result{}, err
	}

	functions, err := collectFunctionRecords(rootAbs)
	if err != nil {
		return Result{}, err
	}

	notesPath := firstExistingPath(
		filepath.Join(rootAbs, "re_notes.md"),
		filepath.Join(rootAbs, "docs", "notes", "re_notes.md"),
	)
	primaryImage := primaryImageFromFunctions(functions)
	notesFunctions, notesArtifacts, stateMachines, messageRoutes, err := parseNotes(notesPath, primaryImage)
	if err != nil {
		return Result{}, err
	}
	functions = mergeFunctionRecords(functions, notesFunctions)

	callEdges, err := collectCallEdges(notesPath, functions)
	if err != nil {
		return Result{}, err
	}

	messageSchema := inferMessageSchema(functions, callEdges)

	functionLinks, err := collectFunctionLinks(rootAbs, functions, embeddingModel)
	if err != nil {
		return Result{}, err
	}

	patchEntries, err := decodePatchEntries(firstExistingPath(
		filepath.Join(rootAbs, "fw_patch_table_8800d80_u02.bin"),
		filepath.Join(rootAbs, "inputs", "firmware", "fw_patch_table_8800d80_u02.bin"),
	))
	if err != nil {
		return Result{}, err
	}

	learningSignals := loadLearningSignals(rootAbs, outAbs, runOutAbs, functions)
	miningQueue := buildMiningQueue(functions, callEdges, functionLinks, messageSchema, learningSignals, queueLimit, queueMinScore)

	artifacts := make([]ArtifactRecord, 0, len(patchArtifacts)+len(notesArtifacts)+256)
	artifacts = append(artifacts, patchArtifacts...)
	artifacts = append(artifacts, notesArtifacts...)
	artifacts = append(artifacts, vectorArtifacts(images)...)

	sort.Slice(images, func(i, j int) bool { return images[i].Image < images[j].Image })
	sort.Slice(functions, func(i, j int) bool {
		if functions[i].Image == functions[j].Image {
			return parseHex(functions[i].Address) < parseHex(functions[j].Address)
		}
		return functions[i].Image < functions[j].Image
	})
	sort.Slice(artifacts, func(i, j int) bool {
		if artifacts[i].Type == artifacts[j].Type {
			if artifacts[i].Image == artifacts[j].Image {
				return artifacts[i].Key < artifacts[j].Key
			}
			return artifacts[i].Image < artifacts[j].Image
		}
		return artifacts[i].Type < artifacts[j].Type
	})

	if err := writeJSONL(filepath.Join(runOutAbs, "images.jsonl"), images); err != nil {
		return Result{}, err
	}
	if err := writeJSONL(filepath.Join(runOutAbs, "functions.jsonl"), functions); err != nil {
		return Result{}, err
	}
	if err := writeJSONL(filepath.Join(runOutAbs, "artifacts.jsonl"), artifacts); err != nil {
		return Result{}, err
	}
	if err := writeJSONL(filepath.Join(runOutAbs, "function_links.jsonl"), functionLinks); err != nil {
		return Result{}, err
	}
	if err := writeJSONL(filepath.Join(runOutAbs, "patch_entries.jsonl"), patchEntries); err != nil {
		return Result{}, err
	}
	if err := writeJSONL(filepath.Join(runOutAbs, "call_edges.jsonl"), callEdges); err != nil {
		return Result{}, err
	}
	if err := writeJSONL(filepath.Join(runOutAbs, "message_schema.jsonl"), messageSchema); err != nil {
		return Result{}, err
	}
	if err := writeJSONL(filepath.Join(runOutAbs, "state_machines.jsonl"), stateMachines); err != nil {
		return Result{}, err
	}
	if err := writeJSONL(filepath.Join(runOutAbs, "message_routes.jsonl"), messageRoutes); err != nil {
		return Result{}, err
	}
	if err := writeJSONL(filepath.Join(runOutAbs, "mining_queue.jsonl"), miningQueue); err != nil {
		return Result{}, err
	}
	fullQueue := buildMiningQueue(functions, callEdges, functionLinks, messageSchema, learningSignals, 0, queueMinScore)
	if err := writeJSONL(filepath.Join(runOutAbs, "mining_queue_full.jsonl"), fullQueue); err != nil {
		return Result{}, err
	}
	if err := writeJSON(filepath.Join(runOutAbs, "learning_signals.json"), learningSignals); err != nil {
		return Result{}, err
	}
	topN := 300
	if queueLimit > 0 && queueLimit < topN {
		topN = queueLimit
	}
	if topN > len(fullQueue) {
		topN = len(fullQueue)
	}
	if topN > 0 {
		if err := writeJSONL(filepath.Join(runOutAbs, "mining_queue_top300.jsonl"), fullQueue[:topN]); err != nil {
			return Result{}, err
		}
	}
	delta := buildMiningQueueDelta(prevQueue, fullQueue, baselinePath, filepath.Join(runOutAbs, "mining_queue_full.jsonl"))
	if err := writeJSON(filepath.Join(runOutAbs, "mining_queue_delta.json"), delta); err != nil {
		return Result{}, err
	}

	if err := generateTwinScaffold(rootAbs, runOutAbs, functions, callEdges, messageSchema, patchEntries); err != nil {
		return Result{}, err
	}

	summary := Result{
		ImageCount:        len(images),
		FunctionCount:     len(functions),
		ArtifactCount:     len(artifacts),
		FunctionLinkCount: len(functionLinks),
		PatchEntryCount:   len(patchEntries),
		CallEdgeCount:     len(callEdges),
		MessageCount:      len(messageSchema),
		StateMachineCount: len(stateMachines),
		MessageRouteCount: len(messageRoutes),
		MiningQueueCount:  len(miningQueue),
	}
	if err := writeJSON(filepath.Join(runOutAbs, "summary.json"), summary); err != nil {
		return Result{}, err
	}

	if _, err := stats.CollectAndPersist(runOutAbs); err != nil {
		return Result{}, fmt.Errorf("collect statistics: %w", err)
	}

	return summary, nil
}

func firstExistingPath(candidates ...string) string {
	for _, p := range candidates {
		if strings.TrimSpace(p) == "" {
			continue
		}
		if _, err := os.Stat(p); err == nil {
			return p
		}
	}
	if len(candidates) == 0 {
		return ""
	}
	return candidates[0]
}

func collectImageRecords(root string, minStringLen int) ([]ImageRecord, []ArtifactRecord, error) {
	paths := make([]string, 0, 16)
	seen := map[string]struct{}{}
	for _, pattern := range []string{
		filepath.Join(root, "*.bin"),
		filepath.Join(root, "inputs", "firmware", "*.bin"),
	} {
		matches, err := filepath.Glob(pattern)
		if err != nil {
			return nil, nil, fmt.Errorf("glob bin files: %w", err)
		}
		for _, p := range matches {
			if _, ok := seen[p]; ok {
				continue
			}
			seen[p] = struct{}{}
			paths = append(paths, p)
		}
	}

	images := make([]ImageRecord, 0, len(paths))
	artifacts := make([]ArtifactRecord, 0, 64)

	type imageResult struct {
		imageRec  ImageRecord
		artifacts []ArtifactRecord
		err       error
	}
	workers := runtime.NumCPU()
	if workers > len(paths) {
		workers = len(paths)
	}
	if workers < 1 {
		workers = 1
	}

	pathCh := make(chan string)
	resCh := make(chan imageResult, len(paths))
	var wg sync.WaitGroup
	for i := 0; i < workers; i++ {
		wg.Add(1)
		go func() {
			defer wg.Done()
			for path := range pathCh {
				fileName := filepath.Base(path)
				data, err := os.ReadFile(path)
				if err != nil {
					resCh <- imageResult{err: fmt.Errorf("read %s: %w", fileName, err)}
					continue
				}
				sha := sha256.Sum256(data)
				md5sum := md5.Sum(data)
				stringsFound := extractASCIIStrings(data, minStringLen)
				rec := ImageRecord{
					SchemaVersion:    schemaVersion,
					Image:            fileName,
					Path:             path,
					Size:             int64(len(data)),
					SHA256:           hex.EncodeToString(sha[:]),
					MD5:              hex.EncodeToString(md5sum[:]),
					LikelyThumb:      false,
					PrintableStrings: len(stringsFound),
					Source:           "binary_scan",
				}
				if len(data) >= 8 {
					sp := binary.LittleEndian.Uint32(data[:4])
					rh := binary.LittleEndian.Uint32(data[4:8])
					if looksLikeVectorTable(sp, rh) {
						rec.VectorInitialSP = fmt.Sprintf("0x%08x", sp)
						rec.VectorResetHandler = fmt.Sprintf("0x%08x", rh)
						rec.LikelyThumb = true
					}
				}
				localArtifacts := make([]ArtifactRecord, 0, 8)
				if strings.Contains(fileName, "patch_table") {
					for _, s := range stringsFound {
						if strings.Contains(s, "AICBT_") {
							localArtifacts = append(localArtifacts, ArtifactRecord{
								SchemaVersion: schemaVersion,
								Image:         fileName,
								Type:          "patch_tag",
								Key:           s,
								Value:         s,
								Source:        "patch_table_strings",
								Confidence:    0.95,
							})
						}
					}
				}
				resCh <- imageResult{imageRec: rec, artifacts: localArtifacts}
			}
		}()
	}
	go func() {
		for _, p := range paths {
			pathCh <- p
		}
		close(pathCh)
		wg.Wait()
		close(resCh)
	}()

	for res := range resCh {
		if res.err != nil {
			return nil, nil, res.err
		}
		images = append(images, res.imageRec)
		artifacts = append(artifacts, res.artifacts...)
	}
	return images, dedupeArtifacts(artifacts), nil
}

func collectFunctionRecords(root string) ([]FunctionRecord, error) {
	dump, err := loadSymbolDump(root)
	if err != nil {
		return nil, err
	}

	rows := make([]FunctionRecord, 0, len(dump.Symbols))
	for _, s := range dump.Symbols {
		name := strings.TrimSpace(s.Name)
		if name == "" {
			continue
		}
		rows = append(rows, FunctionRecord{
			SchemaVersion: schemaVersion,
			Image:         dump.Binary,
			Address:       fmt.Sprintf("0x%x", s.Offset),
			Name:          name,
			Role:          inferRole(name),
			Source:        "function_names_json",
			Confidence:    0.55,
			Tags:          inferTags(name),
		})
	}

	return rows, nil
}

func parseNotes(path string, image string) ([]FunctionRecord, []ArtifactRecord, []StateMachineRecord, []MessageRouteRecord, error) {
	if strings.TrimSpace(image) == "" {
		image = "unknown.bin"
	}
	f, err := os.Open(path)
	if err != nil {
		return nil, nil, nil, nil, fmt.Errorf("open notes: %w", err)
	}
	defer f.Close()

	fnLineRe := regexp.MustCompile(`sub_([0-9A-Fa-f]{4,8})\s*=\s*([A-Za-z0-9_]+)`)
	mmioRe := regexp.MustCompile(`0x[0-9A-Fa-f]{8}`)
	keStateGuardRe := regexp.MustCompile(`(?i)\bke_state_get\(([^)]+)\)\s*==\s*([A-Za-z0-9_]+)`)
	apmTokenRe := regexp.MustCompile(`(?i)\b(APM_[A-Z0-9_]+)\b`)
	smFuncRe := regexp.MustCompile(`(?i)\b(sm_[A-Za-z0-9_]+)\b`)
	stateEqualsRe := regexp.MustCompile(`(?i)\bstate\s*==\s*([0-9]+|[A-Za-z][A-Za-z0-9_]*)`)
	stateCheckRe := regexp.MustCompile(`(?i)\bcheck\s*==\s*([0-9]+|[A-Za-z][A-Za-z0-9_]*)`)
	typeLERe := regexp.MustCompile(`(?i)type\s*<=\s*(0x[0-9a-f]+|\d+)`)
	typeGTRe := regexp.MustCompile(`(?i)type\s*>\s*(0x[0-9a-f]+|\d+)`)
	handlerTableRe := regexp.MustCompile(`(?i)handler table at\s*(0x[0-9a-f]+)\s*\+\s*16\*type`)
	subtypeRe := regexp.MustCompile(`(?i)subtype\s*\(a1\s*&\s*0xFF\)|a1\s*&\s*0xFF|a1\s*>>\s*8`)
	ifCallRe := regexp.MustCompile(`(?i)-\s*if\s+([^:]+):\s*calls\s+(.+)`)

	functions := make([]FunctionRecord, 0, 512)
	artifacts := make([]ArtifactRecord, 0, 512)
	stateMachines := make([]StateMachineRecord, 0, 128)
	messageRoutes := make([]MessageRouteRecord, 0, 128)

	addStateMachine := func(function, machine, state, expr, context, source string, confidence float64) {
		machine = strings.TrimSpace(machine)
		state = strings.TrimSpace(state)
		function = strings.TrimSpace(function)
		expr = strings.TrimSpace(expr)
		context = trimForContext(context)
		if machine == "" {
			machine = "unknown"
		}
		if state == "" || expr == "" {
			return
		}
		stateMachines = append(stateMachines, StateMachineRecord{
			SchemaVersion: schemaVersion,
			Image:         image,
			Function:      function,
			Machine:       machine,
			State:         state,
			Expression:    expr,
			Context:       context,
			Source:        source,
			Confidence:    confidence,
		})
	}

	addRoute := func(dispatcher, condition, subtypeExpr, action, targetName, targetAddr, sideEffect, source, evidence string, confidence float64) {
		if dispatcher == "" {
			dispatcher = "msg_dispatch"
		}
		messageRoutes = append(messageRoutes, MessageRouteRecord{
			SchemaVersion: schemaVersion,
			Image:         image,
			Dispatcher:    dispatcher,
			Condition:     strings.TrimSpace(condition),
			SubtypeExpr:   strings.TrimSpace(subtypeExpr),
			Action:        strings.TrimSpace(action),
			TargetFunc:    strings.TrimSpace(targetName),
			TargetAddr:    strings.ToLower(strings.TrimSpace(targetAddr)),
			SideEffect:    strings.TrimSpace(sideEffect),
			Source:        source,
			Confidence:    confidence,
			Evidence:      trimForContext(evidence),
		})
	}

	var currentName string

	scanner := bufio.NewScanner(f)
	scanner.Buffer(make([]byte, 1024), 1024*1024)
	for scanner.Scan() {
		line := scanner.Text()
		lower := strings.ToLower(line)

		if m := fnLineRe.FindStringSubmatch(line); len(m) == 3 {
			addr := "0x" + strings.ToLower(m[1])
			name := m[2]
			currentName = name
			functions = append(functions, FunctionRecord{
				SchemaVersion: schemaVersion,
				Image:         image,
				Address:       addr,
				Name:          name,
				Role:          inferRole(name),
				Source:        "re_notes",
				Confidence:    0.82,
				Tags:          inferTags(name),
			})
		}

		if strings.Contains(lower, "message processing pipeline") {
			currentName = "msg_dispatch"
		}

		if strings.Contains(line, "MMIO") || strings.Contains(line, "MMIO ") {
			addrs := mmioRe.FindAllString(line, -1)
			for _, addr := range addrs {
				artifacts = append(artifacts, ArtifactRecord{
					SchemaVersion: schemaVersion,
					Image:         image,
					Type:          "mmio_ref",
					Key:           strings.ToLower(addr),
					Value:         strings.ToLower(addr),
					Context:       trimForContext(line),
					Source:        "re_notes",
					Confidence:    0.7,
				})
			}
		}

		if m := keStateGuardRe.FindStringSubmatch(line); len(m) == 3 {
			addStateMachine(currentName, m[1], m[2], m[0], line, "re_notes_state_guard", 0.92)
		}

		if strings.Contains(lower, "state") {
			if m := stateEqualsRe.FindStringSubmatch(line); len(m) == 2 {
				addStateMachine(currentName, currentName, m[1], m[0], line, "re_notes_state_transition", 0.72)
			}
			if m := stateCheckRe.FindStringSubmatch(line); len(m) == 2 {
				addStateMachine(currentName, currentName, m[1], m[0], line, "re_notes_state_transition", 0.68)
			}
		}

		if m := apmTokenRe.FindAllStringSubmatch(line, -1); len(m) > 0 {
			fn := currentName
			if sm := smFuncRe.FindStringSubmatch(line); len(sm) == 2 {
				fn = sm[1]
			}
			machine := "TASK_APM"
			if strings.Contains(lower, "nested state machine") {
				machine = "nested_state_machine"
			}
			for _, tok := range m {
				if len(tok) != 2 {
					continue
				}
				addStateMachine(fn, machine, tok[1], tok[1], line, "re_notes_state_token", 0.83)
			}
		}

		if strings.Contains(lower, "if type") && strings.Contains(lower, "calls") {
			cond := "type_guard"
			subtype := ""
			if m := subtypeRe.FindString(line); m != "" {
				subtype = m
			}
			if m := typeLERe.FindStringSubmatch(line); len(m) == 2 {
				cond = "type<=" + m[1]
			}
			if m := typeGTRe.FindStringSubmatch(line); len(m) == 2 {
				cond = "type>" + m[1]
			}
			if strings.Contains(line, "sub_12D108") {
				addRoute(currentName, cond, subtype, "enqueue", "queue_push", "0x12d108", "queue mutation", "re_notes_message_pipeline", line, 0.9)
			}
			if strings.Contains(line, "sub_12CFC4") {
				addRoute(currentName, cond, subtype, "set_flag", "set_flag", "0x12cfc4", "flag update", "re_notes_message_pipeline", line, 0.88)
			}
			if strings.Contains(line, "sub_12F32C") {
				addRoute(currentName, cond, subtype, "error_path", "error_handler", "0x12f32c", "blocking/error", "re_notes_message_pipeline", line, 0.9)
			}
			if strings.Contains(line, "sub_12E948") {
				addRoute(currentName, cond, subtype, "parse_message", "msg_parse", "0x12e948", "parser dispatch", "re_notes_message_pipeline", line, 0.92)
			}
			if strings.Contains(line, "sub_12CA88") {
				addRoute(currentName, cond, subtype, "pool_get", "buffer_pool_get", "0x12ca88", "buffer allocation", "re_notes_message_pipeline", line, 0.86)
			}
			if strings.Contains(line, "sub_12F3EC") {
				addRoute(currentName, cond, subtype, "fallback", "fallback_handler", "0x12f3ec", "fallback path", "re_notes_message_pipeline", line, 0.84)
			}
		}

		if strings.Contains(lower, "otherwise:") && strings.Contains(lower, "calls") {
			cond := "0xC<type<=0xE"
			subtype := ""
			if m := subtypeRe.FindString(line); m != "" {
				subtype = m
			}
			if strings.Contains(line, "sub_12E948") {
				addRoute(currentName, cond, subtype, "parse_message", "msg_parse", "0x12e948", "parser dispatch", "re_notes_message_pipeline", line, 0.92)
			}
			if strings.Contains(line, "sub_12CA88") {
				addRoute(currentName, cond, subtype, "pool_get", "buffer_pool_get", "0x12ca88", "buffer allocation", "re_notes_message_pipeline", line, 0.86)
			}
			if strings.Contains(line, "sub_12F3EC") {
				addRoute(currentName, cond, subtype, "fallback", "fallback_handler", "0x12f3ec", "fallback path", "re_notes_message_pipeline", line, 0.84)
			}
		}

		if m := handlerTableRe.FindStringSubmatch(line); len(m) == 2 {
			addRoute("msg_register_handler", "type/subtype", "type=(a1>>8),subtype=(a1&0xFF)", "handler_lookup", "handler_table", m[1], "table lookup", "re_notes_handler_table", line, 0.9)
		}

		if m := ifCallRe.FindStringSubmatch(line); len(m) == 3 && strings.Contains(lower, "msg_parse") {
			cond := strings.TrimSpace(m[1])
			if cond != "" {
				addRoute("msg_parse", cond, "", "conditional_call", "msg_parse_path", "", "guarded call path", "re_notes_if_call", line, 0.75)
			}
		}
	}
	if err := scanner.Err(); err != nil {
		return nil, nil, nil, nil, fmt.Errorf("scan notes: %w", err)
	}

	functions = dedupeFunctions(functions)
	artifacts = dedupeArtifacts(artifacts)
	stateMachines = dedupeStateMachines(stateMachines)
	messageRoutes = dedupeMessageRoutes(messageRoutes)
	return functions, artifacts, stateMachines, messageRoutes, nil
}

func mergeFunctionRecords(base []FunctionRecord, overlay []FunctionRecord) []FunctionRecord {
	merged := make(map[string]FunctionRecord, len(base)+len(overlay))
	baseSorted := append([]FunctionRecord(nil), base...)
	overlaySorted := append([]FunctionRecord(nil), overlay...)
	sortFn := func(rows []FunctionRecord) {
		sort.Slice(rows, func(i, j int) bool {
			if rows[i].Image == rows[j].Image {
				ai := parseHex(rows[i].Address)
				aj := parseHex(rows[j].Address)
				if ai == aj {
					return rows[i].Name < rows[j].Name
				}
				return ai < aj
			}
			return rows[i].Image < rows[j].Image
		})
	}
	sortFn(baseSorted)
	sortFn(overlaySorted)

	for _, r := range baseSorted {
		key := r.Image + "|" + strings.ToLower(r.Address)
		merged[key] = r
	}

	for _, r := range overlaySorted {
		key := r.Image + "|" + strings.ToLower(r.Address)
		existing, ok := merged[key]
		if !ok {
			merged[key] = r
			continue
		}

		if r.Confidence > existing.Confidence {
			if existing.Name != r.Name {
				r.Aliases = appendUnique(r.Aliases, existing.Name)
			}
			r.Aliases = appendUnique(r.Aliases, existing.Aliases...)
			merged[key] = r
			continue
		}

		if existing.Name != r.Name {
			existing.Aliases = appendUnique(existing.Aliases, r.Name)
		}
		existing.Aliases = appendUnique(existing.Aliases, r.Aliases...)
		existing.Tags = appendUnique(existing.Tags, r.Tags...)
		merged[key] = existing
	}

	out := make([]FunctionRecord, 0, len(merged))
	for _, r := range merged {
		out = append(out, r)
	}
	sort.Slice(out, func(i, j int) bool {
		if out[i].Image == out[j].Image {
			ai := parseHex(out[i].Address)
			aj := parseHex(out[j].Address)
			if ai == aj {
				return out[i].Name < out[j].Name
			}
			return ai < aj
		}
		return out[i].Image < out[j].Image
	})
	return out
}

func vectorArtifacts(images []ImageRecord) []ArtifactRecord {
	rows := make([]ArtifactRecord, 0, len(images)*2)
	for _, img := range images {
		if img.VectorInitialSP != "" {
			rows = append(rows, ArtifactRecord{
				SchemaVersion: schemaVersion,
				Image:         img.Image,
				Type:          "vector_field",
				Key:           "initial_sp",
				Value:         strings.ToLower(img.VectorInitialSP),
				Source:        "binary_scan",
				Confidence:    0.9,
			})
		}
		if img.VectorResetHandler != "" {
			rows = append(rows, ArtifactRecord{
				SchemaVersion: schemaVersion,
				Image:         img.Image,
				Type:          "vector_field",
				Key:           "reset_handler",
				Value:         strings.ToLower(img.VectorResetHandler),
				Source:        "binary_scan",
				Confidence:    0.9,
			})
		}
	}
	return dedupeArtifacts(rows)
}

func extractASCIIStrings(data []byte, minLen int) []string {
	if minLen <= 0 {
		minLen = 1
	}

	out := make([]string, 0, 1024)
	buf := make([]byte, 0, 128)
	flush := func() {
		if len(buf) >= minLen {
			out = append(out, string(buf))
		}
		buf = buf[:0]
	}

	for _, b := range data {
		if b >= 0x20 && b <= 0x7e {
			buf = append(buf, b)
			continue
		}
		flush()
	}
	flush()

	return out
}

func dedupeFunctions(in []FunctionRecord) []FunctionRecord {
	m := make(map[string]FunctionRecord, len(in))
	for _, r := range in {
		key := r.Image + "|" + strings.ToLower(r.Address) + "|" + r.Name
		m[key] = r
	}
	out := make([]FunctionRecord, 0, len(m))
	for _, r := range m {
		out = append(out, r)
	}
	return out
}

func dedupeArtifacts(in []ArtifactRecord) []ArtifactRecord {
	m := make(map[string]ArtifactRecord, len(in))
	for _, r := range in {
		key := r.Image + "|" + r.Type + "|" + r.Key + "|" + r.Value
		if _, ok := m[key]; ok {
			continue
		}
		m[key] = r
	}
	out := make([]ArtifactRecord, 0, len(m))
	for _, r := range m {
		out = append(out, r)
	}
	return out
}

func dedupeStateMachines(in []StateMachineRecord) []StateMachineRecord {
	m := make(map[string]StateMachineRecord, len(in))
	for _, r := range in {
		key := strings.ToLower(r.Image + "|" + r.Function + "|" + r.Machine + "|" + r.State + "|" + r.Expression)
		if old, ok := m[key]; ok {
			if r.Confidence > old.Confidence {
				m[key] = r
			}
			continue
		}
		m[key] = r
	}
	out := make([]StateMachineRecord, 0, len(m))
	for _, r := range m {
		out = append(out, r)
	}
	sort.Slice(out, func(i, j int) bool {
		if out[i].Machine == out[j].Machine {
			if out[i].Function == out[j].Function {
				return out[i].State < out[j].State
			}
			return out[i].Function < out[j].Function
		}
		return out[i].Machine < out[j].Machine
	})
	return out
}

func dedupeMessageRoutes(in []MessageRouteRecord) []MessageRouteRecord {
	m := make(map[string]MessageRouteRecord, len(in))
	for _, r := range in {
		k := strings.ToLower(r.Dispatcher + "|" + r.Condition + "|" + r.SubtypeExpr + "|" + r.Action + "|" + r.TargetAddr + "|" + r.TargetFunc + "|" + r.SideEffect)
		if old, ok := m[k]; ok {
			if r.Confidence > old.Confidence {
				m[k] = r
			}
			continue
		}
		m[k] = r
	}
	out := make([]MessageRouteRecord, 0, len(m))
	for _, r := range m {
		out = append(out, r)
	}
	sort.Slice(out, func(i, j int) bool {
		if out[i].Dispatcher == out[j].Dispatcher {
			if out[i].Condition == out[j].Condition {
				return out[i].TargetAddr < out[j].TargetAddr
			}
			return out[i].Condition < out[j].Condition
		}
		return out[i].Dispatcher < out[j].Dispatcher
	})
	return out
}

func inferRole(name string) string {
	prefix := strings.ToLower(strings.SplitN(name, "_", 2)[0])
	switch prefix {
	case "ke", "co":
		return "kernel"
	case "sdio", "ipc", "host":
		return "transport"
	case "txl", "tx", "rxl", "scan":
		return "datapath"
	case "phy", "rf":
		return "radio"
	case "sm", "apm", "mm", "me", "bam":
		return "mac_state_machine"
	case "rc", "tpc":
		return "rate_control"
	case "hal":
		return "hal"
	case "crypto":
		return "crypto"
	default:
		if strings.Contains(strings.ToLower(name), "irq") {
			return "interrupt"
		}
		if strings.Contains(strings.ToLower(name), "patch") {
			return "patching"
		}
		return "unknown"
	}
}

func inferTags(name string) []string {
	role := inferRole(name)
	if role == "unknown" {
		return nil
	}
	return []string{role}
}

func appendUnique(slice []string, values ...string) []string {
	seen := make(map[string]struct{}, len(slice)+len(values))
	for _, s := range slice {
		if s == "" {
			continue
		}
		seen[s] = struct{}{}
	}
	for _, v := range values {
		if v == "" {
			continue
		}
		if _, ok := seen[v]; ok {
			continue
		}
		seen[v] = struct{}{}
		slice = append(slice, v)
	}
	return slice
}

func trimForContext(s string) string {
	s = strings.TrimSpace(s)
	if len(s) <= 200 {
		return s
	}
	return s[:200]
}

func writeJSONL[T any](path string, rows []T) error {
	f, err := os.Create(path)
	if err != nil {
		return fmt.Errorf("create %s: %w", path, err)
	}
	defer f.Close()

	bw := bufio.NewWriter(f)
	enc := json.NewEncoder(bw)
	for _, row := range rows {
		if err := enc.Encode(row); err != nil {
			return fmt.Errorf("encode %s: %w", path, err)
		}
	}
	if err := bw.Flush(); err != nil {
		return fmt.Errorf("flush %s: %w", path, err)
	}
	return nil
}

func writeJSON(path string, v any) error {
	f, err := os.Create(path)
	if err != nil {
		return fmt.Errorf("create %s: %w", path, err)
	}
	defer f.Close()

	b, err := json.MarshalIndent(v, "", "  ")
	if err != nil {
		return fmt.Errorf("marshal json %s: %w", path, err)
	}
	if _, err := io.WriteString(f, string(b)+"\n"); err != nil {
		return fmt.Errorf("write %s: %w", path, err)
	}
	return nil
}

func parseHex(s string) uint64 {
	s = strings.TrimSpace(strings.ToLower(s))
	s = strings.TrimPrefix(s, "0x")
	v, err := strconv.ParseUint(s, 16, 64)
	if err != nil {
		return 0
	}
	return v
}

func looksLikeVectorTable(sp uint32, reset uint32) bool {
	if reset&1 == 0 {
		return false
	}
	if sp < 0x00010000 || sp > 0x40000000 {
		return false
	}
	if reset > 0x03ffffff {
		return false
	}
	return true
}

func sanitizePathToken(in string) string {
	in = strings.TrimSpace(in)
	if in == "" {
		return "run"
	}
	var b strings.Builder
	for _, r := range in {
		if (r >= 'a' && r <= 'z') || (r >= 'A' && r <= 'Z') || (r >= '0' && r <= '9') || r == '-' || r == '_' || r == '.' {
			b.WriteRune(r)
			continue
		}
		b.WriteByte('_')
	}
	out := strings.Trim(strings.TrimSpace(b.String()), "._")
	if out == "" {
		return "run"
	}
	return out
}

func loadBaselineQueue(rootOutAbs string, runOutAbs string) ([]MiningTargetRecord, string) {
	if runOutAbs == rootOutAbs {
		path := filepath.Join(rootOutAbs, "mining_queue_full.jsonl")
		rows, err := readMiningQueueJSONL(path)
		if err == nil {
			return rows, path
		}
		return nil, ""
	}
	runsDir := filepath.Join(rootOutAbs, "runs")
	entries, err := os.ReadDir(runsDir)
	if err != nil {
		return nil, ""
	}
	type candidate struct {
		path string
		mod  int64
	}
	cands := make([]candidate, 0, len(entries))
	for _, e := range entries {
		if !e.IsDir() {
			continue
		}
		p := filepath.Join(runsDir, e.Name(), "mining_queue_full.jsonl")
		st, err := os.Stat(p)
		if err != nil || !st.Mode().IsRegular() || filepath.Join(runsDir, e.Name()) == runOutAbs {
			continue
		}
		cands = append(cands, candidate{path: p, mod: st.ModTime().UnixNano()})
	}
	if len(cands) == 0 {
		return nil, ""
	}
	sort.Slice(cands, func(i, j int) bool { return cands[i].mod > cands[j].mod })
	rows, err := readMiningQueueJSONL(cands[0].path)
	if err != nil {
		return nil, ""
	}
	return rows, cands[0].path
}

func readMiningQueueJSONL(path string) ([]MiningTargetRecord, error) {
	f, err := os.Open(path)
	if err != nil {
		return nil, err
	}
	defer f.Close()
	out := make([]MiningTargetRecord, 0, 512)
	s := bufio.NewScanner(f)
	s.Buffer(make([]byte, 1024), 1024*1024)
	for s.Scan() {
		line := strings.TrimSpace(s.Text())
		if line == "" {
			continue
		}
		var rec MiningTargetRecord
		if err := json.Unmarshal([]byte(line), &rec); err != nil {
			return nil, err
		}
		out = append(out, rec)
	}
	if err := s.Err(); err != nil {
		return nil, err
	}
	return out, nil
}

func buildMiningQueueDelta(prev []MiningTargetRecord, cur []MiningTargetRecord, baselinePath string, currentPath string) MiningQueueDelta {
	prevByKey := make(map[string]MiningTargetRecord, len(prev))
	curByKey := make(map[string]MiningTargetRecord, len(cur))
	makeKey := func(r MiningTargetRecord) string {
		return strings.ToLower(r.Image + "|" + r.Address + "|" + r.Name)
	}
	for _, r := range prev {
		prevByKey[makeKey(r)] = r
	}
	for _, r := range cur {
		curByKey[makeKey(r)] = r
	}
	added := make([]MiningTargetRecord, 0, 64)
	removed := make([]MiningTargetRecord, 0, 64)
	for k, r := range curByKey {
		if _, ok := prevByKey[k]; !ok {
			added = append(added, r)
		}
	}
	for k, r := range prevByKey {
		if _, ok := curByKey[k]; !ok {
			removed = append(removed, r)
		}
	}
	addedCount := len(added)
	removedCount := len(removed)
	sort.Slice(added, func(i, j int) bool {
		if added[i].PriorityScore == added[j].PriorityScore {
			return parseHex(added[i].Address) < parseHex(added[j].Address)
		}
		return added[i].PriorityScore > added[j].PriorityScore
	})
	sort.Slice(removed, func(i, j int) bool {
		if removed[i].PriorityScore == removed[j].PriorityScore {
			return parseHex(removed[i].Address) < parseHex(removed[j].Address)
		}
		return removed[i].PriorityScore > removed[j].PriorityScore
	})
	if len(added) > 50 {
		added = added[:50]
	}
	if len(removed) > 50 {
		removed = removed[:50]
	}
	return MiningQueueDelta{
		SchemaVersion: schemaVersion,
		BaselinePath:  baselinePath,
		CurrentPath:   currentPath,
		PreviousCount: len(prev),
		CurrentCount:  len(cur),
		AddedCount:    addedCount,
		RemovedCount:  removedCount,
		AddedTop:      added,
		RemovedTop:    removed,
	}
}
