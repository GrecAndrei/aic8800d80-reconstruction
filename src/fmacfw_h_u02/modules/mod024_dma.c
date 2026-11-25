// tx_80211_frame @ 0x11d1e0
BOOL tx_80211_frame(int a1) {
  volatile int16_t **v1; // r10
  int v2; // r8
  int v3; // r3
  volatile uint32_t *v5; // r9
  int16_t v6; // r11
  unsigned int v7; // r6
  int v8; // r5
  int v10; // r2
  unsigned int v11; // r7
  int v12; // r3
  volatile unsigned int v13; // r1
  unsigned int v14; // r3
  volatile uint8_t *v15; // r5
  int v16; // r2
  int v17; // r3
  int v18; // r11
  int v19; // r2
  volatile uint8_t *v20; // r7
  int v21; // r4
  uint64_t v22; // r0
  uint64_t v23; // r0
  unsigned int v24; // r2
  uint64_t v25; // r4
  uint64_t v26; // r0
  uint64_t v27; // r0
  uint64_t v28; // r0
  int v29; // r0
  volatile uint8_t *v30; // r4
  volatile uint32_t *v31; // r2
  int v32; // r8
  volatile int *v33; // r11
  volatile uint32_t *v34; // r7
  volatile unsigned int v35; // r9
  unsigned int v36; // r3
  volatile uint32_t *v37; // r3
  volatile unsigned int v38; // r2
  volatile uint32_t *v39; // r9
  volatile unsigned int v40; // r5
  unsigned int v41; // r1
  int v42; // r6
  int v43; // r5
  int v44; // r3
  int v45; // r2
  volatile uint32_t *v46; // r6
  int v47; // r2
  unsigned int v48; // r3
  volatile uint32_t *v49; // r6
  int v50; // r1
  unsigned int v51; // r3
  struct __attribute__((packed)) { union { int a3; // [sp+4h] [bp-18h]
  int a3a; }; // [sp+4h] [bp-18h]
  int v54; // [sp+8h] [bp-14h]
  int v55; // [sp+Ch] [bp-10h]
  char _pad3[4]; volatile uint8_t *a4; // [sp+14h] [bp-8h] BYREF
  } _frame;
  if ( *(volatile uint16_t *)(a1 + 48) )
  {
    v1 = (volatile int16_t **)off_11D52C;
    v2 = *(volatile uint32_t *)(a1 + 28);
    v3 = **(volatile int16_t **)off_11D52C;
    if ( v3 < 0 && !v2 )
    {
      v8 = 0;
      log_assert_failure((int)aRhdFirstPbdPtr, (int)aRxlFrameHandle, 423);
      return v8;
    }
    v5 = *(volatile uint32_t **)(v2 + 8);
    v6 = *(volatile uint16_t *)v5;
    v7 = *(volatile uint32_t *)(a1 + 84);
    if ( LOBYTE(((volatile uint32_t *)(uintptr_t)off_11D4F0)[102])
      && (*((volatile uint32_t *)off_11D4F4 + 1) & 0x40) != 0
      && (*(volatile uint32_t *)(a1 + 84) & 0x600) == 0x200 )
    {
      if ( (v6 & 0xFC) == 0xC4 )
        ++*(volatile uint32_t *)off_11D510;
    }
    else
    {
      if ( (dword_11D4F8 & ~v7) != 0 )
        return 0;
      *(volatile uint32_t *)(a1 + 84) = v7 & 0xFEFFFFFF;
      if ( v3 < 0 )
      {
        v8 = (v7 >> 15) & 0x1F0;
        if ( !v8 )
        {
          log_assert_failure((int)aKeyIdxHwMmSecD, (int)aRxlFrameHandle, 475);
          return v8;
        }
      }
      v10 = dword_11D4FC;
      v11 = (uint8_t)((v7 >> 15) - 16);
      v12 = dword_11D4FC + 696 * v11;
      v8 = *(volatile uint8_t *)(v12 + 37);
      if ( !*(volatile uint8_t *)(v12 + 37) )
      {
        *(volatile uint32_t *)(a1 + 84) = v7 & 0xFCFFFFFF;
        return v8;
      }
      if ( v11 <= 0x23 )
      {
        v13 = (*(volatile uint32_t *)0x40501010u);
        *(volatile uint32_t *)(v12 + 664) = v13;
      }
      v14 = v10 + 696 * v11;
      if ( *(volatile uint16_t *)(v14 + 32) == 0xFFFF )
      {
        if ( (v6 & 0xFC) != 0x80 )
        {
          *(volatile uint32_t *)(a1 + 84) = v7 & 0xFCFFFFFF;
          return 0;
        }
        _frame.a3 = *(volatile uint32_t *)(v14 + 44);
        *(volatile uint32_t *)(a1 + 84) = v7 & 0xFE007FFF | ((*(volatile uint8_t *)(_frame.a3 + 35) + 16) << 15);
      }
      else
      {
        _frame.a3 = v10 + 696 * v11;
      }
      _frame.v54 = *(volatile uint8_t *)(_frame.a3 + 34);
      v15 = (volatile uint8_t *)(dword_11D504 + 1320 * _frame.v54);
      _frame.v55 = 1320 * _frame.v54;
      sta_get_state(v5, v11, v15[107]);
      if ( !v15[108] )
        return 0;
      v16 = v15[106];
      v17 = dword_11D504;
      if ( v15[106] )
      {
        if ( (v6 & 4) != 0 )
          goto LABEL_38;
        goto LABEL_36;
      }
      if ( (v6 & 0x300) != 0x200 )
      {
        v8 = v6 & 4;
        if ( (v6 & 4) != 0 )
          goto LABEL_19;
        goto LABEL_36;
      }
      v29 = memcmp((unsigned int)(v5 + 4), _frame.v55 + 100 + dword_11D504, 6u);
      v17 = dword_11D504;
      if ( v29 )
      {
        v8 = v6 & 4;
        if ( (v6 & 4) != 0 )
        {
LABEL_37:
          v16 = *(volatile uint8_t *)(v17 + 1320 * _frame.v54 + 106);
          if ( !*(volatile uint8_t *)(v17 + 1320 * _frame.v54 + 106) )
          {
LABEL_19:
            v18 = v6 & 0xFC;
            v19 = _frame.v55 + v17;
            v20 = (volatile uint8_t *)(_frame.v55 + v17);
            if ( v18 == 128 )
            {
              _frame.a4 = nullptr;
              v43 = process_rx_packet(a1 + 20, (int)v20, _frame.a3, (void *)(&_frame.a4));
              mfp_key_parse((unsigned int)_frame.a4, *(volatile uint16_t *)(a1 + 48), (int)v20);
              get_sys_state((int)v20);
              if ( v43 )
                p2p_process_noa_ie(v20, v2, a1 + 20);
              return v43 == 0;
            }
            if ( v18 == 80 )
            {
              v30 = (void *)(uintptr_t)(off_11D518);
              if ( *((volatile uint8_t *)off_11D518 + 29) == 7 )
              {
                v8 = *((volatile uint8_t *)off_11D518 + 36);
                if ( !*((volatile uint8_t *)off_11D518 + 36) )
                {
                  v31 = (void *)(uintptr_t)(off_11D51C);
                  v32 = *(volatile uint32_t *)off_11D51C & 0xF;
                  if ( v32 )
                  {
                    if ( (__get_CPSR() & 1) == 0 )
                    {
                      __disable_irq();
                      *(volatile uint32_t *)off_11D520 = 1;
                    }
                    v33 = (volatile int *)off_11D530;
                    v34 = (void *)(uintptr_t)(off_11D51C);
                    ++*(volatile uint32_t *)off_11D530;
                    *v34 = 0;
                    v35 = (*(volatile uint32_t *)0x40501010u);
                    while ( *v34 << 28 )
                    {
                      v36 = (*(volatile uint32_t *)0x40501010u) - v35;
                      if ( v36 > 0x7530 )
                        check_feature_flag(2, aIdleErr, 30000);
                    }
                    v37 = (void *)(uintptr_t)(off_11D524);
                    v38 = (*(volatile uint32_t *)0x40501010u);
                    if ( (*(volatile uint32_t *)off_11D528 & *(volatile uint32_t *)off_11D524 & 4) == 0 )
                    {
                      _frame.a3a = v8;
                      v39 = (void *)(uintptr_t)(off_11D528);
                      v40 = v38;
                      do
                      {
                        v41 = (*(volatile uint32_t *)0x40501010u) - v40;
                        v42 = *v37 & *v39;
                        if ( v41 > 0x7530 )
                        {
                          check_feature_flag(2, aIdleIntErr);
                          v37 = (void *)(uintptr_t)(off_11D64C);
                        }
                      }
                      while ( (v42 & 4) == 0 );
                      v8 = _frame.a3a;
                    }
                    *(volatile uint32_t *)off_11D650 = 4;
                    if ( *v33 )
                    {
                      v44 = *v33 - 1;
                      v45 = *(volatile uint32_t *)off_11D654;
                      *v33 = v44;
                      if ( !v44 )
                      {
                        if ( v45 )
                          __enable_irq();
                      }
                    }
                    v46 = (void *)(uintptr_t)(off_11D658);
                    v47 = **v1;
                    v48 = *((volatile uint32_t *)off_11D658 + 1) & 0xFFFFFDFF;
                    *((volatile uint32_t *)off_11D658 + 1) = v48;
                    if ( v47 < 0 && *(volatile uint32_t *)off_11D660 << 28 )
                    {
                      log_warning((int)aNxmacCurrentSt, (int)aMmRxFilterSet, 472);
                      v48 = v46[1];
                    }
                    *(volatile uint32_t *)off_11D65C = v48 | *v46;
                    *(volatile uint32_t *)off_11D660 = 16 * v32;
                  }
                  else
                  {
                    v49 = (void *)(uintptr_t)(off_11D658);
                    v50 = **v1;
                    v51 = *((volatile uint32_t *)off_11D658 + 1) & 0xFFFFFDFF;
                    *((volatile uint32_t *)off_11D658 + 1) = v51;
                    if ( v50 < 0 && *v31 << 28 )
                    {
                      log_warning((int)aNxmacCurrentSt, (int)aMmRxFilterSet, 472);
                      v51 = v49[1];
                    }
                    *(volatile uint32_t *)off_11D65C = v51 | *v49;
                  }
                  v30[36] = 1;
                  v30[29] = 0;
                  return v8;
                }
              }
            }
            else if ( v8 )
            {
              if ( v18 == 132 )
              {
                mfp_get_active((void *)(uintptr_t)((int)v5), v7, v19);
                return 0;
              }
            }
            else
            {
              mfp_get_active((void *)(uintptr_t)((int)v5), v7, v19);
              if ( *(volatile uint8_t *)(dword_11D504 + 1320 * _frame.v54 + 1224) && v18 == 208 )
              {
                bt_parse_adv_report((int)v20, *(volatile uint8_t **)(v2 + 8), *(volatile uint16_t *)(a1 + 48), *(volatile uint32_t *)(a1 + 52));
                return v8;
              }
            }
            return 0;
          }
LABEL_38:
          if ( v16 == 2 && *(volatile uint8_t *)(_frame.a3 + 35) <= 0x23u )
          {
            v21 = *(volatile char *)(a1 + 65);
            get_rf_field_lo();
            if ( !*(volatile uint8_t *)(_frame.a3 + 689) )
            {
              v8 = *(volatile char *)(_frame.a3 + 689);
              *(volatile uint8_t *)(_frame.a3 + 689) = v21;
              return v8;
            }
            v22 = signed_int_to_double(*(volatile char *)(_frame.a3 + 689));
            v23 = ((uint64_t (*)())double_multiply)(v22, *(volatile uint64_t *)&dword_11D4E0);
            v24 = v23;
            v23 = (v23 & ~0xFFFFFFFFull) | ((uint32_t)(v21) & 0xFFFFFFFFu);
            v25 = __PAIR64__(HIDWORD(v23), v24);
            v26 = signed_int_to_double(v23);
            v27 = ((uint64_t (*)())double_multiply)(v26, *(volatile uint64_t *)&dword_11D4E8);
            v28 = double_add(v25, v27);
            *(volatile uint8_t *)(_frame.a3 + 689) = ((int (*)(uint64_t))double_to_float_1)(v28);
          }
          return 0;
        }
LABEL_36:
        is_channel_index_valid(*(volatile uint8_t *)(v17 + 1320 * _frame.v54 + 107), v11, 1);
        v17 = dword_11D504;
        v8 = 0;
        goto LABEL_37;
      }
    }
  }
  return 1;
}


