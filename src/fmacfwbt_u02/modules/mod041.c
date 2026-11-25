// bt_packet_parse @ 0x12a618
int bt_packet_parse(int result, volatile uint8_t *a2, int a3, int a4) {
  int v4; // r4
  int v5; // r6
  int v6; // r5
  int v7; // [sp+4h] [bp-4h]

  if ( a2[24] == 127 && !a2[29] && (uint8_t)a2[31] == 221 && a2[36] == 9 )
  {
    v4 = (int)(a2 + 37);
    if ( a2[37] == 12 )
    {
      v5 = *(volatile uint8_t *)(result + 1225);
      v6 = result;
      if ( **(volatile int16_t **)off_12A684 < 0 )
      {
        if ( *(volatile uint8_t *)(result + 106) )
        {
          v7 = a4;
          mmio_irq_clear(dword_12A68C, dword_12A688, 64);
          a4 = v7;
        }
      }
      return get_struct_ptr(v5, v4, *(volatile uint32_t *)(v6 + 132) + a4);
    }
  }
  return result;
}



// bt_scan_get_state @ 0x12a690
int bt_scan_get_state() {
  int result; // r0
  volatile int *v1; // r3

  result = *(volatile uint8_t *)off_12A6DC;
  if ( *(volatile uint8_t *)off_12A6DC )
  {
    result = *((volatile uint8_t *)off_12A6E0 + 17);
    if ( *((volatile uint8_t *)off_12A6E0 + 17) )
    {
      return 0;
    }
    else if ( *((volatile uint8_t *)off_12A6E0 + 18) <= 1u )
    {
      v1 = *((volatile int **)off_12A6E0 + 2);
      if ( v1 )
      {
        while ( *((volatile uint8_t *)v1 + 106) != 2 || !*((volatile uint8_t *)v1 + 1224) )
        {
          v1 = (volatile int *)*v1;
          if ( !v1 )
            return result;
        }
        return *(volatile uint8_t *)(dword_12A6E4 + 140 * *((volatile uint8_t *)v1 + 1225) + 133) == 0;
      }
    }
  }
  return result;
}



// bt_dev_check_ready @ 0x12a6e8
volatile uint8_t * bt_dev_check_ready(int a1, int a2) {
  volatile uint8_t *result; // r0
  int v3; // r3
  int v4; // r4
  volatile uint8_t *v5; // r2
  int v6; // r5
  volatile uint8_t *v7; // r4

  result = (volatile uint8_t *)(dword_12A744 + 1320 * a1);
  if ( result[1224] && result[106] == 2 )
  {
    v3 = result[1225];
    v4 = dword_12A748;
    v5 = (volatile uint8_t *)(dword_12A748 + 140 * v3);
    v6 = v5[132];
    v5[135] = a2 != 0;
    v7 = (volatile uint8_t *)(v4 + 140 * v3);
    if ( v6 )
      set_flag_byte(v5[113], 3);
    return state_machine_step(v7);
  }
  return result;
}



// bt_conn_set_flag @ 0x12a74c
volatile uint8_t * bt_conn_set_flag(int a1, uint8_t a2) {
  int v2; // r5
  int v3; // r4
  volatile uint8_t *v4; // r3
  int v5; // r0

  v2 = dword_12A784;
  v3 = *(volatile uint8_t *)(a1 + 1225);
  v4 = (volatile uint8_t *)(dword_12A784 + 140 * v3);
  v5 = v4[113];
  v4[115] = a2;
  v4[114] = 1;
  set_flag_byte(v5, 3);
  return state_machine_step((volatile uint8_t *)(v2 + 140 * v3));
}



