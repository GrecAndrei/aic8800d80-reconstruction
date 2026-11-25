// ble_radio_cfg_write @ 0x1239c4
int ble_radio_cfg_write(int a1, int a2, int a3, int a4) {
  int v4; // r0
  volatile uint32_t *v5; // r5
  volatile uint32_t *v6; // r3
  int v7; // r4
  BOOL v8; // r0
  int v9; // r3

  v4 = ke_msg_alloc(5, a4, a3, 28);
  v5 = (void *)(uintptr_t)(off_123A84);
  *(volatile uint32_t *)v4 = dword_123A88;
  v6 = (void *)(uintptr_t)(off_123A8C);
  *(volatile uint32_t *)(v4 + 4) = *v5;
  *(volatile uint32_t *)(v4 + 8) = *v6;
  *(volatile uint8_t *)(v4 + 26) = 4;
  *(volatile uint16_t *)(v4 + 24) = 32;
  v7 = v4;
  rf_read_timestamps((volatile uint32_t *)(v4 + 12), (volatile uint32_t *)(v4 + 16));
  *(volatile uint32_t *)(v7 + 20) = dword_123A90;
  if ( (*v5 & 0x20000) != 0 && rf_get_status_bit28() )
  {
    *(volatile uint32_t *)(v7 + 20) |= 0x400u;
    if ( (*(volatile uint32_t *)off_123A84 & 0x20000) == 0 )
      goto LABEL_3;
  }
  else if ( (*(volatile uint32_t *)off_123A84 & 0x20000) == 0 )
  {
    goto LABEL_3;
  }
  if ( rf_get_status_bit30() )
    *(volatile uint32_t *)(v7 + 20) |= 0x4000u;
LABEL_3:
  if ( (*(volatile uint32_t *)off_123A84 & 0x2000) != 0 )
    *(volatile uint32_t *)(v7 + 20) |= 0x1000u;
  if ( return_true() )
    *(volatile uint32_t *)(v7 + 20) |= 0x200u;
  if ( (*(volatile uint32_t *)off_123A84 & 0x8000) != 0 && rf_get_status_bit21() )
    *(volatile uint32_t *)(v7 + 20) |= 0x800000u;
  v8 = rf_check_status();
  v9 = *(volatile uint32_t *)(v7 + 20);
  if ( v8 )
    v9 |= 0x80000u;
  *(volatile uint32_t *)(v7 + 20) = v9 | 0x600000;
  ke_msg_send_2(v7);
  return 0;
}



// lld_evt_schedule_next @ 0x123a94
/* luna: Handles the MAC-manager start request by initializing radio and peripheral state, applying request configuration, and conditionally sending a no-param */
int lld_evt_schedule_next(int a1, int a2, unsigned int a3, int a4) {
  volatile int16_t **status_ptr; // r8
  int initial_status; // r0
  struct __attribute__((packed)) { uint16_t a1a[2]; // [sp+4h] [bp-24h] BYREF
  int v11; // [sp+8h] [bp-20h]
  char _pad2[1]; char v12; // [sp+Dh] [bp-1Bh]
  char _pad3[2]; uint32_t v13[6]; // [sp+10h] [bp-18h] BYREF
  } _frame;
  status_ptr = (volatile int16_t **)off_123B64;
  initial_status = **(volatile int16_t **)off_123B64;
  memset((void *)(_frame.v13), 0, sizeof(_frame.v13));
  if ( initial_status < 0 && rx_rate_field_parse(a3) )
    mmio_clear_register((int)aKeStateGetDest, (int)aMmStartReqHand, 337);
  periph_init((volatile int *)a2);
  *(volatile uint32_t *)_frame.a1a = dword_123B4C;
  _frame.v12 = 0;
  _frame.v11 = 2484;
  rf_enable(_frame.a1a, 0);
  util_format(15);
  *((volatile uint16_t *)off_123B50 + 14) = *(volatile uint16_t *)(a2 + 68);
  timer_queue_init((int)_frame.v13);
  if ( **status_ptr < 0 && (uint8_t)a4 > 0xEu )
  {
    mmio_clear_register((int)aIdTaskMax, (int)aKeTaskLocal_2, 183);
    goto LABEL_7;
  }
  if ( (uint8_t)a4 > 0xCu )
LABEL_7:
    ke_msg_send_no_param(3, a4, a3);
  set_clock_divisor();
  read_cal_trim();
  ke_state_set(a3, 2);
  return 0;
}


// lld_evt_schedule_check @ 0x123b68
int lld_evt_schedule_check(int a1, void ( **a2)(int), unsigned int a3) {
  volatile int16_t **v3; // r5
  int result; // r0
  int v7; // r0

  v3 = (volatile int16_t **)off_123BE0;
  if ( **(volatile int16_t **)off_123BE0 < 0 && rx_rate_field_parse(a3) == 4 )
    mmio_clear_register((int)aKeStateGetDest_0, (int)aMmForceIdleReq_0, 1587);
  result = rx_rate_field_parse(a3);
  if ( result )
  {
    if ( result != 2 )
    {
      read_cal_trim();
      ke_state_set(a3, 2);
      return 2;
    }
  }
  else
  {
    if ( **v3 < 0 && *(volatile uint32_t *)off_123BEC << 28 )
      mmio_clear_register((int)aNxmacCurrentSt, (int)aMmForceIdleReq_0, 1594);
    v7 = ke_state_set(a3, 3);
    (*a2)(v7);
    return 0;
  }
  return result;
}


