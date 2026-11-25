// radio_init @ 0x12ebb8
/* luna: Queues a USB-off TX event, invokes a handler with selector 0x42F, and clears bit 1 in a global state word. */
int radio_init() {
  alloc_tx_event(aUsbOff);
  invalid_handler_12c5fc((int)(uintptr_t)((volatile char *)0x42F), 1);
  *((volatile uint32_t *)off_12EBDC + 20) &= ~2u;
  return 0;
}


// pdu_alloc_410 @ 0x12ebe0
/* luna: Prepares the 0x410 boot-NPC PDU, applies the request value to the slot selected by selector 1 or 2, and passes the cleared buffer to the RX processor. */
int pdu_alloc_410(int a1, int a2, int a3, int a4) {
  int v5; // r0
  int v6; // r1
  volatile uint32_t *v7; // r4
  volatile uint32_t *v9; // r2
  volatile uint8_t *v10; // r0
  volatile uint32_t *v11; // r3
  volatile uint32_t *v12; // r3

  v5 = tx_send_pdu(1040, a4, a3, 4);
  v6 = *(volatile uint16_t *)(a2 + 4);
  v7 = (volatile uint32_t *)v5;
  if ( BYTE1(((volatile uint32_t *)(uintptr_t)off_12EC58)[44]) )
  {
    if ( (unsigned int)(v6 - 1) > 1 )
      goto LABEL_3;
    v9 = (void *)(uintptr_t)(off_12EC64);
    *(volatile uint32_t *)off_12EC60 |= 0x2000000u;
    v10 = (void *)(uintptr_t)(off_12EC68);
    v9[14] |= 0x10u;
    *v10 = 1;
  }
  if ( v6 == 1 )
  {
    v11 = (void *)(uintptr_t)(off_12EC64);
    *((volatile uint32_t *)off_12EC64 + 18) = *(volatile uint32_t *)a2;
    v11[75] = 64;
    goto LABEL_5;
  }
LABEL_3:
  if ( v6 == 2 )
  {
    v12 = (void *)(uintptr_t)(off_12EC64);
    *((volatile uint32_t *)off_12EC64 + 19) = *(volatile uint32_t *)a2;
    v12[75] = 128;
  }
LABEL_5:
  *v7 = 0;
  alloc_tx_event("\x9D\x81""DBG: Boot NPC %d\n", v6);
  rx_process_packet_1((int)v7);
  return 0;
}


// pdu_alloc_40a @ 0x12ec6c
/* luna: Creates a zero-filled 12-byte PDU for opcode 0x40A, passes it to the packet processor, and returns zero. */
int pdu_alloc_40a(int a1, int a2, int16_t a3, int16_t a4) {
  volatile uint32_t *v4; // r0

  v4 = (volatile uint32_t *)tx_send_pdu(1034, a4, a3, 0xCu);
  *v4 = 0;
  v4[1] = 0;
  v4[2] = 0;
  rx_process_packet_1((int)v4);
  return 0;
}



// pdu_alloc_424 @ 0x12ec8c
/* luna: Copies the supplied packet into a 0x424 PDU, capped at 1024 bytes, allocates a TX event, and submits the PDU to RX packet processing. */
int pdu_alloc_424(int a1, volatile char **a2, int a3, int a4) {
  int v5; // r0
  volatile char *v6; // r1
  unsigned int v7; // r2
  int v8; // r4

  v5 = tx_send_pdu(1060, a4, a3, 1032);
  v7 = (unsigned int)a2[1];
  v6 = *a2;
  if ( v7 >= 0x400 )
    v7 = 1024;
  *(volatile uint32_t *)v5 = (int)(uintptr_t)(v6);
  *(volatile uint32_t *)(v5 + 4) = v7;
  v8 = v5;
  memcpy((volatile char *)(v5 + 8), v6, v7);
  alloc_tx_event(asc_14AB98, *a2, &(*a2)[*(volatile uint32_t *)(v8 + 4)], *(volatile uint32_t *)(v8 + 8));
  rx_process_packet_1(v8);
  return 0;
}


// pdu_alloc_40c @ 0x12ecd4
/* luna: Copies the request’s inline payload to its destination, queues an event describing the written range, and submits the allocated PDU for processing. */
int pdu_alloc_40c(int a1, volatile uint32_t *a2, int a3, int a4) {
  volatile uint32_t *v5; // r5
  volatile char *v6; // r0
  int v7; // zf
  unsigned int v8; // r2

  v5 = (volatile uint32_t *)tx_send_pdu(1036, a4, a3, 4);
  v6 = (volatile char *)*a2;
  v7 = *a2 << 30 == 0;
  v8 = a2[1];
  *v5 = 0;
  if ( !v7 )
    *v5 = 255;
  if ( v8 << 30 )
    *v5 = 1;
  memcpy(v6, (volatile char *)a2 + 8, v8);
  alloc_tx_event(asc_14ABDC, *a2, a2[1] + *a2, a2[2], *v5);
  rx_process_packet_1((int)v5);
  return 0;
}


// send_mcu_cmd_0x412 @ 0x12ed2c
/* luna: Sends MCU command 0x412 to apply a masked write at the supplied address and report the resulting value. */
int send_mcu_cmd_0x412(int a1, volatile uint32_t *a2, int a3, int a4) {
  volatile uint64_t *v5; // r0
  int tx_payload; // r5
  volatile uint32_t *target_address; // r0
  uint64_t v8; // r2
  int result_value; // r0

  v5 = (volatile uint64_t *)tx_send_pdu(1042, a4, a3, 8);
  tx_payload = (int)v5;
  if ( (unsigned int)**(volatile uint8_t **)off_12EDE0 - 1 <= 1 )
  {
    v8 = (v8 & ~0xFFFFFFFFull) | ((uint32_t)(*a2) & 0xFFFFFFFFu);
    if ( *a2 == dword_12EDE8 || (uint32_t)v8 == dword_12EDE8 - 36184 )
    {
      *(volatile uint32_t *)v8 ^= (a2[2] ^ *(volatile uint32_t *)v8) & a2[1];
      v8 = (v8 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(a2[2]) << 32);
      v8 = (v8 & ~0xFFFFFFFFull) | ((uint32_t)(*a2) & 0xFFFFFFFFu);
      result_value = HIDWORD(v8);
      *(volatile uint64_t *)tx_payload = v8;
    }
    else
    {
      v8 = (v8 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(a2[2]) << 32);
      *v5 = v8;
      result_value = HIDWORD(v8);
    }
  }
  else
  {
    target_address = (volatile uint32_t *)*a2;
    if ( ((*a2 >> 20) & 0xFFFFFDFF) == 0x500 )
    {
      mmio_rmw32((int)target_address, a2[2], a2[1], 1);
      result_value = mmio_read32_1(*a2, 1);
      v8 = (v8 & ~0xFFFFFFFFull) | ((uint32_t)(*a2) & 0xFFFFFFFFu);
    }
    else
    {
      *target_address ^= (a2[2] ^ *target_address) & a2[1];
      v8 = (v8 & ~0xFFFFFFFFull) | ((uint32_t)(*a2) & 0xFFFFFFFFu);
      result_value = *(volatile uint32_t *)*a2;
    }
    *(volatile uint32_t *)(tx_payload + 4) = result_value;
    v8 = (v8 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(a2[2]) << 32);
    *(volatile uint32_t *)tx_payload = v8;
  }
  alloc_tx_event(
    "\x9D\x81""DBG: Writing memory with mask:0x%08x, data:0x%08x / %d: [0x%08x] = 0x%08x / %d\n",
    a2[1],
    HIDWORD(v8),
    HIDWORD(v8),
    (uint32_t)v8,
    result_value,
    result_value);
  rx_process_packet_1(tx_payload);
  return 0;
}


