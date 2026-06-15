// mmio_set_flag_bit1 @ 0x114538, size 14 bytes
// Doc: mmio_set_flag_bit1 [mmio]: Sets bit 1 in MMIO register at indirect pointer offset +8
// mmio_set_flag_bit1 [mmio]: Sets bit 1 in MMIO register at indirect pointer offset +8
void mmio_set_flag_bit1()
{
  *(_DWORD *)(*(_DWORD *)off_114548 + 8) |= 2u;
}

