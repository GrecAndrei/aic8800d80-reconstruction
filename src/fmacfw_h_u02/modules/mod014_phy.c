// phy_config_table @ 0x116f34
int phy_config_table(int result) {
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
    v2 = dword_117344;
  else
    v2 = dword_1171FC + 84 * result;
  v3 = dword_117204;
  v41 = 1 << result;
  v4 = *(volatile uint8_t *)(v2 + 26);
  v43 = result + dword_117200;
  v5 = (volatile unsigned int *)(4 * (result + dword_117200));
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
          v9 = REG_4032_0120 + *(volatile uint32_t *)(dword_117208 + 4 * v1);
          *v5 = v9;
LABEL_9:
          if ( (v8 & 0x800000) != 0 )
          {
            v10 = *(volatile uint16_t *)(v6 + 8);
            if ( (v10 & 0x20) == 0 )
            {
              check_hw_fw_status();
              v32 = 4;
              while ( 1 )
              {
                v10 = *(volatile uint16_t *)(v6 + 8);
                if ( (v10 & 0x20) != 0 )
                  break;
                check_hw_fw_status();
                if ( !--v32 )
                {
                  v10 = *(volatile uint16_t *)(v6 + 8);
                  if ( **(volatile int16_t **)dword_11732C < 0 && (v10 & 0x20) == 0 )
                    return log_assert_failure((int)aAggDescStatusA, (int)aTxlFrameExchan_0, 1262);
                  goto LABEL_11;
                }
              }
            }
          }
          else
          {
LABEL_36:
            list_pop(v2 + 28);
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
          v23 = REG_4032_0120 + *(volatile uint32_t *)(dword_117208 + 4 * v1);
          *v5 = v23;
          goto LABEL_31;
        }
      }
      if ( *(volatile uint32_t *)(v2 + 44)
        && !*(volatile uint32_t *)(dword_117228 + 8 * (165 * *(volatile uint8_t *)(*(volatile uint32_t *)(v2 + 48) + 28) + v1 + 154))
        && !*(volatile uint8_t *)(dword_117358 + 0x1FF) )
      {
        v44 = *(volatile uint32_t *)(v6 + 144);
        btm_get_conn_entry(v1);
        v8 = v44;
        v7 = *(volatile uint8_t *)(*(volatile uint32_t *)v3 + 1);
      }
      v31 = REG_4032_0120 + *(volatile uint32_t *)(dword_117208 + 4 * v1);
      *v5 = v31;
      if ( v7 )
        goto LABEL_9;