// bt_conn_get_flag @ 0x12a788
volatile char * bt_conn_get_flag(int a1) {
  int v1; // r7
  int v2; // r4
  volatile uint8_t *v3; // r6
  int v4; // r3
  int v5; // r4
  char v6; // r1

  v1 = dword_12A7F0;
  v2 = *(volatile uint8_t *)(a1 + 1225);
  v3 = (volatile uint8_t *)(dword_12A7F0 + 140 * v2);
  v4 = v3[114];
  v3[115] = 0;
  if ( v4 )
  {
    ke_event_set_lock(140 * v2 + 96 + v1);
    v3[114] = 0;
  }
  state_machine_step(v3);
  v5 = v1 + 140 * v2;
  if ( *(volatile uint8_t *)(v5 + 121) )
    v6 = 3;
  else
    v6 = 2;
  return set_flag_byte(*(volatile uint8_t *)(v5 + 113), v6);
}



// bt_conn_get_entry @ 0x12a7f4
volatile uint8_t * bt_conn_get_entry(volatile uint8_t *result) {
  if ( result[1224] )
    return state_machine_step((volatile uint8_t *)(dword_12A814 + 140 * result[1225]));
  return result;
}



// bt_conn_state_machine @ 0x12a818
int bt_conn_state_machine(int a1, int a2, char a3, char a4, unsigned int a5, int a6, int a7) {
  int v7; // r6
  int v8; // r7
  volatile uint8_t *v9; // r4
  int v10; // r9
  volatile uint8_t *v11; // r5
  int v13; // r0
  int v14; // r10
  int v15; // lr
  int v16; // zf
  int v17; // r1
  char v18; // r11
  char v19; // r11
  char v20; // r4
  int v21; // r7

  v7 = dword_12A920;
  v8 = *(volatile uint8_t *)(a1 + 1225);
  v9 = (volatile uint8_t *)(dword_12A920 + 140 * v8);
  if ( v9[112] != 1 )
    return 255;
  v10 = v9[16];
  v11 = (volatile uint8_t *)(dword_12A920 + 140 * v8);
  if ( v9[16] )
  {
    if ( v9[64] )
      return 255;
    v10 = 1;
    v13 = 140 * v8 + 48 + dword_12A920;
    v14 = 1;
  }
  else
  {
    v13 = dword_12A920 + 140 * v8;
    v14 = v9[16];
  }
  v15 = dword_12A920 + 140 * v8;
  v16 = a2 == 0;
  v17 = dword_12A920 + 140 * v8 + 48 * v14;
  v18 = *(volatile uint8_t *)(v15 + 121);
  *(volatile uint8_t *)(v17 + 19) = a4;
  *(volatile uint8_t *)(v17 + 20) = a4;
  *(volatile uint32_t *)(v17 + 28) = a5;
  v19 = v18 + 1;
  *(volatile uint32_t *)(v17 + 24) = a6;
  v20 = v16;
  *(volatile uint32_t *)(v17 + 36) = a7;
  *(volatile uint8_t *)(v17 + 33) = a3;
  *(volatile uint8_t *)(v17 + 32) = v20;
  *(volatile uint8_t *)(v15 + 121) = v19;
  if ( !v16 )
    ++*(volatile uint8_t *)(v15 + 122);
  if ( a5 )
    *(volatile uint32_t *)(140 * v8 + 48 * v14 + v7 + 40) = 0x80000000 / a5 - 1;
  ke_event_lock((void *)(uintptr_t)(v13), a7);
  v21 = 140 * v8;
  *(volatile uint8_t *)(v7 + v21 + 48 * v14 + 16) = 1;
  set_flag_byte(*(volatile uint8_t *)(v21 + v7 + 113), 3);
  write_cmd((int)v11, v10);
  mem_fill((int)v11);
  state_machine_step(v11);
  return v10;
}



