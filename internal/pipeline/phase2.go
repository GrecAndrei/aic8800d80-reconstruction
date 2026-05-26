package pipeline

import (
	"bytes"
	"encoding/binary"
	"encoding/hex"
	"encoding/json"
	"fmt"
	"os"
	"path/filepath"
	"runtime"
	"sort"
	"strconv"
	"strings"
	"sync"
)

type FunctionLinkRecord struct {
	SchemaVersion string  `json:"schema_version"`
	SourceImage   string  `json:"source_image"`
	SourceAddress string  `json:"source_address"`
	SourceName    string  `json:"source_name"`
	TargetImage   string  `json:"target_image"`
	TargetAddress string  `json:"target_address"`
	Method        string  `json:"method"`
	SignatureLen  int     `json:"signature_len"`
	Confidence    float64 `json:"confidence"`
	Evidence      string  `json:"evidence"`
}

type PatchEntryRecord struct {
	SchemaVersion string  `json:"schema_version"`
	Image         string  `json:"image"`
	SectionTag    string  `json:"section_tag"`
	SectionID     string  `json:"section_id"`
	EntryIndex    int     `json:"entry_index"`
	Address       string  `json:"address"`
	Value         string  `json:"value"`
	AddressKind   string  `json:"address_kind"`
	ValueKind     string  `json:"value_kind"`
	Confidence    float64 `json:"confidence"`
	Source        string  `json:"source"`
}

type patchSection struct {
	Tag      string
	Section  uint32
	Count    uint32
	StartOff int
	EndOff   int
}

func collectFunctionLinks(root string, functions []FunctionRecord, embeddingModel string, embedderCachePath string) ([]FunctionLinkRecord, error) {
	embedderClasses := loadEmbedderClasses(embedderCachePath)

	baseImage := primaryImageFromFunctions(functions)
	if baseImage == "" {
		return nil, nil
	}
	basePath := firstExistingPath(
		filepath.Join(root, baseImage),
		filepath.Join(root, "inputs", "firmware", baseImage),
	)
	baseData, err := os.ReadFile(basePath)
	if err != nil {
		return nil, fmt.Errorf("read base image %s: %w", baseImage, err)
	}

	targets, err := loadAlignmentTargets(root, basePath, baseData)
	if err != nil {
		return nil, err
	}
	if len(targets) == 0 {
		return nil, nil
	}

	seeds := make([]struct {
		Offset int
		Name   string
	}, 0, len(functions))
	for _, fn := range functions {
		if fn.Image != baseImage {
			continue
		}
		if fn.Confidence < 0.75 {
			continue
		}
		addr := normalizeToFileOffset(fn.Address)
		if addr < 0 || addr >= len(baseData)-24 {
			continue
		}
		name := strings.TrimSpace(fn.Name)
		if name == "" {
			continue
		}
		if strings.HasPrefix(name, "sub_") {
			continue
		}
		seeds = append(seeds, struct {
			Offset int
			Name   string
		}{Offset: addr, Name: name})
	}

	sort.Slice(seeds, func(i, j int) bool { return seeds[i].Offset < seeds[j].Offset })

	rows := make([]FunctionLinkRecord, 0, len(seeds)*len(targets))
	var rowsMu sync.Mutex
	type seedItem struct {
		index int
		off   int
		name  string
	}
	seedCh := make(chan seedItem)
	workers := runtime.NumCPU()
	if workers > len(seeds) {
		workers = len(seeds)
	}
	if workers < 1 {
		workers = 1
	}
	var wg sync.WaitGroup
	for w := 0; w < workers; w++ {
		wg.Add(1)
		go func() {
			defer wg.Done()
			localRows := make([]FunctionLinkRecord, 0, len(targets))
			for item := range seedCh {
				i := item.index
				symOffset := item.off
				symName := item.name
				nextOff := len(baseData)
				if i+1 < len(seeds) && seeds[i+1].Offset > symOffset {
					nextOff = seeds[i+1].Offset
				}
				window := nextOff - symOffset
				if window < 24 {
					window = 24
				}
				if window > 160 {
					window = 160
				}
				if symOffset+window > len(baseData) {
					window = len(baseData) - symOffset
				}
				if window < 24 {
					continue
				}

				candidates := signatureLengths(window)
				for _, tgt := range targets {
					for _, sigLen := range candidates {
						if symOffset+sigLen > len(baseData) {
							continue
						}
						sig := baseData[symOffset : symOffset+sigLen]
						if lowComplexity(sig) {
							continue
						}

						method := "byte_signature_unique"
						matches := findMatches(tgt.Data, sig, 2)
						if len(matches) != 1 {
							mask := branchMaskedSignature(sig)
							matches = findMaskedMatches(tgt.Data, sig, mask, 2)
							if len(matches) != 1 {
								continue
							}
							method = "byte_signature_masked_unique"
						}

						confidence := 0.78 + float64(sigLen)/512.0
						if confidence > 0.97 {
							confidence = 0.97
						}
						if embeddingModel != "" {
							if _, err := os.Stat(embeddingModel); err == nil {
								confidence += 0.01
							}
						}
						// Semantic boost: if embedder classified both source and target functions
						// into the same behavioral class, boost link confidence.
						if len(embedderClasses) > 0 {
							srcCls := lookupClass(embedderClasses, baseImage, fmt.Sprintf("0x%x", symOffset), symName)
							tgtCls := lookupClass(embedderClasses, tgt.Name, fmt.Sprintf("0x%x", matches[0]), "")
							if srcCls != "" && tgtCls != "" && srcCls == tgtCls {
								confidence += 0.06
							} else if srcCls != "" || tgtCls != "" {
								confidence += 0.02
							}
						}
						if method == "byte_signature_masked_unique" {
							confidence -= 0.05
						}
						if confidence > 0.98 {
							confidence = 0.98
						}
						if confidence < 0.65 {
							confidence = 0.65
						}

						localRows = append(localRows, FunctionLinkRecord{
							SchemaVersion: schemaVersion,
							SourceImage:   baseImage,
							SourceAddress: fmt.Sprintf("0x%x", symOffset),
							SourceName:    symName,
							TargetImage:   tgt.Name,
							TargetAddress: fmt.Sprintf("0x%x", matches[0]),
							Method:        method,
							SignatureLen:  sigLen,
							Confidence:    confidence,
							Evidence:      "sig=" + hex.EncodeToString(sig[:min(8, len(sig))]),
						})
						break
					}
				}
			}
			rowsMu.Lock()
			rows = append(rows, localRows...)
			rowsMu.Unlock()
		}()
	}
	for i, sym := range seeds {
		seedCh <- seedItem{index: i, off: sym.Offset, name: sym.Name}
	}
	close(seedCh)
	wg.Wait()

	sort.Slice(rows, func(i, j int) bool {
		if rows[i].SourceName == rows[j].SourceName {
			if rows[i].TargetImage == rows[j].TargetImage {
				return parseHex(rows[i].TargetAddress) < parseHex(rows[j].TargetAddress)
			}
			return rows[i].TargetImage < rows[j].TargetImage
		}
		return rows[i].SourceName < rows[j].SourceName
	})

	return dedupeFunctionLinks(rows), nil
}

