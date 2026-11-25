// is_initialized @ 0x117e0c
int is_initialized(int a1, int a2, int a3, int a4) {
  int v4; // r2
  volatile uint32_t *v6; // r0
  volatile int16_t *v7; // r1
  int v8; // r4
  unsigned int v9; // r2
  int result; // r0
  int v11; // r1
  unsigned int v12; // r3
  int v13; // r2

  if ( *(volatile uint8_t *)off_117EF8 )
    return alloc_tx_event(aBaWarn, a2, a3, a4);
  v4 = (v4 & ~0xFFFFu) | ((uint16_t)(*((volatile uint8_t *)off_117EFC + 190)) & 0xFFFFu);
  if ( (*((volatile uint32_t *)off_117EFC + 52) & 1) == 0 )
    v4 = (*(volatile uint32_t *)(a1 + 84) >> 11) & 3;
  v6 = list_pop(dword_117F00 + 84 * (uint16_t)v4 + 28);
  v7 = *(volatile int16_t **)off_117F04;
  v8 = (int)v6;
  if ( **(volatile int16_t **)off_117F04 < 0 && !v6 )
    return unknown_12f2c8((int)aAggDescNull, (int)aTxlBaPush, 369);
  v9 = *(volatile uint32_t *)(a1 + 84);
  result = v9 << 6;
  *(volatile uint16_t *)(v8 + 8) |= 0x20u;
  if ( (v9 & 0x2000000) != 0 )
  {
    result = (uint16_t)(v9 >> 15);
    if ( *v7 < 0 && (result & 0x3F0) == 0 )
      return unknown_12f2c8((int)aKeyIdxHwMmSecD, (int)aTxlIsBaValid, 217);
    if ( ((v9 >> 15) & 0x3FF) - 16 == *(volatile uint8_t *)(v8 + 12) )
    {
      v11 = *(volatile uint32_t *)(*(volatile uint32_t *)(a1 + 28) + 8);
      v12 = *(volatile uint16_t *)(v11 + 16);
      result = v12 & 0x1E;
      if ( result == 22 )
      {
        result = tx_frame_build(a1, v8);
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


// invoke_handler @ 0x117f1c
volatile uint32_t *invoke_handler() {
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

  result = (volatile uint32_t *)(*(int ( **)(uint32_t))(*((volatile uint32_t *)off_117FD0 + 2) + 16))(*((volatile uint32_t *)off_117FD0 + 1));
  if ( result )
  {
    v1 = result;
    v2 = (void *)(uintptr_t)(mmio_read_0());
    v3 = v2;
    if ( v2 )
    {
      v4 = (void *)(uintptr_t)(off_117FD4);
      *v2 = 0;
      v5 = *v4;
      v3[1] = 0;
      v3[2] = 0;
      *v3 = (int)(uintptr_t)((volatile char *)v1 + v5);
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(volatile uint32_t *)off_117FD8 = 1;
      }
      v6 = (volatile int *)off_117FDC;
      v7 = (void *)(uintptr_t)(off_117FE0);
      v8 = *(volatile uint32_t *)off_117FDC + 1;
      *(volatile uint32_t *)off_117FDC = v8;
      *v7 = 1;
      while ( (*v7 & 2) != 0 )
        ;
      if ( *(volatile uint32_t *)off_117FE4 )
      {
        v9 = (void *)(uintptr_t)(off_117FEC);
        v15 = *((volatile uint32_t *)off_117FEC + 1);
        if ( v15 )
        {
          *(volatile uint32_t *)(v15 + 4) = (int)(uintptr_t)(v3);
        }
        else
        {
          alloc_tx_event(aSdioTailError);
          v8 = *v6;
        }
      }
      else
      {
        if ( *(volatile uint32_t *)off_117FE8 )
        {
          alloc_tx_event(aBug);
          v8 = *v6;
        }
        v9 = (void *)(uintptr_t)(off_117FEC);
        *(volatile uint32_t *)off_117FE8 = (int)(uintptr_t)(v3);
      }
      result = (void *)(uintptr_t)(off_117FE4);
      v10 = v9[6];
      v11 = *(volatile uint32_t *)off_117FE4;
      *((volatile uint32_t *)v9 + 1) = (int)(uintptr_t)(v3);
      v12 = (void *)(uintptr_t)(off_117FF0);
      v9[6] = v10 + 1;
      *result = v11 + 1;
      *v12 = 1;
      if ( v8 )
      {
        v13 = v8 - 1;
        v14 = *(volatile uint32_t *)off_117FD8;
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
      return (volatile uint32_t *)wait_for_state(v1);
    }
  }
  return result;
}


// phy_calibrate_1 @ 0x117ffc
volatile uint32_t * phy_calibrate_1(int a1) {
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
  v1 = dword_1182F4 + 8 * a1;
  v2 = ((volatile uint32_t *)(uintptr_t)off_1182F8)[a1];
  if ( **(volatile int16_t **)off_1182F0 < 0 && (v2 & *(volatile uint32_t *)off_1187DC) == 0 )
    irq_disable_mmio_write((int)aKeEvtGetEvtBit, (int)aTxlCfmEvt_0, 612);
  irq_disable_global_3(v2);
  v3 = clear_stats_buf(_frame.result);
  v4 = *(volatile uint32_t *)(dword_1182F4 + 8 * a1);
  if ( v4 )
  {
    v5 = (volatile int *)off_1182FC;
    _frame.a3 = 0;
    _frame.v65 = 0;
    _frame.a2 = 0;
    v6 = 0;
    do
    {
      v7 = *(volatile uint32_t *)(v4 + 76);
      v8 = *(volatile uint32_t *)(v4 + 68);
      v9 = *(volatile uint8_t *)(v4 + 29);
      if ( *((volatile uint8_t *)off_118300 + 512) == 1 )
      {
        *((volatile uint8_t *)off_118300 + 512) = 0;
        v3 = (volatile uint32_t *)irq_disable_global_2(512);
        if ( !v8 )
        {
LABEL_39:
          if ( (__get_CPSR() & 1) == 0 )
          {
            __disable_irq();
            *(volatile uint32_t *)off_118304 = 1;
          }
          ++*v5;
          list_pop(v1);
          if ( *v5 )
          {
            v21 = *v5 - 1;
            v22 = *(volatile uint32_t *)off_118304;
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
          if ( *(volatile uint8_t *)(dword_11830C + 696 * v9 + 36) != 1 || (v24 & 0x810000) != 0x10000 )
            rf_check_irq(v4);
          v25 = dword_118318;
          v26 = dword_118318 + 1320 * v23;
          v27 = *(volatile uint8_t *)(v26 + 1224);
          if ( *(volatile uint8_t *)(v26 + 1224) )
            v8 = dword_118310 + 140 * *(volatile uint8_t *)(v26 + 1225);
          if ( *(volatile uint8_t *)(v4 + 29) > 0x1Fu
            || (v28 = *(volatile uint16_t *)(v4 + 30), (v28 & 8) != 0)
            || (_frame.v62 & 0x810000) != 0x10000
            || !*(volatile uint8_t *)(dword_118318 + 1320 * v23 + 108) )
          {
LABEL_53:
            if ( *(volatile int *)(*(volatile uint32_t *)(v4 + 44) + 60) >= 0 || (_frame.v62 & 0x800000) == 0 )
              goto LABEL_54;
            v41 = *(volatile uint32_t *)(v4 + 76);
            if ( **(volatile int16_t **)off_1185B4 >= 0 )
            {
              v42 = *(volatile uint32_t *)(v41 + 28);
              if ( !v42 )
                goto LABEL_94;
LABEL_96:
              if ( (*(volatile uint16_t *)v42 & 0x8000) != 0 && (*(volatile uint16_t *)v42 & 0xC) == 8 && (*(volatile uint32_t *)(v42 + 26) & 0x3F) == 7 )
                *(volatile uint32_t *)(*(volatile uint32_t *)(v4 + 44) + 60) &= ~0x80000000;
LABEL_54:
              if ( phy_switch_radio(v4, 0) )
              {
                v47 = *(volatile uint32_t *)(v4 + 76);
                v48 = *(volatile uint16_t *)(v4 + 30) | 1;
                *(volatile uint32_t *)(v4 + 68) = 0;
                *(volatile uint32_t *)(v47 + 72) = 0;
                *(volatile uint32_t *)(v47 + 4) = 0;
                *(volatile uint16_t *)(v4 + 30) = v48;
                *(volatile uint16_t *)(v4 + 82) = 0;
                v49 = (void *)(uintptr_t)(off_1185CC);
                *(volatile uint32_t *)(v4 + 44) = 0;
                *(volatile uint32_t *)(v4 + 36) = 0;
                list_foreach(
                  v25 + 8 * (165 * (uint16_t)v23 + a1 + 159),
                  (volatile uint32_t *)v4,
                  (int ( *)(volatile uint32_t *, volatile uint32_t *))v49);
                v3 = (volatile uint32_t *)irq_disable_global_2(512);
              }
              else
              {
                if ( *(volatile uint16_t *)(v4 + 24) == 36488 && (*(volatile uint32_t *)(v7 + 4) & 0xF) == 9 )
                {
                  v44 = dword_1185B8 + 696 * v9;
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
                    *(volatile uint32_t *)(dword_118308 + 4 * (9 * v29 + v30 + 2062)) -= *(volatile uint16_t *)(v4 + 4);
                }
                rx_packet_ready(v4);
                check_cal_status(v4, (volatile uint32_t *)(v7 + 4));
                if ( (*(volatile uint16_t *)(v4 + 30) & 1) != 0 )
                  irq_disable_global_2(512);
                v3 = (volatile uint32_t *)unknown_12f4b4((uint8_t)a1, v4);
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
            irq_disable_mmio_write((int)aTxlBufferGetTx, (int)aTxlBufferMachd_0, 518);
            v42 = *(volatile uint32_t *)(v41 + 28);
            if ( v42 )
              goto LABEL_96;
            if ( **(volatile int16_t **)off_1187FC < 0 )
            {
LABEL_125:
              v43 = *(volatile uint32_t *)(v41 + 24);
              if ( !v43 )
              {
                irq_disable_mmio_write((int)aThdFirstPbdPtr, (int)aTxlBufferMachd_0, 525);
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
          if ( *(volatile uint8_t *)(dword_1187E8 + 696 * v9 + 36) != 1 )
          {
            if ( (v28 & 2) == 0 )
              goto LABEL_132;
            _frame.v64 = dword_118318 + 1320 * v23;
            if ( timer_expired(*(volatile uint16_t *)(v4 + 64)) )
            {
              v27 = *(volatile uint8_t *)(_frame.v64 + 1224);
LABEL_132:
              if ( !v27 || *(volatile uint8_t *)(v8 + 112) != 1 || *(volatile uint8_t *)(v8 + 133) )
                goto LABEL_53;
            }
          }
          alloc_tx_event("st %x, %d, %x\r\n", _frame.v62, a1, v4);
          v54 = (*(volatile uint32_t *)0x40501010u);
          v55 = *(volatile uint16_t *)(v4 + 30);
          v56 = *(volatile uint32_t *)(v4 + 76);
          v57 = (void *)(uintptr_t)(off_1187CC);
          *(volatile uint16_t *)(v4 + 64) = *((volatile uint16_t *)off_1187F4 + 22) + (v54 >> 10);
          *(volatile uint32_t *)(v4 + 68) = 0;
          *(volatile uint32_t *)(v56 + 72) = 0;
          *(volatile uint32_t *)(v56 + 4) = 0;
          *(volatile uint16_t *)(v4 + 82) = 0;
          *(volatile uint32_t *)(v4 + 44) = 0;
          *(volatile uint32_t *)(v4 + 36) = 0;
          *(volatile uint16_t *)(v4 + 30) = v55 | 1;
          list_foreach(
            v25 + 8 * (165 * (uint16_t)v23 + a1 + 159),
            (volatile uint32_t *)v4,
            (int ( *)(volatile uint32_t *, volatile uint32_t *))v57);
          v3 = (volatile uint32_t *)irq_disable_global_2(512);
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
      _frame.v61 = phy_switch_radio(v4, 0);
      if ( (*(volatile uint32_t *)(v4 + 36) & 0x380000) == 0x280000 )
        v6 = v4;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(volatile uint32_t *)off_118304 = 1;
      }
      ++*v5;
      v3 = list_pop(v1);
      if ( (*(volatile uint32_t *)(v4 + 36) & 0x380000) == 0x380000 )
      {
        if ( **(volatile int16_t **)off_1185B4 < 0 && !v6 )
          irq_disable_mmio_write((int)aTxdescFirstNul, (int)aTxlCfmEvt_0, 706);
        if ( *(volatile uint8_t *)(dword_1185B8 + 696 * v9 + 36) != 1 || v11 )
          mac_call_command(v6, _frame.a2, _frame.a3, v8);
        _frame.a3 = 0;
        v3 = (volatile uint32_t *)decrement_refcount(v8);
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
        v14 = *(volatile uint32_t *)off_118304;
        *v5 = v13;
        if ( !v13 )
        {
          if ( v14 )
            __enable_irq();
        }
      }
      if ( *(volatile uint16_t *)(v4 + 24) == 36488 && (*(volatile uint32_t *)(v7 + 4) & 0xF) == 9 )
      {
        v34 = dword_1185B8 + 696 * v9;
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
          if ( **(volatile int16_t **)off_1185B4 >= 0 )
          {
            v32 = *(volatile uint32_t *)(v31 + 28);
            if ( !v32 )
              goto LABEL_65;
LABEL_67:
            if ( (*(volatile uint16_t *)v32 & 0x8000) != 0 && (*(volatile uint16_t *)v32 & 0xC) == 8 && (*(volatile uint32_t *)(v32 + 26) & 0x3F) == 7 )
              *(volatile uint32_t *)(*(volatile uint32_t *)(v4 + 44) + 60) &= ~0x80000000;
            v15 = (volatile uint8_t **)off_1185D8;
            if ( !**(volatile uint8_t **)off_1185D8 )
              goto LABEL_34;
            v16 = dword_1185DC;
            _frame.v63 = *(volatile uint8_t *)(v4 + 28);
            _frame.v66 = dword_1185DC + 1320 * _frame.v63;
            goto LABEL_24;
          }
          if ( *(volatile uint32_t *)(v4 + 72) )
          {
            v32 = *(volatile uint32_t *)(v31 + 28);
            if ( v32 )
              goto LABEL_67;
            goto LABEL_111;
          }
          v3 = (volatile uint32_t *)irq_disable_mmio_write((int)aTxlBufferGetTx, (int)aTxlBufferMachd_0, 518);
          v32 = *(volatile uint32_t *)(v31 + 28);
          if ( v32 )
            goto LABEL_67;
          if ( **(volatile int16_t **)off_1187FC < 0 )
          {
LABEL_111:
            v33 = *(volatile uint32_t *)(v31 + 24);
            if ( !v33 )
            {
              v3 = (volatile uint32_t *)irq_disable_mmio_write((int)aThdFirstPbdPtr, (int)aTxlBufferMachd_0, 525);
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
        v15 = (volatile uint8_t **)off_1185D8;
        if ( !**(volatile uint8_t **)off_1185D8 )
          goto LABEL_34;
        v16 = dword_1185DC;
        _frame.v63 = *(volatile uint8_t *)(v4 + 28);
        _frame.v66 = dword_1185DC + 1320 * _frame.v63;
      }
      else
      {
        v15 = (volatile uint8_t **)off_118314;
        if ( !**(volatile uint8_t **)off_118314 )
          goto LABEL_34;
        v16 = dword_118318;
        _frame.v63 = *(volatile uint8_t *)(v4 + 28);
        _frame.v66 = dword_118318 + 1320 * _frame.v63;
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
        v52 = (void *)(uintptr_t)(off_1187CC);
        *(volatile uint16_t *)(v4 + 82) = 0;
        *(volatile uint32_t *)(v4 + 44) = 0;
        *(volatile uint32_t *)(v4 + 36) = 0;
        v3 = (volatile uint32_t *)list_foreach(
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
          *(volatile uint32_t *)(dword_118308 + 4 * (9 * v17 + v18 + 2062)) -= *(volatile uint16_t *)(v4 + 4);
      }
      check_cal_status(v4, (volatile uint32_t *)(v7 + 4));
      if ( (*(volatile uint16_t *)(v4 + 30) & 1) != 0 )
      {
        irq_disable_global_2(512);
        v19 = *(volatile uint32_t **)(v4 + 72);
        if ( !v19 )
        {
LABEL_101:
          alloc_tx_event("buffer is null in %s\n", aTxlCfmEvt);
          goto LABEL_31;
        }
      }
      else
      {
        v19 = *(volatile uint32_t **)(v4 + 72);
        if ( !v19 )
          goto LABEL_101;
      }
      wait_for_state(v19);
      v20 = *v15;
      *(volatile uint32_t *)(v4 + 72) = 0;
      if ( *v20 == 1 )
        invoke_handler();
LABEL_31:
      v3 = (volatile uint32_t *)unknown_12f4b4((uint8_t)a1, v4);
      if ( v12 )
      {
        if ( _frame.v65 )
        {
LABEL_117:
          if ( phy_lock(_frame.v66) && !*((volatile uint8_t *)off_1187D0 + 511) )
          {
            do
            {
              v53 = *(volatile uint32_t *)(v16 + 8 * (165 * _frame.v63 + a1 + 159));
              if ( !v53 )
                break;
              list_pop(v16 + 8 * (a1 + 159 + 165 * _frame.v63));
              phy_txpower_calc(v53, (uint8_t)a1);
            }
            while ( !*((volatile uint8_t *)off_1187D0 + 511) );
          }
        }
        v3 = (volatile uint32_t *)irq_disable_global_2(512);
        _frame.v65 = 0;
LABEL_34:
        if ( v12 )
          v6 = 0;
      }
LABEL_36:
      v4 = *(volatile uint32_t *)(dword_1182F4 + 8 * a1);
    }
    while ( v4 );
  }
  return v3;
}


// phy_dispatch @ 0x118800
volatile uint32_t * phy_dispatch(unsigned int a1, int a2, int a3) {
  volatile int16_t **v3; // r8
  volatile uint32_t *v7; // r4
  int v8; // r1

  v3 = (volatile int16_t **)off_1188AC;
  while ( 1 )
  {
    v7 = list_pop(a2);
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
      set_string_0x1882c0(v7);
      v7 = list_pop(a2);
      if ( !v7 )
        return alloc_dma_buf();
    }
    *(volatile uint32_t *)(v8 + 4) |= 0x800000u;
    check_cal_status((int)v7, (volatile uint32_t *)(v8 + 4));
    conn_handle_get((int)v7);
    if ( phy_switch_radio((int)v7, 1) )
    {
      if ( **v3 < 0 && !a3 )
        irq_disable_mmio_write((int)aRepushList, (int)aTxlCfmFlush, 1105);
      wlan_ioctl_handler_1(a3, v7);
    }
    else
    {
      unknown_12f4b4(a1, (int)v7);
    }
  }
  return alloc_dma_buf();
}


// mmio_write @ 0x1188b8
int mmio_write(int a1, int a2) {
  volatile int16_t **v2; // r5
  int v3; // r7
  int v4; // r6
  int v6; // r0
  int v7; // r1
  int v8; // r3
  int v9; // r2
  int v10; // r0

  v2 = (volatile int16_t **)off_118920;
  v3 = dword_118924;
  v4 = dword_118928;
LABEL_2:
  v6 = (int)(uintptr_t)(list_pop(a2));
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
        set_string_0x1882c0((void *)(uintptr_t)(v8));
        goto LABEL_2;
      }
      if ( **v2 >= 0 )
        goto LABEL_2;
      irq_disable_mmio_write(v4, v3, 1147);
      v10 = (int)(uintptr_t)(list_pop(a2));
      v7 = 2080374784;
      v8 = v10;
      if ( !v10 )
        return (int)(uintptr_t)(alloc_dma_buf());
    }
    v7 = 0x40000000;
LABEL_4:
    *(volatile uint32_t *)(v9 + 4) = v7;
    goto LABEL_5;
  }
  return (int)(uintptr_t)(alloc_dma_buf());
}



// zero_struct @ 0x11892c
int zero_struct(int a1, int a2, volatile uint32_t *a3, volatile int *a4) {
  int v8; // r1
  int v9; // r2

  memset((volatile int *)a1, 0, 0x64u);
  *(volatile uint8_t *)(a1 + 96) = 1;
  v8 = dword_118968;
  v9 = dword_11896C;
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



// verify_header_magic @ 0x118970
int verify_header_magic(int a1) {
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

  v2 = dword_118A58;
  v3 = (volatile uint32_t *)dword_118A5C;
  v4 = (volatile uint32_t *)dword_118A60;
  v5 = dword_118A70;
  v6 = dword_118A74;
  v7 = dword_118A54;
  clear_stats_buf((volatile uint32_t *)dword_118A54);
  clear_stats_buf((volatile uint32_t *)(v7 + 8));
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
      wlan_ioctl_handler_1(v7, (volatile uint32_t *)v2);
    }
    v2 += 100;
    v3 += 155;
    v4 += 20;
  }
  while ( v2 != v8 );
  v9 = (void *)(uintptr_t)(off_118A64);
  v10 = dword_118A74;
  *(volatile uint32_t *)off_118A64 = dword_118A74;
  v9[13] = 0;
  v9[14] = 0;
  v9[15] = 0;
  v9[1] = get_rf_field_mid() << 14;
  v11 = get_clock_prescaler();
  v12 = (volatile int *)off_118A68;
  v13 = dword_118A6C;
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
  v12[1] = get_rf_field_mid() << 14;
  result = get_clock_prescaler();
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


