// hci_vendor_cmd_send @ 0x131a40
int hci_vendor_cmd_send(int a1, volatile uint8_t *a2, int16_t a3, int16_t a4) {
  int v5; // r0
  int v6; // r2
  int v7; // r6
  int v8; // r5
  int16_t v9; // r0
  int16_t v10; // r1
  int16_t v11; // r2
  uint16_t v12; // r4
  int v13; // r0
  unsigned int v14; // r2
  int v15; // r1
  int v16; // r2
  volatile int *v17; // r4
  int v18; // r3
  int v19; // r0
  int v20; // r3
  int v21; // r3
  int v22; // r2

  v5 = bt_buf_alloc(5135, a4, a3, 0xC8u);
  v6 = *a2;
  v7 = v5;
  v8 = *(volatile uint32_t *)(dword_131B30 + 696 * v6 + 340);
  *(volatile uint8_t *)v5 = v6;
  if ( v8 )
  {
    v9 = *(volatile uint16_t *)(v8 + 184);
    v10 = *(volatile uint16_t *)(v8 + 144);
    v11 = *(volatile uint16_t *)(v8 + 146);
    *(volatile uint32_t *)(v7 + 8) = *(volatile uint32_t *)(v8 + 148);
    *(volatile uint16_t *)(v7 + 2) = v9;
    *(volatile uint16_t *)(v7 + 4) = v10;
    *(volatile uint16_t *)(v7 + 6) = v11;
    *(volatile uint8_t *)(v7 + 12) = *(volatile uint8_t *)(v8 + 168);
    *(volatile uint8_t *)(v7 + 13) = *(volatile uint16_t *)(v8 + 152);
    memcpy((void *)(uintptr_t)(v7 + 14), (void *)(uintptr_t)(v8 + 136), 8);
    memcpy((void *)(uintptr_t)(v7 + 22), (void *)(uintptr_t)(v8 + 4), 120);
    if ( *(volatile uint16_t *)(v8 + 184) )
    {
      v12 = 0;
      do
      {
        v13 = query_tx_power_table(v8, (uint8_t)v12, 0);
        v14 = *(volatile uint16_t *)(v8 + 184);
        *(volatile uint32_t *)(v7 + 4 * v12++ + 156) = v13;
      }
      while ( v14 > v12 );
    }
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(volatile uint32_t *)off_131B34 = 1;
    }
    v15 = *(volatile uint32_t *)(v8 + 128);
    v16 = *(volatile uint32_t *)(v8 + 132);
    v17 = (volatile int *)off_131B38;
    *(volatile uint32_t *)(v7 + 142) = *(volatile uint32_t *)(v8 + 124);
    v18 = *v17;
    *(volatile uint32_t *)(v7 + 146) = v15;
    *(volatile uint32_t *)(v7 + 150) = v16;
    *v17 = v18 + 1;
    v19 = query_tx_power_table(v8, 10, 0);
    v20 = *v17;
    *(volatile uint32_t *)(v7 + 196) = v19;
    if ( v20 )
    {
      v21 = v20 - 1;
      v22 = *(volatile uint32_t *)off_131B34;
      *v17 = v21;
      if ( !v21 )
      {
        if ( v22 )
          __enable_irq();
      }
    }
    hci_evt_send(v7);
    return 0;
  }
  else
  {
    *(volatile uint16_t *)(v5 + 2) = 0;
    hci_evt_send(v5);
    return 0;
  }
}



// llm_adv_start @ 0x131b3c
int llm_adv_start(int a1, int a2, int a3) {
  int v4; // r1

  if ( **(volatile int16_t **)off_131B84 < 0 && hci_cmd_send_short(a3) != 1 )
    mmio_irq_clear((int)aKeStateGetDest_1, (int)aMmSetPsModeCfm, 822);
  v4 = *((volatile uint16_t *)off_131B88 + 4);
  if ( v4 != 255 )
    hci_evt_alloc_send(5146, v4, a3);
  hci_cmd_send(a3, 0);
  return 0;
}


