// tx_power_lookup @ 0x1389d0
int tx_power_lookup(int a1, uint16_t a2, int a3) {
  volatile uint8_t *v3; // r5
  int v4; // r4
  int v5; // r3
  volatile uint32_t *v6; // r6
  int v7; // r7
  int v8; // r12
  int v9; // r3

  v3 = (void *)(uintptr_t)(off_138A5C);
  v4 = *((volatile uint8_t *)off_138A5C + 68);
  v5 = dword_138A60;
  v6 = (volatile uint32_t *)(dword_138A60 + 80 * v4);
  if ( **(volatile int16_t **)off_138A58 < 0 )
  {
    v7 = 4 * v4;
    if ( *(volatile uint16_t *)(dword_138A60 + 80 * v4 + 76) )
    {
      bad_func_0x12f408((int)aRxStatDescValS, (int)aRxuCntrlDescPr, 175);
      return 0;
    }
  }
  else
  {
    v7 = 4 * v4;
  }
  v8 = dword_138A60 + 16 * (v7 + v4);
  *(volatile uint32_t *)(v8 + 12) = a1;
  if ( a1 )
    *(volatile uint8_t *)(v8 + 16) = *(volatile uint8_t *)(a1 + 16);
  v9 = v5 + 16 * (v4 + v7);
  *(volatile uint32_t *)(v9 + 68) = a3;
  *(volatile uint16_t *)(v9 + 76) = a2;
  cmd_handler_a(dword_138A64, v6);
  v3[68] = v3[68]
         + 1
         - -64
         * ((unsigned int)(((unsigned int)dword_138A68 * (uint64_t)((unsigned int)(uint8_t)v3[68] + 1)) >> 32) >> 7);
  return (int)v6;
}


// tx_power_set @ 0x138a74
int tx_power_set(int a1) {
  int v1; // r5
  int v3; // r1

  v1 = dword_138AA4;
  tx_power_lookup(0, 4, *(volatile uint32_t *)(a1 + 20));
  cmd_handler_c(v1, (volatile uint32_t *)a1);
  cmd_handler_a(v1 - 8, (volatile uint32_t *)a1);
  return (int)load_and_process_r0((volatile int *)(v1 - 32), v3);
}


// phy_config_set @ 0x138aa8
int phy_config_set(volatile uint8_t *a1, volatile uint32_t *a2, int a3, int a4) {
  char v5; // r2
  int v6; // r4
  volatile uint8_t *v7; // r3
  int v10; // r7
  int v12; // r9
  int v13; // r7

  v5 = *(volatile uint8_t *)(a3 + 1);
  v6 = a4;
  if ( a4 )
    v6 = 2;
  if ( (v5 & 0x40) != 0 )
    v6 = (uint8_t)(v6 + 8);
  v7 = (volatile uint8_t *)(a3 + v6);
  if ( *(volatile uint8_t *)(a3 + v6 + 30) != 8 )
    return 0;
  if ( v7[31] != 6 )
    return 0;
  v10 = (uint8_t)v7[38];
  if ( v7[38] )
    return 0;
  v12 = (uint8_t)v7[39];
  if ( v12 == 1 )
  {
    v13 = ((uint8_t)v7[58] << 16)
        | ((uint8_t)v7[59] << 24)
        | (uint8_t)v7[56]
        | ((uint8_t)v7[57] << 8);
    check_status_bits(128, "rx arpreq: ip=%x. vif ip=%x\r\n", v13, *a2);
    if ( v13 == *a2 )
      bt_get_acl_by_ble(*a1, (int)(uintptr_t)((volatile char *)(v6 + 40 + a3)), (volatile char *)a3);
    return 1;
  }
  else if ( v12 == 2 )
  {
    check_status_bits(128, aRxArpresp);
  }
  return v10;
}


// rand_gen_u16 @ 0x138bf4
int rand_gen_u16(volatile uint16_t *a1) {
  int v2; // r7
  int v3; // r5
  int i; // r4
  int v6; // r10
  volatile uint32_t *v7; // r4

  if ( *((volatile uint8_t *)off_138CA0 + 16) == 255 || (*a1 & 0xEC) != 0xC4 )
  {
    v2 = dword_138CA4;
    v3 = 0;
    for ( i = dword_138CA4; ; i += 1320 )
    {
      if ( *(volatile uint8_t *)(i + 108) )
      {
        if ( *(volatile uint8_t *)(i + 106) == 2 )
        {
          v6 = 1320 * v3;
          if ( !memcmp((unsigned int)(a1 + 2), i + 100, 6u) )
            break;
        }
      }
      if ( ++v3 == 4 )
        return 0;
    }
    v7 = *(volatile uint32_t **)(v2 + v6 + 240);
    if ( v7 )
    {
      while ( memcmp((unsigned int)(a1 + 5), (unsigned int)v7 + 38, 6u) )
      {
        v7 = (volatile uint32_t *)*v7;
        if ( !v7 )
          goto LABEL_14;
      }
      event_dispatch(
        "keyInValid[%04X:%04X:%04X]\n",
        (uint16_t)a1[5],
        (uint16_t)a1[6],
        (uint16_t)a1[7]);
    }
    else
    {
LABEL_14:
      event_dispatch(
        "%s: send_deauth[%04X:%04X:%04X]\n",
        aRxuCntrlSpurio,
        (uint16_t)a1[5],
        (uint16_t)a1[6],
        (uint16_t)a1[7]);
      rx_process_callback(v2 + v6, (int)(uintptr_t)((volatile char *)a1 + 10));
    }
  }
  return 0;
}


// rf_get_rssi_3 @ 0x138cb4
volatile uint32_t * rf_get_rssi_3(int a1, int16_t a2) {
  volatile uint32_t *v2; // r6
  int16_t v4; // r5
  unsigned int v5; // r3
  unsigned int v6; // r3

  v2 = (void *)(uintptr_t)(off_138D10);
  v4 = a2;
  if ( *((volatile uint8_t *)off_138D14 + 16) != 255 )
  {
    v4 = a2 | 0x80;
LABEL_3:
    v5 = (*((volatile uint8_t *)off_138D10 + 10) << 8)
       | (*((volatile uint8_t *)off_138D10 + 9) << 16)
       | (*((volatile uint8_t *)off_138D10 + 11) << 24)
       | *(volatile uint32_t *)(a1 + 96)
       | 0x80;
    goto LABEL_4;
  }
  if ( (a2 & 0x80) != 0 )
    goto LABEL_3;
  v5 = (*((volatile uint8_t *)off_138D10 + 10) << 8)
     | (*((volatile uint8_t *)off_138D10 + 9) << 16)
     | (*((volatile uint8_t *)off_138D10 + 11) << 24)
     | *(volatile uint32_t *)(a1 + 96) & 0xFFFFFF7F;
LABEL_4:
  if ( (v4 & 1) != 0 )
    v6 = v5 | 0x40;
  else
    v6 = v5 & 0xFFFFFFBF;
  *(volatile uint32_t *)(a1 + 96) = v6;
  mac_mlme_scan(a1);
  return (void *)(uintptr_t)(tx_power_lookup(a1, v4, v2[16]));
}



// rf_rssi_calibrate @ 0x138d18
volatile uint32_t * rf_rssi_calibrate(int a1, int16_t a2) {
  void *v2; // r6
  int16_t v4; // r5
  int v5; // r2
  int v6; // r1
  int v7; // r3
  unsigned int v8; // r3
  unsigned int v9; // r3

  v2 = (void *)(uintptr_t)(off_138DA0);
  v4 = a2;
  if ( *((volatile uint8_t *)off_138D9C + 16) == 255 )
  {
    v7 = (*((volatile uint8_t *)off_138DA0 + 10) << 8)
       | (*((volatile uint8_t *)off_138DA0 + 9) << 16)
       | *(volatile uint32_t *)(a1 + 96);
    if ( (a2 & 0x80) == 0 )
    {
      v8 = (*((volatile uint8_t *)off_138DA0 + 10) << 8)
         | (*((volatile uint8_t *)off_138DA0 + 9) << 16)
         | *(volatile uint32_t *)(a1 + 96) & 0xFFFFFF7D
         | 2;
      if ( (a2 & 1) != 0 )
        goto LABEL_6;
LABEL_10:
      v9 = v8 & 0xFFFFFFBF;
      goto LABEL_7;
    }
    v6 = a2 & 1;
  }
  else
  {
    v5 = *((volatile uint8_t *)off_138DA0 + 10);
    if ( v5 == 255 )
    {
      v6 = 0;
      v4 = 128;
    }
    else
    {
      v6 = a2 & 1;
      v4 |= 0x80u;
    }
    v7 = (v5 << 8) | (*((volatile uint8_t *)off_138DA0 + 9) << 16) | *(volatile uint32_t *)(a1 + 96);
  }
  v8 = v7 | 0x82;
  if ( !v6 )
    goto LABEL_10;
LABEL_6:
  v9 = v8 | 0x40;
LABEL_7:
  *(volatile uint32_t *)(a1 + 96) = v9;
  *((volatile uint8_t *)v2 + 50) = 0;
  mac_mlme_scan(a1);
  return (void *)(uintptr_t)(tx_power_lookup(a1, v4, *((volatile uint32_t *)v2 + 16)));
}



