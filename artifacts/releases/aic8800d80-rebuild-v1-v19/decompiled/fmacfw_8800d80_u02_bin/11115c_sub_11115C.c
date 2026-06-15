// sub_11115C @ 0x11115c, size 222 bytes
int __fastcall sub_11115C(int a1)
{
  int *v2; // r5
  _BYTE *v3; // r3
  int v4; // r1
  _DWORD *v5; // r2
  int result; // r0
  _DWORD *v7; // r2
  _DWORD *v8; // r6
  int v9; // r1
  int v10; // r3
  _BYTE *v11; // r6
  _BYTE *v12; // r7
  int v13; // r3
  int v14; // r6

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_11123C = 1;
  }
  v2 = (int *)off_111240;
  v3 = *(_BYTE **)off_111244;
  v4 = *(_DWORD *)off_111240 + 1;
  *(_DWORD *)off_111240 = v4;
  if ( *v3 == 1 )
  {
    v11 = off_111260;
    v12 = off_111264;
    if ( *(_BYTE *)off_111260 )
    {
      v14 = *((unsigned __int8 *)off_111264 + 374);
      if ( v14 != 1 )
        goto LABEL_4;
      if ( rf_msg_handler_n22e(dword_111268) )
        goto LABEL_18;
      if ( v12[369] )
        sub_10DD14(v14);
      else
        rf_mem_read_n47e(v14);
    }
    else
    {
      if ( *((_BYTE *)off_111264 + 369) )
        sub_10DD14(1);
      else
        rf_mem_read_n47e(1);
      v13 = (unsigned __int8)v12[374];
      *v11 = 1;
      if ( v13 != 1 )
        goto LABEL_18;
    }
    timestamp_update(dword_111268, *((_DWORD *)off_11126C + 4) + 10000);
LABEL_18:
    v4 = *v2;
  }
LABEL_4:
  v5 = off_111248;
  *(_DWORD *)off_111248 = 64;
  while ( (*v5 & 0x80) != 0 )
    ;
  if ( *(_DWORD *)off_11124C )
  {
    result = dword_111250;
    v7 = off_111254;
    *(_DWORD *)(*(_DWORD *)(dword_111250 + 6164) + 4) = a1;
  }
  else
  {
    v7 = off_111254;
    *(_DWORD *)off_11124C = a1;
    result = dword_111250;
  }
  ++*v7;
  v8 = off_11125C;
  *(_BYTE *)off_111258 |= 2u;
  *v8 = 64;
  *(_DWORD *)(result + 6164) = a1;
  if ( v4 )
  {
    v9 = v4 - 1;
    v10 = *(_DWORD *)off_11123C;
    *v2 = v9;
    if ( !v9 )
    {
      if ( v10 )
        __enable_irq();
    }
  }
  return result;
}

