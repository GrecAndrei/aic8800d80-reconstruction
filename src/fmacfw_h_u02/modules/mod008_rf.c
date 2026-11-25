// rf_is_sleep @ 0x1134e0
/* luna: Returns the RF data pointer for an index, preparing the index-1 record in a scratch buffer and applying an optional patched value. */
volatile uint32_t * rf_is_sleep(int a1) {
  volatile uint32_t *result; // r0
  volatile uint32_t *v2; // r4
  int v3; // r0
  unsigned int v4; // r0

  switch ( a1 )
  {
    case 1:
      v2 = (void *)(uintptr_t)(off_113554);
      v3 = (int)(uintptr_t)(memcpy((void *)(uintptr_t)(off_113554), (void *)(uintptr_t)(dword_113558), 18));
      if ( *((volatile uint8_t *)off_11355C + 370) && call_patch_1fc_check(v3) )
      {
        v4 = call_patch_1fc_arg2();
        v2[2] = ((HIWORD(v4) << 16) + 0x10000) | (uint16_t)v4;
        return v2;
      }
      else if ( *(volatile uint16_t *)off_113560 == 0xFFFF || *((volatile uint16_t *)off_113560 + 1) == 0xFFFF )
      {
        return (void *)(uintptr_t)(off_113554);
      }
      else
      {
        result = (void *)(uintptr_t)(off_113554);
        v2[2] = *(volatile uint32_t *)off_113560;
      }
      break;
    case 6:
      return (volatile uint32_t *)dword_113550;
    case 15:
      return (volatile uint32_t *)dword_11354C;
    default:
      return 0;
  }
  return result;
}



// get_handler_by_index @ 0x113564
/* luna: Returns the handler-table entry at the given index, or zero when the index exceeds 7. */
int get_handler_by_index(unsigned int a1) {
  if ( a1 > 7 )
    return 0;
  else
    return *(volatile uint32_t *)(dword_113574 + 4 * a1);
}



// rf_get_flag @ 0x113578
/* luna: Obtains the RX buffer and checks its configured state, disabling global IRQ handling if the buffer is missing or the state persists through five retri */
void rf_get_flag(int a1, int a2, int a3, int a4) {
  volatile uint8_t *v4; // r5
  volatile uint16_t *v5; // r2
  int v6; // r0
  volatile uint32_t *v7; // r4
  volatile uint32_t *v8; // r8
  volatile int *v9; // r6
  int v10; // r1
  int v11; // r0
  int v12; // r0
  volatile uint8_t *v13; // r7
  int v14; // r9
  int v15; // r1
  int v16; // r0
  int v17; // r0
  volatile uint16_t *v18; // r3

  v4 = (void *)(uintptr_t)(off_1136A0);
  if ( *(volatile uint8_t *)off_1136A0 )
  {
    if ( !*(volatile uint16_t *)off_1136AC )
    {
      check_feature_flag(512, "#we\n");
      return;
    }
    if ( *(volatile uint8_t *)off_1136A8 >= (unsigned int)*(volatile uint16_t *)off_1136AC )
    {
      v18 = (volatile uint16_t *)off_1136B0;
      *(volatile uint8_t *)off_1136A4 = 1;
      check_feature_flag(512, "#wf:%X\n", *v18);
    }
  }
  else
  {
    if ( *(volatile uint8_t *)off_1136A4 )
      return;
    if ( *(volatile uint8_t *)off_1136A8 >= (unsigned int)*(volatile uint16_t *)off_1136AC && !*(volatile uint8_t *)off_1136A4 )
    {
      v5 = (volatile uint16_t *)off_1136B0;
      *(volatile uint8_t *)off_1136A4 = 1;
      check_feature_flag(512, "#wf:%X\n", *v5);
      return;
    }
  }
  v6 = (*(int ( **)(uint32_t))(*((volatile uint32_t *)off_1136B8 + 2) + 16))(*((volatile uint32_t *)off_1136B8 + 1));
  v7 = (volatile uint32_t *)v6;
  if ( v6 )
  {
    if ( *v4 )
    {
      v8 = (volatile uint32_t *)off_1136D0;
      v9 = (volatile int *)off_1136BC;
      v10 = *(volatile uint32_t *)off_1136BC;
      v11 = *(volatile uint32_t *)off_1136D0 + v6;
      if ( *(volatile uint8_t *)off_1136A4 )
        v12 = check_and_init_flag(v11, v10);
      else
        v12 = bt_get_state(v11, v10);
    }
    else
    {
      v8 = (volatile uint32_t *)off_1136D0;
      v9 = (volatile int *)off_1136BC;
      v12 = bt_get_state(*(volatile uint32_t *)off_1136D0 + v6, *(volatile uint32_t *)off_1136BC);
    }
    if ( v12 )
    {
      v13 = (void *)(uintptr_t)(off_1136A4);
      debug_printf("wd rx %d\r\n", v12);
      v14 = 5;
      while ( 1 )
      {
        if ( *v4 )
        {
          v15 = *v9;
          v16 = (int)v7 + *v8;
          v17 = *v13 ? check_and_init_flag(v16, v15) : bt_get_state(v16, v15);
        }
        else
        {
          v17 = bt_get_state((int)v7 + *v8, *v9);
        }
        if ( !v17 )
          break;
        if ( !--v14 )
        {
          debug_printf("wd rx max time %d\r\n", 5);
          wait_for_state(v7);
          irq_disable_global_2(32);
          return;
        }
      }
    }
  }
  else
  {
    irq_disable_global_2(32);
    debug_printf(aErrWdNoRxBuf);
  }
}


