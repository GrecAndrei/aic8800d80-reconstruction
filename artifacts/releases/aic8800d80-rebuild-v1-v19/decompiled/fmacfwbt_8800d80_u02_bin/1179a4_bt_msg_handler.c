// bt_msg_handler @ 0x1179a4, size 254 bytes
// Doc: bt_msg_handler [bt]: Bluetooth message handler
// bt_msg_handler [bt]: Bluetooth message handler
int __fastcall bt_msg_handler(int a1, int a2)
{
  char *v4; // r7
  int v5; // r0
  __int16 v6; // r1
  _DWORD *v7; // r3
  int v8; // r3
  _BYTE *v9; // r2
  int *v10; // r6
  int result; // r0
  int v12; // r3
  int v13; // r3
  int v14; // r2

  if ( a2 == 5 )
    v4 = (char *)dword_117AC8;
  else
    v4 = (char *)off_117AA4 + 84 * a2;
  v5 = dword_117AA8;
  v6 = *(_WORD *)(a1 + 30);
  v7 = *(_DWORD **)(a1 + 76);
  v7[9] = *(unsigned __int8 *)(a1 + 51) + *(unsigned __int8 *)(a1 + 53) + *(unsigned __int16 *)(a1 + 4) + 4;
  v7[8] = 0;
  v7[13] = 0;
  v7[14] = 0;
  v7[4] = 0;
  v7[5] = 0;
  v7[6] = 0;
  v7[7] = 0;
  v7[3] = v5;
  v7[15] = 0;
  v7[12] = 0;
  v7[17] = 0;
  v7[10] = 0;
  if ( (v6 & 1) == 0 )
    v7[18] = 0;
  v8 = *((_DWORD *)off_117AAC + 8);
  if ( v8 )
  {
    v9 = *(_BYTE **)off_117AB0;
    *(_DWORD *)off_117AB4 = 0x80000000;
    if ( *v9 == 3 && v8 == dword_117AC0 + 1320 * *(unsigned __int8 *)(a1 + 28) )
      *(_DWORD *)(v8 + 120) = *((_DWORD *)off_117AC4 + 4);
  }
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_117AB8 = 1;
  }
  v10 = (int *)off_117ABC;
  ++*(_DWORD *)off_117ABC;
  sub_11A4D0(a1, a2);
  list_push_tail(v4 + 12);
  sub_12B098(*(unsigned __int8 *)(a1 + 28), *(unsigned __int8 *)(a1 + 29), 0);
  if ( (*(_WORD *)(a1 + 30) & 1) == 0 )
    ++*((_DWORD *)off_117AA4 + 126);
  fw_state_flag_check(a1);
  result = sub_11708C(a1, a2, 0);
  v12 = *v10;
  *(_WORD *)(a1 + 82) |= 1u;
  if ( v12 )
  {
    v13 = v12 - 1;
    v14 = *(_DWORD *)off_117AB8;
    *v10 = v13;
    if ( !v13 )
    {
      if ( v14 )
        __enable_irq();
    }
  }
  return result;
}

