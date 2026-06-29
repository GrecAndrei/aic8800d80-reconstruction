// fwstruct annotate: 1392f4_sub_1392F4.c
// sub_1392F4 @ 0x1392f4, size 66 bytes
_DWORD **__fastcall sub_1392F4(int a1, int a2)
{
  _DWORD **result; // r0
  unsigned int v3; // r2
  int v4; // r1
  int v5; // r3
  __int16 v6; // r1

  result = *(_DWORD ***)(dword_139338 + 4 * (174 * a1 + (*(unsigned __int16 *)(a2 + 16) >> 12) + 102));
  if ( result )
  {
    v3 = *(unsigned __int16 *)(a2 + 18);
    v4 = *((unsigned __int16 *)result + 4);
    if ( v4 != v3 >> 4 )
    {
      v5 = (v3 >> 4) - v4;
      v6 = (v3 >> 4) - v4;
      if ( (v5 & 0x800) == 0 )
      {
        sub_1392A8((int)result, v6 & 0xFFF);
        return sub_12F554((_DWORD **)dword_13933C);
      }
    }
  }
  return result;
}

