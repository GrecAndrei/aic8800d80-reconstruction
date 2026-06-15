// sub_1314CC @ 0x1314cc, size 38 bytes
// Doc: sub_12314CC [util]: Thin wrapper that calls helper at 0x12e1a8 preserving r2 as r4
// sub_12314CC [util]: Thin wrapper that calls helper at 0x12e1a8 preserving r2 as r4
unsigned __int8 *__fastcall sub_1314CC(unsigned __int8 *a1, int a2, _BYTE *a3)
{
  unsigned __int8 *result; // r0
  unsigned int v5; // r3

  result = sdio_buffer_prepare_alt_1a8(a1, a2);
  if ( result )
  {
    v5 = result[3];
    *a3 = v5 & 7;
    a3[1] = (v5 >> 3) & 7;
    return (unsigned __int8 *)1;
  }
  else
  {
    *a3 = 3;
    a3[1] = 5;
  }
  return result;
}

