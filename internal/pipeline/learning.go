package pipeline

import (
	"bufio"
	"encoding/json"
	"os"
	"path/filepath"
	"sort"
	"strconv"
	"strings"
)

type LearningSignal struct {
	Weight float64 `json:"weight"`
	Reason string  `json:"reason"`
	Source string  `json:"source"`
}

type smokeOutcomeRecord struct {
	Image            string `json:"image,omitempty"`
	Address          string `json:"address,omitempty"`
	Function         string `json:"function"`
	Status           string `json:"status"`
	FaultAddress     string `json:"fault_address,omitempty"`
	Instructions     int    `json:"instructions,omitempty"`
	MMIOReadCount    int    `json:"mmio_read_count,omitempty"`
	MMIOWriteCount   int    `json:"mmio_write_count,omitempty"`
	HelperTouchCount int    `json:"helper_touch_count,omitempty"`
	BranchDepthMax   int    `json:"branch_depth_max,omitempty"`
}

type LearningBundle struct {
	ByFunction        map[string]LearningSignal `json:"by_function"`
	ByPrefix          map[string]LearningSignal `json:"by_prefix"`
	OutcomeByFunction map[string]OutcomeStats   `json:"outcome_by_function,omitempty"`
}

type OutcomeStats struct {
	Seen                int `json:"seen"`
	Success             int `json:"success"`
	Returned            int `json:"returned,omitempty"`
	Capped              int `json:"capped,omitempty"`
	Fault               int `json:"fault"`
	Missing             int `json:"missing_symbol"`
	TraceMMIO           int `json:"trace_mmio_total"`
	TraceHelperTouch    int `json:"trace_helper_touch_total"`
	TraceBranchDepthMax int `json:"trace_branch_depth_max"`
}

