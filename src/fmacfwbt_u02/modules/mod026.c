// wlc_phy_chanspec_set @ 0x120370
uint64_t wlc_phy_chanspec_set(volatile uint8_t *a1, char a2) {
  int v3; // r6
  int v4; // r8
  int v5; // r4
  volatile uint8_t *v6; // r7
  int v7; // r10
  volatile int *v8; // r9
  volatile int *v9; // r0
  int v10; // r2
  int v11; // r3
  uint64_t result; // r0
  uint64_t v13; // r2
  int v14; // r4
  int v15; // r0

  v3 = *a1;
  v4 = a1[41];
  v5 = dword_1204C0;
  v6 = (volatile uint8_t *)(1320 * v4 + 120 * v3 + dword_1204C0);
  v7 = 120 * v3 + 1320 * v4;
  v6[578] = a2;
  v6[576] = a1[40];
  v8 = (volatile int *)(v7 + 480 + v5);
  v6[577] = v3;
  v9 = memset(v8, 0, 0x48u);
  switch ( v6[576] )
  {
    case 0:
    case 3:
      *(volatile uint64_t *)(1320 * v4 + 120 * v3 + v5 + 552) = random(v9) & 0xFFFFFFLL;
      break;
    case 1:
      v15 = 1320 * v4 + 120 * v3 + v5;
      *(volatile uint32_t *)(v15 + 560) = *((volatile uint32_t *)a1 + 6);
      *(volatile uint32_t *)(v15 + 564) = *((volatile uint32_t *)a1 + 7);
      *(volatile uint32_t *)(v15 + 568) = *((volatile uint32_t *)a1 + 8);
      *(volatile uint32_t *)(v15 + 572) = *((volatile uint32_t *)a1 + 9);
      *(volatile uint64_t *)(v15 + 552) = 0;
      break;
    case 4:
      *(volatile uint64_t *)(1320 * v4 + 120 * v3 + v5 + 552) = *(volatile uint64_t *)&dword_1204B8;
      break;
    case 5:
      memcpy((void *)(uintptr_t)(v7 + 560 + v5), a1 + 8, 16);
      goto LABEL_3;
    default:
LABEL_3:
      *(volatile uint64_t *)(1320 * v4 + 120 * v3 + v5 + 552) = 0;
      break;
  }
  v10 = 1320 * v4 + 120 * v3 + v5;
  v11 = 1320 * v4 + v5;
  if ( *(volatile uint8_t *)(v10 + 576) == 5 )
    *(volatile uint32_t *)(v11 + 1204) = (int)(uintptr_t)(v8);
  else
    *(volatile uint32_t *)(v11 + 1200) = (int)(uintptr_t)(v8);
  *(volatile uint8_t *)(v10 + 579) = 1;
  result = *((volatile uint64_t *)a1 + 1);
  v13 = *((volatile uint64_t *)a1 + 2);
  v14 = v5 + 1320 * v4 + 120 * v3;
  *(volatile uint64_t *)(v14 + 580) = result;
  *(volatile uint64_t *)(v14 + 588) = v13;
  *(volatile uint8_t *)(v14 + 596) = a1[4];
  return result;
}



// dma_tx_reset @ 0x1204c4
int dma_tx_reset(int result, int a2) {
  int v2; // r4
  int v3; // r3
  int v4; // r1
  int v5; // r3
  int v6; // r3
  int v7; // r3

  v2 = *(volatile uint32_t *)(result + 1200);
  v3 = result + 120 * a2;
  v4 = v3 + 480;
  *(volatile uint8_t *)(v3 + 579) = 0;
  if ( v2 == v3 + 480 )
  {
    v5 = *(volatile uint8_t *)(result + 579);
    *(volatile uint32_t *)(result + 1200) = 0;
    v4 = result + 480;
    if ( v5
      || (v4 = result + 600, *(volatile uint8_t *)(result + 699))
      || (v4 = result + 720, *(volatile uint8_t *)(result + 819))
      || (v4 = result + 840, *(volatile uint8_t *)(result + 939)) )
    {
      *(volatile uint32_t *)(result + 1200) = v4;
      return result;
    }
  }
  if ( *(volatile uint32_t *)(result + 1204) == v4 )
  {
    v6 = *(volatile uint8_t *)(result + 1059);
    *(volatile uint32_t *)(result + 1204) = 0;
    if ( v6 )
    {
      v7 = result + 960;
    }
    else
    {
      if ( !*(volatile uint8_t *)(result + 1179) )
        return result;
      v7 = result + 1080;
    }
    *(volatile uint32_t *)(result + 1204) = v7;
  }
  return result;
}



// wlc_bsscfg_detach @ 0x12054c
int wlc_bsscfg_detach(int result) {
  volatile uint32_t *v1; // r4
  int v2; // r5

  v1 = *(volatile uint32_t **)(result + 240);
  if ( v1 )
  {
    v2 = result;
    do
    {
      result = wlc_bsscfg_down(v2, (int)v1, 0);
      v1 = (volatile uint32_t *)*v1;
    }
    while ( v1 );
  }
  return result;
}



// wlc_bmac_write_shm @ 0x120568
int wlc_bmac_write_shm(int a1) {
  return ke_event_lock((void *)(uintptr_t)(a1 + 48), *((volatile uint32_t *)off_120578 + 4) + 10000);
}



// si_watchdog @ 0x12057c
int si_watchdog(int result) {
  int v1; // r4

  if ( *(volatile uint8_t *)off_1205A4 && (*((volatile uint32_t *)off_1205A4 + 1) & 8) == 0 )
  {
    v1 = result;
    if ( !*(volatile uint32_t *)(result + 4) )
    {
      ke_event_set_lock(result + 48);
      return wlc_ucode_download(v1);
    }
  }
  return result;
}



// wlc_intr_off @ 0x1205a8
int wlc_intr_off(int result, unsigned int a2) {
  volatile uint32_t *v2; // r5
  volatile uint8_t *v3; // r3
  int v4; // r6
  unsigned int v5; // r2
  int v6; // r7
  unsigned int v7; // r4
  volatile int *i; // r3
  unsigned int v9; // r2
  volatile int *v10; // r3
  int v11; // r3

  *(volatile uint16_t *)(result + 222) = a2;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_120638 = 1;
  }
  v2 = (void *)(uintptr_t)(off_12063C);
  v3 = (void *)(uintptr_t)(off_120640);
  v4 = *(volatile uint32_t *)off_12063C;
  v5 = *((volatile uint8_t *)off_120640 + 18);
  v6 = *(volatile uint32_t *)off_12063C + 1;
  *(volatile uint32_t *)off_12063C = v6;
  if ( v5 <= 1 )
  {
    v3[20] = *(volatile uint8_t *)(result + 107);
    v7 = a2;
    *(volatile uint16_t *)(result + 224) = 257;
  }
  else
  {
    v7 = *(volatile uint16_t *)(dword_120644 + 1320 * (uint8_t)v3[20] + 222);
    if ( a2 < v7 )
    {
      v3[20] = *(volatile uint8_t *)(result + 107);
      v7 = a2;
    }
    for ( i = *((volatile int **)v3 + 2); i; i = (volatile int *)*i )
    {
      v9 = *((volatile uint16_t *)i + 111);
      *((volatile uint8_t *)i + 225) = 1;
      *((volatile uint8_t *)i + 224) = v9 / v7;
    }
  }
  *(volatile uint32_t *)off_120648 = (HIWORD(*(volatile uint32_t *)off_120648) << 16) | v7;
  if ( v6 )
  {
    v10 = (volatile int *)off_120638;
    *v2 = v4;
    v11 = *v10;
    if ( !v4 )
    {
      if ( v11 )
        __enable_irq();
    }
  }
  return result;
}



