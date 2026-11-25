// rx_mpdu_process @ 0x11c498
int rx_mpdu_process(int a1, int a2) {
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

  v2 = (volatile uint8_t *)off_11C784;
  v3 = *(volatile uint32_t *)(a1 + 68);
  v4 = *(volatile uint32_t **)(a1 + 76);
  v5 = *((volatile uint8_t *)off_11C784 + 190);
  v7 = a2;
  if ( (a2 & 0x800000) != 0 )
  {
    check_hw_fw_status();
    v8 = 9;
    while ( 1 )
    {
      v9 = *(volatile uint16_t *)(v3 + 8);
      if ( (v9 & 0x20) != 0 )
        break;
      check_hw_fw_status();
      if ( !--v8 )
      {
        v10 = *(volatile uint16_t *)(v3 + 8);
        if ( (v10 & 0x60) != 0x20 )
        {
          if ( (v10 & 0x20) == 0 )
          {
            v11 = dword_11C7A0;
            v12 = 84 * v5;
            list_pop(84 * v5 + 28 + dword_11C7A0);
            decrement_refcount(v3);
            *(volatile uint32_t *)(a1 + 68) = 0;
            goto LABEL_18;
          }
LABEL_7:
          decrement_refcount(v3);
          *(volatile uint32_t *)(a1 + 68) = 0;
          v11 = dword_11C7A0;
          v12 = 84 * v5;
          if ( v2[199] )
            goto LABEL_19;
LABEL_8:
          get_rf_capability(v2[190]);
          list_pop(v12 + 12 + v11);
          if ( *(volatile uint16_t *)(a1 + 4) )
            return register_handler((volatile uint32_t *)a1, v7, v5);
          return set_string_0x1882c0((volatile uint32_t *)a1);
        }
        v7 &= ~0x800000u;
        v4[18] &= ~0x800000u;
        if ( (v10 & 0x20) == 0 )
          goto LABEL_22;
LABEL_31:
        decrement_refcount(v3);
        v11 = dword_11C7A0;
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
    v11 = dword_11C7A0;
    decrement_refcount(*(volatile uint32_t *)(a1 + 68));
    *(volatile uint32_t *)(a1 + 68) = 0;
  }
  else
  {
LABEL_22:
    v11 = dword_11C7A0;
    list_pop(84 * (int16_t)v5 + 28 + dword_11C7A0);
    decrement_refcount(v3);
    *(volatile uint32_t *)(a1 + 68) = 0;
  }
LABEL_12:
  v14 = BYTE1(v7);
  if ( v2[199] )
  {
    v15 = (HIBYTE(*(volatile uint32_t *)off_11C788) & 7) + 1;
    if ( v15 >= v2[165] )
      v15 = v2[165];
    *(volatile uint32_t *)off_11C788 = (v15 << 24) & 0x7000000 | *(volatile uint32_t *)off_11C788 & 0xF8FFFFFF;
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
          v34 = *(volatile uint32_t *)(dword_11C790 + 696 * *(volatile uint8_t *)(a1 + 29) + 340);
          if ( **(volatile int16_t **)off_11C78C < 0 && !*(volatile uint32_t *)(dword_11C790 + 696 * *(volatile uint8_t *)(a1 + 29) + 340) )
          {
            v35 = v22;
            irq_disable_mmio_write((int)aRcSsNull, (int)aRcGetStaStats_1, 475);
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
      sta_rate_status_check((void *)(uintptr_t)(a1));
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
      v28 = (void *)(uintptr_t)(off_11C794);
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
    *(volatile uint32_t *)off_11C788 = (v2[164] << 24) & 0x7000000 | *(volatile uint32_t *)off_11C788 & 0xF8FFFFFF;
    list_pop(v12 + 12 + v11);
    if ( !*(volatile uint16_t *)(a1 + 4) )
      return set_string_0x1882c0((volatile uint32_t *)a1);
    return register_handler((volatile uint32_t *)a1, v7, v5);
  }
  return result;
}


// dma_clear_interrupt @ 0x11c7a4
/* luna: Acknowledges DMA interrupt sources and, for RX-completion events, processes the indicated channel’s MPDU queue and updates per-channel state. */
void dma_clear_interrupt() {
  volatile uint32_t *dma_status_reg; // r2
  volatile uint32_t *dma_register_base; // r7
  int dma_irq_status; // r3
  int channel_id; // r6
  int channel_state_base; // r8
  int v5; // r3
  int v6; // r4
  int v7; // r3
  int v8; // r0
  volatile uint32_t *v9; // r1
  unsigned int v10; // r3
  volatile uint32_t *rx_mpdu; // r4
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

  dma_status_reg = (void *)(uintptr_t)(off_11C920);
  *(volatile uint32_t *)off_11C91C = 0x100000;
  while ( (*dma_status_reg & 0x300000) != 0 )
    ;
  dma_register_base = (void *)(uintptr_t)(off_11C924);
  dma_irq_status = *((volatile uint32_t *)off_11C924 + 52);
  *(volatile uint32_t *)off_11C928 = 0x100000;
  if ( (dma_irq_status & 1) != 0 )
  {
    channel_id = *((volatile uint8_t *)dma_register_base + 190);
    channel_state_base = dword_11C94C;
    v5 = dword_11C94C + 84 * channel_id;
    if ( *(volatile uint8_t *)(v5 + 26) )
    {
LABEL_5:
      v6 = channel_state_base + 84 * channel_id;
      *(volatile uint16_t *)(*(volatile uint32_t *)(v6 + 36) + 8) |= 0x10u;
      list_pop(v6 + 28);
      irq_disable_global_2(*(volatile uint32_t *)(dword_11C92C + 4 * channel_id));
      *(volatile uint8_t *)(v6 + 26) = 0;
      *(volatile uint32_t *)(v6 + 36) = 0;
    }
    else
    {
      rx_mpdu = *(volatile uint32_t **)(v5 + 12);
      if ( (rx_mpdu[9] & 0x200000) != 0 )
      {
        v22 = *(volatile uint32_t *)(*(volatile uint32_t *)(v5 + 20) + 68);
        if ( v22 == rx_mpdu[17] )
          *(volatile uint32_t *)(v5 + 20) = **(volatile uint32_t **)(v22 + 324);
      }
      v12 = (volatile int16_t **)off_11C950;
      v13 = channel_state_base + 84 * channel_id;
      while ( 1 )
      {
        if ( **v12 < 0 && !rx_mpdu )
          irq_disable_mmio_write(dword_11C93C, dword_11C938, 2094);
        v14 = rx_mpdu[19];
        v15 = rx_mpdu[9];
        v16 = *(volatile uint32_t *)(v14 + 72) | 0x80400000;
        *(volatile uint32_t *)(v14 + 72) = v16;
        if ( (v15 & 0x200000) == 0 )
          break;
        get_conn_by_channel((int)rx_mpdu, v16);
        rx_mpdu = *(volatile uint32_t **)(v13 + 12);
        if ( *(volatile uint8_t *)(v13 + 26) )
          goto LABEL_5;
      }
      rx_mpdu_process((int)rx_mpdu, v16);
    }
    v7 = (int)&dma_register_base[7 * channel_id];
    if ( !*(volatile uint8_t *)(v7 + 46) )
    {
      v8 = *(volatile uint32_t *)(v7 + 36);
      if ( v8 )
        ((int (*)())rf_switch_case)(v8, channel_id, *(volatile uint8_t *)(v7 + 46), v7);
      dma_register_base[7 * channel_id + 9] = 0;
    }
    v9 = (void *)(uintptr_t)(off_11C934);
    *(volatile uint32_t *)off_11C930 &= ~0x40u;
    *v9 = 64;
    v10 = dma_register_base[52] & 0xFFFFFFFE;
    --*(volatile uint8_t *)(channel_state_base + 84 * channel_id + 80);
    dma_register_base[52] = v10;
    invalid_handler(channel_id);
  }
  else if ( (dma_irq_status & 2) != 0 )
  {
    dma_register_base[52] = dma_irq_status & 0xFFFFFFFD;
  }
  else
  {
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(volatile uint32_t *)off_11C940 = 1;
    }
    v17 = (void *)(uintptr_t)(off_11C944);
    v18 = *(volatile uint32_t *)off_11C944;
    v19 = *(volatile uint32_t *)off_11C944 + 1;
    v20 = (*(volatile uint32_t *)off_11C948 & 0x1000) != 0;
    *(volatile uint32_t *)off_11C944 = v19;
    if ( v20 )
      dma_register_base[52] |= 4u;
    if ( v19 )
    {
      v21 = (void *)(uintptr_t)(off_11C940);
      *v17 = v18;
      if ( !v18 )
      {
        if ( *v21 )
          __enable_irq();
      }
    }
  }
}



// is_fw_ready @ 0x11c954
void is_fw_ready() {
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

  v0 = (void *)(uintptr_t)(off_11CB10);
  v1 = *((volatile uint32_t *)off_11CB10 + 52);
  if ( (v1 & 2) != 0 )
  {
    *((volatile uint32_t *)off_11CB10 + 52) = v1 & 0xFFFFFFFD;
    return;
  }
  v2 = *((volatile uint8_t *)off_11CB10 + 190);
  v3 = dword_11CB34;
  v4 = dword_11CB34 + 84 * v2;
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
        check_hw_fw_status();
        v17 = 9;
        while ( 1 )
        {
          v16 = *(volatile uint16_t *)(v13 + 8);
          if ( (v16 & 0x20) != 0 )
            break;
          check_hw_fw_status();
          if ( !--v17 )
          {
            v16 = *(volatile uint16_t *)(v13 + 8);
            if ( **(volatile int16_t **)off_11CB18 < 0 && (v16 & 0x20) == 0 )
            {
              unknown_12f2c8((int)aAggDescStatusA, (int)aTxlHeTbTransmi_0, 2274);
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
          *(volatile uint32_t *)off_11CB2C = ((uint8_t)v0[164] << 24) & 0x7000000 | *(volatile uint32_t *)off_11CB2C & 0xF8FFFFFF;
        }
        else
        {
          get_rf_capability((uint8_t)v0[190]);
          v16 = *(volatile uint16_t *)(v13 + 8);
        }
        goto LABEL_35;
      }
    }
    else
    {
      list_pop(v3 + 84 * v2 + 28);
      v16 = *(volatile uint16_t *)(v13 + 8);
    }
    if ( v0[199] )
    {
      v22 = (HIBYTE(*(volatile uint32_t *)off_11CB2C) & 7) + 1;
      if ( v22 >= (uint8_t)v0[165] )
        v22 = (uint8_t)v0[165];
      *(volatile uint32_t *)off_11CB2C = (v22 << 24) & 0x7000000 | *(volatile uint32_t *)off_11CB2C & 0xF8FFFFFF;
    }
LABEL_35:
    v23 = ((volatile uint32_t *)(uintptr_t)off_11CB30)[v2];
    *(volatile uint16_t *)(v13 + 8) = v16 | 0x10;
    irq_disable_global_2(v23);
    v24 = v3 + 84 * v2;
    *(volatile uint8_t *)(v24 + 26) = 0;
    *(volatile uint32_t *)(v24 + 36) = 0;
LABEL_25:
    v18 = &v0[28 * v2];
    if ( !v18[46] )
    {
      v19 = *((volatile uint32_t *)v18 + 9);
      if ( v19 )
        rf_switch_case(v19, v2);
      *(volatile uint32_t *)&v0[28 * v2 + 36] = 0;
    }
    v20 = (void *)(uintptr_t)(off_11CB28);
    *(volatile uint32_t *)off_11CB24 &= ~0x40u;
    *v20 = 64;
    v21 = *((volatile uint32_t *)v0 + 52) & 0xFFFFFFFE;
    --*(volatile uint8_t *)(v3 + 84 * v2 + 80);
    *((volatile uint32_t *)v0 + 52) = v21;
    invalid_handler(v2);
    return;
  }
  v6 = (volatile int16_t **)off_11CB18;
  while ( 1 )
  {
    v12 = *(volatile uint32_t *)(v4 + 12);
    if ( **v6 < 0 && !v12 )
      irq_disable_mmio_write((int)aTxdescNull, (int)aTxlHeTbTransmi_0, 2199);
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
      rx_mpdu_process(v12, v10);
      goto LABEL_25;
    }
    get_conn_by_channel(v12, v10);
    v5 = *(volatile uint8_t *)(v4 + 26);
    if ( *(volatile uint8_t *)(v4 + 26) )
      goto LABEL_12;
  }
}


