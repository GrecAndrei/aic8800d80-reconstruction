// rf_bus_write_n_25c @ 0x13b734, size 576 bytes
// Doc: rf_bus_write_n_25c [rf]: Writes value to RF bus register
// rf_bus_write_n_25c [rf]: Writes value to RF bus register
int  rf_bus_write_n_25c(int a1, int a2, int a3, char a4, __int16 a5, __int16 a6, int a7)
{
  int v7; // r9
  int v8; // r7
  int v9; // r8
  __int16 **v10; // r10
  int v13; // r0
  int v14; // r2
  int result; // r0
  int v16; // r4
  int v17; // r3
  int v18; // r2
  int v19; // r1
  int v20; // r5
  int v21; // r12
  __int16 v22; // r2
  int v23; // r5
  int v24; // r6
  uint32_t *v25; // r1
  int v26; // r5
  uint16_t *v28; // [sp+18h] [bp-14h]

  v7 = dword_13B990;
  v8 = dword_13B974;
  v9 = *(unsigned __int8 *)(dword_13B990 + 696 * a1 + 34);
  v10 = (__int16 **)off_13B994;
  v13 = *(uint32_t *)(dword_13B974 + 1320 * v9 + 72);
  if ( !v13 )
  {
    if ( **(__int16 **)off_13B994 >= 0 )
    {
LABEL_19:
      result = sub_119084(1, 512);
      v16 = result;
      if ( !result )
        return result;
      goto LABEL_4;
    }
LABEL_18:
    sub_12F694(dword_13B980, dword_13B97C, 520);
    goto LABEL_19;
  }
  v14 = *(unsigned __int8 *)(v13 + 4);
  if ( **(__int16 **)off_13B994 < 0 && v14 == 2 )
    goto LABEL_18;
  result = sub_119084((*(unsigned __int8 *)(dword_13B974 + 1320 * v9 + 1224) | v14) != 0, 512);
  v16 = result;
  if ( !result )
    return result;
LABEL_4:
  message_dispatch_n_4a3(v8 + 1320 * v9, v16);
  v17 = *(uint32_t *)(v16 + 72);
  v18 = 696 * a1 + 38;
  *(uint8_t *)(v17 + 108) = -48;
  *(uint8_t *)(v17 + 109) = 0;
  *(uint8_t *)(v17 + 110) = 0;
  *(uint8_t *)(v17 + 111) = 0;
  *(uint16_t *)(v17 + 112) = *(uint16_t *)(v7 + v18);
  v19 = v7 + v18;
  v20 = 1320 * v9 + 100;
  *(uint16_t *)(v17 + 114) = *(uint16_t *)(v7 + v18 + 2);
  *(uint16_t *)(v17 + 116) = *(uint16_t *)(v7 + v18 + 4);
  *(uint16_t *)(v17 + 118) = *(uint16_t *)(v8 + v20);
  v21 = v8 + v20;
  *(uint16_t *)(v17 + 120) = *(uint16_t *)(v8 + v20 + 2);
  v28 = (uint16_t *)(v17 + 108);
  *(uint16_t *)(v17 + 122) = *(uint16_t *)(v8 + v20 + 4);
  if ( *(uint8_t *)(v8 + 1320 * v9 + 106) == 2 )
  {
    *(uint16_t *)(v17 + 124) = *(uint16_t *)(v8 + v20);
    *(uint16_t *)(v17 + 126) = *(uint16_t *)(v21 + 2);
    *(uint16_t *)(v17 + 128) = *(uint16_t *)(v21 + 4);
  }
  else
  {
    *(uint16_t *)(v17 + 124) = *(uint16_t *)(v7 + v18);
    *(uint16_t *)(v17 + 126) = *(uint16_t *)(v19 + 2);
    *(uint16_t *)(v17 + 128) = *(uint16_t *)(v19 + 4);
  }
  v22 = *((uint16_t *)off_13B978 + 254) + 1;
  *((uint16_t *)off_13B978 + 254) = v22;
  *(uint16_t *)(v17 + 130) = 16 * v22;
  *(uint8_t *)(v16 + 51) = 0;
  *(uint8_t *)(v16 + 53) = 0;
  *(uint8_t *)(v16 + 28) = v9;
  *(uint8_t *)(v16 + 29) = a1;
  if ( sub_13C734(v16, 208, 3) == 1 )
  {
    sub_13B13C(v16, v28, 24);
    v23 = *(unsigned __int8 *)(v16 + 51) + 24;
  }
  else
  {
    v23 = 24;
  }
  if ( a3 == 1 )
  {
    v24 = 3;
    v23 += sub_130F68((int)v28 + v23, a2, a5, a4, a6);
  }
  else if ( a3 == 2 )
  {
    v24 = *(unsigned __int8 *)(dword_13B984 + *(unsigned __int8 *)(a2 + 22));
    v23 += sub_130FAC((int)v28 + v23, a2, a6);
  }
  else if ( a3 )
  {
    if ( **v10 < 0 )
      sub_12F6C4(dword_13B98C, dword_13B988, 269);
    v24 = 3;
  }
  else
  {
    v24 = *(unsigned __int8 *)(dword_13B984 + *(unsigned __int8 *)(a2 + 22));
    v23 += bt_chan_info_init((int)v28 + v23, a2);
  }
  v25 = *(uint32_t **)(v16 + 76);
  v26 = v23 + *(unsigned __int8 *)(v16 + 53);
  v25[8] = v25[7] - 1 + v26;
  v25[9] = v26 + 4;
  if ( a7 )
  {
    *(uint32_t *)(v16 + 88) = a7;
    *(uint32_t *)(v16 + 92) = a2;
  }
  return sub_1190B4(v16, v24);
}

