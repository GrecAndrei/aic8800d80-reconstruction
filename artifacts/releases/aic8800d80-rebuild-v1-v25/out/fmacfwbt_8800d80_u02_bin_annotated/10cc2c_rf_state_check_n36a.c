// fwstruct annotate: 10cc2c_rf_state_check_n36a.c
// rf_state_check_n36a @ 0x10cc2c, size 936 bytes
// Doc: rf_state_check_n36a [rf]: Inspect RF status register and derived byte fields for state
// rf_state_check_n36a [rf]: Inspect RF status register and derived byte fields for state
int __fastcall rf_state_check_n36a(unsigned __int16 *a1)
{
  unsigned __int8 **v1; // r7
  unsigned __int8 *v2; // r2
  int v3; // r3
  int v5; // r6
  int v6; // r5
  int v7; // r9
  unsigned int v8; // r2
  int v9; // r3
  _DWORD *v10; // r6
  _DWORD *v11; // r3
  int v12; // r0
  int v13; // r1
  __int16 v14; // lr
  _BYTE *v15; // r6
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
  _DWORD *v41; // r5
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

  v1 = (unsigned __int8 **)off_10CEFC;
  v2 = *(unsigned __int8 **)off_10CEFC;
  v3 = **(unsigned __int8 **)off_10CEFC;
  if ( v3 != 3 )
  {
    v5 = 0;
    goto LABEL_3;
  }
  v41 = off_10CF04;
  while ( !*(_DWORD *)off_10CF04 )
    ;
  if ( !*(_DWORD *)(*(_DWORD *)off_10CF08 + 516) )
  {
    v45 = **(__int16 **)off_10CF00;
    *(_DWORD *)off_10CF04 = 1;
    if ( v45 >= 0 )
    {
      v5 = 4;
      goto LABEL_50;
    }
    goto LABEL_71;
  }
  v42 = sub_12D4F8(*(_DWORD *)off_10CF08 + 516);
  v43 = **(__int16 **)off_10CF00;
  *v41 = 1;
  if ( v43 < 0 )
  {
    if ( v42 )
    {
      v44 = v42 + 4;
      if ( v42 == -4 )
      {
        sub_12F694(dword_10CFF4, dword_10CFF0, 1567);
        v5 = v44;
        v2 = *v1;
        goto LABEL_50;
      }
      goto LABEL_49;
    }
LABEL_71:
    v5 = 4;
    sub_12F694(dword_10CFFC, dword_10CFF8, 973);
    v2 = *v1;
    goto LABEL_50;
  }
  v44 = v42 + 4;
LABEL_49:
  v2 = *v1;
  v5 = v44;
LABEL_50:
  *(_DWORD *)(v5 + 8) = dword_10CF28;
  v3 = *v2;
LABEL_3:
  if ( v3 == 1 )
  {
    if ( a1[5] <= 0x6Cu )
      v6 = log_free_dispatch_n478();
    else
      v6 = (*(int (__fastcall **)(_DWORD))(*(_DWORD *)(*(_DWORD *)off_10CF24 + 8) + 16))(*(_DWORD *)(*(_DWORD *)off_10CF24 + 4));
    if ( !v6 )
      goto LABEL_59;
    v34 = a1[3];
    v35 = a1[4];
    *(_DWORD *)(v6 + 12) = dword_10CF28;
    v36 = *v1;
    *(_WORD *)(v6 + 6) = v34;
    *(_WORD *)(v6 + 8) = v35;
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
    v6 = sub_113864();
  else
    v6 = (*(int (__fastcall **)(_DWORD))(*(_DWORD *)(*(_DWORD *)off_10CF24 + 8) + 16))(*(_DWORD *)(*(_DWORD *)off_10CF24
                                                                                                 + 4));
  if ( !v6 )
  {
LABEL_59:
    log_printf(dword_10CFD4, a1[2], a1[4]);
    return j_buffer_pool_get(a1);
  }
  if ( !*((_DWORD *)off_10CF10 + 2057) )
  {
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(_DWORD *)off_10CFD8 = 1;
    }
    v46 = (int *)off_10CFDC;
    ++*(_DWORD *)off_10CFDC;
    ((void (*)(void))phy_reg_init_n_2c4)();
    if ( *v46 )
    {
      v48 = *v46 - 1;
      v47 = *(_DWORD *)off_10CFD8;
      *v46 = v48;
      if ( !v48 )
      {
        if ( v47 )
          __enable_irq();
      }
    }
    v51 = list_count_d594(dword_10CFE0, v47);
    v50 = list_count_d594(dword_10CFE4, v49);
    log_printf(dword_10CFE8, v51, v50);
    return j_buffer_pool_get(a1);
  }
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_10CF18 = 1;
  }
  v37 = (int *)off_10CF1C;
  v38 = dword_10CF2C;
  ++*(_DWORD *)off_10CF1C;
  v7 = sub_12D4F8(v38);
  if ( *v37 )
  {
    v39 = *v37 - 1;
    v40 = *(_DWORD *)off_10CF18;
    *v37 = v39;
    if ( !v39 )
    {
      if ( v40 )
        __enable_irq();
    }
  }
  *(_WORD *)v6 = a1[5] + 12;
  *(_BYTE *)(v6 + 2) = 17;
  *(_BYTE *)(v6 + 3) = 0;
  v5 = v6 + 4;
