// sub_10FFF0 @ 0x10fff0, size 122 bytes
// Doc: log_free_pool_dispatch2_n460 [util]: Dispatch log entry into free pool with metadata fields
// log_free_pool_dispatch2_n460 [util]: Dispatch log entry into free pool with metadata fields
int sub_10FFF0()
{
  void *v0; // r4
  int v1; // r3
  uint32_t *v2; // r0
  __int16 v3; // r2
  __int16 v4; // r1
  uint64_t v5; // kr00_8
  uint16_t v7[2]; // [sp+4h] [bp-14h] BYREF
  uint16_t v8[8]; // [sp+8h] [bp-10h] BYREF

  v0 = log_free_pool_dispatch2_n49c;
  v1 = *(uint32_t *)log_free_pool_dispatch2_n49c;
  v2 = off_110074;
  v3 = *((uint16_t *)off_110070 + 153);
  v4 = *((uint16_t *)off_110070 + 154) - 4;
  v7[1] = *(uint16_t *)(*(uint32_t *)log_free_pool_dispatch2_n49c + 2);
  v8[1] = *(uint16_t *)(v1 + 4);
  v8[5] = *(uint16_t *)(v1 + 6);
  v8[7] = *(uint16_t *)(v1 + 8);
  v5 = *(QWORD *)(v1 + 20);
  *(uint32_t *)off_110074 = v5;
  v2[3] = dword_110078;
  v2[1] = HIDWORD(v5);
  *((uint8_t *)v2 + 8) = 1;
  v8[2] = v4;
  v8[6] = v3 - 4;
  v7[0] = 12;
  v8[4] = 1596;
  v8[0] = 124;
  v8[3] = 0;
  sub_10F814(v2, (int)v7, 0x20u);
  return rf_init_setup_n3ac((int)v8, *(uint32_t *)(*(uint32_t *)v0 + 28), *(uint32_t *)(*(uint32_t *)v0 + 32));
}

