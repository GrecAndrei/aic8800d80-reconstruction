// ll_queue_advance @ 0x118bb8
int ll_queue_advance(int a1, int a2, int a3) {
  uint64_t v3; // kr00_8
  int v5; // r1
  int v6; // r7
  int result; // r0
  int v8; // r2
  int v9; // r3
  int v10; // r2

  v3 = *(volatile uint64_t *)(a1 + 72);
  *(volatile uint32_t *)(HIDWORD(v3) + 32) = *(volatile uint32_t *)(HIDWORD(v3) + 28) + a3 - 1;
  *(volatile uint32_t *)(HIDWORD(v3) + 36) = a3 + 4;
  *(volatile uint32_t *)(HIDWORD(v3) + 24) = 0;
  if ( a2 )
  {
    if ( a2 == 1 )
      v5 = dword_118C40;
    else
      v5 = v3 + 44;
    v6 = v3 + 44;
  }
  else
  {
    v5 = dword_118C3C;
    v6 = v3 + 44;
  }
  result = (int)(uintptr_t)(memcpy((void *)(uintptr_t)(v6), (void *)(uintptr_t)(v5), 52));
  v8 = *(volatile uint32_t *)off_118C38;
  if ( *(volatile uint32_t *)(v3 + 64) & 0x7C | (*(volatile uint32_t *)(v3 + 64) >> 11) & 6 )
    v9 = (uint16_t)((uint16_t)*(volatile uint32_t *)off_118C38 << 8) | (uint8_t)v8;
  else
    v9 = *(volatile uint32_t *)off_118C38 & 0xFF00 | BYTE1(v8);
  v10 = *(volatile uint32_t *)(a1 + 72);
  *(volatile uint32_t *)(v3 + 80) = v9;
  *(volatile uint32_t *)(HIDWORD(v3) + 44) = 0;
  *(volatile uint32_t *)(HIDWORD(v3) + 48) = v6;
  *(volatile uint32_t *)(HIDWORD(v3) + 68) = 0;
  *(volatile uint32_t *)(a1 + 88) = 0;
  *(volatile uint32_t *)(a1 + 92) = 0;
  *(volatile uint32_t *)(v10 + 40) = 0;
  *(volatile uint16_t *)(a1 + 82) = 0;
  return result;
}



// ke_mutex_guard @ 0x118c44
volatile uint32_t * ke_mutex_guard(int a1, int a2) {
  volatile uint32_t *v4; // r0
  volatile uint32_t *v5; // r4

  v4 = mem_word_load(dword_118C6C);
  v5 = v4;
  if ( v4 )
  {
    ll_queue_advance((int)v4, a1, a2);
    return v5;
  }
  else
  {
    event_dispatch(aNoTxlFrame);
    return nullptr;
  }
}


// tx_path_status @ 0x118c74
int tx_path_status(int a1, int a2) {
  uint64_t v2; // kr00_8
  int v3; // r2
  int v6; // r12
  int v7; // r3
  char v8; // r2

  v2 = *(volatile uint64_t *)(a1 + 72);
  v3 = *(volatile uint32_t *)(HIDWORD(v2) + 28);
  if ( **(volatile int16_t **)off_118CD4 < 0 && (v3 & 1) != 0 )
  {
    mmio_clear_register(dword_118CDC, dword_118CD8, 389);
    v3 = *(volatile uint32_t *)(HIDWORD(v2) + 28);
  }
  v6 = *(volatile uint32_t *)(HIDWORD(v2) + 44);
  *(volatile uint32_t *)(HIDWORD(v2) + 68) &= 0xFF87FFFF;
  v7 = 0;
  *(volatile uint64_t *)(HIDWORD(v2) + 16) = 0;
  v8 = *(volatile uint8_t *)(v3 + 4);
  *(volatile uint32_t *)(HIDWORD(v2) + 72) = 0;
  if ( (v8 & 1) == 0 )
    v7 = 512;
  *(volatile uint32_t *)(HIDWORD(v2) + 64) = v7;
  *(volatile uint32_t *)(v2 + 96) = v7;
  *(volatile uint32_t *)(v2 + 100) = v6;
  return phy_radio_init(a1, a2);
}



// free_buf_1882c0 @ 0x118ce0
int free_buf_1882c0(volatile uint32_t *a1) {
  co_list_push_back(dword_118CF8, a1);
  return unknown_func_12d104(0x20000);
}


