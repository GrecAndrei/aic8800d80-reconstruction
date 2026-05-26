package main

import (
	"bufio"
	"compress/gzip"
	"encoding/json"
	"flag"
	"fmt"
	"io"
	"os"
	"path/filepath"
	"sort"
	"strings"
	"time"

	"aic8800d80/internal/fileio"
)

type focusIndexRow struct {
	SchemaVersion  string  `json:"schema_version,omitempty"`
	WorkID         string  `json:"work_id"`
	ClusterID      string  `json:"cluster_id"`
	Image          string  `json:"image"`
	TargetAddress  string  `json:"target_address"`
	TargetFunction string  `json:"target_function"`
	PriorityClass  string  `json:"priority_class"`
	WorkScore      float64 `json:"work_score"`
}

type callEdge struct {
	SchemaVersion string  `json:"schema_version,omitempty"`
	Image         string  `json:"image"`
	SourceAddr    string  `json:"source_addr"`
	SourceName    string  `json:"source_name"`
	TargetAddr    string  `json:"target_addr"`
	TargetName    string  `json:"target_name"`
	Confidence    float64 `json:"confidence"`
}

type liftedUnit struct {
	SchemaVersion     string   `json:"schema_version"`
	UnitID            string   `json:"unit_id"`
	WorkID            string   `json:"work_id"`
	ClusterID         string   `json:"cluster_id"`
	Image             string   `json:"image"`
	Address           string   `json:"address"`
	Function          string   `json:"function"`
	PriorityClass     string   `json:"priority_class"`
	WorkScore         float64  `json:"work_score"`
	DependencyAddrs   []string `json:"dependency_addresses"`
	DependencyNames   []string `json:"dependency_names"`
	IncomingCallCount int      `json:"incoming_call_count"`
	OutgoingCallCount int      `json:"outgoing_call_count"`
	LiftedAt          string   `json:"lifted_at"`
}

type imageLiftSummary struct {
	Image      string `json:"image"`
	UnitCount  int    `json:"unit_count"`
	Critical   int    `json:"critical_count"`
	High       int    `json:"high_count"`
	DependsAll int    `json:"total_dependencies"`
}

type liftManifest struct {
	SchemaVersion  string             `json:"schema_version"`
	GeneratedAt    string             `json:"generated_at"`
	FocusIndex     string             `json:"focus_index_path"`
	CallEdgesPath  string             `json:"call_edges_path"`
	UnitCount      int                `json:"unit_count"`
	ImageCount     int                `json:"image_count"`
	ImageSummaries []imageLiftSummary `json:"image_summaries"`
	OutputDir      string             `json:"output_dir"`
}

