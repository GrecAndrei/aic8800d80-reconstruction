// bus_cmd52_write @ 0x129404
/* luna: Builds and submits a key-installation PDU for the selected key entry, copying its metadata and key material when the entry is populated. */
int bus_cmd52_write(int a1, int a2) {
  int v4; // r0
  int v5; // r3
  int v6; // r2
  uint64_t v7; // kr00_8

  v4 = tx_send_pdu(85, 13, 0, 16);
  *(volatile uint8_t *)v4 = *(volatile uint8_t *)(a1 + 113);
  v5 = a1 + 48 * a2;
  *(volatile uint8_t *)(v4 + 1) = a2;
  if ( *(volatile uint8_t *)(v5 + 16) )
  {
    v6 = *(volatile uint8_t *)(v5 + 20);
    *(volatile uint8_t *)(v4 + 3) = v6;
    if ( v6 )
    {
      *(volatile uint8_t *)(v4 + 2) = *(volatile uint8_t *)(v5 + 32);
      v7 = *(volatile uint64_t *)(v5 + 24);
      *(volatile uint32_t *)(v4 + 12) = *(volatile uint32_t *)(v5 + 36);
      *(volatile uint64_t *)(v4 + 4) = v7;
    }
  }
  else
  {
    *(volatile uint8_t *)(v4 + 3) = 0;
  }
  return (int)(uintptr_t)(rx_process_packet_1(v4));
}