// seq_num_increment @ 0x11d670
int seq_num_increment() {
  volatile uint8_t *v0; // r4
  unsigned int v1; // r2
  unsigned int v2; // r3
  int result; // r0

  v0 = (void *)(uintptr_t)(off_11D690);
  v1 = *((volatile uint8_t *)off_11D690 + 11);
  v2 = (uint8_t)(*((volatile uint8_t *)off_11D690 + 10) + 1);
  *((volatile uint8_t *)off_11D690 + 10) = v2;
  if ( v1 < v2 )
  {
    result = j_nullsub_6();
    v0[10] = 0;
  }
  return result;
}



// seq_num_read @ 0x11d694
int seq_num_read() {
  volatile uint8_t *v0; // r4
  volatile unsigned int *v1; // r2
  int v2; // r3
  int result; // r0

  v0 = (void *)(uintptr_t)(off_11D6B4);
  if ( *((volatile uint8_t *)off_11D6B4 + 10) )
    result = j_nullsub_6();
  v1 = (volatile unsigned int *)off_11D6B8;
  v2 = *(volatile uint32_t *)off_11D6B8;
  v0[10] = v0[11];
  *v1 = v2 & 0xFFFFFEFF;
  return result;
}



// dma_poll_status @ 0x11d6bc
int dma_poll_status() {
  volatile uint8_t *v0; // r4
  int v1; // r0
  char v2; // r0

  v0 = (void *)(uintptr_t)(off_11D6E0);
  dma_ring_setup();
  v1 = (int)(uintptr_t)(clear_stats_buf((void *)(v0)));
  v2 = phy_mode_check(v1) - 1;
  v0[11] = v2;
  v0[10] = v2;
  return (int)(uintptr_t)(wlc_init_hw());
}



// nullsub_4 @ 0x11d6e4
int nullsub_4(void) {
  return 0;
}


// tail_call_0x12cfc4_0x200000 @ 0x11d6e8
int tail_call_0x12cfc4_0x200000() {
  return irq_disable_global_2(0x200000);
}



// dma_ring_alloc_0 @ 0x11d6f0
int dma_ring_alloc_0() {
  volatile uint16_t *v0; // r5
  int v1; // r4
  int result; // r0
  volatile int *v3; // r9
  volatile int *v4; // r7
  void ( *v5)(uint32_t); // r2
  int v6; // r3
  int v7; // r2
  volatile uint32_t *v8; // r1
  volatile uint32_t *v9; // r2

  v0 = (void *)(uintptr_t)(off_11D790);
  v1 = *(volatile uint32_t *)off_11D790;
  result = irq_disable_global_3(0x200000);
  if ( v1 )
  {
    v3 = (volatile int *)off_11D7A8;
    v4 = (volatile int *)off_11D794;
    do
    {
      if ( (*(volatile uint8_t *)(v1 + 16) & 1) == 0 )
        ++v0[4];
      list_pop((int)(uintptr_t)(v0));
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *v4 = 1;
      }
      v5 = *(void ( **)(uint32_t))(v1 + 4);
      ++*v3;
      *(volatile uint8_t *)(v1 + 16) = 0;
      if ( v5 )
        v5(*(volatile uint32_t *)(v1 + 8));
      result = *(volatile uint32_t *)(v1 + 12);
      if ( result )
        result = ((int (*)())phy_rate_get)();
      if ( *v3 )
      {
        v6 = *v3 - 1;
        v7 = *v4;
        *v3 = v6;
        if ( !v6 )
        {
          if ( v7 )
            __enable_irq();
        }
      }
      v1 = *(volatile uint32_t *)v0;
    }
    while ( *(volatile uint32_t *)v0 );
  }
  if ( *((volatile uint8_t *)v0 + 10) != *((volatile uint8_t *)v0 + 11) )
  {
    v8 = (void *)(uintptr_t)(off_11D7A0);
    v9 = (void *)(uintptr_t)(off_11D7A4);
    *(volatile uint32_t *)off_11D79C = *((volatile uint32_t *)off_11D798 + 4) + 200;
    *v8 = 256;
    *v9 |= 0x100u;
    return 256;
  }
  return result;
}



// dma_ring_alloc_1 @ 0x11d7ac
int dma_ring_alloc_1() {
  volatile int *v0; // r5
  int v1; // r4
  int result; // r0
  volatile int *v3; // r8
  volatile int *v4; // r9
  int v5; // r7
  void ( *v6)(uint32_t); // r2
  int v7; // r3
  int v8; // r2
  volatile uint8_t *v9; // r4

  v0 = (volatile int *)off_11D850;
  v1 = *(volatile uint32_t *)off_11D850;
  result = irq_disable_global_3(0x200000);
  if ( v1 )
  {
    v3 = (volatile int *)off_11D85C;
    v4 = (volatile int *)off_11D860;
    v5 = 0;
    do
    {
      if ( (*(volatile uint8_t *)(v1 + 16) & 1) == 0 )
      {
        if ( v5 )
          break;
        v5 = 1;
      }
      list_pop((int)v0);
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *v3 = 1;
      }
      v6 = *(void ( **)(uint32_t))(v1 + 4);
      ++*v4;
      *(volatile uint8_t *)(v1 + 16) = 0;
      if ( v6 )
        v6(*(volatile uint32_t *)(v1 + 8));
      result = *(volatile uint32_t *)(v1 + 12);
      if ( result )
        result = phy_rate_get(result);
      if ( *v4 )
      {
        v7 = *v4 - 1;
        v8 = *v3;
        *v4 = v7;
        if ( !v7 )
        {
          if ( v8 )
            __enable_irq();
        }
      }
      v1 = *v0;
    }
    while ( *v0 );
  }
  v9 = (void *)(uintptr_t)(off_11D854);
  if ( *((volatile uint8_t *)off_11D854 + 69) )
  {
    irq_disable_global_2(0x80000);
    result = check_feature_flag(1024, aHostBufferReco);
    v9[69] = 0;
  }
  return result;
}


