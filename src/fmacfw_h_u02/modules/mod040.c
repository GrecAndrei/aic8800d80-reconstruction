// sec_table_get @ 0x129b58
/* luna: Computes the next strided security-table address from a supplied range, updates the cursor and remaining-entry state, and returns zero when no entry r */
unsigned int sec_table_get(int a1, int a2, unsigned int a3, unsigned int a4) {
  unsigned int v4; // r6
  int v6; // r7
  unsigned int v7; // r5
  unsigned int v8; // r3
  unsigned int v9; // r5
  volatile int16_t **v10; // r3
  volatile uint32_t *v11; // r2
  unsigned int v12; // r3
  unsigned int result; // r0
  volatile uint32_t *v14; // r1

  v4 = a3;
  v6 = dword_129C10 + 1320 * a2;
  if ( a4 < a3 )
  {
    v9 = 0;
  }
  else
  {
    if ( *(volatile uint8_t *)(a1 + 19) == 1 )
      return 0;
    v7 = *(volatile uint32_t *)(a1 + 28);
    v8 = (a4 - a3) / v7;
    v4 = a3 + v7 + v8 * v7;
    v9 = v8 + 1;
  }
  v10 = (volatile int16_t **)off_129C14;
  *(volatile uint32_t *)(a1 + 44) = v4;
  if ( **v10 < 0 && *(volatile uint8_t *)(v6 + 106) )
    irq_disable_mmio_write(dword_129C24, dword_129C20, 98);
  v11 = (void *)(uintptr_t)(off_129C1C);
  v12 = *(volatile uint8_t *)(a1 + 19);
  result = *((volatile uint32_t *)off_129C1C + 4) - *(volatile uint32_t *)off_129C18 - *(volatile uint32_t *)(v6 + 132) + v4;
  if ( v12 == 255 )
  {
    if ( (int)(result - *((volatile uint32_t *)off_129C1C + 4)) < 0 )
      goto LABEL_10;
    return result;
  }
  if ( v12 > v9 )
    v12 = (v12 & ~0xFFu) | ((uint8_t)(v12 - v9) & 0xFFu);
  else
    v12 = (v12 & ~0xFFu) | ((uint8_t)(0) & 0xFFu);
  v12 = (uint8_t)v12;
  *(volatile uint8_t *)(a1 + 19) = v12;
  if ( (int)(result - v11[4]) < 0 )
  {
LABEL_10:
    v14 = (void *)(uintptr_t)(off_129C1C);
    while ( v12 )
    {
      while ( 1 )
      {
        result += *(volatile uint32_t *)(a1 + 28);
        if ( v12 != 255 )
          break;
        if ( (int)(result - v14[4]) >= 0 )
          return result;
      }
      v12 = (uint8_t)(v12 - 1);
      *(volatile uint8_t *)(a1 + 19) = v12;
      if ( (int)(result - v14[4]) >= 0 )
        goto LABEL_14;
    }
    return 0;
  }
LABEL_14:
  if ( !v12 )
    return 0;
  return result;
}



// sec_table_lookup @ 0x129c28
/* luna: Looks up a security-table entry, copies a nonzero result into the caller buffer, sets the byte at offset 16 to 1, and returns the result's low byte (o */
int sec_table_lookup(int a1, int a2, unsigned int a3, unsigned int a4) {
  unsigned int v5; // r0
  uint8_t v6; // r4

  v5 = sec_table_get(a1, a2, a3, a4);
  v6 = v5;
  if ( !v5 )
    return 0;
  mem_copy_util((void *)(uintptr_t)(a1), v5);
  *(volatile uint8_t *)(a1 + 16) = 1;
  return v6;
}



