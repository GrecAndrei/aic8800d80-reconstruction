// chan_ctxt_unlink @ 0x12847c
int chan_ctxt_unlink(int a1) {
  volatile int16_t **v1; // r9
  int v2; // r8
  int v3; // r10
  int v4; // r6
  int v6; // r5
  volatile uint8_t *v7; // r7
  char v8; // r3
  int v9; // r3
  int v10; // r4
  int v11; // r3
  int v12; // r5
  volatile uint8_t *v13; // r3
  int v14; // r0
  int v15; // r3
  volatile uint32_t *v16; // r4
  int v17; // r2
  int v18; // r3
  volatile uint16_t *v20; // r2
  unsigned int v21; // r3
  int v22; // r3
  int v23; // r1
  volatile uint32_t *v24; // r0
  int v25; // r1
  int v26; // r3
  int v27; // r2
  volatile char *v28; // r1

  v1 = (volatile int16_t **)off_128744;
  v2 = dword_12873C;
  v3 = 1320 * a1;
  v4 = *(volatile uint32_t *)(dword_12873C + 1320 * a1 + 72);
  if ( **(volatile int16_t **)off_128744 < 0 && !v4 )
    irq_disable_mmio_write((int)aCtxtNull, (int)aChanCtxtUnlink, 3149);
  v6 = v2 + 1320 * a1;
  v7 = (volatile uint8_t *)off_128714;
  check_feature_flag(
    256,
    "chan unlink: %d,%d,%d,%d,%d\r\n",
    *(volatile uint8_t *)(v4 + 25),
    *((volatile uint8_t *)off_128714 + 91),
    *((volatile uint8_t *)off_128714 + 90),
    *(volatile uint8_t *)(v6 + 85),
    *(volatile uint8_t *)(v4 + 16));
  wlan_ioctl_handler_3((int)(v7 + 16), (volatile uint32_t *)(v3 + 76 + v2));
  v8 = *(volatile uint8_t *)(v6 + 85);
  *(volatile uint8_t *)(v6 + 85) = v8 & 0xFE;
  if ( (v8 & 2) != 0 )
  {
    v9 = (uint8_t)(v7[91] - 1);
    v7[91] = v9;
    if ( !v9 && (v7[88] & 0x40) != 0 )
    {
      alloc_tx_event(aUnlinkFixUntil);
      llc_hw_reg_sync(*((volatile uint32_t *)v7 + 20));
    }
  }
  v10 = v2 + 1320 * a1;
  *(volatile uint8_t *)(v10 + 85) = 0;
  *(volatile uint32_t *)(v10 + 72) = 0;
  v11 = *(volatile uint8_t *)(v4 + 16);
  v12 = (uint8_t)(*(volatile uint8_t *)(v4 + 25) - 1);
  *(volatile uint8_t *)(v4 + 25) = v12;
  if ( v11 )
  {
    if ( *(volatile uint8_t *)(v4 + 27) == *(volatile uint8_t *)(v10 + 107) )
    {
      scan_entry_lookup(v2 + v3);
      v12 = *(volatile uint8_t *)(v4 + 25);
      *(volatile uint8_t *)(v4 + 27) = -1;
      if ( v12 )
        return type_get(v4);
    }
    else
    {
      v13 = (volatile uint8_t *)off_12871C;
      while ( 1 )
      {
        if ( v13[24] != 255 )
        {
          v14 = v13[27];
          if ( v14 != 255 )
            break;
        }
        v13 += 28;
        if ( (volatile uint8_t *)((volatile char *)off_12871C + 84) == v13 )
          goto LABEL_10;
      }
      v24 = (volatile uint32_t *)(v2 + 1320 * v14);
      if ( v24[18] == v4 )
      {
LABEL_10:
        if ( !v12 )
          goto LABEL_26;
        return type_get(v4);
      }
      if ( v12 )
      {
        rf_mode_setup(v24);
        v12 = (v12 & ~0xFFu) | ((uint8_t)(*(volatile uint8_t *)(v4 + 25)) & 0xFFu);
        if ( (uint8_t)v12 )
          return type_get(v4);
      }
      else
      {
        scan_entry_lookup((int)v24);
        v12 = *(volatile uint8_t *)(v4 + 25);
        if ( *(volatile uint8_t *)(v4 + 25) )
          return type_get(v4);
      }
    }
LABEL_26:
    wlan_ioctl_handler_3(dword_128730, (volatile uint32_t *)v4);
    *(volatile uint8_t *)(v4 + 16) = v12;
    v20 = *v1;
    v21 = (uint8_t)(v7[90] - 1);
    v7[90] = v21;
    if ( *v20 < 0 && v21 > 1 )
    {
      irq_disable_mmio_write((int)aChanEnvNbSched, (int)aChanCtxtUnlink, 3210);
      v21 = v7[90];
    }
    if ( v21 )
    {
      clear_stats_buf((volatile uint32_t *)dword_128738);
      v22 = dword_12873C;
      v23 = dword_12873C + 5280;
      do
      {
        *(volatile uint8_t *)(v22 + 85) &= ~1u;
        v22 += 1320;
      }
      while ( v23 != v22 );
      if ( !*((volatile uint32_t *)v7 + 20) )
        llc_env_get();
    }
    if ( *((volatile uint32_t *)v7 + 10) != v4 )
    {
      if ( *((volatile uint32_t *)v7 + 11) != v4 )
        goto LABEL_30;
      v25 = *(volatile uint8_t *)(v4 + 24);
      v26 = v25 + 1;
      if ( v25 == 2 )
      {
        if ( *((volatile uint8_t *)off_12871C + 24) != 255 )
        {
          v26 = 0;
          v27 = 0;
          goto LABEL_57;
        }
        v26 = 1;
      }
      else
      {
        v27 = 8 * v26;
        if ( *((volatile uint8_t *)off_12871C + 28 * v26 + 24) != 255 )
          goto LABEL_57;
        v26 = v25 + 2;
        if ( v25 == 1 )
          v26 = 0;
      }
      v27 = 8 * v26;
      if ( *((volatile uint8_t *)off_12871C + 28 * v26 + 24) == 255 )
      {
        v28 = nullptr;
LABEL_51:
        *((volatile uint32_t *)v7 + 11) = (int)(uintptr_t)(v28);
        alloc_tx_event("unlink replace sw ctxt:%x\n", v28);
        goto LABEL_30;
      }
LABEL_57:
      v28 = (volatile char *)off_12871C + 4 * (v27 - v26);
      goto LABEL_51;
    }
    v15 = v7[90];
    *((volatile uint32_t *)v7 + 10) = 0;
    if ( !v15 || (v16 = *((volatile uint32_t **)v7 + 11)) != nullptr )
    {
LABEL_30:
      if ( !*(volatile uint8_t *)(v4 + 25) )
        goto LABEL_21;
      return type_get(v4);
    }
    alloc_tx_event(aUnlinkSwChan);
    v17 = *(volatile uint8_t *)(v4 + 24);
    v18 = v17 + 1;
    if ( v17 == 2 )
    {
      if ( *((volatile uint8_t *)off_12871C + 24) != 255 )
      {
        v18 = 0;
        goto LABEL_61;
      }
      v18 = 1;
    }
    else
    {
      if ( *((volatile uint8_t *)off_12871C + 28 * v18 + 24) != 255 )
        goto LABEL_61;
      v18 = v17 + 2;
      if ( v17 == 1 )
        v18 = 0;
    }
    if ( *((volatile uint8_t *)off_12871C + 28 * v18 + 24) == 255 )
    {
LABEL_19:
      llc_conn_command((int)(uintptr_t)(v16));
      v12 = *(volatile uint8_t *)(v4 + 25);
      goto LABEL_20;
    }
LABEL_61:
    v16 = (volatile uint32_t *)((volatile char *)off_12871C + 28 * v18);
    goto LABEL_19;
  }
LABEL_20:
  if ( v12 )
    return type_get(v4);
LABEL_21:
  wifi_disable_calc(*(volatile uint8_t *)(v4 + 24));
  return type_get(v4);
}


