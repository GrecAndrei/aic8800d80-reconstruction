package main

import (
	"bufio"
	"encoding/json"
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
	var minSuccessInsns int
	var shallowCooldown int
	var missingCooldown int
	var recentWindowMin int
	var retryFaultOnce bool
	var retryShallowSuccess bool
	var shallowRetryMaxInsns int
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
	var autoImplOnPlateau bool
	var plateauDeltaSuccessMax int
	var autoImplMaxTasks int
	var plateauEscalateAfter int
	var plateauEscalateStep int
	var plateauEscalateMax int
	var throttleProbesOnPlateau bool
	var throttlePlateauAfter int
	var throttleLimit int
	var implMinCallConf float64
	var implFallbackMinCallConf float64
	var plateauLowerConfAfter int
	var plateauLoweredMinCallConf float64
	var plateauLoweredFallbackMinCallConf float64
	var tag string

	flag.StringVar(&root, "root", ".", "Repository root")
	flag.StringVar(&runRoot, "run-root", "extraction_out/reconstruction/mega7", "Reconstruction run root")
	flag.StringVar(&primarySource, "primary-source", "extraction_out/reconstruction/mega7/final/fmacfw_8800d80_u02_bin.reconstructed.c", "Primary reconstructed C source")
	flag.StringVar(&sourceGlobsCSV, "source-globs", "", "Comma-separated additional source globs")
	flag.StringVar(&seedCSV, "seeds", "0x40000000=0", "Comma-separated default seeds ADDR=VALUE")
	flag.IntVar(&limit, "limit", 10, "Probe target limit")
	flag.IntVar(&maxInsns, "max-insns", 120, "Max instructions per probe")
	flag.IntVar(&minSuccessInsns, "min-success-insns", 8, "Treat success below this instruction count as shallow")
	flag.IntVar(&shallowCooldown, "shallow-cooldown", 3, "Skip targets with repeated shallow-success outcomes")
	flag.IntVar(&missingCooldown, "missing-cooldown", 2, "Skip targets with repeated missing-symbol outcomes")
	flag.IntVar(&recentWindowMin, "recent-window-min", 30, "Skip targets attempted within this many minutes")
	flag.BoolVar(&retryFaultOnce, "retry-fault-once", true, "Retry one time with learned fault seed on unmapped faults")
	flag.BoolVar(&retryShallowSuccess, "retry-shallow-success", true, "Retry shallow successes once with higher instruction budget")
	flag.IntVar(&shallowRetryMaxInsns, "shallow-retry-max-insns", 512, "Instruction cap used for shallow-success retries")
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
	flag.BoolVar(&autoImplOnPlateau, "auto-impl-on-plateau", true, "When learning stalls, run compose/implqueue/implsynth/applysynth/finalize automatically")
	flag.IntVar(&plateauDeltaSuccessMax, "plateau-delta-success-max", 0, "Plateau trigger threshold for delta_learning_smoke_success_count")
	flag.IntVar(&autoImplMaxTasks, "auto-impl-max-tasks", 80, "Max tasks for auto impl synthesis when plateau trigger fires")
	flag.IntVar(&plateauEscalateAfter, "plateau-escalate-after", 2, "Escalate impl task budget after this many consecutive plateau cycles")
	flag.IntVar(&plateauEscalateStep, "plateau-escalate-step", 40, "Extra impl tasks per plateau step when escalating")
	flag.IntVar(&plateauEscalateMax, "plateau-escalate-max", 320, "Upper bound for escalated impl tasks")
	flag.BoolVar(&throttleProbesOnPlateau, "throttle-probes-on-plateau", true, "Reduce probe load when repeated zero-learning plateaus are detected")
	flag.IntVar(&throttlePlateauAfter, "throttle-plateau-after", 3, "Start probe throttling after this many consecutive plateau cycles")
	flag.IntVar(&throttleLimit, "throttle-limit", 3, "Probe limit used while throttling is active")
	flag.Float64Var(&implMinCallConf, "impl-min-call-confidence", 0.7, "Default implsynth min call confidence")
	flag.Float64Var(&implFallbackMinCallConf, "impl-fallback-min-call-confidence", 0.4, "Default implsynth fallback min call confidence")
	flag.IntVar(&plateauLowerConfAfter, "plateau-lower-conf-after", 4, "Lower implsynth call confidence after this many consecutive plateau cycles")
	flag.Float64Var(&plateauLoweredMinCallConf, "plateau-lowered-min-call-confidence", 0.55, "Lowered implsynth min call confidence during deep plateaus")
	flag.Float64Var(&plateauLoweredFallbackMinCallConf, "plateau-lowered-fallback-min-call-confidence", 0.25, "Lowered implsynth fallback confidence during deep plateaus")
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
	if throttleProbesOnPlateau {
		historyPath := filepath.Join(rootAbs, runRoot, "cycle_history.jsonl")
		if streak, err := consecutivePlateauStreak(historyPath, plateauDeltaSuccessMax); err == nil && throttlePlateauAfter > 0 && streak >= throttlePlateauAfter && throttleLimit >= 0 {
			limit = throttleLimit
		}
	}

	args := []string{
		"tools/recon_cycle.py",
		"--run-root", runRoot,
		"--primary-source", primarySource,
		"--limit", fmt.Sprintf("%d", limit),
		"--max-insns", fmt.Sprintf("%d", maxInsns),
		"--min-success-insns", fmt.Sprintf("%d", minSuccessInsns),
		"--shallow-cooldown", fmt.Sprintf("%d", shallowCooldown),
		"--shallow-retry-max-insns", fmt.Sprintf("%d", shallowRetryMaxInsns),
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
	if retryShallowSuccess {
		args = append(args, "--retry-shallow-success")
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

	if autoImplOnPlateau {
		reportPath := filepath.Join(rootAbs, runRoot, "runs", tag, "cycle_report.json")
		if tag == "" {
			reportPath = ""
		}
		if reportPath != "" {
			b, err := os.ReadFile(reportPath)
			if err == nil {
				var report struct {
					DeltaLearningSmokeSuccessCount int `json:"delta_learning_smoke_success_count"`
				}
				if json.Unmarshal(b, &report) == nil && report.DeltaLearningSmokeSuccessCount <= plateauDeltaSuccessMax {
					implTasks := autoImplMaxTasks
					implSkip := 0
					runMinCallConf := implMinCallConf
					runFallbackCallConf := implFallbackMinCallConf
					historyPath := filepath.Join(rootAbs, runRoot, "cycle_history.jsonl")
					if streak, err := consecutivePlateauStreak(historyPath, plateauDeltaSuccessMax); err == nil && plateauEscalateAfter > 0 && plateauEscalateStep > 0 && streak >= plateauEscalateAfter {
						levels := 1 + (streak-plateauEscalateAfter)/plateauEscalateAfter
						implTasks = autoImplMaxTasks + levels*plateauEscalateStep
						if plateauEscalateMax > 0 && implTasks > plateauEscalateMax {
							implTasks = plateauEscalateMax
						}
						// Rotate implementation queue window on prolonged plateaus
						// to avoid repeatedly synthesizing the same top-ranked slice.
						if streak > plateauEscalateAfter {
							implSkip = (streak - plateauEscalateAfter) * implTasks
						}
						if plateauLowerConfAfter > 0 && streak >= plateauLowerConfAfter {
							runMinCallConf = plateauLoweredMinCallConf
							runFallbackCallConf = plateauLoweredFallbackMinCallConf
						}
					}
					steps := [][]string{
						{"run", "./cmd/fwcompose"},
						{"run", "./cmd/fwimplqueue", "-max-tasks", fmt.Sprintf("%d", implTasks), "-skip-tasks", fmt.Sprintf("%d", implSkip)},
						{"run", "./cmd/fwimplsynth", "-max-tasks", fmt.Sprintf("%d", implTasks), "-min-call-confidence", fmt.Sprintf("%.3f", runMinCallConf), "-fallback-min-call-confidence", fmt.Sprintf("%.3f", runFallbackCallConf)},
						{"run", "./cmd/fwapplysynth"},
						{"run", "./cmd/fwfinalize"},
					}
					for _, step := range steps {
						if err := runCmd(rootAbs, "go", step...); err != nil {
							fmt.Fprintf(os.Stderr, "auto impl stage failed (%s): %v\n", strings.Join(step, " "), err)
							os.Exit(1)
						}
					}
				}
			}
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

func consecutivePlateauStreak(historyPath string, threshold int) (int, error) {
	f, err := os.Open(historyPath)
	if err != nil {
		return 0, err
	}
	defer f.Close()
	type row struct {
		Delta int `json:"delta_learning_smoke_success_count"`
	}
	rows := make([]row, 0, 256)
	sc := bufio.NewScanner(f)
	for sc.Scan() {
		line := strings.TrimSpace(sc.Text())
		if line == "" {
			continue
		}
		var r row
		if json.Unmarshal([]byte(line), &r) != nil {
			continue
		}
		rows = append(rows, r)
	}
	if err := sc.Err(); err != nil {
		return 0, err
	}
	streak := 0
	for i := len(rows) - 1; i >= 0; i-- {
		if rows[i].Delta <= threshold {
			streak++
			continue
		}
		break
	}
	return streak, nil
}
