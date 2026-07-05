package main

import (
	"bufio"
	"crypto/sha256"
	"encoding/hex"
	"encoding/json"
	"errors"
	"flag"
	"fmt"
	"os"
	"os/exec"
	"path/filepath"
	"regexp"
	"sort"
	"strconv"
	"strings"
	"time"

	"aic8800d80/internal/fileio"
)

const (
	schemaVersion = "0.1.0"
	chipBase      = uint32(0x100000)
)

var imageToFirmware = map[string]string{
	"fmacfw_8800d80_h_u02_bin":  "fmacfw_8800d80_h_u02.bin",
	"fmacfw_8800d80_u02_bin":    "fmacfw_8800d80_u02.bin",
	"fmacfwbt_8800d80_u02_bin":  "fmacfwbt_8800d80_u02.bin",
	"lmacfw_rf_8800d80_u02_bin": "lmacfw_rf_8800d80_u02.bin",
}

type commonFlags struct {
	Root string
	V25  string
	Out  string
}

func (c *commonFlags) register(fs *flag.FlagSet) {
	fs.StringVar(&c.Root, "root", ".", "workspace root")
	fs.StringVar(&c.V25, "v25", "", "v25 output dir (default <root>/harness_v25/out)")
	fs.StringVar(&c.Out, "out", "", "v26 output dir (default <root>/harness_v26)")
}

func (c *commonFlags) resolve() error {
	if c.Root == "" {
		c.Root = "."
	}
	abs, err := filepath.Abs(c.Root)
	if err != nil {
		return err
	}
	c.Root = abs
	if c.V25 == "" {
		c.V25 = filepath.Join(c.Root, "harness_v25", "out")
	}
	if c.Out == "" {
		c.Out = filepath.Join(c.Root, "harness_v26")
	}
	return os.MkdirAll(c.Out, 0o755)
}

type indexFile struct {
	GeneratedAt    string      `json:"generated_at"`
	Images         []string    `json:"images"`
	TotalFunctions int         `json:"total_functions"`
	NamedFunctions int         `json:"named_functions"`
	Functions      []indexFunc `json:"functions"`
}

type indexFunc struct {
	Image     string `json:"image"`
	Address   uint32 `json:"address"`
	Name      string `json:"name"`
	Subsystem string `json:"subsystem"`
	Cluster   string `json:"cluster"`
	NLines    int    `json:"n_lines"`
	NGotos    int    `json:"n_gotos"`
	NReturns  int    `json:"n_returns"`
	NCallees  int    `json:"n_callees"`
	NCallers  int    `json:"n_callers"`
	NAccesses int    `json:"n_accesses"`
	NLiterals int    `json:"n_literals"`
}

type ledgerRecord struct {
	SchemaVersion string   `json:"schema_version"`
	Image         string   `json:"image"`
	Address       string   `json:"address"`
	Name          string   `json:"name"`
	Size          int      `json:"size"`
	Mode          string   `json:"mode"`
	SourceKind    string   `json:"source_kind"`
	CompileStatus string   `json:"compile_status"`
	VerifyStatus  string   `json:"verify_status"`
	Subsystem     string   `json:"subsystem"`
	Cluster       string   `json:"cluster"`
	NCallers      int      `json:"n_callers"`
	NCallees      int      `json:"n_callees"`
	NAccesses     int      `json:"n_accesses"`
	NLiterals     int      `json:"n_literals"`
	ByteSHA256    string   `json:"byte_sha256"`
	CSource       string   `json:"c_source,omitempty"`
	Reasons       []string `json:"reasons"`
}

type manifest struct {
	SchemaVersion string         `json:"schema_version"`
	GeneratedAt   string         `json:"generated_at"`
	InputIndex    string         `json:"input_index"`
	Total         int            `json:"total"`
	Images        []imageSummary `json:"images"`
}

type imageSummary struct {
	Image       string         `json:"image"`
	Total       int            `json:"total"`
	ByMode      map[string]int `json:"by_mode"`
	ByCompile   map[string]int `json:"by_compile_status"`
	ByVerify    map[string]int `json:"by_verify_status"`
	TotalBytes  int            `json:"total_bytes"`
	Blocked     int            `json:"blocked"`
	AsmExact    int            `json:"asm_exact"`
	Candidates  int            `json:"c_candidate"`
	CVerified   int            `json:"c_verified"`
	SourceBytes int            `json:"source_bytes"`
}

type buildReport struct {
	SchemaVersion string            `json:"schema_version"`
	GeneratedAt   string            `json:"generated_at"`
	Compiler      string            `json:"compiler,omitempty"`
	Objcopy       string            `json:"objcopy,omitempty"`
	Images        map[string]string `json:"images"`
	Errors        []string          `json:"errors,omitempty"`
}

type funcMeta struct {
	Image    string   `json:"image"`
	Address  uint32   `json:"address"`
	Name     string   `json:"name"`
	NLines   int      `json:"n_lines"`
	Callees  []string `json:"callees"`
	Accesses []any    `json:"accesses"`
	Literals []string `json:"literals"`
}

type candidateRecord struct {
	SchemaVersion string   `json:"schema_version"`
	Image         string   `json:"image"`
	Address       string   `json:"address"`
	Name          string   `json:"name"`
	Subsystem     string   `json:"subsystem"`
	Score         int      `json:"score"`
	CSource       string   `json:"c_source"`
	CompileStatus string   `json:"compile_status"`
	RealCallees   []string `json:"real_callees"`
	Reasons       []string `json:"reasons"`
}

type diffRange struct {
	Start       string `json:"start"`
	End         string `json:"end"`
	Length      int    `json:"length"`
	Kind        string `json:"kind"`
	OriginalHex string `json:"original_hex,omitempty"`
	RebuiltHex  string `json:"rebuilt_hex,omitempty"`
}

type imageDiffReport struct {
	SchemaVersion        string      `json:"schema_version"`
	GeneratedAt          string      `json:"generated_at"`
	Image                string      `json:"image"`
	Status               string      `json:"status"`
	OriginalSize         int         `json:"original_size"`
	RebuiltSize          int         `json:"rebuilt_size"`
	ComparedSize         int         `json:"compared_size"`
	EqualBytes           int         `json:"equal_bytes"`
	DifferentBytes       int         `json:"different_bytes"`
	SizeDeltaBytes       int         `json:"size_delta_bytes"`
	FirstDifference      string      `json:"first_difference,omitempty"`
	HeaderEqual          bool        `json:"header_equal"`
	HeaderDiffBytes      int         `json:"header_diff_bytes"`
	PromotedCDiffBytes   int         `json:"promoted_c_diff_bytes"`
	NonPromotedDiffBytes int         `json:"non_promoted_diff_bytes"`
	RangeCount           int         `json:"range_count"`
	RangesSample         []diffRange `json:"ranges_sample"`
	Notes                []string    `json:"notes,omitempty"`
}

type cVerifyRecord struct {
	SchemaVersion   string `json:"schema_version"`
	GeneratedAt     string `json:"generated_at"`
	Image           string `json:"image"`
	Address         string `json:"address"`
	Name            string `json:"name"`
	Status          string `json:"status"`
	CSource         string `json:"c_source"`
	OriginalSize    int    `json:"original_size"`
	CompiledSize    int    `json:"compiled_size"`
	TextSize        int    `json:"text_size"`
	SymbolSize      int    `json:"symbol_size"`
	FirstDifference string `json:"first_difference,omitempty"`
	OriginalSHA256  string `json:"original_sha256,omitempty"`
	CompiledSHA256  string `json:"compiled_sha256,omitempty"`
	OriginalHex     string `json:"original_hex,omitempty"`
	CompiledHex     string `json:"compiled_hex,omitempty"`
	Error           string `json:"error,omitempty"`
}

func main() {
	if len(os.Args) < 2 {
		usage()
		os.Exit(2)
	}
	var err error
	switch os.Args[1] {
	case "ledger":
		err = runLedger(os.Args[2:])
	case "emit":
		err = runEmit(os.Args[2:])
	case "build":
		err = runBuild(os.Args[2:])
	case "link":
		err = runLink(os.Args[2:])
	case "package":
		err = runPackage(os.Args[2:])
	case "diff":
		err = runDiff(os.Args[2:])
	case "cverify":
		err = runCVerify(os.Args[2:])
	case "verify":
		err = runVerify(os.Args[2:])
	case "queue":
		err = runQueue(os.Args[2:])
	case "promote":
		err = runPromote(os.Args[2:])
	case "check":
		err = runCheck(os.Args[2:])
	case "report":
		err = runReport(os.Args[2:])
	case "all":
		err = runAll(os.Args[2:])
	case "-h", "--help", "help":
		usage()
		return
	default:
		fmt.Fprintf(os.Stderr, "fwhybrid: unknown command %q\n", os.Args[1])
		usage()
		os.Exit(2)
	}
	if err != nil {
		fmt.Fprintf(os.Stderr, "fwhybrid %s: %v\n", os.Args[1], err)
		os.Exit(1)
	}
}

