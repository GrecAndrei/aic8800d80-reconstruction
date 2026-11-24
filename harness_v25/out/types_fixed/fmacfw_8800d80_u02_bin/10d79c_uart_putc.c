// uart_putc @ 0x10d79c, size 14 bytes
// Doc: uart_putc [util]: Write one character to UART data register
// uart_putc [util]: Write one character to UART data register
int __fastcall uart_putc(int result)
{
  while ( (*(_DWORD *)off_10D7AC & 0x80000) != 0 )
    ;
  *(_DWORD *)off_10D7B0 = result;
  return result;
}

