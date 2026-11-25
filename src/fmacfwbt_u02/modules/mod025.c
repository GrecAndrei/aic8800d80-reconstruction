// wlc_ucode_download @ 0x11f82c
int wlc_ucode_download(int result) {
  int v1; // r4
  volatile int *v2; // r2
  unsigned int v3; // r1
  volatile uint32_t *v4; // r3
  volatile uint32_t *v5; // r0
  int v6; // r1
  volatile int *v7; // r6
  volatile uint32_t *v8; // r5
  volatile unsigned int v9; // r8
  unsigned int v10; // r3
  volatile unsigned int v11; // r10
  volatile uint32_t *v12; // r9
  volatile uint32_t *v13; // r8
  unsigned int v14; // r3
  int v15; // r5
  int v16; // r3
  int v17; // r2
  volatile uint32_t *v18; // r5
  int v19; // r2
  int v20; // r3
  volatile uint32_t *v21; // r2
  int v22; // r1

  v1 = result;
  if ( *(volatile uint8_t *)(result + 1224) )
    result = (int)(uintptr_t)(bt_conn_flush(result));
  if ( *(volatile uint32_t *)(v1 + 72) )
    result = hci_le_event_proc(v1);
  if ( (*(volatile uint32_t *)(v1 + 4) & 1) != 0 )
  {
    if ( (*(volatile uint32_t *)off_11F9C8 & 0x2000000) != 0 || (result = *(volatile uint32_t *)off_11F9C8 << 6, *((volatile uint8_t *)off_11F9CC + 36)) )
    {
      result = state_check_feature(2, "M,%d\r\n", *(volatile uint8_t *)(v1 + 128));
      v2 = (volatile int *)off_11F9D4;
      v3 = *((volatile uint8_t *)off_11F9D4 + 1);
      *(volatile uint32_t *)(v1 + 4) &= ~1u;
      *v2 = v3 > 1;
      if ( BYTE2(((volatile uint32_t *)(uintptr_t)off_11F9D8)[47]) )
      {
        if ( **(volatile uint8_t **)off_11F9DC == 2 )
        {
          result = sleep_critical_exit();
          v4 = (void *)(uintptr_t)(off_11F9E0);
          *(volatile uint32_t *)off_11F9E0 &= ~1u;
          *v4 &= ~0x80u;
          if ( *(volatile uint8_t *)(v1 + 128) > 9u )
          {
            v5 = (void *)(uintptr_t)(off_11F9E4);
            v6 = dword_11F9E8;
            *(volatile uint32_t *)off_11F9C8 &= ~4u;
            if ( (*v5 & v6) == 0 )
              log_and_check_hw();
            if ( *(volatile uint32_t *)off_11F9EC << 28 )
            {
              if ( (__get_CPSR() & 1) == 0 )
              {
                __disable_irq();
                *(volatile uint32_t *)off_11F9F0 = 1;
              }
              v7 = (volatile int *)off_11F9F4;
              v8 = (void *)(uintptr_t)(off_11F9EC);
              ++*(volatile uint32_t *)off_11F9F4;
              *v8 = 0;
              v9 = (*(volatile uint32_t *)0x40501010u);
              while ( *v8 << 28 )
              {
                v10 = (*(volatile uint32_t *)0x40501010u) - v9;
                if ( v10 > 0x7530 )
                  state_check_feature(2, aIdleErr, 30000);
              }
              v11 = (*(volatile uint32_t *)0x40501010u);
              if ( (*(volatile uint32_t *)off_11F9FC & *(volatile uint32_t *)off_11FA00 & 4) == 0 )
              {
                v12 = (void *)(uintptr_t)(off_11F9FC);
                v13 = (void *)(uintptr_t)(off_11FA00);
                do
                {
                  v14 = (*(volatile uint32_t *)0x40501010u) - v11;
                  v15 = *v12 & *v13;
                  if ( v14 > 0x7530 )
                    state_check_feature(2, aIdleIntErr);
                }
                while ( (v15 & 4) == 0 );
              }
              *(volatile uint32_t *)off_11FA08 = 4;
              if ( *v7 )
              {
                v16 = *v7 - 1;
                v17 = *(volatile uint32_t *)off_11F9F0;
                *v7 = v16;
                if ( !v16 )
                {
                  if ( v17 )
                    __enable_irq();
                }
              }
            }
            v18 = (void *)(uintptr_t)(off_11FA10);
            v19 = **(volatile int16_t **)off_11FA0C;
            v20 = *((volatile uint32_t *)off_11FA10 + 1) | 0x200;
            *((volatile uint32_t *)off_11FA10 + 1) = v20;
            if ( v19 < 0 )
            {
              if ( *(volatile uint32_t *)off_11F9EC << 28 )
              {
                mmio_field_update((int)aNxmacCurrentSt, (int)aMmRxFilterSet_0, 472);
                v20 = v18[1];
              }
            }
            v21 = (void *)(uintptr_t)(off_11F9EC);
            v22 = off_11FA18;
            *(volatile uint32_t *)off_11FA14 = v20 | *v18;
            *v21 = 48;
            return bt_get_conn_entry(*(volatile uint8_t *)(v1 + 107), v22, v1);
          }
        }
      }
    }
  }
  return result;
}


