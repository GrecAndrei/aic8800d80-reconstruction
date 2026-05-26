package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func addrKey(img, addr string) string {
	return strings.ToLower(strings.TrimSpace(img)) + "|" + strings.ToLower(strings.TrimSpace(addr))
}

func addrVariants(addr string) []string {
	a := strings.ToLower(strings.TrimSpace(addr))
	if a == "" {
		return nil
	}
	out := []string{a}
	if strings.HasPrefix(a, "0x") {
		if v, err := strconv.ParseUint(strings.TrimPrefix(a, "0x"), 16, 64); err == nil {
			if v >= 0x120000 {
				out = append(out, fmt.Sprintf("0x%x", v-0x120000))
			}
			if v < 0x200000 {
				out = append(out, fmt.Sprintf("0x%x", v+0x120000))
			}
		}
	}
	return dedupeStrings(out)
}

func aliasFunctionNames(n string) []string {
	n = sanitizeName(n)
	if n == "" || n == "unknown" {
		return nil
	}
	out := []string{n}
	if strings.HasPrefix(n, "sub_") {
		hexp := strings.TrimPrefix(n, "sub_")
		if v, err := strconv.ParseUint(hexp, 16, 64); err == nil && v >= 0x120000 {
			out = append(out, fmt.Sprintf("sub_%x", v-0x120000))
		}
	}
	return dedupeStrings(out)
}

func dedupeStrings(in []string) []string {
	seen := map[string]struct{}{}
	out := make([]string, 0, len(in))
	for _, s := range in {
		s = strings.TrimSpace(s)
		if s == "" {
			continue
		}
		if _, ok := seen[s]; ok {
			continue
		}
		seen[s] = struct{}{}
		out = append(out, s)
	}
	return out
}

func existingEdgePaths(paths ...string) []string {
	out := make([]string, 0, len(paths))
	seen := map[string]struct{}{}
	for _, p := range paths {
		p = strings.TrimSpace(p)
		if p == "" {
			continue
		}
		if _, ok := seen[p]; ok {
			continue
		}
		if _, err := os.Stat(p); err == nil {
			seen[p] = struct{}{}
			out = append(out, p)
		}
	}
	return out
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

func fail(format string, args ...any) {
	fmt.Fprintf(os.Stderr, format+"\n", args...)
	os.Exit(1)
}
