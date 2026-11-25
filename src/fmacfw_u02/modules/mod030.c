// log_message @ 0x122b28
int log_message(int a1, int a2, int a3, int a4) {
  memcpy((void *)(uintptr_t)(dword_122B44), (void *)(uintptr_t)(a2), 69);
  ke_msg_send_no_param(120, a4, a3);
  return 0;
}



// store_hci_event @ 0x122b48
int store_hci_event(int a1, volatile uint32_t *a2, int a3, int a4) {
  int v4; // r0
  volatile uint32_t *v5; // r5
  int v6; // r4
  int v7; // r1

  v4 = *a2;
  v5 = a2;
  v6 = dword_122B64;
  v7 = a2[1];
  v5 = (void *)(uintptr_t)(((uintptr_t)(v5) & ~0xFFFFu) | ((uint16_t)(*((volatile uint16_t *)v5 + 4)) & 0xFFFFu));
  *(volatile uint32_t *)dword_122B64 = v4;
  *(volatile uint32_t *)(v6 + 4) = v7;
  *(volatile uint16_t *)(v6 + 8) = (uint16_t)v5;
  ke_msg_send_no_param(138, a4, a3);
  return 0;
}



// parse_hci_packet @ 0x122b68
int parse_hci_packet(int a1, volatile int *a2, int a3, int a4) {
  volatile char *v7; // r7
  volatile uint32_t *v8; // r3
  int v9; // r6
  int v10; // r4
  int v11; // r12
  int v12; // r5
  int v13; // r6

  if ( *(volatile uint8_t *)a2 )
  {
    v7 = (volatile char *)off_122BB8;
    if ( (*((volatile uint8_t *)off_122BB4 + 1) & 1) == 0 || (*((volatile uint32_t *)off_122BB8 + 98) & 1) != 0 )
    {
      v8 = (void *)(uintptr_t)(off_122BBC);
      v9 = *a2;
      v10 = a2[2];
      v11 = a2[3];
      *((volatile uint32_t *)off_122BBC + 1) = a2[1];
      *(volatile uint32_t *)(v7 + 266) = v9;
      v12 = a2[5];
      v13 = a2[4];
      v8[2] = v10;
      v8[6] = a2[6];
      v8[3] = v11;
      v8[4] = v13;
      v8[5] = v12;
    }
  }
  ke_msg_send_no_param(122, a4, a3);
  return 0;
}



// hci_read_command @ 0x122bc0
int hci_read_command(int a1, volatile uint8_t *a2, int a3, int a4) {
  int v4; // r7
  int v6; // r4
  volatile uint8_t *v9; // r4

  v4 = dword_122C28;
  v6 = *a2;
  if ( **(volatile int16_t **)off_122C24 < 0 && *(volatile uint8_t *)(dword_122C28 + 1320 * v6 + 106) )
    mmio_clear_register(dword_122C30, dword_122C2C, 3702);
  v9 = (volatile uint8_t *)(v4 + 1320 * v6);
  v9[143] = a2[1];
  v9[144] = a2[2];
  v9[145] = 0;
  ke_msg_send_no_param(134, a4, a3);
  return 0;
}