LABEL_31:
      v10 = *(volatile uint16_t *)(v6 + 8);
      if ( (v10 & 0x20) == 0 )
      {
        check_hw_fw_status();
        v24 = 4;
        while ( 1 )
        {
          v10 = *(volatile uint16_t *)(v6 + 8);
          if ( (v10 & 0x20) != 0 )
            break;
          check_hw_fw_status();
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
      v11 = *(volatile uint32_t *)(dword_11720C + 4 * v1);
      *(volatile uint16_t *)(v6 + 8) = v10 | 0x10;
      result = irq_disable_global_2(v11);
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
      v25 = *(volatile uint32_t *)dword_117218;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(volatile uint32_t *)dword_11721C = 1;
      }
      v26 = (volatile uint32_t *)dword_117220;
      result = *(volatile uint32_t *)dword_117220;
      v27 = (volatile uint32_t *)dword_117218;
      v28 = *(volatile uint32_t *)dword_117220 + 1;
      *(volatile uint32_t *)dword_117220 = v28;
      *v27 = v25 & v42;
      if ( v28 )
      {
        v29 = (volatile int *)dword_11721C;
        *v26 = result;
        v30 = *v29;
        if ( !result )
        {
          if ( v30 )
            __enable_irq();
        }
      }
      *(volatile uint32_t *)dword_117224 = v41;
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
        return tx_status_check(*(volatile uint32_t *)(v14 + 68) + 16, v1);
      return result;
    }
    v15[1] = v16;
    get_conn_env(v1);
    v17 = *(volatile uint32_t *)(v14 + 36) & 0x200000;
    if ( !v17 )
    {
      v18 = v15[4];
      if ( v18 )
      {
        v19 = v15[4];
        if ( (*(volatile uint32_t *)(v18 + 56) & 0x380000) == 0x200000 )
        {
          if ( **(volatile int16_t **)dword_11722C < 0 && !*(volatile uint32_t *)(v18 + 8) )
          {
            irq_disable_mmio_write((int)aNextdescNull, (int)aTxlFrameExchan_0, 1077);
            __und(0xFFu);
          }
          v17 = v15[4];
          v19 = *(volatile uint32_t *)(v18 + 8);
        }
        if ( *(volatile int *)(v19 + 60) >= 0 )
        {
          result = v17;
          if ( v17 )
            result = tx_status_check(v17, v1);
          v33 = REG_4032_0120;
          *(volatile uint32_t *)(4 * v43) = v33 + *(volatile uint32_t *)(dword_117338 + 4 * v1);
          return result;
        }
      }
      else
      {
        *(volatile uint32_t *)v2 = 0;
        mmio_modify_bit(v1);
        if ( *(volatile uint8_t *)(v2 + 80) == 1
          && *(volatile uint32_t *)(v2 + 44)
          && !*(volatile uint32_t *)(dword_117228 + 8 * (165 * *(volatile uint8_t *)(*(volatile uint32_t *)(v2 + 48) + 28) + v1 + 154))
          && !*(volatile uint8_t *)(dword_1171FC + 0x1FF) )
        {
          btm_get_conn_entry(v1);
        }
      }
    }
    if ( (v16 & 0x800000) != 0 )
    {
      v20 = *(volatile uint8_t *)(v14 + 29);
      if ( v20 <= 0x23 )
      {
        v21 = (*(volatile uint32_t *)0x40501010u);
        *(volatile uint32_t *)(dword_117210 + 696 * v20 + 664) = v21;
      }
    }
    list_pop(v2 + 12);
    if ( *(volatile uint16_t *)(v14 + 4) )
      register_handler((volatile uint32_t *)v14, v16, v1);
    else
      set_string_0x1882c0((volatile uint32_t *)v14);
    v22 = *(volatile uint32_t *)(v14 + 36);
    result = v22 << 10;
    if ( (v22 & 0x200000) != 0 )
    {
      if ( (v22 & 0x380000) == 0x380000 )
      {
        *(volatile uint32_t *)(v2 + 36) = *(volatile uint32_t *)(v14 + 68);
        *(volatile uint8_t *)(v2 + 26) = 1;
        result = irq_disable_global_2(512);
      }
    }
    else
    {
      --*(volatile uint8_t *)(v2 + 80);
    }
    *v5 = REG_4032_0120 + *(volatile uint32_t *)(dword_117208 + 4 * v1);
    v4 = *(volatile uint8_t *)(v2 + 26);
  }
  v34 = (volatile int *)dword_117348;
  *(volatile uint32_t *)v2 = 0;
  v35 = *v34;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)dword_11734C = 1;
  }
  v36 = (volatile uint32_t *)dword_117350;
  result = *(volatile uint32_t *)dword_117350;
  v37 = (volatile uint32_t *)dword_117348;
  v38 = *(volatile uint32_t *)dword_117350 + 1;
  *(volatile uint32_t *)dword_117350 = v38;
  *v37 = v35 & v42;
  if ( v38 )
  {
    v39 = (volatile int *)dword_11734C;
    *v36 = result;
    v40 = *v39;
    if ( !result )
    {
      if ( v40 )
        __enable_irq();
    }
  }
  *(volatile uint32_t *)dword_117354 = v41;
  return result;
}


