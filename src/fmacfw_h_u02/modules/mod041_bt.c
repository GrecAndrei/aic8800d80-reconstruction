// bt_parse_adv_report @ 0x12a2b4
int bt_parse_adv_report(int result, volatile uint8_t *a2, int a3, int a4) {
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
      if ( **(volatile int16_t **)off_12A320 < 0 )
      {
        if ( *(volatile uint8_t *)(result + 106) )
        {
          v7 = a4;
          irq_disable_mmio_write(dword_12A328, dword_12A324, 64);
          a4 = v7;
        }
      }
      return sec_table_entry_count(v5, v4, *(volatile uint32_t *)(v6 + 132) + a4);
    }
  }
  return result;
}



// bt_ll_flow_control_check @ 0x12a32c
int bt_ll_flow_control_check() {
  int result; // r0
  volatile int *v1; // r3

  result = *(volatile uint8_t *)off_12A378;
  if ( *(volatile uint8_t *)off_12A378 )
  {
    result = *((volatile uint8_t *)off_12A37C + 17);
    if ( *((volatile uint8_t *)off_12A37C + 17) )
    {
      return 0;
    }
    else if ( *((volatile uint8_t *)off_12A37C + 18) <= 1u )
    {
      v1 = *((volatile int **)off_12A37C + 2);
      if ( v1 )
      {
        while ( *((volatile uint8_t *)v1 + 106) != 2 || !*((volatile uint8_t *)v1 + 1224) )
        {
          v1 = (volatile int *)*v1;
          if ( !v1 )
            return result;
        }
        return *(volatile uint8_t *)(dword_12A380 + 140 * *((volatile uint8_t *)v1 + 1225) + 133) == 0;
      }
    }
  }
  return result;
}



// ll_conn_is_connected @ 0x12a384
volatile uint8_t * ll_conn_is_connected(int a1, int a2) {
  volatile uint8_t *result; // r0
  int v3; // r3
  int v4; // r4
  volatile uint8_t *v5; // r2
  int v6; // r5
  volatile uint8_t *v7; // r4

  result = (volatile uint8_t *)(dword_12A3E0 + 1320 * a1);
  if ( result[1224] && result[106] == 2 )
  {
    v3 = result[1225];
    v4 = dword_12A3E4;
    v5 = (volatile uint8_t *)(dword_12A3E4 + 140 * v3);
    v6 = v5[132];
    v5[135] = a2 != 0;
    v7 = (volatile uint8_t *)(v4 + 140 * v3);
    if ( v6 )
      util_get_state(v5[113], 3);
    return rsn_parse_ie(v7);
  }
  return result;
}



// lll_conn_phy_get @ 0x12a3e8
volatile uint8_t * lll_conn_phy_get(int a1, uint8_t a2) {
  int v2; // r5
  int v3; // r4
  volatile uint8_t *v4; // r3
  int v5; // r0

  v2 = dword_12A420;
  v3 = *(volatile uint8_t *)(a1 + 1225);
  v4 = (volatile uint8_t *)(dword_12A420 + 140 * v3);
  v5 = v4[113];
  v4[115] = a2;
  v4[114] = 1;
  util_get_state(v5, 3);
  return rsn_parse_ie((volatile uint8_t *)(v2 + 140 * v3));
}



// lll_conn_phy_ld_get @ 0x12a424
volatile char * lll_conn_phy_ld_get(int a1) {
  int v1; // r7
  int v2; // r4
  volatile uint8_t *v3; // r6
  int v4; // r3
  int v5; // r4
  char v6; // r1

  v1 = dword_12A48C;
  v2 = *(volatile uint8_t *)(a1 + 1225);
  v3 = (volatile uint8_t *)(dword_12A48C + 140 * v2);
  v4 = v3[114];
  v3[115] = 0;
  if ( v4 )
  {
    mem_set_util(140 * v2 + 96 + v1);
    v3[114] = 0;
  }
  rsn_parse_ie(v3);
  v5 = v1 + 140 * v2;
  if ( *(volatile uint8_t *)(v5 + 121) )
    v6 = 3;
  else
    v6 = 2;
  return util_get_state(*(volatile uint8_t *)(v5 + 113), v6);
}



// lll_conn_get @ 0x12a490
volatile uint8_t * lll_conn_get(volatile uint8_t *result) {
  if ( result[1224] )
    return rsn_parse_ie((volatile uint8_t *)(dword_12A4B0 + 140 * result[1225]));
  return result;
}



