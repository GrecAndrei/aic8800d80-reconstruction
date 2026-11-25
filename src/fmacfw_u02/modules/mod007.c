// check_mmio_and_mem @ 0x111390
/* luna: Processes pending SDIO interrupt status bits, acknowledges hardware sources, and dispatches corresponding events. */
int check_mmio_and_mem() {
  int interrupt_status; // r4
  volatile uint32_t *v1; // r0
  int v2; // r1
  volatile uint32_t *v3; // r2
  volatile uint8_t *v4; // r6
  unsigned int v5; // r1
  unsigned int v6; // r2
  int v7; // r5
  unsigned int v8; // r2
  volatile char *v9; // r3
  volatile uint32_t *v10; // r7
  volatile uint32_t *v11; // r0
  int v12; // r3
  volatile char *v13; // r1
  int v14; // r2
  volatile uint32_t *v15; // r0
  volatile uint8_t *v16; // r5
  unsigned int v17; // r1
  unsigned int v18; // r2
  int result; // r0
  volatile int *v20; // r5
  int v21; // r2
  volatile uint8_t *v22; // r0
  unsigned int v23; // r1
  unsigned int v24; // r2
  volatile uint32_t *v25; // r3
  volatile int *v26; // r5
  int v27; // r2
  volatile uint16_t *v28; // r0
  unsigned int v29; // r2
  volatile uint32_t *v30; // r3
  unsigned int v31; // r3
  volatile uint32_t *v32; // r7
  volatile uint32_t *v33; // r1
  unsigned int v34; // r3
  volatile char *v35; // r2
  volatile uint32_t *v36; // r5
  int v37; // r6
  int v38; // r7
  unsigned int v39; // r3
  volatile char *v40; // r2
  int v41; // r5
  int v42; // r1
  int v43; // r1
  volatile uint32_t *v44; // r2
  int int2dev_status; // r5
  volatile uint8_t *pre_sleep_flag; // r6
  volatile uint32_t *v47; // r2

  interrupt_status = *(volatile uint32_t *)off_111618;
  if ( **(volatile int16_t **)off_111614 < 0 && !interrupt_status )
  {
    call_shared_handler((int)aIntStatus0, (int)aSdioIsr, 39);
    goto LABEL_10;
  }
  if ( (interrupt_status & 0x2000) != 0 )
  {
    v44 = (void *)(uintptr_t)(off_111834);
    int2dev_status = *(volatile uint32_t *)off_111848;
    *(volatile uint32_t *)off_111848 = *(volatile uint32_t *)off_111848;
    *v44 &= ~0x20u;
    check_status_bits(2, "int2dev:%d\n", int2dev_status);
    if ( (int2dev_status & 4) != 0 )
    {
      *(volatile uint8_t *)off_111854 = 1;
      check_status_bits(2, &aClrPreSleep[4]);
    }
    if ( (int2dev_status & 1) != 0 )
    {
      pre_sleep_flag = (void *)(uintptr_t)(off_111854);
      *(volatile uint32_t *)off_111850 = 16;
      if ( *pre_sleep_flag )
      {
        check_status_bits(2, aClrPreSleep);
        *pre_sleep_flag = 0;
      }
      if ( *(volatile uint8_t *)off_111858 )
      {
        v47 = (void *)(uintptr_t)(off_111878);
        *((volatile uint8_t *)off_111858 + 1) = 1;
        *v47 |= 1u;
        check_status_bits(2, aSoftwk);
      }
      *(volatile uint8_t *)off_11185C = 0;
    }
    if ( (int2dev_status & 2) != 0 )
    {
      *(volatile uint8_t *)off_11185C = 1;
      check_status_bits(2, aBit1);
    }
    if ( (int2dev_status & 8) != 0 )
      event_dispatch(aNotUsed);
  }
  if ( (interrupt_status & 1) != 0 )
  {
    event_dispatch(aSdioHostSoftRe, interrupt_status << 31);
    *(volatile uint32_t *)off_111620 = 1;
  }
  if ( (interrupt_status & 0x20) != 0 )
  {
    read_random_from_mmio(*(volatile uint32_t *)off_111624);
    *(volatile uint32_t *)off_111620 = 32;
  }
  if ( (interrupt_status & 0x4000) != 0 )
  {
    v1 = (void *)(uintptr_t)(off_11162C);
    v2 = *(volatile uint32_t *)off_111628;
    v3 = (void *)(uintptr_t)(off_111630);
    *(volatile uint32_t *)off_111628 = *(volatile uint32_t *)off_111628;
    event_dispatch("sdio func1 error bit:%x, func1 free cnt=%d, func1 free queue2 cnt=%d\r\n", v2, *v3, *v1);
  }
  if ( (interrupt_status & 0x8000) == 0 )
    goto LABEL_10;
  v41 = *(volatile uint32_t *)off_11182C;
  *(volatile uint32_t *)off_11182C = *(volatile uint32_t *)off_11182C;
  event_dispatch("sdio func1 other bit:%x\r\n", v41);
  if ( (v41 & 4) != 0 )
    *(volatile uint32_t *)off_111834 &= ~1u;
  if ( (v41 & 8) == 0 )
  {
LABEL_10:
    if ( (interrupt_status & 0x400000) == 0 )
      goto LABEL_11;
LABEL_60:
    v42 = *(volatile uint32_t *)off_111838;
    *(volatile uint32_t *)off_111838 = *(volatile uint32_t *)off_111838;
    event_dispatch("sdio func2 error bit:%x\r\n", v42);
    if ( (interrupt_status & 0x800000) == 0 )
      goto LABEL_12;
    goto LABEL_61;
  }
  *(volatile uint32_t *)off_111834 &= ~4u;
  if ( (interrupt_status & 0x400000) != 0 )
    goto LABEL_60;
LABEL_11:
  if ( (interrupt_status & 0x800000) == 0 )
    goto LABEL_12;
LABEL_61:
  v43 = *(volatile uint32_t *)off_111840;
  *(volatile uint32_t *)off_111840 = *(volatile uint32_t *)off_111840;
  event_dispatch("sdio func2 other bit:%x\r\n", v43);
LABEL_12:
  if ( (interrupt_status & 0x400) != 0 )
  {
    v4 = (void *)(uintptr_t)(off_111638);
    v5 = *((volatile uint8_t *)off_111638 + 1621);
    v6 = *((volatile uint8_t *)off_111638 + 1622);
    if ( v5 >= v6 )
    {
      event_dispatch("rxused=%d, total=%d\r\n", v5, v6);
    }
    else
    {
      v7 = *(volatile uint32_t *)off_111640;
      v8 = *((volatile uint8_t *)off_111638 + 1620)
         + 1
         - 81
         * ((unsigned int)(((unsigned int)dword_11163C
                          * (uint64_t)((unsigned int)*((volatile uint8_t *)off_111638 + 1620) + 1)) >> 32) >> 6);
      v9 = (volatile char *)off_111638 + 20 * v8;
      v10 = (void *)(uintptr_t)(off_111648);
      *((volatile uint32_t *)v9 + 1) = *(volatile uint32_t *)off_111644;
      v4[1621] = v5 + 1;
      v11 = (void *)(uintptr_t)(off_11164C);
      *((volatile uint32_t *)v9 + 2) = *v10;
      v9[12] = v7;
      v4[1620] = v8;
      v9[13] = BYTE1(v7) & 7;
      *v11 = 16;
      do
        v12 = *v11 & 0x20;
      while ( v12 );
      v13 = &v4[20 * v8];
      v14 = 5 * v8;
      if ( (v13[13] & 4) == 0 )
        v12 = *(volatile uint32_t *)(*((volatile uint32_t *)v13 + 2) + 4);
      v15 = (void *)(uintptr_t)(off_111654);
      *(volatile uint32_t *)off_111650 = v12;
      *v15 = 16;
      cmd_handler_a(dword_111658, (void *)(&v4[4 * v14]));
      unknown_func_12d104(256);
    }
    *(volatile uint32_t *)off_111620 = 1024;
  }
  if ( (interrupt_status & 0x200) != 0 )
  {
    event_dispatch(aUnexpectH2dCon);
    *(volatile uint32_t *)off_111868 = 512;
  }
  if ( (interrupt_status & 0x100) != 0 )
  {
    v16 = (void *)(uintptr_t)(off_111638);
    v17 = *((volatile uint8_t *)off_111638 + 2433);
    v18 = *((volatile uint8_t *)off_111638 + 2434);
    if ( v17 < v18 )
    {
      v37 = *(volatile uint32_t *)off_111820;
      v38 = *(volatile uint32_t *)off_111818;
      v39 = *((volatile uint8_t *)off_111638 + 2432)
          + 1
          - 40
          * ((unsigned int)(((unsigned int)dword_11181C
                           * (uint64_t)((unsigned int)*((volatile uint8_t *)off_111638 + 2432) + 1)) >> 32) >> 5);
      v40 = (volatile char *)off_111638 + 20 * v39;
      *((volatile uint8_t *)off_111638 + 2432) = v39;
      v40[1645] = BYTE1(v37) & 7;
      *((volatile uint32_t *)v40 + 409) = v38;
      *((volatile uint32_t *)v40 + 410) = v38;
      v40[1644] = v37;
      v16[2433] = v17 + 1;
      cmd_handler_a((int)(v16 + 2436), (volatile uint32_t *)v40 + 408);
      unknown_func_12d104(0x400000);
    }
    else
    {
      event_dispatch("msgrxused=%d, total=%d\r\n", v17, v18);
    }
    *(volatile uint32_t *)off_111620 = 256;
  }
  result = interrupt_status << 19;
  if ( (interrupt_status & 0x1000) != 0 )
  {
    if ( *(volatile uint8_t *)off_111660 )
    {
      v20 = (volatile int *)off_111664;
      v21 = BYTE1(((volatile uint32_t *)(uintptr_t)off_111664)[92]);
      *(volatile uint8_t *)off_111660 = 0;
      if ( v21 )
        gpio_set_bit(1);
      else
        gpio_clear_bit(1);
      if ( *((volatile uint8_t *)v20 + 374) == 1 )
        fault_handler((int)(uintptr_t)((volatile uint32_t *)dword_111668));
    }
    v22 = (void *)(uintptr_t)(off_11166C);
    v23 = *((volatile uint8_t *)off_11166C + 3074);
    v24 = *((volatile uint8_t *)off_11166C + 3073);
    if ( v23 < v24 )
    {
      v34 = *((volatile uint8_t *)off_11166C + 3072)
          + 1
          - 192
          * ((unsigned int)(((unsigned int)dword_111684
                           * (uint64_t)((unsigned int)*((volatile uint8_t *)off_11166C + 3072) + 1)) >> 32) >> 7);
      v35 = (volatile char *)off_11166C + 16 * v34;
      *((volatile uint32_t *)v35 + 1) = *(volatile uint32_t *)off_111694;
      v36 = (void *)(uintptr_t)(off_111698);
      v22[3072] = v34;
      *((volatile uint16_t *)v35 + 4) = *v36;
      v22[3074] = v23 + 1;
      cmd_handler_a((int)(v22 + 3080), (void *)(v35));
      result = unknown_func_12d104(128);
    }
    else
    {
      result = event_dispatch("txcused=%d, total=%d\r\n", v23, v24);
    }
    v25 = (void *)(uintptr_t)(off_111674);
    *(volatile uint32_t *)off_111620 = 4096;
    if ( !*v25 )
      *(volatile uint8_t *)off_111678 &= ~1u;
  }
  if ( (interrupt_status & 0x800) != 0 )
  {
    if ( *(volatile uint8_t *)off_111660 )
    {
      v26 = (volatile int *)off_111664;
      v27 = BYTE1(((volatile uint32_t *)(uintptr_t)off_111664)[92]);
      *(volatile uint8_t *)off_111660 = 0;
      if ( v27 )
        gpio_set_bit(1);
      else
        gpio_clear_bit(1);
      if ( *((volatile uint8_t *)v26 + 374) == 1 )
        fault_handler((int)(uintptr_t)((volatile uint32_t *)dword_111668));
    }
    v28 = (void *)(uintptr_t)(off_11166C);
    v29 = *((volatile uint8_t *)off_11166C + 6162);
    if ( *((volatile uint8_t *)off_11166C + 6161) > v29 )
    {
      v31 = *((volatile uint8_t *)off_11166C + 6160)
          + 1
          - 192
          * ((unsigned int)(((unsigned int)dword_111684
                           * (uint64_t)((unsigned int)*((volatile uint8_t *)off_11166C + 6160) + 1)) >> 32) >> 7);
      v32 = (void *)(uintptr_t)(off_111688);
      *((volatile uint8_t *)off_11166C + 6160) = v31;
      v33 = (void *)(&v28[8 * v31 + 1544]);
      v33[1] = *v32;
      v28[8 * v31 + 1548] = *(volatile uint32_t *)off_11168C;
      *((volatile uint8_t *)v28 + 6162) = v29 + 1;
      cmd_handler_a(dword_111690, v33);
      result = unknown_func_12d104(64);
    }
    else
    {
      result = event_dispatch("txcmsgused=%d, msgtotal=%d\r\n", v29, v29);
    }
    v30 = (void *)(uintptr_t)(off_111680);
    *(volatile uint32_t *)off_111620 = 2048;
    if ( !*v30 )
      *(volatile uint8_t *)off_111678 &= ~2u;
  }
  if ( (interrupt_status & 4) != 0 )
    *(volatile uint32_t *)off_111620 = 4;
  if ( (interrupt_status & 8) != 0 )
    *(volatile uint32_t *)off_111620 = 8;
  return result;
}


