package main

import (
	"bufio"
	"encoding/json"
	"flag"
	"fmt"
	"os"
	"path/filepath"
	"sort"
	"strings"
	"time"
)

type liftedUnit struct {
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
}

type callEdge struct {
	Image      string  `json:"image"`
	SourceAddr string  `json:"source_addr"`
	SourceName string  `json:"source_name"`
	TargetAddr string  `json:"target_addr"`
	TargetName string  `json:"target_name"`
	Confidence float64 `json:"confidence"`
}

type composeManifest struct {
	SchemaVersion         string `json:"schema_version"`
	GeneratedAt           string `json:"generated_at"`
	LiftUnitsPath         string `json:"lift_units_path"`
	UnitCount             int    `json:"unit_count"`
	ImageCount            int    `json:"image_count"`
	DependencyStubCount   int    `json:"dependency_stub_count"`
	ComposedFunctionCount int    `json:"composed_function_count"`
	PerImageFileCount     int    `json:"per_image_file_count"`
	OutputDir             string `json:"output_dir"`
	OutputC               string `json:"output_c"`
	OutputIndex           string `json:"output_index"`
}

type composeIndexRow struct {
	Function     string  `json:"function"`
	Image        string  `json:"image"`
	Address      string  `json:"address"`
	Priority     string  `json:"priority"`
	WorkScore    float64 `json:"work_score"`
	Kind         string  `json:"kind"` // lifted_unit | dependency_stub
	Incoming     int     `json:"incoming_calls"`
	Outgoing     int     `json:"outgoing_calls"`
	Dependencies int     `json:"dependencies"`
}

