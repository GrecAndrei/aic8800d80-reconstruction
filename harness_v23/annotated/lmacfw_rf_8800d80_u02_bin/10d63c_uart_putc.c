// v23 annotated: uart_putc @ 0x10d63c
// Original: 10d63c_uart_putc.c
// Primary struct: <unclustered>
//
// uart_putc @ 0x10d63c, size 14 bytes
// Doc: uart_putc [mmio]: Writes a single character to UART data register at 0x40032000
// uart_putc [mmio]: Writes a single character to UART data register at 0x40032000
int __fastcall uart_putc(int result)
{
  while ( (*(_DWORD *)off_10D64C & 0x80000) != 0 )
    ;
  *(_DWORD *)off_10D650 = result;
  return result;
}

