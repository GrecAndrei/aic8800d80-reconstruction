// ke_timer_tick_inc @ 0x141344
/* luna: Advances the kernel timer counter, clamps a 16-bit field in each of twelve timer records to 1, and performs threshold-dependent HCI/MAC processing. */
int ke_timer_tick_inc() {
  int timer_state_base; // r3
  int next_tick; // r0
  int timer_record_cursor; // r4
  int result; // r0

  timer_state_base = dword_14139C;
  next_tick = *(volatile uint32_t *)(dword_14139C + 6480) + 1;
  *(volatile uint32_t *)(dword_14139C + 6480) = next_tick;
  timer_record_cursor = timer_state_base;
  do
  {
    if ( *(volatile uint16_t *)(timer_record_cursor + 4) > 1u )
      *(volatile uint16_t *)(timer_record_cursor + 4) = 1;
    timer_record_cursor += 528;
  }
  while ( timer_record_cursor != timer_state_base + 6336 );
  if ( next_tick >= (int)*(volatile uint32_t *)(timer_record_cursor + 148) )
  {
    result = hci_cmd_preprocess(0xBu, 0);
    *(volatile uint32_t *)(timer_record_cursor + 144) = -1;
  }
  else
  {
    hci_cmd_preprocess(0xBu, 4);
    return mac_write_header_word(11264, 11, 11);
  }
  return result;
}


// ke_timer_get_time @ 0x1413a0
void ke_timer_get_time() {
  volatile int16_t **v0; // r6
  int v1; // r3
  int v2; // r5
  unsigned int v3; // r3
  int v4; // r4
  int v5; // r6
  volatile uint32_t *v6; // r1
  int v7; // r4
  unsigned int v8; // r3
  unsigned int v9; // r3

  v0 = (volatile int16_t **)off_141498;
  v1 = 136 * *(volatile uint32_t *)(dword_141494 + 6480);
  v2 = v1 + 6336 + dword_141494;
  if ( **(volatile int16_t **)off_141498 >= 0 )
  {
    v3 = *(volatile uint8_t *)(v1 + dword_141494 + 6339);
    if ( v3 > 1 )
    {
      if ( v3 != 2 )
        return;
      goto LABEL_4;
    }
LABEL_12:
    bt_event_dispatch(v2, 1);
    return;
  }
  v7 = dword_141494 + v1;
  if ( *(volatile uint8_t *)(dword_141494 + v1 + 6338) == 5 )
  {
    v9 = *(volatile uint8_t *)(v7 + 6339);
    if ( v9 <= 1 )
      goto LABEL_12;
    if ( v9 != 2 )
    {
LABEL_18:
      irq_disable_mmio_write(off_1414A8, (int)aRmStartActiveR, 1726);
      return;
    }
  }
  else
  {
    irq_disable_mmio_write((int)aRequestTypeMac, (int)aRmStartActiveR, 1714);
    v8 = *(volatile uint8_t *)(v7 + 6339);
    if ( v8 <= 1 )
      goto LABEL_12;
    if ( v8 != 2 )
    {
      if ( **v0 >= 0 )
        return;
      goto LABEL_18;
    }
  }
LABEL_4:
  v4 = dword_141494;
  hci_cmd_preprocess(0xBu, 2);
  v5 = v4 + 6336;
  clear_stats_buf((volatile uint32_t *)dword_14149C);
  do
  {
    while ( *(volatile uint16_t *)(v4 + 4) != 1 || !util_memcmp((volatile uint16_t *)(v4 + 6), v4 + 28, v2) )
    {
      v4 += 528;
      if ( v4 == v5 )
        goto LABEL_9;
    }
    v6 = (volatile uint32_t *)v4;
    *(volatile uint16_t *)(v4 + 24) = 0;
    *(volatile uint8_t *)(v4 + 22) = 0;
    *(volatile uint16_t *)(v4 + 4) = 2;
    v4 += 528;
    wlan_ioctl_handler_1(v5 + 136, v6);
  }
  while ( v4 != v5 );
LABEL_9:
  bt_ll_state_check(v2, 0);
}


