// lookup_table_entry @ 0x129ebc
unsigned int lookup_table_entry(int a1, int a2, unsigned int a3, unsigned int a4) {
  unsigned int v4; // r6
  int v6; // r7
  unsigned int v7; // r5
  unsigned int v8; // r3
  unsigned int v9; // r5
  volatile int16_t **v10; // r3
  volatile uint32_t *v11; // r2
  unsigned int v12; // r3
  unsigned int result; // r0
  volatile uint32_t *v14; // r1

  v4 = a3;
  v6 = dword_129F74 + 1320 * a2;
  if ( a4 < a3 )
  {
    v9 = 0;
  }
  else
  {
    if ( *(volatile uint8_t *)(a1 + 19) == 1 )
      return 0;
    v7 = *(volatile uint32_t *)(a1 + 28);
    v8 = (a4 - a3) / v7;
    v4 = a3 + v7 + v8 * v7;
    v9 = v8 + 1;
  }
  v10 = (volatile int16_t **)off_129F78;
  *(volatile uint32_t *)(a1 + 44) = v4;
  if ( **v10 < 0 && *(volatile uint8_t *)(v6 + 106) )
    mmio_irq_clear(dword_129F88, dword_129F84, 98);
  v11 = (void *)(uintptr_t)(off_129F80);
  v12 = *(volatile uint8_t *)(a1 + 19);
  result = *((volatile uint32_t *)off_129F80 + 4) - *(volatile uint32_t *)off_129F7C - *(volatile uint32_t *)(v6 + 132) + v4;
  if ( v12 == 255 )
  {
    if ( (int)(result - *((volatile uint32_t *)off_129F80 + 4)) < 0 )
      goto LABEL_10;
    return result;
  }
  if ( v12 > v9 )
    v12 = (v12 & ~0xFFu) | ((uint8_t)(v12 - v9) & 0xFFu);
  else
    v12 = (v12 & ~0xFFu) | ((uint8_t)(0) & 0xFFu);
  v12 = (uint8_t)v12;
  *(volatile uint8_t *)(a1 + 19) = v12;
  if ( (int)(result - v11[4]) < 0 )
  {
LABEL_10:
    v14 = (void *)(uintptr_t)(off_129F80);
    while ( v12 )
    {
      while ( 1 )
      {
        result += *(volatile uint32_t *)(a1 + 28);
        if ( v12 != 255 )
          break;
        if ( (int)(result - v14[4]) >= 0 )
          return result;
      }
      v12 = (uint8_t)(v12 - 1);
      *(volatile uint8_t *)(a1 + 19) = v12;
      if ( (int)(result - v14[4]) >= 0 )
        goto LABEL_14;
    }
    return 0;
  }
LABEL_14:
  if ( !v12 )
    return 0;
  return result;
}



// get_table_entry @ 0x129f8c
int get_table_entry(int a1, int a2, unsigned int a3, unsigned int a4) {
  unsigned int v5; // r0
  uint8_t v6; // r4

  v5 = lookup_table_entry(a1, a2, a3, a4);
  v6 = v5;
  if ( !v5 )
    return 0;
  ke_event_lock((void *)(uintptr_t)(a1), v5);
  *(volatile uint8_t *)(a1 + 16) = 1;
  return v6;
}



