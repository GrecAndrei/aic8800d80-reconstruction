// rf_calibrate_init @ 0x1331d4
int rf_calibrate_init(int a1, uint16_t a2, int a3) {
  int v4; // r3
  int v5; // r6
  int v6; // r0
  int v7; // r7
  volatile uint8_t *v8; // r4
  unsigned int v9; // r8
  volatile uint8_t *v10; // r9
  uint16_t v11; // r11
  int v12; // r6
  volatile uint8_t *v13; // r11
  volatile uint8_t *v14; // s17
  volatile uint8_t *v15; // r2
  volatile uint8_t *v16; // r1
  int v17; // r0
  int v18; // r6
  int v19; // r3
  int v20; // r1
  int16_t v21; // r3
  volatile int16_t **v22; // r10
  int v23; // r2
  int v24; // r0
  int v25; // r2
  int16_t v26; // r3
  int v27; // r1
  unsigned int v28; // r3
  unsigned int v29; // r6
  int v30; // r2
  unsigned int v31; // r3
  int v32; // r2
  unsigned int v33; // r12
  int v34; // r3
  char v35; // r0
  int v36; // r1
  unsigned int v37; // r2
  int v38; // r3
  char v39; // r0
  int v40; // r0
  int v41; // r1
  int v42; // r0
  int v43; // r2
  char v44; // lr
  int v45; // r0
  int v46; // r1
  char v47; // lr
  unsigned int v48; // r1
  int v49; // r11
  volatile int *v50; // r4
  int v51; // r0
  int v52; // t1
  volatile uint8_t *v53; // r0
  char v54; // r2
  uint16_t v55; // r3
  int v56; // r0
  unsigned int v57; // r3
  int v58; // r3
  int v59; // r0
  volatile int *v60; // r0
  unsigned int v61; // r2
  int v62; // r3
  int v63; // r3
  volatile uint8_t *v64; // r0
  int v65; // r0
  uint64_t v66; // kr00_8
  struct __attribute__((packed)) { unsigned int v67; // [sp+4h] [bp-20h]
  int v68; // [sp+8h] [bp-1Ch]
  union { volatile uint8_t *a2a; // [sp+Ch] [bp-18h]
  volatile uint8_t *a2c; // [sp+Ch] [bp-18h]
  volatile uint8_t *a2b; }; // [sp+Ch] [bp-18h]
  char _pad3[4]; union { int a1a; // [sp+14h] [bp-10h]
  volatile uint8_t *a1b; }; // [sp+14h] [bp-10h]
  char _pad4[7]; uint8_t v75[5]; // [sp+1Fh] [bp-5h] BYREF
  } _frame;
  v4 = *(volatile uint32_t *)(a1 + 468);
  v5 = *(volatile uint8_t *)(a1 + 464);
  v6 = *(volatile uint8_t *)(a1 + 412);
  v7 = *(volatile uint16_t *)(a1 + 462);
  v8 = *(volatile uint8_t **)(a1 + 240);
  v9 = *(volatile uint8_t *)(a1 + 413);
  _frame.v68 = v5;
  *(volatile uint16_t *)(a1 + 462) = 0;
  _frame.v67 = v4 & 0xFF000000;
  v10 = (volatile uint8_t *)(a3 + 36);
  v11 = a2 - 36;
  if ( v6 )
    goto LABEL_2;
  v12 = v11;
  v53 = memmove_2_1(v10, v11);
  if ( !v53 )
    goto LABEL_2;
  v54 = v53[2];
  v55 = *(volatile uint16_t *)(a1 + 462) & 0xFFF8;
  if ( (v54 & 1) != 0 )
    v55 |= 1u;
  *(volatile uint16_t *)(a1 + 462) = v55;
  if ( (v54 & 4) != 0 )
    *(volatile uint16_t *)(a1 + 462) |= 4u;
  else
LABEL_2:
    v12 = v11;
  if ( (*(volatile uint32_t *)(a1 + 472) & 1) != 0 )
  {
    v49 = *(volatile uint8_t *)(a1 + 106);
    if ( !*(volatile uint8_t *)(a1 + 106) )
    {
      rf_get_cal_status((void *)(uintptr_t)((int)v10), v12, a1 + 440, _frame.v75);
      if ( _frame.v75[0] )
      {
        _frame.a2b = v8;
        v50 = (volatile int *)(a1 + 440);
        do
        {
          v51 = bt_buf_alloc(26, 0, 5, 8);
          v52 = *v50++;
          *(volatile uint32_t *)v51 = v52;
          *(volatile uint8_t *)(v51 + 5) = v49;
          *(volatile uint8_t *)(v51 + 6) = *(volatile uint8_t *)(a1 + 107);
          ++v49;
          *(volatile uint8_t *)(v51 + 4) = 0;
          hci_evt_send(v51);
        }
        while ( v49 != 4 );
        v8 = _frame.a2b;
      }
    }
  }
  v13 = (void *)(uintptr_t)(off_133644);
  if ( (*((volatile uint8_t *)off_133644 + 374) & 1) == 0 )
  {
    v14 = (volatile uint8_t *)(*((volatile uint8_t *)off_133644 + 374) & 1);
    _frame.a2a = v14;
LABEL_6:
    llm_adv_reset((int)v14, _frame.a2a, a1 + 248);
    goto LABEL_7;
  }
  v14 = parse_data_8(v10, v12);
  if ( (v13[374] & 6) != 0 )
  {
    _frame.a2a = parse_data_9(v10, v12);
    if ( !*(volatile uint8_t *)(a1 + 106) )
    {
      v64 = sub_12de48(v10, v12);
      if ( v64
        && (*(volatile uint32_t *)(dword_1337B0 + 696 * *(volatile uint8_t *)(a1 + 116) + 4) & 0x24) != 0
        && (v64[2] & 0x80u) == 0 )
      {
        ((int (*)())rf_config_chan_table)(*(volatile uint8_t *)(a1 + 116), v64[2] & 3, v64[2] >> 4);
      }
      if ( (*(volatile uint32_t *)(a1 + 472) & 8) != 0 )
      {
        _frame.a1b = (volatile uint8_t *)bt_buf_alloc(109, 0, 5, 2);
        rf_phy_unpack((void *)(uintptr_t)((int)v10), v12, _frame.a1b);
        hci_evt_send((int)_frame.a1b);
        rf_get_cal_status2((void *)(uintptr_t)((int)v10), v12, a1 + 348, _frame.v75);
        if ( _frame.v75[0] )
        {
          v65 = bt_buf_alloc(107, 0, 5, 16);
          v66 = *(volatile uint64_t *)(a1 + 352);
          *(volatile uint32_t *)v65 = *(volatile uint32_t *)(a1 + 348);
          *(volatile uint32_t *)(v65 + 12) = *(volatile uint32_t *)(a1 + 360);
          *(volatile uint64_t *)(v65 + 4) = v66;
          hci_evt_send(v65);
        }
      }
    }
    if ( (v13[374] & 4) == 0 )
      goto LABEL_6;
    v56 = (int)(uintptr_t)(rf_set_cal_u32_dc((void *)(uintptr_t)((int)v10), v12, a1 + 248));
    if ( v56 )
    {
      v57 = *(volatile uint32_t *)(a1 + 468);
      _frame.a1a = (v57 >> 4) & 0x3FF;
      if ( *(volatile uint8_t *)(a1 + 106) == 2 )
      {
        v58 = v57 | 0x10000;
        *(volatile uint32_t *)(a1 + 468) = v58;
        *(volatile uint32_t *)(v56 + 3) = v58;
      }
      if ( !_frame.a1a )
        goto LABEL_116;
    }
    else
    {
      _frame.a1a = (_frame.a1a & ~0xFFFFu) | ((uint16_t)(1023) & 0xFFFFu);
    }
    v59 = bt_buf_alloc(111, 0, 5, 4);
    *(volatile uint16_t *)v59 = _frame.a1a;
    *(volatile uint8_t *)(v59 + 2) = *(volatile uint8_t *)(a1 + 107);
    hci_evt_send(v59);
LABEL_116:
    if ( (*(volatile uint32_t *)(a1 + 468) & 0xFF000000) != _frame.v67 )
    {
      v60 = (volatile int *)bt_buf_alloc(113, 0, 5, 4);
      v61 = *(volatile uint32_t *)(a1 + 468);
      v62 = HIBYTE(v61) & 0x3F;
      if ( (v61 & 0x40000000) != 0 )
        v63 = v62 | 0x300;
      else
        v63 = v62 | 0x100;
      *v60 = v63;
      hci_evt_send((int)v60);
    }
    goto LABEL_6;
  }
  llm_adv_reset((int)v14, nullptr, a1 + 248);
LABEL_7:
  v15 = (volatile uint8_t *)(uint8_t)rf_parse_cal_entry((void *)(uintptr_t)((int)v10), v12, _frame.v75, a1 + 1212);
  if ( v15 )
  {
    if ( *(volatile uint8_t *)(a1 + 106) )
    {
      if ( *(volatile uint8_t *)(a1 + 106) == 2 )
        *(volatile uint8_t *)(a1 + 231) = (uint8_t)v15;
    }
    else
    {
      v16 = (volatile uint8_t *)*(volatile uint8_t *)(a1 + 146);
      if ( *(volatile uint8_t *)(a1 + 146)
        || *(volatile uint8_t *)(a1 + 148)
        && _frame.v75[0] == 1
        && (_frame.a2c = v15,
            mmio_write_phy(*(volatile uint8_t *)(a1 + 107), (char)v16),
            v16 = (volatile uint8_t *)*(volatile uint8_t *)(a1 + 146),
            v15 = _frame.a2c,
            *(volatile uint8_t *)(a1 + 146)) )
      {
        if ( v15 != v16 )
          *(volatile uint8_t *)(a1 + 148) = 1;
      }
      *(volatile uint8_t *)(a1 + 146) = (uint8_t)v15;
    }
  }
  v17 = (int)(uintptr_t)(rf_set_cal_byte_d8((void *)(uintptr_t)((int)v10), v12, a1 + 248));
  if ( *(volatile uint8_t *)(a1 + 464) != _frame.v68 )
    v17 = scan_rssi_compare(a1);
  if ( *(volatile uint8_t *)(a1 + 413) > v9 )
  {
    if ( !*(volatile uint32_t *)(a1 + 72) )
      rx_packet_handler_2(a3, 32, 1, 0);
    v18 = bt_buf_alloc(59, 0, 5, 12);
    v19 = *(volatile uint32_t *)(a1 + 72);
    if ( **(volatile int16_t **)off_133628 < 0 && !v19 )
    {
      mmio_irq_clear((int)aVifChanCtxtNul, (int)aMeChanCtxtUpda, 70);
      v19 = *(volatile uint32_t *)(a1 + 72);
    }
    *(volatile uint8_t *)v18 = *(volatile uint8_t *)(v19 + 24);
    v20 = *(volatile uint32_t *)(a1 + 416);
    v21 = *(volatile uint16_t *)(a1 + 420);
    *(volatile uint32_t *)(v18 + 2) = *(volatile uint32_t *)(a1 + 412);
    *(volatile uint32_t *)(v18 + 6) = v20;
    *(volatile uint16_t *)(v18 + 10) = v21;
    v17 = (int)hci_evt_send(v18);
  }
  if ( v8 )
  {
    v22 = (volatile int16_t **)off_133628;
    while ( 1 )
    {
      v23 = *(volatile uint16_t *)(a1 + 462);
      if ( v23 != v7 )
      {
        ke_event_schedule_1("curr=%x, bss=%x\r\n", v7, v23);
        v24 = (uint8_t)v8[35];
        v25 = *(volatile uint16_t *)(a1 + 462) << 29;
        v26 = (uint8_t)v8[350] | 2;
        v27 = 0;
        v8[350] = v26;
        if ( v25 >= 0 )
          v26 = 1024;
        *((volatile uint32_t *)v8 + 86) = 0;
        if ( v25 >= 0 )
        {
          *((volatile uint16_t *)v8 + 174) = v26;
          v27 = 1;
        }
        else
        {
          *((volatile uint16_t *)v8 + 174) = 0;
        }
        v17 = fetch_connection_params(v24, v27);
      }
      v28 = *(volatile uint8_t *)(a1 + 413);
      if ( v28 != v9 )
        break;
LABEL_48:
      if ( (*(volatile uint32_t *)(a1 + 468) & 0xFF000000) != _frame.v67 && (*((volatile uint32_t *)v8 + 1) & 0x20) != 0 )
        v8[350] |= 0x40u;
      v8 = *(volatile uint8_t **)v8;
      if ( !v8 )
        return v17;
    }
    v29 = (uint8_t)v8[308];
    if ( v28 == 4 )
    {
      if ( v29 <= 3 )
      {
        if ( v29 >= 2 )
          v29 = 2;
LABEL_38:
        if ( (uint8_t)v8[309] != v29 )
        {
          v30 = *((volatile uint32_t *)v8 + 1);
          v31 = v30 & 0x20;
          if ( (v30 & 0x20) != 0 )
          {
            if ( **v22 < 0 && (v13[374] & 4) == 0 )
              mmio_irq_clear((int)aLocalCapaHe, (int)aMePolTblBwUpd, 463);
            v32 = 14;
            v33 = 7;
            do
            {
              v34 = ((int)*((volatile uint16_t *)v8 + 135) >> v32) & 3;
              v35 = v33 - 1;
              v32 -= 2;
              if ( v34 != 3 )
                break;
              v33 = (uint8_t)(v33 - 1);
            }
            while ( v35 );
            v36 = 14;
            v37 = 7;
            while ( 1 )
            {
              v38 = ((int)*((volatile uint16_t *)v13 + 40) >> v36) & 3;
              v39 = v37 - 1;
              v36 -= 2;
              if ( v38 != 3 )
                break;
              v37 = (uint8_t)(v37 - 1);
              if ( !v39 )
                goto LABEL_47;
            }
            if ( v37 >= v33 )
              v37 = v33;
          }
          else if ( (v30 & 4) != 0 )
          {
            if ( **v22 < 0 && (v13[374] & 2) == 0 )
            {
              mmio_irq_clear((int)aLocalCapaVht, (int)aMePolTblBwUpd, 476);
              v31 = 0;
            }
            v41 = 14;
            v42 = 7;
            while ( 1 )
            {
              v43 = ((int)*((volatile uint16_t *)v8 + 122) >> v41) & 3;
              v44 = v42 - 1;
              v41 -= 2;
              if ( v43 != 3 )
                break;
              v42 = (uint8_t)(v42 - 1);
              if ( !v44 )
                goto LABEL_62;
            }
            v31 = v42;
LABEL_62:
            v45 = 14;
            v37 = 7;
            while ( 1 )
            {
              v46 = ((int)*((volatile uint16_t *)v13 + 28) >> v45) & 3;
              v47 = v37 - 1;
              v45 -= 2;
              if ( v46 != 3 )
                break;
              v37 = (uint8_t)(v37 - 1);
              if ( !v47 )
                goto LABEL_47;
            }
            if ( v37 >= v31 )
              v37 = (v37 & ~0xFFu) | ((uint8_t)(v31) & 0xFFu);
            v37 = (uint8_t)v37;
          }
          else
          {
            if ( **v22 < 0 && (v13[374] & 1) == 0 )
              mmio_irq_clear((int)aLocalCapaHt, (int)aMePolTblBwUpd, 487);
            if ( v8[214] )
            {
              v48 = 3;
            }
            else if ( v8[213] )
            {
              v48 = 2;
            }
            else
            {
              v48 = (uint8_t)v8[212];
              if ( v8[212] )
                v48 = 1;
            }
            if ( v13[18] )
            {
              v37 = 3;
            }
            else if ( v13[17] )
            {
              v37 = 2;
            }
            else
            {
              v37 = (uint8_t)v13[16];
              if ( v13[16] )
                v37 = 1;
            }
            if ( v37 >= v48 )
              v37 = v48;
          }
LABEL_47:
          v40 = (uint8_t)v8[35];
          v8[309] = v29;
          v17 = get_connection_state(v40, v29, v37);
          v8[350] |= 8u;
        }
        goto LABEL_48;
      }
    }
    else
    {
      if ( v28 >= v29 )
        v28 = (uint8_t)v8[308];
      if ( v28 != 4 )
      {
        v29 = (uint8_t)v28;
        goto LABEL_38;
      }
    }
    v29 = 3;
    goto LABEL_38;
  }
  return v17;
}