func decodePatchEntries(patchTablePath string) ([]PatchEntryRecord, error) {
	b, err := os.ReadFile(patchTablePath)
	if err != nil {
		return nil, fmt.Errorf("read patch table: %w", err)
	}

	sections := parsePatchSections(b)
	rows := make([]PatchEntryRecord, 0, 8192)
	for _, sec := range sections {
		entryOff := sec.StartOff + 24
		for i := 0; i < int(sec.Count); i++ {
			off := entryOff + i*8
			if off+8 > len(b) {
				break
			}
			addr := binary.LittleEndian.Uint32(b[off : off+4])
			val := binary.LittleEndian.Uint32(b[off+4 : off+8])

			rows = append(rows, PatchEntryRecord{
				SchemaVersion: schemaVersion,
				Image:         filepath.Base(patchTablePath),
				SectionTag:    sec.Tag,
				SectionID:     fmt.Sprintf("0x%x", sec.Section),
				EntryIndex:    i,
				Address:       fmt.Sprintf("0x%08x", addr),
				Value:         fmt.Sprintf("0x%08x", val),
				AddressKind:   classifyAddress(addr),
				ValueKind:     classifyValue(val),
				Confidence:    patchEntryConfidence(sec.Tag, addr),
				Source:        "patch_table_section_decoder",
			})
		}
	}

	sort.Slice(rows, func(i, j int) bool {
		if rows[i].SectionTag == rows[j].SectionTag {
			return rows[i].EntryIndex < rows[j].EntryIndex
		}
		return rows[i].SectionTag < rows[j].SectionTag
	})

	return rows, nil
}