// sta_get_state @ 0x11cb38
volatile uint32_t * sta_get_state(volatile uint32_t *result, int a2, int a3) {
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

  v3 = dword_11CDFC + 1320 * a3;
  if ( *(volatile uint8_t *)(v3 + 106) == 2 )
  {
    v5 = *(volatile uint16_t *)result;
    v6 = 696 * a2;
    v7 = dword_11CE00 + 696 * a2;
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
        v31 = (volatile uint8_t *)tx_send_pdu(73, 13, 0, 2);
        *v31 = v9;
        v31[1] = 1;
        rx_process_packet_1((int)v31);
        if ( !*(volatile uint8_t *)(v7 + 36) && *(volatile uint8_t *)(v7 + 35) <= 0x1Fu )
        {
          v32 = (volatile int *)off_11CE18;
          v33 = dword_11CDFC + 1320 * *(volatile uint8_t *)(v7 + 34);
          v34 = (volatile uint32_t *)(dword_11CDFC + 8 * (165 * *(volatile uint8_t *)(v7 + 34) + 159));
          v35 = (volatile uint32_t *)(dword_11CE00 + 8 * (87 * (int16_t)v9 + 78));
          v36 = (volatile uint32_t *)(dword_11CE00 + 664 + v6);
          do
          {
            if ( *(volatile uint32_t *)(v7 + 584) )
            {
              if ( (__get_CPSR() & 1) == 0 )
              {
                __disable_irq();
                *(volatile uint32_t *)off_11CE0C = 1;
              }
              ++*v32;
              alloc_tx_event(aCatTobe);
              get_ptr_value(v35 - 10, v34 - 10);
              *(volatile uint64_t *)(v33 + 1232) = *(volatile uint64_t *)(v7 + 584);
              clear_stats_buf(v35 - 10);
              v37 = *v32 - 1;
              if ( *v32 )
              {
                v38 = (volatile int *)off_11CE0C;
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
              alloc_tx_event(aCatPs);
              get_ptr_value(v34, v35);
              clear_stats_buf(v35);
            }
            v35 += 2;
            v34 += 2;
          }
          while ( v35 != v36 );
          irq_disable_global_2(512);
        }
      }
      v17 = dword_11CDFC + 1320 * a3;
      v18 = *(volatile uint8_t *)(v17 + 234);
      if ( !*(volatile uint8_t *)(v17 + 234) )
      {
        v19 = (uint8_t)(a3 + 32);
        v20 = 696 * v19;
        v21 = dword_11CE00 + 696 * v19;
        if ( *(volatile uint8_t *)(v21 + 36) != 1 )
        {
          v22 = *(volatile uint8_t *)(v21 + 35);
          *(volatile uint8_t *)(v21 + 36) = 1;
          if ( v22 <= 0x1F )
          {
            v23 = (volatile uint8_t *)tx_send_pdu(73, 13, v18, 2);
            *v23 = v19;
            v23[1] = 1;
            rx_process_packet_1((int)v23);
            if ( *(volatile uint8_t *)(v21 + 36) || *(volatile uint8_t *)(v21 + 35) > 0x1Fu )
            {
              v18 = (v18 & ~0xFFu) | ((uint8_t)(*(volatile uint8_t *)(v17 + 234)) & 0xFFu);
            }
            else
            {
              v62 = (volatile int *)off_11D17C;
              v63 = dword_11D164 + 1320 * *(volatile uint8_t *)(v21 + 34);
              v64 = (volatile uint32_t *)(dword_11D164 + 8 * (165 * *(volatile uint8_t *)(v21 + 34) + 159));
              v65 = (volatile uint32_t *)(dword_11D178 - 664 + 8 * (87 * (uint8_t)(a3 + 32) + 78));
              v66 = (volatile uint32_t *)(dword_11D178 + v20);
              do
              {
                if ( *(volatile uint32_t *)(v21 + 584) )
                {
                  if ( (__get_CPSR() & 1) == 0 )
                  {
                    __disable_irq();
                    *(volatile uint32_t *)off_11D16C = 1;
                  }
                  ++*v62;
                  alloc_tx_event(aCatTobe);
                  get_ptr_value(v65 - 10, v64 - 10);
                  *(volatile uint64_t *)(v63 + 1232) = *(volatile uint64_t *)(v21 + 584);
                  clear_stats_buf(v65 - 10);
                  v67 = *v62 - 1;
                  if ( *v62 )
                  {
                    v68 = (volatile int *)off_11D16C;
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
                  alloc_tx_event(aCatPs);
                  get_ptr_value(v64, v65);
                  clear_stats_buf(v65);
                }
                v65 += 2;
                v64 += 2;
              }
              while ( v65 != v66 );
              irq_disable_global_2(512);
              v18 = (v18 & ~0xFFu) | ((uint8_t)(*(volatile uint8_t *)(dword_11D164 + 1320 * a3 + 234)) & 0xFFu);
            }
          }
        }
      }
      v24 = v3;
      *(volatile uint8_t *)(dword_11CDFC + 1320 * a3 + 234) = v18 + 1;
      return (volatile uint32_t *)lll_conn_get((void *)(uintptr_t)(v24));
    }
    if ( (*(volatile uint16_t *)result & 0x1404) == 0 )
    {
      v25 = *(volatile uint8_t *)(v7 + 35);
      *(volatile uint8_t *)(v7 + 36) = 0;
      if ( v25 <= 0x1F )
      {
        v41 = (volatile uint8_t *)tx_send_pdu(73, 13, 0, 2);
        *v41 = v9;
        v41[1] = 0;
        rx_process_packet_1((int)v41);
        if ( !*(volatile uint8_t *)(v7 + 36) && *(volatile uint8_t *)(v7 + 35) <= 0x1Fu )
        {
          v42 = (volatile int *)off_11D17C;
          v76 = v9;
          v43 = (volatile uint32_t *)(dword_11D164 + 8 * (165 * *(volatile uint8_t *)(v7 + 34) + 159));
          v44 = dword_11D168 + 664 + v6;
          v45 = dword_11D164 + 1320 * *(volatile uint8_t *)(v7 + 34);
          v46 = (volatile uint32_t *)(dword_11D168 + 8 * (87 * (int16_t)v9 + 78));
          v47 = (volatile uint32_t *)v44;
          do
          {
            if ( *(volatile uint32_t *)(v7 + 584) )
            {
              if ( (__get_CPSR() & 1) == 0 )
              {
                __disable_irq();
                *(volatile uint32_t *)off_11D16C = 1;
              }
              ++*v42;
              alloc_tx_event(aCatTobe);
              get_ptr_value(v46 - 10, v43 - 10);
              *(volatile uint64_t *)(v45 + 1232) = *(volatile uint64_t *)(v7 + 584);
              clear_stats_buf(v46 - 10);
              v48 = *v42 - 1;
              if ( *v42 )
              {
                v49 = (void *)(uintptr_t)(off_11D16C);
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
              alloc_tx_event(aCatPs);
              get_ptr_value(v43, v46);
              clear_stats_buf(v46);
            }
            v46 += 2;
            v43 += 2;
          }
          while ( v46 != v47 );
          v9 = v76;
          irq_disable_global_2(512);
        }
      }
      rf_get_rate_table_index(v3, v9);
      v26 = dword_11CDFC + 1320 * a3;
      v27 = (uint8_t)(*(volatile uint8_t *)(v26 + 234) - 1);
      *(volatile uint8_t *)(v26 + 234) = v27;
      if ( !v27 )
      {
        v28 = (uint8_t)(a3 + 32);
        v29 = dword_11CE00 + 696 * v28;
        if ( *(volatile uint8_t *)(v29 + 36) )
        {
          v30 = *(volatile uint8_t *)(v29 + 35);
          *(volatile uint8_t *)(v29 + 36) = 0;
          if ( v30 <= 0x1F )
          {
            v52 = (volatile uint16_t *)tx_send_pdu(73, 13, 0, 2);
            *v52 = (uint8_t)v28;
            rx_process_packet_1((int)v52);
            if ( !*(volatile uint8_t *)(v29 + 36) && *(volatile uint8_t *)(v29 + 35) <= 0x1Fu )
            {
              v53 = (volatile int *)off_11D17C;
              v77 = (uint8_t)(a3 + 32);
              v54 = dword_11D164 + 1320 * *(volatile uint8_t *)(v29 + 34);
              v55 = (volatile uint32_t *)(dword_11D164 + 8 * (165 * *(volatile uint8_t *)(v29 + 34) + 159));
              v56 = (volatile uint32_t *)(dword_11D178 - 664 + 8 * (87 * v77 + 78));
              v57 = dword_11D178 + 696 * v28;
              do
              {
                if ( *(volatile uint32_t *)(v29 + 584) )
                {
                  if ( (__get_CPSR() & 1) == 0 )
                  {
                    __disable_irq();
                    *(volatile uint32_t *)off_11D16C = 1;
                  }
                  ++*v53;
                  alloc_tx_event(aCatTobe);
                  get_ptr_value(v56 - 10, v55 - 10);
                  *(volatile uint64_t *)(v54 + 1232) = *(volatile uint64_t *)(v29 + 584);
                  clear_stats_buf(v56 - 10);
                  v58 = *v53 - 1;
                  if ( *v53 )
                  {
                    v59 = (volatile int *)off_11D16C;
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
                  alloc_tx_event(aCatPs);
                  get_ptr_value(v55, v56);
                  clear_stats_buf(v56);
                }
                v56 += 2;
                v55 += 2;
              }
              while ( (volatile uint32_t *)v57 != v56 );
              v28 = v77;
              irq_disable_global_2(512);
            }
          }
        }
        rf_get_rate_table_index(v3, v28);
      }
      v24 = v3;
      return (volatile uint32_t *)lll_conn_get((void *)(uintptr_t)(v24));
    }
    if ( (v5 & 0xFC) == 0xA4 )
    {
      if ( (*(volatile uint8_t *)(v7 + 53) & 2) != 0 )
      {
        *(volatile uint8_t *)(v7 + 54) |= 1u;
        result = (volatile uint32_t *)is_ll_event_pending(v3, v7, 1);
        *(volatile uint8_t *)(v7 + 54) &= ~1u;
      }
      else
      {
        result = (volatile uint32_t *)build_tx_pdu_lists(v3, dword_11CE00 + 696 * a2, 1);
        if ( !result )
        {
          v51 = tx_send_pdu(74, 13, 0, 4);
          *(volatile uint8_t *)v51 = v9;
          *(volatile uint16_t *)(v51 + 1) = (uint8_t)resulta;
          result = rx_process_packet_1(v51);
        }
      }
    }
    if ( (v5 & 0x8C) == 0x88 )
    {
      v10 = (v5 & 0x300) == 0x300 ? *((volatile uint16_t *)v8 + 15) : *((volatile uint16_t *)v8 + 12);
      v11 = v10 & 7;
      v12 = (volatile uint8_t *)(dword_11CE00 + 696 * v9);
      if ( (*((volatile uint8_t *)off_11CE08 + *((volatile uint8_t *)off_11CE04 + v11)) & v12[310]) != 0 )
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
              v73 = is_ll_event_pending(v3, v7, v72);
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
              *(volatile uint8_t *)(dword_11D1D8 + 696 * v9 + 54) = 4;
              v74 = (volatile uint8_t *)tx_send_pdu(74, 13, 0, 4);
              *v74 = v9;
              v74[1] = v14;
              v74[2] = 1;
              return rx_process_packet_1((int)v74);
            }
LABEL_16:
            v15 = dword_11CE00 + 696 * v9;
            result = (volatile uint32_t *)phy_set_channel(*(volatile uint8_t *)(v15 + 35), v11 | 0x10, 0, 0);
            *(volatile uint8_t *)(v15 + 54) = 0;
          }
        }
        else if ( (v12[54] & 6) == 0 )
        {
          v71 = v12[35];
          v12[54] = 2;
          result = (volatile uint32_t *)phy_set_channel(v71, v11 | 0x10, 0, 0);
          v12[54] = 0;
        }
      }
    }
  }
  return result;
}


