// rf_command_handler @ 0x11ab34
/* luna: Selects a pending RF command entry, parses its packet buffer, and links the parsed packet into the active receive queue. */
int rf_command_handler(int result) {
  volatile uint32_t *v1; // r5
  volatile int16_t **v2; // r6
  volatile uint32_t *v3; // r4
  int v4; // r3
  int v5; // r2
  int v6; // r7
  volatile int *v7; // r4
  int v8; // r8
  int v9; // r3
  volatile int *v10; // r6
  int v11; // r1
  unsigned int v12; // r3
  int v13; // r9
  int v14; // r4
  int v15; // r10
  int v16; // r3
  int v17; // r3
  int v18; // [sp+4h] [bp-4h] BYREF

  if ( result == 5 )
  {
    v1 = (volatile uint32_t *)dword_11ACE4;
  }
  else
  {
    result *= 21;
    v1 = (volatile uint32_t *)(dword_11ACCC + 4 * result);
  }
  v2 = (volatile int16_t **)off_11ACD0;
  v3 = (volatile uint32_t *)v1[3];
  if ( **(volatile int16_t **)off_11ACD0 < 0 && !v3 )
    result = irq_disable_mmio_write(dword_11ACE0, dword_11ACDC, 3166);
  while ( 1 )
  {
    v4 = v3[9];
    if ( (v4 & 0x200000) != 0 )
      break;
    if ( *(volatile int *)(v3[19] + 72) < 0 )
    {
      v3 = (volatile uint32_t *)*v3;
      if ( v3 )
        continue;
    }
    return result;
  }
  v5 = **v2;
  if ( v5 >= 0 )
  {
    v6 = v3[17];
    v7 = *(volatile int **)(v6 + 4 * ((uint8_t)*(volatile uint32_t *)off_11ACD4 + 82));
    v8 = v7[19];
LABEL_10:
    v9 = v7[9];
    goto LABEL_11;
  }
  if ( (v4 & 0x380000) == 0x280000 )
  {
    v6 = v3[17];
    v7 = *(volatile int **)(v6 + 4 * ((uint8_t)*(volatile uint32_t *)off_11ACD4 + 82));
    v8 = v7[19];
  }
  else
  {
    irq_disable_mmio_write(dword_11ACE8, dword_11ACDC, 3182);
    v6 = v3[17];
    v5 = **v2;
    v7 = *(volatile int **)(v6 + 4 * ((uint8_t)*(volatile uint32_t *)off_11ACD4 + 82));
    v8 = v7[19];
    if ( v5 >= 0 )
      goto LABEL_10;
  }
  v9 = v7[9];
  if ( (v9 & 0x380000) == 0x380000 )
  {
    irq_disable_mmio_write(dword_11ACEC, dword_11ACDC, 3192);
    v9 = v7[9];
  }
  v5 = **v2;
LABEL_11:
  v10 = (volatile int *)off_11ACD8;
  v11 = *(volatile uint32_t *)off_11ACD8;
  v7[9] = v9 | 0x380000;
  v12 = v9 & 0xFFC7FEFF | 0x380100;
  if ( *(volatile uint8_t *)(v11 + 1) )
  {
    v15 = v6 + 84;
    v13 = *(volatile uint32_t *)(v6 + 88);
    v14 = *v7;
    *(volatile uint32_t *)(v8 + 68) = v12;
    *(volatile uint32_t *)(v8 + 20) = v6 + 84;
    if ( v5 >= 0 )
      goto LABEL_13;
  }
  else
  {
    v13 = *(volatile uint32_t *)(v6 + 20);
    v14 = *v7;
    *(volatile uint32_t *)(v8 + 68) = v12;
    *(volatile uint32_t *)(v8 + 20) = 0;
    v15 = v6 + 16;
    if ( v5 >= 0 )
      goto LABEL_13;
  }
  if ( !v14 )
    irq_disable_mmio_write(dword_11ACE0, dword_11ACDC, 3217);
LABEL_13:
  result = rx_packet_parse((void *)(uintptr_t)(v14), (int)&v18);
  if ( !result )
    return result;
  v16 = *v10;
  *(volatile uint32_t *)(v15 + 4) = result;
  if ( *(volatile uint8_t *)(v16 + 1) )
  {
    v17 = v18;
    *(volatile uint32_t *)(v18 + 4) = v13;
    if ( v13 )
      return result;
    *v1 = v17;
  }
  else if ( (*(volatile uint32_t *)(v18 + 56) & 0x200000) != 0 )
  {
    *(volatile uint32_t *)(result + 4) = v13;
    if ( v13 )
      return result;
  }
  else
  {
    *(volatile uint32_t *)(v18 + 4) = v13;
    if ( v13 )
      return result;
  }
  if ( (*(volatile uint32_t *)(result + 56) & 0x200000) != 0 )
  {
    v1[1] = result;
    v1[2] = 1;
  }
  else
  {
    v1[1] = 0;
    v1[2] = 0;
  }
  return result;
}



