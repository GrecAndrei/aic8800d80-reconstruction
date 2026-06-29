// fwstruct annotate: 12f378_sub_12F378.c
// sub_12F378 @ 0x12f378, size 40 bytes
void sub_12F378()
{
  _DWORD *v0; // r3
  int v1; // r2
  int v2; // r1
  _DWORD *v3; // r1

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_12F3A0 = 1;
  }
  v0 = off_12F3A4;
  v1 = *(_DWORD *)off_12F3A4;
  v2 = *(_DWORD *)off_12F3A4 + 1;
  *(_DWORD *)off_12F3A4 = v2;
  if ( v2 )
  {
    v3 = off_12F3A0;
    *v0 = v1;
    if ( !v1 )
    {
      if ( *v3 )
        __enable_irq();
    }
  }
}

