// process_tx_packet @ 0x116324
int process_tx_packet(int a1, int a2) {
  int v2; // r3
  volatile uint32_t *v3; // r5
  int v4; // r6
  int v5; // r7
  volatile uint32_t *v7; // r8
  int v8; // r3
  int result; // r0
  volatile int16_t **v10; // r7
  int v11; // r5
  volatile uint16_t *v12; // r3
  int v13; // r3
  int v14; // r2
  int16_t v15; // r12
  volatile int16_t **v16; // r9
  int v17; // r3
  int v18; // r3
  char v19; // r2
  int v20; // r2
  int16_t v21; // r2
  int v22; // r3
  int v23; // r3
  int v24; // r3
  int v25; // r7
  unsigned int v26; // r2
  int v27; // r3
  int v28; // r2
  int v29; // r3
  int v30; // r2
  volatile int16_t **v31; // r9
  int v32; // r7
  volatile int16_t *v33; // r3
  int v34; // r3
  int16_t v35; // r12
  unsigned int v36; // r2
  int v37; // r2
  unsigned int v38; // r3
  volatile uint16_t *v40; // r0
  char v41; // r3
  uint64_t v42; // kr00_8

  v2 = *(volatile uint32_t *)(a1 + 36);
  v3 = *(volatile uint32_t **)(a1 + 72);
  v4 = *(volatile uint32_t *)(a1 + 76);
  v5 = v2 & 0x200000;
  v7 = v3 + 11;
  if ( (v2 & 0x200000) == 0 )
  {
    v15 = *(volatile uint16_t *)(a1 + 30);
    if ( (v15 & 8) != 0 )
    {
      v16 = (volatile int16_t **)off_116614;
      if ( **(volatile int16_t **)off_116614 >= 0 )
      {
        v17 = *(volatile uint32_t *)(v4 + 28);
        if ( v17 )
        {
LABEL_15:
          *(volatile uint32_t *)(v4 + 68) &= 0xFF87FFFF;
          v19 = *(volatile uint8_t *)(v17 + 4);
          *(volatile uint32_t *)(v4 + 48) = (int)(uintptr_t)(v7);
          if ( (v19 & 1) == 0 )
            v5 = 512;
          v20 = v15 & 1;
          *(volatile uint32_t *)(v4 + 64) = v5;
          if ( (v15 & 1) == 0 )
            *(volatile uint32_t *)(v4 + 72) = 0;
LABEL_19:
          if ( v20 )
          {
            a2 = *(volatile uint32_t *)(v4 + 64) | 1;
            v21 = *(volatile uint16_t *)v17 | 0x800;
            *(volatile uint32_t *)(v4 + 64) = a2;
            *(volatile uint16_t *)v17 = v21;
          }
          if ( (*((volatile uint8_t *)off_116618 + 361) & 1) != 0 )
          {
            v22 = *(volatile uint8_t *)(v17 + 4);
            a2 = v22 << 31;
            if ( (v22 & 1) == 0 )
            {
              v23 = *(volatile uint32_t *)(a1 + 44);
              if ( v23 != dword_11661C && v23 != dword_116620 )
              {
                check_event_flags((void *)(v3 + 16), (void *)(v3 + 20));
                check_event_flags((void *)(v3 + 17), (void *)(v3 + 21));
                check_event_flags((void *)(v3 + 18), (void *)(v3 + 22));
                check_event_flags((void *)(v3 + 19), (void *)(v3 + 23));
              }
            }
          }
          v24 = v3[12];
          *(volatile uint32_t *)(v4 + 44) = v3[25];
          v3[12] = v24 | 2;
          return (int)(uintptr_t)(((int (*)())wait_channel_clear)((void *)(uintptr_t)(a1), a2));
        }
        v18 = *(volatile uint32_t *)(v4 + 24);
LABEL_14:
        v17 = *(volatile uint32_t *)(v18 + 8);
        goto LABEL_15;
      }
      if ( v3 )
      {
        v17 = *(volatile uint32_t *)(v4 + 28);
        if ( v17 )
          goto LABEL_15;
      }
      else
      {
        mmio_clear_register(dword_116634, dword_116624, 518);
        v17 = *(volatile uint32_t *)(v4 + 28);
        if ( v17 )
        {
          v15 = *(volatile uint16_t *)(a1 + 30);
          goto LABEL_15;
        }
        if ( **v16 >= 0 )
          goto LABEL_66;
      }
      v18 = *(volatile uint32_t *)(v4 + 24);
      if ( v18 )
      {
LABEL_35:
        v15 = *(volatile uint16_t *)(a1 + 30);
        goto LABEL_14;
      }
      mmio_clear_register(dword_116628, dword_116624, 525);
LABEL_66:
      v18 = *(volatile uint32_t *)(v4 + 24);
      goto LABEL_35;
    }
    ((int (*)())ll_conn_rx_packet_get)();
    v30 = v3[24];
    *(volatile uint32_t *)(v4 + 64) = v30;
    if ( !*(volatile uint8_t *)(dword_11662C + 1320 * *(volatile uint8_t *)(a1 + 28) + 106)
      && (*(volatile uint32_t *)(dword_116630 + 696 * *(volatile uint8_t *)(a1 + 29) + 4) & 0x20) != 0 )
    {
      v38 = *(volatile uint32_t *)(*(volatile uint32_t *)(a1 + 44) + 60);
      if ( !((*(volatile uint16_t *)(a1 + 30) & 0x2000) != 0 ? (v38 >> 4) & 1 : (v38 >> 3) & 1) )
      {
        v40 = *(volatile uint16_t **)(v4 + 28);
        if ( (*v40 & 0x8000) != 0 )
        {
          *v40 &= ~0x8000u;
          v41 = *(volatile uint8_t *)(a1 + 50) - 4;
          *(volatile uint8_t *)(a1 + 51) -= 4;
          *(volatile uint8_t *)(a1 + 50) = v41;
          v42 = *(volatile uint64_t *)(v4 + 32);
          *(volatile uint32_t *)(v4 + 32) = v42 - 4;
          *(volatile uint32_t *)(v4 + 36) = HIDWORD(v42) - 4;
        }
      }
    }
    v31 = (volatile int16_t **)off_116614;
    v32 = *(volatile uint32_t *)(a1 + 76);
    v33 = *(volatile int16_t **)off_116614;
    *(volatile uint32_t *)(v4 + 48) = (int)(uintptr_t)(v7);
    if ( *v33 >= 0 )
    {
      v17 = *(volatile uint32_t *)(v32 + 28);
      if ( v17 )
      {
LABEL_46:
        v35 = *(volatile uint16_t *)(a1 + 30);
        v36 = v30 & 0xFFFFF9FF;
        *(volatile uint32_t *)(v4 + 64) = v36;
        a2 = *(volatile uint8_t *)(v17 + 4);
        if ( (a2 & 1) == 0 )
          *(volatile uint32_t *)(v4 + 64) = v36 | 0x200;
        v20 = v35 & 1;
        goto LABEL_19;
      }
      v34 = *(volatile uint32_t *)(v32 + 24);
LABEL_45:
      v17 = *(volatile uint32_t *)(v34 + 8);
      goto LABEL_46;
    }
    if ( *(volatile uint32_t *)(a1 + 72) )
    {
      v17 = *(volatile uint32_t *)(v32 + 28);
      if ( v17 )
        goto LABEL_46;
    }
    else
    {
      mmio_clear_register(dword_11667C, dword_116674, 518);
      v17 = *(volatile uint32_t *)(v32 + 28);
      if ( v17 )
      {
        v30 = *(volatile uint32_t *)(v4 + 64);
        goto LABEL_46;
      }
      if ( **v31 >= 0 )
        goto LABEL_74;
    }
    v34 = *(volatile uint32_t *)(v32 + 24);
    if ( v34 )
    {
LABEL_57:
      v30 = *(volatile uint32_t *)(v4 + 64);
      goto LABEL_45;
    }
    mmio_clear_register(dword_116678, dword_116674, 525);
LABEL_74:
    v34 = *(volatile uint32_t *)(v32 + 24);
    goto LABEL_57;
  }
  if ( (v2 & 0x380000) != 0x280000 )
  {
    v8 = *(volatile uint16_t *)(a1 + 30);
    result = v8 << 31;
    if ( (v8 & 1) == 0 )
      return result;
LABEL_4:
    v10 = (volatile int16_t **)off_116614;
    v11 = *(volatile uint32_t *)(a1 + 76);
    if ( **(volatile int16_t **)off_116614 >= 0 )
    {
      v12 = *(volatile uint16_t **)(v11 + 28);
      if ( v12 )
      {
LABEL_8:
        v14 = *(volatile uint32_t *)(v4 + 64) | 1;
        *v12 |= 0x800u;
        *(volatile uint32_t *)(v4 + 64) = v14;
        return result;
      }
      goto LABEL_6;
    }
    if ( *(volatile uint32_t *)(a1 + 72) )
    {
      v12 = *(volatile uint16_t **)(v11 + 28);
      if ( v12 )
        goto LABEL_8;
    }
    else
    {
      result = mmio_clear_register(dword_116634, dword_116624, 518);
      v12 = *(volatile uint16_t **)(v11 + 28);
      if ( v12 )
        goto LABEL_8;
      if ( **v10 >= 0 )
        goto LABEL_6;
    }
    v13 = *(volatile uint32_t *)(v11 + 24);
    if ( v13 )
      goto LABEL_7;
    result = mmio_clear_register(dword_116628, dword_116624, 525);
LABEL_6:
    v13 = *(volatile uint32_t *)(v11 + 24);
LABEL_7:
    v12 = *(volatile uint16_t **)(v13 + 8);
    goto LABEL_8;
  }
  v25 = *(volatile uint32_t *)(a1 + 68);
  v26 = *(volatile uint32_t *)(v25 + 4);
  *(volatile uint32_t *)(v25 + 52) = (int)(uintptr_t)(v7);
  if ( ((v26 >> 11) & 5) == 5 )
  {
    if ( (v26 & 0x600) == 0x400 )
      v37 = 0x20000;
    else
      v37 = 0x10000;
    if ( (*(volatile uint8_t *)(v25 + 344) & 0x20) != 0 )
      v3[20] = v3[20] & 0xFFFCFFFF | v37 | 0x40000;
    else
      v3[20] = v3[20] & 0xFFF8FFFF | v37 & 0xFFFBFFFF;
  }
  if ( *((volatile uint8_t *)off_116618 + 361) != 2 )
    check_event_flags((void *)(uintptr_t)(v25 + 4), (void *)(v3 + 20));
  v27 = v3[12];
  v28 = v3[24];
  v3[16] = *(volatile uint32_t *)(v25 + 4);
  *(volatile uint32_t *)(v25 + 48) = v3[25];
  *(volatile uint32_t *)(v25 + 68) = v28 | 0x600;
  v3[12] = v27 | 2;
  memcpy((void *)(uintptr_t)(v25 + 272), (void *)(v3 + 11), 52);
  v29 = *(volatile uint16_t *)(a1 + 30);
  result = v29 << 31;
  if ( (v29 & 1) != 0 )
    goto LABEL_4;
  return result;
}



