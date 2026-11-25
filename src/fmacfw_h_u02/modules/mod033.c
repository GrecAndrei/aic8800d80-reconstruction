// mmio_ring_init @ 0x123884
int mmio_ring_init(int a1, int a2, int a3, int a4) {
  int v4; // r0
  volatile uint32_t *v5; // r5
  volatile uint32_t *v6; // r3
  int v7; // r4
  BOOL v8; // r0
  int v9; // r3

  v4 = tx_send_pdu(5, a4, a3, 28);
  v5 = (void *)(uintptr_t)(off_123944);
  *(volatile uint32_t *)v4 = dword_123948;
  v6 = (void *)(uintptr_t)(off_12394C);
  *(volatile uint32_t *)(v4 + 4) = *v5;
  *(volatile uint32_t *)(v4 + 8) = *v6;
  *(volatile uint8_t *)(v4 + 26) = 4;
  *(volatile uint16_t *)(v4 + 24) = 32;
  v7 = v4;
  read_mmio_pair((volatile uint32_t *)(v4 + 12), (volatile uint32_t *)(v4 + 16));
  *(volatile uint32_t *)(v7 + 20) = dword_123950;
  if ( (*v5 & 0x20000) != 0 && rf_status_bit28() )
  {
    *(volatile uint32_t *)(v7 + 20) |= 0x400u;
    if ( (*(volatile uint32_t *)off_123944 & 0x20000) == 0 )
      goto LABEL_3;
  }
  else if ( (*(volatile uint32_t *)off_123944 & 0x20000) == 0 )
  {
    goto LABEL_3;
  }
  if ( rf_status_bit30() )
    *(volatile uint32_t *)(v7 + 20) |= 0x4000u;
LABEL_3:
  if ( (*(volatile uint32_t *)off_123944 & 0x2000) != 0 )
    *(volatile uint32_t *)(v7 + 20) |= 0x1000u;
  if ( return_true() )
    *(volatile uint32_t *)(v7 + 20) |= 0x200u;
  if ( (*(volatile uint32_t *)off_123944 & 0x8000) != 0 && rf_status_bit21() )
    *(volatile uint32_t *)(v7 + 20) |= 0x800000u;
  v8 = check_rf_ready();
  v9 = *(volatile uint32_t *)(v7 + 20);
  if ( v8 )
    v9 |= 0x80000u;
  *(volatile uint32_t *)(v7 + 20) = v9 | 0x600000;
  rx_process_packet_1(v7);
  return 0;
}



// list_check_first @ 0x123954
void list_check_first(int a1, int a2, int a3, int a4) {
  volatile int16_t **v4; // r8
  int v5; // r0
  struct __attribute__((packed)) { int v9; // [sp+0h] [bp-28h]
  uint16_t a1a[2]; // [sp+4h] [bp-24h] BYREF
  char _pad2[5]; char v11; // [sp+Dh] [bp-1Bh]
  char _pad3[2]; uint32_t v12[6]; // [sp+10h] [bp-18h] BYREF
  } _frame;
  v4 = (volatile int16_t **)off_123A24;
  v5 = **(volatile int16_t **)off_123A24;
  memset((void *)(_frame.v12), 0, sizeof(_frame.v12));
  if ( v5 < 0 && hci_cmd_handler(a3) )
    irq_disable_mmio_write((int)aKeStateGetDest, (int)aMmStartReqHand, 337);
  set_rf_channel((volatile int *)a2);
  _frame.v11 = 0;
  ((int (*)())check_boot_flag)(_frame.a1a, 0, dword_123A0C, 2484, _frame.v9, dword_123A0C, 2484);
  call_stack_helper(15);
  *((volatile uint16_t *)off_123A10 + 14) = *(volatile uint16_t *)(a2 + 68);
  poll_hw_ready((int)_frame.v12);
  if ( **v4 < 0 && (uint8_t)a4 > 0xEu )
  {
    irq_disable_mmio_write((int)aIdTaskMax, (int)aKeTaskLocal_2, 183);
    goto LABEL_7;
  }
  if ( (uint8_t)a4 > 0xCu )
LABEL_7:
    mac_write_header_word(3, a4, a3);
  rf_write_reg();
  rf_status_check();
  hci_cmd_preprocess(a3, 2);
}


// list_find_entry @ 0x123a28
int list_find_entry(int a1, void ( **a2)(int), unsigned int a3) {
  volatile int16_t **v3; // r5
  int result; // r0
  int v7; // r0

  v3 = (volatile int16_t **)off_123AA0;
  if ( **(volatile int16_t **)off_123AA0 < 0 && hci_cmd_handler(a3) == 4 )
    irq_disable_mmio_write((int)aKeStateGetDest_0, (int)aMmForceIdleReq_0, 1587);
  result = hci_cmd_handler(a3);
  if ( result )
  {
    if ( result != 2 )
    {
      rf_status_check();
      hci_cmd_preprocess(a3, 2);
      return 2;
    }
  }
  else
  {
    if ( **v3 < 0 && *(volatile uint32_t *)off_123AAC << 28 )
      irq_disable_mmio_write((int)aNxmacCurrentSt, (int)aMmForceIdleReq_0, 1594);
    v7 = hci_cmd_preprocess(a3, 3);
    (*a2)(v7);
    return 0;
  }
  return result;
}


