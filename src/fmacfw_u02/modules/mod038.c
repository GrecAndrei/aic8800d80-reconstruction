// sta_get_by_index @ 0x1285bc
int sta_get_by_index(int a1) {
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

  v1 = (volatile int16_t **)off_128884;
  v2 = dword_12887C;
  v3 = 1320 * a1;
  v4 = *(volatile uint32_t *)(dword_12887C + 1320 * a1 + 72);
  if ( **(volatile int16_t **)off_128884 < 0 && !v4 )
    mmio_clear_register((int)aCtxtNull, (int)aChanCtxtUnlink, 3149);
  v6 = v2 + 1320 * a1;
  v7 = (volatile uint8_t *)off_128854;
  check_status_bits(
    256,
    "chan unlink: %d,%d,%d,%d,%d\r\n",
    *(volatile uint8_t *)(v4 + 25),
    *((volatile uint8_t *)off_128854 + 91),
    *((volatile uint8_t *)off_128854 + 90),
    *(volatile uint8_t *)(v6 + 85),
    *(volatile uint8_t *)(v4 + 16));
  cmd_handler_c((int)(v7 + 16), (volatile uint32_t *)(v3 + 76 + v2));
  v8 = *(volatile uint8_t *)(v6 + 85);
  *(volatile uint8_t *)(v6 + 85) = v8 & 0xFE;
  if ( (v8 & 2) != 0 )
  {
    v9 = (uint8_t)(v7[91] - 1);
    v7[91] = v9;
    if ( !v9 && (v7[88] & 0x40) != 0 )
    {
      event_dispatch(aUnlinkFixUntil);
      dma_setup_transfer(*((volatile uint32_t *)v7 + 20));
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
      lld_evt_update(v2 + v3);
      v12 = *(volatile uint8_t *)(v4 + 25);
      *(volatile uint8_t *)(v4 + 27) = -1;
      if ( v12 )
        return get_control_byte(v4);
    }
    else
    {
      v13 = (volatile uint8_t *)off_12885C;
      while ( 1 )
      {
        if ( v13[24] != 255 )
        {
          v14 = v13[27];
          if ( v14 != 255 )
            break;
        }
        v13 += 28;
        if ( (volatile uint8_t *)((volatile char *)off_12885C + 84) == v13 )
          goto LABEL_10;
      }
      v24 = (volatile uint32_t *)(v2 + 1320 * v14);
      if ( v24[18] == v4 )
      {
LABEL_10:
        if ( !v12 )
          goto LABEL_26;
        return get_control_byte(v4);
      }
      if ( v12 )
      {
        lld_evt_schedule(v24);
        v12 = (v12 & ~0xFFu) | ((uint8_t)(*(volatile uint8_t *)(v4 + 25)) & 0xFFu);
        if ( (uint8_t)v12 )
          return get_control_byte(v4);
      }
      else
      {
        lld_evt_update((int)v24);
        v12 = *(volatile uint8_t *)(v4 + 25);
        if ( *(volatile uint8_t *)(v4 + 25) )
          return get_control_byte(v4);
      }
    }
LABEL_26:
    cmd_handler_c(dword_128870, (volatile uint32_t *)v4);
    *(volatile uint8_t *)(v4 + 16) = v12;
    v20 = *v1;
    v21 = (uint8_t)(v7[90] - 1);
    v7[90] = v21;
    if ( *v20 < 0 && v21 > 1 )
    {
      mmio_clear_register((int)aChanEnvNbSched, (int)aChanCtxtUnlink, 3210);
      v21 = v7[90];
    }
    if ( v21 )
    {
      zero_8_bytes((volatile uint32_t *)dword_128878);
      v22 = dword_12887C;
      v23 = dword_12887C + 5280;
      do
      {
        *(volatile uint8_t *)(v22 + 85) &= ~1u;
        v22 += 1320;
      }
      while ( v23 != v22 );
      if ( !*((volatile uint32_t *)v7 + 20) )
        ke_task_poll();
    }
    if ( *((volatile uint32_t *)v7 + 10) != v4 )
    {
      if ( *((volatile uint32_t *)v7 + 11) != v4 )
        goto LABEL_30;
      v25 = *(volatile uint8_t *)(v4 + 24);
      v26 = v25 + 1;
      if ( v25 == 2 )
      {
        if ( *((volatile uint8_t *)off_12885C + 24) != 255 )
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
        if ( *((volatile uint8_t *)off_12885C + 28 * v26 + 24) != 255 )
          goto LABEL_57;
        v26 = v25 + 2;
        if ( v25 == 1 )
          v26 = 0;
      }
      v27 = 8 * v26;
      if ( *((volatile uint8_t *)off_12885C + 28 * v26 + 24) == 255 )
      {
        v28 = nullptr;
LABEL_51:
        *((volatile uint32_t *)v7 + 11) = (int)(uintptr_t)(v28);
        event_dispatch("unlink replace sw ctxt:%x\n", v28);
        goto LABEL_30;
      }
LABEL_57:
      v28 = (volatile char *)off_12885C + 4 * (v27 - v26);
      goto LABEL_51;
    }
    v15 = v7[90];
    *((volatile uint32_t *)v7 + 10) = 0;
    if ( !v15 || (v16 = *((volatile uint32_t **)v7 + 11)) != nullptr )
    {
LABEL_30:
      if ( !*(volatile uint8_t *)(v4 + 25) )
        goto LABEL_21;
      return get_control_byte(v4);
    }
    event_dispatch(aUnlinkSwChan);
    v17 = *(volatile uint8_t *)(v4 + 24);
    v18 = v17 + 1;
    if ( v17 == 2 )
    {
      if ( *((volatile uint8_t *)off_12885C + 24) != 255 )
      {
        v18 = 0;
        goto LABEL_61;
      }
      v18 = 1;
    }
    else
    {
      if ( *((volatile uint8_t *)off_12885C + 28 * v18 + 24) != 255 )
        goto LABEL_61;
      v18 = v17 + 2;
      if ( v17 == 1 )
        v18 = 0;
    }
    if ( *((volatile uint8_t *)off_12885C + 28 * v18 + 24) == 255 )
    {
LABEL_19:
      ctrl_register_handler((int)(uintptr_t)(v16));
      v12 = *(volatile uint8_t *)(v4 + 25);
      goto LABEL_20;
    }
LABEL_61:
    v16 = (volatile uint32_t *)((volatile char *)off_12885C + 28 * v18);
    goto LABEL_19;
  }
LABEL_20:
  if ( v12 )
    return get_control_byte(v4);
LABEL_21:
  wlc_validate_chip_queue(*(volatile uint8_t *)(v4 + 24));
  return get_control_byte(v4);
}


