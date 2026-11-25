// phy_radio_switch @ 0x117074
/* luna: Handles the indexed PHY radio instance by programming its selector register and servicing the associated RF status handshake. */
int phy_radio_switch(int result) {
  int v1; // r6
  unsigned int v2; // r4
  unsigned int v3; // r7
  int v4; // r3
  volatile unsigned int *v5; // r8
  int v6; // r5
  int v7; // r3
  int v8; // r2
  unsigned int v9; // r3
  uint16_t v10; // r3
  int v11; // r0
  int v12; // r2
  int v13; // r3
  int v14; // r5
  volatile uint32_t *v15; // r11
  int v16; // r10
  int v17; // r3
  int v18; // r1
  int v19; // r0
  unsigned int v20; // r3
  volatile unsigned int v21; // r2
  int v22; // r3
  unsigned int v23; // r3
  int v24; // r10
  int v25; // r3
  volatile uint32_t *v26; // r2
  volatile uint32_t *v27; // r5
  int v28; // r1
  volatile int *v29; // r3
  int v30; // r3
  unsigned int v31; // r1
  int v32; // r10
  volatile unsigned int v33; // r2
  volatile int *v34; // r3
  int v35; // r3
  volatile uint32_t *v36; // r2
  volatile uint32_t *v37; // r4
  int v38; // r1
  volatile int *v39; // r3
  int v40; // r3
  int v41; // [sp+0h] [bp-14h]
  int v42; // [sp+4h] [bp-10h]
  unsigned int v43; // [sp+8h] [bp-Ch]
  int v44; // [sp+Ch] [bp-8h]

  v1 = result;
  if ( result == 5 )
    v2 = dword_117484;
  else
    v2 = dword_11733C + 84 * result;
  v3 = dword_117344;
  v41 = 1 << result;
  v4 = *(volatile uint8_t *)(v2 + 26);
  v43 = result + dword_117340;
  v5 = (volatile unsigned int *)(4 * (result + dword_117340));
  v42 = ~(1 << result);
  while ( 1 )
  {
    while ( 1 )
    {
      if ( !v4 )
        goto LABEL_14;
      v6 = *(volatile uint32_t *)(v2 + 36);
      v7 = *(volatile uint8_t *)(*(volatile uint32_t *)v3 + 1);
      v8 = *(volatile uint32_t *)(v6 + 144);
      if ( *(volatile uint8_t *)(*(volatile uint32_t *)v3 + 1) )
      {
        if ( v8 >= 0 )
          return result;
        if ( *(volatile uint32_t *)(v6 + 88) || *(volatile uint8_t *)(v2 + 80) != 1 )
        {
          v9 = REG_4032_0120 + *(volatile uint32_t *)(dword_117348 + 4 * v1);
          *v5 = v9;
LABEL_9:
          if ( (v8 & 0x800000) != 0 )
          {
            v10 = *(volatile uint16_t *)(v6 + 8);
            if ( (v10 & 0x20) == 0 )
            {
              rf_irq_status_check();
              v32 = 4;
              while ( 1 )
              {
                v10 = *(volatile uint16_t *)(v6 + 8);
                if ( (v10 & 0x20) != 0 )
                  break;
                rf_irq_status_check();
                if ( !--v32 )
                {
                  v10 = *(volatile uint16_t *)(v6 + 8);
                  if ( **(volatile int16_t **)dword_11746C < 0 && (v10 & 0x20) == 0 )
                    return bad_func_0x12f408((int)aAggDescStatusA, (int)aTxlFrameExchan_0, 1262);
                  goto LABEL_11;
                }
              }
            }
          }
          else
          {
LABEL_36:
            mem_word_load(v2 + 28);
            v10 = *(volatile uint16_t *)(v6 + 8);
          }
          goto LABEL_11;
        }
      }
      else
      {
        if ( *(volatile int *)(v6 + 76) >= 0 )
          return result;
        if ( *(volatile uint32_t *)(v6 + 20) || *(volatile uint8_t *)(v2 + 80) != 1 )
        {
          v23 = REG_4032_0120 + *(volatile uint32_t *)(dword_117348 + 4 * v1);
          *v5 = v23;
          goto LABEL_31;
        }
      }
      if ( *(volatile uint32_t *)(v2 + 44)
        && !*(volatile uint32_t *)(dword_117368 + 8 * (165 * *(volatile uint8_t *)(*(volatile uint32_t *)(v2 + 48) + 28) + v1 + 154))
        && !*(volatile uint8_t *)(dword_117498 + 0x1FF) )
      {
        v44 = *(volatile uint32_t *)(v6 + 144);
        rate_get_config(v1);
        v8 = v44;
        v7 = *(volatile uint8_t *)(*(volatile uint32_t *)v3 + 1);
      }
      v31 = REG_4032_0120 + *(volatile uint32_t *)(dword_117348 + 4 * v1);
      *v5 = v31;
      if ( v7 )
        goto LABEL_9;
LABEL_31:
      v10 = *(volatile uint16_t *)(v6 + 8);
      if ( (v10 & 0x20) == 0 )
      {
        rf_irq_status_check();
        v24 = 4;
        while ( 1 )
        {
          v10 = *(volatile uint16_t *)(v6 + 8);
          if ( (v10 & 0x20) != 0 )
            break;
          rf_irq_status_check();
          if ( !--v24 )
          {
            v10 = *(volatile uint16_t *)(v6 + 8);
            if ( (v10 & 0x20) != 0 )
              break;
            goto LABEL_36;
          }
        }
      }
LABEL_11:
      v11 = *(volatile uint32_t *)(dword_11734C + 4 * v1);
      *(volatile uint16_t *)(v6 + 8) = v10 | 0x10;
      result = unknown_func_12d104(v11);
      v12 = *(volatile uint32_t *)v3;
      --*(volatile uint8_t *)(v2 + 80);
      *(volatile uint8_t *)(v2 + 26) = 0;
      *(volatile uint32_t *)(v2 + 36) = 0;
      if ( *(volatile uint8_t *)(v12 + 1) )
        break;
      v13 = *(volatile uint32_t *)(v6 + 20);
      if ( v13 )
        goto LABEL_13;
LABEL_38:
      *(volatile uint32_t *)v2 = v13;
      v25 = *(volatile uint32_t *)dword_117358;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(volatile uint32_t *)dword_11735C = 1;
      }
      v26 = (volatile uint32_t *)dword_117360;
      result = *(volatile uint32_t *)dword_117360;
      v27 = (volatile uint32_t *)dword_117358;
      v28 = *(volatile uint32_t *)dword_117360 + 1;
      *(volatile uint32_t *)dword_117360 = v28;
      *v27 = v25 & v42;
      if ( v28 )
      {
        v29 = (volatile int *)dword_11735C;
        *v26 = result;
        v30 = *v29;
        if ( !result )
        {
          if ( v30 )
            __enable_irq();
        }
      }
      *(volatile uint32_t *)dword_117364 = v41;
      v4 = *(volatile uint8_t *)(v2 + 26);
    }
    v13 = *(volatile uint32_t *)(v6 + 88);
    if ( !v13 )
      goto LABEL_38;
LABEL_13:
    *(volatile uint32_t *)(v2 + 40) = v6;
    ++*(volatile uint8_t *)(v6 + 14);
LABEL_14:
    v14 = *(volatile uint32_t *)(v2 + 12);
    if ( !v14 )
      break;
    v15 = *(volatile uint32_t **)(v14 + 76);
    v16 = v15[18];
    if ( v16 >= 0 )
    {
      if ( (*(volatile uint32_t *)(v14 + 36) & 0x380000) == 0x280000 )
        return get_hw_state(*(volatile uint32_t *)(v14 + 68) + 16, v1);
      return result;
    }
    v15[1] = v16;
    get_channel_by_handle(v1);
    v17 = *(volatile uint32_t *)(v14 + 36) & 0x200000;
    if ( !v17 )
    {
      v18 = v15[4];
      if ( v18 )
      {
        v19 = v15[4];
        if ( (*(volatile uint32_t *)(v18 + 56) & 0x380000) == 0x200000 )
        {
          if ( **(volatile int16_t **)dword_11736C < 0 && !*(volatile uint32_t *)(v18 + 8) )
          {
            mmio_clear_register((int)aNextdescNull, (int)aTxlFrameExchan_0, 1077);
            __und(0xFFu);
          }
          v17 = v15[4];
          v19 = *(volatile uint32_t *)(v18 + 8);
        }
        if ( *(volatile int *)(v19 + 60) >= 0 )
        {
          result = v17;
          if ( v17 )
            result = get_hw_state(v17, v1);
          v33 = REG_4032_0120;
          *(volatile uint32_t *)(4 * v43) = v33 + *(volatile uint32_t *)(dword_117478 + 4 * v1);
          return result;
        }
      }
      else
      {
        *(volatile uint32_t *)v2 = 0;
        mmio_set_bit_1(v1);
        if ( *(volatile uint8_t *)(v2 + 80) == 1
          && *(volatile uint32_t *)(v2 + 44)
          && !*(volatile uint32_t *)(dword_117368 + 8 * (165 * *(volatile uint8_t *)(*(volatile uint32_t *)(v2 + 48) + 28) + v1 + 154))
          && !*(volatile uint8_t *)(dword_11733C + 0x1FF) )
        {
          rate_get_config(v1);
        }
      }
    }
    if ( (v16 & 0x800000) != 0 )
    {
      v20 = *(volatile uint8_t *)(v14 + 29);
      if ( v20 <= 0x23 )
      {
        v21 = (*(volatile uint32_t *)0x40501010u);
        *(volatile uint32_t *)(dword_117350 + 696 * v20 + 664) = v21;
      }
    }
    mem_word_load(v2 + 12);
    if ( *(volatile uint16_t *)(v14 + 4) )
      ipc_handler_register((volatile uint32_t *)v14, v16, v1);
    else
      free_buf_1882c0((volatile uint32_t *)v14);
    v22 = *(volatile uint32_t *)(v14 + 36);
    result = v22 << 10;
    if ( (v22 & 0x200000) != 0 )
    {
      if ( (v22 & 0x380000) == 0x380000 )
      {
        *(volatile uint32_t *)(v2 + 36) = *(volatile uint32_t *)(v14 + 68);
        *(volatile uint8_t *)(v2 + 26) = 1;
        result = unknown_func_12d104(512);
      }
    }
    else
    {
      --*(volatile uint8_t *)(v2 + 80);
    }
    *v5 = REG_4032_0120 + *(volatile uint32_t *)(dword_117348 + 4 * v1);
    v4 = *(volatile uint8_t *)(v2 + 26);
  }
  v34 = (volatile int *)dword_117488;
  *(volatile uint32_t *)v2 = 0;
  v35 = *v34;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)dword_11748C = 1;
  }
  v36 = (volatile uint32_t *)dword_117490;
  result = *(volatile uint32_t *)dword_117490;
  v37 = (volatile uint32_t *)dword_117488;
  v38 = *(volatile uint32_t *)dword_117490 + 1;
  *(volatile uint32_t *)dword_117490 = v38;
  *v37 = v35 & v42;
  if ( v38 )
  {
    v39 = (volatile int *)dword_11748C;
    *v36 = result;
    v40 = *v39;
    if ( !result )
    {
      if ( v40 )
        __enable_irq();
    }
  }
  *(volatile uint32_t *)dword_117494 = v41;
  return result;
}


