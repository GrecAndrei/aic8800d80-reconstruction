// read_hw_stats @ 0x1219e8
unsigned int read_hw_stats(volatile int *a1) {
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

  v1 = (void *)(uintptr_t)(off_121A60);
  v2 = (void *)(uintptr_t)(off_121A64);
  v3 = (void *)(uintptr_t)(off_121A68);
  v4 = (void *)(uintptr_t)(off_121A6C);
  v5 = (void *)(uintptr_t)(off_121A70);
  v6 = (void *)(uintptr_t)(off_121A74);
  *(volatile uint32_t *)off_121A60 &= ~2u;
  *v1 |= 1u;
  *v2 = 768;
  v7 = *a1;
  v8 = *((volatile uint16_t *)a1 + 2);
  *v5 = 0;
  *v6 = 0;
  *v3 = v7;
  *v4 = v8;
  v9 = (volatile int16_t **)off_121A78;
  v10 = (volatile int *)off_121A7C;
  v11 = dword_121A80;
  *v1 &= 0xFFFFF8FF;
  v12 = *v9;
  *v10 = v11;
  if ( *v12 < 0 && *(volatile uint32_t *)off_121A88 << 28 )
  {
    mmio_field_update(dword_121A90, dword_121A8C, 472);
    v11 = *v10;
  }
  *(volatile uint32_t *)off_121A84 = v11 | v10[1];
  return rf_ant_switch_set(0);
}



// mmio_set_bit_1 @ 0x121a94
unsigned int mmio_set_bit_1() {
  volatile int16_t **v0; // r0
  int v1; // r3
  volatile int *v2; // r4
  int v3; // r2
  unsigned int result; // r0
  int v5; // r1
  volatile uint32_t *v6; // r2

  v0 = (volatile int16_t **)off_121AEC;
  v1 = dword_121AF0;
  *(volatile uint32_t *)off_121AE8 |= 2u;
  v2 = (volatile int *)off_121AF4;
  v3 = **v0;
  *(volatile uint32_t *)off_121AF4 = v1;
  if ( v3 < 0 && *(volatile uint32_t *)off_121B08 << 28 )
  {
    mmio_field_update(dword_121B10, dword_121B0C, 472);
    v1 = *v2;
  }
  *(volatile uint32_t *)off_121AF8 = v1 | v2[1];
  result = rf_ant_switch_set(0);
  v5 = dword_121B00;
  v6 = (void *)(uintptr_t)(off_121B04);
  *(volatile uint32_t *)off_121AFC = dword_121B00;
  *v6 |= v5;
  return result;
}



// mmio_clear_bit @ 0x121b14
unsigned int mmio_clear_bit() {
  volatile int16_t **v0; // r0
  int v1; // r3
  volatile int *v2; // r4
  int v3; // r2
  unsigned int result; // r0
  volatile uint32_t *v5; // r2

  v0 = (volatile int16_t **)off_121B74;
  v1 = dword_121B78;
  *(volatile uint32_t *)off_121B70 &= ~2u;
  v2 = (volatile int *)off_121B7C;
  v3 = **v0;
  *(volatile uint32_t *)off_121B7C = v1;
  if ( v3 < 0 && *(volatile uint32_t *)off_121B90 << 28 )
  {
    mmio_field_update(dword_121B98, dword_121B94, 472);
    v1 = *v2;
  }
  *(volatile uint32_t *)off_121B80 = v1 | v2[1];
  result = rf_ant_switch_set(0);
  v5 = (void *)(uintptr_t)(off_121B88);
  *(volatile uint32_t *)off_121B84 = dword_121B8C;
  *v5 &= 0xFFFBFFFE;
  return result;
}



// phy_read_band @ 0x121b9c
BOOL phy_read_band(int a1, int a2) {
  return *(volatile uint8_t *)(696 * a1 + 12 * a2 + dword_121BBC + 453) != 33;
}



// phy_read_channel @ 0x121bc0
BOOL phy_read_channel(int a1, int a2) {
  return *(volatile uint8_t *)(696 * a1 + 12 * a2 + dword_121BE0 + 452) != 33;
}



