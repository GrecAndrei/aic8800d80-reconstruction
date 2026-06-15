// rf_chan_init_n4e8 @ 0x11b4e8, size 448 bytes
// Doc: rf_chan_init_n4e8 [rf]: Initialize RF channel context from data tables, call helper, read signed halfword
// rf_chan_init_n4e8 [rf]: Initialize RF channel context from data tables, call helper, read signed halfword
int __fastcall rf_chan_init_n4e8(int a1)
{
  __int16 **v1; // r7
  _BYTE *v2; // r6
  int v4; // r0
  int v5; // r5
  int v6; // r3
  _DWORD *v7; // r4
  int v8; // r3
  int v9; // r2
  int v10; // r3
  int v11; // r2
  char *v12; // r0
  int v13; // r2
  int v14; // r0
  int result; // r0
  int *v16; // r5
  int v17; // r1
  int v18; // r6
  int v19; // r3
  int v20; // r2
  int *v21; // r3
  int v22; // r3
  int v23; // r3
  int v24; // r1
  int v25; // r3
  int v26; // r2
  int v27; // r2
  int v28; // r7
  int v29; // r3
  int v30; // r2

  v1 = (__int16 **)off_11B6A8;
  v2 = off_11B6AC;
  v4 = sub_11E7AC(dword_11B6B0);
  v5 = v4;
  if ( **v1 >= 0 )
  {
    v6 = (unsigned __int8)*v2;
    if ( *v2 )
    {
LABEL_3:
      v7 = off_11B6B4;
      goto LABEL_4;
    }
LABEL_26:
    v7 = off_11B6B4;
    v8 = *((_DWORD *)off_11B6B4 + 10);
    goto LABEL_6;
  }
  if ( a1 == v4 )
  {
    v6 = (unsigned __int8)*v2;
    if ( *v2 )
      goto LABEL_3;
  }
  else
  {
    rf_cmd_send_n264(dword_11B6E0, dword_11B6DC, 1958);
    v6 = (unsigned __int8)*v2;
    if ( *v2 )
      goto LABEL_3;
    if ( **v1 >= 0 )
      goto LABEL_26;
  }
  v7 = off_11B6B4;
  v8 = *((_DWORD *)off_11B6B4 + 10);
  if ( !v8 )
  {
    rf_cmd_send_n264(dword_11B6E4, dword_11B6DC, 1960);
    v6 = (unsigned __int8)*v2;
LABEL_4:
    if ( v6 != 1 )
    {
LABEL_5:
      v8 = v7[10];
      goto LABEL_6;
    }
    msg_parse(dword_11B6CC, *((unsigned __int8 *)v7 + 88));
    v23 = *((unsigned __int8 *)v7 + 88);
    v24 = v23 << 28;
    if ( (v23 & 8) != 0 )
    {
      v25 = dword_11B6E8;
    }
    else
    {
      if ( (v23 & 4) == 0 )
      {
        v25 = v7[11];
        if ( !v25 )
          goto LABEL_5;
LABEL_33:
        v27 = v7[10];
        if ( v27 )
        {
          v24 = 1;
          *(_BYTE *)(v27 + 16) = 1;
        }
        v7[10] = v25;
        v7[11] = 0;
        v28 = *(unsigned __int8 *)(v25 + 24);
        *(_BYTE *)(v25 + 16) = 4;
        if ( v28 == 3 )
        {
          msg_parse(dword_11B6D4, v24);
          sub_11E1E4(2);
        }
        goto LABEL_5;
      }
      v25 = dword_11B6D0;
    }
    v26 = v7[11];
    if ( v26 != v25 && v26 )
    {
      v24 = 1;
      *(_BYTE *)(v26 + 16) = 1;
    }
    goto LABEL_33;
  }
LABEL_6:
  *(_BYTE *)(v8 + 16) = 1;
  v9 = v7[20];
  v10 = 0;
  *v2 = 0;
  if ( v9 )
  {
    v11 = *((unsigned __int8 *)v7 + 90);
    v7[20] = 0;
    if ( !v11 )
    {
      *(_DWORD *)(v5 + 8) = 0;
      goto LABEL_15;
    }
    if ( v11 == 1 || (v10 = v7[4]) == 0 )
    {
      v12 = (char *)off_11B6EC;
      if ( *((unsigned __int8 *)off_11B6EC + 24) == 255 )
      {
        if ( *((unsigned __int8 *)off_11B6EC + 52) == 255 )
        {
          if ( *((unsigned __int8 *)off_11B6EC + 80) == 255 )
          {
            *(_DWORD *)(v5 + 8) = v10;
            goto LABEL_15;
          }
          v12 = (char *)off_11B6EC + 56;
        }
        else
        {
          v12 = (char *)off_11B6EC + 28;
        }
      }
    }
    else
    {
      v12 = *(char **)(dword_11B6B8 + 224 * *(unsigned __int8 *)(v10 + 8) + 72);
    }
    *(_DWORD *)(v5 + 8) = v12;
  }
  else
  {
    v12 = *(char **)(v5 + 8);
  }
  if ( v12 )
  {
    if ( v7[11] )
      v7[11] = v12;
    else
      sub_11ADD0((int)v12);
  }
LABEL_15:
  list_push_tail(dword_11B6BC);
  v14 = v7[10];
  if ( *(unsigned __int8 *)(v14 + 24) > 2u )
    rf_state_reset_n_3a4(v14, 0, v13);
  result = v7[8];
  v7[18] = result;
  if ( result )
  {
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(_DWORD *)off_11B6C0 = 1;
    }
    v16 = (int *)off_11B6C8;
    v17 = *(_DWORD *)(result + 4);
    v18 = *(_DWORD *)off_11B6C8;
    v19 = v17 - *((_DWORD *)off_11B6C4 + 4);
    v20 = *(_DWORD *)off_11B6C8 + 1;
    *(_DWORD *)off_11B6C8 = v20;
    if ( v19 - 64 >= 0 )
    {
      result = sub_11AB18(dword_11B6D8, v17);
      if ( *v16 )
      {
        v29 = *v16 - 1;
        v30 = *(_DWORD *)off_11B6C0;
        *v16 = v29;
        if ( !v29 )
        {
          if ( v30 )
            __enable_irq();
        }
      }
    }
    else
    {
      if ( v20 )
      {
        v21 = (int *)off_11B6C0;
        *v16 = v18;
        v22 = *v21;
        if ( !v18 )
        {
          if ( v22 )
            __enable_irq();
        }
      }
      return ((int (*)(void))v7[17])();
    }
  }
  return result;
}

