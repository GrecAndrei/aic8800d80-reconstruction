// copy_cal_data @ 0x102b10
/* luna: Logs an interrupt-controller spurious event and, if the global signed flag is negative, invokes the associated MMIO interrupt-disable operation. */
int copy_cal_data() {
  int result; // r0

  result = alloc_tx_event("%s\r\n", aIntcSpurious);
  if ( **(volatile int16_t **)off_102B40 < 0 )
    return irq_disable_mmio_write(off_102B48, (int)aIntcSpurious_0, 61);
  return result;
}


// patch_interrupt_vector @ 0x102b4c
int patch_interrupt_vector() {
  volatile uint32_t *v0; // r2
  volatile uint8_t *v1; // r3
  int v2; // r1
  void *v3; // r0
  void *v4; // r4
  int v5; // r0
  int v6; // r1
  volatile uint8_t *v7; // r2
  int v8; // r2
  volatile uint32_t *v9; // r2
  volatile uint32_t *v10; // r3

  v0 = (void *)(uintptr_t)(off_102BD0);
  v1 = (void *)(uintptr_t)(off_102BD4);
  *(volatile uint32_t *)(*((volatile uint32_t *)off_102BD0 + 2) + 80) = dword_102BD8;
  *(volatile uint32_t *)v1 = 16;
  v2 = dword_102BDC;
  *(volatile uint32_t *)(v0[2] + 84) = dword_102BDC;
  *(volatile uint32_t *)v1 = 32;
  v3 = (void *)(uintptr_t)(off_102BE0);
  *(volatile uint32_t *)(v0[2] + 92) = v2;
  *(volatile uint32_t *)v1 = 128;
  v4 = (void *)(uintptr_t)(off_102BE4);
  *(volatile uint32_t *)(v0[2] + 72) = (int)(uintptr_t)(v3);
  *(volatile uint32_t *)v1 = 4;
  v5 = dword_102BE8;
  *(volatile uint32_t *)(v0[2] + 88) = (int)(uintptr_t)(v4);
  *(volatile uint32_t *)v1 = 64;
  v6 = v0[2];
  v7 = (volatile uint8_t *)off_102BEC;
  *(volatile uint32_t *)(v6 + 76) = v5;
  v8 = v7[413];
  v1[771] = -8;
  *(volatile uint32_t *)v1 = 8;
  if ( v8 )
    *(volatile uint32_t *)v1 = 512;
  v9 = (void *)(uintptr_t)(off_102BD0);
  v10 = (void *)(uintptr_t)(off_102BD4);
  *(volatile uint32_t *)(*((volatile uint32_t *)off_102BD0 + 2) + 208) = off_102BF0;
  v10[1] = 16;
  *(volatile uint32_t *)(v9[2] + 212) = off_102BF4;
  v10[1] = 32;
  *v10 = 0x800000;
  v10[1] = 64;
  __enable_irq();
  return 32;
}



// rf_clear_control_bit_a @ 0x102bf8
volatile int * rf_clear_control_bit_a(int a1) {
  int v1; // r4
  int v2; // r1
  int v3; // zf
  int v4; // r2
  int v5; // r2
  int v6; // r3
  volatile int *result; // r0
  int v8; // r2
  int v9; // r3

  v2 = (int)off_102C58;
  v3 = a1 == 0;
  if ( a1 )
    v4 = -2;
  else
    v4 = -17;
  v5 = v4 & *(volatile uint32_t *)off_102C58;
  if ( !a1 )
    a1 = -33;
  *(volatile uint32_t *)off_102C58 = v5;
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
  result = (volatile int *)off_102C58;
  v8 = v9 | v2;
  *(volatile uint32_t *)off_102C58 = v9;
  v9 = (v9 & ~0xFFu) | ((uint8_t)(50) & 0xFFu);
  *result = v8;
  do
    v9 = (uint8_t)(v9 - 1);
  while ( v9 );
  *(volatile uint32_t *)off_102C58 = v8 | v1;
  return result;
}



// rf_clear_control_bit_b @ 0x102c5c
int rf_clear_control_bit_b(int result) {
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
  v4 = *(volatile uint32_t *)off_102CC8 & v3;
  if ( !result )
    result = 32;
  *(volatile uint32_t *)off_102CC8 = v4;
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
  *(volatile uint32_t *)off_102CC8 = v6;
  v7 = (v7 & ~0xFFu) | ((uint8_t)(50) & 0xFFu);
  do
    v7 = (uint8_t)(v7 - 1);
  while ( v7 );
  v8 = v6 | result;
  *(volatile uint32_t *)off_102CC8 = v8;
  v9 = (v9 & ~0xFFu) | ((uint8_t)(50) & 0xFFu);
  do
    v9 = (uint8_t)(v9 - 1);
  while ( v9 );
  *(volatile uint32_t *)off_102CC8 = v8 | v3;
  return result;
}



// uart_driver_send @ 0x102ccc
int uart_driver_send(int a1, volatile uint16_t *a2) {
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
  volatile int *v26; // [sp+1Ch] [bp-10h]
  } _frame;
  while ( !*(volatile uint32_t *)off_102DE8 )
    ;
  v4 = 0;
  rf_clear_control_bit_a(0);
  v5 = dword_102DF8;
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
  v7 = (volatile unsigned int *)(dword_102DEC + (v4 << 9));
  v8 = 0;
  v9 = _frame.v24 - 1;
  do
  {
    v10 = *v7;
    check_feature_flag(0x2000, "before %d,%d: dcq/i=%4x\r\n", v4, v8, (uint16_t)(*v7 >> 11));
    v11 = v9[1];
    ++v9;
    v12 = v10 & v5 | (v11 << 11);
    *v7 = v12;
    v7 += 8;
    v13 = v8++;
    check_feature_flag(0x2000, "after  %d,%d: dcq/i=%4x\r\n", v4, v13, (uint16_t)(v12 >> 11));
  }
  while ( v8 != 16 );
  if ( v4 <= 1 )
    goto LABEL_4;
  _frame.v23 = 1;
  if ( (uint16_t)v4 != 5 )
    goto LABEL_4;