// dma_ring_alloc_2 @ 0x11d864
int dma_ring_alloc_2() {
  volatile int *v0; // r6
  int v1; // r4
  int result; // r0
  volatile uint16_t *v3; // r5
  volatile int *v4; // r8
  volatile int *v5; // r9
  char v6; // r2
  void ( *v7)(uint32_t); // r3
  int v8; // r3
  int v9; // r2
  volatile uint8_t *v10; // r4

  v0 = (volatile int *)off_11D918;
  v1 = *(volatile uint32_t *)off_11D918;
  result = irq_disable_global_3(0x200000);
  if ( v1 )
  {
    v3 = (void *)(uintptr_t)(off_11D91C);
    if ( *(volatile uint16_t *)off_11D91C )
    {
      v4 = (volatile int *)off_11D928;
      v5 = (volatile int *)off_11D92C;
      do
      {
        if ( (*(volatile uint8_t *)(v1 + 16) & 1) == 0 && !*v3 )
          break;
        list_pop((int)v0);
        if ( (__get_CPSR() & 1) == 0 )
        {
          __disable_irq();
          *v4 = 1;
        }
        v6 = *(volatile uint8_t *)(v1 + 16);
        ++*v5;
        if ( (v6 & 1) == 0 )
          --*v3;
        v7 = *(void ( **)(uint32_t))(v1 + 4);
        *(volatile uint8_t *)(v1 + 16) = 0;
        if ( v7 )
          v7(*(volatile uint32_t *)(v1 + 8));
        result = *(volatile uint32_t *)(v1 + 12);
        if ( result )
          result = phy_rate_get(result);
        if ( *v5 )
        {
          v8 = *v5 - 1;
          v9 = *v4;
          *v5 = v8;
          if ( !v8 )
          {
            if ( v9 )
              __enable_irq();
          }
        }
        v1 = *v0;
      }
      while ( *v0 );
      v10 = (void *)(uintptr_t)(off_11D920);
      if ( *((volatile uint8_t *)off_11D920 + 69) )
      {
        irq_disable_global_2(0x80000);
        result = check_feature_flag(1024, aHostBufferReco);
        v10[69] = 0;
      }
    }
  }
  return result;
}


// dma_ring_init @ 0x11d930
int dma_ring_init(int a1) {
  volatile uint32_t *v1; // r7
  volatile int *v2; // r9
  int v3; // r8
  volatile uint32_t *v4; // r11
  volatile uint32_t *v5; // r10
  int i; // r5
  int v8; // r2
  BOOL v9; // r0
  int v10; // r3
  unsigned int v11; // r4
  int result; // r0
  void ( *v13)(uint32_t); // r2
  BOOL v14; // r0
  volatile uint32_t *v15; // r5
  int v16; // [sp+14h] [bp-8h]

  v1 = (void *)(uintptr_t)(off_11DA94);
  v2 = (volatile int *)off_11DAB4;
  v3 = dword_11DAC0;
  v4 = (void *)(uintptr_t)(off_11DAC4);
  v5 = (void *)(uintptr_t)(off_11DAC8);
  for ( i = 0; ; ++i )
  {
    v11 = check_fw_rom_signature();
    *v1 = 0x10000;
    result = irq_disable_global_3(0x80000);
    if ( !v11 )
      break;
    if ( !a1 )
    {
      if ( *((volatile uint8_t *)v2 + 192) )
      {
        if ( *(volatile uint32_t *)off_11DA98 > 0x80000u || i > 31 )
          return irq_disable_global_2(0x80000);
      }
      else if ( i > 3 )
      {
        return irq_disable_global_2(0x80000);
      }
    }
    if ( !phy_mode_check_1() || !is_rate_valid() )
    {
      *((volatile uint8_t *)off_11DAAC + 69) = 1;
      v14 = is_rate_valid();
      return check_feature_flag(1024, "no host buffer:%d\r\n", !v14);
    }
    v8 = *(volatile uint32_t *)(v11 + 20);
    if ( v8 != v3 )
      alloc_tx_event(
        "rxbuf1 %08x,%08x: start %08x, end %08x, read %08x, wrptr %08x, rdptr %08x\r\n",
        v11,
        v8,
        *(volatile uint32_t *)off_11DA9C,
        *((volatile uint32_t *)off_11DA9C + 1),
        *((volatile uint32_t *)off_11DA9C + 2),
        *v4,
        *v5);
    read_chip_revision(v11);
    v9 = tx_80211_frame(v11);
    if ( v9 )
    {
      if ( !v9 )
        goto LABEL_10;
    }
    else if ( mac_rx_dpc_handler(v11) )
    {
      goto LABEL_10;
    }
    tx_packet_kick(v11);
LABEL_10:
    v10 = **(volatile uint8_t **)off_11DAA4;
    switch ( v10 )
    {
      case 2:
        goto LABEL_22;
      case 4:
        if ( !*(volatile uint32_t *)off_11DAA8 || *(volatile uint32_t *)(*(volatile uint32_t *)off_11DAA8 + 12) != v11 || (*(volatile uint8_t *)(v11 + 16) & 1) == 0 )
        {
LABEL_22:
          dma_ring_alloc_2();
          continue;
        }
        v16 = *(volatile uint32_t *)off_11DAA8;
        list_pop(off_11DAA8);
        v13 = *(void ( **)(uint32_t))(v16 + 4);
        *(volatile uint8_t *)(v16 + 16) = 0;
        if ( v13 )
          v13(*(volatile uint32_t *)(v16 + 8));
        phy_rate_get(v11);
        break;
      case 3:
        dma_ring_alloc_1();
        break;
    }
  }
  if ( LOBYTE(((volatile uint32_t *)(uintptr_t)off_11DAB4)[48]) )
  {
    v15 = (void *)(uintptr_t)(off_11DAB8);
    if ( *((volatile uint8_t *)off_11DAB8 + 33) )
    {
      result = sub_110edc(*((volatile uint32_t *)off_11DAB8 + 4), *((volatile uint32_t *)off_11DAB8 + 5), *((volatile uint32_t *)off_11DAB8 + 6));
      v15[5] = 0;
      v15[7] = 0;
      v15[4] = 0;
      v15[6] = 0;
      *((volatile uint8_t *)v15 + 33) = 0;
    }
  }
  *(volatile uint32_t *)off_11DABC |= 0x10000u;
  return result;
}


// rx_packet_handler @ 0x11dacc
int rx_packet_handler(volatile int *a1, int a2, volatile uint16_t *a3) {
  volatile uint8_t *v3; // r7
  int v4; // r6
  int v5; // r5
  volatile int *v6; // r9
  volatile uint16_t *v7; // r10
  volatile int *v8; // r11
  int16_t v9; // r8
  int v10; // r4
  int v11; // r3
  int v12; // r12
  int v13; // r0
  char v14; // r2
  char v15; // r3
  volatile int *v16; // r3
  int v17; // r3
  int v18; // r3
  int16_t v19; // r0
  int16_t v20; // r3
  int v21; // r2
  volatile int *v22; // r3
  int v23; // r3
  int v25; // [sp+0h] [bp-14h]
  int v26; // [sp+4h] [bp-10h]

  v3 = (void *)(uintptr_t)(off_11DBE4);
  v4 = *a1;
  v5 = (uint16_t)*a3;
  v6 = (volatile int *)off_11DBF8;
  v7 = (void *)(uintptr_t)(off_11DBFC);
  v8 = (volatile int *)off_11DC00;
  v9 = 0;
  *((volatile uint8_t *)off_11DBE4 + 2) = 0;
  v26 = 0;
  while ( 1 )
  {
    v19 = *(volatile uint16_t *)(v4 + 8);
    v20 = *(volatile uint32_t *)(v4 + 12) + 1;
    v21 = (uint16_t)(v20 - v19);
    if ( a2 + v5 >= v21 )
    {
      v10 = (v10 & ~0xFFFFu) | ((uint16_t)(v19 - v20 + v5 + a2) & 0xFFFFu);
      a2 = (uint16_t)(v21 - v5);
      v10 = (uint16_t)v10;
      v5 = 0;
    }
    else
    {
      v10 = 0;
    }
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(volatile uint32_t *)off_11DBE8 = 1;
    }
    v11 = (uint16_t)*v7;
    v12 = *v6;
    v25 = *v8;
    v13 = *v8 + 8 * v11;
    *(volatile uint32_t *)(v13 + 4) = *(volatile uint32_t *)(v4 + 8);
    *v6 = v12 + 1;
    *(volatile uint32_t *)(v25 + 8 * v11) = a2;
    v14 = v3[3] + 1;
    v9 += a2;
    *v7 = v11 + 1;
    v3[3] = v14;
    if ( v10 )
    {
      if ( v12 == -1 )
        goto LABEL_10;
      v22 = (volatile int *)off_11DBE8;
      *v6 = v12;
      v23 = *v22;
      if ( v12 || !v23 )
        goto LABEL_10;
      goto LABEL_9;
    }
    v15 = *(volatile uint8_t *)(v13 + 3);
    *(volatile uint16_t *)v3 = v9;
    *(volatile uint8_t *)(v13 + 3) = v15 | 4;
    v3[2] = 1;
    *((volatile uint32_t *)v3 + 2) = v13;
    if ( v12 == -1 )
      break;
    v16 = (volatile int *)off_11DBE8;
    *v6 = v12;
    v17 = *v16;
    if ( v12 || !v17 )
      break;
LABEL_9:
    __enable_irq();
    if ( !v10 )
      break;
LABEL_10:
    v18 = *(volatile uint32_t *)(v4 + 4);
    if ( **(volatile int16_t **)off_11DBEC < 0 && !v18 )
    {
      irq_disable_mmio_write(dword_11DBF4, dword_11DBF0, 615);
      v18 = 0;
    }
    v26 = v4;
    a2 = v10;
    v4 = v18;
  }
  *a1 = v4;
  *a3 = v5;
  return v26;
}



