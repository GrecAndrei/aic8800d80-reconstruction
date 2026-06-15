// sub_12788C @ 0x12788c, size 526 bytes
int __fastcall sub_12788C(int a1)
{
  __int16 **v1; // r7
  _BYTE *v2; // r6
  int v4; // r0
  int v5; // r5
  int v6; // r3
  _DWORD *v7; // r4
  int v8; // r3
  int v9; // r2
  int v10; // r3
  int v11; // r2
  char *v12; // r0
  int v13; // r0
  int result; // r0
  int *v15; // r5
  int v16; // r1
  int v17; // r6
  int v18; // r3
  int v19; // r2
  int *v20; // r3
  int v21; // r3
  int v22; // r1
  int v23; // r2
  int v24; // r3
  int v25; // r7
  int v26; // r3
  int v27; // r3
  unsigned int v28; // r8
  _DWORD *v29; // r2
  _DWORD *v30; // r7
  int v31; // r1
  int v32; // r0
  int v33; // r3
  int *v34; // r3
  int v35; // r3
  _DWORD *v36; // r2
  int v37; // r3
  int v38; // r2

  v1 = (__int16 **)off_127A9C;
  v2 = off_127AA0;
  v4 = sub_12D4F8(dword_127AA4);
  v5 = v4;
  if ( **v1 >= 0 )
  {
    v6 = (unsigned __int8)*v2;
    if ( *v2 )
    {
LABEL_3:
      v7 = off_127AA8;
      goto LABEL_4;
    }
    goto LABEL_25;
  }
  if ( a1 == v4 )
  {
    v6 = (unsigned __int8)*v2;
    if ( *v2 )
      goto LABEL_3;
  }
  else
  {
    sub_12F694(dword_127AD8, dword_127AD4, 1958);
    v6 = (unsigned __int8)*v2;
    if ( *v2 )
      goto LABEL_3;
    if ( **v1 >= 0 )
    {
LABEL_25:
      v7 = off_127AA8;
      goto LABEL_5;
    }
  }
  v7 = off_127AA8;
  v8 = *((_DWORD *)off_127AA8 + 10);
  if ( v8 )
    goto LABEL_6;
  sub_12F694(dword_127ADC, dword_127AD4, 1960);
  v6 = (unsigned __int8)*v2;
LABEL_4:
  if ( v6 != 1 )
  {
LABEL_5:
    v8 = v7[10];
    goto LABEL_6;
  }
  sub_12ECB0(dword_127AC0, *((unsigned __int8 *)v7 + 88), v7[11]);
  v24 = *((unsigned __int8 *)v7 + 88);
  if ( (v24 & 8) != 0 )
  {
    v25 = dword_127AE0;
  }
  else
  {
    v22 = v24 << 29;
    if ( (v24 & 4) == 0 )
    {
      v25 = v7[11];
      if ( !v25 )
        goto LABEL_5;
      goto LABEL_32;
    }
    v25 = dword_127AC4;
  }
  v26 = v7[11];
  if ( v26 != v25 && v26 )
  {
    v23 = 1;
    *(_BYTE *)(v26 + 16) = 1;
  }
LABEL_32:
  v27 = v7[10];
  if ( v27 )
  {
    v23 = 1;
    *(_BYTE *)(v27 + 16) = 1;
  }
  v7[10] = v25;
  v7[11] = 0;
  v28 = *(unsigned __int8 *)(v25 + 24);
  *(_BYTE *)(v25 + 16) = 4;
  if ( v28 == 3 )
  {
    sub_12ECB0(dword_127AE8, v22, v23);
    rf_bus_mark_n_3b7(2);
    v28 = *(unsigned __int8 *)(v25 + 24);
  }
  if ( v28 <= 2 )
    goto LABEL_5;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_127AB4 = 1;
  }
  v29 = off_127ABC;
  v30 = off_127AC8;
  v31 = *(_DWORD *)off_127ABC;
  v32 = *(_DWORD *)off_127ABC + 1;
  v33 = *((_DWORD *)off_127AC8 + 1) | 2;
  *(_DWORD *)off_127ABC = v32;
  v30[1] = v33;
  if ( v32 )
  {
    v34 = (int *)off_127AB4;
    *v29 = v31;
    v35 = *v34;
    if ( !v31 )
    {
      if ( v35 )
        __enable_irq();
    }
  }
  v36 = off_127ACC;
  v8 = v7[10];
  *((_BYTE *)v7 + 92) = (*(_DWORD *)off_127ACC & 4) != 0;
  *v36 &= ~4u;
LABEL_6:
  *(_BYTE *)(v8 + 16) = 1;
  v9 = v7[20];
  v10 = 0;
  *v2 = 0;
  if ( v9 )
  {
    v11 = *((unsigned __int8 *)v7 + 90);
    v7[20] = 0;
    if ( !v11 )
    {
      *(_DWORD *)(v5 + 8) = 0;
      goto LABEL_14;
    }
    if ( v11 == 1 || (v10 = v7[4]) == 0 )
    {
      v12 = (char *)off_127AE4;
      if ( *((unsigned __int8 *)off_127AE4 + 24) == 255 )
      {
        if ( *((unsigned __int8 *)off_127AE4 + 52) == 255 )
        {
          if ( *((unsigned __int8 *)off_127AE4 + 80) == 255 )
          {
            *(_DWORD *)(v5 + 8) = v10;
            goto LABEL_14;
          }
          v12 = (char *)off_127AE4 + 56;
        }
        else
        {
          v12 = (char *)off_127AE4 + 28;
        }
      }
    }
    else
    {
      v12 = *(char **)(dword_127AAC + 1320 * *(unsigned __int8 *)(v10 + 8) + 72);
    }
    *(_DWORD *)(v5 + 8) = v12;
  }
  else
  {
    v12 = *(char **)(v5 + 8);
  }
  if ( v12 )
    sub_1272F0((int)v12);
LABEL_14:
  list_push_tail(dword_127AB0);
  v13 = v7[10];
  if ( *(unsigned __int8 *)(v13 + 24) > 2u )
    sub_1275A0(v13, 0);
  result = v7[8];
  v7[18] = result;
  if ( result )
  {
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(_DWORD *)off_127AB4 = 1;
    }
    v15 = (int *)off_127ABC;
    v16 = *(_DWORD *)(result + 4);
    v17 = *(_DWORD *)off_127ABC;
    v18 = v16 - *((_DWORD *)off_127AB8 + 4);
    v19 = *(_DWORD *)off_127ABC + 1;
    *(_DWORD *)off_127ABC = v19;
    if ( v18 - 64 >= 0 )
    {
      result = timestamp_update_4f60(dword_127AD0, v16);
      if ( *v15 )
      {
        v37 = *v15 - 1;
        v38 = *(_DWORD *)off_127AB4;
        *v15 = v37;
        if ( !v37 )
        {
          if ( v38 )
            __enable_irq();
        }
      }
    }
    else
    {
      if ( v19 )
      {
        v20 = (int *)off_127AB4;
        *v15 = v17;
        v21 = *v20;
        if ( !v17 )
        {
          if ( v21 )
            __enable_irq();
        }
      }
      return ((int (*)(void))v7[17])();
    }
  }
  return result;
}