// phy_get_cfg_ptr @ 0x11735c
int phy_get_cfg_ptr(int a1) {
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
    v2 = (volatile uint32_t *)dword_1173F0;
  else
    v2 = (volatile uint32_t *)(dword_1173D8 + 84 * a1);
  phy_dispatch(a1, dword_1173DC + 8 * a1, 0);
  phy_dispatch(a1, (int)(uintptr_t)(v2 + 3), 0);
  *v2 = 0;
  v2[5] = 0;
  ll_event_clear(a1);
  v3 = *(volatile uint32_t *)off_1173E0;
  v4 = 1 << a1;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_1173E4 = 1;
  }
  v5 = (void *)(uintptr_t)(off_1173E8);
  v6 = (volatile int *)off_1173E0;
  v7 = *(volatile uint32_t *)off_1173E8;
  result = *(volatile uint32_t *)off_1173E8 + 1;
  *(volatile uint32_t *)off_1173E8 = result;
  *v6 = v3 & ~v4;
  if ( result )
  {
    v9 = (volatile int *)off_1173E4;
    *v5 = v7;
    v10 = *v9;
    if ( !v7 )
    {
      if ( v10 )
        __enable_irq();
    }
  }
  *(volatile uint32_t *)off_1173EC = v4;
  return result;
}



// phy_sleep_prepare @ 0x1173f4
int phy_sleep_prepare(int a1) {
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
    phy_dispatch(v3, v1, 0);
    result = (int)(uintptr_t)(phy_dispatch(v5, v1 - 40, 0));
    v1 += 8;
  }
  while ( v2 != 5 );
  return result;
}



// phy_set_rate_power @ 0x117424
int phy_set_rate_power(int a1, int a2) {
  volatile char *v4; // r7
  int v5; // r0
  int16_t v6; // r1
  volatile uint32_t *v7; // r3
  int v8; // r3
  volatile uint8_t *v9; // r2
  volatile int *v10; // r6
  int result; // r0
  int v12; // r3
  int v13; // r3
  int v14; // r2
  volatile unsigned int v15; // r2

  if ( a2 == 5 )
    v4 = (volatile char *)dword_117548;
  else
    v4 = (volatile char *)off_117524 + 84 * a2;
  v5 = dword_117528;
  v6 = *(volatile uint16_t *)(a1 + 30);
  v7 = *(volatile uint32_t **)(a1 + 76);
  v7[9] = *(volatile uint8_t *)(a1 + 51) + *(volatile uint8_t *)(a1 + 53) + *(volatile uint16_t *)(a1 + 4) + 4;
  v7[8] = 0;
  v7[13] = 0;
  v7[14] = 0;
  v7[4] = 0;
  v7[5] = 0;
  v7[6] = 0;
  v7[7] = 0;
  v7[3] = v5;
  v7[15] = 0;
  v7[12] = 0;
  v7[17] = 0;
  v7[10] = 0;
  if ( (v6 & 1) == 0 )
    v7[18] = 0;
  v8 = *((volatile uint32_t *)off_11752C + 8);
  if ( v8 )
  {
    v9 = *(volatile uint8_t **)off_117530;
    *(volatile uint32_t *)off_117534 = 0x80000000;
    if ( *v9 == 3 && v8 == dword_117540 + 1320 * *(volatile uint8_t *)(a1 + 28) )
    {
      v15 = (*(volatile uint32_t *)0x40501010u);
      *(volatile uint32_t *)(v8 + 120) = v15;
    }
  }
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_117538 = 1;
  }
  v10 = (volatile int *)off_11753C;
  ++*(volatile uint32_t *)off_11753C;
  btm_init_conn_entry(a1, a2);
  co_list_push_back((int)(v4 + 12), (volatile uint32_t *)a1);
  is_channel_index_valid(*(volatile uint8_t *)(a1 + 28), *(volatile uint8_t *)(a1 + 29), 0);
  if ( (*(volatile uint16_t *)(a1 + 30) & 1) == 0 )
    ++*((volatile uint32_t *)off_117524 + 126);
  mfp_is_enabled(a1);
  result = rx_process_packet(a1, a2, 0);
  v12 = *v10;
  *(volatile uint16_t *)(a1 + 82) |= 1u;
  if ( v12 )
  {
    v13 = v12 - 1;
    v14 = *(volatile uint32_t *)off_117538;
    *v10 = v13;
    if ( !v13 )
    {
      if ( v14 )
        __enable_irq();
    }
  }
  return result;
}


// phy_stats_count @ 0x11754c
void phy_stats_count() {
  ++*((volatile uint32_t *)off_11755C + 126);
}