// rx_packet_process_2 @ 0x11dc04
volatile uint32_t * rx_packet_process_2(volatile uint32_t *a1, int a2, volatile uint16_t *a3) {
  volatile int *v3; // r7
  int v4; // r10
  volatile uint32_t *v5; // r6
  volatile int16_t **v6; // r11
  volatile uint32_t *v7; // r8
  int v9; // r9
  int v10; // r5
  int v11; // r0
  int v12; // r3
  volatile uint32_t *v13; // r4
  int v14; // r2
  int v15; // r0
  int v16; // r1
  volatile uint32_t *v17; // r3
  int16_t v18; // r5
  int16_t v19; // r2
  int v20; // r1
  int v22; // [sp+8h] [bp-14h]
  int v23; // [sp+8h] [bp-14h]
  int16_t v24; // [sp+8h] [bp-14h]
  volatile uint32_t *v25; // [sp+Ch] [bp-10h]

  v3 = (volatile int *)off_11DD10;
  v4 = (uint16_t)*a3;
  v5 = (volatile uint32_t *)*a1;
  v6 = (volatile int16_t **)off_11DD20;
  v7 = 0;
  *((volatile uint8_t *)off_11DD10 + 32) = 1;
  v9 = 0;
  v25 = 0;
  while ( 1 )
  {
    v18 = *((volatile uint16_t *)v5 + 4);
    v19 = v5[3] + 1;
    v20 = (uint16_t)(v19 - v18);
    if ( a2 + v4 >= v20 )
      break;
    v23 = a2;
    v11 = mmio_read_0();
    v10 = 0;
    v12 = v23;
    v9 = 1;
    v13 = (volatile uint32_t *)v11;
    if ( !v11 )
      goto LABEL_15;
LABEL_5:
    v14 = v3[1];
    if ( !v14 )
      *v3 = v11;
    v15 = **v6;
    v3[3] += v12;
    v3[1] = v14 + 1;
    v16 = v5[2];
    if ( v15 < 0 && !v16 )
    {
      v24 = v12;
      irq_disable_mmio_write(dword_11DD18, dword_11DD14, 683);
      v16 = v5[2];
      v12 = (v12 & ~0xFFFFu) | ((uint16_t)(v24) & 0xFFFFu);
    }
    tx_desc_set_control(v13, v16, 0, v12, v9);
    if ( v7 )
      v7[1] = (int)(uintptr_t)(v13);
    v3[2] = (int)v13;
    if ( !v10 )
      goto LABEL_16;
    v17 = (volatile uint32_t *)v5[1];
    if ( **v6 < 0 && !v17 )
    {
      irq_disable_mmio_write(dword_11DD1C, dword_11DD14, 704);
      v17 = 0;
    }
    v25 = v5;
    v7 = v13;
    v5 = v17;
    a2 = v10;
  }
  v10 = (uint16_t)(v18 + a2 + v4 - v19);
  v22 = (uint16_t)(v20 - v4);
  if ( !v10 )
    v9 = 1;
  v11 = mmio_read_0();
  v4 = 0;
  v12 = v22;
  v13 = (volatile uint32_t *)v11;
  if ( v11 )
    goto LABEL_5;
LABEL_15:
  *((volatile uint8_t *)v3 + 32) = v11;
LABEL_16:
  *a1 = (int)(uintptr_t)(v5);
  *a3 = v4;
  return v25;
}



// rx_packet_parse_1 @ 0x11dd24
volatile uint32_t * rx_packet_parse_1(volatile uint32_t *a1, unsigned int a2, int a3, volatile uint32_t *a4, int a5) {
  volatile uint8_t **v5; // r9
  volatile uint32_t *v6; // r7
  int v7; // r5
  int v8; // r12
  volatile int16_t **v9; // r10
  volatile uint32_t *v10; // r6
  volatile uint32_t *result; // r0
  unsigned int v13; // r4
  int v14; // r3
  volatile uint32_t *v15; // r3
  volatile uint32_t *v16; // r11
  int v17; // r4
  int16_t v18; // r3
  signed int v19; // r2
  volatile uint32_t *v20; // r3
  volatile uint16_t *v22; // [sp+Ch] [bp-8h]

  v5 = (volatile uint8_t **)off_11DE34;
  v6 = (volatile uint32_t *)*a1;
  v7 = *(volatile uint16_t *)a4;
  v8 = **(volatile uint8_t **)off_11DE34;
  v9 = (volatile int16_t **)off_11DE38;
  v22 = (void *)(a4);
  if ( a2 >= 0x640 )
    a2 = 1600;
  if ( v8 == 3 )
    a4 = (void *)(uintptr_t)(off_11DE28);
  v10 = &v6[12 * a5 + 5];
  if ( v8 == 3 )
    *a4 = (int)(uintptr_t)(v10);
  result = 0;
  while ( 1 )
  {
    v17 = v6[2];
    v18 = v6[3] + 1;
    v19 = (uint16_t)(v18 - v17);
    v10[1] = a3;
    *v10 = v7 + v17;
    if ( (int)(a2 + v7) >= v19 )
    {
      v13 = (uint16_t)(v17 - v18 + v7 + a2);
      a2 = (uint16_t)(v19 - v7);
      v7 = 0;
    }
    else
    {
      v13 = 0;
    }
    if ( v8 == 3 )
    {
      v14 = a2;
      if ( a2 >= 0x800 )
        v14 = 2048;
      v10[2] = v14 | 0xA3000000;
      v10[3] = a2;
      v10[4] = a2;
      v10[5] = 262148;
    }
    a3 += a2;
    if ( !v13 )
      break;
    v15 = (volatile uint32_t *)v6[1];
    v16 = v15 + 5;
    if ( **v9 < 0 && !v15 )
    {
      irq_disable_mmio_write(dword_11DE30, dword_11DE2C, 928);
      v15 = 0;
      v8 = **v5;
    }
    if ( v8 == 3 )
      v10[8] = (int)(uintptr_t)(v16);
    result = v6;
    v10 = v16;
    v6 = v15;
    a2 = v13;
  }
  if ( v8 == 3 )
  {
    v20 = (void *)(uintptr_t)(off_11DE28);
    v10[8] = 0;
    v20[1] = (int)(uintptr_t)(v10);
  }
  *a1 = (int)(uintptr_t)(v6);
  *v22 = v7;
  return result;
}



// rx_dma_advance_cursor @ 0x11de3c
/* luna: Walks the RX descriptor chain until status bit 0 is set, updates the DMA cursor and wrap state, and returns the previous cursor value. */
int rx_dma_advance_cursor(int a1, int a2) {
  int result; // r0
  unsigned int next_cursor; // r3
  volatile uint32_t *ring_state; // r1
  int cursor_wrap_state; // r2
  int v6; // cf
  unsigned int wrap_bit; // r2

  if ( !a2 )
  {
    next_cursor = a1 + 160;
    goto LABEL_9;
  }
  if ( (*(volatile uint16_t *)(a2 + 16) & 1) != 0 )
  {
LABEL_8:
    next_cursor = (*(volatile uint32_t *)(a2 + 12) & 0xFFFFFFFC) + 4;
LABEL_9:
    ring_state = (void *)(uintptr_t)(off_11DEAC);
    cursor_wrap_state = *((volatile uint32_t *)off_11DEAC + 2);
    if ( *((volatile uint32_t *)off_11DEAC + 1) == next_cursor )
      next_cursor = *(volatile uint32_t *)off_11DEAC;
    *(volatile uint32_t *)(a1 + 152) = next_cursor;
    result = cursor_wrap_state & 0x7FFFFFFF;
    v6 = next_cursor >= (cursor_wrap_state & 0x7FFFFFFFu);
    wrap_bit = cursor_wrap_state & 0x80000000;
    if ( !v6 )
      wrap_bit += 0x80000000;
    ring_state[2] = next_cursor | wrap_bit;
    return result;
  }
  while ( 1 )
  {
    a2 = *(volatile uint32_t *)(a2 + 4);
    if ( **(volatile int16_t **)off_11DEA0 < 0 && !a2 )
      return log_assert_failure((int)aPdNull, (int)aRxlGoToLastRbd, 1119);
    if ( (*(volatile uint16_t *)(a2 + 16) & 1) != 0 )
      goto LABEL_8;
  }
}