func loadLearningSignals(rootAbs string, outAbs string, runOutAbs string, functions []FunctionRecord) LearningBundle {
	weights := learningWeightsFromEnv()

	bundle := LearningBundle{
		ByFunction:        map[string]LearningSignal{},
		ByPrefix:          map[string]LearningSignal{},
		OutcomeByFunction: map[string]OutcomeStats{},
	}
	signals := map[string]LearningSignal{}
	indexByName := map[string][]FunctionRecord{}
	indexByImageAddr := map[string][]FunctionRecord{}
	indexByImageName := map[string][]FunctionRecord{}
	for _, fn := range functions {
		n := strings.ToLower(strings.TrimSpace(fn.Name))
		if n == "" {
			continue
		}
		indexByName[n] = append(indexByName[n], fn)
		image := strings.ToLower(strings.TrimSpace(fn.Image))
		addr := normalizeAddressKey(fn.Address)
		if image != "" && addr != "" {
			indexByImageAddr[image+"|"+addr] = append(indexByImageAddr[image+"|"+addr], fn)
		}
		if image != "" {
			indexByImageName[image+"|"+n] = append(indexByImageName[image+"|"+n], fn)
		}
	}
	returnedNames := map[string]struct{}{}

	resolveOutcomeFunctions := func(row smokeOutcomeRecord) []FunctionRecord {
		name := strings.ToLower(strings.TrimSpace(row.Function))
		if name == "" {
			return nil
		}
		image := strings.ToLower(strings.TrimSpace(row.Image))
		addr := normalizeAddressKey(row.Address)
		if image != "" && addr != "" {
			if fns := indexByImageAddr[image+"|"+addr]; len(fns) > 0 {
				return fns
			}
		}
		if image != "" {
			if fns := indexByImageName[image+"|"+name]; len(fns) > 0 {
				return fns
			}
		}
		// Legacy outcomes may only carry function name. To avoid cross-image
		// leakage, only use name-only mapping when it is unique.
		if fns := indexByName[name]; len(fns) == 1 {
			return fns
		}
		return nil
	}

	add := func(fn FunctionRecord, candidate LearningSignal) {
		k := strings.ToLower(fn.Image + "|" + fn.Name)
		cur, ok := signals[k]
		if !ok || candidate.Weight > cur.Weight {
			signals[k] = candidate
		}
	}

	for _, name := range loadSmokeCheckpointNames(filepath.Join(rootAbs, "README.md")) {
		lowerName := strings.ToLower(name)
		fns := indexByName[lowerName]
		if len(fns) != 1 {
			continue
		}
		returnedNames[lowerName] = struct{}{}
		for _, fn := range fns {
			add(fn, LearningSignal{
				Weight: weights.Checkpoint,
				Reason: "learned_smoke_checkpoint",
				Source: "readme_smoke_checkpoints",
			})
		}
	}

	candidates := collectSmokeOutcomePaths(rootAbs, outAbs, runOutAbs)
	for _, path := range candidates {
		rows := loadSmokeOutcomes(path)
		for _, row := range rows {
			resolved := resolveOutcomeFunctions(row)
			if len(resolved) == 0 {
				continue
			}
			status := strings.ToLower(strings.TrimSpace(row.Status))
			if status == "success" {
				status = "returned"
			}
			if status == "returned" {
				for _, fn := range resolved {
					returnedNames[strings.ToLower(strings.TrimSpace(fn.Name))] = struct{}{}
				}
			}
			for _, fn := range resolved {
				k := strings.ToLower(fn.Image + "|" + fn.Name)
				st := bundle.OutcomeByFunction[k]
				st.Seen++
				st.TraceMMIO += maxInt(0, row.MMIOReadCount) + maxInt(0, row.MMIOWriteCount)
				st.TraceHelperTouch += maxInt(0, row.HelperTouchCount)
				if row.BranchDepthMax > st.TraceBranchDepthMax {
					st.TraceBranchDepthMax = row.BranchDepthMax
				}
				switch status {
				case "returned":
					st.Success++
					st.Returned++
				case "capped":
					st.Capped++
				case "missing_symbol":
					st.Missing++
				case "fault", "error", "failed":
					st.Fault++
				}
				bundle.OutcomeByFunction[k] = st
			}

			traceBoost := 0.0
			if row.BranchDepthMax > 0 {
				traceBoost += float64(minInt(row.BranchDepthMax, 6)) * weights.TraceBranchDepth
			}
			if row.HelperTouchCount > 0 {
				traceBoost += float64(minInt(row.HelperTouchCount, 8)) * weights.TraceHelperTouch
			}
			mmioTotal := maxInt(0, row.MMIOReadCount) + maxInt(0, row.MMIOWriteCount)
			if mmioTotal > 0 {
				traceBoost += float64(minInt(mmioTotal, 16)) * weights.TraceMMIO
			}

			signal := LearningSignal{
				Weight: weights.Seen,
				Reason: "learned_smoke_seen",
				Source: "smoke_observations",
			}
			switch status {
			case "returned":
				signal.Weight = weights.Success
				signal.Reason = "learned_smoke_returned"
			case "capped":
				signal.Weight = weights.Capped
				signal.Reason = "learned_smoke_capped"
			case "missing_symbol":
				signal.Weight = weights.MissingSymbol
				signal.Reason = "learned_missing_symbol"
			case "fault", "error", "failed":
				signal.Weight = weights.Fault
				signal.Reason = "learned_smoke_fault"
			}
			signal.Weight += traceBoost
			if traceBoost > 0 {
				signal.Reason = signal.Reason + "_trace_enriched"
			}
			for _, fn := range resolved {
				add(fn, signal)
			}
		}
	}

	prefixCounts := map[string]int{}
	for name := range returnedNames {
		p := functionPrefix(name)
		if p == "" {
			continue
		}
		prefixCounts[p]++
	}
	for prefix, cnt := range prefixCounts {
		// Keep only stable prefixes with repeated wins.
		if cnt < 2 {
			continue
		}
		w := weights.PrefixBase
		if cnt >= 4 {
			w = weights.PrefixMid
		}
		if cnt >= 8 {
			w = weights.PrefixHigh
		}
		bundle.ByPrefix[prefix] = LearningSignal{
			Weight: w,
			Reason: "learned_prefix_success",
			Source: "smoke_history",
		}
	}

	bundle.ByFunction = signals
	return bundle
}

func collectSmokeOutcomePaths(rootAbs string, outAbs string, runOutAbs string) []string {
	candidates := []string{
		filepath.Join(rootAbs, "extraction_out", "reconstruction", "mega7", "smoke_observations.jsonl"),
		filepath.Join(rootAbs, "extraction_out", "reconstruction", "smoke_observations.jsonl"),
		filepath.Join(outAbs, "smoke_observations.jsonl"),
		filepath.Join(runOutAbs, "smoke_observations.jsonl"),
	}
	seen := map[string]struct{}{}
	out := make([]string, 0, len(candidates)+16)
	for _, p := range candidates {
		if _, ok := seen[p]; ok {
			continue
		}
		seen[p] = struct{}{}
		out = append(out, p)
	}
	runsDir := filepath.Join(outAbs, "runs")
	entries, err := os.ReadDir(runsDir)
	if err == nil {
		for _, e := range entries {
			if !e.IsDir() {
				continue
			}
			p := filepath.Join(runsDir, e.Name(), "smoke_observations.jsonl")
			if _, ok := seen[p]; ok {
				continue
			}
			seen[p] = struct{}{}
			out = append(out, p)
		}
	}
	sort.Strings(out)
	return out
}

