// sub_12CFC4 @ 0x12cfc4, size 52 bytes
int  sub_12CFC4(int a1)
{
  uint32_t *v1; // r2
  int *v2; // r5
  int v3; // r1
  int v4; // r4
  int result; // r0
  int *v6; // r3
  int v7; // r3

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_12CFF8 = 1;
  }
  v1 = off_12CFFC;
  v2 = (int *)off_12D000;
  v3 = *(uint32_t *)off_12CFFC;
  v4 = *(uint32_t *)off_12CFFC + 1;
  result = a1 | *(uint32_t *)off_12D000;
  *(uint32_t *)off_12CFFC = v4;
  *v2 = result;
  if ( v4 )
  {
    v6 = (int *)off_12CFF8;
    *v1 = v3;
    v7 = *v6;
    if ( !v3 )
    {
      if ( v7 )
        __enable_irq();
    }
  }
  return result;
}

