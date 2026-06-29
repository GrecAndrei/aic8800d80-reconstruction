// sub_119D88 @ 0x119d88, size 440 bytes
int  sub_119D88(int a1)
{
  int v1; // r8
  int v2; // r3
  int v3; // r5
  int v4; // r6
  uint64_t v5; // kr00_8
  int v7; // r10
  __int16 v8; // r3
  uint8_t *v9; // r2
  int v11; // r4
  char v12; // r3
  int v13; // r0
  void *v14; // r11
  __int16 v15; // r2
  int v16; // r7
  unsigned int v17; // r0
  uint8_t *v18; // r3
  int v19; // r7
  int v20; // [sp+Ch] [bp-8h]

  v1 = dword_119F48;
  v2 = dword_119F48 + 84 * a1;
  v3 = *(uint32_t *)(v2 + 52);
  v4 = *(uint32_t *)(v2 + 44);
  v5 = *(QWORD *)(v3 + 72);
  v7 = HIDWORD(v5) + 12;
  if ( *(uint8_t *)(v2 + 77) == 1 )
  {
    *(uint32_t *)(v3 + 36) = 0;
    *(uint32_t *)(HIDWORD(v5) + 20) = 0;
    *(uint32_t *)(HIDWORD(v5) + 68) = 256;
    *(uint32_t *)(v3 + 68) = 0;
    if ( (uint32_t)v5 )
      sub_1161E4(v3, a1);
    v8 = *(uint16_t *)(v4 + 8);
    if ( (v8 & 2) != 0 )
    {
      v9 = off_119F40;
      *(uint16_t *)(v3 + 82) |= 2u;
      if ( v9[197] )
      {
        v19 = *(uint32_t *)(HIDWORD(v5) + 48);
        if ( v19 )
          *(uint8_t *)(v19 + 36) = sub_101CAC(
                                   (*(uint32_t *)(v19 + 20) >> 11) & 7,
                                   *(uint32_t *)(v19 + 20) & 0x7F,
                                   (unsigned __int8 *)(*(uint32_t *)(dword_119F44
                                                                 + 1320 * *(unsigned __int8 *)(v3 + 28)
                                                                 + 72)
                                                     + 4));
      }
      sub_116860(v7, v7, a1);
    }
    else if ( (v8 & 4) != 0 )
    {
      *(uint16_t *)(v3 + 82) |= 2u;
    }
    else if ( (uint32_t)v5 )
    {
      *(uint16_t *)(v3 + 82) |= 2u;
      sub_115F60(a1, v5);
    }
    sub_12D108(*(uint32_t *)(v4 + 340));
  }
  else
  {
    v13 = *(uint32_t *)(v2 + 48);
    v20 = v2;
    *(uint32_t *)(v3 + 36) |= 0x380000u;
    *(uint32_t *)(v4 + 324) = v3;
    sub_11C410(v13);
    v14 = off_119F4C;
    *(uint8_t *)(HIDWORD(v5) + 1) = *(uint8_t *)(v20 + 77);
    if ( *(uint8_t *)(*(uint32_t *)v14 + 1) )
    {
      sub_11927C(
        v4,
        *(uint16_t *)(v3 + 34),
        *(unsigned __int8 *)(v4 + 12),
        *(unsigned __int8 *)(v4 + 13),
        *(uint8_t *)(v20 + 78));
      *(uint32_t *)(HIDWORD(v5) + 20) = v4 + 84;
    }
    else
    {
      *(uint32_t *)(v4 + 20) = *(unsigned __int8 *)(*(uint32_t *)v14 + 1);
    }
    v15 = *(uint16_t *)(v4 + 8);
    *(uint32_t *)(HIDWORD(v5) + 68) = *(uint32_t *)(v3 + 36) | 0x100;
    *(uint16_t *)(v4 + 8) = v15 | 1;
    if ( (v15 & 2) != 0 )
    {
      if ( *(uint8_t *)(*(uint32_t *)v14 + 1) )
        v7 = v4 + 84;
      v16 = *(uint32_t *)(v4 + 52);
      v17 = *(uint32_t *)(v4 + 4);
      v18 = off_119F40;
      *(uint32_t *)(v16 + 20) = v17;
      if ( v18[197] && v16 )
        *(uint8_t *)(v16 + 36) = sub_101CAC(
                                 (v17 >> 11) & 7,
                                 v17 & 0x7F,
                                 (unsigned __int8 *)(*(uint32_t *)(dword_119F44 + 1320 * *(unsigned __int8 *)(v3 + 28) + 72)
                                                   + 4));
      sub_116860(v4 + 16, v7, a1);
    }
    else if ( (uint32_t)v5 && (v15 & 4) == 0 )
    {
      *(uint16_t *)(v4 + 8) = v15 | 5;
      sub_115F60(a1, v5);
    }
    sub_12D108(v1 + 84 * a1 + 28);
  }
  v11 = v1 + 84 * a1;
  v12 = *(uint8_t *)(v11 + 80);
  *(uint32_t *)(v11 + 44) = 0;
  *(uint8_t *)(v11 + 80) = v12 + 1;
  return 84;
}

