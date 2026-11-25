// rf_get_chan_cfg @ 0x13a528
int rf_get_chan_cfg(int a1, volatile uint32_t *a2) {
  int v3; // r7
  int v4; // r0
  int v5; // r3
  uint64_t v6; // kr00_8
  int v7; // r2
  int v8; // r6
  int v9; // lr
  int v10; // r5
  int v11; // r2
  int v12; // r0

  v3 = dword_13A640;
  v4 = *(volatile uint8_t *)(a1 + 29);
  v5 = dword_13A640 + 696 * v4;
  v6 = *(volatile uint64_t *)(v5 + 184);
  v7 = dword_13A644 + 1320 * *(volatile uint8_t *)(a1 + 28);
  v8 = *(volatile uint32_t *)HIDWORD(v6);
  v9 = *(volatile uint32_t *)(v7 + 1200);
  v10 = 0;
  *a2 = 0;
  if ( !v8 || !v9 )
    return 0;
  if ( (*(volatile uint32_t *)(v7 + 1208) & 2) != 0
    && *(volatile uint16_t *)(v5 + 56) == (uint16_t)__rev16(*(volatile uint16_t *)(a1 + 24)) )
  {
    return v10;
  }
  if ( !(uint32_t)v6
    || (unsigned int)*(volatile uint8_t *)(v6 + 96) - 1 > 1
    || *(volatile uint8_t *)(v3 + 696 * v4 + 669) > 1u )
  {
    switch ( *(volatile uint8_t *)(v8 + 96) )
    {
      case 0:
      case 3:
        v10 = 4;
        *a2 = 4;
        v11 = 2;
        v12 = 1;
        break;
      case 1:
        *a2 = 12;
        v10 = 8;
        v11 = 3;
        v12 = 1;
        break;
      case 2:
        v10 = 8;
        *a2 = 8;
        v11 = 3;
        v12 = 1;
        break;
      case 4:
        *a2 = 16;
        if ( *(volatile uint8_t *)(v8 + 98) >= 0x10u )
          v12 = 2;
        else
          v12 = 1;
        v10 = 18;
        v11 = 4;
        break;
      case 6:
      case 7:
      case 8:
        *a2 = 16;
        v10 = 8;
        v11 = 3;
        v12 = 1;
        break;
      default:
        if ( **(volatile int16_t **)off_13A648 < 0 )
          mmio_clear_register(dword_13A64C, dword_13A650, 181);
        v10 = 0;
        v11 = 3;
        v12 = 1;
        break;
    }
    if ( (*(volatile uint16_t *)(a1 + 30) & 1) == 0 )
    {
      *(volatile uint64_t *)(v8 + 72) += v12;
      memcpy((void *)(uintptr_t)(a1 + 56), (void *)(uintptr_t)(v8 + 72), 2 * v11);
    }
    return v10;
  }
  return 0;
}



// rf_reset_chan_cfg @ 0x13a654
int rf_reset_chan_cfg(int a1) {
  int16_t v1; // r2
  int result; // r0
  int v4; // r1
  int v5; // r5
  int v6; // r3
  char v7; // r5
  int16_t v8; // r7
  int v9; // r1
  unsigned int v10; // r3
  char v11; // r5
  char v12; // r1
  int v13; // [sp+4h] [bp-8h] BYREF

  v1 = *(volatile uint16_t *)(a1 + 30);
  result = *(volatile uint8_t *)(a1 + 29);
  v4 = *(volatile uint8_t *)(a1 + 28);
  *(volatile uint32_t *)(a1 + 36) = 0;
  *(volatile uint32_t *)(a1 + 40) = 0;
  if ( (v1 & 1) == 0 )
  {
    v5 = *(volatile uint8_t *)(a1 + 27);
    if ( v5 == 255 )
    {
      v7 = 24;
    }
    else
    {
      v6 = dword_13A6FC + 2 * (v5 + 348 * result + 156);
      v7 = 26;
      v8 = *(volatile uint16_t *)(v6 + 4);
      *(volatile uint16_t *)(v6 + 4) = (v8 + 1) & 0xFFF;
      *(volatile uint16_t *)(a1 + 32) = v8;
    }
    v9 = dword_13A700 + 1320 * v4;
    if ( (v1 & 0x100) != 0 )
      v7 += 6;
    if ( !*(volatile uint8_t *)(v9 + 106) && (*(volatile uint32_t *)(dword_13A6FC + 696 * result + 4) & 0x20) != 0 )
      v7 += 4;
    *(volatile uint8_t *)(a1 + 50) = v7;
    result = rf_get_chan_cfg(a1, (void *)(&v13));
    v10 = *(volatile uint16_t *)(a1 + 24);
    *(volatile uint16_t *)(a1 + 48) = *(volatile uint16_t *)(a1 + 4);
    v11 = v7 + result;
    *(volatile uint8_t *)(a1 + 53) = v13;
    if ( (uint16_t)__rev16(v10) <= 0x600u )
    {
      v12 = 0;
    }
    else
    {
      v11 += 8;
      v12 = 8;
    }
    *(volatile uint8_t *)(a1 + 51) = v11;
    *(volatile uint8_t *)(a1 + 66) = v11;
    *(volatile uint8_t *)(a1 + 52) = v12;
  }
  return result;
}



