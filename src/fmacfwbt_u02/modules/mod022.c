// mac_process_queue @ 0x11c320
int mac_process_queue() {
  volatile uint32_t *v0; // r4
  int v1; // r6
  int v2; // r7
  int v3; // r5
  char v4; // r8
  volatile char *v5; // r3
  volatile uint32_t *v6; // r2
  int result; // r0
  char v8; // r1
  int v9; // r3
  int v10; // r1
  void *v11; // r0
  struct __attribute__((packed)) { uint32_t v12[28]; // [sp+0h] [bp-90h] BYREF
  char v13; // [sp+70h] [bp-20h] BYREF
  } _frame;
  v0 = (void *)(uintptr_t)(off_11C3D0);
  v1 = *((volatile uint32_t *)off_11C3D0 + 1);
  if ( v1 )
  {
    v2 = *((volatile uint32_t *)off_11C3D0 + 2);
    ke_event_set_lock(off_11C3D0);
    v3 = v0[4];
    if ( v3 )
      goto LABEL_3;
  }
  else
  {
    v3 = *((volatile uint32_t *)off_11C3D0 + 4);
    v2 = 0;
    if ( v3 )
    {
LABEL_3:
      memcpy((void *)(_frame.v12), (void *)(uintptr_t)(dword_11C3D4), 144);
      v4 = *((volatile uint8_t *)v0 + 160);
      if ( _frame.v12[1] )
        ke_event_set_lock(dword_11C3D4);
      if ( _frame.v12[8] )
        ke_event_set_lock(dword_11C3D8);
      if ( _frame.v12[15] )
        ke_event_set_lock(dword_11C3DC);
      if ( _frame.v12[22] )
        ke_event_set_lock(dword_11C3E0);
      mac_reset_controller();
      v0[4] = v3;
      *((volatile uint8_t *)v0 + 160) = v4;
      v0 = (void *)(uintptr_t)(off_11C3D0);
      v5 = (volatile char *)_frame.v12;
      v6 = (void *)(uintptr_t)(off_11C3D0);
      do
      {
        result = *((volatile uint32_t *)v5 + 5);
        v8 = v5[24];
        v6[10] = result;
        v5 += 28;
        *((volatile uint8_t *)v6 + 44) = v8;
        v6 += 7;
      }
      while ( &_frame.v13 != v5 );
      if ( v1 )
        goto LABEL_14;
      return result;
    }
  }
  result = mac_reset_controller();
  v0[4] = v3;
  if ( v1 )
  {
LABEL_14:
    v9 = dword_11C3E8;
    v10 = *((volatile uint32_t *)off_11C3E4 + 4);
    v11 = (void *)(uintptr_t)(off_11C3D0);
    v0[2] = v2;
    v0[1] = v9;
    return ke_event_lock(v11, v10 + 5000);
  }
  return result;
}



// txpacket_prepare @ 0x11c3ec
int txpacket_prepare(int a1, int a2) {
  int v2; // r2
  int v3; // r5
  int v4; // r3
  int result; // r0
  int v7; // r3
  volatile uint16_t *v8; // r5
  int v9; // r12
  unsigned int v10; // r2
  int v11; // r2
  unsigned int v12; // r4
  int v13; // r7

  v2 = *(volatile uint32_t *)(a1 + 84);
  v3 = *(volatile uint32_t *)(*(volatile uint32_t *)(a1 + 28) + 8);
  v4 = *(volatile uint16_t *)(a1 + 48);
  if ( (v2 & 0x200) == 0 || (result = *(volatile uint32_t *)(a1 + 84) & 0x400, (v2 & 0x400) != 0) )
  {
    v7 = v4 - 18;
    v8 = (volatile uint16_t *)(v3 + 18);
    if ( v7 <= 1 )
      return 0;
    v9 = dword_11C4B4 + 696 * *(volatile uint8_t *)(a2 + 12);
    while ( 1 )
    {
      v12 = *v8;
      v13 = v12 & 0x7FF;
      if ( v13 == 2045 )
        break;
      result = v12 & 0x800;
      if ( (v12 & 0x800) == 0 )
      {
        if ( v7 <= 3 )
          return result;
        v10 = v8[1];
        if ( (v10 & 8) != 0 )
          return result;
        v11 = *(volatile uint8_t *)(dword_11C4B8 + ((v10 >> 1) & 7)) + 4;
        if ( v11 > v7 )
          return 0;
LABEL_8:
        v7 -= v11;
        if ( *(volatile uint16_t *)(v9 + 32) == v13 )
          goto LABEL_13;
        goto LABEL_9;
      }
      v11 = 2;
      v7 -= 2;
      if ( *(volatile uint16_t *)(v9 + 32) == v13 )
      {
LABEL_13:
        result = v12 & 0x800;
        if ( (v12 & 0x800) != 0 )
        {
          *(volatile uint32_t *)(a2 + 224) = 0;
          return 1;
        }
        else if ( *(volatile uint8_t *)(a2 + 13) == v12 >> 12 )
        {
          memcpy((void *)(uintptr_t)(a2 + 228), (void *)(v8 + 1), v11 - 2);
          *(volatile uint32_t *)(a2 + 224) = a2 + 228;
          return 1;
        }
        return result;
      }
LABEL_9:
      v8 = (volatile uint16_t *)((volatile char *)v8 + v11);
      if ( v7 <= 1 )
        return 0;
    }
    v11 = 12;
    goto LABEL_8;
  }
  return result;
}



