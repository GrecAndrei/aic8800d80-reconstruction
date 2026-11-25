// handle_radio_event @ 0x10d2d4
int handle_radio_event(int a1, int a2, int a3) {
  volatile int *v6; // r1
  int result; // r0
  int v8; // r12
  int v9; // lr
  int v10; // r9
  int v11; // r3
  volatile int *v12; // r3
  int v13; // r3

  if ( **(volatile int16_t **)off_10D450 < 0 && a3 > 13 )
    irq_disable_mmio_write(dword_10D460, dword_10D45C, 69);
  *(volatile uint32_t *)(a2 + 32) = 0;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_10D454 = 1;
  }
  v6 = (volatile int *)off_10D458;
  result = *(volatile uint32_t *)off_10D458;
  v8 = *(volatile uint32_t *)off_10D458 + 1;
  ((volatile uint32_t *)(uintptr_t)0x40021000u)[16 * a3] |= 1u;
  *v6 = v8;
while ( (((volatile uint32_t *)(uintptr_t)0x40021000u)[16 * a3] & 0x10000) == 0 ) ;
  v9 = dword_10D464;
  v10 = *(volatile uint32_t *)(dword_10D464 + 4 * a3);
if ( v10 && (((volatile uint32_t *)(uintptr_t)0x40021000u)[16 * a3 + 3] & 0x800) == 0 ) { if ( (((volatile uint32_t *)(uintptr_t)0x40021000u)[16 * a3 + 6] & 0x80000) != 0 ) { ((volatile uint32_t *)(uintptr_t)0x40021000u)[16 * a3 + 6] &= ~0x80000u;
      ((volatile uint32_t *)(uintptr_t)0x40021000u)[16 * a3 + 12] = a1;
    }
    *(volatile uint32_t *)(v10 + 8) &= ~0x80000u;
    *(volatile uint32_t *)(v10 + 32) = a1;
  }
  else
  {
    ((volatile uint32_t *)(uintptr_t)0x40021000u)[16 * a3 + 2] = dword_10D468;
    ((volatile uint32_t *)(uintptr_t)0x40021000u)[16 * a3 + 3] = 20;
    ((volatile uint32_t *)(uintptr_t)0x40021000u)[16 * a3 + 4] = 0;
    ((volatile uint32_t *)(uintptr_t)0x40021000u)[16 * a3 + 5] = 0;
    ((volatile uint32_t *)(uintptr_t)0x40021000u)[16 * a3 + 6] = 0;
    ((volatile uint32_t *)(uintptr_t)0x40021000u)[16 * a3 + 7] = 0;
    ((volatile uint32_t *)(uintptr_t)0x40021000u)[16 * a3 + 8] = 0;
    ((volatile uint32_t *)(uintptr_t)0x40021000u)[16 * a3 + 9] = 0;
    ((volatile uint32_t *)(uintptr_t)0x40021000u)[16 * a3 + 10] = 0;
    ((volatile uint32_t *)(uintptr_t)0x40021000u)[16 * a3 + 11] = 0;
    ((volatile uint32_t *)(uintptr_t)0x40021000u)[16 * a3 + 13] = 0;
    ((volatile uint32_t *)(uintptr_t)0x40021000u)[16 * a3 + 14] = 0;
    ((volatile uint32_t *)(uintptr_t)0x40021000u)[16 * a3 + 15] = 0;
    ((volatile uint32_t *)(uintptr_t)0x40021000u)[16 * a3 + 12] = a1;
    *(volatile uint32_t *)(a2 + 8) |= 0x80000u;
    ((volatile uint32_t *)(uintptr_t)0x40021000u)[16 * a3 + 2] |= 1u;
    ((volatile uint32_t *)(uintptr_t)0x40021000u)[16 * a3 + 1] |= 1u;
  }
  v11 = ((volatile uint32_t *)(uintptr_t)0x40021000u)[16 * a3];
  *(volatile uint32_t *)(v9 + 4 * a3) = a2;
  ((volatile uint32_t *)(uintptr_t)0x40021000u)[16 * a3] = v11 & 0xFFFFFFFE;
  if ( v8 )
  {
    v12 = (volatile int *)off_10D454;
    *v6 = result;
    v13 = *v12;
    if ( !result )
    {
      if ( v13 )
        __enable_irq();
    }
  }
  return result;
}



// handle_rf_status @ 0x10d46c
int handle_rf_status() {
  int v0; // r3
  int result; // r0

  v0 = *((volatile uint32_t *)off_10D490 + 3);
  if ( (v0 & 0x8000) != 0 )
    *((volatile uint32_t *)off_10D490 + 2) = 0x800000;
  if ( (v0 & 0x400) != 0 )
  {
    *((volatile uint32_t *)off_10D490 + 2) = 0x40000;
    return irq_disable_global_2(0x20000000);
  }
  return result;
}



// configure_radio @ 0x10d494
int configure_radio() {
  volatile unsigned int *v0; // r2
  unsigned int v1; // r3
  int result; // r0
  volatile uint32_t *v3; // r3

  v0 = (volatile unsigned int *)off_10D4D8;
  v1 = *(volatile uint32_t *)off_10D4D8;
  if ( (*(volatile uint32_t *)off_10D4D8 & 1) == 0 )
  {
    v1 = v1 & 0xFFFFFCFE | 0x101;
    result = 17;
    *((volatile uint32_t *)off_10D4D8 + 4) = 0;
    v0[5] = 0;
    v0[1] = 17;
    *v0 = v1;
  }
  if ( (v1 & 0x4000) == 0 )
    *(volatile uint32_t *)off_10D4D8 = v1 | 0x4040;
  v3 = (void *)(uintptr_t)(off_10D4E0);
  *(volatile uint32_t *)(*((volatile uint32_t *)off_10D4DC + 2) + 148) = dword_10D4E4;
  *v3 = 0x200000;
  return result;
}



// enable_irq @ 0x10d4e8
void enable_irq() {
  volatile uint32_t *v0; // r3

  v0 = (void *)(uintptr_t)(off_10D500);
  *(volatile uint32_t *)(*((volatile uint32_t *)off_10D4FC + 2) + 148) = dword_10D504;
  *v0 = 0x200000;
}



// kernel_schedule_check @ 0x10d508
void kernel_schedule_check() {
  int v0; // r3
  volatile uint32_t *v1; // r5
  volatile uint32_t *v2; // r0
  volatile uint32_t *v3; // r1
  volatile uint32_t *v4; // r4
  volatile uint32_t *v5; // r0
  unsigned int v6; // r3
  unsigned int v7; // r2
  unsigned int v8; // r3
  int v9; // r7
  int v10; // r0
  int v11; // r3
  volatile uint32_t *v12; // r2
  volatile uint32_t *v13; // r4
  volatile int *v14; // r5
  volatile int *v15; // r6
  volatile uint32_t *v16; // r0
  volatile unsigned int *v17; // r1
  volatile uint32_t *v18; // r5
  volatile uint32_t *v19; // r2
  int v20; // r0
  volatile uint32_t *v21; // r2
  volatile uint32_t *v22; // r3
  int v23; // r0

  v0 = *((volatile uint32_t *)off_10D5F4 + 43);
  if ( v0 >= 0 )
  {
    if ( *(volatile uint32_t *)off_10D5F8 )
    {
      v21 = (void *)(uintptr_t)(off_10D620);
      v22 = (void *)(uintptr_t)(off_10D624);
      v23 = dword_10D628;
      *(volatile uint32_t *)off_10D600 = 1;
      *(volatile uint32_t *)(v21[2] + 124) = v23;
      *v22 = 0x8000;
    }
  }
  else if ( *(volatile uint32_t *)off_10D5F8 )
  {
    v1 = (void *)(uintptr_t)(off_10D600);
    v2 = (void *)(uintptr_t)(off_10D604);
    v3 = (void *)(uintptr_t)(off_10D608);
    *(volatile uint32_t *)off_10D5FC = 0;
    *v1 = 0;
    *v2 = 1;
    v4 = (void *)(uintptr_t)(off_10D60C);
    v5 = (void *)(uintptr_t)(off_10D610);
    *v3 |= 0x100u;
    *v4 = 3;
    v6 = v0 & 0x7FFFFFFF;
    if ( (v5[20] & 0x20) != 0 )
    {
      v7 = *(volatile uint32_t *)off_10D630;
      if ( v6 < *(volatile uint32_t *)off_10D630 >> 4 )
        goto LABEL_5;
    }
    else
    {
      v7 = 2 * *(volatile uint32_t *)off_10D614;
      if ( v6 < v7 >> 4 )
      {
LABEL_5:
        v8 = v7 / v6;
        v9 = (uint8_t)(v8 >> 4);
        v10 = ((v8 >> 1) & 7) + 16 * ((v8 & 0xF) - ((v8 >> 1) & 7));
        v11 = (uint8_t)(v8 >> 12);
LABEL_6:
        v12 = (void *)(uintptr_t)(off_10D60C);
        v13 = (void *)(uintptr_t)(off_10D600);
        v14 = (volatile int *)off_10D618;
        v15 = (volatile int *)off_10D61C;
        *(volatile uint32_t *)off_10D60C |= 0x80u;
        *v15 = v9;
        *v13 = v11;
        *v14 = v10;
        v16 = (void *)(uintptr_t)(off_10D5FC);
        v17 = (volatile unsigned int *)off_10D604;
        v18 = (void *)(uintptr_t)(off_10D620);
        *v12 &= ~0x80u;
        *v16 = 7;
        v19 = (void *)(uintptr_t)(off_10D624);
        v20 = dword_10D628;
        *v17 = *v17 & 0xFFFFFE00 | 1;
        *v13 = 1;
        *(volatile uint32_t *)(v18[2] + 124) = v20;
        *v19 = 0x8000;
        goto LABEL_7;
      }
    }
    v10 = 0;
    v11 = 0;
    v9 = 1;
    goto LABEL_6;
  }
LABEL_7:
  *(volatile uint32_t *)off_10D62C = 1;
}



