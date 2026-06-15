// v23 annotated: variant_update_cache @ 0x100670
// Original: 100670_variant_update_cache.c
// Primary struct: <unclustered>
//
// variant_update_cache @ 0x100670, size 18 bytes
// Doc: variant_update_cache [util]: Update cached variant byte from result
// variant_update_cache [util]: Update cached variant byte from result
int __fastcall variant_update_cache(int a1)
{
  int result; // r0

  result = fw_init_setup(a1);
  if ( *(unsigned __int8 *)off_100684 != result )
    *(_BYTE *)off_100684 = result;
  return result;
}

