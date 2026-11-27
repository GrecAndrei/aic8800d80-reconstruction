// get_device_id @ 0x132178
int get_device_id(volatile uint8_t *a1) {
  int v1; // r3
  int result; // r0
  int v4; // r1
  volatile char *v5; // r3
  volatile char *v6; // r1

  v1 = *a1;
  result = *((volatile uint16_t *)a1 + 1);
  if ( v1 )
  {
    v4 = *((volatile uint8_t *)off_1321D4 + 371);
    v5 = (volatile char *)off_1321D4 + 202;
  }
  else
  {
    v4 = *((volatile uint8_t *)off_1321D4 + 370);
    v5 = (volatile char *)off_1321D4 + 118;
  }
  if ( v4 )
  {
    v6 = &v5[6 * v4];
    while ( *(volatile uint16_t *)v5 != result )
    {
      v5 += 6;
      if ( v5 == v6 )
        goto LABEL_9;
    }
    a1[8] = v5[4];
    a1[9] = v5[3];
  }
  else
  {
LABEL_9:
    if ( **(volatile int16_t **)off_1321D8 < 0 )
      result = log_warning(dword_1321E0, dword_1321DC, 141);
    *((volatile uint16_t *)a1 + 4) = 15;
  }
  return result;
}



// ke_malloc_wrapper @ 0x1321e4
int ke_malloc_wrapper(int a1) {
  volatile uint8_t *v2; // r4

  v2 = (volatile uint8_t *)tx_send_pdu(12, 0, 5, 1u);
  ke_event_schedule_1(a1);
  *v2 = a1;
  rx_process_packet_1((int)v2);
  return mac_write_header_word(5130, 13, 5);
}



// rf_get_calibration @ 0x132320
BOOL rf_get_calibration(int a1, int a2) {
  volatile uint8_t *v2; // r8
  unsigned int v3; // r6
  unsigned int v4; // r5
  int v7; // r3
  int v8; // r2
  int v9; // r3
  unsigned int v10; // r3
  unsigned int v11; // r1
  unsigned int v12; // r0
  unsigned int v13; // r2
  unsigned int v14; // r3
  unsigned int v16; // r2
  unsigned int v17; // r2
  unsigned int v18; // r1

  v2 = (volatile uint8_t *)off_132458;
  v3 = *((volatile uint8_t *)off_132458 + 373);
  v4 = *((volatile uint8_t *)off_132458 + 372);
  if ( (*(volatile uint8_t *)off_132450 & 8) == 0 )
  {
    alloc_tx_event(a8800d40HtVhtPa);
    v3 = v3 != 0;
  }
  v7 = *(volatile uint32_t *)(a1 + 4);
  if ( (v7 & 0x20) != 0 )
  {
    v8 = *(volatile uint8_t *)(a1 + 258);
    v9 = v8 >> 1;
    if ( (v8 & 0x10) != 0 )
    {
      v10 = 4;
    }
    else
    {
      if ( (v9 & 4) == 0 )
      {
        if ( (v9 & 2) != 0 )
        {
          v11 = (*(volatile uint8_t *)(a1 + 260) & 8) != 0;
          v10 = 2;
        }
        else
        {
          v10 = (v8 >> 1) & 1;
          v11 = (*(volatile uint8_t *)(a1 + 260) & 8) != 0;
        }
LABEL_7:
        v4 = v2[116];
        v12 = (v12 & ~0xFFFFu) | ((uint16_t)(*(volatile uint16_t *)(a1 + 208)) & 0xFFFFu);
        if ( v4 >= v11 )
          v4 = (v4 & ~0xFFu) | ((uint8_t)(v11) & 0xFFu);
LABEL_9:
        v13 = v3;
        if ( v3 >= v10 )
          v13 = v10;
        *(volatile uint8_t *)(a1 + 308) = v13;
        v14 = *(volatile uint8_t *)(a2 + 165);
        if ( v14 != 4 )
          goto LABEL_12;
        if ( v13 == 4 )
          goto LABEL_37;
LABEL_31:
        v14 = (v14 & ~0xFFu) | ((uint8_t)(v13) & 0xFFu);
        if ( v13 >= 2 )
          v14 = (v14 & ~0xFFu) | ((uint8_t)(2) & 0xFFu);
        goto LABEL_15;
      }
      v10 = 3;
    }
    v11 = (*(volatile uint8_t *)(a1 + 260) >> 3) & (*(volatile uint8_t *)(a1 + 265) >> 7);
    goto LABEL_7;
  }
  if ( (v7 & 4) != 0 )
  {
    v16 = *(volatile uint32_t *)(a1 + 240);
    if ( (v16 & 0xC) == 4 )
    {
      v10 = 3;
    }
    else if ( (v16 & 0xC) == 8 )
    {
      v10 = 4;
    }
    else
    {
      v10 = 2;
    }
    v17 = (v16 >> 8) & 7;
    if ( v17 > 4 )
    {
      v12 = (v12 & ~0xFFFFu) | ((uint16_t)(*(volatile uint16_t *)(a1 + 208)) & 0xFFFFu);
      v4 = (v4 & ~0xFFu) | ((uint8_t)(0) & 0xFFu);
    }
    else
    {
      v12 = (v12 & ~0xFFFFu) | ((uint16_t)(*(volatile uint16_t *)(a1 + 208)) & 0xFFFFu);
      if ( v4 >= v17 )
        v4 = (v4 & ~0xFFu) | ((uint8_t)(v17) & 0xFFu);
    }
    goto LABEL_9;
  }
  v12 = *(volatile uint16_t *)(a1 + 208);
  v18 = (v12 >> 8) & 3;
  if ( (v12 & 2) != 0 )
  {
    v13 = v3;
    if ( v3 )
      v13 = 1;
    *(volatile uint8_t *)(a1 + 308) = v13;
    v14 = *(volatile uint8_t *)(a2 + 165);
    if ( v4 >= v18 )
      v4 = (v12 >> 8) & 3;
    if ( v14 != 4 )
    {
LABEL_12:
      if ( v14 >= v13 )
        v14 = v13;
      if ( v14 != 4 )
        goto LABEL_15;
LABEL_37:
      v14 = (v14 & ~0xFFu) | ((uint8_t)(3) & 0xFFu);
      goto LABEL_15;
    }
    goto LABEL_31;
  }
  *(volatile uint8_t *)(a1 + 308) = 0;
  if ( v4 >= v18 )
    v4 = (v12 >> 8) & 3;
  v14 = (v14 & ~0xFFu) | ((uint8_t)(v12 & 2) & 0xFFu);
LABEL_15:
  *(volatile uint8_t *)(a1 + 309) = v14;
  *(volatile uint8_t *)(a1 + 312) = v4;
  return (v12 & 0xC) != 12;
}


