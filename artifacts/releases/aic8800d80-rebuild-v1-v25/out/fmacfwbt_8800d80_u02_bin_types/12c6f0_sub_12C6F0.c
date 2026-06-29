// sub_12C6F0 @ 0x12c6f0, size 26 bytes
int  sub_12C6F0(int a1, uint8_t *a2, uint8_t *a3)
{
  int v3; // r3
  int result; // r0

  v3 = *(char *)(a1 + 109);
  if ( v3 == 127 )
    result = *(uint32_t *)off_12C70C;
  else
    result = (unsigned __int8)v3;
  if ( v3 == 127 )
    result = (unsigned __int8)result;
  if ( a2 )
    *a2 = v3;
  if ( a3 )
    *a3 = result;
  return result;
}

