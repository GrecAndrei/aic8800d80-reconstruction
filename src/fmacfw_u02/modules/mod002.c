// check_radio_state @ 0x102bc0
/* luna: Logs a spurious interrupt and clears the associated register when its signed status flag is set. */
int check_radio_state() {
  int result; // r0

  result = event_dispatch("%s\r\n", aIntcSpurious);
  if ( **(volatile int16_t **)off_102BF0 < 0 )
    return mmio_clear_register(off_102BF8, (int)aIntcSpurious_0, 61);
  return result;
}


// install_isr @ 0x102bfc
/* luna: Installs radio interrupt handlers in the vector table, enables their NVIC lines, and globally enables interrupts. */
int install_isr() {
  volatile uint32_t *v0; // r2
  volatile uint8_t *nvic_register_base; // r3
  int irq5_and_irq7_handler; // r1
  int irq2_handler; // r0
  int irq6_handler; // r4
  int irq3_handler; // r0
  int vector_table_base; // r1
  volatile uint8_t *v7; // r2
  int enable_irq9_flag; // r2
  volatile uint32_t *v9; // r2
  volatile uint32_t *v10; // r3

  v0 = (void *)(uintptr_t)(off_102C80);
  nvic_register_base = (void *)(uintptr_t)(off_102C84);
  *(volatile uint32_t *)(*((volatile uint32_t *)off_102C80 + 2) + 80) = dword_102C88;
  *(volatile uint32_t *)nvic_register_base = 16;
  irq5_and_irq7_handler = dword_102C8C;
  *(volatile uint32_t *)(v0[2] + 84) = dword_102C8C;
  *(volatile uint32_t *)nvic_register_base = 32;
  irq2_handler = dword_102C90;
  *(volatile uint32_t *)(v0[2] + 92) = irq5_and_irq7_handler;
  *(volatile uint32_t *)nvic_register_base = 128;
  irq6_handler = dword_102C94;
  *(volatile uint32_t *)(v0[2] + 72) = irq2_handler;
  *(volatile uint32_t *)nvic_register_base = 4;
  irq3_handler = dword_102C98;
  *(volatile uint32_t *)(v0[2] + 88) = irq6_handler;
  *(volatile uint32_t *)nvic_register_base = 64;
  vector_table_base = v0[2];
  v7 = (volatile uint8_t *)off_102C9C;
  *(volatile uint32_t *)(vector_table_base + 76) = irq3_handler;
  enable_irq9_flag = v7[413];
  nvic_register_base[771] = -8;
  *(volatile uint32_t *)nvic_register_base = 8;
  if ( enable_irq9_flag )
    *(volatile uint32_t *)nvic_register_base = 512;
  v9 = (void *)(uintptr_t)(off_102C80);
  v10 = (void *)(uintptr_t)(off_102C84);
  *(volatile uint32_t *)(*((volatile uint32_t *)off_102C80 + 2) + 208) = off_102CA0;
  v10[1] = 16;
  *(volatile uint32_t *)(v9[2] + 212) = off_102CA4;
  v10[1] = 32;
  *v10 = 0x800000;
  v10[1] = 64;
  __enable_irq();
  return 32;
}



// set_wakeup_trigger @ 0x102ca8
/* luna: Selects one of two wakeup-trigger configurations in the control register using staged writes and short settling delays. */
volatile int * set_wakeup_trigger(int a1) {
  int v1; // r4
  int v2; // r1
  int v3; // zf
  int v4; // r2
  int v5; // r2
  int v6; // r3
  volatile int *result; // r0
  int v8; // r2
  int v9; // r3

  v2 = (int)off_102D08;
  v3 = a1 == 0;
  if ( a1 )
    v4 = -2;
  else
    v4 = -17;
  v5 = v4 & *(volatile uint32_t *)off_102D08;
  if ( !a1 )
    a1 = -33;
  *(volatile uint32_t *)off_102D08 = v5;
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
  result = (volatile int *)off_102D08;
  v8 = v9 | v2;
  *(volatile uint32_t *)off_102D08 = v9;
  v9 = (v9 & ~0xFFu) | ((uint8_t)(50) & 0xFFu);
  *result = v8;
  do
    v9 = (uint8_t)(v9 - 1);
  while ( v9 );
  *(volatile uint32_t *)off_102D08 = v8 | v1;
  return result;
}



// set_wakeup_polarity @ 0x102d0c
/* luna: Selects a wakeup-control bit group based on the argument and updates its configuration bits in a peripheral register. */
int set_wakeup_polarity(int result) {
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
  v4 = *(volatile uint32_t *)off_102D78 & v3;
  if ( !result )
    result = 32;
  *(volatile uint32_t *)off_102D78 = v4;
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
  *(volatile uint32_t *)off_102D78 = v6;
  v7 = (v7 & ~0xFFu) | ((uint8_t)(50) & 0xFFu);
  do
    v7 = (uint8_t)(v7 - 1);
  while ( v7 );
  v8 = v6 | result;
  *(volatile uint32_t *)off_102D78 = v8;
  v9 = (v9 & ~0xFFu) | ((uint8_t)(50) & 0xFFu);
  do
    v9 = (uint8_t)(v9 - 1);
  while ( v9 );
  *(volatile uint32_t *)off_102D78 = v8 | v3;
  return result;
}



// peripheral_write_32 @ 0x102d7c
/* luna: Writes 16 supplied values, shifted by 11, into selected peripheral register banks while preserving configured bits and updating the corresponding seco */
int peripheral_write_32(int a1, volatile uint16_t *a2) {
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
  while ( !*(volatile uint32_t *)off_102E98 )
    ;
  v4 = 0;
  set_wakeup_trigger(0);
  v5 = dword_102EA8;
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
  v7 = (volatile unsigned int *)(dword_102E9C + (v4 << 9));
  v8 = 0;
  v9 = _frame.v24 - 1;
  do
  {
    v10 = *v7;
    check_status_bits(0x2000, "before %d,%d: dcq/i=%4x\r\n", v4, v8, (uint16_t)(*v7 >> 11));
    v11 = v9[1];
    ++v9;
    v12 = v10 & v5 | (v11 << 11);
    *v7 = v12;
    v7 += 8;
    v13 = v8++;
    check_status_bits(0x2000, "after  %d,%d: dcq/i=%4x\r\n", v4, v13, (uint16_t)(v12 >> 11));
  }
  while ( v8 != 16 );
  if ( v4 <= 1 )
    goto LABEL_4;
  _frame.v23 = 1;
  if ( (uint16_t)v4 != 5 )
    goto LABEL_4;
LABEL_10:
  result = set_wakeup_polarity(0);
  *(volatile uint32_t *)off_102E98 = 1;
  if ( _frame.v23 )
  {
    v15 = *(volatile uint32_t *)off_102EA4;
    _frame.v25 = *(volatile uint64_t *)off_102EA4;
    _frame.v26 = *(volatile uint32_t *)(off_102EA4 + 8);
    v16 = 3;
  }
  else
  {
    v15 = qword_102EAC;
    _frame.v26 = 0;
    _frame.v25 = qword_102EAC;
    v16 = 2;
  }
  v17 = (volatile char *)&_frame.v25 + 4;
  v18 = dword_102EA8;
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


// peripheral_read_32 @ 0x102eb8
/* luna: Copies 32-bit words from the supplied source address into the mode-selected mapped window, applying the mode-specific slot stride and wakeup signaling */
int peripheral_read_32(int a1, int a2, unsigned int a3, int a4) {
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
    v6 = 16 * (dword_102F48 + a2);
    v7 = 4;
    v8 = 3;
  }
  else
  {
    v6 = 32 * (dword_102F40 + a2);
    v7 = 8;
    v8 = 5;
  }
  while ( !*(volatile uint32_t *)off_102F44 )
    ;
  set_wakeup_trigger(a1);
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
  result = set_wakeup_polarity(a1);
  *(volatile uint32_t *)off_102F44 = 1;
  return result;
}