// ll_state_machine_1 @ 0x138da4
int ll_state_machine_1(unsigned int a1, int a2, int a3, int a4) {
  volatile uint32_t *v4; // r8
  unsigned int v5; // r4
  int v8; // r5
  volatile uint32_t *v9; // r6
  int v10; // r1
  int v11; // r1
  int16_t v12; // r2
  int v13; // r0
  unsigned int v14; // r5
  unsigned int v15; // r4
  int v16; // cc
  int v17; // r1
  volatile int16_t **v18; // r10
  volatile int16_t **v19; // r12
  volatile char *v20; // r0
  int v21; // r1
  int64_t v22; // r2
  int16_t v23; // r5
  int16_t v24; // lr
  signed int v25; // r3
  volatile uint8_t *v26; // r2
  int v27; // r3
  int v28; // r10
  volatile uint8_t *v29; // r5
  int v30; // lr
  volatile uint8_t *v32; // r5
  volatile char *v33; // r3
  volatile char *v34; // r2
  int v35; // r6
  volatile uint8_t *v36; // r3
  volatile char *v37; // r2
  volatile uint8_t *v38; // r5
  int v39; // r0
  int v40; // r1
  int v41; // r2
  int64_t v42; // r4
  int v43; // t1
  struct __attribute__((packed)) { int v44; // [sp+Ch] [bp-10h]
  int64_t v45; // [sp+10h] [bp-Ch] BYREF
  } _frame;
  v4 = (void *)(uintptr_t)(off_138FDC);
  v5 = a1;
  if ( a3 )
  {
    crypto_load_args(
      a2,
      (volatile uint32_t *)(*((volatile uint32_t *)off_138FDC + 8) + 88),
      (int)off_138FDC + 36,
      (volatile uint16_t *)off_138FDC + 21,
      *((volatile uint8_t *)off_138FDC + 7));
    v11 = *((volatile uint8_t *)v4 + 8);
    v9 = *(volatile uint32_t **)(v5 + 28);
    v5 = (v5 & ~0xFFFFu) | ((uint16_t)(*(volatile uint16_t *)(v5 + 48) - v11) & 0xFFFFu);
    v12 = *((volatile uint8_t *)v4 + 8);
  }
  else
  {
    v8 = *((volatile uint8_t *)off_138FDC + 8);
    v9 = *(volatile uint32_t **)(a1 + 28);
    v5 = (uint16_t)(*(volatile uint16_t *)(a1 + 48) - v8);
    v10 = a2 + 16;
    if ( a4 && v5 <= 7 )
    {
      _frame.v44 = v10;
      v32 = (volatile uint8_t *)(v8 + v9[2]);
      unaligned_read((volatile uint32_t *)a2, v10, v5);
      v33 = (volatile char *)&_frame.v45;
      v34 = (volatile char *)&_frame.v45 + (uint8_t)(8 - v5);
      do
      {
        *v33 = v33[_frame.v44 + v5 - (uint32_t)&_frame.v45];
        ++v33;
      }
      while ( v34 != v33 );
      v35 = 8 - (uint8_t)(8 - v5);
      if ( v35 )
      {
        v36 = v32;
        v37 = (volatile char *)((uintptr_t)(v34) - (uintptr_t)(v32));
        v38 = &v32[v35];
        do
        {
          v36[(uint32_t)v37] = *v36;
          ++v36;
        }
        while ( v38 != v36 );
      }
      goto LABEL_36;
    }
    unaligned_read((volatile uint32_t *)a2, v10, 8u);
    v11 = *((volatile uint8_t *)v4 + 8);
    v12 = *((volatile uint8_t *)v4 + 8);
  }
  v13 = v9[2];
  v14 = (uint16_t)(v5 - 8);
  v15 = (uint16_t)(v9[3] + 1 - v13);
  v16 = (int)(v11 + v14) <= (int)v15;
  v17 = v11 + v13;
  if ( v16 )
  {
    v15 = (uint16_t)(v12 + v14);
LABEL_11:
    unaligned_read((volatile uint32_t *)a2, v17, v14);
  }
  else
  {
    v18 = (volatile int16_t **)off_138FE0;
    while ( 1 )
    {
      v14 = (uint16_t)(v14 + v12 - v15);
      unaligned_read((volatile uint32_t *)a2, v17, (uint16_t)(v15 - v12));
      v12 = 0;
      if ( !(uint16_t)v14 )
        break;
      v9 = (volatile uint32_t *)v9[1];
      if ( **v18 < 0 && !v9 )
      {
        bad_func_0x12f408((int)aPdNull, (int)aRxuCntrlMicChe, 963);
        return 0;
      }
      v17 = v9[2];
      v15 = (uint16_t)(v9[3] + 1 - v17);
      if ( v15 >= (uint16_t)v14 )
      {
        v15 = (uint16_t)v14;
        goto LABEL_11;
      }
    }
  }
  v19 = (volatile int16_t **)off_138FE0;
  v20 = (volatile char *)&_frame.v45;
  v21 = 8;
  while ( 1 )
  {
    v22 = *((volatile uint64_t *)v9 + 1);
    v23 = v22;
    v24 = WORD2(v22) + 1;
    v25 = (uint16_t)(WORD2(v22) + 1 - v22);
    v26 = (volatile uint8_t *)(v22 + v15);
    if ( (int)(v21 + v15) <= v25 )
      break;
    v27 = (uint16_t)(v25 - v15);
    v28 = v27 - 1;
    if ( v27 )
    {
      v21 = (uint16_t)(v21 + v15 + v23 - v24);
      goto LABEL_16;
    }
    v21 = (uint16_t)(v23 + v21 + v15 - v24);
LABEL_19:
    v9 = (volatile uint32_t *)v9[1];
    v15 = 0;
    if ( **v19 < 0 && !v9 )
    {
      bad_func_0x12f408((int)aPdNull, (int)aRxuCntrlMicChe, 1005);
      return 0;
    }
  }
  v27 = v21;
  v28 = v21 - 1;
  v21 = 0;
LABEL_16:
  v29 = &v26[v28 + 1];
  v30 = (uintptr_t)(v20) - (uintptr_t)(v26);
  do
  {
    v26[v30] = *v26;
    ++v26;
  }
  while ( v26 != v29 );
  v20 += v27;
  if ( v21 )
    goto LABEL_19;
  if ( !a4 )
  {
    *(volatile uint64_t *)(a2 + 16) = _frame.v45;
    return 1;
  }
LABEL_36:
  patch_handle_data(a2);
  if ( _frame.v45 == *(volatile uint64_t *)a2 )
    return 1;
  v39 = ke_msg_alloc(5126, 13, 5, 24);
  v40 = v4[6];
  v41 = dword_138FD8 + 696 * *((volatile uint8_t *)v4 + 9);
  v42 = *((volatile uint64_t *)v4 + 2);
  v43 = *(volatile uint32_t *)(v41 + 38);
  *(volatile uint16_t *)(v39 + 4) = *(volatile uint16_t *)(v41 + 42);
  *(volatile uint64_t *)(v39 + 8) = v42;
  *(volatile uint32_t *)v39 = v43;
  *(volatile uint8_t *)(v39 + 18) = *((volatile uint8_t *)v4 + 10);
  *(volatile uint8_t *)(v39 + 16) = (v40 & 0x400) != 0;
  *(volatile uint8_t *)(v39 + 17) = *(volatile uint8_t *)(v4[8] + 97);
  ke_msg_send_2(v39);
  return 0;
}