// si_secure_check @ 0x11fa28
void si_secure_check() {
  volatile uint8_t *v0; // r3
  unsigned int v1; // r2

  v0 = *((volatile uint8_t **)off_11FA54 + 2);
  if ( !v0[106] && v0[108] && v0[117] )
  {
    v1 = (uint8_t)v0[118];
    if ( v1 <= 8 )
      *(volatile uint32_t *)off_11FA58 = ((1 << v1) - 1) << 8;
  }
}



// si_attach @ 0x11fa5c
int si_attach() {
  volatile uint32_t *v0; // r8
  int v1; // r4
  void *v2; // r7
  int v3; // r6
  volatile uint32_t *v4; // r1
  int result; // r0

  v0 = (void *)(uintptr_t)(off_11FAC0);
  memset((volatile int *)off_11FAC0, 0, 0x18u);
  zero_struct(v0);
  v1 = dword_11FAC4;
  v2 = (void *)(uintptr_t)(off_11FAC8);
  zero_struct(v0 + 2);
  v3 = v1 + 5280;
  do
  {
    memset((volatile int *)v1, 0, 0x528u);
    *(volatile uint32_t *)(v1 + 52) = (int)(uintptr_t)(v2);
    *(volatile uint32_t *)(v1 + 56) = v1;
    *(volatile uint8_t *)(v1 + 106) = 5;
    *(volatile uint8_t *)(v1 + 109) = 127;
    *(volatile uint8_t *)(v1 + 110) = 127;
    v4 = (volatile uint32_t *)v1;
    v1 += 1320;
    result = check_abort_flag((int)v0, v4);
  }
  while ( v1 != v3 );
  *((volatile uint8_t *)v0 + 16) = -1;
  return result;
}


// si_detach @ 0x11facc
int si_detach() {
  volatile uint32_t *i; // r5
  volatile uint32_t *j; // r4
  int result; // r0

  for ( i = *((volatile uint32_t **)off_11FAF4 + 2); i; i = (volatile uint32_t *)*i )
  {
    for ( j = (volatile uint32_t *)i[60]; j; j = (volatile uint32_t *)*j )
      result = wlc_bsscfg_down((int)i, (int)j, 0);
  }
  return result;
}



