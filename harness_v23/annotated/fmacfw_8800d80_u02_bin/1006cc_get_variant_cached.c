// v23 annotated: get_variant_cached @ 0x1006cc
// Original: 1006cc_get_variant_cached.c
// Primary struct: <unclustered>
//
// get_variant_cached @ 0x1006cc, size 6 bytes
// Doc: get_variant_cached [util]: Return cached silicon variant byte from global table at offset 1
// get_variant_cached [util]: Return cached silicon variant byte from global table at offset 1
int get_variant_cached()
{
  return *((unsigned __int8 *)off_1006D4 + 1);
}

