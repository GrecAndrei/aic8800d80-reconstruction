// v23 annotated: rf_clear_flag_bit1 @ 0x1138e0
// Original: 1138e0_rf_clear_flag_bit1.c
// Primary struct: group_14 (cluster 14)
//
// rf_clear_flag_bit1 @ 0x1138e0, size 14 bytes
// Doc: rf_clear_flag_bit1 [mmio]: Clears bit 1 in shared mmio control register (bic r3, r3, 2)
// rf_clear_flag_bit1 [mmio]: Clears bit 1 in shared mmio control register (bic r3, r3, 2)
void rf_clear_flag_bit1()
{
  *(_DWORD *)(*(_DWORD *)off_1138F0 + 8) &= ~2u;
}

