package main

import (
	"flag"
	"fmt"
	"os"
	"time"

	"aic8800d80/internal/pipeline"
)

func main() {
	var root string
	var outDir string
	var minStringLen int
	var embeddingModel string
	var queueLimit int
	var queueMinScore float64
	var runTag string

	flag.StringVar(&root, "root", ".", "Workspace root containing firmware blobs")
	flag.StringVar(&outDir, "out", "extraction_out", "Output directory for JSONL artifacts")
	flag.IntVar(&minStringLen, "min-string-len", 4, "Minimum printable ASCII string length")
	flag.StringVar(&embeddingModel, "embedding-model", "", "Optional GGUF embedding model path for future semantic alignment")
	flag.IntVar(&queueLimit, "queue-limit", 1200, "Maximum mining queue entries to emit (0 = no limit)")
	flag.Float64Var(&queueMinScore, "queue-min-score", 0.8, "Minimum priority score included in mining queues")
	flag.StringVar(&runTag, "run-tag", "", "Optional run namespace; use 'auto' for timestamped runs under <out>/runs/")
	flag.Parse()
	if runTag == "auto" {
		runTag = time.Now().UTC().Format("20060102T150405Z")
	}

	result, err := pipeline.Run(root, outDir, minStringLen, embeddingModel, queueLimit, queueMinScore, runTag)
	if err != nil {
		fmt.Fprintf(os.Stderr, "pipeline failed: %v\n", err)
		os.Exit(1)
	}

	fmt.Printf("Extraction complete.\n")
	fmt.Printf("  root: %s\n", root)
	fmt.Printf("  out:  %s\n", outDir)
	fmt.Printf("  images:    %d\n", result.ImageCount)
	fmt.Printf("  functions: %d\n", result.FunctionCount)
	fmt.Printf("  artifacts: %d\n", result.ArtifactCount)
	fmt.Printf("  links:     %d\n", result.FunctionLinkCount)
	fmt.Printf("  patches:   %d\n", result.PatchEntryCount)
	fmt.Printf("  calls:     %d\n", result.CallEdgeCount)
	fmt.Printf("  messages:  %d\n", result.MessageCount)
	fmt.Printf("  state_machines: %d\n", result.StateMachineCount)
	fmt.Printf("  message_routes: %d\n", result.MessageRouteCount)
	fmt.Printf("  queue:     %d\n", result.MiningQueueCount)
}
