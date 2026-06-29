// sub_1152D8 @ 0x1152d8, size 56 bytes
uint64_t  sub_1152D8(int a1)
{
  int v1; // r1
  int v2; // r3
  int v3; // r5
  int v4; // r0
  int v5; // r3
  int v6; // r4

  v1 = dword_115310;
  v2 = 9 * a1;
  v3 = 36 * a1;
  v4 = a1 + 18;
  v5 = dword_115310 + 4 * v2;
  v6 = dword_115310 + 8 * v4;
  *(uint32_t *)(dword_115310 + v3) = 0;
  *(uint32_t *)(v1 + 8 * v4) = 0;
  *(uint32_t *)(v6 + 4) = 0;
  *(QWORD *)(v5 + 8) = -4294966370LL;
  *(uint32_t *)(v5 + 4) = 0;
  *(uint8_t *)(v5 + 32) = 0;
  *(uint32_t *)(v5 + 20) = 0;
  *(uint32_t *)(v5 + 16) = -1;
  return -4294966370LL;
}

