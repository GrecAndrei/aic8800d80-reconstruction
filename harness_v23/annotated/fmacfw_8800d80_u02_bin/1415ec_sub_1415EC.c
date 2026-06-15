// v23 annotated: sub_1415EC @ 0x1415ec
// Original: 1415ec_sub_1415EC.c
// Primary struct: <unclustered>
//
// sub_1415EC @ 0x1415ec, size 186 bytes
int sub_1415EC()
{
  __int16 **v0; // r8
  int v1; // r5
  int v2; // r4
  int v3; // r6
  int v4; // r7
  int result; // r0

  v0 = (__int16 **)off_1416BC;
  v1 = dword_1416A8;
  v2 = *(_DWORD *)(dword_1416A8 + 6480);
  if ( **(__int16 **)off_1416BC >= 0 || v2 < 0 && (result = sub_12F46C(dword_1416B8, dword_1416AC, 1734), **v0 >= 0) )
  {
    v3 = 16 * v2;
    if ( *(unsigned __int8 *)(v1 + 136 * v2 + 6339) > 1u )
      return result;
    return sub_140BEC(v1 + 8 * (v2 + v3) + 6336, 0);
  }
  v4 = v1 + 136 * v2;
  v3 = 16 * v2;
  if ( *(_BYTE *)(v4 + 6338) == 5 )
  {
    if ( *(unsigned __int8 *)(v4 + 6339) <= 1u )
      return sub_140BEC(v1 + 8 * (v2 + v3) + 6336, 0);
    return sub_12F46C(dword_1416B4, dword_1416AC, 1744);
  }
  result = sub_12F46C(dword_1416B0, dword_1416AC, 1735);
  if ( *(unsigned __int8 *)(v4 + 6339) <= 1u )
    return sub_140BEC(v1 + 8 * (v2 + v3) + 6336, 0);
  if ( **v0 < 0 )
    return sub_12F46C(dword_1416B4, dword_1416AC, 1744);
  return result;
}

