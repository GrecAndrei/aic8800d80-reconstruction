// log_free_pool_dispatch2_n324 @ 0x107068, size 212 bytes
// Doc: log_free_pool_dispatch2_n324 [util]: Initializes log entry and dispatches to free-pool handler
// log_free_pool_dispatch2_n324 [util]: Initializes log entry and dispatches to free-pool handler
int  log_free_pool_dispatch2_n324(int a1, int a2)
{
  uint32_t *v2; // r5
  unsigned int *v3; // r4
  uint32_t *v5; // r2
  int v6; // r1
  int v7; // r2
  unsigned int v8; // r3
  int v9; // r2
  int v10; // r3
  int result; // r0

  v2 = off_10713C;
  v3 = (unsigned int *)off_107140;
  *(uint32_t *)off_10713C |= 4u;
  *v2 |= 8u;
  *v3 |= 0x1000000u;
  *v3 = (a2 << 25) & 0x2000000 | *v3 & 0xFDFFFFFF;
  *v3 |= 0x400000u;
  *v3 |= 0x800000u;
  *v3 |= 0x200000u;
  *v3 |= 0x100000u;
  crypto_hw_clear_regs();
  *v2 &= ~1u;
  delay_us(100);
  v5 = off_107144;
  v6 = dword_107148;
  *v3 |= 0x4000000u;
  v7 = *v5 & 0x7FFF;
  v8 = *v3 & 0xFBFFFFFF;
  *v3 = v8;
  *(uint32_t *)(a1 + 44) = v7;
  sub_11F74C(1, v6, v7, v8);
  delay_us(5);
  result = sub_11F74C(1, dword_10714C, v9, v10);
  *v3 &= ~0x1000000u;
  *v3 &= ~0x2000000u;
  *v2 &= ~4u;
  *v2 &= ~8u;
  *v3 &= ~0x400000u;
  *v3 &= ~0x800000u;
  *v3 &= ~0x200000u;
  *v3 &= ~0x100000u;
  return result;
}

