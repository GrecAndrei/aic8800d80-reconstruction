// init_flow_entry @ 0x11a1a8
int init_flow_entry(int a1, int a2) {
  uint64_t v2; // r6
  volatile int *v3; // r10
  int v6; // r1
  volatile int *v7; // r3
  int v8; // r2
  int v9; // t1
  int v10; // r4
  int v11; // r2
  unsigned int v12; // r0
  int v13; // r3
  int v14; // r3
  int v15; // r3
  volatile uint16_t *v16; // r0
  char v17; // r3
  uint64_t v18; // kr08_8
  int16_t v19; // r3
  unsigned int v21; // r3
  int v22; // r0
  int v23; // r3
  unsigned int v24; // r3

  v2 = *(volatile uint64_t *)(a1 + 72);
  *(volatile uint32_t *)(a1 + 36) = 0;
  *(volatile uint32_t *)(a1 + 68) = 0;
  *(volatile uint32_t *)(HIDWORD(v2) + 20) = 0;
  *(volatile uint32_t *)(HIDWORD(v2) + 68) = 256;
  if ( (uint32_t)v2 )
  {
    v3 = *(volatile int **)(a1 + 44);
    v6 = (int)(v3 + 16);
    v7 = v3;
    v8 = v2 + 40;
    do
    {
      v9 = *v7++;
      *(volatile uint32_t *)(v8 + 4) = v9;
      v8 += 4;
    }
    while ( v7 != (volatile int *)v6 );
    if ( (*(volatile uint16_t *)(a1 + 30) & 0x2000) != 0 )
    {
      v10 = *(volatile uint32_t *)(dword_11A310 + 696 * *(volatile uint8_t *)(a1 + 29) + 340);
      if ( **(volatile int16_t **)off_11A30C >= 0 || v10 )
      {
        v11 = HIDWORD(v2);
      }
      else
      {
        irq_disable_mmio_write(dword_11A318, dword_11A314, 475);
        v11 = *(volatile uint32_t *)(a1 + 76);
      }
      v12 = *(volatile uint32_t *)(v10 + 156);
      *(volatile uint32_t *)(v2 + 68) = v3[5];
      v13 = *(volatile uint32_t *)(v10 + 160);
      *(volatile uint32_t *)(v2 + 84) = v3[9];
      v6 = (v12 >> 11) & 5;
      *(volatile uint32_t *)(v2 + 64) = v12;
      *(volatile uint32_t *)(v2 + 80) = v13;
      if ( v6 == 5 )
      {
        v6 = *(volatile uint8_t *)(v10 + 165);
        v21 = v13 & 0xFFFCFFFF;
        if ( (v12 & 0x600) == 0x400 )
          v22 = 0x20000;
        else
          v22 = 0x10000;
        v23 = v21 | v22;
        if ( *(volatile uint8_t *)(v10 + 165) )
          v24 = v23 | 0x40000;
        else
          v24 = v23 & 0xFFFBFFFF;
        *(volatile uint32_t *)(v2 + 80) = v24;
      }
      if ( (v3[15] & 4) == 0 )
        *(volatile uint32_t *)(v2 + 48) &= 0xFFFFFE7F;
      if ( a2 )
        goto LABEL_16;
      v14 = *(volatile uint16_t *)(a1 + 30);
      v6 = v14 << 18;
      if ( (v14 & 0x2000) != 0 )
      {
        v15 = (*(volatile uint32_t *)(*(volatile uint32_t *)(a1 + 44) + 60) >> 4) & 1;
        goto LABEL_13;
      }
      v3 = *(volatile int **)(a1 + 44);
    }
    else
    {
      v11 = HIDWORD(v2);
      if ( a2 )
      {
LABEL_16:
        *(volatile uint8_t *)(v11 + 1) = 1;
        ((int (*)())sta_rate_status_check)((void *)(uintptr_t)(a1), v6);
        v18 = *(volatile uint64_t *)(v2 + 96);
        v19 = *(volatile uint16_t *)(a1 + 82) | 6;
        *(volatile uint32_t *)(HIDWORD(v2) + 44) = HIDWORD(v18);
        *(volatile uint32_t *)(HIDWORD(v2) + 48) = v2 + 44;
        *(volatile uint32_t *)(HIDWORD(v2) + 64) = v18;
        *(volatile uint16_t *)(a1 + 82) = v19;
        return HIDWORD(v2) + 12;
      }
    }
    v15 = ((unsigned int)v3[15] >> 3) & 1;
LABEL_13:
    if ( !v15 )
    {
      v16 = *(volatile uint16_t **)(HIDWORD(v2) + 28);
      v6 = (uint16_t)*v16;
      if ( (*v16 & 0x8000) != 0 )
      {
        *v16 = v6 & 0x7FFF;
        v17 = *(volatile uint8_t *)(a1 + 50) - 4;
        *(volatile uint8_t *)(a1 + 51) -= 4;
        *(volatile uint8_t *)(a1 + 50) = v17;
        v6 = *(volatile uint32_t *)(HIDWORD(v2) + 36) - 4;
        *(volatile uint32_t *)(HIDWORD(v2) + 32) -= 4;
        *(volatile uint32_t *)(HIDWORD(v2) + 36) = v6;
      }
    }
    goto LABEL_16;
  }
  return 0;
}



