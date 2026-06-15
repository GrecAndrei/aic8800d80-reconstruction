// rf_subcmd_dispatch_n5b60 @ 0x115b60, size 276 bytes
// Doc: rf_register_access_helper [rf]: Helper wrapping RF register access (pushes r4-r6,lr)
// rf_register_access_helper [rf]: Helper wrapping RF register access (pushes r4-r6,lr)
int __fastcall rf_subcmd_dispatch_n5b60(int a1, int a2)
{
  _BYTE *v4; // r3
  char *v5; // r0
  int *v6; // r5
  int v7; // r2
  int v8; // r3
  int v9; // r3
  int v10; // r2
  int v11; // r2
  int v12; // r1
  __int16 v13; // r3
  int *v14; // r3
  int v15; // r3
  int v16; // r2
  int v17; // r3
  int v18; // r2
  int v20; // r3
  int v21; // r0
  _DWORD *v22; // r3

  if ( a2 == 5 )
  {
    v5 = (char *)dword_115C84;
    v4 = (_BYTE *)(dword_115C84 - 112);
  }
  else
  {
    v4 = off_115C74;
    v5 = (char *)off_115C74 + 28 * a2;
  }
  if ( v4[142] )
  {
    v20 = *(unsigned __int8 *)(a1 + 16);
    if ( v20 == 255 )
    {
      sub_116628(a1, 0);
      return 0;
    }
    else
    {
      v21 = dword_115C80;
      *(_BYTE *)(a1 + 14) = a2;
      *(_BYTE *)(a1 + 53) = 1;
      list_push_tail(v21 + 152 * (__int16)v20 + 48);
      return 1;
    }
  }
  *(_DWORD *)(*(_DWORD *)(a1 + 32) + 64) |= 0x100u;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_115C78 = 1;
  }
  v6 = (int *)off_115C7C;
  v7 = *((_DWORD *)v5 + 5);
  ++*(_DWORD *)off_115C7C;
  if ( v7 )
  {
    list_push_tail(v5 + 12);
    v8 = *v6;
    if ( *v6 )
    {
LABEL_8:
      v9 = v8 - 1;
      v10 = *(_DWORD *)off_115C78;
      *v6 = v9;
      if ( !v9 && v10 )
        __enable_irq();
    }
  }
  else
  {
    v22 = *(_DWORD **)(a1 + 28);
    v22[4] = dword_115C88;
    v22[2] = a1;
    v22[3] = a1;
    list_push_tail(v5 + 12);
    v8 = *v6;
    if ( *v6 )
      goto LABEL_8;
  }
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_115C78 = 1;
  }
  v11 = *v6;
  v12 = *v6 + 1;
  v13 = *(_WORD *)(a1 + 38) | 1;
  *v6 = v12;
  *(_WORD *)(a1 + 38) = v13;
  if ( v12 )
  {
    v14 = (int *)off_115C78;
    *v6 = v11;
    v15 = *v14;
    if ( !v11 )
    {
      if ( v15 )
        __enable_irq();
    }
  }
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_115C78 = 1;
  }
  v16 = *(_DWORD *)(a1 + 28);
  ++*v6;
  sub_115754(a1, a1, v16, a2);
  if ( *v6 )
  {
    v17 = *v6 - 1;
    v18 = *(_DWORD *)off_115C78;
    *v6 = v17;
    if ( !v17 )
    {
      if ( v18 )
        __enable_irq();
    }
  }
  return 1;
}