// bsscfg_index @ 0x128748
/* luna: Attaches a BSS configuration to a channel context, updating reference state and notifying dependent channel and link subsystems. */
int bsscfg_index(int a1, int a2) {
  volatile int16_t **v2; // r10
  int v3; // r8
  int v4; // r7
  volatile uint32_t *chanctx; // r6
  int v8; // r9
  int v9; // r1
  volatile uint8_t *v10; // r11
  int v11; // r3
  int v12; // r2
  volatile uint8_t *bsscfg; // r3
  int v14; // r2
  int v15; // r3
  int v16; // r2
  int result; // r0
  int v18; // r3
  char v19; // r0
  volatile int16_t *v20; // r3
  unsigned int v21; // r2
  int v22; // r3
  int v23; // r3
  int v24; // r1

  v2 = (volatile int16_t **)off_12898C;
  v3 = dword_128968;
  v4 = dword_12895C;
  chanctx = (volatile uint32_t *)(dword_128968 + 28 * a2);
  if ( **(volatile int16_t **)off_12898C >= 0
    || *(volatile uint32_t *)(dword_12895C + 1320 * a1 + 72)
    && (irq_disable_mmio_write((int)aVifChanCtxtNul_0, (int)aChanCtxtLink, 3061), **v2 >= 0) )
  {
    v8 = 8 * a2;
  }
  else
  {
    v8 = 8 * a2;
    if ( *(volatile uint8_t *)(v3 + 28 * a2 + 24) == 255 )
      irq_disable_mmio_write((int)aCtxtIdxChanCtx, (int)aChanCtxtLink, 3062);
  }
  v9 = v3 + 4 * (v8 - a2);
  v10 = (void *)(uintptr_t)(off_128990);
  v11 = v4 + 1320 * a1;
  v12 = (uint8_t)(*(volatile uint8_t *)(v9 + 25) + 1);
  *(volatile uint8_t *)(v9 + 25) = v12;
  *(volatile uint32_t *)(v11 + 72) = (int)(uintptr_t)(chanctx);
  *(volatile uint8_t *)(v11 + 85) = 0;
  if ( v12 == 1 )
  {
    v19 = v10[90];
    *(volatile uint8_t *)(v9 + 16) = 1;
    v20 = *v2;
    v21 = (uint8_t)(v19 + 1);
    v10[90] = v21;
    if ( *v20 < 0 && v21 > 2 )
    {
      irq_disable_mmio_write((int)aChanEnvNbSched_0, (int)aChanCtxtLink, 3082);
      v21 = (uint8_t)v10[90];
    }
    if ( v21 == 2 )
    {
      clear_stats_buf((volatile uint32_t *)dword_128988);
      v23 = dword_12895C;
      v24 = dword_12895C + 5280;
      do
      {
        *(volatile uint8_t *)(v23 + 85) &= ~1u;
        v23 += 1320;
      }
      while ( v24 != v23 );
    }
    co_list_push_back(dword_12897C, chanctx);
    if ( (v10[88] & 0xC) != 0 )
    {
      v22 = *((volatile uint32_t *)v10 + 8);
      if ( **v2 < 0 && !v22 )
      {
        irq_disable_mmio_write((int)aChSwitch, (int)aChanCtxtLink, 3097);
        v22 = 0;
      }
      *(volatile uint32_t *)(v22 + 8) = (int)(uintptr_t)(chanctx);
      v12 = *(volatile uint8_t *)(v3 + 4 * (v8 - a2) + 25);
    }
    else
    {
      if ( *((volatile uint32_t *)v10 + 11) )
        *((volatile uint32_t *)v10 + 11) = (int)(uintptr_t)(chanctx);
      else
        llc_conn_command((int)(uintptr_t)(chanctx));
      v12 = *(volatile uint8_t *)(v3 + 4 * (v8 - a2) + 25);
    }
  }
  check_feature_flag(256, "chan link:%d,%d,%d,%d\r\n", v12, a2, (uint8_t)v10[90], (uint8_t)v10[91]);
  bsscfg = (volatile uint8_t *)(v4 + 1320 * a1);
  v14 = (uint8_t)bsscfg[1224];
  bsscfg[86] = -1;
  if ( v14 && *(volatile uint8_t *)(dword_128964 + 140 * (uint8_t)bsscfg[1225] + 112) == 1 )
  {
    bsscfg[85] |= 0x10u;
  }
  else
  {
    v15 = dword_128968;
    while ( 1 )
    {
      if ( *(volatile uint8_t *)(v15 + 24) != 255 )
      {
        v16 = *(volatile uint8_t *)(v15 + 27);
        if ( v16 != 255 )
          break;
      }
      v15 += 28;
      if ( dword_128968 + 84 == v15 )
        goto LABEL_10;
    }
    if ( *(volatile uint32_t **)(v4 + 1320 * v16 + 72) != chanctx )
      *(volatile uint8_t *)(v4 + 1320 * a1 + 85) |= 0x10u;
  }
LABEL_10:
  result = type_get((int)chanctx);
  v18 = *((volatile uint8_t *)off_12896C + 16);
  if ( v18 != a1 && v18 != 255 )
    return bsscfg_current(a2);
  return result;
}


