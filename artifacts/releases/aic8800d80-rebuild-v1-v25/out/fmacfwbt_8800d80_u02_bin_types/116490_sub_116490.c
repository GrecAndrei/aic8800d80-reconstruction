// sub_116490 @ 0x116490, size 56 bytes
int  sub_116490(int a1)
{
  int v1; // r1
  int v2; // r3
  int result; // r0

  v1 = dword_1164C8;
  v2 = dword_1164C8 + 36 * a1;
  *(uint32_t *)v2 = 0;
  result = v1 + 8 * (a1 + 22);
  *(uint32_t *)(v2 + 8) = 4978;
  *(uint32_t *)(v2 + 12) = -1;
  *(uint32_t *)(result + 4) = 0;
  *(uint32_t *)(result + 8) = 0;
  *(uint32_t *)(v2 + 4) = 0;
  *(uint8_t *)(v2 + 32) = 0;
  *(uint32_t *)(v2 + 20) = 0;
  *(uint32_t *)(v2 + 16) = -1;
  return result;
}