func main() {
	var focusIndexPath string
	var callEdgesPath string
	var outDir string
	var minConf float64
	var maxDeps int

	flag.StringVar(&focusIndexPath, "focus-index", "extraction_out/reconstruction/mega7/focus/focus_index.json", "Focus index JSON path")
	flag.StringVar(&callEdgesPath, "call-edges", "extraction_out/call_edges.jsonl", "Call edges JSONL path")
	flag.StringVar(&outDir, "out", "extraction_out/reconstruction/mega7/lift", "Output directory for lifted reconstruction")
	flag.Float64Var(&minConf, "min-call-confidence", 0.7, "Minimum edge confidence for dependencies")
	flag.IntVar(&maxDeps, "max-deps", 16, "Maximum dependencies tracked per lifted unit")
	flag.Parse()

	idxAbs, _ := filepath.Abs(focusIndexPath)
	callAbs, _ := filepath.Abs(callEdgesPath)
	outAbs, _ := filepath.Abs(outDir)
	if err := os.MkdirAll(outAbs, 0o755); err != nil {
		fail("mkdir out: %v", err)
	}

	rows, err := readFocusIndex(idxAbs)
	if err != nil {
		fail("read focus index: %v", err)
	}
	if len(rows) == 0 {
		fail("no focus rows found")
	}

	inAdj, outAdj, err := readAdj(callAbs, minConf)
	if err != nil {
		fail("read call edges: %v", err)
	}

	units := make([]liftedUnit, 0, len(rows))
	byImage := map[string][]liftedUnit{}
	for i, r := range rows {
		k := addrKey(r.Image, r.TargetAddress)
		depAddrs, depNames := collectDeps(inAdj[k], outAdj[k], maxDeps)
		u := liftedUnit{
			SchemaVersion:     "0.1.0",
			UnitID:            fmt.Sprintf("lift_%04d", i+1),
			WorkID:            r.WorkID,
			ClusterID:         r.ClusterID,
			Image:             r.Image,
			Address:           r.TargetAddress,
			Function:          nonEmpty(r.TargetFunction, "sub_"+strings.TrimPrefix(strings.ToLower(r.TargetAddress), "0x")),
			PriorityClass:     r.PriorityClass,
			WorkScore:         round3(r.WorkScore),
			DependencyAddrs:   depAddrs,
			DependencyNames:   depNames,
			IncomingCallCount: len(inAdj[k]),
			OutgoingCallCount: len(outAdj[k]),
			LiftedAt:          time.Now().UTC().Format(time.RFC3339),
		}
		units = append(units, u)
		byImage[u.Image] = append(byImage[u.Image], u)
	}

	sort.Slice(units, func(i, j int) bool {
		if units[i].WorkScore == units[j].WorkScore {
			return units[i].UnitID < units[j].UnitID
		}
		return units[i].WorkScore > units[j].WorkScore
	})

	if err := fileio.WriteJSON(filepath.Join(outAbs, "lift_units.json"), units); err != nil {
		fail("write units: %v", err)
	}

	imageKeys := make([]string, 0, len(byImage))
	for k := range byImage {
		imageKeys = append(imageKeys, k)
	}
	sort.Strings(imageKeys)

	summaries := make([]imageLiftSummary, 0, len(imageKeys))
	for _, img := range imageKeys {
		rows := byImage[img]
		crit := 0
		high := 0
		depTotal := 0
		sort.Slice(rows, func(i, j int) bool { return rows[i].WorkScore > rows[j].WorkScore })
		if err := writeImageLiftC(filepath.Join(outAbs, sanitizeName(img)+".lifted.c"), img, rows); err != nil {
			fail("write lifted c %s: %v", img, err)
		}
		for _, u := range rows {
			if u.PriorityClass == "critical" {
				crit++
			}
			if u.PriorityClass == "high" {
				high++
			}
			depTotal += len(u.DependencyAddrs)
		}
		summaries = append(summaries, imageLiftSummary{
			Image: img, UnitCount: len(rows), Critical: crit, High: high, DependsAll: depTotal,
		})
	}

	manifest := liftManifest{
		SchemaVersion:  "0.1.0",
		GeneratedAt:    time.Now().UTC().Format(time.RFC3339),
		FocusIndex:     idxAbs,
		CallEdgesPath:  callAbs,
		UnitCount:      len(units),
		ImageCount:     len(imageKeys),
		ImageSummaries: summaries,
		OutputDir:      outAbs,
	}
	if err := fileio.WriteJSON(filepath.Join(outAbs, "lift_manifest.json"), manifest); err != nil {
		fail("write manifest: %v", err)
	}

	fmt.Printf("lifted reconstruction generated.\n")
	fmt.Printf("  unit_count: %d\n", manifest.UnitCount)
	fmt.Printf("  image_count: %d\n", manifest.ImageCount)
	fmt.Printf("  out_dir: %s\n", outAbs)
}

func readFocusIndex(path string) ([]focusIndexRow, error) {
	b, err := os.ReadFile(path)
	if err != nil {
		return nil, err
	}
	var rows []focusIndexRow
	if err := json.Unmarshal(b, &rows); err != nil {
		return nil, err
	}
	for _, r := range rows {
		if strings.TrimSpace(r.SchemaVersion) != "" && r.SchemaVersion != "0.1.0" {
			return nil, fmt.Errorf("focus index schema mismatch: got %s, want 0.1.0", r.SchemaVersion)
		}
	}
	return rows, nil
}

func readAdj(path string, minConf float64) (map[string][]callEdge, map[string][]callEdge, error) {
	f, closeFn, err := openMaybeGzip(path)
	if err != nil {
		return nil, nil, err
	}
	defer closeFn()
	in := make(map[string][]callEdge, 4096)
	out := make(map[string][]callEdge, 4096)
	s := bufio.NewScanner(f)
	s.Buffer(make([]byte, 4096), 8*1024*1024)
	for s.Scan() {
		line := strings.TrimSpace(s.Text())
		if line == "" {
			continue
		}
		var e callEdge
		if err := json.Unmarshal([]byte(line), &e); err != nil {
			continue
		}
		if strings.TrimSpace(e.SchemaVersion) != "" && e.SchemaVersion != "0.1.0" {
			return nil, nil, fmt.Errorf("call edges schema mismatch: got %s, want 0.1.0", e.SchemaVersion)
		}
		if e.Confidence < minConf {
			continue
		}
		sk := addrKey(e.Image, e.SourceAddr)
		tk := addrKey(e.Image, e.TargetAddr)
		out[sk] = append(out[sk], e)
		in[tk] = append(in[tk], e)
	}
	return in, out, s.Err()
}

