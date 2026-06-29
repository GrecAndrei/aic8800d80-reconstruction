// sub_121A10 @ 0x121a10, size 40 bytes
void sub_121A10()
{
  uint32_t *v0; // r3
  int v1; // r2
  int v2; // r1
  uint32_t *v3; // r1

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_121A38 = 1;
  }
  v0 = off_121A3C;
  v1 = *(uint32_t *)off_121A3C;
  v2 = *(uint32_t *)off_121A3C + 1;
  *(uint32_t *)off_121A3C = v2;
  if ( v2 )
  {
    v3 = off_121A38;
    *v0 = v1;
    if ( !v1 )
    {
      if ( *v3 )
        __enable_irq();
    }
  }
}