// alloc_buffer @ 0x12064c
int alloc_buffer(int a1) {
  volatile uint8_t *v2; // r5
  int v3; // r0
  int v4; // r1
  int v5; // r0
  char v6; // r1
  int v7; // r3
  int v8; // r7
  char v10[5]; // [sp+7h] [bp-5h] BYREF

  v2 = (volatile uint8_t *)bt_buf_alloc(88, 13, 0, 3);
  v3 = *(volatile uint8_t *)(a1 + 107);
  v10[0] = -1;
  get_entry_by_index(v3);
  v4 = *(volatile uint32_t *)(a1 + 1216);
  *(volatile uint32_t *)(a1 + 412) = *(volatile uint32_t *)(a1 + 1212);
  *(volatile uint32_t *)(a1 + 416) = v4;
  *(volatile uint16_t *)(a1 + 420) = *(volatile uint16_t *)(a1 + 1220);
  *(volatile uint8_t *)(a1 + 464) = 0;
  scan_rssi_compare(a1);
  v5 = find_free_conn((void *)(uintptr_t)(a1 + 1212), v10);
  v6 = v10[0];
  v2[1] = v5;
  v2[2] = v6;
  *v2 = *(volatile uint8_t *)(a1 + 107);
  v7 = *(volatile uint8_t *)(a1 + 106);
  if ( *(volatile uint8_t *)(a1 + 106) )
  {
    if ( v7 == 2 )
    {
      *(volatile uint8_t *)(a1 + 231) = 0;
      if ( !v5 )
      {
        update_entries_from_config(*(volatile uint8_t *)(a1 + 107), (uint8_t)v6);
        *((volatile uint8_t *)off_120728 + 9) = 1;
      }
    }
    return (int)(uintptr_t)(hci_evt_send((int)(uintptr_t)(v2)));
  }
  *(volatile uint8_t *)(a1 + 146) = v7;
  if ( !v5 )
  {
    v8 = *(volatile uint8_t *)(a1 + 116);
    update_entries_from_config(*(volatile uint8_t *)(a1 + 107), (uint8_t)v6);
    ke_event_set_lock(a1 + 48);
    ke_event_lock((void *)(uintptr_t)(a1 + 24), *((volatile uint32_t *)off_120724 + 4) + *(volatile uint32_t *)(dword_120720 + 696 * v8 + 8));
    *(volatile uint8_t *)(a1 + 128) = 0;
    *(volatile uint8_t *)(a1 + 147) = 1;
    return (int)(uintptr_t)(hci_evt_send((int)(uintptr_t)(v2)));
  }
  mmio_read_phy(a1);
  return (int)(uintptr_t)(hci_evt_send((int)(uintptr_t)(v2)));
}



// check_event_state_1 @ 0x12072c
int check_event_state_1() {
  int result; // r0

  if ( *((volatile uint8_t *)off_12074C + 18) + *((volatile uint8_t *)off_12074C + 17) != 1 )
    return 0;
  result = *((volatile uint32_t *)off_12074C + 2);
  if ( *(volatile uint8_t *)(result + 106) )
    return 0;
  return result;
}



// clear_intr_status @ 0x120750
void clear_intr_status() {
  int v0; // r3

  v0 = *((volatile uint8_t *)off_120768 + 18) + *((volatile uint8_t *)off_120768 + 17);
  *(volatile uint32_t *)off_12076C = 0;
  if ( v0 <= 1 )
    si_secure_check();
}



// reset_event_flag @ 0x120770
int reset_event_flag(volatile uint8_t *a1) {
  volatile uint32_t *v1; // r3
  volatile int *v2; // r3
  int result; // r0

  v1 = (void *)(uintptr_t)(off_1207C0);
  *a1 = 0;
  v2 = (volatile int *)v1[2];
  if ( v2 )
  {
    result = 0;
    while ( 1 )
    {
      if ( *((volatile uint8_t *)v2 + 106) )
      {
        if ( *((volatile uint8_t *)v2 + 108) && *((volatile uint8_t *)v2 + 1224) )
          goto LABEL_10;
LABEL_6:
        v2 = (volatile int *)*v2;
        if ( !v2 )
          return result;
      }
      else
      {
        if ( !*((volatile uint8_t *)v2 + 108) )
          goto LABEL_6;
        if ( !*((volatile uint8_t *)v2 + 1224) )
        {
          ++result;
          goto LABEL_6;
        }
LABEL_10:
        *a1 = 1;
        v2 = (volatile int *)*v2;
        if ( !v2 )
          return result;
      }
    }
  }
  return 0;
}



// register_irq_handler @ 0x1207c4
int register_irq_handler(int a1) {
  volatile uint32_t *v2; // r0

  v2 = (volatile uint32_t *)bt_buf_alloc(143, 0, 255, 4);
  *v2 = a1;
  return (int)(uintptr_t)(hci_evt_send((int)(uintptr_t)(v2)));
}



// wait_rf_calibration @ 0x1207e0
int wait_rf_calibration() {
  int result; // r0
  volatile uint32_t *v1; // r1
  volatile uint16_t *v2; // r3
  unsigned int v3; // r2
  int16_t v4; // r2
  volatile uint32_t *v5; // r1
  int16_t v6; // r2
  volatile uint32_t *v7; // r1
  int16_t v8; // r2

  if ( (uint16_t)(*(volatile uint32_t *)off_12086C >> 12) && (uint16_t)(*(volatile uint32_t *)off_12086C >> 12) <= 0x96u )
    result = (uint16_t)(*(volatile uint32_t *)off_12086C >> 12);
  else
    result = 150;
  v1 = (void *)(uintptr_t)(off_120870);
  v2 = (void *)(uintptr_t)(off_120874);
  v3 = *(volatile uint32_t *)off_120870;
  *((volatile uint16_t *)off_120874 + 4) = result;
  if ( (uint16_t)(v3 >> 12) && (uint16_t)(*v1 >> 12) <= 0x96u )
    v4 = *v1 >> 12;
  else
    v4 = 150;
  v5 = (void *)(uintptr_t)(off_120878);
  v2[5] = v4;
  if ( (uint16_t)(*v5 >> 12) && (uint16_t)(*v5 >> 12) <= 0x96u )
    v6 = *v5 >> 12;
  else
    v6 = 150;
  v7 = (void *)(uintptr_t)(off_12087C);
  v2[6] = v6;
  if ( (uint16_t)(*v7 >> 12) && (uint16_t)(*v7 >> 12) <= 0x96u )
  {
    v8 = *v7 >> 12;
    v2[7] = v8;
    v2[8] = v8;
  }
  else
  {
    v2[7] = 150;
    v2[8] = 150;
  }
  return result;
}



// init_ctx_struct @ 0x120880
int init_ctx_struct() {
  volatile uint8_t *v0; // r4
  int v1; // r3
  volatile int16_t *v2; // r1
  int v3; // r1
  int result; // r0

  v0 = (void *)(uintptr_t)(off_1208D4);
  memset((volatile int *)off_1208D4, 0, 0x34u);
  v1 = dword_1208DC;
  v2 = *(volatile int16_t **)off_1208D8;
  *(volatile uint32_t *)v0 = dword_1208DC;
  v0[31] = 1;
  *((volatile uint16_t *)v0 + 9) = 0;
  v3 = *v2;
  *((volatile uint32_t *)v0 + 1) = 0;
  if ( v3 < 0 && *(volatile uint32_t *)off_1208E8 << 28 )
  {
    mmio_field_update(dword_1208F0, dword_1208EC, 472);
    v1 = *(volatile uint32_t *)v0 | *((volatile uint32_t *)v0 + 1);
  }
  *(volatile uint32_t *)off_1208E0 = v1;
  result = wait_rf_calibration();
  *((volatile uint32_t *)v0 + 9) = dword_1208E4;
  return result;
}



