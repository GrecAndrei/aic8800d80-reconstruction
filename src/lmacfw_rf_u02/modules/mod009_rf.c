// get_device_state @ 0x11394c
void get_device_state() {
  unsigned int v0; // r5
  int v1; // r4
  int v2; // lr
  unsigned int CPSR; // r1
  unsigned int v4; // r2
  unsigned int v5; // r5
  unsigned int v6; // r4
  unsigned int v7; // r4
  unsigned int v8; // r5
  int v9; // r1

  v0 = off_113A0C;
  v1 = *(volatile uint32_t *)(*(volatile uint32_t *)off_113A0C + 16);
  dispatch_event_handler_1("\nINT:%x,%x,%x", v1, *(volatile uint32_t *)off_113A14, *(volatile uint32_t *)off_113A10);
  if ( (v1 & 1) != 0 )
    *(volatile uint32_t *)(*(volatile uint32_t *)v0 + 12) = 1;
  CPSR = __get_CPSR();
  v4 = __get_CPSR();
  v5 = __get_CPSR();
  v6 = __get_CPSR();
  dispatch_event_handler_1(aControl08xXpsr_0, CPSR, v4, v5, v6, __get_CPSR(), v2);
  if ( v5 )
  {
    dispatch_event_handler_1(aWrongPsp);
    if ( !v6 )
      goto LABEL_5;
  }
  else if ( !v6 )
  {
    goto LABEL_5;
  }
  v7 = v6 & 0xFFFFFFF0;
  v8 = (dword_113A3C - v7) >> 2;
  dispatch_event_handler_1(aDumpmsp_0);
  v9 = v8;
  if ( v8 >= 0x100 )
    v9 = 256;
  handle_ipc_request(v7, v9, 4, 0);
LABEL_5:
  dispatch_event_handler_1(aIser);
  handle_ipc_request(dword_113A24, 8, 4, 0);
  dispatch_event_handler_1(aIspr);
  handle_ipc_request(dword_113A2C, 8, 4, 0);
  dispatch_event_handler_1(aTim2);
  handle_ipc_request((int)REG_4050_1000, 16, 4, 0);
  bt_check_state();
}


// mmio_read32 @ 0x113a44
int mmio_read32(unsigned int a1) {
  int v1; // r8
  volatile uint32_t *v3; // r3
  unsigned int v4; // r6
  volatile uint32_t *v5; // r5
  int v6; // r4
  unsigned int v7; // r2
  volatile uint32_t *v8; // r3

  while ( !*(volatile uint32_t *)off_113AC8 )
    ;
  if ( a1 <= 0x1F )
  {
    v3 = (void *)(uintptr_t)(off_113ACC);
    v1 = 0;
    *((volatile uint32_t *)off_113ACC + 16) = 1;
    v4 = a1 + 512;
    v5 = v3;
    v3[19] = 34816;
    v6 = 0;
    while ( 1 )
    {
      while ( 1 )
      {
        v5[21] = (v6 << 12) | 0x27D;
        __dsb(0xFu);
        v7 = v5[v4];
        if ( v7 <= 0x29 )
          break;
        v1 |= 1 << v6;
LABEL_7:
        if ( ++v6 == 32 )
          goto LABEL_11;
      }
      if ( v7 <= 0x26 )
        goto LABEL_7;
      ++v6;
      uart_tx_byte(101);
      if ( v6 == 32 )
      {
LABEL_11:
        v8 = (void *)(uintptr_t)(off_113ACC);
        *((volatile uint32_t *)off_113ACC + 16) = 0;
        v8[19] = 0;
        v8[21] &= ~4u;
        goto LABEL_4;
      }
    }
  }
  v1 = 0;
LABEL_4:
  *(volatile uint32_t *)off_113AC8 = 1;
  return v1;
}



