// rf_init @ 0x121648
unsigned int rf_init(volatile int *a1) {
  volatile uint32_t *v1; // r3
  volatile uint32_t *v2; // r7
  volatile uint32_t *v3; // r4
  volatile uint32_t *v4; // r1
  volatile uint32_t *v5; // r6
  volatile uint32_t *v6; // r5
  int v7; // r7
  int v8; // r0
  volatile int16_t **v9; // r0
  volatile int *v10; // r4
  int v11; // r2
  volatile int16_t *v12; // r3

  v1 = (void *)(uintptr_t)(off_1216C0);
  v2 = (void *)(uintptr_t)(off_1216C4);
  v3 = (void *)(uintptr_t)(off_1216C8);
  v4 = (void *)(uintptr_t)(off_1216CC);
  v5 = (void *)(uintptr_t)(off_1216D0);
  v6 = (void *)(uintptr_t)(off_1216D4);
  *(volatile uint32_t *)off_1216C0 &= ~2u;
  *v1 |= 1u;
  *v2 = 768;
  v7 = *a1;
  v8 = *((volatile uint16_t *)a1 + 2);
  *v5 = 0;
  *v6 = 0;
  *v3 = v7;
  *v4 = v8;
  v9 = (volatile int16_t **)off_1216D8;
  v10 = (volatile int *)off_1216DC;
  v11 = dword_1216E0;
  *v1 &= 0xFFFFF8FF;
  v12 = *v9;
  *v10 = v11;
  if ( *v12 < 0 && *(volatile uint32_t *)off_1216E8 << 28 )
  {
    mmio_write_field(dword_1216F0, dword_1216EC, 472);
    v11 = *v10;
  }
  *(volatile uint32_t *)off_1216E4 = v11 | v10[1];
  return mmio_reg_update(0);
}



// rf_irq_enable @ 0x1216f4
unsigned int rf_irq_enable() {
  volatile int16_t **v0; // r0
  int v1; // r3
  volatile int *v2; // r4
  int v3; // r2
  unsigned int result; // r0
  int v5; // r1
  volatile uint32_t *v6; // r2

  v0 = (volatile int16_t **)off_12174C;
  v1 = dword_121750;
  *(volatile uint32_t *)off_121748 |= 2u;
  v2 = (volatile int *)off_121754;
  v3 = **v0;
  *(volatile uint32_t *)off_121754 = v1;
  if ( v3 < 0 && *(volatile uint32_t *)off_121768 << 28 )
  {
    mmio_write_field(dword_121770, dword_12176C, 472);
    v1 = *v2;
  }
  *(volatile uint32_t *)off_121758 = v1 | v2[1];
  result = mmio_reg_update(0);
  v5 = dword_121760;
  v6 = (void *)(uintptr_t)(off_121764);
  *(volatile uint32_t *)off_12175C = dword_121760;
  *v6 |= v5;
  return result;
}



// rf_irq_disable_1 @ 0x121774
unsigned int rf_irq_disable_1() {
  volatile int16_t **v0; // r0
  int v1; // r3
  volatile int *v2; // r4
  int v3; // r2
  unsigned int result; // r0
  volatile uint32_t *v5; // r2

  v0 = (volatile int16_t **)off_1217D4;
  v1 = dword_1217D8;
  *(volatile uint32_t *)off_1217D0 &= ~2u;
  v2 = (volatile int *)off_1217DC;
  v3 = **v0;
  *(volatile uint32_t *)off_1217DC = v1;
  if ( v3 < 0 && *(volatile uint32_t *)off_1217F0 << 28 )
  {
    mmio_write_field(dword_1217F8, dword_1217F4, 472);
    v1 = *v2;
  }
  *(volatile uint32_t *)off_1217E0 = v1 | v2[1];
  result = mmio_reg_update(0);
  v5 = (void *)(uintptr_t)(off_1217E8);
  *(volatile uint32_t *)off_1217E4 = dword_1217EC;
  *v5 &= 0xFFFBFFFE;
  return result;
}



// ll_get_tx_power @ 0x1217fc
BOOL ll_get_tx_power(int a1, int a2) {
  return *(volatile uint8_t *)(696 * a1 + 12 * a2 + dword_12181C + 453) != 33;
}