// hal_phy_init @ 0x1208f4
volatile uint32_t *hal_phy_init() {
  volatile int *v0; // r4
  volatile int *v1; // r5
  volatile int *v2; // r6
  int v3; // r0
  int v4; // r0
  volatile uint32_t *v5; // r0
  volatile unsigned int *v6; // r1
  volatile unsigned int *v7; // r3
  int v8; // r4
  int v9; // r3
  char v10; // r2
  int v11; // zf
  int v12; // r2
  unsigned int v13; // r2
  volatile uint32_t *v14; // r2
  volatile uint32_t *v15; // r6
  volatile uint32_t *v16; // r5
  volatile uint32_t *v17; // r4
  volatile uint32_t *result; // r0
  volatile uint8_t **v19; // r1
  int v20; // r3

  v0 = (volatile int *)off_120A10;
  v1 = (volatile int *)off_120A14;
  v2 = (volatile int *)off_120A18;
  v3 = nullsub_1();
  v4 = ((int (*)())nullsub_2)(v3);
  ((int (*)())nullsub_3)(v4);
  v5 = (void *)(uintptr_t)(off_120A1C);
  v6 = (volatile unsigned int *)off_120A20;
  v7 = (volatile unsigned int *)off_120A24;
  *v0 = *v0 & 0x3FFFFF | 0x2800000;
  v8 = dword_120A28;
  *v5 |= 0x8000000u;
  *v6 = *v6 & 0xFF0FFFFF | 0x200000;
  *v7 = *v7 & 0xFFFFF8FF | 0x600;
  *v7 = *v7 & 0xFFFFC7FF | 0x2000;
  *v7 = *v7 & 0xFFFE3FFF | 0xC000;
  *v7 |= 0xE0000u;
  *v1 = *v1 & v8 | 0x5DC;
  v5[1] = v5[1] & v8 | 0xBB8;
  *(v6 - 205) = *(v6 - 205) & 0xFFFF00FF | 0xDA00;
  v9 = *v2;
  v10 = *(volatile uint8_t *)(*v2 + 2);
  if ( (v10 & 0x10) != 0 )
    v5[16] &= ~0x80000000;
  else
    *(volatile uint32_t *)off_120A54 |= 0x80000000;
  v11 = (v10 & 1) == 0;
  v12 = *(volatile uint32_t *)off_120A2C;
  if ( v11 )
    v13 = v12 & 0xFFFBFFFF;
  else
    v13 = v12 | 0x40000;
  *(volatile uint32_t *)off_120A2C = v13;
  v14 = (void *)(uintptr_t)(off_120A30);
  *(volatile uint32_t *)off_120A30 = dword_120A34;
  if ( *(volatile uint8_t *)(v9 + 1) )
    *(v14 - 215) |= 0x40u;
  v15 = (void *)(uintptr_t)(off_120A3C);
  v16 = (void *)(uintptr_t)(off_120A40);
  v17 = (void *)(uintptr_t)(off_120A44);
  result = (void *)(uintptr_t)(off_120A48);
  v19 = (volatile uint8_t **)off_120A4C;
  *(volatile uint32_t *)off_120A38 &= ~1u;
  *v15 = 0xFFFF;
  *v16 = -1;
  *v17 = 0xFFFF;
  *result = -1;
  v20 = **v19;
  if ( (unsigned int)(v20 - 1) <= 1 || v20 == 4 )
    *(volatile uint32_t *)off_120A50 |= 0x80000000;
  return result;
}



// run_deferred_init @ 0x120a58
volatile uint32_t *run_deferred_init() {
  volatile uint8_t *v0; // r4
  volatile int *v1; // r0
  int inited; // r0
  int v3; // r0
  int v4; // r0
  int v5; // r0
  int v6; // r0
  int v7; // r0
  int v8; // r0
  int v9; // r0

  v0 = (void *)(uintptr_t)(off_120AB0);
  if ( !*((volatile uint8_t *)off_120AB0 + 2) )
    mmio_poll_status();
  init_ctx_struct();
  si_attach();
  v1 = (void *)(uintptr_t)(wlc_attach());
  inited = (int)(uintptr_t)(tx_slot_state_init(v1));
  v3 = mm_state_idle(inited);
  hw_init_1(v3);
  v4 = bt_init();
  if ( v0[2] )
    v5 = ((int (*)())nullsub_4)(v4);
  else
    v5 = is_tx_ready();
  v6 = env_list_init_1903c8(v5);
  v7 = bt_reset_controller(v6);
  v8 = bt_init(v7);
  v9 = rx_env_list_init(v8);
  reset_bt_env(v9);
  check_hw_flag();
  return hal_phy_init();
}



// bt_coex_control @ 0x120ab4
volatile int * bt_coex_control(volatile int *result, int a2, int a3) {
  volatile int *v3; // r3
  volatile unsigned int *v4; // r3
  volatile unsigned int *v5; // r3
  volatile unsigned int *v6; // r3

  if ( !a2 )
  {
    v3 = *((volatile int **)off_120B70 + 2);
    if ( !v3 )
    {
      if ( a3 )
        goto LABEL_13;
      goto LABEL_4;
    }
    while ( 1 )
    {
      while ( result == v3 || !*((volatile uint8_t *)v3 + 108) )
      {
LABEL_7:
        v3 = (volatile int *)*v3;
        if ( !v3 )
          goto LABEL_12;
      }
      if ( *((volatile uint8_t *)v3 + 413) == 2 )
      {
        if ( *((volatile uint8_t *)v3 + 106) == 2 )
          break;
        a2 = 1;
        goto LABEL_7;
      }
      v3 = (volatile int *)*v3;
      if ( !v3 )
      {
LABEL_12:
        if ( a2 | a3 )
        {
LABEL_13:
          v5 = (volatile unsigned int *)off_120B74;
          *(volatile uint32_t *)off_120B74 = *(volatile uint32_t *)off_120B74 & 0xFFFFFF00 | 0x68;
          *v5 = *v5 & 0xFFFF00FF | 0x7800;
          *v5 = *v5 & 0xFF00FFFF | 0x780000;
          return result;
        }
LABEL_4:
        v4 = (volatile unsigned int *)off_120B74;
        *(volatile uint32_t *)off_120B74 = *(volatile uint32_t *)off_120B74 & 0xFFFFFF00 | 0x80;
        *v4 = *v4 & 0xFFFF00FF | 0x8000;
        *v4 = *v4 & 0xFF00FFFF | 0x800000;
        return result;
      }
    }
  }
  v6 = (volatile unsigned int *)off_120B74;
  *(volatile uint32_t *)off_120B74 = *(volatile uint32_t *)off_120B74 & 0xFFFFFF00 | 0x60;
  *v6 = *v6 & 0xFFFF00FF | 0x6000;
  *v6 = *v6 & 0xFF00FFFF | 0x600000;
  return result;
}