// bsscfg_current @ 0x128994
int bsscfg_current(int a1) {
  volatile uint8_t *v1; // r6
  int v2; // r4
  volatile uint8_t *v4; // r0

  v1 = (volatile uint8_t *)off_1289E4;
  v2 = dword_1289E8 + 1320 * *((volatile uint8_t *)off_1289E4 + 16);
  if ( *(volatile uint32_t *)(v2 + 72) )
  {
    chan_ctxt_unlink(*((volatile uint8_t *)off_1289E4 + 16));
  }
  else
  {
    v4 = (volatile uint8_t *)tx_send_pdu(5143, 5, 5, 2);
    *v4 = 1;
    v4[1] = *(volatile uint8_t *)(v2 + 107);
    rx_process_packet_1((int)(uintptr_t)(v4));
  }
  return bsscfg_index(v1[16], a1);
}



// log_printf @ 0x1289ec
int log_printf(int a1, int a2, int a3) {
  int v4; // r0
  int v5; // r1
  int v6; // r5
  volatile uint8_t *v7; // r3
  int v8; // r2
  volatile uint32_t *v9; // r0

  if ( (a2 & 0x800000) != 0 )
  {
    if ( a1 )
      *(volatile uint8_t *)(a1 + 115) = 0;
    return 1;
  }
  else
  {
    v4 = (uint8_t)(*(volatile uint8_t *)(a1 + 115) + 1);
    v5 = *(volatile uint32_t *)off_128A88;
    *(volatile uint8_t *)(a1 + 115) = v4;
    if ( *(volatile uint8_t *)(v5 + 1) == v4 )
    {
      *(volatile uint8_t *)(a1 + 115) = 0;
      check_feature_flag(1024, aPsLinkloss, a3);
      rf_read_reg(a1);
      return 1;
    }
    else
    {
      v6 = *(volatile uint8_t *)(a1 + 108);
      if ( *(volatile uint8_t *)(a1 + 108) )
      {
        phy_get_channel(*(volatile uint8_t *)(a1 + 116), a3, a1);
        return 0;
      }
      else
      {
        v7 = (void *)(uintptr_t)(off_128A90);
        v8 = *((volatile uint8_t *)off_128A8C + 2);
        *((volatile uint8_t *)off_128A90 + 28) = 1;
        if ( v8 )
          *(volatile uint32_t *)off_128A94 &= ~0x80000000;
        if ( v7[8] )
          --v7[8];
        v9 = (volatile uint32_t *)dword_128A98;
        v7[29] = 0;
        mem_set_util((int)(uintptr_t)(v9));
        *(volatile uint32_t *)(a1 + 4) &= ~0x200u;
        return v6;
      }
    }
  }
}


