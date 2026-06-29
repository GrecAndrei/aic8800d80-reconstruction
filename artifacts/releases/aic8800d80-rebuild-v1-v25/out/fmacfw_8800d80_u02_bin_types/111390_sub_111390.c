// sub_111390 @ 0x111390, size 1160 bytes
// Doc: rf_bus_reset2_n_39e [rf]: Performs RF bus register size/count check
// rf_bus_reset2_n_39e [rf]: Performs RF bus register size/count check
int sub_111390()
{
  int v0; // r4
  int v1; // r2
  int v2; // r2
  int v3; // r1
  uint32_t *v4; // r2
  int v5; // r1
  int v6; // r2
  uint8_t *v7; // r6
  unsigned int v8; // r1
  unsigned int v9; // r2
  int v10; // r5
  unsigned int v11; // r2
  char *v12; // r3
  uint32_t *v13; // r7
  uint32_t *v14; // r0
  int v15; // r3
  char *v16; // r1
  uint32_t *v17; // r0
  uint8_t *v18; // r5
  unsigned int v19; // r1
  unsigned int v20; // r2
  int result; // r0
  uint8_t *v22; // r5
  int v23; // r2
  uint8_t *v24; // r0
  unsigned int v25; // r1
  unsigned int v26; // r2
  uint32_t *v27; // r3
  uint8_t *v28; // r5
  int v29; // r2
  uint32_t *v30; // r0
  unsigned int v31; // r2
  uint32_t *v32; // r3
  unsigned int v33; // r3
  uint32_t *v34; // r7
  unsigned int v35; // r3
  char *v36; // r2
  uint32_t *v37; // r5
  int v38; // r6
  int v39; // r7
  unsigned int v40; // r3
  char *v41; // r2
  int v42; // r0
  int v43; // r5
  int v44; // r0
  int v45; // r1
  int v46; // r0
  int v47; // r1
  uint32_t *v48; // r2
  int v49; // r5
  int v50; // r1
  int v51; // r1
  uint8_t *v52; // r6
  int v53; // r1
  int v54; // r1
  uint32_t *v55; // r2
  int v56; // r1

  v0 = *(uint32_t *)rf_bus_mark_618;
  if ( **(__int16 **)rf_bus_mark_n_270 < 0 && !v0 )
  {
    sub_12F49C(dword_111828, dword_111824, 39);
    goto rf_bus_write2_n_3a4;
  }
  v1 = v0 << 18;
  if ( (v0 & 0x2000) != 0 )
  {
    v48 = rf_bus_mark_n_50;
    v49 = *(uint32_t *)rf_bus_write_n_158;
    *(uint32_t *)rf_bus_write_n_158 = *(uint32_t *)rf_bus_write_n_158;
    v50 = dword_11184C;
    *v48 &= ~0x20u;
    feature_guard_check(2, v50);
    if ( (v49 & 4) != 0 )
    {
      v53 = rf_bus_mark_870;
      *(uint8_t *)rf_bus_reset2_n_1a8_1854 = 1;
      feature_guard_check(2, v53);
    }
    if ( (v49 & 1) != 0 )
    {
      v52 = rf_bus_reset2_n_1a8_1854;
      *(uint32_t *)rf_bus_reset2_n_1ac = 16;
      if ( *v52 )
      {
        feature_guard_check(2, ipc_mailbox_init);
        *v52 = 0;
      }
      if ( *(uint8_t *)rf_bus_mark_n_2c )
      {
        v55 = sdio_buffer_prepare_n_406;
        *((uint8_t *)rf_bus_mark_n_2c + 1) = 1;
        v56 = rf_bus_write_n_2e7_187c;
        *v55 |= 1u;
        feature_guard_check(2, v56);
      }
      v1 = 0;
      *(uint8_t *)rf_bus_write_n_308 = 0;
    }
    if ( (v49 & 2) != 0 )
    {
      v54 = dword_111874;
      *(uint8_t *)rf_bus_write_n_308 = 1;
      feature_guard_check(2, v54);
    }
    if ( (v49 & 8) != 0 )
      msg_parse(rf_fault_dump_n16e, v51, v1);
  }
  if ( (v0 & 1) != 0 )
  {
    msg_parse(rf_bus_mark_n_268, v0 << 31, v1);
    *(uint32_t *)rf_bus_reset2_n_3dc = 1;
  }
  v2 = v0 << 26;
  if ( (v0 & 0x20) != 0 )
  {
    reg_field_extract_121130C(*(uint32_t *)rf_bus_reset2_n_3d8);
    v2 = 32;
    *(uint32_t *)rf_bus_reset2_n_3dc = 32;
  }
  if ( (v0 & 0x4000) != 0 )
  {
    v3 = *(uint32_t *)rf_bus_reset2_n_3d4;
    v4 = rf_bus_reset2_n_3cc;
    *(uint32_t *)rf_bus_reset2_n_3d4 = *(uint32_t *)rf_bus_reset2_n_3d4;
    msg_parse(rf_bus_reset2_n_23c, v3, *v4);
  }
  if ( (v0 & 0x8000) == 0 )
    goto rf_bus_write2_n_3a4;
  v42 = rf_bus_mark_n54;
  v43 = *(uint32_t *)rf_bus_reset2_n_1d0;
  *(uint32_t *)rf_bus_reset2_n_1d0 = *(uint32_t *)rf_bus_reset2_n_1d0;
  msg_parse(v42, v43, v2);
  if ( (v43 & 4) != 0 )
  {
    v2 = (int)rf_bus_mark_n_50;
    *(uint32_t *)rf_bus_mark_n_50 &= ~1u;
  }
  if ( (v43 & 8) == 0 )
  {
rf_bus_write2_n_3a4:
    v5 = v0 << 9;
    if ( (v0 & 0x400000) == 0 )
      goto rf_fault_dump_n_378;
rf_bus_reset2_1740:
    v44 = rf_bus_reset2_n_1c0;
    v45 = *(uint32_t *)rf_bus_reset2_n_1c4;
    *(uint32_t *)rf_bus_reset2_n_1c4 = *(uint32_t *)rf_bus_reset2_n_1c4;
    msg_parse(v44, v45, v2);
    v6 = v0 << 8;
    if ( (v0 & 0x800000) == 0 )
      goto rf_bus_mark_n_48d_13f6;
    goto LABEL_61;
  }
  v2 = (int)rf_bus_mark_n_50;
  v5 = v0 << 9;
  *(uint32_t *)rf_bus_mark_n_50 &= ~4u;
  if ( (v0 & 0x400000) != 0 )
    goto rf_bus_reset2_1740;
rf_fault_dump_n_378:
  v6 = v0 << 8;
  if ( (v0 & 0x800000) == 0 )
    goto rf_bus_mark_n_48d_13f6;
LABEL_61:
  v46 = rf_bus_write_n_320;
  v47 = *(uint32_t *)rf_bus_mark_n_44;
  *(uint32_t *)rf_bus_mark_n_44 = *(uint32_t *)rf_bus_mark_n_44;
  msg_parse(v46, v47, v6);
rf_bus_mark_n_48d_13f6:
  if ( (v0 & 0x400) != 0 )
  {
    v7 = ipc_doorbell_handler_n_4ac;
    v8 = *((unsigned __int8 *)ipc_doorbell_handler_n_4ac + 1621);
    v9 = *((unsigned __int8 *)ipc_doorbell_handler_n_4ac + 1622);
    if ( v8 >= v9 )
    {
      msg_parse(dword_11186C, v8, v9);
    }
    else
    {
      v10 = *(uint32_t *)rf_bus_reset2_n_3bc;
      v11 = *((unsigned __int8 *)ipc_doorbell_handler_n_4ac + 1620)
          + 1
          - 81
          * ((unsigned int)(((unsigned int)dword_11163C
                           * (unsigned uint64_t)((unsigned int)*((unsigned __int8 *)ipc_doorbell_handler_n_4ac + 1620) + 1)) >> 32) >> 6);
      v12 = (char *)ipc_doorbell_handler_n_4ac + 20 * v11;
      v13 = rf_bus_reset2_648;
      *((uint32_t *)v12 + 1) = *(uint32_t *)off_111644;
      v7[1621] = v8 + 1;
      v14 = off_11164C;
      *((uint32_t *)v12 + 2) = *v13;
      v12[12] = v10;
      v7[1620] = v11;
      v12[13] = BYTE1(v10) & 7;
      *v14 = 16;
      do
        v15 = *v14 & 0x20;
      while ( v15 );
      v16 = &v7[20 * v11];
      if ( (v16[13] & 4) == 0 )
        v15 = *(uint32_t *)(*((uint32_t *)v16 + 2) + 4);
      v17 = off_111654;
      *(uint32_t *)rf_bus_reset2_n_3ac = v15;
      *v17 = 16;
      list_push_tail(rf_bus_mark_n_22c_1658);
      irq_nesting_or_d104(256);
    }
    v6 = 1024;
    *(uint32_t *)rf_bus_reset2_n_3dc = 1024;
  }
  if ( (v0 & 0x200) != 0 )
  {
    msg_parse(rf_bus_mark_n_1f, v5, v6);
    *(uint32_t *)rf_bus_write_multi = 512;
  }
  if ( (v0 & 0x100) != 0 )
  {
    v18 = ipc_doorbell_handler_n_4ac;
    v19 = *((unsigned __int8 *)ipc_doorbell_handler_n_4ac + 2433);
    v20 = *((unsigned __int8 *)ipc_doorbell_handler_n_4ac + 2434);
    if ( v19 < v20 )
    {
      v38 = *(uint32_t *)rf_bus_mark_n_64;
      v39 = *(uint32_t *)off_111818;
      v40 = *((unsigned __int8 *)ipc_doorbell_handler_n_4ac + 2432)
          + 1
          - 40
          * ((unsigned int)(((unsigned int)rf_bus_reset2_n_1e0
                           * (unsigned uint64_t)((unsigned int)*((unsigned __int8 *)ipc_doorbell_handler_n_4ac + 2432) + 1)) >> 32) >> 5);
      v41 = (char *)ipc_doorbell_handler_n_4ac + 20 * v40;
      *((uint8_t *)ipc_doorbell_handler_n_4ac + 2432) = v40;
      v41[1645] = BYTE1(v38) & 7;
      *((uint32_t *)v41 + 409) = v39;
      *((uint32_t *)v41 + 410) = v39;
      v41[1644] = v38;
      v18[2433] = v19 + 1;
      list_push_tail(v18 + 2436);
      irq_nesting_or_d104(0x400000);
    }
    else
    {
      msg_parse(rf_bus_reset2_n_3a0, v19, v20);
    }
    *(uint32_t *)rf_bus_reset2_n_3dc = 256;
  }
  result = v0 << 19;
  if ( (v0 & 0x1000) != 0 )
  {
    if ( *(uint8_t *)rf_bus_mark_n_224 )
    {
      v22 = off_111664;
      v23 = *((unsigned __int8 *)off_111664 + 369);
      *(uint8_t *)rf_bus_mark_n_224 = 0;
      if ( v23 )
        rf_mem_read_n47e(1);
      else
        sub_10DD14(1);
      if ( v22[374] == 1 )
        timestamp_remove(rf_bus_mark_n_21c);
    }
    v24 = rf_bus_write_n_4f7;
    v25 = *((unsigned __int8 *)rf_bus_write_n_4f7 + 3074);
    v26 = *((unsigned __int8 *)rf_bus_write_n_4f7 + 3073);
    if ( v25 < v26 )
    {
      v35 = *((unsigned __int8 *)rf_bus_write_n_4f7 + 3072)
          + 1
          - 192
          * ((unsigned int)(((unsigned int)rf_bus_mark_n_1ff
                           * (unsigned uint64_t)((unsigned int)*((unsigned __int8 *)rf_bus_write_n_4f7 + 3072) + 1)) >> 32) >> 7);
      v36 = (char *)rf_bus_write_n_4f7 + 16 * v35;
      *((uint32_t *)v36 + 1) = *(uint32_t *)ipc_doorbell_handler_n376;
      v37 = rf_bus_write_n_4cc;
      v24[3072] = v35;
      *((uint16_t *)v36 + 4) = *v37;
      v24[3074] = v25 + 1;
      list_push_tail(v24 + 3080);
      result = irq_nesting_or_d104(128);
    }
    else
    {
      result = msg_parse(rf_bus_write_n_4f4, v25, v26);
    }
    v27 = off_111674;
    *(uint32_t *)rf_bus_reset2_n_3dc = 4096;
    if ( !*v27 )
      *(uint8_t *)rf_bus_write_n_4ec_1678 &= ~1u;
  }
  if ( (v0 & 0x800) != 0 )
  {
    if ( *(uint8_t *)rf_bus_mark_n_224 )
    {
      v28 = off_111664;
      v29 = *((unsigned __int8 *)off_111664 + 369);
      *(uint8_t *)rf_bus_mark_n_224 = 0;
      if ( v29 )
        rf_mem_read_n47e(1);
      else
        sub_10DD14(1);
      if ( v28[374] == 1 )
        timestamp_remove(rf_bus_mark_n_21c);
    }
    v30 = rf_bus_write_n_4f7;
    v31 = *((unsigned __int8 *)rf_bus_write_n_4f7 + 6162);
    if ( *((unsigned __int8 *)rf_bus_write_n_4f7 + 6161) > v31 )
    {
      v33 = *((unsigned __int8 *)rf_bus_write_n_4f7 + 6160)
          + 1
          - 192
          * ((unsigned int)(((unsigned int)rf_bus_mark_n_1ff
                           * (unsigned uint64_t)((unsigned int)*((unsigned __int8 *)rf_bus_write_n_4f7 + 6160) + 1)) >> 32) >> 7);
      v34 = rf_bus_reset2_n_374_1688;
      *((uint8_t *)rf_bus_write_n_4f7 + 6160) = v33;
      v30[4 * v33 + 773] = *v34;
      LOWORD(v30[4 * v33 + 774]) = *(uint32_t *)off_11168C;
      *((uint8_t *)v30 + 6162) = v31 + 1;
      list_push_tail(rf_bus_mark_n_1f3);
      result = irq_nesting_or_d104(64);
    }
    else
    {
      result = msg_parse(rf_bus_write_n_4e7, v31, v31);
    }
    v32 = rf_bus_mark_n_203;
    *(uint32_t *)rf_bus_reset2_n_3dc = 2048;
    if ( !*v32 )
      *(uint8_t *)rf_bus_write_n_4ec_1678 &= ~2u;
  }
  if ( (v0 & 4) != 0 )
    *(uint32_t *)rf_bus_reset2_n_3dc = 4;
  if ( (v0 & 8) != 0 )
    *(uint32_t *)rf_bus_reset2_n_3dc = 8;
  return result;
}

