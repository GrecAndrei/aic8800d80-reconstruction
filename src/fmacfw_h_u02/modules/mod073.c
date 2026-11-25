// parse_adv_report_1 @ 0x141b40
int parse_adv_report_1(volatile uint16_t *a1, unsigned int a2, unsigned int a3, volatile int16_t *a4) {
  unsigned int v4; // r5
  int16_t v5; // r6
  volatile int16_t **v6; // r4
  int v7; // r7
  int16_t v8; // r2
  int v9; // r5
  volatile int16_t *v11; // r3
  int v12; // r5
  int result; // r0
  int v14; // r4
  int v15; // nf
  int v16; // r1
  int v17; // r4
  int v18; // r2
  int v19; // r5

  v4 = *a1;
  v5 = *a4;
  v6 = (volatile int16_t **)off_141BF8;
  *((volatile uint8_t *)a4 + 4) = (v4 & 0x40) != 0;
  *((volatile uint8_t *)a4 + 2) = (v4 >> 7) & 7;
  v7 = (v4 >> 10) & 0x1F;
  *((volatile uint8_t *)a4 + 5) = v7;
  v8 = (a3 >> 3) & 6 | v5 | v4 & 0x10 | v4 & 0x20;
  v9 = *(volatile uint32_t *)(a1 + 1);
  v11 = *v6;
  *((volatile uint32_t *)a4 + 7) = *(volatile uint32_t *)(a1 + 3);
  *a4 = v8;
  *((volatile uint32_t *)a4 + 6) = v9;
  v12 = *((volatile uint8_t *)a1 + 10);
  *((volatile uint8_t *)a4 + 7) = v12;
  v14 = (v14 & ~0xFFFFu) | ((uint16_t)(*(volatile uint16_t *)((volatile char *)a1 + 11)) & 0xFFFFu);
  a4[4] = v14;
  *((volatile uint8_t *)a4 + 41) = *((volatile uint8_t *)a1 + 13);
  result = *v11;
  v14 = (uint16_t)v14;
  if ( result < 0 && a2 <= 0xD )
  {
    result = irq_disable_mmio_write(dword_141C08, dword_141C04, 213);
    v14 = (uint16_t)a4[4];
    v7 = (v7 & ~0xFFu) | ((uint8_t)(*((volatile uint8_t *)a4 + 5)) & 0xFFu);
    v8 = *a4;
    v12 = *((volatile uint8_t *)a4 + 7);
  }
  v15 = (v8 & 4) != 0;
  v16 = dword_141C00;
  v17 = v14 << v7;
  v18 = *((volatile uint16_t *)off_141BFC + 14) + 20;
  *((volatile uint32_t *)a4 + 4) = v17;
  if ( v15 )
    v19 = v12 << 10;
  else
    v19 = v12 << 8;
  *((volatile uint32_t *)a4 + 3) = v19;
  *((volatile uint32_t *)a4 + 12) = (unsigned int)(((unsigned int)v16 * (uint64_t)(unsigned int)(v17 * v18)) >> 32) >> 18;
  return result;
}



// get_ll_conn_ctx @ 0x141c0c
int get_ll_conn_ctx(int a1, int a2) {
  int v3; // r5
  int v4; // r0
  int v5; // r2

  v3 = *(volatile uint32_t *)(a1 + 24)
     - 400
     - *(volatile uint32_t *)(a1 + 48) * a2
     - *(volatile uint32_t *)(dword_141C50 + 1320 * *(volatile uint8_t *)(a1 + 47) + 40);
  v4 = rf_delay();
  v5 = *((volatile uint32_t *)off_141C54 + 4);
  *(volatile uint32_t *)(a1 + 56) = dword_141C58;
  return mem_copy_util((void *)(uintptr_t)(a1 + 52), v5 + v3 - v4);
}



