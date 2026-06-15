// v23 annotated: sub_1287E0 @ 0x1287e0
// Original: 1287e0_sub_1287E0.c
// Primary struct: <unclustered>
//
// sub_1287E0 @ 0x1287e0, size 664 bytes
int __fastcall sub_1287E0(int a1)
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
  _DWORD *v26; // r0
  int v27; // r1
  int v28; // r3
  int v29; // r2
  char *v30; // r1
  int v31; // r0

  v1 = (__int16 **)off_128AA8;
  v2 = dword_128AA0;
  v3 = 1320 * a1;
  v4 = *(unsigned __int8 **)(dword_128AA0 + 1320 * a1 + 72);
  if ( **(__int16 **)off_128AA8 < 0 && !v4 )
    sub_12F694(dword_128A90, dword_128A8C, 3149);
  v6 = v2 + 1320 * a1;
  v7 = (char *)off_128A78;
  feature_guard_sdio(256, dword_128A7C);
  list_remove_node_d510(v7 + 16, v3 + 76 + v2);
  v9 = *(unsigned __int8 *)(v6 + 85);
  *(_BYTE *)(v6 + 85) = v9 & 0xFE;
  v10 = v9 << 30;
  if ( (v9 & 2) != 0 )
  {
    v11 = (unsigned __int8)(v7[91] - 1);
    v7[91] = v11;
    if ( !v11 && (v7[88] & 0x40) != 0 )
    {
      sub_12ECB0(dword_128A88, v8, v10);
      rf_init_or_attach_n488(*((_DWORD *)v7 + 20));
    }
  }
  v12 = v2 + 1320 * a1;
  *(_BYTE *)(v12 + 85) = 0;
  *(_DWORD *)(v12 + 72) = 0;
  v13 = v4[16];
  v14 = (unsigned __int8)(v4[25] - 1);
  v4[25] = v14;
  if ( v13 )
  {
    if ( v4[27] == *(unsigned __int8 *)(v12 + 107) )
    {
      sub_126034(v2 + v3);
      v14 = v4[25];
      v4[27] = -1;
      if ( v14 )
        return sub_12876C((int)v4);
    }
    else
    {
      v15 = (unsigned __int8 *)off_128A80;
      while ( 1 )
      {
        if ( v15[24] != 255 )
        {
          v16 = v15[27];
          if ( v16 != 255 )
            break;
        }
        v15 += 28;
        if ( (unsigned __int8 *)((char *)off_128A80 + 84) == v15 )
          goto LABEL_10;
      }
      v26 = (_DWORD *)(v2 + 1320 * v16);
      if ( (unsigned __int8 *)v26[18] == v4 )
      {
LABEL_10:
        if ( !v14 )
          goto LABEL_26;
        return sub_12876C((int)v4);
      }
      if ( v14 )
      {
        sub_12609C(v26);
        LOBYTE(v14) = v4[25];
        if ( (_BYTE)v14 )
          return sub_12876C((int)v4);
      }
      else
      {
        sub_126034((int)v26);
        v14 = v4[25];
        if ( v4[25] )
          return sub_12876C((int)v4);
      }
    }
LABEL_26:
    list_remove_node_d510(dword_128A94, v4);
    v4[16] = v14;
    v23 = *v1;
    v24 = (unsigned __int8)(v7[90] - 1);
    v7[90] = v24;
    if ( *v23 < 0 && v24 > 1 )
    {
      sub_12F694(dword_128A98, dword_128A8C, 3210);
      v24 = (unsigned __int8)v7[90];
    }
    if ( v24 )
    {
      bt_xtal_init_check(dword_128A9C);
      v25 = dword_128AA0;
      v22 = dword_128AA0 + 5280;
      do
      {
        *(_BYTE *)(v25 + 85) &= ~1u;
        v25 += 1320;
      }
      while ( v22 != v25 );
      if ( !*((_DWORD *)v7 + 20) )
        fmacfwbt_init_load();
    }
    if ( *((unsigned __int8 **)v7 + 10) != v4 )
    {
      if ( *((unsigned __int8 **)v7 + 11) != v4 )
        goto LABEL_30;
      v27 = v4[24];
      v28 = v27 + 1;
      if ( v27 == 2 )
      {
        if ( *((unsigned __int8 *)off_128A80 + 24) != 255 )
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
        if ( *((unsigned __int8 *)off_128A80 + 28 * v28 + 24) != 255 )
          goto LABEL_57;
        v28 = v27 + 2;
        if ( v27 == 1 )
          v28 = 0;
      }
      v29 = 8 * v28;
      if ( *((unsigned __int8 *)off_128A80 + 28 * v28 + 24) == 255 )
      {
        v30 = nullptr;
LABEL_51:
        v31 = dword_128AA4;
        *((_DWORD *)v7 + 11) = v30;
        sub_12ECB0(v31, v30, v29);
        goto LABEL_30;
      }
LABEL_57:
      v30 = (char *)off_128A80 + 4 * (v29 - v28);
      goto LABEL_51;
    }
    v17 = (unsigned __int8)v7[90];
    *((_DWORD *)v7 + 10) = 0;
    if ( !v17 || (v18 = *((char **)v7 + 11)) != nullptr )
    {
LABEL_30:
      if ( !v4[25] )
        goto LABEL_21;
      return sub_12876C((int)v4);
    }
    sub_12ECB0(dword_128A84, v22, 0);
    v19 = v4[24];
    v20 = v19 + 1;
    if ( v19 == 2 )
    {
      if ( *((unsigned __int8 *)off_128A80 + 24) != 255 )
      {
        v20 = 0;
        goto LABEL_61;
      }
      v20 = 1;
    }
    else
    {
      if ( *((unsigned __int8 *)off_128A80 + 28 * v20 + 24) != 255 )
        goto LABEL_61;
      v20 = v19 + 2;
      if ( v19 == 1 )
        v20 = 0;
    }
    if ( *((unsigned __int8 *)off_128A80 + 28 * v20 + 24) == 255 )
    {
LABEL_19:
      sub_1272F0((int)v18);
      v14 = v4[25];
      goto LABEL_20;
    }
LABEL_61:
    v18 = (char *)off_128A80 + 28 * v20;
    goto LABEL_19;
  }
LABEL_20:
  if ( v14 )
    return sub_12876C((int)v4);
LABEL_21:
  bt_msg_handler_dispatch(v4[24]);
  return sub_12876C((int)v4);
}

