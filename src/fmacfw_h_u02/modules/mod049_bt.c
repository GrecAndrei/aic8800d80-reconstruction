// mem_alloc @ 0x1313d8
/* luna: Copies 254 bytes from the source buffer to a global staging buffer, then writes a MAC header word using the two 16-bit arguments. */
int mem_alloc(int a1, int a2, int16_t a3, int16_t a4) {
  memcpy((void *)(uintptr_t)(dword_1313F8), (void *)(uintptr_t)(a2), 254);
  mac_write_header_word(5123, a4, a3);
  return 0;
}



// rf_check_channel @ 0x1313fc
/* luna: Requests an allocation using the byte pointed to by `size_ptr` as its size, discards the returned pointer, and always returns zero. */
int rf_check_channel(int a1, volatile uint8_t *a2) {
  ke_malloc_wrapper(*a2);
  return 0;
}



// parse_adv_report @ 0x131408
/* luna: Updates per-entry status flags, emits an internal PDU when the update mode or entry state permits, and writes the supplied MAC header word. */
int parse_adv_report(int a1, volatile uint8_t *a2, int16_t a3, int16_t a4) {
  int v5; // r5
  int v6; // r8
  char v9; // r2
  int v10; // r3
  int v11; // r1
  int v12; // r3
  char v13; // r2
  int v14; // r0
  int v15; // r5
  char v16; // r3

  v5 = *a2;
  v6 = dword_1314C0;
  if ( !a2[2] )
  {
    v12 = dword_1314C0 + 696 * v5;
    if ( a2[1] )
      v13 = *(volatile uint8_t *)(v12 + 53) | 1;
    else
      v13 = *(volatile uint8_t *)(v12 + 53) & 0xFE;
    *(volatile uint8_t *)(v12 + 53) = v13;
    goto LABEL_9;
  }
  if ( a2[1] )
    v9 = *(volatile uint8_t *)(dword_1314C0 + 696 * v5 + 53) | 4;
  else
    v9 = *(volatile uint8_t *)(dword_1314C0 + 696 * v5 + 53) & 0xFB;
  v10 = dword_1314C0 + 696 * v5;
  v11 = *(volatile uint8_t *)(v10 + 310);
  *(volatile uint8_t *)(v10 + 53) = v9;
  if ( v11 == 15 )
  {
LABEL_9:
    v14 = tx_send_pdu(65, 0, 5, 4u);
    v15 = v6 + 696 * v5;
    v16 = *(volatile uint8_t *)(v15 + 34);
    *(volatile uint16_t *)v14 = *(volatile uint16_t *)(v15 + 32);
    *(volatile uint8_t *)(v14 + 3) = v16;
    *(volatile uint8_t *)(v14 + 2) = a2[1];
    rx_process_packet_1(v14);
  }
  mac_write_header_word(5133, a4, a3);
  return 0;
}



// handle_adv_report @ 0x1314c4
/* luna: Updates the indexed advertising-report state, conditionally creates a follow-up packet for its associated connection, and writes a MAC header word. */
int handle_adv_report(int a1, volatile uint8_t *a2, int16_t a3, int16_t a4) {
  int v4; // r0
  int v7; // r4
  int v8; // r1
  int v9; // r7
  volatile uint8_t *v10; // r0

  v4 = *a2;
  if ( a2[1] )
  {
    v7 = dword_13153C + 696 * v4;
    v8 = *(volatile uint8_t *)(v7 + 34);
    v9 = *(volatile uint8_t *)(dword_131540 + 1320 * v8 + 106);
    *(volatile uint8_t *)(v7 + 52) = 2;
    if ( !v9 && ((*((volatile uint32_t *)off_131544 + 1) >> v8) & 1) != 0 )
    {
      v10 = (volatile uint8_t *)tx_send_pdu(5145, 5, 6, 2u);
      *v10 = 0;
      v10[1] = *(volatile uint8_t *)(v7 + 34);
      rx_process_packet_1((int)v10);
    }
  }
  else
  {
    *(volatile uint8_t *)(dword_13153C + 696 * v4 + 52) = 1;
  }
  mac_write_header_word(5125, a4, a3);
  return 0;
}



