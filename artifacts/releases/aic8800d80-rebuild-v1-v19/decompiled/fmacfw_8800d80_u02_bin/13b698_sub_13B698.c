// sub_13B698 @ 0x13b698, size 576 bytes
// Doc: sub_123B698 [unknown]: Complex handler with multiple parameters from stack
// sub_123B698 [unknown]: Complex handler with multiple parameters from stack
int __fastcall sub_13B698(int a1, int a2, int a3, char a4, __int16 a5, __int16 a6, int a7)
{
  int v7; // r9
  int v8; // r7
  int v9; // r8
  __int16 **v10; // r10
  int v13; // r0
  int v14; // r2
  int result; // r0
  int v16; // r4
  int v17; // r3
  int v18; // r2
  int v19; // r1
  int v20; // r5
  int v21; // r12
  __int16 v22; // r2
  int v23; // r5
  int v24; // r6
  _DWORD *v25; // r1
  int v26; // r5
  _WORD *v28; // [sp+18h] [bp-14h]

  v7 = dword_13B8F4;
  v8 = dword_13B8D8;
  v9 = *(unsigned __int8 *)(dword_13B8F4 + 696 * a1 + 34);
  v10 = (__int16 **)off_13B8F8;
  v13 = *(_DWORD *)(dword_13B8D8 + 1320 * v9 + 72);
  if ( !v13 )
  {
    if ( **(__int16 **)off_13B8F8 >= 0 )
    {
LABEL_19:
      result = sub_118C44(1, 512);
      v16 = result;
      if ( !result )
        return result;
      goto LABEL_4;
    }
LABEL_18:
    sub_12F46C(dword_13B8E4, dword_13B8E0, 520);
    goto LABEL_19;
  }
  v14 = *(unsigned __int8 *)(v13 + 4);
  if ( **(__int16 **)off_13B8F8 < 0 && v14 == 2 )
    goto LABEL_18;
  result = sub_118C44((*(unsigned __int8 *)(dword_13B8D8 + 1320 * v9 + 1224) | v14) != 0, 512);
  v16 = result;
  if ( !result )
    return result;
LABEL_4:
  sub_12C4E8(v8 + 1320 * v9, v16);
  v17 = *(_DWORD *)(v16 + 72);
  v18 = 696 * a1 + 38;
  *(_BYTE *)(v17 + 108) = -48;
  *(_BYTE *)(v17 + 109) = 0;
  *(_BYTE *)(v17 + 110) = 0;
  *(_BYTE *)(v17 + 111) = 0;
  *(_WORD *)(v17 + 112) = *(_WORD *)(v7 + v18);
  v19 = v7 + v18;
  v20 = 1320 * v9 + 100;
  *(_WORD *)(v17 + 114) = *(_WORD *)(v7 + v18 + 2);
  *(_WORD *)(v17 + 116) = *(_WORD *)(v7 + v18 + 4);
  *(_WORD *)(v17 + 118) = *(_WORD *)(v8 + v20);
  v21 = v8 + v20;
  *(_WORD *)(v17 + 120) = *(_WORD *)(v8 + v20 + 2);
  v28 = (_WORD *)(v17 + 108);
  *(_WORD *)(v17 + 122) = *(_WORD *)(v8 + v20 + 4);
  if ( *(_BYTE *)(v8 + 1320 * v9 + 106) == 2 )
  {
    *(_WORD *)(v17 + 124) = *(_WORD *)(v8 + v20);
    *(_WORD *)(v17 + 126) = *(_WORD *)(v21 + 2);
    *(_WORD *)(v17 + 128) = *(_WORD *)(v21 + 4);
  }
  else
  {
    *(_WORD *)(v17 + 124) = *(_WORD *)(v7 + v18);
    *(_WORD *)(v17 + 126) = *(_WORD *)(v19 + 2);
    *(_WORD *)(v17 + 128) = *(_WORD *)(v19 + 4);
  }
  v22 = *((_WORD *)off_13B8DC + 254) + 1;
  *((_WORD *)off_13B8DC + 254) = v22;
  *(_WORD *)(v17 + 130) = 16 * v22;
  *(_BYTE *)(v16 + 51) = 0;
  *(_BYTE *)(v16 + 53) = 0;
  *(_BYTE *)(v16 + 28) = v9;
  *(_BYTE *)(v16 + 29) = a1;
  if ( rf_msg_process_body_n37(v16, 208, 3) == 1 )
  {
    fmac_main_loop_0a0(v16, v28, 24);
    v23 = *(unsigned __int8 *)(v16 + 51) + 24;
  }
  else
  {
    v23 = 24;
  }
  if ( a3 == 1 )
  {
    v24 = 3;
    v23 += sub_130D4C((int)v28 + v23, a2, a5, a4, a6);
  }
  else if ( a3 == 2 )
  {
    v24 = *(unsigned __int8 *)(dword_13B8E8 + *(unsigned __int8 *)(a2 + 22));
    v23 += sub_130D90((int)v28 + v23, a2, a6);
  }
  else if ( a3 )
  {
    if ( **v10 < 0 )
      sub_12F49C(dword_13B8F0, dword_13B8EC, 269);
    v24 = 3;
  }
  else
  {
    v24 = *(unsigned __int8 *)(dword_13B8E8 + *(unsigned __int8 *)(a2 + 22));
    v23 += sub_130D14((int)v28 + v23, a2);
  }
  v25 = *(_DWORD **)(v16 + 76);
  v26 = v23 + *(unsigned __int8 *)(v16 + 53);
  v25[8] = v25[7] - 1 + v26;
  v25[9] = v26 + 4;
  if ( a7 )
  {
    *(_DWORD *)(v16 + 88) = a7;
    *(_DWORD *)(v16 + 92) = a2;
  }
  return rf_param_get_status(v16, v24);
}