// wlc_ioctl @ 0x11faf8
int wlc_ioctl(int a1, int a2, int a3, volatile uint8_t *a4) {
  int v4; // r9
  volatile int **v5; // r4
  int result; // r0
  int v7; // r6
  int v8; // r7
  int v9; // r8
  int v10; // r11
  int v11; // r5
  int v12; // r10
  volatile int *v13; // r3
  volatile int *v14; // r1
  volatile int *v15; // r2
  volatile uint32_t *v16; // r0
  int v17; // r2
  int v18; // r4
  char v19; // r3
  int v20; // r3
  int v21; // r2
  int v22; // r3
  int v23; // r3
  volatile uint32_t *v24; // r5
  int v25; // r1
  int v26; // r2
  int v27; // r0
  volatile uint32_t *v28; // r5
  volatile uint32_t *v29; // r0
  int v30; // r2
  int v31; // r3
  volatile uint32_t *v32; // r3
  int v33; // zf
  int v34; // r0
  int v35; // r1
  int v36; // r0
  volatile int16_t **v37; // r3
  char v38; // r2
  int v39; // r5
  int v40; // r3
  int v41; // r6
  volatile int *v42; // r5
  int v43; // r3
  int v44; // r2
  int v45; // r2
  void *v46; // r2
  int v47; // r0
  struct __attribute__((packed)) { int v52; // [sp+20h] [bp-1Ch]
  int v53; // [sp+24h] [bp-18h]
  char _pad2[3]; uint8_t a2a; // [sp+2Bh] [bp-11h] BYREF
  uint8_t v55[4]; // [sp+2Ch] [bp-10h] BYREF
  int v56; // [sp+30h] [bp-Ch]
  } _frame;
  v4 = off_11FE34;
  if ( !*(volatile uint32_t *)off_11FE34 )
    return 1;
  if ( a3 )
  {
    if ( a2 == 2 && *(volatile uint8_t *)off_11FE90 )
      return 1;
    v5 = *(volatile int ***)(off_11FE34 + 8);
    if ( v5 )
    {
      if ( *(volatile uint8_t *)(off_11FE34 + 0x13) == 2 )
        return 1;
      goto LABEL_8;
    }
LABEL_52:
    read_hw_stats((volatile int *)a1);
    goto LABEL_11;
  }
  v5 = *(volatile int ***)(off_11FE34 + 8);
  if ( !v5 )
    goto LABEL_52;
LABEL_8:
  v7 = *(volatile uint32_t *)a1;
  _frame.v52 = *(volatile uint32_t *)a1;
  v8 = 0;
  _frame.v53 = *(volatile uint16_t *)(a1 + 4);
  v9 = 0;
  v10 = _frame.v53;
  do
  {
    v11 = (int)v5[25];
    v12 = *((volatile uint16_t *)v5 + 52);
    ke_event_schedule_1(aMacIsXXP2pD, v11, v12, *((volatile uint8_t *)v5 + 1224));
    v5 = (volatile int **)*v5;
    v9 |= v11 ^ v7;
    v7 &= v11;
    v8 |= v12 ^ v10;
    v10 &= v12;
  }
  while ( v5 );
  v13 = (volatile int *)off_11FE24;
  v14 = (volatile int *)off_11FE28;
  v15 = (volatile int *)off_11FE2C;
  *(volatile uint32_t *)off_11FE20 = v8 | 0x300;
  *v13 = v9;
  *v14 = _frame.v52;
  *v15 = _frame.v53;
  ke_event_schedule_1("set mac:%x,%x, mask:%x,%x,p2p=%d\r\n", _frame.v52, _frame.v53, v9, v8, a3);
LABEL_11:
  v16 = list_pop_front(off_11FE34);
  v17 = dword_11FE38;
  *((volatile uint8_t *)v16 + 106) = a2;
  v18 = (int)v16;
  v19 = dword_11FE3C;
  v16[25] = *(volatile uint32_t *)a1;
  *((volatile uint16_t *)v16 + 52) = *(volatile uint16_t *)(a1 + 4);
  v20 = (uint8_t)(v19 * (((int)v16 - v17) >> 3));
  *((volatile uint8_t *)v16 + 1224) = a3;
  v21 = dword_11FE40;
  v16[3] = 2627;
  v16[4] = v21;
  v16[5] = dword_11FE44;
  *((volatile uint16_t *)v16 + 611) = 1023;
  v16[2] = 2631;
  *((volatile uint8_t *)v16 + 107) = v20;
  *((volatile uint8_t *)v16 + 84) = v20;
  *((volatile uint8_t *)v16 + 109) = 127;
  *((volatile uint8_t *)v16 + 110) = 127;
  v16[18] = 0;
  *((volatile uint8_t *)v16 + 140) = 0;
  if ( a2 == 2 )
  {
    v38 = *(volatile uint8_t *)(v4 + 0x12);
    if ( v38 )
    {
      v39 = a3;
    }
    else
    {
      mmio_set_bit_1();
      v38 = *(volatile uint8_t *)(v4 + 0x12);
      v20 = *(volatile uint8_t *)(v18 + 107);
      v39 = *(volatile uint8_t *)(v18 + 1224);
    }
    v40 = dword_11FE7C + 696 * (v20 + 32);
    *(volatile uint8_t *)(v4 + 0x12) = v38 + 1;
    *(volatile uint8_t *)(v40 + 37) = 1;
    if ( v39 )
    {
      *(volatile uint32_t *)(v18 + 28) = off_11FE80;
      *(volatile uint32_t *)(v18 + 32) = v18;
    }
    memory_pool_init(v18);
    v22 = *(volatile uint8_t *)(v4 + 0x11);
  }
  else if ( a2 == 4 )
  {
    if ( *(volatile uint8_t *)(v4 + 0x10) != 255 )
      return 1;
    v41 = *(volatile uint32_t *)(v4 + 8);
    *(volatile uint8_t *)(v4 + 0x10) = v20;
    if ( v41 )
    {
      v42 = (volatile int *)off_11FE4C;
      v43 = dword_11FE84;
      v44 = **(volatile int16_t **)off_11FE48;
      *(volatile uint32_t *)off_11FE4C = dword_11FE84;
      if ( v44 < 0 && *(volatile uint32_t *)off_11FEE0 << 28 )
      {
        mmio_field_update((int)aNxmacCurrentSt, (int)aMmRxFilterSet_0, 472);
        v43 = *v42;
      }
      v45 = *(volatile uint32_t *)(v41 + 72);
      *(volatile uint32_t *)off_11FE50 = v43 | v42[1];
      if ( v45 )
        get_current_entry_owner(*(volatile uint8_t *)(v45 + 24));
      v22 = *(volatile uint8_t *)(v4 + 0x11);
    }
    else
    {
      *(volatile uint32_t *)_frame.v55 = dword_11FEEC;
      _frame.v56 = 2437;
      mmio_disable_irq();
      if ( find_free_conn(_frame.v55, &_frame.a2a) )
        return 1;
      v47 = _frame.a2a;
      *(volatile uint32_t *)(v18 + 4) |= 0x80u;
      get_current_entry_owner(v47);
      v22 = *(volatile uint8_t *)(v4 + 0x11);
    }
  }
  else
  {
    v22 = *(volatile uint8_t *)(v4 + 0x11);
    if ( !a2 )
    {
      v16[7] = off_11FE88;
      v46 = (void *)(uintptr_t)(off_11FE8C);
      v16[8] = (int)(uintptr_t)(v16);
      v22 = (uint8_t)(v22 + 1);
      *((volatile uint16_t *)v16 + 73) = 0;
      v16[40] = (int)(uintptr_t)(v16);
      *(volatile uint8_t *)(v4 + 0x11) = v22;
      *((volatile uint8_t *)v16 + 116) = -1;
      v16[39] = (int)(uintptr_t)(v46);
    }
  }
  v23 = v22 + *(volatile uint8_t *)(v4 + 0x12);
  if ( v23 > 1 || *(volatile uint8_t *)(v4 + 0x12) )
  {
    v24 = (void *)(uintptr_t)(off_11FE4C);
    v25 = **(volatile int16_t **)off_11FE48;
    v26 = *((volatile uint32_t *)off_11FE4C + 1) | 0x100;
    *((volatile uint32_t *)off_11FE4C + 1) = v26;
    if ( v25 < 0 && *(volatile uint32_t *)off_11FE70 << 28 )
    {
      mmio_field_update((int)aNxmacCurrentSt, (int)aMmRxFilterSet_0, 472);
      v26 = v24[1];
      v23 = *(volatile uint8_t *)(v4 + 0x11) + *(volatile uint8_t *)(v4 + 0x12);
    }
    *(volatile uint32_t *)off_11FE50 = v26 | *v24;
  }
  if ( v23 == 1 )
    *(volatile uint32_t *)off_11FE54 |= 1u;
  if ( a3 )
  {
    v34 = *(volatile uint8_t *)(v18 + 107);
    v35 = a2;
    if ( a2 )
      v35 = 1;
    ++*(volatile uint8_t *)(v4 + 0x13);
    v36 = poll_ready(v34, v35);
    v37 = (volatile int16_t **)off_11FE48;
    *(volatile uint8_t *)(v18 + 1225) = v36;
    if ( **v37 < 0 && v36 == 255 )
      mmio_irq_clear((int)aVifP2pIndexP2p, (int)aVifMgmtRegiste_0, 498);
  }
  v27 = dword_11FE58;
  *a4 = *(volatile uint8_t *)(v18 + 107);
  check_abort_flag(v27, (volatile uint32_t *)v18);
  v28 = (volatile uint32_t *)(v18 + 1232);
  do
  {
    zero_struct(v28);
    v29 = v28 + 10;
    v28 += 2;
    zero_struct(v29);
  }
  while ( v28 != (volatile uint32_t *)(v18 + 1272) );
  zero_struct((volatile uint32_t *)(v18 + 1312));
  v30 = *(volatile uint8_t *)(v4 + 0x12);
  v31 = *(volatile uint8_t *)(v4 + 0x11) + v30;
  *(volatile uint32_t *)off_11FE5C = 0;
  if ( v31 <= 1 )
  {
    si_secure_check();
    v30 = *(volatile uint8_t *)(v4 + 0x12);
    v31 = *(volatile uint8_t *)(v4 + 0x11) + v30;
  }
  state_check_feature(256, "%s:%d,%d,%d,%d,%d\r\n", aVifMgmtRegiste, v31, v30, a2, a3, *a4);
  v32 = (volatile uint32_t *)(*(volatile uint8_t *)(v4 + 0x12) + *(volatile uint8_t *)(v4 + 0x11));
  v33 = v32 == (volatile uint32_t *)1;
  if ( v32 == (volatile uint32_t *)1 )
    v32 = (void *)(uintptr_t)(off_11FE20);
  result = 0;
  if ( v33 )
    *v32 = 0;
  return result;
}