// llc_tx_check_status @ 0x123bf4
int llc_tx_check_status(int a1, volatile uint8_t *a2, unsigned int a3, int a4) {
  int v7; // r2
  volatile uint16_t *v8; // r5
  int result; // r0

  if ( rx_rate_field_parse(a3) == 3 || rx_rate_field_parse(a3) == 4 )
    return 2;
  v7 = *a2;
  v8 = (void *)(uintptr_t)(off_123C78);
  *((volatile uint8_t *)off_123C78 + 31) = v7;
  if ( !v7 )
  {
    if ( rx_rate_field_parse(a3) != 2 )
    {
      set_clock_divisor();
LABEL_6:
      ke_msg_send_no_param(35, a4, a3);
      return 0;
    }
    return 2;
  }
  result = rx_rate_field_parse(a3);
  if ( !result )
  {
    if ( **(volatile int16_t **)off_123C7C < 0 )
    {
      if ( *(volatile uint32_t *)off_123C80 << 28 )
        mmio_clear_register((int)aNxmacCurrentSt, (int)aMmSetIdleReqHa, 1522);
    }
    v8[9] = 0;
    goto LABEL_6;
  }
  if ( result != 2 )
  {
    read_cal_trim();
    ke_state_set(a3, 2);
    return 2;
  }
  return result;
}


