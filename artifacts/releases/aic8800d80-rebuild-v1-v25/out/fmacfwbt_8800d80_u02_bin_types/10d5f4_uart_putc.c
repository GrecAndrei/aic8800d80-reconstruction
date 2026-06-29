// uart_putc @ 0x10d5f4, size 14 bytes
// Doc: uart_putc [util]: Write one character to UART data register at 0x40032000
// uart_putc [util]: Write one character to UART data register at 0x40032000
int  uart_putc(int result)
{
  while ( (*(uint32_t *)off_10D604 & 0x80000) != 0 )
    ;
  *(uint32_t *)off_10D608 = result;
  return result;
}

