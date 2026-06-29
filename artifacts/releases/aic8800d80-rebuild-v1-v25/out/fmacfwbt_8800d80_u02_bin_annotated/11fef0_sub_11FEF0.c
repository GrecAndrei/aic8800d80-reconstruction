// fwstruct annotate: 11fef0_sub_11FEF0.c
// sub_11FEF0 @ 0x11fef0, size 1108 bytes
int __fastcall sub_11FEF0(int a1)
{
  int v2; // r6
  int *v3; // r8
  int v4; // r3
  _BYTE *v5; // r5
  int v6; // r2
  int v7; // r3
  int v8; // r3
  int v9; // r4
  int v10; // r6
  int v11; // r1
  int *v13; // r10
  int v14; // r9
  int v15; // r1
  int v16; // r3
  int v17; // r7
  int v18; // r5
  int v19; // r11
  int v20; // r1
  int v21; // r0
  int v22; // r3
  int v23; // r2
  int v24; // r0
  int v25; // r2
  int v26; // r0
  int v27; // r3
  int v28; // r2
  __int16 **v29; // r10
  _DWORD *v30; // r7
  int v31; // r1
  int v32; // r9
  unsigned int v33; // r3
  _DWORD *v34; // r0
  _DWORD *v35; // r3
  int v36; // r1
  int v37; // r2
  unsigned int v38; // r3
  int v39; // r3
  int v40; // r0
  int v41; // r3
  int v42; // r1
  int *v43; // r7
  int v44; // r3
  int v45; // r1
  int v46; // r2
  int v47; // r3
  _DWORD *v48; // r12
  _DWORD *v49; // r1
  int v50; // r0
  int v51; // [sp+8h] [bp-1Ch]
  int v52; // [sp+Ch] [bp-18h]
  int v53; // [sp+10h] [bp-14h]
  int *v54; // [sp+14h] [bp-10h]
  unsigned __int8 *v55; // [sp+1Ch] [bp-8h]

  v2 = dword_1201F4;
  v3 = (int *)(dword_1201F4 + 1320 * a1);
  v52 = 1320 * a1;
  list_remove_node_d510(dword_1201F8, v3);
  if ( *((int **)off_1201FC + 8) == v3 )
    *((_DWORD *)off_1201FC + 8) = 0;
  v4 = *(unsigned __int8 *)(v2 + 1320 * a1 + 106);
  if ( v4 == 2 )
  {
    v13 = (int *)off_12023C;
    v54 = v3;
    v14 = dword_12021C + 696 * (a1 + 32);
    v15 = 0;
    v16 = dword_12021C + 8 * (87 * (a1 + 32) + 78);
    v55 = (unsigned __int8 *)off_120200;
    --*((_BYTE *)off_120200 + 18);
    v51 = v16;
    *(_BYTE *)(v14 + 37) = 0;
    v17 = v2 + 8 * (165 * (__int16)a1 + 159);
    v18 = 0;
    do
    {
      if ( *(_DWORD *)(v14 + 584) )
        sub_118D80((unsigned __int8)v18, v51 - 40, 0);
      if ( *(_DWORD *)(v14 + 624) )
        sub_118D80((unsigned __int8)v18, v51, 0);
      if ( v3[318] || v3[308] )
      {
        v19 = v17 - 40;
        v53 = list_count_d594(v17, v15);
        v21 = list_count_d594(v17 - 40, v20);
        sub_12ECB0(dword_120220, v53, v21);
      }
      else
      {
        v19 = v17 - 40;
      }
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(_DWORD *)off_120224 = 1;
      }
      ++*v13;
      sub_118D80((unsigned __int8)v18, v17, 0);
      sub_118D80((unsigned __int8)v18, v19, 0);
      if ( *v13 )
      {
        v22 = *v13 - 1;
        v23 = *(_DWORD *)off_120224;
        *v13 = v22;
        if ( !v22 )
        {
          if ( v23 )
            __enable_irq();
        }
      }
      ++v18;
      v14 += 8;
      v17 += 8;
      v3 += 2;
      v51 += 8;
    }
    while ( v18 != 5 );
    v3 = v54;
    v5 = v55;
    if ( *(_DWORD *)(v2 + 1320 * a1 + 1312) )
    {
      v24 = list_count_d594(v52 + 1312 + v2, v15);
      sub_12ECB0(dword_120228, v24, v25);
    }
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(_DWORD *)off_120224 = 1;
    }
    ++*v13;
    v26 = sub_118D80(5, v52 + 1312 + v2, 0);
    if ( *v13 )
    {
      v27 = *v13 - 1;
      v28 = *(_DWORD *)off_120224;
      *v13 = v27;
      if ( !v27 )
      {
        if ( v28 )
          __enable_irq();
      }
    }
    v6 = v55[18];
    if ( !v55[18] )
    {
      sub_121B14(v26);
LABEL_6:
      v6 = (unsigned __int8)v5[18];
      v7 = (unsigned __int8)v5[17] + v6;
      if ( v7 != 1 )
        goto LABEL_7;
      goto LABEL_40;
    }
    if ( v55[17] + v6 != 1 )
      goto LABEL_9;
  }
  else
  {
    if ( v4 != 4 )
    {
      v5 = off_120200;
      if ( !*(_BYTE *)(v2 + 1320 * a1 + 106) )
      {
        v6 = *((unsigned __int8 *)off_120200 + 18);
        v39 = (unsigned __int8)(*((_BYTE *)off_120200 + 17) - 1);
        *((_BYTE *)off_120200 + 17) = v39;
        v7 = v39 + v6;
        if ( v7 != 1 )
          goto LABEL_7;
        goto LABEL_40;
      }
      goto LABEL_6;
    }
    if ( sub_101888() )
      mmio_bit_toggle_0189c(0);
    v5 = off_120344;
    v40 = *((unsigned __int8 *)off_120344 + 16);
    v41 = v2 + 1320 * v40;
    v42 = *(_DWORD *)(v41 + 72);
    *(_DWORD *)(v41 + 4) &= ~0x80u;
    if ( v42 )
      v40 = sub_1287E0();
    v6 = (unsigned __int8)v5[18];
    if ( v5[18] )
    {
      sub_121A94(v40, v42);
      v6 = (unsigned __int8)v5[18];
    }
    else
    {
      v43 = (int *)off_12034C;
      v44 = dword_120350;
      v45 = **(__int16 **)off_120348;
      *(_DWORD *)off_12034C = dword_120350;
      if ( v45 < 0 )
      {
        v6 = *(_DWORD *)off_120358 & 0xF;
        if ( v6 )
        {
          sub_12F6C4(dword_120360, dword_12035C, 472);
          v44 = *v43;
          v6 = (unsigned __int8)v5[18];
        }
      }
      *(_DWORD *)off_120354 = v44 | v43[1];
    }
    v7 = (unsigned __int8)v5[17] + v6;
    v5[16] = -1;
    if ( v7 != 1 )
      goto LABEL_7;
  }