// wlc_phy_attach @ 0x11fef0
int wlc_phy_attach(int a1) {
  int v2; // r6
  volatile int *v3; // r8
  int v4; // r3
  volatile uint8_t *v5; // r5
  int v6; // r2
  int v7; // r3
  int v8; // r3
  int v9; // r4
  void *v10; // r6
  int v11; // r3
  volatile int *v13; // r10
  int v14; // r9
  int v15; // r3
  volatile uint32_t **v16; // r7
  int v17; // r5
  int v18; // r11
  int v19; // r0
  int v20; // r3
  int v21; // r2
  int v22; // r0
  int v23; // r3
  int v24; // r2
  volatile int16_t **v25; // r10
  volatile uint32_t *v26; // r7
  int v27; // r1
  int v28; // r9
  unsigned int v29; // r3
  volatile uint32_t *v30; // r0
  volatile uint32_t *v31; // r3
  int v32; // r1
  int v33; // r2
  unsigned int v34; // r3
  int v35; // r3
  int v36; // r0
  int v37; // r3
  int v38; // r1
  volatile int *v39; // r7
  int v40; // r3
  int v41; // r1
  int v42; // r2
  int v43; // r3
  volatile uint32_t *v44; // r12
  volatile uint32_t *v45; // r1
  int v46; // r0
  int v47; // [sp+0h] [bp-24h]
  int v48; // [sp+4h] [bp-20h]
  int a2; // [sp+8h] [bp-1Ch]
  int v50; // [sp+Ch] [bp-18h]
  int v51; // [sp+10h] [bp-14h]
  volatile int *v52; // [sp+14h] [bp-10h]
  int v53; // [sp+1Ch] [bp-8h]

  v2 = dword_1201F4;
  v3 = (volatile int *)(dword_1201F4 + 1320 * a1);
  v50 = 1320 * a1;
  check_abort_flag_3(dword_1201F8, (void *)(v3));
  if ( *((volatile int **)off_1201FC + 8) == v3 )
    *((volatile uint32_t *)off_1201FC + 8) = 0;
  v4 = *(volatile uint8_t *)(v2 + 1320 * a1 + 106);
  if ( v4 == 2 )
  {
    v13 = (volatile int *)off_12023C;
    v52 = v3;
    v14 = dword_12021C + 696 * (a1 + 32);
    v15 = dword_12021C + 8 * (87 * (a1 + 32) + 78);
    v53 = off_120200;
    --*(volatile uint8_t *)(off_120200 + 0x12);
    a2 = v15;
    *(volatile uint8_t *)(v14 + 37) = 0;
    v16 = (volatile uint32_t **)(v2 + 8 * (165 * (int16_t)a1 + 159));
    v17 = 0;
    do
    {
      if ( *(volatile uint32_t *)(v14 + 584) )
        rf_calib_config((uint8_t)v17, a2 - 40, 0);
      if ( *(volatile uint32_t *)(v14 + 624) )
        rf_calib_config((uint8_t)v17, a2, 0);
      if ( v3[318] || v3[308] )
      {
        v18 = (int)(v16 - 10);
        v51 = list_length(v16);
        v19 = list_length(v16 - 10);
        ke_event_schedule_1("vif unregister:%d, %d\n", v51, v19);
      }
      else
      {
        v18 = (int)(v16 - 10);
      }
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(volatile uint32_t *)off_120224 = 1;
      }
      ++*v13;
      rf_calib_config((uint8_t)v17, (int)v16, 0);
      rf_calib_config((uint8_t)v17, v18, 0);
      if ( *v13 )
      {
        v20 = *v13 - 1;
        v21 = *(volatile uint32_t *)off_120224;
        *v13 = v20;
        if ( !v20 )
        {
          if ( v21 )
            __enable_irq();
        }
      }
      ++v17;
      v14 += 8;
      v16 += 2;
      v3 += 2;
      a2 += 8;
    }
    while ( v17 != 5 );
    v3 = v52;
    v5 = (volatile uint8_t *)v53;
    if ( *(volatile uint32_t *)(v2 + 1320 * a1 + 1312) )
    {
      v22 = list_length((volatile uint32_t **)(v50 + 1312 + v2));
      ke_event_schedule_1("vif unregister mgmt:%d\n", v22);
    }
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(volatile uint32_t *)off_120224 = 1;
    }
    ++*v13;
    rf_calib_config(5u, v50 + 1312 + v2, 0);
    if ( *v13 )
    {
      v23 = *v13 - 1;
      v24 = *(volatile uint32_t *)off_120224;
      *v13 = v23;
      if ( !v23 )
      {
        if ( v24 )
          __enable_irq();
      }
    }
    v6 = *(volatile uint8_t *)(v53 + 18);
    if ( !*(volatile uint8_t *)(v53 + 18) )
    {
      mmio_clear_bit();
LABEL_6:
      v6 = (uint8_t)v5[18];
      v7 = (uint8_t)v5[17] + v6;
      if ( v7 != 1 )
        goto LABEL_7;
      goto LABEL_40;
    }
    if ( *(volatile uint8_t *)(v53 + 17) + v6 != 1 )
      goto LABEL_9;
  }
  else
  {
    if ( v4 != 4 )
    {
      v5 = (volatile uint8_t *)off_120200;
      if ( !*(volatile uint8_t *)(v2 + 1320 * a1 + 106) )
      {
        v6 = *(volatile uint8_t *)(off_120200 + 0x12);
        v35 = (uint8_t)(*(volatile uint8_t *)(off_120200 + 0x11) - 1);
        *(volatile uint8_t *)(off_120200 + 0x11) = v35;
        v7 = v35 + v6;
        if ( v7 != 1 )
          goto LABEL_7;
        goto LABEL_40;
      }
      goto LABEL_6;
    }
    if ( rf_calibration_done() )
      rf_control_set_bit3(0);
    v5 = (void *)(uintptr_t)(off_120344);
    v36 = *((volatile uint8_t *)off_120344 + 16);
    v37 = v2 + 1320 * v36;
    v38 = *(volatile uint32_t *)(v37 + 72);
    *(volatile uint32_t *)(v37 + 4) &= ~0x80u;
    if ( v38 )
      get_entry_by_index(v36);
    v6 = (uint8_t)v5[18];
    if ( v5[18] )
    {
      mmio_set_bit_1();
      v6 = (uint8_t)v5[18];
    }
    else
    {
      v39 = (volatile int *)off_12034C;
      v40 = dword_120350;
      v41 = **(volatile int16_t **)off_120348;
      *(volatile uint32_t *)off_12034C = dword_120350;
      if ( v41 < 0 )
      {
        v6 = *(volatile uint32_t *)off_120358 & 0xF;
        if ( v6 )
        {
          mmio_field_update((int)aNxmacCurrentSt, (int)aMmRxFilterSet_0, 472);
          v40 = *v39;
          v6 = (uint8_t)v5[18];
        }
      }
      *(volatile uint32_t *)off_120354 = v40 | v39[1];
    }
    v7 = (uint8_t)v5[17] + v6;
    v5[16] = -1;
    if ( v7 != 1 )
      goto LABEL_7;
  }