LABEL_10:
  result = rf_clear_control_bit_b(0);
  *(volatile uint32_t *)off_102DE8 = 1;
  if ( _frame.v23 )
  {
    v15 = *(volatile uint32_t *)aT;
    _frame.v25 = *(volatile uint64_t *)aT;
    _frame.v26 = (volatile int *)off_151B28;
    v16 = 3;
  }
  else
  {
    v15 = qword_102DFC;
    _frame.v26 = nullptr;
    _frame.v25 = qword_102DFC;
    v16 = 2;
  }
  v17 = (volatile char *)&_frame.v25 + 4;
  v18 = dword_102DF8;
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


// uart_send_data @ 0x102e08
int uart_send_data(int a1, int a2, unsigned int a3, int a4) {
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
    v6 = 16 * (dword_102E98 + a2);
    v7 = 4;
    v8 = 3;
  }
  else
  {
    v6 = 32 * (dword_102E90 + a2);
    v7 = 8;
    v8 = 5;
  }
  while ( !*(volatile uint32_t *)off_102E94 )
    ;
  rf_clear_control_bit_a(a1);
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
  result = rf_clear_control_bit_b(a1);
  *(volatile uint32_t *)off_102E94 = 1;
  return result;
}



// hci_send_command @ 0x102e9c
int hci_send_command() {
  uint64_t v0; // kr00_8
  int v1; // r4

  v0 = *(volatile uint64_t *)((volatile char *)off_102ECC + 4);
  v1 = *(volatile uint32_t *)off_102ECC;
  uart_send_data(0, 32, 0x10u, SHIDWORD(v0));
  uart_send_data(0, 48, 0x10u, v0);
  return uart_send_data(0, 64, 0x10u, v1);
}



// radio_is_idle @ 0x102ed0
int radio_is_idle() {
  volatile uint8_t *v0; // r3
  volatile uint32_t *v1; // r2
  volatile uint32_t *v2; // r1
  volatile unsigned int *v3; // r2
  volatile unsigned int *v4; // r0
  volatile uint32_t *v5; // r5
  volatile unsigned int *v6; // r4
  volatile uint32_t *v7; // r6
  volatile uint32_t *v8; // r3
  volatile uint32_t *v9; // r0
  volatile uint32_t *v10; // r2
  volatile uint8_t *v11; // r4
  volatile uint32_t *v12; // r3
  volatile uint32_t *v13; // r4
  volatile unsigned int *v14; // r2
  volatile uint8_t *v15; // r0
  volatile uint32_t *v16; // r1
  int result; // r0
  volatile unsigned int *v18; // r2
  volatile uint32_t *v19; // r3
  volatile uint32_t *v20; // r3
  volatile uint32_t *v21; // r2
  volatile unsigned int *v22; // r0
  volatile uint32_t *v23; // r2

  if ( *((volatile uint8_t *)off_103110 + 2) )
  {
    *(volatile uint32_t *)off_103168 = *(volatile uint32_t *)off_103168 & 0xFFFFF3FF | 0x800;
  }
  else
  {
    v0 = (void *)(uintptr_t)(off_103114);
    v1 = (void *)(uintptr_t)(off_103118);
    *(volatile uint8_t *)off_103114 = 80;
    v0[1] = 78;
    while ( !*v1 )
      ;
    v2 = (void *)(uintptr_t)(off_103120);
    *(volatile uint32_t *)off_10311C &= ~2u;
    if ( (*v2 & 1) == 0 )
    {
      rf_config_read_a(1);
      v23 = (void *)(uintptr_t)(off_103128);
      *(volatile uint32_t *)off_10317C = *(volatile uint32_t *)off_10317C & 0xFFFFFFF0 | 4;
      *v23 |= 2u;
    }
    v3 = (volatile unsigned int *)off_103124;
    v4 = (volatile unsigned int *)off_103128;
    v5 = (void *)(uintptr_t)(off_10312C);
    v6 = (volatile unsigned int *)off_103130;
    v7 = (void *)(uintptr_t)(off_103134);
    *(volatile uint32_t *)off_103118 = 1;
    *v3 = *v3 & 0xC3FFFFFF | 0x30000000;
    *v4 = *v4 & 0xFE3FFFFF | 0x400000;
    *v5 |= 0x78000u;
    *v4 &= ~2u;
    v8 = (void *)(uintptr_t)(off_103138);
    *v3 = *v3 & 0xFF0FFFFF | 0xC00000;
    *v3 = *v3 & 0xFFFFFF0F | 0x60;
    v9 = (void *)(uintptr_t)(off_10313C);
    v5 -= 463846;
    *v6 &= ~1u;
    *v5 = *v5 & 0xFFFFE0FF | 0x1000;
    *v8 |= 8u;
    *v8 &= 0xFFFFFFFC;
    *v7 &= ~0x40000u;
    *v8 &= ~4u;
    v10 = (void *)(uintptr_t)(off_103140);
    *v6 = *v6 & 0xFFFFF3FF | 0x800;
    v11 = (volatile uint8_t *)off_103144;
    v5 -= 1999;
    *v9 &= 0xFFFF3FFF;
    *v5 = *v5 & 0xFFFFFF | 0x10000000;
    v9 -= 2043;
    *v10 = *v10 & 0xFFFC00FF | (*v11 << 8);
    v12 = (void *)(uintptr_t)(off_103148);
    v5 -= 73;
    *v9 |= 0x80000000;
    *v5 |= 0x1000u;
    *v10 &= ~0x40000u;
    *v9 &= ~0x40000000u;
    v13 = (void *)(uintptr_t)(off_10314C);
    *v12 &= ~2u;
    *v12 |= 1u;
    v10 += 2062;
    v5[2083] = 20058;
    *v10 = *v10 & 0x3FFFFFF | 0x7C000000;
    *v10 = *v10 & 0xFC07FFFF | 0x3D00000;
    if ( (*v13 & 0x20) != 0 )
    {
      v20 = (void *)(uintptr_t)(off_103170);
      *((volatile uint8_t *)off_103150 + 1) = 1;
      v21 = (void *)(uintptr_t)(off_103174);
      v22 = (volatile unsigned int *)off_103178;
      *v20 &= 0xFFF0FFFF;
      *v20 &= 0xFF0FFFFF;
      *v21 &= ~0x8000u;
      *v22 = *v22 & 0xFFFFFC7F | 0x200;
    }
    else
    {
      *((volatile uint8_t *)off_103150 + 1) = 0;
    }
    v14 = (volatile unsigned int *)off_103154;
    v15 = (volatile uint8_t *)off_103158;
    v16 = (void *)(uintptr_t)(off_10315C);
    *(volatile uint32_t *)off_103154 = *(volatile uint32_t *)off_103154 & 0x3FFFFFF | 0xA0000000;
    result = v15[362];
    *v14 = *v14 & 0xFC0FFFFF | 0x1800000;
    *v16 |= 0x10u;
    if ( result )
      *(v14 - 8824) = *(v14 - 8824) & 0xFFFFFFC0 | 0x2C;
    v18 = (volatile unsigned int *)off_103164;
    *(volatile uint32_t *)off_103160 &= 0xFFFFFFC7;
    *v18 = *v18 & 0xFFFFFFFC | 2;
  }
  v19 = (void *)(uintptr_t)(off_10316C);
  *(volatile uint32_t *)off_10316C |= 0xC000u;
  *v19 |= 0x30000u;
  return result;
}