// rxreorder_process @ 0x11c4bc
int rxreorder_process(int result) {
  volatile uint32_t *v1; // r2
  volatile int16_t *v2; // r1
  unsigned int v3; // r3
  int v4; // r5
  int v5; // r1
  int16_t v6; // r0
  int v7; // r3
  int v8; // r1
  int v9; // r3
  int v10; // r4
  int v11; // r5
  int v12; // r6
  unsigned int v13; // r5
  int v14; // r8
  int v15; // r9
  int v16; // lr
  int v17; // nf
  int v18; // r0
  unsigned int v19; // r6
  int v20; // r12
  int v21; // r5
  unsigned int v22; // r4
  uint16_t v23; // r9
  volatile unsigned int *v24; // r10
  unsigned int v25; // r11
  uint16_t v26; // r8
  int v27; // r1
  uint16_t v28; // r7
  volatile uint16_t *v29; // r3
  volatile char *v30; // r0
  int v31; // r2
  int v32; // r11
  char v33; // r7
  unsigned int v34; // r4
  int16_t v35; // [sp+0h] [bp-Ch]
  int16_t v36; // [sp+4h] [bp-8h]

  v1 = (void *)(uintptr_t)(off_11C6F0);
  v2 = *(volatile int16_t **)off_11C6EC;
  v3 = *(volatile uint32_t *)(result + 84);
  v4 = *(volatile uint32_t *)(result + 28);
  *((volatile uint8_t *)off_11C6F0 + 200) = 0;
  v5 = *v2;
  if ( v5 < 0 )
  {
    result = *(volatile uint16_t *)(result + 48);
    if ( (unsigned int)result <= 0x1C )
    {
      v30 = aHdrdescFrmlenH;
      v31 = 2509;
      return ke_int_lock_1((int)v30, (int)aTxlHeTriggerPu, v31);
    }
  }
  if ( (v3 & 0x2000000) == 0 )
    goto LABEL_18;
  v6 = v3 >> 15;
  v7 = (v3 >> 15) & 0x3FF;
  if ( v5 < 0 && (v6 & 0x3F0) == 0 )
  {
    v30 = aKeyIdxHwMmSecD;
    v31 = 2522;
    return ke_int_lock_1((int)v30, (int)aTxlHeTriggerPu, v31);
  }
  v8 = dword_11C6F4;
  v9 = (uint8_t)(v7 - 16);
  v10 = dword_11C6F4 + 696 * v9;
  result = *(volatile uint8_t *)(v10 + 37);
  if ( *(volatile uint8_t *)(v10 + 37) )
  {
    v11 = *(volatile uint8_t *)(v10 + 34);
    v1[45] = *(volatile uint32_t *)(v10 + 38);
    v12 = dword_11C6FC;
    *((volatile uint16_t *)off_11C6F8 + 2) = *(volatile uint16_t *)(v10 + 42);
    result = v1[4];
    if ( result == v12 + 1320 * v11 )
    {
      result = *(volatile uint32_t *)off_11C704 & 0x3F;
      if ( *(volatile uint8_t *)(*(volatile uint32_t *)off_11C700 + 62) + 3 < result )
      {
        v13 = *(volatile uint32_t *)off_11C70C;
        v14 = v1[42];
        v15 = *(volatile uint32_t *)off_11C708 & 0xF;
        v16 = HIWORD(*(volatile uint32_t *)off_11C708) & 3;
        v17 = (*(volatile uint32_t *)off_11C708 & 0x80000) != 0;
        v35 = (uint16_t)*(volatile uint32_t *)off_11C708 >> 4;
        *((volatile uint16_t *)v1 + 94) = v35;
        *((volatile uint8_t *)v1 + 191) = v15;
        *((volatile uint8_t *)v1 + 195) = v16;
        v18 = (uint8_t)v13 >> 4;
        v19 = v13 & 7;
        if ( v17 )
        {
          v32 = 2;
          v33 = 2;
          v36 = 1024;
        }
        else
        {
          v32 = 1;
          v33 = 1;
          v36 = 512;
        }
        v20 = (v13 >> 9) & 7;
        *((volatile uint8_t *)v1 + 192) = v33;
        *((volatile uint8_t *)v1 + 193) = v18;
        *((volatile uint8_t *)v1 + 199) = (v13 & 0x1000) != 0;
        *((volatile uint8_t *)v1 + 194) = v20;
        *((volatile uint8_t *)v1 + 196) = v19;
        if ( v15 )
        {
          v21 = (v21 & ~0xFFu) | ((uint8_t)(*((volatile uint8_t *)v1 + 198)) & 0xFFu);
        }
        else
        {
          v34 = v13 >> 30;
          v21 = HIBYTE(v13) & 3;
          *((volatile uint8_t *)v1 + 197) = *((volatile uint8_t *)off_11C72C + v34);
          *((volatile uint8_t *)v1 + 198) = v21;
        }
        while ( *(volatile int *)off_11C724 >= 0 )
          ;
        v22 = *(volatile uint32_t *)off_11C724 & dword_11C710;
        if ( v19 > 2 )
          v23 = *((volatile uint16_t *)&((volatile uint32_t *)(uintptr_t)off_11C730)[3 * v18] + 3 * ((uint8_t)(v19 - 3) >> 1) + v32) << ((v19 - 3) & 1);
        else
          v23 = *(volatile uint16_t *)(*((volatile uint32_t *)off_11C714 + v19) + 2 * (3 * v18 + v32));
        v24 = (volatile unsigned int *)off_11C728;
        if ( v22 >= *(volatile uint32_t *)(v14 + 12) )
          v22 = *(volatile uint32_t *)(v14 + 12);
        v1[44] = v22;
        v25 = *v24;
        v26 = *(volatile uint8_t *)(v14 + 28);
        v27 = v8 + 696 * v9;
        v28 = v36 | v18;
        result = *(volatile uint32_t *)(v27 + 340);
        v1[42] = v27;
        *((volatile uint8_t *)v1 + 200) = v22 > 0x27;
        *((volatile uint16_t *)v1 + 93) = v26 * (1 << v21) * v23;
        v1[43] = (HIBYTE(v25) << 6) | 0x13;
        *(volatile uint16_t *)(result + 130) = v28 | ((uint16_t)v16 << 7) | (16 * v20) | 0x3000;
        *(volatile uint16_t *)(result + 132) = v19 | (8 * v35);
        v1[51] = 0;
      }
    }
  }
  else
  {
LABEL_18:
    v29 = *(volatile uint16_t **)(v4 + 8);
    *((volatile uint16_t *)v1 + 90) = v29[5];
    *((volatile uint16_t *)v1 + 91) = v29[6];
    *((volatile uint16_t *)v1 + 92) = v29[7];
  }
  return result;
}


