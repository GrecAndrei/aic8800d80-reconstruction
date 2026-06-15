// v23 annotated: mmio_write0x40035100_set0x100 @ 0x10cf2c
// Original: 10cf2c_mmio_write0x40035100_set0x100.c
// Primary struct: <unclustered>
//
// mmio_write0x40035100_set0x100 @ 0x10cf2c, size 10 bytes
// Doc: mmio_write0x40035100_set0x100 [mmio]: Write 0x100 to MMIO register 0x40035100 then return
// mmio_write0x40035100_set0x100 [mmio]: Write 0x100 to MMIO register 0x40035100 then return
void mmio_write0x40035100_set0x100()
{
  *(_DWORD *)off_10CF38 = 256;
}