// llm_scan_start @ 0x131b94
int llm_scan_start(int a1, int a2, int a3) {
  int v4; // r1

  if ( **(volatile int16_t **)off_131BDC < 0 && hci_cmd_send_short(a3) != 1 )
    mmio_irq_clear((int)aKeStateGetDest_1, (int)aMmSetIdleCfmHa, 670);
  v4 = *((volatile uint16_t *)off_131BE0 + 4);
  if ( v4 != 255 )
    hci_evt_alloc_send(5144, v4, a3);
  hci_cmd_send(a3, 0);
  return 0;
}


// llm_set_adv_data @ 0x131bec
int llm_set_adv_data(int a1, volatile uint8_t *a2, int a3, int a4) {
  volatile uint32_t *v5; // r5
  int v6; // r7
  int v8; // r0
  int v9; // r0
  int v10; // r3
  volatile uint8_t *v12; // r0
  int v13; // r3
  char v14; // r3
  int a3a; // [sp+4h] [bp-8h]

  v5 = (void *)(uintptr_t)(off_131C78);
  v6 = *((volatile uint32_t *)off_131C78 + 1);
  v8 = 1 << a2[1];
  if ( *a2 )
    v9 = v8 | v6;
  else
    v9 = v6 & ~v8;
  v10 = *((volatile uint8_t *)off_131C78 + 375);
  *((volatile uint32_t *)off_131C78 + 1) = v9;
  if ( !v10 )
    goto LABEL_7;
  a3a = a3;
  if ( hci_cmd_send_short(5u) == 1 )
    return 2;
  a3 = a3a;
  if ( (uint8_t)v6 )
  {
    if ( *a2 )
    {
LABEL_7:
      hci_evt_alloc_send(5146, a4, a3);
      return 0;
    }
  }
  else if ( !*a2 )
  {
    goto LABEL_7;
  }
  v12 = (volatile uint8_t *)bt_buf_alloc(49, 0, a3a, 1);
  v13 = v5[1];
  *((volatile uint16_t *)v5 + 4) = a4;
  if ( v13 )
    v14 = 0;
  else
    v14 = *((volatile uint8_t *)v5 + 376);
  *v12 = v14;
  hci_evt_send((int)v12);
  hci_cmd_send(a3a, 1);
  return 0;
}