// classify_command @ 0x123ab4
int classify_command(int a1, volatile uint8_t *a2, unsigned int a3, int a4) {
  int v7; // r2
  volatile uint16_t *v8; // r5
  int result; // r0

  if ( hci_cmd_handler(a3) == 3 || hci_cmd_handler(a3) == 4 )
    return 2;
  v7 = *a2;
  v8 = (void *)(uintptr_t)(off_123B38);
  *((volatile uint8_t *)off_123B38 + 31) = v7;
  if ( !v7 )
  {
    if ( hci_cmd_handler(a3) != 2 )
    {
      rf_write_reg();
LABEL_6:
      mac_write_header_word(35, a4, a3);
      return 0;
    }
    return 2;
  }
  result = hci_cmd_handler(a3);
  if ( !result )
  {
    if ( **(volatile int16_t **)off_123B3C < 0 )
    {
      if ( *(volatile uint32_t *)off_123B40 << 28 )
        irq_disable_mmio_write((int)aNxmacCurrentSt, (int)aMmSetIdleReqHa, 1522);
    }
    v8[9] = 0;
    goto LABEL_6;
  }
  if ( result != 2 )
  {
    rf_status_check();
    hci_cmd_preprocess(a3, 2);
    return 2;
  }
  return result;
}


// rf_calibrate_1 @ 0x123b4c
int rf_calibrate_1(unsigned int a1, volatile uint8_t *a2, unsigned int a3, int a4) {
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
  int v60; // r3
  int v61; // r2
  unsigned int v62; // r0
  volatile uint8_t *v63; // r6
  volatile int *v64; // r3
  volatile uint8_t *v65; // r2
  int v66; // r3
  int v67; // r1
  volatile uint8_t *v68; // r2
  int v69; // r1
  volatile int *v70; // r3
  volatile uint32_t *v71; // lr
  int v72; // r12
  volatile uint32_t *v73; // r2
  int v74; // r0
  volatile uint32_t *v75; // r3
  volatile uint8_t *v76; // r3
  int v77; // r2
  volatile int *v78; // r3
  int v79; // r0
  int v80; // r7
  volatile int *v81; // r12
  int v82; // r1
  volatile int *v83; // r3
  volatile uint32_t *v84; // r12
  volatile uint32_t *v85; // r2
  int v86; // r0
  int v87; // r3
  volatile uint8_t *v88; // r8
  int v89; // r2
  volatile uint32_t *v90; // r2
  volatile uint32_t *v91; // r0
  int v92; // r1
  volatile uint8_t *v93; // r8
  volatile int *v94; // r0
  volatile int *v95; // r1
  unsigned int v96; // r12
  unsigned int v97; // r3
  volatile uint8_t *v98; // r3
  volatile int *v99; // r12
  unsigned int v100; // r3
  unsigned int v101; // r1
  struct __attribute__((packed)) { int v102; // [sp+0h] [bp-24h]
  int v103; // [sp+4h] [bp-20h]
  int v104; // [sp+8h] [bp-1Ch]
  union { int v105; // [sp+Ch] [bp-18h]
  volatile int *v106; // [sp+Ch] [bp-18h]
  volatile int *v107; // [sp+Ch] [bp-18h]
  char v108; // [sp+Ch] [bp-18h]
  char v109; }; // [sp+Ch] [bp-18h]
  union { int v110; // [sp+10h] [bp-14h]
  int v111; }; // [sp+10h] [bp-14h]
  union { int v112; // [sp+14h] [bp-10h]
  int v113; }; // [sp+14h] [bp-10h]
  char _pad6[4]; uint8_t a1a[8]; // [sp+1Ch] [bp-8h] BYREF
  } _frame;
  v8 = hci_cmd_handler(a3);
  if ( !v8 )
  {
    v10 = (volatile int16_t **)off_123E50;
    v11 = **(volatile int16_t **)off_123E50;
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
              v13 = (void *)(uintptr_t)(off_123E24);
              v14 = 2;
              goto LABEL_10;
          }
        }
        goto LABEL_24;
      }
      if ( a1 == 143 )
      {
LABEL_16:
        v13 = (void *)(uintptr_t)(off_123E24);
        *((volatile uint8_t *)off_123E24 + 48) = 0;
        v14 = abs_i32(*(volatile uint32_t *)a2);
        if ( v14 )
        {
          rf_is_ready(*(volatile uint32_t *)a2);
          v14 = 0;
        }
        else if ( v13[49] )
        {
          v13[49] = 0;
if ( patch_check_ready((void *)(_frame.a1a)) ) get_channel_entry_info( *(volatile uint8_t *)(*(volatile uint32_t *)_frame.a1a + 1225), dword_123E28 + 38 * *(volatile uint8_t *)(*(volatile uint32_t *)_frame.a1a + 107));
        }
        goto LABEL_10;
      }