// global_flag_set @ 0x11c734
void global_flag_set() {
  volatile uint8_t *v1; // r4

  v1 = (void *)(uintptr_t)(off_11C74C);
  *(volatile uint8_t *)off_11C74C = 1;
  mac_irq_handler_1();
  *v1 = 0;
  ke_event_poll();
}



// check_hw_status @ 0x11c750
int check_hw_status() {
  int result; // r0
  int v1; // r4
  volatile int *v2; // r2
  int v3; // r3

  result = check_event_state_1();
  if ( (*(volatile uint32_t *)off_11C784 & 0x8000) != 0 && (v1 = result, (result = sys_status_get_bit21()) != 0) && v1 )
  {
    v2 = (volatile int *)off_11C78C;
    v3 = *(volatile uint32_t *)off_11C78C;
    *((volatile uint32_t *)off_11C788 + 4) = v1;
    *v2 = v3 | 0x80;
  }
  else
  {
    *((volatile uint32_t *)off_11C788 + 4) = 0;
  }
  return result;
}



// enable_irq @ 0x11c790
void enable_irq() {
  *(volatile uint32_t *)off_11C79C |= 0x80u;
}



// nullsub_8 @ 0x11c7a0
int nullsub_8(void) {
  return 0;
}


// is_associated @ 0x11c7a4
int is_associated(int a1, int a2) {
  int v2; // r3

  v2 = *(volatile uint32_t *)(a1 + 68);
  if ( v2 && (*(volatile uint16_t *)(v2 + 8) & 0x200) != 0 )
    return *((volatile uint32_t *)off_11C7D0 + 43);
  if ( *(volatile int *)(*(volatile uint32_t *)(a1 + 44) + 60) >= 0 )
    return *(volatile uint32_t *)(a2 + 580);
  return (*(volatile uint8_t *)(a2 + 309) << 9) | 0x8007;
}