// rf_apply_chan_cfg @ 0x13a704
int rf_apply_chan_cfg(int a1, int a2) {
  int v2; // r11
  int v3; // r10
  int v4; // r8
  int v5; // r7
  int v6; // r6
  int v7; // r3
  int v8; // lr
  int v10; // r2
  int v12; // r4
  int16_t v13; // r3
  int v14; // r1
  int v15; // r0
  int16_t v16; // r1
  int v17; // r0
  int v18; // r3
  int v19; // r12
  int v20; // r3
  int v21; // r3
  int v22; // r3
  int16_t v24; // lr
  int16_t v25; // r3
  int16_t v26; // r3
  int v27; // r6
  int v28; // r6
  int v29; // r0
  int16_t v30; // r3
  int v31; // [sp+4h] [bp-10h]
  int v32; // [sp+8h] [bp-Ch]
  int v33; // [sp+Ch] [bp-8h]

  v2 = *(volatile uint8_t *)(a1 + 29);
  v3 = dword_13A97C;
  v4 = *(volatile uint8_t *)(a1 + 28);
  v5 = dword_13A978;
  v6 = 696 * v2;
  v7 = dword_13A97C + 696 * v2;
  v8 = dword_13A978 + 1320 * v4;
  v32 = *(volatile uint32_t *)(v7 + 184);
  v10 = **(volatile uint32_t **)(v7 + 188);
  v31 = *(volatile uint32_t *)(v8 + 1200);
  v12 = a2 - *(volatile uint8_t *)(a1 + 50);
  if ( *(volatile uint8_t *)(v8 + 106) )
  {
    v13 = 0;
  }
  else
  {
    if ( (*(volatile uint32_t *)(v7 + 4) & 0x20) == 0 )
    {
      v13 = 0;
      v14 = *(volatile uint8_t *)(a1 + 27);
      if ( v14 == 255 )
        goto LABEL_4;
      goto LABEL_26;
    }
    v33 = **(volatile uint32_t **)(v7 + 188);
    v29 = get_phy_descriptor(a1, dword_13A97C + 696 * v2);
    v10 = v33;
    *(volatile uint32_t *)(a2 - 4) = v29;
    v13 = 0x8000;
  }
  v14 = *(volatile uint8_t *)(a1 + 27);
  if ( v14 == 255 )
  {
LABEL_4:
    v15 = *(volatile uint16_t *)(a1 + 30);
    *(volatile uint16_t *)v12 = v13 | 8;
    *(volatile uint8_t *)(v12 + 22) = 0;
    *(volatile uint8_t *)(v12 + 23) = 0;
    v16 = v13 | 8;
    if ( (v15 & 0x800) != 0 )
    {
LABEL_5:
      v16 = v13 & 0xFCF7 | 8;
      *(volatile uint16_t *)v12 = v16;
      goto LABEL_6;
    }
    if ( (v15 & 0x100) != 0 )
      goto LABEL_30;
    goto LABEL_32;
  }
LABEL_26:
  v15 = *(volatile uint16_t *)(a1 + 30);
  *(volatile uint16_t *)(v12 + 22) = 16 * *(volatile uint16_t *)(a1 + 32);
  *(volatile uint8_t *)(v12 + 1) = 0;
  if ( (v15 & 0x200) != 0 )
    v14 = (v14 & ~0xFFFFu) | ((uint16_t)(v14 | 0x10) & 0xFFFFu);
  *(volatile uint8_t *)v12 = 0x80;
  v24 = v13 | 0x88;
  if ( (v15 & 0x100) != 0 )
  {
    *(volatile uint16_t *)(v12 + 30) = v14;
    v13 |= 0x80u;
    *(volatile uint16_t *)v12 = v24;
    if ( (v15 & 0x800) != 0 )
      goto LABEL_5;
LABEL_30:
    v25 = v13 | 0x308;
    *(volatile uint16_t *)v12 = v25;
    v16 = v25;
    goto LABEL_6;
  }
  *(volatile uint16_t *)(v12 + 24) = v14;
  v13 |= 0x80u;
  *(volatile uint16_t *)v12 = v24;
  v16 = v24;
  if ( (v15 & 0x800) != 0 )
    goto LABEL_5;
LABEL_32:
  if ( *(volatile uint8_t *)(v5 + 1320 * v4 + 106) )
  {
    if ( *(volatile uint8_t *)(v5 + 1320 * v4 + 106) == 2 )
    {
      v30 = v13 | 0x208;
      *(volatile uint16_t *)v12 = v30;
      v16 = v30;
    }
  }
  else
  {
    v26 = v13 | 0x108;
    *(volatile uint16_t *)v12 = v26;
    v16 = v26;
  }
LABEL_6:
  v17 = v15 << 29;
  v18 = 1320 * v4;
  if ( v17 < 0 )
    v16 |= 0x2000u;
  v19 = v18 + 100;
  if ( v17 < 0 )
    *(volatile uint16_t *)v12 = v16;
  *(volatile uint16_t *)(v12 + 10) = *(volatile uint16_t *)(v5 + v19);
  *(volatile uint16_t *)(v12 + 12) = *(volatile uint16_t *)(v5 + v19 + 2);
  *(volatile uint16_t *)(v12 + 14) = *(volatile uint16_t *)(v5 + v19 + 4);
  if ( (v16 & 0x300) == 0x100 )
  {
    v27 = v6 + 38;
    *(volatile uint16_t *)(v12 + 4) = *(volatile uint16_t *)(v3 + v27);
    *(volatile uint16_t *)(v12 + 6) = *(volatile uint16_t *)(v3 + v27 + 2);
    *(volatile uint16_t *)(v12 + 8) = *(volatile uint16_t *)(v3 + v27 + 4);
    *(volatile uint16_t *)(v12 + 16) = *(volatile uint16_t *)(a1 + 12);
    *(volatile uint16_t *)(v12 + 18) = *(volatile uint16_t *)(a1 + 14);
    *(volatile uint16_t *)(v12 + 20) = *(volatile uint16_t *)(a1 + 16);
  }
  else if ( (v16 & 0x300) == 0x200 )
  {
    *(volatile uint16_t *)(v12 + 4) = *(volatile uint16_t *)(a1 + 12);
    *(volatile uint16_t *)(v12 + 6) = *(volatile uint16_t *)(a1 + 14);
    *(volatile uint16_t *)(v12 + 8) = *(volatile uint16_t *)(a1 + 16);
    *(volatile uint16_t *)(v12 + 16) = *(volatile uint16_t *)(a1 + 18);
    *(volatile uint16_t *)(v12 + 18) = *(volatile uint16_t *)(a1 + 20);
    *(volatile uint16_t *)(v12 + 20) = *(volatile uint16_t *)(a1 + 22);
  }
  else if ( (v16 & 0x300) != 0 )
  {
    v28 = v6 + 38;
    *(volatile uint16_t *)(v12 + 4) = *(volatile uint16_t *)(v3 + v28);
    *(volatile uint16_t *)(v12 + 6) = *(volatile uint16_t *)(v3 + v28 + 2);
    *(volatile uint16_t *)(v12 + 8) = *(volatile uint16_t *)(v3 + v28 + 4);
    *(volatile uint16_t *)(v12 + 16) = *(volatile uint16_t *)(a1 + 12);
    *(volatile uint16_t *)(v12 + 18) = *(volatile uint16_t *)(a1 + 14);
    *(volatile uint16_t *)(v12 + 20) = *(volatile uint16_t *)(a1 + 16);
    *(volatile uint16_t *)(v12 + 24) = *(volatile uint16_t *)(a1 + 18);
    *(volatile uint16_t *)(v12 + 26) = *(volatile uint16_t *)(a1 + 20);
    *(volatile uint16_t *)(v12 + 28) = *(volatile uint16_t *)(a1 + 22);
  }
  else
  {
    *(volatile uint16_t *)(v12 + 4) = *(volatile uint16_t *)(a1 + 12);
    *(volatile uint16_t *)(v12 + 6) = *(volatile uint16_t *)(a1 + 14);
    *(volatile uint16_t *)(v12 + 8) = *(volatile uint16_t *)(a1 + 16);
    v20 = v18 + 368;
    *(volatile uint16_t *)(v12 + 16) = *(volatile uint16_t *)(v5 + v20);
    v21 = v20 + v5;
    *(volatile uint16_t *)(v12 + 18) = *(volatile uint16_t *)(v21 + 2);
    *(volatile uint16_t *)(v12 + 20) = *(volatile uint16_t *)(v21 + 4);
  }
  if ( v10
    && v31
    && ((*(volatile uint32_t *)(v5 + 1320 * v4 + 1208) & 2) == 0
     || *(volatile uint16_t *)(v3 + 696 * *(volatile uint8_t *)(a1 + 29) + 56) != (uint16_t)__rev16(*(volatile uint16_t *)(a1 + 24))) )
  {
    if ( !v32
      || (v22 = *(volatile uint8_t *)(v32 + 96), v22 == 4)
      || (unsigned int)(v22 - 1) <= 1 && *(volatile uint8_t *)(v3 + 696 * v2 + 669) > 1u )
    {
      *(volatile uint16_t *)v12 = v16 | 0x4000;
    }
  }
  return v12;
}



