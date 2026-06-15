// mmio_clear_bit1_n_524 @ 0x114524, size 14 bytes
// Doc: mmio_clear_bit1_n_524 [mmio]: Clears bit 1 in MMIO register at offset 8
// mmio_clear_bit1_n_524 [mmio]: Clears bit 1 in MMIO register at offset 8
void mmio_clear_bit1_n_524()
{
  *(_DWORD *)(*(_DWORD *)off_114534 + 8) &= ~2u;
}

