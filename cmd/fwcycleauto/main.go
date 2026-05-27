package main

import (
	"errors"
	"encoding/json"
	"flag"
	"fmt"
	"os"
	"os/exec"
	"path/filepath"
	"strings"
	"time"

	"aic8800d80/internal/fileio"
)

type multiFlag []string

func (m *multiFlag) String() string {
	return strings.Join(*m, ",")
}

func (m *multiFlag) Set(value string) error {
	trimmed := strings.TrimSpace(value)
	if trimmed == "" {
		return nil
	}
	*m = append(*m, trimmed)
	return nil
}

type autoStatus struct {
	SchemaVersion         string         `json:"schema_version"`
	State                 string         `json:"state"`
	PID                   int            `json:"pid"`
	RunRoot               string         `json:"run_root"`
	StartedAt             string         `json:"started_at"`
	UpdatedAt             string         `json:"updated_at"`
	TargetEndAt           string         `json:"target_end_at,omitempty"`
	StopFile              string         `json:"stop_file"`
	StatusPath            string         `json:"status_path"`
	TagPrefix             string         `json:"tag_prefix"`
	CurrentCycle          int            `json:"current_cycle"`
	CompletedCycles       int            `json:"completed_cycles"`
	ConsecutiveFailures   int            `json:"consecutive_failures"`
	MaxConsecutiveFailure int            `json:"max_consecutive_failures"`
	LastTag               string         `json:"last_tag,omitempty"`
	LastExitCode          int            `json:"last_exit_code,omitempty"`
	LastError             string         `json:"last_error,omitempty"`
	LastCycleDurationSec  float64        `json:"last_cycle_duration_sec,omitempty"`
	LastCycleReportPath   string         `json:"last_cycle_report_path,omitempty"`
	LastProbeSummary      map[string]any `json:"last_probe_summary,omitempty"`
	LastControllerAction  map[string]any `json:"last_controller_action,omitempty"`
	LastHardenStatus      string         `json:"last_harden_status,omitempty"`
	ChildArgs             []string       `json:"child_args,omitempty"`
}

type cycleReport struct {
	ControllerPrimaryAction map[string]any `json:"controller_primary_action"`
	ProbeSummary            map[string]any `json:"probe_summary"`
	HardenStatus            string         `json:"harden_status"`
}

func main() {
	if err := run(); err != nil {
		fmt.Fprintf(os.Stderr, "%v\n", err)
		os.Exit(1)
	}
}