LABEL_40:
  v25 = (volatile int16_t **)off_120240;
  v26 = (void *)(uintptr_t)(off_12022C);
  v27 = **(volatile int16_t **)off_120240;
  v28 = *((volatile uint32_t *)v5 + 2);
  v29 = *((volatile uint32_t *)off_12022C + 1) & 0xFFFFFFEF;
  *((volatile uint32_t *)off_12022C + 1) = v29;
  if ( v27 >= 0 || !(*(volatile uint32_t *)off_120358 << 28) )
  {
    v30 = (void *)(uintptr_t)(off_120230);
    *(volatile uint32_t *)off_120238 = v29 | *v26;
    v31 = (void *)(uintptr_t)(off_120234);
    v32 = *(volatile uint16_t *)(v28 + 68);
    *v30 = *(volatile uint32_t *)(v28 + 64);
    *v31 = v32;
    if ( v6 )
      goto LABEL_9;
LABEL_42:
    v33 = **v25;
    v34 = v26[1] & 0xFFFFFEFF;
    v26[1] = v34;
    if ( v33 >= 0 || !(*(volatile uint32_t *)off_120358 << 28) )
    {
      *(volatile uint32_t *)off_120238 = v34 | *v26;
      goto LABEL_9;
    }
    mmio_field_update((int)aNxmacCurrentSt, (int)aMmRxFilterSet_0, 472);
    v7 = (uint8_t)v5[17] + (uint8_t)v5[18];
    *(volatile uint32_t *)off_120354 = *v26 | v26[1];
    goto LABEL_7;
  }
  mmio_field_update((int)aNxmacCurrentSt, (int)aMmRxFilterSet_0, 472);
  v42 = (uint8_t)v5[18];
  v43 = (uint8_t)v5[17];
  v44 = (void *)(uintptr_t)(off_120368);
  *(volatile uint32_t *)off_120354 = *v26 | v26[1];
  v7 = v43 + v42;
  v45 = (void *)(uintptr_t)(off_120364);
  v46 = *(volatile uint16_t *)(v28 + 68);
  *v44 = *(volatile uint32_t *)(v28 + 64);
  *v45 = v46;
  if ( v7 == 1 )
  {
    if ( v42 )
      goto LABEL_9;
    goto LABEL_42;
  }
