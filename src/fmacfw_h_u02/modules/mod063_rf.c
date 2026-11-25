// rf_set_channel_cfg @ 0x136eac
/* luna: Caches the requested RF channel configuration, applies fields from the RF initialization record when available, and conditionally performs an MMIO wri */
int rf_set_channel_cfg(int a1, int a2, int a3, int16_t a4) {
  int v4; // r2
  volatile uint16_t *v5; // r4
  int v7; // r1
  volatile int *v8; // r7
  int v9; // r1
  int v10; // r0
  int16_t v11; // r1
  int v12; // r3
  int v13; // r0
  int v14; // r1
  volatile int16_t **v15; // r3
  volatile int16_t *v16; // r3
  char v18; // r7
  int v19; // r2
  int16_t v20; // r6
  int16_t v21; // r1
  volatile int16_t *v22; // r3
  int v23; // r0

  v4 = dword_136F78;
  v5 = (void *)(uintptr_t)(off_136F7C);
  v7 = *(volatile uint8_t *)(a2 + 366);
  *((volatile uint16_t *)off_136F7C + 1924) = a4;
  v8 = (volatile int *)(a2 + 352);
  *(volatile uint32_t *)(v4 + 1320 * v7 + 472) = 0;
  v5[1925] = 1;
  v9 = *(volatile uint32_t *)(a2 + 356);
  *((volatile uint32_t *)v5 + 963) = *(volatile uint32_t *)(a2 + 352);
  v5[1928] = v9;
  *(volatile uint32_t *)v5 = a2;
  *((volatile uint8_t *)v5 + 3899) = 0;
  v10 = rf_hw_init_2((void *)(uintptr_t)(a2 + 352), 0);
  if ( v10 && (v11 = *(volatile uint8_t *)(v10 + 57), v12 = v10, *(volatile uint8_t *)(v10 + 57)) )
  {
    v18 = *(volatile uint8_t *)(v10 + 58);
    v19 = v10 + 2;
    v13 = *(volatile uint32_t *)(v10 + 2);
    *((volatile uint32_t *)v5 + 973) = v13;
    v5[1948] = *(volatile uint16_t *)(v19 + 4);
    v20 = ((1 << v18) - 1) << 8;
    v19 = (v19 & ~0xFFFFu) | ((uint16_t)(v5[1948] & ~v20) & 0xFFFFu);
    v5[1948] = v19;
    v21 = *(volatile uint16_t *)(v12 + 6) - (v11 << 8);
    v22 = *(volatile int16_t **)off_136F80;
    v5[1948] = v20 & v21 | v19;
    if ( *v22 >= 0 )
      goto LABEL_4;
  }
  else
  {
    v13 = *v8;
    v14 = *(volatile uint32_t *)(a2 + 356);
    v15 = (volatile int16_t **)off_136F80;
    *((volatile uint32_t *)v5 + 973) = *v8;
    v16 = *v15;
    v5[1948] = v14;
    if ( *v16 >= 0 )
    {
LABEL_4:
      is_initialized_1(v13);
      return 1;
    }
  }
  if ( (*(volatile uint8_t *)(a2 + 352) & 1) == 0 )
    goto LABEL_4;
  v23 = irq_disable_mmio_write(dword_136F88, dword_136F84, 178);
  is_initialized_1(v23);
  return 1;
}



// rf_set_channel_freq @ 0x136f8c
/* luna: Stores channel-related values from the supplied configuration in shared RF state and sends a channel-control packet unless the selector is 6 or 11. */
int rf_set_channel_freq(int a1, int a2, int a3, int a4) {
  volatile uint16_t *v4; // r2
  uint64_t v6; // r0
  volatile uint8_t *v8; // r0
  int v9; // r0

  v4 = (void *)(uintptr_t)(off_136FE0);
  *((volatile uint16_t *)off_136FE0 + 1924) = a4;
  v4[1925] = 0;
  v6 = *(volatile uint64_t *)(a2 + 352);
  *(volatile uint32_t *)v4 = a2;
  *((volatile uint32_t *)v4 + 963) = v6;
  v4[1928] = WORD2(v6);
  if ( a4 == 11 || a4 == 6 )
  {
    is_initialized_1(v6);
    return 1;
  }
  else
  {
    v8 = (volatile uint8_t *)tx_send_pdu(4105, a4, 4, 2u);
    v8[1] = 1;
    *v8 = *(volatile uint8_t *)(a2 + 366);
    v9 = (int)(uintptr_t)(rx_process_packet_1((int)v8));
    is_initialized_1(v9);
    return 1;
  }
}



// rf_trace_channel2 @ 0x136fe4
/* luna: Sends and processes PDU 4107, logs the scan-cancel confirmation value when feature 8 is enabled, and converts the first input byte to hexadecimal. */
int rf_trace_channel2(int a1, volatile uint8_t *a2) {
  volatile uint16_t *v2; // r5
  int v4; // r0

  v2 = (volatile uint16_t *)off_137014;
  v4 = tx_send_pdu(4107, *((volatile uint16_t *)off_137014 + 1924), 4, 1);
  rx_process_packet_1(v4);
  check_feature_flag(8, "scan cancel cfm %d\r\n", v2[1924]);
  util_hex_convert(*a2);
  return 0;
}


// util_parse_command_char @ 0x13701c
/* luna: Passes a nonzero command byte to the hexadecimal conversion helper and always returns zero. */
int util_parse_command_char(int a1, volatile uint8_t *a2) {
  if ( *a2 )
    util_hex_convert((uint8_t)*a2);
  return 0;
}



// radio_reg_config @ 0x137030
/* luna: Sends a scan-cancel request, processes the response, and logs the HCI command result. */
int radio_reg_config() {
  int v0; // r0
  int cancel_status; // r0

  v0 = tx_send_pdu(2051, 2, 4, 1);
  rx_process_packet_1(v0);
  cancel_status = hci_cmd_handler(4u);
  check_feature_flag(8, "scanu cancel:%d\r\n", cancel_status);
  return 0;
}


// rf_get_band @ 0x137064
/* luna: On the first call, programs the RF band selector from the configured value clamped to 7, then increments the call counter and checks the event flag. */
int rf_get_band() {
  volatile uint8_t *v0; // r2
  char v1; // r3
  unsigned int v2; // r1

  v0 = (void *)(uintptr_t)(off_137094);
  v1 = *((volatile uint8_t *)off_137094 + 3851);
  if ( !v1 )
  {
    v2 = *((volatile uint16_t *)off_137094 + 2);
    if ( v2 >= 7 )
      v2 = 7;
    *(volatile uint32_t *)off_137098 = *(volatile uint32_t *)off_137098 & 0xFFFFFE3F | (v2 << 6);
  }
  v0[3851] = v1 + 1;
  check_event_flag_1();
  return 0;
}



// rf_task_state_handler @ 0x13709c
/* luna: Checks the length-prefixed input against a fixed token or the configured RF command entries, accepting when the entry list is empty. */
BOOL rf_task_state_handler(volatile uint8_t *a1) {
  int v1; // r8
  int v3; // r9
  int v4; // r7
  int v5; // r4
  int v6; // r5
  volatile uint8_t *v7; // r10
  int v8; // r2

  v1 = *((volatile uint8_t *)off_13710C + 3898);
  if ( *((volatile uint8_t *)off_13710C + 3898) )
    return memcmp((int)(uintptr_t)(a1 + 1), dword_137110, 7) == 0;
  v3 = *(volatile uint32_t *)off_13710C;
  v4 = *(volatile uint8_t *)(*(volatile uint32_t *)off_13710C + 368);
  if ( *(volatile uint8_t *)(*(volatile uint32_t *)off_13710C + 368) )
  {
    v5 = *(volatile uint32_t *)off_13710C;
    v6 = *((volatile uint8_t *)off_13710C + 3898);
    v7 = a1 + 1;
    while ( *(volatile uint8_t *)(v5 + 252) )
    {
      v8 = *a1;
      if ( v8 == *(volatile uint8_t *)(v5 + 252) )
      {
if ( !memcmp(v5 + 253, (int)(uintptr_t)(v7), v8) ) return 1;
        v4 = *(volatile uint8_t *)(v3 + 368);
      }
      ++v6;
      v5 += 33;
      if ( v4 <= v6 )
        return v1;
    }
  }
  return 1;
}