// rf_is_state_1 @ 0x13245c
int rf_is_state_1(char a1) {
  int v1; // r0

  v1 = a1 & 3;
  if ( v1 == 1 )
    return 8;
  if ( v1 == 2 )
    return 9;
  return 7;
}



// rf_is_state_2 @ 0x132474
int rf_is_state_2(char a1) {
  int v1; // r0

  v1 = a1 & 3;
  if ( v1 == 1 )
    return 9;
  if ( v1 == 2 )
    return 11;
  return 7;
}



// phy_get_rate_code @ 0x13248c
int phy_get_rate_code(int a1) {
  int v1; // r2
  int result; // r0
  int v4; // r3
  char v5; // r1

  v1 = 14;
  result = 7;
  do
  {
    v4 = (a1 >> v1) & 3;
    v5 = result - 1;
    v1 -= 2;
    if ( v4 != 3 )
      break;
    result = (uint8_t)(result - 1);
  }
  while ( v5 );
  return result;
}



// phy_get_channel_cfg @ 0x1324b4
int phy_get_channel_cfg(volatile uint8_t *a1) {
  if ( a1[3] )
    return 3;
  if ( a1[2] )
    return 2;
  return a1[1] != 0;
}



// clear_module_state @ 0x1324d0
int clear_module_state(int a1) {
  int v1; // r3
  int v2; // zf
  int v3; // r1

  v1 = 0;
  while ( 1 )
  {
    v2 = ((a1 >> v1) & 1) == 0;
    v3 = (uint8_t)v1++;
    if ( !v2 )
      break;
    if ( v1 == 12 )
      return 12;
  }
  return v3;
}



// count_set_bits @ 0x1324ec
/* luna: Returns the index of the highest set bit in the low 12 bits, 12 for zero, or 255 when the input is nonzero but those bits are clear. */
int count_set_bits(int a1) {
  int bit_index; // r3
  int shifted_bit_probe; // r2
  char previous_bit_index; // r1

  if ( !a1 )
    return 12;
  bit_index = 0;
  while ( 1 )
  {
    shifted_bit_probe = a1 >> (11 - bit_index) << 31;
    previous_bit_index = bit_index++;
    if ( shifted_bit_probe < 0 )
      break;
    if ( bit_index == 12 )
      return 255;
  }
  return (uint8_t)(11 - previous_bit_index);
}



