// ble_ll_adv_enable @ 0x140430
int ble_ll_adv_enable() {
  if ( rx_rate_field_parse(0xBu) == 1 )
  {
    ll_event_process();
    return 0;
  }
  else
  {
    if ( **(volatile int16_t **)off_140464 < 0 )
      call_shared_handler(dword_14046C, dword_140468, 157);
    return 0;
  }
}



// ble_ll_scan_enable @ 0x140470
int ble_ll_scan_enable() {
  if ( rx_rate_field_parse(0xBu) == 4 )
  {
    ll_event_schedule();
    return 0;
  }
  else
  {
    if ( **(volatile int16_t **)off_1404A4 < 0 )
      call_shared_handler(dword_1404AC, dword_1404A8, 129);
    return 0;
  }
}



// ble_ll_hci_vendor_cmd @ 0x1404b0
int ble_ll_hci_vendor_cmd(int a1, int a2, int a3) {
  int v3; // r3
  int v4; // r4
  volatile uint8_t *v5; // r2
  volatile uint8_t *v6; // r0
  int v7; // t1
  volatile uint8_t *v9; // r2
  volatile uint8_t *v10; // r3
  int v11; // t1

  if ( !a3 )
    return 1;
  v3 = *(volatile uint32_t *)(a3 + 8);
  if ( v3 )
  {
    if ( a1 != 255 )
    {
      if ( v3 > 0 )
      {
        v9 = (volatile uint8_t *)(a3 + 12);
        v10 = &v9[v3];
        while ( 1 )
        {
          v11 = *v9++;
          if ( v11 == a1 )
            break;
          if ( v9 == v10 )
            return 0;
        }
        return 1;
      }
      return 0;
    }
    v4 = *(volatile uint32_t *)(a3 + 20);
LABEL_5:
    if ( v4 > 0 )
    {
      v5 = (volatile uint8_t *)(a3 + 24);
      v6 = &v5[v4];
      while ( 1 )
      {
        v7 = *v5++;
        if ( a2 == v7 )
          break;
        if ( v5 == v6 )
          return 0;
      }
      return 1;
    }
    return 0;
  }
  v4 = *(volatile uint32_t *)(a3 + 20);
  if ( !v4 )
    return 1;
  if ( a1 == 255 )
    goto LABEL_5;
  return *(volatile uint32_t *)(a3 + 8);
}



// ble_ll_adv_chk_active @ 0x140510
BOOL ble_ll_adv_chk_active() {
  int v0; // r5

  v0 = dword_14053C;
  if ( !*(volatile uint32_t *)(dword_14053C + 6472) )
    return 1;
  if ( rx_rate_field_parse(0xBu) == 3 )
    return **(volatile uint32_t **)(v0 + 6472) == 0;
  return 0;
}



