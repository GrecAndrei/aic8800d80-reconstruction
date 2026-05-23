package main

import (
	"bufio"
	"encoding/json"
	"flag"
	"fmt"
	"os"
	"os/exec"
	"path/filepath"
	"sort"
	"strconv"
	"strings"
	"sync"
	"syscall"
	"time"
)

type profile struct {
	Name         string `json:"name"`
	Thresholds   string `json:"thresholds"`
	NeighborMax  string `json:"neighbor_max"`
	NeighborStep string `json:"neighbor_step"`
	ActionableN  int    `json:"actionable_top_n"`
	PackSize     int    `json:"pack_size"`
}

type profileResult struct {
	Name        string  `json:"name"`
	OutDir      string  `json:"out_dir"`
	StartedAt   string  `json:"started_at"`
	FinishedAt  string  `json:"finished_at"`
	DurationSec float64 `json:"duration_sec"`
	Status      string  `json:"status"`
	Error       string  `json:"error,omitempty"`
	LogPath     string  `json:"log_path,omitempty"`
	SummaryPath string  `json:"summary_path,omitempty"`
	UnionCount  int     `json:"union_count,omitempty"`
}

type megaSummary struct {
	SchemaVersion string          `json:"schema_version"`
	GeneratedAt   string          `json:"generated_at"`
	RunTagPrefix  string          `json:"run_tag_prefix"`
	Root          string          `json:"root"`
	BaseOutDir    string          `json:"base_out_dir"`
	Concurrency   int             `json:"concurrency"`
	MinDiskFreeGB float64         `json:"min_disk_free_gb"`
	Profiles      []profile       `json:"profiles"`
	Results       []profileResult `json:"results"`
	SuccessCount  int             `json:"success_count"`
	FailedCount   int             `json:"failed_count"`
	TotalUnion    int             `json:"total_union_count"`
}