// rf_read_status_1 @ 0x1136d4
/* luna: Clears the USB WLAN RX packet free list and allocates and enqueues the configured number of packet buffers. */
volatile uint32_t *rf_read_status_1() {
  void *rx_config; // r7
  volatile uint32_t *result; // r0
  volatile int *v2; // r9
  volatile uint16_t *allocated_packet_count; // r6
  int v4; // r8
  volatile int16_t **v5; // r10
  int16_t packet_index; // r5
  unsigned int v7; // r1
  volatile uint32_t *rx_packet_buffer; // r4

  rx_config = (void *)(uintptr_t)(off_113750);
  result = clear_stats_buf((volatile uint32_t *)dword_113754);
  if ( *(volatile uint16_t *)(*(volatile uint32_t *)rx_config + 8) )
  {
    v2 = (volatile int *)off_113764;
    allocated_packet_count = (void *)(uintptr_t)(off_113758);
    v4 = dword_113768;
    v5 = (volatile int16_t **)off_113770;
    packet_index = 0;
    do
    {
      rx_packet_buffer = tx_irq_handler(v4, (uint16_t)(*((volatile uint16_t *)v2 + 153) - 4));
      if ( !rx_packet_buffer )
      {
        alloc_tx_event("usb_wlan_rx_pkt_free_list_init alloc fail: %d\n", packet_index);
        if ( **v5 < 0 )
          irq_disable_mmio_write(off_113760, (int)aUsbWlanRxPktFr_0, 495);
      }
      result = (volatile uint32_t *)wlan_ioctl_handler_1(dword_113754, rx_packet_buffer);
      v7 = *(volatile uint16_t *)(*(volatile uint32_t *)rx_config + 8);
      ++packet_index;
      ++*allocated_packet_count;
    }
    while ( v7 > packet_index );
  }
  return result;
}