// clear_measurements @ 0x132518
int clear_measurements(int result, volatile uint32_t *a2, int a3, volatile uint16_t *a4, volatile int *a5, volatile int *a6, volatile char *a7) {
  unsigned int v7; // r4
  int v8; // r12
  int v9; // r4
  char v10; // r12
  int v11; // r1
  int v12; // r3

  *a4 = 0;
  *a5 = 0;
  *a6 = 0;
  if ( result )
  {
    v7 = *(volatile uint8_t *)(result + 2);
    v8 = (v7 >> 2) & 7;
    v9 = v7 & 3;
    if ( v8 > 2 )
      v10 = 1 << (v8 - 3);
    else
      v10 = 1;
    result = (uint16_t)((1 << (v9 + 13)) - 1);
    *a7 = v10;
    *a4 = result;
    if ( a2 )
    {
      v11 = (*a2 >> 23) & 7;
      v12 = (1 << (v11 + 13)) - 1;
      *a5 = v12;
      if ( a3 )
      {
        if ( v11 == 7 )
          *a6 = (1 << (((*(volatile uint8_t *)(a3 + 3) >> 3) & 3) + 20)) - 1;
        else
          *a6 = v12;
      }
    }
    else if ( a3 )
    {
      if ( v9 == 3 )
        *a6 = (1 << (((*(volatile uint8_t *)(a3 + 3) >> 3) & 3) + 16)) - 1;
      else
        *a6 = (uint16_t)result;
    }
  }
  return result;
}



// cmd_char_validate @ 0x1325b4
int cmd_char_validate(char a1) {
  unsigned int v1; // r3
  int result; // r0

  v1 = a1 & 0x7F;
  if ( v1 > 0x48 )
  {
    if ( v1 == 96 )
    {
      return 10;
    }
    else if ( v1 == 108 )
    {
      return 11;
    }
    else
    {
      return 255;
    }
  }
  else if ( (a1 & 0x7E) != 0 )
  {
    switch ( a1 & 0x7F )
    {
      case 2:
        result = 0;
        break;
      case 4:
        result = 1;
        break;
      case 0xB:
        result = 2;
        break;
      case 0xC:
        result = 4;
        break;
      case 0x12:
        result = 5;
        break;
      case 0x16:
        result = 3;
        break;
      case 0x18:
        result = 6;
        break;
      case 0x24:
        result = 7;
        break;
      case 0x30:
        result = 8;
        break;
      case 0x48:
        result = 9;
        break;
      default:
        return 255;
    }
  }
  else
  {
    return 255;
  }
  return result;
}


// status_code_switch @ 0x132632
int status_code_switch() {
  return 9;
}



// hci_cmd_dispatch @ 0x13264a
int hci_cmd_dispatch() {
  return 7;
}



// hci_cmd_handle @ 0x13264e
int hci_cmd_handle() {
  return 8;
}



// handle_rx_packet @ 0x132654
int handle_rx_packet(volatile uint8_t *a1, int a2) {
  int v2; // r11
  volatile int16_t **v3; // r8
  int v4; // r10
  int v5; // r9
  volatile uint8_t *v8; // r4
  int v9; // r7
  int v10; // r0

  v2 = *a1;
  if ( *a1 )
  {
    v3 = (volatile int16_t **)off_1326D4;
    v4 = dword_1326D8;
    v5 = dword_1326DC;
    v8 = a1;
    v9 = 0;
    while ( 1 )
    {
      if ( a2 && (v8[1] & 0x80u) == 0 )
        goto LABEL_6;
      cmd_char_validate(v8[1]);
      if ( **v3 < 0 )
        break;
      if ( v10 <= 11 )
        goto LABEL_11;
LABEL_6:
      if ( ++v8 - a1 >= v2 )
        return v9;
    }
    if ( v10 > 11 )
    {
      log_warning(v5, v4, 598);
      v2 = *a1;
      goto LABEL_6;
    }
LABEL_11:
    v9 = (uint16_t)(v9 | (1 << v10));
    goto LABEL_6;
  }
  return *a1;
}



// extract_bit_pair @ 0x1326e0
int extract_bit_pair(int a1, int a2) {
  int v2; // r4
  int v3; // r7
  unsigned int v4; // r3
  int v5; // r2
  unsigned int v6; // r5
  unsigned int v7; // r3

  v2 = 0;
  v3 = 0;
  do
  {
    v4 = (a1 >> v2) & 3;
    v5 = v3 & ~(3 << v2);
    v6 = (a2 >> v2) & 3;
    if ( v4 == 3 || v6 == 3 )
      break;
    if ( v4 >= v6 )
      v4 = (a2 >> v2) & 3;
    v7 = v4 << v2;
    v2 += 2;
    v3 = (uint16_t)(v5 | v7);
  }
  while ( v2 != 16 );
  return v3;
}