// read_radio_status_flag @ 0x103180
unsigned int read_radio_status_flag(unsigned int result) {
  if ( result )
  {
    if ( *((volatile uint8_t *)off_1031D0 + 362) )
      result = rf_reg_write_byte(0xB5u);
    *(volatile uint32_t *)off_1031D4 |= 2u;
  }
  else
  {
    if ( *((volatile uint8_t *)off_1031D0 + 362) )
      result = rf_reg_write_byte(0xC2u);
    *(volatile uint32_t *)off_1031D4 &= ~2u;
  }
  return result;
}



// aes_load_key @ 0x1031d8
volatile uint32_t *aes_load_key() {
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
  v0 = *(volatile uint32_t *)(dword_103248 + 4);
  v1 = *(volatile uint32_t *)(dword_103248 + 8);
  v2 = *(volatile uint32_t *)(dword_103248 + 12);
  _frame.v11 = *(volatile uint32_t *)dword_103248;
  _frame.v12 = v0;
  _frame.v13 = v1;
  _frame.v14 = v2;
  if ( (*((volatile uint32_t *)off_10324C + 4) & 2) != 0 )
  {
    v3 = dword_103254;
    v4 = &_frame.v15[*((volatile uint32_t *)off_10324C + 9) & 0xF];
    v5 = (char)*(v4 - 16);
    v6 = (uint8_t)*(v4 - 16);
    if ( (*((volatile uint32_t *)off_10324C + 4) & 4) == 0 )
      v3 = dword_103250;
    if ( v5 < 0 )
    {
      v3 *= 2;
      v6 &= 0x7Fu;
    }
    v7 = v3 / v6;
  }
  else
  {
    v7 = 2 * *(volatile uint32_t *)off_103264;
  }
  result = (void *)(uintptr_t)(off_10325C);
  v9 = (volatile unsigned int *)off_103260;
  v10 = v7 / (uint8_t)*((volatile uint32_t *)off_10324C + 8);
  *(volatile uint32_t *)off_103258 = v10;
  *v9 = v10 / (uint8_t)result[9];
  return result;
}



// crypto_read_status @ 0x103268
unsigned int crypto_read_status(unsigned int result) {
  volatile unsigned int v1; // r1
  unsigned int v2; // r3

  v1 = (*(volatile uint32_t *)0x40501010u);
  do
    v2 = (*(volatile uint32_t *)0x40501010u) - v1;
  while ( v2 < result );
  return result;
}


// rf_calibrate_mdll_duty @ 0x10327c
void rf_calibrate_mdll_duty(int a1) {
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
  unsigned int v20; // [sp+0h] [bp-Ch]

  v1 = (volatile uint32_t *)dword_1033E0;
  v2 = (volatile uint32_t *)dword_1033E4;
  *(volatile uint32_t *)dword_1033E0 |= 0x10u;
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
      v20 = v8;
      v17 = v8;
      v5 += v8;
      check_feature_flag(0x2000, "%x -> %x\n", v6, v8);
      if ( v20 <= 0x40 )
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
  *(volatile uint32_t *)dword_1033E0 = ((v5 + 2) << 8) & 0x1FC00 | *(volatile uint32_t *)dword_1033E0 & 0xFFFE03FF;
  v19 = ((unsigned int)v5 + 2) >> 2;
  debug_printf("%dM mdll duty: %x\n", 40 * a1 + 280, v19);
  if ( a1 )
    *(volatile uint8_t *)(dword_1033F4 + 1) = v19;
  else
    *(volatile uint8_t *)dword_1033F4 = v19;
}


