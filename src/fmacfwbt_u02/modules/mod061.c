// rf_cal_trigger @ 0x136408
int rf_cal_trigger(int value) {
  int v2; // r0

  if ( **(volatile int16_t **)off_13643C >= 0 || (value = hci_cmd_send_short(7u), value == 3) )
  {
    txpwr_get_state(value);
    return 0;
  }
  else
  {
    v2 = mmio_irq_clear(dword_136444, dword_136440, 415);
    txpwr_get_state(v2);
    return 0;
  }
}



// rf_cal_cmd @ 0x136448
int rf_cal_cmd() {
  if ( **(volatile int16_t **)off_136490 < 0 && hci_cmd_send_short(7u) != 3 && hci_cmd_send_short(7u) )
    mmio_irq_clear(dword_136498, dword_136494, 442);
  if ( hci_cmd_send_short(7u) == 3 )
    txpwr_get_state(3);
  return 0;
}



// tx_schedule_radio_task @ 0x13649c
int tx_schedule_radio_task() {
  int v0; // r0

  if ( **(volatile int16_t **)off_1364F8 < 0 && hci_cmd_send_short(7u) != 1 && hci_cmd_send_short(7u) && hci_cmd_send_short(7u) != 3 )
    mmio_irq_clear(dword_136500, dword_1364FC, 274);
  v0 = hci_cmd_send_short(7u);
  if ( v0 != 1 )
  {
    v0 = hci_cmd_send_short(7u);
    if ( v0 != 3 )
      return 0;
  }
  txpwr_get_state(v0);
  return 0;
}



// txpwr_update_state @ 0x136504
int txpwr_update_state(int value) {
  int v2; // r0

  if ( **(volatile int16_t **)off_136538 >= 0 || (value = hci_cmd_send_short(7u), value == 1) )
  {
    txpwr_get_state(value);
    return 0;
  }
  else
  {
    v2 = mmio_irq_clear(dword_136540, dword_13653C, 311);
    txpwr_get_state(v2);
    return 0;
  }
}



// txpwr_apply_path @ 0x136544
int txpwr_apply_path() {
  if ( **(volatile int16_t **)off_13657C >= 0 || hci_cmd_send_short(7u) == 2 )
  {
    txpwr_send_cmd(0);
    return 0;
  }
  else
  {
    mmio_irq_clear(dword_136584, dword_136580, 388);
    txpwr_send_cmd(0);
    return 0;
  }
}



// tx_schedule_radio_task_alt @ 0x136588
int tx_schedule_radio_task_alt() {
  volatile int16_t **v0; // r4

  v0 = (volatile int16_t **)off_136614;
  if ( **(volatile int16_t **)off_136614 < 0 && hci_cmd_send_short(7u) != 1 && hci_cmd_send_short(7u) && hci_cmd_send_short(7u) != 3 )
    mmio_irq_clear((int)aKeStateGetTask_14, (int)aMeSetActiveCfm_0, 341);
  if ( hci_cmd_send_short(7u) == 1 )
  {
    if ( **v0 < 0 && *((volatile uint32_t *)off_136618 + 1) )
      mmio_irq_clear((int)aCoListIsEmptyA, (int)aMeSetActiveCfm_0, 349);
    rf_core_enable();
  }
  else if ( hci_cmd_send_short(7u) == 3 )
  {
    hci_evt_alloc_send(7171, 13, 7);
    hci_cmd_send(7u, 0);
  }
  return 0;
}


// rf_load_cal_data @ 0x136628
int rf_load_cal_data(int a1, volatile uint8_t *a2, int a3, int a4) {
  int v7; // r4

  state_check_feature(256, aApStop);
  v7 = dword_136680 + 1320 * *a2;
  if ( *(volatile uint8_t *)(v7 + 106) == 2 && *(volatile uint8_t *)(v7 + 108) )
  {
    if ( hci_cmd_send_short(7u) )
    {
      return 2;
    }
    else
    {
      rf_path_config(v7);
      return 0;
    }
  }
  else
  {
    hci_evt_alloc_send(7171, a4, a3);
    return 0;
  }
}