// enable_component @ 0x11a31c
int enable_component(int a1, volatile int *a2, unsigned int a3, unsigned int a4, uint8_t a5) {
  int v5; // r6
  volatile int *v6; // r8
  int v7; // r4
  volatile uint32_t *v8; // r0
  volatile uint32_t *v10; // r7
  volatile int16_t *v11; // r8
  unsigned int v12; // r12
  unsigned int v13; // r0
  char v14; // r5
  int v15; // r10
  unsigned int v16; // r3
  unsigned int v17; // r1
  unsigned int v18; // r9
  int v19; // r11
  int16_t v20; // r7
  int16_t v21; // r1
  int16_t v22; // r1
  int v23; // r7
  int v24; // r9
  unsigned int v25; // r9
  int v26; // r3
  int v27; // r2
  int v28; // r1
  volatile int *v29; // r1
  int v30; // r2
  volatile int16_t *v32; // r8
  int v33; // r3
  int v34; // [sp+4h] [bp-20h]
  int v35; // [sp+4h] [bp-20h]
  int v36; // [sp+8h] [bp-1Ch]
  int v37; // [sp+Ch] [bp-18h]
  int v38; // [sp+10h] [bp-14h]
  int v40; // [sp+1Ch] [bp-8h]

  v5 = *(volatile uint32_t *)(a1 + 68);
  v6 = (volatile int *)off_11A57C;
  v7 = a1;
  v8 = (void *)(uintptr_t)(off_11A55C);
  *(volatile uint8_t *)(v5 + 14) = 1;
  v37 = v8[43];
  v40 = *(volatile uint32_t *)(v5 + 40);
  v38 = v5 + 16;
  v36 = *v6;
  v10 = *(volatile uint32_t **)(v7 + 76);
  v11 = *(volatile int16_t **)off_11A560;
  v12 = 0;
  *(volatile uint16_t *)(v5 + 10) = 0;
  *(volatile uint32_t *)(v5 + 40) = 0;
  v13 = 0;
  v14 = 0;
  v15 = 0;
  while ( 1 )
  {
    v16 = *(volatile uint32_t *)(v7 + 36);
    v17 = (uint16_t)(((v10[9] + 3) & 0xFFFC) + 4);
    v18 = (uint16_t)(v17 + 4 * ((v16 >> 9) & 0x3FF));
    if ( v18 >= a4 )
    {
      v13 += v18;
      if ( v13 > a3 )
        goto LABEL_23;
    }
    else
    {
      if ( a4 <= v17 )
      {
        v19 = (uint16_t)(((v10[9] + 3) & 0xFFFC) + 4);
        v12 = 0;
      }
      else
      {
        v12 = ((unsigned int)(uint16_t)(a4 - v17) + 3) >> 2;
        v19 = (uint16_t)(v17 + 4 * v12);
      }
      v13 += v19;
      if ( v13 > a3 )
      {
LABEL_23:
        v25 = *(volatile uint32_t *)(v7 + 36);
        if ( !v15 )
        {
          if ( v17 > a3 )
          {
            *(volatile uint32_t *)(v5 + 40) = v40;
            ((int (*)())channel_table_lookup)(v38, a5, a3);
            return 0;
          }
          v26 = *(volatile uint32_t *)v7;
          *(volatile uint16_t *)(v5 + 10) += *(volatile uint16_t *)(v7 + 80);
          v14 = 1;
          if ( (v25 & 0x380000) != 0x280000 )
          {
LABEL_16:
            v27 = *(volatile uint32_t *)(v7 + 76);
            *(volatile uint32_t *)(v5 + 324) = v7;
            *(volatile uint32_t *)(v7 + 36) = v25 | 0x380000;
            v28 = *v11;
            *(volatile uint32_t *)(v27 + 68) = v25 | 0x380100;
            *(volatile uint32_t *)(v27 + 20) = 0;
            if ( v28 >= 0 )
              goto LABEL_17;
            goto LABEL_27;
          }
LABEL_26:
          v34 = v26;
          init_flow_entry(v7, 1);
          v27 = *(volatile uint32_t *)(v7 + 76);
          v32 = *(volatile int16_t **)off_11A560;
          *(volatile uint32_t *)(v7 + 68) = v5;
          v38 = v27 + 12;
          v26 = v34;
          if ( *v32 >= 0 )
          {
LABEL_17:
            v29 = (volatile int *)off_11A568;
            *(volatile uint8_t *)(v27 + 1) = v14;
            v30 = *v29;
            *a2 = v26;
            if ( !*(volatile uint8_t *)(v30 + 1) )
              *(volatile uint32_t *)(v5 + 88) = *(volatile uint32_t *)(v5 + 20);
            return v38;
          }
LABEL_27:
          if ( *(volatile uint32_t *)(dword_11A574 + 84 * a5 + 28) != v5 )
          {
            v35 = v26;
            irq_disable_mmio_write(dword_11A578, dword_11A56C, 1119);
            v27 = *(volatile uint32_t *)(v7 + 76);
            v26 = v35;
          }
          goto LABEL_17;
        }
        v25 = *(volatile uint32_t *)(v15 + 36);
        v26 = v7;
        v23 = v25 & 0x380000;
        v7 = v15;
LABEL_15:
        if ( v23 != 2621440 )
          goto LABEL_16;
        goto LABEL_26;
      }
    }
    if ( v10[7] )
      *(volatile uint32_t *)(v10[8] - 3) = v37;
    if ( v18 < a4 )
    {
      v16 = v10[17] & 0xFFF801FF | (v12 << 9);
      *(volatile uint32_t *)(v7 + 36) = v16;
      v10[17] = v16 | 0x100;
    }
    v20 = *(volatile uint16_t *)(v7 + 80);
    v21 = *(volatile uint16_t *)(v5 + 10);
    *(volatile uint32_t *)(v5 + 40) = v13;
    v22 = v21 + v20;
    v23 = v16 & 0x380000;
    *(volatile uint16_t *)(v5 + 10) = v22;
    if ( (v16 & 0x380000) == 0x380000 )
      break;
    v24 = *(volatile uint32_t *)v7;
    ++v14;
    if ( *v11 < 0 && !v24 )
    {
      irq_disable_mmio_write(dword_11A570, dword_11A56C, 1113);
      __und(0xFFu);
    }
    if ( *(volatile uint8_t *)(v36 + 62) > (*(volatile uint32_t *)off_11A564 & 0x3Fu) )
    {
      v25 = v16;
      v26 = *(volatile uint32_t *)v7;
      goto LABEL_15;
    }
    v10 = *(volatile uint32_t **)(v24 + 76);
    v15 = v7;
    v7 = *(volatile uint32_t *)v7;
  }
  if ( *v11 < 0 && *(volatile uint32_t *)(dword_11A574 + 84 * a5 + 28) != v5 )
    irq_disable_mmio_write(dword_11A578, dword_11A56C, 1119);
  v33 = *(volatile uint32_t *)(v7 + 76);
  *a2 = *(volatile uint32_t *)v7;
  *(volatile uint32_t *)(v33 + 20) = 0;
  return v5 + 16;
}