// rsn_derive_key @ 0x129458
/* luna: Scans three RSN timer records and computes the next eligible key-management deadline, accounting for recurring intervals. */
int rsn_derive_key(int result) {
  int v1; // r12
  int v2; // r6
  int v3; // r5
  int v4; // r3
  int v5; // r7
  int v6; // r1
  int v7; // r2
  int v8; // lr
  int v9; // r3
  int v10; // r9
  int v11; // r8
  unsigned int v12; // r1
  int v13; // r4
  int v14; // r2
  int v15; // r4
  int v16; // r6
  int v17; // r2
  int v18; // cf
  int v19; // r3
  int v20; // r1
  unsigned int v21; // r1
  int v22; // r12
  int v23; // r10
  int v24; // r8
  int v25; // r10
  int v26; // [sp+0h] [bp-Ch]
  int v27; // [sp+4h] [bp-8h]

  v1 = 0;
  v2 = result;
  v3 = result + 96;
  v4 = result;
  v5 = 0;
  v6 = 1;
  do
  {
    if ( *(volatile uint8_t *)(v4 + 16) == 2
      && *(volatile uint8_t *)(v4 + 19) <= 1u
      && (!*(volatile uint8_t *)(result + 135) || !*(volatile uint8_t *)(v4 + 33) || *(volatile uint8_t *)(v4 + 32) != 1) )
    {
      v7 = *(volatile uint32_t *)(v4 + 12);
      if ( !v6 )
      {
        v18 = v1 - v7 < 0;
        v7 &= (v1 - v7) >> 31;
        if ( !v18 )
          v7 = v1;
      }
      ++v5;
      v1 = v7;
      v6 = 0;
    }
    v4 += 48;
  }
  while ( v3 != v4 );
  v8 = v6;
  v9 = result;
  v10 = 0;
  v26 = 1;
  v11 = result;
  do
  {
    if ( *(volatile uint8_t *)(v9 + 16) == 2 )
    {
      v12 = *(volatile uint8_t *)(v9 + 19);
      if ( v12 > 1 && (!*(volatile uint8_t *)(v2 + 135) || !*(volatile uint8_t *)(v9 + 33) || *(volatile uint8_t *)(v9 + 32) != 1) )
      {
        v13 = *(volatile uint32_t *)(v9 + 28);
        v14 = *(volatile uint32_t *)(v9 + 12);
        result = v13 + v14 - *(volatile uint32_t *)(v9 + 24);
        if ( !v8 )
        {
          if ( result - v1 >= 0 )
          {
            v18 = v1 - v14 < 0;
            v14 &= (v1 - v14) >> 31;
            if ( !v18 )
              v14 = v1;
          }
          else
          {
            v21 = v12 - 1;
            while ( 1 )
            {
              result = v13 + v13 - *(volatile uint32_t *)(v9 + 24) + v14;
              v14 += v13;
              if ( v13 - *(volatile uint32_t *)(v9 + 24) - v1 + v14 >= 0 )
                break;
              if ( !--v21 )
                goto LABEL_19;
            }
            v18 = v1 - v14 < 0;
            v22 = v1 & ~((v1 - v14) >> 31);
            if ( v18 )
              v22 = v14;
            if ( v21 == 1 )
            {
              result = v10;
              v14 = v22;
              goto LABEL_18;
            }
            v14 = v22;
          }
          if ( !v26 )
          {
            v18 = result - v10 < 0;
            result &= (result - v10) >> 31;
            if ( !v18 )
              result = v10;
            goto LABEL_18;
          }
        }
        v26 = 0;
LABEL_18:
        ++v5;
        v10 = result;
        v1 = v14;
        v8 = 0;
      }
    }
LABEL_19:
    v9 += 48;
  }
  while ( v3 != v9 );
  v27 = v2;
  v15 = v11;
  v16 = v26;
  do
  {
    while ( 1 )
    {
      if ( *(volatile uint8_t *)(v15 + 16) != 1 )
        goto LABEL_28;
      v19 = *(volatile uint32_t *)(v15 + 12);
      v20 = *(volatile uint32_t *)(v15 + 24) + v19;
      if ( v8 )
        break;
      if ( !v5 )
      {
        if ( v20 - v10 < 0 )
        {
          v10 = *(volatile uint32_t *)(v15 + 12);
          v1 = *(volatile uint32_t *)(v15 + 24) + v19;
        }
        else if ( v1 - v19 >= 0 )
        {
          result = v19 - v10;
          v17 = v1 - v20;
          v18 = v19 - v10 < 0;
          v10 &= ~((v19 - v10) >> 31);
          if ( v18 )
            v10 = *(volatile uint32_t *)(v15 + 12);
          v1 &= ~(v17 >> 31);
          if ( v17 < 0 )
            v1 = *(volatile uint32_t *)(v15 + 24) + v19;
        }
        goto LABEL_28;
      }
      if ( v20 - v1 >= 0 )
      {
        result = *(volatile uint8_t *)(v15 + 19);
        v23 = *(volatile uint32_t *)(v15 + 12);
        v24 = *(volatile uint32_t *)(v15 + 24) + v19;
      }
      else
      {
        result = *(volatile uint8_t *)(v15 + 19) - 1;
        if ( !*(volatile uint8_t *)(v15 + 19) )
          goto LABEL_28;
        v23 = *(volatile uint32_t *)(v15 + 12);
        while ( 1 )
        {
          v23 += *(volatile uint32_t *)(v15 + 28);
          v24 = *(volatile uint32_t *)(v15 + 24) + v23;
          if ( v24 - v1 >= 0 )
            break;
          if ( !result )
            goto LABEL_28;
          --result;
        }
      }
      if ( v16 )
      {
        if ( v1 - v23 < 0 )
        {
          v10 = v23;
          v16 = 0;
        }
        else
        {
          v1 = v24;
          if ( result )
          {
            v10 = v23 + *(volatile uint32_t *)(v15 + 28);
            v16 = 0;
          }
        }
        goto LABEL_28;
      }
      if ( v10 - v23 >= 0 )
      {
        if ( v1 - v23 < 0 )
        {
          v10 = v23;
          v8 = 0;
          goto LABEL_28;
        }
        if ( v24 - v10 < 0 )
        {
          if ( result <= 1 )
          {
            v1 = v24;
            v8 = 0;
          }
          else
          {
            v25 = v23 + *(volatile uint32_t *)(v15 + 28);
            v1 = v24;
            v18 = v25 - v10 < 0;
            v10 &= ~((v25 - v10) >> 31);
            if ( v18 )
              v10 = v25;
            v8 = 0;
          }
          goto LABEL_28;
        }
        if ( **(volatile int16_t **)off_1296B8 < 0 )
          result = mmio_write_field(dword_1296C0, dword_1296BC, 347);
        v1 = v24;
        v10 = v23 + *(volatile uint32_t *)(v15 + 28);
      }
      v8 = 0;
LABEL_28:
      v15 += 48;
      if ( v3 == v15 )
        goto LABEL_32;
    }
    v15 += 48;
    v16 = 0;
    v10 = v19;
    v1 = v20;
    v8 = 0;
  }
  while ( v3 != v15 );
LABEL_32:
  *(volatile uint32_t *)(v27 + 128) = v1;
  if ( v16 )
    v10 = v1 + 10;
  *(volatile uint32_t *)(v27 + 124) = v10;
  return result;
}



