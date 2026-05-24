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
	"strings"
	"time"
)

type implTask struct {
	TaskID    string  `json:"task_id"`
	Function  string  `json:"function"`
	Image     string  `json:"image"`
	Address   string  `json:"address"`
	TaskClass string  `json:"task_class"`
	Priority  string  `json:"priority"`
	RankScore float64 `json:"rank_score"`
}

type callEdge struct {
	Image      string  `json:"image"`
	SourceAddr string  `json:"source_addr"`
	SourceName string  `json:"source_name"`
	TargetAddr string  `json:"target_addr"`
	TargetName string  `json:"target_name"`
	Confidence float64 `json:"confidence"`
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
	Function         string   `json:"function"`
	Image            string   `json:"image"`
	Address          string   `json:"address"`
	IncomingCount    int      `json:"incoming_count"`
	OutgoingCount    int      `json:"outgoing_count"`
	SelectedCount    int      `json:"selected_count"`
	TopIncoming      []string `json:"top_incoming"`
	TopOutgoing      []string `json:"top_outgoing"`
	InferredAlias    string   `json:"inferred_alias,omitempty"`
	InferredLeafCall []string `json:"inferred_leaf_calls,omitempty"`
}

var nameOutgoingHints map[string][]string

func main() {
	var implQueuePath string
	var callEdgesPath string
	var outDir string
	var composedDir string
	var maxTasks int
	var minConf float64
	var fallbackMinConf float64
	var includeDependencies bool

	flag.StringVar(&implQueuePath, "implqueue", "extraction_out/reconstruction/mega7/implqueue/implementation_queue.json", "Implementation queue JSON")
	flag.StringVar(&callEdgesPath, "call-edges", "extraction_out/call_edges.jsonl", "Call edges JSONL")
	flag.StringVar(&outDir, "out", "extraction_out/reconstruction/mega7/synth", "Output directory")
	flag.StringVar(&composedDir, "composed-dir", "extraction_out/reconstruction/mega7/composed", "Composed reconstruction directory for dependency hint fallback")
	flag.IntVar(&maxTasks, "max-tasks", 80, "Maximum synthesized behavior functions")
	flag.Float64Var(&minConf, "min-call-confidence", 0.7, "Minimum call edge confidence")
	flag.Float64Var(&fallbackMinConf, "fallback-min-call-confidence", 0.4, "Lower call edge confidence used only when no high-confidence callee is available")
	flag.BoolVar(&includeDependencies, "include-dependencies", true, "Include dependency_impl tasks after behavior_lift tasks")
	flag.Parse()

	iAbs, _ := filepath.Abs(implQueuePath)
	cAbs, _ := filepath.Abs(callEdgesPath)
	oAbs, _ := filepath.Abs(outDir)
	if err := os.MkdirAll(oAbs, 0o755); err != nil {
		fail("mkdir out: %v", err)
	}
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
	inAdj, outAdj, inByName, outByName, err := readAdj(cAbs, minConf)
	if err != nil {
		fail("read call edges: %v", err)
	}
	hints, composedCallers, _ := loadComposedHints(composedDir)
	familyHints := buildFamilyHints(outByName, minConf, fallbackMinConf)
	suffixHints := buildSuffixHints(outByName, minConf, fallbackMinConf)
	tokenHints := buildTokenHints(outByName, minConf, fallbackMinConf)
	imageHints := buildImageHints(inAdj, outAdj, minConf, fallbackMinConf)
	nameOutgoingHints = buildNameOutgoingHints(outByName, minConf, fallbackMinConf)

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

	totalCallees := 0
	evidence := make([]synthEvidenceRow, 0, len(synth))
	for i, t := range synth {
		incoming, outgoing := edgesForTask(t, inAdj, outAdj, inByName, outByName)
		sort.Slice(outgoing, func(a, b int) bool { return outgoing[a].Confidence > outgoing[b].Confidence })
		aggressive := allowSyntheticInference(t.Function, incoming, outgoing)
		selected := selectCallees(t, outgoing, outAdj, minConf, fallbackMinConf)
		if len(selected) == 0 {
			selected = inferFromNameOutgoingHints(t, minConf, fallbackMinConf)
		}
		if len(selected) == 0 {
			selected = inferFromIncoming(t, incoming, outAdj, outByName, minConf, fallbackMinConf)
		}
		if len(selected) == 0 {
			if aggressive {
				selected = inferFromComposedHints(t, hints)
			}
		}
		if len(selected) == 0 && aggressive {
			selected = inferFromComposedContext(t, hints, composedCallers)
		}
		if len(selected) == 0 && aggressive {
			selected = inferFromTokenHints(t, tokenHints)
		}
		if len(selected) == 0 && aggressive {
			selected = inferFromSuffixHints(t, suffixHints)
		}
		if len(selected) == 0 && aggressive {
			selected = inferFromFamilyHints(t, familyHints)
		}
		if len(selected) == 0 && aggressive {
			selected = inferFromImageHints(t, imageHints)
		}
		totalCallees += len(selected)
		fn := sanitizeName(t.Function)
		row := synthEvidenceRow{
			Function:      fn,
			Image:         t.Image,
			Address:       t.Address,
			IncomingCount: len(incoming),
			OutgoingCount: len(outgoing),
			SelectedCount: len(selected),
			TopIncoming:   topIncomingNames(incoming, 4),
			TopOutgoing:   topOutgoingNames(outgoing, 4),
		}
		if strings.HasPrefix(fn, "sub_") {
			role := functionRole(fn)
			if hint := callerRoleHint(incoming); hint != "" && (role == "shared helper" || role == "unnamed helper") {
				role = hint
			}
			row.InferredAlias = inferredSubAlias(fn, role, t.Image, incoming)
			row.InferredLeafCall = inferLeafCallsFromIncoming(fn, incoming)
		}
		evidence = append(evidence, row)
		file := filepath.Join(oAbs, fmt.Sprintf("%03d_%s.synth.c", i+1, sanitizeName(t.Function)))
		if err := writeSynth(file, t, incoming, selected); err != nil {
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
	mb, err := json.MarshalIndent(m, "", "  ")
	if err != nil {
		fail("marshal manifest: %v", err)
	}
	if err := os.WriteFile(filepath.Join(oAbs, "implsynth_manifest.json"), append(mb, '\n'), 0o644); err != nil {
		fail("write manifest: %v", err)
	}
	eb, err := json.MarshalIndent(evidence, "", "  ")
	if err != nil {
		fail("marshal evidence: %v", err)
	}
	if err := os.WriteFile(filepath.Join(oAbs, "implsynth_evidence.json"), append(eb, '\n'), 0o644); err != nil {
		fail("write evidence: %v", err)
	}
	fmt.Printf("implementation synthesis generated.\n")
	fmt.Printf("  synth_count: %d\n", m.SynthCount)
	fmt.Printf("  behavior_tasks_used: %d\n", m.BehaviorTaskUsed)
	fmt.Printf("  dependency_tasks_used: %d\n", m.DependencyTaskUsed)
	fmt.Printf("  avg_callee_emitted: %s\n", m.AvgCalleeEmitted)
	fmt.Printf("  evidence_path: %s\n", filepath.Join(oAbs, "implsynth_evidence.json"))
	fmt.Printf("  out_dir: %s\n", oAbs)
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
	f, err := os.Open(path)
	if err != nil {
		return nil, nil, nil, nil, err
	}
	defer f.Close()
	in := make(map[string][]callEdge, 4096)
	out := make(map[string][]callEdge, 4096)
	inName := make(map[string][]callEdge, 4096)
	outName := make(map[string][]callEdge, 4096)
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
		out[addrKey(e.Image, e.SourceAddr)] = append(out[addrKey(e.Image, e.SourceAddr)], e)
		in[addrKey(e.Image, e.TargetAddr)] = append(in[addrKey(e.Image, e.TargetAddr)], e)
		srcN := sanitizeName(e.SourceName)
		tgtN := sanitizeName(e.TargetName)
		if srcN != "" && srcN != "unknown" {
			outName[srcN] = append(outName[srcN], e)
		}
		if tgtN != "" && tgtN != "unknown" {
			inName[tgtN] = append(inName[tgtN], e)
		}
	}
	return in, out, inName, outName, sc.Err()
}

func writeSynth(path string, t implTask, incoming, outgoing []callEdge) error {
	var b strings.Builder
	b.WriteString("/* Auto-generated synthesized implementation pass */\n")
	b.WriteString(fmt.Sprintf("/* task=%s class=%s priority=%s score=%.3f */\n", t.TaskID, t.TaskClass, t.Priority, t.RankScore))
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
	b.WriteString(fmt.Sprintf("void %s(void) {\n", fn))
	seed := synthSeed(fn, t.Address)
	b.WriteString(fmt.Sprintf("  uint32_t state = 0x%08xU;\n", seed))
	b.WriteString(fmt.Sprintf("  state ^= ((uint32_t)%dU << 16) ^ ((uint32_t)%dU << 8);\n", len(incoming), len(outgoing)))
	if strings.HasPrefix(fn, "sub_") {
		if alias := inferredSubAlias(fn, role, t.Image, incoming); alias != "" {
			b.WriteString("  // inferred alias: " + alias + "\n")
		}
	}
	synthCalls := leafSyntheticCallees(fn, role, t.Image, incoming, outgoing)
	forceLeafTemplate := shouldPreferLeafTemplate(fn, outgoing, synthCalls)
	if len(outgoing) == 0 || forceLeafTemplate {
		if len(synthCalls) > 0 {
			b.WriteString(fmt.Sprintf("  // reconstructed micro-flow: %s\n", role))
			if len(incoming) > 0 {
				b.WriteString(fmt.Sprintf("  // callers observed: %d\n", len(incoming)))
			}
			b.WriteString("  // step 1: decode local context\n")
			b.WriteString("  // step 2: execute inferred helper chain\n")
			seen := map[string]struct{}{}
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
				b.WriteString("  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;\n")
				b.WriteString("  " + n + "();\n")
			}
			b.WriteString("  state ^= 0xA5A5A5A5U;\n")
		} else {
			b.WriteString(fmt.Sprintf("  // reconstructed leaf: %s\n", role))
			if len(incoming) > 0 {
				b.WriteString(fmt.Sprintf("  // callers observed: %d\n", len(incoming)))
			}
			if len(incoming) > 0 {
				b.WriteString("  state ^= 0x13579BDFU;\n")
			} else {
				b.WriteString("  state ^= 0x2468ACE0U;\n")
			}
		}
	} else {
		b.WriteString(fmt.Sprintf("  // reconstructed control: %s\n", role))
		phase1, phase2, phase3 := skeletonPhases(fn, role)
		b.WriteString(fmt.Sprintf("  // step 1: %s\n", phase1))
		if len(incoming) > 0 {
			b.WriteString(fmt.Sprintf("  // callers observed: %d\n", len(incoming)))
		}
		b.WriteString(fmt.Sprintf("  // step 2: %s\n", phase2))
		seen := map[string]struct{}{}
		emitted := emitControlCalls(&b, fn, outgoing, seen)
		if fn == "log_queue_push" && emitted == 0 {
			b.WriteString("  tx_dequeue();\n")
			b.WriteString("  state ^= 0xD00D00D0U;\n")
		}
		b.WriteString(fmt.Sprintf("  // step 3: %s\n", phase3))
		b.WriteString("  state ^= 0xC3C3C3C3U;\n")
	}
	b.WriteString("  (void)state;\n")
	b.WriteString("}\n")
	return os.WriteFile(path, []byte(b.String()), 0o644)
}

func emitControlCalls(b *strings.Builder, fn string, outgoing []callEdge, seen map[string]struct{}) int {
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
		emitted++
	}
	return emitted
}

func forcedControlCalls(fn string) []string {
	switch fn {
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
		key := addrKey(t.Image, t.Address)
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
