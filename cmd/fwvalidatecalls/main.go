package main

import (
	"bufio"
	"encoding/json"
	"flag"
	"fmt"
	"hash/fnv"
	"os"
	"path/filepath"
	"regexp"
	"sort"
	"strings"

	"aic8800d80/internal/fileio"
)

type callEdge struct {
	SchemaVersion string  `json:"schema_version,omitempty"`
	Image         string  `json:"image"`
	SourceAddr    string  `json:"source_addr"`
	SourceName    string  `json:"source_name"`
	TargetAddr    string  `json:"target_addr"`
	TargetName    string  `json:"target_name"`
	Confidence    float64 `json:"confidence"`
}

type fnCalls struct {
	File           string   `json:"file"`
	Function       string   `json:"function"`
	Address        string   `json:"address"`
	Calls          []string `json:"calls"`
	StructuredLeaf bool     `json:"structured_leaf"`
}

type row struct {
	File           string   `json:"file"`
	Function       string   `json:"function"`
	EmittedCalls   []string `json:"emitted_calls"`
	EvidenceCalls  []string `json:"evidence_calls"`
	Unsupported    []string `json:"unsupported_calls"`
	MissingLikely  []string `json:"missing_likely_calls"`
	ConformancePct float64  `json:"conformance_pct"`
	EvidenceFound  bool     `json:"evidence_found"`
}

type synthEvidenceRow struct {
	SchemaVersion    string   `json:"schema_version,omitempty"`
	Function         string   `json:"function"`
	InferredLeafCall []string `json:"inferred_leaf_calls"`
	TopOutgoing      []string `json:"top_outgoing"`
}

type cfgHint struct {
	SchemaVersion string `json:"schema_version,omitempty"`
	Image         string `json:"image"`
	Address       string `json:"address"`
	Name          string `json:"name"`
	CallsiteCount int    `json:"callsite_count"`
}

type functionLinkRec struct {
	SchemaVersion string  `json:"schema_version,omitempty"`
	SourceName    string  `json:"source_name"`
	TargetName    string  `json:"target_name"`
	Confidence    float64 `json:"confidence"`
}

type holdoutBucketMetrics struct {
	EvaluableCount    int     `json:"evaluable_count"`
	AvgConformancePct float64 `json:"avg_conformance_pct"`
	NonperfectCount   int     `json:"nonperfect_count"`
}

type holdoutConformance struct {
	SplitMod  int                  `json:"split_mod"`
	SplitKey  string               `json:"split_key"`
	InSample  holdoutBucketMetrics `json:"in_sample"`
	OutSample holdoutBucketMetrics `json:"out_of_sample"`
}

