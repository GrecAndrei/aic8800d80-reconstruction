package decompile

import (
	"os"
	"strings"
	"testing"
)

const sampleC = `// sub_100200 @ 0x100200, size 84 bytes
int __fastcall sub_100200(int result, unsigned __int8 a2, unsigned int a3)
{
  int v3;
  unsigned int v4;
  if ( a3 >= 0x10 )
  {
    v3 = result;
    v4 = a3 >> 2;
    do
    {
      *(_DWORD *)(v3 + 0x4) = 0x12345678;
      v3 += 4;
      --v4;
    }
    while ( v4 );
    return result;
  }
  return sub_100300(result, a2, a3);
}
`

func TestParseFile(t *testing.T) {
	tmp := t.TempDir() + "/100200_sub_100200.c"
	if err := os.WriteFile(tmp, []byte(sampleC), 0644); err != nil {
		t.Fatal(err)
	}
	fn, err := ParseFile("testimg", tmp)
	if err != nil {
		t.Fatal(err)
	}
	if fn.Name != "sub_100200" {
		t.Errorf("name = %q want sub_100200", fn.Name)
	}
	if fn.Address != 0x100200 {
		t.Errorf("addr = %x want 100200", fn.Address)
	}
	hasSub100300 := false
	for _, c := range fn.Callees {
		if c == "sub_100300" {
			hasSub100300 = true
		}
	}
	if !hasSub100300 {
		t.Errorf("expected sub_100300 in callees, got %v", fn.Callees)
	}
	found := false
	for _, a := range fn.Accesses {
		if a.Base == "v3" && a.Offset == 0x4 {
			found = true
			if a.Direction != "store" {
				t.Errorf("expected store, got %s", a.Direction)
			}
		}
	}
	if !found {
		t.Errorf("expected access v3+0x4 store, got %+v", fn.Accesses)
	}
	has1234 := false
	for _, l := range fn.Literals {
		if strings.Contains(l, "12345678") {
			has1234 = true
		}
	}
	if !has1234 {
		t.Errorf("expected 0x12345678 in literals, got %v", fn.Literals)
	}
}

func TestParseFileStoreVsLoad(t *testing.T) {
	// Test that "result = *(_DWORD *)v3" is a load, not a store
	tmp := t.TempDir() + "/100200_sub_100200.c"
	body := `int sub_100200(int v3)
{
  int v4 = *(_DWORD *)v3;
  *(_DWORD *)v3 = v4;
  return 0;
}
`
	if err := os.WriteFile(tmp, []byte(body), 0644); err != nil {
		t.Fatal(err)
	}
	fn, err := ParseFile("testimg", tmp)
	if err != nil {
		t.Fatal(err)
	}
	loadCount := 0
	storeCount := 0
	for _, a := range fn.Accesses {
		if a.Base == "v3" && a.Offset == 0 {
			if a.Direction == "load" {
				loadCount++
			} else {
				storeCount++
			}
		}
	}
	if loadCount != 1 {
		t.Errorf("loadCount = %d, want 1", loadCount)
	}
	if storeCount != 1 {
		t.Errorf("storeCount = %d, want 1", storeCount)
	}
}
