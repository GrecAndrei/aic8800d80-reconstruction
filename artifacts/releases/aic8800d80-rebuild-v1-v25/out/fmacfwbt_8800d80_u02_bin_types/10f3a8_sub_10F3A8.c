// sub_10F3A8 @ 0x10f3a8, size 740 bytes
int sub_10F3A8()
{
  int result; // r0
  int *v1; // r9
  int v2; // r0
  int v3; // r2
  int *v4; // r3
  int v5; // r3
  int *v6; // r11
  __int16 **v7; // r6
  int v8; // r5
  int v9; // r8
  int v10; // r7
  int v11; // r0
  unsigned int v12; // r8
  int v13; // r4
  unsigned int v14; // r2
  int v15; // r2
  int v16; // r1
  int v17; // r10
  unsigned __int8 *v18; // r3
  int v19; // r2
  int v20; // r1
  int v21; // r0
  int v22; // r2
  int v23; // r3
  int v24; // r0
  int v25; // [sp+0h] [bp-Ch]
  int *v26; // [sp+4h] [bp-8h]

  result = sub_12D374(512);
  v26 = *((int **)off_10F68C + 2);
  if ( !v26 )
    return result;
  v1 = (int *)off_10F6B8;
  while ( 2 )
  {
    result = bt_sub_121733C(v26);
    if ( !result && *((uint8_t *)v26 + 108) )
      goto LABEL_4;
    for ( ; v26[328]; result = sub_13AC44(v2, 3, v3) )
    {
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(uint32_t *)off_10F690 = 1;
      }
      ++*v1;
      v2 = sub_12D4F8(v26 + 328);
      v3 = *v1 - 1;
      if ( *v1 )
      {
        v4 = (int *)off_10F690;
        *v1 = v3;
        v5 = *v4;
        if ( !v3 )
        {
          if ( v5 )
            __enable_irq();
        }
      }
    }
    if ( *((uint8_t *)off_10F694 + 511) )
      goto LABEL_4;
    v6 = v26;
    v7 = (__int16 **)off_10F698;
    v8 = dword_10F69C;
    v9 = 4;
    if ( !v26[326] )
    {
LABEL_39:
      v10 = (unsigned __int8)v9;
      goto LABEL_26;
    }
    while ( 2 )
    {
      v10 = (unsigned __int8)v9;
      v25 = v9;
      do
      {
        while ( 1 )
        {
          v11 = sub_12D4F8(v6 + 326);
          v12 = *(unsigned __int8 *)(v11 + 29);
          v13 = v11;
          if ( **v7 < 0 && v12 > 0x1F )
          {
            sub_12F694(dword_10F6AC, dword_10F6A8, 374);
            v12 = *(unsigned __int8 *)(v13 + 29);
          }
          v14 = v8 + 696 * v12;
          if ( !*(uint8_t *)(v14 + 37) && (*(uint16_t *)(v13 + 30) & 8) == 0 )
            break;
          v15 = *(unsigned __int8 *)(v8 + 696 * v12 + 36);
          if ( v15 != 1 )
          {
            sub_13AC44(v13, v10, v15);
            goto LABEL_24;
          }
          if ( **v7 < 0 )
          {
            if ( (*(uint16_t *)(v13 + 30) & 1) != 0 )
            {
LABEL_54:
              list_push_tail(v8 + 8 * (87 * (__int16)v12 + v25 + 78));
              goto LABEL_23;
            }
            sub_12F694(dword_10F6B4, dword_10F6A8, 383);
          }
          if ( (*(uint16_t *)(v13 + 30) & 1) != 0 )
            goto LABEL_54;
LABEL_23:
          sub_12ECB0(dword_10F6A0, *(unsigned __int8 *)(v8 + 696 * v12 + 35), 696);
LABEL_24:
          if ( !v6[326] )
            goto LABEL_25;
        }
        sub_12ECB0(dword_10F6B0, *(unsigned __int8 *)(v14 + 35), v14);
        sub_13AB90(v13, v10, 0x80000000);
      }
      while ( v6[326] );
LABEL_25:
      v9 = v25;
LABEL_26:
      v16 = v6[316];
      if ( !v16 )
        goto LABEL_37;
      while ( 2 )
      {
        while ( 1 )
        {
          v17 = *(unsigned __int8 *)(v16 + 29);
          v18 = (unsigned __int8 *)(v8 + 696 * v17);
          if ( v18[37] )
            break;
          sub_12ECB0(dword_10F6B0, v18[35], v18[37]);
          v24 = sub_12D4F8(v6 + 316);
          sub_13AB90(v24, v10, 0x80000000);
          v16 = v6[316];
          if ( !v16 )
            goto LABEL_37;
        }
        if ( v18[36] == 1 )
        {
          if ( (__get_CPSR() & 1) == 0 )
          {
            __disable_irq();
            *(uint32_t *)off_10F690 = 1;
          }
          ++*v1;
          sub_12D4F8(v6 + 316);
          sub_12ECB0(dword_10F6A4, *(unsigned __int8 *)(v8 + 696 * v17 + 35), v8 + 696 * v17);
          if ( *v1 )
          {
            v19 = *v1 - 1;
            v20 = *(uint32_t *)off_10F690;
            *v1 = v19;
            if ( !v19 )
            {
              if ( v20 )
                __enable_irq();
            }
          }
          list_push_tail(v8 + 8 * (87 * (__int16)v17 + v9 + 73));
          goto LABEL_36;
        }
        if ( sub_13C140(v17, *(unsigned __int8 *)(v16 + 27)) )
        {
          if ( (__get_CPSR() & 1) == 0 )
          {
            __disable_irq();
            *(uint32_t *)off_10F690 = 1;
          }
          ++*v1;
          v21 = sub_12D4F8(v6 + 316);
          if ( *v1 )
          {
            v23 = *v1 - 1;
            v22 = *(uint32_t *)off_10F690;
            *v1 = v23;
            if ( !v23 )
            {
              if ( v22 )
                __enable_irq();
            }
          }
          sub_13AC44(v21, v10, v22);
LABEL_36:
          v16 = v6[316];
          if ( !v16 )
            goto LABEL_37;
          continue;
        }
        break;
      }
      *((uint8_t *)off_10F694 + 512) = 1;
LABEL_37:
      --v9;
      result = sub_11AC28(v10);
      v6 -= 2;
      if ( v9 != -1 )
      {
        if ( v6[326] )
          continue;
        goto LABEL_39;
      }
      break;
    }
LABEL_4:
    v26 = (int *)*v26;
    if ( v26 )
      continue;
    return result;
  }
}

