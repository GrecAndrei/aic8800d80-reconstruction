// sub_1103B0 @ 0x1103b0, size 54 bytes
int sub_1103B0()
{
  int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_1103E8 = 1;
  }
  v0 = (int *)off_1103EC;
  v1 = dword_1103F0;
  ++*(uint32_t *)off_1103EC;
  result = list_push_tail(v1);
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(uint32_t *)off_1103E8;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