// lll_conn_state_match @ 0x12a4b4
int lll_conn_state_match(int a1, int a2, char a3, char a4, unsigned int a5, int a6, int a7) {
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

  v7 = dword_12A5BC;
  v8 = *(volatile uint8_t *)(a1 + 1225);
  v9 = (volatile uint8_t *)(dword_12A5BC + 140 * v8);
  if ( v9[112] != 1 )
    return 255;
  v10 = v9[16];
  v11 = (volatile uint8_t *)(dword_12A5BC + 140 * v8);
  if ( v9[16] )
  {
    if ( v9[64] )
      return 255;
    v10 = 1;
    v13 = 140 * v8 + 48 + dword_12A5BC;
    v14 = 1;
  }
  else
  {
    v13 = dword_12A5BC + 140 * v8;
    v14 = v9[16];
  }
  v15 = dword_12A5BC + 140 * v8;
  v16 = a2 == 0;
  v17 = dword_12A5BC + 140 * v8 + 48 * v14;
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
  mm_timer_set((void *)(uintptr_t)(v13), a7);
  v21 = 140 * v8;
  *(volatile uint8_t *)(v7 + v21 + 48 * v14 + 16) = 1;
  util_get_state(*(volatile uint8_t *)(v21 + v7 + 113), 3);
  bus_cmd52_write((int)v11, v10);
  rsn_derive_key((int)v11);
  rsn_parse_ie(v11);
  return v10;
}



// lll_conn_ready_check @ 0x12a5c0
int lll_conn_ready_check(int a1, unsigned int a2, int a3) {
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
  v4 = dword_12A69C;
  result = *(volatile uint8_t *)(dword_12A69C + 140 * v3 + 112);
  if ( result != 1 )
    return 1;
  if ( a2 <= 1 )
  {
    v7 = 140 * v3 + 48 * a2 + dword_12A69C;
    if ( *(volatile uint8_t *)(v7 + 16) )
    {
      if ( !a3 || *(volatile uint8_t *)(v7 + 32) )
      {
        mem_set_util(48 * a2 + 140 * v3 + dword_12A69C);
        v8 = 140 * v3 + 48 * a2 + v4;
        *(volatile uint8_t *)(v8 + 16) = 0;
        rsn_derive_key(v4 + 140 * v3);
        rsn_parse_ie((volatile uint8_t *)(v4 + 140 * v3));
        v9 = v4 + 140 * v3;
        v10 = *(volatile uint8_t *)(v8 + 32);
        v11 = (uint8_t)(*(volatile uint8_t *)(v9 + 121) - 1);
        *(volatile uint8_t *)(v9 + 121) = v11;
        if ( v10 == 1 )
          --*(volatile uint8_t *)(v9 + 122);
        v12 = v4 + 140 * v3;
        if ( *(volatile uint8_t *)(v12 + 115) || v11 )
          util_get_state(*(volatile uint8_t *)(v4 + 140 * v3 + 113), 3);
        else
          util_get_state(*(volatile uint8_t *)(v12 + 113), 2);
        bus_cmd52_write(v4 + 140 * v3, a2);
        return 0;
      }
    }
  }
  return result;
}