// rf_calibration_do @ 0x123c8c
int rf_calibration_do(unsigned int a1, volatile uint8_t *a2, unsigned int a3, int a4) {
  int v8; // r0
  volatile int16_t **v10; // r8
  int v11; // r3
  volatile uint8_t *v12; // r5
  volatile uint8_t *v13; // r7
  int v14; // r6
  uint8_t v15; // r7
  int v16; // r1
  unsigned int v17; // r2
  signed int v18; // r3
  unsigned int v19; // r8
  uint16_t v20; // lr
  int v21; // r2
  int v22; // r3
  uint16_t v23; // r1
  int v24; // r2
  int v25; // r3
  volatile uint8_t *v26; // r0
  int v27; // r11
  int v28; // r10
  int v29; // r9
  int v30; // r0
  int v31; // r2
  int v32; // r1
  int v33; // r7
  volatile unsigned int v34; // r1
  volatile uint32_t *v35; // s16
  volatile uint32_t *v36; // r1
  int v37; // r3
  int v38; // r12
  volatile unsigned int v39; // r0
  int v40; // r3
  volatile uint32_t *v41; // r3
  int v42; // r2
  int v43; // r2
  int v44; // r2
  int v45; // r3
  volatile uint32_t *v46; // r3
  int v47; // r2
  volatile char *v48; // r3
  int v49; // r1
  int v50; // r0
  int v51; // zf
  volatile char *v52; // r5
  int v53; // r2
  unsigned int v54; // r1
  int v55; // r0
  volatile uint32_t *v56; // r2
  int v57; // r0
  int v58; // r6
  int v59; // r2
  unsigned int v60; // r0
  volatile uint8_t *v61; // r6
  volatile int *v62; // r3
  volatile uint8_t *v63; // r2
  int v64; // r3
  int v65; // r1
  volatile uint8_t *v66; // r2
  int v67; // r1
  volatile int *v68; // r3
  volatile uint32_t *v69; // lr
  int v70; // r12
  volatile uint32_t *v71; // r2
  int v72; // r0
  volatile uint32_t *v73; // r3
  volatile uint8_t *v74; // r3
  int v75; // r2
  volatile int *v76; // r3
  int v77; // r0
  int v78; // r7
  volatile int *v79; // r12
  int v80; // r1
  volatile int *v81; // r3
  volatile uint32_t *v82; // r12
  volatile uint32_t *v83; // r2
  int v84; // r0
  int v85; // r3
  volatile uint8_t *v86; // r8
  int v87; // r2
  volatile uint32_t *v88; // r2
  volatile uint32_t *v89; // r0
  int v90; // r1
  volatile uint8_t *v91; // r8
  volatile int *v92; // r0
  volatile int *v93; // r1
  unsigned int v94; // r12
  unsigned int v95; // r3
  volatile uint8_t *v96; // r3
  volatile int *v97; // r12
  unsigned int v98; // r3
  unsigned int v99; // r1
  struct __attribute__((packed)) { union { int v100; // [sp+Ch] [bp-18h]
  volatile int *v101; // [sp+Ch] [bp-18h]
  volatile int *v102; // [sp+Ch] [bp-18h]
  char v103; // [sp+Ch] [bp-18h]
  char v104; }; // [sp+Ch] [bp-18h]
  union { int v105; // [sp+10h] [bp-14h]
  int v106; }; // [sp+10h] [bp-14h]
  union { int v107; // [sp+14h] [bp-10h]
  int v108; }; // [sp+14h] [bp-10h]
  char _pad3[4]; uint8_t a1a[8]; // [sp+1Ch] [bp-8h] BYREF
  } _frame;
  v8 = rx_rate_field_parse(a3);
  if ( !v8 )
  {
    v10 = (volatile int16_t **)off_123F90;
    v11 = **(volatile int16_t **)off_123F90;
    if ( v11 >= 0 )
    {
      if ( a1 <= 0x3B )
      {
        if ( a1 > 5 )
        {
          switch ( a1 )
          {
            case 6u:
              goto LABEL_77;
            case 8u:
              goto LABEL_71;
            case 0xEu:
              goto LABEL_69;
            case 0x10u:
              goto LABEL_67;
            case 0x12u:
              goto LABEL_66;
            case 0x14u:
              goto LABEL_63;
            case 0x16u:
              goto LABEL_53;
            case 0x18u:
              goto LABEL_52;
            case 0x1Cu:
              goto LABEL_76;
            case 0x1Eu:
              goto LABEL_33;
            case 0x20u:
              goto LABEL_32;
            case 0x28u:
              goto LABEL_27;
            case 0x30u:
              goto LABEL_26;
            case 0x3Bu:
              goto LABEL_25;
            default:
              v13 = (void *)(uintptr_t)(off_123F64);
              v14 = 2;
              goto LABEL_10;
          }
        }
        goto LABEL_24;
      }
      if ( a1 == 143 )
      {
LABEL_16:
        v13 = (void *)(uintptr_t)(off_123F64);
        *((volatile uint8_t *)off_123F64 + 48) = 0;
        v14 = util_abs(*(volatile uint32_t *)a2);
        if ( v14 )
        {
          chip_state_handler(*(volatile uint32_t *)a2);
          v14 = 0;
        }
        else if ( v13[49] )
        {
          v13[49] = 0;
if ( llm_adv_param_check((void *)(_frame.a1a)) ) rf_calib_params_get( *(volatile uint8_t *)(*(volatile uint32_t *)_frame.a1a + 1225), dword_123F68 + 38 * *(volatile uint8_t *)(*(volatile uint32_t *)_frame.a1a + 107));
        }
        goto LABEL_10;
      }
LABEL_24:
      v13 = (void *)(uintptr_t)(off_123F64);
      v14 = 2;
      goto LABEL_10;
    }
    if ( !(*(volatile uint32_t *)off_123F60 << 28) )
    {
      if ( a1 > 0x3B )
      {
        if ( a1 == 143 )
          goto LABEL_16;
      }
      else if ( a1 > 5 )
      {
        switch ( a1 )
        {
          case 6u:
            goto LABEL_77;
          case 8u:
            goto LABEL_71;
          case 0xEu:
            goto LABEL_69;
          case 0x10u:
            goto LABEL_67;
          case 0x12u:
            goto LABEL_66;
          case 0x14u:
            goto LABEL_63;
          case 0x16u:
            goto LABEL_53;
          case 0x18u:
            goto LABEL_52;
          case 0x1Cu:
            goto LABEL_76;
          case 0x1Eu:
            goto LABEL_33;
          case 0x20u:
            goto LABEL_32;
          case 0x28u:
            goto LABEL_27;
          case 0x30u:
            goto LABEL_26;
          case 0x3Bu:
            goto LABEL_25;
          default:
            goto LABEL_21;
        }
      }
      goto LABEL_21;
    }
    mmio_clear_register((int)aNxmacCurrentSt, (int)aMmHwConfigHand, 2493);
    if ( a1 > 0x3B )
    {
      if ( a1 == 143 )
        goto LABEL_16;
    }
    else if ( a1 > 5 )
    {
      switch ( a1 )
      {
        case 6u:
LABEL_77:
          v61 = (volatile uint8_t *)ke_msg_alloc(7, a4, a3, 2);
          v13 = (void *)(uintptr_t)(off_1242D4);
          *v61 = task_event_handler((int)(a2 + 2), *a2, a2[8], v61 + 1);
          ke_msg_send_2((int)v61);
          v14 = 0;
          goto LABEL_10;
        case 8u:
LABEL_71:
          v60 = *a2;
          if ( v60 <= 3 )
            get_object_by_index(v60);
          if ( !*((volatile uint32_t *)off_124310 + 2) )
            mmio_disable_bit();
          ke_msg_send_no_param(9, a4, a3);
          v13 = (void *)(uintptr_t)(off_1242D4);
          v14 = 0;
          goto LABEL_10;
        case 0xEu:
          v11 = **v10;
LABEL_69:
          v13 = (void *)(uintptr_t)(off_1242D4);
          v59 = *(volatile uint32_t *)a2;
          *(volatile uint32_t *)off_1242D4 = *(volatile uint32_t *)a2;
          if ( v11 < 0 && *(volatile uint32_t *)off_124634 << 28 )
          {
            call_shared_handler((int)aNxmacCurrentSt, (int)aMmRxFilterSet_4, 472);
            v59 = *(volatile uint32_t *)v13;
          }
          *(volatile uint32_t *)off_12430C = v59 | *((volatile uint32_t *)v13 + 1);
          ke_msg_send_no_param(15, a4, a3);
          v14 = 0;
          goto LABEL_10;
        case 0x10u:
LABEL_67:
          v57 = ke_msg_alloc(17, a4, a3, 2);
          v13 = (void *)(uintptr_t)(off_1242D4);
          v58 = v57;
          rf_enable((volatile uint16_t *)a2, a2[10]);
          ke_msg_send_2(v58);
          v14 = 0;
          goto LABEL_10;
        case 0x12u:
LABEL_66:
          v56 = (void *)(uintptr_t)(off_124308);
          v13 = (void *)(uintptr_t)(off_1242D4);
          *(volatile uint32_t *)off_124308 = *(volatile uint32_t *)off_124308 & 0xFFFFFF00 | *a2;
          *v56 |= 0x80000000;
          ke_msg_send_no_param(19, a4, a3);
          v14 = 0;
          goto LABEL_10;
        case 0x14u:
LABEL_63:
          v54 = *(volatile uint16_t *)a2;
          v55 = dword_124304 + 1320 * a2[2];
          if ( *(volatile uint8_t *)(v55 + 106) )
            set_attribute_word(v55, v54);
          else
            *(volatile uint32_t *)(dword_1242C0 + 696 * *(volatile uint8_t *)(v55 + 116) + 8) = v54 << 10;
          ke_msg_send_no_param(21, a4, a3);
          v13 = (void *)(uintptr_t)(off_1242D4);
          v14 = 0;
          goto LABEL_10;
        case 0x16u:
LABEL_53:
          v48 = *(volatile char **)a2;
          v49 = a2[5];
          v13 = (void *)(uintptr_t)(off_1242D4);
          v50 = *((volatile uint32_t *)off_1242FC + 10);
          v52 = (volatile char *)(*(volatile uint32_t *)a2 & 0xFFFFF1FF);
          v51 = v52 == nullptr;
          v53 = v49 + 4;
          if ( v52 )
            v48 = (volatile char *)off_1242D4 + 4 * v53;
          else
            v52 = (volatile char *)off_1242D4 + 4 * v53;
          if ( v51 )
            *((volatile uint32_t *)v52 + 1) = (int)(uintptr_t)(v48);
          else
            *((volatile uint32_t *)v48 + 1) = (int)(uintptr_t)(v52);
          if ( v50 && *(volatile uint8_t *)(v50 + 4) == v49 )
            *(volatile uint32_t *)off_124300 = *(volatile uint32_t *)&v13[4 * v53 + 4];
          ke_msg_send_no_param(23, a4, a3);
          v14 = 0;
          goto LABEL_10;
        case 0x18u:
LABEL_52:
          v13 = (void *)(uintptr_t)(off_1242D4);
          memcpy((volatile char *)(dword_1242F0 + 1320 * a2[6]), (volatile char *)a2, 6u);
          v46 = (void *)(uintptr_t)(off_1242F8);
          v47 = *((volatile uint16_t *)a2 + 2);
          *(volatile uint32_t *)off_1242F4 = *(volatile uint32_t *)a2;
          *v46 = v47;
          ke_msg_send_no_param(25, a4, a3);
          v14 = 0;
          goto LABEL_10;
        case 0x1Cu:
LABEL_76:
          v13 = (void *)(uintptr_t)(off_1242D4);
          *(volatile uint32_t *)off_124314 = (*a2 << 14) & 0x1C000 | *(volatile uint32_t *)off_124314 & 0xFFFE3FFF;
          ke_msg_send_no_param(29, a4, a3);
          v14 = 0;
          goto LABEL_10;
        case 0x1Eu:
LABEL_33:
          v27 = a2[3];
          v28 = dword_124304;
          v29 = dword_124304 + 1320 * v27;
          _frame.a1a[0] = 0;
          _frame.v105 = 1320 * v27;
          v30 = clear_device_flag(_frame.a1a);
          v31 = *(volatile uint8_t *)(v29 + 106);
          v32 = a2[2];
          *(volatile uint8_t *)(v29 + 108) = v32;
          _frame.v100 = v30;
          if ( !v31 )
          {
            _frame.v107 = *(volatile uint8_t *)(v29 + 116);
            if ( v32 )
            {
              v33 = dword_1242C0 + 696 * *(volatile uint8_t *)(v29 + 116);
              v34 = (*(volatile uint32_t *)0x40501010u);
              v35 = (volatile uint32_t *)(_frame.v105 + 24 + v28);
              unknown_worker(v35, v34 + *(volatile uint32_t *)(v33 + 8));
              *(volatile uint16_t *)(v33 + 32) = *(volatile uint16_t *)a2;
              clear_irq_if_idle();
              check_status_bits(
                256,
                "vif state active:%d,%d,%d,%d\r\n",
                *(volatile uint8_t *)(v33 + 35),
                *(volatile uint16_t *)(v33 + 32),
                *(volatile uint8_t *)(v29 + 1224),
                _frame.v100);
              v36 = (void *)(uintptr_t)(off_1242D0);
              *(volatile uint32_t *)off_1242CC = (uint16_t)*(volatile uint32_t *)off_1242CC | (*(volatile uint16_t *)a2 << 16);
              if ( (*v36 & 0x8000) != 0 && rf_get_status_bit21() && (*(volatile uint32_t *)(v33 + 4) & 0x20) != 0 )
              {
                rf_set_channel(*(volatile uint16_t *)a2);
                check_radio_interrupt();
                check_status_bits(256, aHeEnabled);
                mmio_set_radio_bit();
              }
              v13 = (void *)(uintptr_t)(off_1242D4);
              _frame.v108 = dword_1242C0 + 696 * _frame.v107;
              v37 = v28 + 1320 * v27;
              v38 = *(volatile uint32_t *)(v37 + 4) | 1;
              *(volatile uint16_t *)(_frame.v108 + 30) = (unsigned int)(((unsigned int)dword_124318
                                                    * (uint64_t)(*(volatile uint32_t *)(_frame.v108 + 8)
                                                                       * ((unsigned int)*((volatile uint16_t *)off_1242D4
                                                                                        + 14)
                                                                        + 20))) >> 32) >> 18;
              *(volatile uint16_t *)(v37 + 112) = 0;
              *(volatile uint8_t *)(v37 + 114) = 0;
              *(volatile uint8_t *)(v37 + 148) = 0;
              *(volatile uint8_t *)(v37 + 128) = 0;
              *(volatile uint32_t *)(v37 + 124) = 0;
              *(volatile uint32_t *)(v37 + 4) = v38;
              v39 = (*(volatile uint32_t *)0x40501010u);
              *(volatile uint32_t *)(v37 + 120) = v39;
              _frame.v106 = v37;
              tx_enqueue_frame((int)(uintptr_t)((volatile uint32_t *)v29));
              v40 = *(volatile uint8_t *)(_frame.v106 + 1224);
              if ( *(volatile uint8_t *)(_frame.v106 + 1224) )
              {
                if ( !_frame.v100 )
                  goto LABEL_39;
                v74 = (void *)(uintptr_t)(off_12462C);
                if ( !*((volatile uint32_t *)off_12462C + 8) )
                  goto LABEL_39;
                *((volatile uint32_t *)off_12462C + 8) = 0;
                v74[36] = 0;
                wlc_mmio_clock_enable();
LABEL_120:
                v75 = **v10;
                *((volatile uint32_t *)v13 + 1) |= 0x10u;
                if ( v75 < 0 && *(volatile uint32_t *)off_124978 << 28 )
                  call_shared_handler((int)aNxmacCurrentSt, (int)aMmRxFilterSet_4, 472);
                *(volatile uint32_t *)off_124660 = *(volatile uint32_t *)v13 | *((volatile uint32_t *)v13 + 1);
                v32 = a2[2];
                goto LABEL_40;
              }
              if ( _frame.v100 )
              {
                if ( _frame.v100 != 1 )
                  goto LABEL_39;
                v86 = (void *)(uintptr_t)(off_124954);
                if ( v29 == *((volatile uint32_t *)off_124954 + 8) )
                  goto LABEL_39;
                *((volatile uint32_t *)off_124954 + 8) = v40;
                _frame.v103 = v40;
                fault_handler((int)(uintptr_t)(v35));
                v86[36] = _frame.v103;
                wlc_mmio_clock_enable();
                v32 = a2[2];
              }
              else
              {
                if ( *((volatile uint32_t *)off_1242D8 + 8) )
                {
LABEL_39:
                  v32 = a2[2];
                  goto LABEL_40;
                }
                if ( _frame.a1a[0] )
                {
                  if ( _frame.a1a[0] != 1 )
                    goto LABEL_39;
                  goto LABEL_120;
                }
                v97 = (volatile int *)off_124974;
                v98 = *(volatile uint32_t *)(_frame.v108 + 8);
                v99 = *(volatile uint32_t *)off_124974;
                *((volatile uint32_t *)off_1242D8 + 8) = v29;
                *v97 = (uint16_t)(v98 >> 10) | (HIWORD(v99) << 16);
                fault_handler((int)(uintptr_t)(v35));
                *((volatile uint8_t *)off_124954 + 36) = 0;
                wlc_mmio_regs();
                v32 = a2[2];
              }
            }
            else
            {
              fault_handler((int)(uintptr_t)((volatile uint32_t *)(_frame.v105 + 24 + v28)));
              nullsub_8();
              check_status_bits(256, "vif state inactive:%d,%d\r\n", *(volatile uint8_t *)(v29 + 1224), _frame.v100);
              if ( (*(volatile uint32_t *)off_124654 & 0x8000) != 0
                && rf_get_status_bit21()
                && (*(volatile uint32_t *)(dword_124958 + 696 * _frame.v107 + 4) & 0x20) != 0
                && *(volatile uint8_t *)(v29 + 106) != 4 )
              {
                tx_queue_entry_get(*(volatile uint8_t *)(v29 + 107));
              }
              v64 = v28 + 1320 * v27;
              v65 = *(volatile uint8_t *)(v64 + 1224);
              *(volatile uint8_t *)(v64 + 1227) = 0;
              *(volatile uint32_t *)(v64 + 1228) = 0;
              if ( v65 )
              {
                if ( _frame.v100 )
                {
                  v76 = *((volatile int **)off_124950 + 2);
                  if ( v76 )
                  {
                    while ( *((volatile uint8_t *)v76 + 106)
                         || !*((volatile uint8_t *)v76 + 108)
                         || (volatile int *)v29 == v76
                         || *((volatile uint8_t *)v76 + 1224) )
                    {
                      v76 = (volatile int *)*v76;
                      if ( !v76 )
                        goto LABEL_102;
                    }
                    if ( !*((volatile uint32_t *)off_124954 + 8) )
                    {
                      v77 = *((volatile uint8_t *)v76 + 116);
                      v78 = dword_124958;
                      v79 = (volatile int *)off_124974;
                      *((volatile uint32_t *)off_124954 + 8) = (int)(uintptr_t)(v76);
                      *v79 = (uint16_t)(*(volatile uint32_t *)(v78 + 696 * v77 + 8) >> 10) | (HIWORD(*v79) << 16);
                      _frame.v102 = v76;
                      fault_handler((int)(uintptr_t)(v76 + 6));
                      *((volatile uint8_t *)off_124954 + 36) = 0;
                      v13 = (void *)(uintptr_t)(off_12495C);
                      wlc_mmio_regs();
                      v80 = **v10;
                      v81 = _frame.v102;
                      *((volatile uint32_t *)v13 + 1) &= ~0x10u;
                      if ( v80 < 0 && *(volatile uint32_t *)off_124978 << 28 )
                      {
                        call_shared_handler((int)aNxmacCurrentSt, (int)aMmRxFilterSet_4, 472);
                        v81 = _frame.v102;
                      }
                      v82 = (void *)(uintptr_t)(off_124984);
                      *(volatile uint32_t *)off_124960 = *(volatile uint32_t *)v13 | *((volatile uint32_t *)v13 + 1);
                      v83 = (void *)(uintptr_t)(off_124964);
                      v84 = v81[16];
                      v85 = *((volatile uint16_t *)v81 + 34);
                      *v82 = v84;
                      *v83 = v85;
                      v32 = a2[2];
                      goto LABEL_40;
                    }
                  }
                }
              }
              else if ( _frame.v100 == 2 )
              {
                v91 = (void *)(uintptr_t)(off_124954);
                if ( !*((volatile uint32_t *)off_124954 + 8) )
                {
                  v92 = *((volatile int **)off_124950 + 2);
                  if ( !v92 )
LABEL_170:
                    __und(0xFFu);
                  while ( *((volatile uint8_t *)v92 + 106) || !*((volatile uint8_t *)v92 + 108) || (volatile int *)v29 == v92 || *((volatile uint8_t *)v92 + 1224) )
                  {
                    v92 = (volatile int *)*v92;
                    if ( !v92 )
                      goto LABEL_170;
                  }
                  v93 = (volatile int *)off_124974;
                  _frame.v104 = *((volatile uint8_t *)v92 + 1224);
                  v94 = *(volatile uint32_t *)off_124974;
                  v95 = *(volatile uint32_t *)(dword_124958 + 696 * *((volatile uint8_t *)v92 + 116) + 8);
                  *((volatile uint32_t *)off_124954 + 8) = (int)(uintptr_t)(v92);
                  *v93 = (uint16_t)(v95 >> 10) | (HIWORD(v94) << 16);
                  fault_handler((int)(uintptr_t)(v92 + 6));
                  v91[36] = _frame.v104;
                  v13 = (void *)(uintptr_t)(off_12495C);
                  wlc_mmio_regs();
                  v32 = a2[2];
                  goto LABEL_40;
                }
              }
              else if ( _frame.v100 == 1 )
              {
                v96 = (void *)(uintptr_t)(off_124954);
                if ( v29 == *((volatile uint32_t *)off_124954 + 8) )
                {
                  *((volatile uint32_t *)off_124954 + 8) = 0;
                  v96[36] = 0;
                  v13 = (void *)(uintptr_t)(off_12495C);
                  wlc_mmio_clock_enable();
                  v32 = a2[2];
                  goto LABEL_40;
                }
              }
LABEL_102:
              v32 = a2[2];
              v13 = (void *)(uintptr_t)(off_124630);
            }
LABEL_40:
            llc_get_local_state_idx((volatile uint8_t *)v29, v32);
            if ( a2[2] )
            {
              v41 = *(volatile uint32_t **)off_1242DC;
              v42 = **(volatile uint32_t **)off_1242DC;
              if ( v42 )
                *(volatile uint32_t *)off_1242E0 = v42;
              else
                *(volatile uint32_t *)off_12464C = *(volatile uint32_t *)(v28 + 1320 * v27 + 8);
              v43 = v41[1];
              if ( v43 )
              {
                if ( (v43 & 0xFFF) != 0 )
                  *(volatile uint32_t *)off_124648 = v43;
                else
                  *(volatile uint32_t *)off_1242E4 = v43 & 0xFFFFF000 | *(volatile uint32_t *)(v28 + 1320 * v27 + 12) & 0xFFF;
              }
              else
              {
                *(volatile uint32_t *)off_124648 = *(volatile uint32_t *)(v28 + 1320 * v27 + 12);
              }
              v44 = v41[2];
              if ( v44 )
                *(volatile uint32_t *)off_1242E8 = v44;
              else
                *(volatile uint32_t *)off_124644 = *(volatile uint32_t *)(v28 + 1320 * v27 + 16);
              v45 = v41[3];
              if ( v45 )
                *(volatile uint32_t *)off_1242EC = v45;
              else
                *(volatile uint32_t *)off_124658 = *(volatile uint32_t *)(v28 + 1320 * v27 + 20);
              read_hw_register();
            }
            ke_msg_send_no_param(31, a4, a3);
            v14 = 0;
            goto LABEL_10;
          }
          if ( !v30 )
          {
            if ( v32 )
            {
              v62 = nullptr;
              goto LABEL_85;
            }
LABEL_86:
            v13 = (void *)(uintptr_t)(off_124630);
            goto LABEL_40;
          }
          v62 = *((volatile int **)off_12465C + 2);
          if ( v62 )
          {
            do
            {
              if ( !*((volatile uint8_t *)v62 + 106) && *((volatile uint8_t *)v62 + 108) && (volatile int *)v29 != v62 && !*((volatile uint8_t *)v62 + 1224) )
                break;
              v62 = (volatile int *)*v62;
            }
            while ( v62 );
            if ( !v32 )
            {
              v66 = (void *)(uintptr_t)(off_12462C);
              if ( !*((volatile uint32_t *)off_12462C + 8) && v62 )
              {
                *((volatile uint32_t *)off_12462C + 8) = (int)(uintptr_t)(v62);
                v66[36] = 0;
                _frame.v101 = v62;
                v13 = (void *)(uintptr_t)(off_124630);
                fault_handler((int)(uintptr_t)(v62 + 6));
                wlc_mmio_regs();
                v67 = **v10;
                v68 = _frame.v101;
                *((volatile uint32_t *)v13 + 1) &= ~0x10u;
                if ( v67 < 0 && *(volatile uint32_t *)off_124978 << 28 )
                {
                  call_shared_handler((int)aNxmacCurrentSt, (int)aMmRxFilterSet_4, 472);
                  v68 = _frame.v101;
                }
                v69 = (void *)(uintptr_t)(off_124670);
                v70 = v68[16];
                *(volatile uint32_t *)off_124660 = *(volatile uint32_t *)v13 | *((volatile uint32_t *)v13 + 1);
                v71 = (void *)(uintptr_t)(off_124664);
                v72 = *((volatile uint16_t *)v68 + 34);
                *v69 = v70;
                v73 = (void *)(uintptr_t)(off_124668);
                *v71 = v72;
                *v73 = dword_12466C;
                v71[8212] &= 0xFFFBFFFE;
                goto LABEL_39;
              }
              goto LABEL_86;
            }
          }
          else if ( !v32 )
          {
            goto LABEL_86;
          }
LABEL_85:
          v63 = (void *)(uintptr_t)(off_12462C);
          if ( v62 == *((volatile int **)off_12462C + 8) )
          {
            *((volatile uint32_t *)off_12462C + 8) = 0;
            v63[36] = 0;
            v13 = (void *)(uintptr_t)(off_12495C);
            wlc_mmio_clock_enable();
            v87 = **v10;
            *((volatile uint32_t *)v13 + 1) |= 0x10u;
            if ( v87 < 0 && *(volatile uint32_t *)off_124978 << 28 )
              call_shared_handler((int)aNxmacCurrentSt, (int)aMmRxFilterSet_4, 472);
            v88 = (void *)(uintptr_t)(off_124960);
            v89 = (void *)(uintptr_t)(off_12496C);
            *(volatile uint32_t *)off_124960 = *(volatile uint32_t *)v13 | *((volatile uint32_t *)v13 + 1);
            v90 = dword_124970;
            *v89 = dword_124970;
            v88[8197] |= v90;
            v32 = a2[2];
            goto LABEL_40;
          }
          goto LABEL_86;
        case 0x20u:
LABEL_32:
          v13 = (void *)(uintptr_t)(off_123F64);
          *(volatile uint32_t *)off_123F88 = *a2 | (((uint8_t)*(volatile uint32_t *)off_123F84 * *a2) << 8);
          ke_msg_send_no_param(33, a4, a3);
          v14 = 0;
          goto LABEL_10;
        case 0x28u:
LABEL_27:
          v15 = *a2;
          if ( *a2 )
          {
            if ( tx_desc_release(dword_12463C + 696 * a2[1], a2[2], *((volatile uint16_t *)a2 + 3)) )
            {
              *(volatile uint32_t *)off_124640 |= 0x80u;
              v15 = 0;
            }
            else
            {
              v15 = 4;
            }
          }
          else
          {
            v16 = a2[2];
            v17 = *((volatile uint16_t *)a2 + 2);
            v18 = *(volatile uint32_t *)(dword_123F78 + 4 * *((volatile uint8_t *)off_123F74 + v16));
            if ( (int)v17 >= v18 )
            {
              if ( v17 > 0x40 )
                v19 = (uint16_t)v18;
              else
                v19 = (uint16_t)(v18 / 2);
            }
            else
            {
              v19 = v17 >> 1;
            }
            event_dispatch("mm_ba_add_req_handler %d, %d, %d\n", v16, v17, v19);
            v20 = *((volatile uint16_t *)a2 + 2);
            v21 = 696 * a2[1];
            v22 = *(volatile uint8_t *)(v21 + 12 * a2[2] + dword_123F8C + 453);
            v23 = *((volatile uint16_t *)a2 + 3);
            v24 = v21 + 6 * a2[2] + dword_123F8C;
            v25 = dword_123F80 + 32 * v22;
            *(volatile uint16_t *)(v24 + 354) = v19;
            *(volatile uint16_t *)(v24 + 356) = v20;
            *(volatile uint16_t *)(v25 + 12) = v23;
          }
          v26 = (volatile uint8_t *)ke_msg_alloc(41, a4, a3, 3);
          *v26 = a2[1];
          v26[1] = a2[2];
          v26[2] = v15;
          ke_msg_send_2((int)v26);
          v13 = (void *)(uintptr_t)(off_123F64);
          v14 = 0;
          goto LABEL_10;
        case 0x30u:
LABEL_26:
          bad_func_0x12f4b8();
          v13 = (void *)(uintptr_t)(off_123F64);
          v14 = 0;
          goto LABEL_10;
        case 0x3Bu:
LABEL_25:
          rx_parse_header(a2);
          ke_msg_send_no_param(60, a4, a3);
          v13 = (void *)(uintptr_t)(off_123F64);
          v14 = 0;
          goto LABEL_10;
        default:
          break;
      }
    }
    if ( **v10 >= 0 )
      goto LABEL_24;
LABEL_21:
    v13 = (void *)(uintptr_t)(off_123F64);
    mmio_clear_register(off_123F70, (int)aMmHwConfigHand, 2552);
    v14 = 2;
LABEL_10:
    *(volatile uint32_t *)off_123F60 = (uint8_t)(16 * v13[19]);
    ke_state_set(a3, (uint8_t)v13[18]);
    return v14;
  }
  if ( (uint16_t)(v8 - 2) > 2u )
  {
    v12 = (void *)(uintptr_t)(off_123F64);
    *((volatile uint8_t *)off_123F64 + 19) = *(volatile uint8_t *)off_123F60 & 0xF;
    v12[18] = rx_rate_field_parse(a3);
    read_cal_trim();
    ke_state_set(a3, 2);
  }
  return 2;
}