// rf_test_tx_cmd @ 0x131c7c
int rf_test_tx_cmd(int a1, volatile int *a2, int a3, int a4) {
  volatile uint8_t *v5; // r4
  int v6; // r0
  int v7; // r9
  int v8; // r2
  int v9; // r5
  volatile int *v10; // r8
  volatile int *v11; // r2
  char v12; // r1
  int16_t v13; // r0
  int v14; // r10
  int v15; // r8
  int v16; // r12
  int v17; // r1
  int v18; // r2
  char v19; // r5
  int v20; // r7
  volatile uint32_t *v21; // lr
  int v22; // r5
  int v23; // r3
  char v24; // r1
  int v25; // r6
  unsigned int v26; // r0
  int v27; // r3
  char v28; // r1
  char v29; // r12
  volatile unsigned int v30; // r7
  int v31; // r1
  int v32; // r11
  volatile uint8_t *v33; // r7
  unsigned int v34; // r3
  int v36; // r3
  int v37; // r1
  int v38; // r2
  int v39; // r3
  int v40; // r1
  int v41; // r2
  int v42; // r3
  int v43; // r1
  int v44; // r2
  int v45; // r3
  int v46; // r1
  int v47; // r2
  int v48; // r3
  int v49; // r1
  int v50; // r2
  int v51; // r3
  int v52; // r0
  int v53; // r1
  int v54; // lr
  int v55; // r1
  int v56; // r2
  volatile uint32_t *v57; // r3
  BOOL v58; // r0
  int v59; // r0
  int v60; // r0
  int v61; // r0
  volatile uint8_t *v62; // r0
  volatile int *v63; // r8
  volatile uint8_t *v64; // r10
  volatile uint32_t *v65; // r4
  volatile uint32_t *v66; // r6
  int v67; // r11
  int v68; // r7
  int v69; // r1
  volatile uint32_t *v70; // r3
  int v71; // r2
  struct __attribute__((packed)) { volatile uint32_t *result; // [sp+10h] [bp-44h]
  int v73; // [sp+14h] [bp-40h]
  union { int v74; // [sp+18h] [bp-3Ch]
  int v75; // [sp+18h] [bp-3Ch]
  int v76; // [sp+18h] [bp-3Ch]
  volatile uint8_t *v77; }; // [sp+18h] [bp-3Ch]
  char v78; // [sp+1Ch] [bp-38h]
  char _pad4[7]; char a7; // [sp+24h] [bp-30h] BYREF
  char a3a; // [sp+25h] [bp-2Fh] BYREF
  uint16_t a4a; // [sp+26h] [bp-2Eh] BYREF
  int a5; // [sp+28h] [bp-2Ch] BYREF
  int v83; // [sp+2Ch] [bp-28h] BYREF
  uint8_t a1a[4]; // [sp+30h] [bp-24h] BYREF
  int v85; // [sp+34h] [bp-20h]
  int v86; // [sp+38h] [bp-1Ch]
  int v87; // [sp+3Ch] [bp-18h]
  int16_t v88; // [sp+40h] [bp-14h]
  int v89; // [sp+42h] [bp-12h]
  uint16_t v90; // [sp+46h] [bp-Eh]
  char v91; // [sp+48h] [bp-Ch]
  char v92; // [sp+49h] [bp-Bh]
  char _pad18[3]; char v93; // [sp+4Dh] [bp-7h]
  char v94; // [sp+4Eh] [bp-6h]
  } _frame;
  _frame.a5 = 0;
  _frame.v83 = 0;
  v5 = (volatile uint8_t *)bt_buf_alloc(5128, a4, a3, 3);
  _frame.a4a = 0;
  _frame.a7 = 0;
  v6 = rf_clear_flag();
  v7 = *((volatile uint8_t *)a2 + 129);
  v8 = a2[30];
  _frame.result = (volatile uint32_t *)v6;
  v9 = v8 & 2;
  _frame.v73 = 1320 * v7;
  if ( (v8 & 2) == 0 )
  {
    v12 = *((volatile uint8_t *)a2 + 129);
    goto LABEL_8;
  }
  v9 = v8 & 4;
  if ( (v8 & 4) != 0 )
  {
    v10 = a2 + 13;
    v36 = *(volatile uint8_t *)(dword_132050 + 1320 * v7 + 106);
    if ( v36 == 2 )
    {
      v59 = _frame.v73 + 100;
    }
    else
    {
      if ( v36 == 3 )
      {
        v61 = extract_chan_bits((int)a2);
        v8 = a2[30];
        v9 = v61;
        goto LABEL_4;
      }
      if ( *(volatile uint8_t *)(dword_132050 + 1320 * v7 + 106) )
      {
        v9 = 0;
        goto LABEL_4;
      }
      v59 = _frame.v73 + 368;
    }
    v60 = pack_chan_bits(v59 + dword_132050, *((volatile uint16_t *)a2 + 62));
    v8 = a2[30];
    v9 = v60;
    goto LABEL_4;
  }
  v10 = nullptr;
LABEL_4:
  v11 = (volatile int *)(v8 & 0x20);
  if ( v11 )
    v11 = a2 + 16;
  llm_parse_adv_pdu((int)(a2 + 5), (void *)(v10), (int)v11, &_frame.a4a, &_frame.a5, &_frame.v83, &_frame.a7);
  v12 = *((volatile uint8_t *)a2 + 129);
LABEL_8:
  _frame.v89 = *a2;
  v13 = *((volatile uint16_t *)a2 + 2);
  _frame.v92 = v12;
  _frame.v87 = v9;
  *(volatile uint32_t *)_frame.a1a = 0;
  _frame.v93 = 0;
  _frame.v94 = 0;
  _frame.v90 = v13;
  _frame.v88 = _frame.a4a;
  _frame.v86 = _frame.a5;
  _frame.v85 = _frame.v83;
  _frame.v91 = _frame.a7;
  v14 = buffer_alloc((int)(uintptr_t)(_frame.a1a), v5, &_frame.a3a);
  v5[1] = v14;
  if ( v14 )
    goto LABEL_24;
  v15 = *v5;
  v16 = a2[30];
  v17 = *(volatile int *)((volatile char *)a2 + 10);
  v18 = *(volatile int *)((volatile char *)a2 + 14);
  v19 = *((volatile uint8_t *)a2 + 18);
  v20 = dword_13204C + 696 * v15;
  *(volatile uint32_t *)(v20 + 192) = *(volatile int *)((volatile char *)a2 + 6);
  *(volatile uint32_t *)(v20 + 196) = v17;
  *(volatile uint32_t *)(v20 + 200) = v18;
  *(volatile uint8_t *)(v20 + 204) = v19;
  if ( (v16 & 0x40) != 0 )
    *(volatile uint32_t *)(v20 + 4) |= 0x40u;
  if ( (v16 & 1) != 0
    && (v21 = (volatile uint32_t *)(dword_13204C + 696 * v15), _frame.v74 = v21[1], v21[1] = _frame.v74 | 1, (v16 & 2) != 0)
    && (_frame.v78 = *((volatile uint8_t *)off_132060 + 374), v14 = _frame.v78 & 1, (_frame.v78 & 1) != 0) )
  {
    v37 = a2[6];
    v38 = a2[7];
    v39 = a2[8];
    v21[52] = a2[5];
    v21[53] = v37;
    v21[54] = v38;
    v21[55] = v39;
    v40 = a2[10];
    v41 = a2[11];
    v42 = a2[12];
    v21[56] = a2[9];
    v21[57] = v40;
    v21[58] = v41;
    v21[59] = v42;
    v21[1] = _frame.v74 | 3;
    if ( (v16 & 0x20) != 0 && (_frame.v78 & 4) != 0 )
    {
      v43 = a2[17];
      v44 = a2[18];
      v45 = a2[19];
      v21[63] = a2[16];
      v21[64] = v43;
      v21[65] = v44;
      v21[66] = v45;
      v46 = a2[21];
      v47 = a2[22];
      v48 = a2[23];
      v21[67] = a2[20];
      v21[68] = v46;
      v21[69] = v47;
      v21[70] = v48;
      v49 = a2[25];
      v50 = a2[26];
      v51 = a2[27];
      v21[71] = a2[24];
      v21[72] = v49;
      v21[73] = v50;
      v21[74] = v51;
      v52 = a2[28];
      v53 = a2[29];
      v21[1] = _frame.v74 | 0x23;
      v21[75] = v52;
      v21[76] = v53;
      if ( (_frame.v78 & 8) != 0 )
      {
        configure_dma(v20);
        v16 = a2[30];
      }
    }
    if ( (v16 & 4) != 0 )
    {
      v54 = *(volatile uint32_t *)(dword_13204C + 696 * v15 + 4);
      if ( (*((volatile uint8_t *)off_132060 + 374) & 2) != 0 || (v54 & 0x20) != 0 )
      {
        v55 = a2[14];
        v56 = a2[15];
        v57 = (volatile uint32_t *)(dword_13204C + 696 * v15);
        v57[60] = a2[13];
        v57[61] = v55;
        v57[62] = v56;
        v57[1] = v54 | 4;
      }
    }
    v22 = dword_132050;
    v58 = llm_get_adv_addr(v20, _frame.v73 + 248 + dword_132050);
    v16 = a2[30];
    v14 = v58;
  }
  else
  {
    v22 = dword_132050;
  }
  if ( (v16 & 8) != 0 )
    *(volatile uint32_t *)(dword_13204C + 696 * v15 + 4) |= 8u;
  v23 = dword_13204C + 696 * v15;
  *(volatile uint8_t *)(v23 + 310) = *((volatile uint8_t *)a2 + 126);
  v24 = *((volatile uint8_t *)a2 + 127);
  *(volatile uint16_t *)(v23 + 32) = *((volatile uint16_t *)a2 + 62);
  *(volatile uint8_t *)(v23 + 311) = v24;
  _frame.v75 = v23;
  llm_adv_pdu_build_cmd(v20);
  if ( (a2[30] & 0x10) != 0 && *((volatile char *)a2 + 128) >= 0 )
  {
    ((int (*)())rf_config_chan_table)(*(volatile uint8_t *)(_frame.v75 + 35), a2[32] & 3, *((volatile uint8_t *)a2 + 128) >> 4);
    if ( !v14 )
      goto LABEL_19;
  }
  else if ( !v14 )
  {
    goto LABEL_19;
  }
  ((int (*)())rf_config_chan_table)(*(volatile uint8_t *)(dword_13204C + 696 * v15 + 35), 0xFFu, 0);
LABEL_19:
  v25 = v22 + 1320 * v7;
  v26 = *(volatile uint16_t *)(v25 + 236);
  v27 = dword_13204C + 696 * v15;
  v28 = *(volatile uint32_t *)(v25 + 1208) & 1;
  v29 = *(volatile uint8_t *)(v27 + 350);
  *(volatile uint32_t *)(v27 + 680) = v20;
  *(volatile uint8_t *)(v27 + 52) = 2 - v28;
  *(volatile uint32_t *)(v27 + 676) = off_132054;
  *(volatile uint16_t *)(v27 + 56) = __rev16(v26);
  *(volatile uint8_t *)(v27 + 350) = v29 | 0x10;
  *(volatile uint8_t *)(v27 + 688) = 1;
  v30 = (*(volatile uint32_t *)0x40501010u);
  _frame.v76 = v27;
  ke_event_lock((volatile uint32_t *)(696 * v15 + 672 + dword_13204C), dword_13205C + v30);
  v5[2] = (uint8_t)_frame.result;
  if ( _frame.result )
  {
    v31 = *(volatile uint8_t *)(v25 + 234);
    *(volatile uint8_t *)(_frame.v76 + 36) = (uint8_t)_frame.result;
    if ( !v31 )
    {
      v32 = (uint8_t)(*(volatile uint8_t *)(v25 + 107) + 32);
      v33 = (volatile uint8_t *)(dword_13204C + 696 * v32);
      if ( v33[36] != 1 )
      {
        v34 = v33[35];
        v33[36] = 1;
        if ( v34 <= 0x1F )
        {
          v62 = (volatile uint8_t *)bt_buf_alloc(73, 13, 0, 2);
          *v62 = v32;
          v62[1] = 1;
          hci_evt_send((int)v62);
          if ( v33[36] || v33[35] > 0x1Fu )
          {
            v31 = (v31 & ~0xFFu) | ((uint8_t)(*(volatile uint8_t *)(v25 + 234)) & 0xFFu);
          }
          else
          {
            v63 = (volatile int *)off_132150;
            _frame.v77 = v5;
            v64 = v33;
            v65 = (volatile uint32_t *)(dword_132140 - 664 + 8 * (87 * (int16_t)v32 + 78));
            v66 = (volatile uint32_t *)(v22 + 8 * (165 * v33[34] + 159));
            v67 = 696 * v32 + dword_132140;
            v68 = v22 + 1320 * v33[34];
            do
            {
              if ( *((volatile uint32_t *)v64 + 146) )
              {
                if ( (__get_CPSR() & 1) == 0 )
                {
                  __disable_irq();
                  *(volatile uint32_t *)off_132144 = 1;
                }
                ++*v63;
                ke_event_schedule_1(aCatTobe);
                list_merge(v65 - 10, v66 - 10);
                *(volatile uint64_t *)(v68 + 1232) = *((volatile uint64_t *)v64 + 73);
                zero_struct(v65 - 10);
                v69 = *v63 - 1;
                if ( *v63 )
                {
                  v70 = (void *)(uintptr_t)(off_132144);
                  *v63 = v69;
                  if ( !v69 )
                  {
                    if ( *v70 )
                      __enable_irq();
                  }
                }
              }
              v71 = *((volatile uint32_t *)v64 + 156);
              v68 += 8;
              v64 += 8;
              if ( v71 )
              {
                ke_event_schedule_1(aCatPs);
                list_merge(v66, v65);
                zero_struct(v65);
              }
              v65 += 2;
              v66 += 2;
            }
            while ( (volatile uint32_t *)v67 != v65 );
            v5 = _frame.v77;
            set_system_flag_1(512);
            v31 = (v31 & ~0xFFu) | ((uint8_t)(*(volatile uint8_t *)(v22 + 1320 * v7 + 234)) & 0xFFu);
          }
        }
      }
    }
    *(volatile uint8_t *)(v22 + 1320 * v7 + 234) = v31 + 1;
    bt_conn_get_entry((void *)(uintptr_t)(_frame.v73 + v22));
  }
LABEL_24:
  hci_evt_send((int)v5);
  return 0;
}


