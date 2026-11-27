// check_firmware_state @ 0x102a38
int check_firmware_state() {
  int result; // r0

  result = ke_event_schedule_1("%s\r\n", aIntcSpurious);
  if ( **(volatile int16_t **)off_102A68 < 0 )
    return mmio_irq_clear(off_102A70, (int)aIntcSpurious_0, 61);
  return result;
}


// enable_nvic_irq @ 0x102a74
int enable_nvic_irq() {
  volatile uint32_t *v0; // r2
  volatile uint8_t *v1; // r3
  int v2; // r1
  int v4; // r6
  void *v5; // r5
  int v6; // r6
  void *v7; // r7
  void *v8; // r5

  v0 = (void *)(uintptr_t)(off_102ADC);
  v1 = (void *)(uintptr_t)(off_102AE0);
  *(volatile uint32_t *)(*((volatile uint32_t *)off_102ADC + 2) + 80) = dword_102AE4;
  *(volatile uint32_t *)v1 = 16;
  v2 = dword_102AE8;
  *(volatile uint32_t *)(v0[2] + 84) = dword_102AE8;
  *(volatile uint32_t *)v1 = 32;
  v4 = dword_102AEC;
  *(volatile uint32_t *)(v0[2] + 92) = v2;
  *(volatile uint32_t *)v1 = 128;
  v5 = (void *)(uintptr_t)(off_102AF0);
  *(volatile uint32_t *)(v0[2] + 72) = v4;
  *(volatile uint32_t *)v1 = 4;
  v6 = dword_102AF4;
  *(volatile uint32_t *)(v0[2] + 88) = (int)(uintptr_t)(v5);
  *(volatile uint32_t *)v1 = 64;
  v7 = (void *)(uintptr_t)(off_102AF8);
  *(volatile uint32_t *)(v0[2] + 76) = v6;
  v1[771] = -8;
  *(volatile uint32_t *)v1 = 8;
  v8 = (void *)(uintptr_t)(off_102AFC);
  *(volatile uint32_t *)(v0[2] + 208) = (int)(uintptr_t)(v7);
  *((volatile uint32_t *)v1 + 1) = 16;
  *(volatile uint32_t *)(v0[2] + 212) = (int)(uintptr_t)(v8);
  *((volatile uint32_t *)v1 + 1) = 32;
  *(volatile uint32_t *)v1 = 0x800000;
  *((volatile uint32_t *)v1 + 1) = 64;
  __enable_irq();
  return 32;
}



// set_radio_ctrl_bits @ 0x102b00
volatile int * set_radio_ctrl_bits(int a1) {
  int v1; // r4
  int v2; // r1
  int v3; // zf
  int v4; // r2
  int v5; // r2
  int v6; // r3
  volatile int *result; // r0
  int v8; // r2
  int v9; // r3

  v2 = (int)off_102B60;
  v3 = a1 == 0;
  if ( a1 )
    v4 = -2;
  else
    v4 = -17;
  v5 = v4 & *(volatile uint32_t *)off_102B60;
  if ( !a1 )
    a1 = -33;
  *(volatile uint32_t *)off_102B60 = v5;
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
  result = (volatile int *)off_102B60;
  v8 = v9 | v2;
  *(volatile uint32_t *)off_102B60 = v9;
  v9 = (v9 & ~0xFFu) | ((uint8_t)(50) & 0xFFu);
  *result = v8;
  do
    v9 = (uint8_t)(v9 - 1);
  while ( v9 );
  *(volatile uint32_t *)off_102B60 = v8 | v1;
  return result;
}



// set_radio_ctrl_bits2 @ 0x102b64
int set_radio_ctrl_bits2(int result) {
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
  v4 = *(volatile uint32_t *)off_102BD0 & v3;
  if ( !result )
    result = 32;
  *(volatile uint32_t *)off_102BD0 = v4;
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
  *(volatile uint32_t *)off_102BD0 = v6;
  v7 = (v7 & ~0xFFu) | ((uint8_t)(50) & 0xFFu);
  do
    v7 = (uint8_t)(v7 - 1);
  while ( v7 );
  v8 = v6 | result;
  *(volatile uint32_t *)off_102BD0 = v8;
  v9 = (v9 & ~0xFFu) | ((uint8_t)(50) & 0xFFu);
  do
    v9 = (uint8_t)(v9 - 1);
  while ( v9 );
  *(volatile uint32_t *)off_102BD0 = v8 | v3;
  return result;
}



// radio_event_loop @ 0x102bd4
int radio_event_loop(int a1, volatile uint16_t *a2) {
  unsigned int v4; // r11
  int v5; // r8
  int v6; // r10
  volatile unsigned int *v7; // r6
  int v8; // r5
  volatile uint16_t *v9; // r7
  unsigned int v10; // r4
  int v11; // t1
  unsigned int v12; // r4
  int v13; // r3
  int result; // r0
  int v15; // r4
  int16_t v16; // r12
  volatile char *v17; // r7
  int v18; // r6
  volatile char *v19; // r12
  int v20; // r3
  volatile uint16_t *v21; // r1
  int v22; // t1
  struct __attribute__((packed)) { int v23; // [sp+8h] [bp-24h]
  volatile uint16_t *v24; // [sp+Ch] [bp-20h]
  char _pad2[4]; uint64_t v25; // [sp+14h] [bp-18h] BYREF
  int v26; // [sp+1Ch] [bp-10h]
  } _frame;
  while ( !*(volatile uint32_t *)off_102CF0 )
    ;
  v4 = 0;
  set_radio_ctrl_bits(0);
  v5 = dword_102D00;
  _frame.v23 = 0;
  _frame.v24 = a2;
  v6 = a1;
  while ( ((1 << v4) & v6) == 0 )
  {
    if ( (uint16_t)v4 == 5 )
      goto LABEL_10;
LABEL_4:
    ++v4;
  }
  v7 = (volatile unsigned int *)(dword_102CF4 + (v4 << 9));
  v8 = 0;
  v9 = _frame.v24 - 1;
  do
  {
    v10 = *v7;
    state_check_feature(0x2000, "before %d,%d: dcq/i=%4x\r\n", v4, v8, (uint16_t)(*v7 >> 11));
    v11 = v9[1];
    ++v9;
    v12 = v10 & v5 | (v11 << 11);
    *v7 = v12;
    v7 += 8;
    v13 = v8++;
    state_check_feature(0x2000, "after  %d,%d: dcq/i=%4x\r\n", v4, v13, (uint16_t)(v12 >> 11));
  }
  while ( v8 != 16 );
  if ( v4 <= 1 )
    goto LABEL_4;
  _frame.v23 = 1;
  if ( (uint16_t)v4 != 5 )
    goto LABEL_4;
LABEL_10:
  result = set_radio_ctrl_bits2(0);
  *(volatile uint32_t *)off_102CF0 = 1;
  if ( _frame.v23 )
  {
    v15 = *(volatile uint32_t *)off_102CFC;
    _frame.v25 = *(volatile uint64_t *)off_102CFC;
    _frame.v26 = *(volatile uint32_t *)(off_102CFC + 8);
    v16 = 3;
  }
  else
  {
    v15 = qword_102D04;
    _frame.v26 = 0;
    _frame.v25 = qword_102D04;
    v16 = 2;
  }
  v17 = (volatile char *)&_frame.v25 + 4;
  v18 = dword_102D00;
  v19 = (volatile char *)&_frame.v25 + 4 * (uint16_t)(v16 - 1) + 4;
  while ( 1 )
  {
    v20 = v15;
    v21 = _frame.v24;
    do
    {
      if ( v15 )
      {
        result = *v21;
        *(volatile uint32_t *)(v20 + 16) = *(volatile uint32_t *)(v20 + 16) & v18 | (result << 11);
      }
      v20 += 20;
      ++v21;
    }
    while ( v15 + 320 != v20 );
    if ( v19 == v17 )
      break;
    v22 = *(volatile uint32_t *)v17;
    v17 += 4;
    v15 = v22;
  }
  return result;
}