// crypto_init @ 0x1033f8
/* luna: Configures RF control registers, enables the RF chain, and performs RF hardware startup. */
int crypto_init() {
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
  volatile char *v17; // r6
  int v18; // r9
  int i; // r4
  int v20; // r0
  int v21; // r9
  int v22; // r10
  int k; // r5
  int v24; // r0
  int v25; // r5
  int v26; // r10
  int v27; // r0
  int v28; // r9
  uint64_t v29; // kr00_8
  int v30; // zf
  uint8_t v31; // r2
  int v32; // r3
  unsigned int v33; // r1
  int v34; // r3
  volatile uint16_t *v35; // r5
  int v36; // r0
  int v37; // r2
  int v38; // r0
  volatile unsigned int *v39; // r2
  int v40; // r0
  int j; // r4
  uint8_t v43; // r2
  volatile int *v44; // r2
  int v45; // r3
  int v46; // r6
  unsigned int v47; // r3
  int v48; // r0
  volatile int *v49; // r5
  volatile uint8_t *v50; // r4
  volatile uint32_t *v51; // r3
  volatile uint32_t *v52; // r1
  volatile uint8_t *v53; // r3
  char v54; // r1
  char v55; // r2
  int v56; // r11
  volatile uint8_t *v57; // r4
  volatile uint8_t *v58; // r7
  int n; // r5
  char v60; // t1
  int v61; // r3
  volatile uint32_t *v62; // r7
  int v63; // r11
  volatile char *v64; // r10
  int m; // r4
  char v66; // t1
  int v67; // r1
  struct __attribute__((packed)) { uint8_t v68[4]; // [sp+Ch] [bp-28h] BYREF
  uint32_t v69[3]; // [sp+10h] [bp-24h] BYREF
  uint8_t a2[24]; // [sp+1Ch] [bp-18h] BYREF
  } _frame;
  v0 = (void *)(uintptr_t)(off_103560);
  *((volatile uint32_t *)off_10355C + 64) = 8;
  if ( !v0[2] )
    *((volatile uint32_t *)off_103564 + 2) = *((volatile uint32_t *)off_103564 + 2) & 0xFFF9FFFF | 0x20000;
  v1 = (volatile int *)off_103564;
  while ( (*((volatile uint32_t *)off_103564 + 12) & 0x22) != 2 )
    ;
  v2 = (void *)(uintptr_t)(off_103568);
  v3 = dword_10356C;
  v4 = (void *)(uintptr_t)(off_10355C);
  *((volatile uint32_t *)off_103564 + 2) = *((volatile uint32_t *)off_103564 + 2) & 0xFFFE73FE | 0x18401;
  *v2 = 6;
  v1[21] = v1[21] & 0x37F | 0x80 | v1[21] & v3;
  v4[81] = 16;
  v5 = (volatile uint8_t **)off_103570;
  *v1 = *v1 & 0x37F | 0x80 | *v1 & v3;
  if ( **v5 == 1 )
  {
    *v1 = *v1 & 0x3F7 | 8 | *v1 & v3;
    v1[21] = v3 & v1[21] | v1[21] & 0x3F7 | 8;
  }
  rf_chain_enable();
  v6 = (void *)(uintptr_t)(off_103564);
  v7 = dword_10356C;
  v8 = (void *)(uintptr_t)(off_10355C);
  v9 = (volatile int *)off_103580;
  *(volatile uint32_t *)off_103564 = *(volatile uint32_t *)off_103564 & 0x3EF | 0x10 | *(volatile uint32_t *)off_103564 & dword_10356C;
  v6[21] = v6[21] & 0x3EF | 0x10 | v6[21] & v7;
  v8[22] &= 0xFFFFFFC1;
  v10 = *((volatile uint8_t *)v9 + 177);
  v8[22] |= 0x26u;
  if ( v10 && (v6[12] & 0x40) == 0 && (v6[12] & 4) != 0 )
  {
    v44 = (volatile int *)off_1038F0;
    v45 = v9[42] | 0x2000000;
    *(volatile uint8_t *)off_1038EC = 1;
    *v44 = v45;
    v8[14] |= 0x10u;
  }
  else
  {
    *(volatile uint32_t *)off_103574 = v9[42];
  }
  if ( v0[2] )
  {
    if ( **(volatile uint8_t **)off_103578 == 2 )
    {
      v51 = (void *)(uintptr_t)(off_103A24);
      v52 = (void *)(uintptr_t)(off_103A28);
      *((volatile uint32_t *)off_103A24 + 20) |= 0x40000u;
      v52[7] &= ~0x100u;
      v51[9] = v51[9] & 0xFFFFFF00 | 0x60;
      v51[9] = v51[9] & 0xFFFF00FF | 0xDF00;
LABEL_13:
      enable_irq();
      enable_clock_1();
      if ( !*(volatile uint32_t *)off_10357C )
        goto LABEL_17;
      goto LABEL_14;
    }
    v11 = (void *)(uintptr_t)(off_103564);
    **(volatile uint8_t **)off_103578 = 2;
    v12 = (void *)(uintptr_t)(off_10355C);
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
    v14 = (void *)(uintptr_t)(off_103898);
    v15 = (void *)(uintptr_t)(off_10389C);
    *((volatile uint32_t *)off_103898 + 20) |= 0x40000u;
    v15[7] &= ~0x100u;
    v14[9] = v14[9] & 0xFFFFFF00 | 0x60;
    v14[9] = v14[9] & 0xFFFF00FF | 0xDF00;
  }
  configure_radio();
  enable_clock_1();
  if ( *(volatile uint32_t *)off_1038A0 )
  {
LABEL_14:
    rf_enable_rx();
    rf_hw_init_alt();
    rf_hw_init();
  }
LABEL_17:
  v16 = (void *)(uintptr_t)(off_10389C);
  radio_is_idle();
  v16[4] |= 2u;
  aes_load_key();
  if ( (*v16 & 0x2000000) != 0 )
  {
    v17 = (volatile char *)off_1038A8;
    v18 = 1;
    for ( i = 0; i != 3; ++i )
    {
      v20 = packet_prepare_a(i, *(volatile uint32_t *)asc_151888 + 3 * i);
      if ( v20 != 546 )
      {
        v17[1] |= 1u;
        v18 = 0;
      }
    }
    if ( v18 )
    {
      for ( j = 0; j != 3; ++j )
      {
        _frame.a2[0] = 0;
        if ( rf_cmd_a(j, _frame.a2) <= 1 )
        {
          v43 = _frame.a2[0];
          *(volatile uint8_t *)(*(volatile uint32_t *)asc_151888 + j) = _frame.a2[0];
          *(volatile uint8_t *)(*(volatile uint32_t *)asc_151888 + j + 3) = v43;
          *(volatile uint8_t *)(*(volatile uint32_t *)asc_151888 + j + 6) = v43;
        }
      }
    }
    v21 = dword_1038FC;
    v22 = 1;
    for ( k = 0; k != 3; ++k )
    {
      v24 = packet_prepare_b(k, *(volatile uint32_t *)a2_0 + 6 * k);
      if ( v24 != v21 )
      {
        v17[1] |= 1u;
        v22 = 0;
      }
    }
    if ( v22 )
    {
      v25 = 0;
      v26 = dword_103900;
      _frame.a2[0] = 0;
      v27 = 2;
      v28 = 4;
      do
      {
        v29 = (unsigned int)v26 * (uint64_t)(unsigned int)(2 * v25);
        v30 = v28 == HIDWORD(v29) >> 1;
        v28 = HIDWORD(v29) >> 1;
        if ( !v30 )
          v27 = rf_cmd_b(HIDWORD(v29) >> 1, _frame.a2);
        if ( v27 <= 1 )
        {
          v31 = _frame.a2[0];
          *(volatile uint8_t *)(*(volatile uint32_t *)a2_0 + v25) = _frame.a2[0];
          v32 = *(volatile uint32_t *)a2_0 + v25;
          *(volatile uint8_t *)(v32 + 6) = v31;
          *(volatile uint8_t *)(v32 + 12) = v31;
        }
        ++v25;
      }
      while ( v25 != 6 );
    }
    v33 = 31 - __clz(rf_reg_0x1b());
    *v17 = v33;
  }
  else
  {
    memset((void *)(_frame.v69), 0, sizeof(_frame.v69));
    v46 = send_smc_cmd_4((int)_frame.v69);
    if ( v46 )
    {
      v17 = (volatile char *)off_1038A8;
    }
    else
    {
      debug_printf(aFlTxpwrOfst24g);
      v62 = _frame.v69;
      do
      {
        debug_printf("\r\n  [%d] =", v46);
        v63 = 3 * v46;
        v64 = (volatile char *)v62;
        for ( m = 0; m != 3; ++m )
        {
          v66 = *v64++;
          *(volatile uint8_t *)(*(volatile uint32_t *)asc_151888 + v63 + m) = v66;
          v67 = *(volatile char *)(*(volatile uint32_t *)asc_151888 + v63 + m);
          debug_printf(" %d", v67);
        }
        ++v46;
        v62 = (volatile uint32_t *)((volatile char *)v62 + 3);
      }
      while ( v46 != 3 );
      v17 = (volatile char *)off_103A4C;
      debug_printf(&aNoTxDscrHdr[16]);
      v17[1] |= 1u;
    }
    memset(_frame.a2, 0, 20);
    if ( !send_smc_cmd_0x20((int)_frame.a2) )
    {
      debug_printf(aFlTxpwrOfst5g);
      v56 = 0;
      v57 = _frame.a2;
      do
      {
        debug_printf("\r\n  [%d] =", v56);
        v58 = v57;
        for ( n = 0; n != 6; ++n )
        {
          v60 = *v58++;
          *(volatile uint8_t *)(*(volatile uint32_t *)a2_0 + n + 6 * v56) = v60;
          v61 = *(volatile uint32_t *)a2_0 + n;
          debug_printf(" %d", *(volatile char *)(v61 + 6 * v56));
        }
        ++v56;
        v57 += 6;
      }
      while ( v56 != 3 );
      debug_printf(&aNoTxDscrHdr[16]);
      v17[1] |= 1u;
    }
    if ( patch_validate((int)_frame.v68) )
    {
      v33 = -1;
      *v17 = -1;
    }
    else
    {
      v47 = _frame.v68[0];
      *v17 = _frame.v68[0];
      v33 = v47;
    }
  }
  debug_printf("cal_ver=%d\n", v33);
  if ( *((volatile uint8_t *)v9 + 372) )
  {
    if ( (*(volatile uint32_t *)off_10389C & 0x2000000) != 0 )
    {
      if ( rf_reg_0x0f_bit_18() )
      {
        v48 = rf_reg_0x11_bits_0_2();
        v49 = (volatile int *)off_1038F4;
        v50 = (void *)(uintptr_t)(off_1038F8);
        *(volatile uint8_t *)off_1038F8 = *((volatile uint8_t *)off_1038F4 + v48);
        v50[1] = *((volatile uint8_t *)v49 + rf_reg_0x11_bits_3_5());
        v50[2] = *((volatile uint8_t *)v49 + rf_reg_0x11_bits_6_8());
      }
    }
    else
    {
      *(volatile uint32_t *)_frame.a2 = 0;
      if ( !send_smc_cmd_0x40((int)_frame.a2) )
      {
        v53 = (void *)(uintptr_t)(off_103A30);
        v54 = *((volatile uint8_t *)off_103A2C + _frame.a2[1]);
        v55 = *((volatile uint8_t *)off_103A2C + _frame.a2[2]);
        *(volatile uint8_t *)off_103A30 = *((volatile uint8_t *)off_103A2C + _frame.a2[0]);
        v53[1] = v54;
        v53[2] = v55;
      }
    }
  }
  v34 = off_1038B8;
  v35 = (void *)(uintptr_t)(off_1038C0);
  *(volatile uint32_t *)off_1038B4 &= 0xFFFFFFC7;
  uart_send_data(0, 0, 0x10u, v34);
  uart_send_data(0, 16, 0x10u, off_1038C4);
  uart_send_data(0, 32, 0x10u, (int)off_151B28);
  uart_send_data(0, 48, 0x10u, (int)((volatile uint32_t *)(uintptr_t)&off_151B24)[0]);
  uart_send_data(0, 64, 0x10u, *(volatile int *)aT);
  uart_send_data(1, 0, 0x10u, *(volatile int *)aX);
  uart_send_data(1, 16, 0x10u, *(volatile int *)asc_152738);
  rf_config_read_b();
  rf_calibrate_mdll_duty(1);
  rf_config_read_a(0);
  rf_calibrate_mdll_duty(0);
  *(volatile uint32_t *)off_1038D0 |= 0x8000000u;
  v36 = rf_power_adjust();
  v37 = ((int)(((uint64_t)((int32_t)dword_1038D4 * (int64_t)(int32_t)(4 * (v36 - 35))) >> 32) + 4 * (v36 - 35)) >> 2)
      - ((4 * (v36 - 35)) >> 31)
      + 120;
  *(volatile uint16_t *)off_103904 = v37;
  *v35 = v37;
  alloc_tx_event("Init T=%d C, ipa_target=%d\n", v36, v37);
  v38 = rf_gpio_init((int)_frame.a2);
  debug_printf("cal_ipa_5g offset=%d, cgm=%d\n", v38, *(volatile uint32_t *)_frame.a2);
  if ( (v17[1] & 1) != 0 && *v17 < 0 )
  {
    v39 = (volatile unsigned int *)off_1038E4;
    *(volatile uint32_t *)off_1038E0 = *(volatile uint32_t *)off_1038E0 & 0xFFFFFF87 | 0x40;
    *v39 = *v39 & 0xFFF87FFF | 0x40000;
  }
  v40 = rf_gpio_init_alt();
  return debug_printf("cal_ipa_24g offset=%d\n", v40);
}