// llm_ctrl_config @ 0x132154
int llm_ctrl_config(int a1, int a2, int a3, int a4) {
  volatile uint8_t *v4; // r4
  int v8; // r1
  int v9; // r2
  int v10; // r3
  int v11; // r1
  int v12; // r2
  int v13; // r3
  volatile uint32_t *v14; // r3
  int v15; // r1
  int v16; // r2
  int v17; // r3
  int16_t v18; // r1
  int v19; // r2
  char v20; // r2
  volatile uint32_t *v22; // r6
  int v23; // r1
  int v24; // r2
  int v25; // r3
  int v26; // r1
  int v27; // r2
  int v28; // r3
  int v29; // r1
  int v30; // r2
  int v31; // r3
  int v32; // r1
  volatile uint8_t *v33; // r0
  int v34; // r0
  int v35; // r3
  unsigned int v36; // r2
  int v37; // cc
  int v38; // r3

  v4 = (void *)(uintptr_t)(off_13229C);
  *((volatile uint8_t *)off_13229C + 374) = 0;
  if ( *(volatile uint8_t *)(a2 + 103) )
  {
    v4[374] = 1;
    v8 = *(volatile uint32_t *)(a2 + 4);
    v9 = *(volatile uint32_t *)(a2 + 8);
    v10 = *(volatile uint32_t *)(a2 + 12);
    *((volatile uint32_t *)v4 + 3) = *(volatile uint32_t *)a2;
    *((volatile uint32_t *)v4 + 4) = v8;
    *((volatile uint32_t *)v4 + 5) = v9;
    *((volatile uint32_t *)v4 + 6) = v10;
    v11 = *(volatile uint32_t *)(a2 + 20);
    v12 = *(volatile uint32_t *)(a2 + 24);
    v13 = *(volatile uint32_t *)(a2 + 28);
    *((volatile uint32_t *)v4 + 7) = *(volatile uint32_t *)(a2 + 16);
    *((volatile uint32_t *)v4 + 8) = v11;
    *((volatile uint32_t *)v4 + 9) = v12;
    *((volatile uint32_t *)v4 + 10) = v13;
  }
  if ( *(volatile uint8_t *)(a2 + 104) )
  {
    v14 = (volatile uint32_t *)dword_1322A0;
    v4[374] |= 2u;
    v15 = *(volatile uint32_t *)(a2 + 36);
    v16 = *(volatile uint32_t *)(a2 + 40);
    *v14 = *(volatile uint32_t *)(a2 + 32);
    v14[1] = v15;
    v14[2] = v16;
  }
  if ( get_hw_info_bit19() )
  {
    *(volatile uint8_t *)(a2 + 105) = 0;
    *(volatile uint8_t *)(a2 + 106) = 0;
  }
  else
  {
    if ( *(volatile uint8_t *)(a2 + 105) )
    {
      v22 = (volatile uint32_t *)dword_1322A4;
      v4[374] |= 4u;
      v23 = *(volatile uint32_t *)(a2 + 48);
      v24 = *(volatile uint32_t *)(a2 + 52);
      v25 = *(volatile uint32_t *)(a2 + 56);
      *v22 = *(volatile uint32_t *)(a2 + 44);
      v22[1] = v23;
      v22[2] = v24;
      v22[3] = v25;
      v22 += 4;
      v26 = *(volatile uint32_t *)(a2 + 64);
      v27 = *(volatile uint32_t *)(a2 + 68);
      v28 = *(volatile uint32_t *)(a2 + 72);
      *v22 = *(volatile uint32_t *)(a2 + 60);
      v22[1] = v26;
      v22[2] = v27;
      v22[3] = v28;
      v22 += 4;
      v29 = *(volatile uint32_t *)(a2 + 80);
      v30 = *(volatile uint32_t *)(a2 + 84);
      v31 = *(volatile uint32_t *)(a2 + 88);
      *v22 = *(volatile uint32_t *)(a2 + 76);
      v22[1] = v29;
      v22[2] = v30;
      v22[3] = v31;
      v22 += 4;
      v32 = *(volatile uint32_t *)(a2 + 96);
      *v22 = *(volatile uint32_t *)(a2 + 92);
      v22[1] = v32;
    }
    if ( *(volatile uint8_t *)(a2 + 106) )
      v4[374] |= 8u;
  }
  v4[373] = *(volatile uint8_t *)(a2 + 102);
  hci_evt_alloc_send(5121, a4, a3);
  if ( (v4[374] & 1) != 0 )
  {
    v34 = sys_mode_get();
    v35 = (uint8_t)v4[374] << 29;
    v4[372] = (v34 + 1) >> 1;
    if ( v35 < 0 )
    {
      v36 = (uint8_t)v4[373];
      v37 = v36 > 2;
      if ( v36 > 2 )
        v36 = (uint8_t)v4[73];
      v38 = (uint8_t)v4[68] >> 2;
      if ( v37 )
        v38 &= v36 >> 6;
      v4[116] = v38 & 1;
    }
  }
  else
  {
    v4[372] = 0;
  }
  v17 = *(volatile uint8_t *)(a2 + 107);
  v18 = *(volatile uint16_t *)(a2 + 100);
  v4[375] = v17;
  v19 = *(volatile uint8_t *)(a2 + 109);
  *((volatile uint16_t *)v4 + 22) = v18;
  if ( v19 )
    v20 = 2;
  else
    v20 = 1;
  v4[376] = v20;
  if ( v17 )
  {
    *((volatile uint16_t *)v4 + 4) = 255;
    v33 = (volatile uint8_t *)bt_buf_alloc(49, 0, 5, 1);
    *v33 = v4[376];
    hci_evt_send((int)v33);
    hci_cmd_send(5u, 1);
  }
  return 0;
}


