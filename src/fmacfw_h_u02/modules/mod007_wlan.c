// check_short_value @ 0x111250
int check_short_value() {
  int v0; // r4
  volatile uint32_t *v1; // r0
  int v2; // r1
  volatile uint32_t *v3; // r2
  volatile uint8_t *v4; // r6
  unsigned int v5; // r1
  unsigned int v6; // r2
  int v7; // r5
  unsigned int v8; // r2
  volatile char *v9; // r3
  volatile uint32_t *v10; // r7
  volatile uint32_t *v11; // r0
  int v12; // r3
  volatile char *v13; // r1
  int v14; // r2
  volatile uint32_t *v15; // r0
  volatile uint8_t *v16; // r5
  unsigned int v17; // r1
  unsigned int v18; // r2
  int result; // r0
  volatile int *v20; // r5
  int v21; // r2
  volatile uint8_t *v22; // r0
  unsigned int v23; // r1
  unsigned int v24; // r2
  volatile uint32_t *v25; // r3
  volatile int *v26; // r5
  int v27; // r2
  volatile uint16_t *v28; // r0
  unsigned int v29; // r2
  volatile uint32_t *v30; // r3
  unsigned int v31; // r3
  volatile uint32_t *v32; // r7
  volatile uint32_t *v33; // r1
  unsigned int v34; // r3
  volatile char *v35; // r2
  volatile uint32_t *v36; // r5
  int v37; // r6
  int v38; // r7
  unsigned int v39; // r3
  volatile char *v40; // r2
  int v41; // r5
  int v42; // r1
  int v43; // r1
  volatile uint32_t *v44; // r2
  int v45; // r5
  volatile uint8_t *v46; // r6
  volatile uint32_t *v47; // r2

  v0 = *(volatile uint32_t *)off_1114D8;
  if ( **(volatile int16_t **)off_1114D4 < 0 && !v0 )
  {
    log_warning((int)aIntStatus0, (int)aSdioIsr, 39);
    goto LABEL_10;
  }
  if ( (v0 & 0x2000) != 0 )
  {
    v44 = (void *)(uintptr_t)(off_1116F4);
    v45 = *(volatile uint32_t *)off_111708;
    *(volatile uint32_t *)off_111708 = *(volatile uint32_t *)off_111708;
    *v44 &= ~0x20u;
    check_feature_flag(2, "int2dev:%d\n", v45);
    if ( (v45 & 4) != 0 )
    {
      *(volatile uint8_t *)off_111714 = 1;
      check_feature_flag(2, &aClrPreSleep[4]);
    }
    if ( (v45 & 1) != 0 )
    {
      v46 = (void *)(uintptr_t)(off_111714);
      *(volatile uint32_t *)off_111710 = 16;
      if ( *v46 )
      {
        check_feature_flag(2, aClrPreSleep);
        *v46 = 0;
      }
      if ( *(volatile uint8_t *)off_111718 )
      {
        v47 = (void *)(uintptr_t)(off_111738);
        *((volatile uint8_t *)off_111718 + 1) = 1;
        *v47 |= 1u;
        check_feature_flag(2, aSoftwk);
      }
      *(volatile uint8_t *)off_11171C = 0;
    }
    if ( (v45 & 2) != 0 )
    {
      *(volatile uint8_t *)off_11171C = 1;
      check_feature_flag(2, aBit1);
    }
    if ( (v45 & 8) != 0 )
      alloc_tx_event(aNotUsed);
  }
  if ( (v0 & 1) != 0 )
  {
    alloc_tx_event(aSdioHostSoftRe, v0 << 31);
    *(volatile uint32_t *)off_1114E0 = 1;
  }
  if ( (v0 & 0x20) != 0 )
  {
    sdio_set_phase_config(*(volatile uint32_t *)off_1114E4);
    *(volatile uint32_t *)off_1114E0 = 32;
  }
  if ( (v0 & 0x4000) != 0 )
  {
    v1 = (void *)(uintptr_t)(off_1114EC);
    v2 = *(volatile uint32_t *)off_1114E8;
    v3 = (void *)(uintptr_t)(off_1114F0);
    *(volatile uint32_t *)off_1114E8 = *(volatile uint32_t *)off_1114E8;
    alloc_tx_event("sdio func1 error bit:%x, func1 free cnt=%d, func1 free queue2 cnt=%d\r\n", v2, *v3, *v1);
  }
  if ( (v0 & 0x8000) == 0 )
    goto LABEL_10;
  v41 = *(volatile uint32_t *)off_1116EC;
  *(volatile uint32_t *)off_1116EC = *(volatile uint32_t *)off_1116EC;
  alloc_tx_event("sdio func1 other bit:%x\r\n", v41);
  if ( (v41 & 4) != 0 )
    *(volatile uint32_t *)off_1116F4 &= ~1u;
  if ( (v41 & 8) == 0 )
  {
LABEL_10:
    if ( (v0 & 0x400000) == 0 )
      goto LABEL_11;
LABEL_60:
    v42 = *(volatile uint32_t *)off_1116F8;
    *(volatile uint32_t *)off_1116F8 = *(volatile uint32_t *)off_1116F8;
    alloc_tx_event("sdio func2 error bit:%x\r\n", v42);
    if ( (v0 & 0x800000) == 0 )
      goto LABEL_12;
    goto LABEL_61;
  }
  *(volatile uint32_t *)off_1116F4 &= ~4u;
  if ( (v0 & 0x400000) != 0 )
    goto LABEL_60;
LABEL_11:
  if ( (v0 & 0x800000) == 0 )
    goto LABEL_12;
LABEL_61:
  v43 = *(volatile uint32_t *)off_111700;
  *(volatile uint32_t *)off_111700 = *(volatile uint32_t *)off_111700;
  alloc_tx_event("sdio func2 other bit:%x\r\n", v43);
LABEL_12:
  if ( (v0 & 0x400) != 0 )
  {
    v4 = (void *)(uintptr_t)(off_1114F8);
    v5 = *((volatile uint8_t *)off_1114F8 + 1621);
    v6 = *((volatile uint8_t *)off_1114F8 + 1622);
    if ( v5 >= v6 )
    {
      alloc_tx_event("rxused=%d, total=%d\r\n", v5, v6);
    }
    else
    {
      v7 = *(volatile uint32_t *)off_111500;
      v8 = *((volatile uint8_t *)off_1114F8 + 1620)
         + 1
         - 81
         * ((unsigned int)(((unsigned int)dword_1114FC
                          * (uint64_t)((unsigned int)*((volatile uint8_t *)off_1114F8 + 1620) + 1)) >> 32) >> 6);
      v9 = (volatile char *)off_1114F8 + 20 * v8;
      v10 = (void *)(uintptr_t)(off_111508);
      *((volatile uint32_t *)v9 + 1) = *(volatile uint32_t *)off_111504;
      v4[1621] = v5 + 1;
      v11 = (void *)(uintptr_t)(off_11150C);
      *((volatile uint32_t *)v9 + 2) = *v10;
      v9[12] = v7;
      v4[1620] = v8;
      v9[13] = BYTE1(v7) & 7;
      *v11 = 16;
      do
        v12 = *v11 & 0x20;
      while ( v12 );
      v13 = &v4[20 * v8];
      v14 = 5 * v8;
      if ( (v13[13] & 4) == 0 )
        v12 = *(volatile uint32_t *)(*((volatile uint32_t *)v13 + 2) + 4);
      v15 = (void *)(uintptr_t)(off_111514);
      *(volatile uint32_t *)off_111510 = v12;
      *v15 = 16;
      co_list_push_back(dword_111518, (void *)(&v4[4 * v14]));
      irq_disable_global_2(256);
    }
    *(volatile uint32_t *)off_1114E0 = 1024;
  }
  if ( (v0 & 0x200) != 0 )
  {
    alloc_tx_event(aUnexpectH2dCon);
    *(volatile uint32_t *)off_111728 = 512;
  }
  if ( (v0 & 0x100) != 0 )
  {
    v16 = (void *)(uintptr_t)(off_1114F8);
    v17 = *((volatile uint8_t *)off_1114F8 + 2433);
    v18 = *((volatile uint8_t *)off_1114F8 + 2434);
    if ( v17 < v18 )
    {
      v37 = *(volatile uint32_t *)off_1116E0;
      v38 = *(volatile uint32_t *)off_1116D8;
      v39 = *((volatile uint8_t *)off_1114F8 + 2432)
          + 1
          - 40
          * ((unsigned int)(((unsigned int)dword_1116DC
                           * (uint64_t)((unsigned int)*((volatile uint8_t *)off_1114F8 + 2432) + 1)) >> 32) >> 5);
      v40 = (volatile char *)off_1114F8 + 20 * v39;
      *((volatile uint8_t *)off_1114F8 + 2432) = v39;
      v40[1645] = BYTE1(v37) & 7;
      *((volatile uint32_t *)v40 + 409) = v38;
      *((volatile uint32_t *)v40 + 410) = v38;
      v40[1644] = v37;
      v16[2433] = v17 + 1;
      co_list_push_back((int)(v16 + 2436), (volatile uint32_t *)v40 + 408);
      irq_disable_global_2(0x400000);
    }
    else
    {
      alloc_tx_event("msgrxused=%d, total=%d\r\n", v17, v18);
    }
    *(volatile uint32_t *)off_1114E0 = 256;
  }
  result = v0 << 19;
  if ( (v0 & 0x1000) != 0 )
  {
    if ( *(volatile uint8_t *)off_111520 )
    {
      v20 = (volatile int *)off_111524;
      v21 = BYTE1(((volatile uint32_t *)(uintptr_t)off_111524)[92]);
      *(volatile uint8_t *)off_111520 = 0;
      if ( v21 )
        mmio_set_bit_1(1);
      else
        mmio_clear_bit_1(1);
      if ( *((volatile uint8_t *)v20 + 374) == 1 )
        mem_set_util((int)(uintptr_t)((volatile uint32_t *)dword_111528));
    }
    v22 = (void *)(uintptr_t)(off_11152C);
    v23 = *((volatile uint8_t *)off_11152C + 3074);
    v24 = *((volatile uint8_t *)off_11152C + 3073);
    if ( v23 < v24 )
    {
      v34 = *((volatile uint8_t *)off_11152C + 3072)
          + 1
          - 192
          * ((unsigned int)(((unsigned int)dword_111544
                           * (uint64_t)((unsigned int)*((volatile uint8_t *)off_11152C + 3072) + 1)) >> 32) >> 7);
      v35 = (volatile char *)off_11152C + 16 * v34;
      *((volatile uint32_t *)v35 + 1) = *(volatile uint32_t *)off_111554;
      v36 = (void *)(uintptr_t)(off_111558);
      v22[3072] = v34;
      *((volatile uint16_t *)v35 + 4) = *v36;
      v22[3074] = v23 + 1;
      co_list_push_back((int)(v22 + 3080), (void *)(v35));
      result = irq_disable_global_2(128);
    }
    else
    {
      result = alloc_tx_event("txcused=%d, total=%d\r\n", v23, v24);
    }
    v25 = (void *)(uintptr_t)(off_111534);
    *(volatile uint32_t *)off_1114E0 = 4096;
    if ( !*v25 )
      *(volatile uint8_t *)off_111538 &= ~1u;
  }
  if ( (v0 & 0x800) != 0 )
  {
    if ( *(volatile uint8_t *)off_111520 )
    {
      v26 = (volatile int *)off_111524;
      v27 = BYTE1(((volatile uint32_t *)(uintptr_t)off_111524)[92]);
      *(volatile uint8_t *)off_111520 = 0;
      if ( v27 )
        mmio_set_bit_1(1);
      else
        mmio_clear_bit_1(1);
      if ( *((volatile uint8_t *)v26 + 374) == 1 )
        mem_set_util((int)(uintptr_t)((volatile uint32_t *)dword_111528));
    }
    v28 = (void *)(uintptr_t)(off_11152C);
    v29 = *((volatile uint8_t *)off_11152C + 6162);
    if ( *((volatile uint8_t *)off_11152C + 6161) > v29 )
    {
      v31 = *((volatile uint8_t *)off_11152C + 6160)
          + 1
          - 192
          * ((unsigned int)(((unsigned int)dword_111544
                           * (uint64_t)((unsigned int)*((volatile uint8_t *)off_11152C + 6160) + 1)) >> 32) >> 7);
      v32 = (void *)(uintptr_t)(off_111548);
      *((volatile uint8_t *)off_11152C + 6160) = v31;
      v33 = (void *)(&v28[8 * v31 + 1544]);
      v33[1] = *v32;
      v28[8 * v31 + 1548] = *(volatile uint32_t *)off_11154C;
      *((volatile uint8_t *)v28 + 6162) = v29 + 1;
      co_list_push_back(dword_111550, v33);
      result = irq_disable_global_2(64);
    }
    else
    {
      result = alloc_tx_event("txcmsgused=%d, msgtotal=%d\r\n", v29, v29);
    }
    v30 = (void *)(uintptr_t)(off_111540);
    *(volatile uint32_t *)off_1114E0 = 2048;
    if ( !*v30 )
      *(volatile uint8_t *)off_111538 &= ~2u;
  }
  if ( (v0 & 4) != 0 )
    *(volatile uint32_t *)off_1114E0 = 4;
  if ( (v0 & 8) != 0 )
    *(volatile uint32_t *)off_1114E0 = 8;
  return result;
}