// util_call_raw @ 0x1137c4
/* luna: Calls the WLAN handler with the supplied argument under nested IRQ protection, then performs RF recovery when the post-call threshold is reached. */
int util_call_raw(volatile uint32_t *a1) {
  volatile int *v2; // r4
  int v3; // r0
  volatile uint8_t *v4; // r1
  int result; // r0
  uint16_t v6; // r3
  int v7; // r3
  int v8; // r2
  int v9; // r3
  int v10; // r1
  int v11; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_113860 = 1;
  }
  v2 = (volatile int *)off_113864;
  v3 = dword_113868;
  ++*(volatile uint32_t *)off_113864;
  wlan_ioctl_handler_1(v3, a1);
  v4 = (void *)(uintptr_t)(off_113870);
  result = *(volatile uint8_t *)off_113870;
  v6 = *(volatile uint16_t *)off_11386C + 1;
  *(volatile uint16_t *)off_11386C = v6;
  if ( result && *(volatile uint8_t *)off_113874 <= (unsigned int)v6 )
  {
    v9 = *(volatile uint8_t *)off_113878;
    *v4 = 0;
    if ( v9 )
      *((volatile uint32_t *)off_11387C + 512) &= ~0x2000u;
    else
      *((volatile uint32_t *)off_11387C + 713) &= ~1u;
    wlan_wait_ready_alt(1);
    invalid_handler_12c5fc((int)(uintptr_t)((volatile char *)0x42D), 1);
    result = check_feature_flag(512, aWfr);
    if ( !*(volatile uint8_t *)off_113884 )
      rf_get_flag(result, v10, v11, *(volatile uint8_t *)off_113884);
  }
  if ( *v2 )
  {
    v7 = *v2 - 1;
    v8 = *(volatile uint32_t *)off_113860;
    *v2 = v7;
    if ( !v7 )
    {
      if ( v8 )
        __enable_irq();
    }
  }
  return result;
}


// rf_read_channel @ 0x113888
/* luna: Clears the shared statistics buffer, then processes one callback result for each configured sample. */
volatile uint32_t *rf_read_channel() {
  void *v0; // r5
  volatile uint32_t *result; // r0
  int v2; // r7
  int v3; // r6
  int v4; // r4
  volatile uint32_t *v5; // r0

  v0 = (void *)(uintptr_t)(off_1138BC);
  result = clear_stats_buf((volatile uint32_t *)dword_1138C0);
  if ( *(volatile uint16_t *)(*(volatile uint32_t *)v0 + 4) )
  {
    v2 = dword_1138C4;
    v3 = dword_1138C0;
    v4 = 0;
    do
    {
      v5 = tx_irq_handler(v2, 0x7Cu);
      result = (volatile uint32_t *)wlan_ioctl_handler_1(v3, v5);
      ++v4;
    }
    while ( *(volatile uint16_t *)(*(volatile uint32_t *)v0 + 4) > (unsigned int)(uint16_t)v4 );
  }
  return result;
}


// util_call_void @ 0x1138c8
/* luna: Pops and returns an item from the global list while maintaining a nest-aware interrupt critical section. */
int util_call_void() {
  volatile int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_1138FC = 1;
  }
  v0 = (volatile int *)off_113900;
  v1 = dword_113904;
  ++*(volatile uint32_t *)off_113900;
  result = (int)(uintptr_t)(list_pop(v1));
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(volatile uint32_t *)off_1138FC;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}



// util_call_arg @ 0x113908
/* luna: Calls the WLAN handler with the supplied argument and stored context inside a nesting-counted IRQ critical section. */
int util_call_arg(volatile uint32_t *a1) {
  volatile int *call_nesting_counter; // r4
  int handler_context; // r0
  int result; // r0
  int remaining_call_count; // r3
  int irq_disabled_by_wrapper; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_113940 = 1;
  }
  call_nesting_counter = (volatile int *)off_113944;
  handler_context = dword_113948;
  ++*(volatile uint32_t *)off_113944;
  result = wlan_ioctl_handler_1(handler_context, a1);
  if ( *call_nesting_counter )
  {
    remaining_call_count = *call_nesting_counter - 1;
    irq_disabled_by_wrapper = *(volatile uint32_t *)off_113940;
    *call_nesting_counter = remaining_call_count;
    if ( !remaining_call_count )
    {
      if ( irq_disabled_by_wrapper )
        __enable_irq();
    }
  }
  return result;
}


// rf_calibration_done @ 0x11394c
/* luna: Returns whether the RF calibration completion flag is set. */
BOOL rf_calibration_done() {
  return *((volatile uint8_t *)off_11395C + 8) == 1;
}