// llc_conn_env_get @ 0x1322a8
int llc_conn_env_get(int a1, volatile uint8_t *a2) {
  int v2; // r6
  int v4; // r0

  v2 = dword_1322E8;
  ke_event_set_lock(696 * *a2 + 672 + dword_1322E8);
  v4 = *a2;
  if ( *(volatile uint8_t *)(v2 + 696 * v4 + 37) )
    sdio_cfg_write(v4);
  else
    hci_evt_alloc_send(5130, 13, 5);
  return 0;
}



// llm_event_wait @ 0x1322ec
int llm_event_wait(int a1, volatile char *a2, int a3, int a4) {
  volatile uint16_t *v7; // r4
  char v8; // r3
  int v9; // r1
  volatile uint8_t *v10; // r0
  int v11; // r3

  if ( hci_cmd_send_short(5u) == 1 )
    return 2;
  v7 = (void *)(uintptr_t)(off_13234C);
  v8 = *a2;
  v9 = *((volatile uint32_t *)off_13234C + 1);
  if ( *a2 )
    v8 = 1;
  *((volatile uint8_t *)off_13234C + 375) = v8;
  if ( !v9 )
  {
    v10 = (volatile uint8_t *)bt_buf_alloc(49, 0, 5, 1);
    v11 = *((volatile uint8_t *)v7 + 375);
    v7[4] = 255;
    if ( v11 )
      v11 = (v11 & ~0xFFu) | ((uint8_t)(*((volatile uint8_t *)v7 + 376)) & 0xFFu);
    *v10 = v11;
    hci_evt_send((int)v10);
    hci_cmd_send(5u, 1);
  }
  hci_evt_alloc_send(5140, a4, a3);
  return 0;
}