// send_rf_cmd @ 0x141c5c
int send_rf_cmd(char a1, int a2) {
  int v4; // r0
  int16_t v5; // r2

  v4 = tx_send_pdu(12290, 13, 12, 8u);
  v5 = *(volatile uint16_t *)(a2 + 8);
  *(volatile uint32_t *)(v4 + 2) = *(volatile uint32_t *)(a2 + 4);
  *(volatile uint16_t *)(v4 + 6) = v5;
  *(volatile uint8_t *)(v4 + 1) = *(volatile uint8_t *)(a2 + 46);
  *(volatile uint8_t *)v4 = a1;
  return (int)(uintptr_t)(rx_process_packet_1(v4));
}



// read_rf_timer @ 0x141c90
int read_rf_timer(int a1) {
  int v1; // r2
  int v3; // r3
  uint64_t v4; // r0
  int v5; // r5
  volatile uint8_t *v6; // r2
  int v7; // r3
  int16_t v8; // r1
  int result; // r0
  int v10; // r1

  v1 = *(volatile uint32_t *)(a1 + 12);
  v3 = *((volatile uint32_t *)off_141CF8 + 4) + 100;
  v4 = *(volatile uint64_t *)(a1 + 24) + *(volatile unsigned int *)(a1 + 16);
  *(volatile uint32_t *)(a1 + 56) = dword_141CFC;
  *(volatile uint64_t *)(a1 + 24) = v4;
  v5 = *(volatile uint8_t *)(a1 + 47);
  mem_copy_util((void *)(uintptr_t)(a1 + 52), v3 + v1);
  v6 = (void *)(uintptr_t)(off_141D04);
  v7 = dword_141D00 + 1320 * v5;
  v8 = *(volatile uint16_t *)a1 | 8;
  result = *(volatile uint32_t *)(v7 + 4) | 0x100;
  *(volatile uint32_t *)(v7 + 4) = result;
  *(volatile uint16_t *)a1 = v8;
  v10 = *(volatile uint8_t *)(a1 + 4);
  ++v6[1];
  if ( !v10 )
  {
    result = *(volatile uint8_t *)(a1 + 47);
    v6[2] |= 1 << result;
  }
  return result;
}



// handle_ll_event @ 0x141d08
volatile uint8_t * handle_ll_event(int a1) {
  int v2; // r5
  int16_t v3; // r3
  int v4; // r2
  volatile uint8_t *result; // r0
  int v6; // r5
  uint64_t v7; // r2
  int i; // r8
  uint64_t v9; // r6
  uint64_t v10; // r0

  v2 = *(volatile uint8_t *)(a1 + 47);
  mem_set_util(a1 + 52);
  v3 = *(volatile uint16_t *)a1;
  v4 = dword_141D8C;
  result = (void *)(uintptr_t)(off_141D90);
  *(volatile uint16_t *)a1 &= ~8u;
  v6 = v4 + 1320 * v2;
  v4 = (v4 & ~0xFFu) | ((uint8_t)(result[1] - 1) & 0xFFu);
  *(volatile uint32_t *)(v6 + 4) &= ~0x100u;
  result[1] = v4;
  if ( (v3 & 0x60) == 0x20 )
  {
    v7 = *(volatile uint64_t *)(a1 + 24);
    for ( i = 1; ; i = (uint8_t)(i + 1) )
    {
      v9 = v7 - *(volatile uint64_t *)(v6 + 40);
      v10 = (v10 & ~0xFFFFFFFFull) | ((uint32_t)(rf_delay()) & 0xFFFFFFFFu);
      if ( v9 >= v10 )
        break;
      v7 = *(volatile uint64_t *)(a1 + 24) + *(volatile unsigned int *)(a1 + 16);
      *(volatile uint64_t *)(a1 + 24) = v7;
    }
    return (volatile uint8_t *)get_ll_conn_ctx(a1, i);
  }
  return result;
}



// update_ll_flags @ 0x141d94
int update_ll_flags(int a1) {
  int16_t v1; // r3
  volatile uint8_t *v3; // r1
  int result; // r0

  v1 = *(volatile uint16_t *)a1;
  if ( (*(volatile uint16_t *)a1 & 8) != 0 )
  {
    v3 = (void *)(uintptr_t)(off_141DD8);
    *(volatile uint16_t *)a1 = v1 | 0x40;
    if ( v3[1] )
    {
      if ( (v1 & 9) == 9 )
        handle_ll_event(a1);
    }
  }
  result = mem_set_util(a1 + 52);
  if ( !*(volatile uint8_t *)(a1 + 4) )
  {
    result = *(volatile uint8_t *)(a1 + 47);
    *((volatile uint8_t *)off_141DD8 + 2) &= ~(1 << result);
  }
  return result;
}