// init_bt_stack @ 0x113960
/* luna: Waits for Bluetooth readiness, then allocates the host USB start event. */
int init_bt_stack() {
  bt_wait_ready(off_113974);
  alloc_tx_event(aHostUsbStart);
  return 1;
}


// rf_save_regs @ 0x11397c
/* luna: Initializes the host-interface work buffers and applies the configured USB IN aggregation count, defaulting it to 10 when unset. */
int rf_save_regs(int a1) {
  void *v1; // r5
  volatile uint32_t *v2; // r1
  volatile int *v3; // r2
  volatile uint32_t *v4; // r3
  volatile uint16_t *v5; // r6
  volatile int *v6; // r0
  volatile uint32_t *v7; // r2
  volatile uint32_t *v8; // r3
  volatile uint32_t *v9; // r4
  volatile int *v10; // r3
  int v11; // r5
  int v12; // r0
  int v13; // r1
  volatile uint32_t *v14; // r6
  volatile int *v15; // r2
  volatile uint8_t *v16; // r4
  int v17; // r1
  volatile uint8_t *v18; // r5
  int v19; // cc
  char v20; // r0
  int v21; // r3

  v1 = (void *)(uintptr_t)(off_113A84);
  v2 = (void *)(uintptr_t)(off_113A8C);
  v3 = *(volatile int **)(*(volatile uint32_t *)off_113A84 + 16);
  v4 = (void *)(uintptr_t)(off_113A90);
  *(volatile uint32_t *)off_113A88 = (int)(uintptr_t)(v3);
  *v2 = (int)(uintptr_t)(v3 + 16);
  v5 = (void *)(uintptr_t)(off_113A94);
  v4[2] = a1;
  *v4 = 0;
  v4[1] = 0;
  v4[4] = 0;
  v4[5] = 0;
  v4[3] = 0;
  v5[6] = 0;
  memset(v3, 0, 0x140u);
  v6 = *(volatile int **)(*(volatile uint32_t *)v1 + 20);
  v7 = (void *)(uintptr_t)(off_113A9C);
  v8 = (void *)(uintptr_t)(off_113AA0);
  *(volatile uint32_t *)off_113A98 = (int)(uintptr_t)(v6);
  *v7 = (int)(uintptr_t)(v6 + 2);
  *v8 = (int)(uintptr_t)(v6 + 4);
  v8[1] = (int)(uintptr_t)(v6 + 6);
  v8[2] = (int)(uintptr_t)(v6 + 8);
  v8[3] = (int)(uintptr_t)(v6 + 10);
  v9 = (void *)(uintptr_t)(off_113AA4);
  v8[4] = (int)(uintptr_t)(v6 + 12);
  *v9 = (int)(uintptr_t)(v6 + 14);
  memset(v6, 0, 0xCB8u);
  if ( **(volatile int16_t **)off_113AA8 < 0 && *(volatile uint32_t *)(*(volatile uint32_t *)v1 + 24) <= 0xCB7u )
    irq_disable_mmio_write((int)aIndexHostIfPar, (int)aHostUsbWlanIni, 758);
  v10 = (volatile int *)off_113AAC;
  v11 = LOWORD(((volatile uint32_t *)(uintptr_t)off_113AAC)[82]);
  v12 = LOWORD(((volatile uint32_t *)(uintptr_t)off_113AAC)[77]);
  v13 = dword_113AB4;
  v14 = (void *)(uintptr_t)(off_113AB8);
  *(volatile uint32_t *)off_113ABC = HIWORD(((volatile uint32_t *)(uintptr_t)off_113AAC)[76]) - *(volatile uint32_t *)(uintptr_t)(off_113AB0) - 4;
  v15 = (volatile int *)off_113AC0;
  v16 = (void *)(uintptr_t)(off_113AC4);
  v17 = v13 * v11;
  v18 = (void *)(uintptr_t)(off_113AC8);
  *v14 = v12 - 4;
  v19 = v17 <= (int)v15;
  if ( v17 > (int)v15 )
    v17 = (int)off_113ACC;
  else
    v15 = (volatile int *)off_113ACC;
  *v18 = *((volatile uint8_t *)v10 + 320);
  v20 = *((volatile uint8_t *)v10 + 321);
  v21 = *((volatile uint8_t *)v10 + 368);
  *v16 = v20;
  if ( v19 )
    *v15 = v17;
  else
    *(volatile uint32_t *)v17 = (int)(uintptr_t)(v15);
  if ( v21 )
  {
    *(volatile uint8_t *)off_113AD0 = v21;
    alloc_tx_event("usb in agg cnt %d\n", v21);
  }
  else
  {
    *(volatile uint8_t *)off_113AD0 = 10;
    alloc_tx_event("usb in agg cnt %d\n", 10);
  }
  return 1;
}


