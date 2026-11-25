// get_link_context @ 0x1370f0
int get_link_context(int a1, int a2, int a3, int16_t a4) {
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

  v4 = dword_1371BC;
  v5 = (void *)(uintptr_t)(off_1371C0);
  v7 = *(volatile uint8_t *)(a2 + 366);
  *((volatile uint16_t *)off_1371C0 + 1924) = a4;
  v8 = (volatile int *)(a2 + 352);
  *(volatile uint32_t *)(v4 + 1320 * v7 + 472) = 0;
  v5[1925] = 1;
  v9 = *(volatile uint32_t *)(a2 + 356);
  *((volatile uint32_t *)v5 + 963) = *(volatile uint32_t *)(a2 + 352);
  v5[1928] = v9;
  *(volatile uint32_t *)v5 = a2;
  *((volatile uint8_t *)v5 + 3899) = 0;
  v10 = find_table_entry((void *)(uintptr_t)(a2 + 352), 0);
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
    v22 = *(volatile int16_t **)off_1371C4;
    v5[1948] = v20 & v21 | v19;
    if ( *v22 >= 0 )
      goto LABEL_4;
  }
  else
  {
    v13 = *v8;
    v14 = *(volatile uint32_t *)(a2 + 356);
    v15 = (volatile int16_t **)off_1371C4;
    *((volatile uint32_t *)v5 + 973) = *v8;
    v16 = *v15;
    v5[1948] = v14;
    if ( *v16 >= 0 )
    {
LABEL_4:
      periodic_task_handler(v13);
      return 1;
    }
  }
  if ( (*(volatile uint8_t *)(a2 + 352) & 1) == 0 )
    goto LABEL_4;
  v23 = mmio_irq_clear(dword_1371CC, dword_1371C8, 178);
  periodic_task_handler(v23);
  return 1;
}



// radio_state_control @ 0x1371d0
int radio_state_control(int a1, int a2, int a3, int a4) {
  volatile uint16_t *v4; // r2
  uint64_t v6; // r0
  volatile uint8_t *v8; // r0
  int v9; // r0

  v4 = (void *)(uintptr_t)(off_137224);
  *((volatile uint16_t *)off_137224 + 1924) = a4;
  v4[1925] = 0;
  v6 = *(volatile uint64_t *)(a2 + 352);
  *(volatile uint32_t *)v4 = a2;
  *((volatile uint32_t *)v4 + 963) = v6;
  v4[1928] = WORD2(v6);
  if ( a4 == 11 || a4 == 6 )
  {
    periodic_task_handler(v6);
    return 1;
  }
  else
  {
    v8 = (volatile uint8_t *)bt_buf_alloc(4105, a4, 4, 2u);
    v8[1] = 1;
    *v8 = *(volatile uint8_t *)(a2 + 366);
    v9 = (int)(uintptr_t)(hci_evt_send((int)v8));
    periodic_task_handler(v9);
    return 1;
  }
}



// rf_cmd_read @ 0x137228
int rf_cmd_read(int a1, volatile uint8_t *a2) {
  volatile uint16_t *v2; // r5
  int v4; // r0

  v2 = (volatile uint16_t *)off_137258;
  v4 = bt_buf_alloc(4107, *((volatile uint16_t *)off_137258 + 1924), 4, 1);
  hci_evt_send(v4);
  state_check_feature(8, "scan cancel cfm %d\r\n", v2[1924]);
  radio_event_dispatcher(*a2);
  return 0;
}


// is_device_ready @ 0x137260
int is_device_ready(int a1, volatile uint8_t *a2) {
  if ( *a2 )
    radio_event_dispatcher((uint8_t)*a2);
  return 0;
}



// sdio_set_blocksize @ 0x137274
int sdio_set_blocksize() {
  int v0; // r0
  int v1; // r0

  v0 = bt_buf_alloc(2051, 2, 4, 1);
  hci_evt_send(v0);
  v1 = hci_cmd_send_short(4u);
  state_check_feature(8, "scanu cancel:%d\r\n", v1);
  return 0;
}


// gpio_isr_handler @ 0x1372a8
int gpio_isr_handler() {
  volatile uint8_t *v0; // r2
  char v1; // r3
  unsigned int v2; // r1

  v0 = (void *)(uintptr_t)(off_1372D8);
  v1 = *((volatile uint8_t *)off_1372D8 + 3851);
  if ( !v1 )
  {
    v2 = *((volatile uint16_t *)off_1372D8 + 2);
    if ( v2 >= 7 )
      v2 = 7;
    *(volatile uint32_t *)off_1372DC = *(volatile uint32_t *)off_1372DC & 0xFFFFFE3F | (v2 << 6);
  }
  v0[3851] = v1 + 1;
  adv_state_control();
  return 0;
}



