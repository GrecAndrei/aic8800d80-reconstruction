// dma_tx_setup @ 0x1223b8
int dma_tx_setup(int a1) {
  volatile int *v1; // r3
  int v2; // r6
  int v3; // r5
  volatile int *v4; // r0
  volatile int *v5; // r1
  int v6; // r2
  int v7; // t1
  int v8; // r4
  volatile int *v9; // r4
  volatile uint8_t *v10; // r1
  volatile uint8_t *v11; // r2
  uint32_t v13[7]; // [sp+0h] [bp-1Ch] BYREF

  v1 = (volatile int *)dword_122430;
  v2 = dword_122434;
  v3 = dword_122438;
  v4 = (volatile int *)(a1 + 12);
  v5 = (volatile int *)(*(volatile uint32_t *)off_12242C + 4);
  do
  {
    v7 = *v5++;
    v6 = v7;
    v8 = v7 & 0xFFF;
    if ( v7 )
    {
      if ( !v8 )
      {
        *v1 = *v4 & 0xFFF | v6 & v2;
        goto LABEL_5;
      }
    }
    else
    {
      v6 = *v4;
    }
    *v1 = v6;
LABEL_5:
    ++v1;
    ++v4;
  }
  while ( v1 != (volatile int *)v3 );
  v9 = (volatile int *)off_12243C;
  write_mmio_byte(BYTE1(((volatile uint32_t *)(uintptr_t)off_12243C)[102]));
  v10 = (void *)(uintptr_t)(off_122444);
  v11 = (void *)(uintptr_t)(off_122448);
  *((volatile uint8_t *)off_122440 + 7) = *((volatile uint8_t *)v9 + 409);
  memset((void *)(&v13[1]), 0, 16);
  *v10 = 0;
  v13[0] = 0;
  *v11 = 0;
  v13[5] = 0;
  delay_loop((int)v13);
  return ke_event_schedule_1(aEdcaM0);
}


// dma_rx_setup @ 0x122450
int dma_rx_setup(int a1) {
  int v1; // r4
  volatile int *v2; // r2
  int v3; // r5
  int v4; // r6
  volatile int *v5; // r0
  volatile int *v6; // r1
  int v7; // t1
  int v8; // zf
  int v9; // r3
  volatile int *v10; // r4
  volatile uint32_t *v11; // r5
  volatile uint8_t *v12; // r0
  volatile uint8_t *v13; // r1
  volatile unsigned int v14; // r1
  volatile uint32_t *v15; // r2

  v2 = (volatile int *)dword_1224C8;
  v3 = dword_1224CC;
  v4 = dword_1224D0;
  v5 = (volatile int *)(a1 + 444);
  v6 = (volatile int *)(*(volatile uint32_t *)off_1224C4 + 4);
  do
  {
    v7 = *v6++;
    v9 = v7 & v3;
    v8 = (v7 & v3) == 0;
    if ( (v7 & v3) != 0 )
      v1 = *v5;
    else
      v9 = *v5;
    if ( !v8 )
    {
      v1 &= 0xFFFu;
      v9 |= v1;
    }
    *v2++ = v9;
    ++v5;
  }
  while ( v2 != (volatile int *)v4 );
  v10 = (volatile int *)off_1224D4;
  v11 = (void *)(uintptr_t)(off_1224D8);
  write_mmio_byte(BYTE2(((volatile uint32_t *)(uintptr_t)off_1224D4)[102]));
  v12 = (void *)(uintptr_t)(off_1224E0);
  v13 = (void *)(uintptr_t)(off_1224E4);
  *((volatile uint8_t *)off_1224DC + 9) = *((volatile uint8_t *)v10 + 410);
  *v12 = 1;
  *v13 = 1;
  v14 = REG_4032_0120;
  v15 = (void *)(uintptr_t)(off_1224EC);
  *v11 = v14 + 15000;
  *v15 = 15000;
  v15[1] = 15000;
  v15[2] = 15000;
  v15[3] = 15000;
  v15[4] = 15000;
  v15[5] = 15000;
  return ke_event_schedule_1(aEdcaM1);
}


// util_wait_loop @ 0x1224f4
int util_wait_loop() {
  volatile uint32_t *v0; // r1
  int result; // r0
  int i; // r3

  v0 = (void *)(uintptr_t)(off_122520);
  result = dword_122524;
  for ( i = 0; i != 6; ++i )
  {
    if ( ((*v0 >> i) & 1) != 0 )
      *(volatile uint32_t *)(result + 4 * i) += 15000;
  }
  return result;
}



