// peripheral_config @ 0x123bf8
int peripheral_config(int a1, int a2, int a3, int a4) {
  int v4; // r0
  volatile uint32_t *v5; // r5
  volatile uint32_t *v6; // r3
  int v7; // r4
  BOOL v8; // r0
  int v9; // r3

  v4 = bt_buf_alloc(5, a4, a3, 28);
  v5 = (void *)(uintptr_t)(off_123CB8);
  *(volatile uint32_t *)v4 = dword_123CBC;
  v6 = (void *)(uintptr_t)(off_123CC0);
  *(volatile uint32_t *)(v4 + 4) = *v5;
  *(volatile uint32_t *)(v4 + 8) = *v6;
  *(volatile uint8_t *)(v4 + 26) = 4;
  *(volatile uint16_t *)(v4 + 24) = 32;
  v7 = v4;
  sys_status_read((volatile uint32_t *)(v4 + 12), (volatile uint32_t *)(v4 + 16));
  *(volatile uint32_t *)(v7 + 20) = dword_123CC4;
  if ( (*v5 & 0x20000) != 0 && sys_status_get_bit28() )
  {
    *(volatile uint32_t *)(v7 + 20) |= 0x400u;
    if ( (*(volatile uint32_t *)off_123CB8 & 0x20000) == 0 )
      goto LABEL_3;
  }
  else if ( (*(volatile uint32_t *)off_123CB8 & 0x20000) == 0 )
  {
    goto LABEL_3;
  }
  if ( sys_status_get_bit30() )
    *(volatile uint32_t *)(v7 + 20) |= 0x4000u;
LABEL_3:
  if ( (*(volatile uint32_t *)off_123CB8 & 0x2000) != 0 )
    *(volatile uint32_t *)(v7 + 20) |= 0x1000u;
  if ( return_one() )
    *(volatile uint32_t *)(v7 + 20) |= 0x200u;
  if ( (*(volatile uint32_t *)off_123CB8 & 0x8000) != 0 && sys_status_get_bit21() )
    *(volatile uint32_t *)(v7 + 20) |= 0x800000u;
  v8 = rf_calibration_done();
  v9 = *(volatile uint32_t *)(v7 + 20);
  if ( v8 )
    v9 |= 0x80000u;
  *(volatile uint32_t *)(v7 + 20) = v9 | 0x600000;
  hci_evt_send(v7);
  return 0;
}



// read_global_state @ 0x123cc8
int read_global_state(int a1, int a2, unsigned int a3, int a4) {
  volatile int16_t **v4; // r8
  int v5; // r0
  struct __attribute__((packed)) { uint16_t a1a[2]; // [sp+4h] [bp-24h] BYREF
  int v11; // [sp+8h] [bp-20h]
  char _pad2[1]; char v12; // [sp+Dh] [bp-1Bh]
  char _pad3[2]; uint32_t v13[6]; // [sp+10h] [bp-18h] BYREF
  } _frame;
  v4 = (volatile int16_t **)off_123D98;
  v5 = **(volatile int16_t **)off_123D98;
  memset((void *)(_frame.v13), 0, sizeof(_frame.v13));
  if ( v5 < 0 && hci_cmd_send_short(a3) )
    mmio_irq_clear((int)aKeStateGetDest, (int)aMmStartReqHand, 337);
  flash_init((volatile int *)a2);
  *(volatile uint32_t *)_frame.a1a = dword_123D80;
  _frame.v12 = 0;
  _frame.v11 = 2484;
  gpio_init(_frame.a1a, 0);
  util_format_string(15);
  *((volatile uint16_t *)off_123D84 + 14) = *(volatile uint16_t *)(a2 + 68);
  delay_loop((int)_frame.v13);
  if ( **v4 < 0 && (uint8_t)a4 > 0xEu )
  {
    mmio_irq_clear((int)aIdTaskMax, (int)aKeTaskLocal_2, 183);
    goto LABEL_7;
  }
  if ( (uint8_t)a4 > 0xCu )
LABEL_7:
    hci_evt_alloc_send(3, a4, a3);
  write_pmu_control();
  rf_check_clk_state();
  hci_cmd_send(a3, 2);
  return 0;
}


// state_is_valid @ 0x123d9c
int state_is_valid(int a1, void ( **a2)(int), unsigned int a3) {
  volatile int16_t **v3; // r5
  int result; // r0
  int v7; // r0

  v3 = (volatile int16_t **)off_123E14;
  if ( **(volatile int16_t **)off_123E14 < 0 && hci_cmd_send_short(a3) == 4 )
    mmio_irq_clear((int)aKeStateGetDest_0, (int)aMmForceIdleReq_0, 1587);
  result = hci_cmd_send_short(a3);
  if ( result )
  {
    if ( result != 2 )
    {
      rf_check_clk_state();
      hci_cmd_send(a3, 2);
      return 2;
    }
  }
  else
  {
    if ( **v3 < 0 && *(volatile uint32_t *)off_123E20 << 28 )
      mmio_irq_clear((int)aNxmacCurrentSt, (int)aMmForceIdleReq_0, 1594);
    v7 = hci_cmd_send(a3, 3);
    (*a2)(v7);
    return 0;
  }
  return result;
}


