// hci_read_variant @ 0x122c34
int hci_read_variant(int a1, volatile uint8_t *a2, int a3, int a4) {
  int v4; // r7
  int v6; // r5
  int v9; // r0

  v4 = dword_122C94;
  v6 = *a2;
  if ( **(volatile int16_t **)off_122C90 < 0 && *(volatile uint8_t *)(dword_122C94 + 1320 * v6 + 106) )
    mmio_clear_register(dword_122C9C, dword_122C98, 2639);
  v9 = v4 + 1320 * v6;
  *(volatile uint16_t *)(v9 + 112) = *((volatile uint16_t *)a2 + 1);
  *(volatile uint8_t *)(v9 + 114) = a2[4];
  ke_msg_send_no_param(76, a4, a3);
  return 0;
}



// get_patch_table_entry @ 0x122ca0
int get_patch_table_entry(int a1, int a2, int a3, int a4) {
  *(volatile uint16_t *)(dword_122CC0 + 1320 * *(volatile uint8_t *)(a2 + 2) + 1222) = *(volatile uint16_t *)a2;
  ke_msg_send_no_param(112, a4, a3);
  return 0;
}



// set_mmio_and_send_cmd @ 0x122cc4
int set_mmio_and_send_cmd(int a1, volatile uint32_t *a2, int a3, int a4) {
  *(volatile uint32_t *)off_122CD8 = *a2;
  ke_msg_send_no_param(114, a4, a3);
  return 0;
}



// handle_special_packet @ 0x122cdc
int handle_special_packet(int a1, volatile char *a2, int a3, int a4) {
  int v4; // r0
  int v8; // r1
  volatile uint8_t *v9; // r2
  BOOL v10; // r0

  v4 = (uint8_t)a2[1];
  if ( v4 != 255 )
    rf_pll_calibrate(v4);
  v8 = (uint8_t)*a2;
  v9 = (void *)(uintptr_t)(off_122D20);
  if ( *a2 )
    v8 = 1;
  v10 = a2[2] != 0;
  *(volatile uint8_t *)off_122D1C = v10;
  *v9 = v8;
  event_dispatch("set agg disable=%d, disable_rx=%d\n", v8, v10);
  ke_msg_send_no_param(100, a4, a3);
  return 0;
}


