// sub_13AA68 @ 0x13aa68, size 882 bytes
int  sub_13AA68(int a1, int a2)
{
  unsigned int v2; // r6
  int v5; // r3
  int v6; // r7
  int v7; // r3
  __int16 v9; // r0
  int v10; // r2
  uint8_t *v11; // r7
  int v12; // r3
  __int16 v13; // r8
  int v14; // r6
  int v15; // r8
  uint8_t *v16; // r9
  __int16 **v17; // r10
  int v18; // r11
  int v19; // r7
  unsigned int v20; // r0
  signed int v21; // r1
  unsigned int v22; // r0
  char v23; // r2
  int v24; // r9
  uint8_t *v25; // r8
  int v26; // r3
  unsigned int v27; // r6
  uint32_t *v28; // r7
  uint8_t *v29; // r3
  __int16 v30; // r3
  int v31; // r0
  void *v32; // r3
  int v33; // r0
  uint32_t *v34; // r0
  int v35; // r2
  int v36; // r0
  char v37; // r2
  uint32_t *v38; // r0
  int v39; // r1
  char v40; // [sp+4h] [bp-10h]
  int v41; // [sp+Ch] [bp-8h] BYREF

  v2 = *(unsigned __int8 *)(a1 + 28);
  if ( v2 > 3 )
    return sub_13A9B4(a1, a2, 0x80000000);
  v5 = *(unsigned __int8 *)(a1 + 29);
  if ( v5 == 255 )
  {
    if ( (*(uint16_t *)(a1 + 30) & 8) == 0 )
    {
      sub_12E948(dword_13AD98);
      return sub_13A9B4(a1, a2, 0x80000000);
    }
    goto LABEL_11;
  }
  v6 = dword_13AD6C;
  v7 = dword_13AD6C + 696 * v5;
  if ( !*(uint8_t *)(v7 + 37) || *(uint8_t *)(v7 + 48) )
    return sub_13A9B4(a1, a2, 0x80000000);
  v9 = *(uint16_t *)(a1 + 30);
  if ( (v9 & 8) != 0 )
  {
LABEL_11:
    v11 = off_13AD74;
    v12 = *((unsigned __int8 *)off_13AD74 + 13);
    v41 = 0;
    if ( v12 && (*((uint8_t *)off_13AD74 + 15) & 6) == 2 && (*(uint16_t *)(*(uint32_t *)(a1 + 72) + 172) & 0xFC) == 0xB0 )
    {
      sub_12C4A4(6155, 6, dword_13AD78);
      sub_10D0F4();
      v11[15] |= 4u;
    }
    v13 = *(uint16_t *)(a1 + 30);
    v14 = dword_13AD7C + 1320 * v2;
    if ( (v13 & 0x10) != 0 || *(uint8_t *)(v14 + 1224) )
    {
      *(uint32_t *)(a1 + 44) = off_13AD80;
    }
    else
    {
      v32 = off_13AD84;
      if ( *(uint8_t *)(*(uint32_t *)(v14 + 72) + 4) )
        v32 = off_13AD80;
      *(uint32_t *)(a1 + 44) = v32;
    }
    v15 = v13 & 0x80;
    if ( v15 )
    {
      v33 = sub_13C558(a1, 192, 0);
      if ( v33 == 1 )
      {
        LOBYTE(v15) = sub_13A3E8(a1, &v41);
        sub_143630(*(uint32_t *)(a1 + 72) + 164, *(uint32_t *)(a1 + 72) + 172, 24);
        v40 = 24;
      }
      else
      {
        LOBYTE(v15) = 0;
        if ( v33 == 2 )
          v41 = 18;
        else
          *(uint16_t *)(a1 + 30) &= ~0x80u;
        v40 = 0;
      }
    }
    else
    {
      v40 = 0;
    }
    v16 = off_13AD88;
    v17 = (__int16 **)off_13AD8C;
    v18 = dword_13ADA0;
    v19 = 0;
    while ( 1 )
    {
      v20 = *(uint32_t *)(a1 + 8);
      v21 = v20 & 0x7F;
      if ( (v20 & 0x40000000) != 0 )
      {
        v22 = (v20 >> 11) & 7;
        *(uint32_t *)(*(uint32_t *)(a1 + 44) + 4 * v19 + 20) = *(uint32_t *)(a1 + 8) & 0x387F | 0x20000000;
        if ( !v16[197] )
          goto LABEL_22;
      }
      else
      {
        v22 = (*(uint32_t *)(*(uint32_t *)(a1 + 44) + 4 * v19 + 20) >> 11) & 7;
        v21 = *(uint32_t *)(*(uint32_t *)(a1 + 44) + 4 * v19 + 20) & 0x7F;
        if ( !v16[197] )
        {
LABEL_22:
          if ( **v17 < 0 )
            sub_12F32C(dword_13AD90, v18, 414);
          goto LABEL_24;
        }
      }
      v31 = sub_101CAC(v22, v21, (unsigned __int8 *)(*(uint32_t *)(v14 + 72) + 4));
      *(uint32_t *)(*(uint32_t *)(a1 + 44) + 4 * v19 + 36) = v31 | (v31 << 8);
LABEL_24:
      if ( ++v19 == 4 )
      {
        *(uint8_t *)(a1 + 50) = v40;
        *(uint32_t *)(a1 + 36) = 0;
        *(uint32_t *)(a1 + 40) = 0;
        v23 = v41;
        *(uint8_t *)(a1 + 51) = v15;
        *(uint8_t *)(a1 + 66) = v15;
        *(uint8_t *)(a1 + 53) = v23;
        return sub_117424(a1, a2);
      }
    }
  }
  v10 = *(unsigned __int8 *)(v7 + 52);
  if ( *(unsigned __int16 *)(v7 + 56) == (unsigned __int16)__rev16(*(unsigned __int16 *)(a1 + 24)) )
  {
    *(uint16_t *)(a1 + 30) = v9 & 0xFEFF;
    if ( (unsigned int)(v10 - 1) > 1 )
      goto LABEL_9;
  }
  else if ( v10 != 2 )
  {
LABEL_9:
    sub_12EB90(32, dword_13AD70);
    return sub_13A9B4(a1, a2, 0x80000000);
  }
  v24 = dword_13AD7C;
  v25 = (uint8_t *)(dword_13AD7C + 1320 * v2);
  if ( !v25[108] )
  {
    sub_12E948(dword_13AD94);
    return sub_13A9B4(a1, a2, 0x80000000);
  }
  sub_13A514(a1);
  v26 = v6 + 696 * *(unsigned __int8 *)(a1 + 29);
  if ( *(uint8_t *)(v26 + 52) != 2 )
    goto LABEL_30;
  if ( v25[106] )
  {
    if ( v25[106] != 2 || !*(uint8_t *)(v26 + 688) )
      goto LABEL_52;
LABEL_30:
    v27 = v24 + 1320 * v2;
    v28 = off_13AD84;
    v29 = off_13AD88;
    if ( *(uint8_t *)(*(uint32_t *)(v27 + 72) + 4) )
      v28 = off_13AD80;
    *(uint32_t *)(a1 + 44) = v28;
    if ( v29[197] )
    {
      v36 = sub_101CAC((v28[5] >> 11) & 7, v28[5] & 0x7F, (unsigned __int8 *)(*(uint32_t *)(v27 + 72) + 4));
      v30 = *(uint16_t *)(a1 + 30);
      v28[9] = v36 | (v36 << 8);
    }
    else
    {
      if ( **(__int16 **)off_13AD8C < 0 )
        sub_12F32C(dword_13ADE0, dword_13ADDC, 1195);
      v30 = *(uint16_t *)(a1 + 30);
    }
    goto LABEL_36;
  }
  if ( v25[149] )
    goto LABEL_30;
LABEL_52:
  if ( !*(uint8_t *)off_13AD9C )
    sub_13BFD8(a1);
  sub_1400C4(a1);
  v34 = sub_1327C4(v6 + 696 * *(unsigned __int8 *)(a1 + 29));
  v30 = *(uint16_t *)(a1 + 30);
  *(uint32_t *)(a1 + 44) = v34;
  if ( (v30 & 0x2000) != 0 )
  {
    v35 = *(uint32_t *)(v6 + 696 * *(unsigned __int8 *)(a1 + 29) + 340);
    *(uint32_t *)(a1 + 40) = *(uint32_t *)(v35 + 156);
    if ( *(uint8_t *)(v35 + 165) )
      *(uint8_t *)(a1 + 54) |= 0x20u;
  }
  else
  {
    v37 = *(uint8_t *)(a1 + 54);
    v38 = &v34[v37 & 3];
    v39 = v38[9];
    *(uint32_t *)(a1 + 40) = v38[5];
    if ( (v39 & 0x40000) != 0 )
      *(uint8_t *)(a1 + 54) = v37 | 0x20;
  }
LABEL_36:
  if ( (v30 & 1) == 0 )
    sub_13AA30(a1, (uint16_t *)(*(uint32_t *)(a1 + 72) + 172));
  return sub_117424(a1, a2);
}