// ble_mmio_config @ 0x124988
int ble_mmio_config(volatile uint16_t *a1) {
  int v1; // r3
  volatile int *v2; // r2
  int v4; // r0
  volatile int *v5; // r5
  volatile int *v6; // r7
  int v7; // r6
  int v8; // r1
  int v9; // r5
  volatile int *v10; // r0

  v1 = dword_124A10;
  v2 = *(volatile int **)off_124A0C;
  v4 = *a1;
  v5 = (volatile int *)off_124A14;
  v6 = (volatile int *)off_124A18;
  v7 = a1[2];
  *v2 = **(volatile uint32_t **)off_124A0C & dword_124A10 | (v4 << 12);
  *v5 = *v5 & v1 | (v4 << 12);
  v8 = a1[1];
  v2[1] = v2[1] & v1 | (v8 << 12);
  v9 = a1[3];
  *v6 = *v6 & v1 | (v8 << 12);
  v2[2] = v2[2] & v1 | (v7 << 12);
  v10 = (volatile int *)off_124A1C;
  v6[1] = v6[1] & v1 | (v7 << 12);
  v2[3] = v2[3] & v1 | (v9 << 12);
  *v10 = v1 & *v10 | (v9 << 12);
  read_hw_register();
  event_dispatch("set txop: bk:%x,be:%x,vi:%x,vo:%x\n", *a1, a1[1], a1[2], a1[3]);
  return 0;
}