func usage() {
	fmt.Fprint(os.Stderr, `fwhybrid - v26 hybrid firmware rebuild pipeline

Usage:
  fwhybrid <command> [flags]

Commands:
  ledger   build harness_v26/ledger/functions.jsonl
  emit     emit per-image hybrid.c from the ledger
  build    compile emitted C if an ARM compiler is available
  link     link hybrid.o at 0x100 and objcopy flat binaries
  package  wrap linked code with original firmware header
  diff     compare packaged firmware against original firmware bytes
  cverify  compile and byte-compare c_candidate functions
  verify   verify ledger/source bytes against raw firmware
  queue    rank low-risk C promotion candidates
  promote  mark top queued functions as c_candidate
  check    syntax-check emitted hybrid C with host GCC
  report   summarize v26 state
  all      run ledger, emit, build, verify, report

Common flags:
  --root <path>   workspace root (default .)
  --v25 <path>    v25 output dir (default <root>/harness_v25/out)
  --out <path>    v26 output dir (default <root>/harness_v26)
`)
}

func runAll(args []string) error {
	steps := []struct {
		name string
		fn   func([]string) error
	}{
		{"ledger", runLedger},
		{"verify", runVerify},
		{"emit", runEmit},
		{"build", runBuild},
		{"link", runLink},
		{"package", runPackage},
		{"diff", runDiff},
		{"queue", runQueue},
		{"check", runCheck},
		{"report", runReport},
	}
	for _, step := range steps {
		fmt.Printf("==> %s\n", step.name)
		if err := step.fn(args); err != nil {
			return err
		}
	}
	return nil
}

func runLedger(args []string) error {
	fs := flag.NewFlagSet("ledger", flag.ContinueOnError)
	var cf commonFlags
	cf.register(fs)
	if err := fs.Parse(args); err != nil {
		return err
	}
	if err := cf.resolve(); err != nil {
		return err
	}

	idx, indexPath, err := loadIndex(cf.V25)
	if err != nil {
		return err
	}
	byImage := map[string][]indexFunc{}
	for _, fn := range idx.Functions {
		byImage[fn.Image] = append(byImage[fn.Image], fn)
	}
	images := append([]string(nil), idx.Images...)
	if len(images) == 0 {
		for img := range byImage {
			images = append(images, img)
		}
	}
	sort.Strings(images)

	sizeHints := loadSizeHints(filepath.Join(cf.Root, "harness_v19", "decompiled"))
	var rows []ledgerRecord
	var summaries []imageSummary
	for _, img := range images {
		funcs := dedupeAndSort(byImage[img])
		raw, err := loadFirmware(cf.Root, img)
		if err != nil {
			return err
		}
		imageRows := make([]ledgerRecord, 0, len(funcs))
		for i, fn := range funcs {
			size, reasons := functionSize(fn, i, funcs, raw, sizeHints[img])
			rec := ledgerRecord{
				SchemaVersion: schemaVersion,
				Image:         img,
				Address:       fmt.Sprintf("0x%06x", fn.Address),
				Name:          safeSymbol(fn.Name, fn.Address),
				Size:          size,
				Mode:          "asm_exact",
				SourceKind:    "raw_firmware",
				CompileStatus: "not_attempted",
				VerifyStatus:  "not_attempted",
				Subsystem:     fn.Subsystem,
				Cluster:       fn.Cluster,
				NCallers:      fn.NCallers,
				NCallees:      fn.NCallees,
				NAccesses:     fn.NAccesses,
				NLiterals:     fn.NLiterals,
				Reasons:       reasons,
			}
			body, err := rawBytesFor(rec, raw)
			if err != nil {
				rec.Mode = "blocked"
				rec.SourceKind = "missing"
				rec.CompileStatus = "not_applicable"
				rec.VerifyStatus = "fails"
				rec.Reasons = append(rec.Reasons, err.Error())
			} else {
				sum := sha256.Sum256(body)
				rec.ByteSHA256 = hex.EncodeToString(sum[:])
			}
			imageRows = append(imageRows, rec)
		}
		rows = append(rows, imageRows...)
		summaries = append(summaries, summarize(img, imageRows))
	}

	ledgerDir := filepath.Join(cf.Out, "ledger")
	if err := fileio.WriteJSONL(filepath.Join(ledgerDir, "functions.jsonl"), rows); err != nil {
		return err
	}
	man := manifest{
		SchemaVersion: schemaVersion,
		GeneratedAt:   time.Now().UTC().Format(time.RFC3339),
		InputIndex:    indexPath,
		Total:         len(rows),
		Images:        summaries,
	}
	if err := fileio.WriteJSON(filepath.Join(ledgerDir, "manifest.json"), man); err != nil {
		return err
	}
	fmt.Printf("ledger: %d functions -> %s\n", len(rows), ledgerDir)
	return nil
}

func runEmit(args []string) error {
	fs := flag.NewFlagSet("emit", flag.ContinueOnError)
	var cf commonFlags
	cf.register(fs)
	if err := fs.Parse(args); err != nil {
		return err
	}
	if err := cf.resolve(); err != nil {
		return err
	}
	rows, err := loadLedger(cf.Out)
	if err != nil {
		return err
	}
	byImage := groupLedger(rows)
	for img, recs := range byImage {
		raw, err := loadFirmware(cf.Root, img)
		if err != nil {
			return err
		}
		sortLedger(recs)
		source, err := emitSource(img, recs, raw)
		if err != nil {
			return err
		}
		outPath := filepath.Join(cf.Out, "out", img, "hybrid.c")
		if err := fileio.WriteBytes(outPath, []byte(source)); err != nil {
			return err
		}
		fmt.Printf("emit: %s -> %s\n", img, outPath)
	}
	return nil
}

func runBuild(args []string) error {
	fs := flag.NewFlagSet("build", flag.ContinueOnError)
	var cf commonFlags
	var compiler string
	cf.register(fs)
	fs.StringVar(&compiler, "cc", "", "ARM C compiler override")
	if err := fs.Parse(args); err != nil {
		return err
	}
	if err := cf.resolve(); err != nil {
		return err
	}
	rows, err := loadLedger(cf.Out)
	if err != nil {
		return err
	}
	if compiler == "" {
		compiler = findTool("arm-none-eabi-gcc", "arm-linux-gnueabihf-gcc")
	}
	rep := buildReport{
		SchemaVersion: schemaVersion,
		GeneratedAt:   time.Now().UTC().Format(time.RFC3339),
		Compiler:      compiler,
		Objcopy:       findTool("arm-none-eabi-objcopy", "arm-linux-gnueabihf-objcopy"),
		Images:        map[string]string{},
	}
	if compiler == "" {
		rep.Errors = append(rep.Errors, "no ARM compiler found on PATH")
		if err := fileio.WriteJSON(filepath.Join(cf.Out, "out", "build.json"), rep); err != nil {
			return err
		}
		fmt.Println("build: skipped (no ARM compiler found)")
		return nil
	}
	for img := range groupLedger(rows) {
		src := filepath.Join(cf.Out, "out", img, "hybrid.c")
		obj := filepath.Join(cf.Out, "out", img, "hybrid.o")
		cmd := exec.Command(compiler, "-c", "-O0", "-mthumb", "-mcpu=cortex-r5",
			"-ffreestanding", "-nostdlib", src, "-o", obj)
		out, err := cmd.CombinedOutput()
		if err != nil {
			rep.Images[img] = "fails"
			rep.Errors = append(rep.Errors, fmt.Sprintf("%s: %v: %s", img, err, strings.TrimSpace(string(out))))
			continue
		}
		rep.Images[img] = "object_built"
	}
	if err := fileio.WriteJSON(filepath.Join(cf.Out, "out", "build.json"), rep); err != nil {
		return err
	}
	fmt.Printf("build: %d images, compiler=%s\n", len(rep.Images), compiler)
	return nil
}