// system_ready_check @ 0x10d634
void system_ready_check() {
  if ( !*(volatile uint32_t *)off_10D640 )
    kernel_schedule_check();
}



// nvic_disable_irq15 @ 0x10d644
/* luna: Disables NVIC interrupt 15 and synchronizes the change with data and instruction barriers. */
void nvic_disable_irq15() {
  *((volatile uint32_t *)off_10D658 + 32) = 0x8000;
  __dsb(0xFu);
  __isb(0xFu);
}



// radio_tx_write_byte @ 0x10d65c
/* luna: Waits until the radio transmit register is ready, writes a byte value, and returns that value. */
int radio_tx_write_byte(int result) {
  while ( (*(volatile uint32_t *)off_10D66C & 0x80000) != 0 )
    ;
  *(volatile uint32_t *)off_10D670 = result;
  return result;
}



// radio_tx_write_string @ 0x10d674
/* luna: Writes a null-terminated byte string to the radio transmit register, polling until the transmit status bit clears before each byte, and returns a poin */
volatile uint8_t * radio_tx_write_string(volatile uint8_t *result) {
  int current_byte; // r1
  volatile uint32_t *tx_status_reg; // r2
  volatile uint32_t *tx_data_reg; // r4
  int next_byte; // t1

  current_byte = (uint8_t)*result;
  if ( *result )
  {
    tx_status_reg = (void *)(uintptr_t)(off_10D698);
    tx_data_reg = (void *)(uintptr_t)(off_10D69C);
    do
    {
      while ( (*tx_status_reg & 0x80000) != 0 )
        ;
      *tx_data_reg = current_byte;
      next_byte = (uint8_t)*++result;
      current_byte = next_byte;
    }
    while ( next_byte );
  }
  return result;
}



// radio_rx_read_byte @ 0x10d6a0
/* luna: Waits until the radio receive-ready bit is set, then returns the received byte. */
int radio_rx_read_byte() {
  while ( (*(volatile uint32_t *)off_10D6B0 & 1) == 0 )
    ;
  return (uint8_t)*(volatile uint32_t *)off_10D6B4;
}



// radio_rx_status @ 0x10d6b8
int radio_rx_status() {
  return *(volatile uint32_t *)off_10D6C4 & 1;
}