func loadSymbolDump(root string) (symbolDump, error) {
	path := filepath.Join(root, "extracted_kernel", "function_names.json")
	b, err := os.ReadFile(path)
	if err != nil {
		return symbolDump{}, fmt.Errorf("read function names: %w", err)
	}
	var dump symbolDump
	if err := json.Unmarshal(b, &dump); err != nil {
		return symbolDump{}, fmt.Errorf("parse function names json: %w", err)
	}
	if dump.Binary == "" {
		return symbolDump{}, fmt.Errorf("missing binary name in function_names.json")
	}
	return dump, nil
}

func loadAlignmentTargets(root string, basePath string, baseData []byte) ([]struct {
	Name string
	Data []byte
}, error) {
	paths := make([]string, 0, 16)
	seen := map[string]struct{}{}
	for _, pattern := range []string{
		filepath.Join(root, "*.bin"),
		filepath.Join(root, "inputs", "firmware", "*.bin"),
	} {
		matches, err := filepath.Glob(pattern)
		if err != nil {
			return nil, fmt.Errorf("glob images for alignment: %w", err)
		}
		for _, p := range matches {
			if _, ok := seen[p]; ok {
				continue
			}
			seen[p] = struct{}{}
			paths = append(paths, p)
		}
	}

	baseSP, baseRH := uint32(0), uint32(0)
	if len(baseData) >= 8 {
		baseSP = binary.LittleEndian.Uint32(baseData[:4])
		baseRH = binary.LittleEndian.Uint32(baseData[4:8])
	}

	targets := make([]struct {
		Name string
		Data []byte
	}, 0, 4)

	for _, p := range paths {
		if p == basePath {
			continue
		}
		name := filepath.Base(p)
		data, err := os.ReadFile(p)
		if err != nil {
			return nil, fmt.Errorf("read target image %s: %w", name, err)
		}
		if len(data) < 8 || len(data) < 128*1024 {
			continue
		}
		sp := binary.LittleEndian.Uint32(data[:4])
		rh := binary.LittleEndian.Uint32(data[4:8])
		if sp != baseSP || rh != baseRH {
			continue
		}
		targets = append(targets, struct {
			Name string
			Data []byte
		}{Name: name, Data: data})
	}

	return targets, nil
}

func signatureLengths(window int) []int {
	base := []int{96, 80, 64, 48, 40, 32, 24}
	seen := map[int]struct{}{}
	out := make([]int, 0, len(base)+1)
	if window > 24 {
		start := window
		if start > 96 {
			start = 96
		}
		if start >= 24 {
			seen[start] = struct{}{}
			out = append(out, start)
		}
	}
	for _, n := range base {
		if n > window {
			continue
		}
		if _, ok := seen[n]; ok {
			continue
		}
		seen[n] = struct{}{}
		out = append(out, n)
	}
	sort.Sort(sort.Reverse(sort.IntSlice(out)))
	return out
}

func lowComplexity(sig []byte) bool {
	seen := make(map[byte]struct{}, 16)
	for _, b := range sig {
		seen[b] = struct{}{}
		if len(seen) >= 6 {
			return false
		}
	}
	return true
}

func findMatches(hay []byte, needle []byte, max int) []int {
	if len(needle) == 0 || len(hay) < len(needle) {
		return nil
	}

	out := make([]int, 0, max)
	for start := 0; start <= len(hay)-len(needle); {
		idx := bytes.Index(hay[start:], needle)
		if idx < 0 {
			break
		}
		pos := start + idx
		out = append(out, pos)
		if len(out) >= max {
			break
		}
		start = pos + 1
	}
	return out
}

func branchMaskedSignature(sig []byte) []byte {
	mask := make([]byte, len(sig))
	for i := range mask {
		mask[i] = 0xFF
	}
	for i := 0; i+2 < len(sig); i += 2 {
		hw := binary.LittleEndian.Uint16(sig[i : i+2])
		op := hw >> 11
		if op == 0x1C || op == 0x1D {
			// Thumb B/BL-family: mask immediate bits to survive minor relocation.
			mask[i] = 0x00
			mask[i+1] = 0xF8
		}
	}
	return mask
}

func findMaskedMatches(hay []byte, needle []byte, mask []byte, max int) []int {
	if len(needle) == 0 || len(hay) < len(needle) || len(mask) != len(needle) {
		return nil
	}
	out := make([]int, 0, max)
	for pos := 0; pos <= len(hay)-len(needle); pos++ {
		ok := true
		for i := 0; i < len(needle); i++ {
			if (hay[pos+i] & mask[i]) != (needle[i] & mask[i]) {
				ok = false
				break
			}
		}
		if !ok {
			continue
		}
		out = append(out, pos)
		if len(out) >= max {
			break
		}
	}
	return out
}