func main() {
	var root string
	var out string
	var runTagPrefix string
	var profileSpec string
	var concurrency int
	var minDiskFreeGB float64
	var keepSweeps int
	var keepRuns int
	var keepProfiles int
	var keepMegaSummaries int
	var leanRuns bool
	var pruneOnly bool
	var extraPruneOuts string
	var pruneDeep bool
	var postPruneDeep bool
	var reconcileOnly bool
	var unionShards int
	var ramCapEnabled bool
	var ramCapGB float64

	flag.StringVar(&root, "root", ".", "Workspace root containing firmware blobs")
	flag.StringVar(&out, "out", "extraction_out/mega", "Base output directory for mega profile runs")
	flag.StringVar(&runTagPrefix, "run-tag-prefix", "mega", "Run tag prefix for nested fwsweep runs")
	flag.StringVar(&profileSpec, "profiles", "", "Semicolon-separated profile list: name|thresholds|neighbor_max|neighbor_step|actionable_top_n|pack_size")
	flag.IntVar(&concurrency, "concurrency", 3, "Maximum concurrent profile runs")
	flag.Float64Var(&minDiskFreeGB, "min-disk-free-gb", 20, "Pause launches when free disk is below this threshold")
	flag.IntVar(&keepSweeps, "keep-sweeps", 2, "Pass-through retention for fwsweep")
	flag.IntVar(&keepRuns, "keep-runs", 3, "Pass-through retention for fwsweep")
	flag.IntVar(&keepProfiles, "keep-profiles", 3, "Keep only newest N profile output dirs under mega out (0 disables)")
	flag.IntVar(&keepMegaSummaries, "keep-mega-summaries", 8, "Keep only newest N mega summary files (0 disables)")
	flag.BoolVar(&leanRuns, "lean-runs", true, "Enable lean per-run artifact pruning in nested fwsweep runs")
	flag.BoolVar(&pruneOnly, "prune-only", false, "Prune outputs and exit without launching sweeps")
	flag.StringVar(&extraPruneOuts, "extra-prune-outs", "", "Comma-separated additional mega output dirs to prune before run")
	flag.BoolVar(&pruneDeep, "prune-deep", false, "Deep-prune profile internals (runs and bulky sweep artifacts), keeping summaries")
	flag.BoolVar(&postPruneDeep, "post-prune-deep", false, "After run, deep-prune all profile dirs in current out dir")
	flag.BoolVar(&reconcileOnly, "reconcile-only", false, "Rebuild latest mega summary from existing profile sweep summaries and exit")
	flag.IntVar(&unionShards, "union-shards", 512, "Pass-through union shard count for nested fwsweep (higher reduces RAM spikes)")
	flag.BoolVar(&ramCapEnabled, "ram-cap-enabled", true, "Auto-cap concurrency on low-RAM hosts")
	flag.Float64Var(&ramCapGB, "ram-cap-gb", 18.0, "If MemTotal <= this, reduce default concurrency to 1")
	flag.Parse()

	profiles, err := parseProfiles(profileSpec)
	if err != nil {
		fmt.Fprintf(os.Stderr, "invalid profiles: %v\n", err)
		os.Exit(1)
	}
	if concurrency < 1 {
		concurrency = 1
	}
	memGB := detectMemTotalGB()
	if ramCapEnabled && memGB > 0 && memGB <= ramCapGB && concurrency > 1 {
		fmt.Printf("ram-cap applied: mem_total_gb=%.2f requested_concurrency=%d adjusted_concurrency=1\n", memGB, concurrency)
		concurrency = 1
	}
	sort.Slice(profiles, func(i, j int) bool {
		return profileWeight(profiles[i]) > profileWeight(profiles[j])
	})

	rootAbs, err := filepath.Abs(root)
	if err != nil {
		fmt.Fprintf(os.Stderr, "resolve root: %v\n", err)
		os.Exit(1)
	}
	outAbs, err := filepath.Abs(out)
	if err != nil {
		fmt.Fprintf(os.Stderr, "resolve out: %v\n", err)
		os.Exit(1)
	}
	if err := os.MkdirAll(outAbs, 0o755); err != nil {
		fmt.Fprintf(os.Stderr, "mkdir out: %v\n", err)
		os.Exit(1)
	}
	pruneTargets := []string{outAbs}
	for _, raw := range strings.Split(extraPruneOuts, ",") {
		raw = strings.TrimSpace(raw)
		if raw == "" {
			continue
		}
		p, e := filepath.Abs(raw)
		if e != nil {
			continue
		}
		pruneTargets = append(pruneTargets, p)
	}
	totalPrunedProfiles := 0
	totalPrunedSummaries := 0
	if !reconcileOnly {
		for _, t := range dedupeStrings(pruneTargets) {
			_ = os.MkdirAll(t, 0o755)
			prunedProfiles, prunedSummaries, pruneErr := pruneMegaOutputs(t, keepProfiles, keepMegaSummaries, pruneDeep)
			if pruneErr != nil {
				fmt.Fprintf(os.Stderr, "prune warning (%s): %v\n", t, pruneErr)
			}
			totalPrunedProfiles += prunedProfiles
			totalPrunedSummaries += prunedSummaries
		}
	}
	if pruneOnly {
		fmt.Printf("prune complete.\n")
		fmt.Printf("  targets: %d\n", len(dedupeStrings(pruneTargets)))
		fmt.Printf("  pruned_profiles: %d\n", totalPrunedProfiles)
		fmt.Printf("  pruned_mega_summaries: %d\n", totalPrunedSummaries)
		return
	}
	if reconcileOnly {
		recon, err := reconcileFromExisting(outAbs, runTagPrefix, concurrency, minDiskFreeGB)
		if err != nil {
			fmt.Fprintf(os.Stderr, "reconcile failed: %v\n", err)
			os.Exit(1)
		}
		summaryPath := filepath.Join(outAbs, fmt.Sprintf("%s_%s_summary.json", sanitize(runTagPrefix), time.Now().UTC().Format("20060102T150405Z")))
		if err := writeJSON(summaryPath, recon); err != nil {
			fmt.Fprintf(os.Stderr, "write reconciled summary: %v\n", err)
			os.Exit(1)
		}
		latestPath := filepath.Join(outAbs, "latest_mega_summary.json")
		if err := writeJSON(latestPath, recon); err != nil {
			fmt.Fprintf(os.Stderr, "write latest reconciled summary: %v\n", err)
			os.Exit(1)
		}
		fmt.Printf("reconcile complete.\n")
		fmt.Printf("  profiles: %d\n", len(recon.Results))
		fmt.Printf("  success: %d\n", recon.SuccessCount)
		fmt.Printf("  failed: %d\n", recon.FailedCount)
		fmt.Printf("  total_union_count: %d\n", recon.TotalUnion)
		fmt.Printf("  summary_path: %s\n", summaryPath)
		fmt.Printf("  latest_summary_path: %s\n", latestPath)
		return
	}

	results := make([]profileResult, len(profiles))
	sem := make(chan struct{}, concurrency)
	var wg sync.WaitGroup
	var mu sync.Mutex

	for i, p := range profiles {
		wg.Add(1)
		go func(idx int, prof profile) {
			defer wg.Done()
			for {
				freeGB, _ := diskUsageGB(outAbs)
				if freeGB >= minDiskFreeGB {
					break
				}
				time.Sleep(5 * time.Second)
			}
			sem <- struct{}{}
			defer func() { <-sem }()

			started := time.Now().UTC()
			res := runProfile(rootAbs, outAbs, runTagPrefix, prof, keepSweeps, keepRuns, leanRuns, unionShards, started)
			mu.Lock()
			results[idx] = res
			mu.Unlock()
		}(i, p)
	}

	wg.Wait()
	now := time.Now().UTC()
	sort.Slice(results, func(i, j int) bool { return results[i].Name < results[j].Name })

	summary := megaSummary{
		SchemaVersion: "0.1.0",
		GeneratedAt:   now.Format(time.RFC3339),
		RunTagPrefix:  sanitize(runTagPrefix),
		Root:          rootAbs,
		BaseOutDir:    outAbs,
		Concurrency:   concurrency,
		MinDiskFreeGB: minDiskFreeGB,
		Profiles:      profiles,
		Results:       results,
	}
	for _, r := range results {
		if r.Status == "ok" {
			summary.SuccessCount++
			summary.TotalUnion += r.UnionCount
		} else if r.Status == "partial" {
			summary.TotalUnion += r.UnionCount
		} else {
			summary.FailedCount++
		}
	}

	summaryPath := filepath.Join(outAbs, fmt.Sprintf("%s_%s_summary.json", sanitize(runTagPrefix), now.Format("20060102T150405Z")))
	if err := writeJSON(summaryPath, summary); err != nil {
		fmt.Fprintf(os.Stderr, "write mega summary: %v\n", err)
		os.Exit(1)
	}
	latestPath := filepath.Join(outAbs, "latest_mega_summary.json")
	if err := writeJSON(latestPath, summary); err != nil {
		fmt.Fprintf(os.Stderr, "write latest mega summary: %v\n", err)
		os.Exit(1)
	}
	postPrunedProfiles := 0
	if postPruneDeep {
		for _, r := range results {
			if r.OutDir == "" {
				continue
			}
			if err := deepPruneProfileDir(r.OutDir); err == nil {
				postPrunedProfiles++
			}
		}
	}

	fmt.Printf("mega complete.\n")
	fmt.Printf("  profiles: %d\n", len(profiles))
	fmt.Printf("  success: %d\n", summary.SuccessCount)
	fmt.Printf("  failed: %d\n", summary.FailedCount)
	fmt.Printf("  total_union_count: %d\n", summary.TotalUnion)
	fmt.Printf("  pruned_profiles: %d\n", totalPrunedProfiles)
	fmt.Printf("  pruned_mega_summaries: %d\n", totalPrunedSummaries)
	fmt.Printf("  post_pruned_profiles: %d\n", postPrunedProfiles)
	fmt.Printf("  summary_path: %s\n", summaryPath)
	fmt.Printf("  latest_summary_path: %s\n", latestPath)
}

