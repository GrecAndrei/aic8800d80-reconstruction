// get_bss_by_channel @ 0x11fef8
uint64_t get_bss_by_channel(volatile uint8_t *a1, char a2) {
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
  v5 = dword_120048;
  v6 = (volatile uint8_t *)(1320 * v4 + 120 * v3 + dword_120048);
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
      *(volatile uint64_t *)(1320 * v4 + 120 * v3 + v5 + 552) = hash32(v9) & 0xFFFFFFLL;
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
      *(volatile uint64_t *)(1320 * v4 + 120 * v3 + v5 + 552) = *(volatile uint64_t *)&dword_120040;
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



// get_sta_by_idx @ 0x12004c
int get_sta_by_idx(int result, int a2) {
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



// get_hw_tsf @ 0x1200d4
int get_hw_tsf(int result) {
  volatile uint32_t *v1; // r4
  int v2; // r5

  v1 = *(volatile uint32_t **)(result + 240);
  if ( v1 )
  {
    v2 = result;
    do
    {
      result = is_ll_event_pending(v2, (int)v1, 0);
      v1 = (volatile uint32_t *)*v1;
    }
    while ( v1 );
  }
  return result;
}



// mmio_reg_addr @ 0x1200f0
int mmio_reg_addr(int a1) {
  return mm_timer_set((void *)(uintptr_t)(a1 + 48), *((volatile uint32_t *)off_120100 + 4) + 10000);
}



// get_sys_state @ 0x120104
int get_sys_state(int result) {
  int v1; // r4

  if ( *(volatile uint8_t *)off_12012C && (*((volatile uint32_t *)off_12012C + 1) & 8) == 0 )
  {
    v1 = result;
    if ( !*(volatile uint32_t *)(result + 4) )
    {
      mem_set_util(result + 48);
      return is_tx_engine_busy(v1);
    }
  }
  return result;
}



// set_bss_cap @ 0x120130
int set_bss_cap(int result, unsigned int a2) {
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
    *(volatile uint32_t *)off_1201C0 = 1;
  }
  v2 = (void *)(uintptr_t)(off_1201C4);
  v3 = (void *)(uintptr_t)(off_1201C8);
  v4 = *(volatile uint32_t *)off_1201C4;
  v5 = *((volatile uint8_t *)off_1201C8 + 18);
  v6 = *(volatile uint32_t *)off_1201C4 + 1;
  *(volatile uint32_t *)off_1201C4 = v6;
  if ( v5 <= 1 )
  {
    v3[20] = *(volatile uint8_t *)(result + 107);
    v7 = a2;
    *(volatile uint16_t *)(result + 224) = 257;
  }
  else
  {
    v7 = *(volatile uint16_t *)(dword_1201CC + 1320 * (uint8_t)v3[20] + 222);
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
  *(volatile uint32_t *)off_1201D0 = (HIWORD(*(volatile uint32_t *)off_1201D0) << 16) | v7;
  if ( v6 )
  {
    v10 = (volatile int *)off_1201C0;
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



// alloc_ctrl_block @ 0x1201d4
int alloc_ctrl_block(int a1) {
  volatile uint8_t *v2; // r5
  int v3; // r0
  int v4; // r1
  int v5; // r0
  char v6; // r1
  int v7; // r3
  int v8; // r7
  char v10[5]; // [sp+7h] [bp-5h] BYREF

  v2 = (volatile uint8_t *)tx_send_pdu(88, 13, 0, 3);
  v3 = *(volatile uint8_t *)(a1 + 107);
  v10[0] = -1;
  chan_ctxt_unlink(v3);
  v4 = *(volatile uint32_t *)(a1 + 1216);
  *(volatile uint32_t *)(a1 + 412) = *(volatile uint32_t *)(a1 + 1212);
  *(volatile uint32_t *)(a1 + 416) = v4;
  *(volatile uint16_t *)(a1 + 420) = *(volatile uint16_t *)(a1 + 1220);
  *(volatile uint8_t *)(a1 + 464) = 0;
  compute_byte_delta(a1);
  v5 = cfm_radio_check((void *)(uintptr_t)(a1 + 1212), v10);
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
        ((int (*)())bsscfg_index)();
        *((volatile uint8_t *)off_1202B0 + 9) = 1;
      }
    }
    return (int)(uintptr_t)(rx_process_packet_1((int)(uintptr_t)(v2)));
  }
  *(volatile uint8_t *)(a1 + 146) = v7;
  if ( !v5 )
  {
    v8 = *(volatile uint8_t *)(a1 + 116);
    ((int (*)())bsscfg_index)();
    mem_set_util(a1 + 48);
    mm_timer_set((void *)(uintptr_t)(a1 + 24), *((volatile uint32_t *)off_1202AC + 4) + *(volatile uint32_t *)(dword_1202A8 + 696 * v8 + 8));
    *(volatile uint8_t *)(a1 + 128) = 0;
    *(volatile uint8_t *)(a1 + 147) = 1;
    return (int)(uintptr_t)(rx_process_packet_1((int)(uintptr_t)(v2)));
  }
  rf_read_reg(a1);
  return (int)(uintptr_t)(rx_process_packet_1((int)(uintptr_t)(v2)));
}



// check_hw_counters @ 0x1202b4
int check_hw_counters() {
  int result; // r0

  if ( *((volatile uint8_t *)off_1202D4 + 18) + *((volatile uint8_t *)off_1202D4 + 17) != 1 )
    return 0;
  result = *((volatile uint32_t *)off_1202D4 + 2);
  if ( *(volatile uint8_t *)(result + 106) )
    return 0;
  return result;
}



// mac_clear_irq @ 0x1202d8
void mac_clear_irq() {
  int v0; // r3

  v0 = *((volatile uint8_t *)off_1202F0 + 18) + *((volatile uint8_t *)off_1202F0 + 17);
  *(volatile uint32_t *)off_1202F4 = 0;
  if ( v0 <= 1 )
    get_current_channel_1();
}



// reset_drv_flag @ 0x1202f8
int reset_drv_flag(volatile uint8_t *a1) {
  volatile uint32_t *v1; // r3
  volatile int *v2; // r3
  int result; // r0

  v1 = (void *)(uintptr_t)(off_120348);
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



// alloc_shared_packet @ 0x12034c
int alloc_shared_packet(int a1) {
  volatile uint32_t *v2; // r0

  v2 = (volatile uint32_t *)tx_send_pdu(143, 0, 255, 4);
  *v2 = a1;
  return (int)(uintptr_t)(rx_process_packet_1((int)(uintptr_t)(v2)));
}



// get_mac_ver @ 0x120368
int get_mac_ver() {
  int result; // r0
  volatile uint32_t *v1; // r1
  volatile uint16_t *v2; // r3
  unsigned int v3; // r2
  int16_t v4; // r2
  volatile uint32_t *v5; // r1
  int16_t v6; // r2
  volatile uint32_t *v7; // r1
  int16_t v8; // r2

  if ( (uint16_t)(*(volatile uint32_t *)off_1203F4 >> 12) && (uint16_t)(*(volatile uint32_t *)off_1203F4 >> 12) <= 0x96u )
    result = (uint16_t)(*(volatile uint32_t *)off_1203F4 >> 12);
  else
    result = 150;
  v1 = (void *)(uintptr_t)(off_1203F8);
  v2 = (void *)(uintptr_t)(off_1203FC);
  v3 = *(volatile uint32_t *)off_1203F8;
  *((volatile uint16_t *)off_1203FC + 4) = result;
  if ( (uint16_t)(v3 >> 12) && (uint16_t)(*v1 >> 12) <= 0x96u )
    v4 = *v1 >> 12;
  else
    v4 = 150;
  v5 = (void *)(uintptr_t)(off_120400);
  v2[5] = v4;
  if ( (uint16_t)(*v5 >> 12) && (uint16_t)(*v5 >> 12) <= 0x96u )
    v6 = *v5 >> 12;
  else
    v6 = 150;
  v7 = (void *)(uintptr_t)(off_120404);
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



// init_fw_config @ 0x120408
int init_fw_config() {
  volatile uint8_t *v0; // r4
  int v1; // r3
  volatile int16_t *v2; // r1
  int v3; // r1
  int result; // r0

  v0 = (void *)(uintptr_t)(off_12045C);
  memset((volatile int *)off_12045C, 0, 0x34u);
  v1 = dword_120464;
  v2 = *(volatile int16_t **)off_120460;
  *(volatile uint32_t *)v0 = dword_120464;
  v0[31] = 1;
  *((volatile uint16_t *)v0 + 9) = 0;
  v3 = *v2;
  *((volatile uint32_t *)v0 + 1) = 0;
  if ( v3 < 0 && *(volatile uint32_t *)off_120470 << 28 )
  {
    log_warning(dword_120478, dword_120474, 472);
    v1 = *(volatile uint32_t *)v0 | *((volatile uint32_t *)v0 + 1);
  }
  *(volatile uint32_t *)off_120468 = v1;
  result = get_mac_ver();
  *((volatile uint32_t *)v0 + 9) = dword_12046C;
  return result;
}



// rf_phy_init_1 @ 0x12047c
/* luna: Initializes RF/PHY control registers with startup defaults and applies configuration-dependent mode bits. */
volatile uint32_t *rf_phy_init_1() {
  volatile int *v0; // r4
  volatile int *v1; // r5
  volatile int *v2; // r6
  int v3; // r0
  int v4; // r0
  volatile uint32_t *v5; // r0
  volatile unsigned int *v6; // r1
  volatile unsigned int *v7; // r3
  int v8; // r4
  int rf_config; // r3
  char rf_config_flags; // r2
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

  v0 = (volatile int *)off_120598;
  v1 = (volatile int *)off_12059C;
  v2 = (volatile int *)off_1205A0;
  v3 = nullsub_1();
  v4 = ((int (*)())nullsub_2)(v3);
  ((int (*)())nullsub_3)(v4);
  v5 = (void *)(uintptr_t)(off_1205A4);
  v6 = (volatile unsigned int *)off_1205A8;
  v7 = (volatile unsigned int *)off_1205AC;
  *v0 = *v0 & 0x3FFFFF | 0x2800000;
  v8 = dword_1205B0;
  *v5 |= 0x8000000u;
  *v6 = *v6 & 0xFF0FFFFF | 0x200000;
  *v7 = *v7 & 0xFFFFF8FF | 0x600;
  *v7 = *v7 & 0xFFFFC7FF | 0x2000;
  *v7 = *v7 & 0xFFFE3FFF | 0xC000;
  *v7 |= 0xE0000u;
  *v1 = *v1 & v8 | 0x5DC;
  v5[1] = v5[1] & v8 | 0xBB8;
  *(v6 - 205) = *(v6 - 205) & 0xFFFF00FF | 0xDA00;
  rf_config = *v2;
  rf_config_flags = *(volatile uint8_t *)(*v2 + 2);
  if ( (rf_config_flags & 0x10) != 0 )
    v5[16] &= ~0x80000000;
  else
    *(volatile uint32_t *)off_1205DC |= 0x80000000;
  v11 = (rf_config_flags & 1) == 0;
  v12 = *(volatile uint32_t *)off_1205B4;
  if ( v11 )
    v13 = v12 & 0xFFFBFFFF;
  else
    v13 = v12 | 0x40000;
  *(volatile uint32_t *)off_1205B4 = v13;
  v14 = (void *)(uintptr_t)(off_1205B8);
  *(volatile uint32_t *)off_1205B8 = dword_1205BC;
  if ( *(volatile uint8_t *)(rf_config + 1) )
    *(v14 - 215) |= 0x40u;
  v15 = (void *)(uintptr_t)(off_1205C4);
  v16 = (void *)(uintptr_t)(off_1205C8);
  v17 = (void *)(uintptr_t)(off_1205CC);
  result = (void *)(uintptr_t)(off_1205D0);
  v19 = (volatile uint8_t **)off_1205D4;
  *(volatile uint32_t *)off_1205C0 &= ~1u;
  *v15 = 0xFFFF;
  *v16 = -1;
  *v17 = 0xFFFF;
  *result = -1;
  v20 = **v19;
  if ( (unsigned int)(v20 - 1) <= 1 || v20 == 4 )
    *(volatile uint32_t *)off_1205D8 |= 0x80000000;
  return result;
}



// get_rf_state @ 0x1205e0
volatile uint32_t *get_rf_state() {
  volatile uint8_t *v0; // r4
  volatile int *v1; // r0
  int v2; // r0
  int v3; // r0
  int v4; // r0
  int v5; // r0
  int v6; // r0
  int v7; // r0
  int v8; // r0
  int v9; // r0

  v0 = (void *)(uintptr_t)(off_120638);
  if ( !*((volatile uint8_t *)off_120638 + 2) )
    rf_hw_init_1();
  init_fw_config();
  reset_controller_block();
  v1 = (void *)(uintptr_t)(controller_init_pools());
  v2 = (int)(uintptr_t)(init_all_chan_entries(v1));
  v3 = mfp_key_clear(v2);
  rf_patch_init(v3);
  v4 = system_init_seq();
  if ( v0[2] )
    v5 = ((int (*)())nullsub_4)(v4);
  else
    v5 = dma_poll_status();
  v6 = deinit_global_0x18fb00(v5);
  v7 = reset_global_config(v6);
  v8 = llc_env_init(v7);
  v9 = deinit_bt_global_0x190688(v8);
  init_bt_global_0x190310(v9);
  ke_get_state();
  return rf_phy_init_1();
}



// check_non_null @ 0x12063c
volatile int * check_non_null(volatile int *result, int a2, int a3) {
  volatile int *v3; // r3
  volatile unsigned int *v4; // r3
  volatile unsigned int *v5; // r3
  volatile unsigned int *v6; // r3

  if ( !a2 )
  {
    v3 = *((volatile int **)off_1206F8 + 2);
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
          v5 = (volatile unsigned int *)off_1206FC;
          *(volatile uint32_t *)off_1206FC = *(volatile uint32_t *)off_1206FC & 0xFFFFFF00 | 0x68;
          *v5 = *v5 & 0xFFFF00FF | 0x7800;
          *v5 = *v5 & 0xFF00FFFF | 0x780000;
          return result;
        }
LABEL_4:
        v4 = (volatile unsigned int *)off_1206FC;
        *(volatile uint32_t *)off_1206FC = *(volatile uint32_t *)off_1206FC & 0xFFFFFF00 | 0x80;
        *v4 = *v4 & 0xFFFF00FF | 0x8000;
        *v4 = *v4 & 0xFF00FFFF | 0x800000;
        return result;
      }
    }
  }
  v6 = (volatile unsigned int *)off_1206FC;
  *(volatile uint32_t *)off_1206FC = *(volatile uint32_t *)off_1206FC & 0xFFFFFF00 | 0x60;
  *v6 = *v6 & 0xFFFF00FF | 0x6000;
  *v6 = *v6 & 0xFF00FFFF | 0x600000;
  return result;
}