// llm_event_wait_next @ 0x132350
int llm_event_wait_next(int a1, volatile uint8_t *a2, int a3, int a4) {
  volatile uint16_t *v7; // r7
  volatile int *v9; // r0
  char v10; // r1
  int v11; // r3

  if ( hci_cmd_send_short(5u) == 1 )
    return 2;
  v7 = (void *)(uintptr_t)(off_1323E0);
  if ( *(volatile uint32_t *)off_1323E0 )
  {
    if ( *a2 )
    {
      *(volatile uint32_t *)off_1323E0 |= 1 << a2[1];
      hci_evt_alloc_send(5144, a4, a3);
      return 0;
    }
  }
  else if ( !*a2 )
  {
    hci_evt_alloc_send(5144, a4, a3);
    return 0;
  }
  v9 = (volatile int *)bt_buf_alloc(34, 0, a3, 1);
  v10 = a2[1];
  if ( *a2 )
    v11 = (1 << v10) | *(volatile uint32_t *)v7;
  else
    v11 = *(volatile uint32_t *)v7 & ~(1 << v10);
  *(volatile uint32_t *)v7 = v11;
  v7[4] = a4;
  *v9 = v11 == 0;
  hci_evt_send((int)v9);
  hci_cmd_send(a3, 1);
  return 0;
}