// stack_struct_init @ 0x10d6c8
int stack_struct_init(volatile uint8_t *a1, volatile unsigned int *a2) {
  volatile uint32_t *v2; // r4
  unsigned int CPSR; // r6
  signed int v4; // r0
  int v5; // r7
  signed int v6; // r5
  int v7; // r3
  volatile char *v8; // r4
  volatile uint32_t *v9; // r1
  volatile uint32_t *v10; // r0
  volatile char *v11; // r5
  int v12; // r2
  int v13; // t1
  int v15; // r3
  volatile uint8_t **v16; // r8
  volatile char *v17; // r0
  volatile uint32_t *v18; // r2
  volatile int *v19; // r4
  int v20; // r1
  int v21; // t1
  int v22; // r3
  volatile char *v23; // r8
  unsigned int v24; // r0
  volatile uint8_t *v25; // r8
  volatile uint8_t *v26; // r9
  volatile char *v27; // r0
  volatile uint32_t *v28; // r2
  volatile int *v29; // r12
  int v30; // r1
  int v31; // t1
  volatile uint16_t *v32; // r10
  int v33; // r11
  volatile char *v34; // r0
  volatile uint32_t *v35; // r2
  volatile int *v36; // r5
  int v37; // r1
  int v38; // t1
  volatile char **v39; // r3
  int v40; // r0
  volatile char *v41; // r8
  int v42; // r3
  volatile uint8_t *v43; // r1
  unsigned int v44; // r2
  uint16_t v45; // r0
  volatile uint32_t *v46; // r5
  int v47; // r2
  volatile int *v48; // r5
  int v49; // r0
  int v50; // r3
  int v51; // r2
  volatile char *v52; // r0
  volatile uint32_t *v53; // r2
  volatile int *v54; // r4
  int v55; // r1
  int v56; // t1
  volatile char *v57; // r0
  volatile uint32_t *v58; // r2
  volatile int *v59; // r4
  int v60; // r1
  int v61; // t1
  volatile char *v62; // r0
  volatile uint32_t *v63; // r2
  volatile int *v64; // r12
  int v65; // r1
  int v66; // t1
  int v67; // r2
  uint64_t v68; // r0
  int ( *v69)(uint32_t); // r2
  int v70; // r0
  volatile uint16_t *v71; // r2
  int v72; // r2
  uint16_t v73; // r5
  volatile char *v74; // r1
  volatile uint32_t *v75; // r2
  volatile int *v76; // r0
  int v77; // t1
  struct __attribute__((packed)) { volatile int *v78; // [sp+Ch] [bp-108h]
  char a1a[260]; // [sp+10h] [bp-104h] BYREF
  } _frame;
  CPSR = __get_CPSR();
  v4 = rx_process_packet_2(_frame.a1a, 256, 0, a1, a2);
  v5 = v4;
  if ( v4 <= 0 )
    return v5;
  v6 = v4;
  if ( *(volatile uint32_t *)off_10D994 )
  {
    if ( CPSR )
      goto LABEL_5;
  }
  else
  {
    kernel_schedule_check();
    if ( CPSR )
      goto LABEL_5;
  }
  while ( !*(volatile uint32_t *)off_10D998 )
    ;
LABEL_5:
  if ( !*(volatile uint32_t *)off_10D99C )
  {
    while ( (*(volatile uint32_t *)off_10D9A0 & 0x80000) != 0 )
      ;
    *(volatile uint32_t *)off_10D9A4 = 95;
  }
  v7 = HIWORD(((volatile uint32_t *)(uintptr_t)off_10D9A8)[44]) & 0x4000;
  if ( (((volatile uint32_t *)(uintptr_t)off_10D9A8)[44] & 0x40000000) == 0 )
  {
    v8 = _frame.a1a;
    v9 = (void *)(uintptr_t)(off_10D9A0);
    v10 = (void *)(uintptr_t)(off_10D9A4);
    v11 = &_frame.a1a[v6];
    do
    {
      v13 = (uint8_t)*v8++;
      v12 = v13;
      if ( v13 == 10 && v7 != 13 )
      {
        while ( (*v9 & 0x80000) != 0 )
          ;
        *v10 = 13;
        v12 = (uint8_t)*(v8 - 1);
      }
      while ( (*v9 & 0x80000) != 0 )
        ;
      *v10 = v12;
      v7 = (uint8_t)*(v8 - 1);
    }
    while ( v8 != v11 );
    goto LABEL_13;
  }
  v15 = **(volatile uint8_t **)off_10D9AC;
  if ( v15 == 1 )
  {
    v22 = **(volatile uint8_t **)off_10D9B4;
    if ( v22 != 3 )
    {
      if ( v6 >= 124 )
        v6 = (v6 & ~0xFFFFu) | ((uint16_t)(124) & 0xFFFFu);
      kmalloc(19, _frame.a1a, (uint16_t)v6, v22);
    }
    goto LABEL_13;
  }
  if ( v15 != 2 )
    goto LABEL_13;
  v16 = (volatile uint8_t **)off_10D9B4;
  if ( **(volatile uint8_t **)off_10D9B4 == 3 )
  {
LABEL_19:
    v17 = aNoActive;
    v18 = (void *)(uintptr_t)(off_10D9A0);
    v19 = (volatile int *)off_10D9A4;
    v20 = 110;
    do
    {
      while ( (*v18 & 0x80000) != 0 )
        ;
      *v19 = v20;
      v21 = (uint8_t)*++v17;
      v20 = v21;
    }
    while ( v21 );
    goto LABEL_13;
  }
  if ( (unsigned int)list_length((volatile uint32_t **)dword_10D9B8) <= 4 )
  {
    if ( **(volatile uint8_t **)off_10D9AC == 2 )
    {
      if ( **v16 != 3 )
      {
        if ( (unsigned int)list_length((volatile uint32_t **)dword_10D9B8) > 4 )
        {
          v57 = aOtherErr;
          v58 = (void *)(uintptr_t)(off_10D9A0);
          v59 = (volatile int *)off_10D9A4;
          v60 = 111;
          do
          {
            while ( (*v58 & 0x80000) != 0 )
              ;
            *v59 = v60;
            v61 = (uint8_t)*++v57;
            v60 = v61;
          }
          while ( v61 );
        }
        else
        {
          v52 = aFree5;
          v53 = (void *)(uintptr_t)(off_10D9A0);
          v54 = (volatile int *)off_10D9A4;
          v55 = 102;
          do
          {
            while ( (*v53 & 0x80000) != 0 )
              ;
            *v54 = v55;
            v56 = (uint8_t)*++v52;
            v55 = v56;
          }
          while ( v56 );
        }
        goto LABEL_13;
      }
      goto LABEL_19;
    }
LABEL_13:
    if ( !CPSR )
      *(volatile uint32_t *)off_10D998 = 1;
    return v5;
  }
  v23 = _frame.a1a;
  while ( 1 )
  {
    v24 = (unsigned int)v23++;
    if ( !memcmp(v24, (unsigned int)aCm4FaultHandle, 0x14u) )
      break;
    if ( &_frame.a1a[v6] == v23 )
    {
      v25 = (void *)(uintptr_t)(off_10D9EC);
      goto LABEL_37;
    }
  }
  v62 = aFoundPanic;
  v63 = (void *)(uintptr_t)(off_10DAC4);
  v64 = (volatile int *)off_10DADC;
  v65 = 70;
  do
  {
    while ( (*v63 & 0x80000) != 0 )
      ;
    *v64 = v65;
    v66 = (uint8_t)*++v62;
    v65 = v66;
  }
  while ( v66 );
  v25 = (void *)(uintptr_t)(off_10DAE0);
  v67 = *(volatile uint32_t *)off_10DAC8;
  _frame.v78 = (volatile int *)off_10DACC;
  v68 = *(volatile uint64_t *)(v67 + 4);
  v69 = *(int ( **)(uint32_t))(HIDWORD(v68) + 16);
  *(volatile uint8_t *)off_10DAE0 = 1;
  v70 = v69(v68);
  v71 = (void *)(uintptr_t)(off_10DAD0);
  *_frame.v78 = v70;
  *v71 = 4;
LABEL_37:
  if ( *v25 )
  {
    v26 = (void *)(uintptr_t)(off_10D9F0);
    if ( !memcmp((unsigned int)_frame.a1a, (unsigned int)aPanic, 5u) )
    {
      v27 = aPanicEnd;
      v28 = (void *)(uintptr_t)(off_10D9A0);
      v29 = (volatile int *)off_10D9A4;
      *v26 = 1;
      v30 = 80;
      do
      {
        while ( (*v28 & 0x80000) != 0 )
          ;
        *v29 = v30;
        v31 = (uint8_t)*++v27;
        v30 = v31;
      }
      while ( v31 );
    }
    v32 = (volatile uint16_t *)off_10D9F4;
    v33 = *(volatile uint16_t *)off_10D9F4;
    if ( v33 + v6 <= 1720 )
    {
      _frame.v78 = (volatile int *)off_10DACC;
      memcpy((volatile char *)(*(volatile uint32_t *)off_10DACC + v33), _frame.a1a, v6);
      v72 = (uint8_t)*v26;
      v39 = (volatile char **)_frame.v78;
      v73 = v6 + *v32;
      v33 = v73;
      *v32 = v73;
      if ( !v72 )
        return v5;
    }
    else
    {
      v34 = aBufFull;
      v35 = (void *)(uintptr_t)(off_10D9A0);
      v36 = (volatile int *)off_10D9A4;
      v37 = 66;
      do
      {
        while ( (*v35 & 0x80000) != 0 )
          ;
        *v36 = v37;
        v38 = (uint8_t)*++v34;
        v37 = v38;
      }
      while ( v38 );
      v39 = (volatile char **)off_10D9C8;
    }
    v40 = dword_10D9B8;
    *v25 = 0;
    *v26 = 0;
    v41 = *v39;
    *v32 = 4;
    *v39 = nullptr;
    v5 = v33;
    list_pop(v40);
    goto LABEL_48;
  }
  v2 = list_pop(dword_10DAD4);
  if ( v6 <= 122 )
    v41 = (volatile char *)util_call_void();
  else
    v41 = (volatile char *)(*(int ( **)(uint32_t))(*(volatile uint32_t *)(*(volatile uint32_t *)off_10DAC8 + 8) + 16))(*(volatile uint32_t *)(*(volatile uint32_t *)off_10DAC8 + 4));
  if ( v41 )
  {
    memcpy(v41 + 4, _frame.a1a, v6);
    v33 = (v33 & ~0xFFFFu) | ((uint16_t)(v6) & 0xFFFFu);
LABEL_48:
    *(volatile uint16_t *)v41 = v5 + 1;
    v41[2] = 19;
    v42 = 0;
    v43 = (void *)(uintptr_t)(off_10D9CC);
    v41[3] = 0;
    v41[v5 + 4] = 0;
    v44 = *((volatile uint16_t *)v43 + 4122);
    if ( v44 > 0x186 )
    {
      v44 = (v44 & ~0xFFFFu) | ((uint16_t)(0) & 0xFFFFu);
      v45 = 1;
    }
    else
    {
      v45 = v44 + 1;
      v42 = 8 * v44;
    }
    v46 = (void *)(uintptr_t)(off_10D9D0);
    *((volatile uint16_t *)v2 + 6) = v44;
    v47 = *v46 + v42;
    *(volatile uint32_t *)(v47 + 4) = (int)(uintptr_t)(v41);
    *(volatile uint16_t *)v47 = v33 + 5;
    *(volatile uint8_t *)(v47 + 3) = *(volatile uint8_t *)(v47 + 3) & 0x31 | 4;
    v46 = (void *)(uintptr_t)(((uintptr_t)(v46) & ~0xFFu) | ((uint8_t)(v43[3074] + 1) & 0xFFu));
    *((volatile uint16_t *)v43 + 4122) = v45;
    v43[3074] = (uint8_t)v46;
    v2[1] = v47;
    *((volatile uint8_t *)v2 + 14) = 1;
    *v2 = 0;
    v2[2] = v5 + 5;
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(volatile uint32_t *)off_10D9D4 = 1;
    }
    v48 = (volatile int *)off_10D9D8;
    v49 = dword_10D9DC;
    ++*(volatile uint32_t *)off_10D9D8;
    co_list_push_back(v49, v2);
    ((int (*)())rf_is_idle)();
    if ( *v48 )
    {
      v50 = *v48 - 1;
      v51 = *(volatile uint32_t *)off_10D9D4;
      *v48 = v50;
      if ( !v50 )
      {
        if ( v51 )
          __enable_irq();
      }
    }
    goto LABEL_13;
  }
  v74 = aNoTxBuffer;
  v75 = (void *)(uintptr_t)(off_10DAC4);
  v76 = (volatile int *)off_10DADC;
  v5 = 110;
  do
  {
    while ( (*v75 & 0x80000) != 0 )
      ;
    *v76 = v5;
    v77 = (uint8_t)*++v74;
    v5 = v77;
  }
  while ( v77 );
  return v5;
}


// debug_printf @ 0x10dae4
/* luna: Forwards a variadic debug-format string and its argument list to the stack formatter. */
int debug_printf(const volatile char *fmt, ...) {
  va_list varg_r1; // [sp+14h] [bp+8h] BYREF

  va_start(varg_r1, fmt);
  return stack_struct_init(fmt, (volatile unsigned int *)(*(void **)&(varg_r1)));
}


// rf_irq_pending @ 0x10db00
/* luna: Dispatches pending RF interrupts for indices 0–7, acknowledging each interrupt before invoking its registered handler. */
void rf_irq_pending() {
  volatile uint32_t *irq_registers; // r4
  unsigned int initial_pending_mask; // r3
  signed int irq_index; // r3
  int handler_table; // r6
  int callback_status; // r0
  unsigned int pending_mask; // r2
  void ( *irq_handler)(int); // r1

  irq_registers = (void *)(uintptr_t)(off_10DB5C);
  initial_pending_mask = *((volatile uint32_t *)off_10DB5C + 8);
  if ( initial_pending_mask )
  {
    irq_index = 31 - __clz(initial_pending_mask);
    if ( irq_index <= 7 )
    {
      handler_table = dword_10DB60;
      do
      {
        irq_registers[9] = 1 << irq_index;
        __isb(0xFu);
        irq_handler = *(void ( **)(int))(handler_table + 4 * irq_index);
        if ( irq_handler )
        {
          if ( ((irq_registers[4] >> irq_index) & 1) != 0 )
            callback_status = 2;
          else
            callback_status = ((irq_registers[5] >> irq_index) & 1) == 0;
          irq_handler(callback_status | (irq_index << 16));
        }
        pending_mask = irq_registers[8];
        irq_index = 31 - __clz(pending_mask);
      }
      while ( pending_mask && irq_index <= 7 );
    }
  }
}