// ll_rx_irq @ 0x138fe4
int ll_rx_irq(int a1, int a2, int a3) {
  volatile uint16_t *v3; // r6
  char v5; // r5
  int v7; // r10
  int v8; // r9
  int v9; // r7
  volatile uint32_t *v10; // r4
  int v11; // r2
  int16_t v13; // r2
  char v14; // r1
  volatile unsigned int v15; // r1
  void *v16; // r3
  uint64_t v17; // r2
  int v18; // r0
  volatile unsigned int v19; // r3
  int v20; // r0
  int v21; // r5
  int16_t v22; // r3
  int16_t v23; // r6
  int16_t v24; // r1
  int v25; // r0
  int v26; // r3
  volatile uint32_t *v27; // r0
  uint64_t a2a[3]; // [sp+8h] [bp-18h] BYREF

  v3 = (void *)(uintptr_t)(off_139284);
  v5 = a2;
  if ( a3 )
  {
    v7 = *((volatile uint8_t *)off_139284 + 7);
    v8 = *(volatile uint16_t *)off_139284 & 0x400;
    if ( (*(volatile uint16_t *)off_139284 & 0x400) == 0 )
      goto LABEL_3;
LABEL_14:
    v10 = *((volatile uint32_t **)off_139284 + 22);
    v11 = *((volatile uint16_t *)off_139284 + 2);
    v9 = *((volatile uint8_t *)off_139284 + 6);
    if ( v10 )
      goto LABEL_7;
LABEL_15:
    if ( v9 )
      return 0;
    v10 = mem_word_load(dword_139288);
    if ( !v10 )
    {
      v27 = mem_word_load(dword_139294);
      v10 = v27;
      if ( **(volatile int16_t **)off_13929C < 0 && !v27 )
        mmio_clear_register((int)aDefragNull, (int)aRxuCntrlDefrag, 1111);
      tx_power_lookup(0, 4, v10[5]);
    }
    v13 = v3[2];
    *((volatile uint8_t *)v10 + 6) = v5;
    *((volatile uint8_t *)v10 + 7) = v7;
    *((volatile uint8_t *)v10 + 8) = 1;
    *((volatile uint8_t *)v10 + 4) = 0;
    v14 = *((volatile uint8_t *)v3 + 8);
    v10[4] = 0;
    *((volatile uint8_t *)v10 + 9) = v14;
    v15 = (*(volatile uint32_t *)0x40501010u);
    v16 = (void *)(uintptr_t)(off_139290);
    *((volatile uint16_t *)v10 + 5) = v13;
    v10[14] = (int)(uintptr_t)(v16);
    v10[15] = (int)(uintptr_t)(v10);
    unknown_worker(v10 + 13, v15 + 100000);
    if ( (v3[24] & 1) != 0 )
      ll_state_machine_1(a1, (int)(uintptr_t)(v10 + 7), 1, 0);
    *(volatile uint32_t *)(a1 + 96) &= ~0x20u;
    rf_get_rssi_3(a1, 1);
    v17 = (v17 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(*((volatile uint32_t *)v3 + 16)) << 32);
    v17 = (v17 & ~0xFFFFFFFFull) | ((uint32_t)(*((volatile uint32_t *)v3 + 7)) & 0xFFFFFFFFu);
    v18 = dword_139294;
    *((volatile uint64_t *)v10 + 2) = v17;
    *((volatile uint8_t *)v10 + 5) = *((volatile uint8_t *)v3 + 49);
    *((volatile uint16_t *)v10 + 6) = *(volatile uint16_t *)(a1 + 48);
    cmd_handler_a(v18, v10);
    goto LABEL_20;
  }
  v8 = *(volatile uint16_t *)off_139284 & 0x400;
  v7 = 0;
  if ( (*(volatile uint16_t *)off_139284 & 0x400) != 0 )
    goto LABEL_14;
LABEL_3:
  v9 = *((volatile uint8_t *)off_139284 + 6);
  if ( *((volatile uint8_t *)off_139284 + 6) )
  {
    v10 = *((volatile uint32_t **)off_139284 + 22);
    v11 = *((volatile uint16_t *)off_139284 + 2);
    if ( !v10 )
      return *((volatile uint32_t *)off_139284 + 22);
LABEL_7:
    while ( *((volatile uint8_t *)v10 + 6) != a2
         || *((volatile uint8_t *)v10 + 7) != v7
         || *((volatile uint16_t *)v10 + 5) != v11 )
    {
      v10 = (volatile uint32_t *)*v10;
      if ( !v10 )
        goto LABEL_15;
    }
    if ( *((volatile uint8_t *)v10 + 8) != v9 )
      return 0;
    v21 = (uint16_t)(*(volatile uint16_t *)(a1 + 48) - *((volatile uint8_t *)v10 + 9));
    v22 = *((volatile uint16_t *)v10 + 6) + v21;
    *((volatile uint8_t *)v10 + 8) = v9 + 1;
    *((volatile uint16_t *)v10 + 6) = v22;
    if ( (v3[24] & 1) != 0 )
    {
if ( ll_state_machine_1(a1, (int)(uintptr_t)(v10 + 7), 0, v8 == 0) ) { v26 = *(volatile uint32_t *)(a1 + 96);
        if ( !v8 )
        {
          *((volatile uint16_t *)v10 + 6) -= 8;
          *(volatile uint32_t *)(a1 + 96) = v26 & 0xFFFFFF9F | 0x40;
          mac_mcps_request(a1, v21, v10[4], *((volatile uint8_t *)v10 + 9), 0, 0);
          v10[4] += v21;
          v23 = 1;
          goto LABEL_30;
        }
        *(volatile uint32_t *)(a1 + 96) = v26 & 0xFFFFFF9F | 0x40;
        mac_mcps_request(a1, v21, v10[4], *((volatile uint8_t *)v10 + 9), 0, 0);
        v10[4] += v21;
LABEL_20:
        v19 = (*(volatile uint32_t *)0x40501010u);
        v10[6] = v19;
        return 1;
      }
      v23 = 4;
    }
    else
    {
      v23 = 1;
    }
    *(volatile uint32_t *)(a1 + 96) = *(volatile uint32_t *)(a1 + 96) & 0xFFFFFF9F | 0x40;
    mac_mcps_request(a1, v21, v10[4], *((volatile uint8_t *)v10 + 9), 0, 0);
    v10[4] += v21;
    if ( !v8 )
    {
LABEL_30:
      if ( *((volatile uint8_t *)v10 + 5) )
        v24 = 24;
      else
        v24 = 8;
      v25 = tx_power_lookup(0, v24, v10[5]);
      if ( v25 )
        *(volatile uint32_t *)(v25 + 72) = *((volatile uint16_t *)v10 + 6);
      tx_power_lookup(0, v23, v10[5]);
      fault_handler((int)(uintptr_t)(v10 + 13));
      cmd_handler_c(dword_139294, v10);
      cmd_handler_a(dword_139288, v10);
      goto LABEL_20;
    }
    goto LABEL_20;
  }
  if ( (*((volatile uint8_t *)off_139284 + 48) & 1) != 0 )
  {
if ( !ll_state_machine_1(a1, (int)(uintptr_t)(a2a), 1, 1) ) return v9;
    *(volatile uint16_t *)(a1 + 48) -= 8;
  }
  v20 = dword_139298 + 1320 * *((volatile uint8_t *)v3 + 10);
  if ( *(volatile uint8_t *)(v20 + 1227)
    && phy_config_set(
         (volatile uint8_t *)(v20 + 107),
         (volatile uint32_t *)(v20 + 1228),
         *(volatile uint32_t *)(*(volatile uint32_t *)(a1 + 28) + 8),
         a3) == 1 )
  {
    return v9;
  }
  rf_get_rssi_3(a1, 3);
  return 1;
}


// list_find @ 0x1392a8
int list_find(int result, unsigned int a2) {
  uint16_t v2; // r2
  char v3; // r7
  char v4; // r4
  int v5; // r3
  int v6; // r3
  char v7; // r7
  int16_t v8; // r1

  if ( a2 )
  {
    v2 = 0;
    v3 = *(volatile uint8_t *)(result + 10);
    do
    {
      v4 = *(volatile uint8_t *)(result + 11);
      v5 = (v3 + (uint8_t)v2++) & 0x3F;
      v6 = result + 4 * v5;
      if ( !v4 )
        break;
      if ( *(volatile uint32_t *)(v6 + 16) )
      {
        *(volatile uint32_t *)(v6 + 16) = 0;
        *(volatile uint8_t *)(result + 11) = v4 - 1;
      }
    }
    while ( v2 < a2 );
  }
  else
  {
    v3 = *(volatile uint8_t *)(result + 10);
  }
  v7 = v3 + a2;
  v8 = (a2 + *(volatile uint16_t *)(result + 8)) & 0xFFF;
  *(volatile uint8_t *)(result + 10) = v7 & 0x3F;
  *(volatile uint16_t *)(result + 8) = v8;
  return ke_msg_dispatch(result);
}



// rf_get_chan_param @ 0x1392f4
volatile uint32_t ** rf_get_chan_param(int a1, int a2) {
  volatile uint32_t **result; // r0
  unsigned int v3; // r2
  int v4; // r1
  int v5; // r3
  int16_t v6; // r1

  result = *(volatile uint32_t ***)(dword_139338 + 4 * (174 * a1 + (*(volatile uint16_t *)(a2 + 16) >> 12) + 102));
  if ( result )
  {
    v3 = *(volatile uint16_t *)(a2 + 18);
    v4 = *((volatile uint16_t *)result + 4);
    if ( v4 != v3 >> 4 )
    {
      v5 = (v3 >> 4) - v4;
      v6 = (v3 >> 4) - v4;
      if ( (v5 & 0x800) == 0 )
      {
        list_find((int)result, v6 & 0xFFF);
        return (void *)(uintptr_t)(((int (*)())load_and_process_r0)((void *)((volatile uint32_t **)dword_13933C)));
      }
    }
  }
  return result;
}