// rx_packet_proc @ 0x120700
int rx_packet_proc(int a1, int a2, int a3, int a4, int a5, int a6) {
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
    calc_channel_rate(*(volatile uint8_t *)(a4 + 107), v9, (uint8_t)v13);
    v51 = v12 * v13;
  }
  else if ( a6 )
  {
    v13 = *(volatile uint8_t *)(a6 + 2);
    if ( !*(volatile uint8_t *)(a6 + 2) )
    {
      v13 = *(volatile uint8_t *)(a6 + 3);
      calc_channel_rate(*(volatile uint8_t *)(a4 + 107), v9, v13);
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
    v14 = (volatile char *)off_120A14;
    v15 = (volatile int *)off_120A64;
    v16 = (volatile int *)off_120A18;
    *(volatile uint32_t *)off_120A14 = *((volatile uint8_t *)off_120A64 + (*(volatile uint8_t *)(a3 + 44) >> 4)) & 0x7F
                          | *(volatile uint32_t *)off_120A14 & 0xFFFFFF80;
    v17 = (void *)(v14 + 8);
    *v16 = a2 | (*(volatile uint8_t *)(a3 + 40) >> 7 << 20);
    *v17 = 0x80000000;
    __dsb(0xFu);
    while ( (*v17 & 0xC0000000) != 0x40000000 )
      ;
    v18 = (volatile int16_t **)off_120A1C;
    if ( **(volatile int16_t **)off_120A1C >= 0 || (*v17 & 0x40000000) != 0 )
    {
      v19 = (uint16_t)*(volatile uint32_t *)off_120A20;
    }
    else
    {
      log_assert_failure((int)aNxmacTimeOnAir, (int)aHalMachwRxBcnD, 430);
      v19 = 500;
      v18 = (volatile int16_t **)off_120A1C;
    }
    if ( !(*(volatile uint8_t *)(a3 + 40) << 28) )
    {
      v20 = (volatile char *)off_120A14;
      v21 = (volatile int *)off_120A18;
      *(volatile uint32_t *)off_120A14 = *((volatile uint8_t *)v15 + (*(volatile uint8_t *)(a3 + 44) >> 4)) & 0x7F
                            | *(volatile uint32_t *)off_120A14 & 0xFFFFFF80;
      v22 = (void *)(v20 + 8);
      *v21 = (*(volatile uint8_t *)(a3 + 40) >> 7 << 20) | 0x18;
      *v22 = 0x80000000;
      __dsb(0xFu);
      while ( (*v22 & 0xC0000000) != 0x40000000 )
        ;
      if ( **v18 >= 0 || (*v22 & 0x40000000) != 0 )
      {
        v23 = (uint16_t)*(volatile uint32_t *)off_120A20;
        v24 = v19 - v23;
        goto LABEL_15;
      }
      log_assert_failure((int)aNxmacTimeOnAir, (int)aHalMachwRxBcnD, 430);
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
  v27 = double_cmp(__PAIR64__(v11, v10), v12);
  v47 = __PAIR64__(v11, v10) - (unsigned int)v23;
  v28 = v27 * (v12 >> 31) + v12 * HIDWORD(v27);
  v29 = (unsigned int)v27 * (uint64_t)(unsigned int)v12;
  v29 = (v29 & 0xFFFFFFFFull) | ((uint64_t)(uint32_t)(((uint32_t)(v29 >> 32) & 0xFFFFFFFFu) + (uint32_t)(v28))) << 32;;
  if ( v29 < v47 )
    v47 = v29;
  v30 = v47 + v51;
  if ( (*(volatile uint32_t *)off_120A24 & 0x2000000) != 0 )
    v31 = dword_120A34 - v48 - v26 + v30;
  else
    v31 = v30 - v48 - 400;
  v32 = (*(volatile uint32_t *)0x40501010u);
  v33 = v32 - *(volatile uint32_t *)off_120A2C + v31;
  v34 = v33 - (*(volatile uint32_t *)0x40501010u) - 4300 - get_timeout_1000();
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
        alloc_tx_event(aMoveTbtt, v36);
      }
    }
  }
  v38 = get_timeout_1000();
  v39 = (*(volatile uint32_t *)0x40501010u);
  result = v33 - v39 - 4300 - v38;
  if ( result >= 0 && *(volatile uint32_t *)(a4 + 36) != v33 )
  {
    v41 = (void *)(uintptr_t)(off_120A30);
if ( *((volatile uint32_t *)off_120A30 + 8) != a4 || (v42 = (void *)(uintptr_t)(off_120A24), *(volatile uint32_t *)(a4 + 36) = v33, (*v42 & 0x2000000) != 0) ) { mm_timer_set((volatile uint32_t *)(a4 + 24), v33);
    }
    else
    {
      v43 = (volatile uint8_t *)off_120A44;
      v44 = (uint8_t)v41[36];
      *(volatile uint8_t *)off_120A44 = BYTE2(*(volatile uint32_t *)off_120A40);
      if ( !v44 )
      {
        v45 = *(volatile uint8_t **)off_120A4C;
        v43[1] = *(volatile uint32_t *)off_120A48;
        v41[36] = 1;
        if ( *v45 == 1 )
        {
          v46 = (void *)(uintptr_t)(off_120A54);
          *(volatile uint32_t *)off_120A50 = 1;
          *v46 |= 1u;
        }
        if ( *v43 >= (unsigned int)v43[1] )
          alloc_tx_event(
            "dtim:%d,%d,%d,%d\r\n",
            *v43,
            v43[1],
            HIWORD(*(volatile uint32_t *)off_120A88),
            (uint8_t)*(volatile uint32_t *)off_120A84);
        if ( **(volatile int16_t **)off_120A1C < 0 && *v43 >= (unsigned int)v43[1] )
          irq_disable_mmio_write((int)aVolatileUint8T, (int)aMmTbttCompute, 523);
      }
    }
    return radio_disabled_check(a4);
  }
  return result;
}