// queue_ipc_msg @ 0x141e00
int queue_ipc_msg(int a1, int a2, int a3, int a4) {
  int v6; // r0
  int v7; // r1
  int v8; // r1
  int16_t v9; // r3
  int v10; // r5
  int16_t v11; // r3
  int v12; // r4
  int v13; // r1
  uint64_t v14; // r2
  int v16; // [sp+Ch] [bp-8h] BYREF

  v6 = acl_rx_setup((int)&v16, a1, a2, 6, *(volatile uint8_t *)(a3 + 2));
  v7 = *(volatile uint32_t *)(v16 + 72) + 108;
  *(volatile uint8_t *)(v7 + v6) = -40;
  v8 = v7 + v6;
  *(volatile uint8_t *)(v8 + 2) = (8 * *(volatile uint8_t *)a3) & 0x30;
  v9 = (a4 != 4) | (uint16_t)(2 * a4) | *(volatile uint16_t *)a3 & 0x10 | *(volatile uint16_t *)a3 & 0x20;
  if ( *(volatile uint8_t *)(a3 + 4) )
    v9 |= 0x40u;
  v10 = *(volatile uint32_t *)(a3 + 24);
  v11 = v9 | (*(volatile uint8_t *)(a3 + 5) << 10) | (*(volatile uint8_t *)(a3 + 2) << 7);
  *(volatile uint32_t *)(v8 + 9) = *(volatile uint32_t *)(a3 + 28);
  *(volatile uint32_t *)(v8 + 5) = v10;
  *(volatile uint16_t *)(v8 + 3) = v11;
  *(volatile uint8_t *)(v8 + 13) = *(volatile uint8_t *)(a3 + 7);
  *(volatile uint16_t *)(v8 + 14) = *(volatile uint16_t *)(a3 + 8);
  *(volatile uint8_t *)(v8 + 16) = *(volatile uint8_t *)(a3 + 41);
  *(volatile uint8_t *)(v8 + 1) = 15;
  v12 = v16;
  v13 = *(volatile uint32_t *)(v16 + 76);
  v14 = (v14 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)((uint16_t)(v6 + 17)) << 32);
  v14 = (v14 & ~0xFFFFFFFFull) | ((uint32_t)(*(volatile uint32_t *)(v13 + 28) - 1 + HIDWORD(v14)) & 0xFFFFFFFFu);
  v14 = (v14 & 0xFFFFFFFFull) | ((uint64_t)(uint32_t)(((uint32_t)(v14 >> 32) & 0xFFFFFFFFu) + (uint32_t)(4))) << 32;;
  *(volatile uint64_t *)(v13 + 32) = v14;
  return sec_check(v12, 3);
}



// get_acl_ctx @ 0x141ea0
int get_acl_ctx(int a1, int a2, char a3) {
  int result; // r0
  uint16_t v5; // r3
  int v6; // r0
  int v7; // r1
  uint64_t v8; // r2
  int v9; // [sp+Ch] [bp-4h] BYREF

  result = acl_rx_setup((int)&v9, dword_141EF4 + 1320 * a1, dword_141EF0 + 696 * a2, 7, 0);
  if ( result )
  {
    v5 = result + 1;
    *(volatile uint8_t *)(*(volatile uint32_t *)(v9 + 72) + result + 108) = a3;
    v6 = v9;
    v7 = *(volatile uint32_t *)(v9 + 76);
    v8 = (v8 & ~0xFFFFFFFFull) | ((uint32_t)(*(volatile uint32_t *)(v7 + 28) - 1 + v5) & 0xFFFFFFFFu);
    v8 = (v8 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(v5 + 4) << 32);
    *(volatile uint64_t *)(v7 + 32) = v8;
    return sec_check(v6, 3);
  }
  return result;
}



