// sub_119D18 @ 0x119d18, size 58 bytes
int __fastcall sub_119D18(int a1, unsigned __int8 *a2, int a3, int a4)
{
  int v4; // r5
  int v6; // r6
  int v7; // r0
  int v8; // r5
  int v9; // r1
  int v10; // r4

  v4 = dword_119D54;
  v6 = 7 * *a2;
  v7 = rf_setup_dispatch(47, a4, a3, 2);
  v8 = v4 + 32 * v6;
  v9 = (char)a2[1];
  v10 = v7;
  sub_11DA5C(v8, v9);
  sub_11DA3C(v8, v10 + 1, v10);
  sub_11DE50(v10);
  return 0;
}