// rf_set_antenna_cfg @ 0x137114
/* luna: Validates an RF configuration blob and maps recognized factory-mode identifiers into bitfields in the caller's state. */
volatile uint8_t * rf_set_antenna_cfg(volatile uint8_t *result, int a2, char a3, int a4) {
  volatile uint8_t *v5; // r6
  volatile uint8_t *v7; // r0
  volatile uint8_t *v8; // r4
  int v9; // r6
  int v10; // r8
  int v11; // r6
  volatile unsigned int *i; // r4
  volatile unsigned int *v13; // r4
  int v14; // r7
  int v15; // t1
  int v16; // r6
  int v17; // r2
  volatile unsigned int *v18; // r3
  int v19; // r2
  volatile uint8_t *v20; // r0
  volatile uint8_t *v21; // r4
  int v22; // r6
  unsigned int v23; // r0
  int v24; // r8
  int v25; // r6
  volatile unsigned int *j; // r4
  volatile unsigned int *v27; // r7
  int v28; // r8
  unsigned int v29; // r4
  int v30; // r7
  int v31; // r4
  volatile unsigned int *v32; // r6
  volatile unsigned int *v33; // r6
  int v34; // r8
  int v35; // t1
  int v36; // r4
  uint8_t v37; // [sp+7h] [bp-1h] BYREF

  *(volatile uint32_t *)(a4 + 48) = 0;
  *(volatile uint32_t *)(a4 + 52) = 0;
  if ( (a3 & 0x10) == 0 )
  {
    *(volatile uint32_t *)(a4 + 48) = 1;
    return result;
  }
  v5 = result;
  v7 = check_buf_range_12d854(result, a2, &v37);
  v8 = v7;
  if ( v7 )
  {
    v9 = v37;
    result = (volatile uint8_t *)is_factory_mode_b(bswap32(*((volatile uint32_t *)v7 + 1)));
    if ( result )
    {
      result = (volatile uint8_t *)((1 << (char)result) | *(volatile uint16_t *)(a4 + 52));
      *(volatile uint16_t *)(a4 + 52) = (uint16_t)result;
    }
    v10 = *((volatile uint16_t *)v8 + 4);
    v11 = v9 - 8;
    for ( i = (volatile unsigned int *)(v8 + 10); v10 && v11 > 3; --v10 )
    {
      result = (volatile uint8_t *)is_factory_mode_b(bswap32(*i));
      v11 -= 4;
      ++i;
      if ( result )
      {
        result = (volatile uint8_t *)((1 << (char)result) | *(volatile uint16_t *)(a4 + 54));
        *(volatile uint16_t *)(a4 + 54) = (uint16_t)result;
      }
    }
    if ( v11 > 1 )
    {
      v15 = *(volatile uint16_t *)i;
      v13 = (volatile unsigned int *)((volatile char *)i + 2);
      v14 = v15;
      v16 = v11 - 2;
      if ( v15 && v16 > 3 )
      {
        while ( 1 )
        {
          result = (volatile uint8_t *)is_factory_mode_a((volatile char *)bswap32(*v13));
          v16 -= 4;
          ++v13;
          if ( result )
          {
            result = (volatile uint8_t *)((1 << (char)result) | *(volatile uint32_t *)(a4 + 48));
            *(volatile uint32_t *)(a4 + 48) = (int)(uintptr_t)(result);
          }
          if ( !--v14 )
            break;
          if ( v16 <= 3 )
          {
            if ( v16 <= 1 || (*(volatile uint16_t *)v13 & 0xC0) == 0 )
              return result;
            goto LABEL_69;
          }
        }
      }
      if ( v16 > 1 )
      {
        v17 = v16 - 2;
        v18 = (volatile unsigned int *)((volatile char *)v13 + 2);
        if ( v16 - 2 > 1 )
        {
          v19 = *(volatile uint16_t *)v18;
          v18 = &v13[4 * v19 + 1];
          v17 = v16 - 4 - 16 * v19;
        }
        if ( (*(volatile uint16_t *)v13 & 0xC0) != 0 )
        {
          if ( v17 <= 3 )
          {
LABEL_69:
            *(volatile uint16_t *)(a4 + 52) |= 0x20u;
            return result;
          }
          result = (volatile uint8_t *)is_factory_mode_b(bswap32(*v18));
          if ( result )
LABEL_28:
            *(volatile uint16_t *)(a4 + 52) |= 1 << (char)result;
        }
      }
    }
  }
  else
  {
    v20 = log_message_level(v5, a2, &v37);
    v21 = v20;
    if ( v20 )
    {
      v22 = v37;
      v23 = bswap32(*((volatile uint32_t *)v20 + 2));
      *(volatile uint32_t *)(a4 + 48) = 2;
      result = (volatile uint8_t *)is_factory_mode_b(v23);
      if ( result )
      {
        result = (volatile uint8_t *)((1 << (char)result) | *(volatile uint16_t *)(a4 + 52));
        *(volatile uint16_t *)(a4 + 52) = (uint16_t)result;
      }
      v24 = *((volatile uint16_t *)v21 + 6);
      v25 = v22 - 12;
      for ( j = (volatile unsigned int *)(v21 + 14); v24 && v25 > 3; --v24 )
      {
        result = (volatile uint8_t *)is_factory_mode_b(bswap32(*j));
        v25 -= 4;
        ++j;
        if ( result )
        {
          result = (volatile uint8_t *)((1 << (char)result) | *(volatile uint16_t *)(a4 + 54));
          *(volatile uint16_t *)(a4 + 54) = (uint16_t)result;
        }
      }
      if ( v25 > 1 )
      {
        v27 = (volatile unsigned int *)((volatile char *)j + 2);
        v28 = *(volatile uint16_t *)j;
        if ( *(volatile uint16_t *)j )
        {
          if ( v25 > 5 )
          {
            v29 = (unsigned int)j + ((v25 - 6) & 0xFFFFFFFC) + 6;
            do
            {
              result = (volatile uint8_t *)is_factory_mode_a((volatile char *)bswap32(*v27++));
              if ( result )
              {
                result = (volatile uint8_t *)((1 << (char)result) | *(volatile uint32_t *)(a4 + 48));
                *(volatile uint32_t *)(a4 + 48) = (int)(uintptr_t)(result);
              }
              --v28;
            }
            while ( v28 && v27 != (volatile unsigned int *)v29 );
          }
        }
      }
    }
    else
    {
      result = check_buf_range_12d8bc(v5, a2, &v37);
      if ( !result )
      {
        *(volatile uint32_t *)(a4 + 48) = 2;
        *(volatile uint16_t *)(a4 + 52) = 1;
        return result;
      }
      v30 = *((volatile uint16_t *)result + 2);
      v31 = v37 - 4;
      v32 = (volatile unsigned int *)(result + 6);
      if ( *((volatile uint16_t *)result + 2) && v31 > 3 )
      {
        do
        {
          result = (volatile uint8_t *)is_factory_mode_a((volatile char *)bswap32(*v32));
          v31 -= 4;
          ++v32;
          if ( result )
          {
            result = (volatile uint8_t *)((1 << (char)result) | *(volatile uint32_t *)(a4 + 48));
            *(volatile uint32_t *)(a4 + 48) = (int)(uintptr_t)(result);
          }
          --v30;
        }
        while ( v30 && v31 > 3 );
      }
      if ( v31 > 1 )
      {
        v35 = *(volatile uint16_t *)v32;
        v33 = (volatile unsigned int *)((volatile char *)v32 + 2);
        v34 = v35;
        v36 = v31 - 2;
        if ( v35 )
        {
          if ( v36 <= 3 )
            return result;
          while ( 1 )
          {
            result = (volatile uint8_t *)is_factory_mode_b(bswap32(*v33));
            v36 -= 4;
            ++v33;
            if ( result )
            {
              result = (volatile uint8_t *)((1 << (char)result) | *(volatile uint16_t *)(a4 + 54));
              *(volatile uint16_t *)(a4 + 54) = (uint16_t)result;
            }
            if ( !--v34 )
              break;
            if ( v36 <= 3 )
              return result;
          }
        }
        if ( v36 > 3 )
        {
          result = (volatile uint8_t *)is_factory_mode_b(bswap32(*v33));
          if ( result )
            goto LABEL_28;
        }
      }
    }
  }
  return result;
}



// util_hex_convert @ 0x137388
/* luna: Selects a scan-confirmation message from the RF mode, queues its payload, and completes packet and HCI command processing. */
int util_hex_convert(int a1) {
  volatile uint16_t *v2; // r4
  volatile uint8_t **v3; // r7
  int16_t v4; // r0
  volatile uint8_t *v5; // r5
  volatile int *v6; // r2
  volatile uint16_t *v7; // r0
  int v8; // r1
  int v9; // r0
  volatile uint32_t *v11; // r3

  if ( *(volatile uint8_t *)off_13745C )
    rf_reg_write_byte(*((volatile uint8_t *)off_13748C + 9));
  v2 = (void *)(uintptr_t)(off_137460);
  v3 = (volatile uint8_t **)off_137464;
  if ( *((volatile uint8_t *)off_137460 + 3850) == 1 )
    v4 = 4099;
  else
    v4 = 4097;
  v5 = (volatile uint8_t *)tx_send_pdu(v4, *((volatile uint16_t *)off_137460 + 1924), 4, 3);
  check_feature_flag(
    8,
    "%s:%d,%d,%d\r\n",
    aScanuConfirm,
    *(volatile uint8_t *)(*(volatile uint32_t *)v2 + 366),
    *((volatile uint8_t *)v2 + 3850),
    a1);
  v6 = (volatile int *)off_137474;
  v7 = (void *)(uintptr_t)(off_137478);
  *(volatile uint32_t *)off_137470 &= ~4u;
  v8 = (uint16_t)*v7;
  v9 = *(volatile uint32_t *)v2;
  *v6 = (HIWORD(*v6) << 16) | v8;
  *v5 = *(volatile uint8_t *)(v9 + 366);
  v5[1] = a1;
  v5[2] = v2[2];
  if ( **v3 == 1 && BYTE1(((volatile uint32_t *)(uintptr_t)off_137480)[47]) )
  {
    v11 = (void *)(uintptr_t)(off_137488);
    *(volatile uint32_t *)off_137484 &= 0xFC0FFFFF;
    *v11 |= 0x400000u;
    *v11 |= 0x200000u;
  }
  tx_process_jump((int)(uintptr_t)((volatile char *)(v9 - 12)));
  *(volatile uint32_t *)v2 = 0;
  rx_process_packet_1((int)v5);
  *((volatile uint32_t *)off_13747C + 1) &= ~0x20u;
  return hci_cmd_preprocess(4u, 0);
}


