// process_tx_packet_1 @ 0x11c5d8
/* luna: Handles a radio TX completion by polling status, updating retry and PHY bookkeeping, and dispatching or freeing the packet buffer. */
int process_tx_packet_1(int a1, int a2) {
  volatile uint8_t *v2; // r5
  int v3; // r11
  volatile uint32_t *v4; // r7
  int v5; // r6
  int v7; // r10
  int v8; // r9
  int16_t v9; // r3
  int16_t v10; // r3
  int v11; // r8
  int v12; // r7
  int result; // r0
  int v14; // r9
  unsigned int v15; // r3
  int v16; // r10
  int v17; // r11
  int v18; // r1
  int64_t v19; // kr00_8
  int v20; // r8
  char v21; // r3
  volatile int *v22; // r3
  volatile int *v23; // r2
  int v24; // r1
  int v25; // t1
  unsigned int v26; // r1
  int v27; // r2
  void *v28; // r1
  int v29; // r2
  unsigned int v30; // r2
  int v31; // r0
  int v32; // r2
  unsigned int v33; // r2
  int v34; // [sp+0h] [bp-Ch]
  volatile int *v35; // [sp+4h] [bp-8h]

  v2 = (volatile uint8_t *)off_11C8C4;
  v3 = *(volatile uint32_t *)(a1 + 68);
  v4 = *(volatile uint32_t **)(a1 + 76);
  v5 = *((volatile uint8_t *)off_11C8C4 + 190);
  v7 = a2;
  if ( (a2 & 0x800000) != 0 )
  {
    rf_irq_status_check();
    v8 = 9;
    while ( 1 )
    {
      v9 = *(volatile uint16_t *)(v3 + 8);
      if ( (v9 & 0x20) != 0 )
        break;
      rf_irq_status_check();
      if ( !--v8 )
      {
        v10 = *(volatile uint16_t *)(v3 + 8);
        if ( (v10 & 0x60) != 0x20 )
        {
          if ( (v10 & 0x20) == 0 )
          {
            v11 = dword_11C8E0;
            v12 = 84 * v5;
            mem_word_load(84 * v5 + 28 + dword_11C8E0);
            dec_retry_count(v3);
            *(volatile uint32_t *)(a1 + 68) = 0;
            goto LABEL_18;
          }
LABEL_7:
          dec_retry_count(v3);
          *(volatile uint32_t *)(a1 + 68) = 0;
          v11 = dword_11C8E0;
          v12 = 84 * v5;
          if ( v2[199] )
            goto LABEL_19;
LABEL_8:
          get_phy_status(v2[190]);
          mem_word_load(v12 + 12 + v11);
          if ( *(volatile uint16_t *)(a1 + 4) )
            return ipc_handler_register((volatile uint32_t *)a1, v7, v5);
          return free_buf_1882c0((volatile uint32_t *)a1);
        }
        v7 &= ~0x800000u;
        v4[18] &= ~0x800000u;
        if ( (v10 & 0x20) == 0 )
          goto LABEL_22;
LABEL_31:
        dec_retry_count(v3);
        v11 = dword_11C8E0;
        *(volatile uint32_t *)(a1 + 68) = 0;
        goto LABEL_12;
      }
    }
    if ( (v9 & 0x60) != 0x20 )
      goto LABEL_7;
    v7 &= ~0x800000u;
    v4[18] &= ~0x800000u;
    goto LABEL_31;
  }
  if ( (*(volatile uint16_t *)(v3 + 8) & 0x20) != 0 )
  {
    v11 = dword_11C8E0;
    dec_retry_count(*(volatile uint32_t *)(a1 + 68));
    *(volatile uint32_t *)(a1 + 68) = 0;
  }
  else
  {
LABEL_22:
    v11 = dword_11C8E0;
    mem_word_load(84 * (int16_t)v5 + 28 + dword_11C8E0);
    dec_retry_count(v3);
    *(volatile uint32_t *)(a1 + 68) = 0;
  }
LABEL_12:
  v14 = BYTE1(v7);
  if ( v2[199] )
  {
    v15 = (HIBYTE(*(volatile uint32_t *)off_11C8C8) & 7) + 1;
    if ( v15 >= v2[165] )
      v15 = v2[165];
    *(volatile uint32_t *)off_11C8C8 = (v15 << 24) & 0x7000000 | *(volatile uint32_t *)off_11C8C8 & 0xF8FFFFFF;
  }
  if ( BYTE1(v7) <= 4u )
  {
    v16 = *(volatile uint32_t *)(a1 + 72);
    if ( v14 )
    {
      v17 = v16 + 44;
    }
    else
    {
      if ( *(volatile uint16_t *)(a1 + 4) )
      {
        v22 = *(volatile int **)(a1 + 44);
        v17 = v16 + 44;
        v23 = v22;
        v24 = v16 + 40;
        do
        {
          v25 = *v23++;
          *(volatile uint32_t *)(v24 + 4) = v25;
          v24 += 4;
        }
        while ( v22 + 16 != v23 );
        if ( (*(volatile uint16_t *)(a1 + 30) & 0x2000) != 0 )
        {
          v34 = *(volatile uint32_t *)(dword_11C8D0 + 696 * *(volatile uint8_t *)(a1 + 29) + 340);
          if ( **(volatile int16_t **)off_11C8CC < 0 && !*(volatile uint32_t *)(dword_11C8D0 + 696 * *(volatile uint8_t *)(a1 + 29) + 340) )
          {
            v35 = v22;
            mmio_clear_register((int)aRcSsNull, (int)aRcGetStaStats_1, 475);
            v22 = v35;
          }
          v26 = *(volatile uint32_t *)(v34 + 156);
          *(volatile uint32_t *)(v16 + 68) = v22[5];
          v27 = *(volatile uint32_t *)(v34 + 160);
          *(volatile uint32_t *)(v16 + 84) = v22[9];
          *(volatile uint32_t *)(v16 + 64) = v26;
          *(volatile uint32_t *)(v16 + 80) = v27;
          if ( ((v26 >> 11) & 5) == 5 )
          {
            v30 = v27 & 0xFFFCFFFF;
            if ( (v26 & 0x600) == 0x400 )
              v31 = 0x20000;
            else
              v31 = 0x10000;
            v32 = v30 | v31;
            if ( *(volatile uint8_t *)(v34 + 165) )
              v33 = v32 | 0x40000;
            else
              v33 = v32 & 0xFFFBFFFF;
            *(volatile uint32_t *)(v16 + 80) = v33;
          }
          if ( (v22[15] & 4) == 0 )
            *(volatile uint32_t *)(v16 + 48) &= 0xFFFFFE7F;
        }
      }
      else
      {
        v17 = v16 + 44;
      }
      wait_channel_clear((void *)(uintptr_t)(a1));
    }
    v18 = *(volatile uint32_t *)&v2[28 * v5 + 36];
    v19 = *(volatile uint64_t *)(v16 + 96);
    v4[16] = v19;
    v4[18] = (v14 + 1) << 8;
    v4[11] = HIDWORD(v19);
    v4[12] = v17;
    result = (int)(v4 + 3);
    if ( v18 )
    {
      v4[4] = v18;
    }
    else
    {
      v28 = (void *)(uintptr_t)(off_11C8D4);
      *(volatile uint32_t *)(v11 + 84 * v5) = result;
      v29 = 84 * v5 + v11;
      if ( !*(volatile uint8_t *)(*(volatile uint32_t *)v28 + 1) )
      {
        *(volatile uint32_t *)(v29 + 4) = 0;
        *(volatile uint32_t *)(v29 + 8) = 0;
      }
    }
    v20 = v11 + 84 * v5;
    v21 = *(volatile uint8_t *)(v20 + 80) + 1;
    *(volatile uint32_t *)&v2[28 * v5 + 36] = result;
    *(volatile uint8_t *)(v20 + 80) = v21;
  }
  else
  {
    v4[18] |= 0x10000u;
    v12 = 84 * v5;
LABEL_18:
    if ( !v2[199] )
      goto LABEL_8;
LABEL_19:
    *(volatile uint32_t *)off_11C8C8 = (v2[164] << 24) & 0x7000000 | *(volatile uint32_t *)off_11C8C8 & 0xF8FFFFFF;
    mem_word_load(v12 + 12 + v11);
    if ( !*(volatile uint16_t *)(a1 + 4) )
      return free_buf_1882c0((volatile uint32_t *)a1);
    return ipc_handler_register((volatile uint32_t *)a1, v7, v5);
  }
  return result;
}