// ll_get_conn @ 0x139340
int ll_get_conn(int a1, int a2) {
  volatile uint16_t *v2; // r6
  int v3; // r7
  int v5; // r4
  int v7; // r12
  int v8; // r9
  int v9; // r1
  int v10; // r7
  int v11; // r3
  int16_t v12; // r3
  unsigned int v13; // r1
  int v14; // r2
  int v16; // r4
  int v17; // r0
  volatile uint32_t *v18; // r2
  int v19; // r3
  int v20; // r2
  int16_t v21; // r2
  int16_t v22; // r3
  int v23; // r9
  volatile int16_t *v24; // r2
  unsigned int v25; // r3
  int16_t v26; // r3
  int16_t v27; // r3

  v2 = (void *)(uintptr_t)(off_139564);
  v3 = dword_139568 + 1320 * *((volatile uint8_t *)off_139564 + 10);
  v5 = *(volatile uint8_t *)(v3 + 1227);
  if ( !*(volatile uint8_t *)(v3 + 1227) )
  {
    v7 = *((volatile uint8_t *)off_139564 + 7);
    v8 = dword_139580;
    v9 = *((volatile uint16_t *)off_139564 + 2);
    v10 = *(volatile uint32_t *)(dword_139580 + 4 * (v7 + 174 * a2 + 102));
    v11 = *(volatile uint16_t *)(v10 + 8);
    if ( v11 != v9 )
      goto LABEL_3;
    goto LABEL_28;
  }
  v8 = dword_139580;
v17 = phy_config_set((volatile uint8_t *)(v3 + 107), (volatile uint32_t *)(v3 + 1228), (int)(uintptr_t)(*(volatile char **)(*(volatile uint32_t *)(a1 + 28) + 8)), 1);
  v7 = *((volatile uint8_t *)v2 + 7);
  v9 = (uint16_t)v2[2];
  v10 = *(volatile uint32_t *)(v8 + 4 * (v7 + 174 * a2 + 102));
  v11 = *(volatile uint16_t *)(v10 + 8);
  v5 = v17 == 1;
  if ( v9 == v11 )
  {
LABEL_15:
    if ( v5 )
    {
      v16 = 0;
LABEL_17:
      v18 = (void *)(uintptr_t)(off_13956C);
      *(volatile uint8_t *)(v10 + 288) = 1;
      v19 = *(volatile uint8_t *)(v10 + 10);
      *(volatile uint32_t *)(v10 + 4) = v18[4];
      v20 = v10 + 4 * v19;
      if ( *(volatile uint32_t *)(v20 + 16) )
      {
        *(volatile uint32_t *)(v20 + 16) = 0;
        --*(volatile uint8_t *)(v10 + 11);
      }
      v21 = (*(volatile uint16_t *)(v10 + 8) + 1) & 0xFFF;
      *(volatile uint8_t *)(v10 + 10) = (v19 + 1) & 0x3F;
      *(volatile uint16_t *)(v10 + 8) = v21;
      ke_msg_dispatch(v10);
      lookup_tx_power_limit(a2, *((volatile uint8_t *)v2 + 7));
      return v16;
    }
LABEL_28:
    v26 = *(volatile uint16_t *)(a1 + 50) & 0xFF00;
    *(volatile uint32_t *)(a1 + 96) |= 0x20u;
    *(volatile uint16_t *)(a1 + 50) = v26;
    rf_get_rssi_3(a1, 3);
    v16 = 1;
    goto LABEL_17;
  }
LABEL_3:
  while ( 1 )
  {
    v12 = v9 - v11;
    v13 = v12 & 0xFFF;
    if ( (v12 & 0xFC0) == 0 )
      break;
    if ( v13 > 0x7FE )
    {
      if ( !*(volatile uint8_t *)(v10 + 288) )
      {
        if ( (*v2 & 0x800) == 0 )
        {
          v14 = (v14 & ~0xFFFFu) | ((uint16_t)(v2[1]) & 0xFFFFu);
LABEL_8:
          *(volatile uint16_t *)(v8 + 2 * (v7 + 348 * a2) + 554) = v14;
          if ( !v5 )
          {
            v22 = *(volatile uint16_t *)(a1 + 50) & 0xFF00;
            *(volatile uint32_t *)(a1 + 96) |= 0x20u;
            *(volatile uint16_t *)(a1 + 50) = v22;
            rf_get_rssi_3(a1, 3);
          }
LABEL_10:
          lookup_tx_power_limit(a2, *((volatile uint8_t *)v2 + 7));
          return (uint8_t)(1 - v5);
        }
        v14 = (uint16_t)v2[1];
        if ( *(volatile uint16_t *)(v8 + 2 * (v7 + 348 * a2) + 554) != v14 )
          goto LABEL_8;
      }
      return 0;
    }
    list_find(v10, (uint16_t)(v13 - 63));
    v7 = *((volatile uint8_t *)v2 + 7);
    v9 = (uint16_t)v2[2];
    v10 = *(volatile uint32_t *)(v8 + 4 * (174 * a2 + v7 + 102));
    v11 = *(volatile uint16_t *)(v10 + 8);
    if ( v9 == v11 )
      goto LABEL_15;
  }
  v23 = v10 + 4 * ((*(volatile uint8_t *)(v10 + 10) + (uint8_t)v12) & 0x3F);
  *(volatile uint8_t *)(v10 + 288) = 1;
  if ( !*(volatile uint32_t *)(v23 + 16) )
  {
    if ( !v5 )
    {
      v27 = *(volatile uint16_t *)(a1 + 50) & 0xFF00;
      *(volatile uint32_t *)(a1 + 96) |= 0x20u;
      *(volatile uint16_t *)(a1 + 50) = v27;
      rf_get_rssi_3(a1, 3);
    }
    *(volatile uint32_t *)(v23 + 16) = dword_139570;
    v24 = *(volatile int16_t **)off_139574;
    v25 = (uint8_t)(*(volatile uint8_t *)(v10 + 11) + 1);
    *(volatile uint8_t *)(v10 + 11) = v25;
    if ( *v24 < 0 && v25 > 0x40 )
    {
      mmio_clear_register(dword_13957C, dword_139578, 1860);
      v25 = *(volatile uint8_t *)(v10 + 11);
    }
    if ( v25 == 1 )
      unknown_worker((void *)(uintptr_t)(v10 + 272), *((volatile uint32_t *)off_13956C + 4) + 50000);
    goto LABEL_10;
  }
  return 0;
}



