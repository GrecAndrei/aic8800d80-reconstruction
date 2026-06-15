// v23 annotated: rf_msg_process @ 0x110d00
// Original: 110d00_rf_msg_process.c
// Primary struct: group_20 (cluster 20)
//
// rf_msg_process @ 0x110d00, size 1068 bytes
// Doc: rf_bus_mark_n_3b2 [rf]: Marks RF bus registers with channel/state flags
// rf_bus_mark_n_3b2 [rf]: Marks RF bus registers with channel/state flags
int rf_msg_process()
{
  int v0; // r4
  int v1; // r1
  int v2; // r1
  _BYTE *v3; // r6
  unsigned int v4; // r1
  int v5; // r5
  unsigned int v6; // r2
  char *v7; // r3
  _DWORD *v8; // r7
  _DWORD *v9; // r0
  int v10; // r3
  char *v11; // r1
  _DWORD *v12; // r0
  _BYTE *v13; // r5
  unsigned int v14; // r1
  int result; // r0
  _BYTE *v16; // r0
  unsigned int v17; // r1
  _DWORD *v18; // r3
  _DWORD *v19; // r0
  unsigned int v20; // r2
  _DWORD *v21; // r3
  unsigned int v22; // r3
  _DWORD *v23; // r7
  unsigned int v24; // r3
  char *v25; // r2
  _DWORD *v26; // r5
  int v27; // r6
  int v28; // r7
  unsigned int v29; // r3
  char *v30; // r2
  int v31; // r0
  int v32; // r5
  int v33; // r0
  int v34; // r1
  int v35; // r0
  int v36; // r1
  unsigned int *v37; // r2
  int v38; // r5
  int v39; // r1
  unsigned int v40; // r3
  int v41; // r1
  _BYTE *v42; // r6
  void *v43; // r3
  int v44; // r1
  void *v45; // r3
  int v46; // r1
  int *v47; // r2
  int v48; // r1
  int v49; // r3

  v0 = *(_DWORD *)rf_bus_write_n_4d8;
  if ( **(__int16 **)rf_bus_reset2_n_373 < 0 && !v0 )
  {
    sub_1219F4(dword_111130, dword_11112C, 39);
    goto rf_bus_mark_n_431;
  }
  if ( (v0 & 0x2000) != 0 )
  {
    v37 = (unsigned int *)off_11113C;
    v38 = *(_DWORD *)log_free_pool_dispatch2_n480_1150;
    *(_DWORD *)log_free_pool_dispatch2_n480_1150 = *(_DWORD *)log_free_pool_dispatch2_n480_1150;
    v39 = rf_bus_write2_n_3d0;
    v40 = *v37 & 0xFFFFFFDF;
    *v37 = v40;
    sub_11F74C(2, v39, v38, v40);
    if ( (v38 & 4) != 0 )
    {
      v43 = rf_bus_mark_n_30;
      v44 = rf_bus_write_n_2f4;
      *(_BYTE *)rf_bus_mark_n_30 = 1;
      sub_11F74C(2, v44, 1, v43);
    }
    if ( (v38 & 1) != 0 )
    {
      v42 = rf_bus_mark_n_30;
      *(_DWORD *)rf_bus_write2_n_3cc = 16;
      if ( *v42 )
      {
        sub_11F74C(2, rf_bus_reset_n1a7, 16, (unsigned __int8)*v42);
        *v42 = 0;
      }
      if ( *(_BYTE *)rf_bus_write_n_30c )
      {
        v47 = (int *)rf_bus_mark_n_b;
        *((_BYTE *)rf_bus_write_n_30c + 1) = 1;
        v48 = rf_bus_write2_n_3a0;
        v49 = *v47 | 1;
        *v47 = v49;
        sub_11F74C(2, v48, v47, v49);
      }
      *(_BYTE *)off_111164 = 0;
    }
    if ( (v38 & 2) != 0 )
    {
      v45 = off_111164;
      v46 = dword_11117C;
      *(_BYTE *)off_111164 = 1;
      sub_11F74C(2, v46, 1, v45);
    }
    if ( (v38 & 8) != 0 )
      msg_parse(rf_bus_reset2_n_19c, v41);
  }
  if ( (v0 & 1) != 0 )
  {
    msg_parse(rf_bus_write_n_4d3, v0 << 31);
    *(_DWORD *)rf_bus_reset2_n_367 = 1;
  }
  if ( (v0 & 0x20) != 0 )
  {
    sub_110C7C(*(_DWORD *)rf_bus_write_n_4cc);
    *(_DWORD *)rf_bus_reset2_n_367 = 32;
  }
  if ( (v0 & 0x4000) != 0 )
  {
    v1 = *(_DWORD *)off_110FA4;
    *(_DWORD *)off_110FA4 = *(_DWORD *)off_110FA4;
    msg_parse(rf_bus_write_n_4bc, v1);
  }
  if ( (v0 & 0x8000) == 0 )
    goto rf_bus_mark_n_431;
  v31 = dword_111138;
  v32 = *(_DWORD *)sdio_buffer_prepare_n140;
  *(_DWORD *)sdio_buffer_prepare_n140 = *(_DWORD *)sdio_buffer_prepare_n140;
  msg_parse(v31, v32);
  if ( (v32 & 4) != 0 )
    *(_DWORD *)off_11113C &= ~1u;
  if ( (v32 & 8) == 0 )
  {
rf_bus_mark_n_431:
    v2 = v0 << 9;
    if ( (v0 & 0x400000) == 0 )
      goto LABEL_11;
log_free_dispatch_1060:
    v33 = dword_111144;
    v34 = *(_DWORD *)rf_bus_write2_1140;
    *(_DWORD *)rf_bus_write2_1140 = *(_DWORD *)rf_bus_write2_1140;
    msg_parse(v33, v34);
    if ( (v0 & 0x800000) == 0 )
      goto rf_bus_mark_n_425;
    goto rf_bus_reset2_n_292;
  }
  v2 = v0 << 9;
  *(_DWORD *)off_11113C &= ~4u;
  if ( (v0 & 0x400000) != 0 )
    goto log_free_dispatch_1060;
LABEL_11:
  if ( (v0 & 0x800000) == 0 )
    goto rf_bus_mark_n_425;
rf_bus_reset2_n_292:
  v35 = dword_11114C;
  v36 = *(_DWORD *)rf_bus_reset2_n_1bc;
  *(_DWORD *)rf_bus_reset2_n_1bc = *(_DWORD *)rf_bus_reset2_n_1bc;
  msg_parse(v35, v36);
rf_bus_mark_n_425:
  if ( (v0 & 0x400) != 0 )
  {
    v3 = rf_bus_reset2_n_350;
    v4 = *((unsigned __int8 *)rf_bus_reset2_n_350 + 1621);
    if ( v4 >= *((unsigned __int8 *)rf_bus_reset2_n_350 + 1622) )
    {
      msg_parse(rf_bus_write2_174, v4);
    }
    else
    {
      v5 = *(_DWORD *)rf_bus_reset2_n_348;
      v6 = *((unsigned __int8 *)rf_bus_reset2_n_350 + 1620)
         + 1
         - 81
         * ((unsigned int)(((unsigned int)dword_110FB8
                          * (unsigned __int64)((unsigned int)*((unsigned __int8 *)rf_bus_reset2_n_350 + 1620) + 1)) >> 32) >> 6);
      v7 = (char *)rf_bus_reset2_n_350 + 20 * v6;
      v8 = rf_bus_write_n_4a8;
      *((_DWORD *)v7 + 1) = *(_DWORD *)off_110FC0;
      v3[1621] = v4 + 1;
      v9 = rf_bus_mark_n_1c4;
      *((_DWORD *)v7 + 2) = *v8;
      v7[12] = v5;
      v3[1620] = v6;
      v7[13] = BYTE1(v5) & 7;
      *v9 = 16;
      do
        v10 = *v9 & 0x20;
      while ( v10 );
      v11 = &v3[20 * v6];
      if ( (v11[13] & 4) == 0 )
        v10 = *(_DWORD *)(*((_DWORD *)v11 + 2) + 4);
      v12 = patch_apply_n_ff;
      *(_DWORD *)rf_bus_reset2_n_338 = v10;
      *v12 = 16;
      list_push_tail(dword_110FD4);
      irq_nesting_or(2048);
    }
    *(_DWORD *)rf_bus_reset2_n_367 = 1024;
  }
  if ( (v0 & 0x200) != 0 )
  {
    msg_parse(dword_11116C, v2);
    *(_DWORD *)rf_bus_write_1170 = 512;
  }
  if ( (v0 & 0x100) != 0 )
  {
    v13 = rf_bus_reset2_n_350;
    v14 = *((unsigned __int8 *)rf_bus_reset2_n_350 + 2433);
    if ( v14 < *((unsigned __int8 *)rf_bus_reset2_n_350 + 2434) )
    {
      v27 = *(_DWORD *)rf_bus_write_n_458;
      v28 = *(_DWORD *)off_11100C;
      v29 = *((unsigned __int8 *)rf_bus_reset2_n_350 + 2432)
          + 1
          - 40
          * ((unsigned int)(((unsigned int)rf_bus_reset2_n_2f4
                           * (unsigned __int64)((unsigned int)*((unsigned __int8 *)rf_bus_reset2_n_350 + 2432) + 1)) >> 32) >> 5);
      v30 = (char *)rf_bus_reset2_n_350 + 20 * v29;
      *((_BYTE *)rf_bus_reset2_n_350 + 2432) = v29;
      v30[1645] = BYTE1(v27) & 7;
      *((_DWORD *)v30 + 409) = v28;
      *((_DWORD *)v30 + 410) = v28;
      v30[1644] = v27;
      v13[2433] = v14 + 1;
      list_push_tail(v13 + 2436);
      irq_nesting_or(0x1000000);
    }
    else
    {
      msg_parse(dword_110FD8, v14);
    }
    *(_DWORD *)rf_bus_reset2_n_367 = 256;
  }
  result = v0 << 19;
  if ( (v0 & 0x1000) != 0 )
  {
    v16 = rf_bus_reset2_n_328;
    v17 = *((unsigned __int8 *)rf_bus_reset2_n_328 + 3074);
    if ( v17 < *((unsigned __int8 *)rf_bus_reset2_n_328 + 3073) )
    {
      v24 = *((unsigned __int8 *)rf_bus_reset2_n_328 + 3072)
          + 1
          - 192
          * ((unsigned int)(((unsigned int)patch_apply_with_membar
                           * (unsigned __int64)((unsigned int)*((unsigned __int8 *)rf_bus_reset2_n_328 + 3072) + 1)) >> 32) >> 7);
      v25 = (char *)rf_bus_reset2_n_328 + 16 * v24;
      *((_DWORD *)v25 + 1) = *(_DWORD *)rf_bus_mark_n_188;
      v26 = rf_bus_write_n_463;
      v16[3072] = v24;
      *((_WORD *)v25 + 4) = *v26;
      v16[3074] = v17 + 1;
      list_push_tail(v16 + 3080);
      result = irq_nesting_or(1024);
    }
    else
    {
      result = msg_parse(dword_110FE0, v17);
    }
    v18 = rf_bus_mark_n_1a7;
    *(_DWORD *)rf_bus_reset2_n_367 = 4096;
    if ( !*v18 )
      *(_BYTE *)rf_bus_mark_id_n_1a3 &= ~1u;
  }
  if ( (v0 & 0x800) != 0 )
  {
    v19 = rf_bus_reset2_n_328;
    v20 = *((unsigned __int8 *)rf_bus_reset2_n_328 + 6162);
    if ( *((unsigned __int8 *)rf_bus_reset2_n_328 + 6161) > v20 )
    {
      v22 = *((unsigned __int8 *)rf_bus_reset2_n_328 + 6160)
          + 1
          - 192
          * ((unsigned int)(((unsigned int)patch_apply_with_membar
                           * (unsigned __int64)((unsigned int)*((unsigned __int8 *)rf_bus_reset2_n_328 + 6160) + 1)) >> 32) >> 7);
      v23 = rf_bus_mark_n_193;
      *((_BYTE *)rf_bus_reset2_n_328 + 6160) = v22;
      v19[4 * v22 + 773] = *v23;
      LOWORD(v19[4 * v22 + 774]) = *(_DWORD *)rf_bus_mark_n190;
      *((_BYTE *)v19 + 6162) = v20 + 1;
      list_push_tail(rf_bus_mark_n_18b);
      result = irq_nesting_or(512);
    }
    else
    {
      result = msg_parse(dword_110FEC, v20);
    }
    v21 = rf_bus_write_n_47c;
    *(_DWORD *)rf_bus_reset2_n_367 = 2048;
    if ( !*v21 )
      *(_BYTE *)rf_bus_mark_id_n_1a3 &= ~2u;
  }
  if ( (v0 & 4) != 0 )
    *(_DWORD *)rf_bus_reset2_n_367 = 4;
  if ( (v0 & 8) != 0 )
    *(_DWORD *)rf_bus_reset2_n_367 = 8;
  return result;
}