// ll_conn_context_get @ 0x13a980
volatile uint16_t * ll_conn_context_get(int a1, volatile uint16_t *a2, int a3) {
  int v4; // r5
  int v5; // r3
  volatile uint16_t *v6; // r9
  volatile uint8_t *v7; // r8
  int v9; // r4
  int v10; // r5
  int v11; // r3
  int16_t v12; // r3
  int v13; // r2

  v4 = *(volatile uint8_t *)(a1 + 29);
  v5 = dword_13AADC + 696 * v4;
  v6 = a2;
  v7 = **(volatile uint8_t ***)(v5 + 188);
  if ( v7 )
  {
    v9 = dword_13AAE0 + 1320 * *(volatile uint8_t *)(a1 + 28);
    if ( *(volatile uint32_t *)(v9 + 1200) )
    {
      if ( (*(volatile uint32_t *)(v9 + 1208) & 2) == 0
        || *(volatile uint16_t *)(v5 + 56) != (uint16_t)__rev16(*(volatile uint16_t *)(a1 + 24)) )
      {
        v10 = dword_13AADC + 696 * v4;
        v11 = *(volatile uint32_t *)(v10 + 184);
        if ( !v11 || (unsigned int)*(volatile uint8_t *)(v11 + 96) - 1 > 1 || *(volatile uint8_t *)(v10 + 669) > 1u )
        {
          switch ( v7[96] )
          {
            case 0:
            case 3:
              *(a2 - 2) = *(volatile uint16_t *)(a1 + 56);
              v6 = a2 - 2;
              *(a2 - 1) = *(volatile uint16_t *)(a1 + 58) | ((uint8_t)v7[97] << 14);
              if ( a3 )
                goto LABEL_11;
              goto LABEL_17;
            case 1:
              *(a2 - 4) = *(volatile uint16_t *)(a1 + 56) & 0x5F00 | 0x2000 | HIBYTE(*(volatile uint16_t *)(a1 + 56));
              v6 = a2 - 4;
              v12 = *(volatile uint8_t *)(a1 + 56) | (uint16_t)((uint8_t)v7[97] << 14);
              goto LABEL_9;
            case 2:
            case 6:
            case 7:
            case 8:
              *(a2 - 4) = *(volatile uint16_t *)(a1 + 56);
              v6 = a2 - 4;
              v12 = (uint8_t)v7[97] << 14;
LABEL_9:
              v6[1] = v12 | 0x2000;
              v6[2] = *(volatile uint16_t *)(a1 + 58);
              v6[3] = *(volatile uint16_t *)(a1 + 60);
              break;
            case 4:
              *(a2 - 9) = (uint8_t)v7[97];
              v6 = a2 - 9;
              v6[1] = *(volatile uint16_t *)(a1 + 56);
              v6[2] = *(volatile uint16_t *)(a1 + 58);
              v6[3] = *(volatile uint16_t *)(a1 + 60);
              v6[4] = *(volatile uint16_t *)(a1 + 62);
              v6[5] = 23606;
              v6[6] = 23606;
              v6[7] = 23606;
              v6[8] = 23606;
              break;
            default:
              if ( **(volatile int16_t **)off_13AAE8 < 0 )
                mmio_clear_register(dword_13AAF0, dword_13AAEC, 743);
              break;
          }
          if ( a3 )
LABEL_11:
            v13 = *(volatile uint32_t *)(a1 + 44);
          else
LABEL_17:
            v13 = *(volatile uint32_t *)(a1 + 72) + 44;
          *(volatile uint32_t *)(v13 + 12) = dword_13AAE4 & *(volatile uint32_t *)(v13 + 12) | (uint8_t)v7[98];
        }
      }
    }
  }
  return v6;
}