// tx_prepare_descriptor @ 0x120b78
int tx_prepare_descriptor(int a1, int a2, int a3, int a4, int a5, int a6) {
  unsigned int v8; // r9
  int v9; // r3
  unsigned int v10; // r7
  unsigned int v11; // r11
  int v12; // r10
  int v13; // r5
  volatile char *v14; // r2
  volatile int *v15; // r8
  volatile int *v16; // r0
  volatile uint32_t *v17; // r2
  volatile int16_t **v18; // r3
  int v19; // r5
  volatile char *v20; // r1
  volatile int *v21; // r0
  volatile uint32_t *v22; // r1
  int v23; // r6
  int v24; // r5
  int v25; // r2
  uint64_t v26; // kr08_8
  uint64_t v27; // r0
  int v28; // r3
  uint64_t v29; // r0
  int v30; // r2
  int v31; // r1
  volatile unsigned int v32; // r5
  int v33; // r5
  signed int v34; // r0
  int v35; // r3
  int v36; // r1
  volatile unsigned int v37; // r3
  int v38; // r0
  volatile unsigned int v39; // r3
  int result; // r0
  volatile uint8_t *v41; // r3
  volatile uint32_t *v42; // r2
  volatile uint8_t *v43; // r5
  int v44; // r1
  volatile uint8_t *v45; // r1
  volatile uint32_t *v46; // r2
  uint64_t v47; // [sp+8h] [bp-1Ch]
  int v48; // [sp+10h] [bp-14h]
  unsigned int v49; // [sp+14h] [bp-10h]
  int v51; // [sp+1Ch] [bp-8h]

  v8 = *(volatile uint32_t *)(a3 + 32);
  v9 = *(volatile uint16_t *)(a1 + 32);
  v49 = *(volatile uint32_t *)(a3 + 36);
  v10 = *(volatile uint32_t *)(a1 + 24);
  v11 = *(volatile uint32_t *)(a1 + 28);
  v12 = v9 << 10;
  if ( !*(volatile uint8_t *)(a4 + 106) && (v13 = *(volatile uint16_t *)(a4 + 112), *(volatile uint16_t *)(a4 + 112)) )
  {
    mac_duration_calc(*(volatile uint8_t *)(a4 + 107), v9, (uint8_t)v13);
    v51 = v12 * v13;
  }
  else if ( a6 )
  {
    v13 = *(volatile uint8_t *)(a6 + 2);
    if ( !*(volatile uint8_t *)(a6 + 2) )
    {
      v13 = *(volatile uint8_t *)(a6 + 3);
      mac_duration_calc(*(volatile uint8_t *)(a4 + 107), v9, v13);
    }
    v51 = v12 * v13;
  }
  else
  {
    v51 = v9 << 10;
    v13 = 1;
  }
  v48 = v13 * *(volatile uint16_t *)(a5 + 30);
  if ( *(volatile uint8_t *)(a3 + 40) << 28 )
  {
    v23 = 500;
    v24 = 0;
  }
  else
  {
    v14 = (volatile char *)off_120E8C;
    v15 = (volatile int *)off_120EDC;
    v16 = (volatile int *)off_120E90;
    *(volatile uint32_t *)off_120E8C = *((volatile uint8_t *)off_120EDC + (*(volatile uint8_t *)(a3 + 44) >> 4)) & 0x7F
                          | *(volatile uint32_t *)off_120E8C & 0xFFFFFF80;
    v17 = (void *)(v14 + 8);
    *v16 = a2 | (*(volatile uint8_t *)(a3 + 40) >> 7 << 20);
    *v17 = 0x80000000;
    __dsb(0xFu);
    while ( (*v17 & 0xC0000000) != 0x40000000 )
      ;
    v18 = (volatile int16_t **)off_120E94;
    if ( **(volatile int16_t **)off_120E94 >= 0 || (*v17 & 0x40000000) != 0 )
    {
      v19 = (uint16_t)*(volatile uint32_t *)off_120E98;
    }
    else
    {
      ke_int_lock_1((int)aNxmacTimeOnAir, (int)aHalMachwRxBcnD, 430);
      v19 = 500;
      v18 = (volatile int16_t **)off_120E94;
    }
    if ( !(*(volatile uint8_t *)(a3 + 40) << 28) )
    {
      v20 = (volatile char *)off_120E8C;
      v21 = (volatile int *)off_120E90;
      *(volatile uint32_t *)off_120E8C = *((volatile uint8_t *)v15 + (*(volatile uint8_t *)(a3 + 44) >> 4)) & 0x7F
                            | *(volatile uint32_t *)off_120E8C & 0xFFFFFF80;
      v22 = (void *)(v20 + 8);
      *v21 = (*(volatile uint8_t *)(a3 + 40) >> 7 << 20) | 0x18;
      *v22 = 0x80000000;
      __dsb(0xFu);
      while ( (*v22 & 0xC0000000) != 0x40000000 )
        ;
      if ( **v18 >= 0 || (*v22 & 0x40000000) != 0 )
      {
        v23 = (uint16_t)*(volatile uint32_t *)off_120E98;
        v24 = v19 - v23;
        goto LABEL_15;
      }
      ke_int_lock_1((int)aNxmacTimeOnAir, (int)aHalMachwRxBcnD, 430);
    }
    v24 = v19 - 500;
    v23 = 500;
  }
LABEL_15:
  v25 = *(volatile uint8_t *)(a4 + 106);
  v26 = __PAIR64__(v11, v10) - __PAIR64__(v49, v8) + (unsigned int)v24;
  *(volatile uint64_t *)(a4 + 40) = v26;
  if ( !v25 )
  {
    *(volatile uint32_t *)(a4 + 132) = v26;
    *(volatile uint32_t *)(a4 + 136) = v48 + 400;
  }
  v27 = double_is_nan(__PAIR64__(v11, v10), v12);
  v47 = __PAIR64__(v11, v10) - (unsigned int)v23;
  v28 = v27 * (v12 >> 31) + v12 * HIDWORD(v27);
  v29 = (unsigned int)v27 * (uint64_t)(unsigned int)v12;
  v29 = (v29 & 0xFFFFFFFFull) | ((uint64_t)(uint32_t)(((uint32_t)(v29 >> 32) & 0xFFFFFFFFu) + (uint32_t)(v28))) << 32;;
  if ( v29 < v47 )
    v47 = v29;
  v30 = v47 + v51;
  if ( (*(volatile uint32_t *)off_120E9C & 0x2000000) != 0 )
    v31 = dword_120EAC - v48 - v26 + v30;
  else
    v31 = v30 - v48 - 400;
  v32 = (*(volatile uint32_t *)0x40501010u);
  v33 = v32 - *(volatile uint32_t *)off_120EA4 + v31;
  v34 = v33 - (*(volatile uint32_t *)0x40501010u) - 4300 - return_1000();
  if ( v34 < 0 )
    v33 += v12;
  if ( (*(volatile uint32_t *)(a4 + 4) & 1) != 0 )
  {
    v35 = *(volatile uint8_t *)(a4 + 85);
    v36 = v35 << 30;
    if ( (v35 & 2) != 0 )
    {
      v37 = (*(volatile uint32_t *)0x40501010u);
      if ( (int)(v33 - v37 - 10000) < 0 )
      {
        v33 += v12;
        ke_event_schedule_1(aMoveTbtt, v36);
      }
    }
  }
  v38 = return_1000();
  v39 = (*(volatile uint32_t *)0x40501010u);
  result = v33 - v39 - 4300 - v38;
  if ( result >= 0 && *(volatile uint32_t *)(a4 + 36) != v33 )
  {
    v41 = (void *)(uintptr_t)(off_120EA8);
if ( *((volatile uint32_t *)off_120EA8 + 8) != a4 || (v42 = (void *)(uintptr_t)(off_120E9C), *(volatile uint32_t *)(a4 + 36) = v33, (*v42 & 0x2000000) != 0) ) { ke_event_lock((volatile uint32_t *)(a4 + 24), v33);
    }
    else
    {
      v43 = (volatile uint8_t *)off_120EBC;
      v44 = (uint8_t)v41[36];
      *(volatile uint8_t *)off_120EBC = BYTE2(*(volatile uint32_t *)off_120EB8);
      if ( !v44 )
      {
        v45 = *(volatile uint8_t **)off_120EC4;
        v43[1] = *(volatile uint32_t *)off_120EC0;
        v41[36] = 1;
        if ( *v45 == 1 )
        {
          v46 = (void *)(uintptr_t)(off_120ECC);
          *(volatile uint32_t *)off_120EC8 = 1;
          *v46 |= 1u;
        }
        if ( *v43 >= (unsigned int)v43[1] )
          ke_event_schedule_1(
            "dtim:%d,%d,%d,%d\r\n",
            *v43,
            v43[1],
            HIWORD(*(volatile uint32_t *)off_120F00),
            (uint8_t)*(volatile uint32_t *)off_120EFC);
        if ( **(volatile int16_t **)off_120E94 < 0 && *v43 >= (unsigned int)v43[1] )
          mmio_irq_clear((int)aVolatileUint8T, (int)aMmTbttCompute, 523);
      }
    }
    return hci_event_proc(a4);
  }
  return result;
}