// phy_band_validate @ 0x11749c
/* luna: Initializes the indexed RF transmit context and event slot, clears per-slot fields, and updates the corresponding global slot mask. */
int phy_band_validate(int a1) {
  volatile uint32_t *v2; // r5
  int v3; // r3
  int v4; // r4
  volatile uint32_t *v5; // r2
  volatile int *v6; // r5
  int v7; // r1
  int result; // r0
  volatile int *v9; // r3
  int v10; // r3

  if ( a1 == 5 )
    v2 = (volatile uint32_t *)dword_117530;
  else
    v2 = (volatile uint32_t *)(dword_117518 + 84 * a1);
  rf_tx_setup(a1, dword_11751C + 8 * a1, 0);
  rf_tx_setup(a1, (int)(uintptr_t)(v2 + 3), 0);
  *v2 = 0;
  v2[5] = 0;
  init_event_slot(a1);
  v3 = *(volatile uint32_t *)off_117520;
  v4 = 1 << a1;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_117524 = 1;
  }
  v5 = (void *)(uintptr_t)(off_117528);
  v6 = (volatile int *)off_117520;
  v7 = *(volatile uint32_t *)off_117528;
  result = *(volatile uint32_t *)off_117528 + 1;
  *(volatile uint32_t *)off_117528 = result;
  *v6 = v3 & ~v4;
  if ( result )
  {
    v9 = (volatile int *)off_117524;
    *v5 = v7;
    v10 = *v9;
    if ( !v7 )
    {
      if ( v10 )
        __enable_irq();
    }
  }
  *(volatile uint32_t *)off_11752C = v4;
  return result;
}