// bt_scan_event @ 0x139584
int bt_scan_event(uint16_t a1, int a2, int a3, int a4, volatile uint8_t *a5, int a6, volatile uint16_t *a7, volatile uint8_t *a8) {
  int v9; // r12
  unsigned int v11; // r5
  int v12; // r8
  int v13; // r4
  int v15; // r5
  unsigned int v16; // r0
  int v17; // r5
  volatile int *v18; // r3
  int v19; // r3
  int v20; // r2
  int v21; // r5
  unsigned int v22; // r8
  unsigned int v23; // r6
  int v24; // r10
  uint16_t v25; // r11
  volatile uint8_t *v26; // r3
  volatile uint8_t *v27; // r0
  volatile uint8_t *v28; // r10
  volatile uint8_t *v29; // r11
  uint16_t v30; // r5
  unsigned int v31; // r1
  int v32; // r3
  volatile uint8_t *v33; // r2
  int v34; // r4
  unsigned int v35; // r1
  uint16_t v36; // r0
  volatile uint8_t *v37; // r8
  int v38; // r3
  int v39; // r9
  int v40; // r4
  unsigned int v41; // r10
  int v42; // r7
  volatile uint8_t *v43; // r9
  unsigned int v44; // r4
  unsigned int v45; // r10
  int v46; // r0
  int v47; // r2
  unsigned int v48; // r1
  volatile uint32_t *v49; // r0
  int v50; // r1
  struct __attribute__((packed)) { uint8_t a3a; // [sp+Eh] [bp-6h] BYREF
  uint8_t v53[5]; // [sp+Fh] [bp-5h] BYREF
  } _frame;
  v9 = (uint8_t)*a5;
  if ( v9 == 255 )
  {
    v16 = a1 & 0xFC;
    if ( v16 == 176 )
    {
      is_hw_feature_6();
      return 1;
    }
    if ( v16 > 0xB0 )
    {
      if ( v16 != 208 )
        return 1;
LABEL_12:
      v15 = a6 + a3;
      if ( a4 == 255 )
        return 1;
      switch ( *(volatile uint8_t *)(a6 + a3) )
      {
        case 0:
          v39 = *(volatile uint8_t *)(v15 + 1);
          event_dispatch("rx spectrum action: action code=%d\n", v39);
          v37 = (volatile uint8_t *)(v15 + 1);
          if ( v39 == 4 )
          {
            v40 = (uint8_t)*a5;
            if ( v40 != 255 )
            {
              v41 = dword_139A90;
              v42 = (uint8_t)rx_packet_handler_2((void *)(uintptr_t)(v15 + 2), a2 - a3 - 2, _frame.v53, 1320 * v40 + 1212 + dword_139A90);
              event_dispatch("csa count=%d, mode=%d!\n", v42, _frame.v53[0]);
              if ( v42 )
              {
                v43 = (volatile uint8_t *)(1320 * v40 + v41);
                if ( !v43[106] )
                {
                  if ( !v43[146] && v43[148] && _frame.v53[0] == 1 )
                    hci_send_cmd_0x59(v43[107], 0);
                  v44 = v41 + 1320 * v40;
                  *(volatile uint8_t *)(v44 + 146) = v42;
                  *(volatile uint8_t *)(v44 + 148) = 1;
                }
              }
            }
          }
          goto LABEL_65;
        case 3:
          v36 = ll_cmd_handler(a4, (volatile uint16_t *)v15, *(volatile uint8_t *)(v15 + 1));
          v9 = v36;
          if ( v36 != 33 )
          {
            v30 = (char)v36 << 8;
            v13 = 0;
            *a7 = 8;
            goto LABEL_49;
          }
          return 0;
        case 5:
          v31 = dword_139858;
          if ( *(volatile uint8_t *)(dword_139858 + 1320 * v9 + 106) == 2
            || (v32 = *(volatile uint8_t *)(v15 + 1), v33 = (volatile uint8_t *)(v15 + 1), *(volatile uint8_t *)(v15 + 1)) )
          {
            v13 = 1;
LABEL_84:
            if ( v9 == 255 )
              goto LABEL_88;
            v33 = (volatile uint8_t *)(v15 + 1);
            if ( *(volatile uint8_t *)(dword_139A90 + 1320 * v9 + 106) )
              goto LABEL_46;
            v9 = 255;
          }
          else
          {
            *a7 = 11;
            v34 = (uint8_t)*a5;
            if ( v34 == 255 )
            {
              v30 = v32;
              v13 = 1;
              goto LABEL_50;
            }
            v35 = v31 + 1320 * v34;
            v13 = *(volatile uint8_t *)(v35 + 106);
            if ( *(volatile uint8_t *)(v35 + 106) )
            {
              v9 = v32;
              v13 = 1;
              goto LABEL_48;
            }
            v9 = *(volatile uint8_t *)(v35 + 106);
          }
          if ( (unsigned int)*v33 - 6 > 1 )
          {
LABEL_88:
            v13 = 1;
            goto LABEL_47;
          }
          *a7 = 12;
          v30 = 0;
LABEL_50:
          *a7 |= v30;
          return v13;
        case 7:
          v13 = *(volatile uint8_t *)(v15 + 1);
          if ( *(volatile uint8_t *)(v15 + 1) )
          {
            if ( v13 != 1 )
              goto LABEL_46;
            if ( (*(volatile uint32_t *)(dword_139870 + 696 * a4 + 4) & 2) != 0 )
            {
              v13 = *(volatile uint8_t *)(v15 + 2) & 1;
              if ( (*(volatile uint8_t *)(v15 + 2) & 1) != 0 )
              {
                ((int (*)())bt_get_conn_entry)(a4, 0xFFu, 0);
                v13 = 0;
              }
              else
              {
                ((int (*)())bt_get_conn_entry)(a4, 0xFFu, 0xFFu);
              }
              v9 = 255;
              goto LABEL_47;
            }
          }
          else if ( (*(volatile uint32_t *)(dword_139AA0 + 696 * a4 + 4) & 2) != 0 )
          {
            v48 = *(volatile uint8_t *)(v15 + 2);
            if ( v48 <= 1 )
            {
              ((int (*)())bt_get_conn_entry)(a4, v48, 0xFFu);
              v9 = 255;
              goto LABEL_47;
            }
          }
          goto LABEL_69;
        case 8:
          if ( a2 - a3 <= 3 )
            goto LABEL_69;
          if ( v9 == 255 )
            goto LABEL_88;
          v13 = *(volatile uint8_t *)(v15 + 1) | *(volatile uint8_t *)(dword_139A90 + 1320 * v9 + 106);
          if ( v13 )
            goto LABEL_46;
          *a7 = 6;
          v30 = 0;
          goto LABEL_50;
        case 0x15:
          v37 = (volatile uint8_t *)(v15 + 1);
LABEL_65:
          v38 = *v37;
          if ( v38 == 1 )
          {
            rf_set_address((volatile uint32_t *)(v15 + 2), (volatile uint32_t *)(v15 + 10));
          }
          else
          {
            if ( v38 != 2 )
            {
LABEL_46:
              v13 = 1;
              v9 = 255;
              goto LABEL_47;
            }
            if ( (*(volatile uint32_t *)(dword_139870 + 696 * a4 + 4) & 0x24) != 0 && *(volatile char *)(v15 + 2) >= 0 )
            {
              ((int (*)())bt_get_conn_entry)(a4, *(volatile uint8_t *)(v15 + 2) & 3, *(volatile uint8_t *)(v15 + 2) >> 4);
              v13 = 0;
              v9 = 255;
LABEL_47:
              if ( *a7 == 255 )
                return v13;
LABEL_48:
              v30 = (uint16_t)v9 << 8;
LABEL_49:
              if ( **(volatile int16_t **)dword_13986C < 0 && v9 == 255 )
                mmio_clear_register((int)aTaskIdx0xff, (int)aRxuMgtRouteAct, 2326);
              goto LABEL_50;
            }
          }
LABEL_69:
          v13 = 0;
          v9 = 255;
          goto LABEL_47;
        case 0x16:
          v13 = 0;
          goto LABEL_84;
        default:
          goto LABEL_46;
      }
    }
    if ( v16 == 64 )
    {
LABEL_33:
      if ( !*(volatile uint8_t *)(dword_139860 + 0x12) )
        return 1;
      v20 = **(volatile uint8_t **)dword_139864;
      if ( (unsigned int)(v20 - 1) > 1 && v20 != 4 )
        return 1;
      v21 = *(volatile uint32_t *)(dword_139860 + 8);
      if ( !v21 )
        return 1;
      v22 = dword_139874;
      v23 = dword_139868;
      v13 = 1;
      while ( 1 )
      {
        if ( *(volatile uint8_t *)(v21 + 106) == 2 && *(volatile uint8_t *)(v21 + 108) && !*(volatile uint8_t *)(v21 + 1224) )
        {
          v24 = *(volatile uint8_t *)(v21 + 107);
          v25 = *(volatile uint16_t *)(v22 + 2 * v24);
          v26 = buf_calc_3((volatile uint8_t *)(a6 + 24), (uint16_t)(a2 - 24), &_frame.a3a);
          v27 = (volatile uint8_t *)(v23 + (v24 << 9) + 36);
          v28 = v26;
          v29 = buf_calc_3(v27, (uint16_t)(v25 - 36), _frame.v53);
          if ( _frame.v53[0] )
          {
            if ( _frame.a3a )
            {
              v45 = (unsigned int)(v28 + 2);
              v46 = memcmp(v45, (unsigned int)aDirect, 7u);
              v47 = _frame.a3a;
              if ( v46 && _frame.a3a == _frame.v53[0] )
              {
                if ( !memcmp(v45, (unsigned int)(v29 + 2), _frame.a3a) )
                {
                  event_dispatch(aSsidMatch);
                  v49 = (volatile uint32_t *)dword_139AAC;
                  *(volatile uint8_t *)dword_139AA8 = 1;
                  v50 = (*(volatile uint32_t *)0x40501010u) + 200000;
                  unknown_worker(v49, v50);
                }
                v47 = _frame.a3a;
              }
              if ( v47
                && (!memcmp(v45, (unsigned int)aDirect, 7u)
                 || _frame.a3a != _frame.v53[0]
                 || memcmp(v45, (unsigned int)(v29 + 2), _frame.a3a)) )
              {
                goto LABEL_38;
              }
            }
          }
          else if ( _frame.a3a )
          {
            return 1;
          }
          bt_link_state_check(v21, (volatile char *)(a6 + 10));
          v13 = 0;
        }
LABEL_38:
        v21 = *(volatile uint32_t *)v21;
        if ( !v21 )
          return v13;
      }
    }
    if ( v16 != 128 )
      return 1;
    v17 = 0;
  }
  else
  {
    v11 = a1 & 0xFC;
    v12 = *(volatile uint8_t *)(dword_139858 + 1320 * v9 + 106);
    if ( v11 != 128 )
    {
      if ( (a1 & 0xFCu) <= 0x80 )
      {
        if ( v11 != 64 )
        {
          if ( v11 > 0x40 )
          {
            v13 = 1;
            if ( v11 == 80 )
            {
              *a8 = 1;
              *a7 = 4;
            }
            return v13;
          }
          if ( (a1 & 0xDC) != 0x10 )
            return 1;
          goto LABEL_19;
        }
        goto LABEL_33;
      }
      if ( v11 != 192 )
      {
        if ( v11 > 0xC0 )
        {
          if ( v11 != 208 )
            return 1;
          goto LABEL_12;
        }
        if ( v11 != 160 && (v11 != 176 || is_hw_feature_6()) )
          return 1;
      }
LABEL_19:
      if ( !v12 )
      {
        *a7 = 6;
        return 1;
      }
      return 1;
    }
    v17 = dword_139858 + 1320 * v9;
  }
  if ( rx_rate_field_parse(4u) == 1 )
  {
    v18 = (volatile int *)dword_13985C;
    *a8 = 1;
    v19 = *v18;
    *a7 = 4;
    *a5 = *(volatile uint8_t *)(v19 + 366);
  }
  if ( a4 != 255 && *(volatile uint8_t *)(v17 + 108) )
  {
    rx_process_packet_1(v17, a2, a6);
    return 1;
  }
  return 1;
}