// rx_ring_init @ 0x120f08
int rx_ring_init() {
  unsigned int v0; // r10
  int v1; // r8
  int result; // r0
  unsigned int v3; // r4
  int v4; // r1
  volatile uint32_t *v5; // r7
  volatile uint32_t *v6; // r5
  volatile uint32_t *v7; // r9
  int v8; // r3
  volatile unsigned int v9; // r2
  int v10; // r1
  int v11; // r1
  unsigned int v12; // r3
  int v13; // r6
  unsigned int v14; // r5
  unsigned int v15; // r6
  int v16; // r1
  int v17; // r3
  volatile unsigned int v18; // r2
  char v19; // r5
  volatile uint8_t **v20; // r7
  volatile uint8_t *v21; // r1
  volatile uint32_t *v22; // r3
  int v23; // r3
  volatile int16_t **v24; // r1
  int v25; // r3
  int v26; // r2
  int v27; // r3
  int v28; // r1
  char v29; // r1
  volatile unsigned int v30; // r3
  volatile uint32_t *v31; // r2
  volatile uint32_t *v32; // r7
  volatile uint32_t *v33; // r1
  unsigned int v34; // r3
  volatile uint32_t *v35; // r9
  volatile uint32_t *v36; // r5
  int v37; // r2
  volatile unsigned int v38; // r6
  int v39; // r2
  unsigned int v40; // r3
  volatile uint32_t *v41; // r6
  volatile unsigned int v42; // r3
  int v43; // r3
  int v44; // r2
  volatile uint32_t *v45; // r2
  volatile unsigned int v46; // r8
  unsigned int v47; // r1
  int v48; // r5
  uint64_t v49; // [sp+0h] [bp-Ch]
  int v50; // [sp+0h] [bp-Ch]
  int v51; // [sp+0h] [bp-Ch]

  v0 = dword_12128C;
  v1 = *(volatile uint32_t *)(dword_12128C + 0x20);
  result = set_system_flag_2(0x40000);
  if ( v1 )
  {
    v3 = dword_121214;
    v4 = *(volatile uint8_t *)(dword_121214 + 0x1E);
LABEL_3:
    v5 = (volatile uint32_t *)dword_121218;
    v6 = (volatile uint32_t *)dword_12121C;
    v7 = (volatile uint32_t *)dword_121294;
    while ( 1 )
    {
      if ( !v4 )
        return result;
      if ( (v4 & 8) != 0 )
      {
        v8 = *(volatile uint32_t *)dword_121220;
        *(volatile uint32_t *)dword_121224 = 0x80000000;
        v9 = (*(volatile uint32_t *)0x40501010u);
        if ( (int)(*(volatile uint32_t *)(v8 + 4) + *(volatile uint32_t *)(v1 + 120) - v9) < 0
          && !ble_conn_get(*(volatile uint8_t *)(v1 + 116), 0, 0) )
        {
          v30 = (*(volatile uint32_t *)0x40501010u);
          *(volatile uint32_t *)(v1 + 120) = v30;
        }
        v4 = *(volatile uint8_t *)(v3 + 0x1E) & 0xF7;
        *(volatile uint8_t *)(v3 + 0x1E) = v4;
      }
      if ( (v4 & 4) != 0 )
      {
        state_check_feature(2, (const volatile char *)dword_12124C);
        v24 = (volatile int16_t **)dword_121230;
        v25 = *(volatile uint32_t *)(v3 + 4);
        *v5 &= ~4u;
        v26 = **v24;
        v27 = v25 | 0x200;
        *(volatile uint32_t *)(v3 + 4) = v27;
        if ( v26 < 0 && *(volatile uint32_t *)dword_12125C << 28 )
        {
          mmio_field_update((int)aNxmacCurrentSt, (int)aMmRxFilterSet_1, 472);
          v27 = *(volatile uint32_t *)(v3 + 4);
        }
        v28 = off_121250;
        *(volatile uint32_t *)dword_121254 = v27 | *(volatile uint32_t *)v3;
        bt_get_conn_entry(*(volatile uint8_t *)(v1 + 107), v28, v1);
        v29 = *(volatile uint8_t *)(v3 + 0x1E);
        *v6 &= 0xFC0FFFFF;
        v4 = v29 & 0xFB;
        *v7 |= 0x400000u;
        *(volatile uint8_t *)(v3 + 0x1E) = v4;
      }
      if ( (v4 & 2) != 0 )
      {
        *(volatile uint32_t *)(v1 + 4) &= ~2u;
        if ( *(volatile uint8_t *)(v0 + 0x1D) == 5 )
        {
          ke_event_set_lock((int)(uintptr_t)((volatile uint32_t *)dword_12126C));
          v4 = (v4 & ~0xFFu) | ((uint8_t)(*(volatile uint8_t *)(v3 + 0x1E)) & 0xFFu);
          *(volatile uint8_t *)(v0 + 0x1D) = 0;
        }
        v4 &= 0xFDu;
        *(volatile uint8_t *)(v3 + 0x1E) = v4;
      }
      result = v4 << 31;
      if ( (v4 & 1) != 0 )
        break;
LABEL_20:
      if ( (v4 & 0x20) != 0 )
      {
        v14 = *(volatile uint32_t *)dword_121238;
        v15 = (*(volatile uint32_t *)dword_121238 >> 5) & 3;
        state_check_feature(2, "BCN:%d[%d]\r\n", v15, HIWORD(*(volatile uint32_t *)(dword_121238 - 12)) & 0x7FFF);
        v16 = *(volatile uint32_t *)(v1 + 120);
        v17 = *(volatile uint32_t *)(*(volatile uint32_t *)dword_121220 + 4);
        *(volatile uint8_t *)(v1 + 128) = 0;
        v18 = (*(volatile uint32_t *)0x40501010u);
        v19 = v14 >> 5;
        if ( (int)(v17 + v16 - v18) < 0 )
        {
          *(volatile uint8_t *)(v3 + 0x1E) |= 8u;
          state_check_feature(2, aNull);
        }
        if ( v15 )
        {
          while ( (*(volatile uint32_t *)dword_121238 & 8) == 0 )
            ;
          v32 = (volatile uint32_t *)dword_121238;
          *(volatile uint32_t *)dword_121238 &= ~8u;
          if ( (*v32 & 0x10) != 0 )
          {
            state_check_feature(2, aFcsOk);
            *(volatile uint8_t *)dword_121240 = BYTE2(*(volatile uint32_t *)dword_121284);
            rf_rx_packet_get(v15 >> 1, v19 & 1, v1);
            *v32 &= ~0x10u;
          }
          else
          {
            *(volatile uint32_t *)dword_1213B0 = 1;
            state_check_feature(2, aFcsNotOk);
            v33 = (volatile uint32_t *)dword_1213BC;
            *(volatile uint8_t *)dword_1213B8 = *(volatile uint8_t *)(dword_1213B8 + 1) > 1u;
            *v33 = 1;
          }
        }
        else
        {
          *(volatile uint8_t *)dword_121240 = *(volatile uint8_t *)(dword_121240 + 1);
        }
        v20 = (volatile uint8_t **)dword_121248;
        *(volatile uint32_t *)dword_121244 &= ~0x200u;
        *(volatile uint32_t *)(v1 + 4) &= ~1u;
        result = ke_event_set_lock((int)(uintptr_t)((volatile uint32_t *)(v1 + 48)));
        v21 = *v20;
        if ( **v20 == 2 )
        {
          if ( (__get_CPSR() & 1) == 0 )
          {
            __disable_irq();
            *(volatile uint32_t *)dword_1213CC = 1;
          }
          v35 = (volatile uint32_t *)dword_1213E8;
          v36 = (volatile uint32_t *)dword_1213C0;
          v37 = *(volatile uint32_t *)dword_1213C0;
          ++*(volatile uint32_t *)dword_1213E8;
          *v36 = 0;
          v38 = (*(volatile uint32_t *)0x40501010u);
          v39 = v37 & 0xF;
          while ( *v36 << 28 )
          {
            v40 = (*(volatile uint32_t *)0x40501010u) - v38;
            if ( v40 > 0x7530 )
            {
              v50 = v39;
              state_check_feature(2, aIdleErr);
              v39 = v50;
            }
          }
          v41 = (volatile uint32_t *)dword_1213D4;
          result = *(volatile uint32_t *)dword_1213D4;
          v42 = (*(volatile uint32_t *)0x40501010u);
          if ( v39 )
          {
            result &= *(volatile uint32_t *)dword_1213D0;
            if ( (result & 4) == 0 )
            {
              v51 = v1;
              v45 = (volatile uint32_t *)dword_1213D0;
              v46 = v42;
              do
              {
                result = 30000;
                v47 = (*(volatile uint32_t *)0x40501010u) - v46;
                v48 = *v45 & *v41;
                if ( v47 > 0x7530 )
                {
                  result = state_check_feature(2, aIdleIntErr);
                  v45 = (volatile uint32_t *)dword_1213D0;
                }
              }
              while ( (v48 & 4) == 0 );
              v1 = v51;
            }
          }
          *(volatile uint32_t *)dword_1213D8 = 4;
          if ( *v35 )
          {
            v43 = *v35 - 1;
            v44 = *(volatile uint32_t *)dword_1213CC;
            *v35 = v43;
            if ( !v43 )
            {
              if ( v44 )
                __enable_irq();
            }
          }
          v21 = *v20;
        }
        v22 = (volatile uint32_t *)dword_121238;
        *(volatile uint32_t *)dword_121238 &= ~1u;
        *v22 &= ~0x80u;
        v23 = *v21;
        if ( v23 == 1 )
        {
          v34 = (*(volatile uint32_t *)0x40501010u) + 32 * *(volatile uint32_t *)dword_1213C4;
          result = ke_event_lock((volatile uint32_t *)(v1 + 24), v34 - *(volatile uint16_t *)(dword_1213C8 + 0xBA));
          v23 = **v20;
        }
        if ( v23 == 2 )
        {
          *(volatile uint32_t *)dword_1213C0 = 48;
          result = sleep_critical_exit();
        }
        v4 = *(volatile uint8_t *)(v3 + 0x1E) & 0xDF;
        *(volatile uint8_t *)(v3 + 0x1E) = v4;
        goto LABEL_3;
      }
    }
    if ( (*(volatile uint32_t *)dword_121228 & 0x4000000) != 0 )
    {
      v10 = HIWORD(*(volatile uint32_t *)dword_121228);
      if ( (v10 & 0x3F0) != 0 )
      {
        v11 = (uint8_t)(v10 - 16);
        v12 = dword_12122C + 696 * v11;
        if ( *(volatile uint8_t *)(v12 + 37) )
        {
          result = 1320;
          v13 = dword_121234 + 1320 * *(volatile uint8_t *)(v12 + 34);
          if ( **(volatile int16_t **)dword_121230 >= 0 || v1 == v13 )
          {
            if ( (*v6 & 0x70000) == 0 )
              goto LABEL_43;
          }
          else
          {
            result = mmio_irq_clear((int)aVifStaVif, (int)aMmSleepinfoRxE, 864);
            if ( (*v6 & 0x70000) == 0 )
            {
LABEL_43:
              v49 = (v49 & ~0xFFFFFFFFull) | ((uint32_t)(*(volatile uint32_t *)dword_121228 >> 31) & 0xFFFFFFFFu);
              v49 = (v49 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)((*(volatile uint32_t *)dword_121228 >> 30) & 1) << 32);
              state_check_feature(2, "T=%d,%d\r\n", (uint32_t)v49, HIDWORD(v49));
              result = v49;
              if ( v49 )
              {
                result = rf_rx_packet_get(v49, SHIDWORD(v49), v13);
                v31 = (volatile uint32_t *)dword_121228;
                *(volatile uint32_t *)dword_121228 &= ~0x80000000;
                *v31 &= ~0x40000000u;
              }
            }
          }
        }
        else
        {
          result = ke_event_schedule_1("\x9B\x84Invalid STA:%d\n", v11);
        }
      }
      else
      {
        result = ke_event_schedule_1(asc_1489A0);
      }
    }
    else
    {
      result = ke_event_schedule_1("\x9B\x84Keyidx invalid,%02X\n", v4);
    }
    v4 = *(volatile uint8_t *)(v3 + 0x1E) & 0xFE;
    *(volatile uint8_t *)(v3 + 0x1E) = v4;
    goto LABEL_20;
  }
  return result;
}


