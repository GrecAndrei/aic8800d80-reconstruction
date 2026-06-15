// Package structs recovers struct types from function access patterns.
//
// The recovery pipeline:
//  1. For each function, find its "primary struct arg" - the register
//     (r0-r3) with the most accesses through it. This is the "this" pointer.
//  2. Build a fingerprint: list of (offset, size) tuples accessed via the
//     primary arg. Same fingerprint = same struct.
//  3. Cluster functions by fingerprint. A cluster = a struct usage site.
//  4. For each cluster, generate struct proposal: name, field list.
//  5. Cross-reference: for each struct field, find all readers/writers.
//
// The primary-arg heuristic is "most-accessed argument register" - r0-r3 in
// the AAPCS calling convention are the first 4 arguments, with r0 usually
// holding the return value or the implicit "this".
package structs

import (
	"crypto/sha1"
	"encoding/hex"
	"fmt"
	"sort"
	"strings"

	"aic8800d80/internal/decompile"
)

// AccessKey identifies a (base, offset, size) tuple. Used as a field key.
type AccessKey struct {
	Base   string
	Offset int
	Size   int
}

func (k AccessKey) String() string {
	return fmt.Sprintf("%s+0x%x/%d", k.Base, k.Offset, k.Size)
}

// Cluster represents a group of functions that all touch the same struct
// fields in the same way.
type Cluster struct {
	ID         int                `json:"id"`
	GroupID    int                `json:"group_id"`
	Image      string             `json:"image"`
	Name       string             `json:"name,omitempty"`
	PrimaryArg string             `json:"primary_arg"`
	Fingerprint []AccessKey       `json:"fingerprint"`
	FPHash     string             `json:"fp_hash"`
	Funcs      []uint32           `json:"funcs"`
	Fields     map[string]int     `json:"fields,omitempty"` // name -> offset
	FieldSizes map[string]int     `json:"field_sizes,omitempty"` // name -> size
	Confidence float64            `json:"confidence"`
}

// FuncCluster maps a function address to its cluster.
type FuncCluster struct {
	Image     string `json:"image"`
	Address   uint32 `json:"address"`
	ClusterID int    `json:"cluster_id"`
	GroupID   int    `json:"group_id"`
}

// BuildClusters groups funcs in an image by primary-arg access fingerprint.
//
// Returns the list of clusters, a map from (image, addr) -> cluster_id, and
// the number of funcs that were clustered (i.e., had a primary arg).
func BuildClusters(image string, funcs []*decompile.Func) ([]*Cluster, map[uint32]int, int) {
	// For each func, find primary arg and build fingerprint
	type fp struct {
		primary string
		keys    []AccessKey
	}
	fps := make(map[uint32]fp, len(funcs))
	for _, fn := range funcs {
		primary, keys := PrimaryArgFingerprint(fn)
		if primary == "" {
			continue
		}
		fps[fn.Address] = fp{primary, keys}
	}

	// Group by fingerprint
	groupMap := map[string][]uint32{}
	groupInfo := map[string]fp{}
	for addr, f := range fps {
		// Hash the fingerprint
		parts := make([]string, len(f.keys))
		for i, k := range f.keys {
			parts[i] = k.String()
		}
		// Include primary arg in hash so r0-struct and r1-struct don't collide
		key := f.primary + "|" + strings.Join(parts, ",")
		h := sha1.Sum([]byte(key))
		hh := hex.EncodeToString(h[:8])
		groupMap[hh] = append(groupMap[hh], addr)
		groupInfo[hh] = f
	}

	// Sort group IDs
	hashes := make([]string, 0, len(groupMap))
	for h := range groupMap {
		hashes = append(hashes, h)
	}
	sort.Slice(hashes, func(i, j int) bool {
		return len(groupMap[hashes[i]]) > len(groupMap[hashes[j]])
	})

	clusters := make([]*Cluster, 0, len(hashes))
	funcToCluster := map[uint32]int{}
	for i, h := range hashes {
		addrs := groupMap[h]
		sort.Slice(addrs, func(i, j int) bool { return addrs[i] < addrs[j] })
		info := groupInfo[h]
		// Confidence = number of funcs * fingerprint_specificity
		// (more funcs with same fp = higher confidence)
		conf := float64(len(addrs)) * float64(len(info.keys))
		clusters = append(clusters, &Cluster{
			ID:          i,
			GroupID:     i,
			Image:       image,
			PrimaryArg:  info.primary,
			Fingerprint: info.keys,
			FPHash:      h,
			Funcs:       addrs,
			Confidence:  conf,
		})
		for _, a := range addrs {
			funcToCluster[a] = i
		}
	}

	return clusters, funcToCluster, len(fps)
}

