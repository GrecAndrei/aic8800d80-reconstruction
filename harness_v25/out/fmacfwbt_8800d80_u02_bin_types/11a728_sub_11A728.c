// sub_11A728 @ 0x11a728, size 354 bytes
int  sub_11A728(int a1, int a2)
{
  uint64_t v2; // r6
  int *v3; // r10
  int v6; // r1
  int *v7; // r3
  int v8; // r2
  int v9; // t1
  int v10; // r4
  int v11; // r2
  unsigned int v12; // r0
  int v13; // r3
  int v14; // r3
  int v15; // r3
  uint16_t *v16; // r0
  char v17; // r3
  uint64_t v18; // kr08_8
  __int16 v19; // r3
  unsigned int v21; // r3
  int v22; // r0
  int v23; // r3
  unsigned int v24; // r3

  v2 = *(QWORD *)(a1 + 72);
  *(uint32_t *)(a1 + 36) = 0;
  *(uint32_t *)(a1 + 68) = 0;
  *(uint32_t *)(HIDWORD(v2) + 20) = 0;
  *(uint32_t *)(HIDWORD(v2) + 68) = 256;
  if ( (uint32_t)v2 )
  {
    v3 = *(int **)(a1 + 44);
    v6 = (int)(v3 + 16);
    v7 = v3;
    v8 = v2 + 40;
    do
    {
      v9 = *v7++;
      *(uint32_t *)(v8 + 4) = v9;
      v8 += 4;
    }
    while ( v7 != (int *)v6 );
    if ( (*(uint16_t *)(a1 + 30) & 0x2000) != 0 )
    {
      v10 = *(uint32_t *)(dword_11A890 + 696 * *(unsigned __int8 *)(a1 + 29) + 340);
      if ( **(__int16 **)off_11A88C >= 0 || v10 )
      {
        v11 = HIDWORD(v2);
      }
      else
      {
        sub_12F694(dword_11A898, dword_11A894, 475);
        v11 = *(uint32_t *)(a1 + 76);
      }
      v12 = *(uint32_t *)(v10 + 156);
      *(uint32_t *)(v2 + 68) = v3[5];
      v13 = *(uint32_t *)(v10 + 160);
      *(uint32_t *)(v2 + 84) = v3[9];
      v6 = (v12 >> 11) & 5;
      *(uint32_t *)(v2 + 64) = v12;
      *(uint32_t *)(v2 + 80) = v13;
      if ( v6 == 5 )
      {
        v6 = *(unsigned __int8 *)(v10 + 165);
        v21 = v13 & 0xFFFCFFFF;
        if ( (v12 & 0x600) == 0x400 )
          v22 = 0x20000;
        else
          v22 = 0x10000;
        v23 = v21 | v22;
        if ( *(uint8_t *)(v10 + 165) )
          v24 = v23 | 0x40000;
        else
          v24 = v23 & 0xFFFBFFFF;
        *(uint32_t *)(v2 + 80) = v24;
      }
      if ( (v3[15] & 4) == 0 )
        *(uint32_t *)(v2 + 48) &= 0xFFFFFE7F;
      if ( a2 )
        goto LABEL_16;
      v14 = *(unsigned __int16 *)(a1 + 30);
      v6 = v14 << 18;
      if ( (v14 & 0x2000) != 0 )
      {
        v15 = (*(uint32_t *)(*(uint32_t *)(a1 + 44) + 60) >> 4) & 1;
        goto LABEL_13;
      }
      v3 = *(int **)(a1 + 44);
    }
    else
    {
      v11 = HIDWORD(v2);
      if ( a2 )
      {
LABEL_16:
        *(uint8_t *)(v11 + 1) = 1;
        sub_11C9C8(a1, v6);
        v18 = *(QWORD *)(v2 + 96);
        v19 = *(uint16_t *)(a1 + 82) | 6;
        *(uint32_t *)(HIDWORD(v2) + 44) = HIDWORD(v18);
        *(uint32_t *)(HIDWORD(v2) + 48) = v2 + 44;
        *(uint32_t *)(HIDWORD(v2) + 64) = v18;
        *(uint16_t *)(a1 + 82) = v19;
        return HIDWORD(v2) + 12;
      }
    }
    v15 = ((unsigned int)v3[15] >> 3) & 1;
LABEL_13:
    if ( !v15 )
    {
      v16 = *(uint16_t **)(HIDWORD(v2) + 28);
      v6 = (unsigned __int16)*v16;
      if ( (*v16 & 0x8000) != 0 )
      {
        *v16 = v6 & 0x7FFF;
        v17 = *(uint8_t *)(a1 + 50) - 4;
        *(uint8_t *)(a1 + 51) -= 4;
        *(uint8_t *)(a1 + 50) = v17;
        v6 = *(uint32_t *)(HIDWORD(v2) + 36) - 4;
        *(uint32_t *)(HIDWORD(v2) + 32) -= 4;
        *(uint32_t *)(HIDWORD(v2) + 36) = v6;
      }
    }
    goto LABEL_16;
  }
  return 0;
}

