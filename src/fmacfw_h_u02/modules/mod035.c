// patch_init_check @ 0x125970
int patch_init_check(int result) {
  unsigned int v1; // r4
  int v2; // r5
  int v3; // r6
  int v4; // r5
  unsigned int v5; // r9
  volatile uint8_t *v6; // r4
  unsigned int v7; // r7
  unsigned int v8; // r8
  unsigned int v9; // r5
  unsigned int v10; // r3
  int v11; // cc
  int v12; // r2
  unsigned int v13; // r3
  int v14; // r1
  volatile uint8_t *v15; // r10
  int v16; // r7
  volatile uint8_t *v17; // r11
  unsigned int v18; // r5
  volatile uint16_t *v19; // r0
  unsigned int v20; // r8
  int i; // r10
  volatile uint32_t *v22; // r0
  volatile uint8_t *v23; // r0
  unsigned int v24; // r8
  volatile uint32_t *v25; // r0

  v1 = dword_125B64;
  v2 = *(volatile uint32_t *)(dword_125B64 + 4);
  v3 = result;
  if ( **(volatile int16_t **)dword_125B60 >= 0 || v2 )
  {
    v4 = v2 - 1;
    *(volatile uint32_t *)(dword_125B64 + 4) = v4;
    if ( !v4 )
    {
LABEL_20:
      v15 = (volatile uint8_t *)dword_125B90;
      check_config_flag();
      v16 = *(volatile uint8_t *)(v3 + 107) + 32;
      if ( *v15 )
      {
        v23 = (volatile uint8_t *)tx_send_pdu(74, 13, v4, 4);
        *v23 = v16;
        v23[1] = v4;
        v23[2] = v4;
        rx_process_packet_1((int)v23);
        v5 = dword_125B68;
        if ( *v15 )
        {
          v24 = dword_125B68 + 696 * v16;
          if ( (*(volatile uint8_t *)(v24 + 53) & 2) != 0 )
          {
            *(volatile uint8_t *)(v24 + 54) = 9;
            is_ll_event_pending(v3, v5 + 696 * v16, v4);
            *(volatile uint8_t *)(v24 + 54) = v4;
          }
          *v15 = 0;
        }
      }
      else
      {
        v5 = dword_125B68;
      }
      v17 = (volatile uint8_t *)dword_125B94;
      if ( *(volatile uint8_t *)dword_125B94 )
      {
        v20 = v5 + 696 * v16;
        for ( i = 0; i != 4; ++i )
        {
          while ( *(volatile uint32_t *)(v20 + 584) )
          {
            v22 = list_pop(v20 + 584);
            phy_txpower_calc((unsigned int)v22, (uint8_t)i);
          }
          if ( *(volatile uint32_t *)(v20 + 624) )
          {
            v25 = list_pop(v5 + 8 * (87 * v16 + 78 + i));
            phy_txpower_calc((unsigned int)v25, (uint8_t)i);
            alloc_tx_event(aThisWilleNever);
            while ( 1 )
              ;
          }
          v20 += 8;
        }
        *v17 = 0;
      }
      if ( *(volatile uint8_t *)(v1 + 0xA) )
        bt_task_init(*(volatile uint32_t *)v1);
      if ( *(volatile uint32_t *)(v1 + 0xC) )
      {
        v18 = dword_125B80;
        do
        {
          v19 = (volatile uint16_t *)list_pop(v18);
          rx_pkt_parse(v19 + 6);
        }
        while ( *(volatile uint32_t *)(v1 + 0xC) );
      }
      result = *(volatile uint8_t *)(v3 + 107);
      if ( *(volatile uint8_t *)(v1 + result + 20) && !*(volatile uint32_t *)(v1 + 4) )
        result = bt_config_check(result, *(volatile uint8_t *)(v1 + result + 20));
      if ( *(volatile uint8_t *)(v3 + 231) == 1 )
        result = (int)alloc_ctrl_block(v3);
      goto LABEL_4;
    }
  }
  else
  {
    result = irq_disable_mmio_write((int)aMmBcnEnvTxCfm_0, (int)aMmBcnTransmitt, 764);
    v4 = *(volatile uint32_t *)(v1 + 4) - 1;
    *(volatile uint32_t *)(v1 + 4) = v4;
    if ( !v4 )
      goto LABEL_20;
  }
  v5 = dword_125B68;
LABEL_4:
  v6 = (volatile uint8_t *)dword_125B68;
  v7 = dword_125B6C;
  v8 = dword_125B8C;
  v9 = dword_125B68 + 22272;
  do
  {
    while ( 1 )
    {
      if ( v6[37] && v3 == v7 + 1320 * v6[34] )
      {
        v10 = v6[35];
        v11 = v10 > 0x23;
        if ( v10 > 0x23 )
        {
          v12 = 0;
        }
        else
        {
          v12 = 696;
          v10 = v5 + 696 * v10;
        }
        if ( !v11 )
          v12 = *(volatile uint32_t *)(v10 + 664);
        v13 = v8 - (*(volatile uint32_t *)0x40501010u);
        if ( (int)(v13 + v12) < 0 )
        {
          result = phy_lock(v3);
          if ( result )
          {
            result = phy_get_channel(v6[35], off_125B70, (int)v6);
            if ( !result )
              break;
          }
        }
      }
      v6 += 696;
      if ( v6 == (volatile uint8_t *)v9 )
        return result;
    }
    v14 = v6[35];
    v6 += 696;
    result = alloc_tx_event("apm send null to probe sta: sta_idx=%d\n", v14);
  }
  while ( v6 != (volatile uint8_t *)v9 );
  return result;
}