// event_loop_tick @ 0x1372e0
BOOL event_loop_tick(volatile uint8_t *a1) {
  int v1; // r8
  int v3; // r9
  int v4; // r7
  int v5; // r4
  int v6; // r5
  volatile uint8_t *v7; // r10
  int v8; // r2

  v1 = *((volatile uint8_t *)off_137350 + 3898);
  if ( *((volatile uint8_t *)off_137350 + 3898) )
    return memcmp((int)(uintptr_t)(a1 + 1), dword_137354, 7) == 0;
  v3 = *(volatile uint32_t *)off_137350;
  v4 = *(volatile uint8_t *)(*(volatile uint32_t *)off_137350 + 368);
  if ( *(volatile uint8_t *)(*(volatile uint32_t *)off_137350 + 368) )
  {
    v5 = *(volatile uint32_t *)off_137350;
    v6 = *((volatile uint8_t *)off_137350 + 3898);
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



// init_radio_params @ 0x137358
volatile uint8_t * init_radio_params(volatile uint8_t *result, int a2, char a3, int a4) {
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
  v7 = find_char_3(result, a2, &v37);
  v8 = v7;
  if ( v7 )
  {
    v9 = v37;
    result = (volatile uint8_t *)freq_to_chan_map2(bswap32(*((volatile uint32_t *)v7 + 1)));
    if ( result )
    {
      result = (volatile uint8_t *)((1 << (char)result) | *(volatile uint16_t *)(a4 + 52));
      *(volatile uint16_t *)(a4 + 52) = (uint16_t)result;
    }
    v10 = *((volatile uint16_t *)v8 + 4);
    v11 = v9 - 8;
    for ( i = (volatile unsigned int *)(v8 + 10); v10 && v11 > 3; --v10 )
    {
      result = (volatile uint8_t *)freq_to_chan_map2(bswap32(*i));
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
          result = (volatile uint8_t *)freq_to_chan_map(bswap32(*v13));
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
          result = (volatile uint8_t *)freq_to_chan_map2(bswap32(*v18));
          if ( result )
LABEL_28:
            *(volatile uint16_t *)(a4 + 52) |= 1 << (char)result;
        }
      }
    }
  }
  else
  {
    v20 = debug_log(v5, a2, &v37);
    v21 = v20;
    if ( v20 )
    {
      v22 = v37;
      v23 = bswap32(*((volatile uint32_t *)v20 + 2));
      *(volatile uint32_t *)(a4 + 48) = 2;
      result = (volatile uint8_t *)freq_to_chan_map2(v23);
      if ( result )
      {
        result = (volatile uint8_t *)((1 << (char)result) | *(volatile uint16_t *)(a4 + 52));
        *(volatile uint16_t *)(a4 + 52) = (uint16_t)result;
      }
      v24 = *((volatile uint16_t *)v21 + 6);
      v25 = v22 - 12;
      for ( j = (volatile unsigned int *)(v21 + 14); v24 && v25 > 3; --v24 )
      {
        result = (volatile uint8_t *)freq_to_chan_map2(bswap32(*j));
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
              result = (volatile uint8_t *)freq_to_chan_map(bswap32(*v27++));
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
      result = find_char_5(v5, a2, &v37);
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
          result = (volatile uint8_t *)freq_to_chan_map(bswap32(*v32));
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
            result = (volatile uint8_t *)freq_to_chan_map2(bswap32(*v33));
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
          result = (volatile uint8_t *)freq_to_chan_map2(bswap32(*v33));
          if ( result )
            goto LABEL_28;
        }
      }
    }
  }
  return result;
}



