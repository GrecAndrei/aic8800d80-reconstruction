// sub_13376C @ 0x13376c, size 68 bytes
_DWORD *__fastcall sub_13376C(int a1)
{
  int v1; // r5
  unsigned int v2; // r2
  _DWORD *v4; // r0
  int *v5; // r1

  v1 = *(_DWORD *)(a1 + 8);
  v2 = *(unsigned __int8 *)(a1 + 12);
  if ( **(__int16 **)off_1337B0 < 0 && v2 > 3 )
  {
    sub_12F46C(dword_1337B8, dword_1337B4, 321);
    LOBYTE(v2) = *(_BYTE *)(a1 + 12);
  }
  v4 = sub_1335B0((_DWORD *)a1, (int *)(a1 + 4), (90 << (8 * v2)) | v1);
  return sub_1335B0(v4, v5, 0);
}