// get_struct_ptr @ 0x129fac
int get_struct_ptr(int result, int a2, unsigned int a3) {
  int v3; // r8
  int v4; // r9
  int v5; // r5
  int v6; // r4
  int v8; // r3
  int v10; // r2
  volatile uint8_t *v11; // r7
  int v12; // r3
  int v13; // r7
  int v14; // r3
  int v15; // r3
  uint64_t v16; // kr00_8
  unsigned int v17; // r7
  volatile uint8_t *v18; // r9
  uint8_t v19; // r11
  unsigned int v20; // r3
  int v21; // r5
  int v22; // r2
  char v23; // r3
  volatile uint8_t *v24; // r7
  int v25; // r3
  int v26; // r6
  int v27; // r3
  int v28; // [sp+0h] [bp-Ch]
  int v29; // [sp+4h] [bp-8h]

  v3 = dword_12A164;
  v4 = 140 * result;
  v5 = result;
  v6 = dword_12A164 + 140 * result;
  if ( !a2 )
  {
    v24 = (volatile uint8_t *)(dword_12A164 + 140 * result);
    v25 = (uint8_t)v24[121];
    v24[132] = 0;
    if ( v25 )
    {
      if ( v24[16] )
      {
        ke_event_set_lock(v6);
        v24[16] = 0;
      }
      v26 = v3 + 140 * v5;
      v27 = *(volatile uint8_t *)(v26 + 64);
      *(volatile uint8_t *)(v26 + 121) = 0;
      if ( v27 )
      {
        ke_event_set_lock(v4 + 48 + v3);
        *(volatile uint8_t *)(v26 + 64) = 0;
      }
      *(volatile uint8_t *)(v3 + 140 * v5 + 121) = 0;
      state_machine_step((volatile uint8_t *)v6);
    }
    goto LABEL_19;
  }
  v8 = dword_12A164 + 140 * result;
  v10 = *(volatile uint8_t *)(a2 + 3);
  if ( !*(volatile uint8_t *)(v8 + 132) || *(volatile uint8_t *)(v8 + 120) != v10 )
  {
    v11 = (volatile uint8_t *)(dword_12A164 + 140 * result);
    v12 = (uint8_t)v11[121];
    v11[120] = v10;
    v11[132] = 1;
    if ( v12 )
    {
      if ( v11[16] )
      {
        ke_event_set_lock(v6);
        v11[16] = 0;
      }
      v13 = v3 + 140 * v5;
      v14 = *(volatile uint8_t *)(v13 + 64);
      *(volatile uint8_t *)(v13 + 121) = 0;
      if ( v14 )
      {
        ke_event_set_lock(v4 + 48 + v3);
        *(volatile uint8_t *)(v13 + 64) = 0;
      }
      *(volatile uint8_t *)(v3 + 140 * v5 + 121) = 0;
      state_machine_step((volatile uint8_t *)v6);
    }
    v15 = *(volatile uint16_t *)(a2 + 1) - 2;
    v16 = (int32_t)dword_12A160 * (int64_t)(int32_t)(v15);
    v17 = (uint8_t)((SHIDWORD(v16) >> 2) - (v15 >> 31));
    if ( (uint8_t)(SHIDWORD(v16) >> 2) != (uint8_t)(v15 >> 31) )
    {
      v28 = v3 + 140 * v5;
      v18 = (volatile uint8_t *)(a2 + 5);
      v19 = 0;
      v29 = v5;
      do
      {
        v20 = *v18;
        *(volatile uint8_t *)(v6 + 20) = v20;
        ++v19;
        if ( v20 )
        {
          v21 = *(volatile uint32_t *)(v18 + 5);
          if ( v20 <= 1 || v21 )
          {
            *(volatile uint32_t *)(v6 + 24) = *(volatile uint32_t *)(v18 + 1);
            v22 = v21 - 4000 - return_1000();
            v23 = *(volatile uint8_t *)(v6 + 20);
            *(volatile uint32_t *)(v6 + 28) = v22;
            *(volatile uint8_t *)(v6 + 19) = v23;
            if ( get_table_entry(v6, *(volatile uint8_t *)(v28 + 113), *(volatile uint32_t *)(v18 + 9), a3) )
              ++*(volatile uint8_t *)(v28 + 121);
          }
        }
        v18 += 13;
        v6 += 48;
      }
      while ( v19 < v17 );
      v5 = v29;
    }
    if ( *(volatile char *)(a2 + 4) < 0 )
    {
      *(volatile uint8_t *)(v3 + 140 * v5 + 115) = *(volatile uint8_t *)(a2 + 4) & 0x7F;
      return 140;
    }
LABEL_19:
    *(volatile uint8_t *)(v3 + 140 * v5 + 115) = 0;
    return 140;
  }
  return result;
}



// hw_init_1 @ 0x12a168
volatile int *hw_init_1() {
  volatile int *result; // r0
  volatile uint8_t *v1; // r3

  result = memset((volatile int *)dword_12A184, 0, 1u);
  v1 = (void *)(uintptr_t)(off_12A188);
  *((volatile uint8_t *)off_12A188 + 113) = -1;
  v1[253] = -1;
  return result;
}



