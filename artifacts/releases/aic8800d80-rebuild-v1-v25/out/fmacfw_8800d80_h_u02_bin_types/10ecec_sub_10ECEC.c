// sub_10ECEC @ 0x10ecec, size 70 bytes
int  sub_10ECEC(int a1, int a2, int a3, int a4)
{
  int *v4; // r5
  uint32_t *v5; // r4
  int result; // r0
  int v7; // r3
  int v8; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_10ED34 = 1;
  }
  v4 = (int *)off_10ED38;
  ++*(uint32_t *)off_10ED38;
  if ( a4 )
  {
    v5 = off_10ED3C;
    while ( !*(uint32_t *)off_10ED3C )
      ;
    result = sub_10EC3C();
    *v5 = 1;
  }
  else
  {
    result = sub_10EC3C();
  }
  if ( *v4 )
  {
    v7 = *v4 - 1;
    v8 = *(uint32_t *)off_10ED34;
    *v4 = v7;
    if ( !v7 )
    {
      if ( v8 )
        __enable_irq();
    }
  }
  return result;
}

