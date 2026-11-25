// llm_adv_pdu_build @ 0x11538c
int llm_adv_pdu_build(int result) {
  uint64_t v1; // kr00_8
  int v2; // r2
  int v3; // r3
  int v4; // r2
  unsigned int v5; // r3
  int v6; // r3

  v1 = *(volatile uint64_t *)(result + 28);
  v2 = *(volatile uint32_t *)(HIDWORD(v1) + 24);
  v3 = *(volatile uint32_t *)(v1 + 96);
  *(volatile uint32_t *)(HIDWORD(v1) + 60) = v3;
  *(volatile uint32_t *)(HIDWORD(v1) + 44) = v1 + 44;
  if ( !v2 )
  {
    v4 = *(volatile uint32_t *)(HIDWORD(v1) + 20);
    if ( **(volatile int16_t **)off_1153E8 < 0 && !v4 )
    {
      result = flash_ctrl_init(dword_1153F0, dword_1153EC, 525);
      v4 = *(volatile uint32_t *)(HIDWORD(v1) + 20);
      v3 = *(volatile uint32_t *)(HIDWORD(v1) + 60);
    }
    v2 = *(volatile uint32_t *)(v4 + 8);
  }
  v5 = v3 & 0xFFFFF9FF;
  *(volatile uint32_t *)(HIDWORD(v1) + 60) = v5;
  if ( (*(volatile uint8_t *)(v2 + 4) & 1) == 0 )
    *(volatile uint32_t *)(HIDWORD(v1) + 60) = v5 | 0x200;
  v6 = *(volatile uint32_t *)(v1 + 48);
  *(volatile uint32_t *)(HIDWORD(v1) + 40) = *(volatile uint32_t *)(v1 + 100);
  *(volatile uint32_t *)(v1 + 48) = v6 | 2;
  return result;
}



