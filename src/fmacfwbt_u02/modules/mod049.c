// rf_calib_load @ 0x131734
int rf_calib_load(int a1, int a2, int16_t a3, int16_t a4) {
  memcpy((void *)(uintptr_t)(dword_131754), (void *)(uintptr_t)(a2), 254);
  hci_evt_alloc_send(5123, a4, a3);
  return 0;
}



// pdu_type_validate @ 0x131758
int pdu_type_validate(int a1, volatile uint8_t *a2) {
  sdio_cfg_write(*a2);
  return 0;
}



// rx_data_pdu_parse @ 0x131764
int rx_data_pdu_parse(int a1, volatile uint8_t *a2, int16_t a3, int16_t a4) {
  int v5; // r5
  int v6; // r8
  char v9; // r2
  int v10; // r3
  int v11; // r1
  int v12; // r3
  char v13; // r2
  int v14; // r0
  int v15; // r5
  char v16; // r3

  v5 = *a2;
  v6 = dword_13181C;
  if ( !a2[2] )
  {
    v12 = dword_13181C + 696 * v5;
    if ( a2[1] )
      v13 = *(volatile uint8_t *)(v12 + 53) | 1;
    else
      v13 = *(volatile uint8_t *)(v12 + 53) & 0xFE;
    *(volatile uint8_t *)(v12 + 53) = v13;
    goto LABEL_9;
  }
  if ( a2[1] )
    v9 = *(volatile uint8_t *)(dword_13181C + 696 * v5 + 53) | 4;
  else
    v9 = *(volatile uint8_t *)(dword_13181C + 696 * v5 + 53) & 0xFB;
  v10 = dword_13181C + 696 * v5;
  v11 = *(volatile uint8_t *)(v10 + 310);
  *(volatile uint8_t *)(v10 + 53) = v9;
  if ( v11 == 15 )
  {
LABEL_9:
    v14 = bt_buf_alloc(65, 0, 5, 4u);
    v15 = v6 + 696 * v5;
    v16 = *(volatile uint8_t *)(v15 + 34);
    *(volatile uint16_t *)v14 = *(volatile uint16_t *)(v15 + 32);
    *(volatile uint8_t *)(v14 + 3) = v16;
    *(volatile uint8_t *)(v14 + 2) = a2[1];
    hci_evt_send(v14);
  }
  hci_evt_alloc_send(5133, a4, a3);
  return 0;
}



// rx_pdu_process @ 0x131820
int rx_pdu_process(int a1, volatile uint8_t *a2, int16_t a3, int16_t a4) {
  int v4; // r0
  int v7; // r4
  int v8; // r1
  int v9; // r7
  volatile uint8_t *v10; // r0

  v4 = *a2;
  if ( a2[1] )
  {
    v7 = dword_131898 + 696 * v4;
    v8 = *(volatile uint8_t *)(v7 + 34);
    v9 = *(volatile uint8_t *)(dword_13189C + 1320 * v8 + 106);
    *(volatile uint8_t *)(v7 + 52) = 2;
    if ( !v9 && ((*((volatile uint32_t *)off_1318A0 + 1) >> v8) & 1) != 0 )
    {
      v10 = (volatile uint8_t *)bt_buf_alloc(5145, 5, 6, 2u);
      *v10 = 0;
      v10[1] = *(volatile uint8_t *)(v7 + 34);
      hci_evt_send((int)v10);
    }
  }
  else
  {
    *(volatile uint8_t *)(dword_131898 + 696 * v4 + 52) = 1;
  }
  hci_evt_alloc_send(5125, a4, a3);
  return 0;
}