// rf_irq_clear @ 0x10db64
int rf_irq_clear(int result) {
  volatile uint32_t *v1; // r1

  if ( result <= 7 )
  {
    v1 = (void *)(uintptr_t)(off_10DB90);
    ((volatile uint32_t *)(uintptr_t)0x40504080u)[result] &= 0xFFFFFFF0;
    result = (1 << result) | v1[1];
    v1[1] = result;
  }
  return result;
}



// rf_irq_disable @ 0x10db94
/* luna: Clears the selected RF interrupt-enable bit and returns its bit mask. */
int rf_irq_disable(char a1) {
  int result; // r0

  result = 1 << a1;
  *((volatile uint32_t *)off_10DBA8 + 2) &= ~result;
  return result;
}



// gpio_set_pin @ 0x10dbac
/* luna: Sets the bit for the specified GPIO pin in a memory-mapped register and returns the updated register value. */
int gpio_set_pin(char a1) {
  int result; // r0

  result = (1 << a1) | *((volatile uint32_t *)off_10DBBC + 2);
  *((volatile uint32_t *)off_10DBBC + 2) = result;
  return result;
}



// mmio_set_bit_1 @ 0x10dbc0
/* luna: Sets the bit at the given index in a fixed memory-mapped register and returns the updated register value. */
int mmio_set_bit_1(char a1) {
  int result; // r0

  result = (1 << a1) | *(volatile uint32_t *)off_10DBD0;
  *(volatile uint32_t *)off_10DBD0 = result;
  return result;
}



// mmio_clear_bit_1 @ 0x10dbd4
/* luna: Clears the bit at the specified index in a fixed volatile register and returns its bit mask. */
int mmio_clear_bit_1(char a1) {
  int result; // r0

  result = 1 << a1;
  *(volatile uint32_t *)off_10DBE8 &= ~result;
  return result;
}



// mmio_get_bit @ 0x10dbec
/* luna: Returns whether the bit selected by bit_index is set in a fixed volatile MMIO register. */
BOOL mmio_get_bit(char a1) {
  return ((1 << a1) & *(volatile uint32_t *)off_10DC00) != 0;
}



// make_bit_mask @ 0x10dc04
int make_bit_mask(int result, int a2, int a3) {
  int v3; // r4
  volatile uint32_t *v4; // r6
  volatile uint32_t *v5; // r3
  int v6; // r6
  volatile uint32_t *v7; // r3
  volatile uint8_t *v8; // r5
  int v9; // nf

  v3 = 1 << result;
  if ( result <= 7 )
  {
    v4 = (void *)(uintptr_t)(off_10DCB4);
    ((volatile uint32_t *)(uintptr_t)0x40504080u)[result] &= 0xFFFFFFF0;
    v4[1] |= v3;
  }
  v5 = (void *)(uintptr_t)(off_10DCB4);
  *((volatile uint32_t *)off_10DCB4 + 2) &= ~v3;
  v5[10] |= v3;
  v5[3] &= ~v3;
  v6 = ~v3;
  if ( a2 == 2 )
  {
    v5[4] |= v3;
  }
  else
  {
    v5[4] &= v6;
    if ( a2 )
      v5[5] &= v6;
    else
      v5[5] |= v3;
  }
  v7 = (void *)(uintptr_t)(off_10DCB4);
  v8 = (void *)(uintptr_t)(off_10DCB8);
  *((volatile uint32_t *)off_10DCB4 + 9) = v3;
  v7[6] |= v3;
  v7[11] |= 7 << (result & 0xFC);
  v9 = (*(volatile uint32_t *)v8 & 0x800000) != 0;
  *(volatile uint32_t *)(dword_10DCBC + 4 * result) = a3;
  if ( !v9 )
  {
    result = dword_10DCC4;
    *(volatile uint32_t *)(*((volatile uint32_t *)off_10DCC0 + 2) + 156) = dword_10DCC4;
    v8[791] = -4;
    *(volatile uint32_t *)v8 = 0x800000;
  }
  return result;
}



// ptr_add_12 @ 0x10dcc8
int ptr_add_12() {
  if ( *((volatile uint8_t *)off_10DCDC + 369) )
    return mmio_set_bit_1(2);
  else
    return mmio_clear_bit_1(2);
}



// ptr_add_12_alt @ 0x10dce0
int ptr_add_12_alt() {
  if ( *((volatile uint8_t *)off_10DCF4 + 369) )
    return mmio_set_bit_1(1);
  else
    return mmio_clear_bit_1(1);
}



// rf_table_lookup @ 0x10dcf8
int rf_table_lookup(int a1) {
  int v1; // r4
  int result; // r0
  BOOL v3; // r4
  int v4; // r5

  v1 = BYTE2(a1);
  result = debug_printf("wakeup:%d\n", BYTE2(a1));
  if ( v1 == 3 )
  {
    v3 = mmio_get_bit(3);
    if ( v3 )
    {
      v4 = 1;
    }
    else
    {
      if ( BYTE1(((volatile uint32_t *)(uintptr_t)off_10DD4C)[92]) )
        mmio_set_bit_1(2);
      else
        mmio_clear_bit_1(2);
      v4 = 2;
    }
    debug_printf("wkbt=%d\r\n", v3);
    return set_radio_mode(v4);
  }
  return result;
}


// rf_chain_enable @ 0x10dd54
int rf_chain_enable() {
  volatile uint32_t *v0; // r1
  volatile uint32_t *v1; // r3
  int result; // r0

  rf_irq_clear(1);
  gpio_set_pin(1);
  rf_irq_clear(2);
  gpio_set_pin(2);
  if ( *((volatile uint8_t *)off_10DDB4 + 369) )
  {
    mmio_set_bit_1(1);
    mmio_set_bit_1(2);
  }
  else
  {
    mmio_clear_bit_1(1);
    mmio_clear_bit_1(2);
  }
  rf_irq_disable(3);
  make_bit_mask(3, 2, dword_10DDB8);
  v0 = (void *)(uintptr_t)(off_10DDBC);
  v1 = (void *)(uintptr_t)(off_10DDC4);
  result = dword_10DDC8;
  *((volatile uint32_t *)off_10DDBC + 1) = off_10DDC0;
  v1[1] = result;
  v1[2] = 0;
  v0[2] = 0;
  return result;
}



// nullsub_1 @ 0x10ddcc
int nullsub_1(void) {
  return 0;
}


// nullsub_2 @ 0x10ddd0
int nullsub_2(void) {
  return 0;
}


// nullsub_3 @ 0x10ddd4
int nullsub_3(void) {
  return 0;
}


// rf_table_update @ 0x10ddd8
int rf_table_update(int a1) {
  int v1; // r2
  int v2; // r0
  int v3; // r1

  v1 = dword_10DE00;
  v2 = 4 * a1;
  v3 = dword_10DE00 + 192;
  do
  {
    *(volatile uint32_t *)(v1 - 12) = *(volatile uint32_t *)(v1 - 12) & 0xFFFFFFF3 | v2;
    v1 += 12;
  }
  while ( v1 != v3 );
  return uart_send_data(1, 16, 0x10u, dword_10DE04);
}



// hw_block_disable @ 0x10de08
unsigned int hw_block_disable() {
  volatile uint32_t *v0; // r0
  volatile uint32_t *v1; // r3
  int v2; // r1
  int v3; // r2
  uint64_t v4; // r0
  uint64_t v5; // r0
  uint64_t v6; // r0
  uint64_t v7; // r0

  v0 = (void *)(uintptr_t)(off_10DEA0);
  v1 = (void *)(uintptr_t)(off_10DEA4);
  v2 = dword_10DEA8;
  v3 = dword_10DEAC;
  *(volatile uint32_t *)off_10DEA4 = 0;
  v0[14] = 296;
  v1[2] = v1[2] & 0xF000FFFF | 0x2000000;
  v1[3] = v2 & v1[3] | 0xA06A000;
  v1[3] = v3 & v1[3] | 0x100230;
  v1[1] = 1;
  while ( v1[7] != 1 )
    ;
  v1[7] = 1;
  v4 = unsigned_int_to_double(v1[4]);
  v5 = ((uint64_t (*)())double_multiply)(v4, *(volatile uint64_t *)&dword_10DE88);
  v6 = ((uint64_t (*)())double_divide)(v5, *(volatile uint64_t *)&dword_10DE90);
  v7 = ((uint64_t (*)())double_compare_neg)(v6, *(volatile uint64_t *)&dword_10DE98);
  return ((int (*)(uint64_t))double_to_int)(v7);
}


// hw_block_reset @ 0x10deb0
int hw_block_reset() {
  volatile uint32_t *v0; // r3
  volatile uint32_t *v1; // r0
  int v2; // r1
  int v3; // r2
  int result; // r0

  v0 = (void *)(uintptr_t)(off_10DEF8);
  v1 = (void *)(uintptr_t)(off_10DEFC);
  v2 = dword_10DF00;
  v3 = dword_10DF04;
  *(volatile uint32_t *)off_10DEF8 = 0;
  v1[14] = 296;
  v0[2] = v0[2] & 0xF000FFFF | 0x2000000;
  result = v0[3];
  v0[3] = v2 & result | 0xA06A000;
  v0[3] = v3 & v0[3] | 0x100230;
  v0[1] = 1;
  return result;
}