// ll_get_tx_power_alt @ 0x121820
BOOL ll_get_tx_power_alt(int a1, int a2) {
  return *(volatile uint8_t *)(696 * a1 + 12 * a2 + dword_121840 + 452) != 33;
}



// rf_is_ready @ 0x121844
int rf_is_ready(int a1) {
  volatile uint32_t *v1; // r2
  unsigned int v2; // r3
  unsigned int v3; // r6
  int v4; // r4
  volatile int *v5; // r5
  volatile uint32_t *v6; // r7
  int v7; // r0
  int v8; // r1
  unsigned int v9; // r7
  int v10; // r1
  unsigned int v11; // r0
  int v12; // r1
  int v13; // r0
  int v14; // r3
  int v15; // r2
  unsigned int v17; // r1
  int v18; // r0
  int v19; // r0

  v1 = (void *)(uintptr_t)(off_121918);
  if ( !*((volatile uint8_t *)off_121918 + 48) )
  {
    if ( !a1 )
      return 0;
    v2 = (uint16_t)*(volatile uint32_t *)off_12191C << 10;
    *((volatile uint8_t *)off_121918 + 48) = 1;
    v3 = abs32(a1);
    if ( a1 <= 0 )
    {
      if ( v3 <= v2 >> 1 )
        v4 = a1;
      else
        v4 = -(v2 >> 1);
    }
    else
    {
      v4 = v2 >> 1;
      if ( v3 <= v2 >> 1 )
        v4 = a1;
    }
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(volatile uint32_t *)off_121920 = 1;
    }
    v5 = (volatile int *)off_121924;
    v6 = (void *)(uintptr_t)(off_121928);
    v7 = *(volatile uint32_t *)off_12192C;
    ++*(volatile uint32_t *)off_121924;
    v8 = v6[4];
    v9 = 32 * v7;
    v10 = v8 + 32 * v7;
    v11 = v2 >> 2;
    if ( v4 <= 0 )
    {
      if ( v3 + v11 >= v9 )
      {
        v19 = dword_121930;
        v1[10] = v4;
        mem_copy_util((void *)(uintptr_t)(v19), v10 + 100);
        goto LABEL_12;
      }
    }
    else
    {
      if ( v11 > v9 )
      {
        v17 = v10 + v2 - v11;
        v18 = dword_121930;
        v1[10] = v4;
        mem_copy_util((void *)(uintptr_t)(v18), v17);
        goto LABEL_12;
      }
      if ( v3 + 100 > v2 - v9 )
      {
        v12 = v10 - v11;
        v13 = dword_121930;
        v1[10] = v4;
        mem_copy_util((void *)(uintptr_t)(v13), v12);
LABEL_12:
        if ( *v5 )
        {
          v14 = *v5 - 1;
          v15 = *(volatile uint32_t *)off_121920;
          *v5 = v14;
          if ( !v14 )
          {
            if ( v15 )
              __enable_irq();
          }
        }
        return v4;
      }
    }
    alloc_shared_packet(v4);
    goto LABEL_12;
  }
  return 0;
}



// ke_evt_poll @ 0x121934
int ke_evt_poll() {
  if ( **(volatile int16_t **)off_12198C < 0 && hci_cmd_handler(0) != 3 )
    irq_disable_mmio_write((int)aKeStateGetTask_0, (int)aMmBackToHostId, 1785);
  if ( *((volatile uint8_t *)off_121990 + 31) && *((volatile uint8_t *)off_121994 + 18) + *((volatile uint8_t *)off_121994 + 17) <= 1 )
    return hci_cmd_preprocess(0, 0);
  *(volatile uint32_t *)off_121998 = 48;
  return hci_cmd_preprocess(0, 1);
}


