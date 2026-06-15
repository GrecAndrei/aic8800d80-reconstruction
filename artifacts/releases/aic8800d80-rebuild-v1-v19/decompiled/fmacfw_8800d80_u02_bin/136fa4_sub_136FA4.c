// sub_136FA4 @ 0x136fa4, size 64 bytes
int __fastcall sub_136FA4(int a1, unsigned __int16 *a2, int a3, __int16 a4)
{
  _BYTE *v5; // r4
  char *v6; // r0
  int v7; // r2

  v5 = (_BYTE *)sub_12C92C(4104, a4, 4, 2u);
  feature_guard_check(8, dword_136FE4);
  v6 = (char *)off_136FE8;
  v7 = *a2;
  *(_WORD *)off_136FE8 = v7;
  sub_143770(v6 + 3, (char *)a2 + 3, v7);
  *v5 = 1;
  v5[1] = *((_BYTE *)a2 + 2);
  sdio_buffer_prepare_n_4e8((int)v5);
  return 0;
}

