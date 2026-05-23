package main

import (
	"bufio"
	"encoding/json"
	"flag"
	"fmt"
	"hash/fnv"
	"os"
	"path/filepath"
	"sort"
	"strings"
	"time"
)

type miningRecord struct {
	SchemaVersion string   `json:"schema_version"`
	Image         string   `json:"image"`
	Address       string   `json:"address"`
	Name          string   `json:"name"`
	Role          string   `json:"role"`
	Confidence    float64  `json:"confidence"`
	OutDegree     int      `json:"out_degree"`
	InDegree      int      `json:"in_degree"`
	LinkDegree    int      `json:"link_degree"`
	MessageHits   int      `json:"message_hits"`
	PriorityScore float64  `json:"priority_score"`
	Reasons       []string `json:"reasons"`
}

type runSummary struct {
	MiningQueueCount int `json:"mining_queue_count"`
}

type unionRecord struct {
	miningRecord
	SeenInProfiles []string `json:"seen_in_profiles"`
	SeenCount      int      `json:"seen_count"`
}

type profileResult struct {
	Name       string `json:"name"`
	UnionCount int    `json:"union_count"`
}

type megaSummary struct {
	Results []profileResult `json:"results"`
}

type idaJob struct {
	Image        string   `json:"image"`
	AddressCount int      `json:"address_count"`
	AddressFile  string   `json:"address_file"`
	IdatCommand  string   `json:"idat_command"`
	TopAddresses []string `json:"top_addresses"`
}

type reconManifest struct {
	SchemaVersion   string   `json:"schema_version"`
	GeneratedAt     string   `json:"generated_at"`
	MegaDir         string   `json:"mega_dir"`
	ProfileCount    int      `json:"profile_count"`
	TotalUnion      int      `json:"total_union"`
	WorksetCount    int      `json:"workset_count"`
	StrictCount     int      `json:"strict_count"`
	AggressiveCount int      `json:"aggressive_count"`
	TopN            int      `json:"top_n"`
	UnionShards     int      `json:"union_shards"`
	IdatPath        string   `json:"idat_path"`
	Profiles        []string `json:"profiles"`
}

