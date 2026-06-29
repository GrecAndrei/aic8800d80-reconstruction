// mmio_read_byte_uart @ 0x10d7e0, size 16 bytes
// Doc: mmio_read_byte_uart [mmio]: Reads a byte from UART MMIO at 0x40032000 (offset 0x14)
// mmio_read_byte_uart [mmio]: Reads a byte from UART MMIO at 0x40032000 (offset 0x14)
int mmio_read_byte_uart()
{
  while ( (*(uint32_t *)off_10D7F0 & 1) == 0 )
    ;
  return (unsigned __int8)*(uint32_t *)off_10D7F4;
}

