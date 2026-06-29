// fwstruct annotate: 138378_sub_138378.c
// sub_138378 @ 0x138378, size 98 bytes
_BYTE *__fastcall sub_138378(unsigned __int8 *a1)
{
  _BYTE *v1; // r4
  _BYTE *v3; // r8
  int v4; // r6
  int v5; // r5
  unsigned __int8 *v6; // r9
  int v7; // r2

  if ( !*a1 )
    return (_BYTE *)*a1;
  v1 = (_BYTE *)dword_1383DC;
  v3 = nullptr;
  v4 = dword_1383DC + 3840;
  v5 = -128;
  v6 = a1 + 1;
  while ( v1[8] )
  {
    if ( (char)v1[64] <= v5 || (v7 = *a1, v7 != (unsigned __int8)v1[16]) || sub_1437AC(v1 + 17, v6, v7) )
    {
      v1 += 60;
      if ( v1 == (_BYTE *)v4 )
        return v3;
    }
    else
    {
      v5 = (char)v1[64];
      v3 = v1 + 8;
      v1 += 60;
      if ( v1 == (_BYTE *)v4 )
        return v3;
    }
  }
  return v3;
}

