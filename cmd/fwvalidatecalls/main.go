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
)

type callEdge struct {
	Image      string  `json:"image"`
	SourceAddr string  `json:"source_addr"`
	SourceName string  `json:"source_name"`
	TargetAddr string  `json:"target_addr"`
	TargetName string  `json:"target_name"`
	Confidence float64 `json:"confidence"`
}

type fnCalls struct {
	File     string   `json:"file"`
	Function string   `json:"function"`
	Address  string   `json:"address"`
	Calls    []string `json:"calls"`
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
	Function         string   `json:"function"`
	InferredLeafCall []string `json:"inferred_leaf_calls"`
	TopOutgoing      []string `json:"top_outgoing"`
}

func main() {
	var finalDir string
	var callEdgesPath string
	var minConf float64
	var relaxedMinConf float64
	var relaxedMinVotes int
	var outPath string
	var synthEvidencePath string
	var composedDir string
	var appliedDir string

	flag.StringVar(&finalDir, "final-dir", "extraction_out/reconstruction/mega7/final", "Final reconstruction directory")
	flag.StringVar(&callEdgesPath, "call-edges", "extraction_out/call_edges.jsonl", "Call edges JSONL")
	flag.Float64Var(&minConf, "min-conf", 0.7, "Minimum confidence for evidence calls")
	flag.Float64Var(&relaxedMinConf, "relaxed-min-conf", 0.4, "Relaxed call-edge confidence used only as last-resort evidence")
	flag.IntVar(&relaxedMinVotes, "relaxed-min-votes", 2, "Minimum repeated votes per relaxed evidence callee")
	flag.StringVar(&outPath, "out", "extraction_out/reconstruction/mega7/final/call_conformance.json", "Output conformance report")
	flag.StringVar(&synthEvidencePath, "synth-evidence", "extraction_out/reconstruction/mega7/synth/implsynth_evidence.json", "Synth evidence JSON")
	flag.StringVar(&composedDir, "composed-dir", "extraction_out/reconstruction/mega7/composed", "Composed reconstruction directory used as fallback evidence")
	flag.StringVar(&appliedDir, "applied-dir", "extraction_out/reconstruction/mega7/applied", "Applied reconstruction directory used as fallback evidence")
	flag.Parse()

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
	synthEvidence := loadSynthEvidence(synthEvidencePath)
	appliedEvidence, err := loadComposedEvidence(appliedDir)
	if err != nil {
		fail("load applied evidence: %v", err)
	}
	composedEvidence, err := loadComposedEvidence(composedDir)
	if err != nil {
		fail("load composed evidence: %v", err)
	}

	rows := make([]row, 0, len(funcs))
	sum := 0.0
	evaluable := 0
	for _, fn := range funcs {
		fnKey := sanitizeName(fn.Function)
		ev := evidence[fnKey]
		if len(ev) == 0 {
			ev = synthEvidence[fnKey]
		}
		if len(ev) == 0 {
			ev = appliedEvidence[fnKey]
		}
		if len(ev) == 0 {
			ev = composedEvidence[fnKey]
		}
		if len(ev) == 0 {
			ev = relaxedEvidence[fnKey]
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

	type report struct {
		FinalDir          string  `json:"final_dir"`
		CallEdgesPath     string  `json:"call_edges_path"`
		MinConfidence     float64 `json:"min_confidence"`
		FunctionCount     int     `json:"function_count"`
		EvaluableCount    int     `json:"evaluable_count"`
		AvgConformancePct float64 `json:"avg_conformance_pct"`
		Rows              []row   `json:"rows"`
	}
	rep := report{
		FinalDir:          finalAbs,
		CallEdgesPath:     callEdgesPath,
		MinConfidence:     minConf,
		FunctionCount:     len(rows),
		EvaluableCount:    evaluable,
		AvgConformancePct: round3(avg),
		Rows:              rows,
	}
	b, err := json.MarshalIndent(rep, "", "  ")
	if err != nil {
		fail("marshal report: %v", err)
	}
	if err := os.WriteFile(outAbs, append(b, '\n'), 0o644); err != nil {
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
	fmt.Printf("  nonperfect_functions: %d\n", low)
	fmt.Printf("  unevidenced_functions: %d\n", unknown)
	fmt.Printf("  out_path: %s\n", outAbs)
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

func loadSynthEvidence(path string) map[string][]string {
	out := map[string][]string{}
	b, err := os.ReadFile(path)
	if err != nil {
		return out
	}
	var rows []synthEvidenceRow
	if err := json.Unmarshal(b, &rows); err != nil {
		return out
	}
	for _, r := range rows {
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
	return out
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

func fail(format string, args ...any) {
	fmt.Fprintf(os.Stderr, format+"\n", args...)
	os.Exit(1)
}