func runLink(args []string) error {
	fs := flag.NewFlagSet("link", flag.ContinueOnError)
	var cf commonFlags
	cf.register(fs)
	if err := fs.Parse(args); err != nil {
		return err
	}
	if err := cf.resolve(); err != nil {
		return err
	}
	rows, err := loadLedger(cf.Out)
	if err != nil {
		return err
	}
	ld := findTool("arm-none-eabi-ld", "arm-linux-gnueabihf-ld")
	objcopy := findTool("arm-none-eabi-objcopy", "arm-linux-gnueabihf-objcopy")
	rep := map[string]any{
		"schema_version": schemaVersion,
		"generated_at":   time.Now().UTC().Format(time.RFC3339),
		"ld":             ld,
		"objcopy":        objcopy,
		"images":         map[string]string{},
	}
	results := rep["images"].(map[string]string)
	var errorsOut []string
	if ld == "" || objcopy == "" {
		if ld == "" {
			errorsOut = append(errorsOut, "no ARM ld found on PATH")
		}
		if objcopy == "" {
			errorsOut = append(errorsOut, "no ARM objcopy found on PATH")
		}
		rep["errors"] = errorsOut
		return fileio.WriteJSON(filepath.Join(cf.Out, "out", "link.json"), rep)
	}
	script := filepath.Join(cf.Out, "out", "linker.ld")
	if err := fileio.WriteBytes(script, []byte(linkerScript(collectAbsoluteSymbols(rows)))); err != nil {
		return err
	}
	for img := range groupLedger(rows) {
		dir := filepath.Join(cf.Out, "out", img)
		obj := filepath.Join(dir, "hybrid.o")
		elf := filepath.Join(dir, "hybrid.elf")
		bin := filepath.Join(dir, "hybrid.bin")
		_ = os.Remove(elf)
		_ = os.Remove(bin)
		if _, err := os.Stat(obj); err != nil {
			results[img] = "missing_object"
			errorsOut = append(errorsOut, img+": "+err.Error())
			continue
		}
		cmd := exec.Command(ld, "-T", script, "-nostdlib", "-o", elf, obj)
		out, err := cmd.CombinedOutput()
		if err != nil {
			results[img] = "link_fails"
			errorsOut = append(errorsOut, fmt.Sprintf("%s link: %v: %s", img, err, strings.TrimSpace(string(out))))
			continue
		}
		cmd = exec.Command(objcopy, "-O", "binary", elf, bin)
		out, err = cmd.CombinedOutput()
		if err != nil {
			results[img] = "objcopy_fails"
			errorsOut = append(errorsOut, fmt.Sprintf("%s objcopy: %v: %s", img, err, strings.TrimSpace(string(out))))
			continue
		}
		results[img] = "linked"
	}
	if len(errorsOut) > 0 {
		rep["errors"] = errorsOut
	}
	if err := fileio.WriteJSON(filepath.Join(cf.Out, "out", "link.json"), rep); err != nil {
		return err
	}
	fmt.Printf("link: %d images\n", len(results))
	return nil
}

func runPackage(args []string) error {
	fs := flag.NewFlagSet("package", flag.ContinueOnError)
	var cf commonFlags
	cf.register(fs)
	if err := fs.Parse(args); err != nil {
		return err
	}
	if err := cf.resolve(); err != nil {
		return err
	}
	rows, err := loadLedger(cf.Out)
	if err != nil {
		return err
	}
	rep := map[string]any{
		"schema_version": schemaVersion,
		"generated_at":   time.Now().UTC().Format(time.RFC3339),
		"images":         map[string]map[string]any{},
	}
	images := rep["images"].(map[string]map[string]any)
	var errorsOut []string
	for img := range groupLedger(rows) {
		raw, err := loadFirmware(cf.Root, img)
		if err != nil {
			errorsOut = append(errorsOut, img+": "+err.Error())
			continue
		}
		codePath := filepath.Join(cf.Out, "out", img, "hybrid.bin")
		code, err := os.ReadFile(codePath)
		if err != nil {
			errorsOut = append(errorsOut, img+": "+err.Error())
			continue
		}
		out := make([]byte, len(raw))
		headerLen := 0x100
		if len(raw) < headerLen {
			headerLen = len(raw)
		}
		copy(out, raw[:headerLen])
		if len(out) > 0x100 {
			copy(out[0x100:], code)
		}
		outPath := filepath.Join(cf.Out, "out", img, "hybrid_firmware.bin")
		if err := fileio.WriteBytes(outPath, out); err != nil {
			return err
		}
		images[img] = map[string]any{
			"status":        "packaged",
			"raw_size":      len(raw),
			"code_size":     len(code),
			"packaged_size": len(out),
			"output":        outPath,
		}
	}
	if len(errorsOut) > 0 {
		rep["errors"] = errorsOut
	}
	if err := fileio.WriteJSON(filepath.Join(cf.Out, "out", "package.json"), rep); err != nil {
		return err
	}
	fmt.Printf("package: %d images\n", len(images))
	return nil
}

func runDiff(args []string) error {
	fs := flag.NewFlagSet("diff", flag.ContinueOnError)
	var cf commonFlags
	var sampleLimit int
	cf.register(fs)
	fs.IntVar(&sampleLimit, "sample-ranges", 64, "maximum diff ranges to include per image")
	if err := fs.Parse(args); err != nil {
		return err
	}
	if err := cf.resolve(); err != nil {
		return err
	}
	rows, err := loadLedger(cf.Out)
	if err != nil {
		return err
	}
	byImage := groupLedger(rows)
	aggregate := map[string]any{
		"schema_version": schemaVersion,
		"generated_at":   time.Now().UTC().Format(time.RFC3339),
		"images":         map[string]imageDiffReport{},
	}
	images := aggregate["images"].(map[string]imageDiffReport)
	totalCompared := 0
	totalEqual := 0
	totalDiff := 0
	totalSizeDelta := 0
	byteIdentical := 0
	var names []string
	for img := range byImage {
		names = append(names, img)
	}
	sort.Strings(names)
	for _, img := range names {
		raw, err := loadFirmware(cf.Root, img)
		if err != nil {
			return err
		}
		rebuiltPath := filepath.Join(cf.Out, "out", img, "hybrid_firmware.bin")
		rebuilt, err := os.ReadFile(rebuiltPath)
		if err != nil {
			return fmt.Errorf("read rebuilt firmware for %s: %w; run `bin/fwhybrid package` first", img, err)
		}
		rep := compareFirmware(img, raw, rebuilt, byImage[img], sampleLimit)
		if err := fileio.WriteJSON(filepath.Join(cf.Out, "out", img, "diff.json"), rep); err != nil {
			return err
		}
		images[img] = rep
		totalCompared += rep.ComparedSize
		totalEqual += rep.EqualBytes
		totalDiff += rep.DifferentBytes
		totalSizeDelta += absInt(rep.SizeDeltaBytes)
		if rep.Status == "byte_identical" {
			byteIdentical++
		}
	}
	aggregate["total_images"] = len(images)
	aggregate["byte_identical_images"] = byteIdentical
	aggregate["different_images"] = len(images) - byteIdentical
	aggregate["compared_bytes"] = totalCompared
	aggregate["equal_bytes"] = totalEqual
	aggregate["different_bytes"] = totalDiff
	aggregate["absolute_size_delta_bytes"] = totalSizeDelta
	if err := fileio.WriteJSON(filepath.Join(cf.Out, "out", "diff.json"), aggregate); err != nil {
		return err
	}
	fmt.Printf("diff: images=%d byte_identical=%d different=%d diff_bytes=%d\n",
		len(images), byteIdentical, len(images)-byteIdentical, totalDiff)
	return nil
}

func compareFirmware(image string, original, rebuilt []byte, recs []ledgerRecord, sampleLimit int) imageDiffReport {
	now := time.Now().UTC().Format(time.RFC3339)
	limit := minInt(len(original), len(rebuilt))
	ranges := findDiffRanges(original, rebuilt, sampleLimit)
	if ranges == nil {
		ranges = []diffRange{}
	}
	diffBytes := 0
	headerDiffBytes := 0
	promotedDiffBytes := 0
	mask := promotedCMask(len(original), recs)
	first := ""
	for i := 0; i < limit; i++ {
		if original[i] == rebuilt[i] {
			continue
		}
		if first == "" {
			first = fmt.Sprintf("0x%06x", i)
		}
		diffBytes++
		if i < 0x100 {
			headerDiffBytes++
		}
		if i < len(mask) && mask[i] {
			promotedDiffBytes++
		}
	}
	sizeDelta := len(rebuilt) - len(original)
	status := "different"
	if diffBytes == 0 && sizeDelta == 0 {
		status = "byte_identical"
	}
	if first == "" && sizeDelta != 0 {
		first = fmt.Sprintf("size_delta:%+d", sizeDelta)
	}
	notes := []string{}
	if diffBytes > promotedDiffBytes {
		notes = append(notes, "non_promoted_diffs_indicate_layout_or_asm_mismatch")
	}
	if sizeDelta != 0 {
		notes = append(notes, "rebuilt_size_differs_from_original")
	}
	headerEqual := true
	headerLimit := minInt(0x100, limit)
	for i := 0; i < headerLimit; i++ {
		if original[i] != rebuilt[i] {
			headerEqual = false
			break
		}
	}
	if len(original) < 0x100 || len(rebuilt) < 0x100 {
		headerEqual = false
	}
	return imageDiffReport{
		SchemaVersion:        schemaVersion,
		GeneratedAt:          now,
		Image:                image,
		Status:               status,
		OriginalSize:         len(original),
		RebuiltSize:          len(rebuilt),
		ComparedSize:         limit,
		EqualBytes:           limit - diffBytes,
		DifferentBytes:       diffBytes,
		SizeDeltaBytes:       sizeDelta,
		FirstDifference:      first,
		HeaderEqual:          headerEqual,
		HeaderDiffBytes:      headerDiffBytes,
		PromotedCDiffBytes:   promotedDiffBytes,
		NonPromotedDiffBytes: diffBytes - promotedDiffBytes,
		RangeCount:           countDiffRanges(original, rebuilt),
		RangesSample:         ranges,
		Notes:                notes,
	}
}