// util_get_state @ 0x125b98
volatile char * util_get_state(int a1, char a2) {
  volatile char *result; // r0

  if ( !*((volatile uint32_t *)off_125BB0 + 1) )
    return (volatile char *)bt_config_check(a1, a2);
  result = (volatile char *)off_125BB0 + a1;
  result[20] = a2;
  return result;
}



// util_diff32 @ 0x125bb4
unsigned int util_diff32(volatile unsigned int *a1, volatile unsigned int *a2, volatile unsigned int *a3, unsigned int a4) {
  unsigned int v4; // r5
  volatile unsigned int *v5; // lr
  unsigned int v6; // r4
  unsigned int v7; // r7
  unsigned int v8; // r12
  unsigned int v9; // r5
  unsigned int v10; // r3
  unsigned int v11; // r3
  unsigned int v12; // r4
  unsigned int v13; // r5
  unsigned int v14; // r1
  unsigned int result; // r0
  unsigned int v16; // r0
  unsigned int v17; // r0

  v4 = *a1 - *a2;
  if ( (v4 & 0x80000000) != 0 )
  {
    v4 = *a2 - *a1;
    v5 = a1;
  }
  else
  {
    v5 = a2;
  }
  if ( a4 < v4 )
  {
    v6 = a4 + *v5;
    do
    {
      v4 -= a4;
      v7 = v5[1] - *v5 + v6;
      v8 = v6;
      v6 += a4;
    }
    while ( a4 < v4 );
    *v5 = v8;
    v5[1] = v7;
  }
  if ( v4 > a4 >> 1 )
  {
    v9 = *v5 + a4;
    v10 = a4 + v5[1];
    *v5 = v9;
    v5[1] = v10;
  }
  v11 = a1[1];
  v12 = a2[1];
  if ( (int)(v11 - v12) < 0 )
  {
    if ( a3 )
    {
      v13 = *a1;
      v14 = *a2;
      a3[1] = v12;
      if ( (int)(v13 - v14) < 0 )
      {
        result = v12 - v13;
        goto LABEL_13;
      }
      result = v12 - v14;
      goto LABEL_18;
    }
    v17 = *a1;
    if ( (int)(v17 - *a2) < 0 )
      return v12 - v17;
    else
      return v12 - *a2;
  }
  else
  {
    if ( a3 )
    {
      v13 = *a1;
      v14 = *a2;
      a3[1] = v11;
      if ( (int)(v13 - v14) < 0 )
      {
        result = v11 - v13;
LABEL_13:
        *a3 = v13;
        return result;
      }
      result = v11 - v14;
LABEL_18:
      *a3 = v14;
      return result;
    }
    v16 = *a1;
    if ( (int)(v16 - *a2) >= 0 )
      return v11 - *a2;
    else
      return v11 - v16;
  }
}



