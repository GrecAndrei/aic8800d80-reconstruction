// get_rf_capability @ 0x11b350
/* luna: Marks the indexed TX queue entry and checks the corresponding hardware status bits when the entry has no cached state. */
int get_rf_capability(int result) {
  volatile uint32_t *v1; // r5
  volatile char *v2; // r3
  int v3; // r2
  int v4; // r4
  int v5; // r6
  BOOL v6; // r3
  volatile int16_t **v7; // r7

  v1 = (void *)(uintptr_t)(off_11B41C);
  if ( *((volatile uint8_t *)off_11B41C + 160) )
  {
    v2 = (volatile char *)off_11B41C + 28 * result;
    v3 = *((volatile uint32_t *)v2 + 6);
    v2[47] = 1;
    v4 = result;
    v5 = 8 * result;
    if ( !v3 )
    {
      switch ( (char)result )
      {
        case 0:
          v6 = (*(volatile uint32_t *)off_11B420 & 0x30) == 0;
          goto LABEL_6;
        case 1:
          v6 = (*(volatile uint32_t *)off_11B420 & 0x300) == 0;
          goto LABEL_6;
        case 2:
          v6 = (*(volatile uint32_t *)off_11B420 & 0x3000) == 0;
          goto LABEL_6;
        case 3:
          v6 = (*(volatile uint32_t *)off_11B420 & 0x30000) == 0;
          goto LABEL_6;
        case 4:
          v6 = (*(volatile uint32_t *)off_11B420 & 3) == 0;
LABEL_6:
          if ( v6 )
            goto LABEL_9;
          v7 = (volatile int16_t **)off_11B424;
          break;
        default:
          v7 = (volatile int16_t **)off_11B424;
          if ( **(volatile int16_t **)off_11B424 >= 0 )
            goto LABEL_9;
          irq_disable_mmio_write(off_11B430, (int)aTxlHeEdcaQueue, 520);
          break;
      }
      if ( **v7 < 0 )
      {
        return unknown_12f2c8(off_11B430, (int)aTxlHeMuEdcaSta, 684);
      }
      else
      {
LABEL_9:
        v1[v5 - v4 + 6] = off_11B428;
        return invalid_instruction_trap(v4);
      }
    }
  }
  return result;
}