LABEL_40:
  v29 = (__int16 **)off_120240;
  v30 = off_12022C;
  v31 = **(__int16 **)off_120240;
  v32 = *((_DWORD *)v5 + 2);
  v33 = *((_DWORD *)off_12022C + 1) & 0xFFFFFFEF;
  *((_DWORD *)off_12022C + 1) = v33;
  if ( v31 >= 0 || !(*(_DWORD *)off_120358 << 28) )
  {
    v34 = off_120230;
    *(_DWORD *)off_120238 = v33 | *v30;
    v35 = off_120234;
    v36 = *(unsigned __int16 *)(v32 + 68);
    *v34 = *(_DWORD *)(v32 + 64);
    *v35 = v36;
    if ( v6 )
      goto LABEL_9;
LABEL_42:
    v37 = **v29;
    v38 = v30[1] & 0xFFFFFEFF;
    v30[1] = v38;
    if ( v37 >= 0 || !(*(_DWORD *)off_120358 << 28) )
    {
      *(_DWORD *)off_120238 = v38 | *v30;
      goto LABEL_9;
    }
    sub_12F6C4(dword_120360, dword_12035C, 472);
    v7 = (unsigned __int8)v5[17] + (unsigned __int8)v5[18];
    *(_DWORD *)off_120354 = *v30 | v30[1];
    goto LABEL_7;
  }
  sub_12F6C4(dword_120360, dword_12035C, 472);
  v46 = (unsigned __int8)v5[18];
  v47 = (unsigned __int8)v5[17];
  v48 = off_120368;
  *(_DWORD *)off_120354 = *v30 | v30[1];
  v7 = v47 + v46;
  v49 = off_120364;
  v50 = *(unsigned __int16 *)(v32 + 68);
  *v48 = *(_DWORD *)(v32 + 64);
  *v49 = v50;
  if ( v7 == 1 )
  {
    if ( v46 )
      goto LABEL_9;
    goto LABEL_42;
  }
LABEL_7:
  if ( !v7 )
    *(_DWORD *)off_120204 = 0;
LABEL_9:
  timestamp_remove_058(v52 + 24 + v2);
  timestamp_remove_058(v52 + 48 + v2);
  v8 = v2 + 1320 * a1;
  if ( *(_BYTE *)(v8 + 1224) )
  {
    sub_12A270(*(unsigned __int8 *)(v8 + 1225), 1);
    --v5[19];
  }
  phy_tbl_lookup_by_idx(*(unsigned __int8 *)(v2 + 1320 * a1 + 107));
  if ( *((int **)off_120208 + 4) == v3 )
    *((_DWORD *)off_120208 + 4) = 0;
  *(_DWORD *)off_12020C = 0;
  if ( (unsigned __int8)v5[18] + (unsigned __int8)v5[17] <= 1 )
    sub_11FA28();
  memset_thunk(v3, 0, 0x528u);
  v9 = v2 + 1320 * a1;
  v10 = dword_120210;
  *(_BYTE *)(v9 + 106) = 5;
  v11 = dword_120218;
  *(_DWORD *)(v9 + 56) = v3;
  *(_DWORD *)(v9 + 52) = v10;
  *(_BYTE *)(v9 + 109) = 127;
  *(_BYTE *)(v9 + 110) = 127;
  feature_guard_sdio(256, v11);
  return list_push_tail(off_120200);
}

