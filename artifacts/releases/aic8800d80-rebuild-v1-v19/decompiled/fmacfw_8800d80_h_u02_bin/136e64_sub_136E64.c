// sub_136E64 @ 0x136e64, size 64 bytes
int __fastcall sub_136E64(int a1, unsigned __int16 *a2, int a3, __int16 a4)
{
  _BYTE *v5; // r4
  char *v6; // r0
  int v7; // r2

  v5 = (_BYTE *)sub_12C7EC(4104, a4, 4, 2u);
  sub_12EB90(8, dword_136EA4);
  v6 = (char *)off_136EA8;
  v7 = *a2;
  *(_WORD *)off_136EA8 = v7;
  sub_143630(v6 + 3, (char *)a2 + 3, v7);
  *v5 = 1;
  v5[1] = *((_BYTE *)a2 + 2);
  sub_12C84C((int)v5);
  return 0;
}