// event_dispatch @ 0x122528
volatile uint32_t * event_dispatch(volatile uint32_t *result, int a2) {
  unsigned int v2; // r4
  int v3; // r7
  volatile uint32_t *v4; // r5
  int v5; // r6
  int v6; // r8
  float v7; // s17
  float v8; // s16
  int v9; // r3
  volatile uint8_t *v10; // r7
  volatile uint32_t *v11; // r10
  volatile unsigned int *v12; // r9
  volatile unsigned int *v13; // r8
  volatile uint32_t *v14; // r0
  unsigned int v15; // r12
  volatile char *v16; // r11
  int v17; // lr
  volatile uint32_t *v18; // r3
  unsigned int v19; // r2
  unsigned int v20; // r3
  unsigned int v21; // r0
  unsigned int v22; // r2
  char v23; // r2
  int v24; // r1
  int v25; // r2
  int v26; // r1
  volatile uint32_t *v27; // r3
  volatile unsigned int *v28; // r2
  unsigned int v29; // r3
  int v30; // r2
  volatile uint32_t *v31; // r12
  volatile uint32_t *v32; // r1
  int v33; // r2
  volatile uint8_t *v34; // r2
  int v35; // r3
  volatile uint8_t *v36; // r0
  int v37; // r2
  int v39; // [sp+14h] [bp-10h]
  unsigned int v40; // [sp+18h] [bp-Ch]
  volatile uint8_t *v41; // [sp+18h] [bp-Ch]

  v2 = off_1227BC;
  v3 = *(volatile char *)off_1227BC;
  if ( !*(volatile uint8_t *)off_1227BC )
    return result;
  v4 = result;
  v5 = *(volatile uint8_t *)(off_1227BC + 2);
  v6 = *(volatile char *)(off_1227BC + 1);
  v7 = *(volatile float *)(off_1227BC + 4);
  result = (volatile uint32_t *)hci_cmd_send_short(4u);
  if ( result )
    return result;
  v8 = (float)((float)(v7 * flt_1227C0) + (float)a2) * flt_1227C4;
  v9 = (char)(int)v8;
  v39 = v9;
  if ( v9 < v3 - v6 )
  {
    v10 = (void *)(uintptr_t)(off_1227CC);
    v5 = 1;
    if ( LOBYTE(((volatile uint32_t *)(uintptr_t)off_1227C8)[102]) )
      goto LABEL_8;
LABEL_27:
    v30 = *(volatile uint8_t *)off_1227F4;
    v31 = (void *)(uintptr_t)(off_122808);
    result = (void *)(uintptr_t)(off_1227F8);
    v32 = (void *)(uintptr_t)(off_1227FC);
    *(volatile uint8_t *)off_12280C = 0;
    *(volatile uint32_t *)v10 = 0;
    *v31 = 0;
    *result = 0;
    *v32 = 0;
    if ( !v30 )
      goto LABEL_22;
    goto LABEL_28;
  }
  if ( v3 < v9 )
    v5 = 0;
  v10 = (void *)(uintptr_t)(off_1227CC);
  if ( !LOBYTE(((volatile uint32_t *)(uintptr_t)off_1227C8)[102]) )
    goto LABEL_27;
LABEL_8:
  if ( !v10[8] )
    goto LABEL_27;
  v11 = (void *)(uintptr_t)(off_122808);
  v12 = (volatile unsigned int *)off_1227F8;
  v13 = (volatile unsigned int *)off_1227FC;
  v14 = (void *)(uintptr_t)(off_1227D4);
  v15 = *(volatile uint32_t *)v10;
  v16 = (volatile char *)off_12280C;
  v17 = *(volatile uint32_t *)off_1227D0 + *(volatile uint32_t *)off_122808;
  v18 = (volatile uint32_t *)((volatile char *)off_1227D0 + 268);
  *(volatile uint32_t *)off_122808 = v17;
  v19 = *v13;
  v20 = *v18 + *v12;
  *v12 = v20;
  v21 = *v14 + v19;
  if ( v21 <= v15 )
    v22 = 0;
  else
    v22 = v21 - v15;
  v40 = v22;
  v23 = *v16;
  v24 = *(volatile uint8_t *)off_1227D8;
  *v13 = v21;
  v25 = (uint8_t)(v23 + 1);
  *v16 = v25;
  if ( v24 == v25 )
  {
    if ( *(volatile uint8_t *)off_1227E8 == 1 && v20 <= 0x13 && v40 <= 9 )
    {
      v41 = (volatile uint8_t *)off_1227DC;
      v33 = 2;
      *(volatile uint8_t *)off_1227DC = 2;
    }
    else if ( *(volatile uint8_t *)(off_1227D8 + 3) <= v40 || v20 <= v40 * *(volatile uint8_t *)(off_1227D8 + 2) )
    {
      v41 = (volatile uint8_t *)off_1227DC;
      v33 = 0;
      *(volatile uint8_t *)off_1227DC = 0;
    }
    else
    {
      v41 = (volatile uint8_t *)off_1227DC;
      v33 = 1;
      *(volatile uint8_t *)off_1227DC = 1;
    }
    state_check_feature(64, "$%d %d,%d,%d,%d %d\n", v33, v20, v21, v15, v17, v39);
    v26 = *v41;
    *v16 = 0;
    *v11 = 0;
    *v12 = 0;
    *v13 = 0;
    *(volatile uint32_t *)v10 = 0;
    if ( v26 == 1 )
    {
      v36 = (void *)(uintptr_t)(off_1227E4);
      v37 = *(volatile uint8_t *)off_1227E4;
      *(volatile uint8_t *)off_122800 = 0;
      if ( v37 != 255 )
        *v36 = v37 + 1;
    }
    else if ( !v26 )
    {
      v34 = (void *)(uintptr_t)(off_122800);
      v35 = *(volatile uint8_t *)off_122800;
      *(volatile uint8_t *)off_1227E4 = 0;
      if ( v35 != 255 )
        *v34 = v35 + 1;
    }
  }
  else
  {
    v26 = *(volatile uint8_t *)off_1227DC;
  }
  v27 = (void *)(uintptr_t)(off_1227E0);
  *(volatile uint32_t *)off_1227E0 &= ~0x4000u;
  *v27 = (uint16_t)*v27;
  *v27 = *v27 & 0xFFFFFC00 | 0x44;
  *v27 |= 0x8000u;
  while ( (*v27 & 0x8000) != 0 )
    ;
  v28 = (volatile unsigned int *)off_1227E0;
  *v27 = *v27 & 0xFFFFFC00 | 0x54;
  result = (volatile uint32_t *)(*v27 | 0x8000);
  *v27 = (int)(uintptr_t)(result);
  while ( (*v28 & 0x8000) != 0 )
    ;
  *v28 = *v28 & 0xFFFFFC00 | 1;
  *v28 |= 0x8000u;
  if ( v26 == 2 )
    goto LABEL_22;
  v29 = *(volatile uint8_t *)(off_1227D8 + 1);
  if ( *(volatile uint8_t *)off_1227E4 > v29 )
  {
    if ( *(volatile uint8_t *)off_1227E8 != 1 )
      result = (volatile uint32_t *)dma_rx_setup((int)v4);
    goto LABEL_22;
  }
  if ( *(volatile uint8_t *)off_122800 > v29 >> 1 && *(volatile uint8_t *)off_1227E8 )
LABEL_28:
    result = (volatile uint32_t *)dma_tx_setup((int)v4);
LABEL_22:
  if ( !v5 || *((volatile uint8_t *)off_1227F0 + 18) )
    *(volatile uint32_t *)off_1227EC &= ~0x200u;
  else
    *(volatile uint32_t *)off_1227EC |= 0x200u;
  *(volatile uint8_t *)(v2 + 2) = v5;
  *(volatile float *)(v2 + 4) = v8;
  return result;
}


