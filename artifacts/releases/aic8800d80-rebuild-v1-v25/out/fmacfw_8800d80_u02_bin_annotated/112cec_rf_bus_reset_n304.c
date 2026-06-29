// fwstruct annotate: 112cec_rf_bus_reset_n304.c
// rf_bus_reset_n304 @ 0x112cec, size 594 bytes
// Doc: rf_stream_start2_n_4bc [rf]: Start RF data stream variant 2
// rf_stream_start2_n_4bc [rf]: Start RF data stream variant 2
int rf_bus_reset_n304()
{
  _DWORD *v0; // r3
  int v1; // r2
  int v2; // r4
  __int64 v3; // r0
  int v4; // r10
  int v5; // r2
  int v6; // r8
  int v7; // r11
  _DWORD *v8; // r6
  int v9; // r5
  int v10; // r4
  int v11; // r9
  char *v12; // r3
  int (__fastcall *v13)(int, int, BOOL); // r3
  _DWORD *v14; // r5
  int v15; // r6
  int v16; // r9
  int v17; // r7
  int i; // r4
  char *v19; // r3
  int v20; // r3
  int v21; // r3
  int v22; // r3
  _DWORD *v23; // r3
  _DWORD **v24; // r4
  int *v25; // r0
  int v26; // r1
  _DWORD *v27; // r1
  int v28; // r4
  int (__fastcall *v29)(int, int, _DWORD); // r3
  BOOL v31; // [sp+4h] [bp-10h]
  int v32; // [sp+4h] [bp-10h]
  int v33; // [sp+8h] [bp-Ch]
  int v34; // [sp+8h] [bp-Ch]
  int v35; // [sp+Ch] [bp-8h]
  int v36; // [sp+Ch] [bp-8h]

  v0 = rf_stream_start2_n_4b0;
  v1 = *((_DWORD *)rf_stream_start2_n_4b0 + 5);
  *((_DWORD *)rf_stream_start2_n_4b0 + 5) = v1;
  v2 = v0[6] & v1;
  LODWORD(v3) = v2 << 19;
  if ( (v2 & 0x1000) != 0 )
  {
    LODWORD(v3) = sub_1129E8();
    v4 = v2 & 0x2000;
    if ( (v2 & 0x2000) == 0 )
      return v3;
    v7 = 0;
    v6 = 0;
    v5 = 0;
  }
  else
  {
    HIDWORD(v3) = v2 << 18;
    v4 = v2 & rf_stream_start_f68;
    v5 = v2 & 0x40000;
    v6 = v2 & 0x80000;
    v7 = v2 & 0x800;
    if ( (v2 & 0x2000) == 0 )
      goto rf_cmd_wait_n_254;
  }
  v22 = *((_DWORD *)rf_stream_start2_n_4b0 + 514);
  if ( (v22 & 6) != 0 && (v22 & 2) != 0 )
    *(_DWORD *)rf_stream_start_n_3fc = 1;
  v23 = rf_stream_start2_n_4b0;
  v24 = (_DWORD **)rf_stream_start2_n_498;
  v25 = (int *)rf_cmd_send_2f5c;
  v26 = rf_stream_start_f60;
  *((_DWORD *)rf_stream_start2_n_4b0 + 576) = rf_stream_start_f60;
  v23[704] = v26;
  v27 = *v24;
  v28 = *v25;
  LODWORD(v3) = dword_112F64;
  *v27 = dword_112F64;
  v27[1] = v28;
  v23[709] = v27;
  v23[706] = v23[706];
  HIDWORD(v3) = v23[704] | 0x84000000;
  v23[704] = HIDWORD(v3);
rf_cmd_wait_n_254:
  if ( v5 )
  {
    v8 = rf_stream_start2_n_4b0;
    v9 = rf_cmd_send_n4fa;
    v5 = *((_DWORD *)rf_stream_start2_n_4b0 + 518);
    v10 = 0;
    v11 = v5 & *((_DWORD *)rf_stream_start2_n_4b0 + 519);
    while ( 1 )
    {
      LODWORD(v3) = 1;
      if ( ((1 << v10) & v11) != 0 )
      {
        if ( !v10 )
        {
          HIDWORD(v3) = v8[578];
          v8[578] = HIDWORD(v3);
          v21 = v8[516] & HIDWORD(v3);
          if ( (v21 & 0x18) != 0 )
          {
            v8[516] &= ~0x10u;
            rf_bus_write2_1c1c(0, 0x200000, 0);
          }
          else if ( (v21 & 1) != 0 )
          {
            sub_112228(v3);
          }
          goto rf_msg_handler_n_366;
        }
        v12 = (char *)&v8[8 * v10 - 8];
        v5 = *((_DWORD *)v12 + 586);
        *((_DWORD *)v12 + 586) = v5;
        HIDWORD(v3) = v8[516] & v5;
        if ( (v3 & 0x900000000LL) != 0 )
        {
          if ( *(_BYTE *)(v9 - 5) )
          {
            v33 = *(_DWORD *)(v9 - 12);
            v35 = *(_DWORD *)(v9 - 16);
            v31 = (v5 & 1) == 0;
            if ( (v5 & 1) == 0 )
              sub_111D44((int *)1, (unsigned __int8)v10);
            LODWORD(v3) = memset_thunk((int *)(v9 - 16), 0, 0x10u);
            v13 = *(int (__fastcall **)(int, int, BOOL))(rf_msg_handler_n_1bc + 4 * v10 + 52);
            if ( v13 )
              LODWORD(v3) = v13(v35, v33, v31);
          }
        }
        else
        {
          LODWORD(v3) = sub_10DC24(dword_112F50);
        }
      }
      if ( (unsigned __int8)v10 == 5 )
        break;
rf_msg_handler_n_366:
      ++v10;
      v9 += 16;
    }
  }
  if ( v6 )
  {
    v14 = rf_stream_start2_n_4b0;
    v15 = rf_cmd_wait_status;
    v16 = rf_cmd_send_f6c;
    v17 = *((_DWORD *)rf_stream_start2_n_4b0 + 518) & *((_DWORD *)rf_stream_start2_n_4b0 + 519);
    for ( i = 0; ; ++i )
    {
      if ( ((0x10000 << i) & v17) != 0 )
      {
        if ( !i )
        {
          HIDWORD(v3) = v14[706];
          v14[706] = HIDWORD(v3);
          v20 = v14[517] & HIDWORD(v3);
          v5 = v20 << 27;
          if ( (v20 & 0x10) != 0 )
          {
            v14[517] &= ~0x10u;
            LODWORD(v3) = rf_bus_write_1b64(0, 0x200000, 0);
          }
          else if ( (v20 & 0x29) != 0 )
          {
            LODWORD(v3) = 0;
            LODWORD(v3) = sub_112228(v3);
          }
          goto LABEL_19;
        }
        v19 = (char *)&v14[8 * i - 8];
        v5 = *((_DWORD *)v19 + 714);
        *((_DWORD *)v19 + 714) = v5;
        if ( (v14[517] & v5 & 1) != 0 )
        {
          if ( *(_BYTE *)(v15 - 8) )
          {
            v34 = **(unsigned __int16 **)(v16 + 4 * i);
            v32 = *(_DWORD *)(v15 - 12);
            v36 = *(_DWORD *)(v15 - 16);
            LODWORD(v3) = memset_thunk((int *)(v15 - 16), 0, 0x10u);
            v29 = *(int (__fastcall **)(int, int, _DWORD))(4 * i + rf_msg_handler_n_1bc + 32);
            if ( v29 )
              LODWORD(v3) = v29(v36, v32 - v34, 0);
          }
        }
      }
      if ( (unsigned __int8)i == 5 )
        break;
LABEL_19:
      v15 += 16;
    }
  }
  if ( v7 )
  {
    LODWORD(v3) = sub_112C64(v3, SHIDWORD(v3), v5);
    if ( v4 >= 0 )
      return v3;
  }
  else if ( v4 >= 0 )
  {
    return v3;
  }
  LODWORD(v3) = rf_cmd_stop(v3, SHIDWORD(v3), v5);
  return v3;
}