func main() {
	var megaDir string
	var outDir string
	var topN int
	var strictMinSeen int
	var strictMinScore float64
	var unionShards int
	var idatPath string
	var root string

	flag.StringVar(&megaDir, "mega-dir", "extraction_out/mega7", "Mega output directory")
	flag.StringVar(&outDir, "out", "extraction_out/reconstruction", "Output directory for reconstruction artifacts")
	flag.IntVar(&topN, "top-n", 120000, "Top reconstruction targets to emit")
	flag.IntVar(&strictMinSeen, "strict-min-seen", 2, "Minimum profile coverage for strict lane")
	flag.Float64Var(&strictMinScore, "strict-min-score", 1.2, "Minimum score for strict lane")
	flag.IntVar(&unionShards, "union-shards", 512, "Shard count for disk-backed dedupe")
	flag.StringVar(&idatPath, "idat", "/home/grec-alexander/ida-pro-9.2/idat", "IDA headless executable path")
	flag.StringVar(&root, "root", ".", "Workspace root for image path resolution")
	flag.Parse()

	megaAbs, err := filepath.Abs(megaDir)
	if err != nil {
		fail("resolve mega dir: %v", err)
	}
	outAbs, err := filepath.Abs(outDir)
	if err != nil {
		fail("resolve out dir: %v", err)
	}
	rootAbs, err := filepath.Abs(root)
	if err != nil {
		fail("resolve root: %v", err)
	}
	if err := os.MkdirAll(outAbs, 0o755); err != nil {
		fail("mkdir out: %v", err)
	}

	profiles, err := discoverProfiles(megaAbs)
	if err != nil {
		fail("discover profiles: %v", err)
	}
	if len(profiles) == 0 {
		fail("no profiles discovered in %s", megaAbs)
	}

	unionRows, err := buildUnionRowsSharded(megaAbs, profiles, unionShards)
	if err != nil {
		fail("build union rows: %v", err)
	}
	sort.Slice(unionRows, func(i, j int) bool {
		if unionRows[i].PriorityScore == unionRows[j].PriorityScore {
			if unionRows[i].SeenCount == unionRows[j].SeenCount {
				return unionRows[i].Address < unionRows[j].Address
			}
			return unionRows[i].SeenCount > unionRows[j].SeenCount
		}
		return unionRows[i].PriorityScore > unionRows[j].PriorityScore
	})

	strict := make([]unionRecord, 0, len(unionRows)/5)
	aggressive := make([]unionRecord, 0, len(unionRows))
	for _, r := range unionRows {
		if r.SeenCount >= strictMinSeen && r.PriorityScore >= strictMinScore && !hasReason(r.Reasons, "cross_image_neighborhood") {
			strict = append(strict, r)
		} else if r.PriorityScore >= 1.0 {
			aggressive = append(aggressive, r)
		}
	}

	workset := make([]unionRecord, 0, topN)
	workset = append(workset, strict...)
	workset = append(workset, aggressive...)
	if len(workset) > topN {
		workset = workset[:topN]
	}

	unionPath := filepath.Join(outAbs, "recon_union.jsonl")
	strictPath := filepath.Join(outAbs, "recon_strict.jsonl")
	worksetPath := filepath.Join(outAbs, "recon_workset.jsonl")
	if err := writeJSONL(unionPath, unionRows); err != nil {
		fail("write union: %v", err)
	}
	if err := writeJSONL(strictPath, strict); err != nil {
		fail("write strict: %v", err)
	}
	if err := writeJSONL(worksetPath, workset); err != nil {
		fail("write workset: %v", err)
	}

	idaDir := filepath.Join(outAbs, "ida_jobs")
	if err := os.MkdirAll(idaDir, 0o755); err != nil {
		fail("mkdir ida_jobs: %v", err)
	}
	idaJobs, err := buildIDAJobs(idaDir, workset, rootAbs, idatPath)
	if err != nil {
		fail("build ida jobs: %v", err)
	}
	if err := writeJSON(filepath.Join(outAbs, "ida_jobs.json"), idaJobs); err != nil {
		fail("write ida jobs: %v", err)
	}

	manifest := reconManifest{
		SchemaVersion:   "0.1.0",
		GeneratedAt:     time.Now().UTC().Format(time.RFC3339),
		MegaDir:         megaAbs,
		ProfileCount:    len(profiles),
		TotalUnion:      len(unionRows),
		WorksetCount:    len(workset),
		StrictCount:     len(strict),
		AggressiveCount: len(aggressive),
		TopN:            topN,
		UnionShards:     unionShards,
		IdatPath:        idatPath,
		Profiles:        profiles,
	}
	if err := writeJSON(filepath.Join(outAbs, "recon_manifest.json"), manifest); err != nil {
		fail("write manifest: %v", err)
	}

	fmt.Printf("reconstruction prepared.\n")
	fmt.Printf("  mega_dir: %s\n", megaAbs)
	fmt.Printf("  profile_count: %d\n", len(profiles))
	fmt.Printf("  union_count: %d\n", len(unionRows))
	fmt.Printf("  strict_count: %d\n", len(strict))
	fmt.Printf("  aggressive_count: %d\n", len(aggressive))
	fmt.Printf("  workset_count: %d\n", len(workset))
	fmt.Printf("  union_path: %s\n", unionPath)
	fmt.Printf("  strict_path: %s\n", strictPath)
	fmt.Printf("  workset_path: %s\n", worksetPath)
	fmt.Printf("  ida_jobs_path: %s\n", filepath.Join(outAbs, "ida_jobs.json"))
	fmt.Printf("  manifest_path: %s\n", filepath.Join(outAbs, "recon_manifest.json"))
}

func discoverProfiles(megaAbs string) ([]string, error) {
	latest := filepath.Join(megaAbs, "latest_mega_summary.json")
	b, err := os.ReadFile(latest)
	if err == nil {
		var s megaSummary
		if json.Unmarshal(b, &s) == nil && len(s.Results) > 0 {
			out := make([]string, 0, len(s.Results))
			for _, r := range s.Results {
				if strings.TrimSpace(r.Name) != "" {
					out = append(out, r.Name)
				}
			}
			if len(out) > 0 {
				return out, nil
			}
		}
	}
	ents, err := os.ReadDir(megaAbs)
	if err != nil {
		return nil, err
	}
	out := make([]string, 0, len(ents))
	for _, e := range ents {
		if !e.IsDir() || strings.HasPrefix(e.Name(), ".") {
			continue
		}
		out = append(out, e.Name())
	}
	sort.Strings(out)
	return out, nil
}

