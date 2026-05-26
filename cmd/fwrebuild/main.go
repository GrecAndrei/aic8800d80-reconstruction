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

type reconRecord struct {
	SchemaVersion  string   `json:"schema_version"`
	Image          string   `json:"image"`
	Address        string   `json:"address"`
	Name           string   `json:"name"`
	Role           string   `json:"role"`
	Confidence     float64  `json:"confidence"`
	OutDegree      int      `json:"out_degree"`
	InDegree       int      `json:"in_degree"`
	LinkDegree     int      `json:"link_degree"`
	MessageHits    int      `json:"message_hits"`
	PriorityScore  float64  `json:"priority_score"`
	Reasons        []string `json:"reasons"`
	SeenInProfiles []string `json:"seen_in_profiles"`
	SeenCount      int      `json:"seen_count"`
}

type imageSummary struct {
	Image            string  `json:"image"`
	FunctionCount    int     `json:"function_count"`
	AvgPriorityScore float64 `json:"avg_priority_score"`
	HighPriority     int     `json:"high_priority_count"`
	MessageHandlers  int     `json:"message_related_count"`
}

type rebuildManifest struct {
	SchemaVersion    string         `json:"schema_version"`
	GeneratedAt      string         `json:"generated_at"`
	WorksetPath      string         `json:"workset_path"`
	TotalFunctions   int            `json:"total_functions"`
	ImageCount       int            `json:"image_count"`
	TopPriorityCount int            `json:"top_priority_count"`
	ImageSummaries   []imageSummary `json:"image_summaries"`
	OutputDir        string         `json:"output_dir"`
}

func main() {
	var worksetPath string
	var outDir string
	var topPriority float64
	var maxPerImage int

	flag.StringVar(&worksetPath, "workset", "extraction_out/reconstruction/mega7/recon_workset.jsonl", "Input reconstruction workset JSONL")
	flag.StringVar(&outDir, "out", "extraction_out/reconstruction/mega7/rebuilt", "Output directory for reconstructed artifacts")
	flag.Float64Var(&topPriority, "top-priority", 4.0, "Priority threshold for high-priority bucket")
	flag.IntVar(&maxPerImage, "max-per-image", 30000, "Maximum emitted functions per image")
	flag.Parse()

	worksetAbs, err := filepath.Abs(worksetPath)
	if err != nil {
		fail("resolve workset: %v", err)
	}
	outAbs, err := filepath.Abs(outDir)
	if err != nil {
		fail("resolve out: %v", err)
	}
	if err := os.MkdirAll(outAbs, 0o755); err != nil {
		fail("mkdir out: %v", err)
	}

	rows, err := readJSONL(worksetAbs)
	if err != nil {
		fail("read workset: %v", err)
	}
	if len(rows) == 0 {
		fail("workset empty: %s", worksetAbs)
	}

	byImage := map[string][]reconRecord{}
	for _, r := range rows {
		byImage[r.Image] = append(byImage[r.Image], r)
	}

	imageKeys := make([]string, 0, len(byImage))
	for k := range byImage {
		imageKeys = append(imageKeys, k)
	}
	sort.Strings(imageKeys)

	manifest := rebuildManifest{
		SchemaVersion:  "0.1.0",
		GeneratedAt:    time.Now().UTC().Format(time.RFC3339),
		WorksetPath:    worksetAbs,
		TotalFunctions: len(rows),
		ImageCount:     len(imageKeys),
		OutputDir:      outAbs,
	}

	for _, img := range imageKeys {
		recs := byImage[img]
		sort.Slice(recs, func(i, j int) bool {
			if recs[i].PriorityScore == recs[j].PriorityScore {
				return recs[i].Address < recs[j].Address
			}
			return recs[i].PriorityScore > recs[j].PriorityScore
		})
		if maxPerImage > 0 && len(recs) > maxPerImage {
			recs = recs[:maxPerImage]
		}
		byImage[img] = recs

		sum := 0.0
		high := 0
		msg := 0
		for _, r := range recs {
			sum += r.PriorityScore
			if r.PriorityScore >= topPriority {
				high++
			}
			if r.MessageHits > 0 || hasReason(r.Reasons, "message_path") {
				msg++
			}
		}
		if high > 0 {
			manifest.TopPriorityCount += high
		}
		avg := 0.0
		if len(recs) > 0 {
			avg = sum / float64(len(recs))
		}
		manifest.ImageSummaries = append(manifest.ImageSummaries, imageSummary{
			Image: img, FunctionCount: len(recs), AvgPriorityScore: avg, HighPriority: high, MessageHandlers: msg,
		})

		jsonOut := filepath.Join(outAbs, sanitizeName(img)+".reconstructed.json")
		if err := fileio.WriteJSON(jsonOut, recs); err != nil {
			fail("write reconstructed json (%s): %v", img, err)
		}
		cOut := filepath.Join(outAbs, sanitizeName(img)+".reconstructed.c")
		if err := writeCStubs(cOut, img, recs); err != nil {
			fail("write c stubs (%s): %v", img, err)
		}
	}

	sort.Slice(manifest.ImageSummaries, func(i, j int) bool {
		return manifest.ImageSummaries[i].FunctionCount > manifest.ImageSummaries[j].FunctionCount
	})
	if err := fileio.WriteJSON(filepath.Join(outAbs, "rebuild_manifest.json"), manifest); err != nil {
		fail("write manifest: %v", err)
	}

	fmt.Printf("firmware reconstruction generated.\n")
	fmt.Printf("  workset_path: %s\n", worksetAbs)
	fmt.Printf("  total_functions: %d\n", manifest.TotalFunctions)
	fmt.Printf("  image_count: %d\n", manifest.ImageCount)
	fmt.Printf("  top_priority_count: %d\n", manifest.TopPriorityCount)
	fmt.Printf("  out_dir: %s\n", outAbs)
	fmt.Printf("  manifest_path: %s\n", filepath.Join(outAbs, "rebuild_manifest.json"))
}

