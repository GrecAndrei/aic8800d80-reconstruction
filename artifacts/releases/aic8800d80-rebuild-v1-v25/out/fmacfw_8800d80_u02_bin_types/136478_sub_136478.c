// sub_136478 @ 0x136478, size 450 bytes
int  sub_136478(int a1, int a2, __int16 a3, __int16 a4)
{
  int v4; // r8
  int v8; // r6
  int v9; // r5
  char v10; // r5
  char *v11; // r0
  char v13; // r2
  __int16 v14; // r3
  int v15; // r3
  uint8_t *v16; // r10
  char v17; // r2
  int v18; // r1
  __int16 v19; // r2
  int v20; // r9
  int v21; // r0
  int v22; // r3
  unsigned int v23; // r2
  int v24; // r0
  unsigned int v25; // r0
  int v26; // r2
  unsigned __int8 v27; // [sp+3h] [bp-11h] BYREF
  int v28; // [sp+4h] [bp-10h] BYREF
  int v29; // [sp+8h] [bp-Ch]
  __int16 v30; // [sp+Ch] [bp-8h]

  v4 = dword_136660;
  feature_guard_check(256, dword_136640, *(uint32_t *)(a2 + 20), *((unsigned __int8 *)off_13663C + 413));
  v8 = *(unsigned __int8 *)(a2 + 51);
  v9 = v4 + 1320 * v8;
  if ( *(uint8_t *)(v9 + 106) != 2 )
  {
    v10 = 4;
LABEL_3:
    v11 = (char *)sub_12C92C(7169, a4, a3, 4u);
    *v11 = v10;
    v11[1] = *(uint8_t *)(a2 + 51);
    sdio_buffer_prepare_n_4e8((int)v11);
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
  if ( **(__int16 **)off_136644 < 0 && *(uint32_t *)(v9 + 72) )
    sub_12F46C(dword_13664C, dword_136648, 105);
  v13 = *(uint8_t *)(a2 + 28);
  LOBYTE(v28) = *(uint8_t *)(a2 + 16);
  v14 = *(uint16_t *)(a2 + 14);
  BYTE1(v28) = v13;
  HIWORD(v28) = v14;
  v15 = *(uint32_t *)(a2 + 24);
  v16 = off_136664;
  LOWORD(v29) = *(uint32_t *)(a2 + 20);
  v17 = *(uint8_t *)(a2 + 18);
  HIWORD(v29) = v15;
  LOBYTE(v15) = *(uint8_t *)(a2 + 17);
  *(uint32_t *)off_136664 = a2;
  LOBYTE(v30) = v17;
  HIBYTE(v30) = v15;
  if ( sub_127D34((unsigned __int8 *)&v28, &v27) )
  {
    v10 = 1;
    goto LABEL_3;
  }
  v18 = v29;
  v19 = v30;
  v20 = v4 + 1320 * v8;
  *(uint32_t *)(v20 + 412) = v28;
  *(uint32_t *)(v20 + 416) = v18;
  *(uint8_t *)(v20 + 464) = 0;
  *(uint16_t *)(v20 + 420) = v19;
  message_dispatch_408(v20);
  if ( BYTE1(v28) == 2 )
    sub_12077C((int *)(v4 + 1320 * v8), 1, 0);
  v21 = sub_128888(*(unsigned __int8 *)(a2 + 51), v27);
  if ( *((unsigned __int8 *)off_136650 + 18) + *((unsigned __int8 *)off_136650 + 17) == 1
    && !*(uint8_t *)(v4 + 1320 * v8 + 1224) )
  {
    *(uint8_t *)off_13665C = 0;
    sub_136E74(v21);
  }
  if ( !*(uint8_t *)(a2 + 16) )
  {
    v25 = task_entry_n794((unsigned __int8 *)(1320 * v8 + 424 + v4), 1) & 0xF;
    if ( v25 )
      *(uint8_t *)(v4 + 1320 * v8 + 461) = 31 - __clz(v25);
    else
      *(uint8_t *)(v4 + 1320 * v8 + 461) = 1;
  }
  sub_136864();
  if ( !*(uint32_t *)off_136654 )
  {
    v22 = v4 + 1320 * v8;
    v23 = *(unsigned __int16 *)(v22 + 416);
    if ( v23 <= 0x1387 )
    {
      v26 = v23 | (*(unsigned __int8 *)(v22 + 413) << 16);
      mmio_init_or_reset(v26 | 0x80000000, 4999, v26);
    }
  }
  v24 = dword_136658;
  v16[14] = v16[15];
  v16[13] = 0;
  timestamp_remove(v24);
  return 1;
}