// mmio_write32 @ 0x113ad0
int mmio_write32(unsigned int a1, int a2) {
  volatile uint32_t *v4; // r3

  get_bandgap_trim(1);
  while ( !*(volatile uint32_t *)off_113B28 )
    ;
  if ( a1 <= 0x1F )
  {
    v4 = (void *)(uintptr_t)(off_113B2C);
    *((volatile uint32_t *)off_113B2C + 16) = 1;
    v4[19] = 34816;
    v4[21] = 629;
    __dsb(0xFu);
    v4[a1 + 512] = a2;
    v4[16] = 0;
    v4[19] = 0;
    v4[21] &= ~4u;
  }
  *(volatile uint32_t *)off_113B28 = 1;
  return get_bandgap_trim(0);
}



// rf_get_reg1_bit9 @ 0x113b30
/* luna: Returns bit 9 of the selected RF register (offset/index 1) read via MMIO. */
unsigned int rf_get_reg1_bit9() {
  return ((unsigned int)mmio_read32(1u) >> 9) & 1;
}



// rf_set_reg1_bit9 @ 0x113b40
/* luna: Sets RF register 1 to 0x200 through the MMIO write32 accessor, enabling bit 9 of that register. */
int rf_set_reg1_bit9() {
  return mmio_write32(1u, 512);
}



// rf_get_reg1_bits13_16 @ 0x113b4c
/* luna: Reads RF register 1 through MMIO and returns the four-bit field extracted from bits 13 through 16. */
unsigned int rf_get_reg1_bits13_16() {
  return ((unsigned int)mmio_read32(1u) >> 13) & 0xF;
}



// mmio_rmw_field @ 0x113b5c
unsigned int mmio_rmw_field(int a1) {
  mmio_write32(1u, (a1 << 13) & 0x1E000);
  return ((unsigned int)mmio_read32(1u) >> 13) & 0xF;
}



// rf_get_reg2 @ 0x113b78
/* luna: Reads the 32-bit value from RF register index or MMIO offset 2. */
int rf_get_reg2() {
  return mmio_read32(2u);
}



// mmio_write_reg2 @ 0x113b80
int mmio_write_reg2(int a1) {
  return mmio_write32(2u, a1);
}



// mmio_read_status @ 0x113b88
int mmio_read_status(volatile uint8_t *a1) {
  int16_t v2; // r0

  v2 = mmio_read32(6u);
  if ( (v2 & 0xFF00) != 0 )
  {
    *a1 = HIBYTE(v2);
    return 0;
  }
  else
  {
    *a1 = v2;
    if ( (uint8_t)v2 )
      return 1;
    else
      return 2;
  }
}



// mmio_get_field @ 0x113bb0
int mmio_get_field(int a1) {
  int16_t v2; // r0
  char v3; // r1
  int v4; // r5

  v2 = mmio_read32(6u);
  v3 = v2;
  if ( !(uint8_t)v2 )
  {
    v4 = 1;
LABEL_3:
    mmio_write32(6u, a1 << v3);
    return v4;
  }
  v4 = HIBYTE(v2);
  if ( (v2 & 0xFF00) == 0 )
  {
    v3 = 8;
    goto LABEL_3;
  }
  return -1;
}



// mmio_read_byte @ 0x113be8
int mmio_read_byte(volatile uint8_t *a1) {
  unsigned int v2; // r0
  char v4; // r3

  v2 = mmio_read32(6u);
  if ( HIBYTE(v2) )
  {
    *a1 = HIBYTE(v2);
    return 0;
  }
  else
  {
    v4 = BYTE2(v2);
    if ( !HIWORD(v2) )
      v4 = 0;
    *a1 = v4;
    if ( HIWORD(v2) )
      return 1;
    else
      return 2;
  }
}



// mmio_wait_bit @ 0x113c14
int mmio_wait_bit(int a1) {
  unsigned int v2; // r0
  char v3; // r1
  int v4; // r4

  v2 = mmio_read32(6u);
  if ( (v2 & 0xFF0000) == 0 )
  {
    v3 = 16;
    v4 = 1;
LABEL_3:
    mmio_write32(6u, a1 << v3);
    return v4;
  }
  v4 = HIBYTE(v2);
  if ( !HIBYTE(v2) )
  {
    v3 = 24;
    goto LABEL_3;
  }
  return -1;
}



