// delay_us @ 0x100560, size 40 bytes
// Doc: delay_us [util]: Microsecond delay loop using 0x40501000 timer base
// delay_us [util]: Microsecond delay loop using 0x40501000 timer base
int  delay_us(int a1)
{
  int result; // r0
  int v3; // [sp+4h] [bp-8h]

  result = a1 + *((uint32_t *)off_100588 + 4);
  do
  {
    v3 = 32;
    while ( v3-- )
      ;
  }
  while ( *((uint32_t *)off_100588 + 4) - result < 0 );
  return result;
}

