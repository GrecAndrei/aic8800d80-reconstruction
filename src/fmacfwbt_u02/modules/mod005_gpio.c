// ke_event_process @ 0x10d26c
int ke_event_process(int a1, int a2, int a3) {
  volatile int *v6; // r1
  int result; // r0
  int v8; // r12
  int v9; // lr
  int v10; // r9
  int v11; // r3
  volatile int *v12; // r3
  int v13; // r3

  if ( **(volatile int16_t **)off_10D3E8 < 0 && a3 > 13 )
    mmio_irq_clear(dword_10D3F8, dword_10D3F4, 69);
  *(volatile uint32_t *)(a2 + 32) = 0;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_10D3EC = 1;
  }
  v6 = (volatile int *)off_10D3F0;
  result = *(volatile uint32_t *)off_10D3F0;
  v8 = *(volatile uint32_t *)off_10D3F0 + 1;
  ((volatile uint32_t *)(uintptr_t)0x40021000u)[16 * a3] |= 1u;
  *v6 = v8;
while ( (((volatile uint32_t *)(uintptr_t)0x40021000u)[16 * a3] & 0x10000) == 0 ) ;
  v9 = dword_10D3FC;
  v10 = *(volatile uint32_t *)(dword_10D3FC + 4 * a3);
if ( v10 && (((volatile uint32_t *)(uintptr_t)0x40021000u)[16 * a3 + 3] & 0x800) == 0 ) { if ( (((volatile uint32_t *)(uintptr_t)0x40021000u)[16 * a3 + 6] & 0x80000) != 0 ) { ((volatile uint32_t *)(uintptr_t)0x40021000u)[16 * a3 + 6] &= ~0x80000u;
      ((volatile uint32_t *)(uintptr_t)0x40021000u)[16 * a3 + 12] = a1;
    }
    *(volatile uint32_t *)(v10 + 8) &= ~0x80000u;
    *(volatile uint32_t *)(v10 + 32) = a1;
  }
  else
  {
    ((volatile uint32_t *)(uintptr_t)0x40021000u)[16 * a3 + 2] = dword_10D400;
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
    v12 = (volatile int *)off_10D3EC;
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



// watchdog_kick @ 0x10d404
int watchdog_kick() {
  int v0; // r3
  int result; // r0

  v0 = *((volatile uint32_t *)off_10D428 + 3);
  if ( (v0 & 0x8000) != 0 )
    *((volatile uint32_t *)off_10D428 + 2) = 0x800000;
  if ( (v0 & 0x400) != 0 )
  {
    *((volatile uint32_t *)off_10D428 + 2) = 0x40000;
    return set_system_flag_1(0x20000000);
  }
  return result;
}



// watchdog_init @ 0x10d42c
int watchdog_init() {
  volatile unsigned int *v0; // r2
  unsigned int v1; // r3
  int result; // r0
  volatile uint32_t *v3; // r3

  v0 = (volatile unsigned int *)off_10D470;
  v1 = *(volatile uint32_t *)off_10D470;
  if ( (*(volatile uint32_t *)off_10D470 & 1) == 0 )
  {
    v1 = v1 & 0xFFFFFCFE | 0x101;
    result = 17;
    *((volatile uint32_t *)off_10D470 + 4) = 0;
    v0[5] = 0;
    v0[1] = 17;
    *v0 = v1;
  }
  if ( (v1 & 0x4000) == 0 )
    *(volatile uint32_t *)off_10D470 = v1 | 0x4040;
  v3 = (void *)(uintptr_t)(off_10D478);
  *(volatile uint32_t *)(*((volatile uint32_t *)off_10D474 + 2) + 148) = dword_10D47C;
  *v3 = 0x200000;
  return result;
}



// irq_install @ 0x10d480
void irq_install() {
  volatile uint32_t *v0; // r3

  v0 = (void *)(uintptr_t)(off_10D498);
  *(volatile uint32_t *)(*((volatile uint32_t *)off_10D494 + 2) + 148) = dword_10D49C;
  *v0 = 0x200000;
}



// event_loop @ 0x10d4a0
void event_loop() {
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

  v0 = *((volatile uint32_t *)off_10D58C + 43);
  if ( v0 >= 0 )
  {
    if ( *(volatile uint32_t *)off_10D590 )
    {
      v21 = (void *)(uintptr_t)(off_10D5B8);
      v22 = (void *)(uintptr_t)(off_10D5BC);
      v23 = dword_10D5C0;
      *(volatile uint32_t *)off_10D598 = 1;
      *(volatile uint32_t *)(v21[2] + 124) = v23;
      *v22 = 0x8000;
    }
  }
  else if ( *(volatile uint32_t *)off_10D590 )
  {
    v1 = (void *)(uintptr_t)(off_10D598);
    v2 = (void *)(uintptr_t)(off_10D59C);
    v3 = (void *)(uintptr_t)(off_10D5A0);
    *(volatile uint32_t *)off_10D594 = 0;
    *v1 = 0;
    *v2 = 1;
    v4 = (void *)(uintptr_t)(off_10D5A4);
    v5 = (void *)(uintptr_t)(off_10D5A8);
    *v3 |= 0x100u;
    *v4 = 3;
    v6 = v0 & 0x7FFFFFFF;
    if ( (v5[20] & 0x20) != 0 )
    {
      v7 = *(volatile uint32_t *)off_10D5C8;
      if ( v6 < *(volatile uint32_t *)off_10D5C8 >> 4 )
        goto LABEL_5;
    }
    else
    {
      v7 = 2 * *(volatile uint32_t *)off_10D5AC;
      if ( v6 < v7 >> 4 )
      {
LABEL_5:
        v8 = v7 / v6;
        v9 = (uint8_t)(v8 >> 4);
        v10 = ((v8 >> 1) & 7) + 16 * ((v8 & 0xF) - ((v8 >> 1) & 7));
        v11 = (uint8_t)(v8 >> 12);
LABEL_6:
        v12 = (void *)(uintptr_t)(off_10D5A4);
        v13 = (void *)(uintptr_t)(off_10D598);
        v14 = (volatile int *)off_10D5B0;
        v15 = (volatile int *)off_10D5B4;
        *(volatile uint32_t *)off_10D5A4 |= 0x80u;
        *v15 = v9;
        *v13 = v11;
        *v14 = v10;
        v16 = (void *)(uintptr_t)(off_10D594);
        v17 = (volatile unsigned int *)off_10D59C;
        v18 = (void *)(uintptr_t)(off_10D5B8);
        *v12 &= ~0x80u;
        *v16 = 7;
        v19 = (void *)(uintptr_t)(off_10D5BC);
        v20 = dword_10D5C0;
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
  *(volatile uint32_t *)off_10D5C4 = 1;
}



// event_loop_check @ 0x10d5cc
void event_loop_check() {
  if ( !*(volatile uint32_t *)off_10D5D8 )
    event_loop();
}



// irq_disable @ 0x10d5dc
void irq_disable() {
  *((volatile uint32_t *)off_10D5F0 + 32) = 0x8000;
  __dsb(0xFu);
  __isb(0xFu);
}



// uart_putc @ 0x10d5f4
/* luna: Waits until the UART transmit register is ready, writes the character, and returns it. */
int uart_putc(int result) {
  while ( (*(volatile uint32_t *)off_10D604 & 0x80000) != 0 )
    ;
  *(volatile uint32_t *)off_10D608 = result;
  return result;
}



// uart_puts @ 0x10d60c
/* luna: Writes a NUL-terminated string to UART, waiting for the transmitter before each byte, and returns a pointer to the terminator. */
volatile uint8_t * uart_puts(volatile uint8_t *result) {
  int current_char; // r1
  volatile uint32_t *uart_status_reg; // r2
  volatile uint32_t *uart_tx_data_reg; // r4
  int next_char; // t1

  current_char = (uint8_t)*result;
  if ( *result )
  {
    uart_status_reg = (void *)(uintptr_t)(off_10D630);
    uart_tx_data_reg = (void *)(uintptr_t)(off_10D634);
    do
    {
      while ( (*uart_status_reg & 0x80000) != 0 )
        ;
      *uart_tx_data_reg = current_char;
      next_char = (uint8_t)*++result;
      current_char = next_char;
    }
    while ( next_char );
  }
  return result;
}



// uart_getc @ 0x10d638
/* luna: Busy-waits for the UART receive-ready bit, then reads and returns the received byte. */
int uart_getc() {
  while ( (*(volatile uint32_t *)off_10D648 & 1) == 0 )
    ;
  return (uint8_t)*(volatile uint32_t *)off_10D64C;
}



// uart_rx_ready @ 0x10d650
/* luna: Returns whether the UART receive-data-ready status bit is set. */
int uart_rx_ready() {
  return *(volatile uint32_t *)off_10D65C & 1;
}



// debug_printf @ 0x10d660
int debug_printf(volatile uint8_t *a1, volatile unsigned int *a2) {
  volatile uint32_t *v2; // r4
  unsigned int IPSR; // r6
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
  volatile char *v22; // r8
  unsigned int v23; // r0
  volatile uint8_t *v24; // r8
  volatile uint8_t *v25; // r9
  volatile char *v26; // r0
  volatile uint32_t *v27; // r2
  volatile int *v28; // r12
  int v29; // r1
  int v30; // t1
  volatile uint16_t *v31; // r10
  int v32; // r11
  volatile char *v33; // r0
  volatile uint32_t *v34; // r2
  volatile int *v35; // r5
  int v36; // r1
  int v37; // t1
  volatile char **v38; // r3
  int v39; // r0
  volatile char *v40; // r8
  int v41; // r3
  volatile uint8_t *v42; // r1
  unsigned int v43; // r2
  uint16_t v44; // r0
  volatile uint32_t *v45; // r5
  int v46; // r2
  volatile int *v47; // r5
  int v48; // r0
  int v49; // r3
  int v50; // r2
  volatile char *v51; // r0
  volatile uint32_t *v52; // r2
  volatile int *v53; // r4
  int v54; // r1
  int v55; // t1
  volatile char *v56; // r0
  volatile uint32_t *v57; // r2
  volatile int *v58; // r4
  int v59; // r1
  int v60; // t1
  volatile char *v61; // r0
  volatile uint32_t *v62; // r2
  volatile int *v63; // r12
  int v64; // r1
  int v65; // t1
  int v66; // r2
  uint64_t v67; // r0
  int ( *v68)(uint32_t); // r2
  int v69; // r0
  volatile uint16_t *v70; // r2
  int v71; // r2
  uint16_t v72; // r5
  volatile char *v73; // r1
  volatile uint32_t *v74; // r2
  volatile int *v75; // r0
  int v76; // t1
  struct __attribute__((packed)) { volatile int *v77; // [sp+Ch] [bp-108h]
  char a1a[260]; // [sp+10h] [bp-104h] BYREF
  } _frame;
  IPSR = __get_IPSR();
  v4 = main_loop_dispatch(_frame.a1a, 256, 0, a1, a2);
  v5 = v4;
  if ( v4 <= 0 )
    return v5;
  v6 = v4;
  if ( *(volatile uint32_t *)off_10D92C )
  {
    if ( IPSR )
      goto LABEL_5;
  }
  else
  {
    event_loop();
    if ( IPSR )
      goto LABEL_5;
  }
  while ( !*(volatile uint32_t *)off_10D930 )
    ;
LABEL_5:
  if ( !*(volatile uint32_t *)off_10D934 )
  {
    while ( (*(volatile uint32_t *)off_10D938 & 0x80000) != 0 )
      ;
    *(volatile uint32_t *)off_10D93C = 95;
  }
  v7 = HIWORD(((volatile uint32_t *)(uintptr_t)off_10D940)[44]) & 0x4000;
  if ( (((volatile uint32_t *)(uintptr_t)off_10D940)[44] & 0x40000000) == 0 )
  {
    v8 = _frame.a1a;
    v9 = (void *)(uintptr_t)(off_10D938);
    v10 = (void *)(uintptr_t)(off_10D93C);
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
  v15 = **(volatile uint8_t **)off_10D944;
  if ( v15 == 1 )
  {
    if ( **(volatile uint8_t **)off_10D94C != 3 )
    {
      if ( v6 >= 124 )
        v6 = (v6 & ~0xFFFFu) | ((uint16_t)(124) & 0xFFFFu);
      ke_mem_alloc(19, _frame.a1a, (uint16_t)v6);
    }
    goto LABEL_13;
  }
  if ( v15 != 2 )
    goto LABEL_13;
  v16 = (volatile uint8_t **)off_10D94C;
  if ( **(volatile uint8_t **)off_10D94C == 3 )
  {
LABEL_19:
    v17 = aNoActive;
    v18 = (void *)(uintptr_t)(off_10D938);
    v19 = (volatile int *)off_10D93C;
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
  if ( (unsigned int)list_length((volatile uint32_t **)dword_10D950) <= 4 )
  {
    if ( **(volatile uint8_t **)off_10D944 == 2 )
    {
      if ( **v16 != 3 )
      {
        if ( (unsigned int)list_length((volatile uint32_t **)dword_10D950) > 4 )
        {
          v56 = aOtherErr;
          v57 = (void *)(uintptr_t)(off_10D938);
          v58 = (volatile int *)off_10D93C;
          v59 = 111;
          do
          {
            while ( (*v57 & 0x80000) != 0 )
              ;
            *v58 = v59;
            v60 = (uint8_t)*++v56;
            v59 = v60;
          }
          while ( v60 );
        }
        else
        {
          v51 = aFree5;
          v52 = (void *)(uintptr_t)(off_10D938);
          v53 = (volatile int *)off_10D93C;
          v54 = 102;
          do
          {
            while ( (*v52 & 0x80000) != 0 )
              ;
            *v53 = v54;
            v55 = (uint8_t)*++v51;
            v54 = v55;
          }
          while ( v55 );
        }
        goto LABEL_13;
      }
      goto LABEL_19;
    }
LABEL_13:
    if ( !IPSR )
      *(volatile uint32_t *)off_10D930 = 1;
    return v5;
  }
  v22 = _frame.a1a;
  while ( 1 )
  {
    v23 = (unsigned int)v22++;
    if ( !memcmp(v23, (unsigned int)aCm4FaultHandle, 0x14u) )
      break;
    if ( &_frame.a1a[v6] == v22 )
    {
      v24 = (void *)(uintptr_t)(off_10D984);
      goto LABEL_37;
    }
  }
  v61 = aFoundPanic;
  v62 = (void *)(uintptr_t)(off_10DA5C);
  v63 = (volatile int *)off_10DA74;
  v64 = 70;
  do
  {
    while ( (*v62 & 0x80000) != 0 )
      ;
    *v63 = v64;
    v65 = (uint8_t)*++v61;
    v64 = v65;
  }
  while ( v65 );
  v24 = (void *)(uintptr_t)(off_10DA78);
  v66 = *(volatile uint32_t *)off_10DA60;
  _frame.v77 = (volatile int *)off_10DA64;
  v67 = *(volatile uint64_t *)(v66 + 4);
  v68 = *(int ( **)(uint32_t))(HIDWORD(v67) + 16);
  *(volatile uint8_t *)off_10DA78 = 1;
  v69 = v68(v67);
  v70 = (void *)(uintptr_t)(off_10DA68);
  *_frame.v77 = v69;
  *v70 = 4;
LABEL_37:
  if ( *v24 )
  {
    v25 = (void *)(uintptr_t)(off_10D988);
    if ( !memcmp((unsigned int)_frame.a1a, (unsigned int)aPanic, 5u) )
    {
      v26 = aPanicEnd;
      v27 = (void *)(uintptr_t)(off_10D938);
      v28 = (volatile int *)off_10D93C;
      *v25 = 1;
      v29 = 80;
      do
      {
        while ( (*v27 & 0x80000) != 0 )
          ;
        *v28 = v29;
        v30 = (uint8_t)*++v26;
        v29 = v30;
      }
      while ( v30 );
    }
    v31 = (volatile uint16_t *)off_10D98C;
    v32 = *(volatile uint16_t *)off_10D98C;
    if ( v32 + v6 <= 1720 )
    {
      _frame.v77 = (volatile int *)off_10DA64;
      memcpy((volatile char *)(*(volatile uint32_t *)off_10DA64 + v32), _frame.a1a, v6);
      v71 = (uint8_t)*v25;
      v38 = (volatile char **)_frame.v77;
      v72 = v6 + *v31;
      v32 = v72;
      *v31 = v72;
      if ( !v71 )
        return v5;
    }
    else
    {
      v33 = aBufFull;
      v34 = (void *)(uintptr_t)(off_10D938);
      v35 = (volatile int *)off_10D93C;
      v36 = 66;
      do
      {
        while ( (*v34 & 0x80000) != 0 )
          ;
        *v35 = v36;
        v37 = (uint8_t)*++v33;
        v36 = v37;
      }
      while ( v37 );
      v38 = (volatile char **)off_10D960;
    }
    v39 = dword_10D950;
    *v24 = 0;
    *v25 = 0;
    v40 = *v38;
    *v31 = 4;
    *v38 = nullptr;
    v5 = v32;
    list_pop_front(v39);
    goto LABEL_48;
  }
  v2 = list_pop_front(dword_10DA6C);
  if ( v6 <= 122 )
    v40 = (volatile char *)int_disable_set_flag();
  else
    v40 = (volatile char *)(*(int ( **)(uint32_t))(*(volatile uint32_t *)(*(volatile uint32_t *)off_10DA60 + 8) + 16))(*(volatile uint32_t *)(*(volatile uint32_t *)off_10DA60 + 4));
  if ( v40 )
  {
    memcpy(v40 + 4, _frame.a1a, v6);
    v32 = (v32 & ~0xFFFFu) | ((uint16_t)(v6) & 0xFFFFu);
LABEL_48:
    *(volatile uint16_t *)v40 = v5 + 1;
    v40[2] = 19;
    v41 = 0;
    v42 = (void *)(uintptr_t)(off_10D964);
    v40[3] = 0;
    v40[v5 + 4] = 0;
    v43 = *((volatile uint16_t *)v42 + 4122);
    if ( v43 > 0x186 )
    {
      v43 = (v43 & ~0xFFFFu) | ((uint16_t)(0) & 0xFFFFu);
      v44 = 1;
    }
    else
    {
      v44 = v43 + 1;
      v41 = 8 * v43;
    }
    v45 = (void *)(uintptr_t)(off_10D968);
    *((volatile uint16_t *)v2 + 6) = v43;
    v46 = *v45 + v41;
    *(volatile uint32_t *)(v46 + 4) = (int)(uintptr_t)(v40);
    *(volatile uint16_t *)v46 = v32 + 5;
    *(volatile uint8_t *)(v46 + 3) = *(volatile uint8_t *)(v46 + 3) & 0x31 | 4;
    v45 = (void *)(uintptr_t)(((uintptr_t)(v45) & ~0xFFu) | ((uint8_t)(v42[3074] + 1) & 0xFFu));
    *((volatile uint16_t *)v42 + 4122) = v44;
    v42[3074] = (uint8_t)v45;
    v2[1] = v46;
    *((volatile uint8_t *)v2 + 14) = 1;
    *v2 = 0;
    v2[2] = v5 + 5;
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(volatile uint32_t *)off_10D96C = 1;
    }
    v47 = (volatile int *)off_10D970;
    v48 = dword_10D974;
    ++*(volatile uint32_t *)off_10D970;
    check_abort_flag(v48, v2);
    rf_calib_init();
    if ( *v47 )
    {
      v49 = *v47 - 1;
      v50 = *(volatile uint32_t *)off_10D96C;
      *v47 = v49;
      if ( !v49 )
      {
        if ( v50 )
          __enable_irq();
      }
    }
    goto LABEL_13;
  }
  v73 = aNoTxBuffer;
  v74 = (void *)(uintptr_t)(off_10DA5C);
  v75 = (volatile int *)off_10DA74;
  v5 = 110;
  do
  {
    while ( (*v74 & 0x80000) != 0 )
      ;
    *v75 = v5;
    v76 = (uint8_t)*++v73;
    v5 = v76;
  }
  while ( v76 );
  return v5;
}


// printf_wrapper @ 0x10da7c
/* luna: Forwards variadic arguments to the debug output formatter. */
int printf_wrapper(const volatile char *fmt, ...) {
  va_list varg_r1; // [sp+14h] [bp+8h] BYREF

  va_start(varg_r1, fmt);
  return debug_printf(fmt, (volatile unsigned int *)(*(void **)&(varg_r1)));
}


// irq_get_pending @ 0x10da98
void irq_get_pending() {
  volatile uint32_t *v0; // r4
  unsigned int v1; // r3
  signed int v2; // r3
  int v3; // r6
  int v4; // r0
  unsigned int v5; // r2
  void ( *v6)(int); // r1

  v0 = (void *)(uintptr_t)(off_10DAF4);
  v1 = *((volatile uint32_t *)off_10DAF4 + 8);
  if ( v1 )
  {
    v2 = 31 - __clz(v1);
    if ( v2 <= 7 )
    {
      v3 = dword_10DAF8;
      do
      {
        v0[9] = 1 << v2;
        __isb(0xFu);
        v6 = *(void ( **)(int))(v3 + 4 * v2);
        if ( v6 )
        {
          if ( ((v0[4] >> v2) & 1) != 0 )
            v4 = 2;
          else
            v4 = ((v0[5] >> v2) & 1) == 0;
          v6(v4 | (v2 << 16));
        }
        v5 = v0[8];
        v2 = 31 - __clz(v5);
      }
      while ( v5 && v2 <= 7 );
    }
  }
}



// irq_set_priority @ 0x10dafc
int irq_set_priority(int result) {
  volatile uint32_t *v1; // r1

  if ( result <= 7 )
  {
    v1 = (void *)(uintptr_t)(off_10DB28);
    ((volatile uint32_t *)(uintptr_t)0x40504080u)[result] &= 0xFFFFFFF0;
    result = (1 << result) | v1[1];
    v1[1] = result;
  }
  return result;
}



// gpio_clear_bit_reg8 @ 0x10db2c
/* luna: Clears the selected bit in the GPIO register at offset 8 and returns the bit mask. */
int gpio_clear_bit_reg8(char a1) {
  int result; // r0

  result = 1 << a1;
  *((volatile uint32_t *)off_10DB40 + 2) &= ~result;
  return result;
}



// gpio_set_bit_reg8 @ 0x10db44
/* luna: Sets the bit indexed by the argument in the GPIO register at offset 8 and returns the updated register value. */
int gpio_set_bit_reg8(char a1) {
  int result; // r0

  result = (1 << a1) | *((volatile uint32_t *)off_10DB54 + 2);
  *((volatile uint32_t *)off_10DB54 + 2) = result;
  return result;
}



// gpio_set_bit_reg0 @ 0x10db58
/* luna: Sets the bit indexed by the argument in GPIO register 0 and returns the updated register value. */
int gpio_set_bit_reg0(char a1) {
  int result; // r0

  result = (1 << a1) | *(volatile uint32_t *)off_10DB68;
  *(volatile uint32_t *)off_10DB68 = result;
  return result;
}



// gpio_clear_bit_reg0 @ 0x10db6c
/* luna: Clears the bit selected by bit_index in GPIO register 0 and returns its bit mask. */
int gpio_clear_bit_reg0(char a1) {
  int result; // r0

  result = 1 << a1;
  *(volatile uint32_t *)off_10DB80 &= ~result;
  return result;
}



// gpio_test_bit_reg0 @ 0x10db84
/* luna: Returns whether the GPIO register 0 bit selected by the bit index is set. */
BOOL gpio_test_bit_reg0(char a1) {
  return ((1 << a1) & *(volatile uint32_t *)off_10DB98) != 0;
}



// gpio_pin_config @ 0x10db9c
int gpio_pin_config(int result, int a2, int a3) {
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
    v4 = (void *)(uintptr_t)(off_10DC4C);
    ((volatile uint32_t *)(uintptr_t)0x40504080u)[result] &= 0xFFFFFFF0;
    v4[1] |= v3;
  }
  v5 = (void *)(uintptr_t)(off_10DC4C);
  *((volatile uint32_t *)off_10DC4C + 2) &= ~v3;
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
  v7 = (void *)(uintptr_t)(off_10DC4C);
  v8 = (void *)(uintptr_t)(off_10DC50);
  *((volatile uint32_t *)off_10DC4C + 9) = v3;
  v7[6] |= v3;
  v7[11] |= 7 << (result & 0xFC);
  v9 = (*(volatile uint32_t *)v8 & 0x800000) != 0;
  *(volatile uint32_t *)(dword_10DC54 + 4 * result) = a3;
  if ( !v9 )
  {
    result = dword_10DC5C;
    *(volatile uint32_t *)(*((volatile uint32_t *)off_10DC58 + 2) + 156) = dword_10DC5C;
    v8[791] = -4;
    *(volatile uint32_t *)v8 = 0x800000;
  }
  return result;
}



// gpio_write_pin2 @ 0x10dc60
/* luna: Sets GPIO pin 2 when the associated flag is nonzero, otherwise clears it. */
int gpio_write_pin2() {
  if ( *((volatile uint8_t *)off_10DC74 + 369) )
    return gpio_set_bit_reg0(2);
  else
    return gpio_clear_bit_reg0(2);
}



// check_radio_flag @ 0x10dc78
int check_radio_flag() {
  if ( *((volatile uint8_t *)off_10DC8C + 369) )
    return gpio_set_bit_reg0(1);
  else
    return gpio_clear_bit_reg0(1);
}



// set_radio_channel @ 0x10dc90
int set_radio_channel(int a1) {
  int v1; // r4
  int result; // r0
  BOOL v3; // r4
  int v4; // r5

  v1 = BYTE2(a1);
  result = printf_wrapper("wakeup:%d\n", BYTE2(a1));
  if ( v1 == 3 )
  {
    v3 = gpio_test_bit_reg0(3);
    if ( v3 )
    {
      v4 = 1;
    }
    else
    {
      if ( BYTE1(((volatile uint32_t *)(uintptr_t)off_10DCE4)[92]) )
        gpio_set_bit_reg0(2);
      else
        gpio_clear_bit_reg0(2);
      v4 = 2;
    }
    printf_wrapper("wkbt=%d\r\n", v3);
    return power_mode_set(v4);
  }
  return result;
}


// init_oscillators @ 0x10dcec
int init_oscillators() {
  volatile uint32_t *v0; // r1
  volatile uint32_t *v1; // r3
  int result; // r0

  irq_set_priority(1);
  gpio_set_bit_reg8(1);
  irq_set_priority(2);
  gpio_set_bit_reg8(2);
  if ( *((volatile uint8_t *)off_10DD4C + 369) )
  {
    gpio_set_bit_reg0(1);
    gpio_set_bit_reg0(2);
  }
  else
  {
    gpio_clear_bit_reg0(1);
    gpio_clear_bit_reg0(2);
  }
  gpio_clear_bit_reg8(3);
  gpio_pin_config(3, 2, dword_10DD50);
  v0 = (void *)(uintptr_t)(off_10DD54);
  v1 = (void *)(uintptr_t)(off_10DD5C);
  result = dword_10DD60;
  *((volatile uint32_t *)off_10DD54 + 1) = off_10DD58;
  v1[1] = result;
  v1[2] = 0;
  v0[2] = 0;
  return result;
}



// nullsub_1 @ 0x10dd64
int nullsub_1(void) {
  return 0;
}


// nullsub_2 @ 0x10dd68
int nullsub_2(void) {
  return 0;
}


// nullsub_3 @ 0x10dd6c
int nullsub_3(void) {
  return 0;
}


// set_pin_mux @ 0x10dd70
int set_pin_mux(int a1) {
  int v1; // r2
  int v2; // r0
  int v3; // r1

  v1 = dword_10DD98;
  v2 = 4 * a1;
  v3 = dword_10DD98 + 192;
  do
  {
    *(volatile uint32_t *)(v1 - 12) = *(volatile uint32_t *)(v1 - 12) & 0xFFFFFFF3 | v2;
    v1 += 12;
  }
  while ( v1 != v3 );
  return sub_102d10(1, 16, 0x10u, dword_10DD9C);
}



// gpio_init_1 @ 0x10dda0
unsigned int gpio_init_1() {
  volatile uint32_t *v0; // r0
  volatile uint32_t *v1; // r3
  int v2; // r1
  int v3; // r2
  uint64_t v4; // r0
  uint64_t v5; // r0
  uint64_t v6; // r0
  uint64_t v7; // r0

  v0 = (void *)(uintptr_t)(off_10DE38);
  v1 = (void *)(uintptr_t)(off_10DE3C);
  v2 = dword_10DE40;
  v3 = dword_10DE44;
  *(volatile uint32_t *)off_10DE3C = 0;
  v0[14] = 296;
  v1[2] = v1[2] & 0xF000FFFF | 0x2000000;
  v1[3] = v2 & v1[3] | 0xA06A000;
  v1[3] = v3 & v1[3] | 0x100230;
  v1[1] = 1;
  while ( v1[7] != 1 )
    ;
  v1[7] = 1;
  v4 = __aeabi_ui2d(v1[4]);
  v5 = ((uint64_t (*)())__aeabi_dmul)(v4, *(volatile uint64_t *)&dword_10DE20);
  v6 = ((uint64_t (*)())__aeabi_ddiv)(v5, *(volatile uint64_t *)&dword_10DE28);
  v7 = ((uint64_t (*)())__aeabi_dsub)(v6, *(volatile uint64_t *)&dword_10DE30);
  return ((int (*)(uint64_t))double_to_float)(v7);
}


// gpio_reset @ 0x10de48
int gpio_reset() {
  volatile uint32_t *v0; // r3
  volatile uint32_t *v1; // r0
  int v2; // r1
  int v3; // r2
  int result; // r0

  v0 = (void *)(uintptr_t)(off_10DE90);
  v1 = (void *)(uintptr_t)(off_10DE94);
  v2 = dword_10DE98;
  v3 = dword_10DE9C;
  *(volatile uint32_t *)off_10DE90 = 0;
  v1[14] = 296;
  v0[2] = v0[2] & 0xF000FFFF | 0x2000000;
  result = v0[3];
  v0[3] = v2 & result | 0xA06A000;
  v0[3] = v3 & v0[3] | 0x100230;
  v0[1] = 1;
  return result;
}



// wait_radio_ready @ 0x10dea0
unsigned int wait_radio_ready() {
  volatile uint32_t *v0; // r3
  uint64_t v1; // r0
  uint64_t v2; // r0
  uint64_t v3; // r0
  uint64_t v4; // r0

  while ( *((volatile uint32_t *)off_10DF00 + 7) != 1 )
    ;
  v0 = (void *)(uintptr_t)(off_10DF00);
  *((volatile uint32_t *)off_10DF00 + 7) = 1;
  v1 = __aeabi_ui2d(v0[4]);
  v2 = ((uint64_t (*)())__aeabi_dmul)(v1, *(volatile uint64_t *)&dword_10DEE8);
  v3 = ((uint64_t (*)())__aeabi_ddiv)(v2, *(volatile uint64_t *)&dword_10DEF0);
  v4 = ((uint64_t (*)())__aeabi_dsub)(v3, *(volatile uint64_t *)&dword_10DEF8);
  return ((int (*)(uint64_t))double_to_float)(v4);
}


// radio_setup @ 0x10df08
int radio_setup() {
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

  v0 = (void *)(uintptr_t)(off_10E028);
  set_pin_mux(1);
  v0[1] = 1;
  while ( v0[7] != 1 )
    ;
  v0[7] = 1;
  v1 = __aeabi_ui2d(v0[4]);
  v2 = ((uint64_t (*)())__aeabi_dmul)(v1, *(volatile uint64_t *)&dword_10E008);
  v3 = ((uint64_t (*)())__aeabi_ddiv)(v2, *(volatile uint64_t *)&dword_10E010);
  v4 = ((uint64_t (*)())__aeabi_dsub)(v3, *(volatile uint64_t *)&dword_10E008);
  v5 = ((int (*)(uint64_t))double_to_float)(v4);
  set_pin_mux(2);
  v6 = (void *)(uintptr_t)(off_10E028);
  v0[1] = 1;
  while ( v6[7] != 1 )
    ;
  v6[7] = 1;
  v7 = v6[4];
  set_pin_mux(3);
  v8 = __aeabi_ui2d(v7);
  v9 = ((uint64_t (*)())__aeabi_dmul)(v8, *(volatile uint64_t *)&dword_10E008);
  v10 = ((uint64_t (*)())__aeabi_ddiv)(v9, *(volatile uint64_t *)&dword_10E010);
  v11 = ((uint64_t (*)())__aeabi_dsub)(v10, *(volatile uint64_t *)&dword_10E008);
  v12 = ((int (*)(uint64_t))double_to_float)(v11);
  v13 = ((uint64_t (*)())__aeabi_f2d)(v12);
  v14 = ((uint64_t (*)())__aeabi_ddiv)(v13, *(volatile uint64_t *)&dword_10E018);
  v15 = (v15 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_10E02C) << 32);
  v15 = (v15 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v16 = ((uint64_t (*)())__aeabi_dmul)(v14, v15);
  v17 = ((uint64_t (*)())__aeabi_f2d)(v5);
  v18 = ((uint64_t (*)())__aeabi_ddiv)(v17, *(volatile uint64_t *)&dword_10E018);
  v19 = (v19 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_10E030) << 32);
  v19 = (v19 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v20 = ((uint64_t (*)())__aeabi_dmul)(v18, v19);
  v21 = __aeabi_dadd(v16, v20);
  v22 = (v22 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_10E034) << 32);
  v22 = (v22 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v23 = ((uint64_t (*)())__aeabi_dmul)(v21, v22);
  v24 = ((uint64_t (*)())__aeabi_dmul)(v23, *(volatile uint64_t *)&dword_10E020);
  v25 = (v25 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_10E038) << 32);
  v25 = (v25 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v26 = ((uint64_t (*)())__aeabi_ddiv)(v24, v25);
  return (int)COERCE_FLOAT(((int (*)(uint64_t))double_to_float)(v26));
}


// radio_enable @ 0x10e040
int radio_enable() {
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

  v0 = (void *)(uintptr_t)(off_10E0E8);
  *((volatile uint32_t *)off_10E0E8 + 1) = 1;
  while ( v0[7] != 1 )
    ;
  v0[7] = 1;
  v1 = __aeabi_ui2d(v0[4]);
  v2 = ((uint64_t (*)())__aeabi_dmul)(v1, *(volatile uint64_t *)&dword_10E0C8);
  v3 = ((uint64_t (*)())__aeabi_ddiv)(v2, *(volatile uint64_t *)&dword_10E0D0);
  v4 = ((uint64_t (*)())__aeabi_dsub)(v3, *(volatile uint64_t *)&dword_10E0C8);
  v5 = ((int (*)(uint64_t))double_to_float)(v4);
  v6 = ((uint64_t (*)())__aeabi_f2d)(v5);
  v7 = ((uint64_t (*)())__aeabi_ddiv)(v6, *(volatile uint64_t *)&dword_10E0D8);
  v8 = (v8 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_10E0EC) << 32);
  v8 = (v8 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v9 = ((uint64_t (*)())__aeabi_dmul)(v7, v8);
  v10 = (v10 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_10E0F0) << 32);
  v10 = (v10 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v11 = ((uint64_t (*)())__aeabi_dmul)(v9, v10);
  v12 = ((uint64_t (*)())__aeabi_dmul)(v11, *(volatile uint64_t *)&dword_10E0E0);
  v13 = (v13 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_10E0F4) << 32);
  v13 = (v13 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v14 = ((uint64_t (*)())__aeabi_ddiv)(v12, v13);
  return (int)COERCE_FLOAT(((int (*)(uint64_t))double_to_float)(v14));
}


// radio_init_1 @ 0x10e0f8
int radio_init_1() {
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

  v0 = dword_10E38C;
  v1 = (void *)(uintptr_t)(off_10E394);
  *((volatile uint32_t *)off_10E388 + 14) = 296;
  v1[3] = v0 | v1[3] & 0xE0000000;
  call_vector_1b8();
  v1[2] = dword_10E398 & v1[2] | 0x1200000F;
  v1[1] = 1;
  while ( v1[7] != 1 )
    ;
  v1[7] = 1;
  v2 = __aeabi_ui2d(v1[4]);
  v3 = ((uint64_t (*)())__aeabi_dmul)(v2, *(volatile uint64_t *)&dword_10E370);
  v4 = ((uint64_t (*)())__aeabi_dsub)(v3, *(volatile uint64_t *)&dword_10E378);
  v5 = ((uint64_t (*)())__aeabi_d2lz)(v4);
  ke_event_schedule_1("Initial    Volt:  %d mV\n", v5);
  v6 = jump_table_1b0();
  v7 = v5 - 1400;
  v8 = abs32(v5 - 1400);
  v9 = v6 & 0x3F;
  v38 = v9;
  if ( v8 > 49 )
  {
    v10 = __aeabi_i2d(v8);
    v11 = ((uint64_t (*)())__aeabi_dmul)(v10, *(volatile uint64_t *)&dword_10E380);
    v12 = ((uint64_t (*)())__aeabi_d2lz)(v11);
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
      call_vector_1b8();
      v15 = (void *)(uintptr_t)(off_10E394);
      *((volatile uint32_t *)off_10E394 + 1) = 1;
      while ( v15[7] != 1 )
        ;
      v15[7] = 1;
      v16 = __aeabi_ui2d(v15[4]);
      v17 = ((uint64_t (*)())__aeabi_dmul)(v16, *(volatile uint64_t *)&dword_10E370);
      v18 = ((uint64_t (*)())__aeabi_dsub)(v17, *(volatile uint64_t *)&dword_10E378);
      v5 = ((uint64_t (*)())__aeabi_d2lz)(v18);
      ke_event_schedule_1("step=%d, val=%d, volt=%d\n", v13, v14, v5);
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
  v21 = (void *)(uintptr_t)(off_10E394);
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
    call_vector_1b8();
    v21[1] = 1;
    while ( v21[7] != 1 )
      ;
    v21[7] = 1;
    v26 = __aeabi_ui2d(v21[4]);
    v27 = ((uint64_t (*)())__aeabi_dmul)(v26, *(volatile uint64_t *)&dword_10E370);
    v28 = ((uint64_t (*)())__aeabi_dsub)(v27, *(volatile uint64_t *)&dword_10E378);
    v37 = ((uint64_t (*)())__aeabi_d2lz)(v28);
    ke_event_schedule_1("ofst=%d, val=%d, volt=%d\n", v25, v23, v37);
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
  ke_event_schedule_1("reg_value_offset: %d\n", v25);
  call_vector_1b8();
  v31 = (void *)(uintptr_t)(off_10E394);
  *((volatile uint32_t *)off_10E394 + 1) = 1;
  while ( v31[7] != 1 )
    ;
  v31[7] = 1;
  v32 = __aeabi_ui2d(v31[4]);
  v33 = ((uint64_t (*)())__aeabi_dmul)(v32, *(volatile uint64_t *)&dword_10E370);
  v34 = ((uint64_t (*)())__aeabi_dsub)(v33, *(volatile uint64_t *)&dword_10E378);
  v35 = ((uint64_t (*)())__aeabi_d2lz)(v34);
  ke_event_schedule_1("Calibrated Volt:  %d mV\n", v35);
  return call_vector_1b8();
}


// system_init_mmio @ 0x10e3b8
int system_init_mmio() {
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

  v0 = (void *)(uintptr_t)(off_10E66C);
  v1 = dword_10E670;
  v2 = dword_10E674;
  *((volatile uint32_t *)off_10E668 + 14) = 296;
  v0[2] = v1 & v0[2] | 0x200000B;
  v0[3] = v2 | v0[3] & 0xE0000000;
  v0[1] = 1;
  while ( v0[7] != 1 )
    ;
  v0[7] = 1;
  v3 = __aeabi_ui2d(v0[4]);
  v4 = ((uint64_t (*)())__aeabi_dmul)(v3, *(volatile uint64_t *)&dword_10E650);
  v5 = ((uint64_t (*)())__aeabi_ddiv)(v4, *(volatile uint64_t *)&dword_10E658);
  v6 = ((uint64_t (*)())__aeabi_dsub)(v5, *(volatile uint64_t *)&dword_10E650);
  v7 = ((uint64_t (*)())__aeabi_d2lz)(v6);
  v8 = jump_table_1b0() & 0x1F;
  v9 = v7 - 840;
  printf_wrapper("Initl vcore Volt: %d mV, reg: %x\n", v7, v8);
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
    v11 = __aeabi_i2d(v10);
    v12 = ((uint64_t (*)())__aeabi_dmul)(v11, *(volatile uint64_t *)&dword_10E660);
    v13 = ((uint64_t (*)())__aeabi_d2lz)(v12);
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
    call_vector_1b8();
    v16 = (void *)(uintptr_t)(off_10E66C);
    *((volatile uint32_t *)off_10E66C + 1) = 1;
    while ( v16[7] != 1 )
      ;
    v16[7] = 1;
    v17 = __aeabi_ui2d(v16[4]);
    v18 = ((uint64_t (*)())__aeabi_dmul)(v17, *(volatile uint64_t *)&dword_10E650);
    v19 = ((uint64_t (*)())__aeabi_ddiv)(v18, *(volatile uint64_t *)&dword_10E658);
    v20 = ((uint64_t (*)())__aeabi_dsub)(v19, *(volatile uint64_t *)&dword_10E650);
    v7 = ((uint64_t (*)())__aeabi_d2lz)(v20);
    ke_event_schedule_1("step=%d, val=%x, volt=%d\n", v14, v15, v7);
    if ( v7 <= 840 )
      v21 = 1;
    else
      v21 = -1;
    v41 = v21;
  }
  v23 = (void *)(uintptr_t)(off_10E66C);
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
    call_vector_1b8();
    v23[1] = 1;
    while ( v23[7] != 1 )
      ;
    v23[7] = 1;
    v27 = __aeabi_ui2d(v23[4]);
    v28 = ((uint64_t (*)())__aeabi_dmul)(v27, *(volatile uint64_t *)&dword_10E650);
    v29 = ((uint64_t (*)())__aeabi_ddiv)(v28, *(volatile uint64_t *)&dword_10E658);
    v30 = ((uint64_t (*)())__aeabi_dsub)(v29, *(volatile uint64_t *)&dword_10E650);
    v31 = ((uint64_t (*)())__aeabi_d2lz)(v30);
    ke_event_schedule_1("ofst=%d, val=%x, volt=%d\n", v9, v24, v31);
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
  printf_wrapper("reg_value_offset: %d\n", v9);
  call_vector_1b8();
  v34 = (void *)(uintptr_t)(off_10E66C);
  *((volatile uint32_t *)off_10E66C + 1) = 1;
  while ( v34[7] != 1 )
    ;
  v34[7] = 1;
  v35 = __aeabi_ui2d(v34[4]);
  v36 = ((uint64_t (*)())__aeabi_dmul)(v35, *(volatile uint64_t *)&dword_10E650);
  v37 = ((uint64_t (*)())__aeabi_ddiv)(v36, *(volatile uint64_t *)&dword_10E658);
  v38 = ((uint64_t (*)())__aeabi_dsub)(v37, *(volatile uint64_t *)&dword_10E650);
  v39 = ((uint64_t (*)())__aeabi_d2lz)(v38);
  printf_wrapper("Calib vcore Volt: %d mV\n", v39);
  result = ((volatile uint32_t *)(uintptr_t)off_10E690)[94];
  if ( result != 0x80000000 )
    return rf_set_tx_power_1(result);
  return result;
}


// rf_pa_current_calibrate @ 0x10e694
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

  v4 = (volatile unsigned int *)off_10E834;
  v5 = (volatile unsigned int *)off_10E838;
  *(volatile uint32_t *)off_10E834 = *(volatile uint32_t *)off_10E834 & 0xFFFFFFF8 | a1 & 7;
  *v5 = ((uint16_t)a1 << 12) & 0x7000 | *v5 & 0xFFFF8FFF;
  *v4 = (8 * a2) & 0x78 | *v4 & 0xFFFFFF87;
  *v5 = (a2 << 15) & 0x78000 | *v5 & 0xFFF87FFF;
  v8 = (volatile int16_t *)off_10E83C;
  v9 = radio_setup();
  ke_event_schedule_1("cal start, reg_init=(%d,%d), i_pa_init=%d, i_pa_target=%d\n", a1, a2, v9, *v8);
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
  v11 = (volatile unsigned int *)off_10E834;
  v12 = (volatile unsigned int *)off_10E838;
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
    v9 = radio_setup();
    ke_event_schedule_1("reg_val_res=%d, reg_val_cgm=%d, i_pa=%d\n", v13, v3, v9);
    v16 = *(volatile int16_t *)off_10E83C;
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
  ke_event_schedule_1("cal done, offset_res=%d,(%d,%d), i_pa_res=%d\n", v20, v13 - v21, v3 - a2, v9);
LABEL_9:
  *a3 = v3;
  return v20;
}


// gpio_set_alternate @ 0x10e84c
int gpio_set_alternate(int a1) {
  volatile int16_t *v1; // r9
  int v2; // r7
  int v3; // r5
  int v4; // r3
  volatile unsigned int *v5; // r8
  int v6; // r6
  int v7; // r10
  int v8; // r2
  int v9; // r4
  int v10; // r3
  int v11; // r0
  int v12; // r3
  int v14; // r1
  int v15; // r2
  int v16; // [sp+0h] [bp-Ch]
  int v17; // [sp+4h] [bp-8h]

  v1 = (volatile int16_t *)off_10E968;
  *(volatile uint32_t *)off_10E95C = (a1 << 26) & 0x1C000000 | *(volatile uint32_t *)off_10E95C & 0xE3FFFFFF;
  v2 = a1;
  v3 = radio_enable();
  ke_event_schedule_1("cal start, reg_init=%d, i_pa_init=%d, i_pa_target=%d\n", v2, v3, *v1);
  v4 = *v1;
  if ( v4 > v3 )
  {
    v16 = 1;
  }
  else
  {
    if ( v4 >= v3 )
      return 0;
    v16 = -1;
  }
  v5 = (volatile unsigned int *)off_10E95C;
  v17 = v2;
  v6 = 4;
  v7 = 0;
  while ( 1 )
  {
    v2 += v16;
    if ( v2 <= 7 )
    {
      if ( v2 < 0 )
      {
        v2 = 0;
        v8 = 0;
        v7 = -v17;
      }
      else
      {
        v8 = v2 << 26;
        v7 += v16;
      }
    }
    else
    {
      v8 = 469762048;
      v7 = 7 - v17;
      v2 = 7;
    }
    *v5 = *v5 & 0xE3FFFFFF | v8;
    v9 = radio_enable();
    ke_event_schedule_1("reg_val=%d, i_pa=%d\n", v2, v9);
    v10 = *v1;
    v11 = v9 - v10;
    v12 = v3 - v10;
    if ( v12 * v11 <= 0 )
      break;
    --v6;
    v3 = v9;
    if ( !v6 )
      return v7;
  }
  v14 = v12;
  if ( v12 < 0 )
    v14 = -v12;
  if ( v11 < 0 )
    v11 = -v11;
  v15 = v9;
  if ( v14 <= v11 )
  {
    v7 -= v16;
    v15 = v3;
    *v5 = ((v2 - v16) << 26) & 0x1C000000 | *v5 & 0xE3FFFFFF;
  }
  ke_event_schedule_1("cal done, offset_res=%d, i_pa_res=%d\n", v7, v15);
  return v7;
}


// board_init @ 0x10e970
/* luna: Initializes board-specific MMIO settings and GPIO configuration, temporarily changing control-register bits while setting pin 4 to mode 8. */
int board_init(int a1) {
  volatile uint32_t *v1; // r2
  int v2; // r7
  int v3; // r3
  volatile uint32_t *v4; // r5
  volatile uint32_t *v5; // r10
  int v6; // r6
  volatile unsigned int *pin_mode_ctrl_reg; // r4
  volatile int *v8; // r1
  int v9; // r0
  unsigned int saved_ctrl_bit_19; // r9
  unsigned int saved_ctrl_bit_20; // r8
  unsigned int saved_ctrl_bit_21; // r7
  unsigned int saved_ctrl_bit_22; // r6
  int result; // r0
  struct __attribute__((packed)) { uint16_t a1a[2]; // [sp+Ch] [bp-Ch] BYREF
  int v17; // [sp+10h] [bp-8h]
  uint16_t v18; // [sp+14h] [bp-4h]
  } _frame;
  v1 = (void *)(uintptr_t)(off_10EA74);
  v2 = dword_10EA78;
  v3 = dword_10EA7C;
  v4 = (void *)(uintptr_t)(off_10EA80);
  v5 = (void *)(uintptr_t)(off_10EA98);
  v6 = dword_10EA84;
  pin_mode_ctrl_reg = (volatile unsigned int *)off_10EA88;
  _frame.v18 = 0;
  *((volatile uint32_t *)off_10EA94 + 14) = 296;
  v1[3] = v1[3] & 0xE0000000 | v2;
  v1[2] = v3 & v1[2] | 0x1200000D;
  *v4 |= 2u;
  *v4 &= ~1u;
  *(volatile uint32_t *)_frame.a1a = v6;
  _frame.v17 = 5610;
  phy_set_channel(_frame.a1a, 0);
  v8 = (volatile int *)off_10EA8C;
  v9 = dword_10EA90;
  *v5 |= 0x80000000;
  *v8 = v9;
  saved_ctrl_bit_19 = *pin_mode_ctrl_reg;
  saved_ctrl_bit_20 = *pin_mode_ctrl_reg;
  saved_ctrl_bit_21 = *pin_mode_ctrl_reg;
  saved_ctrl_bit_22 = *pin_mode_ctrl_reg;
  *pin_mode_ctrl_reg &= ~0x80000u;
  *pin_mode_ctrl_reg |= 0x100000u;
  *pin_mode_ctrl_reg |= 0x200000u;
  *pin_mode_ctrl_reg |= 0x400000u;
  result = rf_pa_current_calibrate(4u, 8u, (volatile unsigned int *)a1);
  *v5 &= ~0x80000000;
  *v4 &= ~2u;
  *pin_mode_ctrl_reg = saved_ctrl_bit_19 & 0x80000 | *pin_mode_ctrl_reg & 0xFFF7FFFF;
  *pin_mode_ctrl_reg = saved_ctrl_bit_20 & 0x100000 | *pin_mode_ctrl_reg & 0xFFEFFFFF;
  *pin_mode_ctrl_reg = saved_ctrl_bit_21 & 0x200000 | *pin_mode_ctrl_reg & 0xFFDFFFFF;
  *pin_mode_ctrl_reg = saved_ctrl_bit_22 & 0x400000 | *pin_mode_ctrl_reg & 0xFFBFFFFF;
  return result;
}


// board_init_2 @ 0x10ea9c
int board_init_2() {
  volatile unsigned int *v0; // r4
  volatile uint32_t *v1; // r2
  int v2; // r0
  int v3; // r3
  volatile uint32_t *v4; // r9
  volatile uint32_t *v5; // r6
  volatile uint32_t *v6; // r10
  int v7; // r5
  volatile int *v8; // r2
  int v9; // r1
  unsigned int v10; // r8
  unsigned int v11; // r7
  unsigned int v12; // r6
  unsigned int v13; // r5
  int result; // r0
  struct __attribute__((packed)) { uint16_t a1[2]; // [sp+4h] [bp-Ch] BYREF
  int v16; // [sp+8h] [bp-8h]
  uint16_t v17; // [sp+Ch] [bp-4h]
  } _frame;
  v0 = (volatile unsigned int *)off_10EB9C;
  v1 = (void *)(uintptr_t)(off_10EBA0);
  v2 = dword_10EBA4;
  v3 = dword_10EBA8;
  v4 = (void *)(uintptr_t)(off_10EBBC);
  v5 = (void *)(uintptr_t)(off_10EBAC);
  v6 = (void *)(uintptr_t)(off_10EBC0);
  v7 = dword_10EBB0;
  _frame.v17 = 0;
  *((volatile uint32_t *)off_10EB9C + 14) = 296;
  v1[3] = v2 | v1[3] & 0xE0000000;
  v1[2] = v3 & v1[2] | 0x1200000D;
  *v4 |= 0x20000000u;
  *v5 &= ~1u;
  *(volatile uint32_t *)_frame.a1 = v7;
  _frame.v16 = 2442;
  phy_set_channel(_frame.a1, 0);
  v8 = (volatile int *)off_10EBB4;
  v9 = dword_10EBB8;
  v0 += 593954;
  *v6 |= 0x80000000;
  *v8 = v9;
  v10 = *v0;
  v11 = *v0;
  v12 = *v0;
  v13 = *v0;
  *v0 &= ~0x80000u;
  *v0 |= 0x100000u;
  *v0 |= 0x200000u;
  *v0 |= 0x400000u;
  result = gpio_set_alternate(4);
  *v6 &= ~0x80000000;
  *v4 &= ~0x20000000u;
  *v0 = v10 & 0x80000 | *v0 & 0xFFF7FFFF;
  *v0 = v11 & 0x100000 | *v0 & 0xFFEFFFFF;
  *v0 = v12 & 0x200000 | *v0 & 0xFFDFFFFF;
  *v0 = v13 & 0x400000 | *v0 & 0xFFBFFFFF;
  return result;
}


// jump_table_1b0 @ 0x10ebc4
int jump_table_1b0() {
  return ((int (*)())MEMD(0x1B0))();
}



// jump_table_1b4 @ 0x10ebcc
int jump_table_1b4() {
  return ((int (*)())MEMD(0x1B4))();
}



// call_vector_1b8 @ 0x10ebd4
int call_vector_1b8() {
  return ((int (*)())MEMD(0x1B8))();
}



// atomic_reg_read @ 0x10ebdc
int atomic_reg_read(int a1, int a2) {
  volatile int *v2; // r5
  volatile uint32_t *v3; // r4
  int result; // r0
  int v5; // r3
  int v6; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_10EC24 = 1;
  }
  v2 = (volatile int *)off_10EC28;
  ++*(volatile uint32_t *)off_10EC28;
  if ( a2 )
  {
    v3 = (void *)(uintptr_t)(off_10EC2C);
    while ( !*(volatile uint32_t *)off_10EC2C )
      ;
    result = jump_table_1b0();
    *v3 = 1;
  }
  else
  {
    result = jump_table_1b0();
  }
  if ( *v2 )
  {
    v5 = *v2 - 1;
    v6 = *(volatile uint32_t *)off_10EC24;
    *v2 = v5;
    if ( !v5 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
  return result;
}



// atomic_reg_read_alt @ 0x10ec30
int atomic_reg_read_alt(int a1, int a2, int a3) {
  volatile int *v3; // r5
  volatile uint32_t *v4; // r4
  int result; // r0
  int v6; // r3
  int v7; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_10EC78 = 1;
  }
  v3 = (volatile int *)off_10EC7C;
  ++*(volatile uint32_t *)off_10EC7C;
  if ( a3 )
  {
    v4 = (void *)(uintptr_t)(off_10EC80);
    while ( !*(volatile uint32_t *)off_10EC80 )
      ;
    result = jump_table_1b4();
    *v4 = 1;
  }
  else
  {
    result = jump_table_1b4();
  }
  if ( *v3 )
  {
    v6 = *v3 - 1;
    v7 = *(volatile uint32_t *)off_10EC78;
    *v3 = v6;
    if ( !v6 )
    {
      if ( v7 )
        __enable_irq();
    }
  }
  return result;
}



// atomic_reg_write @ 0x10ec84
int atomic_reg_write(int a1, int a2, int a3, int a4) {
  volatile int *v4; // r5
  volatile uint32_t *v5; // r4
  int result; // r0
  int v7; // r3
  int v8; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_10ECCC = 1;
  }
  v4 = (volatile int *)off_10ECD0;
  ++*(volatile uint32_t *)off_10ECD0;
  if ( a4 )
  {
    v5 = (void *)(uintptr_t)(off_10ECD4);
    while ( !*(volatile uint32_t *)off_10ECD4 )
      ;
    result = call_vector_1b8();
    *v5 = 1;
  }
  else
  {
    result = call_vector_1b8();
  }
  if ( *v4 )
  {
    v7 = *v4 - 1;
    v8 = *(volatile uint32_t *)off_10ECCC;
    *v4 = v7;
    if ( !v7 )
    {
      if ( v8 )
        __enable_irq();
    }
  }
  return result;
}



// periph_trigger_write @ 0x10ecd8
int periph_trigger_write(int a1) {
  ke_event_schedule_1("Reboot:%x\n", a1);
  atomic_reg_write(dword_10ED24, 196608, dword_10ED20, 1);
  atomic_reg_write(1879048192, 1, 1, 1);
  atomic_reg_read_alt(dword_10ED28, a1, 1);
  return atomic_reg_write(dword_10ED2C, 2, 2, 1);
}


// periph_field_set @ 0x10ed30
int periph_field_set(int a1) {
  atomic_reg_write(dword_10ED64, 196608, dword_10ED60, 1);
  atomic_reg_read_alt(dword_10ED68, a1 << 15, 1);
  return atomic_reg_write(1879048192, 1, 1, 1);
}



