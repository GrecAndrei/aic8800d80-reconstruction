// fwstruct annotate: 13f03c_sub_13F03C.c
// sub_13F03C @ 0x13f03c, size 174 bytes
int __fastcall sub_13F03C(int a1, unsigned int a2, unsigned int a3)
{
  __int16 **v3; // r8
  int v4; // r3
  int result; // r0
  _BYTE *v7; // r4
  __int16 *v10; // r3

  v3 = (__int16 **)off_13F100;
  v4 = dword_13F0EC + 696 * a1;
  result = **(__int16 **)off_13F100;
  v7 = *(_BYTE **)(v4 + 340);
  if ( result < 0 && !v7 )
    result = sub_12F32C(dword_13F0F4, dword_13F0F0, 3326);
  if ( (unsigned __int8)v7[179] != a2 || (unsigned __int8)v7[180] != a3 )
  {
    v10 = *v3;
    v7[179] = a2;
    if ( *v10 < 0 && a2 > 3 )
    {
      result = sub_12F32C(dword_13F0FC, dword_13F0F0, 3332);
      v10 = *v3;
    }
    v7[180] = a3;
    if ( *v10 < 0 && a3 > 7 )
      result = sub_12F32C(dword_13F0F8, dword_13F0F0, 3334);
    if ( (v7[166] & 0x20) != 0 )
      v7[166] |= 0x80u;
    else
      return sub_13EF7C(a1);
  }
  return result;
}