// sub_102d10 @ 0x102d10
int sub_102d10(int a1, int a2, unsigned int a3, int a4) {
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
    v6 = 16 * (dword_102DA0 + a2);
    v7 = 4;
    v8 = 3;
  }
  else
  {
    v6 = 32 * (dword_102D98 + a2);
    v7 = 8;
    v8 = 5;
  }
  while ( !*(volatile uint32_t *)off_102D9C )
    ;
  set_radio_ctrl_bits(a1);
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
  result = set_radio_ctrl_bits2(a1);
  *(volatile uint32_t *)off_102D9C = 1;
  return result;
}



// copy_config_struct @ 0x102da4
int copy_config_struct() {
  uint64_t v0; // kr00_8
  int v1; // r4

  v0 = *(volatile uint64_t *)(off_102DD4 + 4);
  v1 = *(volatile uint32_t *)off_102DD4;
  sub_102d10(0, 32, 0x10u, SHIDWORD(v0));
  sub_102d10(0, 48, 0x10u, v0);
  return sub_102d10(0, 64, 0x10u, v1);
}


// radio_process_packet @ 0x102dd8
int radio_process_packet() {
  volatile uint8_t *v0; // r3
  volatile uint32_t *v1; // r2
  volatile uint32_t *v2; // r1
  volatile unsigned int *v3; // r4
  volatile unsigned int *v4; // r0
  volatile unsigned int *v5; // r5
  volatile uint32_t *v6; // r3
  volatile uint8_t *v7; // r6
  volatile uint32_t *v8; // r1
  volatile uint32_t *v9; // r3
  volatile uint32_t *v10; // r4
  volatile unsigned int *v11; // r2
  volatile uint8_t *v12; // r0
  volatile uint32_t *v13; // r1
  int result; // r0
  volatile unsigned int *v15; // r2
  volatile uint32_t *v16; // r3
  volatile uint32_t *v17; // r3
  volatile uint32_t *v18; // r2
  volatile unsigned int *v19; // r0
  volatile uint32_t *v20; // r2

  if ( *((volatile uint8_t *)off_102FF0 + 2) )
  {
    *(volatile uint32_t *)off_10303C = *(volatile uint32_t *)off_10303C & 0xFFFFF3FF | 0x800;
  }
  else
  {
    v0 = (void *)(uintptr_t)(off_102FF4);
    v1 = (void *)(uintptr_t)(off_102FF8);
    *(volatile uint8_t *)off_102FF4 = 80;
    v0[1] = 78;
    while ( !*v1 )
      ;
    v2 = (void *)(uintptr_t)(off_103000);
    *(volatile uint32_t *)off_102FFC &= ~2u;
    if ( (*v2 & 1) == 0 )
    {
      adc_read_ch0(1);
      v20 = (void *)(uintptr_t)(off_103054);
      *(volatile uint32_t *)off_103050 = *(volatile uint32_t *)off_103050 & 0xFFFFFFF0 | 4;
      *v20 |= 2u;
    }
    v3 = (volatile unsigned int *)off_103004;
    v4 = (volatile unsigned int *)off_103008;
    v5 = (volatile unsigned int *)off_10300C;
    v6 = (void *)(uintptr_t)(off_103010);
    v7 = (volatile uint8_t *)off_103014;
    *(volatile uint32_t *)off_102FF8 = 1;
    *v3 = *v3 & 0xFF0FFFFF | 0xC00000;
    *v3 = *v3 & 0xFFFFFF0F | 0x60;
    *v4 &= ~1u;
    *v5 = *v5 & 0xFFFFE0FF | 0x1000;
    *v6 |= 8u;
    *v6 &= 0xFFFFFFFC;
    *(volatile unsigned int *)((volatile char *)v3 + 0xFFFFFFB8) &= ~0x40000u;
    *v6 &= ~4u;
    v8 = (void *)(uintptr_t)(off_103018);
    *v4 = *v4 & 0xFFFFF3FF | 0x800;
    *(volatile unsigned int *)((volatile char *)v5 + 0xFFFFFF94) &= 0xFFFF3FFF;
    *(v3 - 1996) = *(v3 - 1996) & 0xFFFFFF | 0x10000000;
    v4 -= 2045;
    *v8 = *v8 & 0xFFFC00FF | (*v7 << 8);
    v9 = (void *)(uintptr_t)(off_10301C);
    v5 -= 2072;
    *v4 |= 0x80000000;
    *v5 |= 0x1000u;
    *v8 &= ~0x40000u;
    *v4 &= ~0x40000000u;
    v10 = (void *)(uintptr_t)(off_103020);
    *v9 &= ~2u;
    *v9 |= 1u;
    v8 += 2062;
    v5[2083] = 20058;
    *v8 = *v8 & 0x3FFFFFF | 0x7C000000;
    *v8 = *v8 & 0xFC07FFFF | 0x3E00000;
    if ( (*v10 & 0x20) != 0 )
    {
      v17 = (void *)(uintptr_t)(off_103044);
      *((volatile uint8_t *)off_103024 + 1) = 1;
      v18 = (void *)(uintptr_t)(off_103048);
      v19 = (volatile unsigned int *)off_10304C;
      *v17 &= 0xFFF0FFFF;
      *v17 &= 0xFF0FFFFF;
      *v18 &= ~0x8000u;
      *v19 = *v19 & 0xFFFFFC7F | 0x200;
    }
    else
    {
      *((volatile uint8_t *)off_103024 + 1) = 0;
    }
    v11 = (volatile unsigned int *)off_103028;
    v12 = (volatile uint8_t *)off_10302C;
    v13 = (void *)(uintptr_t)(off_103030);
    *(volatile uint32_t *)off_103028 = *(volatile uint32_t *)off_103028 & 0x3FFFFFF | 0xA0000000;
    result = v12[362];
    *v11 = *v11 & 0xFC0FFFFF | 0x1800000;
    *v13 |= 0x10u;
    if ( result )
      *(v11 - 8824) = *(v11 - 8824) & 0xFFFFFFC0 | 0x2C;
    v15 = (volatile unsigned int *)off_103038;
    *(volatile uint32_t *)off_103034 &= 0xFFFFFFC7;
    *v15 = *v15 & 0xFFFFFFFC | 2;
  }
  v16 = (void *)(uintptr_t)(off_103040);
  *(volatile uint32_t *)off_103040 |= 0xC000u;
  *v16 |= 0x30000u;
  return result;
}



