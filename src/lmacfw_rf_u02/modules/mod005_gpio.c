// gpio_init_pin_10 @ 0x10dc78
int gpio_init_pin_10() {
  int result; // r0
  volatile uint32_t *v1; // r3

  result = call_slot_0x1b8(dword_10DCA8, 1024, 15360);
  v1 = (void *)(uintptr_t)(off_10DCAC);
  *((volatile uint32_t *)off_10DCAC + 2) |= 0xFu;
  v1[2] |= 0x10000000u;
  v1[3] &= 0xFFFFF7FE;
  return result;
}



// gpio_init_pin_13 @ 0x10dcb0
int gpio_init_pin_13() {
  int result; // r0
  volatile uint32_t *v1; // r3

  result = call_slot_0x1b8(dword_10DCE0, 0x2000, 15360);
  v1 = (void *)(uintptr_t)(off_10DCE4);
  *((volatile uint32_t *)off_10DCE4 + 2) |= 0xFu;
  v1[2] |= 0x10000000u;
  v1[3] &= 0xFFFFF7FE;
  return result;
}



// gpio_init_pin_12 @ 0x10dce8
/* luna: Initializes GPIO pin 12 by calling the shared pin-control helper and then updating GPIO configuration registers to enable the pin function and clear c */
int gpio_init_pin_12() {
  int result; // r0
  volatile uint32_t *gpio_ctrl_base; // r3

  result = call_slot_0x1b8(dword_10DD18, 4096, 15360);
  gpio_ctrl_base = (void *)(uintptr_t)(off_10DD1C);
  *((volatile uint32_t *)off_10DD1C + 2) |= 0xFu;
  gpio_ctrl_base[2] |= 0x10000000u;
  gpio_ctrl_base[3] &= 0xFFFFF7FE;
  return result;
}



// gpio_port_init @ 0x10dd20
unsigned int gpio_port_init() {
  volatile uint32_t *v0; // r0
  volatile uint32_t *v1; // r3
  int v2; // r1
  int v3; // r2
  uint64_t v4; // r0
  uint64_t v5; // r0
  uint64_t v6; // r0
  uint64_t v7; // r0

  v0 = (void *)(uintptr_t)(off_10DDB8);
  v1 = (void *)(uintptr_t)(off_10DDBC);
  v2 = dword_10DDC0;
  v3 = dword_10DDC4;
  *(volatile uint32_t *)off_10DDBC = 0;
  v0[14] = 296;
  v1[2] = v1[2] & 0xF000FFFF | 0x2000000;
  v1[3] = v2 & v1[3] | 0xA06A000;
  v1[3] = v3 & v1[3] | 0x100230;
  v1[1] = 1;
  while ( v1[7] != 1 )
    ;
  v1[7] = 1;
  v4 = aeabi_ui2d(v1[4]);
  v5 = ((uint64_t (*)())aeabi_dadd)(v4, *(volatile uint64_t *)&dword_10DDA0);
  v6 = ((uint64_t (*)())aeabi_dsub)(v5, *(volatile uint64_t *)&dword_10DDA8);
  v7 = ((uint64_t (*)())double_subtract)(v6, *(volatile uint64_t *)&dword_10DDB0);
  return ((int (*)(uint64_t))aeabi_dmul)(v7);
}


// sdio_core_reset @ 0x10ddc8
unsigned int sdio_core_reset(unsigned int result, int a2) {
  volatile uint32_t *v2; // r4
  volatile uint32_t *v3; // r3
  int v4; // r2
  int v5; // r3
  uint64_t v6; // r8
  uint64_t v7; // r6
  volatile unsigned int *v8; // r5
  unsigned int v9; // r10
  uint64_t v10; // r0
  uint64_t v11; // r0
  uint64_t v12; // r0
  uint64_t v13; // r0

  v2 = (void *)(uintptr_t)(off_10DE88);
  v3 = (void *)(uintptr_t)(off_10DE8C);
  v4 = dword_10DE90;
  *(volatile uint32_t *)off_10DE88 = 0;
  v3[14] = 296;
  v5 = dword_10DE94;
  v2[2] = v2[2] & 0xF000FFFF | 0x2000000;
  v2[3] = v4 & v2[3] | 0xA06A000;
  v2[3] = v5 & v2[3] | 0x100230;
  if ( a2 > 0 )
  {
    v6 = *(volatile uint64_t *)&dword_10DE70;
    v7 = *(volatile uint64_t *)&dword_10DE78;
    v8 = (volatile unsigned int *)result;
    v9 = result + 4 * a2;
    do
    {
      v2[1] = 1;
      while ( v2[7] != 1 )
        ;
      v2[7] = 1;
      v10 = aeabi_ui2d(v2[4]);
      v11 = ((uint64_t (*)())aeabi_dadd)(v10, v6);
      v12 = ((uint64_t (*)())aeabi_dsub)(v11, v7);
      v13 = ((uint64_t (*)())double_subtract)(v12, *(volatile uint64_t *)&dword_10DE80);
      result = ((int (*)(uint64_t))aeabi_dmul)(v13);
      *v8++ = result;
    }
    while ( v8 != (volatile unsigned int *)v9 );
  }
  return result;
}


// sdio_core_reset_alt @ 0x10de98
int sdio_core_reset_alt() {
  volatile uint32_t *v0; // r3
  volatile uint32_t *v1; // r0
  int v2; // r1
  int v3; // r2
  int result; // r0

  v0 = (void *)(uintptr_t)(off_10DEE0);
  v1 = (void *)(uintptr_t)(off_10DEE4);
  v2 = dword_10DEE8;
  v3 = dword_10DEEC;
  *(volatile uint32_t *)off_10DEE0 = 0;
  v1[14] = 296;
  v0[2] = v0[2] & 0xF000FFFF | 0x2000000;
  result = v0[3];
  v0[3] = v2 & result | 0xA06A000;
  v0[3] = v3 & v0[3] | 0x100230;
  v0[1] = 1;
  return result;
}



// wait_sdio_core_ready @ 0x10def0
unsigned int wait_sdio_core_ready() {
  volatile uint32_t *v0; // r3
  uint64_t v1; // r0
  uint64_t v2; // r0
  uint64_t v3; // r0
  uint64_t v4; // r0

  while ( *((volatile uint32_t *)off_10DF50 + 7) != 1 )
    ;
  v0 = (void *)(uintptr_t)(off_10DF50);
  *((volatile uint32_t *)off_10DF50 + 7) = 1;
  v1 = aeabi_ui2d(v0[4]);
  v2 = ((uint64_t (*)())aeabi_dadd)(v1, *(volatile uint64_t *)&dword_10DF38);
  v3 = ((uint64_t (*)())aeabi_dsub)(v2, *(volatile uint64_t *)&dword_10DF40);
  v4 = ((uint64_t (*)())double_subtract)(v3, *(volatile uint64_t *)&dword_10DF48);
  return ((int (*)(uint64_t))aeabi_dmul)(v4);
}


// sdio_core_config_0 @ 0x10df54
float sdio_core_config_0() {
  volatile uint32_t *v0; // r4
  volatile uint32_t *v1; // r2
  int v2; // r3
  int v3; // r0
  int v4; // r1
  unsigned int v5; // r4

  v0 = (void *)(uintptr_t)(off_10DFE8);
  v1 = (void *)(uintptr_t)(off_10DFEC);
  v2 = dword_10DFF0;
  v3 = dword_10DFF4;
  v4 = dword_10DFF8;
  *(volatile uint32_t *)off_10DFE8 = 0;
  v1[14] = 296;
  v0[2] = v0[2] & 0xF000FFFF | 0x2000000;
  v0[3] = v2 & v0[3] | 0xA06A000;
  v0[3] = v4 | v3 & v0[3];
  gpio_init_pin_13();
  v0[1] = 1;
  while ( v0[7] != 1 )
    ;
  v0[7] = 1;
  v5 = v0[4];
  call_slot_0x1b8(dword_10DFFC, 0, 15360);
  return (float)((float)((float)((float)v5 / flt_10E000) - 1.0) * flt_10E004) * 5.5;
}



// sdio_core_config_1 @ 0x10e008
float sdio_core_config_1() {
  volatile uint32_t *v0; // r4
  volatile uint32_t *v1; // r2
  int v2; // r3
  int v3; // r0
  int v4; // r1
  unsigned int v5; // r4

  v0 = (void *)(uintptr_t)(off_10E098);
  v1 = (void *)(uintptr_t)(off_10E09C);
  v2 = dword_10E0A0;
  v3 = dword_10E0A4;
  v4 = dword_10E0A8;
  *(volatile uint32_t *)off_10E098 = 0;
  v1[14] = 296;
  v0[2] = v0[2] & 0xF000FFFF | 0x2000000;
  v0[3] = v2 & v0[3] | 0xA06A000;
  v0[3] = v4 | v3 & v0[3];
  gpio_init_pin_11();
  v0[1] = 1;
  while ( v0[7] != 1 )
    ;
  v0[7] = 1;
  v5 = v0[4];
  call_slot_0x1b8(dword_10E0AC, 0, 15360);
  return (float)((float)((float)((float)v5 / flt_10E0B0) - 1.0) * flt_10E0B4)
       + (float)((float)((float)((float)v5 / flt_10E0B0) - 1.0) * flt_10E0B4);
}



