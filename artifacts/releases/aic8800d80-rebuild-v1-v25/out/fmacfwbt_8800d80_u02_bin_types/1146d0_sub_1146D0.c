// sub_1146D0 @ 0x1146d0, size 52 bytes
// Doc: sub_12146D0 [util]: Helper routine in fmacfwbt with shift/branch logic
// sub_12146D0 [util]: Helper routine in fmacfwbt with shift/branch logic
int sub_1146D0()
{
  int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_114704 = 1;
  }
  v0 = (int *)off_114708;
  v1 = dword_11470C;
  ++*(uint32_t *)off_114708;
  result = sub_12D4F8(v1);
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(uint32_t *)off_114704;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