// radio_set_power @ 0x103058
unsigned int radio_set_power(unsigned int result) {
  if ( result )
  {
    if ( *((volatile uint8_t *)off_1030A8 + 362) )
      result = write_mmio_byte(0xB5u);
    *(volatile uint32_t *)off_1030AC |= 2u;
  }
  else
  {
    if ( *((volatile uint8_t *)off_1030A8 + 362) )
      result = write_mmio_byte(0xC2u);
    *(volatile uint32_t *)off_1030AC &= ~2u;
  }
  return result;
}



// read_hw_status @ 0x1030b0
volatile uint32_t *read_hw_status() {
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
  v0 = *(volatile uint32_t *)(dword_103120 + 4);
  v1 = *(volatile uint32_t *)(dword_103120 + 8);
  v2 = *(volatile uint32_t *)(dword_103120 + 12);
  _frame.v11 = *(volatile uint32_t *)dword_103120;
  _frame.v12 = v0;
  _frame.v13 = v1;
  _frame.v14 = v2;
  if ( (*((volatile uint32_t *)off_103124 + 4) & 2) != 0 )
  {
    v3 = dword_10312C;
    v4 = &_frame.v15[*((volatile uint32_t *)off_103124 + 9) & 0xF];
    v5 = (char)*(v4 - 16);
    v6 = (uint8_t)*(v4 - 16);
    if ( (*((volatile uint32_t *)off_103124 + 4) & 4) == 0 )
      v3 = dword_103128;
    if ( v5 < 0 )
    {
      v3 *= 2;
      v6 &= 0x7Fu;
    }
    v7 = v3 / v6;
  }
  else
  {
    v7 = 2 * *(volatile uint32_t *)off_10313C;
  }
  result = (void *)(uintptr_t)(off_103134);
  v9 = (volatile unsigned int *)off_103138;
  v10 = v7 / (uint8_t)*((volatile uint32_t *)off_103124 + 8);
  *(volatile uint32_t *)off_103130 = v10;
  *v9 = v10 / (uint8_t)result[9];
  return result;
}



// wait_for_hw_data @ 0x103140
/* luna: Busy-waits until the hardware timer advances by the requested number of ticks. */
unsigned int wait_for_hw_data(unsigned int result) {
  volatile unsigned int start_tick; // r1
  unsigned int elapsed_ticks; // r3

  start_tick = (*(volatile uint32_t *)0x40501010u);
  do
    elapsed_ticks = (*(volatile uint32_t *)0x40501010u) - start_tick;
  while ( elapsed_ticks < result );
  return result;
}


// hw_init @ 0x103154
int hw_init(int a1) {
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

  v1 = (volatile uint32_t *)dword_1032B8;
  v2 = (volatile uint32_t *)dword_1032BC;
  *(volatile uint32_t *)dword_1032B8 |= 0x10u;
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
      state_check_feature(0x2000, "%x -> %x\n", v6, v8);
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
  *(volatile uint32_t *)dword_1032B8 = ((v5 + 2) << 8) & 0x1FC00 | *(volatile uint32_t *)dword_1032B8 & 0xFFFE03FF;
  v19 = ((unsigned int)v5 + 2) >> 2;
  result = printf_wrapper("%dM mdll duty: %x\n", 40 * a1 + 280, v19);
  if ( a1 )
    *(volatile uint8_t *)(dword_1032CC + 1) = v19;
  else
    *(volatile uint8_t *)dword_1032CC = v19;
  return result;
}


