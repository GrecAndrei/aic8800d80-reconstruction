// check_button @ 0x102a1c
int check_button() {
  int result; // r0

  result = dispatch_event_handler_1("%s\r\n", aIntcSpurious);
  if ( **(volatile int16_t **)off_102A4C < 0 )
    return flash_ctrl_init(off_102A54, (int)aIntcSpurious_0, 61);
  return result;
}


// nvic_enable_irq @ 0x102a58
int nvic_enable_irq() {
  volatile uint32_t *v0; // r2
  volatile uint8_t *v1; // r3
  int v3; // r4
  int v4; // r5
  int v5; // r6
  int v6; // r5
  int v7; // r6
  void *v8; // r4

  v0 = (void *)(uintptr_t)(off_102AB8);
  v1 = (void *)(uintptr_t)(off_102ABC);
  *(volatile uint32_t *)(*((volatile uint32_t *)off_102AB8 + 2) + 80) = dword_102AC0;
  *(volatile uint32_t *)v1 = 16;
  v3 = dword_102AC4;
  *(volatile uint32_t *)(v0[2] + 84) = dword_102AC4;
  *(volatile uint32_t *)v1 = 32;
  v4 = dword_102AC8;
  *(volatile uint32_t *)(v0[2] + 92) = v3;
  *(volatile uint32_t *)v1 = 128;
  v5 = dword_102ACC;
  *(volatile uint32_t *)(v0[2] + 72) = v4;
  *(volatile uint32_t *)v1 = 4;
  v6 = dword_102AD0;
  *(volatile uint32_t *)(v0[2] + 88) = v5;
  *(volatile uint32_t *)v1 = 64;
  v7 = dword_102AD4;
  *(volatile uint32_t *)(v0[2] + 76) = v6;
  v1[771] = -8;
  *(volatile uint32_t *)v1 = 8;
  v8 = (void *)(uintptr_t)(off_102AD8);
  *(volatile uint32_t *)(v0[2] + 208) = v7;
  *((volatile uint32_t *)v1 + 1) = 16;
  *(volatile uint32_t *)(v0[2] + 212) = (int)(uintptr_t)(v8);
  *((volatile uint32_t *)v1 + 1) = 32;
  __enable_irq();
  return 16;
}



// gpio_set_pin @ 0x102adc
volatile int * gpio_set_pin(int a1) {
  int v1; // r4
  int v2; // r1
  int v3; // zf
  int v4; // r2
  int v5; // r2
  int v6; // r3
  volatile int *result; // r0
  int v8; // r2
  int v9; // r3

  v2 = (int)off_102B3C;
  v3 = a1 == 0;
  if ( a1 )
    v4 = -2;
  else
    v4 = -17;
  v5 = v4 & *(volatile uint32_t *)off_102B3C;
  if ( !a1 )
    a1 = -33;
  *(volatile uint32_t *)off_102B3C = v5;
  if ( v3 )
    v2 = 64;
  else
    a1 = -3;
  if ( v3 )
    v1 = 16;
  else
    v2 = 4;
  if ( !v3 )
    v1 = 1;
  v6 = (v6 & ~0xFFu) | ((uint8_t)(50) & 0xFFu);
  do
    v6 = (uint8_t)(v6 - 1);
  while ( v6 );
  v9 = v5 & a1;
  result = (volatile int *)off_102B3C;
  v8 = v9 | v2;
  *(volatile uint32_t *)off_102B3C = v9;
  v9 = (v9 & ~0xFFu) | ((uint8_t)(50) & 0xFFu);
  *result = v8;
  do
    v9 = (uint8_t)(v9 - 1);
  while ( v9 );
  *(volatile uint32_t *)off_102B3C = v8 | v1;
  return result;
}



// gpio_clear_pin @ 0x102b40
int gpio_clear_pin(int result) {
  int v1; // r4
  int v2; // zf
  int v3; // r1
  int v4; // r2
  int v5; // r3
  int v6; // r2
  int v7; // r3
  int v8; // r2
  int v9; // r3

  v2 = result == 0;
  if ( result )
    v3 = -5;
  else
    v3 = -65;
  v4 = *(volatile uint32_t *)off_102BAC & v3;
  if ( !result )
    result = 32;
  *(volatile uint32_t *)off_102BAC = v4;
  if ( v2 )
    v1 = -17;
  else
    result = 2;
  if ( v2 )
    v3 = 16;
  else
    v1 = -2;
  if ( !v2 )
    v3 = 1;
  v5 = (v5 & ~0xFFu) | ((uint8_t)(-56) & 0xFFu);
  do
    v5 = (uint8_t)(v5 - 1);
  while ( v5 );
  v6 = v4 & v1;
  *(volatile uint32_t *)off_102BAC = v6;
  v7 = (v7 & ~0xFFu) | ((uint8_t)(50) & 0xFFu);
  do
    v7 = (uint8_t)(v7 - 1);
  while ( v7 );
  v8 = v6 | result;
  *(volatile uint32_t *)off_102BAC = v8;
  v9 = (v9 & ~0xFFu) | ((uint8_t)(50) & 0xFFu);
  do
    v9 = (uint8_t)(v9 - 1);
  while ( v9 );
  *(volatile uint32_t *)off_102BAC = v8 | v3;
  return result;
}



// periph_wait_status @ 0x102bb0
int periph_wait_status(int a1, volatile uint16_t *a2) {
  unsigned int v2; // r7
  unsigned int v4; // r11
  int v5; // r8
  unsigned int v6; // r4
  volatile unsigned int *v7; // r6
  int v8; // r5
  unsigned int v9; // r4
  int v10; // t1
  unsigned int v11; // r4
  int v12; // r3
  int result; // r0
  volatile uint64_t *v14; // r3
  volatile char *v15; // r12
  int v16; // r6
  volatile char *v17; // r7
  int v18; // r4
  int v19; // t1
  volatile uint16_t *v20; // r1
  int v21; // r3
  int v22; // r5
  volatile int *v23; // r1
  uint64_t v24; // r2
  struct __attribute__((packed)) { int v25; // [sp+Ch] [bp-28h]
  char _pad1[12]; uint64_t v27; // [sp+1Ch] [bp-18h] BYREF
  volatile int *v28; // [sp+24h] [bp-10h]
  uint64_t v29; // [sp+28h] [bp-Ch]
  } _frame;
  while ( !*(volatile uint32_t *)off_102D18 )
    ;
  v4 = 0;
  gpio_set_pin(0);
  v5 = dword_102D40;
  _frame.v25 = 0;
  while ( ((1 << v4) & a1) == 0 )
  {
    v6 = (uint16_t)v4;
    if ( (uint16_t)v4 == 5 )
      goto LABEL_10;
LABEL_4:
    ++v4;
  }
  v7 = (volatile unsigned int *)(dword_102D1C + (v4 << 9));
  v8 = 0;
  v2 = (unsigned int)(a2 - 1);
  do
  {
    v9 = *v7;
    check_interrupt_flag(0x2000, "before %d,%d: dcq/i=%4x\r\n", v4, v8, (uint16_t)(*v7 >> 11));
    v10 = *(volatile uint16_t *)(v2 + 2);
    v2 += 2;
    v11 = v9 & v5 | (v10 << 11);
    *v7 = v11;
    v7 += 8;
    v12 = v8++;
    check_interrupt_flag(0x2000, "after  %d,%d: dcq/i=%4x\r\n", v4, v12, (uint16_t)(v11 >> 11));
  }
  while ( v8 != 16 );
  if ( v4 <= 1 )
    goto LABEL_4;
  v6 = (uint16_t)v4;
  _frame.v25 = 1;
  if ( (uint16_t)v4 != 5 )
    goto LABEL_4;
LABEL_10:
  result = gpio_clear_pin(0);
  *(volatile uint32_t *)off_102D18 = 1;
  if ( _frame.v25 )
  {
    if ( (a1 & 0x80) != 0 )
      v2 = 3;
    else
      v6 = 3;
    if ( (a1 & 0x80) == 0 )
      v2 = 0;
    if ( (*(volatile uint32_t *)off_102D24 & 0x8000000) == 0 || (*(volatile uint32_t *)off_102D28 & 0x400) != 0 )
      v14 = (volatile uint64_t *)off_102D44;
    else
      v14 = (volatile uint64_t *)off_102D2C;
    _frame.v27 = *v14;
    v23 = *((volatile int **)v14 + 2);
    v24 = *(volatile uint64_t *)((volatile char *)v14 + 12);
    _frame.v28 = v23;
    _frame.v29 = v24;
  }
  else
  {
    result = 0;
    _frame.v28 = (volatile int *)((volatile uint32_t *)(uintptr_t)&off_102D34)[0];
    _frame.v27 = __PAIR64__((unsigned int)((volatile uint32_t *)(uintptr_t)&off_102D30)[0], (unsigned int)((volatile uint32_t *)(uintptr_t)&off_102D38)[0]);
    _frame.v29 = (unsigned int)off_102D3C;
    if ( (a1 & 0x80) != 0 )
      v6 = 4;
    else
      v6 = 2;
    if ( (a1 & 0x80) != 0 )
      v2 = 2;
    else
      v2 = 0;
  }
  if ( v2 < v6 )
  {
    v15 = (volatile char *)&_frame.v27 + 4 * v2 + 4 * (uint16_t)(v6 - 1 - v2) + 4;
    v16 = dword_102D40;
    v17 = (volatile char *)&_frame.v27 + 4 * v2;
    do
    {
      v19 = *(volatile uint32_t *)v17;
      v17 += 4;
      v18 = v19;
      v20 = a2;
      v21 = v19;
      v22 = v19 + 320;
      do
      {
        if ( v18 )
        {
          result = *v20;
          *(volatile uint32_t *)(v21 + 16) = *(volatile uint32_t *)(v21 + 16) & v16 | (result << 11);
        }
        v21 += 20;
        ++v20;
      }
      while ( v22 != v21 );
    }
    while ( v17 != v15 );
  }
  return result;
}