// dma_rx_setup @ 0x117534
/* luna: Initializes two five-entry RF transmit configuration tables by calling rf_tx_setup for each indexed entry. */
int dma_rx_setup(int a1) {
  int v1; // r4
  int v2; // r5
  int v3; // r0
  int result; // r0
  int v5; // [sp+4h] [bp-8h]

  v1 = a1 + 1272;
  v2 = 0;
  do
  {
    v3 = (uint8_t)v2;
    v5 = (uint8_t)v2++;
    rf_tx_setup(v3, v1, 0);
    result = (int)(uintptr_t)(rf_tx_setup(v5, v1 - 40, 0));
    v1 += 8;
  }
  while ( v2 != 5 );
  return result;
}



// phy_chan_set @ 0x117564
/* luna: Configures the requested PHY channel by initializing its state, applying rate and TX-length settings, issuing the channel command, and initializing th */
int phy_chan_set(int a1, int a2) {
  volatile char *phy_config_entry; // r7
  int v5; // r0
  int16_t v6; // r1
  volatile uint32_t *phy_state_words; // r3
  int v8; // r3
  volatile uint8_t *v9; // r2
  volatile int *irq_lock_depth; // r6
  int result; // r0
  int v12; // r3
  int v13; // r3
  int v14; // r2
  volatile unsigned int v15; // r2

  if ( a2 == 5 )
    phy_config_entry = (volatile char *)dword_117688;
  else
    phy_config_entry = (volatile char *)off_117664 + 84 * a2;
  v5 = dword_117668;
  v6 = *(volatile uint16_t *)(a1 + 30);
  phy_state_words = *(volatile uint32_t **)(a1 + 76);
  phy_state_words[9] = *(volatile uint8_t *)(a1 + 51) + *(volatile uint8_t *)(a1 + 53) + *(volatile uint16_t *)(a1 + 4) + 4;
  phy_state_words[8] = 0;
  phy_state_words[13] = 0;
  phy_state_words[14] = 0;
  phy_state_words[4] = 0;
  phy_state_words[5] = 0;
  phy_state_words[6] = 0;
  phy_state_words[7] = 0;
  phy_state_words[3] = v5;
  phy_state_words[15] = 0;
  phy_state_words[12] = 0;
  phy_state_words[17] = 0;
  phy_state_words[10] = 0;
  if ( (v6 & 1) == 0 )
    phy_state_words[18] = 0;
  v8 = *((volatile uint32_t *)off_11766C + 8);
  if ( v8 )
  {
    v9 = *(volatile uint8_t **)off_117670;
    *(volatile uint32_t *)off_117674 = 0x80000000;
    if ( *v9 == 3 && v8 == dword_117680 + 1320 * *(volatile uint8_t *)(a1 + 28) )
    {
      v15 = (*(volatile uint32_t *)0x40501010u);
      *(volatile uint32_t *)(v8 + 120) = v15;
    }
  }
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_117678 = 1;
  }
  irq_lock_depth = (volatile int *)off_11767C;
  ++*(volatile uint32_t *)off_11767C;
  rate_set_config(a1, a2);
  cmd_handler_a((int)(phy_config_entry + 12), (volatile uint32_t *)a1);
  tx_len_check(*(volatile uint8_t *)(a1 + 28), *(volatile uint8_t *)(a1 + 29), 0);
  if ( (*(volatile uint16_t *)(a1 + 30) & 1) == 0 )
    ++*((volatile uint32_t *)off_117664 + 126);
  wlc_is_ready(a1);
  result = dma_ring_init(a1, a2, 0);
  v12 = *irq_lock_depth;
  *(volatile uint16_t *)(a1 + 82) |= 1u;
  if ( v12 )
  {
    v13 = v12 - 1;
    v14 = *(volatile uint32_t *)off_117678;
    *irq_lock_depth = v13;
    if ( !v13 )
    {
      if ( v14 )
        __enable_irq();
    }
  }
  return result;
}