// ke_timer_check @ 0x1414ac
/* luna: Checks the current kernel timer entry and dispatches its event when the entry is eligible. */
int ke_timer_check() {
  volatile int16_t **v0; // r8
  int timer_env; // r5
  int timer_index; // r4
  int v3; // r6
  int timer_entry; // r7
  int result; // r0

  v0 = (volatile int16_t **)off_14157C;
  timer_env = dword_141568;
  timer_index = *(volatile uint32_t *)(dword_141568 + 6480);
  if ( **(volatile int16_t **)off_14157C >= 0 || timer_index < 0 && (result = irq_disable_mmio_write(dword_141578, dword_14156C, 1734), **v0 >= 0) )
  {
    v3 = 16 * timer_index;
    if ( *(volatile uint8_t *)(timer_env + 136 * timer_index + 6339) > 1u )
      return result;
    return bt_event_dispatch(timer_env + 8 * (timer_index + v3) + 6336, 0);
  }
  timer_entry = timer_env + 136 * timer_index;
  v3 = 16 * timer_index;
  if ( *(volatile uint8_t *)(timer_entry + 6338) == 5 )
  {
    if ( *(volatile uint8_t *)(timer_entry + 6339) <= 1u )
      return bt_event_dispatch(timer_env + 8 * (timer_index + v3) + 6336, 0);
    return irq_disable_mmio_write(dword_141574, dword_14156C, 1744);
  }
  result = irq_disable_mmio_write(dword_141570, dword_14156C, 1735);
  if ( *(volatile uint8_t *)(timer_entry + 6339) <= 1u )
    return bt_event_dispatch(timer_env + 8 * (timer_index + v3) + 6336, 0);
  if ( **v0 < 0 )
    return irq_disable_mmio_write(dword_141574, dword_14156C, 1744);
  return result;
}



// ke_timer_clear @ 0x141580
int ke_timer_clear(int a1, int a2) {
  int v2; // r4
  int v4; // r6
  int result; // r0

  if ( a2 )
  {
    v2 = dword_1415EC;
    v4 = *(volatile uint32_t *)(dword_1415EC + 6480);
    if ( bt_global_state_read() )
    {
      if ( hci_cmd_handler(0xBu) == 3 )
        return ke_timer_check();
      else
        return ke_timer_tick_inc();
    }
    else
    {
      *(volatile uint8_t *)(a1 + 98) = 1;
      acl_tx_setup(a1, 0, 0, v2 + 136 * v4 + 6336);
      return sec_check(a1, 3);
    }
  }
  else
  {
    result = hci_cmd_preprocess(0xBu, 0);
    *(volatile uint32_t *)(dword_1415EC + 6480) = -1;
  }
  return result;
}