// ke_evt_handler @ 0x1219a4
int ke_evt_handler() {
  volatile int *v0; // r8
  volatile int *v1; // r4
  int v2; // r3
  volatile unsigned int v3; // r7
  int v4; // r9
  unsigned int v5; // r3
  volatile uint32_t *v6; // r0
  volatile uint32_t *v7; // r1
  int v8; // r4
  int v9; // r3
  int result; // r0
  int v11; // r3
  int v12; // r3
  int v13; // r2

  if ( **(volatile int16_t **)off_121A8C < 0 && hci_cmd_handler(0) == 4 )
    irq_disable_mmio_write((int)aKeStateGetTask, (int)aMmForceIdleReq, 1799);
  check_feature_flag(4, aForceIdle);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_121A94 = 1;
  }
  v0 = (volatile int *)off_121AC4;
  v1 = (volatile int *)off_121A98;
  ++*(volatile uint32_t *)off_121AC4;
  v2 = *v1;
  *v1 = 0;
  v3 = (*(volatile uint32_t *)0x40501010u);
  v4 = v2 & 0xF;
  while ( *v1 << 28 )
  {
    radio_irq_clear();
    v5 = (*(volatile uint32_t *)0x40501010u) - v3;
    if ( v5 > 0x7530 )
      check_feature_flag(4, aIdleErr);
  }
  v6 = (void *)(uintptr_t)(off_121AA4);
  v7 = (void *)(uintptr_t)(off_121AA8);
  v8 = *(volatile uint32_t *)off_121AA4;
  *((volatile uint32_t *)off_121AA0 + 1) &= ~4u;
  if ( v4 && (*v7 & v8 & 4) == 0 )
  {
    while ( (*v7 & *v6 & 4) == 0 )
      ;
  }
  v9 = *((volatile uint8_t *)off_121AAC + 90);
  *(volatile uint32_t *)off_121AB0 = 4;
  if ( v9 )
    critical_section_enter();
  result = hci_cmd_preprocess(0, 3);
  v11 = *v0;
  *((volatile uint16_t *)off_121AB4 + 9) = 0;
  if ( v11 )
  {
    v12 = v11 - 1;
    v13 = *(volatile uint32_t *)off_121A94;
    *v0 = v12;
    if ( !v12 )
    {
      if ( v13 )
        __enable_irq();
    }
  }
  return result;
}


// ke_evt_peek @ 0x121ac8
int ke_evt_peek() {
  volatile int *v1; // r4
  int v2; // r3
  int v3; // r2

  if ( **(volatile int16_t **)off_121B5C < 0 && (hci_cmd_handler(0) == 3 || !hci_cmd_handler(0)) )
    irq_disable_mmio_write((int)aKeStateGetTask_1, (int)aMmNoIdleStart, 1862);
  if ( hci_cmd_handler(0) == 2 )
  {
    *(volatile uint32_t *)off_121B60 = 48;
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(volatile uint32_t *)off_121B64 = 1;
    }
    v1 = (volatile int *)off_121B68;
    ++*(volatile uint32_t *)off_121B68;
    irq_disable_global_3(0x2000000);
    if ( (*(volatile uint32_t *)off_121B6C & 4) != 0 )
      *(volatile uint32_t *)off_121B70 = 4;
    if ( *v1 )
    {
      v2 = *v1 - 1;
      v3 = *(volatile uint32_t *)off_121B64;
      *v1 = v2;
      if ( !v2 )
      {
        if ( v3 )
          __enable_irq();
      }
    }
  }
  return hci_cmd_preprocess(0, 4);
}


// check_config_flag @ 0x121b7c
int check_config_flag() {
  int result; // r0

  result = hci_cmd_handler(0);
  if ( result == 4 )
    return hci_cmd_preprocess(0, 1);
  return result;
}


// ke_send_msg @ 0x121b98
int ke_send_msg(int a1, volatile uint8_t *a2, volatile uint8_t *a3) {
  int v6; // r4
  int v8; // r5
  int v9; // r9
  int v10; // r0
  int v11; // r3
  volatile uint8_t *v12; // r3
  int v13; // r1

  v6 = is_controller_active((volatile int *)a1, a2);
  if ( v6 )
    return v6;
  v8 = *(volatile uint8_t *)(a1 + 25);
  v9 = dword_121C34 + 696 * (uint8_t)*a2;
  *(volatile uint8_t *)(v9 + 669) = 0;
  *(volatile uint16_t *)(v9 + 670) = 0;
  v10 = ll_tx_setup((uint8_t)*a2, v8);
  *a3 = v10;
  v11 = *(volatile uint32_t *)(v9 + 44);
  if ( v11 )
    v10 = ll_tx_setup(*(volatile uint8_t *)(v11 + 35), *(volatile uint8_t *)(a1 + 25));
  v12 = (volatile uint8_t *)(dword_121C38 + 1320 * v8);
  if ( v12[106] )
  {
    if ( (uint8_t)*a2 <= 0x1Fu && v12[106] == 2 && !v12[1224] )
    {
      v13 = *(volatile uint8_t *)off_121C40;
      ++*(volatile uint8_t *)off_121C3C;
      if ( v13 == 1 )
        rf_rate_code_check_alt(v10);
    }
    return v6;
  }
  v12[116] = *a2;
  v12[117] = *(volatile uint8_t *)(a1 + 29);
  v12[118] = *(volatile uint8_t *)(a1 + 30);
  return 0;
}