// reset_radio_core @ 0x11c8e4
/* luna: Acknowledges a radio event and dispatches transmit-completion handling for the active connection slot while updating radio state. */
void reset_radio_core() {
  volatile uint32_t *v0; // r2
  volatile uint32_t *v1; // r7
  int v2; // r3
  int v3; // r6
  int v4; // r8
  int v5; // r3
  int v6; // r4
  int v7; // r3
  int v8; // r0
  volatile uint32_t *v9; // r1
  unsigned int v10; // r3
  volatile uint32_t *v11; // r4
  volatile int16_t **v12; // r9
  int v13; // r5
  int v14; // r3
  int v15; // r2
  unsigned int v16; // r1
  volatile uint32_t *v17; // r3
  int v18; // r2
  int v19; // r1
  int v20; // nf
  volatile uint32_t *v21; // r1
  int v22; // r2

  v0 = (void *)(uintptr_t)(off_11CA60);
  *(volatile uint32_t *)off_11CA5C = 0x100000;
  while ( (*v0 & 0x300000) != 0 )
    ;
  v1 = (void *)(uintptr_t)(off_11CA64);
  v2 = *((volatile uint32_t *)off_11CA64 + 52);
  *(volatile uint32_t *)off_11CA68 = 0x100000;
  if ( (v2 & 1) != 0 )
  {
    v3 = *((volatile uint8_t *)v1 + 190);
    v4 = dword_11CA8C;
    v5 = dword_11CA8C + 84 * v3;
    if ( *(volatile uint8_t *)(v5 + 26) )
    {
LABEL_5:
      v6 = v4 + 84 * v3;
      *(volatile uint16_t *)(*(volatile uint32_t *)(v6 + 36) + 8) |= 0x10u;
      mem_word_load(v6 + 28);
      unknown_func_12d104(*(volatile uint32_t *)(dword_11CA6C + 4 * v3));
      *(volatile uint8_t *)(v6 + 26) = 0;
      *(volatile uint32_t *)(v6 + 36) = 0;
    }
    else
    {
      v11 = *(volatile uint32_t **)(v5 + 12);
      if ( (v11[9] & 0x200000) != 0 )
      {
        v22 = *(volatile uint32_t *)(*(volatile uint32_t *)(v5 + 20) + 68);
        if ( v22 == v11[17] )
          *(volatile uint32_t *)(v5 + 20) = **(volatile uint32_t **)(v22 + 324);
      }
      v12 = (volatile int16_t **)off_11CA90;
      v13 = v4 + 84 * v3;
      while ( 1 )
      {
        if ( **v12 < 0 && !v11 )
          mmio_clear_register(dword_11CA7C, dword_11CA78, 2094);
        v14 = v11[19];
        v15 = v11[9];
        v16 = *(volatile uint32_t *)(v14 + 72) | 0x80400000;
        *(volatile uint32_t *)(v14 + 72) = v16;
        if ( (v15 & 0x200000) == 0 )
          break;
        get_connection_by_slot((int)v11, v16);
        v11 = *(volatile uint32_t **)(v13 + 12);
        if ( *(volatile uint8_t *)(v13 + 26) )
          goto LABEL_5;
      }
      process_tx_packet_1((int)v11, v16);
    }
    v7 = (int)&v1[7 * v3];
    if ( !*(volatile uint8_t *)(v7 + 46) )
    {
      v8 = *(volatile uint32_t *)(v7 + 36);
      if ( v8 )
        ((int (*)())radio_band_validate)(v8, v3, *(volatile uint8_t *)(v7 + 46), v7);
      v1[7 * v3 + 9] = 0;
    }
    v9 = (void *)(uintptr_t)(off_11CA74);
    *(volatile uint32_t *)off_11CA70 &= ~0x40u;
    *v9 = 64;
    v10 = v1[52] & 0xFFFFFFFE;
    --*(volatile uint8_t *)(v4 + 84 * v3 + 80);
    v1[52] = v10;
    test_flag(v3);
  }
  else if ( (v2 & 2) != 0 )
  {
    v1[52] = v2 & 0xFFFFFFFD;
  }
  else
  {
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(volatile uint32_t *)off_11CA80 = 1;
    }
    v17 = (void *)(uintptr_t)(off_11CA84);
    v18 = *(volatile uint32_t *)off_11CA84;
    v19 = *(volatile uint32_t *)off_11CA84 + 1;
    v20 = (*(volatile uint32_t *)off_11CA88 & 0x1000) != 0;
    *(volatile uint32_t *)off_11CA84 = v19;
    if ( v20 )
      v1[52] |= 4u;
    if ( v19 )
    {
      v21 = (void *)(uintptr_t)(off_11CA80);
      *v17 = v18;
      if ( !v18 )
      {
        if ( *v21 )
          __enable_irq();
      }
    }
  }
}