// ke_msg_dispatch @ 0x117560
int ke_msg_dispatch(int a1, int a2) {
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
    v4 = (volatile char *)dword_11774C;
  else
    v4 = (volatile char *)off_117748 + 84 * a2;
  v5 = *(volatile uint8_t *)(a1 + 28);
  v6 = dword_117780;
  v7 = *(volatile uint32_t *)(a1 + 76);
  v8 = dword_117780 + 1320 * v5;
  if ( phy_lock(v8)
    && ((v10 = *(volatile uint8_t *)(a1 + 28), *(volatile uint8_t *)(v6 + 1320 * v10 + 106))
     || *(volatile uint8_t *)(a1 + 29) > 0x23u
     || *(volatile uint16_t *)(a1 + 4)
     || (v11 = *(volatile uint16_t *)(*(volatile uint32_t *)(a1 + 72) + 108), (uint8_t)v11 != 192)
     && (uint8_t)v11 != 176
     && (v11 & 0xDF) != 0
     || (v12 = *((volatile uint32_t *)off_117750 + 10)) == 0
     || *(volatile uint8_t *)(v12 + 24) <= 2u
     || (v13 = *(volatile uint32_t *)(v6 + 1320 * v10 + 72)) == 0
     || (v31 = v13, alloc_tx_event("is_on_chan:%d, %x\n", v12 == v13, (uint8_t)v11), v12 == v31))
    && get_connection_state(a1) )
  {
    *(volatile uint32_t *)(v7 + 68) |= 0x100u;
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(volatile uint32_t *)off_117758 = 1;
    }
    v14 = (volatile int *)off_11775C;
    v15 = *((volatile uint32_t *)v4 + 11);
    v16 = v4[80] + 1;
    ++*(volatile uint32_t *)off_11775C;
    v4[80] = v16;
    if ( v15 )
      btm_get_conn_entry(a2);
    if ( !*((volatile uint32_t *)v4 + 5) )
    {
      v30 = *(volatile uint32_t **)(a1 + 72);
      v30[4] = dword_11777C;
      v30[2] = a1;
      v30[3] = a1;
    }
    co_list_push_back((int)(v4 + 12), (volatile uint32_t *)a1);
    v17 = *((volatile uint32_t *)off_117760 + 8);
    ++*((volatile uint32_t *)off_117748 + 126);
    if ( v17 )
    {
      v18 = *(volatile uint8_t **)off_117764;
      *(volatile uint32_t *)off_117768 = 0x80000000;
      if ( *v18 == 3 && v17 == v8 )
      {
        v19 = (*(volatile uint32_t *)0x40501010u);
        *(volatile uint32_t *)(v6 + 1320 * v5 + 120) = v19;
      }
    }
    if ( **(volatile uint8_t **)off_117770 == 2 && (*(volatile uint32_t *)off_117774 & dword_117778) == 0 )
      process_event();
    if ( *v14 )
    {
      v20 = *v14 - 1;
      v21 = *(volatile uint32_t *)off_117758;
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
      *(volatile uint32_t *)off_117758 = 1;
    }
    v22 = *v14;
    v23 = *v14 + 1;
    v24 = *(volatile uint16_t *)(a1 + 82) | 1;
    *v14 = v23;
    *(volatile uint16_t *)(a1 + 82) = v24;
    if ( v23 )
    {
      v25 = (volatile int *)off_117758;
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
      *(volatile uint32_t *)off_117758 = 1;
    }
    v27 = *(volatile uint32_t *)(a1 + 72);
    ++*v14;
    mac_update_flags(a1, a1, v27, a2);
    if ( *v14 )
    {
      v28 = *v14 - 1;
      v29 = *(volatile uint32_t *)off_117758;
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
    check_packet_flag(a1, 0);
    return 0;
  }
  else
  {
    conn_table_get(a1, a2);
    return 1;
  }
}


// nullsub_7 @ 0x117784
int nullsub_7(void) {
  return 0;
}