// ll_channel_hop @ 0x121c44
int ll_channel_hop(int a1) {
  int v1; // r5
  int v2; // r7
  int v3; // r6
  int v4; // r4
  int v5; // r9
  int v6; // r8
  unsigned int v7; // r10
  int v8; // r3
  int v9; // r1
  int v10; // r7
  volatile uint8_t *v11; // r3
  int v12; // r1
  volatile uint32_t *v13; // r1
  volatile char *v14; // r0
  volatile uint32_t *v15; // r7
  volatile uint32_t *v16; // r6
  volatile int *v17; // r1
  int v18; // r2
  volatile char *v19; // r5
  volatile uint32_t *v20; // r6
  uint8_t v21; // r0
  volatile uint32_t *v22; // r1
  unsigned int v23; // r0
  int v25; // r11
  int v26; // r9
  volatile uint8_t *v27; // r10
  unsigned int v28; // r3
  int v29; // r6
  volatile uint8_t *v30; // r0
  volatile uint32_t *v31; // r3
  int v32; // r2
  int v33; // r1
  volatile uint32_t *v34; // r8
  volatile uint32_t *v35; // r4
  volatile uint32_t *v36; // r10
  int v37; // r9
  volatile uint32_t *v38; // r11
  int v39; // r3
  int v40; // r0
  volatile uint32_t *v41; // r2
  int v42; // r1
  int v43; // [sp+Ch] [bp-8h]

  v1 = dword_121EA8;
  v2 = dword_121EA8 + 696 * a1;
  v3 = *(volatile uint8_t *)(v2 + 34);
  v4 = a1;
  v5 = dword_121EA8 + 8 * (87 * (int16_t)a1 + 78);
  v6 = 0;
  do
  {
    v7 = (uint8_t)v6++;
    if ( *(volatile uint32_t *)(v2 + 584) )
      phy_dispatch(v7, v5 - 40, 0);
    v8 = *(volatile uint32_t *)(v2 + 624);
    v9 = v5;
    v2 += 8;
    v5 += 8;
    if ( v8 )
      phy_dispatch(v7, v9, 0);
  }
  while ( v6 != 5 );
  v10 = dword_121EAC;
  v11 = (volatile uint8_t *)(dword_121EAC + 1320 * v3);
  v12 = v11[106];
  if ( v11[106] )
  {
    v18 = *(volatile uint8_t *)(v1 + 696 * v4 + 36);
    if ( v18 == 1 )
    {
      v18 = (uint8_t)(v11[234] - 1);
      v11[234] = v18;
      if ( !v18 )
      {
        v25 = (uint8_t)(v11[107] + 32);
        v26 = 696 * v25;
        v27 = (volatile uint8_t *)(v1 + 696 * v25);
        if ( v27[36] )
        {
          v28 = v27[35];
          v27[36] = 0;
          if ( v28 <= 0x1F )
          {
            v30 = (volatile uint8_t *)tx_send_pdu(73, 13, 0, 2);
            *v30 = v25;
            v30[1] = 0;
            rx_process_packet_1((int)v30);
            if ( !v27[36] && v27[35] <= 0x1Fu )
            {
              v31 = (void *)(uintptr_t)(off_121EC4);
              v43 = v4;
              v32 = v10 + 1320 * v27[34];
              v33 = dword_121EC0 + v26;
              v34 = (volatile uint32_t *)(v1 + v26);
              v35 = (volatile uint32_t *)(v1 + 8 * (87 * (int16_t)v25 + 78));
              v36 = (volatile uint32_t *)(v10 + 8 * (165 * v27[34] + 159));
              v37 = v32;
              v38 = (volatile uint32_t *)v33;
              do
              {
                if ( v34[146] )
                {
                  if ( (__get_CPSR() & 1) == 0 )
                  {
                    __disable_irq();
                    *(volatile uint32_t *)off_121EC8 = 1;
                  }
                  ++*v31;
                  alloc_tx_event(aCatTobe);
                  get_ptr_value(v35 - 10, v36 - 10);
                  v39 = v34[147];
                  *(volatile uint32_t *)(v37 + 1232) = v34[146];
                  *(volatile uint32_t *)(v37 + 1236) = v39;
                  clear_stats_buf(v35 - 10);
                  v31 = (void *)(uintptr_t)(off_121EC4);
                  v40 = *(volatile uint32_t *)off_121EC4 - 1;
                  if ( *(volatile uint32_t *)off_121EC4 )
                  {
                    v41 = (void *)(uintptr_t)(off_121EC8);
                    *(volatile uint32_t *)off_121EC4 = v40;
                    if ( !v40 )
                    {
                      if ( *v41 )
                        __enable_irq();
                    }
                  }
                }
                v42 = v34[156];
                v37 += 8;
                v34 += 2;
                if ( v42 )
                {
                  alloc_tx_event(aCatPs);
                  get_ptr_value(v36, v35);
                  clear_stats_buf(v35);
                  v31 = (void *)(uintptr_t)(off_121EC4);
                }
                v35 += 2;
                v36 += 2;
              }
              while ( v35 != v38 );
              v4 = v43;
              irq_disable_global_2(512);
            }
          }
        }
        v29 = v10 + 1320 * v3;
        rf_get_rate_table_index(v29, (uint8_t)(*(volatile uint8_t *)(v29 + 107) + 32));
        v12 = *(volatile uint8_t *)(v29 + 106);
      }
    }
    if ( v12 == 2 )
    {
      v23 = v4;
      return get_connection_tx_power(v23, v12, v18, (int)v11);
    }
  }
  else
  {
    v11[116] = -1;
  }
  v13 = (void *)(uintptr_t)(off_121EB0);
  v14 = (volatile char *)off_121EB4;
  v15 = (void *)(uintptr_t)(off_121EB8);
  v16 = (void *)(uintptr_t)(off_121EBC);
  *(volatile uint32_t *)off_121EB4 = -1;
  *v13 = -1;
  *v15 = 0;
  v17 = (void *)(v13 + 1);
  *v16 = 0;
  *(volatile int *)((volatile char *)v17 + 0xFFFFFFF0) = 0;
  *(volatile uint32_t *)&v14[-4] = 0;
  v18 = (int)v17;
  *v17 = ((uint8_t)(v4 + 16) << 16) | 0x40000000;
  do
    v11 = (volatile uint8_t *)(*v17 & 0x40000000);
  while ( v11 );
  v12 = *(volatile uint32_t *)(v1 + 696 * v4 + 44);
  if ( v12 )
  {
    v19 = (volatile char *)off_121EB4;
    v20 = (void *)(uintptr_t)(off_121EB0);
    v21 = *(volatile uint8_t *)(v12 + 35) + 16;
    *(volatile uint32_t *)off_121EB4 = -1;
    *v20 = -1;
    v22 = (void *)(uintptr_t)(off_121EBC);
    *(volatile uint32_t *)&v19[-16] = 0;
    *v22 = 0;
    *(volatile uint32_t *)((volatile char *)v20 + 0xFFFFFFF4) = 0;
    v12 = (int)(v22 + 5);
    *(volatile uint32_t *)&v19[-4] = 0;
    *(volatile uint32_t *)v18 = (v21 << 16) | 0x40000000;
    do
      v11 = (volatile uint8_t *)(2 * *(volatile uint32_t *)v12);
    while ( (*(volatile uint32_t *)v12 & 0x40000000) != 0 );
  }
  v23 = v4;
  return get_connection_tx_power(v23, v12, v18, (int)v11);
}