// rf_set_control_bit @ 0x103a54
int rf_set_control_bit() {
  volatile uint32_t *v0; // r2
  int v1; // r3
  volatile uint32_t *v2; // r3
  volatile uint32_t *v3; // r2
  int v4; // r3
  volatile uint32_t *v5; // r3
  volatile uint32_t *v6; // r0

  v0 = (void *)(uintptr_t)(off_103AE4);
  *(volatile uint32_t *)off_103AE0 |= 1u;
  while ( (*v0 & 0x10) == 0 )
  {
    v1 = (v1 & ~0xFFFFu) | ((uint16_t)(50) & 0xFFFFu);
    do
      v1 = (uint16_t)(v1 - 1);
    while ( v1 );
  }
  v2 = (void *)(uintptr_t)(off_103AE8);
  v3 = (void *)(uintptr_t)(off_103AE4);
  *(volatile uint32_t *)off_103AE8 |= 0x80000u;
  *v2 |= 0x100000u;
  while ( (*v3 & 8) == 0 )
  {
    v4 = (v4 & ~0xFFFFu) | ((uint16_t)(50) & 0xFFFFu);
    do
      v4 = (uint16_t)(v4 - 1);
    while ( v4 );
  }
  v5 = (void *)(uintptr_t)(off_103AF0);
  v6 = (void *)(uintptr_t)(off_103AF4);
  *(volatile uint32_t *)off_103AEC |= 0x20000u;
  *v5 |= 0x1000000u;
  *v5 |= 0x8000000u;
  *v6 |= 0x524u;
  return check_feature_flag(0x2000, aWfDfeAndRfintf);
}