func parsePatchSections(data []byte) []patchSection {
	sections := make([]patchSection, 0, 16)
	for off := 0; off+24 <= len(data); {
		idx := bytes.Index(data[off:], []byte("AICBT_"))
		if idx < 0 {
			break
		}
		start := off + idx
		if start+24 > len(data) {
			break
		}

		tag := parseCStr16(data[start : start+16])
		if !strings.HasPrefix(tag, "AICBT_") {
			off = start + 1
			continue
		}

		sectionID := binary.LittleEndian.Uint32(data[start+16 : start+20])
		count := binary.LittleEndian.Uint32(data[start+20 : start+24])
		end := start + 24 + int(count)*8
		if count == 0 || count > 100000 || end > len(data) {
			off = start + 1
			continue
		}

		sections = append(sections, patchSection{
			Tag:      tag,
			Section:  sectionID,
			Count:    count,
			StartOff: start,
			EndOff:   end,
		})
		off = end
	}

	return sections
}

func classifyAddress(addr uint32) string {
	switch {
	case addr >= 0x40000000 && addr < 0x50000000:
		return "mmio"
	case addr >= 0x20000000 && addr < 0x21000000:
		return "sram"
	case addr >= 0x00100000 && addr < 0x00300000:
		return "rom_window"
	default:
		return "word"
	}
}

func classifyValue(v uint32) string {
	if v >= 0x20000000 && v < 0x50000000 {
		return "pointer_like"
	}
	if v <= 0xFFFF {
		return "small_constant"
	}
	b := []byte{byte(v), byte(v >> 8), byte(v >> 16), byte(v >> 24)}
	if b[0] >= 0x20 && b[0] <= 0x7e && b[1] >= 0x20 && b[1] <= 0x7e && b[2] >= 0x20 && b[2] <= 0x7e {
		return "ascii_word"
	}
	return "word"
}

func patchEntryConfidence(tag string, addr uint32) float64 {
	conf := 0.72
	if strings.Contains(tag, "TRAP") || strings.Contains(tag, "PATCH") {
		conf += 0.1
	}
	switch classifyAddress(addr) {
	case "mmio", "sram", "rom_window":
		conf += 0.1
	}
	if conf > 0.96 {
		conf = 0.96
	}
	return conf
}

func parseCStr16(b []byte) string {
	n := bytes.IndexByte(b, 0)
	if n < 0 {
		n = len(b)
	}
	return string(b[:n])
}

func dedupeFunctionLinks(in []FunctionLinkRecord) []FunctionLinkRecord {
	m := make(map[string]FunctionLinkRecord, len(in))
	for _, r := range in {
		k := r.SourceImage + "|" + r.SourceAddress + "|" + r.TargetImage + "|" + r.TargetAddress
		old, ok := m[k]
		if !ok || r.Confidence > old.Confidence {
			m[k] = r
		}
	}
	out := make([]FunctionLinkRecord, 0, len(m))
	for _, r := range m {
		out = append(out, r)
	}
	return out
}

func normalizeToFileOffset(addr string) int {
	clean := strings.TrimSpace(strings.ToLower(addr))
	clean = strings.TrimPrefix(clean, "0x")
	v, err := strconv.ParseUint(clean, 16, 64)
	if err != nil {
		return -1
	}
	if v >= 0x100000 {
		v -= 0x100000
	}
	if v > uint64(^uint(0)>>1) {
		return -1
	}
	return int(v)
}

type embedderClassEntry struct {
	Classification struct {
		PrimaryClass string `json:"primary_class"`
	} `json:"classification"`
}

func loadEmbedderClasses(path string) map[string]string {
	if path == "" {
		return nil
	}
	b, err := os.ReadFile(path)
	if err != nil {
		return nil
	}
	var raw map[string]embedderClassEntry
	if err := json.Unmarshal(b, &raw); err != nil {
		return nil
	}
	out := make(map[string]string, len(raw))
	for k, v := range raw {
		if v.Classification.PrimaryClass != "" {
			out[k] = v.Classification.PrimaryClass
		}
	}
	return out
}

func lookupClass(classes map[string]string, image, addr, name string) string {
	n := strings.ToLower(strings.TrimSpace(name))
	img := strings.ToLower(strings.TrimSpace(image))
	a := strings.ToLower(strings.TrimSpace(addr))
	// Try image|address|name first
	if img != "" || a != "" {
		k := fmt.Sprintf("%s|%s|%s", img, a, n)
		if cls, ok := classes[k]; ok {
			return cls
		}
	}
	k := fmt.Sprintf("|%s", n)
	return classes[k]
}
