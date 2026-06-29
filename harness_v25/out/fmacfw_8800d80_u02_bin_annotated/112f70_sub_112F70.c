// fwstruct annotate: 112f70_sub_112F70.c
// sub_112F70 @ 0x112f70, size 126 bytes
void sub_112F70()
{
  int *v0; // r4
  int v1; // r2
  int v2; // r3
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_112FF0 = 1;
  }
  v0 = (int *)off_112FF4;
  v1 = *(unsigned __int8 *)off_112FF8;
  v2 = *(_DWORD *)off_112FF4 + 1;
  *(_DWORD *)off_112FF4 = v2;
  if ( v1 )
  {
    *((_DWORD *)off_112FFC + 513) |= 1u;
    while ( 1 )
      ;
  }
  if ( v2 )
  {
    v3 = v2 - 1;
    v4 = *(_DWORD *)off_112FF0;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
}

