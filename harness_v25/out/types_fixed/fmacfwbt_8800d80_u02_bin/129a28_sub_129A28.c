// sub_129A28 @ 0x129a28, size 1100 bytes
// Doc: sub_1229A28 [unknown]: Dispatches handler based on state byte at offset 0x10 of argument
// sub_1229A28 [unknown]: Dispatches handler based on state byte at offset 0x10 of argument
unsigned __int8 *__fastcall sub_129A28(unsigned __int8 *result)
{
  unsigned __int8 *v1; // r4
  int v2; // r9
  int v3; // r3
  int v4; // r10
  int v5; // r8
  _BYTE *v6; // r0
  unsigned int v7; // r3
  int v8; // r1
  int v9; // r5
  int v10; // r6
  _BYTE *v11; // r0
  int v12; // r3
  int v13; // r3
  _WORD *v14; // r0
  int v15; // r7
  int v16; // r1
  int v17; // r5
  int v18; // r6
  int v19; // r4
  _DWORD *v20; // r2
  int v21; // r11
  int v22; // r5
  int v23; // r3
  int v24; // r0
  _DWORD *v25; // r3
  int v26; // r3
  int v27; // r0
  int v28; // r2
  int v29; // r8
  int v30; // r1
  int *v31; // r5
  int v32; // r3
  int v33; // r2
  unsigned __int8 *v34; // [sp+4h] [bp-8h]

  v1 = result;
  if ( *(_DWORD *)(result + 0x40) != 2 )
  {
    if ( *(_DWORD *)(result + 0x100) != 2 )
      goto LABEL_3;
    if ( !*(_DWORD *)(result + 0x21c) )
    {
      v7 = 255;
      goto LABEL_36;
    }
    goto LABEL_17;
  }
  if ( !*(_DWORD *)(result + 0x21c) )
  {
    v7 = *(_DWORD *)(result + 0x50);
    if ( *(_DWORD *)(result + 0x100) != 2 )
      goto LABEL_26;
    goto LABEL_36;
  }
  if ( *(_DWORD *)(result + 0x84) && *(_DWORD *)(result + 0x80) == 1 )
  {
    if ( *(_DWORD *)(result + 0x100) != 2 )
      goto LABEL_3;
LABEL_17:
    v7 = 255;
    v8 = 0;
    goto LABEL_18;
  }
  v7 = *(_DWORD *)(result + 0x50);
  if ( *(_DWORD *)(result + 0x100) != 2 )
    goto LABEL_26;
  v8 = 1;
LABEL_18:
  if ( !*(_DWORD *)(result + 0x144) || *(_DWORD *)(result + 0x140) != 1 )
  {
LABEL_36:
    if ( v7 >= *(_DWORD *)(result + 0x110) )
      v7 = *(_DWORD *)(result + 0x110);
LABEL_26:
    if ( v7 != 1 )
    {
      v2 = *(_DWORD *)(result + 0x218);
      if ( *(_DWORD *)(result + 0x218) )
      {
        if ( *(_DWORD *)(result + 0x214) == 1 )
          return result;
        v5 = *(_DWORD *)(result + 0x1c4);
        v4 = dword_129D80;
        v2 = 1;
        goto LABEL_42;
      }
      v9 = *(_DWORD *)(result + 0x1c8);
      v10 = v9 == 1;
      if ( *(_DWORD *)(result + 0x214) == v10 )
      {
        if ( !*(_DWORD *)(result + 0x1c0) && v9 == 1 )
          goto LABEL_7;
        return result;
      }
      v5 = *(_DWORD *)(result + 0x1c4);
      v4 = dword_129D80;
      v11 = (_BYTE *)rf_bus_setup_n3a8(77, 13, *(_DWORD *)(result + 0x218), 2);
      *v11 = *(_DWORD *)(v1 + 0x1c4);
      *(_DWORD *)(v11 + 0x4) = v9 != 1;
      sub_12CBB4(v11);
      *(_DWORD *)(v1 + 0x214) = v10;
      result = (unsigned __int8 *)nullsub_5(*(_DWORD *)(v4 + 1320 * v5 + 72), v9 != 1);
      if ( v9 == 1 )
      {
LABEL_43:
        if ( *(_DWORD *)(v1 + 0x1c0) )
        {
          result = (unsigned __int8 *)irq_nesting_or(512);
          v28 = *(_DWORD *)(v1 + 0x1c0);
        }
        else
        {
          v15 = v4 + 1320 * v5;
          v16 = *(unsigned __int8 *)(v15 + 116);
          if ( v16 == 255 )
          {
            if ( *(_BYTE *)(v15 + 106) == 2 )
            {
              *(_DWORD *)(v15 + 4) |= 0x20u;
              if ( !v2 )
                return (unsigned __int8 *)sub_12054C(v4 + 1320 * *(_DWORD *)(v1 + 0x1c4));
              return result;
            }
            goto LABEL_59;
          }
          v17 = dword_129D74;
          v34 = v1;
          v18 = dword_129D74 + 696 * v16;
          v19 = v4 + 8 * (165 * v5 + 159);
          v20 = off_129D78;
          v21 = 696 * v16 + dword_129D74 + 664;
          *(_BYTE *)(v18 + 36) = 0;
          v22 = v17 + 8 * (87 * (__int16)v16 + 78);
          do
          {
            if ( *(_DWORD *)(v18 + 584) )
            {
              if ( (__get_CPSR() & 1) == 0 )
              {
                __disable_irq();
                *(_DWORD *)off_129D7C = 1;
              }
              ++*v20;
              sub_12D658(v22 - 40, v19 - 40);
              v23 = *(_DWORD *)(v18 + 588);
              *(_DWORD *)(v15 + 1232) = *(_DWORD *)(v18 + 584);
              *(_DWORD *)(v15 + 1236) = v23;
              bt_xtal_init_check(v22 - 40);
              v20 = off_129D78;
              v24 = *(_DWORD *)off_129D78 - 1;
              if ( *(_DWORD *)off_129D78 )
              {
                v25 = off_129D7C;
                *(_DWORD *)off_129D78 = v24;
                if ( !v24 )
                {
                  if ( *v25 )
                    __enable_irq();
                }
              }
            }
            v26 = *(_DWORD *)(v18 + 624);
            v27 = v19;
            v18 += 8;
            v19 += 8;
            v15 += 8;
            if ( v26 )
            {
              sub_12D658(v27, v22);
              bt_xtal_init_check(v22);
              v20 = off_129D78;
            }
            v22 += 8;
          }
          while ( v22 != v21 );
          v1 = v34;
          result = (unsigned __int8 *)irq_nesting_or(512);
          v28 = *(_DWORD *)(v34 + 0x1c0);
        }
        v29 = v4 + 1320 * v5;
        if ( *(_BYTE *)(v29 + 106) == 2 )
        {
          *(_DWORD *)(v29 + 4) |= 0x20u;
          if ( v28 )
            return result;
        }
        else if ( v28 )
        {
          return result;
        }
LABEL_59:
        if ( !v2 )
          return (unsigned __int8 *)sub_12054C(v4 + 1320 * *(_DWORD *)(v1 + 0x1c4));
        return result;
      }
LABEL_30:
      v12 = v4 + 1320 * v5;
      if ( *(_BYTE *)(v12 + 106) == 2 )
      {
        v30 = *((_DWORD *)off_129E74 + 1);
        *(_DWORD *)(v12 + 4) &= ~0x20u;
        if ( v30 > 0 )
        {
          if ( (__get_CPSR() & 1) == 0 )
          {
            __disable_irq();
            *(_DWORD *)off_129E78 = 1;
          }
          v31 = (int *)off_129E7C;
          ++*(_DWORD *)off_129E7C;
          patch_sub_1217374(4);
          result = (unsigned __int8 *)sub_1178DC(4);
          if ( *v31 )
          {
            v32 = *v31 - 1;
            v33 = *(_DWORD *)off_129E78;
            *v31 = v32;
            if ( !v32 )
            {
              if ( v33 )
                __enable_irq();
            }
          }
        }
      }
      if ( !*(_DWORD *)(v1 + 0x1c0) )
      {
        v13 = *(unsigned __int8 *)(v4 + 1320 * v5 + 116);
        if ( v13 != 255 )
          *(_BYTE *)(dword_129D74 + 696 * v13 + 36) = 1;
      }
      return result;
    }
    goto LABEL_13;
  }
  if ( v8 )
    goto LABEL_26;
LABEL_3:
  v2 = *(_DWORD *)(result + 0x1cc);
  if ( !*(_DWORD *)(result + 0x1cc) )
  {
    if ( *(_DWORD *)(result + 0x214) == 1 )
    {
LABEL_5:
      v3 = *(_DWORD *)(result + 0x1c0);
      goto LABEL_6;
    }
    goto LABEL_41;
  }
  if ( *(_DWORD *)(result + 0x1c8) == 1 )
  {
    if ( *(_DWORD *)(result + 0x214) == 1 )
      goto LABEL_5;
    goto LABEL_62;
  }
  v3 = *(_DWORD *)(result + 0x1c0);
  if ( v3 == 1 )
  {
    v5 = *(_DWORD *)(result + 0x1c4);
    v4 = dword_129E80;
    if ( *(unsigned __int8 *)(dword_129E80 + 1320 * v5 + 234) != *(unsigned __int8 *)(dword_129E80 + 1320 * v5 + 1226) )
    {
      if ( *(_DWORD *)(result + 0x214) == 1 )
        return result;
      v2 = 0;
      goto LABEL_42;
    }
    if ( !*(_DWORD *)(result + 0x214) )
      return result;
    goto LABEL_15;
  }
  v2 = *(unsigned __int8 *)off_129D70;
  if ( *(_BYTE *)off_129D70 )
  {
    if ( (*((_DWORD *)off_129D70 + 1) & 8) == 0 )
    {
LABEL_13:
      if ( !*(_DWORD *)(result + 0x214) )
        return result;
      v5 = *(_DWORD *)(result + 0x1c4);
      v4 = dword_129D80;
LABEL_15:
      v6 = (_BYTE *)rf_bus_setup_n3a8(77, 13, 0, 2);
      *v6 = *(_DWORD *)(v1 + 0x1c4);
      *(_DWORD *)(v6 + 0x4) = 1;
      sub_12CBB4(v6);
      *(_DWORD *)(v1 + 0x214) = 0;
      result = (unsigned __int8 *)nullsub_5(*(_DWORD *)(v4 + 1320 * v5 + 72), 1);
      goto LABEL_30;
    }
    if ( *(_DWORD *)(result + 0x214) == 1 )
    {
      if ( !*(_DWORD *)(result + 0x1c0) )
        goto LABEL_7;
      return result;
    }
LABEL_62:
    v5 = *(_DWORD *)(result + 0x1c4);
    v4 = dword_129D80;
    v2 = 0;
    goto LABEL_42;
  }
  if ( *(_DWORD *)(result + 0x214) != 1 )
  {
LABEL_41:
    v5 = *(_DWORD *)(result + 0x1c4);
    v4 = dword_129D80;
LABEL_42:
    v14 = (_WORD *)rf_bus_setup_n3a8(77, 13, 0, 2);
    *v14 = *(_DWORD *)(v1 + 0x1c4);
    sub_12CBB4(v14);
    *(_DWORD *)(v1 + 0x214) = 1;
    result = (unsigned __int8 *)nullsub_5(*(_DWORD *)(v4 + 1320 * v5 + 72), 0);
    goto LABEL_43;
  }
LABEL_6:
  if ( !v3 )
  {
LABEL_7:
    v4 = dword_129D80;
    return (unsigned __int8 *)sub_12054C(v4 + 1320 * *(_DWORD *)(v1 + 0x1c4));
  }
  return result;
}

