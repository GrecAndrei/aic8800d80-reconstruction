package structs

import (
	"testing"

	"aic8800d80/internal/decompile"
)

func TestBuildClusters(t *testing.T) {
	// Two funcs, both access v3+0x4 and v3+0x8
	// They should cluster together
	funcs := []*decompile.Func{
		{Address: 0x100200, Name: "func1", Accesses: []decompile.Access{
			{Base: "v3", Offset: 0x4, Size: 4, Direction: "store"},
			{Base: "v3", Offset: 0x8, Size: 4, Direction: "load"},
		}},
		{Address: 0x100300, Name: "func2", Accesses: []decompile.Access{
			{Base: "v3", Offset: 0x4, Size: 4, Direction: "store"},
			{Base: "v3", Offset: 0x8, Size: 4, Direction: "load"},
		}},
		{Address: 0x100400, Name: "func3", Accesses: []decompile.Access{
			{Base: "v3", Offset: 0x10, Size: 4, Direction: "store"}, // different offset
		}},
	}
	clusters, f2c, n := BuildClusters("test", funcs)
	if n != 3 {
		t.Errorf("clustered count = %d, want 3", n)
	}
	if len(clusters) != 2 {
		t.Errorf("clusters = %d, want 2 (func1+func2 share fp, func3 different)", len(clusters))
	}
	// Both func1 and func2 should be in the same cluster
	c1, ok := f2c[0x100200]
	if !ok {
		t.Fatal("func1 not in cluster map")
	}
	c2, ok := f2c[0x100300]
	if !ok {
		t.Fatal("func2 not in cluster map")
	}
	if c1 != c2 {
		t.Errorf("func1 and func2 should be in same cluster, got %d vs %d", c1, c2)
	}
}