// sdio_core_config_2 @ 0x10e0b8
/* luna: Configures SDIO core control registers and GPIO, waits for the core handshake, and returns a converted timing/status value. */
float sdio_core_config_2() {
  volatile uint32_t *sdio_core_regs; // r4
  volatile uint32_t *sdio_config_regs; // r2
  int sdio_reg3_preserve_mask; // r3
  int sdio_reg3_select_mask; // r0
  int sdio_reg3_select_value; // r1
  unsigned int sdio_status_or_counter; // r4

  sdio_core_regs = (void *)(uintptr_t)(off_10E14C);
  sdio_config_regs = (void *)(uintptr_t)(off_10E150);
  sdio_reg3_preserve_mask = dword_10E154;
  sdio_reg3_select_mask = dword_10E158;
  sdio_reg3_select_value = dword_10E15C;
  *(volatile uint32_t *)off_10E14C = 0;
  sdio_config_regs[14] = 296;
  sdio_core_regs[2] = sdio_core_regs[2] & 0xF000FFFF | 0x2000000;
  sdio_core_regs[3] = sdio_reg3_preserve_mask & sdio_core_regs[3] | 0xA06A000;
  sdio_core_regs[3] = sdio_reg3_select_value | sdio_reg3_select_mask & sdio_core_regs[3];
  gpio_init_pin_10();
  sdio_core_regs[1] = 1;
  while ( sdio_core_regs[7] != 1 )
    ;
  sdio_core_regs[7] = 1;
  sdio_status_or_counter = sdio_core_regs[4];
  call_slot_0x1b8(dword_10E160, 0, 15360);
  return (float)((float)((float)((float)sdio_status_or_counter / flt_10E164) - 1.0) * flt_10E168) * flt_10E16C;
}



// sdio_core_config_3 @ 0x10e170
float sdio_core_config_3() {
  volatile uint32_t *v0; // r4
  volatile uint32_t *v1; // r2
  int v2; // r3
  int v3; // r0
  int v4; // r1
  unsigned int v5; // r4

  v0 = (void *)(uintptr_t)(off_10E1FC);
  v1 = (void *)(uintptr_t)(off_10E200);
  v2 = dword_10E204;
  v3 = dword_10E208;
  v4 = dword_10E20C;
  *(volatile uint32_t *)off_10E1FC = 0;
  v1[14] = 296;
  v0[2] = v0[2] & 0xF000FFFF | 0x2000000;
  v0[3] = v2 & v0[3] | 0xA06A000;
  v0[3] = v4 | v3 & v0[3];
  gpio_init_pin_12();
  v0[1] = 1;
  while ( v0[7] != 1 )
    ;
  v0[7] = 1;
  v5 = v0[4];
  call_slot_0x1b8(dword_10E210, 0, 15360);
  return (float)((float)((float)v5 / flt_10E214) - 1.0) * flt_10E218;
}



// sdio_core_init @ 0x10e21c
float sdio_core_init() {
  volatile uint32_t *v0; // r3
  volatile uint32_t *v1; // r1
  int v2; // r2
  int v3; // r5
  int v4; // r4

  v0 = (void *)(uintptr_t)(off_10E2C8);
  v1 = (void *)(uintptr_t)(off_10E2CC);
  v2 = dword_10E2D0;
  *(volatile uint32_t *)off_10E2C8 = 0;
  v1[14] = 296;
  v3 = dword_10E2D4;
  v4 = dword_10E2D8;
  v0[2] = v0[2] & 0xF000FFFF | 0x2000000;
  v0[3] = v2 & v0[3] | 0xA06A000;
  v0[3] = v4 | v3 & v0[3];
  v0[2] = v0[2] & 0xEFFFFFF0 | 0xB;
  v0[3] = v0[3] & 0xFFFFF7FE | 1;
  v0[2] &= ~0x10000000u;
  v0[3] = v0[3] & 0xFFFFF7FE | 1;
  v0[1] = 1;
  while ( v0[7] != 1 )
    ;
  v0[7] = 1;
  return (float)((float)((float)(unsigned int)v0[4] / flt_10E2DC) - 1.0) * flt_10E2E0;
}



// sdio_core_enable @ 0x10e2e8
int sdio_core_enable() {
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

  v0 = (void *)(uintptr_t)(off_10E408);
  check_hw_status(1);
  v0[1] = 1;
  while ( v0[7] != 1 )
    ;
  v0[7] = 1;
  v1 = aeabi_ui2d(v0[4]);
  v2 = ((uint64_t (*)())aeabi_dadd)(v1, *(volatile uint64_t *)&dword_10E3E8);
  v3 = ((uint64_t (*)())aeabi_dsub)(v2, *(volatile uint64_t *)&dword_10E3F0);
  v4 = ((uint64_t (*)())double_subtract)(v3, *(volatile uint64_t *)&dword_10E3E8);
  v5 = ((int (*)(uint64_t))aeabi_dmul)(v4);
  check_hw_status(2);
  v6 = (void *)(uintptr_t)(off_10E408);
  v0[1] = 1;
  while ( v6[7] != 1 )
    ;
  v6[7] = 1;
  v7 = v6[4];
  check_hw_status(3);
  v8 = aeabi_ui2d(v7);
  v9 = ((uint64_t (*)())aeabi_dadd)(v8, *(volatile uint64_t *)&dword_10E3E8);
  v10 = ((uint64_t (*)())aeabi_dsub)(v9, *(volatile uint64_t *)&dword_10E3F0);
  v11 = ((uint64_t (*)())double_subtract)(v10, *(volatile uint64_t *)&dword_10E3E8);
  v12 = ((int (*)(uint64_t))aeabi_dmul)(v11);
  v13 = ((uint64_t (*)())aeabi_d2f)(v12);
  v14 = ((uint64_t (*)())aeabi_dsub)(v13, *(volatile uint64_t *)&dword_10E3F8);
  v15 = (v15 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_10E40C) << 32);
  v15 = (v15 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v16 = ((uint64_t (*)())aeabi_dadd)(v14, v15);
  v17 = ((uint64_t (*)())aeabi_d2f)(v5);
  v18 = ((uint64_t (*)())aeabi_dsub)(v17, *(volatile uint64_t *)&dword_10E3F8);
  v19 = (v19 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_10E410) << 32);
  v19 = (v19 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v20 = ((uint64_t (*)())aeabi_dadd)(v18, v19);
  v21 = double_add(v16, v20);
  v22 = (v22 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_10E414) << 32);
  v22 = (v22 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v23 = ((uint64_t (*)())aeabi_dadd)(v21, v22);
  v24 = ((uint64_t (*)())aeabi_dadd)(v23, *(volatile uint64_t *)&dword_10E400);
  v25 = (v25 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_10E418) << 32);
  v25 = (v25 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v26 = ((uint64_t (*)())aeabi_dsub)(v24, v25);
  return (int)COERCE_FLOAT(((int (*)(uint64_t))aeabi_dmul)(v26));
}


// sdio_core_set_enable @ 0x10e420
int sdio_core_set_enable() {
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

  v0 = (void *)(uintptr_t)(off_10E4C8);
  *((volatile uint32_t *)off_10E4C8 + 1) = 1;
  while ( v0[7] != 1 )
    ;
  v0[7] = 1;
  v1 = aeabi_ui2d(v0[4]);
  v2 = ((uint64_t (*)())aeabi_dadd)(v1, *(volatile uint64_t *)&dword_10E4A8);
  v3 = ((uint64_t (*)())aeabi_dsub)(v2, *(volatile uint64_t *)&dword_10E4B0);
  v4 = ((uint64_t (*)())double_subtract)(v3, *(volatile uint64_t *)&dword_10E4A8);
  v5 = ((int (*)(uint64_t))aeabi_dmul)(v4);
  v6 = ((uint64_t (*)())aeabi_d2f)(v5);
  v7 = ((uint64_t (*)())aeabi_dsub)(v6, *(volatile uint64_t *)&dword_10E4B8);
  v8 = (v8 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_10E4CC) << 32);
  v8 = (v8 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v9 = ((uint64_t (*)())aeabi_dadd)(v7, v8);
  v10 = (v10 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_10E4D0) << 32);
  v10 = (v10 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v11 = ((uint64_t (*)())aeabi_dadd)(v9, v10);
  v12 = ((uint64_t (*)())aeabi_dadd)(v11, *(volatile uint64_t *)&dword_10E4C0);
  v13 = (v13 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_10E4D4) << 32);
  v13 = (v13 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v14 = ((uint64_t (*)())aeabi_dsub)(v12, v13);
  return (int)COERCE_FLOAT(((int (*)(uint64_t))aeabi_dmul)(v14));
}