// wifi_disable_log @ 0x128aa0
int wifi_disable_log(int a1, int a2) {
  int result; // r0
  volatile uint8_t *v4; // r5
  int v5; // r3

  result = log_printf(a1, a2, (int)off_128AE4);
  if ( result )
  {
    v4 = (void *)(uintptr_t)(off_128AEC);
    v5 = *((volatile uint8_t *)off_128AE8 + 2);
    *((volatile uint8_t *)off_128AEC + 28) = 0;
    if ( v5 )
      *(volatile uint32_t *)off_128AF0 |= 0x80000000;
    if ( v4[8] )
      --v4[8];
    result = mem_set_util(dword_128AF4);
    v4[29] = 0;
    *(volatile uint32_t *)(a1 + 4) &= 0xFFFFFDF9;
  }
  return result;
}



// hex_log @ 0x128af8
int hex_log(int a1, int a2) {
  int result; // r0
  volatile uint8_t *v4; // r3
  int v5; // r2
  int v6; // r2
  int v7; // r1
  int v8; // r0

  result = log_printf(a1, a2, dword_128B44);
  if ( result )
  {
    v4 = (void *)(uintptr_t)(off_128B4C);
    v5 = *((volatile uint8_t *)off_128B48 + 2);
    *((volatile uint8_t *)off_128B4C + 28) = 1;
    if ( v5 )
      *(volatile uint32_t *)off_128B50 &= ~0x80000000;
    if ( v4[8] )
      --v4[8];
    v6 = *((volatile uint32_t *)off_128B58 + 4);
    v7 = *(volatile uint16_t *)(*(volatile uint32_t *)off_128B54 + 54);
    v8 = dword_128B5C;
    *((volatile uint32_t *)v4 + 5) = a1;
    v4[29] = 4;
    result = mm_timer_set((void *)(uintptr_t)(v8), v7 + v6);
    *(volatile uint32_t *)(a1 + 4) |= 0x200u;
  }
  return result;
}



// log_message @ 0x128b60
int log_message(int a1, int a2) {
  int result; // r0
  volatile uint16_t *v5; // r2
  char v6; // r3

  check_feature_flag(2, "%s:%x\r\n", aPsEnableCfm, a2);
  result = log_printf(a1, a2, off_128BA8);
  if ( result )
  {
    v5 = (volatile uint16_t *)off_128BAC;
    if ( !*((volatile uint8_t *)off_128BAC + 8) || (v6 = *((volatile uint8_t *)off_128BAC + 8) - 1, (*((volatile uint8_t *)off_128BAC + 8) = v6) == 0) )
    {
      *(volatile uint8_t *)v5 = 1;
      return mac_write_header_word(50, v5[1], 0);
    }
  }
  return result;
}


// sec_log_dbg @ 0x128bb0
volatile uint16_t * sec_log_dbg(int a1, int a2) {
  volatile uint16_t *result; // r0
  volatile int *i; // r3
  int v6; // r3

  check_feature_flag(2, "%s:%x\r\n", aPsDisableCfm, a2);
  result = (volatile uint16_t *)log_printf(a1, a2, off_128C18);
  if ( result )
  {
    result = (volatile uint16_t *)off_128C1C;
    if ( !*((volatile uint8_t *)off_128C1C + 8)
      || (v6 = (uint8_t)(*((volatile uint8_t *)off_128C1C + 8) - 1), *((volatile uint8_t *)off_128C1C + 8) = v6, !v6) )
    {
      for ( i = *((volatile int **)off_128C20 + 2); i; i = (volatile int *)*i )
      {
        if ( !*((volatile uint8_t *)i + 106) )
        {
          if ( *((volatile uint8_t *)i + 108) )
            i[1] &= 0xFFFFFFF1;
        }
      }
      *(volatile uint8_t *)result = 0;
      return (volatile uint16_t *)mac_write_header_word(50, result[1], 0);
    }
  }
  return result;
}


// mfp_get_state @ 0x128c24
void mfp_get_state() {
  volatile uint8_t *v0; // r5
  int v1; // r4
  void *v2; // r6
  int v3; // r0

  v0 = (void *)(uintptr_t)(off_128C74);
  if ( *(volatile uint8_t *)off_128C74 )
  {
    if ( *((volatile uint8_t *)off_128C74 + 28) )
    {
      v1 = *((volatile uint32_t *)off_128C7C + 2);
      *(volatile uint32_t *)off_128C78 |= 4u;
      v0[8] = 0;
      if ( v1 )
      {
        v2 = (void *)(uintptr_t)(off_128C80);
        do
        {
          if ( !*(volatile uint8_t *)(v1 + 106) )
          {
            if ( *(volatile uint8_t *)(v1 + 108) )
            {
              v3 = *(volatile uint8_t *)(v1 + 116);
              if ( v3 != 255 && !phy_get_channel(v3, (int)v2, v1) )
                ++v0[8];
            }
          }
          v1 = *(volatile uint32_t *)v1;
        }
        while ( v1 );
      }
    }
  }
}