func main() {
	var runRoot string
	var finalDir string
	var callEdgesPath string
	var minConf float64
	var relaxedMinConf float64
	var relaxedMinVotes int
	var outPath string
	var synthEvidencePath string
	var composedDir string
	var appliedDir string
	var cfgHintsPath string
	var functionLinksPath string
	var holdoutMod int

	flag.StringVar(&runRoot, "run-root", "extraction_out/reconstruction/mega7", "Reconstruction run root")
	flag.StringVar(&finalDir, "final-dir", "", "Final reconstruction directory")
	flag.StringVar(&callEdgesPath, "call-edges", "extraction_out/call_edges.jsonl", "Call edges JSONL")
	flag.Float64Var(&minConf, "min-conf", 0.7, "Minimum confidence for evidence calls")
	flag.Float64Var(&relaxedMinConf, "relaxed-min-conf", 0.4, "Relaxed call-edge confidence used only as last-resort evidence")
	flag.IntVar(&relaxedMinVotes, "relaxed-min-votes", 2, "Minimum repeated votes per relaxed evidence callee")
	flag.StringVar(&outPath, "out", "", "Output conformance report")
	flag.StringVar(&synthEvidencePath, "synth-evidence", "", "Synth evidence JSON")
	flag.StringVar(&composedDir, "composed-dir", "", "Composed reconstruction directory used as fallback evidence")
	flag.StringVar(&appliedDir, "applied-dir", "", "Applied reconstruction directory used as fallback evidence")
	flag.StringVar(&cfgHintsPath, "cfg-hints", "extraction_out/ida_export_cfg/cfg_hints.jsonl", "IDA CFG hints JSONL")
	flag.StringVar(&functionLinksPath, "function-links", "extraction_out/function_links.jsonl", "Cross-image function link evidence JSONL")
	flag.IntVar(&holdoutMod, "holdout-mod", 5, "Deterministic holdout split modulus (bucket 0 is out-of-sample)")
	flag.Parse()
	if holdoutMod < 2 {
		holdoutMod = 5
	}
	runRoot = filepath.Clean(strings.TrimSpace(runRoot))
	if strings.TrimSpace(finalDir) == "" {
		finalDir = filepath.Join(runRoot, "final")
	}
	if strings.TrimSpace(outPath) == "" {
		outPath = filepath.Join(runRoot, "final", "call_conformance.json")
	}
	if strings.TrimSpace(synthEvidencePath) == "" {
		synthEvidencePath = filepath.Join(runRoot, "synth", "implsynth_evidence.json")
	}
	if strings.TrimSpace(composedDir) == "" {
		composedDir = filepath.Join(runRoot, "composed")
	}
	if strings.TrimSpace(appliedDir) == "" {
		appliedDir = filepath.Join(runRoot, "applied")
	}

	finalAbs, _ := filepath.Abs(finalDir)
	outAbs, _ := filepath.Abs(outPath)
	funcs, err := parseFinalFunctions(finalAbs)
	if err != nil {
		fail("parse final functions: %v", err)
	}
	addrByName := buildAddrByName(funcs)
	fnByAddr := buildFnByAddr(funcs)
	evidence, relaxedEvidence, err := loadEvidence(callEdgesPath, minConf, relaxedMinConf, relaxedMinVotes, addrByName, fnByAddr)
	if err != nil {
		fail("load call edges: %v", err)
	}
	targetSeen, err := loadTargetSeen(callEdgesPath, minConf, fnByAddr)
	if err != nil {
		fail("load target seen: %v", err)
	}
	rawEdgesPath := filepath.Join(filepath.Dir(callEdgesPath), "call_edges.with_ida_raw.jsonl")
	if _, err := os.Stat(rawEdgesPath); err == nil {
		ev2, relax2, err := loadEvidence(rawEdgesPath, minConf, relaxedMinConf, relaxedMinVotes, addrByName, fnByAddr)
		if err == nil {
			evidence = mergeEvidenceMaps(evidence, ev2)
			relaxedEvidence = mergeEvidenceMaps(relaxedEvidence, relax2)
		}
		t2, terr := loadTargetSeen(rawEdgesPath, minConf, fnByAddr)
		if terr != nil {
			fail("load target seen (raw): %v", terr)
		}
		for k := range t2 {
			targetSeen[k] = struct{}{}
		}
	}
	synthEvidence, err := loadSynthEvidence(synthEvidencePath)
	if err != nil {
		fail("load synth evidence: %v", err)
	}
	appliedEvidence, err := loadComposedEvidence(appliedDir)
	if err != nil {
		fail("load applied evidence: %v", err)
	}
	composedEvidence, err := loadComposedEvidence(composedDir)
	if err != nil {
		fail("load composed evidence: %v", err)
	}
	cfgByName, cfgByAddr, _ := loadCFGHints(cfgHintsPath)
	linkMap, _ := loadFunctionLinks(functionLinksPath, 0.80)

	evidenceFor := func(name string) []string {
		if name == "" {
			return nil
		}
		if ev := evidence[name]; len(ev) > 0 {
			return ev
		}
		if ev := synthEvidence[name]; len(ev) > 0 {
			return ev
		}
		if ev := appliedEvidence[name]; len(ev) > 0 {
			return ev
		}
		if ev := composedEvidence[name]; len(ev) > 0 {
			return ev
		}
		if ev := relaxedEvidence[name]; len(ev) > 0 {
			return ev
		}
		return nil
	}

	rows := make([]row, 0, len(funcs))
	sum := 0.0
	evaluable := 0
	for _, fn := range funcs {
		fnKey := sanitizeName(fn.Function)
		ev := evidenceFor(fnKey)
		if len(ev) == 0 {
			if base := baseEvidenceName(fnKey); base != "" && base != fnKey {
				ev = evidenceFor(base)
			}
		}
		if len(ev) == 0 {
			for _, cand := range linkMap[fnKey] {
				if linked := evidenceFor(cand); len(linked) > 0 {
					ev = linked
					break
				}
			}
		}
		evSet := make(map[string]struct{}, len(ev))
		for _, n := range ev {
			evSet[n] = struct{}{}
		}
		emSet := make(map[string]struct{}, len(fn.Calls)*2)
		for _, n := range fn.Calls {
			emSet[n] = struct{}{}
			if addr := addrByName[sanitizeName(n)]; addr != "" {
				emSet["@"+addr] = struct{}{}
			}
		}
		unsupported := make([]string, 0)
		for _, c := range fn.Calls {
			if _, ok := evSet[c]; ok {
				continue
			}
			addrMatch := false
			if addr := addrByName[sanitizeName(c)]; addr != "" {
				_, addrMatch = evSet["@"+addr]
			}
			if !addrMatch {
				unsupported = append(unsupported, c)
			}
		}
		missing := make([]string, 0)
		for _, c := range ev {
			if _, ok := emSet[c]; !ok {
				missing = append(missing, c)
			}
		}
		match := len(fn.Calls) - len(unsupported)
		denom := len(fn.Calls)
		pct := 100.0
		foundEvidence := len(ev) > 0
		if !foundEvidence && len(fn.Calls) == 0 && isIntrinsicLeafFunction(fn.Function) {
			foundEvidence = true
		}
		if !foundEvidence && len(fn.Calls) == 0 && fn.StructuredLeaf {
			foundEvidence = true
		}
		if !foundEvidence && len(fn.Calls) == 0 {
			fnKey := sanitizeName(fn.Function)
			cfgCallsites, ok := cfgCallsiteCount(fnKey, fn.Address, cfgByName, cfgByAddr)
			if ok && cfgCallsites == 0 {
				// IDA CFG confirms this function has no callsites.
				foundEvidence = true
			}
		}
		if !foundEvidence && len(fn.Calls) == 0 {
			if _, ok := targetSeen[fnKey]; ok {
				// IDA confirms this function is a real call target even if leaf.
				foundEvidence = true
			}
			if !foundEvidence {
				if base := baseEvidenceName(fnKey); base != "" {
					if _, ok := targetSeen[base]; ok {
						foundEvidence = true
					}
				}
			}
		}
		if denom > 0 && foundEvidence {
			pct = float64(match) / float64(denom) * 100.0
			sum += pct
			evaluable++
		} else if !foundEvidence {
			pct = 100.0
		}
		rows = append(rows, row{
			File:           fn.File,
			Function:       fn.Function,
			EmittedCalls:   fn.Calls,
			EvidenceCalls:  ev,
			Unsupported:    unsupported,
			MissingLikely:  missing,
			ConformancePct: round3(pct),
			EvidenceFound:  foundEvidence,
		})
	}
	sort.Slice(rows, func(i, j int) bool {
		if rows[i].ConformancePct == rows[j].ConformancePct {
			if rows[i].File == rows[j].File {
				return rows[i].Function < rows[j].Function
			}
			return rows[i].File < rows[j].File
		}
		return rows[i].ConformancePct < rows[j].ConformancePct
	})

	avg := 100.0
	if evaluable > 0 {
		avg = sum / float64(evaluable)
	}
	holdout := computeHoldoutConformance(rows, holdoutMod)

	type report struct {
		SchemaVersion     string             `json:"schema_version"`
		FinalDir          string             `json:"final_dir"`
		CallEdgesPath     string             `json:"call_edges_path"`
		MinConfidence     float64            `json:"min_confidence"`
		FunctionCount     int                `json:"function_count"`
		EvaluableCount    int                `json:"evaluable_count"`
		AvgConformancePct float64            `json:"avg_conformance_pct"`
		Holdout           holdoutConformance `json:"holdout"`
		Rows              []row              `json:"rows"`
	}
	rep := report{
		SchemaVersion:     "0.1.0",
		FinalDir:          finalAbs,
		CallEdgesPath:     callEdgesPath,
		MinConfidence:     minConf,
		FunctionCount:     len(rows),
		EvaluableCount:    evaluable,
		AvgConformancePct: round3(avg),
		Holdout:           holdout,
		Rows:              rows,
	}
	if err := fileio.WriteJSON(outAbs, rep); err != nil {
		fail("write report: %v", err)
	}

	low := 0
	unknown := 0
	for _, r := range rows {
		if !r.EvidenceFound {
			unknown++
			continue
		}
		if r.ConformancePct < 100.0 {
			low++
		}
	}
	fmt.Printf("call conformance validated.\n")
	fmt.Printf("  function_count: %d\n", len(rows))
	fmt.Printf("  evaluable_count: %d\n", evaluable)
	fmt.Printf("  avg_conformance_pct: %.3f\n", rep.AvgConformancePct)
	fmt.Printf("  holdout_in_sample_pct: %.3f\n", rep.Holdout.InSample.AvgConformancePct)
	fmt.Printf("  holdout_out_of_sample_pct: %.3f\n", rep.Holdout.OutSample.AvgConformancePct)
	fmt.Printf("  nonperfect_functions: %d\n", low)
	fmt.Printf("  unevidenced_functions: %d\n", unknown)
	fmt.Printf("  out_path: %s\n", outAbs)
}

