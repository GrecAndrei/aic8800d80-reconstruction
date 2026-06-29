package main

import (
	"flag"
	"fmt"
	"os"
	"path/filepath"
	"strings"

	"aic8800d80/internal/decompile"
	"aic8800d80/internal/fileio"
)

// Common flags shared by all subcommands.
type commonFlags struct {
	Root       string
	Decompiled string
	Out        string
	Images     string
	Verbose    bool
}

func (c *commonFlags) Register(fs *flag.FlagSet) {
	fs.StringVar(&c.Root, "root", ".", "workspace root")
	fs.StringVar(&c.Decompiled, "decompiled", "", "decompiled C dir (default <root>/harness_v19/decompiled)")
	fs.StringVar(&c.Out, "out", "", "output dir (default <root>/harness_v25/out)")
	fs.StringVar(&c.Images, "images", "", "comma-separated image list (default: all)")
	fs.BoolVar(&c.Verbose, "verbose", false, "verbose output")
}

func (c *commonFlags) Resolve() error {
	if c.Root == "" {
		c.Root = "."
	}
	abs, err := filepath.Abs(c.Root)
	if err != nil {
		return err
	}
	c.Root = abs
	if c.Decompiled == "" {
		c.Decompiled = filepath.Join(c.Root, "harness_v19", "decompiled")
	}
	if c.Out == "" {
		c.Out = filepath.Join(c.Root, "harness_v25", "out")
	}
	if err := os.MkdirAll(c.Out, 0o755); err != nil {
		return err
	}
	return nil
}

func (c *commonFlags) SelectedImages() ([]string, error) {
	if c.Images == "" {
		return decompile.CollectImages(c.Decompiled), nil
	}
	var out []string
	for _, s := range strings.Split(c.Images, ",") {
		s = strings.TrimSpace(s)
		if s != "" {
			out = append(out, s)
		}
	}
	return out, nil
}

func (c *commonFlags) VPrintf(format string, args ...any) {
	if c.Verbose {
		fmt.Fprintf(os.Stderr, format+"\n", args...)
	}
}

// funcList represents a list of funcs in one image.
type funcList struct {
	Image  string
	Funcs  []*decompile.Func
	OutDir string
}

// runScan parses v19 decompiled C into funcs.jsonl.
func runScan(args []string) error {
	fs := flag.NewFlagSet("scan", flag.ContinueOnError)
	var cf commonFlags
	cf.Register(fs)
	if err := fs.Parse(args); err != nil {
		return err
	}
	if err := cf.Resolve(); err != nil {
		return err
	}
	images, err := cf.SelectedImages()
	if err != nil {
		return err
	}
	cf.VPrintf("scan: %d images, out=%s", len(images), cf.Out)
	for _, img := range images {
		funcs, err := decompile.ParseDir(cf.Decompiled, img)
		if err != nil {
			fmt.Fprintf(os.Stderr, "  %s: %v\n", img, err)
			continue
		}
		// Write per-image funcs.jsonl
		outPath := filepath.Join(cf.Out, img+"_funcs.jsonl")
		if err := fileio.WriteJSONL(outPath, funcs); err != nil {
			return err
		}
		cf.VPrintf("  %s: %d funcs -> %s", img, len(funcs), outPath)
	}
	return nil
}