// llc_update_channel_map @ 0x124a24
int llc_update_channel_map(volatile uint8_t *a1) {
  volatile int *v1; // r3
  int v2; // r4
  int v3; // r1
  int v5; // r0
  uint8_t v6; // r2
  int v7; // r1
  volatile uint32_t *v8; // r10
  volatile uint32_t *v9; // r9
  volatile uint32_t *v10; // r8
  int v11; // r11
  volatile uint8_t *v12; // r6
  int v13; // r7
  int i; // r4
  int v15; // r3
  int v16; // t1
  int v17; // r2

  v1 = (volatile int *)off_124B14;
  v2 = a1[16];
  ((volatile uint32_t *)(uintptr_t)off_124B14)[90] = (((volatile uint32_t *)(uintptr_t)off_124B14)[90] & ~0xFFu) | ((uint8_t)(a1[17]) & 0xFFu);
  *((volatile uint8_t *)v1 + 361) = a1[18];
  v3 = a1[21];
  *((volatile uint8_t *)v1 + 356) = v3;
  v5 = a1[22];
  *((volatile uint8_t *)v1 + 357) = v5;
  v6 = a1[23];
  *((volatile uint8_t *)v1 + 358) = v6;
  v7 = v3 + v5;
  *((volatile uint8_t *)v1 + 359) = v6 + v7;
  if ( a1[19] )
    *(volatile uint32_t *)off_124B18 |= 0x10u;
  else
    *(volatile uint32_t *)off_124B18 &= ~0x10u;
  if ( a1[20] )
    *(volatile uint32_t *)off_124B18 |= 2u;
  else
    *(volatile uint32_t *)off_124B18 &= ~2u;
  v8 = (void *)(uintptr_t)(off_124B30);
  v9 = (void *)(uintptr_t)(off_124B34);
  v10 = (void *)(uintptr_t)(off_124B38);
  v11 = 1320 * v2 + 8 + dword_124B1C;
  v12 = a1 - 4;
  v13 = dword_124B1C + 1320 * v2;
  for ( i = 0; i != 4; ++i )
  {
    v16 = *((volatile uint32_t *)v12 + 1);
    v12 += 4;
    v15 = v16;
    v17 = (uint8_t)i;
    if ( v16 )
    {
      *(volatile uint32_t *)(v11 + 4 * i) = v15;
      v7 = *(volatile uint8_t *)(v13 + 108);
      *(volatile uint32_t *)(*(volatile uint32_t *)off_124B20 + 4 * i) = v15;
      if ( v7 )
      {
        if ( i == 1 )
        {
          *v8 = v15;
        }
        else if ( (uint8_t)i == 2 )
        {
          *v9 = v15;
        }
        else if ( (uint8_t)i )
        {
          *v10 = v15;
        }
        else
        {
          *(volatile uint32_t *)off_124B2C = v15;
        }
        read_hw_register();
      }
    }
  }
  if ( a1[24] )
  {
    v17 = off_124B24;
    *(volatile uint32_t *)(uintptr_t)(off_124B24) = a1[24];
  }
  event_dispatch(aSetVendorCa, v7, v17);
  return send_msg((int)a1, 28, 1, 0);
}