// tx_send_packet_1 @ 0x139ab0
int tx_send_packet_1(int a1, int a2) {
  int v2; // r7
  volatile int16_t *v3; // r9
  int v4; // r6
  volatile uint8_t *v7; // r8
  int v8; // r0
  int v10; // r10
  int16_t v11; // r0
  int v12; // r9
  int v13; // r11
  char v14; // r5
  int16_t v15; // r3^2
  volatile uint16_t *v16; // r0
  volatile int *v17; // r3
  char v18; // r3
  struct __attribute__((packed)) { int v19; // [sp+10h] [bp-24h]
  char _pad1[2]; int16_t v20; // [sp+16h] [bp-1Eh]
  char _pad2[4]; unsigned int v21; // [sp+1Ch] [bp-18h]
  char _pad3[4]; uint8_t v22; // [sp+24h] [bp-10h] BYREF
  char v23; // [sp+25h] [bp-Fh] BYREF
  int16_t v24; // [sp+26h] [bp-Eh] BYREF
  uint64_t v25; // [sp+28h] [bp-Ch] BYREF
  } _frame;
  v2 = *(volatile uint32_t *)(a1 + 28);
  v3 = *(volatile int16_t **)(v2 + 8);
  _frame.v22 = 1;
  if ( (*v3 & 0x400) == 0 )
  {
    v4 = v3[11] & 0xF;
    if ( !v4 )
    {
      if ( a2 == 255 )
      {
        if ( (*(volatile uint32_t *)(a1 + 84) & 0x600) != 0 )
        {
LABEL_31:
          v18 = -1;
        }
        else
        {
          v17 = *((volatile int **)off_139CD8 + 2);
          if ( v17 )
          {
            while ( *((volatile uint16_t *)v17 + 50) != (uint16_t)v3[2]
                 || *((volatile uint16_t *)v17 + 51) != (uint16_t)v3[3]
                 || *((volatile uint16_t *)v17 + 52) != (uint16_t)v3[4] )
            {
              v17 = (volatile int *)*v17;
              if ( !v17 )
                goto LABEL_31;
            }
            v18 = *((volatile uint8_t *)v17 + 107);
          }
          else
          {
            v18 = -1;
          }
        }
        v7 = (void *)(uintptr_t)(off_139CDC);
        *((volatile uint8_t *)off_139CDC + 10) = v18;
      }
      else if ( *((volatile uint8_t *)off_139CD8 + 16) == 255 )
      {
        v7 = (void *)(uintptr_t)(off_139CDC);
      }
      else
      {
        v7 = (void *)(uintptr_t)(off_139CDC);
        if ( (v3[2] & 1) == 0 )
        {
          v16 = (volatile uint16_t *)(1320 * *((volatile uint8_t *)off_139CDC + 10) + 100 + dword_139CE8);
          if ( *v16 == (uint16_t)v3[2] && v16[1] == (uint16_t)v3[3] && v16[2] == (uint16_t)v3[4] )
            *((volatile uint8_t *)off_139CDC + 10) = -1;
} } if ( lookup_rate_table_entry((void *)(uintptr_t)(off_139CDC), (int)(uintptr_t)(v3), *(volatile uint16_t *)(a1 + 48), &_frame.v22) ) { v8 = _frame.v22;
      }
      else
      {
        _frame.v20 = *v3;
        _frame.v19 = (uint8_t)v7[8];
        v10 = *(volatile uint16_t *)(a1 + 48);
        _frame.v21 = *(volatile uint32_t *)(v2 + 8);
        v11 = *v3;
        _frame.v23 = 0;
        _frame.v24 = 255;
        v8 = bt_scan_event(v11, v10, _frame.v19, a2, (volatile uint8_t *)dword_139CE0, _frame.v21, &_frame.v24, &_frame.v23);
        if ( _frame.v24 != 255 )
        {
          v12 = ke_msg_alloc(10240, _frame.v24, 10, (uint16_t)(v10 + 12));
          rf_call_handler(&_frame.v25, 0);
          v13 = v10;
          if ( !_frame.v23 )
          {
            if ( **(volatile int16_t **)off_139CE4 < 0 && _frame.v19 << 30 )
              call_shared_handler(dword_139CF0, dword_139CEC, 2608);
            v4 = _frame.v19;
            v13 = v10 - _frame.v19;
            v10 = (uint16_t)(v10 - _frame.v19);
          }
          *(volatile uint16_t *)v12 = v10;
          mem_is_null(v2, v10, v4, v12 + 12);
          *(volatile uint8_t *)(v12 + 8) = v7[10];
          *(volatile uint8_t *)(v12 + 7) = a2;
          *(volatile uint16_t *)(v12 + 2) = _frame.v20;
          v14 = *(volatile uint8_t *)(a1 + 65);
          rf_get_field0();
          v15 = WORD1(_frame.v25);
          *(volatile uint8_t *)(v12 + 6) = _frame.v25;
          *(volatile uint8_t *)(v12 + 9) = v14;
          *(volatile uint16_t *)(v12 + 4) = v15;
          ke_msg_send_2(v12);
          if ( _frame.v24 == 4 )
            ll_event_prepare(
              _frame.v21,
              v13,
              *(volatile uint32_t *)(a1 + 52),
              *(volatile uint16_t *)(v12 + 4),
              *(volatile uint8_t *)(v12 + 6),
              *(volatile char *)(v12 + 9),
              *(volatile uint8_t *)(a1 + 61));
          return 0;
        }
        _frame.v22 = v8;
      }
      if ( v8 )
      {
        rf_rssi_calibrate(a1, 3);
        return 1;
      }
    }
  }
  return 0;
}



// bt_init_mod @ 0x139cf4
void *bt_init_mod() {
  volatile uint32_t *v0; // r6
  int v1; // r4
  int v2; // r5
  volatile uint32_t *v3; // r1
  int v4; // r3
  void *result; // r0
  int v6; // r1

  v0 = (volatile uint32_t *)(dword_139D6C + 16);
  zero_8_bytes((volatile uint32_t *)dword_139D6C);
  v1 = dword_139D70;
  zero_8_bytes(v0);
  v2 = v1 + 4672;
  do
  {
    v3 = (volatile uint32_t *)v1;
    v1 += 292;
    cmd_handler_a((int)v0, v3);
  }
  while ( v1 != v2 );
  zero_8_bytes((volatile uint32_t *)dword_139D74);
  zero_8_bytes((volatile uint32_t *)dword_139D78);
  cmd_handler_a(dword_139D74, (volatile uint32_t *)dword_139D7C);
  cmd_handler_a(dword_139D74, (volatile uint32_t *)dword_139D80);
  cmd_handler_a(dword_139D74, (volatile uint32_t *)dword_139D84);
  v4 = dword_139D8C;
  result = (void *)(uintptr_t)(off_139D90);
  *((volatile uint16_t *)off_139D88 + 51) = -1;
  v6 = v4 + 15360;
  do
  {
    *(volatile uint8_t *)(v4 - 52) = 0;
    *(volatile uint16_t *)(v4 + 8) = 0;
    *(volatile uint32_t *)(v4 - 64) = (int)(uintptr_t)(result);
    *(volatile uint32_t *)(v4 - 60) = v4;
    *(volatile uint32_t *)(v4 - 48) = v4;
    v4 += 80;
  }
  while ( v6 != v4 );
  return result;
}


// scan_parse_report @ 0x139d94
int scan_parse_report(volatile char *a1, char a2, int a3) {
  char v4; // r3
  int v6; // r4
  volatile char *v7; // r8
  int v8; // r7
  int v10; // r2
  int v11; // r3
  volatile char *v12; // r5
  int v13; // r6
  unsigned int v14; // r3
  volatile unsigned int v15; // r4
  volatile unsigned int v16; // r3
  char a1a[2]; // [sp+6h] [bp-2h] BYREF

  if ( *a1 >= 0 )
    v4 = 24;
  else
    v4 = 26;
  *(volatile uint16_t *)a1a = 0;
  if ( (a2 & 0x78) == 8 )
  {
    v4 += 8;
  }
  else if ( (a2 & 0x7C) == 4 )
  {
    v4 += 4;
  }
  v6 = (uint8_t)(v4 + 6);
  v7 = &a1[v6];
  memcpy(a1a, &a1[v6], 2u);
  v8 = a1[4] & 1;
  if ( (a1[4] & 1) != 0 )
  {
    if ( *(volatile uint16_t *)a1a == 1544 )
      return v8;
    if ( *(volatile uint16_t *)a1a != 56710 )
      return 0;
  }
  else if ( *(volatile uint16_t *)a1a != 56710 )
  {
    if ( *(volatile uint16_t *)a1a == 8 )
    {
      v10 = (uint8_t)v7[11];
      if ( v10 == 2 )
      {
        event_dispatch("igmp:%x,%x\n", (uint8_t)v7[10], 2);
        return v8;
      }
      if ( v10 == 17 )
      {
        v12 = &a1[4 * (v7[2] & 0xF) + 2 + v6];
        if ( (uint8_t)*(v12 - 4) == 239
          && (uint8_t)*(v12 - 3) == 255
          && (uint8_t)*(v12 - 2) == 255
          && (uint8_t)*(v12 - 1) == 250 )
        {
          event_dispatch("discovery: port=%d\n", (uint8_t)v12[3] | ((uint8_t)v12[2] << 8));
          return v8;
        }
      }
    }
    return 1;
  }
  if ( v7[8] == 58 )
  {
    v11 = (uint8_t)v7[42];
    if ( v11 == 134 )
    {
      v13 = dword_139EEC + 696 * a3;
      v14 = (uint8_t)v7[49] | ((uint8_t)v7[48] << 8);
      *(volatile uint16_t *)(v13 + 690) = _byteswap_ushort(*((volatile uint16_t *)v7 + 24));
      v15 = (*(volatile uint32_t *)0x40501010u);
      if ( (int)(*(volatile uint32_t *)(v13 + 692) - v15 + dword_139EF4 * (v14 >> 1)) < 0 )
      {
        v16 = (*(volatile uint32_t *)0x40501010u);
        *(volatile uint32_t *)(v13 + 692) = v16;
        return 1;
      }
      return 0;
    }
    return v11 == 136 || v11 == 135 && ((uint8_t)v7[26] != 255 || v7[27] != 2);
  }
  return (uint8_t)(1 - v8);
}