// bt_conn_get_state @ 0x12a924
int bt_conn_get_state(int a1, unsigned int a2, int a3) {
  int v3; // r6
  int v4; // r5
  int result; // r0
  int v7; // r3
  unsigned int v8; // r8
  int v9; // r3
  int v10; // r1
  int v11; // r2
  int v12; // r3

  v3 = *(volatile uint8_t *)(a1 + 1225);
  v4 = dword_12AA00;
  result = *(volatile uint8_t *)(dword_12AA00 + 140 * v3 + 112);
  if ( result != 1 )
    return 1;
  if ( a2 <= 1 )
  {
    v7 = 140 * v3 + 48 * a2 + dword_12AA00;
    if ( *(volatile uint8_t *)(v7 + 16) )
    {
      if ( !a3 || *(volatile uint8_t *)(v7 + 32) )
      {
        ke_event_set_lock(48 * a2 + 140 * v3 + dword_12AA00);
        v8 = 140 * v3 + 48 * a2 + v4;
        *(volatile uint8_t *)(v8 + 16) = 0;
        mem_fill(v4 + 140 * v3);
        state_machine_step((volatile uint8_t *)(v4 + 140 * v3));
        v9 = v4 + 140 * v3;
        v10 = *(volatile uint8_t *)(v8 + 32);
        v11 = (uint8_t)(*(volatile uint8_t *)(v9 + 121) - 1);
        *(volatile uint8_t *)(v9 + 121) = v11;
        if ( v10 == 1 )
          --*(volatile uint8_t *)(v9 + 122);
        v12 = v4 + 140 * v3;
        if ( *(volatile uint8_t *)(v12 + 115) || v11 )
          set_flag_byte(*(volatile uint8_t *)(v4 + 140 * v3 + 113), 3);
        else
          set_flag_byte(*(volatile uint8_t *)(v12 + 113), 2);
        write_cmd(v4 + 140 * v3, a2);
        return 0;
      }
    }
  }
  return result;
}



