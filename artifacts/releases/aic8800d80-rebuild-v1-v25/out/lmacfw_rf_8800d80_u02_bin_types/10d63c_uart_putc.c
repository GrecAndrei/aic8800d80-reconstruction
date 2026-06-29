// uart_putc @ 0x10d63c, size 14 bytes
// Doc: uart_putc [mmio]: Writes a single character to UART data register at 0x40032000
// uart_putc [mmio]: Writes a single character to UART data register at 0x40032000
int  uart_putc(int result)
{
  while ( (*(uint32_t *)off_10D64C & 0x80000) != 0 )
    ;
  *(uint32_t *)off_10D650 = result;
  return result;
}