// periph_cmd_write @ 0x10e4d8
int periph_cmd_write() {
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

  v0 = dword_10E76C;
  v1 = (void *)(uintptr_t)(off_10E774);
  *((volatile uint32_t *)off_10E768 + 14) = 296;
  v1[3] = v0 | v1[3] & 0xE0000000;
  call_slot_0x1b8();
  v1[2] = dword_10E778 & v1[2] | 0x1200000F;
  v1[1] = 1;
  while ( v1[7] != 1 )
    ;
  v1[7] = 1;
  v2 = aeabi_ui2d(v1[4]);
  v3 = ((uint64_t (*)())aeabi_dadd)(v2, *(volatile uint64_t *)&dword_10E750);
  v4 = ((uint64_t (*)())double_subtract)(v3, *(volatile uint64_t *)&dword_10E758);
  v5 = ((int (*)(uint64_t))double_to_float_1)(v4);
  dispatch_event_handler_1("Initial    Volt:  %d mV\n", v5);
  v6 = call_indirect_table();
  v7 = v5 - 1400;
  v8 = abs32(v5 - 1400);
  v9 = v6 & 0x3F;
  v38 = v9;
  if ( v8 > 49 )
  {
    v10 = aeabi_i2d(v8);
    v11 = ((uint64_t (*)())aeabi_dadd)(v10, *(volatile uint64_t *)&dword_10E760);
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
      call_slot_0x1b8();
      v15 = (void *)(uintptr_t)(off_10E774);
      *((volatile uint32_t *)off_10E774 + 1) = 1;
      while ( v15[7] != 1 )
        ;
      v15[7] = 1;
      v16 = aeabi_ui2d(v15[4]);
      v17 = ((uint64_t (*)())aeabi_dadd)(v16, *(volatile uint64_t *)&dword_10E750);
      v18 = ((uint64_t (*)())double_subtract)(v17, *(volatile uint64_t *)&dword_10E758);
      v5 = ((int (*)(uint64_t))double_to_float_1)(v18);
      dispatch_event_handler_1("step=%d, val=%d, volt=%d\n", v13, v14, v5);
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
  v21 = (void *)(uintptr_t)(off_10E774);
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
    call_slot_0x1b8();
    v21[1] = 1;
    while ( v21[7] != 1 )
      ;
    v21[7] = 1;
    v26 = aeabi_ui2d(v21[4]);
    v27 = ((uint64_t (*)())aeabi_dadd)(v26, *(volatile uint64_t *)&dword_10E750);
    v28 = ((uint64_t (*)())double_subtract)(v27, *(volatile uint64_t *)&dword_10E758);
    v37 = ((int (*)(uint64_t))double_to_float_1)(v28);
    dispatch_event_handler_1("ofst=%d, val=%d, volt=%d\n", v25, v23, v37);
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
  dispatch_event_handler_1("reg_value_offset: %d\n", v25);
  call_slot_0x1b8();
  v31 = (void *)(uintptr_t)(off_10E774);
  *((volatile uint32_t *)off_10E774 + 1) = 1;
  while ( v31[7] != 1 )
    ;
  v31[7] = 1;
  v32 = aeabi_ui2d(v31[4]);
  v33 = ((uint64_t (*)())aeabi_dadd)(v32, *(volatile uint64_t *)&dword_10E750);
  v34 = ((uint64_t (*)())double_subtract)(v33, *(volatile uint64_t *)&dword_10E758);
  v35 = ((int (*)(uint64_t))double_to_float_1)(v34);
  dispatch_event_handler_1("Calibrated Volt:  %d mV\n", v35);
  return call_slot_0x1b8();
}


// periph_cmd_poll @ 0x10e798
int periph_cmd_poll() {
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

  v0 = (void *)(uintptr_t)(off_10EA4C);
  v1 = dword_10EA50;
  v2 = dword_10EA54;
  *((volatile uint32_t *)off_10EA48 + 14) = 296;
  v0[2] = v1 & v0[2] | 0x200000B;
  v0[3] = v2 | v0[3] & 0xE0000000;
  v0[1] = 1;
  while ( v0[7] != 1 )
    ;
  v0[7] = 1;
  v3 = aeabi_ui2d(v0[4]);
  v4 = ((uint64_t (*)())aeabi_dadd)(v3, *(volatile uint64_t *)&dword_10EA30);
  v5 = ((uint64_t (*)())aeabi_dsub)(v4, *(volatile uint64_t *)&dword_10EA38);
  v6 = ((uint64_t (*)())double_subtract)(v5, *(volatile uint64_t *)&dword_10EA30);
  v7 = ((int (*)(uint64_t))double_to_float_1)(v6);
  v8 = call_indirect_table() & 0x1F;
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
    v11 = aeabi_i2d(v10);
    v12 = ((uint64_t (*)())aeabi_dadd)(v11, *(volatile uint64_t *)&dword_10EA40);
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
    call_slot_0x1b8();
    v16 = (void *)(uintptr_t)(off_10EA4C);
    *((volatile uint32_t *)off_10EA4C + 1) = 1;
    while ( v16[7] != 1 )
      ;
    v16[7] = 1;
    v17 = aeabi_ui2d(v16[4]);
    v18 = ((uint64_t (*)())aeabi_dadd)(v17, *(volatile uint64_t *)&dword_10EA30);
    v19 = ((uint64_t (*)())aeabi_dsub)(v18, *(volatile uint64_t *)&dword_10EA38);
    v20 = ((uint64_t (*)())double_subtract)(v19, *(volatile uint64_t *)&dword_10EA30);
    v7 = ((int (*)(uint64_t))double_to_float_1)(v20);
    dispatch_event_handler_1("step=%d, val=%x, volt=%d\n", v14, v15, v7);
    if ( v7 <= 840 )
      v21 = 1;
    else
      v21 = -1;
    v41 = v21;
  }
  v23 = (void *)(uintptr_t)(off_10EA4C);
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
    call_slot_0x1b8();
    v23[1] = 1;
    while ( v23[7] != 1 )
      ;
    v23[7] = 1;
    v27 = aeabi_ui2d(v23[4]);
    v28 = ((uint64_t (*)())aeabi_dadd)(v27, *(volatile uint64_t *)&dword_10EA30);
    v29 = ((uint64_t (*)())aeabi_dsub)(v28, *(volatile uint64_t *)&dword_10EA38);
    v30 = ((uint64_t (*)())double_subtract)(v29, *(volatile uint64_t *)&dword_10EA30);
    v31 = ((int (*)(uint64_t))double_to_float_1)(v30);
    dispatch_event_handler_1("ofst=%d, val=%x, volt=%d\n", v9, v24, v31);
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
  call_slot_0x1b8();
  v34 = (void *)(uintptr_t)(off_10EA4C);
  *((volatile uint32_t *)off_10EA4C + 1) = 1;
  while ( v34[7] != 1 )
    ;
  v34[7] = 1;
  v35 = aeabi_ui2d(v34[4]);
  v36 = ((uint64_t (*)())aeabi_dadd)(v35, *(volatile uint64_t *)&dword_10EA30);
  v37 = ((uint64_t (*)())aeabi_dsub)(v36, *(volatile uint64_t *)&dword_10EA38);
  v38 = ((uint64_t (*)())double_subtract)(v37, *(volatile uint64_t *)&dword_10EA30);
  v39 = ((int (*)(uint64_t))double_to_float_1)(v38);
  log_printf("Calib vcore Volt: %d mV\n", v39);
  result = ((volatile uint32_t *)(uintptr_t)off_10EA70)[94];
  if ( result != 0x80000000 )
    return rf_reg_update(result);
  return result;
}


// gpio_mode_set @ 0x10ea74
int gpio_mode_set(unsigned int a1, unsigned int a2, volatile unsigned int *a3) {
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

  v4 = (volatile unsigned int *)off_10EC14;
  v5 = (volatile unsigned int *)off_10EC18;
  *(volatile uint32_t *)off_10EC14 = *(volatile uint32_t *)off_10EC14 & 0xFFFFFFF8 | a1 & 7;
  *v5 = ((uint16_t)a1 << 12) & 0x7000 | *v5 & 0xFFFF8FFF;
  *v4 = (8 * a2) & 0x78 | *v4 & 0xFFFFFF87;
  *v5 = (a2 << 15) & 0x78000 | *v5 & 0xFFF87FFF;
  v8 = (volatile int16_t *)off_10EC1C;
  v9 = sdio_core_enable();
  dispatch_event_handler_1("cal start, reg_init=(%d,%d), i_pa_init=%d, i_pa_target=%d\n", a1, a2, v9, *v8);
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
  v11 = (volatile unsigned int *)off_10EC14;
  v12 = (volatile unsigned int *)off_10EC18;
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
    v9 = sdio_core_enable();
    dispatch_event_handler_1("reg_val_res=%d, reg_val_cgm=%d, i_pa=%d\n", v13, v3, v9);
    v16 = *(volatile int16_t *)off_10EC1C;
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
  dispatch_event_handler_1("cal done, offset_res=%d,(%d,%d), i_pa_res=%d\n", v20, v13 - v21, v3 - a2, v9);
LABEL_9:
  *a3 = v3;
  return v20;
}