func buildUnionRowsSharded(megaAbs string, profiles []string, shardCount int) ([]unionRecord, error) {
	if shardCount < 1 {
		shardCount = 1
	}
	tmpDir := filepath.Join(megaAbs, ".recon_tmp")
	if err := os.MkdirAll(tmpDir, 0o755); err != nil {
		return nil, err
	}
	defer os.RemoveAll(tmpDir)

	type shardEntry struct {
		Profile string       `json:"profile"`
		Record  miningRecord `json:"record"`
	}
	type writer struct {
		f   *os.File
		bw  *bufio.Writer
		enc *json.Encoder
	}
	writers := make([]*writer, shardCount)
	openWriter := func(i int) (*writer, error) {
		if writers[i] != nil {
			return writers[i], nil
		}
		p := filepath.Join(tmpDir, fmt.Sprintf("shard_%04d.jsonl", i))
		f, err := os.Create(p)
		if err != nil {
			return nil, err
		}
		bw := bufio.NewWriterSize(f, 1024*1024)
		w := &writer{f: f, bw: bw, enc: json.NewEncoder(bw)}
		writers[i] = w
		return w, nil
	}

	for _, profile := range profiles {
		bestRunPath, err := bestRunQueuePath(megaAbs, profile)
		if err != nil {
			continue
		}
		if err := streamJSONL(bestRunPath, func(line string) error {
			var r miningRecord
			if err := json.Unmarshal([]byte(line), &r); err != nil {
				return err
			}
			key := strings.ToLower(r.Image + "|" + r.Address + "|" + r.Name)
			idx := shardIndex(key, shardCount)
			w, err := openWriter(idx)
			if err != nil {
				return err
			}
			return w.enc.Encode(shardEntry{Profile: profile, Record: r})
		}); err != nil {
			return nil, err
		}
	}
	for _, w := range writers {
		if w == nil {
			continue
		}
		if err := w.bw.Flush(); err != nil {
			return nil, err
		}
		if err := w.f.Close(); err != nil {
			return nil, err
		}
	}

	out := make([]unionRecord, 0, 4096)
	for i := 0; i < shardCount; i++ {
		p := filepath.Join(tmpDir, fmt.Sprintf("shard_%04d.jsonl", i))
		f, err := os.Open(p)
		if err != nil {
			if os.IsNotExist(err) {
				continue
			}
			return nil, err
		}
		s := bufio.NewScanner(f)
		s.Buffer(make([]byte, 4096), 8*1024*1024)
		union := make(map[string]unionRecord, 4096)
		for s.Scan() {
			line := strings.TrimSpace(s.Text())
			if line == "" {
				continue
			}
			var e shardEntry
			if err := json.Unmarshal([]byte(line), &e); err != nil {
				_ = f.Close()
				return nil, err
			}
			r := e.Record
			key := strings.ToLower(r.Image + "|" + r.Address + "|" + r.Name)
			cur, ok := union[key]
			if !ok {
				union[key] = unionRecord{
					miningRecord:   r,
					SeenInProfiles: []string{e.Profile},
					SeenCount:      1,
				}
				continue
			}
			if r.PriorityScore > cur.PriorityScore {
				cur.miningRecord = r
			}
			if !contains(cur.SeenInProfiles, e.Profile) {
				cur.SeenInProfiles = append(cur.SeenInProfiles, e.Profile)
				cur.SeenCount++
			}
			union[key] = cur
		}
		if err := s.Err(); err != nil {
			_ = f.Close()
			return nil, err
		}
		_ = f.Close()
		for _, r := range union {
			sort.Strings(r.SeenInProfiles)
			out = append(out, r)
		}
	}
	return out, nil
}

func bestRunQueuePath(megaAbs, profile string) (string, error) {
	runsDir := filepath.Join(megaAbs, profile, "runs")
	ents, err := os.ReadDir(runsDir)
	if err != nil {
		return "", err
	}
	bestPath := ""
	bestCount := -1
	for _, e := range ents {
		if !e.IsDir() {
			continue
		}
		summaryPath := filepath.Join(runsDir, e.Name(), "summary.json")
		b, err := os.ReadFile(summaryPath)
		if err != nil {
			continue
		}
		var s runSummary
		if err := json.Unmarshal(b, &s); err != nil {
			continue
		}
		if s.MiningQueueCount > bestCount {
			bestCount = s.MiningQueueCount
			bestPath = filepath.Join(runsDir, e.Name(), "mining_queue_full.jsonl")
		}
	}
	if bestPath == "" {
		return "", fmt.Errorf("no run queue found for profile %s", profile)
	}
	return bestPath, nil
}

