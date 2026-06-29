// sub_127668 @ 0x127668, size 526 bytes
int  sub_127668(int a1)
{
  __int16 **v1; // r7
  uint8_t *v2; // r6
  int v4; // r0
  int v5; // r5
  int v6; // r3
  uint32_t *v7; // r4
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
  uint32_t *v29; // r2
  uint32_t *v30; // r7
  int v31; // r1
  int v32; // r0
  int v33; // r3
  int *v34; // r3
  int v35; // r3
  uint32_t *v36; // r2
  int v37; // r3
  int v38; // r2

  v1 = (__int16 **)off_127878;
  v2 = off_12787C;
  v4 = rf_bus_mark_n100_d2d0(dword_127880);
  v5 = v4;
  if ( **v1 >= 0 )
  {
    v6 = (unsigned __int8)*v2;
    if ( *v2 )
    {
LABEL_3:
      v7 = off_127884;
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
    sub_12F46C(dword_1278B4, dword_1278B0, 1958);
    v6 = (unsigned __int8)*v2;
    if ( *v2 )
      goto LABEL_3;
    if ( **v1 >= 0 )
    {
LABEL_25:
      v7 = off_127884;
      goto LABEL_5;
    }
  }
  v7 = off_127884;
  v8 = *((uint32_t *)off_127884 + 10);
  if ( v8 )
    goto LABEL_6;
  sub_12F46C(dword_1278B8, dword_1278B0, 1960);
  v6 = (unsigned __int8)*v2;
LABEL_4:
  if ( v6 != 1 )
  {
LABEL_5:
    v8 = v7[10];
    goto LABEL_6;
  }
  msg_parse(dword_12789C, *((unsigned __int8 *)v7 + 88), v7[11]);
  v24 = *((unsigned __int8 *)v7 + 88);
  if ( (v24 & 8) != 0 )
  {
    v25 = dword_1278BC;
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
    v25 = dword_1278A0;
  }
  v26 = v7[11];
  if ( v26 != v25 && v26 )
  {
    v23 = 1;
    *(uint8_t *)(v26 + 16) = 1;
  }
LABEL_32:
  v27 = v7[10];
  if ( v27 )
  {
    v23 = 1;
    *(uint8_t *)(v27 + 16) = 1;
  }
  v7[10] = v25;
  v7[11] = 0;
  v28 = *(unsigned __int8 *)(v25 + 24);
  *(uint8_t *)(v25 + 16) = 4;
  if ( v28 == 3 )
  {
    msg_parse(dword_1278C4, v22, v23);
    sub_12CD34(2);
    v28 = *(unsigned __int8 *)(v25 + 24);
  }
  if ( v28 <= 2 )
    goto LABEL_5;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_127890 = 1;
  }
  v29 = off_127898;
  v30 = off_1278A4;
  v31 = *(uint32_t *)off_127898;
  v32 = *(uint32_t *)off_127898 + 1;
  v33 = *((uint32_t *)off_1278A4 + 1) | 2;
  *(uint32_t *)off_127898 = v32;
  v30[1] = v33;
  if ( v32 )
  {
    v34 = (int *)off_127890;
    *v29 = v31;
    v35 = *v34;
    if ( !v31 )
    {
      if ( v35 )
        __enable_irq();
    }
  }
  v36 = off_1278A8;
  v8 = v7[10];
  *((uint8_t *)v7 + 92) = (*(uint32_t *)off_1278A8 & 4) != 0;
  *v36 &= ~4u;
LABEL_6:
  *(uint8_t *)(v8 + 16) = 1;
  v9 = v7[20];
  v10 = 0;
  *v2 = 0;
  if ( v9 )
  {
    v11 = *((unsigned __int8 *)v7 + 90);
    v7[20] = 0;
    if ( !v11 )
    {
      *(uint32_t *)(v5 + 8) = 0;
      goto LABEL_14;
    }
    if ( v11 == 1 || (v10 = v7[4]) == 0 )
    {
      v12 = (char *)off_1278C0;
      if ( *((unsigned __int8 *)off_1278C0 + 24) == 255 )
      {
        if ( *((unsigned __int8 *)off_1278C0 + 52) == 255 )
        {
          if ( *((unsigned __int8 *)off_1278C0 + 80) == 255 )
          {
            *(uint32_t *)(v5 + 8) = v10;
            goto LABEL_14;
          }
          v12 = (char *)off_1278C0 + 56;
        }
        else
        {
          v12 = (char *)off_1278C0 + 28;
        }
      }
    }
    else
    {
      v12 = *(char **)(dword_127888 + 1320 * *(unsigned __int8 *)(v10 + 8) + 72);
    }
    *(uint32_t *)(v5 + 8) = v12;
  }
  else
  {
    v12 = *(char **)(v5 + 8);
  }
  if ( v12 )
    sub_1270CC((int)v12);
LABEL_14:
  list_push_tail(dword_12788C);
  v13 = v7[10];
  if ( *(unsigned __int8 *)(v13 + 24) > 2u )
    sub_12737C(v13, 0);
  result = v7[8];
  v7[18] = result;
  if ( result )
  {
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(uint32_t *)off_127890 = 1;
    }
    v15 = (int *)off_127898;
    v16 = *(uint32_t *)(result + 4);
    v17 = *(uint32_t *)off_127898;
    v18 = v16 - *((uint32_t *)off_127894 + 4);
    v19 = *(uint32_t *)off_127898 + 1;
    *(uint32_t *)off_127898 = v19;
    if ( v18 - 64 >= 0 )
    {
      result = timestamp_update(dword_1278AC, v16);
      if ( *v15 )
      {
        v37 = *v15 - 1;
        v38 = *(uint32_t *)off_127890;
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
        v20 = (int *)off_127890;
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