func runCVerify(args []string) error {
	fs := flag.NewFlagSet("cverify", flag.ContinueOnError)
	var cf commonFlags
	var compiler string
	var limit int
	var updateLedger bool
	cf.register(fs)
	fs.StringVar(&compiler, "cc", "", "ARM C compiler override")
	fs.IntVar(&limit, "limit", 0, "maximum candidate/verified rows to verify; 0 means all")
	fs.BoolVar(&updateLedger, "update-ledger", false, "mark exact matches as c_verified in the ledger")
	if err := fs.Parse(args); err != nil {
		return err
	}
	if err := cf.resolve(); err != nil {
		return err
	}
	rows, err := loadLedger(cf.Out)
	if err != nil {
		return err
	}
	if compiler == "" {
		compiler = findTool("arm-none-eabi-gcc", "arm-linux-gnueabihf-gcc")
	}
	objcopy := findTool("arm-none-eabi-objcopy", "arm-linux-gnueabihf-objcopy")
	if compiler == "" || objcopy == "" {
		return errors.New("cverify requires arm-none-eabi-gcc and arm-none-eabi-objcopy on PATH")
	}
	scratch := filepath.Join(cf.Out, "out", "cverify")
	if err := os.MkdirAll(scratch, 0o755); err != nil {
		return err
	}
	now := time.Now().UTC().Format(time.RFC3339)
	var reports []cVerifyRecord
	verified := map[string]bool{}
	attempted := 0
	for _, rec := range rows {
		if rec.Mode != "c_candidate" && rec.Mode != "c_verified" {
			continue
		}
		if limit > 0 && attempted >= limit {
			break
		}
		attempted++
		raw, err := loadFirmware(cf.Root, rec.Image)
		if err != nil {
			return err
		}
		orig, err := rawBytesFor(rec, raw)
		if err != nil {
			return err
		}
		rep := verifyCandidateC(cf, compiler, objcopy, scratch, rec, raw, orig, now)
		reports = append(reports, rep)
		if rep.Status == "byte_exact" {
			verified[rec.Image+"|"+rec.Address] = true
		}
	}
	if updateLedger && len(verified) > 0 {
		for i := range rows {
			key := rows[i].Image + "|" + rows[i].Address
			if !verified[key] {
				continue
			}
			rows[i].Mode = "c_verified"
			rows[i].VerifyStatus = "c_byte_exact"
			rows[i].CompileStatus = "c_byte_exact"
			rows[i].Reasons = appendUnique(rows[i].Reasons, "cverify_byte_exact")
		}
		if err := fileio.WriteJSONL(filepath.Join(cf.Out, "ledger", "functions.jsonl"), rows); err != nil {
			return err
		}
	}
	outDir := filepath.Join(cf.Out, "cverify")
	if err := fileio.WriteJSONL(filepath.Join(outDir, "results.jsonl"), reports); err != nil {
		return err
	}
	exact := 0
	for _, rep := range reports {
		if rep.Status == "byte_exact" {
			exact++
		}
	}
	summary := map[string]any{
		"schema_version":          schemaVersion,
		"generated_at":            now,
		"compiler":                compiler,
		"objcopy":                 objcopy,
		"attempted":               len(reports),
		"byte_exact":              exact,
		"failed":                  len(reports) - exact,
		"updated_ledger":          updateLedger && len(verified) > 0,
		"update_ledger_requested": updateLedger,
	}
	if err := fileio.WriteJSON(filepath.Join(outDir, "summary.json"), summary); err != nil {
		return err
	}
	fmt.Printf("cverify: attempted=%d byte_exact=%d failed=%d\n", len(reports), exact, len(reports)-exact)
	return nil
}

func verifyCandidateC(cf commonFlags, compiler, objcopy, scratch string, rec ledgerRecord, raw []byte, original []byte, now string) cVerifyRecord {
	rep := cVerifyRecord{
		SchemaVersion: schemaVersion,
		GeneratedAt:   now,
		Image:         rec.Image,
		Address:       rec.Address,
		Name:          rec.Name,
		Status:        "fails",
		CSource:       rec.CSource,
		OriginalSize:  len(original),
		OriginalHex:   hex.EncodeToString(original[:minInt(len(original), 32)]),
	}
	origSum := sha256.Sum256(original)
	rep.OriginalSHA256 = hex.EncodeToString(origSum[:])
	if rec.CSource == "" {
		rep.Error = "missing c_source"
		return rep
	}
	addr, err := parseAddr(rec.Address)
	if err != nil {
		rep.Error = err.Error()
		return rep
	}
	symbol := safeSymbol(rec.Name, addr)
	workBase := fmt.Sprintf("%s_%06x_%s", rec.Image, addr, symbol)
	srcPath := filepath.Join(scratch, workBase+".c")
	objPath := filepath.Join(scratch, workBase+".o")
	elfPath := filepath.Join(scratch, workBase+".elf")
	binPath := filepath.Join(scratch, workBase+".bin")
	sectionPath := filepath.Join(scratch, workBase+".text.bin")
	src, err := cVerifySource(rec, symbol, raw)
	if err != nil {
		rep.Error = err.Error()
		return rep
	}
	if err := fileio.WriteBytes(srcPath, []byte(src)); err != nil {
		rep.Error = err.Error()
		return rep
	}
	cmd := exec.Command(compiler, "-c", "-Os", "-mthumb", "-mcpu=cortex-r5",
		"-ffreestanding", "-fno-builtin", "-nostdlib", srcPath, "-o", objPath)
	if out, err := cmd.CombinedOutput(); err != nil {
		rep.Status = "compile_fails"
		rep.Error = strings.TrimSpace(string(out))
		return rep
	}
	ld := findTool("arm-none-eabi-ld", "arm-linux-gnueabihf-ld")
	if ld == "" {
		rep.Status = "link_fails"
		rep.Error = "no ARM ld found on PATH"
		return rep
	}
	scriptPath := filepath.Join(scratch, workBase+".ld")
	if err := fileio.WriteBytes(scriptPath, []byte(cVerifyLinkerScript(collectAbsoluteSymbols([]ledgerRecord{rec})))); err != nil {
		rep.Error = err.Error()
		return rep
	}
	cmd = exec.Command(ld, "-T", scriptPath, "-nostdlib", "-o", elfPath, objPath)
	if out, err := cmd.CombinedOutput(); err != nil {
		rep.Status = "link_fails"
		rep.Error = strings.TrimSpace(string(out))
		return rep
	}
	cmd = exec.Command(objcopy, "-O", "binary", elfPath, binPath)
	if out, err := cmd.CombinedOutput(); err != nil {
		rep.Status = "objcopy_fails"
		rep.Error = strings.TrimSpace(string(out))
		return rep
	}
	cmd = exec.Command(objcopy, "--dump-section", ".text="+sectionPath, elfPath)
	if out, err := cmd.CombinedOutput(); err != nil {
		rep.Status = "objcopy_fails"
		rep.Error = strings.TrimSpace(string(out))
		return rep
	}
	compiled, err := os.ReadFile(sectionPath)
	if err != nil {
		rep.Error = err.Error()
		return rep
	}
	rep.TextSize = len(compiled)
	symAddr, symSize := symbolInfo(elfPath, symbol)
	rep.SymbolSize = symSize
	if symSize <= 0 || symAddr < 0 || symAddr+symSize > len(compiled) {
		rep.Status = "symbol_missing"
		rep.Error = fmt.Sprintf("symbol %s size=%d addr=%d text_size=%d", symbol, symSize, symAddr, len(compiled))
		return rep
	}
	symbolBytes := compiled[symAddr : symAddr+symSize]
	rep.CompiledSize = len(symbolBytes)
	rep.CompiledHex = hex.EncodeToString(symbolBytes[:minInt(len(symbolBytes), 32)])
	compSum := sha256.Sum256(symbolBytes)
	rep.CompiledSHA256 = hex.EncodeToString(compSum[:])
	if string(symbolBytes) == string(original) {
		rep.Status = "byte_exact"
		return rep
	}
	rep.Status = "differs"
	rep.FirstDifference = firstByteDiff(original, symbolBytes)
	return rep
}