// ke_timer_set_1 @ 0x1415f0
volatile int * ke_timer_set_1(int a1, int a2, int a3, int a4, char a5, char a6, char a7) {
  int v7; // r7
  int v9; // r0
  int v10; // cc
  volatile int *result; // r0
  int v14; // r3
  int v15; // r1
  int v16; // r2
  int v17; // r12
  int v18; // r5
  uint16_t v19; // r1
  uint16_t v20; // r2
  volatile uint8_t *v21; // r8
  volatile uint8_t *v22; // r4
  int v23; // r3
  char v24; // t1
  int v25; // r9
  int v26; // r11
  int v27; // r10
  int v28; // r6
  int v29; // r3
  unsigned int v30; // r4
  volatile uint8_t *v31; // r1
  unsigned int v32; // r2
  int16_t v33; // r10
  unsigned int v34; // r3
  char v35; // r3
  volatile uint8_t *v36; // r3
  int v37; // r1
  int v38; // r2
  int v39; // r2
  int v40; // zf
  int v41; // r2
  int v42; // r2
  int v43; // r2
  char v44; // r3
  struct __attribute__((packed)) { int v45; // [sp+4h] [bp-28h]
  char _pad1[16]; int v47; // [sp+18h] [bp-14h]
  int v48; // [sp+1Ch] [bp-10h]
  uint16_t v49; // [sp+20h] [bp-Ch] BYREF
  uint16_t v50; // [sp+22h] [bp-Ah]
  uint16_t v51; // [sp+24h] [bp-8h]
  } _frame;
  v7 = dword_1418D4;
  v9 = *(volatile uint32_t *)(dword_1418D4 + 6480);
  _frame.v49 = *(volatile uint16_t *)(a1 + 16);
  v10 = v9 < 0;
  if ( v9 >= 0 )
    v9 *= 17;
  _frame.v50 = (_frame.v50 & ~0xFFu) | ((uint8_t)(*(volatile uint8_t *)(a1 + 18)) & 0xFFu);
  if ( !v10 )
    v9 = dword_1418D4 + 8 * v9;
  _frame.v50 = (_frame.v50 & ~0xFF00u) | (((uint8_t)(*(volatile uint8_t *)(a1 + 19)) & 0xFFu) << 8);
  if ( !v10 )
    v7 = v9 + 6336;
  _frame.v51 = (_frame.v51 & ~0xFFu) | ((uint8_t)(*(volatile uint8_t *)(a1 + 20)) & 0xFFu);
  if ( v10 )
    v7 = 0;
  _frame.v51 = (_frame.v51 & ~0xFF00u) | (((uint8_t)(*(volatile uint8_t *)(a1 + 21)) & 0xFFu) << 8);
  result = (volatile int *)util_memcmp(&_frame.v49, 0, v7);
  if ( !result )
    return result;
  v14 = dword_1418D4;
  v15 = 0;
  v16 = dword_1418D4 + 6336;
  v17 = 0;
  v18 = 0;
  do
  {
    while ( 1 )
    {
      if ( *(volatile uint16_t *)(v14 + 6) == _frame.v49 && *(volatile uint16_t *)(v14 + 8) == _frame.v50 )
      {
        result = (volatile int *)*(volatile uint16_t *)(v14 + 10);
        if ( result == (volatile int *)_frame.v51 )
        {
          v18 = v14;
          goto LABEL_25;
        }
      }
      result = (volatile int *)*(volatile uint16_t *)(v14 + 4);
      if ( result == (volatile int *)1 )
      {
        if ( v17 )
        {
          result = (volatile int *)*(volatile char *)(v17 + 20);
          if ( *(volatile char *)(v14 + 20) < (int)result )
            v17 = v14;
        }
        else
        {
          v17 = v14;
        }
        goto LABEL_15;
      }
      if ( result == (volatile int *)3 )
      {
        if ( v15 )
        {
          result = (volatile int *)*(volatile char *)(v15 + 20);
          if ( *(volatile char *)(v14 + 20) < (int)result )
            v15 = v14;
        }
        else
        {
          v15 = v14;
        }
        goto LABEL_15;
      }
      if ( !*(volatile uint16_t *)(v14 + 4) )
        break;
LABEL_15:
      v14 += 528;
      if ( v14 == v16 )
        goto LABEL_23;
    }
    if ( !v18 )
      v18 = v14;
    v14 += 528;
  }
  while ( v14 != v16 );
LABEL_23:
  if ( v18 )
    goto LABEL_24;
  if ( v15 )
  {
    v18 = v15;
    goto LABEL_24;
  }
  if ( v17 && *(volatile char *)(v17 + 20) < a6 )
  {
    v18 = v17;
LABEL_24:
    result = memset((volatile int *)v18, 0, 0x210u);
LABEL_25:
    if ( *(volatile uint16_t *)(v18 + 4) != 3 )
    {
      v19 = _frame.v49;
      v20 = _frame.v50;
      *(volatile uint32_t *)(v18 + 12) = a3;
      *(volatile uint16_t *)(v18 + 10) = _frame.v51;
      if ( a5 )
        result = (volatile int *)4;
      else
        result = (volatile int *)5;
      v21 = (volatile uint8_t *)(a1 + 36);
      *(volatile uint8_t *)(v18 + 17) = a7;
      *(volatile uint8_t *)(v18 + 18) = (uint8_t)result;
      *(volatile uint16_t *)(v18 + 6) = v19;
      *(volatile uint16_t *)(v18 + 8) = v20;
      v22 = (volatile uint8_t *)(a1 + 24);
      v23 = v18 + 63;
      do
      {
        v24 = *v22++;
        *(volatile uint8_t *)++v23 = v24;
      }
      while ( v22 != v21 );
      v25 = a2 - 36;
      v26 = v18 + 76;
      _frame.v47 = 0;
      _frame.v48 = 0;
      if ( a2 - 36 > 2 )
      {
        v27 = 452;
        while ( 1 )
        {
          v28 = *v21;
          v29 = v21[2];
          v30 = v21[1] + 2;
          v31 = v21 + 2;
          if ( *v21 )
          {
            if ( v28 == 3 )
            {
              *(volatile uint8_t *)(v18 + 21) = v26 - (v18 + 64);
              *(volatile uint8_t *)(v18 + 16) = *v31;
            }
            else
            {
              v32 = *(volatile uint8_t *)(v18 + 18);
              if ( v32 > 5 )
              {
                if ( v32 == 6 )
                {
LABEL_37:
                  if ( v28 == 61 )
                  {
                    if ( v21[1] == 22 )
                    {
                      *(volatile uint8_t *)(v18 + 18) = 7;
                      _frame.v48 = v21[3] & 3;
                      v38 = _frame.v47;
                      if ( (v21[3] & 3) != 0 )
                        v38 = 1;
                      _frame.v47 = v38;
                    }
                    goto LABEL_41;
                  }
LABEL_38:
                  if ( v28 == 192 )
                  {
                    if ( v21[1] == 5 )
                    {
                      *(volatile uint8_t *)(v18 + 18) = 9;
                      v39 = (uint8_t)*v31;
                      if ( *v31 )
                      {
                        if ( v39 == 1 )
                        {
                          _frame.v47 = 2;
                        }
                        else if ( v39 == 2 )
                        {
                          _frame.v47 = 3;
                        }
                        else
                        {
                          v40 = v39 == 3;
                          v41 = _frame.v47;
                          if ( v40 )
                            v41 = 4;
                          _frame.v47 = v41;
                        }
                      }
                    }
                    goto LABEL_41;
                  }
LABEL_39:
                  if ( v28 == 255 && v30 > 8 && v29 == 36 )
                  {
                    if ( v32 != 9 && v30 > 0xB && (*(volatile uint32_t *)(v21 + 3) & 0x4000) != 0 )
                    {
                      v42 = v21[9];
                      if ( v21[9] )
                      {
                        if ( v42 == 1 )
                        {
                          _frame.v47 = 2;
                        }
                        else if ( v42 == 2 )
                        {
                          _frame.v47 = 3;
                        }
                        else
                        {
                          v40 = v42 == 3;
                          v43 = _frame.v47;
                          if ( v40 )
                            v43 = 4;
                          _frame.v47 = v43;
                        }
                      }
                    }
                    *(volatile uint8_t *)(v18 + 18) = 14;
                  }
                  goto LABEL_41;
                }
                if ( v32 <= 8 )
                  goto LABEL_38;
                if ( v32 <= 0xD )
                  goto LABEL_39;
              }
              else
              {
                if ( v28 != 42 )
                  goto LABEL_37;
                *(volatile uint8_t *)(v18 + 18) = 6;
              }
            }
          }
          else
          {
            _frame.v45 = v21[2];
            memcpy((void *)(uintptr_t)(v18 + 28), v21, v21[1] + 2);
            result = (volatile int *)util_memcmp((volatile uint16_t *)(v18 + 6), (int)v21, v7);
            v29 = _frame.v45;
            if ( !result )
            {
              *(volatile uint16_t *)(v18 + 4) = 0;
              return result;
            }
          }
LABEL_41:
          if ( (int)v30 <= v27 && (result = (volatile int *)find_ll_item(v28, v29, v7)) != 0 )
          {
            v36 = v21;
            v37 = v26 - (uint32_t)v21;
            v21 += v30;
            do
            {
              v36[v37] = *v36;
              ++v36;
            }
            while ( v21 != v36 );
            v26 += v30;
            v27 -= v30;
          }
          else
          {
            v21 += v30;
          }
          v25 -= v30;
          if ( v25 <= 2 )
          {
            v33 = 464 - v27;
            goto LABEL_46;
          }
        }
      }
      v33 = 12;
LABEL_46:
      v34 = *(volatile uint8_t *)(v18 + 21);
      *(volatile uint16_t *)(v18 + 26) = v33;
      if ( v34 )
      {
        *(volatile uint8_t *)(v18 + 20) = a6;
        v34 = *(volatile uint8_t *)(v18 + 16);
        goto LABEL_48;
      }
      if ( *(volatile uint16_t *)(v18 + 4) && *(volatile char *)(v18 + 20) >= a6 )
      {
        v34 = *(volatile uint8_t *)(v18 + 16);
      }
      else
      {
        *(volatile uint8_t *)(v18 + 20) = a6;
        if ( a5 )
        {
          if ( a5 != 1 || (uint16_t)(a4 - 5005) > 0x370u )
            goto LABEL_96;
          v34 = (uint8_t)((unsigned int)(((unsigned int)dword_141A2C
                                                * (uint64_t)(unsigned int)(a4 - 5000)) >> 32) >> 2);
          *(volatile uint8_t *)(v18 + 16) = v34;
        }
        else if ( (unsigned int)(a4 - 2412) > 0x48 )
        {
          v34 = 0;
          *(volatile uint8_t *)(v18 + 16) = 0;
        }
        else
        {
          if ( a4 != 2484 )
          {
            v34 = (uint8_t)((unsigned int)(((unsigned int)dword_141A2C
                                                  * (uint64_t)(unsigned int)(a4 - 2407)) >> 32) >> 2);
LABEL_96:
            *(volatile uint8_t *)(v18 + 16) = v34;
            goto LABEL_48;
          }
          v34 = 14;
          *(volatile uint8_t *)(v18 + 16) = 14;
        }
      }
LABEL_48:
      if ( _frame.v47 != 4 )
      {
        if ( _frame.v47 == 3 )
        {
          v35 = -127;
          goto LABEL_57;
        }
        if ( _frame.v47 == 2 )
        {
          v35 = 0x80;
          goto LABEL_57;
        }
        if ( !a5 )
        {
          if ( v34 == 14 )
          {
            v35 = 82;
          }
          else if ( _frame.v47 )
          {
            if ( _frame.v48 == 1 )
              v35 = 84;
            else
              v35 = 83;
          }
          else
          {
            v35 = 81;
          }
          goto LABEL_57;
        }
        if ( v34 <= 0x30 )
        {
          if ( !_frame.v47 )
          {
            v35 = 115;
            goto LABEL_57;
          }
          v44 = 0;
        }
        else if ( v34 <= 0x40 )
        {
          if ( !_frame.v47 )
          {
            v35 = 118;
            goto LABEL_57;
          }
          v44 = 3;
        }
        else
        {
          if ( v34 > 0x90 )
          {
            if ( v34 <= 0xA4 )
            {
              if ( _frame.v47 )
                goto LABEL_115;
              v35 = 124;
            }
            else
            {
              if ( _frame.v47 )
              {
LABEL_115:
                v44 = 10;
                goto LABEL_116;
              }
              v35 = 125;
            }
LABEL_57:
            *(volatile uint8_t *)(v18 + 19) = v35;
            *(volatile uint16_t *)(v18 + 4) = 1;
            return result;
          }
          if ( !_frame.v47 )
          {
            v35 = 121;
            goto LABEL_57;
          }
          v44 = 6;
        }
LABEL_116:
        if ( _frame.v48 == 1 )
          v35 = v44 + 116;
        else
          v35 = v44 + 117;
        goto LABEL_57;
      }
      v35 = -126;
      goto LABEL_57;
    }
  }
  return result;
}