// check_isr_handler @ 0x1213ec
int check_isr_handler() {
  if ( hci_cmd_send_short(0) != 1 )
    return hci_cmd_send(0, 0);
  *(volatile uint32_t *)off_121418 = 48;
  return hci_cmd_send(0, 1);
}


// write_pmu_control @ 0x12141c
int write_pmu_control() {
  *(volatile uint32_t *)off_12142C = 48;
  return hci_cmd_send(0, 1);
}


// irq_lock_save @ 0x121430
void irq_lock_save() {
  int v0; // r4
  volatile uint32_t *v1; // r5
  int v2; // r3
  int v3; // r2
  volatile uint32_t *v4; // r5
  volatile uint32_t **v5; // r6
  int v6; // r3
  volatile uint32_t *v7; // r3
  unsigned int v8; // r8
  unsigned int v9; // r2
  int v10; // r8
  volatile int **i; // r3
  int v12; // r2
  int v13; // r1
  int v14; // r0
  int v15; // r12
  int v16; // r2

  v0 = *(volatile uint32_t *)(dword_12157C + 8);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)dword_121580 = 1;
  }
  v1 = (volatile uint32_t *)dword_121584;
  ++*(volatile uint32_t *)dword_121584;
  mmio_set_bit(4);
  conn_get(4u);
  if ( *v1 )
  {
    v2 = *v1 - 1;
    v3 = *(volatile uint32_t *)dword_121580;
    *v1 = v2;
    if ( !v2 )
    {
      if ( v3 )
        __enable_irq();
    }
  }
  if ( v0 )
  {
    v4 = (volatile uint32_t *)dword_121588;
    v5 = (volatile uint32_t **)dword_12158C;
    do
    {
      while ( 1 )
      {
        if ( *(volatile uint8_t *)(v0 + 106) != 2 )
          goto LABEL_7;
        v6 = (uint8_t)(*(volatile uint8_t *)(v0 + 225) - 1);
        *(volatile uint8_t *)(v0 + 225) = v6;
        if ( v6 )
          goto LABEL_7;
        v7 = *v5;
        *(volatile uint8_t *)(v0 + 225) = *(volatile uint8_t *)(v0 + 224);
        if ( v7 )
          break;
LABEL_15:
        wlc_bmac_write_shm(v0);
        bt_conn_event_process((void *)(uintptr_t)(v0), *(volatile uint32_t *)(v0 + 36) + 3048);
        v8 = 32 * *v4;
        if ( v8 <= 0xBE7 )
          v8 += *(volatile uint16_t *)(v0 + 222) << 10;
        v9 = (*(volatile uint32_t *)0x40501010u) - 3048;
        v10 = v8 + v9;
        if ( *(volatile uint32_t *)(v0 + 72) )
          hci_command_handler(v0, *(volatile uint32_t *)(v0 + 36), v10);
        if ( *(volatile uint8_t *)(v0 + 1224) )
        {
          ke_event_lock((volatile uint32_t *)(v0 + 24), v10);
          goto LABEL_7;
        }
        if ( *(volatile uint8_t *)(dword_121594 + 0x5A) > 1u )
        {
          for ( i = *(volatile int ***)(dword_121594 + 0x10); i; i = (volatile int **)*i )
          {
            if ( *((volatile uint8_t *)i + 8) == *(volatile uint8_t *)(v0 + 107) )
            {
              v12 = *(volatile uint16_t *)(v0 + 222);
              v13 = *(volatile uint32_t *)(v0 + 36);
              v14 = (int)i[1];
              v15 = v13 + (v12 << 10);
              v16 = v12 << 10;
              if ( v14 == v15 )
              {
                i[1] = (volatile int *)v10;
                v14 = v10;
                v16 = *(volatile uint16_t *)(v0 + 222) << 10;
              }
              if ( v13 + 2 * v16 == v14 )
                i[1] = (volatile int *)(v16 + v10);
            }
          }
        }
        *(volatile uint32_t *)(v0 + 36) = v10;
        v0 = *(volatile uint32_t *)v0;
        if ( !v0 )
          goto LABEL_22;
      }
      while ( v7 != (volatile uint32_t *)(v0 + 48) )
      {
        v7 = (volatile uint32_t *)*v7;
        if ( !v7 )
          goto LABEL_15;
      }
      ke_event_schedule_1(aNextTbttTooClo);
LABEL_7:
      v0 = *(volatile uint32_t *)v0;
    }
    while ( v0 );
  }
