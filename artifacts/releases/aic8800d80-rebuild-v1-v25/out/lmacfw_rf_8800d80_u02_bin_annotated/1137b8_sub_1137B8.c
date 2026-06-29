// fwstruct annotate: 1137b8_sub_1137B8.c
// sub_1137B8 @ 0x1137b8, size 72 bytes
int sub_1137B8()
{
  int *v0; // r5
  _DWORD *v1; // r4
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_113800 = 1;
  }
  v0 = (int *)off_113804;
  v1 = off_113808;
  ++*(_DWORD *)off_113804;
  while ( !*v1 )
    ;
  result = sub_11E724(*(_DWORD *)off_11380C + 580);
  *v1 = 1;
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(_DWORD *)off_113800;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