// scan_control @ 0x118cfc
int scan_control(int result, int a2) {
  int v2; // r4
  int ( *v4)(uint32_t, uint32_t); // r3

  v2 = result;
  if ( !*(volatile uint8_t *)(result + 96) )
    result = co_list_push_back(dword_118D24, (volatile uint32_t *)result);
  if ( a2 )
  {
    v4 = *(int ( **)(uint32_t, uint32_t))(v2 + 88);
    if ( v4 )
      return v4(*(volatile uint32_t *)(v2 + 92), 0);
  }
  return result;
}


// tx_pool_init @ 0x118d28
volatile uint32_t *tx_pool_init() {
  volatile int *v0; // r8
  volatile int *v1; // r7
  int v2; // r6
  volatile uint32_t *v3; // r5
  volatile uint32_t *result; // r0
  volatile uint32_t *v5; // r4
  int v6; // r3
  int v7; // r2
  void ( *v8)(uint32_t, uint32_t); // r2

  unknown_func_12d14c(0x20000);
  v0 = (volatile int *)off_118DC0;
  v1 = (volatile int *)off_118DB0;
  v2 = dword_118DB4;
  v3 = (void *)(uintptr_t)(off_118DB8);
  while ( 1 )
  {
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *v1 = 1;
    }
    ++*v0;
    result = mem_word_load(v2);
    v5 = result;
    if ( *v0 )
    {
      v6 = *v0 - 1;
      v7 = *v1;
      *v0 = v6;
      if ( !v6 )
      {
        if ( v7 )
          __enable_irq();
      }
    }
    if ( !result )
      break;
    v8 = (void ( *)(uint32_t, uint32_t))result[22];
    --v3[126];
    if ( v8 && (v8(result[23], *(volatile uint32_t *)(result[19] + 72)), *((volatile uint8_t *)v5 + 98)) )
    {
      *((volatile uint8_t *)v5 + 98) = 0;
    }
    else if ( !*((volatile uint8_t *)v5 + 96) )
    {
      co_list_push_back(dword_118DBC, v5);
    }
  }
  return result;
}