// sta_lookup_by_bss @ 0x128888
int sta_lookup_by_bss(int a1, int a2) {
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

  v2 = (volatile int16_t **)off_128ACC;
  v3 = dword_128AA8;
  v4 = dword_128A9C;
  v7 = (volatile uint32_t *)(dword_128AA8 + 28 * a2);
  if ( **(volatile int16_t **)off_128ACC >= 0
    || *(volatile uint32_t *)(dword_128A9C + 1320 * a1 + 72)
    && (mmio_clear_register((int)aVifChanCtxtNul_0, (int)aChanCtxtLink, 3061), **v2 >= 0) )
  {
    v8 = 8 * a2;
  }
  else
  {
    v8 = 8 * a2;
    if ( *(volatile uint8_t *)(v3 + 28 * a2 + 24) == 255 )
      mmio_clear_register((int)aCtxtIdxChanCtx, (int)aChanCtxtLink, 3062);
  }
  v9 = v3 + 4 * (v8 - a2);
  v10 = (void *)(uintptr_t)(off_128AD0);
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
      mmio_clear_register((int)aChanEnvNbSched_0, (int)aChanCtxtLink, 3082);
      v21 = (uint8_t)v10[90];
    }
    if ( v21 == 2 )
    {
      zero_8_bytes((volatile uint32_t *)dword_128AC8);
      v23 = dword_128A9C;
      v24 = dword_128A9C + 5280;
      do
      {
        *(volatile uint8_t *)(v23 + 85) &= ~1u;
        v23 += 1320;
      }
      while ( v24 != v23 );
    }
    co_list_push_back(dword_128ABC, v7);
    if ( (v10[88] & 0xC) != 0 )
    {
      v22 = *((volatile uint32_t *)v10 + 8);
      if ( **v2 < 0 && !v22 )
      {
        mmio_clear_register((int)aChSwitch, (int)aChanCtxtLink, 3097);
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
        ctrl_register_handler((int)(uintptr_t)(v7));
      v12 = *(volatile uint8_t *)(v3 + 4 * (v8 - a2) + 25);
    }
  }
  check_status_bits(256, "chan link:%d,%d,%d,%d\r\n", v12, a2, (uint8_t)v10[90], (uint8_t)v10[91]);
  v13 = (volatile uint8_t *)(v4 + 1320 * a1);
  v14 = (uint8_t)v13[1224];
  v13[86] = -1;
  if ( v14 && *(volatile uint8_t *)(dword_128AA4 + 140 * (uint8_t)v13[1225] + 112) == 1 )
  {
    v13[85] |= 0x10u;
  }
  else
  {
    v15 = dword_128AA8;
    while ( 1 )
    {
      if ( *(volatile uint8_t *)(v15 + 24) != 255 )
      {
        v16 = *(volatile uint8_t *)(v15 + 27);
        if ( v16 != 255 )
          break;
      }
      v15 += 28;
      if ( dword_128AA8 + 84 == v15 )
        goto LABEL_10;
    }
    if ( *(volatile uint32_t **)(v4 + 1320 * v16 + 72) != v7 )
      *(volatile uint8_t *)(v4 + 1320 * a1 + 85) |= 0x10u;
  }