func run() error {
	var root string
	var runRoot string
	var hours float64
	var maxCycles int
	var sleepSec int
	var limit int
	var autoImplMaxTasks int
	var maxConsecutiveFailures int
	var embedderModel string
	var stopFile string
	var statusPath string
	var lockPath string
	var tagPrefix string
	var clearStopFile bool
	var dryRun bool
	var childArgs multiFlag

	flag.StringVar(&root, "root", ".", "Repository root")
	flag.StringVar(&runRoot, "run-root", "extraction_out/reconstruction/mega7", "Reconstruction run root")
	flag.Float64Var(&hours, "hours", 6.0, "Maximum wall-clock hours to run (<=0 means until stopped)")
	flag.IntVar(&maxCycles, "max-cycles", 0, "Maximum cycle count (<=0 means unlimited)")
	flag.IntVar(&sleepSec, "sleep-sec", 20, "Sleep between cycles in seconds")
	flag.IntVar(&limit, "limit", 12, "Probe target limit passed to fwcycle")
	flag.IntVar(&autoImplMaxTasks, "auto-impl-max-tasks", 320, "Auto implementation task budget passed to fwcycle")
	flag.IntVar(&maxConsecutiveFailures, "max-consecutive-failures", 3, "Stop after this many consecutive fwcycle failures (<=0 disables)")
	flag.StringVar(&embedderModel, "embedder-model", "/home/grec-alexander/Downloads/bge-code-v1-q8_0.gguf", "Path to GGUF embedding model for behavioral classification")
	flag.StringVar(&stopFile, "stop-file", "", "Stop-file path (default: <run-root>/.fwcycleauto.stop)")
	flag.StringVar(&statusPath, "status", "", "Status JSON path (default: <run-root>/fwcycleauto_status.json)")
	flag.StringVar(&lockPath, "lock-file", "", "Autoloop lock path (default: <run-root>/.fwcycleauto.lock)")
	flag.StringVar(&tagPrefix, "tag-prefix", "cycle_auto", "Prefix for generated cycle tags")
	flag.BoolVar(&clearStopFile, "clear-stop-file", true, "Remove pre-existing stop file on startup")
	flag.BoolVar(&dryRun, "dry-run", false, "Print planned child command(s) without executing them")
	flag.Var(&childArgs, "child-arg", "Extra argument passed through to fwcycle (repeatable)")
	flag.Parse()

	rootAbs, err := filepath.Abs(root)
	if err != nil {
		return fmt.Errorf("resolve root: %w", err)
	}
	runRootAbs := filepath.Join(rootAbs, runRoot)
	if strings.TrimSpace(stopFile) == "" {
		stopFile = filepath.Join(runRootAbs, ".fwcycleauto.stop")
	}
	if strings.TrimSpace(statusPath) == "" {
		statusPath = filepath.Join(runRootAbs, "fwcycleauto_status.json")
	}
	if strings.TrimSpace(lockPath) == "" {
		lockPath = filepath.Join(runRootAbs, ".fwcycleauto.lock")
	}
	if err := os.MkdirAll(runRootAbs, 0o755); err != nil {
		return fmt.Errorf("mkdir run-root: %w", err)
	}
	if clearStopFile {
		_ = os.Remove(stopFile)
	} else if _, err := os.Stat(stopFile); err == nil {
		return fmt.Errorf("stop file already exists: %s", stopFile)
	}
	lock, err := fileio.AcquireFileLock(lockPath)
	if err != nil {
		return fmt.Errorf("acquire fwcycleauto lock: %w", err)
	}
	defer lock.Release()

	startedAt := time.Now().UTC()
	endAt := time.Time{}
	if hours > 0 {
		endAt = startedAt.Add(time.Duration(hours * float64(time.Hour)))
	}
	status := autoStatus{
		SchemaVersion:         "0.1.0",
		State:                 "running",
		PID:                   os.Getpid(),
		RunRoot:               runRootAbs,
		StartedAt:             startedAt.Format(time.RFC3339),
		UpdatedAt:             startedAt.Format(time.RFC3339),
		StopFile:              stopFile,
		StatusPath:            statusPath,
		TagPrefix:             tagPrefix,
		MaxConsecutiveFailure: maxConsecutiveFailures,
		ChildArgs:             append([]string(nil), childArgs...),
	}
	if !endAt.IsZero() {
		status.TargetEndAt = endAt.Format(time.RFC3339)
	}
	if err := writeStatus(statusPath, status); err != nil {
		return err
	}

	cycleIndex := 0
	for {
	if shouldStop(stopFile, endAt, cycleIndex, maxCycles) {
			status.State = "stopped"
			status.UpdatedAt = time.Now().UTC().Format(time.RFC3339)
			return writeStatus(statusPath, status)
		}
		cycleIndex++
		tag := makeCycleTag(tagPrefix, cycleIndex, time.Now().UTC())
		cmdArgs := buildFWCycleArgs(runRoot, tag, limit, autoImplMaxTasks, embedderModel, childArgs)
		status.State = "running"
		status.CurrentCycle = cycleIndex
		status.LastTag = tag
		status.UpdatedAt = time.Now().UTC().Format(time.RFC3339)
		status.LastError = ""
		status.LastExitCode = 0
		status.LastCycleReportPath = filepath.Join(runRootAbs, "runs", tag, "cycle_report.json")
		if err := writeStatus(statusPath, status); err != nil {
			return err
		}
		fmt.Printf("fwcycleauto: starting cycle %d tag=%s\n", cycleIndex, tag)
		fmt.Printf("fwcycleauto: command: go %s\n", strings.Join(cmdArgs, " "))
		if dryRun {
			status.CompletedCycles++
			status.UpdatedAt = time.Now().UTC().Format(time.RFC3339)
			if err := writeStatus(statusPath, status); err != nil {
				return err
			}
			break
		}
		cycleStart := time.Now()
		cmd := exec.Command("go", cmdArgs...)
		cmd.Dir = rootAbs
		cmd.Stdout = os.Stdout
		cmd.Stderr = os.Stderr
		err := cmd.Run()
		dur := time.Since(cycleStart)
		status.LastCycleDurationSec = dur.Seconds()
		status.CompletedCycles++
		if err != nil {
			status.ConsecutiveFailures++
			status.LastExitCode = exitCode(err)
			status.LastError = err.Error()
			fmt.Printf("fwcycleauto: cycle failed tag=%s err=%v\n", tag, err)
		} else {
			status.ConsecutiveFailures = 0
			status.LastExitCode = 0
			status.LastError = ""
			if report, ok := loadCycleReport(status.LastCycleReportPath); ok {
				status.LastProbeSummary = report.ProbeSummary
				status.LastControllerAction = report.ControllerPrimaryAction
				status.LastHardenStatus = report.HardenStatus
			}
		}
		status.UpdatedAt = time.Now().UTC().Format(time.RFC3339)
		if err := writeStatus(statusPath, status); err != nil {
			return err
		}
		if err != nil && maxConsecutiveFailures > 0 && status.ConsecutiveFailures >= maxConsecutiveFailures {
			status.State = "failed"
			status.UpdatedAt = time.Now().UTC().Format(time.RFC3339)
			_ = writeStatus(statusPath, status)
			return fmt.Errorf("stopping after %d consecutive failures", status.ConsecutiveFailures)
		}
		if shouldStop(stopFile, endAt, cycleIndex, maxCycles) {
			status.State = "stopped"
			status.UpdatedAt = time.Now().UTC().Format(time.RFC3339)
			return writeStatus(statusPath, status)
		}
		if sleepSec > 0 {
			fmt.Printf("fwcycleauto: sleeping %ds before next cycle\n", sleepSec)
			time.Sleep(time.Duration(sleepSec) * time.Second)
		}
	}
	status.State = "stopped"
	status.UpdatedAt = time.Now().UTC().Format(time.RFC3339)
	return writeStatus(statusPath, status)
}