// rf_channel_get @ 0x118dc4
int rf_channel_get(int a1, int a2, int a3) {
  int v3; // r9
  int v4; // r5
  int v6; // r10
  int v8; // r3
  int v10; // r2
  int v11; // r4
  int v12; // r5
  int v13; // r3
  int v14; // r2
  int v15; // r0
  int v16; // t1
  int16_t v17; // r12
  int16_t v18; // lr
  int v19; // r5
  int16_t v20; // r5
  char v21; // r2
  int v23; // r1
  int v24; // r0
  int v25; // lr
  int v26; // r0
  int16_t v27; // r2

  v3 = dword_118F44;
  v4 = dword_118F30;
  v6 = *(volatile uint8_t *)(dword_118F44 + 696 * a1 + 34);
  v8 = *(volatile uint32_t *)(dword_118F30 + 1320 * v6 + 72);
  if ( !v8 )
  {
    if ( **(volatile int16_t **)off_118F34 >= 0 )
    {
LABEL_9:
      v11 = (int)(uintptr_t)(ke_mutex_guard(1, 24));
      if ( !v11 )
        return 1;
      goto LABEL_4;
    }
LABEL_8:
    mmio_clear_register(dword_118F40, dword_118F3C, 520);
    goto LABEL_9;
  }
  v10 = *(volatile uint8_t *)(v8 + 4);
  if ( **(volatile int16_t **)off_118F34 < 0 && v10 == 2 )
    goto LABEL_8;
  v11 = (int)(uintptr_t)(ke_mutex_guard((*(volatile uint8_t *)(dword_118F30 + 1320 * v6 + 1224) | v10) != 0, 24));
  if ( !v11 )
    return 1;
LABEL_4:
  v12 = v4 + 1320 * v6;
  rf_check_temperature(v12, v11);
  v13 = *(volatile uint32_t *)(v11 + 72);
  if ( *(volatile uint8_t *)(v12 + 106) == 2 )
  {
    v23 = v3 + 696 * a1;
    v24 = *(volatile uint32_t *)(v12 + 100);
    v25 = *(volatile uint32_t *)(v23 + 38);
    *(volatile uint8_t *)(v13 + 109) = 2;
    *(volatile uint16_t *)(v13 + 116) = *(volatile uint16_t *)(v23 + 42);
    v23 = (v23 & ~0xFFFFu) | ((uint16_t)(*(volatile uint16_t *)(v12 + 104)) & 0xFFFFu);
    *(volatile uint32_t *)(v13 + 118) = v24;
    v26 = *(volatile uint32_t *)(v12 + 100);
    *(volatile uint8_t *)(v13 + 110) = 0;
    *(volatile uint8_t *)(v13 + 111) = 0;
    v27 = *(volatile uint16_t *)(v12 + 104);
    *(volatile uint32_t *)(v13 + 112) = v25;
    *(volatile uint8_t *)(v13 + 108) = 72;
    *(volatile uint16_t *)(v13 + 122) = v23;
    *(volatile uint32_t *)(v13 + 124) = v26;
    *(volatile uint16_t *)(v13 + 128) = v27;
  }
  else
  {
    v14 = v3 + 696 * a1;
    v15 = *(volatile uint32_t *)(v12 + 100);
    v16 = *(volatile uint32_t *)(v14 + 38);
    v14 += 38;
    v17 = *(volatile uint16_t *)(v12 + 104);
    v18 = *(volatile uint16_t *)(v14 + 4);
    v19 = *(volatile uint32_t *)v14;
    *(volatile uint32_t *)(v13 + 112) = v16;
    *(volatile uint16_t *)(v13 + 128) = *(volatile uint16_t *)(v14 + 4);
    *(volatile uint32_t *)(v13 + 124) = v19;
    *(volatile uint16_t *)(v13 + 116) = v18;
    *(volatile uint32_t *)(v13 + 118) = v15;
    *(volatile uint16_t *)(v13 + 122) = v17;
    *(volatile uint8_t *)(v13 + 110) = 0;
    *(volatile uint8_t *)(v13 + 111) = 0;
    *(volatile uint8_t *)(v13 + 108) = 72;
    *(volatile uint8_t *)(v13 + 109) = 1;
  }
  v20 = *((volatile uint16_t *)off_118F38 + 254) + 1;
  *((volatile uint16_t *)off_118F38 + 254) = v20;
  v21 = *(volatile uint8_t *)(v3 + 696 * a1 + 34);
  *(volatile uint16_t *)(v13 + 130) = 16 * v20;
  *(volatile uint32_t *)(v11 + 88) = a2;
  *(volatile uint32_t *)(v11 + 92) = a3;
  *(volatile uint8_t *)(v11 + 28) = v21;
  *(volatile uint8_t *)(v11 + 29) = a1;
  tx_path_status(v11, 5);
  return 0;
}



// rf_channel_set @ 0x118f48
int rf_channel_set(int a1, int16_t a2, int a3, int a4) {
  int v4; // r11
  int v5; // r4
  int v7; // r7
  int v9; // r0
  int v12; // r2
  int v13; // r5
  int v14; // r7
  int v15; // r3
  int v16; // r4
  int v17; // r1
  int v18; // r12
  int16_t v19; // lr
  int v20; // r0
  int16_t v21; // r2
  char v22; // r3

  v4 = dword_119088;
  v5 = dword_119078;
  v7 = *(volatile uint8_t *)(dword_119088 + 696 * a1 + 34);
  v9 = *(volatile uint32_t *)(dword_119078 + 1320 * v7 + 72);
  if ( !v9 )
  {
    if ( **(volatile int16_t **)off_11907C >= 0 )
    {
LABEL_10:
      v13 = (int)(uintptr_t)(ke_mutex_guard(1, 26));
      if ( !v13 )
        return 1;
      goto LABEL_4;
    }
LABEL_9:
    mmio_clear_register(dword_119084, dword_119080, 520);
    goto LABEL_10;
  }
  v12 = *(volatile uint8_t *)(v9 + 4);
  if ( **(volatile int16_t **)off_11907C < 0 && v12 == 2 )
    goto LABEL_9;
  v13 = (int)(uintptr_t)(ke_mutex_guard((*(volatile uint8_t *)(dword_119078 + 1320 * v7 + 1224) | v12) != 0, 26));
  if ( !v13 )
    return 1;
LABEL_4:
  v14 = v5 + 1320 * v7;
  rf_check_temperature(v14, v13);
  v15 = v4 + 696 * a1;
  v16 = *(volatile uint32_t *)(v13 + 72);
  v17 = *(volatile uint32_t *)(v15 + 38);
  v18 = *(volatile uint8_t *)(v14 + 106);
  v19 = *(volatile uint16_t *)(v15 + 42);
  v20 = *(volatile uint32_t *)(v14 + 100);
  v21 = *(volatile uint16_t *)(v14 + 104);
  *(volatile uint16_t *)(v16 + 122) = v21;
  *(volatile uint16_t *)(v16 + 116) = v19;
  *(volatile uint32_t *)(v16 + 112) = v17;
  *(volatile uint32_t *)(v16 + 118) = v20;
  *(volatile uint8_t *)(v16 + 110) = 0;
  *(volatile uint8_t *)(v16 + 111) = 0;
  if ( v18 )
  {
    *(volatile uint32_t *)(v16 + 124) = *(volatile uint32_t *)(v14 + 100);
    *(volatile uint16_t *)(v16 + 128) = v21;
    *(volatile uint8_t *)(v16 + 108) = -56;
    *(volatile uint8_t *)(v16 + 109) = 2;
  }
  else
  {
    *(volatile uint32_t *)(v16 + 124) = v17;
    *(volatile uint16_t *)(v16 + 128) = v19;
    *(volatile uint8_t *)(v16 + 108) = -56;
    *(volatile uint8_t *)(v16 + 109) = 1;
  }
  v22 = *(volatile uint8_t *)(v4 + 696 * a1 + 34);
  *(volatile uint16_t *)(v16 + 132) = a2;
  *(volatile uint8_t *)(v16 + 130) = 0;
  *(volatile uint8_t *)(v16 + 131) = 0;
  *(volatile uint32_t *)(v13 + 88) = a3;
  *(volatile uint32_t *)(v13 + 92) = a4;
  *(volatile uint8_t *)(v13 + 28) = v22;
  *(volatile uint8_t *)(v13 + 29) = a1;
  tx_path_status(v13, 5);
  return 0;
}