// update_packet_buffer @ 0x111744
int update_packet_buffer() {
  int v0; // r3
  volatile int *v1; // r2
  volatile uint32_t *v2; // r1
  int result; // r0
  int v4; // r3
  int v5; // r1
  volatile char *v6; // r3
  volatile uint32_t *v7; // r4
  int v8; // r6
  uint64_t v9; // kr00_8
  uint64_t v10; // kr08_8

  v0 = *(volatile uint32_t *)off_1117BC;
  v1 = (volatile int *)off_1117C0;
  v2 = (void *)(uintptr_t)(off_1117C4);
  *(volatile uint32_t *)(v0 + 4) = *(volatile uint32_t *)off_1117B8;
  result = *v1;
  v2[709] = v0;
  v4 = *(volatile uint32_t *)off_1117C8;
  *(volatile uint8_t *)(result + 3) |= 0xC0u;
  v5 = v4 + 3200;
  do
  {
    *(volatile uint8_t *)(v4 + 3) |= 0xC0u;
    v4 += 8;
  }
  while ( v4 != v5 );
  v6 = (volatile char *)off_1117CC;
  v7 = (void *)(uintptr_t)(off_1117C4);
  v8 = *((volatile uint32_t *)off_1117CC + 2);
  v9 = *(volatile uint64_t *)off_1117CC;
  *(volatile uint8_t *)(*(volatile uint32_t *)off_1117CC + 3) |= 0xC0u;
  *(volatile uint8_t *)(HIDWORD(v9) + 3) |= 0xC0u;
  v10 = *(volatile uint64_t *)(v6 + 12);
  *(volatile uint8_t *)(v8 + 3) |= 0xC0u;
  *(volatile uint8_t *)(v10 + 3) |= 0xC0u;
  *(volatile uint8_t *)(HIDWORD(v10) + 3) |= 0xC0u;
  v7[581] = result;
  return result;
}



// set_tx_control @ 0x1117d0
int set_tx_control() {
  volatile uint32_t *v0; // r1
  int v1; // r0
  volatile uint32_t *v2; // r3
  int result; // r0

  v0 = *(volatile uint32_t **)off_11181C;
  v1 = *(volatile uint32_t *)off_111820;
  v2 = (void *)(uintptr_t)(off_111824);
  *((volatile uint16_t *)off_111828 + 5) = 0;
  *v0 = 167772160;
  v0[1] = v1;
  v2[4] = v2[4] & 0xFFFFF81F | 0x20;
  do
    result = v2[4] & 0x20;
  while ( result );
  v2[578] = v2[578];
  v2[581] = (int)(uintptr_t)(v0);
  v2[576] |= 0x84000000;
  return result;
}



// get_node_offset8 @ 0x11182c
volatile int * get_node_offset8(int a1) {
  int v2; // r0
  int v3; // r5
  volatile int *result; // r0
  int ( *v5)(uint32_t, uint32_t, int); // r3

  v2 = dword_11185C + 16 * (a1 - 1);
  v3 = *(volatile uint8_t *)(v2 + 8);
  result = memset((volatile int *)v2, 0, 0x10u);
  if ( v3 )
  {
    result = (volatile int *)dword_111860;
    v5 = *(int ( **)(uint32_t, uint32_t, int))(dword_111860 + 4 * a1 + 32);
    if ( v5 )
      return (volatile int *)v5(0, 0, 1);
  }
  return result;
}



// get_node_offset_b @ 0x111864
volatile int * get_node_offset_b(int a1) {
  int v2; // r0
  int v3; // r5
  volatile int *result; // r0
  int ( *v5)(uint32_t, uint32_t, int); // r3

  v2 = dword_111894 + 16 * (a1 - 1);
  v3 = *(volatile uint8_t *)(v2 + 11);
  result = memset((volatile int *)v2, 0, 0x10u);
  if ( v3 )
  {
    v5 = *(int ( **)(uint32_t, uint32_t, int))(dword_111898 + 4 * (a1 + 13));
    if ( v5 )
      return (volatile int *)v5(0, 0, 1);
  }
  return result;
}



// call_get_node @ 0x11189c
volatile int *call_get_node() {
  int i; // r4
  int v1; // r0
  volatile int *result; // r0
  int v3; // [sp+4h] [bp-4h]

  for ( i = 1; i != 6; ++i )
  {
    v1 = (uint8_t)i;
    v3 = (uint8_t)i;
    get_node_offset8(v1);
    result = get_node_offset_b(v3);
  }
  return result;
}



// mmio_set_bit_2 @ 0x1118bc
int mmio_set_bit_2() {
  volatile uint32_t *v0; // r2
  volatile uint32_t *v1; // r2
  volatile uint32_t *v2; // r1
  volatile uint32_t *v3; // r2
  volatile uint32_t *v4; // r1
  int v5; // r3
  volatile uint32_t *v6; // r2

  v0 = (void *)(uintptr_t)(off_1119B0);
  *((volatile uint32_t *)off_1119B0 + 4) |= 1u;
  while ( (v0[4] & 1) != 0 )
    ;
  v1 = (void *)(uintptr_t)(off_1119B0);
  while ( *((volatile int *)off_1119B0 + 4) >= 0 )
    ;
  v2 = (void *)(uintptr_t)(off_1119B0);
  *((volatile uint32_t *)off_1119B0 + 3) |= 0x40000007u;
  v1[3] = v1[3] & 0xFFFFC0FF | 0x2700;
  v1[4] |= 1u;
  while ( (v2[4] & 1) != 0 )
    ;
  v3 = (void *)(uintptr_t)(off_1119B0);
  while ( *((volatile int *)off_1119B0 + 4) >= 0 )
    ;
  v4 = (void *)(uintptr_t)(off_1119B0);
  *((volatile uint32_t *)off_1119B0 + 3) |= 0x40000007u;
  v3[3] = v3[3] & 0xFFFFC0FF | 0x2700;
  v3[512] &= 0xFFFFE7FC;
  v3[512] |= 0x800004u;
  v3[6] = 0;
  v5 = 1;
  v3[5] = -1;
  v3[519] = 0;
  v3[517] = 0;
  v3[516] = 0;
  while ( 1 )
  {
    v6 = &v4[8 * v5 - 16];
    if ( v5 != 1 )
      break;
    v4[706] = -1;
    v4[578] = -1;
LABEL_11:
    ++v5;
  }
  v6[714] = -1;
  v6[586] = -1;
  if ( v5 != 6 )
    goto LABEL_11;
  v4[6] = dword_1119B4;
  v4[513] &= ~2u;
  v4[513] |= 0x8000u;
  v4[2] = 46;
  v4[2] |= 1u;
  return alloc_tx_event(aUsbInitDone);
}


// send_data_word @ 0x1119bc
int send_data_word(int result, int a2) {
  volatile int *v2; // r4
  int v3; // r5
  int v4; // r3
  char v5; // r2
  volatile uint32_t *v6; // r2

  v2 = (volatile int *)off_111A18;
  v3 = *(volatile uint32_t *)off_111A14;
  v4 = *(volatile uint32_t *)off_111A18;
  *((volatile uint16_t *)off_111A1C + 5) = a2;
  if ( a2 == 64 )
    v5 = -54;
  else
    v5 = -50;
  *(volatile uint32_t *)v4 = -1073741824;
  *(volatile uint32_t *)(v4 + 4) = v3;
  *(volatile uint8_t *)(v4 + 3) = v5;
  *(volatile uint16_t *)v4 = a2;
  if ( result && a2 )
  {
    result = (int)(uintptr_t)(memcpy((void *)(uintptr_t)(v3), (void *)(uintptr_t)(result), a2));
    v4 = *v2;
  }
  v6 = (void *)(uintptr_t)(off_111A20);
  *(volatile uint8_t *)(v4 + 3) &= 0x3Fu;
  v6[578] = v6[578];
  v6[581] = v4;
  v6[576] |= 0x84000000;
  return result;
}



// unknown_handler @ 0x111a24
volatile int * unknown_handler(int a1, int a2, int a3) {
  volatile uint32_t *v3; // r6
  volatile int *v4; // r5
  int v5; // r7
  volatile uint32_t *v6; // r4

  if ( a1 )
  {
    v3 = (volatile uint32_t *)(dword_111AC8 + 32 * (a1 - 1) + 8);
    v4 = (volatile int *)(dword_111AC8 + 32 * (a1 - 1));
  }
  else
  {
    v3 = (volatile uint32_t *)dword_111AD4;
    v4 = (volatile int *)dword_111AD8;
  }
  v5 = *v4;
  if ( (*v4 & 0x80008000) != 0 && ((dword_111ACC & v5) != 0x20000 || a2 != 0x8000000 || a3) )
  {
    v6 = (void *)(uintptr_t)(off_111AD0);
    *((volatile uint32_t *)off_111AD0 + 513) |= 0x200u;
    while ( (v6[5] & 0x80) == 0 )
      ;
    *v4 |= a2 | 0x8008000;
    if ( a3 )
      *v4 &= ~a3;
    if ( !a1 )
      goto LABEL_10;
    if ( v5 < 0 )
    {
      *v3 = 2;
      *v4 |= 0x40000000u;
      while ( (*v3 & 2) == 0 )
        ;
      if ( (v5 & 0x8000) != 0 )
        goto LABEL_10;
    }
    else if ( (v5 & 0x8000) != 0 )
    {
LABEL_10:
      *((volatile uint32_t *)off_111AD0 + 513) |= 0x400u;
      return get_node_offset8(a1);
    }
    *v4 &= ~0x8000u;
    goto LABEL_10;
  }
  return get_node_offset8(a1);
}