LABEL_7:
  if ( !v7 )
    *(volatile uint32_t *)off_120204 = 0;
LABEL_9:
  ke_event_set_lock((int)(uintptr_t)((volatile uint32_t *)(v50 + 24 + v2)));
  ke_event_set_lock((int)(uintptr_t)((volatile uint32_t *)(v50 + 48 + v2)));
  v8 = v2 + 1320 * a1;
  if ( *(volatile uint8_t *)(v8 + 1224) )
  {
    rf_channel_state_get(*(volatile uint8_t *)(v8 + 1225), 1);
    --v5[19];
  }
  tx_slot_state_get(*(volatile uint8_t *)(v2 + 1320 * a1 + 107));
  if ( *((volatile int **)off_120208 + 4) == v3 )
    *((volatile uint32_t *)off_120208 + 4) = 0;
  *(volatile uint32_t *)off_12020C = 0;
  if ( (uint8_t)v5[18] + (uint8_t)v5[17] <= 1 )
    si_secure_check();
  memset(v3, 0, 0x528u);
  v48 = a1;
  v9 = v2 + 1320 * a1;
  v10 = (void *)(uintptr_t)(off_120210);
  v47 = (uint8_t)v5[18];
  v11 = v47 + (uint8_t)v5[17];
  *(volatile uint8_t *)(v9 + 106) = 5;
  *(volatile uint32_t *)(v9 + 56) = (int)(uintptr_t)(v3);
  *(volatile uint32_t *)(v9 + 52) = (int)(uintptr_t)(v10);
  *(volatile uint8_t *)(v9 + 109) = 127;
  *(volatile uint8_t *)(v9 + 110) = 127;
  state_check_feature(256, "%s:%d,%d,%d\r\n", aVifMgmtUnregis, v11, v47, v48);
  return check_abort_flag(off_120200, (void *)(v3));
}