// radio_isr @ 0x117788
/* luna: Processes masked radio interrupt status, runs the busy-flag path when bit 0x10 is set, dispatches encoded RF commands, and acknowledges the handled st */
unsigned int radio_isr() {
  int pending_irq_status; // r4
  unsigned int result; // r0

  pending_irq_status = dword_1177D8 & *(volatile uint32_t *)off_1177D4;
  if ( (*(volatile uint32_t *)off_1177D4 & 0x10) != 0 )
  {
    if ( (*(volatile uint32_t *)off_1177D4 & 0x1000) != 0 )
    {
      pending_irq_status |= 0x1000u;
      *((volatile uint32_t *)off_1177E0 + 52) |= 4u;
    }
    ((int (*)())run_with_busy_flag)();
  }
  result = pending_irq_status & 0xF00000;
  if ( (pending_irq_status & 0xF00000) != 0 )
    result = rf_command_handler((uint8_t)(11 - __clz(result)));
  *(volatile uint32_t *)off_1177DC = pending_irq_status;
  return result;
}



// radio_event_handler @ 0x1177e4
int radio_event_handler(int result) {
  int v1; // r4
  int v2; // r5
  unsigned int v3; // r3
  unsigned int v4; // r4

  v1 = *(volatile uint32_t *)off_11788C;
  if ( (*(volatile uint32_t *)off_11788C & 0x1000) != 0 )
  {
    result = ((int (*)())dma_irq_handler)(result, *(volatile uint32_t *)off_11788C << 19);
    *(volatile uint32_t *)off_1178A0 = 4096;
  }
  v2 = dword_117890;
  if ( (v1 & dword_117890) != 0 )
  {
    result = ((int (*)())is_fw_ready)();
    *(volatile uint32_t *)off_1178A0 = v2;
  }
  if ( (dword_117894 & v1) != 0 && (*(volatile uint32_t *)off_117898 & 0x300000) == 0 )
  {
    *(volatile uint32_t *)off_1178A8 |= 0x200u;
    v3 = dword_11789C & v1;
    if ( (dword_11789C & v1) == 0 )
      return result;
  }
  else
  {
    v3 = dword_11789C & v1;
    if ( (dword_11789C & v1) == 0 )
      return result;
  }
  if ( (v1 & 0x80000) != 0 )
  {
LABEL_9:
    *(volatile uint32_t *)off_1178A0 = 0x80000;
    return phy_config_table(5);
  }
  v4 = (uint8_t)(25 - __clz(v3));
  if ( **(volatile int16_t **)off_1178A4 >= 0 || v4 <= 6 )
  {
    if ( v4 == 5 )
      goto LABEL_9;
  }
  else
  {
    irq_disable_mmio_write(dword_1178B0, dword_1178AC, 2883);
  }
  *(volatile uint32_t *)off_1178A0 = 1 << (v4 + 6);
  return phy_config_table(v4);
}



// radio_irq_clear @ 0x1178b4
/* luna: Dispatches the highest set bit in the 0xF00000 interrupt field to rf_command_handler and writes the captured field, or zero when none is set, to the a */
int radio_irq_clear() {
  unsigned int pending_irq_bits; // r4
  int result; // r0

  pending_irq_bits = *(volatile uint32_t *)off_1178DC & 0xF00000;
  if ( pending_irq_bits )
  {
    result = rf_command_handler((uint8_t)(11 - __clz(pending_irq_bits)));
    *(volatile uint32_t *)off_1178E0 = pending_irq_bits;
  }
  else
  {
    *(volatile uint32_t *)off_1178E0 = 0;
  }
  return result;
}



// critical_section_enter @ 0x1178e4
void critical_section_enter() {
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
    *(volatile uint32_t *)off_117968 = 1;
  }
  v0 = (volatile int *)off_117970;
  v1 = (void *)(uintptr_t)(off_11796C);
  v2 = (void *)(uintptr_t)(off_117974);
  ++*(volatile uint32_t *)off_117970;
  v3 = v1;
  v4 = v2;
  for ( i = 4; i != -1; --i )
  {
    if ( !*((volatile uint8_t *)v3 + 158)
      && ((v1[52] & 1) == 0 || *((volatile uint8_t *)v1 + 190) != (uint8_t)i)
      && *((volatile uint32_t *)v4 + 84) )
    {
      mmio_modify_bit((uint8_t)i);
    }
    v3 -= 7;
    v4 -= 84;
  }
  v6 = *v0;
  v2[511] = 1;
  if ( v6 )
  {
    v7 = v6 - 1;
    v8 = *(volatile uint32_t *)off_117968;
    *v0 = v7;
    if ( !v7 )
    {
      if ( v8 )
        __enable_irq();
    }
  }
}



