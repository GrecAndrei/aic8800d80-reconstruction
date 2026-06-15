// v23 annotated: sub_125904 @ 0x125904
// Original: 125904_sub_125904.c
// Primary struct: <unclustered>
//
// sub_125904 @ 0x125904, size 66 bytes
int __fastcall sub_125904(int a1)
{
  int v2; // r0
  _BYTE *v3; // r2
  int v4; // r1
  int v5; // r4
  int v6; // r0
  int v7; // r6

  v2 = *(unsigned __int8 *)(a1 + 9);
  v3 = off_125950;
  v4 = dword_125954;
  v5 = dword_125948 + 1320 * v2;
  v6 = dword_12594C + 620 * v2;
  v7 = *(unsigned __int8 *)(v5 + 107);
  *((_BYTE *)off_125950 + 9) = 1;
  v3[10] = 0;
  sub_143630(v6 + 108, v4 + (v7 << 9), *(unsigned __int16 *)(a1 + 4));
  return sub_1258A0(v5);
}