// rf_load_calibration @ 0x113ae0
/* luna: Saves the RF register state, then copies two stored calibration bytes into RF configuration locations. */
int rf_load_calibration(int a1) {
  volatile uint8_t *v1; // r2
  char v2; // r3

  rf_save_regs(a1);
  v1 = (void *)(uintptr_t)(off_113B04);
  v2 = *((volatile uint8_t *)off_113AFC + 352);
  *(volatile uint8_t *)off_113B00 = *((volatile uint8_t *)off_113AFC + 326);
  *v1 = v2;
  return 1;
}



// adv_parse_report @ 0x113b08
/* luna: Validates an incoming Wi-Fi RX descriptor, copies it into an available host descriptor, updates per-peer/TID byte accounting, and dispatches it to the */
int adv_parse_report(int a1) {
  unsigned int peer_id; // r3
  int vif_id; // r7
  int v4; // r8
  unsigned int rx_queue_id; // r6
  volatile uint32_t *rx_descriptor; // r4
  int v7; // r1
  int16_t v8; // r3
  int16_t v9; // r2
  int v10; // r3
  unsigned int descriptor_peer_id; // r3
  unsigned int tid; // r2

  peer_id = *(volatile uint8_t *)(a1 + 25);
  vif_id = *(volatile uint8_t *)(a1 + 24);
  if ( peer_id <= 0x1F && !*(volatile uint8_t *)(dword_113C48 + 696 * peer_id + 37) )
  {
    alloc_tx_event(aPktDiscardSinc);
    return wait_for_state((volatile uint32_t *)(a1 - *(volatile uint32_t *)(uintptr_t)(off_113C54) - 4));
  }
  v4 = dword_113C6C;
  if ( (*(volatile uint16_t *)(a1 + 26) & 8) == 0 )
  {
    if ( *(volatile uint8_t *)(dword_113C6C + 1320 * vif_id + 108) )
    {
      rx_queue_id = *(volatile uint8_t *)(a1 + 22);
      if ( **(volatile int16_t **)off_113C4C < 0 && rx_queue_id > 4 )
        irq_disable_mmio_write((int)aAcNxTxqCnt_0, (int)aHandleUsbRx, 926);
      rx_descriptor = (void *)(uintptr_t)(rssi_compare());
      if ( rx_descriptor )
        goto LABEL_7;
LABEL_13:
      debug_printf(" host rx: dscr used = %d\r\n", *(volatile uint8_t *)(dword_113C50 + rx_queue_id));
      while ( 1 )
        ;
    }
    return wait_for_state((volatile uint32_t *)(a1 - *(volatile uint32_t *)(uintptr_t)(off_113C54) - 4));
  }
  rx_queue_id = 3;
  rx_descriptor = (void *)(uintptr_t)(rssi_compare());
  if ( !rx_descriptor )
    goto LABEL_13;
LABEL_7:
  v7 = rx_descriptor[19];
  v8 = *((volatile uint16_t *)rx_descriptor + 15) & 0xFFFE;
  ++*(volatile uint8_t *)(dword_113C50 + rx_queue_id);
  *((volatile uint16_t *)rx_descriptor + 15) = v8;
  rx_descriptor[17] = 0;
  *(volatile uint32_t *)(v7 + 4) = 0;
  *(volatile uint32_t *)(v7 + 72) = 0;
  rx_descriptor[11] = 0;
  memcpy((volatile char *)rx_descriptor + 4, (volatile char *)a1, 0x1Cu);
  v9 = *((volatile uint16_t *)rx_descriptor + 15);
  v10 = *(volatile uint32_t *)(uintptr_t)(off_113C54);
  *((volatile uint16_t *)rx_descriptor + 3) = 0;
  rx_descriptor[18] = a1 - v10 - 4;
  *((volatile uint8_t *)rx_descriptor + 66) = 0;
  rx_descriptor[9] = 0;
  rx_descriptor[21] = 0;
  *((volatile uint16_t *)rx_descriptor + 41) = 0;
  *((volatile uint16_t *)rx_descriptor + 15) = v9 & 0xFFFD;
  if ( (v9 & 8) != 0 )
    return wlan_ioctl_handler_1(v4 + 1320 * vif_id + 1312, rx_descriptor);
  descriptor_peer_id = *((volatile uint8_t *)rx_descriptor + 29);
  if ( descriptor_peer_id <= 0x1F )
  {
    tid = *((volatile uint8_t *)rx_descriptor + 27);
    if ( tid <= 8 )
      *(volatile uint32_t *)(dword_113C58 + 4 * (9 * descriptor_peer_id + tid + 2062)) += *((volatile uint16_t *)rx_descriptor + 2);
  }
  return wlan_ioctl_handler_1(v4 + 8 * (rx_queue_id + 165 * vif_id + 154), rx_descriptor);
}


