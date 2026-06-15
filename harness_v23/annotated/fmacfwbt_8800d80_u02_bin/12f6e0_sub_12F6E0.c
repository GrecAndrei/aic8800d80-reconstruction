// v23 annotated: sub_12F6E0 @ 0x12f6e0
// Original: 12f6e0_sub_12F6E0.c
// Primary struct: <unclustered>
//
// sub_12F6E0 @ 0x12f6e0, size 40 bytes
void sub_12F6E0()
{
  _DWORD *v0; // r3
  int v1; // r2
  int v2; // r1
  _DWORD *v3; // r1

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_12F708 = 1;
  }
  v0 = off_12F70C;
  v1 = *(_DWORD *)off_12F70C;
  v2 = *(_DWORD *)off_12F70C + 1;
  *(_DWORD *)off_12F70C = v2;
  if ( v2 )
  {
    v3 = off_12F708;
    *v0 = v1;
    if ( !v1 )
    {
      if ( *v3 )
        __enable_irq();
    }
  }
}

