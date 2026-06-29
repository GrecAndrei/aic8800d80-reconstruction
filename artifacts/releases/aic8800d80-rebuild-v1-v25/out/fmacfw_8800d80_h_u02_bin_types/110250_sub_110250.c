// sub_110250 @ 0x110250, size 62 bytes
int sub_110250()
{
  int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r3
  int v5; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_110290 = 1;
  }
  v0 = (int *)off_110294;
  v1 = dword_110298;
  ++*(uint32_t *)off_110294;
  result = sub_12D108(v1);
  v3 = *v0;
  ++*(uint32_t *)off_11029C;
  if ( v3 )
  {
    v4 = v3 - 1;
    v5 = *(uint32_t *)off_110290;
    *v0 = v4;
    if ( !v4 )
    {
      if ( v5 )
        __enable_irq();
    }
  }
  return result;
}

