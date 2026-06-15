package main

import "fmt"

// runAll chains all subcommands in order.
func runAll(args []string) error {
	steps := []struct {
		name string
		fn   func([]string) error
		skip bool
	}{
		{"scan", runScan, false},
		{"structs", runStructs, false},
		{"callgraph", runCallgraph, false},
		{"magic", runMagic, false},
		{"initpath", runInitPath, false},
		{"initpath2", runInitPath2, false},
		{"diff", runDiff, true},  // diff needs explicit A,B args
		{"annotate", runAnnotate, false},
		{"report", runReport, false},
	}
	for _, s := range steps {
		if s.skip {
			fmt.Printf("[skip] %s\n", s.name)
			continue
		}
		fmt.Printf("[run]  %s\n", s.name)
		if err := s.fn(args); err != nil {
			return fmt.Errorf("%s: %w", s.name, err)
		}
	}
	return nil
}
