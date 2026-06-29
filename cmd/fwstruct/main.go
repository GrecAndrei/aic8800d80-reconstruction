// fwstruct - unified firmware-structure analyzer.
//
// Subcommands:
//   scan        parse v19 decompiled C into funcs.jsonl
//   structs     cluster funcs by access pattern, propose struct types
//   names       LLM-name proposed structs
//   xref        cross-reference struct fields to functions (TODO)
//   callgraph   build call graph
//   magic       classify numeric literals (magic numbers)
//   initpath    extract boot path from start()
//   diff        cross-binary version diff
//   types       fix Hex-Rays type-inference bugs (TODO)
//   ivt         rewrite IVT for v18 bootable (TODO)
//   annotate    emit annotated C with all known context (TODO)
//   report      aggregate summary across all subcommands (TODO)
//   all         run scan+structs+names+xref+callgraph+magic+initpath+annotate (TODO)
//
// All outputs go to <out>/. Each subcommand reads prior outputs when
// available, so a re-run of `names` doesn't re-parse v19.
package main

import (
	"fmt"
	"os"
)

// runStub prints a TODO message for unimplemented subcommands.
func runStub(args []string, name string) error {
	fmt.Fprintf(os.Stderr, "fwstruct %s: not yet implemented\n", name)
	return nil
}

func main() {
	if len(os.Args) < 2 {
		usage()
		os.Exit(2)
	}
	cmd, args := os.Args[1], os.Args[2:]
	var err error
	switch cmd {
	case "scan":
		err = runScan(args)
	case "structs":
		err = runStructs(args)
	case "names":
		err = runNames(args)
	case "xref":
		err = runStub(args, "xref")
	case "callgraph":
		err = runCallgraph(args)
	case "magic":
		err = runMagic(args)
	case "initpath":
		err = runInitPath(args)
	case "diff":
		err = runDiff(args)
	case "types":
		err = runStub(args, "types")
	case "ivt":
		err = runStub(args, "ivt")
	case "annotate":
		err = runStub(args, "annotate")
	case "report":
		err = runStub(args, "report")
	case "all":
		err = runStub(args, "all")
	case "-h", "--help", "help":
		usage()
		return
	default:
		fmt.Fprintf(os.Stderr, "fwstruct: unknown command %q\n", cmd)
		usage()
		os.Exit(2)
	}
	if err != nil {
		fmt.Fprintf(os.Stderr, "fwstruct %s: %v\n", cmd, err)
		os.Exit(1)
	}
}

func usage() {
	fmt.Fprint(os.Stderr, `fwstruct - unified firmware-structure analyzer

Usage:
  fwstruct <command> [flags]

Commands:
  scan         parse v19 decompiled C into funcs.jsonl
  structs      cluster funcs by access pattern, propose struct types
  names        LLM-name proposed structs (calls MiniMax-M3)
  xref         cross-reference struct fields to functions
  callgraph    build call graph from C
  magic        classify numeric literals
  initpath     extract boot path from start()
  diff         cross-binary version diff
  types        fix Hex-Rays type-inference bugs
  ivt          rewrite IVT for v18 bootable WFFW
  annotate     emit annotated C with all known context
  report       aggregate summary across all subcommands
  all          run full pipeline (scan..annotate)

Common flags:
  --root <path>      workspace root (default: .)
  --decompiled <p>   decompiled C dir (default: <root>/harness_v19/decompiled)
  --out <path>       output dir (default: <root>/harness_v25/out)
  --images <a,b,c>   comma-separated image list (default: all)
  --llm-key-dir <p>  directory of *.key files for LLM
  --llm-model <m>    LLM model (default: MiniMax-M3)
  --concurrency <n>  LLM call parallelism (default: 4)
  --verbose          verbose output
`)
}
