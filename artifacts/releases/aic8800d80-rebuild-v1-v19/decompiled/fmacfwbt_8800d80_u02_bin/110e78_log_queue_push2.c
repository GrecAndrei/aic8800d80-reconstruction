// log_queue_push2 @ 0x110e78, size 238 bytes
// Doc: log_queue_push2 [util]: Push formatted log entry into debug queue
// log_queue_push2 [util]: Push formatted log entry into debug queue
int __fastcall log_queue_push2(int a1, int a2, int a3)
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
    *(_DWORD *)off_110F68 = 1;
  }
  v6 = (int *)off_110F94;
  v7 = *(unsigned __int8 **)off_110F6C;
  v8 = *(_DWORD *)off_110F94 + 1;
  *(_DWORD *)off_110F94 = v8;
  result = *v7;
  if ( result == 1 )
  {
    v16 = off_110F84;
    if ( *(_BYTE *)off_110F84 )
    {
      v19 = off_110F88;
      v20 = *((unsigned __int8 *)off_110F88 + 374);
      if ( v20 != 1 )
        goto LABEL_4;
      result = timestamp_list_contains_51a0(dword_110F8C);
      if ( result )
        goto LABEL_18;
      if ( v19[369] )
        sub_10DB6C(v20);
      else
        irq_enable(v20);
    }
    else
    {
      v17 = (unsigned __int8 *)off_110F88;
      if ( *((_BYTE *)off_110F88 + 369) )
        result = sub_10DB6C(1);
      else
        result = irq_enable(1);
      v18 = v17[374];
      *v16 = 1;
      if ( v18 != 1 )
        goto LABEL_18;
    }
    result = timestamp_update_4f60(dword_110F8C, *((_DWORD *)off_110F90 + 4) + 10000);
LABEL_18:
    v8 = *v6;
  }
LABEL_4:
  v10 = off_110F70;
  *(_DWORD *)off_110F70 = 256;
  while ( (*v10 & 0x200) != 0 )
    ;
  if ( *(_DWORD *)off_110F74 )
  {
    v11 = off_110F78;
    v12 = off_110F7C;
    *(_DWORD *)(*((_DWORD *)off_110F78 + 769) + 4) = a1;
    *v12 += a2;
  }
  else
  {
    v15 = off_110F7C;
    *(_DWORD *)off_110F74 = a1;
    v11 = off_110F78;
    *v15 += a2;
  }
  *(_DWORD *)off_110F80 = 256;
  v11[769] = a3;
  if ( v8 )
  {
    v13 = v8 - 1;
    v14 = *(_DWORD *)off_110F68;
    *v6 = v13;
    if ( !v13 )
    {
      if ( v14 )
        __enable_irq();
    }
  }
  return result;
}

