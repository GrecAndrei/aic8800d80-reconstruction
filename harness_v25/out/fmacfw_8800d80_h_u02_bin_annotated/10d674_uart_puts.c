// fwstruct annotate: 10d674_uart_puts.c
// uart_puts @ 0x10d674, size 34 bytes
// Doc: uart_puts [util]: Write a null-terminated string to UART
// uart_puts [util]: Write a null-terminated string to UART
_BYTE *__fastcall uart_puts(_BYTE *result)
{
  int v1; // r1
  _DWORD *v2; // r2
  _DWORD *v3; // r4
  int v4; // t1

  v1 = (unsigned __int8)*result;
  if ( *result )
  {
    v2 = off_10D698;
    v3 = off_10D69C;
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