// clear_shared_mem @ 0x137490
/* luna: Preprocesses HCI command 4 and zeroes the 0xFC0-byte shared-memory region. */
int clear_shared_mem() {
  hci_cmd_preprocess(4u, 0);
  return (int)memset((volatile int *)dword_1374AC, 0, 0xFC0u);
}


// rf_hw_init_2 @ 0x1374b0
/* luna: Searches the RF state table for an entry matching three 16-bit key fields, optionally marking and returning the first free slot. */
int rf_hw_init_2(volatile uint16_t *a1, int a2) {
  int v2; // r3
  int v3; // r4

  v2 = dword_1374FC;
  v3 = dword_1374FC + 3840;
  do
  {
    while ( !*(volatile uint8_t *)v2 )
    {
      if ( a2 )
      {
        *(volatile uint8_t *)(v2 + 56) = 0x80;
        return v2;
      }
LABEL_3:
      v2 += 60;
      if ( v2 == v3 )
        return 0;
    }
    if ( *(volatile uint16_t *)(v2 + 2) != *a1 || *(volatile uint16_t *)(v2 + 4) != a1[1] )
      goto LABEL_3;
    if ( *(volatile uint16_t *)(v2 + 6) == a1[2] )
      return v2;
    v2 += 60;
  }
  while ( v2 != v3 );
  return 0;
}