// event_dispatch_by_type @ 0x1337b4
int event_dispatch_by_type(int result, int a2, int a3, volatile uint8_t *a4) {
  unsigned int v4; // r4
  unsigned int v5; // r2
  int v6; // r1
  unsigned int v7; // r2
  int16_t v8; // r1
  int v9; // r1

  if ( (unsigned int)(result - 1) > 2 )
    return result;
  v4 = *a4;
  if ( *a4 )
  {
    if ( v4 == 1 )
    {
      if ( (uint8_t)(a2 - 1) > 0xB0u )
        v4 = 0;
      else
        v4 = 5 * a2 + 5000;
      *((volatile uint16_t *)a4 + 2) = v4;
      if ( (uint8_t)(a3 - 1) <= 0xB0u )
      {
        v5 = 5 * a3 + 5000;
LABEL_15:
        *((volatile uint16_t *)a4 + 3) = v5;
        if ( result != 2 )
        {
          if ( result != 3 )
          {
            if ( v5 < v4 )
            {
              v6 = v4 - v5;
              goto LABEL_19;
            }
            v9 = v5;
LABEL_36:
            v6 = v9 - v4;
LABEL_19:
            if ( v6 != 40 )
            {
              if ( v6 > 40 && *((volatile uint8_t *)off_132678 + 373) == 4 )
                goto LABEL_22;
              goto LABEL_27;
            }
            if ( *((volatile uint8_t *)off_132678 + 373) > 2u )
            {
              *((volatile uint16_t *)a4 + 2) = v5;
              a4[1] = 3;
              *((volatile uint16_t *)a4 + 3) = 0;
              return 3;
            }
LABEL_27:
            a4[1] = 2;
            *((volatile uint16_t *)a4 + 3) = 0;
            return result;
          }
          goto LABEL_26;
        }
        goto LABEL_28;
      }
    }
    else
    {
      *((volatile uint16_t *)a4 + 2) = 0;
      v4 = 0;
    }
  }
  else
  {
    if ( (unsigned int)(a2 - 1) <= 0xD )
    {
      if ( a2 == 14 )
        v4 = 2484;
      else
        v4 = 5 * a2 + 2407;
    }
    *((volatile uint16_t *)a4 + 2) = v4;
    if ( a3 && a3 <= 14 )
    {
      if ( a3 == 14 )
      {
        v9 = 2484;
        *((volatile uint16_t *)a4 + 3) = 2484;
        if ( result != 2 )
        {
          if ( result != 3 )
          {
            v5 = (v5 & ~0xFFFFu) | ((uint16_t)(2484) & 0xFFFFu);
            goto LABEL_36;
          }
LABEL_26:
          if ( *((volatile uint8_t *)off_132678 + 373) == 4 )
          {
LABEL_22:
            a4[1] = 4;
            return result;
          }
          goto LABEL_27;
        }
        goto LABEL_28;
      }
      v5 = 5 * a3 + 2407;
      goto LABEL_15;
    }
  }
  *((volatile uint16_t *)a4 + 3) = 0;
  if ( result != 2 )
  {
    if ( result != 3 )
      goto LABEL_27;
    goto LABEL_26;
  }
LABEL_28:
  if ( *((volatile uint8_t *)off_132678 + 373) <= 2u )
  {
    v7 = *((volatile uint16_t *)a4 + 1);
    a4[1] = 2;
    if ( v7 <= v4 )
      v8 = v4 - 40;
    else
      v8 = v4 + 40;
    *((volatile uint16_t *)a4 + 2) = v8;
  }
  else
  {
    a4[1] = 3;
  }
  return result;
}



