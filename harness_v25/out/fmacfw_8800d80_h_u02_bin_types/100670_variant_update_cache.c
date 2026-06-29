// variant_update_cache @ 0x100670, size 18 bytes
int  variant_update_cache(int a1)
{
  int result; // r0

  result = sub_1005B0(a1);
  if ( *(unsigned __int8 *)off_100684 != result )
    *(uint8_t *)off_100684 = result;
  return result;
}

