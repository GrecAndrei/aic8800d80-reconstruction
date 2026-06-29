// sub_116EC4 @ 0x116ec4, size 312 bytes
int  sub_116EC4(int a1, int a2, int a3, int a4)
{
  uint32_t *v4; // r7
  uint8_t *v5; // r9
  int v6; // r8
  int v7; // r6
  int i; // r5
  int v9; // r3
  int result; // r0
  int v11; // r4
  int v12; // r1
  int v13; // r2
  void ( *v14)(uint32_t); // r2
  uint32_t *v15; // r5
  int v16; // [sp+14h] [bp-8h]

  v4 = off_116FFC;
  v5 = off_117014;
  v6 = dword_117020;
  v7 = a1;
  for ( i = 0; ; ++i )
  {
    v11 = sub_11798C(a1, a2, a3, a4);
    *v4 = 0x10000;
    result = sub_11E628(0x400000);
    if ( !v11 )
      break;
    if ( !v7 )
    {
      v9 = (unsigned __int8)v5[192];
      if ( v5[192] )
      {
        v9 = *(uint32_t *)off_117000;
        if ( *(uint32_t *)off_117000 > 0x400000u || i > 31 )
          return irq_nesting_or(0x400000);
      }
      else if ( i > 3 )
      {
        return irq_nesting_or(0x400000);
      }
    }
    result = sub_121A68(result, v12, v13, v9);
    if ( !result )
      return result;
    if ( *(uint32_t *)(v11 + 20) != v6 )
      msg_parse(dword_117008, v11);
    sub_1179C8(v11);
    a1 = sub_116858(v11);
    if ( a1 )
    {
      if ( a1 == 1 )
        a1 = rf_table_lookup_handler(v11);
    }
    else
    {
      a1 = sub_117590(v11);
    }
    a4 = **(unsigned __int8 **)off_11700C;
    switch ( a4 )
    {
      case 2:
LABEL_22:
        a1 = sub_116E24();
        continue;
      case 4:
        if ( !*(uint32_t *)off_117010 || *(uint32_t *)(*(uint32_t *)off_117010 + 12) != v11 || (*(uint8_t *)(v11 + 16) & 1) == 0 )
          goto LABEL_22;
        v16 = *(uint32_t *)off_117010;
        sub_11E7AC(off_117010);
        v14 = *(void ( **)(uint32_t))(v16 + 4);
        *(uint8_t *)(v16 + 16) = 0;
        if ( v14 )
          v14(*(uint32_t *)(v16 + 8));
        a1 = sub_1174EC(v11);
        break;
      case 3:
        a1 = sub_116D98();
        break;
    }
  }
  if ( *((uint8_t *)off_117014 + 192) )
  {
    v15 = off_117018;
    if ( *((uint8_t *)off_117018 + 33) )
    {
      result = sub_110AB8(*((uint32_t *)off_117018 + 4), *((uint32_t *)off_117018 + 5), *((uint32_t *)off_117018 + 6));
      v15[5] = 0;
      v15[7] = 0;
      v15[4] = 0;
      v15[6] = 0;
      *((uint8_t *)v15 + 33) = 0;
    }
  }
  *(uint32_t *)off_11701C |= 0x10000u;
  return result;
}