// rf_read_reg @ 0x121ed4
int rf_read_reg(int a1) {
  volatile uint8_t *v2; // r0

  v2 = (volatile uint8_t *)tx_send_pdu(67, 6, 0, 1);
  *v2 = *(volatile uint8_t *)(a1 + 107);
  return (int)(uintptr_t)(rx_process_packet_1((int)(uintptr_t)(v2)));
}



// rf_set_channel_2 @ 0x121ef4
int rf_set_channel_2(int result, int a2, int a3) {
  int v3; // r4

  v3 = result;
  if ( (a2 & 0x800000) != 0 )
  {
    *(volatile uint8_t *)(result + 128) = 0;
  }
  else
  {
    check_feature_flag(1024, aBcnLinkloss, a3, a2 << 8);
    return (int)rf_read_reg(v3);
  }
  return result;
}


// rf_set_rx_mode @ 0x121f1c
int rf_set_rx_mode(int a1, int a2) {
  int v3; // r3
  int v4; // r2
  volatile uint16_t *v5; // r3
  int result; // r0
  volatile unsigned int v7; // r1
  volatile uint8_t *v8; // r3
  volatile uint32_t *v9; // r0

  if ( (a2 & 0x800000) != 0 )
  {
    *(volatile uint8_t *)(a1 + 128) = 0;
    v7 = (*(volatile uint32_t *)0x40501010u);
    v8 = (void *)(uintptr_t)(off_121FD0);
    v9 = (volatile uint32_t *)((volatile char *)off_121FD0 + 12);
    *((volatile uint16_t *)off_121FD0 + 14) = 1793;
    v8[36] = 0;
    *((volatile uint32_t *)v8 + 5) = a1;
    result = mem_copy_util(v9, v7 + 10000);
    *(volatile uint8_t *)(a1 + 115) = 0;
  }
  else
  {
    v3 = (uint8_t)(*(volatile uint8_t *)(a1 + 115) + 1);
    v4 = *(volatile uint32_t *)off_121FC4;
    *(volatile uint8_t *)(a1 + 115) = v3;
    if ( *(volatile uint8_t *)(v4 + 1) == v3 )
    {
      *(volatile uint8_t *)(a1 + 115) = 0;
      check_feature_flag(1024, aSleepLinkloss);
      return (int)rf_read_reg(a1);
    }
    else if ( *(volatile uint8_t *)(a1 + 108) )
    {
      return get_bt_device_state(*(volatile uint8_t *)(a1 + 107), off_121FDC, a1);
    }
    else
    {
      if ( *((volatile uint8_t *)off_121FC8 + 2) )
        *(volatile uint32_t *)off_121FCC &= ~0x80000000;
      v5 = (void *)(uintptr_t)(off_121FD0);
      if ( *((volatile uint8_t *)off_121FD0 + 8) )
        --*((volatile uint8_t *)off_121FD0 + 8);
      v5[14] = 1;
      result = mem_set_util((int)(uintptr_t)((volatile uint32_t *)dword_121FD4));
      *(volatile uint32_t *)(a1 + 4) &= ~0x200u;
    }
  }
  return result;
}