// rf_control_cmd @ 0x137500
int rf_control_cmd(volatile uint16_t *a1) {
  volatile uint8_t *v1; // r11
  char v3; // r3
  char v4; // r1
  char v5; // r2
  char v6; // r0
  char v7; // r1
  char v8; // r2
  uint16_t v9; // r0
  int v10; // r4
  int16_t v11; // r3
  int16_t v12; // r2
  volatile uint8_t *v13; // r0
  volatile uint8_t *v14; // r6
  volatile uint8_t *v15; // r4
  volatile uint8_t *v16; // r10
  volatile uint8_t *v17; // r0
  volatile uint8_t *v18; // r7
  int v19; // r3
  int v20; // r5
  volatile uint8_t *v21; // r9
  volatile uint8_t *v22; // r0
  volatile uint8_t *v23; // r11
  int v24; // r8
  volatile uint8_t *v25; // r7
  volatile uint8_t *v26; // r0
  int v27; // r5
  int v28; // r6
  int v29; // r1
  volatile uint8_t *v30; // r3
  volatile uint8_t *v31; // r2
  volatile uint8_t *v33; // r3
  volatile uint8_t *v34; // r1
  int v35; // r3
  int v36; // r2
  volatile uint8_t *v37; // r3
  int16_t v38; // r1
  volatile uint8_t *v39; // r0
  volatile uint8_t *v40; // r0
  int v41; // r1
  int v42; // r0
  int v43; // r1
  volatile char *v44; // r0
  int v45; // r5
  int v46; // r3
  int v47; // r0
  int v48; // r6
  char v49; // r9
  int v50; // r8
  volatile uint16_t *v51; // r7
  int v52; // r1
  int v53; // r2
  int v54; // r3
  int v55; // r1
  int v56; // r2
  int v57; // r3
  int v58; // r1
  int v59; // r2
  unsigned int v60; // r3
  int v61; // r1
  int v62; // r2
  int v63; // r3
  const volatile char *v64; // r4
  int v65; // r5
  volatile uint16_t *v66; // r10
  volatile uint32_t *v67; // r4
  int16_t v68; // lr
  unsigned int v69; // r7
  int v70; // r8
  int v71; // r12
  int v72; // r2
  volatile uint16_t *v73; // r3
  int v74; // r1
  int v75; // r2
  int v76; // r3
  int v77; // r1
  int v78; // r2
  int v79; // r3
  int v80; // r1
  int v81; // r2
  unsigned int v82; // r3
  int v83; // r1
  int v84; // r2
  unsigned int v85; // r2
  volatile uint16_t *v86; // r1
  int v87; // r0
  int v88; // r12
  int v89; // r1
  int v90; // r2
  int v91; // r3
  int v92; // r1
  int v93; // r2
  int v94; // r3
  int v95; // r1
  int v96; // r2
  unsigned int v97; // r3
  int v98; // r1
  int v99; // r2
  int v100; // r0
  int v101; // r1
  int v102; // r2
  int v103; // r3
  int v104; // r1
  int v105; // r2
  int v106; // r3
  int v107; // r1
  int v108; // r2
  int v109; // r3
  int v110; // r1
  int v111; // r2
  int v112; // r1
  int v113; // r8
  int v114; // r1
  int v115; // r3
  uint16_t v116; // r1
  int v117; // r1
  char v118; // r2
  volatile uint16_t **v119; // r3
  int v120; // r1
  int v121; // r2
  int v122; // r3
  volatile uint16_t *v123; // lr
  int v124; // r1
  int v125; // r2
  int v126; // r3
  int v127; // r1
  int v128; // r2
  unsigned int v129; // r3
  int v130; // r1
  int v131; // r2
  struct __attribute__((packed)) { volatile uint16_t *v132; // [sp+1Ch] [bp-98h]
  int v133; // [sp+20h] [bp-94h]
  volatile uint8_t *v134; // [sp+24h] [bp-90h]
  volatile uint8_t *v135; // [sp+28h] [bp-8Ch]
  int v136; // [sp+2Ch] [bp-88h]
  char _pad5[4]; int a2; // [sp+34h] [bp-80h]
  int v139; // [sp+38h] [bp-7Ch]
  volatile uint16_t *v140; // [sp+3Ch] [bp-78h]
  char _pad8[7]; uint8_t a3; // [sp+47h] [bp-6Dh] BYREF
  uint16_t v142; // [sp+48h] [bp-6Ch] BYREF
  uint16_t v143; // [sp+4Ah] [bp-6Ah]
  uint16_t v144; // [sp+4Ch] [bp-68h]
  char _pad12[2]; uint8_t v145[4]; // [sp+50h] [bp-64h] BYREF
  int16_t v146; // [sp+54h] [bp-60h]
  char _pad14[30]; int v147; // [sp+74h] [bp-40h] BYREF
  int v148; // [sp+78h] [bp-3Ch]
  uint8_t a1a[4]; // [sp+7Ch] [bp-38h] BYREF
  int v150; // [sp+80h] [bp-34h]
  int v151; // [sp+84h] [bp-30h]
  int v152; // [sp+88h] [bp-2Ch]
  int v153; // [sp+8Ch] [bp-28h]
  int v154; // [sp+90h] [bp-24h]
  int v155; // [sp+94h] [bp-20h]
  int v156; // [sp+98h] [bp-1Ch]
  int v157; // [sp+9Ch] [bp-18h]
  unsigned int v158; // [sp+A0h] [bp-14h]
  int v159; // [sp+A4h] [bp-10h]
  int v160; // [sp+A8h] [bp-Ch]
  int v161; // [sp+ACh] [bp-8h]
  char v162; // [sp+B0h] [bp-4h] BYREF
  } _frame;
  v1 = (void *)(uintptr_t)(off_137944);
  v3 = *((volatile uint8_t *)off_137944 + 3852);
  v4 = *((volatile uint8_t *)a1 + 29);
  v5 = *((volatile uint8_t *)a1 + 30);
  _frame.v142 = (_frame.v142 & ~0xFFu) | ((uint8_t)(*((volatile uint8_t *)a1 + 28)) & 0xFFu);
  _frame.v142 = (_frame.v142 & ~0xFF00u) | (((uint8_t)(v4) & 0xFFu) << 8);
  v6 = *((volatile uint8_t *)a1 + 31);
  v7 = *((volatile uint8_t *)a1 + 32);
  _frame.v143 = (_frame.v143 & ~0xFFu) | ((uint8_t)(v5) & 0xFFu);
  v8 = *((volatile uint8_t *)a1 + 33);
  _frame.v144 = (_frame.v144 & ~0xFFu) | ((uint8_t)(v7) & 0xFFu);
  _frame.v143 = (_frame.v143 & ~0xFF00u) | (((uint8_t)(v6) & 0xFFu) << 8);
  _frame.v144 = (_frame.v144 & ~0xFF00u) | (((uint8_t)(v8) & 0xFFu) << 8);
  _frame.v139 = v3 & 1;
  if ( (v3 & 1) != 0 )
  {
    v9 = _frame.v143;
    v10 = (v10 & ~0xFFFFu) | ((uint16_t)(_frame.v144) & 0xFFFFu);
    _frame.v139 = 0;
  }
  else if ( *((volatile uint16_t *)off_137944 + 1926) != _frame.v142
         || (v9 = _frame.v143, *((volatile uint16_t *)off_137944 + 1927) != _frame.v143)
         || (v10 = *((volatile uint16_t *)off_137944 + 1928), _frame.v144 != v10) )
  {
    if ( !LOBYTE(((volatile uint32_t *)(uintptr_t)off_137934)[102]) || *((volatile uint8_t *)off_137944 + 3850) )
      return 0;
    v9 = _frame.v143;
    v10 = (v10 & ~0xFFFFu) | ((uint16_t)(_frame.v144) & 0xFFFFu);
    _frame.v139 = 1;
  }
  v11 = a1[23];
  v12 = *a1;
  _frame.v147 = (_frame.v147 & ~0xFFFF0000u) | (((uint16_t)(_frame.v142) & 0xFFFFu) << 16);
  _frame.v148 = (_frame.v148 & ~0xFFFFu) | ((uint16_t)(v9) & 0xFFFFu);
  _frame.v140 = a1 + 24;
  _frame.a2 = (uint16_t)(v12 - 36);
  _frame.v148 = (_frame.v148 & ~0xFFFF0000u) | (((uint16_t)(v10) & 0xFFFFu) << 16);
  _frame.v157 = (_frame.v157 & ~0xFFFF0000u) | (((uint16_t)(2 - (v11 & 1)) & 0xFFFFu) << 16);
  v13 = check_buf_range_12d7d8((volatile uint8_t *)a1 + 48, _frame.a2, &_frame.a3);
  if ( v13 )
  {
    _frame.a1a[0] = _frame.a3;
    if ( _frame.a3 )
    {
      v33 = _frame.a1a;
      v34 = &_frame.a1a[_frame.a3];
      do
      {
        v33[1] = v33[(uint32_t)v13 + 54 - (uint32_t)&_frame.v162];
        ++v33;
      }
      while ( v34 != v33 );
    }
  }
  else
  {
    _frame.a1a[0] = 0;
  }
  v14 = nullptr;
  v1[4029] = 0;
  if ( _frame.a2 )
  {
    _frame.v133 = _frame.a2;
    _frame.v132 = a1 + 24;
    v15 = nullptr;
    v16 = nullptr;
    _frame.v134 = v1;
    while ( 1 )
    {
      v17 = test_arg2_one_12dc08((void *)(_frame.v132), _frame.v133);
      v18 = v17;
      if ( !v17 )
        goto LABEL_18;
      v19 = (uint8_t)v17[1];
      _frame.v134[4028] = v17[2];
      v20 = (uint16_t)(v19 - 1);
      _frame.v136 = v19 + 2;
      v21 = v17 + 3;
      if ( (uint16_t)v19 == 1 )
        goto LABEL_17;
      _frame.v135 = v17;
      while ( 1 )
      {
        v22 = test_arg2_one_12dc48(v21, v20);
        v23 = v22;
        if ( !v22 )
          break;
        v24 = v22[1];
        v25 = v22 + 2;
        v20 = (uint16_t)(v20 - (v24 + 2));
        v21 += v24 + 2;
        if ( test_arg2_one_12dc90(v22 + 2, 4) )
        {
          v16 = v23 + 4;
          v15 = sub_12DCD0(v25, v24);
          goto LABEL_13;
        }
        if ( v16 )
        {
          if ( v15 )
          {
            if ( !v14 )
            {
              v14 = check_buf_range_12d7d8(v25, v24, _frame.v145);
              if ( !v14 )
                goto LABEL_15;
            }
            goto LABEL_40;
          }
          v39 = sub_12DCD0(v25, v24);
          v15 = v39;
          if ( v14 )
          {
            if ( v39 )
              goto LABEL_40;
            if ( !v20 )
              break;
          }
          else
          {
LABEL_13:
            v26 = check_buf_range_12d7d8(v25, v24, _frame.v145);
            v14 = v26;
            if ( !v15 || !v26 )
              goto LABEL_15;
LABEL_40:
            v35 = (uint8_t)_frame.v134[4029];
            v36 = (uint8_t)(v35 + 1);
            v37 = &_frame.v134[8 * v35];
            v38 = *v16 | (v16[1] << 8);
            v37[3906] = v15[2];
            *((volatile uint32_t *)v37 + 975) = (int)(uintptr_t)(v14);
            *((volatile uint16_t *)v37 + 1952) = v38;
            _frame.v134[4029] = v36;
            if ( v36 == 16 )
              goto LABEL_18;
            v16 = nullptr;
            if ( !v20 )
              break;
          }
        }
        else
        {
LABEL_15:
          if ( !v20 )
            break;
        }
      }
      v18 = _frame.v135;
LABEL_17:
      _frame.v133 = (uint16_t)(_frame.v133 + (uint16_t)_frame.v132 - (uint16_t)v18 - _frame.v136);
      _frame.v132 = (volatile uint16_t *)&v18[_frame.v136];
      if ( !_frame.v133 )
      {
LABEL_18:
        v1 = _frame.v134;
        break;
      }
    }
  }
  if ( !_frame.v139 && !rf_task_state_handler(_frame.a1a) )
  {
    if ( !v1[4029] )
      return 0;
    v27 = dword_137930;
    v28 = 0;
    while ( 1 )
    {
      v29 = *(volatile uint32_t *)(v27 + 8 * v28);
      _frame.v145[0] = *(volatile uint8_t *)(v29 + 1);
      if ( _frame.v145[0] )
      {
        v30 = _frame.v145;
        v31 = &_frame.v145[_frame.v145[0]];
        do
        {
          v30[1] = v30[v29 + 98 - (uint32_t)&_frame.v162];
          ++v30;
        }
        while ( v31 != v30 );
      }
      if ( rf_task_state_handler(_frame.v145) )
        break;
      if ( ++v28 >= (uint8_t)v1[4029] )
        return 0;
    }
  }
  v40 = test_arg2_one_12da20((void *)(_frame.v140), _frame.a2);
  if ( v40 )
  {
    v41 = (uint8_t)v40[2];
    v42 = *((volatile uint8_t *)a1 + 6);
    if ( *((volatile uint8_t *)a1 + 6) )
    {
      if ( v42 == 1 && (uint8_t)(v41 - 1) <= 0xB0u )
      {
LABEL_53:
        v43 = 5 * v41 + 5000;
LABEL_56:
        v44 = is_adv_enabled(v42, v43);
        v45 = 1;
        _frame.v158 = (unsigned int)v44;
        goto LABEL_57;
      }
LABEL_55:
      v43 = 0;
      goto LABEL_56;
    }
LABEL_54:
    if ( (unsigned int)(v41 - 1) <= 0xD )
    {
      if ( v41 == 14 )
        v43 = 2484;
      else
        v43 = 5 * v41 + 2407;
      goto LABEL_56;
    }
    goto LABEL_55;
  }
  v45 = (int)test_arg2_one_12dd78((void *)(_frame.v140), _frame.a2);
  if ( v45 )
  {
    v42 = *((volatile uint8_t *)a1 + 6);
    v41 = *(volatile uint8_t *)(v45 + 2);
    if ( *((volatile uint8_t *)a1 + 6) )
    {
      if ( v42 != 1 || (uint8_t)(v41 - 1) > 0xB0u )
      {
        v43 = 0;
        goto LABEL_56;
      }
      goto LABEL_53;
    }
    goto LABEL_54;
  }
  v44 = is_adv_enabled(*((volatile uint8_t *)a1 + 6), (uint16_t)a1[2]);
  _frame.v158 = (unsigned int)v44;
LABEL_57:
  v46 = *(volatile uint16_t *)v44;
  if ( (uint16_t)a1[2] != v46 )
    a1[2] = v46;
  rf_set_antenna_cfg((void *)(uintptr_t)((int)_frame.v140), _frame.a2, (uint16_t)a1[23], (int)&_frame.v147);
  v47 = rf_hw_init_2(&_frame.v142, 1);
  v48 = v47;
  if ( !v47 )
    goto LABEL_79;
  v49 = *(volatile uint8_t *)v47;
  v50 = *((volatile char *)a1 + 9);
  v51 = (volatile uint16_t *)_frame.v158;
  if ( *(volatile uint8_t *)v47 )
  {
    if ( *(volatile uint8_t *)(v47 + 8) != _frame.a1a[0] )
    {
      if ( *(volatile uint8_t *)(v47 + 8) && !_frame.a1a[0] )
      {
        v50 = (v50 & ~0xFFu) | ((uint8_t)(*(volatile uint8_t *)(v47 + 56)) & 0xFFu);
        v51 = *(volatile uint16_t **)(v47 + 44);
      }
      goto LABEL_63;
    }
    v87 = memcmp(*(volatile uint32_t *)(v47 + 44), _frame.v158, 6u);
    if ( *(volatile uint8_t *)(v48 + 8) == _frame.a1a[0] )
    {
      v88 = *(volatile char *)(v48 + 56);
      if ( v88 > v50 )
      {
LABEL_93:
        v51 = *(volatile uint16_t **)(v48 + 44);
        v50 = (v50 & ~0xFFu) | ((uint8_t)(v88) & 0xFFu);
        if ( !v87 )
        {
          v89 = _frame.v148;
          v90 = *(volatile uint32_t *)_frame.a1a;
          v91 = _frame.v150;
          *(volatile uint32_t *)v48 = _frame.v147;
          *(volatile uint32_t *)(v48 + 4) = v89;
          *(volatile uint32_t *)(v48 + 8) = v90;
          *(volatile uint32_t *)(v48 + 12) = v91;
          v92 = _frame.v152;
          v93 = _frame.v153;
          v94 = _frame.v154;
          *(volatile uint32_t *)(v48 + 16) = _frame.v151;
          *(volatile uint32_t *)(v48 + 20) = v92;
          *(volatile uint32_t *)(v48 + 24) = v93;
          *(volatile uint32_t *)(v48 + 28) = v94;
          v95 = _frame.v156;
          v96 = _frame.v157;
          v97 = _frame.v158;
          *(volatile uint32_t *)(v48 + 32) = _frame.v155;
          *(volatile uint32_t *)(v48 + 36) = v95;
          *(volatile uint32_t *)(v48 + 40) = v96;
          *(volatile uint32_t *)(v48 + 44) = v97;
          v98 = _frame.v160;
          v99 = _frame.v161;
          *(volatile uint32_t *)(v48 + 48) = _frame.v159;
          *(volatile uint32_t *)(v48 + 52) = v98;
          *(volatile uint32_t *)(v48 + 56) = v99;
          *(volatile uint8_t *)(v48 + 56) = v88;
          *(volatile uint32_t *)(v48 + 44) = (int)(uintptr_t)(v51);
          *(volatile uint8_t *)v48 = v49;
          goto LABEL_68;
        }
        goto LABEL_63;
      }
    }
    if ( *(volatile uint8_t *)(v48 + 8) && !_frame.a1a[0] )
    {
      v88 = (v88 & ~0xFFu) | ((uint8_t)(*(volatile uint8_t *)(v48 + 56)) & 0xFFu);
      goto LABEL_93;
    }
    if ( v87 )
    {
LABEL_63:
      v52 = _frame.v148;
      v53 = *(volatile uint32_t *)_frame.a1a;
      v54 = _frame.v150;
      *(volatile uint32_t *)v48 = _frame.v147;
      *(volatile uint32_t *)(v48 + 4) = v52;
      *(volatile uint32_t *)(v48 + 8) = v53;
      *(volatile uint32_t *)(v48 + 12) = v54;
      v55 = _frame.v152;
      v56 = _frame.v153;
      v57 = _frame.v154;
      *(volatile uint32_t *)(v48 + 16) = _frame.v151;
      *(volatile uint32_t *)(v48 + 20) = v55;
      *(volatile uint32_t *)(v48 + 24) = v56;
      *(volatile uint32_t *)(v48 + 28) = v57;
      v58 = _frame.v156;
      v59 = _frame.v157;
      v60 = _frame.v158;
      *(volatile uint32_t *)(v48 + 32) = _frame.v155;
      *(volatile uint32_t *)(v48 + 36) = v58;
      *(volatile uint32_t *)(v48 + 40) = v59;
      *(volatile uint32_t *)(v48 + 44) = v60;
      v61 = _frame.v160;
      v62 = _frame.v161;
      *(volatile uint32_t *)(v48 + 48) = _frame.v159;
      *(volatile uint32_t *)(v48 + 52) = v61;
      *(volatile uint32_t *)(v48 + 56) = v62;
      *(volatile uint8_t *)(v48 + 56) = v50;
      *(volatile uint32_t *)(v48 + 44) = (int)(uintptr_t)(v51);
      *(volatile uint8_t *)v48 = v49;
      goto LABEL_64;
    }
    v120 = _frame.v148;
    v121 = *(volatile uint32_t *)_frame.a1a;
    v122 = _frame.v150;
    v123 = *(volatile uint16_t **)(v48 + 44);
    *(volatile uint32_t *)v48 = _frame.v147;
    *(volatile uint32_t *)(v48 + 4) = v120;
    *(volatile uint32_t *)(v48 + 8) = v121;
    *(volatile uint32_t *)(v48 + 12) = v122;
    v124 = _frame.v152;
    v125 = _frame.v153;
    v126 = _frame.v154;
    *(volatile uint32_t *)(v48 + 16) = _frame.v151;
    *(volatile uint32_t *)(v48 + 20) = v124;
    *(volatile uint32_t *)(v48 + 24) = v125;
    *(volatile uint32_t *)(v48 + 28) = v126;
    v127 = _frame.v156;
    v128 = _frame.v157;
    v129 = _frame.v158;
    *(volatile uint32_t *)(v48 + 32) = _frame.v155;
    *(volatile uint32_t *)(v48 + 36) = v127;
    *(volatile uint32_t *)(v48 + 40) = v128;
    *(volatile uint32_t *)(v48 + 44) = v129;
    v130 = _frame.v160;
    v131 = _frame.v161;
    *(volatile uint32_t *)(v48 + 48) = _frame.v159;
    *(volatile uint32_t *)(v48 + 52) = v130;
    *(volatile uint32_t *)(v48 + 56) = v131;
    *(volatile uint8_t *)(v48 + 56) = v50;
    *(volatile uint32_t *)(v48 + 44) = (int)(uintptr_t)(v51);
    *(volatile uint8_t *)v48 = v49;
    if ( v123 == v51 )
      goto LABEL_68;
  }
  else
  {
    v74 = _frame.v148;
    v75 = *(volatile uint32_t *)_frame.a1a;
    v76 = _frame.v150;
    *(volatile uint32_t *)v47 = _frame.v147;
    *(volatile uint32_t *)(v47 + 4) = v74;
    *(volatile uint32_t *)(v47 + 8) = v75;
    *(volatile uint32_t *)(v47 + 12) = v76;
    v77 = _frame.v152;
    v78 = _frame.v153;
    v79 = _frame.v154;
    *(volatile uint32_t *)(v47 + 16) = _frame.v151;
    *(volatile uint32_t *)(v47 + 20) = v77;
    *(volatile uint32_t *)(v47 + 24) = v78;
    *(volatile uint32_t *)(v47 + 28) = v79;
    v80 = _frame.v156;
    v81 = _frame.v157;
    v82 = _frame.v158;
    *(volatile uint32_t *)(v47 + 32) = _frame.v155;
    *(volatile uint32_t *)(v47 + 36) = v80;
    *(volatile uint32_t *)(v47 + 40) = v81;
    *(volatile uint32_t *)(v47 + 44) = v82;
    v83 = _frame.v160;
    v84 = _frame.v161;
    *(volatile uint32_t *)(v47 + 48) = _frame.v159;
    *(volatile uint32_t *)(v47 + 52) = v83;
    *(volatile uint32_t *)(v47 + 56) = v84;
    *(volatile uint8_t *)(v47 + 56) = v50;
    *(volatile uint32_t *)(v47 + 44) = (int)(uintptr_t)(v51);
    ++*((volatile uint16_t *)v1 + 2);
    *(volatile uint8_t *)v47 = 1;
    v85 = *((volatile uint8_t *)v51 + 2);
    if ( v85 <= 1 )
    {
      v63 = *(volatile uint8_t *)(v47 + 8);
      if ( !*(volatile uint8_t *)(v47 + 8) )
      {
        if ( (**(volatile uint16_t **)off_137BB8 & 8) == 0 )
          goto LABEL_68;
        v64 = aHidden;
        goto LABEL_67;
      }
      v86 = *(volatile uint16_t **)off_137BB8;
      ++*(volatile uint16_t *)(dword_137BB4 + 2 * v85 + 4);
      if ( (*v86 & 8) == 0 )
        goto LABEL_68;
      goto LABEL_84;
    }
  }
LABEL_64:
  if ( (**(volatile uint16_t **)off_137938 & 8) != 0 )
  {
    v63 = *(volatile uint8_t *)(v48 + 8);
    if ( !*(volatile uint8_t *)(v48 + 8) )
    {
      v51 = *(volatile uint16_t **)(v48 + 44);
      v50 = *((volatile char *)a1 + 9);
      v64 = aHidden;
LABEL_67:
      alloc_tx_event(
        " %d %d %x 0x%x %d %d %x %s\n",
        *((volatile uint16_t *)v1 + 2),
        *v51,
        v45,
        *((volatile uint8_t *)a1 + 12),
        (uint16_t)a1[17] >> 4,
        v50,
        v63,
        v64);
      goto LABEL_68;
    }
LABEL_84:
    v64 = (const volatile char *)(v48 + 9);
    if ( memcpy_aligned(v48 + 9) )
    {
      v63 = *(volatile uint8_t *)(v48 + 8);
      *(volatile uint8_t *)(v48 + v63 + 9) = 0;
      v51 = *(volatile uint16_t **)(v48 + 44);
      v50 = *((volatile char *)a1 + 9);
    }
    else
    {
      v51 = *(volatile uint16_t **)(v48 + 44);
      v50 = *((volatile char *)a1 + 9);
      v64 = aHidden;
      v63 = *(volatile uint8_t *)(v48 + 8);
    }
    goto LABEL_67;
  }
LABEL_68:
  v65 = 0;
  *(volatile uint8_t *)(v48 + 57) = 0;
  *(volatile uint8_t *)(v48 + 58) = 0;
  v66 = (volatile uint16_t *)off_137944;
  if ( v1[4029] )
  {
    v67 = (void *)(uintptr_t)(off_137944);
    while ( 2 )
    {
      v68 = *((volatile uint8_t *)v67 + 3906);
      if ( *((volatile uint8_t *)v67 + 3906) )
      {
        v69 = *((volatile uint8_t *)v66 + 4028);
        if ( v69 <= 8 )
        {
          v70 = *(volatile uint8_t *)(v67[975] + 1);
          *(volatile uint32_t *)_frame.v145 = *(volatile uint32_t *)(v48 + 2);
          _frame.v146 = *(volatile uint16_t *)(v48 + 6);
          v71 = (1 << v69) - 1;
          v72 = (uint16_t)(_frame.v146 ^ ((*(volatile uint16_t *)(v48 + 6) + (v68 << 8)) ^ _frame.v146) & ((uint16_t)v71 << 8));
          _frame.v146 ^= ((*(volatile uint16_t *)(v48 + 6) + (v68 << 8)) ^ _frame.v146) & (uint16_t)((uint16_t)v71 << 8);
          v73 = v66;
          do
          {
            if ( *((volatile uint8_t *)v73 + 8)
              && v73[5] == *(volatile uint16_t *)_frame.v145
              && v73[6] == *(volatile uint16_t *)&_frame.v145[2]
              && v73[7] == v72 )
            {
              goto LABEL_78;
            }
            v73 += 30;
          }
          while ( v66 + 1920 != v73 );
          v100 = rf_hw_init_2((volatile uint16_t *)_frame.v145, 1);
          if ( !v100 )
            break;
          v101 = *(volatile uint32_t *)(v48 + 4);
          v102 = *(volatile uint32_t *)(v48 + 8);
          v103 = *(volatile uint32_t *)(v48 + 12);
          *(volatile uint32_t *)v100 = *(volatile uint32_t *)v48;
          *(volatile uint32_t *)(v100 + 4) = v101;
          *(volatile uint32_t *)(v100 + 8) = v102;
          *(volatile uint32_t *)(v100 + 12) = v103;
          v104 = *(volatile uint32_t *)(v48 + 20);
          v105 = *(volatile uint32_t *)(v48 + 24);
          v106 = *(volatile uint32_t *)(v48 + 28);
          *(volatile uint32_t *)(v100 + 16) = *(volatile uint32_t *)(v48 + 16);
          *(volatile uint32_t *)(v100 + 20) = v104;
          *(volatile uint32_t *)(v100 + 24) = v105;
          *(volatile uint32_t *)(v100 + 28) = v106;
          v107 = *(volatile uint32_t *)(v48 + 36);
          v108 = *(volatile uint32_t *)(v48 + 40);
          v109 = *(volatile uint32_t *)(v48 + 44);
          *(volatile uint32_t *)(v100 + 32) = *(volatile uint32_t *)(v48 + 32);
          *(volatile uint32_t *)(v100 + 36) = v107;
          *(volatile uint32_t *)(v100 + 40) = v108;
          *(volatile uint32_t *)(v100 + 44) = v109;
          v110 = *(volatile uint32_t *)(v48 + 52);
          v111 = *(volatile uint32_t *)(v48 + 56);
          *(volatile uint32_t *)(v100 + 48) = *(volatile uint32_t *)(v48 + 48);
          *(volatile uint32_t *)(v100 + 52) = v110;
          *(volatile uint32_t *)(v100 + 56) = v111;
          *(volatile uint32_t *)(v100 + 2) = *(volatile uint32_t *)_frame.v145;
          v109 = (v109 & ~0xFFFFu) | ((uint16_t)(_frame.v146) & 0xFFFFu);
          *(volatile uint8_t *)(v100 + 8) = v70;
          v112 = v67[975];
          *(volatile uint16_t *)(v100 + 6) = v109;
          if ( v70 )
          {
            v113 = v70 + 8 + v100;
            v114 = v112 - 6 - v100;
            v115 = v100 + 8;
            do
            {
              *(volatile uint8_t *)(v115 + 1) = *(volatile uint8_t *)(v114 + v115);
              ++v115;
            }
            while ( v115 != v113 );
          }
          v116 = v66[2];
          *(volatile uint8_t *)(v100 + 58) = v69;
          v117 = (uint16_t)(v116 + 1);
          v118 = *((volatile uint8_t *)v67 + 3906);
          v66[2] = v117;
          *(volatile uint8_t *)v100 = 1;
          v119 = (volatile uint16_t **)off_137BB8;
          *(volatile uint8_t *)(v100 + 57) = v118;
          if ( (**v119 & 8) == 0 )
          {
LABEL_78:
            ++v65;
            v67 += 2;
            if ( v65 < *((volatile uint8_t *)v66 + 4029) )
              continue;
            break;
          }
          *(volatile uint8_t *)(*(volatile uint8_t *)(v48 + 8) + v100 + 9) = 0;
          alloc_tx_event(
            " %d %d %x %s\n",
            v117,
            **(volatile uint16_t **)(v100 + 44),
            *(volatile uint8_t *)(v100 + 8),
            (const volatile char *)(v100 + 9));
          ++v65;
          v67 += 2;
          if ( v65 < *((volatile uint8_t *)v66 + 4029) )
            continue;
        }
      }
      break;
    }
  }
LABEL_79:
  if ( _frame.v139 )
    return 0;
  nop_function((int)a1, 4100, 13, 4);
  return 1;
}


