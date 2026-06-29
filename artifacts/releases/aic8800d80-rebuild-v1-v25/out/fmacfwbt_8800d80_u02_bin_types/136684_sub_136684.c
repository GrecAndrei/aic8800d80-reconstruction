// sub_136684 @ 0x136684, size 388 bytes
int  sub_136684(int a1, int a2, __int16 a3, __int16 a4)
{
  int v4; // r8
  int v8; // r6
  int v9; // r5
  char v10; // r5
  char *v11; // r0
  char v13; // r3
  __int16 v14; // r3
  int v15; // r3
  char v16; // r2
  int v17; // r1
  __int16 v18; // r2
  int v19; // r9
  unsigned int v20; // r0
  int v21; // r3
  unsigned int v22; // r2
  int v23; // r2
  unsigned __int8 v24; // [sp+3h] [bp-Dh] BYREF
  int v25; // [sp+4h] [bp-Ch] BYREF
  int v26; // [sp+8h] [bp-8h]
  __int16 v27; // [sp+Ch] [bp-4h]

  v4 = dword_136824;
  feature_guard_sdio(256, dword_13680C, *(uint32_t *)(a2 + 20), *((unsigned __int8 *)off_136808 + 413));
  v8 = *(unsigned __int8 *)(a2 + 51);
  v9 = v4 + 1320 * v8;
  if ( *(uint8_t *)(v9 + 106) != 2 )
  {
    v10 = 4;
LABEL_3:
    v11 = (char *)rf_bus_setup_n3a8(7169, a4, a3, 4u);
    *v11 = v10;
    v11[1] = *(uint8_t *)(a2 + 51);
    sub_12CBB4((int)v11);
    return 0;
  }
  if ( msg_get_value(7u) )
  {
    v10 = 8;
    goto LABEL_3;
  }
  if ( *(uint8_t *)(v9 + 108) )
  {
    v10 = 9;
    goto LABEL_3;
  }
  if ( **(__int16 **)off_136810 < 0 && *(uint32_t *)(v9 + 72) )
    sub_12F694(dword_13681C, dword_136818, 105);
  v13 = *(uint8_t *)(a2 + 16);
  *(uint32_t *)off_136814 = a2;
  LOBYTE(v25) = v13;
  v14 = *(uint16_t *)(a2 + 14);
  BYTE1(v25) = *(uint8_t *)(a2 + 28);
  HIWORD(v25) = v14;
  v15 = *(uint32_t *)(a2 + 24);
  LOWORD(v26) = *(uint32_t *)(a2 + 20);
  v16 = *(uint8_t *)(a2 + 18);
  HIWORD(v26) = v15;
  LOBYTE(v15) = *(uint8_t *)(a2 + 17);
  LOBYTE(v27) = v16;
  HIBYTE(v27) = v15;
  if ( sub_127F58((unsigned __int8 *)&v25, &v24) )
  {
    v10 = 1;
    goto LABEL_3;
  }
  v17 = v26;
  v18 = v27;
  v19 = v4 + 1320 * v8;
  *(uint32_t *)(v19 + 412) = v25;
  *(uint32_t *)(v19 + 416) = v17;
  *(uint8_t *)(v19 + 464) = 0;
  *(uint16_t *)(v19 + 420) = v18;
  message_dispatch_c7ac(v19);
  if ( BYTE1(v25) == 2 )
    sub_120AB4((int *)(v4 + 1320 * v8), 1, 0);
  v20 = sub_128AAC(*(unsigned __int8 *)(a2 + 51), v24);
  if ( !*(uint8_t *)(a2 + 16) )
  {
    v20 = sub_1329B0((unsigned __int8 *)(1320 * v8 + 424 + v4), 1) & 0xF;
    if ( v20 )
    {
      v20 = __clz(v20);
      *(uint8_t *)(v4 + 1320 * v8 + 461) = 31 - v20;
    }
    else
    {
      *(uint8_t *)(v4 + 1320 * v8 + 461) = 1;
    }
  }
  sub_1369C0(v20);
  if ( !*(uint32_t *)off_136820 )
  {
    v21 = v4 + 1320 * v8;
    v22 = *(unsigned __int16 *)(v21 + 416);
    if ( v22 <= 0x1387 )
    {
      v23 = v22 | (*(unsigned __int8 *)(v21 + 413) << 16);
      sub_10D054(v23 | 0x80000000, 4999, v23);
    }
  }
  return 1;
}