func loadSmokeCheckpointNames(readmePath string) []string {
	f, err := os.Open(readmePath)
	if err != nil {
		return nil
	}
	defer f.Close()

	out := make([]string, 0, 256)
	seen := map[string]struct{}{}
	inSection := false
	s := bufio.NewScanner(f)
	for s.Scan() {
		line := strings.TrimSpace(s.Text())
		if strings.HasPrefix(line, "## ") {
			inSection = strings.EqualFold(line, "## Smoke Checkpoints")
			continue
		}
		if !inSection {
			continue
		}
		if !strings.HasPrefix(line, "- ") {
			continue
		}
		start := strings.Index(line, "`")
		if start < 0 {
			continue
		}
		end := strings.Index(line[start+1:], "`")
		if end < 0 {
			continue
		}
		name := strings.TrimSpace(line[start+1 : start+1+end])
		if name == "" {
			continue
		}
		k := strings.ToLower(name)
		if _, ok := seen[k]; ok {
			continue
		}
		seen[k] = struct{}{}
		out = append(out, name)
	}
	return out
}

func loadSmokeOutcomes(path string) []smokeOutcomeRecord {
	f, err := os.Open(path)
	if err != nil {
		return nil
	}
	defer f.Close()

	out := make([]smokeOutcomeRecord, 0, 256)
	s := bufio.NewScanner(f)
	s.Buffer(make([]byte, 1024), 1024*1024)
	for s.Scan() {
		line := strings.TrimSpace(s.Text())
		if line == "" {
			continue
		}
		var row smokeOutcomeRecord
		if err := json.Unmarshal([]byte(line), &row); err != nil {
			continue
		}
		out = append(out, row)
	}
	return out
}

func functionPrefix(name string) string {
	name = strings.TrimSpace(strings.ToLower(name))
	if name == "" {
		return ""
	}
	if i := strings.IndexByte(name, '_'); i > 0 {
		return name[:i]
	}
	return name
}

func normalizeAddressKey(v string) string {
	raw := strings.TrimSpace(strings.ToLower(v))
	if raw == "" {
		return ""
	}
	if strings.HasPrefix(raw, "0x") {
		n, err := strconv.ParseUint(raw[2:], 16, 64)
		if err != nil {
			return ""
		}
		return "0x" + strconv.FormatUint(n, 16)
	}
	n, err := strconv.ParseUint(raw, 0, 64)
	if err != nil {
		return ""
	}
	return "0x" + strconv.FormatUint(n, 16)
}

type learningWeights struct {
	Checkpoint       float64
	Seen             float64
	Success          float64
	Capped           float64
	MissingSymbol    float64
	Fault            float64
	PrefixBase       float64
	PrefixMid        float64
	PrefixHigh       float64
	TraceMMIO        float64
	TraceHelperTouch float64
	TraceBranchDepth float64
}

func learningWeightsFromEnv() learningWeights {
	return learningWeights{
		Checkpoint:       envLearningFloat("FW_LEARNING_WEIGHT_CHECKPOINT", 1.0),
		Seen:             envLearningFloat("FW_LEARNING_WEIGHT_SEEN", 0.45),
		Success:          envLearningFloat("FW_LEARNING_WEIGHT_SUCCESS", 1.3),
		Capped:           envLearningFloat("FW_LEARNING_WEIGHT_CAPPED", 0.3),
		MissingSymbol:    envLearningFloat("FW_LEARNING_WEIGHT_MISSING_SYMBOL", 0.2),
		Fault:            envLearningFloat("FW_LEARNING_WEIGHT_FAULT", 0.9),
		PrefixBase:       envLearningFloat("FW_LEARNING_WEIGHT_PREFIX_BASE", 0.25),
		PrefixMid:        envLearningFloat("FW_LEARNING_WEIGHT_PREFIX_MID", 0.4),
		PrefixHigh:       envLearningFloat("FW_LEARNING_WEIGHT_PREFIX_HIGH", 0.55),
		TraceMMIO:        envLearningFloat("FW_LEARNING_WEIGHT_TRACE_MMIO", 0.015),
		TraceHelperTouch: envLearningFloat("FW_LEARNING_WEIGHT_TRACE_HELPER_TOUCH", 0.04),
		TraceBranchDepth: envLearningFloat("FW_LEARNING_WEIGHT_TRACE_BRANCH_DEPTH", 0.03),
	}
}

func maxInt(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func minInt(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func envLearningFloat(name string, def float64) float64 {
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
