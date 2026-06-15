// v23 annotated: sub_125D98 @ 0x125d98
// Original: 125d98_sub_125D98.c
// Primary struct: <unclustered>
//
// sub_125D98 @ 0x125d98, size 42 bytes
int __fastcall sub_125D98(int a1)
{
  _BYTE *v2; // r0
  _DWORD *v3; // r2

  v2 = (_BYTE *)sub_12C92C(72, *(unsigned __int16 *)(a1 + 14), 0, 2);
  v2[1] = *(_BYTE *)(a1 + 24);
  v3 = off_125DC4;
  *v2 = *(_BYTE *)(a1 + 26);
  *v3 &= ~4u;
  return sdio_buffer_prepare_n_4e8(v2);
}

