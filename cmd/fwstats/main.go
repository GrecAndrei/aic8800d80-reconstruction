package main

import (
	"flag"
	"fmt"
	"os"
	"time"

	"aic8800d80/internal/stats"
)

func main() {
	var outDir string
	var watch bool
	var interval time.Duration

	flag.StringVar(&outDir, "out", "extraction_out", "Extraction output directory")
	flag.BoolVar(&watch, "watch", false, "Continuously collect stats")
	flag.DurationVar(&interval, "interval", 5*time.Second, "Watch collection interval")
	flag.Parse()

	collect := func() {
		snap, err := stats.CollectAndPersist(outDir)
		if err != nil {
			fmt.Fprintf(os.Stderr, "stats collection failed: %v\n", err)
			return
		}
		fmt.Printf("stats updated at %s | images=%d functions=%d links=%d calls=%d messages=%d state_machines=%d queue=%d patches=%d recon_semantic=%.3f%% recon_conformance=%.3f%% low=%d\n",
			snap.GeneratedAt,
			snap.Totals.Images,
			snap.Totals.Functions,
			snap.Totals.Links,
			snap.Totals.Calls,
			snap.Totals.Messages,
			snap.Totals.StateMachines,
			snap.Totals.Queue,
			snap.Totals.Patches,
			snap.Progress.ReconSemanticPct,
			snap.Progress.ReconConformancePct,
			snap.Progress.ReconConformanceLow,
		)
	}

	collect()
	if !watch {
		return
	}

	ticker := time.NewTicker(interval)
	defer ticker.Stop()

	for range ticker.C {
		collect()
	}
}