// mfp_check_rsn_cap @ 0x128c84
void mfp_check_rsn_cap(int a1) {
  volatile uint8_t *v1; // r5
  uint64_t v3; // r2
  BOOL v4; // r0
  volatile uint32_t *v5; // r3
  int v6; // r2
  int v7; // r1
  int v8; // r0

  v1 = (void *)(uintptr_t)(off_128D44);
  v3 = (v3 & ~0xFFFFFFFFull) | ((uint32_t)(*((volatile uint32_t *)off_128D48 + 126)) & 0xFFFFFFFFu);
  v3 = (v3 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(*((volatile uint32_t *)off_128D44 + 1) & 0x20) << 32);
  if ( **(volatile uint8_t **)off_128D40 == 1 )
  {
    if ( v3 )
      v4 = 0;
    else
      v4 = get_init_flag() != 0;
  }
  else
  {
    v4 = v3 == 0;
  }
  if ( *(volatile uint8_t *)(a1 + 149) )
  {
    if ( !**(volatile uint8_t **)off_128D4C || !*(volatile uint8_t *)(a1 + 108) )
    {
LABEL_6:
      v1[29] = 0;
      *(volatile uint32_t *)(a1 + 4) = 0;
      return;
    }
LABEL_18:
    v5 = (void *)(uintptr_t)(off_128D58);
    v6 = *(volatile uint32_t *)off_128D54;
    *((volatile uint32_t *)v1 + 5) = a1;
    v7 = *(volatile uint16_t *)(v6 + 54);
    v8 = dword_128D5C;
    v1[29] = 1;
    mm_timer_set((void *)(uintptr_t)(v8), v7 + v5[4]);
    return;
  }
  if ( !**(volatile uint8_t **)off_128D4C || !*(volatile uint8_t *)(a1 + 108) )
    goto LABEL_6;
  if ( !v4 || (*(volatile uint32_t *)off_128D50 & 0x2000000) == 0 && !v1[36] )
    goto LABEL_18;
  if ( v1[29] == 5 )
  {
    *(volatile uint32_t *)(a1 + 4) &= ~2u;
    v1[29] = 0;
  }
  if ( v1[28] )
    mfp_get_state();
  else
    v1[29] = 0;
}



// mfp_get_config @ 0x128d60
void mfp_get_config() {
  volatile uint8_t *v0; // r5
  volatile unsigned int *v1; // r1
  int v2; // r2
  int v3; // r4
  int v4; // r6
  int v5; // r0

  v0 = (void *)(uintptr_t)(off_128DA8);
  if ( !*((volatile uint8_t *)off_128DA8 + 28) )
  {
    v1 = (volatile unsigned int *)off_128DAC;
    v2 = *(volatile uint32_t *)off_128DAC;
    v3 = *((volatile uint32_t *)off_128DB0 + 2);
    *((volatile uint8_t *)off_128DA8 + 8) = 0;
    *v1 = v2 & 0xFFFFFFFB;
    if ( v3 )
    {
      v4 = dword_128DB4;
      do
      {
        if ( !*(volatile uint8_t *)(v3 + 106) )
        {
          if ( *(volatile uint8_t *)(v3 + 108) )
          {
            v5 = *(volatile uint8_t *)(v3 + 116);
            if ( v5 != 255 && !phy_get_channel(v5, v4, v3) )
              ++v0[8];
          }
        }
        v3 = *(volatile uint32_t *)v3;
      }
      while ( v3 );
    }
  }
}



// mfp_key_clear @ 0x128db8
/* luna: Clears the MFP key state, reinitializes its runtime state, and restores its default pointer and flag. */
int mfp_key_clear() {
  volatile uint32_t *key_state; // r4
  volatile int *cleared_state; // r0
  int result; // r0

  key_state = (void *)(uintptr_t)(off_128DD4);
  cleared_state = memset((volatile int *)off_128DD4, 0, 0x28u);
  result = (int)(uintptr_t)(init_runtime_state(cleared_state));
  key_state[4] = off_128DD8;
  *((volatile uint8_t *)key_state + 28) = 1;
  return result;
}



// mfp_key_get_status @ 0x128ddc
int mfp_key_get_status() {
  volatile uint32_t *v0; // r4
  volatile uint32_t *v1; // r3

  v0 = (void *)(uintptr_t)(off_128E10);
  if ( !*(volatile uint8_t *)off_128E10 && !bt_ll_flow_control_check() )
    return 0;
  if ( v0[1] )
    return 0;
  v1 = *((volatile uint32_t **)off_128E14 + 2);
  if ( v1 )
  {
    while ( !v1[1] )
    {
      v1 = (volatile uint32_t *)*v1;
      if ( !v1 )
        return 1;
    }
    return 0;
  }
  return 1;
}



// mfp_key_update @ 0x128e18
int mfp_key_update(int a1, uint16_t a2) {
  volatile uint8_t *v2; // r2
  volatile uint8_t *v3; // r3
  int v4; // zf
  int ( *v5)(int, int); // r3

  v2 = (void *)(uintptr_t)(off_128E40);
  v3 = *(volatile uint8_t **)off_128E3C;
  *((volatile uint16_t *)off_128E40 + 1) = a2;
  v4 = *v3 == 2;
  v5 = (int ( *)(int, int))off_128E44;
  if ( !v4 && a1 )
    v5 = (int ( *)(int, int))off_128E48;
  v2[8] = 0;
  return v5(0, 0x800000);
}