// phy_ctx_get_by_index @ 0x116680
int phy_ctx_get_by_index(int a1, char a2) {
  int v2; // r6
  int v4; // r5

  v2 = dword_1166B0;
  v4 = 696 * *(volatile uint8_t *)(a1 + 29);
  *(volatile uint8_t *)(a1 + 27) = a2;
  *(volatile uint8_t *)(a1 + 97) = 1;
  co_list_push_back(v4 + 572 + v2, (volatile uint32_t *)a1);
  return tx_handle_pending_flag(a1, v2 + v4);
}


// tx_queue_set_new_head @ 0x1166b4
int tx_queue_set_new_head(int a1, int a2) {
  volatile uint32_t *v3; // r3
  volatile unsigned int v4; // r2
  volatile int *v5; // r0
  volatile unsigned int *v6; // r3
  unsigned int v7; // r2
  int v8; // r4
  volatile uint32_t *v9; // r3
  volatile int *v10; // r1
  int result; // r0
  int v12; // r2
  int v13; // r4
  volatile uint32_t *v14; // r2
  volatile uint32_t *v15; // r3
  volatile uint32_t *v16; // r3
  volatile uint32_t *v17; // r3
  volatile uint32_t *v18; // r3
  volatile uint32_t *v19; // r3
  volatile unsigned int v20; // r5
  unsigned int v21; // r5
  int v22; // r3
  volatile unsigned int v23; // r5
  unsigned int v24; // r5
  int v25; // r3
  volatile unsigned int v26; // r5
  unsigned int v27; // r5
  int v28; // r3
  volatile unsigned int v29; // r5
  unsigned int v30; // r5
  int v31; // r3
  volatile unsigned int v32; // r5
  unsigned int v33; // r5
  int v34; // r3

  switch ( a2 )
  {
    case 0:
      if ( ((*(volatile uint32_t *)off_116940 >> 4) & 3) != 2 )
        goto LABEL_12;
      v29 = REG_4032_0120;
      v30 = v29 + 2;
      do
      {
        if ( ((*(volatile uint32_t *)off_116940 >> 4) & 3) != 2 )
          break;
        v31 = REG_4032_0120 - v30;
      }
      while ( v31 < 0 );
      if ( **(volatile int16_t **)off_116978 >= 0 || ((*(volatile uint32_t *)off_116940 >> 4) & 3) != 2 )
      {
LABEL_12:
        v15 = (void *)(uintptr_t)(off_116948);
        *(volatile uint32_t *)off_116968 = a1;
        *v15 = 512;
        goto LABEL_4;
      }
      result = bad_func_0x12f408((int)aNxmacTxAc0Stat, (int)aTxlCntrlNewhea, 1919);
      break;
    case 1:
      if ( ((*(volatile uint32_t *)off_116940 >> 8) & 3) != 2 )
        goto LABEL_14;
      v26 = REG_4032_0120;
      v27 = v26 + 2;
      do
      {
        if ( ((*(volatile uint32_t *)off_116940 >> 8) & 3) != 2 )
          break;
        v28 = REG_4032_0120 - v27;
      }
      while ( v28 < 0 );
      if ( **(volatile int16_t **)off_116978 >= 0 || ((*(volatile uint32_t *)off_116940 >> 8) & 3) != 2 )
      {
LABEL_14:
        v16 = (void *)(uintptr_t)(off_116948);
        *(volatile uint32_t *)off_11696C = a1;
        *v16 = 1024;
        goto LABEL_4;
      }
      result = bad_func_0x12f408((int)aNxmacTxAc1Stat, (int)aTxlCntrlNewhea, 1907);
      break;
    case 2:
      if ( ((*(volatile uint32_t *)off_116940 >> 12) & 3) != 2 )
        goto LABEL_16;
      v23 = REG_4032_0120;
      v24 = v23 + 2;
      do
      {
        if ( ((*(volatile uint32_t *)off_116940 >> 12) & 3) != 2 )
          break;
        v25 = REG_4032_0120 - v24;
      }
      while ( v25 < 0 );
      if ( **(volatile int16_t **)off_116978 >= 0 || ((*(volatile uint32_t *)off_116940 >> 12) & 3) != 2 )
      {
LABEL_16:
        v17 = (void *)(uintptr_t)(off_116948);
        *(volatile uint32_t *)off_116970 = a1;
        *v17 = 2048;
        goto LABEL_4;
      }
      result = bad_func_0x12f408((int)aNxmacTxAc2Stat, (int)aTxlCntrlNewhea, 1895);
      break;
    case 3:
      if ( (HIWORD(*(volatile uint32_t *)off_116940) & 3) != 2 )
        goto LABEL_18;
      v20 = REG_4032_0120;
      v21 = v20 + 2;
      do
      {
        if ( (HIWORD(*(volatile uint32_t *)off_116940) & 3) != 2 )
          break;
        v22 = REG_4032_0120 - v21;
      }
      while ( v22 < 0 );
      if ( **(volatile int16_t **)off_116978 >= 0 || (HIWORD(*(volatile uint32_t *)off_116940) & 3) != 2 )
      {
LABEL_18:
        v18 = (void *)(uintptr_t)(off_116948);
        *(volatile uint32_t *)off_116974 = a1;
        *v18 = 4096;
        goto LABEL_4;
      }
      result = bad_func_0x12f408((int)aNxmacTxAc3Stat, (int)aTxlCntrlNewhea, 1883);
      break;
    case 4:
      if ( **(volatile int16_t **)off_116978 >= 0 || (*(volatile uint32_t *)off_116940 & 3) != 2 )
      {
        v19 = (void *)(uintptr_t)(off_116948);
        *(volatile uint32_t *)off_11697C = a1;
        *v19 = 256;
        goto LABEL_4;
      }
      result = bad_func_0x12f408((int)aNxmacTxBcnStat, (int)aTxlCntrlNewhea, 1871);
      break;
    case 5:
      if ( (HIBYTE(*(volatile uint32_t *)off_116940) & 3) != 2 )
        goto LABEL_3;
      v32 = REG_4032_0120;
      v33 = v32 + 2;
      do
      {
        if ( (HIBYTE(*(volatile uint32_t *)off_116940) & 3) != 2 )
          break;
        v34 = REG_4032_0120 - v33;
      }
      while ( v34 < 0 );
      if ( **(volatile int16_t **)off_116978 >= 0 || (HIBYTE(*(volatile uint32_t *)off_116940) & 3) != 2 )
      {
LABEL_3:
        v3 = (void *)(uintptr_t)(off_116948);
        *(volatile uint32_t *)off_116944 = a1;
        *v3 = 0x4000;
        goto LABEL_4;
      }
      result = bad_func_0x12f408((int)aNxmacTxHiState, (int)aTxlCntrlNewhea, 1931);
      break;
    default:
      if ( **(volatile int16_t **)off_116978 < 0 )
        mmio_clear_register(off_11699C, (int)aTxlCntrlNewhea, 1937);
LABEL_4:
      v4 = REG_4032_0120;
      v5 = (volatile int *)off_116958;
      v6 = (volatile unsigned int *)(4 * (dword_116954 + a2));
      v7 = v4 + *(volatile uint32_t *)(dword_11694C + 4 * a2);
      v8 = 1 << a2;
      *v6 = v7;
      *v5 = v8;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(volatile uint32_t *)off_11695C = 1;
      }
      v9 = (void *)(uintptr_t)(off_116960);
      v10 = (volatile int *)off_116964;
      result = *(volatile uint32_t *)off_116960;
      v12 = *(volatile uint32_t *)off_116960 + 1;
      v13 = v8 | *(volatile uint32_t *)off_116964;
      *(volatile uint32_t *)off_116960 = v12;
      *v10 = v13;
      if ( v12 )
      {
        v14 = (void *)(uintptr_t)(off_11695C);
        *v9 = result;
        if ( !result )
        {
          if ( *v14 )
            __enable_irq();
        }
      }
      break;
  }
  return result;
}