// get_phy_config_entry @ 0x132720
int get_phy_config_entry(int a1) {
  if ( *(volatile uint8_t *)(dword_132740 + 1320 * a1 + 412) == 1 )
    return 5409;
  else
    return 5153;
}



// rf_read_status_flags @ 0x132744
/* luna: Reads the status word at offset 0xDC and returns bits 29:24 with bit 8 set and bit 9 set when bit 30 is present. */
int rf_read_status_flags(int a1) {
  unsigned int raw_status_word; // r3
  int status_bits; // r0

  raw_status_word = *(volatile uint32_t *)(a1 + 220);
  status_bits = HIBYTE(raw_status_word) & 0x3F;
  if ( (raw_status_word & 0x40000000) != 0 )
    return status_bits | 0x300;
  else
    return status_bits | 0x100;
}



// set_rf_mode_from_status_bytes @ 0x13275c
int set_rf_mode_from_status_bytes(int a1) {
  int v2; // r0
  int v3; // r3
  int v4; // r4
  int v5 = 0; // r0
  char v6; // r2
  int v7; // t1
  int v8; // r0
  int result; // r0

  v2 = *(volatile uint8_t *)(a1 + 192);
  if ( **(volatile int16_t **)off_1327B8 >= 0 )
  {
LABEL_2:
    if ( !v2 )
      goto LABEL_7;
    goto LABEL_3;
  }
  if ( !v2 )
  {
    irq_disable_mmio_write(dword_1327BC, dword_1327C0, 707);
    v2 = *(volatile uint8_t *)(a1 + 192);
    goto LABEL_2;
  }
LABEL_3:
  v3 = a1 + 192;
  v4 = a1 + 192 + v2;
  v5 = 0;
  do
  {
    v7 = *(volatile uint8_t *)++v3;
    v6 = v7;
    if ( (int)(v7 & 0xFFFFFF7F) > v5 )
      v5 = v6 & 0x7F;
  }
  while ( v3 != v4 );
LABEL_7:
  v8 = cmd_char_validate(v5);
  result = rf_set_mode(a1, v8);
  *(volatile uint8_t *)(a1 + 350) = 0;
  return result;
}



