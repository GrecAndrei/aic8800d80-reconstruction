// sdio_buffer_prepare_n_2f4 @ 0x11e2c8, size 810 bytes
// Doc: sdio_buffer_prepare_n_2f4 [mmio]: Compares two buffer pointers for SDIO prepare operation
// sdio_buffer_prepare_n_2f4 [mmio]: Compares two buffer pointers for SDIO prepare operation
int  sdio_buffer_prepare_n_2f4(int a1, unsigned int a2, int a3, __int16 a4, int a5, int a6)
{
  int v6; // r8
  unsigned __int8 **v7; // r7
  int v8; // r12
  unsigned __int8 *v9; // r5
  int v11; // r3
  int v14; // r3
  uint32_t *v15; // r0
  int v16; // r3
  int *v18; // r5
  int v19; // r8
  unsigned __int8 v20; // r7
  uint16_t *v21; // r5
  int *v22; // r9
  int v23; // r10
  bool v24; // cc
  int v25; // r0
  int v26; // r0
  int v27; // r1
  int v28; // r3
  int v29; // r0
  uint8_t *v30; // r1
  int v31; // r2
  char v32; // r10
  int v33; // r2
  int v34; // r3
  uint8_t *v35; // r5
  int v36; // r2
  int *v37; // r9
  int v38; // r0
  int v39; // r0
  int v40; // r1
  int v41; // r3
  int v42; // r2
  uint32_t *v43; // r0
  int v44; // r1
  int v45; // r2
  int v46; // r7
  int v47; // r2
  int v48; // r12
  int v49; // r2
  int v50; // r0
  unsigned int CPSR; // r3
  int *v52; // r4
  int _4b4; // r0
  int v54; // r2
  int v55; // r3
  int v56; // r0
  int v57; // [sp+Eh] [bp-Eh] BYREF
  int v58[2]; // [sp+14h] [bp-8h] BYREF

  v7 = (unsigned __int8 **)off_11E55C;
  v8 = *(uint32_t *)(a1 + 28);
  v9 = *(unsigned __int8 **)off_11E55C;
  v58[0] = v8;
  LOWORD(v57) = a4;
  v11 = *v9;
  if ( v11 != 2 )
    goto LABEL_2;
  v21 = off_11E56C;
  if ( *((uint32_t *)off_11E56C + 2057) )
  {
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(uint32_t *)off_11E570 = 1;
    }
    v22 = (int *)off_11E590;
    v23 = dword_11E594;
    v24 = (unsigned __int16)v21[4122] > 0x186u;
    ++*(uint32_t *)off_11E590;
    v25 = dword_11E574;
    if ( v24 )
      v21[4122] = 0;
    v26 = rf_bus_mark_n100_d2d0(v25);
    v27 = *(uint32_t *)off_11E578;
    v28 = (unsigned __int16)v21[4122];
    v6 = v26;
    v29 = *(uint32_t *)off_11E578 + 8 * v28;
    *(uint16_t *)(v6 + 12) = v28;
    *(uint32_t *)(v29 + 4) = a1 + 48;
    *(uint32_t *)(v27 + 8 * v28) = v23;
    v30 = off_11E57C;
    *(uint32_t *)(v6 + 4) = v29;
    v31 = *v22;
    v32 = *((uint8_t *)v21 + 3074) + 1;
    LOBYTE(v29) = v30[3] + 1;
    v21[4122] = v28 + 1;
    *((uint8_t *)v21 + 3074) = v32;
    v30[3] = v29;
    if ( v31 )
    {
      v33 = v31 - 1;
      v34 = *(uint32_t *)off_11E570;
      *v22 = v33;
      if ( !v33 )
      {
        if ( v34 )
          __enable_irq();
      }
    }
    v11 = **v7;
    if ( v11 == 2 )
    {
      fmac_init_dispatch(v58, a2, &v57);
      v14 = **v7;
      if ( v14 != 2 )
        goto LABEL_5;
LABEL_25:
      v35 = off_11E57C;
      if ( !*((uint8_t *)off_11E57C + 2) )
        goto LABEL_6;
      v36 = *(uint32_t *)(v6 + 4);
      *(uint32_t *)(v6 + 8) = *(unsigned __int16 *)off_11E57C + 58;
      *(uint8_t *)(v36 + 3) &= 0x3Fu;
      *(uint8_t *)(v6 + 14) = v35[3];
      *(uint32_t *)v6 = 0;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(uint32_t *)off_11E570 = 1;
      }
      v37 = (int *)off_11E590;
      v38 = dword_11E580;
      ++*(uint32_t *)off_11E590;
      v39 = list_push_tail(v38);
      rf_cmd_queue_next_4b4(v39, v40);
      if ( *v37 )
      {
        v41 = *v37 - 1;
        v42 = *(uint32_t *)off_11E570;
        *v37 = v41;
        if ( !v41 )
        {
          if ( v42 )
            __enable_irq();
        }
      }
      *(uint32_t *)v35 = 0;
      *((uint32_t *)v35 + 1) = 0;
      v14 = **v7;
LABEL_5:
      if ( v14 == 1 )
      {
        v18 = (int *)off_11E564;
        if ( *((uint8_t *)off_11E564 + 32) )
        {
          v43 = (uint32_t *)sub_1102BC();
          v46 = (int)v43;
          if ( v43 )
          {
            if ( *((uint8_t *)v18 + 32) )
            {
              v47 = *v18;
              v48 = v18[1] + 1;
              v43[2] = (v48 << 24) & 0x7F000000 | v43[2] & 0x80FFFFFF;
              v18[1] = v48;
              sub_11113C(v43, a1 + 48, v47, 0x3Au, 0);
              v49 = *((unsigned __int8 *)off_11E588 + 192);
              v18[3] += 58;
              if ( v49 )
                sub_11E270(v46);
              else
                sub_11101C(v46, v18[1], v18[2]);
              *(uint8_t *)off_11E58C |= 1u;
              v18[1] = 0;
              v18[3] = 0;
              *v18 = 0;
              v18[2] = 0;
              *((uint8_t *)v18 + 32) = 0;
              goto LABEL_6;
            }
          }
          else
          {
            v56 = dword_11E600;
            *(uint8_t *)(a1 + 16) |= 1u;
            msg_parse(v56, v44, v45);
            *((uint8_t *)v18 + 32) = 0;
          }
        }
        feature_guard_check(1024, dword_11E568);
        v19 = *v18;
        *(uint8_t *)(a1 + 16) |= 1u;
        if ( v19 && v18[1] )
        {
          v20 = 0;
          do
          {
            v19 = *(uint32_t *)(v19 + 4);
            log_free_dispatch_n2f4_0();
            ++v20;
          }
          while ( v20 < (unsigned int)v18[1] );
        }
        v18[1] = 0;
        v18[3] = 0;
        *v18 = 0;
        v18[2] = 0;
      }
LABEL_6:
      sub_11DF7C(a1, v58[0]);
      v15 = off_11E560;
      *(uint32_t *)(a1 + 4) = a5;
      v16 = v15[14];
      *(uint32_t *)(a1 + 8) = a6;
      if ( v16 )
        return list_push_tail(v15 + 14);
      else
        return list_push_tail(dword_11E584);
    }
LABEL_2:
    if ( v11 == 1 )
      sub_11DD44(v58, a2, &v57);
    else
      main_event_handler(v58, a2, a3, &v57, 0);
    v14 = **v7;
    if ( v14 != 2 )
      goto LABEL_5;
    goto LABEL_25;
  }
  *(uint8_t *)(a1 + 16) |= 1u;
  v50 = sub_11DF7C(a1, v8);
  CPSR = __get_CPSR();
  if ( (CPSR & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_11E5F4 = 1;
  }
  v52 = (int *)off_11E5F8;
  ++*(uint32_t *)off_11E5F8;
  _4b4 = rf_cmd_queue_next_4b4(v50, CPSR << 31);
  if ( *v52 )
  {
    v55 = *v52 - 1;
    v54 = *(uint32_t *)off_11E5F4;
    *v52 = v55;
    if ( !v55 )
    {
      if ( v54 )
        __enable_irq();
    }
  }
  return sub_10DC24(dword_11E5FC, _4b4, v54);
}

