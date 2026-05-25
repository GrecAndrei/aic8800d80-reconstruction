package main

import (
	"flag"
	"fmt"
	"os"
	"os/exec"
	"path/filepath"
)

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

	cmd := exec.Command("python3", args...)
	cmd.Dir = rootAbs
	cmd.Stdout = os.Stdout
	cmd.Stderr = os.Stderr
	if err := cmd.Run(); err != nil {
		fmt.Fprintf(os.Stderr, "run recon cycle: %v\n", err)
		os.Exit(1)
	}
}
