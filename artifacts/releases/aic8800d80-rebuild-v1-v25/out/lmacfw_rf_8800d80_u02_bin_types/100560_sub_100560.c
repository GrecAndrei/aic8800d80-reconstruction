// sub_100560 @ 0x100560, size 40 bytes
int  sub_100560(int a1)
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