// critical_section_enter_alt @ 0x117978
int critical_section_enter_alt() {
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
    *(volatile uint32_t *)off_117A58 = 1;
  }
  v0 = (volatile int *)off_117A5C;
  v1 = (void *)(uintptr_t)(off_117A60);
  v2 = (void *)(uintptr_t)(off_117A6C);
  v3 = (void *)(uintptr_t)(off_117A70);
  v4 = dword_117A74;
  v5 = (volatile int *)off_117A78;
  ++*(volatile uint32_t *)off_117A5C;
  v1[511] = 0;
  v6 = v2;
  for ( i = 4; i != -1; --i )
  {
    v8 = (uint8_t)i;
    if ( !*((volatile uint8_t *)v6 + 158) && ((v2[52] & 1) == 0 || *((volatile uint8_t *)v2 + 190) != (uint8_t)i) )
    {
      if ( *((volatile uint32_t *)v1 + 84) )
      {
        adv_type_valid((uint8_t)i);
        *(volatile uint32_t *)(dword_117A64 + 4 * i) = *v3 + *(volatile uint32_t *)(v4 + 4 * i);
        *(volatile uint32_t *)off_117A68 = 1 << i;
        v8 = (uint8_t)i;
        if ( (__get_CPSR() & 1) == 0 )
        {
          __disable_irq();
          *(volatile uint32_t *)off_117A58 = 1;
        }
        v9 = *v0;
        v10 = *v0 + 1;
        v11 = (1 << i) | *v5;
        *v0 = v10;
        *v5 = v11;
        if ( v10 )
        {
          v12 = (volatile int *)off_117A58;
          *v0 = v9;
          v13 = *v12;
          if ( !v9 )
          {
            if ( v13 )
              __enable_irq();
          }
        }
      }
      invalid_handler(v8);
    }
    v6 -= 7;
    v1 -= 84;
  }
  if ( *v0 )
  {
    v14 = *v0 - 1;
    v15 = *(volatile uint32_t *)off_117A58;
    *v0 = v14;
    if ( !v14 )
    {
      if ( v15 )
        __enable_irq();
    }
  }
  return irq_disable_global_2(512);
}