// gpio_af_set @ 0x10ec2c
int gpio_af_set(int a1) {
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
  int a4; // [sp+0h] [bp-Ch]
  int v17; // [sp+4h] [bp-8h]

  v1 = (volatile int16_t *)off_10ED48;
  *(volatile uint32_t *)off_10ED3C = (a1 << 26) & 0x1C000000 | *(volatile uint32_t *)off_10ED3C & 0xE3FFFFFF;
  v2 = a1;
  v3 = sdio_core_set_enable();
  dispatch_event_handler_1("cal start, reg_init=%d, i_pa_init=%d, i_pa_target=%d\n", v2, v3, *v1);
  v4 = *v1;
  if ( v4 > v3 )
  {
    a4 = 1;
  }
  else
  {
    if ( v4 >= v3 )
      return 0;
    a4 = -1;
  }
  v5 = (volatile unsigned int *)off_10ED3C;
  v17 = v2;
  v6 = 4;
  v7 = 0;
  while ( 1 )
  {
    v2 += a4;
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
        v7 += a4;
      }
    }
    else
    {
      v8 = 469762048;
      v7 = 7 - v17;
      v2 = 7;
    }
    *v5 = *v5 & 0xE3FFFFFF | v8;
    v9 = sdio_core_set_enable();
    dispatch_event_handler_1("reg_val=%d, i_pa=%d\n", v2, v9);
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
    v7 -= a4;
    v15 = v3;
    *v5 = ((v2 - a4) << 26) & 0x1C000000 | *v5 & 0xE3FFFFFF;
  }
  dispatch_event_handler_1("cal done, offset_res=%d, i_pa_res=%d\n", v7, v15);
  return v7;
}


// gpio_bank_init @ 0x10ed50
int gpio_bank_init(int a1) {
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
  struct __attribute__((packed)) { uint8_t a1a[4]; // [sp+Ch] [bp-Ch] BYREF
  int v17; // [sp+10h] [bp-8h]
  uint16_t v18; // [sp+14h] [bp-4h]
  } _frame;
  v1 = (void *)(uintptr_t)(off_10EE54);
  v2 = dword_10EE58;
  v3 = dword_10EE5C;
  v4 = (void *)(uintptr_t)(off_10EE60);
  v5 = (void *)(uintptr_t)(off_10EE78);
  v6 = dword_10EE64;
  v7 = (volatile unsigned int *)off_10EE68;
  _frame.v18 = 0;
  *((volatile uint32_t *)off_10EE74 + 14) = 296;
  v1[3] = v1[3] & 0xE0000000 | v2;
  v1[2] = v3 & v1[2] | 0x1200000D;
  *v4 |= 2u;
  *v4 &= ~1u;
  *(volatile uint32_t *)_frame.a1a = v6;
  _frame.v17 = 5610;
  tx_set_power(_frame.a1a, 0);
  v8 = (volatile int *)off_10EE6C;
  v9 = dword_10EE70;
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
  result = gpio_mode_set(4u, 8u, (volatile unsigned int *)a1);
  *v5 &= ~0x80000000;
  *v4 &= ~2u;
  *v7 = v10 & 0x80000 | *v7 & 0xFFF7FFFF;
  *v7 = v11 & 0x100000 | *v7 & 0xFFEFFFFF;
  *v7 = v12 & 0x200000 | *v7 & 0xFFDFFFFF;
  *v7 = v13 & 0x400000 | *v7 & 0xFFBFFFFF;
  return result;
}


// gpio_bank_init2 @ 0x10ee7c
int gpio_bank_init2() {
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
  struct __attribute__((packed)) { uint8_t a1[4]; // [sp+4h] [bp-Ch] BYREF
  int v16; // [sp+8h] [bp-8h]
  uint16_t v17; // [sp+Ch] [bp-4h]
  } _frame;
  v0 = (volatile unsigned int *)off_10EF7C;
  v1 = (void *)(uintptr_t)(off_10EF80);
  v2 = dword_10EF84;
  v3 = dword_10EF88;
  v4 = (void *)(uintptr_t)(off_10EF9C);
  v5 = (void *)(uintptr_t)(off_10EF8C);
  v6 = (void *)(uintptr_t)(off_10EFA0);
  v7 = dword_10EF90;
  _frame.v17 = 0;
  *((volatile uint32_t *)off_10EF7C + 14) = 296;
  v1[3] = v2 | v1[3] & 0xE0000000;
  v1[2] = v3 & v1[2] | 0x1200000D;
  *v4 |= 0x20000000u;
  *v5 &= ~1u;
  *(volatile uint32_t *)_frame.a1 = v7;
  _frame.v16 = 2442;
  tx_set_power(_frame.a1, 0);
  v8 = (volatile int *)off_10EF94;
  v9 = dword_10EF98;
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
  result = gpio_af_set(4);
  *v6 &= ~0x80000000;
  *v4 &= ~0x20000000u;
  *v0 = v10 & 0x80000 | *v0 & 0xFFF7FFFF;
  *v0 = v11 & 0x100000 | *v0 & 0xFFEFFFFF;
  *v0 = v12 & 0x200000 | *v0 & 0xFFDFFFFF;
  *v0 = v13 & 0x400000 | *v0 & 0xFFBFFFFF;
  return result;
}


// call_indirect_table @ 0x10efa4
int call_indirect_table() {
  return ((int (*)())MEMD(0x1B0))();
}



// call_slot_0x1b4 @ 0x10efac
int call_slot_0x1b4() {
  return ((int (*)())MEMD(0x1B4))();
}



// call_slot_0x1b8 @ 0x10efb4
/* luna: Indirect call thunk that invokes the function pointer stored at literal table slot 0x1B8. */
int call_slot_0x1b8() {
  return ((int (*)())MEMD(0x1B8))();
}



// critical_enter @ 0x10efbc
int critical_enter(int a1, int a2) {
  volatile int *v2; // r5
  volatile uint32_t *v3; // r4
  int result; // r0
  int v5; // r3
  int v6; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_10F004 = 1;
  }
  v2 = (volatile int *)off_10F008;
  ++*(volatile uint32_t *)off_10F008;
  if ( a2 )
  {
    v3 = (void *)(uintptr_t)(off_10F00C);
    while ( !*(volatile uint32_t *)off_10F00C )
      ;
    result = call_indirect_table();
    *v3 = 1;
  }
  else
  {
    result = call_indirect_table();
  }
  if ( *v2 )
  {
    v5 = *v2 - 1;
    v6 = *(volatile uint32_t *)off_10F004;
    *v2 = v5;
    if ( !v5 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
  return result;
}



// critical_enter2 @ 0x10f010
int critical_enter2(int a1, int a2, int a3) {
  volatile int *v3; // r5
  volatile uint32_t *v4; // r4
  int result; // r0
  int v6; // r3
  int v7; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_10F058 = 1;
  }
  v3 = (volatile int *)off_10F05C;
  ++*(volatile uint32_t *)off_10F05C;
  if ( a3 )
  {
    v4 = (void *)(uintptr_t)(off_10F060);
    while ( !*(volatile uint32_t *)off_10F060 )
      ;
    result = call_slot_0x1b4();
    *v4 = 1;
  }
  else
  {
    result = call_slot_0x1b4();
  }
  if ( *v3 )
  {
    v6 = *v3 - 1;
    v7 = *(volatile uint32_t *)off_10F058;
    *v3 = v6;
    if ( !v6 )
    {
      if ( v7 )
        __enable_irq();
    }
  }
  return result;
}



// critical_enter3 @ 0x10f064
int critical_enter3(int a1, int a2, int a3, int a4) {
  volatile int *v4; // r5
  volatile uint32_t *v5; // r4
  int result; // r0
  int v7; // r3
  int v8; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_10F0AC = 1;
  }
  v4 = (volatile int *)off_10F0B0;
  ++*(volatile uint32_t *)off_10F0B0;
  if ( a4 )
  {
    v5 = (void *)(uintptr_t)(off_10F0B4);
    while ( !*(volatile uint32_t *)off_10F0B4 )
      ;
    result = call_slot_0x1b8();
    *v5 = 1;
  }
  else
  {
    result = call_slot_0x1b8();
  }
  if ( *v4 )
  {
    v7 = *v4 - 1;
    v8 = *(volatile uint32_t *)off_10F0AC;
    *v4 = v7;
    if ( !v7 )
    {
      if ( v8 )
        __enable_irq();
    }
  }
  return result;
}



