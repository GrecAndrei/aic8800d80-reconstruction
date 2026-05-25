package pipeline

import (
	"bufio"
	"encoding/json"
	"os"
	"path/filepath"
	"strings"
)

type LearningSignal struct {
	Weight float64 `json:"weight"`
	Reason string  `json:"reason"`
	Source string  `json:"source"`
}

type smokeOutcomeRecord struct {
	Function     string `json:"function"`
	Status       string `json:"status"`
	FaultAddress string `json:"fault_address,omitempty"`
}

func loadLearningSignals(rootAbs string, outAbs string, runOutAbs string, functions []FunctionRecord) map[string]LearningSignal {
	signals := map[string]LearningSignal{}
	index := map[string][]FunctionRecord{}
	for _, fn := range functions {
		n := strings.ToLower(strings.TrimSpace(fn.Name))
		if n == "" {
			continue
		}
		index[n] = append(index[n], fn)
	}

	add := func(fn FunctionRecord, candidate LearningSignal) {
		k := strings.ToLower(fn.Image + "|" + fn.Name)
		cur, ok := signals[k]
		if !ok || candidate.Weight > cur.Weight {
			signals[k] = candidate
		}
	}

	for _, name := range loadSmokeCheckpointNames(filepath.Join(rootAbs, "README.md")) {
		for _, fn := range index[strings.ToLower(name)] {
			add(fn, LearningSignal{
				Weight: 1.0,
				Reason: "learned_smoke_checkpoint",
				Source: "readme_smoke_checkpoints",
			})
		}
	}

	candidates := []string{
		filepath.Join(rootAbs, "extraction_out", "reconstruction", "mega7", "smoke_observations.jsonl"),
		filepath.Join(rootAbs, "extraction_out", "reconstruction", "smoke_observations.jsonl"),
		filepath.Join(outAbs, "smoke_observations.jsonl"),
		filepath.Join(runOutAbs, "smoke_observations.jsonl"),
	}
	for _, path := range candidates {
		rows := loadSmokeOutcomes(path)
		for _, row := range rows {
			name := strings.ToLower(strings.TrimSpace(row.Function))
			if name == "" {
				continue
			}
			fns := index[name]
			if len(fns) == 0 {
				continue
			}

			status := strings.ToLower(strings.TrimSpace(row.Status))
			signal := LearningSignal{
				Weight: 0.45,
				Reason: "learned_smoke_seen",
				Source: "smoke_observations",
			}
			switch status {
			case "success":
				signal.Weight = 1.3
				signal.Reason = "learned_smoke_success"
			case "fault", "error", "failed":
				signal.Weight = 0.9
				signal.Reason = "learned_smoke_fault"
			}
			for _, fn := range fns {
				add(fn, signal)
			}
		}
	}

	return signals
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