// handle_rx_event @ 0x11ca94
/* luna: Handles a pending radio receive event for the selected slot, acknowledges its descriptor, and updates associated PHY and radio state. */
void handle_rx_event() {
  volatile uint8_t *v0; // r6
  int v1; // r3
  int v2; // r7
  int v3; // r8
  int v4; // r5
  int v5; // r3
  volatile int16_t **v6; // r10
  int v7; // r12
  int v8; // r3
  int v9; // r2
  int v10; // r1
  int v11; // r3
  int v12; // r4
  int v13; // r4
  int v14; // r3
  int v15; // r3
  uint16_t v16; // r3
  int v17; // r5
  volatile char *v18; // r3
  int v19; // r0
  volatile uint32_t *v20; // r1
  unsigned int v21; // r3
  unsigned int v22; // r2
  int v23; // r0
  int v24; // r3

  v0 = (void *)(uintptr_t)(off_11CC50);
  v1 = *((volatile uint32_t *)off_11CC50 + 52);
  if ( (v1 & 2) != 0 )
  {
    *((volatile uint32_t *)off_11CC50 + 52) = v1 & 0xFFFFFFFD;
    return;
  }
  v2 = *((volatile uint8_t *)off_11CC50 + 190);
  v3 = dword_11CC74;
  v4 = dword_11CC74 + 84 * v2;
  v5 = *(volatile uint8_t *)(v4 + 26);
  if ( *(volatile uint8_t *)(v4 + 26) )
  {
LABEL_12:
    v13 = *(volatile uint32_t *)(v3 + 84 * v2 + 36);
    if ( v5 == 2 )
      v14 = v13 + 16;
    else
      v14 = v13 + 84;
    v15 = *(volatile uint32_t *)(v14 + 60);
    if ( v15 >= 0 )
      return;
    if ( (v15 & 0x800000) != 0 )
    {
      v16 = *(volatile uint16_t *)(v13 + 8);
      if ( (v16 & 0x20) == 0 )
      {
        rf_irq_status_check();
        v17 = 9;
        while ( 1 )
        {
          v16 = *(volatile uint16_t *)(v13 + 8);
          if ( (v16 & 0x20) != 0 )
            break;
          rf_irq_status_check();
          if ( !--v17 )
          {
            v16 = *(volatile uint16_t *)(v13 + 8);
            if ( **(volatile int16_t **)off_11CC58 < 0 && (v16 & 0x20) == 0 )
            {
              bad_func_0x12f408((int)aAggDescStatusA, (int)aTxlHeTbTransmi_0, 2274);
              return;
            }
            break;
          }
        }
      }
      if ( (v16 & 0x40) != 0 )
      {
        if ( v0[199] )
        {
          *(volatile uint32_t *)off_11CC6C = ((uint8_t)v0[164] << 24) & 0x7000000 | *(volatile uint32_t *)off_11CC6C & 0xF8FFFFFF;
        }
        else
        {
          get_phy_status((uint8_t)v0[190]);
          v16 = *(volatile uint16_t *)(v13 + 8);
        }
        goto LABEL_35;
      }
    }
    else
    {
      mem_word_load(v3 + 84 * v2 + 28);
      v16 = *(volatile uint16_t *)(v13 + 8);
    }
    if ( v0[199] )
    {
      v22 = (HIBYTE(*(volatile uint32_t *)off_11CC6C) & 7) + 1;
      if ( v22 >= (uint8_t)v0[165] )
        v22 = (uint8_t)v0[165];
      *(volatile uint32_t *)off_11CC6C = (v22 << 24) & 0x7000000 | *(volatile uint32_t *)off_11CC6C & 0xF8FFFFFF;
    }
LABEL_35:
    v23 = ((volatile uint32_t *)(uintptr_t)off_11CC70)[v2];
    *(volatile uint16_t *)(v13 + 8) = v16 | 0x10;
    unknown_func_12d104(v23);
    v24 = v3 + 84 * v2;
    *(volatile uint8_t *)(v24 + 26) = 0;
    *(volatile uint32_t *)(v24 + 36) = 0;
LABEL_25:
    v18 = &v0[28 * v2];
    if ( !v18[46] )
    {
      v19 = *((volatile uint32_t *)v18 + 9);
      if ( v19 )
        radio_band_validate(v19, v2);
      *(volatile uint32_t *)&v0[28 * v2 + 36] = 0;
    }
    v20 = (void *)(uintptr_t)(off_11CC68);
    *(volatile uint32_t *)off_11CC64 &= ~0x40u;
    *v20 = 64;
    v21 = *((volatile uint32_t *)v0 + 52) & 0xFFFFFFFE;
    --*(volatile uint8_t *)(v3 + 84 * v2 + 80);
    *((volatile uint32_t *)v0 + 52) = v21;
    test_flag(v2);
    return;
  }
  v6 = (volatile int16_t **)off_11CC58;
  while ( 1 )
  {
    v12 = *(volatile uint32_t *)(v4 + 12);
    if ( **v6 < 0 && !v12 )
      mmio_clear_register((int)aTxdescNull, (int)aTxlHeTbTransmi_0, 2199);
    v7 = *(volatile uint32_t *)(v12 + 76);
    v8 = *(volatile uint32_t *)(v7 + 72);
    v9 = v8 | 0x400000;
    v10 = v8 | 0x400000;
    if ( v8 >= 0 )
      break;
    v11 = *(volatile uint32_t *)(v12 + 36);
    *(volatile uint32_t *)(v7 + 72) = v9;
    if ( (v11 & 0x200000) == 0 )
    {
      process_tx_packet_1(v12, v10);
      goto LABEL_25;
    }
    get_connection_by_slot(v12, v10);
    v5 = *(volatile uint8_t *)(v4 + 26);
    if ( *(volatile uint8_t *)(v4 + 26) )
      goto LABEL_12;
  }
}