// mmio_write_phy @ 0x122810
int mmio_write_phy(char a1, char a2) {
  volatile uint8_t *v4; // r0

  v4 = (volatile uint8_t *)bt_buf_alloc(89, 13, 0, 2);
  *v4 = a1;
  v4[1] = a2;
  return (int)(uintptr_t)(hci_evt_send((int)(uintptr_t)(v4)));
}



// rx_process_packet_1 @ 0x122830
int rx_process_packet_1(int a1, int a2, int a3, volatile int *a4) {
  int v4; // r7
  int v5; // r11
  int v6; // r9
  int v7; // r4
  int v9; // r0
  int v10; // r2
  int v11; // r3
  volatile uint32_t *v12; // r3
  int v13; // r1
  int v14; // r0
  volatile int *v15; // r7
  volatile uint8_t *v16; // r1
  int v17; // r8
  unsigned int v18; // r4
  int v19; // r5
  volatile uint8_t *v20; // r10
  int result; // r0
  int v23; // [sp+10h] [bp-Ch]
  int v24; // [sp+10h] [bp-Ch]
  int v25; // [sp+14h] [bp-8h]

  v4 = a1;
  v5 = *(volatile uint16_t *)(a1 + 28);
  v6 = *(volatile uint32_t *)(*(volatile uint32_t *)(a1 + 8) + 8);
  v7 = a2;
  v25 = *(volatile uint32_t *)(a2 + 124);
  v9 = (int)(uintptr_t)(sub_12dd88((void *)(uintptr_t)(v6 + 36), (uint16_t)(v5 - 36)));
  if ( !v9 )
    goto LABEL_7;
  v10 = *(volatile uint8_t *)(v9 + 2);
  v11 = *((volatile uint8_t *)off_1229B8 + 36);
  if ( !*((volatile uint8_t *)off_1229B8 + 36) )
  {
    if ( (unsigned int)(v10 - 1) <= 0xD )
    {
      if ( v10 == 14 )
        v11 = 2484;
      else
        v11 = 5 * v10 + 2407;
    }
LABEL_6:
    if ( *(volatile uint16_t *)(v7 + 414) != v11 )
      goto LABEL_8;
    goto LABEL_7;
  }
  if ( v11 == 1 && (uint8_t)(v10 - 1) <= 0xB0u )
  {
    v11 = 5 * v10 + 5000;
    goto LABEL_6;
  }
  if ( !*(volatile uint16_t *)(v7 + 414) )
LABEL_7:
    *(volatile uint8_t *)(v7 + 128) = 0;
LABEL_8:
  if ( *(volatile uint8_t *)(v7 + 147) )
  {
    mmio_write_phy(*(volatile uint8_t *)(v7 + 107), 1);
    *(volatile uint16_t *)(v7 + 146) = 0;
    *(volatile uint8_t *)(v7 + 148) = 0;
  }
  v12 = (void *)(uintptr_t)(off_1229BC);
  *(volatile uint8_t *)(v7 + 141) = 1;
  if ( (int)(dword_1229C0 - v12[4] + *(volatile uint32_t *)(v7 + 120)) < 0 && !phy_channel_validate(*(volatile uint8_t *)(v7 + 116), 0, 0) )
    *(volatile uint32_t *)(v7 + 120) = *((volatile uint32_t *)off_1229BC + 4);
  v23 = *(volatile char *)(v4 + 45);
  sys_mode_get_low();
  v13 = v23;
  if ( *((volatile uint8_t *)off_1229C4 + 17) == 1 )
  {
    event_dispatch((volatile uint32_t *)v7, v23);
    v13 = v23;
  }
  rf_iq_calibrate((volatile uint8_t *)v7, v13);
  v14 = crc32_update((void *)(uintptr_t)(v6 + 32), 4, 0);
  *a4 = 0;
  if ( (uint16_t)(v5 - 36) > 1u )
  {
    v24 = v4;
    v15 = a4;
    v16 = (volatile uint8_t *)(v6 + 36);
    v17 = v7;
    v18 = (uint16_t)(v5 - 36);
    do
    {
      v19 = (uint8_t)v16[1];
      v20 = v16 + 2;
      if ( v19 + 1 >= (int)v18 )
        break;
      if ( *v16 == 5 )
        *v15 = (int)v16;
      else
        v14 = crc32_update(v20, (uint8_t)v16[1], v14);
      v18 = (uint16_t)(v18 + -2 - v19);
      v16 = &v20[v19];
    }
    while ( v18 > 1 );
    v7 = v17;
    a4 = v15;
    v4 = v24;
  }
  *(volatile uint32_t *)(v7 + 124) = v14;
  tx_prepare_descriptor(v6, v5, v4, v7, a3, *a4);
  result = hci_cmd_send_short(4);
  if ( result != 1 )
    return *(volatile uint32_t *)(v7 + 124) != v25;
  return result;
}