// memcpy_advance @ 0x102d4c
int memcpy_advance(int a1, int a2, unsigned int a3, int a4) {
  int v6; // r6
  int v7; // r4
  int v8; // r10
  int v9; // r12
  int v10; // r2
  int v11; // r6
  int v12; // lr
  volatile int *v13; // r7
  volatile int *v14; // r1
  volatile uint32_t *v15; // r4
  int v16; // t1
  int result; // r0

  if ( a1 )
  {
    v6 = 16 * (dword_102DDC + a2);
    v7 = 4;
    v8 = 3;
  }
  else
  {
    v6 = 32 * (dword_102DD4 + a2);
    v7 = 8;
    v8 = 5;
  }
  while ( !*(volatile uint32_t *)off_102DD8 )
    ;
  gpio_set_pin(a1);
  if ( a3 )
  {
    v9 = 0;
    v10 = 4 * (v7 - v8);
    v11 = v6 - a4;
    v12 = 0;
    v13 = (volatile int *)(a4 + 4 * v8);
    do
    {
      v14 = (volatile int *)(a4 + 4 * v9);
      do
      {
        v15 = (void *)((volatile int *)((volatile char *)v14 + v11));
        v16 = *v14++;
        *v15 = v16;
      }
      while ( v13 != v14 );
      ++v12;
      v9 += v8;
      v11 += v10;
      v13 += v8;
    }
    while ( a3 > (uint8_t)v12 );
  }
  result = gpio_clear_pin(a1);
  *(volatile uint32_t *)off_102DD8 = 1;
  return result;
}



// get_reset_reason @ 0x102de0
BOOL get_reset_reason() {
  BOOL result; // r0

  result = (*(volatile uint32_t *)off_102DFC >> 27) & 1;
  if ( (*(volatile uint32_t *)off_102DFC & 0x8000000) != 0 )
    return (*(volatile uint32_t *)off_102E00 & 0x400) == 0;
  return result;
}



// dma_init @ 0x102e04
int dma_init(int a1) {
  uint64_t v1; // kr00_8
  int v2; // r4

  if ( a1 )
  {
    v1 = *(volatile uint64_t *)((volatile char *)off_102E40 + 4);
    v2 = *(volatile uint32_t *)off_102E40;
  }
  else
  {
    v2 = *(volatile uint32_t *)off_102E44;
    v1 = *(volatile uint64_t *)((volatile char *)off_102E44 + 4);
  }
  memcpy_advance(0, 32, 0x10u, SHIDWORD(v1));
  memcpy_advance(0, 48, 0x10u, v1);
  return memcpy_advance(0, 64, 0x10u, v2);
}



// gpio_set_high @ 0x102e48
int gpio_set_high(int a1) {
  volatile int *v1; // r2
  int v2; // r3

  if ( a1 )
  {
    v1 = (volatile int *)off_102E80;
    *(volatile uint32_t *)off_102E7C &= ~0x400u;
    v2 = *v1 | 0x8000000;
  }
  else
  {
    v1 = (volatile int *)off_102E7C;
    *(volatile uint32_t *)off_102E80 &= ~0x8000000u;
    v2 = *v1 | 0x400;
  }
  *v1 = v2;
  return dma_init(a1);
}


// clock_set_source @ 0x102e84
int clock_set_source(int a1, int a2, int a3) {
  volatile uint32_t *v3; // r3
  volatile uint32_t *v4; // r5
  volatile unsigned int *v5; // r4
  int v6; // r6
  volatile int *v7; // r3
  int v8; // r5
  int v9; // r4
  int result; // r0
  volatile int *v11; // r1
  volatile unsigned int *v12; // r1
  int v13; // r3
  int v14; // r4
  void *v15; // r3
  volatile unsigned int *v16; // r1

  if ( !a3 )
  {
    v12 = (volatile unsigned int *)off_102FDC;
    *((volatile uint32_t *)off_102FD8 + 13) = 31;
    *v12 = *v12 & 0xF1FFFFFF | 0x8000000;
    if ( !a1 )
    {
      v6 = 0;
      goto LABEL_17;
    }
    if ( (*(volatile uint32_t *)off_102FF0 & 0x8000000) != 0 )
    {
      v13 = 1 - ((*(volatile uint32_t *)off_102FF4 >> 10) & 1);
      goto LABEL_11;
    }
LABEL_20:
    v14 = a3;
    goto LABEL_21;
  }
  if ( a3 == 1 )
  {
    v16 = (volatile unsigned int *)off_102FDC;
    *((volatile uint32_t *)off_102FD8 + 13) = 29;
    *v16 = *v16 & 0xF1FFFFFF | 0x4000000;
    if ( !a1 )
    {
      v7 = (volatile int *)((volatile uint32_t *)(uintptr_t)&off_103000)[0];
      v6 = 1;
      v8 = 770048;
      v9 = 12;
      goto LABEL_6;
    }
    if ( (*(volatile uint32_t *)off_102FF0 & 0x8000000) == 0 || (*(volatile uint32_t *)off_102FF4 & 0x400) != 0 )
    {
      v8 = 409600;
      v15 = (void *)(uintptr_t)(((volatile uint32_t *)(uintptr_t)off_103008)[3]);
      v14 = 1;
    }
    else
    {
      v14 = 1;
      v15 = *((void **)off_102FF8 + 3);
      v8 = 409600;
    }
LABEL_13:
    memcpy_advance(0, 32, 0x10u, (int)v15);
    result = dispatch_event_handler_1("5g bwmode change to %d\n", v14);
    v9 = 12;
    goto LABEL_7;
  }
  v3 = (void *)(uintptr_t)(off_102FD4);
  v4 = (void *)(uintptr_t)(off_102FD8);
  v5 = (volatile unsigned int *)off_102FDC;
  *(volatile uint32_t *)off_102FD4 |= 1u;
  *v3 |= 2u;
  v4[13] = 25;
  *v5 = *v5 & 0xF1FFFFFF | 0x2000000;
  if ( a1 )
  {
    if ( (*(volatile uint32_t *)off_102FF0 & 0x8000000) != 0 )
    {
      v13 = 1 - ((*(volatile uint32_t *)off_102FF4 >> 10) & 1);
      if ( a3 == 2 )
      {
        if ( v13 )
        {
          v14 = 2;
          v15 = *((void **)off_102FF8 + 4);
          v8 = 819200;
          goto LABEL_13;
        }
LABEL_29:
        v8 = 819200;
        v15 = (void *)(uintptr_t)(((volatile uint32_t *)(uintptr_t)off_103008)[4]);
        v14 = 2;
        goto LABEL_13;
      }
LABEL_11:
      v14 = a3;
      if ( v13 )
      {
        v15 = *((void **)off_102FF8 + 2);
        v8 = 204800;
        goto LABEL_13;
      }
LABEL_21:
      v8 = 204800;
      v15 = (void *)(uintptr_t)(((volatile uint32_t *)(uintptr_t)off_103008)[2]);
      goto LABEL_13;
    }
    if ( a3 == 2 )
      goto LABEL_29;
    goto LABEL_20;
  }
  v6 = a3;
  if ( a3 != 2 )
  {
LABEL_17:
    v7 = (volatile int *)off_103004;
    v8 = 385024;
    v9 = 12;
    goto LABEL_6;
  }
  v7 = (volatile int *)off_102FE0;
  v8 = 1540096;
  v9 = 17;
LABEL_6:
  memcpy_advance(0, 0, 0x10u, (int)v7);
  result = dispatch_event_handler_1("2.4g bwmode change to %d\n", v6);
LABEL_7:
  v11 = (volatile int *)off_102FEC;
  *(volatile uint32_t *)off_102FE8 = *(volatile uint32_t *)off_102FE8 & 0xFFC01FFF | v8;
  *v11 = v9;
  return result;
}