// hash_mix_words @ 0x1337cc
volatile uint32_t * hash_mix_words(volatile uint32_t *result, volatile int *a2, int a3) {
  int v3; // r2
  int v4; // r4
  unsigned int v5; // r2
  unsigned int v6; // r3
  unsigned int v7; // r2
  int v8; // r3
  unsigned int v9; // r2
  int v10; // r3

  v3 = a3 ^ *result;
  v4 = *a2 ^ __ROR4__(v3, 15);
  v5 = v3 + v4;
  v6 = ((v5 >> 8) & 0xFF00FF | (v5 << 8) & 0xFF00FF00) ^ v4;
  v7 = v5 + v6;
  v8 = v6 ^ __ROR4__(v7, 29);
  v9 = v7 + v8;
  v10 = v8 ^ __ROR4__(v9, 2);
  *a2 = v10;
  *result = v9 + v10;
  return result;
}



// assemble_bt_descriptor @ 0x133800
volatile uint32_t * assemble_bt_descriptor(int a1, volatile uint32_t *a2, int a3, volatile uint16_t *a4, uint8_t a5) {
  int v5; // r7
  int v6; // r5
  int v7; // r6
  int v8; // r2
  int v9; // r6
  int v10; // r4

  v5 = *a4;
  v6 = *(volatile uint32_t *)(a4 + 1);
  v7 = *(volatile uint16_t *)(a3 + 4);
  v8 = *(volatile uint32_t *)a3;
  *(volatile uint32_t *)a1 = *a2;
  *(volatile uint32_t *)(a1 + 4) = a2[1];
  *(volatile uint32_t *)(a1 + 8) = 0;
  *(volatile uint8_t *)(a1 + 12) = 0;
  v9 = v7 | (v5 << 16);
  if ( a5 == 255 )
    v10 = 0;
  else
    v10 = a5 & 7;
  hash_mix_words((volatile uint32_t *)a1, (volatile int *)(a1 + 4), v8);
  hash_mix_words((volatile uint32_t *)a1, (volatile int *)(a1 + 4), v9);
  hash_mix_words((volatile uint32_t *)a1, (volatile int *)(a1 + 4), v6);
  hash_mix_words((volatile uint32_t *)a1, (volatile int *)(a1 + 4), v10);
  return (volatile uint32_t *)a1;
}