// mmio_read_pair @ 0x113c48
int mmio_read_pair(volatile int *a1, volatile unsigned int *a2) {
  unsigned int v4; // r4
  unsigned int v5; // r0
  unsigned int v6; // r4
  unsigned int v7; // r3
  int v8; // r4
  int result; // r0
  uint16_t v10; // r0

  v4 = mmio_read32(8u);
  v5 = mmio_read32(9u);
  v6 = HIWORD(v4) << 16;
  if ( v6 | v5 )
  {
    v7 = HIWORD(v5);
    v8 = (v5 << 16) | HIWORD(v6);
    result = 0;
  }
  else
  {
    v8 = mmio_read32(7u);
    v10 = mmio_read32(8u);
    v7 = v10;
    if ( v8 )
    {
      result = 1;
    }
    else if ( v10 )
    {
      result = 1;
    }
    else
    {
      result = 2;
    }
  }
  *a1 = v8;
  *a2 = v7;
  return result;
}



// rf_status_check @ 0x113c98
int rf_status_check(unsigned int a1, int a2) {
  int v4; // r4
  unsigned int v5; // r4

  v4 = mmio_read32(7u);
  if ( (uint16_t)mmio_read32(8u) | v4 )
  {
    v5 = mmio_read32(8u);
    if ( (HIWORD(v5) << 16) | mmio_read32(9u) )
    {
      return -1;
    }
    else
    {
      mmio_write32(8u, a1 << 16);
      mmio_write32(9u, HIWORD(a1) | (a2 << 16));
      return 0;
    }
  }
  else
  {
    mmio_write32(7u, a1);
    mmio_write32(8u, a2);
    return 1;
  }
}



// rf_irq_bit16_check @ 0x113d00
int rf_irq_bit16_check(volatile int *a1, volatile unsigned int *a2) {
  unsigned int v4; // r0
  int v5; // r4
  int result; // r0
  unsigned int v7; // r7
  unsigned int v8; // r0
  unsigned int v9; // r7
  int v10; // r7
  unsigned int v11; // r0

  v4 = mmio_read32(0xFu);
  v5 = HIWORD(v4) & 1;
  if ( (v4 & 0x10000) != 0 )
  {
    result = mmio_read_pair(a1, a2);
    if ( result <= 1 )
      *a1 = *a1 & 0xFFFFFF00 | (uint8_t)(*a1 + 1);
  }
  else
  {
    v7 = mmio_read32(0xDu);
    v8 = mmio_read32(0xEu);
    v9 = HIWORD(v7) << 16;
    if ( v9 | v8 )
    {
      v10 = (v8 << 16) | HIWORD(v9);
      v11 = HIWORD(v8);
    }
    else
    {
      v10 = mmio_read32(0xCu);
      v11 = (uint16_t)mmio_read32(0xDu);
      if ( v10 )
      {
        v5 = 1;
      }
      else if ( (uint16_t)v11 )
      {
        v5 = 1;
      }
      else
      {
        v5 = 2;
      }
    }
    *a1 = v10;
    *a2 = v11;
    return v5;
  }
  return result;
}



// rf_irq_handle @ 0x113d80
int rf_irq_handle(unsigned int a1, int a2) {
  int v4; // r4
  unsigned int v5; // r4

  if ( (mmio_read32(0xFu) & 0x10000) != 0 )
    return -2;
  v4 = mmio_read32(0xCu);
  if ( (uint16_t)mmio_read32(0xDu) | v4 )
  {
    v5 = mmio_read32(0xDu);
    if ( (HIWORD(v5) << 16) | mmio_read32(0xEu) )
    {
      return -1;
    }
    else
    {
      mmio_write32(0xDu, a1 << 16);
      mmio_write32(0xEu, HIWORD(a1) | (a2 << 16));
      return 0;
    }
  }
  else
  {
    mmio_write32(0xCu, a1);
    mmio_write32(0xDu, a2);
    return 1;
  }
}