// mac_tx_init @ 0x11acf0
/* luna: Prepares a MAC transmit packet by adjusting its packet-buffer state and allocating and initializing a transmit descriptor when none is attached. */
int mac_tx_init(int a1, volatile int *a2, unsigned int a3, unsigned int a4, uint8_t a5) {
  int v5; // r7
  volatile uint32_t *v6; // r10
  volatile uint32_t *v8; // r9
  int v12; // r11
  int v13; // r7
  int v14; // r3
  int v15; // r12
  int v16; // r2
  volatile uint32_t *v17; // r11
  void *v18; // r7
  int v19; // r0
  int v20; // r3
  int v21; // r12
  int v22; // r0
  int v23; // r5
  int v24; // r1
  int v25; // r2
  volatile uint16_t *v26; // r1
  char v27; // r2
  int v28; // r2
  unsigned int v29; // r3
  int v30; // r1
  int v32; // r3

  v5 = *(volatile uint32_t *)(a1 + 36);
  v6 = *(volatile uint32_t **)(a1 + 76);
  v8 = v6 + 3;
  if ( (v5 & 0x200000) == 0 )
  {
    if ( (*(volatile uint16_t *)(a1 + 82) & 4) == 0 )
      return 0;
    v16 = *(volatile uint16_t *)(a1 + 4);
    if ( !*(volatile uint16_t *)(a1 + 4) || (*(volatile uint16_t *)(a1 + 30) & 8) != 0 )
    {
      if ( a3 >= (uint16_t)(((v6[9] + 3) & 0xFFFC) + 4) )
        goto LABEL_32;
    }
    else
    {
      v26 = (volatile uint16_t *)v6[7];
      if ( !v26 || (*v26 & 0x8000) != 0 )
      {
        if ( a3 >= (uint16_t)(((v6[9] + 3) & 0xFFFC) + 4) )
        {
          if ( !v26 )
            goto LABEL_32;
          v30 = v6[8];
          goto LABEL_31;
        }
      }
      else
      {
        *v26 = ~((unsigned int)~((uint16_t)*v26 << 17) >> 17);
        v27 = *(volatile uint8_t *)(a1 + 51) + 4;
        *(volatile uint8_t *)(a1 + 50) += 4;
        *(volatile uint8_t *)(a1 + 51) = v27;
        v28 = v6[9];
        v29 = (uint16_t)(((v28 + 7) & 0xFFFC) + 4);
        v16 = v28 + 4;
        v30 = v6[8] + 4;
        v6[8] = v30;
        v6[9] = v16;
        if ( v29 <= a3 )
        {
          v16 = *(volatile uint16_t *)(a1 + 4);
          if ( !*(volatile uint16_t *)(a1 + 4) || (*(volatile uint16_t *)(a1 + 30) & 8) != 0 )
            goto LABEL_32;
LABEL_31:
          *(volatile uint32_t *)(v30 - 3) = *((volatile uint32_t *)off_11AF84 + 43);
LABEL_32:
          v14 = *(volatile uint32_t *)a1;
          *a2 = *(volatile uint32_t *)a1;
          if ( !v14 )
          {
LABEL_20:
            if ( !*(volatile uint32_t *)(a1 + 68) )
            {
              v22 = (int)(uintptr_t)(list_pop(dword_11AF78));
              v23 = v22;
              if ( **(volatile int16_t **)off_11AF7C < 0 && !v22 )
                irq_disable_mmio_write(dword_11AF8C, dword_11AF88, 3646);
              *(volatile uint8_t *)(v23 + 14) = 1;
              *(volatile uint32_t *)(v23 + 40) = v6[9];
              *(volatile uint16_t *)(v23 + 8) = 0;
              *(volatile uint8_t *)(v23 + 12) = *(volatile uint8_t *)(a1 + 29);
              v24 = *(volatile uint32_t *)(a1 + 76);
              *(volatile uint32_t *)(v23 + 324) = a1;
              *(volatile uint8_t *)(v24 + 1) = 1;
              v25 = dword_11AF80;
              *(volatile uint32_t *)(a1 + 68) = v23;
              wlan_ioctl_handler_2(84 * a5 + 28 + v25, (void *)(uintptr_t)(v23));
            }
            return (int)v8;
          }
          v17 = (void *)(uintptr_t)(off_11AF70);
          v18 = (void *)(uintptr_t)(off_11AF74);
          v19 = 0;
          goto LABEL_8;
        }
      }
    }
    ((int (*)())channel_table_lookup)((int)(uintptr_t)(v6 + 3), a5, v16);
    return 0;
  }
  if ( (v5 & 0x380000) != 0x280000 )
    return 0;
  v12 = *(volatile uint32_t *)(a1 + 68);
  if ( (*(volatile uint16_t *)(v12 + 8) & 3) != 3
    || *(volatile uint8_t *)(*(volatile uint32_t *)off_11AF74 + 62) > (*(volatile uint32_t *)off_11AF70 & 0x3Fu) )
  {
    return 0;
  }
  if ( *(volatile uint32_t *)(v12 + 40) > a3 )
    return enable_component(a1, a2, a3, a4, a5);
  btm_read_indirect((volatile int16_t *)a1);
  v13 = *(volatile uint32_t *)(a1 + 36);
  v14 = **(volatile uint32_t **)(v12 + 324);
  *a2 = v14;
  if ( v14 )
  {
    v15 = v13 & 0x200000;
    v16 = *(volatile uint16_t *)(a1 + 4);
    v17 = (void *)(uintptr_t)(off_11AF70);
    v18 = (void *)(uintptr_t)(off_11AF74);
    v19 = v15;
LABEL_8:
    if ( v16 )
    {
      while ( (*(volatile uint16_t *)(a1 + 30) & 8) == 0
           && *(volatile uint16_t *)(v14 + 4)
           && (*(volatile uint16_t *)(v14 + 30) & 8) == 0
           && *(volatile uint8_t *)(*(volatile uint32_t *)v18 + 62) <= (*v17 & 0x3Fu) )
      {
        v20 = *(volatile uint32_t *)(v14 + 36);
        if ( v19 )
        {
          if ( (v20 & 0x200000) != 0 )
          {
            if ( !btm_indirect_handler(a1, a2, a3, a4, a5) )
              goto LABEL_40;
          }
          else if ( !btm_is_link_active(a1, a2, a3, a4, a5) )
          {
            goto LABEL_40;
          }
        }
        else
        {
          if ( (v20 & 0x200000) == 0 )
            goto LABEL_20;
          if ( !config_stream(a1, a2, a3, a4, a5) )
          {
LABEL_40:
            if ( (*(volatile uint32_t *)(a1 + 36) & 0x200000) == 0 )
              goto LABEL_20;
            goto LABEL_41;
          }
        }
        v14 = *a2;
        if ( !*a2 )
          goto LABEL_40;
        v19 = *(volatile uint32_t *)(a1 + 36) & 0x200000;
        if ( !*(volatile uint16_t *)(a1 + 4) )
          break;
      }
    }
    v21 = v19;
    goto LABEL_19;
  }
  v21 = v13 & 0x200000;
LABEL_19:
  if ( !v21 )
    goto LABEL_20;
LABEL_41:
  v32 = *(volatile uint32_t *)(a1 + 68);
  *(volatile uint32_t *)(*(volatile uint32_t *)(*(volatile uint32_t *)(v32 + 324) + 76) + 20) = 0;
  return v32 + 16;
}



