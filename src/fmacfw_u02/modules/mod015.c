// init_flag_check @ 0x117f4c
/* luna: Updates a TX block-ack descriptor for a frame, validating the matching entry and caching its header when applicable. */
int init_flag_check(int a1, int a2, int a3, int a4) {
  int v4; // r2
  volatile uint32_t *v6; // r0
  volatile int16_t *v7; // r1
  int v8; // r4
  unsigned int v9; // r2
  int result; // r0
  int v11; // r1
  unsigned int v12; // r3
  int v13; // r2

  if ( *(volatile uint8_t *)off_118038 )
    return event_dispatch(aBaWarn, a2, a3, a4);
  v4 = (v4 & ~0xFFFFu) | ((uint16_t)(*((volatile uint8_t *)off_11803C + 190)) & 0xFFFFu);
  if ( (*((volatile uint32_t *)off_11803C + 52) & 1) == 0 )
    v4 = (*(volatile uint32_t *)(a1 + 84) >> 11) & 3;
  v6 = mem_word_load(dword_118040 + 84 * (uint16_t)v4 + 28);
  v7 = *(volatile int16_t **)off_118044;
  v8 = (int)v6;
  if ( **(volatile int16_t **)off_118044 < 0 && !v6 )
    return bad_func_0x12f408((int)aAggDescNull, (int)aTxlBaPush, 369);
  v9 = *(volatile uint32_t *)(a1 + 84);
  result = v9 << 6;
  *(volatile uint16_t *)(v8 + 8) |= 0x20u;
  if ( (v9 & 0x2000000) != 0 )
  {
    result = (uint16_t)(v9 >> 15);
    if ( *v7 < 0 && (result & 0x3F0) == 0 )
      return bad_func_0x12f408((int)aKeyIdxHwMmSecD, (int)aTxlIsBaValid, 217);
    if ( ((v9 >> 15) & 0x3FF) - 16 == *(volatile uint8_t *)(v8 + 12) )
    {
      v11 = *(volatile uint32_t *)(*(volatile uint32_t *)(a1 + 28) + 8);
      v12 = *(volatile uint16_t *)(v11 + 16);
      result = v12 & 0x1E;
      if ( result == 22 )
      {
        result = parse_rx_header(a1, v8);
        if ( result )
          goto LABEL_17;
      }
      else if ( (v9 & 0x200) == 0 )
      {
        v13 = *(volatile uint16_t *)(a1 + 48);
        if ( (v13 == 52 || v13 == 28) && *(volatile uint8_t *)(v8 + 13) == v12 >> 12 )
        {
          result = (int)memcpy((volatile char *)(v8 + 228), (volatile char *)(v11 + 18), 0x22u);
          *(volatile uint32_t *)(v8 + 224) = v8 + 228;
LABEL_17:
          *(volatile uint16_t *)(v8 + 8) |= 0x40u;
        }
      }
    }
  }
  return result;
}


