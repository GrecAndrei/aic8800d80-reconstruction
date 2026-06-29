// fwstruct annotate: 10f550_sub_10F550.c
// sub_10F550 @ 0x10f550, size 740 bytes
int sub_10F550()
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

  result = clear_flags(512);
  v26 = *((int **)off_10F834 + 2);
  if ( !v26 )
    return result;
  v1 = (int *)off_10F860;
  while ( 2 )
  {
    result = scan_chan_setup_n134(v26);
    if ( !result && *((_BYTE *)v26 + 108) )
      goto LABEL_4;
    for ( ; v26[328]; result = sub_13ABA8(v2, 3, v3) )
    {
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(_DWORD *)off_10F838 = 1;
      }
      ++*v1;
      v2 = rf_bus_mark_n100_d2d0(v26 + 328);
      v3 = *v1 - 1;
      if ( *v1 )
      {
        v4 = (int *)off_10F838;
        *v1 = v3;
        v5 = *v4;
        if ( !v3 )
        {
          if ( v5 )
            __enable_irq();
        }
      }
    }
    if ( *((_BYTE *)off_10F83C + 511) )
      goto LABEL_4;
    v6 = v26;
    v7 = (__int16 **)off_10F840;
    v8 = dword_10F844;
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
          v11 = rf_bus_mark_n100_d2d0(v6 + 326);
          v12 = *(unsigned __int8 *)(v11 + 29);
          v13 = v11;
          if ( **v7 < 0 && v12 > 0x1F )
          {
            sub_12F46C(dword_10F854, dword_10F850, 374);
            v12 = *(unsigned __int8 *)(v13 + 29);
          }
          v14 = v8 + 696 * v12;
          if ( !*(_BYTE *)(v14 + 37) && (*(_WORD *)(v13 + 30) & 8) == 0 )
            break;
          v15 = *(unsigned __int8 *)(v8 + 696 * v12 + 36);
          if ( v15 != 1 )
          {
            sub_13ABA8(v13, v10, v15);
            goto LABEL_24;
          }
          if ( **v7 < 0 )
          {
            if ( (*(_WORD *)(v13 + 30) & 1) != 0 )
            {
LABEL_54:
              list_push_tail(v8 + 8 * (87 * (__int16)v12 + v25 + 78));
              goto LABEL_23;
            }
            sub_12F46C(dword_10F85C, dword_10F850, 383);
          }
          if ( (*(_WORD *)(v13 + 30) & 1) != 0 )
            goto LABEL_54;
LABEL_23:
          msg_parse(dword_10F848, *(unsigned __int8 *)(v8 + 696 * v12 + 35), 696);
LABEL_24:
          if ( !v6[326] )
            goto LABEL_25;
        }
        msg_parse(dword_10F858, *(unsigned __int8 *)(v14 + 35), v14);
        sub_13AAF4(v13, v10, 0x80000000);
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
          msg_parse(dword_10F858, v18[35], v18[37]);
          v24 = rf_bus_mark_n100_d2d0(v6 + 316);
          sub_13AAF4(v24, v10, 0x80000000);
          v16 = v6[316];
          if ( !v16 )
            goto LABEL_37;
        }
        if ( v18[36] == 1 )
        {
          if ( (__get_CPSR() & 1) == 0 )
          {
            __disable_irq();
            *(_DWORD *)off_10F838 = 1;
          }
          ++*v1;
          rf_bus_mark_n100_d2d0(v6 + 316);
          msg_parse(dword_10F84C, *(unsigned __int8 *)(v8 + 696 * v17 + 35), v8 + 696 * v17);
          if ( *v1 )
          {
            v19 = *v1 - 1;
            v20 = *(_DWORD *)off_10F838;
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
        if ( sub_13C0A4(v17, *(unsigned __int8 *)(v16 + 27)) )
        {
          if ( (__get_CPSR() & 1) == 0 )
          {
            __disable_irq();
            *(_DWORD *)off_10F838 = 1;
          }
          ++*v1;
          v21 = rf_bus_mark_n100_d2d0(v6 + 316);
          if ( *v1 )
          {
            v23 = *v1 - 1;
            v22 = *(_DWORD *)off_10F838;
            *v1 = v23;
            if ( !v23 )
            {
              if ( v22 )
                __enable_irq();
            }
          }
          sub_13ABA8(v21, v10, v22);
LABEL_36:
          v16 = v6[316];
          if ( !v16 )
            goto LABEL_37;
          continue;
        }
        break;
      }
      *((_BYTE *)off_10F83C + 512) = 1;
LABEL_37:
      --v9;
      result = sub_11A7E8(v10);
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