// save_rx_packet @ 0x11b438
/* luna: Records received-packet metadata and searches the channel-indexed buffer table for compatible storage. */
int save_rx_packet(int a1) {
  volatile uint32_t *v1; // r8
  volatile char *v2; // r6
  int v3; // r2
  int v5; // r3
  int16_t v6; // r4
  int v7; // r0
  unsigned int v8; // r1
  int v9; // r0
  int v10; // r4
  unsigned int v11; // r0
  int v12; // r5
  volatile char *v13; // r1
  int v14; // r6
  volatile unsigned int *v15; // r12
  volatile char *v16; // r2
  volatile char *v17; // r9
  int v18; // lr
  int16_t v19; // r3
  unsigned int v20; // r3
  unsigned int v21; // t1
  int v22; // r2
  int v23; // r0
  int16_t v24; // r2
  volatile uint32_t *v25; // r4
  volatile uint32_t *v26; // r3
  int result; // r0
  int v28; // r3
  int v29; // r2
  volatile uint32_t *v30; // r0
  volatile uint32_t *v31; // r4
  int v32; // r2
  volatile uint32_t *v33; // r1
  int v34; // r4
  int16_t v35; // r0
  unsigned int v36; // [sp+4h] [bp-8h]

  v1 = (void *)(uintptr_t)(off_11B684);
  v2 = (volatile char *)off_11B66C;
  v3 = *((volatile uint32_t *)off_11B684 + 4);
  v5 = *(volatile uint32_t *)a1 + 38;
  *((volatile uint32_t *)off_11B66C + 18) = *(volatile uint32_t *)v5;
  v6 = *(volatile uint16_t *)(v5 + 4);
  v7 = *(volatile uint32_t *)(v3 + 100);
  v8 = *(volatile uint16_t *)(a1 + 18);
  v3 = (v3 & ~0xFFFFu) | ((uint16_t)(*(volatile uint16_t *)(v3 + 104)) & 0xFFFFu);
  *(volatile uint32_t *)(v2 + 78) = v7;
  v9 = *(volatile uint32_t *)v5;
  v5 = (v5 & ~0xFFFFu) | ((uint16_t)(*(volatile uint16_t *)(v5 + 4)) & 0xFFFFu);
  *((volatile uint16_t *)v2 + 38) = v6;
  v10 = 0;
  *((volatile uint32_t *)v2 + 21) = v9;
  *((volatile uint16_t *)v2 + 41) = v3;
  *((volatile uint16_t *)v2 + 44) = v5;
  *((volatile uint32_t *)v2 + 275) = 0;
  *((volatile uint32_t *)v2 + 276) = 0;
  *((volatile uint32_t *)v2 + 6) = 0;
  v11 = align_alloc_size((int)(v2 + 92), v8);
  v12 = *((volatile uint32_t *)v2 + 6);
  v13 = v2;
  v14 = (uint16_t)(((*((volatile uint16_t *)v2 + 58) + 3) & 0xFFFC) + 4 + 4 * v11);
  v15 = (volatile unsigned int *)(36 * *(volatile uint8_t *)(*(volatile uint32_t *)a1 + 35) + 8248 + dword_11B670);
  v36 = v11 << 9;
  v16 = v13 + 92;
  v17 = v13;
  v18 = 2621440;
  while ( 1 )
  {
    v21 = *v15++;
    v20 = v21;
    if ( v21 )
      break;
LABEL_4:
    ++v10;
    v16 += 92;
    if ( v10 == 9 )
      goto LABEL_12;
  }
  if ( (unsigned int)(v14 + v12) <= *(volatile uint32_t *)(a1 + 8) )
  {
    if ( v20 <= 0x3F0 )
    {
      v19 = ((uint16_t)((v20 + 15) >> 4) << 7) | 0x30;
    }
    else if ( v20 <= 0x400 )
    {
      v19 = 8240;
    }
    else if ( v20 > 0x4300 )
    {
      if ( v20 > 0x4400 )
      {
        if ( v20 <= 0x23C00 )
        {
          v19 = ((uint8_t)((v20 - 15361) >> 11) << 7) | 0x4030;
        }
        else if ( v20 <= 0x24400 )
        {
          v19 = 24624;
        }
        else if ( v20 > dword_11B680 )
        {
          v35 = 32560;
          if ( v20 == -1 )
            v35 = 32688;
          v19 = v35;
        }
        else
        {
          v19 = ((uint8_t)((v20 - 115713) >> 15) << 7) | 0x6030;
        }
      }
      else
      {
        v19 = 16432;
      }
    }
    else
    {
      v19 = ((uint8_t)((v20 - 1009) >> 4) << 7) | 0x2030;
    }
    *((volatile uint32_t *)v16 + 9) = 0;
    *((volatile uint32_t *)v16 + 14) = v36 | v18;
    *((volatile uint32_t *)v16 + 15) = 0;
    *((volatile uint16_t *)v16 + 44) = v19 | v10;
    *((volatile uint32_t *)v17 + 2) = (int)(uintptr_t)(v16);
    v12 = *((volatile uint32_t *)v13 + 6) + v14;
    *((volatile uint32_t *)v13 + 6) = v12;
    v17 = v16;
    v18 = 3145728;
    goto LABEL_4;
  }
LABEL_12:
  v1[52] |= 2u;
  if ( v12 )
  {
    v22 = *((volatile uint32_t *)v17 + 14);
    *((volatile uint32_t *)v17 + 2) = 0;
    if ( (v22 & 0x380000) == 0x280000 )
    {
      v32 = *((volatile uint32_t *)v17 + 15);
      result = (int)off_11B674;
      v33 = (void *)(uintptr_t)(off_11B678);
      v34 = dword_11B67C;
      *((volatile uint32_t *)v17 + 1) = 0;
      *((volatile uint8_t *)v1 + 200) = 0;
      *((volatile uint32_t *)v17 + 15) = v32 & 0xFF00;
      *((volatile uint32_t *)v17 + 14) = 256;
      *((volatile uint32_t *)v17 + 9) = v34;
      *(volatile uint32_t *)result = (int)(uintptr_t)(v17);
      *v33 = 0x2000;
    }
    else
    {
      *((volatile uint32_t *)v17 + 14) = v22 | 0x380000;
      v23 = *((volatile uint32_t *)v13 + 14);
      v24 = *((volatile uint32_t *)v13 + 15);
      *((volatile uint32_t *)v13 + 1) = 0;
      *((volatile uint8_t *)v1 + 200) = 0;
      v25 = (void *)(uintptr_t)(off_11B674);
      v26 = (void *)(uintptr_t)(off_11B678);
      *((volatile uint32_t *)v13 + 14) = v23 | 0x100;
      *((volatile uint32_t *)v13 + 15) = v24 & 0xFF00;
      *v25 = (int)(uintptr_t)(v13);
      *v26 = 0x2000;
      return 0x2000;
    }
  }
  else
  {
    v28 = *((volatile uint32_t *)v13 + 38);
    v29 = dword_11B67C;
    v30 = (void *)(uintptr_t)(off_11B674);
    v31 = (void *)(uintptr_t)(off_11B678);
    *((volatile uint32_t *)v13 + 25) = 0;
    *((volatile uint32_t *)v13 + 38) = v28 & 0xFF00;
    *((volatile uint32_t *)v13 + 24) = 0;
    *((volatile uint8_t *)v1 + 200) = 0;
    *v30 = v29 - 996;
    *v31 = 0x2000;
    *((volatile uint16_t *)v13 + 90) = 48;
    *((volatile uint32_t *)v13 + 37) = 256;
    *((volatile uint32_t *)v13 + 32) = v29;
    return 48;
  }
  return result;
}