// mmio_sync @ 0x111884
/* luna: Stores the configured MMIO base and primary register address in shared state, copies a value to the base’s offset-4 register, and sets bits 6–7 in off */
int mmio_sync() {
  int v0; // r3
  volatile int *v1; // r2
  volatile uint32_t *v2; // r1
  int result; // r0
  int v4; // r3
  int v5; // r1
  volatile char *v6; // r3
  volatile uint32_t *v7; // r4
  int v8; // r6
  uint64_t v9; // kr00_8
  uint64_t v10; // kr08_8

  v0 = *(volatile uint32_t *)off_1118FC;
  v1 = (volatile int *)off_111900;
  v2 = (void *)(uintptr_t)(off_111904);
  *(volatile uint32_t *)(v0 + 4) = *(volatile uint32_t *)off_1118F8;
  result = *v1;
  v2[709] = v0;
  v4 = *(volatile uint32_t *)off_111908;
  *(volatile uint8_t *)(result + 3) |= 0xC0u;
  v5 = v4 + 3200;
  do
  {
    *(volatile uint8_t *)(v4 + 3) |= 0xC0u;
    v4 += 8;
  }
  while ( v4 != v5 );
  v6 = (volatile char *)off_11190C;
  v7 = (void *)(uintptr_t)(off_111904);
  v8 = *((volatile uint32_t *)off_11190C + 2);
  v9 = *(volatile uint64_t *)off_11190C;
  *(volatile uint8_t *)(*(volatile uint32_t *)off_11190C + 3) |= 0xC0u;
  *(volatile uint8_t *)(HIDWORD(v9) + 3) |= 0xC0u;
  v10 = *(volatile uint64_t *)(v6 + 12);
  *(volatile uint8_t *)(v8 + 3) |= 0xC0u;
  *(volatile uint8_t *)(v10 + 3) |= 0xC0u;
  *(volatile uint8_t *)(HIDWORD(v10) + 3) |= 0xC0u;
  v7[581] = result;
  return result;
}



// mmio_sync_2 @ 0x111910
/* luna: Programs the MMIO synchronization buffer, triggers and waits for the hardware handshake, then enables the associated path. */
int mmio_sync_2() {
  volatile uint32_t *v0; // r1
  int v1; // r0
  volatile uint32_t *v2; // r3
  int result; // r0

  v0 = *(volatile uint32_t **)off_11195C;
  v1 = *(volatile uint32_t *)off_111960;
  v2 = (void *)(uintptr_t)(off_111964);
  *((volatile uint16_t *)off_111968 + 5) = 0;
  *v0 = 167772160;
  v0[1] = v1;
  v2[4] = v2[4] & 0xFFFFF81F | 0x20;
  do
    result = v2[4] & 0x20;
  while ( result );
  v2[578] = v2[578];
  v2[581] = (int)(uintptr_t)(v0);
  v2[576] |= 0x84000000;
  return result;
}



// table_lookup_entry @ 0x11196c
/* luna: Clears the indexed 16-byte table slot and invokes its callback with (0, 0, 1) if the slot's byte at offset 8 was nonzero. */
int table_lookup_entry(int a1) {
  int v2; // r0
  int v3; // r5
  int result; // r0
  int ( *v5)(uint32_t, uint32_t, int); // r3

  v2 = dword_11199C + 16 * (a1 - 1);
  v3 = *(volatile uint8_t *)(v2 + 8);
  result = (int)memset((volatile int *)v2, 0, 0x10u);
  if ( v3 )
  {
    result = dword_1119A0;
    v5 = *(int ( **)(uint32_t, uint32_t, int))(dword_1119A0 + 4 * a1 + 32);
    if ( v5 )
      return v5(0, 0, 1);
  }
  return result;
}


// table_lookup_entry_2 @ 0x1119a4
/* luna: Clears the 16-byte entry at index `entry_index - 1` and invokes its indexed callback with `(0, 0, 1)` if the entry's byte at offset 11 is nonzero. */
volatile int * table_lookup_entry_2(int a1) {
  int v2; // r0
  int v3; // r5
  volatile int *result; // r0
  int ( *v5)(uint32_t, uint32_t, int); // r3

  v2 = dword_1119D4 + 16 * (a1 - 1);
  v3 = *(volatile uint8_t *)(v2 + 11);
  result = memset((volatile int *)v2, 0, 0x10u);
  if ( v3 )
  {
    v5 = *(int ( **)(uint32_t, uint32_t, int))(dword_1119D8 + 4 * (a1 + 13));
    if ( v5 )
      return (volatile int *)v5(0, 0, 1);
  }
  return result;
}



// table_lookup_wrapper @ 0x1119dc
/* luna: Calls both table lookup routines for indices 1 through 5 and returns the second routine’s result for index 5. */
volatile int *table_lookup_wrapper() {
  int i; // r4
  int v1; // r0
  volatile int *result; // r0
  int v3; // [sp+4h] [bp-4h]

  for ( i = 1; i != 6; ++i )
  {
    v1 = (uint8_t)i;
    v3 = (uint8_t)i;
    table_lookup_entry(v1);
    result = table_lookup_entry_2(v3);
  }
  return result;
}



// mmio_set_bit @ 0x1119fc
/* luna: Initializes the USB controller registers and dispatches the USB-init-complete event. */
int mmio_set_bit() {
  volatile uint32_t *v0; // r2
  volatile uint32_t *v1; // r2
  volatile uint32_t *v2; // r1
  volatile uint32_t *v3; // r2
  volatile uint32_t *v4; // r1
  int v5; // r3
  volatile uint32_t *v6; // r2

  v0 = (void *)(uintptr_t)(off_111AF0);
  *((volatile uint32_t *)off_111AF0 + 4) |= 1u;
  while ( (v0[4] & 1) != 0 )
    ;
  v1 = (void *)(uintptr_t)(off_111AF0);
  while ( *((volatile int *)off_111AF0 + 4) >= 0 )
    ;
  v2 = (void *)(uintptr_t)(off_111AF0);
  *((volatile uint32_t *)off_111AF0 + 3) |= 0x40000007u;
  v1[3] = v1[3] & 0xFFFFC0FF | 0x2700;
  v1[4] |= 1u;
  while ( (v2[4] & 1) != 0 )
    ;
  v3 = (void *)(uintptr_t)(off_111AF0);
  while ( *((volatile int *)off_111AF0 + 4) >= 0 )
    ;
  v4 = (void *)(uintptr_t)(off_111AF0);
  *((volatile uint32_t *)off_111AF0 + 3) |= 0x40000007u;
  v3[3] = v3[3] & 0xFFFFC0FF | 0x2700;
  v3[512] &= 0xFFFFE7FC;
  v3[512] |= 0x800004u;
  v3[6] = 0;
  v5 = 1;
  v3[5] = -1;
  v3[519] = 0;
  v3[517] = 0;
  v3[516] = 0;
  while ( 1 )
  {
    v6 = &v4[8 * v5 - 16];
    if ( v5 != 1 )
      break;
    v4[706] = -1;
    v4[578] = -1;
LABEL_11:
    ++v5;
  }
  v6[714] = -1;
  v6[586] = -1;
  if ( v5 != 6 )
    goto LABEL_11;
  v4[6] = dword_111AF4;
  v4[513] &= ~2u;
  v4[513] |= 0x8000u;
  v4[2] = 46;
  v4[2] |= 1u;
  return event_dispatch(aUsbInitDone);
}


// bt_cmd_handler @ 0x111afc
/* luna: Copies a packet into the shared TX buffer, builds its descriptor, and submits it to the hardware transmit path. */
int bt_cmd_handler(int result, int a2) {
  volatile int *v2; // r4
  int v3; // r5
  int v4; // r3
  char v5; // r2
  volatile uint32_t *v6; // r2

  v2 = (volatile int *)off_111B58;
  v3 = *(volatile uint32_t *)off_111B54;
  v4 = *(volatile uint32_t *)off_111B58;
  *((volatile uint16_t *)off_111B5C + 5) = a2;
  if ( a2 == 64 )
    v5 = -54;
  else
    v5 = -50;
  *(volatile uint32_t *)v4 = -1073741824;
  *(volatile uint32_t *)(v4 + 4) = v3;
  *(volatile uint8_t *)(v4 + 3) = v5;
  *(volatile uint16_t *)v4 = a2;
  if ( result && a2 )
  {
    result = (int)(uintptr_t)(memcpy((void *)(uintptr_t)(v3), (void *)(uintptr_t)(result), a2));
    v4 = *v2;
  }
  v6 = (void *)(uintptr_t)(off_111B60);
  *(volatile uint8_t *)(v4 + 3) &= 0x3Fu;
  v6[578] = v6[578];
  v6[581] = v4;
  v6[576] |= 0x84000000;
  return result;
}



// unknown_15 @ 0x111b64
/* luna: Applies set and clear masks to a selected MMIO control word, performs any required hardware handshakes, and returns the corresponding table entry. */
volatile int * unknown_15(int a1, int a2, int a3) {
  volatile uint32_t *v3; // r6
  volatile int *v4; // r5
  int v5; // r7
  volatile uint32_t *v6; // r4

  if ( a1 )
  {
    v3 = (volatile uint32_t *)(dword_111C08 + 32 * (a1 - 1) + 8);
    v4 = (volatile int *)(dword_111C08 + 32 * (a1 - 1));
  }
  else
  {
    v3 = (volatile uint32_t *)dword_111C14;
    v4 = (volatile int *)dword_111C18;
  }
  v5 = *v4;
  if ( (*v4 & 0x80008000) != 0 && ((dword_111C0C & v5) != 0x20000 || a2 != 0x8000000 || a3) )
  {
    v6 = (void *)(uintptr_t)(off_111C10);
    *((volatile uint32_t *)off_111C10 + 513) |= 0x200u;
    while ( (v6[5] & 0x80) == 0 )
      ;
    *v4 |= a2 | 0x8008000;
    if ( a3 )
      *v4 &= ~a3;
    if ( !a1 )
      goto LABEL_10;
    if ( v5 < 0 )
    {
      *v3 = 2;
      *v4 |= 0x40000000u;
      while ( (*v3 & 2) == 0 )
        ;
      if ( (v5 & 0x8000) != 0 )
        goto LABEL_10;
    }
    else if ( (v5 & 0x8000) != 0 )
    {
LABEL_10:
      *((volatile uint32_t *)off_111C10 + 513) |= 0x400u;
      return (void *)(uintptr_t)(table_lookup_entry(a1));
    }
    *v4 &= ~0x8000u;
    goto LABEL_10;
  }
  return (void *)(uintptr_t)(table_lookup_entry(a1));
}



// unknown_16 @ 0x111c1c
/* luna: Updates a flash device’s configuration flags, performs any required controller handshake, and returns its table entry for nonzero device indices. */
int unknown_16(int a1, int a2, int a3) {
  int v3; // r6
  volatile uint32_t *v4; // r4
  int v5; // r5
  volatile uint32_t *v6; // r3
  volatile uint32_t *v7; // r2

  if ( a1 )
  {
    v3 = 32 * (a1 - 1);
    v4 = (volatile uint32_t *)(dword_111CFC + v3);
    v5 = *(volatile uint32_t *)(v3 + dword_111CFC);
    if ( (v5 & 0x80008000) == 0 )
      return (int)table_lookup_entry_2(a1);
    v6 = (volatile uint32_t *)(dword_111CFC + v3 + 8);
    if ( (dword_111D00 & v5) == 0x20000 )
      goto LABEL_4;
    goto LABEL_15;
  }
  v4 = (void *)(uintptr_t)(off_111D08);
  v5 = *(volatile uint32_t *)off_111D08;
  if ( (*(volatile uint32_t *)off_111D08 & 0x80008000) != 0 )
  {
    v6 = (volatile uint32_t *)dword_111D0C;
    if ( (dword_111D00 & v5) == 0x20000 )
    {
LABEL_4:
      if ( a2 == 0x8000000 )
      {
        if ( !a3 )
          goto LABEL_11;
        *v6 = 64;
        *v4 |= 0x8008000u;
LABEL_27:
        *v4 &= ~a3;
LABEL_7:
        v7 = (void *)(uintptr_t)(off_111D04);
        *((volatile uint32_t *)off_111D04 + 4) = (a1 << 6) | 0x20;
        while ( (v7[4] & 0x20) != 0 )
          ;
        if ( (v5 & 0x8000) == 0 )
          *v4 &= ~0x8000u;
LABEL_11:
        if ( !a1 )
          return a1;
        return (int)table_lookup_entry_2(a1);
      }
      *v6 = 64;
      *v4 |= a2 | 0x8008000;
LABEL_6:
      if ( !a3 )
        goto LABEL_7;
      goto LABEL_27;
    }
LABEL_15:
    *v6 = 64;
    *v4 |= a2 | 0x8008000;
    if ( v5 < 0 )
    {
      if ( (v5 & 0x20000) == 0 )
      {
        while ( (*v6 & 0x40) == 0 )
          ;
        *v6 = 64;
      }
      if ( a3 )
        *v4 &= ~a3;
      *v6 = 2;
      *v4 |= 0x40000000u;
      while ( (*v6 & 2) == 0 )
        ;
      goto LABEL_7;
    }
    goto LABEL_6;
  }
  return a1;
}



