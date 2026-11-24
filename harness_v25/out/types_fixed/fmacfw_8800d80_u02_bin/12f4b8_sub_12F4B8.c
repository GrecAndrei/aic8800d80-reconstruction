// sub_12F4B8 @ 0x12f4b8, size 40 bytes
void sub_12F4B8()
{
  _DWORD *v0; // r3
  int v1; // r2
  int v2; // r1
  _DWORD *v3; // r1

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_12F4E0 = 1;
  }
  v0 = off_12F4E4;
  v1 = *(_DWORD *)off_12F4E4;
  v2 = *(_DWORD *)off_12F4E4 + 1;
  *(_DWORD *)off_12F4E4 = v2;
  if ( v2 )
  {
    v3 = off_12F4E0;
    *v0 = v1;
    if ( !v1 )
    {
      if ( *v3 )
        __enable_irq();
    }
  }
}