// radio_irq_check @ 0x11b688
/* luna: Sets up a timed radio operation, stages two words from the context’s current buffer, publishes the context, and issues command 0x2000. */
volatile uint32_t * radio_irq_check(volatile uint32_t *result) {
  volatile uint32_t *v1; // r2
  int v2; // r5
  volatile uint32_t *v3; // r4
  volatile uint32_t *v4; // r2
  volatile uint32_t *v5; // r3
  volatile uint32_t *v6; // r6
  int v7; // r4
  int v8; // r1
  volatile uint32_t *v9; // r5

  v1 = (void *)(uintptr_t)(off_11B6F4);
  v2 = result[9];
  v3 = (void *)(uintptr_t)(off_11B6F8);
  *(volatile uint32_t *)off_11B6F0 = *(volatile uint32_t *)off_11B6EC + 20000;
  *v1 = 64;
  v4 = (void *)(uintptr_t)(off_11B6FC);
  v5 = (void *)(uintptr_t)(off_11B700);
  v6 = (void *)(uintptr_t)(off_11B704);
  *v3 |= 0x40u;
  v5[275] = *(volatile uint32_t *)(v2 + 12);
  v7 = v4[52];
  v8 = result[15];
  v5[276] = *(volatile uint32_t *)(v2 + 16);
  v4[52] = v7 | 1;
  v9 = (void *)(uintptr_t)(off_11B708);
  result[9] = (int)(uintptr_t)(v5 + 272);
  result[15] = v8 & 0xFF00;
  result[1] = 0;
  *((volatile uint8_t *)v4 + 200) = 0;
  *v6 = (int)(uintptr_t)(result);
  *v9 = 0x2000;
  return result;
}