// check_chip_flag @ 0x10300c
void check_chip_flag() {
  volatile uint8_t *v0; // r3
  volatile uint32_t *v1; // r2
  volatile uint32_t *v2; // r1
  volatile uint8_t *v3; // r3
  int v4; // r2
  volatile unsigned int *v5; // r4
  volatile unsigned int *v6; // r0
  volatile uint32_t *v7; // r5
  volatile uint32_t *v8; // r3
  volatile uint32_t *v9; // r6
  volatile uint32_t *v10; // r1
  volatile uint8_t *v11; // r0
  volatile uint32_t *v12; // r3
  volatile int *v13; // r0
  unsigned int v14; // r3
  int v15; // r3
  volatile unsigned int *v16; // r2
  volatile uint8_t *v17; // r0
  volatile uint32_t *v18; // r1
  int v19; // r0
  volatile unsigned int *v20; // r2
  volatile uint32_t *v21; // r3
  volatile uint32_t *v22; // r3
  volatile uint32_t *v23; // r2
  volatile unsigned int *v24; // r0
  volatile unsigned int *v25; // r1
  volatile uint32_t *v26; // r0
  volatile uint32_t *v27; // r2

  if ( *((volatile uint8_t *)off_103264 + 2) )
  {
    *(volatile uint32_t *)off_1032BC = *(volatile uint32_t *)off_1032BC & 0xFFFFF3FF | 0x800;
  }
  else
  {
    v0 = (void *)(uintptr_t)(off_103268);
    v1 = (void *)(uintptr_t)(off_10326C);
    *(volatile uint8_t *)off_103268 = 80;
    v0[1] = 78;
    while ( !*v1 )
      ;
    v2 = (void *)(uintptr_t)(off_103274);
    *(volatile uint32_t *)off_103270 &= ~2u;
    if ( (*v2 & 1) == 0 )
    {
      rf_cal_read_0(1);
      v27 = (void *)(uintptr_t)(off_1032D0);
      *(volatile uint32_t *)off_1032D8 = *(volatile uint32_t *)off_1032D8 & 0xFFFFFFF0 | 4;
      *v27 |= 2u;
    }
    v3 = (void *)(uintptr_t)(off_103278);
    *(volatile uint32_t *)off_10326C = 1;
    v4 = *v3 & 0xC0;
    if ( v4 == 192 )
    {
      v25 = (volatile unsigned int *)off_1032D0;
      v26 = (void *)(uintptr_t)(off_1032D4);
      *(volatile uint32_t *)off_10327C = *(volatile uint32_t *)off_10327C & 0xC3FFFFFF | 0x30000000;
      *v25 = *v25 & 0xFE3FFFFF | 0x400000;
      *v26 |= 0x78000u;
      *v25 &= ~2u;
    }
    v5 = (volatile unsigned int *)off_10327C;
    v6 = (volatile unsigned int *)off_103280;
    v7 = (void *)(uintptr_t)(off_103284);
    v8 = (void *)(uintptr_t)(off_103288);
    v9 = (void *)(uintptr_t)(off_10328C);
    *(volatile uint32_t *)off_10327C = *(volatile uint32_t *)off_10327C & 0xFF0FFFFF | 0xC00000;
    *v5 = *v5 & 0xFFFFFF0F | 0x60;
    *v6 &= ~1u;
    *v7 = *v7 & 0xFFFFE0FF | 0x1000;
    *v8 |= 8u;
    *v8 &= 0xFFFFFFFC;
    *(volatile unsigned int *)((volatile char *)v5 + 0xFFFFFFB8) &= ~0x40000u;
    *v8 &= ~4u;
    v10 = (void *)(uintptr_t)(off_103290);
    *v6 = *v6 & 0xFFFFF3FF | 0x800;
    v11 = (volatile uint8_t *)off_103294;
    v7 -= 1999;
    *v9 &= 0xFFFF3FFF;
    v5 -= 2068;
    *v7 = *v7 & 0xFFFFFF | 0x10000000;
    *v5 = *v5 & 0xFFFC00FF | (*v11 << 8);
    v12 = (void *)(uintptr_t)(off_103298);
    v7 -= 73;
    *v10 |= 0x80000000;
    *v7 |= 0x1000u;
    *v5 &= ~0x40000u;
    v13 = (volatile int *)off_10329C;
    *v10 &= ~0x40000000u;
    *v12 &= ~2u;
    *v12 |= 1u;
    v7[2083] = 20058;
    *v13 = *v13 & 0x3FFFFFF | 0x7C000000;
    v14 = *v13 & 0xFC07FFFF;
    if ( v4 == 192 )
      v15 = v14 | 0x3D00000;
    else
      v15 = v14 | 0x3E00000;
    *v13 = v15;
    if ( (*(volatile uint32_t *)off_1032A0 & 0x20) != 0 )
    {
      v22 = (void *)(uintptr_t)(off_1032C4);
      v23 = (void *)(uintptr_t)(off_1032C8);
      v24 = (volatile unsigned int *)off_1032CC;
      *((volatile uint8_t *)off_1032A4 + 1) = 1;
      *v22 &= 0xFFF0FFFF;
      *v22 &= 0xFF0FFFFF;
      *v23 &= ~0x8000u;
      *v24 = *v24 & 0xFFFFFC7F | 0x200;
    }
    else
    {
      *((volatile uint8_t *)off_1032A4 + 1) = 0;
    }
    v16 = (volatile unsigned int *)off_1032A8;
    v17 = (volatile uint8_t *)off_1032AC;
    v18 = (void *)(uintptr_t)(off_1032B0);
    *(volatile uint32_t *)off_1032A8 = *(volatile uint32_t *)off_1032A8 & 0x3FFFFFF | 0xA0000000;
    v19 = v17[362];
    *v16 = *v16 & 0xFC0FFFFF | 0x1800000;
    *v18 |= 0x10u;
    if ( v19 )
      *(v16 - 8824) = *(v16 - 8824) & 0xFFFFFFC0 | 0x2C;
    v20 = (volatile unsigned int *)off_1032B8;
    *(volatile uint32_t *)off_1032B4 &= 0xFFFFFFC7;
    *v20 = *v20 & 0xFFFFFFFC | 2;
  }
  v21 = (void *)(uintptr_t)(off_1032C0);
  *(volatile uint32_t *)off_1032C0 |= 0xC000u;
  *v21 |= 0x30000u;
}



// configure_external_clock @ 0x1032dc
/* luna: Enables or disables the external clock source by programming GPIO function muxing when configured and setting or clearing the external clock select bi */
unsigned int configure_external_clock(unsigned int result) {
  if ( result )
  {
    if ( *((volatile uint8_t *)off_10332C + 362) )
      result = gpio_config(0xB5u);
    *(volatile uint32_t *)off_103330 |= 2u;
  }
  else
  {
    if ( *((volatile uint8_t *)off_10332C + 362) )
      result = gpio_config(0xC2u);
    *(volatile uint32_t *)off_103330 &= ~2u;
  }
  return result;
}



// save_rf_context @ 0x103334
volatile uint32_t *save_rf_context() {
  int v0; // r1
  int v1; // r2
  int v2; // r3
  unsigned int v3; // r3
  volatile uint8_t *v4; // r2
  int v5; // r1
  unsigned int v6; // r2
  unsigned int v7; // r3
  volatile uint32_t *result; // r0
  volatile unsigned int *v9; // r1
  unsigned int v10; // r3
  struct __attribute__((packed)) { int v11; // [sp+0h] [bp-14h]
  int v12; // [sp+4h] [bp-10h]
  int v13; // [sp+8h] [bp-Ch]
  int v14; // [sp+Ch] [bp-8h]
  uint8_t v15[4]; // [sp+10h] [bp-4h] BYREF
  } _frame;
  v0 = *(volatile uint32_t *)(dword_1033A4 + 4);
  v1 = *(volatile uint32_t *)(dword_1033A4 + 8);
  v2 = *(volatile uint32_t *)(dword_1033A4 + 12);
  _frame.v11 = *(volatile uint32_t *)dword_1033A4;
  _frame.v12 = v0;
  _frame.v13 = v1;
  _frame.v14 = v2;
  if ( (*((volatile uint32_t *)off_1033A8 + 4) & 2) != 0 )
  {
    v3 = dword_1033B0;
    v4 = &_frame.v15[*((volatile uint32_t *)off_1033A8 + 9) & 0xF];
    v5 = (char)*(v4 - 16);
    v6 = (uint8_t)*(v4 - 16);
    if ( (*((volatile uint32_t *)off_1033A8 + 4) & 4) == 0 )
      v3 = dword_1033AC;
    if ( v5 < 0 )
    {
      v3 *= 2;
      v6 &= 0x7Fu;
    }
    v7 = v3 / v6;
  }
  else
  {
    v7 = 2 * *(volatile uint32_t *)off_1033C0;
  }
  result = (void *)(uintptr_t)(off_1033B8);
  v9 = (volatile unsigned int *)off_1033BC;
  v10 = v7 / (uint8_t)*((volatile uint32_t *)off_1033A8 + 8);
  *(volatile uint32_t *)off_1033B4 = v10;
  *v9 = v10 / (uint8_t)result[9];
  return result;
}