LABEL_6:
  v8 = a1[5];
  *(_WORD *)v5 = a1[2];
  *(_WORD *)(v5 + 6) = v8;
  if ( v8 )
  {
    if ( **(__int16 **)off_10CF00 < 0 && v8 > 0x400 )
    {
      sub_12F694(dword_10CF34, dword_10CF30, 1671);
      v8 = a1[5];
    }
    sub_14380C(v5 + 12, a1 + 6, v8);
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
      v15 = off_10CF10;
      v16 = *((unsigned __int16 *)off_10CF10 + 4122);
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
      v19 = (int *)off_10CF14;
      *(_WORD *)(v7 + 12) = v16;
      v20 = *v19;
      v21 = v12 + 16;
      v22 = v20 + v18;
      *(_DWORD *)(v22 + 4) = v6;
      *(_WORD *)(v20 + v18) = v14 + v21;
      *(_BYTE *)(v22 + 3) = *(_BYTE *)(v20 + v18 + 3) & 0x31 | 4;
      v23 = v15[3074];
      *((_WORD *)v15 + 4122) = v17;
      v15[3074] = v23 + 1;
      *(_DWORD *)(v7 + 4) = v20 + v18;
      *(_DWORD *)(v7 + 8) = v21 + v13;
      *(_BYTE *)(v7 + 14) = 1;
      *(_DWORD *)v7 = 0;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(_DWORD *)off_10CF18 = 1;
      }
      v24 = (int *)off_10CF1C;
      v25 = dword_10CF20;
      ++*(_DWORD *)off_10CF1C;
      v26 = list_push_tail(v25);
      phy_reg_init_n_2c4(v26);
      if ( *v24 )
      {
        v27 = *v24 - 1;
        v28 = *(_DWORD *)off_10CF18;
        *v24 = v27;
        if ( !v27 )
        {
          if ( v28 )
            __enable_irq();
        }
      }
      if ( **v1 != 1 )
        return j_buffer_pool_get(a1);
      goto LABEL_27;
    }
  }
  else
  {
    v9 = **v1;
    if ( v9 != 3 )
      goto LABEL_8;
  }
  v10 = off_10CF04;
  while ( !*(_DWORD *)off_10CF04 )
    ;
  list_push_tail(*(_DWORD *)off_10CF08 + 524);
  v11 = off_10CF0C;
  *v10 = 1;
  *v11 = 2;
  v9 = **v1;
  if ( v9 == 2 )
    goto LABEL_16;
LABEL_9:
  if ( v9 != 1 )
    return j_buffer_pool_get(a1);
LABEL_27:
  v29 = (int *)log_free_dispatch_n2b4();
  if ( !v29 )
  {
    log_printf(dword_10CFEC, v30, v31);
    return j_buffer_pool_get(a1);
  }
  *(_WORD *)v6 = a1[5] + 12;
  *(_BYTE *)(v6 + 2) = 17;
  *(_BYTE *)(v6 + 3) = 0;
  v32 = a1[5];
  v29[1] = 0;
  *v29 = v6;
  v29[2] = (unsigned __int16)(v32 + 16) | 0x80000000;
  log_queue_push();
  return j_buffer_pool_get(a1);
}