// ipc_post_msg @ 0x125c58
int ipc_post_msg(int a1) {
  volatile uint8_t *v2; // r0
  volatile uint32_t *v3; // r2

  v2 = (volatile uint8_t *)tx_send_pdu(72, *(volatile uint16_t *)(a1 + 14), 0, 2);
  v2[1] = *(volatile uint8_t *)(a1 + 24);
  v3 = (void *)(uintptr_t)(off_125C84);
  *v2 = *(volatile uint8_t *)(a1 + 26);
  *v3 &= ~4u;
  return (int)(uintptr_t)(rx_process_packet_1((int)(uintptr_t)(v2)));
}



// util_list_len @ 0x125c88
BOOL util_list_len(int a1, int a2) {
  int v3; // r4
  int v4; // r0
  int v5; // r5
  int v6; // r6
  int v7; // r0

  v3 = *(volatile uint32_t *)(a1 + 4);
  v4 = get_timeout_1000();
  v5 = *(volatile uint32_t *)(a2 + 4);
  v6 = v4;
  v7 = get_timeout_1000();
  return v3 - v5 < 0 && v5 - 14000 - v3 - v6 < 0 || v5 - v3 < 0 && v3 - v5 - 14000 - v7 < 0 || v3 == v5;
}



// scan_entry_lookup @ 0x125cd0
int scan_entry_lookup(int result) {
  int v1; // r6
  int v2; // r4
  int v3; // r3
  int v4; // r5
  int v5; // r4
  volatile int *v6; // r3
  int v7; // r1

  v1 = dword_125D30;
  v2 = *(volatile uint8_t *)(result + 1225);
  v3 = dword_125D30 + 140 * v2;
  v4 = result;
  if ( !*(volatile uint8_t *)(v3 + 32) && *(volatile uint8_t *)(v3 + 16) )
    result = ((int (*)(void))lll_conn_ready_check)();
  v5 = v1 + 140 * v2;
  if ( !*(volatile uint8_t *)(v5 + 80) && *(volatile uint8_t *)(v5 + 64) )
    result = ((int (*)())lll_conn_ready_check)(v4, 1);
  v6 = *((volatile int **)off_125D34 + 2);
  if ( v6 )
  {
    v7 = *(volatile uint8_t *)(v4 + 107);
    result = 255;
    do
    {
      if ( *((volatile uint8_t *)v6 + 86) == v7 )
        *((volatile uint8_t *)v6 + 86) = -1;
      v6 = (volatile int *)*v6;
    }
    while ( v6 );
  }
  return result;
}