LABEL_24:
      v13 = (void *)(uintptr_t)(off_123E24);
      v14 = 2;
      goto LABEL_10;
    }
    if ( !(*(volatile uint32_t *)off_123E20 << 28) )
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
    irq_disable_mmio_write((int)aNxmacCurrentSt, (int)aMmHwConfigHand, 2493);
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
          v63 = (volatile uint8_t *)tx_send_pdu(7, a4, a3, 2);
          v13 = (void *)(uintptr_t)(off_124194);
          *v63 = transmit_radio_packet((int)(a2 + 2), *a2, a2[8], v63 + 1);
          rx_process_packet_1((int)v63);
          v14 = 0;
          goto LABEL_10;
        case 8u:
LABEL_71:
          v62 = *a2;
          if ( v62 <= 3 )
            get_bss_by_index(v62);
          if ( !*((volatile uint32_t *)off_1241D0 + 2) )
            rf_set_power_off();
          mac_write_header_word(9, a4, a3);
          v13 = (void *)(uintptr_t)(off_124194);
          v14 = 0;
          goto LABEL_10;
        case 0xEu:
          v11 = **v10;
LABEL_69:
          v13 = (void *)(uintptr_t)(off_124194);
          v61 = *(volatile uint32_t *)a2;
          *(volatile uint32_t *)off_124194 = *(volatile uint32_t *)a2;
          if ( v11 < 0 && *(volatile uint32_t *)off_1244F4 << 28 )
          {
            mmio_write_field((int)aNxmacCurrentSt, (int)aMmRxFilterSet_4, 472);
            v61 = *(volatile uint32_t *)v13;
          }
          *(volatile uint32_t *)off_1241CC = v61 | *((volatile uint32_t *)v13 + 1);
          mac_write_header_word(15, a4, a3);
          v14 = 0;
          goto LABEL_10;
        case 0x10u:
LABEL_67:
          v57 = tx_send_pdu(17, a4, a3, 2);
          v13 = (void *)(uintptr_t)(off_124194);
          v58 = v57;
          ((int (*)())check_boot_flag)((volatile uint16_t *)a2, a2[10], v59, v60, _frame.v102, _frame.v103, _frame.v104);
          rx_process_packet_1(v58);
          v14 = 0;
          goto LABEL_10;
        case 0x12u:
LABEL_66:
          v56 = (void *)(uintptr_t)(off_1241C8);
          v13 = (void *)(uintptr_t)(off_124194);
          *(volatile uint32_t *)off_1241C8 = *(volatile uint32_t *)off_1241C8 & 0xFFFFFF00 | *a2;
          *v56 |= 0x80000000;
          mac_write_header_word(19, a4, a3);
          v14 = 0;
          goto LABEL_10;
        case 0x14u:
LABEL_63:
          v54 = *(volatile uint16_t *)a2;
          v55 = dword_1241C4 + 1320 * a2[2];
          if ( *(volatile uint8_t *)(v55 + 106) )
            set_bss_cap(v55, v54);
          else
            *(volatile uint32_t *)(dword_124180 + 696 * *(volatile uint8_t *)(v55 + 116) + 8) = v54 << 10;
          mac_write_header_word(21, a4, a3);
          v13 = (void *)(uintptr_t)(off_124194);
          v14 = 0;
          goto LABEL_10;
        case 0x16u:
LABEL_53:
          v48 = *(volatile char **)a2;
          v49 = a2[5];
          v13 = (void *)(uintptr_t)(off_124194);
          v50 = *((volatile uint32_t *)off_1241BC + 10);
          v52 = (volatile char *)(*(volatile uint32_t *)a2 & 0xFFFFF1FF);
          v51 = v52 == nullptr;
          v53 = v49 + 4;
          if ( v52 )
            v48 = (volatile char *)off_124194 + 4 * v53;
          else
            v52 = (volatile char *)off_124194 + 4 * v53;
          if ( v51 )
            *((volatile uint32_t *)v52 + 1) = (int)(uintptr_t)(v48);
          else
            *((volatile uint32_t *)v48 + 1) = (int)(uintptr_t)(v52);
          if ( v50 && *(volatile uint8_t *)(v50 + 4) == v49 )
            *(volatile uint32_t *)off_1241C0 = *(volatile uint32_t *)&v13[4 * v53 + 4];
          mac_write_header_word(23, a4, a3);
          v14 = 0;
          goto LABEL_10;
        case 0x18u:
LABEL_52:
          v13 = (void *)(uintptr_t)(off_124194);
          memcpy((volatile char *)(dword_1241B0 + 1320 * a2[6]), (volatile char *)a2, 6u);
          v46 = (void *)(uintptr_t)(off_1241B8);
          v47 = *((volatile uint16_t *)a2 + 2);
          *(volatile uint32_t *)off_1241B4 = *(volatile uint32_t *)a2;
          *v46 = v47;
          mac_write_header_word(25, a4, a3);
          v14 = 0;
          goto LABEL_10;
        case 0x1Cu:
LABEL_76:
          v13 = (void *)(uintptr_t)(off_124194);
          *(volatile uint32_t *)off_1241D4 = (*a2 << 14) & 0x1C000 | *(volatile uint32_t *)off_1241D4 & 0xFFFE3FFF;
          mac_write_header_word(29, a4, a3);
          v14 = 0;
          goto LABEL_10;
        case 0x1Eu:
LABEL_33:
          v27 = a2[3];
          v28 = dword_1241C4;
          v29 = dword_1241C4 + 1320 * v27;
          _frame.a1a[0] = 0;
          _frame.v110 = 1320 * v27;
          v30 = reset_drv_flag(_frame.a1a);
          v31 = *(volatile uint8_t *)(v29 + 106);
          v32 = a2[2];
          *(volatile uint8_t *)(v29 + 108) = v32;
          _frame.v105 = v30;
          if ( !v31 )
          {
            _frame.v112 = *(volatile uint8_t *)(v29 + 116);
            if ( v32 )
            {
              v33 = dword_124180 + 696 * *(volatile uint8_t *)(v29 + 116);
              v34 = (*(volatile uint32_t *)0x40501010u);
              v35 = (volatile uint32_t *)(_frame.v110 + 24 + v28);
              mem_copy_util(v35, v34 + *(volatile uint32_t *)(v33 + 8));
              *(volatile uint16_t *)(v33 + 32) = *(volatile uint16_t *)a2;
              mac_clear_irq();
              check_feature_flag(
                256,
                "vif state active:%d,%d,%d,%d\r\n",
                *(volatile uint8_t *)(v33 + 35),
                *(volatile uint16_t *)(v33 + 32),
                *(volatile uint8_t *)(v29 + 1224),
                _frame.v105);
              v36 = (void *)(uintptr_t)(off_124190);
              *(volatile uint32_t *)off_12418C = (uint16_t)*(volatile uint32_t *)off_12418C | (*(volatile uint16_t *)a2 << 16);
              if ( (*v36 & 0x8000) != 0 && rf_status_bit21() && (*(volatile uint32_t *)(v33 + 4) & 0x20) != 0 )
              {
                set_rf_frequency(*(volatile uint16_t *)a2);
                read_int_status();
                check_feature_flag(256, aHeEnabled);
                mmio_set_register_bit();
              }
              v13 = (void *)(uintptr_t)(off_124194);
              _frame.v113 = dword_124180 + 696 * _frame.v112;
              v37 = v28 + 1320 * v27;
              v38 = *(volatile uint32_t *)(v37 + 4) | 1;
              *(volatile uint16_t *)(_frame.v113 + 30) = (unsigned int)(((unsigned int)dword_1241D8
                                                    * (uint64_t)(*(volatile uint32_t *)(_frame.v113 + 8)
                                                                       * ((unsigned int)*((volatile uint16_t *)off_124194
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
              _frame.v111 = v37;
              wifi_disable_action((int)(uintptr_t)((volatile uint32_t *)v29));
              v40 = *(volatile uint8_t *)(_frame.v111 + 1224);
              if ( *(volatile uint8_t *)(_frame.v111 + 1224) )
              {
                if ( !_frame.v105 )
                  goto LABEL_39;
                v76 = (void *)(uintptr_t)(off_1244EC);
                if ( !*((volatile uint32_t *)off_1244EC + 8) )
                  goto LABEL_39;
                *((volatile uint32_t *)off_1244EC + 8) = 0;
                v76[36] = 0;
                chip_register_set_bit();
LABEL_120:
                v77 = **v10;
                *((volatile uint32_t *)v13 + 1) |= 0x10u;
                if ( v77 < 0 && *(volatile uint32_t *)off_124838 << 28 )
                  mmio_write_field((int)aNxmacCurrentSt, (int)aMmRxFilterSet_4, 472);
                *(volatile uint32_t *)off_124520 = *(volatile uint32_t *)v13 | *((volatile uint32_t *)v13 + 1);
                v32 = a2[2];
                goto LABEL_40;
              }
              if ( _frame.v105 )
              {
                if ( _frame.v105 != 1 )
                  goto LABEL_39;
                v88 = (void *)(uintptr_t)(off_124814);
                if ( v29 == *((volatile uint32_t *)off_124814 + 8) )
                  goto LABEL_39;
                *((volatile uint32_t *)off_124814 + 8) = v40;
                _frame.v108 = v40;
                mem_set_util((int)(uintptr_t)(v35));
                v88[36] = _frame.v108;
                chip_register_set_bit();
                v32 = a2[2];
              }
              else
              {
                if ( *((volatile uint32_t *)off_124198 + 8) )
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
                v99 = (volatile int *)off_124834;
                v100 = *(volatile uint32_t *)(_frame.v113 + 8);
                v101 = *(volatile uint32_t *)off_124834;
                *((volatile uint32_t *)off_124198 + 8) = v29;
                *v99 = (uint16_t)(v100 >> 10) | (HIWORD(v101) << 16);
                mem_set_util((int)(uintptr_t)(v35));
                *((volatile uint8_t *)off_124814 + 36) = 0;
                chip_register_read();
                v32 = a2[2];
              }
            }
            else
            {
              mem_set_util((int)(uintptr_t)((volatile uint32_t *)(_frame.v110 + 24 + v28)));
              nullsub_8();
              check_feature_flag(256, "vif state inactive:%d,%d\r\n", *(volatile uint8_t *)(v29 + 1224), _frame.v105);
              if ( (*(volatile uint32_t *)off_124514 & 0x8000) != 0
                && rf_status_bit21()
                && (*(volatile uint32_t *)(dword_124818 + 696 * _frame.v112 + 4) & 0x20) != 0
                && *(volatile uint8_t *)(v29 + 106) != 4 )
              {
                init_chan_entry(*(volatile uint8_t *)(v29 + 107));
              }
              v66 = v28 + 1320 * v27;
              v67 = *(volatile uint8_t *)(v66 + 1224);
              *(volatile uint8_t *)(v66 + 1227) = 0;
              *(volatile uint32_t *)(v66 + 1228) = 0;
              if ( v67 )
              {
                if ( _frame.v105 )
                {
                  v78 = *((volatile int **)off_124810 + 2);
                  if ( v78 )
                  {
                    while ( *((volatile uint8_t *)v78 + 106)
                         || !*((volatile uint8_t *)v78 + 108)
                         || (volatile int *)v29 == v78
                         || *((volatile uint8_t *)v78 + 1224) )
                    {
                      v78 = (volatile int *)*v78;
                      if ( !v78 )
                        goto LABEL_102;
                    }
                    if ( !*((volatile uint32_t *)off_124814 + 8) )
                    {
                      v79 = *((volatile uint8_t *)v78 + 116);
                      v80 = dword_124818;
                      v81 = (volatile int *)off_124834;
                      *((volatile uint32_t *)off_124814 + 8) = (int)(uintptr_t)(v78);
                      *v81 = (uint16_t)(*(volatile uint32_t *)(v80 + 696 * v79 + 8) >> 10) | (HIWORD(*v81) << 16);
                      _frame.v107 = v78;
                      mem_set_util((int)(uintptr_t)(v78 + 6));
                      *((volatile uint8_t *)off_124814 + 36) = 0;
                      v13 = (void *)(uintptr_t)(off_12481C);
                      chip_register_read();
                      v82 = **v10;
                      v83 = _frame.v107;
                      *((volatile uint32_t *)v13 + 1) &= ~0x10u;
                      if ( v82 < 0 && *(volatile uint32_t *)off_124838 << 28 )
                      {
                        mmio_write_field((int)aNxmacCurrentSt, (int)aMmRxFilterSet_4, 472);
                        v83 = _frame.v107;
                      }
                      v84 = (void *)(uintptr_t)(off_124844);
                      *(volatile uint32_t *)off_124820 = *(volatile uint32_t *)v13 | *((volatile uint32_t *)v13 + 1);
                      v85 = (void *)(uintptr_t)(off_124824);
                      v86 = v83[16];
                      v87 = *((volatile uint16_t *)v83 + 34);
                      *v84 = v86;
                      *v85 = v87;
                      v32 = a2[2];
                      goto LABEL_40;
                    }
                  }
                }
              }
              else if ( _frame.v105 == 2 )
              {
                v93 = (void *)(uintptr_t)(off_124814);
                if ( !*((volatile uint32_t *)off_124814 + 8) )
                {
                  v94 = *((volatile int **)off_124810 + 2);
                  if ( !v94 )
LABEL_170:
                    __und(0xFFu);
                  while ( *((volatile uint8_t *)v94 + 106) || !*((volatile uint8_t *)v94 + 108) || (volatile int *)v29 == v94 || *((volatile uint8_t *)v94 + 1224) )
                  {
                    v94 = (volatile int *)*v94;
                    if ( !v94 )
                      goto LABEL_170;
                  }
                  v95 = (volatile int *)off_124834;
                  _frame.v109 = *((volatile uint8_t *)v94 + 1224);
                  v96 = *(volatile uint32_t *)off_124834;
                  v97 = *(volatile uint32_t *)(dword_124818 + 696 * *((volatile uint8_t *)v94 + 116) + 8);
                  *((volatile uint32_t *)off_124814 + 8) = (int)(uintptr_t)(v94);
                  *v95 = (uint16_t)(v97 >> 10) | (HIWORD(v96) << 16);
                  mem_set_util((int)(uintptr_t)(v94 + 6));
                  v93[36] = _frame.v109;
                  v13 = (void *)(uintptr_t)(off_12481C);
                  chip_register_read();
                  v32 = a2[2];
                  goto LABEL_40;
                }
              }
              else if ( _frame.v105 == 1 )
              {
                v98 = (void *)(uintptr_t)(off_124814);
                if ( v29 == *((volatile uint32_t *)off_124814 + 8) )
                {
                  *((volatile uint32_t *)off_124814 + 8) = 0;
                  v98[36] = 0;
                  v13 = (void *)(uintptr_t)(off_12481C);
                  chip_register_set_bit();
                  v32 = a2[2];
                  goto LABEL_40;
                }
              }
LABEL_102:
              v32 = a2[2];
              v13 = (void *)(uintptr_t)(off_1244F0);
            }
LABEL_40:
            bt_scan_start((volatile uint8_t *)v29, v32);
            if ( a2[2] )
            {
              v41 = *(volatile uint32_t **)off_12419C;
              v42 = **(volatile uint32_t **)off_12419C;
              if ( v42 )
                *(volatile uint32_t *)off_1241A0 = v42;
              else
                *(volatile uint32_t *)off_12450C = *(volatile uint32_t *)(v28 + 1320 * v27 + 8);
              v43 = v41[1];
              if ( v43 )
              {
                if ( (v43 & 0xFFF) != 0 )
                  *(volatile uint32_t *)off_124508 = v43;
                else
                  *(volatile uint32_t *)off_1241A4 = v43 & 0xFFFFF000 | *(volatile uint32_t *)(v28 + 1320 * v27 + 12) & 0xFFF;
              }
              else
              {
                *(volatile uint32_t *)off_124508 = *(volatile uint32_t *)(v28 + 1320 * v27 + 12);
              }
              v44 = v41[2];
              if ( v44 )
                *(volatile uint32_t *)off_1241A8 = v44;
              else
                *(volatile uint32_t *)off_124504 = *(volatile uint32_t *)(v28 + 1320 * v27 + 16);
              v45 = v41[3];
              if ( v45 )
                *(volatile uint32_t *)off_1241AC = v45;
              else
                *(volatile uint32_t *)off_124518 = *(volatile uint32_t *)(v28 + 1320 * v27 + 20);
              get_mac_ver();
            }
            mac_write_header_word(31, a4, a3);
            v14 = 0;
            goto LABEL_10;
          }
          if ( !v30 )
          {
            if ( v32 )
            {
              v64 = nullptr;
              goto LABEL_85;
            }
LABEL_86:
            v13 = (void *)(uintptr_t)(off_1244F0);
            goto LABEL_40;
          }
          v64 = *((volatile int **)off_12451C + 2);
          if ( v64 )
          {
            do
            {
              if ( !*((volatile uint8_t *)v64 + 106) && *((volatile uint8_t *)v64 + 108) && (volatile int *)v29 != v64 && !*((volatile uint8_t *)v64 + 1224) )
                break;
              v64 = (volatile int *)*v64;
            }
            while ( v64 );
            if ( !v32 )
            {
              v68 = (void *)(uintptr_t)(off_1244EC);
              if ( !*((volatile uint32_t *)off_1244EC + 8) && v64 )
              {
                *((volatile uint32_t *)off_1244EC + 8) = (int)(uintptr_t)(v64);
                v68[36] = 0;
                _frame.v106 = v64;
                v13 = (void *)(uintptr_t)(off_1244F0);
                mem_set_util((int)(uintptr_t)(v64 + 6));
                chip_register_read();
                v69 = **v10;
                v70 = _frame.v106;
                *((volatile uint32_t *)v13 + 1) &= ~0x10u;
                if ( v69 < 0 && *(volatile uint32_t *)off_124838 << 28 )
                {
                  mmio_write_field((int)aNxmacCurrentSt, (int)aMmRxFilterSet_4, 472);
                  v70 = _frame.v106;
                }
                v71 = (void *)(uintptr_t)(off_124530);
                v72 = v70[16];
                *(volatile uint32_t *)off_124520 = *(volatile uint32_t *)v13 | *((volatile uint32_t *)v13 + 1);
                v73 = (void *)(uintptr_t)(off_124524);
                v74 = *((volatile uint16_t *)v70 + 34);
                *v71 = v72;
                v75 = (void *)(uintptr_t)(off_124528);
                *v73 = v74;
                *v75 = dword_12452C;
                v73[8212] &= 0xFFFBFFFE;
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
          v65 = (void *)(uintptr_t)(off_1244EC);
          if ( v64 == *((volatile int **)off_1244EC + 8) )
          {
            *((volatile uint32_t *)off_1244EC + 8) = 0;
            v65[36] = 0;
            v13 = (void *)(uintptr_t)(off_12481C);
            chip_register_set_bit();
            v89 = **v10;
            *((volatile uint32_t *)v13 + 1) |= 0x10u;
            if ( v89 < 0 && *(volatile uint32_t *)off_124838 << 28 )
              mmio_write_field((int)aNxmacCurrentSt, (int)aMmRxFilterSet_4, 472);
            v90 = (void *)(uintptr_t)(off_124820);
            v91 = (void *)(uintptr_t)(off_12482C);
            *(volatile uint32_t *)off_124820 = *(volatile uint32_t *)v13 | *((volatile uint32_t *)v13 + 1);
            v92 = dword_124830;
            *v91 = dword_124830;
            v90[8197] |= v92;
            v32 = a2[2];
            goto LABEL_40;
          }
          goto LABEL_86;
        case 0x20u:
LABEL_32:
          v13 = (void *)(uintptr_t)(off_123E24);
          *(volatile uint32_t *)off_123E48 = *a2 | (((uint8_t)*(volatile uint32_t *)off_123E44 * *a2) << 8);
          mac_write_header_word(33, a4, a3);
          v14 = 0;
          goto LABEL_10;
        case 0x28u:
LABEL_27:
          v15 = *a2;
          if ( *a2 )
          {
            if ( dma_tx_ring(dword_1244FC + 696 * a2[1], a2[2], *((volatile uint16_t *)a2 + 3)) )
            {
              *(volatile uint32_t *)off_124500 |= 0x80u;
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
            v18 = *(volatile uint32_t *)(dword_123E38 + 4 * *((volatile uint8_t *)off_123E34 + v16));
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
            alloc_tx_event("mm_ba_add_req_handler %d, %d, %d\n", v16, v17, v19);
            v20 = *((volatile uint16_t *)a2 + 2);
            v21 = 696 * a2[1];
            v22 = *(volatile uint8_t *)(v21 + 12 * a2[2] + dword_123E4C + 453);
            v23 = *((volatile uint16_t *)a2 + 3);
            v24 = v21 + 6 * a2[2] + dword_123E4C;
            v25 = dword_123E40 + 32 * v22;
            *(volatile uint16_t *)(v24 + 354) = v19;
            *(volatile uint16_t *)(v24 + 356) = v20;
            *(volatile uint16_t *)(v25 + 12) = v23;
          }
          v26 = (volatile uint8_t *)tx_send_pdu(41, a4, a3, 3);
          *v26 = a2[1];
          v26[1] = a2[2];
          v26[2] = v15;
          rx_process_packet_1((int)v26);
          v13 = (void *)(uintptr_t)(off_123E24);
          v14 = 0;
          goto LABEL_10;
        case 0x30u:
LABEL_26:
          unknown_12f378();
          v13 = (void *)(uintptr_t)(off_123E24);
          v14 = 0;
          goto LABEL_10;
        case 0x3Bu:
LABEL_25:
          cfm_mac_info(a2);
          mac_write_header_word(60, a4, a3);
          v13 = (void *)(uintptr_t)(off_123E24);
          v14 = 0;
          goto LABEL_10;
        default:
          break;
      }
    }
    if ( **v10 >= 0 )
      goto LABEL_24;
LABEL_21:
    v13 = (void *)(uintptr_t)(off_123E24);
    irq_disable_mmio_write(off_123E30, (int)aMmHwConfigHand, 2552);
    v14 = 2;
LABEL_10:
    *(volatile uint32_t *)off_123E20 = (uint8_t)(16 * v13[19]);
    hci_cmd_preprocess(a3, (uint8_t)v13[18]);
    return v14;
  }
  if ( (uint16_t)(v8 - 2) > 2u )
  {
    v12 = (void *)(uintptr_t)(off_123E24);
    *((volatile uint8_t *)off_123E24 + 19) = *(volatile uint8_t *)off_123E20 & 0xF;
    v12[18] = hci_cmd_handler(a3);
    rf_status_check();
    hci_cmd_preprocess(a3, 2);
  }
  return 2;
}


// mmio_read_status @ 0x124848
int mmio_read_status(volatile uint16_t *a1) {
  int v1; // r3
  volatile int *v2; // r2
  int v4; // r0
  volatile int *v5; // r5
  volatile int *v6; // r7
  int v7; // r6
  int v8; // r1
  int v9; // r5
  volatile int *v10; // r0

  v1 = dword_1248D0;
  v2 = *(volatile int **)off_1248CC;
  v4 = *a1;
  v5 = (volatile int *)off_1248D4;
  v6 = (volatile int *)off_1248D8;
  v7 = a1[2];
  *v2 = **(volatile uint32_t **)off_1248CC & dword_1248D0 | (v4 << 12);
  *v5 = *v5 & v1 | (v4 << 12);
  v8 = a1[1];
  v2[1] = v2[1] & v1 | (v8 << 12);
  v9 = a1[3];
  *v6 = *v6 & v1 | (v8 << 12);
  v2[2] = v2[2] & v1 | (v7 << 12);
  v10 = (volatile int *)off_1248DC;
  v6[1] = v6[1] & v1 | (v7 << 12);
  v2[3] = v2[3] & v1 | (v9 << 12);
  *v10 = v1 & *v10 | (v9 << 12);
  get_mac_ver();
  alloc_tx_event("set txop: bk:%x,be:%x,vi:%x,vo:%x\n", *a1, a1[1], a1[2], a1[3]);
  return 0;
}


// scan_param_update @ 0x1248e4
int scan_param_update(volatile uint8_t *a1) {
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

  v1 = (volatile int *)off_1249D4;
  v2 = a1[16];
  ((volatile uint32_t *)(uintptr_t)off_1249D4)[90] = (((volatile uint32_t *)(uintptr_t)off_1249D4)[90] & ~0xFFu) | ((uint8_t)(a1[17]) & 0xFFu);
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
    *(volatile uint32_t *)off_1249D8 |= 0x10u;
  else
    *(volatile uint32_t *)off_1249D8 &= ~0x10u;
  if ( a1[20] )
    *(volatile uint32_t *)off_1249D8 |= 2u;
  else
    *(volatile uint32_t *)off_1249D8 &= ~2u;
  v8 = (void *)(uintptr_t)(off_1249F0);
  v9 = (void *)(uintptr_t)(off_1249F4);
  v10 = (void *)(uintptr_t)(off_1249F8);
  v11 = 1320 * v2 + 8 + dword_1249DC;
  v12 = a1 - 4;
  v13 = dword_1249DC + 1320 * v2;
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
      *(volatile uint32_t *)(*(volatile uint32_t *)off_1249E0 + 4 * i) = v15;
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
          *(volatile uint32_t *)off_1249EC = v15;
        }
        get_mac_ver();
      }
    }
  }
  if ( a1[24] )
  {
    v17 = off_1249E4;
    *(volatile uint32_t *)(uintptr_t)(off_1249E4) = a1[24];
  }
  alloc_tx_event(aSetVendorCa, v7, v17);
  return process_packet_params((int)a1, 28, 1, 0);
}


// mmio_read_byte @ 0x1249fc
int mmio_read_byte(volatile uint8_t *a1) {
  int v1; // r1
  int v3; // r3
  volatile unsigned int *v4; // r0
  int v5; // r1
  volatile unsigned int *v6; // r0
  int v7; // r1
  volatile unsigned int *v8; // r0

  v1 = *a1;
  v3 = (uint8_t)*(volatile uint32_t *)off_124ABC;
  if ( *a1 )
  {
    v4 = (volatile unsigned int *)off_124AC0;
    *(volatile uint32_t *)off_124AC0 = *(volatile uint32_t *)off_124AC0 & 0xFFFFFF00 | v1;
    *v4 = *v4 & 0xFF0000FF | ((v3 * v1) << 8);
  }
  v5 = a1[1];
  if ( a1[1] )
  {
    v6 = (volatile unsigned int *)off_124AC4;
    *(volatile uint32_t *)off_124AC4 = *(volatile uint32_t *)off_124AC4 & 0xFFFFFF00 | v5;
    *v6 = *v6 & 0xFF0000FF | ((v3 * v5) << 8);
  }
  v7 = a1[2];
  if ( a1[2] )
  {
    v8 = (volatile unsigned int *)off_124AC8;
    *(volatile uint32_t *)off_124AC8 = *(volatile uint32_t *)off_124AC8 & 0xFFFFFF00 | v7;
    *v8 = *v8 & 0xFF0000FF | ((v3 * v7) << 8);
  }
  if ( a1[3] )
    *(volatile uint32_t *)off_124ACC = *(volatile uint32_t *)off_124ACC & 0xFFFFFF00 | a1[3];
  if ( a1[4] )
    *(volatile uint32_t *)off_124ACC = *(volatile uint32_t *)off_124ACC & 0xFFFF00FF | (a1[4] << 8);
  if ( a1[5] )
    *(volatile uint32_t *)off_124ACC = *(volatile uint32_t *)off_124ACC & 0xFF00FFFF | (a1[5] << 16);
  alloc_tx_event(aSetVendorTs);
  return process_packet_params((int)a1, 6, 1, 0);
}


// check_flag_bit @ 0x124ad4
int check_flag_bit(volatile uint8_t *a1) {
  int v1; // r3

  v1 = *a1;
  if ( v1 << 28 )
    *(volatile uint8_t *)off_124B60 = v1 & 1;
  if ( (v1 & 0xF0) != 0 )
    ((volatile uint32_t *)(uintptr_t)off_124B64)[102] = (((volatile uint32_t *)(uintptr_t)off_124B64)[102] & ~0xFFu) | ((uint8_t)(v1 & 0x10) & 0xFFu);
  if ( a1[1] )
    *(volatile uint32_t *)off_124B68 = a1[1] | *(volatile uint32_t *)off_124B68 & 0xFFFFFF00;
  if ( a1[2] )
    *(volatile uint32_t *)off_124B6C = a1[2] | *(volatile uint32_t *)off_124B6C & 0xFFFFFF00;
  if ( a1[3] )
    *(volatile uint32_t *)off_124B68 = *(volatile uint32_t *)off_124B68 & 0xFFF00FFF | (a1[3] << 12);
  if ( a1[4] )
    *(volatile uint32_t *)off_124B6C = *(volatile uint32_t *)off_124B6C & 0xFFF00FFF | (a1[4] << 12);
  alloc_tx_event(aSetVendorCca);
  return process_packet_params((int)a1, 5, 1, 0);
}


// cmd_dispatch @ 0x124b74
int cmd_dispatch(int a1, int a2, int a3, int a4) {
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
      mmio_read_status((volatile uint16_t *)(a2 + 4));
      a3 = a3a;
      break;
    case 1:
      a3c = a3;
      scan_param_update((volatile uint8_t *)(a2 + 4));
      a3 = a3c;
      break;
    case 2:
      a3d = a3;
      mmio_read_byte((volatile uint8_t *)(a2 + 4));
      a3 = a3d;
      break;
    case 3:
      a3e = a3;
      check_flag_bit((volatile uint8_t *)(a2 + 4));
      a3 = a3e;
      break;
    case 6:
      v6 = *(volatile uint8_t *)(a2 + 4);
      a3b = a3;
      *(volatile uint32_t *)(uintptr_t)(off_124BDC) = v6;
      alloc_tx_event("vendor set ap ps =%d\n", v6);
      a3 = a3b;
      break;
    default:
      break;
  }
  mac_write_header_word(127, a4, a3);
  return 0;
}


// is_time_before @ 0x124be4
unsigned int is_time_before(int a1, int a2) {
  return (unsigned int)(*(volatile uint32_t *)(a1 + 12) - *(volatile uint32_t *)(a2 + 12)) >> 31;
}



// deinit_global_0x18fb00 @ 0x124bf0
int deinit_global_0x18fb00() {
  return (int)(uintptr_t)(clear_stats_buf((void *)(uintptr_t)(dword_124BF8)));
}