// mac_check_hw_state @ 0x121be4
int mac_check_hw_state(int a1) {
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

  v1 = (void *)(uintptr_t)(off_121CB8);
  if ( !*((volatile uint8_t *)off_121CB8 + 48) )
  {
    if ( !a1 )
      return 0;
    v2 = (uint16_t)*(volatile uint32_t *)off_121CBC << 10;
    *((volatile uint8_t *)off_121CB8 + 48) = 1;
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
      *(volatile uint32_t *)off_121CC0 = 1;
    }
    v5 = (volatile int *)off_121CC4;
    v6 = (void *)(uintptr_t)(off_121CC8);
    v7 = *(volatile uint32_t *)off_121CCC;
    ++*(volatile uint32_t *)off_121CC4;
    v8 = v6[4];
    v9 = 32 * v7;
    v10 = v8 + 32 * v7;
    v11 = v2 >> 2;
    if ( v4 <= 0 )
    {
      if ( v3 + v11 >= v9 )
      {
        v19 = dword_121CD0;
        v1[10] = v4;
        ke_event_lock((void *)(uintptr_t)(v19), v10 + 100);
        goto LABEL_12;
      }
    }
    else
    {
      if ( v11 > v9 )
      {
        v17 = v10 + v2 - v11;
        v18 = dword_121CD0;
        v1[10] = v4;
        ke_event_lock((void *)(uintptr_t)(v18), v17);
        goto LABEL_12;
      }
      if ( v3 + 100 > v2 - v9 )
      {
        v12 = v10 - v11;
        v13 = dword_121CD0;
        v1[10] = v4;
        ke_event_lock((void *)(uintptr_t)(v13), v12);
LABEL_12:
        if ( *v5 )
        {
          v14 = *v5 - 1;
          v15 = *(volatile uint32_t *)off_121CC0;
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
    register_irq_handler(v4);
    goto LABEL_12;
  }
  return 0;
}



// mac_wait_fw_ready @ 0x121cd4
int mac_wait_fw_ready() {
  if ( **(volatile int16_t **)off_121D2C < 0 && hci_cmd_send_short(0) != 3 )
    mmio_irq_clear((int)aKeStateGetTask_0, (int)aMmBackToHostId, 1785);
  if ( *((volatile uint8_t *)off_121D30 + 31) && *((volatile uint8_t *)off_121D34 + 18) + *((volatile uint8_t *)off_121D34 + 17) <= 1 )
    return hci_cmd_send(0, 0);
  *(volatile uint32_t *)off_121D38 = 48;
  return hci_cmd_send(0, 1);
}


// mac_cmd_send @ 0x121d44
int mac_cmd_send() {
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

  if ( **(volatile int16_t **)off_121E2C < 0 && hci_cmd_send_short(0) == 4 )
    mmio_irq_clear((int)aKeStateGetTask, (int)aMmForceIdleReq, 1799);
  state_check_feature(4, aForceIdle);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_121E34 = 1;
  }
  v0 = (volatile int *)off_121E64;
  v1 = (volatile int *)off_121E38;
  ++*(volatile uint32_t *)off_121E64;
  v2 = *v1;
  *v1 = 0;
  v3 = (*(volatile uint32_t *)0x40501010u);
  v4 = v2 & 0xF;
  while ( *v1 << 28 )
  {
    rf_irq_clear();
    v5 = (*(volatile uint32_t *)0x40501010u) - v3;
    if ( v5 > 0x7530 )
      state_check_feature(4, aIdleErr);
  }
  v6 = (void *)(uintptr_t)(off_121E44);
  v7 = (void *)(uintptr_t)(off_121E48);
  v8 = *(volatile uint32_t *)off_121E44;
  *((volatile uint32_t *)off_121E40 + 1) &= ~4u;
  if ( v4 && (*v7 & v8 & 4) == 0 )
  {
    while ( (*v7 & *v6 & 4) == 0 )
      ;
  }
  v9 = *((volatile uint8_t *)off_121E4C + 90);
  *(volatile uint32_t *)off_121E50 = 4;
  if ( v9 )
    sleep_critical_enter();
  result = hci_cmd_send(0, 3);
  v11 = *v0;
  *((volatile uint16_t *)off_121E54 + 9) = 0;
  if ( v11 )
  {
    v12 = v11 - 1;
    v13 = *(volatile uint32_t *)off_121E34;
    *v0 = v12;
    if ( !v12 )
    {
      if ( v13 )
        __enable_irq();
    }
  }
  return result;
}


// mac_util_event @ 0x121e68
int mac_util_event() {
  volatile int *v1; // r4
  int v2; // r3
  int v3; // r2

  if ( **(volatile int16_t **)off_121EFC < 0 && (hci_cmd_send_short(0) == 3 || !hci_cmd_send_short(0)) )
    mmio_irq_clear((int)aKeStateGetTask_1, (int)aMmNoIdleStart, 1862);
  if ( hci_cmd_send_short(0) == 2 )
  {
    *(volatile uint32_t *)off_121F00 = 48;
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(volatile uint32_t *)off_121F04 = 1;
    }
    v1 = (volatile int *)off_121F08;
    ++*(volatile uint32_t *)off_121F08;
    set_system_flag_2(0x2000000);
    if ( (*(volatile uint32_t *)off_121F0C & 4) != 0 )
      *(volatile uint32_t *)off_121F10 = 4;
    if ( *v1 )
    {
      v2 = *v1 - 1;
      v3 = *(volatile uint32_t *)off_121F04;
      *v1 = v2;
      if ( !v2 )
      {
        if ( v3 )
          __enable_irq();
      }
    }
  }
  return hci_cmd_send(0, 4);
}