// call_transfer @ 0x102f4c
/* luna: Reads 16-byte peripheral blocks at offsets 0x20, 0x30, and 0x40 into configured destination buffers, returning the final read status. */
int call_transfer() {
  uint64_t v0; // kr00_8
  int v1; // r4

  v0 = *(volatile uint64_t *)((volatile char *)off_102F7C + 4);
  v1 = *(volatile uint32_t *)off_102F7C;
  peripheral_read_32(0, 32, 0x10u, SHIDWORD(v0));
  peripheral_read_32(0, 48, 0x10u, v0);
  return peripheral_read_32(0, 64, 0x10u, v1);
}



// is_radio_busy @ 0x102f80
/* luna: Initializes radio control registers and hardware state when the initialization flag is clear, otherwise sets a radio control bit. */
int is_radio_busy() {
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

  if ( *((volatile uint8_t *)off_103198 + 2) )
  {
    *(volatile uint32_t *)off_1031E4 = *(volatile uint32_t *)off_1031E4 & 0xFFFFF3FF | 0x800;
  }
  else
  {
    v0 = (void *)(uintptr_t)(off_10319C);
    v1 = (void *)(uintptr_t)(off_1031A0);
    *(volatile uint8_t *)off_10319C = 80;
    v0[1] = 78;
    while ( !*v1 )
      ;
    v2 = (void *)(uintptr_t)(off_1031A8);
    *(volatile uint32_t *)off_1031A4 &= ~2u;
    if ( (*v2 & 1) == 0 )
    {
      rng_read(1);
      v20 = (void *)(uintptr_t)(off_1031FC);
      *(volatile uint32_t *)off_1031F8 = *(volatile uint32_t *)off_1031F8 & 0xFFFFFFF0 | 4;
      *v20 |= 2u;
    }
    v3 = (volatile unsigned int *)off_1031AC;
    v4 = (volatile unsigned int *)off_1031B0;
    v5 = (volatile unsigned int *)off_1031B4;
    v6 = (void *)(uintptr_t)(off_1031B8);
    v7 = (volatile uint8_t *)off_1031BC;
    *(volatile uint32_t *)off_1031A0 = 1;
    *v3 = *v3 & 0xFF0FFFFF | 0xC00000;
    *v3 = *v3 & 0xFFFFFF0F | 0x60;
    *v4 &= ~1u;
    *v5 = *v5 & 0xFFFFE0FF | 0x1000;
    *v6 |= 8u;
    *v6 &= 0xFFFFFFFC;
    *(volatile unsigned int *)((volatile char *)v3 + 0xFFFFFFB8) &= ~0x40000u;
    *v6 &= ~4u;
    v8 = (void *)(uintptr_t)(off_1031C0);
    *v4 = *v4 & 0xFFFFF3FF | 0x800;
    *(volatile unsigned int *)((volatile char *)v5 + 0xFFFFFF94) &= 0xFFFF3FFF;
    *(v3 - 1996) = *(v3 - 1996) & 0xFFFFFF | 0x10000000;
    v4 -= 2045;
    *v8 = *v8 & 0xFFFC00FF | (*v7 << 8);
    v9 = (void *)(uintptr_t)(off_1031C4);
    v5 -= 2072;
    *v4 |= 0x80000000;
    *v5 |= 0x1000u;
    *v8 &= ~0x40000u;
    *v4 &= ~0x40000000u;
    v10 = (void *)(uintptr_t)(off_1031C8);
    *v9 &= ~2u;
    *v9 |= 1u;
    v8 += 2062;
    v5[2083] = 20058;
    *v8 = *v8 & 0x3FFFFFF | 0x7C000000;
    *v8 = *v8 & 0xFC07FFFF | 0x3E00000;
    if ( (*v10 & 0x20) != 0 )
    {
      v17 = (void *)(uintptr_t)(off_1031EC);
      *((volatile uint8_t *)off_1031CC + 1) = 1;
      v18 = (void *)(uintptr_t)(off_1031F0);
      v19 = (volatile unsigned int *)off_1031F4;
      *v17 &= 0xFFF0FFFF;
      *v17 &= 0xFF0FFFFF;
      *v18 &= ~0x8000u;
      *v19 = *v19 & 0xFFFFFC7F | 0x200;
    }
    else
    {
      *((volatile uint8_t *)off_1031CC + 1) = 0;
    }
    v11 = (volatile unsigned int *)off_1031D0;
    v12 = (volatile uint8_t *)off_1031D4;
    v13 = (void *)(uintptr_t)(off_1031D8);
    *(volatile uint32_t *)off_1031D0 = *(volatile uint32_t *)off_1031D0 & 0x3FFFFFF | 0xA0000000;
    result = v12[362];
    *v11 = *v11 & 0xFC0FFFFF | 0x1800000;
    *v13 |= 0x10u;
    if ( result )
      *(v11 - 8824) = *(v11 - 8824) & 0xFFFFFFC0 | 0x2C;
    v15 = (volatile unsigned int *)off_1031E0;
    *(volatile uint32_t *)off_1031DC &= 0xFFFFFFC7;
    *v15 = *v15 & 0xFFFFFFFC | 2;
  }
  v16 = (void *)(uintptr_t)(off_1031E8);
  *(volatile uint32_t *)off_1031E8 |= 0xC000u;
  *v16 |= 0x30000u;
  return result;
}



// get_radio_state @ 0x103200
/* luna: Applies the requested radio state by setting or clearing control-register bit 1 and conditionally issuing the matching PHY configuration command. */
unsigned int get_radio_state(unsigned int result) {
  if ( result )
  {
    if ( *((volatile uint8_t *)off_103250 + 362) )
      result = write_phy_config(0xB5u);
    *(volatile uint32_t *)off_103254 |= 2u;
  }
  else
  {
    if ( *((volatile uint8_t *)off_103250 + 362) )
      result = write_phy_config(0xC2u);
    *(volatile uint32_t *)off_103254 &= ~2u;
  }
  return result;
}



