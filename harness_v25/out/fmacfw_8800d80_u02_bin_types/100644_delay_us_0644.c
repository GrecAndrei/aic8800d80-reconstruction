// delay_us_0644 @ 0x100644, size 40 bytes
// Doc: delay_us_0644 [util]: Microsecond busy-wait delay using MMIO timer at 0x40501000
// delay_us_0644 [util]: Microsecond busy-wait delay using MMIO timer at 0x40501000
int  delay_us_0644(int a1)
{
  int result; // r0
  int v3; // [sp+4h] [bp-8h]

  result = a1 + *((uint32_t *)off_10066C + 4);
  do
  {
    v3 = 32;
    while ( v3-- )
      ;
  }
  while ( *((uint32_t *)off_10066C + 4) - result < 0 );
  return result;
}