func runProfile(rootAbs, outAbs, runTagPrefix string, p profile, keepSweeps, keepRuns int, leanRuns bool, unionShards int, started time.Time) profileResult {
	runOut := filepath.Join(outAbs, sanitize(p.Name))
	_ = os.MkdirAll(runOut, 0o755)
	tag := fmt.Sprintf("%s_%s", sanitize(runTagPrefix), sanitize(p.Name))
	args := []string{
		"run", "./cmd/fwsweep",
		"-root", rootAbs,
		"-out", runOut,
		"-thresholds", p.Thresholds,
		"-queue-limit", "0",
		"-run-tag-prefix", tag,
		"-impact-min-score", "0.9",
		"-impact-min-seen", "1",
		"-actionable-top-n", strconv.Itoa(maxInt(1000, p.ActionableN)),
		"-pack-size", strconv.Itoa(maxInt(200, p.PackSize)),
		"-neighbor-max", p.NeighborMax,
		"-neighbor-step", p.NeighborStep,
		"-keep-sweeps", strconv.Itoa(maxInt(0, keepSweeps)),
		"-keep-runs", strconv.Itoa(maxInt(0, keepRuns)),
		"-lean-runs", strconv.FormatBool(leanRuns),
		"-union-shards", strconv.Itoa(maxInt(64, unionShards)),
	}
	cmd := exec.Command("go", args...)
	cmd.Dir = rootAbs
	cmd.Env = os.Environ()
	out, err := cmd.CombinedOutput()
	finished := time.Now().UTC()
	res := profileResult{
		Name:        p.Name,
		OutDir:      runOut,
		StartedAt:   started.Format(time.RFC3339),
		FinishedAt:  finished.Format(time.RFC3339),
		DurationSec: finished.Sub(started).Seconds(),
		Status:      "ok",
	}
	res.LogPath = filepath.Join(runOut, "last_fwmega_run.log")
	_ = os.WriteFile(res.LogPath, out, 0o644)
	if err != nil {
		res.Status = "failed"
		res.Error = strings.TrimSpace(string(out))
		summaryPath, unionCount := discoverLatestSweepSummary(runOut)
		if summaryPath != "" {
			res.Status = "partial"
			res.SummaryPath = summaryPath
			res.UnionCount = unionCount
		}
		return res
	}
	lines := strings.Split(string(out), "\n")
	for _, ln := range lines {
		ln = strings.TrimSpace(ln)
		if strings.HasPrefix(ln, "summary_path:") {
			res.SummaryPath = strings.TrimSpace(strings.TrimPrefix(ln, "summary_path:"))
		}
		if strings.HasPrefix(ln, "union_count:") {
			v := strings.TrimSpace(strings.TrimPrefix(ln, "union_count:"))
			if n, convErr := strconv.Atoi(v); convErr == nil {
				res.UnionCount = n
			}
		}
	}
	return res
}