// tx_channel_setup @ 0x11b70c
/* luna: Prepares per-channel transmit packet state from connection metadata and a packet descriptor, clearing cached channel state when no usable packet is av */
int tx_channel_setup(int a1) {
  volatile uint32_t *v1; // r5
  int v2; // r6
  int v4; // r3
  void *v5; // r7
  int v6; // r2
  int v7; // r8
  volatile uint32_t *v8; // r4
  uint64_t v9; // r0
  volatile uint32_t *v10; // r2
  volatile uint32_t *v11; // r2
  unsigned int v12; // r3
  int v13; // r3
  volatile uint16_t *v14; // r7
  void *v15; // r7
  char v16; // r3
  int v17; // r1
  int v18; // r2
  int v19; // r2
  int v20; // r3
  volatile uint32_t *v22; // [sp+4h] [bp-4h] BYREF

  v1 = (void *)(uintptr_t)(off_11B88C);
  v2 = *((volatile uint8_t *)off_11B88C + 190);
  v22 = 0;
  mmio_modify_bit(v2);
  get_conn_env(*((volatile uint8_t *)v1 + 190));
  if ( !a1 )
    goto LABEL_24;
  v4 = *(volatile uint32_t *)(a1 + 36);
  if ( (v4 & 0x200000) != 0 )
  {
    v5 = (void *)(uintptr_t)(off_11B890);
    v6 = *(volatile uint32_t *)(a1 + 68);
    if ( *(volatile uint8_t *)(*(volatile uint32_t *)off_11B890 + 1) )
    {
      v7 = *(volatile uint32_t *)(v6 + 88);
    }
    else if ( (v4 & 0x380000) == 0x280000 || (*(volatile uint16_t *)(v6 + 8) & 0x400) != 0 )
    {
      v7 = *(volatile uint32_t *)(v6 + 20);
    }
    else
    {
      v7 = *(volatile uint32_t *)(v6 + 88);
      *(volatile uint32_t *)(v6 + 88) = *(volatile uint16_t *)(v6 + 8) & 0x400;
    }
    v9 = (v9 & ~0xFFFFFFFFull) | ((uint32_t)(rx_packet_parse((void *)(uintptr_t)(a1), (int)&v22)) & 0xFFFFFFFFu);
    v8 = v22;
    v9 = (v9 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(*(volatile uint8_t *)(*(volatile uint32_t *)v5 + 1)) << 32);
    if ( v22 )
    {
      if ( !*(volatile uint8_t *)(*(volatile uint32_t *)v5 + 1) && (v22[14] & 0x200000) != 0 )
      {
        *(volatile uint32_t *)(v9 + 4) = v7;
        v1[7 * v2 + 9] = v9;
        goto LABEL_11;
      }
      v22[1] = v7;
    }
    if ( (uint32_t)v9 )
      goto LABEL_21;
LABEL_25:
    v18 = dword_11B894;
    v9 = (v9 & ~0xFFFFFFFFull) | ((uint32_t)(84 * v2) & 0xFFFFFFFFu);
    *(volatile uint32_t *)(dword_11B894 + 84 * v2) = 0;
    v1[7 * v2 + 9] = 0;
    v19 = v18 + 84 * v2;
    if ( !HIDWORD(v9) )
    {
      *(volatile uint32_t *)(v19 + 4) = 0;
      *(volatile uint32_t *)(v19 + 8) = 0;
    }
    return v9;
  }
  if ( (*(volatile uint16_t *)(a1 + 82) & 4) == 0 )
  {
LABEL_24:
    v9 = (v9 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(*(volatile uint8_t *)(*(volatile uint32_t *)off_11B890 + 1)) << 32);
    goto LABEL_25;
  }
  v11 = *(volatile uint32_t **)(a1 + 76);
  v12 = *(volatile uint32_t *)(*(volatile uint32_t *)(a1 + 44) + 60);
  v9 = (v9 & ~0xFFFFFFFFull) | ((uint32_t)(v11 + 3) & 0xFFFFFFFFu);
  if ( (*(volatile uint16_t *)(a1 + 30) & 0x2000) != 0 )
    v13 = (v12 >> 4) & 1;
  else
    v13 = (v12 >> 3) & 1;
  v22 = v11 + 3;
  if ( v13 || (v14 = (volatile uint16_t *)v11[7], (*v14 & 0x8000) == 0) )
  {
    v8 = v11 + 3;
    v9 = (v9 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(*(volatile uint8_t *)(*(volatile uint32_t *)off_11B890 + 1)) << 32);
  }
  else
  {
    *v14 &= ~0x8000u;
    v15 = (void *)(uintptr_t)(off_11B890);
    v16 = *(volatile uint8_t *)(a1 + 50) - 4;
    *(volatile uint8_t *)(a1 + 51) -= 4;
    *(volatile uint8_t *)(a1 + 50) = v16;
    v17 = v11[9];
    v11[8] -= 4;
    v11[9] = v17 - 4;
    v9 = (v9 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(*(volatile uint8_t *)(*(volatile uint32_t *)v15 + 1)) << 32);
    v8 = v11 + 3;
  }
LABEL_21:
  v1[7 * v2 + 9] = v9;
  if ( !HIDWORD(v9) )
  {
LABEL_11:
    if ( (v8[14] & 0x200000) != 0 )
    {
      if ( !*(volatile uint32_t *)(v9 + 4) )
      {
        v20 = dword_11B894 + 84 * v2;
        v9 = (v9 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(1) << 32);
        *(volatile uint64_t *)(v20 + 4) = v9;
        *(volatile uint32_t *)v20 = (int)(uintptr_t)(v8);
      }
    }
    else if ( !v8[1] )
    {
      v10 = (volatile uint32_t *)(dword_11B894 + 84 * v2);
      v10[1] = 0;
      v10[2] = 0;
      *v10 = (int)(uintptr_t)(v8);
      v9 = (v9 & ~0xFFFFFFFFull) | ((uint32_t)(84 * v2) & 0xFFFFFFFFu);
    }
    return v9;
  }
  if ( !v8[1] )
  {
    *(volatile uint32_t *)(dword_11B894 + 84 * v2) = (int)(uintptr_t)(v8);
    v9 = (v9 & ~0xFFFFFFFFull) | ((uint32_t)(84 * v2) & 0xFFFFFFFFu);
  }
  return v9;
}



