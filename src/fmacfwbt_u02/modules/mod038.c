// get_entry_by_index @ 0x1287e0
int get_entry_by_index(int a1) {
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

  v1 = (volatile int16_t **)off_128AA8;
  v2 = dword_128AA0;
  v3 = 1320 * a1;
  v4 = *(volatile uint32_t *)(dword_128AA0 + 1320 * a1 + 72);
  if ( **(volatile int16_t **)off_128AA8 < 0 && !v4 )
    mmio_irq_clear((int)aCtxtNull, (int)aChanCtxtUnlink, 3149);
  v6 = v2 + 1320 * a1;
  v7 = (volatile uint8_t *)off_128A78;
  state_check_feature(
    256,
    "chan unlink: %d,%d,%d,%d,%d\r\n",
    *(volatile uint8_t *)(v4 + 25),
    *((volatile uint8_t *)off_128A78 + 91),
    *((volatile uint8_t *)off_128A78 + 90),
    *(volatile uint8_t *)(v6 + 85),
    *(volatile uint8_t *)(v4 + 16));
  check_abort_flag_3((int)(v7 + 16), (volatile uint32_t *)(v3 + 76 + v2));
  v8 = *(volatile uint8_t *)(v6 + 85);
  *(volatile uint8_t *)(v6 + 85) = v8 & 0xFE;
  if ( (v8 & 2) != 0 )
  {
    v9 = (uint8_t)(v7[91] - 1);
    v7[91] = v9;
    if ( !v9 && (v7[88] & 0x40) != 0 )
    {
      ke_event_schedule_1(aUnlinkFixUntil);
      rf_tx_packet(*((volatile uint32_t *)v7 + 20));
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
      lookup_conn_table(v2 + v3);
      v12 = *(volatile uint8_t *)(v4 + 25);
      *(volatile uint8_t *)(v4 + 27) = -1;
      if ( v12 )
        return remove_entry_by_owner(v4);
    }
    else
    {
      v13 = (volatile uint8_t *)off_128A80;
      while ( 1 )
      {
        if ( v13[24] != 255 )
        {
          v14 = v13[27];
          if ( v14 != 255 )
            break;
        }
        v13 += 28;
        if ( (volatile uint8_t *)((volatile char *)off_128A80 + 84) == v13 )
          goto LABEL_10;
      }
      v24 = (volatile uint32_t *)(v2 + 1320 * v14);
      if ( v24[18] == v4 )
      {
LABEL_10:
        if ( !v12 )
          goto LABEL_26;
        return remove_entry_by_owner(v4);
      }
      if ( v12 )
      {
        scan_state_process(v24);
        v12 = (v12 & ~0xFFu) | ((uint8_t)(*(volatile uint8_t *)(v4 + 25)) & 0xFFu);
        if ( (uint8_t)v12 )
          return remove_entry_by_owner(v4);
      }
      else
      {
        lookup_conn_table((int)v24);
        v12 = *(volatile uint8_t *)(v4 + 25);
        if ( *(volatile uint8_t *)(v4 + 25) )
          return remove_entry_by_owner(v4);
      }
    }
LABEL_26:
    check_abort_flag_3(dword_128A94, (volatile uint32_t *)v4);
    *(volatile uint8_t *)(v4 + 16) = v12;
    v20 = *v1;
    v21 = (uint8_t)(v7[90] - 1);
    v7[90] = v21;
    if ( *v20 < 0 && v21 > 1 )
    {
      mmio_irq_clear((int)aChanEnvNbSched, (int)aChanCtxtUnlink, 3210);
      v21 = v7[90];
    }
    if ( v21 )
    {
      zero_struct((volatile uint32_t *)dword_128A9C);
      v22 = dword_128AA0;
      v23 = dword_128AA0 + 5280;
      do
      {
        *(volatile uint8_t *)(v22 + 85) &= ~1u;
        v22 += 1320;
      }
      while ( v23 != v22 );
      if ( !*((volatile uint32_t *)v7 + 20) )
        hci_acl_buf_alloc();
    }
    if ( *((volatile uint32_t *)v7 + 10) != v4 )
    {
      if ( *((volatile uint32_t *)v7 + 11) != v4 )
        goto LABEL_30;
      v25 = *(volatile uint8_t *)(v4 + 24);
      v26 = v25 + 1;
      if ( v25 == 2 )
      {
        if ( *((volatile uint8_t *)off_128A80 + 24) != 255 )
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
        if ( *((volatile uint8_t *)off_128A80 + 28 * v26 + 24) != 255 )
          goto LABEL_57;
        v26 = v25 + 2;
        if ( v25 == 1 )
          v26 = 0;
      }
      v27 = 8 * v26;
      if ( *((volatile uint8_t *)off_128A80 + 28 * v26 + 24) == 255 )
      {
        v28 = nullptr;
LABEL_51:
        *((volatile uint32_t *)v7 + 11) = (int)(uintptr_t)(v28);
        ke_event_schedule_1("unlink replace sw ctxt:%x\n", v28);
        goto LABEL_30;
      }
LABEL_57:
      v28 = (volatile char *)off_128A80 + 4 * (v27 - v26);
      goto LABEL_51;
    }
    v15 = v7[90];
    *((volatile uint32_t *)v7 + 10) = 0;
    if ( !v15 || (v16 = *((volatile uint32_t **)v7 + 11)) != nullptr )
    {
LABEL_30:
      if ( !*(volatile uint8_t *)(v4 + 25) )
        goto LABEL_21;
      return remove_entry_by_owner(v4);
    }
    ke_event_schedule_1(aUnlinkSwChan);
    v17 = *(volatile uint8_t *)(v4 + 24);
    v18 = v17 + 1;
    if ( v17 == 2 )
    {
      if ( *((volatile uint8_t *)off_128A80 + 24) != 255 )
      {
        v18 = 0;
        goto LABEL_61;
      }
      v18 = 1;
    }
    else
    {
      if ( *((volatile uint8_t *)off_128A80 + 28 * v18 + 24) != 255 )
        goto LABEL_61;
      v18 = v17 + 2;
      if ( v17 == 1 )
        v18 = 0;
    }
    if ( *((volatile uint8_t *)off_128A80 + 28 * v18 + 24) == 255 )
    {
LABEL_19:
      set_tx_buffer((int)(uintptr_t)(v16));
      v12 = *(volatile uint8_t *)(v4 + 25);
      goto LABEL_20;
    }
LABEL_61:
    v16 = (volatile uint32_t *)((volatile char *)off_128A80 + 28 * v18);
    goto LABEL_19;
  }
LABEL_20:
  if ( v12 )
    return remove_entry_by_owner(v4);
LABEL_21:
  lookup_7byte_channel(*(volatile uint8_t *)(v4 + 24));
  return remove_entry_by_owner(v4);
}