// tx_desc_init @ 0x113df8
int tx_desc_init(int a1, int a2) {
  int v3; // r1
  int v4; // r2
  unsigned int v5; // r0
  int v6; // r3
  int v7; // r1
  unsigned int v8; // r2
  char v9; // r5
  unsigned int v10; // r4
  char v11; // r2
  volatile uint8_t *v12; // r2
  uint32_t v14[3]; // [sp+4h] [bp-10h]

  v3 = *(volatile uint32_t *)(dword_113E6C + 4);
  v4 = *(volatile uint32_t *)(dword_113E6C + 8);
  v14[0] = *(volatile uint32_t *)dword_113E6C;
  v14[1] = v3;
  v14[2] = v4;
  v5 = mmio_read32(v14[a1]);
  v6 = 0;
  v7 = 0;
  do
  {
    v8 = v5 >> (8 * v6);
    v9 = v8;
    v10 = (uint8_t)v8 >> 4;
    if ( (v8 & 0xF0) == 0 )
    {
      if ( !(uint8_t)v8 )
      {
        v7 |= 2 << (4 * v6);
        v12 = (volatile uint8_t *)(a2 + v6);
        goto LABEL_9;
      }
      v7 |= 1 << (4 * v6);
      v10 = (uint8_t)v8;
    }
    if ( (v10 & 1) != 0 )
      v11 = -1;
    else
      v11 = 1;
    v9 = (v10 >> 1) * v11;
    v12 = (volatile uint8_t *)(a2 + v6);
LABEL_9:
    ++v6;
    *v12 = v9;
  }
  while ( v6 != 3 );
  return v7;
}



// tx_desc_build @ 0x113e70
int tx_desc_build(int a1, char a2, volatile uint8_t *a3) {
  int v5; // r1
  int v6; // r2
  unsigned int v7; // r0
  unsigned int v8; // r3
  int result; // r0
  char v10; // r2
  uint32_t v11[3]; // [sp+4h] [bp-Ch]

  v5 = *(volatile uint32_t *)(dword_113ECC + 4);
  v6 = *(volatile uint32_t *)(dword_113ECC + 8);
  v11[0] = *(volatile uint32_t *)dword_113ECC;
  v11[1] = v5;
  v11[2] = v6;
  v7 = (unsigned int)mmio_read32(v11[a1]) >> (8 * a2);
  v8 = (uint8_t)v7 >> 4;
  if ( (v7 & 0xF0) != 0 )
  {
    result = 0;
  }
  else
  {
    if ( !(uint8_t)v7 )
    {
      *a3 = 0;
      return 2;
    }
    v8 = (uint8_t)v7;
    result = 1;
  }
  if ( (v8 & 1) != 0 )
    v10 = -1;
  else
    v10 = 1;
  *a3 = (v8 >> 1) * v10;
  return result;
}



// tx_packet_prepare @ 0x113ed0
int tx_packet_prepare(int a1, char a2, int a3) {
  int v5; // r1
  int v6; // r2
  unsigned int v7; // r5
  unsigned int v8; // r0
  char v9; // r1
  unsigned int v10; // r0
  unsigned int v11; // r6
  int v12; // r0
  int v13; // r6
  uint8_t v15; // r4
  uint32_t v16[3]; // [sp+4h] [bp-Ch]

  v5 = *(volatile uint32_t *)(dword_113F38 + 4);
  v6 = *(volatile uint32_t *)(dword_113F38 + 8);
  v16[0] = *(volatile uint32_t *)dword_113F38;
  v16[1] = v5;
  v16[2] = v6;
  v7 = v16[a1];
  v8 = mmio_read32(v7);
  v9 = 8 * a2;
  v10 = v8 >> (8 * a2);
  v11 = (uint8_t)v10;
  v12 = v10 & 0xF;
  if ( v12 )
  {
    v13 = v11 >> 4;
    if ( v13 )
      return -1;
    v12 = (v12 & ~0xFFu) | ((uint8_t)(4) & 0xFFu);
  }
  else
  {
    v13 = 1;
  }
  if ( a3 > 0 )
    v15 = 2 * a3;
  else
    v15 = (-2 * a3) | 1;
  mmio_write32(v7, v15 << v12 << v9);
  return v13;
}