// config_stream @ 0x11a580
int config_stream(int a1, volatile int *a2, unsigned int a3, unsigned int a4, uint8_t a5) {
  int v5; // r7
  int v6; // r6
  int result; // r0
  volatile uint32_t *v12; // r3
  unsigned int v13; // r2
  unsigned int v14; // r1
  int16_t v15; // r12
  int16_t v16; // r2
  unsigned int v17; // r4
  int v18; // r4
  int v19; // r1
  int v20; // lr
  int v21; // r12
  volatile uint32_t *v22; // [sp+Ch] [bp-8h]
  unsigned int v23; // [sp+Ch] [bp-8h]

  v5 = *a2;
  v6 = *(volatile uint32_t *)(*a2 + 68);
  v22 = *(volatile uint32_t **)(a1 + 76);
  result = compare_device_state(a1, *a2, a5);
  if ( result )
  {
    v12 = v22;
    v13 = (uint16_t)(((v22[9] + 3) & 0xFFFC) + 4);
    if ( a4 > v13 )
    {
      v14 = ((unsigned int)(uint16_t)(a4 - v13) + 3) >> 2;
      v13 = (uint16_t)(v13 + 4 * v14);
    }
    else
    {
      v14 = 0;
    }
    v23 = v13 + *(volatile uint32_t *)(v6 + 40);
    if ( v23 > a3 && (*(volatile uint32_t *)off_11A6A0 & 0x3Fu) <= 0x11 )
    {
      return 0;
    }
    else
    {
      v15 = *(volatile uint16_t *)(a1 + 80);
      v16 = *(volatile uint16_t *)(v6 + 10);
      v17 = *(volatile uint32_t *)(a1 + 36) & 0xFFE7FFFF;
      --*(volatile uint8_t *)(dword_11A6A4 + 84 * a5 + 80);
      v12[5] = *(volatile uint32_t *)(v6 + 24);
      v18 = v17 | (v14 << 9);
      *(volatile uint16_t *)(v6 + 10) = v16 + v15;
      *(volatile uint32_t *)(v6 + 24) = (int)(uintptr_t)(v12 + 3);
      *(volatile uint32_t *)(v6 + 40) = v23;
      *(volatile uint32_t *)(v6 + 268) = a1;
      *(volatile uint32_t *)(a1 + 36) = v18 | 0x680000;
      v19 = *(volatile uint32_t *)(v5 + 36);
      v20 = *(volatile uint32_t *)(v5 + 76);
      v21 = *(volatile uint32_t *)(*(volatile uint32_t *)(v6 + 324) + 76);
      *(volatile uint32_t *)(a1 + 68) = v6;
      v19 &= 0xFFE7FFFF;
      v12[17] = v18 | 0x680100;
      v12[12] = 0;
      *(volatile uint32_t *)(v5 + 36) = v19 | 0x300000;
      *(volatile uint32_t *)(v20 + 68) = v19 | 0x300100;
      ++*(volatile uint8_t *)(v21 + 1);
      if ( v23 > a3 )
      {
        enable_component(a1, a2, a3, a4, a5);
        return 0;
      }
      else
      {
        btm_read_indirect((volatile int16_t *)v5);
        *a2 = **(volatile uint32_t **)(v6 + 324);
        return 1;
      }
    }
  }
  return result;
}