func discoverLatestSweepSummary(runOut string) (string, int) {
	sweepDir := filepath.Join(runOut, "sweeps")
	entries, err := os.ReadDir(sweepDir)
	if err != nil {
		return discoverRunSummaryFallback(runOut)
	}
	type candidate struct {
		path string
		mod  time.Time
	}
	cands := make([]candidate, 0, len(entries))
	for _, e := range entries {
		if e.IsDir() {
			continue
		}
		name := e.Name()
		if !strings.HasSuffix(name, "_summary.json") {
			continue
		}
		p := filepath.Join(sweepDir, name)
		st, statErr := os.Stat(p)
		if statErr != nil {
			continue
		}
		cands = append(cands, candidate{path: p, mod: st.ModTime()})
	}
	if len(cands) == 0 {
		return discoverRunSummaryFallback(runOut)
	}
	sort.Slice(cands, func(i, j int) bool { return cands[i].mod.After(cands[j].mod) })
	type sweepSummary struct {
		UnionCount int `json:"union_count"`
	}
	var s sweepSummary
	if b, readErr := os.ReadFile(cands[0].path); readErr == nil {
		_ = json.Unmarshal(b, &s)
	}
	return cands[0].path, s.UnionCount
}

func discoverRunSummaryFallback(runOut string) (string, int) {
	runsDir := filepath.Join(runOut, "runs")
	entries, err := os.ReadDir(runsDir)
	if err != nil {
		return "", 0
	}
	type runSummary struct {
		MiningQueueCount int `json:"mining_queue_count"`
	}
	bestCount := 0
	bestPath := ""
	for _, e := range entries {
		if !e.IsDir() {
			continue
		}
		p := filepath.Join(runsDir, e.Name(), "summary.json")
		b, readErr := os.ReadFile(p)
		if readErr != nil {
			continue
		}
		var rs runSummary
		if err := json.Unmarshal(b, &rs); err != nil {
			continue
		}
		if rs.MiningQueueCount > bestCount {
			bestCount = rs.MiningQueueCount
			bestPath = p
		}
	}
	return bestPath, bestCount
}