// rf_calibrate @ 0x103afc
int rf_calibrate() {
  volatile uint32_t *v0; // r0
  volatile uint32_t *v1; // r1
  volatile uint32_t *v2; // r2

  v0 = (void *)(uintptr_t)(off_103B44);
  v1 = (void *)(uintptr_t)(off_103B48);
  v2 = (void *)(uintptr_t)(off_103B4C);
  *(volatile uint32_t *)off_103B40 &= 0xFFFFFA53;
  *v0 &= ~0x20000u;
  *v1 &= ~0x1000000u;
  *v2 &= 0xFFE7FFFF;
  mmio_read32(10);
  return check_feature_flag(0x2000, aWfDfeAndRfintf_0);
}


// rf_clear_ana_bits @ 0x103b54
int rf_clear_ana_bits() {
  volatile uint32_t *v0; // r4
  int result; // r0

  v0 = (void *)(uintptr_t)(off_103B88);
  *(volatile uint32_t *)off_103B88 &= ~0x400000u;
  *v0 &= ~0x200000u;
  mmio_read32(2);
  *v0 |= 0x200000u;
  result = mmio_read32(2);
  *v0 |= 0x400000u;
  return result;
}



// bb_start_cmd @ 0x103b8c
int bb_start_cmd(int a1) {
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

  *(volatile uint32_t *)off_103D7C = dword_103D80;
  if ( a1 )
  {
    switch ( a1 )
    {
      case 1:
        v11 = (volatile unsigned int *)off_103D84;
        v12 = (volatile int *)off_103D88;
        v13 = dword_103DB0;
        v14 = *(volatile uint32_t *)off_103D84;
        v15 = aDumpDac150m;
        v16 = *(volatile uint32_t *)off_103D84 & 0x70 | 1;
        break;
      case 10:
        v1 = (volatile unsigned int *)off_103D84;
        v2 = (volatile int *)off_103D88;
        v3 = *(volatile uint32_t *)off_103D84;
        v4 = dword_103DA8;
        v5 = *(volatile uint32_t *)off_103D84;
        v6 = aDumpDpdTxRx;
        goto LABEL_24;
      case 14:
        v1 = (volatile unsigned int *)off_103D84;
        v2 = (volatile int *)off_103D88;
        v3 = *(volatile uint32_t *)off_103D84;
        v4 = dword_103DB8;
        v5 = *(volatile uint32_t *)off_103D84;
        v6 = aDumpLoftOut;
        goto LABEL_24;
      case 2:
        v11 = (volatile unsigned int *)off_103D84;
        v12 = (volatile int *)off_103D88;
        v13 = dword_103DC0;
        v14 = *(volatile uint32_t *)off_103D84;
        v15 = aDumpAdcIn;
        v16 = *(volatile uint32_t *)off_103D84 & 0x70 | 2;
        break;
      default:
        switch ( a1 )
        {
          case 3:
            v1 = (volatile unsigned int *)off_103D84;
            v2 = (volatile int *)off_103D88;
            v3 = *(volatile uint32_t *)off_103D84;
            v4 = dword_103DC8;
            v5 = *(volatile uint32_t *)off_103D84;
            v6 = aDumpRxDataIq;
            break;
          case 30:
            v1 = (volatile unsigned int *)off_103D84;
            v2 = (volatile int *)off_103D88;
            v3 = *(volatile uint32_t *)off_103D84;
            v4 = dword_103DD0;
            v5 = *(volatile uint32_t *)off_103D84;
            v6 = aDumpRcAdcIq;
            break;
          case 31:
            v1 = (volatile unsigned int *)off_103D84;
            v2 = (volatile int *)off_103D88;
            v3 = *(volatile uint32_t *)off_103D84;
            v4 = dword_103DE0;
            v5 = *(volatile uint32_t *)off_103D84;
            v6 = aDumpDccancelOu;
            break;
          case 32:
            v1 = (volatile unsigned int *)off_103D84;
            v2 = (volatile int *)off_103D88;
            v3 = *(volatile uint32_t *)off_103D84;
            v4 = dword_103DE8;
            v5 = *(volatile uint32_t *)off_103D84;
            v6 = aDumpPreDgcOutI;
            break;
          case 33:
            v1 = (volatile unsigned int *)off_103D84;
            v2 = (volatile int *)off_103D88;
            v3 = *(volatile uint32_t *)off_103D84;
            v4 = dword_103DF0;
            v5 = *(volatile uint32_t *)off_103D84;
            v6 = aDumpNotchOutIq;
            break;
          default:
            if ( a1 != 4 )
            {
              if ( a1 == 5 )
              {
                v1 = (volatile unsigned int *)off_103D84;
                v2 = (volatile int *)off_103D88;
                v3 = *(volatile uint32_t *)off_103D84;
                v4 = dword_103DF8;
                v5 = *(volatile uint32_t *)off_103D84;
                v6 = aDumpRcOutIq;
                break;
              }
              if ( a1 != 50 )
              {
                switch ( a1 )
                {
                  case 6:
                    v1 = (volatile unsigned int *)off_103D84;
                    v2 = (volatile int *)off_103D88;
                    v3 = *(volatile uint32_t *)off_103D84;
                    v4 = dword_103E00;
                    v5 = *(volatile uint32_t *)off_103D84;
                    v6 = aDumpRcStatus;
                    break;
                  case 7:
                    v17 = (volatile unsigned int *)off_103D98;
                    v18 = (volatile int *)off_103D88;
                    v19 = dword_103D9C;
                    *(volatile uint32_t *)off_103D84 &= 0xFFFFFF70;
                    *v17 = *v17 & 0xFF00FFFF | 0x540000;
                    *v18 = v19;
                    alloc_tx_event(aDumpLpfOutBpfO);
                    goto LABEL_22;
                  case 8:
                    v1 = (volatile unsigned int *)off_103D84;
                    v2 = (volatile int *)off_103D88;
                    v4 = dword_103D9C;
                    v6 = aDumpGainLoft2I;
                    *(volatile uint32_t *)off_103D98 = *(volatile uint32_t *)off_103D98 & 0xFF00FFFF | 0x570000;
                    v3 = *v1;
                    v5 = *v1;
                    break;
                  case 81:
                    v1 = (volatile unsigned int *)off_103D84;
                    v2 = (volatile int *)off_103D88;
                    v4 = dword_103D9C;
                    v6 = aDumpGainLoftIn;
                    *(volatile uint32_t *)off_103D98 = *(volatile uint32_t *)off_103D98 & 0xFF00FFFF | 0x30000;
                    v3 = *v1;
                    v5 = *v1;
                    break;
                  default:
                    v1 = (volatile unsigned int *)off_103D84;
                    v2 = (volatile int *)off_103D88;
                    v3 = *(volatile uint32_t *)off_103D84;
                    v4 = dword_103D8C;
                    v5 = *(volatile uint32_t *)off_103D84;
                    if ( a1 == 9 )
                      v6 = aDumpAuxFifoOut;
                    else
                      v6 = aReselectMode;
                    break;
                }
                break;
              }
            }
            v1 = (volatile unsigned int *)off_103D84;
            v2 = (volatile int *)off_103D88;
            v3 = *(volatile uint32_t *)off_103D84;
            v4 = dword_103DD8;
            v5 = *(volatile uint32_t *)off_103D84;
            v6 = aDumpRcInIq;
            break;
        }
LABEL_24:
        *v1 = v5 & 0xFFFFFF00 | v3 & 0x70;
        *v2 = v4;
        alloc_tx_event(v6);
        goto LABEL_22;
    }
    *v11 = v16 | v14 & 0xFFFFFF00;
    *v12 = v13;
    alloc_tx_event(v15);
    goto LABEL_22;
  }
  v7 = (volatile unsigned int *)off_103D98;
  v8 = (volatile int *)off_103D88;
  v9 = dword_103D9C;
  *(volatile uint32_t *)off_103D84 &= 0xFFFFFF70;
  *v7 = *v7 & 0xFF00FFFF | 0x770000;
  *v8 = v9;
  alloc_tx_event(aDumpLoftPwrInO);
LABEL_22:
  *(volatile uint32_t *)off_103DA4 = 769;
  return mmio_read32(500);
}