// rx_desc_init @ 0x113f3c
int rx_desc_init(int a1, int a2) {
  int v3; // r1
  int v4; // r2
  unsigned int v5; // r6
  unsigned int v6; // r4
  int v7; // r0
  int v8; // r3
  int result; // r0
  unsigned int v10; // r4
  int v11; // zf
  int v12; // r2
  unsigned int v13; // r4
  unsigned int v14; // r7
  volatile uint8_t *v15; // r4
  struct __attribute__((packed)) { unsigned int v16; // [sp+4h] [bp-18h]
  int v17; // [sp+8h] [bp-14h]
  uint32_t v18[4]; // [sp+Ch] [bp-10h] BYREF
  } _frame;
  v3 = *(volatile uint32_t *)(dword_113FD4 + 4);
  v4 = *(volatile uint32_t *)(dword_113FD4 + 8);
  _frame.v18[0] = *(volatile uint32_t *)dword_113FD4;
  _frame.v18[1] = v3;
  _frame.v18[2] = v4;
  v5 = _frame.v18[a1];
  v6 = mmio_read32(v5);
  _frame.v16 = v6;
  v7 = mmio_read32(v5 + 1);
  v8 = 0;
  _frame.v17 = v7;
  result = 0;
  while ( 1 )
  {
    v12 = v6 >> (8 * (v8 & 3));
    v14 = (uint8_t)v12;
    v10 = (uint8_t)v12 >> 4;
    if ( (v12 & 0xF0) == 0 )
    {
      v12 = 1 << (4 * v8);
      if ( !v14 )
      {
        result |= 2 << (4 * v8);
        v15 = (volatile uint8_t *)(a2 + v8);
        goto LABEL_8;
      }
      result |= v12;
      v10 = v14;
    }
    v11 = (v10 & 1) == 0;
    if ( (v10 & 1) != 0 )
      v12 = (v12 & ~0xFFu) | ((uint8_t)(-1) & 0xFFu);
    v13 = v10 >> 1;
    if ( v11 )
      v12 = (v12 & ~0xFFu) | ((uint8_t)(1) & 0xFFu);
    v14 = (v14 & ~0xFFu) | ((uint8_t)(v13 * v12) & 0xFFu);
    v15 = (volatile uint8_t *)(a2 + v8);
LABEL_8:
    ++v8;
    *v15 = v14;
    if ( v8 == 6 )
      return result;
    v6 = *(volatile uint32_t *)((volatile char *)&_frame.v18[-2] + (v8 & 0xFFFFFFFC));
  }
}



// rx_desc_build @ 0x113fd8
int rx_desc_build(int a1, int a2, volatile uint8_t *a3) {
  int v5; // r1
  int v6; // r2
  unsigned int v7; // r0
  unsigned int v8; // r4
  unsigned int v9; // r3
  int result; // r0
  char v11; // r2
  uint32_t v12[3]; // [sp+4h] [bp-Ch]

  v5 = *(volatile uint32_t *)(dword_114040 + 4);
  v6 = *(volatile uint32_t *)(dword_114040 + 8);
  v12[0] = *(volatile uint32_t *)dword_114040;
  v12[1] = v5;
  v12[2] = v6;
  v7 = v12[a1];
  if ( a2 > 3 )
  {
    ++v7;
    a2 = (a2 & ~0xFFu) | ((uint8_t)(a2 - 4) & 0xFFu);
  }
  v8 = (unsigned int)mmio_read32(v7) >> (8 * a2);
  v9 = (uint8_t)v8 >> 4;
  if ( (v8 & 0xF0) != 0 )
  {
    result = 0;
  }
  else
  {
    if ( !(uint8_t)v8 )
    {
      *a3 = 0;
      return 2;
    }
    v9 = (uint8_t)v8;
    result = 1;
  }
  if ( (v9 & 1) != 0 )
    v11 = -1;
  else
    v11 = 1;
  *a3 = (v9 >> 1) * v11;
  return result;
}



