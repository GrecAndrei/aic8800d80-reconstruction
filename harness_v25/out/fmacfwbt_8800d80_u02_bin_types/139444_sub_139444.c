// sub_139444 @ 0x139444, size 546 bytes
int  sub_139444(int a1, int a2)
{
  uint16_t *v2; // r6
  int v3; // r7
  int v5; // r4
  int v7; // r12
  int v8; // r9
  int v9; // r1
  int v10; // r7
  int v11; // r3
  __int16 v12; // r3
  unsigned int v13; // r1
  int v14; // r2
  int v16; // r4
  int v17; // r0
  uint32_t *v18; // r2
  int v19; // r3
  int v20; // r2
  __int16 v21; // r2
  __int16 v22; // r3
  int v23; // r9
  __int16 *v24; // r2
  unsigned int v25; // r3
  __int16 v26; // r3
  __int16 v27; // r3

  v2 = off_139668;
  v3 = dword_13966C + 1320 * *((unsigned __int8 *)off_139668 + 10);
  v5 = *(unsigned __int8 *)(v3 + 1227);
  if ( !*(uint8_t *)(v3 + 1227) )
  {
    v7 = *((unsigned __int8 *)off_139668 + 7);
    v8 = dword_139684;
    v9 = *((unsigned __int16 *)off_139668 + 2);
    v10 = *(uint32_t *)(dword_139684 + 4 * (v7 + 174 * a2 + 102));
    v11 = *(unsigned __int16 *)(v10 + 8);
    if ( v11 != v9 )
      goto LABEL_3;
    goto LABEL_28;
  }
  v8 = dword_139684;
  v17 = sub_138BAC((unsigned __int8 *)(v3 + 107), (uint32_t *)(v3 + 1228), *(char **)(*(uint32_t *)(a1 + 28) + 8), 1);
  v7 = *((unsigned __int8 *)v2 + 7);
  v9 = (unsigned __int16)v2[2];
  v10 = *(uint32_t *)(v8 + 4 * (v7 + 174 * a2 + 102));
  v11 = *(unsigned __int16 *)(v10 + 8);
  v5 = v17 == 1;
  if ( v9 == v11 )
  {
LABEL_15:
    if ( v5 )
    {
      v16 = 0;
LABEL_17:
      v18 = off_139670;
      *(uint8_t *)(v10 + 288) = 1;
      v19 = *(unsigned __int8 *)(v10 + 10);
      *(uint32_t *)(v10 + 4) = v18[4];
      v20 = v10 + 4 * v19;
      if ( *(uint32_t *)(v20 + 16) )
      {
        *(uint32_t *)(v20 + 16) = 0;
        --*(uint8_t *)(v10 + 11);
      }
      v21 = (*(uint16_t *)(v10 + 8) + 1) & 0xFFF;
      *(uint8_t *)(v10 + 10) = (v19 + 1) & 0x3F;
      *(uint16_t *)(v10 + 8) = v21;
      sub_138A5C(v10);
      sub_13C4C0(a2, *((unsigned __int8 *)v2 + 7));
      return v16;
    }
LABEL_28:
    v26 = *(uint16_t *)(a1 + 50) & 0xFF00;
    *(uint32_t *)(a1 + 96) |= 0x20u;
    *(uint16_t *)(a1 + 50) = v26;
    sub_138DB8(a1, 3);
    v16 = 1;
    goto LABEL_17;
  }
LABEL_3:
  while ( 1 )
  {
    v12 = v9 - v11;
    v13 = v12 & 0xFFF;
    if ( (v12 & 0xFC0) == 0 )
      break;
    if ( v13 > 0x7FE )
    {
      if ( !*(uint8_t *)(v10 + 288) )
      {
        if ( (*v2 & 0x800) == 0 )
        {
          LOWORD(v14) = v2[1];
LABEL_8:
          *(uint16_t *)(v8 + 2 * (v7 + 348 * a2) + 554) = v14;
          if ( !v5 )
          {
            v22 = *(uint16_t *)(a1 + 50) & 0xFF00;
            *(uint32_t *)(a1 + 96) |= 0x20u;
            *(uint16_t *)(a1 + 50) = v22;
            sub_138DB8(a1, 3);
          }
LABEL_10:
          sub_13C4C0(a2, *((unsigned __int8 *)v2 + 7));
          return (unsigned __int8)(1 - v5);
        }
        v14 = (unsigned __int16)v2[1];
        if ( *(unsigned __int16 *)(v8 + 2 * (v7 + 348 * a2) + 554) != v14 )
          goto LABEL_8;
      }
      return 0;
    }
    sub_1393AC(v10, (unsigned __int16)(v13 - 63));
    v7 = *((unsigned __int8 *)v2 + 7);
    v9 = (unsigned __int16)v2[2];
    v10 = *(uint32_t *)(v8 + 4 * (174 * a2 + v7 + 102));
    v11 = *(unsigned __int16 *)(v10 + 8);
    if ( v9 == v11 )
      goto LABEL_15;
  }
  v23 = v10 + 4 * ((*(uint8_t *)(v10 + 10) + (uint8_t)v12) & 0x3F);
  *(uint8_t *)(v10 + 288) = 1;
  if ( !*(uint32_t *)(v23 + 16) )
  {
    if ( !v5 )
    {
      v27 = *(uint16_t *)(a1 + 50) & 0xFF00;
      *(uint32_t *)(a1 + 96) |= 0x20u;
      *(uint16_t *)(a1 + 50) = v27;
      sub_138DB8(a1, 3);
    }
    *(uint32_t *)(v23 + 16) = dword_139674;
    v24 = *(__int16 **)off_139678;
    v25 = (unsigned __int8)(*(uint8_t *)(v10 + 11) + 1);
    *(uint8_t *)(v10 + 11) = v25;
    if ( *v24 < 0 && v25 > 0x40 )
    {
      sub_12F694(dword_139680, dword_13967C, 1860);
      v25 = *(unsigned __int8 *)(v10 + 11);
    }
    if ( v25 == 1 )
      sub_124F60(v10 + 272, *((uint32_t *)off_139670 + 4) + 50000);
    goto LABEL_10;
  }
  return 0;
}

