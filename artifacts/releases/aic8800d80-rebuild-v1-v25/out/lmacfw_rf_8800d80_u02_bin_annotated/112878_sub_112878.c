// fwstruct annotate: 112878_sub_112878.c
// sub_112878 @ 0x112878, size 126 bytes
void sub_112878()
{
  int *v0; // r4
  int v1; // r2
  int v2; // r3
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_1128F8 = 1;
  }
  v0 = (int *)off_1128FC;
  v1 = *(unsigned __int8 *)off_112900;
  v2 = *(_DWORD *)off_1128FC + 1;
  *(_DWORD *)off_1128FC = v2;
  if ( v1 )
  {
    *((_DWORD *)off_112904 + 513) |= 1u;
    while ( 1 )
      ;
  }
  if ( v2 )
  {
    v3 = v2 - 1;
    v4 = *(_DWORD *)off_1128F8;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
}