// phy_channel_is_5g @ 0x11908c
int phy_channel_is_5g(int a1, int a2, int a3) {
  if ( (*(volatile uint32_t *)(dword_1190B0 + 696 * a1 + 4) & 0x20) != 0 )
    return rf_channel_set(a1, 7, a2, a3);
  else
    return rf_channel_get(a1, a2, a3);
}



// phy_channel_get_attr @ 0x1190b4
BOOL phy_channel_get_attr(int a1, int a2, int a3, int a4, uint8_t a5, uint8_t a6, int a7, int a8) {
  int v8; // r10
  int v9; // r8
  int v11; // r9
  int v12; // r0
  int v15; // r3
  int v16; // r1
  BOOL v17; // r0
  int v18; // r0
  int v19; // r8
  int v20; // r9
  volatile uint8_t *v21; // r2
  int v22; // r1
  int16_t v23; // lr
  int v24; // r0
  unsigned int v25; // r7
  volatile uint16_t *v26; // r8
  int v27; // lr
  int v28; // r2
  volatile uint32_t *v31; // [sp+4h] [bp-8h]
  int v32; // [sp+4h] [bp-8h]

  v8 = dword_119258;
  v9 = dword_11925C;
  v11 = *(volatile uint8_t *)(dword_119258 + 696 * a1 + 34);
  v12 = *(volatile uint32_t *)(dword_11925C + 1320 * v11 + 72);
  if ( a2 )
    v15 = 29;
  else
    v15 = 30;
  if ( v12 )
  {
    v16 = *(volatile uint8_t *)(v12 + 4);
    if ( **(volatile int16_t **)off_119240 >= 0 || v16 != 2 )
    {
      v17 = (*(volatile uint8_t *)(dword_11925C + 1320 * v11 + 1224) | v16) != 0;
      goto LABEL_7;
    }
    goto LABEL_16;
  }
  if ( **(volatile int16_t **)off_119240 < 0 )
  {
LABEL_16:
    v32 = v15;
    mmio_clear_register(dword_119250, dword_119254, 520);
    v15 = v32;
    v17 = 1;
    goto LABEL_7;
  }
  v17 = 1;
LABEL_7:
  v18 = (int)(uintptr_t)(ke_mutex_guard(v17, v15));
  if ( !v18 )
    return 1;
  v19 = v9 + 1320 * v11;
  v20 = *(volatile uint32_t *)(v18 + 72);
  v31 = (volatile uint32_t *)v18;
  rf_check_temperature(v19, v18);
  v21 = (volatile uint8_t *)off_119244;
  v22 = v31[18];
  v23 = *(volatile uint16_t *)(v19 + 104);
  *(volatile uint32_t *)(v20 + 60) = HIWORD(*(volatile uint32_t *)(v20 + 60)) << 16;
  v24 = *(volatile uint32_t *)(v19 + 100);
  *(volatile uint32_t *)(v22 + 124) = a2 | (16 * a3);
  *(volatile uint8_t *)(v22 + 128) = 0;
  *(volatile uint8_t *)(v22 + 129) = 0;
  *(volatile uint8_t *)(v22 + 130) = 0;
  *(volatile uint8_t *)(v22 + 131) = 0;
  v25 = v21[67];
  v26 = (void *)(uintptr_t)(off_119260);
  *(volatile uint32_t *)(v22 + 118) = v24;
  v21 = (void *)(uintptr_t)(((uintptr_t)(v21) & ~0xFFFFu) | ((uint16_t)(v26[2]) & 0xFFFFu));
  *(volatile uint16_t *)(v22 + 122) = v23;
  *(volatile uint8_t *)(v22 + 108) = 36;
  v27 = *(volatile uint32_t *)v26;
  *(volatile uint16_t *)(v22 + 116) = (uint16_t)v21;
  *(volatile uint32_t *)(v22 + 112) = v27;
  *(volatile uint8_t *)(v22 + 109) = 0;
  *(volatile uint8_t *)(v22 + 110) = 0;
  *(volatile uint8_t *)(v22 + 111) = 0;
  v28 = (v25 >> 5) & 1;
  if ( (v25 & 0x20) != 0 )
  {
    if ( (*(volatile uint8_t *)(dword_119248 + 696 * a1 + 1) & 0x20) != 0 )
      v28 = 0x100000;
    else
      v28 = 0;
  }
  *(volatile uint32_t *)(v22 + 132) = (a5 << 21) | (a4 << 13) | *(volatile uint16_t *)(v8 + 696 * a1 + 32) | v28;
  *(volatile uint8_t *)(v22 + 136) = -40;
  if ( !a2 )
    *(volatile uint8_t *)(v22 + 137) = *(volatile uint8_t *)(dword_11924C + a6) << 6;
  v31[22] = a7;
  v31[23] = a8;
  return tx_path_status((int)v31, a6) == 0;
}



