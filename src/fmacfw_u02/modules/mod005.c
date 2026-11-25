// read_global_halfword @ 0x10d414
int read_global_halfword(int a1, int a2, int a3) {
  volatile int *v6; // r1
  int result; // r0
  int v8; // r12
  int v9; // lr
  int v10; // r9
  int v11; // r3
  volatile int *v12; // r3
  int v13; // r3

  if ( **(volatile int16_t **)off_10D590 < 0 && a3 > 13 )
    mmio_clear_register(dword_10D5A0, dword_10D59C, 69);
  *(volatile uint32_t *)(a2 + 32) = 0;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_10D594 = 1;
  }
  v6 = (volatile int *)off_10D598;
  result = *(volatile uint32_t *)off_10D598;
  v8 = *(volatile uint32_t *)off_10D598 + 1;
  ((volatile uint32_t *)(uintptr_t)0x40021000u)[16 * a3] |= 1u;
  *v6 = v8;
while ( (((volatile uint32_t *)(uintptr_t)0x40021000u)[16 * a3] & 0x10000) == 0 ) ;
  v9 = dword_10D5A4;
  v10 = *(volatile uint32_t *)(dword_10D5A4 + 4 * a3);
if ( v10 && (((volatile uint32_t *)(uintptr_t)0x40021000u)[16 * a3 + 3] & 0x800) == 0 ) { if ( (((volatile uint32_t *)(uintptr_t)0x40021000u)[16 * a3 + 6] & 0x80000) != 0 ) { ((volatile uint32_t *)(uintptr_t)0x40021000u)[16 * a3 + 6] &= ~0x80000u;
      ((volatile uint32_t *)(uintptr_t)0x40021000u)[16 * a3 + 12] = a1;
    }
    *(volatile uint32_t *)(v10 + 8) &= ~0x80000u;
    *(volatile uint32_t *)(v10 + 32) = a1;
  }
  else
  {
    ((volatile uint32_t *)(uintptr_t)0x40021000u)[16 * a3 + 2] = dword_10D5A8;
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
    v12 = (volatile int *)off_10D594;
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



// rf_tx_config @ 0x10d5ac
int rf_tx_config() {
  int v0; // r3
  int result; // r0

  v0 = *((volatile uint32_t *)off_10D5D0 + 3);
  if ( (v0 & 0x8000) != 0 )
    *((volatile uint32_t *)off_10D5D0 + 2) = 0x800000;
  if ( (v0 & 0x400) != 0 )
  {
    *((volatile uint32_t *)off_10D5D0 + 2) = 0x40000;
    return unknown_func_12d104(0x20000000);
  }
  return result;
}



// rf_get_lock_status @ 0x10d5d4
int rf_get_lock_status() {
  volatile unsigned int *v0; // r2
  unsigned int v1; // r3
  int result; // r0
  volatile uint32_t *v3; // r3

  v0 = (volatile unsigned int *)off_10D618;
  v1 = *(volatile uint32_t *)off_10D618;
  if ( (*(volatile uint32_t *)off_10D618 & 1) == 0 )
  {
    v1 = v1 & 0xFFFFFCFE | 0x101;
    result = 17;
    *((volatile uint32_t *)off_10D618 + 4) = 0;
    v0[5] = 0;
    v0[1] = 17;
    *v0 = v1;
  }
  if ( (v1 & 0x4000) == 0 )
    *(volatile uint32_t *)off_10D618 = v1 | 0x4040;
  v3 = (void *)(uintptr_t)(off_10D620);
  *(volatile uint32_t *)(*((volatile uint32_t *)off_10D61C + 2) + 148) = dword_10D624;
  *v3 = 0x200000;
  return result;
}



// irq_install_handler @ 0x10d628
void irq_install_handler() {
  volatile uint32_t *v0; // r3

  v0 = (void *)(uintptr_t)(off_10D640);
  *(volatile uint32_t *)(*((volatile uint32_t *)off_10D63C + 2) + 148) = dword_10D644;
  *v0 = 0x200000;
}



// is_initialized @ 0x10d648
void is_initialized() {
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

  v0 = *((volatile uint32_t *)off_10D734 + 43);
  if ( v0 >= 0 )
  {
    if ( *(volatile uint32_t *)off_10D738 )
    {
      v21 = (void *)(uintptr_t)(off_10D760);
      v22 = (void *)(uintptr_t)(off_10D764);
      v23 = dword_10D768;
      *(volatile uint32_t *)off_10D740 = 1;
      *(volatile uint32_t *)(v21[2] + 124) = v23;
      *v22 = 0x8000;
    }
  }
  else if ( *(volatile uint32_t *)off_10D738 )
  {
    v1 = (void *)(uintptr_t)(off_10D740);
    v2 = (void *)(uintptr_t)(off_10D744);
    v3 = (void *)(uintptr_t)(off_10D748);
    *(volatile uint32_t *)off_10D73C = 0;
    *v1 = 0;
    *v2 = 1;
    v4 = (void *)(uintptr_t)(off_10D74C);
    v5 = (void *)(uintptr_t)(off_10D750);
    *v3 |= 0x100u;
    *v4 = 3;
    v6 = v0 & 0x7FFFFFFF;
    if ( (v5[20] & 0x20) != 0 )
    {
      v7 = *(volatile uint32_t *)off_10D770;
      if ( v6 < *(volatile uint32_t *)off_10D770 >> 4 )
        goto LABEL_5;
    }
    else
    {
      v7 = 2 * *(volatile uint32_t *)off_10D754;
      if ( v6 < v7 >> 4 )
      {
LABEL_5:
        v8 = v7 / v6;
        v9 = (uint8_t)(v8 >> 4);
        v10 = ((v8 >> 1) & 7) + 16 * ((v8 & 0xF) - ((v8 >> 1) & 7));
        v11 = (uint8_t)(v8 >> 12);
LABEL_6:
        v12 = (void *)(uintptr_t)(off_10D74C);
        v13 = (void *)(uintptr_t)(off_10D740);
        v14 = (volatile int *)off_10D758;
        v15 = (volatile int *)off_10D75C;
        *(volatile uint32_t *)off_10D74C |= 0x80u;
        *v15 = v9;
        *v13 = v11;
        *v14 = v10;
        v16 = (void *)(uintptr_t)(off_10D73C);
        v17 = (volatile unsigned int *)off_10D744;
        v18 = (void *)(uintptr_t)(off_10D760);
        *v12 &= ~0x80u;
        *v16 = 7;
        v19 = (void *)(uintptr_t)(off_10D764);
        v20 = dword_10D768;
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
  *(volatile uint32_t *)off_10D76C = 1;
}



// nvic_configure @ 0x10d774
void nvic_configure() {
  if ( !*(volatile uint32_t *)off_10D780 )
    is_initialized();
}



// nvic_set_priority @ 0x10d784
void nvic_set_priority() {
  *((volatile uint32_t *)off_10D798 + 32) = 0x8000;
  __dsb(0xFu);
  __isb(0xFu);
}



// gpio_write_1 @ 0x10d79c
int gpio_write_1(int result) {
  while ( (*(volatile uint32_t *)off_10D7AC & 0x80000) != 0 )
    ;
  *(volatile uint32_t *)off_10D7B0 = result;
  return result;
}



// read_memory_byte @ 0x10d7b4
volatile uint8_t * read_memory_byte(volatile uint8_t *result) {
  int v1; // r1
  volatile uint32_t *v2; // r2
  volatile uint32_t *v3; // r4
  int v4; // t1

  v1 = (uint8_t)*result;
  if ( *result )
  {
    v2 = (void *)(uintptr_t)(off_10D7D8);
    v3 = (void *)(uintptr_t)(off_10D7DC);
    do
    {
      while ( (*v2 & 0x80000) != 0 )
        ;
      *v3 = v1;
      v4 = (uint8_t)*++result;
      v1 = v4;
    }
    while ( v4 );
  }
  return result;
}



// gpio_read @ 0x10d7e0
int gpio_read() {
  while ( (*(volatile uint32_t *)off_10D7F0 & 1) == 0 )
    ;
  return (uint8_t)*(volatile uint32_t *)off_10D7F4;
}



// gpio_read_pin @ 0x10d7f8
int gpio_read_pin() {
  return *(volatile uint32_t *)off_10D804 & 1;
}



// prepare_debug_buffer @ 0x10d808
int prepare_debug_buffer(volatile uint8_t *a1, volatile unsigned int *a2) {
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
  v4 = rf_cal_init(_frame.a1a, 256, 0, a1, a2);
  v5 = v4;
  if ( v4 <= 0 )
    return v5;
  v6 = v4;
  if ( *(volatile uint32_t *)off_10DAD4 )
  {
    if ( CPSR )
      goto LABEL_5;
  }
  else
  {
    is_initialized();
    if ( CPSR )
      goto LABEL_5;
  }
  while ( !*(volatile uint32_t *)off_10DAD8 )
    ;
LABEL_5:
  if ( !*(volatile uint32_t *)off_10DADC )
  {
    while ( (*(volatile uint32_t *)off_10DAE0 & 0x80000) != 0 )
      ;
    *(volatile uint32_t *)off_10DAE4 = 95;
  }
  v7 = HIWORD(((volatile uint32_t *)(uintptr_t)off_10DAE8)[44]) & 0x4000;
  if ( (((volatile uint32_t *)(uintptr_t)off_10DAE8)[44] & 0x40000000) == 0 )
  {
    v8 = _frame.a1a;
    v9 = (void *)(uintptr_t)(off_10DAE0);
    v10 = (void *)(uintptr_t)(off_10DAE4);
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
  v15 = **(volatile uint8_t **)off_10DAEC;
  if ( v15 == 1 )
  {
    v22 = **(volatile uint8_t **)off_10DAF4;
    if ( v22 != 3 )
    {
      if ( v6 >= 124 )
        v6 = (v6 & ~0xFFFFu) | ((uint16_t)(124) & 0xFFFFu);
      mutex_lock(19, _frame.a1a, (uint16_t)v6, v22);
    }
    goto LABEL_13;
  }
  if ( v15 != 2 )
    goto LABEL_13;
  v16 = (volatile uint8_t **)off_10DAF4;
  if ( **(volatile uint8_t **)off_10DAF4 == 3 )
  {
LABEL_19:
    v17 = aNoActive;
    v18 = (void *)(uintptr_t)(off_10DAE0);
    v19 = (volatile int *)off_10DAE4;
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
  if ( (unsigned int)read_u32((volatile uint32_t **)dword_10DAF8) <= 4 )
  {
    if ( **(volatile uint8_t **)off_10DAEC == 2 )
    {
      if ( **v16 != 3 )
      {
        if ( (unsigned int)read_u32((volatile uint32_t **)dword_10DAF8) > 4 )
        {
          v57 = aOtherErr;
          v58 = (void *)(uintptr_t)(off_10DAE0);
          v59 = (volatile int *)off_10DAE4;
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
          v53 = (void *)(uintptr_t)(off_10DAE0);
          v54 = (volatile int *)off_10DAE4;
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
      *(volatile uint32_t *)off_10DAD8 = 1;
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
      v25 = (void *)(uintptr_t)(off_10DB2C);
      goto LABEL_37;
    }
  }
  v62 = aFoundPanic;
  v63 = (void *)(uintptr_t)(off_10DC04);
  v64 = (volatile int *)off_10DC1C;
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
  v25 = (void *)(uintptr_t)(off_10DC20);
  v67 = *(volatile uint32_t *)off_10DC08;
  _frame.v78 = (volatile int *)off_10DC0C;
  v68 = *(volatile uint64_t *)(v67 + 4);
  v69 = *(int ( **)(uint32_t))(HIDWORD(v68) + 16);
  *(volatile uint8_t *)off_10DC20 = 1;
  v70 = v69(v68);
  v71 = (void *)(uintptr_t)(off_10DC10);
  *_frame.v78 = v70;
  *v71 = 4;
LABEL_37:
  if ( *v25 )
  {
    v26 = (void *)(uintptr_t)(off_10DB30);
    if ( !memcmp((unsigned int)_frame.a1a, (unsigned int)aPanic, 5u) )
    {
      v27 = aPanicEnd;
      v28 = (void *)(uintptr_t)(off_10DAE0);
      v29 = (volatile int *)off_10DAE4;
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
    v32 = (volatile uint16_t *)off_10DB34;
    v33 = *(volatile uint16_t *)off_10DB34;
    if ( v33 + v6 <= 1720 )
    {
      _frame.v78 = (volatile int *)off_10DC0C;
      memcpy((volatile char *)(*(volatile uint32_t *)off_10DC0C + v33), _frame.a1a, v6);
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
      v35 = (void *)(uintptr_t)(off_10DAE0);
      v36 = (volatile int *)off_10DAE4;
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
      v39 = (volatile char **)off_10DB08;
    }
    v40 = dword_10DAF8;
    *v25 = 0;
    *v26 = 0;
    v41 = *v39;
    *v32 = 4;
    *v39 = nullptr;
    v5 = v33;
    mem_word_load(v40);
    goto LABEL_48;
  }
  v2 = mem_word_load(dword_10DC14);
  if ( v6 <= 122 )
    v41 = (volatile char *)error_trap();
  else
    v41 = (volatile char *)(*(int ( **)(uint32_t))(*(volatile uint32_t *)(*(volatile uint32_t *)off_10DC08 + 8) + 16))(*(volatile uint32_t *)(*(volatile uint32_t *)off_10DC08 + 4));
  if ( v41 )
  {
    memcpy(v41 + 4, _frame.a1a, v6);
    v33 = (v33 & ~0xFFFFu) | ((uint16_t)(v6) & 0xFFFFu);
LABEL_48:
    *(volatile uint16_t *)v41 = v5 + 1;
    v41[2] = 19;
    v42 = 0;
    v43 = (void *)(uintptr_t)(off_10DB0C);
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
    v46 = (void *)(uintptr_t)(off_10DB10);
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
      *(volatile uint32_t *)off_10DB14 = 1;
    }
    v48 = (volatile int *)off_10DB18;
    v49 = dword_10DB1C;
    ++*(volatile uint32_t *)off_10DB18;
    cmd_handler_a(v49, v2);
    check_init_flag();
    if ( *v48 )
    {
      v50 = *v48 - 1;
      v51 = *(volatile uint32_t *)off_10DB14;
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
  v75 = (void *)(uintptr_t)(off_10DC04);
  v76 = (volatile int *)off_10DC1C;
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


// log_printf @ 0x10dc24
int log_printf(const volatile char *fmt, ...) {
  va_list varg_r1; // [sp+14h] [bp+8h] BYREF

  va_start(varg_r1, fmt);
  return prepare_debug_buffer(fmt, (volatile unsigned int *)(*(void **)&(varg_r1)));
}


// rf_get_int_status @ 0x10dc40
void rf_get_int_status() {
  volatile uint32_t *v0; // r4
  unsigned int v1; // r3
  signed int v2; // r3
  int v3; // r6
  int v4; // r0
  unsigned int v5; // r2
  void ( *v6)(int); // r1

  v0 = (void *)(uintptr_t)(off_10DC9C);
  v1 = *((volatile uint32_t *)off_10DC9C + 8);
  if ( v1 )
  {
    v2 = 31 - __clz(v1);
    if ( v2 <= 7 )
    {
      v3 = dword_10DCA0;
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



// switch_on_arg @ 0x10dca4
int switch_on_arg(int result) {
  volatile uint32_t *v1; // r1

  if ( result <= 7 )
  {
    v1 = (void *)(uintptr_t)(off_10DCD0);
    ((volatile uint32_t *)(uintptr_t)0x40504080u)[result] &= 0xFFFFFFF0;
    result = (1 << result) | v1[1];
    v1[1] = result;
  }
  return result;
}



// rf_disable_irq @ 0x10dcd4
int rf_disable_irq(char a1) {
  int result; // r0

  result = 1 << a1;
  *((volatile uint32_t *)off_10DCE8 + 2) &= ~result;
  return result;
}



// rf_enable_irq @ 0x10dcec
int rf_enable_irq(char a1) {
  int result; // r0

  result = (1 << a1) | *((volatile uint32_t *)off_10DCFC + 2);
  *((volatile uint32_t *)off_10DCFC + 2) = result;
  return result;
}



// gpio_set_bit @ 0x10dd00
int gpio_set_bit(char a1) {
  int result; // r0

  result = (1 << a1) | *(volatile uint32_t *)off_10DD10;
  *(volatile uint32_t *)off_10DD10 = result;
  return result;
}



// gpio_clear_bit @ 0x10dd14
int gpio_clear_bit(char a1) {
  int result; // r0

  result = 1 << a1;
  *(volatile uint32_t *)off_10DD28 &= ~result;
  return result;
}



// gpio_read_bit @ 0x10dd2c
BOOL gpio_read_bit(char a1) {
  return ((1 << a1) & *(volatile uint32_t *)off_10DD40) != 0;
}



// gpio_configure_pin @ 0x10dd44
int gpio_configure_pin(int result, int a2, int a3) {
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
    v4 = (void *)(uintptr_t)(off_10DDF4);
    ((volatile uint32_t *)(uintptr_t)0x40504080u)[result] &= 0xFFFFFFF0;
    v4[1] |= v3;
  }
  v5 = (void *)(uintptr_t)(off_10DDF4);
  *((volatile uint32_t *)off_10DDF4 + 2) &= ~v3;
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
  v7 = (void *)(uintptr_t)(off_10DDF4);
  v8 = (void *)(uintptr_t)(off_10DDF8);
  *((volatile uint32_t *)off_10DDF4 + 9) = v3;
  v7[6] |= v3;
  v7[11] |= 7 << (result & 0xFC);
  v9 = (*(volatile uint32_t *)v8 & 0x800000) != 0;
  *(volatile uint32_t *)(dword_10DDFC + 4 * result) = a3;
  if ( !v9 )
  {
    result = dword_10DE04;
    *(volatile uint32_t *)(*((volatile uint32_t *)off_10DE00 + 2) + 156) = dword_10DE04;
    v8[791] = -4;
    *(volatile uint32_t *)v8 = 0x800000;
  }
  return result;
}



// util_get_struct_offset @ 0x10de08
int util_get_struct_offset() {
  if ( *((volatile uint8_t *)off_10DE1C + 369) )
    return gpio_set_bit(2);
  else
    return gpio_clear_bit(2);
}



// util_get_struct_offset_alt @ 0x10de20
int util_get_struct_offset_alt() {
  if ( *((volatile uint8_t *)off_10DE34 + 369) )
    return gpio_set_bit(1);
  else
    return gpio_clear_bit(1);
}



// ble_phy_decode @ 0x10de38
int ble_phy_decode(int a1) {
  int v1; // r4
  int result; // r0
  BOOL v3; // r4
  int v4; // r5

  v1 = BYTE2(a1);
  result = log_printf("wakeup:%d\n", BYTE2(a1));
  if ( v1 == 3 )
  {
    v3 = gpio_read_bit(3);
    if ( v3 )
    {
      v4 = 1;
    }
    else
    {
      if ( BYTE1(((volatile uint32_t *)(uintptr_t)off_10DE8C)[92]) )
        gpio_set_bit(2);
      else
        gpio_clear_bit(2);
      v4 = 2;
    }
    log_printf("wkbt=%d\r\n", v3);
    return check_arg_one(v4);
  }
  return result;
}


// gpio_init_sequence @ 0x10de94
int gpio_init_sequence() {
  volatile uint32_t *v0; // r1
  volatile uint32_t *v1; // r3
  int result; // r0

  switch_on_arg(1);
  rf_enable_irq(1);
  switch_on_arg(2);
  rf_enable_irq(2);
  if ( *((volatile uint8_t *)off_10DEF4 + 369) )
  {
    gpio_set_bit(1);
    gpio_set_bit(2);
  }
  else
  {
    gpio_clear_bit(1);
    gpio_clear_bit(2);
  }
  rf_disable_irq(3);
  gpio_configure_pin(3, 2, dword_10DEF8);
  v0 = (void *)(uintptr_t)(off_10DEFC);
  v1 = (void *)(uintptr_t)(off_10DF04);
  result = dword_10DF08;
  *((volatile uint32_t *)off_10DEFC + 1) = off_10DF00;
  v1[1] = result;
  v1[2] = 0;
  v0[2] = 0;
  return result;
}



// nullsub_1 @ 0x10df0c
int nullsub_1(void) {
  return 0;
}


// nullsub_2 @ 0x10df10
int nullsub_2(void) {
  return 0;
}


// nullsub_3 @ 0x10df14
int nullsub_3(void) {
  return 0;
}


// rf_ctrl_config_set @ 0x10df18
int rf_ctrl_config_set(int a1) {
  int v1; // r2
  int v2; // r0
  int v3; // r1

  v1 = dword_10DF40;
  v2 = 4 * a1;
  v3 = dword_10DF40 + 192;
  do
  {
    *(volatile uint32_t *)(v1 - 12) = *(volatile uint32_t *)(v1 - 12) & 0xFFFFFFF3 | v2;
    v1 += 12;
  }
  while ( v1 != v3 );
  return peripheral_read_32(1, 16, 0x10u, dword_10DF44);
}



// rf_core_reset @ 0x10df48
unsigned int rf_core_reset() {
  volatile uint32_t *v0; // r0
  volatile uint32_t *v1; // r3
  int v2; // r1
  int v3; // r2
  uint64_t v4; // r0
  uint64_t v5; // r0
  uint64_t v6; // r0
  uint64_t v7; // r0

  v0 = (void *)(uintptr_t)(off_10DFE0);
  v1 = (void *)(uintptr_t)(off_10DFE4);
  v2 = dword_10DFE8;
  v3 = dword_10DFEC;
  *(volatile uint32_t *)off_10DFE4 = 0;
  v0[14] = 296;
  v1[2] = v1[2] & 0xF000FFFF | 0x2000000;
  v1[3] = v2 & v1[3] | 0xA06A000;
  v1[3] = v3 & v1[3] | 0x100230;
  v1[1] = 1;
  while ( v1[7] != 1 )
    ;
  v1[7] = 1;
  v4 = uint_to_double(v1[4]);
  v5 = ((uint64_t (*)())double_add_1)(v4, *(volatile uint64_t *)&dword_10DFC8);
  v6 = ((uint64_t (*)())double_subtract)(v5, *(volatile uint64_t *)&dword_10DFD0);
  v7 = ((uint64_t (*)())double_compare_wrapper)(v6, *(volatile uint64_t *)&dword_10DFD8);
  return ((int (*)(uint64_t))double_to_uint)(v7);
}


// rf_core_reset_alt @ 0x10dff0
int rf_core_reset_alt() {
  volatile uint32_t *v0; // r3
  volatile uint32_t *v1; // r0
  int v2; // r1
  int v3; // r2
  int result; // r0

  v0 = (void *)(uintptr_t)(off_10E038);
  v1 = (void *)(uintptr_t)(off_10E03C);
  v2 = dword_10E040;
  v3 = dword_10E044;
  *(volatile uint32_t *)off_10E038 = 0;
  v1[14] = 296;
  v0[2] = v0[2] & 0xF000FFFF | 0x2000000;
  result = v0[3];
  v0[3] = v2 & result | 0xA06A000;
  v0[3] = v3 & v0[3] | 0x100230;
  v0[1] = 1;
  return result;
}



// rf_core_is_ready @ 0x10e048
unsigned int rf_core_is_ready() {
  volatile uint32_t *v0; // r3
  uint64_t v1; // r0
  uint64_t v2; // r0
  uint64_t v3; // r0
  uint64_t v4; // r0

  while ( *((volatile uint32_t *)off_10E0A8 + 7) != 1 )
    ;
  v0 = (void *)(uintptr_t)(off_10E0A8);
  *((volatile uint32_t *)off_10E0A8 + 7) = 1;
  v1 = uint_to_double(v0[4]);
  v2 = ((uint64_t (*)())double_add_1)(v1, *(volatile uint64_t *)&dword_10E090);
  v3 = ((uint64_t (*)())double_subtract)(v2, *(volatile uint64_t *)&dword_10E098);
  v4 = ((uint64_t (*)())double_compare_wrapper)(v3, *(volatile uint64_t *)&dword_10E0A0);
  return ((int (*)(uint64_t))double_to_uint)(v4);
}


// rf_core_enable @ 0x10e0b0
int rf_core_enable() {
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

  v0 = (void *)(uintptr_t)(off_10E1D0);
  rf_ctrl_config_set(1);
  v0[1] = 1;
  while ( v0[7] != 1 )
    ;
  v0[7] = 1;
  v1 = uint_to_double(v0[4]);
  v2 = ((uint64_t (*)())double_add_1)(v1, *(volatile uint64_t *)&dword_10E1B0);
  v3 = ((uint64_t (*)())double_subtract)(v2, *(volatile uint64_t *)&dword_10E1B8);
  v4 = ((uint64_t (*)())double_compare_wrapper)(v3, *(volatile uint64_t *)&dword_10E1B0);
  v5 = ((int (*)(uint64_t))double_to_uint)(v4);
  rf_ctrl_config_set(2);
  v6 = (void *)(uintptr_t)(off_10E1D0);
  v0[1] = 1;
  while ( v6[7] != 1 )
    ;
  v6[7] = 1;
  v7 = v6[4];
  rf_ctrl_config_set(3);
  v8 = uint_to_double(v7);
  v9 = ((uint64_t (*)())double_add_1)(v8, *(volatile uint64_t *)&dword_10E1B0);
  v10 = ((uint64_t (*)())double_subtract)(v9, *(volatile uint64_t *)&dword_10E1B8);
  v11 = ((uint64_t (*)())double_compare_wrapper)(v10, *(volatile uint64_t *)&dword_10E1B0);
  v12 = ((int (*)(uint64_t))double_to_uint)(v11);
  v13 = ((uint64_t (*)())float_to_double)(v12);
  v14 = ((uint64_t (*)())double_subtract)(v13, *(volatile uint64_t *)&dword_10E1C0);
  v15 = (v15 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_10E1D4) << 32);
  v15 = (v15 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v16 = ((uint64_t (*)())double_add_1)(v14, v15);
  v17 = ((uint64_t (*)())float_to_double)(v5);
  v18 = ((uint64_t (*)())double_subtract)(v17, *(volatile uint64_t *)&dword_10E1C0);
  v19 = (v19 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_10E1D8) << 32);
  v19 = (v19 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v20 = ((uint64_t (*)())double_add_1)(v18, v19);
  v21 = double_compare(v16, v20);
  v22 = (v22 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_10E1DC) << 32);
  v22 = (v22 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v23 = ((uint64_t (*)())double_add_1)(v21, v22);
  v24 = ((uint64_t (*)())double_add_1)(v23, *(volatile uint64_t *)&dword_10E1C8);
  v25 = (v25 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_10E1E0) << 32);
  v25 = (v25 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v26 = ((uint64_t (*)())double_subtract)(v24, v25);
  return (int)COERCE_FLOAT(((int (*)(uint64_t))double_to_uint)(v26));
}


// rf_core_power_on @ 0x10e1e8
int rf_core_power_on() {
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

  v0 = (void *)(uintptr_t)(off_10E290);
  *((volatile uint32_t *)off_10E290 + 1) = 1;
  while ( v0[7] != 1 )
    ;
  v0[7] = 1;
  v1 = uint_to_double(v0[4]);
  v2 = ((uint64_t (*)())double_add_1)(v1, *(volatile uint64_t *)&dword_10E270);
  v3 = ((uint64_t (*)())double_subtract)(v2, *(volatile uint64_t *)&dword_10E278);
  v4 = ((uint64_t (*)())double_compare_wrapper)(v3, *(volatile uint64_t *)&dword_10E270);
  v5 = ((int (*)(uint64_t))double_to_uint)(v4);
  v6 = ((uint64_t (*)())float_to_double)(v5);
  v7 = ((uint64_t (*)())double_subtract)(v6, *(volatile uint64_t *)&dword_10E280);
  v8 = (v8 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_10E294) << 32);
  v8 = (v8 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v9 = ((uint64_t (*)())double_add_1)(v7, v8);
  v10 = (v10 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_10E298) << 32);
  v10 = (v10 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v11 = ((uint64_t (*)())double_add_1)(v9, v10);
  v12 = ((uint64_t (*)())double_add_1)(v11, *(volatile uint64_t *)&dword_10E288);
  v13 = (v13 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_10E29C) << 32);
  v13 = (v13 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v14 = ((uint64_t (*)())double_subtract)(v12, v13);
  return (int)COERCE_FLOAT(((int (*)(uint64_t))double_to_uint)(v14));
}


// rf_event_handler @ 0x10e2a0
int rf_event_handler() {
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

  v0 = dword_10E534;
  v1 = (void *)(uintptr_t)(off_10E53C);
  *((volatile uint32_t *)off_10E530 + 14) = 296;
  v1[3] = v0 | v1[3] & 0xE0000000;
  call_ptr_1b8();
  v1[2] = dword_10E540 & v1[2] | 0x1200000F;
  v1[1] = 1;
  while ( v1[7] != 1 )
    ;
  v1[7] = 1;
  v2 = uint_to_double(v1[4]);
  v3 = ((uint64_t (*)())double_add_1)(v2, *(volatile uint64_t *)&dword_10E518);
  v4 = ((uint64_t (*)())double_compare_wrapper)(v3, *(volatile uint64_t *)&dword_10E520);
  v5 = ((int (*)(uint64_t))double_to_float_1)(v4);
  event_dispatch("Initial    Volt:  %d mV\n", v5);
  v6 = call_ptr_1b0();
  v7 = v5 - 1400;
  v8 = abs32(v5 - 1400);
  v9 = v6 & 0x3F;
  v38 = v9;
  if ( v8 > 49 )
  {
    v10 = int_to_double(v8);
    v11 = ((uint64_t (*)())double_add_1)(v10, *(volatile uint64_t *)&dword_10E528);
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
      call_ptr_1b8();
      v15 = (void *)(uintptr_t)(off_10E53C);
      *((volatile uint32_t *)off_10E53C + 1) = 1;
      while ( v15[7] != 1 )
        ;
      v15[7] = 1;
      v16 = uint_to_double(v15[4]);
      v17 = ((uint64_t (*)())double_add_1)(v16, *(volatile uint64_t *)&dword_10E518);
      v18 = ((uint64_t (*)())double_compare_wrapper)(v17, *(volatile uint64_t *)&dword_10E520);
      v5 = ((int (*)(uint64_t))double_to_float_1)(v18);
      event_dispatch("step=%d, val=%d, volt=%d\n", v13, v14, v5);
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
  v21 = (void *)(uintptr_t)(off_10E53C);
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
    call_ptr_1b8();
    v21[1] = 1;
    while ( v21[7] != 1 )
      ;
    v21[7] = 1;
    v26 = uint_to_double(v21[4]);
    v27 = ((uint64_t (*)())double_add_1)(v26, *(volatile uint64_t *)&dword_10E518);
    v28 = ((uint64_t (*)())double_compare_wrapper)(v27, *(volatile uint64_t *)&dword_10E520);
    v37 = ((int (*)(uint64_t))double_to_float_1)(v28);
    event_dispatch("ofst=%d, val=%d, volt=%d\n", v25, v23, v37);
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
  event_dispatch("reg_value_offset: %d\n", v25);
  call_ptr_1b8();
  v31 = (void *)(uintptr_t)(off_10E53C);
  *((volatile uint32_t *)off_10E53C + 1) = 1;
  while ( v31[7] != 1 )
    ;
  v31[7] = 1;
  v32 = uint_to_double(v31[4]);
  v33 = ((uint64_t (*)())double_add_1)(v32, *(volatile uint64_t *)&dword_10E518);
  v34 = ((uint64_t (*)())double_compare_wrapper)(v33, *(volatile uint64_t *)&dword_10E520);
  v35 = ((int (*)(uint64_t))double_to_float_1)(v34);
  event_dispatch("Calibrated Volt:  %d mV\n", v35);
  return call_ptr_1b8();
}


// rf_event_handler_alt @ 0x10e560
int rf_event_handler_alt() {
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

  v0 = (void *)(uintptr_t)(off_10E814);
  v1 = dword_10E818;
  v2 = dword_10E81C;
  *((volatile uint32_t *)off_10E810 + 14) = 296;
  v0[2] = v1 & v0[2] | 0x200000B;
  v0[3] = v2 | v0[3] & 0xE0000000;
  v0[1] = 1;
  while ( v0[7] != 1 )
    ;
  v0[7] = 1;
  v3 = uint_to_double(v0[4]);
  v4 = ((uint64_t (*)())double_add_1)(v3, *(volatile uint64_t *)&dword_10E7F8);
  v5 = ((uint64_t (*)())double_subtract)(v4, *(volatile uint64_t *)&dword_10E800);
  v6 = ((uint64_t (*)())double_compare_wrapper)(v5, *(volatile uint64_t *)&dword_10E7F8);
  v7 = ((int (*)(uint64_t))double_to_float_1)(v6);
  v8 = call_ptr_1b0() & 0x1F;
  v9 = v7 - 840;
  log_printf("Initl vcore Volt: %d mV, reg: %x\n", v7, v8);
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
    v11 = int_to_double(v10);
    v12 = ((uint64_t (*)())double_add_1)(v11, *(volatile uint64_t *)&dword_10E808);
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
    call_ptr_1b8();
    v16 = (void *)(uintptr_t)(off_10E814);
    *((volatile uint32_t *)off_10E814 + 1) = 1;
    while ( v16[7] != 1 )
      ;
    v16[7] = 1;
    v17 = uint_to_double(v16[4]);
    v18 = ((uint64_t (*)())double_add_1)(v17, *(volatile uint64_t *)&dword_10E7F8);
    v19 = ((uint64_t (*)())double_subtract)(v18, *(volatile uint64_t *)&dword_10E800);
    v20 = ((uint64_t (*)())double_compare_wrapper)(v19, *(volatile uint64_t *)&dword_10E7F8);
    v7 = ((int (*)(uint64_t))double_to_float_1)(v20);
    event_dispatch("step=%d, val=%x, volt=%d\n", v14, v15, v7);
    if ( v7 <= 840 )
      v21 = 1;
    else
      v21 = -1;
    v41 = v21;
  }
  v23 = (void *)(uintptr_t)(off_10E814);
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
    call_ptr_1b8();
    v23[1] = 1;
    while ( v23[7] != 1 )
      ;
    v23[7] = 1;
    v27 = uint_to_double(v23[4]);
    v28 = ((uint64_t (*)())double_add_1)(v27, *(volatile uint64_t *)&dword_10E7F8);
    v29 = ((uint64_t (*)())double_subtract)(v28, *(volatile uint64_t *)&dword_10E800);
    v30 = ((uint64_t (*)())double_compare_wrapper)(v29, *(volatile uint64_t *)&dword_10E7F8);
    v31 = ((int (*)(uint64_t))double_to_float_1)(v30);
    event_dispatch("ofst=%d, val=%x, volt=%d\n", v9, v24, v31);
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
  log_printf("reg_value_offset: %d\n", v9);
  call_ptr_1b8();
  v34 = (void *)(uintptr_t)(off_10E814);
  *((volatile uint32_t *)off_10E814 + 1) = 1;
  while ( v34[7] != 1 )
    ;
  v34[7] = 1;
  v35 = uint_to_double(v34[4]);
  v36 = ((uint64_t (*)())double_add_1)(v35, *(volatile uint64_t *)&dword_10E7F8);
  v37 = ((uint64_t (*)())double_subtract)(v36, *(volatile uint64_t *)&dword_10E800);
  v38 = ((uint64_t (*)())double_compare_wrapper)(v37, *(volatile uint64_t *)&dword_10E7F8);
  v39 = ((int (*)(uint64_t))double_to_float_1)(v38);
  log_printf("Calib vcore Volt: %d mV\n", v39);
  result = ((volatile uint32_t *)(uintptr_t)off_10E838)[94];
  if ( result != 0x80000000 )
    return read_random_from_mmio(result);
  return result;
}


// rf_analog_ctrl_set @ 0x10e83c
int rf_analog_ctrl_set(unsigned int a1, unsigned int a2, volatile unsigned int *a3) {
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

  v4 = (volatile unsigned int *)off_10E9DC;
  v5 = (volatile unsigned int *)off_10E9E0;
  *(volatile uint32_t *)off_10E9DC = *(volatile uint32_t *)off_10E9DC & 0xFFFFFFF8 | a1 & 7;
  *v5 = ((uint16_t)a1 << 12) & 0x7000 | *v5 & 0xFFFF8FFF;
  *v4 = (8 * a2) & 0x78 | *v4 & 0xFFFFFF87;
  *v5 = (a2 << 15) & 0x78000 | *v5 & 0xFFF87FFF;
  v8 = (volatile int16_t *)off_10E9E4;
  v9 = rf_core_enable();
  event_dispatch("cal start, reg_init=(%d,%d), i_pa_init=%d, i_pa_target=%d\n", a1, a2, v9, *v8);
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
  v11 = (volatile unsigned int *)off_10E9DC;
  v12 = (volatile unsigned int *)off_10E9E0;
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
    v9 = rf_core_enable();
    event_dispatch("reg_val_res=%d, reg_val_cgm=%d, i_pa=%d\n", v13, v3, v9);
    v16 = *(volatile int16_t *)off_10E9E4;
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
  event_dispatch("cal done, offset_res=%d,(%d,%d), i_pa_res=%d\n", v20, v13 - v21, v3 - a2, v9);
LABEL_9:
  *a3 = v3;
  return v20;
}


// rf_control_field_set @ 0x10e9f4
int rf_control_field_set(int a1) {
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

  v1 = (volatile int16_t *)off_10EB10;
  *(volatile uint32_t *)off_10EB04 = (a1 << 26) & 0x1C000000 | *(volatile uint32_t *)off_10EB04 & 0xE3FFFFFF;
  v2 = a1;
  v3 = rf_core_power_on();
  event_dispatch("cal start, reg_init=%d, i_pa_init=%d, i_pa_target=%d\n", v2, v3, *v1);
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
  v5 = (volatile unsigned int *)off_10EB04;
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
    v9 = rf_core_power_on();
    event_dispatch("reg_val=%d, i_pa=%d\n", v2, v9);
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
  event_dispatch("cal done, offset_res=%d, i_pa_res=%d\n", v7, v15);
  return v7;
}


// rf_hardware_init @ 0x10eb18
int rf_hardware_init(int a1) {
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
  v1 = (void *)(uintptr_t)(off_10EC1C);
  v2 = dword_10EC20;
  v3 = dword_10EC24;
  v4 = (void *)(uintptr_t)(off_10EC28);
  v5 = (void *)(uintptr_t)(off_10EC40);
  v6 = dword_10EC2C;
  v7 = (volatile unsigned int *)off_10EC30;
  _frame.v18 = 0;
  *((volatile uint32_t *)off_10EC3C + 14) = 296;
  v1[3] = v1[3] & 0xE0000000 | v2;
  v1[2] = v3 & v1[2] | 0x1200000D;
  *v4 |= 2u;
  *v4 &= ~1u;
  *(volatile uint32_t *)_frame.a1a = v6;
  _frame.v17 = 5610;
  rf_enable(_frame.a1a, 0);
  v8 = (volatile int *)off_10EC34;
  v9 = dword_10EC38;
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
  result = rf_analog_ctrl_set(4u, 8u, (volatile unsigned int *)a1);
  *v5 &= ~0x80000000;
  *v4 &= ~2u;
  *v7 = v10 & 0x80000 | *v7 & 0xFFF7FFFF;
  *v7 = v11 & 0x100000 | *v7 & 0xFFEFFFFF;
  *v7 = v12 & 0x200000 | *v7 & 0xFFDFFFFF;
  *v7 = v13 & 0x400000 | *v7 & 0xFFBFFFFF;
  return result;
}


// rf_hardware_setup @ 0x10ec44
int rf_hardware_setup() {
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
  v0 = (volatile unsigned int *)off_10ED44;
  v1 = (void *)(uintptr_t)(off_10ED48);
  v2 = dword_10ED4C;
  v3 = dword_10ED50;
  v4 = (void *)(uintptr_t)(off_10ED64);
  v5 = (void *)(uintptr_t)(off_10ED54);
  v6 = (void *)(uintptr_t)(off_10ED68);
  v7 = dword_10ED58;
  _frame.v17 = 0;
  *((volatile uint32_t *)off_10ED44 + 14) = 296;
  v1[3] = v2 | v1[3] & 0xE0000000;
  v1[2] = v3 & v1[2] | 0x1200000D;
  *v4 |= 0x20000000u;
  *v5 &= ~1u;
  *(volatile uint32_t *)_frame.a1 = v7;
  _frame.v16 = 2442;
  rf_enable(_frame.a1, 0);
  v8 = (volatile int *)off_10ED5C;
  v9 = dword_10ED60;
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
  result = rf_control_field_set(4);
  *v6 &= ~0x80000000;
  *v4 &= ~0x20000000u;
  *v0 = v10 & 0x80000 | *v0 & 0xFFF7FFFF;
  *v0 = v11 & 0x100000 | *v0 & 0xFFEFFFFF;
  *v0 = v12 & 0x200000 | *v0 & 0xFFDFFFFF;
  *v0 = v13 & 0x400000 | *v0 & 0xFFBFFFFF;
  return result;
}


// call_ptr_1b0 @ 0x10ed6c
int call_ptr_1b0() {
  return ((int (*)())MEMD(0x1B0))();
}



// call_ptr_1b4 @ 0x10ed74
int call_ptr_1b4() {
  return ((int (*)())MEMD(0x1B4))();
}



// call_ptr_1b8 @ 0x10ed7c
int call_ptr_1b8() {
  return ((int (*)())MEMD(0x1B8))();
}



// mmio_read32 @ 0x10ed84
int mmio_read32(int a1, int a2) {
  volatile int *v2; // r5
  volatile uint32_t *v3; // r4
  int result; // r0
  int v5; // r3
  int v6; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_10EDCC = 1;
  }
  v2 = (volatile int *)off_10EDD0;
  ++*(volatile uint32_t *)off_10EDD0;
  if ( a2 )
  {
    v3 = (void *)(uintptr_t)(off_10EDD4);
    while ( !*(volatile uint32_t *)off_10EDD4 )
      ;
    result = call_ptr_1b0();
    *v3 = 1;
  }
  else
  {
    result = call_ptr_1b0();
  }
  if ( *v2 )
  {
    v5 = *v2 - 1;
    v6 = *(volatile uint32_t *)off_10EDCC;
    *v2 = v5;
    if ( !v5 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
  return result;
}



// mmio_write32 @ 0x10edd8
int mmio_write32(int a1, int a2, int a3) {
  volatile int *v3; // r5
  volatile uint32_t *v4; // r4
  int result; // r0
  int v6; // r3
  int v7; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_10EE20 = 1;
  }
  v3 = (volatile int *)off_10EE24;
  ++*(volatile uint32_t *)off_10EE24;
  if ( a3 )
  {
    v4 = (void *)(uintptr_t)(off_10EE28);
    while ( !*(volatile uint32_t *)off_10EE28 )
      ;
    result = call_ptr_1b4();
    *v4 = 1;
  }
  else
  {
    result = call_ptr_1b4();
  }
  if ( *v3 )
  {
    v6 = *v3 - 1;
    v7 = *(volatile uint32_t *)off_10EE20;
    *v3 = v6;
    if ( !v6 )
    {
      if ( v7 )
        __enable_irq();
    }
  }
  return result;
}