// load_and_store_block @ 0x103258
/* luna: Calculates and stores two radio divider values from the selected mode, table entry, and configuration bytes, then returns the associated parameter blo */
volatile uint32_t *load_and_store_block() {
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
  v0 = *(volatile uint32_t *)(dword_1032C8 + 4);
  v1 = *(volatile uint32_t *)(dword_1032C8 + 8);
  v2 = *(volatile uint32_t *)(dword_1032C8 + 12);
  _frame.v11 = *(volatile uint32_t *)dword_1032C8;
  _frame.v12 = v0;
  _frame.v13 = v1;
  _frame.v14 = v2;
  if ( (*((volatile uint32_t *)off_1032CC + 4) & 2) != 0 )
  {
    v3 = dword_1032D4;
    v4 = &_frame.v15[*((volatile uint32_t *)off_1032CC + 9) & 0xF];
    v5 = (char)*(v4 - 16);
    v6 = (uint8_t)*(v4 - 16);
    if ( (*((volatile uint32_t *)off_1032CC + 4) & 4) == 0 )
      v3 = dword_1032D0;
    if ( v5 < 0 )
    {
      v3 *= 2;
      v6 &= 0x7Fu;
    }
    v7 = v3 / v6;
  }
  else
  {
    v7 = 2 * *(volatile uint32_t *)off_1032E4;
  }
  result = (void *)(uintptr_t)(off_1032DC);
  v9 = (volatile unsigned int *)off_1032E0;
  v10 = v7 / (uint8_t)*((volatile uint32_t *)off_1032CC + 8);
  *(volatile uint32_t *)off_1032D8 = v10;
  *v9 = v10 / (uint8_t)result[9];
  return result;
}



// get_controller_state @ 0x1032e8
/* luna: Busy-waits until the hardware timer advances by the requested number of ticks, then returns that interval. */
unsigned int get_controller_state(unsigned int result) {
  volatile unsigned int start_count; // r1
  unsigned int elapsed_ticks; // r3

  start_count = (*(volatile uint32_t *)0x40501010u);
  do
    elapsed_ticks = (*(volatile uint32_t *)0x40501010u) - start_count;
  while ( elapsed_ticks < result );
  return result;
}


// enable_radio_controller @ 0x1032fc
/* luna: Sweeps the MDLL feedback control to derive a duty setting and stores the result for the selected clock mode. */
int enable_radio_controller(int a1) {
  volatile uint32_t *mdll_control_reg; // r6
  volatile uint32_t *mdll_trigger_reg; // r5
  int previous_feedback_state; // r7
  int calibration_pass; // r8
  uint16_t duty_sum; // r11
  unsigned int sweep_value; // r2
  int sweep_step; // r10
  unsigned int measured_duty; // r3
  int sample_count; // r0
  unsigned int v10; // r12
  int v11; // r1
  unsigned int v12; // r12
  int v13; // r1
  int v14; // r12
  int v15; // r1
  int v16; // r7
  uint16_t v17; // r9
  int16_t v18; // r2
  uint8_t stored_duty_setting; // r4
  int result; // r0
  unsigned int v21; // [sp+0h] [bp-Ch]

  mdll_control_reg = (volatile uint32_t *)dword_103460;
  mdll_trigger_reg = (volatile uint32_t *)dword_103464;
  *(volatile uint32_t *)dword_103460 |= 0x10u;
  previous_feedback_state = 0;
  calibration_pass = 0;
  *mdll_trigger_reg = *mdll_trigger_reg & 0xFFFFC0FF | 0x300;
  duty_sum = 0;
  sweep_value = 64;
  while ( 2 )
  {
    *mdll_control_reg = *mdll_control_reg & 0xFFFFFDFF | (calibration_pass << 9);
    sweep_step = (sweep_step & ~0xFFFFu) | ((uint16_t)(10) & 0xFFFFu);
    do
    {
      *mdll_control_reg = *mdll_control_reg & 0xFFFE03FF | (sweep_value << 10);
      measured_duty = (uint8_t)sweep_value;
      sample_count = 0;
      while ( 1 )
      {
        *mdll_trigger_reg |= 0x4000u;
        v10 = REG_4032_0120 + 5;
        do
          v11 = REG_4032_0120 - v10;
        while ( v11 < 0 );
        *mdll_trigger_reg &= ~0x4000u;
        v12 = REG_4032_0120 + 5;
        do
          v13 = REG_4032_0120 - v12;
        while ( v13 < 0 );
        v14 = (*mdll_control_reg >> 3) & 1;
        if ( sample_count )
        {
          if ( v14 != previous_feedback_state )
            break;
        }
        if ( calibration_pass )
          v15 = (*mdll_control_reg >> 3) & 1;
        else
          v15 = (*mdll_control_reg & 8) == 0;
        if ( v15 )
        {
          if ( measured_duty )
          {
            measured_duty = (uint8_t)(measured_duty - 1);
            v16 = (measured_duty << 10) & 0x1FC00;
          }
          else
          {
            v16 = 0;
          }
        }
        else
        {
          if ( measured_duty <= 0x7E )
            measured_duty = (uint8_t)(measured_duty + 1);
          v16 = (measured_duty << 10) & 0x1FC00;
        }
        sample_count = (uint8_t)(sample_count + 1);
        *mdll_control_reg = *mdll_control_reg & 0xFFFE03FF | v16;
        if ( sample_count == 128 )
        {
          previous_feedback_state = v14;
          break;
        }
        previous_feedback_state = v14;
      }
      v21 = measured_duty;
      v17 = measured_duty;
      duty_sum += measured_duty;
      check_status_bits(0x2000, "%x -> %x\n", sweep_value, measured_duty);
      if ( v21 <= 0x40 )
        v18 = v17 - sweep_step;
      else
        v18 = v17 + sweep_step;
      sweep_step = (uint16_t)(sweep_step - 20);
      sweep_value = __usat(7u, v18);
    }
    while ( sweep_step != 65506 );
    if ( !calibration_pass )
    {
      calibration_pass = 1;
      continue;
    }
    break;
  }
  *(volatile uint32_t *)dword_103460 = ((duty_sum + 2) << 8) & 0x1FC00 | *(volatile uint32_t *)dword_103460 & 0xFFFE03FF;
  stored_duty_setting = ((unsigned int)duty_sum + 2) >> 2;
  result = log_printf("%dM mdll duty: %x\n", 40 * a1 + 280, stored_duty_setting);
  if ( a1 )
    *(volatile uint8_t *)(dword_103474 + 1) = stored_duty_setting;
  else
    *(volatile uint8_t *)dword_103474 = stored_duty_setting;
  return result;
}


