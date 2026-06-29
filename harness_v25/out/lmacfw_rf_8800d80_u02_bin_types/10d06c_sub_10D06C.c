// sub_10D06C @ 0x10d06c, size 932 bytes
// Doc: sub_120D06C [unknown]: Dispatches handler based on byte tag compare against 3
// sub_120D06C [unknown]: Dispatches handler based on byte tag compare against 3
int  sub_10D06C(unsigned __int16 *a1)
{
  unsigned __int8 **v1; // r7
  unsigned __int8 *v2; // r2
  int v3; // r3
  int v5; // r6
  int v6; // r5
  int v7; // r9
  unsigned int v8; // r2
  int v9; // r3
  uint32_t *v10; // r6
  uint32_t *v11; // r3
  int v12; // r0
  int v13; // r1
  __int16 v14; // lr
  uint8_t *v15; // r6
  unsigned int v16; // r2
  __int16 v17; // r12
  int v18; // r8
  int *v19; // r3
  int v20; // r10
  int v21; // r3
  int v22; // r0
  char v23; // r2
  int *v24; // r6
  int v25; // r0
  int v26; // r0
  int v27; // r3
  int v28; // r2
  int *v29; // r0
  int v30; // r1
  int v31; // r2
  unsigned __int16 v32; // r2
  unsigned __int16 v34; // r1
  unsigned __int16 v35; // r2
  unsigned __int8 *v36; // r3
  int *v37; // r6
  int v38; // r0
  int v39; // r3
  int v40; // r2
  uint32_t *v41; // r5
  int v42; // r0
  int v43; // r3
  int v44; // r8
  int v45; // r3
  int *v46; // r5
  int v47; // r1
  int v48; // r2
  int v49; // r1
  int v50; // r0
  int v51; // [sp+0h] [bp-8h]

  v1 = (unsigned __int8 **)off_10D338;
  v2 = *(unsigned __int8 **)off_10D338;
  v3 = **(unsigned __int8 **)off_10D338;
  if ( v3 != 3 )
  {
    v5 = 0;
    goto LABEL_3;
  }
  v41 = off_10D340;
  while ( !*(uint32_t *)off_10D340 )
    ;
  if ( !*(uint32_t *)(*(uint32_t *)off_10D344 + 516) )
  {
    v45 = **(__int16 **)off_10D33C;
    *(uint32_t *)off_10D340 = 1;
    if ( v45 >= 0 )
    {
      v5 = 4;
      goto LABEL_50;
    }
    goto LABEL_71;
  }
  v42 = sub_11E7AC(*(uint32_t *)off_10D344 + 516);
  v43 = **(__int16 **)off_10D33C;
  *v41 = 1;
  if ( v43 < 0 )
  {
    if ( v42 )
    {
      v44 = v42 + 4;
      if ( v42 == -4 )
      {
        rf_cmd_send_n264(dword_10D430, dword_10D42C, 1567);
        v5 = v44;
        v2 = *v1;
        goto LABEL_50;
      }
      goto LABEL_49;
    }
LABEL_71:
    v5 = 4;
    rf_cmd_send_n264(dword_10D438, dword_10D434, 973);
    v2 = *v1;
    goto LABEL_50;
  }
  v44 = v42 + 4;
LABEL_49:
  v2 = *v1;
  v5 = v44;
LABEL_50:
  *(uint32_t *)(v5 + 8) = dword_10D364;
  v3 = *v2;
LABEL_3:
  if ( v3 == 1 )
  {
    if ( a1[5] <= 0x6Cu )
      v6 = sub_110370();
    else
      v6 = (*(int ( **)(uint32_t))(*(uint32_t *)(*(uint32_t *)off_10D360 + 8) + 16))(*(uint32_t *)(*(uint32_t *)off_10D360 + 4));
    if ( !v6 )
      goto LABEL_59;
    v34 = a1[3];
    v35 = a1[4];
    *(uint32_t *)(v6 + 12) = dword_10D364;
    v36 = *v1;
    *(uint16_t *)(v6 + 6) = v34;
    *(uint16_t *)(v6 + 8) = v35;
    v5 = v6 + 4;
    if ( *v36 != 2 )
      goto LABEL_5;
  }
  else
  {
    v6 = 0;
    if ( v3 != 2 )
    {
LABEL_5:
      v7 = 0;
      goto LABEL_6;
    }
  }
  if ( a1[5] <= 0x6Cu )
    v6 = sub_1132C0();
  else
    v6 = (*(int ( **)(uint32_t))(*(uint32_t *)(*(uint32_t *)off_10D360 + 8) + 16))(*(uint32_t *)(*(uint32_t *)off_10D360
                                                                                                 + 4));
  if ( !v6 )
  {
LABEL_59:
    sub_10DA6C(dword_10D410, a1[2], a1[4]);
    return sub_11DEE8(a1);
  }
  if ( !*((uint32_t *)off_10D34C + 2057) )
  {
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(uint32_t *)off_10D414 = 1;
    }
    v46 = (int *)off_10D418;
    ++*(uint32_t *)off_10D418;
    ((void (*)(void))rf_bus_mark_ne0)();
    if ( *v46 )
    {
      v48 = *v46 - 1;
      v47 = *(uint32_t *)off_10D414;
      *v46 = v48;
      if ( !v48 )
      {
        if ( v47 )
          __enable_irq();
      }
    }
    v51 = sub_11E82C(dword_10D41C, v47);
    v50 = sub_11E82C(dword_10D420, v49);
    sub_10DA6C(dword_10D424, v51, v50);
    return sub_11DEE8(a1);
  }
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_10D354 = 1;
  }
  v37 = (int *)off_10D358;
  v38 = dword_10D368;
  ++*(uint32_t *)off_10D358;
  v7 = sub_11E7AC(v38);
  if ( *v37 )
  {
    v39 = *v37 - 1;
    v40 = *(uint32_t *)off_10D354;
    *v37 = v39;
    if ( !v39 )
    {
      if ( v40 )
        __enable_irq();
    }
  }
  *(uint16_t *)v6 = a1[5] + 12;
  *(uint8_t *)(v6 + 2) = 17;
  *(uint8_t *)(v6 + 3) = 0;
  v5 = v6 + 4;
