// v23 annotated: sub_1129E8 @ 0x1129e8
// Original: 1129e8_sub_1129E8.c
// Primary struct: <unclustered>
//
// sub_1129E8 @ 0x1129e8, size 582 bytes
// Doc: rf_mem_read_n_41a [rf]: Read RF register/memory block into buffer
// rf_mem_read_n_41a [rf]: Read RF register/memory block into buffer
int sub_1129E8()
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

  v0 = rf_bus_reset_n24c;
  v1 = rf_msg_handler_n_4cc;
  *(_BYTE *)rf_bus_reset_bitfield_n248 = 2;
  *v0 = 0;
  v1[896] &= ~1u;
  v1[513] &= ~1u;
  rf_bus_scan_19dc();
  if ( (v1[6] & 0x80) != 0 )
    v1[6] &= ~0x80u;
  v2 = rf_msg_handler_n_4cc;
  *((_DWORD *)rf_msg_handler_n_4cc + 513) |= 0x200u;
  while ( (v2[5] & 0x80) == 0 )
    ;
  v3 = (int *)rf_msg_handler_4c8;
  v4 = rf_bus_reset_n258;
  v5 = rf_msg_handler_4c8;
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
  v8 = rf_msg_handler_n_4cc;
  *((_DWORD *)rf_msg_handler_n_4cc + 513) |= 0x400u;
  v8[513] |= 0x80u;
  while ( (v8[5] & 0x40) == 0 )
    ;
  v9 = (int *)off_112C44;
  v10 = dword_112C60;
  v11 = rf_bus_reset_n258;
  v12 = (int *)off_112C44;
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
        goto LABEL_23;
      }
      goto rf_cmd_wait_n_48c;
    }
    v14 = *v9;
    v15 = v9;
    if ( (*v9 & 0x80008000) != 0 )
    {
      v16 = v9 + 2;
      goto LABEL_20;
    }
LABEL_23:
    if ( v13 != 6 )
    {
rf_cmd_wait_n_48c:
      ++v13;
      v9 += 8;
      continue;
    }
    break;
  }
  v17 = rf_msg_handler_n_4cc;
  *((_DWORD *)rf_msg_handler_n_4cc + 4) = 1072;
  while ( (v17[4] & 0x30) != 0 )
    ;
  v17[513] |= 0x100u;
  v17[519] = 65537;
  v17[517] = 41;
  v17[516] = 9;
  v17[6] |= 0xC0000u;
  if ( (v17[18] & 0x80000) != 0 )
  {
    v22 = off_112C58;
    v23 = dword_112C5C;
    v24 = rf_msg_handler_n_4cc;
    v17[9] = 285;
    v17[10] = v23;
    *v22 = 318;
    v17[513] |= 0x80u;
    while ( (v24[5] & 0x40) == 0 )
      ;
    while ( *((int *)rf_msg_handler_n_4cc + 4) >= 0 )
      ;
    v25 = rf_msg_handler_n_4cc;
    *((_DWORD *)rf_msg_handler_n_4cc + 4) = 1056;
    while ( (v25[4] & 0x20) != 0 )
      ;
    v26 = rf_msg_handler_n_4cc;
    v25[513] |= 0x100u;
    v25[513] |= 0x200u;
    while ( (v26[5] & 0x80) == 0 )
      ;
    v27 = rf_msg_handler_n_4cc;
    v26[4] |= 0x10u;
    while ( (v27[4] & 0x10) != 0 )
      ;
    v27[513] |= 0x400u;
  }
  v18 = rf_cmd_send_n_3c8_2c48;
  v19 = (int *)dword_112C4C;
  *((_DWORD *)rf_msg_handler_n_4cc + 512) &= 0xFFFFF80F;
  v18[1] = 0;
  v18[2] = 0;
  *(_BYTE *)v18 = 0;
  memset_thunk(v19, 0, 0x50u);
  memset_thunk((int *)rf_cmd_send_n_3c0, 0, 0x50u);
  result = rf_bus_mark_n1();
  v21 = *((int (__fastcall **)(_DWORD))off_112C54 + 8);
  if ( v21 )
    return v21(0);
  return result;
}

