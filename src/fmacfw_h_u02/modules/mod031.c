// scan_state_validate @ 0x122af4
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
int ipc_send_command_1(int a1, int a2, int a3, int a4) {
  *(volatile uint16_t *)(dword_122B80 + 1320 * *(volatile uint8_t *)(a2 + 2) + 1222) = *(volatile uint16_t *)a2;
  mac_write_header_word(112, a4, a3);
  return 0;
}



// ipc_mbox_write @ 0x122b84
int ipc_mbox_write(int a1, volatile uint32_t *a2, int a3, int a4) {
  *(volatile uint32_t *)off_122B98 = *a2;
  mac_write_header_word(114, a4, a3);
  return 0;
}



// ipc_msg_process @ 0x122b9c
int ipc_msg_process(int a1, volatile char *a2, int a3, int a4) {
  int v4; // r0
  int v8; // r1
  volatile uint8_t *v9; // r2
  BOOL v10; // r0

  v4 = (uint8_t)a2[1];
  if ( v4 != 255 )
    init_patch_table(v4);
  v8 = (uint8_t)*a2;
  v9 = (void *)(uintptr_t)(off_122BE0);
  if ( *a2 )
    v8 = 1;
  v10 = a2[2] != 0;
  *(volatile uint8_t *)off_122BDC = v10;
  *v9 = v8;
  alloc_tx_event("set agg disable=%d, disable_rx=%d\n", v8, v10);
  mac_write_header_word(100, a4, a3);
  return 0;
}