// ke_event_set @ 0x10f0b8
int ke_event_set(int a1) {
  dispatch_event_handler_1("Reboot:%x\n", a1);
  critical_enter3(dword_10F104, 196608, dword_10F100, 1);
  critical_enter3(1879048192, 1, 1, 1);
  critical_enter2(dword_10F108, a1, 1);
  return critical_enter3(dword_10F10C, 2, 2, 1);
}


// pmu_write_clock_ctrl @ 0x10f110
int pmu_write_clock_ctrl(int a1) {
  critical_enter3(dword_10F144, 196608, dword_10F140, 1);
  critical_enter2(dword_10F148, a1 << 15, 1);
  return critical_enter3(1879048192, 1, 1, 1);
}



// mmio_set_reg_0x70001408 @ 0x10f14c
int mmio_set_reg_0x70001408() {
  return critical_enter3(dword_10F158, 0, 2, 1);
}



// get_xtal_ftune @ 0x10f15c
/* luna: Reads the crystal oscillator frequency tuning/trim field from a common register and returns the extracted bits. */
int get_xtal_ftune() {
  return (uint16_t)critical_enter(dword_10F16C, 1) >> 11;
}



// set_xtal_ftune @ 0x10f170
int set_xtal_ftune(int a1) {
  return critical_enter3(dword_10F184, (a1 << 11) & 0xF800, 63488, 1);
}



// get_bandgap_trim @ 0x10f188
int get_bandgap_trim(int a1) {
  unsigned int v2; // r0
  unsigned int v3; // r1

  v2 = critical_enter(dword_10F1DC, 1);
  v3 = (v2 >> 20) & 0xF;
  if ( a1 )
  {
    if ( ((v2 >> 20) & 0xE) != 0 )
    {
      v3 = ((v3 - 2) << 20) & 0xF00000;
    }
    else if ( v3 )
    {
      v3 = ((v3 - 1) << 20) & 0xF00000;
    }
  }
  else if ( v3 > 0xD )
  {
    v3 = 15728640;
  }
  else
  {
    v3 = ((v3 + 2) << 20) & 0xF00000;
  }
  return critical_enter3(dword_10F1DC, v3, 15728640, 1);
}



// chip_common_write @ 0x10f1e0
int chip_common_write() {
  volatile uint8_t *v0; // r4
  int v1; // r5
  int v2; // r1
  int v3; // r2
  int result; // r0

  critical_enter3(1879048192, 256, 264, 1);
  v0 = (void *)(uintptr_t)(off_10F3AC);
  v1 = dword_10F3B4;
  critical_enter3(dword_10F3B0, 0x8000000, 0x8000000, 1);
  critical_enter3(dword_10F3B8, 21, 31, 1);
  v2 = dword_10F3BC;
  if ( (*v0 & 0xC0) == 0xC0 )
    v2 = v1;
  critical_enter3(dword_10F3C4, v2, dword_10F3C0, 1);
  critical_enter3(dword_10F3C8, 2560, 2560, 1);
  critical_enter3(dword_10F3CC, 255, 255, 1);
  critical_enter3(dword_10F3D0, 0, 100663296, 1);
  critical_enter3(dword_10F3D4, 0, 983040, 1);
  critical_enter3(dword_10F3D8, 96, 96, 1);
  critical_enter3(dword_10F3DC, 256, 256, 1);
  critical_enter3(dword_10F3E0, 469762048, 469762048, 1);
  critical_enter3(dword_10F3E4, 104, 252, 1);
  if ( (*v0 & 0xC0) == 0xC0 )
    v3 = 102;
  else
    v3 = 6;
  critical_enter3(dword_10F3E8, 6, v3, 1);
  critical_enter3(dword_10F3EC, 320, 992, 1);
  critical_enter3(dword_10F3F8, dword_10F3F4, dword_10F3F0, 1);
  critical_enter3(dword_10F3FC, 0x400000, 15728640, 1);
  critical_enter3(dword_10F400, 16, 63, 1);
  critical_enter3(dword_10F404, 0, 60, 1);
  critical_enter3(dword_10F408, 0, 256, 1);
  critical_enter3(dword_10F40C, 2048, 16128, 1);
  result = critical_enter3(dword_10F410, 1, 1, 1);
  if ( **(volatile uint8_t **)off_10F414 == 1 )
  {
    critical_enter2(dword_10F41C, dword_10F418, 1);
    critical_enter2(dword_10F424, dword_10F420, 1);
    critical_enter3(dword_10F410, 0x100000, 0x100000, 1);
    result = critical_enter3(dword_10F428, 2, 31, 1);
    if ( !*((volatile uint8_t *)off_10F42C + 375) )
    {
      critical_enter3(dword_10F430, 1, 1, 1);
      critical_enter3(dword_10F408, 256, 256, 1);
      critical_enter3(dword_10F40C, 0x2000, 16128, 1);
      critical_enter3(dword_10F3D0, 2359296, 16515072, 1);
      return critical_enter3(dword_10F410, 256, 256, 1);
    }
  }
  return result;
}



// set_tx_power_cal @ 0x10f434
unsigned int set_tx_power_cal() {
  unsigned int result; // r0

  result = gpio_config(0xC2u);
  *((volatile uint8_t *)off_10F448 + 7) = -62;
  return result;
}



// tx_power_temperature_comp @ 0x10f44c
/* luna: Computes and stores the RF TX power temperature compensation value, clamps negative compensation, updates GPIO configuration, logs the change, and eit */
int tx_power_temperature_comp() {
  volatile uint8_t *p_temp_comp_state; // r6
  int temp_base_code; // r5
  int temp_comp_value; // r4
  int result; // r0
  volatile unsigned int now_tick; // r3

  p_temp_comp_state = (void *)(uintptr_t)(off_10F4AC);
  temp_base_code = (char)(*((volatile uint8_t *)off_10F4AC + 5) + (*(volatile uint8_t *)off_10F4A8 & 3));
  temp_comp_value = *((volatile char *)off_10F4AC + 7) - temp_base_code;
  if ( temp_comp_value < -62 )
    temp_comp_value = (temp_comp_value & ~0xFFu) | ((uint8_t)(-62) & 0xFFu);
  gpio_config(temp_comp_value);
  p_temp_comp_state[7] = temp_comp_value;
  result = dispatch_event_handler_1("update# =%d %d\r\n", (char)temp_comp_value, temp_base_code);
  if ( (char)temp_comp_value < -61 )
  {
    p_temp_comp_state[11] = 0;
  }
  else
  {
    now_tick = (*(volatile uint32_t *)0x40501010u);
    return ke_enter_critical((volatile uint32_t *)p_temp_comp_state + 3, now_tick + 30000 * *((volatile uint16_t *)p_temp_comp_state + 4));
  }
  return result;
}


// mem_get_stats @ 0x10f4b8
int mem_get_stats() {
  uint64_t v0; // r0
  uint64_t v1; // kr00_8
  volatile uint64_t *v2; // r3

  v0 = *(volatile uint64_t *)(*(volatile uint32_t *)off_10F500 + 32);
  v1 = *(volatile uint64_t *)(*(volatile uint32_t *)off_10F500 + 24);
  v2 = (void *)(uintptr_t)(off_10F504);
  *((volatile uint32_t *)off_10F504 + 4) = *(volatile uint32_t *)(*(volatile uint32_t *)off_10F500 + 44);
  *v2 = v1;
  v2[1] = v0;
  configure_dma_engine();
  get_device_config();
  nvic_enable_irq();
  if ( **(volatile uint8_t **)off_10F508 == 3 )
    clear_buffer_180a0c();
  return (int)(uintptr_t)(clear_mac_info());
}


// rf_init @ 0x10f50c
int rf_init() {
  volatile uint8_t *v0; // r3
  int result; // r0
  void *v2; // r1
  int v3; // r2

  if ( *((volatile uint8_t *)off_10F540 + 362) )
  {
    *(volatile uint8_t *)off_10F544 = 0;
  }
  else
  {
    v0 = (void *)(uintptr_t)(off_10F544);
    *(volatile uint32_t *)off_10F544 = dword_10F548;
    v2 = (void *)(uintptr_t)(off_10F54C);
    v3 = dword_10F550;
    v0[7] = -62;
    *((volatile uint32_t *)v0 + 2) = 1000;
    *((volatile uint16_t *)v0 + 2) = 1752;
    *((volatile uint32_t *)v0 + 4) = (int)(uintptr_t)(v2);
    *((volatile uint32_t *)v0 + 8) = v3;
    return 1752;
  }
  return result;
}



// mem_free_ret @ 0x10f5bc
int mem_free_ret(int a1, int a2) {
  mem_free((void *)(uintptr_t)(a2));
  return 1;
}



// bt_msg_init @ 0x10f5c8
int bt_msg_init() {
  volatile uint8_t *v0; // r4
  volatile char *v1; // r0

  v0 = (void *)(uintptr_t)(off_10F5F8);
  v1 = (volatile char *)off_10F5F8 + 1624;
  *((volatile uint16_t *)off_10F5F8 + 810) = 80;
  v0[1622] = 81;
  list_init_1((void *)(v1));
  *((volatile uint16_t *)v0 + 1216) = 39;
  v0[2434] = 40;
  return (int)(uintptr_t)(list_init_1((void *)(v0 + 2436)));
}



