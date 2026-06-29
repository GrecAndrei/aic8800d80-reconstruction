// sub_135384 @ 0x135384, size 462 bytes
// Doc: sub_1235384 [scan]: Iterate indexed entries (0x528 stride) into lookup tables
// sub_1235384 [scan]: Iterate indexed entries (0x528 stride) into lookup tables
uint32_t * sub_135384(int a1, char *a2)
{
  uint8_t *v2; // r7
  int v3; // r5
  int v4; // r6
  int v5; // r11
  unsigned __int8 *v6; // r4
  int v9; // r10
  int v10; // r0
  int v11; // r4
  int v12; // r5
  int v13; // r3
  int v14; // r2
  __int16 v15; // r1
  int v16; // t1
  int v17; // lr
  __int16 v18; // r0
  int v19; // r1
  int v20; // r10
  int v21; // r11
  int v22; // r11
  uint32_t *v23; // r1
  int v24; // r0
  unsigned int v26; // r0
  char *v27; // r1
  char *v28; // r0
  char *v29; // r2
  char v30; // t1
  unsigned int v31; // [sp+Ch] [bp-8h]

  v2 = off_135554;
  v3 = dword_135558;
  v4 = *((uint32_t *)off_135554 + 4);
  v5 = *(unsigned __int8 *)(v4 + 61);
  v6 = (unsigned __int8 *)(dword_135558 + 1320 * v5);
  v9 = v6[116];
  feature_guard_sdio(256, dword_135560, dword_13555C);
  if ( !v6[1224] )
  {
    v10 = v6[412];
    if ( v6[412] )
      v10 = 1;
    v11 = sub_119084(v10, 512);
    if ( v11 )
      goto LABEL_5;
    return (uint32_t *)sub_135020(1);
  }
  v11 = sub_119084(1, 512);
  if ( !v11 )
    return (uint32_t *)sub_135020(1);
LABEL_5:
  v12 = v3 + 1320 * v5;
  message_dispatch_n_4a3(v12, v11);
  v13 = *(uint32_t *)(v11 + 72);
  v14 = loc_135564 + 696 * v9;
  v15 = *(uint16_t *)(loc_13557C + 0x1FC);
  v16 = *(uint32_t *)(v14 + 38);
  v14 += 38;
  *(uint32_t *)(v13 + 112) = v16;
  *(uint8_t *)(v13 + 108) = -80;
  *(uint16_t *)(v13 + 116) = *(uint16_t *)(v14 + 4);
  *(uint32_t *)(v13 + 118) = *(uint32_t *)(v12 + 100);
  v17 = *(uint32_t *)v14;
  *(uint16_t *)(v13 + 122) = *(uint16_t *)(v12 + 104);
  ++v15;
  *(uint16_t *)(v13 + 128) = *(uint16_t *)(v14 + 4);
  *(uint32_t *)(v13 + 124) = v17;
  *(uint8_t *)(v13 + 109) = 0;
  *(uint8_t *)(v13 + 110) = 0;
  *(uint8_t *)(v13 + 111) = 0;
  v18 = 16 * v15;
  *(uint16_t *)(loc_13557C + 0x1FC) = v15;
  LOBYTE(v15) = *(uint8_t *)(v12 + 107);
  *(uint16_t *)(v13 + 130) = v18;
  *(uint8_t *)(v11 + 28) = v15;
  *(uint8_t *)(v11 + 29) = *(uint8_t *)(v12 + 116);
  *(uint8_t *)(v11 + 51) = 0;
  *(uint8_t *)(v11 + 53) = 0;
  v19 = *(unsigned __int8 *)(v4 + 59);
  v20 = v13 + 108;
  if ( v19 == 1 && a1 == 3 )
  {
    sub_13B13C(v11, v13 + 108, 24);
    LOWORD(v19) = *(unsigned __int8 *)(v4 + 59);
    v21 = *(unsigned __int8 *)(v11 + 51) + 24;
  }
  else
  {
    v21 = 24;
  }
  v22 = v21 + sub_130A20(v20 + v21, v19, a1, 0, a2);
  if ( *(uint8_t *)(v4 + 59) == 2 )
  {
    v26 = *(unsigned __int16 *)(v4 + 54);
    if ( 512 - v22 < v26 )
    {
      if ( *(__int16 *)*loc_135570 < 0 )
        sub_12F6C4(loc_135578, loc_135574, 1015);
    }
    else
    {
      v27 = (char *)(v4 + 64);
      if ( *(uint16_t *)(v4 + 54) )
      {
        v28 = &v27[v26];
        do
        {
          v29 = v27 - 64;
          v30 = *v27++;
          v29[v20 + v22 - v4] = v30;
        }
        while ( v27 != v28 );
        v26 = *(unsigned __int16 *)(v4 + 54);
      }
      v22 += v26;
    }
  }
  v23 = *(uint32_t **)(v11 + 76);
  v24 = *(unsigned __int8 *)(v11 + 53) + v22;
  v31 = *(uint32_t *)(*loc_135568 + 12);
  v23[8] = v23[7] - 1 + v24;
  v23[9] = v24 + 4;
  *(uint32_t *)(v11 + 88) = loc_13556C;
  *(uint32_t *)(v11 + 92) = v11;
  sub_1190B4(v11, 5);
  v2[34] = 1;
  rf_level_apply_80c(6154, 6, v31);
  return rf_bus_mark_n_3b7(6u, 5);
}