// hw_enable @ 0x1032d0
int hw_enable() {
  volatile uint8_t *v0; // r4
  volatile int *v1; // r2
  volatile uint32_t *v2; // r0
  int v3; // r1
  volatile uint32_t *v4; // r5
  volatile uint8_t **v5; // r5
  volatile uint32_t *v6; // r1
  int v7; // r6
  volatile uint32_t *v8; // r0
  volatile int *v9; // r8
  int v10; // r2
  volatile uint32_t *v11; // r3
  volatile uint32_t *v12; // r1
  int v13; // r0
  volatile uint32_t *v14; // r3
  volatile uint32_t *v15; // r1
  volatile uint32_t *v16; // r4
  volatile uint32_t *v17; // r5
  volatile char *v18; // r6
  int v19; // r9
  int i; // r4
  int v21; // r0
  volatile uint32_t *v22; // r4
  int v23; // r9
  int v24; // r10
  int k; // r5
  int v26; // r0
  int v27; // r5
  int v28; // r10
  int v29; // r0
  int v30; // r9
  uint64_t v31; // kr00_8
  int v32; // zf
  uint8_t v33; // r2
  int v34; // r3
  unsigned int v35; // r1
  int v36; // r3
  volatile int *v37; // r4
  volatile int *v38; // r2
  int v39; // r0
  int v40; // r1
  volatile int *v41; // r3
  int v42; // r4
  volatile int *v43; // r1
  volatile uint16_t *v44; // r5
  int v45; // r0
  int v46; // r2
  int v47; // r0
  volatile unsigned int *v48; // r2
  int v49; // r0
  int j; // r4
  uint8_t v52; // r2
  volatile int *v53; // r2
  int v54; // r3
  int v55; // r6
  unsigned int v56; // r3
  int v57; // r0
  volatile int *v58; // r5
  volatile uint8_t *v59; // r4
  volatile uint32_t *v60; // r3
  volatile uint32_t *v61; // r1
  volatile uint8_t *v62; // r3
  char v63; // r1
  char v64; // r2
  volatile uint32_t *v65; // r4
  int v66; // r11
  volatile uint32_t *v67; // r6
  volatile uint8_t *v68; // r4
  volatile uint8_t *v69; // r7
  int n; // r5
  char v71; // t1
  int v72; // r3
  volatile uint32_t *v73; // r5
  volatile uint32_t *v74; // r7
  int v75; // r11
  volatile char *v76; // r10
  int m; // r4
  char v78; // t1
  int v79; // r1
  struct __attribute__((packed)) { volatile char *v80; // [sp+4h] [bp-30h]
  char _pad1[4]; uint8_t v81[4]; // [sp+Ch] [bp-28h] BYREF
  uint32_t v82[3]; // [sp+10h] [bp-24h] BYREF
  uint8_t a2[24]; // [sp+1Ch] [bp-18h] BYREF
  } _frame;
  v0 = (void *)(uintptr_t)(off_103438);
  *((volatile uint32_t *)off_103434 + 64) = 8;
  if ( !v0[2] )
    *((volatile uint32_t *)off_10343C + 2) = *((volatile uint32_t *)off_10343C + 2) & 0xFFF9FFFF | 0x20000;
  v1 = (volatile int *)off_10343C;
  while ( (*((volatile uint32_t *)off_10343C + 12) & 0x22) != 2 )
    ;
  v2 = (void *)(uintptr_t)(off_103440);
  v3 = dword_103444;
  v4 = (void *)(uintptr_t)(off_103434);
  *((volatile uint32_t *)off_10343C + 2) = *((volatile uint32_t *)off_10343C + 2) & 0xFFFE73FE | 0x18401;
  *v2 = 6;
  v1[21] = v1[21] & 0x37F | 0x80 | v1[21] & v3;
  v4[81] = 16;
  v5 = (volatile uint8_t **)off_103448;
  *v1 = *v1 & 0x37F | 0x80 | *v1 & v3;
  if ( **v5 == 1 )
  {
    *v1 = *v1 & 0x3F7 | 8 | *v1 & v3;
    v1[21] = v3 & v1[21] | v1[21] & 0x3F7 | 8;
  }
  init_oscillators();
  v6 = (void *)(uintptr_t)(off_10343C);
  v7 = dword_103444;
  v8 = (void *)(uintptr_t)(off_103434);
  v9 = (volatile int *)off_103458;
  *(volatile uint32_t *)off_10343C = *(volatile uint32_t *)off_10343C & 0x3EF | 0x10 | *(volatile uint32_t *)off_10343C & dword_103444;
  v6[21] = v6[21] & 0x3EF | 0x10 | v6[21] & v7;
  v8[22] &= 0xFFFFFFC1;
  v10 = *((volatile uint8_t *)v9 + 177);
  v8[22] |= 0x26u;
  if ( v10 && (v6[12] & 0x40) == 0 && (v6[12] & 4) != 0 )
  {
    v53 = (volatile int *)off_103990;
    v54 = v9[42] | 0x2000000;
    *(volatile uint8_t *)off_10398C = 1;
    *v53 = v54;
    v8[14] |= 0x10u;
  }
  else
  {
    *(volatile uint32_t *)off_10344C = v9[42];
  }
  if ( v0[2] )
  {
    if ( **(volatile uint8_t **)off_103450 == 2 )
    {
      v60 = (void *)(uintptr_t)(off_1039A0);
      v61 = (void *)(uintptr_t)(off_1039A4);
      *((volatile uint32_t *)off_1039A0 + 20) |= 0x40000u;
      v61[7] &= ~0x100u;
      v60[9] = v60[9] & 0xFFFFFF00 | 0x60;
      v60[9] = v60[9] & 0xFFFF00FF | 0xDF00;
LABEL_13:
      irq_install();
      clock_enable();
      if ( !*(volatile uint32_t *)off_103454 )
        goto LABEL_17;
      goto LABEL_14;
    }
    v11 = (void *)(uintptr_t)(off_10343C);
    **(volatile uint8_t **)off_103450 = 2;
    v12 = (void *)(uintptr_t)(off_103434);
    v13 = (uint8_t)v0[2];
    v11[20] |= 0x40000u;
    v12[7] &= ~0x100u;
    v11[9] = v11[9] & 0xFFFFFF00 | 0x60;
    v11[9] = v11[9] & 0xFFFF00FF | 0xDF00;
    if ( v13 )
      goto LABEL_13;
  }
  else
  {
    v14 = (void *)(uintptr_t)(off_10376C);
    v15 = (void *)(uintptr_t)(off_103770);
    *((volatile uint32_t *)off_10376C + 20) |= 0x40000u;
    v15[7] &= ~0x100u;
    v14[9] = v14[9] & 0xFFFFFF00 | 0x60;
    v14[9] = v14[9] & 0xFFFF00FF | 0xDF00;
  }
  watchdog_init();
  clock_enable();
  if ( *(volatile uint32_t *)off_103774 )
  {
LABEL_14:
    periph_enable();
    system_init_mmio();
    radio_init_1();
  }
LABEL_17:
  v16 = (void *)(uintptr_t)(off_103770);
  radio_process_packet();
  v16[4] |= 2u;
  read_hw_status();
  if ( (*v16 & 0x2000000) != 0 )
  {
    v17 = (void *)(uintptr_t)(off_103778);
    v18 = (volatile char *)off_10377C;
    v19 = 1;
    for ( i = 0; i != 3; ++i )
    {
      v21 = load_calib_data(i, *v17 + 3 * i);
      if ( v21 != 546 )
      {
        v18[1] |= 1u;
        v19 = 0;
      }
    }
    if ( v19 )
    {
      for ( j = 0; j != 3; ++j )
      {
        _frame.a2[0] = 0;
        if ( syscall10_flash_erase(j, _frame.a2) <= 1 )
        {
          v52 = _frame.a2[0];
          *(volatile uint8_t *)(*v17 + j) = _frame.a2[0];
          *(volatile uint8_t *)(*v17 + j + 3) = v52;
          *(volatile uint8_t *)(*v17 + j + 6) = v52;
        }
      }
    }
    v22 = (void *)(uintptr_t)(off_103780);
    v23 = dword_1037D4;
    v24 = 1;
    for ( k = 0; k != 3; ++k )
    {
      v26 = load_calib_data2(k, *v22 + 6 * k);
      if ( v26 != v23 )
      {
        v18[1] |= 1u;
        v24 = 0;
      }
    }
    if ( v24 )
    {
      v27 = 0;
      v28 = dword_1037D8;
      _frame.a2[0] = 0;
      v29 = 2;
      v30 = 4;
      do
      {
        v31 = (unsigned int)v28 * (uint64_t)(unsigned int)(2 * v27);
        v32 = v30 == HIDWORD(v31) >> 1;
        v30 = HIDWORD(v31) >> 1;
        if ( !v32 )
          v29 = syscall11_flash_write(HIDWORD(v31) >> 1, _frame.a2);
        if ( v29 <= 1 )
        {
          v33 = _frame.a2[0];
          *(volatile uint8_t *)(*v22 + v27) = _frame.a2[0];
          v34 = *v22 + v27;
          *(volatile uint8_t *)(v34 + 6) = v33;
          *(volatile uint8_t *)(v34 + 12) = v33;
        }
        ++v27;
      }
      while ( v27 != 6 );
    }
    v35 = 31 - __clz(get_hw_info_1b());
    *v18 = v35;
  }
  else
  {
    memset((void *)(_frame.v82), 0, sizeof(_frame.v82));
    v55 = ioctl_cmd_2((int)_frame.v82);
    if ( v55 )
    {
      v18 = (volatile char *)off_103994;
    }
    else
    {
      v73 = (void *)(uintptr_t)(off_1039BC);
      printf_wrapper(aFlTxpwrOfst24g);
      v74 = _frame.v82;
      do
      {
        printf_wrapper("\r\n  [%d] =", v55);
        v75 = 3 * v55;
        v76 = (volatile char *)v74;
        for ( m = 0; m != 3; ++m )
        {
          v78 = *v76++;
          *(volatile uint8_t *)(*v73 + v75 + m) = v78;
          v79 = *(volatile char *)(*v73 + v75 + m);
          printf_wrapper(" %d", v79);
        }
        ++v55;
        v74 = (volatile uint32_t *)((volatile char *)v74 + 3);
      }
      while ( v55 != 3 );
      v18 = (volatile char *)off_103994;
      printf_wrapper((const volatile char *)off_1039B4);
      v18[1] |= 1u;
    }
    memset((volatile int *)(uintptr_t)_frame.a2, 0, 20);
    if ( !ioctl_cmd_4((int)_frame.a2) )
    {
      v65 = (void *)(uintptr_t)(off_1039A8);
      printf_wrapper(aFlTxpwrOfst5g);
      v66 = 0;
      _frame.v80 = v18;
      v67 = v65;
      v68 = _frame.a2;
      do
      {
        printf_wrapper("\r\n  [%d] =", v66);
        v69 = v68;
        for ( n = 0; n != 6; ++n )
        {
          v71 = *v69++;
          *(volatile uint8_t *)(*v67 + n + 6 * v66) = v71;
          v72 = *v67 + n;
          printf_wrapper(" %d", *(volatile char *)(v72 + 6 * v66));
        }
        ++v66;
        v68 += 6;
      }
      while ( v66 != 3 );
      v18 = _frame.v80;
      printf_wrapper((const volatile char *)off_1039B4);
      _frame.v80[1] |= 1u;
    }
    if ( ioctl_cmd_0x80((int)_frame.v81) )
    {
      v35 = -1;
      *v18 = -1;
    }
    else
    {
      v56 = _frame.v81[0];
      *v18 = _frame.v81[0];
      v35 = v56;
    }
  }
  printf_wrapper("cal_ver=%d\n", v35);
  if ( *((volatile uint8_t *)v9 + 372) )
  {
    if ( (*(volatile uint32_t *)off_103770 & 0x2000000) != 0 )
    {
      if ( get_hw_info_bit18() )
      {
        v57 = get_hw_info_field0();
        v58 = (volatile int *)off_103998;
        v59 = (void *)(uintptr_t)(off_10399C);
        *(volatile uint8_t *)off_10399C = *((volatile uint8_t *)off_103998 + v57);
        v59[1] = *((volatile uint8_t *)v58 + get_hw_info_field1());
        v59[2] = *((volatile uint8_t *)v58 + get_hw_info_field2());
      }
    }
    else
    {
      *(volatile uint32_t *)_frame.a2 = 0;
      if ( !ioctl_cmd_0x20((int)_frame.a2) )
      {
        v62 = (void *)(uintptr_t)(off_10399C);
        v63 = *((volatile uint8_t *)off_103998 + _frame.a2[1]);
        v64 = *((volatile uint8_t *)off_103998 + _frame.a2[2]);
        *(volatile uint8_t *)off_10399C = *((volatile uint8_t *)off_103998 + _frame.a2[0]);
        v62[1] = v63;
        v62[2] = v64;
      }
    }
  }
  v36 = off_10378C;
  v37 = (volatile int *)((volatile uint32_t *)(uintptr_t)&off_103790)[0];
  *(volatile uint32_t *)off_103788 &= 0xFFFFFFC7;
  sub_102d10(0, 0, 0x10u, v36);
  sub_102d10(0, 16, 0x10u, off_103794);
  sub_102d10(0, 32, 0x10u, v37[2]);
  sub_102d10(0, 48, 0x10u, v37[1]);
  sub_102d10(0, 64, 0x10u, *v37);
  sub_102d10(1, 0, 0x10u, *(volatile uint32_t *)off_103798);
  sub_102d10(1, 16, 0x10u, ((volatile uint32_t *)(uintptr_t)off_10379C)[0]);
  adc_read_ch1();
  hw_init(1);
  adc_read_ch0(0);
  hw_init(0);
  if ( (v9[98] & 4) != 0 )
  {
    v38 = (volatile int *)off_1037A0;
    v39 = dword_1037A4;
    v40 = dword_1037A8;
    ((volatile uint32_t *)(uintptr_t)off_1037A0)[13] = dword_1037A4;
    v38[14] = v40;
    --v39;
    v40 -= 10;
    v38[109] = v39;
    v38[110] = v40;
    v39 += 2;
    v40 -= 8;
    v41 = (volatile int *)off_1037AC;
    v38[204] = v39;
    v38[205] = v40;
    v39 += 33;
    v40 += 41;
    v42 = dword_1037B0;
    v38[206] = v39;
    v38[15] = v40;
    v39 -= 7;
    v38[111] = v40;
    v38[207] = v40;
    v38[303] = v40;
    v38[399] = v40;
    v38[495] = v40;
    v40 -= 16;
    v38[302] = v40;
    v38[398] = v40;
    v38[494] = v40;
    v38[300] = v42;
    v38[396] = v42;
    v38[492] = v42;
    v38[301] = v39;
    v38[397] = v39;
    v38[493] = v39;
    v43 = v41 + 1896;
    do
    {
      v41[318] |= 0x8000u;
      v41 += 316;
    }
    while ( v41 != v43 );
  }
  v44 = (void *)(uintptr_t)(off_1037B8);
  *(volatile uint32_t *)off_1037B4 |= 0x8000000u;
  v45 = ke_event_handler();
  v46 = ((int)(((uint64_t)((int32_t)dword_1037BC * (int64_t)(int32_t)(4 * (v45 - 35))) >> 32) + 4 * (v45 - 35)) >> 2)
      - ((4 * (v45 - 35)) >> 31)
      + 120;
  *(volatile uint16_t *)off_1037DC = v46;
  *v44 = v46;
  ke_event_schedule_1("Init T=%d C, ipa_target=%d\n", v45, v46);
  v47 = board_init((int)_frame.a2);
  printf_wrapper("cal_ipa_5g offset=%d, cgm=%d\n", v47, *(volatile uint32_t *)_frame.a2);
  if ( (v18[1] & 1) != 0 && *v18 < 0 )
  {
    v48 = (volatile unsigned int *)off_1037CC;
    *(volatile uint32_t *)off_1037C8 = *(volatile uint32_t *)off_1037C8 & 0xFFFFFF87 | 0x40;
    *v48 = *v48 & 0xFFF87FFF | 0x40000;
  }
  v49 = board_init_2();
  return printf_wrapper("cal_ipa_24g offset=%d\n", v49);
}