// check_mode_flag @ 0x11b898
/* luna: Consumes pending Bluetooth receive state and checks and dispatches radio-state work when controller flags permit it. */
void check_mode_flag() {
  volatile uint32_t *v0; // r4
  int v1; // r3
  int v2; // r2
  volatile uint8_t *v3; // r6
  int v4; // r0
  unsigned int v5; // lr
  char v6; // r1
  int v7; // r7
  volatile uint32_t *v8; // r2
  int v9; // r12
  int v10; // r8
  int16_t v11; // r0
  int v12; // r1
  int v13; // r0
  volatile uint32_t *v14; // lr
  volatile uint32_t *v15; // r1
  volatile uint32_t *v16; // r1
  volatile uint32_t *v17; // r6
  int v18; // r5
  int v19; // r0
  volatile uint32_t *v20; // r3
  volatile uint32_t *v21; // r0
  int v22; // r0
  volatile int *v23; // r7
  volatile char *v24; // r2
  int v25; // r5
  int v26; // r6
  int16_t v27; // r12
  int v28; // r1
  int v29; // r0
  int v30; // r0
  int v31; // r1
  int v32; // r3
  volatile uint32_t *v33; // r6
  volatile uint32_t *v34; // r0
  int v35; // [sp+4h] [bp-4h] BYREF

  v0 = (void *)(uintptr_t)(off_11BA58);
  v1 = *((volatile uint32_t *)off_11BA58 + 52);
  v35 = 0;
  if ( (v1 & 4) != 0 )
  {
    *((volatile uint32_t *)off_11BA58 + 52) = v1 & 0xFFFFFFFB;
  }
  else
  {
    v2 = *((volatile uint8_t *)off_11BA58 + 200);
    if ( *((volatile uint8_t *)off_11BA58 + 200) )
    {
      if ( *((volatile uint8_t *)off_11BA58 + 191) == 4 )
      {
        save_rx_packet((int)off_11BA58 + 168);
      }
      else
      {
        v3 = (void *)(uintptr_t)(off_11BA5C);
        if ( *((volatile uint8_t *)off_11BA5C + 1) )
        {
          v4 = *((volatile uint32_t *)off_11BA58 + 42);
          v5 = *((volatile uint8_t *)off_11BA5C + 2);
          v6 = *(volatile uint8_t *)(v4 + 34);
          if ( ((v5 >> v6) & 1) != 0 )
          {
            v7 = *(volatile uint16_t *)(v4 + 32);
            v8 = (void *)(uintptr_t)(off_11BA60);
            *((volatile uint32_t *)off_11BA60 + 303) = *((volatile uint32_t *)off_11BA58 + 45);
            v9 = v0[4];
            v10 = v8[300] & 0xFF00;
            v11 = ~((unsigned int)~(v7 << 18) >> 18);
            v7 = (v7 & ~0xFFu) | ((uint8_t)(v5 & ~(uint8_t)(1 << v6)) & 0xFFu);
            v12 = v0[46];
            *((volatile uint16_t *)v8 + 605) = v11;
            *((volatile uint16_t *)v8 + 608) = v12;
            v13 = *(volatile uint32_t *)(v9 + 100);
            v14 = (void *)(uintptr_t)(off_11BA68);
            v9 = (v9 & ~0xFFFFu) | ((uint16_t)(*(volatile uint16_t *)(v9 + 104)) & 0xFFFFu);
            v15 = (void *)(uintptr_t)(off_11BA64);
            *(volatile uint32_t *)((volatile char *)v8 + 1218) = v13;
            v0[52] = v1 | 2;
            *((volatile uint16_t *)v8 + 611) = v9;
            v8[286] = 0;
            *((volatile uint8_t *)v0 + 200) = 0;
            v8[300] = v10;
            v3[2] = v7;
            *v14 = (int)(uintptr_t)(v8 + 285);
            *v15 = 0x2000;
            return;
          }
        }
        if ( (v1 & 1) == 0 )
        {
          v21 = (volatile uint32_t *)check_radio_state(&v35);
          if ( v21 )
          {
            radio_irq_check(v21);
            v22 = v35;
            *(volatile uint32_t *)off_11BA6C &= ~0x200u;
            tx_channel_setup(v22);
            return;
          }
          v1 = v0[52];
        }
        v23 = (volatile int *)dword_11BA70;
        v24 = (volatile char *)off_11BA60;
        v25 = v0[4];
        v26 = *((volatile uint32_t *)off_11BA60 + 244);
        v27 = *(volatile uint16_t *)(v25 + 104);
        v28 = *(volatile uint32_t *)(dword_11BA70 + 4);
        *((volatile uint32_t *)off_11BA60 + 248) = *(volatile uint32_t *)dword_11BA70;
        v29 = *(volatile uint32_t *)(v25 + 100);
        *((volatile uint16_t *)v24 + 498) = v28;
        *(volatile uint32_t *)(v24 + 998) = v29;
        v30 = *v23;
        v31 = v23[1];
        v0[52] = v1 | 2;
        v32 = *((volatile uint32_t *)v24 + 245);
        *((volatile uint32_t *)v24 + 244) = v26 | 0x100;
        v33 = (void *)(uintptr_t)(off_11BA68);
        *((volatile uint32_t *)v24 + 251) = v30;
        *((volatile uint16_t *)v24 + 504) = v31;
        v34 = (void *)(uintptr_t)(off_11BA64);
        *(volatile uint32_t *)(v24 + 1014) = v0[43];
        *((volatile uint16_t *)v24 + 501) = v27;
        *((volatile uint32_t *)v24 + 245) = v32 & 0xFF00;
        *v33 = (int)(uintptr_t)(v24 + 920);
        *((volatile uint32_t *)v24 + 275) = 0;
        *((volatile uint32_t *)v24 + 276) = 0;
        *((volatile uint32_t *)v24 + 231) = 0;
        *((volatile uint8_t *)v0 + 200) = 0;
        *v34 = 0x2000;
      }
    }
    else
    {
      v16 = (void *)(uintptr_t)(off_11BA60);
      v17 = (void *)(uintptr_t)(off_11BA68);
      v18 = *((volatile uint32_t *)off_11BA60 + 269);
      v19 = *((volatile uint32_t *)off_11BA60 + 270);
      *((volatile uint8_t *)off_11BA58 + 200) = v2;
      v0[52] = v1 | 2;
      v20 = (void *)(uintptr_t)(off_11BA64);
      v16[275] = v2;
      v16[276] = v2;
      v16[256] = v2;
      v16[269] = v18 | 0x100;
      v16[270] = v19 & 0xFF00;
      *v17 = (int)(uintptr_t)(v16 + 255);
      *v20 = 0x2000;
    }
  }
}