func parseProfiles(spec string) ([]profile, error) {
	if strings.TrimSpace(spec) == "" {
		return []profile{
			{Name: "ultra", Thresholds: "0.0,0.6,1.2", NeighborMax: "0x500", NeighborStep: "1", ActionableN: 10000, PackSize: 5000},
			{Name: "stratos", Thresholds: "0.0,0.8,1.6", NeighborMax: "0x700", NeighborStep: "1", ActionableN: 12000, PackSize: 6000},
			{Name: "omega", Thresholds: "0.0,1.0,2.0", NeighborMax: "0x900", NeighborStep: "1", ActionableN: 15000, PackSize: 7000},
		}, nil
	}
	parts := strings.Split(spec, ";")
	out := make([]profile, 0, len(parts))
	for _, raw := range parts {
		raw = strings.TrimSpace(raw)
		if raw == "" {
			continue
		}
		f := strings.Split(raw, "|")
		if len(f) < 4 {
			return nil, fmt.Errorf("profile %q needs at least 4 fields", raw)
		}
		p := profile{
			Name:         strings.TrimSpace(f[0]),
			Thresholds:   strings.TrimSpace(f[1]),
			NeighborMax:  strings.TrimSpace(f[2]),
			NeighborStep: strings.TrimSpace(f[3]),
			ActionableN:  10000,
			PackSize:     5000,
		}
		if p.Name == "" || p.Thresholds == "" {
			return nil, fmt.Errorf("profile %q has empty name/thresholds", raw)
		}
		if len(f) >= 5 && strings.TrimSpace(f[4]) != "" {
			n, err := strconv.Atoi(strings.TrimSpace(f[4]))
			if err != nil {
				return nil, fmt.Errorf("profile %q actionable_top_n: %w", raw, err)
			}
			p.ActionableN = n
		}
		if len(f) >= 6 && strings.TrimSpace(f[5]) != "" {
			n, err := strconv.Atoi(strings.TrimSpace(f[5]))
			if err != nil {
				return nil, fmt.Errorf("profile %q pack_size: %w", raw, err)
			}
			p.PackSize = n
		}
		out = append(out, p)
	}
	if len(out) == 0 {
		return nil, fmt.Errorf("no valid profiles")
	}
	return out, nil
}