// dma_ring_setup @ 0x11deb0
int dma_ring_setup() {
  volatile int *v0; // r2
  int v1; // r0
  volatile uint32_t *v2; // r1
  volatile uint32_t *v3; // r12
  uint64_t v4; // kr00_8
  volatile uint32_t *v5; // r5
  volatile uint32_t *v6; // r5
  int v7; // r1
  uint64_t v8; // kr08_8
  volatile uint32_t *v9; // lr
  volatile uint32_t *v10; // r7
  volatile int *v12; // r4
  int v13; // r6
  int v14; // r3

  v0 = (volatile int *)off_11DF18;
  v1 = *(volatile uint32_t *)off_11DF14;
  v2 = (void *)(uintptr_t)(off_11DF1C);
  v3 = (void *)(uintptr_t)(off_11DF38);
  v4 = *(volatile uint64_t *)*(volatile uint32_t *)off_11DF14;
  v5 = (void *)(uintptr_t)(off_11DF20);
  *(volatile uint32_t *)off_11DF18 = v4;
  *v5 = v4;
  *v2 = HIDWORD(v4) + v4 - 4;
  v6 = (void *)(uintptr_t)(off_11DF28);
  v7 = *v0;
  *(volatile uint32_t *)off_11DF24 = *v0;
  *v6 = v7;
  v8 = *(volatile uint64_t *)(v1 + 8);
  v9 = (void *)(uintptr_t)(off_11DF3C);
  v10 = (void *)(uintptr_t)(off_11DF2C);
  v0[1] = HIDWORD(v4) + v4;
  v6[1] = v8;
  v12 = (volatile int *)off_11DF30;
  v0[2] = v4;
  v13 = dword_11DF34;
  *v9 = HIDWORD(v8) + v8 - 4;
  *v3 = v8;
  *v10 = v8;
  v6[5] = v13;
  v14 = *v12;
  v0[4] = HIDWORD(v8) + v8;
  v0[3] = v8;
  v0[5] = v8;
  *v12 = v14 & 0x80000 | 0x78025;
  return HIDWORD(v8) + v8;
}



// mmio_reg_update @ 0x11df40
/* luna: Sets or clears bit 10 in one MMIO register and bit 19 in another according to bit 0 of the input, returning the updated second register value. */
unsigned int mmio_reg_update(int a1) {
  volatile unsigned int *second_register; // r1
  unsigned int result; // r0

  second_register = (volatile unsigned int *)off_11DF70;
  *(volatile uint32_t *)off_11DF6C = (a1 << 10) & 0x400 | *(volatile uint32_t *)off_11DF6C & 0xFFFFFBFF;
  result = (a1 << 19) & 0x80000 | *second_register & 0xFFF7FFFF;
  *second_register = result;
  return result;
}



// phy_rate_get @ 0x11df74
int phy_rate_get(int result) {
  unsigned int v1; // r3
  unsigned int v2; // r2
  unsigned int v3; // r2

  v1 = *(volatile uint32_t *)(result + 152);
  if ( *(volatile uint8_t *)(result + 156) )
  {
    v3 = *(volatile uint32_t *)off_11DFBC & 0x80000000;
    if ( v1 < (*(volatile uint32_t *)off_11DFBC & 0x7FFFFFFFu) )
      v3 += 0x80000000;
    *(volatile uint32_t *)off_11DFBC = v1 | v3;
  }
  else
  {
    v2 = *(volatile uint32_t *)off_11DFB8 & 0x80000000;
    if ( v1 < (*(volatile uint32_t *)off_11DFB8 & 0x7FFFFFFFu) )
      v2 += 0x80000000;
    *(volatile uint32_t *)off_11DFB8 = v1 | v2;
  }
  return result;
}



// capability_get @ 0x11dfc0
int capability_get(int a1) {
  int v1; // r4
  int v2; // r2
  int v3; // r3
  unsigned int v4; // r3
  volatile uint32_t *v5; // r1
  int v6; // r2
  int v7; // cf
  unsigned int v8; // r2
  volatile char *v10; // r0
  int v11; // r2
  int a1b; // [sp+4h] [bp-4h]
  int a1a; // [sp+4h] [bp-4h]

  if ( *(volatile uint16_t *)(a1 + 48) )
  {
    v1 = *(volatile uint32_t *)(a1 + 28);
    if ( **(volatile int16_t **)off_11E07C < 0 && !v1 )
    {
      v10 = aPdNull;
      v11 = 393;
      return log_assert_failure((int)v10, (int)aRxlRxcntrlFram, v11);
    }
    v2 = *(volatile uint32_t *)(a1 + 84);
    v3 = **(volatile uint16_t **)(v1 + 8) & 0xFC;
    *(volatile uint32_t *)(a1 + 84) = v2 & 0xFEFFFFFF;
    if ( v3 == 36 )
    {
      if ( (v2 & 0x2000) != 0 )
      {
        a1b = a1;
        tx_frame_send(a1);
        a1 = a1b;
      }
    }
    else if ( v3 == 148 && (~v2 & 0x2002) == 0 )
    {
      a1a = a1;
      txl_ba_push(a1, v2 & 0xFEFFFFFF, v2, 0);
      a1 = a1a;
    }
    v4 = (*(volatile uint32_t *)(v1 + 12) & 0xFFFFFFFC) + 4;
  }
  else
  {
    if ( **(volatile int16_t **)off_11E07C < 0 && *(volatile uint32_t *)(a1 + 28) )
    {
      v10 = aDmaHdrdescHdFi;
      v11 = 436;
      return log_assert_failure((int)v10, (int)aRxlRxcntrlFram, v11);
    }
    v4 = a1 + 160;
  }
  v5 = (void *)(uintptr_t)(off_11E080);
  v6 = *((volatile uint32_t *)off_11E080 + 5);
  if ( *((volatile uint32_t *)off_11E080 + 4) == v4 )
    v4 = *((volatile uint32_t *)off_11E080 + 3);
  *(volatile uint32_t *)(a1 + 152) = v4;
  v7 = v4 >= (v6 & 0x7FFFFFFFu);
  v8 = v6 & 0x80000000;
  if ( !v7 )
    v8 += 0x80000000;
  v5[5] = v4 | v8;
  return phy_rate_get(a1);
}


// ptr_is_null @ 0x11e090
int ptr_is_null(int result, int a2, int a3, int a4) {
  int v4; // r7
  volatile int16_t **v5; // r10
  int v6; // r11
  int v7; // r1
  unsigned int v9; // r8
  int16_t v10; // r3
  uint64_t v11; // r4
  int v12; // r6
  int v13; // r4
  int v14; // r3
  volatile uint32_t *v15; // r2
  volatile uint32_t *v16; // r5
  int v17; // r3

  if ( a2 )
  {
    v4 = result;
    v5 = (volatile int16_t **)off_11E128;
    v6 = dword_11E12C;
    result = a2;
    v7 = dword_11E124;
    v9 = 0;
    while ( 1 )
    {
      v11 = *(volatile uint64_t *)(v4 + 8);
      v10 = WORD2(v11) + 1;
      v11 = (v11 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)((uint16_t)(WORD2(v11) + 1 - v11) - a3) << 32);
      if ( result < SHIDWORD(v11) )
      {
        v12 = 0;
      }
      else
      {
        v12 = (uint16_t)(v11 - v10 + a3 + result);
        result = WORD2(v11);
      }
      v13 = v11 + a3;
      v14 = a4 + 4 * (v9 >> 2);
      if ( (unsigned int)(result + 3) >> 2 )
      {
        v15 = (volatile uint32_t *)(a4 + 4 * (v9 >> 2));
        v16 = (volatile uint32_t *)(v14 + 4 * ((unsigned int)(result + 3) >> 2));
        v17 = v13 - v14;
        do
        {
          *v15 = *(volatile uint32_t *)((volatile char *)v15 + v17);
          ++v15;
        }
        while ( v15 != v16 );
      }
      if ( !v12 )
        break;
      v4 = *(volatile uint32_t *)(v4 + 4);
      v9 = (uint16_t)(v9 + result);
      if ( **v5 < 0 && !v4 )
      {
        irq_disable_mmio_write(v6, v7, 1189);
        v7 = dword_11E124;
      }
      result = v12;
      a3 = 0;
    }
  }
  return result;
}



// op_mode_get @ 0x11e130
int op_mode_get(int a1) {
  volatile uint32_t *v1; // r4
  int result; // r0
  unsigned int v3; // r3
  int v4; // r1
  int v5; // r2

  v1 = (void *)(uintptr_t)(off_11E180);
  if ( *((volatile uint8_t *)off_11E180 + 33) )
    *(volatile uint32_t *)(*((volatile uint32_t *)off_11E180 + 6) + 4) = a1;
  else
    *((volatile uint32_t *)off_11E180 + 4) = a1;
  result = *((volatile uint8_t *)off_11E184 + 193);
  v3 = v1[7] + v1[3];
  v4 = v1[5] + v1[1];
  v5 = v1[2];
  v1[5] = v4;
  v1[7] = v3;
  *((volatile uint8_t *)v1 + 33) = 1;
  v1[6] = v5;
  if ( v3 >= result << 9 )
  {
    result = sub_110edc(v1[4], v4, v5);
    v1[4] = 0;
    v1[5] = 0;
    v1[6] = 0;
    v1[7] = 0;
    *((volatile uint8_t *)v1 + 33) = 0;
  }
  return result;
}