// unknown_handler2 @ 0x111adc
int unknown_handler2(int a1, int a2, int a3) {
  int v3; // r6
  volatile uint32_t *v4; // r4
  int v5; // r5
  volatile uint32_t *v6; // r3
  volatile uint32_t *v7; // r2

  if ( a1 )
  {
    v3 = 32 * (a1 - 1);
    v4 = (volatile uint32_t *)(dword_111BBC + v3);
    v5 = *(volatile uint32_t *)(v3 + dword_111BBC);
    if ( (v5 & 0x80008000) == 0 )
      return (int)get_node_offset_b(a1);
    v6 = (volatile uint32_t *)(dword_111BBC + v3 + 8);
    if ( (dword_111BC0 & v5) == 0x20000 )
      goto LABEL_4;
    goto LABEL_15;
  }
  v4 = (void *)(uintptr_t)(off_111BC8);
  v5 = *(volatile uint32_t *)off_111BC8;
  if ( (*(volatile uint32_t *)off_111BC8 & 0x80008000) != 0 )
  {
    v6 = (volatile uint32_t *)dword_111BCC;
    if ( (dword_111BC0 & v5) == 0x20000 )
    {
LABEL_4:
      if ( a2 == 0x8000000 )
      {
        if ( !a3 )
          goto LABEL_11;
        *v6 = 64;
        *v4 |= 0x8008000u;
LABEL_27:
        *v4 &= ~a3;
LABEL_7:
        v7 = (void *)(uintptr_t)(off_111BC4);
        *((volatile uint32_t *)off_111BC4 + 4) = (a1 << 6) | 0x20;
        while ( (v7[4] & 0x20) != 0 )
          ;
        if ( (v5 & 0x8000) == 0 )
          *v4 &= ~0x8000u;
LABEL_11:
        if ( !a1 )
          return a1;
        return (int)get_node_offset_b(a1);
      }
      *v6 = 64;
      *v4 |= a2 | 0x8008000;
LABEL_6:
      if ( !a3 )
        goto LABEL_7;
      goto LABEL_27;
    }
LABEL_15:
    *v6 = 64;
    *v4 |= a2 | 0x8008000;
    if ( v5 < 0 )
    {
      if ( (v5 & 0x20000) == 0 )
      {
        while ( (*v6 & 0x40) == 0 )
          ;
        *v6 = 64;
      }
      if ( a3 )
        *v4 &= ~a3;
      *v6 = 2;
      *v4 |= 0x40000000u;
      while ( (*v6 & 2) == 0 )
        ;
      goto LABEL_7;
    }
    goto LABEL_6;
  }
  return a1;
}



// read_hw_sel @ 0x111bd0
int read_hw_sel(int a1, int a2) {
  volatile uint32_t *v2; // r0
  int v4; // r0

  if ( a2 )
  {
    if ( a1 == 1 )
      v4 = dword_111BFC;
    else
      v4 = dword_111C00;
    return (*(volatile uint32_t *)(v4 + 32 * a2) >> 21) & 1;
  }
  else
  {
    if ( a1 == 1 )
      v2 = (volatile uint32_t *)dword_111BFC;
    else
      v2 = (volatile uint32_t *)dword_111C00;
    return (*v2 >> 21) & 1;
  }
}



// set_hw_cfg_a @ 0x111c04
volatile int * set_hw_cfg_a(volatile int *result, unsigned int a2) {
  if ( result )
  {
    if ( a2 <= 5 )
      return (volatile int *)unknown_handler2(a2, 0x8000000, 0);
  }
  else if ( a2 <= 5 )
  {
    return unknown_handler(a2, 0x8000000, 0);
  }
  return result;
}



// set_hw_cfg_b @ 0x111c28
volatile int * set_hw_cfg_b(volatile int *result, unsigned int a2) {
  if ( result )
  {
    if ( a2 <= 5 )
      return (volatile int *)unknown_handler2(a2, 0x200000, 0);
  }
  else if ( a2 <= 5 )
  {
    return unknown_handler(a2, 0x200000, 0);
  }
  return result;
}



// set_hw_cfg_c @ 0x111c4c
volatile int * set_hw_cfg_c(volatile int *result, unsigned int a2) {
  if ( result )
  {
    if ( a2 <= 5 )
      return (volatile int *)unknown_handler2(a2, 0x8000000, 0x200000);
  }
  else if ( a2 <= 5 )
  {
    return unknown_handler(a2, 0x8000000, 0x200000);
  }
  return result;
}



// wlan_ctrl_check @ 0x111c74
volatile int * wlan_ctrl_check(volatile int *result, unsigned int a2) {
  return set_hw_cfg_a(result, a2);
}



// wlan_open @ 0x111c78
int wlan_open(int a1, int a2) {
  volatile uint8_t *v4; // r6
  volatile int *v5; // r7
  volatile char *v6; // r0
  int v7; // r1
  volatile uint32_t *v8; // r4
  volatile uint32_t *v9; // r3
  volatile uint8_t *v11; // r7
  int v12; // r0
  int v13; // r1
  volatile uint32_t *v14; // r3
  void ( *v15)(int); // r2

  alloc_tx_event("open:%d/%d\n", 0, a2);
  if ( !a1 )
    return 1;
  if ( !*(volatile uint32_t *)a1 || !*(volatile uint32_t *)(a1 + 4) || !*(volatile uint32_t *)(a1 + 8) || !*(volatile uint32_t *)(a1 + 20) )
    return 2;
  v4 = (void *)(uintptr_t)(off_111D84);
  if ( *(volatile uint8_t *)off_111D84 )
    return 3;
  v5 = (volatile int *)off_111D88;
  v6 = (volatile char *)off_111D8C;
  *(volatile uint8_t *)off_111D84 = 1;
  memcpy(v6, (volatile char *)a1, 0x50u);
  v7 = v5[97];
  if ( v7 )
  {
    alloc_tx_event("usb sftdiscon delay %d\n", v7);
    mmio_read32(v5[97]);
  }
  v8 = (void *)(uintptr_t)(off_111D90);
  if ( (*((volatile uint32_t *)off_111D90 + 512) & 0x7F0) != 0 )
  {
    v11 = (void *)(uintptr_t)(off_111DA8);
    *((volatile uint32_t *)off_111DA8 + 1) = 0;
    *((volatile uint32_t *)v11 + 2) = 0;
    *v11 = 0;
    *v4 = 4;
    v12 = update_packet_buffer();
    v13 = *(volatile uint32_t *)off_111DAC;
    v14 = *(volatile uint32_t **)off_111DB0;
    *v14 = dword_111DB4;
    v14[1] = v13;
    v8[709] = (int)(uintptr_t)(v14);
    v8[706] = v8[706];
    v15 = *((void ( **)(int))off_111D8C + 19);
    v8[704] |= 0x84000000;
    *v11 = 1;
    if ( v15 )
      v15(v12);
  }
  else
  {
    if ( (*((volatile uint32_t *)off_111D90 + 2) & 1) != 0 )
    {
      *((volatile uint32_t *)off_111D90 + 2) &= ~1u;
      v8[513] |= 2u;
    }
    mmio_set_bit_2();
  }
  alloc_tx_event(aEnableIrq);
  v9 = (void *)(uintptr_t)(off_111DA0);
  *(volatile uint32_t *)(*((volatile uint32_t *)off_111D98 + 2) + 320) = off_111D9C;
  v9[2] = 1;
  if ( a2 == 1 )
  {
    while ( *v4 != 4 )
      ;
  }
  alloc_tx_event(aOpenDone);
  return 0;
}


// wlan_configure_tx_queue @ 0x111dbc
int wlan_configure_tx_queue(int result, int a2, int a3, unsigned int a4) {
  int v4; // r6
  unsigned int v7; // r11
  int v8; // r7
  int v9; // r10
  int v10; // r9
  int v11; // r2
  volatile uint16_t *v12; // r4
  int v13; // r1
  volatile uint32_t *v14; // r2
  int v15; // r5
  int v16; // r6
  volatile uint32_t *v17; // r2
  unsigned int v18; // r3
  int v19; // cf

  v4 = a2 - 1;
  if ( (uint8_t)(a2 - 1) <= 4u )
  {
    v7 = a4;
    if ( result )
    {
      if ( (a3 & 0xFD) == 1 )
      {
        if ( a4 > 0x320 )
        {
          v9 = 400;
          v8 = (v8 & ~0xFFFFu) | ((uint16_t)(400) & 0xFFFFu);
          v10 = 26214400;
        }
        else
        {
          v8 = (uint16_t)(2 * ((int)(a4 + 3) >> 2));
          v9 = v8;
          v10 = (uint16_t)v8 << 16;
        }
        if ( a4 > 0x400 )
        {
          v18 = -1025;
          v19 = v7 - 1025 >= 0x400;
          if ( v7 - 1025 < 0x400 )
            v7 >>= 1;
          else
            v18 = ((unsigned int)dword_111F00 * (uint64_t)v7) >> 32;
          if ( v19 )
            v7 = (v7 & ~0xFFFFu) | ((uint16_t)(v18 >> 1) & 0xFFFFu);
        }
      }
      else
      {
        v8 = (uint16_t)(2 * ((int)(a4 + 3) >> 2));
        v9 = v8;
        v10 = (uint16_t)v8 << 16;
      }
      if ( (*((volatile uint32_t *)&REG_4020_0900 + 8 * a2) & 0x80008000) != 0 )
        result = (int)(uintptr_t)(set_hw_cfg_a((void *)(uintptr_t)(result), a2));
      v11 = (a3 << 18) & 0xC0000;
      v12 = (void *)(uintptr_t)(off_111EF8);
      v13 = *(volatile uint16_t *)off_111EF8;
      *((volatile uint32_t *)&REG_4020_0900 + 8 * a2) = v7 & 0x7FF | v11 | (a2 << 22) | 0x18008000;
      if ( v13 + v9 > 2048 )
      {
        result = debug_printf("FIFO ERROR: overflow, addr is %d, size is %d, Total RAM is %d", v13, v9, 2048);
        v13 = (uint16_t)*v12;
      }
      v14 = (void *)(uintptr_t)(off_111EFC);
      *((volatile uint32_t *)off_111EFC + v4 + 65) = v13 | v10;
      v15 = (1 << a2) | v14[519];
      *v12 = v8 + v13;
      v14[519] = v15;
    }
    else
    {
      v16 = 32 * a2 + 1075838976;
      if ( (*((volatile uint32_t *)&REG_4020_0b00 + 8 * a2) & 0x80008000) != 0 )
        result = (int)(uintptr_t)(set_hw_cfg_a(0, a2));
      v17 = (void *)(uintptr_t)(off_111EFC);
      *(volatile uint32_t *)(v16 + 2816) = v7 & 0x7FF | (a3 << 18) & 0xC0000 | 0x18008000;
      v17[519] |= 0x10000 << a2;
    }
  }
  return result;
}


// mac_read_queue_reg @ 0x111f08
int mac_read_queue_reg(int a1, int a2, unsigned int a3) {
  int v3; // r4
  int v4; // r12
  int v5; // r3
  int v6; // r0
  int v7; // r0
  unsigned int v8; // r7
  int v9; // r4
  char v10; // r6

  if ( *(volatile uint8_t *)off_111FA8 != 4 )
    return 1;
  v3 = a1 - 1;
  if ( (uint8_t)(a1 - 1) > 5u )
    return 2;
  if ( a2 << 30 )
  {
    debug_printf(aErrAlignmentEr);
    return 3;
  }
  else
  {
    v4 = dword_111FAC + 16 * v3;
    if ( *(volatile uint32_t *)v4 )
    {
      return 4;
    }
    else
    {
      v5 = 32 * a1 + 1075838976;
      if ( (*((volatile uint32_t *)&REG_4020_0b00 + 8 * a1) & 0x8000) != 0 )
      {
        v6 = dword_111FB0;
        *(volatile uint32_t *)(dword_111FAC + 16 * v3) = a2;
        v7 = *(volatile uint32_t *)(v6 + 4 * v3);
        v8 = dword_111FB4;
        *(volatile uint8_t *)(v4 + 8) = 1;
        v9 = 32 * v3 + 1075838976;
        v10 = *(volatile uint8_t *)(v7 + 3) & 0x31;
        if ( a3 >= v8 )
          a3 = v8;
        *(volatile uint32_t *)(v4 + 4) = a3;
        *(volatile uint16_t *)v7 = a3;
        *(volatile uint32_t *)(v7 + 4) = a2;
        *(volatile uint8_t *)(v7 + 3) = v10 | 0xE;
        *(volatile uint32_t *)(v9 + 2868) = v7;
        *(volatile uint32_t *)(v5 + 2816) |= 0x84000000;
        return 0;
      }
      else
      {
        return 5;
      }
    }
  }
}


