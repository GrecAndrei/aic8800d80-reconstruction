// send_hci_le_meta_event @ 0x122818
int send_hci_le_meta_event(int a1, volatile uint8_t *a2, int a3, int a4) {
  int v5; // r0
  int v6; // r3
  int v7; // r2
  int v8; // r2
  int v9; // r1

  v5 = tx_send_pdu(118, a4, a3, 12);
  v6 = dword_122874 + 696 * *a2;
  v7 = *(volatile uint8_t *)(v6 + 34);
  if ( v7 == 255 )
    goto LABEL_4;
  v8 = dword_122878 + 1320 * v7;
  v9 = *(volatile uint8_t *)(v8 + 106);
  *(volatile uint32_t *)v5 = *(volatile uint32_t *)(*(volatile uint32_t *)(v6 + 336) + 20);
  *(volatile uint32_t *)(v5 + 4) = 0;
  if ( !v9 )
  {
    *(volatile uint8_t *)(v5 + 8) = *(volatile uint8_t *)(v8 + 142);
LABEL_4:
    rx_process_packet_1(v5);
    return 0;
  }
  *(volatile uint8_t *)(v5 + 8) = *(volatile uint8_t *)(v6 + 689);
  rx_process_packet_1(v5);
  return 0;
}



// scan_state_check @ 0x12287c
/* luna: Stores a VIF's DHCP-acquired flag and IPv4 address, handles conditional ARP-offload and pending-state cleanup, and writes the command-98 response. */
int scan_state_check(int a1, int a2, int a3, int a4) {
  int vif_table_base; // r9
  int vif_index; // r5
  int vif_state; // r8
  char dhcped; // r1
  int v11; // r2
  int ipv4_addr; // r3

  vif_table_base = dword_122920;
  vif_index = *(volatile uint8_t *)(a2 + 5);
  if ( **(volatile int16_t **)off_122910 < 0 && *(volatile uint8_t *)(dword_122920 + 1320 * vif_index + 106) )
    irq_disable_mmio_write((int)aVifTypeVifSta, (int)aMmSetArpoffloa, 2660);
  vif_state = vif_table_base + 1320 * vif_index;
  dhcped = *(volatile uint8_t *)(a2 + 4);
  v11 = *(volatile uint8_t *)(vif_state + 149);
  ipv4_addr = *(volatile uint32_t *)a2;
  *(volatile uint32_t *)(vif_state + 1228) = *(volatile uint32_t *)a2;
  *(volatile uint8_t *)(vif_state + 1227) = dhcped;
  if ( v11 == 1 )
  {
    mem_set_util((int)(uintptr_t)((volatile uint32_t *)(1320 * vif_index + 152 + vif_table_base)));
    ipv4_addr = *(volatile uint32_t *)(vif_state + 1228);
    *(volatile uint8_t *)(vif_state + 149) = 0;
  }
  check_feature_flag(256, "DHCPed:%d,%x.\r\n", *(volatile uint8_t *)(vif_table_base + 1320 * vif_index + 1227), ipv4_addr);
  mac_write_header_word(98, a4, a3);
  return 0;
}


// scan_control_update @ 0x122924
int scan_control_update(int a1, volatile uint8_t *a2, int a3, int a4) {
  int v4; // r4
  volatile uint8_t *v7; // r4
  volatile uint32_t *v8; // r6
  volatile uint32_t *v9; // r5
  unsigned int v10; // r3
  volatile uint32_t *v11; // r3
  volatile uint32_t *v13; // r6
  volatile uint32_t *v14; // r5

  v4 = *a2;
  if ( v4 && *((volatile uint8_t *)off_1229BC + 177) )
  {
    v7 = (void *)(uintptr_t)(off_1229C0);
    v13 = (void *)(uintptr_t)(off_1229C4);
    v14 = (void *)(uintptr_t)(off_1229C8);
    *(volatile uint8_t *)off_1229C0 = 1;
    *v13 |= 0x2000000u;
    v14[14] |= 0x10u;
  }
  else
  {
    v7 = (void *)(uintptr_t)(off_1229C0);
    v8 = (void *)(uintptr_t)(off_1229C4);
    v9 = (void *)(uintptr_t)(off_1229C8);
    *(volatile uint8_t *)off_1229C0 = 0;
    *v8 &= ~0x2000000u;
    v9[14] &= ~0x10u;
  }
  *(volatile uint32_t *)off_1229C4 &= ~0x800u;
  v7[2] = 0;
  if ( a2[2] )
    v10 = *(volatile uint32_t *)off_1229CC | 0x80000000;
  else
    v10 = *(volatile uint32_t *)off_1229CC & 0x7FFFFFFF;
  *(volatile uint32_t *)off_1229CC = v10;
  if ( a2[4] )
  {
    v11 = (void *)(uintptr_t)(off_1229D4);
    *(volatile uint32_t *)off_1229D0 = *((volatile uint32_t *)a2 + 2);
    *v11 &= 0xFFFFFu;
    *v11 |= *((volatile uint32_t *)a2 + 3) << 20;
  }
  mac_write_header_word(102, a4, a3);
  return 0;
}



// send_hci_vendor_event @ 0x1229d8
int send_hci_vendor_event(int a1, int a2, int a3, int a4) {
  mac_write_header_word(104, a4, a3);
  return 0;
}