// get_rate_index @ 0x11c7d4
unsigned int get_rate_index(int a1, int a2, volatile uint32_t *a3, volatile uint32_t *a4, volatile uint32_t *a5, volatile int *a6) {
  unsigned int v6; // r4
  int v7; // r8
  int v8; // r0
  int v9; // r9
  unsigned int v10; // r12
  unsigned int v11; // r7
  volatile int16_t **v12; // r4
  volatile int16_t *v13; // r1
  int v14; // r2
  volatile int16_t **v16; // r4
  volatile int16_t *v17; // r1
  int v18; // r2

  v6 = *(volatile uint32_t *)(a1 + 4);
  v7 = *(volatile uint8_t *)(a1 + 12);
  v8 = ((v6 >> 4) & 7) + 1;
  *a6 = v8;
  v9 = (v6 >> 9) & 3;
  v10 = v6 >> 4;
  v11 = v6 & 0xF;
  if ( a2 == 7 && ((v6 >> 7) & 3) == 1 )
  {
    v16 = (volatile int16_t **)off_11C8A4;
    v17 = *(volatile int16_t **)off_11C8A4;
    *a3 = dword_11C8BC;
    v18 = *v17;
    *a4 = off_11C8C0;
    if ( v18 < 0 )
    {
      if ( v11 )
      {
        mmio_irq_clear(dword_11C8CC, dword_11C8B4, 2707);
        if ( **v16 >= 0 )
          goto LABEL_3;
        v8 = *a6;
      }
      if ( v8 != 1 )
        mmio_irq_clear(dword_11C8C4, dword_11C8B4, 2709);
    }
  }
  else
  {
    v12 = (volatile int16_t **)off_11C8A4;
    v13 = *(volatile int16_t **)off_11C8A4;
    *a3 = dword_11C8A8;
    v14 = *v13;
    *a4 = dword_11C8AC;
    if ( v14 < 0 )
    {
      if ( (v10 & 4) == 0 || (mmio_irq_clear(dword_11C8C8, dword_11C8B4, 2717), **v12 < 0) )
      {
        if ( v11 > 0xB )
          mmio_irq_clear(dword_11C8B8, dword_11C8B4, 2718);
      }
    }
  }
LABEL_3:
  *a5 = *(volatile uint32_t *)(dword_11C8B0 + 696 * v7 + 12);
  return v9 + 6 * v11;
}