// tx_packet_start @ 0x11e188
int tx_packet_start(int a1, int a2, int a3, uint16_t a4, int a5, int a6) {
  volatile uint32_t *v6; // r8
  volatile uint8_t **v7; // r7
  int v8; // r12
  volatile uint8_t *v9; // r5
  int v11; // r3
  int v14; // r3
  volatile uint32_t *v15; // r0
  int v16; // r3
  volatile int *v18; // r5
  volatile uint32_t *v19; // r8
  uint8_t v20; // r7
  volatile uint32_t *v21; // r0
  volatile uint16_t *v22; // r5
  volatile int *v23; // r9
  int v24; // r10
  int v25; // cc
  int v26; // r0
  volatile uint32_t *v27; // r0
  int v28; // r1
  int v29; // r3
  int v30; // r0
  volatile uint8_t *v31; // r1
  int v32; // r2
  char v33; // r10
  int v34; // r2
  int v35; // r3
  volatile uint8_t *v36; // r5
  int v37; // r2
  volatile int *v38; // r9
  int v39; // r0
  int v40; // r3
  int v41; // r2
  volatile uint32_t *v42; // r0
  int v43; // r7
  int v44; // r2
  int v45; // r12
  int v46; // r2
  volatile int *v47; // r4
  int v48; // r0
  int v49; // r3
  int v50; // r2
  struct __attribute__((packed)) { int a4a; // [sp+Eh] [bp-Eh] BYREF
  char _pad1[2]; int a1a[2]; // [sp+14h] [bp-8h] BYREF
  } _frame;
  v7 = (volatile uint8_t **)off_11E41C;
  v8 = *(volatile uint32_t *)(a1 + 28);
  v9 = *(volatile uint8_t **)off_11E41C;
  _frame.a1a[0] = v8;
  _frame.a4a = (_frame.a4a & ~0xFFFFu) | ((uint16_t)(a4) & 0xFFFFu);
  v11 = *v9;
  if ( v11 != 2 )
    goto LABEL_2;
  v22 = (void *)(uintptr_t)(off_11E42C);
  if ( *((volatile uint32_t *)off_11E42C + 2057) )
  {
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(volatile uint32_t *)off_11E430 = 1;
    }
    v23 = (volatile int *)off_11E450;
    v24 = dword_11E454;
    v25 = (uint16_t)v22[4122] > 0x186u;
    ++*(volatile uint32_t *)off_11E450;
    v26 = dword_11E434;
    if ( v25 )
      v22[4122] = 0;
    v27 = list_pop(v26);
    v28 = *(volatile uint32_t *)off_11E438;
    v29 = (uint16_t)v22[4122];
    v6 = v27;
    v30 = *(volatile uint32_t *)off_11E438 + 8 * v29;
    *((volatile uint16_t *)v6 + 6) = v29;
    *(volatile uint32_t *)(v30 + 4) = a1 + 48;
    *(volatile uint32_t *)(v28 + 8 * v29) = v24;
    v31 = (void *)(uintptr_t)(off_11E43C);
    v6[1] = v30;
    v32 = *v23;
    v33 = *((volatile uint8_t *)v22 + 3074) + 1;
    v30 = (v30 & ~0xFFu) | ((uint8_t)(v31[3] + 1) & 0xFFu);
    v22[4122] = v29 + 1;
    *((volatile uint8_t *)v22 + 3074) = v33;
    v31[3] = v30;
    if ( v32 )
    {
      v34 = v32 - 1;
      v35 = *(volatile uint32_t *)off_11E430;
      *v23 = v34;
      if ( !v34 )
      {
        if ( v35 )
          __enable_irq();
      }
    }
    v11 = **v7;
    if ( v11 == 2 )
    {
      rx_packet_handler(_frame.a1a, a2, (void *)(&_frame.a4a));
      v14 = **v7;
      if ( v14 != 2 )
        goto LABEL_5;
LABEL_25:
      v36 = (void *)(uintptr_t)(off_11E43C);
      if ( !*((volatile uint8_t *)off_11E43C + 2) )
        goto LABEL_6;
      v37 = v6[1];
      v6[2] = *(volatile uint16_t *)off_11E43C + 58;
      *(volatile uint8_t *)(v37 + 3) &= 0x3Fu;
      *((volatile uint8_t *)v6 + 14) = v36[3];
      *v6 = 0;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(volatile uint32_t *)off_11E430 = 1;
      }
      v38 = (volatile int *)off_11E450;
      v39 = dword_11E440;
      ++*(volatile uint32_t *)off_11E450;
      co_list_push_back(v39, v6);
      ((int (*)())rf_is_idle)();
      if ( *v38 )
      {
        v40 = *v38 - 1;
        v41 = *(volatile uint32_t *)off_11E430;
        *v38 = v40;
        if ( !v40 )
        {
          if ( v41 )
            __enable_irq();
        }
      }
      *(volatile uint32_t *)v36 = 0;
      *((volatile uint32_t *)v36 + 1) = 0;
      v14 = **v7;
LABEL_5:
      if ( v14 == 1 )
      {
        v18 = (volatile int *)off_11E424;
        if ( *((volatile uint8_t *)off_11E424 + 32) )
        {
          v42 = (void *)(uintptr_t)(mmio_read_0());
          v43 = (int)v42;
          if ( v42 )
          {
            if ( *((volatile uint8_t *)v18 + 32) )
            {
              v44 = *v18;
              v45 = v18[1] + 1;
              v42[2] = (v45 << 24) & 0x7F000000 | v42[2] & 0x80FFFFFF;
              v18[1] = v45;
              tx_desc_set_control(v42, a1 + 48, v44, 0x3Au, 0);
              v46 = LOBYTE(((volatile uint32_t *)(uintptr_t)off_11E448)[48]);
              v18[3] += 58;
              if ( v46 )
                op_mode_get(v43);
              else
                sub_110edc(v43, v18[1], v18[2]);
              *(volatile uint8_t *)off_11E44C |= 1u;
              v18[1] = 0;
              v18[3] = 0;
              *v18 = 0;
              v18[2] = 0;
              *((volatile uint8_t *)v18 + 32) = 0;
              goto LABEL_6;
            }
          }
          else
          {
            *(volatile uint8_t *)(a1 + 16) |= 1u;
            alloc_tx_event("partial no tx_dscr_hdr\r\n");
            *((volatile uint8_t *)v18 + 32) = 0;
          }
        }
        check_feature_flag(1024, "partial no tx_dscr_hdr!!\r\n");
        v19 = (volatile uint32_t *)*v18;
        *(volatile uint8_t *)(a1 + 16) |= 1u;
        if ( v19 && v18[1] )
        {
          v20 = 0;
          do
          {
            v21 = v19;
            v19 = (volatile uint32_t *)v19[1];
            mmio_write_0(v21);
            ++v20;
          }
          while ( v20 < (unsigned int)v18[1] );
        }
        v18[1] = 0;
        v18[3] = 0;
        *v18 = 0;
        v18[2] = 0;
      }
LABEL_6:
      rx_dma_advance_cursor(a1, _frame.a1a[0]);
      v15 = (void *)(uintptr_t)(off_11E420);
      *(volatile uint32_t *)(a1 + 4) = a5;
      v16 = v15[14];
      *(volatile uint32_t *)(a1 + 8) = a6;
      if ( v16 )
        return co_list_push_back((int)(v15 + 14), (volatile uint32_t *)a1);
      else
        return co_list_push_back(dword_11E444, (volatile uint32_t *)a1);
    }
LABEL_2:
    if ( v11 == 1 )
      rx_packet_process_2((void *)(_frame.a1a), a2, (void *)(&_frame.a4a));
    else
      rx_packet_parse_1((void *)(_frame.a1a), a2, a3, (void *)(&_frame.a4a), 0);
    v14 = **v7;
    if ( v14 != 2 )
      goto LABEL_5;
    goto LABEL_25;
  }
  *(volatile uint8_t *)(a1 + 16) |= 1u;
  rx_dma_advance_cursor(a1, v8);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_11E4B4 = 1;
  }
  v47 = (volatile int *)off_11E4B8;
  ++*(volatile uint32_t *)off_11E4B8;
  v48 = ((int (*)())rf_is_idle)();
  if ( *v47 )
  {
    v49 = *v47 - 1;
    v50 = *(volatile uint32_t *)off_11E4B4;
    *v47 = v49;
    if ( !v49 )
    {
      if ( v50 )
        __enable_irq();
    }
  }
  return debug_printf("rxl err, no buf %d\n", v48);
}