// check_clock_state @ 0x121f1c
int check_clock_state() {
  int result; // r0

  result = hci_cmd_send_short(0);
  if ( result == 4 )
    return hci_cmd_send(0, 1);
  return result;
}


// buffer_alloc @ 0x121f38
int buffer_alloc(int a1, volatile uint8_t *a2, volatile uint8_t *a3) {
  int v6; // r4
  int v8; // r5
  int v9; // r9
  int v10; // r3
  volatile uint8_t *v11; // r3

  v6 = wlc_detach((volatile int *)a1, a2);
  if ( v6 )
    return v6;
  v8 = *(volatile uint8_t *)(a1 + 25);
  v9 = dword_121FB0 + 696 * (uint8_t)*a2;
  *(volatile uint8_t *)(v9 + 669) = 0;
  *(volatile uint16_t *)(v9 + 670) = 0;
  *a3 = rf_set_channel((uint8_t)*a2, v8);
  v10 = *(volatile uint32_t *)(v9 + 44);
  if ( v10 )
    rf_set_channel(*(volatile uint8_t *)(v10 + 35), *(volatile uint8_t *)(a1 + 25));
  v11 = (volatile uint8_t *)(dword_121FB4 + 1320 * v8);
  if ( v11[106] )
    return v6;
  v11[116] = *a2;
  v11[117] = *(volatile uint8_t *)(a1 + 29);
  v11[118] = *(volatile uint8_t *)(a1 + 30);
  return 0;
}