// wlan_wait_ready_alt @ 0x111fbc
int wlan_wait_ready_alt(int a1) {
  int result; // r0
  int v2; // r3

  result = 32 * a1 + 1075838976;
  v2 = *(volatile uint32_t *)(result + 2816);
  if ( v2 < 0 )
    *(volatile uint32_t *)(result + 2816) = v2 & 0x7BFFFFFF | 0x4000000;
  return result;
}



// phy_save_rssi @ 0x111fdc
int phy_save_rssi(int a1, int a2, unsigned int a3) {
  int v3; // r4
  int v4; // r12
  int v5; // r3
  int v6; // r0
  int v7; // r0
  unsigned int v8; // r7
  int v9; // r4
  char v10; // r6

  if ( *(volatile uint8_t *)off_112080 != 4 )
    return 1;
  v3 = a1 - 1;
  if ( (uint8_t)(a1 - 1) > 5u )
    return 2;
  if ( a2 << 30 )
  {
    debug_printf(aErrAlignmentEr);
    return 3;
  }
  else
  {
    v4 = dword_112084 + 16 * v3;
    if ( *(volatile uint32_t *)v4 )
    {
      return 4;
    }
    else
    {
      v5 = 32 * a1 + 1075838976;
      if ( (*((volatile uint32_t *)&REG_4020_0b00 + 8 * a1) & 0x8000) != 0 )
      {
        v6 = dword_112088;
        *(volatile uint32_t *)(dword_112084 + 16 * v3) = a2;
        v7 = *(volatile uint32_t *)(v6 + 4 * v3);
        v8 = dword_11208C;
        *(volatile uint8_t *)(v4 + 8) = 1;
        v9 = 32 * v3 + 1075838976;
        v10 = *(volatile uint8_t *)(v7 + 3) & 0x31;
        if ( a3 >= v8 )
          a3 = v8;
        *(volatile uint32_t *)(v4 + 4) = a3;
        *(volatile uint16_t *)v7 = a3;
        *(volatile uint32_t *)(v7 + 4) = a2;
        *(volatile uint8_t *)(v7 + 3) = v10 | 0xE;
        *(volatile uint32_t *)(v9 + 2868) = v7;
        *(volatile uint32_t *)(v5 + 2816) = *(volatile uint32_t *)(v5 + 2816) & 0x7BFFFFFF | 0x80000000;
        return 0;
      }
      else
      {
        return 5;
      }
    }
  }
}


// wlan_process_packet @ 0x112094
int wlan_process_packet() {
  volatile uint8_t *v0; // r4
  int v1; // r0
  int ( *v3)(uint32_t); // r3

  v0 = (void *)(uintptr_t)(off_1120D8);
  v1 = *((volatile uint16_t *)off_1120D8 + 7);
  *(volatile uint16_t *)off_1120DC = v1;
  if ( v1 )
  {
    v3 = *((int ( **)(uint32_t))off_1120E4 + 5);
    if ( v3 && v3((uint8_t)v1) )
    {
      *(volatile uint8_t *)off_1120E0 = 4;
      *v0 = 7;
      if ( !rf_calibration_done() )
        set_config_field(0);
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    *(volatile uint8_t *)off_1120E0 = 3;
    return 1;
  }
}



// wlan_reset @ 0x1120e8
int wlan_reset(uint64_t a1, volatile uint32_t *a2) {
  int v2; // r4
  volatile uint8_t *v3; // r5
  void *v4; // r6
  volatile uint8_t *v5; // r3
  uint8_t v6; // r2
  int v7; // r3
  volatile uint32_t *v8; // r3
  int ( **v9)(int, unsigned int); // r4
  int ( *v10)(void *); // r1
  volatile uint8_t *v11; // r8
  char v12; // r2
  int v13; // r7
  int v14; // r0
  int v15; // r3
  int v16; // r3
  volatile uint32_t *v17; // r2
  int v18; // r3
  volatile uint32_t *v19; // r3
  volatile uint32_t *v20; // r3
  int v21; // r1
  volatile uint32_t *v22; // r2
  volatile uint32_t *v23; // r3
  int v24; // r3
  volatile uint32_t *v25; // r2
  volatile uint32_t *v26; // r3
  volatile uint32_t *v27; // r2
  int v28; // r0
  volatile uint32_t *v29; // r3
  int v30; // r3
  void *v31; // r3
  unsigned int v32; // r0
  unsigned int v33; // r1
  int v34; // r1
  int ( *v35)(int, unsigned int); // r3
  volatile uint8_t *v36; // r3
  volatile uint16_t *v37; // r3
  void *v38; // r2
  int v39; // r4
  unsigned int v40; // r1
  volatile uint8_t *v41; // r0
  int v42; // r3
  unsigned int v43; // r3
  volatile uint8_t *v44; // r0
  volatile uint8_t *v45; // r0
  uint16_t v46; // r2
  uint16_t v47; // r3
  char v48; // r3
  char v49; // r3
  volatile uint32_t *v50; // r4
  int v51; // r0
  volatile int *v52; // r8
  int v53; // r7
  int v54; // r3
  int v55; // r7
  volatile uint32_t *v56; // r2
  volatile uint32_t *v57; // r3
  uint16_t v58; // r2
  int v59; // r6
  unsigned int v60; // r2
  unsigned int v61; // r1
  volatile uint32_t *v62; // r2
  void ( *v63)(volatile uint8_t *); // r3
  volatile uint32_t *v64; // r2
  int v65; // r0
  volatile uint32_t *v66; // r3
  unsigned int v67; // r0
  int v68; // r0

  v2 = HIDWORD(a1);
  if ( (uint32_t)a1 )
  {
    v3 = (volatile uint8_t *)off_1123F4;
    v15 = *(volatile uint8_t *)off_1123F4;
    if ( v15 == 2 )
    {
      v4 = (void *)(uintptr_t)(off_1123F8);
      debug_printf(aEp0SetupErrorD, HIDWORD(a1), a2);
      goto LABEL_7;
    }
    if ( (a1 & 0x100000000LL) == 0 )
      goto LABEL_18;
    if ( v15 == 4 )
    {
      a1 = (a1 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(*((volatile uint16_t *)off_1123F4 + 4)) << 32);
      v58 = *((volatile uint16_t *)off_1123F4 + 5);
      a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)((uint16_t)(WORD2(a1) - v58)) & 0xFFFFFFFFu);
      if ( WORD2(a1) == v58 )
      {
        *(volatile uint8_t *)off_1123F4 = 5;
        return a1;
      }
      if ( (uint32_t)a1 == 64 )
      {
        v59 = 1;
      }
      else
      {
        if ( (unsigned int)a1 >= 0x40 )
          a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)(64) & 0xFFFFFFFFu);
        v59 = 0;
      }
      v60 = (uint16_t)(v58 + a1);
      *((volatile uint16_t *)off_1123F4 + 5) = v60;
      if ( HIDWORD(a1) < v60 )
      {
        a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)(debug_printf("Ep0 send length err %u-%u", HIDWORD(a1), v60)) & 0xFFFFFFFFu);
        a1 = (a1 & ~0xFFFF0000u) | (((uint16_t)(*((volatile uint16_t *)v3 + 4)) & 0xFFFFu) << 16);
        v60 = *((volatile uint16_t *)v3 + 5);
      }
      v61 = (uint16_t)(WORD2(a1) - v60);
      if ( v61 > 0x40 )
      {
        v61 = 64;
      }
      else if ( !v61 )
      {
        if ( !v59 )
        {
          v62 = (void *)(uintptr_t)(off_112890);
          *v3 = 5;
          v62[516] |= 0x10u;
          return a1;
        }
        a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)(send_data_word((int)(uintptr_t)(nullptr), 0)) & 0xFFFFFFFFu);
        goto LABEL_18;
      }
      a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)(send_data_word((int)(uintptr_t)((volatile char *)(*((volatile uint32_t *)v3 + 1) + v60)), v61)) & 0xFFFFFFFFu);
LABEL_18:
      if ( (v2 & 0x20) == 0 )
        return a1;
