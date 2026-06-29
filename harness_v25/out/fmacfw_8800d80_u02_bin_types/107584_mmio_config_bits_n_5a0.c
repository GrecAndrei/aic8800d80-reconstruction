// mmio_config_bits_n_5a0 @ 0x107584, size 222 bytes
// Doc: mmio_config_bits_n_5a0 [mmio]: Configure MMIO register bit field using bic/orr mask pattern
// mmio_config_bits_n_5a0 [mmio]: Configure MMIO register bit field using bic/orr mask pattern
int  mmio_config_bits_n_5a0(int a1, int a2)
{
  unsigned int *v2; // r5
  unsigned int *v3; // r4
  uint32_t *v5; // r2
  int v6; // r3
  int result; // r0

  v2 = (unsigned int *)off_107664;
  v3 = (unsigned int *)off_107668;
  *(uint32_t *)off_107664 = *(uint32_t *)off_107664 & 0xFFFFFF8F | 0x50;
  *v2 &= ~4u;
  *v2 &= ~8u;
  *v3 |= 0x400000u;
  *v3 |= 0x800000u;
  *v3 |= 0x200000u;
  *v3 |= 0x100000u;
  *v3 |= 0x1000000u;
  *v3 = (a2 << 25) & 0x2000000 | *v3 & 0xFDFFFFFF;
  crypto_engine_clear_sram_regs();
  *v2 &= ~1u;
  delay_us_0644(140);
  v5 = off_10766C;
  *v3 |= 0x4000000u;
  v6 = *v5 & 0x7FFF;
  *v3 &= ~0x4000000u;
  *(uint32_t *)(a1 + 44) = v6;
  delay_us_0644(5);
  feature_guard_check(1, dword_107670);
  result = feature_guard_check(1, dword_107674);
  *v3 &= ~0x1000000u;
  *v3 &= ~0x2000000u;
  *v3 &= ~0x400000u;
  *v3 &= ~0x800000u;
  *v3 &= ~0x200000u;
  *v3 &= ~0x100000u;
  *v2 = *v2 & 0xFFFFFF8F | 0x40;
  return result;
}