// radio_channel_validate @ 0x1169a0
int radio_channel_validate(int result, int a2, int a3) {
  int v4; // r6
  volatile int *v6; // r5
  int v7; // r2
  void *v8; // r8
  int v9; // r3
  int v10; // r2
  int v11; // r2

  v4 = result;
  if ( a3 == 5 )
    v6 = (volatile int *)dword_116AAC;
  else
    v6 = (volatile int *)(dword_116A98 + 84 * a3);
  v7 = *v6;
  if ( **(volatile int16_t **)off_116A9C < 0 && v7 == result )
    return bad_func_0x12f408((int)aPrevHdFirstThd, (int)aTxlFrameExchan, 1972);
  if ( v7 )
  {
    v8 = (void *)(uintptr_t)(off_116AB0);
    v9 = *(volatile uint8_t *)(*(volatile uint32_t *)off_116AB0 + 1);
    if ( *(volatile uint8_t *)(*(volatile uint32_t *)off_116AB0 + 1) || !v6[2] )
      *(volatile uint32_t *)(v7 + 4) = result;
    else
      *(volatile uint32_t *)(v6[1] + 4) = result;
    if ( a3 == 5
      || !*((volatile uint8_t *)off_116AA0 + 28 * a3 + 46)
      && ((v10 = *((volatile uint32_t *)off_116AA0 + 52), result = v10 << 31, (v10 & 1) == 0)
       || *((volatile uint8_t *)off_116AA0 + 190) != a3) )
    {
      result = dispatch_config_command(a3);
      v9 = *(volatile uint8_t *)(*(volatile uint32_t *)v8 + 1);
    }
  }
  else if ( a3 != 5
         && (*((volatile uint8_t *)off_116AA0 + 28 * a3 + 46)
          || (result = *((volatile uint8_t *)off_116AA0 + 190), (*((volatile uint32_t *)off_116AA0 + 52) & 1) != 0) && a3 == result) )
  {
    v11 = *(volatile uint32_t *)off_116AB0;
    *((volatile uint32_t *)off_116AA0 + 7 * a3 + 9) = v4;
    v9 = *(volatile uint8_t *)(v11 + 1);
  }
  else
  {
    result = tx_queue_set_new_head(v4, a3);
    v9 = *(volatile uint8_t *)(*(volatile uint32_t *)off_116AB0 + 1);
  }
  if ( !v9 )
  {
    if ( (*(volatile uint32_t *)(a2 + 56) & 0x200000) != 0 )
    {
      v6[1] = v4;
      v6[2] = 1;
    }
    else
    {
      v6[1] = 0;
      v6[2] = 0;
    }
  }
  *(volatile uint32_t *)(dword_116A98 + 84 * a3) = a2;
  return result;
}


