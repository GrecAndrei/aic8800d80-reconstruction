// sub_11101C @ 0x11101c, size 238 bytes
int __fastcall sub_11101C(int a1, int a2, int a3)
{
  int *v6; // r9
  unsigned __int8 *v7; // r3
  int v8; // r5
  int result; // r0
  _DWORD *v10; // r4
  _DWORD *v11; // r3
  _DWORD *v12; // r1
  int v13; // r5
  int v14; // r3
  _DWORD *v15; // r2
  _BYTE *v16; // r4
  unsigned __int8 *v17; // r5
  int v18; // r3
  _BYTE *v19; // r10
  int v20; // r4

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_11110C = 1;
  }
  v6 = (int *)off_111138;
  v7 = *(unsigned __int8 **)off_111110;
  v8 = *(_DWORD *)off_111138 + 1;
  *(_DWORD *)off_111138 = v8;
  result = *v7;
  if ( result == 1 )
  {
    v16 = off_111128;
    if ( *(_BYTE *)off_111128 )
    {
      v19 = off_11112C;
      v20 = *((unsigned __int8 *)off_11112C + 374);
      if ( v20 != 1 )
        goto LABEL_4;
      result = rf_msg_handler_n22e(dword_111130);
      if ( result )
        goto LABEL_18;
      if ( v19[369] )
        sub_10DD14(v20);
      else
        rf_mem_read_n47e(v20);
    }
    else
    {
      v17 = (unsigned __int8 *)off_11112C;
      if ( *((_BYTE *)off_11112C + 369) )
        result = sub_10DD14(1);
      else
        result = rf_mem_read_n47e(1);
      v18 = v17[374];
      *v16 = 1;
      if ( v18 != 1 )
        goto LABEL_18;
    }
    result = timestamp_update(dword_111130, *((_DWORD *)off_111134 + 4) + 10000);
LABEL_18:
    v8 = *v6;
  }
LABEL_4:
  v10 = off_111114;
  *(_DWORD *)off_111114 = 256;
  while ( (*v10 & 0x200) != 0 )
    ;
  if ( *(_DWORD *)off_111118 )
  {
    v11 = off_11111C;
    v12 = off_111120;
    *(_DWORD *)(*((_DWORD *)off_11111C + 769) + 4) = a1;
    *v12 += a2;
  }
  else
  {
    v15 = off_111120;
    *(_DWORD *)off_111118 = a1;
    v11 = off_11111C;
    *v15 += a2;
  }
  *(_DWORD *)off_111124 = 256;
  v11[769] = a3;
  if ( v8 )
  {
    v13 = v8 - 1;
    v14 = *(_DWORD *)off_11110C;
    *v6 = v13;
    if ( !v13 )
    {
      if ( v14 )
        __enable_irq();
    }
  }
  return result;
}