// get_conn_by_channel @ 0x11ba74
/* luna: Pops the current channel's list, registers the supplied object for that channel, and updates the channel record when the object's 0x380000 flag bits a */
int get_conn_by_channel(int a1, int a2) {
  int v2; // r6
  int v3; // r5
  int result; // r0
  int v6; // r5

  v2 = dword_11BABC;
  v3 = *((volatile uint8_t *)off_11BAB8 + 190);
  list_pop(dword_11BABC + 84 * v3 + 12);
  result = register_handler((void *)(uintptr_t)(a1), a2, v3);
  if ( (*(volatile uint32_t *)(a1 + 36) & 0x380000) == 0x380000 )
  {
    v6 = v2 + 84 * v3;
    *(volatile uint32_t *)(v6 + 36) = *(volatile uint32_t *)(a1 + 68);
    *(volatile uint8_t *)(v6 + 26) = 2;
  }
  return result;
}



// bt_start_operation @ 0x11bac0
/* luna: Aggregates eight channel-indexed counters by mapped rate class and computes a compact, scaled summary for an eligible connection. */
volatile uint8_t * bt_start_operation(volatile uint8_t *result) {
  unsigned int v1; // r4
  int v2; // r5
  volatile uint8_t *v3; // r1
  int v4; // r6
  int v5; // r11
  char v6; // lr
  unsigned int v7; // r2
  unsigned int v8; // r10
  unsigned int v9; // r0
  unsigned int v10; // r3
  unsigned int v11; // t1
  int v12; // r7
  int v13; // r3
  volatile int *v14; // r12
  unsigned int v15; // r5
  int v16; // r4
  unsigned int v17; // r2
  int v18; // r3
  int v19; // r10
  int v20; // r1
  unsigned int v21; // r10
  unsigned int v22; // r0
  struct __attribute__((packed)) { unsigned int v23; // [sp+0h] [bp-1Ch]
  int v24; // [sp+4h] [bp-18h]
  int v25[5]; // [sp+8h] [bp-14h] BYREF
  } _frame;
  v1 = result[106];
  if ( !result[106] )
  {
    if ( result[108] )
    {
      _frame.v24 = result[116];
      v2 = dword_11BC38 + 696 * _frame.v24;
      if ( *(volatile uint8_t *)(v2 + 37) )
      {
        if ( (*(volatile uint32_t *)(v2 + 4) & 0x20) != 0 )
        {
          memset(_frame.v25, v1, 0x10u);
          v3 = (volatile uint8_t *)dword_11BC40;
          _frame.v23 = v1;
          v4 = 36 * *(volatile uint8_t *)(v2 + 35) + 8244 + dword_11BC3C;
          v5 = dword_11BC40 + 8;
          v6 = v1;
          v7 = v1;
          v8 = v1;
          v9 = v1;
          do
          {
            v11 = *(volatile uint32_t *)(v4 + 4);
            v4 += 4;
            v10 = v11;
            v12 = v11;
            if ( v11 >= 0x7F0000 )
              v12 = 8323072;
            if ( v10 )
            {
              v13 = *(volatile uint8_t *)(dword_11BC44 + *v3);
              v14 = &_frame.v25[v13 + 4];
              v15 = *(v14 - 4) + v12;
              if ( v15 > v8 )
              {
                v8 = *(v14 - 4) + v12;
                _frame.v23 = *(volatile uint8_t *)(dword_11BC44 + *v3);
              }
              v1 = (uint8_t)(v1 + 1);
              v9 += v12;
              *(v14 - 4) = v15;
              if ( ((v7 >> v13) & 1) == 0 )
              {
                v7 = (uint8_t)(v7 | (1 << v13));
                ++v6;
              }
            }
            ++v3;
          }
          while ( (volatile uint8_t *)v5 != v3 );
          if ( v1 == 8 )
          {
            v16 = 3072;
            v17 = 0;
          }
          else
          {
            v16 = (uint8_t)(v1 - v6) << 10;
            v17 = v7 << 6;
          }
          if ( v9 > 0xFD0 )
          {
            if ( v9 <= 0xFD00 )
            {
              v18 = (uint8_t)((uint16_t)(v9 + 255) >> 8);
              v19 = (uint8_t)((uint16_t)(v8 + 255) >> 8);
              v20 = 0x4000;
            }
            else if ( v9 > 0x7E800 )
            {
              if ( v8 > 0x7F0000 )
                v21 = 8355839;
              else
                v21 = v8 + 0x7FFF;
              if ( v9 > 0x7F0000 )
                v22 = 8355839;
              else
                v22 = v9 + 0x7FFF;
              v18 = (uint8_t)(v22 >> 15);
              v19 = (uint8_t)(v21 >> 15);
              v20 = 49152;
            }
            else
            {
              v18 = (uint8_t)((v9 + 2047) >> 11);
              v19 = (uint8_t)((v8 + 2047) >> 11);
              v20 = 0x8000;
            }
          }
          else
          {
            v18 = (uint8_t)((v9 + 15) >> 4);
            v19 = (uint8_t)((v8 + 15) >> 4);
            v20 = 0;
          }
          *(volatile uint32_t *)(dword_11BC38 + 696 * _frame.v24 + 580) = (v18 << 24) | (_frame.v23 << 12) | v17 | v16 | v20 | (v19 << 16) | 0xF;
          return (volatile uint8_t *)_frame.v24;
        }
      }
    }
  }
  return result;
}



