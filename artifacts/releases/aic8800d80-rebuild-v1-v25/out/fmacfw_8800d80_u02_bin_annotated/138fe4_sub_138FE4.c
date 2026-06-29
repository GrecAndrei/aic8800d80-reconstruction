// fwstruct annotate: 138fe4_sub_138FE4.c
// sub_138FE4 @ 0x138fe4, size 672 bytes
// Doc: sub_1238FE4 [ipc]: Generic handler with 8 saved regs; likely IPC or command dispatcher
// sub_1238FE4 [ipc]: Generic handler with 8 saved regs; likely IPC or command dispatcher
int __fastcall sub_138FE4(unsigned int a1, int a2, int a3)
{
  _WORD *v3; // r6
  char v5; // r5
  int v7; // r10
  int v8; // r9
  int v9; // r7
  _DWORD *v10; // r4
  int v11; // r2
  __int16 v13; // r2
  char v14; // r1
  _DWORD *v15; // r3
  int v16; // r1
  int v17; // r3
  __int64 v18; // r2
  int v19; // r0
  int v20; // r0
  unsigned int v21; // r5
  __int16 v22; // r3
  __int16 v23; // r6
  __int16 v24; // r1
  _DWORD *v25; // r0
  int v26; // r3
  _DWORD *v27; // r0
  _BYTE v28[24]; // [sp+8h] [bp-18h] BYREF

  v3 = off_139284;
  v5 = a2;
  if ( a3 )
  {
    v7 = *((unsigned __int8 *)off_139284 + 7);
    v8 = *(_WORD *)off_139284 & 0x400;
    if ( (*(_WORD *)off_139284 & 0x400) == 0 )
      goto LABEL_3;
LABEL_14:
    v10 = *((_DWORD **)off_139284 + 22);
    v11 = *((unsigned __int16 *)off_139284 + 2);
    v9 = *((unsigned __int8 *)off_139284 + 6);
    if ( v10 )
      goto LABEL_7;
LABEL_15:
    if ( v9 )
      return 0;
    v10 = rf_bus_mark_n100_d2d0(dword_139288);
    if ( !v10 )
    {
      v27 = rf_bus_mark_n100_d2d0(dword_139294);
      v10 = v27;
      if ( **(__int16 **)off_13929C < 0 && !v27 )
        sub_12F46C(dword_1392A4, dword_1392A0, 1111);
      sub_1389D0(0, 4, v10[5]);
    }
    v13 = v3[2];
    *((_BYTE *)v10 + 6) = v5;
    *((_BYTE *)v10 + 7) = v7;
    *((_BYTE *)v10 + 8) = 1;
    *((_BYTE *)v10 + 4) = 0;
    v14 = *((_BYTE *)v3 + 8);
    v15 = off_13928C;
    v10[4] = 0;
    *((_BYTE *)v10 + 9) = v14;
    v16 = v15[4];
    v17 = dword_139290;
    *((_WORD *)v10 + 5) = v13;
    v10[14] = v17;
    v10[15] = v10;
    timestamp_update((int)(v10 + 13), v16 + 100000);
    if ( (v3[24] & 1) != 0 )
      fmac_msg_handler_n3a4(a1, (int)(v10 + 7), 1, 0);
    *(_DWORD *)(a1 + 96) &= ~0x20u;
    sub_138CB4(a1, 1);
    HIDWORD(v18) = *((_DWORD *)v3 + 16);
    LODWORD(v18) = *((_DWORD *)v3 + 7);
    v19 = dword_139294;
    *((_QWORD *)v10 + 2) = v18;
    *((_BYTE *)v10 + 5) = *((_BYTE *)v3 + 49);
    *((_WORD *)v10 + 6) = *(_WORD *)(a1 + 48);
    list_push_tail(v19, v10);
    goto LABEL_20;
  }
  v8 = *(_WORD *)off_139284 & 0x400;
  v7 = 0;
  if ( (*(_WORD *)off_139284 & 0x400) != 0 )
    goto LABEL_14;
LABEL_3:
  v9 = *((unsigned __int8 *)off_139284 + 6);
  if ( *((_BYTE *)off_139284 + 6) )
  {
    v10 = *((_DWORD **)off_139284 + 22);
    v11 = *((unsigned __int16 *)off_139284 + 2);
    if ( !v10 )
      return *((_DWORD *)off_139284 + 22);
LABEL_7:
    while ( *((unsigned __int8 *)v10 + 6) != a2
         || *((unsigned __int8 *)v10 + 7) != v7
         || *((unsigned __int16 *)v10 + 5) != v11 )
    {
      v10 = (_DWORD *)*v10;
      if ( !v10 )
        goto LABEL_15;
    }
    if ( *((unsigned __int8 *)v10 + 8) != v9 )
      return 0;
    v21 = (unsigned __int16)(*(_WORD *)(a1 + 48) - *((unsigned __int8 *)v10 + 9));
    v22 = *((_WORD *)v10 + 6) + v21;
    *((_BYTE *)v10 + 8) = v9 + 1;
    *((_WORD *)v10 + 6) = v22;
    if ( (v3[24] & 1) != 0 )
    {
      if ( fmac_msg_handler_n3a4(a1, (int)(v10 + 7), 0, v8 == 0) )
      {
        v26 = *(_DWORD *)(a1 + 96);
        if ( !v8 )
        {
          *((_WORD *)v10 + 6) -= 8;
          *(_DWORD *)(a1 + 96) = v26 & 0xFFFFFF9F | 0x40;
          sdio_buffer_prepare_n_2f4(a1, v21, v10[4], *((unsigned __int8 *)v10 + 9), 0, 0);
          v10[4] += v21;
          v23 = 1;
          goto LABEL_30;
        }
        *(_DWORD *)(a1 + 96) = v26 & 0xFFFFFF9F | 0x40;
        sdio_buffer_prepare_n_2f4(a1, v21, v10[4], *((unsigned __int8 *)v10 + 9), 0, 0);
        v10[4] += v21;
LABEL_20:
        v10[6] = *((_DWORD *)off_13928C + 4);
        return 1;
      }
      v23 = 4;
    }
    else
    {
      v23 = 1;
    }
    *(_DWORD *)(a1 + 96) = *(_DWORD *)(a1 + 96) & 0xFFFFFF9F | 0x40;
    sdio_buffer_prepare_n_2f4(a1, v21, v10[4], *((unsigned __int8 *)v10 + 9), 0, 0);
    v10[4] += v21;
    if ( !v8 )
    {
LABEL_30:
      if ( *((_BYTE *)v10 + 5) )
        v24 = 24;
      else
        v24 = 8;
      v25 = sub_1389D0(0, v24, v10[5]);
      if ( v25 )
        v25[18] = *((unsigned __int16 *)v10 + 6);
      sub_1389D0(0, v23, v10[5]);
      timestamp_remove((int)(v10 + 13));
      sub_12D2E8(dword_139294, v10);
      list_push_tail(dword_139288, v10);
      goto LABEL_20;
    }
    goto LABEL_20;
  }
  if ( (*((_BYTE *)off_139284 + 48) & 1) != 0 )
  {
    if ( !fmac_msg_handler_n3a4(a1, (int)v28, 1, 1) )
      return v9;
    *(_WORD *)(a1 + 48) -= 8;
  }
  v20 = dword_139298 + 1320 * *((unsigned __int8 *)v3 + 10);
  if ( *(_BYTE *)(v20 + 1227)
    && rf_msg_process_body_n422(
         (unsigned __int8 *)(v20 + 107),
         (_DWORD *)(v20 + 1228),
         *(char **)(*(_DWORD *)(a1 + 28) + 8),
         a3) == 1 )
  {
    return v9;
  }
  sub_138CB4(a1, 3);
  return 1;
}