// ll_conn_event_prepare @ 0x13aaf4
int ll_conn_event_prepare(int a1, int a2, int a3) {
  int v6; // r3
  int v7; // r1
  volatile int *v8; // r5
  int result; // r0
  int v10; // r3
  int v11; // r2

  check_status_bits(
    32,
    "txu discard: %d, %x, %d\r\n",
    *(volatile uint16_t *)(a1 + 32),
    *(volatile uint16_t *)(a1 + 30),
    *(volatile uint8_t *)(a1 + 27));
  v6 = *(volatile uint16_t *)(a1 + 30);
  v7 = v6 << 31;
  if ( (v6 & 1) != 0 || (irq_counter_inc(), (*(volatile uint16_t *)(a1 + 30) & 1) != 0) )
    event_dispatch(aRetransmitTxuD, v7);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_13AB68 = 1;
  }
  v8 = (volatile int *)off_13AB6C;
  ++*(volatile uint32_t *)off_13AB6C;
  result = ipc_handler_register((volatile uint32_t *)a1, a3, a2);
  if ( *v8 )
  {
    v10 = *v8 - 1;
    v11 = *(volatile uint32_t *)off_13AB68;
    *v8 = v10;
    if ( !v10 )
    {
      if ( v11 )
        __enable_irq();
    }
  }
  return result;
}


// ll_conn_event_type_check @ 0x13ab70
int ll_conn_event_type_check(int a1, volatile uint16_t *a2) {
  unsigned int v2; // r2
  volatile uint16_t *v4; // r1

  v2 = *(volatile uint16_t *)(a1 + 24);
  if ( (uint16_t)__rev16(v2) >= 0x600u )
  {
    *(a2 - 4) = -21846;
    a2 -= 4;
    a2[3] = v2;
    a2[1] = 3;
    a2[2] = 0;
  }
  v4 = ll_conn_context_get(a1, a2, 1);
  return rf_apply_chan_cfg(a1, (int)v4);
}



