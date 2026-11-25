// scan_state_validate @ 0x122af4
/* luna: Copies indexed state fields from the request into the scan table, conditionally masks an MMIO interrupt, and updates the associated MAC header word. */
int scan_state_validate(int a1, volatile uint8_t *a2, int a3, int a4) {
  int v4; // r7
  int v6; // r5
  int v9; // r0

  v4 = dword_122B54;
  v6 = *a2;
  if ( **(volatile int16_t **)off_122B50 < 0 && *(volatile uint8_t *)(dword_122B54 + 1320 * v6 + 106) )
    irq_disable_mmio_write(dword_122B5C, dword_122B58, 2639);
  v9 = v4 + 1320 * v6;
  *(volatile uint16_t *)(v9 + 112) = *((volatile uint16_t *)a2 + 1);
  *(volatile uint8_t *)(v9 + 114) = a2[4];
  mac_write_header_word(76, a4, a3);
  return 0;
}



// ipc_send_command_1 @ 0x122b60
/* luna: Stores the message identifier in the IPC slot selected by the message’s byte-2 index, then writes the associated header fields to MAC header word 112. */
int ipc_send_command_1(int a1, int a2, int a3, int a4) {
  *(volatile uint16_t *)(dword_122B80 + 1320 * *(volatile uint8_t *)(a2 + 2) + 1222) = *(volatile uint16_t *)a2;
  mac_write_header_word(112, a4, a3);
  return 0;
}



// ipc_mbox_write @ 0x122b84
/* luna: Writes the 32-bit value from the source pointer to the mailbox data register, then writes header word 114 using the supplied header arguments. */
int ipc_mbox_write(int a1, volatile uint32_t *a2, int a3, int a4) {
  *(volatile uint32_t *)off_122B98 = *a2;
  mac_write_header_word(114, a4, a3);
  return 0;
}



// ipc_msg_process @ 0x122b9c
/* luna: Applies aggregation-disable settings from the IPC payload, initializes the selected patch table when requested, and writes the response header. */
int ipc_msg_process(int a1, volatile char *a2, int a3, int a4) {
  int v4; // r0
  int disable_aggregation; // r1
  volatile uint8_t *v9; // r2
  BOOL disable_rx_aggregation; // r0

  v4 = (uint8_t)a2[1];
  if ( v4 != 255 )
    init_patch_table(v4);
  disable_aggregation = (uint8_t)*a2;
  v9 = (void *)(uintptr_t)(off_122BE0);
  if ( *a2 )
    disable_aggregation = 1;
  disable_rx_aggregation = a2[2] != 0;
  *(volatile uint8_t *)off_122BDC = disable_rx_aggregation;
  *v9 = disable_aggregation;
  alloc_tx_event("set agg disable=%d, disable_rx=%d\n", disable_aggregation, disable_rx_aggregation);
  mac_write_header_word(100, a4, a3);
  return 0;
}


