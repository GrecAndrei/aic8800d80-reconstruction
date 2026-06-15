// sub_1138A4 @ 0x1138a4, size 54 bytes
int sub_1138A4()
{
  int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_1138DC = 1;
  }
  v0 = (int *)off_1138E0;
  v1 = dword_1138E4;
  ++*(_DWORD *)off_1138E0;
  result = sub_12D470(v1);
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(_DWORD *)off_1138DC;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