// init_radio_hw @ 0x103478
/* luna: Initializes radio-controller registers, waits for a status condition, and invokes the GPIO initialization sequence. */
int init_radio_hw() {
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
  v0 = (void *)(uintptr_t)(off_1035E0);
  *((volatile uint32_t *)off_1035DC + 64) = 8;
  if ( !v0[2] )
    *((volatile uint32_t *)off_1035E4 + 2) = *((volatile uint32_t *)off_1035E4 + 2) & 0xFFF9FFFF | 0x20000;
  v1 = (volatile int *)off_1035E4;
  while ( (*((volatile uint32_t *)off_1035E4 + 12) & 0x22) != 2 )
    ;
  v2 = (void *)(uintptr_t)(off_1035E8);
  v3 = dword_1035EC;
  v4 = (void *)(uintptr_t)(off_1035DC);
  *((volatile uint32_t *)off_1035E4 + 2) = *((volatile uint32_t *)off_1035E4 + 2) & 0xFFFE73FE | 0x18401;
  *v2 = 6;
  v1[21] = v1[21] & 0x37F | 0x80 | v1[21] & v3;
  v4[81] = 16;
  v5 = (volatile uint8_t **)off_1035F0;
  *v1 = *v1 & 0x37F | 0x80 | *v1 & v3;
  if ( **v5 == 1 )
  {
    *v1 = *v1 & 0x3F7 | 8 | *v1 & v3;
    v1[21] = v3 & v1[21] | v1[21] & 0x3F7 | 8;
  }
  gpio_init_sequence();
  v6 = (void *)(uintptr_t)(off_1035E4);
  v7 = dword_1035EC;
  v8 = (void *)(uintptr_t)(off_1035DC);
  v9 = (volatile int *)off_103600;
  *(volatile uint32_t *)off_1035E4 = *(volatile uint32_t *)off_1035E4 & 0x3EF | 0x10 | *(volatile uint32_t *)off_1035E4 & dword_1035EC;
  v6[21] = v6[21] & 0x3EF | 0x10 | v6[21] & v7;
  v8[22] &= 0xFFFFFFC1;
  v10 = *((volatile uint8_t *)v9 + 177);
  v8[22] |= 0x26u;
  if ( v10 && (v6[12] & 0x40) == 0 && (v6[12] & 4) != 0 )
  {
    v53 = (volatile int *)off_103B38;
    v54 = v9[42] | 0x2000000;
    *(volatile uint8_t *)off_103B34 = 1;
    *v53 = v54;
    v8[14] |= 0x10u;
  }
  else
  {
    *(volatile uint32_t *)off_1035F4 = v9[42];
  }
  if ( v0[2] )
  {
    if ( **(volatile uint8_t **)off_1035F8 == 2 )
    {
      v60 = (void *)(uintptr_t)(off_103B48);
      v61 = (void *)(uintptr_t)(off_103B4C);
      *((volatile uint32_t *)off_103B48 + 20) |= 0x40000u;
      v61[7] &= ~0x100u;
      v60[9] = v60[9] & 0xFFFFFF00 | 0x60;
      v60[9] = v60[9] & 0xFFFF00FF | 0xDF00;
LABEL_13:
      irq_install_handler();
      mmio_set_control_bit_25();
      if ( !*(volatile uint32_t *)off_1035FC )
        goto LABEL_17;
      goto LABEL_14;
    }
    v11 = (void *)(uintptr_t)(off_1035E4);
    **(volatile uint8_t **)off_1035F8 = 2;
    v12 = (void *)(uintptr_t)(off_1035DC);
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
    v14 = (void *)(uintptr_t)(off_103914);
    v15 = (void *)(uintptr_t)(off_103918);
    *((volatile uint32_t *)off_103914 + 20) |= 0x40000u;
    v15[7] &= ~0x100u;
    v14[9] = v14[9] & 0xFFFFFF00 | 0x60;
    v14[9] = v14[9] & 0xFFFF00FF | 0xDF00;
  }
  rf_get_lock_status();
  mmio_set_control_bit_25();
  if ( *(volatile uint32_t *)off_10391C )
  {
LABEL_14:
    rf_enable_1();
    rf_event_handler_alt();
    rf_event_handler();
  }
LABEL_17:
  v16 = (void *)(uintptr_t)(off_103918);
  is_radio_busy();
  v16[4] |= 2u;
  load_and_store_block();
  if ( (*v16 & 0x2000000) != 0 )
  {
    v17 = (void *)(uintptr_t)(off_103920);
    v18 = (volatile char *)off_103924;
    v19 = 1;
    for ( i = 0; i != 3; ++i )
    {
      v21 = copy_global_1672ec(i, *v17 + 3 * i);
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
        if ( rf_cmd_a_write(j, _frame.a2) <= 1 )
        {
          v52 = _frame.a2[0];
          *(volatile uint8_t *)(*v17 + j) = _frame.a2[0];
          *(volatile uint8_t *)(*v17 + j + 3) = v52;
          *(volatile uint8_t *)(*v17 + j + 6) = v52;
        }
      }
    }
    v22 = (void *)(uintptr_t)(off_103928);
    v23 = dword_10397C;
    v24 = 1;
    for ( k = 0; k != 3; ++k )
    {
      v26 = copy_global_1672f8(k, *v22 + 6 * k);
      if ( v26 != v23 )
      {
        v18[1] |= 1u;
        v24 = 0;
      }
    }
    if ( v24 )
    {
      v27 = 0;
      v28 = dword_103980;
      _frame.a2[0] = 0;
      v29 = 2;
      v30 = 4;
      do
      {
        v31 = (unsigned int)v28 * (uint64_t)(unsigned int)(2 * v27);
        v32 = v30 == HIDWORD(v31) >> 1;
        v30 = HIDWORD(v31) >> 1;
        if ( !v32 )
          v29 = rf_cmd_b_write(HIDWORD(v31) >> 1, _frame.a2);
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
    v35 = 31 - __clz(call_hook_27());
    *v18 = v35;
  }
  else
  {
    memset((void *)(_frame.v82), 0, sizeof(_frame.v82));
    v55 = ke_event_send_4((int)_frame.v82);
    if ( v55 )
    {
      v18 = (volatile char *)off_103B3C;
    }
    else
    {
      v73 = (void *)(uintptr_t)(off_103B64);
      log_printf(aFlTxpwrOfst24g);
      v74 = _frame.v82;
      do
      {
        log_printf("\r\n  [%d] =", v55);
        v75 = 3 * v55;
        v76 = (volatile char *)v74;
        for ( m = 0; m != 3; ++m )
        {
          v78 = *v76++;
          *(volatile uint8_t *)(*v73 + v75 + m) = v78;
          v79 = *(volatile char *)(*v73 + v75 + m);
          log_printf(" %d", v79);
        }
        ++v55;
        v74 = (volatile uint32_t *)((volatile char *)v74 + 3);
      }
      while ( v55 != 3 );
      v18 = (volatile char *)off_103B3C;
      log_printf((const volatile char *)off_103B5C);
      v18[1] |= 1u;
    }
    memset((void *)(_frame.a2), 0, 20);
    if ( !ke_event_send_0x20((int)_frame.a2) )
    {
      v65 = (void *)(uintptr_t)(off_103B50);
      log_printf(aFlTxpwrOfst5g);
      v66 = 0;
      _frame.v80 = v18;
      v67 = v65;
      v68 = _frame.a2;
      do
      {
        log_printf("\r\n  [%d] =", v66);
        v69 = v68;
        for ( n = 0; n != 6; ++n )
        {
          v71 = *v69++;
          *(volatile uint8_t *)(*v67 + n + 6 * v66) = v71;
          v72 = *v67 + n;
          log_printf(" %d", *(volatile char *)(v72 + 6 * v66));
        }
        ++v66;
        v68 += 6;
      }
      while ( v66 != 3 );
      v18 = _frame.v80;
      log_printf((const volatile char *)off_103B5C);
      _frame.v80[1] |= 1u;
    }
    if ( ke_task_handler_short((int)_frame.v81) )
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
  log_printf("cal_ver=%d\n", v35);
  if ( *((volatile uint8_t *)v9 + 372) )
  {
    if ( (*(volatile uint32_t *)off_103918 & 0x2000000) != 0 )
    {
      if ( get_hook_bit_18() )
      {
        v57 = get_hook_bits_0_2();
        v58 = (volatile int *)off_103B40;
        v59 = (void *)(uintptr_t)(off_103B44);
        *(volatile uint8_t *)off_103B44 = *((volatile uint8_t *)off_103B40 + v57);
        v59[1] = *((volatile uint8_t *)v58 + get_hook_bits_3_5());
        v59[2] = *((volatile uint8_t *)v58 + get_hook_bits_6_8());
      }
    }
    else
    {
      *(volatile uint32_t *)_frame.a2 = 0;
      if ( !ke_event_send_0x40((int)_frame.a2) )
      {
        v62 = (void *)(uintptr_t)(off_103B44);
        v63 = *((volatile uint8_t *)off_103B40 + _frame.a2[1]);
        v64 = *((volatile uint8_t *)off_103B40 + _frame.a2[2]);
        *(volatile uint8_t *)off_103B44 = *((volatile uint8_t *)off_103B40 + _frame.a2[0]);
        v62[1] = v63;
        v62[2] = v64;
      }
    }
  }
  v36 = off_103934;
  v37 = (volatile int *)((volatile uint32_t *)(uintptr_t)&off_103938)[0];
  *(volatile uint32_t *)off_103930 &= 0xFFFFFFC7;
  peripheral_read_32(0, 0, 0x10u, v36);
  peripheral_read_32(0, 16, 0x10u, off_10393C);
  peripheral_read_32(0, 32, 0x10u, v37[2]);
  peripheral_read_32(0, 48, 0x10u, v37[1]);
  peripheral_read_32(0, 64, 0x10u, *v37);
  peripheral_read_32(1, 0, 0x10u, *(volatile uint32_t *)off_103940);
  peripheral_read_32(1, 16, 0x10u, ((volatile uint32_t *)(uintptr_t)off_103944)[0]);
  rng_read_alt();
  enable_radio_controller(1);
  rng_read(0);
  enable_radio_controller(0);
  if ( (v9[98] & 4) != 0 )
  {
    v38 = (volatile int *)off_103948;
    v39 = dword_10394C;
    v40 = dword_103950;
    ((volatile uint32_t *)(uintptr_t)off_103948)[13] = dword_10394C;
    v38[14] = v40;
    --v39;
    v40 -= 10;
    v38[109] = v39;
    v38[110] = v40;
    v39 += 2;
    v40 -= 8;
    v41 = (volatile int *)off_103954;
    v38[204] = v39;
    v38[205] = v40;
    v39 += 33;
    v40 += 41;
    v42 = dword_103958;
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
  v44 = (void *)(uintptr_t)(off_103960);
  *(volatile uint32_t *)off_10395C |= 0x8000000u;
  v45 = rf_get_bandwidth();
  v46 = ((int)(((uint64_t)((int32_t)dword_103964 * (int64_t)(int32_t)(4 * (v45 - 35))) >> 32) + 4 * (v45 - 35)) >> 2)
      - ((4 * (v45 - 35)) >> 31)
      + 120;
  *(volatile uint16_t *)off_103984 = v46;
  *v44 = v46;
  event_dispatch("Init T=%d C, ipa_target=%d\n", v45, v46);
  v47 = rf_hardware_init((int)_frame.a2);
  log_printf("cal_ipa_5g offset=%d, cgm=%d\n", v47, *(volatile uint32_t *)_frame.a2);
  if ( (v18[1] & 1) != 0 && *v18 < 0 )
  {
    v48 = (volatile unsigned int *)off_103974;
    *(volatile uint32_t *)off_103970 = *(volatile uint32_t *)off_103970 & 0xFFFFFF87 | 0x40;
    *v48 = *v48 & 0xFFF87FFF | 0x40000;
  }
  v49 = rf_hardware_setup();
  return log_printf("cal_ipa_24g offset=%d\n", v49);
}


// enable_pa @ 0x103b6c
/* luna: Enables the Wi-Fi DFE and RF interface, waits for hardware-ready bits, and checks status bit 0x2000. */
int enable_pa() {
  volatile uint32_t *v0; // r2
  int v1; // r3
  volatile uint32_t *v2; // r3
  volatile uint32_t *v3; // r2
  int v4; // r3
  volatile uint32_t *v5; // r3
  volatile uint32_t *v6; // r0

  v0 = (void *)(uintptr_t)(off_103BFC);
  *(volatile uint32_t *)off_103BF8 |= 1u;
  while ( (*v0 & 0x10) == 0 )
  {
    v1 = (v1 & ~0xFFFFu) | ((uint16_t)(50) & 0xFFFFu);
    do
      v1 = (uint16_t)(v1 - 1);
    while ( v1 );
  }
  v2 = (void *)(uintptr_t)(off_103C00);
  v3 = (void *)(uintptr_t)(off_103BFC);
  *(volatile uint32_t *)off_103C00 |= 0x80000u;
  *v2 |= 0x100000u;
  while ( (*v3 & 8) == 0 )
  {
    v4 = (v4 & ~0xFFFFu) | ((uint16_t)(50) & 0xFFFFu);
    do
      v4 = (uint16_t)(v4 - 1);
    while ( v4 );
  }
  v5 = (void *)(uintptr_t)(off_103C08);
  v6 = (void *)(uintptr_t)(off_103C0C);
  *(volatile uint32_t *)off_103C04 |= 0x20000u;
  *v5 |= 0x1000000u;
  *v5 |= 0x8000000u;
  *v6 |= 0x524u;
  return check_status_bits(0x2000, aWfDfeAndRfintf);
}


// configure_gpio_bits @ 0x103c14
/* luna: Clears selected GPIO and control-register bits, waits 10 timer units, then checks status bit 0x2000. */
int configure_gpio_bits() {
  volatile uint32_t *v0; // r0
  volatile uint32_t *v1; // r1
  volatile uint32_t *v2; // r2

  v0 = (void *)(uintptr_t)(off_103C5C);
  v1 = (void *)(uintptr_t)(off_103C60);
  v2 = (void *)(uintptr_t)(off_103C64);
  *(volatile uint32_t *)off_103C58 &= 0xFFFFFA53;
  *v0 &= ~0x20000u;
  *v1 &= ~0x1000000u;
  *v2 &= 0xFFE7FFFF;
  timer_delay(10);
  return check_status_bits(0x2000, aWfDfeAndRfintf_0);
}


// clear_chip_ctrl_clk @ 0x103c6c
/* luna: Cycles two chip-control clock bits with short delays between transitions. */
int clear_chip_ctrl_clk() {
  volatile uint32_t *v0; // r4
  int result; // r0

  v0 = (void *)(uintptr_t)(off_103CA0);
  *(volatile uint32_t *)off_103CA0 &= ~0x400000u;
  *v0 &= ~0x200000u;
  timer_delay(2);
  *v0 |= 0x200000u;
  result = timer_delay(2);
  *v0 |= 0x400000u;
  return result;
}



// pmu_write_control @ 0x103ca4
/* luna: Selects an RF diagnostic dump source and programs the corresponding hardware debug-routing controls. */
int pmu_write_control(int a1) {
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

  *(volatile uint32_t *)off_103E94 = dword_103E98;
  if ( a1 )
  {
    switch ( a1 )
    {
      case 1:
        v11 = (volatile unsigned int *)off_103E9C;
        v12 = (volatile int *)off_103EA0;
        v13 = dword_103EC8;
        v14 = *(volatile uint32_t *)off_103E9C;
        v15 = aDumpDac150m;
        v16 = *(volatile uint32_t *)off_103E9C & 0x70 | 1;
        break;
      case 10:
        v1 = (volatile unsigned int *)off_103E9C;
        v2 = (volatile int *)off_103EA0;
        v3 = *(volatile uint32_t *)off_103E9C;
        v4 = dword_103EC0;
        v5 = *(volatile uint32_t *)off_103E9C;
        v6 = aDumpDpdTxRx;
        goto LABEL_24;
      case 14:
        v1 = (volatile unsigned int *)off_103E9C;
        v2 = (volatile int *)off_103EA0;
        v3 = *(volatile uint32_t *)off_103E9C;
        v4 = dword_103ED0;
        v5 = *(volatile uint32_t *)off_103E9C;
        v6 = aDumpLoftOut;
        goto LABEL_24;
      case 2:
        v11 = (volatile unsigned int *)off_103E9C;
        v12 = (volatile int *)off_103EA0;
        v13 = dword_103ED8;
        v14 = *(volatile uint32_t *)off_103E9C;
        v15 = aDumpAdcIn;
        v16 = *(volatile uint32_t *)off_103E9C & 0x70 | 2;
        break;
      default:
        switch ( a1 )
        {
          case 3:
            v1 = (volatile unsigned int *)off_103E9C;
            v2 = (volatile int *)off_103EA0;
            v3 = *(volatile uint32_t *)off_103E9C;
            v4 = dword_103EE0;
            v5 = *(volatile uint32_t *)off_103E9C;
            v6 = aDumpRxDataIq;
            break;
          case 30:
            v1 = (volatile unsigned int *)off_103E9C;
            v2 = (volatile int *)off_103EA0;
            v3 = *(volatile uint32_t *)off_103E9C;
            v4 = dword_103EE8;
            v5 = *(volatile uint32_t *)off_103E9C;
            v6 = aDumpRcAdcIq;
            break;
          case 31:
            v1 = (volatile unsigned int *)off_103E9C;
            v2 = (volatile int *)off_103EA0;
            v3 = *(volatile uint32_t *)off_103E9C;
            v4 = dword_103EF8;
            v5 = *(volatile uint32_t *)off_103E9C;
            v6 = aDumpDccancelOu;
            break;
          case 32:
            v1 = (volatile unsigned int *)off_103E9C;
            v2 = (volatile int *)off_103EA0;
            v3 = *(volatile uint32_t *)off_103E9C;
            v4 = dword_103F00;
            v5 = *(volatile uint32_t *)off_103E9C;
            v6 = aDumpPreDgcOutI;
            break;
          case 33:
            v1 = (volatile unsigned int *)off_103E9C;
            v2 = (volatile int *)off_103EA0;
            v3 = *(volatile uint32_t *)off_103E9C;
            v4 = dword_103F08;
            v5 = *(volatile uint32_t *)off_103E9C;
            v6 = aDumpNotchOutIq;
            break;
          default:
            if ( a1 != 4 )
            {
              if ( a1 == 5 )
              {
                v1 = (volatile unsigned int *)off_103E9C;
                v2 = (volatile int *)off_103EA0;
                v3 = *(volatile uint32_t *)off_103E9C;
                v4 = dword_103F10;
                v5 = *(volatile uint32_t *)off_103E9C;
                v6 = aDumpRcOutIq;
                break;
              }
              if ( a1 != 50 )
              {
                switch ( a1 )
                {
                  case 6:
                    v1 = (volatile unsigned int *)off_103E9C;
                    v2 = (volatile int *)off_103EA0;
                    v3 = *(volatile uint32_t *)off_103E9C;
                    v4 = dword_103F18;
                    v5 = *(volatile uint32_t *)off_103E9C;
                    v6 = aDumpRcStatus;
                    break;
                  case 7:
                    v17 = (volatile unsigned int *)off_103EB0;
                    v18 = (volatile int *)off_103EA0;
                    v19 = dword_103EB4;
                    *(volatile uint32_t *)off_103E9C &= 0xFFFFFF70;
                    *v17 = *v17 & 0xFF00FFFF | 0x540000;
                    *v18 = v19;
                    event_dispatch(aDumpLpfOutBpfO);
                    goto LABEL_22;
                  case 8:
                    v1 = (volatile unsigned int *)off_103E9C;
                    v2 = (volatile int *)off_103EA0;
                    v4 = dword_103EB4;
                    v6 = aDumpGainLoft2I;
                    *(volatile uint32_t *)off_103EB0 = *(volatile uint32_t *)off_103EB0 & 0xFF00FFFF | 0x570000;
                    v3 = *v1;
                    v5 = *v1;
                    break;
                  case 81:
                    v1 = (volatile unsigned int *)off_103E9C;
                    v2 = (volatile int *)off_103EA0;
                    v4 = dword_103EB4;
                    v6 = aDumpGainLoftIn;
                    *(volatile uint32_t *)off_103EB0 = *(volatile uint32_t *)off_103EB0 & 0xFF00FFFF | 0x30000;
                    v3 = *v1;
                    v5 = *v1;
                    break;
                  default:
                    v1 = (volatile unsigned int *)off_103E9C;
                    v2 = (volatile int *)off_103EA0;
                    v3 = *(volatile uint32_t *)off_103E9C;
                    v4 = dword_103EA4;
                    v5 = *(volatile uint32_t *)off_103E9C;
                    if ( a1 == 9 )
                      v6 = aDumpAuxFifoOut;
                    else
                      v6 = aReselectMode;
                    break;
                }
                break;
              }
            }
            v1 = (volatile unsigned int *)off_103E9C;
            v2 = (volatile int *)off_103EA0;
            v3 = *(volatile uint32_t *)off_103E9C;
            v4 = dword_103EF0;
            v5 = *(volatile uint32_t *)off_103E9C;
            v6 = aDumpRcInIq;
            break;
        }
LABEL_24:
        *v1 = v5 & 0xFFFFFF00 | v3 & 0x70;
        *v2 = v4;
        event_dispatch(v6);
        goto LABEL_22;
    }
    *v11 = v16 | v14 & 0xFFFFFF00;
    *v12 = v13;
    event_dispatch(v15);
    goto LABEL_22;
  }
  v7 = (volatile unsigned int *)off_103EB0;
  v8 = (volatile int *)off_103EA0;
  v9 = dword_103EB4;
  *(volatile uint32_t *)off_103E9C &= 0xFFFFFF70;
  *v7 = *v7 & 0xFF00FFFF | 0x770000;
  *v8 = v9;
  event_dispatch(aDumpLoftPwrInO);
LABEL_22:
  *(volatile uint32_t *)off_103EBC = 769;
  return timer_delay(500);
}


// mac_phy_config @ 0x103f2c
/* luna: Waits for the debug end-address value to become nonnegative, clears related state, and emits a request to dump 16 KiB at 0x00100000. */
int mac_phy_config() {
  volatile int *v0; // r4
  volatile int *v1; // r3
  int v2; // r1
  volatile uint32_t *v3; // r2

  v0 = (volatile int *)off_103F88;
  *(volatile uint32_t *)off_103F84 = 777;
  while ( *v0 < 0 )
    timer_delay(1);
  event_dispatch("end_addr=%d\n", *(volatile uint32_t *)off_103F88);
  *(volatile uint32_t *)off_103F84 = 0;
  event_dispatch(aFinish);
  v1 = (volatile int *)off_103F98;
  v2 = dword_103F9C;
  v3 = (void *)(uintptr_t)(off_103FA0);
  *(volatile uint32_t *)off_103F94 = 0;
  *v1 = v2;
  *v3 &= 0xFF00FFFF;
  return event_dispatch("*0* dump    r 00100000 %d**\n", 0x4000);
}


// mac_irq_enable @ 0x103fa8
/* luna: Copies 0x480 bytes from the source image starting at offset 0x30 into the banked MAC memory window, selecting banks 0–2. */
volatile int * mac_irq_enable(int a1) {
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

  v1 = (volatile unsigned int *)off_104024;
  *(volatile uint32_t *)off_104020 |= 0x100u;
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
    v9 = dword_104028 + v3;
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
  *(volatile uint32_t *)off_104020 &= ~0x100u;
  return result;
}



// parse_table_entry @ 0x10402c
/* luna: Initializes the indexed 12-word RF table entry when defaults are enabled, then copies it into the RF memory window while selecting each bank. */
int parse_table_entry(int a1, int a2, int a3) {
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
    v17 = dword_1040F4;
    v16[13] = dword_1040F0;
    v16[14] = v17;
    v18 = dword_1040F8;
    v19 = dword_1040FC;
    v16[12] = dword_104100;
    v16[18] = 0;
    v16[19] = 0;
    v16[20] = 0;
    v16[21] = 0;
    v16[22] = 0;
    v16[23] = 0;
    v16[15] = dword_104104;
    v16[16] = v18;
    v16[17] = v19;
  }
  v4 = 4 * v3;
  v5 = (volatile unsigned int *)off_1040EC;
  v6 = dword_104108;
  *(volatile uint32_t *)off_1040E8 |= 0x100u;
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
  *(volatile uint32_t *)off_1040E8 &= ~0x100u;
  return result;
}



// mac_reset_control @ 0x10410c
/* luna: Runs the MAC reset-control sequence, writes the reset parameter, installs the value in bits 16–20, and restores the auxiliary control bit to its origi */
unsigned int mac_reset_control(int a1, int a2) {
  volatile unsigned int *v2; // r2
  volatile unsigned int *v3; // r3
  int v4; // r4
  volatile uint32_t *v5; // r6
  unsigned int result; // r0

  v2 = (volatile unsigned int *)off_10418C;
  v3 = (volatile unsigned int *)off_104190;
  v4 = *(volatile uint32_t *)off_10418C;
  v5 = (void *)(uintptr_t)(off_104194);
  *(volatile uint32_t *)off_10418C |= 0x1000000u;
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



// mac_hw_init @ 0x104198
/* luna: Initializes WLAN MAC control registers and sequences hardware clock and reset bits with a short delay. */
volatile uint32_t *mac_hw_init() {
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

  v0 = (volatile unsigned int *)off_104270;
  v1 = (volatile unsigned int *)off_104274;
  v2 = (void *)(uintptr_t)(off_104278);
  v3 = (void *)(uintptr_t)(off_10427C);
  v4 = (void *)(uintptr_t)(off_104280);
  v5 = (volatile unsigned int *)off_104284;
  *(volatile uint32_t *)off_104270 &= ~0x200u;
  *v1 = *v1 & 0xFC000FFF | 0x333000;
  *v2 = 8;
  *v3 |= 0x1000000u;
  v0 -= 136;
  *v4 |= 0x2000000u;
  *v0 &= ~0x20000u;
  timer_delay(2);
  v6 = (void *)(uintptr_t)(off_104288);
  result = (void *)(uintptr_t)(off_10428C);
  v8 = (void *)(uintptr_t)(off_104290);
  *v0 |= 0x10000u;
  *v0 |= 0x20000u;
  *v0 = *v0 & 0xFFFF0FFF | 0x6000;
  *v0 |= 0x80000u;
  v9 = dword_104294;
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



// mac_irq_disable @ 0x104298
volatile unsigned int *mac_irq_disable() {
  volatile unsigned int *v0; // r1
  volatile uint32_t *v1; // r0
  volatile unsigned int *v2; // r2
  volatile uint32_t *v3; // r6
  volatile uint32_t *v4; // r5
  volatile uint32_t *v5; // r4
  volatile unsigned int *result; // r0

  v0 = (volatile unsigned int *)off_104374;
  v1 = (void *)(uintptr_t)(off_104378);
  v2 = (volatile unsigned int *)off_10437C;
  *(volatile uint32_t *)off_104374 &= ~0x10000000u;
  v3 = (void *)(uintptr_t)(off_104380);
  v4 = (void *)(uintptr_t)(off_104384);
  v5 = (void *)(uintptr_t)(off_104388);
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



// get_next_sequence @ 0x10438c
/* luna: Returns a wrapped 14-bit sequence value, choosing a one- or two-step base advance from the next entry's low-bit tag and mode flag, then adding twice t */
int get_next_sequence(int a1, int a2, volatile uint32_t *a3) {
  int v3; // r3
  int v4; // r4
  int result; // r0

  v3 = (uint16_t)*(volatile uint32_t *)off_1043D0;
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



// select_fuse_bank @ 0x1043d4
/* luna: Computes the mean signed 12-bit I/Q values across the selected 8192-sample buffer and subtracts those means from the samples in place. */
int select_fuse_bank() {
  BOOL v0; // r1
  int min_i; // r2
  volatile int *iq_sample_buffer; // r4
  int v3; // r7
  volatile int *sample_ptr; // r5
  int v5; // r6
  int max_q; // lr
  int max_i; // r12
  int sum_q; // r9
  int v9; // r8
  int sample_i; // r1
  int sample_q; // r0
  unsigned int packed_sample; // r0
  unsigned int v13; // r3
  int16_t v14; // r2
  int result; // r0
  int v16; // r3

  v0 = (MEMD(0x100000) & 1) == 0;
  min_i = 0;
  iq_sample_buffer = (volatile int *)(4 * (v0 + 0x40000));
  v3 = v0 + 278528;
  sample_ptr = iq_sample_buffer;
  v5 = 4 * (v0 + 278528);
  max_q = 0;
  max_i = 0;
  sum_q = 0;
  v9 = 0;
  do
  {
    sample_i = (unsigned int)*sample_ptr >> 20;
    if ( *sample_ptr < 0 )
      sample_i -= 4096;
    sample_q = (uint16_t)*sample_ptr >> 4;
    if ( (((unsigned int)*sample_ptr >> 4) & 0x800) != 0 )
      sample_q -= 4096;
    if ( max_i < sample_i )
      max_i = sample_i;
    sample_ptr += 2;
    if ( max_q < sample_q )
      max_q = sample_q;
    if ( min_i >= sample_i )
      min_i = sample_i;
    v9 += sample_i;
    sum_q += sample_q;
  }
  while ( sample_ptr != (volatile int *)v5 );
  if ( max_i > 2040 || max_q > 2040 || min_i < -2040 )
    check_status_bits(1, aWarningDataSat);
  check_status_bits(1, "sum_i=%d\nsum_q=%d\ndc_i=%d\ndc_q=%d\n", v9, sum_q, v9 / 0x2000, sum_q / 0x2000);
  do
  {
    packed_sample = *iq_sample_buffer;
    v13 = (unsigned int)*iq_sample_buffer >> 20;
    if ( *iq_sample_buffer < 0 )
      v13 = (v13 & ~0xFFFFu) | ((uint16_t)(v13 - 4096) & 0xFFFFu);
    v14 = (uint16_t)packed_sample >> 4;
    result = packed_sample >> 4 << 20;
    v16 = (int16_t)(v13 - v9 / 0x2000);
    if ( result < 0 )
      v14 -= 4096;
    *iq_sample_buffer = ((v16 + (v16 < 0 ? 0x1000 : 0)) << 20)
        + 65537
        + 16 * ((int16_t)(v14 - sum_q / 0x2000) + ((int16_t)(v14 - sum_q / 0x2000) < 0 ? 0x1000 : 0));
    iq_sample_buffer += 2;
  }
  while ( (volatile int *)(4 * v3) != iq_sample_buffer );
  return result;
}


// start_arm_boot @ 0x1044e0
/* luna: Configures and runs the hardware sequence for a type-3 tone dump, waits for completion, then restores and clears the associated control registers. */
int start_arm_boot() {
  volatile int *v0; // r1
  volatile uint32_t *tone_dump_control_reg; // r3
  int v2; // r0
  int saved_reg_value; // r5
  volatile uint32_t *v4; // r6
  volatile int *end_addr_reg; // r4
  int result; // r0
  volatile uint32_t *v7; // r3
  volatile uint32_t *v8; // r1

  v0 = (volatile int *)off_1045B4;
  tone_dump_control_reg = (void *)(uintptr_t)(off_1045BC);
  v2 = dword_1045C0;
  saved_reg_value = *(volatile uint32_t *)off_1045B8;
  *(volatile uint32_t *)off_1045B8 = dword_1045C4;
  *v0 = v2;
  v4 = (void *)(uintptr_t)(off_1045C8);
  end_addr_reg = (volatile int *)off_1045CC;
  *tone_dump_control_reg = *tone_dump_control_reg & 0xFC000FFF | 0x333000;
  *tone_dump_control_reg &= 0x3FFFFFFFu;
  *tone_dump_control_reg |= 0xC000000u;
  *tone_dump_control_reg = ~(~(*tone_dump_control_reg >> 12) << 12);
  v0[29] = v0[29] & 0xFFFFFF0F | 0xA0;
  *tone_dump_control_reg |= 0x10000000u;
  timer_delay(10);
  *v4 = dword_1045D0;
  timer_delay(125);
  *v4 = dword_1045D4;
  while ( *end_addr_reg < 0 )
    timer_delay(1);
  check_status_bits(1, "end_addr=%x\n", *(volatile uint32_t *)off_1045CC);
  *(volatile uint32_t *)off_1045C8 = 0;
  check_status_bits(1, aDumpFinish);
  *(volatile uint32_t *)off_1045B8 = saved_reg_value;
  select_fuse_bank();
  result = check_status_bits(1, "** dump tone typ3   r 00100000 %d**\n", 0x4000);
  v7 = (void *)(uintptr_t)(off_1045BC);
  v8 = (void *)(uintptr_t)(off_1045E4);
  *(volatile uint32_t *)off_1045BC &= 0xF3FFFFFF;
  *v8 |= 0xF0u;
  *v7 &= ~0x10000000u;
  *v7 &= 0x3FFFFFFFu;
  return result;
}


// lookup_rate_entry @ 0x1045e8
/* luna: Returns the sum of squares of the two signed 12-bit components in the sequence-selected packed word. */
int lookup_rate_entry(int a1, int a2, volatile uint32_t *a3) {
  int v3; // r2
  unsigned int v4; // r0
  int v5; // r3

  v3 = a3[get_next_sequence(a1, a2, a3)];
  v4 = (unsigned int)v3 >> 20;
  v5 = (uint16_t)v3 >> 4;
  if ( v3 < 0 )
    v4 -= 4096;
  if ( (((unsigned int)v3 >> 4) & 0x800) != 0 )
    v5 -= 4096;
  return v5 * v5 + v4 * v4;
}