func cVerifySource(rec ledgerRecord, symbol string, raw []byte) (string, error) {
	src, err := cBodyForHybrid(rec, symbol)
	if err != nil {
		return "", err
	}
	var b strings.Builder
	b.WriteString("#include <stdint.h>\n")
	b.WriteString("#define BYTE1(x) ((uint8_t)(((uint32_t)(x) >> 8) & 0xFFu))\n")
	b.WriteString("#define BYTE2(x) ((uint8_t)(((uint32_t)(x) >> 16) & 0xFFu))\n")
	b.WriteString("#define BYTE3(x) ((uint8_t)(((uint32_t)(x) >> 24) & 0xFFu))\n")
	b.WriteString("#define __noreturn\n")
	b.WriteString("#define _VF 0\n")
	b.WriteString("#define _CF 0\n")
	b.WriteString(rewriteAbsoluteExterns(src, raw))
	return b.String(), nil
}

func rewriteAbsoluteExterns(src string, raw []byte) string {
	re := regexp.MustCompile(`(?m)^extern\s+uint32_t\s+((?:off|dword|byte|word|qword|algn|unk)_[0-9A-Fa-f]+);\s*$`)
	return re.ReplaceAllStringFunc(src, func(line string) string {
		m := re.FindStringSubmatch(line)
		if len(m) != 2 {
			return line
		}
		name := m[1]
		parts := strings.Split(name, "_")
		if len(parts) < 2 {
			return line
		}
		addr, err := strconv.ParseUint(parts[len(parts)-1], 16, 32)
		if err != nil {
			return line
		}
		value := uint32(addr)
		if addr >= uint64(chipBase) {
			off := int(uint32(addr) - chipBase)
			if off >= 0 && off+4 <= len(raw) {
				value = uint32(raw[off]) | uint32(raw[off+1])<<8 | uint32(raw[off+2])<<16 | uint32(raw[off+3])<<24
			}
		}
		return fmt.Sprintf("#define %s ((uint32_t)0x%08xu)", name, value)
	})
}

func cVerifyLinkerScript(symbols map[string]uint32) string {
	var b strings.Builder
	var names []string
	for name := range symbols {
		names = append(names, name)
	}
	sort.Strings(names)
	for _, name := range names {
		b.WriteString(fmt.Sprintf("PROVIDE(%s = 0x%08x);\n", name, symbols[name]))
	}
	b.WriteString(`SECTIONS
{
  . = 0;
  .text : ALIGN(2)
  {
    *(.text*)
    *(.rodata*)
  }
  /DISCARD/ :
  {
    *(.comment)
    *(.ARM.attributes)
    *(.note*)
  }
}
`)
	return b.String()
}

func symbolInfo(elfPath, symbol string) (int, int) {
	nm := findTool("arm-none-eabi-nm", "arm-linux-gnueabihf-nm")
	if nm == "" {
		return 0, 0
	}
	out, err := exec.Command(nm, "-S", "--size-sort", elfPath).Output()
	if err != nil {
		return 0, 0
	}
	for _, line := range strings.Split(string(out), "\n") {
		fields := strings.Fields(line)
		if len(fields) < 4 || fields[len(fields)-1] != symbol {
			continue
		}
		addr, err := strconv.ParseUint(fields[0], 16, 32)
		if err != nil {
			return 0, 0
		}
		size, err := strconv.ParseUint(fields[1], 16, 32)
		if err == nil {
			return int(addr), int(size)
		}
	}
	return 0, 0
}

func firstByteDiff(a, b []byte) string {
	limit := minInt(len(a), len(b))
	for i := 0; i < limit; i++ {
		if a[i] != b[i] {
			return fmt.Sprintf("0x%06x", i)
		}
	}
	if len(a) != len(b) {
		return fmt.Sprintf("size_delta:%+d", len(b)-len(a))
	}
	return ""
}

func appendUnique(in []string, v string) []string {
	for _, cur := range in {
		if cur == v {
			return in
		}
	}
	return append(in, v)
}

func findDiffRanges(original, rebuilt []byte, sampleLimit int) []diffRange {
	limit := minInt(len(original), len(rebuilt))
	var ranges []diffRange
	for i := 0; i < limit; {
		if original[i] == rebuilt[i] {
			i++
			continue
		}
		start := i
		for i < limit && original[i] != rebuilt[i] {
			i++
		}
		if sampleLimit <= 0 || len(ranges) < sampleLimit {
			ranges = append(ranges, makeDiffRange(start, i, original, rebuilt))
		}
	}
	if len(original) != len(rebuilt) && (sampleLimit <= 0 || len(ranges) < sampleLimit) {
		start := limit
		end := maxInt(len(original), len(rebuilt))
		ranges = append(ranges, diffRange{
			Start:  fmt.Sprintf("0x%06x", start),
			End:    fmt.Sprintf("0x%06x", end),
			Length: end - start,
			Kind:   "size_delta",
		})
	}
	return ranges
}

func countDiffRanges(original, rebuilt []byte) int {
	limit := minInt(len(original), len(rebuilt))
	count := 0
	for i := 0; i < limit; {
		if original[i] == rebuilt[i] {
			i++
			continue
		}
		count++
		for i < limit && original[i] != rebuilt[i] {
			i++
		}
	}
	if len(original) != len(rebuilt) {
		count++
	}
	return count
}

func makeDiffRange(start, end int, original, rebuilt []byte) diffRange {
	sampleEnd := minInt(end, start+16)
	return diffRange{
		Start:       fmt.Sprintf("0x%06x", start),
		End:         fmt.Sprintf("0x%06x", end),
		Length:      end - start,
		Kind:        diffKind(start, end),
		OriginalHex: hex.EncodeToString(original[start:sampleEnd]),
		RebuiltHex:  hex.EncodeToString(rebuilt[start:sampleEnd]),
	}
}

func diffKind(start, end int) string {
	if end <= 0x100 {
		return "header"
	}
	if start >= 0x100 {
		return "code"
	}
	return "header_and_code"
}

func promotedCMask(size int, recs []ledgerRecord) []bool {
	mask := make([]bool, size)
	for _, rec := range recs {
		if rec.Mode != "c_candidate" && rec.Mode != "c_verified" {
			continue
		}
		addr, err := parseAddr(rec.Address)
		if err != nil || addr < chipBase || rec.Size <= 0 {
			continue
		}
		start := int(addr - chipBase)
		end := start + rec.Size
		if start < 0 || start >= size {
			continue
		}
		if end > size {
			end = size
		}
		for i := start; i < end; i++ {
			mask[i] = true
		}
	}
	return mask
}

func linkerScript(symbols map[string]uint32) string {
	var b strings.Builder
	b.WriteString("ENTRY(start)\n")
	var names []string
	for name := range symbols {
		names = append(names, name)
	}
	sort.Strings(names)
	for _, name := range names {
		b.WriteString(fmt.Sprintf("PROVIDE(%s = 0x%08x);\n", name, symbols[name]))
	}
	b.WriteString(`SECTIONS
{
  . = 0x100;
  .text : ALIGN(2)
  {
    KEEP(*(.text.v26))
    *(.text*)
    *(.rodata*)
  }
  /DISCARD/ :
  {
    *(.comment)
    *(.ARM.attributes)
    *(.note*)
  }
}
`)
	return b.String()
}

func collectAbsoluteSymbols(rows []ledgerRecord) map[string]uint32 {
	out := map[string]uint32{}
	re := regexp.MustCompile(`\b(?:off|dword|byte|word|qword|algn|unk)_([0-9A-Fa-f]+)\b`)
	for _, row := range rows {
		if row.CSource == "" {
			continue
		}
		data, err := os.ReadFile(row.CSource)
		if err != nil {
			continue
		}
		for _, m := range re.FindAllStringSubmatch(string(data), -1) {
			if len(m) != 2 {
				continue
			}
			addr, err := strconv.ParseUint(m[1], 16, 32)
			if err != nil {
				continue
			}
			out[m[0]] = uint32(addr)
		}
	}
	return out
}

