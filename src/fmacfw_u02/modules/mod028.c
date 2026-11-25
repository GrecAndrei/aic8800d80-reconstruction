// mmio_update @ 0x122184
int mmio_update(int a1) {
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

  v1 = (volatile int *)dword_1221FC;
  v2 = dword_122200;
  v3 = dword_122204;
  v4 = (volatile int *)(a1 + 12);
  v5 = (volatile int *)(*(volatile uint32_t *)off_1221F8 + 4);
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
  v9 = (volatile int *)off_122208;
  write_phy_config(BYTE1(((volatile uint32_t *)(uintptr_t)off_122208)[102]));
  v10 = (void *)(uintptr_t)(off_122210);
  v11 = (void *)(uintptr_t)(off_122214);
  *((volatile uint8_t *)off_12220C + 7) = *((volatile uint8_t *)v9 + 409);
  memset((void *)(&v13[1]), 0, 16);
  *v10 = 0;
  v13[0] = 0;
  *v11 = 0;
  v13[5] = 0;
  timer_queue_init((int)v13);
  return event_dispatch(aEdcaM0);
}


// mmio_masked_write @ 0x12221c
int mmio_masked_write(int a1) {
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

  v2 = (volatile int *)dword_122294;
  v3 = dword_122298;
  v4 = dword_12229C;
  v5 = (volatile int *)(a1 + 444);
  v6 = (volatile int *)(*(volatile uint32_t *)off_122290 + 4);
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
  v10 = (volatile int *)off_1222A0;
  v11 = (void *)(uintptr_t)(off_1222A4);
  write_phy_config(BYTE2(((volatile uint32_t *)(uintptr_t)off_1222A0)[102]));
  v12 = (void *)(uintptr_t)(off_1222AC);
  v13 = (void *)(uintptr_t)(off_1222B0);
  *((volatile uint8_t *)off_1222A8 + 9) = *((volatile uint8_t *)v10 + 410);
  *v12 = 1;
  *v13 = 1;
  v14 = REG_4032_0120;
  v15 = (void *)(uintptr_t)(off_1222B8);
  *v11 = v14 + 15000;
  *v15 = 15000;
  v15[1] = 15000;
  v15[2] = 15000;
  v15[3] = 15000;
  v15[4] = 15000;
  v15[5] = 15000;
  return event_dispatch(aEdcaM1);
}


// poll_register_bit @ 0x1222c0
int poll_register_bit() {
  volatile uint32_t *v0; // r1
  int result; // r0
  int i; // r3

  v0 = (void *)(uintptr_t)(off_1222EC);
  result = dword_1222F0;
  for ( i = 0; i != 6; ++i )
  {
    if ( ((*v0 >> i) & 1) != 0 )
      *(volatile uint32_t *)(result + 4 * i) += 15000;
  }
  return result;
}



