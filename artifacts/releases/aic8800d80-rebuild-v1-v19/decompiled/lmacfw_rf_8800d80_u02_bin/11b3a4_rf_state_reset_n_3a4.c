// rf_state_reset_n_3a4 @ 0x11b3a4, size 282 bytes
// Doc: rf_state_reset_n_3a4 [rf]: RF state reset clearing context fields
// rf_state_reset_n_3a4 [rf]: RF state reset clearing context fields
int __fastcall rf_state_reset_n_3a4(int result, int a2, int a3)
{
  _BYTE *v3; // r6
  int v4; // r4
  int v6; // r3
  bool v7; // zf
  int v8; // r3
  _WORD *v9; // r8
  _WORD *v10; // r0
  _WORD *v11; // r7
  int v12; // r0
  int v13; // r2
  unsigned int *v14; // r12
  _DWORD *v15; // r1
  char v16; // r3
  _DWORD *v17; // r7
  int v18; // r2
  unsigned int v19; // r3

  v3 = off_11B4C0;
  v4 = result;
  *((_DWORD *)off_11B4C0 + 10) = 0;
  if ( a2 )
  {
    v6 = *(unsigned __int8 *)(result + 24);
    if ( v6 != 3 )
      goto LABEL_3;
  }
  else
  {
    result = rf_link_state_check(result, 0, a3);
    v6 = *(unsigned __int8 *)(v4 + 24);
    if ( v6 != 3 )
    {
LABEL_3:
      v7 = v6 == 4;
      v8 = (unsigned __int8)v3[88];
      if ( v7 )
      {
        v3[88] = v8 & 0xFB;
        if ( *(_WORD *)(v4 + 14) )
        {
          result = ipc_msg_send_n_d58(v4);
          v8 = (unsigned __int8)v3[88];
        }
        else
        {
          v8 &= 0xDBu;
        }
      }
      goto LABEL_4;
    }
  }
  v3[88] &= ~8u;
  v9 = (_WORD *)sub_11CD3C();
  v10 = (_WORD *)rf_setup_dispatch(79, 4, 0, 12);
  *v10 = *v9;
  v11 = v10;
  v12 = sub_11CD50(v9);
  v13 = dword_11B4C4;
  v14 = (unsigned int *)off_11B4E4;
  v15 = off_11B4C8;
  *((_DWORD *)v11 + 1) = (unsigned int)(((unsigned int)dword_11B4C4 * (unsigned __int64)(unsigned int)v12) >> 32) >> 6;
  *((_DWORD *)v11 + 2) = (unsigned int)(((unsigned int)v13 * (unsigned __int64)*v14) >> 32) >> 6;
  *((_BYTE *)v11 + 2) = 0;
  v16 = 10;
  while ( 1 )
  {
    --v16;
    if ( (unsigned __int8)*v15 )
      break;
    if ( !v16 )
      goto LABEL_13;
  }
  *((_BYTE *)v11 + 2) = *v15;
LABEL_13:
  sub_11DE50(v11);
  v17 = off_11B4D0;
  v18 = **(__int16 **)off_11B4CC;
  v19 = *((_DWORD *)off_11B4D0 + 1) & 0xFFFFDDFF;
  *((_DWORD *)off_11B4D0 + 1) = v19;
  if ( v18 < 0 && *(_DWORD *)off_11B4D8 << 28 )
  {
    sub_1219F4(dword_11B4E0, dword_11B4DC, 472);
    v19 = v17[1];
  }
  *(_DWORD *)off_11B4D4 = v19 | *v17;
  result = sub_11DED8(142, 2, 255);
  v8 = (unsigned __int8)v3[88];
LABEL_4:
  *(_BYTE *)(v4 + 24) = -1;
  v3[88] = v8 & 0xEF;
  if ( !(v8 << 30) )
  {
    if ( a2 )
      return result;
    return sub_118E58();
  }
  result = phy_flag_check_or_set();
  if ( !a2 )
    return sub_118E58();
  return result;
}