func runVerify(args []string) error {
	fs := flag.NewFlagSet("verify", flag.ContinueOnError)
	var cf commonFlags
	cf.register(fs)
	if err := fs.Parse(args); err != nil {
		return err
	}
	if err := cf.resolve(); err != nil {
		return err
	}
	rows, err := loadLedger(cf.Out)
	if err != nil {
		return err
	}
	byImage := groupLedger(rows)
	for img, recs := range byImage {
		raw, err := loadFirmware(cf.Root, img)
		if err != nil {
			return err
		}
		sortLedger(recs)
		passed := 0
		failed := 0
		for i := range recs {
			body, err := rawBytesFor(recs[i], raw)
			if err != nil {
				recs[i].VerifyStatus = "fails"
				failed++
				continue
			}
			sum := sha256.Sum256(body)
			if hex.EncodeToString(sum[:]) == recs[i].ByteSHA256 {
				recs[i].VerifyStatus = "byte_exact"
				passed++
			} else {
				recs[i].VerifyStatus = "fails"
				failed++
			}
		}
		rep := map[string]any{
			"schema_version": schemaVersion,
			"generated_at":   time.Now().UTC().Format(time.RFC3339),
			"image":          img,
			"byte_exact":     passed,
			"fails":          failed,
			"total":          len(recs),
		}
		if err := fileio.WriteJSON(filepath.Join(cf.Out, "out", img, "verify.json"), rep); err != nil {
			return err
		}
	}
	all := flatten(groupLedgerRows(byImage))
	if err := fileio.WriteJSONL(filepath.Join(cf.Out, "ledger", "functions.jsonl"), all); err != nil {
		return err
	}
	fmt.Printf("verify: %d images\n", len(byImage))
	return nil
}

func runQueue(args []string) error {
	fs := flag.NewFlagSet("queue", flag.ContinueOnError)
	var cf commonFlags
	var limit int
	cf.register(fs)
	fs.IntVar(&limit, "limit", 200, "maximum candidates to emit")
	if err := fs.Parse(args); err != nil {
		return err
	}
	if err := cf.resolve(); err != nil {
		return err
	}
	rows, err := loadLedger(cf.Out)
	if err != nil {
		return err
	}
	meta, err := loadFuncMeta(cf.V25)
	if err != nil {
		return err
	}
	var candidates []candidateRecord
	for _, rec := range rows {
		key := rec.Image + "|" + rec.Address
		m, ok := meta[key]
		if !ok {
			continue
		}
		cand, ok := rankCandidate(cf, rec, m)
		if ok {
			candidates = append(candidates, cand)
		}
	}
	sort.Slice(candidates, func(i, j int) bool {
		if candidates[i].Score == candidates[j].Score {
			if candidates[i].Image == candidates[j].Image {
				return candidates[i].Address < candidates[j].Address
			}
			return candidates[i].Image < candidates[j].Image
		}
		return candidates[i].Score > candidates[j].Score
	})
	if limit > 0 && len(candidates) > limit {
		candidates = candidates[:limit]
	}
	outPath := filepath.Join(cf.Out, "queue", "c_candidates.jsonl")
	if err := fileio.WriteJSONL(outPath, candidates); err != nil {
		return err
	}
	summary := map[string]any{
		"schema_version": schemaVersion,
		"generated_at":   time.Now().UTC().Format(time.RFC3339),
		"limit":          limit,
		"candidates":     len(candidates),
		"output":         outPath,
	}
	if err := fileio.WriteJSON(filepath.Join(cf.Out, "queue", "summary.json"), summary); err != nil {
		return err
	}
	fmt.Printf("queue: %d candidates -> %s\n", len(candidates), outPath)
	return nil
}

func runPromote(args []string) error {
	fs := flag.NewFlagSet("promote", flag.ContinueOnError)
	var cf commonFlags
	var limit int
	cf.register(fs)
	fs.IntVar(&limit, "limit", 10, "number of queued candidates to mark c_candidate")
	if err := fs.Parse(args); err != nil {
		return err
	}
	if err := cf.resolve(); err != nil {
		return err
	}
	rows, err := loadLedger(cf.Out)
	if err != nil {
		return err
	}
	queuePath := filepath.Join(cf.Out, "queue", "c_candidates.jsonl")
	candidates, err := fileio.ReadJSONL[candidateRecord](queuePath)
	if err != nil {
		return fmt.Errorf("read queue: %w; run `bin/fwhybrid queue` first", err)
	}
	if limit > 0 && len(candidates) > limit {
		candidates = candidates[:limit]
	}
	selected := map[string]candidateRecord{}
	for _, c := range candidates {
		selected[c.Image+"|"+c.Address] = c
	}
	promoted := 0
	for i := range rows {
		key := rows[i].Image + "|" + rows[i].Address
		c, ok := selected[key]
		if !ok {
			continue
		}
		rows[i].Mode = "c_candidate"
		rows[i].SourceKind = "v25_type_rewrite"
		rows[i].CompileStatus = c.CompileStatus
		rows[i].CSource = c.CSource
		rows[i].Reasons = append(rows[i].Reasons, "promoted_from_v26_queue")
		promoted++
	}
	if err := fileio.WriteJSONL(filepath.Join(cf.Out, "ledger", "functions.jsonl"), rows); err != nil {
		return err
	}
	rep := map[string]any{
		"schema_version": schemaVersion,
		"generated_at":   time.Now().UTC().Format(time.RFC3339),
		"requested":      limit,
		"promoted":       promoted,
	}
	if err := fileio.WriteJSON(filepath.Join(cf.Out, "queue", "promote.json"), rep); err != nil {
		return err
	}
	fmt.Printf("promote: %d c_candidate functions\n", promoted)
	return nil
}

func runCheck(args []string) error {
	fs := flag.NewFlagSet("check", flag.ContinueOnError)
	var cf commonFlags
	cf.register(fs)
	if err := fs.Parse(args); err != nil {
		return err
	}
	if err := cf.resolve(); err != nil {
		return err
	}
	rows, err := loadLedger(cf.Out)
	if err != nil {
		return err
	}
	results := map[string]string{}
	var errorsOut []string
	for img := range groupLedger(rows) {
		src := filepath.Join(cf.Out, "out", img, "hybrid.c")
		if _, err := os.Stat(src); err != nil {
			results[img] = "missing"
			errorsOut = append(errorsOut, img+": "+err.Error())
			continue
		}
		status := syntaxStatus(src)
		results[img] = status
		if status != "syntax_ok" {
			errorsOut = append(errorsOut, img+": "+status)
		}
	}
	rep := map[string]any{
		"schema_version": schemaVersion,
		"generated_at":   time.Now().UTC().Format(time.RFC3339),
		"results":        results,
	}
	if len(errorsOut) > 0 {
		rep["errors"] = errorsOut
	}
	if err := fileio.WriteJSON(filepath.Join(cf.Out, "out", "check.json"), rep); err != nil {
		return err
	}
	fmt.Printf("check: %d images\n", len(results))
	return nil
}

func runReport(args []string) error {
	fs := flag.NewFlagSet("report", flag.ContinueOnError)
	var cf commonFlags
	cf.register(fs)
	if err := fs.Parse(args); err != nil {
		return err
	}
	if err := cf.resolve(); err != nil {
		return err
	}
	rows, err := loadLedger(cf.Out)
	if err != nil {
		return err
	}
	var summaries []imageSummary
	for img, recs := range groupLedger(rows) {
		summaries = append(summaries, summarize(img, recs))
	}
	sort.Slice(summaries, func(i, j int) bool { return summaries[i].Image < summaries[j].Image })
	man := manifest{
		SchemaVersion: schemaVersion,
		GeneratedAt:   time.Now().UTC().Format(time.RFC3339),
		Total:         len(rows),
		Images:        summaries,
	}
	if err := fileio.WriteJSON(filepath.Join(cf.Out, "report.json"), man); err != nil {
		return err
	}
	fmt.Printf("fwhybrid report (out=%s):\n", cf.Out)
	for _, s := range summaries {
		fmt.Printf("  %-32s funcs=%-5d asm=%-5d c_candidate=%-4d c_verified=%-4d blocked=%-4d bytes=%d\n",
			s.Image, s.Total, s.AsmExact, s.Candidates, s.CVerified, s.Blocked, s.TotalBytes)
	}
	return nil
}

func loadFuncMeta(v25 string) (map[string]funcMeta, error) {
	paths, err := filepath.Glob(filepath.Join(v25, "*_funcs.jsonl"))
	if err != nil {
		return nil, err
	}
	out := map[string]funcMeta{}
	for _, path := range paths {
		rows, err := fileio.ReadJSONL[funcMeta](path)
		if err != nil {
			return nil, err
		}
		for _, row := range rows {
			if row.Image == "" {
				row.Image = strings.TrimSuffix(filepath.Base(path), "_funcs.jsonl")
			}
			key := row.Image + "|" + fmt.Sprintf("0x%06x", row.Address)
			cur, ok := out[key]
			if !ok || preferMeta(row, cur) {
				out[key] = row
			}
		}
	}
	return out, nil
}

