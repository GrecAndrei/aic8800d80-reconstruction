// v23 annotated: sub_133988 @ 0x133988
// Original: 133988_sub_133988.c
// Primary struct: <unclustered>
//
// sub_133988 @ 0x133988, size 68 bytes
_DWORD *__fastcall sub_133988(int a1)
{
  int v1; // r5
  unsigned int v2; // r2
  _DWORD *v4; // r0
  int *v5; // r1

  v1 = *(_DWORD *)(a1 + 8);
  v2 = *(unsigned __int8 *)(a1 + 12);
  if ( **(__int16 **)off_1339CC < 0 && v2 > 3 )
  {
    sub_12F694(dword_1339D4, dword_1339D0, 321);
    LOBYTE(v2) = *(_BYTE *)(a1 + 12);
  }
  v4 = xtea_block_decrypt((_DWORD *)a1, (int *)(a1 + 4), (90 << (8 * v2)) | v1);
  return xtea_block_decrypt(v4, v5, 0);
}