// rf_tx_power_calc @ 0x1222f4
volatile uint32_t * rf_tx_power_calc(volatile uint32_t *result, int a2) {
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

  v2 = off_122588;
  v3 = *(volatile char *)off_122588;
  if ( !*(volatile uint8_t *)off_122588 )
    return result;
  v4 = result;
  v5 = *(volatile uint8_t *)(off_122588 + 2);
  v6 = *(volatile char *)(off_122588 + 1);
  v7 = *(volatile float *)(off_122588 + 4);
  result = (volatile uint32_t *)rx_rate_field_parse(4u);
  if ( result )
    return result;
  v8 = (float)((float)(v7 * flt_12258C) + (float)a2) * flt_122590;
  v9 = (char)(int)v8;
  v39 = v9;
  if ( v9 < v3 - v6 )
  {
    v10 = (void *)(uintptr_t)(off_122598);
    v5 = 1;
    if ( LOBYTE(((volatile uint32_t *)(uintptr_t)off_122594)[102]) )
      goto LABEL_8;
LABEL_27:
    v30 = *(volatile uint8_t *)off_1225C0;
    v31 = (void *)(uintptr_t)(off_1225D4);
    result = (void *)(uintptr_t)(off_1225C4);
    v32 = (void *)(uintptr_t)(off_1225C8);
    *(volatile uint8_t *)off_1225D8 = 0;
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
  v10 = (void *)(uintptr_t)(off_122598);
  if ( !LOBYTE(((volatile uint32_t *)(uintptr_t)off_122594)[102]) )
    goto LABEL_27;
LABEL_8:
  if ( !v10[8] )
    goto LABEL_27;
  v11 = (void *)(uintptr_t)(off_1225D4);
  v12 = (volatile unsigned int *)off_1225C4;
  v13 = (volatile unsigned int *)off_1225C8;
  v14 = (void *)(uintptr_t)(off_1225A0);
  v15 = *(volatile uint32_t *)v10;
  v16 = (volatile char *)off_1225D8;
  v17 = *(volatile uint32_t *)off_12259C + *(volatile uint32_t *)off_1225D4;
  v18 = (volatile uint32_t *)((volatile char *)off_12259C + 268);
  *(volatile uint32_t *)off_1225D4 = v17;
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
  v24 = *(volatile uint8_t *)off_1225A4;
  *v13 = v21;
  v25 = (uint8_t)(v23 + 1);
  *v16 = v25;
  if ( v24 == v25 )
  {
    if ( *(volatile uint8_t *)off_1225B4 == 1 && v20 <= 0x13 && v40 <= 9 )
    {
      v41 = (volatile uint8_t *)off_1225A8;
      v33 = 2;
      *(volatile uint8_t *)off_1225A8 = 2;
    }
    else if ( *(volatile uint8_t *)(off_1225A4 + 3) <= v40 || v20 <= v40 * *(volatile uint8_t *)(off_1225A4 + 2) )
    {
      v41 = (volatile uint8_t *)off_1225A8;
      v33 = 0;
      *(volatile uint8_t *)off_1225A8 = 0;
    }
    else
    {
      v41 = (volatile uint8_t *)off_1225A8;
      v33 = 1;
      *(volatile uint8_t *)off_1225A8 = 1;
    }
    check_status_bits(64, "$%d %d,%d,%d,%d %d\n", v33, v20, v21, v15, v17, v39);
    v26 = *v41;
    *v16 = 0;
    *v11 = 0;
    *v12 = 0;
    *v13 = 0;
    *(volatile uint32_t *)v10 = 0;
    if ( v26 == 1 )
    {
      v36 = (void *)(uintptr_t)(off_1225B0);
      v37 = *(volatile uint8_t *)off_1225B0;
      *(volatile uint8_t *)off_1225CC = 0;
      if ( v37 != 255 )
        *v36 = v37 + 1;
    }
    else if ( !v26 )
    {
      v34 = (void *)(uintptr_t)(off_1225CC);
      v35 = *(volatile uint8_t *)off_1225CC;
      *(volatile uint8_t *)off_1225B0 = 0;
      if ( v35 != 255 )
        *v34 = v35 + 1;
    }
  }
  else
  {
    v26 = *(volatile uint8_t *)off_1225A8;
  }
  v27 = (void *)(uintptr_t)(off_1225AC);
  *(volatile uint32_t *)off_1225AC &= ~0x4000u;
  *v27 = (uint16_t)*v27;
  *v27 = *v27 & 0xFFFFFC00 | 0x44;
  *v27 |= 0x8000u;
  while ( (*v27 & 0x8000) != 0 )
    ;
  v28 = (volatile unsigned int *)off_1225AC;
  *v27 = *v27 & 0xFFFFFC00 | 0x54;
  result = (volatile uint32_t *)(*v27 | 0x8000);
  *v27 = (int)(uintptr_t)(result);
  while ( (*v28 & 0x8000) != 0 )
    ;
  *v28 = *v28 & 0xFFFFFC00 | 1;
  *v28 |= 0x8000u;
  if ( v26 == 2 )
    goto LABEL_22;
  v29 = *(volatile uint8_t *)(off_1225A4 + 1);
  if ( *(volatile uint8_t *)off_1225B0 > v29 )
  {
    if ( *(volatile uint8_t *)off_1225B4 != 1 )
      result = (volatile uint32_t *)mmio_masked_write((int)v4);
    goto LABEL_22;
  }
  if ( *(volatile uint8_t *)off_1225CC > v29 >> 1 && *(volatile uint8_t *)off_1225B4 )
LABEL_28:
    result = (volatile uint32_t *)mmio_update((int)v4);
LABEL_22:
  if ( !v5 || *((volatile uint8_t *)off_1225BC + 18) )
    *(volatile uint32_t *)off_1225B8 &= ~0x200u;
  else
    *(volatile uint32_t *)off_1225B8 |= 0x200u;
  *(volatile uint8_t *)(v2 + 2) = v5;
  *(volatile float *)(v2 + 4) = v8;
  return result;
}


// hci_send_cmd_0x59 @ 0x1225dc
int hci_send_cmd_0x59(char a1, char a2) {
  volatile uint8_t *v4; // r0

  v4 = (volatile uint8_t *)ke_msg_alloc(89, 13, 0, 2);
  *v4 = a1;
  v4[1] = a2;
  return (int)(uintptr_t)(ke_msg_send_2((int)(uintptr_t)(v4)));
}



// rx_process_packet @ 0x1225fc
int rx_process_packet(int a1, int a2, int a3, volatile int *a4) {
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
  v9 = (int)(uintptr_t)(check_one_12db60((void *)(uintptr_t)(v6 + 36), (uint16_t)(v5 - 36)));
  if ( !v9 )
    goto LABEL_7;
  v10 = *(volatile uint8_t *)(v9 + 2);
  v11 = *((volatile uint8_t *)off_122784 + 36);
  if ( !*((volatile uint8_t *)off_122784 + 36) )
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
    hci_send_cmd_0x59(*(volatile uint8_t *)(v7 + 107), 1);
    *(volatile uint16_t *)(v7 + 146) = 0;
    *(volatile uint8_t *)(v7 + 148) = 0;
  }
  v12 = (void *)(uintptr_t)(off_122788);
  *(volatile uint8_t *)(v7 + 141) = 1;
  if ( (int)(dword_12278C - v12[4] + *(volatile uint32_t *)(v7 + 120)) < 0 && !phy_channel_is_5g(*(volatile uint8_t *)(v7 + 116), 0, 0) )
    *(volatile uint32_t *)(v7 + 120) = *((volatile uint32_t *)off_122788 + 4);
  v23 = *(volatile char *)(v4 + 45);
  rf_get_field0();
  v13 = v23;
  if ( *((volatile uint8_t *)off_122790 + 17) == 1 )
  {
    rf_tx_power_calc((volatile uint32_t *)v7, v23);
    v13 = v23;
  }
  rssi_compensation((volatile uint8_t *)v7, v13);
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
  handle_rx_data(v6, v5, v4, v7, a3, *a4);
  result = rx_rate_field_parse(4);
  if ( result != 1 )
    return *(volatile uint32_t *)(v7 + 124) != v25;
  return result;
}