LABEL_10:
  result = get_control_byte((int)v7);
  v18 = *((volatile uint8_t *)off_128AAC + 16);
  if ( v18 != a1 && v18 != 255 )
    return sta_get_current(a2);
  return result;
}


// sta_get_current @ 0x128ad4
int sta_get_current(int a1) {
  volatile uint8_t *v1; // r6
  int v2; // r4
  volatile uint8_t *v4; // r0

  v1 = (volatile uint8_t *)off_128B24;
  v2 = dword_128B28 + 1320 * *((volatile uint8_t *)off_128B24 + 16);
  if ( *(volatile uint32_t *)(v2 + 72) )
  {
    sta_get_by_index(*((volatile uint8_t *)off_128B24 + 16));
  }
  else
  {
    v4 = (volatile uint8_t *)ke_msg_alloc(5143, 5, 5, 2);
    *v4 = 1;
    v4[1] = *(volatile uint8_t *)(v2 + 107);
    ke_msg_send_2((int)(uintptr_t)(v4));
  }
  return sta_lookup_by_bss(v1[16], a1);
}



// wlc_check_rate_flag @ 0x128b2c
int wlc_check_rate_flag(int a1, int a2, int a3) {
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
    v5 = *(volatile uint32_t *)off_128BC8;
    *(volatile uint8_t *)(a1 + 115) = v4;
    if ( *(volatile uint8_t *)(v5 + 1) == v4 )
    {
      *(volatile uint8_t *)(a1 + 115) = 0;
      check_status_bits(1024, aPsLinkloss, a3);
      send_fw_cmd(a1);
      return 1;
    }
    else
    {
      v6 = *(volatile uint8_t *)(a1 + 108);
      if ( *(volatile uint8_t *)(a1 + 108) )
      {
        rf_channel_get(*(volatile uint8_t *)(a1 + 116), a3, a1);
        return 0;
      }
      else
      {
        v7 = (void *)(uintptr_t)(off_128BD0);
        v8 = *((volatile uint8_t *)off_128BCC + 2);
        *((volatile uint8_t *)off_128BD0 + 28) = 1;
        if ( v8 )
          *(volatile uint32_t *)off_128BD4 &= ~0x80000000;
        if ( v7[8] )
          --v7[8];
        v9 = (volatile uint32_t *)dword_128BD8;
        v7[29] = 0;
        fault_handler((int)(uintptr_t)(v9));
        *(volatile uint32_t *)(a1 + 4) &= ~0x200u;
        return v6;
      }
    }
  }
}


// wlc_print_hex @ 0x128be0
int wlc_print_hex(int a1, int a2) {
  int result; // r0
  volatile uint8_t *v4; // r5
  int v5; // r3

  result = wlc_check_rate_flag(a1, a2, dword_128C24);
  if ( result )
  {
    v4 = (void *)(uintptr_t)(off_128C2C);
    v5 = *((volatile uint8_t *)off_128C28 + 2);
    *((volatile uint8_t *)off_128C2C + 28) = 0;
    if ( v5 )
      *(volatile uint32_t *)off_128C30 |= 0x80000000;
    if ( v4[8] )
      --v4[8];
    result = fault_handler(dword_128C34);
    v4[29] = 0;
    *(volatile uint32_t *)(a1 + 4) &= 0xFFFFFDF9;
  }
  return result;
}