// radio_event_loop @ 0x11cc78
/* luna: Processes a received packet using the selected link and peer contexts, applying state checks and sending a kernel message when required. */
volatile uint32_t * radio_event_loop(volatile uint32_t *result, int a2, int a3) {
  int v3; // r8
  int16_t v5; // r10
  int v6; // r9
  int v7; // r6
  volatile uint32_t *v8; // r5
  int v9; // r4
  int16_t v10; // r7
  int v11; // r7
  volatile uint8_t *v12; // r5
  uint8_t v13; // r3
  int v14; // r9
  int v15; // r4
  unsigned int v16; // r2
  int v17; // r6
  uint16_t v18; // r2
  int v19; // r5
  int v20; // r9
  int v21; // r4
  unsigned int v22; // r3
  volatile uint8_t *v23; // r0
  int v24; // r0
  unsigned int v25; // r1
  int v26; // r3
  int v27; // r9
  int v28; // r5
  int v29; // r4
  unsigned int v30; // r3
  volatile uint8_t *v31; // r0
  volatile int *v32; // r10
  int v33; // r7
  volatile uint32_t *v34; // r5
  volatile uint32_t *v35; // r4
  volatile uint32_t *v36; // r9
  int v37; // r2
  volatile int *v38; // r3
  int v39; // r3
  int v40; // r3
  volatile uint8_t *v41; // r0
  volatile int *v42; // r10
  volatile uint32_t *v43; // r7
  int v44; // r3
  int v45; // r9
  volatile uint32_t *v46; // r4
  volatile uint32_t *v47; // r5
  int v48; // r1
  volatile uint32_t *v49; // r3
  int v50; // r2
  int v51; // r0
  volatile uint16_t *v52; // r0
  volatile int *v53; // r9
  int v54; // r7
  volatile uint32_t *v55; // r10
  volatile uint32_t *v56; // r11
  int v57; // r6
  int v58; // r2
  volatile int *v59; // r3
  int v60; // r3
  int v61; // r3
  volatile int *v62; // r10
  int v63; // r7
  volatile uint32_t *v64; // r6
  volatile uint32_t *v65; // r5
  volatile uint32_t *v66; // r9
  int v67; // r2
  volatile int *v68; // r3
  int v69; // r3
  int v70; // r3
  int v71; // r0
  int v72; // r2
  int v73; // r0
  volatile uint8_t *v74; // r0
  volatile uint32_t *resulta; // [sp+4h] [bp-10h]
  int v76; // [sp+8h] [bp-Ch]
  int v77; // [sp+8h] [bp-Ch]

  v3 = dword_11CF3C + 1320 * a3;
  if ( *(volatile uint8_t *)(v3 + 106) == 2 )
  {
    v5 = *(volatile uint16_t *)result;
    v6 = 696 * a2;
    v7 = dword_11CF40 + 696 * a2;
    v8 = result;
    resulta = (volatile uint32_t *)*(volatile uint8_t *)(v7 + 36);
    v9 = a2;
    if ( resulta != (volatile uint32_t *)1 )
    {
      if ( (v5 & 0x1404) != 0x1000 )
        return result;
      v16 = *(volatile uint8_t *)(v7 + 35);
      *(volatile uint8_t *)(v7 + 36) = 1;
      if ( v16 <= 0x1F )
      {
        v31 = (volatile uint8_t *)ke_msg_alloc(73, 13, 0, 2);
        *v31 = v9;
        v31[1] = 1;
        ke_msg_send_2((int)v31);
        if ( !*(volatile uint8_t *)(v7 + 36) && *(volatile uint8_t *)(v7 + 35) <= 0x1Fu )
        {
          v32 = (volatile int *)off_11CF58;
          v33 = dword_11CF3C + 1320 * *(volatile uint8_t *)(v7 + 34);
          v34 = (volatile uint32_t *)(dword_11CF3C + 8 * (165 * *(volatile uint8_t *)(v7 + 34) + 159));
          v35 = (volatile uint32_t *)(dword_11CF40 + 8 * (87 * (int16_t)v9 + 78));
          v36 = (volatile uint32_t *)(dword_11CF40 + 664 + v6);
          do
          {
            if ( *(volatile uint32_t *)(v7 + 584) )
            {
              if ( (__get_CPSR() & 1) == 0 )
              {
                __disable_irq();
                *(volatile uint32_t *)off_11CF4C = 1;
              }
              ++*v32;
              event_dispatch(aCatTobe);
              list_next(v35 - 10, v34 - 10);
              *(volatile uint64_t *)(v33 + 1232) = *(volatile uint64_t *)(v7 + 584);
              zero_8_bytes(v35 - 10);
              v37 = *v32 - 1;
              if ( *v32 )
              {
                v38 = (volatile int *)off_11CF4C;
                *v32 = v37;
                v39 = *v38;
                if ( !v37 )
                {
                  if ( v39 )
                    __enable_irq();
                }
              }
            }
            v40 = *(volatile uint32_t *)(v7 + 624);
            v33 += 8;
            v7 += 8;
            if ( v40 )
            {
              event_dispatch(aCatPs);
              list_next(v34, v35);
              zero_8_bytes(v35);
            }
            v35 += 2;
            v34 += 2;
          }
          while ( v35 != v36 );
          unknown_func_12d104(512);
        }
      }
      v17 = dword_11CF3C + 1320 * a3;
      v18 = *(volatile uint8_t *)(v17 + 234);
      if ( !*(volatile uint8_t *)(v17 + 234) )
      {
        v19 = (uint8_t)(a3 + 32);
        v20 = 696 * v19;
        v21 = dword_11CF40 + 696 * v19;
        if ( *(volatile uint8_t *)(v21 + 36) != 1 )
        {
          v22 = *(volatile uint8_t *)(v21 + 35);
          *(volatile uint8_t *)(v21 + 36) = 1;
          if ( v22 <= 0x1F )
          {
            v23 = (volatile uint8_t *)ke_msg_alloc(73, 13, v18, 2);
            *v23 = v19;
            v23[1] = 1;
            ke_msg_send_2((int)v23);
            if ( *(volatile uint8_t *)(v21 + 36) || *(volatile uint8_t *)(v21 + 35) > 0x1Fu )
            {
              v18 = (v18 & ~0xFFu) | ((uint8_t)(*(volatile uint8_t *)(v17 + 234)) & 0xFFu);
            }
            else
            {
              v62 = (volatile int *)off_11D2BC;
              v63 = dword_11D2A4 + 1320 * *(volatile uint8_t *)(v21 + 34);
              v64 = (volatile uint32_t *)(dword_11D2A4 + 8 * (165 * *(volatile uint8_t *)(v21 + 34) + 159));
              v65 = (volatile uint32_t *)(dword_11D2B8 - 664 + 8 * (87 * (uint8_t)(a3 + 32) + 78));
              v66 = (volatile uint32_t *)(dword_11D2B8 + v20);
              do
              {
                if ( *(volatile uint32_t *)(v21 + 584) )
                {
                  if ( (__get_CPSR() & 1) == 0 )
                  {
                    __disable_irq();
                    *(volatile uint32_t *)off_11D2AC = 1;
                  }
                  ++*v62;
                  event_dispatch(aCatTobe);
                  list_next(v65 - 10, v64 - 10);
                  *(volatile uint64_t *)(v63 + 1232) = *(volatile uint64_t *)(v21 + 584);
                  zero_8_bytes(v65 - 10);
                  v67 = *v62 - 1;
                  if ( *v62 )
                  {
                    v68 = (volatile int *)off_11D2AC;
                    *v62 = v67;
                    v69 = *v68;
                    if ( !v67 )
                    {
                      if ( v69 )
                        __enable_irq();
                    }
                  }
                }
                v70 = *(volatile uint32_t *)(v21 + 624);
                v63 += 8;
                v21 += 8;
                if ( v70 )
                {
                  event_dispatch(aCatPs);
                  list_next(v64, v65);
                  zero_8_bytes(v65);
                }
                v65 += 2;
                v64 += 2;
              }
              while ( v65 != v66 );
              unknown_func_12d104(512);
              v18 = (v18 & ~0xFFu) | ((uint8_t)(*(volatile uint8_t *)(dword_11D2A4 + 1320 * a3 + 234)) & 0xFFu);
            }
          }
        }
      }
      v24 = v3;
      *(volatile uint8_t *)(dword_11CF3C + 1320 * a3 + 234) = v18 + 1;
      return (volatile uint32_t *)llc_get_evt_ptr((void *)(uintptr_t)(v24));
    }
    if ( (*(volatile uint16_t *)result & 0x1404) == 0 )
    {
      v25 = *(volatile uint8_t *)(v7 + 35);
      *(volatile uint8_t *)(v7 + 36) = 0;
      if ( v25 <= 0x1F )
      {
        v41 = (volatile uint8_t *)ke_msg_alloc(73, 13, 0, 2);
        *v41 = v9;
        v41[1] = 0;
        ke_msg_send_2((int)v41);
        if ( !*(volatile uint8_t *)(v7 + 36) && *(volatile uint8_t *)(v7 + 35) <= 0x1Fu )
        {
          v42 = (volatile int *)off_11D2BC;
          v76 = v9;
          v43 = (volatile uint32_t *)(dword_11D2A4 + 8 * (165 * *(volatile uint8_t *)(v7 + 34) + 159));
          v44 = dword_11D2A8 + 664 + v6;
          v45 = dword_11D2A4 + 1320 * *(volatile uint8_t *)(v7 + 34);
          v46 = (volatile uint32_t *)(dword_11D2A8 + 8 * (87 * (int16_t)v9 + 78));
          v47 = (volatile uint32_t *)v44;
          do
          {
            if ( *(volatile uint32_t *)(v7 + 584) )
            {
              if ( (__get_CPSR() & 1) == 0 )
              {
                __disable_irq();
                *(volatile uint32_t *)off_11D2AC = 1;
              }
              ++*v42;
              event_dispatch(aCatTobe);
              list_next(v46 - 10, v43 - 10);
              *(volatile uint64_t *)(v45 + 1232) = *(volatile uint64_t *)(v7 + 584);
              zero_8_bytes(v46 - 10);
              v48 = *v42 - 1;
              if ( *v42 )
              {
                v49 = (void *)(uintptr_t)(off_11D2AC);
                *v42 = v48;
                if ( !v48 )
                {
                  if ( *v49 )
                    __enable_irq();
                }
              }
            }
            v50 = *(volatile uint32_t *)(v7 + 624);
            v45 += 8;
            v7 += 8;
            if ( v50 )
            {
              event_dispatch(aCatPs);
              list_next(v43, v46);
              zero_8_bytes(v46);
            }
            v46 += 2;
            v43 += 2;
          }
          while ( v46 != v47 );
          v9 = v76;
          unknown_func_12d104(512);
        }
      }
      bt_get_link_context(v3, v9);
      v26 = dword_11CF3C + 1320 * a3;
      v27 = (uint8_t)(*(volatile uint8_t *)(v26 + 234) - 1);
      *(volatile uint8_t *)(v26 + 234) = v27;
      if ( !v27 )
      {
        v28 = (uint8_t)(a3 + 32);
        v29 = dword_11CF40 + 696 * v28;
        if ( *(volatile uint8_t *)(v29 + 36) )
        {
          v30 = *(volatile uint8_t *)(v29 + 35);
          *(volatile uint8_t *)(v29 + 36) = 0;
          if ( v30 <= 0x1F )
          {
            v52 = (volatile uint16_t *)ke_msg_alloc(73, 13, 0, 2);
            *v52 = (uint8_t)v28;
            ke_msg_send_2((int)v52);
            if ( !*(volatile uint8_t *)(v29 + 36) && *(volatile uint8_t *)(v29 + 35) <= 0x1Fu )
            {
              v53 = (volatile int *)off_11D2BC;
              v77 = (uint8_t)(a3 + 32);
              v54 = dword_11D2A4 + 1320 * *(volatile uint8_t *)(v29 + 34);
              v55 = (volatile uint32_t *)(dword_11D2A4 + 8 * (165 * *(volatile uint8_t *)(v29 + 34) + 159));
              v56 = (volatile uint32_t *)(dword_11D2B8 - 664 + 8 * (87 * v77 + 78));
              v57 = dword_11D2B8 + 696 * v28;
              do
              {
                if ( *(volatile uint32_t *)(v29 + 584) )
                {
                  if ( (__get_CPSR() & 1) == 0 )
                  {
                    __disable_irq();
                    *(volatile uint32_t *)off_11D2AC = 1;
                  }
                  ++*v53;
                  event_dispatch(aCatTobe);
                  list_next(v56 - 10, v55 - 10);
                  *(volatile uint64_t *)(v54 + 1232) = *(volatile uint64_t *)(v29 + 584);
                  zero_8_bytes(v56 - 10);
                  v58 = *v53 - 1;
                  if ( *v53 )
                  {
                    v59 = (volatile int *)off_11D2AC;
                    *v53 = v58;
                    v60 = *v59;
                    if ( !v58 )
                    {
                      if ( v60 )
                        __enable_irq();
                    }
                  }
                }
                v61 = *(volatile uint32_t *)(v29 + 624);
                v54 += 8;
                v29 += 8;
                if ( v61 )
                {
                  event_dispatch(aCatPs);
                  list_next(v55, v56);
                  zero_8_bytes(v56);
                }
                v56 += 2;
                v55 += 2;
              }
              while ( (volatile uint32_t *)v57 != v56 );
              v28 = v77;
              unknown_func_12d104(512);
            }
          }
        }
        bt_get_link_context(v3, v28);
      }
      v24 = v3;
      return (volatile uint32_t *)llc_get_evt_ptr((void *)(uintptr_t)(v24));
    }
    if ( (v5 & 0xFC) == 0xA4 )
    {
      if ( (*(volatile uint8_t *)(v7 + 53) & 2) != 0 )
      {
        *(volatile uint8_t *)(v7 + 54) |= 1u;
        result = (volatile uint32_t *)llc_ccm_encrypt(v3, v7, 1);
        *(volatile uint8_t *)(v7 + 54) &= ~1u;
      }
      else
      {
        result = (volatile uint32_t *)llc_ctrl_pdu_send(v3, dword_11CF40 + 696 * a2, 1);
        if ( !result )
        {
          v51 = ke_msg_alloc(74, 13, 0, 4);
          *(volatile uint8_t *)v51 = v9;
          *(volatile uint16_t *)(v51 + 1) = (uint8_t)resulta;
          result = ke_msg_send_2(v51);
        }
      }
    }
    if ( (v5 & 0x8C) == 0x88 )
    {
      v10 = (v5 & 0x300) == 0x300 ? *((volatile uint16_t *)v8 + 15) : *((volatile uint16_t *)v8 + 12);
      v11 = v10 & 7;
      v12 = (volatile uint8_t *)(dword_11CF40 + 696 * v9);
      if ( (*((volatile uint8_t *)off_11CF48 + *((volatile uint8_t *)off_11CF44 + v11)) & v12[310]) != 0 )
      {
        v13 = v12[53];
        if ( (v13 & 0xC) != 0 )
        {
          if ( (v12[54] & 6) == 0 )
          {
            v14 = v12[311];
            if ( (v12[53] & 8) != 0 )
            {
              v72 = v12[311];
              v12[54] = 2;
              v73 = llc_ccm_encrypt(v3, v7, v72);
              if ( v14 )
              {
                v14 -= v73;
                if ( v14 <= 0 )
                  goto LABEL_16;
              }
              v13 = v12[53];
            }
            if ( (v13 & 4) != 0 )
            {
              *(volatile uint8_t *)(dword_11D318 + 696 * v9 + 54) = 4;
              v74 = (volatile uint8_t *)ke_msg_alloc(74, 13, 0, 4);
              *v74 = v9;
              v74[1] = v14;
              v74[2] = 1;
              return ke_msg_send_2((int)v74);
            }
LABEL_16:
            v15 = dword_11CF40 + 696 * v9;
            result = (volatile uint32_t *)rf_channel_set(*(volatile uint8_t *)(v15 + 35), v11 | 0x10, 0, 0);
            *(volatile uint8_t *)(v15 + 54) = 0;
          }
        }
        else if ( (v12[54] & 6) == 0 )
        {
          v71 = v12[35];
          v12[54] = 2;
          result = (volatile uint32_t *)rf_channel_set(v71, v11 | 0x10, 0, 0);
          v12[54] = 0;
        }
      }
    }
  }
  return result;
}


