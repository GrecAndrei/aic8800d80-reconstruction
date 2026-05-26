package fileio

import (
	"bufio"
	"encoding/json"
	"fmt"
	"os"
	"path/filepath"
	"strings"
)

func WriteJSONL[T any](path string, rows []T) error {
	f, err := openAtomicWriter(path)
	if err != nil {
		return err
	}
	defer f.Close()

	bw := bufio.NewWriter(f)
	enc := json.NewEncoder(bw)
	for _, row := range rows {
		if err := enc.Encode(row); err != nil {
			return fmt.Errorf("encode %s: %w", path, err)
		}
	}
	if err := bw.Flush(); err != nil {
		return fmt.Errorf("flush %s: %w", path, err)
	}
	return commitAtomicWriter(path, f)
}

func WriteJSON(path string, v any) error {
	b, err := json.MarshalIndent(v, "", "  ")
	if err != nil {
		return fmt.Errorf("marshal json %s: %w", path, err)
	}
	b = append(b, '\n')
	return WriteBytes(path, b)
}

func WriteBytes(path string, b []byte) error {
	f, err := openAtomicWriter(path)
	if err != nil {
		return err
	}
	defer f.Close()
	if _, err := f.Write(b); err != nil {
		return fmt.Errorf("write %s: %w", path, err)
	}
	return commitAtomicWriter(path, f)
}

func ReadJSONL[T any](path string) ([]T, error) {
	f, err := os.Open(path)
	if err != nil {
		return nil, err
	}
	defer f.Close()
	out := make([]T, 0, 256)
	s := bufio.NewScanner(f)
	s.Buffer(make([]byte, 1024), 4*1024*1024)
	for s.Scan() {
		line := strings.TrimSpace(s.Text())
		if line == "" {
			continue
		}
		var t T
		if err := json.Unmarshal([]byte(line), &t); err != nil {
			return nil, err
		}
		out = append(out, t)
	}
	if err := s.Err(); err != nil {
		return nil, err
	}
	return out, nil
}

func openAtomicWriter(path string) (*os.File, error) {
	dir := filepath.Dir(path)
	if err := os.MkdirAll(dir, 0o755); err != nil {
		return nil, fmt.Errorf("create dir %s: %w", dir, err)
	}
	tmp, err := os.CreateTemp(dir, ".tmp-*")
	if err != nil {
		return nil, fmt.Errorf("create temp for %s: %w", path, err)
	}
	return tmp, nil
}

func commitAtomicWriter(path string, f *os.File) error {
	tmpName := f.Name()
	if err := f.Sync(); err != nil {
		_ = os.Remove(tmpName)
		return fmt.Errorf("sync temp for %s: %w", path, err)
	}
	if err := f.Close(); err != nil {
		_ = os.Remove(tmpName)
		return fmt.Errorf("close temp for %s: %w", path, err)
	}
	if err := os.Rename(tmpName, path); err != nil {
		_ = os.Remove(tmpName)
		return fmt.Errorf("rename temp to %s: %w", path, err)
	}
	return nil
}