func readJSONL(path string) ([]reconRecord, error) {
	f, c, err := openMaybeGzip(path)
	if err != nil {
		return nil, err
	}
	defer c()
	s := bufio.NewScanner(f)
	s.Buffer(make([]byte, 4096), 8*1024*1024)
	out := make([]reconRecord, 0, 4096)
	for s.Scan() {
		line := strings.TrimSpace(s.Text())
		if line == "" {
			continue
		}
		var r reconRecord
		if err := json.Unmarshal([]byte(line), &r); err != nil {
			return nil, err
		}
		if strings.TrimSpace(r.SchemaVersion) != "" && r.SchemaVersion != "0.1.0" {
			return nil, fmt.Errorf("workset schema mismatch: got %s want 0.1.0", r.SchemaVersion)
		}
		out = append(out, r)
	}
	return out, s.Err()
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

func writeCStubs(path, image string, recs []reconRecord) error {
	var b strings.Builder
	b.WriteString("/* Auto-generated mined reconstruction stubs */\n")
	b.WriteString("/* image: " + image + " */\n\n")
	b.WriteString("#include <stdint.h>\n\n")
	for _, r := range recs {
		name := sanitizeName(r.Name)
		if name == "" || name == "unknown" {
			name = "sub_" + strings.TrimPrefix(strings.ToLower(r.Address), "0x")
		}
		b.WriteString(fmt.Sprintf("/* addr=%s priority=%.3f seen=%d role=%s reasons=%s */\n", r.Address, r.PriorityScore, r.SeenCount, r.Role, strings.Join(r.Reasons, ",")))
		b.WriteString(fmt.Sprintf("void %s(void) {\n", name))
		b.WriteString("  /* TODO: recovered behavior from mined evidence */\n")
		if r.MessageHits > 0 {
			b.WriteString("  /* message-path related function */\n")
		}
		b.WriteString("}\n\n")
	}
	return fileio.WriteBytes(path, []byte(b.String()))
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

func hasReason(reasons []string, want string) bool {
	for _, r := range reasons {
		if r == want {
			return true
		}
	}
	return false
}

func fail(format string, args ...any) {
	fmt.Fprintf(os.Stderr, format+"\n", args...)
	os.Exit(1)
}