// scan_parse_response @ 0x139ef8
volatile char * scan_parse_response(volatile char *a1, char a2, int a3) {
  char v3; // r3
  volatile char *result; // r0
  char a1a[2]; // [sp+6h] [bp-2h] BYREF

  if ( *a1 >= 0 )
    v3 = 24;
  else
    v3 = 26;
  *(volatile uint16_t *)a1a = 0;
  if ( (a2 & 0x78) == 8 )
  {
    v3 += 8;
  }
  else if ( (a2 & 0x7C) == 4 )
  {
    v3 += 4;
  }
  result = memcpy(a1a, &a1[(uint8_t)(v3 + 6)], 2u);
  if ( *(volatile uint16_t *)a1a == 36488 )
    return (volatile char *)event_dispatch("rx eapol:%x,%d\r\n", 36488, a3);
  return result;
}


// tx_check_allow @ 0x139f5c
int tx_check_allow(int a1) {
  unsigned int v1; // r7
  int v2; // r5
  int v3; // r3
  volatile uint8_t *v4; // r4
  int v5; // r6
  int v6; // r1
  volatile uint8_t *v8; // r6
  uint16_t v9; // r8
  uint16_t v10; // r3
  int v11; // r11
  int v12; // r9
  char v13; // r3
  uint16_t v14; // r3
  int v15; // r10
  int v16; // r3
  int v17; // r1
  int v18; // r1
  int v19; // r12
  int v20; // r2
  int v21; // r1
  int v22; // r0
  uint16_t v23; // r1
  volatile uint8_t **v24; // r11
  int v25; // r1
  int v26; // r1
  int v27; // r1
  int v28; // r1
  int v29; // r3
  volatile uint16_t *v30; // r1
  volatile uint8_t *v31; // r9
  int v32; // r0
  uint16_t v33; // r3
  char v34; // r0
  int v35; // r1
  int v36; // r0
  uint16_t v37; // r1
  int v38; // r7
  int v39; // r1
  int v40; // r2
  int v41; // r1
  int v42; // r1
  uint16_t v43; // r1
  int v44; // r1
  int v45; // r1
  volatile uint16_t *v46; // r10
  BOOL v47; // r0
  int v48; // [sp+0h] [bp-Ch]
  unsigned int v49; // [sp+0h] [bp-Ch]
  int v50; // [sp+0h] [bp-Ch]
  int v51; // [sp+4h] [bp-8h]
  int v52; // [sp+4h] [bp-8h]
  int v53; // [sp+4h] [bp-8h]

  v1 = *(volatile uint32_t *)(a1 + 84);
  v2 = a1;
  if ( (v1 & 0x2000) == 0 )
  {
    v3 = *((volatile uint8_t *)off_13A238 + 16);
    if ( v3 != 255 )
    {
      v4 = (void *)(uintptr_t)(off_13A23C);
LABEL_4:
      v4[10] = v3;
      rf_rssi_calibrate(v2, 128);
      v5 = 1;
      goto LABEL_5;
    }
LABEL_35:
    v5 = 0;
    goto LABEL_5;
  }
  v4 = (void *)(uintptr_t)(off_13A23C);
  v8 = *(volatile uint8_t **)(*(volatile uint32_t *)(a1 + 28) + 8);
  v9 = *(volatile uint16_t *)v8;
  *(volatile uint16_t *)off_13A23C = *(volatile uint16_t *)v8;
  *(volatile uint32_t *)(a1 + 96) = 0;
  v4[9] = -1;
  v4[10] = -1;
  v10 = *((volatile uint16_t *)v8 + 11);
  *((volatile uint16_t *)v4 + 1) = v10;
  v4[48] = 0;
  *((volatile uint16_t *)v4 + 2) = v10 >> 4;
  v4[6] = v10 & 0xF;
  if ( (v9 & 0x88) == 0x88 )
  {
    v11 = v9 & 0x300;
    if ( v11 == 768 )
      v33 = *((volatile uint16_t *)v8 + 15);
    else
      v33 = *((volatile uint16_t *)v8 + 12);
    v4[7] = v33 & 7;
  }
  else
  {
    v4[7] = 0;
    v11 = v9 & 0x300;
  }
  v12 = v9 & 0xFC;
  if ( v11 == 768 )
    v13 = 30;
  else
    v13 = 24;
  if ( v12 == 136 )
    v13 += 2;
  if ( v9 < 0 )
    v13 += 4;
  v4[8] = v13;
  if ( (v8[4] & 1) != 0 )
    v4[48] = 8;
  if ( (v9 & 0x100) != 0 )
  {
    *((volatile uint16_t *)v4 + 18) = *((volatile uint16_t *)v8 + 8);
    *((volatile uint16_t *)v4 + 19) = *((volatile uint16_t *)v8 + 9);
    *((volatile uint16_t *)v4 + 20) = *((volatile uint16_t *)v8 + 10);
    v14 = *(volatile uint16_t *)v8;
    if ( (*(volatile uint16_t *)v8 & 0x200) != 0 )
    {
LABEL_19:
      if ( (v14 & 0x100) != 0 )
      {
        *((volatile uint16_t *)v4 + 21) = *((volatile uint16_t *)v8 + 12);
        *((volatile uint16_t *)v4 + 22) = *((volatile uint16_t *)v8 + 13);
        *((volatile uint16_t *)v4 + 23) = *((volatile uint16_t *)v8 + 14);
      }
      else
      {
        *((volatile uint16_t *)v4 + 21) = *((volatile uint16_t *)v8 + 8);
        *((volatile uint16_t *)v4 + 22) = *((volatile uint16_t *)v8 + 9);
        *((volatile uint16_t *)v4 + 23) = *((volatile uint16_t *)v8 + 10);
      }
      if ( (v1 & 0x2000000) != 0 )
        goto LABEL_22;
LABEL_38:
      if ( v4[115]
        && (v1 & 0x200) == 0
        && *((volatile uint16_t *)v4 + 54) == *((volatile uint16_t *)v8 + 5)
        && *((volatile uint16_t *)v4 + 55) == *((volatile uint16_t *)v8 + 6)
        && *((volatile uint16_t *)v4 + 56) == *((volatile uint16_t *)v8 + 7) )
      {
        v4[114] = (*(volatile uint16_t *)v8 & 0x1400) == 4096;
      }
      if ( (v9 & 0xC) != 0 )
        goto LABEL_56;
      v29 = *((volatile uint16_t *)v8 + 11);
      if ( (*(volatile uint16_t *)v8 & 0x800) != 0 )
      {
        v30 = (volatile uint16_t *)off_13A3E4;
        v31 = v8 + 10;
        if ( *((volatile uint16_t *)v4 + 51) == v29 )
        {
          v49 = off_13A3E4;
          if ( !memcmp((unsigned int)(v8 + 10), off_13A3E4, 6u) )
            goto LABEL_34;
          v9 = *(volatile uint16_t *)v4;
          v29 = (v29 & ~0xFFFFu) | ((uint16_t)(*((volatile uint16_t *)v8 + 11)) & 0xFFFFu);
          v30 = (volatile uint16_t *)v49;
        }
      }
      else
      {
        v30 = (void *)(uintptr_t)(off_13A248);
        v31 = v8 + 10;
      }
      v32 = *(volatile uint32_t *)v31;
      v30[2] = *((volatile uint16_t *)v31 + 2);
      *((volatile uint16_t *)v4 + 51) = v29;
      *((volatile uint32_t *)v4 + 24) = v32;
      if ( (v9 & 0x4000) != 0 && ((v1 & 0x7C) != 4 || !tx_packet_ack((int)v8, v1)) )
LABEL_56:
        v5 = rand_gen_u16((void *)(v8));
      else
        v5 = tx_send_packet_1(v2, 255);
      goto LABEL_57;
    }
  }
  else
  {
    *((volatile uint16_t *)v4 + 18) = *((volatile uint16_t *)v8 + 2);
    *((volatile uint16_t *)v4 + 19) = *((volatile uint16_t *)v8 + 3);
    *((volatile uint16_t *)v4 + 20) = *((volatile uint16_t *)v8 + 4);
    v14 = *(volatile uint16_t *)v8;
    if ( (*(volatile uint16_t *)v8 & 0x200) != 0 )
      goto LABEL_19;
  }
  *((volatile uint16_t *)v4 + 21) = *((volatile uint16_t *)v8 + 5);
  *((volatile uint16_t *)v4 + 22) = *((volatile uint16_t *)v8 + 6);
  *((volatile uint16_t *)v4 + 23) = *((volatile uint16_t *)v8 + 7);
  if ( (v1 & 0x2000000) == 0 )
    goto LABEL_38;
LABEL_22:
  v15 = dword_13A250;
  v16 = (uint8_t)((v1 >> 15) - 16);
  v17 = dword_13A250 + 696 * v16;
  if ( !*(volatile uint8_t *)(v17 + 37) )
    goto LABEL_34;
  v19 = *(volatile uint8_t *)(v18 + 34);
  v20 = dword_13A244;
  v21 = *(volatile uint32_t *)(v18 + 184);
  v4[9] = v16;
  *((volatile uint32_t *)v4 + 6) = v1;
  v22 = *(volatile uint8_t *)(v20 + 1320 * v19 + 106);
  v4[10] = v19;
  v48 = v21;
  if ( v22 != 2 || (v4[36] & 1) != 0 )
  {
    v23 = v9;
  }
  else
  {
    v34 = fifo_write((volatile int *)dword_13A24C);
    v23 = *(volatile uint16_t *)v4;
    v16 = (uint8_t)((v1 >> 15) - 16);
    v20 = dword_13A244;
    v4[11] = v34;
  }
  if ( v11 == 768 )
    *(volatile uint32_t *)(v2 + 96) |= 4u;
  if ( (v23 & 0x4000) != 0 )
  {
    v51 = v16;
    a1 = tx_packet_ack((int)v8, *((volatile uint32_t *)v4 + 6));
    v16 = v51;
    v20 = dword_13A3E8;
    if ( !a1 )
      goto LABEL_34;
  }
  v24 = (volatile uint8_t **)off_13A254;
  if ( **(volatile uint8_t **)off_13A254 == 1 && !LOBYTE(((volatile uint32_t *)(uintptr_t)off_13A3EC)[103]) )
  {
    v39 = v9 & 0xC;
    if ( v39 == 8 )
    {
      if ( !*(volatile uint8_t *)(v20 + 1320 * (uint8_t)v4[10] + 106) )
      {
        v53 = v16;
        a1 = scan_parse_report((volatile char *)v8, v1, v16);
        v16 = v53;
        if ( !a1 )
          goto LABEL_34;
      }
      goto LABEL_83;
    }
LABEL_30:
    if ( *(volatile uint8_t *)(v15 + 696 * v16 + 669) > 1u
      || !v48
      || (unsigned int)*(volatile uint8_t *)(v48 + 96) - 1 > 1 )
    {
      goto LABEL_31;
    }
    goto LABEL_72;
  }
  v25 = v9 & 0xC;
  if ( v25 != 8 )
    goto LABEL_30;
LABEL_83:
  v52 = v16;
  scan_parse_response((volatile char *)v8, v1, *(volatile uint16_t *)(v2 + 48));
  v16 = v52;
  if ( *(volatile uint8_t *)(v15 + 696 * v52 + 669) > 1u || !v48 || (unsigned int)*(volatile uint8_t *)(v48 + 96) - 1 > 1 )
    goto LABEL_84;
  v45 = 8;
LABEL_72:
  if ( (v9 & 0x4000) != 0 && (v4[36] & 1) == 0 )
    *(volatile uint8_t *)(v15 + 696 * v16 + 669) = 2;
LABEL_31:
  if ( v26 == 4 )
  {
    if ( v12 == 132 )
      rf_get_chan_param(v16, (int)v8);
    goto LABEL_34;
  }
  if ( v27 != 8 )
  {
    if ( v28 )
      goto LABEL_34;
    if ( (v9 & 0x800) != 0 )
    {
      v35 = *((volatile uint16_t *)v4 + 1);
      if ( *(volatile uint16_t *)(v15 + 696 * v16 + 552) == v35 )
        goto LABEL_34;
    }
    else
    {
      v44 = *((volatile uint16_t *)v4 + 1);
    }
    v36 = (uint8_t)v4[48] << 30;
    *(volatile uint16_t *)(v15 + 696 * v16 + 552) = v37;
    if ( v36 < 0 )
    {
      v38 = *((volatile uint32_t *)v4 + 8);
      *(volatile uint64_t *)&a1 = *((volatile uint64_t *)v4 + 2);
      if ( *(volatile uint64_t *)(v38 + 64) >= *(volatile uint64_t *)&a1 )
      {
        event_dispatch(aPnCheckFiltere);
        goto LABEL_34;
      }
      *(volatile uint64_t *)(v38 + 64) = *(volatile uint64_t *)&a1;
    }
    if ( **v24 == 1 && *v8 == 128 && !v8[1] )
    {
LABEL_34:
      v3 = *((volatile uint8_t *)off_13A238 + 16);
      if ( v3 != 255 )
        goto LABEL_4;
      goto LABEL_35;
    }
    v5 = tx_send_packet_1(v2, (uint8_t)v4[9]);
    goto LABEL_57;
  }
LABEL_84:
  if ( (v9 & 0x40) != 0 )
    goto LABEL_34;
  if ( (v9 & 0x80) != 0 )
  {
    v40 = 1;
    if ( (v4[48] & 8) == 0 )
    {
      v50 = v16;
      v47 = phy_read_offset_b(v16, (uint8_t)v4[7]);
      v16 = v50;
      v40 = 1;
      if ( v47 )
      {
        v5 = ll_get_conn(v2, v50);
        goto LABEL_57;
      }
    }
    v46 = (volatile uint16_t *)(v15 + 2 * ((uint8_t)v4[7] + 277 + 348 * v16));
  }
  else
  {
    v40 = 0;
    v46 = (volatile uint16_t *)(v15 + 696 * v16 + 552);
  }
  v41 = *((volatile uint16_t *)v4 + 1);
  if ( (v9 & 0x800) != 0 && (uint16_t)*v46 == v42 )
    goto LABEL_34;
  *v46 = v43;
  v5 = ll_rx_irq(v2, v16, v40);
LABEL_57:
  v3 = *((volatile uint8_t *)off_13A238 + 16);
  if ( v3 != 255 && !v5 )
    goto LABEL_4;
LABEL_5:
  load_and_process_r0((volatile int *)dword_13A240, v6);
  return v5;
}