// rx_packet_prepare @ 0x114044
int rx_packet_prepare(int a1, int a2, int a3) {
  int v5; // r1
  int v6; // r2
  unsigned int v7; // r6
  char v8; // r5
  unsigned int v9; // r0
  unsigned int v10; // r7
  int v11; // r0
  int v12; // r7
  uint8_t v14; // r1
  uint32_t v15[3]; // [sp+4h] [bp-10h]

  v5 = *(volatile uint32_t *)(dword_1140B4 + 4);
  v6 = *(volatile uint32_t *)(dword_1140B4 + 8);
  v15[0] = *(volatile uint32_t *)dword_1140B4;
  v15[1] = v5;
  v15[2] = v6;
  v7 = v15[a1];
  if ( a2 > 3 )
  {
    ++v7;
    a2 = (a2 & ~0xFFu) | ((uint8_t)(a2 - 4) & 0xFFu);
  }
  v8 = 8 * a2;
  v9 = (unsigned int)mmio_read32(v7) >> v8;
  v10 = (uint8_t)v9;
  v11 = v9 & 0xF;
  if ( v11 )
  {
    v12 = v10 >> 4;
    if ( v12 )
      return -1;
    v11 = (v11 & ~0xFFu) | ((uint8_t)(4) & 0xFFu);
  }
  else
  {
    v12 = 1;
  }
  if ( a3 > 0 )
    v14 = 2 * a3;
  else
    v14 = (-2 * a3) | 1;
  mmio_write32(v7, v14 << v11 << v8);
  return v12;
}



// rf_reg10_status @ 0x1140b8
int rf_reg10_status(volatile int *a1) {
  uint8_t v2; // r0
  int v3; // r2
  int result; // r0
  int v5; // r3

  v2 = mmio_read32(0x10u);
  v3 = v2 >> 4;
  if ( (v2 & 0xF0) != 0 )
  {
    result = 0;
  }
  else
  {
    if ( !v2 )
    {
      *a1 = 0;
      return 2;
    }
    v3 = v2;
    result = 1;
  }
  if ( (v3 & 8) != 0 )
    v5 = v3 & 7;
  else
    v5 = -v3;
  if ( (v3 & 8) != 0 )
    ++v5;
  *a1 = v5;
  return result;
}



// rf_reg10_low_check @ 0x1140f0
int rf_reg10_low_check(int a1) {
  uint8_t v2; // r0
  char v3; // r1
  int v4; // r4
  int v6; // r5

  v2 = mmio_read32(0x10u);
  v3 = v2 & 0xF;
  if ( (v2 & 0xF) != 0 )
  {
    v4 = v2 >> 4;
    if ( v4 )
      return -1;
    v3 = 4;
  }
  else
  {
    v4 = 1;
  }
  if ( (unsigned int)(a1 + 7) > 0xF )
    return v4 + 1;
  if ( a1 <= 0 )
    v6 = -a1;
  else
    v6 = (a1 - 1) | 8;
  mmio_write32(0x10u, v6 << v3);
  return v4;
}



// rf_get_reg0x11_bits0_2 @ 0x11413c
int rf_get_reg0x11_bits0_2() {
  return mmio_read32(0x11u) & 7;
}



// rf_get_reg0x11_bits3_5 @ 0x11414c
/* luna: Reads the RF/mmio register at offset 0x11 and returns bits 3 through 5. */
unsigned int rf_get_reg0x11_bits3_5() {
  return ((unsigned int)mmio_read32(0x11u) >> 3) & 7;
}



// rf_get_reg0x11_bits6_8 @ 0x11415c
/* luna: Extracts bits 6-8 from RF/MMIO register offset 0x11. */
unsigned int rf_get_reg0x11_bits6_8() {
  return ((unsigned int)mmio_read32(0x11u) >> 6) & 7;
}



// rf_regf_high_check @ 0x11416c
int rf_regf_high_check(volatile uint8_t *a1) {
  int16_t v2; // r0

  v2 = mmio_read32(0xFu);
  if ( (v2 & 0xFF00) != 0 )
  {
    *a1 = HIBYTE(v2);
    return 0;
  }
  else
  {
    *a1 = v2;
    if ( (uint8_t)v2 )
      return 1;
    else
      return 2;
  }
}



// rf_regf_mask_shift @ 0x114194
int rf_regf_mask_shift(int a1) {
  int16_t v2; // r0
  char v3; // r1
  int v4; // r5

  v2 = mmio_read32(0xFu);
  v3 = v2;
  if ( !(uint8_t)v2 )
  {
    v4 = 1;
LABEL_3:
    mmio_write32(0xFu, a1 << v3);
    return v4;
  }
  v4 = HIBYTE(v2);
  if ( (v2 & 0xFF00) == 0 )
  {
    v3 = 8;
    goto LABEL_3;
  }
  return -1;
}



