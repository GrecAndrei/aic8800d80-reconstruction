// sub_12ADC8 @ 0x12adc8, size 30 bytes
int __fastcall sub_12ADC8(int a1, int a2, int a3)
{
  int v3; // r3
  unsigned int v4; // r2
  int result; // r0

  v3 = dword_12ADE8;
  v4 = (unsigned int)(1967 * a2 * a3) >> 16;
  result = dword_12ADE8 + 32 * a1;
  if ( v4 )
    *(_DWORD *)(result + 24) = v4;
  else
    v3 = 1;
  if ( !v4 )
    *(_DWORD *)(result + 24) = v3;
  return result;
}

