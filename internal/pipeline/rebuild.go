package pipeline

import (
	"bufio"
	"encoding/json"
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

type CallEdgeRecord struct {
	SchemaVersion string  `json:"schema_version"`
	Image         string  `json:"image"`
	SourceAddr    string  `json:"source_addr"`
	SourceName    string  `json:"source_name"`
	TargetAddr    string  `json:"target_addr"`
	TargetName    string  `json:"target_name"`
	Evidence      string  `json:"evidence"`
	Source        string  `json:"source"`
	Confidence    float64 `json:"confidence"`
}

type MessageSchemaRecord struct {
	SchemaVersion string  `json:"schema_version"`
	Image         string  `json:"image"`
	MessageKey    string  `json:"message_key"`
	Family        string  `json:"family"`
	Kind          string  `json:"kind"`
	HandlerName   string  `json:"handler_name"`
	HandlerAddr   string  `json:"handler_addr"`
	Role          string  `json:"role"`
	OutgoingCalls int     `json:"outgoing_calls"`
	Confidence    float64 `json:"confidence"`
	Source        string  `json:"source"`
}

type TwinPlan struct {
	SchemaVersion string           `json:"schema_version"`
	GeneratedAt   string           `json:"generated_at"`
	Root          string           `json:"root"`
	OutDir        string           `json:"out_dir"`
	FunctionCount int              `json:"function_count"`
	CallEdgeCount int              `json:"call_edge_count"`
	MessageCount  int              `json:"message_count"`
	PatchCount    int              `json:"patch_count"`
	RoleCounts    []map[string]any `json:"role_counts"`
	SourceFiles   []string         `json:"source_files"`
	Headers       []string         `json:"headers"`
	Notes         []string         `json:"notes"`
}

type MiningTargetRecord struct {
	SchemaVersion string   `json:"schema_version"`
	Image         string   `json:"image"`
	Address       string   `json:"address"`
	Name          string   `json:"name"`
	Role          string   `json:"role"`
	Confidence    float64  `json:"confidence"`
	OutDegree     int      `json:"out_degree"`
	InDegree      int      `json:"in_degree"`
	LinkDegree    int      `json:"link_degree"`
	MessageHits   int      `json:"message_hits"`
	PriorityScore float64  `json:"priority_score"`
	Reasons       []string `json:"reasons"`
}

type FamilyConsensusRecord struct {
	SchemaVersion       string   `json:"schema_version"`
	CanonicalFunction   string   `json:"canonical_function"`
	ImageCount          int      `json:"image_count"`
	LinkCount           int      `json:"link_count"`
	AvgLinkConfidence   float64  `json:"avg_link_confidence"`
	ConsensusConfidence float64  `json:"consensus_confidence"`
	MemberImages        []string `json:"member_images"`
	RoleHints           []string `json:"role_hints"`
	TopOutgoingCalls    []string `json:"top_outgoing_calls"`
	MessageFamilies     []string `json:"message_families"`
	MessageKinds        []string `json:"message_kinds"`
}

type consensusCallVote struct {
	count int
	conf  float64
}

func primaryImageFromFunctions(functions []FunctionRecord) string {
	counts := map[string]int{}
	best := ""
	bestCount := 0
	for _, fn := range functions {
		img := strings.TrimSpace(fn.Image)
		if img == "" {
			continue
		}
		counts[img]++
		if counts[img] > bestCount {
			bestCount = counts[img]
			best = img
		}
	}
	return best
}

func collectCallEdges(notesPath string, functions []FunctionRecord) ([]CallEdgeRecord, error) {
	baseImage := primaryImageFromFunctions(functions)
	if baseImage == "" {
		baseImage = "unknown.bin"
	}
	addrName := map[string]string{}
	for _, fn := range functions {
		if fn.Image != baseImage {
			continue
		}
		addr := strings.ToLower(fn.Address)
		addrName[addr] = fn.Name
		if v := parseHex(addr); v > 0 && v < 0x100000 {
			addrName[fmt.Sprintf("0x%x", v+0x100000)] = fn.Name
		}
		if v := parseHex(addr); v >= 0x100000 {
			addrName[fmt.Sprintf("0x%x", v-0x100000)] = fn.Name
		}
	}

	f, err := os.Open(notesPath)
	if err != nil {
		return nil, fmt.Errorf("open notes for call edges: %w", err)
	}
	defer f.Close()

	fnDef := regexp.MustCompile(`sub_([0-9A-Fa-f]{4,8})\s*=\s*([A-Za-z0-9_]+)`)
	callSub := regexp.MustCompile(`sub_([0-9A-Fa-f]{4,8})(?:\s*=\s*([A-Za-z0-9_]+))?`)
	thunkRe := regexp.MustCompile(`(?i)sub_([0-9A-Fa-f]{4,8}).*thunk to sub_([0-9A-Fa-f]{4,8})`)
	tailRe := regexp.MustCompile(`(?i)sub_([0-9A-Fa-f]{4,8}).*tailcalls\s+sub_([0-9A-Fa-f]{4,8})`)

	type subRef struct {
		addr string
		name string
	}

	resolveName := func(addr string) string {
		if n, ok := addrName[strings.ToLower(addr)]; ok && strings.TrimSpace(n) != "" {
			return n
		}
		if v := parseHex(addr); v > 0 && v < 0x100000 {
			if n, ok := addrName[fmt.Sprintf("0x%x", v+0x100000)]; ok {
				return n
			}
		}
		return "sub_" + strings.TrimPrefix(strings.ToLower(addr), "0x")
	}

	extractRefs := func(line string) []subRef {
		matches := callSub.FindAllStringSubmatch(line, -1)
		refs := make([]subRef, 0, len(matches))
		for _, m := range matches {
			if len(m) < 2 {
				continue
			}
			addr := "0x" + strings.ToLower(m[1])
			name := ""
			if len(m) >= 3 {
				name = strings.TrimSpace(m[2])
			}
			if name == "" {
				name = resolveName(addr)
			}
			refs = append(refs, subRef{addr: addr, name: name})
		}
		return refs
	}

	var currentAddr string
	var currentName string

	edges := make([]CallEdgeRecord, 0, 4096)
	addEdge := func(srcAddr, srcName, dstAddr, dstName, evidence, source string, confidence float64) {
		if srcAddr == "" || dstAddr == "" {
			return
		}
		if strings.EqualFold(srcAddr, dstAddr) {
			return
		}
		if strings.TrimSpace(srcName) == "" {
			srcName = resolveName(srcAddr)
		}
		if strings.TrimSpace(dstName) == "" {
			dstName = resolveName(dstAddr)
		}
		edges = append(edges, CallEdgeRecord{
			SchemaVersion: schemaVersion,
			Image:         baseImage,
			SourceAddr:    srcAddr,
			SourceName:    srcName,
			TargetAddr:    dstAddr,
			TargetName:    dstName,
			Evidence:      trimForContext(evidence),
			Source:        source,
			Confidence:    confidence,
		})
	}

	s := bufio.NewScanner(f)
	s.Buffer(make([]byte, 1024), 2*1024*1024)
	for s.Scan() {
		line := strings.TrimSpace(s.Text())
		if line == "" {
			continue
		}

		if m := fnDef.FindStringSubmatch(line); len(m) == 3 {
			currentAddr = "0x" + strings.ToLower(m[1])
			currentName = m[2]
		}

		if m := thunkRe.FindStringSubmatch(line); len(m) == 3 {
			srcAddr := "0x" + strings.ToLower(m[1])
			dstAddr := "0x" + strings.ToLower(m[2])
			addEdge(srcAddr, resolveName(srcAddr), dstAddr, resolveName(dstAddr), line, "re_notes_thunk", 0.92)
		}
		if m := tailRe.FindStringSubmatch(line); len(m) == 3 {
			srcAddr := "0x" + strings.ToLower(m[1])
			dstAddr := "0x" + strings.ToLower(m[2])
			addEdge(srcAddr, resolveName(srcAddr), dstAddr, resolveName(dstAddr), line, "re_notes_tailcall", 0.9)
		}

		refs := extractRefs(line)
		if len(refs) == 0 {
			continue
		}

		lower := strings.ToLower(line)

		if strings.Contains(lower, "called from") && currentAddr != "" {
			for _, r := range refs {
				addEdge(r.addr, r.name, currentAddr, currentName, line, "re_notes_called_from", 0.82)
			}
		}

		if strings.Contains(lower, "calls") {
			srcAddr := currentAddr
			srcName := currentName
			start := 0
			if strings.HasPrefix(lower, "- sub_") || strings.HasPrefix(lower, "sub_") {
				srcAddr = refs[0].addr
				srcName = refs[0].name
				start = 1
			}
			if srcAddr != "" {
				for i := start; i < len(refs); i++ {
					addEdge(srcAddr, srcName, refs[i].addr, refs[i].name, line, "re_notes_calls", 0.8)
				}
			}
		}

		if strings.Contains(line, "→") || strings.Contains(line, "->") {
			if len(refs) >= 2 {
				for i := 0; i < len(refs)-1; i++ {
					addEdge(refs[i].addr, refs[i].name, refs[i+1].addr, refs[i+1].name, line, "re_notes_chain", 0.72)
				}
			} else if len(refs) == 1 && currentAddr != "" {
				addEdge(currentAddr, currentName, refs[0].addr, refs[0].name, line, "re_notes_chain", 0.7)
			}
		}
	}
	if err := s.Err(); err != nil {
		return nil, fmt.Errorf("scan notes for call edges: %w", err)
	}

	return dedupeCallEdges(edges), nil
}

func inferMessageSchema(functions []FunctionRecord, edges []CallEdgeRecord) []MessageSchemaRecord {
	baseImage := primaryImageFromFunctions(functions)
	outgoing := map[string]int{}
	for _, e := range edges {
		k := strings.ToLower(e.SourceAddr)
		outgoing[k]++
	}

	suffixMap := []struct {
		suffix string
		kind   string
	}{
		{"_req_handler", "request_handler"},
		{"_cfm_handler", "confirm_handler"},
		{"_ind_handler", "indication_handler"},
		{"_msg_handler", "message_handler"},
		{"_evt", "event"},
		{"_dispatch", "dispatch"},
		{"_parse", "parser"},
		{"_timer", "timer"},
	}

	rows := make([]MessageSchemaRecord, 0, 512)
	for _, fn := range functions {
		if baseImage != "" && fn.Image != baseImage {
			continue
		}
		name := strings.ToLower(strings.TrimSpace(fn.Name))
		if name == "" || strings.HasPrefix(name, "sub_") {
			continue
		}

		kind := ""
		for _, m := range suffixMap {
			if strings.Contains(name, m.suffix) {
				kind = m.kind
				break
			}
		}
		if kind == "" && !strings.Contains(name, "msg") {
			continue
		}
		if kind == "" {
			kind = "message_related"
		}

		family := name
		if idx := strings.Index(family, "_"); idx > 0 {
			family = family[:idx]
		}

		msgKey := strings.ToUpper(family + "_" + kind + "_" + strings.ReplaceAll(name, "_", "-"))
		conf := fn.Confidence + 0.05
		if conf > 0.95 {
			conf = 0.95
		}

		rows = append(rows, MessageSchemaRecord{
			SchemaVersion: schemaVersion,
			Image:         fn.Image,
			MessageKey:    msgKey,
			Family:        family,
			Kind:          kind,
			HandlerName:   fn.Name,
			HandlerAddr:   fn.Address,
			Role:          fn.Role,
			OutgoingCalls: outgoing[strings.ToLower(fn.Address)],
			Confidence:    conf,
			Source:        "function_name_inference",
		})
	}

	sort.Slice(rows, func(i, j int) bool {
		if rows[i].Family == rows[j].Family {
			if rows[i].Kind == rows[j].Kind {
				return rows[i].HandlerName < rows[j].HandlerName
			}
			return rows[i].Kind < rows[j].Kind
		}
		return rows[i].Family < rows[j].Family
	})

	return dedupeMessageSchema(rows)
}

func generateTwinScaffold(root string, outDir string, functions []FunctionRecord, edges []CallEdgeRecord, schemas []MessageSchemaRecord, patches []PatchEntryRecord) error {
	baseImage := primaryImageFromFunctions(functions)
	genRoot := filepath.Join(outDir, "generated_twin")
	incDir := filepath.Join(genRoot, "include")
	srcDir := filepath.Join(genRoot, "src")
	if err := os.MkdirAll(incDir, 0o755); err != nil {
		return fmt.Errorf("create include dir: %w", err)
	}
	if err := os.MkdirAll(srcDir, 0o755); err != nil {
		return fmt.Errorf("create src dir: %w", err)
	}

	selected := make([]FunctionRecord, 0, len(functions))
	for _, fn := range functions {
		if baseImage != "" && fn.Image != baseImage {
			continue
		}
		if strings.HasPrefix(strings.ToLower(fn.Name), "sub_") || fn.Name == "" {
			continue
		}
		if fn.Confidence < 0.75 {
			continue
		}
		selected = append(selected, fn)
	}

	byRole := map[string][]FunctionRecord{}
	for _, fn := range selected {
		role := fn.Role
		if role == "" {
			role = "unknown"
		}
		byRole[role] = append(byRole[role], fn)
	}

	roles := make([]string, 0, len(byRole))
	for role := range byRole {
		roles = append(roles, role)
	}
	sort.Strings(roles)

	headerPath := filepath.Join(incDir, "fw_twin_contracts.h")
	var hb strings.Builder
	hb.WriteString("#ifndef FW_TWIN_CONTRACTS_H\n")
	hb.WriteString("#define FW_TWIN_CONTRACTS_H\n\n")
	hb.WriteString("#include <stdint.h>\n\n")
	hb.WriteString(fmt.Sprintf("#define FW_TWIN_FUNCTIONS %d\n", len(selected)))
	hb.WriteString(fmt.Sprintf("#define FW_TWIN_CALL_EDGES %d\n", len(edges)))
	hb.WriteString(fmt.Sprintf("#define FW_TWIN_MESSAGE_SCHEMAS %d\n", len(schemas)))
	hb.WriteString(fmt.Sprintf("#define FW_TWIN_PATCH_ENTRIES %d\n\n", len(patches)))
	hb.WriteString("typedef struct fw_msg_desc {\n")
	hb.WriteString("    const char *key;\n")
	hb.WriteString("    const char *family;\n")
	hb.WriteString("    const char *kind;\n")
	hb.WriteString("    const char *handler;\n")
	hb.WriteString("    uint32_t handler_addr;\n")
	hb.WriteString("} fw_msg_desc_t;\n\n")

	seenProto := map[string]struct{}{}
	for _, fn := range selected {
		proto := fmt.Sprintf("int fw_%s(void *ctx);", fn.Name)
		if _, ok := seenProto[proto]; ok {
			continue
		}
		seenProto[proto] = struct{}{}
		hb.WriteString(proto)
		hb.WriteByte('\n')
	}
	hb.WriteString("\n#endif\n")
	if err := fileio.WriteBytes(headerPath, []byte(hb.String())); err != nil {
		return fmt.Errorf("write contracts header: %w", err)
	}

	sourceFiles := make([]string, 0, len(roles)+1)
	for _, role := range roles {
		funcs := byRole[role]
		sort.Slice(funcs, func(i, j int) bool {
			if funcs[i].Confidence == funcs[j].Confidence {
				return funcs[i].Name < funcs[j].Name
			}
			return funcs[i].Confidence > funcs[j].Confidence
		})
		if len(funcs) > 40 {
			funcs = funcs[:40]
		}

		fileName := "fw_role_" + sanitizeRole(role) + ".c"
		path := filepath.Join(srcDir, fileName)
		var sb strings.Builder
		sb.WriteString("#include \"fw_twin_contracts.h\"\n\n")
		sb.WriteString(fmt.Sprintf("/* role: %s */\n", role))
		for _, fn := range funcs {
			sb.WriteString(fmt.Sprintf("/* original: %s %s */\n", fn.Address, fn.Name))
			sb.WriteString(fmt.Sprintf("int fw_%s(void *ctx) {\n", fn.Name))
			sb.WriteString("    (void)ctx;\n")
			sb.WriteString("    return 0;\n")
			sb.WriteString("}\n\n")
		}
		if err := fileio.WriteBytes(path, []byte(sb.String())); err != nil {
			return fmt.Errorf("write source %s: %w", fileName, err)
		}
		sourceFiles = append(sourceFiles, path)
	}

	var roleCounts []map[string]any
	for _, role := range roles {
		roleCounts = append(roleCounts, map[string]any{"role": role, "count": len(byRole[role])})
	}

	plan := TwinPlan{
		SchemaVersion: schemaVersion,
		GeneratedAt:   time.Now().UTC().Format(time.RFC3339),
		Root:          root,
		OutDir:        genRoot,
		FunctionCount: len(selected),
		CallEdgeCount: len(edges),
		MessageCount:  len(schemas),
		PatchCount:    len(patches),
		RoleCounts:    roleCounts,
		SourceFiles:   sourceFiles,
		Headers:       []string{headerPath},
		Notes: []string{
			"Generated scaffold is a behavioral twin bootstrap, not original source recovery.",
			"Stubs are grouped by inferred role and should be replaced with reconstructed logic incrementally.",
		},
	}

	b, err := json.MarshalIndent(plan, "", "  ")
	if err != nil {
		return fmt.Errorf("marshal twin plan: %w", err)
	}
	if err := fileio.WriteBytes(filepath.Join(genRoot, "twin_plan.json"), append(b, '\n')); err != nil {
		return fmt.Errorf("write twin plan: %w", err)
	}

	readme := "# Generated Firmware Twin Scaffold\n\n" +
		"This folder contains generated C stubs and contracts from extraction artifacts.\n\n" +
		"- `include/fw_twin_contracts.h`: extracted API contract surface\n" +
		"- `src/fw_role_*.c`: role-grouped stub implementations\n" +
		"- `twin_plan.json`: machine-readable generation plan and counts\n"
	if err := fileio.WriteBytes(filepath.Join(genRoot, "README.md"), []byte(readme)); err != nil {
		return fmt.Errorf("write twin readme: %w", err)
	}

	return nil
}

func buildMiningQueue(functions []FunctionRecord, edges []CallEdgeRecord, links []FunctionLinkRecord, schemas []MessageSchemaRecord, learning LearningBundle, limit int, minScore float64) []MiningTargetRecord {
	weights := loadMiningWeightsFromEnv()

	outDeg := map[string]int{}
	inDeg := map[string]int{}
	for _, e := range edges {
		src := strings.ToLower(e.SourceAddr)
		dst := strings.ToLower(e.TargetAddr)
		outDeg[src]++
		inDeg[dst]++
	}

	linkDeg := map[string]int{}
	outLinksBySource := map[string][]FunctionLinkRecord{}
	for _, l := range links {
		k := strings.ToLower(l.SourceImage + "|" + l.SourceAddress)
		linkDeg[k]++
		outLinksBySource[k] = append(outLinksBySource[k], l)
	}

	msgHits := map[string]int{}
	for _, m := range schemas {
		msgHits[strings.ToLower(m.Image+"|"+m.HandlerAddr)]++
	}

	queue := make([]MiningTargetRecord, 0, len(functions)+len(links))
	seen := map[string]int{}
	functionByImageAddr := map[string]FunctionRecord{}
	for _, fn := range functions {
		functionByImageAddr[strings.ToLower(fn.Image+"|"+fn.Address)] = fn
	}
	resolveSourceFn := func(image string, addr string) (FunctionRecord, bool) {
		addr = strings.ToLower(strings.TrimSpace(addr))
		key := strings.ToLower(image + "|" + addr)
		if fn, ok := functionByImageAddr[key]; ok {
			return fn, true
		}
		v := parseHex(addr)
		if v > 0 && v < 0x100000 {
			key2 := strings.ToLower(image + "|" + fmt.Sprintf("0x%x", v+0x100000))
			if fn, ok := functionByImageAddr[key2]; ok {
				return fn, true
			}
		}
		if v >= 0x100000 {
			key3 := strings.ToLower(image + "|" + fmt.Sprintf("0x%x", v-0x100000))
			if fn, ok := functionByImageAddr[key3]; ok {
				return fn, true
			}
		}
		return FunctionRecord{}, false
	}
	addOrUpdate := func(row MiningTargetRecord) {
		k := strings.ToLower(row.Image + "|" + row.Address + "|" + row.Name)
		if idx, ok := seen[k]; ok {
			if row.PriorityScore > queue[idx].PriorityScore {
				queue[idx] = row
			}
			return
		}
		seen[k] = len(queue)
		queue = append(queue, row)
	}

	for _, fn := range functions {
		addr := strings.ToLower(fn.Address)
		name := strings.TrimSpace(fn.Name)
		if name == "" {
			continue
		}
		imageAddr := strings.ToLower(fn.Image + "|" + fn.Address)

		od := outDeg[addr]
		id := inDeg[addr]
		ld := linkDeg[imageAddr]
		mh := msgHits[imageAddr]

		score := 0.0
		reasons := make([]string, 0, 6)
		if fn.Role == "unknown" {
			score += weights.UnknownRole
			reasons = append(reasons, "unknown_role")
		}
		if fn.Confidence < 0.7 {
			score += weights.LowConfidence
			reasons = append(reasons, "low_confidence")
		}
		if strings.HasPrefix(strings.ToLower(name), "sub_") {
			score += weights.UnnamedFunction
			reasons = append(reasons, "unnamed_function")
		}
		if od > 0 {
			score += float64(od) * weights.Fanout
			reasons = append(reasons, "fanout")
		}
		if id > 0 {
			score += float64(id) * weights.Fanin
			reasons = append(reasons, "fanin")
		}
		if ld > 0 {
			score += float64(ld) * weights.CrossImageAnchor
			reasons = append(reasons, "cross_image_anchor")
		}
		if mh > 0 {
			score += float64(mh) * weights.MessagePath
			reasons = append(reasons, "message_path")
		}
		if fn.Role == "radio" || fn.Role == "transport" || fn.Role == "patching" {
			score += weights.CriticalSubsystem
			reasons = append(reasons, "critical_subsystem")
		}
		if sig, ok := learning.ByFunction[strings.ToLower(fn.Image+"|"+fn.Name)]; ok {
			score += sig.Weight
			reasons = append(reasons, sig.Reason)
		}
		if ps, ok := learning.ByPrefix[functionPrefix(fn.Name)]; ok {
			score += ps.Weight
			reasons = append(reasons, ps.Reason)
		}
		obs := learning.OutcomeByFunction[strings.ToLower(fn.Image+"|"+fn.Name)]
		if obs.Seen == 0 {
			score += weights.NoveltyUnseenBonus
			reasons = append(reasons, "novelty_unseen")
		} else {
			score -= float64(obs.Seen) * weights.NoveltySeenPenalty
			if obs.Success > 1 {
				score -= float64(obs.Success-1) * weights.NoveltySuccessDecay
				reasons = append(reasons, "novelty_repeat_success_decay")
			}
			if obs.Fault > 0 {
				score += float64(obs.Fault) * weights.NoveltyFaultRecovery
				reasons = append(reasons, "novelty_fault_recovery")
			}
			if obs.Missing > 0 {
				score -= float64(obs.Missing) * weights.NoveltyMissingPenalty
				reasons = append(reasons, "novelty_missing_symbol_penalty")
			}
		}

		if score < minScore {
			continue
		}

		addOrUpdate(MiningTargetRecord{
			SchemaVersion: schemaVersion,
			Image:         fn.Image,
			Address:       fn.Address,
			Name:          fn.Name,
			Role:          fn.Role,
			Confidence:    fn.Confidence,
			OutDegree:     od,
			InDegree:      id,
			LinkDegree:    ld,
			MessageHits:   mh,
			PriorityScore: score,
			Reasons:       uniqueStrings(reasons),
		})
	}

	// Cross-image mining expansion: project high-confidence linked targets into frontier.
	for _, l := range links {
		srcFn, ok := resolveSourceFn(l.SourceImage, l.SourceAddress)
		if !ok {
			continue
		}
		role := srcFn.Role
		if role == "" || role == "unknown" {
			role = inferRole(l.SourceName)
		}
		score := weights.CrossImageProjectionBase + l.Confidence*weights.CrossImageProjectionScale
		reasons := []string{"cross_image_projection", "cross_image_anchor"}
		if strings.HasPrefix(strings.ToLower(l.SourceName), "sub_") {
			reasons = append(reasons, "unnamed_function")
			score += weights.CrossImageUnnamedBonus
		}
		if role == "radio" || role == "transport" || role == "patching" {
			reasons = append(reasons, "critical_subsystem")
			score += weights.CrossImageCriticalBonus
		}
		if score < minScore {
			continue
		}
		targetName := l.SourceName
		if strings.TrimSpace(targetName) == "" {
			targetName = "sub_" + strings.TrimPrefix(strings.ToLower(l.TargetAddress), "0x")
		}
		addOrUpdate(MiningTargetRecord{
			SchemaVersion: schemaVersion,
			Image:         l.TargetImage,
			Address:       l.TargetAddress,
			Name:          targetName,
			Role:          role,
			Confidence:    l.Confidence,
			OutDegree:     0,
			InDegree:      0,
			LinkDegree:    1,
			MessageHits:   0,
			PriorityScore: score,
			Reasons:       uniqueStrings(reasons),
		})
	}

	// Second-hop expansion: project from first-hop targets into their own linked images.
	for _, l1 := range links {
		srcFn, ok := resolveSourceFn(l1.SourceImage, l1.SourceAddress)
		if !ok {
			continue
		}
		role := srcFn.Role
		if role == "" || role == "unknown" {
			role = inferRole(l1.SourceName)
		}

		// Use normalized source name for target identity propagation.
		propagatedName := strings.TrimSpace(l1.SourceName)
		if propagatedName == "" {
			propagatedName = "sub_" + strings.TrimPrefix(strings.ToLower(l1.TargetAddress), "0x")
		}
		hopSourceKey := strings.ToLower(l1.TargetImage + "|" + l1.TargetAddress)
		secondLinks := outLinksBySource[hopSourceKey]
		if len(secondLinks) == 0 {
			continue
		}
		for _, l2 := range secondLinks {
			// Avoid degenerate self-cycle on exact same image+addr.
			if strings.EqualFold(l1.TargetImage, l2.TargetImage) && strings.EqualFold(l1.TargetAddress, l2.TargetAddress) {
				continue
			}
			score := weights.Hop2Base + (l1.Confidence*l2.Confidence)*weights.Hop2Scale
			reasons := []string{"cross_image_projection_hop2", "cross_image_anchor"}
			if role == "radio" || role == "transport" || role == "patching" {
				reasons = append(reasons, "critical_subsystem")
				score += weights.Hop2CriticalBonus
			}
			if strings.HasPrefix(strings.ToLower(propagatedName), "sub_") {
				reasons = append(reasons, "unnamed_function")
				score += weights.Hop2UnnamedBonus
			}
			if score < minScore {
				continue
			}
			addOrUpdate(MiningTargetRecord{
				SchemaVersion: schemaVersion,
				Image:         l2.TargetImage,
				Address:       l2.TargetAddress,
				Name:          propagatedName,
				Role:          role,
				Confidence:    l1.Confidence * l2.Confidence,
				OutDegree:     0,
				InDegree:      0,
				LinkDegree:    1,
				MessageHits:   0,
				PriorityScore: score,
				Reasons:       uniqueStrings(reasons),
			})
		}
	}

	// Neighborhood expansion: mine likely nearby function starts around projected anchors.
	neighborMax := envInt64("FW_MINING_NEIGHBOR_MAX", 0x200)
	neighborStep := envInt64("FW_MINING_NEIGHBOR_STEP", 2)
	if neighborMax < 2 {
		neighborMax = 2
	}
	if neighborStep < 1 {
		neighborStep = 1
	}
	neighborOffsets := make([]int64, 0, int((neighborMax/neighborStep)*2))
	for off := neighborStep; off <= neighborMax; off += neighborStep {
		neighborOffsets = append(neighborOffsets, -off, off)
	}
	for _, l := range links {
		srcFn, ok := resolveSourceFn(l.SourceImage, l.SourceAddress)
		if !ok {
			continue
		}
		role := srcFn.Role
		if role == "" || role == "unknown" {
			role = inferRole(l.SourceName)
		}
		baseAddr := int64(parseHex(l.TargetAddress))
		if baseAddr <= 0 {
			continue
		}
		for _, off := range neighborOffsets {
			na := baseAddr + off
			if na <= 0 {
				continue
			}
			addr := fmt.Sprintf("0x%x", uint64(na))
			score := weights.NeighborhoodBase + l.Confidence*weights.NeighborhoodScale
			reasons := []string{"cross_image_neighborhood", "cross_image_anchor"}
			if role == "radio" || role == "transport" || role == "patching" {
				reasons = append(reasons, "critical_subsystem")
				score += weights.NeighborhoodCriticalBonus
			}
			if score < minScore {
				continue
			}
			name := strings.TrimSpace(l.SourceName)
			if name == "" {
				name = "sub_" + strings.TrimPrefix(strings.ToLower(addr), "0x")
			} else {
				name = name + "_n" + strings.TrimPrefix(strings.ToLower(fmt.Sprintf("%+x", off)), "+")
			}
			addOrUpdate(MiningTargetRecord{
				SchemaVersion: schemaVersion,
				Image:         l.TargetImage,
				Address:       addr,
				Name:          name,
				Role:          role,
				Confidence:    l.Confidence * 0.9,
				OutDegree:     0,
				InDegree:      0,
				LinkDegree:    1,
				MessageHits:   0,
				PriorityScore: score,
				Reasons:       uniqueStrings(reasons),
			})
		}
	}

	sort.Slice(queue, func(i, j int) bool {
		if queue[i].PriorityScore == queue[j].PriorityScore {
			return parseHex(queue[i].Address) < parseHex(queue[j].Address)
		}
		return queue[i].PriorityScore > queue[j].PriorityScore
	})

	if limit > 0 && len(queue) > limit {
		queue = queue[:limit]
	}
	return queue
}

func dedupeCallEdges(in []CallEdgeRecord) []CallEdgeRecord {
	m := make(map[string]CallEdgeRecord, len(in))
	for _, e := range in {
		k := strings.ToLower(e.Image + "|" + e.SourceAddr + "|" + e.TargetAddr)
		if old, ok := m[k]; ok {
			if e.Confidence > old.Confidence {
				m[k] = e
			}
			continue
		}
		m[k] = e
	}
	out := make([]CallEdgeRecord, 0, len(m))
	for _, v := range m {
		out = append(out, v)
	}
	sort.Slice(out, func(i, j int) bool {
		if out[i].SourceAddr == out[j].SourceAddr {
			return out[i].TargetAddr < out[j].TargetAddr
		}
		return parseHex(out[i].SourceAddr) < parseHex(out[j].SourceAddr)
	})
	return out
}

func dedupeMessageSchema(in []MessageSchemaRecord) []MessageSchemaRecord {
	m := make(map[string]MessageSchemaRecord, len(in))
	for _, r := range in {
		k := strings.ToLower(r.Image + "|" + r.HandlerAddr + "|" + r.Kind)
		if old, ok := m[k]; ok {
			if r.Confidence > old.Confidence {
				m[k] = r
			}
			continue
		}
		m[k] = r
	}
	out := make([]MessageSchemaRecord, 0, len(m))
	for _, v := range m {
		out = append(out, v)
	}
	return out
}

func buildFamilyConsensus(functions []FunctionRecord, links []FunctionLinkRecord, edges []CallEdgeRecord, schemas []MessageSchemaRecord) []FamilyConsensusRecord {
	fnByName := map[string][]FunctionRecord{}
	for _, fn := range functions {
		n := normalizeConsensusName(fn.Name)
		if n == "" || n == "unknown" {
			continue
		}
		fnByName[n] = append(fnByName[n], fn)
	}

	outgoingByName := map[string]map[string]consensusCallVote{}
	for _, e := range edges {
		if e.Confidence < 0.55 {
			continue
		}
		src := normalizeConsensusName(e.SourceName)
		tgt := normalizeConsensusName(e.TargetName)
		if src == "" || src == "unknown" || tgt == "" || tgt == "unknown" || src == tgt {
			continue
		}
		if outgoingByName[src] == nil {
			outgoingByName[src] = map[string]consensusCallVote{}
		}
		cur := outgoingByName[src][tgt]
		cur.count++
		cur.conf += e.Confidence
		outgoingByName[src][tgt] = cur
	}

	familyByName := map[string]map[string]struct{}{}
	kindByName := map[string]map[string]struct{}{}
	for _, s := range schemas {
		h := normalizeConsensusName(s.HandlerName)
		if h == "" || h == "unknown" {
			continue
		}
		if familyByName[h] == nil {
			familyByName[h] = map[string]struct{}{}
		}
		if kindByName[h] == nil {
			kindByName[h] = map[string]struct{}{}
		}
		if strings.TrimSpace(s.Family) != "" {
			familyByName[h][s.Family] = struct{}{}
		}
		if strings.TrimSpace(s.Kind) != "" {
			kindByName[h][s.Kind] = struct{}{}
		}
	}

	grouped := map[string][]FunctionLinkRecord{}
	for _, l := range links {
		n := normalizeConsensusName(l.SourceName)
		if n == "" || n == "unknown" || strings.HasPrefix(n, "sub_") {
			continue
		}
		grouped[n] = append(grouped[n], l)
	}

	out := make([]FamilyConsensusRecord, 0, len(grouped))
	for name, rows := range grouped {
		imgSet := map[string]struct{}{}
		roleSet := map[string]struct{}{}
		avgConf := 0.0
		for _, r := range rows {
			if strings.TrimSpace(r.SourceImage) != "" {
				imgSet[r.SourceImage] = struct{}{}
			}
			if strings.TrimSpace(r.TargetImage) != "" {
				imgSet[r.TargetImage] = struct{}{}
			}
			avgConf += r.Confidence
		}
		for _, fn := range fnByName[name] {
			if strings.TrimSpace(fn.Role) == "" {
				continue
			}
			roleSet[fn.Role] = struct{}{}
			imgSet[fn.Image] = struct{}{}
		}
		if len(imgSet) < 2 {
			continue
		}
		avgConf /= float64(len(rows))

		memberImages := setToSortedList(imgSet)
		roles := setToSortedList(roleSet)
		families := setToSortedList(familyByName[name])
		kinds := setToSortedList(kindByName[name])
		topCalls := topConsensusOutgoing(outgoingByName[name], 6)
		conf := 0.45 + (avgConf * 0.35)
		if len(memberImages) >= 3 {
			conf += 0.10
		}
		if len(topCalls) > 0 {
			conf += 0.05
		}
		if conf > 0.99 {
			conf = 0.99
		}
		out = append(out, FamilyConsensusRecord{
			SchemaVersion:       schemaVersion,
			CanonicalFunction:   name,
			ImageCount:          len(memberImages),
			LinkCount:           len(rows),
			AvgLinkConfidence:   round3Local(avgConf),
			ConsensusConfidence: round3Local(conf),
			MemberImages:        memberImages,
			RoleHints:           roles,
			TopOutgoingCalls:    topCalls,
			MessageFamilies:     families,
			MessageKinds:        kinds,
		})
	}

	sort.Slice(out, func(i, j int) bool {
		if out[i].ImageCount == out[j].ImageCount {
			if out[i].ConsensusConfidence == out[j].ConsensusConfidence {
				return out[i].CanonicalFunction < out[j].CanonicalFunction
			}
			return out[i].ConsensusConfidence > out[j].ConsensusConfidence
		}
		return out[i].ImageCount > out[j].ImageCount
	})
	return out
}

func setToSortedList(set map[string]struct{}) []string {
	if len(set) == 0 {
		return nil
	}
	out := make([]string, 0, len(set))
	for k := range set {
		if strings.TrimSpace(k) == "" {
			continue
		}
		out = append(out, k)
	}
	sort.Strings(out)
	return out
}

func topConsensusOutgoing(votes map[string]consensusCallVote, n int) []string {
	if len(votes) == 0 || n <= 0 {
		return nil
	}
	type kv struct {
		name  string
		score float64
	}
	items := make([]kv, 0, len(votes))
	for name, v := range votes {
		score := float64(v.count) + (v.conf * 0.25)
		items = append(items, kv{name: name, score: score})
	}
	sort.Slice(items, func(i, j int) bool {
		if items[i].score == items[j].score {
			return items[i].name < items[j].name
		}
		return items[i].score > items[j].score
	})
	if len(items) > n {
		items = items[:n]
	}
	out := make([]string, 0, len(items))
	for _, it := range items {
		out = append(out, it.name)
	}
	return out
}

func normalizeConsensusName(s string) string {
	s = strings.TrimSpace(strings.ToLower(s))
	if s == "" {
		return ""
	}
	var b strings.Builder
	for _, r := range s {
		if (r >= 'a' && r <= 'z') || (r >= '0' && r <= '9') || r == '_' {
			b.WriteRune(r)
		} else {
			b.WriteByte('_')
		}
	}
	return strings.Trim(b.String(), "_")
}

func round3Local(v float64) float64 {
	return float64(int(v*1000+0.5)) / 1000
}

func sanitizeRole(role string) string {
	role = strings.ToLower(role)
	role = strings.ReplaceAll(role, "-", "_")
	role = strings.ReplaceAll(role, " ", "_")
	if role == "" {
		return "unknown"
	}
	return role
}

func uniqueStrings(in []string) []string {
	m := map[string]struct{}{}
	out := make([]string, 0, len(in))
	for _, s := range in {
		if _, ok := m[s]; ok {
			continue
		}
		m[s] = struct{}{}
		out = append(out, s)
	}
	return out
}

func envInt64(name string, def int64) int64 {
	raw := strings.TrimSpace(os.Getenv(name))
	if raw == "" {
		return def
	}
	base := 10
	valText := raw
	if strings.HasPrefix(strings.ToLower(raw), "0x") {
		base = 16
		valText = raw[2:]
	}
	v, err := strconv.ParseInt(valText, base, 64)
	if err != nil {
		return def
	}
	return v
}

type miningWeights struct {
	UnknownRole               float64
	LowConfidence             float64
	UnnamedFunction           float64
	Fanout                    float64
	Fanin                     float64
	CrossImageAnchor          float64
	MessagePath               float64
	CriticalSubsystem         float64
	CrossImageProjectionBase  float64
	CrossImageProjectionScale float64
	CrossImageUnnamedBonus    float64
	CrossImageCriticalBonus   float64
	Hop2Base                  float64
	Hop2Scale                 float64
	Hop2CriticalBonus         float64
	Hop2UnnamedBonus          float64
	NeighborhoodBase          float64
	NeighborhoodScale         float64
	NeighborhoodCriticalBonus float64
	NoveltyUnseenBonus        float64
	NoveltySeenPenalty        float64
	NoveltySuccessDecay       float64
	NoveltyFaultRecovery      float64
	NoveltyMissingPenalty     float64
}

func loadMiningWeightsFromEnv() miningWeights {
	return miningWeights{
		UnknownRole:               envFloat64("FW_MINING_SCORE_UNKNOWN_ROLE", 3.0),
		LowConfidence:             envFloat64("FW_MINING_SCORE_LOW_CONFIDENCE", 2.0),
		UnnamedFunction:           envFloat64("FW_MINING_SCORE_UNNAMED", 2.5),
		Fanout:                    envFloat64("FW_MINING_SCORE_FANOUT", 0.35),
		Fanin:                     envFloat64("FW_MINING_SCORE_FANIN", 0.25),
		CrossImageAnchor:          envFloat64("FW_MINING_SCORE_CROSS_IMAGE_ANCHOR", 0.2),
		MessagePath:               envFloat64("FW_MINING_SCORE_MESSAGE_PATH", 0.5),
		CriticalSubsystem:         envFloat64("FW_MINING_SCORE_CRITICAL_SUBSYSTEM", 0.4),
		CrossImageProjectionBase:  envFloat64("FW_MINING_SCORE_PROJECTION_BASE", 0.9),
		CrossImageProjectionScale: envFloat64("FW_MINING_SCORE_PROJECTION_SCALE", 2.2),
		CrossImageUnnamedBonus:    envFloat64("FW_MINING_SCORE_PROJECTION_UNNAMED", 0.4),
		CrossImageCriticalBonus:   envFloat64("FW_MINING_SCORE_PROJECTION_CRITICAL", 0.2),
		Hop2Base:                  envFloat64("FW_MINING_SCORE_HOP2_BASE", 0.55),
		Hop2Scale:                 envFloat64("FW_MINING_SCORE_HOP2_SCALE", 1.9),
		Hop2CriticalBonus:         envFloat64("FW_MINING_SCORE_HOP2_CRITICAL", 0.15),
		Hop2UnnamedBonus:          envFloat64("FW_MINING_SCORE_HOP2_UNNAMED", 0.2),
		NeighborhoodBase:          envFloat64("FW_MINING_SCORE_NEIGHBOR_BASE", 0.35),
		NeighborhoodScale:         envFloat64("FW_MINING_SCORE_NEIGHBOR_SCALE", 1.35),
		NeighborhoodCriticalBonus: envFloat64("FW_MINING_SCORE_NEIGHBOR_CRITICAL", 0.1),
		NoveltyUnseenBonus:        envFloat64("FW_MINING_SCORE_NOVELTY_UNSEEN_BONUS", 0.55),
		NoveltySeenPenalty:        envFloat64("FW_MINING_SCORE_NOVELTY_SEEN_PENALTY", 0.05),
		NoveltySuccessDecay:       envFloat64("FW_MINING_SCORE_NOVELTY_SUCCESS_DECAY", 0.18),
		NoveltyFaultRecovery:      envFloat64("FW_MINING_SCORE_NOVELTY_FAULT_RECOVERY", 0.22),
		NoveltyMissingPenalty:     envFloat64("FW_MINING_SCORE_NOVELTY_MISSING_PENALTY", 0.08),
	}
}

func envFloat64(name string, def float64) float64 {
	raw := strings.TrimSpace(os.Getenv(name))
	if raw == "" {
		return def
	}
	v, err := strconv.ParseFloat(raw, 64)
	if err != nil {
		return def
	}
	return v
}