// clear_ll_flag @ 0x141ef8
int clear_ll_flag(int a1) {
  int result; // r0
  volatile uint8_t *v3; // r2
  char v4; // r3

  result = update_ll_flags(a1);
  v3 = (void *)(uintptr_t)(off_141F18);
  *(volatile uint16_t *)a1 &= ~1u;
  v4 = *v3 - 1;
  *(volatile uint8_t *)(a1 + 2) = 0;
  *v3 = v4;
  return result;
}



// scan_slot_init @ 0x141f1c
int scan_slot_init(int a1, int a2, int a3) {
  int v3; // r4
  int v4; // r3

  v3 = 0;
  v4 = dword_141F5C;
  do
  {
    if ( (*(volatile uint16_t *)v4 & 1) != 0
      && *(volatile uint8_t *)(v4 + 47) == a2
      && *(volatile uint8_t *)(v4 + 46) == a1
      && *(volatile uint8_t *)(v4 + 2) == a3 )
    {
      return dword_141F5C + 72 * v3;
    }
    ++v3;
    v4 += 72;
  }
  while ( v3 != 8 );
  return 0;
}



// init_runtime_state @ 0x141f60
volatile int *init_runtime_state() {
  volatile int *v0; // r4
  volatile int *v1; // r5
  volatile int *result; // r0

  v0 = (volatile int *)dword_141F8C;
  memset((volatile int *)dword_141F88, 0, 3u);
  v1 = v0 + 144;
  do
  {
    result = memset(v0, 0, 0x48u);
    v0[15] = (int)v0;
    v0 += 18;
  }
  while ( v0 != v1 );
  return result;
}