// mmio_bank_read @ 0x111d10
/* luna: Selects one of two MMIO bases, reads the 32-bit register at the requested 32-byte bank index, and returns bit 21. */
int mmio_bank_read(int a1, int a2) {
  volatile uint32_t *v2; // r0
  int v4; // r0

  if ( a2 )
  {
    if ( a1 == 1 )
      v4 = dword_111D3C;
    else
      v4 = dword_111D40;
    return (*(volatile uint32_t *)(v4 + 32 * a2) >> 21) & 1;
  }
  else
  {
    if ( a1 == 1 )
      v2 = (volatile uint32_t *)dword_111D3C;
    else
      v2 = (volatile uint32_t *)dword_111D40;
    return (*v2 >> 21) & 1;
  }
}


// flash_erase_main @ 0x111d44
/* luna: Dispatches an operation for values 0–5 to one of two flash-related backends based on whether the first pointer is non-null. */
volatile int * flash_erase_main(volatile int *result, unsigned int a2) {
  if ( result )
  {
    if ( a2 <= 5 )
      return (volatile int *)unknown_16(a2, 0x8000000, 0);
  }
  else if ( a2 <= 5 )
  {
    return unknown_15(a2, 0x8000000, 0);
  }
  return result;
}



// flash_erase_area @ 0x111d68
/* luna: For area indices 0–5, dispatches to one of two handlers with a fixed 2 MiB argument based on whether the first argument is non-NULL; otherwise returns */
volatile int * flash_erase_area(volatile int *result, unsigned int a2) {
  if ( result )
  {
    if ( a2 <= 5 )
      return (volatile int *)unknown_16(a2, 0x200000, 0);
  }
  else if ( a2 <= 5 )
  {
    return unknown_15(a2, 0x200000, 0);
  }
  return result;
}



// flash_write_data @ 0x111d8c
/* luna: For selectors 0–5, calls one of two helpers with the fixed flash region depending on whether `result` is non-null; otherwise returns `result` unchange */
volatile int * flash_write_data(volatile int *result, unsigned int a2) {
  if ( result )
  {
    if ( a2 <= 5 )
      return (volatile int *)unknown_16(a2, 0x8000000, 0x200000);
  }
  else if ( a2 <= 5 )
  {
    return unknown_15(a2, 0x8000000, 0x200000);
  }
  return result;
}



// shared_call_check @ 0x111db4
/* luna: Forwards both arguments unchanged to flash_erase_main and returns its result. */
volatile int * shared_call_check(volatile int *result, unsigned int a2) {
  return flash_erase_main(result, a2);
}



// cmd_dispatch @ 0x111db8
/* luna: Validates and stores USB open parameters, initializes the peripheral, and optionally waits for the open state. */
int cmd_dispatch(int a1, int a2) {
  volatile uint8_t *v4; // r6
  volatile int *v5; // r7
  volatile char *v6; // r0
  int v7; // r1
  volatile uint32_t *v8; // r4
  volatile uint32_t *v9; // r3
  volatile uint8_t *v11; // r7
  int v12; // r0
  int v13; // r1
  volatile uint32_t *v14; // r3
  void ( *v15)(int); // r2

  event_dispatch("open:%d/%d\n", 0, a2);
  if ( !a1 )
    return 1;
  if ( !*(volatile uint32_t *)a1 || !*(volatile uint32_t *)(a1 + 4) || !*(volatile uint32_t *)(a1 + 8) || !*(volatile uint32_t *)(a1 + 20) )
    return 2;
  v4 = (void *)(uintptr_t)(off_111EC4);
  if ( *(volatile uint8_t *)off_111EC4 )
    return 3;
  v5 = (volatile int *)off_111EC8;
  v6 = (volatile char *)off_111ECC;
  *(volatile uint8_t *)off_111EC4 = 1;
  memcpy(v6, (volatile char *)a1, 0x50u);
  v7 = v5[97];
  if ( v7 )
  {
    event_dispatch("usb sftdiscon delay %d\n", v7);
    timer_delay(v5[97]);
  }
  v8 = (void *)(uintptr_t)(off_111ED0);
  if ( (*((volatile uint32_t *)off_111ED0 + 512) & 0x7F0) != 0 )
  {
    v11 = (void *)(uintptr_t)(off_111EE8);
    *((volatile uint32_t *)off_111EE8 + 1) = 0;
    *((volatile uint32_t *)v11 + 2) = 0;
    *v11 = 0;
    *v4 = 4;
    v12 = mmio_sync();
    v13 = *(volatile uint32_t *)off_111EEC;
    v14 = *(volatile uint32_t **)off_111EF0;
    *v14 = dword_111EF4;
    v14[1] = v13;
    v8[709] = (int)(uintptr_t)(v14);
    v8[706] = v8[706];
    v15 = *((void ( **)(int))off_111ECC + 19);
    v8[704] |= 0x84000000;
    *v11 = 1;
    if ( v15 )
      v15(v12);
  }
  else
  {
    if ( (*((volatile uint32_t *)off_111ED0 + 2) & 1) != 0 )
    {
      *((volatile uint32_t *)off_111ED0 + 2) &= ~1u;
      v8[513] |= 2u;
    }
    mmio_set_bit();
  }
  event_dispatch(aEnableIrq);
  v9 = (void *)(uintptr_t)(off_111EE0);
  *(volatile uint32_t *)(*((volatile uint32_t *)off_111ED8 + 2) + 320) = off_111EDC;
  v9[2] = 1;
  if ( a2 == 1 )
  {
    while ( *v4 != 4 )
      ;
  }
  event_dispatch(aOpenDone);
  return 0;
}


// state_check_4 @ 0x111efc
/* luna: Queues a data or control request for a valid peripheral channel, updating its MMIO registers, FIFO descriptor state, and pending bits. */
int state_check_4(int result, int a2, int a3, unsigned int a4) {
  int v4; // r6
  unsigned int v7; // r11
  int v8; // r7
  int v9; // r10
  int v10; // r9
  int v11; // r2
  volatile uint16_t *v12; // r4
  int v13; // r1
  volatile uint32_t *v14; // r2
  int v15; // r5
  int v16; // r6
  volatile uint32_t *v17; // r2
  unsigned int v18; // r3
  int v19; // cf

  v4 = a2 - 1;
  if ( (uint8_t)(a2 - 1) <= 4u )
  {
    v7 = a4;
    if ( result )
    {
      if ( (a3 & 0xFD) == 1 )
      {
        if ( a4 > 0x320 )
        {
          v9 = 400;
          v8 = (v8 & ~0xFFFFu) | ((uint16_t)(400) & 0xFFFFu);
          v10 = 26214400;
        }
        else
        {
          v8 = (uint16_t)(2 * ((int)(a4 + 3) >> 2));
          v9 = v8;
          v10 = (uint16_t)v8 << 16;
        }
        if ( a4 > 0x400 )
        {
          v18 = -1025;
          v19 = v7 - 1025 >= 0x400;
          if ( v7 - 1025 < 0x400 )
            v7 >>= 1;
          else
            v18 = ((unsigned int)dword_112040 * (uint64_t)v7) >> 32;
          if ( v19 )
            v7 = (v7 & ~0xFFFFu) | ((uint16_t)(v18 >> 1) & 0xFFFFu);
        }
      }
      else
      {
        v8 = (uint16_t)(2 * ((int)(a4 + 3) >> 2));
        v9 = v8;
        v10 = (uint16_t)v8 << 16;
      }
      if ( (*((volatile uint32_t *)&REG_4020_0900 + 8 * a2) & 0x80008000) != 0 )
        result = (int)(uintptr_t)(flash_erase_main((void *)(uintptr_t)(result), a2));
      v11 = (a3 << 18) & 0xC0000;
      v12 = (void *)(uintptr_t)(off_112038);
      v13 = *(volatile uint16_t *)off_112038;
      *((volatile uint32_t *)&REG_4020_0900 + 8 * a2) = v7 & 0x7FF | v11 | (a2 << 22) | 0x18008000;
      if ( v13 + v9 > 2048 )
      {
        result = log_printf("FIFO ERROR: overflow, addr is %d, size is %d, Total RAM is %d", v13, v9, 2048);
        v13 = (uint16_t)*v12;
      }
      v14 = (void *)(uintptr_t)(off_11203C);
      *((volatile uint32_t *)off_11203C + v4 + 65) = v13 | v10;
      v15 = (1 << a2) | v14[519];
      *v12 = v8 + v13;
      v14[519] = v15;
    }
    else
    {
      v16 = 32 * a2 + 1075838976;
      if ( (*((volatile uint32_t *)&REG_4020_0b00 + 8 * a2) & 0x80008000) != 0 )
        result = (int)(uintptr_t)(flash_erase_main(0, a2));
      v17 = (void *)(uintptr_t)(off_11203C);
      *(volatile uint32_t *)(v16 + 2816) = v7 & 0x7FF | (a3 << 18) & 0xC0000 | 0x18008000;
      v17[519] |= 0x10000 << a2;
    }
  }
  return result;
}


// periph_channel_flag @ 0x112048
/* luna: Queues a 4-byte-aligned buffer transfer on an available peripheral DMA channel, clipping its length to the configured maximum. */
int periph_channel_flag(int a1, int a2, unsigned int a3) {
  int channel_index; // r4
  int channel_entry; // r12
  int v5; // r3
  int v6; // r0
  int dma_descriptor; // r0
  unsigned int max_transfer_len; // r7
  int v9; // r4
  char descriptor_flags; // r6

  if ( *(volatile uint8_t *)off_1120E8 != 4 )
    return 1;
  channel_index = a1 - 1;
  if ( (uint8_t)(a1 - 1) > 5u )
    return 2;
  if ( a2 << 30 )
  {
    log_printf(aErrAlignmentEr);
    return 3;
  }
  else
  {
    channel_entry = dword_1120EC + 16 * channel_index;
    if ( *(volatile uint32_t *)channel_entry )
    {
      return 4;
    }
    else
    {
      v5 = 32 * a1 + 1075838976;
      if ( (*((volatile uint32_t *)&REG_4020_0b00 + 8 * a1) & 0x8000) != 0 )
      {
        v6 = dword_1120F0;
        *(volatile uint32_t *)(dword_1120EC + 16 * channel_index) = a2;
        dma_descriptor = *(volatile uint32_t *)(v6 + 4 * channel_index);
        max_transfer_len = dword_1120F4;
        *(volatile uint8_t *)(channel_entry + 8) = 1;
        v9 = 32 * channel_index + 1075838976;
        descriptor_flags = *(volatile uint8_t *)(dma_descriptor + 3) & 0x31;
        if ( a3 >= max_transfer_len )
          a3 = max_transfer_len;
        *(volatile uint32_t *)(channel_entry + 4) = a3;
        *(volatile uint16_t *)dma_descriptor = a3;
        *(volatile uint32_t *)(dma_descriptor + 4) = a2;
        *(volatile uint8_t *)(dma_descriptor + 3) = descriptor_flags | 0xE;
        *(volatile uint32_t *)(v9 + 2868) = dma_descriptor;
        *(volatile uint32_t *)(v5 + 2816) |= 0x84000000;
        return 0;
      }
      else
      {
        return 5;
      }
    }
  }
}


// state_check_4_b @ 0x1120fc
/* luna: For the indexed peripheral block, clears bit 31 and sets bit 26 in the register at offset 0xB00 when bit 31 is set, then returns the block base addres */
int state_check_4_b(int a1) {
  int result; // r0
  int v2; // r3

  result = 32 * a1 + 1075838976;
  v2 = *(volatile uint32_t *)(result + 2816);
  if ( v2 < 0 )
    *(volatile uint32_t *)(result + 2816) = v2 & 0x7BFFFFFF | 0x4000000;
  return result;
}



