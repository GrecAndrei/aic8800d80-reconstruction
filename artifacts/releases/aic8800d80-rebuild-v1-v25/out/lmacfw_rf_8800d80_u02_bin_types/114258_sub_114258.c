// sub_114258 @ 0x114258, size 54 bytes
int sub_114258()
{
  int *v0; // r4
  int result; // r0
  int v2; // r3
  int v3; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_114290 = 1;
  }
  v0 = (int *)off_114294;
  ++*(uint32_t *)off_114294;
  result = MEMORY[0x1D0]();
  if ( *v0 )
  {
    v2 = *v0 - 1;
    v3 = *(uint32_t *)off_114290;
    *v0 = v2;
    if ( !v2 )
    {
      if ( v3 )
        __enable_irq();
    }
  }
  return result;
}

