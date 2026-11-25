// is_channel_index_valid @ 0x12ad34
int is_channel_index_valid(int a1, unsigned int a2, int a3) {
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
      result = dword_12ADB4 + 32 * a1;
      v4 = 3 * a2 + dword_12ADB8;
      v5 = *(volatile uint8_t *)(v4 + 2);
      ++*(volatile uint32_t *)(result + 20);
      if ( v5 <= 2 )
        *(volatile uint8_t *)(v4 + 2) = v5 + 1;
    }
    else
    {
      result = dword_12ADB4 + 32 * a1;
      v6 = 3 * a2 + dword_12ADB8;
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
      v8 = **(volatile int16_t **)off_12ADBC;
      ++*(volatile uint32_t *)(dword_12ADB4 + 32 * a1 + 20);
      if ( v8 < 0 )
        irq_disable_mmio_write(dword_12ADC4, dword_12ADC0, 365);
      __und(0xFFu);
    }
    result = dword_12ADB4 + 32 * a1;
    ++*(volatile uint32_t *)(result + 16);
  }
  return result;
}



// calc_channel_rate @ 0x12adc8
int calc_channel_rate(int a1, int a2, int a3) {
  int v3; // r3
  unsigned int v4; // r2
  int result; // r0

  v3 = dword_12ADE8;
  v4 = (unsigned int)(1967 * a2 * a3) >> 16;
  result = dword_12ADE8 + 32 * a1;
  if ( v4 )
    *(volatile uint32_t *)(result + 24) = v4;
  else
    v3 = 1;
  if ( !v4 )
    *(volatile uint32_t *)(result + 24) = v3;
  return result;
}



// get_state_name @ 0x12adec
int get_state_name(int a1, int a2, int a3, uint16_t a4) {
  int v5; // r4

  v5 = hci_cmd_handler(2u);
  check_feature_flag(4, "%s:%d\r\n", aScanCancelReqH, v5);
  if ( v5 )
    *((volatile uint8_t *)off_12AE24 + 11) = 1;
  else
    rf_execute_cmd(1, a4);
  return 0;
}


// is_state_three @ 0x12ae28
int is_state_three() {
  int v0; // r0
  volatile uint8_t *v1; // r4
  int v2; // r0
  unsigned int v3; // r2
  unsigned int v4; // r3
  int v5; // r1

  if ( hci_cmd_handler(2u) != 3 )
  {
    v0 = hci_cmd_handler(2u);
    alloc_tx_event("end st=%d\n", v0);
  }
  if ( **(volatile int16_t **)off_12AEB8 < 0 && hci_cmd_handler(2u) != 3 )
    irq_disable_mmio_write((int)aKeStateGetTask_2, (int)aMmScanChannelE, 201);
  v1 = (void *)(uintptr_t)(off_12AEBC);
  v2 = *(volatile uint32_t *)off_12AEBC;
  v3 = *(volatile uint8_t *)(*(volatile uint32_t *)off_12AEBC + 367);
  v4 = (uint8_t)(*((volatile uint8_t *)off_12AEBC + 10) + 1);
  *((volatile uint8_t *)off_12AEBC + 10) = v4;
  if ( v3 <= v4 || v1[11] )
  {
    tx_process_jump((int)(uintptr_t)((volatile char *)(v2 - 12)));
    v5 = *((volatile uint16_t *)v1 + 4);
    if ( v1[11] )
    {
      rf_execute_cmd(0, v5);
      v1[11] = 0;
    }
    else
    {
      mac_write_header_word(2050, v5, 2);
    }
    ke_state_set(2u, 0);
    return 0;
  }
  else
  {
    process_entry_list();
    return 0;
  }
}