// alloc_rx_buf_pool @ 0x120a90
int alloc_rx_buf_pool() {
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

  v0 = dword_120E14;
  v1 = *(volatile uint32_t *)(dword_120E14 + 0x20);
  result = irq_disable_global_3(0x40000);
  if ( v1 )
  {
    v3 = dword_120D9C;
    v4 = *(volatile uint8_t *)(dword_120D9C + 0x1E);
LABEL_3:
    v5 = (volatile uint32_t *)dword_120DA0;
    v6 = (volatile uint32_t *)dword_120DA4;
    v7 = (volatile uint32_t *)dword_120E1C;
    while ( 1 )
    {
      if ( !v4 )
        return result;
      if ( (v4 & 8) != 0 )
      {
        v8 = *(volatile uint32_t *)dword_120DA8;
        *(volatile uint32_t *)dword_120DAC = 0x80000000;
        v9 = (*(volatile uint32_t *)0x40501010u);
        if ( (int)(*(volatile uint32_t *)(v8 + 4) + *(volatile uint32_t *)(v1 + 120) - v9) < 0
          && !phy_get_channel(*(volatile uint8_t *)(v1 + 116), 0, 0) )
        {
          v30 = (*(volatile uint32_t *)0x40501010u);
          *(volatile uint32_t *)(v1 + 120) = v30;
        }
        v4 = *(volatile uint8_t *)(v3 + 0x1E) & 0xF7;
        *(volatile uint8_t *)(v3 + 0x1E) = v4;
      }
      if ( (v4 & 4) != 0 )
      {
        check_feature_flag(2, aL);
        v24 = (volatile int16_t **)dword_120DB8;
        v25 = *(volatile uint32_t *)(v3 + 4);
        *v5 &= ~4u;
        v26 = **v24;
        v27 = v25 | 0x200;
        *(volatile uint32_t *)(v3 + 4) = v27;
        if ( v26 < 0 && *(volatile uint32_t *)dword_120DE4 << 28 )
        {
          log_warning((int)aNxmacCurrentSt, (int)aMmRxFilterSet_1, 472);
          v27 = *(volatile uint32_t *)(v3 + 4);
        }
        v28 = off_120DD8;
        *(volatile uint32_t *)dword_120DDC = v27 | *(volatile uint32_t *)v3;
        get_bt_device_state(*(volatile uint8_t *)(v1 + 107), v28, v1);
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
          mem_set_util((int)(uintptr_t)((volatile uint32_t *)dword_120DF4));
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
        v14 = *(volatile uint32_t *)dword_120DC0;
        v15 = (*(volatile uint32_t *)dword_120DC0 >> 5) & 3;
        check_feature_flag(2, "BCN:%d[%d]\r\n", v15, HIWORD(*(volatile uint32_t *)(dword_120DC0 - 12)) & 0x7FFF);
        v16 = *(volatile uint32_t *)(v1 + 120);
        v17 = *(volatile uint32_t *)(*(volatile uint32_t *)dword_120DA8 + 4);
        *(volatile uint8_t *)(v1 + 128) = 0;
        v18 = (*(volatile uint32_t *)0x40501010u);
        v19 = v14 >> 5;
        if ( (int)(v17 + v16 - v18) < 0 )
        {
          *(volatile uint8_t *)(v3 + 0x1E) |= 8u;
          check_feature_flag(2, aNull);
        }
        if ( v15 )
        {
          while ( (*(volatile uint32_t *)dword_120DC0 & 8) == 0 )
            ;
          v32 = (volatile uint32_t *)dword_120DC0;
          *(volatile uint32_t *)dword_120DC0 &= ~8u;
          if ( (*v32 & 0x10) != 0 )
          {
            check_feature_flag(2, aFcsOk);
            *(volatile uint8_t *)dword_120DC8 = BYTE2(*(volatile uint32_t *)dword_120E0C);
            mfp_key_disable(v15 >> 1, v19 & 1, v1);
            *v32 &= ~0x10u;
          }
          else
          {
            *(volatile uint32_t *)dword_120F38 = 1;
            check_feature_flag(2, aFcsNotOk);
            v33 = (volatile uint32_t *)dword_120F44;
            *(volatile uint8_t *)dword_120F40 = *(volatile uint8_t *)(dword_120F40 + 1) > 1u;
            *v33 = 1;
          }
        }
        else
        {
          *(volatile uint8_t *)dword_120DC8 = *(volatile uint8_t *)(dword_120DC8 + 1);
        }
        v20 = (volatile uint8_t **)dword_120DD0;
        *(volatile uint32_t *)dword_120DCC &= ~0x200u;
        *(volatile uint32_t *)(v1 + 4) &= ~1u;
        result = mem_set_util((int)(uintptr_t)((volatile uint32_t *)(v1 + 48)));
        v21 = *v20;
        if ( **v20 == 2 )
        {
          if ( (__get_CPSR() & 1) == 0 )
          {
            __disable_irq();
            *(volatile uint32_t *)dword_120F54 = 1;
          }
          v35 = (volatile uint32_t *)dword_120F70;
          v36 = (volatile uint32_t *)dword_120F48;
          v37 = *(volatile uint32_t *)dword_120F48;
          ++*(volatile uint32_t *)dword_120F70;
          *v36 = 0;
          v38 = (*(volatile uint32_t *)0x40501010u);
          v39 = v37 & 0xF;
          while ( *v36 << 28 )
          {
            v40 = (*(volatile uint32_t *)0x40501010u) - v38;
            if ( v40 > 0x7530 )
            {
              v50 = v39;
              check_feature_flag(2, aIdleErr);
              v39 = v50;
            }
          }
          v41 = (volatile uint32_t *)dword_120F5C;
          result = *(volatile uint32_t *)dword_120F5C;
          v42 = (*(volatile uint32_t *)0x40501010u);
          if ( v39 )
          {
            result &= *(volatile uint32_t *)dword_120F58;
            if ( (result & 4) == 0 )
            {
              v51 = v1;
              v45 = (volatile uint32_t *)dword_120F58;
              v46 = v42;
              do
              {
                result = 30000;
                v47 = (*(volatile uint32_t *)0x40501010u) - v46;
                v48 = *v45 & *v41;
                if ( v47 > 0x7530 )
                {
                  result = check_feature_flag(2, aIdleIntErr);
                  v45 = (volatile uint32_t *)dword_120F58;
                }
              }
              while ( (v48 & 4) == 0 );
              v1 = v51;
            }
          }
          *(volatile uint32_t *)dword_120F60 = 4;
          if ( *v35 )
          {
            v43 = *v35 - 1;
            v44 = *(volatile uint32_t *)dword_120F54;
            *v35 = v43;
            if ( !v43 )
            {
              if ( v44 )
                __enable_irq();
            }
          }
          v21 = *v20;
        }
        v22 = (volatile uint32_t *)dword_120DC0;
        *(volatile uint32_t *)dword_120DC0 &= ~1u;
        *v22 &= ~0x80u;
        v23 = *v21;
        if ( v23 == 1 )
        {
          v34 = (*(volatile uint32_t *)0x40501010u) + 32 * *(volatile uint32_t *)dword_120F4C;
          result = mm_timer_set((volatile uint32_t *)(v1 + 24), v34 - *(volatile uint16_t *)(dword_120F50 + 0xBA));
          v23 = **v20;
        }
        if ( v23 == 2 )
        {
          *(volatile uint32_t *)dword_120F48 = 48;
          result = critical_section_enter_alt();
        }
        v4 = *(volatile uint8_t *)(v3 + 0x1E) & 0xDF;
        *(volatile uint8_t *)(v3 + 0x1E) = v4;
        goto LABEL_3;
      }
    }
    if ( (*(volatile uint32_t *)dword_120DB0 & 0x4000000) != 0 )
    {
      v10 = HIWORD(*(volatile uint32_t *)dword_120DB0);
      if ( (v10 & 0x3F0) != 0 )
      {
        v11 = (uint8_t)(v10 - 16);
        v12 = dword_120DB4 + 696 * v11;
        if ( *(volatile uint8_t *)(v12 + 37) )
        {
          result = 1320;
          v13 = dword_120DBC + 1320 * *(volatile uint8_t *)(v12 + 34);
          if ( **(volatile int16_t **)dword_120DB8 >= 0 || v1 == v13 )
          {
            if ( (*v6 & 0x70000) == 0 )
              goto LABEL_43;
          }
          else
          {
            result = irq_disable_mmio_write((int)aVifStaVif, (int)aMmSleepinfoRxE, 864);
            if ( (*v6 & 0x70000) == 0 )
            {
LABEL_43:
              v49 = (v49 & ~0xFFFFFFFFull) | ((uint32_t)(*(volatile uint32_t *)dword_120DB0 >> 31) & 0xFFFFFFFFu);
              v49 = (v49 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)((*(volatile uint32_t *)dword_120DB0 >> 30) & 1) << 32);
              check_feature_flag(2, "T=%d,%d\r\n", (uint32_t)v49, HIDWORD(v49));
              result = v49;
              if ( v49 )
              {
                result = mfp_key_disable(v49, SHIDWORD(v49), v13);
                v31 = (volatile uint32_t *)dword_120DB0;
                *(volatile uint32_t *)dword_120DB0 &= ~0x80000000;
                *v31 &= ~0x40000000u;
              }
            }
          }
        }
        else
        {
          result = alloc_tx_event("\x9B\x84Invalid STA:%d\n", v11);
        }
      }
      else
      {
        result = alloc_tx_event(asc_1486C0);
      }
    }
    else
    {
      result = alloc_tx_event("\x9B\x84Keyidx invalid,%02X\n", v4);
    }
    v4 = *(volatile uint8_t *)(v3 + 0x1E) & 0xFE;
    *(volatile uint8_t *)(v3 + 0x1E) = v4;
    goto LABEL_20;
  }
  return result;
}


