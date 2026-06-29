// sub_125C88 @ 0x125c88, size 70 bytes
BOOL  sub_125C88(int a1, int a2)
{
  int v3; // r4
  int v4; // r0
  int v5; // r5
  int v6; // r6
  int v7; // r0

  v3 = *(uint32_t *)(a1 + 4);
  v4 = sub_101944();
  v5 = *(uint32_t *)(a2 + 4);
  v6 = v4;
  v7 = sub_101944();
  return v3 - v5 < 0 && v5 - 14000 - v3 - v6 < 0 || v5 - v3 < 0 && v3 - v5 - 14000 - v7 < 0 || v3 == v5;
}

