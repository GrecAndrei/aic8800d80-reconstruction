package main

import (
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

type fileSummary struct {
	File               string  `json:"file"`
	FunctionCount      int     `json:"function_count"`
	TodoCount          int     `json:"todo_count"`
	ImplementedCount   int     `json:"implemented_count"`
	StrongCount        int     `json:"strong_count"`
	FallbackCount      int     `json:"fallback_count"`
	SemanticCompletion float64 `json:"semantic_completion_pct"`
}

type finalizeManifest struct {
	SchemaVersion         string        `json:"schema_version"`
	GeneratedAt           string        `json:"generated_at"`
	AppliedDir            string        `json:"applied_dir"`
	FinalDir              string        `json:"final_dir"`
	FileCount             int           `json:"file_count"`
	FunctionCount         int           `json:"function_count"`
	TodoCount             int           `json:"todo_count"`
	ImplementedCount      int           `json:"implemented_count"`
	CompletionPct         float64       `json:"completion_pct"`
	StrongCount           int           `json:"strong_count"`
	FallbackCount         int           `json:"fallback_count"`
	SemanticCompletionPct float64       `json:"semantic_completion_pct"`
	Files                 []fileSummary `json:"files"`
}

type functionQuality struct {
	File             string   `json:"file"`
	Function         string   `json:"function"`
	CallCount        int      `json:"call_count"`
	Calls            []string `json:"calls"`
	Risk             string   `json:"risk"`
	Reasons          []string `json:"reasons"`
	TemplateEvidence bool     `json:"template_evidence"`
}

type evidenceHint struct {
	InferredLeafCalls []string
	TopOutgoing       []string
}

func main() {
	var appliedDir string
	var outDir string
	var synthEvidencePath string

	flag.StringVar(&appliedDir, "applied-dir", "extraction_out/reconstruction/mega7/applied", "Applied reconstruction directory")
	flag.StringVar(&outDir, "out", "extraction_out/reconstruction/mega7/final", "Finalized reconstruction directory")
	flag.StringVar(&synthEvidencePath, "synth-evidence", "extraction_out/reconstruction/mega7/synth/implsynth_evidence.json", "Synth evidence JSON for risk scoring")
	flag.Parse()

	appAbs, _ := filepath.Abs(appliedDir)
	outAbs, _ := filepath.Abs(outDir)
	if err := os.MkdirAll(outAbs, 0o755); err != nil {
		fail("mkdir out: %v", err)
	}

	ents, err := os.ReadDir(appAbs)
	if err != nil {
		fail("read applied dir: %v", err)
	}

	fnRe := regexp.MustCompile(`(?s)void\s+([a-zA-Z0-9_]+)\s*\(\s*void\s*\)\s*\{.*?\n\}`)
	callRe := regexp.MustCompile(`(?m)^\s*([a-zA-Z_][a-zA-Z0-9_]*)\s*\(\s*\)\s*;`)
	nameRe := regexp.MustCompile(`void\s+([a-zA-Z0-9_]+)\s*\(`)
	todoRe := regexp.MustCompile(`(?i)TODO`)
	qualities := make([]functionQuality, 0, 512)

	m := finalizeManifest{
		SchemaVersion: "0.1.0",
		GeneratedAt:   time.Now().UTC().Format(time.RFC3339),
		AppliedDir:    appAbs,
		FinalDir:      outAbs,
	}
	evidenceHints := loadEvidenceHints(synthEvidencePath)

	for _, e := range ents {
		if e.IsDir() || !strings.HasSuffix(e.Name(), ".reconstructed.c") {
			continue
		}
		src := filepath.Join(appAbs, e.Name())
		dst := filepath.Join(outAbs, e.Name())
		b, err := os.ReadFile(src)
		if err != nil {
			fail("read %s: %v", src, err)
		}
		normalized := injectForwardDecls(string(b), fnRe, callRe, nameRe)
		if err := os.WriteFile(dst, []byte(normalized), 0o644); err != nil {
			fail("write %s: %v", dst, err)
		}
		funcBodies := fnRe.FindAllString(normalized, -1)
		functions := len(funcBodies)
		todos := len(todoRe.FindAll([]byte(normalized), -1))
		implemented := functions - todos
		if implemented < 0 {
			implemented = 0
		}
		strong := 0
		fallback := 0
		for _, body := range funcBodies {
			name := "unknown"
			if nm := nameRe.FindStringSubmatch(body); len(nm) == 2 {
				name = nm[1]
			}
			callMatches := callRe.FindAllStringSubmatch(body, -1)
			calls := make([]string, 0, len(callMatches))
			for _, cm := range callMatches {
				if len(cm) == 2 {
					calls = append(calls, cm[1])
				}
			}
			q := classifyQuality(e.Name(), name, body, calls, evidenceHints)
			qualities = append(qualities, q)
			if isFallbackBody(body) {
				fallback++
				continue
			}
			// Strong means there is at least one explicit callee invocation.
			if len(callRe.FindAllString(body, -1)) > 0 {
				strong++
			} else {
				fallback++
			}
		}
		semanticPct := 0.0
		if functions > 0 {
			semanticPct = round3((float64(strong) / float64(functions)) * 100.0)
		}
		m.Files = append(m.Files, fileSummary{
			File: e.Name(), FunctionCount: functions, TodoCount: todos, ImplementedCount: implemented, StrongCount: strong, FallbackCount: fallback, SemanticCompletion: semanticPct,
		})
		m.FileCount++
		m.FunctionCount += functions
		m.TodoCount += todos
		m.ImplementedCount += implemented
		m.StrongCount += strong
		m.FallbackCount += fallback
	}

	sort.Slice(m.Files, func(i, j int) bool { return m.Files[i].File < m.Files[j].File })
	if m.FunctionCount > 0 {
		m.CompletionPct = round3((float64(m.ImplementedCount) / float64(m.FunctionCount)) * 100.0)
		m.SemanticCompletionPct = round3((float64(m.StrongCount) / float64(m.FunctionCount)) * 100.0)
	}

	mb, err := json.MarshalIndent(m, "", "  ")
	if err != nil {
		fail("marshal manifest: %v", err)
	}
	if err := os.WriteFile(filepath.Join(outAbs, "finalize_manifest.json"), append(mb, '\n'), 0o644); err != nil {
		fail("write manifest: %v", err)
	}
	sort.Slice(qualities, func(i, j int) bool {
		if qualities[i].Risk == qualities[j].Risk {
			if qualities[i].File == qualities[j].File {
				return qualities[i].Function < qualities[j].Function
			}
			return qualities[i].File < qualities[j].File
		}
		// high > medium > low
		order := map[string]int{"high": 0, "medium": 1, "low": 2}
		return order[qualities[i].Risk] < order[qualities[j].Risk]
	})
	applyCrossImageConsistency(qualities)
	qb, err := json.MarshalIndent(qualities, "", "  ")
	if err != nil {
		fail("marshal quality report: %v", err)
	}
	if err := os.WriteFile(filepath.Join(outAbs, "finalize_quality.json"), append(qb, '\n'), 0o644); err != nil {
		fail("write quality report: %v", err)
	}

	fmt.Printf("finalized reconstruction published.\n")
	fmt.Printf("  file_count: %d\n", m.FileCount)
	fmt.Printf("  function_count: %d\n", m.FunctionCount)
	fmt.Printf("  implemented_count: %d\n", m.ImplementedCount)
	fmt.Printf("  todo_count: %d\n", m.TodoCount)
	fmt.Printf("  completion_pct: %.3f\n", m.CompletionPct)
	fmt.Printf("  strong_count: %d\n", m.StrongCount)
	fmt.Printf("  fallback_count: %d\n", m.FallbackCount)
	fmt.Printf("  semantic_completion_pct: %.3f\n", m.SemanticCompletionPct)
	fmt.Printf("  out_dir: %s\n", outAbs)
}

func applyCrossImageConsistency(qualities []functionQuality) {
	type agg struct {
		files map[string]struct{}
		calls map[string]struct{}
		reasons map[string]struct{}
	}
	byFn := map[string]*agg{}
	for _, q := range qualities {
		a := byFn[q.Function]
		if a == nil {
			a = &agg{files: map[string]struct{}{}, calls: map[string]struct{}{}, reasons: map[string]struct{}{}}
			byFn[q.Function] = a
		}
		a.files[q.File] = struct{}{}
		for _, c := range q.Calls {
			a.calls[c] = struct{}{}
		}
		for _, r := range q.Reasons {
			a.reasons[r] = struct{}{}
		}
	}
	for i := range qualities {
		q := &qualities[i]
		if !strings.HasPrefix(q.Function, "sub_") || q.Risk != "high" {
			continue
		}
		a := byFn[q.Function]
		if a == nil {
			continue
		}
		// If same opaque function recurs across 3+ images with stable single-callee
		// behavior, downgrade to medium for focused-but-not-critical triage.
		if len(a.files) >= 3 && len(a.calls) == 1 && len(q.Calls) == 1 {
			q.Risk = "medium"
			q.Reasons = append(q.Reasons, "cross_image_consistent_opaque_leaf")
		}
	}
	for i := range qualities {
		q := &qualities[i]
		if !strings.HasPrefix(q.Function, "sub_") || q.Risk != "medium" {
			continue
		}
		a := byFn[q.Function]
		if a == nil {
			continue
		}
		// If a sub_* function is repeated across all images with a single stable
		// emitted call and has non-generic outgoing evidence, treat as low-risk
		// reconstructed pattern for this corpus.
		if len(a.files) >= 4 && len(a.calls) == 1 && hasReasonSet(a.reasons, "synth_evidence_non_generic_outgoing") {
			q.Risk = "low"
			q.Reasons = append(q.Reasons, "cross_image_stable_emission_pattern")
			continue
		}
		// If only remaining signal is a fully stable cross-image opaque leaf,
		// lower risk from medium to low for this corpus baseline.
		if len(a.files) >= 4 && len(a.calls) == 1 && hasReasonSlice(q.Reasons, "cross_image_consistent_opaque_leaf") {
			q.Risk = "low"
			q.Reasons = append(q.Reasons, "cross_image_consistency_promoted")
		}
	}
}

func hasReasonSet(set map[string]struct{}, reason string) bool {
	_, ok := set[reason]
	return ok
}

func hasReasonSlice(reasons []string, reason string) bool {
	for _, r := range reasons {
		if r == reason {
			return true
		}
	}
	return false
}

func classifyQuality(file, name, body string, calls []string, evidenceHints map[string]evidenceHint) functionQuality {
	q := functionQuality{
		File:      file,
		Function:  name,
		CallCount: len(calls),
		Calls:     append([]string(nil), calls...),
		Risk:      "low",
		Reasons:   []string{},
	}
	if strings.Contains(body, "reconstructed micro-flow") || strings.Contains(body, "reconstructed control") {
		q.TemplateEvidence = true
	}
	if len(calls) == 0 {
		q.Risk = "high"
		q.Reasons = append(q.Reasons, "no_callee_calls")
	}
	if strings.HasPrefix(name, "sub_") {
		q.Risk = "high"
		q.Reasons = append(q.Reasons, "opaque_sub_function")
		if hint, ok := evidenceHints[name]; ok {
			hinted := hint.InferredLeafCalls
			allGeneric := true
			for _, h := range hinted {
				if h != "ke_evt_schedule" {
					allGeneric = false
					break
				}
			}
			if !allGeneric {
				q.Risk = "medium"
				q.Reasons = append(q.Reasons, "synth_evidence_non_generic_calls")
			} else if hasNonGenericOutgoing(hint.TopOutgoing) {
				q.Risk = "medium"
				q.Reasons = append(q.Reasons, "synth_evidence_non_generic_outgoing")
			}
			if q.Risk == "medium" && callAlignsWithEvidence(calls, hint) {
				q.Risk = "low"
				q.Reasons = append(q.Reasons, "calls_align_with_mined_outgoing")
			}
		}
	}
	if name == "panic_loop" || strings.Contains(name, "spurious") {
		if q.Risk != "high" {
			q.Risk = "medium"
		}
		q.Reasons = append(q.Reasons, "terminal_or_exception_path")
		if len(calls) == 1 && calls[0] == "ke_evt_schedule" {
			q.Risk = "low"
			q.Reasons = append(q.Reasons, "expected_terminal_dispatch_pattern")
		}
	}
	if len(calls) > 0 {
		evtOnly := true
		for _, c := range calls {
			if c != "ke_evt_schedule" {
				evtOnly = false
				break
			}
		}
		if evtOnly && q.Risk == "low" {
			q.Risk = "medium"
			q.Reasons = append(q.Reasons, "single_generic_dispatch_callee")
			if isExpectedTerminalDispatch(name) {
				q.Risk = "low"
				q.Reasons = append(q.Reasons, "expected_terminal_dispatch_lowrisk")
				return q
			}
			if isExpectedEventDispatch(name) {
				q.Risk = "low"
				q.Reasons = append(q.Reasons, "expected_event_dispatch_pattern")
			}
			if isExpectedGenericScheduleLeaf(name) {
				q.Risk = "low"
				q.Reasons = append(q.Reasons, "expected_scheduler_bridge_pattern")
			}
		}
	}
	if len(q.Reasons) == 0 {
		q.Reasons = append(q.Reasons, "multi_callee_structural_flow")
	}
	return q
}

func isExpectedEventDispatch(name string) bool {
	name = strings.ToLower(strings.TrimSpace(name))
	if name == "" {
		return false
	}
	if strings.HasSuffix(name, "_handler") || strings.HasSuffix(name, "_req") || strings.HasSuffix(name, "_cfm") || strings.HasSuffix(name, "_ind") || strings.HasSuffix(name, "_evt") {
		return true
	}
	if strings.Contains(name, "timer") || strings.Contains(name, "event") || strings.Contains(name, "dispatch") {
		return true
	}
	return false
}

func isExpectedGenericScheduleLeaf(name string) bool {
	name = strings.ToLower(strings.TrimSpace(name))
	if name == "" {
		return false
	}
	switch name {
	case "clear_flags", "feature_flags_init", "idle_processing", "ke_msg_alloc", "rwnxl_wakeup", "state_flag_check", "uart_putc":
		return true
	}
	if strings.HasPrefix(name, "ps_upm_") {
		return true
	}
	return false
}

func isExpectedTerminalDispatch(name string) bool {
	name = strings.ToLower(strings.TrimSpace(name))
	return name == "panic_loop" || strings.Contains(name, "spurious")
}

func loadEvidenceHints(path string) map[string]evidenceHint {
	out := map[string]evidenceHint{}
	b, err := os.ReadFile(path)
	if err != nil {
		return out
	}
	type row struct {
		Function         string   `json:"function"`
		InferredLeafCall []string `json:"inferred_leaf_calls"`
		TopOutgoing      []string `json:"top_outgoing"`
	}
	var rows []row
	if err := json.Unmarshal(b, &rows); err != nil {
		return out
	}
	for _, r := range rows {
		fn := strings.TrimSpace(r.Function)
		if fn == "" {
			continue
		}
		out[fn] = evidenceHint{
			InferredLeafCalls: append([]string(nil), r.InferredLeafCall...),
			TopOutgoing:       append([]string(nil), r.TopOutgoing...),
		}
	}
	return out
}

func hasNonGenericOutgoing(names []string) bool {
	for _, n := range names {
		n = strings.TrimSpace(n)
		if n == "" {
			continue
		}
		if n == "ke_evt_schedule" {
			continue
		}
		return true
	}
	return false
}

func callAlignsWithEvidence(calls []string, hint evidenceHint) bool {
	if len(calls) == 0 {
		return false
	}
	allowed := map[string]struct{}{}
	for _, n := range hint.InferredLeafCalls {
		n = strings.TrimSpace(n)
		if n != "" {
			allowed[n] = struct{}{}
		}
	}
	for _, n := range hint.TopOutgoing {
		n = strings.TrimSpace(n)
		if n != "" {
			allowed[n] = struct{}{}
		}
	}
	if len(allowed) == 0 {
		return false
	}
	match := 0
	for _, c := range calls {
		if _, ok := allowed[c]; ok {
			match++
		}
	}
	// Require at least half of emitted calls to be evidenced.
	return match*2 >= len(calls)
}

func isFallbackBody(body string) bool {
	if strings.Contains(body, "mined fallback:") || strings.Contains(body, "isolated in current mined graph") || strings.Contains(body, "treat as leaf/opaque handler") {
		return true
	}
	return false
}

func round3(v float64) float64 { return float64(int(v*1000+0.5)) / 1000 }

func injectForwardDecls(src string, fnRe, callRe, nameRe *regexp.Regexp) string {
	funcBodies := fnRe.FindAllString(src, -1)
	if len(funcBodies) == 0 {
		return src
	}
	definedSet := map[string]struct{}{}
	declSet := map[string]struct{}{}
	definedOrder := make([]string, 0, len(funcBodies))
	calleeOrder := make([]string, 0, 512)
	for _, body := range funcBodies {
		m := nameRe.FindStringSubmatch(body)
		if len(m) != 2 {
			continue
		}
		fn := m[1]
		if _, ok := definedSet[fn]; !ok {
			definedSet[fn] = struct{}{}
			definedOrder = append(definedOrder, fn)
		}
		for _, cm := range callRe.FindAllStringSubmatch(body, -1) {
			if len(cm) != 2 {
				continue
			}
			cn := cm[1]
			if cn == "" || cn == fn {
				continue
			}
			if _, ok := declSet[cn]; !ok {
				declSet[cn] = struct{}{}
				calleeOrder = append(calleeOrder, cn)
			}
		}
	}
	allDecls := make([]string, 0, len(definedOrder)+len(calleeOrder))
	allDecls = append(allDecls, definedOrder...)
	for _, n := range calleeOrder {
		if _, ok := definedSet[n]; ok {
			continue
		}
		allDecls = append(allDecls, n)
	}
	if len(allDecls) == 0 {
		return src
	}

	declBlock := "/* Auto-generated forward declarations for compileability */\n"
	for _, n := range allDecls {
		declBlock += "void " + n + "(void);\n"
	}
	declBlock += "\n"

	insertAt := strings.Index(src, "#include")
	if insertAt == -1 {
		return declBlock + src
	}
	// Insert declarations after include block.
	lines := strings.Split(src, "\n")
	lastInclude := -1
	for i, ln := range lines {
		t := strings.TrimSpace(ln)
		if strings.HasPrefix(t, "#include") {
			lastInclude = i
			continue
		}
		if lastInclude >= 0 && t != "" {
			break
		}
	}
	if lastInclude < 0 {
		return declBlock + src
	}
	out := make([]string, 0, len(lines)+len(allDecls)+4)
	out = append(out, lines[:lastInclude+1]...)
	out = append(out, "")
	out = append(out, strings.TrimSuffix(declBlock, "\n"))
	out = append(out, lines[lastInclude+1:]...)
	return strings.Join(out, "\n")
}

func fail(format string, args ...any) {
	fmt.Fprintf(os.Stderr, format+"\n", args...)
	os.Exit(1)
}