// send_mcu_cmd_0x401 @ 0x12edec
/* luna: Reads a 32-bit value from the requested address and returns the address/value pair in a 0x401 PDU. */
int send_mcu_cmd_0x401(int a1, volatile uint32_t *a2, int a3, int a4) {
  int response_pdu; // r0
  volatile int *address; // r1
  volatile int **response_payload; // r4
  int read_value; // r3
  int mmio_value; // r0

  response_pdu = tx_send_pdu(1025, a4, a3, 8);
  address = (volatile int *)*a2;
  response_payload = (volatile int **)response_pdu;
  if ( ((*a2 >> 20) & 0xFFFFFDFF) == 0x500 )
  {
    mmio_value = mmio_read32_1(*a2, 1);
    address = (volatile int *)*a2;
    response_payload[1] = (volatile int *)mmio_value;
    read_value = mmio_value;
  }
  else
  {
    read_value = *address;
    *(volatile uint32_t *)(response_pdu + 4) = *address;
  }
  *response_payload = address;
  alloc_tx_event("\x9D\x81""DBG: Reading memory: [0x%08x] = 0x%08x / %d\n", address, read_value, read_value);
  rx_process_packet_1((int)response_payload);
  return 0;
}


// bt_global_op_0x16acb4 @ 0x12ee38
/* luna: Sets the Bluetooth debug severity filter and updates the associated MAC header word. */
int bt_global_op_0x16acb4(int a1, volatile uint32_t *a2, int a3, int a4) {
  alloc_tx_event("\x9D\x81""DBG: Setting severity filter: 0x%08x\n", *a2);
  *((volatile uint32_t *)off_12EE68 + 1) = *a2;
  mac_write_header_word(1031, a4, a3);
  return 0;
}


// bt_global_op_0x16acdc @ 0x12ee6c
/* luna: Stores the requested Bluetooth module filter and writes the corresponding response header. */
int bt_global_op_0x16acdc(int a1, volatile uint32_t *a2, int a3, int a4) {
  alloc_tx_event("\x9D\x81""DBG: Setting module filter: 0x%08x\n", *a2);
  *(volatile uint32_t *)off_12EE9C = *a2;
  mac_write_header_word(1029, a4, a3);
  return 0;
}


// send_mcu_cmd_0x403 @ 0x12eea0
/* luna: Builds and dispatches MCU command 0x403 for a memory write, including the reported value or readback in its payload. */
int send_mcu_cmd_0x403(int a1, volatile uint32_t *a2, int a3, int a4) {
  volatile int *v5; // r0
  volatile int *command_payload; // r5
  volatile uint32_t *target_address_ptr; // r0
  int memory_address; // r3
  int reported_value; // r0
  int write_value; // r2

  v5 = (volatile int *)tx_send_pdu(1027, a4, a3, 8);
  command_payload = v5;
  if ( (unsigned int)**(volatile uint8_t **)off_12EF18 - 1 <= 1 )
  {
    write_value = a2[1];
    memory_address = *a2;
    *(volatile uint64_t *)v5 = *(volatile uint64_t *)a2;
    reported_value = write_value;
  }
  else
  {
    target_address_ptr = (volatile uint32_t *)*a2;
    if ( ((*a2 >> 20) & 0xFFFFFDFF) == 0x500 )
    {
      mmio_read32_variant((int)target_address_ptr, a2[1], 1);
      reported_value = mmio_read32_1(*a2, 1);
      memory_address = *a2;
    }
    else
    {
      *target_address_ptr = a2[1];
      memory_address = *a2;
      reported_value = *(volatile uint32_t *)*a2;
    }
    command_payload[1] = reported_value;
    write_value = a2[1];
    *command_payload = memory_address;
  }
  alloc_tx_event("\x9D\x81""DBG: Writing memory with 0x%08x / %d: [0x%08x] = 0x%08x / %d\n", write_value, write_value, memory_address, reported_value, reported_value);
  rx_process_packet_1((int)command_payload);
  return 0;
}


// bt_coex_check_state @ 0x12ef20
/* luna: Alternates between firmware-version and RF-timer actions, rescheduling event 1070 after each phase. */
int bt_coex_check_state() {
  volatile uint8_t *v0; // r5
  int v1; // r0
  int v2; // r4

  v0 = (void *)(uintptr_t)(off_12EF7C);
  v1 = invalid_handler_12c5fc(1070, 1);
  v2 = (char)v0[1];
  if ( v2 == 1 )
  {
    fw_version_get();
    ke_event_handler(1070, 1, dword_12EF80);
    v0[1] = 2;
    return 0;
  }
  else
  {
    if ( v2 == 2 )
    {
      rf_timer_toggle_start(v1);
      ke_event_handler(1070, 1, 1000 * *((volatile uint32_t *)off_12EF84 + 91));
      v0[1] = 1;
    }
    return 0;
  }
}



// event_sync @ 0x12ef88
/* luna: Gets the PHY state, calls the RF frequency setter, and then enters an infinite loop. */
void event_sync() {
  int v0; // r0
  int v1; // r1
  int v2; // r2

  v0 = get_phy_state();
  ((int (*)())rf_set_frequency)(v0, v1, v2);
  while ( 1 )
    ;
}



// send_event_42d @ 0x12ef94
/* luna: Reports a WLAN flow-control timeout by creating a transmit event and synchronizing event 0x42D. */
void send_event_42d() {
  volatile char *v0; // r0

  alloc_tx_event(aErrWlanFcTimeo);
  v0 = (void *)(uintptr_t)(invalid_handler_12c5fc((int)(uintptr_t)((volatile char *)0x42D), 1));
  event_sync((int)v0);
}


// send_event_42c @ 0x12efb0
/* luna: Queues the reboot transmit event, synchronizes event 0x42C in mode 1, and passes the returned value to event_sync. */
void send_event_42c() {
  volatile char *v0; // r0

  alloc_tx_event(aReboot);
  v0 = (void *)(uintptr_t)(invalid_handler_12c5fc((int)(uintptr_t)((volatile char *)0x42C), 1));
  event_sync((int)v0);
}


// send_mcu_cmd_0x40e @ 0x12efcc
/* luna: Handles the 0x40E boot-mode test request, logs the selected mode, schedules a requested delay when applicable, and finalizes the response packet. */
int send_mcu_cmd_0x40e(int a1, volatile int *a2, int a3, int a4) {
  int v5; // r0
  int v6; // r3
  volatile uint32_t *v7; // r4
  int v9; // r5
  int v10; // r0

  v5 = tx_send_pdu(1038, a4, a3, 4);
  v6 = a2[1];
  v7 = (volatile uint32_t *)v5;
  switch ( v6 )
  {
    case 1:
      alloc_tx_event("\x9D\x81""Auto boot to 0x%08x\r\n", *(volatile uint32_t *)(*a2 + 4));
      break;
    case 2:
      alloc_tx_event("\x9D\x81""Custom boot to 0x%08x\r\n", *a2);
      break;
    case 3:
      v9 = *a2;
      v10 = alloc_tx_event("delay %d\r\n", v9);
      if ( !v9 )
        event_sync(v10);
      ke_event_handler(1068, 1, v9 << 10);
      break;
    default:
      alloc_tx_event(aInvalidBootTyp);
      break;
  }
  *v7 = (uint8_t)call_patch_1fc_0(15);
  alloc_tx_event(asc_14ADBC);
  rx_process_packet_1((int)v7);
  return 0;
}