// bt_state_flags_check @ 0x1229c8
volatile char * bt_state_flags_check(volatile char *result) {
  int v1; // r4
  int v2; // r6
  int v3; // r5
  unsigned int v4; // r3
  int v5; // r2
  volatile uint8_t *v6; // r1
  unsigned int v7; // r2
  volatile uint8_t *v8; // r3
  unsigned int v9; // r3

  if ( result[108] )
  {
    v1 = (int)result;
    if ( result[146] && result[148] )
    {
      v9 = (uint8_t)(result[146] - 1);
      result[146] = v9;
      if ( v9 <= 1 )
        return (volatile char *)alloc_buffer((int)result);
      if ( v9 == 2 )
        mmio_write_phy(result[107], 0);
    }
    v2 = *(volatile uint32_t *)(v1 + 36);
    v3 = *(volatile uint32_t *)(dword_122AA0 + 696 * *(volatile uint8_t *)(v1 + 116) + 8) + v2;
    if ( v1 != *((volatile uint32_t *)off_122AA4 + 8)
      || (v8 = (void *)(uintptr_t)(off_122AAC), *(volatile uint32_t *)(v1 + 36) = v3, !v8[189]) && **(volatile uint8_t **)off_122AB0 != 2 )
    {
      ke_event_lock((void *)(uintptr_t)(v1 + 24), v3);
    }
    wlc_bmac_write_shm(v1);
    bt_conn_event_process((void *)(uintptr_t)(v1), *(volatile uint32_t *)(v1 + 136) + v2);
    result = (volatile char *)hci_command_handler(v1, v2, v3);
    if ( !result )
    {
      v4 = (uint8_t)(*(volatile uint8_t *)(v1 + 128) + 1);
      v5 = *(volatile uint32_t *)(v1 + 4) | 1;
      v6 = *(volatile uint8_t **)off_122AA8;
      *(volatile uint8_t *)(v1 + 128) = v4;
      *(volatile uint32_t *)(v1 + 4) = v5;
      v7 = *v6;
      if ( v4 > v7 )
      {
        return (volatile char *)phy_channel_validate(*(volatile uint8_t *)(v1 + 116), dword_122AB4, v1);
      }
      else if ( v4 == v7 )
      {
        return (volatile char *)bt_power_state(v1);
      }
    }
  }
  return result;
}