// hw_poll_status @ 0x10df08
unsigned int hw_poll_status() {
  volatile uint32_t *v0; // r3
  uint64_t v1; // r0
  uint64_t v2; // r0
  uint64_t v3; // r0
  uint64_t v4; // r0

  while ( *((volatile uint32_t *)off_10DF68 + 7) != 1 )
    ;
  v0 = (void *)(uintptr_t)(off_10DF68);
  *((volatile uint32_t *)off_10DF68 + 7) = 1;
  v1 = unsigned_int_to_double(v0[4]);
  v2 = ((uint64_t (*)())double_multiply)(v1, *(volatile uint64_t *)&dword_10DF50);
  v3 = ((uint64_t (*)())double_divide)(v2, *(volatile uint64_t *)&dword_10DF58);
  v4 = ((uint64_t (*)())double_compare_neg)(v3, *(volatile uint64_t *)&dword_10DF60);
  return ((int (*)(uint64_t))double_to_int)(v4);
}


// hw_block_enable @ 0x10df70
int hw_block_enable() {
  volatile uint32_t *v0; // r5
  uint64_t v1; // r0
  uint64_t v2; // r0
  uint64_t v3; // r0
  uint64_t v4; // r0
  unsigned int v5; // r6
  volatile uint32_t *v6; // r2
  unsigned int v7; // r4
  uint64_t v8; // r0
  uint64_t v9; // r0
  uint64_t v10; // r0
  uint64_t v11; // r0
  unsigned int v12; // r0
  uint64_t v13; // r0
  uint64_t v14; // r0
  uint64_t v15; // r2
  uint64_t v16; // r4
  uint64_t v17; // r0
  uint64_t v18; // r0
  uint64_t v19; // r2
  uint64_t v20; // r0
  uint64_t v21; // r0
  uint64_t v22; // r2
  uint64_t v23; // r0
  uint64_t v24; // r0
  uint64_t v25; // r2
  uint64_t v26; // r0

  v0 = (void *)(uintptr_t)(off_10E090);
  rf_table_update(1);
  v0[1] = 1;
  while ( v0[7] != 1 )
    ;
  v0[7] = 1;
  v1 = unsigned_int_to_double(v0[4]);
  v2 = ((uint64_t (*)())double_multiply)(v1, *(volatile uint64_t *)&dword_10E070);
  v3 = ((uint64_t (*)())double_divide)(v2, *(volatile uint64_t *)&dword_10E078);
  v4 = ((uint64_t (*)())double_compare_neg)(v3, *(volatile uint64_t *)&dword_10E070);
  v5 = ((int (*)(uint64_t))double_to_int)(v4);
  rf_table_update(2);
  v6 = (void *)(uintptr_t)(off_10E090);
  v0[1] = 1;
  while ( v6[7] != 1 )
    ;
  v6[7] = 1;
  v7 = v6[4];
  rf_table_update(3);
  v8 = unsigned_int_to_double(v7);
  v9 = ((uint64_t (*)())double_multiply)(v8, *(volatile uint64_t *)&dword_10E070);
  v10 = ((uint64_t (*)())double_divide)(v9, *(volatile uint64_t *)&dword_10E078);
  v11 = ((uint64_t (*)())double_compare_neg)(v10, *(volatile uint64_t *)&dword_10E070);
  v12 = ((int (*)(uint64_t))double_to_int)(v11);
  v13 = ((uint64_t (*)())float_to_double)(v12);
  v14 = ((uint64_t (*)())double_divide)(v13, *(volatile uint64_t *)&dword_10E080);
  v15 = (v15 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_10E094) << 32);
  v15 = (v15 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v16 = ((uint64_t (*)())double_multiply)(v14, v15);
  v17 = ((uint64_t (*)())float_to_double)(v5);
  v18 = ((uint64_t (*)())double_divide)(v17, *(volatile uint64_t *)&dword_10E080);
  v19 = (v19 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_10E098) << 32);
  v19 = (v19 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v20 = ((uint64_t (*)())double_multiply)(v18, v19);
  v21 = double_add(v16, v20);
  v22 = (v22 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_10E09C) << 32);
  v22 = (v22 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v23 = ((uint64_t (*)())double_multiply)(v21, v22);
  v24 = ((uint64_t (*)())double_multiply)(v23, *(volatile uint64_t *)&dword_10E088);
  v25 = (v25 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_10E0A0) << 32);
  v25 = (v25 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v26 = ((uint64_t (*)())double_divide)(v24, v25);
  return (int)COERCE_FLOAT(((int (*)(uint64_t))double_to_int)(v26));
}


// hw_ctrl_set @ 0x10e0a8
int hw_ctrl_set() {
  volatile uint32_t *v0; // r2
  uint64_t v1; // r0
  uint64_t v2; // r0
  uint64_t v3; // r0
  uint64_t v4; // r0
  unsigned int v5; // r0
  uint64_t v6; // r0
  uint64_t v7; // r0
  uint64_t v8; // r2
  uint64_t v9; // r0
  uint64_t v10; // r2
  uint64_t v11; // r0
  uint64_t v12; // r0
  uint64_t v13; // r2
  uint64_t v14; // r0

  v0 = (void *)(uintptr_t)(off_10E150);
  *((volatile uint32_t *)off_10E150 + 1) = 1;
  while ( v0[7] != 1 )
    ;
  v0[7] = 1;
  v1 = unsigned_int_to_double(v0[4]);
  v2 = ((uint64_t (*)())double_multiply)(v1, *(volatile uint64_t *)&dword_10E130);
  v3 = ((uint64_t (*)())double_divide)(v2, *(volatile uint64_t *)&dword_10E138);
  v4 = ((uint64_t (*)())double_compare_neg)(v3, *(volatile uint64_t *)&dword_10E130);
  v5 = ((int (*)(uint64_t))double_to_int)(v4);
  v6 = ((uint64_t (*)())float_to_double)(v5);
  v7 = ((uint64_t (*)())double_divide)(v6, *(volatile uint64_t *)&dword_10E140);
  v8 = (v8 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_10E154) << 32);
  v8 = (v8 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v9 = ((uint64_t (*)())double_multiply)(v7, v8);
  v10 = (v10 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_10E158) << 32);
  v10 = (v10 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v11 = ((uint64_t (*)())double_multiply)(v9, v10);
  v12 = ((uint64_t (*)())double_multiply)(v11, *(volatile uint64_t *)&dword_10E148);
  v13 = (v13 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_10E15C) << 32);
  v13 = (v13 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v14 = ((uint64_t (*)())double_divide)(v12, v13);
  return (int)COERCE_FLOAT(((int (*)(uint64_t))double_to_int)(v14));
}