// call_common_handler @ 0x123e28
int call_common_handler(int a1, volatile uint8_t *a2, unsigned int a3, int a4) {
  int v7; // r2
  volatile uint16_t *v8; // r5
  int result; // r0

  if ( hci_cmd_send_short(a3) == 3 || hci_cmd_send_short(a3) == 4 )
    return 2;
  v7 = *a2;
  v8 = (void *)(uintptr_t)(off_123EAC);
  *((volatile uint8_t *)off_123EAC + 31) = v7;
  if ( !v7 )
  {
    if ( hci_cmd_send_short(a3) != 2 )
    {
      write_pmu_control();
LABEL_6:
      hci_evt_alloc_send(35, a4, a3);
      return 0;
    }
    return 2;
  }
  result = hci_cmd_send_short(a3);
  if ( !result )
  {
    if ( **(volatile int16_t **)off_123EB0 < 0 )
    {
      if ( *(volatile uint32_t *)off_123EB4 << 28 )
        mmio_irq_clear((int)aNxmacCurrentSt, (int)aMmSetIdleReqHa, 1522);
    }
    v8[9] = 0;
    goto LABEL_6;
  }
  if ( result != 2 )
  {
    rf_check_clk_state();
    hci_cmd_send(a3, 2);
    return 2;
  }
  return result;
}


// process_float_packet @ 0x123ec0
int process_float_packet(unsigned int a1, volatile uint8_t *a2, unsigned int a3, int a4) {
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
  v8 = hci_cmd_send_short(a3);
  if ( !v8 )
  {
    v10 = (volatile int16_t **)off_1241C4;
    v11 = **(volatile int16_t **)off_1241C4;
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
              v13 = (void *)(uintptr_t)(off_124198);
              v14 = 2;
              goto LABEL_10;
          }
        }
        goto LABEL_24;
      }
      if ( a1 == 143 )
      {
LABEL_16:
        v13 = (void *)(uintptr_t)(off_124198);
        *((volatile uint8_t *)off_124198 + 48) = 0;
        v14 = ke_enter_critical(*(volatile uint32_t *)a2);
        if ( v14 )
        {
          mac_check_hw_state(*(volatile uint32_t *)a2);
          v14 = 0;
        }
        else if ( v13[49] )
        {
          v13[49] = 0;
if ( check_bt_addr_valid((void *)(_frame.a1a)) ) bt_conn_read_info( *(volatile uint8_t *)(*(volatile uint32_t *)_frame.a1a + 1225), dword_12419C + 38 * *(volatile uint8_t *)(*(volatile uint32_t *)_frame.a1a + 107));
        }
        goto LABEL_10;
      }
LABEL_24:
      v13 = (void *)(uintptr_t)(off_124198);
      v14 = 2;
      goto LABEL_10;
    }
    if ( !(*(volatile uint32_t *)off_124194 << 28) )
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
    mmio_irq_clear((int)aNxmacCurrentSt, (int)aMmHwConfigHand, 2493);
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
          v61 = (volatile uint8_t *)bt_buf_alloc(7, a4, a3, 2);
          v13 = (void *)(uintptr_t)(off_124508);
          *v61 = wlc_ioctl((int)(a2 + 2), *a2, a2[8], v61 + 1);
          hci_evt_send((int)v61);
          v14 = 0;
          goto LABEL_10;
        case 8u:
LABEL_71:
          v60 = *a2;
          if ( v60 <= 3 )
            wlc_phy_attach(v60);
          if ( !*((volatile uint32_t *)off_124544 + 2) )
            mmio_disable_irq();
          hci_evt_alloc_send(9, a4, a3);
          v13 = (void *)(uintptr_t)(off_124508);
          v14 = 0;
          goto LABEL_10;
        case 0xEu:
          v11 = **v10;
LABEL_69:
          v13 = (void *)(uintptr_t)(off_124508);
          v59 = *(volatile uint32_t *)a2;
          *(volatile uint32_t *)off_124508 = *(volatile uint32_t *)a2;
          if ( v11 < 0 && *(volatile uint32_t *)off_124868 << 28 )
          {
            mmio_field_update((int)aNxmacCurrentSt, (int)aMmRxFilterSet_4, 472);
            v59 = *(volatile uint32_t *)v13;
          }
          *(volatile uint32_t *)off_124540 = v59 | *((volatile uint32_t *)v13 + 1);
          hci_evt_alloc_send(15, a4, a3);
          v14 = 0;
          goto LABEL_10;
        case 0x10u:
LABEL_67:
          v57 = bt_buf_alloc(17, a4, a3, 2);
          v13 = (void *)(uintptr_t)(off_124508);
          v58 = v57;
          gpio_init((volatile uint16_t *)a2, a2[10]);
          hci_evt_send(v58);
          v14 = 0;
          goto LABEL_10;
        case 0x12u:
LABEL_66:
          v56 = (void *)(uintptr_t)(off_12453C);
          v13 = (void *)(uintptr_t)(off_124508);
          *(volatile uint32_t *)off_12453C = *(volatile uint32_t *)off_12453C & 0xFFFFFF00 | *a2;
          *v56 |= 0x80000000;
          hci_evt_alloc_send(19, a4, a3);
          v14 = 0;
          goto LABEL_10;
        case 0x14u:
LABEL_63:
          v54 = *(volatile uint16_t *)a2;
          v55 = dword_124538 + 1320 * a2[2];
          if ( *(volatile uint8_t *)(v55 + 106) )
            wlc_intr_off(v55, v54);
          else
            *(volatile uint32_t *)(dword_1244F4 + 696 * *(volatile uint8_t *)(v55 + 116) + 8) = v54 << 10;
          hci_evt_alloc_send(21, a4, a3);
          v13 = (void *)(uintptr_t)(off_124508);
          v14 = 0;
          goto LABEL_10;
        case 0x16u:
LABEL_53:
          v48 = *(volatile char **)a2;
          v49 = a2[5];
          v13 = (void *)(uintptr_t)(off_124508);
          v50 = *((volatile uint32_t *)off_124530 + 10);
          v52 = (volatile char *)(*(volatile uint32_t *)a2 & 0xFFFFF1FF);
          v51 = v52 == nullptr;
          v53 = v49 + 4;
          if ( v52 )
            v48 = (volatile char *)off_124508 + 4 * v53;
          else
            v52 = (volatile char *)off_124508 + 4 * v53;
          if ( v51 )
            *((volatile uint32_t *)v52 + 1) = (int)(uintptr_t)(v48);
          else
            *((volatile uint32_t *)v48 + 1) = (int)(uintptr_t)(v52);
          if ( v50 && *(volatile uint8_t *)(v50 + 4) == v49 )
            *(volatile uint32_t *)off_124534 = *(volatile uint32_t *)&v13[4 * v53 + 4];
          hci_evt_alloc_send(23, a4, a3);
          v14 = 0;
          goto LABEL_10;
        case 0x18u:
LABEL_52:
          v13 = (void *)(uintptr_t)(off_124508);
          memcpy((volatile char *)(dword_124524 + 1320 * a2[6]), (volatile char *)a2, 6u);
          v46 = (void *)(uintptr_t)(off_12452C);
          v47 = *((volatile uint16_t *)a2 + 2);
          *(volatile uint32_t *)off_124528 = *(volatile uint32_t *)a2;
          *v46 = v47;
          hci_evt_alloc_send(25, a4, a3);
          v14 = 0;
          goto LABEL_10;
        case 0x1Cu:
LABEL_76:
          v13 = (void *)(uintptr_t)(off_124508);
          *(volatile uint32_t *)off_124548 = (*a2 << 14) & 0x1C000 | *(volatile uint32_t *)off_124548 & 0xFFFE3FFF;
          hci_evt_alloc_send(29, a4, a3);
          v14 = 0;
          goto LABEL_10;
        case 0x1Eu:
LABEL_33:
          v27 = a2[3];
          v28 = dword_124538;
          v29 = dword_124538 + 1320 * v27;
          _frame.a1a[0] = 0;
          _frame.v105 = 1320 * v27;
          v30 = reset_event_flag(_frame.a1a);
          v31 = *(volatile uint8_t *)(v29 + 106);
          v32 = a2[2];
          *(volatile uint8_t *)(v29 + 108) = v32;
          _frame.v100 = v30;
          if ( !v31 )
          {
            _frame.v107 = *(volatile uint8_t *)(v29 + 116);
            if ( v32 )
            {
              v33 = dword_1244F4 + 696 * *(volatile uint8_t *)(v29 + 116);
              v34 = (*(volatile uint32_t *)0x40501010u);
              v35 = (volatile uint32_t *)(_frame.v105 + 24 + v28);
              ke_event_lock(v35, v34 + *(volatile uint32_t *)(v33 + 8));
              *(volatile uint16_t *)(v33 + 32) = *(volatile uint16_t *)a2;
              clear_intr_status();
              state_check_feature(
                256,
                "vif state active:%d,%d,%d,%d\r\n",
                *(volatile uint8_t *)(v33 + 35),
                *(volatile uint16_t *)(v33 + 32),
                *(volatile uint8_t *)(v29 + 1224),
                _frame.v100);
              v36 = (void *)(uintptr_t)(off_124504);
              *(volatile uint32_t *)off_124500 = (uint16_t)*(volatile uint32_t *)off_124500 | (*(volatile uint16_t *)a2 << 16);
              if ( (*v36 & 0x8000) != 0 && sys_status_get_bit21() && (*(volatile uint32_t *)(v33 + 4) & 0x20) != 0 )
              {
                rf_channel_set(*(volatile uint16_t *)a2);
                check_hw_status();
                state_check_feature(256, aHeEnabled);
                enable_irq();
              }
              v13 = (void *)(uintptr_t)(off_124508);
              _frame.v108 = dword_1244F4 + 696 * _frame.v107;
              v37 = v28 + 1320 * v27;
              v38 = *(volatile uint32_t *)(v37 + 4) | 1;
              *(volatile uint16_t *)(_frame.v108 + 30) = (unsigned int)(((unsigned int)dword_12454C
                                                    * (uint64_t)(*(volatile uint32_t *)(_frame.v108 + 8)
                                                                       * ((unsigned int)*((volatile uint16_t *)off_124508
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
              bt_power_state((int)(uintptr_t)((volatile uint32_t *)v29));
              v40 = *(volatile uint8_t *)(_frame.v106 + 1224);
              if ( *(volatile uint8_t *)(_frame.v106 + 1224) )
              {
                if ( !_frame.v100 )
                  goto LABEL_39;
                v74 = (void *)(uintptr_t)(off_124860);
                if ( !*((volatile uint32_t *)off_124860 + 8) )
                  goto LABEL_39;
                *((volatile uint32_t *)off_124860 + 8) = 0;
                v74[36] = 0;
                set_reg_bit();
LABEL_120:
                v75 = **v10;
                *((volatile uint32_t *)v13 + 1) |= 0x10u;
                if ( v75 < 0 && *(volatile uint32_t *)off_124BAC << 28 )
                  mmio_field_update((int)aNxmacCurrentSt, (int)aMmRxFilterSet_4, 472);
                *(volatile uint32_t *)off_124894 = *(volatile uint32_t *)v13 | *((volatile uint32_t *)v13 + 1);
                v32 = a2[2];
                goto LABEL_40;
              }
              if ( _frame.v100 )
              {
                if ( _frame.v100 != 1 )
                  goto LABEL_39;
                v86 = (void *)(uintptr_t)(off_124B88);
                if ( v29 == *((volatile uint32_t *)off_124B88 + 8) )
                  goto LABEL_39;
                *((volatile uint32_t *)off_124B88 + 8) = v40;
                _frame.v103 = v40;
                ke_event_set_lock((int)(uintptr_t)(v35));
                v86[36] = _frame.v103;
                set_reg_bit();
                v32 = a2[2];
              }
              else
              {
                if ( *((volatile uint32_t *)off_12450C + 8) )
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
                v97 = (volatile int *)off_124BA8;
                v98 = *(volatile uint32_t *)(_frame.v108 + 8);
                v99 = *(volatile uint32_t *)off_124BA8;
                *((volatile uint32_t *)off_12450C + 8) = v29;
                *v97 = (uint16_t)(v98 >> 10) | (HIWORD(v99) << 16);
                ke_event_set_lock((int)(uintptr_t)(v35));
                *((volatile uint8_t *)off_124B88 + 36) = 0;
                ke_evt_wait();
                v32 = a2[2];
              }
            }
            else
            {
              ke_event_set_lock((int)(uintptr_t)((volatile uint32_t *)(_frame.v105 + 24 + v28)));
              nullsub_8();
              state_check_feature(256, "vif state inactive:%d,%d\r\n", *(volatile uint8_t *)(v29 + 1224), _frame.v100);
              if ( (*(volatile uint32_t *)off_124888 & 0x8000) != 0
                && sys_status_get_bit21()
                && (*(volatile uint32_t *)(dword_124B8C + 696 * _frame.v107 + 4) & 0x20) != 0
                && *(volatile uint8_t *)(v29 + 106) != 4 )
              {
                tx_slot_state_get(*(volatile uint8_t *)(v29 + 107));
              }
              v64 = v28 + 1320 * v27;
              v65 = *(volatile uint8_t *)(v64 + 1224);
              *(volatile uint8_t *)(v64 + 1227) = 0;
              *(volatile uint32_t *)(v64 + 1228) = 0;
              if ( v65 )
              {
                if ( _frame.v100 )
                {
                  v76 = *((volatile int **)off_124B84 + 2);
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
                    if ( !*((volatile uint32_t *)off_124B88 + 8) )
                    {
                      v77 = *((volatile uint8_t *)v76 + 116);
                      v78 = dword_124B8C;
                      v79 = (volatile int *)off_124BA8;
                      *((volatile uint32_t *)off_124B88 + 8) = (int)(uintptr_t)(v76);
                      *v79 = (uint16_t)(*(volatile uint32_t *)(v78 + 696 * v77 + 8) >> 10) | (HIWORD(*v79) << 16);
                      _frame.v102 = v76;
                      ke_event_set_lock((int)(uintptr_t)(v76 + 6));
                      *((volatile uint8_t *)off_124B88 + 36) = 0;
                      v13 = (void *)(uintptr_t)(off_124B90);
                      ke_evt_wait();
                      v80 = **v10;
                      v81 = _frame.v102;
                      *((volatile uint32_t *)v13 + 1) &= ~0x10u;
                      if ( v80 < 0 && *(volatile uint32_t *)off_124BAC << 28 )
                      {
                        mmio_field_update((int)aNxmacCurrentSt, (int)aMmRxFilterSet_4, 472);
                        v81 = _frame.v102;
                      }
                      v82 = (void *)(uintptr_t)(off_124BB8);
                      *(volatile uint32_t *)off_124B94 = *(volatile uint32_t *)v13 | *((volatile uint32_t *)v13 + 1);
                      v83 = (void *)(uintptr_t)(off_124B98);
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
                v91 = (void *)(uintptr_t)(off_124B88);
                if ( !*((volatile uint32_t *)off_124B88 + 8) )
                {
                  v92 = *((volatile int **)off_124B84 + 2);
                  if ( !v92 )
LABEL_170:
                    __und(0xFFu);
                  while ( *((volatile uint8_t *)v92 + 106) || !*((volatile uint8_t *)v92 + 108) || (volatile int *)v29 == v92 || *((volatile uint8_t *)v92 + 1224) )
                  {
                    v92 = (volatile int *)*v92;
                    if ( !v92 )
                      goto LABEL_170;
                  }
                  v93 = (volatile int *)off_124BA8;
                  _frame.v104 = *((volatile uint8_t *)v92 + 1224);
                  v94 = *(volatile uint32_t *)off_124BA8;
                  v95 = *(volatile uint32_t *)(dword_124B8C + 696 * *((volatile uint8_t *)v92 + 116) + 8);
                  *((volatile uint32_t *)off_124B88 + 8) = (int)(uintptr_t)(v92);
                  *v93 = (uint16_t)(v95 >> 10) | (HIWORD(v94) << 16);
                  ke_event_set_lock((int)(uintptr_t)(v92 + 6));
                  v91[36] = _frame.v104;
                  v13 = (void *)(uintptr_t)(off_124B90);
                  ke_evt_wait();
                  v32 = a2[2];
                  goto LABEL_40;
                }
              }
              else if ( _frame.v100 == 1 )
              {
                v96 = (void *)(uintptr_t)(off_124B88);
                if ( v29 == *((volatile uint32_t *)off_124B88 + 8) )
                {
                  *((volatile uint32_t *)off_124B88 + 8) = 0;
                  v96[36] = 0;
                  v13 = (void *)(uintptr_t)(off_124B90);
                  set_reg_bit();
                  v32 = a2[2];
                  goto LABEL_40;
                }
              }
LABEL_102:
              v32 = a2[2];
              v13 = (void *)(uintptr_t)(off_124864);
            }
LABEL_40:
            rx_frame_process((volatile uint8_t *)v29, v32);
            if ( a2[2] )
            {
              v41 = *(volatile uint32_t **)off_124510;
              v42 = **(volatile uint32_t **)off_124510;
              if ( v42 )
                *(volatile uint32_t *)off_124514 = v42;
              else
                *(volatile uint32_t *)off_124880 = *(volatile uint32_t *)(v28 + 1320 * v27 + 8);
              v43 = v41[1];
              if ( v43 )
              {
                if ( (v43 & 0xFFF) != 0 )
                  *(volatile uint32_t *)off_12487C = v43;
                else
                  *(volatile uint32_t *)off_124518 = v43 & 0xFFFFF000 | *(volatile uint32_t *)(v28 + 1320 * v27 + 12) & 0xFFF;
              }
              else
              {
                *(volatile uint32_t *)off_12487C = *(volatile uint32_t *)(v28 + 1320 * v27 + 12);
              }
              v44 = v41[2];
              if ( v44 )
                *(volatile uint32_t *)off_12451C = v44;
              else
                *(volatile uint32_t *)off_124878 = *(volatile uint32_t *)(v28 + 1320 * v27 + 16);
              v45 = v41[3];
              if ( v45 )
                *(volatile uint32_t *)off_124520 = v45;
              else
                *(volatile uint32_t *)off_12488C = *(volatile uint32_t *)(v28 + 1320 * v27 + 20);
              wait_rf_calibration();
            }
            hci_evt_alloc_send(31, a4, a3);
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
            v13 = (void *)(uintptr_t)(off_124864);
            goto LABEL_40;
          }
          v62 = *((volatile int **)off_124890 + 2);
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
              v66 = (void *)(uintptr_t)(off_124860);
              if ( !*((volatile uint32_t *)off_124860 + 8) && v62 )
              {
                *((volatile uint32_t *)off_124860 + 8) = (int)(uintptr_t)(v62);
                v66[36] = 0;
                _frame.v101 = v62;
                v13 = (void *)(uintptr_t)(off_124864);
                ke_event_set_lock((int)(uintptr_t)(v62 + 6));
                ke_evt_wait();
                v67 = **v10;
                v68 = _frame.v101;
                *((volatile uint32_t *)v13 + 1) &= ~0x10u;
                if ( v67 < 0 && *(volatile uint32_t *)off_124BAC << 28 )
                {
                  mmio_field_update((int)aNxmacCurrentSt, (int)aMmRxFilterSet_4, 472);
                  v68 = _frame.v101;
                }
                v69 = (void *)(uintptr_t)(off_1248A4);
                v70 = v68[16];
                *(volatile uint32_t *)off_124894 = *(volatile uint32_t *)v13 | *((volatile uint32_t *)v13 + 1);
                v71 = (void *)(uintptr_t)(off_124898);
                v72 = *((volatile uint16_t *)v68 + 34);
                *v69 = v70;
                v73 = (void *)(uintptr_t)(off_12489C);
                *v71 = v72;
                *v73 = dword_1248A0;
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
          v63 = (void *)(uintptr_t)(off_124860);
          if ( v62 == *((volatile int **)off_124860 + 8) )
          {
            *((volatile uint32_t *)off_124860 + 8) = 0;
            v63[36] = 0;
            v13 = (void *)(uintptr_t)(off_124B90);
            set_reg_bit();
            v87 = **v10;
            *((volatile uint32_t *)v13 + 1) |= 0x10u;
            if ( v87 < 0 && *(volatile uint32_t *)off_124BAC << 28 )
              mmio_field_update((int)aNxmacCurrentSt, (int)aMmRxFilterSet_4, 472);
            v88 = (void *)(uintptr_t)(off_124B94);
            v89 = (void *)(uintptr_t)(off_124BA0);
            *(volatile uint32_t *)off_124B94 = *(volatile uint32_t *)v13 | *((volatile uint32_t *)v13 + 1);
            v90 = dword_124BA4;
            *v89 = dword_124BA4;
            v88[8197] |= v90;
            v32 = a2[2];
            goto LABEL_40;
          }
          goto LABEL_86;
        case 0x20u:
LABEL_32:
          v13 = (void *)(uintptr_t)(off_124198);
          *(volatile uint32_t *)off_1241BC = *a2 | (((uint8_t)*(volatile uint32_t *)off_1241B8 * *a2) << 8);
          hci_evt_alloc_send(33, a4, a3);
          v14 = 0;
          goto LABEL_10;
        case 0x28u:
LABEL_27:
          v15 = *a2;
          if ( *a2 )
          {
            if ( get_instance_handle(dword_124870 + 696 * a2[1], a2[2], *((volatile uint16_t *)a2 + 3)) )
            {
              *(volatile uint32_t *)off_124874 |= 0x80u;
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
            v18 = *(volatile uint32_t *)(dword_1241AC + 4 * *((volatile uint8_t *)off_1241A8 + v16));
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
            ke_event_schedule_1("mm_ba_add_req_handler %d, %d, %d\n", v16, v17, v19);
            v20 = *((volatile uint16_t *)a2 + 2);
            v21 = 696 * a2[1];
            v22 = *(volatile uint8_t *)(v21 + 12 * a2[2] + dword_1241C0 + 453);
            v23 = *((volatile uint16_t *)a2 + 3);
            v24 = v21 + 6 * a2[2] + dword_1241C0;
            v25 = dword_1241B4 + 32 * v22;
            *(volatile uint16_t *)(v24 + 354) = v19;
            *(volatile uint16_t *)(v24 + 356) = v20;
            *(volatile uint16_t *)(v25 + 12) = v23;
          }
          v26 = (volatile uint8_t *)bt_buf_alloc(41, a4, a3, 3);
          *v26 = a2[1];
          v26[1] = a2[2];
          v26[2] = v15;
          hci_evt_send((int)v26);
          v13 = (void *)(uintptr_t)(off_124198);
          v14 = 0;
          goto LABEL_10;
        case 0x30u:
LABEL_26:
          ke_int_unlock();
          v13 = (void *)(uintptr_t)(off_124198);
          v14 = 0;
          goto LABEL_10;
        case 0x3Bu:
LABEL_25:
          tx_packet_start(a2);
          hci_evt_alloc_send(60, a4, a3);
          v13 = (void *)(uintptr_t)(off_124198);
          v14 = 0;
          goto LABEL_10;
        default:
          break;
      }
    }
    if ( **v10 >= 0 )
      goto LABEL_24;
LABEL_21:
    v13 = (void *)(uintptr_t)(off_124198);
    mmio_irq_clear(off_1241A4, (int)aMmHwConfigHand, 2552);
    v14 = 2;
LABEL_10:
    *(volatile uint32_t *)off_124194 = (uint8_t)(16 * v13[19]);
    hci_cmd_send(a3, (uint8_t)v13[18]);
    return v14;
  }
  if ( (uint16_t)(v8 - 2) > 2u )
  {
    v12 = (void *)(uintptr_t)(off_124198);
    *((volatile uint8_t *)off_124198 + 19) = *(volatile uint8_t *)off_124194 & 0xF;
    v12[18] = hci_cmd_send_short(a3);
    rf_check_clk_state();
    hci_cmd_send(a3, 2);
  }
  return 2;
}


// radio_reg_init @ 0x124bbc
int radio_reg_init(volatile uint16_t *a1) {
  int v1; // r3
  volatile int *v2; // r2
  int v4; // r0
  volatile int *v5; // r5
  volatile int *v6; // r7
  int v7; // r6
  int v8; // r1
  int v9; // r5
  volatile int *v10; // r0

  v1 = dword_124C44;
  v2 = *(volatile int **)off_124C40;
  v4 = *a1;
  v5 = (volatile int *)off_124C48;
  v6 = (volatile int *)off_124C4C;
  v7 = a1[2];
  *v2 = **(volatile uint32_t **)off_124C40 & dword_124C44 | (v4 << 12);
  *v5 = *v5 & v1 | (v4 << 12);
  v8 = a1[1];
  v2[1] = v2[1] & v1 | (v8 << 12);
  v9 = a1[3];
  *v6 = *v6 & v1 | (v8 << 12);
  v2[2] = v2[2] & v1 | (v7 << 12);
  v10 = (volatile int *)off_124C50;
  v6[1] = v6[1] & v1 | (v7 << 12);
  v2[3] = v2[3] & v1 | (v9 << 12);
  *v10 = v1 & *v10 | (v9 << 12);
  wait_rf_calibration();
  ke_event_schedule_1("set txop: bk:%x,be:%x,vi:%x,vo:%x\n", *a1, a1[1], a1[2], a1[3]);
  return 0;
}


// ble_store_adv_data @ 0x124c58
int ble_store_adv_data(volatile uint8_t *a1) {
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

  v1 = (volatile int *)off_124D48;
  v2 = a1[16];
  ((volatile uint32_t *)(uintptr_t)off_124D48)[90] = (((volatile uint32_t *)(uintptr_t)off_124D48)[90] & ~0xFFu) | ((uint8_t)(a1[17]) & 0xFFu);
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
    *(volatile uint32_t *)off_124D4C |= 0x10u;
  else
    *(volatile uint32_t *)off_124D4C &= ~0x10u;
  if ( a1[20] )
    *(volatile uint32_t *)off_124D4C |= 2u;
  else
    *(volatile uint32_t *)off_124D4C &= ~2u;
  v8 = (void *)(uintptr_t)(off_124D64);
  v9 = (void *)(uintptr_t)(off_124D68);
  v10 = (void *)(uintptr_t)(off_124D6C);
  v11 = 1320 * v2 + 8 + dword_124D50;
  v12 = a1 - 4;
  v13 = dword_124D50 + 1320 * v2;
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
      *(volatile uint32_t *)(*(volatile uint32_t *)off_124D54 + 4 * i) = v15;
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
          *(volatile uint32_t *)off_124D60 = v15;
        }
        wait_rf_calibration();
      }
    }
  }
  if ( a1[24] )
  {
    v17 = off_124D58;
    *(volatile uint32_t *)(uintptr_t)(off_124D58) = a1[24];
  }
  ke_event_schedule_1(aSetVendorCa, v7, v17);
  return rx_packet_handler_2((int)a1, 28, 1, 0);
}


// radio_read_config @ 0x124d70
int radio_read_config(volatile uint8_t *a1) {
  int v1; // r1
  int v3; // r3
  volatile unsigned int *v4; // r0
  int v5; // r1
  volatile unsigned int *v6; // r0
  int v7; // r1
  volatile unsigned int *v8; // r0

  v1 = *a1;
  v3 = (uint8_t)*(volatile uint32_t *)off_124E30;
  if ( *a1 )
  {
    v4 = (volatile unsigned int *)off_124E34;
    *(volatile uint32_t *)off_124E34 = *(volatile uint32_t *)off_124E34 & 0xFFFFFF00 | v1;
    *v4 = *v4 & 0xFF0000FF | ((v3 * v1) << 8);
  }
  v5 = a1[1];
  if ( a1[1] )
  {
    v6 = (volatile unsigned int *)off_124E38;
    *(volatile uint32_t *)off_124E38 = *(volatile uint32_t *)off_124E38 & 0xFFFFFF00 | v5;
    *v6 = *v6 & 0xFF0000FF | ((v3 * v5) << 8);
  }
  v7 = a1[2];
  if ( a1[2] )
  {
    v8 = (volatile unsigned int *)off_124E3C;
    *(volatile uint32_t *)off_124E3C = *(volatile uint32_t *)off_124E3C & 0xFFFFFF00 | v7;
    *v8 = *v8 & 0xFF0000FF | ((v3 * v7) << 8);
  }
  if ( a1[3] )
    *(volatile uint32_t *)off_124E40 = *(volatile uint32_t *)off_124E40 & 0xFFFFFF00 | a1[3];
  if ( a1[4] )
    *(volatile uint32_t *)off_124E40 = *(volatile uint32_t *)off_124E40 & 0xFFFF00FF | (a1[4] << 8);
  if ( a1[5] )
    *(volatile uint32_t *)off_124E40 = *(volatile uint32_t *)off_124E40 & 0xFF00FFFF | (a1[5] << 16);
  ke_event_schedule_1(aSetVendorTs);
  return rx_packet_handler_2((int)a1, 6, 1, 0);
}


// set_cfg_flag @ 0x124e48
int set_cfg_flag(volatile uint8_t *a1) {
  int v1; // r3

  v1 = *a1;
  if ( v1 << 28 )
    *(volatile uint8_t *)off_124ED4 = v1 & 1;
  if ( (v1 & 0xF0) != 0 )
    ((volatile uint32_t *)(uintptr_t)off_124ED8)[102] = (((volatile uint32_t *)(uintptr_t)off_124ED8)[102] & ~0xFFu) | ((uint8_t)(v1 & 0x10) & 0xFFu);
  if ( a1[1] )
    *(volatile uint32_t *)off_124EDC = a1[1] | *(volatile uint32_t *)off_124EDC & 0xFFFFFF00;
  if ( a1[2] )
    *(volatile uint32_t *)off_124EE0 = a1[2] | *(volatile uint32_t *)off_124EE0 & 0xFFFFFF00;
  if ( a1[3] )
    *(volatile uint32_t *)off_124EDC = *(volatile uint32_t *)off_124EDC & 0xFFF00FFF | (a1[3] << 12);
  if ( a1[4] )
    *(volatile uint32_t *)off_124EE0 = *(volatile uint32_t *)off_124EE0 & 0xFFF00FFF | (a1[4] << 12);
  ke_event_schedule_1(aSetVendorCca);
  return rx_packet_handler_2((int)a1, 5, 1, 0);
}


// dispatch_by_type @ 0x124ee8
int dispatch_by_type(int a1, volatile uint16_t *a2, int a3, void *a4) {
  int v4; // r4
  void *v6; // r1
  int v8; // [sp+0h] [bp-8h]
  int v9; // [sp+0h] [bp-8h]
  int v10; // [sp+0h] [bp-8h]
  int v11; // [sp+0h] [bp-8h]

  v4 = *(volatile uint32_t *)a2;
  v6 = a4;
  switch ( v4 )
  {
    case 0:
      v8 = a3;
      radio_reg_init(a2 + 2);
      a3 = v8;
      v6 = a4;
      break;
    case 1:
      v10 = a3;
      ble_store_adv_data((volatile uint8_t *)a2 + 4);
      a3 = v10;
      v6 = a4;
      break;
    case 2:
      v11 = a3;
      radio_read_config((volatile uint8_t *)a2 + 4);
      a3 = v11;
      v6 = a4;
      break;
    case 3:
      v9 = a3;
      ((int (*)())set_cfg_flag)((volatile uint8_t *)a2 + 4, a4);
      a3 = v9;
      v6 = a4;
      break;
    default:
      break;
  }
  ((int (*)())hci_evt_alloc_send)(127, (int)(uintptr_t)(v6), a3, a4);
  return 0;
}



// compare_offsets @ 0x124f48
unsigned int compare_offsets(int a1, int a2) {
  return (unsigned int)(*(volatile uint32_t *)(a1 + 12) - *(volatile uint32_t *)(a2 + 12)) >> 31;
}



// env_list_init_1903c8 @ 0x124f54
int env_list_init_1903c8() {
  return (int)(uintptr_t)(zero_struct((void *)(uintptr_t)(dword_124F5C)));
}