// sec_table_entry_count @ 0x129c48
/* luna: Updates the indexed security-table record from an optional encoded security list, invalidating and reparsing cached RSN state when the list discrimina */
int sec_table_entry_count(int result, int a2, unsigned int a3) {
  int v3; // r8
  int v4; // r9
  int v5; // r5
  int v6; // r4
  int v8; // r3
  int v10; // r2
  volatile uint8_t *v11; // r7
  int v12; // r3
  int v13; // r7
  int v14; // r3
  int v15; // r3
  uint64_t v16; // kr00_8
  unsigned int v17; // r7
  volatile uint8_t *v18; // r9
  uint8_t v19; // r11
  unsigned int v20; // r3
  int v21; // r5
  int v22; // r2
  char v23; // r3
  volatile uint8_t *v24; // r7
  int v25; // r3
  int v26; // r6
  int v27; // r3
  int v28; // [sp+0h] [bp-Ch]
  int v29; // [sp+4h] [bp-8h]

  v3 = dword_129E00;
  v4 = 140 * result;
  v5 = result;
  v6 = dword_129E00 + 140 * result;
  if ( !a2 )
  {
    v24 = (volatile uint8_t *)(dword_129E00 + 140 * result);
    v25 = (uint8_t)v24[121];
    v24[132] = 0;
    if ( v25 )
    {
      if ( v24[16] )
      {
        mem_set_util(v6);
        v24[16] = 0;
      }
      v26 = v3 + 140 * v5;
      v27 = *(volatile uint8_t *)(v26 + 64);
      *(volatile uint8_t *)(v26 + 121) = 0;
      if ( v27 )
      {
        mem_set_util(v4 + 48 + v3);
        *(volatile uint8_t *)(v26 + 64) = 0;
      }
      *(volatile uint8_t *)(v3 + 140 * v5 + 121) = 0;
      rsn_parse_ie((volatile uint8_t *)v6);
    }
    goto LABEL_19;
  }
  v8 = dword_129E00 + 140 * result;
  v10 = *(volatile uint8_t *)(a2 + 3);
  if ( !*(volatile uint8_t *)(v8 + 132) || *(volatile uint8_t *)(v8 + 120) != v10 )
  {
    v11 = (volatile uint8_t *)(dword_129E00 + 140 * result);
    v12 = (uint8_t)v11[121];
    v11[120] = v10;
    v11[132] = 1;
    if ( v12 )
    {
      if ( v11[16] )
      {
        mem_set_util(v6);
        v11[16] = 0;
      }
      v13 = v3 + 140 * v5;
      v14 = *(volatile uint8_t *)(v13 + 64);
      *(volatile uint8_t *)(v13 + 121) = 0;
      if ( v14 )
      {
        mem_set_util(v4 + 48 + v3);
        *(volatile uint8_t *)(v13 + 64) = 0;
      }
      *(volatile uint8_t *)(v3 + 140 * v5 + 121) = 0;
      rsn_parse_ie((volatile uint8_t *)v6);
    }
    v15 = *(volatile uint16_t *)(a2 + 1) - 2;
    v16 = (int32_t)dword_129DFC * (int64_t)(int32_t)(v15);
    v17 = (uint8_t)((SHIDWORD(v16) >> 2) - (v15 >> 31));
    if ( (uint8_t)(SHIDWORD(v16) >> 2) != (uint8_t)(v15 >> 31) )
    {
      v28 = v3 + 140 * v5;
      v18 = (volatile uint8_t *)(a2 + 5);
      v19 = 0;
      v29 = v5;
      do
      {
        v20 = *v18;
        *(volatile uint8_t *)(v6 + 20) = v20;
        ++v19;
        if ( v20 )
        {
          v21 = *(volatile uint32_t *)(v18 + 5);
          if ( v20 <= 1 || v21 )
          {
            *(volatile uint32_t *)(v6 + 24) = *(volatile uint32_t *)(v18 + 1);
            v22 = v21 - 4000 - get_timeout_1000();
            v23 = *(volatile uint8_t *)(v6 + 20);
            *(volatile uint32_t *)(v6 + 28) = v22;
            *(volatile uint8_t *)(v6 + 19) = v23;
            if ( sec_table_lookup(v6, *(volatile uint8_t *)(v28 + 113), *(volatile uint32_t *)(v18 + 9), a3) )
              ++*(volatile uint8_t *)(v28 + 121);
          }
        }
        v18 += 13;
        v6 += 48;
      }
      while ( v19 < v17 );
      v5 = v29;
    }
    if ( *(volatile char *)(a2 + 4) < 0 )
    {
      *(volatile uint8_t *)(v3 + 140 * v5 + 115) = *(volatile uint8_t *)(a2 + 4) & 0x7F;
      return 140;
    }
LABEL_19:
    *(volatile uint8_t *)(v3 + 140 * v5 + 115) = 0;
    return 140;
  }
  return result;
}