// rf_init_regs @ 0x1033c4
int rf_init_regs(int a1) {
  volatile uint32_t *v1; // r6
  volatile uint32_t *v2; // r5
  int v3; // r7
  int v4; // r8
  uint16_t v5; // r11
  unsigned int v6; // r2
  int v7; // r10
  unsigned int v8; // r3
  int v9; // r0
  unsigned int v10; // r12
  int v11; // r1
  unsigned int v12; // r12
  int v13; // r1
  int v14; // r12
  int v15; // r1
  int v16; // r7
  uint16_t v17; // r9
  int16_t v18; // r2
  uint8_t v19; // r4
  int result; // r0
  unsigned int v21; // [sp+0h] [bp-Ch]

  v1 = (volatile uint32_t *)dword_103528;
  v2 = (volatile uint32_t *)dword_10352C;
  *(volatile uint32_t *)dword_103528 |= 0x10u;
  v3 = 0;
  v4 = 0;
  *v2 = *v2 & 0xFFFFC0FF | 0x300;
  v5 = 0;
  v6 = 64;
  while ( 2 )
  {
    *v1 = *v1 & 0xFFFFFDFF | (v4 << 9);
    v7 = (v7 & ~0xFFFFu) | ((uint16_t)(10) & 0xFFFFu);
    do
    {
      *v1 = *v1 & 0xFFFE03FF | (v6 << 10);
      v8 = (uint8_t)v6;
      v9 = 0;
      while ( 1 )
      {
        *v2 |= 0x4000u;
        v10 = REG_4032_0120 + 5;
        do
          v11 = REG_4032_0120 - v10;
        while ( v11 < 0 );
        *v2 &= ~0x4000u;
        v12 = REG_4032_0120 + 5;
        do
          v13 = REG_4032_0120 - v12;
        while ( v13 < 0 );
        v14 = (*v1 >> 3) & 1;
        if ( v9 )
        {
          if ( v14 != v3 )
            break;
        }
        if ( v4 )
          v15 = (*v1 >> 3) & 1;
        else
          v15 = (*v1 & 8) == 0;
        if ( v15 )
        {
          if ( v8 )
          {
            v8 = (uint8_t)(v8 - 1);
            v16 = (v8 << 10) & 0x1FC00;
          }
          else
          {
            v16 = 0;
          }
        }
        else
        {
          if ( v8 <= 0x7E )
            v8 = (uint8_t)(v8 + 1);
          v16 = (v8 << 10) & 0x1FC00;
        }
        v9 = (uint8_t)(v9 + 1);
        *v1 = *v1 & 0xFFFE03FF | v16;
        if ( v9 == 128 )
        {
          v3 = v14;
          break;
        }
        v3 = v14;
      }
      v21 = v8;
      v17 = v8;
      v5 += v8;
      check_interrupt_flag(0x2000, "%x -> %x\n", v6, v8);
      if ( v21 <= 0x40 )
        v18 = v17 - v7;
      else
        v18 = v17 + v7;
      v7 = (uint16_t)(v7 - 20);
      v6 = __usat(7u, v18);
    }
    while ( v7 != 65506 );
    if ( !v4 )
    {
      v4 = 1;
      continue;
    }
    break;
  }
  *(volatile uint32_t *)dword_103528 = ((v5 + 2) << 8) & 0x1FC00 | *(volatile uint32_t *)dword_103528 & 0xFFFE03FF;
  v19 = ((unsigned int)v5 + 2) >> 2;
  result = log_printf("%dM mdll duty: %x\n", 40 * a1 + 280, v19);
  if ( a1 )
    *(volatile uint8_t *)(dword_10353C + 1) = v19;
  else
    *(volatile uint8_t *)dword_10353C = v19;
  return result;
}


// poll_rf_status @ 0x103540
int poll_rf_status() {
  volatile uint32_t *v0; // r2
  int v1; // r3
  volatile uint32_t *v2; // r3
  volatile uint32_t *v3; // r2
  int v4; // r3
  volatile uint32_t *v5; // r3
  volatile uint32_t *v6; // r0

  v0 = (void *)(uintptr_t)(off_1035D0);
  *(volatile uint32_t *)off_1035CC |= 1u;
  while ( (*v0 & 0x10) == 0 )
  {
    v1 = (v1 & ~0xFFFFu) | ((uint16_t)(50) & 0xFFFFu);
    do
      v1 = (uint16_t)(v1 - 1);
    while ( v1 );
  }
  v2 = (void *)(uintptr_t)(off_1035D4);
  v3 = (void *)(uintptr_t)(off_1035D0);
  *(volatile uint32_t *)off_1035D4 |= 0x80000u;
  *v2 |= 0x100000u;
  while ( (*v3 & 8) == 0 )
  {
    v4 = (v4 & ~0xFFFFu) | ((uint16_t)(50) & 0xFFFFu);
    do
      v4 = (uint16_t)(v4 - 1);
    while ( v4 );
  }
  v5 = (void *)(uintptr_t)(off_1035DC);
  v6 = (void *)(uintptr_t)(off_1035E0);
  *(volatile uint32_t *)off_1035D8 |= 0x20000u;
  *v5 |= 0x1000000u;
  *v5 |= 0x8000000u;
  *v6 |= 0x524u;
  return check_interrupt_flag(0x2000, aWfDfeAndRfintf);
}


// configure_bb_clock @ 0x1035e8
int configure_bb_clock() {
  volatile uint32_t *v0; // r0
  volatile uint32_t *v1; // r1
  volatile uint32_t *v2; // r2

  v0 = (void *)(uintptr_t)(off_103630);
  v1 = (void *)(uintptr_t)(off_103634);
  v2 = (void *)(uintptr_t)(off_103638);
  *(volatile uint32_t *)off_10362C &= 0xFFFFFA53;
  *v0 &= ~0x20000u;
  *v1 &= ~0x1000000u;
  *v2 &= 0xFFE7FFFF;
  write_timer_reg(10);
  return check_interrupt_flag(0x2000, aWfDfeAndRfintf_0);
}


// disable_bb_timer_irq @ 0x103640
int disable_bb_timer_irq() {
  volatile uint32_t *v0; // r4
  int result; // r0

  v0 = (void *)(uintptr_t)(off_103674);
  *(volatile uint32_t *)off_103674 &= ~0x400000u;
  *v0 &= ~0x200000u;
  write_timer_reg(2);
  *v0 |= 0x200000u;
  result = write_timer_reg(2);
  *v0 |= 0x400000u;
  return result;
}



// set_system_mode @ 0x103678
/* luna: Selects and enables a baseband debug monitor dump source, using mode-specific register values and trace labels. */
int set_system_mode(int a1) {
  volatile unsigned int *bb_dump_ctrl_reg; // r2
  volatile int *v2; // r4
  unsigned int v3; // r1
  int v4; // r5
  unsigned int v5; // r3
  const volatile char *v6; // r0
  volatile unsigned int *v7; // r4
  volatile int *v8; // r5
  int v9; // r6
  volatile unsigned int *v11; // r2
  volatile int *bb_dump_aux_reg; // r4
  int dump_config_value; // r5
  int bb_dump_ctrl_value; // r1
  const volatile char *dump_label; // r0
  int v16; // r3
  volatile unsigned int *v17; // r4
  volatile int *v18; // r5
  int v19; // r6

  *(volatile uint32_t *)off_103868 = dword_10386C;
  if ( a1 )
  {
    switch ( a1 )
    {
      case 1:
        v11 = (volatile unsigned int *)off_103870;
        bb_dump_aux_reg = (volatile int *)off_103874;
        dump_config_value = dword_10389C;
        bb_dump_ctrl_value = *(volatile uint32_t *)off_103870;
        dump_label = aDumpDac150m;
        v16 = *(volatile uint32_t *)off_103870 & 0x70 | 1;
        break;
      case 10:
        bb_dump_ctrl_reg = (volatile unsigned int *)off_103870;
        v2 = (volatile int *)off_103874;
        v3 = *(volatile uint32_t *)off_103870;
        v4 = dword_103894;
        v5 = *(volatile uint32_t *)off_103870;
        v6 = aDumpDpdTxRx;
        goto LABEL_24;
      case 14:
        bb_dump_ctrl_reg = (volatile unsigned int *)off_103870;
        v2 = (volatile int *)off_103874;
        v3 = *(volatile uint32_t *)off_103870;
        v4 = dword_1038A4;
        v5 = *(volatile uint32_t *)off_103870;
        v6 = aDumpLoftOut;
        goto LABEL_24;
      case 2:
        v11 = (volatile unsigned int *)off_103870;
        bb_dump_aux_reg = (volatile int *)off_103874;
        dump_config_value = dword_1038AC;
        bb_dump_ctrl_value = *(volatile uint32_t *)off_103870;
        dump_label = aDumpAdcIn;
        v16 = *(volatile uint32_t *)off_103870 & 0x70 | 2;
        break;
      default:
        switch ( a1 )
        {
          case 3:
            bb_dump_ctrl_reg = (volatile unsigned int *)off_103870;
            v2 = (volatile int *)off_103874;
            v3 = *(volatile uint32_t *)off_103870;
            v4 = dword_1038B4;
            v5 = *(volatile uint32_t *)off_103870;
            v6 = aDumpRxDataIq;
            break;
          case 30:
            bb_dump_ctrl_reg = (volatile unsigned int *)off_103870;
            v2 = (volatile int *)off_103874;
            v3 = *(volatile uint32_t *)off_103870;
            v4 = dword_1038BC;
            v5 = *(volatile uint32_t *)off_103870;
            v6 = aDumpRcAdcIq;
            break;
          case 31:
            bb_dump_ctrl_reg = (volatile unsigned int *)off_103870;
            v2 = (volatile int *)off_103874;
            v3 = *(volatile uint32_t *)off_103870;
            v4 = dword_1038CC;
            v5 = *(volatile uint32_t *)off_103870;
            v6 = aDumpDccancelOu;
            break;
          case 32:
            bb_dump_ctrl_reg = (volatile unsigned int *)off_103870;
            v2 = (volatile int *)off_103874;
            v3 = *(volatile uint32_t *)off_103870;
            v4 = dword_1038D4;
            v5 = *(volatile uint32_t *)off_103870;
            v6 = aDumpPreDgcOutI;
            break;
          case 33:
            bb_dump_ctrl_reg = (volatile unsigned int *)off_103870;
            v2 = (volatile int *)off_103874;
            v3 = *(volatile uint32_t *)off_103870;
            v4 = dword_1038DC;
            v5 = *(volatile uint32_t *)off_103870;
            v6 = aDumpNotchOutIq;
            break;
          default:
            if ( a1 != 4 )
            {
              if ( a1 == 5 )
              {
                bb_dump_ctrl_reg = (volatile unsigned int *)off_103870;
                v2 = (volatile int *)off_103874;
                v3 = *(volatile uint32_t *)off_103870;
                v4 = dword_1038E4;
                v5 = *(volatile uint32_t *)off_103870;
                v6 = aDumpRcOutIq;
                break;
              }
              if ( a1 != 50 )
              {
                switch ( a1 )
                {
                  case 6:
                    bb_dump_ctrl_reg = (volatile unsigned int *)off_103870;
                    v2 = (volatile int *)off_103874;
                    v3 = *(volatile uint32_t *)off_103870;
                    v4 = dword_1038EC;
                    v5 = *(volatile uint32_t *)off_103870;
                    v6 = aDumpRcStatus;
                    break;
                  case 7:
                    v17 = (volatile unsigned int *)off_103884;
                    v18 = (volatile int *)off_103874;
                    v19 = dword_103888;
                    *(volatile uint32_t *)off_103870 &= 0xFFFFFF70;
                    *v17 = *v17 & 0xFF00FFFF | 0x540000;
                    *v18 = v19;
                    dispatch_event_handler_1(aDumpLpfOutBpfO);
                    goto LABEL_22;
                  case 8:
                    bb_dump_ctrl_reg = (volatile unsigned int *)off_103870;
                    v2 = (volatile int *)off_103874;
                    v4 = dword_103888;
                    v6 = aDumpGainLoft2I;
                    *(volatile uint32_t *)off_103884 = *(volatile uint32_t *)off_103884 & 0xFF00FFFF | 0x570000;
                    v3 = *bb_dump_ctrl_reg;
                    v5 = *bb_dump_ctrl_reg;
                    break;
                  case 81:
                    bb_dump_ctrl_reg = (volatile unsigned int *)off_103870;
                    v2 = (volatile int *)off_103874;
                    v4 = dword_103888;
                    v6 = aDumpGainLoftIn;
                    *(volatile uint32_t *)off_103884 = *(volatile uint32_t *)off_103884 & 0xFF00FFFF | 0x30000;
                    v3 = *bb_dump_ctrl_reg;
                    v5 = *bb_dump_ctrl_reg;
                    break;
                  default:
                    bb_dump_ctrl_reg = (volatile unsigned int *)off_103870;
                    v2 = (volatile int *)off_103874;
                    v3 = *(volatile uint32_t *)off_103870;
                    v4 = dword_103878;
                    v5 = *(volatile uint32_t *)off_103870;
                    if ( a1 == 9 )
                      v6 = aDumpAuxFifoOut;
                    else
                      v6 = aReselectMode;
                    break;
                }
                break;
              }
            }
            bb_dump_ctrl_reg = (volatile unsigned int *)off_103870;
            v2 = (volatile int *)off_103874;
            v3 = *(volatile uint32_t *)off_103870;
            v4 = dword_1038C4;
            v5 = *(volatile uint32_t *)off_103870;
            v6 = aDumpRcInIq;
            break;
        }
LABEL_24:
        *bb_dump_ctrl_reg = v5 & 0xFFFFFF00 | v3 & 0x70;
        *v2 = v4;
        dispatch_event_handler_1(v6);
        goto LABEL_22;
    }
    *v11 = v16 | bb_dump_ctrl_value & 0xFFFFFF00;
    *bb_dump_aux_reg = dump_config_value;
    dispatch_event_handler_1(dump_label);
    goto LABEL_22;
  }
  v7 = (volatile unsigned int *)off_103884;
  v8 = (volatile int *)off_103874;
  v9 = dword_103888;
  *(volatile uint32_t *)off_103870 &= 0xFFFFFF70;
  *v7 = *v7 & 0xFF00FFFF | 0x770000;
  *v8 = v9;
  dispatch_event_handler_1(aDumpLoftPwrInO);
LABEL_22:
  *(volatile uint32_t *)off_103890 = 769;
  return write_timer_reg(500);
}