// bt_dev_update @ 0x12aa04
volatile uint8_t * bt_dev_update(int a1) {
  int v1; // r9
  int v2; // r8
  int v3; // r6
  int v4; // r3
  int v6; // r10
  volatile uint8_t *v7; // r7
  int v8; // r4
  volatile int16_t **v9; // r3
  int v10; // r1
  volatile uint32_t *v11; // r11
  int v12; // r0
  int v13; // r12
  int v14; // r2
  unsigned int v15; // lr
  int v16; // r3
  int v17; // r6
  volatile uint8_t *result; // r0
  uint64_t v19; // r0
  int v20; // r4
  int v21; // [sp+0h] [bp-Ch]
  char v22; // [sp+4h] [bp-8h]

  v1 = dword_12ACF4;
  v2 = *(volatile uint8_t *)(a1 + 17);
  v3 = *(volatile uint8_t *)(a1 + 16);
  v4 = dword_12ACF4 + 140 * v2;
  v21 = *(volatile uint8_t *)(v4 + 113);
  v6 = dword_12ACD0 + 1320 * v21;
  v7 = (volatile uint8_t *)v4;
  if ( *(volatile uint8_t *)(v4 + 112) == 1 )
  {
    v8 = *(volatile uint32_t *)(a1 + 12);
  }
  else
  {
    v20 = *(volatile uint32_t *)(a1 + 44);
    if ( **(volatile int16_t **)off_12ACD4 < 0 && *(volatile uint8_t *)(v6 + 106) )
      mmio_irq_clear(dword_12ACEC, dword_12ACE8, 98);
    v8 = v20 + *((volatile uint32_t *)off_12ACDC + 4) - *(volatile uint32_t *)off_12ACE4 - *(volatile uint32_t *)(v6 + 132);
  }
  v9 = (volatile int16_t **)off_12ACD4;
  v10 = dword_12ACD8;
  v11 = (void *)(uintptr_t)(off_12ACDC);
  while ( 1 )
  {
    if ( v3 == 1 )
      goto LABEL_27;
    if ( v3 == 2 )
    {
      do
      {
        v17 = *(volatile uint8_t *)(a1 + 19);
        if ( v17 != 255 )
        {
          v17 = (uint8_t)(v17 - 1);
          *(volatile uint8_t *)(a1 + 19) = v17;
          if ( !v17 )
          {
            if ( *(volatile uint8_t *)(v1 + 140 * v2 + 112) == 1 )
            {
              bt_conn_get_state(v6, *(volatile uint8_t *)(a1 + 18), 0);
              v12 = (int)v7;
            }
            else
            {
              if ( *(volatile uint8_t *)(a1 + 16) )
              {
                ke_event_set_lock(a1);
                *(volatile uint8_t *)(a1 + 16) = 0;
              }
              v12 = (int)v7;
            }
            goto LABEL_21;
          }
        }
        v13 = v1 + 140 * v2;
        v15 = *(volatile uint32_t *)(a1 + 28);
        v14 = *(volatile uint32_t *)(a1 + 24);
        v16 = *(volatile uint8_t *)(v13 + 112);
        v8 += v15 - v14;
        if ( v16 == 1 )
        {
          if ( *(volatile uint8_t *)(v13 + 132) )
          {
            v19 = *(volatile uint64_t *)(a1 + 36);
            v19 = (v19 & ~0xFFFFFFFFull) | ((uint32_t)(v19 + v15) & 0xFFFFFFFFu);
            v19 = (v19 & 0xFFFFFFFFull) | ((uint64_t)(uint32_t)(((uint32_t)(v19 >> 32) & 0xFFFFFFFFu) - (uint32_t)(1))) << 32;;
            *(volatile uint64_t *)(a1 + 36) = v19;
            if ( HIDWORD(v19) )
            {
              if ( (int)(v8 - *((volatile uint32_t *)off_12ACDC + 4) - 5000) >= 0 )
              {
                v3 = 1;
                v16 = *(volatile uint8_t *)(v13 + 112);
                goto LABEL_35;
              }
            }
            else
            {
              *(volatile uint8_t *)(a1 + 20) = v17;
              if ( v15 )
                *(volatile uint32_t *)(a1 + 40) = 0x80000000 / v15 - 1;
              set_flag_byte(*(volatile uint8_t *)(dword_12ACD0 + 1320 * v21 + 107), 3);
              if ( (int)(v8 - *((volatile uint32_t *)off_12ACDC + 4) - 5000) >= 0 )
              {
                v3 = 1;
                v16 = *(volatile uint8_t *)(v1 + 140 * v2 + 112);
                goto LABEL_35;
              }
LABEL_27:
              v14 = *(volatile uint32_t *)(a1 + 24);
            }
          }
          else if ( (int)(v8 - *((volatile uint32_t *)off_12ACDC + 4) - 5000) >= 0 )
          {
            v22 = *(volatile uint8_t *)(v13 + 112);
            ke_event_lock((void *)(uintptr_t)(a1), v8);
            *(volatile uint8_t *)(a1 + 16) = v22;
            mem_fill((int)v7);
            result = state_machine_step(v7);
            if ( *(volatile uint8_t *)(dword_12ACD0 + 1320 * v21 + 106) != 2 )
              return result;
            goto LABEL_30;
          }
        }
        else if ( (int)(v8 - *((volatile uint32_t *)off_12ACDC + 4) - 5000) >= 0 )
        {
          v3 = 1;
          goto LABEL_35;
        }
        v8 += v14;
      }
      while ( (int)(v8 - *((volatile uint32_t *)off_12ACDC + 4) - 5000) < 0 );
      v3 = 2;
      if ( *(volatile uint8_t *)(v1 + 140 * v2 + 112) )
        goto LABEL_36;
LABEL_42:
      if ( **(volatile int16_t **)off_12ACD4 < 0 && *(volatile uint8_t *)(v6 + 106) )
        mmio_irq_clear(dword_12ACEC, dword_12ACF0, 79);
      *(volatile uint32_t *)(a1 + 44) = *(volatile uint32_t *)off_12ACE4 - *((volatile uint32_t *)off_12ACDC + 4) + *(volatile uint32_t *)(v6 + 132) + v8;
      goto LABEL_36;
    }
    if ( **v9 < 0 )
    {
      mmio_irq_clear(dword_12ACE0, v10, 720);
      v9 = (volatile int16_t **)off_12ACD4;
      v10 = dword_12ACD8;
    }
    if ( (int)(v8 - v11[4] - 5000) >= 0 )
      break;
    if ( !v3 )
      goto LABEL_10;
  }
  if ( !v3 )
  {
LABEL_10:
    v12 = (int)v7;
LABEL_21:
    mem_fill(v12);
    return state_machine_step(v7);
  }
  v16 = *(volatile uint8_t *)(v1 + 140 * v2 + 112);
LABEL_35:
  if ( !v16 )
    goto LABEL_42;
LABEL_36:
  ke_event_lock((void *)(uintptr_t)(a1), v8);
  *(volatile uint8_t *)(a1 + 16) = v3;
  mem_fill((int)v7);
  result = state_machine_step(v7);
  if ( *(volatile uint8_t *)(dword_12ACD0 + 1320 * v21 + 106) == 2 && v3 == 1 )
LABEL_30:
    *(volatile uint32_t *)(dword_12ACD0 + 1320 * v21 + 4) |= 0x20u;
  return result;
}



