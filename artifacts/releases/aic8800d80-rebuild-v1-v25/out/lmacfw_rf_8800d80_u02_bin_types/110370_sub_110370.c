// sub_110370 @ 0x110370, size 52 bytes
// Doc: sub_1210370 [util]: Trampoline stub with shifted register setup
// sub_1210370 [util]: Trampoline stub with shifted register setup
int sub_110370()
{
  int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_1103A4 = 1;
  }
  v0 = (int *)off_1103A8;
  v1 = dword_1103AC;
  ++*(uint32_t *)off_1103A8;
  result = sub_11E7AC(v1);
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(uint32_t *)off_1103A4;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

