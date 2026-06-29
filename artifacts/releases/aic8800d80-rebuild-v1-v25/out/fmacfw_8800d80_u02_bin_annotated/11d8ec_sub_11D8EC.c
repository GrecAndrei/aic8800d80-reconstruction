// fwstruct annotate: 11d8ec_sub_11D8EC.c
// sub_11D8EC @ 0x11d8ec, size 162 bytes
// Doc: sub_121D8EC [util]: Initialization routine loading config and calling setup
// sub_121D8EC [util]: Initialization routine loading config and calling setup
int sub_11D8EC()
{
  int *v0; // r5
  int v1; // r4
  int result; // r0
  int *v3; // r8
  int *v4; // r9
  int v5; // r7
  void (__fastcall *v6)(_DWORD); // r2
  int v7; // r3
  int v8; // r2
  _BYTE *v9; // r4

  v0 = (int *)off_11D990;
  v1 = *(_DWORD *)off_11D990;
  result = clear_flags(0x200000);
  if ( v1 )
  {
    v3 = (int *)off_11D99C;
    v4 = (int *)off_11D9A0;
    v5 = 0;
    do
    {
      if ( (*(_BYTE *)(v1 + 16) & 1) == 0 )
      {
        if ( v5 )
          break;
        v5 = 1;
      }
      rf_bus_mark_n100_d2d0(v0);
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *v3 = 1;
      }
      v6 = *(void (__fastcall **)(_DWORD))(v1 + 4);
      ++*v4;
      *(_BYTE *)(v1 + 16) = 0;
      if ( v6 )
        v6(*(_DWORD *)(v1 + 8));
      result = *(_DWORD *)(v1 + 12);
      if ( result )
        result = sub_11E0B4();
      if ( *v4 )
      {
        v7 = *v4 - 1;
        v8 = *v3;
        *v4 = v7;
        if ( !v7 )
        {
          if ( v8 )
            __enable_irq();
        }
      }
      v1 = *v0;
    }
    while ( *v0 );
  }
  v9 = off_11D994;
  if ( *((_BYTE *)off_11D994 + 69) )
  {
    irq_nesting_or_d104(0x80000);
    result = feature_guard_check(1024, dword_11D998);
    v9[69] = 0;
  }
  return result;
}

