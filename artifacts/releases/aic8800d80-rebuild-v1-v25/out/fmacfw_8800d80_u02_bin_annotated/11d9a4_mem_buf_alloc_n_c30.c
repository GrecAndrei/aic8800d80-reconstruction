// fwstruct annotate: 11d9a4_mem_buf_alloc_n_c30.c
// mem_buf_alloc_n_c30 @ 0x11d9a4, size 180 bytes
// Doc: mem_buf_alloc_n_c30 [util]: Allocate 2MB buffer and initialize linked list node
// mem_buf_alloc_n_c30 [util]: Allocate 2MB buffer and initialize linked list node
int mem_buf_alloc_n_c30()
{
  int *v0; // r6
  int v1; // r4
  int result; // r0
  _WORD *v3; // r5
  int *v4; // r8
  int *v5; // r9
  char v6; // r2
  void (__fastcall *v7)(_DWORD); // r3
  int v8; // r3
  int v9; // r2
  _BYTE *v10; // r4

  v0 = (int *)off_11DA58;
  v1 = *(_DWORD *)off_11DA58;
  result = clear_flags(0x200000);
  if ( v1 )
  {
    v3 = off_11DA5C;
    if ( *(_WORD *)off_11DA5C )
    {
      v4 = (int *)off_11DA68;
      v5 = (int *)off_11DA6C;
      do
      {
        if ( (*(_BYTE *)(v1 + 16) & 1) == 0 && !*v3 )
          break;
        rf_bus_mark_n100_d2d0(v0);
        if ( (__get_CPSR() & 1) == 0 )
        {
          __disable_irq();
          *v4 = 1;
        }
        v6 = *(_BYTE *)(v1 + 16);
        ++*v5;
        if ( (v6 & 1) == 0 )
          --*v3;
        v7 = *(void (__fastcall **)(_DWORD))(v1 + 4);
        *(_BYTE *)(v1 + 16) = 0;
        if ( v7 )
          v7(*(_DWORD *)(v1 + 8));
        result = *(_DWORD *)(v1 + 12);
        if ( result )
          result = sub_11E0B4();
        if ( *v5 )
        {
          v8 = *v5 - 1;
          v9 = *v4;
          *v5 = v8;
          if ( !v8 )
          {
            if ( v9 )
              __enable_irq();
          }
        }
        v1 = *v0;
      }
      while ( *v0 );
      v10 = off_11DA60;
      if ( *((_BYTE *)off_11DA60 + 69) )
      {
        irq_nesting_or_d104(0x80000);
        result = feature_guard_check(1024, dword_11DA64);
        v10[69] = 0;
      }
    }
  }
  return result;
}

