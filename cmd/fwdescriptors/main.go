package main

import (
	"flag"
	"fmt"
	"os"
	"path/filepath"

	"aic8800d80/internal/fileio"
	"aic8800d80/internal/reconstruct"
)

func main() {
	var runRoot string
	var cfgHints string
	var pseudoHints string
	var outcomes string
	var synthEvidence string
	var embedderCache string
	var functionLinks string
	var consensusPath string
	var descriptorOut string
	var motifOut string
	var summaryOut string

	flag.StringVar(&runRoot, "run-root", "extraction_out/reconstruction/mega7", "Reconstruction run root")
	flag.StringVar(&cfgHints, "cfg-hints", "", "CFG hints JSONL path")
	flag.StringVar(&pseudoHints, "pseudo-hints", "", "Pseudocode hints JSONL path")
	flag.StringVar(&outcomes, "outcomes", "", "Smoke outcomes JSONL path")
	flag.StringVar(&synthEvidence, "synth-evidence", "", "Synth evidence JSON path")
	flag.StringVar(&embedderCache, "embedder-cache", "", "Embedder cache JSON path")
	flag.StringVar(&functionLinks, "function-links", "", "Function links JSONL path")
	flag.StringVar(&consensusPath, "consensus", "", "Consensus behavior JSONL path")
	flag.StringVar(&descriptorOut, "out", "", "Descriptor JSON output path")
	flag.StringVar(&motifOut, "motif-out", "", "Motif memory JSON output path")
	flag.StringVar(&summaryOut, "summary-out", "", "Descriptor summary JSON output path")
	flag.Parse()

	if cfgHints == "" {
		cfgHints = filepath.Join(runRoot, "cfg_hints.jsonl")
	}
	if pseudoHints == "" {
		pseudoHints = filepath.Join("extraction_out", "ida_export_pseudo", "pseudocode_hints.jsonl")
	}
	if outcomes == "" {
		outcomes = filepath.Join(runRoot, "smoke_observations.jsonl")
	}
	if synthEvidence == "" {
		synthEvidence = filepath.Join(runRoot, "synth", "implsynth_evidence.json")
	}
	if embedderCache == "" {
		embedderCache = filepath.Join(runRoot, "embedder_cache.json")
	}
	analysisDir := filepath.Join(runRoot, "analysis")
	if descriptorOut == "" {
		descriptorOut = filepath.Join(analysisDir, "function_descriptors.json")
	}
	if motifOut == "" {
		motifOut = filepath.Join(analysisDir, "motif_recipe_memory.json")
	}
	if summaryOut == "" {
		summaryOut = filepath.Join(analysisDir, "descriptor_summary.json")
	}

	artifacts, err := reconstruct.BuildArtifacts(reconstruct.BuildPaths{
		CFGHintsPath:      cfgHints,
		PseudoHintsPath:   pseudoHints,
		OutcomesPath:      outcomes,
		SynthEvidencePath: synthEvidence,
		EmbedderCachePath: embedderCache,
		FunctionLinksPath: functionLinks,
		ConsensusPath:     consensusPath,
	})
	if err != nil {
		fail("build descriptors: %v", err)
	}
	if err := fileio.WriteJSON(descriptorOut, artifacts.Descriptors); err != nil {
		fail("write descriptors: %v", err)
	}
	if err := fileio.WriteJSON(motifOut, artifacts.MotifMemory); err != nil {
		fail("write motif memory: %v", err)
	}
	if err := fileio.WriteJSON(summaryOut, artifacts.Summary); err != nil {
		fail("write summary: %v", err)
	}

	fmt.Printf("descriptor analysis generated.\n")
	fmt.Printf("  descriptor_count: %d\n", artifacts.Summary.DescriptorCount)
	fmt.Printf("  motif_backed_count: %d\n", artifacts.Summary.MotifBackedCount)
	fmt.Printf("  out: %s\n", descriptorOut)
	fmt.Printf("  motif_out: %s\n", motifOut)
	fmt.Printf("  summary_out: %s\n", summaryOut)
}

func fail(format string, args ...any) {
	fmt.Fprintf(os.Stderr, format+"\n", args...)
	os.Exit(1)
}