// invoke_callback_1 @ 0x11805c
/* luna: Obtains a callback-produced payload, wraps it in a queue entry, and appends it to the SDIO transmit work queue with interrupt-safe synchronization. */
volatile uint32_t *invoke_callback_1() {
  volatile uint32_t *result; // r0
  volatile uint32_t *v1; // r4
  volatile uint32_t *v2; // r0
  volatile uint32_t *v3; // r5
  volatile int *v4; // r2
  int v5; // r0
  volatile int *v6; // r6
  volatile uint32_t *v7; // r2
  int v8; // r1
  volatile uint16_t *v9; // r4
  int16_t v10; // r2
  int v11; // r3
  volatile uint32_t *v12; // r5
  int v13; // r1
  int v14; // r3
  int v15; // r3

  result = (volatile uint32_t *)(*(int ( **)(uint32_t))(*((volatile uint32_t *)off_118110 + 2) + 16))(*((volatile uint32_t *)off_118110 + 1));
  if ( result )
  {
    v1 = result;
    v2 = is_scan_enabled();
    v3 = v2;
    if ( v2 )
    {
      v4 = (void *)(uintptr_t)(off_118114);
      *v2 = 0;
      v5 = *v4;
      v3[1] = 0;
      v3[2] = 0;
      *v3 = (int)(uintptr_t)((volatile char *)v1 + v5);
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(volatile uint32_t *)off_118118 = 1;
      }
      v6 = (volatile int *)off_11811C;
      v7 = (void *)(uintptr_t)(off_118120);
      v8 = *(volatile uint32_t *)off_11811C + 1;
      *(volatile uint32_t *)off_11811C = v8;
      *v7 = 1;
      while ( (*v7 & 2) != 0 )
        ;
      if ( *(volatile uint32_t *)off_118124 )
      {
        v9 = (void *)(uintptr_t)(off_11812C);
        v15 = *((volatile uint32_t *)off_11812C + 1);
        if ( v15 )
        {
          *(volatile uint32_t *)(v15 + 4) = (int)(uintptr_t)(v3);
        }
        else
        {
          event_dispatch(aSdioTailError);
          v8 = *v6;
        }
      }
      else
      {
        if ( *(volatile uint32_t *)off_118128 )
        {
          event_dispatch(aBug);
          v8 = *v6;
        }
        v9 = (void *)(uintptr_t)(off_11812C);
        *(volatile uint32_t *)off_118128 = (int)(uintptr_t)(v3);
      }
      result = (void *)(uintptr_t)(off_118124);
      v10 = v9[6];
      v11 = *(volatile uint32_t *)off_118124;
      *((volatile uint32_t *)v9 + 1) = (int)(uintptr_t)(v3);
      v12 = (void *)(uintptr_t)(off_118130);
      v9[6] = v10 + 1;
      *result = v11 + 1;
      *v12 = 1;
      if ( v8 )
      {
        v13 = v8 - 1;
        v14 = *(volatile uint32_t *)off_118118;
        *v6 = v13;
        if ( !v13 )
        {
          if ( v14 )
            __enable_irq();
        }
      }
    }
    else
    {
      return (volatile uint32_t *)is_controller_mode(v1);
    }
  }
  return result;
}