// ll_conn_state_dispatch @ 0x13aba8
int ll_conn_state_dispatch(unsigned int a1, int a2) {
  unsigned int v2; // r6
  int v5; // r3
  int v6; // r7
  int v7; // r3
  int16_t v9; // r0
  int v10; // r2
  volatile uint8_t *v11; // r7
  int v12; // r3
  int16_t v13; // r8
  int v14; // r6
  int v15; // r8
  volatile int *v16; // r9
  volatile int16_t **v17; // r10
  int v18; // r7
  unsigned int v19; // r0
  signed int v20; // r1
  unsigned int v21; // r0
  char v22; // r2
  int v23; // r9
  volatile uint8_t *v24; // r8
  int v25; // r1
  int v26; // r3
  unsigned int v27; // r6
  volatile uint32_t *v28; // r7
  volatile int *v29; // r3
  int16_t v30; // r3
  int v31; // r0
  void *v32; // r3
  int v33; // r0
  int v34; // r2
  volatile uint32_t *v35; // r0
  int v36; // r2
  int v37; // r0
  char v38; // r2
  volatile uint32_t *v39; // r0
  int v40; // r1
  struct __attribute__((packed)) { char v41; // [sp+4h] [bp-10h]
  char _pad1[7]; int a2a; // [sp+Ch] [bp-8h] BYREF
  } _frame;
  v2 = *(volatile uint8_t *)(a1 + 28);
  if ( v2 > 3 )
    return ll_conn_event_prepare(a1, a2, 0x80000000);
  v5 = *(volatile uint8_t *)(a1 + 29);
  if ( v5 == 255 )
  {
    if ( (*(volatile uint16_t *)(a1 + 30) & 8) == 0 )
    {
      event_dispatch(aDataStaInvalid);
      return ll_conn_event_prepare(a1, a2, 0x80000000);
    }
    goto LABEL_11;
  }
  v6 = dword_13AEAC;
  v7 = dword_13AEAC + 696 * v5;
  if ( !*(volatile uint8_t *)(v7 + 37) || *(volatile uint8_t *)(v7 + 48) )
    return ll_conn_event_prepare(a1, a2, 0x80000000);
  v9 = *(volatile uint16_t *)(a1 + 30);
  if ( (v9 & 8) != 0 )
  {
LABEL_11:
    v11 = (void *)(uintptr_t)(off_13AEB4);
    v12 = *((volatile uint8_t *)off_13AEB4 + 13);
    _frame.a2a = 0;
    if ( v12 && (*((volatile uint8_t *)off_13AEB4 + 15) & 6) == 2 && (*(volatile uint16_t *)(*(volatile uint32_t *)(a1 + 72) + 172) & 0xFC) == 0xB0 )
    {
      ke_task_create(6155, 6, dword_13AEB8);
      mmio_set_control_bit_26();
      v11[15] |= 4u;
    }
    v13 = *(volatile uint16_t *)(a1 + 30);
    v14 = dword_13AEBC + 1320 * v2;
    if ( (v13 & 0x10) != 0 || *(volatile uint8_t *)(v14 + 1224) )
    {
      *(volatile uint32_t *)(a1 + 44) = off_13AEC0;
    }
    else
    {
      v32 = (void *)(uintptr_t)(off_13AEC4);
      if ( *(volatile uint8_t *)(*(volatile uint32_t *)(v14 + 72) + 4) )
        v32 = (void *)(uintptr_t)(off_13AEC0);
      *(volatile uint32_t *)(a1 + 44) = (int)(uintptr_t)(v32);
    }
    v15 = v13 & 0x80;
    if ( v15 )
    {
      v33 = get_channel_tx_power(a1, 192, 0);
      if ( v33 == 1 )
      {
        v15 = (v15 & ~0xFFu) | ((uint8_t)(rf_get_chan_cfg(a1, (void *)(&_frame.a2a))) & 0xFFu);
        memcpy((volatile char *)(*(volatile uint32_t *)(a1 + 72) + 164), (volatile char *)(*(volatile uint32_t *)(a1 + 72) + 172), 0x18u);
        _frame.v41 = 24;
      }
      else
      {
        v15 = (v15 & ~0xFFu) | ((uint8_t)(0) & 0xFFu);
        if ( v33 == 2 )
          _frame.a2a = 18;
        else
          *(volatile uint16_t *)(a1 + 30) &= ~0x80u;
        _frame.v41 = 0;
      }
    }
    else
    {
      _frame.v41 = 0;
    }
    v16 = (volatile int *)off_13AEC8;
    v17 = (volatile int16_t **)off_13AECC;
    v18 = 0;
    while ( 1 )
    {
      v19 = *(volatile uint32_t *)(a1 + 8);
      v20 = v19 & 0x7F;
      if ( (v19 & 0x40000000) != 0 )
      {
        v21 = (v19 >> 11) & 7;
        *(volatile uint32_t *)(*(volatile uint32_t *)(a1 + 44) + 4 * v18 + 20) = *(volatile uint32_t *)(a1 + 8) & 0x387F | 0x20000000;
        if ( !*((volatile uint8_t *)v16 + 197) )
          goto LABEL_22;
      }
      else
      {
        v21 = (*(volatile uint32_t *)(*(volatile uint32_t *)(a1 + 44) + 4 * v18 + 20) >> 11) & 7;
        v20 = *(volatile uint32_t *)(*(volatile uint32_t *)(a1 + 44) + 4 * v18 + 20) & 0x7F;
        if ( !*((volatile uint8_t *)v16 + 197) )
        {
LABEL_22:
          if ( **v17 < 0 )
            mmio_clear_register(off_13AED0, (int)aTxuCntrlUmacde, 414);
          goto LABEL_24;
        }
      }
      v31 = rx_packet_handler(v21, v20, (volatile uint8_t *)(*(volatile uint32_t *)(v14 + 72) + 4));
      *(volatile uint32_t *)(*(volatile uint32_t *)(a1 + 44) + 4 * v18 + 36) = v31 | (v31 << 8);
LABEL_24:
      if ( ++v18 == 4 )
      {
        *(volatile uint8_t *)(a1 + 50) = _frame.v41;
        *(volatile uint32_t *)(a1 + 36) = 0;
        *(volatile uint32_t *)(a1 + 40) = 0;
        v22 = _frame.a2a;
        *(volatile uint8_t *)(a1 + 51) = v15;
        *(volatile uint8_t *)(a1 + 66) = v15;
        *(volatile uint8_t *)(a1 + 53) = v22;
        return phy_chan_set(a1, a2);
      }
    }
  }
  v10 = *(volatile uint8_t *)(v7 + 52);
  if ( *(volatile uint16_t *)(v7 + 56) == (uint16_t)__rev16(*(volatile uint16_t *)(a1 + 24)) )
  {
    *(volatile uint16_t *)(a1 + 30) = v9 & 0xFEFF;
    if ( (unsigned int)(v10 - 1) > 1 )
    {
      v10 = *(volatile uint8_t *)(v7 + 52);
      goto LABEL_9;
    }
  }
  else if ( v10 != 2 )
  {
LABEL_9:
    check_status_bits(32, "port filter:%d\r\n", v10);
    return ll_conn_event_prepare(a1, a2, 0x80000000);
  }
  v23 = dword_13AEBC;
  v24 = (volatile uint8_t *)(dword_13AEBC + 1320 * v2);
  if ( !v24[108] )
  {
    event_dispatch(aTxuVifInactive);
    return ll_conn_event_prepare(a1, a2, 0x80000000);
  }
  rf_reset_chan_cfg(a1);
  v26 = v6 + 696 * *(volatile uint8_t *)(a1 + 29);
  if ( *(volatile uint8_t *)(v26 + 52) != 2 )
    goto LABEL_31;
  v34 = v24[106];
  if ( v24[106] )
  {
    if ( v34 != 2 || !*(volatile uint8_t *)(v26 + 688) )
      goto LABEL_53;
LABEL_31:
    v27 = v23 + 1320 * v2;
    v28 = (void *)(uintptr_t)(off_13AEC4);
    v29 = (volatile int *)off_13AEC8;
    if ( *(volatile uint8_t *)(*(volatile uint32_t *)(v27 + 72) + 4) )
      v28 = (void *)(uintptr_t)(off_13AEC0);
    *(volatile uint32_t *)(a1 + 44) = (int)(uintptr_t)(v28);
    if ( *((volatile uint8_t *)v29 + 197) )
    {
      v37 = rx_packet_handler((v28[5] >> 11) & 7, v28[5] & 0x7F, (volatile uint8_t *)(*(volatile uint32_t *)(v27 + 72) + 4));
      v30 = *(volatile uint16_t *)(a1 + 30);
      v28[9] = v37 | (v37 << 8);
    }
    else
    {
      if ( **(volatile int16_t **)off_13AECC < 0 )
        mmio_clear_register(off_13AF20, (int)aTxuCntrlPush, 1195);
      v30 = *(volatile uint16_t *)(a1 + 30);
    }
    goto LABEL_37;
  }
  if ( v24[149] )
    goto LABEL_31;
LABEL_53:
  if ( !*(volatile uint8_t *)off_13AEDC )
    ((int (*)())read_tx_power_cal)(a1, v25, v34, *(volatile uint8_t *)off_13AEDC);
  ble_ll_adv_set_data(a1);
  v35 = tx_send_controller_pkt(v6 + 696 * *(volatile uint8_t *)(a1 + 29));
  v30 = *(volatile uint16_t *)(a1 + 30);
  *(volatile uint32_t *)(a1 + 44) = (int)(uintptr_t)(v35);
  if ( (v30 & 0x2000) != 0 )
  {
    v36 = *(volatile uint32_t *)(v6 + 696 * *(volatile uint8_t *)(a1 + 29) + 340);
    *(volatile uint32_t *)(a1 + 40) = *(volatile uint32_t *)(v36 + 156);
    if ( *(volatile uint8_t *)(v36 + 165) )
      *(volatile uint8_t *)(a1 + 54) |= 0x20u;
  }
  else
  {
    v38 = *(volatile uint8_t *)(a1 + 54);
    v39 = &v35[v38 & 3];
    v40 = v39[9];
    *(volatile uint32_t *)(a1 + 40) = v39[5];
    if ( (v40 & 0x40000) != 0 )
      *(volatile uint8_t *)(a1 + 54) = v38 | 0x20;
  }
LABEL_37:
  if ( (v30 & 1) == 0 )
    ll_conn_event_type_check(a1, (volatile uint16_t *)(*(volatile uint32_t *)(a1 + 72) + 172));
  return phy_chan_set(a1, a2);
}