// irq_counter_inc @ 0x11768c
/* luna: Increments the volatile IRQ counter at byte offset 0x1F8 from the global state base. */
void irq_counter_inc() {
  ++*((volatile uint32_t *)off_11769C + 126);
}



// phy_radio_init @ 0x1176a0
/* luna: Processes a per-interface PHY event, checks link and channel conditions, updates state, and dispatches the associated command handler. */
int phy_radio_init(int a1, int a2) {
  volatile char *v4; // r7
  int v5; // r10
  int v6; // r8
  int v7; // r11
  int v8; // r9
  int v10; // r3
  int16_t v11; // r1
  int v12; // r6
  int v13; // r3
  volatile int *v14; // r6
  int v15; // r2
  char v16; // r3
  int v17; // r1
  volatile uint8_t *v18; // r3
  volatile unsigned int v19; // r3
  int v20; // r3
  int v21; // r2
  int v22; // r2
  int v23; // r1
  int16_t v24; // r3
  volatile int *v25; // r3
  int v26; // r3
  int v27; // r2
  int v28; // r3
  int v29; // r2
  volatile uint32_t *v30; // r3
  int v31; // [sp+4h] [bp-8h]

  if ( a2 == 5 )
    v4 = (volatile char *)dword_11788C;
  else
    v4 = (volatile char *)off_117888 + 84 * a2;
  v5 = *(volatile uint8_t *)(a1 + 28);
  v6 = dword_1178C0;
  v7 = *(volatile uint32_t *)(a1 + 76);
  v8 = dword_1178C0 + 1320 * v5;
  if ( isr_flag_dispatch(v8)
    && ((v10 = *(volatile uint8_t *)(a1 + 28), *(volatile uint8_t *)(v6 + 1320 * v10 + 106))
     || *(volatile uint8_t *)(a1 + 29) > 0x23u
     || *(volatile uint16_t *)(a1 + 4)
     || (v11 = *(volatile uint16_t *)(*(volatile uint32_t *)(a1 + 72) + 108), (uint8_t)v11 != 192)
     && (uint8_t)v11 != 176
     && (v11 & 0xDF) != 0
     || (v12 = *((volatile uint32_t *)off_117890 + 10)) == 0
     || *(volatile uint8_t *)(v12 + 24) <= 2u
     || (v13 = *(volatile uint32_t *)(v6 + 1320 * v10 + 72)) == 0
     || (v31 = v13, event_dispatch("is_on_chan:%d, %x\n", v12 == v13, (uint8_t)v11), v12 == v31))
    && bt_is_link_active(a1) )
  {
    *(volatile uint32_t *)(v7 + 68) |= 0x100u;
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(volatile uint32_t *)off_117898 = 1;
    }
    v14 = (volatile int *)off_11789C;
    v15 = *((volatile uint32_t *)v4 + 11);
    v16 = v4[80] + 1;
    ++*(volatile uint32_t *)off_11789C;
    v4[80] = v16;
    if ( v15 )
      rate_get_config(a2);
    if ( !*((volatile uint32_t *)v4 + 5) )
    {
      v30 = *(volatile uint32_t **)(a1 + 72);
      v30[4] = dword_1178BC;
      v30[2] = a1;
      v30[3] = a1;
    }
    cmd_handler_a((int)(v4 + 12), (volatile uint32_t *)a1);
    v17 = *((volatile uint32_t *)off_1178A0 + 8);
    ++*((volatile uint32_t *)off_117888 + 126);
    if ( v17 )
    {
      v18 = *(volatile uint8_t **)off_1178A4;
      *(volatile uint32_t *)off_1178A8 = 0x80000000;
      if ( *v18 == 3 && v17 == v8 )
      {
        v19 = (*(volatile uint32_t *)0x40501010u);
        *(volatile uint32_t *)(v6 + 1320 * v5 + 120) = v19;
      }
    }
    if ( **(volatile uint8_t **)off_1178B0 == 2 && (*(volatile uint32_t *)off_1178B4 & dword_1178B8) == 0 )
      process_global_167204();
    if ( *v14 )
    {
      v20 = *v14 - 1;
      v21 = *(volatile uint32_t *)off_117898;
      *v14 = v20;
      if ( !v20 )
      {
        if ( v21 )
          __enable_irq();
      }
    }
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(volatile uint32_t *)off_117898 = 1;
    }
    v22 = *v14;
    v23 = *v14 + 1;
    v24 = *(volatile uint16_t *)(a1 + 82) | 1;
    *v14 = v23;
    *(volatile uint16_t *)(a1 + 82) = v24;
    if ( v23 )
    {
      v25 = (volatile int *)off_117898;
      *v14 = v22;
      v26 = *v25;
      if ( !v22 )
      {
        if ( v26 )
          __enable_irq();
      }
    }
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(volatile uint32_t *)off_117898 = 1;
    }
    v27 = *(volatile uint32_t *)(a1 + 72);
    ++*v14;
    mac_flags_set(a1, a1, v27, a2);
    if ( *v14 )
    {
      v28 = *v14 - 1;
      v29 = *(volatile uint32_t *)off_117898;
      *v14 = v28;
      if ( !v28 )
      {
        if ( v29 )
          __enable_irq();
      }
    }
    return 1;
  }
  else if ( *(volatile uint8_t *)(a1 + 29) == 255 )
  {
    scan_control(a1, 0);
    return 0;
  }
  else
  {
    phy_ctx_get_by_index(a1, a2);
    return 1;
  }
}