func buildIDAJobs(idaDir string, rows []unionRecord, rootAbs, idatPath string) ([]idaJob, error) {
	group := map[string][]unionRecord{}
	for _, r := range rows {
		group[r.Image] = append(group[r.Image], r)
	}
	images := make([]string, 0, len(group))
	for img := range group {
		images = append(images, img)
	}
	sort.Strings(images)

	jobs := make([]idaJob, 0, len(images))
	for _, img := range images {
		recs := group[img]
		sort.Slice(recs, func(i, j int) bool {
			if recs[i].PriorityScore == recs[j].PriorityScore {
				return recs[i].Address < recs[j].Address
			}
			return recs[i].PriorityScore > recs[j].PriorityScore
		})
		addrPath := filepath.Join(idaDir, sanitizeName(img)+"_addresses.txt")
		f, err := os.Create(addrPath)
		if err != nil {
			return nil, err
		}
		bw := bufio.NewWriter(f)
		top := make([]string, 0, 12)
		for i, r := range recs {
			if _, err := bw.WriteString(r.Address + "\n"); err != nil {
				_ = f.Close()
				return nil, err
			}
			if i < 12 {
				top = append(top, r.Address)
			}
		}
		if err := bw.Flush(); err != nil {
			_ = f.Close()
			return nil, err
		}
		_ = f.Close()

		imagePath := filepath.Join(rootAbs, img)
		cmd := fmt.Sprintf("%s -A \"%s\"", shellQuote(idatPath), shellQuote(imagePath))
		jobs = append(jobs, idaJob{
			Image:        img,
			AddressCount: len(recs),
			AddressFile:  addrPath,
			IdatCommand:  cmd,
			TopAddresses: top,
		})
	}
	return jobs, nil
}

func streamJSONL(path string, onLine func(string) error) error {
	f, err := os.Open(path)
	if err != nil {
		return err
	}
	defer f.Close()
	s := bufio.NewScanner(f)
	s.Buffer(make([]byte, 4096), 8*1024*1024)
	for s.Scan() {
		line := strings.TrimSpace(s.Text())
		if line == "" {
			continue
		}
		if err := onLine(line); err != nil {
			return err
		}
	}
	return s.Err()
}

func writeJSON(path string, v any) error {
	b, err := json.MarshalIndent(v, "", "  ")
	if err != nil {
		return err
	}
	return os.WriteFile(path, append(b, '\n'), 0o644)
}

func writeJSONL[T any](path string, rows []T) error {
	f, err := os.Create(path)
	if err != nil {
		return err
	}
	defer f.Close()
	bw := bufio.NewWriter(f)
	enc := json.NewEncoder(bw)
	for _, row := range rows {
		if err := enc.Encode(row); err != nil {
			return err
		}
	}
	return bw.Flush()
}

func hasReason(reasons []string, want string) bool {
	for _, r := range reasons {
		if r == want {
			return true
		}
	}
	return false
}

func contains(items []string, v string) bool {
	for _, s := range items {
		if s == v {
			return true
		}
	}
	return false
}

func shardIndex(key string, shardCount int) int {
	h := fnv.New32a()
	_, _ = h.Write([]byte(key))
	return int(h.Sum32() % uint32(shardCount))
}

func sanitizeName(s string) string {
	s = strings.TrimSpace(strings.ToLower(s))
	if s == "" {
		return "image"
	}
	var b strings.Builder
	for _, r := range s {
		if (r >= 'a' && r <= 'z') || (r >= '0' && r <= '9') || r == '_' || r == '-' {
			b.WriteRune(r)
		} else {
			b.WriteByte('_')
		}
	}
	return strings.Trim(b.String(), "_")
}

func shellQuote(s string) string {
	if s == "" {
		return "''"
	}
	if !strings.ContainsAny(s, " \t\n'\"\\$`") {
		return s
	}
	return "'" + strings.ReplaceAll(s, "'", "'\"'\"'") + "'"
}

func fail(format string, args ...any) {
	fmt.Fprintf(os.Stderr, format+"\n", args...)
	os.Exit(1)
}