// unaligned_memcpy @ 0x13384c
volatile uint32_t * unaligned_memcpy(volatile uint32_t *result, int a2, unsigned int a3) {
  volatile unsigned int *v3; // r6
  char v4; // r1
  unsigned int v5; // r7
  int v6; // r12
  int v7; // r5
  unsigned int v8; // r3
  volatile uint32_t *v9; // r6
  unsigned int v10; // r1
  volatile uint32_t *v11; // r9
  unsigned int v12; // r11
  unsigned int v13; // r8
  unsigned int v14; // r7
  int v15; // r4
  int v16; // r5
  int v17; // r10
  volatile int *v18; // r1
  volatile unsigned int *v19; // r8
  volatile unsigned int *v20; // r9
  unsigned int v21; // r3
  int v22; // r2
  int v23; // r7
  int v24; // r2
  unsigned int v25; // r3
  unsigned int v26; // r7
  int v27; // r4
  unsigned int v28; // r3
  int v29; // r2
  char v30; // r2
  int v31; // r12
  int v32; // r2
  int v33; // [sp+4h] [bp-8h]

  v3 = (volatile unsigned int *)(a2 & 0xFFFFFFFC);
  v4 = a2 & 3;
  v5 = *v3;
  v6 = *((volatile uint8_t *)result + 12);
  v7 = result[2];
  v8 = (uint8_t)(4 - v4);
  v9 = (void *)(v3 + 1);
  v10 = v5 >> (8 * v4);
  v11 = v9;
  if ( a3 >= v8 )
  {
    v14 = a3 - v8;
    v13 = (a3 - v8) >> 2;
    a3 = v8;
    v12 = v14 & 0xFFFFFFFC;
  }
  else
  {
    v12 = 0;
    v10 &= 0xFFFFFFFF >> (8 * (4 - a3));
    v13 = 0;
    v14 = 0;
  }
  v15 = v6 + a3;
  if ( v6 + a3 > 3 )
  {
    v30 = 8 * v6;
    v31 = 8 * (4 - v6);
    v32 = (v10 << v30) | v7;
    if ( v31 == 32 )
      v16 = 0;
    else
      v16 = v10 >> v31;
    v15 -= 4;
    result = hash_mix_words(result, (void *)(result + 1), v32);
  }
  else
  {
    v16 = v7 | (v10 << (8 * v6));
  }
  if ( v13 )
  {
    v17 = 8 * (4 - v15);
    v18 = (void *)(result + 1);
    v33 = v13;
    v19 = (void *)(&v9[v13]);
    v20 = (void *)(v9);
    do
    {
      v21 = *v20;
      v22 = (*v20++ << (8 * v15)) | v16;
      if ( v17 == 32 )
        v16 = 0;
      else
        v16 = v21 >> v17;
      result = hash_mix_words(result, v18, v22);
    }
    while ( v20 != v19 );
    v11 = &v9[v33];
  }
  if ( v14 <= v12 )
    goto LABEL_20;
  v23 = v14 & 3;
  v24 = 8 * (4 - v23);
  if ( v24 == 32 )
  {
    v25 = 0;
  }
  else
  {
    v25 = (0xFFFFFFFF >> v24) & *v11;
    v16 |= v25 << (8 * v15);
  }
  v26 = v23 + v15;
  if ( v26 > 3 )
  {
    v27 = 8 * (4 - v15);
    if ( v27 == 32 )
      v28 = 0;
    else
      v28 = v25 >> v27;
    v29 = v16;
    v15 = (v15 & ~0xFFu) | ((uint8_t)(v26 - 4) & 0xFFu);
    v16 = v28;
    result = hash_mix_words(result, (void *)(result + 1), v29);
LABEL_20:
    result[2] = v16;
    *((volatile uint8_t *)result + 12) = v15;
    return result;
  }
  result[2] = v16;
  *((volatile uint8_t *)result + 12) = v26;
  return result;
}