// rx_packet_type @ 0x11af90
/* luna: Updates packet-format and status bits in a packed RX word when a table-derived rate/length comparison succeeds. */
volatile unsigned int * rx_packet_type(volatile unsigned int *result, unsigned int a2, int a3) {
  unsigned int v3; // r3
  int v4; // r4
  unsigned int v5; // r2
  int v6; // r3
  unsigned int v7; // r3

  v3 = *result;
  if ( ((*result >> 11) & 5) == 5 )
  {
    v4 = (v3 >> 7) & 3;
    if ( (a3 - 1)
       * (*(volatile uint16_t *)(dword_11B014
                              + 2 * (3 * ((*result >> 8) & 1) + 6 * (*result & 0x7F) + ((*result >> 9) & 3))) << ((*result & 0x80) != 0)) < a2 )
    {
      if ( (v3 & 0x1C000) != 0 )
      {
        v7 = v3 & 0xFFFE3FFF | 0x8000;
      }
      else
      {
        v5 = v3 & 0xE01FFFFF;
        if ( (*result & 0xF) <= 2 )
          v6 = 0x80000;
        else
          v6 = 0x100000;
        v7 = v6 | (v4 << 24) | v5 & 0xFFE03FFF | 0x4008000;
      }
      *result = v7;
    }
  }
  return result;
}