// rf_get_reg0xf_bit18 @ 0x1141cc
/* luna: Reads RF register 0xF and returns bit 18. */
unsigned int rf_get_reg0xf_bit18() {
  return ((unsigned int)mmio_read32(0xFu) >> 18) & 1;
}



// rf_get_reg0xf_bit19 @ 0x1141dc
/* luna: Reads RF register 0xF via MMIO and extracts bit 19. */
unsigned int rf_get_reg0xf_bit19() {
  return ((unsigned int)mmio_read32(0xFu) >> 19) & 1;
}



// rf_set_reg0xf_bit19 @ 0x1141ec
/* luna: Write RF register 0xF with bit 19 (0x80000) set via the MMIO helper. */
int rf_set_reg0xf_bit19() {
  return mmio_write32(0xFu, 0x80000);
}



// rf_get_reg0xf_bit20 @ 0x1141f8
/* luna: Return bit 20 of the RF register located at offset 0xF via an MMIO read. */
unsigned int rf_get_reg0xf_bit20() {
  return ((unsigned int)mmio_read32(0xFu) >> 20) & 1;
}



// rf_get_reg0x1b @ 0x114208
int rf_get_reg0x1b() {
  return mmio_read32(0x1Bu);
}



// mmio_reg_write_1b @ 0x114210
int mmio_reg_write_1b(int a1) {
  return mmio_write32(0x1Bu, a1);
}



// ke_event_schedule @ 0x114218
int ke_event_schedule() {
  volatile int *v0; // r4
  int result; // r0
  int v2; // r3
  int v3; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_114250 = 1;
  }
  v0 = (volatile int *)off_114254;
  ++*(volatile uint32_t *)off_114254;
  result = ((int (*)())MEMD(0x1C8))();
  if ( *v0 )
  {
    v2 = *v0 - 1;
    v3 = *(volatile uint32_t *)off_114250;
    *v0 = v2;
    if ( !v2 )
    {
      if ( v3 )
        __enable_irq();
    }
  }
  return result;
}



// ke_event_schedule_alt @ 0x114258
int ke_event_schedule_alt() {
  volatile int *v0; // r4
  int result; // r0
  int v2; // r3
  int v3; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_114290 = 1;
  }
  v0 = (volatile int *)off_114294;
  ++*(volatile uint32_t *)off_114294;
  result = ((int (*)())MEMD(0x1D0))();
  if ( *v0 )
  {
    v2 = *v0 - 1;
    v3 = *(volatile uint32_t *)off_114290;
    *v0 = v2;
    if ( !v2 )
    {
      if ( v3 )
        __enable_irq();
    }
  }
  return result;
}



// ke_event_schedule_prio @ 0x114298
int ke_event_schedule_prio() {
  volatile int *v0; // r4
  int result; // r0
  int v2; // r3
  int v3; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_1142D0 = 1;
  }
  v0 = (volatile int *)off_1142D4;
  ++*(volatile uint32_t *)off_1142D4;
  result = ((int (*)())MEMD(0x1D4))();
  if ( *v0 )
  {
    v2 = *v0 - 1;
    v3 = *(volatile uint32_t *)off_1142D0;
    *v0 = v2;
    if ( !v2 )
    {
      if ( v3 )
        __enable_irq();
    }
  }
  return result;
}



// call_slot_0x1d8 @ 0x1142d8
int call_slot_0x1d8() {
  return ((int (*)())MEMD(0x1D8))();
}



// ke_event_busy_check @ 0x1142e0
void ke_event_busy_check() {
  volatile int *v0; // r4

  v0 = (volatile int *)off_11430C;
  if ( !*(volatile uint32_t *)off_11430C )
    *v0 = ke_event_schedule();
  if ( !*(volatile uint32_t *)off_114310 )
    *(volatile uint32_t *)off_114310 = *v0 + 67092480;
  *(volatile uint32_t *)off_114314 = 1;
}