// rf_pll_enable @ 0x1039c4
/* luna: Enables the RF PLL stages, polls their ready status bits, and applies the RF-interface configuration. */
int rf_pll_enable() {
  volatile uint32_t *pll_status_reg; // r2
  int poll_delay_count; // r3
  volatile uint32_t *pll_control_reg; // r3
  volatile uint32_t *v3; // r2
  int v4; // r3
  volatile uint32_t *rf_control_reg; // r3
  volatile uint32_t *rf_interface_reg; // r0

  pll_status_reg = (void *)(uintptr_t)(off_103A54);
  *(volatile uint32_t *)off_103A50 |= 1u;
  while ( (*pll_status_reg & 0x10) == 0 )
  {
    poll_delay_count = (poll_delay_count & ~0xFFFFu) | ((uint16_t)(50) & 0xFFFFu);
    do
      poll_delay_count = (uint16_t)(poll_delay_count - 1);
    while ( poll_delay_count );
  }
  pll_control_reg = (void *)(uintptr_t)(off_103A58);
  v3 = (void *)(uintptr_t)(off_103A54);
  *(volatile uint32_t *)off_103A58 |= 0x80000u;
  *pll_control_reg |= 0x100000u;
  while ( (*v3 & 8) == 0 )
  {
    v4 = (v4 & ~0xFFFFu) | ((uint16_t)(50) & 0xFFFFu);
    do
      v4 = (uint16_t)(v4 - 1);
    while ( v4 );
  }
  rf_control_reg = (void *)(uintptr_t)(off_103A60);
  rf_interface_reg = (void *)(uintptr_t)(off_103A64);
  *(volatile uint32_t *)off_103A5C |= 0x20000u;
  *rf_control_reg |= 0x1000000u;
  *rf_control_reg |= 0x8000000u;
  *rf_interface_reg |= 0x524u;
  return state_check_feature(0x2000, aWfDfeAndRfintf);
}