// update_entries_from_config @ 0x128aac
int update_entries_from_config(int a1, int a2) {
  volatile int16_t **v2; // r10
  int v3; // r8
  int v4; // r7
  volatile uint32_t *v7; // r6
  int v8; // r9
  int v9; // r1
  volatile uint8_t *v10; // r11
  int v11; // r3
  int v12; // r2
  volatile uint8_t *v13; // r3
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

  v2 = (volatile int16_t **)off_128CF0;
  v3 = dword_128CCC;
  v4 = dword_128CC0;
  v7 = (volatile uint32_t *)(dword_128CCC + 28 * a2);
  if ( **(volatile int16_t **)off_128CF0 >= 0
    || *(volatile uint32_t *)(dword_128CC0 + 1320 * a1 + 72)
    && (mmio_irq_clear((int)aVifChanCtxtNul_0, (int)aChanCtxtLink, 3061), **v2 >= 0) )
  {
    v8 = 8 * a2;
  }
  else
  {
    v8 = 8 * a2;
    if ( *(volatile uint8_t *)(v3 + 28 * a2 + 24) == 255 )
      mmio_irq_clear((int)aCtxtIdxChanCtx, (int)aChanCtxtLink, 3062);
  }
  v9 = v3 + 4 * (v8 - a2);
  v10 = (void *)(uintptr_t)(off_128CF4);
  v11 = v4 + 1320 * a1;
  v12 = (uint8_t)(*(volatile uint8_t *)(v9 + 25) + 1);
  *(volatile uint8_t *)(v9 + 25) = v12;
  *(volatile uint32_t *)(v11 + 72) = (int)(uintptr_t)(v7);
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
      mmio_irq_clear((int)aChanEnvNbSched_0, (int)aChanCtxtLink, 3082);
      v21 = (uint8_t)v10[90];
    }
    if ( v21 == 2 )
    {
      zero_struct((volatile uint32_t *)dword_128CEC);
      v23 = dword_128CC0;
      v24 = dword_128CC0 + 5280;
      do
      {
        *(volatile uint8_t *)(v23 + 85) &= ~1u;
        v23 += 1320;
      }
      while ( v24 != v23 );
    }
    check_abort_flag(dword_128CE0, v7);
    if ( (v10[88] & 0xC) != 0 )
    {
      v22 = *((volatile uint32_t *)v10 + 8);
      if ( **v2 < 0 && !v22 )
      {
        mmio_irq_clear((int)aChSwitch, (int)aChanCtxtLink, 3097);
        v22 = 0;
      }
      *(volatile uint32_t *)(v22 + 8) = (int)(uintptr_t)(v7);
      v12 = *(volatile uint8_t *)(v3 + 4 * (v8 - a2) + 25);
    }
    else
    {
      if ( *((volatile uint32_t *)v10 + 11) )
        *((volatile uint32_t *)v10 + 11) = (int)(uintptr_t)(v7);
      else
        set_tx_buffer((int)(uintptr_t)(v7));
      v12 = *(volatile uint8_t *)(v3 + 4 * (v8 - a2) + 25);
    }
  }
  state_check_feature(256, "chan link:%d,%d,%d,%d\r\n", v12, a2, (uint8_t)v10[90], (uint8_t)v10[91]);
  v13 = (volatile uint8_t *)(v4 + 1320 * a1);
  v14 = (uint8_t)v13[1224];
  v13[86] = -1;
  if ( v14 && *(volatile uint8_t *)(dword_128CC8 + 140 * (uint8_t)v13[1225] + 112) == 1 )
  {
    v13[85] |= 0x10u;
  }
  else
  {
    v15 = dword_128CCC;
    while ( 1 )
    {
      if ( *(volatile uint8_t *)(v15 + 24) != 255 )
      {
        v16 = *(volatile uint8_t *)(v15 + 27);
        if ( v16 != 255 )
          break;
      }
      v15 += 28;
      if ( dword_128CCC + 84 == v15 )
        goto LABEL_10;
    }
    if ( *(volatile uint32_t **)(v4 + 1320 * v16 + 72) != v7 )
      *(volatile uint8_t *)(v4 + 1320 * a1 + 85) |= 0x10u;
  }
