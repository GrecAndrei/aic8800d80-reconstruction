// fwstruct annotate: 13bd84_sub_13BD84.c
// sub_13BD84 @ 0x13bd84, size 108 bytes
int __fastcall sub_13BD84(int result)
{
  int v1; // r4
  int v2; // r5
  int v3; // r10
  int v4; // r7
  __int16 v5; // r9
  int v6; // r6
  int v7; // t1

  v1 = dword_13BDF0;
  v2 = dword_13BDF4;
  v3 = dword_13BDF8;
  v4 = result;
  v5 = -128 * dword_13BDF0;
  v6 = dword_13BDF0 + 64;
  do
  {
    v7 = *(unsigned __int16 *)(v1 + 2);
    v1 += 2;
    if ( v7 )
    {
      if ( *(unsigned __int8 *)(v2 + 16) == v4 )
      {
        rf_bus_mark_n_3b7((unsigned __int16)(v5 + ((_WORD)v1 << 7) - 256) | 8, 4);
        *(_BYTE *)(v2 + 25) = 0;
        result = rf_bus_write_n_25c(v4, v2, 2, 0, 0, 39, v3);
      }
    }
    v2 += 32;
  }
  while ( v1 != v6 );
  return result;
}