// sub_12F054 @ 0x12f054
/* luna: Logs TX queue pointers and status, selects a pending packet from the hardware status bits, and dumps its descriptor and packet data. */
int sub_12F054() {
  volatile uint32_t *v0; // r4
  volatile uint32_t *tx_list_cptr_reg; // r10
  volatile uint32_t *ac0_sptr_reg; // r6
  volatile uint32_t *ac1_sptr_reg; // r7
  volatile uint32_t *ac2_sptr_reg; // r8
  volatile uint32_t *ac3_sptr_reg; // r9
  volatile uint32_t *hiq_sptr_reg; // r5
  int v7; // r0
  int v8; // r3
  volatile uint32_t *v9; // r7
  volatile uint32_t *v10; // r5
  int v11; // r4
  int v13; // nf
  volatile uint32_t **v14; // r3

  v0 = (void *)(uintptr_t)(off_12F21C);
  tx_list_cptr_reg = (void *)(uintptr_t)(off_12F2B8);
  ac0_sptr_reg = (void *)(uintptr_t)(off_12F220);
  ac1_sptr_reg = (void *)(uintptr_t)(off_12F224);
  ac2_sptr_reg = (void *)(uintptr_t)(off_12F2BC);
  ac3_sptr_reg = (void *)(uintptr_t)(off_12F2C0);
  hiq_sptr_reg = (void *)(uintptr_t)(off_12F228);
  alloc_tx_event("\x9B""current state is %d\r\n", *(volatile uint32_t *)off_12F214 & 0xF);
  alloc_tx_event("\x9B""40328188=%08x, 4032818c=%x\r\n", *v0, *(volatile uint32_t *)off_12F22C);
  alloc_tx_event("txlist cptr 40128540=%08x \r\n", *tx_list_cptr_reg);
  alloc_tx_event("ac0 sptr 40328528=%08x \r\n", *ac0_sptr_reg);
  alloc_tx_event("ac1 sptr 4032852c=%08x \r\n", *ac1_sptr_reg);
  alloc_tx_event("ac2 sptr 40328530=%08x \r\n", *ac2_sptr_reg);
  alloc_tx_event("ac3 sptr 40328534=%08x \r\n", *ac3_sptr_reg);
  alloc_tx_event("hiq sptr 4032853c=%08x \r\n", *hiq_sptr_reg);
  alloc_tx_event(
    "\x9B""ac0header=%08x, ac1header=%08x, ac2header=%08x, ac3header=%08x, hiqheader=%x\r\n",
    *(volatile uint32_t *)off_12F24C,
    *(volatile uint32_t *)off_12F250,
    *(volatile uint32_t *)off_12F254,
    *(volatile uint32_t *)off_12F258,
    *(volatile uint32_t *)off_12F2C4);
  alloc_tx_event("\x9Bstatus of 0x40328528=%08x\r\n", *(volatile uint32_t *)(*ac0_sptr_reg + 60));
  alloc_tx_event("\x9Bstatus of 0x4032852c=%08x\r\n", *(volatile uint32_t *)(*ac1_sptr_reg + 60));
  alloc_tx_event("\x9Bstatus of 0x40328530=%08x\r\n", *(volatile uint32_t *)(*ac2_sptr_reg + 60));
  alloc_tx_event("\x9Bstatus of 0x40328534=%08x\r\n", *(volatile uint32_t *)(*ac3_sptr_reg + 60));
  alloc_tx_event("\x9Bstatus of 0x4032853c=%08x\r\n", *(volatile uint32_t *)(*hiq_sptr_reg + 60));
  if ( (*v0 & 0x2000000) != 0 )
  {
    v0 = (volatile uint32_t *)*hiq_sptr_reg;
  }
  else if ( (*v0 & 0x200000) != 0 )
  {
    v0 = *(volatile uint32_t **)off_12F2B0;
  }
  else if ( (*v0 & 0x20) != 0 )
  {
    v0 = (volatile uint32_t *)*ac0_sptr_reg;
  }
  else if ( (*v0 & 0x200) != 0 )
  {
    v0 = (volatile uint32_t *)*ac1_sptr_reg;
  }
  else if ( (*v0 & 0x2000) != 0 )
  {
    v0 = (volatile uint32_t *)*ac2_sptr_reg;
  }
  else if ( (*v0 & 0x20000) != 0 )
  {
    v0 = (volatile uint32_t *)*ac3_sptr_reg;
  }
  else
  {
    v14 = (volatile uint32_t **)(*v0 << 30);
    v13 = (*v0 & 2) != 0;
    if ( (*v0 & 2) != 0 )
      v14 = (volatile uint32_t **)dword_12F2B4;
    else
      v0 = (volatile uint32_t *)*tx_list_cptr_reg;
    if ( v13 )
      v0 = *v14;
  }
  if ( v0 )
  {
    process_packet_params((int)v0, 68, 1, 0);
    process_packet_params(v0[9], 52, 1, 0);
    alloc_tx_event("\x9B""frmlen=%x\r\n", v0[6]);
    v7 = v0[4];
    if ( v7 )
    {
      process_packet_params(v7, v0[5] + 1 - v7, 1, 0);
      v8 = v0[3];
      if ( !v8 )
        goto LABEL_6;
    }
    else
    {
      v8 = v0[3];
      if ( !v8 )
        goto LABEL_6;
    }
    process_packet_params(*(volatile uint32_t *)(v8 + 8), *(volatile uint32_t *)(v8 + 12) + 1 - *(volatile uint32_t *)(v8 + 8), 1, 0);
  }
LABEL_6:
  v9 = (void *)(uintptr_t)(off_12F278);
  v10 = (void *)(uintptr_t)(off_12F280);
  v11 = (v11 & ~0xFFu) | ((uint8_t)(8) & 0xFFu);
  do
  {
    alloc_tx_event("\x9B""0x40320500=%08x\r\n", *v9);
    alloc_tx_event("\x9B""0x40320504=%08x\r\n", *v10);
    v11 = (uint8_t)(v11 - 1);
  }
  while ( v11 );
  alloc_tx_event("\x9B""0x40320514=%08x\r\n", *(volatile uint32_t *)off_12F288);
  alloc_tx_event("\x9B""0x40320518=%08x\r\n", *(volatile uint32_t *)off_12F290);
  alloc_tx_event("\x9B""0x4032051c=%08x\r\n", *(volatile uint32_t *)off_12F298);
  alloc_tx_event("\x9B""0x40320520=%08x\r\n", *(volatile uint32_t *)off_12F2A0);
  return alloc_tx_event("\x9B""0x40320560=%08x\r\n", *(volatile uint32_t *)off_12F2A8);
}