// mfp_key_parse @ 0x128e4c
unsigned int mfp_key_parse(unsigned int result, int a2, int a3) {
  int v3; // r3
  volatile uint32_t *v4; // r7
  int v6; // r2
  int v7; // r12
  unsigned int v8; // r6
  unsigned int v9; // r5
  volatile uint8_t *v10; // r8
  unsigned int v11; // r3
  unsigned int v12; // r3
  unsigned int v13; // r3
  unsigned int v14; // r1
  volatile uint8_t *v15; // r5
  volatile uint32_t *v16; // r3
  int v17; // r3
  int v18; // r1
  int v19; // r0
  volatile uint8_t *v20; // r5
  volatile uint32_t *v21; // r2
  int v22; // r1
  int v23; // r0
  int v24; // r3

  v3 = *(volatile uint8_t *)(a3 + 116);
  v4 = (void *)(uintptr_t)(off_129018);
  v6 = *(volatile uint32_t *)(a3 + 4);
  v7 = *(volatile uint8_t *)off_129018;
  v8 = *(volatile uint16_t *)(dword_129014 + 696 * v3 + 32);
  *(volatile uint32_t *)(a3 + 4) = v6 & 0xFFFFFFFE;
  v9 = result;
  if ( v7 )
  {
    if ( result )
    {
      if ( *(volatile uint8_t *)(a3 + 114) )
      {
        v10 = (volatile uint8_t *)(result + 4);
      }
      else
      {
        v10 = (volatile uint8_t *)(result + 4);
        if ( ((*(volatile uint8_t *)((*(volatile uint8_t *)(a3 + 117) >> 3) + result + 4) >> (*(volatile uint8_t *)(a3 + 117) & 7))
            & 1) != 0 )
        {
          v16 = (void *)(uintptr_t)(off_12901C);
          *(volatile uint32_t *)(a3 + 4) = v6 & 0xFFFFFFFC | 2;
          if ( (*v16 & 0x200) != 0 )
            *v16 &= ~0x200u;
          if ( !*((volatile uint8_t *)v4 + 29) )
          {
            v17 = *((volatile uint32_t *)off_129030 + 4);
            v18 = *(volatile uint16_t *)(*(volatile uint32_t *)off_12902C + 56);
            v19 = dword_129034;
            v4[5] = a3;
            *((volatile uint8_t *)v4 + 29) = 5;
            mm_timer_set((void *)(uintptr_t)(v19), v18 + v17);
          }
        }
        else
        {
          *(volatile uint32_t *)(a3 + 4) = v6 & 0xFFFFFFFC;
        }
      }
      v11 = *v10 & 0xFE;
      result = v8 >> 3;
      if ( v11 <= v8 >> 3
        && result <= *(volatile uint8_t *)(v9 + 1) - 4 + v11
        && (result += v9, (*(volatile uint8_t *)(result - v11 + 5) & (1 << (v8 & 7))) != 0) )
      {
        if ( (*(volatile uint32_t *)off_12901C & 0x200) != 0 )
          *(volatile uint32_t *)off_12901C &= ~0x200u;
        if ( !*(volatile uint8_t *)off_129020 )
        {
          mfp_get_config();
          if ( !*((volatile uint8_t *)v4 + 28) || (*(volatile uint32_t *)off_129028 & 4) != 0 )
          {
            *(volatile uint8_t *)off_129024 = 0;
          }
          else
          {
            v20 = (void *)(uintptr_t)(off_129024);
            if ( *(volatile uint8_t *)off_129024 && (get_rx_pdu() != 1 || !*((volatile uint32_t *)off_129038 + 126)) )
              phy_get_channel(*(volatile uint8_t *)(a3 + 116), 0, 0);
            *v20 = 1;
          }
          v21 = (void *)(uintptr_t)(off_129030);
          v22 = *(volatile uint16_t *)(*(volatile uint32_t *)off_12902C + 58);
          v23 = dword_129034;
          *(volatile uint32_t *)(a3 + 4) |= 4u;
          v24 = v21[4];
          v4[5] = a3;
          *((volatile uint8_t *)v4 + 29) = 6;
          return mm_timer_set((void *)(uintptr_t)(v23), v22 + v24);
        }
      }
      else
      {
        v12 = *(volatile uint32_t *)(a3 + 4) & 0xFFFFFFFB;
        *(volatile uint8_t *)off_129024 = 0;
        *(volatile uint32_t *)(a3 + 4) = v12;
      }
    }
  }
  else if ( result
         && (*(volatile uint32_t *)off_129028 & 4) == 0
         && (v13 = *(volatile uint8_t *)(result + 4) & 0xFE, v14 = v8 >> 3, v13 <= v8 >> 3)
         && v14 <= *(volatile uint8_t *)(result + 1) - 4 + v13
         && (*(volatile uint8_t *)(result + v14 - v13 + 5) & (1 << (v8 & 7))) != 0 )
  {
    v15 = (void *)(uintptr_t)(off_129024);
    if ( *(volatile uint8_t *)off_129024 )
    {
      result = get_rx_pdu();
      if ( result != 1 || !*((volatile uint32_t *)off_129038 + 126) )
        result = phy_get_channel(*(volatile uint8_t *)(a3 + 116), 0, 0);
    }
    *v15 = 1;
  }
  else
  {
    *(volatile uint8_t *)off_129024 = 0;
  }
  return result;
}