// rf_write_register @ 0x12acf8
int rf_write_register(int result, int a2) {
  volatile int *v2; // r7
  volatile uint32_t *v3; // r9
  volatile int *v4; // r8
  int v5; // r10
  int v6; // r5
  int v8; // r6
  int v9; // r4
  int v10; // r1
  int v11; // r3
  int v12; // r2
  int v13; // r2
  int v14; // r3

  v2 = (volatile int *)off_12AD98;
  v3 = (void *)(uintptr_t)(off_12AD9C);
  v4 = (volatile int *)off_12ADA0;
  v5 = dword_12AD94 + 140 * *(volatile uint8_t *)(result + 1225);
  v6 = 0;
  v8 = result;
  v9 = v5;
  v10 = 0;
  while ( 1 )
  {
    if ( !*(volatile uint8_t *)(v9 + 32) && *(volatile uint8_t *)(v9 + 16) )
    {
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *v4 = 1;
      }
      result = *(volatile uint32_t *)(v9 + 12) + a2;
      v11 = result - v3[4];
      v12 = *v2 + 1;
      *v2 = v12;
      if ( v11 - 62 >= 0 )
      {
        *(volatile uint32_t *)(v8 + 88) = 0;
        result = ke_event_lock((void *)(uintptr_t)(v9), result);
        v12 = *v2;
        v10 = 1;
        if ( !*v2 )
          goto LABEL_8;
      }
      else if ( !v12 )
      {
        goto LABEL_8;
      }
      v13 = v12 - 1;
      v14 = *v4;
      *v2 = v13;
      if ( !v13 && v14 )
        __enable_irq();
    }
LABEL_8:
    v9 += 48;
    if ( v6 )
      break;
    v6 = 1;
  }
  if ( v10 )
    return mem_fill(v5);
  return result;
}



// bt_conn_is_connected @ 0x12ada4
int bt_conn_is_connected(int a1) {
  volatile uint8_t *v1; // r3
  int result; // r0

  v1 = (volatile uint8_t *)(dword_12ADD0 + 140 * a1);
  if ( v1[113] == 255 )
    return 0;
  result = v1[132];
  if ( v1[132] )
    return (uint8_t)(13 * v1[136] + 11);
  return result;
}



// bt_hci_fill_cmd @ 0x12add4
volatile uint8_t * bt_hci_fill_cmd(volatile uint8_t *result) {
  *result = -35;
  result[2] = 80;
  result[3] = 111;
  result[4] = -102;
  result[5] = 9;
  result[6] = 12;
  return result;
}