// rf_check_status @ 0x1380d8
/* luna: Scans the 64-entry RF table for an active entry whose three 16-bit fields match the supplied values and returns its address, or zero if none matches. */
int rf_check_status(volatile uint16_t *a1) {
  int current_entry; // r3
  int table_end; // r1

  current_entry = dword_138130;
  table_end = dword_138130 + 3840;
  while ( !*(volatile uint8_t *)current_entry )
  {
    current_entry += 60;
    if ( current_entry == table_end )
      return 0;
  }
  if ( *(volatile uint16_t *)(current_entry + 2) == *a1 )
    goto LABEL_7;
  while ( 1 )
  {
    current_entry += 60;
    if ( current_entry == table_end )
      break;
    if ( *(volatile uint8_t *)current_entry && *(volatile uint16_t *)(current_entry + 2) == *a1 )
    {
LABEL_7:
      if ( *(volatile uint16_t *)(current_entry + 4) == a1[1] && *(volatile uint16_t *)(current_entry + 6) == a1[2] )
        return current_entry;
    }
  }
  return 0;
}



// get_object_state @ 0x138134
/* luna: Finds the active RF table entry matching a length-prefixed key with the greatest signed priority and returns its state-field address, or NULL if none  */
volatile uint8_t * get_object_state(volatile uint8_t *a1) {
  volatile uint8_t *v1; // r4
  volatile uint8_t *v3; // r8
  int v4; // r6
  int v5; // r5
  volatile uint8_t *v6; // r9
  int v7; // r2

  if ( !*a1 )
    return (volatile uint8_t *)*a1;
  v1 = (volatile uint8_t *)dword_138198;
  v3 = 0;
  v4 = dword_138198 + 3840;
  v5 = -128;
  v6 = a1 + 1;
while ( v1[8] ) { if ( (char)v1[64] <= v5 || (v7 = *a1, v7 != (uint8_t)v1[16]) || memcmp((int)(uintptr_t)(v1 + 17), (int)(uintptr_t)(v6), v7) ) { v1 += 60;
      if ( v1 == (volatile uint8_t *)v4 )
        return v3;
    }
    else
    {
      v5 = (char)v1[64];
      v3 = v1 + 8;
      v1 += 60;
      if ( v1 == (volatile uint8_t *)v4 )
        return v3;
    }
  }
  return v3;
}