// wlc_print_msg @ 0x128c38
int wlc_print_msg(int a1, int a2) {
  int result; // r0
  volatile uint8_t *v4; // r3
  int v5; // r2
  int v6; // r2
  int v7; // r1
  int v8; // r0

  result = wlc_check_rate_flag(a1, a2, dword_128C84);
  if ( result )
  {
    v4 = (void *)(uintptr_t)(off_128C8C);
    v5 = *((volatile uint8_t *)off_128C88 + 2);
    *((volatile uint8_t *)off_128C8C + 28) = 1;
    if ( v5 )
      *(volatile uint32_t *)off_128C90 &= ~0x80000000;
    if ( v4[8] )
      --v4[8];
    v6 = *((volatile uint32_t *)off_128C98 + 4);
    v7 = *(volatile uint16_t *)(*(volatile uint32_t *)off_128C94 + 54);
    v8 = dword_128C9C;
    *((volatile uint32_t *)v4 + 5) = a1;
    v4[29] = 4;
    result = unknown_worker((void *)(uintptr_t)(v8), v7 + v6);
    *(volatile uint32_t *)(a1 + 4) |= 0x200u;
  }
  return result;
}



// wlc_log_event_a @ 0x128ca0
int wlc_log_event_a(int a1, int a2) {
  int result; // r0
  volatile uint16_t *v5; // r2
  char v6; // r3

  check_status_bits(2, "%s:%x\r\n", aPsEnableCfm, a2);
  result = wlc_check_rate_flag(a1, a2, off_128CE8);
  if ( result )
  {
    v5 = (volatile uint16_t *)off_128CEC;
    if ( !*((volatile uint8_t *)off_128CEC + 8) || (v6 = *((volatile uint8_t *)off_128CEC + 8) - 1, (*((volatile uint8_t *)off_128CEC + 8) = v6) == 0) )
    {
      *(volatile uint8_t *)v5 = 1;
      return ke_msg_send_no_param(50, v5[1], 0);
    }
  }
  return result;
}


// wlc_log_event_b @ 0x128cf0
volatile uint16_t * wlc_log_event_b(int a1, int a2) {
  volatile uint16_t *result; // r0
  volatile int *i; // r3
  int v6; // r3

  check_status_bits(2, "%s:%x\r\n", aPsDisableCfm, a2);
  result = (volatile uint16_t *)wlc_check_rate_flag(a1, a2, off_128D58);
  if ( result )
  {
    result = (volatile uint16_t *)off_128D5C;
    if ( !*((volatile uint8_t *)off_128D5C + 8)
      || (v6 = (uint8_t)(*((volatile uint8_t *)off_128D5C + 8) - 1), *((volatile uint8_t *)off_128D5C + 8) = v6, !v6) )
    {
      for ( i = *((volatile int **)off_128D60 + 2); i; i = (volatile int *)*i )
      {
        if ( !*((volatile uint8_t *)i + 106) )
        {
          if ( *((volatile uint8_t *)i + 108) )
            i[1] &= 0xFFFFFFF1;
        }
      }
      *(volatile uint8_t *)result = 0;
      return (volatile uint16_t *)ke_msg_send_no_param(50, result[1], 0);
    }
  }
  return result;
}


