// v23 annotated: delay_us @ 0x100644
// Original: 100644_delay_us.c
// Primary struct: <unclustered>
//
// delay_us @ 0x100644, size 40 bytes
// Doc: delay_us [util]: Busy-wait delay in microseconds using timer
// delay_us [util]: Busy-wait delay in microseconds using timer
int __fastcall delay_us(int a1)
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

