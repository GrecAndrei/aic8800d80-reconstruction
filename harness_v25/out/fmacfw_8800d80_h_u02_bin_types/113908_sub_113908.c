// sub_113908 @ 0x113908, size 54 bytes
int sub_113908()
{
  int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_113940 = 1;
  }
  v0 = (int *)off_113944;
  v1 = dword_113948;
  ++*(uint32_t *)off_113944;
  result = sub_12D108(v1);
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(uint32_t *)off_113940;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