// rf_rssi_read @ 0x124b3c
int rf_rssi_read(volatile uint8_t *a1) {
  int v1; // r1
  int v3; // r3
  volatile unsigned int *v4; // r0
  int v5; // r1
  volatile unsigned int *v6; // r0
  int v7; // r1
  volatile unsigned int *v8; // r0

  v1 = *a1;
  v3 = (uint8_t)*(volatile uint32_t *)off_124BFC;
  if ( *a1 )
  {
    v4 = (volatile unsigned int *)off_124C00;
    *(volatile uint32_t *)off_124C00 = *(volatile uint32_t *)off_124C00 & 0xFFFFFF00 | v1;
    *v4 = *v4 & 0xFF0000FF | ((v3 * v1) << 8);
  }
  v5 = a1[1];
  if ( a1[1] )
  {
    v6 = (volatile unsigned int *)off_124C04;
    *(volatile uint32_t *)off_124C04 = *(volatile uint32_t *)off_124C04 & 0xFFFFFF00 | v5;
    *v6 = *v6 & 0xFF0000FF | ((v3 * v5) << 8);
  }
  v7 = a1[2];
  if ( a1[2] )
  {
    v8 = (volatile unsigned int *)off_124C08;
    *(volatile uint32_t *)off_124C08 = *(volatile uint32_t *)off_124C08 & 0xFFFFFF00 | v7;
    *v8 = *v8 & 0xFF0000FF | ((v3 * v7) << 8);
  }
  if ( a1[3] )
    *(volatile uint32_t *)off_124C0C = *(volatile uint32_t *)off_124C0C & 0xFFFFFF00 | a1[3];
  if ( a1[4] )
    *(volatile uint32_t *)off_124C0C = *(volatile uint32_t *)off_124C0C & 0xFFFF00FF | (a1[4] << 8);
  if ( a1[5] )
    *(volatile uint32_t *)off_124C0C = *(volatile uint32_t *)off_124C0C & 0xFF00FFFF | (a1[5] << 16);
  event_dispatch(aSetVendorTs);
  return send_msg((int)a1, 6, 1, 0);
}


