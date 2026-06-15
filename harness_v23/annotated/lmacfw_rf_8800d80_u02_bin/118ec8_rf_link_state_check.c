// v23 annotated: rf_link_state_check @ 0x118ec8
// Original: 118ec8_rf_link_state_check.c
// Primary struct: <unclustered>
//
// rf_link_state_check @ 0x118ec8, size 214 bytes
// Doc: rf_link_state_check [rf]: Checks current RF link state value against zero
// rf_link_state_check [rf]: Checks current RF link state value against zero
int __fastcall rf_link_state_check(int a1, int a2, int a3)
{
  int v3; // r3
  int *v4; // r8
  int *v5; // r4
  _DWORD *v6; // r5
  int v7; // r3
  int v8; // r7
  int v9; // r9
  int v10; // r2
  unsigned int v11; // r3
  int v12; // r2
  int v13; // r3
  int v14; // r3
  int result; // r0
  int v16; // r3
  int v17; // r3
  int v18; // r2

  v3 = **(__int16 **)off_118FA0;
  if ( v3 < 0 && sub_11E34C(0) == 4 )
    rf_cmd_send_n264(dword_118FD0, dword_118FCC, 1799);
  sub_11F74C(4, dword_118FA4, a3, v3);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_118FA8 = 1;
  }
  v4 = (int *)off_118FD4;
  v5 = (int *)off_118FAC;
  v6 = off_118FB0;
  ++*(_DWORD *)off_118FD4;
  v7 = *v5;
  *v5 = 0;
  v8 = v6[4];
  v9 = v7 & 0xF;
  while ( *v5 << 28 )
  {
    sub_115D4C();
    v11 = v6[4] - v8;
    if ( v11 > 0x7530 )
      sub_11F74C(4, dword_118FC8, v10, v11);
  }
  v12 = *(_DWORD *)off_118FB4;
  v13 = *(_DWORD *)off_118FB8;
  if ( v9 )
  {
    while ( (v13 & v12 & 4) == 0 )
    {
      v12 = *(_DWORD *)off_118FB4;
      v13 = *(_DWORD *)off_118FB8;
    }
  }
  v14 = *((unsigned __int8 *)off_118FBC + 90);
  *(_DWORD *)off_118FC0 = 4;
  if ( v14 )
    sub_115D64();
  result = sub_11E1E4(0);
  v16 = *v4;
  *((_WORD *)off_118FC4 + 8) = 0;
  if ( v16 )
  {
    v17 = v16 - 1;
    v18 = *(_DWORD *)off_118FA8;
    *v4 = v17;
    if ( !v17 )
    {
      if ( v18 )
        __enable_irq();
    }
  }
  return result;
}