// bt_process_rx_data @ 0x133988
volatile uint32_t * bt_process_rx_data(int a1) {
  int v1; // r5
  unsigned int v2; // r2
  volatile uint32_t *v4; // r0
  volatile int *v5; // r1

  v1 = *(volatile uint32_t *)(a1 + 8);
  v2 = *(volatile uint8_t *)(a1 + 12);
  if ( **(volatile int16_t **)off_1339CC < 0 && v2 > 3 )
  {
    mmio_irq_clear(dword_1339D4, dword_1339D0, 321);
    v2 = (v2 & ~0xFFu) | ((uint8_t)(*(volatile uint8_t *)(a1 + 12)) & 0xFFu);
  }
  hash_mix_words((volatile uint32_t *)a1, (volatile int *)(a1 + 4), (90 << (8 * v2)) | v1);
  hash_mix_words((volatile uint32_t *)a1, (volatile int *)(a1 + 4), 0);
  return (volatile uint32_t *)a1;
}



// bt_poll_controller @ 0x1339d8
int bt_poll_controller(int value) {
  int v2; // r0

  if ( **(volatile int16_t **)off_133A0C >= 0 || (value = hci_cmd_send_short(6u), value == 10) )
  {
    check_fw_ready(value);
    return 0;
  }
  else
  {
    v2 = mmio_irq_clear(dword_133A14, dword_133A10, 1038);
    check_fw_ready(v2);
    return 0;
  }
}