// lll_conn_event_prepare @ 0x12a6a0
/* luna: Advances low-level connection-event timing and countdown state, invoking readiness handling when the countdown expires. */
volatile uint8_t * lll_conn_event_prepare(int a1) {
  int conn_slot_table_base; // r9
  int conn_slot_index; // r8
  int event_state; // r6
  int conn_slot; // r3
  int conn_context; // r10
  volatile uint8_t *conn_slot_ptr; // r7
  int event_time; // r4
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
  int conn_context_index; // [sp+0h] [bp-Ch]
  char v22; // [sp+4h] [bp-8h]

  conn_slot_table_base = dword_12A990;
  conn_slot_index = *(volatile uint8_t *)(a1 + 17);
  event_state = *(volatile uint8_t *)(a1 + 16);
  conn_slot = dword_12A990 + 140 * conn_slot_index;
  conn_context_index = *(volatile uint8_t *)(conn_slot + 113);
  conn_context = dword_12A96C + 1320 * conn_context_index;
  conn_slot_ptr = (volatile uint8_t *)conn_slot;
  if ( *(volatile uint8_t *)(conn_slot + 112) == 1 )
  {
    event_time = *(volatile uint32_t *)(a1 + 12);
  }
  else
  {
    v20 = *(volatile uint32_t *)(a1 + 44);
    if ( **(volatile int16_t **)off_12A970 < 0 && *(volatile uint8_t *)(conn_context + 106) )
      irq_disable_mmio_write(dword_12A988, dword_12A984, 98);
    event_time = v20 + *((volatile uint32_t *)off_12A978 + 4) - *(volatile uint32_t *)off_12A980 - *(volatile uint32_t *)(conn_context + 132);
  }
  v9 = (volatile int16_t **)off_12A970;
  v10 = dword_12A974;
  v11 = (void *)(uintptr_t)(off_12A978);
  while ( 1 )
  {
    if ( event_state == 1 )
      goto LABEL_27;
    if ( event_state == 2 )
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
            if ( *(volatile uint8_t *)(conn_slot_table_base + 140 * conn_slot_index + 112) == 1 )
            {
              lll_conn_ready_check(conn_context, *(volatile uint8_t *)(a1 + 18), 0);
              v12 = (int)conn_slot_ptr;
            }
            else
            {
              if ( *(volatile uint8_t *)(a1 + 16) )
              {
                mem_set_util(a1);
                *(volatile uint8_t *)(a1 + 16) = 0;
              }
              v12 = (int)conn_slot_ptr;
            }
            goto LABEL_21;
          }
        }
        v13 = conn_slot_table_base + 140 * conn_slot_index;
        v15 = *(volatile uint32_t *)(a1 + 28);
        v14 = *(volatile uint32_t *)(a1 + 24);
        v16 = *(volatile uint8_t *)(v13 + 112);
        event_time += v15 - v14;
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
              if ( (int)(event_time - *((volatile uint32_t *)off_12A978 + 4) - 5000) >= 0 )
              {
                event_state = 1;
                v16 = *(volatile uint8_t *)(v13 + 112);
                goto LABEL_35;
              }
            }
            else
            {
              *(volatile uint8_t *)(a1 + 20) = v17;
              if ( v15 )
                *(volatile uint32_t *)(a1 + 40) = 0x80000000 / v15 - 1;
              util_get_state(*(volatile uint8_t *)(dword_12A96C + 1320 * conn_context_index + 107), 3);
              if ( (int)(event_time - *((volatile uint32_t *)off_12A978 + 4) - 5000) >= 0 )
              {
                event_state = 1;
                v16 = *(volatile uint8_t *)(conn_slot_table_base + 140 * conn_slot_index + 112);
                goto LABEL_35;
              }
LABEL_27:
              v14 = *(volatile uint32_t *)(a1 + 24);
            }
          }
          else if ( (int)(event_time - *((volatile uint32_t *)off_12A978 + 4) - 5000) >= 0 )
          {
            v22 = *(volatile uint8_t *)(v13 + 112);
            mm_timer_set((void *)(uintptr_t)(a1), event_time);
            *(volatile uint8_t *)(a1 + 16) = v22;
            rsn_derive_key((int)conn_slot_ptr);
            result = rsn_parse_ie(conn_slot_ptr);
            if ( *(volatile uint8_t *)(dword_12A96C + 1320 * conn_context_index + 106) != 2 )
              return result;
            goto LABEL_30;
          }
        }
        else if ( (int)(event_time - *((volatile uint32_t *)off_12A978 + 4) - 5000) >= 0 )
        {
          event_state = 1;
          goto LABEL_35;
        }
        event_time += v14;
      }
      while ( (int)(event_time - *((volatile uint32_t *)off_12A978 + 4) - 5000) < 0 );
      event_state = 2;
      if ( *(volatile uint8_t *)(conn_slot_table_base + 140 * conn_slot_index + 112) )
        goto LABEL_36;
LABEL_42:
      if ( **(volatile int16_t **)off_12A970 < 0 && *(volatile uint8_t *)(conn_context + 106) )
        irq_disable_mmio_write(dword_12A988, dword_12A98C, 79);
      *(volatile uint32_t *)(a1 + 44) = *(volatile uint32_t *)off_12A980 - *((volatile uint32_t *)off_12A978 + 4) + *(volatile uint32_t *)(conn_context + 132) + event_time;
      goto LABEL_36;
    }
    if ( **v9 < 0 )
    {
      irq_disable_mmio_write(dword_12A97C, v10, 720);
      v9 = (volatile int16_t **)off_12A970;
      v10 = dword_12A974;
    }
    if ( (int)(event_time - v11[4] - 5000) >= 0 )
      break;
    if ( !event_state )
      goto LABEL_10;
  }
  if ( !event_state )
  {
LABEL_10:
    v12 = (int)conn_slot_ptr;
LABEL_21:
    rsn_derive_key(v12);
    return rsn_parse_ie(conn_slot_ptr);
  }
  v16 = *(volatile uint8_t *)(conn_slot_table_base + 140 * conn_slot_index + 112);