LABEL_10:
  result = remove_entry_by_owner((int)v7);
  v18 = *((volatile uint8_t *)off_128CD0 + 16);
  if ( v18 != a1 && v18 != 255 )
    return get_current_entry_owner(a2);
  return result;
}


// get_current_entry_owner @ 0x128cf8
int get_current_entry_owner(int a1) {
  volatile uint8_t *v1; // r6
  int v2; // r4
  volatile uint8_t *v4; // r0

  v1 = (volatile uint8_t *)off_128D48;
  v2 = dword_128D4C + 1320 * *((volatile uint8_t *)off_128D48 + 16);
  if ( *(volatile uint32_t *)(v2 + 72) )
  {
    get_entry_by_index(*((volatile uint8_t *)off_128D48 + 16));
  }
  else
  {
    v4 = (volatile uint8_t *)bt_buf_alloc(5143, 5, 5, 2);
    *v4 = 1;
    v4[1] = *(volatile uint8_t *)(v2 + 107);
    hci_evt_send((int)(uintptr_t)(v4));
  }
  return update_entries_from_config(v1[16], a1);
}



// is_log_enabled @ 0x128d50
int is_log_enabled(int a1, int a2, int a3) {
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
    v5 = *(volatile uint32_t *)off_128DEC;
    *(volatile uint8_t *)(a1 + 115) = v4;
    if ( *(volatile uint8_t *)(v5 + 1) == v4 )
    {
      *(volatile uint8_t *)(a1 + 115) = 0;
      state_check_feature(1024, aPsLinkloss, a3);
      mmio_read_phy(a1);
      return 1;
    }
    else
    {
      v6 = *(volatile uint8_t *)(a1 + 108);
      if ( *(volatile uint8_t *)(a1 + 108) )
      {
        ble_conn_get(*(volatile uint8_t *)(a1 + 116), a3, a1);
        return 0;
      }
      else
      {
        v7 = (void *)(uintptr_t)(off_128DF4);
        v8 = *((volatile uint8_t *)off_128DF0 + 2);
        *((volatile uint8_t *)off_128DF4 + 28) = 1;
        if ( v8 )
          *(volatile uint32_t *)off_128DF8 &= ~0x80000000;
        if ( v7[8] )
          --v7[8];
        v9 = (volatile uint32_t *)dword_128DFC;
        v7[29] = 0;
        ke_event_set_lock((int)(uintptr_t)(v9));
        *(volatile uint32_t *)(a1 + 4) &= ~0x200u;
        return v6;
      }
    }
  }
}


