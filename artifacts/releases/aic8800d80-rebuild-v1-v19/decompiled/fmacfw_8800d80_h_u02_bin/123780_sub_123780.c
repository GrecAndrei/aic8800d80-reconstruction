// sub_123780 @ 0x123780, size 60 bytes
int __fastcall sub_123780(int a1, unsigned __int8 *a2, int a3, int a4)
{
  int v4; // r5
  int v6; // r0
  int v7; // r4

  v4 = dword_1237BC + 1320 * *a2;
  v6 = sub_12C7EC(47, a4, a3, 2);
  *(_BYTE *)(v4 + 110) = a2[1];
  v7 = v6;
  sub_12C444(v4);
  sub_12C388(v4, v7 + 1, v7);
  sub_12C84C(v7);
  return 0;
}

