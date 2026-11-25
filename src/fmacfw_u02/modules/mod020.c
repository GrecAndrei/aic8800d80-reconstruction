// check_link_state @ 0x11b240
/* luna: Scans link slots for an eligible connection, processes its transmit request, and updates the selected transmit descriptor. */
int check_link_state(volatile int *a1) {
  volatile uint16_t *v1; // r6
  int v2; // r3
  int v3; // r9
  int v5; // r4
  int v6; // r10
  int v7; // r3
  int v8; // r2
  volatile int *v9; // r5
  int v10; // r10
  int v11; // r3
  int v12; // r2
  int v13; // r11
  int v15; // r0
  int v16; // r4
  int16_t v17; // r3

  v1 = (volatile uint16_t *)off_11B350;
  if ( *((volatile uint8_t *)off_11B350 + 197) > 3u )
    return 0;
  v2 = 3;
  v3 = dword_11B364;
  v5 = (v5 & ~0xFFu) | ((uint8_t)(3) & 0xFFu);
  while ( 1 )
  {
    v7 = v3 + 84 * v2;
    v8 = *(volatile uint8_t *)(v7 + 26);
    *((volatile uint8_t *)v1 + 190) = v5;
    if ( v8 == 1 )
      break;
    v9 = *(volatile int **)(v7 + 12);
    if ( v9 )
    {
      v10 = v7;
      v11 = v9[9] & 0x200000;
      if ( v11 )
      {
LABEL_13:
        v13 = (int)v9;
        v9 = 0;
      }
      else
      {
        while ( 1 )
        {
          v12 = v9[19];
          if ( *(volatile int *)(v12 + 72) >= 0 )
            break;
          if ( *(volatile uint32_t *)(v12 + 16) )
          {
            v13 = *v9;
            if ( *(volatile int *)(*(volatile uint32_t *)(*v9 + 76) + 72) >= 0 )
              goto LABEL_3;
          }
          get_connection_by_index((int)v9, (uint8_t)v5);
          v9 = *(volatile int **)(v10 + 12);
          if ( !v9 )
            goto LABEL_4;
          v11 = v9[9] & 0x200000;
          if ( v11 )
            goto LABEL_13;
        }
        v13 = (int)v9;
        v9 = (volatile int *)v11;
      }
LABEL_3:
      v6 = process_tx_request(v13, a1, *((volatile uint32_t *)v1 + 44), v1[93], *((volatile uint8_t *)v1 + 190));
      if ( v6 )
      {
        if ( v9 )
          get_connection_by_index((int)v9, (uint8_t)v5);
        v16 = *(volatile uint32_t *)(v13 + 68);
        if ( **(volatile int16_t **)off_11B358 < 0 && !v16 )
          mmio_clear_register(dword_11B360, dword_11B35C, 1383);
        v17 = *(volatile uint16_t *)(v16 + 8);
        *((volatile uint32_t *)v1 + 51) = v16;
        *(volatile uint16_t *)(v16 + 8) = v17 | 0x200;
        return v6;
      }
    }
LABEL_4:
    v5 = (char)(v5 - 1);
    v2 = v5;
    if ( v5 < *((volatile uint8_t *)v1 + 197) )
      return 0;
  }
  if ( !*(volatile uint8_t *)(*(volatile uint32_t *)off_11B354 + 1) )
    return 0;
  v15 = *(volatile uint32_t *)(v7 + 36);
  *a1 = *(volatile uint32_t *)(v7 + 12);
  return v15 + 84;
}



// get_slot_context @ 0x11b368
/* luna: Clears a pending slot marker and, unless the slot is currently active, validates and clears its associated stored value. */
int get_slot_context(int result) {
  volatile uint32_t *v1; // r6
  volatile char *v2; // r3
  int v3; // r2
  int v4; // r4
  int v5; // r5
  int v6; // r3

  v1 = (void *)(uintptr_t)(off_11B3B4);
  v2 = (volatile char *)off_11B3B4 + 28 * result;
  if ( v2[46] )
  {
    v3 = *((volatile uint32_t *)off_11B3B4 + 52);
    v2[46] = 0;
    v4 = result;
    v5 = 8 * result;
    if ( (v3 & 1) == 0 || *((volatile uint8_t *)v1 + 190) != result )
    {
      v6 = (int)&v1[7 * result];
      result = *(volatile uint32_t *)(v6 + 36);
      if ( result )
        result = ((int (*)())radio_band_validate)(result, v4, v3, v6);
      v1[v5 - v4 + 9] = 0;
    }
  }
  return result;
}



// invalid_handler_1 @ 0x11b3b8
/* luna: Processes a link slot's pending context and countdown state, dispatching its worker while maintaining the interrupt guard. */
int invalid_handler_1(int a1) {
  unsigned int CPSR; // r3
  int result; // r0
  volatile uint8_t *v4; // r7
  volatile int *v5; // r6
  volatile char *v6; // r2
  int v7; // r1
  int v8; // r3
  int v9; // r3
  int v10; // r3
  int v11; // r2
  int v12; // r1

  CPSR = __get_CPSR();
  result = CPSR << 31;
  if ( (CPSR & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_11B47C = 1;
  }
  v4 = (void *)(uintptr_t)(off_11B480);
  v5 = (volatile int *)off_11B484;
  v6 = (volatile char *)off_11B480 + 28 * a1;
  v7 = (uint8_t)v6[47];
  v8 = *(volatile uint32_t *)off_11B484 + 1;
  *(volatile uint32_t *)off_11B484 = v8;
  if ( v7 )
  {
    v9 = *((volatile uint32_t *)v6 + 10);
    v6[47] = 0;
    if ( v9 << 28 )
    {
      *(volatile uint32_t *)(dword_11B48C + 4 * a1) = v9;
      get_slot_context((uint8_t)a1);
    }
    else if ( !v6[46] )
    {
      v6[46] = 1;
    }
    v4[28 * a1 + 45] = v4[28 * a1 + 44];
    goto LABEL_8;
  }
  if ( !v6[45] )
  {
LABEL_17:
    *(volatile uint32_t *)&v4[28 * a1 + 24] = 0;
    goto LABEL_9;
  }
  v12 = (uint8_t)(v6[45] - 1);
  v6[45] = v12;
  if ( !v12 )
  {
    *(volatile uint32_t *)(dword_11B48C + 4 * a1) = *(volatile uint32_t *)(*((volatile uint32_t *)v4 + 4) + 4 * (a1 + 2));
    result = get_slot_context((uint8_t)a1);
    v8 = *v5;
    goto LABEL_17;
  }
LABEL_8:
  result = unknown_worker((void *)(&v4[28 * a1 + 20]), *((volatile uint32_t *)off_11B488 + 4) + 0x2000);
  v8 = *v5;
LABEL_9:
  if ( v8 )
  {
    v10 = v8 - 1;
    v11 = *(volatile uint32_t *)off_11B47C;
    *v5 = v10;
    if ( !v10 )
    {
      if ( v11 )
        __enable_irq();
    }
  }
  return result;
}



