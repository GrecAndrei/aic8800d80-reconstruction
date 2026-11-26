// main_loop_init @ 0x133a54
int main_loop_init() {
  int v0; // r2
  struct __attribute__((packed)) { int v2; // [sp+0h] [bp-Ch] BYREF
  int v3; // [sp+4h] [bp-8h] BYREF
  } _frame;
  v0 = **(volatile int16_t **)off_133AB0;
  _frame.v2 = 0;
  _frame.v3 = 0;
  if ( v0 < 0 && rx_rate_field_parse(6u) != 1 )
    mmio_clear_register(dword_133AB8, dword_133AB4, 303);
  get_controller_state_1((void *)(&_frame.v2), (void *)(&_frame.v3));
  if ( _frame.v2 && _frame.v3 )
  {
    rx_packet_handler_3(_frame.v2, _frame.v3, 0);
    return 0;
  }
  else
  {
    bt_setup_conn_profile(1);
    return 0;
  }
}



// main_loop_check @ 0x133abc
int main_loop_check() {
  int v0; // r2
  unsigned int v1; // r3
  volatile uint8_t *v2; // r3
  volatile uint8_t *v4; // r4
  int v5; // r3
  int v6; // r1
  struct __attribute__((packed)) { int v7; // [sp+0h] [bp-Ch] BYREF
  int a2; // [sp+4h] [bp-8h] BYREF
  } _frame;
  if ( **(volatile int16_t **)off_133BC8 < 0 && rx_rate_field_parse(6u) != 4 && rx_rate_field_parse(6u) != 10 )
    mmio_clear_register((int)aKeStateGetTask_9, (int)aMeSetActiveCfm, 697);
  if ( rx_rate_field_parse(6u) == 10 )
  {
    v4 = (void *)(uintptr_t)(off_133BCC);
    v5 = *((volatile uint8_t *)off_133BCC + 4);
    *(volatile uint32_t *)(*((volatile uint32_t *)off_133BCC + 2) + 472) = 0;
    if ( v5 )
    {
      ke_msg_send_no_param(6148, 13, 6);
      v4[4] = 0;
    }
    ke_msg_send_2(*(volatile uint32_t *)v4 + 12);
    v6 = (uint8_t)v4[33];
    *(volatile uint32_t *)v4 = 0;
    if ( v6 )
    {
      _frame.v7 = 0;
      _frame.a2 = 0;
      get_controller_state_1((void *)(&_frame.v7), (void *)(&_frame.a2));
      rx_packet_handler_3(_frame.v7, _frame.a2, 0);
    }
    else
    {
      ke_state_set(6u, 0);
    }
    return 0;
  }
  else
  {
    v0 = *((volatile uint32_t *)off_133BCC + 4);
    v1 = *(volatile uint8_t *)(v0 + 59);
    if ( v1 == 2 )
    {
      if ( (*(volatile uint32_t *)(v0 + 48) & 0x40) != 0 )
      {
        sm_assoc_req_send();
        v2 = (void *)(uintptr_t)(off_133BD0);
        if ( *((volatile uint8_t *)off_133BD0 + 13) )
        {
LABEL_6:
          if ( (v2[15] & 1) != 0 )
          {
            ke_timer_set(6155, 6, dword_133BD4);
            mmio_set_control_bit_26();
          }
        }
        return 0;
      }
LABEL_5:
      bt_get_profile_by_id(1, 0);
      v2 = (void *)(uintptr_t)(off_133BD0);
      if ( *((volatile uint8_t *)off_133BD0 + 13) )
        goto LABEL_6;
      return 0;
    }
    if ( v1 <= 2 )
      goto LABEL_5;
    if ( v1 == 3 )
    {
      bt_get_current_profile_conn(dword_133BD8);
      if ( *((volatile uint8_t *)off_133BD0 + 13) )
        *((volatile uint8_t *)off_133BD0 + 15) |= 2u;
      return 0;
    }
    bt_setup_conn_profile(1);
    return 0;
  }
}


// send_control_command @ 0x133be4
int send_control_command(int a1, volatile uint8_t *a2) {
  int v2; // r4
  int result; // r0
  int v4; // r3
  int v5; // r4

  v2 = *a2;
  check_status_bits(256, aConnLossInd);
  result = rx_rate_field_parse(6u);
  if ( result )
    return 2;
  v4 = dword_133C2C + 1320 * v2;
  v5 = *(volatile uint8_t *)(v4 + 106);
  if ( !*(volatile uint8_t *)(v4 + 106) )
  {
    result = *(volatile uint8_t *)(v4 + 108);
    if ( *(volatile uint8_t *)(v4 + 108) )
    {
      bt_schedule_ack_timeout(v4, 1, *(volatile uint8_t *)(v4 + 106));
      return v5;
    }
  }
  return result;
}


