// variant_update_cache @ 0x100670, size 18 bytes
// Doc: variant_update_cache [util]: Update cached variant byte from result
// variant_update_cache [util]: Update cached variant byte from result
int  variant_update_cache(int a1)
{
  int result; // r0

  result = fw_init_setup(a1);
  if ( *(unsigned __int8 *)off_100684 != result )
    *(uint8_t *)off_100684 = result;
  return result;
}