// rf_rssi_process @ 0x11813c
volatile uint32_t * rf_rssi_process(int a1) {
  int v1; // s16
  int v2; // r4
  volatile uint32_t *v3; // r0
  int v4; // r4
  volatile int *v5; // r7
  int v6; // r8
  int v7; // r6
  int v8; // r10
  int v9; // r11
  unsigned int v10; // r5
  int v11; // r9
  int v12; // r10
  int v13; // r3
  int v14; // r2
  volatile uint8_t **v15; // r11
  int v16; // r9
  unsigned int v17; // r2
  unsigned int v18; // r1
  volatile uint32_t *v19; // r0
  volatile uint8_t *v20; // r3
  int v21; // r3
  int v22; // r2
  int v23; // r5
  int v24; // r2
  int v25; // r9
  int v26; // r3
  int v27; // r2
  uint16_t v28; // r1
  unsigned int v29; // r3
  unsigned int v30; // r2
  int v31; // r5
  int v32; // r3
  int v33; // r3
  int v34; // r11
  unsigned int v35; // r3
  int v36; // r2
  volatile uint16_t *v37; // r2
  unsigned int v38; // r3
  unsigned int v39; // r1
  int v40; // r3
  int v41; // r10
  int v42; // r3
  int v43; // r3
  int v44; // r11
  unsigned int v45; // r3
  int v46; // r2
  int v47; // r1
  uint16_t v48; // r2
  void *v49; // r2
  int v50; // r2
  uint16_t v51; // r1
  void *v52; // r2
  unsigned int v53; // r6
  volatile unsigned int v54; // r0
  uint16_t v55; // r6
  int v56; // r1
  void *v57; // r2
  struct __attribute__((packed)) { int a2; // [sp+4h] [bp-28h]
  char _pad1[4]; int a3; // [sp+Ch] [bp-20h]
  union { int v61; // [sp+10h] [bp-1Ch]
  int v62; }; // [sp+10h] [bp-1Ch]
  union { int v63; // [sp+14h] [bp-18h]
  int v64; }; // [sp+14h] [bp-18h]
  int v65; // [sp+18h] [bp-14h]
  int v66; // [sp+1Ch] [bp-10h]
  uint32_t result[3]; // [sp+20h] [bp-Ch] BYREF
  } _frame;
  v1 = dword_118434 + 8 * a1;
  v2 = ((volatile uint32_t *)(uintptr_t)off_118438)[a1];
  if ( **(volatile int16_t **)off_118430 < 0 && (v2 & *(volatile uint32_t *)off_11891C) == 0 )
    mmio_clear_register((int)aKeEvtGetEvtBit, (int)aTxlCfmEvt_0, 612);
  unknown_func_12d14c(v2);
  v3 = zero_8_bytes(_frame.result);
  v4 = *(volatile uint32_t *)(dword_118434 + 8 * a1);
  if ( v4 )
  {
    v5 = (volatile int *)off_11843C;
    _frame.a3 = 0;
    _frame.v65 = 0;
    _frame.a2 = 0;
    v6 = 0;
    do
    {
      v7 = *(volatile uint32_t *)(v4 + 76);
      v8 = *(volatile uint32_t *)(v4 + 68);
      v9 = *(volatile uint8_t *)(v4 + 29);
      if ( *((volatile uint8_t *)off_118440 + 512) == 1 )
      {
        *((volatile uint8_t *)off_118440 + 512) = 0;
        v3 = (volatile uint32_t *)unknown_func_12d104(512);
        if ( !v8 )
        {
LABEL_39:
          if ( (__get_CPSR() & 1) == 0 )
          {
            __disable_irq();
            *(volatile uint32_t *)off_118444 = 1;
          }
          ++*v5;
          mem_word_load(v1);
          if ( *v5 )
          {
            v21 = *v5 - 1;
            v22 = *(volatile uint32_t *)off_118444;
            *v5 = v21;
            if ( !v21 )
            {
              if ( v22 )
                __enable_irq();
            }
          }
          v23 = *(volatile uint8_t *)(v4 + 28);
          v24 = *(volatile uint32_t *)(v7 + 4);
          _frame.v62 = v24;
          if ( *(volatile uint8_t *)(dword_11844C + 696 * v9 + 36) != 1 || (v24 & 0x810000) != 0x10000 )
            int_status_check(v4);
          v25 = dword_118458;
          v26 = dword_118458 + 1320 * v23;
          v27 = *(volatile uint8_t *)(v26 + 1224);
          if ( *(volatile uint8_t *)(v26 + 1224) )
            v8 = dword_118450 + 140 * *(volatile uint8_t *)(v26 + 1225);
          if ( *(volatile uint8_t *)(v4 + 29) > 0x1Fu
            || (v28 = *(volatile uint16_t *)(v4 + 30), (v28 & 8) != 0)
            || (_frame.v62 & 0x810000) != 0x10000
            || !*(volatile uint8_t *)(dword_118458 + 1320 * v23 + 108) )
          {
LABEL_53:
            if ( *(volatile int *)(*(volatile uint32_t *)(v4 + 44) + 60) >= 0 || (_frame.v62 & 0x800000) == 0 )
              goto LABEL_54;
            v41 = *(volatile uint32_t *)(v4 + 76);
            if ( **(volatile int16_t **)off_1186F4 >= 0 )
            {
              v42 = *(volatile uint32_t *)(v41 + 28);
              if ( !v42 )
                goto LABEL_94;
LABEL_96:
              if ( (*(volatile uint16_t *)v42 & 0x8000) != 0 && (*(volatile uint16_t *)v42 & 0xC) == 8 && (*(volatile uint32_t *)(v42 + 26) & 0x3F) == 7 )
                *(volatile uint32_t *)(*(volatile uint32_t *)(v4 + 44) + 60) &= ~0x80000000;
LABEL_54:
              if ( ll_conn_tx_pdu_check(v4, 0) )
              {
                v47 = *(volatile uint32_t *)(v4 + 76);
                v48 = *(volatile uint16_t *)(v4 + 30) | 1;
                *(volatile uint32_t *)(v4 + 68) = 0;
                *(volatile uint32_t *)(v47 + 72) = 0;
                *(volatile uint32_t *)(v47 + 4) = 0;
                *(volatile uint16_t *)(v4 + 30) = v48;
                *(volatile uint16_t *)(v4 + 82) = 0;
                v49 = (void *)(uintptr_t)(off_11870C);
                *(volatile uint32_t *)(v4 + 44) = 0;
                *(volatile uint32_t *)(v4 + 36) = 0;
                list_process(
                  v25 + 8 * (165 * (uint16_t)v23 + a1 + 159),
                  (volatile uint32_t *)v4,
                  (int ( *)(volatile uint32_t *, volatile uint32_t *))v49);
                v3 = (volatile uint32_t *)unknown_func_12d104(512);
              }
              else
              {
                if ( *(volatile uint16_t *)(v4 + 24) == 36488 && (*(volatile uint32_t *)(v7 + 4) & 0xF) == 9 )
                {
                  v44 = dword_1186F8 + 696 * v9;
                  v45 = *(volatile uint8_t *)(v44 + 669);
                  if ( v45 <= 1 )
                  {
                    v46 = *(volatile uint32_t *)(*(volatile uint32_t *)(v4 + 76) + 36);
                    if ( v46 != *(volatile uint16_t *)(v44 + 670) )
                    {
                      *(volatile uint8_t *)(v44 + 669) = v45 + 1;
                      *(volatile uint16_t *)(v44 + 670) = v46;
                    }
                  }
                }
                v29 = *(volatile uint8_t *)(v4 + 29);
                if ( v29 <= 0x1F )
                {
                  v30 = *(volatile uint8_t *)(v4 + 27);
                  if ( v30 <= 8 )
                    *(volatile uint32_t *)(dword_118448 + 4 * (9 * v29 + v30 + 2062)) -= *(volatile uint16_t *)(v4 + 4);
                }
                hw_type_get(v4);
                ll_state_check(v4, (volatile uint32_t *)(v7 + 4));
                if ( (*(volatile uint16_t *)(v4 + 30) & 1) != 0 )
                  unknown_func_12d104(512);
                v3 = (volatile uint32_t *)save_context_args((uint8_t)a1, v4);
              }
              goto LABEL_36;
            }
            if ( *(volatile uint32_t *)(v4 + 72) )
            {
              v42 = *(volatile uint32_t *)(v41 + 28);
              if ( v42 )
                goto LABEL_96;
              goto LABEL_125;
            }
            mmio_clear_register((int)aTxlBufferGetTx, (int)aTxlBufferMachd_0, 518);
            v42 = *(volatile uint32_t *)(v41 + 28);
            if ( v42 )
              goto LABEL_96;
            if ( **(volatile int16_t **)off_11893C < 0 )
            {
LABEL_125:
              v43 = *(volatile uint32_t *)(v41 + 24);
              if ( !v43 )
              {
                mmio_clear_register((int)aThdFirstPbdPtr, (int)aTxlBufferMachd_0, 525);
                goto LABEL_94;
              }
            }
            else
            {
LABEL_94:
              v43 = *(volatile uint32_t *)(v41 + 24);
            }
            v42 = *(volatile uint32_t *)(v43 + 8);
            goto LABEL_96;
          }
          if ( *(volatile uint8_t *)(dword_118928 + 696 * v9 + 36) != 1 )
          {
            if ( (v28 & 2) == 0 )
              goto LABEL_132;
            _frame.v64 = dword_118458 + 1320 * v23;
            if ( radio_timer_expired(*(volatile uint16_t *)(v4 + 64)) )
            {
              v27 = *(volatile uint8_t *)(_frame.v64 + 1224);
LABEL_132:
              if ( !v27 || *(volatile uint8_t *)(v8 + 112) != 1 || *(volatile uint8_t *)(v8 + 133) )
                goto LABEL_53;
            }
          }
          event_dispatch("st %x, %d, %x\r\n", _frame.v62, a1, v4);
          v54 = (*(volatile uint32_t *)0x40501010u);
          v55 = *(volatile uint16_t *)(v4 + 30);
          v56 = *(volatile uint32_t *)(v4 + 76);
          v57 = (void *)(uintptr_t)(off_11890C);
          *(volatile uint16_t *)(v4 + 64) = *((volatile uint16_t *)off_118934 + 22) + (v54 >> 10);
          *(volatile uint32_t *)(v4 + 68) = 0;
          *(volatile uint32_t *)(v56 + 72) = 0;
          *(volatile uint32_t *)(v56 + 4) = 0;
          *(volatile uint16_t *)(v4 + 82) = 0;
          *(volatile uint32_t *)(v4 + 44) = 0;
          *(volatile uint32_t *)(v4 + 36) = 0;
          *(volatile uint16_t *)(v4 + 30) = v55 | 1;
          list_process(
            v25 + 8 * (165 * (uint16_t)v23 + a1 + 159),
            (volatile uint32_t *)v4,
            (int ( *)(volatile uint32_t *, volatile uint32_t *))v57);
          v3 = (volatile uint32_t *)unknown_func_12d104(512);
          goto LABEL_36;
        }
      }
      else if ( !v8 )
      {
        goto LABEL_39;
      }
      if ( (*(volatile uint8_t *)(v8 + 8) & 0x10) == 0 )
        return v3;
      v10 = *(volatile uint32_t *)(v7 + 4) & 0xFF7FFFFF;
      v11 = *(volatile uint8_t *)(v8 + 8) & 0x40;
      ++_frame.a2;
      *(volatile uint32_t *)(v7 + 4) = v10;
      if ( v11 )
      {
        v37 = *(volatile uint16_t **)(v8 + 224);
        if ( !v37
          || (v38 = (*(volatile uint16_t *)(v4 + 32) - (*v37 >> 4)) & 0xFFF, v38 <= 0x7FE)
          && ((*v37 & 0xF) != 4 ? (v39 = 3) : (v39 = 15),
              v39 >= v38 >> 4 && (((int)(uint16_t)v37[(v38 >> 4) + 1] >> (v38 & 0xF)) & 1) != 0) )
        {
          ++_frame.a3;
          v40 = 8650752;
        }
        else
        {
          v40 = 0x40000;
        }
        v10 |= v40;
        *(volatile uint32_t *)(v7 + 4) = v10;
      }
      _frame.v61 = ll_conn_tx_pdu_check(v4, 0);
      if ( (*(volatile uint32_t *)(v4 + 36) & 0x380000) == 0x280000 )
        v6 = v4;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(volatile uint32_t *)off_118444 = 1;
      }
      ++*v5;
      v3 = mem_word_load(v1);
      if ( (*(volatile uint32_t *)(v4 + 36) & 0x380000) == 0x380000 )
      {
        if ( **(volatile int16_t **)off_1186F4 < 0 && !v6 )
          mmio_clear_register((int)aTxdescFirstNul, (int)aTxlCfmEvt_0, 706);
        if ( *(volatile uint8_t *)(dword_1186F8 + 696 * v9 + 36) != 1 || v11 )
          ipc_dispatch_one(v6, _frame.a2, _frame.a3, v8);
        _frame.a3 = 0;
        v3 = (volatile uint32_t *)dec_retry_count(v8);
        _frame.a2 = 0;
        v12 = 1;
      }
      else
      {
        v12 = 0;
      }
      if ( *v5 )
      {
        v13 = *v5 - 1;
        v14 = *(volatile uint32_t *)off_118444;
        *v5 = v13;
        if ( !v13 )
        {
          if ( v14 )
            __enable_irq();
        }
      }
      if ( *(volatile uint16_t *)(v4 + 24) == 36488 && (*(volatile uint32_t *)(v7 + 4) & 0xF) == 9 )
      {
        v34 = dword_1186F8 + 696 * v9;
        v35 = *(volatile uint8_t *)(v34 + 669);
        if ( v35 <= 1 )
        {
          v36 = *(volatile uint32_t *)(*(volatile uint32_t *)(v4 + 76) + 36);
          if ( v36 != *(volatile uint16_t *)(v34 + 670) )
          {
            *(volatile uint8_t *)(v34 + 669) = v35 + 1;
            *(volatile uint16_t *)(v34 + 670) = v36;
          }
        }
      }
      if ( *(volatile int *)(*(volatile uint32_t *)(v4 + 44) + 60) < 0 )
      {
        if ( (v10 & 0x800000) != 0 )
        {
          v31 = *(volatile uint32_t *)(v4 + 76);
          if ( **(volatile int16_t **)off_1186F4 >= 0 )
          {
            v32 = *(volatile uint32_t *)(v31 + 28);
            if ( !v32 )
              goto LABEL_65;
LABEL_67:
            if ( (*(volatile uint16_t *)v32 & 0x8000) != 0 && (*(volatile uint16_t *)v32 & 0xC) == 8 && (*(volatile uint32_t *)(v32 + 26) & 0x3F) == 7 )
              *(volatile uint32_t *)(*(volatile uint32_t *)(v4 + 44) + 60) &= ~0x80000000;
            v15 = (volatile uint8_t **)off_118718;
            if ( !**(volatile uint8_t **)off_118718 )
              goto LABEL_34;
            v16 = dword_11871C;
            _frame.v63 = *(volatile uint8_t *)(v4 + 28);
            _frame.v66 = dword_11871C + 1320 * _frame.v63;
            goto LABEL_24;
          }
          if ( *(volatile uint32_t *)(v4 + 72) )
          {
            v32 = *(volatile uint32_t *)(v31 + 28);
            if ( v32 )
              goto LABEL_67;
            goto LABEL_111;
          }
          v3 = (volatile uint32_t *)mmio_clear_register((int)aTxlBufferGetTx, (int)aTxlBufferMachd_0, 518);
          v32 = *(volatile uint32_t *)(v31 + 28);
          if ( v32 )
            goto LABEL_67;
          if ( **(volatile int16_t **)off_11893C < 0 )
          {
LABEL_111:
            v33 = *(volatile uint32_t *)(v31 + 24);
            if ( !v33 )
            {
              v3 = (volatile uint32_t *)mmio_clear_register((int)aThdFirstPbdPtr, (int)aTxlBufferMachd_0, 525);
              goto LABEL_65;
            }
          }
          else
          {
LABEL_65:
            v33 = *(volatile uint32_t *)(v31 + 24);
          }
          v32 = *(volatile uint32_t *)(v33 + 8);
          goto LABEL_67;
        }
        v15 = (volatile uint8_t **)off_118718;
        if ( !**(volatile uint8_t **)off_118718 )
          goto LABEL_34;
        v16 = dword_11871C;
        _frame.v63 = *(volatile uint8_t *)(v4 + 28);
        _frame.v66 = dword_11871C + 1320 * _frame.v63;
      }
      else
      {
        v15 = (volatile uint8_t **)off_118454;
        if ( !**(volatile uint8_t **)off_118454 )
          goto LABEL_34;
        v16 = dword_118458;
        _frame.v63 = *(volatile uint8_t *)(v4 + 28);
        _frame.v66 = dword_118458 + 1320 * _frame.v63;
        if ( (v10 & 0x800000) != 0 )
          goto LABEL_24;
      }
      if ( _frame.v61 && *(volatile uint8_t *)(v16 + 1320 * _frame.v63 + 108) )
      {
        v50 = *(volatile uint32_t *)(v4 + 76);
        v51 = *(volatile uint16_t *)(v4 + 30) | 1;
        *(volatile uint32_t *)(v4 + 68) = 0;
        *(volatile uint32_t *)(v50 + 72) = 0;
        *(volatile uint32_t *)(v50 + 4) = 0;
        *(volatile uint16_t *)(v4 + 30) = v51;
        v52 = (void *)(uintptr_t)(off_11890C);
        *(volatile uint16_t *)(v4 + 82) = 0;
        *(volatile uint32_t *)(v4 + 44) = 0;
        *(volatile uint32_t *)(v4 + 36) = 0;
        v3 = (volatile uint32_t *)list_process(
                         v16 + 8 * (a1 + 159 + 165 * _frame.v63),
                         (volatile uint32_t *)v4,
                         (int ( *)(volatile uint32_t *, volatile uint32_t *))v52);
        if ( v12 )
          goto LABEL_117;
        _frame.v65 = 1;
        goto LABEL_36;
      }
LABEL_24:
      v17 = *(volatile uint8_t *)(v4 + 29);
      if ( v17 <= 0x1F )
      {
        v18 = *(volatile uint8_t *)(v4 + 27);
        if ( v18 <= 8 )
          *(volatile uint32_t *)(dword_118448 + 4 * (9 * v17 + v18 + 2062)) -= *(volatile uint16_t *)(v4 + 4);
      }
      ll_state_check(v4, (volatile uint32_t *)(v7 + 4));
      if ( (*(volatile uint16_t *)(v4 + 30) & 1) != 0 )
      {
        unknown_func_12d104(512);
        v19 = *(volatile uint32_t **)(v4 + 72);
        if ( !v19 )
        {
LABEL_101:
          event_dispatch("buffer is null in %s\n", aTxlCfmEvt);
          goto LABEL_31;
        }
      }
      else
      {
        v19 = *(volatile uint32_t **)(v4 + 72);
        if ( !v19 )
          goto LABEL_101;
      }
      is_controller_mode(v19);
      v20 = *v15;
      *(volatile uint32_t *)(v4 + 72) = 0;
      if ( *v20 == 1 )
        invoke_callback_1();
LABEL_31:
      v3 = (volatile uint32_t *)save_context_args((uint8_t)a1, v4);
      if ( v12 )
      {
        if ( _frame.v65 )
        {
LABEL_117:
          if ( isr_flag_dispatch(_frame.v66) && !*((volatile uint8_t *)off_118910 + 511) )
          {
            do
            {
              v53 = *(volatile uint32_t *)(v16 + 8 * (165 * _frame.v63 + a1 + 159));
              if ( !v53 )
                break;
              mem_word_load(v16 + 8 * (a1 + 159 + 165 * _frame.v63));
              ll_conn_state_dispatch(v53, (uint8_t)a1);
            }
            while ( !*((volatile uint8_t *)off_118910 + 511) );
          }
        }
        v3 = (volatile uint32_t *)unknown_func_12d104(512);
        _frame.v65 = 0;
LABEL_34:
        if ( v12 )
          v6 = 0;
      }
LABEL_36:
      v4 = *(volatile uint32_t *)(dword_118434 + 8 * a1);
    }
    while ( v4 );
  }
  return v3;
}