// unknown_12f2c8 @ 0x12f2c8
/* luna: Emits an ASSERT diagnostic with the failed expression, source file, and line, then performs configured RF and interrupt cleanup. */
int unknown_12f2c8(int a1, int a2, int a3) {
  volatile int *v3; // r4
  int result; // r0
  int v5; // r3
  int v6; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_12F31C = 1;
  }
  v3 = (volatile int *)off_12F320;
  ++*(volatile uint32_t *)off_12F320;
  result = alloc_tx_event("\x9B""ASSERT (%s) at %s:%d\n", (const volatile char *)a1, (const volatile char *)a2, a3 & 0xFFFFF);
  if ( *(volatile int *)off_12F328 >= 0 )
  {
    rf_irq_clear_1();
    result = irq_disable_global_2(0x80000000);
  }
  if ( *v3 )
  {
    v5 = *v3 - 1;
    v6 = *(volatile uint32_t *)off_12F31C;
    *v3 = v5;
    if ( !v5 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
  return result;
}


// irq_disable_mmio_write @ 0x12f32c
/* luna: Disables interrupts, emits an ASSERT diagnostic with the expression, file, and line, then spins until a volatile word clears. */
int irq_disable_mmio_write(int a1, int a2, int a3) {
  int result; // r0

  __disable_irq();
  *(volatile uint32_t *)off_12F350 = 0;
  result = alloc_tx_event("\x9B""ASSERT (%s) at %s:%d\n", (const volatile char *)a1, (const volatile char *)a2, a3 & 0xFFFFF);
while ( *(volatile uint32_t *)(uintptr_t)(off_12F358) ) ;
  return result;
}


// mmio_write_field @ 0x12f35c
/* luna: Emits a warning identifying the function, source file, and line number. */
int mmio_write_field(int a1, int a2, int a3) {
  return alloc_tx_event("\x9BWARNING (%s) at %s:%d\n", (const volatile char *)a1, (const volatile char *)a2, a3 & 0xFFFFF);
}


// unknown_12f378 @ 0x12f378
void unknown_12f378() {
  volatile uint32_t *v0; // r3
  int v1; // r2
  int v2; // r1
  volatile uint32_t *v3; // r1

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_12F3A0 = 1;
  }
  v0 = (void *)(uintptr_t)(off_12F3A4);
  v1 = *(volatile uint32_t *)off_12F3A4;
  v2 = *(volatile uint32_t *)off_12F3A4 + 1;
  *(volatile uint32_t *)off_12F3A4 = v2;
  if ( v2 )
  {
    v3 = (void *)(uintptr_t)(off_12F3A0);
    *v0 = v1;
    if ( !v1 )
    {
      if ( *v3 )
        __enable_irq();
    }
  }
}



// lock_init_0x18274c @ 0x12f3a8
/* luna: Initializes the global 8-byte lock state to 0x00000002FFFFFFFF and returns its address. */
volatile int *lock_init_0x18274c() {
  volatile uint64_t *v0; // r4
  volatile int *result; // r0

  v0 = (void *)(uintptr_t)(off_12F3C4);
  result = memset((volatile int *)off_12F3C4, 0, 8u);
  *v0 = 0x2FFFFFFFFLL;
  return result;
}



// timer_init_0x1922d4 @ 0x12f3c8
/* luna: Zero-initializes the global test-statistics state and clears its embedded statistics buffer. */
int timer_init_0x1922d4() {
  int v0; // r4

  v0 = dword_12F3E4;
  memset((volatile int *)dword_12F3E4, 0, 0x10u);
  clear_stats_buf((volatile uint32_t *)(v0 + 8));
  return 0;
}



// phy_rate_map @ 0x12f3e8
/* luna: Returns the result of the event-flag check. */
int phy_rate_map() {
  return check_event_flag();
}



// state_check_0x182ba0 @ 0x12f3ec
/* luna: Forwards the supplied pointer to `rx_packet_dispatch` and returns its result. */
int state_check_0x182ba0(volatile uint16_t *a1) {
  return (int)(uintptr_t)(rx_packet_dispatch((int)(uintptr_t)(a1)));
}



// phy_mode_check @ 0x12f3f0
int phy_mode_check() {
  return 2;
}



// j_nullsub_6 @ 0x12f3f4
/* luna: Calls the null stub and returns its result without performing any additional work. */
int j_nullsub_6(void) {
  return nullsub_6();
}



// phy_mode_check_1 @ 0x12f3f8
/* luna: Returns zero only when the mode byte is 3 and the context word at offset 612 is zero, writing 32 to the associated status globals along the way. */
int phy_mode_check_1() {
  int result; // r0

  if ( **(volatile uint8_t **)off_12F40C != 3 )
    return 1;
  result = *(volatile uint32_t *)(*(volatile uint32_t *)off_10CA98 + 612);
  *(volatile uint32_t *)off_10CA9C = 32;
  if ( result )
    return 1;
  *(volatile uint32_t *)off_10CAA0 = 32;
  return result;
}



// list_foreach_1 @ 0x12f410
/* luna: Forwards the call to the event handler and returns its result. */
int list_foreach_1() {
  return invoke_event_handler();
}



// deref_and_check @ 0x12f414
/* luna: Drains a linked list, dispatching entries with a nonzero field at offset 12 and otherwise clearing the associated object's 16-bit field at offset 8. */
volatile int * deref_and_check(volatile int *result, int a2) {
  volatile uint32_t *v2; // r4
  volatile int *v3; // r6
  volatile int *v4; // r5
  int v5; // r2

  v2 = (volatile uint32_t *)*result;
  if ( *result )
  {
    v3 = (volatile int *)dword_12F444;
    v4 = result;
    do
    {
      while ( 1 )
      {
        list_pop((int)v4);
        result = v3;
        if ( !v2[3] )
          break;
        result = (volatile int *)wlan_ioctl_handler_1((int)v3, v2);
        v2 = (volatile uint32_t *)*v4;
        if ( !*v4 )
          return result;
      }
      v5 = v2[2];
      v2 = (volatile uint32_t *)*v4;
      *(volatile uint16_t *)(v5 + 8) = 0;
    }
    while ( v2 );
  }
  return result;
}


// state_check_0x182ba0_b @ 0x12f448
/* luna: In state 3, tags and copies a 28-byte RF-test message into an alternate buffer, waits for the ioctl handshake, forwards it, and resets RF command stat */
int state_check_0x182ba0_b(int result) {
  int v1; // r4
  volatile char *v2; // r0
  volatile char *v3; // r5
  volatile uint32_t *v4; // r4

  if ( **(volatile uint8_t **)off_12F49C == 3 )
  {
    v1 = result;
    v2 = (volatile char *)invoke_alt_handler();
    v3 = v2;
    if ( v2 )
    {
      *(volatile uint32_t *)(v1 + 24) = 49374;
      memcpy(v2, (volatile char *)v1, 0x1Cu);
      v4 = (void *)(uintptr_t)(off_12F4A0);
      while ( !*(volatile uint32_t *)off_12F4A0 )
        ;
      wlan_ioctl_handler_1(((volatile uint32_t *)(uintptr_t)off_12F4A4)[0] + 604, (volatile uint32_t *)v3 - 1);
      *v4 = 1;
      rf_cmd_reset();
    }
    else
    {
      return alloc_tx_event(aErrUfHostRxBuf);
    }
  }
  return result;
}


// return_fail @ 0x12f4ac
/* luna: Requests an RX buffer using a zero allocation argument and returns the allocator's result. */
int return_fail() {
  return alloc_rx_buffer(0);
}