// rf_hw_init @ 0x10e160
int rf_hw_init() {
  int v0; // r3
  volatile uint32_t *v1; // r4
  uint64_t v2; // r0
  uint64_t v3; // r0
  uint64_t v4; // r0
  int v5; // r5
  char v6; // r0
  int v7; // r4
  int v8; // r3
  int v9; // r6
  uint64_t v10; // r0
  uint64_t v11; // r0
  int v12; // r0
  int v13; // r8
  int v14; // r4
  volatile uint32_t *v15; // r2
  uint64_t v16; // r0
  uint64_t v17; // r0
  uint64_t v18; // r0
  int v19; // r3
  int v20; // r3
  volatile uint32_t *v21; // r6
  int v22; // r7
  int v23; // r4
  int v24; // r2
  int v25; // r9
  uint64_t v26; // r0
  uint64_t v27; // r0
  uint64_t v28; // r0
  int v29; // r5
  int v30; // r2
  volatile uint32_t *v31; // r2
  uint64_t v32; // r0
  uint64_t v33; // r0
  uint64_t v34; // r0
  int v35; // r0
  int v37; // [sp+4h] [bp-10h]
  int v38; // [sp+8h] [bp-Ch]
  int v39; // [sp+Ch] [bp-8h]

  v0 = dword_10E3F4;
  v1 = (void *)(uintptr_t)(off_10E3FC);
  *((volatile uint32_t *)off_10E3F0 + 14) = 296;
  v1[3] = v0 | v1[3] & 0xE0000000;
  call_patch_hook_2();
  v1[2] = dword_10E400 & v1[2] | 0x1200000F;
  v1[1] = 1;
  while ( v1[7] != 1 )
    ;
  v1[7] = 1;
  v2 = unsigned_int_to_double(v1[4]);
  v3 = ((uint64_t (*)())double_multiply)(v2, *(volatile uint64_t *)&dword_10E3D8);
  v4 = ((uint64_t (*)())double_compare_neg)(v3, *(volatile uint64_t *)&dword_10E3E0);
  v5 = ((int (*)(uint64_t))double_to_float_1)(v4);
  alloc_tx_event("Initial    Volt:  %d mV\n", v5);
  v6 = call_patch_hook_0();
  v7 = v5 - 1400;
  v8 = abs32(v5 - 1400);
  v9 = v6 & 0x3F;
  v38 = v9;
  if ( v8 > 49 )
  {
    v10 = signed_int_to_double(v8);
    v11 = ((uint64_t (*)())double_multiply)(v10, *(volatile uint64_t *)&dword_10E3E8);
    v12 = ((int (*)(uint64_t))double_to_float_1)(v11);
    v13 = v12;
    if ( v7 <= 0 )
    {
      if ( v5 == 1400 )
        goto LABEL_38;
      v14 = v12 + v9;
    }
    else
    {
      v14 = v9 - v12;
    }
    if ( v14 > 32 )
    {
      v25 = 7;
      goto LABEL_28;
    }
    if ( v14 > 11 )
    {
      call_patch_hook_2();
      v15 = (void *)(uintptr_t)(off_10E3FC);
      *((volatile uint32_t *)off_10E3FC + 1) = 1;
      while ( v15[7] != 1 )
        ;
      v15[7] = 1;
      v16 = unsigned_int_to_double(v15[4]);
      v17 = ((uint64_t (*)())double_multiply)(v16, *(volatile uint64_t *)&dword_10E3D8);
      v18 = ((uint64_t (*)())double_compare_neg)(v17, *(volatile uint64_t *)&dword_10E3E0);
      v5 = ((int (*)(uint64_t))double_to_float_1)(v18);
      alloc_tx_event("step=%d, val=%d, volt=%d\n", v13, v14, v5);
      if ( v5 <= 1400 )
        v19 = 1;
      else
        v19 = -1;
      v39 = v19;
      goto LABEL_19;
    }
LABEL_38:
    v25 = -13;
    goto LABEL_28;
  }
  if ( (unsigned int)(v8 - 1) > 0x30 )
  {
    v25 = 0;
    goto LABEL_28;
  }
  if ( v7 <= 0 )
    v20 = 1;
  else
    v20 = -1;
  v39 = v20;
  v13 = 0;
LABEL_19:
  v21 = (void *)(uintptr_t)(off_10E3FC);
  v22 = v13 + 1;
  v23 = v39 + v13 * v39 + v38;
  while ( 1 )
  {
    v24 = v13;
    v25 = v23 - v38;
    v13 = v22;
    if ( (unsigned int)(v23 - 12) > 0x14 )
    {
      v25 = v39 * v24;
      goto LABEL_28;
    }
    call_patch_hook_2();
    v21[1] = 1;
    while ( v21[7] != 1 )
      ;
    v21[7] = 1;
    v26 = unsigned_int_to_double(v21[4]);
    v27 = ((uint64_t (*)())double_multiply)(v26, *(volatile uint64_t *)&dword_10E3D8);
    v28 = ((uint64_t (*)())double_compare_neg)(v27, *(volatile uint64_t *)&dword_10E3E0);
    v37 = ((int (*)(uint64_t))double_to_float_1)(v28);
    alloc_tx_event("ofst=%d, val=%d, volt=%d\n", v25, v23, v37);
    v29 = v5 - 1400;
    v30 = v37 - 1400;
    if ( v29 * (v37 - 1400) <= 0 )
      break;
    v23 += v39;
    v5 = v37;
    ++v22;
  }
  if ( v30 < 0 )
    v30 = 1400 - v37;
  if ( v29 < 0 )
    v29 = -v29;
  if ( v30 > v29 )
    v25 -= v39;
LABEL_28:
  alloc_tx_event("reg_value_offset: %d\n", v25);
  call_patch_hook_2();
  v31 = (void *)(uintptr_t)(off_10E3FC);
  *((volatile uint32_t *)off_10E3FC + 1) = 1;
  while ( v31[7] != 1 )
    ;
  v31[7] = 1;
  v32 = unsigned_int_to_double(v31[4]);
  v33 = ((uint64_t (*)())double_multiply)(v32, *(volatile uint64_t *)&dword_10E3D8);
  v34 = ((uint64_t (*)())double_compare_neg)(v33, *(volatile uint64_t *)&dword_10E3E0);
  v35 = ((int (*)(uint64_t))double_to_float_1)(v34);
  alloc_tx_event("Calibrated Volt:  %d mV\n", v35);
  return call_patch_hook_2();
}


// rf_hw_init_alt @ 0x10e420
int rf_hw_init_alt() {
  volatile uint32_t *v0; // r1
  int v1; // r3
  int v2; // r2
  uint64_t v3; // r0
  uint64_t v4; // r0
  uint64_t v5; // r0
  uint64_t v6; // r0
  int v7; // r5
  int v8; // r10
  int v9; // r8
  int v10; // r0
  uint64_t v11; // r0
  uint64_t v12; // r0
  int v13; // r0
  int v14; // r9
  int v15; // r4
  volatile uint32_t *v16; // r2
  uint64_t v17; // r0
  uint64_t v18; // r0
  uint64_t v19; // r0
  uint64_t v20; // r0
  int v21; // r3
  int v22; // r3
  volatile uint32_t *v23; // r6
  int v24; // r4
  int i; // r7
  int v26; // r2
  uint64_t v27; // r0
  uint64_t v28; // r0
  uint64_t v29; // r0
  uint64_t v30; // r0
  int v31; // r10
  int v32; // r5
  int v33; // r2
  volatile uint32_t *v34; // r2
  uint64_t v35; // r0
  uint64_t v36; // r0
  uint64_t v37; // r0
  uint64_t v38; // r0
  int v39; // r0
  int result; // r0
  int v41; // [sp+0h] [bp-Ch]
  int v42; // [sp+4h] [bp-8h]

  v0 = (void *)(uintptr_t)(off_10E6D4);
  v1 = dword_10E6D8;
  v2 = dword_10E6DC;
  *((volatile uint32_t *)off_10E6D0 + 14) = 296;
  v0[2] = v1 & v0[2] | 0x200000B;
  v0[3] = v2 | v0[3] & 0xE0000000;
  v0[1] = 1;
  while ( v0[7] != 1 )
    ;
  v0[7] = 1;
  v3 = unsigned_int_to_double(v0[4]);
  v4 = ((uint64_t (*)())double_multiply)(v3, *(volatile uint64_t *)&dword_10E6B8);
  v5 = ((uint64_t (*)())double_divide)(v4, *(volatile uint64_t *)&dword_10E6C0);
  v6 = ((uint64_t (*)())double_compare_neg)(v5, *(volatile uint64_t *)&dword_10E6B8);
  v7 = ((int (*)(uint64_t))double_to_float_1)(v6);
  v8 = call_patch_hook_0() & 0x1F;
  v9 = v7 - 840;
  debug_printf("Initl vcore Volt: %d mV, reg: %x\n", v7, v8);
  v10 = abs32(v7 - 840);
  if ( v10 <= 47 )
  {
    if ( (unsigned int)(v10 - 1) > 0x2E )
    {
      v9 = 0;
      goto LABEL_33;
    }
    if ( v9 <= 0 )
      v22 = 1;
    else
      v22 = -1;
    v41 = v22;
    v14 = 0;
  }
  else
  {
    v11 = signed_int_to_double(v10);
    v12 = ((uint64_t (*)())double_multiply)(v11, *(volatile uint64_t *)&dword_10E6C8);
    v13 = ((int (*)(uint64_t))double_to_float_1)(v12);
    v14 = v13;
    if ( v9 <= 0 )
    {
      if ( v7 == 840 )
        goto LABEL_33;
      v15 = v13 + v8;
    }
    else
    {
      v15 = v8 - v13;
    }
    if ( v15 > 31 )
    {
      v9 = 9;
      goto LABEL_33;
    }
    if ( v15 <= 12 )
    {
      v9 = -9;
      goto LABEL_33;
    }
    call_patch_hook_2();
    v16 = (void *)(uintptr_t)(off_10E6D4);
    *((volatile uint32_t *)off_10E6D4 + 1) = 1;
    while ( v16[7] != 1 )
      ;
    v16[7] = 1;
    v17 = unsigned_int_to_double(v16[4]);
    v18 = ((uint64_t (*)())double_multiply)(v17, *(volatile uint64_t *)&dword_10E6B8);
    v19 = ((uint64_t (*)())double_divide)(v18, *(volatile uint64_t *)&dword_10E6C0);
    v20 = ((uint64_t (*)())double_compare_neg)(v19, *(volatile uint64_t *)&dword_10E6B8);
    v7 = ((int (*)(uint64_t))double_to_float_1)(v20);
    alloc_tx_event("step=%d, val=%x, volt=%d\n", v14, v15, v7);
    if ( v7 <= 840 )
      v21 = 1;
    else
      v21 = -1;
    v41 = v21;
  }
  v23 = (void *)(uintptr_t)(off_10E6D4);
  v42 = v8;
  v24 = v41 + v14 * v41 + v8;
  for ( i = v14 + 1; ; ++i )
  {
    v26 = v14;
    v9 = v24 - v42;
    v14 = i;
    if ( (unsigned int)(v24 - 13) > 0x12 )
    {
      v9 = v41 * v26;
      goto LABEL_33;
    }
    call_patch_hook_2();
    v23[1] = 1;
    while ( v23[7] != 1 )
      ;
    v23[7] = 1;
    v27 = unsigned_int_to_double(v23[4]);
    v28 = ((uint64_t (*)())double_multiply)(v27, *(volatile uint64_t *)&dword_10E6B8);
    v29 = ((uint64_t (*)())double_divide)(v28, *(volatile uint64_t *)&dword_10E6C0);
    v30 = ((uint64_t (*)())double_compare_neg)(v29, *(volatile uint64_t *)&dword_10E6B8);
    v31 = ((int (*)(uint64_t))double_to_float_1)(v30);
    alloc_tx_event("ofst=%d, val=%x, volt=%d\n", v9, v24, v31);
    v32 = v7 - 840;
    v33 = v31 - 840;
    if ( v32 * (v31 - 840) <= 0 )
      break;
    v24 += v41;
    v7 = v31;
  }
  if ( v33 < 0 )
    v33 = 840 - v31;
  if ( v32 < 0 )
    v32 = -v32;
  if ( v33 > v32 )
    v9 -= v41;
LABEL_33:
  debug_printf("reg_value_offset: %d\n", v9);
  call_patch_hook_2();
  v34 = (void *)(uintptr_t)(off_10E6D4);
  *((volatile uint32_t *)off_10E6D4 + 1) = 1;
  while ( v34[7] != 1 )
    ;
  v34[7] = 1;
  v35 = unsigned_int_to_double(v34[4]);
  v36 = ((uint64_t (*)())double_multiply)(v35, *(volatile uint64_t *)&dword_10E6B8);
  v37 = ((uint64_t (*)())double_divide)(v36, *(volatile uint64_t *)&dword_10E6C0);
  v38 = ((uint64_t (*)())double_compare_neg)(v37, *(volatile uint64_t *)&dword_10E6B8);
  v39 = ((int (*)(uint64_t))double_to_float_1)(v38);
  debug_printf("Calib vcore Volt: %d mV\n", v39);
  result = ((volatile uint32_t *)(uintptr_t)off_10E6F8)[94];
  if ( result != 0x80000000 )
    return sdio_set_phase_config(result);
  return result;
}