// tx_packet_complete @ 0x11e4c4
int tx_packet_complete(int a1) {
  volatile uint32_t *v1; // r8
  int v2; // r10
  int v3; // r11
  volatile uint32_t *v4; // r6
  volatile uint8_t **v5; // r5
  int16_t v6; // r2
  volatile uint8_t *v7; // r3
  int v8; // r4
  int v9; // r3
  unsigned int v10; // r7
  int v11; // r3
  volatile int *v12; // r6
  int v13; // r11
  int v14; // r3
  uint8_t v15; // r7
  volatile uint32_t *v16; // r4
  int v17; // r11
  volatile uint32_t *v18; // r0
  int v19; // r3
  volatile uint16_t *v20; // r6
  int v21; // r2
  volatile int *v22; // r7
  int v23; // r0
  int v24; // r3
  int v25; // r2
  volatile uint16_t *v27; // r7
  volatile int *v28; // r9
  unsigned int v29; // r1
  int v30; // r0
  volatile uint32_t *v31; // r0
  int v32; // r12
  int v33; // r3
  volatile uint32_t *v34; // r1
  volatile uint8_t *v35; // r12
  int v36; // r0
  char v37; // r2
  int v38; // r0
  int v39; // r3
  volatile int *v40; // r2
  int v41; // r3
  int v42; // r1
  int v43; // r3
  unsigned int CPSR; // r0
  volatile uint32_t *v45; // r3
  volatile uint32_t *v46; // r0
  int v47; // r1
  int v48; // r2
  volatile uint32_t *v49; // r2
  volatile uint32_t *v50; // r5
  volatile uint32_t *v51; // r0
  int v52; // r7
  int v53; // r2
  int v54; // r12
  int v55; // r2
  volatile uint8_t *v56; // r1
  char v57; // r2
  volatile uint8_t *v58; // r3
  int v59; // r1
  volatile int *v60; // r4
  int v61; // r0
  int v62; // r3
  int v63; // r2
  struct __attribute__((packed)) { int a2; // [sp+Ch] [bp-10h]
  char _pad1[2]; uint16_t a4; // [sp+12h] [bp-Ah] BYREF
  int a4_2[2]; // [sp+14h] [bp-8h] BYREF
  } _frame;
  v4 = (void *)(uintptr_t)(off_11E6F8);
  v5 = (volatile uint8_t **)off_11E6FC;
  v6 = *((volatile uint8_t *)off_11E6F8 + 50);
  v7 = *(volatile uint8_t **)off_11E6FC;
  v8 = a1;
  _frame.a4_2[0] = *(volatile uint32_t *)(a1 + 28);
  _frame.a4 = v6;
  v9 = *v7;
  if ( v9 == 3 )
  {
    v2 = list_foreach_1();
    v9 = **v5;
    v3 = v2 + 60;
  }
  if ( v9 == 2 )
  {
    v27 = (void *)(uintptr_t)(off_11E71C);
    if ( !*((volatile uint32_t *)off_11E71C + 2057) )
    {
      v59 = _frame.a4_2[0];
      *(volatile uint8_t *)(v8 + 16) |= 1u;
      rx_dma_advance_cursor(v8, v59);
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(volatile uint32_t *)off_11E92C = 1;
      }
      v60 = (volatile int *)off_11E930;
      ++*(volatile uint32_t *)off_11E930;
      v61 = ((int (*)())rf_is_idle)();
      if ( *v60 )
      {
        v62 = *v60 - 1;
        v63 = *(volatile uint32_t *)off_11E92C;
        *v60 = v62;
        if ( !v62 )
        {
          if ( v63 )
            __enable_irq();
        }
      }
      return debug_printf("err, no buf %d\n", v61);
    }
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(volatile uint32_t *)off_11E710 = 1;
    }
    v28 = (volatile int *)off_11E714;
    v29 = (uint16_t)v27[4122];
    v30 = dword_11E720;
    ++*(volatile uint32_t *)off_11E714;
    if ( v29 > 0x186 )
      v27[4122] = 0;
    v31 = list_pop(v30);
    v32 = *(volatile uint32_t *)off_11E724;
    v33 = (uint16_t)v27[4122];
    *((volatile uint16_t *)v31 + 6) = v33;
    v34 = (volatile uint32_t *)(v32 + 8 * v33);
    v34[1] = v8 + 48;
    *v34 = dword_11E728;
    v35 = (void *)(uintptr_t)(off_11E70C);
    v31[1] = (int)(uintptr_t)(v34);
    v1 = v31;
    v36 = *v28;
    v34 = (void *)(uintptr_t)(((uintptr_t)(v34) & ~0xFFu) | ((uint8_t)(*((volatile uint8_t *)v27 + 3074) + 1) & 0xFFu));
    v37 = v35[3] + 1;
    v27[4122] = v33 + 1;
    *((volatile uint8_t *)v27 + 3074) = (uint8_t)v34;
    v35[3] = v37;
    if ( v36 )
    {
      v38 = v36 - 1;
      v39 = *(volatile uint32_t *)off_11E710;
      *v28 = v38;
      if ( !v38 )
      {
        if ( v39 )
          __enable_irq();
      }
    }
    v10 = *(volatile uint16_t *)(v8 + 48);
    if ( **(volatile int16_t **)off_11E700 >= 0 )
    {
LABEL_37:
      v9 = **v5;
      if ( v9 == 2 )
      {
        rx_packet_handler(_frame.a4_2, v10, &_frame.a4);
        goto LABEL_7;
      }
LABEL_5:
      if ( v9 == 1 )
      {
        rx_packet_process_2((void *)(_frame.a4_2), v10, &_frame.a4);
      }
      else
      {
        rx_packet_parse_1((void *)(_frame.a4_2), v10, v3, (void *)(&_frame.a4), 0);
        v4[7] = v10 + v3;
      }
LABEL_7:
      unknown_1018f0((volatile uint64_t *)(v8 + 88), 0);
      v11 = **v5;
      if ( v11 == 3 )
      {
        v40 = (volatile int *)off_11E918;
        v41 = *((volatile uint32_t *)off_11E918 + 1);
        *(volatile uint32_t *)(v8 + 100) = dword_11E91C;
        *(volatile uint32_t *)(v8 + 104) = v8 + 48;
        v42 = dword_11E920;
        *(volatile uint32_t *)(v8 + 108) = v2;
        *(volatile uint32_t *)(v41 + 32) = v8 + 104;
        *(volatile uint32_t *)(v8 + 112) = v42;
        *(volatile uint32_t *)(v8 + 116) = 58;
        *(volatile uint32_t *)(v8 + 120) = 58;
        _frame.a2 = v8 + 104;
        *(volatile uint32_t *)(v8 + 124) = 262148;
        *(volatile uint32_t *)(v8 + 136) = 0;
        goto LABEL_41;
      }
      if ( v11 != 1 )
      {
        if ( v11 == 2 )
        {
          v20 = (volatile uint16_t *)off_11E940;
          if ( *((volatile uint8_t *)off_11E940 + 2) )
          {
LABEL_17:
            v21 = v1[1];
            v1[2] = *v20 + 58;
            *(volatile uint8_t *)(v21 + 3) &= 0x3Fu;
            *((volatile uint8_t *)v1 + 14) = *((volatile uint8_t *)v20 + 3);
            *v1 = 0;
            if ( (__get_CPSR() & 1) == 0 )
            {
              __disable_irq();
              *(volatile uint32_t *)off_11E710 = 1;
            }
            v22 = (volatile int *)off_11E714;
            v23 = dword_11E718;
            ++*(volatile uint32_t *)off_11E714;
            co_list_push_back(v23, v1);
            ((int (*)())rf_is_idle)();
            if ( *v22 )
            {
              v24 = *v22 - 1;
              v25 = *(volatile uint32_t *)off_11E710;
              *v22 = v24;
              if ( !v24 )
              {
                if ( v25 )
                  __enable_irq();
              }
            }
            *(volatile uint32_t *)v20 = 0;
            *((volatile uint32_t *)v20 + 1) = 0;
            if ( **v5 != 3 )
              return rx_dma_advance_cursor(v8, _frame.a4_2[0]);
            goto LABEL_65;
          }
        }
        return rx_dma_advance_cursor(v8, _frame.a4_2[0]);
      }
      v12 = (volatile int *)off_11E704;
      if ( *((volatile uint8_t *)off_11E704 + 32) )
      {
        v51 = (void *)(uintptr_t)(mmio_read_0());
        v52 = (int)v51;
        if ( v51 )
        {
          if ( *((volatile uint8_t *)v12 + 32) )
          {
            v53 = *v12;
            v54 = v12[1] + 1;
            v51[2] = (v54 << 24) & 0x7F000000 | v51[2] & 0x80FFFFFF;
            v12[1] = v54;
            tx_desc_set_control(v51, v8 + 48, v53, 0x3Au, 0);
            v55 = LOBYTE(((volatile uint32_t *)(uintptr_t)off_11E944)[48]);
            v12[3] += 58;
            if ( v55 )
              op_mode_get(v52);
            else
              sub_110edc(v52, v12[1], v12[2]);
            v56 = (void *)(uintptr_t)(off_11E948);
            v57 = *(volatile uint8_t *)off_11E948;
            v12[1] = 0;
            v12[3] = 0;
            *v12 = 0;
            v12[2] = 0;
            *((volatile uint8_t *)v12 + 32) = 0;
            v58 = *v5;
            *v56 = v57 | 1;
            v19 = *v58;
            if ( v19 == 2 )
              goto LABEL_16;
            goto LABEL_64;
          }
        }
        else
        {
          *(volatile uint8_t *)(v8 + 16) |= 1u;
          alloc_tx_event(aNoTxDscrHdr_0);
          *((volatile uint8_t *)v12 + 32) = 0;
        }
      }
      check_feature_flag(1024, aNoTxDscrHdr);
      v13 = *v12;
      *(volatile uint8_t *)(v8 + 16) |= 1u;
      if ( v13 && v12[1] )
      {
        v14 = v8;
        v15 = 0;
        v16 = (volatile uint32_t *)v13;
        v17 = v14;
        do
        {
          v18 = v16;
          v16 = (volatile uint32_t *)v16[1];
          mmio_write_0(v18);
          ++v15;
        }
        while ( v15 < (unsigned int)v12[1] );
        v8 = v17;
      }
      v12[1] = 0;
      v12[3] = 0;
      *v12 = 0;
      v12[2] = 0;
      v19 = **v5;
      if ( v19 == 2 )
      {
LABEL_16:
        v20 = (volatile uint16_t *)off_11E70C;
        if ( *((volatile uint8_t *)off_11E70C + 2) )
          goto LABEL_17;
        return rx_dma_advance_cursor(v8, _frame.a4_2[0]);
      }
LABEL_64:
      if ( v19 == 3 )
      {
LABEL_65:
        v40 = (volatile int *)off_11E918;
LABEL_41:
        handle_radio_event(*v40, _frame.a2, 5);
        while ( (*(volatile uint32_t *)off_11E924 & 0x800) == 0 )
          ;
        v43 = *(volatile uint32_t *)off_11E924;
        if ( (*(volatile uint32_t *)off_11E924 & 0x40000) != 0 )
          *(volatile uint32_t *)off_11E924 |= 0x4000000u;
        if ( (v43 & 0x800) != 0 )
        {
          CPSR = __get_CPSR();
          *(volatile uint32_t *)(dword_11E928 + 4428) |= 0x8000000u;
          if ( CPSR )
          {
            *((volatile uint32_t *)off_11E934 + 5) = 0;
          }
          else
          {
            if ( (__get_CPSR() & 1) == 0 )
            {
              __disable_irq();
              *(volatile uint32_t *)off_11E92C = 1;
            }
            v45 = (void *)(uintptr_t)(off_11E930);
            v46 = (void *)(uintptr_t)(off_11E934);
            v47 = *(volatile uint32_t *)off_11E930;
            v48 = *(volatile uint32_t *)off_11E930 + 1;
            *(volatile uint32_t *)off_11E930 = v48;
            v46[5] = 0;
            if ( v48 )
            {
              v49 = (void *)(uintptr_t)(off_11E92C);
              *v45 = v47;
              if ( !v47 )
              {
                if ( *v49 )
                  __enable_irq();
              }
            }
          }
        }
        v50 = (void *)(uintptr_t)(off_11E938);
        while ( !*(volatile uint32_t *)off_11E938 )
          ;
        co_list_push_back(((volatile uint32_t *)(uintptr_t)off_11E93C)[0] + 620, (volatile uint32_t *)(v2 - 20));
        *v50 = 1;
        rf_cmd_sleep();
        return rx_dma_advance_cursor(v8, _frame.a4_2[0]);
      }
      return rx_dma_advance_cursor(v8, _frame.a4_2[0]);
    }
  }
  else
  {
    v10 = *(volatile uint16_t *)(v8 + 48);
    if ( **(volatile int16_t **)off_11E700 >= 0 )
      goto LABEL_5;
  }
  if ( !v10 )
    return log_assert_failure((int)aMpduLen0, (int)aRxlMpduTransfe, 1545);
  if ( v10 <= 0x3000 )
    goto LABEL_37;
  return log_assert_failure((int)aMpduLenRwnxMax, (int)aRxlMpduTransfe, 1547);
}


