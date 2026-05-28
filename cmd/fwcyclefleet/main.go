package main

import (
	"flag"
	"fmt"
	"io"
	"os"
	"os/exec"
	"path/filepath"
	"sort"
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

type fleetManifest struct {
	SchemaVersion string        `json:"schema_version"`
	GeneratedAt   string        `json:"generated_at"`
	Root          string        `json:"root"`
	BaseRunRoot   string        `json:"base_run_root"`
	FleetRoot     string        `json:"fleet_root"`
	Workers       int           `json:"workers"`
	Hours         float64       `json:"hours"`
	Limit         int           `json:"limit"`
	AutoImplMax   int           `json:"auto_impl_max_tasks"`
	RecentRuns    int           `json:"recent_runs"`
	EmbedderModel string        `json:"embedder_model,omitempty"`
	WorkerRows    []fleetWorker `json:"workers_detail"`
}

type fleetWorker struct {
	Name       string   `json:"name"`
	RunRoot    string   `json:"run_root"`
	LogPath    string   `json:"log_path"`
	StatusPath string   `json:"status_path"`
	TagPrefix  string   `json:"tag_prefix"`
	ChildArgs  []string `json:"child_args"`
	PID        int      `json:"pid,omitempty"`
}

var workerCopyDirs = []string{
	"analysis",
	"applied",
	"applied_recovered",
	"composed",
	"final",
	"final_recovered",
	"implqueue",
	"implwork",
	"lift",
	"rebuilt",
	"synth",
}

var workerCopyFiles = []string{
	"controller_experience.jsonl",
	"controller_state.json",
	"cycle_gate_history.jsonl",
	"cycle_gate_report.json",
	"cycle_history.jsonl",
	"cycle_plateau_history.jsonl",
	"cycle_plateau_routing.json",
	"embedder_cache.json",
	"pseudocode_targets.json",
	"recon_manifest.json",
	"smoke_observations.jsonl",
}

func main() {
	if err := run(); err != nil {
		fmt.Fprintf(os.Stderr, "%v\n", err)
		os.Exit(1)
	}
}

func run() error {
	var root string
	var baseRunRoot string
	var fleetRoot string
	var workers int
	var hours float64
	var limit int
	var autoImplMaxTasks int
	var sleepSec int
	var maxConsecutiveFailures int
	var recentRuns int
	var embedderModel string
	var dryRun bool
	var childArgs multiFlag

	flag.StringVar(&root, "root", ".", "Repository root")
	flag.StringVar(&baseRunRoot, "base-run-root", "extraction_out/reconstruction/mega7", "Base reconstruction run root used to seed workers")
	flag.StringVar(&fleetRoot, "fleet-root", "", "Fleet working directory (default: extraction_out/reconstruction/fleets/<base>-<timestamp>)")
	flag.IntVar(&workers, "workers", 4, "Number of detached fwcycleauto workers to launch")
	flag.Float64Var(&hours, "hours", 6.0, "Maximum wall-clock hours per worker")
	flag.IntVar(&limit, "limit", 12, "Probe limit passed to fwcycleauto workers")
	flag.IntVar(&autoImplMaxTasks, "auto-impl-max-tasks", 320, "Auto implementation task budget passed to fwcycleauto workers")
	flag.IntVar(&sleepSec, "sleep-sec", 20, "Sleep between cycles in seconds for each worker")
	flag.IntVar(&maxConsecutiveFailures, "max-consecutive-failures", 3, "Stop a worker after this many consecutive failures")
	flag.IntVar(&recentRuns, "recent-runs", 12, "How many recent run directories to seed into each worker snapshot")
	flag.StringVar(&embedderModel, "embedder-model", "/home/grec-alexander/Downloads/bge-code-v1-q8_0.gguf", "Path to GGUF embedding model for behavioral classification")
	flag.BoolVar(&dryRun, "dry-run", false, "Plan provisioning and commands without launching workers")
	flag.Var(&childArgs, "child-arg", "Extra argument passed through to fwcycle (repeatable)")
	flag.Parse()

	if workers <= 0 {
		return fmt.Errorf("workers must be > 0")
	}
	if recentRuns <= 0 {
		recentRuns = 12
	}

	rootAbs, err := filepath.Abs(root)
	if err != nil {
		return fmt.Errorf("resolve root: %w", err)
	}
	baseRunRootAbs := filepath.Join(rootAbs, filepath.Clean(baseRunRoot))
	if st, err := os.Stat(baseRunRootAbs); err != nil || !st.IsDir() {
		return fmt.Errorf("base run root not found: %s", baseRunRootAbs)
	}
	if strings.TrimSpace(fleetRoot) == "" {
		baseName := filepath.Base(filepath.Clean(baseRunRoot))
		fleetRoot = filepath.Join("extraction_out", "reconstruction", "fleets", fmt.Sprintf("%s_%s", baseName, time.Now().UTC().Format("20060102T150405Z")))
	}
	fleetRootAbs := filepath.Join(rootAbs, filepath.Clean(fleetRoot))
	if err := os.MkdirAll(filepath.Join(fleetRootAbs, "workers"), 0o755); err != nil {
		return fmt.Errorf("mkdir workers dir: %w", err)
	}
	if err := os.MkdirAll(filepath.Join(fleetRootAbs, "logs"), 0o755); err != nil {
		return fmt.Errorf("mkdir logs dir: %w", err)
	}

	manifest := fleetManifest{
		SchemaVersion: "0.1.0",
		GeneratedAt:   time.Now().UTC().Format(time.RFC3339),
		Root:          rootAbs,
		BaseRunRoot:   baseRunRootAbs,
		FleetRoot:     fleetRootAbs,
		Workers:       workers,
		Hours:         hours,
		Limit:         limit,
		AutoImplMax:   autoImplMaxTasks,
		RecentRuns:    recentRuns,
		EmbedderModel: strings.TrimSpace(embedderModel),
		WorkerRows:    make([]fleetWorker, 0, workers),
	}

	for i := 1; i <= workers; i++ {
		name := fmt.Sprintf("worker-%02d", i)
		workerRootAbs := filepath.Join(fleetRootAbs, "workers", name, "run-root")
		workerDir := filepath.Dir(workerRootAbs)
		logPath := filepath.Join(fleetRootAbs, "logs", name+".log")
		if err := os.RemoveAll(workerDir); err != nil {
			return fmt.Errorf("reset worker dir %s: %w", workerDir, err)
		}
		if err := os.MkdirAll(workerRootAbs, 0o755); err != nil {
			return fmt.Errorf("mkdir worker root %s: %w", workerRootAbs, err)
		}
		if err := provisionWorkerRoot(baseRunRootAbs, workerRootAbs, recentRuns); err != nil {
			return fmt.Errorf("provision %s: %w", name, err)
		}
		workerRunRootRel, err := filepath.Rel(rootAbs, workerRootAbs)
		if err != nil {
			return fmt.Errorf("rel worker root %s: %w", workerRootAbs, err)
		}
		statusPath := filepath.Join(workerRootAbs, "fwcycleauto_status.json")
		row := fleetWorker{
			Name:       name,
			RunRoot:    workerRunRootRel,
			LogPath:    logPath,
			StatusPath: statusPath,
			TagPrefix:  fmt.Sprintf("fleet_w%02d", i),
			ChildArgs:  buildWorkerChildArgs(i, append([]string(nil), childArgs...)),
		}
		manifest.WorkerRows = append(manifest.WorkerRows, row)
	}

	manifestPath := filepath.Join(fleetRootAbs, "fleet_manifest.json")
	if err := fileio.WriteJSON(manifestPath, manifest); err != nil {
		return fmt.Errorf("write fleet manifest: %w", err)
	}

	if dryRun {
		fmt.Printf("fwcyclefleet: planned %d workers\n", len(manifest.WorkerRows))
		fmt.Printf("  manifest: %s\n", manifestPath)
		for _, row := range manifest.WorkerRows {
			fmt.Printf("  %s run_root=%s log=%s child_args=%s\n", row.Name, row.RunRoot, row.LogPath, strings.Join(row.ChildArgs, " "))
		}
		return nil
	}

	for i := range manifest.WorkerRows {
		pid, err := launchWorker(rootAbs, manifest.WorkerRows[i], hours, limit, autoImplMaxTasks, sleepSec, maxConsecutiveFailures, embedderModel)
		if err != nil {
			return err
		}
		manifest.WorkerRows[i].PID = pid
	}
	if err := fileio.WriteJSON(manifestPath, manifest); err != nil {
		return fmt.Errorf("write fleet manifest with pids: %w", err)
	}

	fmt.Printf("fwcyclefleet: launched %d workers\n", len(manifest.WorkerRows))
	fmt.Printf("  manifest: %s\n", manifestPath)
	for _, row := range manifest.WorkerRows {
		fmt.Printf("  %s pid=%d run_root=%s log=%s\n", row.Name, row.PID, row.RunRoot, row.LogPath)
	}
	return nil
}

func buildWorkerChildArgs(workerIndex int, base []string) []string {
	args := append([]string(nil), base...)
	args = ensureArg(args, "-update-checkpoints=false")
	args = ensureArg(args, "-refresh-ida-before-cycle=false")
	args = ensureArg(args, "-refresh-ida-on-zero-probes=false")
	args = ensureArg(args, "-dead-plateau-after=4")
	args = ensurePrefixedArg(args, "-plateau-mode=", defaultPlateauMode(workerIndex))
	return args
}

func defaultPlateauMode(workerIndex int) string {
	modes := []string{"synthesize", "synthesize", "auto", "explore"}
	if workerIndex <= 0 {
		return modes[0]
	}
	return modes[(workerIndex-1)%len(modes)]
}

func ensureArg(args []string, want string) []string {
	for _, arg := range args {
		if strings.TrimSpace(arg) == want {
			return args
		}
	}
	return append(args, want)
}

func ensurePrefixedArg(args []string, prefix, value string) []string {
	for _, arg := range args {
		if strings.HasPrefix(strings.TrimSpace(arg), prefix) {
			return args
		}
	}
	return append(args, prefix+value)
}

func launchWorker(rootAbs string, row fleetWorker, hours float64, limit, autoImplMaxTasks, sleepSec, maxConsecutiveFailures int, embedderModel string) (int, error) {
	if err := os.MkdirAll(filepath.Dir(row.LogPath), 0o755); err != nil {
		return 0, fmt.Errorf("mkdir log dir: %w", err)
	}
	logFile, err := os.OpenFile(row.LogPath, os.O_CREATE|os.O_WRONLY|os.O_TRUNC, 0o644)
	if err != nil {
		return 0, fmt.Errorf("open log %s: %w", row.LogPath, err)
	}
	cmdArgs := []string{
		"run", "./cmd/fwcycleauto",
		"-run-root", row.RunRoot,
		"-hours", fmt.Sprintf("%.3f", hours),
		"-limit", fmt.Sprintf("%d", limit),
		"-auto-impl-max-tasks", fmt.Sprintf("%d", autoImplMaxTasks),
		"-sleep-sec", fmt.Sprintf("%d", sleepSec),
		"-max-consecutive-failures", fmt.Sprintf("%d", maxConsecutiveFailures),
		"-tag-prefix", row.TagPrefix,
	}
	if strings.TrimSpace(embedderModel) != "" {
		cmdArgs = append(cmdArgs, "-embedder-model", embedderModel)
	}
	for _, arg := range row.ChildArgs {
		cmdArgs = append(cmdArgs, "-child-arg", arg)
	}
	cmd := exec.Command("go", cmdArgs...)
	cmd.Dir = rootAbs
	cmd.Stdout = logFile
	cmd.Stderr = logFile
	if err := cmd.Start(); err != nil {
		_ = logFile.Close()
		return 0, fmt.Errorf("launch %s: %w", row.Name, err)
	}
	pid := cmd.Process.Pid
	_ = cmd.Process.Release()
	_ = logFile.Close()
	return pid, nil
}

func provisionWorkerRoot(baseRunRootAbs, workerRootAbs string, recentRuns int) error {
	for _, name := range workerCopyDirs {
		src := filepath.Join(baseRunRootAbs, name)
		if _, err := os.Stat(src); err != nil {
			if os.IsNotExist(err) {
				continue
			}
			return err
		}
		if err := copyPath(src, filepath.Join(workerRootAbs, name)); err != nil {
			return fmt.Errorf("copy %s: %w", name, err)
		}
	}
	for _, name := range workerCopyFiles {
		src := filepath.Join(baseRunRootAbs, name)
		if _, err := os.Stat(src); err != nil {
			if os.IsNotExist(err) {
				continue
			}
			return err
		}
		if err := copyPath(src, filepath.Join(workerRootAbs, name)); err != nil {
			return fmt.Errorf("copy %s: %w", name, err)
		}
	}
	return copyRecentRuns(filepath.Join(baseRunRootAbs, "runs"), filepath.Join(workerRootAbs, "runs"), recentRuns)
}

func copyRecentRuns(srcRuns, dstRuns string, recentRuns int) error {
	entries, err := os.ReadDir(srcRuns)
	if err != nil {
		if os.IsNotExist(err) {
			return nil
		}
		return err
	}
	type runDir struct {
		name string
		mod  time.Time
	}
	rows := make([]runDir, 0, len(entries))
	for _, entry := range entries {
		if !entry.IsDir() {
			continue
		}
		info, err := entry.Info()
		if err != nil {
			continue
		}
		rows = append(rows, runDir{name: entry.Name(), mod: info.ModTime()})
	}
	sort.Slice(rows, func(i, j int) bool {
		if rows[i].mod.Equal(rows[j].mod) {
			return rows[i].name > rows[j].name
		}
		return rows[i].mod.After(rows[j].mod)
	})
	if recentRuns > 0 && len(rows) > recentRuns {
		rows = rows[:recentRuns]
	}
	for _, row := range rows {
		if err := copyPath(filepath.Join(srcRuns, row.name), filepath.Join(dstRuns, row.name)); err != nil {
			return err
		}
	}
	return nil
}

func copyPath(src, dst string) error {
	info, err := os.Lstat(src)
	if err != nil {
		return err
	}
	if info.Mode()&os.ModeSymlink != 0 {
		target, err := os.Readlink(src)
		if err != nil {
			return err
		}
		if err := os.MkdirAll(filepath.Dir(dst), 0o755); err != nil {
			return err
		}
		return os.Symlink(target, dst)
	}
	if info.IsDir() {
		if err := os.MkdirAll(dst, info.Mode().Perm()); err != nil {
			return err
		}
		entries, err := os.ReadDir(src)
		if err != nil {
			return err
		}
		for _, entry := range entries {
			if err := copyPath(filepath.Join(src, entry.Name()), filepath.Join(dst, entry.Name())); err != nil {
				return err
			}
		}
		return nil
	}
	if err := os.MkdirAll(filepath.Dir(dst), 0o755); err != nil {
		return err
	}
	in, err := os.Open(src)
	if err != nil {
		return err
	}
	defer in.Close()
	out, err := os.OpenFile(dst, os.O_CREATE|os.O_WRONLY|os.O_TRUNC, info.Mode().Perm())
	if err != nil {
		return err
	}
	defer out.Close()
	if _, err := io.Copy(out, in); err != nil {
		return err
	}
	return out.Sync()
}
