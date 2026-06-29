// sub_12C068 @ 0x12c068, size 60 bytes
int sub_12C068()
{
  uint32_t *v0; // r3
  int v1; // r2
  int result; // r0
  int v3; // r4
  uint32_t *v4; // r4

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_12C0A4 = 1;
  }
  v0 = off_12C0A8;
  v1 = *(uint32_t *)off_12C0A8;
  result = *(uint32_t *)off_12C0B0;
  v3 = *(uint32_t *)off_12C0A8 + 1;
  *(uint32_t *)off_12C0A8 = v3;
  if ( v3 )
  {
    v4 = off_12C0A4;
    *v0 = v1;
    if ( !v1 )
    {
      if ( *v4 )
        __enable_irq();
    }
  }
  return result;
}