// rf_patch_init @ 0x129e04
/* luna: Initializes security-table state by clearing one byte and setting two fields to the invalid sentinel value 0xFF. */
volatile int *rf_patch_init() {
  volatile int *result; // r0
  volatile uint8_t *v1; // r3

  result = memset((volatile int *)dword_129E20, 0, 1u);
  v1 = (void *)(uintptr_t)(off_129E24);
  *((volatile uint8_t *)off_129E24 + 113) = -1;
  v1[253] = -1;
  return result;
}



// bt_is_ready @ 0x129e28
/* luna: Allocates and initializes the first free one of two 140-byte Bluetooth connection contexts, returning its slot index or 0xFF if both are occupied. */
int bt_is_ready(int a1, int a2) {
  volatile char *context_table_base; // r4
  int v5; // r5
  volatile char *slot_bytes; // r3
  int v8; // r1
  void *v9; // r0
  int slot_index; // r8
  int v11; // r10
  volatile int *slot_base; // r9
  int v13; // r2
  volatile uint8_t *v14; // r12
  int v15; // r0
  int v16; // r1
  int v17; // r4
  void *v18; // r1

  context_table_base = (volatile char *)off_129EF8;
  if ( *((volatile uint8_t *)off_129EF8 + 113) == 255 )
  {
    v5 = 0;
    slot_index = 0;
    v11 = 48;
    slot_base = (volatile int *)off_129EF8;
  }
  else
  {
    if ( *((volatile uint8_t *)off_129EF8 + 253) != 255 )
      return 255;
    v5 = 1;
    slot_index = 1;
    v11 = 188;
    slot_base = (volatile int *)((volatile char *)off_129EF8 + 140);
  }
  memset(slot_base, 0, 0x8Cu);
  slot_bytes = &context_table_base[140 * slot_index];
  slot_bytes[113] = a1;
  slot_bytes[112] = a2;
  if ( a2 == 1 )
  {
    v13 = dword_129F04;
    v14 = (void *)(uintptr_t)(off_129F08);
    slot_bytes[66] = 1;
    v15 = v13 + 1320 * a1;
    v13 = (v13 & ~0xFFu) | ((uint8_t)(*v14) & 0xFFu);
    v16 = *(volatile uint32_t *)(v15 + 4);
    slot_bytes[133] = 1;
    *((volatile uint32_t *)slot_bytes + 14) = (int)(uintptr_t)(&context_table_base[v11]);
    v17 = dword_129EFC;
    *(volatile uint32_t *)(v15 + 4) = v16 | 0x20;
    v18 = (void *)(uintptr_t)(off_129F00);
    *((volatile uint32_t *)slot_bytes + 2) = (int)(uintptr_t)(slot_base);
    slot_bytes[17] = v5;
    slot_bytes[65] = v5;
    *((volatile uint32_t *)slot_bytes + 26) = (int)(uintptr_t)(slot_base);
    *v14 = v13 + 1;
    *((volatile uint32_t *)slot_bytes + 1) = v17;
    *((volatile uint32_t *)slot_bytes + 13) = v17;
    slot_bytes[18] = 0;
    *((volatile uint32_t *)slot_bytes + 25) = (int)(uintptr_t)(v18);
  }
  else
  {
    v8 = dword_129EFC;
    v9 = (void *)(uintptr_t)(off_129F00);
    *((volatile uint32_t *)slot_bytes + 14) = (int)(uintptr_t)(&context_table_base[v11]);
    *((volatile uint32_t *)slot_bytes + 2) = (int)(uintptr_t)(slot_base);
    slot_bytes[17] = v5;
    slot_bytes[65] = v5;
    *((volatile uint32_t *)slot_bytes + 26) = (int)(uintptr_t)(slot_base);
    *((volatile uint32_t *)slot_bytes + 1) = v8;
    *((volatile uint32_t *)slot_bytes + 13) = v8;
    slot_bytes[18] = 0;
    slot_bytes[66] = 1;
    slot_bytes[133] = 1;
    *((volatile uint32_t *)slot_bytes + 25) = (int)(uintptr_t)(v9);
  }
  return v5;
}