// mac_irq_disable @ 0x103a6c
int mac_irq_disable() {
  volatile uint32_t *v0; // r0
  volatile uint32_t *v1; // r1
  volatile uint32_t *v2; // r2

  v0 = (void *)(uintptr_t)(off_103AB4);
  v1 = (void *)(uintptr_t)(off_103AB8);
  v2 = (void *)(uintptr_t)(off_103ABC);
  *(volatile uint32_t *)off_103AB0 &= 0xFFFFFA53;
  *v0 &= ~0x20000u;
  *v1 &= ~0x1000000u;
  *v2 &= 0xFFE7FFFF;
  timer_set(10);
  return state_check_feature(0x2000, aWfDfeAndRfintf_0);
}


// rf_lo_cal_clear @ 0x103ac4
int rf_lo_cal_clear() {
  volatile uint32_t *v0; // r4
  int result; // r0

  v0 = (void *)(uintptr_t)(off_103AF8);
  *(volatile uint32_t *)off_103AF8 &= ~0x400000u;
  *v0 &= ~0x200000u;
  timer_set(2);
  *v0 |= 0x200000u;
  result = timer_set(2);
  *v0 |= 0x400000u;
  return result;
}



// ke_sleep_set_mode @ 0x103afc
int ke_sleep_set_mode(int a1) {
  volatile unsigned int *v1; // r2
  volatile int *v2; // r4
  unsigned int v3; // r1
  int v4; // r5
  unsigned int v5; // r3
  const volatile char *v6; // r0
  volatile unsigned int *v7; // r4
  volatile int *v8; // r5
  int v9; // r6
  volatile unsigned int *v11; // r2
  volatile int *v12; // r4
  int v13; // r5
  int v14; // r1
  const volatile char *v15; // r0
  int v16; // r3
  volatile unsigned int *v17; // r4
  volatile int *v18; // r5
  int v19; // r6

  *(volatile uint32_t *)off_103CEC = dword_103CF0;
  if ( a1 )
  {
    switch ( a1 )
    {
      case 1:
        v11 = (volatile unsigned int *)off_103CF4;
        v12 = (volatile int *)off_103CF8;
        v13 = dword_103D20;
        v14 = *(volatile uint32_t *)off_103CF4;
        v15 = aDumpDac150m;
        v16 = *(volatile uint32_t *)off_103CF4 & 0x70 | 1;
        break;
      case 10:
        v1 = (volatile unsigned int *)off_103CF4;
        v2 = (volatile int *)off_103CF8;
        v3 = *(volatile uint32_t *)off_103CF4;
        v4 = dword_103D18;
        v5 = *(volatile uint32_t *)off_103CF4;
        v6 = aDumpDpdTxRx;
        goto LABEL_24;
      case 14:
        v1 = (volatile unsigned int *)off_103CF4;
        v2 = (volatile int *)off_103CF8;
        v3 = *(volatile uint32_t *)off_103CF4;
        v4 = dword_103D28;
        v5 = *(volatile uint32_t *)off_103CF4;
        v6 = aDumpLoftOut;
        goto LABEL_24;
      case 2:
        v11 = (volatile unsigned int *)off_103CF4;
        v12 = (volatile int *)off_103CF8;
        v13 = dword_103D30;
        v14 = *(volatile uint32_t *)off_103CF4;
        v15 = aDumpAdcIn;
        v16 = *(volatile uint32_t *)off_103CF4 & 0x70 | 2;
        break;
      default:
        switch ( a1 )
        {
          case 3:
            v1 = (volatile unsigned int *)off_103CF4;
            v2 = (volatile int *)off_103CF8;
            v3 = *(volatile uint32_t *)off_103CF4;
            v4 = dword_103D38;
            v5 = *(volatile uint32_t *)off_103CF4;
            v6 = aDumpRxDataIq;
            break;
          case 30:
            v1 = (volatile unsigned int *)off_103CF4;
            v2 = (volatile int *)off_103CF8;
            v3 = *(volatile uint32_t *)off_103CF4;
            v4 = dword_103D40;
            v5 = *(volatile uint32_t *)off_103CF4;
            v6 = aDumpRcAdcIq;
            break;
          case 31:
            v1 = (volatile unsigned int *)off_103CF4;
            v2 = (volatile int *)off_103CF8;
            v3 = *(volatile uint32_t *)off_103CF4;
            v4 = dword_103D50;
            v5 = *(volatile uint32_t *)off_103CF4;
            v6 = aDumpDccancelOu;
            break;
          case 32:
            v1 = (volatile unsigned int *)off_103CF4;
            v2 = (volatile int *)off_103CF8;
            v3 = *(volatile uint32_t *)off_103CF4;
            v4 = dword_103D58;
            v5 = *(volatile uint32_t *)off_103CF4;
            v6 = aDumpPreDgcOutI;
            break;
          case 33:
            v1 = (volatile unsigned int *)off_103CF4;
            v2 = (volatile int *)off_103CF8;
            v3 = *(volatile uint32_t *)off_103CF4;
            v4 = dword_103D60;
            v5 = *(volatile uint32_t *)off_103CF4;
            v6 = aDumpNotchOutIq;
            break;
          default:
            if ( a1 != 4 )
            {
              if ( a1 == 5 )
              {
                v1 = (volatile unsigned int *)off_103CF4;
                v2 = (volatile int *)off_103CF8;
                v3 = *(volatile uint32_t *)off_103CF4;
                v4 = dword_103D68;
                v5 = *(volatile uint32_t *)off_103CF4;
                v6 = aDumpRcOutIq;
                break;
              }
              if ( a1 != 50 )
              {
                switch ( a1 )
                {
                  case 6:
                    v1 = (volatile unsigned int *)off_103CF4;
                    v2 = (volatile int *)off_103CF8;
                    v3 = *(volatile uint32_t *)off_103CF4;
                    v4 = dword_103D70;
                    v5 = *(volatile uint32_t *)off_103CF4;
                    v6 = aDumpRcStatus;
                    break;
                  case 7:
                    v17 = (volatile unsigned int *)off_103D08;
                    v18 = (volatile int *)off_103CF8;
                    v19 = dword_103D0C;
                    *(volatile uint32_t *)off_103CF4 &= 0xFFFFFF70;
                    *v17 = *v17 & 0xFF00FFFF | 0x540000;
                    *v18 = v19;
                    ke_event_schedule_1(aDumpLpfOutBpfO);
                    goto LABEL_22;
                  case 8:
                    v1 = (volatile unsigned int *)off_103CF4;
                    v2 = (volatile int *)off_103CF8;
                    v4 = dword_103D0C;
                    v6 = aDumpGainLoft2I;
                    *(volatile uint32_t *)off_103D08 = *(volatile uint32_t *)off_103D08 & 0xFF00FFFF | 0x570000;
                    v3 = *v1;
                    v5 = *v1;
                    break;
                  case 81:
                    v1 = (volatile unsigned int *)off_103CF4;
                    v2 = (volatile int *)off_103CF8;
                    v4 = dword_103D0C;
                    v6 = aDumpGainLoftIn;
                    *(volatile uint32_t *)off_103D08 = *(volatile uint32_t *)off_103D08 & 0xFF00FFFF | 0x30000;
                    v3 = *v1;
                    v5 = *v1;
                    break;
                  default:
                    v1 = (volatile unsigned int *)off_103CF4;
                    v2 = (volatile int *)off_103CF8;
                    v3 = *(volatile uint32_t *)off_103CF4;
                    v4 = dword_103CFC;
                    v5 = *(volatile uint32_t *)off_103CF4;
                    if ( a1 == 9 )
                      v6 = aDumpAuxFifoOut;
                    else
                      v6 = aReselectMode;
                    break;
                }
                break;
              }
            }
            v1 = (volatile unsigned int *)off_103CF4;
            v2 = (volatile int *)off_103CF8;
            v3 = *(volatile uint32_t *)off_103CF4;
            v4 = dword_103D48;
            v5 = *(volatile uint32_t *)off_103CF4;
            v6 = aDumpRcInIq;
            break;
        }
LABEL_24:
        *v1 = v5 & 0xFFFFFF00 | v3 & 0x70;
        *v2 = v4;
        ke_event_schedule_1(v6);
        goto LABEL_22;
    }
    *v11 = v16 | v14 & 0xFFFFFF00;
    *v12 = v13;
    ke_event_schedule_1(v15);
    goto LABEL_22;
  }
  v7 = (volatile unsigned int *)off_103D08;
  v8 = (volatile int *)off_103CF8;
  v9 = dword_103D0C;
  *(volatile uint32_t *)off_103CF4 &= 0xFFFFFF70;
  *v7 = *v7 & 0xFF00FFFF | 0x770000;
  *v8 = v9;
  ke_event_schedule_1(aDumpLoftPwrInO);
LABEL_22:
  *(volatile uint32_t *)off_103D14 = 769;
  return timer_set(500);
}