// adv_pdu_type_handler @ 0x1153f4
volatile int * adv_pdu_type_handler(int a1, int a2) {
  volatile uint32_t *v3; // r3
  volatile unsigned int v4; // r2
  volatile int *v5; // r0
  volatile unsigned int *v6; // r3
  unsigned int v7; // r2
  int v8; // r4
  volatile uint32_t *v9; // r3
  volatile int *result; // r0
  int v11; // r2
  int v12; // r1
  int v13; // r4
  volatile uint32_t *v14; // r1
  volatile uint32_t *v15; // r3
  volatile uint32_t *v16; // r3
  volatile uint32_t *v17; // r3
  volatile uint32_t *v18; // r3
  volatile unsigned int v19; // r5
  unsigned int v20; // r5
  int v21; // r3
  volatile unsigned int v22; // r5
  unsigned int v23; // r5
  int v24; // r3
  volatile unsigned int v25; // r5
  unsigned int v26; // r5
  int v27; // r3
  volatile unsigned int v28; // r5
  unsigned int v29; // r5
  int v30; // r3
  volatile unsigned int v31; // r5
  unsigned int v32; // r5
  int v33; // r3

  switch ( a2 )
  {
    case 0:
      if ( ((*(volatile uint32_t *)off_115648 >> 4) & 3) != 2 )
        goto LABEL_12;
      v22 = REG_4032_0120;
      v23 = v22 + 2;
      do
      {
        if ( ((*(volatile uint32_t *)off_115648 >> 4) & 3) != 2 )
          break;
        v24 = REG_4032_0120 - v23;
      }
      while ( v24 < 0 );
      if ( **(volatile int16_t **)off_115680 >= 0 || ((*(volatile uint32_t *)off_115648 >> 4) & 3) != 2 )
      {
LABEL_12:
        v15 = (void *)(uintptr_t)(off_115650);
        *(volatile uint32_t *)off_115670 = a1;
        *v15 = 512;
        goto LABEL_4;
      }
      result = (volatile int *)ke_int_lock_1((int)aNxmacTxAc0Stat, (int)aTxlCntrlNewhea, 1919);
      break;
    case 1:
      if ( ((*(volatile uint32_t *)off_115648 >> 8) & 3) != 2 )
        goto LABEL_16;
      v25 = REG_4032_0120;
      v26 = v25 + 2;
      do
      {
        if ( ((*(volatile uint32_t *)off_115648 >> 8) & 3) != 2 )
          break;
        v27 = REG_4032_0120 - v26;
      }
      while ( v27 < 0 );
      if ( **(volatile int16_t **)off_115680 >= 0 || ((*(volatile uint32_t *)off_115648 >> 8) & 3) != 2 )
      {
LABEL_16:
        v17 = (void *)(uintptr_t)(off_115650);
        *(volatile uint32_t *)off_115678 = a1;
        *v17 = 1024;
        goto LABEL_4;
      }
      result = (volatile int *)ke_int_lock_1((int)aNxmacTxAc1Stat, (int)aTxlCntrlNewhea, 1907);
      break;
    case 2:
      if ( ((*(volatile uint32_t *)off_115648 >> 12) & 3) != 2 )
        goto LABEL_14;
      v28 = REG_4032_0120;
      v29 = v28 + 2;
      do
      {
        if ( ((*(volatile uint32_t *)off_115648 >> 12) & 3) != 2 )
          break;
        v30 = REG_4032_0120 - v29;
      }
      while ( v30 < 0 );
      if ( **(volatile int16_t **)off_115680 >= 0 || ((*(volatile uint32_t *)off_115648 >> 12) & 3) != 2 )
      {
LABEL_14:
        v16 = (void *)(uintptr_t)(off_115650);
        *(volatile uint32_t *)off_115674 = a1;
        *v16 = 2048;
        goto LABEL_4;
      }
      result = (volatile int *)ke_int_lock_1((int)aNxmacTxAc2Stat, (int)aTxlCntrlNewhea, 1895);
      break;
    case 3:
      if ( (HIWORD(*(volatile uint32_t *)off_115648) & 3) != 2 )
        goto LABEL_18;
      v31 = REG_4032_0120;
      v32 = v31 + 2;
      do
      {
        if ( (HIWORD(*(volatile uint32_t *)off_115648) & 3) != 2 )
          break;
        v33 = REG_4032_0120 - v32;
      }
      while ( v33 < 0 );
      if ( **(volatile int16_t **)off_115680 >= 0 || (HIWORD(*(volatile uint32_t *)off_115648) & 3) != 2 )
      {
LABEL_18:
        v18 = (void *)(uintptr_t)(off_115650);
        *(volatile uint32_t *)off_11567C = a1;
        *v18 = 4096;
        goto LABEL_4;
      }
      result = (volatile int *)ke_int_lock_1((int)aNxmacTxAc3Stat, (int)aTxlCntrlNewhea, 1883);
      break;
    case 5:
      if ( (HIBYTE(*(volatile uint32_t *)off_115648) & 3) != 2 )
        goto LABEL_3;
      v19 = REG_4032_0120;
      v20 = v19 + 2;
      do
      {
        if ( (HIBYTE(*(volatile uint32_t *)off_115648) & 3) != 2 )
          break;
        v21 = REG_4032_0120 - v20;
      }
      while ( v21 < 0 );
      if ( **(volatile int16_t **)off_115680 >= 0 || (HIBYTE(*(volatile uint32_t *)off_115648) & 3) != 2 )
      {
LABEL_3:
        v3 = (void *)(uintptr_t)(off_115650);
        *(volatile uint32_t *)off_11564C = a1;
        *v3 = 0x4000;
        goto LABEL_4;
      }
      result = (volatile int *)ke_int_lock_1((int)aNxmacTxHiState, (int)aTxlCntrlNewhea, 1931);
      break;
    default:
      if ( **(volatile int16_t **)off_115680 < 0 )
        flash_ctrl_init(off_115688, (int)aTxlCntrlNewhea, 1937);
LABEL_4:
      v4 = REG_4032_0120;
      v5 = (volatile int *)off_115660;
      v6 = (volatile unsigned int *)(4 * (dword_11565C + a2));
      v7 = v4 + *(volatile uint32_t *)(dword_115654 + 4 * a2);
      v8 = 1 << a2;
      *v6 = v7;
      *v5 = v8;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(volatile uint32_t *)off_115664 = 1;
      }
      v9 = (void *)(uintptr_t)(off_115668);
      result = (volatile int *)off_11566C;
      v11 = *(volatile uint32_t *)off_115668;
      v12 = *(volatile uint32_t *)off_115668 + 1;
      v13 = v8 | *(volatile uint32_t *)off_11566C;
      *(volatile uint32_t *)off_115668 = v12;
      *result = v13;
      if ( v12 )
      {
        v14 = (void *)(uintptr_t)(off_115664);
        *v9 = v11;
        if ( !v11 )
        {
          if ( *v14 )
            __enable_irq();
        }
      }
      break;
  }
  return result;
}


// pdu_type_init @ 0x1156a0
int pdu_type_init(int a1, int a2, int a3, int a4) {
  volatile int *v5; // r5
  int v6; // r3
  void *v9; // r8
  int result; // r0

  if ( a3 != 5 )
    a4 = 7 * a3;
  if ( a3 == 5 )
    v5 = (volatile int *)dword_115744;
  else
    v5 = (volatile int *)dword_115740;
  if ( a3 != 5 )
    v5 += a4;
  v6 = *v5;
  if ( **(volatile int16_t **)off_11573C < 0 && v6 == a1 )
    return ke_int_lock_1((int)aPrevHdFirstThd, (int)aTxlFrameExchan, 1972);
  if ( v6 )
  {
    v9 = (void *)(uintptr_t)(off_115750);
    if ( *(volatile uint8_t *)(*(volatile uint32_t *)off_115750 + 1) || !v5[2] )
      *(volatile uint32_t *)(v6 + 4) = a1;
    else
      *(volatile uint32_t *)(v5[1] + 4) = a1;
    result = radio_pdu_type_cfg(a3);
  }
  else
  {
    result = (int)adv_pdu_type_handler(a1, a3);
    v9 = (void *)(uintptr_t)(off_115750);
  }
  if ( !*(volatile uint8_t *)(*(volatile uint32_t *)v9 + 1) )
  {
    if ( (*(volatile uint32_t *)(a2 + 56) & 0x200000) != 0 )
    {
      v5[1] = a1;
      v5[2] = 1;
    }
    else
    {
      v5[1] = 0;
      v5[2] = 0;
    }
  }
  *(volatile uint32_t *)(dword_115740 + 28 * a3) = a2;
  return result;
}


