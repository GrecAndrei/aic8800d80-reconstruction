// fwstruct annotate: 10d638_mmio_read_u8.c
// mmio_read_u8 @ 0x10d638, size 16 bytes
// Doc: mmio_read_u8 [mmio]: Read a byte from MMIO register at 0x40032000
// mmio_read_u8 [mmio]: Read a byte from MMIO register at 0x40032000
int mmio_read_u8()
{
  while ( (*(_DWORD *)off_10D648 & 1) == 0 )
    ;
  return (unsigned __int8)*(_DWORD *)off_10D64C;
}