func buildFWCycleArgs(runRoot, tag string, limit, autoImplMaxTasks int, embedderModel string, childArgs []string) []string {
	args := []string{
		"run", "./cmd/fwcycle",
		"-run-root", runRoot,
		"-tag", tag,
		"-limit", fmt.Sprintf("%d", limit),
		"-throttle-probes-on-plateau=false",
		"-auto-impl-max-tasks", fmt.Sprintf("%d", autoImplMaxTasks),
	}
	if strings.TrimSpace(embedderModel) != "" {
		args = append(args, "-embedder-model", embedderModel)
	}
	args = append(args, childArgs...)
	return args
}

func shouldStop(stopFile string, endAt time.Time, cycleIndex, maxCycles int) bool {
	if strings.TrimSpace(stopFile) != "" {
		if _, err := os.Stat(stopFile); err == nil {
			return true
		}
	}
	if maxCycles > 0 && cycleIndex >= maxCycles {
		return true
	}
	if !endAt.IsZero() && time.Now().UTC().After(endAt) {
		return true
	}
	return false
}

func makeCycleTag(prefix string, cycleIndex int, now time.Time) string {
	clean := strings.TrimSpace(prefix)
	if clean == "" {
		clean = "cycle_auto"
	}
	return fmt.Sprintf("%s_%s_%03d", clean, now.UTC().Format("20060102T150405Z"), cycleIndex)
}

func loadCycleReport(path string) (cycleReport, bool) {
	b, err := os.ReadFile(path)
	if err != nil {
		return cycleReport{}, false
	}
	var report cycleReport
	if err := json.Unmarshal(b, &report); err != nil {
		return cycleReport{}, false
	}
	return report, true
}

func writeStatus(path string, status autoStatus) error {
	status.UpdatedAt = time.Now().UTC().Format(time.RFC3339)
	if err := os.MkdirAll(filepath.Dir(path), 0o755); err != nil {
		return fmt.Errorf("mkdir status dir: %w", err)
	}
	if err := fileio.WriteJSON(path, status); err != nil {
		return fmt.Errorf("write status: %w", err)
	}
	return nil
}

func exitCode(err error) int {
	if err == nil {
		return 0
	}
	var exitErr *exec.ExitError
	if errors.As(err, &exitErr) {
		return exitErr.ExitCode()
	}
	return 1
}