LABEL_19:
      if ( *v3 == 6 )
      {
        v27 = *(volatile uint32_t **)off_1123F8;
        v28 = *(volatile uint32_t *)off_112404;
        v29 = (void *)(uintptr_t)(off_1123FC);
        *v27 = dword_112408;
        v27[1] = v28;
        v29[709] = (int)(uintptr_t)(v27);
        v29[706] = v29[706];
        v29[704] |= 0x84000000;
        *v3 = 7;
        v29[517] |= 0x10u;
        a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)(set_tx_control()) & 0xFFFFFFFFu);
      }
      return a1;
    }
    if ( v15 != 7 )
      goto LABEL_18;
    v23 = (void *)(uintptr_t)(off_1123FC);
    a1 = (a1 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(off_112410) << 32);
    a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
    *(volatile uint8_t *)off_1123F4 = 0;
    v23[517] &= ~0x10u;
    v23[516] &= ~0x10u;
    if ( *(volatile uint8_t *)HIDWORD(a1) )
    {
      v23[513] = (16 * (uint8_t)*(volatile uint8_t *)HIDWORD(a1)) & 0x70 | v23[513] & 0xFFFFFF8F;
      *(volatile uint8_t *)HIDWORD(a1) = 0;
    }
  }
  else
  {
    if ( (BYTE4(a1) & 0x21) == 0x21 )
    {
      v17 = (void *)(uintptr_t)(off_1123FC);
      if ( (*((volatile uint32_t *)off_1123FC + 708) & 0x7F) == 0x40 )
      {
        v18 = *((volatile uint32_t *)off_1123FC + 708);
        a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)(v18 << 12) & 0xFFFFFFFFu);
        if ( (v18 & 0x80000) != 0 )
        {
          a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)(*(volatile uint32_t *)off_112404) & 0xFFFFFFFFu);
          v19 = *(volatile uint32_t **)off_1123F8;
          *v19 = dword_112408;
          v19[1] = a1;
          v17[709] = (int)(uintptr_t)(v19);
          v17[706] = v17[706];
          v17[704] |= 0x84000000;
          return a1;
        }
      }
    }
    if ( (a1 & 0x100000000LL) == 0 )
    {
      v3 = (volatile uint8_t *)off_1123F4;
      v16 = *(volatile uint8_t *)off_1123F4;
      if ( (a1 & 0x800000000LL) != 0 )
      {
        if ( v16 != 1 )
          return a1;
        goto LABEL_6;
      }
      if ( v16 == 2 )
      {
LABEL_6:
        v4 = (void *)(uintptr_t)(off_1123F8);
        goto LABEL_7;
      }
      goto LABEL_18;
    }
    if ( (a1 & 0x800000000LL) != 0 )
    {
      v3 = (volatile uint8_t *)off_1123F4;
      if ( !*(volatile uint8_t *)off_1123F4 )
        goto LABEL_6;
      set_hw_cfg_a((void *)(uintptr_t)(1), 0);
      v4 = (void *)(uintptr_t)(off_112750);
LABEL_7:
      if ( (v2 & 0x40) != 0 )
        v5 = (volatile uint8_t *)(*((volatile uint32_t *)off_1123FC + 709) - 8);
      else
        v5 = *(volatile uint8_t **)(*(volatile uint32_t *)v4 + 4);
      *((volatile uint32_t *)v3 + 1) = 0;
      *((volatile uint32_t *)v3 + 2) = 0;
      *v3 = 2;
      v3[12] = v3[12] & 0x7F | (*v5 >> 7 << 7);
      v6 = v3[12] & 0x9F | (32 * (((int)*v5 >> 5) & 3));
      v3[12] = v6;
      v3[12] = v6 & 0xE0 | *v5 & 0x1F;
      v3[13] = v5[1];
      *((volatile uint16_t *)v3 + 7) = v5[2] | (v5[3] << 8);
      *((volatile uint16_t *)v3 + 8) = v5[4] | (v5[5] << 8);
      v7 = v5[6] | (v5[7] << 8);
      *((volatile uint16_t *)v3 + 9) = v7;
      if ( !v7 && (v3[12] & 0x80u) != 0 )
        debug_printf(aEp0SetupErrorW);
      v8 = (void *)(uintptr_t)(off_1123FC);
      v9 = (int ( **)(int, unsigned int))off_112400;
      v10 = *((int ( **)(void *))off_112400 + 3);
      *((volatile uint32_t *)off_1123FC + 517) &= ~0x10u;
      v8[516] &= ~0x10u;
if ( !v10 || !v10((void *)(uintptr_t)(off_1123F4)) ) { v11 = (void *)(uintptr_t)(off_11241C);
        v12 = *(volatile uint8_t *)off_11241C;
        v13 = *(volatile uint8_t *)off_11241C;
        if ( (v3[12] & 0x60) != 0 )
        {
LABEL_54:
          if ( v13 == 4 && *v11 != 4 )
LABEL_56:
            call_get_node();
          goto LABEL_49;
        }
        v14 = v3[13];
        switch ( v3[13] )
        {
          case 0u:
            if ( *(volatile uint8_t *)off_11241C == 4 )
            {
              v30 = v3[12] & 0x1F;
              if ( v30 == 1 )
                goto LABEL_156;
              if ( v30 != 2 )
                goto LABEL_66;
              v67 = *((volatile uint16_t *)v3 + 8);
              v40 = v67 & 0xF;
              if ( v40 > 5 )
                goto LABEL_156;
              v14 = (v67 >> 7) & 1;
            }
            else
            {
              if ( *((volatile uint16_t *)v3 + 8) )
                goto LABEL_54;
              v30 = v3[12] & 0x1F;
              if ( v30 == 1 )
                goto LABEL_156;
              if ( v30 != 2 )
              {
LABEL_66:
                if ( v30 )
                  goto LABEL_59;
                v31 = (void *)(uintptr_t)(off_112734);
                *(volatile uint16_t *)off_112734 = *(volatile uint8_t *)off_112730;
                goto LABEL_68;
              }
              v40 = v3[13];
            }
            if ( read_hw_sel(v14, v40) )
            {
              v31 = (void *)(uintptr_t)(off_112734);
              *(volatile uint16_t *)off_112734 = 1;
LABEL_68:
              *((volatile uint32_t *)v3 + 1) = (int)(uintptr_t)(v31);
              *((volatile uint16_t *)v3 + 4) = 2;
              *v3 = 4;
              goto LABEL_86;
            }
LABEL_156:
            v31 = (void *)(uintptr_t)(off_1128A0);
            *(volatile uint16_t *)off_1128A0 = 0;
            goto LABEL_68;
          case 1u:
            if ( *(volatile uint8_t *)off_11241C != 4 && *((volatile uint16_t *)v3 + 8) )
              goto LABEL_54;
            if ( (v3[12] & 0x1F) != 2 || *((volatile uint16_t *)v3 + 7) )
              goto LABEL_79;
            set_hw_cfg_c((void *)(uintptr_t)((*((volatile uint16_t *)v3 + 8) >> 7) & 1), *((volatile uint16_t *)v3 + 8) & 0xF);
            *v3 = 7;
            if ( v13 == 4 )
              goto LABEL_44;
            goto LABEL_73;
          case 3u:
            if ( *(volatile uint8_t *)off_11241C != 4 && *((volatile uint16_t *)v3 + 8) )
              goto LABEL_54;
            if ( (v3[12] & 0x1F) != 0 )
            {
              if ( (v3[12] & 0x1F) != 2 || *((volatile uint16_t *)v3 + 7) )
              {
LABEL_79:
                *v3 = 7;
                if ( v12 == 4 )
                {
LABEL_60:
                  if ( *v11 != 4 )
                    goto LABEL_56;
                }
                goto LABEL_49;
              }
              set_hw_cfg_b((void *)(uintptr_t)((*((volatile uint16_t *)v3 + 8) >> 7) & 1), *((volatile uint16_t *)v3 + 8) & 0xF);
              *v3 = 7;
              if ( v13 != 4 )
                goto LABEL_73;
            }
            else
            {
              v68 = *((volatile uint16_t *)v3 + 7);
              if ( v68 != 2 )
              {
                v39 = v68 == 1;
                *v3 = 7;
LABEL_89:
                if ( v13 != 4 || *v11 == 4 )
                {
                  if ( v39 )
                    break;
                }
                else
                {
                  call_get_node();
                  if ( v39 )
                    break;
                }
                goto LABEL_49;
              }
              *(volatile uint8_t *)off_1128A4 = HIBYTE(*((volatile uint16_t *)v3 + 8));
              *v3 = 7;
              if ( v12 != 4 )
                goto LABEL_73;
            }
LABEL_44:
            if ( *v11 == 4 )
              goto LABEL_73;
LABEL_45:
            call_get_node();
            break;
          case 5u:
            v34 = *((volatile uint16_t *)v3 + 7);
            *((volatile uint32_t *)off_112738 + 512) = (16 * v34) & 0x7F0 | *((volatile uint32_t *)off_112738 + 512) & 0xFFFFF80F;
            *v3 = 7;
            if ( v34 )
              *v11 = 3;
            else
              *v11 = 2;
            goto LABEL_72;
          case 6u:
            v32 = *((volatile uint16_t *)v3 + 7);
            v33 = v32 >> 8;
            switch ( v32 >> 8 )
            {
              case 1u:
                v41 = (volatile uint8_t *)(*v9)(1, v33);
                if ( !v41 )
                  goto LABEL_54;
                v42 = *v41;
                if ( v42 != 18 || v41[1] != 1 )
                  goto LABEL_54;
                goto LABEL_102;
              case 2u:
                v45 = (volatile uint8_t *)v9[1](0, v33);
                if ( !v45 || *v45 != 9 || v45[1] != 2 )
                  goto LABEL_54;
                v46 = (uint8_t)v45[3];
                v47 = (uint8_t)v45[2];
                *((volatile uint32_t *)v3 + 1) = (int)(uintptr_t)(v45);
                *((volatile uint16_t *)v3 + 4) = v47 | (v46 << 8);
                v48 = *(volatile uint8_t *)off_112730;
                if ( (v45[7] & 0x40) != 0 )
                  v49 = v48 | 1;
                else
                  v49 = v48 & 0xFE;
                *(volatile uint8_t *)off_112730 = v49;
                goto LABEL_103;
              case 3u:
                v44 = (volatile uint8_t *)v9[2]((uint8_t)v32, v33);
                *((volatile uint32_t *)v3 + 1) = (int)(uintptr_t)(v44);
                if ( !v44 )
                  goto LABEL_54;
                *((volatile uint16_t *)v3 + 4) = *v44;
                goto LABEL_103;
              case 4u:
              case 5u:
                goto LABEL_59;
              case 6u:
                v41 = (volatile uint8_t *)(*v9)(6, v33);
                if ( !v41 )
                  goto LABEL_54;
                v42 = *v41;
                if ( v42 != 10 || v41[1] != 6 )
                  goto LABEL_54;
                goto LABEL_102;
              case 0xFu:
                v41 = (volatile uint8_t *)(*v9)(15, v33);
                if ( !v41 || *v41 != 5 || v41[1] != 15 )
                  goto LABEL_54;
                v42 = (v42 & ~0xFFFFu) | ((uint16_t)(v41[2]) & 0xFFFFu);
LABEL_102:
                *((volatile uint16_t *)v3 + 4) = v42;
                *((volatile uint32_t *)v3 + 1) = (int)(uintptr_t)(v41);
LABEL_103:
                v43 = *((volatile uint16_t *)v3 + 9);
                if ( *((volatile uint16_t *)v3 + 4) > v43 )
                  *((volatile uint16_t *)v3 + 4) = v43;
                *v3 = 4;
                break;
              default:
                debug_printf("Unknown descriptor: %d", v33);
                goto LABEL_54;
            }
            goto LABEL_86;
          case 8u:
            *((volatile uint32_t *)v3 + 1) = dword_112744;
            *((volatile uint16_t *)v3 + 4) = 2;
            *v3 = 4;
            goto LABEL_86;
          case 9u:
            v39 = wlan_process_packet();
            goto LABEL_89;
          case 0xAu:
            if ( *(volatile uint8_t *)off_11241C != 4 )
              goto LABEL_54;
            v37 = (void *)(uintptr_t)(off_11273C);
            *v3 = *(volatile uint8_t *)off_11241C;
            v38 = (void *)(uintptr_t)(off_112740);
            *((volatile uint16_t *)v3 + 8) = *v37;
            *((volatile uint32_t *)v3 + 1) = (int)(uintptr_t)(v38);
            *((volatile uint16_t *)v3 + 4) = 1;
LABEL_86:
            if ( v13 != 4 )
              goto LABEL_87;
            goto LABEL_152;
          case 0xBu:
            v35 = v9[6];
            if ( !v35 || !v35(*((volatile uint16_t *)v3 + 8), *((volatile uint16_t *)v3 + 7)) )
              goto LABEL_54;
            v36 = (void *)(uintptr_t)(off_112740);
            *(volatile uint16_t *)off_11273C = *((volatile uint16_t *)v3 + 8);
            *v36 = *((volatile uint16_t *)v3 + 7);
            *v3 = 7;
LABEL_72:
            if ( v13 != 4 )
              goto LABEL_73;
LABEL_152:
            if ( *v11 != 4 )
              goto LABEL_45;
            break;
          default:
LABEL_59:
            if ( v13 != 4 )
              goto LABEL_49;
            goto LABEL_60;
        }
      }
      v24 = *v3;
      switch ( v24 )
      {
        case 3:
          if ( !*((volatile uint32_t *)v3 + 1) )
            *((volatile uint32_t *)v3 + 1) = dword_112418;
          goto LABEL_50;
        case 4:
LABEL_87:
          send_data_word((int)(uintptr_t)(*((volatile char **)v3 + 1)), *((volatile uint16_t *)v3 + 4));
          goto LABEL_50;
        case 7:
LABEL_73:
          set_tx_control();
          goto LABEL_50;
      }
LABEL_49:
      *v3 = 0;
      unknown_handler(0, 0x200000, 0);
      unknown_handler2(0, 0x200000, 0);
LABEL_50:
      v25 = *(volatile uint32_t **)v4;
      a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)(*(volatile uint32_t *)off_112404) & 0xFFFFFFFFu);
      v26 = (void *)(uintptr_t)(off_1123FC);
      *v25 = dword_112408;
      v25[1] = a1;
