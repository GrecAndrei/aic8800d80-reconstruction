package main

import (
	"flag"
	"fmt"
	"os"
	"os/exec"
	"path/filepath"
	"strings"
)

func runCmd(rootAbs string, name string, args ...string) error {
	cmd := exec.Command(name, args...)
	cmd.Dir = rootAbs
	cmd.Stdout = os.Stdout
	cmd.Stderr = os.Stderr
	return cmd.Run()
}

func main() {
	var root string
	var runRoot string
	var primarySource string
	var sourceGlobsCSV string
	var seedCSV string
	var limit int
	var maxInsns int
	var missingCooldown int
	var recentWindowMin int
	var retryFaultOnce bool
	var preferNonCycleQueue bool
	var updateCheckpoints bool
	var checkpointMinSuccess int
	var checkpointMaxAdd int
	var readmePath string
	var outcomesPath string
	var gateTrend bool
	var gateLast int
	var gateMinSuccessRate float64
	var gateMaxMissingRate float64
	var pruneOldRuns bool
	var pruneKeepLatest int
	var tag string

	flag.StringVar(&root, "root", ".", "Repository root")
	flag.StringVar(&runRoot, "run-root", "extraction_out/reconstruction/mega7", "Reconstruction run root")
	flag.StringVar(&primarySource, "primary-source", "extraction_out/reconstruction/mega7/final/fmacfw_8800d80_u02_bin.reconstructed.c", "Primary reconstructed C source")
	flag.StringVar(&sourceGlobsCSV, "source-globs", "", "Comma-separated additional source globs")
	flag.StringVar(&seedCSV, "seeds", "0x40000000=0", "Comma-separated default seeds ADDR=VALUE")
	flag.IntVar(&limit, "limit", 10, "Probe target limit")
	flag.IntVar(&maxInsns, "max-insns", 120, "Max instructions per probe")
	flag.IntVar(&missingCooldown, "missing-cooldown", 2, "Skip targets with repeated missing-symbol outcomes")
	flag.IntVar(&recentWindowMin, "recent-window-min", 30, "Skip targets attempted within this many minutes")
	flag.BoolVar(&retryFaultOnce, "retry-fault-once", true, "Retry one time with learned fault seed on unmapped faults")
	flag.BoolVar(&preferNonCycleQueue, "prefer-non-cycle-queue", false, "Prefer latest non-cycle queue over latest cycle queue")
	flag.BoolVar(&updateCheckpoints, "update-checkpoints", true, "Automatically promote stable smoke successes into README after cycle")
	flag.IntVar(&checkpointMinSuccess, "checkpoint-min-success", 1, "Minimum success count required for checkpoint auto-promotion")
	flag.IntVar(&checkpointMaxAdd, "checkpoint-max-add", 15, "Maximum checkpoint entries auto-added per cycle")
	flag.StringVar(&readmePath, "readme", "README.md", "README path for checkpoint promotion")
	flag.StringVar(&outcomesPath, "outcomes", "", "Smoke outcomes JSONL path (default: <run-root>/smoke_observations.jsonl)")
	flag.BoolVar(&gateTrend, "gate-trend", false, "Run fwcycletrend gates after cycle")
	flag.IntVar(&gateLast, "gate-last", 12, "Number of recent cycles to evaluate in trend gating")
	flag.Float64Var(&gateMinSuccessRate, "gate-min-success-rate", 0, "Minimum success rate percent for trend gate")
	flag.Float64Var(&gateMaxMissingRate, "gate-max-missing-rate", 0, "Maximum missing-symbol rate percent for trend gate")
	flag.BoolVar(&pruneOldRuns, "prune-old-runs", true, "Gzip large run artifacts for older runs to save disk")
	flag.IntVar(&pruneKeepLatest, "prune-keep-latest", 8, "Number of latest runs to keep uncompressed when pruning")
	flag.StringVar(&tag, "tag", "", "Cycle run tag")
	flag.Parse()

	rootAbs, err := filepath.Abs(root)
	if err != nil {
		fmt.Fprintf(os.Stderr, "resolve root: %v\n", err)
		os.Exit(1)
	}

	if strings.TrimSpace(sourceGlobsCSV) == "" {
		sourceGlobsCSV = filepath.ToSlash(filepath.Join(runRoot, "final_recovered", "*.c")) + "," + filepath.ToSlash(filepath.Join(runRoot, "final", "*.c"))
	}
	if strings.TrimSpace(outcomesPath) == "" {
		outcomesPath = filepath.ToSlash(filepath.Join(runRoot, "smoke_observations.jsonl"))
	}

	args := []string{
		"tools/recon_cycle.py",
		"--run-root", runRoot,
		"--primary-source", primarySource,
		"--limit", fmt.Sprintf("%d", limit),
		"--max-insns", fmt.Sprintf("%d", maxInsns),
		"--missing-cooldown", fmt.Sprintf("%d", missingCooldown),
		"--recent-window-min", fmt.Sprintf("%d", recentWindowMin),
	}
	for _, g := range strings.Split(sourceGlobsCSV, ",") {
		g = strings.TrimSpace(g)
		if g == "" {
			continue
		}
		args = append(args, "--source-glob", g)
	}
	for _, s := range strings.Split(seedCSV, ",") {
		s = strings.TrimSpace(s)
		if s == "" {
			continue
		}
		args = append(args, "--seed", s)
	}
	if retryFaultOnce {
		args = append(args, "--retry-fault-once")
	}
	if preferNonCycleQueue {
		args = append(args, "--prefer-non-cycle-queue")
	}
	if tag != "" {
		args = append(args, "--tag", tag)
	}

	if err := runCmd(rootAbs, "python3", args...); err != nil {
		fmt.Fprintf(os.Stderr, "run recon cycle: %v\n", err)
		os.Exit(1)
	}

	if updateCheckpoints {
		updateArgs := []string{
			"tools/update_smoke_checkpoints.py",
			"--readme", readmePath,
			"--outcomes", outcomesPath,
			"--min-success", fmt.Sprintf("%d", checkpointMinSuccess),
			"--max-add", fmt.Sprintf("%d", checkpointMaxAdd),
		}
		if err := runCmd(rootAbs, "python3", updateArgs...); err != nil {
			fmt.Fprintf(os.Stderr, "update smoke checkpoints: %v\n", err)
			os.Exit(1)
		}
	}

	if pruneOldRuns {
		pruneArgs := []string{
			"tools/prune_cycle_artifacts.py",
			"--run-root", runRoot,
			"--keep-latest", fmt.Sprintf("%d", pruneKeepLatest),
			"--file", "mining_queue_full.jsonl",
		}
		if err := runCmd(rootAbs, "python3", pruneArgs...); err != nil {
			fmt.Fprintf(os.Stderr, "prune old runs: %v\n", err)
			os.Exit(1)
		}
	}

	if !gateTrend {
		return
	}
	trendArgs := []string{
		"run", "./cmd/fwcycletrend",
		"-run-root", runRoot,
		"-last", fmt.Sprintf("%d", gateLast),
		"-min-success-rate", fmt.Sprintf("%.3f", gateMinSuccessRate),
		"-max-missing-rate", fmt.Sprintf("%.3f", gateMaxMissingRate),
	}
	if err := runCmd(rootAbs, "go", trendArgs...); err != nil {
		fmt.Fprintf(os.Stderr, "trend gate failed: %v\n", err)
		os.Exit(1)
	}
}