// enable_bb_clock @ 0x103900
int enable_bb_clock() {
  volatile int *v0; // r4
  volatile int *v1; // r3
  int v2; // r1
  volatile uint32_t *v3; // r2

  v0 = (volatile int *)off_10395C;
  *(volatile uint32_t *)off_103958 = 777;
  while ( *v0 < 0 )
    write_timer_reg(1);
  dispatch_event_handler_1("end_addr=%d\n", *(volatile uint32_t *)off_10395C);
  *(volatile uint32_t *)off_103958 = 0;
  dispatch_event_handler_1(aFinish);
  v1 = (volatile int *)off_10396C;
  v2 = dword_103970;
  v3 = (volatile uint32_t *)off_103974;
  *(volatile uint32_t *)off_103968 = 0;
  *v1 = v2;
  *v3 &= 0xFF00FFFF;
  return dispatch_event_handler_1("*0* dump    r 00100000 %d**\n", 0x4000);
}


// bb_reset @ 0x10397c
volatile int * bb_reset(int a1) {
  volatile unsigned int *v1; // r3
  int v2; // r5
  int v3; // r7
  int v4; // r12
  volatile unsigned int *v5; // lr
  int v6; // r6
  int v7; // r0
  volatile int *result; // r0
  int v9; // r4
  volatile int *v10; // r3
  volatile uint32_t *v11; // r2
  int v12; // t1

  v1 = (volatile unsigned int *)off_1039F8;
  *(volatile uint32_t *)off_1039F4 |= 0x100u;
  v2 = 0;
  v3 = -a1;
  v4 = a1 + 48;
  *v1 &= 0xFFFCFFFF;
  v5 = v1;
  v6 = 0;
  v7 = 128;
  while ( 1 )
  {
    result = (volatile int *)(v4 + 4 * (v7 + v2));
    v9 = dword_1039FC + v3;
    v10 = (volatile int *)(48 - v3);
    do
    {
      v11 = (void *)((volatile int *)((volatile char *)v10 + v9));
      v12 = *v10++;
      *v11 = v12;
    }
    while ( v10 != result );
    ++v6;
    if ( v2 == 256 )
      break;
    v2 += 128;
    v3 -= 512;
    *v5 = *v5 & 0xFFFCFFFF | (v6 << 16);
    if ( v6 == 2 )
      v7 = 32;
    else
      v7 = 128;
  }
  *(volatile uint32_t *)off_1039F4 &= ~0x100u;
  return result;
}



// configure_bb_winsize @ 0x103a00
int configure_bb_winsize(int a1, int a2, int a3) {
  int v3; // r1
  int v4; // r2
  volatile unsigned int *v5; // r3
  int v6; // r8
  int v7; // r12
  int v8; // r6
  volatile unsigned int *v9; // lr
  int v10; // r7
  int result; // r0
  int v12; // r4
  int v13; // r1
  int v14; // r1
  int v15; // r3
  volatile uint32_t *v16; // r3
  int v17; // r4
  int v18; // r5
  int v19; // r4

  v3 = 3 * a2;
  if ( !a3 )
  {
    v16 = (volatile uint32_t *)(a1 + 16 * v3);
    v17 = dword_103AC8;
    v16[13] = dword_103AC4;
    v16[14] = v17;
    v18 = dword_103ACC;
    v19 = dword_103AD0;
    v16[12] = dword_103AD4;
    v16[18] = 0;
    v16[19] = 0;
    v16[20] = 0;
    v16[21] = 0;
    v16[22] = 0;
    v16[23] = 0;
    v16[15] = dword_103AD8;
    v16[16] = v18;
    v16[17] = v19;
  }
  v4 = 4 * v3;
  v5 = (volatile unsigned int *)off_103AC0;
  v6 = dword_103ADC;
  *(volatile uint32_t *)off_103ABC |= 0x100u;
  v7 = 0;
  v8 = a1 + 48;
  *v5 &= 0xFFFCFFFF;
  v9 = v5;
  v10 = 0;
  result = 0;
  v12 = 4 * v3 + 11;
  v13 = 128;
  while ( 1 )
  {
    v14 = v13 + v10;
    v15 = v10;
    do
    {
      if ( v15 >= v4 && v15 <= v12 )
        *(volatile uint32_t *)(v7 + v6 + 4 * v15) = *(volatile uint32_t *)(v8 + 4 * v15);
      ++v15;
    }
    while ( v15 != v14 );
    if ( ++result == 3 )
      break;
    v10 += 128;
    v7 -= 512;
    *v9 = *v9 & 0xFFFCFFFF | (result << 16);
    if ( result == 2 )
      v13 = 32;
    else
      v13 = 128;
  }
  *(volatile uint32_t *)off_103ABC &= ~0x100u;
  return result;
}



// enable_rf_dll @ 0x103ae0
unsigned int enable_rf_dll(int a1, int a2) {
  volatile unsigned int *v2; // r2
  volatile unsigned int *v3; // r3
  int v4; // r4
  volatile uint32_t *v5; // r6
  unsigned int result; // r0

  v2 = (volatile unsigned int *)off_103B60;
  v3 = (volatile unsigned int *)off_103B64;
  v4 = *(volatile uint32_t *)off_103B60;
  v5 = (void *)(uintptr_t)(off_103B68);
  *(volatile uint32_t *)off_103B60 |= 0x1000000u;
  *v3 |= 0x8000u;
  *v3 &= ~0x400000u;
  *v3 &= ~0x200000u;
  *v3 |= 0x200000u;
  *v5 = a2;
  result = (a1 << 16) & 0x1F0000 | *v3 & 0xFFE0FFFF;
  *v3 = result;
  *v3 &= ~0x200000u;
  *v3 |= 0x200000u;
  *v3 &= ~0x8000u;
  *v3 |= 0x400000u;
  *v3 |= 0x200000u;
  *v2 = v4 & 0x1000000 | *v2 & 0xFEFFFFFF;
  return result;
}