// nullsub_7 @ 0x1178c4
/* luna: Returns zero without performing any operation. */
int nullsub_7(void) {
  return 0;
}


// core_rev_read @ 0x1178c8
/* luna: Reads the masked PHY core configuration, conditionally enables the radio clock, dispatches the encoded revision index, and caches the configuration. */
unsigned int core_rev_read() {
  int v0; // r4
  unsigned int result; // r0

  v0 = dword_117918 & *(volatile uint32_t *)off_117914;
  if ( (*(volatile uint32_t *)off_117914 & 0x10) != 0 )
  {
    if ( (*(volatile uint32_t *)off_117914 & 0x1000) != 0 )
    {
      v0 |= 0x1000u;
      *((volatile uint32_t *)off_117920 + 52) |= 4u;
    }
    ((int (*)())enable_radio_clock)();
  }
  result = v0 & 0xF00000;
  if ( (v0 & 0xF00000) != 0 )
    result = dispatch_command((uint8_t)(11 - __clz(result)));
  *(volatile uint32_t *)off_11791C = v0;
  return result;
}



// chip_type_read @ 0x117924
/* luna: Reads and acknowledges PHY status events, then dispatches RX handling, radio-core reset, or radio switching as indicated by the status bits. */
int chip_type_read(int result) {
  int v1; // r4
  int v2; // r5
  unsigned int v3; // r3
  unsigned int v4; // r4

  v1 = *(volatile uint32_t *)off_1179CC;
  if ( (*(volatile uint32_t *)off_1179CC & 0x1000) != 0 )
  {
    result = ((int (*)())reset_radio_core)(result, *(volatile uint32_t *)off_1179CC << 19);
    *(volatile uint32_t *)off_1179E0 = 4096;
  }
  v2 = dword_1179D0;
  if ( (v1 & dword_1179D0) != 0 )
  {
    result = ((int (*)())handle_rx_event)();
    *(volatile uint32_t *)off_1179E0 = v2;
  }
  if ( (dword_1179D4 & v1) != 0 && (*(volatile uint32_t *)off_1179D8 & 0x300000) == 0 )
  {
    *(volatile uint32_t *)off_1179E8 |= 0x200u;
    v3 = dword_1179DC & v1;
    if ( (dword_1179DC & v1) == 0 )
      return result;
  }
  else
  {
    v3 = dword_1179DC & v1;
    if ( (dword_1179DC & v1) == 0 )
      return result;
  }
  if ( (v1 & 0x80000) != 0 )
  {
LABEL_9:
    *(volatile uint32_t *)off_1179E0 = 0x80000;
    return phy_radio_switch(5);
  }
  v4 = (uint8_t)(25 - __clz(v3));
  if ( **(volatile int16_t **)off_1179E4 >= 0 || v4 <= 6 )
  {
    if ( v4 == 5 )
      goto LABEL_9;
  }
  else
  {
    mmio_clear_register(dword_1179F0, dword_1179EC, 2883);
  }
  *(volatile uint32_t *)off_1179E0 = 1 << (v4 + 6);
  return phy_radio_switch(v4);
}