// global_copy_u16 @ 0x11211c
/* luna: Validates a 1-based peripheral DMA channel and aligned buffer, caps the transfer length, then fills its descriptor and programs the channel registers  */
int global_copy_u16(int a1, int a2, unsigned int a3) {
  int v3; // r4
  int v4; // r12
  int v5; // r3
  int v6; // r0
  int v7; // r0
  unsigned int v8; // r7
  int v9; // r4
  char v10; // r6

  if ( *(volatile uint8_t *)off_1121C0 != 4 )
    return 1;
  v3 = a1 - 1;
  if ( (uint8_t)(a1 - 1) > 5u )
    return 2;
  if ( a2 << 30 )
  {
    log_printf(aErrAlignmentEr);
    return 3;
  }
  else
  {
    v4 = dword_1121C4 + 16 * v3;
    if ( *(volatile uint32_t *)v4 )
    {
      return 4;
    }
    else
    {
      v5 = 32 * a1 + 1075838976;
      if ( (*((volatile uint32_t *)&REG_4020_0b00 + 8 * a1) & 0x8000) != 0 )
      {
        v6 = dword_1121C8;
        *(volatile uint32_t *)(dword_1121C4 + 16 * v3) = a2;
        v7 = *(volatile uint32_t *)(v6 + 4 * v3);
        v8 = dword_1121CC;
        *(volatile uint8_t *)(v4 + 8) = 1;
        v9 = 32 * v3 + 1075838976;
        v10 = *(volatile uint8_t *)(v7 + 3) & 0x31;
        if ( a3 >= v8 )
          a3 = v8;
        *(volatile uint32_t *)(v4 + 4) = a3;
        *(volatile uint16_t *)v7 = a3;
        *(volatile uint32_t *)(v7 + 4) = a2;
        *(volatile uint8_t *)(v7 + 3) = v10 | 0xE;
        *(volatile uint32_t *)(v9 + 2868) = v7;
        *(volatile uint32_t *)(v5 + 2816) = *(volatile uint32_t *)(v5 + 2816) & 0x7BFFFFFF | 0x80000000;
        return 0;
      }
      else
      {
        return 5;
      }
    }
  }
}


// arg_store @ 0x1121d4
/* luna: Copies the pending 16-bit value, treats zero as a successful status-3 case, and otherwise sets status 4 and state 7 only when callback slot 5 accepts  */
int arg_store() {
  volatile uint8_t *v0; // r4
  int v1; // r0
  int ( *v3)(uint32_t); // r3

  v0 = (void *)(uintptr_t)(off_112218);
  v1 = *((volatile uint16_t *)off_112218 + 7);
  *(volatile uint16_t *)off_11221C = v1;
  if ( v1 )
  {
    v3 = *((int ( **)(uint32_t))off_112224 + 5);
    if ( v3 && v3((uint8_t)v1) )
    {
      *(volatile uint8_t *)off_112220 = 4;
      *v0 = 7;
      if ( !is_flag_one() )
        store_byte_field(0);
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    *(volatile uint8_t *)off_112220 = 3;
    return 1;
  }
}



// rf_init @ 0x112228
/* luna: Advances an EP0 control transfer by sending at most one 64-byte packet and tracking progress against the setup request length. */
int rf_init(uint64_t a1, volatile uint32_t *a2) {
  int v2; // r4
  volatile uint8_t *ep0_context; // r5
  void *v4; // r6
  volatile uint8_t *v5; // r3
  uint8_t v6; // r2
  int v7; // r3
  volatile uint32_t *v8; // r3
  int ( **v9)(int, unsigned int); // r4
  int ( *v10)(void *); // r1
  volatile uint8_t *v11; // r8
  char v12; // r2
  int v13; // r7
  int v14; // r0
  int ep0_state; // r3
  int v16; // r3
  volatile uint32_t *v17; // r2
  int v18; // r3
  volatile uint32_t *v19; // r3
  volatile uint32_t *v20; // r3
  int v21; // r1
  volatile uint32_t *v22; // r2
  volatile uint32_t *v23; // r3
  int v24; // r3
  volatile uint32_t *v25; // r2
  volatile uint32_t *v26; // r3
  volatile uint32_t *v27; // r2
  int v28; // r0
  volatile uint32_t *v29; // r3
  int v30; // r3
  void *v31; // r3
  unsigned int v32; // r0
  unsigned int v33; // r1
  int v34; // r1
  int ( *v35)(int, unsigned int); // r3
  volatile uint8_t *v36; // r3
  volatile uint16_t *v37; // r3
  void *v38; // r2
  int v39; // r4
  unsigned int v40; // r1
  volatile uint8_t *v41; // r0
  int v42; // r3
  unsigned int v43; // r3
  volatile uint8_t *v44; // r0
  volatile uint8_t *v45; // r0
  uint16_t v46; // r2
  uint16_t v47; // r3
  char v48; // r3
  char v49; // r3
  volatile uint32_t *v50; // r4
  int v51; // r0
  volatile int *v52; // r8
  int v53; // r7
  int v54; // r3
  int v55; // r7
  volatile uint32_t *v56; // r2
  volatile uint32_t *v57; // r3
  uint16_t bytes_sent; // r2
  int v59; // r6
  unsigned int updated_bytes_sent; // r2
  unsigned int v61; // r1
  volatile uint32_t *v62; // r2
  void ( *v63)(volatile uint8_t *); // r3
  volatile uint32_t *v64; // r2
  int v65; // r0
  volatile uint32_t *v66; // r3
  unsigned int v67; // r0
  int v68; // r0

  v2 = HIDWORD(a1);
  if ( (uint32_t)a1 )
  {
    ep0_context = (volatile uint8_t *)off_112534;
    ep0_state = *(volatile uint8_t *)off_112534;
    if ( ep0_state == 2 )
    {
      v4 = (void *)(uintptr_t)(off_112538);
      log_printf(aEp0SetupErrorD, HIDWORD(a1), a2);
      goto LABEL_7;
    }
    if ( (a1 & 0x100000000LL) == 0 )
      goto LABEL_18;
    if ( ep0_state == 4 )
    {
      a1 = (a1 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(*((volatile uint16_t *)off_112534 + 4)) << 32);
      bytes_sent = *((volatile uint16_t *)off_112534 + 5);
      a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)((uint16_t)(WORD2(a1) - bytes_sent)) & 0xFFFFFFFFu);
      if ( WORD2(a1) == bytes_sent )
      {
        *(volatile uint8_t *)off_112534 = 5;
        return a1;
      }
      if ( (uint32_t)a1 == 64 )
      {
        v59 = 1;
      }
      else
      {
        if ( (unsigned int)a1 >= 0x40 )
          a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)(64) & 0xFFFFFFFFu);
        v59 = 0;
      }
      updated_bytes_sent = (uint16_t)(bytes_sent + a1);
      *((volatile uint16_t *)off_112534 + 5) = updated_bytes_sent;
      if ( HIDWORD(a1) < updated_bytes_sent )
      {
        a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)(log_printf("Ep0 send length err %u-%u", HIDWORD(a1), updated_bytes_sent)) & 0xFFFFFFFFu);
        a1 = (a1 & ~0xFFFF0000u) | (((uint16_t)(*((volatile uint16_t *)ep0_context + 4)) & 0xFFFFu) << 16);
        updated_bytes_sent = *((volatile uint16_t *)ep0_context + 5);
      }
      v61 = (uint16_t)(WORD2(a1) - updated_bytes_sent);
      if ( v61 > 0x40 )
      {
        v61 = 64;
      }
      else if ( !v61 )
      {
        if ( !v59 )
        {
          v62 = (void *)(uintptr_t)(off_1129D0);
          *ep0_context = 5;
          v62[516] |= 0x10u;
          return a1;
        }
        a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)(bt_cmd_handler((int)(uintptr_t)(nullptr), 0)) & 0xFFFFFFFFu);
        goto LABEL_18;
      }
      a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)(bt_cmd_handler((int)(uintptr_t)((volatile char *)(*((volatile uint32_t *)ep0_context + 1) + updated_bytes_sent)), v61)) & 0xFFFFFFFFu);
LABEL_18:
      if ( (v2 & 0x20) == 0 )
        return a1;