// poll_ready @ 0x12a18c
int poll_ready(int a1, int a2) {
  volatile char *v2; // r4
  int v5; // r5
  volatile char *v7; // r3
  int v8; // r1
  int v9; // r0
  int v10; // r8
  int v11; // r10
  volatile int *v12; // r9
  int v13; // r2
  volatile uint8_t *v14; // r12
  int v15; // r0
  int v16; // r1
  int v17; // r4
  int v18; // r1

  v2 = (volatile char *)off_12A25C;
  if ( *((volatile uint8_t *)off_12A25C + 113) == 255 )
  {
    v5 = 0;
    v10 = 0;
    v11 = 48;
    v12 = (volatile int *)off_12A25C;
  }
  else
  {
    if ( *((volatile uint8_t *)off_12A25C + 253) != 255 )
      return 255;
    v5 = 1;
    v10 = 1;
    v11 = 188;
    v12 = (volatile int *)((volatile char *)off_12A25C + 140);
  }
  memset(v12, 0, 0x8Cu);
  v7 = &v2[140 * v10];
  v7[113] = a1;
  v7[112] = a2;
  if ( a2 == 1 )
  {
    v13 = dword_12A268;
    v14 = (void *)(uintptr_t)(off_12A26C);
    v7[66] = 1;
    v15 = v13 + 1320 * a1;
    v13 = (v13 & ~0xFFu) | ((uint8_t)(*v14) & 0xFFu);
    v16 = *(volatile uint32_t *)(v15 + 4);
    v7[133] = 1;
    *((volatile uint32_t *)v7 + 14) = (int)(uintptr_t)(&v2[v11]);
    v17 = dword_12A260;
    *(volatile uint32_t *)(v15 + 4) = v16 | 0x20;
    v18 = dword_12A264;
    *((volatile uint32_t *)v7 + 2) = (int)(uintptr_t)(v12);
    v7[17] = v5;
    v7[65] = v5;
    *((volatile uint32_t *)v7 + 26) = (int)(uintptr_t)(v12);
    *v14 = v13 + 1;
    *((volatile uint32_t *)v7 + 1) = v17;
    *((volatile uint32_t *)v7 + 13) = v17;
    v7[18] = 0;
    *((volatile uint32_t *)v7 + 25) = v18;
  }
  else
  {
    v8 = dword_12A260;
    v9 = dword_12A264;
    *((volatile uint32_t *)v7 + 14) = (int)(uintptr_t)(&v2[v11]);
    *((volatile uint32_t *)v7 + 2) = (int)(uintptr_t)(v12);
    v7[17] = v5;
    v7[65] = v5;
    *((volatile uint32_t *)v7 + 26) = (int)(uintptr_t)(v12);
    *((volatile uint32_t *)v7 + 1) = v8;
    *((volatile uint32_t *)v7 + 13) = v8;
    v7[18] = 0;
    v7[66] = 1;
    v7[133] = 1;
    *((volatile uint32_t *)v7 + 25) = v9;
  }
  return v5;
}



// rf_channel_state_get @ 0x12a270
int rf_channel_state_get(int result, int a2) {
  int v2; // r2
  int v3; // r3

  v2 = dword_12A2AC;
  v3 = dword_12A2AC + 140 * result;
  if ( *(volatile uint8_t *)(v3 + 113) != 255 )
  {
    if ( *(volatile uint8_t *)(v3 + 112) != 1 )
    {
      if ( !a2 )
        return result;
      goto LABEL_4;
    }
    --*(volatile uint8_t *)off_12A2B0;
    if ( a2 )
    {
LABEL_4:
      result = v2 + 140 * result;
      *(volatile uint8_t *)(result + 113) = -1;
    }
  }
  return result;
}



