// get_controller_state @ 0x122e68
int get_controller_state(int a1, volatile uint8_t *a2, int a3, int a4) {
  int v4; // r7
  int v6; // r5
  int v9; // r0
  int v10; // r3

  v4 = dword_122EC8;
  v6 = *a2;
  if ( **(volatile int16_t **)off_122EC4 < 0 && *(volatile uint8_t *)(dword_122EC8 + 1320 * v6 + 106) )
    mmio_irq_clear(dword_122ED0, dword_122ECC, 2639);
  v9 = v4 + 1320 * v6;
  *(volatile uint16_t *)(v9 + 112) = *((volatile uint16_t *)a2 + 1);
  v10 = a2[4];
  *(volatile uint8_t *)(v9 + 114) = v10;
  ((int (*)())hci_evt_alloc_send)(76, a4, a3, v10);
  return 0;
}



// send_le_conn_update @ 0x122ed4
int send_le_conn_update(int a1, int a2, int a3, int a4) {
  *(volatile uint16_t *)(dword_122EF4 + 1320 * *(volatile uint8_t *)(a2 + 2) + 1222) = *(volatile uint16_t *)a2;
  ((int (*)())hci_evt_alloc_send)(112, a4, a3, a4);
  return 0;
}



// write_mmio_send_cmd @ 0x122ef8
int write_mmio_send_cmd(int a1, volatile uint32_t *a2, int a3, int a4) {
  *(volatile uint32_t *)off_122F0C = *a2;
  ((int (*)())hci_evt_alloc_send)(114, a4, a3, a4);
  return 0;
}



// is_valid_conn_handle @ 0x122f10
int is_valid_conn_handle(int a1, volatile char *a2, int a3, int a4) {
  int v4; // r0
  int v8; // r1
  volatile uint8_t *v9; // r2
  BOOL v10; // r0

  v4 = (uint8_t)a2[1];
  if ( v4 != 255 )
    rf_scan_start(v4);
  v8 = (uint8_t)*a2;
  v9 = (void *)(uintptr_t)(off_122F54);
  if ( *a2 )
    v8 = 1;
  v10 = a2[2] != 0;
  *(volatile uint8_t *)off_122F50 = v10;
  *v9 = v8;
  ke_event_schedule_1("set agg disable=%d, disable_rx=%d\n", v8, v10);
  hci_evt_alloc_send(100, a4, a3);
  return 0;
}


