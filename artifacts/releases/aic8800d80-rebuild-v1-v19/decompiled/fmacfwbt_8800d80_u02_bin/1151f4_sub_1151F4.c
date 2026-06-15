// sub_1151F4 @ 0x1151f4, size 54 bytes
int sub_1151F4()
{
  int *v0; // r4
  int result; // r0
  int v2; // r3
  int v3; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_11522C = 1;
  }
  v0 = (int *)off_115230;
  ++*(_DWORD *)off_115230;
  result = MEMORY[0x1C8]();
  if ( *v0 )
  {
    v2 = *v0 - 1;
    v3 = *(_DWORD *)off_11522C;
    *v0 = v2;
    if ( !v2 )
    {
      if ( v3 )
        __enable_irq();
    }
  }
  return result;
}