LABEL_22:
  rf_status_poll();
}


// jump_to_12af2c @ 0x12159c
int jump_to_12af2c(int a1) {
  return bt_conn_set_bit(a1);
}



// rf_set_channel @ 0x1215a0
int rf_set_channel(int a1, int a2) {
  int v2; // r6
  volatile uint32_t *v3; // r3
  volatile uint32_t *v4; // lr
  volatile uint32_t *v5; // r12
  volatile uint32_t *v6; // r7
  volatile uint16_t *v7; // r2
  volatile uint32_t *v8; // r5
  volatile int *v9; // r2
  int v10; // r4
  unsigned int v11; // r5
  volatile uint32_t *v12; // r12
  volatile uint32_t *v13; // r7
  volatile uint16_t *v14; // r3
  volatile uint32_t *v15; // r2

  v2 = dword_121658;
  v3 = (void *)(uintptr_t)(off_12165C);
  v4 = (void *)(uintptr_t)(off_121670);
  v5 = (void *)(uintptr_t)(off_121674);
  v6 = (void *)(uintptr_t)(off_121660);
  v7 = (volatile uint16_t *)(dword_121658 + 696 * a1);
  *(volatile uint32_t *)off_12165C = v7[19] | (v7[20] << 16);
  v8 = (void *)(uintptr_t)(off_121664);
  v3[1] = v7[21];
  v9 = (volatile int *)off_121668;
  *v4 = 0;
  *v5 = 0;
  *v8 = 0;
  *v6 = 0;
  v10 = (uint8_t)(a1 + 16);
  *v9 = 0x20000000;
  while ( (*v9 & 0x20000000) != 0 )
    ;
  if ( (*v9 & 0x10000000) == 0 )
  {
    v11 = HIWORD(*v9);
    if ( (uint8_t)BYTE2(*v9) != v10 )
    {
      v12 = (void *)(uintptr_t)(off_12166C);
      v13 = (void *)(uintptr_t)(off_121668);
      *(volatile uint32_t *)off_12165C = -1;
      *v12 = -1;
      *v9 = ((uint8_t)v11 << 16) | 0x40000000;
      while ( (*v13 & 0x40000000) != 0 )
        ;
      v14 = (volatile uint16_t *)(v2 + 696 * a1);
      *(volatile uint32_t *)off_12165C = v14[19] | (v14[20] << 16);
      *(volatile uint32_t *)off_12166C = v14[21];
    }
  }
  v15 = (void *)(uintptr_t)(off_121668);
  *(volatile uint32_t *)off_121668 = (16 * a2) | (v10 << 16) | 0x40000002;
  while ( (*v15 & 0x40000000) != 0 )
    ;
  return (uint8_t)(a1 + 16);
}



