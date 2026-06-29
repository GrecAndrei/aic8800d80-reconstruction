// panic_loop_06d8 @ 0x1006d8, size 78 bytes
// Doc: panic_loop_06d8 [util]: Fatal error handler that triggers watchdog/reset loop
// panic_loop_06d8 [util]: Fatal error handler that triggers watchdog/reset loop
void __noreturn panic_loop_06d8()
{
  int v1; // [sp+0h] [bp-Ch]

  *(uint32_t *)off_100728 = 17;
  while ( 1 )
  {
    v1 = 32;
    while ( v1-- )
      ;
  }
}