// PrimaryArgFingerprint finds the primary struct arg of a function and
// returns the (offset, size) tuples accessed through it.
//
// Heuristic: among r0-r3, pick the one with the most accesses. If r0 is
// the only one with accesses, use it. If none have accesses, return "".
func PrimaryArgFingerprint(fn *decompile.Func) (string, []AccessKey) {
	// Count accesses per base
	baseCount := map[string]int{}
	baseAccesses := map[string][]AccessKey{}
	for _, a := range fn.Accesses {
		if !isArgReg(a.Base) {
			continue
		}
		baseCount[a.Base]++
		baseAccesses[a.Base] = append(baseAccesses[a.Base], AccessKey{
			Base:   a.Base,
			Offset: a.Offset,
			Size:   a.Size,
		})
	}
	if len(baseCount) == 0 {
		return "", nil
	}
	// Pick the arg reg with most accesses
	var best string
	bestN := 0
	for b, n := range baseCount {
		if n > bestN || (n == bestN && argOrder(b) < argOrder(best)) {
			best, bestN = b, n
		}
	}
	if best == "" {
		return "", nil
	}
	keys := baseAccesses[best]
	sort.Slice(keys, func(i, j int) bool {
		if keys[i].Offset != keys[j].Offset {
			return keys[i].Offset < keys[j].Offset
		}
		return keys[i].Size < keys[j].Size
	})
	// Dedup
	dedup := keys[:0]
	seen := map[AccessKey]struct{}{}
	for _, k := range keys {
		if _, ok := seen[k]; ok {
			continue
		}
		seen[k] = struct{}{}
		dedup = append(dedup, k)
	}
	return best, dedup
}



// FieldAccess counts read/write per field across all funcs in a cluster.
type FieldAccess struct {
	Name       string         `json:"name"`
	Offset     int            `json:"offset"`
	Size       int            `json:"size"`
	Reads      int            `json:"reads"`
	Writes     int            `json:"writes"`
	Readers    map[uint32]int `json:"readers,omitempty"`
	Writers    map[uint32]int `json:"writers,omitempty"`
	ReadFuncs  []uint32       `json:"read_funcs,omitempty"`
	WriteFuncs []uint32       `json:"write_funcs,omitempty"`
}
// BuildFieldXref computes, for a cluster, per-field read/write stats.
//
// For each field, count:
//   - read/write occurrences
//   - unique readers/writers
//   - top readers/writers by count
func BuildFieldXref(cluster *Cluster, funcs []*decompile.Func) map[string]*FieldAccess {
	funcMap := map[uint32]*decompile.Func{}
	for _, fn := range funcs {
		funcMap[fn.Address] = fn
	}
	// First, generate field names from offsets (in the order they appear in the
	// fingerprint). The LLM will later propose better names.
	fields := map[int]string{} // offset -> name
	for i, k := range cluster.Fingerprint {
		fields[k.Offset] = fmt.Sprintf("field_%d_0x%x", i, k.Offset)
	}
	xref := map[string]*FieldAccess{}
	for _, fa := range cluster.Fingerprint {
		name := fields[fa.Offset]
		xref[name] = &FieldAccess{
			Name:    name,
			Offset:  fa.Offset,
			Size:    fa.Size,
			Readers: map[uint32]int{},
			Writers: map[uint32]int{},
		}
	}
	for _, addr := range cluster.Funcs {
		fn, ok := funcMap[addr]
		if !ok {
			continue
		}
		for _, a := range fn.Accesses {
			if a.Base != cluster.PrimaryArg {
				continue
			}
			name, ok := fields[a.Offset]
			if !ok {
				continue
			}
			fa, ok := xref[name]
			if !ok {
				continue
			}
			if a.Direction == "load" {
				fa.Reads++
				fa.Readers[addr]++
			} else {
				fa.Writes++
				fa.Writers[addr]++
			}
		}
	}
	for _, fa := range xref {
		readers := topN(fa.Readers, 10)
		fa.ReadFuncs = make([]uint32, 0, len(readers))
		for _, addr := range readers {
			fa.ReadFuncs = append(fa.ReadFuncs, addr)
		}
		sort.Slice(fa.ReadFuncs, func(i, j int) bool { return fa.ReadFuncs[i] < fa.ReadFuncs[j] })
		writers := topN(fa.Writers, 10)
		fa.WriteFuncs = make([]uint32, 0, len(writers))
		for _, addr := range writers {
			fa.WriteFuncs = append(fa.WriteFuncs, addr)
		}
		sort.Slice(fa.WriteFuncs, func(i, j int) bool { return fa.WriteFuncs[i] < fa.WriteFuncs[j] })
		fa.Readers = nil
		fa.Writers = nil
	}
	return xref
}

func topN(m map[uint32]int, n int) []uint32 {
	out := make([]uint32, 0, len(m))
	for k := range m {
		if len(out) >= n {
			break
		}
		out = append(out, k)
	}
	return out
}