// mfp_key_disable @ 0x12903c
int mfp_key_disable(int result, int a2, int a3) {
  volatile uint32_t *v3; // r6
  int v5; // r2
  int v6; // r5
  unsigned int v7; // r3
  int v9; // r1
  int v10; // r3
  int v11; // r1
  volatile uint32_t *v12; // r1
  int v13; // r2
  int v14; // r3
  int v15; // r1

  v3 = (void *)(uintptr_t)(off_1290B8);
  v5 = *(volatile uint32_t *)(a3 + 4);
  v6 = *(volatile uint8_t *)off_1290B8;
  v7 = v5 & 0xFFFFFFFE;
  *(volatile uint32_t *)(a3 + 4) = v5 & 0xFFFFFFFE;
  if ( v6 )
  {
    v9 = *(volatile uint8_t *)(a3 + 114);
    if ( !*(volatile uint8_t *)(a3 + 114) )
    {
      if ( result )
      {
        v12 = (void *)(uintptr_t)(off_1290C0);
        v13 = *(volatile uint32_t *)off_1290BC;
        *(volatile uint32_t *)(a3 + 4) = v7 | 2;
        v14 = v12[4];
        v15 = *(volatile uint16_t *)(v13 + 56);
        v3[5] = a3;
        *((volatile uint8_t *)v3 + 29) = 5;
        result = mm_timer_set((void *)(uintptr_t)((int)(v3 + 3)), v15 + v14);
        v7 = *(volatile uint32_t *)(a3 + 4);
        if ( !a2 )
          goto LABEL_6;
        goto LABEL_8;
      }
      v7 = v5 & 0xFFFFFFFC;
    }
    if ( !a2 )
    {
LABEL_6:
      *(volatile uint32_t *)(a3 + 4) = v7 & 0xFFFFFFFB;
      return result;
    }
LABEL_8:
    *(volatile uint32_t *)(a3 + 4) = v7 | 4;
    process_event(result, v9, v5);
    mfp_get_config();
    v10 = *((volatile uint32_t *)off_1290C0 + 4);
    v11 = *(volatile uint16_t *)(*(volatile uint32_t *)off_1290BC + 58);
    v3[5] = a3;
    *((volatile uint8_t *)v3 + 29) = 6;
    return mm_timer_set((void *)(uintptr_t)(dword_1290C4), v11 + v10);
  }
  return result;
}



// mfp_get_active @ 0x1290c8
void mfp_get_active(volatile uint16_t *a1, int16_t a2, int a3) {
  volatile uint8_t *v3; // r5
  uint16_t v4; // r6
  int v6; // r3
  int v7; // r1
  int v8; // r3
  int v9; // r3
  int v10; // r1

  v3 = (void *)(uintptr_t)(off_129180);
  if ( *(volatile uint8_t *)off_129180 )
  {
    v4 = *a1;
    if ( (a1[2] & 1) != 0 )
    {
      if ( *((volatile uint8_t *)off_129180 + 29) == 5 )
      {
        mem_set_util((int)off_129180 + 12);
        v3[29] = 0;
      }
      if ( (v4 & 0x2000) == 0 || *(volatile uint8_t *)(a3 + 114) )
      {
        *(volatile uint32_t *)(a3 + 4) &= ~2u;
      }
      else
      {
        *(volatile uint32_t *)(a3 + 4) |= 2u;
        if ( !v3[29] )
        {
          v9 = *((volatile uint32_t *)off_12918C + 4);
          v10 = *(volatile uint16_t *)(*(volatile uint32_t *)off_129188 + 56);
          *((volatile uint32_t *)v3 + 5) = a3;
          v3[29] = 5;
          mm_timer_set((void *)(uintptr_t)(dword_129190), v10 + v9);
        }
      }
    }
    else if ( *(volatile uint8_t *)off_129184 )
    {
      adv_type_validate(a3, *a1, a1);
    }
    else if ( (a2 & 0x200) == 0 )
    {
      v6 = *((volatile uint32_t *)off_12918C + 4);
      v7 = *(volatile uint16_t *)(*(volatile uint32_t *)off_129188 + 54);
      *((volatile uint32_t *)off_129180 + 5) = a3;
      v3[29] = 2;
      mm_timer_set((void *)(uintptr_t)((int)(v3 + 12)), v7 + v6);
      v8 = *(volatile uint32_t *)(a3 + 4);
      if ( (v4 & 0x2000) != 0 )
      {
        if ( (v8 & 4) == 0 )
          *(volatile uint32_t *)(a3 + 4) = v8 | 4;
        mfp_get_config();
      }
      else
      {
        *(volatile uint32_t *)(a3 + 4) = v8 & 0xFFFFFFFB;
      }
    }
  }
}



