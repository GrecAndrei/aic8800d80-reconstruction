// sub_135E98 @ 0x135e98, size 68 bytes
int __fastcall sub_135E98(int a1, unsigned __int8 *a2, __int16 a3, __int16 a4)
{
  unsigned __int16 v5; // r7
  _BYTE *v8; // r0

  v5 = *((_WORD *)a2 + 1);
  sub_143630(dword_135EDC + (*a2 << 9), a2 + 4, v5);
  *(_WORD *)(dword_135EE0 + 2 * *a2) = v5;
  v8 = (_BYTE *)sub_12C7EC(7177, a4, a3, 2u);
  *v8 = 1;
  v8[1] = *a2;
  sub_12C84C((int)v8);
  return 0;
}