// tx_wait_ready @ 0x103e14
int tx_wait_ready() {
  volatile int *v0; // r4
  volatile int *v1; // r3
  int v2; // r1
  volatile uint32_t *v3; // r2

  v0 = (volatile int *)off_103E70;
  *(volatile uint32_t *)off_103E6C = 777;
  while ( *v0 < 0 )
    mmio_read32(1);
  alloc_tx_event("end_addr=%d\n", *(volatile uint32_t *)off_103E70);
  *(volatile uint32_t *)off_103E6C = 0;
  alloc_tx_event(aFinish);
  v1 = (volatile int *)off_103E80;
  v2 = dword_103E84;
  v3 = (void *)(uintptr_t)(off_103E88);
  *(volatile uint32_t *)off_103E7C = 0;
  *v1 = v2;
  *v3 &= 0xFF00FFFF;
  return alloc_tx_event("*0* dump    r 00100000 %d**\n", 0x4000);
}


// scan_enable @ 0x103e90
volatile int * scan_enable(int a1) {
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

  v1 = (volatile unsigned int *)off_103F0C;
  *(volatile uint32_t *)off_103F08 |= 0x100u;
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
    v9 = dword_103F10 + v3;
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
  *(volatile uint32_t *)off_103F08 &= ~0x100u;
  return result;
}



// mul3 @ 0x103f14
int mul3(int a1, int a2, int a3) {
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
    v17 = dword_103FDC;
    v16[13] = dword_103FD8;
    v16[14] = v17;
    v18 = dword_103FE0;
    v19 = dword_103FE4;
    v16[12] = dword_103FE8;
    v16[18] = 0;
    v16[19] = 0;
    v16[20] = 0;
    v16[21] = 0;
    v16[22] = 0;
    v16[23] = 0;
    v16[15] = dword_103FEC;
    v16[16] = v18;
    v16[17] = v19;
  }
  v4 = 4 * v3;
  v5 = (volatile unsigned int *)off_103FD4;
  v6 = dword_103FF0;
  *(volatile uint32_t *)off_103FD0 |= 0x100u;
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
  *(volatile uint32_t *)off_103FD0 &= ~0x100u;
  return result;
}