// mmio_write16 @ 0x10f5fc
uint64_t mmio_write16() {
  volatile uint16_t *v0; // r5
  volatile int *v1; // r4
  volatile int *v2; // r5
  int v3; // r6
  volatile int *v4; // r1
  int v5; // r2
  uint64_t result; // r0
  volatile uint32_t *v7; // r3

  v0 = (void *)(uintptr_t)(off_10F698);
  v1 = (volatile int *)dword_10F69C;
  *((volatile uint16_t *)off_10F698 + 3080) = -16193;
  v0[1536] = -16193;
  *((volatile uint8_t *)v0 + 6162) = 0;
  *((volatile uint32_t *)v0 + 1541) = 0;
  *((volatile uint8_t *)v0 + 6176) = 0;
  *((volatile uint8_t *)v0 + 3074) = 0;
  *((volatile uint32_t *)v0 + 769) = 0;
  list_init_1((volatile uint32_t *)v0 + 770);
  list_init_1((void *)(v1 - 3));
  list_init_1((void *)(v1 + 512));
  list_init_1((void *)(v1 + 514));
  v0[4122] = 0;
  *((volatile uint8_t *)v0 + 3074) = 0;
  *((volatile uint32_t *)v0 + 769) = 0;
  memset(v1, 0, 0x800u);
  v2 = v1 + 512;
  v3 = (int)(v1 + 512);
  do
  {
    v4 = v1;
    v1 += 4;
    check_kernel_state(v3, (void *)(v4));
  }
  while ( v1 != v2 );
  v5 = dword_10F6A0;
  result = (unsigned int)(dword_10F6A0 + 144);
  do
  {
    v7 = (volatile uint32_t *)(v5 - 36);
    do
      *v7++ = 0;
    while ( v7 != (volatile uint32_t *)v5 );
    v5 = (int)(v7 + 9);
  }
  while ( v7 + 9 != (volatile uint32_t *)result );
  return result;
}


// bt_state_dispatch @ 0x10f6a4
int bt_state_dispatch() {
  volatile uint8_t **v0; // r4
  int v1; // r3
  volatile uint32_t *v2; // r3
  void *v3; // r2
  int result; // r0
  int v5; // r3
  volatile uint32_t *v6; // r3
  void *v7; // r2
  volatile uint32_t *v8; // r3
  void *v9; // r2
  int ( **v10)(volatile int *); // r4
  int v11; // r0
  int v12; // r2
  int ( **v13)(volatile int *); // r5
  int v14; // r0
  int ( **v15)(volatile int *); // r5
  int v16; // r0

  v0 = (volatile uint8_t **)off_10F764;
  v1 = **(volatile uint8_t **)off_10F764;
  switch ( v1 )
  {
    case 1:
      v8 = (void *)(uintptr_t)(off_10F768);
      v9 = (void *)(uintptr_t)(off_10F780);
      *((volatile uint32_t *)off_10F768 + 2) = off_10F77C;
      v8[3] = (int)(uintptr_t)(v9);
      break;
    case 2:
      v2 = (void *)(uintptr_t)(off_10F768);
      v3 = (void *)(uintptr_t)(off_10F770);
      *((volatile uint32_t *)off_10F768 + 6) = off_10F76C;
      v2[7] = (int)(uintptr_t)(v3);
      break;
    case 3:
      v6 = (void *)(uintptr_t)(off_10F768);
      v7 = (void *)(uintptr_t)(off_10F778);
      *((volatile uint32_t *)off_10F768 + 8) = off_10F774;
      v6[9] = (int)(uintptr_t)(v7);
      break;
  }
  bt_msg_init();
  result = mmio_write16();
  v5 = **v0;
  if ( v5 == 1 )
  {
    v15 = (int ( **)(volatile int *))off_10F768;
    *(volatile uint32_t *)off_10F784 = dword_10F798;
    rx_packet_event();
    rf_lmac_init_n114();
    rx_adv_event();
    rx_channel_event();
    v16 = v15[2]((volatile int *)off_10F78C);
    result = v15[3]((volatile int *)v16);
    v5 = **v0;
  }
  if ( v5 == 2 )
  {
    v12 = dword_10F794;
    *(volatile uint32_t *)off_10F784 = dword_10F790;
    v13 = (int ( **)(volatile int *))off_10F768;
    *(volatile uint16_t *)(v12 + 8244) = 0;
    tx_event_handler();
    timer_event_handler();
    v14 = v13[6]((volatile int *)off_10F78C);
    v13[7]((volatile int *)v14);
    result = prepare_and_dispatch();
    v5 = **v0;
  }
  if ( v5 == 3 )
  {
    v10 = (int ( **)(volatile int *))off_10F768;
    *(volatile uint32_t *)off_10F784 = dword_10F788;
    controller_state_machine();
    v11 = v10[8]((volatile int *)off_10F78C);
    return v10[9]((volatile int *)v11);
  }
  return result;
}


// ipc_send_0x40d @ 0x10f7fc
int ipc_send_0x40d() {
  int v0; // r0

  v0 = ke_msg_send_1(1037, 1, 4, 8);
  return (int)(uintptr_t)(rx_irq_handler_1(v0));
}



// ke_msg_send @ 0x10f814
unsigned int ke_msg_send(volatile int *a1, int a2, unsigned int a3) {
  unsigned int result; // r0
  unsigned int v6; // r2
  unsigned int v7; // r3
  volatile int *v8; // r8
  volatile int *v9; // r9
  int v10; // r7
  volatile int *v11; // r11
  int v12; // r4
  unsigned int v13; // r5
  int v14; // r6
  volatile uint32_t *v15; // r5
  volatile uint32_t *v16; // r10
  int v17; // r3
  int v18; // r3
  int v19; // r3
  volatile uint32_t *v20; // r7
  int v21; // r5
  unsigned int v22; // r3
  unsigned int v23; // r2
  unsigned int v24; // r3
  int v25; // [sp+0h] [bp-24h]
  int v26; // [sp+4h] [bp-20h]
  unsigned int v27; // [sp+8h] [bp-1Ch]
  unsigned int v28; // [sp+Ch] [bp-18h]
  char v29; // [sp+10h] [bp-14h]

  result = *a1;
  v28 = result;
  if ( a3 )
  {
    v6 = result % a3;
    v7 = a3;
    if ( v6 )
    {
      v7 = a3 - v6;
      if ( a3 - v6 <= 3 )
        v7 += a3;
    }
    v28 = result + v7 - 4;
  }
  if ( !*((volatile uint8_t *)a1 + 8) )
    return result;
  v8 = (void *)(uintptr_t)(((volatile uint32_t *)(uintptr_t)&off_10FA10)[0]);
  v9 = (void *)(uintptr_t)(off_10FA14);
  v25 = 0;
  v10 = 0;
  v11 = a1;
  while ( 2 )
  {
    result = *(volatile uint16_t *)(a2 + 4 * v10);
    v12 = 0;
    v13 = *(volatile uint16_t *)(a2 + 4 * v10 + 2);
    v14 = v11[3] + 12 * v10;
    *(volatile uint32_t *)v14 = 0;
    *(volatile uint16_t *)(v14 + 4) = 0;
    if ( !v13 )
      goto LABEL_6;
    v26 = result + 4;
    *(volatile uint16_t *)(v14 + 2) = v13;
    v27 = v13;
    *(volatile uint16_t *)(v14 + 4) = result;
    v15 = (volatile uint32_t *)(v28 + 4);
    v16 = nullptr;
    v29 = v10;
    do
    {
      v20 = v16;
      v16 = v15;
      if ( *v8 <= (unsigned int)v15 && *v8 + v8[1] >= (unsigned int)v15
        || *v9 <= (unsigned int)v15 && *v9 + v9[1] >= (unsigned int)v15 )
      {
        *((volatile uint8_t *)v15 - 4) = v29;
        v17 = *v8;
        if ( *v8 > (unsigned int)v15 )
          goto LABEL_22;
      }
      else
      {
        log_printf("set_native_pool_id: Invalid buffer passed: %x\n", v15);
        v17 = *v8;
        if ( *v8 > (unsigned int)v15 )
          goto LABEL_22;
      }
      if ( v17 + v8[1] >= (unsigned int)v15 )
        goto LABEL_12;
LABEL_22:
      if ( *v9 <= (unsigned int)v15 && *v9 + v9[1] >= (unsigned int)v15 )
      {
LABEL_12:
        *((volatile uint8_t *)v15 - 3) = 85;
        v18 = *v8;
        if ( *v8 > (unsigned int)v15 )
          goto LABEL_25;
        goto LABEL_13;
      }
      log_printf("set_pattern: Invalid buffer passed: %x\n", v15);
      v18 = *v8;
      if ( *v8 > (unsigned int)v15 )
        goto LABEL_25;
LABEL_13:
      if ( v18 + v8[1] >= (unsigned int)v15 )
        goto LABEL_14;
LABEL_25:
      if ( *v9 <= (unsigned int)v15 && *v9 + v9[1] >= (unsigned int)v15 )
      {
LABEL_14:
        *((volatile uint8_t *)v15 - 2) = 0;
        v19 = *v8;
        if ( *v8 > (unsigned int)v15 )
          goto LABEL_28;
        goto LABEL_15;
      }
      log_printf("set_num_users: Invalid buffer passed: %x\n", v15);
      v19 = *v8;
      if ( *v8 > (unsigned int)v15 )
        goto LABEL_28;
LABEL_15:
      if ( v19 + v8[1] >= (unsigned int)v15 )
        goto LABEL_16;
LABEL_28:
      if ( *v9 <= (unsigned int)v15 && *v9 + v9[1] >= (unsigned int)v15 )
      {
LABEL_16:
        *v15 = (int)(uintptr_t)(v20);
        goto LABEL_17;
      }
      log_printf("set_next_buffer_addr: Invalid buffer passed: %x\n", v15);
LABEL_17:
      ++v12;
      ++*(volatile uint16_t *)v14;
      v15 = (volatile uint32_t *)((volatile char *)v15 + v26);
    }
    while ( v27 > (uint16_t)v12 );
    v21 = (uint16_t)(v27 - 1);
    v22 = v28 + v21 * v26;
    result = v28 + v26 + v21 * v26;
    v28 = result;
    *(volatile uint32_t *)(v14 + 8) = v22 + 4;
    if ( a3 )
    {
      v23 = result % a3;
      v24 = a3;
      if ( result % a3 )
      {
        v24 = a3 - v23;
        if ( a3 - v23 <= 3 )
          v24 += a3;
      }
      v28 = result + v24 - 4;
    }
LABEL_6:
    v10 = (uint8_t)++v25;
    if ( *((volatile uint8_t *)v11 + 8) > (unsigned int)(uint8_t)v25 )
      continue;
    return result;
  }
}