// rf_mode_setup @ 0x125d38
volatile uint32_t * rf_mode_setup(volatile uint32_t *result) {
  volatile int16_t **v1; // r9
  int v2; // r3
  int v3; // r2
  int v4; // zf
  int v5; // r2
  int v6; // r2
  int v7; // r3
  int v8; // r1
  int v9; // r6
  unsigned int v10; // r11
  int v11; // r7
  int v12; // r3
  int v13; // r3
  int v14; // zf
  volatile char *v15; // r4
  int v16; // r5
  uint64_t v17; // r0
  unsigned int v18; // r8
  unsigned int v19; // r2
  int v20; // r0
  volatile uint32_t *v21; // r5
  char v22; // r1
  int v23; // r4
  unsigned int v24; // r2
  volatile char *v25; // r1
  int v26; // r3
  volatile uint32_t *v27; // r4
  volatile uint32_t *v28; // r10
  volatile unsigned int *v29; // r4
  int v30; // r11
  unsigned int v31; // r7
  int v32; // r0
  uint64_t v33; // kr00_8
  unsigned int v34; // r5
  int v35; // r0
  int v36; // r1
  int v37; // r7
  unsigned int i; // r3
  int v39; // r6
  char v40; // r7
  int j; // r5
  unsigned int v42; // r3
  unsigned int v43; // r2
  unsigned int v44; // r3
  int v45; // r3
  int v46; // r0
  volatile uint8_t *v47; // r2
  char v48; // r3
  volatile uint32_t *v49; // r2
  int v50; // r4
  unsigned int v51; // r2
  volatile uint32_t *v52; // r4
  int v53; // r3
  volatile uint32_t *v54; // r2
  int v55; // r0
  unsigned int v56; // r0
  unsigned int v57; // r2
  unsigned int v58; // r1
  int v59; // r5
  uint64_t v60; // kr08_8
  int v61; // r5
  int v62; // r3
  int v63; // r2
  int v64; // r2
  int v65; // r2
  struct __attribute__((packed)) { union { unsigned int v66; // [sp+14h] [bp-58h]
  int v67; }; // [sp+14h] [bp-58h]
  union { unsigned int v68; // [sp+18h] [bp-54h]
  int v69; }; // [sp+18h] [bp-54h]
  int v70; // [sp+1Ch] [bp-50h]
  int v71; // [sp+20h] [bp-4Ch]
  union { unsigned int v72; // [sp+24h] [bp-48h]
  int v73; }; // [sp+24h] [bp-48h]
  unsigned int v74; // [sp+28h] [bp-44h]
  unsigned int v75; // [sp+2Ch] [bp-40h]
  volatile uint32_t *v76; // [sp+30h] [bp-3Ch] BYREF
  volatile char *v77; // [sp+34h] [bp-38h]
  int v78; // [sp+38h] [bp-34h] BYREF
  int v79; // [sp+3Ch] [bp-30h]
  char v80; // [sp+40h] [bp-2Ch] BYREF
  char _pad12[7]; char v81; // [sp+48h] [bp-24h] BYREF
  char _pad13[31]; uint32_t var4[2]; // [sp+68h] [bp-4h] BYREF
  int vars4; // [sp+70h] [bp+4h]
  int vars8; // [sp+74h] [bp+8h]
  } _frame;
  _frame.v71 = (int)result;
  if ( *((volatile uint8_t *)off_12604C + 90) <= 1u )
    return result;
  v1 = (volatile int16_t **)off_126060;
  if ( **(volatile int16_t **)off_126060 < 0 )
  {
    v53 = *(volatile uint8_t *)(result[18] + 27);
    if ( v53 != 255 && *((volatile uint8_t *)result + 107) != v53 )
      irq_disable_mmio_write(dword_1262DC, dword_1262D8, 691);
  }
  scan_entry_lookup(_frame.v71);
  v2 = *(volatile uint32_t *)(_frame.v71 + 72);
  *(volatile uint8_t *)(v2 + 27) = *(volatile uint8_t *)(_frame.v71 + 107);
  v3 = *(volatile uint8_t *)(_frame.v71 + 106);
  if ( *(volatile uint8_t *)(_frame.v71 + 106) )
  {
    v4 = v3 == 2;
    if ( v3 == 2 )
      v3 = _frame.v71;
    result = (void *)(uintptr_t)(off_126050);
    if ( v4 )
      v5 = *(volatile uint16_t *)(v3 + 222);
    else
      v5 = 102400;
    if ( v4 )
      v5 <<= 10;
    _frame.v74 = v5;
    v6 = *(volatile uint8_t *)(v2 + 24);
    v7 = v6 + 1;
    if ( v6 != 2 )
    {
LABEL_12:
      v8 = 8 * v7;
      if ( LOBYTE(result[7 * v7 + 6]) == 255 )
      {
        v7 = v6 + 2;
        if ( v6 == 1 )
          v7 = 0;
        goto LABEL_15;
      }
      goto LABEL_16;
    }
  }
  else
  {
    result = (void *)(uintptr_t)(off_1262E4);
    _frame.v74 = *(volatile uint32_t *)(dword_1262E0 + 696 * *(volatile uint8_t *)(_frame.v71 + 116) + 8);
    v6 = *(volatile uint8_t *)(v2 + 24);
    v7 = v6 + 1;
    if ( v6 != 2 )
      goto LABEL_12;
  }
  if ( *((volatile uint8_t *)result + 24) == 255 )
  {
    v7 = 1;
LABEL_15:
    v8 = 8 * v7;
    if ( LOBYTE(result[7 * v7 + 6]) == 255 )
    {
      if ( **v1 < 0 )
        irq_disable_mmio_write(dword_1262FC, dword_1262D8, 698);
      __und(0xFFu);
    }
    goto LABEL_16;
  }
  v7 = 0;
  v8 = 0;
LABEL_16:
  v9 = *((volatile uint32_t *)off_126054 + 2);
  _frame.v68 = BYTE1(result[v8 - v7 + 6]);
  if ( !v9 )
    return result;
  v10 = 0;
  v11 = 0;
  do
  {
    while ( 1 )
    {
      v12 = *(volatile uint32_t *)(v9 + 72);
      if ( !v12 || v12 == *(volatile uint32_t *)(_frame.v71 + 72) )
        goto LABEL_18;
      v13 = *(volatile uint8_t *)(v9 + 106);
      if ( *(volatile uint8_t *)(v9 + 106) )
      {
        v14 = v13 == 2;
        if ( v13 == 2 )
          v13 = *(volatile uint16_t *)(v9 + 222);
        else
          v10 = 102400;
        if ( v14 )
          v10 = v13 << 10;
      }
      else
      {
        v10 = *(volatile uint32_t *)(dword_1262E0 + 696 * *(volatile uint8_t *)(v9 + 116) + 8);
      }
      if ( 2 * _frame.v74 <= v10 )
        v10 /= v10 / _frame.v74;
      _frame.v72 = (v10 >> 1) / _frame.v68;
      if ( get_timeout_1000() + 14000 <= _frame.v72 )
        break;
      _frame.v72 = get_timeout_1000() + 14000;
      if ( v11 )
        goto LABEL_31;
LABEL_59:
      if ( **v1 < 0 )
      {
        if ( v11 == 2 )
        {
          result = (volatile uint32_t *)irq_disable_mmio_write(dword_1262F8, dword_1262D8, 755);
          v65 = **v1;
          _frame.var4[0] = v10;
          _frame.var4[1] = _frame.v72;
          _frame.vars4 = *(volatile uint32_t *)(v9 + 36);
          _frame.vars8 = _frame.vars4 + 10000;
          v50 = 8;
          if ( v65 >= 0 )
            goto LABEL_61;
        }
        else
        {
          result = *(volatile uint32_t **)(v9 + 36);
          v54 = &_frame.var4[5 * v11];
          *(v54 - 10) = v10;
          *(v54 - 9) = _frame.v72;
          *(v54 - 8) = (int)(uintptr_t)(result);
          *(v54 - 7) = (int)(uintptr_t)(result + 2500);
          v50 = 4 * v11;
        }
        v51 = *(volatile uint8_t *)(v9 + 107);
        if ( v51 <= 0x1F )
          goto LABEL_62;
        result = (volatile uint32_t *)irq_disable_mmio_write(dword_1262F0, dword_1262D8, 761);
      }
      else
      {
        result = *(volatile uint32_t **)(v9 + 36);
        v49 = &_frame.var4[5 * v11];
        *(v49 - 10) = v10;
        *(v49 - 9) = _frame.v72;
        *(v49 - 8) = (int)(uintptr_t)(result);
        *(v49 - 7) = (int)(uintptr_t)(result + 2500);
        v50 = 4 * v11;
      }
LABEL_61:
      v51 = (v51 & ~0xFFu) | ((uint8_t)(*(volatile uint8_t *)(v9 + 107)) & 0xFFu);
LABEL_62:
      v52 = &_frame.var4[v50 + v11++];
      *(v52 - 6) = 1 << v51;
LABEL_18:
      v9 = *(volatile uint32_t *)v9;
      if ( !v9 )
        goto LABEL_39;
    }
    if ( !v11 )
      goto LABEL_59;
LABEL_31:
    v15 = &_frame.v80;
    v16 = 0;
    while ( 1 )
    {
      if ( *(volatile uint32_t *)v15 == v10 )
      {
        _frame.v76 = *(volatile uint32_t **)(v9 + 36);
        v17 = *((volatile uint64_t *)v15 + 1);
        _frame.v78 = *((volatile uint32_t *)v15 + 2);
        _frame.v79 = HIDWORD(v17);
        _frame.v77 = (volatile char *)(_frame.v76 + 2500);
        v18 = util_diff32((volatile unsigned int *)&_frame.v76, (volatile unsigned int *)&_frame.v78, (volatile unsigned int *)&_frame.v76, v10);
        if ( **v1 < 0 && _frame.v68 <= 1 )
          irq_disable_mmio_write(dword_1262E8, dword_1262D8, 735);
        v19 = _frame.v68 * _frame.v72 / (_frame.v68 - 1) - 4000 - get_timeout_1000();
        if ( v19 < *((volatile uint32_t *)v15 + 1) )
          v19 = *((volatile uint32_t *)v15 + 1);
        if ( v19 > v18 )
          break;
      }
      ++v16;
      v15 += 20;
      if ( v11 == v16 )
        goto LABEL_59;
    }
    _frame.v66 = v19;
    v20 = get_timeout_1000();
    v21 = &_frame.var4[5 * v16];
    v22 = *(volatile uint8_t *)(v9 + 107);
    v9 = *(volatile uint32_t *)v9;
    v23 = 1 << v22;
    v24 = _frame.v66 + v20;
    result = _frame.v76;
    v25 = _frame.v77;
    v26 = *(v21 - 6) | v23;
    v27 = v21 - 8;
    *v27 = (int)(uintptr_t)(_frame.v76);
    v27[1] = (int)(uintptr_t)(v25);
    *(v21 - 9) = v24 + 4000;
    *(v21 - 6) = v26;
  }
  while ( v9 );
LABEL_39:
  if ( !v11 )
    return result;
  v28 = (void *)(uintptr_t)(off_126064);
  _frame.v70 = v9;
  _frame.v73 = v9;
  _frame.v69 = v9;
  v29 = (volatile unsigned int *)&_frame.v81;
  _frame.v67 = v11;
  v30 = v9;
  while ( 2 )
  {
    v31 = *(v29 - 2);
    if ( !(v31 % _frame.v74) )
    {
      v55 = v28[4] + 32 * *(volatile uint32_t *)off_1262F4;
      if ( v31 >= _frame.v74 )
        v31 = _frame.v74;
      _frame.v78 = v28[4] + 32 * *(volatile uint32_t *)off_1262F4;
      _frame.v79 = v55 + 10000;
      v56 = util_diff32(v29, (volatile unsigned int *)&_frame.v78, 0, v31);
      v57 = v29[1];
      if ( (int)(*v29 - _frame.v78) >= 0 )
        v58 = v31 - v56;
      else
        v58 = _frame.v78 - v57;
      v59 = *(v29 - 1) + *v29 - 2000 - v57;
      _frame.v75 = v58;
      if ( get_timeout_1000() + 4000 > v59 )
        v59 = get_timeout_1000() + 4000;
      v60 = *((volatile uint64_t *)v29 - 1);
      v61 = v59 - _frame.v75;
      v62 = v60 - 14000 - HIDWORD(v60) - get_timeout_1000() + v61;
      if ( !_frame.v69 )
      {
        _frame.v70 = v62;
        _frame.v73 = v61;
        _frame.v69 = 1;
        goto LABEL_42;
      }
      if ( _frame.v70 < v61 )
      {
        v61 -= _frame.v74;
        v62 -= _frame.v74;
      }
      else
      {
        if ( _frame.v73 <= v62 )
        {
LABEL_96:
          v63 = _frame.v73;
          if ( _frame.v73 < v61 )
            v63 = v61;
          _frame.v73 = v63;
          v64 = _frame.v70;
          if ( _frame.v70 >= v62 )
            v64 = v62;
          _frame.v70 = v64;
          goto LABEL_42;
        }
        v62 += _frame.v74;
        v61 += _frame.v74;
      }
      if ( _frame.v70 < v61 || _frame.v73 > v62 )
        goto LABEL_42;
      goto LABEL_96;
    }
LABEL_42:
    v32 = get_timeout_1000();
    v33 = *(volatile uint64_t *)(v29 - 1);
    v34 = HIDWORD(v33) - 6000 - v32;
    v35 = get_timeout_1000();
    v36 = *(v29 - 2);
    v37 = v33 + 4000 + v35;
    if ( (int)(v34 - v28[4]) < 0 )
    {
      do
      {
        v34 += v36;
        if ( (int)(v34 - v28[4]) >= 0 )
          break;
        v34 += v36;
      }
      while ( (int)(v34 - v28[4]) < 0 );
    }
    else
    {
      for ( i = v34 - v36; (int)(i - v28[4]) >= 0; i -= v36 )
        v34 = i;
    }
    result = (volatile uint32_t *)lll_conn_state_match(_frame.v71, 1, 0, 255, v36, v37, v34);
    v39 = dword_126058;
    *v29 = v34;
    v29[1] = v34 + v37;
    v40 = (char)result;
    for ( j = 0; j != 4; ++j )
    {
      if ( ((v29[2] >> j) & 1) != 0 )
      {
        v42 = *(v29 - 2);
        _frame.v78 = *(volatile uint32_t *)(v39 + 36);
        _frame.v79 = _frame.v78 + 10000;
        result = (volatile uint32_t *)util_diff32(v29, (volatile unsigned int *)&_frame.v78, 0, v42);
        if ( **v1 < 0 && *(volatile uint8_t *)(v39 + 86) != 255 )
          result = (volatile uint32_t *)irq_disable_mmio_write(dword_1262EC, dword_1262D8, 876);
        v43 = _frame.v78;
        v44 = v29[1];
        *(volatile uint8_t *)(v39 + 86) = *(volatile uint8_t *)(_frame.v71 + 107);
        *(volatile uint32_t *)(v39 + 92) = v44 - v43;
        *(volatile uint8_t *)(v39 + 87) = v40;
        *(volatile uint16_t *)(v39 + 96) = 0;
      }
      v39 += 1320;
    }
    ++v30;
    v29 += 5;
    if ( _frame.v67 != v30 )
      continue;
    break;
  }
  if ( _frame.v69 )
  {
    v45 = _frame.v70;
    if ( _frame.v70 >= _frame.v73 + 5000 )
      v45 = _frame.v73 + 5000;
    v46 = v45;
    if ( v45 > (int)_frame.v74 / 2 )
    {
      v46 = v45 - _frame.v74;
    }
    else if ( (int)_frame.v74 / -2 > v45 )
    {
      v46 = v45 + _frame.v74;
    }
    result = (volatile uint32_t *)rf_is_ready(v46);
    v47 = (void *)(uintptr_t)(off_12605C);
    v48 = *(volatile uint8_t *)(_frame.v71 + 85);
    *(volatile uint32_t *)(_frame.v71 + 88) = (int)(uintptr_t)(result);
    *(volatile uint8_t *)(_frame.v71 + 85) = v48 | 0x20;
    v47[49] = 1;
  }
  return result;
}