// mac_set_rx_timeout @ 0x103d84
int mac_set_rx_timeout() {
  volatile int *v0; // r4
  volatile int *v1; // r3
  int v2; // r1
  volatile uint32_t *v3; // r2

  v0 = (volatile int *)off_103DE0;
  *(volatile uint32_t *)off_103DDC = 777;
  while ( *v0 < 0 )
    timer_set(1);
  ke_event_schedule_1("end_addr=%d\n", *(volatile uint32_t *)off_103DE0);
  *(volatile uint32_t *)off_103DDC = 0;
  ke_event_schedule_1(aFinish);
  v1 = (volatile int *)off_103DF0;
  v2 = dword_103DF4;
  v3 = (void *)(uintptr_t)(off_103DF8);
  *(volatile uint32_t *)off_103DEC = 0;
  *v1 = v2;
  *v3 &= 0xFF00FFFF;
  return ke_event_schedule_1("*0* dump    r 00100000 %d**\n", 0x4000);
}


// mac_tx_enable @ 0x103e00
volatile int * mac_tx_enable(int a1) {
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

  v1 = (volatile unsigned int *)off_103E7C;
  *(volatile uint32_t *)off_103E78 |= 0x100u;
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
    v9 = dword_103E80 + v3;
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
  *(volatile uint32_t *)off_103E78 &= ~0x100u;
  return result;
}



// mac_tx_wait_ack @ 0x103e84
int mac_tx_wait_ack(int a1, int a2, int a3) {
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
    v17 = dword_103F4C;
    v16[13] = dword_103F48;
    v16[14] = v17;
    v18 = dword_103F50;
    v19 = dword_103F54;
    v16[12] = dword_103F58;
    v16[18] = 0;
    v16[19] = 0;
    v16[20] = 0;
    v16[21] = 0;
    v16[22] = 0;
    v16[23] = 0;
    v16[15] = dword_103F5C;
    v16[16] = v18;
    v16[17] = v19;
  }
  v4 = 4 * v3;
  v5 = (volatile unsigned int *)off_103F44;
  v6 = dword_103F60;
  *(volatile uint32_t *)off_103F40 |= 0x100u;
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
  *(volatile uint32_t *)off_103F40 &= ~0x100u;
  return result;
}



