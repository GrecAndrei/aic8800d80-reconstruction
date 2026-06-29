// fwstruct annotate: 11d830_sub_11D830.c
// sub_11D830 @ 0x11d830, size 158 bytes
int sub_11D830()
{
  _WORD *v0; // r5
  int v1; // r4
  int result; // r0
  int *v3; // r9
  int *v4; // r7
  void (__fastcall *v5)(_DWORD); // r2
  int v6; // r3
  int v7; // r2
  _DWORD *v8; // r1
  _DWORD *v9; // r2

  v0 = off_11D8D0;
  v1 = *(_DWORD *)off_11D8D0;
  result = clear_flags(0x200000);
  if ( v1 )
  {
    v3 = (int *)off_11D8E8;
    v4 = (int *)off_11D8D4;
    do
    {
      if ( (*(_BYTE *)(v1 + 16) & 1) == 0 )
        ++v0[4];
      rf_bus_mark_n100_d2d0(v0);
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *v4 = 1;
      }
      v5 = *(void (__fastcall **)(_DWORD))(v1 + 4);
      ++*v3;
      *(_BYTE *)(v1 + 16) = 0;
      if ( v5 )
        v5(*(_DWORD *)(v1 + 8));
      result = *(_DWORD *)(v1 + 12);
      if ( result )
        result = sub_11E0B4();
      if ( *v3 )
      {
        v6 = *v3 - 1;
        v7 = *v4;
        *v3 = v6;
        if ( !v6 )
        {
          if ( v7 )
            __enable_irq();
        }
      }
      v1 = *(_DWORD *)v0;
    }
    while ( *(_DWORD *)v0 );
  }
  if ( *((unsigned __int8 *)v0 + 10) != *((unsigned __int8 *)v0 + 11) )
  {
    v8 = off_11D8E0;
    v9 = off_11D8E4;
    *(_DWORD *)off_11D8DC = *((_DWORD *)off_11D8D8 + 4) + 200;
    *v8 = 256;
    *v9 |= 0x100u;
    return 256;
  }
  return result;
}