// tx_buffer_cleanup @ 0x11c8d0
int tx_buffer_cleanup(int a1) {
  volatile uint8_t *v1; // r6
  int v2; // r7
  int v3; // r5
  int result; // r0
  volatile uint32_t *v5; // r1
  volatile uint32_t *v6; // r4
  unsigned int v7; // t1
  int v8; // r3

  v1 = (void *)(uintptr_t)(off_11C91C);
  v2 = dword_11C920;
  v3 = *((volatile uint32_t *)off_11C91C + 4);
  result = a1 - 4;
  v5 = (void *)(uintptr_t)(off_11C91C);
  v6 = (volatile uint32_t *)(v3 + 8);
  do
  {
    v7 = *(volatile uint32_t *)(result + 4);
    result += 4;
    v8 = (v7 >> 4) & 0xFF0 | v7 & 0xF;
    v5[10] = v8;
    *((volatile uint8_t *)v5 + 44) = BYTE2(v7);
    if ( v3 )
      v5[10] = v8 | *v6 & v2;
    ++v6;
    v5 += 7;
  }
  while ( (volatile uint32_t *)(v3 + 24) != v6 );
  v1[160] = 1;
  return result;
}



// set_rf_channel @ 0x11c924
volatile uint8_t * set_rf_channel(volatile uint8_t *result) {
  volatile uint8_t *v1; // r3

  v1 = (void *)(uintptr_t)(off_11C934);
  *((volatile uint8_t *)off_11C934 + 164) = *result;
  v1[165] = result[1];
  return result;
}



// get_station_by_index @ 0x11c938
int get_station_by_index(int result, int a2) {
  int v2; // r2
  int v3; // r3

  v2 = dword_11C964;
  v3 = dword_11C964 + 28 * a2;
  if ( *(volatile uint32_t *)(v3 + 24) )
  {
    if ( *(volatile uint8_t *)(v3 + 46) )
      *(volatile uint32_t *)(v3 + 36) = result;
    *(volatile uint8_t *)(v2 + 28 * a2 + 45) = 1;
  }
  return result;
}



// configure_dma @ 0x11c968
int configure_dma(int a1) {
  volatile uint32_t *v1; // r3
  int v2; // r1

  v1 = (void *)(uintptr_t)(off_11C988);
  v2 = *((volatile uint32_t *)off_11C984 + 4);
  *((volatile uint32_t *)off_11C988 + 1) = dword_11C98C;
  v1[2] = a1;
  return ke_event_lock(v1, v2 + 5000);
}



// get_cal_value @ 0x11c990
volatile unsigned int * get_cal_value(volatile unsigned int *result) {
  int v1; // r2

  v1 = *(volatile uint16_t *)(dword_11C9C0 + 1320 * *((volatile uint8_t *)result + 28) + 1222);
  if ( v1 != 1023 && *((volatile uint8_t *)off_11C9C4 + 361) != 2 )
    return check_packet_bits((volatile unsigned int *)(result[17] + 4), *(volatile uint32_t *)(result[17] + 40), v1);
  return result;
}



// set_cal_value @ 0x11c9c8
volatile unsigned int * set_cal_value(volatile unsigned int *result) {
  int v1; // r2
  int v2; // r5
  volatile unsigned int *v3; // r4
  uint64_t v4; // r6
  volatile unsigned int *v5; // r0

  v1 = *(volatile uint16_t *)(dword_11CA10 + 1320 * *((volatile uint8_t *)result + 28) + 1222);
  if ( v1 != 1023 && *((volatile uint8_t *)off_11CA14 + 361) != 2 )
  {
    v4 = *((volatile uint64_t *)result + 9);
    v2 = dword_11CA10 + 1320 * *((volatile uint8_t *)result + 28);
    v3 = (volatile unsigned int *)(v4 + 64);
    v4 = (v4 & ~0xFFFFFFFFull) | ((uint32_t)(v4 + 80) & 0xFFFFFFFFu);
    while ( 1 )
    {
      v5 = v3++;
      result = check_packet_bits(v5, *(volatile uint32_t *)(HIDWORD(v4) + 36), v1);
      if ( v3 == (volatile unsigned int *)v4 )
        break;
      v1 = *(volatile uint16_t *)(v2 + 1222);
    }
  }
  return result;
}