// check_event_flag_1 @ 0x13819c
/* luna: Searches the context’s six-byte records for the current state, retries with state 1 after a miss, and submits a 0x178-byte PDU when a record matches. */
volatile uint32_t *check_event_flag_1() {
  volatile uint8_t *v0; // r5
  unsigned int v1; // r1
  int v2; // r6
  int v3; // r7
  int v4; // r3
  int v5; // r4
  int v6; // r2
  int v7; // r0
  int v8; // r7
  uint64_t v9; // r0
  int v10; // r0
  int v11; // r8
  int v12; // r4
  int v13; // r1
  int v14; // r3
  int v15; // r2
  int v16; // r1
  int v17; // r10
  volatile int *v18; // r3
  volatile uint32_t *v19; // r2
  int v20; // r12
  int v21; // r4
  int v22; // r0
  volatile uint8_t *v23; // lr
  unsigned int v24; // r1
  volatile uint8_t *v25; // r4
  volatile uint8_t *v26; // r6
  volatile char *v27; // r3
  volatile char *v28; // r2
  volatile char *v29; // r2
  volatile char *v30; // r12
  char v31; // t1
  volatile uint8_t *v32; // r3
  volatile uint8_t *v33; // r3
  volatile char *v34; // r2
  volatile uint8_t *v35; // r3
  int v36; // r8
  volatile uint8_t *v37; // r3
  volatile uint8_t *v38; // r12
  char v39; // t1
  volatile uint8_t *v40; // r3
  volatile uint8_t *v41; // r3
  int v42; // r2
  volatile uint8_t *v43; // r8
  int v44; // r0
  volatile uint8_t *v45; // r3
  volatile uint8_t *v46; // r6
  volatile uint8_t *v47; // r0
  char v48; // r3
  int v49; // r2
  volatile uint16_t *v50; // r5
  int v51; // r2
  unsigned int v52; // r3
  int v54; // r2
  int v55; // r6
  volatile char *v56; // r0
  volatile uint8_t *v57; // r12
  char v58; // t1
  int v59; // r12
  volatile uint8_t *v60; // r3
  volatile uint8_t *v61; // lr
  volatile uint8_t *v62; // r0
  char v63; // r2
  struct __attribute__((packed)) { unsigned int v64; // [sp+4h] [bp-Ch]
  char _pad1[4]; int v65; // [sp+Ch] [bp-4h] BYREF
  } _frame;
  v0 = (volatile uint8_t *)off_1384B8;
  v1 = *((volatile uint8_t *)off_1384B8 + 3851);
  v2 = *(volatile uint32_t *)off_1384B8;
  if ( v1 > 1 )
    return (void *)(uintptr_t)(util_hex_convert(0));
  v3 = 0;
  while ( !*(volatile uint8_t *)(v2 + 367) )
  {
LABEL_59:
    v3 = 1;
    if ( v1 == 1 )
    {
      *((volatile uint8_t *)off_1384B8 + 3851) = 2;
      return (void *)(uintptr_t)(util_hex_convert(0));
    }
    v1 = 1;
  }
  v4 = *(volatile uint32_t *)off_1384B8;
  v5 = 0;
  while ( 1 )
  {
    v6 = *(volatile uint8_t *)(v4 + 2);
    v4 += 6;
    if ( v6 == v1 )
      break;
    if ( ++v5 == *(volatile uint8_t *)(v2 + 367) )
      goto LABEL_59;
  }
  if ( v3 )
    *((volatile uint8_t *)off_1384B8 + 3851) = v1;
  v7 = tx_send_pdu(2048, 2, 4, 0x178u);
  *(volatile uint8_t *)(v7 + 366) = *(volatile uint8_t *)(v2 + 366);
  v8 = v7;
  v9 = *(volatile uint64_t *)(v2 + 352);
  *(volatile uint32_t *)(v8 + 352) = v9;
  *(volatile uint16_t *)(v8 + 356) = WORD2(v9);
  v10 = *(volatile uint8_t *)(v2 + 368);
  *(volatile uint8_t *)(v8 + 368) = v10;
  *(volatile uint8_t *)(v8 + 369) = *(volatile uint8_t *)(v2 + 369);
  *(volatile uint32_t *)(v8 + 372) = *(volatile uint32_t *)(v2 + 372);
  if ( v5 >= *(volatile uint8_t *)(v2 + 367) )
  {
    v11 = v0[3851];
  }
  else
  {
    v11 = v0[3851];
    v12 = v2 + 6 * v5;
    v13 = 6 * *(volatile uint8_t *)(v2 + 367) + v2;
    do
    {
      if ( *(volatile uint8_t *)(v12 + 2) == v11 )
      {
        v14 = *(volatile uint8_t *)(v8 + 367);
        v15 = 3 * v14;
        *(volatile uint32_t *)(v8 + 2 * v15) = *(volatile uint32_t *)v12;
        *(volatile uint16_t *)(v8 + 2 * v15 + 4) = *(volatile uint16_t *)(v12 + 4);
        *(volatile uint8_t *)(v8 + 367) = v14 + 1;
      }
      v12 += 6;
    }
    while ( v12 != v13 );
  }
  if ( v10 )
  {
    v16 = 252;
    v17 = 33 * (int16_t)v10 + 252;
    do
    {
      v18 = (volatile int *)(v2 + v16);
      v19 = (volatile uint32_t *)(v8 + v16);
      do
      {
        v20 = *v18;
        v21 = v18[1];
        v22 = v18[2];
        v19[3] = v18[3];
        v18 += 4;
        *v19 = v20;
        v19[1] = v21;
        v19[2] = v22;
        v19 += 4;
      }
      while ( v18 != (volatile int *)(v2 + v16 + 32) );
      v16 += 33;
      *(volatile uint8_t *)v19 = *(volatile uint8_t *)v18;
    }
    while ( v17 != v16 );
  }
  v23 = (volatile uint8_t *)off_1384D8;
  v24 = *(volatile uint16_t *)(*(volatile uint32_t *)v0 + 364);
  v25 = (void *)(uintptr_t)(off_1384BC);
  if ( v24 >= 0xC9 )
    v24 = 0;
  v26 = (volatile uint8_t *)off_1384D8;
  if ( v11 == 1 )
  {
    v27 = (volatile char *)dword_1384C0;
    v11 = 8;
  }
  else
  {
    v27 = (volatile char *)dword_1384C0;
    if ( *(volatile uint8_t *)(*(volatile uint32_t *)v0 + 369) )
      v11 = 8;
    else
      v27 = (volatile char *)(dword_1384C0 - 4);
    if ( !*(volatile uint8_t *)(*(volatile uint32_t *)v0 + 369) )
      v11 = 12;
  }
  v28 = (volatile char *)off_1384C4;
  *((volatile uint8_t *)off_1384C4 + 20) = 1;
  v29 = v28 + 21;
  v25[1] = 8;
  v30 = v27 + 8;
  do
  {
    v31 = *v27++;
    *++v29 = v31;
  }
  while ( v27 != v30 );
  v32 = (volatile uint8_t *)dword_1384C8;
  _frame.v65 = dword_1384C8;
  if ( v24 )
  {
    v54 = *v23;
    if ( v54 == 10 )
    {
      v55 = (uint8_t)(v23[1] + 2);
      if ( v23[1] != 0xFE )
      {
        v56 = (volatile char *)off_1384D8;
        v57 = (volatile uint8_t *)(dword_1384C8 + v55);
        while ( 1 )
        {
          *v32++ = v54;
          if ( v57 == v32 )
            break;
          v58 = *++v56;
          v54 = (v54 & ~0xFFu) | ((uint8_t)(v58) & 0xFFu);
        }
        v32 = (volatile uint8_t *)_frame.v65;
      }
      _frame.v65 = (int)&v32[v55];
      v24 = (uint16_t)(v24 - v55);
      v26 = &v23[v55];
    }
  }
  if ( v11 != 8 )
  {
    v33 = (volatile uint8_t *)_frame.v65;
    v34 = (volatile char *)dword_1384CC;
    ++_frame.v65;
    *v33 = 50;
    v35 = (volatile uint8_t *)_frame.v65;
    v36 = (uint8_t)(v11 - 8);
    ++_frame.v65;
    *v35 = v36;
    v37 = (volatile uint8_t *)_frame.v65;
    v38 = (volatile uint8_t *)(_frame.v65 + 4);
    do
    {
      v39 = *v34++;
      *v37++ = v39;
    }
    while ( v37 != v38 );
    _frame.v65 += v36;
  }
  if ( !v0[3851] )
  {
    v40 = (volatile uint8_t *)_frame.v65++;
    *v40 = 3;
    v41 = (volatile uint8_t *)_frame.v65++;
    *v41 = 1;
    ++_frame.v65;
  }
  if ( !v24 )
  {
    v43 = (void *)(uintptr_t)(off_1384E4);
    v48 = *((volatile uint8_t *)off_1384E4 + 374);
    if ( (v48 & 1) == 0 )
      goto LABEL_48;
    write_dash_header(&_frame.v65);
LABEL_74:
    v48 = v43[374];
LABEL_48:
    if ( v0[3851] == 1 )
      goto LABEL_44;
LABEL_49:
    if ( (v48 & 4) == 0 )
      goto LABEL_50;
    goto LABEL_46;
  }
  v42 = *v26;
  if ( v42 == 59 )
  {
    v44 = _frame.v65;
    v59 = (uint8_t)(v26[1] + 2);
    if ( v26[1] == 0xFE )
    {
      v43 = (void *)(uintptr_t)(off_138524);
      if ( (*((volatile uint8_t *)off_138524 + 374) & 1) == 0 )
        goto LABEL_40;
    }
    else
    {
      v60 = (volatile uint8_t *)_frame.v65;
      v61 = &v26[-_frame.v65];
      v62 = (volatile uint8_t *)(_frame.v65 + v59);
      while ( 1 )
      {
        *v60++ = v42;
        if ( v62 == v60 )
          break;
        v42 = (v42 & ~0xFFu) | ((uint8_t)(v60[(uint32_t)v61]) & 0xFFu);
      }
      v43 = (void *)(uintptr_t)(off_1384E4);
      v63 = *((volatile uint8_t *)off_1384E4 + 374);
      v24 = (uint16_t)(v24 - v59);
      v26 += v59;
      _frame.v65 += v59;
      if ( (v63 & 1) == 0 )
      {
LABEL_69:
        if ( v24 )
        {
          v44 = _frame.v65;
          v42 = (v42 & ~0xFFu) | ((uint8_t)(*v26) & 0xFFu);
          goto LABEL_40;
        }
        goto LABEL_74;
      }
    }
LABEL_72:
    _frame.v64 = v24;
    write_dash_header(&_frame.v65);
    v24 = _frame.v64;
    goto LABEL_69;
  }
  v43 = (void *)(uintptr_t)(off_1384E4);
  if ( (*((volatile uint8_t *)off_1384E4 + 374) & 1) != 0 )
    goto LABEL_72;
  v44 = _frame.v65;
LABEL_40:
  v45 = (volatile uint8_t *)v44;
  v46 = &v26[-v44];
  v47 = (volatile uint8_t *)(v44 + v24);
  while ( 1 )
  {
    *v45++ = v42;
    if ( v47 == v45 )
      break;
    v42 = (v42 & ~0xFFu) | ((uint8_t)(v45[(uint32_t)v46]) & 0xFFu);
  }
  v48 = v43[374];
  v49 = v0[3851];
  _frame.v65 += v24;
  if ( v49 != 1 )
    goto LABEL_49;
LABEL_44:
  if ( (v48 & 2) == 0 )
    goto LABEL_49;
  write_bf_header((int)&_frame.v65);
  if ( (v43[374] & 4) != 0 )
LABEL_46:
    write_hash_header((int)&_frame.v65);
LABEL_50:
  v50 = (volatile uint16_t *)off_1384D0;
  memcpy((void *)(uintptr_t)(_frame.v65), (volatile char *)off_1384D0 + 3, *(volatile uint16_t *)off_1384D0);
  v51 = **(volatile int16_t **)off_1384D4;
  _frame.v65 += *v50;
  v52 = _frame.v65 - (uint32_t)v25;
  if ( v51 < 0 && v52 > 0x12C )
  {
    irq_disable_mmio_write(dword_1384E0, dword_1384DC, 182);
    v52 = (v52 & ~0xFFFFu) | ((uint16_t)(_frame.v65 - (uint16_t)v25) & 0xFFFFu);
  }
  *(volatile uint16_t *)(v8 + 364) = v52;
  *(volatile uint32_t *)(v8 + 360) = 0;
  return (volatile uint32_t *)rx_process_packet_1(v8);
}