// process_rx_event @ 0x1327c4
volatile uint32_t * process_rx_event(int a1) {
  char v1; // r3
  volatile uint32_t *v2; // r6
  volatile int *v3; // r4
  volatile int *v4; // r7
  volatile int *v5; // r9
  volatile int *v7; // r2
  volatile uint32_t *v8; // r12
  volatile uint32_t *v9; // r0
  volatile int *v10; // r11
  int v11; // t1
  int v12; // r0
  volatile uint16_t *v13; // r10
  int v14; // r1
  volatile unsigned int *v15; // r12
  int v16; // r3
  int v17; // r0
  int v18; // t1
  int v19; // r2
  int16_t v20; // r0
  unsigned int v21; // r2
  unsigned int v22; // r8
  unsigned int v23; // lr
  int v24; // r8
  unsigned int v25; // r8
  unsigned int v26; // r0
  unsigned int v27; // lr
  int v28; // r8
  unsigned int v29; // r10
  int16_t v30; // r2
  unsigned int v31; // r3
  int v32; // r0
  int v33; // r3
  int v34; // r8
  volatile unsigned int *v35; // r12
  unsigned int v36; // r2
  unsigned int v37; // t1
  int v38; // r1
  volatile uint32_t *v39; // r8
  volatile unsigned int *v40; // r6
  volatile int *v41; // r10
  volatile int *v42; // r7
  int v43; // r2
  unsigned int v44; // r0
  unsigned int v45; // t1
  int v46; // r4
  int v47; // r3
  unsigned int v48; // r2
  volatile uint32_t *v49; // r2
  int v50; // r1
  int v51; // t1
  int v52; // t1
  volatile int *v53; // r3
  int v54; // r3
  unsigned int v56; // r1
  unsigned int v57; // r2
  int v58; // r0
  unsigned int v59; // r0
  int v60; // r0
  unsigned int v61; // [sp+14h] [bp-50h]
  int a8; // [sp+18h] [bp-4Ch]
  char v63[4]; // [sp+18h] [bp-4Ch]
  int v64; // [sp+1Ch] [bp-48h]
  BOOL v65; // [sp+20h] [bp-44h]
  int v66; // [sp+20h] [bp-44h]
  int v67; // [sp+24h] [bp-40h]
  unsigned int v68; // [sp+24h] [bp-40h]
  volatile uint32_t *v69; // [sp+24h] [bp-40h]
  unsigned int v70; // [sp+28h] [bp-3Ch]
  int v71; // [sp+28h] [bp-3Ch]
  unsigned int v72; // [sp+2Ch] [bp-38h]
  volatile int *v73; // [sp+30h] [bp-34h]
  char v74; // [sp+34h] [bp-30h]
  unsigned int v75; // [sp+3Ch] [bp-28h]
  uint8_t v76[16]; // [sp+40h] [bp-24h] BYREF
  uint32_t v77[5]; // [sp+50h] [bp-14h] BYREF

  v1 = *(volatile uint8_t *)(a1 + 350);
  v2 = *(volatile uint32_t **)(a1 + 336);
  if ( !v1 )
    return v2;
  v70 = v2[15];
  v61 = v2[1];
  v3 = (void *)(v2 + 5);
  v64 = v2[2];
  v4 = (volatile int *)v76;
  v5 = (void *)(v77);
  v7 = (void *)(v2 + 5);
  v8 = (void *)(v76);
  v9 = v77;
  v10 = (void *)(v2 + 9);
  do
  {
    v11 = *v7++;
    *v8++ = v11;
    *v9++ = v7[3];
  }
  while ( v10 != v7 );
  a8 = v1 & 1;
  if ( (v1 & 1) == 0 )
  {
    a8 = (v70 >> 3) & 1;
    goto LABEL_24;
  }
  v12 = *(volatile uint32_t *)(a1 + 340);
  v67 = HIBYTE(((volatile uint32_t *)(uintptr_t)off_132AEC)[89]);
  v75 = *(volatile uint8_t *)(a1 + 312);
  v73 = (void *)(&((volatile uint32_t *)(uintptr_t)off_132AEC)[89]);
  v74 = v1;
  v65 = 0;
  v13 = (volatile uint16_t *)(v12 + 136);
  v72 = 0;
  v14 = 0;
  v15 = (volatile unsigned int *)v76;
  v16 = v12;
  do
  {
    v18 = *v13++;
    v17 = v18;
    if ( !v67 || v14 == 3 )
      v19 = 0x40000000;
    else
      v19 = *((volatile uint8_t *)v73 + v14) << 29;
    v20 = *(volatile uint16_t *)(v16 + 12 * v17 + 10);
    v21 = v20 & 0x3FFF | v19;
    if ( ((v21 >> 11) & 6) != 0 )
    {
      v22 = (v21 >> 11) & 7;
      v23 = v21 & 0x7F;
      if ( v22 == 4 )
      {
        v27 = v23 >> 4;
      }
      else
      {
        if ( v22 <= 4 )
        {
          v27 = (v23 >> 3) & 3;
          if ( v14 )
          {
LABEL_20:
            if ( v65 )
              v65 = v27 == v72;
LABEL_22:
            *v15 = *v15 & 0x1FFFC000 | v21;
            goto LABEL_58;
          }
LABEL_66:
          v59 = v72;
          if ( v27 < v75 )
            v59 = v27;
          v72 = v59;
          v60 = v65;
          if ( v27 < v75 )
            v60 = 1;
          v65 = v60;
          goto LABEL_22;
        }
        if ( (v21 & 0x600) == 0x400 )
          v24 = 0x20000;
        else
          v24 = 0x10000;
        v25 = v77[v14] & 0xFFFCFFFF | v24;
        if ( (v20 & 0x4000) != 0 )
          v26 = v25 | 0x40000;
        else
          v26 = v25 & 0xFFFBFFFF;
        v77[v14] = v26;
        v27 = v23 >> 4;
      }
      if ( v14 )
        goto LABEL_20;
      goto LABEL_66;
    }
    a8 = 0;
    *v15 = *v15 & 0x1FFFC000 | v21;
LABEL_58:
    ++v14;
    ++v15;
  }
  while ( v14 != 4 );
  v56 = v61 & 0xFFFFFE7F;
  v61 &= 0xFFFFFE7F;
  v3 = (void *)(v2 + 5);
  if ( v65 )
    v61 = v56 | ((v72 + 1) << 7);
  if ( a8 )
    v57 = v70 | 8;
  else
    v57 = v70 & 0xFFFFFFF7;
  v1 = v74 | 2;
  v2[15] = v57;
  *(volatile uint8_t *)(a1 + 350) = v74 | 2;
LABEL_24:
  if ( (v1 & 0x20) != 0 )
  {
    v28 = *(volatile uint32_t *)(a1 + 340);
    v29 = v2[9];
    v66 = v2[5];
    v71 = v28 + 12 * *(volatile uint8_t *)(v28 + 164);
    v30 = *(volatile uint16_t *)(v71 + 10);
    v31 = v30 & 0x3FFF | 0x40000000;
    v68 = v31;
    if ( BYTE1(((volatile uint32_t *)(uintptr_t)off_132AEC)[49]) && (v2[5] & 0x387F) != (v31 & 0x387F) )
    {
      v32 = rf_get_tx_power(
              (v31 >> 11) & 7,
              v30 & 0x7F,
              (volatile uint8_t *)(*(volatile uint32_t *)(dword_132AF0 + 1320 * *(volatile uint8_t *)(a1 + 34) + 72) + 4));
      v30 = *(volatile uint16_t *)(v71 + 10);
      v29 = v32 | (v32 << 8) | (HIWORD(v29) << 16);
    }
    v33 = dword_132AF4;
    *(volatile uint32_t *)(v28 + 160) = v29;
    *(volatile uint8_t *)(v28 + 165) = (v30 & 0x4000) != 0;
    *(volatile uint32_t *)(v28 + 156) = v66 & v33 | v68;
    if ( is_id_lt_10(5u, 4u) )
      alloc_tx_event("trial rate/power=(%x,%x)\n", *(volatile uint32_t *)(v28 + 156), v29);
    l2c_sig_hdr_parse((int)v2, *(volatile uint32_t *)(v28 + 156), 0, (v61 & 0x180) != 0, ((v61 >> 7) & 3) - 1, 0, 0, a8);
    v1 = *(volatile uint8_t *)(a1 + 350);
  }
  if ( (v1 & 2) != 0 )
  {
    v34 = dword_132B08;
    v35 = (volatile unsigned int *)v76;
    do
    {
      v37 = *v35++;
      v36 = v37;
      v38 = v37 & v34;
      if ( v37 & 0x7C | (v37 >> 11) & 7 )
        *(v35 - 1) = v38 | *(volatile uint32_t *)(a1 + 344) | (((v36 >> 7) & 3) << 24);
    }
    while ( v77 != v35 );
  }
  if ( (v1 & 0x10) != 0 )
  {
    *(volatile uint32_t *)v63 = dword_132AF0 + 1320 * *(volatile uint8_t *)(a1 + 34);
    v69 = v2;
    v39 = v77;
    v40 = (volatile unsigned int *)v76;
    v41 = v3;
    v42 = (volatile int *)off_132AEC;
    do
    {
      v43 = *((volatile uint8_t *)v42 + 197);
      v45 = *v40++;
      v44 = v45;
      v46 = HIWORD(*v39) << 16;
      *v39++ = v46;
      if ( v43 )
      {
        v58 = rf_get_tx_power((v44 >> 11) & 7, v44 & 0x7F, (volatile uint8_t *)(*(volatile uint32_t *)(*(volatile uint32_t *)v63 + 72) + 4));
        *(v39 - 1) = v46 | v58 | (v58 << 8);
      }
      else if ( **(volatile int16_t **)off_132AFC < 0 )
      {
        irq_disable_mmio_write(off_132BC0, (int)aMeUpdateBuffer, 986);
      }
    }
    while ( v77 != v40 );
    v4 = (volatile int *)v76;
    v2 = v69;
    v1 = *(volatile uint8_t *)(a1 + 350);
    v3 = v41;
  }
  if ( (v1 & 0x40) != 0 )
  {
    v47 = *(volatile uint32_t *)(dword_132AF0 + 1320 * *(volatile uint8_t *)(a1 + 34) + 468);
    v48 = v64 & 0xFC0FFFFF;
    v64 &= 0xFC0FFFFF;
    if ( v47 >= 0 )
      v64 = v48 | ((HIBYTE(v47) & 0x3F) << 20);
  }
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_132B00 = 1;
  }
  v49 = (void *)(uintptr_t)(off_132B04);
  v50 = *(volatile uint32_t *)off_132B04;
  v2[1] = v61;
  v2[2] = v64;
  *v49 = v50 + 1;
  do
  {
    v51 = *v4++;
    *v3++ = v51;
    v52 = *v5++;
    v3[3] = v52;
  }
  while ( v10 != v3 );
  if ( v50 != -1 )
  {
    v53 = (volatile int *)off_132B00;
    *v49 = v50;
    v54 = *v53;
    if ( !v50 )
    {
      if ( v54 )
        __enable_irq();
    }
  }
  *(volatile uint8_t *)(a1 + 350) = 0;
  return v2;
}


