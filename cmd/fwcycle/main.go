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
	"strings"
	"time"

	"aic8800d80/internal/fileio"
)

func runCmd(rootAbs string, name string, args ...string) error {
	cmd := exec.Command(name, args...)
	cmd.Dir = rootAbs
	cmd.Stdout = os.Stdout
	cmd.Stderr = os.Stderr
	return cmd.Run()
}

func runIDARefresh(rootAbs, runRoot, idatPath string) error {
	if strings.TrimSpace(idatPath) == "" {
		return fmt.Errorf("empty idat path")
	}
	targetFile := filepath.Join(rootAbs, runRoot, "pseudocode_targets.json")
	if err := runCmd(rootAbs, "python3", "tools/select_pseudocode_targets.py", "--run-root", runRoot, "--out", targetFile); err != nil {
		return fmt.Errorf("select pseudocode targets: %w", err)
	}
	refreshArgs := []string{"tools/refresh_ida_exports.py", "--idat", idatPath, "--pseudo-targets", targetFile}
	return runCmd(rootAbs, "python3", refreshArgs...)
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
	var retryCappedOnce bool
	var shallowRetryMaxInsns int
	var cappedRetryMaxInsns int
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
	var gateMinHardenPassRate float64
	var gateMinNaturalReturnRate float64
	var gateMaxCapHitRate float64
	var gateMinNontrivialRate float64
	var gateMinMmioTouchRate float64
	var gateMinImageDiversity float64
	var gateMaxWrapperDominanceRate float64
	var gateMinDeepReturnRate float64
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
	var refreshIDAOnZeroProbes bool
	var refreshIDABeforeCycle bool
	var refreshIDAStrict bool
	var idatPath string
	var gateHarden bool
	var gateFocusOnFailure bool
	var gateFocusMax int
	var hardenMinNaturalReturnRate float64
	var hardenMaxCapHitRate float64
	var hardenMinNontrivialRate float64
	var hardenMinMmioTouchRate float64
	var hardenMinDistinctImages int
	var hardenMaxWrapperDominanceRate float64
	var hardenMinDeepReturnRate float64
	var plateauMode string
	var tag string

	flag.StringVar(&root, "root", ".", "Repository root")
	flag.StringVar(&runRoot, "run-root", "extraction_out/reconstruction/mega7", "Reconstruction run root")
	flag.StringVar(&primarySource, "primary-source", "extraction_out/reconstruction/mega7/final/fmacfw_8800d80_u02_bin.reconstructed.c", "Primary reconstructed C source")
	flag.StringVar(&sourceGlobsCSV, "source-globs", "", "Comma-separated additional source globs")
	flag.StringVar(&seedCSV, "seeds", "0x40000000=0", "Comma-separated default seeds ADDR=VALUE")
	flag.IntVar(&limit, "limit", 10, "Probe target limit")
	flag.IntVar(&maxInsns, "max-insns", 192, "Max instructions per probe")
	flag.IntVar(&minSuccessInsns, "min-success-insns", 8, "Treat success below this instruction count as shallow")
	flag.IntVar(&shallowCooldown, "shallow-cooldown", 3, "Skip targets with repeated shallow-success outcomes")
	flag.IntVar(&missingCooldown, "missing-cooldown", 2, "Skip targets with repeated missing-symbol outcomes")
	flag.IntVar(&recentWindowMin, "recent-window-min", 30, "Skip targets attempted within this many minutes")
	flag.BoolVar(&retryFaultOnce, "retry-fault-once", true, "Retry one time with learned fault seed on unmapped faults")
	flag.BoolVar(&retryShallowSuccess, "retry-shallow-success", true, "Retry shallow successes once with higher instruction budget")
	flag.BoolVar(&retryCappedOnce, "retry-capped-once", true, "Retry capped probes once with higher instruction budget")
	flag.IntVar(&shallowRetryMaxInsns, "shallow-retry-max-insns", 1024, "Instruction cap used for shallow-success retries")
	flag.IntVar(&cappedRetryMaxInsns, "capped-retry-max-insns", 1024, "Instruction cap used for capped retries")
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
	flag.Float64Var(&gateMinHardenPassRate, "gate-min-harden-pass-rate", 0, "Minimum harden pass rate percent for trend gate")
	flag.Float64Var(&gateMinNaturalReturnRate, "gate-min-natural-return-rate", 0, "Minimum natural return rate percent for trend gate")
	flag.Float64Var(&gateMaxCapHitRate, "gate-max-cap-hit-rate", 0, "Maximum cap-hit rate percent for trend gate")
	flag.Float64Var(&gateMinNontrivialRate, "gate-min-nontrivial-rate", 0, "Minimum nontrivial return rate percent for trend gate")
	flag.Float64Var(&gateMinMmioTouchRate, "gate-min-mmio-touch-rate", 0, "Minimum MMIO-touch probe rate percent for trend gate")
	flag.Float64Var(&gateMinImageDiversity, "gate-min-image-diversity", 0, "Minimum average distinct-image diversity for trend gate")
	flag.Float64Var(&gateMaxWrapperDominanceRate, "gate-max-wrapper-dominance-rate", 0, "Maximum shallow-wrapper dominance rate percent for trend gate")
	flag.Float64Var(&gateMinDeepReturnRate, "gate-min-deep-return-rate", 0, "Minimum deep-pass return rate percent for trend gate")
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
	flag.BoolVar(&refreshIDAOnZeroProbes, "refresh-ida-on-zero-probes", true, "Run headless IDA export refresh when a cycle probes zero functions")
	flag.BoolVar(&refreshIDABeforeCycle, "refresh-ida-before-cycle", true, "Refresh IDA-derived exports before every cycle")
	flag.BoolVar(&refreshIDAStrict, "refresh-ida-strict", true, "Fail cycle immediately if IDA refresh fails")
	flag.StringVar(&idatPath, "idat", "tools/local-bin/ida-idat", "Path to IDA idat executable")
	flag.BoolVar(&gateHarden, "gate-harden", true, "Run fwharden after cycle stages complete")
	flag.BoolVar(&gateFocusOnFailure, "gate-focus-on-failure", true, "Generate quality/conformance focus reports when harden gate fails")
	flag.IntVar(&gateFocusMax, "gate-focus-max", 120, "Maximum rows for generated focus reports on harden failure")
	flag.Float64Var(&hardenMinNaturalReturnRate, "harden-min-natural-return-rate", 0.0, "Minimum natural return rate percent for hardening gate")
	flag.Float64Var(&hardenMaxCapHitRate, "harden-max-cap-hit-rate", 95.0, "Maximum cap-hit rate percent for hardening gate")
	flag.Float64Var(&hardenMinNontrivialRate, "harden-min-nontrivial-rate", 0.0, "Minimum nontrivial return rate percent for hardening gate")
	flag.Float64Var(&hardenMinMmioTouchRate, "harden-min-mmio-touch-rate", 0.0, "Minimum MMIO-touch probe rate percent for hardening gate")
	flag.IntVar(&hardenMinDistinctImages, "harden-min-distinct-images", 1, "Minimum distinct selected images for hardening gate")
	flag.Float64Var(&hardenMaxWrapperDominanceRate, "harden-max-wrapper-dominance-rate", 100.0, "Maximum shallow-wrapper dominance rate percent for hardening gate")
	flag.Float64Var(&hardenMinDeepReturnRate, "harden-min-deep-return-rate", 0.0, "Minimum deep-pass return rate percent for hardening gate")
	flag.StringVar(&plateauMode, "plateau-mode", "auto", "Plateau response mode: auto|explore|deepen|synthesize|validate")
	var embedderModel string
	flag.StringVar(&embedderModel, "embedder-model", "", "Path to GGUF embedding model for behavioral classification")
	flag.StringVar(&tag, "tag", "", "Cycle run tag")
	flag.Parse()

	rootAbs, err := filepath.Abs(root)
	if err != nil {
		fmt.Fprintf(os.Stderr, "resolve root: %v\n", err)
		os.Exit(1)
	}
	lockPath := filepath.Join(rootAbs, runRoot, ".fwcycle.lock")
	if err := os.MkdirAll(filepath.Dir(lockPath), 0o755); err != nil {
		fmt.Fprintf(os.Stderr, "prepare run-root lock dir: %v\n", err)
		os.Exit(1)
	}
	lock, err := fileio.AcquireFileLock(lockPath)
	if err != nil {
		fmt.Fprintf(os.Stderr, "acquire fwcycle lock: %v\n", err)
		os.Exit(1)
	}
	defer lock.Release()

	if strings.TrimSpace(sourceGlobsCSV) == "" {
		sourceGlobsCSV = filepath.ToSlash(filepath.Join(runRoot, "final_recovered", "*.c")) + "," + filepath.ToSlash(filepath.Join(runRoot, "final", "*.c"))
	}
	if strings.TrimSpace(outcomesPath) == "" {
		outcomesPath = filepath.ToSlash(filepath.Join(runRoot, "smoke_observations.jsonl"))
	}
	if refreshIDABeforeCycle {
		if err := runIDARefresh(rootAbs, runRoot, idatPath); err != nil {
			if refreshIDAStrict {
				fmt.Fprintf(os.Stderr, "ida pre-cycle refresh failed: %v\n", err)
				os.Exit(1)
			}
			fmt.Fprintf(os.Stderr, "ida pre-cycle refresh failed (continuing): %v\n", err)
		}
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
		"--capped-retry-max-insns", fmt.Sprintf("%d", cappedRetryMaxInsns),
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
	if retryCappedOnce {
		args = append(args, "--retry-capped-once")
	}
	if preferNonCycleQueue {
		args = append(args, "--prefer-non-cycle-queue")
	}
	if embedderModel != "" {
		args = append(args, "--embedder-model", embedderModel)
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

	effectiveTag := strings.TrimSpace(tag)
	if effectiveTag == "" {
		runsDir := filepath.Join(rootAbs, runRoot, "runs")
		if t, err := latestRunTag(runsDir); err == nil {
			effectiveTag = t
		}
	}

	if autoImplOnPlateau {
		reportPath := filepath.Join(rootAbs, runRoot, "runs", effectiveTag, "cycle_report.json")
		if effectiveTag == "" {
			reportPath = ""
		}
		if reportPath != "" {
			b, err := os.ReadFile(reportPath)
			if err == nil {
				var report cycleReport
				if json.Unmarshal(b, &report) == nil && report.DeltaLearningSmokeSuccessCount <= plateauDeltaSuccessMax {
					if refreshIDAOnZeroProbes && report.ProbeSummary.Probed == 0 && strings.TrimSpace(idatPath) != "" {
						if err := runIDARefresh(rootAbs, runRoot, idatPath); err != nil {
							fmt.Fprintf(os.Stderr, "ida refresh failed: %v\n", err)
						}
					}

					historyPath := filepath.Join(rootAbs, runRoot, "cycle_history.jsonl")
					streak := 1
					if s, err := consecutivePlateauStreak(historyPath, plateauDeltaSuccessMax); err == nil {
						streak = s
					}
					routing, _ := classifyPlateau(report, plateauMode)
					routing.Streak = streak
					_ = writePlateauRouting(rootAbs, runRoot, effectiveTag, routing)

					switch routing.Mode {
					case "explore":
						if strings.TrimSpace(idatPath) != "" {
							if err := runIDARefresh(rootAbs, runRoot, idatPath); err != nil {
								fmt.Fprintf(os.Stderr, "explore mode IDA refresh failed: %v\n", err)
							}
						}
					case "deepen":
						if err := runDeepenProbePass(rootAbs, runRoot, primarySource, sourceGlobsCSV, seedCSV, outcomesPath, limit, maxInsns, minSuccessInsns, shallowCooldown, shallowRetryMaxInsns, missingCooldown, recentWindowMin); err != nil {
							fmt.Fprintf(os.Stderr, "deepen mode failed: %v\n", err)
						}
					case "validate":
						if err := runCmd(rootAbs, "go", "run", "./cmd/fwvalidatecalls"); err != nil {
							fmt.Fprintf(os.Stderr, "validate mode failed: %v\n", err)
						}
					default:
						implTasks := autoImplMaxTasks
						implSkip := 0
						runMinCallConf := implMinCallConf
						runFallbackCallConf := implFallbackMinCallConf
						if plateauEscalateAfter > 0 && plateauEscalateStep > 0 && streak >= plateauEscalateAfter {
							levels := 1 + (streak-plateauEscalateAfter)/plateauEscalateAfter
							implTasks = autoImplMaxTasks + levels*plateauEscalateStep
							if plateauEscalateMax > 0 && implTasks > plateauEscalateMax {
								implTasks = plateauEscalateMax
							}
							if streak > plateauEscalateAfter {
								implSkip = (streak - plateauEscalateAfter) * implTasks
							}
							if plateauLowerConfAfter > 0 && streak >= plateauLowerConfAfter {
								runMinCallConf = plateauLoweredMinCallConf
								runFallbackCallConf = plateauLoweredFallbackMinCallConf
							}
						}
						if report.ProbeSummary.Probed == 0 {
							implTasks *= 2
							if plateauEscalateMax > 0 && implTasks > plateauEscalateMax {
								implTasks = plateauEscalateMax
							}
						}
						steps := [][]string{
							{"run", "./cmd/fwcompose"},
							{"run", "./cmd/fwimplqueue", "-max-tasks", fmt.Sprintf("%d", implTasks), "-skip-tasks", fmt.Sprintf("%d", implSkip)},
							{"run", "./cmd/fwimplsynth", "-max-tasks", fmt.Sprintf("%d", implTasks), "-min-call-confidence", fmt.Sprintf("%.3f", runMinCallConf), "-fallback-min-call-confidence", fmt.Sprintf("%.3f", runFallbackCallConf)},
							{"run", "./cmd/fwapplysynth"},
							{"run", "./cmd/fwfinalize"},
							{"run", "./cmd/fwvalidatecalls"},
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
	}

	if gateHarden {
		hardenCfg := hardenConfig{
			MinNaturalReturnRate:    hardenMinNaturalReturnRate,
			MaxCapHitRate:           hardenMaxCapHitRate,
			MinNontrivialRate:       hardenMinNontrivialRate,
			MinMmioTouchRate:        hardenMinMmioTouchRate,
			MinDistinctImages:       hardenMinDistinctImages,
			MaxWrapperDominanceRate: hardenMaxWrapperDominanceRate,
			MinDeepReturnRate:       hardenMinDeepReturnRate,
		}
		if _, err := runHardeningGate(rootAbs, runRoot, effectiveTag, gateFocusOnFailure, gateFocusMax, hardenCfg); err != nil {
			fmt.Fprintf(os.Stderr, "hardening gate failed: %v\n", err)
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
		"-min-harden-pass-rate", fmt.Sprintf("%.3f", gateMinHardenPassRate),
		"-min-natural-return-rate", fmt.Sprintf("%.3f", gateMinNaturalReturnRate),
		"-max-cap-hit-rate", fmt.Sprintf("%.3f", gateMaxCapHitRate),
		"-min-nontrivial-rate", fmt.Sprintf("%.3f", gateMinNontrivialRate),
		"-min-mmio-touch-rate", fmt.Sprintf("%.3f", gateMinMmioTouchRate),
		"-min-image-diversity", fmt.Sprintf("%.3f", gateMinImageDiversity),
		"-max-wrapper-dominance-rate", fmt.Sprintf("%.3f", gateMaxWrapperDominanceRate),
		"-min-deep-return-rate", fmt.Sprintf("%.3f", gateMinDeepReturnRate),
	}
	if err := runCmd(rootAbs, "go", trendArgs...); err != nil {
		fmt.Fprintf(os.Stderr, "trend gate failed: %v\n", err)
		os.Exit(1)
	}
}

type gateReport struct {
	SchemaVersion         string `json:"schema_version"`
	GeneratedAt           string `json:"generated_at"`
	Tag                   string `json:"tag,omitempty"`
	HardenStatus          string `json:"harden_status"`
	Failure               string `json:"failure,omitempty"`
	ConformanceFocusPath  string `json:"conformance_focus_path,omitempty"`
	QualityFocusPath      string `json:"quality_focus_path,omitempty"`
	ConformanceFocusError string `json:"conformance_focus_error,omitempty"`
	QualityFocusError     string `json:"quality_focus_error,omitempty"`
}

type hardenConfig struct {
	MinNaturalReturnRate    float64
	MaxCapHitRate           float64
	MinNontrivialRate       float64
	MinMmioTouchRate        float64
	MinDistinctImages       int
	MaxWrapperDominanceRate float64
	MinDeepReturnRate       float64
}

type cycleReport struct {
	DeltaLearningSmokeSuccessCount int               `json:"delta_learning_smoke_success_count"`
	LearningReasonCounts           map[string]int    `json:"learning_reason_counts"`
	ProbeSummary                   probeSummaryCycle `json:"probe_summary"`
	ControllerRecommendedMode      string            `json:"controller_recommended_mode"`
	ControllerPrimaryAction        map[string]any    `json:"controller_primary_action"`
}

type probeSummaryCycle struct {
	Probed               int `json:"probed"`
	Returned             int `json:"returned"`
	Capped               int `json:"capped"`
	Fault                int `json:"fault"`
	MissingSymbol        int `json:"missing_symbol"`
	ShallowReturn        int `json:"shallow_return"`
	NontrivialReturn     int `json:"nontrivial_return"`
	MmioTouchProbes      int `json:"mmio_touch_probes"`
	DeepProbed           int `json:"deep_probed"`
	DeepReturned         int `json:"deep_returned"`
	SelectedDistinctImgs int `json:"selected_distinct_images"`
}

type plateauRouting struct {
	SchemaVersion string             `json:"schema_version"`
	GeneratedAt   string             `json:"generated_at"`
	Tag           string             `json:"tag,omitempty"`
	Mode          string             `json:"mode"`
	PrimaryCause  string             `json:"primary_cause"`
	CauseScores   map[string]float64 `json:"cause_scores"`
	Reasons       []string           `json:"reasons,omitempty"`
	Streak        int                `json:"plateau_streak"`
}

func runHardeningGate(rootAbs, runRoot, tag string, focusOnFailure bool, focusMax int, cfg hardenConfig) (gateReport, error) {
	finalDir := filepath.ToSlash(filepath.Join(runRoot, "final"))
	rebuiltDir := filepath.ToSlash(filepath.Join(runRoot, "rebuilt"))
	cycleReportPath := ""
	if strings.TrimSpace(tag) != "" {
		cycleReportPath = filepath.ToSlash(filepath.Join(runRoot, "runs", tag, "cycle_report.json"))
	}
	hardenArgs := []string{"run", "./cmd/fwharden", "-final-dir", finalDir, "-rebuilt-dir", rebuiltDir}
	if cycleReportPath != "" {
		hardenArgs = append(hardenArgs,
			"-cycle-report", cycleReportPath,
			"-min-natural-return-rate", fmt.Sprintf("%.3f", cfg.MinNaturalReturnRate),
			"-max-cap-hit-rate", fmt.Sprintf("%.3f", cfg.MaxCapHitRate),
			"-min-nontrivial-rate", fmt.Sprintf("%.3f", cfg.MinNontrivialRate),
			"-min-mmio-touch-rate", fmt.Sprintf("%.3f", cfg.MinMmioTouchRate),
			"-min-distinct-images", fmt.Sprintf("%d", cfg.MinDistinctImages),
			"-max-wrapper-dominance-rate", fmt.Sprintf("%.3f", cfg.MaxWrapperDominanceRate),
			"-min-deep-return-rate", fmt.Sprintf("%.3f", cfg.MinDeepReturnRate),
		)
	}
	err := runCmd(rootAbs, "go", hardenArgs...)
	report := gateReport{
		SchemaVersion: "0.1.0",
		GeneratedAt:   time.Now().UTC().Format(time.RFC3339),
		Tag:           tag,
		HardenStatus:  "pass",
	}
	if err != nil {
		report.HardenStatus = "fail"
		report.Failure = err.Error()
		if focusOnFailure {
			conformancePath := filepath.ToSlash(filepath.Join(runRoot, "final", "conformance_focus.json"))
			qualityPath := filepath.ToSlash(filepath.Join(runRoot, "final", "quality_focus.json"))
			report.ConformanceFocusPath = conformancePath
			report.QualityFocusPath = qualityPath
			maxStr := fmt.Sprintf("%d", focusMax)
			if e := runCmd(rootAbs, "go", "run", "./cmd/fwconformancefocus", "-in", filepath.ToSlash(filepath.Join(runRoot, "final", "call_conformance.json")), "-out", conformancePath, "-max", maxStr); e != nil {
				report.ConformanceFocusError = e.Error()
			}
			if e := runCmd(rootAbs, "go", "run", "./cmd/fwqualityfocus", "-quality", filepath.ToSlash(filepath.Join(runRoot, "final", "finalize_quality.json")), "-out", qualityPath, "-max", maxStr); e != nil {
				report.QualityFocusError = e.Error()
			}
		}
	}
	latestReportPath := filepath.Join(rootAbs, runRoot, "cycle_gate_report.json")
	_ = fileio.WriteJSON(latestReportPath, report)
	if tag != "" {
		reportPath := filepath.Join(rootAbs, runRoot, "runs", tag, "cycle_gate_report.json")
		_ = fileio.WriteJSON(reportPath, report)
		_ = mergeCycleReportGate(filepath.Join(rootAbs, runRoot, "runs", tag, "cycle_report.json"), report)
	}
	_ = appendJSONL(filepath.Join(rootAbs, runRoot, "cycle_gate_history.jsonl"), report)
	if err != nil {
		return report, err
	}
	return report, nil
}

func appendJSONL(path string, v any) error {
	if err := os.MkdirAll(filepath.Dir(path), 0o755); err != nil {
		return err
	}
	b, err := json.Marshal(v)
	if err != nil {
		return err
	}
	f, err := os.OpenFile(path, os.O_CREATE|os.O_APPEND|os.O_WRONLY, 0o644)
	if err != nil {
		return err
	}
	defer f.Close()
	if _, err := f.Write(append(b, '\n')); err != nil {
		return err
	}
	return nil
}

func mergeCycleReportGate(cycleReportPath string, report gateReport) error {
	b, err := os.ReadFile(cycleReportPath)
	if err != nil {
		return err
	}
	var raw map[string]any
	if err := json.Unmarshal(b, &raw); err != nil {
		return err
	}
	raw["harden_status"] = report.HardenStatus
	if report.Failure != "" {
		raw["harden_failure"] = report.Failure
	}
	raw["gate_generated_at"] = report.GeneratedAt
	if report.ConformanceFocusPath != "" {
		raw["conformance_focus_path"] = report.ConformanceFocusPath
	}
	if report.QualityFocusPath != "" {
		raw["quality_focus_path"] = report.QualityFocusPath
	}
	return fileio.WriteJSON(cycleReportPath, raw)
}

func pct(numer int, denom int) float64 {
	if denom <= 0 {
		return 0
	}
	return float64(numer) * 100.0 / float64(denom)
}

func classifyPlateau(report cycleReport, forcedMode string) (plateauRouting, error) {
	ps := report.ProbeSummary
	scores := map[string]float64{}
	reasons := make([]string, 0, 8)
	probed := max(1, ps.Probed)

	missingRate := pct(ps.MissingSymbol, probed)
	capRate := pct(ps.Capped, probed)
	faultRate := pct(ps.Fault, probed)
	shallowRate := pct(ps.ShallowReturn, probed)
	nontrivialRate := pct(ps.NontrivialReturn, probed)
	mmioRate := pct(ps.MmioTouchProbes, probed)

	if missingRate >= 25 {
		scores["missing_symbols"] += missingRate
		reasons = append(reasons, fmt.Sprintf("missing-symbol rate %.1f%%", missingRate))
	}
	if capRate >= 40 {
		scores["harness_weakness"] += capRate
		reasons = append(reasons, fmt.Sprintf("cap-hit rate %.1f%%", capRate))
	}
	if shallowRate >= 45 {
		scores["repeated_trivial_wrappers"] += shallowRate
		reasons = append(reasons, fmt.Sprintf("shallow-wrapper dominance %.1f%%", shallowRate))
	}
	if faultRate >= 30 && mmioRate < 15 {
		scores["mmio_state_faults"] += faultRate
		reasons = append(reasons, fmt.Sprintf("fault rate %.1f%% with low mmio-touch %.1f%%", faultRate, mmioRate))
	}
	if nontrivialRate < 20 {
		scores["low_evidence_synthesis"] += (20 - nontrivialRate)
		reasons = append(reasons, fmt.Sprintf("nontrivial-return rate %.1f%%", nontrivialRate))
	}
	if ps.SelectedDistinctImgs > 0 && ps.SelectedDistinctImgs < 2 {
		scores["identity_ambiguity"] += 10
		reasons = append(reasons, fmt.Sprintf("image diversity low (%d)", ps.SelectedDistinctImgs))
	}

	for reason, cnt := range report.LearningReasonCounts {
		if !strings.Contains(reason, "capped") {
			continue
		}
		scores["low_evidence_synthesis"] += float64(cnt) * 0.5
	}

	primary := "low_evidence_synthesis"
	best := -1.0
	for k, v := range scores {
		if v > best {
			best = v
			primary = k
		}
	}
	mode := "synthesize"
	if m := strings.ToLower(strings.TrimSpace(forcedMode)); m != "" && m != "auto" {
		mode = m
	} else if m := strings.ToLower(strings.TrimSpace(report.ControllerRecommendedMode)); m != "" {
		mode = m
		reasons = append(reasons, fmt.Sprintf("controller recommended mode %s", m))
		if name, _ := report.ControllerPrimaryAction["name"].(string); strings.TrimSpace(name) != "" {
			reasons = append(reasons, fmt.Sprintf("controller primary action %s", name))
		}
	} else {
		switch primary {
		case "missing_symbols", "identity_ambiguity":
			mode = "explore"
		case "harness_weakness", "mmio_state_faults", "repeated_trivial_wrappers":
			mode = "deepen"
		case "low_evidence_synthesis":
			mode = "validate"
		default:
			mode = "synthesize"
		}
	}
	return plateauRouting{
		SchemaVersion: "0.1.0",
		GeneratedAt:   time.Now().UTC().Format(time.RFC3339),
		Mode:          mode,
		PrimaryCause:  primary,
		CauseScores:   scores,
		Reasons:       reasons,
	}, nil
}

func writePlateauRouting(rootAbs, runRoot, tag string, routing plateauRouting) error {
	routing.Tag = tag
	latestPath := filepath.Join(rootAbs, runRoot, "cycle_plateau_routing.json")
	if err := fileio.WriteJSON(latestPath, routing); err != nil {
		return err
	}
	if tag != "" {
		runPath := filepath.Join(rootAbs, runRoot, "runs", tag, "cycle_plateau_routing.json")
		if err := fileio.WriteJSON(runPath, routing); err != nil {
			return err
		}
	}
	return appendJSONL(filepath.Join(rootAbs, runRoot, "cycle_plateau_history.jsonl"), routing)
}

func runDeepenProbePass(rootAbs, runRoot, primarySource, sourceGlobsCSV, seedCSV, outcomesPath string, limit, maxInsns, minSuccessInsns, shallowCooldown, shallowRetryMaxInsns, missingCooldown, recentWindowMin int) error {
	queuePath, err := latestQueuePath(filepath.Join(rootAbs, runRoot, "runs"))
	if err != nil {
		return err
	}
	deepenLimit := limit
	if deepenLimit <= 0 {
		deepenLimit = 3
	}
	if deepenLimit > 4 {
		deepenLimit = 4
	}
	args := []string{
		"tools/smoke_learn_loop.py",
		"--source", primarySource,
		"--queue", queuePath,
		"--outcomes", outcomesPath,
		"--readme", "README.md",
		"--limit", fmt.Sprintf("%d", deepenLimit),
		"--max-insns", fmt.Sprintf("%d", max(256, maxInsns*2)),
		"--min-success-insns", fmt.Sprintf("%d", minSuccessInsns),
		"--shallow-cooldown", fmt.Sprintf("%d", shallowCooldown),
		"--shallow-retry-max-insns", fmt.Sprintf("%d", max(512, shallowRetryMaxInsns)),
		"--missing-cooldown", fmt.Sprintf("%d", missingCooldown),
		"--recent-window-min", fmt.Sprintf("%d", recentWindowMin),
		"--deep-pass",
		"--deep-on-capped",
		"--deep-max-insns", fmt.Sprintf("%d", max(512, maxInsns*3)),
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
	return runCmd(rootAbs, "python3", args...)
}

func latestQueuePath(runsDir string) (string, error) {
	entries, err := os.ReadDir(runsDir)
	if err != nil {
		return "", err
	}
	type queueRow struct {
		path string
		mod  int64
	}
	rows := make([]queueRow, 0, len(entries))
	for _, e := range entries {
		if !e.IsDir() {
			continue
		}
		p := filepath.Join(runsDir, e.Name(), "mining_queue_top300.jsonl")
		st, err := os.Stat(p)
		if err != nil {
			continue
		}
		rows = append(rows, queueRow{path: p, mod: st.ModTime().UnixNano()})
	}
	if len(rows) == 0 {
		return "", fmt.Errorf("no mining_queue_top300.jsonl found under %s", runsDir)
	}
	sort.Slice(rows, func(i, j int) bool { return rows[i].mod > rows[j].mod })
	return rows[0].path, nil
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func latestRunTag(runsDir string) (string, error) {
	ents, err := os.ReadDir(runsDir)
	if err != nil {
		return "", err
	}
	type row struct {
		name string
		mod  int64
	}
	rows := make([]row, 0, len(ents))
	for _, e := range ents {
		if !e.IsDir() {
			continue
		}
		info, err := e.Info()
		if err != nil {
			continue
		}
		rows = append(rows, row{name: e.Name(), mod: info.ModTime().UnixNano()})
	}
	if len(rows) == 0 {
		return "", fmt.Errorf("no runs under %s", runsDir)
	}
	sort.Slice(rows, func(i, j int) bool {
		if rows[i].mod == rows[j].mod {
			return rows[i].name < rows[j].name
		}
		return rows[i].mod > rows[j].mod
	})
	return rows[0].name, nil
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