func preferMeta(a, b funcMeta) bool {
	aNamed := !strings.HasPrefix(a.Name, "sub_")
	bNamed := !strings.HasPrefix(b.Name, "sub_")
	if aNamed != bNamed {
		return aNamed
	}
	return a.NLines > b.NLines
}

func rankCandidate(cf commonFlags, rec ledgerRecord, meta funcMeta) (candidateRecord, bool) {
	if rec.Mode != "asm_exact" || rec.VerifyStatus != "byte_exact" {
		return candidateRecord{}, false
	}
	if rec.Size <= 0 || rec.Size > 128 {
		return candidateRecord{}, false
	}
	if meta.NLines <= 0 || meta.NLines > 40 {
		return candidateRecord{}, false
	}
	if len(meta.Accesses) > 0 {
		return candidateRecord{}, false
	}
	realCallees := realCallees(meta.Callees, meta.Name)
	if len(realCallees) > 2 {
		return candidateRecord{}, false
	}
	cPath := findTypedC(cf.V25, rec.Image, rec.Address, rec.Name)
	if cPath == "" {
		return candidateRecord{}, false
	}
	compileStatus := syntaxStatus(cPath)
	if compileStatus != "syntax_ok" {
		return candidateRecord{}, false
	}
	score := 1000
	score -= rec.Size
	score -= meta.NLines * 4
	score -= len(realCallees) * 80
	score -= len(meta.Literals) * 3
	if rec.Subsystem == "util" {
		score += 120
	}
	if !strings.HasPrefix(rec.Name, "sub_") {
		score += 80
	}
	reasons := []string{
		"byte_exact_baseline",
		"v25_typed_c_syntax_ok",
		"no_v25_accesses",
		"small_function",
	}
	if len(realCallees) == 0 {
		reasons = append(reasons, "leaf_after_noise_filter")
	}
	return candidateRecord{
		SchemaVersion: schemaVersion,
		Image:         rec.Image,
		Address:       rec.Address,
		Name:          rec.Name,
		Subsystem:     rec.Subsystem,
		Score:         score,
		CSource:       cPath,
		CompileStatus: compileStatus,
		RealCallees:   realCallees,
		Reasons:       reasons,
	}, true
}

func realCallees(callees []string, self string) []string {
	seen := map[string]bool{}
	var out []string
	for _, c := range callees {
		c = strings.TrimSpace(c)
		if c == "" || c == self {
			continue
		}
		if strings.HasPrefix(c, "while") || strings.HasPrefix(c, "return") ||
			strings.HasPrefix(c, "if") || strings.HasPrefix(c, "for") ||
			strings.HasPrefix(c, "switch") {
			continue
		}
		if seen[c] {
			continue
		}
		seen[c] = true
		out = append(out, c)
	}
	sort.Strings(out)
	return out
}

func findTypedC(v25, image, address, name string) string {
	addr, err := parseAddr(address)
	if err != nil {
		return ""
	}
	dir := filepath.Join(v25, image+"_types")
	pattern := filepath.Join(dir, fmt.Sprintf("%06x_*.c", addr))
	matches, _ := filepath.Glob(pattern)
	if len(matches) == 0 {
		pattern = filepath.Join(dir, fmt.Sprintf("%x_*.c", addr))
		matches, _ = filepath.Glob(pattern)
	}
	if len(matches) == 0 {
		return ""
	}
	sort.Slice(matches, func(i, j int) bool {
		ibase := filepath.Base(matches[i])
		jbase := filepath.Base(matches[j])
		iname := strings.Contains(ibase, name)
		jname := strings.Contains(jbase, name)
		if iname != jname {
			return iname
		}
		isub := strings.Contains(ibase, "_sub_")
		jsub := strings.Contains(jbase, "_sub_")
		if isub != jsub {
			return !isub
		}
		return ibase < jbase
	})
	return matches[0]
}

func syntaxStatus(path string) string {
	if _, err := exec.LookPath("gcc"); err != nil {
		return "not_attempted"
	}
	cmd := exec.Command("gcc", "-std=gnu89", "-fsyntax-only", "-w", path)
	if err := cmd.Run(); err != nil {
		return "fails"
	}
	return "syntax_ok"
}

func loadIndex(v25 string) (*indexFile, string, error) {
	path := filepath.Join(v25, "function_index.json")
	data, err := os.ReadFile(path)
	if err != nil {
		return nil, "", fmt.Errorf("read index: %w; run `bin/fwstruct index` first", err)
	}
	var idx indexFile
	if err := json.Unmarshal(data, &idx); err != nil {
		return nil, "", err
	}
	if len(idx.Functions) == 0 {
		return nil, "", errors.New("function_index.json has no functions")
	}
	return &idx, path, nil
}

func loadFirmware(root, image string) ([]byte, error) {
	name, ok := imageToFirmware[image]
	if !ok {
		return nil, fmt.Errorf("no firmware mapping for %s", image)
	}
	return os.ReadFile(filepath.Join(root, "inputs", "firmware", name))
}

func dedupeAndSort(in []indexFunc) []indexFunc {
	seen := map[uint32]indexFunc{}
	for _, fn := range in {
		cur, ok := seen[fn.Address]
		if !ok || prefer(fn, cur) {
			seen[fn.Address] = fn
		}
	}
	out := make([]indexFunc, 0, len(seen))
	for _, fn := range seen {
		out = append(out, fn)
	}
	sort.Slice(out, func(i, j int) bool { return out[i].Address < out[j].Address })
	return out
}

func prefer(a, b indexFunc) bool {
	aNamed := !strings.HasPrefix(a.Name, "sub_")
	bNamed := !strings.HasPrefix(b.Name, "sub_")
	if aNamed != bNamed {
		return aNamed
	}
	if a.NAccesses != b.NAccesses {
		return a.NAccesses > b.NAccesses
	}
	return a.NLines > b.NLines
}

func loadSizeHints(decompiledRoot string) map[string]map[uint32]int {
	out := map[string]map[uint32]int{}
	re := regexp.MustCompile(`@\s+0x([0-9a-fA-F]+),\s+size\s+(\d+)\s+bytes`)
	_ = filepath.WalkDir(decompiledRoot, func(path string, d os.DirEntry, err error) error {
		if err != nil || d.IsDir() || !strings.HasSuffix(path, ".c") {
			return nil
		}
		img := filepath.Base(filepath.Dir(path))
		f, err := os.Open(path)
		if err != nil {
			return nil
		}
		defer f.Close()
		s := bufio.NewScanner(f)
		for i := 0; i < 4 && s.Scan(); i++ {
			m := re.FindStringSubmatch(s.Text())
			if len(m) != 3 {
				continue
			}
			addr64, _ := strconv.ParseUint(m[1], 16, 32)
			size, _ := strconv.Atoi(m[2])
			if out[img] == nil {
				out[img] = map[uint32]int{}
			}
			if size > out[img][uint32(addr64)] {
				out[img][uint32(addr64)] = size
			}
			break
		}
		return nil
	})
	return out
}

func functionSize(fn indexFunc, i int, funcs []indexFunc, raw []byte, hints map[uint32]int) (int, []string) {
	var reasons []string
	maxSize := int(uint32(len(raw)) - (fn.Address - chipBase))
	if fn.Address < chipBase || maxSize <= 0 {
		return 0, []string{"address_outside_firmware"}
	}
	if hint := hints[fn.Address]; hint > 0 && hint <= maxSize {
		reasons = append(reasons, "size_from_v19_comment")
		return hint, reasons
	}
	if i+1 < len(funcs) && funcs[i+1].Address > fn.Address {
		size := int(funcs[i+1].Address - fn.Address)
		if size <= maxSize {
			reasons = append(reasons, "size_from_next_function")
			return size, reasons
		}
	}
	reasons = append(reasons, "size_to_end_of_firmware")
	return maxSize, reasons
}

func rawBytesFor(rec ledgerRecord, raw []byte) ([]byte, error) {
	addr, err := parseAddr(rec.Address)
	if err != nil {
		return nil, err
	}
	if addr < chipBase {
		return nil, fmt.Errorf("address below chip base: %s", rec.Address)
	}
	start := int(addr - chipBase)
	end := start + rec.Size
	if start < 0 || end > len(raw) || rec.Size <= 0 {
		return nil, fmt.Errorf("invalid byte range: %s size=%d", rec.Address, rec.Size)
	}
	return raw[start:end], nil
}