// bt_data_process @ 0x141f90
unsigned int bt_data_process(unsigned int result) {
  int v1; // r1
  int v2; // r2
  int v3; // r5
  unsigned int v4; // r4
  int v5; // r6
  int v6; // r3
  unsigned int v7; // r3
  int v8; // r6
  unsigned int v9; // r5
  int v10; // r3
  int v11; // r5
  int v12; // r4
  volatile uint8_t *v13; // r1
  char v14; // r3
  int v15; // r9
  int16_t v16; // r8
  unsigned int v17; // r7
  unsigned int v18; // r10
  int v19; // r11
  int v20; // r8
  volatile char *v21; // r8
  unsigned int v22; // r5
  int v23; // r7
  int16_t v24; // r2
  char v25; // r3
  int v26; // r0
  volatile uint16_t *v27; // r3
  char v28; // r12
  char v29; // r0
  int v30; // r4
  volatile char *v31; // r11
  char v32; // r3
  char v33; // r3
  uint64_t v34; // r0
  uint8_t v35; // r0
  uint8_t v36[76]; // [sp+0h] [bp-4Ch] BYREF

  v1 = *(volatile uint8_t *)(result + 7);
  v2 = *(volatile uint8_t *)(result + 8);
  v3 = dword_1421D8;
  v4 = result;
  v5 = v2;
  if ( (v1 != 255 || !*(volatile uint8_t *)(dword_1421D8 + 1320 * v2 + 108))
    && (*(volatile uint32_t *)(dword_1421D8 + 1320 * v2 + 472) & 8) != 0 )
  {
    if ( *(volatile uint8_t *)(result + 12) == 22 )
    {
      v6 = *(volatile uint8_t *)(result + 13);
      result += 12;
      if ( v6 == 6 )
      {
        v15 = *(volatile uint8_t *)(v4 + 17);
        v16 = *(volatile uint16_t *)v4;
        v17 = v4 + 18;
        v18 = *(volatile uint16_t *)(v4 + 18);
        if ( **(volatile int16_t **)off_1421DC < 0 && v2 == 255 )
        {
          result = irq_disable_mmio_write((int)aParamInstNbrIn, (int)aTwtHandleSetup, 637);
          v5 = *(volatile uint8_t *)(v4 + 8);
        }
        if ( (v15 & 0xC) == 0 )
        {
          v19 = (v18 >> 1) & 7;
          v20 = (uint16_t)(v16 - 6);
          if ( v19 == 4 )
          {
            if ( (v18 & 1) == 0 )
            {
              v26 = v3 + 1320 * v5;
              if ( *(volatile uint64_t *)(v26 + 40) )
              {
                v27 = (volatile uint16_t *)dword_1421E0;
                v28 = *(volatile uint8_t *)(v26 + 107);
                v29 = *(volatile uint8_t *)(v4 + 7);
                v30 = v18 & 1;
                do
                {
                  if ( (*v27 & 1) == 0 )
                    v30 = (int)v27;
                  v27 += 36;
                }
                while ( (volatile uint16_t *)(dword_1421E0 + 576) != v27 );
                v31 = (volatile char *)off_1421E4;
                *(volatile uint8_t *)(v30 + 47) = v28;
                v32 = *v31;
                *(volatile uint8_t *)(v30 + 46) = v29;
                *(volatile uint8_t *)(v30 + 2) = v32;
                *(volatile uint8_t *)(v30 + 41) = 0;
                memset((volatile int *)(v30 + 32), 0, 9u);
                v33 = *v31;
                *(volatile int16_t *)v30 = 1;
                *v31 = v33 + 1;
                parse_adv_report_1((void *)(uintptr_t)(v17), v20, v15, (void *)(uintptr_t)(v30));
                send_rf_cmd(4, v30);
                v34 = (v34 & ~0xFFFFFFFFull) | ((uint32_t)(rf_delay()) & 0xFFFFFFFFu);
                v35 = double_cmp(
                        *(volatile uint64_t *)(v30 + 24) - v34 - *(volatile uint64_t *)(v3 + 1320 * v5 + 40),
                        *(volatile unsigned int *)(v30 + 16));
                return get_ll_conn_ctx(v30, v35);
              }
              else
              {
                return get_acl_ctx(*(volatile uint8_t *)(v26 + 107), *(volatile uint8_t *)(v4 + 7), (v18 >> 7) & 7);
              }
            }
          }
          else if ( v19 == 7 )
          {
            parse_adv_report_1((void *)(uintptr_t)(v4 + 18), v20, v15, (void *)(v36));
            return send_rf_cmd((v18 >> 1) & 7, (int)(uintptr_t)(v36));
          }
        }
      }
      else if ( v6 == 7 )
      {
        result = *(volatile uint8_t *)(v4 + 14);
        v7 = (result >> 5) & 3;
        if ( (result & 0x60) == 0 )
        {
          v8 = dword_1421E0;
          if ( (result & 0x80) != 0 )
          {
            v21 = (volatile char *)off_1421E4;
            v22 = (result >> 5) & 3;
            v23 = dword_1421E0 + 576;
            do
            {
              if ( (*(volatile uint16_t *)v8 & 1) != 0
                && *(volatile uint8_t *)(v8 + 46) == *(volatile uint8_t *)(v4 + 7)
                && *(volatile uint8_t *)(v8 + 47) == *(volatile uint8_t *)(v4 + 8) )
              {
                result = update_ll_flags(v8);
                v24 = *(volatile uint16_t *)v8;
                v25 = *v21;
                *(volatile uint8_t *)(v8 + 2) = v22;
                *(volatile uint16_t *)v8 = v24 & 0xFFFE;
                *v21 = v25 - 1;
              }
              v8 += 72;
            }
            while ( v8 != v23 );
          }
          else
          {
            v9 = result & 7;
            result = dword_1421E0;
            while ( (*(volatile uint16_t *)result & 1) == 0
                 || *(volatile uint8_t *)(result + 47) != v2
                 || *(volatile uint8_t *)(result + 46) != v1
                 || *(volatile uint8_t *)(result + 2) != v9 )
            {
              ++v7;
              result += 72;
              if ( v7 == 8 )
                return result;
            }
            v10 = 9 * v7;
            v11 = dword_1421E0 + 8 * v10;
            v12 = 8 * v10;
            update_ll_flags(v11);
            v13 = (void *)(uintptr_t)(off_1421E4);
            v14 = *(volatile uint8_t *)off_1421E4 - 1;
            *(volatile uint16_t *)(v8 + v12) &= ~1u;
            *(volatile uint8_t *)(v11 + 2) = 0;
            *v13 = v14;
            return 0;
          }
        }
      }
    }
    else if ( **(volatile int16_t **)off_1421DC < 0 )
    {
      return irq_disable_mmio_write((int)aFalse, (int)aTwtHandleActio, 828);
    }
  }
  return result;
}