// rf_tx_setup @ 0x118940
/* luna: Processes queued BLE link-layer transmit items, prepares their hardware control word, and dispatches eligible connection PDUs. */
volatile uint32_t * rf_tx_setup(unsigned int a1, int a2, int a3) {
  volatile int16_t **v3; // r8
  volatile uint32_t *v7; // r4
  int v8; // r1

  v3 = (volatile int16_t **)off_1189EC;
  while ( 1 )
  {
    v7 = mem_word_load(a2);
    if ( !v7 )
      break;
    while ( 1 )
    {
      v8 = v7[19];
      if ( v7[17] )
      {
        *(volatile uint32_t *)(v8 + 4) = 2080374784;
      }
      else if ( *(volatile int *)(v8 + 4) >= 0 )
      {
        *(volatile uint32_t *)(v8 + 4) = 0x40000000;
      }
      if ( *((volatile uint16_t *)v7 + 2) )
        break;
      free_buf_1882c0(v7);
      v7 = mem_word_load(a2);
      if ( !v7 )
        return tx_pool_init();
    }
    *(volatile uint32_t *)(v8 + 4) |= 0x800000u;
    ll_state_check((int)v7, (volatile uint32_t *)(v8 + 4));
    call_delayed_callback((int)v7);
    if ( ll_conn_tx_pdu_check((int)v7, 1) )
    {
      if ( **v3 < 0 && !a3 )
        mmio_clear_register((int)aRepushList, (int)aTxlCfmFlush, 1105);
      cmd_handler_a(a3, v7);
    }
    else
    {
      save_context_args(a1, (int)v7);
    }
  }
  return tx_pool_init();
}