LABEL_51:
      v26[709] = (int)(uintptr_t)(v25);
      v26[706] = v26[706];
      v26[704] |= 0x84000000;
      return a1;
    }
    v4 = (void *)(uintptr_t)(off_1123F8);
    v3 = (volatile uint8_t *)off_1123F4;
    v20 = *(volatile uint32_t **)off_1123F8;
    if ( (*(volatile uint8_t *)(*(volatile uint32_t *)off_1123F8 + 3) & 1) == 0 )
    {
      v21 = *(volatile uint8_t *)off_1123F4;
      switch ( v21 )
      {
        case 2:
          goto LABEL_7;
        case 3:
          v51 = *((volatile uint16_t *)off_1123F4 + 5);
          v52 = (volatile int *)off_112748;
          v53 = 64 - *(volatile uint16_t *)v20;
          if ( v53 >= (uint16_t)(*((volatile uint16_t *)off_1123F4 + 4) - v51) )
            v53 = (v53 & ~0xFFFFu) | ((uint16_t)(*((volatile uint16_t *)off_1123F4 + 4) - v51) & 0xFFFFu);
          memcpy((volatile char *)(v51 + *((volatile uint32_t *)off_1123F4 + 1)), *(volatile char **)off_112748, (uint16_t)v53);
          v54 = *((volatile uint16_t *)v3 + 4);
          v55 = (uint16_t)(v53 + *((volatile uint16_t *)v3 + 5));
          *((volatile uint16_t *)v3 + 5) = v55;
          if ( v54 == v55 )
          {
            v63 = *((void ( **)(volatile uint8_t *))off_112894 + 4);
            if ( v63 )
              v63(v3);
            a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)(v2 << 26) & 0xFFFFFFFFu);
            if ( (v2 & 0x20) == 0 )
            {
              *v3 = 6;
              return a1;
            }
            v64 = *(volatile uint32_t **)v4;
            v65 = *v52;
            v66 = (void *)(uintptr_t)(off_112890);
            *v64 = dword_11289C;
            v64[1] = v65;
            v66[709] = (int)(uintptr_t)(v64);
            v66[706] = v66[706];
            v66[704] |= 0x84000000;
            *v3 = 7;
            v66[517] |= 0x10u;
            a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)(set_tx_control()) & 0xFFFFFFFFu);
            goto LABEL_19;
          }
          v56 = *(volatile uint32_t **)v4;
          a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)(*v52) & 0xFFFFFFFFu);
          v57 = (void *)(uintptr_t)(off_112738);
          *v56 = dword_11274C;
          v56[1] = a1;
          v57[709] = (int)(uintptr_t)(v56);
          v57[706] = v57[706];
          v57[704] |= 0x84000000;
          break;
        case 5:
          v26 = (void *)(uintptr_t)(off_112738);
          *(volatile uint8_t *)off_1123F4 = 0;
          v25 = *(volatile uint32_t **)v4;
          v50 = (void *)(uintptr_t)(off_112748);
          a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)(dword_11274C) & 0xFFFFFFFFu);
          v26[517] &= ~0x10u;
          v26[516] &= ~0x10u;
          a1 = (a1 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(*v50) << 32);
          *(volatile uint64_t *)v25 = a1;
          goto LABEL_51;
        default:
          v22 = (void *)(uintptr_t)(off_1123FC);
          a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)(*(volatile uint32_t *)off_112404) & 0xFFFFFFFFu);
          *v20 = dword_112408;
          v20[1] = a1;
          v22[709] = (int)(uintptr_t)(v20);
          v22[706] = v22[706];
          v22[704] |= 0x84000000;
          break;
      }
      goto LABEL_18;
    }
    if ( *(volatile uint8_t *)off_1123F4 )
      a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)(set_hw_cfg_a((void *)(uintptr_t)(1), 0)) & 0xFFFFFFFFu);
    *v3 = 1;
  }
  return a1;
}


// phy_is_calibrated @ 0x1128a8
int phy_is_calibrated() {
  volatile uint8_t *v0; // r3
  volatile uint32_t *v1; // r4
  volatile uint32_t *v2; // r3
  volatile int *v3; // r1
  int v4; // r5
  volatile uint32_t *v5; // r4
  int i; // r0
  int v7; // r3
  volatile uint32_t *v8; // r3
  volatile int *v9; // r1
  int v10; // lr
  int v11; // r12
  volatile int *v12; // r6
  int v13; // r5
  int v14; // r0
  volatile int *v15; // r2
  volatile uint32_t *v16; // r4
  volatile uint32_t *v17; // r3
  volatile uint32_t *v18; // r3
  volatile int *v19; // r0
  int result; // r0
  int ( *v21)(uint32_t); // r3
  volatile uint16_t *v22; // r2
  int v23; // r4
  volatile uint32_t *v24; // r1
  volatile uint32_t *v25; // r3
  volatile uint32_t *v26; // r2
  volatile uint32_t *v27; // r3

  v0 = (void *)(uintptr_t)(off_112AF4);
  v1 = (void *)(uintptr_t)(off_112AF8);
  *(volatile uint8_t *)off_112AF0 = 2;
  *v0 = 0;
  v1[896] &= ~1u;
  v1[513] &= ~1u;
  call_get_node();
  if ( (v1[6] & 0x80) != 0 )
    v1[6] &= ~0x80u;
  v2 = (void *)(uintptr_t)(off_112AF8);
  *((volatile uint32_t *)off_112AF8 + 513) |= 0x200u;
  while ( (v2[5] & 0x80) == 0 )
    ;
  v3 = (volatile int *)off_112AFC;
  v4 = dword_112B00;
  v5 = (void *)(uintptr_t)(off_112AFC);
  for ( i = 1; ; ++i )
  {
    if ( i == 1 )
    {
      if ( (*v5 & 0x80008000) != 0 )
        *v5 |= v4;
      goto LABEL_11;
    }
    v7 = *v3;
    if ( (*v3 & 0x80008000) != 0 )
    {
      *v3 |= v4;
      if ( v7 < 0 )
      {
        v3[2] = 2;
        *v3 |= 0x40000000u;
        while ( (v3[2] & 2) == 0 )
          ;
      }
      if ( (v7 & 0x8000) == 0 )
        *v3 &= ~0x8000u;
    }
    if ( i == 6 )
      break;
LABEL_11:
    v3 += 8;
  }
  v8 = (void *)(uintptr_t)(off_112AF8);
  *((volatile uint32_t *)off_112AF8 + 513) |= 0x400u;
  v8[513] |= 0x80u;
  while ( (v8[5] & 0x40) == 0 )
    ;
  v9 = (volatile int *)off_112B04;
  v10 = dword_112B20;
  v11 = dword_112B00;
  v12 = (volatile int *)off_112B04;
  v13 = 1;
  while ( 2 )
  {
    if ( v13 == 1 )
    {
      v14 = *v12;
      if ( (*v12 & 0x80008000) != 0 )
      {
        v16 = (volatile uint32_t *)v10;
        v15 = v12;
LABEL_20:
        *v16 = 64;
        *v15 |= v11;
        if ( v14 < 0 )
        {
          if ( (v14 & 0x20000) == 0 )
          {
            while ( (*v16 & 0x40) == 0 )
              ;
            *v16 = 64;
          }
          *v16 = 2;
          *v15 |= 0x40000000u;
          while ( (*v16 & 2) == 0 )
            ;
        }
        if ( (v14 & 0x8000) == 0 )
          *v15 &= ~0x8000u;
        goto LABEL_23;
      }
      goto LABEL_24;
    }
    v14 = *v9;
    v15 = v9;
    if ( (*v9 & 0x80008000) != 0 )
    {
      v16 = (void *)(v9 + 2);
      goto LABEL_20;
    }
LABEL_23:
    if ( v13 != 6 )
    {
LABEL_24:
      ++v13;
      v9 += 8;
      continue;
    }
    break;
  }
  v17 = (void *)(uintptr_t)(off_112AF8);
  *((volatile uint32_t *)off_112AF8 + 4) = 1072;
  while ( (v17[4] & 0x30) != 0 )
    ;
  v17[513] |= 0x100u;
  v17[519] = 65537;
  v17[517] = 41;
  v17[516] = 9;
  v17[6] |= 0xC0000u;
  if ( (v17[18] & 0x80000) != 0 )
  {
    v22 = (void *)(uintptr_t)(off_112B18);
    v23 = dword_112B1C;
    v24 = (void *)(uintptr_t)(off_112AF8);
    v17[9] = 285;
    v17[10] = v23;
    *v22 = 318;
    v17[513] |= 0x80u;
    while ( (v24[5] & 0x40) == 0 )
      ;
    while ( *((volatile int *)off_112AF8 + 4) >= 0 )
      ;
    v25 = (void *)(uintptr_t)(off_112AF8);
    *((volatile uint32_t *)off_112AF8 + 4) = 1056;
    while ( (v25[4] & 0x20) != 0 )
      ;
    v26 = (void *)(uintptr_t)(off_112AF8);
    v25[513] |= 0x100u;
    v25[513] |= 0x200u;
    while ( (v26[5] & 0x80) == 0 )
      ;
    v27 = (void *)(uintptr_t)(off_112AF8);
    v26[4] |= 0x10u;
    while ( (v27[4] & 0x10) != 0 )
      ;
    v27[513] |= 0x400u;
  }
  v18 = (void *)(uintptr_t)(off_112B08);
  v19 = (volatile int *)dword_112B0C;
  *((volatile uint32_t *)off_112AF8 + 512) &= 0xFFFFF80F;
  v18[1] = 0;
  v18[2] = 0;
  *(volatile uint8_t *)v18 = 0;
  memset(v19, 0, 0x50u);
  memset((volatile int *)dword_112B10, 0, 0x50u);
  result = update_packet_buffer();
  v21 = *((int ( **)(uint32_t))off_112B14 + 8);
  if ( v21 )
    return v21(0);
  return result;
}



// wlan_get_state @ 0x112b24
int wlan_get_state() {
  int result; // r0

  if ( (((volatile uint32_t *)(uintptr_t)off_112B4C)[44] & 0x40000000) != 0 )
    result = (int)radio_tx_write_string(aUsbSusp_0);
  else
    result = alloc_tx_event(aUsbSusp);
  *(volatile uint8_t *)off_112B54 = 1;
  return result;
}


// phy_get_status @ 0x112b5c
/* luna: Returns the current PHY status byte from a volatile global. */
int phy_get_status() {
  return *(volatile uint8_t *)off_112B64;
}



// mac_get_int_status @ 0x112b68
int mac_get_int_status() {
  int result; // r0
  volatile uint32_t *v1; // r2

  if ( (((volatile uint32_t *)(uintptr_t)off_112B98)[44] & 0x40000000) != 0 )
    result = (int)radio_tx_write_string(aUsbWkup_0);
  else
    result = alloc_tx_event(aUsbWkup);
  v1 = (void *)(uintptr_t)(off_112BA4);
  *(volatile uint8_t *)off_112BA0 = 0;
  v1[896] &= ~1u;
  return result;
}