// set_rf_tx_power_compensation @ 0x121fe4
int set_rf_tx_power_compensation(volatile uint8_t *a1, int a2) {
  int v2; // r3
  int result; // r0
  char v5; // r2
  int v6; // r6
  char v7; // r5
  volatile uint8_t *v8; // r0

  v2 = (char)a1[143];
  result = (char)a1[142];
  v5 = a1[144];
  v6 = (uint8_t)a1[145];
  a1[142] = a2;
  if ( v2 )
  {
    v7 = a2;
    if ( v6 )
    {
      if ( v6 != 1 || result >= a2 || a2 <= v2 + v5 )
        goto LABEL_7;
      v6 = (v6 & ~0xFFu) | ((uint8_t)(0) & 0xFFu);
    }
    else
    {
      if ( result <= a2 || a2 >= v2 - v5 )
        goto LABEL_7;
      v6 = (v6 & ~0xFFu) | ((uint8_t)(1) & 0xFFu);
    }
    v8 = (volatile uint8_t *)tx_send_pdu(87, 13, 0, 3);
    *v8 = a1[107];
    v8[1] = v6;
    v8[2] = v7;
    result = (int)(uintptr_t)(rx_process_packet_1((int)(uintptr_t)(v8)));
LABEL_7:
    a1[145] = v6;
  }
  return result;
}