// ke_evt_wait5 @ 0x1318a4
int ke_evt_wait5(int a1, volatile int *a2, int16_t a3, int16_t a4) {
  int v7; // r5
  int v8; // r4
  int v9; // r7
  int v10; // r4
  int v11; // r0
  int v12; // r1
  volatile uint8_t *v14; // r7
  int v15; // r0
  int16_t v16; // r1
  int v17; // r4
  int v18; // r1
  int v19; // r2

  if ( hci_cmd_send_short(5u) == 1 )
    return 2;
  v7 = bt_buf_alloc(5138, a4, a3, 0xCu);
  if ( **(volatile int16_t **)off_131988 < 0 )
  {
    v14 = (volatile uint8_t *)off_13198C;
    v8 = *((volatile uint8_t *)off_13198C + 16);
    if ( v8 == 255 )
    {
      mmio_irq_clear(dword_131998, dword_131994, 1092);
      v8 = v14[16];
    }
  }
  else
  {
    v8 = *((volatile uint8_t *)off_13198C + 16);
  }
  if ( rf_calibration_done() )
    rf_control_set_bit3(*((volatile uint8_t *)a2 + 11));
  v9 = dword_131990 + 1320 * v8;
  v10 = *(volatile uint32_t *)(v9 + 72);
  if ( v10 )
  {
    *(volatile uint8_t *)v7 = *(volatile uint8_t *)(v10 + 24);
    if ( *((volatile uint8_t *)a2 + 10) )
    {
      if ( list_length((volatile uint32_t **)dword_13199C) == 1 )
      {
        v15 = bt_buf_alloc(59, 0, 5, 0xCu);
        *(volatile uint8_t *)v15 = *(volatile uint8_t *)(*(volatile uint32_t *)(v9 + 72) + 24);
        v16 = *((volatile uint16_t *)a2 + 4);
        v17 = a2[1];
        *(volatile uint32_t *)(v15 + 2) = *a2;
        *(volatile uint16_t *)(v15 + 10) = v16;
        *(volatile uint32_t *)(v15 + 6) = v17;
        hci_evt_send(v15);
        v18 = *a2;
        v19 = a2[1];
        *(volatile uint16_t *)(v7 + 10) = *((volatile uint16_t *)a2 + 4);
        *(volatile uint32_t *)(v7 + 2) = v18;
        *(volatile uint32_t *)(v7 + 6) = v19;
        goto LABEL_9;
      }
      v10 = *(volatile uint32_t *)(v9 + 72);
    }
    v11 = *(volatile uint32_t *)(v10 + 4);
    v12 = *(volatile uint32_t *)(v10 + 8);
    *(volatile uint16_t *)(v7 + 10) = *(volatile uint16_t *)(v10 + 12);
    *(volatile uint32_t *)(v7 + 2) = v11;
    *(volatile uint32_t *)(v7 + 6) = v12;
LABEL_9:
    hci_evt_send(v7);
    return 0;
  }
  *(volatile uint8_t *)v7 = -1;
  hci_evt_send(v7);
  return 0;
}



// llc_conn_env_get_by_handle @ 0x1319a0
int llc_conn_env_get_by_handle(int a1, volatile uint8_t *a2) {
  int v3; // r5
  int v4; // r6
  char v5; // r3
  char v7; // r3

  v3 = *(volatile uint32_t *)(dword_131A34 + 696 * *a2 + 340);
  if ( **(volatile int16_t **)off_131A30 < 0 && !v3 )
    mmio_irq_clear(dword_131A3C, dword_131A38, 1031);
  v4 = *((volatile uint16_t *)a2 + 1);
  if ( v4 == 0xFFFF )
  {
    v5 = *(volatile uint8_t *)(v3 + 166);
    *(volatile uint16_t *)(v3 + 190) = -1;
    v5 &= 0xCFu;
    *(volatile uint8_t *)(v3 + 166) = v5;
    if ( (v5 & 0x80) == 0 )
      return 0;
    is_connection_active(*a2);
    *(volatile uint8_t *)(v3 + 166) &= ~0x80u;
    return 0;
  }
  else
  {
if ( !validate_channel_map((void *)(uintptr_t)(v3), *((volatile uint16_t *)a2 + 1)) ) return 0;
    v7 = *(volatile uint8_t *)(v3 + 166);
    *(volatile uint16_t *)(v3 + 190) = v4;
    *(volatile uint8_t *)(v3 + 166) = v7 & 0xCF | 0x10;
    return 0;
  }
}