// util_call_deep @ 0x113f18
/* luna: Runs the mask-128 IRQ operation inside a nesting-aware critical section and restores interrupts when the outermost call exits. */
int util_call_deep() {
  volatile int *v0; // r4
  int result; // r0
  int v2; // r3
  int v3; // r2

  dma_ring_alloc_2();
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_113F50 = 1;
  }
  v0 = (volatile int *)off_113F54;
  ++*(volatile uint32_t *)off_113F54;
  result = irq_disable_global_3(128);
  if ( *v0 )
  {
    v2 = *v0 - 1;
    v3 = *(volatile uint32_t *)off_113F50;
    *v0 = v2;
    if ( !v2 )
    {
      if ( v3 )
        __enable_irq();
    }
  }
  return result;
}



// util_init_buffer @ 0x113fc4
/* luna: Calls rf_get_flag only when the byte-sized global flag at 0x113FD0 is clear. */
void util_init_buffer() {
  if ( !*(volatile uint8_t *)off_113FD0 )
    ((int (*)())rf_get_flag)();
}



// invoke_callback @ 0x113fd4
/* luna: Retrieves a WLAN data buffer through a configured callback, checks its state, and waits for the state condition if the check fails. */
int invoke_callback() {
  int v0; // r0
  volatile uint32_t *v1; // r4
  int result; // r0

  v0 = (*(int ( **)(uint32_t))(*((volatile uint32_t *)off_114014 + 2) + 16))(*((volatile uint32_t *)off_114014 + 1));
  if ( !v0 )
    return debug_printf(aErrNoWlanDataB);
  v1 = (volatile uint32_t *)v0;
  result = bt_get_state(*(volatile uint32_t *)off_114018 + v0, *(volatile uint32_t *)off_11401C);
  if ( result < 0 )
  {
    wait_for_state(v1);
    return debug_printf(aWlanDataRecvRe);
  }
  return result;
}


// set_config_field @ 0x114028
/* luna: Allocates a host-ready transmit event, then invokes and returns the callback result. */
int set_config_field() {
  alloc_tx_event(aHostReady);
  return invoke_callback();
}