// get_chip_status @ 0x122ab8
volatile char *get_chip_status() {
  int v0; // r4

  v0 = *(volatile uint32_t *)off_122B08 & 0x1800000;
  if ( **(volatile int16_t **)off_122B04 < 0 && v0 == 25165824 )
    mmio_irq_clear(dword_122B18, dword_122B14, 1308);
  set_system_flag_2(v0);
  if ( *((volatile uint8_t *)off_122B0C + 18) )
    return (volatile char *)((int (*)())irq_lock_save)();
  else
    return bt_state_flags_check(*((volatile char **)off_122B10 + 8));
}



// find_pending_command @ 0x122b1c
int find_pending_command() {
  volatile int *v0; // r2
  int result; // r0
  volatile uint32_t *v2; // r3

  v0 = *((volatile int **)off_122B60 + 2);
  if ( v0 )
  {
    result = 0;
    while ( !*((volatile uint8_t *)v0 + 106) )
    {
      if ( *((volatile uint8_t *)v0 + 108) && (v2 = (volatile uint32_t *)v0[60]) != 0 )
      {
        do
        {
          v2 = (volatile uint32_t *)*v2;
          if ( *((volatile uint8_t *)v0 + 116) != 255 )
            result = (uint8_t)(result + 1);
        }
        while ( v2 );
        v0 = (volatile int *)*v0;
        if ( !v0 )
          return result;
      }
      else
      {
        v0 = (volatile int *)*v0;
        if ( !v0 )
          return result;
      }
    }
  }
  return 0;
}



// send_cmd_0x0b @ 0x122b64
int send_cmd_0x0b(int a1, int a2, int a3, int a4) {
  volatile uint8_t *v5; // r4

  v5 = (volatile uint8_t *)bt_buf_alloc(11, a4, a3, 3);
  *v5 = buffer_alloc(a2, v5 + 1, v5 + 2);
  hci_evt_send((int)(uintptr_t)(v5));
  return 0;
}