// rx_frame_process @ 0x12a2b4
volatile uint8_t * rx_frame_process(volatile uint8_t *result, int a2) {
  int v2; // r5
  int v3; // r7
  volatile uint8_t *v4; // r8
  int v5; // r9
  int v6; // r4
  volatile uint8_t *v7; // r5
  int v8; // r3

  if ( result[1224] && !(result[106] | a2) )
  {
    v2 = result[1225];
    v3 = dword_12A34C;
    v4 = (volatile uint8_t *)(dword_12A34C + 140 * v2);
    v5 = 140 * v2;
    if ( v4[16] )
    {
      ke_event_set_lock(dword_12A34C + 140 * v2);
      v4[16] = 0;
    }
    v6 = v3 + 140 * v2;
    if ( *(volatile uint8_t *)(v6 + 64) )
    {
      ke_event_set_lock(v5 + 48 + v3);
      *(volatile uint8_t *)(v6 + 64) = 0;
    }
    v7 = (volatile uint8_t *)(v3 + 140 * v2);
    v8 = v7[114];
    v7[115] = 0;
    v7[120] = 0;
    v7[132] = 0;
    if ( v8 )
    {
      ke_event_set_lock(v5 + 96 + v3);
      v7[114] = 0;
    }
    return state_machine_step(v4);
  }
  return result;
}



// rf_channel_offset_get @ 0x12a350
int rf_channel_offset_get(int a1) {
  return *(volatile uint8_t *)(dword_12A360 + 140 * a1 + 133);
}



// util_feature_get @ 0x12a364
unsigned int util_feature_get(int a1, volatile uint32_t *a2, volatile uint32_t *a3) {
  int v6; // r3
  int v7; // r0

  if ( **(volatile int16_t **)off_12A3AC < 0 && !*(volatile uint8_t *)(a1 + 1224) )
    mmio_irq_clear(dword_12A3B8, dword_12A3B4, 1311);
  v6 = dword_12A3B0 + 140 * *(volatile uint8_t *)(a1 + 1225);
  *a2 = *(volatile uint32_t *)(v6 + 128);
  v7 = *(volatile uint32_t *)(v6 + 124);
  *a3 = v7;
  return (unsigned int)(v7 - *a2) >> 31;
}



// rf_read_state @ 0x12a3bc
int rf_read_state(int a1, unsigned int a2) {
  volatile int16_t **v2; // r6
  int v5; // r2
  int v6; // r0
  int v7; // r3
  int v8; // r1
  int v9; // r3
  int v11; // r3
  unsigned int v12; // r1
  int v13; // r3
  int v14; // r3

  v2 = (volatile int16_t **)off_12A494;
  if ( **(volatile int16_t **)off_12A494 >= 0 )
  {
    v5 = *(volatile uint8_t *)(a1 + 1225);
    v6 = dword_12A498;
    v7 = 140 * v5 + 48 * a2 + dword_12A498;
    v8 = 2 * a2;
    v9 = *(volatile uint8_t *)(v7 + 16);
    if ( v9 != 1 )
    {
      if ( v9 != 2 )
        return 0;
      return *(volatile uint32_t *)(140 * v5 + 16 * (a2 + v8) + v6 + 12);
    }
    goto LABEL_10;
  }
  if ( *(volatile uint8_t *)(a1 + 1224) && a2 <= 1 )
  {
    v5 = *(volatile uint8_t *)(a1 + 1225);
    v6 = dword_12A498;
    v13 = 140 * v5 + 48 * a2 + dword_12A498;
    v8 = 2 * a2;
    v14 = *(volatile uint8_t *)(v13 + 16);
    if ( v14 != 1 )
    {
      if ( v14 == 2 )
        return *(volatile uint32_t *)(140 * v5 + 16 * (a2 + v8) + v6 + 12);
      goto LABEL_15;
    }
LABEL_10:
    v12 = v6 + 140 * v5 + 16 * (a2 + v8);
    return *(volatile uint32_t *)(v12 + 12) + *(volatile uint32_t *)(v12 + 24);
  }
  mmio_irq_clear(dword_12A4A0, dword_12A49C, 1325);
  v5 = *(volatile uint8_t *)(a1 + 1225);
  v6 = dword_12A498;
  v8 = 2 * a2;
  v11 = *(volatile uint8_t *)(140 * v5 + 48 * a2 + dword_12A498 + 16);
  if ( v11 == 1 )
    goto LABEL_10;
  if ( v11 == 2 )
    return *(volatile uint32_t *)(140 * v5 + 16 * (a2 + v8) + v6 + 12);
  if ( **v2 >= 0 )
    return 0;
LABEL_15:
  mmio_field_update(dword_12A4A4, dword_12A49C, 1337);
  return 0;
}