// rx_mpdu_parse_header @ 0x131548
/* luna: Queues a connection report using either caller-provided data or the active connection’s stored data, with an extra notification when only one connecti */
int rx_mpdu_parse_header(int a1, volatile int *a2, int16_t a3, int16_t a4) {
  int v7; // r5
  int v8; // r4
  int v9; // r7
  int v10; // r4
  int v11; // r0
  int v12; // r1
  volatile uint8_t *v14; // r7
  int v15; // r0
  int16_t v16; // r1
  int v17; // r4
  int v18; // r1
  int v19; // r2

  if ( hci_cmd_handler(5u) == 1 )
    return 2;
  v7 = tx_send_pdu(5138, a4, a3, 0xCu);
  if ( **(volatile int16_t **)off_13162C < 0 )
  {
    v14 = (volatile uint8_t *)off_131630;
    v8 = *((volatile uint8_t *)off_131630 + 16);
    if ( v8 == 255 )
    {
      irq_disable_mmio_write(dword_13163C, dword_131638, 1092);
      v8 = v14[16];
    }
  }
  else
  {
    v8 = *((volatile uint8_t *)off_131630 + 16);
  }
  if ( check_rf_ready() )
    set_rf_control_bit(*((volatile uint8_t *)a2 + 11));
  v9 = dword_131634 + 1320 * v8;
  v10 = *(volatile uint32_t *)(v9 + 72);
  if ( v10 )
  {
    *(volatile uint8_t *)v7 = *(volatile uint8_t *)(v10 + 24);
    if ( *((volatile uint8_t *)a2 + 10) )
    {
      if ( list_length((volatile uint32_t **)dword_131640) == 1 )
      {
        v15 = tx_send_pdu(59, 0, 5, 0xCu);
        *(volatile uint8_t *)v15 = *(volatile uint8_t *)(*(volatile uint32_t *)(v9 + 72) + 24);
        v16 = *((volatile uint16_t *)a2 + 4);
        v17 = a2[1];
        *(volatile uint32_t *)(v15 + 2) = *a2;
        *(volatile uint16_t *)(v15 + 10) = v16;
        *(volatile uint32_t *)(v15 + 6) = v17;
        rx_process_packet_1(v15);
        v18 = *a2;
        v19 = a2[1];
        *(volatile uint16_t *)(v7 + 10) = *((volatile uint16_t *)a2 + 4);
        *(volatile uint32_t *)(v7 + 2) = v18;
        *(volatile uint32_t *)(v7 + 6) = v19;
        goto LABEL_9;
      }
      v10 = *(volatile uint32_t *)(v9 + 72);
    }
    v11 = *(volatile uint32_t *)(v10 + 4);
    v12 = *(volatile uint32_t *)(v10 + 8);
    *(volatile uint16_t *)(v7 + 10) = *(volatile uint16_t *)(v10 + 12);
    *(volatile uint32_t *)(v7 + 2) = v11;
    *(volatile uint32_t *)(v7 + 6) = v12;
LABEL_9:
    rx_process_packet_1(v7);
    return 0;
  }
  *(volatile uint8_t *)v7 = -1;
  rx_process_packet_1(v7);
  return 0;
}



// bt_get_connection @ 0x131644
/* luna: Validates and records the received frame-control value, or clears pending RX state and refreshes channel configuration when given the 0xFFFF sentinel. */
int bt_get_connection(int a1, volatile uint8_t *a2) {
  int v3; // r5
  int v4; // r6
  char v5; // r3
  char v7; // r3

  v3 = *(volatile uint32_t *)(dword_1316D8 + 696 * *a2 + 340);
  if ( **(volatile int16_t **)off_1316D4 < 0 && !v3 )
    irq_disable_mmio_write(dword_1316E0, dword_1316DC, 1031);
  v4 = *((volatile uint16_t *)a2 + 1);
  if ( v4 == 0xFFFF )
  {
    v5 = *(volatile uint8_t *)(v3 + 166);
    *(volatile uint16_t *)(v3 + 190) = -1;
    v5 &= 0xCFu;
    *(volatile uint8_t *)(v3 + 166) = v5;
    if ( (v5 & 0x80) == 0 )
      return 0;
    phy_get_channel_config(*a2);
    *(volatile uint8_t *)(v3 + 166) &= ~0x80u;
    return 0;
  }
  else
  {
if ( !rx_validate_fcf((void *)(uintptr_t)(v3), *((volatile uint16_t *)a2 + 1)) ) return 0;
    v7 = *(volatile uint8_t *)(v3 + 166);
    *(volatile uint16_t *)(v3 + 190) = v4;
    *(volatile uint8_t *)(v3 + 166) = v7 & 0xCF | 0x10;
    return 0;
  }
}