LABEL_19:
      if ( *ep0_context == 6 )
      {
        v27 = *(volatile uint32_t **)off_112538;
        v28 = *(volatile uint32_t *)off_112544;
        v29 = (void *)(uintptr_t)(off_11253C);
        *v27 = dword_112548;
        v27[1] = v28;
        v29[709] = (int)(uintptr_t)(v27);
        v29[706] = v29[706];
        v29[704] |= 0x84000000;
        *ep0_context = 7;
        v29[517] |= 0x10u;
        a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)(mmio_sync_2()) & 0xFFFFFFFFu);
      }
      return a1;
    }
    if ( ep0_state != 7 )
      goto LABEL_18;
    v23 = (void *)(uintptr_t)(off_11253C);
    a1 = (a1 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(off_112550) << 32);
    a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
    *(volatile uint8_t *)off_112534 = 0;
    v23[517] &= ~0x10u;
    v23[516] &= ~0x10u;
    if ( *(volatile uint8_t *)HIDWORD(a1) )
    {
      v23[513] = (16 * (uint8_t)*(volatile uint8_t *)HIDWORD(a1)) & 0x70 | v23[513] & 0xFFFFFF8F;
      *(volatile uint8_t *)HIDWORD(a1) = 0;
    }
  }
  else
  {
    if ( (BYTE4(a1) & 0x21) == 0x21 )
    {
      v17 = (void *)(uintptr_t)(off_11253C);
      if ( (*((volatile uint32_t *)off_11253C + 708) & 0x7F) == 0x40 )
      {
        v18 = *((volatile uint32_t *)off_11253C + 708);
        a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)(v18 << 12) & 0xFFFFFFFFu);
        if ( (v18 & 0x80000) != 0 )
        {
          a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)(*(volatile uint32_t *)off_112544) & 0xFFFFFFFFu);
          v19 = *(volatile uint32_t **)off_112538;
          *v19 = dword_112548;
          v19[1] = a1;
          v17[709] = (int)(uintptr_t)(v19);
          v17[706] = v17[706];
          v17[704] |= 0x84000000;
          return a1;
        }
      }
    }
    if ( (a1 & 0x100000000LL) == 0 )
    {
      ep0_context = (volatile uint8_t *)off_112534;
      v16 = *(volatile uint8_t *)off_112534;
      if ( (a1 & 0x800000000LL) != 0 )
      {
        if ( v16 != 1 )
          return a1;
        goto LABEL_6;
      }
      if ( v16 == 2 )
      {
LABEL_6:
        v4 = (void *)(uintptr_t)(off_112538);
        goto LABEL_7;
      }
      goto LABEL_18;
    }
    if ( (a1 & 0x800000000LL) != 0 )
    {
      ep0_context = (volatile uint8_t *)off_112534;
      if ( !*(volatile uint8_t *)off_112534 )
        goto LABEL_6;
      flash_erase_main((void *)(uintptr_t)(1), 0);
      v4 = (void *)(uintptr_t)(off_112890);
LABEL_7:
      if ( (v2 & 0x40) != 0 )
        v5 = (volatile uint8_t *)(*((volatile uint32_t *)off_11253C + 709) - 8);
      else
        v5 = *(volatile uint8_t **)(*(volatile uint32_t *)v4 + 4);
      *((volatile uint32_t *)ep0_context + 1) = 0;
      *((volatile uint32_t *)ep0_context + 2) = 0;
      *ep0_context = 2;
      ep0_context[12] = ep0_context[12] & 0x7F | (*v5 >> 7 << 7);
      v6 = ep0_context[12] & 0x9F | (32 * (((int)*v5 >> 5) & 3));
      ep0_context[12] = v6;
      ep0_context[12] = v6 & 0xE0 | *v5 & 0x1F;
      ep0_context[13] = v5[1];
      *((volatile uint16_t *)ep0_context + 7) = v5[2] | (v5[3] << 8);
      *((volatile uint16_t *)ep0_context + 8) = v5[4] | (v5[5] << 8);
      v7 = v5[6] | (v5[7] << 8);
      *((volatile uint16_t *)ep0_context + 9) = v7;
      if ( !v7 && (ep0_context[12] & 0x80u) != 0 )
        log_printf(aEp0SetupErrorW);
      v8 = (void *)(uintptr_t)(off_11253C);
      v9 = (int ( **)(int, unsigned int))off_112540;
      v10 = *((int ( **)(void *))off_112540 + 3);
      *((volatile uint32_t *)off_11253C + 517) &= ~0x10u;
      v8[516] &= ~0x10u;
if ( !v10 || !v10((void *)(uintptr_t)(off_112534)) ) { v11 = (void *)(uintptr_t)(off_11255C);
        v12 = *(volatile uint8_t *)off_11255C;
        v13 = *(volatile uint8_t *)off_11255C;
        if ( (ep0_context[12] & 0x60) != 0 )
        {
LABEL_54:
          if ( v13 == 4 && *v11 != 4 )
LABEL_56:
            table_lookup_wrapper();
          goto LABEL_49;
        }
        v14 = ep0_context[13];
        switch ( ep0_context[13] )
        {
          case 0u:
            if ( *(volatile uint8_t *)off_11255C == 4 )
            {
              v30 = ep0_context[12] & 0x1F;
              if ( v30 == 1 )
                goto LABEL_156;
              if ( v30 != 2 )
                goto LABEL_66;
              v67 = *((volatile uint16_t *)ep0_context + 8);
              v40 = v67 & 0xF;
              if ( v40 > 5 )
                goto LABEL_156;
              v14 = (v67 >> 7) & 1;
            }
            else
            {
              if ( *((volatile uint16_t *)ep0_context + 8) )
                goto LABEL_54;
              v30 = ep0_context[12] & 0x1F;
              if ( v30 == 1 )
                goto LABEL_156;
              if ( v30 != 2 )
              {
LABEL_66:
                if ( v30 )
                  goto LABEL_59;
                v31 = (void *)(uintptr_t)(off_112874);
                *(volatile uint16_t *)off_112874 = *(volatile uint8_t *)off_112870;
                goto LABEL_68;
              }
              v40 = ep0_context[13];
            }
            if ( mmio_bank_read(v14, v40) )
            {
              v31 = (void *)(uintptr_t)(off_112874);
              *(volatile uint16_t *)off_112874 = 1;
LABEL_68:
              *((volatile uint32_t *)ep0_context + 1) = (int)(uintptr_t)(v31);
              *((volatile uint16_t *)ep0_context + 4) = 2;
              *ep0_context = 4;
              goto LABEL_86;
            }
LABEL_156:
            v31 = (void *)(uintptr_t)(off_1129E0);
            *(volatile uint16_t *)off_1129E0 = 0;
            goto LABEL_68;
          case 1u:
            if ( *(volatile uint8_t *)off_11255C != 4 && *((volatile uint16_t *)ep0_context + 8) )
              goto LABEL_54;
            if ( (ep0_context[12] & 0x1F) != 2 || *((volatile uint16_t *)ep0_context + 7) )
              goto LABEL_79;
            flash_write_data((void *)(uintptr_t)((*((volatile uint16_t *)ep0_context + 8) >> 7) & 1), *((volatile uint16_t *)ep0_context + 8) & 0xF);
            *ep0_context = 7;
            if ( v13 == 4 )
              goto LABEL_44;
            goto LABEL_73;
          case 3u:
            if ( *(volatile uint8_t *)off_11255C != 4 && *((volatile uint16_t *)ep0_context + 8) )
              goto LABEL_54;
            if ( (ep0_context[12] & 0x1F) != 0 )
            {
              if ( (ep0_context[12] & 0x1F) != 2 || *((volatile uint16_t *)ep0_context + 7) )
              {
LABEL_79:
                *ep0_context = 7;
                if ( v12 == 4 )
                {
LABEL_60:
                  if ( *v11 != 4 )
                    goto LABEL_56;
                }
                goto LABEL_49;
              }
              flash_erase_area((void *)(uintptr_t)((*((volatile uint16_t *)ep0_context + 8) >> 7) & 1), *((volatile uint16_t *)ep0_context + 8) & 0xF);
              *ep0_context = 7;
              if ( v13 != 4 )
                goto LABEL_73;
            }
            else
            {
              v68 = *((volatile uint16_t *)ep0_context + 7);
              if ( v68 != 2 )
              {
                v39 = v68 == 1;
                *ep0_context = 7;
LABEL_89:
                if ( v13 != 4 || *v11 == 4 )
                {
                  if ( v39 )
                    break;
                }
                else
                {
                  table_lookup_wrapper();
                  if ( v39 )
                    break;
                }
                goto LABEL_49;
              }
              *(volatile uint8_t *)off_1129E4 = HIBYTE(*((volatile uint16_t *)ep0_context + 8));
              *ep0_context = 7;
              if ( v12 != 4 )
                goto LABEL_73;
            }
LABEL_44:
            if ( *v11 == 4 )
              goto LABEL_73;
LABEL_45:
            table_lookup_wrapper();
            break;
          case 5u:
            v34 = *((volatile uint16_t *)ep0_context + 7);
            *((volatile uint32_t *)off_112878 + 512) = (16 * v34) & 0x7F0 | *((volatile uint32_t *)off_112878 + 512) & 0xFFFFF80F;
            *ep0_context = 7;
            if ( v34 )
              *v11 = 3;
            else
              *v11 = 2;
            goto LABEL_72;
          case 6u:
            v32 = *((volatile uint16_t *)ep0_context + 7);
            v33 = v32 >> 8;
            switch ( v32 >> 8 )
            {
              case 1u:
                v41 = (volatile uint8_t *)(*v9)(1, v33);
                if ( !v41 )
                  goto LABEL_54;
                v42 = *v41;
                if ( v42 != 18 || v41[1] != 1 )
                  goto LABEL_54;
                goto LABEL_102;
              case 2u:
                v45 = (volatile uint8_t *)v9[1](0, v33);
                if ( !v45 || *v45 != 9 || v45[1] != 2 )
                  goto LABEL_54;
                v46 = (uint8_t)v45[3];
                v47 = (uint8_t)v45[2];
                *((volatile uint32_t *)ep0_context + 1) = (int)(uintptr_t)(v45);
                *((volatile uint16_t *)ep0_context + 4) = v47 | (v46 << 8);
                v48 = *(volatile uint8_t *)off_112870;
                if ( (v45[7] & 0x40) != 0 )
                  v49 = v48 | 1;
                else
                  v49 = v48 & 0xFE;
                *(volatile uint8_t *)off_112870 = v49;
                goto LABEL_103;
              case 3u:
                v44 = (volatile uint8_t *)v9[2]((uint8_t)v32, v33);
                *((volatile uint32_t *)ep0_context + 1) = (int)(uintptr_t)(v44);
                if ( !v44 )
                  goto LABEL_54;
                *((volatile uint16_t *)ep0_context + 4) = *v44;
                goto LABEL_103;
              case 4u:
              case 5u:
                goto LABEL_59;
              case 6u:
                v41 = (volatile uint8_t *)(*v9)(6, v33);
                if ( !v41 )
                  goto LABEL_54;
                v42 = *v41;
                if ( v42 != 10 || v41[1] != 6 )
                  goto LABEL_54;
                goto LABEL_102;
              case 0xFu:
                v41 = (volatile uint8_t *)(*v9)(15, v33);
                if ( !v41 || *v41 != 5 || v41[1] != 15 )
                  goto LABEL_54;
                v42 = (v42 & ~0xFFFFu) | ((uint16_t)(v41[2]) & 0xFFFFu);
LABEL_102:
                *((volatile uint16_t *)ep0_context + 4) = v42;
                *((volatile uint32_t *)ep0_context + 1) = (int)(uintptr_t)(v41);
LABEL_103:
                v43 = *((volatile uint16_t *)ep0_context + 9);
                if ( *((volatile uint16_t *)ep0_context + 4) > v43 )
                  *((volatile uint16_t *)ep0_context + 4) = v43;
                *ep0_context = 4;
                break;
              default:
                log_printf("Unknown descriptor: %d", v33);
                goto LABEL_54;
            }
            goto LABEL_86;
          case 8u:
            *((volatile uint32_t *)ep0_context + 1) = dword_112884;
            *((volatile uint16_t *)ep0_context + 4) = 2;
            *ep0_context = 4;
            goto LABEL_86;
          case 9u:
            v39 = arg_store();
            goto LABEL_89;
          case 0xAu:
            if ( *(volatile uint8_t *)off_11255C != 4 )
              goto LABEL_54;
            v37 = (void *)(uintptr_t)(off_11287C);
            *ep0_context = *(volatile uint8_t *)off_11255C;
            v38 = (void *)(uintptr_t)(off_112880);
            *((volatile uint16_t *)ep0_context + 8) = *v37;
            *((volatile uint32_t *)ep0_context + 1) = (int)(uintptr_t)(v38);
            *((volatile uint16_t *)ep0_context + 4) = 1;
LABEL_86:
            if ( v13 != 4 )
              goto LABEL_87;
            goto LABEL_152;
          case 0xBu:
            v35 = v9[6];
            if ( !v35 || !v35(*((volatile uint16_t *)ep0_context + 8), *((volatile uint16_t *)ep0_context + 7)) )
              goto LABEL_54;
            v36 = (void *)(uintptr_t)(off_112880);
            *(volatile uint16_t *)off_11287C = *((volatile uint16_t *)ep0_context + 8);
            *v36 = *((volatile uint16_t *)ep0_context + 7);
            *ep0_context = 7;
LABEL_72:
            if ( v13 != 4 )
              goto LABEL_73;
LABEL_152:
            if ( *v11 != 4 )
              goto LABEL_45;
            break;
          default:
LABEL_59:
            if ( v13 != 4 )
              goto LABEL_49;
            goto LABEL_60;
        }
      }
      v24 = *ep0_context;
      switch ( v24 )
      {
        case 3:
          if ( !*((volatile uint32_t *)ep0_context + 1) )
            *((volatile uint32_t *)ep0_context + 1) = dword_112558;
          goto LABEL_50;
        case 4:
LABEL_87:
          bt_cmd_handler((int)(uintptr_t)(*((volatile char **)ep0_context + 1)), *((volatile uint16_t *)ep0_context + 4));
          goto LABEL_50;
        case 7:
LABEL_73:
          mmio_sync_2();
          goto LABEL_50;
      }
LABEL_49:
      *ep0_context = 0;
      unknown_15(0, 0x200000, 0);
      unknown_16(0, 0x200000, 0);
LABEL_50:
      v25 = *(volatile uint32_t **)v4;
      a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)(*(volatile uint32_t *)off_112544) & 0xFFFFFFFFu);
      v26 = (void *)(uintptr_t)(off_11253C);
      *v25 = dword_112548;
      v25[1] = a1;
LABEL_51:
      v26[709] = (int)(uintptr_t)(v25);
      v26[706] = v26[706];
      v26[704] |= 0x84000000;
      return a1;
    }
    v4 = (void *)(uintptr_t)(off_112538);
    ep0_context = (volatile uint8_t *)off_112534;
    v20 = *(volatile uint32_t **)off_112538;
    if ( (*(volatile uint8_t *)(*(volatile uint32_t *)off_112538 + 3) & 1) == 0 )
    {
      v21 = *(volatile uint8_t *)off_112534;
      switch ( v21 )
      {
        case 2:
          goto LABEL_7;
        case 3:
          v51 = *((volatile uint16_t *)off_112534 + 5);
          v52 = (volatile int *)off_112888;
          v53 = 64 - *(volatile uint16_t *)v20;
          if ( v53 >= (uint16_t)(*((volatile uint16_t *)off_112534 + 4) - v51) )
            v53 = (v53 & ~0xFFFFu) | ((uint16_t)(*((volatile uint16_t *)off_112534 + 4) - v51) & 0xFFFFu);
          memcpy((volatile char *)(v51 + *((volatile uint32_t *)off_112534 + 1)), *(volatile char **)off_112888, (uint16_t)v53);
          v54 = *((volatile uint16_t *)ep0_context + 4);
          v55 = (uint16_t)(v53 + *((volatile uint16_t *)ep0_context + 5));
          *((volatile uint16_t *)ep0_context + 5) = v55;
          if ( v54 == v55 )
          {
            v63 = *((void ( **)(volatile uint8_t *))off_1129D4 + 4);
            if ( v63 )
              v63(ep0_context);
            a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)(v2 << 26) & 0xFFFFFFFFu);
            if ( (v2 & 0x20) == 0 )
            {
              *ep0_context = 6;
              return a1;
            }
            v64 = *(volatile uint32_t **)v4;
            v65 = *v52;
            v66 = (void *)(uintptr_t)(off_1129D0);
            *v64 = dword_1129DC;
            v64[1] = v65;
            v66[709] = (int)(uintptr_t)(v64);
            v66[706] = v66[706];
            v66[704] |= 0x84000000;
            *ep0_context = 7;
            v66[517] |= 0x10u;
            a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)(mmio_sync_2()) & 0xFFFFFFFFu);
            goto LABEL_19;
          }
          v56 = *(volatile uint32_t **)v4;
          a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)(*v52) & 0xFFFFFFFFu);
          v57 = (void *)(uintptr_t)(off_112878);
          *v56 = dword_11288C;
          v56[1] = a1;
          v57[709] = (int)(uintptr_t)(v56);
          v57[706] = v57[706];
          v57[704] |= 0x84000000;
          break;
        case 5:
          v26 = (void *)(uintptr_t)(off_112878);
          *(volatile uint8_t *)off_112534 = 0;
          v25 = *(volatile uint32_t **)v4;
          v50 = (void *)(uintptr_t)(off_112888);
          a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)(dword_11288C) & 0xFFFFFFFFu);
          v26[517] &= ~0x10u;
          v26[516] &= ~0x10u;
          a1 = (a1 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(*v50) << 32);
          *(volatile uint64_t *)v25 = a1;
          goto LABEL_51;
        default:
          v22 = (void *)(uintptr_t)(off_11253C);
          a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)(*(volatile uint32_t *)off_112544) & 0xFFFFFFFFu);
          *v20 = dword_112548;
          v20[1] = a1;
          v22[709] = (int)(uintptr_t)(v20);
          v22[706] = v22[706];
          v22[704] |= 0x84000000;
          break;
      }
      goto LABEL_18;
    }
    if ( *(volatile uint8_t *)off_112534 )
      a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)(flash_erase_main((void *)(uintptr_t)(1), 0)) & 0xFFFFFFFFu);
    *ep0_context = 1;
  }
  return a1;
}