// llm_env_reset @ 0x1323e4
/* luna: Reset the LLM/link-layer environment by clearing its global state block and reinitializing HCI, DMA RX/TX, tx-power state, control flags, and RF queue */
int llm_env_reset() {
  memset((volatile int *)dword_132414, 0, 0x17Cu);
  hci_cmd_send(5u, 0);
  dma_rx_reset();
  txpwr_reset_state();
  llm_get_ctrl_flags();
  rf_init_queues();
  return dma_tx_reset_1();
}


// llm_adv_state_get @ 0x132418
volatile char * llm_adv_state_get(int a1, int a2) {
  volatile char *result; // r0
  volatile char *v3; // r3
  volatile char *v4; // r4
  int v5; // r2

  if ( a1 )
  {
    result = (volatile char *)*((volatile uint8_t *)off_13245C + 371);
    v3 = (volatile char *)off_13245C + 202;
  }
  else
  {
    result = (volatile char *)*((volatile uint8_t *)off_13245C + 370);
    v3 = (volatile char *)off_13245C + 118;
  }
  if ( result )
  {
    v4 = &v3[6 * (uint32_t)result];
    while ( 1 )
    {
      v5 = *(volatile uint16_t *)v3;
      result = v3;
      v3 += 6;
      if ( v5 == a2 )
        break;
      if ( v3 == v4 )
        return 0;
    }
  }
  return result;
}



// rf_channel_to_freq @ 0x132460
volatile char * rf_channel_to_freq(volatile char *result, int a2) {
  int v2; // r1
  volatile char *v3; // r3
  volatile char *v4; // r4
  int v5; // r2

  if ( result )
  {
    if ( result != (volatile char *)1 || (uint8_t)(a2 - 1) > 0xB0u )
      return 0;
    result = (volatile char *)*((volatile uint8_t *)off_1324D0 + 371);
    v2 = 5 * a2 + 5000;
    v3 = (volatile char *)off_1324D0 + 202;
  }
  else
  {
    if ( (unsigned int)(a2 - 1) > 0xD )
      return result;
    if ( a2 == 14 )
      v2 = 2484;
    else
      v2 = 5 * a2 + 2407;
    result = (volatile char *)*((volatile uint8_t *)off_1324D0 + 370);
    v3 = (volatile char *)off_1324D0 + 118;
  }
  if ( result )
  {
    v4 = &v3[6 * (uint32_t)result];
    while ( 1 )
    {
      v5 = *(volatile uint16_t *)v3;
      result = v3;
      v3 += 6;
      if ( v5 == v2 )
        break;
      if ( v3 == v4 )
        return 0;
    }
  }
  return result;
}



