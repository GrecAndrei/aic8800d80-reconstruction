// tx_len_check @ 0x12ae74
int tx_len_check(int a1, unsigned int a2, int a3) {
  int result; // r0
  int v4; // r1
  unsigned int v5; // r3
  int v6; // r1
  unsigned int v7; // r2
  int v8; // r2

  if ( a2 <= 0x1F )
  {
    if ( a3 )
    {
      result = dword_12AEF4 + 32 * a1;
      v4 = 3 * a2 + dword_12AEF8;
      v5 = *(volatile uint8_t *)(v4 + 2);
      ++*(volatile uint32_t *)(result + 20);
      if ( v5 <= 2 )
        *(volatile uint8_t *)(v4 + 2) = v5 + 1;
    }
    else
    {
      result = dword_12AEF4 + 32 * a1;
      v6 = 3 * a2 + dword_12AEF8;
      v7 = *(volatile uint8_t *)(v6 + 1);
      ++*(volatile uint32_t *)(result + 16);
      if ( v7 <= 2 )
        *(volatile uint8_t *)(v6 + 1) = v7 + 1;
    }
  }
  else
  {
    if ( a3 )
    {
      v8 = **(volatile int16_t **)off_12AEFC;
      ++*(volatile uint32_t *)(dword_12AEF4 + 32 * a1 + 20);
      if ( v8 < 0 )
        mmio_clear_register(dword_12AF04, dword_12AF00, 365);
      __und(0xFFu);
    }
    result = dword_12AEF4 + 32 * a1;
    ++*(volatile uint32_t *)(result + 16);
  }
  return result;
}



// tx_arbiter_calc @ 0x12af08
int tx_arbiter_calc(int a1, int a2, int a3) {
  int v3; // r3
  unsigned int v4; // r2
  int result; // r0

  v3 = dword_12AF28;
  v4 = (unsigned int)(1967 * a2 * a3) >> 16;
  result = dword_12AF28 + 32 * a1;
  if ( v4 )
    *(volatile uint32_t *)(result + 24) = v4;
  else
    v3 = 1;
  if ( !v4 )
    *(volatile uint32_t *)(result + 24) = v3;
  return result;
}



// ke_msg_dequeue @ 0x12af2c
int ke_msg_dequeue(int a1, int a2, int a3, uint16_t a4) {
  int v5; // r4

  v5 = rx_rate_field_parse(2u);
  check_status_bits(4, "%s:%d\r\n", aScanCancelReqH, v5);
  if ( v5 )
    *((volatile uint8_t *)off_12AF64 + 11) = 1;
  else
    reg_read_indirect(1, a4);
  return 0;
}


// ke_state_check @ 0x12af68
int ke_state_check() {
  int v0; // r0
  volatile uint8_t *v1; // r4
  int v2; // r0
  unsigned int v3; // r2
  unsigned int v4; // r3
  int v5; // r1

  if ( rx_rate_field_parse(2u) != 3 )
  {
    v0 = rx_rate_field_parse(2u);
    event_dispatch("end st=%d\n", v0);
  }
  if ( **(volatile int16_t **)off_12AFF8 < 0 && rx_rate_field_parse(2u) != 3 )
    mmio_clear_register((int)aKeStateGetTask_2, (int)aMmScanChannelE, 201);
  v1 = (void *)(uintptr_t)(off_12AFFC);
  v2 = *(volatile uint32_t *)off_12AFFC;
  v3 = *(volatile uint8_t *)(*(volatile uint32_t *)off_12AFFC + 367);
  v4 = (uint8_t)(*((volatile uint8_t *)off_12AFFC + 10) + 1);
  *((volatile uint8_t *)off_12AFFC + 10) = v4;
  if ( v3 <= v4 || v1[11] )
  {
    branch_to_12cbc8((int)(uintptr_t)((volatile char *)(v2 - 12)));
    v5 = *((volatile uint16_t *)v1 + 4);
    if ( v1[11] )
    {
      reg_read_indirect(0, v5);
      v1[11] = 0;
    }
    else
    {
      ke_msg_send_no_param(2050, v5, 2);
    }
    rx_phy_status_parse(2u, 0);
    return 0;
  }
  else
  {
    ke_timer_setup();
    return 0;
  }
}


