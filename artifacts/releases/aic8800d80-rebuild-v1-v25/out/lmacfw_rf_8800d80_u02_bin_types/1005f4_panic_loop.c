// panic_loop @ 0x1005f4, size 78 bytes
// Doc: panic_loop [util]: CPU panic infinite loop / fatal halt
// panic_loop [util]: CPU panic infinite loop / fatal halt
void __noreturn panic_loop()
{
  int v1; // [sp+0h] [bp-Ch]

  *(uint32_t *)off_100644 = 17;
  while ( 1 )
  {
    v1 = 32;
    while ( v1-- )
      ;
  }
}