// rf_helper @ 0x112bac
int rf_helper() {
  volatile uint32_t *v0; // r3
  int v1; // r2
  int v2; // r4
  uint64_t v3; // r0
  int v4; // r10
  int v5; // r2
  int v6; // r8
  int v7; // r11
  volatile uint32_t *v8; // r6
  int v9; // r5
  unsigned int v10; // r2
  int v11; // r4
  int v12; // r9
  volatile char *v13; // r3
  int v14; // r1
  int ( *v15)(int, int, BOOL); // r3
  volatile uint32_t *v16; // r5
  int v17; // r6
  int v18; // r9
  int v19; // r7
  int i; // r4
  volatile char *v21; // r3
  int v22; // r2
  uint64_t v23; // r0
  int v24; // r3
  int v25; // r3
  int v26; // r3
  volatile uint32_t *v27; // r3
  volatile uint32_t *v28; // r4
  volatile int *v29; // r0
  int v30; // r1
  int v31; // r4
  int ( *v32)(int, int, uint32_t); // r3
  BOOL v34; // [sp+4h] [bp-10h]
  int v35; // [sp+4h] [bp-10h]
  int v36; // [sp+8h] [bp-Ch]
  int v37; // [sp+8h] [bp-Ch]
  int v38; // [sp+Ch] [bp-8h]
  int v39; // [sp+Ch] [bp-8h]

  v0 = (void *)(uintptr_t)(off_112E00);
  v1 = *((volatile uint32_t *)off_112E00 + 5);
  *((volatile uint32_t *)off_112E00 + 5) = v1;
  v2 = v0[6] & v1;
  v3 = (v3 & ~0xFFFFFFFFull) | ((uint32_t)(v2 << 19) & 0xFFFFFFFFu);
  if ( (v2 & 0x1000) != 0 )
  {
    v3 = (v3 & ~0xFFFFFFFFull) | ((uint32_t)(phy_is_calibrated()) & 0xFFFFFFFFu);
    v4 = v2 & 0x2000;
    if ( (v2 & 0x2000) == 0 )
      return v3;
    v7 = 0;
    v6 = 0;
    v5 = 0;
  }
  else
  {
    v4 = v2 & dword_112E28;
    v5 = v2 & 0x40000;
    v6 = v2 & 0x80000;
    v7 = v2 & 0x800;
    if ( (v2 & 0x2000) == 0 )
      goto LABEL_3;
  }
  v26 = *((volatile uint32_t *)off_112E00 + 514);
  if ( (v26 & 6) != 0 && (v26 & 2) != 0 )
    *(volatile uint32_t *)off_112E14 = 1;
  v27 = (void *)(uintptr_t)(off_112E00);
  v28 = (void *)(uintptr_t)(off_112E18);
  v29 = (volatile int *)off_112E1C;
  v30 = dword_112E20;
  *((volatile uint32_t *)off_112E00 + 576) = dword_112E20;
  v27[704] = v30;
  v3 = (v3 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(*v28) << 32);
  v31 = *v29;
  v3 = (v3 & ~0xFFFFFFFFull) | ((uint32_t)(dword_112E24) & 0xFFFFFFFFu);
  *(volatile uint32_t *)HIDWORD(v3) = dword_112E24;
  *(volatile uint32_t *)(HIDWORD(v3) + 4) = v31;
  v27[709] = HIDWORD(v3);
  v27[706] = v27[706];
  v27[704] |= 0x84000000;
LABEL_3:
  if ( v5 )
  {
    v8 = (void *)(uintptr_t)(off_112E00);
    v9 = dword_112E04;
    v10 = *((volatile uint32_t *)off_112E00 + 518);
    v11 = 0;
    v12 = v10 & *((volatile uint32_t *)off_112E00 + 519);
    while ( 1 )
    {
      v3 = (v3 & ~0xFFFFFFFFull) | ((uint32_t)(1) & 0xFFFFFFFFu);
      if ( ((1 << v11) & v12) != 0 )
      {
        if ( !v11 )
        {
          v3 = (v3 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(v8[578]) << 32);
          v8[578] = HIDWORD(v3);
          v25 = v8[516] & HIDWORD(v3);
          if ( (v25 & 0x18) != 0 )
          {
            v8[516] &= ~0x10u;
            unknown_handler2(0, 0x200000, 0);
          }
          else if ( (v25 & 1) != 0 )
          {
            wlan_reset(v3, (volatile uint32_t *)v10);
          }
          goto LABEL_14;
        }
        v13 = (volatile char *)&v8[8 * v11 - 8];
        v10 = *((volatile uint32_t *)v13 + 586);
        *((volatile uint32_t *)v13 + 586) = v10;
        v14 = v8[516] & v10;
        if ( (v14 & 9) != 0 )
        {
          if ( *(volatile uint8_t *)(v9 - 5) )
          {
            v36 = *(volatile uint32_t *)(v9 - 12);
            v38 = *(volatile uint32_t *)(v9 - 16);
            v34 = (v10 & 1) == 0;
            if ( (v10 & 1) == 0 )
              set_hw_cfg_a((void *)(uintptr_t)(1), (uint8_t)v11);
            v3 = (v3 & ~0xFFFFFFFFull) | ((uint32_t)(memset((volatile int *)(v9 - 16), 0, 0x10u)) & 0xFFFFFFFFu);
            v15 = *(int ( **)(int, int, BOOL))(dword_112E08 + 4 * v11 + 52);
            if ( v15 )
              v3 = (v3 & ~0xFFFFFFFFull) | ((uint32_t)(v15(v38, v36, v34)) & 0xFFFFFFFFu);
          }
        }
        else
        {
          v3 = (v3 & ~0xFFFFFFFFull) | ((uint32_t)(debug_printf("irq %x\r\n", v14)) & 0xFFFFFFFFu);
        }
      }
      if ( (uint8_t)v11 == 5 )
        break;
LABEL_14:
      ++v11;
      v9 += 16;
    }
  }
  if ( v6 )
  {
    v16 = (void *)(uintptr_t)(off_112E00);
    v17 = dword_112E0C;
    v18 = dword_112E2C;
    v19 = *((volatile uint32_t *)off_112E00 + 518) & *((volatile uint32_t *)off_112E00 + 519);
    for ( i = 0; ; ++i )
    {
      if ( ((0x10000 << i) & v19) != 0 )
      {
        if ( !i )
        {
          v23 = (v23 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(v16[706]) << 32);
          v16[706] = HIDWORD(v23);
          v24 = v16[517] & HIDWORD(v23);
          if ( (v24 & 0x10) != 0 )
          {
            v16[517] &= ~0x10u;
            v3 = (v3 & ~0xFFFFFFFFull) | ((uint32_t)(unknown_handler(0, 0x200000, 0)) & 0xFFFFFFFFu);
          }
          else if ( (v24 & 0x29) != 0 )
          {
            v23 = (v23 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
            v3 = (v3 & ~0xFFFFFFFFull) | ((uint32_t)(wlan_reset(v23, (volatile uint32_t *)(v24 << 27))) & 0xFFFFFFFFu);
          }
          goto LABEL_19;
        }
        v21 = (volatile char *)&v16[8 * i - 8];
        v22 = *((volatile uint32_t *)v21 + 714);
        *((volatile uint32_t *)v21 + 714) = v22;
        if ( (v16[517] & v22 & 1) != 0 )
        {
          if ( *(volatile uint8_t *)(v17 - 8) )
          {
            v37 = **(volatile uint16_t **)(v18 + 4 * i);
            v35 = *(volatile uint32_t *)(v17 - 12);
            v39 = *(volatile uint32_t *)(v17 - 16);
            v3 = (v3 & ~0xFFFFFFFFull) | ((uint32_t)(memset((volatile int *)(v17 - 16), 0, 0x10u)) & 0xFFFFFFFFu);
            v32 = *(int ( **)(int, int, uint32_t))(4 * i + dword_112E08 + 32);
            if ( v32 )
              v3 = (v3 & ~0xFFFFFFFFull) | ((uint32_t)(v32(v39, v35 - v37, 0)) & 0xFFFFFFFFu);
          }
        }
      }
      if ( (uint8_t)i == 5 )
        break;
LABEL_19:
      v17 += 16;
    }
  }
  if ( v7 )
  {
    v3 = (v3 & ~0xFFFFFFFFull) | ((uint32_t)(wlan_get_state()) & 0xFFFFFFFFu);
    if ( v4 >= 0 )
      return v3;
  }
  else if ( v4 >= 0 )
  {
    return v3;
  }
  v3 = (v3 & ~0xFFFFFFFFull) | ((uint32_t)(mac_get_int_status()) & 0xFFFFFFFFu);
  return v3;
}


// phy_irq_handler @ 0x112e30
/* luna: Serializes PHY interrupt processing, checks PHY status after a hardware settling delay, dispatches a USB remote-wakeup notification, and restores IRQ  */
int phy_irq_handler() {
  volatile int *active_handler_count; // r4
  volatile uint8_t *pending_wakeup_flag; // r5
  int wakeup_pending; // r2
  int handler_depth; // r3
  volatile unsigned int delay_start_ticks; // r2
  unsigned int delay_deadline_ticks; // r2
  int ticks_remaining; // r3
  uint16_t phy_status; // r1
  int result; // r0
  int remaining_handler_depth; // r3
  int reenable_irq_on_exit; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)dword_112EB0 = 1;
  }
  active_handler_count = (volatile int *)dword_112EB4;
  pending_wakeup_flag = (volatile uint8_t *)dword_112EB8;
  wakeup_pending = *(volatile uint8_t *)dword_112EB8;
  handler_depth = *(volatile uint32_t *)dword_112EB4 + 1;
  *(volatile uint32_t *)dword_112EB4 = handler_depth;
  if ( wakeup_pending )
  {
    *(volatile uint32_t *)(dword_112EBC + 0x804) |= 1u;
    delay_start_ticks = (*(volatile uint32_t *)0x40501010u);
    delay_deadline_ticks = delay_start_ticks + 9000;
    do
      ticks_remaining = delay_deadline_ticks - (*(volatile uint32_t *)0x40501010u);
    while ( ticks_remaining >= 0 );
    phy_status = *(volatile uint16_t *)(dword_112EC4 + 0xB2);
    *(volatile uint32_t *)(dword_112EBC + 0x804) &= ~1u;
    if ( (phy_status & 0x4000) != 0 )
      result = (int)radio_tx_write_string(aUsbRmtwkup);
    else
      result = alloc_tx_event(aUsbRmtwkup_0);
    handler_depth = *active_handler_count;
    *pending_wakeup_flag = 0;
  }
  if ( handler_depth )
  {
    remaining_handler_depth = handler_depth - 1;
    reenable_irq_on_exit = *(volatile uint32_t *)dword_112EB0;
    *active_handler_count = remaining_handler_depth;
    if ( !remaining_handler_depth )
    {
      if ( reenable_irq_on_exit )
        __enable_irq();
    }
  }
  return result;
}


// rx_increment_count @ 0x112ed0
int rx_increment_count(int a1, volatile uint16_t *a2) {
  int v4; // r2
  int v5; // r3
  int v6; // r2

  phy_irq_handler();
  if ( *(volatile uint8_t *)off_112F34 != 4 )
    return 1;
  v4 = a1 - 1;
  if ( (uint8_t)(a1 - 1) > 5u )
    return 2;
  if ( (*((volatile uint32_t *)&REG_4020_0900 + 8 * a1) & 0x8000) == 0 )
    return 5;
  v5 = 32 * v4 + 0x40000000;
  v6 = dword_112F38 + 16 * v4;
  *(volatile uint32_t *)(v6 + 4) = *a2;
  *(volatile uint8_t *)(v6 + 11) = 1;
  *(volatile uint32_t *)(v5 + 2099508) = (int)(uintptr_t)(a2);
  *((volatile uint32_t *)&REG_4020_0900 + 8 * a1) |= 0x84000000;
  return 0;
}



// get_global_flag @ 0x112f84
int get_global_flag() {
  return dword_112F88;
}