func main() {
	var liftUnitsPath string
	var outDir string
	var callEdgesPath string
	var minNameConfidence float64

	flag.StringVar(&liftUnitsPath, "lift-units", "extraction_out/reconstruction/mega7/lift/lift_units.json", "Lift units JSON")
	flag.StringVar(&outDir, "out", "extraction_out/reconstruction/mega7/composed", "Output directory")
	flag.StringVar(&callEdgesPath, "call-edges", "extraction_out/call_edges.jsonl", "Call edges JSONL for canonical naming")
	flag.Float64Var(&minNameConfidence, "min-name-confidence", 0.7, "Minimum edge confidence for canonical naming")
	flag.Parse()

	liftAbs, _ := filepath.Abs(liftUnitsPath)
	outAbs, _ := filepath.Abs(outDir)
	callAbs, _ := filepath.Abs(callEdgesPath)
	if err := os.MkdirAll(outAbs, 0o755); err != nil {
		fail("mkdir out: %v", err)
	}

	b, err := os.ReadFile(liftAbs)
	if err != nil {
		fail("read lift units: %v", err)
	}
	var units []liftedUnit
	if err := json.Unmarshal(b, &units); err != nil {
		fail("parse lift units: %v", err)
	}
	if len(units) == 0 {
		fail("no lifted units found")
	}
	canonicalByAddr := deriveCanonicalNames(callAbs, minNameConfidence)

	sort.Slice(units, func(i, j int) bool {
		if units[i].Image == units[j].Image {
			if units[i].PriorityClass == units[j].PriorityClass {
				return units[i].WorkScore > units[j].WorkScore
			}
			return classRank(units[i].PriorityClass) < classRank(units[j].PriorityClass)
		}
		return units[i].Image < units[j].Image
	})

	images := map[string]struct{}{}
	byImage := map[string][]liftedUnit{}
	unitFuncSet := map[string]struct{}{}
	unitNameByAddr := map[string]string{}
	depSet := map[string]struct{}{}
	index := make([]composeIndexRow, 0, len(units)+64)
	var sb strings.Builder
	sb.WriteString("/* Auto-generated composed firmware reconstruction */\n")
	sb.WriteString("/* synthesized from lifted units */\n\n")
	sb.WriteString("#include <stdint.h>\n\n")

	curImg := ""
	for _, u := range units {
		fn := chooseFunctionName(u, canonicalByAddr)
		unitNameByAddr[addrKey(u.Image, u.Address)] = fn
	}
	for _, u := range units {
		images[u.Image] = struct{}{}
		byImage[u.Image] = append(byImage[u.Image], u)
		if u.Image != curImg {
			curImg = u.Image
			sb.WriteString("\n/* ===== IMAGE: " + curImg + " ===== */\n\n")
		}
		fn := chooseFunctionName(u, canonicalByAddr)
		unitFuncSet[fn] = struct{}{}
		index = append(index, composeIndexRow{
			Function: fn, Image: u.Image, Address: u.Address, Priority: u.PriorityClass,
			WorkScore: u.WorkScore, Kind: "lifted_unit", Incoming: u.IncomingCallCount, Outgoing: u.OutgoingCallCount, Dependencies: len(u.DependencyNames),
		})
		sb.WriteString(fmt.Sprintf("/* unit=%s class=%s score=%.3f addr=%s in=%d out=%d */\n", u.UnitID, u.PriorityClass, u.WorkScore, u.Address, u.IncomingCallCount, u.OutgoingCallCount))
		if len(u.DependencyNames) > 0 {
			sb.WriteString("/* deps: " + strings.Join(u.DependencyNames, ", ") + " */\n")
		}
		resolvedDeps := resolveDependencyNames(u, unitNameByAddr)
		for _, d := range resolvedDeps {
			ds := sanitizeName(d)
			if ds != "" && ds != "unknown" {
				depSet[ds] = struct{}{}
			}
		}
		sb.WriteString("void " + fn + "(void) {\n")
		if len(resolvedDeps) == 0 {
			sb.WriteString("  // TODO: integrate full control/data flow from focused bundle evidence.\n")
		} else {
			sb.WriteString("  // Reconstructed call scaffold from mined dependency evidence.\n")
			for _, d := range resolvedDeps {
				ds := sanitizeName(d)
				if ds == "" || ds == "unknown" {
					continue
				}
				sb.WriteString("  " + ds + "();\n")
			}
		}
		sb.WriteString("}\n\n")
	}

	// Append stubs for unresolved dependency functions to improve compilable surface.
	deps := make([]string, 0, len(depSet))
	for d := range depSet {
		if _, exists := unitFuncSet[d]; !exists {
			deps = append(deps, d)
		}
	}
	sort.Strings(deps)
	if len(deps) > 0 {
		sb.WriteString("\n/* ===== AUTO-GENERATED DEPENDENCY STUBS ===== */\n\n")
		for _, d := range deps {
			sb.WriteString("void " + d + "(void) {\n")
			sb.WriteString("  // TODO: dependency stub from mined call graph evidence.\n")
			sb.WriteString("}\n\n")
			index = append(index, composeIndexRow{
				Function: d, Image: "shared", Address: "", Priority: "stub", WorkScore: 0, Kind: "dependency_stub",
			})
		}
	}

	outC := filepath.Join(outAbs, "firmware_reconstructed.c")
	if err := os.WriteFile(outC, []byte(sb.String()), 0o644); err != nil {
		fail("write composed c: %v", err)
	}
	sort.Slice(index, func(i, j int) bool {
		if index[i].Kind == index[j].Kind {
			if index[i].Image == index[j].Image {
				return index[i].Function < index[j].Function
			}
			return index[i].Image < index[j].Image
		}
		return index[i].Kind < index[j].Kind
	})
	outIndex := filepath.Join(outAbs, "compose_index.json")
	ib, err := json.MarshalIndent(index, "", "  ")
	if err != nil {
		fail("marshal compose index: %v", err)
	}
	if err := os.WriteFile(outIndex, append(ib, '\n'), 0o644); err != nil {
		fail("write compose index: %v", err)
	}

	imageKeys := make([]string, 0, len(byImage))
	for img := range byImage {
		imageKeys = append(imageKeys, img)
	}
	sort.Strings(imageKeys)
	for _, img := range imageKeys {
		outImg := filepath.Join(outAbs, sanitizeName(img)+".reconstructed.c")
		if err := writePerImageFile(outImg, img, byImage[img], depSet, unitFuncSet, canonicalByAddr, unitNameByAddr); err != nil {
			fail("write per-image file %s: %v", img, err)
		}
	}

	m := composeManifest{
		SchemaVersion:         "0.1.0",
		GeneratedAt:           time.Now().UTC().Format(time.RFC3339),
		LiftUnitsPath:         liftAbs,
		UnitCount:             len(units),
		ImageCount:            len(images),
		DependencyStubCount:   len(deps),
		ComposedFunctionCount: len(units) + len(deps),
		PerImageFileCount:     len(byImage),
		OutputDir:             outAbs,
		OutputC:               outC,
		OutputIndex:           outIndex,
	}
	mb, err := json.MarshalIndent(m, "", "  ")
	if err != nil {
		fail("manifest marshal: %v", err)
	}
	if err := os.WriteFile(filepath.Join(outAbs, "compose_manifest.json"), append(mb, '\n'), 0o644); err != nil {
		fail("write compose manifest: %v", err)
	}

	fmt.Printf("composed firmware reconstruction generated.\n")
	fmt.Printf("  unit_count: %d\n", m.UnitCount)
	fmt.Printf("  image_count: %d\n", m.ImageCount)
	fmt.Printf("  dependency_stub_count: %d\n", m.DependencyStubCount)
	fmt.Printf("  composed_function_count: %d\n", m.ComposedFunctionCount)
	fmt.Printf("  per_image_file_count: %d\n", m.PerImageFileCount)
	fmt.Printf("  output_index: %s\n", outIndex)
	fmt.Printf("  output_c: %s\n", outC)
}