// mfp_is_enabled @ 0x129194
void mfp_is_enabled(int a1) {
  volatile uint8_t *v1; // r2
  int v2; // r3
  int v3; // r3
  int v4; // r1
  int v5; // r0
  volatile uint32_t *v6; // r3

  v1 = (void *)(uintptr_t)(off_12922C);
  if ( *(volatile uint8_t *)off_12922C )
  {
    v2 = *(volatile uint8_t *)(a1 + 29);
    if ( v2 != 255 && *(volatile uint8_t *)(a1 + 27) != 255 )
    {
      v3 = dword_129234 + 1320 * *(volatile uint8_t *)(dword_129230 + 696 * v2 + 34);
      if ( !*(volatile uint8_t *)(v3 + 106) )
      {
        if ( *(volatile uint8_t *)(v3 + 108) )
        {
          v4 = *((volatile uint32_t *)off_12923C + 4);
          v5 = *(volatile uint16_t *)(*(volatile uint32_t *)off_129238 + 54);
          *((volatile uint32_t *)off_12922C + 5) = v3;
          v1[29] = 3;
          mm_timer_set((void *)(uintptr_t)((int)(v1 + 12)), v4 + v5);
          if ( (*(volatile uint32_t *)off_129240 & 4) != 0 )
          {
            if ( *((volatile uint8_t *)off_129244 + 190) )
            {
              if ( **(volatile uint8_t **)off_129248 == 2 )
              {
                v6 = (void *)(uintptr_t)(off_129250);
                *(volatile uint32_t *)off_12924C &= ~0x200u;
                *v6 &= ~1u;
                *v6 &= ~0x80u;
              }
            }
            mfp_get_config();
          }
        }
      }
    }
  }
}



// chip_register_read @ 0x129254
int chip_register_read() {
  volatile unsigned int *v0; // r12
  volatile int *v1; // r1
  volatile int *v2; // r7
  volatile uint32_t *v3; // r4
  unsigned int v4; // r0
  volatile unsigned int *v5; // r5
  volatile uint8_t **v6; // r6
  int result; // r0
  volatile uint8_t *v8; // r2
  int v9; // r3
  volatile uint32_t *v10; // r1
  volatile uint32_t *v11; // r4
  volatile uint32_t *v12; // r2
  volatile uint32_t *v13; // r6
  volatile uint32_t *v14; // r5

  v0 = (volatile unsigned int *)off_129384;
  v1 = (volatile int *)off_129358;
  v2 = (volatile int *)off_12935C;
  v3 = (void *)(uintptr_t)(off_129360);
  v4 = HIWORD(((volatile uint32_t *)(uintptr_t)off_12935C)[46]);
  v5 = (volatile unsigned int *)off_129364;
  v6 = (volatile uint8_t **)off_129368;
  *(volatile uint32_t *)off_129354 |= 0x40000000u;
  *v3 |= 0x10000000u;
  *v0 &= 0xFFF0FFFF;
  *v0 = *v0 & 0xFFFFFF00 | 0x10;
  *v5 = *v5 & 0xFFFFFF03 | 0x10;
  *v1 = *v1 & 0x3FFFFF | (((v4 >> 5) + 32) << 22);
  result = check_feature_flag(2, "%s:%d,%d\r\n", aPsUpmEnter, **v6, (v4 >> 5) + 32);
  v8 = *v6;
  v9 = **v6;
  if ( v9 == 1 )
  {
    if ( *((volatile uint8_t *)v2 + 189) )
    {
      result = (int)off_129374;
      *(volatile uint32_t *)off_129378 &= ~0x2000000u;
      *v5 |= 0x200000u;
      *(volatile uint32_t *)result = 36;
      if ( *v8 != 2 )
        goto LABEL_3;
      goto LABEL_6;
    }
    result = (int)off_129378;
    v13 = (void *)(uintptr_t)(off_129374);
    v14 = (void *)(uintptr_t)(off_129380);
    *(volatile uint32_t *)off_129378 |= 0x2000000u;
    *v13 = 4;
    *v14 = 1;
    *v3 &= 0xFFFBFFFE;
    v9 = *v8;
  }
  if ( v9 != 2 )
  {
LABEL_3:
    *(volatile uint32_t *)off_129374 &= ~0x20u;
    return result;
  }
LABEL_6:
  v10 = (void *)(uintptr_t)(off_129378);
  v11 = (void *)(uintptr_t)(off_129374);
  v12 = (void *)(uintptr_t)(off_129364);
  *(volatile uint32_t *)off_12937C |= 0x10000u;
  *v10 &= ~0x2000000u;
  *v11 = 63;
  *v12 &= ~1u;
  return 63;
}


// chip_register_set_bit @ 0x129388
int chip_register_set_bit() {
  volatile uint32_t *v0; // r0
  volatile uint32_t *v1; // r1
  volatile uint32_t *v2; // r5
  volatile uint32_t *v3; // r2

  *(volatile uint32_t *)off_1293E0 |= 0x2000000u;
  check_feature_flag(2, "%s\r\n", aPsUpmExit);
  if ( !*((volatile uint8_t *)off_1293EC + 18) )
    *(volatile uint32_t *)off_1293F0 &= ~1u;
  v0 = (void *)(uintptr_t)(off_1293F8);
  v1 = (void *)(uintptr_t)(off_1293F0);
  v2 = (void *)(uintptr_t)(off_1293FC);
  v3 = (void *)(uintptr_t)(off_129400);
  *(volatile uint32_t *)off_1293F4 &= ~0x10000u;
  *v0 &= ~0x40000000u;
  *v1 &= ~0x10000000u;
  *v2 = 0;
  *v3 &= ~1u;
  return 0;
}