// rf_pll_lock @ 0x1189f8
/* luna: Processes queued transmit buffers and descriptor state, releases buffers with no outstanding references, and invokes transmit-pool initialization when */
int rf_pll_lock(int a1, int a2) {
  volatile int16_t **v2; // r5
  int v3; // r7
  int v4; // r6
  int v6; // r0
  int v7; // r1
  int v8; // r3
  int v9; // r2
  int v10; // r0

  v2 = (volatile int16_t **)off_118A60;
  v3 = dword_118A64;
  v4 = dword_118A68;
LABEL_2:
  v6 = (int)(uintptr_t)(mem_word_load(a2));
  v7 = 2080374784;
  v8 = v6;
  if ( v6 )
  {
    while ( 1 )
    {
      v9 = *(volatile uint32_t *)(v8 + 76);
      if ( *(volatile uint32_t *)(v8 + 68) )
        goto LABEL_4;
      if ( *(volatile int *)(v9 + 4) >= 0 )
        break;
LABEL_5:
      if ( !*(volatile uint16_t *)(v8 + 4) )
      {
        free_buf_1882c0((void *)(uintptr_t)(v8));
        goto LABEL_2;
      }
      if ( **v2 >= 0 )
        goto LABEL_2;
      mmio_clear_register(v4, v3, 1147);
      v10 = (int)(uintptr_t)(mem_word_load(a2));
      v7 = 2080374784;
      v8 = v10;
      if ( !v10 )
        return (int)(uintptr_t)(tx_pool_init());
    }
    v7 = 0x40000000;
LABEL_4:
    *(volatile uint32_t *)(v9 + 4) = v7;
    goto LABEL_5;
  }
  return (int)(uintptr_t)(tx_pool_init());
}