// is_band_5g @ 0x120f74
int is_band_5g() {
  if ( hci_cmd_handler(0) != 1 )
    return ke_state_set(0, 0);
  *(volatile uint32_t *)off_120FA0 = 48;
  return ke_state_set(0, 1);
}


// rf_write_reg @ 0x120fa4
int rf_write_reg() {
  *(volatile uint32_t *)off_120FB4 = 48;
  return ke_state_set(0, 1);
}


// ke_timer_handler @ 0x120fb8
void ke_timer_handler() {
  unsigned int v0; // r6
  int v1; // r4
  volatile uint32_t *v2; // r5
  int v3; // r3
  int v4; // r2
  volatile uint32_t *v5; // r7
  volatile uint32_t *v6; // r9
  int v7; // r5
  int v8; // r3
  volatile uint32_t *v9; // r3
  unsigned int v10; // r10
  unsigned int v11; // r2
  int v12; // r10
  unsigned int v13; // r4
  volatile unsigned int v14; // r2
  unsigned int v15; // r3
  int v16; // zf
  int v17; // cc
  int v18; // r3
  int v19; // r1
  int v20; // r3
  int v21; // r2
  int v22; // r3
  volatile unsigned int v23; // r1
  volatile uint32_t *v24; // r0
  volatile int **i; // r3
  int v26; // r2
  int v27; // r1
  int v28; // r0
  int v29; // r12
  int v30; // r2

  v0 = dword_1211C0;
  v1 = *(volatile uint32_t *)(dword_1211C0 + 8);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)dword_1211C4 = 1;
  }
  v2 = (volatile uint32_t *)dword_1211C8;
  ++*(volatile uint32_t *)dword_1211C8;
  mmio_modify_bit(4);
  phy_get_cfg_ptr(4u);
  if ( *v2 && (v3 = *v2 - 1, v4 = *(volatile uint32_t *)dword_1211C4, (*v2 = v3) == 0) && v4 )
  {
    __enable_irq();
    if ( !v1 )
      goto LABEL_32;
  }
  else if ( !v1 )
  {
LABEL_32:
    patch_check_enable();
    return;
  }
  v5 = (volatile uint32_t *)dword_1211CC;
  v6 = (volatile uint32_t *)dword_1211F8;
  v7 = 0;
  do
  {
    while ( 1 )
    {
      if ( *(volatile uint8_t *)(v1 + 106) != 2 )
        goto LABEL_7;
      v8 = (uint8_t)(*(volatile uint8_t *)(v1 + 225) - 1);
      *(volatile uint8_t *)(v1 + 225) = v8;
      if ( v8 )
        goto LABEL_7;
      v9 = *(volatile uint32_t **)dword_1211D0;
      *(volatile uint8_t *)(v1 + 225) = *(volatile uint8_t *)(v1 + 224);
      if ( !v9 )
        break;
      while ( v9 != (volatile uint32_t *)(v1 + 48) )
      {
        v9 = (volatile uint32_t *)*v9;
        if ( !v9 )
          goto LABEL_15;
      }
      alloc_tx_event(aNextTbttTooClo);
LABEL_7:
      v1 = *(volatile uint32_t *)v1;
      if ( !v1 )
        goto LABEL_26;
    }
LABEL_15:
    mmio_reg_addr(v1);
    bt_scan_poll((void *)(uintptr_t)(v1), *(volatile uint32_t *)(v1 + 36) + 3048);
    v10 = 32 * *v5;
    if ( v10 <= 0xBE7 )
      v10 += *(volatile uint16_t *)(v1 + 222) << 10;
    v11 = (*(volatile uint32_t *)0x40501010u) - 3048;
    v12 = v10 + v11;
    if ( *(volatile uint32_t *)(v1 + 72) )
      cfm_dword_get(v1, *(volatile uint32_t *)(v1 + 36), v12);
    if ( *(volatile uint8_t *)(v1 + 1224) )
    {
      mm_timer_set((volatile uint32_t *)(v1 + 24), v12);
    }
    else
    {
      if ( *(volatile uint8_t *)(dword_1211D4 + 0x5A) > 1u )
      {
        for ( i = *(volatile int ***)(dword_1211D4 + 0x10); i; i = (volatile int **)*i )
        {
          if ( *((volatile uint8_t *)i + 8) == *(volatile uint8_t *)(v1 + 107) )
          {
            v26 = *(volatile uint16_t *)(v1 + 222);
            v27 = *(volatile uint32_t *)(v1 + 36);
            v28 = (int)i[1];
            v29 = v27 + (v26 << 10);
            v30 = v26 << 10;
            if ( v28 == v29 )
            {
              i[1] = (volatile int *)v12;
              v28 = v12;
              v30 = *(volatile uint16_t *)(v1 + 222) << 10;
            }
            if ( v27 + 2 * v30 == v28 )
              i[1] = (volatile int *)(v30 + v12);
          }
        }
      }
      if ( *(volatile uint8_t *)dword_1211D8 && (*(volatile uint32_t *)(v0 + 0x10) & 0xFFFF00) == 0x10000 && (uint16_t)*v6 > 0x14u )
      {
        v14 = (*(volatile uint32_t *)0x40501010u);
        v15 = *(volatile uint8_t *)dword_1211E8;
        v16 = v15 == 2;
        v17 = v15 > 2;
        v18 = (uint16_t)*v6;
        if ( v17 )
        {
          mm_timer_set((volatile uint32_t *)dword_1211EC, v14 + 500 * v18);
        }
        else
        {
          if ( v16 )
            v19 = 250;
          else
            v19 = 200;
          mm_timer_set((volatile uint32_t *)dword_1211EC, v14 + v19 * v18);
        }
      }
      *(volatile uint32_t *)(v1 + 36) = v12;
    }
    if ( *(volatile uint8_t *)(v1 + 412) == 1 )
      v7 = v1;
    v1 = *(volatile uint32_t *)v1;
  }
  while ( v1 );
