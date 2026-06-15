// variant_update_cache @ 0x100670, size 18 bytes
// Doc: variant_update_cache [util]: Update cached variant byte if changed by callee
// variant_update_cache [util]: Update cached variant byte if changed by callee
int __fastcall variant_update_cache(int a1)
{
  int result; // r0

  result = sub_1005B0(a1);
  if ( *(unsigned __int8 *)off_100684 != result )
    *(_BYTE *)off_100684 = result;
  return result;
}