// alloc_shared_ctx @ 0x117a7c
uint64_t alloc_shared_ctx() {
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

  v0 = (void *)(uintptr_t)(off_117B7C);
  v1 = dword_117B80;
  irq_disable_global_3(126976);
  v2 = v0 + 12;
  v3 = v17;
  v0[510] = 1;
  v4 = (int)(v0 + 12);
  v5 = (void *)(v17);
  v6 = 0;
  do
  {
    v7 = (uint8_t)v6;
    clear_stats_buf(v5);
    phy_dispatch((uint8_t)v6++, v1, (int)v5);
    phy_dispatch(v7, v4, (int)v5);
    v1 += 8;
    v5 += 2;
    v4 += 84;
  }
  while ( v6 != 5 );
  v8 = dword_117B74;
  mmio_write(5, dword_117B74);
  init_mac_global_0x1882c8();
  v9 = (void *)(uintptr_t)(init_mac_global_0x188290());
  rx_queue_process((int)v9);
  v10 = *((volatile uint16_t *)v0 + 254);
  memset((volatile int *)(v8 - 432), 0, 0x204u);
  *((volatile uint16_t *)v0 + 254) = v10;
  do
  {
    clear_stats_buf((void *)(v2));
    *((volatile uint32_t *)v2 - 3) = 0;
    v2[14] = 0;
    v2[68] = 0;
    *((volatile uint32_t *)v2 + 6) = 0;
    *((volatile uint32_t *)v2 + 7) = 0;
    v11 = (void *)(v2 + 16);
    v2 += 84;
    clear_stats_buf(v11);
  }
  while ( v2 != (volatile char *)v8 );
  for ( i = 0; i != 5; ++i )
  {
    v13 = list_pop((int)v3);
    if ( v13 )
    {
      do
      {
        phy_enable((int)v13, (uint8_t)i);
        v13 = list_pop((int)v3);
      }
      while ( v13 );
      invalid_handler((uint8_t)i);
    }
    v3 += 8;
  }
  v14 = dword_117B78;
  result = (unsigned int)(dword_117B78 + 1152);
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


// poll_hw_ready @ 0x117b84
int poll_hw_ready(int a1) {
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

  v1 = (void *)(uintptr_t)(off_117BC8);
  v2 = (void *)(uintptr_t)(off_117BCC);
  v3 = a1 - 4;
  v4 = (void *)(uintptr_t)(off_117BC8);
  result = a1 + 12;
  v6 = (volatile int *)off_117BCC;
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



// compare_short @ 0x117bd0
BOOL compare_short(int a1, int a2) {
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



// send_tx_confirmation @ 0x117bf0
int send_tx_confirmation(int result, volatile uint32_t *a2) {
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
    v3 = **(volatile uint8_t **)off_117D6C;
    v4 = result;
    switch ( v3 )
    {
      case 2:
        v6 = (void *)(uintptr_t)(util_call_void());
        if ( v6 )
        {
          v7 = (void *)(uintptr_t)(off_117D98);
          if ( *((volatile uint32_t *)off_117D98 + 2057) )
          {
            v8 = list_pop(dword_117D70);
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
            v14 = (void *)(uintptr_t)(off_117D74);
            *((volatile uint16_t *)v10 + 6) = v11;
            v15 = dword_117D78;
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
              *(volatile uint32_t *)off_117D7C = 1;
            }
            v17 = (volatile int *)off_117D80;
            v18 = *(volatile uint16_t *)(v4 + 32);
            v19 = *a2 & 0xF;
            ++*(volatile uint32_t *)off_117D80;
            alloc_tx_event("cfms: %x, sn=%d, st=%d\r\n", v4, v18, v19);
            co_list_push_back(dword_117D88, v10);
            result = rf_is_idle();
            if ( *v17 )
            {
              v20 = *v17 - 1;
              v21 = *(volatile uint32_t *)off_117D7C;
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
            return debug_printf(aErrTxlCfmNoBuf);
          }
        }
        else
        {
          return debug_printf(aErrNoMsgPkt);
        }
        break;
      case 1:
        v22 = *a2 & 0xF;
        _frame.v24 = v2 & 0x3FFFFFFF;
        _frame.v23 = v22;
        kmalloc(18, (volatile char *)&_frame.v23, 8u, v2 & 0x3FFFFFFF);
        return alloc_tx_event("cfms: %x, sn=%d, st=%d\r\n", v4, *(volatile uint16_t *)(v4 + 32), *a2 & 0xF);
      case 3:
        *(volatile uint32_t *)((volatile uint32_t *)(uintptr_t)off_117D8C)[0] = *a2 & 0xF;
        rf_cmd_wakeup();
        break;
    }
  }
  return result;
}


// init_mac_global_0x188290 @ 0x117d9c
int init_mac_global_0x188290() {
  int v0; // r4

  v0 = dword_117DD4;
  memset((volatile int *)dword_117DD4, 0, 0x28u);
  clear_stats_buf((void *)(uintptr_t)(v0));
  clear_stats_buf((void *)(uintptr_t)(v0 + 8));
  clear_stats_buf((void *)(uintptr_t)(v0 + 16));
  clear_stats_buf((void *)(uintptr_t)(v0 + 24));
  return (int)(uintptr_t)(clear_stats_buf((void *)(uintptr_t)(v0 + 32)));
}



// register_handler @ 0x117dd8
int register_handler(volatile uint32_t *a1, int a2, int a3) {
  int v3; // r3
  int v5; // r0
  int result; // r0

  v3 = a1[19];
  v5 = dword_117E04;
  *(volatile uint32_t *)(v3 + 4) = a2;
  result = co_list_push_back(v5 + 8 * a3, a1);
  if ( (a1[9] & 0x200000) == 0 )
    return irq_disable_global_2(((volatile uint32_t *)(uintptr_t)off_117E08)[a3]);
  return result;
}