// ll_event_init @ 0x118a6c
/* luna: Initializes an event-control block, links it to the supplied context and auxiliary descriptor, clears selected descriptor fields, and returns the cont */
int ll_event_init(int a1, int a2, volatile uint32_t *a3, volatile int *a4) {
  int v8; // r1
  int v9; // r2

  memset((volatile int *)a1, 0, 0x64u);
  *(volatile uint8_t *)(a1 + 96) = 1;
  v8 = dword_118AA8;
  v9 = dword_118AAC;
  *(volatile uint32_t *)(a1 + 72) = a2;
  *(volatile uint32_t *)(a1 + 44) = (int)(uintptr_t)(a4);
  *(volatile uint32_t *)(a1 + 76) = (int)(uintptr_t)(a3);
  a3[13] = 0;
  a3[14] = 0;
  a3[7] = a2 + 108;
  a3[3] = v8;
  a3[10] = 0;
  a3[15] = 0;
  *a4 = v9;
  return a2 + 108;
}



// fw_magic_check @ 0x118ab0
/* luna: Initializes a set of four RF contexts and configures two associated timing structures, optionally skipping contexts already marked active. */
int fw_magic_check(int a1) {
  int v2; // r4
  volatile uint32_t *v3; // r6
  volatile uint32_t *v4; // r5
  int v5; // r11
  int v6; // r10
  int v7; // r9
  int v8; // r8
  volatile uint32_t *v9; // r6
  int v10; // r8
  int v11; // r0
  volatile int *v12; // r5
  int v13; // r7
  int result; // r0

  v2 = dword_118B98;
  v3 = (volatile uint32_t *)dword_118B9C;
  v4 = (volatile uint32_t *)dword_118BA0;
  v5 = dword_118BB0;
  v6 = dword_118BB4;
  v7 = dword_118B94;
  zero_8_bytes((volatile uint32_t *)dword_118B94);
  zero_8_bytes((volatile uint32_t *)(v7 + 8));
  v8 = v2 + 400;
  do
  {
    if ( !a1 || !*(volatile uint8_t *)(v2 + 97) )
    {
      memset((volatile int *)v2, 0, 0x64u);
      *(volatile uint32_t *)(v2 + 44) = (int)(uintptr_t)(v3 + 11);
      *(volatile uint32_t *)(v2 + 72) = (int)(uintptr_t)(v3);
      *(volatile uint32_t *)(v2 + 76) = (int)(uintptr_t)(v4);
      v4[13] = 0;
      v4[14] = 0;
      v3[24] = 0;
      v3[25] = 0;
      v4[3] = v5;
      v3[11] = v6;
      *(volatile uint8_t *)(v2 + 96) = 0;
      v4[10] = 0;
      v4[15] = 0;
      v4[7] = (int)(uintptr_t)(v3 + 27);
      cmd_handler_a(v7, (volatile uint32_t *)v2);
    }
    v2 += 100;
    v3 += 155;
    v4 += 20;
  }
  while ( v2 != v8 );
  v9 = (void *)(uintptr_t)(off_118BA4);
  v10 = dword_118BB4;
  *(volatile uint32_t *)off_118BA4 = dword_118BB4;
  v9[13] = 0;
  v9[14] = 0;
  v9[15] = 0;
  v9[1] = rf_get_field4() << 14;
  v11 = get_hw_clock_multiplier();
  v12 = (volatile int *)off_118BA8;
  v13 = dword_118BAC;
  v9[2] = v11;
  v9[4] = v13;
  v9[5] = 1024;
  v9[6] = 0;
  v9[7] = 0;
  v9[3] = 0;
  v9[8] = 0;
  *v12 = v10;
  v9[10] = 0;
  v9[11] = 0;
  v12[13] = 0;
  v12[14] = 0;
  v9[12] = 0;
  v12[15] = 0;
  v12[1] = rf_get_field4() << 14;
  result = get_hw_clock_multiplier();
  v12[2] = result;
  v12[3] = 0;
  v12[6] = 0;
  v12[7] = 0;
  v12[10] = 0;
  v12[11] = 0;
  v12[4] = v13;
  v12[8] = 0;
  v12[12] = 0;
  v12[5] = 4;
  return result;
}