// rf_enable_switch @ 0x103ff4
unsigned int rf_enable_switch(int a1, int a2) {
  volatile unsigned int *v2; // r2
  volatile unsigned int *v3; // r3
  int v4; // r4
  volatile uint32_t *v5; // r6
  unsigned int result; // r0

  v2 = (volatile unsigned int *)off_104074;
  v3 = (volatile unsigned int *)off_104078;
  v4 = *(volatile uint32_t *)off_104074;
  v5 = (void *)(uintptr_t)(off_10407C);
  *(volatile uint32_t *)off_104074 |= 0x1000000u;
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



// bt_radio_init @ 0x104080
volatile uint32_t *bt_radio_init() {
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

  v0 = (volatile unsigned int *)off_104158;
  v1 = (volatile unsigned int *)off_10415C;
  v2 = (void *)(uintptr_t)(off_104160);
  v3 = (void *)(uintptr_t)(off_104164);
  v4 = (void *)(uintptr_t)(off_104168);
  v5 = (volatile unsigned int *)off_10416C;
  *(volatile uint32_t *)off_104158 &= ~0x200u;
  *v1 = *v1 & 0xFC000FFF | 0x333000;
  *v2 = 8;
  *v3 |= 0x1000000u;
  v0 -= 136;
  *v4 |= 0x2000000u;
  *v0 &= ~0x20000u;
  mmio_read32(2);
  v6 = (void *)(uintptr_t)(off_104170);
  result = (void *)(uintptr_t)(off_104174);
  v8 = (void *)(uintptr_t)(off_104178);
  *v0 |= 0x10000u;
  *v0 |= 0x20000u;
  *v0 = *v0 & 0xFFFF0FFF | 0x6000;
  *v0 |= 0x80000u;
  v9 = dword_10417C;
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



// rf_disable @ 0x104180
/* luna: Disables the RF hardware by clearing enable, clock, and power-control bits in its MMIO registers. */
volatile unsigned int *rf_disable() {
  volatile unsigned int *v0; // r1
  volatile uint32_t *v1; // r0
  volatile unsigned int *v2; // r2
  volatile uint32_t *v3; // r6
  volatile uint32_t *v4; // r5
  volatile uint32_t *v5; // r4
  volatile unsigned int *result; // r0

  v0 = (volatile unsigned int *)off_10425C;
  v1 = (void *)(uintptr_t)(off_104260);
  v2 = (volatile unsigned int *)off_104264;
  *(volatile uint32_t *)off_10425C &= ~0x10000000u;
  v3 = (void *)(uintptr_t)(off_104268);
  v4 = (void *)(uintptr_t)(off_10426C);
  v5 = (void *)(uintptr_t)(off_104270);
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



// tx_ring_next_idx @ 0x104274
int tx_ring_next_idx(int a1, int a2, volatile uint32_t *a3) {
  int v3; // r3
  int v4; // r4
  int result; // r0

  v3 = (uint16_t)*(volatile uint32_t *)off_1042B8;
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



// rf_remove_iq_dc_offset @ 0x1042bc
int rf_remove_iq_dc_offset() {
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
    check_feature_flag(1, aWarningDataSat);
  check_feature_flag(1, "sum_i=%d\nsum_q=%d\ndc_i=%d\ndc_q=%d\n", v9, v8, v9 / 0x2000, v8 / 0x2000);
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


// mac_config_and_start @ 0x1043c8
/* luna: Configures the RF dump path for tone type 3, waits for the capture to finish, and restores the saved control state. */
int mac_config_and_start() {
  volatile int *rf_register_base; // r1
  volatile uint32_t *dump_control_reg; // r3
  int v2; // r0
  int saved_control_value; // r5
  volatile uint32_t *v4; // r6
  volatile int *dump_end_addr_reg; // r4
  int result; // r0
  volatile uint32_t *v7; // r3
  volatile uint32_t *v8; // r1

  rf_register_base = (volatile int *)off_10449C;
  dump_control_reg = (void *)(uintptr_t)(off_1044A4);
  v2 = dword_1044A8;
  saved_control_value = *(volatile uint32_t *)off_1044A0;
  *(volatile uint32_t *)off_1044A0 = dword_1044AC;
  *rf_register_base = v2;
  v4 = (void *)(uintptr_t)(off_1044B0);
  dump_end_addr_reg = (volatile int *)off_1044B4;
  *dump_control_reg = *dump_control_reg & 0xFC000FFF | 0x333000;
  *dump_control_reg &= 0x3FFFFFFFu;
  *dump_control_reg |= 0xC000000u;
  *dump_control_reg = ~(~(*dump_control_reg >> 12) << 12);
  rf_register_base[29] = rf_register_base[29] & 0xFFFFFF0F | 0xA0;
  *dump_control_reg |= 0x10000000u;
  mmio_read32(10);
  *v4 = dword_1044B8;
  mmio_read32(125);
  *v4 = dword_1044BC;
  while ( *dump_end_addr_reg < 0 )
    mmio_read32(1);
  check_feature_flag(1, "end_addr=%x\n", *(volatile uint32_t *)off_1044B4);
  *(volatile uint32_t *)off_1044B0 = 0;
  check_feature_flag(1, aDumpFinish);
  *(volatile uint32_t *)off_1044A0 = saved_control_value;
  rf_remove_iq_dc_offset();
  result = check_feature_flag(1, "** dump tone typ3   r 00100000 %d**\n", 0x4000);
  v7 = (void *)(uintptr_t)(off_1044A4);
  v8 = (void *)(uintptr_t)(off_1044CC);
  *(volatile uint32_t *)off_1044A4 &= 0xF3FFFFFF;
  *v8 |= 0xF0u;
  *v7 &= ~0x10000000u;
  *v7 &= 0x3FFFFFFFu;
  return result;
}


// tx_desc_parse @ 0x1044d0
int tx_desc_parse(int a1, int a2, volatile uint32_t *a3) {
  int v3; // r2
  unsigned int v4; // r0
  int v5; // r3

  v3 = a3[tx_ring_next_idx(a1, a2, a3)];
  v4 = (unsigned int)v3 >> 20;
  v5 = (uint16_t)v3 >> 4;
  if ( v3 < 0 )
    v4 -= 4096;
  if ( (((unsigned int)v3 >> 4) & 0x800) != 0 )
    v5 -= 4096;
  return v5 * v5 + v4 * v4;
}