// bb_hw_init @ 0x103b6c
volatile uint32_t *bb_hw_init() {
  volatile unsigned int *v0; // r4
  volatile unsigned int *v1; // r0
  volatile uint32_t *v2; // r5
  volatile uint32_t *v3; // r1
  volatile uint32_t *v4; // r2
  volatile unsigned int *v5; // r6
  volatile uint32_t *v6; // r1
  volatile uint32_t *result; // r0
  volatile uint32_t *v8; // r2
  int v9; // r4

  v0 = (volatile unsigned int *)off_103C44;
  v1 = (volatile unsigned int *)off_103C48;
  v2 = (void *)(uintptr_t)(off_103C4C);
  v3 = (void *)(uintptr_t)(off_103C50);
  v4 = (void *)(uintptr_t)(off_103C54);
  v5 = (volatile unsigned int *)off_103C58;
  *(volatile uint32_t *)off_103C44 &= ~0x200u;
  *v1 = *v1 & 0xFC000FFF | 0x333000;
  *v2 = 8;
  *v3 |= 0x1000000u;
  v0 -= 136;
  *v4 |= 0x2000000u;
  *v0 &= ~0x20000u;
  write_timer_reg(2);
  v6 = (void *)(uintptr_t)(off_103C5C);
  result = (void *)(uintptr_t)(off_103C60);
  v8 = (void *)(uintptr_t)(off_103C64);
  *v0 |= 0x10000u;
  *v0 |= 0x20000u;
  *v0 = *v0 & 0xFFFF0FFF | 0x6000;
  *v0 |= 0x80000u;
  v9 = dword_103C68;
  *v6 |= 0x80u;
  *result |= 8u;
  *v5 = *v5 & 0xFFFFF3FF | 0x800;
  *(volatile uint32_t *)((volatile char *)v2 + 0xFFFFFFF0) = *(volatile uint32_t *)((volatile char *)v2 + 0xFFFFFFF0) & 0xF8FFFFFF | 0x6000000;
  *v8 |= 0x20000000u;
  *v8 &= ~0x10000000u;
  v6[104] |= 0x80000000;
  *(volatile uint32_t *)((volatile char *)result + 0xFFFFFF68) = v9;
  *(volatile uint32_t *)((volatile char *)v2 + 0xFFFFFFD0) |= 0x1000000u;
  return result;
}



// disable_rx_path @ 0x103c6c
volatile unsigned int *disable_rx_path() {
  volatile unsigned int *v0; // r1
  volatile uint32_t *v1; // r0
  volatile unsigned int *v2; // r2
  volatile uint32_t *v3; // r6
  volatile uint32_t *v4; // r5
  volatile uint32_t *v5; // r4
  volatile unsigned int *result; // r0

  v0 = (volatile unsigned int *)off_103D48;
  v1 = (void *)(uintptr_t)(off_103D4C);
  v2 = (volatile unsigned int *)off_103D50;
  *(volatile uint32_t *)off_103D48 &= ~0x10000000u;
  v3 = (void *)(uintptr_t)(off_103D54);
  v4 = (void *)(uintptr_t)(off_103D58);
  v5 = (void *)(uintptr_t)(off_103D5C);
  *v1 &= ~0x200u;
  *v0 = *v0 & 0xFC000FFF | 0x333000;
  *v3 = 0;
  *v4 &= ~0x1000000u;
  *v2 = *v2 & 0xFFFF0FFF | 0xA000;
  *v2 &= ~0x20000u;
  *v2 &= ~0x10000u;
  *v2 &= ~0x80000u;
  *v5 &= ~0x20000000u;
  result = (void *)(v1 - 138);
  *v5 &= ~0x10000000u;
  v4 += 2046;
  *result &= 0xE7FFFFFF;
  *v4 &= ~0x2000000u;
  v2[8] = v2[8] & 0xFC00FFFF | 0x100000;
  v5[23] &= ~0x80u;
  v4[48] &= ~8u;
  *v0 = *v0 & 0xFFFFF000 | 0x80;
  *result = *result & 0xF8FFFFFF | 0x5000000;
  *(volatile unsigned int *)((volatile char *)v2 + 0xFFFFFFD8) &= ~0x1000000u;
  return result;
}



// sub_103d60 @ 0x103d60
int sub_103d60(int a1, int a2, volatile uint32_t *a3) {
  int v3; // r3
  int v4; // r4
  int result; // r0

  v3 = (uint16_t)*(volatile uint32_t *)off_103DA4;
  v4 = 0x3FFF;
  if ( v3 == 0x3FFF )
    a3 = (volatile uint32_t *)*a3;
  else
    v4 = v3 + 1;
  if ( v3 != 0x3FFF )
    a3 = (volatile uint32_t *)a3[v4];
  if ( ((uint8_t)a3 & 1) != 0 )
  {
    if ( a2 )
      goto LABEL_8;
  }
  else if ( a2 != 1 )
  {
LABEL_8:
    result = v3 + 2 + 2 * a1;
    goto LABEL_9;
  }
  result = v3 + 1 + 2 * a1;
LABEL_9:
  if ( result >= 0x4000 )
    result -= 0x4000;
  return result;
}



// wait_rf_ready @ 0x103da8
int wait_rf_ready() {
  BOOL v0; // r1
  int v1; // r2
  volatile int *v2; // r4
  int v3; // r7
  volatile int *v4; // r5
  int v5; // r6
  int v6; // lr
  int v7; // r12
  int v8; // r9
  int v9; // r8
  int v10; // r1
  int v11; // r0
  unsigned int v12; // r0
  unsigned int v13; // r3
  uint16_t v14; // r2
  int result; // r0
  int v16; // r3

  v0 = (MEMD(0x100000) & 1) == 0;
  v1 = 0;
  v2 = (volatile int *)(4 * (v0 + 0x40000));
  v3 = v0 + 278528;
  v4 = v2;
  v5 = 4 * (v0 + 278528);
  v6 = 0;
  v7 = 0;
  v8 = 0;
  v9 = 0;
  do
  {
    v10 = (unsigned int)*v4 >> 20;
    if ( *v4 < 0 )
      v10 -= 4096;
    v11 = (uint16_t)*v4 >> 4;
    if ( (((unsigned int)*v4 >> 4) & 0x800) != 0 )
      v11 -= 4096;
    if ( v7 < v10 )
      v7 = v10;
    v4 += 2;
    if ( v6 < v11 )
      v6 = v11;
    if ( v1 >= v10 )
      v1 = v10;
    v9 += v10;
    v8 += v11;
  }
  while ( v4 != (volatile int *)v5 );
  if ( v7 > 2040 || v6 > 2040 || v1 < -2040 )
    check_interrupt_flag(1, aWarningDataSat);
  check_interrupt_flag(1, "sum_i=%d\nsum_q=%d\ndc_i=%d\ndc_q=%d\n", v9, v8, v9 / 0x2000, v8 / 0x2000);
  do
  {
    v12 = *v2;
    v13 = (unsigned int)*v2 >> 20;
    if ( *v2 < 0 )
      v13 = (v13 & ~0xFFFFu) | ((uint16_t)(v13 - 4096) & 0xFFFFu);
    v14 = (uint16_t)v12 >> 4;
    result = v12 >> 4 << 20;
    v16 = (uint16_t)(v13 - v9 / 0x2000);
    if ( result < 0 )
      v14 -= 4096;
    *v2 = ((v16 + (v16 < 0 ? 0x1000 : 0)) << 20)
        + 65537
        + 16 * ((uint16_t)(v14 - v8 / 0x2000) + ((uint16_t)(v14 - v8 / 0x2000) < 0 ? 0x1000 : 0));
    v2 += 2;
  }
  while ( (volatile int *)(4 * v3) != v2 );
  return result;
}


// load_patch_data @ 0x103eb4
int load_patch_data() {
  volatile int *v0; // r1
  volatile uint32_t *v1; // r3
  int v2; // r0
  int v3; // r5
  volatile uint32_t *v4; // r6
  volatile int *v5; // r4
  int result; // r0
  volatile uint32_t *v7; // r3
  volatile uint32_t *v8; // r1

  v0 = (volatile int *)off_103F88;
  v1 = (void *)(uintptr_t)(off_103F90);
  v2 = dword_103F94;
  v3 = *(volatile uint32_t *)off_103F8C;
  *(volatile uint32_t *)off_103F8C = dword_103F98;
  *v0 = v2;
  v4 = (void *)(uintptr_t)(off_103F9C);
  v5 = (volatile int *)off_103FA0;
  *v1 = *v1 & 0xFC000FFF | 0x333000;
  *v1 &= 0x3FFFFFFFu;
  *v1 |= 0xC000000u;
  *v1 = ~(~(*v1 >> 12) << 12);
  v0[29] = v0[29] & 0xFFFFFF0F | 0xA0;
  *v1 |= 0x10000000u;
  write_timer_reg(10);
  *v4 = dword_103FA4;
  write_timer_reg(125);
  *v4 = dword_103FA8;
  while ( *v5 < 0 )
    write_timer_reg(1);
  check_interrupt_flag(1, "end_addr=%x\n", *(volatile uint32_t *)off_103FA0);
  *(volatile uint32_t *)off_103F9C = 0;
  check_interrupt_flag(1, aDumpFinish);
  *(volatile uint32_t *)off_103F8C = v3;
  wait_rf_ready();
  result = check_interrupt_flag(1, "** dump tone typ3   r 00100000 %d**\n", 0x4000);
  v7 = (void *)(uintptr_t)(off_103F90);
  v8 = (void *)(uintptr_t)(off_103FB8);
  *(volatile uint32_t *)off_103F90 &= 0xF3FFFFFF;
  *v8 |= 0xF0u;
  *v7 &= ~0x10000000u;
  *v7 &= 0x3FFFFFFFu;
  return result;
}