// ll_conn_reset_flags @ 0x13af24
int ll_conn_reset_flags(int a1, int a2) {
  int16_t v2; // r2

  v2 = *(volatile uint16_t *)(a1 + 30) | 1;
  *(volatile uint32_t *)(a1 + 68) = 0;
  *(volatile uint32_t *)(a1 + 80) = 0;
  *(volatile uint16_t *)(a1 + 30) = v2;
  return ll_conn_state_dispatch(a1, a2);
}



// ll_conn_rx_packet_get @ 0x13af3c
volatile int * ll_conn_rx_packet_get(volatile int *result) {
  int v1; // r5

  v1 = **(volatile uint32_t **)(dword_13AF7C + 696 * *((volatile uint8_t *)result + 29) + 188);
  if ( v1 )
  {
    if ( *(volatile uint8_t *)(v1 + 96) == 1 )
      return check_global_flag(
               (int)result,
               v1 + 80,
               result[18] - *((volatile uint8_t *)result + 52) + 172,
               *((volatile uint8_t *)result + 52) + *((volatile uint16_t *)result + 24));
  }
  return result;
}



// ll_conn_tx_pdu_check @ 0x13af80
int ll_conn_tx_pdu_check(int a1, int a2) {
  int v2; // r5
  int v3; // r3
  int16_t v5; // r0
  int v6; // r3
  int v8; // r6
  int v9; // r0
  char v10; // r0
  int v11; // r3
  int result; // r0
  int v13; // r1
  int v14; // r3

  v2 = *(volatile uint32_t *)(a1 + 76);
  v3 = *(volatile uint16_t *)(a1 + 32);
  v5 = *(volatile uint16_t *)(a1 + 30);
  v6 = 16 * v3;
  v8 = *(volatile uint32_t *)(v2 + 4) & 0x800000;
  *(volatile uint32_t *)(v2 + 4) = v6;
  if ( (v5 & 8) != 0 )
  {
    if ( (v5 & 0x20) != 0 )
    {
      if ( v8 )
      {
        if ( (v5 & 0x200) == 0 )
          goto LABEL_19;
LABEL_5:
        if ( **(volatile int16_t **)off_13B090 >= 0 )
          goto LABEL_6;
        goto LABEL_27;
      }
      clear_flag();
      if ( (*(volatile uint16_t *)(a1 + 30) & 0x200) != 0 )
        goto LABEL_5;
LABEL_9:
      if ( *(volatile uint8_t *)(a1 + 27) == 255 )
        goto LABEL_10;
      goto LABEL_20;
    }
    if ( (v5 & 0x200) != 0 )
    {
      if ( **(volatile int16_t **)off_13B090 >= 0 )
        goto LABEL_6;
LABEL_27:
      v9 = *(volatile uint8_t *)(a1 + 29);
      if ( v9 != 255 )
        goto LABEL_7;
      mmio_clear_register(dword_13B09C, dword_13B098, 1325);
LABEL_6:
      v9 = *(volatile uint8_t *)(a1 + 29);
LABEL_7:
      rf_channel_set(v9, 23, 0, 0);
      *(volatile uint8_t *)(dword_13B094 + 696 * *(volatile uint8_t *)(a1 + 29) + 54) = 0;
    }
LABEL_8:
    if ( !v8 )
      goto LABEL_9;
    goto LABEL_18;
  }
  if ( (v5 & 0x200) == 0 )
    goto LABEL_8;
  *(volatile uint8_t *)(dword_13B094 + 696 * *(volatile uint8_t *)(a1 + 29) + 54) = 0;
  if ( !v8 )
    goto LABEL_9;
LABEL_18:
  v6 = *(volatile uint32_t *)(v2 + 4);
LABEL_19:
  *(volatile uint32_t *)(v2 + 4) = v6 | 8;
  if ( *(volatile uint8_t *)(a1 + 27) == 255 )
  {
LABEL_10:
    v10 = 1;
    if ( (*(volatile uint32_t *)(a1 + 36) & 0x200000) != 0 )
      goto LABEL_11;
    goto LABEL_17;
  }
LABEL_20:
  v13 = v8;
  if ( v8 )
    v13 = 1;
  v10 = get_tx_power_cal_entry(a1, v13, a2);
  v14 = *(volatile uint32_t *)(a1 + 36);
  if ( (v14 & 0x200000) == 0 )
  {
LABEL_17:
    *(volatile uint8_t *)(v2 + 1) = 1;
    goto LABEL_11;
  }
  if ( (v14 & 0x380000) != 0x380000 )
    *(volatile uint8_t *)(v2 + 1) = 0;
LABEL_11:
  v11 = *(volatile uint32_t *)(v2 + 4);
  *(volatile uint8_t *)v2 = v10;
  result = v11 & 2;
  *(volatile uint32_t *)(v2 + 4) = v11 | 1;
  if ( (v11 & 2) != 0 )
    return *(volatile uint8_t *)(dword_13B094 + 696 * *(volatile uint8_t *)(a1 + 29) + 48) == 0;
  return result;
}