// phy_txpower_calc @ 0x121fb8
int phy_txpower_calc(int a1) {
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
  volatile int *v18; // r2
  int v19; // r1
  volatile char *v20; // r5
  volatile uint32_t *v21; // r6
  uint8_t v22; // r0
  volatile uint32_t *v23; // r1
  volatile uint32_t *v24; // r1
  int v26; // r2
  int v27; // r11
  int v28; // r9
  volatile uint8_t *v29; // r10
  unsigned int v30; // r3
  int v31; // r6
  volatile uint8_t *v32; // r0
  volatile uint32_t *v33; // r3
  int v34; // r2
  int v35; // r1
  volatile uint32_t *v36; // r8
  volatile uint32_t *v37; // r4
  volatile uint32_t *v38; // r10
  int v39; // r9
  volatile uint32_t *v40; // r11
  int v41; // r3
  int v42; // r0
  volatile uint32_t *v43; // r2
  int v44; // r1
  int v45; // [sp+Ch] [bp-8h]

  v1 = dword_12221C;
  v2 = dword_12221C + 696 * a1;
  v3 = *(volatile uint8_t *)(v2 + 34);
  v4 = a1;
  v5 = dword_12221C + 8 * (87 * (int16_t)a1 + 78);
  v6 = 0;
  do
  {
    v7 = (uint8_t)v6++;
    if ( *(volatile uint32_t *)(v2 + 584) )
      rf_calib_config(v7, v5 - 40, 0);
    v8 = *(volatile uint32_t *)(v2 + 624);
    v9 = v5;
    v2 += 8;
    v5 += 8;
    if ( v8 )
      rf_calib_config(v7, v9, 0);
  }
  while ( v6 != 5 );
  v10 = dword_122220;
  v11 = (volatile uint8_t *)(dword_122220 + 1320 * v3);
  v12 = v11[106];
  if ( !v11[106] )
  {
    v11[116] = -1;
LABEL_9:
    v13 = (void *)(uintptr_t)(off_122224);
    v14 = (volatile char *)off_122228;
    v15 = (void *)(uintptr_t)(off_12222C);
    v16 = (void *)(uintptr_t)(off_122230);
    *(volatile uint32_t *)off_122228 = -1;
    *v13 = -1;
    *v15 = 0;
    v17 = (void *)(v13 + 1);
    *v16 = 0;
    *(volatile int *)((volatile char *)v17 + 0xFFFFFFF0) = 0;
    *(volatile uint32_t *)&v14[-4] = 0;
    v18 = v17;
    *v17 = ((uint8_t)(v4 + 16) << 16) | 0x40000000;
    while ( (*v17 & 0x40000000) != 0 )
      ;
    v19 = *(volatile uint32_t *)(v1 + 696 * v4 + 44);
    if ( v19 )
    {
      v20 = (volatile char *)off_122228;
      v21 = (void *)(uintptr_t)(off_122224);
      v22 = *(volatile uint8_t *)(v19 + 35) + 16;
      *(volatile uint32_t *)off_122228 = -1;
      *v21 = -1;
      v23 = (void *)(uintptr_t)(off_122230);
      *(volatile uint32_t *)&v20[-16] = 0;
      *v23 = 0;
      *(volatile uint32_t *)((volatile char *)v21 + 0xFFFFFFF4) = 0;
      v24 = v23 + 5;
      *(volatile uint32_t *)&v20[-4] = 0;
      *v18 = (v22 << 16) | 0x40000000;
      while ( (*v24 & 0x40000000) != 0 )
        ;
    }
    return wlc_phy_cal_init(v4);
  }
  if ( *(volatile uint8_t *)(v1 + 696 * v4 + 36) == 1 )
  {
    v26 = (uint8_t)(v11[234] - 1);
    v11[234] = v26;
    if ( !v26 )
    {
      v27 = (uint8_t)(v11[107] + 32);
      v28 = 696 * v27;
      v29 = (volatile uint8_t *)(v1 + 696 * v27);
      if ( v29[36] )
      {
        v30 = v29[35];
        v29[36] = 0;
        if ( v30 <= 0x1F )
        {
          v32 = (volatile uint8_t *)bt_buf_alloc(73, 13, 0, 2);
          *v32 = v27;
          v32[1] = 0;
          hci_evt_send((int)v32);
          if ( !v29[36] && v29[35] <= 0x1Fu )
          {
            v33 = (void *)(uintptr_t)(off_122238);
            v45 = v4;
            v34 = v10 + 1320 * v29[34];
            v35 = dword_122234 + v28;
            v36 = (volatile uint32_t *)(v1 + v28);
            v37 = (volatile uint32_t *)(v1 + 8 * (87 * (int16_t)v27 + 78));
            v38 = (volatile uint32_t *)(v10 + 8 * (165 * v29[34] + 159));
            v39 = v34;
            v40 = (volatile uint32_t *)v35;
            do
            {
              if ( v36[146] )
              {
                if ( (__get_CPSR() & 1) == 0 )
                {
                  __disable_irq();
                  *(volatile uint32_t *)off_12223C = 1;
                }
                ++*v33;
                ke_event_schedule_1(aCatTobe);
                list_merge(v37 - 10, v38 - 10);
                v41 = v36[147];
                *(volatile uint32_t *)(v39 + 1232) = v36[146];
                *(volatile uint32_t *)(v39 + 1236) = v41;
                zero_struct(v37 - 10);
                v33 = (void *)(uintptr_t)(off_122238);
                v42 = *(volatile uint32_t *)off_122238 - 1;
                if ( *(volatile uint32_t *)off_122238 )
                {
                  v43 = (void *)(uintptr_t)(off_12223C);
                  *(volatile uint32_t *)off_122238 = v42;
                  if ( !v42 )
                  {
                    if ( *v43 )
                      __enable_irq();
                  }
                }
              }
              v44 = v36[156];
              v39 += 8;
              v36 += 2;
              if ( v44 )
              {
                ke_event_schedule_1(aCatPs);
                list_merge(v38, v37);
                zero_struct(v37);
                v33 = (void *)(uintptr_t)(off_122238);
              }
              v37 += 2;
              v38 += 2;
            }
            while ( v37 != v40 );
            v4 = v45;
            set_system_flag_1(512);
          }
        }
      }
      v31 = v10 + 1320 * v3;
      txpwr_cal_entry_get(v31, (uint8_t)(*(volatile uint8_t *)(v31 + 107) + 32));
      v12 = *(volatile uint8_t *)(v31 + 106);
    }
  }
  if ( v12 != 2 )
    goto LABEL_9;
  return wlc_phy_cal_init(v4);
}


