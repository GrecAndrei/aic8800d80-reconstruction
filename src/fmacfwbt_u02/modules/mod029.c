// send_cmd_0x76 @ 0x122b8c
int send_cmd_0x76(int a1, volatile uint8_t *a2, int a3, int a4) {
  int v5; // r0
  int v6; // r3
  int v7; // r2
  int v8; // r2
  int v9; // r1

  v5 = bt_buf_alloc(118, a4, a3, 12);
  v6 = dword_122BE8 + 696 * *a2;
  v7 = *(volatile uint8_t *)(v6 + 34);
  if ( v7 == 255 )
    goto LABEL_4;
  v8 = dword_122BEC + 1320 * v7;
  v9 = *(volatile uint8_t *)(v8 + 106);
  *(volatile uint32_t *)v5 = *(volatile uint32_t *)(*(volatile uint32_t *)(v6 + 336) + 20);
  *(volatile uint32_t *)(v5 + 4) = 0;
  if ( !v9 )
  {
    *(volatile uint8_t *)(v5 + 8) = *(volatile uint8_t *)(v8 + 142);
LABEL_4:
    hci_evt_send(v5);
    return 0;
  }
  *(volatile uint8_t *)(v5 + 8) = *(volatile uint8_t *)(v6 + 689);
  hci_evt_send(v5);
  return 0;
}



// process_hci_command_status @ 0x122bf0
int process_hci_command_status(int a1, int a2, int a3, int a4) {
  int v4; // r9
  int v6; // r5
  int v9; // r8
  char v10; // r1
  int v11; // r2
  int v12; // r3

  v4 = dword_122C94;
  v6 = *(volatile uint8_t *)(a2 + 5);
  if ( **(volatile int16_t **)off_122C84 < 0 && *(volatile uint8_t *)(dword_122C94 + 1320 * v6 + 106) )
    mmio_irq_clear((int)aVifTypeVifSta, (int)aMmSetArpoffloa, 2660);
  v9 = v4 + 1320 * v6;
  v10 = *(volatile uint8_t *)(a2 + 4);
  v11 = *(volatile uint8_t *)(v9 + 149);
  v12 = *(volatile uint32_t *)a2;
  *(volatile uint32_t *)(v9 + 1228) = *(volatile uint32_t *)a2;
  *(volatile uint8_t *)(v9 + 1227) = v10;
  if ( v11 == 1 )
  {
    ke_event_set_lock((int)(uintptr_t)((volatile uint32_t *)(1320 * v6 + 152 + v4)));
    v12 = *(volatile uint32_t *)(v9 + 1228);
    *(volatile uint8_t *)(v9 + 149) = 0;
  }
  state_check_feature(256, "DHCPed:%d,%x.\r\n", *(volatile uint8_t *)(v4 + 1320 * v6 + 1227), v12);
  hci_evt_alloc_send(98, a4, a3);
  return 0;
}


// check_command_permitted @ 0x122c98
int check_command_permitted(int a1, volatile uint8_t *a2, int a3, int a4) {
  int v4; // r4
  volatile uint8_t *v7; // r4
  volatile uint32_t *v8; // r6
  volatile uint32_t *v9; // r5
  unsigned int v10; // r3
  void *v11; // r3
  volatile uint32_t *v13; // r6
  volatile uint32_t *v14; // r5

  v4 = *a2;
  if ( v4 && *((volatile uint8_t *)off_122D30 + 177) )
  {
    v7 = (void *)(uintptr_t)(off_122D34);
    v13 = (void *)(uintptr_t)(off_122D38);
    v14 = (void *)(uintptr_t)(off_122D3C);
    *(volatile uint8_t *)off_122D34 = 1;
    *v13 |= 0x2000000u;
    v14[14] |= 0x10u;
  }
  else
  {
    v7 = (void *)(uintptr_t)(off_122D34);
    v8 = (void *)(uintptr_t)(off_122D38);
    v9 = (void *)(uintptr_t)(off_122D3C);
    *(volatile uint8_t *)off_122D34 = 0;
    *v8 &= ~0x2000000u;
    v9[14] &= ~0x10u;
  }
  *(volatile uint32_t *)off_122D38 &= ~0x800u;
  v7[2] = 0;
  if ( a2[2] )
    v10 = *(volatile uint32_t *)off_122D40 | 0x80000000;
  else
    v10 = *(volatile uint32_t *)off_122D40 & 0x7FFFFFFF;
  *(volatile uint32_t *)off_122D40 = v10;
  v11 = (void *)a2[4];
  if ( a2[4] )
  {
    v11 = (void *)(uintptr_t)(off_122D48);
    *(volatile uint32_t *)off_122D44 = *((volatile uint32_t *)a2 + 2);
    *(volatile uint32_t *)v11 &= 0xFFFFFu;
    *(volatile uint32_t *)v11 |= *((volatile uint32_t *)a2 + 3) << 20;
  }
  ((int (*)())hci_evt_alloc_send)(102, a4, a3, v11);
  return 0;
}



// send_cmd_0x68 @ 0x122d4c
int send_cmd_0x68(int a1, int a2, int a3, int a4) {
  ((int (*)())hci_evt_alloc_send)(104, a4, a3, a4);
  return 0;
}



