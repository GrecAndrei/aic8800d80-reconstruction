// v23 annotated: sub_135FD8 @ 0x135fd8
// Original: 135fd8_sub_135FD8.c
// Primary struct: <unclustered>
//
// sub_135FD8 @ 0x135fd8, size 68 bytes
// Doc: sub_1235FD8 [mac]: Indexed table lookup and field copy from 0x18fb08 base
// sub_1235FD8 [mac]: Indexed table lookup and field copy from 0x18fb08 base
int __fastcall sub_135FD8(int a1, unsigned __int8 *a2, __int16 a3, __int16 a4)
{
  unsigned __int16 v5; // r7
  _BYTE *v8; // r0

  v5 = *((_WORD *)a2 + 1);
  sub_143770(dword_13601C + (*a2 << 9), a2 + 4, v5);
  *(_WORD *)(dword_136020 + 2 * *a2) = v5;
  v8 = (_BYTE *)sub_12C92C(7177, a4, a3, 2u);
  *v8 = 1;
  v8[1] = *a2;
  sdio_buffer_prepare_n_4e8((int)v8);
  return 0;
}