// ble_ll_adv_event_start @ 0x140540
volatile uint32_t * ble_ll_adv_event_start(int a1, int a2, int a3, int a4) {
  int v4; // r11
  int v5; // r0
  volatile uint16_t *v8; // r5
  int v9; // r1
  int16_t v10; // r3
  int v11; // r3
  volatile uint8_t *v12; // r1
  int v13; // r10
  int v14; // r3
  volatile uint32_t *result; // r0
  int v16; // r3
  int v17; // r3
  int v18; // r6
  int v19; // r2
  int v20; // r1
  unsigned int v21; // r4
  int v22; // r3
  unsigned int v23; // r5
  int v24; // r2
  int v25; // r5
  uint64_t v26; // kr00_8
  volatile char *v27; // r3
  char v28; // t1
  int16_t v29; // r4
  int16_t v30; // r4
  void *v31; // r0
  int v32; // r2
  unsigned int v33; // r3
  int v34; // r0
  uint16_t v35; // r3
  int v36; // r5
  int v37; // r12
  volatile char *v38; // r2
  volatile char *v39; // r3
  char v40; // t1
  int v41; // r3
  int v42; // r6
  volatile char *v43; // r7
  volatile uint8_t *v44; // r11
  int v45; // r10
  char v46; // r8
  unsigned int v47; // r5
  volatile uint8_t *v48; // r1
  volatile uint8_t *v49; // r0
  int v50; // r2
  unsigned int v51; // r0
  unsigned int v52; // r1
  int v53; // r3
  int v54; // r3
  int v55; // r8
  int v56; // r2
  int v57; // r8
  volatile uint8_t *v58; // r7
  int v59; // r0
  int v60; // r11
  unsigned int i; // r6
  int v62; // [sp+4h] [bp-20h]
  unsigned int v63; // [sp+8h] [bp-1Ch]
  int v64; // [sp+Ch] [bp-18h]
  volatile uint8_t *v65; // [sp+10h] [bp-14h]
  int v66; // [sp+14h] [bp-10h]
  unsigned int v67; // [sp+18h] [bp-Ch]
  int v68; // [sp+1Ch] [bp-8h]

  v4 = a1;
  v5 = *(volatile uint32_t *)(a1 + 72);
  v8 = (volatile uint16_t *)(v5 + 108);
  if ( a2 )
  {
    v17 = dword_140858;
    v18 = dword_14085C;
    *(volatile uint8_t *)(v5 + 109) = 0;
    *(volatile uint8_t *)(v5 + 110) = 0;
    *(volatile uint8_t *)(v5 + 111) = 0;
    *(volatile uint8_t *)(v5 + 108) = -48;
    v19 = dword_140860;
    *(volatile uint16_t *)(v5 + 112) = *(volatile uint16_t *)(696 * *(volatile uint8_t *)(v17 + 6488) + v18);
    *(volatile uint16_t *)(v5 + 114) = *(volatile uint16_t *)(v18 + 696 * *(volatile uint8_t *)(v17 + 6488) + 2);
    *(volatile uint16_t *)(v5 + 116) = *(volatile uint16_t *)(v18 + 696 * *(volatile uint8_t *)(v17 + 6488) + 4);
    *(volatile uint16_t *)(v5 + 118) = *(volatile uint16_t *)(1320 * *(volatile uint8_t *)(v17 + 6489) + v19);
    *(volatile uint16_t *)(v5 + 120) = *(volatile uint16_t *)(v19 + 1320 * *(volatile uint8_t *)(v17 + 6489) + 2);
    *(volatile uint16_t *)(v5 + 122) = *(volatile uint16_t *)(v19 + 1320 * *(volatile uint8_t *)(v17 + 6489) + 4);
    v20 = 1320 * *(volatile uint8_t *)(v17 + 6489);
    if ( *(volatile uint8_t *)(v19 + v20 + 6) == 2 )
    {
      *(volatile uint16_t *)(v5 + 124) = *(volatile uint16_t *)(v20 + v19);
      v9 = 208;
      *(volatile uint16_t *)(v5 + 126) = *(volatile uint16_t *)(v19 + 1320 * *(volatile uint8_t *)(v17 + 6489) + 2);
      *(volatile uint16_t *)(v5 + 128) = *(volatile uint16_t *)(v19 + 1320 * *(volatile uint8_t *)(v17 + 6489) + 4);
    }
    else
    {
      v9 = 208;
      *(volatile uint16_t *)(v5 + 124) = *(volatile uint16_t *)(696 * *(volatile uint8_t *)(v17 + 6488) + v18);
      *(volatile uint16_t *)(v5 + 126) = *(volatile uint16_t *)(v18 + 696 * *(volatile uint8_t *)(v17 + 6488) + 2);
      *(volatile uint16_t *)(v5 + 128) = *(volatile uint16_t *)(v18 + 696 * *(volatile uint8_t *)(v17 + 6488) + 4);
    }
  }
  else
  {
    v9 = *(volatile uint16_t *)(v5 + 108);
  }
  v10 = *((volatile uint16_t *)off_140854 + 254) + 1;
  *((volatile uint16_t *)off_140854 + 254) = v10;
  *(volatile uint16_t *)(v5 + 130) = 16 * v10;
  if ( get_channel_tx_power(v4, v9, 5) == 1 )
  {
    ll_conn_window_calc(v4, v8, 24);
    v24 = *(volatile uint8_t *)(v4 + 51);
    v11 = v24 + 24;
    v64 = v24 + 27;
  }
  else
  {
    v64 = 27;
    v11 = 24;
  }
  v12 = (volatile char *)v8 + v11;
  *((volatile uint8_t *)v8 + v11) = 5;
  v12[1] = 1;
  v12[2] = *(volatile uint8_t *)a4;
  v13 = (int)v8 + v11 + 3;
  if ( a3 )
  {
    v12[3] = 39;
    v12[4] = 3;
    v12[5] = *(volatile uint8_t *)(a4 + 1);
    v12[6] = a3;
    v12[7] = *(volatile uint8_t *)(a4 + 2);
    v14 = v11 + 8;
  }
  else
  {
    v62 = 0;
    v63 = (uint16_t)(512 - v64);
    v66 = v4;
    do
    {
      v21 = (uint16_t)(v63 - 5);
      if ( *(volatile uint8_t *)(a4 + 2) == 5 )
      {
        v32 = *(volatile uint32_t *)off_140ACC;
        if ( *(volatile uint32_t *)off_140ACC )
        {
          if ( v21 <= 0x19 )
            break;
          v33 = (uint16_t)(v63 - 31);
          if ( *(volatile uint8_t *)(a4 + 32) )
          {
            if ( v33 <= 2 )
              break;
            v33 = (uint16_t)(v63 - 34);
          }
          if ( *(volatile uint8_t *)(a4 + 4) )
          {
            if ( v33 <= 3 )
              break;
            v34 = *(volatile uint16_t *)(v32 + 24);
            v35 = v33 - 4;
            v36 = v35;
            if ( *(volatile uint16_t *)(v32 + 24) )
            {
              v55 = *(volatile uint16_t *)(v32 + 26);
              v56 = v32 + 64;
              v57 = v55 - v34;
              v58 = (volatile uint8_t *)(v56 + v34);
              if ( *(volatile uint8_t *)(a4 + 4) == 1 )
              {
                v59 = *(volatile uint8_t *)(v56 + v34);
                v60 = v58[2];
                for ( i = (uint8_t)(v58[1] + 2);
                      !ble_ll_hci_vendor_cmd(v59, v60, a4) || i > 0xD9;
                      i = (uint8_t)(v58[1] + 2) )
                {
                  v57 -= i;
                  v58 += i;
                  if ( !v57 )
                    goto LABEL_90;
                  v59 = *v58;
                }
              }
              if ( v57 )
              {
                if ( v58[1] + 3 >= v36 )
                  break;
              }
              else
              {
LABEL_90:
                if ( **(volatile int16_t **)off_140AD0 < 0 )
                  call_shared_handler(dword_140AE0, dword_140ADC, 1043);
              }
            }
            else if ( v35 <= 0xDu )
            {
              break;
            }
          }
        }
      }
      *(volatile uint8_t *)v13 = 39;
      *(volatile uint8_t *)(v13 + 2) = *(volatile uint8_t *)(a4 + 1);
      *(volatile uint8_t *)(v13 + 3) = 0;
      v22 = *(volatile uint8_t *)(a4 + 2);
      *(volatile uint8_t *)(v13 + 4) = v22;
      if ( v22 == 5 )
      {
        v25 = *(volatile uint32_t *)off_140868;
        ++*(volatile uint32_t *)(a4 + 92);
        v65 = (volatile uint8_t *)(v13 + 5);
        if ( !v25 )
        {
          *(volatile uint8_t *)(v13 + 1) = 3;
          if ( **(volatile int16_t **)off_140AD0 >= 0 )
          {
            v13 += 5;
            v63 = (uint16_t)(v63 - 5);
            v23 = 5;
            goto LABEL_14;
          }
          v23 = 5;
          goto LABEL_73;
        }
        *(volatile uint8_t *)(v13 + 5) = *(volatile uint8_t *)(v25 + 19);
        *(volatile uint8_t *)(v13 + 6) = *(volatile uint8_t *)(v25 + 16);
        v26 = *(volatile uint64_t *)(a4 + 40);
        *(volatile uint16_t *)(v13 + 15) = *(volatile uint16_t *)(a4 + 48);
        *(volatile uint64_t *)(v13 + 7) = v26;
        *(volatile uint8_t *)(v13 + 17) = *(volatile uint8_t *)(v25 + 18);
        *(volatile uint8_t *)(v13 + 18) = rf_cal_code_idx(*(volatile char *)(v25 + 20));
        *(volatile uint8_t *)(v13 + 19) = -1;
        v27 = (volatile char *)(v25 + 6);
        do
        {
          v28 = *v27++;
          v27[v13 + 13 - v25] = v28;
        }
        while ( v27 != (volatile char *)(v25 + 12) );
        *(volatile uint8_t *)(v13 + 26) = *(volatile uint8_t *)(v25 + 17);
        *(volatile uint32_t *)(v13 + 27) = *(volatile uint32_t *)(v25 + 12);
        v29 = 257;
        if ( v63 <= 0x101 )
          v29 = v63;
        v65 = (volatile uint8_t *)(v13 + 31);
        if ( *(volatile uint8_t *)(a4 + 32) )
          v30 = v29 - 34;
        else
          v30 = v29 - 31;
        if ( !*(volatile uint8_t *)(a4 + 4) )
        {
          *(volatile uint16_t *)(v25 + 24) = *(volatile uint16_t *)(v25 + 26);
          goto LABEL_29;
        }
        *v65 = 1;
        v67 = (uint16_t)(v30 - 6);
        v37 = v13 + 33;
        if ( *(volatile uint16_t *)(v25 + 24) <= 0xBu )
        {
          if ( **(volatile int16_t **)off_140AD0 < 0 && (uint16_t)(v30 - 6) <= 0xBu )
            mmio_clear_register(dword_140AD8, dword_140AD4, 1149);
          v38 = (volatile char *)(v25 + 64);
          do
          {
            v39 = v38 - 31;
            v40 = *v38++;
            v39[v13 - v25] = v40;
          }
          while ( v38 != (volatile char *)(v25 + 76) );
          *(volatile uint16_t *)(v25 + 24) = 12;
          v67 = (uint16_t)(v30 - 18);
          v37 = v13 + 45;
        }
        if ( *(volatile uint8_t *)(a4 + 4) == 1 && !*(volatile uint32_t *)(a4 + 8) && !*(volatile uint32_t *)(a4 + 20) )
        {
          *(volatile uint16_t *)(v25 + 24) = *(volatile uint16_t *)(v25 + 26);
          goto LABEL_66;
        }
        v41 = *(volatile uint16_t *)(v25 + 24);
        v42 = (v42 & ~0xFFFFu) | ((uint16_t)(*(volatile uint16_t *)(v25 + 26) - v41) & 0xFFFFu);
        v43 = (volatile char *)(v25 + 64 + v41);
        if ( !(uint16_t)v42 )
          goto LABEL_66;
        v68 = v13;
        v44 = (volatile uint8_t *)v37;
        v45 = v25;
        while ( 1 )
        {
          v46 = *v43;
          v47 = (uint8_t)(v43[1] + 2);
          if ( ble_ll_hci_vendor_cmd((uint8_t)*v43, (uint8_t)v43[2], a4) && v47 <= 0xD9 )
          {
            if ( (uint8_t)v47 > v67 )
            {
LABEL_71:
              v25 = v45;
              v37 = (int)v44;
              v13 = v68;
LABEL_66:
              *(volatile uint8_t *)(v13 + 32) = -2 - (uint8_t)v65 + v37;
              *(volatile uint8_t *)v37 = 2;
              *(volatile uint8_t *)(v37 + 1) = 2;
              v50 = *(volatile uint8_t *)(v25 + 22);
              v51 = *(volatile uint16_t *)(v25 + 24);
              v52 = *(volatile uint16_t *)(v25 + 26);
              v53 = *(volatile uint8_t *)(a4 + 1);
              *(volatile uint8_t *)(v25 + 22) = v50 + 1;
              v54 = v53 | (v50 << 8);
              if ( v51 < v52 )
              {
                *(volatile uint16_t *)(v37 + 2) = ~((unsigned int)~(v54 << 17) >> 17);
                v65 = (volatile uint8_t *)(v37 + 4);
LABEL_30:
                if ( *(volatile uint8_t *)(a4 + 32) )
                {
                  *v65 = -92;
                  v65[1] = 1;
                  v65[2] = ble_ll_adv_chk_active();
                  v65 += 3;
                }
                v23 = (unsigned int)&v65[-v13];
                *(volatile uint8_t *)(v13 + 1) = (uint8_t)v65 - v13 - 2;
                v21 = (uint16_t)(v63 - ((uint16_t)v65 - v13));
                if ( **(volatile int16_t **)off_140864 < 0 && v63 < v23 )
                {
                  v13 = (int)v65;
                  mmio_clear_register(dword_140870, dword_14086C, 1287);
                  v63 = v21;
                  goto LABEL_14;
                }
LABEL_73:
                v13 = (int)v65;
                v63 = v21;
                goto LABEL_14;
              }
              *(volatile uint16_t *)(v37 + 2) = v54;
              v65 = (volatile uint8_t *)(v37 + 4);
LABEL_29:
              v31 = (void *)(uintptr_t)(off_140868);
              *(volatile uint16_t *)(v25 + 4) = 3;
              cmd_handler_c((int)v31, (volatile uint32_t *)v25);
              goto LABEL_30;
            }
            if ( v47 )
            {
              v48 = v44;
              v49 = (volatile uint8_t *)((uintptr_t)(v43) - (uintptr_t)(v44));
              v44 += v47;
              while ( 1 )
              {
                *v48++ = v46;
                if ( v44 == v48 )
                  break;
                v46 = v48[(uint32_t)v49];
              }
            }
            v67 = (uint16_t)(v67 - (uint8_t)v47);
          }
          v42 = (uint16_t)(v42 - (uint8_t)v47);
          v43 += v47;
          *(volatile uint16_t *)(v45 + 24) += (uint8_t)v47;
          if ( !v42 )
            goto LABEL_71;
        }
      }
      *(volatile uint8_t *)(v13 + 1) = 3;
      v63 = (uint16_t)(v63 - 5);
      v13 += 5;
      v23 = 5;
LABEL_14:
      v62 += v23;
    }
    while ( !ble_ll_adv_chk_active() && v21 > 4 );
    v4 = v66;
    if ( **(volatile int16_t **)off_140864 < 0 && !v62 )
      call_shared_handler(dword_140874, dword_14086C, 1298);
    v14 = v62 + v64;
  }
  result = *(volatile uint32_t **)(v4 + 76);
  v16 = v14 + *(volatile uint8_t *)(v4 + 53);
  result[8] = result[7] - 1 + v16;
  result[9] = v16 + 4;
  return result;
}



