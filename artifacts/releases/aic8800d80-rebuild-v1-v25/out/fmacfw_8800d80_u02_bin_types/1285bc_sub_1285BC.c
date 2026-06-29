// sub_1285BC @ 0x1285bc, size 664 bytes
int  sub_1285BC(int a1)
{
  __int16 **v1; // r9
  int v2; // r8
  int v3; // r10
  unsigned __int8 *v4; // r6
  int v6; // r5
  char *v7; // r7
  int v8; // r1
  int v9; // r3
  int v10; // r2
  int v11; // r3
  int v12; // r4
  int v13; // r3
  int v14; // r5
  unsigned __int8 *v15; // r3
  int v16; // r0
  int v17; // r3
  char *v18; // r4
  int v19; // r2
  int v20; // r3
  int v22; // r1
  __int16 *v23; // r2
  unsigned int v24; // r3
  int v25; // r3
  uint32_t *v26; // r0
  int v27; // r1
  int v28; // r3
  int v29; // r2
  char *v30; // r1
  int v31; // r0

  v1 = (__int16 **)off_128884;
  v2 = dword_12887C;
  v3 = 1320 * a1;
  v4 = *(unsigned __int8 **)(dword_12887C + 1320 * a1 + 72);
  if ( **(__int16 **)off_128884 < 0 && !v4 )
    sub_12F46C(dword_12886C, dword_128868, 3149);
  v6 = v2 + 1320 * a1;
  v7 = (char *)off_128854;
  feature_guard_check(256, dword_128858);
  sub_12D2E8(v7 + 16, v3 + 76 + v2);
  v9 = *(unsigned __int8 *)(v6 + 85);
  *(uint8_t *)(v6 + 85) = v9 & 0xFE;
  v10 = v9 << 30;
  if ( (v9 & 2) != 0 )
  {
    v11 = (unsigned __int8)(v7[91] - 1);
    v7[91] = v11;
    if ( !v11 && (v7[88] & 0x40) != 0 )
    {
      msg_parse(dword_128864, v8, v10);
      sub_127170(*((uint32_t *)v7 + 20));
    }
  }
  v12 = v2 + 1320 * a1;
  *(uint8_t *)(v12 + 85) = 0;
  *(uint32_t *)(v12 + 72) = 0;
  v13 = v4[16];
  v14 = (unsigned __int8)(v4[25] - 1);
  v4[25] = v14;
  if ( v13 )
  {
    if ( v4[27] == *(unsigned __int8 *)(v12 + 107) )
    {
      sub_125E10(v2 + v3);
      v14 = v4[25];
      v4[27] = -1;
      if ( v14 )
        return sub_128548((int)v4);
    }
    else
    {
      v15 = (unsigned __int8 *)off_12885C;
      while ( 1 )
      {
        if ( v15[24] != 255 )
        {
          v16 = v15[27];
          if ( v16 != 255 )
            break;
        }
        v15 += 28;
        if ( (unsigned __int8 *)((char *)off_12885C + 84) == v15 )
          goto LABEL_10;
      }
      v26 = (uint32_t *)(v2 + 1320 * v16);
      if ( (unsigned __int8 *)v26[18] == v4 )
      {
LABEL_10:
        if ( !v14 )
          goto LABEL_26;
        return sub_128548((int)v4);
      }
      if ( v14 )
      {
        sub_125E78(v26);
        LOBYTE(v14) = v4[25];
        if ( (uint8_t)v14 )
          return sub_128548((int)v4);
      }
      else
      {
        sub_125E10((int)v26);
        v14 = v4[25];
        if ( v4[25] )
          return sub_128548((int)v4);
      }
    }
LABEL_26:
    sub_12D2E8(dword_128870, v4);
    v4[16] = v14;
    v23 = *v1;
    v24 = (unsigned __int8)(v7[90] - 1);
    v7[90] = v24;
    if ( *v23 < 0 && v24 > 1 )
    {
      sub_12F46C(dword_128874, dword_128868, 3210);
      v24 = (unsigned __int8)v7[90];
    }
    if ( v24 )
    {
      sub_12D240(dword_128878);
      v25 = dword_12887C;
      v22 = dword_12887C + 5280;
      do
      {
        *(uint8_t *)(v25 + 85) &= ~1u;
        v25 += 1320;
      }
      while ( v22 != v25 );
      if ( !*((uint32_t *)v7 + 20) )
        bt_event_handler();
    }
    if ( *((unsigned __int8 **)v7 + 10) != v4 )
    {
      if ( *((unsigned __int8 **)v7 + 11) != v4 )
        goto LABEL_30;
      v27 = v4[24];
      v28 = v27 + 1;
      if ( v27 == 2 )
      {
        if ( *((unsigned __int8 *)off_12885C + 24) != 255 )
        {
          v28 = 0;
          v29 = 0;
          goto LABEL_57;
        }
        v28 = 1;
      }
      else
      {
        v29 = 8 * v28;
        if ( *((unsigned __int8 *)off_12885C + 28 * v28 + 24) != 255 )
          goto LABEL_57;
        v28 = v27 + 2;
        if ( v27 == 1 )
          v28 = 0;
      }
      v29 = 8 * v28;
      if ( *((unsigned __int8 *)off_12885C + 28 * v28 + 24) == 255 )
      {
        v30 = nullptr;
LABEL_51:
        v31 = dword_128880;
        *((uint32_t *)v7 + 11) = v30;
        msg_parse(v31, v30, v29);
        goto LABEL_30;
      }
LABEL_57:
      v30 = (char *)off_12885C + 4 * (v29 - v28);
      goto LABEL_51;
    }
    v17 = (unsigned __int8)v7[90];
    *((uint32_t *)v7 + 10) = 0;
    if ( !v17 || (v18 = *((char **)v7 + 11)) != nullptr )
    {
LABEL_30:
      if ( !v4[25] )
        goto LABEL_21;
      return sub_128548((int)v4);
    }
    msg_parse(dword_128860, v22, 0);
    v19 = v4[24];
    v20 = v19 + 1;
    if ( v19 == 2 )
    {
      if ( *((unsigned __int8 *)off_12885C + 24) != 255 )
      {
        v20 = 0;
        goto LABEL_61;
      }
      v20 = 1;
    }
    else
    {
      if ( *((unsigned __int8 *)off_12885C + 28 * v20 + 24) != 255 )
        goto LABEL_61;
      v20 = v19 + 2;
      if ( v19 == 1 )
        v20 = 0;
    }
    if ( *((unsigned __int8 *)off_12885C + 28 * v20 + 24) == 255 )
    {
LABEL_19:
      sub_1270CC((int)v18);
      v14 = v4[25];
      goto LABEL_20;
    }
LABEL_61:
    v18 = (char *)off_12885C + 28 * v20;
    goto LABEL_19;
  }
LABEL_20:
  if ( v14 )
    return sub_128548((int)v4);
LABEL_21:
  sub_127E00(v4[24]);
  return sub_128548((int)v4);
}

