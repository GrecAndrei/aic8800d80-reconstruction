// panic_loop_06d8 @ 0x1006d8, size 78 bytes
// Doc: panic_loop_06d8 [util]: Fatal error handler that triggers watchdog/reset loop
// panic_loop_06d8 [util]: Fatal error handler that triggers watchdog/reset loop
void panic_loop_06d8()
{
  unsigned int v0; // r0
  unsigned int v1; // r1
  int v2; // [sp+0h] [bp-Ch]

  *(_DWORD *)off_100728 = 17;
  v0 = *((_DWORD *)off_10066C + 4) + 10;
  do
  {
    v2 = 32;
    while ( v2-- )
      ;
  }
  while ( *((_DWORD *)off_10066C + 4) - v0 < 0 );
  *(_DWORD *)off_100728 = 0;
  v1 = *((_DWORD *)off_10066C + 4) + 10;
  do
  {
    v2 = 32;
    while ( v2-- )
      ;
  }
  while ( *((_DWORD *)off_10066C + 4) - v1 < 0 );
}
