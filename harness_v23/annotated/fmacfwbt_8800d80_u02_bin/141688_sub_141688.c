// v23 annotated: sub_141688 @ 0x141688
// Original: 141688_sub_141688.c
// Primary struct: <unclustered>
//
// sub_141688 @ 0x141688, size 186 bytes
int sub_141688()
{
  __int16 **v0; // r8
  int v1; // r5
  int v2; // r4
  int v3; // r6
  int v4; // r7
  int result; // r0

  v0 = (__int16 **)off_141758;
  v1 = dword_141744;
  v2 = *(_DWORD *)(dword_141744 + 6480);
  if ( **(__int16 **)off_141758 >= 0 || v2 < 0 && (result = sub_12F694(dword_141754, dword_141748, 1734), **v0 >= 0) )
  {
    v3 = 16 * v2;
    if ( *(unsigned __int8 *)(v1 + 136 * v2 + 6339) > 1u )
      return result;
    return sub_140C88(v1 + 8 * (v2 + v3) + 6336, 0);
  }
  v4 = v1 + 136 * v2;
  v3 = 16 * v2;
  if ( *(_BYTE *)(v4 + 6338) == 5 )
  {
    if ( *(unsigned __int8 *)(v4 + 6339) <= 1u )
      return sub_140C88(v1 + 8 * (v2 + v3) + 6336, 0);
    return sub_12F694(dword_141750, dword_141748, 1744);
  }
  result = sub_12F694(dword_14174C, dword_141748, 1735);
  if ( *(unsigned __int8 *)(v4 + 6339) <= 1u )
    return sub_140C88(v1 + 8 * (v2 + v3) + 6336, 0);
  if ( **v0 < 0 )
    return sub_12F694(dword_141750, dword_141748, 1744);
  return result;
}