// util_get_flag @ 0x124c14
int util_get_flag(volatile uint8_t *a1) {
  int v1; // r3

  v1 = *a1;
  if ( v1 << 28 )
    *(volatile uint8_t *)off_124CA0 = v1 & 1;
  if ( (v1 & 0xF0) != 0 )
    ((volatile uint32_t *)(uintptr_t)off_124CA4)[102] = (((volatile uint32_t *)(uintptr_t)off_124CA4)[102] & ~0xFFu) | ((uint8_t)(v1 & 0x10) & 0xFFu);
  if ( a1[1] )
    *(volatile uint32_t *)off_124CA8 = a1[1] | *(volatile uint32_t *)off_124CA8 & 0xFFFFFF00;
  if ( a1[2] )
    *(volatile uint32_t *)off_124CAC = a1[2] | *(volatile uint32_t *)off_124CAC & 0xFFFFFF00;
  if ( a1[3] )
    *(volatile uint32_t *)off_124CA8 = *(volatile uint32_t *)off_124CA8 & 0xFFF00FFF | (a1[3] << 12);
  if ( a1[4] )
    *(volatile uint32_t *)off_124CAC = *(volatile uint32_t *)off_124CAC & 0xFFF00FFF | (a1[4] << 12);
  event_dispatch(aSetVendorCca);
  return send_msg((int)a1, 5, 1, 0);
}


