// sub_12F4B4 @ 0x12f4b4, size 78 bytes
int  sub_12F4B4(unsigned int a1)
{
  int *v2; // r5
  int result; // r0
  int v4; // r3
  int v5; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_12F504 = 1;
  }
  v2 = (int *)off_12F508;
  ++*(uint32_t *)off_12F508;
  result = sub_115F04();
  if ( a1 <= 4 )
    --*(uint8_t *)(dword_12F50C + a1);
  if ( *v2 )
  {
    v4 = *v2 - 1;
    v5 = *(uint32_t *)off_12F504;
    *v2 = v4;
    if ( !v4 )
    {
      if ( v5 )
        __enable_irq();
    }
  }
  --*((uint32_t *)off_12F510 + 126);
  return result;
}