// bt_conn_read_info @ 0x12adf4
int bt_conn_read_info(int a1, int a2) {
  int v2; // r6
  int v3; // r3
  char v4; // r2
  int v5; // r4
  volatile uint32_t *v6; // r9
  volatile uint32_t *v7; // r8
  int v8; // r3
  int v9; // r2
  int16_t v10; // r4
  int result; // r0

  v2 = dword_12AEB0;
  v3 = dword_12AEB0 + 140 * a1;
  v4 = *(volatile uint8_t *)(v3 + 120);
  *(volatile uint8_t *)(a2 + 9) = v4;
  v5 = *(volatile uint8_t *)(v3 + 115);
  *(volatile uint8_t *)(v3 + 120) = v4 + 1;
  if ( v5 )
    *(volatile uint8_t *)(a2 + 10) = v5 | 0x80;
  else
    *(volatile uint8_t *)(a2 + 10) = 0;
  v6 = (void *)(uintptr_t)(off_12AEB4);
  v7 = (void *)(uintptr_t)(off_12AEB8);
  v8 = v2 + 140 * a1;
  v9 = a2 + 11;
  v10 = 0;
  do
  {
    if ( *(volatile uint8_t *)(v8 + 16) && (!*(volatile uint8_t *)(v2 + 140 * a1 + 135) || !*(volatile uint8_t *)(v8 + 33) || *(volatile uint8_t *)(v8 + 32) != 1) )
    {
      *(volatile uint8_t *)v9 = *(volatile uint8_t *)(v8 + 20);
      *(volatile uint64_t *)(v9 + 1) = *(volatile uint64_t *)(v8 + 24);
      v10 = (uint8_t)(v10 + 1);
      *(volatile uint32_t *)(v9 + 9) = *v6 - v7[4] + *(volatile uint32_t *)(v8 + 36);
    }
    v9 += 13;
    v8 += 48;
  }
  while ( v9 != a2 + 37 );
  result = v2 + 140 * a1;
  *(volatile uint8_t *)(result + 136) = v10;
  *(volatile uint8_t *)(a2 + 1) = 13 * v10 + 9;
  *(volatile uint16_t *)(a2 + 7) = 13 * v10 + 2;
  return result;
}



// bt_control_dispatch @ 0x12aebc
int bt_control_dispatch(int result, int a2) {
  switch ( a2 )
  {
    case 2:
      result = dword_12AF20 + 140 * result;
      *(volatile uint8_t *)(result + 132) = 0;
      break;
    case 3:
      result = dword_12AF20 + 140 * result;
      if ( !*(volatile uint8_t *)(result + 132) )
        return (int)set_flag_byte(*(volatile uint8_t *)(result + 113), 1);
      break;
    case 1:
      result = dword_12AF20 + 140 * result;
      *(volatile uint8_t *)(result + 132) = 1;
      break;
    default:
      if ( **(volatile int16_t **)off_12AF1C < 0 )
        return mmio_irq_clear(dword_12AF28, dword_12AF24, 1898);
      break;
  }
  return result;
}



// bt_conn_set_bit @ 0x12af2c
int bt_conn_set_bit(int result) {
  if ( *(volatile uint8_t *)(result + 1224) )
  {
    if ( *(volatile uint8_t *)(result + 108) )
      *(volatile uint32_t *)(result + 4) |= 0x40u;
  }
  return result;
}