// tx_packet_kick @ 0x11e960
int tx_packet_kick(int a1) {
  void *v2; // r0
  volatile uint32_t *v3; // r1
  int v4; // r0
  char v5; // r2

  rx_dma_advance_cursor(a1, *(volatile uint32_t *)(a1 + 28));
  v2 = (void *)(uintptr_t)(off_11E9B0);
  if ( *((volatile uint32_t *)off_11E9B0 + 14) )
  {
    *(volatile uint8_t *)(a1 + 16) |= 1u;
    *(volatile uint32_t *)(a1 + 4) = 0;
    v3 = (volatile uint32_t *)a1;
    v4 = (int)v2 + 56;
    return co_list_push_back(v4, v3);
  }
  v4 = off_11E9B4;
  if ( *(volatile uint32_t *)off_11E9B4 )
  {
    v5 = *(volatile uint8_t *)(a1 + 16);
    *(volatile uint32_t *)(a1 + 4) = 0;
    *(volatile uint8_t *)(a1 + 16) = v5 | 1;
    v3 = (volatile uint32_t *)a1;
    return co_list_push_back(v4, v3);
  }
  return phy_rate_get(a1);
}


// check_fw_rom_signature @ 0x11e9b8
unsigned int check_fw_rom_signature() {
  int v0; // r3
  unsigned int result; // r0
  unsigned int v2; // r3
  int v3; // r3

  v0 = *((volatile uint32_t *)off_11E9EC + 2);
  if ( v0 == *(volatile uint32_t *)off_11E9F0 )
    return 0;
  result = v0 & 0x7FFFFFFF;
  if ( *((volatile uint32_t *)off_11E9EC + 1) - (v0 & 0x7FFFFFFFu) <= 0x9F )
  {
    v2 = v0 & 0x80000000;
    if ( result > *(volatile uint32_t *)off_11E9EC )
      v2 += 0x80000000;
    v3 = v2 | *(volatile uint32_t *)off_11E9EC;
    *((volatile uint32_t *)off_11E9EC + 2) = v3;
    return v3 & 0x7FFFFFFF;
  }
  return result;
}



// read_chip_revision @ 0x11e9f4
int read_chip_revision(int result) {
  int v1; // r4
  int16_t v2; // r2
  int v3; // r1

  v1 = result;
  if ( **(volatile int16_t **)off_11EA70 < 0 && *(volatile uint32_t *)(result + 20) != dword_11EA78 )
    result = irq_disable_mmio_write(dword_11EA80, dword_11EA7C, 1811);
  v2 = *(volatile uint16_t *)(v1 + 48);
  if ( v2 )
  {
    switch ( *(volatile uint32_t *)(v1 + 84) & 0x7C )
    {
      case 4:
      case 8:
        *(volatile uint16_t *)(v1 + 48) = v2 - 8;
        break;
      case 0xC:
        *(volatile uint16_t *)(v1 + 48) = v2 - 12;
        break;
      case 0x10:
      case 0x14:
      case 0x18:
      case 0x1C:
        *(volatile uint16_t *)(v1 + 48) = v2 - 20;
        break;
      default:
        *(volatile uint16_t *)(v1 + 48) = v2 - 4;
        break;
    }
  }
  v3 = dword_11EA74;
  *(volatile uint8_t *)(v1 + 16) = 2;
  *(volatile uint8_t *)(v1 + 156) = 0;
  *(volatile uint32_t *)(v1 + 12) = v1;
  *(volatile uint32_t *)(v1 + 4) = v3;
  return result;
}



// disable_watchdog @ 0x11ea84
int disable_watchdog() {
  volatile uint32_t *v0; // r2
  int result; // r0

  v0 = (void *)(uintptr_t)(off_11EAB4);
  *(volatile uint32_t *)off_11EAB0 = 0x10000;
  *v0 &= ~0x10000u;
  result = irq_disable_global_2(0x80000);
  if ( *(volatile uint8_t *)off_11EAB8 )
    return poll_rf_register_done(result);
  return result;
}



// check_hw_fw_status @ 0x11eabc
void check_hw_fw_status() {
  volatile uint32_t *v0; // r5
  volatile uint32_t *v1; // r6
  int v2; // r3
  int v3; // r7
  volatile uint32_t *v4; // r8
  int v5; // r3
  int v6; // r4
  int v7; // r2
  int v8; // r12
  unsigned int v9; // r1
  unsigned int v10; // r2
  unsigned int v11; // r3
  unsigned int v12; // r2

  v0 = (void *)(uintptr_t)(off_11EB40);
  v1 = (void *)(uintptr_t)(off_11EB44);
  v2 = *((volatile uint32_t *)off_11EB40 + 5);
  if ( v2 != *(volatile uint32_t *)off_11EB44 )
  {
    v3 = dword_11EB48;
    v4 = (void *)(uintptr_t)(off_11EB50);
    do
    {
      v8 = v0[4];
      v9 = v2 & 0x7FFFFFFF;
      v10 = v8 - (v2 & 0x7FFFFFFF);
      v11 = v2 & 0x80000000;
      if ( v10 > 0x9F )
      {
        v5 = v0[5];
      }
      else
      {
        v12 = v0[3];
        if ( v9 > v12 )
          v11 += 0x80000000;
        v5 = v11 | v12;
        v0[5] = v5;
      }
      v6 = v5 & 0x7FFFFFFF;
      v7 = *(volatile uint32_t *)((v5 & 0x7FFFFFFF) + 0x14);
      if ( v7 != v3 )
        alloc_tx_event(
          "rxbuf2 %08x,%08x: start %08x, end %08x, read %08x, wrptr %08x, rdptr %08x\r\n",
          v5 & 0x7FFFFFFF,
          v7,
          v0[3],
          v8,
          v5,
          *v1,
          *v4);
      read_chip_revision(v6);
      *(volatile uint8_t *)(v6 + 156) = 1;
      capability_get(v6);
      v2 = v0[5];
    }
    while ( v2 != *v1 );
  }
}