// unknown_12f4b4 @ 0x12f4b4
/* luna: Calls the string setter within a nesting-aware IRQ guard, decrements the indexed byte counter for indices 0–4, and decrements a global counter before  */
int unknown_12f4b4(unsigned int a1, int a2) {
  volatile int *v3; // r5
  int result; // r0
  int v5; // r3
  int v6; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_12F504 = 1;
  }
  v3 = (volatile int *)off_12F508;
  ++*(volatile uint32_t *)off_12F508;
  result = set_string_0x182588((volatile uint32_t *)a2);
  if ( a1 <= 4 )
    --*(volatile uint8_t *)(dword_12F50C + a1);
  if ( *v3 )
  {
    v5 = *v3 - 1;
    v6 = *(volatile uint32_t *)off_12F504;
    *v3 = v5;
    if ( !v5 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
  --*((volatile uint32_t *)off_12F510 + 126);
  return result;
}


// get_buffer_size @ 0x12f514
/* luna: Returns the fixed buffer size of 1024 bytes. */
int get_buffer_size() {
  return 1024;
}



// parse_rx_packet_header @ 0x12f51c
/* luna: Erases the final input character, redrawing the remaining text with tab-stop-aware cursor handling when the erased character is a tab. */
unsigned int parse_rx_packet_header(unsigned int a1, int a2, int a3) {
  unsigned int last_char_ptr; // r7
  volatile int *column_ptr; // r5
  volatile uint8_t *erase_sequence; // r9
  int column; // r3
  int tab_fill_table; // r8
  volatile uint8_t *redraw_ptr; // r4
  volatile uint8_t *redraw_last_ptr; // r6
  int current_char; // t1

  last_char_ptr = a2 - 1;
  if ( *(volatile uint8_t *)(a2 - 1) == 9 )
  {
    column_ptr = (volatile int *)off_12F5AC;
    if ( a3 < (int)*(volatile uint32_t *)off_12F5AC )
    {
      erase_sequence = (volatile uint8_t *)dword_12F5B4;
      do
      {
        radio_tx_write_string(erase_sequence);
        column = *column_ptr - 1;
        *column_ptr = column;
      }
      while ( column > a3 );
    }
    if ( last_char_ptr > a1 )
    {
      tab_fill_table = dword_12F5B8;
      redraw_ptr = (volatile uint8_t *)(a1 - 1);
      redraw_last_ptr = (volatile uint8_t *)(a2 - 2);
      do
      {
        while ( 1 )
        {
          current_char = *++redraw_ptr;
          if ( current_char == 9 )
            break;
          ++*column_ptr;
          radio_tx_write_byte(*redraw_ptr);
          if ( redraw_ptr == redraw_last_ptr )
            goto LABEL_10;
        }
        radio_tx_write_string((volatile uint8_t *)((*column_ptr & 7) + tab_fill_table));
        *column_ptr = (*column_ptr & 0xFFFFFFF8) + 8;
      }
      while ( redraw_ptr != redraw_last_ptr );
    }
  }
  else
  {
    radio_tx_write_string((volatile uint8_t *)dword_12F5B4);
    --*(volatile uint32_t *)off_12F5AC;
  }
LABEL_10:
  --*(volatile uint32_t *)off_12F5B0;
  return last_char_ptr;
}



// skip_leading_spaces @ 0x12f5bc
/* luna: Destructively splits a mutable argument string on spaces and tabs into a pointer array, removing double-quote delimiters for quoted tokens and limitin */
int skip_leading_spaces(volatile uint8_t *a1, int a2) {
  int token_count; // r4
  volatile uint8_t *scan_ptr; // r0
  int v5; // r2
  int v6; // t1
  int v7; // r3
  int v8; // r5
  int v9; // r6
  int v10; // t1
  volatile uint8_t *v12; // r2
  int v13; // r3
  int v14; // t1

  token_count = 0;
  while ( 1 )
  {
    do
    {
      do
      {
        scan_ptr = a1;
        v6 = *a1++;
        v5 = v6;
      }
      while ( v6 == 32 );
    }
    while ( v5 == 9 );
    if ( !v5 )
    {
      *(volatile uint32_t *)(a2 + 4 * token_count) = 0;
      return token_count;
    }
    if ( v5 == 34 )
      break;
    *(volatile uint32_t *)(a2 + 4 * token_count) = (int)(uintptr_t)(scan_ptr);
    v7 = *scan_ptr;
    v8 = token_count + 1;
    v9 = token_count + 1;
    if ( !*scan_ptr )
      goto LABEL_20;
    while ( v7 != 32 && v7 != 9 )
    {
      v10 = *++scan_ptr;
      v7 = v10;
      if ( !v10 )
        goto LABEL_20;
    }
LABEL_11:
    if ( !*scan_ptr )
      goto LABEL_20;
    *scan_ptr = 0;
    a1 = scan_ptr + 1;
    token_count = v9;
    if ( v9 == 16 )
    {
      radio_tx_write_string((volatile uint8_t *)dword_12F644);
      return 16;
    }
  }
  v12 = scan_ptr + 1;
  *(volatile uint32_t *)(a2 + 4 * token_count) = (int)(uintptr_t)(scan_ptr + 1);
  v13 = scan_ptr[1];
  v8 = token_count + 1;
  v9 = token_count + 1;
  if ( scan_ptr[1] )
  {
    while ( v13 != 34 )
    {
      v14 = *++v12;
      v13 = v14;
      if ( !v14 )
        goto LABEL_20;
    }
    scan_ptr = v12;
    goto LABEL_11;
  }
LABEL_20:
  *(volatile uint32_t *)(a2 + 4 * v9) = 0;
  return v8;
}



// split_on_dot @ 0x12f648
/* luna: Finds an entry whose name exactly matches the input segment before the first dot, or returns the sole entry whose name begins with that segment. */
volatile uint32_t * split_on_dot(int a1, volatile uint32_t *a2, int a3) {
  int v5; // r0
  int v6; // r11
  int v7; // r9
  volatile uint32_t *v8; // r4
  int v9; // r5
  int v10; // r6
  volatile uint32_t *v11; // r10

  v5 = (int)(uintptr_t)(strchr((void *)(uintptr_t)(a1), 46));
  if ( v5 )
    v6 = v5 - a1;
  else
    v6 = memcpy_aligned(a1);
  if ( a3 )
  {
    v7 = 0;
    v8 = a2;
    v9 = 0;
    do
    {
      while ( 1 )
      {
        v10 = *v8;
        ++v9;
        v11 = v8;
if ( !memcpy_fixed((void *)(uintptr_t)(a1), (void *)(uintptr_t)(*v8), v6) ) break;
        v8 += 4;
        if ( a3 == v9 )
          goto LABEL_9;
      }
      if ( memcpy_aligned(v10) == v6 )
        return v11;
      a2 = v8;
      ++v7;
      v8 += 4;
    }
    while ( a3 != v9 );
LABEL_9:
    if ( v7 == 1 )
      return a2;
  }
  return 0;
}



// lock_global_mutex @ 0x12f6d0
/* luna: Processes a console keystroke, updating the input line and returning its completion or cancellation status. */
int lock_global_mutex(unsigned int a1, volatile uint8_t *a2, int a3) {
  volatile int *v3; // r6
  char v4; // r4
  volatile int *v6; // r7
  volatile uint32_t *v7; // r3
  int v8; // r2
  volatile int *v9; // r8
  int result; // r0
  int v11; // r0
  volatile int *v12; // r2
  volatile uint32_t *v13; // r3
  volatile int *v14; // r8
  int v15; // r1
  unsigned int v16; // r0
  volatile uint8_t *v17; // r0
  int v18; // r2
  int v19; // r3
  unsigned int v20; // r1
  volatile uint8_t *v21; // r0
  volatile uint32_t *v22; // r3
  volatile uint8_t *v23; // r3
  int v24; // r2

  v3 = (volatile int *)off_12F800;
  v4 = a1;
  if ( *(volatile uint32_t *)off_12F800 )
  {
    if ( !a3 )
      goto LABEL_3;
LABEL_11:
    v11 = memcpy_aligned(a3);
    v12 = (volatile int *)off_12F804;
    v13 = (void *)(uintptr_t)(off_12F80C);
    *v3 = (int)a2;
    *v12 = v11;
    *v13 = 0;
    return 0;
  }
  *(volatile uint32_t *)off_12F800 = (int)(uintptr_t)(a2);
  if ( a3 )
    goto LABEL_11;
LABEL_3:
  v6 = (volatile int *)off_12F804;
  v7 = (void *)(uintptr_t)(off_12F808);
  v8 = *(volatile uint32_t *)off_12F804;
  *(volatile uint32_t *)off_12F808 = *(volatile uint32_t *)off_12F804;
  if ( a1 <= 0x17 )
  {
    switch ( a1 )
    {
      case 0u:
        return -1;
      case 3u:
        result = 0;
        *a2 = 0;
        return result;
      case 8u:
        goto LABEL_19;
      case 0xAu:
      case 0xDu:
        v21 = (volatile uint8_t *)dword_12F810;
        *(volatile uint8_t *)*v3 = 0;
        radio_tx_write_string(v21);
        return *v3 - (uint32_t)a2;
      case 0x15u:
        v22 = (void *)(uintptr_t)(off_12F80C);
        *v3 = (int)a2;
        *v22 = 0;
        return -1;
      case 0x17u:
        v14 = (volatile int *)off_12F80C;
        v15 = *v3;
        if ( *(volatile uint32_t *)off_12F80C )
        {
          v16 = (unsigned int)a2;
          while ( 1 )
          {
            v17 = (volatile uint8_t *)parse_rx_packet_header(v16, v15, v8);
            v18 = *v14;
            *v3 = (int)v17;
            v15 = (int)v17;
            if ( v18 <= 0 )
              break;
            v19 = *v17;
            v16 = (unsigned int)a2;
            if ( v19 == 32 )
              break;
            v8 = *v6;
          }
        }
        return -1;
      default:
        v9 = (volatile int *)off_12F80C;
        if ( *(volatile int *)off_12F80C > 61 )
          goto LABEL_7;
        if ( a1 != 9 )
          goto LABEL_28;
        radio_tx_write_string((volatile uint8_t *)(dword_12F814 + (v8 & 7)));
        *(volatile uint32_t *)off_12F808 = (*(volatile uint32_t *)off_12F808 & 0xFFFFFFF8) + 8;
        break;
    }
    goto LABEL_27;
  }
  if ( a1 == 127 )
  {
LABEL_19:
    v20 = *v3;
    if ( *(volatile uint32_t *)off_12F80C )
      v20 = parse_rx_packet_header((unsigned int)a2, v20, v8);
    *v3 = v20;
    return -1;
  }
  else
  {
    v9 = (volatile int *)off_12F80C;
    if ( *(volatile int *)off_12F80C <= 61 )
    {
LABEL_28:
      *v7 = v8 + 1;
      radio_tx_write_byte(a1);
LABEL_27:
      v23 = (volatile uint8_t *)*v3;
      *v23 = v4;
      v24 = *v9 + 1;
      *v3 = (int)(v23 + 1);
      *v9 = v24;
      return -1;
    }
LABEL_7:
    radio_tx_write_byte(7);
    return -1;
  }
}



// parse_uint_base @ 0x12f818
/* luna: Parses a signed integer using the requested base, with base zero selecting octal for a leading zero and decimal otherwise, accepts a valid `0x` prefix */
int parse_uint_base(volatile uint8_t *a1, volatile uint32_t *a2, unsigned int a3) {
  int current_char; // r5
  int is_negative; // r7
  int i; // r6
  unsigned int digit_value; // r3
  int next_char; // t1
  int v9; // r3
  int v10; // r3

  current_char = *a1;
  if ( current_char == 48 )
  {
    current_char = a1[1];
    if ( (unsigned int)(current_char - 65) > 0x19 )
      v9 = a1[1];
    else
      v9 = (uint8_t)(current_char + 32);
    if ( v9 == 120 && ((v10 = a1[2], (unsigned int)(v10 - 48) <= 9) || (v10 & 0xFFFFFFDF) - 65 <= 5) )
    {
      a1 += 2;
      current_char = v10;
      a3 = 16;
    }
    else
    {
      ++a1;
      if ( !a3 )
      {
        a3 = 8;
        if ( current_char != 45 )
          goto LABEL_5;
LABEL_25:
        is_negative = 1;
        current_char = *++a1;
        goto LABEL_6;
      }
    }
  }
  else if ( !a3 )
  {
    a3 = 10;
  }
  if ( current_char == 45 )
    goto LABEL_25;
LABEL_5:
  is_negative = 0;
LABEL_6:
  for ( i = 0; ; i = digit_value + i * a3 )
  {
    digit_value = current_char - 48;
    if ( (uint8_t)(current_char - 48) > 9u )
    {
      if ( (current_char & 0xFFFFFFDF) - 65 > 5 )
        break;
      if ( (unsigned int)(current_char - 97) > 0x19 )
        digit_value = current_char - 55;
      else
        digit_value = (uint8_t)(current_char - 32) - 55;
    }
    if ( a3 <= digit_value )
      break;
    next_char = *++a1;
    current_char = next_char;
  }
  if ( is_negative )
    i = -i;
  if ( a2 )
    *a2 = (int)(uintptr_t)(a1);
  return i;
}



// setup_global_table @ 0x12f8c4
/* luna: Logs the two string fields of each populated entry in the global table. */
int setup_global_table() {
  unsigned int v0; // r4
  unsigned int v1; // r5
  const volatile char *v2; // r2

  v0 = off_12F8E4;
  v1 = off_12F8E4 + 112;
  do
  {
    v2 = *(const volatile char **)(v0 + 4);
    if ( v2 )
      debug_printf("%s %s\r\n", *(const volatile char **)v0, v2);
    v0 += 16;
  }
  while ( v0 != v1 );
  return 0;
}


// is_two_char_string @ 0x12f8ec
/* luna: Returns 1 for a trailing `.b`, 2 for `.h`, 4 when no qualifying suffix is present, and -1 for another suffix after a nonempty prefix. */
int is_two_char_string(int a1) {
  int v2; // r0
  int v3; // r0
  int v5; // r3

  v2 = memcpy_aligned(a1);
  if ( v2 <= 2 )
    return 4;
  v3 = v2 + a1;
  if ( *(volatile uint8_t *)(v3 - 2) != 46 )
    return 4;
  v5 = *(volatile uint8_t *)(v3 - 1);
  if ( v5 == 98 )
    return 1;
  if ( v5 == 104 )
    return 2;
  return -1;
}



// parse_hex_string @ 0x12f920
/* luna: Parses a test memory-access command and either prints a volatile read of the requested width or forwards the supplied value to the packet-parameter ha */
int parse_hex_string(int a1, volatile uint32_t *a2) {
  unsigned int v4; // r5
  int v5; // r0
  int v7; // r3
  int v8; // r0
  int a2a; // [sp+4h] [bp-4h]

  v4 = parse_uint_base((volatile uint8_t *)a2[1], nullptr, 0x10u);
  if ( a1 <= 2 )
  {
    v5 = is_two_char_string(*a2);
    if ( v5 >= 0 )
      goto LABEL_3;
LABEL_18:
    debug_printf("Unknown data size:%d\r\n", v5);
    return -1;
  }
  a2a = parse_uint_base((volatile uint8_t *)a2[2], nullptr, 0);
  v5 = is_two_char_string(*a2);
  if ( v5 < 0 )
    goto LABEL_18;
  if ( a2a == 1 )
  {
LABEL_3:
    if ( ((v4 >> 20) & 0xFFFFFDFF) == 0x500 )
    {
      v8 = call_patch_hook_0();
      debug_printf("[0x%08X] = 0x%08X\r\n", v4 & 0xFFFFFFFC, v8);
      return 0;
    }
    else if ( v5 == 4 )
    {
      debug_printf("[0x%08lX] = 0x%08lX\r\n", v4, *(volatile uint32_t *)v4);
      return 0;
    }
    else if ( v5 == 2 )
    {
      debug_printf("[0x%08lX] = 0x%04X\r\n", v4, *(volatile uint16_t *)v4);
      return 0;
    }
    else
    {
      if ( v5 == 1 )
        debug_printf("[0x%08lX] = 0x%02X\r\n", v4, *(volatile uint8_t *)v4);
      return 0;
    }
  }
  v7 = *(volatile uint8_t *)*a2 == 82 && v4 < 0x40000000;
  process_packet_params(v4, a2a, (uint8_t)v5, v7);
  return 0;
}


// parse_mac_string @ 0x12fa08
/* luna: Parses a write width, hexadecimal address and value, and optional repeat count, then writes the value to successive addresses or invokes the patch hoo */
int parse_mac_string(int a1, volatile uint32_t *a2) {
  int width_bytes; // r10
  unsigned int address; // r4
  int value; // r6
  int writes_remaining; // r5
  unsigned int aligned_address; // r4
  int repeat_count; // r0

  width_bytes = is_two_char_string(*a2);
  if ( width_bytes < 0 )
  {
    debug_printf("Unknown data size:%d\r\n", width_bytes);
    return -1;
  }
  else
  {
    address = parse_uint_base((volatile uint8_t *)a2[1], nullptr, 0x10u);
    value = parse_uint_base((volatile uint8_t *)a2[2], nullptr, 0x10u);
    if ( a1 <= 3 )
    {
      writes_remaining = 0;
      goto LABEL_9;
    }
    repeat_count = parse_uint_base((volatile uint8_t *)a2[3], nullptr, 0);
    if ( repeat_count )
    {
      writes_remaining = repeat_count - 1;
      do
      {
LABEL_9:
        while ( ((address >> 20) & 0xFFFFFDFF) == 0x500 )
        {
          aligned_address = address & 0xFFFFFFFC;
          debug_printf("[0x%08X] = 0x%08lX\r\n", aligned_address, value);
          --writes_remaining;
          call_patch_hook_1();
          address = aligned_address + width_bytes;
          if ( writes_remaining == -1 )
            return 0;
        }
        switch ( width_bytes )
        {
          case 4:
            debug_printf("[0x%08lX] = 0x%08lX\r\n", address, value);
            *(volatile uint32_t *)address = value;
            break;
          case 2:
            debug_printf("[0x%08lX] = 0x%04X\r\n", address, (uint16_t)value);
            *(volatile uint16_t *)address = value;
            break;
          case 1:
            debug_printf("[0x%08lX] = 0x%02X\r\n", address, (uint8_t)value);
            *(volatile uint8_t *)address = value;
            break;
        }
        --writes_remaining;
        address += width_bytes;
      }
      while ( writes_remaining != -1 );
    }
    return 0;
  }
}


// parse_decimal_string @ 0x12faf8
/* luna: Prints the current debug mask and module selector, or updates one from a hexadecimal argument selected by a decimal operation code. */
int parse_decimal_string(int a1, int a2) {
  int operation_code; // r0
  uint16_t debug_mask; // r0
  int current_debug_module; // r0
  int debug_module; // r4

  operation_code = parse_uint_base(*(volatile uint8_t **)(a2 + 4), nullptr, 0xAu);
  if ( operation_code )
  {
    if ( operation_code == 1 )
    {
      if ( a1 <= 2 )
        goto LABEL_5;
      debug_mask = parse_uint_base(*(volatile uint8_t **)(a2 + 8), nullptr, 0x10u);
      **(volatile uint16_t **)off_12FB8C = debug_mask;
      alloc_tx_event("cfg dbg_msk: 0x%x\n", debug_mask);
      return 0;
    }
    else if ( operation_code == 2 )
    {
      if ( a1 <= 2 )
      {
LABEL_5:
        alloc_tx_event(aInvalidArgs);
        return 0;
      }
      debug_module = parse_uint_base(*(volatile uint8_t **)(a2 + 8), nullptr, 0x10u);
      alloc_tx_event("cfg dbg mod: %08X\n", debug_module);
      set_global_field0(debug_module);
      return 0;
    }
    else
    {
      alloc_tx_event("invalid func: %d\n", operation_code);
      return 0;
    }
  }
  else
  {
    alloc_tx_event("cur dbg_msk: 0x%x\n", **(volatile uint16_t **)off_12FB8C);
    current_debug_module = get_global_field0();
    alloc_tx_event("dbg mod: %08X\n", current_debug_module);
    return 0;
  }
}


// is_compact_mac_string @ 0x12fba4
/* luna: Validates 12-digit hexadecimal MAC and BSSID strings, programs the monitor address state, and logs the selected addresses. */
int is_compact_mac_string(int a1, int a2) {
  int v3; // r6
  unsigned int mac_upper32; // r6
  uint16_t v5; // r0
  int v6; // r5
  uint16_t mac_lower16; // r7
  unsigned int bssid_upper32; // r8
  volatile uint32_t *v9; // r0
  volatile uint32_t *v10; // r1
  volatile uint32_t *v11; // r12
  volatile uint32_t *v12; // lr
  volatile uint32_t *v13; // r3
  volatile uint32_t *v14; // r9
  volatile uint32_t *v15; // lr
  volatile uint32_t *v16; // r0
  volatile uint32_t *v17; // r12
  volatile unsigned int *v18; // r1
  unsigned int v19; // r3
  volatile char *v20; // r0
  volatile int *v21; // r12
  int v22; // lr
  int v23; // r9
  struct __attribute__((packed)) { char a1a[4]; // [sp+8h] [bp-Ch] BYREF
  char v26; // [sp+Ch] [bp-8h]
  } _frame;
  if ( memcpy_aligned(*(volatile uint32_t *)(a2 + 4)) != 12 || memcpy_aligned(*(volatile uint32_t *)(a2 + 8)) != 12 )
    return -2;
  v3 = *(volatile uint32_t *)(a2 + 4);
  memcpy(_frame.a1a, (volatile char *)(v3 + 8), 4u);
  *(volatile uint8_t *)(v3 + 8) = 0;
  _frame.v26 = 0;
  mac_upper32 = parse_uint_base((volatile uint8_t *)v3, nullptr, 0x10u);
  v5 = parse_uint_base((volatile uint8_t *)_frame.a1a, nullptr, 0x10u);
  v6 = *(volatile uint32_t *)(a2 + 8);
  mac_lower16 = v5;
  memcpy(_frame.a1a, (volatile char *)(v6 + 8), 4u);
  *(volatile uint8_t *)(v6 + 8) = 0;
  _frame.v26 = 0;
  bssid_upper32 = parse_uint_base((volatile uint8_t *)v6, nullptr, 0x10u);
  v6 = (v6 & ~0xFFFFu) | ((uint16_t)(parse_uint_base((volatile uint8_t *)_frame.a1a, nullptr, 0x10u)) & 0xFFFFu);
  alloc_tx_event(aSetMonitor);
  v9 = (void *)(uintptr_t)(off_12FD18);
  v10 = (void *)(uintptr_t)(off_12FD1C);
  v11 = (void *)(uintptr_t)(off_12FD44);
  v12 = (void *)(uintptr_t)(off_12FD48);
  v13 = (void *)(uintptr_t)(off_12FD20);
  *(volatile uint32_t *)off_12FD14 = 512;
  *v12 = 7;
  *v9 = 7;
  *v10 = 7;
  *v11 = 7;
  *v13 = 7;
  v9[4] = 7;
  v13 -= 495296;
  v10[4] = 7;
  v11[4] = 7;
  *v13 = 9816;
  *(v9 - 457703) = 50529027;
  *(v10 - 457698) = dword_12FD24;
  v14 = (void *)(uintptr_t)(off_12FD4C);
  v15 = (void *)(uintptr_t)(off_12FD50);
  v16 = (void *)(uintptr_t)(off_12FD2C);
  v13[37597] = dword_12FD28;
  v17 = (void *)(uintptr_t)(off_12FD54);
  v18 = (volatile unsigned int *)off_12FD30;
  *v14 = -1;
  *v15 = -1;
  *v16 = -1;
  *v17 = -1;
  *v18 = bswap32(mac_upper32);
  v18 += 4;
  *(volatile uint32_t *)off_12FD34 = __rev16(mac_lower16);
  v19 = bswap32(bssid_upper32);
  *v18 = v19;
  v20 = (volatile char *)off_12FD38;
  *(volatile uint32_t *)off_12FD38 = __rev16((uint16_t)v6);
  *(v18 - 380) = v19;
  v21 = (volatile int *)off_12FD58;
  v22 = dword_12FD5C;
  v23 = dword_12FD60;
  *(volatile uint32_t *)off_12FD3C = __rev16((uint16_t)v6);
  *(volatile uint32_t *)&v20[-148] = 7;
  *(volatile uint32_t *)&v20[-148] = v23;
  *v21 = v22;
  alloc_tx_event("set mon: mac=%08x%04x, bssid=%08x%04x\n", mac_upper32, mac_lower16, bssid_upper32, (uint16_t)v6);
  return 0;
}


// parse_format_switch @ 0x12fd64
/* luna: Displays the current debug severity when no command is selected, or sets it to a validated index from 0 through 5. */
int parse_format_switch(int a1, int a2) {
  int command; // r0
  int current_severity; // r0
  unsigned int severity_index; // r4

  if ( a1 <= 1 || (command = parse_uint_base(*(volatile uint8_t **)(a2 + 4), nullptr, 0)) == 0 )
  {
    current_severity = get_global_field4();
    alloc_tx_event("dbg sev: %d\n", current_severity);
    return 0;
  }
  if ( command == 1 )
  {
    if ( a1 == 2 )
    {
      alloc_tx_event(aInvalidArgs);
    }
    else
    {
      severity_index = parse_uint_base(*(volatile uint8_t **)(a2 + 8), nullptr, 0);
      if ( severity_index > 5 )
      {
        alloc_tx_event("invalid sev_idx:%d\n", severity_index);
      }
      else
      {
        alloc_tx_event("Cfg dbg sev: %d\n", severity_index);
        set_global_field4(severity_index);
      }
    }
    return 0;
  }
  alloc_tx_event(aInvalidFunc);
  return 0;
}


// mode_dispatch @ 0x12fde0
/* luna: Parses temperature-compensation enable and optional period values, updates shared RF state and signals changes, or invokes the transmit-power lookup w */
int mode_dispatch(int a1, int a2) {
  unsigned int v4; // r0
  int v5; // r1
  int v6; // r7
  unsigned int v7; // r6
  volatile int *v8; // r4

  if ( a1 == 1 )
  {
    rf_tx_power_lookup();
    return 0;
  }
  else
  {
    v4 = parse_uint_base(*(volatile uint8_t **)(a2 + 4), nullptr, 0);
    v6 = v4;
    if ( v4 )
      v6 = 1;
    v7 = v4;
    if ( a1 > 2 )
    {
      v8 = (volatile int *)off_12FE50;
      v4 = parse_uint_base(*(volatile uint8_t **)(a2 + 8), nullptr, 0);
      if ( v4 > 0x7D0 )
        v8[91] = v4;
    }
    else
    {
      v8 = (volatile int *)off_12FE50;
    }
    if ( *((volatile uint8_t *)v8 + 363) != v6 )
    {
      *((volatile uint8_t *)v8 + 363) = v6;
      if ( v7 )
      {
        read_global_signed_flag(v4, v5);
        set_flag_send_event_42e();
      }
      else
      {
        clear_flag_send_event_42e();
      }
    }
    alloc_tx_event("temp_comp en=%d, peroid_ms=%d\n", v6, v8[91]);
    return 0;
  }
}


// debug_assert @ 0x12fe58
/* luna: Checks system readiness, enters a nested IRQ-protected section, clears two statistics buffers, and dispatches four WLAN ioctl handlers. */
int debug_assert() {
  volatile int *v0; // r4
  volatile uint32_t *v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  system_ready_check();
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_12FEB8 = 1;
  }
  v0 = (volatile int *)off_12FEBC;
  v1 = (volatile uint32_t *)dword_12FEC0;
  ++*(volatile uint32_t *)off_12FEBC;
  clear_stats_buf(v1);
  clear_stats_buf((volatile uint32_t *)dword_12FEC4);
  wlan_ioctl_handler_1(dword_12FEC0, (volatile uint32_t *)dword_12FEC8);
  wlan_ioctl_handler_1(dword_12FEC0, (volatile uint32_t *)dword_12FECC);
  wlan_ioctl_handler_1(dword_12FEC0, (volatile uint32_t *)dword_12FED0);
  result = wlan_ioctl_handler_1(dword_12FEC0, (volatile uint32_t *)dword_12FED4);
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(volatile uint32_t *)off_12FEB8;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}


