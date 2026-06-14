// bt_hci_cmd_handler @ 0x11d760, size 1128 bytes
// Doc: bt_hci_cmd_handler [bt]: BT HCI command handler entry, reads opcode offset 0x30
// bt_hci_cmd_handler [bt]: BT HCI command handler entry, reads opcode offset 0x30
BOOL __fastcall bt_hci_cmd_handler(int a1)
{
  __int16 **v1; // r10
  int v2; // r8
  int v3; // r3
  __int16 *v5; // r9
  __int16 v6; // r11
  unsigned int v7; // r6
  int v8; // r5
  int v10; // r2
  unsigned int v11; // r7
  int v12; // r3
  unsigned int v13; // r3
  unsigned __int8 *v14; // r5
  int v15; // r2
  int v16; // r3
  int v17; // r11
  int v18; // r7
  int v19; // r4
  __int64 v20; // r0
  __int64 v21; // r0
  unsigned int v22; // r2
  unsigned __int64 v23; // r4
  __int64 v24; // r0
  __int64 v25; // r0
  __int64 v26; // r0
  int v27; // r0
  _BYTE *v28; // r4
  _DWORD *v29; // r2
  int v30; // r8
  int *v31; // r11
  _DWORD *v32; // r7
  _DWORD *v33; // r6
  int v34; // r9
  _DWORD *v35; // r3
  _DWORD *v36; // r7
  _DWORD *v37; // r9
  int v38; // r5
  int v39; // r6
  int v40; // r5
  int v41; // r3
  int v42; // r2
  _DWORD *v43; // r6
  int v44; // r2
  unsigned int v45; // r3
  _DWORD *v46; // r6
  int v47; // r1
  unsigned int v48; // r3
  unsigned int v49; // [sp+4h] [bp-18h]
  int v50; // [sp+4h] [bp-18h]
  int v51; // [sp+8h] [bp-14h]
  int v52; // [sp+Ch] [bp-10h]
  int v53; // [sp+14h] [bp-8h] BYREF

  if ( *(_WORD *)(a1 + 48) )
  {
    v1 = (__int16 **)off_11DAAC;
    v2 = *(_DWORD *)(a1 + 28);
    v3 = **(__int16 **)off_11DAAC;
    if ( v3 < 0 && !v2 )
    {
      v8 = 0;
      sub_12F630(dword_11DA8C, dword_11DA88, 423, v3);
      return v8;
    }
    v5 = *(__int16 **)(v2 + 8);
    v6 = *v5;
    v7 = *(_DWORD *)(a1 + 84);
    if ( *((_BYTE *)off_11DA70 + 408)
      && (*((_DWORD *)off_11DA74 + 1) & 0x40) != 0
      && (*(_DWORD *)(a1 + 84) & 0x600) == 0x200 )
    {
      if ( (v6 & 0xFC) == 0xC4 )
        ++*(_DWORD *)off_11DA90;
    }
    else
    {
      if ( (dword_11DA78 & ~v7) != 0 )
        return 0;
      *(_DWORD *)(a1 + 84) = v7 & 0xFEFFFFFF;
      if ( v3 < 0 )
      {
        v8 = (v7 >> 15) & 0x1F0;
        if ( !v8 )
        {
          sub_12F630(dword_11DA94, dword_11DA88, 475, v3);
          return v8;
        }
      }
      v10 = dword_11DA7C;
      v11 = (unsigned __int8)((v7 >> 15) - 16);
      v12 = dword_11DA7C + 696 * v11;
      v8 = *(unsigned __int8 *)(v12 + 37);
      if ( !*(_BYTE *)(v12 + 37) )
      {
        *(_DWORD *)(a1 + 84) = v7 & 0xFCFFFFFF;
        return v8;
      }
      if ( v11 <= 0x23 )
        *(_DWORD *)(v12 + 664) = *((_DWORD *)off_11DA80 + 4);
      v13 = v10 + 696 * v11;
      if ( *(unsigned __int16 *)(v13 + 32) == 0xFFFF )
      {
        if ( (v6 & 0xFC) != 0x80 )
        {
          *(_DWORD *)(a1 + 84) = v7 & 0xFCFFFFFF;
          return 0;
        }
        v49 = *(_DWORD *)(v13 + 44);
        *(_DWORD *)(a1 + 84) = v7 & 0xFE007FFF | ((*(unsigned __int8 *)(v49 + 35) + 16) << 15);
      }
      else
      {
        v49 = v10 + 696 * v11;
      }
      v51 = *(unsigned __int8 *)(v49 + 34);
      v14 = (unsigned __int8 *)(dword_11DA84 + 1320 * v51);
      v52 = 1320 * v51;
      sub_11D0B8(v5, v11, v14[107]);
      if ( !v14[108] )
        return 0;
      v15 = v14[106];
      v16 = dword_11DA84;
      if ( v14[106] )
      {
        if ( (v6 & 4) != 0 )
          goto LABEL_38;
        goto LABEL_36;
      }
      if ( (v6 & 0x300) != 0x200 )
      {
        v8 = v6 & 4;
        if ( (v6 & 4) != 0 )
          goto LABEL_19;
        goto LABEL_36;
      }
      v27 = sub_1437AC(v5 + 8, v52 + 100 + dword_11DA84, 6);
      v16 = dword_11DA84;
      if ( v27 )
      {
        v8 = v6 & 4;
        if ( (v6 & 4) != 0 )
        {
LABEL_37:
          v15 = *(unsigned __int8 *)(v16 + 1320 * v51 + 106);
          if ( !*(_BYTE *)(v16 + 1320 * v51 + 106) )
          {
LABEL_19:
            v17 = v6 & 0xFC;
            v18 = v52 + v16;
            if ( v17 == 128 )
            {
              v53 = 0;
              v40 = bt_cmd_handler_n830(a1 + 20, v18, v49, &v53);
              fmac_bt_chan_ctx_load(v53, *(unsigned __int16 *)(a1 + 48), v18);
              sub_12057C(v18);
              if ( v40 )
                bt_state_check_4c8(v18, v2, a1 + 20);
              return v40 == 0;
            }
            if ( v17 == 80 )
            {
              v28 = off_11DA98;
              if ( *((_BYTE *)off_11DA98 + 29) == 7 )
              {
                v8 = *((unsigned __int8 *)off_11DA98 + 36);
                if ( !*((_BYTE *)off_11DA98 + 36) )
                {
                  v29 = off_11DA9C;
                  v30 = *(_DWORD *)off_11DA9C & 0xF;
                  if ( v30 )
                  {
                    if ( (__get_CPSR() & 1) == 0 )
                    {
                      __disable_irq();
                      *(_DWORD *)off_11DAA0 = 1;
                    }
                    v31 = (int *)off_11DAB0;
                    v32 = off_11DA9C;
                    v33 = off_11DA80;
                    ++*(_DWORD *)off_11DAB0;
                    *v32 = 0;
                    v34 = v33[4];
                    while ( *v32 << 28 )
                    {
                      if ( (unsigned int)(v33[4] - v34) > 0x7530 )
                        feature_guard_sdio(2, dword_11DBE4);
                    }
                    v35 = off_11DAA4;
                    v36 = off_11DA80;
                    if ( (*(_DWORD *)off_11DAA8 & *(_DWORD *)off_11DAA4 & 4) == 0 )
                    {
                      v50 = v8;
                      v37 = off_11DAA8;
                      v38 = *((_DWORD *)off_11DA80 + 4);
                      do
                      {
                        v39 = *v35 & *v37;
                        if ( (unsigned int)(v36[4] - v38) > 0x7530 )
                        {
                          feature_guard_sdio(2, dword_11DBC8);
                          v35 = off_11DBCC;
                        }
                      }
                      while ( (v39 & 4) == 0 );
                      v8 = v50;
                    }
                    *(_DWORD *)off_11DBD0 = 4;
                    if ( *v31 )
                    {
                      v41 = *v31 - 1;
                      v42 = *(_DWORD *)off_11DBD4;
                      *v31 = v41;
                      if ( !v41 )
                      {
                        if ( v42 )
                          __enable_irq();
                      }
                    }
                    v43 = off_11DBD8;
                    v44 = **v1;
                    v45 = *((_DWORD *)off_11DBD8 + 1) & 0xFFFFFDFF;
                    *((_DWORD *)off_11DBD8 + 1) = v45;
                    if ( v44 < 0 && *(_DWORD *)off_11DBE0 << 28 )
                    {
                      sub_12F6C4(dword_11DBEC, dword_11DBE8, 472);
                      v45 = v43[1];
                    }
                    *(_DWORD *)off_11DBDC = v45 | *v43;
                    *(_DWORD *)off_11DBE0 = 16 * v30;
                  }
                  else
                  {
                    v46 = off_11DBD8;
                    v47 = **v1;
                    v48 = *((_DWORD *)off_11DBD8 + 1) & 0xFFFFFDFF;
                    *((_DWORD *)off_11DBD8 + 1) = v48;
                    if ( v47 < 0 && *v29 << 28 )
                    {
                      sub_12F6C4(dword_11DBEC, dword_11DBE8, 472);
                      v48 = v46[1];
                    }
                    *(_DWORD *)off_11DBDC = v48 | *v46;
                  }
                  v28[36] = 1;
                  v28[29] = 0;
                  return v8;
                }
              }
            }
            else if ( v8 )
            {
              if ( v17 == 132 )
              {
                rf_cmd_send_n_d2_942c(v5, v7);
                return 0;
              }
            }
            else
            {
              rf_cmd_send_n_d2_942c(v5, v7);
              if ( *(_BYTE *)(dword_11DA84 + 1320 * v51 + 1224) && v17 == 208 )
              {
                bt_chan_check(v18, *(_DWORD *)(v2 + 8), *(unsigned __int16 *)(a1 + 48), *(_DWORD *)(a1 + 52));
                return v8;
              }
            }
            return 0;
          }
LABEL_38:
          if ( v15 == 2 && *(unsigned __int8 *)(v49 + 35) <= 0x23u )
          {
            v19 = *(char *)(a1 + 65);
            sub_101968();
            if ( !*(_BYTE *)(v49 + 689) )
            {
              v8 = *(char *)(v49 + 689);
              *(_BYTE *)(v49 + 689) = v19;
              return v8;
            }
            v20 = sub_142A70(*(char *)(v49 + 689));
            v21 = sub_142B44(v20, HIDWORD(v20), dword_11DA60, dword_11DA64);
            v22 = v21;
            LODWORD(v21) = v19;
            v23 = __PAIR64__(HIDWORD(v21), v22);
            v24 = sub_142A70(v21);
            v25 = sub_142B44(v24, HIDWORD(v24), dword_11DA68, dword_11DA6C);
            v26 = sub_1427D8(v23, HIDWORD(v23), v25, HIDWORD(v25));
            *(_BYTE *)(v49 + 689) = sub_143078(v26, HIDWORD(v26));
          }
          return 0;
        }
LABEL_36:
        sub_12B098(*(unsigned __int8 *)(v16 + 1320 * v51 + 107), v11, 1);
        v16 = dword_11DA84;
        v8 = 0;
        goto LABEL_37;
      }
    }
  }
  return 1;
}