LABEL_35:
  if ( !v16 )
    goto LABEL_42;
LABEL_36:
  mm_timer_set((void *)(uintptr_t)(a1), event_time);
  *(volatile uint8_t *)(a1 + 16) = event_state;
  rsn_derive_key((int)conn_slot_ptr);
  result = rsn_parse_ie(conn_slot_ptr);
  if ( *(volatile uint8_t *)(dword_12A96C + 1320 * conn_context_index + 106) == 2 && event_state == 1 )
LABEL_30:
    *(volatile uint32_t *)(dword_12A96C + 1320 * conn_context_index + 4) |= 0x20u;
  return result;
}



// lll_conn_rf_process @ 0x12a994
int lll_conn_rf_process(int result, int a2) {
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

  v2 = (volatile int *)off_12AA34;
  v3 = (void *)(uintptr_t)(off_12AA38);
  v4 = (volatile int *)off_12AA3C;
  v5 = dword_12AA30 + 140 * *(volatile uint8_t *)(result + 1225);
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
        result = mm_timer_set((void *)(uintptr_t)(v9), result);
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
    return rsn_derive_key(v5);
  return result;
}



// is_channel_entry_valid @ 0x12aa40
int is_channel_entry_valid(int a1) {
  volatile uint8_t *v1; // r3
  int result; // r0

  v1 = (volatile uint8_t *)(dword_12AA6C + 140 * a1);
  if ( v1[113] == 255 )
    return 0;
  result = v1[132];
  if ( v1[132] )
    return (uint8_t)(13 * v1[136] + 11);
  return result;
}



// init_fixed_packet_header @ 0x12aa70
volatile uint8_t * init_fixed_packet_header(volatile uint8_t *result) {
  *result = -35;
  result[2] = 80;
  result[3] = 111;
  result[4] = -102;
  result[5] = 9;
  result[6] = 12;
  return result;
}



// get_channel_entry_info @ 0x12aa90
/* luna: Serializes the connection sequence and status bytes plus up to three eligible channel entries into the output buffer, updating the sequence counter an */
int get_channel_entry_info(int a1, int a2) {
  int conn_table_base; // r6
  int conn; // r3
  char sequence; // r2
  int status; // r4
  volatile uint32_t *v6; // r9
  volatile uint32_t *v7; // r8
  int channel_entry; // r3
  int entry_out; // r2
  int16_t entry_count; // r4
  int result; // r0

  conn_table_base = dword_12AB4C;
  conn = dword_12AB4C + 140 * a1;
  sequence = *(volatile uint8_t *)(conn + 120);
  *(volatile uint8_t *)(a2 + 9) = sequence;
  status = *(volatile uint8_t *)(conn + 115);
  *(volatile uint8_t *)(conn + 120) = sequence + 1;
  if ( status )
    *(volatile uint8_t *)(a2 + 10) = status | 0x80;
  else
    *(volatile uint8_t *)(a2 + 10) = 0;
  v6 = (void *)(uintptr_t)(off_12AB50);
  v7 = (void *)(uintptr_t)(off_12AB54);
  channel_entry = conn_table_base + 140 * a1;
  entry_out = a2 + 11;
  entry_count = 0;
  do
  {
    if ( *(volatile uint8_t *)(channel_entry + 16) && (!*(volatile uint8_t *)(conn_table_base + 140 * a1 + 135) || !*(volatile uint8_t *)(channel_entry + 33) || *(volatile uint8_t *)(channel_entry + 32) != 1) )
    {
      *(volatile uint8_t *)entry_out = *(volatile uint8_t *)(channel_entry + 20);
      *(volatile uint64_t *)(entry_out + 1) = *(volatile uint64_t *)(channel_entry + 24);
      entry_count = (uint8_t)(entry_count + 1);
      *(volatile uint32_t *)(entry_out + 9) = *v6 - v7[4] + *(volatile uint32_t *)(channel_entry + 36);
    }
    entry_out += 13;
    channel_entry += 48;
  }
  while ( entry_out != a2 + 37 );
  result = conn_table_base + 140 * a1;
  *(volatile uint8_t *)(result + 136) = entry_count;
  *(volatile uint8_t *)(a2 + 1) = 13 * entry_count + 9;
  *(volatile uint16_t *)(a2 + 7) = 13 * entry_count + 2;
  return result;
}