// is_initialized_1 @ 0x138528
/* luna: Initializes scan state and starts a scan, detecting a Direct SSID and copying optional request data. */
int is_initialized_1() {
  volatile uint32_t *v0; // r6
  volatile uint16_t *v1; // r4
  volatile uint32_t *v2; // r5
  int v3; // r6
  volatile char *v4; // r3
  volatile char *v5; // r0
  volatile uint32_t *v6; // r3
  volatile uint8_t *v7; // r1
  BOOL v8; // r2
  BOOL v9; // r0
  volatile int *v10; // r2
  volatile uint16_t *v11; // r0
  volatile char *v12; // r1
  unsigned int v13; // r2
  int v15; // r1
  int v16; // r3
  volatile unsigned int v17; // r2

  if ( *(volatile uint8_t *)off_138664 )
    rf_reg_write_byte(0xC2u);
  if ( **(volatile uint8_t **)off_138668 == 1 )
    *(volatile uint32_t *)off_13866C &= ~0x200000u;
  v0 = (void *)(uintptr_t)(off_138670);
  v1 = (void *)(uintptr_t)(off_138674);
  v2 = (void *)(uintptr_t)(off_138678);
  if ( (*(volatile uint32_t *)off_138670 & 4) != 0 )
  {
    v15 = *(volatile uint16_t *)(*(volatile uint32_t *)off_13869C + 54);
    v16 = dword_1386A0 + 1320 * *(volatile uint8_t *)(*(volatile uint32_t *)off_138674 + 366);
    *((volatile uint8_t *)off_138678 + 29) = 3;
    v17 = (*(volatile uint32_t *)0x40501010u);
    v2[5] = v16;
    mem_copy_util(v2 + 3, v15 + v17);
    *((volatile uint8_t *)v2 + 28) = 1;
    *v0 &= ~4u;
  }
  v3 = *((volatile uint8_t *)v1 + 3850);
  if ( !*((volatile uint8_t *)v1 + 3850) )
  {
    v4 = (volatile char *)off_138674;
    v5 = (volatile char *)off_138674 + 3840;
    do
    {
      v4[8] = v3;
      v4[64] = 0x80;
      v4 += 60;
    }
    while ( v5 != v4 );
    v6 = (void *)(uintptr_t)(off_13867C);
    v1[2] = v3;
    v6[1] = v3;
  }
  v7 = *(volatile uint8_t **)v1;
  if ( *(volatile uint8_t *)(*(volatile uint32_t *)v1 + 368) == 1 && v7[252] == 7 )
  {
    v9 = memcmp((unsigned int)(v7 + 253), (unsigned int)aDirect, 7u) == 0;
    v7 = *(volatile uint8_t **)v1;
    v3 = *((volatile uint8_t *)v1 + 3850);
    v8 = v9;
  }
  else
  {
    v8 = 0;
    v9 = (v9 & ~0xFFu) | ((uint8_t)(0) & 0xFFu);
  }
  *((volatile uint8_t *)v1 + 3898) = v9;
  check_feature_flag(8, "%s:%d,%d,%d,cnt=%d\r\n", aScanuStart, (uint8_t)v7[366], v3, v8, (uint8_t)v7[367]);
  v10 = (volatile int *)off_13868C;
  v11 = (void *)(uintptr_t)(off_138690);
  *(volatile uint32_t *)off_138688 |= 4u;
  *v11 = *v10;
  *v10 = (HIWORD(*v10) << 16) | 0x5DC;
  v2[1] |= 0x20u;
  hci_cmd_preprocess(4u, 1);
  v12 = *(volatile char **)(*(volatile uint32_t *)v1 + 360);
  if ( v12 )
  {
    v13 = *(volatile uint16_t *)(*(volatile uint32_t *)v1 + 364);
    if ( v13 <= 0xC8 )
      memcpy((volatile char *)dword_138694, v12, v13);
  }
  return (int)(uintptr_t)(check_event_flag_1());
}


