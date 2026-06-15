// patch_table_apply_dbc @ 0x115dbc, size 186 bytes
// Doc: patch_table_apply_dbc [patch]: Applies a sequence of register patches from table
// patch_table_apply_dbc [patch]: Applies a sequence of register patches from table
int patch_table_apply_dbc()
{
  int *v0; // r10
  _BYTE *v1; // r5
  _DWORD *v2; // r8
  int v3; // r9
  int v4; // r7
  _DWORD *v5; // r6
  int *v6; // r11
  int i; // r4
  int v8; // r0
  int v9; // r1
  int v10; // r3
  int *v11; // r3
  int v12; // r3
  int v13; // r3
  int v14; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_115E78 = 1;
  }
  v0 = (int *)off_115E88;
  v1 = off_115E7C;
  v2 = off_115E8C;
  v3 = dword_115E90;
  v4 = dword_115E80;
  v5 = off_115E84;
  v6 = (int *)off_115E94;
  ++*(_DWORD *)off_115E88;
  v1[143] = 0;
  for ( i = 4; i != -1; --i )
  {
    if ( *((_DWORD *)v1 + 28) )
    {
      rf_subcmd_dispatch((unsigned __int8)i);
      *(_DWORD *)(v4 + 4 * i) = *v2 + *(_DWORD *)(v3 + 4 * i);
      *v5 = 1 << i;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(_DWORD *)off_115E78 = 1;
      }
      v8 = *v0;
      v9 = *v0 + 1;
      v10 = (1 << i) | *v6;
      *v0 = v9;
      *v6 = v10;
      if ( v9 )
      {
        v11 = (int *)off_115E78;
        *v0 = v8;
        v12 = *v11;
        if ( !v8 )
        {
          if ( v12 )
            __enable_irq();
        }
      }
    }
    v1 -= 28;
  }
  if ( *v0 )
  {
    v13 = *v0 - 1;
    v14 = *(_DWORD *)off_115E78;
    *v0 = v13;
    if ( !v13 )
    {
      if ( v14 )
        __enable_irq();
    }
  }
  return irq_nesting_or(4096);
}

