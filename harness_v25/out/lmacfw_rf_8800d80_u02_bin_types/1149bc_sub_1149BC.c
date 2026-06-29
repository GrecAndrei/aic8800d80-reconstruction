// sub_1149BC @ 0x1149bc, size 52 bytes
int sub_1149BC()
{
  int *v0; // r4
  int ( *v1)(int); // r2
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_1149F0 = 1;
  }
  v0 = (int *)off_1149F4;
  v1 = (int ( *)(int))off_1149F8;
  ++*(uint32_t *)off_1149F4;
  result = v1(2);
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(uint32_t *)off_1149F0;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