LABEL_26:
  patch_check_enable();
  if ( *(volatile uint8_t *)(dword_1211DC + 0x19D) )
  {
    if ( v7 )
    {
      v13 = dword_1211E0;
      if ( *(volatile uint8_t *)(dword_1211E0 + 0xF) )
      {
        if ( hci_cmd_handler(4u) != 1 )
        {
          if ( !*(volatile uint8_t *)(v13 + 0xE)
            || (v20 = (uint8_t)(*(volatile uint8_t *)(v13 + 0xE) - 1), *(volatile uint8_t *)(v13 + 0xE) = v20, !v20) )
          {
            v21 = *(volatile uint16_t *)(v7 + 222);
            v22 = *(volatile uint32_t *)(v13 + 0x10);
            v23 = (*(volatile uint32_t *)0x40501010u);
            v24 = (volatile uint32_t *)dword_1211F4;
            *(volatile uint32_t *)(v13 + 0x1C) = v7;
            *(volatile uint8_t *)(v13 + 0xE) = *(volatile uint8_t *)(v13 + 0xF);
            mm_timer_set(v24, v23 + ((unsigned int)((v21 << 10) - v22) >> 1));
          }
        }
      }
    }
  }
}


// jump_0x12abc8 @ 0x1211fc
/* luna: Returns the ACL flag value for the supplied argument. */
int jump_0x12abc8(int a1) {
  return get_acl_flag(a1);
}