// rf_pa_current_calibrate @ 0x10e6fc
int rf_pa_current_calibrate(unsigned int a1, unsigned int a2, volatile unsigned int *a3) {
  unsigned int v3; // r4
  volatile unsigned int *v4; // r6
  volatile unsigned int *v5; // r5
  volatile int16_t *v8; // r5
  int v9; // r10
  int v10; // r2
  volatile unsigned int *v11; // r7
  volatile unsigned int *v12; // r6
  unsigned int v13; // r11
  int v14; // r8
  int v15; // r9
  int v16; // r2
  int v17; // r0
  int v18; // r2
  int v20; // r5
  unsigned int v21; // [sp+Ch] [bp-20h]
  unsigned int v22; // [sp+10h] [bp-1Ch]
  int v23; // [sp+14h] [bp-18h]
  unsigned int v24; // [sp+18h] [bp-14h]
  unsigned int v25; // [sp+1Ch] [bp-10h]

  v4 = (volatile unsigned int *)off_10E89C;
  v5 = (volatile unsigned int *)off_10E8A0;
  *(volatile uint32_t *)off_10E89C = *(volatile uint32_t *)off_10E89C & 0xFFFFFFF8 | a1 & 7;
  *v5 = ((uint16_t)a1 << 12) & 0x7000 | *v5 & 0xFFFF8FFF;
  *v4 = (8 * a2) & 0x78 | *v4 & 0xFFFFFF87;
  *v5 = (a2 << 15) & 0x78000 | *v5 & 0xFFF87FFF;
  v8 = (volatile int16_t *)off_10E8A4;
  v9 = hw_block_enable();
  alloc_tx_event("cal start, reg_init=(%d,%d), i_pa_init=%d, i_pa_target=%d\n", a1, a2, v9, *v8);
  v10 = *v8;
  if ( v10 > v9 )
  {
    v23 = 1;
  }
  else
  {
    if ( v10 >= v9 )
    {
      v20 = 0;
      goto LABEL_9;
    }
    v23 = -1;
  }
  v3 = a2;
  v11 = (volatile unsigned int *)off_10E89C;
  v12 = (volatile unsigned int *)off_10E8A0;
  v21 = a1;
  v22 = a1 + a2;
  v13 = a1;
  v14 = 7;
  v20 = 0;
  while ( 1 )
  {
    v24 = v13;
    v20 += v23;
    v13 = __usat(3u, v21 + v20);
    *v11 = *v11 & 0xFFFFFFF8 | v13;
    *v12 = *v12 & 0xFFFF8FFF | (v13 << 12);
    v25 = v3;
    v3 = __usat(4u, v22 + v20 - v13);
    *v11 = *v11 & 0xFFFFFF87 | (8 * v3);
    *v12 = *v12 & 0xFFF87FFF | (v3 << 15);
    v15 = v9;
    v9 = hw_block_enable();
    alloc_tx_event("reg_val_res=%d, reg_val_cgm=%d, i_pa=%d\n", v13, v3, v9);
    v16 = *(volatile int16_t *)off_10E8A4;
    v17 = v9 - v16;
    v18 = v15 - v16;
    if ( v18 * v17 <= 0 )
      break;
    if ( !--v14 )
      goto LABEL_9;
  }
  if ( v18 < 0 )
    v18 = -v18;
  if ( v17 < 0 )
    v17 = -v17;
  if ( v18 <= v17 )
  {
    v3 = v25;
    *v11 = *v11 & 0xFFFFFFF8 | v24 & 7;
    *v12 = (v24 << 12) & 0x7000 | *v12 & 0xFFFF8FFF;
    *v11 = (8 * v25) & 0x78 | *v11 & 0xFFFFFF87;
    v9 = v15;
    v13 = v24;
    *v12 = (v25 << 15) & 0x78000 | *v12 & 0xFFF87FFF;
  }
  alloc_tx_event("cal done, offset_res=%d,(%d,%d), i_pa_res=%d\n", v20, v13 - v21, v3 - a2, v9);
LABEL_9:
  *a3 = v3;
  return v20;
}


// gpio_pad_ctrl_set @ 0x10e8b4
/* luna: Sweeps the RF PA control code to find the setting whose measured PA current is closest to the target, returning the selected code's offset from the in */
int gpio_pad_ctrl_set(int a1) {
  volatile int16_t *target_pa_current_ptr; // r9
  int current_control_code; // r7
  int previous_pa_current; // r5
  int v4; // r3
  volatile unsigned int *control_register; // r8
  int v6; // r6
  int control_code_offset; // r10
  int v8; // r2
  int measured_pa_current; // r4
  int v10; // r3
  int v11; // r0
  int v12; // r3
  int v14; // r1
  int v15; // r2
  int sweep_direction; // [sp+0h] [bp-Ch]
  int initial_control_code; // [sp+4h] [bp-8h]

  target_pa_current_ptr = (volatile int16_t *)off_10E9D0;
  *(volatile uint32_t *)off_10E9C4 = (a1 << 26) & 0x1C000000 | *(volatile uint32_t *)off_10E9C4 & 0xE3FFFFFF;
  current_control_code = a1;
  previous_pa_current = hw_ctrl_set();
  alloc_tx_event("cal start, reg_init=%d, i_pa_init=%d, i_pa_target=%d\n", current_control_code, previous_pa_current, *target_pa_current_ptr);
  v4 = *target_pa_current_ptr;
  if ( v4 > previous_pa_current )
  {
    sweep_direction = 1;
  }
  else
  {
    if ( v4 >= previous_pa_current )
      return 0;
    sweep_direction = -1;
  }
  control_register = (volatile unsigned int *)off_10E9C4;
  initial_control_code = current_control_code;
  v6 = 4;
  control_code_offset = 0;
  while ( 1 )
  {
    current_control_code += sweep_direction;
    if ( current_control_code <= 7 )
    {
      if ( current_control_code < 0 )
      {
        current_control_code = 0;
        v8 = 0;
        control_code_offset = -initial_control_code;
      }
      else
      {
        v8 = current_control_code << 26;
        control_code_offset += sweep_direction;
      }
    }
    else
    {
      v8 = 469762048;
      control_code_offset = 7 - initial_control_code;
      current_control_code = 7;
    }
    *control_register = *control_register & 0xE3FFFFFF | v8;
    measured_pa_current = hw_ctrl_set();
    alloc_tx_event("reg_val=%d, i_pa=%d\n", current_control_code, measured_pa_current);
    v10 = *target_pa_current_ptr;
    v11 = measured_pa_current - v10;
    v12 = previous_pa_current - v10;
    if ( v12 * v11 <= 0 )
      break;
    --v6;
    previous_pa_current = measured_pa_current;
    if ( !v6 )
      return control_code_offset;
  }
  v14 = v12;
  if ( v12 < 0 )
    v14 = -v12;
  if ( v11 < 0 )
    v11 = -v11;
  v15 = measured_pa_current;
  if ( v14 <= v11 )
  {
    control_code_offset -= sweep_direction;
    v15 = previous_pa_current;
    *control_register = ((current_control_code - sweep_direction) << 26) & 0x1C000000 | *control_register & 0xE3FFFFFF;
  }
  alloc_tx_event("cal done, offset_res=%d, i_pa_res=%d\n", control_code_offset, v15);
  return control_code_offset;
}


