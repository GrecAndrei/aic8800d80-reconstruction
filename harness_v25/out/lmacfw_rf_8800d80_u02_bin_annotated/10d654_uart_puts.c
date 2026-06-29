// fwstruct annotate: 10d654_uart_puts.c
// uart_puts @ 0x10d654, size 34 bytes
// Doc: uart_puts [util]: Output null-terminated string to UART byte-by-byte
// uart_puts [util]: Output null-terminated string to UART byte-by-byte
_BYTE *__fastcall uart_puts(_BYTE *result)
{
  int v1; // r1
  _DWORD *v2; // r2
  _DWORD *v3; // r4
  int v4; // t1

  v1 = (unsigned __int8)*result;
  if ( *result )
  {
    v2 = off_10D678;
    v3 = off_10D67C;
    do
    {
      while ( (*v2 & 0x80000) != 0 )
        ;
      *v3 = v1;
      v4 = (unsigned __int8)*++result;
      v1 = v4;
    }
    while ( v4 );
  }
  return result;
}