// list_iterate @ 0x10fa18
volatile uint32_t * list_iterate(int a1, unsigned int a2) {
  unsigned int v2; // r6
  volatile uint32_t *v3; // r5
  volatile uint16_t *v4; // r4
  unsigned int v5; // r3
  volatile int *v6; // r6
  int v7; // r3
  int v8; // r2
  volatile unsigned int *v9; // r7
  unsigned int v10; // r2
  int v11; // r1
  int v12; // r3
  int v13; // r2
  uint16_t v14; // r3
  int v15; // cc
  unsigned int v16; // r3
  volatile int *v18; // r3
  int v19; // r3
  int v20; // r3
  int v21; // r2

  v2 = *(volatile uint8_t *)(a1 + 8);
  if ( !*(volatile uint8_t *)(a1 + 8) )
  {
LABEL_57:
    log_printf("SwEr:NoSizeAlloc : %d\n\r", a2);
    return nullptr;
  }
  v3 = *(volatile uint32_t **)(a1 + 12);
  if ( !v3 )
  {
    log_printf(aMemmgrerrSubpo, a2);
    return v3;
  }
  v4 = *(volatile uint16_t **)(a1 + 12);
  v5 = 1;
  while ( v4[2] < a2 )
  {
    if ( v2 <= v5 )
      goto LABEL_11;
    v4 = (volatile uint16_t *)&v3[3 * v5];
LABEL_7:
    v5 = (uint8_t)(v5 + 1);
  }
  if ( *v4 )
    goto LABEL_12;
  if ( v2 > v5 )
  {
    v4 = (volatile uint16_t *)&v3[3 * v5];
    goto LABEL_7;
  }
LABEL_11:
  if ( v2 == v5 )
    goto LABEL_57;
LABEL_12:
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_10FBA4 = 1;
  }
  v6 = (volatile int *)off_10FBA8;
  v7 = *v4;
  v3 = *(volatile uint32_t **)off_10FBA8;
  v8 = *(volatile uint32_t *)off_10FBA8 + 1;
  *(volatile uint32_t *)off_10FBA8 = v8;
  if ( !v7 )
  {
    if ( v8 )
    {
      v18 = (volatile int *)off_10FBA4;
      *v6 = (int)v3;
      v19 = *v18;
      if ( !v3 )
      {
        if ( v19 )
          goto LABEL_43;
      }
    }
    return nullptr;
  }
  v9 = (volatile unsigned int *)((volatile uint32_t *)(uintptr_t)&off_10FBAC)[0];
  v3 = *((volatile uint32_t **)v4 + 2);
  v10 = *(volatile uint32_t *)((volatile uint32_t *)(uintptr_t)&off_10FBAC)[0];
if ( *(volatile uint32_t *)((volatile uint32_t *)(uintptr_t)&off_10FBAC)[0] <= (unsigned int)v3 && (unsigned int)v3 <= *(volatile uint32_t *)(((volatile uint32_t *)(uintptr_t)&off_10FBAC)[0] + 4) + v10 || (unsigned int)v3 >= *(volatile uint32_t *)off_10FBB0 && (unsigned int)v3 <= *(volatile uint32_t *)off_10FBB0 + *(volatile uint32_t *)(off_10FBB0 + 4) ) { *((volatile uint32_t *)v4 + 2) = *v3;
    *v4 = v7 - 1;
    if ( v10 <= (unsigned int)v3 )
      goto LABEL_18;
  }
  else
  {
    log_printf("get_next_buffer_addr: Invalid buffer passed: %x\n", *((volatile uint32_t *)v4 + 2));
    v10 = *v9;
    v14 = *v4 - 1;
    v15 = *v9 > (unsigned int)v3;
    *((volatile uint32_t *)v4 + 2) = 0;
    *v4 = v14;
    if ( !v15 )
    {
LABEL_18:
      if ( v9[1] + v10 >= (unsigned int)v3 )
      {
        v11 = *((volatile uint8_t *)v3 - 3);
        if ( v11 == 85 )
          goto LABEL_20;
        goto LABEL_45;
      }
    }
  }
  v16 = *(volatile uint32_t *)off_10FBB0;
  if ( *(volatile uint32_t *)off_10FBB0 > (unsigned int)v3 || *(volatile uint32_t *)(off_10FBB0 + 4) + v16 < (unsigned int)v3 )
  {
    log_printf("get_pattern: Invalid buffer passed: %x\n", v3);
    v11 = 0;
    goto LABEL_45;
  }
  v11 = *((volatile uint8_t *)v3 - 3);
  if ( v11 != 85 )
  {
LABEL_45:
    if ( *v6 )
    {
      v20 = *v6 - 1;
      v21 = *(volatile uint32_t *)off_10FBA4;
      *v6 = v20;
      if ( !v20 )
      {
        if ( v21 )
          __enable_irq();
      }
    }
    log_printf("SwEr:AllcErrPtrn : %d, buffer: 0x%x\n\r", v11, v3);
    return nullptr;
  }
  if ( v10 > (unsigned int)v3 )
    goto LABEL_36;
  if ( (unsigned int)v3 <= v10 + v9[1] )
    goto LABEL_20;
  if ( (unsigned int)v3 < v16 )
  {
LABEL_37:
    log_printf("set_pattern: Invalid buffer passed: %x\n", v3);
  }
  else
  {
LABEL_36:
    if ( (unsigned int)v3 > v16 + *(volatile uint32_t *)(off_10FBB0 + 4) )
      goto LABEL_37;
LABEL_20:
    *((volatile uint8_t *)v3 - 3) = -86;
  }
  if ( (unsigned int)v3 >= *v9 && (unsigned int)v3 <= *v9 + v9[1]
    || (unsigned int)v3 >= *(volatile uint32_t *)off_10FBB0
    && (unsigned int)v3 <= *(volatile uint32_t *)off_10FBB0 + *(volatile uint32_t *)(off_10FBB0 + 4) )
  {
    *((volatile uint8_t *)v3 - 2) = 1;
  }
  else
  {
    log_printf("set_num_users: Invalid buffer passed: %x\n", v3);
  }
  if ( *v6 )
  {
    v12 = *v6 - 1;
    v13 = *(volatile uint32_t *)off_10FBA4;
    *v6 = v12;
    if ( !v12 )
    {
      if ( v13 )
LABEL_43:
        __enable_irq();
    }
  }
  return v3;
}