// mmio_read_phy @ 0x122248
int mmio_read_phy(int a1) {
  volatile uint8_t *v2; // r0

  v2 = (volatile uint8_t *)bt_buf_alloc(67, 6, 0, 1);
  *v2 = *(volatile uint8_t *)(a1 + 107);
  return (int)(uintptr_t)(hci_evt_send((int)(uintptr_t)(v2)));
}



// tx_rate_set @ 0x122268
int tx_rate_set(int result, int a2, int a3) {
  int v3; // r4

  v3 = result;
  if ( (a2 & 0x800000) != 0 )
  {
    *(volatile uint8_t *)(result + 128) = 0;
  }
  else
  {
    state_check_feature(1024, aBcnLinkloss, a3, a2 << 8);
    return (int)mmio_read_phy(v3);
  }
  return result;
}


// rf_band_select @ 0x122290
int rf_band_select(int a1, int a2) {
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
    v8 = (void *)(uintptr_t)(off_122344);
    v9 = (volatile uint32_t *)((volatile char *)off_122344 + 12);
    *((volatile uint16_t *)off_122344 + 14) = 1793;
    v8[36] = 0;
    *((volatile uint32_t *)v8 + 5) = a1;
    result = ke_event_lock(v9, v7 + 10000);
    *(volatile uint8_t *)(a1 + 115) = 0;
  }
  else
  {
    v3 = (uint8_t)(*(volatile uint8_t *)(a1 + 115) + 1);
    v4 = *(volatile uint32_t *)off_122338;
    *(volatile uint8_t *)(a1 + 115) = v3;
    if ( *(volatile uint8_t *)(v4 + 1) == v3 )
    {
      *(volatile uint8_t *)(a1 + 115) = 0;
      state_check_feature(1024, aSleepLinkloss);
      return (int)mmio_read_phy(a1);
    }
    else if ( *(volatile uint8_t *)(a1 + 108) )
    {
      return bt_get_conn_entry(*(volatile uint8_t *)(a1 + 107), off_122350, a1);
    }
    else
    {
      if ( *((volatile uint8_t *)off_12233C + 2) )
        *(volatile uint32_t *)off_122340 &= ~0x80000000;
      v5 = (void *)(uintptr_t)(off_122344);
      if ( *((volatile uint8_t *)off_122344 + 8) )
        --*((volatile uint8_t *)off_122344 + 8);
      v5[14] = 1;
      result = ke_event_set_lock((int)(uintptr_t)((volatile uint32_t *)dword_122348));
      *(volatile uint32_t *)(a1 + 4) &= ~0x200u;
    }
  }
  return result;
}


// rf_iq_calibrate @ 0x122358
int rf_iq_calibrate(volatile uint8_t *a1, int a2) {
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
    v8 = (volatile uint8_t *)bt_buf_alloc(87, 13, 0, 3);
    *v8 = a1[107];
    v8[1] = v6;
    v8[2] = v7;
    result = (int)(uintptr_t)(hci_evt_send((int)(uintptr_t)(v8)));
LABEL_7:
    a1[145] = v6;
  }
  return result;
}