// chip_status_read @ 0x1179f4
/* luna: Reads status bits 20–23, dispatches the index of the highest set bit, and writes the captured mask back to the status register. */
int chip_status_read() {
  unsigned int v0; // r4
  int result; // r0

  v0 = *(volatile uint32_t *)off_117A1C & 0xF00000;
  if ( v0 )
  {
    result = dispatch_command((uint8_t)(11 - __clz(v0)));
    *(volatile uint32_t *)off_117A20 = v0;
  }
  else
  {
    *(volatile uint32_t *)off_117A20 = 0;
  }
  return result;
}



// func_117a24 @ 0x117a24
/* luna: Under an IRQ-preserving critical section, scans five slots and sets the hardware bit for each eligible slot, then marks a shared state byte. */
void func_117a24() {
  volatile int *v0; // r9
  volatile uint32_t *v1; // r7
  volatile uint8_t *v2; // r8
  volatile uint32_t *v3; // r5
  volatile uint8_t *v4; // r6
  int i; // r4
  int v6; // r3
  int v7; // r3
  int v8; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_117AA8 = 1;
  }
  v0 = (volatile int *)off_117AB0;
  v1 = (void *)(uintptr_t)(off_117AAC);
  v2 = (void *)(uintptr_t)(off_117AB4);
  ++*(volatile uint32_t *)off_117AB0;
  v3 = v1;
  v4 = v2;
  for ( i = 4; i != -1; --i )
  {
    if ( !*((volatile uint8_t *)v3 + 158)
      && ((v1[52] & 1) == 0 || *((volatile uint8_t *)v1 + 190) != (uint8_t)i)
      && *((volatile uint32_t *)v4 + 84) )
    {
      mmio_set_bit_1((uint8_t)i);
    }
    v3 -= 7;
    v4 -= 84;
  }
  v6 = *v0;
  v2[511] = 1;
  if ( v6 )
  {
    v7 = v6 - 1;
    v8 = *(volatile uint32_t *)off_117AA8;
    *v0 = v7;
    if ( !v7 )
    {
      if ( v8 )
        __enable_irq();
    }
  }
}



// fatal_error_handler @ 0x117ab8
/* luna: Scans five configuration slots, dispatches eligible commands, records per-slot deadlines, and sets the corresponding active-command bits under the int */
int fatal_error_handler() {
  volatile int *v0; // r7
  volatile uint8_t *v1; // r5
  volatile uint32_t *v2; // r8
  volatile uint32_t *v3; // r11
  int v4; // r10
  volatile int *v5; // r9
  volatile uint32_t *v6; // r6
  int i; // r4
  int v8; // r0
  int v9; // r2
  int v10; // r1
  int v11; // r3
  volatile int *v12; // r3
  int v13; // r3
  int v14; // r3
  int v15; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_117B98 = 1;
  }
  v0 = (volatile int *)off_117B9C;
  v1 = (void *)(uintptr_t)(off_117BA0);
  v2 = (void *)(uintptr_t)(off_117BAC);
  v3 = (void *)(uintptr_t)(off_117BB0);
  v4 = dword_117BB4;
  v5 = (volatile int *)off_117BB8;
  ++*(volatile uint32_t *)off_117B9C;
  v1[511] = 0;
  v6 = v2;
  for ( i = 4; i != -1; --i )
  {
    v8 = (uint8_t)i;
    if ( !*((volatile uint8_t *)v6 + 158) && ((v2[52] & 1) == 0 || *((volatile uint8_t *)v2 + 190) != (uint8_t)i) )
    {
      if ( *((volatile uint32_t *)v1 + 84) )
      {
        dispatch_config_command((uint8_t)i);
        *(volatile uint32_t *)(dword_117BA4 + 4 * i) = *v3 + *(volatile uint32_t *)(v4 + 4 * i);
        *(volatile uint32_t *)off_117BA8 = 1 << i;
        v8 = (uint8_t)i;
        if ( (__get_CPSR() & 1) == 0 )
        {
          __disable_irq();
          *(volatile uint32_t *)off_117B98 = 1;
        }
        v9 = *v0;
        v10 = *v0 + 1;
        v11 = (1 << i) | *v5;
        *v0 = v10;
        *v5 = v11;
        if ( v10 )
        {
          v12 = (volatile int *)off_117B98;
          *v0 = v9;
          v13 = *v12;
          if ( !v9 )
          {
            if ( v13 )
              __enable_irq();
          }
        }
      }
      test_flag(v8);
    }
    v6 -= 7;
    v1 -= 84;
  }
  if ( *v0 )
  {
    v14 = *v0 - 1;
    v15 = *(volatile uint32_t *)off_117B98;
    *v0 = v14;
    if ( !v14 )
    {
      if ( v15 )
        __enable_irq();
    }
  }
  return unknown_func_12d104(512);
}