// adv_type_validate @ 0x1421f8
int adv_type_validate(int result, int16_t a2, volatile uint16_t *a3) {
  volatile uint8_t *v3; // r6
  int16_t v4; // r2
  int v5; // r3
  int v6; // r4
  int v7; // r1
  int v8; // r5
  volatile uint32_t *v9; // r5
  volatile uint32_t *v10; // r4
  volatile int16_t *v11; // t1
  int16_t v12; // r3
  int v13; // r3
  uint32_t _0[12]; // [sp+0h] [bp-20h] BYREF

  v3 = (void *)(uintptr_t)(off_14229C);
  if ( (*a3 & 0x300) == 0x300 )
    v4 = a3[15];
  else
    v4 = a3[12];
  if ( *((volatile uint8_t *)off_14229C + 1) )
  {
    if ( (a2 & 0x88) == 0x88 )
    {
      if ( (v4 & 0x10) == 0 )
        return result;
    }
    else if ( (a2 & 0x2000) == 0 )
    {
      return result;
    }
    v5 = dword_1422A0;
    v6 = *(volatile uint8_t *)(result + 116);
    result = *(volatile uint8_t *)(result + 107);
    v7 = dword_1422A0 + 576;
    v8 = 0;
    do
    {
      while ( (*(volatile uint16_t *)v5 & 1) == 0 || *(volatile uint8_t *)(v5 + 47) != result || *(volatile uint8_t *)(v5 + 46) != v6 )
      {
        v5 += 72;
        if ( v5 == v7 )
          goto LABEL_13;
      }
      _0[v8] = v5;
      v5 += 72;
      v8 = (uint8_t)(v8 + 1);
    }
    while ( v5 != v7 );
LABEL_13:
    if ( v8 )
    {
      v9 = &_0[(uint8_t)(v8 - 1)];
      v10 = &_0[-1];
      do
      {
        v11 = (volatile int16_t *)v10[1];
        ++v10;
        result = (int)v11;
        v12 = *v11;
        if ( (*v11 & 8) != 0 )
        {
          v13 = v12 & 9;
          if ( v3[1] )
          {
            if ( v13 == 9 )
              result = (int)handle_ll_event(result);
          }
        }
      }
      while ( v10 != v9 );
    }
  }
  return result;
}



// scan_state_dispatch @ 0x1422a4
int scan_state_dispatch(int a1, volatile uint8_t *a2, int16_t a3, int16_t a4) {
  int v6; // r7
  int v8; // r11
  int v9; // r4
  int v10; // r0
  char v11; // r2
  volatile uint8_t *v12; // r0
  int v14; // r4
  int v15; // r10
  int v16; // r1
  uint8_t v17; // [sp+4h] [bp-8h]
  int v18; // [sp+4h] [bp-8h]

  if ( !*(volatile uint8_t *)off_14236C )
    goto LABEL_7;
  v6 = *a2;
  if ( *a2 )
    goto LABEL_7;
  v8 = a2[3];
  if ( !a2[1] )
  {
    v9 = dword_142370;
    v17 = a2[2];
    v10 = scan_slot_init(*(volatile uint8_t *)(dword_142370 + 1320 * v8 + 116), v8, v17);
    if ( v10 )
    {
      clear_ll_flag(v10);
      v11 = v17;
LABEL_6:
      v6 = (v6 & ~0xFFu) | ((uint8_t)(get_acl_ctx(a2[3], *(volatile uint8_t *)(v9 + 1320 * v8 + 116), v11) == 0) & 0xFFu);
      goto LABEL_8;
    }
LABEL_7:
    v6 = (v6 & ~0xFFu) | ((uint8_t)(1) & 0xFFu);
    goto LABEL_8;
  }
  v14 = dword_142374;
  v15 = dword_142374 + 576;
  v16 = dword_142370 + 1320 * v8;
  do
  {
    if ( (*(volatile uint16_t *)v14 & 1) != 0
      && *(volatile uint8_t *)(v14 + 46) == *(volatile uint8_t *)(v16 + 116)
      && *(volatile uint8_t *)(v14 + 47) == a2[3] )
    {
      v18 = v16;
      v6 = 1;
      clear_ll_flag(v14);
      v16 = v18;
    }
    v14 += 72;
  }
  while ( v14 != v15 );
  if ( v6 )
  {
    v9 = dword_142370;
    v11 = 0x80;
    goto LABEL_6;
  }
LABEL_8:
  v12 = (volatile uint8_t *)tx_send_pdu(12292, a4, a3, 1u);
  *v12 = v6;
  rx_process_packet_1((int)v12);
  return 0;
}



