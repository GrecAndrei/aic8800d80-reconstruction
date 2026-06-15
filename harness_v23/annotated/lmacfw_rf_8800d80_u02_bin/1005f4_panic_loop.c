// v23 annotated: panic_loop @ 0x1005f4
// Original: 1005f4_panic_loop.c
// Primary struct: <unclustered>
//
// panic_loop @ 0x1005f4, size 78 bytes
// Doc: panic_loop [util]: CPU panic infinite loop / fatal halt
// panic_loop [util]: CPU panic infinite loop / fatal halt
void __noreturn panic_loop()
{
  int v1; // [sp+0h] [bp-Ch]

  *(_DWORD *)off_100644 = 17;
  while ( 1 )
  {
    v1 = 32;
    while ( v1-- )
      ;
  }
}