// rf_index_to_value @ 0x11b050
/* luna: Returns the 16-bit RF table value at the specified index. */
int rf_index_to_value(int a1) {
  return *(volatile uint16_t *)(dword_11B058 + 2 * a1);
}



// rf_index_to_value2 @ 0x11b05c
/* luna: Returns the 16-bit value at the specified index in a volatile RF lookup table. */
int rf_index_to_value2(int a1) {
  return *(volatile uint16_t *)(dword_11B064 + 2 * a1);
}



// get_ll_conn @ 0x11b068
/* luna: Removes an item from the indexed RF list, decrements its pending count, and dispatches the completion handler or fallback routine. */
int get_ll_conn(int a1, int a2) {
  int v4; // r5
  int v5; // r8
  int v6; // r2

  v4 = dword_11B0B0 + 84 * a2;
  v5 = *(volatile uint32_t *)(a1 + 76);
  list_pop(84 * (int16_t)a2 + 12 + dword_11B0B0);
  v6 = *(volatile uint16_t *)(a1 + 4);
  --*(volatile uint8_t *)(v4 + 80);
  if ( v6 )
    return register_handler((volatile uint32_t *)a1, *(volatile uint32_t *)(v5 + 72), a2);
  else
    return set_string_0x1882c0((volatile uint32_t *)a1);
}


// radio_status_read @ 0x11b0b4
/* luna: When the context flag at offset 37 is set, copies a block from the radio-state area into a global buffer and queries state for the connection identifi */
BOOL radio_status_read(BOOL result) {
  int v1; // r3
  volatile uint32_t *v2; // r2
  int v3; // r4

  v1 = *(volatile uint8_t *)(result + 37);
  if ( *(volatile uint8_t *)(result + 37) )
  {
    v3 = result;
    mem_copy_util((void *)(uintptr_t)(off_11B0F8), *((volatile uint32_t *)off_11B0FC + 4) + 5000);
    return btm_acl_get_state(*(volatile uint8_t *)(v3 + 35), 0, 2500, 37, 5u, 2u, 0, 0);
  }
  else
  {
    v2 = (void *)(uintptr_t)(off_11B0F8);
    *((volatile uint32_t *)off_11B0F8 + 1) = v1;
    v2[2] = v1;
  }
  return result;
}



