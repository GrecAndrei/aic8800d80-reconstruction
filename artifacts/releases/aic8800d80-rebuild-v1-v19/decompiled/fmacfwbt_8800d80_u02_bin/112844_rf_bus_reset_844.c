// rf_bus_reset_844 @ 0x112844, size 582 bytes
// Doc: rf_cmd_send_n_458 [rf]: Send RF command (dispatch via table at 0x40200000)
// rf_cmd_send_n_458 [rf]: Send RF command (dispatch via table at 0x40200000)
int rf_bus_reset_844()
{
  _BYTE *v0; // r3
  _DWORD *v1; // r4
  _DWORD *v2; // r3
  int *v3; // r1
  int v4; // r5
  _DWORD *v5; // r4
  int i; // r0
  int v7; // r3
  _DWORD *v8; // r3
  int *v9; // r1
  int v10; // lr
  int v11; // r12
  int *v12; // r6
  int v13; // r5
  int v14; // r0
  int *v15; // r2
  _DWORD *v16; // r4
  _DWORD *v17; // r3
  _DWORD *v18; // r3
  int *v19; // r0
  int result; // r0
  int (__fastcall *v21)(_DWORD); // r3
  _WORD *v22; // r2
  int v23; // r4
  _DWORD *v24; // r1
  _DWORD *v25; // r3
  _DWORD *v26; // r2
  _DWORD *v27; // r3

  v0 = rf_msg_handler_n_4d0;
  v1 = off_112A94;
  *(_BYTE *)rf_cmd_send_n_3e0 = 2;
  *v0 = 0;
  v1[896] &= ~1u;
  v1[513] &= ~1u;
  rf_bus_scan();
  if ( (v1[6] & 0x80) != 0 )
    v1[6] &= ~0x80u;
  v2 = off_112A94;
  *((_DWORD *)off_112A94 + 513) |= 0x200u;
  while ( (v2[5] & 0x80) == 0 )
    ;
  v3 = (int *)off_112A98;
  v4 = dword_112A9C;
  v5 = off_112A98;
  for ( i = 1; ; ++i )
  {
    if ( i == 1 )
    {
      if ( (*v5 & 0x80008000) != 0 )
        *v5 |= v4;
      goto LABEL_11;
    }
    v7 = *v3;
    if ( (*v3 & 0x80008000) != 0 )
    {
      *v3 |= v4;
      if ( v7 < 0 )
      {
        v3[2] = 2;
        *v3 |= 0x40000000u;
        while ( (v3[2] & 2) == 0 )
          ;
      }
      if ( (v7 & 0x8000) == 0 )
        *v3 &= ~0x8000u;
    }
    if ( i == 6 )
      break;
LABEL_11:
    v3 += 8;
  }
  v8 = off_112A94;
  *((_DWORD *)off_112A94 + 513) |= 0x400u;
  v8[513] |= 0x80u;
  while ( (v8[5] & 0x40) == 0 )
    ;
  v9 = (int *)off_112AA0;
  v10 = rf_msg_handler_n_4a4;
  v11 = dword_112A9C;
  v12 = (int *)off_112AA0;
  v13 = 1;
  while ( 2 )
  {
    if ( v13 == 1 )
    {
      v14 = *v12;
      if ( (*v12 & 0x80008000) != 0 )
      {
        v16 = (_DWORD *)v10;
        v15 = v12;
LABEL_20:
        *v16 = 64;
        *v15 |= v11;
        if ( v14 < 0 )
        {
          if ( (v14 & 0x20000) == 0 )
          {
            while ( (*v16 & 0x40) == 0 )
              ;
            *v16 = 64;
          }
          *v16 = 2;
          *v15 |= 0x40000000u;
          while ( (*v16 & 2) == 0 )
            ;
        }
        if ( (v14 & 0x8000) == 0 )
          *v15 &= ~0x8000u;
        goto rf_bus_handler;
      }
      goto rf_bus_reset_nfc;
    }
    v14 = *v9;
    v15 = v9;
    if ( (*v9 & 0x80008000) != 0 )
    {
      v16 = v9 + 2;
      goto LABEL_20;
    }
rf_bus_handler:
    if ( v13 != 6 )
    {
rf_bus_reset_nfc:
      ++v13;
      v9 += 8;
      continue;
    }
    break;
  }
  v17 = off_112A94;
  *((_DWORD *)off_112A94 + 4) = 1072;
  while ( (v17[4] & 0x30) != 0 )
    ;
  v17[513] |= 0x100u;
  v17[519] = 65537;
  v17[517] = 41;
  v17[516] = 9;
  v17[6] |= 0xC0000u;
  if ( (v17[18] & 0x80000) != 0 )
  {
    v22 = off_112AB4;
    v23 = rf_bus_reset_clken_set;
    v24 = off_112A94;
    v17[9] = 285;
    v17[10] = v23;
    *v22 = 318;
    v17[513] |= 0x80u;
    while ( (v24[5] & 0x40) == 0 )
      ;
    while ( *((int *)off_112A94 + 4) >= 0 )
      ;
    v25 = off_112A94;
    *((_DWORD *)off_112A94 + 4) = 1056;
    while ( (v25[4] & 0x20) != 0 )
      ;
    v26 = off_112A94;
    v25[513] |= 0x100u;
    v25[513] |= 0x200u;
    while ( (v26[5] & 0x80) == 0 )
      ;
    v27 = off_112A94;
    v26[4] |= 0x10u;
    while ( (v27[4] & 0x10) != 0 )
      ;
    v27[513] |= 0x400u;
  }
  v18 = rf_msg_handler_n_4bc;
  v19 = (int *)rf_msg_handler_n_4b8;
  *((_DWORD *)off_112A94 + 512) &= 0xFFFFF80F;
  v18[1] = 0;
  v18[2] = 0;
  *(_BYTE *)v18 = 0;
  memset_thunk(v19, 0, 0x50u);
  memset_thunk((int *)rf_msg_handler_n_4b4, 0, 0x50u);
  result = rf_bus_reset2_n_177();
  v21 = *((int (__fastcall **)(_DWORD))rf_bus_reset_ab0 + 8);
  if ( v21 )
    return v21(0);
  return result;
}