// mem_pool_init @ 0x117bbc
/* luna: Configures five RF transmit entries, locks the PLL and processes radio completion, then resets associated records and a fixed-size pool. */
uint64_t mem_pool_init() {
  volatile uint8_t *v0; // r8
  int v1; // r10
  volatile char *v2; // r5
  volatile uint8_t *v3; // r4
  int v4; // r9
  volatile uint32_t *v5; // r7
  int v6; // r6
  unsigned int v7; // r11
  int v8; // r9
  volatile uint32_t *v9; // r0
  uint16_t v10; // r7
  volatile uint32_t *v11; // r0
  int i; // r6
  volatile uint32_t *v13; // r0
  int v14; // r2
  uint64_t result; // r0
  volatile uint32_t *v16; // r3
  uint8_t v17[44]; // [sp+0h] [bp-2Ch] BYREF

  v0 = (void *)(uintptr_t)(off_117CBC);
  v1 = dword_117CC0;
  unknown_func_12d14c(126976);
  v2 = v0 + 12;
  v3 = v17;
  v0[510] = 1;
  v4 = (int)(v0 + 12);
  v5 = (void *)(v17);
  v6 = 0;
  do
  {
    v7 = (uint8_t)v6;
    zero_8_bytes(v5);
    rf_tx_setup((uint8_t)v6++, v1, (int)v5);
    rf_tx_setup(v7, v4, (int)v5);
    v1 += 8;
    v5 += 2;
    v4 += 84;
  }
  while ( v6 != 5 );
  v8 = dword_117CB4;
  rf_pll_lock(5, dword_117CB4);
  process_event_loop();
  v9 = (void *)(uintptr_t)(init_buf_188290());
  handle_radio_done((int)v9);
  v10 = *((volatile uint16_t *)v0 + 254);
  memset((volatile int *)(v8 - 432), 0, 0x204u);
  *((volatile uint16_t *)v0 + 254) = v10;
  do
  {
    zero_8_bytes((void *)(v2));
    *((volatile uint32_t *)v2 - 3) = 0;
    v2[14] = 0;
    v2[68] = 0;
    *((volatile uint32_t *)v2 + 6) = 0;
    *((volatile uint32_t *)v2 + 7) = 0;
    v11 = (void *)(v2 + 16);
    v2 += 84;
    zero_8_bytes(v11);
  }
  while ( v2 != (volatile char *)v8 );
  for ( i = 0; i != 5; ++i )
  {
    v13 = mem_word_load((int)v3);
    if ( v13 )
    {
      do
      {
        ll_conn_reset_flags((int)v13, (uint8_t)i);
        v13 = mem_word_load((int)v3);
      }
      while ( v13 );
      test_flag((uint8_t)i);
    }
    v3 += 8;
  }
  v14 = dword_117CB8;
  result = (unsigned int)(dword_117CB8 + 1152);
  do
  {
    v16 = (volatile uint32_t *)(v14 - 36);
    do
      *v16++ = 0;
    while ( (volatile uint32_t *)v14 != v16 );
    v14 += 36;
  }
  while ( (uint32_t)result != v14 );
  return result;
}


// timer_queue_init @ 0x117cc4
/* luna: Populates a global six-value PHY timing table by scaling input values by 1000, using defaults for zero-valued entries among the first four inputs. */
int timer_queue_init(int a1) {
  volatile uint64_t *v1; // r6
  volatile uint64_t *v2; // r7
  int v3; // r2
  volatile uint32_t *v4; // r4
  int result; // r0
  volatile int *v6; // r1
  int v7; // r3
  int v8; // t1
  uint64_t v9; // kr00_8
  uint64_t v10; // r2

  v1 = (void *)(uintptr_t)(off_117D08);
  v2 = (void *)(uintptr_t)(off_117D0C);
  v3 = a1 - 4;
  v4 = (void *)(uintptr_t)(off_117D08);
  result = a1 + 12;
  v6 = (volatile int *)off_117D0C;
  do
  {
    v8 = *(volatile uint32_t *)(v3 + 4);
    v3 += 4;
    v7 = v8;
    if ( !v8 )
      v7 = *v6;
    *v4++ = 1000 * v7;
    ++v6;
  }
  while ( v3 != result );
  v9 = v2[2];
  v10 = (v10 & ~0xFFFFFFFFull) | ((uint32_t)(1000 * v9) & 0xFFFFFFFFu);
  v10 = (v10 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(1000 * HIDWORD(v9)) << 32);
  v1[2] = v10;
  return result;
}



// compare_uint16_field @ 0x117d10
/* luna: Returns true when the 16-bit value at offset 32 in the second object is greater than or equal to the first object's value and no more than 63 ahead. */
BOOL compare_uint16_field(int a1, int a2) {
  unsigned int v2; // r3
  unsigned int v3; // r0

  v2 = *(volatile uint16_t *)(a1 + 32);
  v3 = *(volatile uint16_t *)(a2 + 32);
  if ( v2 > v3 )
    return 0;
  if ( v2 >= v3 )
    return 1;
  return (int)(v3 - v2) <= 63;
}