// lookup_rf_table @ 0x103fbc
int lookup_rf_table(int a1, int a2, volatile uint32_t *a3) {
  int v3; // r2
  unsigned int v4; // r0
  int v5; // r3

  v3 = a3[sub_103d60(a1, a2, a3)];
  v4 = (unsigned int)v3 >> 20;
  v5 = (uint16_t)v3 >> 4;
  if ( v3 < 0 )
    v4 -= 4096;
  if ( (((unsigned int)v3 >> 4) & 0x800) != 0 )
    v5 -= 4096;
  return v5 * v5 + v4 * v4;
}



// apply_tx_power @ 0x103ff0
int apply_tx_power(int a1, int a2, int a3) {
  unsigned int v3; // r3
  int v4; // r5
  int v5; // r0
  int v6; // r11
  int v7; // r10
  int v8; // r4
  int v9; // r0
  unsigned int v10; // s16
  uint64_t v11; // r8
  uint64_t v12; // r4
  uint64_t v13; // r6
  uint64_t v14; // r0
  uint64_t v15; // r0
  uint64_t v16; // r0
  uint64_t v17; // r0
  unsigned int v18; // r0
  uint64_t v19; // r0
  uint64_t v20; // r0
  int result; // r0
  uint64_t v22; // r0
  uint64_t v23; // r0
  unsigned int v24; // s16
  uint64_t v25; // r8
  uint64_t v26; // r4
  uint64_t v27; // r6
  uint64_t v28; // r0
  uint64_t v29; // r0
  uint64_t v30; // r0
  uint64_t v31; // r0
  uint64_t v32; // r0
  uint64_t v33; // r0

  v3 = *(volatile uint32_t *)(a3 + 4 * sub_103d60(a1, a2, (volatile uint32_t *)a3));
  v4 = (uint16_t)v3 >> 4;
  if ( (v3 & 0x80000000) == 0 )
  {
    v5 = v3 >> 20;
    if ( ((v3 >> 4) & 0x800) != 0 )
    {
      v4 -= 4096;
      v6 = 1;
      v7 = -1;
    }
    else
    {
      v6 = 1;
      v7 = 1;
    }
LABEL_4:
    v8 = i32_abs(v5);
    v9 = i32_abs(v4);
    if ( v8 < v9 )
      goto LABEL_5;
    goto LABEL_11;
  }
  v5 = (v3 >> 20) - 4096;
  if ( ((v3 >> 4) & 0x800) == 0 )
  {
    v6 = -1;
    v7 = 1;
    goto LABEL_4;
  }
  v8 = i32_abs(v5);
  v9 = i32_abs(v4 - 4096);
  v6 = -1;
  v7 = -1;
  if ( v8 < v9 )
  {
LABEL_5:
    *(volatile float *)&v10 = (float)v8 / (float)v9;
    v11 = ((uint64_t (*)())aeabi_d2f)(v10);
    v12 = ((uint64_t (*)())aeabi_dadd)(v11, *(volatile uint64_t *)&dword_1041D8);
    v13 = ((uint64_t (*)())aeabi_d2f)(COERCE_UNSIGNED_INT((float)(*(volatile float *)&v10 - 1.0) * *(volatile float *)&v10));
    v14 = ((uint64_t (*)())aeabi_dadd)(v11, *(volatile uint64_t *)&dword_1041E0);
    v15 = double_add(v14, *(volatile uint64_t *)&dword_1041E8);
    v16 = ((uint64_t (*)())aeabi_dadd)(v13, v15);
    v17 = ((uint64_t (*)())double_subtract)(v12, v16);
    v18 = ((int (*)(uint64_t))aeabi_dmul)(v17);
    v19 = ((uint64_t (*)())aeabi_d2f)(v18);
    v20 = ((uint64_t (*)())double_subtract)(*(volatile uint64_t *)&dword_1041F0, v19);
    result = ((int (*)(uint64_t))aeabi_dmul)(v20);
    if ( v7 != 1 )
      goto LABEL_16;
    goto LABEL_12;
  }
LABEL_11:
  *(volatile float *)&v24 = (float)v9 / (float)v8;
  v25 = ((uint64_t (*)())aeabi_d2f)(v24);
  v26 = ((uint64_t (*)())aeabi_dadd)(v25, *(volatile uint64_t *)&dword_1041D8);
  v27 = ((uint64_t (*)())aeabi_d2f)(COERCE_UNSIGNED_INT((float)(*(volatile float *)&v24 - 1.0) * *(volatile float *)&v24));
  v28 = ((uint64_t (*)())aeabi_dadd)(v25, *(volatile uint64_t *)&dword_1041E0);
  v29 = double_add(v28, *(volatile uint64_t *)&dword_1041E8);
  v30 = ((uint64_t (*)())aeabi_dadd)(v27, v29);
  v31 = ((uint64_t (*)())double_subtract)(v26, v30);
  result = ((int (*)(uint64_t))aeabi_dmul)(v31);
  if ( v7 != 1 )
  {
LABEL_16:
    if ( v6 == 1 )
      return result ^ 0x80000000;
    v22 = ((uint64_t (*)())aeabi_d2f)(result);
    v23 = ((uint64_t (*)())double_subtract)(v22, *(volatile uint64_t *)&dword_1041F8);
    return ((int (*)(uint64_t))aeabi_dmul)(v23);
  }
LABEL_12:
  if ( v6 != 1 )
  {
    v32 = ((uint64_t (*)())aeabi_d2f)(result ^ 0x80000000);
    v33 = double_add(v32, *(volatile uint64_t *)&dword_1041F8);
    return ((int (*)(uint64_t))aeabi_dmul)(v33);
  }
  return result;
}


// tx_power_calibrate @ 0x104200
int tx_power_calibrate(int a1, int a2, volatile uint32_t *a3) {
  int v3; // r3
  int v6; // r10
  int v7; // r6
  int v8; // r9
  float v9; // s14
  int v10; // r11
  int v11; // r10
  int v12; // r5
  int v13; // r4
  int v14; // r4
  int v15; // r3
  float v16; // s13
  volatile int *v17; // r11
  int v18; // r5
  int v19; // r6
  int v20; // r4
  int v21; // r0
  int v22; // r3
  float v23; // s13
  volatile float *v24; // r1
  int v25; // r0
  int v26; // r4
  float v27; // s15
  int result; // r0
  struct __attribute__((packed)) { union { int v29; // [sp+4h] [bp-A8h]
  int v30; }; // [sp+4h] [bp-A8h]
  int v31; // [sp+8h] [bp-A4h]
  int v32; // [sp+Ch] [bp-A0h]
  int v33; // [sp+10h] [bp-9Ch]
  int v34; // [sp+14h] [bp-98h]
  char _pad5[4]; int v35; // [sp+1Ch] [bp-90h]
  char _pad6[4]; int v36; // [sp+24h] [bp-88h]
  float v37; // [sp+28h] [bp-84h] BYREF
  float v38; // [sp+2Ch] [bp-80h]
  } _frame;
  if ( a1 )
    v3 = 2560;
  else
    v3 = 1280;
  if ( a1 )
    v6 = 528;
  else
    v6 = 256;
  _frame.v32 = v3;
  if ( a1 )
    v7 = 2624;
  else
    v7 = 1344;
  if ( a1 )
    v8 = 32;
  else
    v8 = 16;
  memset((volatile int *)&_frame.v37, 0, 0x80u);
  v9 = flt_1043D4;
  _frame.v29 = v6;
  v10 = 10;
  v11 = 0;
  do
  {
    v12 = v10;
    v10 += v8;
    v13 = lookup_rf_table(v10, a2, a3);
    v14 = v13 - lookup_rf_table(v12, a2, a3);
    if ( (float)v14 < v9 )
    {
      v9 = (float)v14;
      v11 = v12;
    }
  }
  while ( v10 < v7 );
  _frame.v35 = v11;
  v15 = v11 - _frame.v29;
  if ( v11 - _frame.v29 <= 0 )
  {
    _frame.v35 = v11 + _frame.v32;
    v15 = v11 + _frame.v32 - _frame.v29;
    _frame.v36 = 1;
  }
  else
  {
    _frame.v36 = 0;
  }
  _frame.v33 = v15 - 1;
  v16 = flt_1043D4;
  _frame.v34 = v15;
  v17 = (volatile int *)&_frame.v37;
  do
  {
    _frame.v31 = 9;
    *(volatile float *)v17++ = v16;
    _frame.v30 = _frame.v34;
    do
    {
      v18 = _frame.v30;
      v19 = 5;
      do
      {
        v20 = lookup_rf_table(v18, a2, a3);
        v21 = lookup_rf_table(_frame.v33 - _frame.v34 + v18, a2, a3);
        --v19;
        v18 += v8;
        *((volatile float *)v17 - 1) = *((volatile float *)v17 - 1) + (float)(v20 - v21);
      }
      while ( v19 );
      _frame.v30 += _frame.v32;
      --_frame.v31;
    }
    while ( _frame.v31 );
    ++_frame.v34;
    ++_frame.v33;
  }
  while ( v17 != (volatile int *)(&_frame.v37 + v8) );
  v22 = 0;
  v23 = flt_1043D4;
  v24 = &_frame.v37;
  v25 = 0;
LABEL_32:
  if ( (float)((float)(_frame.v37 + _frame.v38) * 0.5) > v23 )
  {
    v23 = (float)(_frame.v37 + _frame.v38) * 0.5;
    v25 = v22;
  }
  do
  {
    ++v22;
    ++v24;
    if ( !v22 )
      goto LABEL_32;
    if ( v8 - 1 == v22 )
    {
      v26 = v8;
      v27 = (float)(*v24 + *(v24 - 1)) * 0.5;
    }
    else
    {
      v26 = v22 + 1;
      v27 = (float)((float)(*(v24 - 1) + *v24) + v24[1]) / 3.0;
    }
    if ( v27 > v23 )
    {
      v23 = v27;
      v25 = v22;
    }
  }
  while ( v26 < v8 );
  result = _frame.v35 + v25 + 1;
  if ( _frame.v36 )
    result -= _frame.v32;
  return result;
}



