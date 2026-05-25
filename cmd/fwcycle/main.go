package main

import (
	"flag"
	"fmt"
	"os"
	"os/exec"
	"path/filepath"
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
	var sourceGlobA string
	var sourceGlobB string
	var limit int
	var maxInsns int
	var missingCooldown int
	var retryFaultOnce bool
	var updateCheckpoints bool
	var checkpointMinSuccess int
	var checkpointMaxAdd int
	var readmePath string
	var outcomesPath string
	var tag string

	flag.StringVar(&root, "root", ".", "Repository root")
	flag.StringVar(&runRoot, "run-root", "extraction_out/reconstruction/mega7", "Reconstruction run root")
	flag.StringVar(&primarySource, "primary-source", "extraction_out/reconstruction/mega7/final/fmacfw_8800d80_u02_bin.reconstructed.c", "Primary reconstructed C source")
	flag.StringVar(&sourceGlobA, "source-glob-a", "extraction_out/reconstruction/mega7/final_recovered/*.c", "Additional source glob A")
	flag.StringVar(&sourceGlobB, "source-glob-b", "extraction_out/reconstruction/mega7/final/*.c", "Additional source glob B")
	flag.IntVar(&limit, "limit", 10, "Probe target limit")
	flag.IntVar(&maxInsns, "max-insns", 120, "Max instructions per probe")
	flag.IntVar(&missingCooldown, "missing-cooldown", 2, "Skip targets with repeated missing-symbol outcomes")
	flag.BoolVar(&retryFaultOnce, "retry-fault-once", true, "Retry one time with learned fault seed on unmapped faults")
	flag.BoolVar(&updateCheckpoints, "update-checkpoints", true, "Automatically promote stable smoke successes into README after cycle")
	flag.IntVar(&checkpointMinSuccess, "checkpoint-min-success", 1, "Minimum success count required for checkpoint auto-promotion")
	flag.IntVar(&checkpointMaxAdd, "checkpoint-max-add", 15, "Maximum checkpoint entries auto-added per cycle")
	flag.StringVar(&readmePath, "readme", "README.md", "README path for checkpoint promotion")
	flag.StringVar(&outcomesPath, "outcomes", "extraction_out/reconstruction/mega7/smoke_observations.jsonl", "Smoke outcomes JSONL path")
	flag.StringVar(&tag, "tag", "", "Cycle run tag")
	flag.Parse()

	rootAbs, err := filepath.Abs(root)
	if err != nil {
		fmt.Fprintf(os.Stderr, "resolve root: %v\n", err)
		os.Exit(1)
	}

	args := []string{
		"tools/recon_cycle.py",
		"--run-root", runRoot,
		"--primary-source", primarySource,
		"--source-glob", sourceGlobA,
		"--source-glob", sourceGlobB,
		"--limit", fmt.Sprintf("%d", limit),
		"--max-insns", fmt.Sprintf("%d", maxInsns),
		"--missing-cooldown", fmt.Sprintf("%d", missingCooldown),
	}
	if retryFaultOnce {
		args = append(args, "--retry-fault-once")
	}
	if tag != "" {
		args = append(args, "--tag", tag)
	}

	if err := runCmd(rootAbs, "python3", args...); err != nil {
		fmt.Fprintf(os.Stderr, "run recon cycle: %v\n", err)
		os.Exit(1)
	}

	if !updateCheckpoints {
		return
	}
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
