// fwstruct annotate: 10ed7c_mmio_read_bitfield_7000101c.c
// mmio_read_bitfield_7000101c @ 0x10ed7c, size 16 bytes
// Doc: mmio_read_bitfield_7000101c [mmio]: Reads a 5-bit field at offset 0xb from MMIO 0x7000101c
// mmio_read_bitfield_7000101c [mmio]: Reads a 5-bit field at offset 0xb from MMIO 0x7000101c
int mmio_read_bitfield_7000101c()
{
  return (unsigned __int16)sub_10EBDC(dword_10ED8C, 1) >> 11;
}