// invalid_handler @ 0x11a6a8
int invalid_handler(int result) {
  volatile int *v1; // r4
  int v2; // r2
  int v3; // r1
  int v4; // r3
  int v5; // r3
  int v6; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_11A6EC = 1;
  }
  v1 = (volatile int *)off_11A6F4;
  v2 = dword_11A6F0 + 84 * result;
  v3 = *(volatile uint8_t *)(v2 + 80);
  v4 = *(volatile uint32_t *)off_11A6F4 + 1;
  *(volatile uint32_t *)off_11A6F4 = v4;
  if ( !v3 && *(volatile uint32_t *)(v2 + 44) )
  {
    result = btm_get_conn_entry(result);
    v4 = *v1;
  }
  if ( v4 )
  {
    v5 = v4 - 1;
    v6 = *(volatile uint32_t *)off_11A6EC;
    *v1 = v5;
    if ( !v5 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
  return result;
}



// check_status_flags @ 0x11a6f8
volatile unsigned int * check_status_flags(volatile unsigned int *result, volatile unsigned int *a2) {
  unsigned int v2; // r4
  unsigned int v3; // r5
  int v4; // r2
  int v5; // r5
  unsigned int v6; // r3
  int v7; // r2

  v2 = *result;
  if ( (*result & 0x1C000) == 0 )
  {
    if ( (v2 & 0x2000) != 0 )
      v3 = *result & 0xF;
    else
      v3 = *result & 7;
    v4 = (v2 >> 11) & 6;
    if ( v4 )
    {
      if ( v3 >= 3 )
        v4 = 0x100000;
      else
        v4 = 0x80000;
      if ( v3 >= 3 )
        v5 = 8;
      else
        v5 = 4;
    }
    else if ( v3 > 3 )
    {
      v4 = 0x80000;
      v5 = 4;
    }
    else
    {
      v5 = 0;
    }
    *result = v4 | (((v2 >> 7) & 3) << 24) | v2 & 0xE0003FFF | 0x4008000;
    v6 = *a2 & 0xFFFF00FF;
    v7 = dword_11A76C + v5;
    *a2 = v6;
    *a2 = v6 | (*(volatile char *)(v7 + 198) << 8);
  }
  return result;
}



// tx_status_check @ 0x11a770
int tx_status_check(int result, int a2) {
  int v2; // r3
  int v3; // r2
  unsigned int v4; // r3

  v2 = *(volatile uint32_t *)(result + 60);
  if ( v2 < 0 )
  {
    v3 = *(volatile uint32_t *)(result + 36);
    if ( **(volatile int16_t **)off_11A7B4 >= 0 || (v2 & 0x10000) != 0 )
    {
      v4 = *(volatile uint32_t *)(v3 + 20) & 0xFFFE3FFF | 0x4000;
      *(volatile uint32_t *)(result + 60) = 0;
      *(volatile uint32_t *)(v3 + 20) = v4;
      return tx_queue_set_head(result, a2);
    }
    else
    {
      return log_assert_failure((int)aAThdStatusRetr, (int)aTxlAggCheckRts, 3371);
    }
  }
  return result;
}


// get_conn_env @ 0x11a7c0
int get_conn_env(int result) {
  int v1; // r5
  int v2; // r1
  char v3; // r3
  int v4; // r4

  v1 = dword_11A7FC;
  v2 = *(volatile uint32_t *)(dword_11A7FC + 84 * result + 40);
  if ( v2 )
  {
    v3 = *(volatile uint8_t *)(v2 + 14) - 1;
    v4 = result;
    *(volatile uint8_t *)(v2 + 14) = v3;
    if ( !v3 )
      co_list_push_back(*(volatile uint32_t *)(v2 + 340), (volatile uint32_t *)v2);
    *(volatile uint32_t *)(v1 + 84 * v4 + 40) = 0;
    return 84;
  }
  return result;
}


// rx_packet_parse @ 0x11a800
int rx_packet_parse(volatile uint32_t *a1, int a2) {
  int v2; // r10
  volatile int *v3; // r4
  int16_t v4; // r2
  int v5; // r6
  int v6; // r3
  volatile uint32_t *v7; // r5
  int v8; // r0
  int v9; // r3
  volatile char *v11; // r0
  int v12; // r7
  int v13; // r1
  int v14; // r4
  volatile int16_t **v15; // r11
  int v16; // r0
  unsigned int v17; // r2
  int16_t v18; // r3
  volatile int *v19; // r6
  unsigned int v20; // r0
  unsigned int v21; // r9
  volatile uint32_t *v22; // r12
  int v23; // r8
  int v24; // r5
  unsigned int v25; // r1
  unsigned int v26; // r4
  unsigned int v27; // r2
  volatile int *v28; // r5
  int v29; // r0
  int v30; // r3
  int v31; // r2
  volatile int *v32; // r4
  int v33; // r2
  int v34; // r2
  int v35; // r2
  volatile int *v36; // r3
  int v37; // r2
  volatile int *v38; // r10
  int v39; // t1
  int v40; // r1
  unsigned int v41; // r2
  unsigned int v42; // r3
  int v43; // r8
  int v44; // r4
  int v45; // r7
  volatile int16_t **v46; // r8
  int v47; // r6
  int v48; // r3
  int v49; // r9
  int v50; // r0
  struct __attribute__((packed)) { int v52; // [sp+4h] [bp-38h]
  int v53; // [sp+8h] [bp-34h]
  volatile uint32_t *v54; // [sp+Ch] [bp-30h]
  char _pad3[4]; uint8_t v55[40]; // [sp+14h] [bp-28h] BYREF
  } _frame;
  v2 = a1[17];
  v3 = (volatile int *)off_11AAEC;
  v4 = *(volatile uint16_t *)(v2 + 8);
  v5 = v4 & 1;
  _frame.v52 = *((volatile uint8_t *)off_11AAEC + *(volatile uint8_t *)(v2 + 13));
  if ( (v4 & 1) == 0 )
    return v5;
  v6 = a1[9] & 0x380000;
  v7 = a1;
  if ( v6 == 3670016 )
  {
    ++*(volatile uint8_t *)(dword_11AB04 + 84 * _frame.v52 + 80);
    v29 = init_flow_entry((int)a1, 0);
    v30 = *(volatile uint16_t *)(v2 + 8) << 21;
    v5 = v29;
    *(volatile uint32_t *)a2 = v29;
    if ( v30 < 0 )
    {
      co_list_push_back(*(volatile uint32_t *)(v2 + 340), (volatile uint32_t *)v2);
      return *(volatile uint32_t *)a2;
    }
    return v5;
  }
  if ( v6 != 3145728 )
  {
    v8 = *(volatile uint8_t *)(*(volatile uint32_t *)off_11AAF0 + 1);
LABEL_5:
    *(volatile uint16_t *)(v2 + 8) = 3;
    if ( v8 )
      v9 = v2 + 84;
    else
      v9 = *(volatile uint32_t *)(*(volatile uint32_t *)(v2 + 324) + 76) + 12;
    v5 = v2 + 16;
    *(volatile uint32_t *)a2 = v9;
    return v5;
  }
  *(volatile uint16_t *)(v2 + 8) = v4 & 0xFBFF;
  _frame.v53 = v4 & 0x400;
  if ( (v4 & 0x400) != 0 )
  {
    v13 = _frame.v52;
    v12 = v2;
  }
  else
  {
    v11 = (volatile char *)list_pop(dword_11AAF4 + 8 * _frame.v52);
    v12 = (int)v11;
    if ( !v11 )
    {
      v43 = dword_11AB30;
      goto LABEL_41;
    }
    memcpy(v11, (volatile char *)v2, 0x168u);
    v13 = *((volatile uint8_t *)v3 + *(volatile uint8_t *)(v12 + 13));
  }
  v14 = v7[19];
  v15 = (volatile int16_t **)off_11AB0C;
  ecc_point_mul(v12, v13, (int)_frame.v55);
  v16 = *(volatile uint32_t *)(v14 + 36);
  v17 = v7[9];
  v18 = *((volatile uint16_t *)v7 + 40);
  v7[17] = v12;
  v19 = (volatile int *)*v7;
  *(volatile uint32_t *)(v12 + 268) = (int)(uintptr_t)(v7);
  *(volatile uint32_t *)(v12 + 56) = 0;
  *(volatile uint32_t *)(v12 + 60) = 0;
  v20 = (uint16_t)(((v16 + 3) & 0xFFFC) + 4 * ((v17 >> 9) & 0x3FF) + 4);
  *(volatile uint16_t *)(v12 + 10) = v18;
  *(volatile uint32_t *)(v12 + 64) = 0;
  v21 = 0;
  v22 = v7;
  v23 = 1;
  _frame.v54 = v7;
  while ( 1 )
  {
    v24 = v19[19];
    v25 = v19[9];
    v26 = (uint16_t)(((*(volatile uint32_t *)(v24 + 36) + 3) & 0xFFFC) + 4 * ((v25 >> 9) & 0x3FF) + 4) + v20;
    if ( v26 <= *(volatile uint32_t *)&_frame.v55[4 * v21 + 12] )
      goto LABEL_20;
    if ( _frame.v55[34] > v21 )
      break;
    if ( **v15 < 0 )
    {
      irq_disable_mmio_write(off_11AB00, (int)aTxlAggRecomput, 721);
      v25 = v19[9];
    }
LABEL_20:
    *(volatile uint16_t *)(v12 + 10) += *((volatile uint16_t *)v19 + 40);
    v23 = (uint8_t)(v23 + 1);
    v19[17] = v12;
    if ( (v25 & 0x380000) == 0x380000 )
    {
      v31 = v19[19];
      *(volatile uint32_t *)(v12 + 40) = v26;
      v32 = (volatile int *)off_11AAF0;
      *(volatile uint8_t *)(v31 + 1) = v23;
      v33 = *v32;
      *(volatile uint32_t *)(v12 + 324) = (int)(uintptr_t)(v19);
      v8 = *(volatile uint8_t *)(v33 + 1);
      if ( *(volatile uint8_t *)(v33 + 1) )
        *(volatile uint32_t *)(v24 + 20) = v12 + 84;
      else
        *(volatile uint32_t *)(v24 + 20) = v8;
      v34 = dword_11AB04 + 84 * _frame.v52;
      ++*(volatile uint8_t *)(v34 + 80);
      if ( !_frame.v53 )
      {
        list_remove((void *)(uintptr_t)(v34 + 28), (void *)((volatile int *)v2), (void *)((volatile int *)v12));
        v8 = *(volatile uint8_t *)(*v32 + 1);
      }
      v35 = _frame.v54[18];
      if ( v35 )
      {
        v36 = (volatile int *)(v2 + 272);
        v37 = v35 + 40;
        v38 = (volatile int *)(v2 + 324);
        do
        {
          v39 = *v36++;
          *(volatile uint32_t *)(v37 + 4) = v39;
          v37 += 4;
        }
        while ( v36 != v38 );
      }
      v40 = _frame.v54[19];
      v41 = _frame.v54[9] & 0xFFE7FFFF;
      v42 = *(volatile uint32_t *)(v40 + 68) & 0xFFC7FFFF;
      *(volatile uint32_t *)(v12 + 24) = v40 + 12;
      *(volatile uint32_t *)(v12 + 76) = 0;
      *(volatile uint32_t *)(v12 + 52) = v12 + 272;
      v2 = v12;
      _frame.v54[9] = v41 | 0x280000;
      *(volatile uint32_t *)(v40 + 68) = v42 | 0x280000;
      goto LABEL_5;
    }
    v28 = (volatile int *)*v19;
    if ( **v15 < 0 && !v28 )
      irq_disable_mmio_write((int)aTxdescNull, (int)aTxlAggRecomput, 744);
    v22 = (void *)(v19);
    v20 = v26;
    v19 = v28;
  }
  if ( v23 != 1 && v26 <= *(volatile uint32_t *)&_frame.v55[4 * v21 + 16] )
  {
    v27 = v12 + 4 * v21;
    *(volatile uint32_t *)(v27 + 328) = (int)(uintptr_t)(v22);
    *(volatile uint32_t *)(v27 + 56) = v20;
    v21 = (uint8_t)(v21 + 1);
    goto LABEL_20;
  }
  v7 = _frame.v54;
  if ( _frame.v53 )
  {
    v43 = dword_11AB30;
    wlan_ioctl_handler_3(84 * (uint16_t)_frame.v52 + 28 + dword_11AB30, (volatile uint32_t *)v12);
  }
  else
  {
    v43 = dword_11AB04;
  }
  co_list_push_back(*(volatile uint32_t *)(v12 + 340), (volatile uint32_t *)v12);
LABEL_41:
  v44 = 0;
  v45 = v43 + 84 * _frame.v52;
  v46 = (volatile int16_t **)off_11AB0C;
  v47 = 0;
  while ( 2 )
  {
    v48 = v7[9];
    ++*(volatile uint8_t *)(v45 + 80);
    v49 = v48 & 0x380000;
    v50 = init_flow_entry((int)v7, 0);
    if ( !v50 )
    {
LABEL_45:
      if ( v49 == 3670016 )
        break;
      goto LABEL_46;
    }
    if ( v44 )
    {
      *(volatile uint32_t *)(v44 + 4) = v50;
      v44 = v50;
      goto LABEL_45;
    }
    v44 = v50;
    v47 = v50;
    if ( v49 != 3670016 )
    {
LABEL_46:
      v7 = (volatile uint32_t *)*v7;
      if ( **v46 < 0 && !v7 )
        irq_disable_mmio_write((int)aTxdescNull, (int)aTxlAggReconfig, 3509);
      continue;
    }
    break;
  }
  *(volatile uint32_t *)a2 = v44;
  return v47;
}


