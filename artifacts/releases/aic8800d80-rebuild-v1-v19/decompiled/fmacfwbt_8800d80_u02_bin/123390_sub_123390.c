// sub_123390 @ 0x123390, size 50 bytes
int __fastcall sub_123390(int a1, int a2, int a3, int a4)
{
  _BYTE *v4; // r4
  int v5; // r1
  int v6; // r3

  v4 = (_BYTE *)sub_12CB54(129, a4, a3, 64);
  v5 = dword_1233C4;
  *v4 = 0;
  sub_14380C(v4 + 1, v5, 36);
  v6 = (unsigned __int8)(*v4 + 36);
  *v4 = v6;
  v4[v6 + 1] = 0;
  sub_12CBB4(v4);
  return 0;
}

