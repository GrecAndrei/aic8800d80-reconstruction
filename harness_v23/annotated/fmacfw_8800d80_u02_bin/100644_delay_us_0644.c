// v23 annotated: delay_us_0644 @ 0x100644
// Original: 100644_delay_us_0644.c
// Primary struct: <unclustered>
//
// delay_us_0644 @ 0x100644, size 40 bytes
// Doc: delay_us_0644 [util]: Microsecond busy-wait delay using MMIO timer at 0x40501000
// delay_us_0644 [util]: Microsecond busy-wait delay using MMIO timer at 0x40501000
int __fastcall delay_us_0644(int a1)
{
  int result; // r0
  int v3; // [sp+4h] [bp-8h]

  result = a1 + *((_DWORD *)off_10066C + 4);
  do
  {
    v3 = 32;
    while ( v3-- )
      ;
  }
  while ( *((_DWORD *)off_10066C + 4) - result < 0 );
  return result;
}

