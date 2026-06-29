// fwstruct annotate: 139ff8_sub_139FF8.c
// sub_139FF8 @ 0x139ff8, size 1160 bytes
// Doc: sub_1239FF8 [mac]: Frame/status processing helper using r0+0x54 field
// sub_1239FF8 [mac]: Frame/status processing helper using r0+0x54 field
int __fastcall sub_139FF8(unsigned int a1)
{
  unsigned int v1; // r7
  int v3; // r3
  _BYTE *v4; // r4
  int v5; // r6
  unsigned __int8 *v7; // r6
  __int16 v8; // r8
  unsigned __int16 v9; // r3
  int v10; // r11
  int v11; // r9
  char v12; // r3
  __int16 v13; // r3
  int v14; // r10
  int v15; // r3
  int v16; // r1
  int v17; // r12
  int v18; // r2
  int v19; // r1
  int v20; // r0
  __int16 v21; // r1
  _BYTE **v22; // r11
  int v23; // r1
  int v24; // r3
  _WORD *v25; // r1
  unsigned __int8 *v26; // r9
  int v27; // r0
  __int16 v28; // r3
  char v29; // r0
  int v30; // r1
  int v31; // r0
  int v32; // r7
  unsigned __int64 v33; // r0
  int v34; // r0
  int v35; // r2
  int v36; // r1
  _WORD *v37; // r10
  BOOL n1c0; // r0
  int v39; // r0
  int v40; // [sp+0h] [bp-Ch]
  _WORD *v41; // [sp+0h] [bp-Ch]
  int v42; // [sp+0h] [bp-Ch]
  int v43; // [sp+4h] [bp-8h]
  int v44; // [sp+4h] [bp-8h]
  int v45; // [sp+4h] [bp-8h]

  v1 = *(_DWORD *)(a1 + 84);
  if ( (v1 & 0x2000) == 0 )
  {
    v3 = *((unsigned __int8 *)off_13A2D4 + 16);
    if ( v3 != 255 )
    {
      v4 = off_13A2D8;
LABEL_4:
      v4[10] = v3;
      sub_138E1C(a1, 128);
      v5 = 1;
      goto LABEL_5;
    }
LABEL_35:
    v5 = 0;
    goto LABEL_5;
  }
  v4 = off_13A2D8;
  v7 = *(unsigned __int8 **)(*(_DWORD *)(a1 + 28) + 8);
  v8 = *(_WORD *)v7;
  *(_WORD *)off_13A2D8 = *(_WORD *)v7;
  *(_DWORD *)(a1 + 96) = 0;
  v4[9] = -1;
  v4[10] = -1;
  v9 = *((_WORD *)v7 + 11);
  *((_WORD *)v4 + 1) = v9;
  v4[48] = 0;
  *((_WORD *)v4 + 2) = v9 >> 4;
  v4[6] = v9 & 0xF;
  if ( (v8 & 0x88) == 0x88 )
  {
    v10 = v8 & 0x300;
    if ( v10 == 768 )
      v28 = *((_WORD *)v7 + 15);
    else
      v28 = *((_WORD *)v7 + 12);
    v4[7] = v28 & 7;
  }
  else
  {
    v4[7] = 0;
    v10 = v8 & 0x300;
  }
  v11 = v8 & 0xFC;
  if ( v10 == 768 )
    v12 = 30;
  else
    v12 = 24;
  if ( v11 == 136 )
    v12 += 2;
  if ( v8 < 0 )
    v12 += 4;
  v4[8] = v12;
  if ( (v7[4] & 1) != 0 )
    v4[48] = 8;
  if ( (v8 & 0x100) != 0 )
  {
    *((_WORD *)v4 + 18) = *((_WORD *)v7 + 8);
    *((_WORD *)v4 + 19) = *((_WORD *)v7 + 9);
    *((_WORD *)v4 + 20) = *((_WORD *)v7 + 10);
    v13 = *(_WORD *)v7;
    if ( (*(_WORD *)v7 & 0x200) != 0 )
    {
LABEL_19:
      if ( (v13 & 0x100) != 0 )
      {
        *((_WORD *)v4 + 21) = *((_WORD *)v7 + 12);
        *((_WORD *)v4 + 22) = *((_WORD *)v7 + 13);
        *((_WORD *)v4 + 23) = *((_WORD *)v7 + 14);
      }
      else
      {
        *((_WORD *)v4 + 21) = *((_WORD *)v7 + 8);
        *((_WORD *)v4 + 22) = *((_WORD *)v7 + 9);
        *((_WORD *)v4 + 23) = *((_WORD *)v7 + 10);
      }
      if ( (v1 & 0x2000000) != 0 )
        goto LABEL_22;
LABEL_38:
      if ( v4[115]
        && (v1 & 0x200) == 0
        && *((unsigned __int16 *)v4 + 54) == *((unsigned __int16 *)v7 + 5)
        && *((unsigned __int16 *)v4 + 55) == *((unsigned __int16 *)v7 + 6)
        && *((unsigned __int16 *)v4 + 56) == *((unsigned __int16 *)v7 + 7) )
      {
        v4[114] = (*(_WORD *)v7 & 0x1400) == 4096;
      }
      if ( (v8 & 0xC) != 0 )
        goto LABEL_56;
      v24 = *((unsigned __int16 *)v7 + 11);
      if ( (*(_WORD *)v7 & 0x800) != 0 )
      {
        v25 = off_13A480;
        v26 = v7 + 10;
        if ( *((unsigned __int16 *)v4 + 51) == v24 )
        {
          v41 = off_13A480;
          if ( !sub_1437AC(v7 + 10, off_13A480, 6) )
            goto LABEL_34;
          v8 = *(_WORD *)v4;
          LOWORD(v24) = *((_WORD *)v7 + 11);
          v25 = v41;
        }
      }
      else
      {
        v25 = off_13A2E4;
        v26 = v7 + 10;
      }
      v27 = *(_DWORD *)v26;
      v25[2] = *((_WORD *)v26 + 2);
      *((_WORD *)v4 + 51) = v24;
      *((_DWORD *)v4 + 24) = v27;
      if ( (v8 & 0x4000) != 0 && ((v1 & 0x7C) != 4 || !sub_1388EC((int)v7, v1)) )
LABEL_56:
        v5 = scan_chan_eval_n8c8(v7);
      else
        v5 = sub_139B4C(a1, 255);
      goto LABEL_57;
    }
  }
  else
  {
    *((_WORD *)v4 + 18) = *((_WORD *)v7 + 2);
    *((_WORD *)v4 + 19) = *((_WORD *)v7 + 3);
    *((_WORD *)v4 + 20) = *((_WORD *)v7 + 4);
    v13 = *(_WORD *)v7;
    if ( (*(_WORD *)v7 & 0x200) != 0 )
      goto LABEL_19;
  }
  *((_WORD *)v4 + 21) = *((_WORD *)v7 + 5);
  *((_WORD *)v4 + 22) = *((_WORD *)v7 + 6);
  *((_WORD *)v4 + 23) = *((_WORD *)v7 + 7);
  if ( (v1 & 0x2000000) == 0 )
    goto LABEL_38;
LABEL_22:
  v14 = dword_13A2EC;
  v15 = (unsigned __int8)((v1 >> 15) - 16);
  v16 = dword_13A2EC + 696 * v15;
  if ( !*(_BYTE *)(v16 + 37) )
    goto LABEL_34;
  v17 = *(unsigned __int8 *)(v16 + 34);
  v18 = dword_13A2E0;
  v19 = *(_DWORD *)(v16 + 184);
  v4[9] = v15;
  *((_DWORD *)v4 + 6) = v1;
  v20 = *(unsigned __int8 *)(v18 + 1320 * v17 + 106);
  v4[10] = v17;
  v40 = v19;
  if ( v20 != 2 || (v4[36] & 1) != 0 )
  {
    v21 = v8;
  }
  else
  {
    v29 = mmio_block_write_n_e18((int *)dword_13A2E8);
    v21 = *(_WORD *)v4;
    v15 = (unsigned __int8)((v1 >> 15) - 16);
    v18 = dword_13A2E0;
    v4[11] = v29;
  }
  if ( v10 == 768 )
    *(_DWORD *)(a1 + 96) |= 4u;
  if ( (v21 & 0x4000) != 0 )
  {
    v43 = v15;
    v34 = sub_1388EC((int)v7, *((_DWORD *)v4 + 6));
    v15 = v43;
    v18 = dword_13A484;
    if ( !v34 )
      goto LABEL_34;
  }
  v22 = (_BYTE **)off_13A2F0;
  if ( **(_BYTE **)off_13A2F0 == 1 && !*((_BYTE *)off_13A488 + 412) )
  {
    v23 = v8 & 0xC;
    if ( v23 == 8 )
    {
      if ( !*(_BYTE *)(v18 + 1320 * (unsigned __int8)v4[10] + 106) )
      {
        v45 = v15;
        v39 = fmac_bt_idle_handler((char *)v7, v1, v15);
        v15 = v45;
        if ( !v39 )
          goto LABEL_34;
      }
      goto LABEL_83;
    }
LABEL_30:
    if ( *(unsigned __int8 *)(v14 + 696 * v15 + 669) > 1u
      || !v40
      || (unsigned int)*(unsigned __int8 *)(v40 + 96) - 1 > 1 )
    {
      goto LABEL_31;
    }
    goto LABEL_72;
  }
  v23 = v8 & 0xC;
  if ( v23 != 8 )
    goto LABEL_30;
LABEL_83:
  v44 = v15;
  sub_139F94((char *)v7, v1, *(unsigned __int16 *)(a1 + 48));
  v15 = v44;
  if ( *(unsigned __int8 *)(v14 + 696 * v44 + 669) > 1u || !v40 || (unsigned int)*(unsigned __int8 *)(v40 + 96) - 1 > 1 )
    goto LABEL_84;
  v23 = 8;
LABEL_72:
  if ( (v8 & 0x4000) != 0 && (v4[36] & 1) == 0 )
    *(_BYTE *)(v14 + 696 * v15 + 669) = 2;
LABEL_31:
  if ( v23 == 4 )
  {
    if ( v11 == 132 )
      sub_1393F8(v15, (int)v7);
    goto LABEL_34;
  }
  if ( v23 != 8 )
  {
    if ( v23 )
      goto LABEL_34;
    if ( (v8 & 0x800) != 0 )
    {
      v30 = *((unsigned __int16 *)v4 + 1);
      if ( *(unsigned __int16 *)(v14 + 696 * v15 + 552) == v30 )
        goto LABEL_34;
    }
    else
    {
      LOWORD(v30) = *((_WORD *)v4 + 1);
    }
    v31 = (unsigned __int8)v4[48] << 30;
    *(_WORD *)(v14 + 696 * v15 + 552) = v30;
    if ( v31 < 0 )
    {
      v32 = *((_DWORD *)v4 + 8);
      v33 = *((_QWORD *)v4 + 2);
      if ( *(_QWORD *)(v32 + 64) >= v33 )
      {
        sub_12ECB0(dword_13A48C);
        goto LABEL_34;
      }
      *(_QWORD *)(v32 + 64) = v33;
    }
    if ( **v22 == 1 && *v7 == 128 && !v7[1] )
    {
LABEL_34:
      v3 = *((unsigned __int8 *)off_13A2D4 + 16);
      if ( v3 != 255 )
        goto LABEL_4;
      goto LABEL_35;
    }
    v5 = sub_139B4C(a1, (unsigned __int8)v4[9]);
    goto LABEL_57;
  }
LABEL_84:
  if ( (v8 & 0x40) != 0 )
    goto LABEL_34;
  if ( (v8 & 0x80) != 0 )
  {
    v35 = 1;
    if ( (v4[48] & 8) == 0 )
    {
      v42 = v15;
      n1c0 = rf_channel_status_get_n1c0(v15, (unsigned __int8)v4[7]);
      v15 = v42;
      v35 = 1;
      if ( n1c0 )
      {
        v5 = tx_desc_slot_lookup(a1, v42);
        goto LABEL_57;
      }
    }
    v37 = (_WORD *)(v14 + 2 * ((unsigned __int8)v4[7] + 277 + 348 * v15));
  }
  else
  {
    v35 = 0;
    v37 = (_WORD *)(v14 + 696 * v15 + 552);
  }
  v36 = *((unsigned __int16 *)v4 + 1);
  if ( (v8 & 0x800) != 0 && (unsigned __int16)*v37 == v36 )
    goto LABEL_34;
  *v37 = v36;
  v5 = bt_rx_pkt_process_1390e8(a1, v15, v35);
LABEL_57:
  v3 = *((unsigned __int8 *)off_13A2D4 + 16);
  if ( v3 != 255 && !v5 )
    goto LABEL_4;
LABEL_5:
  sub_12F770((_DWORD **)dword_13A2DC);
  return v5;
}