// rsn_parse_ie @ 0x1296c4
/* luna: Reconciles the requested power-save state with the current state and updates per-interface beacon timing accordingly. */
volatile uint8_t * rsn_parse_ie(volatile uint8_t *result) {
  volatile uint8_t *v1; // r4
  int v2; // r9
  int v3; // r3
  int v4; // r10
  int v5; // r8
  volatile uint8_t *v6; // r0
  unsigned int v7; // r3
  int v8; // r1
  int v9; // r5
  int v10; // r6
  volatile uint8_t *v11; // r0
  int v12; // r3
  int v13; // r3
  volatile uint16_t *v14; // r0
  int v15; // r7
  int v16; // r1
  int v17; // r5
  int v18; // r6
  int v19; // r4
  volatile uint32_t *v20; // r2
  int v21; // r11
  int v22; // r5
  int v23; // r3
  int v24; // r0
  volatile uint32_t *v25; // r3
  int v26; // r3
  int v27; // r0
  int v28; // r2
  int v29; // r8
  int v30; // r1
  volatile int *v31; // r5
  int v32; // r3
  int v33; // r2
  volatile uint8_t *v34; // [sp+4h] [bp-8h]

  v1 = result;
  if ( result[16] != 2 )
  {
    if ( result[64] != 2 )
      goto LABEL_3;
    if ( !result[135] )
    {
      v7 = 255;
      goto LABEL_36;
    }
    goto LABEL_17;
  }
  if ( !result[135] )
  {
    v7 = result[20];
    if ( result[64] != 2 )
      goto LABEL_26;
    goto LABEL_36;
  }
  if ( result[33] && result[32] == 1 )
  {
    if ( result[64] != 2 )
      goto LABEL_3;
LABEL_17:
    v7 = 255;
    v8 = 0;
    goto LABEL_18;
  }
  v7 = result[20];
  if ( result[64] != 2 )
    goto LABEL_26;
  v8 = 1;
LABEL_18:
  if ( !result[81] || result[80] != 1 )
  {
LABEL_36:
    if ( v7 >= result[68] )
      v7 = result[68];
LABEL_26:
    if ( v7 != 1 )
    {
      v2 = result[134];
      if ( result[134] )
      {
        if ( result[133] == 1 )
          return result;
        v5 = result[113];
        v4 = dword_129A1C;
        v2 = 1;
        goto LABEL_42;
      }
      v9 = result[114];
      v10 = v9 == 1;
      if ( result[133] == v10 )
      {
        if ( !result[112] && v9 == 1 )
          goto LABEL_7;
        return result;
      }
      v5 = result[113];
      v4 = dword_129A1C;
      v11 = (volatile uint8_t *)tx_send_pdu(77, 13, result[134], 2);
      *v11 = v1[113];
      v11[1] = v9 != 1;
      rx_process_packet_1((int)(uintptr_t)(v11));
      v1[133] = v10;
      result = (volatile uint8_t *)((int (*)())nullsub_5)(*(volatile uint32_t *)(v4 + 1320 * v5 + 72), v9 != 1);
      if ( v9 == 1 )
      {
LABEL_43:
        if ( v1[112] )
        {
          result = (volatile uint8_t *)irq_disable_global_2(512);
          v28 = v1[112];
        }
        else
        {
          v15 = v4 + 1320 * v5;
          v16 = *(volatile uint8_t *)(v15 + 116);
          if ( v16 == 255 )
          {
            if ( *(volatile uint8_t *)(v15 + 106) == 2 )
            {
              *(volatile uint32_t *)(v15 + 4) |= 0x20u;
              if ( !v2 )
                return (volatile uint8_t *)get_hw_tsf(v4 + 1320 * v1[113]);
              return result;
            }
            goto LABEL_59;
          }
          v17 = dword_129A10;
          v34 = v1;
          v18 = dword_129A10 + 696 * v16;
          v19 = v4 + 8 * (165 * v5 + 159);
          v20 = (void *)(uintptr_t)(off_129A14);
          v21 = 696 * v16 + dword_129A10 + 664;
          *(volatile uint8_t *)(v18 + 36) = 0;
          v22 = v17 + 8 * (87 * (int16_t)v16 + 78);
          do
          {
            if ( *(volatile uint32_t *)(v18 + 584) )
            {
              if ( (__get_CPSR() & 1) == 0 )
              {
                __disable_irq();
                *(volatile uint32_t *)off_129A18 = 1;
              }
              ++*v20;
              get_ptr_value((void *)(uintptr_t)(v22 - 40), (void *)(uintptr_t)(v19 - 40));
              v23 = *(volatile uint32_t *)(v18 + 588);
              *(volatile uint32_t *)(v15 + 1232) = *(volatile uint32_t *)(v18 + 584);
              *(volatile uint32_t *)(v15 + 1236) = v23;
              clear_stats_buf((void *)(uintptr_t)(v22 - 40));
              v20 = (void *)(uintptr_t)(off_129A14);
              v24 = *(volatile uint32_t *)off_129A14 - 1;
              if ( *(volatile uint32_t *)off_129A14 )
              {
                v25 = (void *)(uintptr_t)(off_129A18);
                *(volatile uint32_t *)off_129A14 = v24;
                if ( !v24 )
                {
                  if ( *v25 )
                    __enable_irq();
                }
              }
            }
            v26 = *(volatile uint32_t *)(v18 + 624);
            v27 = v19;
            v18 += 8;
            v19 += 8;
            v15 += 8;
            if ( v26 )
            {
              get_ptr_value((void *)(uintptr_t)(v27), (void *)(uintptr_t)(v22));
              clear_stats_buf((void *)(uintptr_t)(v22));
              v20 = (void *)(uintptr_t)(off_129A14);
            }
            v22 += 8;
          }
          while ( v22 != v21 );
          v1 = v34;
          result = (volatile uint8_t *)irq_disable_global_2(512);
          v28 = v34[112];
        }
        v29 = v4 + 1320 * v5;
        if ( *(volatile uint8_t *)(v29 + 106) == 2 )
        {
          *(volatile uint32_t *)(v29 + 4) |= 0x20u;
          if ( v28 )
            return result;
        }
        else if ( v28 )
        {
          return result;
        }
LABEL_59:
        if ( !v2 )
          return (volatile uint8_t *)get_hw_tsf(v4 + 1320 * v1[113]);
        return result;
      }
LABEL_30:
      v12 = v4 + 1320 * v5;
      if ( *(volatile uint8_t *)(v12 + 106) == 2 )
      {
        v30 = *((volatile uint32_t *)off_129B10 + 1);
        *(volatile uint32_t *)(v12 + 4) &= ~0x20u;
        if ( v30 > 0 )
        {
          if ( (__get_CPSR() & 1) == 0 )
          {
            __disable_irq();
            *(volatile uint32_t *)off_129B14 = 1;
          }
          v31 = (volatile int *)off_129B18;
          ++*(volatile uint32_t *)off_129B18;
          mmio_modify_bit(4);
          result = (volatile uint8_t *)phy_get_cfg_ptr(4);
          if ( *v31 )
          {
            v32 = *v31 - 1;
            v33 = *(volatile uint32_t *)off_129B14;
            *v31 = v32;
            if ( !v32 )
            {
              if ( v33 )
                __enable_irq();
            }
          }
        }
      }
      if ( !v1[112] )
      {
        v13 = *(volatile uint8_t *)(v4 + 1320 * v5 + 116);
        if ( v13 != 255 )
          *(volatile uint8_t *)(dword_129A10 + 696 * v13 + 36) = 1;
      }
      return result;
    }
    goto LABEL_13;
  }
  if ( v8 )
    goto LABEL_26;
LABEL_3:
  v2 = result[115];
  if ( !result[115] )
  {
    if ( result[133] == 1 )
    {
LABEL_5:
      v3 = result[112];
      goto LABEL_6;
    }
    goto LABEL_41;
  }
  if ( result[114] == 1 )
  {
    if ( result[133] == 1 )
      goto LABEL_5;
    goto LABEL_62;
  }
  v3 = result[112];
  if ( v3 == 1 )
  {
    v5 = result[113];
    v4 = dword_129B1C;
    if ( *(volatile uint8_t *)(dword_129B1C + 1320 * v5 + 234) != *(volatile uint8_t *)(dword_129B1C + 1320 * v5 + 1226) )
    {
      if ( result[133] == 1 )
        return result;
      v2 = 0;
      goto LABEL_42;
    }
    if ( !result[133] )
      return result;
    goto LABEL_15;
  }
  v2 = *(volatile uint8_t *)off_129A0C;
  if ( *(volatile uint8_t *)off_129A0C )
  {
    if ( (*((volatile uint32_t *)off_129A0C + 1) & 8) == 0 )
    {
LABEL_13:
      if ( !result[133] )
        return result;
      v5 = result[113];
      v4 = dword_129A1C;
LABEL_15:
      v6 = (volatile uint8_t *)tx_send_pdu(77, 13, 0, 2);
      *v6 = v1[113];
      v6[1] = 1;
      rx_process_packet_1((int)(uintptr_t)(v6));
      v1[133] = 0;
      result = (volatile uint8_t *)((int (*)())nullsub_5)(*(volatile uint32_t *)(v4 + 1320 * v5 + 72), 1);
      goto LABEL_30;
    }
    if ( result[133] == 1 )
    {
      if ( !result[112] )
        goto LABEL_7;
      return result;
    }
LABEL_62:
    v5 = result[113];
    v4 = dword_129A1C;
    v2 = 0;
    goto LABEL_42;
  }
  if ( result[133] != 1 )
  {
LABEL_41:
    v5 = result[113];
    v4 = dword_129A1C;
LABEL_42:
    v14 = (volatile uint16_t *)tx_send_pdu(77, 13, 0, 2);
    *v14 = v1[113];
    rx_process_packet_1((int)(uintptr_t)(v14));
    v1[133] = 1;
    result = (volatile uint8_t *)((int (*)())nullsub_5)(*(volatile uint32_t *)(v4 + 1320 * v5 + 72), 0);
    goto LABEL_43;
  }
LABEL_6:
  if ( !v3 )
  {
LABEL_7:
    v4 = dword_129A1C;
    return (volatile uint8_t *)get_hw_tsf(v4 + 1320 * v1[113]);
  }
  return result;
}



// key_install_check @ 0x129b20
/* luna: Processes the context’s pending RSN information-element state, copies deferred data when present, and invokes the IE parser. */
volatile uint8_t * key_install_check(volatile uint8_t *result) {
  int v1; // r3
  volatile uint8_t *v2; // r4
  int v3; // r1

  v1 = result[114];
  v2 = result;
  if ( v1 == 1 )
  {
    result[114] = 0;
    return rsn_parse_ie(result);
  }
  else if ( v1 == 2 )
  {
    v3 = *((volatile uint32_t *)result + 29);
    result[114] = 1;
    mem_copy_util((void *)(uintptr_t)((int)(result + 96)), v3);
    return rsn_parse_ie(v2);
  }
  return result;
}



