// sub_102A58 @ 0x102a58, size 96 bytes
int sub_102A58()
{
  uint32_t *v0; // r2
  uint8_t *v1; // r3
  int v3; // r4
  int v4; // r5
  int v5; // r6
  int v6; // r5
  int v7; // r6
  void *v8; // r4

  v0 = off_102AB8;
  v1 = off_102ABC;
  *(uint32_t *)(*((uint32_t *)off_102AB8 + 2) + 80) = dword_102AC0;
  *(uint32_t *)v1 = 16;
  v3 = dword_102AC4;
  *(uint32_t *)(v0[2] + 84) = dword_102AC4;
  *(uint32_t *)v1 = 32;
  v4 = dword_102AC8;
  *(uint32_t *)(v0[2] + 92) = v3;
  *(uint32_t *)v1 = 128;
  v5 = dword_102ACC;
  *(uint32_t *)(v0[2] + 72) = v4;
  *(uint32_t *)v1 = 4;
  v6 = dword_102AD0;
  *(uint32_t *)(v0[2] + 88) = v5;
  *(uint32_t *)v1 = 64;
  v7 = dword_102AD4;
  *(uint32_t *)(v0[2] + 76) = v6;
  v1[771] = -8;
  *(uint32_t *)v1 = 8;
  v8 = off_102AD8;
  *(uint32_t *)(v0[2] + 208) = v7;
  *((uint32_t *)v1 + 1) = 16;
  *(uint32_t *)(v0[2] + 212) = v8;
  *((uint32_t *)v1 + 1) = 32;
  __enable_irq();
  return 16;
}