// mmio_read_flag @ 0x1129e8
/* luna: Performs staged RF hardware initialization, invoking a table helper and polling control/status handshakes for six register entries. */
int mmio_read_flag() {
  volatile uint8_t *v0; // r3
  volatile uint32_t *v1; // r4
  volatile uint32_t *v2; // r3
  volatile int *v3; // r1
  int v4; // r5
  volatile uint32_t *v5; // r4
  int i; // r0
  int v7; // r3
  volatile uint32_t *v8; // r3
  volatile int *v9; // r1
  int v10; // lr
  int v11; // r12
  volatile int *v12; // r6
  int v13; // r5
  int v14; // r0
  volatile int *v15; // r2
  volatile uint32_t *v16; // r4
  volatile uint32_t *v17; // r3
  volatile uint32_t *v18; // r3
  volatile int *v19; // r0
  int result; // r0
  int ( *v21)(uint32_t); // r3
  volatile uint16_t *v22; // r2
  int v23; // r4
  volatile uint32_t *v24; // r1
  volatile uint32_t *v25; // r3
  volatile uint32_t *v26; // r2
  volatile uint32_t *v27; // r3

  v0 = (void *)(uintptr_t)(off_112C34);
  v1 = (void *)(uintptr_t)(off_112C38);
  *(volatile uint8_t *)off_112C30 = 2;
  *v0 = 0;
  v1[896] &= ~1u;
  v1[513] &= ~1u;
  table_lookup_wrapper();
  if ( (v1[6] & 0x80) != 0 )
    v1[6] &= ~0x80u;
  v2 = (void *)(uintptr_t)(off_112C38);
  *((volatile uint32_t *)off_112C38 + 513) |= 0x200u;
  while ( (v2[5] & 0x80) == 0 )
    ;
  v3 = (volatile int *)off_112C3C;
  v4 = dword_112C40;
  v5 = (void *)(uintptr_t)(off_112C3C);
  for ( i = 1; ; ++i )
  {
    if ( i == 1 )
    {
      if ( (*v5 & 0x80008000) != 0 )
        *v5 |= v4;
      goto LABEL_11;
    }
    v7 = *v3;
    if ( (*v3 & 0x80008000) != 0 )
    {
      *v3 |= v4;
      if ( v7 < 0 )
      {
        v3[2] = 2;
        *v3 |= 0x40000000u;
        while ( (v3[2] & 2) == 0 )
          ;
      }
      if ( (v7 & 0x8000) == 0 )
        *v3 &= ~0x8000u;
    }
    if ( i == 6 )
      break;
LABEL_11:
    v3 += 8;
  }
  v8 = (void *)(uintptr_t)(off_112C38);
  *((volatile uint32_t *)off_112C38 + 513) |= 0x400u;
  v8[513] |= 0x80u;
  while ( (v8[5] & 0x40) == 0 )
    ;
  v9 = (volatile int *)off_112C44;
  v10 = dword_112C60;
  v11 = dword_112C40;
  v12 = (volatile int *)off_112C44;
  v13 = 1;
  while ( 2 )
  {
    if ( v13 == 1 )
    {
      v14 = *v12;
      if ( (*v12 & 0x80008000) != 0 )
      {
        v16 = (volatile uint32_t *)v10;
        v15 = v12;
LABEL_20:
        *v16 = 64;
        *v15 |= v11;
        if ( v14 < 0 )
        {
          if ( (v14 & 0x20000) == 0 )
          {
            while ( (*v16 & 0x40) == 0 )
              ;
            *v16 = 64;
          }
          *v16 = 2;
          *v15 |= 0x40000000u;
          while ( (*v16 & 2) == 0 )
            ;
        }
        if ( (v14 & 0x8000) == 0 )
          *v15 &= ~0x8000u;
        goto LABEL_23;
      }
      goto LABEL_24;
    }
    v14 = *v9;
    v15 = v9;
    if ( (*v9 & 0x80008000) != 0 )
    {
      v16 = (void *)(v9 + 2);
      goto LABEL_20;
    }
LABEL_23:
    if ( v13 != 6 )
    {
LABEL_24:
      ++v13;
      v9 += 8;
      continue;
    }
    break;
  }
  v17 = (void *)(uintptr_t)(off_112C38);
  *((volatile uint32_t *)off_112C38 + 4) = 1072;
  while ( (v17[4] & 0x30) != 0 )
    ;
  v17[513] |= 0x100u;
  v17[519] = 65537;
  v17[517] = 41;
  v17[516] = 9;
  v17[6] |= 0xC0000u;
  if ( (v17[18] & 0x80000) != 0 )
  {
    v22 = (void *)(uintptr_t)(off_112C58);
    v23 = dword_112C5C;
    v24 = (void *)(uintptr_t)(off_112C38);
    v17[9] = 285;
    v17[10] = v23;
    *v22 = 318;
    v17[513] |= 0x80u;
    while ( (v24[5] & 0x40) == 0 )
      ;
    while ( *((volatile int *)off_112C38 + 4) >= 0 )
      ;
    v25 = (void *)(uintptr_t)(off_112C38);
    *((volatile uint32_t *)off_112C38 + 4) = 1056;
    while ( (v25[4] & 0x20) != 0 )
      ;
    v26 = (void *)(uintptr_t)(off_112C38);
    v25[513] |= 0x100u;
    v25[513] |= 0x200u;
    while ( (v26[5] & 0x80) == 0 )
      ;
    v27 = (void *)(uintptr_t)(off_112C38);
    v26[4] |= 0x10u;
    while ( (v27[4] & 0x10) != 0 )
      ;
    v27[513] |= 0x400u;
  }
  v18 = (void *)(uintptr_t)(off_112C48);
  v19 = (volatile int *)dword_112C4C;
  *((volatile uint32_t *)off_112C38 + 512) &= 0xFFFFF80F;
  v18[1] = 0;
  v18[2] = 0;
  *(volatile uint8_t *)v18 = 0;
  memset(v19, 0, 0x50u);
  memset((volatile int *)dword_112C50, 0, 0x50u);
  result = mmio_sync();
  v21 = *((int ( **)(uint32_t))off_112C54 + 8);
  if ( v21 )
    return v21(0);
  return result;
}


// get_state_byte @ 0x112c64
/* luna: Returns the `usb_susp` byte through the selected read path and sets a related global byte flag to one. */
int get_state_byte() {
  int result; // r0

  if ( (((volatile uint32_t *)(uintptr_t)off_112C8C)[44] & 0x40000000) != 0 )
    result = (int)read_memory_byte(aUsbSusp_0);
  else
    result = event_dispatch(aUsbSusp);
  *(volatile uint8_t *)off_112C94 = 1;
  return result;
}


// mmio_read_flag_b @ 0x112c9c
/* luna: Reads and returns a byte from a fixed memory-mapped register address. */
int mmio_read_flag_b() {
  return *(volatile uint8_t *)off_112CA4;
}



// rf_isr_clear @ 0x112ca8
/* luna: Selects the USB-wakeup handling path from a status bit, clears the associated byte flag and acknowledgment bit, and returns the handler result. */
int rf_isr_clear() {
  int result; // r0
  volatile uint32_t *v1; // r2

  if ( (((volatile uint32_t *)(uintptr_t)off_112CD8)[44] & 0x40000000) != 0 )
    result = (int)read_memory_byte(aUsbWkup_0);
  else
    result = event_dispatch(aUsbWkup);
  v1 = (void *)(uintptr_t)(off_112CE4);
  *(volatile uint8_t *)off_112CE0 = 0;
  v1[896] &= ~1u;
  return result;
}


