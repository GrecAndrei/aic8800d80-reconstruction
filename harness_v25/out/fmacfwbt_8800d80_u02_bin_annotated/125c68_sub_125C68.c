// fwstruct annotate: 125c68_sub_125C68.c
// sub_125C68 @ 0x125c68, size 66 bytes
// Doc: sub_1225C68 [util]: Initializes a data structure from global tables
// sub_1225C68 [util]: Initializes a data structure from global tables
int __fastcall sub_125C68(int a1)
{
  int v2; // r0
  _BYTE *v3; // r2
  int v4; // r1
  int v5; // r4
  int v6; // r0
  int v7; // r6
  int v8; // r2
  int v9; // r3

  v2 = *(unsigned __int8 *)(a1 + 9);
  v3 = off_125CB4;
  v4 = dword_125CB8;
  v5 = dword_125CAC + 1320 * v2;
  v6 = dword_125CB0 + 620 * v2;
  v7 = *(unsigned __int8 *)(v5 + 107);
  *((_BYTE *)off_125CB4 + 9) = 1;
  v3[10] = 0;
  sub_14380C(v6 + 108, v4 + (v7 << 9), *(unsigned __int16 *)(a1 + 4));
  return sub_125C04(v5, 0, v8, v9);
}