// ble_ll_adv_sm_check @ 0x140ae4
int ble_ll_adv_sm_check(int result, int a2) {
  int v2; // r6
  unsigned int v3; // r4
  int v4; // r7
  int v5; // r3
  int v7; // r0
  int v8; // r4

  v2 = dword_140B68;
  v3 = *(volatile uint8_t *)(dword_140B68 + 6489);
  if ( v3 <= 3 && *(volatile uint8_t *)(dword_140B68 + 6488) <= 0x1Fu )
  {
    v4 = result;
    v5 = *(volatile uint32_t *)(dword_140B6C + 1320 * v3 + 72);
    v7 = v5 ? *(volatile uint8_t *)(v5 + 4) : *((volatile uint8_t *)off_140B74 + 36);
    result = (int)(uintptr_t)(ke_mutex_guard(v7 != 0, 512));
    v8 = result;
    if ( result )
    {
      *(volatile uint8_t *)(result + 28) = *(volatile uint8_t *)(v2 + 6489);
      *(volatile uint8_t *)(result + 29) = *(volatile uint8_t *)(v2 + 6488);
      *(volatile uint8_t *)(result + 51) = 0;
      *(volatile uint8_t *)(result + 53) = 0;
      if ( !a2 )
      {
        *(volatile uint32_t *)(result + 88) = dword_140B70;
        *(volatile uint32_t *)(result + 92) = result;
      }
      ble_ll_adv_event_start(result, 1, a2, v4);
      return tx_path_status(v8, 3);
    }
  }
  return result;
}