// radio_event_dispatcher @ 0x1375cc
int radio_event_dispatcher(int a1) {
  volatile uint16_t *v2; // r4
  volatile uint8_t **v3; // r7
  int16_t v4; // r0
  volatile uint8_t *v5; // r5
  volatile int *v6; // r2
  volatile uint16_t *v7; // r0
  int v8; // r1
  int v9; // r0
  volatile uint32_t *v11; // r3

  if ( *(volatile uint8_t *)off_1376A0 )
    write_mmio_byte(*((volatile uint8_t *)off_1376D0 + 9));
  v2 = (void *)(uintptr_t)(off_1376A4);
  v3 = (volatile uint8_t **)off_1376A8;
  if ( *((volatile uint8_t *)off_1376A4 + 3850) == 1 )
    v4 = 4099;
  else
    v4 = 4097;
  v5 = (volatile uint8_t *)bt_buf_alloc(v4, *((volatile uint16_t *)off_1376A4 + 1924), 4, 3);
  state_check_feature(
    8,
    "%s:%d,%d,%d\r\n",
    aScanuConfirm,
    *(volatile uint8_t *)(*(volatile uint32_t *)v2 + 366),
    *((volatile uint8_t *)v2 + 3850),
    a1);
  v6 = (volatile int *)off_1376B8;
  v7 = (void *)(uintptr_t)(off_1376BC);
  *(volatile uint32_t *)off_1376B4 &= ~4u;
  v8 = (uint16_t)*v7;
  v9 = *(volatile uint32_t *)v2;
  *v6 = (HIWORD(*v6) << 16) | v8;
  *v5 = *(volatile uint8_t *)(v9 + 366);
  v5[1] = a1;
  v5[2] = v2[2];
  if ( **v3 == 1 && BYTE1(((volatile uint32_t *)(uintptr_t)off_1376C4)[47]) )
  {
    v11 = (void *)(uintptr_t)(off_1376CC);
    *(volatile uint32_t *)off_1376C8 &= 0xFC0FFFFF;
    *v11 |= 0x400000u;
    *v11 |= 0x200000u;
  }
  jump_to_tx_entry((int)(uintptr_t)((volatile char *)(v9 - 12)));
  *(volatile uint32_t *)v2 = 0;
  hci_evt_send((int)v5);
  *((volatile uint32_t *)off_1376C0 + 1) &= ~0x20u;
  return hci_cmd_send(4u, 0);
}


// dma_rx_reset @ 0x1376d4
int dma_rx_reset() {
  hci_cmd_send(4u, 0);
  return (int)memset((volatile int *)dword_1376F0, 0, 0xFC0u);
}


// find_table_entry @ 0x1376f4
int find_table_entry(volatile uint16_t *a1, int a2) {
  int v2; // r3
  int v3; // r4

  v2 = dword_137740;
  v3 = dword_137740 + 3840;
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



// process_hci_command @ 0x137744
int process_hci_command(volatile uint16_t *a1) {
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
  v1 = (void *)(uintptr_t)(off_137B88);
  v3 = *((volatile uint8_t *)off_137B88 + 3852);
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
  else if ( *((volatile uint16_t *)off_137B88 + 1926) != _frame.v142
         || (v9 = _frame.v143, *((volatile uint16_t *)off_137B88 + 1927) != _frame.v143)
         || (v10 = *((volatile uint16_t *)off_137B88 + 1928), _frame.v144 != v10) )
  {
    if ( !LOBYTE(((volatile uint32_t *)(uintptr_t)off_137B78)[102]) || *((volatile uint8_t *)off_137B88 + 3850) )
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
  v13 = find_char_1((volatile uint8_t *)a1 + 48, _frame.a2, &_frame.a3);
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
      v17 = parse_data_3((void *)(_frame.v132), _frame.v133);
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
        v22 = parse_data_4(v21, v20);
        v23 = v22;
        if ( !v22 )
          break;
        v24 = v22[1];
        v25 = v22 + 2;
        v20 = (uint16_t)(v20 - (v24 + 2));
        v21 += v24 + 2;
        if ( parse_data_5(v22 + 2, 4) )
        {
          v16 = v23 + 4;
          v15 = parse_data_6(v25, v24);
          goto LABEL_13;
        }
        if ( v16 )
        {
          if ( v15 )
          {
            if ( !v14 )
            {
              v14 = find_char_1(v25, v24, _frame.v145);
              if ( !v14 )
                goto LABEL_15;
            }
            goto LABEL_40;
          }
          v39 = parse_data_6(v25, v24);
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
            v26 = find_char_1(v25, v24, _frame.v145);
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
  if ( !_frame.v139 && !event_loop_tick(_frame.a1a) )
  {
    if ( !v1[4029] )
      return 0;
    v27 = dword_137B74;
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
      if ( event_loop_tick(_frame.v145) )
        break;
      if ( ++v28 >= (uint8_t)v1[4029] )
        return 0;
    }
  }
  v40 = sub_12dd88((void *)(_frame.v140), _frame.a2);
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
        v44 = llm_adv_state_get(v42, v43);
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
  v45 = (int)parse_data_8((void *)(_frame.v140), _frame.a2);
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
  v44 = llm_adv_state_get(*((volatile uint8_t *)a1 + 6), (uint16_t)a1[2]);
  _frame.v158 = (unsigned int)v44;
LABEL_57:
  v46 = *(volatile uint16_t *)v44;
  if ( (uint16_t)a1[2] != v46 )
    a1[2] = v46;
  init_radio_params((void *)(uintptr_t)((int)_frame.v140), _frame.a2, (uint16_t)a1[23], (int)&_frame.v147);
  v47 = find_table_entry(&_frame.v142, 1);
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
        if ( (**(volatile uint16_t **)off_137DFC & 8) == 0 )
          goto LABEL_68;
        v64 = aHidden;
        goto LABEL_67;
      }
      v86 = *(volatile uint16_t **)off_137DFC;
      ++*(volatile uint16_t *)(dword_137DF8 + 2 * v85 + 4);
      if ( (*v86 & 8) == 0 )
        goto LABEL_68;
      goto LABEL_84;
    }
  }