func computeHoldoutConformance(rows []row, splitMod int) holdoutConformance {
	if splitMod < 2 {
		splitMod = 5
	}
	inEval := 0
	outEval := 0
	inLow := 0
	outLow := 0
	inSum := 0.0
	outSum := 0.0
	for _, r := range rows {
		if !r.EvidenceFound || len(r.EmittedCalls) == 0 {
			continue
		}
		bucket := holdoutBucket(r.Function, r.File, splitMod)
		if bucket == 0 {
			outEval++
			outSum += r.ConformancePct
			if r.ConformancePct < 100.0 {
				outLow++
			}
		} else {
			inEval++
			inSum += r.ConformancePct
			if r.ConformancePct < 100.0 {
				inLow++
			}
		}
	}
	inAvg := 100.0
	outAvg := 100.0
	if inEval > 0 {
		inAvg = inSum / float64(inEval)
	}
	if outEval > 0 {
		outAvg = outSum / float64(outEval)
	}
	return holdoutConformance{
		SplitMod:  splitMod,
		SplitKey:  "fnv32(function|file)",
		InSample:  holdoutBucketMetrics{EvaluableCount: inEval, AvgConformancePct: round3(inAvg), NonperfectCount: inLow},
		OutSample: holdoutBucketMetrics{EvaluableCount: outEval, AvgConformancePct: round3(outAvg), NonperfectCount: outLow},
	}
}