// ll_tx_setup @ 0x121200
int ll_tx_setup(int a1, int a2) {
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

  v2 = dword_1212B8;
  v3 = (void *)(uintptr_t)(off_1212BC);
  v4 = (void *)(uintptr_t)(off_1212D0);
  v5 = (void *)(uintptr_t)(off_1212D4);
  v6 = (void *)(uintptr_t)(off_1212C0);
  v7 = (volatile uint16_t *)(dword_1212B8 + 696 * a1);
  *(volatile uint32_t *)off_1212BC = v7[19] | (v7[20] << 16);
  v8 = (void *)(uintptr_t)(off_1212C4);
  v3[1] = v7[21];
  v9 = (volatile int *)off_1212C8;
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
      v12 = (void *)(uintptr_t)(off_1212CC);
      v13 = (void *)(uintptr_t)(off_1212C8);
      *(volatile uint32_t *)off_1212BC = -1;
      *v12 = -1;
      *v9 = ((uint8_t)v11 << 16) | 0x40000000;
      while ( (*v13 & 0x40000000) != 0 )
        ;
      v14 = (volatile uint16_t *)(v2 + 696 * a1);
      *(volatile uint32_t *)off_1212BC = v14[19] | (v14[20] << 16);
      *(volatile uint32_t *)off_1212CC = v14[21];
    }
  }
  v15 = (void *)(uintptr_t)(off_1212C8);
  *(volatile uint32_t *)off_1212C8 = (16 * a2) | (v10 << 16) | 0x40000002;
  while ( (*v15 & 0x40000000) != 0 )
    ;
  return (uint8_t)(a1 + 16);
}