// nop_stub @ 0x132bc4
volatile uint32_t * nop_stub(int a1) {
  ((int (*)())l2c_ccb_run)();
  return process_rx_event(a1);
}



// ble_ll_conn_rx_update @ 0x132bd8
int ble_ll_conn_rx_update(int result, volatile uint8_t *a2, int a3) {
  unsigned int v3; // r4
  unsigned int v4; // r2
  int v5; // r1
  unsigned int v6; // r2
  int16_t v7; // r1
  int v8; // r1
  int16_t v9; // r4
  int16_t v10; // r3
  volatile uint8_t *v11; // r3
  int v12; // r2
  int v13; // r1

  v9 = *(volatile uint16_t *)(a3 + 166);
  *(volatile uint16_t *)(a3 + 168) = v9;
  *(volatile uint8_t *)(a3 + 165) = 0;
  *(volatile uint16_t *)(a3 + 170) = 0;
  if ( result )
  {
    if ( !*((volatile uint8_t *)off_132C44 + 373) )
      return result;
    if ( (*(volatile uint8_t *)(result + 3) & 3) != 0 )
    {
      v10 = -10;
      if ( (*(volatile uint8_t *)(result + 3) & 3) == 1 )
        v10 = 10;
      *(volatile uint16_t *)(a3 + 168) = v9 + v10;
      *(volatile uint8_t *)(a3 + 165) = 1;
    }
  }
  if ( a2 )
  {
    if ( *((volatile uint8_t *)off_132C44 + 373) > 1u )
    {
      result = a2[2] & 3;
      if ( (unsigned int)(result - 1) <= 2 )
      {
        v11 = (volatile uint8_t *)(a3 + 164);
        v12 = (uint8_t)a2[4];
        v13 = (uint8_t)a2[3];
        v3 = *v11;
        if ( *v11 )
        {
          if ( v3 == 1 )
          {
            if ( (uint8_t)(v13 - 1) > 0xB0u )
              v3 = 0;
            else
              v3 = 5 * v13 + 5000;
            *((volatile uint16_t *)v11 + 2) = v3;
            if ( (uint8_t)(v12 - 1) <= 0xB0u )
            {
              v4 = 5 * v12 + 5000;
LABEL_25:
              *((volatile uint16_t *)v11 + 3) = v4;
              if ( result != 2 )
              {
                if ( result != 3 )
                {
                  if ( v4 < v3 )
                  {
                    v5 = v3 - v4;
                    goto LABEL_29;
                  }
                  v8 = v4;
LABEL_46:
                  v5 = v8 - v3;
LABEL_29:
                  if ( v5 != 40 )
                  {
                    if ( v5 > 40 && *((volatile uint8_t *)off_13231C + 373) == 4 )
                      goto LABEL_32;
                    goto LABEL_37;
                  }
                  if ( *((volatile uint8_t *)off_13231C + 373) > 2u )
                  {
                    *((volatile uint16_t *)v11 + 2) = v4;
                    v11[1] = 3;
                    *((volatile uint16_t *)v11 + 3) = 0;
                    return 3;
                  }
LABEL_37:
                  v11[1] = 2;
                  *((volatile uint16_t *)v11 + 3) = 0;
                  return result;
                }
                goto LABEL_36;
              }
              goto LABEL_38;
            }
          }
          else
          {
            *((volatile uint16_t *)v11 + 2) = 0;
            v3 = 0;
          }
        }
        else
        {
          if ( (unsigned int)(v13 - 1) <= 0xD )
          {
            if ( v13 == 14 )
              v3 = 2484;
            else
              v3 = 5 * v13 + 2407;
          }
          *((volatile uint16_t *)v11 + 2) = v3;
          if ( v12 && v12 <= 14 )
          {
            if ( v12 == 14 )
            {
              v8 = 2484;
              *((volatile uint16_t *)v11 + 3) = 2484;
              if ( result != 2 )
              {
                if ( result != 3 )
                {
                  v4 = (v4 & ~0xFFFFu) | ((uint16_t)(2484) & 0xFFFFu);
                  goto LABEL_46;
                }
LABEL_36:
                if ( *((volatile uint8_t *)off_13231C + 373) == 4 )
                {
LABEL_32:
                  v11[1] = 4;
                  return result;
                }
                goto LABEL_37;
              }
              goto LABEL_38;
            }
            v4 = 5 * v12 + 2407;
            goto LABEL_25;
          }
        }
        *((volatile uint16_t *)v11 + 3) = 0;
        if ( result != 2 )
        {
          if ( result != 3 )
            goto LABEL_37;
          goto LABEL_36;
        }
LABEL_38:
        if ( *((volatile uint8_t *)off_13231C + 373) <= 2u )
        {
          v6 = *((volatile uint16_t *)v11 + 1);
          v11[1] = 2;
          if ( v6 <= v3 )
            v7 = v3 - 40;
          else
            v7 = v3 + 40;
          *((volatile uint16_t *)v11 + 2) = v7;
        }
        else
        {
          v11[1] = 3;
        }
      }
    }
  }
  return result;
}