LABEL_64:
  if ( (**(volatile uint16_t **)off_137B7C & 8) != 0 )
  {
    v63 = *(volatile uint8_t *)(v48 + 8);
    if ( !*(volatile uint8_t *)(v48 + 8) )
    {
      v51 = *(volatile uint16_t **)(v48 + 44);
      v50 = *((volatile char *)a1 + 9);
      v64 = aHidden;
LABEL_67:
      ke_event_schedule_1(
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
    if ( strlen(v48 + 9) )
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
  v66 = (volatile uint16_t *)off_137B88;
  if ( v1[4029] )
  {
    v67 = (void *)(uintptr_t)(off_137B88);
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
          v100 = find_table_entry((volatile uint16_t *)_frame.v145, 1);
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
          v119 = (volatile uint16_t **)off_137DFC;
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
          ke_event_schedule_1(
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
  hci_evt_prepare((int)a1, 4100, 13, 4);
  return 1;
}


// lookup_handle_entry @ 0x13831c
int lookup_handle_entry(volatile uint16_t *a1) {
  int v1; // r3
  int v2; // r1

  v1 = dword_138374;
  v2 = dword_138374 + 3840;
  while ( !*(volatile uint8_t *)v1 )
  {
    v1 += 60;
    if ( v1 == v2 )
      return 0;
  }
  if ( *(volatile uint16_t *)(v1 + 2) == *a1 )
    goto LABEL_7;
  while ( 1 )
  {
    v1 += 60;
    if ( v1 == v2 )
      break;
    if ( *(volatile uint8_t *)v1 && *(volatile uint16_t *)(v1 + 2) == *a1 )
    {
LABEL_7:
      if ( *(volatile uint16_t *)(v1 + 4) == a1[1] && *(volatile uint16_t *)(v1 + 6) == a1[2] )
        return v1;
    }
  }
  return 0;
}



// parse_pdu_data @ 0x138378
volatile uint8_t * parse_pdu_data(volatile uint8_t *a1) {
  volatile uint8_t *v1; // r4
  volatile uint8_t *v3; // r8
  int v4; // r6
  int v5; // r5
  volatile uint8_t *v6; // r9
  int v7; // r2

  if ( !*a1 )
    return (volatile uint8_t *)*a1;
  v1 = (volatile uint8_t *)dword_1383DC;
  v3 = 0;
  v4 = dword_1383DC + 3840;
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



// adv_state_control @ 0x1383e0
volatile uint32_t *adv_state_control() {
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
  v0 = (volatile uint8_t *)off_1386FC;
  v1 = *((volatile uint8_t *)off_1386FC + 3851);
  v2 = *(volatile uint32_t *)off_1386FC;
  if ( v1 > 1 )
    return (void *)(uintptr_t)(radio_event_dispatcher(0));
  v3 = 0;
  while ( !*(volatile uint8_t *)(v2 + 367) )
  {
LABEL_59:
    v3 = 1;
    if ( v1 == 1 )
    {
      *((volatile uint8_t *)off_1386FC + 3851) = 2;
      return (void *)(uintptr_t)(radio_event_dispatcher(0));
    }
    v1 = 1;
  }
  v4 = *(volatile uint32_t *)off_1386FC;
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
    *((volatile uint8_t *)off_1386FC + 3851) = v1;
  v7 = bt_buf_alloc(2048, 2, 4, 0x178u);
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
  v23 = (volatile uint8_t *)off_13871C;
  v24 = *(volatile uint16_t *)(*(volatile uint32_t *)v0 + 364);
  v25 = (void *)(uintptr_t)(off_138700);
  if ( v24 >= 0xC9 )
    v24 = 0;
  v26 = (volatile uint8_t *)off_13871C;
  if ( v11 == 1 )
  {
    v27 = (volatile char *)dword_138704;
    v11 = 8;
  }
  else
  {
    v27 = (volatile char *)dword_138704;
    if ( *(volatile uint8_t *)(*(volatile uint32_t *)v0 + 369) )
      v11 = 8;
    else
      v27 = (volatile char *)(dword_138704 - 4);
    if ( !*(volatile uint8_t *)(*(volatile uint32_t *)v0 + 369) )
      v11 = 12;
  }
  v28 = (volatile char *)off_138708;
  *((volatile uint8_t *)off_138708 + 20) = 1;
  v29 = v28 + 21;
  v25[1] = 8;
  v30 = v27 + 8;
  do
  {
    v31 = *v27++;
    *++v29 = v31;
  }
  while ( v27 != v30 );
  v32 = (volatile uint8_t *)dword_13870C;
  _frame.v65 = dword_13870C;
  if ( v24 )
  {
    v54 = *v23;
    if ( v54 == 10 )
    {
      v55 = (uint8_t)(v23[1] + 2);
      if ( v23[1] != 0xFE )
      {
        v56 = (volatile char *)off_13871C;
        v57 = (volatile uint8_t *)(dword_13870C + v55);
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
    v34 = (volatile char *)dword_138710;
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
    v43 = (void *)(uintptr_t)(off_138728);
    v48 = *((volatile uint8_t *)off_138728 + 374);
    if ( (v48 & 1) == 0 )
      goto LABEL_48;
    build_tx_packet_1(&_frame.v65);
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
      v43 = (void *)(uintptr_t)(off_138768);
      if ( (*((volatile uint8_t *)off_138768 + 374) & 1) == 0 )
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
      v43 = (void *)(uintptr_t)(off_138728);
      v63 = *((volatile uint8_t *)off_138728 + 374);
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
    build_tx_packet_1(&_frame.v65);
    v24 = _frame.v64;
    goto LABEL_69;
  }
  v43 = (void *)(uintptr_t)(off_138728);
  if ( (*((volatile uint8_t *)off_138728 + 374) & 1) != 0 )
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
  rf_write_pattern_bf0c((int)&_frame.v65);
  if ( (v43[374] & 4) != 0 )
LABEL_46:
    rf_write_pattern_ff23((int)&_frame.v65);
LABEL_50:
  v50 = (volatile uint16_t *)off_138714;
  memcpy((void *)(uintptr_t)(_frame.v65), (volatile char *)off_138714 + 3, *(volatile uint16_t *)off_138714);
  v51 = **(volatile int16_t **)off_138718;
  _frame.v65 += *v50;
  v52 = _frame.v65 - (uint32_t)v25;
  if ( v51 < 0 && v52 > 0x12C )
  {
    mmio_irq_clear(dword_138724, dword_138720, 182);
    v52 = (v52 & ~0xFFFFu) | ((uint16_t)(_frame.v65 - (uint16_t)v25) & 0xFFFFu);
  }
  *(volatile uint16_t *)(v8 + 364) = v52;
  *(volatile uint32_t *)(v8 + 360) = 0;
  return (volatile uint32_t *)hci_evt_send(v8);
}



// periodic_task_handler @ 0x13876c
int periodic_task_handler() {
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

  if ( *(volatile uint8_t *)off_1388A8 )
    write_mmio_byte(0xC2u);
  if ( **(volatile uint8_t **)off_1388AC == 1 )
    *(volatile uint32_t *)off_1388B0 &= ~0x200000u;
  v0 = (void *)(uintptr_t)(off_1388B4);
  v1 = (void *)(uintptr_t)(off_1388B8);
  v2 = (void *)(uintptr_t)(off_1388BC);
  if ( (*(volatile uint32_t *)off_1388B4 & 4) != 0 )
  {
    v15 = *(volatile uint16_t *)(*(volatile uint32_t *)off_1388E0 + 54);
    v16 = dword_1388E4 + 1320 * *(volatile uint8_t *)(*(volatile uint32_t *)off_1388B8 + 366);
    *((volatile uint8_t *)off_1388BC + 29) = 3;
    v17 = (*(volatile uint32_t *)0x40501010u);
    v2[5] = v16;
    ke_event_lock(v2 + 3, v15 + v17);
    *((volatile uint8_t *)v2 + 28) = 1;
    *v0 &= ~4u;
  }
  v3 = *((volatile uint8_t *)v1 + 3850);
  if ( !*((volatile uint8_t *)v1 + 3850) )
  {
    v4 = (volatile char *)off_1388B8;
    v5 = (volatile char *)off_1388B8 + 3840;
    do
    {
      v4[8] = v3;
      v4[64] = 0x80;
      v4 += 60;
    }
    while ( v5 != v4 );
    v6 = (void *)(uintptr_t)(off_1388C0);
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
  state_check_feature(8, "%s:%d,%d,%d,cnt=%d\r\n", aScanuStart, (uint8_t)v7[366], v3, v8, (uint8_t)v7[367]);
  v10 = (volatile int *)off_1388D0;
  v11 = (void *)(uintptr_t)(off_1388D4);
  *(volatile uint32_t *)off_1388CC |= 4u;
  *v11 = *v10;
  *v10 = (HIWORD(*v10) << 16) | 0x5DC;
  v2[1] |= 0x20u;
  hci_cmd_send(4u, 1);
  v12 = *(volatile char **)(*(volatile uint32_t *)v1 + 360);
  if ( v12 )
  {
    v13 = *(volatile uint16_t *)(*(volatile uint32_t *)v1 + 364);
    if ( v13 <= 0xC8 )
      memcpy((volatile char *)dword_1388D8, v12, v13);
  }
  return (int)(uintptr_t)(adv_state_control());
}


// phy_flags_decode @ 0x1388ec
int phy_flags_decode(int a1, int16_t a2) {
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

  v2 = (void *)(uintptr_t)(off_138A50);
  v3 = *((volatile uint8_t *)off_138A50 + 8);
  v4 = (a2 & 0x7C) - 4;
  v5 = a2 & 0x400;
  v6 = a1 + v3;
  switch ( v4 )
  {
    case 0:
      *((volatile uint8_t *)off_138A50 + 8) = v3 + 4;
      result = 1;
      break;
    case 4:
      *((volatile uint8_t *)off_138A50 + 8) = v3 + 8;
      v16 = *(volatile uint16_t *)(a1 + v3);
      v17 = *(volatile uint16_t *)(v6 + 6);
      v18 = v2[48];
      *((volatile uint32_t *)v2 + 4) = (uint16_t)(v16 << 8)
                          | *(volatile uint8_t *)(v6 + 2)
                          | (*(volatile uint16_t *)(v6 + 4) << 16);
      *((volatile uint32_t *)v2 + 5) = v17;
      v2[48] = v18 | 3;
      if ( v5 )
        v19 = 1320 * (uint8_t)v2[10] + 480 + 120 * (*(volatile uint16_t *)(v6 + 2) >> 14) + dword_138A54;
      else
        v19 = dword_138A58 + 696 * (uint8_t)v2[9];
      *((volatile uint32_t *)v2 + 8) = v19;
      result = 1;
      break;
    case 8:
    case 12:
    case 16:
    case 20:
      if ( v5 )
        v8 = 1320 * *((volatile uint8_t *)off_138A50 + 10)
           + 480
           + 120 * (*(volatile uint16_t *)(v6 + 2) >> 14)
           + dword_138A54;
      else
        v8 = dword_138A58 + 696 * *((volatile uint8_t *)off_138A50 + 9);
      *((volatile uint8_t *)off_138A50 + 8) = v3 + 8;
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
        v12 = 1320 * *((volatile uint8_t *)off_138A50 + 10)
            + 480
            + 120 * (*(volatile uint16_t *)(v6 + 2) >> 14)
            + dword_138A54;
      else
        v12 = dword_138A58 + 696 * *((volatile uint8_t *)off_138A50 + 9);
      *((volatile uint8_t *)off_138A50 + 8) = v3 + 18;
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



// opcode_handler_dispatch @ 0x138a5c
int opcode_handler_dispatch(int result) {
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
    v2 = (volatile int16_t **)off_138AC0;
    v3 = dword_138AC4;
    v4 = dword_138AC8;
    v5 = result;
    do
    {
      if ( **v2 < 0 && !v1 )
      {
        mmio_irq_clear(v4, v3, 1537);
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



// clear_status_and_continue @ 0x138acc
int clear_status_and_continue(int a1) {
  *(volatile uint16_t *)(a1 + 8) = 0;
  return seq_count_inc();
}



