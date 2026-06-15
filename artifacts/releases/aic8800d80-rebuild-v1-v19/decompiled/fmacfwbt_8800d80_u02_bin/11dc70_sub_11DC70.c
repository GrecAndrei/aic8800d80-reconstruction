// sub_11DC70 @ 0x11dc70, size 158 bytes
int sub_11DC70()
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

  v0 = off_11DD10;
  v1 = *(_DWORD *)off_11DD10;
  result = sub_12D374(0x200000);
  if ( v1 )
  {
    v3 = (int *)off_11DD28;
    v4 = (int *)off_11DD14;
    do
    {
      if ( (*(_BYTE *)(v1 + 16) & 1) == 0 )
        ++v0[4];
      sub_12D4F8(v0);
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
        result = rx_desc_status_get();
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
    v8 = off_11DD20;
    v9 = off_11DD24;
    *(_DWORD *)off_11DD1C = *((_DWORD *)off_11DD18 + 4) + 200;
    *v8 = 256;
    *v9 |= 0x100u;
    return 256;
  }
  return result;
}

