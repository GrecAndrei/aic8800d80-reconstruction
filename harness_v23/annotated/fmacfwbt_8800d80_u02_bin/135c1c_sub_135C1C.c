// v23 annotated: sub_135C1C @ 0x135c1c
// Original: 135c1c_sub_135C1C.c
// Primary struct: <unclustered>
//
// sub_135C1C @ 0x135c1c, size 124 bytes
_DWORD *__fastcall sub_135C1C(unsigned __int16 *a1)
{
  unsigned __int16 *v1; // r6
  int v3; // r5
  _DWORD *result; // r0
  int v5; // r3
  int v6; // r3

  v1 = a1 + 6;
  sub_12C964(6154, 6);
  v3 = v1[2];
  result = (_DWORD *)sub_12EEF8(256, dword_135C98, v3);
  if ( v3 )
    return (_DWORD *)sub_135020(v3);
  v5 = a1[6];
  if ( !a1[6] )
    return sub_135580();
  if ( v5 != 1 )
  {
    if ( v5 == 2 )
      return (_DWORD *)sub_135B94(*((_BYTE *)a1 + 8), (int)(a1 + 9), (unsigned __int16)(*a1 - 6));
    return result;
  }
  v6 = v1[1];
  if ( v6 == 4 )
  {
    sub_103140(3000);
    return sub_135580();
  }
  if ( v6 == 2 && *a1 > 0x22u )
    return sub_135384(3, (char *)a1 + 20);
  return result;
}