// ll_conn_process @ 0x142378
int ll_conn_process(int a1, volatile uint8_t *a2, int16_t a3, int16_t a4) {
  int v4; // r8
  int v5; // r9
  volatile uint8_t *v6; // r5
  int v10; // r11
  int v11; // r10
  int v12; // r0
  char v13; // r5
  int16_t v14; // r3
  int v15; // r1
  int16_t v16; // r2
  int v17; // r3
  uint8_t v18; // r0
  int v19; // r4
  volatile int *v20; // r0
  uint64_t v22; // r0
  struct __attribute__((packed)) { char v23; // [sp+4h] [bp-50h]
  char _pad1[3]; int v24[2]; // [sp+8h] [bp-4Ch] BYREF
  int16_t v25; // [sp+10h] [bp-44h]
  char _pad3[6]; int v26; // [sp+18h] [bp-3Ch]
  char _pad4[4]; uint64_t v27; // [sp+20h] [bp-34h]
  char _pad5[9]; char v28; // [sp+31h] [bp-23h]
  char _pad6[4]; char v29; // [sp+36h] [bp-1Eh]
  char v30; // [sp+37h] [bp-1Dh]
  } _frame;
  v4 = dword_142488;
  v5 = *a2;
  v6 = (volatile uint8_t *)(dword_142488 + 1320 * v5);
  if ( !v6[108] || v6[106] || *(volatile uint8_t *)off_142484 > 7u )
  {
    v19 = 1;
  }
  else
  {
    v10 = (uint8_t)v6[116];
    v11 = dword_14248C;
    _frame.v23 = v6[106];
    memset(_frame.v24, 0, 0x48u);
    v12 = a2[4];
    v13 = v6[107];
    _frame.v24[0] = (_frame.v24[0] & ~0xFF00u) | (((uint8_t)(*(volatile uint8_t *)off_142484) & 0xFFu) << 8);
    _frame.v30 = v13;
    _frame.v29 = *(volatile uint8_t *)(v11 + 696 * v10 + 35);
    _frame.v28 = _frame.v23;
    v14 = _frame.v24[0];
    if ( v12 )
      v14 = LOWORD(_frame.v24[0]) | 4;
    v15 = *((volatile uint16_t *)a2 + 3);
    _frame.v24[1] = *(volatile uint32_t *)(a2 + 2);
    _frame.v25 = *((volatile uint16_t *)a2 + 3);
    v16 = v14 | 0x30;
    v17 = a2[1];
    v18 = a2[3];
    _frame.v24[0] = (_frame.v24[0] & ~0xFFFFu) | ((uint16_t)(v16) & 0xFFFFu);
    _frame.v26 = v15 << v18;
    if ( (unsigned int)(v17 - 1) <= 1 )
    {
      v22 = (v22 & ~0xFFFFFFFFull) | ((uint32_t)(rf_delay()) & 0xFFFFFFFFu);
      v17 = a2[1];
      _frame.v27 = *(volatile uint64_t *)(v4 + 1320 * v5 + 40) + (unsigned int)dword_142490 + v22;
    }
    v19 = queue_ipc_msg(v4 + 1320 * v5, v11 + 696 * v10, (int)_frame.v24, v17) == 0;
  }
  v20 = (volatile int *)tx_send_pdu(12289, a4, a3, 1u);
  *v20 = v19;
  rx_process_packet_1((int)v20);
  return 0;
}



