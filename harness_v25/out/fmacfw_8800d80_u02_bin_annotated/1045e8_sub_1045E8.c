// fwstruct annotate: 1045e8_sub_1045E8.c
// sub_1045E8 @ 0x1045e8, size 48 bytes
int __fastcall sub_1045E8(int a1, int a2, _DWORD *a3)
{
  int v3; // r2
  unsigned int v4; // r0
  int v5; // r3

  v3 = a3[rf_bus_reset_0(a1, a2, a3)];
  v4 = (unsigned int)v3 >> 20;
  v5 = (unsigned __int16)v3 >> 4;
  if ( v3 < 0 )
    v4 -= 4096;
  if ( (((unsigned int)v3 >> 4) & 0x800) != 0 )
    v5 -= 4096;
  return v5 * v5 + v4 * v4;
}

