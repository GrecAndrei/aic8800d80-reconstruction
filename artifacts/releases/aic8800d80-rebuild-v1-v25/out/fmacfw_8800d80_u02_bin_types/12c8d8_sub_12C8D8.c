// sub_12C8D8 @ 0x12c8d8, size 72 bytes
int sub_12C8D8()
{
  int *v0; // r5
  int v1; // r4
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_12C920 = 1;
  }
  v0 = (int *)off_12C924;
  v1 = dword_12C928;
  ++*(uint32_t *)off_12C924;
  sub_12D14C(0x10000000);
  while ( 1 )
  {
    result = sub_12D2D0(v1);
    if ( !result )
      break;
    sub_12CBC8(result);
  }
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(uint32_t *)off_12C920;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

