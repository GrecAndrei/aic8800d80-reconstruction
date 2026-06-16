package main

import (
	"encoding/json"
	"flag"
	"fmt"
	"os"
	"path/filepath"
	"sort"
	"strings"

	"aic8800d80/internal/fileio"
)

// runApplyNames renames sub_XXXXXX functions in v19 C files
// using the names from llm_names.json.
//
// For each (img, addr) -> name mapping:
//   - The C file 100200_sub_100200.c is renamed to 100200_<name>.c
//   - The function definition sub_100200(...) is renamed to <name>(...)
//   - All callers sub_100200(...) are renamed to <name>(...)
func runApplyNames(args []string) error {
	fs := flag.NewFlagSet("applynames", flag.ContinueOnError)
	var (
		root      string
		decDir    string
		namesPath string
		outDir    string
		dryRun    bool
	)
	fs.StringVar(&root, "root", ".", "workspace root")
	fs.StringVar(&decDir, "decompiled", "harness_v19/decompiled", "v19 decompiled C dir")
	fs.StringVar(&namesPath, "names", "harness_v19/llm_names.json", "llm_names.json path")
	fs.StringVar(&outDir, "out", "harness_v19_named/decompiled", "output dir for named C files")
	fs.BoolVar(&dryRun, "dry-run", false, "don't write files, just report")
	if err := fs.Parse(args); err != nil {
		return err
	}

	// Load names
	namesRaw, err := os.ReadFile(namesPath)
	if err != nil {
		return err
	}
	var allNames map[string]struct {
		Name string `json:"name"`
	}
	if err := json.Unmarshal(namesRaw, &allNames); err != nil {
		return err
	}

	// Group by image
	byImage := make(map[string]map[string]string) // image -> addr_hex -> name
	// First pass: count name occurrences per image
	nameCount := make(map[string]map[string]int) // image -> name -> count
	for k, v := range allNames {
		if v.Name == "" || strings.HasPrefix(v.Name, "sub_") {
			continue
		}
		parts := strings.SplitN(k, "|", 2)
		if len(parts) != 2 {
			continue
		}
		img := parts[0]
		if _, ok := nameCount[img]; !ok {
			nameCount[img] = make(map[string]int)
		}
		nameCount[img][v.Name]++
	}
	// Second pass: assign names, disambiguating duplicates with _n suffix
	seen := make(map[string]map[string]int) // image -> name -> suffix count
	for k, v := range allNames {
		if v.Name == "" || strings.HasPrefix(v.Name, "sub_") {
			continue
		}
		parts := strings.SplitN(k, "|", 2)
		if len(parts) != 2 {
			continue
		}
		img, addr := parts[0], parts[1]
		name := v.Name
		if nameCount[img][name] > 1 {
			// Multiple funcs with this name - need to disambiguate
			if _, ok := seen[img]; !ok {
				seen[img] = make(map[string]int)
			}
			seen[img][name]++
			if seen[img][name] > 1 {
				name = fmt.Sprintf("%s_%d", name, seen[img][name])
			}
		}
		if _, ok := byImage[img]; !ok {
			byImage[img] = make(map[string]string)
		}
		byImage[img][strings.ToLower(addr)] = name
	}

	if !dryRun {
		if err := os.MkdirAll(outDir, 0o755); err != nil {
			return err
		}
	}

	// For each image, process its C files
	images, err := os.ReadDir(decDir)
	if err != nil {
		return err
	}
	totalFiles := 0
	totalRenames := 0
	totalDefRenames := 0
	for _, imgE := range images {
		if !imgE.IsDir() {
			continue
		}
		img := imgE.Name()
		names, ok := byImage[img]
		if !ok {
			continue
		}
		imgIn := filepath.Join(decDir, img)
		imgOut := filepath.Join(outDir, img)
		if !dryRun {
			if err := os.MkdirAll(imgOut, 0o755); err != nil {
				return err
			}
		}
		// Read all C files
		files, err := os.ReadDir(imgIn)
		if err != nil {
			fmt.Fprintf(os.Stderr, "skip %s: %v\n", img, err)
			continue
		}
		// Build a sub_ -> real_name map for callers
		subToReal := make(map[string]string)
		for addr, name := range names {
			subToReal["sub_"+strings.ToLower(strings.TrimPrefix(addr, "0x"))] = name
		}
		// Pre-compute (old_sub, new_name) pairs (use strings.Replace, not regex - much faster)
		type rename struct {
			old  string
			repl string // "old(" -> "new("
		}
		var renames []rename
		for sub, real := range subToReal {
			if sub == real {
				continue
			}
			renames = append(renames, rename{old: sub + "(", repl: real + "("})
		}
		// For each C file:
		for _, f := range files {
			if !strings.HasSuffix(f.Name(), ".c") {
				continue
			}
			fp := filepath.Join(imgIn, f.Name())
			content, err := os.ReadFile(fp)
			if err != nil {
				continue
			}
			text := string(content)
			// Parse filename
			parts := strings.SplitN(strings.TrimSuffix(f.Name(), ".c"), "_", 2)
			if len(parts) != 2 {
				continue
			}
			addrHex := "0x" + strings.ToLower(parts[0])
			oldSub := parts[1]
			newName, hasName := names[addrHex]
			if !hasName {
				newName = oldSub // no rename
			}
			// Rename callers in body using strings.Replace (O(n) per call)
			bodyChanged := false
			for _, r := range renames {
				if strings.Contains(text, r.old) {
					text = strings.ReplaceAll(text, r.old, r.repl)
					bodyChanged = true
				}
			}
			// Rename function definition (only if this file's func has a new name)
			defChanged := false
			if hasName {
				// Pattern: "oldSub(...) {" -> "newName(...) {"
				oldDef := oldSub + "("
				newDef := newName + "("
				if strings.Contains(text, oldDef) {
					text = strings.ReplaceAll(text, oldDef, newDef)
					defChanged = true
				}
				// Also rename the top comment "// sub_XXXXX @..." -> "// name @..."
				// The comment uses uppercase sub_ name (e.g., "sub_1002A0")
				// But the filename uses lowercase. So we need to find the
				// uppercase version in the comment.
				upperSub := strings.ToUpper(oldSub)
				// The original sub_ is already uppercase, no change needed
				_ = upperSub
				oldComment := oldSub + " @"
				newComment := newName + " @"
				text = strings.ReplaceAll(text, oldComment, newComment)
				// Also rename the filename
				newFileName := parts[0] + "_" + newName + ".c"
				fp = filepath.Join(imgOut, newFileName)
			} else {
				fp = filepath.Join(imgOut, f.Name())
			}
			// Write output
			if !dryRun {
				if err := os.WriteFile(fp, []byte(text), 0644); err != nil {
					fmt.Fprintf(os.Stderr, "write %s: %v\n", fp, err)
				}
			}
			totalFiles++
			if bodyChanged {
				totalRenames++
			}
			if defChanged {
				totalDefRenames++
			}
		}
	}
	if dryRun {
		fmt.Fprintf(os.Stderr, "applynames (dry-run): would process %d files, %d body renames, %d def renames\n",
			totalFiles, totalRenames, totalDefRenames)
	} else {
		fmt.Fprintf(os.Stderr, "applynames: processed %d files, %d body renames, %d def renames\n",
			totalFiles, totalRenames, totalDefRenames)
	}
	return nil
}

// Use fileio for atomic write
var _ = fileio.WriteBytes
var _ = sort.Strings