// is_state_arg_valid @ 0x12ab58
int is_state_arg_valid(int result, int a2) {
  switch ( a2 )
  {
    case 2:
      result = dword_12ABBC + 140 * result;
      *(volatile uint8_t *)(result + 132) = 0;
      break;
    case 3:
      result = dword_12ABBC + 140 * result;
      if ( !*(volatile uint8_t *)(result + 132) )
        return (int)util_get_state(*(volatile uint8_t *)(result + 113), 1);
      break;
    case 1:
      result = dword_12ABBC + 140 * result;
      *(volatile uint8_t *)(result + 132) = 1;
      break;
    default:
      if ( **(volatile int16_t **)off_12ABB8 < 0 )
        return irq_disable_mmio_write(dword_12ABC4, dword_12ABC0, 1898);
      break;
  }
  return result;
}



// get_acl_flag @ 0x12abc8
int get_acl_flag(int result) {
  if ( *(volatile uint8_t *)(result + 1224) )
  {
    if ( *(volatile uint8_t *)(result + 108) )
      *(volatile uint32_t *)(result + 4) |= 0x40u;
  }
  return result;
}



// get_dev_entry @ 0x12abe0
int get_dev_entry(int a1) {
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

  v1 = dword_12ACB4;
  v3 = *((volatile uint32_t *)off_12ACB8 + 4);
  bt_start_operation((volatile uint8_t *)(dword_12ACB4 + 1320 * *(volatile uint8_t *)(a1 + 28)));
  if ( *(volatile uint8_t *)(a1 + 31) )
  {
    v4 = *(volatile uint32_t *)(a1 + 16) > 2u;
    v5 = *(volatile uint8_t *)(a1 + 28);
    if ( *(volatile uint32_t *)(a1 + 20) > 2u )
      v4 |= 2u;
    if ( (*(volatile uint8_t *)(a1 + 29) ^ v4) << 30 )
      ll_conn_is_connected(*(volatile uint8_t *)(a1 + 28), v4);
    v6 = *(volatile uint8_t *)(a1 + 28);
    *(volatile uint8_t *)(a1 + 29) = v4;
    v7 = *(volatile int ***)(v1 + 1320 * v5 + 240);
    if ( v7 )
    {
      v8 = dword_12ACC0;
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
  *(volatile uint8_t *)(a1 + 31) = *((volatile uint32_t *)off_12ACBC + 10) == *(volatile uint32_t *)(v1 + 1320 * v6 + 72);
  *(volatile uint32_t *)(a1 + 16) = 0;
  *(volatile uint32_t *)(a1 + 20) = 0;
  return mm_timer_set((void *)(uintptr_t)(a1), v3 + 102400);
}



// init_chan_entry @ 0x12acc4
volatile int * init_chan_entry(int a1) {
  int v1; // r4
  int v2; // r6
  char v3; // r5
  int v4; // r7
  volatile int *result; // r0
  int v6; // r3
  void *v7; // r1

  v1 = dword_12ACF8;
  v2 = dword_12ACF8 + 32 * a1;
  v3 = a1;
  v4 = 32 * a1;
  if ( *(volatile uint8_t *)(v2 + 30) )
    mem_set_util(dword_12ACF8 + 32 * a1);
  result = memset((volatile int *)v2, 0, 0x20u);
  v6 = v1 + v4;
  v7 = (void *)(uintptr_t)(off_12ACFC);
  *(volatile uint32_t *)(v6 + 8) = v2;
  *(volatile uint8_t *)(v6 + 28) = v3;
  *(volatile uint32_t *)(v6 + 4) = (int)(uintptr_t)(v7);
  *(volatile uint32_t *)(v6 + 24) = 3;
  return result;
}



// init_all_chan_entries @ 0x12ad00
/* luna: Initializes channel entries 0–3, then zeroes a 96-byte table in three-byte strides. */
volatile int *init_all_chan_entries() {
  volatile int *result; // r0
  volatile uint8_t *table_bytes; // r3
  int table_end; // r1

  init_chan_entry(0);
  init_chan_entry(1);
  init_chan_entry(2);
  result = init_chan_entry(3);
  table_bytes = (volatile uint8_t *)dword_12AD30;
  table_end = dword_12AD30 + 96;
  do
  {
    table_bytes[1] = 0;
    table_bytes[2] = 0;
    *table_bytes = 0;
    table_bytes += 3;
  }
  while ( table_bytes != (volatile uint8_t *)table_end );
  return result;
}