// bt_link_state_check @ 0x119264
int bt_link_state_check(int a1, volatile char *a2) {
  int v2; // r3
  int v3; // r3
  int v6; // r3
  BOOL v7; // r0
  int v8; // r8
  volatile uint32_t *v9; // r0
  int v10; // r6
  int v11; // r5
  volatile uint16_t *v12; // r2
  uint16_t v13; // r3
  uint16_t v14; // r1
  int v15; // r0

  v2 = *(volatile uint8_t *)(a1 + 106);
  if ( v2 != 2 )
  {
    event_dispatch("vif type error:%d\n", v2);
    return 1;
  }
  v3 = *(volatile uint32_t *)(a1 + 72);
  if ( v3 )
  {
    v6 = *(volatile uint8_t *)(v3 + 4);
    if ( **(volatile int16_t **)off_11937C >= 0 || v6 != 2 )
    {
      v7 = (v6 | *(volatile uint8_t *)(a1 + 1224)) != 0;
      goto LABEL_5;
    }
  }
  else if ( **(volatile int16_t **)off_11937C >= 0 )
  {
    goto LABEL_9;
  }
  mmio_clear_register((int)aBandPhyBandMax_0, (int)aVifMgmtGetTxty, 520);
LABEL_9:
  v7 = 1;
LABEL_5:
  v8 = dword_119398;
  v9 = ke_mutex_guard(v7, *(volatile uint16_t *)(dword_119398 + 2 * *(volatile uint8_t *)(a1 + 107)));
  v10 = (int)v9;
  if ( v9 )
  {
    rf_check_temperature(a1, (int)v9);
    v11 = *(volatile uint32_t *)(v10 + 72);
    *(volatile uint8_t *)(v11 + 108) = 80;
    *(volatile uint8_t *)(v11 + 109) = 0;
    *(volatile uint8_t *)(v11 + 110) = 0;
    *(volatile uint8_t *)(v11 + 111) = 0;
    memcpy((volatile char *)(v11 + 112), a2, 6u);
    v12 = (void *)(uintptr_t)(off_119380);
    v13 = *((volatile uint16_t *)off_119380 + 254);
    v14 = *(volatile uint16_t *)(a1 + 104);
    *(volatile uint32_t *)(v11 + 118) = *(volatile uint32_t *)(a1 + 100);
    ++v13;
    v15 = *(volatile uint32_t *)(a1 + 100);
    *(volatile uint16_t *)(v11 + 122) = v14;
    *(volatile uint32_t *)(v11 + 124) = v15;
    *(volatile uint16_t *)(v11 + 128) = v14;
    v12[254] = v13;
    *(volatile uint16_t *)(v11 + 130) = 16 * v13;
    memcpy(
      (volatile char *)(v11 + 132),
      (volatile char *)(dword_119384 + (*(volatile uint8_t *)(a1 + 107) << 9)),
      *(volatile uint16_t *)(v8 + 2 * *(volatile uint8_t *)(a1 + 107)) - 24);
    *(volatile uint32_t *)(v10 + 88) = 0;
    *(volatile uint32_t *)(v10 + 92) = 0;
    *(volatile uint8_t *)(v10 + 28) = *(volatile uint8_t *)(a1 + 107);
    *(volatile uint8_t *)(v10 + 29) = -1;
    tx_path_status(v10, 5);
    return 0;
  }
  else
  {
    event_dispatch("no probe buf:%d\n", *(volatile uint16_t *)(v8 + 2 * *(volatile uint8_t *)(a1 + 107)));
    return 1;
  }
}