// patch_check_ready @ 0x126300
int patch_check_ready(volatile uint32_t *a1) {
  int v1; // r3
  int v2; // r2

  v1 = dword_12632C;
  while ( 1 )
  {
    if ( *(volatile uint8_t *)(v1 + 24) != 255 )
    {
      v2 = *(volatile uint8_t *)(v1 + 27);
      if ( v2 != 255 )
        break;
    }
    v1 += 28;
    if ( v1 == dword_12632C + 84 )
      return 0;
  }
  *a1 = dword_126330 + 1320 * v2;
  return 1;
}



// llc_pdu_check @ 0x126334
BOOL llc_pdu_check(int a1, int a2, int a3) {
  int v6; // r5
  int v7; // r3
  int v8; // r9
  unsigned int v9; // r8
  int v10; // r6
  int v11; // r6
  int v12; // r0
  int v13; // r3
  int v14; // r0
  int v16; // r3
  int v17; // r5
  int v18; // r3

  if ( a1 )
  {
    v6 = a1;
  }
  else
  {
    v16 = dword_12643C;
    while ( 1 )
    {
      if ( *(volatile uint8_t *)(v16 + 24) != 255 )
      {
        v17 = *(volatile uint8_t *)(v16 + 27);
        if ( v17 != 255 )
          break;
      }
      v16 += 28;
      if ( dword_12643C + 84 == v16 )
        return 0;
    }
    v6 = dword_126438 + 1320 * v17;
  }
  if ( !a3 || *(volatile uint8_t *)(a3 + 10) == 255 )
  {
    v14 = get_timeout_1000() + 14000;
  }
  else
  {
    v7 = dword_126438 + 1320 * *(volatile uint8_t *)(a3 + 8);
    if ( *(volatile uint8_t *)(v7 + 106) )
    {
      if ( *(volatile uint8_t *)(v7 + 106) == 2 )
      {
        v18 = *(volatile uint16_t *)(v7 + 222);
        v9 = v18 << 10;
        v8 = v18 << 9;
      }
      else
      {
        v8 = 51200;
        v9 = 102400;
      }
    }
    else
    {
      v9 = *(volatile uint32_t *)(dword_126440 + 696 * *(volatile uint8_t *)(v7 + 116) + 8);
      v8 = v9 >> 1;
    }
    v10 = *(volatile uint32_t *)(a3 + 4);
    v11 = v10 + 10000 + get_timeout_1000();
    v12 = rf_check_cal_state(a1, *(volatile uint8_t *)(a3 + 11));
    v13 = v12 - a2;
    if ( v12 - a2 + v8 < 0 )
    {
      do
        v12 += v9;
      while ( v8 - a2 + v12 < 0 );
      v13 = v12 - a2;
    }
    if ( v13 < 0 )
      a2 = v12 - 1;
    if ( v11 + 9000 - a2 < 0 )
      v14 = 5000;
    else
      v14 = v11 + 4000 - a2;
  }
  return lll_conn_state_match(v6, 1, 0, 1, 0, v14, a2) != 255;
}