// ble_ll_adv_set_params @ 0x140b78
int ble_ll_adv_set_params(volatile uint16_t *a1, int a2, int a3) {
  int result; // r0
  int v6; // r2
  volatile uint8_t *v7; // r0
  volatile char *v8; // r5
  struct __attribute__((packed)) { uint8_t v9; // [sp+4h] [bp-34h] BYREF
  char v10; // [sp+5h] [bp-33h] BYREF
  } _frame;
  if ( !a3 )
    return 1;
  result = *(volatile uint8_t *)(a3 + 50);
  if ( *(volatile uint8_t *)(a3 + 50)
    || *(volatile uint16_t *)(a3 + 52) == *a1
    && *(volatile uint16_t *)(a3 + 54) == a1[1]
    && *(volatile uint16_t *)(a3 + 56) == a1[2] )
  {
    v6 = *(volatile uint8_t *)(a3 + 58);
    if ( !*(volatile uint8_t *)(a3 + 58) )
      return 1;
    if ( !a2 )
      return 1;
    _frame.v9 = *(volatile uint8_t *)(a2 + 1);
    if ( !_frame.v9 )
      return 0;
    v7 = &_frame.v9;
    v8 = (volatile char *)(&_frame.v9 + _frame.v9);
    do
    {
      v7[1] = v7[a2 + 2 - (uint32_t)&_frame.v9];
      ++v7;
    }
    while ( v7 != (volatile uint8_t *)v8 );
    return _frame.v9 == v6 && !memcmp(a3 + 59, (int)(uintptr_t)(&_frame.v10), v6);
  }
  return result;
}