// tx_desc_release @ 0x13a3f4
int tx_desc_release(int a1, int a2, int16_t a3) {
  int v3; // r4
  char v5; // r5
  volatile int *v7; // r0
  volatile int *v8; // r6
  volatile uint32_t *v9; // r3
  int v10; // r3
  int v11; // r2

  v3 = a1 + 4 * a2;
  if ( *(volatile uint32_t *)(v3 + 408) )
    return 0;
  v5 = a2;
  v7 = (void *)(mem_word_load(dword_13A454));
  v8 = v7;
  if ( !v7 )
    return 0;
  memset(v7, 0, 0x124u);
  v9 = (void *)(uintptr_t)(off_13A458);
  *((volatile uint8_t *)v8 + 10) = a3 & 0x3F;
  *((volatile uint8_t *)v8 + 12) = v5;
  v10 = v9[4];
  v11 = dword_13A45C;
  *((volatile uint16_t *)v8 + 4) = a3;
  v8[69] = v11;
  v8[70] = (int)v8;
  v8[1] = v10;
  *(volatile uint32_t *)(v3 + 408) = (int)(uintptr_t)(v8);
  unknown_worker((void *)(uintptr_t)((int)(v8 + 68)), v10 + 50000);
  return 1;
}



// tx_slot_get @ 0x13a460
int tx_slot_get(int a1, int a2) {
  int v2; // r4
  volatile uint32_t *v3; // r5
  int result; // r0

  v2 = a1 + 4 * a2;
  v3 = *(volatile uint32_t **)(v2 + 408);
  if ( **(volatile int16_t **)off_13A4A0 < 0 && !v3 )
    mmio_clear_register((int)aReordNull, (int)aRxuCntrlReordD, 3320);
  fault_handler((int)(uintptr_t)(v3 + 68));
  result = cmd_handler_a(dword_13A4A4, v3);
  *(volatile uint32_t *)(v2 + 408) = 0;
  return result;
}


// mac_store_config @ 0x13a4b0
volatile uint16_t * mac_store_config(volatile uint16_t *result) {
  volatile uint16_t *v1; // r3

  v1 = (void *)(uintptr_t)(off_13A4D4);
  if ( !*((volatile uint8_t *)off_13A4D4 + 115) )
  {
    *((volatile uint16_t *)off_13A4D4 + 54) = *result;
    v1[55] = result[1];
    v1[56] = result[2];
    v1[57] = 256;
  }
  return result;
}



// clear_flag @ 0x13a4d8
int clear_flag() {
  int result; // r0

  result = *((volatile uint8_t *)off_13A4E8 + 114);
  *((volatile uint16_t *)off_13A4E8 + 57) = 0;
  return result;
}



// ke_task_schedule @ 0x13a4ec
volatile uint32_t **ke_task_schedule() {
  unknown_func_12d14c(0x100000);
  return (void *)(uintptr_t)(((int (*)())load_and_process_r0)((void *)((volatile uint32_t **)dword_13A500)));
}



// rf_chan_enabled @ 0x13a504
BOOL rf_chan_enabled() {
  return *(volatile uint16_t *)(dword_13A524 + 80 * *((volatile uint8_t *)off_13A520 + 68) + 76) == 0;
}