// ll_parse_pdu @ 0x1212d8
/* luna: Installs a pairwise or group Wi-Fi key and updates the associated hardware key state. */
int ll_parse_pdu(volatile char *a1, int a2, int a3, int a4) {
  unsigned int sta_idx_or_group_marker; // r7
  int key_index; // r5
  int key_table_slot; // r6
  volatile uint32_t *v8; // r2
  volatile uint16_t *sta_key_entry; // r7
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

  sta_idx_or_group_marker = (uint8_t)a1[1];
  key_index = (uint8_t)a1[41];
  if ( sta_idx_or_group_marker == 255 )
  {
    if ( a1[40] == 5 )
    {
      v25 = HIBYTE(*(volatile uint32_t *)off_121528) - 3 + (uint8_t)*a1 + 2 * key_index;
      key_table_slot = (uint8_t)v25;
      get_bss_by_channel((volatile uint8_t *)a1, v25);
      return key_table_slot;
    }
    v18 = *a1;
    v19 = (void *)(uintptr_t)(off_121500);
    *(volatile uint32_t *)off_1214FC = -1;
    *v19 = -1;
    key_table_slot = (uint8_t)(v18 + 4 * key_index);
    check_feature_flag(256, "add gtk:%d,%d\r\n", (uint8_t)a1[41], (uint8_t)a1[40]);
    get_bss_by_channel((volatile uint8_t *)a1, key_table_slot);
  }
  else
  {
    if ( **(volatile int16_t **)off_1214F0 < 0 && sta_idx_or_group_marker > 0x23 )
      irq_disable_mmio_write((int)aStaIdxStaMax, (int)aMmSecMachwkeyW, 1424);
    key_table_slot = (uint8_t)(sta_idx_or_group_marker + 16);
    check_feature_flag(256, "add ptk:%d,%d\r\n", sta_idx_or_group_marker, (uint8_t)a1[40]);
    set_connection_flag((int)a1, sta_idx_or_group_marker + 16);
    v8 = (void *)(uintptr_t)(off_121500);
    sta_key_entry = (volatile uint16_t *)(dword_1214F8 + 696 * sta_idx_or_group_marker);
    *(volatile uint32_t *)off_1214FC = sta_key_entry[19] | (sta_key_entry[20] << 16);
    *v8 = sta_key_entry[21];
  }
  switch ( a1[40] )
  {
    case 0:
      v20 = (void *)(uintptr_t)(off_12150C);
      *(volatile uint32_t *)off_12150C = *((volatile uint32_t *)a1 + 2);
      v20[1] = *((volatile uint32_t *)a1 + 3);
      v20[2] = *((volatile uint32_t *)a1 + 4);
      v20[3] = *((volatile uint32_t *)a1 + 5);
      v13 = 256;
      v14 = 0;
      break;
    case 1:
      v10 = (void *)(uintptr_t)(off_12150C);
      *(volatile uint32_t *)off_12150C = *((volatile uint32_t *)a1 + 2);
      v10[1] = *((volatile uint32_t *)a1 + 3);
      v10[2] = *((volatile uint32_t *)a1 + 4);
      v11 = *(volatile uint8_t **)off_121510;
      *(volatile uint32_t *)off_121514 = *((volatile uint32_t *)a1 + 5);
      if ( (*v11 & 1) != 0 )
      {
        v12 = (void *)(uintptr_t)(off_121518);
        *(volatile uint32_t *)off_121518 = *((volatile uint32_t *)a1 + 6);
        v12[1] = *((volatile uint32_t *)a1 + 7);
        v12[2] = *((volatile uint32_t *)a1 + 8);
        v12[3] = *((volatile uint32_t *)a1 + 9);
      }
      else
      {
        *(volatile uint32_t *)off_121524 &= ~1u;
      }
      v13 = 512;
      v14 = 4096;
      break;
    case 2:
      v15 = (void *)(uintptr_t)(off_12150C);
      *(volatile uint32_t *)off_12150C = *((volatile uint32_t *)a1 + 2);
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
      v24 = (void *)(uintptr_t)(off_12150C);
      *(volatile uint32_t *)off_12150C = *((volatile uint32_t *)a1 + 2);
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
      v21 = (void *)(uintptr_t)(off_12150C);
      *(volatile uint32_t *)off_12150C = *((volatile uint32_t *)a1 + 2);
      v21[1] = *((volatile uint32_t *)a1 + 3);
      v21[2] = *((volatile uint32_t *)a1 + 4);
      v21[3] = *((volatile uint32_t *)a1 + 5);
      v14 = 0x2000;
LABEL_20:
      v22 = (void *)(uintptr_t)(off_121518);
      *(volatile uint32_t *)off_121518 = *((volatile uint32_t *)a1 + 6);
      v22[1] = *((volatile uint32_t *)a1 + 7);
      v22[2] = *((volatile uint32_t *)a1 + 8);
      v22[3] = *((volatile uint32_t *)a1 + 9);
      break;
    default:
      if ( **(volatile int16_t **)off_1214F0 < 0 )
        irq_disable_mmio_write(off_121530, (int)aMmKeyRamParamG, 159);
      v13 = 0;
      v14 = 4096;
LABEL_22:
      v23 = (void *)(uintptr_t)(off_12150C);
      *(volatile uint32_t *)off_12150C = *((volatile uint32_t *)a1 + 2);
      v23[1] = *((volatile uint32_t *)a1 + 3);
      v23[2] = *((volatile uint32_t *)a1 + 4);
      v23[3] = *((volatile uint32_t *)a1 + 5);
      break;
  }
  v16 = (void *)(uintptr_t)(off_12151C);
  *(volatile uint32_t *)off_12151C = (16 * key_index) | (4 * (uint8_t)a1[42]) | v13 | (key_table_slot << 16) | v14 | 0x40000000;
  while ( (*v16 & 0x40000000) != 0 )
    ;
  return key_table_slot;
}