// dump_hex_value @ 0x128e04
int dump_hex_value(int a1, int a2) {
  int result; // r0
  volatile uint8_t *v4; // r5
  int v5; // r3

  result = is_log_enabled(a1, a2, dword_128E48);
  if ( result )
  {
    v4 = (void *)(uintptr_t)(off_128E50);
    v5 = *((volatile uint8_t *)off_128E4C + 2);
    *((volatile uint8_t *)off_128E50 + 28) = 0;
    if ( v5 )
      *(volatile uint32_t *)off_128E54 |= 0x80000000;
    if ( v4[8] )
      --v4[8];
    result = ke_event_set_lock(dword_128E58);
    v4[29] = 0;
    *(volatile uint32_t *)(a1 + 4) &= 0xFFFFFDF9;
  }
  return result;
}



// dump_stats_values @ 0x128e5c
int dump_stats_values(int a1, int a2) {
  int result; // r0
  volatile uint8_t *v4; // r3
  int v5; // r2
  int v6; // r2
  int v7; // r1
  int v8; // r0

  result = is_log_enabled(a1, a2, (int)off_128EA8);
  if ( result )
  {
    v4 = (void *)(uintptr_t)(off_128EB0);
    v5 = *((volatile uint8_t *)off_128EAC + 2);
    *((volatile uint8_t *)off_128EB0 + 28) = 1;
    if ( v5 )
      *(volatile uint32_t *)off_128EB4 &= ~0x80000000;
    if ( v4[8] )
      --v4[8];
    v6 = *((volatile uint32_t *)off_128EBC + 4);
    v7 = *(volatile uint16_t *)(*(volatile uint32_t *)off_128EB8 + 54);
    v8 = dword_128EC0;
    *((volatile uint32_t *)v4 + 5) = a1;
    v4[29] = 4;
    result = ke_event_lock((void *)(uintptr_t)(v8), v7 + v6);
    *(volatile uint32_t *)(a1 + 4) |= 0x200u;
  }
  return result;
}



// log_state_message @ 0x128ec4
int log_state_message(int a1, int a2) {
  int result; // r0
  volatile uint16_t *v5; // r2
  char v6; // r3

  state_check_feature(2, "%s:%x\r\n", aPsEnableCfm, a2);
  result = is_log_enabled(a1, a2, off_128F0C);
  if ( result )
  {
    v5 = (volatile uint16_t *)off_128F10;
    if ( !*((volatile uint8_t *)off_128F10 + 8) || (v6 = *((volatile uint8_t *)off_128F10 + 8) - 1, (*((volatile uint8_t *)off_128F10 + 8) = v6) == 0) )
    {
      *(volatile uint8_t *)v5 = 1;
      return hci_evt_alloc_send(50, v5[1], 0);
    }
  }
  return result;
}


// log_alt_state_message @ 0x128f14
volatile uint16_t * log_alt_state_message(int a1, int a2) {
  volatile uint16_t *result; // r0
  volatile int *i; // r3
  int v6; // r3

  state_check_feature(2, "%s:%x\r\n", aPsDisableCfm, a2);
  result = (volatile uint16_t *)is_log_enabled(a1, a2, off_128F7C);
  if ( result )
  {
    result = (volatile uint16_t *)off_128F80;
    if ( !*((volatile uint8_t *)off_128F80 + 8)
      || (v6 = (uint8_t)(*((volatile uint8_t *)off_128F80 + 8) - 1), *((volatile uint8_t *)off_128F80 + 8) = v6, !v6) )
    {
      for ( i = *((volatile int **)off_128F84 + 2); i; i = (volatile int *)*i )
      {
        if ( !*((volatile uint8_t *)i + 106) )
        {
          if ( *((volatile uint8_t *)i + 108) )
            i[1] &= 0xFFFFFFF1;
        }
      }
      *(volatile uint8_t *)result = 0;
      return (volatile uint16_t *)hci_evt_alloc_send(50, result[1], 0);
    }
  }
  return result;
}


