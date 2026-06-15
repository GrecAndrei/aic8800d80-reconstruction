// sub_11AD88 @ 0x11ad88, size 70 bytes
// Doc: sub_121AD88 [unknown]: Resolve two symbol pointers and compute difference between resolved addresses
// sub_121AD88 [unknown]: Resolve two symbol pointers and compute difference between resolved addresses
BOOL __fastcall sub_11AD88(int a1, int a2)
{
  int v3; // r4
  int v4; // r0
  int v5; // r5
  int v6; // r6
  int v7; // r0

  v3 = *(_DWORD *)(a1 + 4);
  v4 = sub_101A20();
  v5 = *(_DWORD *)(a2 + 4);
  v6 = v4;
  v7 = sub_101A20();
  return v3 - v5 < 0 && v5 - 14000 - v3 - v6 < 0 || v5 - v3 < 0 && v3 - v5 - 14000 - v7 < 0 || v3 == v5;
}