// ll_state_check @ 0x117d30
/* luna: When an operation has a negative status, packages its error details into a queued confirmation command and logs the status. */
int ll_state_check(int result, volatile uint32_t *a2) {
  int v2; // r3
  int v3; // r2
  int v4; // r4
  volatile uint8_t *v6; // r6
  volatile uint8_t *v7; // r9
  volatile uint32_t *v8; // r0
  int v9; // r12
  volatile uint32_t *v10; // r7
  unsigned int v11; // r3
  int16_t v12; // lr
  int v13; // r2
  volatile uint32_t *v14; // r1
  int v15; // r3
  volatile int *v16; // r12
  volatile int *v17; // r6
  int v18; // r2
  int v19; // r3
  int v20; // r3
  int v21; // r2
  int v22; // r6
  struct __attribute__((packed)) { int v23; // [sp+0h] [bp-28h] BYREF
  int v24; // [sp+4h] [bp-24h]
  } _frame;
  v2 = *(volatile uint32_t *)(result + 84);
  if ( v2 < 0 )
  {
    v3 = **(volatile uint8_t **)off_117EAC;
    v4 = result;
    switch ( v3 )
    {
      case 2:
        v6 = (void *)(error_trap());
        if ( v6 )
        {
          v7 = (void *)(uintptr_t)(off_117ED8);
          if ( *((volatile uint32_t *)off_117ED8 + 2057) )
          {
            v8 = mem_word_load(dword_117EB0);
            *v6 = 8;
            v6[1] = 0;
            v6[3] = 0;
            v6[2] = 18;
            v9 = *a2 & 0xF;
            v10 = v8;
            _frame.v24 = *(volatile uint32_t *)(v4 + 84) & 0x3FFFFFFF;
            _frame.v23 = v9;
            memcpy(v6 + 4, (volatile char *)&_frame.v23, 8u);
            v11 = *((volatile uint16_t *)v7 + 4122);
            if ( v11 > 0x186 )
            {
              v13 = 0;
              v11 = (v11 & ~0xFFFFu) | ((uint16_t)(0) & 0xFFFFu);
              v12 = 1;
            }
            else
            {
              v12 = v11 + 1;
              v13 = 8 * v11;
            }
            v14 = (void *)(uintptr_t)(off_117EB4);
            *((volatile uint16_t *)v10 + 6) = v11;
            v15 = dword_117EB8;
            v16 = (volatile int *)(*v14 + v13);
            v16[1] = (int)v6;
            *v16 = v15 & *v16 | 0x400000C;
            v15 = (v15 & ~0xFFu) | ((uint8_t)(v7[3074]) & 0xFFu);
            *((volatile uint16_t *)v7 + 4122) = v12;
            v7[3074] = v15 + 1;
            v10[1] = (int)(uintptr_t)(v16);
            *((volatile uint8_t *)v10 + 14) = 1;
            *v10 = 0;
            v10[2] = 12;
            if ( (__get_CPSR() & 1) == 0 )
            {
              __disable_irq();
              *(volatile uint32_t *)off_117EBC = 1;
            }
            v17 = (volatile int *)off_117EC0;
            v18 = *(volatile uint16_t *)(v4 + 32);
            v19 = *a2 & 0xF;
            ++*(volatile uint32_t *)off_117EC0;
            event_dispatch("cfms: %x, sn=%d, st=%d\r\n", v4, v18, v19);
            cmd_handler_a(dword_117EC8, v10);
            result = check_init_flag();
            if ( *v17 )
            {
              v20 = *v17 - 1;
              v21 = *(volatile uint32_t *)off_117EBC;
              *v17 = v20;
              if ( !v20 )
              {
                if ( v21 )
                  __enable_irq();
              }
            }
          }
          else
          {
            return log_printf(aErrTxlCfmNoBuf);
          }
        }
        else
        {
          return log_printf(aErrNoMsgPkt);
        }
        break;
      case 1:
        v22 = *a2 & 0xF;
        _frame.v24 = v2 & 0x3FFFFFFF;
        _frame.v23 = v22;
        mutex_lock(18, (volatile char *)&_frame.v23, 8u, v2 & 0x3FFFFFFF);
        return event_dispatch("cfms: %x, sn=%d, st=%d\r\n", v4, *(volatile uint16_t *)(v4 + 32), *a2 & 0xF);
      case 3:
        *(volatile uint32_t *)((volatile uint32_t *)(uintptr_t)off_117ECC)[0] = *a2 & 0xF;
        gpio_set_pin8();
        break;
    }
  }
  return result;
}


// init_buf_188290 @ 0x117edc
int init_buf_188290() {
  int v0; // r4

  v0 = dword_117F14;
  memset((volatile int *)dword_117F14, 0, 0x28u);
  zero_8_bytes((void *)(uintptr_t)(v0));
  zero_8_bytes((void *)(uintptr_t)(v0 + 8));
  zero_8_bytes((void *)(uintptr_t)(v0 + 16));
  zero_8_bytes((void *)(uintptr_t)(v0 + 24));
  return (int)(uintptr_t)(zero_8_bytes((void *)(uintptr_t)(v0 + 32)));
}



// ipc_handler_register @ 0x117f18
/* luna: Stores the supplied value in a nested context field, processes the indexed operation-table entry, and invokes an indexed fallback callback when flag b */
int ipc_handler_register(volatile uint32_t *a1, int a2, int a3) {
  int v3; // r3
  int v5; // r0
  int result; // r0

  v3 = a1[19];
  v5 = dword_117F44;
  *(volatile uint32_t *)(v3 + 4) = a2;
  result = cmd_handler_a(v5 + 8 * a3, a1);
  if ( (a1[9] & 0x200000) == 0 )
    return unknown_func_12d104(((volatile uint32_t *)(uintptr_t)off_117F48)[a3]);
  return result;
}