// rf_read_status @ 0x112fc4
/* luna: Validates received USB wireless frames and dispatches advertising reports or queues WLAN messages for ioctl handling. */
int rf_read_status(volatile uint8_t *a1, unsigned int a2, int a3) {
  volatile uint16_t *rx_event_count; // r7
  volatile uint8_t *rx_status; // r6
  volatile uint8_t *v5; // r4
  char v6; // r2
  int frame_type; // r8
  int declared_length; // r6
  volatile uint8_t *rx_queue_state; // r8
  char queued_count; // r5
  int v13; // r0
  unsigned int queue_slot_index; // r3
  volatile uint32_t *queue_entry; // r3

  rx_event_count = (volatile uint16_t *)off_11312C;
  rx_status = (volatile uint8_t *)off_113130;
  v5 = (void *)(uintptr_t)(off_113134);
  ++*(volatile uint16_t *)off_11312C;
  if ( a3 )
    v6 = 3;
  else
    v6 = 2;
  *rx_status = v6;
  *v5 = 0;
  if ( *rx_status != 2 )
  {
    debug_printf("usb wlan recv err %X %d\n", *rx_event_count, *rx_status);
    check_global_value(off_113148);
    return 1;
  }
  *rx_status = 0;
  if ( a2 <= 3 )
  {
    debug_printf("len err %X %d\n", *rx_event_count, a2);
  }
  else
  {
    frame_type = a1[2];
    declared_length = *a1 | (a1[1] << 8) & 0xF00;
    if ( *(volatile uint8_t *)off_113138 )
      check_feature_flag(512, "R:%d\n", a2);
    if ( frame_type == 1 )
    {
      if ( a2 == declared_length || declared_length + 1 == a2 )
      {
        util_init_buffer();
        handle_rx_descriptor((int)(a1 + 4));
        irq_disable_global_2(512);
        return 1;
      }
      debug_printf("wdl err %X %d %d\n", *rx_event_count, declared_length, a2);
    }
    else if ( frame_type == 17 )
    {
      rx_queue_state = (void *)(uintptr_t)(off_113168);
      if ( *((volatile uint8_t *)off_113168 + 2433) >= (unsigned int)*((volatile uint8_t *)off_113168 + 2434) )
      {
        debug_printf(aErrNoRxMsgElem);
      }
      else
      {
        if ( declared_length + 4 == a2 || a2 == declared_length + 5 )
        {
          util_init_buffer();
          queued_count = rx_queue_state[2433];
          v13 = dword_113140;
          queue_slot_index = (uint8_t)rx_queue_state[2432]
              + 1
              - 40
              * ((unsigned int)(((unsigned int)dword_11313C
                               * (uint64_t)((unsigned int)(uint8_t)rx_queue_state[2432] + 1)) >> 32) >> 5);
          rx_queue_state[2432] = queue_slot_index;
          queue_entry = (void *)(&rx_queue_state[20 * queue_slot_index]);
          queue_entry[409] = (int)(uintptr_t)(a1 + 4);
          queue_entry[412] = declared_length;
          rx_queue_state[2433] = queued_count + 1;
          co_list_push_back(v13, queue_entry + 408);
          irq_disable_global_2(0x400000);
          return 1;
        }
        debug_printf("wml err %X %d %d\n", *rx_event_count, declared_length, a2);
      }
    }
    else
    {
      debug_printf("type err %X %X %d %d\r\n", *rx_event_count, frame_type, declared_length, a2);
    }
  }
  pkt_mem_free((void *)(&a1[-*(volatile uint32_t *)off_113150]));
  util_init_buffer();
  return 1;
}


// bt_wait_ready @ 0x11316c
int bt_wait_ready(int a1) {
  volatile uint16_t *v2; // r4
  int v3; // r2
  int v4; // r1
  volatile uint8_t *v5; // r1
  volatile uint8_t *v6; // r2
  int v7; // r1
  int v8; // r4

  if ( (*(volatile uint32_t *)off_1131EC & 0x2000000) != 0 )
  {
    memset((volatile int *)off_1131F0, 0xFFu, 4u);
  }
  else
  {
    v2 = (volatile uint16_t *)off_1131F0;
    memset((volatile int *)off_1131F0, 0xFFu, 4u);
    if ( get_rssi((int)v2) || (v3 = v2[1], v3 == 0xFFFF) || (v4 = *v2, v4 == 0xFFFF) )
      alloc_tx_event(aNoUsbInfoInFla);
    else
      alloc_tx_event("get vid %x, pid %x\r\n", v4, v3);
  }
  v5 = (void *)(uintptr_t)(off_1131FC);
  v6 = (void *)(uintptr_t)(off_113200);
  *(volatile uint32_t *)off_1131F8 = *(volatile uint32_t *)a1;
  *v5 = 0;
  *v6 = 0;
  do
  {
    v7 = *(volatile uint8_t *)(a1 + 8);
    if ( *(volatile uint8_t *)(a1 + 8) )
      v7 = 1;
    v8 = wlan_open((int)asc_1532B0, v7);
    alloc_tx_event("open res:%d\n", v8);
  }
  while ( v8 );
  return 0;
}


// bt_get_state @ 0x113210
int bt_get_state(int a1, int a2) {
  volatile uint8_t *v2; // r4
  volatile uint8_t *v3; // r6
  volatile uint32_t *v4; // r7
  int v5; // r0
  int v6; // r2

  v2 = (void *)(uintptr_t)(off_113294);
  if ( *(volatile uint8_t *)off_113294 )
    return -14;
  if ( !a1 || !a2 )
    return -11;
  v3 = (void *)(uintptr_t)(off_113298);
  if ( *(volatile uint8_t *)off_113298 )
  {
    debug_printf("err: %s state=%d\r\n", aUsbWlanRecv, *(volatile uint8_t *)off_113298);
    return -3;
  }
  else
  {
    v4 = (void *)(uintptr_t)(off_11329C);
    *(volatile uint8_t *)off_113298 = 1;
    v4[716] &= 0xE007FFFF;
    v5 = mac_read_queue_reg(1, a1, a2);
    v6 = v5;
    if ( v5 )
    {
      debug_printf("err: %s ret=%d\r\n", aUsbWlanRecv, v5);
      return -1;
    }
    else
    {
      *(volatile uint8_t *)off_1132A0 = 1;
      if ( *v2 )
      {
        ((int (*)())wlan_ctrl_check)(0, 1, 0);
        *v3 = 0;
        return -14;
      }
    }
  }
  return v6;
}


// check_and_init_flag @ 0x1132b0
int check_and_init_flag(int a1, int a2) {
  volatile uint8_t *v2; // r4
  volatile uint8_t *v3; // r5
  int v4; // r3
  volatile uint32_t *v5; // r2
  int v6; // r0
  int v7; // r2

  v2 = (void *)(uintptr_t)(off_113354);
  if ( *(volatile uint8_t *)off_113354 )
    return -14;
  if ( !a1 || !a2 )
    return -11;
  v3 = (void *)(uintptr_t)(off_113358);
  if ( *(volatile uint8_t *)off_113358 )
  {
    debug_printf("err: %s state=%d\r\n", aUsbWlanRecvFcO, *(volatile uint8_t *)off_113358);
    return -3;
  }
  else
  {
    v4 = *(volatile char *)off_11335C;
    *(volatile uint8_t *)off_113358 = 1;
    v5 = (void *)(uintptr_t)(off_113360);
    if ( v4 )
    {
      *((volatile uint32_t *)off_113360 + 716) &= 0xE007FFFF;
      v5[512] |= 0x2000u;
    }
    else
    {
      *((volatile uint32_t *)off_113360 + 713) |= 1u;
    }
    v6 = phy_save_rssi(1, a1, a2);
    v7 = v6;
    if ( v6 )
    {
      debug_printf("err: %s ret=%d\r\n", aUsbWlanRecvFcO, v6);
      return -1;
    }
    else
    {
      *(volatile uint8_t *)off_113364 = 1;
      if ( *v2 )
      {
        ((int (*)())wlan_ctrl_check)(0, 1, 0);
        *v3 = 0;
        return -14;
      }
    }
  }
  return v7;
}


// rf_is_idle @ 0x113374
int rf_is_idle() {
  volatile uint8_t *v2; // r6
  volatile int **v3; // r4
  char v4; // r0
  volatile uint8_t *v5; // r12
  volatile int *v6; // r7
  volatile int *v7; // r5
  unsigned int v8; // r4
  volatile int *v9; // r1
  char v10; // r3
  char v11; // r2
  volatile uint16_t *v12; // r1
  int v13; // r2
  char v14; // r3

  v2 = (void *)(uintptr_t)(off_113408);
  if ( *(volatile uint8_t *)off_113408 )
    return -99;
  v3 = (volatile int **)off_11340C;
  v4 = list_length((volatile uint32_t **)(uintptr_t)off_11340C);
  v5 = (void *)(uintptr_t)(off_113414);
  *(volatile uint8_t *)off_113414 = v4;
  if ( v4 )
  {
    v6 = *v3;
    v7 = *(volatile int **)(dword_113410 + 8240);
    if ( v4 != 1 )
    {
      v8 = *((volatile uint16_t *)v6 + 6);
      if ( *((volatile uint16_t *)v7 + 6) < v8 )
      {
        v9 = v6;
        v10 = v4;
        while ( 1 )
        {
          v11 = v4 - v10--;
          if ( !v8 )
            break;
          if ( !*v9 || !v10 )
          {
            *v5 = v10;
            v7 = v9;
            goto LABEL_11;
          }
          v8 = *(volatile uint16_t *)(*v9 + 12);
          v7 = v9;
          v9 = (volatile int *)*v9;
        }
        *v5 = v11;
      }
      goto LABEL_11;
    }
    if ( v7 )
    {
LABEL_11:
      v12 = (volatile uint16_t *)v6[1];
      v13 = v7[1] + 8 * (*((volatile uint8_t *)v7 + 14) - 1);
      v14 = *(volatile uint8_t *)(v13 + 3);
      *v2 = 1;
      *(volatile uint8_t *)(v13 + 3) = v14 & 0xF5 | 0xA;
      return rx_increment_count(1, v12);
    }
  }
  return -98;
}



// rf_set_state @ 0x113418
int rf_set_state(int a1, int a2, int a3) {
  volatile uint8_t *v3; // r5
  char v4; // r3
  volatile uint8_t *v5; // r4
  int v6; // r3
  int v7; // r5
  int v8; // r6
  volatile uint32_t *v9; // r0
  int v10; // r8
  int v11; // r3

  v3 = (volatile uint8_t *)off_1134C4;
  if ( a3 )
    v4 = 3;
  else
    v4 = 2;
  *(volatile uint8_t *)off_1134C4 = v4;
  if ( *v3 == 2 )
  {
    v5 = (void *)(uintptr_t)(off_1134C8);
    v6 = *(volatile uint8_t *)off_1134C8;
    *v3 = 0;
    if ( v6 )
    {
      v7 = dword_1134CC;
      v8 = dword_1134CC - 8;
      do
      {
        while ( 1 )
        {
          v9 = list_pop(v7);
          v10 = *(volatile uint32_t *)(v9[1] + 4);
          --*v5;
          co_list_push_back(v8, v9);
          v11 = *(volatile uint8_t *)(v10 + 2) >> 4;
          if ( v11 )
            break;
          ++*(volatile uint16_t *)off_1134D4;
          irq_disable_global_2(128);
          if ( !*v5 )
            goto LABEL_12;
        }
        if ( v11 == 1 )
        {
          pkt_mem_free((volatile uint32_t *)v10);
        }
        else
        {
          debug_printf("###err### %x\r\n", v10);
          process_packet_params(v10, 32, 1, 0);
        }
      }
      while ( *v5 );
    }
LABEL_12:
    rf_is_idle();
    return 1;
  }
  else
  {
    debug_printf("usb wlan send err %d\n", *v3);
    check_global_value(off_1134DC);
    return 1;
  }
}