// bt_get_conn_role @ 0x129f0c
/* luna: For a valid connection slot, decrements the global count when offset 112 is 1 and, when requested, marks offset 113 as invalid. */
int bt_get_conn_role(int result, int a2) {
  int v2; // r2
  int v3; // r3

  v2 = dword_129F48;
  v3 = dword_129F48 + 140 * result;
  if ( *(volatile uint8_t *)(v3 + 113) != 255 )
  {
    if ( *(volatile uint8_t *)(v3 + 112) != 1 )
    {
      if ( !a2 )
        return result;
      goto LABEL_4;
    }
    --*(volatile uint8_t *)off_129F4C;
    if ( a2 )
    {
LABEL_4:
      result = v2 + 140 * result;
      *(volatile uint8_t *)(result + 113) = -1;
    }
  }
  return result;
}



// bt_scan_start @ 0x129f50
/* luna: When the selected security context is enabled and parsing is not suppressed, clears its marked subrecords and transient state bytes, then calls `rsn_p */
volatile uint8_t * bt_scan_start(volatile uint8_t *result, int a2) {
  int v2; // r5
  int v3; // r7
  volatile uint8_t *v4; // r8
  int v5; // r9
  int v6; // r4
  volatile uint8_t *v7; // r5
  int v8; // r3

  if ( result[1224] && !(result[106] | a2) )
  {
    v2 = result[1225];
    v3 = dword_129FE8;
    v4 = (volatile uint8_t *)(dword_129FE8 + 140 * v2);
    v5 = 140 * v2;
    if ( v4[16] )
    {
      mem_set_util(dword_129FE8 + 140 * v2);
      v4[16] = 0;
    }
    v6 = v3 + 140 * v2;
    if ( *(volatile uint8_t *)(v6 + 64) )
    {
      mem_set_util(v5 + 48 + v3);
      *(volatile uint8_t *)(v6 + 64) = 0;
    }
    v7 = (volatile uint8_t *)(v3 + 140 * v2);
    v8 = v7[114];
    v7[115] = 0;
    v7[120] = 0;
    v7[132] = 0;
    if ( v8 )
    {
      mem_set_util(v5 + 96 + v3);
      v7[114] = 0;
    }
    return rsn_parse_ie(v4);
  }
  return result;
}



// bt_get_conn_channel @ 0x129fec
/* luna: Returns the channel byte stored in the connection entry for the given connection index. */
int bt_get_conn_channel(int a1) {
  return *(volatile uint8_t *)(dword_129FFC + 140 * a1 + 133);
}



// rf_check_trim @ 0x12a000
/* luna: Conditionally performs an IRQ/MMIO operation, reads the selected 140-byte trim record's words at offsets 128 and 124 into the output pointers, and ret */
unsigned int rf_check_trim(int a1, volatile uint32_t *a2, volatile uint32_t *a3) {
  int v6; // r3
  int v7; // r0

  if ( **(volatile int16_t **)off_12A048 < 0 && !*(volatile uint8_t *)(a1 + 1224) )
    irq_disable_mmio_write(dword_12A054, dword_12A050, 1311);
  v6 = dword_12A04C + 140 * *(volatile uint8_t *)(a1 + 1225);
  *a2 = *(volatile uint32_t *)(v6 + 128);
  v7 = *(volatile uint32_t *)(v6 + 124);
  *a3 = v7;
  return (unsigned int)(v7 - *a2) >> 31;
}