// handle_mmio_event @ 0x128f88
void handle_mmio_event() {
  volatile uint8_t *v0; // r5
  int v1; // r4
  int v2; // r6
  int v3; // r0

  v0 = (void *)(uintptr_t)(off_128FD8);
  if ( *(volatile uint8_t *)off_128FD8 )
  {
    if ( *((volatile uint8_t *)off_128FD8 + 28) )
    {
      v1 = *((volatile uint32_t *)off_128FE0 + 2);
      *(volatile uint32_t *)off_128FDC |= 4u;
      v0[8] = 0;
      if ( v1 )
      {
        v2 = dword_128FE4;
        do
        {
          if ( !*(volatile uint8_t *)(v1 + 106) )
          {
            if ( *(volatile uint8_t *)(v1 + 108) )
            {
              v3 = *(volatile uint8_t *)(v1 + 116);
              if ( v3 != 255 && !ble_conn_get(v3, v2, v1) )
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



// efuse_check @ 0x128fe8
void efuse_check(int a1) {
  volatile uint8_t *v1; // r5
  uint64_t v3; // r2
  BOOL v4; // r0
  volatile uint32_t *v5; // r3
  int v6; // r2
  int v7; // r1
  int v8; // r0

  v1 = (void *)(uintptr_t)(off_1290A8);
  v3 = (v3 & ~0xFFFFFFFFull) | ((uint32_t)(*((volatile uint32_t *)off_1290AC + 126)) & 0xFFFFFFFFu);
  v3 = (v3 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(*((volatile uint32_t *)off_1290A8 + 1) & 0x20) << 32);
  if ( **(volatile uint8_t **)off_1290A4 == 1 )
  {
    if ( v3 )
      v4 = 0;
    else
      v4 = ll_util_get_state() != 0;
  }
  else
  {
    v4 = v3 == 0;
  }
  if ( *(volatile uint8_t *)(a1 + 149) )
  {
    if ( !**(volatile uint8_t **)off_1290B0 || !*(volatile uint8_t *)(a1 + 108) )
    {
LABEL_6:
      v1[29] = 0;
      *(volatile uint32_t *)(a1 + 4) = 0;
      return;
    }
LABEL_18:
    v5 = (void *)(uintptr_t)(off_1290BC);
    v6 = *(volatile uint32_t *)off_1290B8;
    *((volatile uint32_t *)v1 + 5) = a1;
    v7 = *(volatile uint16_t *)(v6 + 54);
    v8 = dword_1290C0;
    v1[29] = 1;
    ke_event_lock((void *)(uintptr_t)(v8), v7 + v5[4]);
    return;
  }
  if ( !**(volatile uint8_t **)off_1290B0 || !*(volatile uint8_t *)(a1 + 108) )
    goto LABEL_6;
  if ( !v4 || (*(volatile uint32_t *)off_1290B4 & 0x2000000) == 0 && !v1[36] )
    goto LABEL_18;
  if ( v1[29] == 5 )
  {
    *(volatile uint32_t *)(a1 + 4) &= ~2u;
    v1[29] = 0;
  }
  if ( v1[28] )
    handle_mmio_event();
  else
    v1[29] = 0;
}



// mm_beacon_irq @ 0x1290c4
void mm_beacon_irq() {
  volatile uint8_t *v0; // r5
  volatile unsigned int *v1; // r1
  int v2; // r2
  int v3; // r4
  void *v4; // r6
  int v5; // r0

  v0 = (void *)(uintptr_t)(off_12910C);
  if ( !*((volatile uint8_t *)off_12910C + 28) )
  {
    v1 = (volatile unsigned int *)off_129110;
    v2 = *(volatile uint32_t *)off_129110;
    v3 = *((volatile uint32_t *)off_129114 + 2);
    *((volatile uint8_t *)off_12910C + 8) = 0;
    *v1 = v2 & 0xFFFFFFFB;
    if ( v3 )
    {
      v4 = (void *)(uintptr_t)(off_129118);
      do
      {
        if ( !*(volatile uint8_t *)(v3 + 106) )
        {
          if ( *(volatile uint8_t *)(v3 + 108) )
          {
            v5 = *(volatile uint8_t *)(v3 + 116);
            if ( v5 != 255 && !ble_conn_get(v5, (int)v4, v3) )
              ++v0[8];
          }
        }
        v3 = *(volatile uint32_t *)v3;
      }
      while ( v3 );
    }
  }
}



// mm_state_idle @ 0x12911c
int mm_state_idle() {
  volatile uint32_t *v0; // r4
  volatile int *v1; // r0
  int result; // r0

  v0 = (void *)(uintptr_t)(off_129138);
  v1 = memset((volatile int *)off_129138, 0, 0x28u);
  result = (int)(uintptr_t)(mac_init_ring(v1));
  v0[4] = dword_12913C;
  *((volatile uint8_t *)v0 + 28) = 1;
  return result;
}



// mm_state_run @ 0x129140
int mm_state_run() {
  volatile uint32_t *v0; // r4
  volatile uint32_t *v1; // r3

  v0 = (void *)(uintptr_t)(off_129174);
  if ( !*(volatile uint8_t *)off_129174 && !bt_scan_get_state() )
    return 0;
  if ( v0[1] )
    return 0;
  v1 = *((volatile uint32_t **)off_129178 + 2);
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



// ipc_msg_send @ 0x12917c
int ipc_msg_send(int a1, uint16_t a2) {
  volatile uint8_t *v2; // r2
  volatile uint8_t *v3; // r3
  int v4; // zf
  int ( *v5)(int, int); // r3

  v2 = (void *)(uintptr_t)(off_1291A4);
  v3 = *(volatile uint8_t **)off_1291A0;
  *((volatile uint16_t *)off_1291A4 + 1) = a2;
  v4 = *v3 == 2;
  v5 = (int ( *)(int, int))off_1291A8;
  if ( !v4 && a1 )
    v5 = (int ( *)(int, int))off_1291AC;
  v2[8] = 0;
  return v5(0, 0x800000);
}


// ipc_msg_receive @ 0x1291b0
unsigned int ipc_msg_receive(unsigned int result, int a2, int a3) {
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
  v4 = (void *)(uintptr_t)(off_12937C);
  v6 = *(volatile uint32_t *)(a3 + 4);
  v7 = *(volatile uint8_t *)off_12937C;
  v8 = *(volatile uint16_t *)(dword_129378 + 696 * v3 + 32);
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
          v16 = (void *)(uintptr_t)(off_129380);
          *(volatile uint32_t *)(a3 + 4) = v6 & 0xFFFFFFFC | 2;
          if ( (*v16 & 0x200) != 0 )
            *v16 &= ~0x200u;
          if ( !*((volatile uint8_t *)v4 + 29) )
          {
            v17 = *((volatile uint32_t *)off_129394 + 4);
            v18 = *(volatile uint16_t *)(*(volatile uint32_t *)off_129390 + 56);
            v19 = dword_129398;
            v4[5] = a3;
            *((volatile uint8_t *)v4 + 29) = 5;
            ke_event_lock((void *)(uintptr_t)(v19), v18 + v17);
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
        if ( (*(volatile uint32_t *)off_129380 & 0x200) != 0 )
          *(volatile uint32_t *)off_129380 &= ~0x200u;
        if ( !*(volatile uint8_t *)off_129384 )
        {
          mm_beacon_irq();
          if ( !*((volatile uint8_t *)v4 + 28) || (*(volatile uint32_t *)off_12938C & 4) != 0 )
          {
            *(volatile uint8_t *)off_129388 = 0;
          }
          else
          {
            v20 = (void *)(uintptr_t)(off_129388);
            if ( *(volatile uint8_t *)off_129388 && (find_pending_command() != 1 || !*((volatile uint32_t *)off_12939C + 126)) )
              ble_conn_get(*(volatile uint8_t *)(a3 + 116), 0, 0);
            *v20 = 1;
          }
          v21 = (void *)(uintptr_t)(off_129394);
          v22 = *(volatile uint16_t *)(*(volatile uint32_t *)off_129390 + 58);
          v23 = dword_129398;
          *(volatile uint32_t *)(a3 + 4) |= 4u;
          v24 = v21[4];
          v4[5] = a3;
          *((volatile uint8_t *)v4 + 29) = 6;
          return ke_event_lock((void *)(uintptr_t)(v23), v22 + v24);
        }
      }
      else
      {
        v12 = *(volatile uint32_t *)(a3 + 4) & 0xFFFFFFFB;
        *(volatile uint8_t *)off_129388 = 0;
        *(volatile uint32_t *)(a3 + 4) = v12;
      }
    }
  }
  else if ( result
         && (*(volatile uint32_t *)off_12938C & 4) == 0
         && (v13 = *(volatile uint8_t *)(result + 4) & 0xFE, v14 = v8 >> 3, v13 <= v8 >> 3)
         && v14 <= *(volatile uint8_t *)(result + 1) - 4 + v13
         && (*(volatile uint8_t *)(result + v14 - v13 + 5) & (1 << (v8 & 7))) != 0 )
  {
    v15 = (void *)(uintptr_t)(off_129388);
    if ( *(volatile uint8_t *)off_129388 )
    {
      result = find_pending_command();
      if ( result != 1 || !*((volatile uint32_t *)off_12939C + 126) )
        result = ble_conn_get(*(volatile uint8_t *)(a3 + 116), 0, 0);
    }
    *v15 = 1;
  }
  else
  {
    *(volatile uint8_t *)off_129388 = 0;
  }
  return result;
}



// rf_rx_packet_get @ 0x1293a0
int rf_rx_packet_get(int result, int a2, int a3) {
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

  v3 = (void *)(uintptr_t)(off_12941C);
  v5 = *(volatile uint32_t *)(a3 + 4);
  v6 = *(volatile uint8_t *)off_12941C;
  v7 = v5 & 0xFFFFFFFE;
  *(volatile uint32_t *)(a3 + 4) = v5 & 0xFFFFFFFE;
  if ( v6 )
  {
    v9 = *(volatile uint8_t *)(a3 + 114);
    if ( !*(volatile uint8_t *)(a3 + 114) )
    {
      if ( result )
      {
        v12 = (void *)(uintptr_t)(off_129424);
        v13 = *(volatile uint32_t *)off_129420;
        *(volatile uint32_t *)(a3 + 4) = v7 | 2;
        v14 = v12[4];
        v15 = *(volatile uint16_t *)(v13 + 56);
        v3[5] = a3;
        *((volatile uint8_t *)v3 + 29) = 5;
        result = ke_event_lock((void *)(uintptr_t)((int)(v3 + 3)), v15 + v14);
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
    log_and_check_hw(result, v9, v5);
    mm_beacon_irq();
    v10 = *((volatile uint32_t *)off_129424 + 4);
    v11 = *(volatile uint16_t *)(*(volatile uint32_t *)off_129420 + 58);
    v3[5] = a3;
    *((volatile uint8_t *)v3 + 29) = 6;
    return ke_event_lock((void *)(uintptr_t)(dword_129428), v11 + v10);
  }
  return result;
}



// rf_tx_power_configure @ 0x12942c
void rf_tx_power_configure(volatile uint16_t *a1, int16_t a2, int a3) {
  volatile uint8_t *v3; // r5
  uint16_t v4; // r6
  int v6; // r3
  int v7; // r1
  int v8; // r3
  int v9; // r3
  int v10; // r1

  v3 = (void *)(uintptr_t)(off_1294E4);
  if ( *(volatile uint8_t *)off_1294E4 )
  {
    v4 = *a1;
    if ( (a1[2] & 1) != 0 )
    {
      if ( *((volatile uint8_t *)off_1294E4 + 29) == 5 )
      {
        ke_event_set_lock((int)off_1294E4 + 12);
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
          v9 = *((volatile uint32_t *)off_1294F0 + 4);
          v10 = *(volatile uint16_t *)(*(volatile uint32_t *)off_1294EC + 56);
          *((volatile uint32_t *)v3 + 5) = a3;
          v3[29] = 5;
          ke_event_lock((void *)(uintptr_t)(dword_1294F4), v10 + v9);
        }
      }
    }
    else if ( *(volatile uint8_t *)off_1294E8 )
    {
      check_phy_flags(a3, *a1, a1);
    }
    else if ( (a2 & 0x200) == 0 )
    {
      v6 = *((volatile uint32_t *)off_1294F0 + 4);
      v7 = *(volatile uint16_t *)(*(volatile uint32_t *)off_1294EC + 54);
      *((volatile uint32_t *)off_1294E4 + 5) = a3;
      v3[29] = 2;
      ke_event_lock((void *)(uintptr_t)((int)(v3 + 12)), v7 + v6);
      v8 = *(volatile uint32_t *)(a3 + 4);
      if ( (v4 & 0x2000) != 0 )
      {
        if ( (v8 & 4) == 0 )
          *(volatile uint32_t *)(a3 + 4) = v8 | 4;
        mm_beacon_irq();
      }
      else
      {
        *(volatile uint32_t *)(a3 + 4) = v8 & 0xFFFFFFFB;
      }
    }
  }
}



// rf_isr_1 @ 0x1294f8
void rf_isr_1(int a1) {
  volatile uint8_t *v1; // r2
  int v2; // r3
  int v3; // r3
  int v4; // r1
  int v5; // r0
  volatile uint32_t *v6; // r3

  v1 = (void *)(uintptr_t)(off_129590);
  if ( *(volatile uint8_t *)off_129590 )
  {
    v2 = *(volatile uint8_t *)(a1 + 29);
    if ( v2 != 255 && *(volatile uint8_t *)(a1 + 27) != 255 )
    {
      v3 = dword_129598 + 1320 * *(volatile uint8_t *)(dword_129594 + 696 * v2 + 34);
      if ( !*(volatile uint8_t *)(v3 + 106) )
      {
        if ( *(volatile uint8_t *)(v3 + 108) )
        {
          v4 = *((volatile uint32_t *)off_1295A0 + 4);
          v5 = *(volatile uint16_t *)(*(volatile uint32_t *)off_12959C + 54);
          *((volatile uint32_t *)off_129590 + 5) = v3;
          v1[29] = 3;
          ke_event_lock((void *)(uintptr_t)((int)(v1 + 12)), v4 + v5);
          if ( (*(volatile uint32_t *)off_1295A4 & 4) != 0 )
          {
            if ( *((volatile uint8_t *)off_1295A8 + 190) )
            {
              if ( **(volatile uint8_t **)off_1295AC == 2 )
              {
                v6 = (void *)(uintptr_t)(off_1295B4);
                *(volatile uint32_t *)off_1295B0 &= ~0x200u;
                *v6 &= ~1u;
                *v6 &= ~0x80u;
              }
            }
            mm_beacon_irq();
          }
        }
      }
    }
  }
}



// ke_evt_wait @ 0x1295b8
int ke_evt_wait() {
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

  v0 = (volatile unsigned int *)off_1296E8;
  v1 = (volatile int *)off_1296BC;
  v2 = (volatile int *)off_1296C0;
  v3 = (void *)(uintptr_t)(off_1296C4);
  v4 = HIWORD(((volatile uint32_t *)(uintptr_t)off_1296C0)[46]);
  v5 = (volatile unsigned int *)off_1296C8;
  v6 = (volatile uint8_t **)off_1296CC;
  *(volatile uint32_t *)off_1296B8 |= 0x40000000u;
  *v3 |= 0x10000000u;
  *v0 &= 0xFFF0FFFF;
  *v0 = *v0 & 0xFFFFFF00 | 0x10;
  *v5 = *v5 & 0xFFFFFF03 | 0x10;
  *v1 = *v1 & 0x3FFFFF | (((v4 >> 5) + 32) << 22);
  result = state_check_feature(2, "%s:%d,%d\r\n", aPsUpmEnter, **v6, (v4 >> 5) + 32);
  v8 = *v6;
  v9 = **v6;
  if ( v9 == 1 )
  {
    if ( *((volatile uint8_t *)v2 + 189) )
    {
      result = (int)off_1296D8;
      *(volatile uint32_t *)off_1296DC &= ~0x2000000u;
      *v5 |= 0x200000u;
      *(volatile uint32_t *)result = 36;
      if ( *v8 != 2 )
        goto LABEL_3;
      goto LABEL_6;
    }
    result = (int)off_1296DC;
    v13 = (void *)(uintptr_t)(off_1296D8);
    v14 = (void *)(uintptr_t)(off_1296E4);
    *(volatile uint32_t *)off_1296DC |= 0x2000000u;
    *v13 = 4;
    *v14 = 1;
    *v3 &= 0xFFFBFFFE;
    v9 = *v8;
  }
  if ( v9 != 2 )
  {
LABEL_3:
    *(volatile uint32_t *)off_1296D8 &= ~0x20u;
    return result;
  }
LABEL_6:
  v10 = (void *)(uintptr_t)(off_1296DC);
  v11 = (void *)(uintptr_t)(off_1296D8);
  v12 = (void *)(uintptr_t)(off_1296C8);
  *(volatile uint32_t *)off_1296E0 |= 0x10000u;
  *v10 &= ~0x2000000u;
  *v11 = 63;
  *v12 &= ~1u;
  return 63;
}


// set_reg_bit @ 0x1296ec
int set_reg_bit() {
  volatile uint32_t *v0; // r0
  volatile uint32_t *v1; // r1
  volatile uint32_t *v2; // r5
  volatile uint32_t *v3; // r2

  *(volatile uint32_t *)off_129744 |= 0x2000000u;
  state_check_feature(2, "%s\r\n", aPsUpmExit);
  if ( !*((volatile uint8_t *)off_129750 + 18) )
    *(volatile uint32_t *)off_129754 &= ~1u;
  v0 = (void *)(uintptr_t)(off_12975C);
  v1 = (void *)(uintptr_t)(off_129754);
  v2 = (void *)(uintptr_t)(off_129760);
  v3 = (void *)(uintptr_t)(off_129764);
  *(volatile uint32_t *)off_129758 &= ~0x10000u;
  *v0 &= ~0x40000000u;
  *v1 &= ~0x10000000u;
  *v2 = 0;
  *v3 &= ~1u;
  return 0;
}