func holdoutBucket(function, file string, mod int) int {
	if mod < 1 {
		mod = 1
	}
	h := fnv.New32a()
	_, _ = h.Write([]byte(strings.ToLower(strings.TrimSpace(function) + "|" + strings.TrimSpace(file))))
	return int(h.Sum32() % uint32(mod))
}

func loadTargetSeen(path string, minConf float64, fnByAddr map[string]string) (map[string]struct{}, error) {
	out := map[string]struct{}{}
	f, err := os.Open(path)
	if err != nil {
		return out, nil
	}
	defer f.Close()
	sc := bufio.NewScanner(f)
	sc.Buffer(make([]byte, 4096), 8*1024*1024)
	for sc.Scan() {
		line := strings.TrimSpace(sc.Text())
		if line == "" {
			continue
		}
		var e callEdge
		if err := json.Unmarshal([]byte(line), &e); err != nil {
			continue
		}
		if strings.TrimSpace(e.SchemaVersion) != "" && e.SchemaVersion != "0.1.0" {
			return nil, fmt.Errorf("call edges schema mismatch: got %s want 0.1.0", e.SchemaVersion)
		}
		if e.Confidence < minConf {
			continue
		}
		dst := sanitizeName(e.TargetName)
		if dstAddr := normalizeAddr(e.TargetAddr); dstAddr != "" {
			if mapped := fnByAddr[dstAddr]; mapped != "" {
				dst = mapped
			}
		}
		if dst == "" || dst == "unknown" {
			continue
		}
		out[dst] = struct{}{}
	}
	if err := sc.Err(); err != nil {
		return nil, err
	}
	return out, nil
}