// rf_gpio_init @ 0x10e9d8
/* luna: Temporarily enables the RF GPIO control path, applies GPIO mode 8 using the supplied configuration, and restores the temporary control bits. */
int rf_gpio_init(int a1) {
  volatile uint32_t *v1; // r2
  int v2; // r7
  int v3; // r3
  volatile uint32_t *v4; // r5
  volatile uint32_t *v5; // r10
  int v6; // r6
  volatile unsigned int *v7; // r4
  volatile int *v8; // r1
  int v9; // r0
  unsigned int v10; // r9
  unsigned int v11; // r8
  unsigned int v12; // r7
  unsigned int v13; // r6
  int result; // r0
  struct __attribute__((packed)) { uint16_t a1a[2]; // [sp+Ch] [bp-Ch] BYREF
  int v17; // [sp+10h] [bp-8h]
  uint16_t v18; // [sp+14h] [bp-4h]
  } _frame;
  v1 = (void *)(uintptr_t)(off_10EADC);
  v2 = dword_10EAE0;
  v3 = dword_10EAE4;
  v4 = (void *)(uintptr_t)(off_10EAE8);
  v5 = (void *)(uintptr_t)(off_10EB00);
  v6 = dword_10EAEC;
  v7 = (volatile unsigned int *)off_10EAF0;
  _frame.v18 = 0;
  *((volatile uint32_t *)off_10EAFC + 14) = 296;
  v1[3] = v1[3] & 0xE0000000 | v2;
  v1[2] = v3 & v1[2] | 0x1200000D;
  *v4 |= 2u;
  *v4 &= ~1u;
  *(volatile uint32_t *)_frame.a1a = v6;
  _frame.v17 = 5610;
  check_boot_flag(_frame.a1a, 0);
  v8 = (volatile int *)off_10EAF4;
  v9 = dword_10EAF8;
  *v5 |= 0x80000000;
  *v8 = v9;
  v10 = *v7;
  v11 = *v7;
  v12 = *v7;
  v13 = *v7;
  *v7 &= ~0x80000u;
  *v7 |= 0x100000u;
  *v7 |= 0x200000u;
  *v7 |= 0x400000u;
  result = rf_pa_current_calibrate(4u, 8u, (volatile unsigned int *)a1);
  *v5 &= ~0x80000000;
  *v4 &= ~2u;
  *v7 = v10 & 0x80000 | *v7 & 0xFFF7FFFF;
  *v7 = v11 & 0x100000 | *v7 & 0xFFEFFFFF;
  *v7 = v12 & 0x200000 | *v7 & 0xFFDFFFFF;
  *v7 = v13 & 0x400000 | *v7 & 0xFFBFFFFF;
  return result;
}


// rf_gpio_init_alt @ 0x10eb04
/* luna: Performs the alternate RF GPIO setup sequence, configures GPIO pad 4, and restores the saved control-register bits. */
int rf_gpio_init_alt() {
  volatile unsigned int *rf_gpio_ctrl_reg; // r4
  int v1; // r2
  int v2; // r0
  int v3; // r3
  volatile uint32_t *v4; // r9
  volatile uint32_t *v5; // r6
  volatile uint32_t *v6; // r10
  int v7; // r5
  volatile int *v8; // r2
  int v9; // r1
  unsigned int saved_ctrl_reg_value_1; // r8
  unsigned int saved_ctrl_reg_value_2; // r7
  unsigned int saved_ctrl_reg_value_3; // r6
  unsigned int saved_ctrl_reg_value_4; // r5
  int result; // r0
  struct __attribute__((packed)) { int a6[2]; // [sp+4h] [bp-Ch] BYREF
  int16_t v16; // [sp+Ch] [bp-4h]
  } _frame;
  rf_gpio_ctrl_reg = (volatile unsigned int *)off_10EC04;
  v1 = off_10EC08;
  v2 = dword_10EC0C;
  v3 = dword_10EC10;
  v4 = (void *)(uintptr_t)(off_10EC24);
  v5 = (void *)(uintptr_t)(off_10EC14);
  v6 = (void *)(uintptr_t)(off_10EC28);
  v7 = dword_10EC18;
  _frame.v16 = 0;
  *((volatile uint32_t *)off_10EC04 + 14) = 296;
  *(volatile uint32_t *)(v1 + 0xC) = v2 | *(volatile uint32_t *)(v1 + 0xC) & 0xE0000000;
  *(volatile uint32_t *)(v1 + 8) = v3 & *(volatile uint32_t *)(v1 + 8) | 0x1200000D;
  *v4 |= 0x20000000u;
  *v5 &= ~1u;
  _frame.a6[0] = v7;
  _frame.a6[1] = 2442;
  check_boot_flag((volatile uint16_t *)_frame.a6, 0);
  v8 = (volatile int *)off_10EC1C;
  v9 = dword_10EC20;
  rf_gpio_ctrl_reg += 593954;
  *v6 |= 0x80000000;
  *v8 = v9;
  saved_ctrl_reg_value_1 = *rf_gpio_ctrl_reg;
  saved_ctrl_reg_value_2 = *rf_gpio_ctrl_reg;
  saved_ctrl_reg_value_3 = *rf_gpio_ctrl_reg;
  saved_ctrl_reg_value_4 = *rf_gpio_ctrl_reg;
  *rf_gpio_ctrl_reg &= ~0x80000u;
  *rf_gpio_ctrl_reg |= 0x100000u;
  *rf_gpio_ctrl_reg |= 0x200000u;
  *rf_gpio_ctrl_reg |= 0x400000u;
  result = gpio_pad_ctrl_set(4);
  *v6 &= ~0x80000000;
  *v4 &= ~0x20000000u;
  *rf_gpio_ctrl_reg = saved_ctrl_reg_value_1 & 0x80000 | *rf_gpio_ctrl_reg & 0xFFF7FFFF;
  *rf_gpio_ctrl_reg = saved_ctrl_reg_value_2 & 0x100000 | *rf_gpio_ctrl_reg & 0xFFEFFFFF;
  *rf_gpio_ctrl_reg = saved_ctrl_reg_value_3 & 0x200000 | *rf_gpio_ctrl_reg & 0xFFDFFFFF;
  *rf_gpio_ctrl_reg = saved_ctrl_reg_value_4 & 0x400000 | *rf_gpio_ctrl_reg & 0xFFBFFFFF;
  return result;
}


// call_patch_hook_0 @ 0x10ec2c
/* luna: Calls the no-argument function pointer stored at MEMD offset 0x1B0 and returns its result. */
int call_patch_hook_0() {
  return ((int (*)())MEMD(0x1B0))();
}



// call_patch_hook_1 @ 0x10ec34
/* luna: Calls the function pointer stored at address 0x1B4 and returns its result. */
int call_patch_hook_1() {
  return ((int (*)())MEMD(0x1B4))();
}



// call_patch_hook_2 @ 0x10ec3c
/* luna: Calls the function pointer stored at memory-data address 0x1B8 and returns its result. */
int call_patch_hook_2() {
  return ((int (*)())MEMD(0x1B8))();
}



// mmio_read32_1 @ 0x10ec44
int mmio_read32_1(int a1, int a2) {
  volatile int *v2; // r5
  volatile uint32_t *v3; // r4
  int result; // r0
  int v5; // r3
  int v6; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_10EC8C = 1;
  }
  v2 = (volatile int *)off_10EC90;
  ++*(volatile uint32_t *)off_10EC90;
  if ( a2 )
  {
    v3 = (void *)(uintptr_t)(off_10EC94);
    while ( !*(volatile uint32_t *)off_10EC94 )
      ;
    result = call_patch_hook_0();
    *v3 = 1;
  }
  else
  {
    result = call_patch_hook_0();
  }
  if ( *v2 )
  {
    v5 = *v2 - 1;
    v6 = *(volatile uint32_t *)off_10EC8C;
    *v2 = v5;
    if ( !v5 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
  return result;
}



// mmio_read32_variant @ 0x10ec98
int mmio_read32_variant(int a1, int a2, int a3) {
  volatile int *v3; // r5
  volatile uint32_t *v4; // r4
  int result; // r0
  int v6; // r3
  int v7; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_10ECE0 = 1;
  }
  v3 = (volatile int *)off_10ECE4;
  ++*(volatile uint32_t *)off_10ECE4;
  if ( a3 )
  {
    v4 = (void *)(uintptr_t)(off_10ECE8);
    while ( !*(volatile uint32_t *)off_10ECE8 )
      ;
    result = call_patch_hook_1();
    *v4 = 1;
  }
  else
  {
    result = call_patch_hook_1();
  }
  if ( *v3 )
  {
    v6 = *v3 - 1;
    v7 = *(volatile uint32_t *)off_10ECE0;
    *v3 = v6;
    if ( !v6 )
    {
      if ( v7 )
        __enable_irq();
    }
  }
  return result;
}



