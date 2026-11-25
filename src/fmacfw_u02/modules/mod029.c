// hci_send_cmd_0x76 @ 0x122958
int hci_send_cmd_0x76(int a1, volatile uint8_t *a2, int a3, int a4) {
  int v5; // r0
  int v6; // r3
  int v7; // r2
  int v8; // r2
  int v9; // r1

  v5 = ke_msg_alloc(118, a4, a3, 12);
  v6 = dword_1229B4 + 696 * *a2;
  v7 = *(volatile uint8_t *)(v6 + 34);
  if ( v7 == 255 )
    goto LABEL_4;
  v8 = dword_1229B8 + 1320 * v7;
  v9 = *(volatile uint8_t *)(v8 + 106);
  *(volatile uint32_t *)v5 = *(volatile uint32_t *)(*(volatile uint32_t *)(v6 + 336) + 20);
  *(volatile uint32_t *)(v5 + 4) = 0;
  if ( !v9 )
  {
    *(volatile uint8_t *)(v5 + 8) = *(volatile uint8_t *)(v8 + 142);
LABEL_4:
    ke_msg_send_2(v5);
    return 0;
  }
  *(volatile uint8_t *)(v5 + 8) = *(volatile uint8_t *)(v6 + 689);
  ke_msg_send_2(v5);
  return 0;
}



// scan_process_report @ 0x1229bc
int scan_process_report(int a1, int a2, int a3, int a4) {
  int v4; // r9
  int v6; // r5
  int v9; // r8
  char v10; // r1
  int v11; // r2
  int v12; // r3

  v4 = dword_122A60;
  v6 = *(volatile uint8_t *)(a2 + 5);
  if ( **(volatile int16_t **)off_122A50 < 0 && *(volatile uint8_t *)(dword_122A60 + 1320 * v6 + 106) )
    mmio_clear_register((int)aVifTypeVifSta, (int)aMmSetArpoffloa, 2660);
  v9 = v4 + 1320 * v6;
  v10 = *(volatile uint8_t *)(a2 + 4);
  v11 = *(volatile uint8_t *)(v9 + 149);
  v12 = *(volatile uint32_t *)a2;
  *(volatile uint32_t *)(v9 + 1228) = *(volatile uint32_t *)a2;
  *(volatile uint8_t *)(v9 + 1227) = v10;
  if ( v11 == 1 )
  {
    fault_handler((int)(uintptr_t)((volatile uint32_t *)(1320 * v6 + 152 + v4)));
    v12 = *(volatile uint32_t *)(v9 + 1228);
    *(volatile uint8_t *)(v9 + 149) = 0;
  }
  check_status_bits(256, "DHCPed:%d,%x.\r\n", *(volatile uint8_t *)(v4 + 1320 * v6 + 1227), v12);
  ke_msg_send_no_param(98, a4, a3);
  return 0;
}


// parse_byte_param @ 0x122a64
int parse_byte_param(int a1, volatile uint8_t *a2, int a3, int a4) {
  int v4; // r4
  volatile uint8_t *v7; // r4
  volatile uint32_t *v8; // r6
  volatile uint32_t *v9; // r5
  unsigned int v10; // r3
  volatile uint32_t *v11; // r3
  volatile uint32_t *v13; // r6
  volatile uint32_t *v14; // r5

  v4 = *a2;
  if ( v4 && *((volatile uint8_t *)off_122AFC + 177) )
  {
    v7 = (void *)(uintptr_t)(off_122B00);
    v13 = (void *)(uintptr_t)(off_122B04);
    v14 = (void *)(uintptr_t)(off_122B08);
    *(volatile uint8_t *)off_122B00 = 1;
    *v13 |= 0x2000000u;
    v14[14] |= 0x10u;
  }
  else
  {
    v7 = (void *)(uintptr_t)(off_122B00);
    v8 = (void *)(uintptr_t)(off_122B04);
    v9 = (void *)(uintptr_t)(off_122B08);
    *(volatile uint8_t *)off_122B00 = 0;
    *v8 &= ~0x2000000u;
    v9[14] &= ~0x10u;
  }
  *(volatile uint32_t *)off_122B04 &= ~0x800u;
  v7[2] = 0;
  if ( a2[2] )
    v10 = *(volatile uint32_t *)off_122B0C | 0x80000000;
  else
    v10 = *(volatile uint32_t *)off_122B0C & 0x7FFFFFFF;
  *(volatile uint32_t *)off_122B0C = v10;
  if ( a2[4] )
  {
    v11 = (void *)(uintptr_t)(off_122B14);
    *(volatile uint32_t *)off_122B10 = *((volatile uint32_t *)a2 + 2);
    *v11 &= 0xFFFFFu;
    *v11 |= *((volatile uint32_t *)a2 + 3) << 20;
  }
  ke_msg_send_no_param(102, a4, a3);
  return 0;
}



// hci_send_cmd_0x68 @ 0x122b18
/* luna: Sends the no-parameter kernel message 0x68 using the supplied destination and source task IDs. */
int hci_send_cmd_0x68(int a1, int a2, int a3, int a4) {
  ke_msg_send_no_param(104, a4, a3);
  return 0;
}