// hci_event_dispatch @ 0x124cb4
int hci_event_dispatch(int a1, int a2, int a3, int a4) {
  int v6; // r1
  int a3a; // [sp+4h] [bp-4h]
  int a3b; // [sp+4h] [bp-4h]
  int a3c; // [sp+4h] [bp-4h]
  int a3d; // [sp+4h] [bp-4h]
  int a3e; // [sp+4h] [bp-4h]

  switch ( *(volatile uint32_t *)a2 )
  {
    case 0:
      a3a = a3;
      ble_mmio_config((volatile uint16_t *)(a2 + 4));
      a3 = a3a;
      break;
    case 1:
      a3c = a3;
      llc_update_channel_map((volatile uint8_t *)(a2 + 4));
      a3 = a3c;
      break;
    case 2:
      a3d = a3;
      rf_rssi_read((volatile uint8_t *)(a2 + 4));
      a3 = a3d;
      break;
    case 3:
      a3e = a3;
      util_get_flag((volatile uint8_t *)(a2 + 4));
      a3 = a3e;
      break;
    case 6:
      v6 = *(volatile uint8_t *)(a2 + 4);
      a3b = a3;
      *(volatile uint32_t *)(uintptr_t)(off_124D1C) = v6;
      event_dispatch("vendor set ap ps =%d\n", v6);
      a3 = a3b;
      break;
    default:
      break;
  }
  ke_msg_send_no_param(127, a4, a3);
  return 0;
}


// co_time_compare @ 0x124d24
unsigned int co_time_compare(int a1, int a2) {
  return (unsigned int)(*(volatile uint32_t *)(a1 + 12) - *(volatile uint32_t *)(a2 + 12)) >> 31;
}



// get_soc_handle @ 0x124d30
int get_soc_handle() {
  return (int)(uintptr_t)(zero_8_bytes((void *)(uintptr_t)(dword_124D38)));
}