// rf_validate_rate @ 0x1386a8
/* luna: Parses a supported rate-format descriptor from the input buffer, stages its parameters and derived timing value, advances the buffer cursor, and retur */
int rf_validate_rate(int a1, int16_t a2) {
  volatile uint8_t *v2; // r2
  int v3; // r4
  int v4; // r3
  int v5; // r1
  int v6; // r5
  int result; // r0
  int v8; // r3
  char v9; // r1
  int v10; // r6
  int v11; // r8
  int v12; // r3
  int v13; // t1
  char v14; // r1
  int v15; // r4
  int16_t v16; // r3
  int v17; // r12
  char v18; // r4
  int v19; // r3

  v2 = (void *)(uintptr_t)(off_13880C);
  v3 = *((volatile uint8_t *)off_13880C + 8);
  v4 = (a2 & 0x7C) - 4;
  v5 = a2 & 0x400;
  v6 = a1 + v3;
  switch ( v4 )
  {
    case 0:
      *((volatile uint8_t *)off_13880C + 8) = v3 + 4;
      result = 1;
      break;
    case 4:
      *((volatile uint8_t *)off_13880C + 8) = v3 + 8;
      v16 = *(volatile uint16_t *)(a1 + v3);
      v17 = *(volatile uint16_t *)(v6 + 6);
      v18 = v2[48];
      *((volatile uint32_t *)v2 + 4) = (uint16_t)(v16 << 8)
                          | *(volatile uint8_t *)(v6 + 2)
                          | (*(volatile uint16_t *)(v6 + 4) << 16);
      *((volatile uint32_t *)v2 + 5) = v17;
      v2[48] = v18 | 3;
      if ( v5 )
        v19 = 1320 * (uint8_t)v2[10] + 480 + 120 * (*(volatile uint16_t *)(v6 + 2) >> 14) + dword_138810;
      else
        v19 = dword_138814 + 696 * (uint8_t)v2[9];
      *((volatile uint32_t *)v2 + 8) = v19;
      result = 1;
      break;
    case 8:
    case 12:
    case 16:
    case 20:
      if ( v5 )
        v8 = 1320 * *((volatile uint8_t *)off_13880C + 10)
           + 480
           + 120 * (*(volatile uint16_t *)(v6 + 2) >> 14)
           + dword_138810;
      else
        v8 = dword_138814 + 696 * *((volatile uint8_t *)off_13880C + 9);
      *((volatile uint8_t *)off_13880C + 8) = v3 + 8;
      v9 = v2[48];
      v10 = *(volatile uint16_t *)(a1 + v3);
      v11 = *(volatile uint16_t *)(v6 + 4);
      *((volatile uint32_t *)v2 + 8) = v8;
      *((volatile uint32_t *)v2 + 5) = *(volatile uint16_t *)(v6 + 6);
      v2[48] = v9 | 2;
      *((volatile uint32_t *)v2 + 4) = v10 | (v11 << 16);
      result = 1;
      break;
    case 24:
      if ( v5 )
        v12 = 1320 * *((volatile uint8_t *)off_13880C + 10)
            + 480
            + 120 * (*(volatile uint16_t *)(v6 + 2) >> 14)
            + dword_138810;
      else
        v12 = dword_138814 + 696 * *((volatile uint8_t *)off_13880C + 9);
      *((volatile uint8_t *)off_13880C + 8) = v3 + 18;
      v13 = *(volatile uint32_t *)(v6 + 2);
      v14 = v2[48];
      v15 = *(volatile uint32_t *)(v6 + 6);
      *((volatile uint32_t *)v2 + 8) = v12;
      v2[48] = v14 | 2;
      *((volatile uint32_t *)v2 + 4) = v13;
      *((volatile uint32_t *)v2 + 5) = v15;
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}



// get_table_entry @ 0x138818
/* luna: Clears occupied entries from a 64-slot RF queue while advancing its read index and sequence counter. */
int get_table_entry(int result) {
  int v1; // r1
  volatile int16_t **v2; // r5
  int v3; // r7
  int v4; // r6
  int v5; // r4
  int v6; // r3
  int16_t v7; // r2
  int v8; // r0
  int v9; // r3

  if ( *(volatile uint32_t *)(result + 4 * (*(volatile uint8_t *)(result + 10) + 4)) )
  {
    v1 = *(volatile uint8_t *)(result + 11);
    v2 = (volatile int16_t **)off_13887C;
    v3 = dword_138880;
    v4 = dword_138884;
    v5 = result;
    do
    {
      if ( **v2 < 0 && !v1 )
      {
        irq_disable_mmio_write(v4, v3, 1537);
        v1 = (v1 & ~0xFFu) | ((uint8_t)(*(volatile uint8_t *)(v5 + 11)) & 0xFFu);
      }
      v6 = *(volatile uint8_t *)(v5 + 10);
      v7 = *(volatile uint16_t *)(v5 + 8);
      v8 = v6 + 4;
      v9 = ((uint8_t)v6 + 1) & 0x3F;
      *(volatile uint32_t *)(v5 + 4 * v8) = 0;
      v1 = (uint8_t)(v1 - 1);
      *(volatile uint8_t *)(v5 + 10) = v9;
      *(volatile uint8_t *)(v5 + 11) = v1;
      result = *(volatile uint32_t *)(v5 + 4 * (v9 + 4));
      *(volatile uint16_t *)(v5 + 8) = (v7 + 1) & 0xFFF;
    }
    while ( result );
  }
  return result;
}



// rf_read_tx_power @ 0x138888
/* luna: Clears the 16-bit field at offset 8 of the supplied object and returns the next sequence number. */
int rf_read_tx_power(int a1) {
  *(volatile uint16_t *)(a1 + 8) = 0;
  return seq_num_increment();
}