// wifi_core_init @ 0x11bc48
/* luna: Initializes shared radio state and its repeated records, then selects RF control bits according to status bit 26. */
int wifi_core_init() {
  volatile int *v0; // r4
  int v1; // r3
  int v2; // lr
  int v3; // r8
  volatile int *v4; // r3
  int v5; // r3
  volatile uint32_t *v6; // r5
  int v7; // r6
  int v8; // r3
  int v9; // r0
  int v10; // r3
  unsigned int v11; // r3

  v0 = (volatile int *)off_11BD80;
  memset((volatile int *)off_11BD84, 0, 0xD4u);
  memset(v0, 0, 0x4C8u);
  v1 = dword_11BD88;
  v0[272] = dword_11BD8C;
  *((volatile uint16_t *)v0 + 34) = 456;
  *((volatile uint16_t *)v0 + 494) = -32312;
  v2 = dword_11BD9C;
  *((volatile uint16_t *)v0 + 506) = -208;
  v0[234] = (int)(v0 + 247);
  v0[235] = (int)v0 + 1021;
  v0[236] = 34;
  v0[230] = v1;
  v0[255] = v1;
  *v0 = v1;
  v3 = v1;
  v0[14] = 0x200000;
  v0[239] = (int)(v0 + 272);
  v0[264] = (int)(v0 + 272);
  v0[9] = (int)(v0 + 272);
  v0[233] = 0;
  v0[243] = 0;
  v0[268] = 0;
  v4 = v0 + 45;
  do
  {
    *(v4 - 22) = v3;
    *(v4 - 16) = 30;
    *(v4 - 9) = 0;
    *(v4 - 5) = v2;
    *(v4 - 19) = (int)(v4 - 5);
    *(v4 - 2) = (int)v4 + 1;
    *(v4 - 18) = (int)(v0 + 17);
    *(v4 - 17) = (int)v0 + 91;
    *(v4 - 3) = (int)v4;
    v4 += 23;
  }
  while ( v0 + 252 != v4 );
  v5 = dword_11BD90;
  v6 = (void *)(uintptr_t)(off_11BD84);
  v0[298] = 0;
  v7 = v5 + 15;
  v0[295] = 0;
  v0[296] = 0;
  v0[297] = 0;
  v0[293] = 0;
  v0[288] = 0;
  v0[289] = v5;
  v8 = dword_11BD94;
  v0[291] = 20;
  v0[299] = v8;
  v0[294] = (int)(v0 + 272);
  v0[285] = v3;
  v0[290] = v7;
  v6[43] = 467;
  *((volatile uint16_t *)v0 + 604) = 164;
  v9 = rf_status_bit26();
  v10 = *(volatile uint32_t *)off_11BD98 & 0xFFFFFFF;
  if ( v9 )
    v11 = v10 | 0xB0000000;
  else
    v11 = v10 | 0x90000000;
  *(volatile uint32_t *)off_11BD98 = v11;
  v6[7] = 0;
  v6[14] = 1;
  v6[21] = 2;
  v6[28] = 3;
  return 0;
}



