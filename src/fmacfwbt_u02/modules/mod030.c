// copy_fixed_string @ 0x122d5c
int copy_fixed_string(int a1, int a2, int a3, int a4) {
  int v6; // r3

  memcpy((void *)(uintptr_t)(dword_122D78), (void *)(uintptr_t)(a2), 69);
  ((int (*)())hci_evt_alloc_send)(120, a4, a3, v6);
  return 0;
}



// store_hci_event_info @ 0x122d7c
int store_hci_event_info(int a1, volatile uint32_t *a2, int a3, int a4) {
  int v4; // r0
  volatile uint32_t *v5; // r5
  int v6; // r4
  int v7; // r1

  v4 = *a2;
  v5 = a2;
  v6 = dword_122D98;
  v7 = a2[1];
  v5 = (void *)(uintptr_t)(((uintptr_t)(v5) & ~0xFFFFu) | ((uint16_t)(*((volatile uint16_t *)v5 + 4)) & 0xFFFFu));
  *(volatile uint32_t *)dword_122D98 = v4;
  *(volatile uint32_t *)(v6 + 4) = v7;
  *(volatile uint16_t *)(v6 + 8) = (uint16_t)v5;
  ((int (*)())hci_evt_alloc_send)(138, a4, a3, a4);
  return 0;
}



// handle_hci_command @ 0x122d9c
int handle_hci_command(int a1, volatile int *a2, int a3, volatile uint32_t *a4) {
  int v4; // r4
  volatile uint32_t *v6; // r1
  volatile char *v7; // r7
  int v8; // r6
  int v9; // r4
  int v10; // r12
  int v11; // r5
  int v12; // r6

  v4 = *(volatile uint8_t *)a2;
  v6 = a4;
  if ( v4 )
  {
    v7 = (volatile char *)off_122DEC;
    if ( (*((volatile uint8_t *)off_122DE8 + 1) & 1) == 0
      || (a4 = (volatile uint32_t *)(*((volatile uint32_t *)off_122DEC + 98) << 31), (*((volatile uint32_t *)off_122DEC + 98) & 1) != 0) )
    {
      a4 = (void *)(uintptr_t)(off_122DF0);
      v8 = *a2;
      v9 = a2[2];
      v10 = a2[3];
      *((volatile uint32_t *)off_122DF0 + 1) = a2[1];
      *(volatile uint32_t *)(v7 + 266) = v8;
      v11 = a2[5];
      v12 = a2[4];
      a4[2] = v9;
      a4[6] = a2[6];
      a4[3] = v10;
      a4[4] = v12;
      a4[5] = v11;
    }
  }
  ((int (*)())hci_evt_alloc_send)(122, (int)(uintptr_t)(v6), a3, a4);
  return 0;
}



// check_controller_ready @ 0x122df4
int check_controller_ready(int a1, volatile uint8_t *a2, int a3, int a4) {
  int v4; // r7
  int v6; // r4
  int v9; // r4
  int v10; // r3

  v4 = dword_122E5C;
  v6 = *a2;
  if ( **(volatile int16_t **)off_122E58 < 0 && *(volatile uint8_t *)(dword_122E5C + 1320 * v6 + 106) )
    mmio_irq_clear(dword_122E64, dword_122E60, 3702);
  v9 = v4 + 1320 * v6;
  *(volatile uint8_t *)(v9 + 143) = a2[1];
  v10 = a2[2];
  *(volatile uint16_t *)(v9 + 144) = (uint8_t)v10;
  ((int (*)())hci_evt_alloc_send)(134, a4, a3, v10);
  return 0;
}