// rf_tx_power_configure_1 @ 0x12af44
int rf_tx_power_configure_1(int a1) {
  int v1; // r7
  int v3; // r5
  int v4; // r4
  int v5; // r9
  int v6; // r8
  volatile int **v7; // r0
  int v8; // r12
  int v9; // r1
  int v10; // r4
  unsigned int v11; // r2
  unsigned int v12; // r4
  int v13; // cc
  int v14; // r3
  int v15; // r1

  v1 = dword_12B018;
  v3 = *((volatile uint32_t *)off_12B01C + 4);
  bt_adv_check((volatile uint8_t *)(dword_12B018 + 1320 * *(volatile uint8_t *)(a1 + 28)));
  if ( *(volatile uint8_t *)(a1 + 31) )
  {
    v4 = *(volatile uint32_t *)(a1 + 16) > 2u;
    v5 = *(volatile uint8_t *)(a1 + 28);
    if ( *(volatile uint32_t *)(a1 + 20) > 2u )
      v4 |= 2u;
    if ( (*(volatile uint8_t *)(a1 + 29) ^ v4) << 30 )
      bt_dev_check_ready(*(volatile uint8_t *)(a1 + 28), v4);
    v6 = *(volatile uint8_t *)(a1 + 28);
    *(volatile uint8_t *)(a1 + 29) = v4;
    v7 = *(volatile int ***)(v1 + 1320 * v5 + 240);
    if ( v7 )
    {
      v8 = dword_12B024;
      do
      {
        v9 = *((volatile uint8_t *)v7 + 35);
        v7 = (volatile int **)*v7;
        v10 = 3 * v9 + v8;
        v11 = *(volatile uint8_t *)(v10 + 1);
        v12 = *(volatile uint8_t *)(v10 + 2);
        v13 = v11 > 2;
        v14 = 3 * v9;
        if ( v11 > 2 )
          v11 = (v11 & ~0xFFu) | ((uint8_t)(1) & 0xFFu);
        v15 = v8 + v14;
        if ( !v13 )
          v11 = (v11 & ~0xFFu) | ((uint8_t)(0) & 0xFFu);
        if ( v12 > 2 )
          v11 = (v11 & ~0xFFu) | ((uint8_t)(v11 | 2) & 0xFFu);
        *(volatile uint8_t *)(v8 + v14) = v11;
        *(volatile uint8_t *)(v15 + 1) = 0;
        *(volatile uint8_t *)(v15 + 2) = 0;
      }
      while ( v7 );
    }
  }
  else
  {
    v6 = *(volatile uint8_t *)(a1 + 28);
  }
  *(volatile uint8_t *)(a1 + 31) = *((volatile uint32_t *)off_12B020 + 10) == *(volatile uint32_t *)(v1 + 1320 * v6 + 72);
  *(volatile uint32_t *)(a1 + 16) = 0;
  *(volatile uint32_t *)(a1 + 20) = 0;
  return ke_event_lock((void *)(uintptr_t)(a1), v3 + 102400);
}



// tx_slot_state_get @ 0x12b028
volatile int * tx_slot_state_get(int a1) {
  int v1; // r4
  int v2; // r6
  char v3; // r5
  int v4; // r7
  volatile int *result; // r0
  int v6; // r3
  int v7; // r1

  v1 = dword_12B05C;
  v2 = dword_12B05C + 32 * a1;
  v3 = a1;
  v4 = 32 * a1;
  if ( *(volatile uint8_t *)(v2 + 30) )
    ke_event_set_lock(dword_12B05C + 32 * a1);
  result = memset((volatile int *)v2, 0, 0x20u);
  v6 = v1 + v4;
  v7 = dword_12B060;
  *(volatile uint32_t *)(v6 + 8) = v2;
  *(volatile uint8_t *)(v6 + 28) = v3;
  *(volatile uint32_t *)(v6 + 4) = v7;
  *(volatile uint32_t *)(v6 + 24) = 3;
  return result;
}



// tx_slot_state_init @ 0x12b064
volatile int *tx_slot_state_init() {
  volatile int *result; // r0
  volatile uint8_t *v1; // r3
  int v2; // r1

  tx_slot_state_get(0);
  tx_slot_state_get(1);
  tx_slot_state_get(2);
  result = tx_slot_state_get(3);
  v1 = (volatile uint8_t *)dword_12B094;
  v2 = dword_12B094 + 96;
  do
  {
    v1[1] = 0;
    v1[2] = 0;
    *v1 = 0;
    v1 += 3;
  }
  while ( v1 != (volatile uint8_t *)v2 );
  return result;
}