func writeJSON(path string, v any) error {
	b, err := json.MarshalIndent(v, "", "  ")
	if err != nil {
		return err
	}
	return os.WriteFile(path, append(b, '\n'), 0o644)
}

func sanitize(s string) string {
	s = strings.TrimSpace(strings.ToLower(s))
	if s == "" {
		return "run"
	}
	repl := strings.NewReplacer(" ", "_", "/", "_", "\\", "_", ":", "_", ".", "p")
	return repl.Replace(s)
}

func maxInt(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func diskUsageGB(path string) (freeGB, usePct float64) {
	var st syscall.Statfs_t
	if err := syscall.Statfs(path, &st); err != nil {
		return 0, 0
	}
	total := float64(st.Blocks) * float64(st.Bsize)
	free := float64(st.Bavail) * float64(st.Bsize)
	if total <= 0 {
		return 0, 0
	}
	return free / (1024.0 * 1024.0 * 1024.0), (1.0 - (free / total)) * 100.0
}

func profileWeight(p profile) int64 {
	tCount := int64(1)
	for _, s := range strings.Split(p.Thresholds, ",") {
		if strings.TrimSpace(s) != "" {
			tCount++
		}
	}
	nMax := int64(0)
	raw := strings.TrimSpace(strings.ToLower(p.NeighborMax))
	if strings.HasPrefix(raw, "0x") {
		if v, err := strconv.ParseInt(raw[2:], 16, 64); err == nil {
			nMax = v
		}
	} else if raw != "" {
		if v, err := strconv.ParseInt(raw, 10, 64); err == nil {
			nMax = v
		}
	}
	if nMax == 0 {
		nMax = 0x300
	}
	return nMax*tCount + int64(p.ActionableN) + int64(p.PackSize)
}

func dedupeStrings(in []string) []string {
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

func pruneMegaOutputs(outAbs string, keepProfiles int, keepMegaSummaries int, pruneDeep bool) (prunedProfiles int, prunedSummaries int, err error) {
	type entry struct {
		path string
		mod  time.Time
	}
	if keepProfiles > 0 {
		ents, readErr := os.ReadDir(outAbs)
		if readErr == nil {
			profiles := make([]entry, 0, len(ents))
			for _, e := range ents {
				if !e.IsDir() {
					continue
				}
				if strings.HasPrefix(e.Name(), ".") {
					continue
				}
				p := filepath.Join(outAbs, e.Name())
				st, statErr := os.Stat(p)
				if statErr != nil {
					continue
				}
				profiles = append(profiles, entry{path: p, mod: st.ModTime()})
			}
			sort.Slice(profiles, func(i, j int) bool { return profiles[i].mod.After(profiles[j].mod) })
			if pruneDeep {
				limit := keepProfiles
				if limit > len(profiles) {
					limit = len(profiles)
				}
				for i := 0; i < limit; i++ {
					_ = deepPruneProfileDir(profiles[i].path)
				}
			}
			for i := keepProfiles; i < len(profiles); i++ {
				if removeErr := os.RemoveAll(profiles[i].path); removeErr == nil {
					prunedProfiles++
				}
			}
		}
	}
	if keepMegaSummaries > 0 {
		pattern := filepath.Join(outAbs, "*_summary.json")
		matches, _ := filepath.Glob(pattern)
		entries := make([]entry, 0, len(matches))
		for _, m := range matches {
			st, statErr := os.Stat(m)
			if statErr != nil {
				continue
			}
			entries = append(entries, entry{path: m, mod: st.ModTime()})
		}
		sort.Slice(entries, func(i, j int) bool { return entries[i].mod.After(entries[j].mod) })
		for i := keepMegaSummaries; i < len(entries); i++ {
			if removeErr := os.Remove(entries[i].path); removeErr == nil {
				prunedSummaries++
			}
		}
	}
	return prunedProfiles, prunedSummaries, nil
}

func deepPruneProfileDir(profileDir string) error {
	// Keep high-level summaries/logs, remove massive internals.
	_ = os.RemoveAll(filepath.Join(profileDir, "runs"))
	sweepsDir := filepath.Join(profileDir, "sweeps")
	ents, err := os.ReadDir(sweepsDir)
	if err != nil {
		if os.IsNotExist(err) {
			return nil
		}
		return err
	}
	type cand struct {
		path string
		mod  time.Time
	}
	summaries := make([]cand, 0, len(ents))
	for _, e := range ents {
		if e.IsDir() {
			continue
		}
		if !strings.HasSuffix(e.Name(), "_summary.json") {
			continue
		}
		p := filepath.Join(sweepsDir, e.Name())
		st, se := os.Stat(p)
		if se != nil {
			continue
		}
		summaries = append(summaries, cand{path: p, mod: st.ModTime()})
	}
	sort.Slice(summaries, func(i, j int) bool { return summaries[i].mod.After(summaries[j].mod) })
	keepBase := ""
	if len(summaries) > 0 {
		keepBase = strings.TrimSuffix(filepath.Base(summaries[0].path), "_summary.json")
	}
	for _, e := range ents {
		p := filepath.Join(sweepsDir, e.Name())
		if keepBase != "" && strings.HasPrefix(e.Name(), keepBase+"_") {
			// keep current summary and small companion files only
			if strings.HasSuffix(e.Name(), "_summary.json") || strings.HasSuffix(e.Name(), "_hotspots.json") {
				continue
			}
		}
		_ = os.RemoveAll(p)
	}
	return nil
}

func detectMemTotalGB() float64 {
	f, err := os.Open("/proc/meminfo")
	if err != nil {
		return 0
	}
	defer f.Close()
	s := bufio.NewScanner(f)
	for s.Scan() {
		line := strings.TrimSpace(s.Text())
		if !strings.HasPrefix(line, "MemTotal:") {
			continue
		}
		fields := strings.Fields(line)
		if len(fields) < 2 {
			return 0
		}
		kb, err := strconv.ParseFloat(fields[1], 64)
		if err != nil {
			return 0
		}
		return kb / (1024.0 * 1024.0)
	}
	return 0
}

func reconcileFromExisting(outAbs, runTagPrefix string, concurrency int, minDiskFreeGB float64) (megaSummary, error) {
	ents, err := os.ReadDir(outAbs)
	if err != nil {
		return megaSummary{}, err
	}
	results := make([]profileResult, 0, len(ents))
	profiles := make([]profile, 0, len(ents))
	for _, e := range ents {
		if !e.IsDir() {
			continue
		}
		name := e.Name()
		if strings.HasPrefix(name, ".") {
			continue
		}
		runOut := filepath.Join(outAbs, name)
		summaryPath, unionCount := discoverLatestSweepSummary(runOut)
		if summaryPath == "" {
			continue
		}
		results = append(results, profileResult{
			Name:        name,
			OutDir:      runOut,
			Status:      "ok",
			SummaryPath: summaryPath,
			UnionCount:  unionCount,
		})
		profiles = append(profiles, profile{Name: name})
	}
	sort.Slice(results, func(i, j int) bool { return results[i].Name < results[j].Name })
	now := time.Now().UTC().Format(time.RFC3339)
	s := megaSummary{
		SchemaVersion: "0.1.0",
		GeneratedAt:   now,
		RunTagPrefix:  sanitize(runTagPrefix),
		BaseOutDir:    outAbs,
		Concurrency:   concurrency,
		MinDiskFreeGB: minDiskFreeGB,
		Profiles:      profiles,
		Results:       results,
	}
	for _, r := range results {
		if r.Status == "ok" {
			s.SuccessCount++
		} else {
			s.FailedCount++
		}
		s.TotalUnion += r.UnionCount
	}
	return s, nil
}