// ble_ll_conn_get @ 0x132c48
int ble_ll_conn_get(int a1, unsigned int a2) {
  int v2; // r7
  int v4; // r0
  int v6; // r6
  volatile uint16_t *v7; // r9
  int v8; // r1
  char v9; // r2
  int v10; // r3
  char v11; // r0
  int v12; // r1
  char v13; // r2
  int v14; // r3
  char v15; // r0
  volatile uint8_t *v16; // r4
  unsigned int v17; // r1
  int v18; // r0
  unsigned int v19; // r3
  int result; // r0
  volatile uint16_t *v21; // r9
  int v22; // r3
  int v23; // r2
  char v24; // r0
  int v25; // r3
  char v26; // r1
  int v27; // r1
  char v28; // r2
  int v29; // r3
  char v30; // r0

  v2 = dword_132E58;
  v4 = dword_132E58 + 696 * a1;
  v6 = *(volatile uint8_t *)(v4 + 34);
  if ( (*(volatile uint32_t *)(v4 + 4) & 0x20) != 0 )
  {
    v7 = (volatile uint16_t *)off_132E74;
    if ( **(volatile int16_t **)off_132E5C < 0 && (*((volatile uint8_t *)off_132E74 + 374) & 4) == 0 )
      irq_disable_mmio_write(dword_132E68, dword_132E64, 1328);
    v8 = 14;
    v9 = 7;
    do
    {
      v10 = ((int)*(volatile uint16_t *)(v2 + 696 * a1 + 270) >> v8) & 3;
      v11 = v9 - 1;
      v8 -= 2;
      if ( v10 != 3 )
        break;
      --v9;
    }
    while ( v11 );
    v12 = 14;
    v13 = 7;
    do
    {
      v14 = ((int)v7[40] >> v12) & 3;
      v15 = v13 - 1;
      v12 -= 2;
      if ( v14 != 3 )
        break;
      --v13;
    }
    while ( v15 );
  }
  else
  {
    v21 = (volatile uint16_t *)off_132E74;
    v22 = **(volatile int16_t **)off_132E5C;
    if ( (*(volatile uint32_t *)(v4 + 4) & 4) != 0 )
    {
      if ( v22 < 0 && (*((volatile uint8_t *)off_132E74 + 374) & 2) == 0 )
        irq_disable_mmio_write(dword_132E6C, dword_132E64, 1341);
      v23 = 14;
      v24 = 7;
      do
      {
        v25 = ((int)*(volatile uint16_t *)(v2 + 696 * a1 + 244) >> v23) & 3;
        v26 = v24 - 1;
        v23 -= 2;
        if ( v25 != 3 )
          break;
        --v24;
      }
      while ( v26 );
      v27 = 14;
      v28 = 7;
      do
      {
        v29 = ((int)v21[28] >> v27) & 3;
        v30 = v28 - 1;
        v27 -= 2;
        if ( v29 != 3 )
          break;
        --v28;
      }
      while ( v30 );
    }
    else if ( v22 < 0 && (*((volatile uint8_t *)off_132E74 + 374) & 1) == 0 )
    {
      irq_disable_mmio_write(dword_132E70, dword_132E64, 1352);
    }
  }
  v16 = (volatile uint8_t *)(v2 + 696 * a1);
  v17 = v16[308];
  v18 = v16[35];
  v19 = *(volatile uint8_t *)(dword_132E60 + 1320 * v6 + 413);
  if ( v17 == 4 )
    v17 = 3;
  if ( v17 >= a2 )
    v17 = a2;
  if ( v19 == 4 )
    v19 = 3;
  if ( v19 >= v17 )
    v19 = (v19 & ~0xFFu) | ((uint8_t)(v17) & 0xFFu);
  v16[309] = v19;
  result = ((int (*)())phy_get_channel_data)(v18, (uint8_t)v19, 0);
  v16[350] |= 8u;
  return result;
}