// wlc_chip_state @ 0x128d64
void wlc_chip_state() {
  volatile uint8_t *v0; // r5
  int v1; // r4
  int v2; // r6
  int v3; // r0

  v0 = (void *)(uintptr_t)(off_128DB4);
  if ( *(volatile uint8_t *)off_128DB4 )
  {
    if ( *((volatile uint8_t *)off_128DB4 + 28) )
    {
      v1 = *((volatile uint32_t *)off_128DBC + 2);
      *(volatile uint32_t *)off_128DB8 |= 4u;
      v0[8] = 0;
      if ( v1 )
      {
        v2 = dword_128DC0;
        do
        {
          if ( !*(volatile uint8_t *)(v1 + 106) )
          {
            if ( *(volatile uint8_t *)(v1 + 108) )
            {
              v3 = *(volatile uint8_t *)(v1 + 116);
              if ( v3 != 255 && !rf_channel_get(v3, v2, v1) )
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



// wlc_phy_band_check @ 0x128dc4
void wlc_phy_band_check(int a1) {
  volatile uint8_t *v1; // r5
  uint64_t v3; // r2
  BOOL v4; // r0
  volatile uint32_t *v5; // r3
  int v6; // r2
  int v7; // r1
  int v8; // r0

  v1 = (void *)(uintptr_t)(off_128E84);
  v3 = (v3 & ~0xFFFFFFFFull) | ((uint32_t)(*((volatile uint32_t *)off_128E88 + 126)) & 0xFFFFFFFFu);
  v3 = (v3 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(*((volatile uint32_t *)off_128E84 + 1) & 0x20) << 32);
  if ( **(volatile uint8_t **)off_128E80 == 1 )
  {
    if ( v3 )
      v4 = 0;
    else
      v4 = get_status_flag() != 0;
  }
  else
  {
    v4 = v3 == 0;
  }
  if ( *(volatile uint8_t *)(a1 + 149) )
  {
    if ( !**(volatile uint8_t **)off_128E8C || !*(volatile uint8_t *)(a1 + 108) )
    {
LABEL_6:
      v1[29] = 0;
      *(volatile uint32_t *)(a1 + 4) = 0;
      return;
    }
LABEL_18:
    v5 = (void *)(uintptr_t)(off_128E98);
    v6 = *(volatile uint32_t *)off_128E94;
    *((volatile uint32_t *)v1 + 5) = a1;
    v7 = *(volatile uint16_t *)(v6 + 54);
    v8 = dword_128E9C;
    v1[29] = 1;
    unknown_worker((void *)(uintptr_t)(v8), v7 + v5[4]);
    return;
  }
  if ( !**(volatile uint8_t **)off_128E8C || !*(volatile uint8_t *)(a1 + 108) )
    goto LABEL_6;
  if ( !v4 || (*(volatile uint32_t *)off_128E90 & 0x2000000) == 0 && !v1[36] )
    goto LABEL_18;
  if ( v1[29] == 5 )
  {
    *(volatile uint32_t *)(a1 + 4) &= ~2u;
    v1[29] = 0;
  }
  if ( v1[28] )
    wlc_chip_state();
  else
    v1[29] = 0;
}



// wlc_core_state @ 0x128ea0
void wlc_core_state() {
  volatile uint8_t *v0; // r5
  volatile unsigned int *v1; // r1
  int v2; // r2
  int v3; // r4
  int v4; // r6
  int v5; // r0

  v0 = (void *)(uintptr_t)(off_128EE8);
  if ( !*((volatile uint8_t *)off_128EE8 + 28) )
  {
    v1 = (volatile unsigned int *)off_128EEC;
    v2 = *(volatile uint32_t *)off_128EEC;
    v3 = *((volatile uint32_t *)off_128EF0 + 2);
    *((volatile uint8_t *)off_128EE8 + 8) = 0;
    *v1 = v2 & 0xFFFFFFFB;
    if ( v3 )
    {
      v4 = dword_128EF4;
      do
      {
        if ( !*(volatile uint8_t *)(v3 + 106) )
        {
          if ( *(volatile uint8_t *)(v3 + 108) )
          {
            v5 = *(volatile uint8_t *)(v3 + 116);
            if ( v5 != 255 && !rf_channel_get(v5, v4, v3) )
              ++v0[8];
          }
        }
        v3 = *(volatile uint32_t *)v3;
      }
      while ( v3 );
    }
  }
}



// wlc_mfp_key_clear @ 0x128ef8
int wlc_mfp_key_clear() {
  volatile uint32_t *v0; // r4
  volatile int *v1; // r0
  int result; // r0

  v0 = (void *)(uintptr_t)(off_128F14);
  v1 = memset((volatile int *)off_128F14, 0, 0x28u);
  result = (int)(uintptr_t)(init_1990b0_buffers(v1));
  v0[4] = off_128F18;
  *((volatile uint8_t *)v0 + 28) = 1;
  return result;
}



// wlc_bss_state @ 0x128f1c
int wlc_bss_state() {
  volatile uint32_t *v0; // r4
  volatile uint32_t *v1; // r3

  v0 = (void *)(uintptr_t)(off_128F50);
  if ( !*(volatile uint8_t *)off_128F50 && !controller_status_byte() )
    return 0;
  if ( v0[1] )
    return 0;
  v1 = *((volatile uint32_t **)off_128F54 + 2);
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



// wlc_band_set @ 0x128f58
int wlc_band_set(int a1, uint16_t a2) {
  volatile uint8_t *v2; // r2
  volatile uint8_t *v3; // r3
  int v4; // zf
  int ( *v5)(int, int); // r3

  v2 = (void *)(uintptr_t)(off_128F80);
  v3 = *(volatile uint8_t **)off_128F7C;
  *((volatile uint16_t *)off_128F80 + 1) = a2;
  v4 = *v3 == 2;
  v5 = (int ( *)(int, int))off_128F84;
  if ( !v4 && a1 )
    v5 = (int ( *)(int, int))off_128F88;
  v2[8] = 0;
  return v5(0, 0x800000);
}


// wlc_ioctl_handler @ 0x128f8c
unsigned int wlc_ioctl_handler(unsigned int result, int a2, int a3) {
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
  v4 = (void *)(uintptr_t)(off_129158);
  v6 = *(volatile uint32_t *)(a3 + 4);
  v7 = *(volatile uint8_t *)off_129158;
  v8 = *(volatile uint16_t *)(dword_129154 + 696 * v3 + 32);
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
          v16 = (void *)(uintptr_t)(off_12915C);
          *(volatile uint32_t *)(a3 + 4) = v6 & 0xFFFFFFFC | 2;
          if ( (*v16 & 0x200) != 0 )
            *v16 &= ~0x200u;
          if ( !*((volatile uint8_t *)v4 + 29) )
          {
            v17 = *((volatile uint32_t *)off_129170 + 4);
            v18 = *(volatile uint16_t *)(*(volatile uint32_t *)off_12916C + 56);
            v19 = dword_129174;
            v4[5] = a3;
            *((volatile uint8_t *)v4 + 29) = 5;
            unknown_worker((void *)(uintptr_t)(v19), v18 + v17);
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
        if ( (*(volatile uint32_t *)off_12915C & 0x200) != 0 )
          *(volatile uint32_t *)off_12915C &= ~0x200u;
        if ( !*(volatile uint8_t *)off_129160 )
        {
          wlc_core_state();
          if ( !*((volatile uint8_t *)v4 + 28) || (*(volatile uint32_t *)off_129168 & 4) != 0 )
          {
            *(volatile uint8_t *)off_129164 = 0;
          }
          else
          {
            v20 = (void *)(uintptr_t)(off_129164);
            if ( *(volatile uint8_t *)off_129164 && (get_phy_channel() != 1 || !*((volatile uint32_t *)off_129178 + 126)) )
              rf_channel_get(*(volatile uint8_t *)(a3 + 116), 0, 0);
            *v20 = 1;
          }
          v21 = (void *)(uintptr_t)(off_129170);
          v22 = *(volatile uint16_t *)(*(volatile uint32_t *)off_12916C + 58);
          v23 = dword_129174;
          *(volatile uint32_t *)(a3 + 4) |= 4u;
          v24 = v21[4];
          v4[5] = a3;
          *((volatile uint8_t *)v4 + 29) = 6;
          return unknown_worker((void *)(uintptr_t)(v23), v22 + v24);
        }
      }
      else
      {
        v12 = *(volatile uint32_t *)(a3 + 4) & 0xFFFFFFFB;
        *(volatile uint8_t *)off_129164 = 0;
        *(volatile uint32_t *)(a3 + 4) = v12;
      }
    }
  }
  else if ( result
         && (*(volatile uint32_t *)off_129168 & 4) == 0
         && (v13 = *(volatile uint8_t *)(result + 4) & 0xFE, v14 = v8 >> 3, v13 <= v8 >> 3)
         && v14 <= *(volatile uint8_t *)(result + 1) - 4 + v13
         && (*(volatile uint8_t *)(result + v14 - v13 + 5) & (1 << (v8 & 7))) != 0 )
  {
    v15 = (void *)(uintptr_t)(off_129164);
    if ( *(volatile uint8_t *)off_129164 )
    {
      result = get_phy_channel();
      if ( result != 1 || !*((volatile uint32_t *)off_129178 + 126) )
        result = rf_channel_get(*(volatile uint8_t *)(a3 + 116), 0, 0);
    }
    *v15 = 1;
  }
  else
  {
    *(volatile uint8_t *)off_129164 = 0;
  }
  return result;
}



// wlc_rx_reclaim @ 0x12917c
int wlc_rx_reclaim(int result, int a2, int a3) {
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

  v3 = (void *)(uintptr_t)(off_1291F8);
  v5 = *(volatile uint32_t *)(a3 + 4);
  v6 = *(volatile uint8_t *)off_1291F8;
  v7 = v5 & 0xFFFFFFFE;
  *(volatile uint32_t *)(a3 + 4) = v5 & 0xFFFFFFFE;
  if ( v6 )
  {
    v9 = *(volatile uint8_t *)(a3 + 114);
    if ( !*(volatile uint8_t *)(a3 + 114) )
    {
      if ( result )
      {
        v12 = (void *)(uintptr_t)(off_129200);
        v13 = *(volatile uint32_t *)off_1291FC;
        *(volatile uint32_t *)(a3 + 4) = v7 | 2;
        v14 = v12[4];
        v15 = *(volatile uint16_t *)(v13 + 56);
        v3[5] = a3;
        *((volatile uint8_t *)v3 + 29) = 5;
        result = unknown_worker((void *)(uintptr_t)((int)(v3 + 3)), v15 + v14);
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
    process_global_167204(result, v9, v5);
    wlc_core_state();
    v10 = *((volatile uint32_t *)off_129200 + 4);
    v11 = *(volatile uint16_t *)(*(volatile uint32_t *)off_1291FC + 58);
    v3[5] = a3;
    *((volatile uint8_t *)v3 + 29) = 6;
    return unknown_worker((void *)(uintptr_t)(dword_129204), v11 + v10);
  }
  return result;
}



// wlc_bus_state @ 0x129208
void wlc_bus_state(volatile uint16_t *a1, int16_t a2, int a3) {
  volatile uint8_t *v3; // r5
  uint16_t v4; // r6
  int v6; // r3
  int v7; // r1
  int v8; // r3
  int v9; // r3
  int v10; // r1

  v3 = (void *)(uintptr_t)(off_1292C0);
  if ( *(volatile uint8_t *)off_1292C0 )
  {
    v4 = *a1;
    if ( (a1[2] & 1) != 0 )
    {
      if ( *((volatile uint8_t *)off_1292C0 + 29) == 5 )
      {
        fault_handler((int)off_1292C0 + 12);
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
          v9 = *((volatile uint32_t *)off_1292CC + 4);
          v10 = *(volatile uint16_t *)(*(volatile uint32_t *)off_1292C8 + 56);
          *((volatile uint32_t *)v3 + 5) = a3;
          v3[29] = 5;
          unknown_worker((void *)(uintptr_t)(dword_1292D0), v10 + v9);
        }
      }
    }
    else if ( *(volatile uint8_t *)off_1292C4 )
    {
      llcp_is_control(a3, *a1, a1);
    }
    else if ( (a2 & 0x200) == 0 )
    {
      v6 = *((volatile uint32_t *)off_1292CC + 4);
      v7 = *(volatile uint16_t *)(*(volatile uint32_t *)off_1292C8 + 54);
      *((volatile uint32_t *)off_1292C0 + 5) = a3;
      v3[29] = 2;
      unknown_worker((void *)(uintptr_t)((int)(v3 + 12)), v7 + v6);
      v8 = *(volatile uint32_t *)(a3 + 4);
      if ( (v4 & 0x2000) != 0 )
      {
        if ( (v8 & 4) == 0 )
          *(volatile uint32_t *)(a3 + 4) = v8 | 4;
        wlc_core_state();
      }
      else
      {
        *(volatile uint32_t *)(a3 + 4) = v8 & 0xFFFFFFFB;
      }
    }
  }
}



// wlc_is_ready @ 0x1292d4
void wlc_is_ready(int a1) {
  volatile uint8_t *v1; // r2
  int v2; // r3
  int v3; // r3
  int v4; // r1
  int v5; // r0
  volatile uint32_t *v6; // r3

  v1 = (void *)(uintptr_t)(off_12936C);
  if ( *(volatile uint8_t *)off_12936C )
  {
    v2 = *(volatile uint8_t *)(a1 + 29);
    if ( v2 != 255 && *(volatile uint8_t *)(a1 + 27) != 255 )
    {
      v3 = dword_129374 + 1320 * *(volatile uint8_t *)(dword_129370 + 696 * v2 + 34);
      if ( !*(volatile uint8_t *)(v3 + 106) )
      {
        if ( *(volatile uint8_t *)(v3 + 108) )
        {
          v4 = *((volatile uint32_t *)off_12937C + 4);
          v5 = *(volatile uint16_t *)(*(volatile uint32_t *)off_129378 + 54);
          *((volatile uint32_t *)off_12936C + 5) = v3;
          v1[29] = 3;
          unknown_worker((void *)(uintptr_t)((int)(v1 + 12)), v4 + v5);
          if ( (*(volatile uint32_t *)off_129380 & 4) != 0 )
          {
            if ( *((volatile uint8_t *)off_129384 + 190) )
            {
              if ( **(volatile uint8_t **)off_129388 == 2 )
              {
                v6 = (void *)(uintptr_t)(off_129390);
                *(volatile uint32_t *)off_12938C &= ~0x200u;
                *v6 &= ~1u;
                *v6 &= ~0x80u;
              }
            }
            wlc_core_state();
          }
        }
      }
    }
  }
}



// wlc_mmio_regs @ 0x129394
int wlc_mmio_regs() {
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

  v0 = (volatile unsigned int *)off_1294C4;
  v1 = (volatile int *)off_129498;
  v2 = (volatile int *)off_12949C;
  v3 = (void *)(uintptr_t)(off_1294A0);
  v4 = HIWORD(((volatile uint32_t *)(uintptr_t)off_12949C)[46]);
  v5 = (volatile unsigned int *)off_1294A4;
  v6 = (volatile uint8_t **)off_1294A8;
  *(volatile uint32_t *)off_129494 |= 0x40000000u;
  *v3 |= 0x10000000u;
  *v0 &= 0xFFF0FFFF;
  *v0 = *v0 & 0xFFFFFF00 | 0x10;
  *v5 = *v5 & 0xFFFFFF03 | 0x10;
  *v1 = *v1 & 0x3FFFFF | (((v4 >> 5) + 32) << 22);
  result = check_status_bits(2, "%s:%d,%d\r\n", aPsUpmEnter, **v6, (v4 >> 5) + 32);
  v8 = *v6;
  v9 = **v6;
  if ( v9 == 1 )
  {
    if ( *((volatile uint8_t *)v2 + 189) )
    {
      result = (int)off_1294B4;
      *(volatile uint32_t *)off_1294B8 &= ~0x2000000u;
      *v5 |= 0x200000u;
      *(volatile uint32_t *)result = 36;
      if ( *v8 != 2 )
        goto LABEL_3;
      goto LABEL_6;
    }
    result = (int)off_1294B8;
    v13 = (void *)(uintptr_t)(off_1294B4);
    v14 = (void *)(uintptr_t)(off_1294C0);
    *(volatile uint32_t *)off_1294B8 |= 0x2000000u;
    *v13 = 4;
    *v14 = 1;
    *v3 &= 0xFFFBFFFE;
    v9 = *v8;
  }
  if ( v9 != 2 )
  {
LABEL_3:
    *(volatile uint32_t *)off_1294B4 &= ~0x20u;
    return result;
  }
LABEL_6:
  v10 = (void *)(uintptr_t)(off_1294B8);
  v11 = (void *)(uintptr_t)(off_1294B4);
  v12 = (void *)(uintptr_t)(off_1294A4);
  *(volatile uint32_t *)off_1294BC |= 0x10000u;
  *v10 &= ~0x2000000u;
  *v11 = 63;
  *v12 &= ~1u;
  return 63;
}


// wlc_mmio_clock_enable @ 0x1294c8
int wlc_mmio_clock_enable() {
  volatile uint32_t *v0; // r0
  volatile uint32_t *v1; // r1
  volatile uint32_t *v2; // r5
  volatile uint32_t *v3; // r2

  *(volatile uint32_t *)off_129520 |= 0x2000000u;
  check_status_bits(2, "%s\r\n", aPsUpmExit);
  if ( !*((volatile uint8_t *)off_12952C + 18) )
    *(volatile uint32_t *)off_129530 &= ~1u;
  v0 = (void *)(uintptr_t)(off_129538);
  v1 = (void *)(uintptr_t)(off_129530);
  v2 = (void *)(uintptr_t)(off_12953C);
  v3 = (void *)(uintptr_t)(off_129540);
  *(volatile uint32_t *)off_129534 &= ~0x10000u;
  *v0 &= ~0x40000000u;
  *v1 &= ~0x10000000u;
  *v2 = 0;
  *v3 &= ~1u;
  return 0;
}