// rf_check_status @ 0x133a18
int rf_check_status(int a1, int a2) {
  if ( **(volatile int16_t **)off_133A54 >= 0 || hci_cmd_send_short(6u) == 7 )
  {
    hci_vendor_get_state(a2);
    return 1;
  }
  else
  {
    mmio_irq_clear(dword_133A5C, dword_133A58, 1012);
    hci_vendor_get_state(a2);
    return 1;
  }
}



// ipc_send_command @ 0x133a60
int ipc_send_command(int a1, int a2, int16_t a3, int16_t a4) {
  int v5; // r0
  int16_t v6; // r1
  int16_t v7; // r2
  int16_t v10; // [sp+0h] [bp-8h]
  int16_t v12; // [sp+4h] [bp-4h]

  v5 = hci_cmd_send_short(6u);
  v6 = a4;
  v7 = a3;
  if ( v5 == 6 )
  {
    v10 = a3;
    v12 = v6;
    hci_vendor_cmd_dispatch(*(volatile uint16_t *)(a2 + 2));
    v7 = v10;
    v6 = v12;
  }
  hci_evt_alloc_send(6156, v6, v7);
  return 0;
}



// rx_parse_descriptor @ 0x133a98
int rx_parse_descriptor(int a1, int a2) {
  int v2; // r3

  v2 = *(volatile uint16_t *)(a2 + 2) & 0xFC;
  switch ( v2 )
  {
    case 176:
      if ( hci_cmd_send_short(6u) == 5 )
        hci_vendor_read_rf_cache((void *)(uintptr_t)(a2));
      break;
    case 16:
    case 48:
      if ( hci_cmd_send_short(6u) == 8 )
        hci_vendor_read_rf((void *)(uintptr_t)(a2));
      break;
    case 192:
    case 160:
      return rf_check_channel_10(a2);
    default:
      if ( v2 == 208 && *(volatile uint8_t *)(a2 + 12) == 8 )
        rf_get_power_by_index(a2);
      break;
  }
  return 0;
}



// rf_stop @ 0x133afc
int rf_stop(int a1) {
  int v2; // r0

  if ( **(volatile int16_t **)off_133B30 >= 0 || (a1 = hci_cmd_send_short(6u), a1 == 10) )
  {
    check_hw_ready_status(a1);
    return 0;
  }
  else
  {
    v2 = mmio_irq_clear(dword_133B38, dword_133B34, 898);
    check_hw_ready_status(v2);
    return 0;
  }
}



// bt_stop @ 0x133b3c
int bt_stop(int a1) {
  int v2; // r0

  if ( **(volatile int16_t **)off_133B70 >= 0 || (a1 = hci_cmd_send_short(6u), a1 == 10) )
  {
    check_hw_ready_status(a1);
    return 0;
  }
  else
  {
    v2 = mmio_irq_clear(dword_133B78, dword_133B74, 871);
    check_hw_ready_status(v2);
    return 0;
  }
}