// check_global_value @ 0x114088
/* luna: Logs whether the supplied function name matches a recognized USB-transfer handler and schedules a configured delayed event when enabled. */
int check_global_value(int a1) {
  int result; // r0
  int v2; // r2

  if ( a1 == *(volatile uint32_t *)asc_153304 )
  {
    v2 = 0;
  }
  else
  {
    if ( (_UNKNOWN *)a1 != off_153308 )
    {
      result = alloc_tx_event("%s, func 0x%x unknown\n", (const volatile char *)a1, *(volatile uint32_t *)asc_153304);
      goto LABEL_4;
    }
    v2 = 1;
  }
  result = alloc_tx_event("%s, func is %s\n", aUsbTransErrorH, (&off_15330C)[v2]);
LABEL_4:
  if ( BYTE1(((volatile uint32_t *)(uintptr_t)off_1140E4)[88]) )
    return ke_event_handler(1068, 1, 1000 * BYTE2(((volatile uint32_t *)(uintptr_t)off_1140E4)[88]));
  return result;
}


// rf_power_down @ 0x1140f4
/* luna: Initializes two context buffers, then creates and submits one 0x6B8-byte record to the first buffer for each configured entry. */
volatile uint32_t *rf_power_down() {
  volatile int *v0; // r5
  void *v1; // r7
  volatile uint32_t *result; // r0
  int v3; // r6
  int v4; // r4
  volatile uint32_t *v5; // r0

  v0 = (volatile int *)off_11413C;
  v1 = (void *)(uintptr_t)(off_114140);
  clear_stats_buf((volatile uint32_t *)(((volatile uint32_t *)(uintptr_t)off_11413C)[0] + 628));
  result = clear_stats_buf((volatile uint32_t *)(*v0 + 636));
  if ( *(volatile uint16_t *)(*(volatile uint32_t *)v1 + 8) )
  {
    v3 = dword_114144;
    v4 = 0;
    do
    {
      v5 = tx_irq_handler(v3, 0x6B8u);
      result = (volatile uint32_t *)wlan_ioctl_handler_1(*v0 + 628, v5);
      ++v4;
    }
    while ( *(volatile uint16_t *)(*(volatile uint32_t *)v1 + 8) > (unsigned int)(uint16_t)v4 );
  }
  return result;
}


// assert_fail @ 0x11414c
/* luna: Waits for a shared readiness flag, calls the handler with the context at offset 628, and restores IRQs when the outermost guarded call exits. */
int assert_fail(volatile uint32_t *a1) {
  volatile int *v1; // r5
  volatile uint32_t *v2; // r4
  int result; // r0
  int v4; // r3
  int v5; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_114194 = 1;
  }
  v1 = (volatile int *)off_114198;
  v2 = (void *)(uintptr_t)(off_11419C);
  ++*(volatile uint32_t *)off_114198;
  while ( !*v2 )
    ;
  result = wlan_ioctl_handler_1(((volatile uint32_t *)(uintptr_t)off_1141A0)[0] + 628, a1);
  *v2 = 1;
  if ( *v1 )
  {
    v4 = *v1 - 1;
    v5 = *(volatile uint32_t *)off_114194;
    *v1 = v4;
    if ( !v4 )
    {
      if ( v5 )
        __enable_irq();
    }
  }
  return result;
}


// load_bt_config @ 0x1141a4
/* luna: Checks feature flag 256 using the host-IPC-start label, then returns 1. */
int load_bt_config() {
  check_feature_flag(256, aHostIpcStart);
  return 1;
}


// state_init @ 0x1141b8
/* luna: Stores the argument in an RF state slot, clears several associated state words and a halfword, and returns 1. */
int state_init(int a1) {
  volatile uint32_t *v1; // r2
  volatile uint16_t *v2; // r1

  v1 = (void *)(uintptr_t)(off_1141D0);
  v2 = (void *)(uintptr_t)(off_1141D4);
  *((volatile uint32_t *)off_1141D0 + 2) = a1;
  v1[3] = 0;
  v1[4] = 0;
  v1[5] = 0;
  *v1 = 0;
  v1[1] = 0;
  v2[6] = 0;
  return 1;
}



// get_config_a @ 0x114410
/* luna: Allocates and returns a transmit event associated with the error low-power-level key. */
int get_config_a() {
  return alloc_tx_event(aErrorLpLevelPo_1);
}