// wlan_init_globals @ 0x1043d8
int wlan_init_globals(int a1, int a2, int a3, int a4, int a5, int a6) {
  volatile int *v7; // r6
  int v11; // r0
  int v12; // r1
  int v13; // r2
  int v14; // r3
  int v15; // r1
  int v16; // r2
  int v17; // r3
  int v18; // r0
  int v19; // r6
  int v20; // r2
  int v21; // r5
  int v22; // r3
  volatile uint32_t *v23; // r3
  float v24; // s23
  float v25; // s20
  float v26; // s19
  float v27; // s18
  float v28; // s21
  float v29; // s22
  int v30; // r8
  int v31; // r9
  int v32; // r3
  float v33; // s14
  int v34; // r7
  int v35; // r0
  float v36; // s17
  int i; // r5
  float v38; // s16
  float v39; // s15
  float v40; // s17
  float v41; // s17
  float v42; // s18
  float v43; // s17
  float v44; // s16
  volatile float *v45; // r4
  int j; // r5
  float v47; // s15
  float v48; // r0
  volatile char *v49; // r2
  float v50; // s15
  float v51; // s16
  volatile float *v52; // r5
  float v53; // s14
  int result; // r0
  int v55; // r0
  struct __attribute__((packed)) { int v56; // [sp+8h] [bp-14Ch]
  int v57; // [sp+Ch] [bp-148h]
  int v58; // [sp+10h] [bp-144h]
  char _pad3[4]; int v59; // [sp+18h] [bp-13Ch]
  int v60; // [sp+1Ch] [bp-138h]
  char _pad5[4]; int v61; // [sp+24h] [bp-130h]
  char _pad6[8]; uint32_t v63[8]; // [sp+30h] [bp-124h]
  char a1a[128]; // [sp+50h] [bp-104h] BYREF
  char v65[132]; // [sp+D0h] [bp-84h] BYREF
  } _frame;
  v7 = (volatile int *)off_104704;
  check_interrupt_flag(1, aRunparescore);
  memcpy(_frame.a1a, (volatile char *)off_104708, 0x80u);
  v11 = *v7;
  v12 = v7[1];
  v13 = v7[2];
  v14 = v7[3];
  v7 += 4;
  _frame.v63[0] = v11;
  _frame.v63[1] = v12;
  _frame.v63[2] = v13;
  _frame.v63[3] = v14;
  v15 = v7[1];
  v16 = v7[2];
  v17 = v7[3];
  _frame.v63[4] = *v7;
  _frame.v63[5] = v15;
  _frame.v63[6] = v16;
  _frame.v63[7] = v17;
  memcpy(_frame.v65, (volatile char *)v7 + 16, 0x80u);
  v18 = tx_power_calibrate(0, 0, (void *)(uintptr_t)(a3));
  v19 = v18;
  _frame.v58 = a1 + 128;
  _frame.v59 = a1 + 384;
  if ( a2 == 1 )
  {
    v55 = tx_power_calibrate(0, 1, (void *)(uintptr_t)(a4));
    if ( v19 < v55 )
      v19 += 1280;
    v21 = v55;
    v20 = v19 - v55;
  }
  else
  {
    v20 = v18;
    v21 = 0;
  }
  v22 = ((int)((uint64_t)((int32_t)dword_10470C * (int64_t)(int32_t)(0x2000 - v19)) >> 32) >> 9) - ((0x2000 - v19) >> 31);
  if ( a6 )
  {
    if ( v22 >= 5 )
      v22 = 5;
  }
  else if ( v22 >= 10 )
  {
    v22 = 10;
  }
  _frame.v60 = v22;
  check_interrupt_flag(1, " est tx start = %4d, est rx start = %4d, dly = %d, total seg = %d, \n", v21, v19, v20, v22);
  v23 = (volatile uint32_t *)(a1 + 128);
  do
  {
    *v23++ = 0;
    v23[63] = 0;
  }
  while ( v23 != (volatile uint32_t *)(a1 + 256) );
  if ( _frame.v60 > 0 )
  {
    v24 = flt_104714;
    v25 = flt_104718;
    v26 = flt_10471C;
    v27 = flt_104720;
    _frame.v57 = v19;
    v28 = flt_104714;
    _frame.v61 = v21 - v19;
    do
    {
      v29 = flt_104724;
      v30 = 0;
      v31 = 2;
      while ( 1 )
      {
        if ( a6 == 1 && !*((volatile uint8_t *)_frame.v63 + v31) )
          goto LABEL_12;
        v33 = flt_104714;
        _frame.v56 = *(volatile uint32_t *)&_frame.v65[4 * v31];
        v34 = _frame.v56 + _frame.v57;
        do
        {
          v35 = lookup_rf_table(v34++, 0, (void *)(uintptr_t)(a3));
          v33 = v33 + (float)v35;
        }
        while ( v34 != _frame.v56 + _frame.v57 + 12 );
        *(volatile float *)(_frame.v58 + 4 * v31) = *(volatile float *)(_frame.v58 + 4 * v31) + v33;
        if ( v31 <= 1 )
        {
LABEL_12:
          v32 = v30 + 1;
          if ( v30 == 31 )
            break;
          goto LABEL_13;
        }
        v36 = flt_104714;
        for ( i = 1; ; ++i )
        {
          v38 = COERCE_FLOAT(apply_tx_power(_frame.v56 + _frame.v57 - 1 + i, 0, a3));
          v39 = v38 - COERCE_FLOAT(apply_tx_power(_frame.v56 + _frame.v61 + _frame.v57 - 1 + i, 1, a4));
          if ( v39 < v25 )
            v39 = v39 + v26;
          if ( v39 > v27 )
            v39 = v39 - v26;
          if ( i == 1 )
          {
            v36 = v36 + v39;
            v28 = v39;
            continue;
          }
          if ( (float)(v39 - v28) <= v27 )
            break;
          v36 = v36 + (float)(v39 - v26);
          if ( i == 12 )
            goto LABEL_34;
LABEL_24:
          ;
        }
        if ( (float)(v39 - v28) < v25 )
          v39 = v39 + v26;
        v36 = v36 + v39;
        if ( i != 12 )
          goto LABEL_24;
LABEL_34:
        v40 = v36 * v29;
        if ( v40 <= 1.0 )
        {
          if ( v40 < -1.0 )
            v40 = v40 + 2.0;
          if ( v31 == 2 )
            goto LABEL_48;
LABEL_36:
          v41 = v40 - v24;
          if ( v41 <= 1.0 )
          {
            if ( v41 < -1.0 )
              v41 = v41 + 2.0;
          }
          else
          {
            v41 = v41 - 2.0;
          }
        }
        else
        {
          v40 = v40 - 2.0;
          if ( v31 != 2 )
            goto LABEL_36;
LABEL_48:
          v24 = v40;
          v41 = flt_104714;
        }
        *(volatile float *)(4 * v31 + _frame.v59) = *(volatile float *)(4 * v31 + _frame.v59) + v41;
        v32 = v30 + 1;
        if ( v30 == 31 )
          break;
LABEL_13:
        if ( v32 <= 2 )
          v31 = v30;
        else
          v31 = v32;
        v30 = v32;
      }
      _frame.v57 += 1280;
    }
    while ( _frame.v57 != v19 + 1280 * _frame.v60 );
  }
  v42 = flt_104728;
  v43 = flt_10472C;
  v44 = (float)_frame.v60;
  v45 = (volatile float *)a1;
  for ( j = 1; ; ++j )
  {
    v48 = hash_const_init((float)(v45[32] / v44) / 12.0);
    v49 = &_frame.a1a[4 * j];
    v45[32] = v48;
    if ( (unsigned int)(j - 1) > 1 )
      break;
    v50 = (float)*((volatile int *)v49 - 1) * v42;
    v45[96] = (float)(*(volatile float *)(a1 + 392) / v44) * v43;
    *v45 = v50;
LABEL_42:
    ++v45;
  }
  v47 = (float)*((volatile int *)v49 - 1) * v42;
  v45[96] = (float)(v45[96] / v44) * v43;
  *v45 = v47;
  if ( j != 32 )
    goto LABEL_42;
  v51 = flt_1047B0;
  check_interrupt_flag(1, aAmBeginAmBackP);
  v52 = (volatile float *)a1;
  do
  {
    v53 = *v52++;
    result = check_interrupt_flag(
               1,
               "%10d %10d %10d\n",
               (int)(float)(v53 * v51),
               (int)(float)(v52[31] * v51),
               (int)(float)(v52[95] * v51));
  }
  while ( (volatile float *)_frame.v58 != v52 );
  return result;
}


