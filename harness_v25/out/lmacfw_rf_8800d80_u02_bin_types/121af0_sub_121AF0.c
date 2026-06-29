// sub_121AF0 @ 0x121af0, size 66 bytes
int  sub_121AF0(unsigned int a1)
{
  int *v2; // r5
  int result; // r0
  int v4; // r3
  int v5; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_121B34 = 1;
  }
  v2 = (int *)off_121B38;
  ++*(uint32_t *)off_121B38;
  result = sub_1152CC();
  if ( a1 <= 3 )
    --*(uint8_t *)(dword_121B3C + a1);
  if ( *v2 )
  {
    v4 = *v2 - 1;
    v5 = *(uint32_t *)off_121B34;
    *v2 = v4;
    if ( !v4 )
    {
      if ( v5 )
        __enable_irq();
    }
  }
  return result;
}