// ble_ll_adv_reset @ 0x140bec
int ble_ll_adv_reset(int a1, int a2) {
  int v3; // r5
  int v4; // r7
  volatile int *v5; // r0
  uint64_t v6; // r0
  int v7; // r8
  int v8; // r7
  int v9; // r5
  int v10; // r9
  volatile uint32_t *v11; // r1
  int v12; // r2
  int v13; // r3
  int v14; // r3
  int v15; // r2
  volatile char *v16; // r0
  volatile char *v17; // r5
  int v18; // r6
  unsigned int v19; // r2

  if ( a2 )
  {
    v3 = dword_140D88;
    zero_8_bytes((volatile uint32_t *)dword_140D84);
    v4 = v3 + 6336;
    do
    {
      *(volatile uint16_t *)(v3 - 2) = 0;
      v5 = (volatile int *)v3;
      v3 += 528;
      memset(v5, 0, 6u);
    }
    while ( v4 != v3 );
    v6 = (v6 & ~0xFFFFFFFFull) | ((uint32_t)(util_unknown()) & 0xFFFFFFFFu);
    *(volatile uint64_t *)(a1 + 40) = v6;
    *(volatile uint32_t *)(a1 + 96) = 0;
  }
  v7 = dword_140D8C;
  v8 = dword_140D84;
LABEL_6:
  while ( rx_rate_field_parse(0xBu) == 1 )
  {
    v9 = dword_140D8C;
    v10 = dword_140D8C + 6336;
    do
    {
      while ( *(volatile uint16_t *)(v9 + 4) != 1 || !ble_ll_adv_set_params((volatile uint16_t *)(v9 + 6), v9 + 28, a1) )
      {
        v9 += 528;
        if ( v9 == v10 )
          goto LABEL_12;
      }
      v11 = (volatile uint32_t *)v9;
      *(volatile uint16_t *)(v9 + 24) = 0;
      *(volatile uint8_t *)(v9 + 22) = 0;
      *(volatile uint16_t *)(v9 + 4) = 2;
      v9 += 528;
      cmd_handler_a(v8, v11);
    }
    while ( v9 != v10 );
LABEL_12:
    v12 = *(volatile uint8_t *)(a1 + 101);
    v13 = *(volatile uint32_t *)(a1 + 96) + 1;
    *(volatile uint32_t *)(a1 + 96) = v13;
    if ( v13 >= v12 )
    {
      if ( **(volatile int16_t **)off_140D90 < 0 && ble_ll_adv_chk_active() )
      {
        if ( *(volatile uint32_t *)(a1 + 92) )
          mmio_clear_register((int)aRmNoMoreMeasur, (int)aRmProcessBeaco, 1585);
      }
      rx_phy_status_parse(0xBu, 2);
      return ble_ll_adv_sm_check(a1, 0);
    }
    rx_phy_status_parse(0xBu, 3);
    if ( !ble_ll_adv_chk_active() )
      return ble_ll_adv_sm_check(a1, 0);
  }
  rx_phy_status_parse(0xBu, 1);
  v14 = *(volatile uint32_t *)(a1 + 96);
  while ( 1 )
  {
    v16 = rf_channel_freq((volatile char *)*(volatile uint8_t *)(a1 + 100), *(volatile uint8_t *)(v14 + a1 + 102));
    v17 = v16;
    if ( v16 )
    {
      if ( (v16[3] & 2) == 0 )
        break;
    }
    v15 = *(volatile uint8_t *)(a1 + 101);
    v14 = *(volatile uint32_t *)(a1 + 96) + 1;
    *(volatile uint32_t *)(a1 + 96) = v14;
    if ( v14 >= v15 )
      goto LABEL_6;
  }
  v18 = ke_msg_alloc(4096, 4, 11, 376);
  *(volatile uint32_t *)v18 = *(volatile uint32_t *)v17;
  *(volatile uint16_t *)(v18 + 4) = *((volatile uint16_t *)v17 + 2);
  if ( !*(volatile uint8_t *)(a1 + 3) )
    *(volatile uint8_t *)(v18 + 3) |= 1u;
  *(volatile uint8_t *)(v18 + 367) = 1;
  v19 = *(volatile uint8_t *)(a1 + 58);
  *(volatile uint8_t *)(v18 + 252) = v19;
  memcpy((volatile char *)(v18 + 253), (volatile char *)(a1 + 59), v19);
  *(volatile uint8_t *)(v18 + 368) = 1;
  *(volatile uint16_t *)(v18 + 352) = *(volatile uint16_t *)(a1 + 52);
  *(volatile uint16_t *)(v18 + 354) = *(volatile uint16_t *)(a1 + 54);
  *(volatile uint16_t *)(v18 + 356) = *(volatile uint16_t *)(a1 + 56);
  *(volatile uint8_t *)(v18 + 366) = *(volatile uint8_t *)(v7 + 6489);
  *(volatile uint32_t *)(v18 + 372) = *(volatile uint16_t *)(a1 + 48) << 10;
  return (int)ke_msg_send_2(v18);
}


// clear_197750_buffer @ 0x140d9c
int clear_197750_buffer() {
  volatile int *v0; // r4
  int result; // r0

  v0 = (volatile int *)dword_140DC0;
  rx_phy_status_parse(0xBu, 0);
  result = (int)memset(v0, 0, 0x1960u);
  v0[1620] = -1;
  return result;
}


// ll_sched_config @ 0x140dc4
int ll_sched_config(char a1, char a2, char a3, int a4, char a5) {
  int v5; // r4
  int16_t v6; // r6
  int result; // r0
  uint8_t v8[140]; // [sp+0h] [bp-8Ch] BYREF

  v5 = dword_140DF8;
  v8[2] = a5;
  v6 = *(volatile uint16_t *)(dword_140DF8 + 6488);
  *(volatile uint8_t *)(dword_140DF8 + 6488) = a2;
  *(volatile uint8_t *)(v5 + 6489) = a1;
  v8[0] = a3;
  result = ble_ll_adv_sm_check((int)v8, a4);
  *(volatile uint16_t *)(v5 + 6488) = v6;
  return result;
}