// rf_check_cal_state @ 0x12a058
/* luna: Returns the indexed calibration result, combining the two result words in state 1, returning the primary word in state 2, and otherwise returning zero */
int rf_check_cal_state(int a1, unsigned int a2) {
  volatile int16_t **v2; // r6
  int v5; // r2
  int v6; // r0
  int v7; // r3
  int v8; // r1
  int v9; // r3
  int v11; // r3
  unsigned int v12; // r1
  int v13; // r3
  int v14; // r3

  v2 = (volatile int16_t **)off_12A130;
  if ( **(volatile int16_t **)off_12A130 >= 0 )
  {
    v5 = *(volatile uint8_t *)(a1 + 1225);
    v6 = dword_12A134;
    v7 = 140 * v5 + 48 * a2 + dword_12A134;
    v8 = 2 * a2;
    v9 = *(volatile uint8_t *)(v7 + 16);
    if ( v9 != 1 )
    {
      if ( v9 != 2 )
        return 0;
      return *(volatile uint32_t *)(140 * v5 + 16 * (a2 + v8) + v6 + 12);
    }
    goto LABEL_10;
  }
  if ( *(volatile uint8_t *)(a1 + 1224) && a2 <= 1 )
  {
    v5 = *(volatile uint8_t *)(a1 + 1225);
    v6 = dword_12A134;
    v13 = 140 * v5 + 48 * a2 + dword_12A134;
    v8 = 2 * a2;
    v14 = *(volatile uint8_t *)(v13 + 16);
    if ( v14 != 1 )
    {
      if ( v14 == 2 )
        return *(volatile uint32_t *)(140 * v5 + 16 * (a2 + v8) + v6 + 12);
      goto LABEL_15;
    }
LABEL_10:
    v12 = v6 + 140 * v5 + 16 * (a2 + v8);
    return *(volatile uint32_t *)(v12 + 12) + *(volatile uint32_t *)(v12 + 24);
  }
  irq_disable_mmio_write(dword_12A13C, dword_12A138, 1325);
  v5 = *(volatile uint8_t *)(a1 + 1225);
  v6 = dword_12A134;
  v8 = 2 * a2;
  v11 = *(volatile uint8_t *)(140 * v5 + 48 * a2 + dword_12A134 + 16);
  if ( v11 == 1 )
    goto LABEL_10;
  if ( v11 == 2 )
    return *(volatile uint32_t *)(140 * v5 + 16 * (a2 + v8) + v6 + 12);
  if ( **v2 >= 0 )
    return 0;
LABEL_15:
  mmio_write_field(dword_12A140, dword_12A138, 1337);
  return 0;
}



