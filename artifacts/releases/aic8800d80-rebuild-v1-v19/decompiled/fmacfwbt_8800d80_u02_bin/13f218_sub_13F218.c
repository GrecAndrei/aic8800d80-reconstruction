// sub_13F218 @ 0x13f218, size 174 bytes
int __fastcall sub_13F218(int a1, unsigned int a2, unsigned int a3)
{
  __int16 **v3; // r8
  int v4; // r3
  int result; // r0
  _BYTE *v7; // r4
  __int16 *v10; // r3

  v3 = (__int16 **)off_13F2DC;
  v4 = dword_13F2C8 + 696 * a1;
  result = **(__int16 **)off_13F2DC;
  v7 = *(_BYTE **)(v4 + 340);
  if ( result < 0 && !v7 )
    result = sub_12F694(dword_13F2D0, dword_13F2CC, 3326);
  if ( (unsigned __int8)v7[179] != a2 || (unsigned __int8)v7[180] != a3 )
  {
    v10 = *v3;
    v7[179] = a2;
    if ( *v10 < 0 && a2 > 3 )
    {
      result = sub_12F694(dword_13F2D8, dword_13F2CC, 3332);
      v10 = *v3;
    }
    v7[180] = a3;
    if ( *v10 < 0 && a3 > 7 )
      result = sub_12F694(dword_13F2D4, dword_13F2CC, 3334);
    if ( (v7[166] & 0x20) != 0 )
      v7[166] |= 0x80u;
    else
      return sub_13F158(a1);
  }
  return result;
}