// undef_stub @ 0x112cec
/* luna: Acknowledges enabled interrupt causes in the RF register block and dispatches associated RF state updates and recovery actions. */
int undef_stub() {
  volatile uint32_t *v0; // r3
  int v1; // r2
  int v2; // r4
  uint64_t v3; // r0
  int v4; // r10
  int v5; // r2
  int v6; // r8
  int v7; // r11
  volatile uint32_t *v8; // r6
  int v9; // r5
  unsigned int v10; // r2
  int v11; // r4
  int v12; // r9
  volatile char *v13; // r3
  int v14; // r1
  int ( *v15)(int, int, BOOL); // r3
  volatile uint32_t *v16; // r5
  int v17; // r6
  int v18; // r9
  int v19; // r7
  int i; // r4
  volatile char *v21; // r3
  int v22; // r2
  uint64_t v23; // r0
  int v24; // r3
  int v25; // r3
  int v26; // r3
  volatile uint32_t *v27; // r3
  volatile uint32_t *v28; // r4
  volatile int *v29; // r0
  int v30; // r1
  int v31; // r4
  int ( *v32)(int, int, uint32_t); // r3
  BOOL v34; // [sp+4h] [bp-10h]
  int v35; // [sp+4h] [bp-10h]
  int v36; // [sp+8h] [bp-Ch]
  int v37; // [sp+8h] [bp-Ch]
  int v38; // [sp+Ch] [bp-8h]
  int v39; // [sp+Ch] [bp-8h]

  v0 = (void *)(uintptr_t)(off_112F40);
  v1 = *((volatile uint32_t *)off_112F40 + 5);
  *((volatile uint32_t *)off_112F40 + 5) = v1;
  v2 = v0[6] & v1;
  v3 = (v3 & ~0xFFFFFFFFull) | ((uint32_t)(v2 << 19) & 0xFFFFFFFFu);
  if ( (v2 & 0x1000) != 0 )
  {
    v3 = (v3 & ~0xFFFFFFFFull) | ((uint32_t)(mmio_read_flag()) & 0xFFFFFFFFu);
    v4 = v2 & 0x2000;
    if ( (v2 & 0x2000) == 0 )
      return v3;
    v7 = 0;
    v6 = 0;
    v5 = 0;
  }
  else
  {
    v4 = v2 & dword_112F68;
    v5 = v2 & 0x40000;
    v6 = v2 & 0x80000;
    v7 = v2 & 0x800;
    if ( (v2 & 0x2000) == 0 )
      goto LABEL_3;
  }
  v26 = *((volatile uint32_t *)off_112F40 + 514);
  if ( (v26 & 6) != 0 && (v26 & 2) != 0 )
    *(volatile uint32_t *)off_112F54 = 1;
  v27 = (void *)(uintptr_t)(off_112F40);
  v28 = (void *)(uintptr_t)(off_112F58);
  v29 = (volatile int *)off_112F5C;
  v30 = dword_112F60;
  *((volatile uint32_t *)off_112F40 + 576) = dword_112F60;
  v27[704] = v30;
  v3 = (v3 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(*v28) << 32);
  v31 = *v29;
  v3 = (v3 & ~0xFFFFFFFFull) | ((uint32_t)(dword_112F64) & 0xFFFFFFFFu);
  *(volatile uint32_t *)HIDWORD(v3) = dword_112F64;
  *(volatile uint32_t *)(HIDWORD(v3) + 4) = v31;
  v27[709] = HIDWORD(v3);
  v27[706] = v27[706];
  v27[704] |= 0x84000000;
LABEL_3:
  if ( v5 )
  {
    v8 = (void *)(uintptr_t)(off_112F40);
    v9 = dword_112F44;
    v10 = *((volatile uint32_t *)off_112F40 + 518);
    v11 = 0;
    v12 = v10 & *((volatile uint32_t *)off_112F40 + 519);
    while ( 1 )
    {
      v3 = (v3 & ~0xFFFFFFFFull) | ((uint32_t)(1) & 0xFFFFFFFFu);
      if ( ((1 << v11) & v12) != 0 )
      {
        if ( !v11 )
        {
          v3 = (v3 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(v8[578]) << 32);
          v8[578] = HIDWORD(v3);
          v25 = v8[516] & HIDWORD(v3);
          if ( (v25 & 0x18) != 0 )
          {
            v8[516] &= ~0x10u;
            unknown_16(0, 0x200000, 0);
          }
          else if ( (v25 & 1) != 0 )
          {
            rf_init(v3, (volatile uint32_t *)v10);
          }
          goto LABEL_14;
        }
        v13 = (volatile char *)&v8[8 * v11 - 8];
        v10 = *((volatile uint32_t *)v13 + 586);
        *((volatile uint32_t *)v13 + 586) = v10;
        v14 = v8[516] & v10;
        if ( (v14 & 9) != 0 )
        {
          if ( *(volatile uint8_t *)(v9 - 5) )
          {
            v36 = *(volatile uint32_t *)(v9 - 12);
            v38 = *(volatile uint32_t *)(v9 - 16);
            v34 = (v10 & 1) == 0;
            if ( (v10 & 1) == 0 )
              flash_erase_main((void *)(uintptr_t)(1), (uint8_t)v11);
            v3 = (v3 & ~0xFFFFFFFFull) | ((uint32_t)(memset((volatile int *)(v9 - 16), 0, 0x10u)) & 0xFFFFFFFFu);
            v15 = *(int ( **)(int, int, BOOL))(dword_112F48 + 4 * v11 + 52);
            if ( v15 )
              v3 = (v3 & ~0xFFFFFFFFull) | ((uint32_t)(v15(v38, v36, v34)) & 0xFFFFFFFFu);
          }
        }
        else
        {
          v3 = (v3 & ~0xFFFFFFFFull) | ((uint32_t)(log_printf("irq %x\r\n", v14)) & 0xFFFFFFFFu);
        }
      }
      if ( (uint8_t)v11 == 5 )
        break;
LABEL_14:
      ++v11;
      v9 += 16;
    }
  }
  if ( v6 )
  {
    v16 = (void *)(uintptr_t)(off_112F40);
    v17 = dword_112F4C;
    v18 = dword_112F6C;
    v19 = *((volatile uint32_t *)off_112F40 + 518) & *((volatile uint32_t *)off_112F40 + 519);
    for ( i = 0; ; ++i )
    {
      if ( ((0x10000 << i) & v19) != 0 )
      {
        if ( !i )
        {
          v23 = (v23 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(v16[706]) << 32);
          v16[706] = HIDWORD(v23);
          v24 = v16[517] & HIDWORD(v23);
          if ( (v24 & 0x10) != 0 )
          {
            v16[517] &= ~0x10u;
            v3 = (v3 & ~0xFFFFFFFFull) | ((uint32_t)(unknown_15(0, 0x200000, 0)) & 0xFFFFFFFFu);
          }
          else if ( (v24 & 0x29) != 0 )
          {
            v23 = (v23 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
            v3 = (v3 & ~0xFFFFFFFFull) | ((uint32_t)(rf_init(v23, (volatile uint32_t *)(v24 << 27))) & 0xFFFFFFFFu);
          }
          goto LABEL_19;
        }
        v21 = (volatile char *)&v16[8 * i - 8];
        v22 = *((volatile uint32_t *)v21 + 714);
        *((volatile uint32_t *)v21 + 714) = v22;
        if ( (v16[517] & v22 & 1) != 0 )
        {
          if ( *(volatile uint8_t *)(v17 - 8) )
          {
            v37 = **(volatile uint16_t **)(v18 + 4 * i);
            v35 = *(volatile uint32_t *)(v17 - 12);
            v39 = *(volatile uint32_t *)(v17 - 16);
            v3 = (v3 & ~0xFFFFFFFFull) | ((uint32_t)(memset((volatile int *)(v17 - 16), 0, 0x10u)) & 0xFFFFFFFFu);
            v32 = *(int ( **)(int, int, uint32_t))(4 * i + dword_112F48 + 32);
            if ( v32 )
              v3 = (v3 & ~0xFFFFFFFFull) | ((uint32_t)(v32(v39, v35 - v37, 0)) & 0xFFFFFFFFu);
          }
        }
      }
      if ( (uint8_t)i == 5 )
        break;
LABEL_19:
      v17 += 16;
    }
  }
  if ( v7 )
  {
    v3 = (v3 & ~0xFFFFFFFFull) | ((uint32_t)(get_state_byte()) & 0xFFFFFFFFu);
    if ( v4 >= 0 )
      return v3;
  }
  else if ( v4 >= 0 )
  {
    return v3;
  }
  v3 = (v3 & ~0xFFFFFFFFull) | ((uint32_t)(rf_isr_clear()) & 0xFFFFFFFFu);
  return v3;
}


// after_helper_call @ 0x112f70
/* luna: Consumes a pending USB remote-wakeup request under an IRQ-safe nesting guard and dispatches the action selected by USB status bit 14. */
int after_helper_call() {
  volatile int *critical_section_depth_ptr; // r4
  volatile uint8_t *remote_wakeup_pending_ptr; // r5
  int remote_wakeup_pending; // r2
  int critical_section_depth; // r3
  volatile unsigned int wait_start_tick; // r2
  unsigned int wait_deadline_tick; // r2
  int ticks_remaining; // r3
  uint16_t usb_wakeup_status; // r1
  int result; // r0
  int v9; // r3
  int v10; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)dword_112FF0 = 1;
  }
  critical_section_depth_ptr = (volatile int *)dword_112FF4;
  remote_wakeup_pending_ptr = (volatile uint8_t *)dword_112FF8;
  remote_wakeup_pending = *(volatile uint8_t *)dword_112FF8;
  critical_section_depth = *(volatile uint32_t *)dword_112FF4 + 1;
  *(volatile uint32_t *)dword_112FF4 = critical_section_depth;
  if ( remote_wakeup_pending )
  {
    *(volatile uint32_t *)(dword_112FFC + 0x804) |= 1u;
    wait_start_tick = (*(volatile uint32_t *)0x40501010u);
    wait_deadline_tick = wait_start_tick + 9000;
    do
      ticks_remaining = wait_deadline_tick - (*(volatile uint32_t *)0x40501010u);
    while ( ticks_remaining >= 0 );
    usb_wakeup_status = *(volatile uint16_t *)(dword_113004 + 0xB2);
    *(volatile uint32_t *)(dword_112FFC + 0x804) &= ~1u;
    if ( (usb_wakeup_status & 0x4000) != 0 )
      result = (int)read_memory_byte(aUsbRmtwkup);
    else
      result = event_dispatch(aUsbRmtwkup_0);
    critical_section_depth = *critical_section_depth_ptr;
    *remote_wakeup_pending_ptr = 0;
  }
  if ( critical_section_depth )
  {
    v9 = critical_section_depth - 1;
    v10 = *(volatile uint32_t *)dword_112FF0;
    *critical_section_depth_ptr = v9;
    if ( !v9 )
    {
      if ( v10 )
        __enable_irq();
    }
  }
  return result;
}


// rx_counter_inc @ 0x113010
/* luna: In mode 4, validates the RX channel and submits the supplied buffer pointer to its MMIO slot while marking the software entry ready. */
int rx_counter_inc(int a1, volatile uint16_t *a2) {
  int v4; // r2
  int v5; // r3
  int v6; // r2

  after_helper_call();
  if ( *(volatile uint8_t *)off_113074 != 4 )
    return 1;
  v4 = a1 - 1;
  if ( (uint8_t)(a1 - 1) > 5u )
    return 2;
  if ( (*((volatile uint32_t *)&REG_4020_0900 + 8 * a1) & 0x8000) == 0 )
    return 5;
  v5 = 32 * v4 + 0x40000000;
  v6 = dword_113078 + 16 * v4;
  *(volatile uint32_t *)(v6 + 4) = *a2;
  *(volatile uint8_t *)(v6 + 11) = 1;
  *(volatile uint32_t *)(v5 + 2099508) = (int)(uintptr_t)(a2);
  *((volatile uint32_t *)&REG_4020_0900 + 8 * a1) |= 0x84000000;
  return 0;
}


// get_global_166e84 @ 0x1130c4
/* luna: Returns a pointer to a fixed volatile 32-bit memory-mapped location. */
volatile int *get_global_166e84() {
  return (volatile int *)off_1130C8;
}


// read_periph_status @ 0x113104
/* luna: Validates a USB WLAN receive frame and dispatches data frames or enqueues management messages for command handling. */
int read_periph_status(volatile uint8_t *a1, unsigned int a2, int a3) {
  volatile uint16_t *rx_packet_counter; // r7
  volatile uint8_t *v4; // r6
  volatile uint8_t *v5; // r4
  char v6; // r2
  int frame_type; // r8
  int declared_payload_len; // r6
  volatile uint8_t *rx_message_queue; // r8
  char queued_message_count; // r5
  int command_context; // r0
  unsigned int rx_message_slot_index; // r3
  volatile uint32_t *rx_message_slot; // r3

  rx_packet_counter = (volatile uint16_t *)off_11326C;
  v4 = (volatile uint8_t *)off_113270;
  v5 = (void *)(uintptr_t)(off_113274);
  ++*(volatile uint16_t *)off_11326C;
  if ( a3 )
    v6 = 3;
  else
    v6 = 2;
  *v4 = v6;
  *v5 = 0;
  if ( *v4 != 2 )
  {
    log_printf("usb wlan recv err %X %d\n", *rx_packet_counter, *v4);
    is_current_task(off_113288);
    return 1;
  }
  *v4 = 0;
  if ( a2 <= 3 )
  {
    log_printf("len err %X %d\n", *rx_packet_counter, a2);
  }
  else
  {
    frame_type = a1[2];
    declared_payload_len = *a1 | (a1[1] << 8) & 0xF00;
    if ( *(volatile uint8_t *)off_113278 )
      check_status_bits(512, "R:%d\n", a2);
    if ( frame_type == 1 )
    {
      if ( a2 == declared_payload_len || declared_payload_len + 1 == a2 )
      {
        timer_delay_1();
        check_packet_length((int)(a1 + 4));
        unknown_func_12d104(512);
        return 1;
      }
      log_printf("wdl err %X %d %d\n", *rx_packet_counter, declared_payload_len, a2);
    }
    else if ( frame_type == 17 )
    {
      rx_message_queue = (void *)(uintptr_t)(off_1132A8);
      if ( *((volatile uint8_t *)off_1132A8 + 2433) >= (unsigned int)*((volatile uint8_t *)off_1132A8 + 2434) )
      {
        log_printf(aErrNoRxMsgElem);
      }
      else
      {
        if ( declared_payload_len + 4 == a2 || a2 == declared_payload_len + 5 )
        {
          timer_delay_1();
          queued_message_count = rx_message_queue[2433];
          command_context = dword_113280;
          rx_message_slot_index = (uint8_t)rx_message_queue[2432]
              + 1
              - 40
              * ((unsigned int)(((unsigned int)dword_11327C
                               * (uint64_t)((unsigned int)(uint8_t)rx_message_queue[2432] + 1)) >> 32) >> 5);
          rx_message_queue[2432] = rx_message_slot_index;
          rx_message_slot = (void *)(&rx_message_queue[20 * rx_message_slot_index]);
          rx_message_slot[409] = (int)(uintptr_t)(a1 + 4);
          rx_message_slot[412] = declared_payload_len;
          rx_message_queue[2433] = queued_message_count + 1;
          cmd_handler_a(command_context, rx_message_slot + 408);
          unknown_func_12d104(0x400000);
          return 1;
        }
        log_printf("wml err %X %d %d\n", *rx_packet_counter, declared_payload_len, a2);
      }
    }
    else
    {
      log_printf("type err %X %X %d %d\r\n", *rx_packet_counter, frame_type, declared_payload_len, a2);
    }
  }
  is_controller_mode((void *)(&a1[-*(volatile uint32_t *)off_113290]));
  timer_delay_1();
  return 1;
}


// irq_state_load @ 0x1132ac
/* luna: Loads optional USB VID/PID values from flash, resets USB state, and retries the open command until it returns success. */
int irq_state_load(int a1) {
  volatile uint16_t *v2; // r4
  int v3; // r2
  int v4; // r1
  volatile uint8_t *v5; // r1
  volatile uint8_t *v6; // r2
  int v7; // r7
  int v8; // r1
  int v9; // r4

  if ( (*(volatile uint32_t *)off_11332C & 0x2000000) != 0 )
  {
    memset((volatile int *)off_113330, 0xFFu, 4u);
  }
  else
  {
    v2 = (volatile uint16_t *)off_113330;
    memset((volatile int *)off_113330, 0xFFu, 4u);
    if ( patch_get_field((int)v2) || (v3 = v2[1], v3 == 0xFFFF) || (v4 = *v2, v4 == 0xFFFF) )
      event_dispatch(aNoUsbInfoInFla);
    else
      event_dispatch("get vid %x, pid %x\r\n", v4, v3);
  }
  v5 = (void *)(uintptr_t)(off_11333C);
  v6 = (void *)(uintptr_t)(off_113340);
  *(volatile uint32_t *)off_113338 = *(volatile uint32_t *)a1;
  v7 = off_113344;
  *v5 = 0;
  *v6 = 0;
  do
  {
    v8 = *(volatile uint8_t *)(a1 + 8);
    if ( *(volatile uint8_t *)(a1 + 8) )
      v8 = 1;
    v9 = cmd_dispatch(v7, v8);
    event_dispatch("open res:%d\n", v9);
  }
  while ( v9 );
  return 0;
}