// ll_conn_window_calc @ 0x13b0a0
volatile uint16_t * ll_conn_window_calc(int a1, volatile uint16_t *a2, int a3) {
  volatile uint16_t *v6; // r1
  int v8; // r0
  char v9; // r3
  int v10; // [sp+4h] [bp-4h] BYREF

  if ( *(volatile uint8_t *)(a1 + 51) )
  {
    v6 = (volatile uint16_t *)((volatile char *)a2 + a3 + *(volatile uint8_t *)(a1 + 51));
  }
  else
  {
    v8 = rf_get_chan_cfg(a1, (void *)(&v10));
    v9 = v10;
    *(volatile uint8_t *)(a1 + 51) = v8;
    v6 = (volatile uint16_t *)((volatile char *)a2 + a3 + v8);
    *(volatile uint8_t *)(a1 + 53) = v9;
  }
  *a2 |= 0x4000u;
  return ll_conn_context_get(a1, v6, 0);
}



// ll_encrypt_packet @ 0x13b0e0
int ll_encrypt_packet(int a1, int a2, unsigned int a3) {
  int v3; // r3
  int v6; // r5
  unsigned int v7; // r6
  unsigned int v9; // r7
  int v10; // r8
  unsigned int v11; // r2
  int v12; // r11
  unsigned int a5; // r7
  unsigned int v14; // r10
  uint16_t v15; // r8
  int v16; // r9
  uint16_t v17; // r3
  int v18; // r1
  int v19; // r4
  int v20; // r2
  volatile unsigned int v21; // r1
  int v22; // r8
  unsigned int v23; // r8
  uint16_t v24; // r3
  unsigned int v25; // r2
  unsigned int v26; // r7
  char v27; // r0
  int v28; // r1
  int v29; // r2
  int v30; // r3
  int v31; // r5
  int v32; // r3
  int a4; // [sp+14h] [bp-10h]
  volatile uint32_t *a4a; // [sp+14h] [bp-10h]
  volatile uint32_t *a2a; // [sp+1Ch] [bp-8h]

  v3 = *(volatile uint8_t *)(a2 + 13);
  v6 = a2 + 12;
  v7 = a3 >> 8;
  if ( v3 == 1 )
  {
    v9 = *(volatile uint16_t *)(a2 + 17);
    if ( rx_rate_field_parse(a3) != 2 )
      return 0;
    v10 = dword_13B368;
    ke_int_lock((int)(uintptr_t)((volatile char *)0x2000), a3);
    v11 = v10 + 32 * v7;
    v12 = 32 * v7;
    if ( *(volatile uint8_t *)(v11 + 23) != *(volatile uint8_t *)(v6 + 2)
      || *(volatile uint8_t *)(v11 + 22) != ((v9 >> 2) & 0xF)
      || *(volatile uint16_t *)(v6 + 3) )
    {
      rf_get_chan_state(v7);
      cmd_handler_a(dword_13B35C, (volatile uint32_t *)(v10 + v12));
      rx_phy_status_parse(a3, 0);
      return 0;
    }
    if ( *(volatile uint16_t *)(v11 + 20) > v9 >> 6 )
      *(volatile uint16_t *)(v11 + 20) = v9 >> 6;
    v29 = *((volatile uint8_t *)off_13B38C + 377);
    v30 = v10 + v12;
    if ( v29 != 1 )
    {
      if ( v29 != 2 )
      {
        *(volatile uint8_t *)(v30 + 24) = v9 & 1;
LABEL_38:
        v27 = *(volatile uint8_t *)(a2 + 7);
        v28 = v7;
LABEL_31:
        rf_ctrl_send(v27, v28);
        rx_phy_status_parse(a3, 3);
        return 0;
      }
      v29 = (v29 & ~0xFFu) | ((uint8_t)(0) & 0xFFu);
    }
    *(volatile uint8_t *)(v30 + 24) = v29;
    goto LABEL_38;
  }
  if ( v3 == 2 )
  {
    if ( rx_rate_field_parse(a3) != 4 )
    {
      if ( rx_rate_field_parse(a3) == 1 || rx_rate_field_parse(a3) == 3 )
      {
        rx_phy_status_parse(a3, 4);
        a4a = (volatile uint32_t *)(dword_13B368 + 32 * v7);
        if ( v7 > 0xF )
        {
          cmd_handler_c(dword_13B374, (volatile uint32_t *)(dword_13B368 + 32 * v7));
          cmd_handler_a(dword_13B378, a4a);
        }
        else
        {
          cmd_handler_c(dword_13B36C, (volatile uint32_t *)(dword_13B368 + 32 * v7));
          cmd_handler_a(dword_13B370, a4a);
        }
        rf_phy_write(*(volatile uint8_t *)(a2 + 7), v7);
        return 0;
      }
      v18 = dword_13B368 + 32 * v7;
      v19 = *(volatile uint8_t *)(v18 + 16);
      v20 = *(volatile uint8_t *)(v18 + 22);
      v21 = (*(volatile uint32_t *)0x40501010u);
      *(volatile uint32_t *)(696 * v19 + 12 * v20 + dword_13B37C + 448) = v21;
      rf_set_channel_3(v7);
    }
    return 0;
  }
  if ( *(volatile uint8_t *)(a2 + 13) )
    return 0;
  a5 = *(volatile uint16_t *)(a2 + 15);
  v14 = (a5 >> 2) & 0xF;
  if ( v14 > 8 )
    return 0;
  v15 = *(volatile uint8_t *)off_13B360;
  if ( *(volatile uint8_t *)off_13B360 )
    return 0;
  v16 = *(volatile uint8_t *)(a2 + 7);
  a4 = *(volatile uint8_t *)(a2 + 14);
  check_status_bits(2048, "handle addba_req:tid=%d\r\n", (a5 >> 2) & 0xF);
  if ( !phy_read_offset_b(v16, (a5 >> 2) & 0xF) )
  {
    if ( rx_rate_field_parse(a3) == 4 )
      return 2;
    v22 = dword_13B368;
    a2a = (volatile uint32_t *)(dword_13B368 + 32 * v7);
    if ( mem_word_cmp((volatile uint32_t **)dword_13B384, a2a) )
      cmd_handler_c(dword_13B384, a2a);
    v23 = v22 + 32 * v7;
    *(volatile uint8_t *)(v23 + 22) = v14;
    *(volatile uint8_t *)(v23 + 16) = v16;
    *(volatile uint8_t *)(v23 + 23) = a4;
    *(volatile uint8_t *)(v23 + 18) = (a5 & 2) != 0;
    *(volatile uint8_t *)(v23 + 17) = 0;
    v24 = *(volatile uint16_t *)(v6 + 5);
    v25 = *(volatile uint16_t *)(v6 + 7);
    *(volatile uint16_t *)(v23 + 14) = v24;
    v26 = a5 >> 6;
    if ( v26 >= 0x40 )
      v26 = (v26 & ~0xFFFFu) | ((uint16_t)(64) & 0xFFFFu);
    *(volatile uint16_t *)(v23 + 20) = v26;
    *(volatile uint16_t *)(v23 + 12) = v25 >> 4;
    *(volatile uint32_t *)(v23 + 4) = 0;
    if ( !v24 )
      *(volatile uint16_t *)(v23 + 14) = *(volatile uint16_t *)(*(volatile uint32_t *)off_13B388 + 2);
    v27 = v16;
    v28 = v7;
    goto LABEL_31;
  }
  if ( rx_rate_field_parse(a3) == 1 )
  {
    v31 = dword_13B368 + 32 * v7;
    v32 = a5 >> 6;
    if ( a5 >> 6 >= 0x40 )
      v32 = 64;
    if ( *(volatile uint16_t *)(v31 + 20) == v32 )
    {
      v17 = v15;
    }
    else
    {
      rx_phy_status_parse(a3, 4);
      cmd_handler_c(dword_13B36C, (volatile uint32_t *)v31);
      cmd_handler_a(dword_13B370, (volatile uint32_t *)v31);
      rf_phy_write(v16, v7);
      v17 = 37;
    }
  }
  else
  {
    v17 = 37;
  }
  adv_set_params(v16, 0, 1, a4, a5, v17, 0);
  return 0;
}


// ll_ccm_decrypt @ 0x13b390
int ll_ccm_decrypt(int a1, int a2, unsigned int a3) {
  rf_get_chan_param_1(a3 >> 8);
  return 0;
}



