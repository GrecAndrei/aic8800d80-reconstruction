// fwstruct annotate: 12bd00_sub_12BD00.c
// sub_12BD00 @ 0x12bd00, size 60 bytes
int sub_12BD00()
{
  _DWORD *v0; // r3
  int v1; // r2
  int result; // r0
  int v3; // r4
  _DWORD *v4; // r4

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_12BD3C = 1;
  }
  v0 = off_12BD40;
  v1 = *(_DWORD *)off_12BD40;
  result = *(_DWORD *)off_12BD48;
  v3 = *(_DWORD *)off_12BD40 + 1;
  *(_DWORD *)off_12BD40 = v3;
  if ( v3 )
  {
    v4 = off_12BD3C;
    *v0 = v1;
    if ( !v1 )
    {
      if ( *v4 )
        __enable_irq();
    }
  }
  return result;
}