// lock_with_timeout @ 0x12fed8
/* luna: Processes a command-like string, forwarding non-`aic` input to a queued handler and dumping CPU stack state while updating a diagnostic flag for the ` */
int lock_with_timeout(int a1) {
  int v1; // r0
  int v2; // r4
  volatile uint32_t *v4; // r0
  volatile uint32_t *v5; // r5
  unsigned int CPSR; // r1
  unsigned int v7; // r2
  unsigned int v8; // r4
  unsigned int v9; // r5
  volatile uint8_t *v10; // r2
  int v11; // r0
  unsigned int v12; // r5
  unsigned int v13; // r6
  int v14; // t1
  unsigned int v15; // r4
  unsigned int v16; // r5
  int v17; // t1

  v1 = lock_global_mutex(a1, (volatile uint8_t *)dword_12FFF8, 0);
  v2 = v1;
  if ( v1 >= 0 )
  {
    if ( v1 )
    {
      if ( memcpy_aligned((unsigned int)asc_14B2A4) != v1
        || strcmp((unsigned int)asc_14B2A4, (volatile unsigned int *)dword_12FFF8) )
      {
        v4 = list_pop(dword_130004);
        v5 = v4;
        if ( v4 )
        {
          strcpy((unsigned int)(v4 + 1), dword_12FFF8);
          wlan_ioctl_handler_1(dword_130008, v5);
        }
        else
        {
          radio_tx_write_string(aErrCmdFreeList);
        }
      }
      else
      {
        CPSR = __get_CPSR();
        v7 = __get_CPSR();
        v8 = __get_CPSR();
        v9 = __get_CPSR();
        debug_printf(aControl08xXpsr, CPSR, v7, v8, v9, __get_CPSR(), __get_CPSR());
        if ( v9 )
        {
          v12 = v9 & 0xFFFFFFF0;
          radio_tx_write_string(aDumpmsp);
          v13 = v12 + 256;
          do
          {
            if ( !(v12 << 28) )
              debug_printf("\r\n[%08x]:", v12);
            v14 = *(volatile uint32_t *)v12;
            v12 += 4;
            debug_printf(" %08X", v14);
          }
          while ( v13 != v12 );
        }
        if ( v8 )
        {
          v15 = v8 & 0xFFFFFFF0;
          radio_tx_write_string(aDumppsp);
          v16 = v15 + 256;
          do
          {
            if ( !(v15 << 28) )
              debug_printf("\r\n[%08x]:", v15);
            v17 = *(volatile uint32_t *)v15;
            v15 += 4;
            debug_printf(" %08X", v17);
          }
          while ( v16 != v15 );
        }
        radio_tx_write_string(aAic_0);
        v10 = (void *)(uintptr_t)(off_130014);
        v11 = *(volatile uint8_t *)off_130014;
        if ( *(volatile uint8_t *)off_130014 )
        {
          *((volatile uint8_t *)off_130018 + 783) = -4;
          v2 = 0;
          *v10 = 0;
        }
        else
        {
          *((volatile uint8_t *)off_130018 + 783) = -12;
          v2 = v11;
          *v10 = 1;
        }
      }
    }
    else
    {
      radio_tx_write_string(aAic);
    }
    lock_global_mutex(0x30u, (volatile uint8_t *)dword_12FFF8, (unsigned int)aAic);
  }
  return v2;
}


