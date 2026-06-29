// fwstruct annotate: 100670_variant_update_cache.c
// variant_update_cache @ 0x100670, size 18 bytes
int __fastcall variant_update_cache(int a1)
{
  int result; // r0

  result = sub_1005B0(a1);
  if ( *(unsigned __int8 *)off_100684 != result )
    *(_BYTE *)off_100684 = result;
  return result;
}