// bt_scan_poll @ 0x12a144
/* luna: Processes a pending scan-result entry, copying buffered payload into the entry and invoking RSN IE parsing when appropriate. */
volatile uint8_t * bt_scan_poll(volatile uint8_t *result, int a2) {
  int v2; // r2
  int v3; // r7
  int v4; // r6
  int v5; // r12
  unsigned int v6; // r4
  int v7; // lr
  volatile uint8_t *v8; // r5
  int v9; // r3
  int v10; // r1

  if ( result[1224] )
  {
    v2 = result[1225];
    v3 = dword_12A1D4;
    v4 = dword_12A1D4 + 140 * v2;
    v5 = *(volatile uint8_t *)(v4 + 115);
    v6 = *((volatile uint32_t *)result + 1) & 0xFFFFFFBF;
    *(volatile uint8_t *)(v4 + 134) = 1;
    v7 = 140 * v2;
    v8 = (volatile uint8_t *)(v3 + 140 * v2);
    *((volatile uint32_t *)result + 1) = v6;
    if ( !v5 )
      return rsn_parse_ie(v8);
    v9 = a2 + (v5 << 10);
    if ( *(volatile uint8_t *)(v4 + 112) || (v10 = a2 + 300, *((volatile uint32_t *)off_12A1D8 + 4) - v10 + 50 >= 0) )
    {
      *(volatile uint8_t *)(v3 + 140 * v2 + 114) = 1;
      mem_copy_util((void *)(uintptr_t)(v7 + 96 + v3), v9);
      return rsn_parse_ie(v8);
    }
    *(volatile uint32_t *)(v4 + 116) = v9;
    *(volatile uint8_t *)(v4 + 114) = 2;
    return (volatile uint8_t *)mem_copy_util((void *)(uintptr_t)(v7 + 96 + v3), v10);
  }
  return result;
}



// bt_get_conn_ptr @ 0x12a1dc
/* luna: Selects the connection record indexed by the caller's context, clears byte 134, and passes the record to the RSN IE parser. */
volatile uint8_t * bt_get_conn_ptr(int a1) {
  volatile uint8_t *v1; // r0

  v1 = (volatile uint8_t *)(dword_12A200 + 140 * *(volatile uint8_t *)(a1 + 1225));
  v1[134] = 0;
  return rsn_parse_ie(v1);
}



// bt_scan_stop @ 0x12a204
/* luna: Searches a received 802.11 management frame for a P2P vendor IE containing the Notice of Absence attribute and forwards that attribute to the NoA hand */
unsigned int bt_scan_stop(volatile uint8_t *a1, int a2, int a3) {
  unsigned int noa_attr; // r4
  unsigned int v5; // r0
  int frame; // r7
  volatile uint8_t *ie_cursor; // r3
  unsigned int ies_end; // r7
  int ie_length; // r5
  int ie_id; // r2
  volatile uint8_t *v13; // r4
  unsigned int attribute_end; // r5

  noa_attr = (uint8_t)a1[1224];
  if ( !a1[1224] )
    return noa_attr;
  if ( !a1[106] )
  {
    v5 = (uint8_t)a1[1225];
    if ( **(volatile int16_t **)off_12A2A8 < 0 && v5 > 1 )
    {
      irq_disable_mmio_write(dword_12A2AC, dword_12A2B0, 1420);
      v5 = (uint8_t)a1[1225];
    }
    frame = *(volatile uint32_t *)(a2 + 8);
    ie_cursor = (volatile uint8_t *)(frame + 36);
    ies_end = frame + *(volatile uint16_t *)(a3 + 28);
    if ( (unsigned int)ie_cursor < ies_end )
    {
      while ( 1 )
      {
        ie_length = ie_cursor[1];
        ie_id = *ie_cursor;
        v13 = ie_cursor;
        ie_cursor += ie_length + 2;
        if ( ie_id == 221 && v13[5] == 9 )
        {
          noa_attr = (unsigned int)(v13 + 6);
          attribute_end = noa_attr + (uint16_t)(ie_length - 4);
          if ( noa_attr < attribute_end )
          {
            while ( *(volatile uint8_t *)noa_attr != 12 )
            {
              noa_attr += *(volatile uint16_t *)(noa_attr + 1) + 3;
              if ( attribute_end <= noa_attr )
                goto LABEL_6;
            }
            if ( noa_attr )
              break;
          }
        }
LABEL_6:
        if ( ies_end <= (unsigned int)ie_cursor )
          goto LABEL_19;
      }
    }
    else
    {
LABEL_19:
      noa_attr = 0;
    }
    sec_table_entry_count(v5, noa_attr, *(volatile uint32_t *)(*(volatile uint32_t *)(*(volatile uint32_t *)(a3 + 8) + 8) + 24));
    return noa_attr;
  }
  return 0;
}



