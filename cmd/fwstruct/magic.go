package main

import (
	"flag"
	"fmt"
	"path/filepath"
	"os"
	"sort"

	"aic8800d80/internal/decompile"
	"aic8800d80/internal/fileio"
)

// runMagic classifies numeric literals found in decompiled C.
//
// Categories:
//   mmio       - 0x40000000-0x60000000 (MMIO register address)
//   data       - 0x100000-0x200000 (data segment)
//   bit_mask   - 0xFF, 0x1F, 0xFFFF, etc. (looks like bit pattern)
//   small      - 1-100 (count/index)
//   timer_freq - common timer frequencies (1000, 32768, 32000, etc.)
//   power      - powers of 2
//   all_ones   - 0xFFFFFFFF (-1)
//   medium     - 0x10000-0x100000
//   high       - 0x10000000-0x40000000
//   other      - unclassified
func runMagic(args []string) error {
	fs := flag.NewFlagSet("magic", flag.ContinueOnError)
	var cf commonFlags
	cf.Register(fs)
	var mmioPath string
	fs.StringVar(&mmioPath, "mmio", "", "MMIO database (default <root>/harness_v19/mmio_registers.json)")
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
	if mmioPath == "" {
		mmioPath = filepath.Join(cf.Root, "harness_v19", "mmio_registers.json")
	}
	mmio := loadMMIO(mmioPath)
	cf.VPrintf("magic: %d images, %d MMIO regs", len(images), len(mmio))

	timerFreqs := map[int]bool{1000: true, 3125: true, 31250: true, 32000: true, 32768: true,
		100000: true, 1000000: true, 8000000: true, 16000000: true, 24000000: true,
		40000000: true, 48000000: true}

	for _, img := range images {
		funcs, err := loadFuncs(cf.Out, img)
		if err != nil {
			fmt.Fprintf(os.Stderr, "  %s: %v\n", img, err)
			continue
		}
		// Aggregate
		type litInfo struct {
			Category   string
			Count      int
			SampleFuncs []string
		}
		allLits := map[string]*litInfo{} // hex -> info
		allDec := map[string]*litInfo{} // dec -> info
		for _, fn := range funcs {
			seenThis := map[string]bool{}
			for _, lit := range fn.Literals {
				key := lit
				if seenThis[key] {
					continue
				}
				seenThis[key] = true
				val, ok := parseLiteral(lit)
				if !ok || val == 0 {
					continue
				}
				cat := classify(val, mmio, timerFreqs)
				bucket := allLits
				if !isHex(lit) {
					bucket = allDec
				}
				info, ok := bucket[key]
				if !ok {
					info = &litInfo{Category: cat}
					bucket[key] = info
				}
				info.Count++
				if len(info.SampleFuncs) < 3 {
					info.SampleFuncs = append(info.SampleFuncs, fn.Name)
				}
			}
		}
		// Build report
		type litRow struct {
			Literal    string   `json:"literal"`
			Category   string   `json:"category"`
			Count      int      `json:"count"`
			SampleFuncs []string `json:"sample_funcs"`
		}
		var rows []litRow
		for k, v := range allLits {
			rows = append(rows, litRow{Literal: k, Category: v.Category, Count: v.Count, SampleFuncs: v.SampleFuncs})
		}
		for k, v := range allDec {
			rows = append(rows, litRow{Literal: k, Category: v.Category, Count: v.Count, SampleFuncs: v.SampleFuncs})
		}
		sort.Slice(rows, func(i, j int) bool {
			if rows[i].Count != rows[j].Count {
				return rows[i].Count > rows[j].Count
			}
			return rows[i].Literal < rows[j].Literal
		})
		report := struct {
			Image  string   `json:"image"`
			Total  int      `json:"total_literals"`
			ByCat  map[string]int `json:"by_category"`
			Top    []litRow `json:"top_100"`
		}{
			Image: img,
			Total: len(rows),
		}
		report.ByCat = map[string]int{}
		for _, r := range rows {
			report.ByCat[r.Category] += r.Count
		}
		if len(rows) > 100 {
			report.Top = rows[:100]
		} else {
			report.Top = rows
		}
		outPath := filepath.Join(cf.Out, img+"_magic.json")
		if err := fileio.WriteJSON(outPath, report); err != nil {
			return err
		}
		cf.VPrintf("  %s: %d literals, %d categories", img, report.Total, len(report.ByCat))
	}
	return nil
}

func isHex(s string) bool {
	return len(s) > 2 && (s[:2] == "0x" || s[:2] == "0X")
}

func parseLiteral(s string) (int64, bool) {
	s = stripSuffix(s)
	if isHex(s) {
		var v int64
		for i := 2; i < len(s); i++ {
			c := s[i]
			var d int64
			switch {
			case c >= '0' && c <= '9':
				d = int64(c - '0')
			case c >= 'a' && c <= 'f':
				d = int64(c-'a') + 10
			case c >= 'A' && c <= 'F':
				d = int64(c-'A') + 10
			default:
				return 0, false
			}
			v = v*16 + d
		}
		return v, true
	}
	var v int64
	for i := 0; i < len(s); i++ {
		c := s[i]
		if c < '0' || c > '9' {
			return 0, false
		}
		v = v*10 + int64(c-'0')
	}
	return v, true
}

func stripSuffix(s string) string {
	for len(s) > 0 {
		c := s[len(s)-1]
		if c == 'u' || c == 'U' || c == 'l' || c == 'L' {
			s = s[:len(s)-1]
		} else {
			break
		}
	}
	return s
}

func classify(v int64, mmio map[uint32]string, timerFreqs map[int]bool) string {
	if v < 0 {
		return "negative"
	}
	if v < 0x100 {
		return "small"
	}
	if v >= 0x40000000 && v < 0x60000000 {
		if name, ok := mmio[uint32(v)]; ok {
			return "mmio/" + name
		}
		return "mmio_unknown"
	}
	if v >= 0x100000 && v < 0x200000 {
		return "data_addr"
	}
	if timerFreqs[int(v)] {
		return "timer_freq"
	}
	if v > 0 && (v&(v+1)) == 0 {
		return "bit_mask"
	}
	if v == 0xFFFFFFFF {
		return "all_ones"
	}
	if v >= 0x10000 && v < 0x100000 {
		return "medium"
	}
	if v >= 0x10000000 && v < 0x40000000 {
		return "high"
	}
	return "other"
}

func loadMMIO(path string) map[uint32]string {
	out := map[uint32]string{}
	if path == "" {
		return out
	}
	// Try nested format first
	var nested map[string]map[string]string
	if err := readJSON(path, &nested); err == nil {
		for page, regs := range nested {
			var p uint64
			fmt.Sscanf(page, "%x", &p)
			for offset, name := range regs {
				var o uint64
				fmt.Sscanf(offset, "%x", &o)
				out[uint32(p*0x10000+o)] = name
			}
		}
		return out
	}
	// Try flat format
	var flat map[string]string
	if err := readJSON(path, &flat); err == nil {
		for k, v := range flat {
			var addr uint64
			fmt.Sscanf(k, "%x", &addr)
			out[uint32(addr)] = v
		}
	}
	return out
}

// silence "imported and not used" if we end up not using decompile directly
var _ = decompile.Func{}