func classRank(c string) int {
	switch c {
	case "critical":
		return 0
	case "high":
		return 1
	case "medium":
		return 2
	default:
		return 3
	}
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

func nonEmpty(v, fallback string) string {
	if strings.TrimSpace(v) == "" {
		return fallback
	}
	return v
}

func writePerImageFile(path, image string, units []liftedUnit, depSet map[string]struct{}, unitFuncSet map[string]struct{}, canonicalByAddr map[string]string, unitNameByAddr map[string]string) error {
	sort.Slice(units, func(i, j int) bool {
		if units[i].PriorityClass == units[j].PriorityClass {
			return units[i].WorkScore > units[j].WorkScore
		}
		return classRank(units[i].PriorityClass) < classRank(units[j].PriorityClass)
	})
	var b strings.Builder
	b.WriteString("/* Auto-generated per-image composed reconstruction */\n")
	b.WriteString("/* image: " + image + " */\n\n")
	b.WriteString("#include <stdint.h>\n\n")
	for _, u := range units {
		fn := chooseFunctionName(u, canonicalByAddr)
		b.WriteString(fmt.Sprintf("/* unit=%s class=%s score=%.3f addr=%s */\n", u.UnitID, u.PriorityClass, u.WorkScore, u.Address))
		b.WriteString("void " + fn + "(void) {\n")
		resolvedDeps := resolveDependencyNames(u, unitNameByAddr)
		if len(resolvedDeps) == 0 {
			b.WriteString("  // TODO: integrate control/data flow.\n")
		} else {
			for _, d := range resolvedDeps {
				ds := sanitizeName(d)
				if ds == "" || ds == "unknown" {
					continue
				}
				b.WriteString("  " + ds + "();\n")
			}
		}
		b.WriteString("}\n\n")
	}
	deps := make([]string, 0, len(depSet))
	for d := range depSet {
		if _, exists := unitFuncSet[d]; !exists {
			deps = append(deps, d)
		}
	}
	sort.Strings(deps)
	if len(deps) > 0 {
		b.WriteString("/* shared dependency stubs */\n\n")
		for _, d := range deps {
			b.WriteString("void " + d + "(void) {\n")
			b.WriteString("  // TODO: dependency stub from mined call graph evidence.\n")
			b.WriteString("}\n\n")
		}
	}
	return os.WriteFile(path, []byte(b.String()), 0o644)
}

func resolveDependencyNames(u liftedUnit, unitNameByAddr map[string]string) []string {
	out := make([]string, 0, len(u.DependencyNames)+len(u.DependencyAddrs))
	seen := map[string]struct{}{}
	add := func(n string) {
		n = sanitizeName(n)
		if n == "" || n == "unknown" {
			return
		}
		if _, ok := seen[n]; ok {
			return
		}
		seen[n] = struct{}{}
		out = append(out, n)
	}
	for _, a := range u.DependencyAddrs {
		if n, ok := unitNameByAddr[addrKey(u.Image, a)]; ok {
			add(n)
		}
	}
	for _, n := range u.DependencyNames {
		add(n)
	}
	return out
}

func addrKey(img, addr string) string {
	return strings.ToLower(strings.TrimSpace(img)) + "|" + strings.ToLower(strings.TrimSpace(addr))
}

func chooseFunctionName(u liftedUnit, canonicalByAddr map[string]string) string {
	k := strings.ToLower(strings.TrimSpace(u.Image)) + "|" + strings.ToLower(strings.TrimSpace(u.Address))
	if n, ok := canonicalByAddr[k]; ok && n != "" {
		return sanitizeName(n)
	}
	return sanitizeName(nonEmpty(u.Function, "sub_"+strings.TrimPrefix(strings.ToLower(u.Address), "0x")))
}

func deriveCanonicalNames(callPath string, minConf float64) map[string]string {
	f, err := os.Open(callPath)
	if err != nil {
		return map[string]string{}
	}
	defer f.Close()
	type vote struct {
		name string
		w    float64
	}
	score := map[string]map[string]float64{}
	sc := bufio.NewScanner(f)
	sc.Buffer(make([]byte, 4096), 8*1024*1024)
	for sc.Scan() {
		line := strings.TrimSpace(sc.Text())
		if line == "" {
			continue
		}
		var e callEdge
		if json.Unmarshal([]byte(line), &e) != nil {
			continue
		}
		if e.Confidence < minConf {
			continue
		}
		if strings.TrimSpace(e.SourceAddr) != "" && strings.TrimSpace(e.SourceName) != "" {
			k := strings.ToLower(strings.TrimSpace(e.Image)) + "|" + strings.ToLower(strings.TrimSpace(e.SourceAddr))
			if score[k] == nil {
				score[k] = map[string]float64{}
			}
			score[k][sanitizeName(e.SourceName)] += e.Confidence
		}
		if strings.TrimSpace(e.TargetAddr) != "" && strings.TrimSpace(e.TargetName) != "" {
			k := strings.ToLower(strings.TrimSpace(e.Image)) + "|" + strings.ToLower(strings.TrimSpace(e.TargetAddr))
			if score[k] == nil {
				score[k] = map[string]float64{}
			}
			score[k][sanitizeName(e.TargetName)] += e.Confidence * 0.8
		}
	}
	out := map[string]string{}
	for k, names := range score {
		best := vote{}
		for n, w := range names {
			if n == "" || n == "unknown" || strings.HasPrefix(n, "sub_") {
				continue
			}
			if w > best.w {
				best = vote{name: n, w: w}
			}
		}
		if best.name != "" {
			out[k] = best.name
		}
	}
	return out
}

func fail(format string, args ...any) {
	fmt.Fprintf(os.Stderr, format+"\n", args...)
	os.Exit(1)
}