func openMaybeGzip(path string) (io.Reader, func() error, error) {
	if f, err := os.Open(path); err == nil {
		return f, f.Close, nil
	}
	if f, err := os.Open(path + ".gz"); err == nil {
		gz, zerr := gzip.NewReader(f)
		if zerr != nil {
			_ = f.Close()
			return nil, nil, zerr
		}
		return gz, func() error {
			_ = gz.Close()
			return f.Close()
		}, nil
	}
	return nil, nil, fmt.Errorf("missing input: %s(.gz)", path)
}

func collectDeps(in, out []callEdge, maxDeps int) ([]string, []string) {
	seenA := map[string]struct{}{}
	seenN := map[string]struct{}{}
	addrs := make([]string, 0, maxDeps)
	names := make([]string, 0, maxDeps)
	add := func(addr, name string) {
		addr = strings.ToLower(strings.TrimSpace(addr))
		name = strings.TrimSpace(name)
		if addr == "" {
			return
		}
		if _, ok := seenA[addr]; ok {
			return
		}
		seenA[addr] = struct{}{}
		addrs = append(addrs, addr)
		if name != "" {
			if _, ok := seenN[name]; !ok {
				seenN[name] = struct{}{}
				names = append(names, name)
			}
		}
	}
	for _, e := range out {
		add(e.TargetAddr, e.TargetName)
		if len(addrs) >= maxDeps {
			break
		}
	}
	for _, e := range in {
		if len(addrs) >= maxDeps {
			break
		}
		add(e.SourceAddr, e.SourceName)
	}
	return addrs, names
}

func writeImageLiftC(path, image string, units []liftedUnit) error {
	var b strings.Builder
	b.WriteString("/* Auto-generated lifted reconstruction units */\n")
	b.WriteString("/* image: " + image + " */\n\n")
	b.WriteString("#include <stdint.h>\n\n")
	for _, u := range units {
		fn := sanitizeName(nonEmpty(u.Function, "sub_"+strings.TrimPrefix(strings.ToLower(u.Address), "0x")))
		b.WriteString(fmt.Sprintf("/* unit=%s class=%s score=%.3f addr=%s in=%d out=%d deps=%d */\n", u.UnitID, u.PriorityClass, u.WorkScore, u.Address, u.IncomingCallCount, u.OutgoingCallCount, len(u.DependencyAddrs)))
		if len(u.DependencyNames) > 0 {
			b.WriteString("/* deps: " + strings.Join(u.DependencyNames, ", ") + " */\n")
		}
		b.WriteString("void " + fn + "(void) {\n")
		b.WriteString("  // TODO: replace lifted skeleton with recovered logic.\n")
		b.WriteString("}\n\n")
	}
	return fileio.WriteBytes(path, []byte(b.String()))
}

func addrKey(img, addr string) string {
	return strings.TrimSpace(img) + "|" + strings.ToLower(strings.TrimSpace(addr))
}

func nonEmpty(v, fallback string) string {
	if strings.TrimSpace(v) == "" {
		return fallback
	}
	return v
}

func sanitizeName(s string) string {
	s = strings.TrimSpace(strings.ToLower(s))
	if s == "" {
		return "unknown"
	}
	var b strings.Builder
	for _, r := range s {
		if (r >= 'a' && r <= 'z') || (r >= '0' && r <= '9') || r == '_' {
			b.WriteRune(r)
		} else {
			b.WriteByte('_')
		}
	}
	out := strings.Trim(b.String(), "_")
	if out == "" {
		return "unknown"
	}
	return out
}

func round3(v float64) float64 { return float64(int(v*1000+0.5)) / 1000 }

func fail(format string, args ...any) {
	fmt.Fprintf(os.Stderr, format+"\n", args...)
	os.Exit(1)
}