// rf_get_version @ 0x121534
volatile uint32_t * rf_get_version(int a1) {
  int v2; // r1
  volatile uint32_t *v3; // r5
  volatile uint32_t *v4; // r2
  volatile int *v5; // r1
  volatile uint32_t *v6; // r5
  volatile uint32_t *result; // r0
  int v8; // r5
  int v9; // r6
  volatile uint32_t *v10; // r2

  if ( (unsigned int)a1 > HIBYTE(*(volatile uint32_t *)off_1215FC) )
    return (volatile uint32_t *)get_sta_by_idx(
                       dword_121604 + 1320 * ((a1 - (HIBYTE(*(volatile uint32_t *)off_1215FC) + 1)) / 2),
                       (((uint8_t)a1 - 1 - HIBYTE(*(volatile uint32_t *)off_1215FC)) & 1) + 4);
  if ( (unsigned int)a1 > 0xF )
  {
    v8 = dword_121620 + 696 * (uint8_t)(a1 - 16);
    v9 = *(volatile uint8_t *)(v8 + 34);
    result = (volatile uint32_t *)reset_rx_control_fields(v8);
    if ( *(volatile uint8_t *)(dword_121604 + 1320 * v9 + 106) == 2 )
      return result;
    v10 = (void *)(uintptr_t)(off_121608);
    *(volatile uint32_t *)off_121600 = *(volatile uint16_t *)(v8 + 38) | (*(volatile uint16_t *)(v8 + 40) << 16);
    *v10 = *(volatile uint16_t *)(v8 + 42);
  }
  else
  {
    v2 = dword_121604;
    v3 = (void *)(uintptr_t)(off_121608);
    *(volatile uint32_t *)off_121600 = -1;
    *v3 = -1;
    get_sta_by_idx(v2 + 1320 * (a1 >> 2), a1 & 3);
  }
  v4 = (void *)(uintptr_t)(off_12160C);
  v5 = (volatile int *)off_121610;
  v6 = (void *)(uintptr_t)(off_121618);
  result = (void *)(uintptr_t)(off_12161C);
  *(volatile uint32_t *)off_121614 = 0;
  *v6 = 0;
  *v4 = 0;
  *result = 0;
  *v5 = (a1 << 16) | 0x40000000;
  while ( (*v5 & 0x40000000) != 0 )
    ;
  return result;
}



// util_delay_clear_flag @ 0x121624
int util_delay_clear_flag() {
  irq_disable_global_3(0x2000000);
  *((volatile uint32_t *)off_121644 + 1) &= ~4u;
  return ke_state_set(0, 0);
}