// irq_state_load_b @ 0x113350
/* luna: Starts a USB WLAN receive operation by configuring its peripheral channel and aborts if the operation is cancelled during setup. */
int irq_state_load_b(int a1, int a2) {
  volatile uint8_t *v2; // r4
  volatile uint8_t *v3; // r6
  volatile uint32_t *v4; // r7
  int v5; // r0
  int v6; // r2

  v2 = (void *)(uintptr_t)(off_1133D4);
  if ( *(volatile uint8_t *)off_1133D4 )
    return -14;
  if ( !a1 || !a2 )
    return -11;
  v3 = (void *)(uintptr_t)(off_1133D8);
  if ( *(volatile uint8_t *)off_1133D8 )
  {
    log_printf("err: %s state=%d\r\n", aUsbWlanRecv, *(volatile uint8_t *)off_1133D8);
    return -3;
  }
  else
  {
    v4 = (void *)(uintptr_t)(off_1133DC);
    *(volatile uint8_t *)off_1133D8 = 1;
    v4[716] &= 0xE007FFFF;
    v5 = periph_channel_flag(1, a1, a2);
    v6 = v5;
    if ( v5 )
    {
      log_printf("err: %s ret=%d\r\n", aUsbWlanRecv, v5);
      return -1;
    }
    else
    {
      *(volatile uint8_t *)off_1133E0 = 1;
      if ( *v2 )
      {
        ((int (*)())shared_call_check)(0, 1, 0);
        *v3 = 0;
        return -14;
      }
    }
  }
  return v6;
}


// ke_task_init @ 0x1133f0
/* luna: Opens USB WLAN receive flow control by programming mode-dependent MMIO bits and copying the supplied configuration, returning an error if the operatio */
int ke_task_init(int a1, int a2) {
  volatile uint8_t *v2; // r4
  volatile uint8_t *v3; // r5
  int v4; // r3
  volatile uint32_t *v5; // r2
  int v6; // r0
  int v7; // r2

  v2 = (void *)(uintptr_t)(off_113494);
  if ( *(volatile uint8_t *)off_113494 )
    return -14;
  if ( !a1 || !a2 )
    return -11;
  v3 = (void *)(uintptr_t)(off_113498);
  if ( *(volatile uint8_t *)off_113498 )
  {
    log_printf("err: %s state=%d\r\n", aUsbWlanRecvFcO, *(volatile uint8_t *)off_113498);
    return -3;
  }
  else
  {
    v4 = *(volatile char *)off_11349C;
    *(volatile uint8_t *)off_113498 = 1;
    v5 = (void *)(uintptr_t)(off_1134A0);
    if ( v4 )
    {
      *((volatile uint32_t *)off_1134A0 + 716) &= 0xE007FFFF;
      v5[512] |= 0x2000u;
    }
    else
    {
      *((volatile uint32_t *)off_1134A0 + 713) |= 1u;
    }
    v6 = global_copy_u16(1, a1, a2);
    v7 = v6;
    if ( v6 )
    {
      log_printf("err: %s ret=%d\r\n", aUsbWlanRecvFcO, v6);
      return -1;
    }
    else
    {
      *(volatile uint8_t *)off_1134A4 = 1;
      if ( *v2 )
      {
        ((int (*)())shared_call_check)(0, 1, 0);
        *v3 = 0;
        return -14;
      }
    }
  }
  return v7;
}


// check_init_flag @ 0x1134b4
/* luna: On its first successful invocation, selects a table node, sets bits 1 and 3 in its final 8-byte entry, and calls the RX-counter increment routine with */
int check_init_flag() {
  volatile uint8_t *v0; // r6
  volatile int **v1; // r4
  char v2; // r0
  volatile uint8_t *v3; // r12
  volatile int *v4; // r7
  volatile int *v5; // r5
  unsigned int v6; // r4
  volatile int *v7; // r1
  char v8; // r3
  char v9; // r2
  volatile uint16_t *v10; // r1
  int v11; // r2
  char v12; // r3

  v0 = (void *)(uintptr_t)(off_113548);
  if ( *(volatile uint8_t *)off_113548 )
    return -99;
  v1 = (volatile int **)off_11354C;
  v2 = read_u32((volatile uint32_t **)off_11354C);
  v3 = (void *)(uintptr_t)(off_113554);
  *(volatile uint8_t *)off_113554 = v2;
  if ( v2 )
  {
    v4 = *v1;
    v5 = *(volatile int **)(dword_113550 + 8240);
    if ( v2 != 1 )
    {
      v6 = *((volatile uint16_t *)v4 + 6);
      if ( *((volatile uint16_t *)v5 + 6) < v6 )
      {
        v7 = v4;
        v8 = v2;
        while ( 1 )
        {
          v9 = v2 - v8--;
          if ( !v6 )
            break;
          if ( !*v7 || !v8 )
          {
            *v3 = v8;
            v5 = v7;
            goto LABEL_11;
          }
          v6 = *(volatile uint16_t *)(*v7 + 12);
          v5 = v7;
          v7 = (volatile int *)*v7;
        }
        *v3 = v9;
      }
      goto LABEL_11;
    }
    if ( v5 )
    {
LABEL_11:
      v10 = (volatile uint16_t *)v4[1];
      v11 = v5[1] + 8 * (*((volatile uint8_t *)v5 + 14) - 1);
      v12 = *(volatile uint8_t *)(v11 + 3);
      *v0 = 1;
      *(volatile uint8_t *)(v11 + 3) = v12 & 0xF5 | 0xA;
      return rx_counter_inc(1, v10);
    }
  }
  return -98;
}


// set_mode_flag @ 0x113558
/* luna: Records the USB WLAN send result and, on success, drains pending entries while dispatching supported message types and reporting unsupported ones. */
int set_mode_flag(int a1, int a2, int a3) {
  volatile uint8_t *v3; // r5
  char v4; // r3
  volatile uint8_t *v5; // r4
  int v6; // r3
  int v7; // r5
  int v8; // r6
  volatile uint32_t *v9; // r0
  int v10; // r8
  int v11; // r3

  v3 = (volatile uint8_t *)off_113604;
  if ( a3 )
    v4 = 3;
  else
    v4 = 2;
  *(volatile uint8_t *)off_113604 = v4;
  if ( *v3 == 2 )
  {
    v5 = (void *)(uintptr_t)(off_113608);
    v6 = *(volatile uint8_t *)off_113608;
    *v3 = 0;
    if ( v6 )
    {
      v7 = dword_11360C;
      v8 = dword_11360C - 8;
      do
      {
        while ( 1 )
        {
          v9 = mem_word_load(v7);
          v10 = *(volatile uint32_t *)(v9[1] + 4);
          --*v5;
          cmd_handler_a(v8, v9);
          v11 = *(volatile uint8_t *)(v10 + 2) >> 4;
          if ( v11 )
            break;
          ++*(volatile uint16_t *)off_113614;
          unknown_func_12d104(128);
          if ( !*v5 )
            goto LABEL_12;
        }
        if ( v11 == 1 )
        {
          is_controller_mode((volatile uint32_t *)v10);
        }
        else
        {
          log_printf("###err### %x\r\n", v10);
          send_msg(v10, 32, 1, 0);
        }
      }
      while ( *v5 );
    }
LABEL_12:
    check_init_flag();
    return 1;
  }
  else
  {
    log_printf("usb wlan send err %d\n", *v3);
    is_current_task(off_11361C);
    return 1;
  }
}


// is_single_channel @ 0x113620
/* luna: Returns the configuration block for selector 1, 6, or 15, refreshing the selector-1 block from defaults and applying a hook-derived or stored override */
volatile int * is_single_channel(int a1) {
  volatile int *result; // r0
  volatile int *v2; // r4
  unsigned int v3; // r0

  switch ( a1 )
  {
    case 1:
      v2 = (volatile int *)off_113694;
      memcpy((volatile char *)off_113694, (volatile char *)off_113698, 0x12u);
      if ( BYTE2(((volatile uint32_t *)(uintptr_t)off_11369C)[92]) && get_hook_bit_9() )
      {
        v3 = call_hook_2();
        v2[2] = ((HIWORD(v3) << 16) + 0x10000) | (uint16_t)v3;
        return v2;
      }
      else if ( *(volatile uint16_t *)off_1136A0 == 0xFFFF || *((volatile uint16_t *)off_1136A0 + 1) == 0xFFFF )
      {
        return (volatile int *)off_113694;
      }
      else
      {
        result = (volatile int *)off_113694;
        v2[2] = *(volatile uint32_t *)off_1136A0;
      }
      break;
    case 6:
      return (volatile int *)off_113690;
    case 15:
      return (volatile int *)((volatile uint32_t *)(uintptr_t)&off_11368C)[0];
    default:
      return nullptr;
  }
  return result;
}


// lookup_channel_table @ 0x1136a4
/* luna: Returns the indexed 32-bit entry from the volatile channel table, or zero when the index is outside the eight-entry range. */
int lookup_channel_table(unsigned int a1) {
  if ( a1 > 7 )
    return 0;
  else
    return *(volatile uint32_t *)(dword_1136B4 + 4 * a1);
}



// read_state_flag @ 0x1136b8
/* luna: Obtains a watchdog RX buffer, processes it through the state-load path, and retries failed loads up to five times while recording threshold conditions */
void read_state_flag(int a1, int a2, int a3, int a4) {
  volatile uint8_t *v4; // r5
  volatile uint16_t *v5; // r2
  int v6; // r0
  volatile uint32_t *v7; // r4
  volatile uint32_t *v8; // r8
  volatile int *v9; // r6
  int v10; // r1
  int v11; // r0
  int v12; // r0
  volatile uint8_t *v13; // r7
  int v14; // r9
  int v15; // r1
  int v16; // r0
  int v17; // r0
  volatile uint16_t *v18; // r3

  v4 = (void *)(uintptr_t)(off_1137E0);
  if ( *(volatile uint8_t *)off_1137E0 )
  {
    if ( !*(volatile uint16_t *)off_1137EC )
    {
      check_status_bits(512, "#we\n");
      return;
    }
    if ( *(volatile uint8_t *)off_1137E8 >= (unsigned int)*(volatile uint16_t *)off_1137EC )
    {
      v18 = (volatile uint16_t *)off_1137F0;
      *(volatile uint8_t *)off_1137E4 = 1;
      check_status_bits(512, "#wf:%X\n", *v18);
    }
  }
  else
  {
    if ( *(volatile uint8_t *)off_1137E4 )
      return;
    if ( *(volatile uint8_t *)off_1137E8 >= (unsigned int)*(volatile uint16_t *)off_1137EC && !*(volatile uint8_t *)off_1137E4 )
    {
      v5 = (volatile uint16_t *)off_1137F0;
      *(volatile uint8_t *)off_1137E4 = 1;
      check_status_bits(512, "#wf:%X\n", *v5);
      return;
    }
  }
  v6 = (*(int ( **)(uint32_t))(*((volatile uint32_t *)off_1137F8 + 2) + 16))(*((volatile uint32_t *)off_1137F8 + 1));
  v7 = (volatile uint32_t *)v6;
  if ( v6 )
  {
    if ( *v4 )
    {
      v8 = (volatile uint32_t *)off_113810;
      v9 = (volatile int *)off_1137FC;
      v10 = *(volatile uint32_t *)off_1137FC;
      v11 = *(volatile uint32_t *)off_113810 + v6;
      if ( *(volatile uint8_t *)off_1137E4 )
        v12 = ke_task_init(v11, v10);
      else
        v12 = irq_state_load_b(v11, v10);
    }
    else
    {
      v8 = (volatile uint32_t *)off_113810;
      v9 = (volatile int *)off_1137FC;
      v12 = irq_state_load_b(*(volatile uint32_t *)off_113810 + v6, *(volatile uint32_t *)off_1137FC);
    }
    if ( v12 )
    {
      v13 = (void *)(uintptr_t)(off_1137E4);
      log_printf("wd rx %d\r\n", v12);
      v14 = 5;
      while ( 1 )
      {
        if ( *v4 )
        {
          v15 = *v9;
          v16 = (int)v7 + *v8;
          v17 = *v13 ? ke_task_init(v16, v15) : irq_state_load_b(v16, v15);
        }
        else
        {
          v17 = irq_state_load_b((int)v7 + *v8, *v9);
        }
        if ( !v17 )
          break;
        if ( !--v14 )
        {
          log_printf("wd rx max time %d\r\n", 5);
          is_controller_mode(v7);
          unknown_func_12d104(32);
          return;
        }
      }
    }
  }
  else
  {
    unknown_func_12d104(32);
    log_printf(aErrWdNoRxBuf);
  }
}