func parseAddr(s string) (uint32, error) {
	u, err := strconv.ParseUint(strings.TrimPrefix(s, "0x"), 16, 32)
	return uint32(u), err
}

func safeSymbol(name string, addr uint32) string {
	name = strings.TrimSpace(name)
	if name == "" {
		name = fmt.Sprintf("sub_%06x", addr)
	}
	if '0' <= name[0] && name[0] <= '9' {
		return fmt.Sprintf("sub_%06x", addr)
	}
	var b strings.Builder
	for i, r := range name {
		ok := r == '_' || ('a' <= r && r <= 'z') || ('A' <= r && r <= 'Z') || (i > 0 && '0' <= r && r <= '9')
		if ok {
			b.WriteRune(r)
		} else {
			b.WriteByte('_')
		}
	}
	out := b.String()
	if out == "" || ('0' <= out[0] && out[0] <= '9') {
		out = fmt.Sprintf("sub_%06x", addr)
	}
	return out
}

func loadLedger(out string) ([]ledgerRecord, error) {
	return fileio.ReadJSONL[ledgerRecord](filepath.Join(out, "ledger", "functions.jsonl"))
}

func groupLedger(rows []ledgerRecord) map[string][]ledgerRecord {
	out := map[string][]ledgerRecord{}
	for _, r := range rows {
		out[r.Image] = append(out[r.Image], r)
	}
	return out
}

func groupLedgerRows(in map[string][]ledgerRecord) [][]ledgerRecord {
	var keys []string
	for k := range in {
		keys = append(keys, k)
	}
	sort.Strings(keys)
	out := make([][]ledgerRecord, 0, len(keys))
	for _, k := range keys {
		sortLedger(in[k])
		out = append(out, in[k])
	}
	return out
}

func flatten(groups [][]ledgerRecord) []ledgerRecord {
	var out []ledgerRecord
	for _, g := range groups {
		out = append(out, g...)
	}
	return out
}

func sortLedger(rows []ledgerRecord) {
	sort.Slice(rows, func(i, j int) bool {
		ai, _ := parseAddr(rows[i].Address)
		aj, _ := parseAddr(rows[j].Address)
		return ai < aj
	})
}

func emitSource(image string, recs []ledgerRecord, raw []byte) (string, error) {
	used := map[string]int{}
	var b strings.Builder
	b.WriteString("/* v26 hybrid reconstruction */\n")
	b.WriteString("/* image: " + image + " */\n")
	b.WriteString("/* generated by fwhybrid emit */\n")
	b.WriteString("#include <stdint.h>\n\n")
	b.WriteString("#ifndef BYTE1\n#define BYTE1(x) ((uint8_t)(((uint32_t)(x) >> 8) & 0xFFu))\n#endif\n\n")
	cursor := 0x100
	for _, rec := range recs {
		sym := uniqueSymbol(rec.Name, used)
		addr, err := parseAddr(rec.Address)
		if err != nil {
			return "", err
		}
		if addr < chipBase {
			return "", fmt.Errorf("address below chip base: %s", rec.Address)
		}
		start := int(addr - chipBase)
		if start > len(raw) {
			return "", fmt.Errorf("address outside firmware: %s", rec.Address)
		}
		if cursor < start {
			emitTopLevelBytes(&b, "", raw[cursor:start], fmt.Sprintf("gap_%06x", chipBase+uint32(cursor)), false)
			cursor = start
		}
		b.WriteString(fmt.Sprintf("/* %s @ %s size=%d mode=%s verify=%s */\n",
			rec.Name, rec.Address, rec.Size, rec.Mode, rec.VerifyStatus))
		if rec.Mode == "blocked" {
			b.WriteString(fmt.Sprintf("void %s(void) { __builtin_trap(); }\n\n", sym))
			continue
		}
		body, err := rawBytesFor(rec, raw)
		if err != nil {
			return "", err
		}
		if rec.Mode == "c_candidate" {
			b.WriteString("/* c_candidate is tracked in the ledger; raw bytes stay packaged until equivalence verification. */\n")
		}
		if rec.Mode == "c_verified" {
			b.WriteString("/* c_verified has byte-equivalent C evidence; raw bytes stay packaged until layout-safe C substitution. */\n")
		}
		emitTopLevelBytes(&b, sym, body, fmt.Sprintf("fn_%06x", addr), true)
		cursor = maxInt(cursor, start+len(body))
	}
	if cursor < len(raw) {
		emitTopLevelBytes(&b, "", raw[cursor:], fmt.Sprintf("tail_%06x", chipBase+uint32(cursor)), false)
	}
	return b.String(), nil
}

func emitTopLevelBytes(b *strings.Builder, symbol string, body []byte, label string, function bool) {
	b.WriteString("__asm__(\n")
	b.WriteString("    \".section .text.v26,\\\"ax\\\",%progbits\\n\"\n")
	if function {
		b.WriteString(fmt.Sprintf("    \".global %s\\n\"\n", symbol))
		b.WriteString(fmt.Sprintf("    \".type %s, %%function\\n\"\n", symbol))
		b.WriteString(fmt.Sprintf("    \"%s:\\n\"\n", symbol))
	} else {
		b.WriteString(fmt.Sprintf("    \".L%s:\\n\"\n", safeAsmLabel(label)))
	}
	for _, by := range body {
		b.WriteString(fmt.Sprintf("    \".byte 0x%02x\\n\"\n", by))
	}
	if function {
		b.WriteString(fmt.Sprintf("    \".size %s, .-%s\\n\"\n", symbol, symbol))
	}
	b.WriteString("    \".previous\\n\"\n")
	b.WriteString(");\n\n")
}

func safeAsmLabel(s string) string {
	var b strings.Builder
	for _, r := range s {
		if r == '_' || ('a' <= r && r <= 'z') || ('A' <= r && r <= 'Z') || ('0' <= r && r <= '9') {
			b.WriteRune(r)
		} else {
			b.WriteByte('_')
		}
	}
	if b.Len() == 0 {
		return "gap"
	}
	return b.String()
}

func cBodyForHybrid(rec ledgerRecord, symbol string) (string, error) {
	if rec.CSource == "" {
		return "", fmt.Errorf("missing c_source for %s %s", rec.Image, rec.Address)
	}
	data, err := os.ReadFile(rec.CSource)
	if err != nil {
		return "", err
	}
	text := string(data)
	prelude, body := splitCPrelude(text)
	body = renameFirstFunction(body, symbol)
	if prelude != "" {
		return prelude + "\n" + body, nil
	}
	return body, nil
}

func stripCPrelude(text string) string {
	_, body := splitCPrelude(text)
	return body
}

func splitCPrelude(text string) (string, string) {
	lines := strings.Split(text, "\n")
	start := 0
	for i, line := range lines {
		trim := strings.TrimSpace(line)
		if trim == "" || strings.HasPrefix(trim, "#") || strings.HasPrefix(trim, "extern ") {
			continue
		}
		if strings.HasPrefix(trim, "//") {
			start = i
			break
		}
		start = i
		break
	}
	return strings.Join(lines[:start], "\n"), strings.Join(lines[start:], "\n")
}

func renameFirstFunction(text, symbol string) string {
	re := regexp.MustCompile(`(?m)^([A-Za-z_][A-Za-z0-9_\s\*]*\s+)([A-Za-z_][A-Za-z0-9_]*)\s*\(`)
	return re.ReplaceAllString(text, "${1}"+symbol+"(")
}

func uniqueSymbol(base string, used map[string]int) string {
	base = safeSymbol(base, 0)
	n := used[base]
	used[base] = n + 1
	if n == 0 {
		return base
	}
	return fmt.Sprintf("%s__dup%d", base, n)
}

func summarize(img string, recs []ledgerRecord) imageSummary {
	s := imageSummary{
		Image:     img,
		Total:     len(recs),
		ByMode:    map[string]int{},
		ByCompile: map[string]int{},
		ByVerify:  map[string]int{},
	}
	for _, r := range recs {
		s.ByMode[r.Mode]++
		s.ByCompile[r.CompileStatus]++
		s.ByVerify[r.VerifyStatus]++
		s.TotalBytes += r.Size
		if r.ByteSHA256 != "" {
			s.SourceBytes += r.Size
		}
		switch r.Mode {
		case "asm_exact":
			s.AsmExact++
		case "c_candidate":
			s.Candidates++
		case "c_verified":
			s.CVerified++
		case "blocked":
			s.Blocked++
		}
	}
	return s
}

func findTool(names ...string) string {
	for _, name := range names {
		if p, err := exec.LookPath(name); err == nil {
			return p
		}
	}
	return ""
}

func minInt(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func maxInt(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func absInt(v int) int {
	if v < 0 {
		return -v
	}
	return v
}
