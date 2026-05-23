package main

import (
	"embed"
	"encoding/json"
	"flag"
	"fmt"
	"io/fs"
	"log"
	"net/http"
	"os"
	"path"
	"path/filepath"
	"sort"
	"strings"
	"sync"
	"time"

	"aic8800d80/internal/stats"
)

//go:embed static/*
var staticFS embed.FS

type dashboardState struct {
	mu      sync.RWMutex
	latest  stats.Snapshot
	history []stats.HistoryPoint
	sweep   map[string]any
	mega    map[string]any
	outDir  string
}

type dashboardPayload struct {
	stats.Snapshot
	Sweep map[string]any `json:"sweep,omitempty"`
	Mega  map[string]any `json:"mega,omitempty"`
}

func main() {
	var outDir string
	var addr string
	var interval time.Duration

	flag.StringVar(&outDir, "out", "extraction_out", "Extraction output directory")
	flag.StringVar(&addr, "addr", "127.0.0.1:8090", "HTTP listen address")
	flag.DurationVar(&interval, "interval", 2*time.Second, "Refresh interval for live stats")
	flag.Parse()

	state := &dashboardState{outDir: outDir}
	if err := state.refresh(); err != nil {
		log.Printf("initial refresh warning: %v", err)
	}

	go func() {
		t := time.NewTicker(interval)
		defer t.Stop()
		for range t.C {
			if err := state.refresh(); err != nil {
				log.Printf("refresh warning: %v", err)
			}
		}
	}()

	mux := http.NewServeMux()

	sub, err := fs.Sub(staticFS, "static")
	if err != nil {
		log.Fatalf("static fs: %v", err)
	}
	mux.Handle("/static/", http.StripPrefix("/static/", http.FileServer(http.FS(sub))))

	mux.HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {
		if r.URL.Path != "/" {
			http.NotFound(w, r)
			return
		}
		http.ServeFileFS(w, r, sub, "index.html")
	})

	mux.HandleFunc("/api/stats", func(w http.ResponseWriter, r *http.Request) {
		state.mu.RLock()
		payload := state.latest
		payload.History = state.history
		sweep := state.sweep
		mega := state.mega
		state.mu.RUnlock()
		writeJSON(w, dashboardPayload{Snapshot: payload, Sweep: sweep, Mega: mega})
	})

	mux.HandleFunc("/api/history", func(w http.ResponseWriter, r *http.Request) {
		state.mu.RLock()
		payload := state.history
		state.mu.RUnlock()
		writeJSON(w, payload)
	})

	mux.HandleFunc("/api/stats/stream", func(w http.ResponseWriter, r *http.Request) {
		w.Header().Set("Content-Type", "text/event-stream")
		w.Header().Set("Cache-Control", "no-cache")
		w.Header().Set("Connection", "keep-alive")

		flusher, ok := w.(http.Flusher)
		if !ok {
			http.Error(w, "streaming unsupported", http.StatusInternalServerError)
			return
		}

		ticker := time.NewTicker(interval)
		defer ticker.Stop()

		send := func() bool {
			state.mu.RLock()
			payload := state.latest
			payload.History = state.history
			sweep := state.sweep
			mega := state.mega
			state.mu.RUnlock()

			b, err := json.Marshal(dashboardPayload{Snapshot: payload, Sweep: sweep, Mega: mega})
			if err != nil {
				return false
			}
			if _, err := fmt.Fprintf(w, "event: stats\ndata: %s\n\n", b); err != nil {
				return false
			}
			flusher.Flush()
			return true
		}

		if !send() {
			return
		}

		for {
			select {
			case <-r.Context().Done():
				return
			case <-ticker.C:
				if !send() {
					return
				}
			}
		}
	})

	log.Printf("dashboard listening on http://%s%s", addr, path.Clean("/"))
	if err := http.ListenAndServe(addr, mux); err != nil {
		log.Fatalf("server error: %v", err)
	}
}

func (s *dashboardState) refresh() error {
	snap, err := stats.CollectAndPersist(s.outDir)
	if err != nil {
		return err
	}
	history, err := stats.ReadHistory(s.outDir, 300)
	if err != nil {
		return err
	}
	s.mu.Lock()
	s.latest = snap
	s.history = history
	s.sweep = readLatestSweepSummary(s.outDir)
	s.mega = readLatestMegaSummary(s.outDir)
	s.mu.Unlock()
	return nil
}

func readLatestSweepSummary(outDir string) map[string]any {
	sweepsDir := filepath.Join(outDir, "sweeps")
	entries, err := os.ReadDir(sweepsDir)
	if err != nil {
		return nil
	}
	type cand struct {
		path string
		mod  time.Time
	}
	cands := make([]cand, 0, len(entries))
	for _, e := range entries {
		if e.IsDir() || filepath.Ext(e.Name()) != ".json" || len(e.Name()) < len("_summary.json") || e.Name()[len(e.Name())-len("_summary.json"):] != "_summary.json" {
			continue
		}
		p := filepath.Join(sweepsDir, e.Name())
		st, err := os.Stat(p)
		if err != nil {
			continue
		}
		cands = append(cands, cand{path: p, mod: st.ModTime()})
	}
	if len(cands) == 0 {
		return nil
	}
	sort.Slice(cands, func(i, j int) bool { return cands[i].mod.After(cands[j].mod) })
	b, err := os.ReadFile(cands[0].path)
	if err != nil {
		return nil
	}
	var m map[string]any
	if err := json.Unmarshal(b, &m); err != nil {
		return nil
	}
	m["summary_path"] = cands[0].path
	return m
}

func readLatestMegaSummary(outDir string) map[string]any {
	entries, err := os.ReadDir(outDir)
	if err != nil {
		return nil
	}
	type cand struct {
		path string
		mod  time.Time
	}
	cands := make([]cand, 0, len(entries))
	for _, e := range entries {
		if !e.IsDir() {
			continue
		}
		name := e.Name()
		if name != "mega" && !strings.HasPrefix(name, "mega") {
			continue
		}
		p := filepath.Join(outDir, name, "latest_mega_summary.json")
		st, se := os.Stat(p)
		if se != nil {
			continue
		}
		cands = append(cands, cand{path: p, mod: st.ModTime()})
	}
	if len(cands) == 0 {
		return nil
	}
	sort.Slice(cands, func(i, j int) bool { return cands[i].mod.After(cands[j].mod) })
	b, err := os.ReadFile(cands[0].path)
	if err != nil {
		return nil
	}
	var m map[string]any
	if err := json.Unmarshal(b, &m); err != nil {
		return nil
	}
	m["summary_path"] = cands[0].path
	return m
}

func writeJSON(w http.ResponseWriter, v any) {
	w.Header().Set("Content-Type", "application/json")
	enc := json.NewEncoder(w)
	enc.SetIndent("", "  ")
	if err := enc.Encode(v); err != nil {
		http.Error(w, err.Error(), http.StatusInternalServerError)
	}
}