// rx_handle_frame @ 0x121678
int rx_handle_frame(volatile char *a1, int a2, int a3, int a4) {
  unsigned int v4; // r7
  int v5; // r5
  int v7; // r6
  volatile uint32_t *v8; // r2
  volatile uint16_t *v9; // r7
  volatile uint32_t *v10; // r3
  volatile uint8_t *v11; // r3
  volatile uint32_t *v12; // r3
  int v13; // r0
  int v14; // r1
  volatile uint32_t *v15; // r3
  volatile uint32_t *v16; // r2
  char v18; // r6
  volatile uint32_t *v19; // r2
  volatile uint32_t *v20; // r3
  volatile uint32_t *v21; // r3
  volatile uint32_t *v22; // r3
  volatile uint32_t *v23; // r3
  volatile uint32_t *v24; // r3
  int v25; // r5

  v4 = (uint8_t)a1[1];
  v5 = (uint8_t)a1[41];
  if ( v4 == 255 )
  {
    if ( a1[40] == 5 )
    {
      v25 = HIBYTE(*(volatile uint32_t *)off_1218C8) - 3 + (uint8_t)*a1 + 2 * v5;
      v7 = (uint8_t)v25;
      wlc_phy_chanspec_set((volatile uint8_t *)a1, v25);
      return v7;
    }
    v18 = *a1;
    v19 = (void *)(uintptr_t)(off_1218A0);
    *(volatile uint32_t *)off_12189C = -1;
    *v19 = -1;
    v7 = (uint8_t)(v18 + 4 * v5);
    state_check_feature(256, "add gtk:%d,%d\r\n", (uint8_t)a1[41], (uint8_t)a1[40]);
    wlc_phy_chanspec_set((volatile uint8_t *)a1, v7);
  }
  else
  {
    if ( **(volatile int16_t **)off_121890 < 0 && v4 > 0x23 )
      mmio_irq_clear((int)aStaIdxStaMax, (int)aMmSecMachwkeyW, 1424);
    v7 = (uint8_t)(v4 + 16);
    state_check_feature(256, "add ptk:%d,%d\r\n", v4, (uint8_t)a1[40]);
    wlc_phy_radio_set((int)a1, v4 + 16);
    v8 = (void *)(uintptr_t)(off_1218A0);
    v9 = (volatile uint16_t *)(dword_121898 + 696 * v4);
    *(volatile uint32_t *)off_12189C = v9[19] | (v9[20] << 16);
    *v8 = v9[21];
  }
  switch ( a1[40] )
  {
    case 0:
      v20 = (void *)(uintptr_t)(off_1218AC);
      *(volatile uint32_t *)off_1218AC = *((volatile uint32_t *)a1 + 2);
      v20[1] = *((volatile uint32_t *)a1 + 3);
      v20[2] = *((volatile uint32_t *)a1 + 4);
      v20[3] = *((volatile uint32_t *)a1 + 5);
      v13 = 256;
      v14 = 0;
      break;
    case 1:
      v10 = (void *)(uintptr_t)(off_1218AC);
      *(volatile uint32_t *)off_1218AC = *((volatile uint32_t *)a1 + 2);
      v10[1] = *((volatile uint32_t *)a1 + 3);
      v10[2] = *((volatile uint32_t *)a1 + 4);
      v11 = *(volatile uint8_t **)off_1218B0;
      *(volatile uint32_t *)off_1218B4 = *((volatile uint32_t *)a1 + 5);
      if ( (*v11 & 1) != 0 )
      {
        v12 = (void *)(uintptr_t)(off_1218B8);
        *(volatile uint32_t *)off_1218B8 = *((volatile uint32_t *)a1 + 6);
        v12[1] = *((volatile uint32_t *)a1 + 7);
        v12[2] = *((volatile uint32_t *)a1 + 8);
        v12[3] = *((volatile uint32_t *)a1 + 9);
      }
      else
      {
        *(volatile uint32_t *)off_1218C4 &= ~1u;
      }
      v13 = 512;
      v14 = 4096;
      break;
    case 2:
      v15 = (void *)(uintptr_t)(off_1218AC);
      *(volatile uint32_t *)off_1218AC = *((volatile uint32_t *)a1 + 2);
      v15[1] = *((volatile uint32_t *)a1 + 3);
      v15[2] = *((volatile uint32_t *)a1 + 4);
      v15[3] = *((volatile uint32_t *)a1 + 5);
      v13 = 768;
      v14 = 0;
      break;
    case 3:
      v13 = 256;
      v14 = 4096;
      goto LABEL_22;
    case 4:
      v24 = (void *)(uintptr_t)(off_1218AC);
      *(volatile uint32_t *)off_1218AC = *((volatile uint32_t *)a1 + 2);
      v24[1] = *((volatile uint32_t *)a1 + 3);
      v24[2] = *((volatile uint32_t *)a1 + 4);
      v24[3] = *((volatile uint32_t *)a1 + 5);
      v13 = 1024;
      v14 = 4096;
      goto LABEL_20;
    case 6:
      v13 = 1280;
      v14 = 0;
      goto LABEL_22;
    case 7:
      v13 = 1280;
      goto LABEL_19;
    case 8:
      v13 = 768;
LABEL_19:
      v21 = (void *)(uintptr_t)(off_1218AC);
      *(volatile uint32_t *)off_1218AC = *((volatile uint32_t *)a1 + 2);
      v21[1] = *((volatile uint32_t *)a1 + 3);
      v21[2] = *((volatile uint32_t *)a1 + 4);
      v21[3] = *((volatile uint32_t *)a1 + 5);
      v14 = 0x2000;
LABEL_20:
      v22 = (void *)(uintptr_t)(off_1218B8);
      *(volatile uint32_t *)off_1218B8 = *((volatile uint32_t *)a1 + 6);
      v22[1] = *((volatile uint32_t *)a1 + 7);
      v22[2] = *((volatile uint32_t *)a1 + 8);
      v22[3] = *((volatile uint32_t *)a1 + 9);
      break;
    default:
      if ( **(volatile int16_t **)off_121890 < 0 )
        mmio_irq_clear(off_1218D0, (int)aMmKeyRamParamG, 159);
      v13 = 0;
      v14 = 4096;
LABEL_22:
      v23 = (void *)(uintptr_t)(off_1218AC);
      *(volatile uint32_t *)off_1218AC = *((volatile uint32_t *)a1 + 2);
      v23[1] = *((volatile uint32_t *)a1 + 3);
      v23[2] = *((volatile uint32_t *)a1 + 4);
      v23[3] = *((volatile uint32_t *)a1 + 5);
      break;
  }
  v16 = (void *)(uintptr_t)(off_1218BC);
  *(volatile uint32_t *)off_1218BC = (16 * v5) | (4 * (uint8_t)a1[42]) | v13 | (v7 << 16) | v14 | 0x40000000;
  while ( (*v16 & 0x40000000) != 0 )
    ;
  return v7;
}


// check_hw_version @ 0x1218d4
volatile uint32_t * check_hw_version(int a1) {
  int v2; // r1
  volatile uint32_t *v3; // r5
  volatile uint32_t *v4; // r2
  volatile int *v5; // r1
  volatile uint32_t *v6; // r5
  volatile uint32_t *result; // r0
  int v8; // r5
  int v9; // r6
  volatile uint32_t *v10; // r2

  if ( (unsigned int)a1 > HIBYTE(*(volatile uint32_t *)off_12199C) )
    return (volatile uint32_t *)dma_tx_reset(
                       dword_1219A4 + 1320 * ((a1 - (HIBYTE(*(volatile uint32_t *)off_12199C) + 1)) / 2),
                       (((uint8_t)a1 - 1 - HIBYTE(*(volatile uint32_t *)off_12199C)) & 1) + 4);
  if ( (unsigned int)a1 > 0xF )
  {
    v8 = dword_1219C0 + 696 * (uint8_t)(a1 - 16);
    v9 = *(volatile uint8_t *)(v8 + 34);
    result = (volatile uint32_t *)wlc_phy_band_init(v8);
    if ( *(volatile uint8_t *)(dword_1219A4 + 1320 * v9 + 106) == 2 )
      return result;
    v10 = (void *)(uintptr_t)(off_1219A8);
    *(volatile uint32_t *)off_1219A0 = *(volatile uint16_t *)(v8 + 38) | (*(volatile uint16_t *)(v8 + 40) << 16);
    *v10 = *(volatile uint16_t *)(v8 + 42);
  }
  else
  {
    v2 = dword_1219A4;
    v3 = (void *)(uintptr_t)(off_1219A8);
    *(volatile uint32_t *)off_1219A0 = -1;
    *v3 = -1;
    dma_tx_reset(v2 + 1320 * (a1 >> 2), a1 & 3);
  }
  v4 = (void *)(uintptr_t)(off_1219AC);
  v5 = (volatile int *)off_1219B0;
  v6 = (void *)(uintptr_t)(off_1219B8);
  result = (void *)(uintptr_t)(off_1219BC);
  *(volatile uint32_t *)off_1219B4 = 0;
  *v6 = 0;
  *v4 = 0;
  *result = 0;
  *v5 = (a1 << 16) | 0x40000000;
  while ( (*v5 & 0x40000000) != 0 )
    ;
  return result;
}



// dma_free_buf @ 0x1219c4
int dma_free_buf() {
  set_system_flag_2(0x2000000);
  *((volatile uint32_t *)off_1219E4 + 1) &= ~4u;
  return hci_cmd_send(0, 0);
}


