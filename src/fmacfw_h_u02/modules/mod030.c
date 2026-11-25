// copy_config_data @ 0x1229e8
int copy_config_data(int a1, int a2, int a3, int a4) {
  memcpy((void *)(uintptr_t)(dword_122A04), (void *)(uintptr_t)(a2), 69);
  mac_write_header_word(120, a4, a3);
  return 0;
}



// store_rx_info @ 0x122a08
int store_rx_info(int a1, volatile uint32_t *a2, int a3, int a4) {
  int v4; // r0
  volatile uint32_t *v5; // r5
  int v6; // r4
  int v7; // r1

  v4 = *a2;
  v5 = a2;
  v6 = dword_122A24;
  v7 = a2[1];
  v5 = (void *)(uintptr_t)(((uintptr_t)(v5) & ~0xFFFFu) | ((uint16_t)(*((volatile uint16_t *)v5 + 4)) & 0xFFFFu));
  *(volatile uint32_t *)dword_122A24 = v4;
  *(volatile uint32_t *)(v6 + 4) = v7;
  *(volatile uint16_t *)(v6 + 8) = (uint16_t)v5;
  mac_write_header_word(138, a4, a3);
  return 0;
}



// scan_validate @ 0x122a28
int scan_validate(int a1, volatile int *a2, int a3, int a4) {
  volatile char *v7; // r7
  volatile uint32_t *v8; // r3
  int v9; // r6
  int v10; // r4
  int v11; // r12
  int v12; // r5
  int v13; // r6

  if ( *(volatile uint8_t *)a2 )
  {
    v7 = (volatile char *)off_122A78;
    if ( (*((volatile uint8_t *)off_122A74 + 1) & 1) == 0 || (*((volatile uint32_t *)off_122A78 + 98) & 1) != 0 )
    {
      v8 = (void *)(uintptr_t)(off_122A7C);
      v9 = *a2;
      v10 = a2[2];
      v11 = a2[3];
      *((volatile uint32_t *)off_122A7C + 1) = a2[1];
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
  mac_write_header_word(122, a4, a3);
  return 0;
}



// adv_state_check @ 0x122a80
int adv_state_check(int a1, volatile uint8_t *a2, int a3, int a4) {
  int v4; // r7
  int v6; // r4
  volatile uint8_t *v9; // r4

  v4 = dword_122AE8;
  v6 = *a2;
  if ( **(volatile int16_t **)off_122AE4 < 0 && *(volatile uint8_t *)(dword_122AE8 + 1320 * v6 + 106) )
    irq_disable_mmio_write(dword_122AF0, dword_122AEC, 3702);
  v9 = (volatile uint8_t *)(v4 + 1320 * v6);
  v9[143] = a2[1];
  v9[144] = a2[2];
  v9[145] = 0;
  mac_write_header_word(134, a4, a3);
  return 0;
}



