// sub_1101EC @ 0x1101ec, size 54 bytes
int sub_1101EC()
{
  int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_110224 = 1;
  }
  v0 = (int *)off_110228;
  v1 = dword_11022C;
  ++*(uint32_t *)off_110228;
  result = sub_11E724(v1);
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(uint32_t *)off_110224;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