// llc_rx_event_save @ 0x126444
int llc_rx_event_save(int a1, int a2, int a3) {
  volatile uint32_t *v3; // r10
  int v4; // r5
  int v7; // r11
  int v8; // r8
  int v9; // r3
  int v10; // r0
  int v11; // r4
  int v12; // r8
  int v13; // r3
  int result; // r0
  volatile uint32_t *v15; // r9
  int v16; // r4
  int v17; // r4
  unsigned int v18; // r4
  int v19; // r3
  int v20; // zf
  int v21; // r3
  int v22; // r4
  int v23; // [sp+4h] [bp-8h]

  v3 = (void *)(uintptr_t)(off_1265D0);
  v23 = a3;
  v4 = dword_1265C0;
  v7 = a1 + 76;
  if ( !a3 )
    goto LABEL_30;
  while ( 1 )
  {
    v8 = *(volatile uint32_t *)(a1 + 72);
    if ( !v3[8] )
      break;
    v15 = (volatile uint32_t *)v3[9];
    v16 = v15[1];
    v17 = v16 + 4000 + get_timeout_1000();
    if ( v8 != v15[2] )
    {
      v17 += 4000 + get_timeout_1000();
      if ( v15[3] )
        v17 += 10000;
    }
    v18 = (unsigned int)(a2 - v17) >> 31;
LABEL_18:
    if ( !v18 )
      goto LABEL_5;
    v11 = 0;
LABEL_20:
    if ( *(volatile uint8_t *)(a1 + 1224) && *(volatile uint8_t *)(dword_1265C8 + 140 * *(volatile uint8_t *)(a1 + 1225) + 112) == 1 )
      llc_pdu_check(a1, a2, v11);
    v19 = *(volatile uint8_t *)(a1 + 106);
    if ( *(volatile uint8_t *)(a1 + 106) )
    {
      v20 = v19 == 2;
      if ( v19 == 2 )
        v21 = *(volatile uint16_t *)(a1 + 222);
      else
        v21 = 102400;
      if ( v20 )
        v21 <<= 10;
    }
    else
    {
      v21 = *(volatile uint32_t *)(dword_1265CC + 696 * *(volatile uint8_t *)(a1 + 116) + 8);
    }
    a2 += v21;
    if ( !++v23 )
    {
LABEL_30:
      if ( (*(volatile uint8_t *)(a1 + 85) & 1) != 0 )
      {
        wlan_ioctl_handler_3(dword_1265C4, (void *)(uintptr_t)(v7));
        *(volatile uint8_t *)(a1 + 85) &= ~1u;
      }
    }
  }
  v9 = v3[20];
  if ( v9 && v8 != v9 )
  {
    v22 = v3[21];
    v18 = (unsigned int)(a2 - v22 - 4000 - get_timeout_1000()) >> 31;
    goto LABEL_18;
  }
LABEL_5:
  *(volatile uint32_t *)(a1 + 80) = a2;
  v10 = get_timeout_1000();
  v11 = v3[4];
  v12 = a2 + 13999 + v10;
  if ( v11 )
  {
    while ( 1 )
    {
      v13 = *(volatile uint32_t *)(v11 + 4);
      if ( v12 - v13 < 0 )
        break;
      if ( *(volatile uint32_t *)(v4 + 1320 * *(volatile uint8_t *)(a1 + 84) + 72) != *(volatile uint32_t *)(v4
                                                                                    + 1320
                                                                                    * *(volatile uint8_t *)(v11 + 8)
                                                                                    + 72) )
      {
        if ( util_list_len(v7, v11) )
          goto LABEL_20;
        v13 = *(volatile uint32_t *)(v11 + 4);
      }
      if ( a2 - v13 < 0 )
        break;
      v11 = *(volatile uint32_t *)v11;
      if ( !v11 )
        goto LABEL_33;
    }
  }
  else
  {
LABEL_33:
    v11 = 0;
  }
  result = (int)(uintptr_t)(list_find_prev((void *)(uintptr_t)(dword_1265C4), (void *)(uintptr_t)(v11), (void *)(uintptr_t)(v7)));
  *(volatile uint8_t *)(a1 + 85) |= 1u;
  return result;
}



