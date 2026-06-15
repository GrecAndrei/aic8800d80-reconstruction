// v23 annotated: sub_134A90 @ 0x134a90
// Original: 134a90_sub_134A90.c
// Primary struct: <unclustered>
//
// sub_134A90 @ 0x134a90, size 302 bytes
// Doc: sub_1234A90 [unknown]: Unidentified helper function at 0x134a90
// sub_1234A90 [unknown]: Unidentified helper function at 0x134a90
int sub_134A90()
{
  int v0; // r6
  __int16 v1; // r7
  int v2; // r8
  int v3; // r0
  int v4; // r0
  int v5; // r4
  int v6; // r5
  _WORD *v7; // r1
  int v8; // r3
  __int16 v9; // r2
  int v10; // t1
  int v11; // r0
  int v12; // r3
  int v13; // r6
  int v14; // r9
  int v15; // r0
  int v16; // r5
  _DWORD *v17; // r1
  int result; // r0
  int v19; // r6

  v0 = *((_DWORD *)off_134BC0 + 2);
  v1 = *((_WORD *)off_134BC0 + 6);
  v2 = *(unsigned __int8 *)(v0 + 116);
  if ( *(_BYTE *)(v0 + 1224) )
  {
    v3 = 1;
  }
  else
  {
    v3 = *(unsigned __int8 *)(v0 + 412);
    if ( *(_BYTE *)(v0 + 412) )
      v3 = 1;
  }
  v4 = sub_118C44(v3, 512);
  v5 = v4;
  if ( !v4 )
    return sub_134914();
  sub_12C4E8(v0, v4);
  v6 = *(_DWORD *)(v5 + 72);
  v7 = off_134BC8;
  v8 = dword_134BC4 + 696 * v2;
  v9 = *((_WORD *)off_134BC8 + 254);
  v10 = *(_DWORD *)(v8 + 38);
  v8 += 38;
  *(_DWORD *)(v6 + 112) = v10;
  *(_BYTE *)(v6 + 108) = -64;
  *(_WORD *)(v6 + 116) = *(_WORD *)(v8 + 4);
  *(_DWORD *)(v6 + 118) = *(_DWORD *)(v0 + 100);
  *(_WORD *)(v6 + 122) = *(_WORD *)(v0 + 104);
  v11 = *(_DWORD *)v8;
  *(_WORD *)(v6 + 128) = *(_WORD *)(v8 + 4);
  ++v9;
  v12 = dword_134BCC;
  *(_DWORD *)(v6 + 124) = v11;
  *(_BYTE *)(v6 + 109) = 0;
  *(_BYTE *)(v6 + 110) = 0;
  *(_BYTE *)(v6 + 111) = 0;
  v7[254] = v9;
  *(_WORD *)(v6 + 130) = 16 * v9;
  *(_DWORD *)(v5 + 88) = v12;
  *(_DWORD *)(v5 + 92) = v0;
  *(_BYTE *)(v5 + 28) = *(_BYTE *)(v0 + 107);
  *(_BYTE *)(v5 + 29) = *(_BYTE *)(v0 + 116);
  *(_BYTE *)(v5 + 51) = 0;
  *(_BYTE *)(v5 + 53) = 0;
  v13 = rf_msg_process_body_n37(v5, 192, 0);
  v14 = v6 + 108;
  if ( v13 == 1 )
  {
    fmac_main_loop_0a0(v5, v6 + 108, 24);
    v19 = *(unsigned __int8 *)(v5 + 51) + 24;
    v16 = sub_130838((_WORD *)(v14 + v19), v1) + v19 + *(unsigned __int8 *)(v5 + 53);
  }
  else
  {
    v15 = sub_130838((_WORD *)(v6 + 132), v1);
    v16 = v15 + 24;
    if ( v13 == 2 )
      v16 += sub_13C710(v5, v14, v15 + 24);
  }
  v17 = *(_DWORD **)(v5 + 76);
  v17[8] = v17[7] - 1 + v16;
  v17[9] = v16 + 4;
  result = rf_param_get_status(v5, 3);
  if ( !result )
    return sub_134914();
  return result;
}