// bt_conn_event_process @ 0x12a4a8
volatile uint8_t * bt_conn_event_process(volatile uint8_t *result, int a2) {
  int v2; // r2
  int v3; // r7
  int v4; // r6
  int v5; // r12
  unsigned int v6; // r4
  int v7; // lr
  volatile uint8_t *v8; // r5
  int v9; // r3
  int v10; // r1

  if ( result[1224] )
  {
    v2 = result[1225];
    v3 = dword_12A538;
    v4 = dword_12A538 + 140 * v2;
    v5 = *(volatile uint8_t *)(v4 + 115);
    v6 = *((volatile uint32_t *)result + 1) & 0xFFFFFFBF;
    *(volatile uint8_t *)(v4 + 134) = 1;
    v7 = 140 * v2;
    v8 = (volatile uint8_t *)(v3 + 140 * v2);
    *((volatile uint32_t *)result + 1) = v6;
    if ( !v5 )
      return state_machine_step(v8);
    v9 = a2 + (v5 << 10);
    if ( *(volatile uint8_t *)(v4 + 112) || (v10 = a2 + 300, *((volatile uint32_t *)off_12A53C + 4) - v10 + 50 >= 0) )
    {
      *(volatile uint8_t *)(v3 + 140 * v2 + 114) = 1;
      ke_event_lock((void *)(uintptr_t)(v7 + 96 + v3), v9);
      return state_machine_step(v8);
    }
    *(volatile uint32_t *)(v4 + 116) = v9;
    *(volatile uint8_t *)(v4 + 114) = 2;
    return (volatile uint8_t *)ke_event_lock((void *)(uintptr_t)(v7 + 96 + v3), v10);
  }
  return result;
}



// bt_conn_flush @ 0x12a540
volatile uint8_t * bt_conn_flush(int a1) {
  volatile uint8_t *v1; // r0

  v1 = (volatile uint8_t *)(dword_12A564 + 140 * *(volatile uint8_t *)(a1 + 1225));
  v1[134] = 0;
  return state_machine_step(v1);
}



// bt_conn_validate @ 0x12a568
unsigned int bt_conn_validate(volatile uint8_t *a1, int a2, int a3) {
  unsigned int v3; // r4
  unsigned int v5; // r0
  int v8; // r7
  volatile uint8_t *v9; // r3
  unsigned int v10; // r7
  int v11; // r5
  int v12; // r2
  volatile uint8_t *v13; // r4
  unsigned int v14; // r5

  v3 = (uint8_t)a1[1224];
  if ( !a1[1224] )
    return v3;
  if ( !a1[106] )
  {
    v5 = (uint8_t)a1[1225];
    if ( **(volatile int16_t **)off_12A60C < 0 && v5 > 1 )
    {
      mmio_irq_clear(dword_12A610, dword_12A614, 1420);
      v5 = (uint8_t)a1[1225];
    }
    v8 = *(volatile uint32_t *)(a2 + 8);
    v9 = (volatile uint8_t *)(v8 + 36);
    v10 = v8 + *(volatile uint16_t *)(a3 + 28);
    if ( (unsigned int)v9 < v10 )
    {
      while ( 1 )
      {
        v11 = v9[1];
        v12 = *v9;
        v13 = v9;
        v9 += v11 + 2;
        if ( v12 == 221 && v13[5] == 9 )
        {
          v3 = (unsigned int)(v13 + 6);
          v14 = v3 + (uint16_t)(v11 - 4);
          if ( v3 < v14 )
          {
            while ( *(volatile uint8_t *)v3 != 12 )
            {
              v3 += *(volatile uint16_t *)(v3 + 1) + 3;
              if ( v14 <= v3 )
                goto LABEL_6;
            }
            if ( v3 )
              break;
          }
        }
LABEL_6:
        if ( v10 <= (unsigned int)v9 )
          goto LABEL_19;
      }
    }
    else
    {
LABEL_19:
      v3 = 0;
    }
    get_struct_ptr(v5, v3, *(volatile uint32_t *)(*(volatile uint32_t *)(*(volatile uint32_t *)(a3 + 8) + 8) + 24));
    return v3;
  }
  return 0;
}