LABEL_6:
  v8 = a1[5];
  *(uint16_t *)v5 = a1[2];
  *(uint16_t *)(v5 + 6) = v8;
  if ( v8 )
  {
    if ( **(__int16 **)off_10D33C < 0 && v8 > 0x80 )
    {
      rf_cmd_send_n264(dword_10D370, dword_10D36C, 1671);
      v8 = a1[5];
    }
    sub_1282E8(v5 + 12, a1 + 6, v8);
    v9 = **v1;
    if ( v9 != 3 )
    {
LABEL_8:
      if ( v9 != 2 )
        goto LABEL_9;
LABEL_16:
      v12 = a1[5];
      if ( (v12 & 3) != 0 )
      {
        v14 = (unsigned __int8)(4 - (v12 & 3));
        v13 = (unsigned __int8)(4 - (v12 & 3));
      }
      else
      {
        v13 = 0;
        v14 = 0;
      }
      v15 = off_10D34C;
      v16 = *((unsigned __int16 *)off_10D34C + 4122);
      if ( v16 > 0x186 )
      {
        v18 = 0;
        LOWORD(v16) = 0;
        v17 = 1;
      }
      else
      {
        v17 = v16 + 1;
        v18 = 8 * v16;
      }
      v19 = (int *)off_10D350;
      *(uint16_t *)(v7 + 12) = v16;
      v20 = *v19;
      v21 = v12 + 16;
      v22 = v20 + v18;
      *(uint32_t *)(v22 + 4) = v6;
      *(uint16_t *)(v20 + v18) = v14 + v21;
      *(uint8_t *)(v22 + 3) = *(uint8_t *)(v20 + v18 + 3) & 0x31 | 4;
      v23 = v15[3074];
      *((uint16_t *)v15 + 4122) = v17;
      v15[3074] = v23 + 1;
      *(uint32_t *)(v7 + 4) = v20 + v18;
      *(uint32_t *)(v7 + 8) = v21 + v13;
      *(uint8_t *)(v7 + 14) = 1;
      *(uint32_t *)v7 = 0;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(uint32_t *)off_10D354 = 1;
      }
      v24 = (int *)off_10D358;
      v25 = dword_10D35C;
      ++*(uint32_t *)off_10D358;
      v26 = list_push_tail(v25);
      rf_bus_mark_ne0(v26);
      if ( *v24 )
      {
        v27 = *v24 - 1;
        v28 = *(uint32_t *)off_10D354;
        *v24 = v27;
        if ( !v27 )
        {
          if ( v28 )
            __enable_irq();
        }
      }
      if ( **v1 != 1 )
        return sub_11DEE8(a1);
      goto LABEL_27;
    }
  }
  else
  {
    v9 = **v1;
    if ( v9 != 3 )
      goto LABEL_8;
  }
  v10 = off_10D340;
  while ( !*(uint32_t *)off_10D340 )
    ;
  list_push_tail(*(uint32_t *)off_10D344 + 524);
  v11 = off_10D348;
  *v10 = 1;
  *v11 = 2;
  v9 = **v1;
  if ( v9 == 2 )
    goto LABEL_16;
LABEL_9:
  if ( v9 != 1 )
    return sub_11DEE8(a1);
LABEL_27:
  v29 = (int *)sub_1101AC();
  if ( !v29 )
  {
    sub_10DA6C(dword_10D428, v30, v31);
    return sub_11DEE8(a1);
  }
  *(uint16_t *)v6 = a1[5] + 12;
  *(uint8_t *)(v6 + 2) = 17;
  *(uint8_t *)(v6 + 3) = 0;
  v32 = a1[5];
  v29[1] = 0;
  *v29 = v6;
  v29[2] = (unsigned __int16)(v32 + 16) | 0x80000000;
  rf_field_align_n_2a4();
  return sub_11DEE8(a1);
}