// read_config_byte @ 0x122794
volatile char * read_config_byte(volatile char *result) {
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
        return (volatile char *)alloc_kernel_message((int)result);
      if ( v9 == 2 )
        hci_send_cmd_0x59(result[107], 0);
    }
    v2 = *(volatile uint32_t *)(v1 + 36);
    v3 = *(volatile uint32_t *)(dword_12286C + 696 * *(volatile uint8_t *)(v1 + 116) + 8) + v2;
    if ( v1 != *((volatile uint32_t *)off_122870 + 8)
      || (v8 = (void *)(uintptr_t)(off_122878), *(volatile uint32_t *)(v1 + 36) = v3, !v8[189]) && **(volatile uint8_t **)off_12287C != 2 )
    {
      unknown_worker((void *)(uintptr_t)(v1 + 24), v3);
    }
    configure_mmio(v1);
    llc_get_conn_idx((void *)(uintptr_t)(v1), *(volatile uint32_t *)(v1 + 136) + v2);
    result = (volatile char *)rx_dispatch_frame(v1, v2, v3);
    if ( !result )
    {
      v4 = (uint8_t)(*(volatile uint8_t *)(v1 + 128) + 1);
      v5 = *(volatile uint32_t *)(v1 + 4) | 1;
      v6 = *(volatile uint8_t **)off_122874;
      *(volatile uint8_t *)(v1 + 128) = v4;
      *(volatile uint32_t *)(v1 + 4) = v5;
      v7 = *v6;
      if ( v4 > v7 )
      {
        return (volatile char *)phy_channel_is_5g(*(volatile uint8_t *)(v1 + 116), (int)off_122880, v1);
      }
      else if ( v4 == v7 )
      {
        return (volatile char *)tx_enqueue_frame(v1);
      }
    }
  }
  return result;
}



// check_hw_version @ 0x122884
volatile char *check_hw_version() {
  int v0; // r4

  v0 = *(volatile uint32_t *)off_1228D4 & 0x1800000;
  if ( **(volatile int16_t **)off_1228D0 < 0 && v0 == 25165824 )
    mmio_clear_register(dword_1228E4, dword_1228E0, 1308);
  unknown_func_12d14c(v0);
  if ( *((volatile uint8_t *)off_1228D8 + 18) )
    return (volatile char *)((int (*)())event_queue_drain)();
  else
    return read_config_byte(*((volatile char **)off_1228DC + 8));
}



// get_phy_channel @ 0x1228e8
int get_phy_channel() {
  volatile int *v0; // r2
  int result; // r0
  volatile uint32_t *v2; // r3

  v0 = *((volatile int **)off_12292C + 2);
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



// hci_send_cmd_0x0b @ 0x122930
int hci_send_cmd_0x0b(int a1, int a2, int a3, int a4) {
  volatile uint8_t *v5; // r4

  v5 = (volatile uint8_t *)ke_msg_alloc(11, a4, a3, 3);
  *v5 = call_fw_handler(a2, v5 + 1, v5 + 2);
  ke_msg_send_2((int)(uintptr_t)(v5));
  return 0;
}