// sorted_list_search @ 0x10fbd0
int sorted_list_search(int a1, volatile uint32_t *a2) {
  volatile unsigned int *v4; // r7
  unsigned int v5; // r6
  int v6; // r8
  volatile int *v7; // r5
  unsigned int v8; // r0
  int v9; // cf
  int v10; // r9
  int result; // r0
  int v12; // r3
  int v13; // r2
  volatile int *v14; // r3
  int v15; // r2
  int v16; // r3
  int v17; // r2
  int v18; // r6
  volatile uint16_t *v19; // r9
  int v20; // r6
  int16_t v21; // r3
  int v22; // r0
  int v23; // r3
  int v24; // r3
  int v25; // r2

  if ( !a2 )
    return -1;
  if ( *(volatile uint32_t *)a1 > (unsigned int)a2 || (unsigned int)a2 > *(volatile uint32_t *)a1 + *(volatile uint32_t *)(a1 + 4) )
    return -1;
  if ( (v4 = (volatile unsigned int *)off_10FDFC, (unsigned int)a2 >= *(volatile uint32_t *)off_10FDFC)
    && (unsigned int)a2 <= *(volatile uint32_t *)off_10FDFC + *(volatile uint32_t *)(off_10FDFC + 4)
    || (unsigned int)a2 >= *(volatile uint32_t *)off_10FE08
    && (unsigned int)a2 <= *(volatile uint32_t *)off_10FE08 + *(volatile uint32_t *)(off_10FE08 + 4) )
  {
    v5 = *((volatile uint8_t *)a2 - 4);
  }
  else
  {
    log_printf("get_native_pool_id: Invalid buffer passed: %x\n", a2);
    v5 = 0;
  }
  if ( *(volatile uint8_t *)(a1 + 8) <= v5 )
    return -1;
  v6 = *(volatile uint32_t *)(a1 + 12);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_10FE00 = 1;
  }
  v7 = (volatile int *)off_10FE04;
  v8 = *v4;
  v9 = (unsigned int)a2 >= *v4;
  ++*(volatile uint32_t *)off_10FE04;
  if ( !v9 || (unsigned int)a2 > v4[1] + v8 )
  {
    v14 = (volatile int *)off_10FE08;
    v15 = *(volatile uint32_t *)off_10FE08;
    if ( (unsigned int)a2 < *(volatile uint32_t *)off_10FE08 || (unsigned int)a2 > *(volatile uint32_t *)(off_10FE08 + 4) + v15 )
    {
      log_printf("get_pattern: Invalid buffer passed: %x\n", a2);
    }
    else
    {
      v10 = *((volatile uint8_t *)a2 - 3);
      if ( v10 == 170 )
      {
        if ( (unsigned int)a2 < v8 )
          goto LABEL_37;
        goto LABEL_15;
      }
      if ( v10 == 255 )
      {
        if ( (unsigned int)a2 < v8 )
          goto LABEL_36;
        goto LABEL_15;
      }
    }
LABEL_24:
    if ( *v7 )
    {
      v16 = *v7 - 1;
      v17 = *(volatile uint32_t *)off_10FE00;
      *v7 = v16;
      if ( !v16 )
      {
        if ( v17 )
          __enable_irq();
      }
    }
    return -1;
  }
  v10 = *((volatile uint8_t *)a2 - 3);
  if ( v10 == 170 )
  {
    result = (uint8_t)(*((volatile uint8_t *)a2 - 2) - 1);
    *((volatile uint8_t *)a2 - 2) = result;
    if ( result )
    {
LABEL_17:
      if ( *v7 )
      {
        v12 = *v7 - 1;
        v13 = *(volatile uint32_t *)off_10FE00;
        *v7 = v12;
        if ( !v12 )
        {
          if ( v13 )
            __enable_irq();
        }
      }
      return (char)result;
    }
LABEL_40:
    v18 = 3 * v5;
    v19 = (volatile uint16_t *)(v6 + 4 * v18);
    v20 = 4 * v18;
    if ( *v19 < (unsigned int)v19[1] )
    {
      if ( (unsigned int)a2 >= *v4 && (unsigned int)a2 <= *v4 + v4[1]
        || (unsigned int)a2 >= *(volatile uint32_t *)off_10FE08
        && (unsigned int)a2 <= *(volatile uint32_t *)off_10FE08 + *(volatile uint32_t *)(off_10FE08 + 4) )
      {
        *((volatile uint8_t *)a2 - 3) = 85;
      }
      else
      {
        log_printf("set_pattern: Invalid buffer passed: %x\n", a2);
      }
      if ( (unsigned int)a2 >= *v4 && (unsigned int)a2 <= *v4 + v4[1]
        || (unsigned int)a2 >= *(volatile uint32_t *)off_10FE08
        && (unsigned int)a2 <= *(volatile uint32_t *)off_10FE08 + *(volatile uint32_t *)(off_10FE08 + 4) )
      {
        *a2 = *((volatile uint32_t *)v19 + 2);
      }
      else
      {
        log_printf("set_next_buffer_addr: Invalid buffer passed: %x\n", a2);
      }
      v21 = *(volatile uint16_t *)(v6 + v20);
      v22 = *v7;
      *((volatile uint32_t *)v19 + 2) = (int)(uintptr_t)(a2);
      *(volatile uint16_t *)(v6 + v20) = v21 + 1;
      if ( !v22 )
        return 0;
      result = v22 - 1;
      v23 = *(volatile uint32_t *)off_10FE00;
      *v7 = result;
      if ( result || !v23 )
        return 0;
      __enable_irq();
      return result;
    }
    goto LABEL_24;
  }
  if ( v10 != 255 )
    goto LABEL_24;
LABEL_15:
  if ( (unsigned int)a2 <= v8 + v4[1] )
    goto LABEL_16;
  v14 = (volatile int *)off_10FE08;
LABEL_36:
  v15 = *v14;
  if ( (unsigned int)a2 < *v14 )
  {
LABEL_38:
    log_printf("decr_num_users: Invalid buffer passed: %x\n", a2);
    goto LABEL_39;
  }
LABEL_37:
  if ( (unsigned int)a2 > v15 + v14[1] )
    goto LABEL_38;
LABEL_16:
  result = (uint8_t)(*((volatile uint8_t *)a2 - 2) - 1);
  *((volatile uint8_t *)a2 - 2) = result;
  if ( result )
    goto LABEL_17;
LABEL_39:
  if ( v10 != 255 )
    goto LABEL_40;
  if ( (unsigned int)a2 >= *v4 && (unsigned int)a2 <= *v4 + v4[1]
    || (unsigned int)a2 >= *(volatile uint32_t *)off_10FE08
    && (unsigned int)a2 <= *(volatile uint32_t *)off_10FE08 + *(volatile uint32_t *)(off_10FE08 + 4) )
  {
    *((volatile uint8_t *)a2 - 2) = 1;
  }
  else
  {
    log_printf("set_num_users: Invalid buffer passed: %x\n", a2);
  }
  if ( *v7 )
  {
    v24 = *v7 - 1;
    v25 = *(volatile uint32_t *)off_10FE00;
    *v7 = v24;
    if ( !v24 )
    {
      if ( v25 )
        __enable_irq();
    }
  }
  return 1;
}


// mem_is_in_heap @ 0x10fe24
/* luna: Checks whether an address lies within either of two configured heap regions by comparing it against each region's base address and size. */
BOOL mem_is_in_heap(unsigned int a1) {
  if ( *(volatile uint32_t *)off_10FE54 <= a1 && a1 <= *(volatile uint32_t *)off_10FE54 + *((volatile uint32_t *)off_10FE54 + 1) )
    return 1;
  if ( a1 < *(volatile uint32_t *)off_10FE58 )
    return 0;
  return a1 <= *(volatile uint32_t *)off_10FE58 + *((volatile uint32_t *)off_10FE58 + 1);
}



// mem_region_init @ 0x10fe5c
int mem_region_init(int a1, int a2, int a3) {
  volatile uint32_t *v3; // r3
  volatile uint32_t *v4; // r3

  v3 = (void *)(uintptr_t)(off_10FEA0);
  *((volatile uint32_t *)off_10FEA0 + 3) = dword_10FEA4;
  *v3 = a2;
  v3[1] = a3;
  *((volatile uint8_t *)v3 + 8) = 4;
  ke_msg_send((void *)(v3), a1, 0x20u);
  v4 = (void *)(uintptr_t)(off_10FEA8);
  *((volatile uint32_t *)off_10FEA8 + 5) = 4;
  v4[1] = 0x10000;
  v4[3] = 131074;
  v4[6] = 0x40000;
  *v4 = 1;
  v4[2] = 1;
  v4[4] = 0;
  *((volatile uint16_t *)v4 + 14) = 0;
  return 0x40000;
}



// mem_alloc_checked @ 0x10feac
volatile uint32_t * mem_alloc_checked(char a1) {
  volatile uint32_t *v2; // r4

  if ( **(volatile uint8_t **)off_10FEEC == 1 )
    v2 = (void *)(uintptr_t)(irq_disable_set_flag_2());
  else
    v2 = list_iterate(dword_10FEF0, 0x7Cu);
  if ( !v2 )
    return v2;
  if ( mem_is_in_heap((unsigned int)v2) )
  {
    *((volatile uint8_t *)v2 - 1) = a1;
    return v2;
  }
  log_printf("set_user_id: Invalid buffer passed: %x\n", v2);
  return v2;
}