// mmio_irq_enable @ 0x103f64
unsigned int mmio_irq_enable(int a1, int a2) {
  volatile unsigned int *v2; // r2
  volatile unsigned int *v3; // r3
  int v4; // r4
  volatile uint32_t *v5; // r6
  unsigned int result; // r0

  v2 = (volatile unsigned int *)off_103FE4;
  v3 = (volatile unsigned int *)off_103FE8;
  v4 = *(volatile uint32_t *)off_103FE4;
  v5 = (void *)(uintptr_t)(off_103FEC);
  *(volatile uint32_t *)off_103FE4 |= 0x1000000u;
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



// mac_irq_handler @ 0x103ff0
volatile uint32_t *mac_irq_handler() {
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

  v0 = (volatile unsigned int *)off_1040C8;
  v1 = (volatile unsigned int *)off_1040CC;
  v2 = (void *)(uintptr_t)(off_1040D0);
  v3 = (void *)(uintptr_t)(off_1040D4);
  v4 = (void *)(uintptr_t)(off_1040D8);
  v5 = (volatile unsigned int *)off_1040DC;
  *(volatile uint32_t *)off_1040C8 &= ~0x200u;
  *v1 = *v1 & 0xFC000FFF | 0x333000;
  *v2 = 8;
  *v3 |= 0x1000000u;
  v0 -= 136;
  *v4 |= 0x2000000u;
  *v0 &= ~0x20000u;
  timer_set(2);
  v6 = (void *)(uintptr_t)(off_1040E0);
  result = (void *)(uintptr_t)(off_1040E4);
  v8 = (void *)(uintptr_t)(off_1040E8);
  *v0 |= 0x10000u;
  *v0 |= 0x20000u;
  *v0 = *v0 & 0xFFFF0FFF | 0x6000;
  *v0 |= 0x80000u;
  v9 = dword_1040EC;
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



// mac_irq_pending_clear @ 0x1040f0
volatile unsigned int *mac_irq_pending_clear() {
  volatile unsigned int *v0; // r1
  volatile uint32_t *v1; // r0
  volatile unsigned int *v2; // r2
  volatile uint32_t *v3; // r6
  volatile uint32_t *v4; // r5
  volatile uint32_t *v5; // r4
  volatile unsigned int *result; // r0

  v0 = (volatile unsigned int *)off_1041CC;
  v1 = (void *)(uintptr_t)(off_1041D0);
  v2 = (volatile unsigned int *)off_1041D4;
  *(volatile uint32_t *)off_1041CC &= ~0x10000000u;
  v3 = (void *)(uintptr_t)(off_1041D8);
  v4 = (void *)(uintptr_t)(off_1041DC);
  v5 = (void *)(uintptr_t)(off_1041E0);
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



// util_get_hw_index @ 0x1041e4
int util_get_hw_index(int a1, int a2, volatile uint32_t *a3) {
  int v3; // r3
  int v4; // r4
  int result; // r0

  v3 = (uint16_t)*(volatile uint32_t *)off_104228;
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



// util_get_buf_addr @ 0x10422c
int util_get_buf_addr() {
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
  int16_t v14; // r2
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
    state_check_feature(1, aWarningDataSat);
  state_check_feature(1, "sum_i=%d\nsum_q=%d\ndc_i=%d\ndc_q=%d\n", v9, v8, v9 / 0x2000, v8 / 0x2000);
  do
  {
    v12 = *v2;
    v13 = (unsigned int)*v2 >> 20;
    if ( *v2 < 0 )
      v13 = (v13 & ~0xFFFFu) | ((uint16_t)(v13 - 4096) & 0xFFFFu);
    v14 = (uint16_t)v12 >> 4;
    result = v12 >> 4 << 20;
    v16 = (int16_t)(v13 - v9 / 0x2000);
    if ( result < 0 )
      v14 -= 4096;
    *v2 = ((v16 + (v16 < 0 ? 0x1000 : 0)) << 20)
        + 65537
        + 16 * ((int16_t)(v14 - v8 / 0x2000) + ((int16_t)(v14 - v8 / 0x2000) < 0 ? 0x1000 : 0));
    v2 += 2;
  }
  while ( (volatile int *)(4 * v3) != v2 );
  return result;
}


// rf_power_on_reset @ 0x104338
int rf_power_on_reset() {
  volatile int *v0; // r1
  volatile uint32_t *v1; // r3
  int v2; // r0
  int v3; // r5
  volatile uint32_t *v4; // r6
  volatile int *v5; // r4
  int result; // r0
  volatile uint32_t *v7; // r3
  volatile uint32_t *v8; // r1

  v0 = (volatile int *)off_10440C;
  v1 = (void *)(uintptr_t)(off_104414);
  v2 = dword_104418;
  v3 = *(volatile uint32_t *)off_104410;
  *(volatile uint32_t *)off_104410 = dword_10441C;
  *v0 = v2;
  v4 = (void *)(uintptr_t)(off_104420);
  v5 = (volatile int *)off_104424;
  *v1 = *v1 & 0xFC000FFF | 0x333000;
  *v1 &= 0x3FFFFFFFu;
  *v1 |= 0xC000000u;
  *v1 = ~(~(*v1 >> 12) << 12);
  v0[29] = v0[29] & 0xFFFFFF0F | 0xA0;
  *v1 |= 0x10000000u;
  timer_set(10);
  *v4 = dword_104428;
  timer_set(125);
  *v4 = dword_10442C;
  while ( *v5 < 0 )
    timer_set(1);
  state_check_feature(1, "end_addr=%x\n", *(volatile uint32_t *)off_104424);
  *(volatile uint32_t *)off_104420 = 0;
  state_check_feature(1, aDumpFinish);
  *(volatile uint32_t *)off_104410 = v3;
  util_get_buf_addr();
  result = state_check_feature(1, "** dump tone typ3   r 00100000 %d**\n", 0x4000);
  v7 = (void *)(uintptr_t)(off_104414);
  v8 = (void *)(uintptr_t)(off_10443C);
  *(volatile uint32_t *)off_104414 &= 0xF3FFFFFF;
  *v8 |= 0xF0u;
  *v7 &= ~0x10000000u;
  *v7 &= 0x3FFFFFFFu;
  return result;
}


// rx_parse_desc @ 0x104440
int rx_parse_desc(int a1, int a2, volatile uint32_t *a3) {
  int v3; // r2
  unsigned int v4; // r0
  int v5; // r3

  v3 = a3[util_get_hw_index(a1, a2, a3)];
  v4 = (unsigned int)v3 >> 20;
  v5 = (uint16_t)v3 >> 4;
  if ( v3 < 0 )
    v4 -= 4096;
  if ( (((unsigned int)v3 >> 4) & 0x800) != 0 )
    v5 -= 4096;
  return v5 * v5 + v4 * v4;
}