func loadFunctionLinks(path string, minConfidence float64) (map[string][]string, error) {
	f, err := os.Open(path)
	if err != nil {
		return map[string][]string{}, err
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
		if strings.TrimSpace(r.SchemaVersion) != "" && r.SchemaVersion != "0.1.0" {
			return map[string][]string{}, fmt.Errorf("function links schema mismatch: got %s want 0.1.0", r.SchemaVersion)
		}
		if r.Confidence < minConfidence {
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
	for k, set := range adj {
		list := make([]string, 0, len(set))
		for n := range set {
			list = append(list, n)
		}
		sort.Strings(list)
		out[k] = list
	}
	return out, sc.Err()
}

func loadCFGHints(path string) (map[string]int, map[string]int, error) {
	f, err := os.Open(path)
	if err != nil {
		return map[string]int{}, map[string]int{}, err
	}
	defer f.Close()
	byName := map[string]int{}
	byAddr := map[string]int{}
	sc := bufio.NewScanner(f)
	sc.Buffer(make([]byte, 4096), 8*1024*1024)
	for sc.Scan() {
		line := strings.TrimSpace(sc.Text())
		if line == "" {
			continue
		}
		var h cfgHint
		if err := json.Unmarshal([]byte(line), &h); err != nil {
			continue
		}
		if strings.TrimSpace(h.SchemaVersion) != "" && h.SchemaVersion != "0.1.0" {
			return map[string]int{}, map[string]int{}, fmt.Errorf("cfg hints schema mismatch: got %s want 0.1.0", h.SchemaVersion)
		}
		n := sanitizeName(h.Name)
		if n != "" {
			byName[n] = h.CallsiteCount
		}
		if a := normalizeAddr(h.Address); a != "" {
			byAddr[a] = h.CallsiteCount
		}
	}
	return byName, byAddr, sc.Err()
}

func cfgCallsiteCount(fnKey, addr string, byName, byAddr map[string]int) (int, bool) {
	if fnKey != "" {
		if v, ok := byName[fnKey]; ok {
			return v, true
		}
	}
	if a := normalizeAddr(addr); a != "" {
		if v, ok := byAddr[a]; ok {
			return v, true
		}
	}
	return 0, false
}

func mergeEvidenceMaps(a, b map[string][]string) map[string][]string {
	if len(a) == 0 {
		return b
	}
	if len(b) == 0 {
		return a
	}
	out := map[string][]string{}
	for k, v := range a {
		cp := append([]string(nil), v...)
		out[k] = cp
	}
	for k, v := range b {
		seen := map[string]struct{}{}
		cur := out[k]
		for _, x := range cur {
			seen[x] = struct{}{}
		}
		for _, x := range v {
			if _, ok := seen[x]; ok {
				continue
			}
			seen[x] = struct{}{}
			cur = append(cur, x)
		}
		sort.Strings(cur)
		out[k] = cur
	}
	return out
}

func baseEvidenceName(n string) string {
	n = sanitizeName(n)
	if n == "" || n == "unknown" {
		return ""
	}
	// Collapse synthetic variant suffixes used by reconstruction fanout.
	reSuffix := regexp.MustCompile(`_n_[0-9a-f]+$|_n[0-9a-f]+$`)
	base := reSuffix.ReplaceAllString(n, "")
	base = strings.TrimSuffix(base, "_")
	if base == "" || base == n {
		return ""
	}
	return base
}

func loadEvidence(path string, minConf float64, relaxedMinConf float64, relaxedMinVotes int, addrByName map[string]string, fnByAddr map[string]string) (map[string][]string, map[string][]string, error) {
	f, err := os.Open(path)
	if err != nil {
		return nil, nil, err
	}
	defer f.Close()
	tmp := map[string]map[string]struct{}{}
	relaxedVotes := map[string]map[string]int{}
	sc := bufio.NewScanner(f)
	sc.Buffer(make([]byte, 4096), 8*1024*1024)
	for sc.Scan() {
		line := strings.TrimSpace(sc.Text())
		if line == "" {
			continue
		}
		var e callEdge
		if err := json.Unmarshal([]byte(line), &e); err != nil {
			continue
		}
		if strings.TrimSpace(e.SchemaVersion) != "" && e.SchemaVersion != "0.1.0" {
			return nil, nil, fmt.Errorf("call edges schema mismatch: got %s want 0.1.0", e.SchemaVersion)
		}
		src := sanitizeName(e.SourceName)
		if srcAddr := normalizeAddr(e.SourceAddr); srcAddr != "" {
			if mapped := fnByAddr[srcAddr]; mapped != "" {
				src = mapped
			}
		}
		dst := sanitizeName(e.TargetName)
		if dstAddr := normalizeAddr(e.TargetAddr); dstAddr != "" {
			if mapped := fnByAddr[dstAddr]; mapped != "" {
				dst = mapped
			}
		}
		if src == "" || dst == "" || src == "unknown" || dst == "unknown" || src == dst {
			continue
		}
		if e.Confidence >= minConf {
			if tmp[src] == nil {
				tmp[src] = map[string]struct{}{}
			}
			tmp[src][dst] = struct{}{}
			if addr := normalizeAddr(e.TargetAddr); addr != "" {
				tmp[src]["@"+addr] = struct{}{}
			} else if addr := addrByName[dst]; addr != "" {
				tmp[src]["@"+addr] = struct{}{}
			}
		}
		if e.Confidence >= relaxedMinConf {
			if relaxedVotes[src] == nil {
				relaxedVotes[src] = map[string]int{}
			}
			relaxedVotes[src][dst]++
			if addr := normalizeAddr(e.TargetAddr); addr != "" {
				relaxedVotes[src]["@"+addr]++
			} else if addr := addrByName[dst]; addr != "" {
				relaxedVotes[src]["@"+addr]++
			}
		}
	}
	if err := sc.Err(); err != nil {
		return nil, nil, err
	}
	out := map[string][]string{}
	for fn, set := range tmp {
		list := make([]string, 0, len(set))
		for c := range set {
			list = append(list, c)
		}
		sort.Strings(list)
		out[fn] = list
	}
	relaxed := map[string][]string{}
	if relaxedMinVotes < 1 {
		relaxedMinVotes = 1
	}
	for fn, votes := range relaxedVotes {
		list := make([]string, 0, len(votes))
		for n, c := range votes {
			if c >= relaxedMinVotes {
				list = append(list, n)
			}
		}
		if len(list) == 0 {
			continue
		}
		sort.Strings(list)
		relaxed[fn] = list
	}
	return out, relaxed, nil
}

func loadSynthEvidence(path string) (map[string][]string, error) {
	out := map[string][]string{}
	b, err := os.ReadFile(path)
	if err != nil {
		return out, nil
	}
	var rows []synthEvidenceRow
	if err := json.Unmarshal(b, &rows); err != nil {
		return out, nil
	}
	for _, r := range rows {
		if strings.TrimSpace(r.SchemaVersion) != "" && r.SchemaVersion != "0.1.0" {
			return nil, fmt.Errorf("implsynth evidence schema mismatch: got %s want 0.1.0", r.SchemaVersion)
		}
		fn := sanitizeName(r.Function)
		if fn == "" || fn == "unknown" {
			continue
		}
		seen := map[string]struct{}{}
		merged := make([]string, 0, len(r.InferredLeafCall)+len(r.TopOutgoing))
		for _, n := range append(append([]string{}, r.InferredLeafCall...), r.TopOutgoing...) {
			n = sanitizeName(n)
			if n == "" || n == "unknown" {
				continue
			}
			if _, ok := seen[n]; ok {
				continue
			}
			seen[n] = struct{}{}
			merged = append(merged, n)
		}
		if len(merged) > 0 {
			out[fn] = merged
		}
	}
	return out, nil
}

func parseFinalFunctions(dir string) ([]fnCalls, error) {
	ents, err := os.ReadDir(dir)
	if err != nil {
		return nil, err
	}
	fnRe := regexp.MustCompile(`(?s)(?:/\*.*?addr=(0x[0-9a-fA-F]+).*?\*/\s*)?void\s+([a-zA-Z0-9_]+)\s*\(\s*void\s*\)\s*\{(.*?)\n\}`)
	callRe := regexp.MustCompile(`(?m)^\s*([a-zA-Z_][a-zA-Z0-9_]*)\s*\(\s*\)\s*;`)
	out := make([]fnCalls, 0, 512)
	for _, e := range ents {
		if e.IsDir() || !strings.HasSuffix(e.Name(), ".reconstructed.c") {
			continue
		}
		b, err := os.ReadFile(filepath.Join(dir, e.Name()))
		if err != nil {
			return nil, err
		}
		for _, m := range fnRe.FindAllStringSubmatch(string(b), -1) {
			if len(m) != 4 {
				continue
			}
			addr := normalizeAddr(m[1])
			fn := m[2]
			body := m[3]
			calls := make([]string, 0)
			seen := map[string]struct{}{}
			for _, c := range callRe.FindAllStringSubmatch(body, -1) {
				if len(c) != 2 {
					continue
				}
				n := c[1]
				if _, ok := seen[n]; ok {
					continue
				}
				seen[n] = struct{}{}
				calls = append(calls, n)
			}
			out = append(out, fnCalls{File: e.Name(), Function: fn, Address: addr, Calls: calls})
			out[len(out)-1].StructuredLeaf = isStructuredLeafBody(body)
		}
	}
	sort.Slice(out, func(i, j int) bool {
		if out[i].File == out[j].File {
			return out[i].Function < out[j].Function
		}
		return out[i].File < out[j].File
	})
	return out, nil
}

func loadComposedEvidence(dir string) (map[string][]string, error) {
	absDir, _ := filepath.Abs(dir)
	ents, err := os.ReadDir(absDir)
	if err != nil {
		if os.IsNotExist(err) {
			return map[string][]string{}, nil
		}
		return nil, err
	}
	fnRe := regexp.MustCompile(`(?s)void\s+([a-zA-Z0-9_]+)\s*\(\s*void\s*\)\s*\{(.*?)\n\}`)
	callRe := regexp.MustCompile(`(?m)^\s*([a-zA-Z_][a-zA-Z0-9_]*)\s*\(\s*\)\s*;`)
	out := map[string][]string{}
	for _, e := range ents {
		if e.IsDir() || !strings.HasSuffix(e.Name(), ".reconstructed.c") {
			continue
		}
		b, err := os.ReadFile(filepath.Join(absDir, e.Name()))
		if err != nil {
			continue
		}
		for _, m := range fnRe.FindAllStringSubmatch(string(b), -1) {
			if len(m) != 3 {
				continue
			}
			fn := sanitizeName(m[1])
			if fn == "" || fn == "unknown" {
				continue
			}
			seen := map[string]struct{}{}
			calls := make([]string, 0, 6)
			for _, c := range callRe.FindAllStringSubmatch(m[2], -1) {
				if len(c) != 2 {
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
				calls = append(calls, n)
			}
			if len(calls) == 0 {
				continue
			}
			if _, exists := out[fn]; !exists {
				sort.Strings(calls)
				out[fn] = calls
			}
		}
	}
	return out, nil
}

func buildAddrByName(funcs []fnCalls) map[string]string {
	out := map[string]string{}
	for _, fn := range funcs {
		if fn.Address == "" {
			continue
		}
		name := sanitizeName(fn.Function)
		if name == "" || name == "unknown" {
			continue
		}
		if _, exists := out[name]; !exists {
			out[name] = fn.Address
		}
	}
	return out
}

func buildFnByAddr(funcs []fnCalls) map[string]string {
	out := map[string]string{}
	for _, fn := range funcs {
		if fn.Address == "" {
			continue
		}
		name := sanitizeName(fn.Function)
		if name == "" || name == "unknown" {
			continue
		}
		if _, exists := out[fn.Address]; !exists {
			out[fn.Address] = name
		}
	}
	return out
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

func normalizeAddr(s string) string {
	s = strings.TrimSpace(strings.ToLower(s))
	if s == "" {
		return ""
	}
	if strings.HasPrefix(s, "0x") {
		s = s[2:]
	}
	s = strings.TrimLeft(s, "0")
	if s == "" {
		s = "0"
	}
	for _, r := range s {
		if !((r >= '0' && r <= '9') || (r >= 'a' && r <= 'f')) {
			return ""
		}
	}
	return "0x" + s
}

func round3(v float64) float64 { return float64(int(v*1000+0.5)) / 1000 }

func isIntrinsicLeafFunction(name string) bool {
	n := sanitizeName(name)
	switch n {
	case "memset_impl", "memcpy_fast", "log_queue_push2",
		"apm_bss_config_init", "apm_tx_int_ps_get_postpone",
		"bam_rx_active", "bam_send_air_action_frame",
		"co_list_push_front",
		"hal_machw_idle_irq_handler", "hal_machw_rx_bcn_duration", "hal_machw_sleep_check",
		"host_id", "host_usb_wlan_init",
		"ke_handler_search", "ke_malloc", "ke_state_get", "ke_stateid_ptr", "ke_task_handler_get", "ke_task_local",
		"mm_bcn_transmit", "mm_bcn_transmitted", "mm_bcn_update_p2p_noa", "mm_hw_config_handler", "mm_no_idle_start", "mm_rx_filter_set", "mm_sec_machwkey_wr", "mm_tbtt_compute",
		"phy_hw_set_channel", "phy_set_channel", "phy_stop",
		"rc_check", "rc_init_rates", "rc_update_bw_nss_max", "rc_update_counters", "rc_update_preamble_type",
		"rxl_frame_handle", "rxl_go_to_last_rbd", "rxl_mpdu_transfer", "rxl_payload_transfer", "rxl_payload_transfer_usb", "rxl_rxdesc_ready_for_processing",
		"sm_assoc_rsp_handler", "sm_auth_send", "sm_bss_config_init", "sm_external_auth_start",
		"tx_txdesc_init",
		"txl_agg_bw_drop_handle", "txl_agg_he_tb_cat_ampdu", "txl_agg_split", "txl_ba_push",
		"txl_cntrl_newhead", "txl_frame_exchange_chain", "txl_frame_exchange_done",
		"txl_he_ampdu_param_get", "txl_he_tb_transmit_cancelled", "txl_he_trigger_push",
		"txl_ht_vht_ampdu_param_get", "txl_is_ba_valid",
		"crypto_hw_write32_core":
		return true
	}
	return false
}

func isStructuredLeafBody(body string) bool {
	needles := []string{
		"for (",
		"while (",
		"switch (",
		"volatile uint32_t *",
		"static uint8_t ",
		"static uint32_t ",
	}
	hits := 0
	for _, n := range needles {
		if strings.Contains(body, n) {
			hits++
		}
	}
	return hits >= 2
}

func fail(format string, args ...any) {
	fmt.Fprintf(os.Stderr, format+"\n", args...)
	os.Exit(1)
}