// lookup_table_u16 @ 0x11939c
int lookup_table_u16(int a1, int a2) {
  return *(volatile uint16_t *)(dword_1193A8 + 2 * (a1 | (2 * a2)));
}



// lookup_table_u8 @ 0x1193ac
int lookup_table_u8(int a1, int a2) {
  return *(volatile uint8_t *)(dword_1193B8 + (a1 | (2 * a2)));
}



// phy_channel_select @ 0x1193bc
int phy_channel_select(int a1, int16_t a2, int a3, int16_t a4, uint8_t a5) {
  volatile int *v5; // r7
  int v6; // r6
  int v7; // r4
  int v8; // t1
  int16_t v9; // r12
  int v11; // r0
  int v12; // r4
  int v13; // r6
  int result; // r0

  v5 = (volatile int *)off_119444;
  v6 = dword_11943C + 696 * a3;
  v7 = dword_119440 + 1320 * *(volatile uint8_t *)(v6 + 34);
  v8 = *(volatile uint32_t *)(v6 + 38);
  v9 = *(volatile uint16_t *)(v7 + 104);
  v11 = *(volatile uint32_t *)(v7 + 100);
  *(volatile uint16_t *)(a1 + 160) = *(volatile uint16_t *)(v6 + 42);
  *(volatile uint32_t *)(a1 + 120) = a1 + 172;
  *(volatile uint32_t *)(a1 + 88) = 0;
  *(volatile uint32_t *)(a1 + 144) = 0;
  v12 = *v5;
  v13 = *v5;
  *(volatile uint32_t *)(a1 + 162) = v11;
  result = (a5 << 7) | 0x808;
  *(volatile uint32_t *)(a1 + 156) = v8;
  *(volatile uint32_t *)(a1 + 208) = (uint16_t)((uint16_t)v12 << 8) | (uint8_t)v13;
  *(volatile uint16_t *)(a1 + 166) = v9;
  *(volatile uint16_t *)(a1 + 168) = (a4 << 12) | 4;
  *(volatile uint16_t *)(a1 + 170) = 16 * a2;
  *(volatile uint32_t *)(a1 + 192) = result;
  return result;
}



// get_hw_pointer @ 0x119448
volatile int16_t * get_hw_pointer(volatile int16_t *result) {
  int v1; // r2
  int v2; // r1
  volatile uint32_t *v3; // r4
  int v4; // r3

  v1 = *((volatile uint32_t *)result + 19);
  if ( *(volatile uint32_t *)(v1 + 28) )
  {
    v2 = *((volatile uint32_t *)off_119498 + 43);
    v3 = (void *)(result);
    result = *(volatile int16_t **)off_11949C;
    do
    {
      v4 = v3[9] & 0x380000;
      *(volatile uint32_t *)(*(volatile uint32_t *)(v1 + 32) - 3) = v2;
      if ( v4 == 3670016 )
        break;
      v3 = (volatile uint32_t *)*v3;
      if ( *result < 0 && !v3 )
      {
        mmio_clear_register(dword_1194A4, dword_1194A0, 909);
        __und(0xFFu);
      }
      v1 = v3[19];
    }
    while ( *(volatile uint32_t *)(v1 + 28) );
  }
  return result;
}



