// udelay_50 @ 0x109120
volatile uint32_t * udelay_50(volatile uint32_t *result, volatile unsigned int *a2) {
  int v2; // r3
  int v3; // r3
  int v4; // r3
  int v5; // r3
  int v6; // r2
  int v7; // r3
  unsigned int v8; // r3

  v2 = (v2 & ~0xFFFFu) | ((uint16_t)(50) & 0xFFFFu);
  do
    v2 = (uint16_t)(v2 - 1);
  while ( v2 );
  *(volatile uint32_t *)off_109194 = 2;
  v3 = (v3 & ~0xFFFFu) | ((uint16_t)(50) & 0xFFFFu);
  do
    v3 = (uint16_t)(v3 - 1);
  while ( v3 );
  if ( (*(volatile uint32_t *)off_109198 & 1) == 0 )
  {
    while ( 1 )
    {
      v4 = (v4 & ~0xFFFFu) | ((uint16_t)(50) & 0xFFFFu);
      do
        v4 = (uint16_t)(v4 - 1);
      while ( v4 );
      if ( (*(volatile uint32_t *)off_109198 & 1) != 0 )
      {
        v5 = (v5 & ~0xFFFFu) | ((uint16_t)(50) & 0xFFFFu);
        do
          v5 = (uint16_t)(v5 - 1);
        while ( v5 );
        if ( (*(volatile uint32_t *)off_109198 & 1) != 0 )
          break;
      }
    }
  }
  v6 = *(volatile uint32_t *)off_109198;
  v7 = *(volatile uint32_t *)off_109198 >> 17;
  if ( *(volatile int *)off_109198 < 0 )
    v7 = ~((unsigned int)~(v7 << 17) >> 17);
  *result = v7;
  v8 = (uint16_t)v6 >> 1;
  if ( (v6 & 0x8000) != 0 )
    v8 = ~(~(v8 << 17) >> 17);
  *a2 = v8;
  return result;
}



// mac_cmd_dispatch @ 0x109350
int mac_cmd_dispatch(int result, int a2, volatile uint8_t *a3, volatile char *a4, volatile int *a5) {
  unsigned int v5; // r3
  uint64_t v6; // kr00_8
  char v7; // r3
  char v8; // r3
  int v9; // r3
  char v10; // r3
  char v11; // r3
  char v12; // r3
  int v13; // r4
  char v14; // r3
  int v15; // r3
  char v16; // r3
  int savedregs; // [sp+0h] [bp+0h]
  int savedregs_4; // [sp+4h] [bp+4h]

  if ( a2 == 15 )
  {
    if ( result == 1 )
    {
      v15 = *a5;
      if ( *a5 >= 0x2000 )
      {
        *a4 = 48;
      }
      else if ( v15 <= 0 )
      {
        if ( v15 > -8192 )
          v16 = -80;
        else
          v16 = -48;
        *a4 = v16;
      }
      else
      {
        *a4 = 80;
      }
    }
    else if ( result == 2 )
    {
      savedregs_4 = savedregs;
      v13 = *a5;
      if ( *a5 >= 0x2000 )
      {
        a4[1] = *a4 + 16;
        *a3 = 1;
        return 1;
      }
      else if ( v13 <= 0 )
      {
        if ( v13 > -8192 )
        {
          if ( a5[1] <= 0 )
            result = 6;
          else
            result = 5;
          a4[1] = *a4 - 16;
          *a3 = result;
        }
        else
        {
          a4[1] = *a4 - 16;
          *a3 = 4;
          return 4;
        }
      }
      else
      {
        v14 = *a4;
        if ( a5[1] < 0 )
          v14 += 16;
        else
          result = 3;
        if ( a5[1] >= 0 )
          v14 -= 16;
        a4[1] = v14;
        *a3 = result;
      }
    }
    else
    {
      switch ( *a3 )
      {
        case 1:
          if ( a5[2] <= 0 )
            goto LABEL_62;
          a4[2] = 32;
          break;
        case 2:
          if ( a5[2] <= 0 )
            goto LABEL_64;
          a4[2] = 64;
          break;
        case 3:
          a4[2] = 56;
          break;
        case 4:
          if ( a5[2] <= 0 )
            a4[2] = -32;
          else
LABEL_64:
            a4[2] = -112;
          break;
        case 5:
          if ( a5[2] <= 0 )
            a4[2] = -64;
          else
LABEL_62:
            a4[2] = 112;
          break;
        case 6:
          a4[2] = -56;
          break;
        default:
          a4[2] = -120;
          break;
      }
    }
  }
  else if ( result == 1 )
  {
    v9 = *a5;
    if ( *a5 >= 0x2000 )
    {
      *a4 = 32;
    }
    else if ( v9 <= 0 )
    {
      if ( v9 > -8192 )
        v10 = -64;
      else
        v10 = -32;
      *a4 = v10;
    }
    else
    {
      *a4 = 64;
    }
  }
  else if ( result == 2 )
  {
    v6 = *(volatile uint64_t *)a5;
    if ( *a5 <= 0 )
    {
      if ( SHIDWORD(v6) <= 0 )
      {
        v11 = *a4;
        if ( (int)v6 >= 2 * HIDWORD(v6) )
          v12 = v11 + 24;
        else
          v12 = v11 + 16;
        a4[1] = v12;
      }
      else
      {
        a4[1] = *a4 - 32;
      }
    }
    else if ( v6 < 0 )
    {
      a4[1] = *a4 + 32;
    }
    else
    {
      v7 = *a4;
      if ( (int)v6 <= 2 * HIDWORD(v6) )
        v8 = v7 - 24;
      else
        v8 = v7 - 16;
      a4[1] = v8;
    }
  }
  else
  {
    v5 = (uint8_t)a4[1];
    if ( v5 <= 0x10 )
    {
LABEL_7:
      a4[2] = 48;
      return result;
    }
    if ( v5 <= 0x30 )
    {
      a4[2] = 24;
      return result;
    }
    if ( v5 > 0x60 )
    {
      if ( v5 > 0xC0 )
      {
        if ( v5 <= 0xD8 )
        {
          a4[2] = -24;
          return result;
        }
      }
      else
      {
        if ( a5[2] > 0 )
        {
          a4[2] = 96;
          return result;
        }
        if ( v5 == 160 )
        {
          a4[2] = -32;
          return result;
        }
      }
      a4[2] = -48;
      return result;
    }
    if ( a5[2] < 0 )
    {
      a4[2] = -96;
    }
    else
    {
      if ( v5 != 96 )
        goto LABEL_7;
      a4[2] = 32;
    }
  }
  return result;
}



// u64_set_or_add @ 0x109370
int u64_set_or_add(uint64_t a1, int a2, volatile uint32_t *a3) {
  uint8_t v3; // r5
  volatile uint32_t *v4; // r6
  int v5; // r4
  volatile uint32_t *v6; // r3

  if ( a1 )
  {
    a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)(HIDWORD(a1) + a1) & 0xFFFFFFFFu);
    if ( (uint32_t)a1 )
    {
      a1 = (a1 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(0) << 32);
      while ( 1 )
      {
        v3 = BYTE4(a1) + 1;
        v4 = &a3[HIDWORD(a1)];
        if ( *v4 <= a2 )
          break;
        a1 = (a1 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(v3) << 32);
        if ( v3 >= (int)a1 )
          goto LABEL_12;
      }
      a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)((uint8_t)a1) & 0xFFFFFFFFu);
      if ( (unsigned int)(uint8_t)a1 > HIDWORD(a1) )
      {
        v5 = (int)&a3[(uint8_t)a1 - 1 - (uint8_t)(a1 - 1 - BYTE4(a1))];
        v6 = &a3[(uint8_t)a1];
        do
        {
          *v6 = *(v6 - 1);
          --v6;
        }
        while ( v6 != (volatile uint32_t *)v5 );
      }
      *v4 = a2;
    }
    else
    {
LABEL_12:
      a3[(uint32_t)a1] = a2;
    }
  }
  else
  {
    *a3 = a2;
  }
  return a1;
}



// sub_1093d4 @ 0x1093d4
int sub_1093d4(unsigned int a1, int a2, volatile int *a3) {
  int v3; // r12
  int v4; // r4
  volatile int *v5; // r6
  unsigned int v6; // r5
  int v7; // r3
  int v9; // r7
  int v10; // t1
  int v11; // r1
  int v12; // r8
  unsigned int v13; // r0
  volatile int *v14; // r5
  int v15; // r7
  unsigned int v16; // r4
  int v17; // r6
  int v18; // lr
  int v19; // r8
  signed int v20; // r1
  int v22; // r11
  volatile uint8_t *v23; // r7
  volatile uint8_t *v24; // r1
  int v25; // r5
  int v26; // r3
  int v27; // r0
  int v28; // r1
  int v29; // r4
  volatile uint8_t *v30; // r5
  struct __attribute__((packed)) { int v31; // [sp+4h] [bp-10h]
  int v32; // [sp+8h] [bp-Ch] BYREF
  int16_t v33; // [sp+Ch] [bp-8h]
  char _pad3[2]; uint8_t v34[4]; // [sp+10h] [bp-4h] BYREF
  } _frame;
  v3 = (uint8_t)((a1 - 1) >> 1);
  _frame.v31 = v3;
  _frame.v32 = -2139062144;
  _frame.v33 = -32640;
  if ( a1 <= 1 )
    return a3[_frame.v31];
  v4 = 128;
  v5 = a3;
  v6 = 0;
  v7 = (v7 & ~0xFFu) | ((uint8_t)(1) & 0xFFu);
  while ( 1 )
  {
    v9 = *v5;
    v10 = v5[1];
    ++v5;
    if ( v9 - v10 > a2 )
      break;
    if ( v4 == 128 )
      *((volatile uint8_t *)&_frame.v32 + 2 * v6) = v7 - 1;
    _frame.v34[2 * v6 - 7] = v7;
LABEL_6:
    v7 = (uint8_t)(v7 + 1);
    if ( a1 == v7 )
      goto LABEL_14;
LABEL_7:
    v4 = *((volatile uint8_t *)&_frame.v32 + 2 * v6);
  }
  if ( v4 == 128 )
    goto LABEL_6;
  v11 = a3[v4];
  if ( v11 > 14000 )
  {
    v12 = *((volatile uint8_t *)&_frame.v32 + 2 * v6 + 1);
    goto LABEL_12;
  }
  v12 = *((volatile uint8_t *)&_frame.v32 + 2 * v6 + 1);
  v22 = a3[v12];
  if ( v22 < dword_1095B0 || v11 < 1000 && v22 >= dword_1095B4 )
  {
LABEL_12:
    if ( v12 >= v4 + v3 )
      goto LABEL_13;
    goto LABEL_27;
  }
  if ( v12 < v4 + 2 )
  {
LABEL_27:
    v23 = &_frame.v34[2 * v6];
    *(v23 - 8) = 0x80;
    *(v23 - 7) = 0x80;
    goto LABEL_6;
  }
LABEL_13:
  v7 = (uint8_t)(v7 + 1);
  v6 = (uint8_t)(v6 + 1);
  if ( a1 != v7 )
    goto LABEL_7;
LABEL_14:
  if ( v6 <= 2 )
  {
    v24 = &_frame.v34[2 * v6];
    v25 = 2 * v6;
    v26 = (uint8_t)*(v24 - 8);
    if ( v26 != 128 )
    {
      v27 = a3[v26];
      v28 = (uint8_t)*(v24 - 7);
      if ( v27 <= 14000 )
      {
        v29 = a3[v28];
        if ( v29 >= dword_1095B0 && (v27 >= 1000 || v29 <= -1000) )
          v3 = 2;
      }
      if ( v28 < v3 + v26 )
      {
        v30 = &_frame.v34[v25];
        *(v30 - 8) = 0x80;
        *(v30 - 7) = 0x80;
      }
    }
  }
  if ( (uint8_t)_frame.v32 != 128 )
  {
    v13 = (uint8_t)(BYTE1(_frame.v32) + 1 - _frame.v32);
    v14 = &_frame.v32;
    v15 = 1;
    v16 = (uint16_t)((a3[(uint8_t)_frame.v32] - a3[BYTE1(_frame.v32)]) / (int)v13);
    v17 = 0;
    while ( 1 )
    {
      v18 = *((volatile uint8_t *)v14 + 2);
      if ( v18 == 128 )
        break;
      v19 = *((volatile uint8_t *)v14 + 3);
      v20 = (uint8_t)(v19 + 1 - v18);
      if ( v20 > v13 )
      {
        v16 = (uint16_t)((a3[v18] - a3[v19]) / v20);
        v13 = (uint8_t)(v19 + 1 - v18);
        v17 = (uint8_t)v15;
        v14 = (volatile int *)((volatile char *)v14 + 2);
        if ( v15 == 2 )
          break;
      }
      else
      {
        if ( v20 == v13 && (uint16_t)((a3[v18] - a3[v19]) / v20) < v16 )
        {
          v16 = (uint16_t)((a3[v18] - a3[v19]) / v20);
          v17 = (uint8_t)v15;
        }
        v14 = (volatile int *)((volatile char *)v14 + 2);
        if ( v15 == 2 )
          break;
      }
      v15 = 2;
    }
    _frame.v31 = (uint8_t)(*((volatile uint8_t *)&_frame.v32 + 2 * v17)
                          + ((*((volatile uint8_t *)&_frame.v32 + 2 * v17 + 1) - *((volatile uint8_t *)&_frame.v32 + 2 * v17) + 1) >> 1));
  }
  return a3[_frame.v31];
}



// float_compare @ 0x1095b8
int float_compare(volatile float *a1, volatile float *a2) {
  float v2; // s15
  float v3; // s14
  float v4; // s13

  v2 = *a1;
  v3 = a1[1];
  if ( *a1 < v3 && *a2 >= a2[1] )
    return 2;
  if ( v2 > v3 && *a2 <= a2[1] )
    return 2;
  v4 = a1[2];
  if ( v2 < v4 && *a2 >= a2[2] )
    return 2;
  if ( v2 > v4 && *a2 <= a2[2] || v3 < v4 && a2[1] >= a2[2] || v3 > v4 && a2[1] <= a2[2] )
    return 2;
  if ( *a2 > 0.0 && a2[1] > 0.0 && a2[2] > 0.0 )
    return 1;
  if ( *a2 >= 0.0 || a2[1] >= 0.0 )
    return 0;
  return a2[2] < 0.0;
}



// sub_1096d0 @ 0x1096d0
int sub_1096d0(int a1, volatile int16_t *a2) {
  unsigned int v2; // r2
  volatile int16_t *v3; // r8
  volatile int16_t *v4; // r4
  unsigned int v5; // r7
  int v6; // r12
  int result; // r0
  int v8; // t1
  char v9; // r6
  int v10; // r3
  int v11; // r2
  char v12; // r4
  char v13; // r5
  int v14; // r9
  int v15; // r7
  char v16; // lr
  int v17; // r8
  int v18; // r2
  int v19; // r3
  int v20; // r7
  int v21; // r10
  char v22; // r2
  int v23; // r2
  int v24; // r8
  int v25; // r7
  int v26; // r3
  int v27; // r3
  int v28; // r4
  int v29; // r2
  int v30; // r2
  int j; // r3
  volatile int16_t *v32; // r3
  volatile int16_t *v33; // r1
  int v34; // t1
  int v35; // r4
  int v36; // r2
  int i; // r3
  unsigned int v38; // r3
  int v39; // r4
  volatile int16_t *v40; // r1
  uint8_t v41; // [sp+1h] [bp-27h]
  int16_t v42; // [sp+2h] [bp-26h]

  if ( !a1 )
  {
    v32 = a2 - 1;
    result = 128;
    v33 = a2 + 5;
    do
    {
      v34 = v32[1];
      ++v32;
      if ( v34 < 0 )
        *v32 = 128;
    }
    while ( v33 != v32 );
    return result;
  }
  v2 = 0;
  v3 = a2 - 1;
  v4 = a2 - 1;
  v5 = 0;
  v6 = 0;
  result = 0;
  while ( 1 )
  {
    v8 = v4[1];
    ++v4;
    v9 = v2;
    if ( v8 < 0 )
      break;
    if ( (uint8_t)v2 == 5 )
      goto LABEL_8;
LABEL_4:
    ++v2;
  }
  result = (uint8_t)((1 << v2) | result);
  if ( v2 <= 1 )
  {
    v6 = (uint8_t)(v6 + 1);
    goto LABEL_4;
  }
  v5 = (uint8_t)(v5 + 1);
  if ( (uint8_t)v2 != 5 )
    goto LABEL_4;
LABEL_8:
  if ( v5 == 4 )
  {
    if ( v6 == 2 )
    {
      v40 = a2 + 5;
      do
      {
        v3[1] = 128;
        ++v3;
      }
      while ( v3 != v40 );
      return result;
    }
  }
  else if ( v5 <= 2 )
  {
    if ( !v6 )
    {
      v10 = a2[1];
      v11 = *a2;
      if ( v10 + 9 < v11 || v11 < v10 - 9 )
        a2[1] = v11;
    }
    v12 = 3;
    v41 = 3;
    v42 = 1284;
    if ( a2[2] < a2[3] )
    {
      v13 = 2;
      v41 = 2;
      v14 = 2;
      v15 = 3;
      if ( a2[4] >= a2[5] )
        goto LABEL_48;
LABEL_16:
      v42 = 1029;
      v16 = 5;
      v17 = 4;
      v9 = 4;
      v18 = 5;
    }
    else
    {
      v13 = 3;
      v14 = 3;
      v15 = 2;
      v12 = 2;
      if ( a2[4] < a2[5] )
        goto LABEL_16;
LABEL_48:
      v17 = 5;
      v18 = 4;
      v16 = 4;
    }
    v19 = a2[v15];
    v20 = a2[v18];
    if ( v19 < v20 )
    {
      v21 = a2[v18];
      v22 = v16;
      v42 = (v42 & ~0xFFu) | ((uint8_t)(v12) & 0xFFu);
      v20 = v19;
      v16 = v12;
      v19 = v21;
      v12 = v22;
    }
    v23 = a2[v14];
    v24 = a2[v17];
    if ( v23 < v24 )
    {
      v42 = (v42 & ~0xFF00u) | (((uint8_t)(v13) & 0xFFu) << 8);
      v41 = v9;
      v23 = v24;
      v13 = v9;
    }
    if ( v20 > v23 )
    {
      v42 = (v42 & ~0xFFu) | ((uint8_t)(v13) & 0xFFu);
      v41 = v16;
      v23 = v20;
      v13 = v16;
    }
    v25 = a2[(uint8_t)v42];
    if ( v19 > v23 + 7 )
      v26 = 0;
    else
      v26 = 4;
    if ( a2[v41] <= v25 + 7 )
      v26 |= 2u;
    if ( a2[HIBYTE(v42)] + 7 >= v25 )
      v26 |= 1u;
    switch ( v26 )
    {
      case 0:
      case 5:
        if ( !v6 )
          result |= 0x3Cu;
        break;
      case 1:
        result = (uint8_t)(result | (1 << v12) | (1 << v13));
        break;
      case 2:
        result = (uint8_t)(result | (1 << SHIBYTE(v42)) | (1 << v12));
        break;
      case 3:
        result = (uint8_t)(result | (1 << v12));
        break;
      case 4:
        result = (uint8_t)(result | (1 << v42) | (1 << SHIBYTE(v42)));
        break;
      case 6:
        result = (uint8_t)(result | (1 << SHIBYTE(v42)));
        break;
      default:
        break;
    }
    v35 = 0;
    v36 = 0;
    for ( i = 2; i != 6; ++i )
    {
      if ( ((result >> i) & 1) == 0 )
      {
        v35 = (uint8_t)(v35 + 1);
        v36 = (int16_t)(v36 + a2[i]);
      }
    }
    if ( !v35 )
    {
      if ( (result & 1) == 0 )
      {
        v36 = (int16_t)(v36 + *a2);
        v35 = 1;
      }
      if ( (result & 2) == 0 )
      {
        v35 = (uint8_t)(v35 + 1);
        v36 = (int16_t)(a2[1] + v36);
      }
    }
    v38 = 0;
    v39 = v36 / v35;
    while ( 2 )
    {
      if ( ((result >> v38) & 1) != 0 )
      {
        if ( v38 > 1 || v6 == 2 )
        {
          a2[v38] = v39;
          goto LABEL_65;
        }
      }
      else
      {
LABEL_65:
        if ( (uint8_t)v38 == 5 )
        {
          if ( v6 == 1 )
          {
            if ( (result & 1) != 0 )
            {
              *a2 = a2[1];
            }
            else if ( (result & 2) != 0 )
            {
              a2[1] = *a2;
            }
          }
          return result;
        }
      }
      ++v38;
      continue;
    }
  }
  v27 = 0;
  v28 = 0;
  v29 = 0;
  do
  {
    if ( ((result >> v27) & 1) == 0 )
    {
      v28 = (uint8_t)(v28 + 1);
      v29 = (int16_t)(v29 + a2[v27]);
    }
    ++v27;
  }
  while ( v27 != 6 );
  v30 = v29 / v28;
  for ( j = 0; j != 6; ++j )
  {
    if ( ((result >> j) & 1) != 0 )
      a2[j] = v30;
  }
  return result;
}



// f32_compare @ 0x109988
int f32_compare(unsigned int a1, volatile float *a2, volatile float *a3, int a4) {
  float v4; // s13
  float v5; // s14
  float v10; // s15
  float v11; // s16
  float v12; // s19
  float v13; // s18
  float v14; // s20
  float v15; // s17
  float v16; // s21
  uint64_t v17; // r0
  float v18; // s10
  float v19; // s11
  float v20; // s15
  float v21; // s17
  float v22; // s16
  int result; // r0
  float v24; // s12
  float v25; // s15
  char v26; // r3
  uint64_t v27; // r0
  float v28; // s15
  float v29; // s13
  float v30; // s14
  float v31; // s9
  float v32; // s10
  float v33; // s11
  uint64_t v34; // r0

  v4 = a2[1];
  v5 = *a2;
  if ( v4 <= *a2 )
  {
    v4 = *a2;
    v5 = a2[1];
  }
  v10 = a2[2];
  if ( v10 <= v4 )
  {
    if ( v10 < v5 )
      v5 = a2[2];
    v10 = v4;
  }
  *(volatile uint8_t *)(a4 + 2) = (unsigned int)(float)(v10 - v5);
  v11 = *a2;
  v12 = a2[1];
  v13 = a2[2];
  v14 = (float)((float)(v11 * v11) + (float)(v12 * v12)) + (float)(v13 * v13);
  v15 = (float)(*a2 + v12) + v13;
  v16 = (float)(v14 * 3.0) - (float)(v15 * v15);
  if ( v16 > 0.0 )
  {
    v17 = ((uint64_t (*)())__aeabi_f2d)(COERCE_UNSIGNED_INT((float)(v14 * 3.0) - (float)(v15 * v15)));
if ( !((int (*)())__aeabi_dcmplt)(v17, *(volatile uint64_t *)&dword_109BF0) ) goto LABEL_11;
    v16 = flt_109BF8;
    goto LABEL_10;
  }
  v34 = ((uint64_t (*)())__aeabi_f2d)(COERCE_UNSIGNED_INT(-v16));
if ( ((int (*)())__aeabi_dcmplt)(v34, *(volatile uint64_t *)&dword_109BF0) ) { v16 = flt_109C08;
LABEL_10:
    *(volatile uint8_t *)a4 |= 4u;
    printf_wrapper(aDetectDivision);
    v11 = *a2;
    v12 = a2[1];
    v13 = a2[2];
  }
LABEL_11:
  v18 = a3[1];
  v19 = a3[2];
  v20 = -(float)((float)(1.0 / v16) * v15);
  v21 = (float)((float)((float)((float)((float)((float)(1.0 / v16) * 3.0) * v11) - (float)((float)(1.0 / v16) * v15))
                      * *a3)
              + (float)((float)((float)((float)((float)(1.0 / v16) * 3.0) * v12) - (float)((float)(1.0 / v16) * v15))
                      * v18))
      + (float)((float)((float)((float)((float)(1.0 / v16) * 3.0) * v13) - (float)((float)(1.0 / v16) * v15)) * v19);
  v22 = (float)((float)((float)((float)(v20 * v11) + (float)(v14 * (float)(1.0 / v16))) * *a3)
              + (float)((float)((float)(v20 * v12) + (float)(v14 * (float)(1.0 / v16))) * v18))
      + (float)((float)((float)(v20 * v13) + (float)(v14 * (float)(1.0 / v16))) * v19);
  if ( a1 > 0xD && v21 < 20.0
    || (v27 = ((uint64_t (*)())__aeabi_f2d)(COERCE_UNSIGNED_INT(v21)), (result = ((int (*)())__aeabi_dcmplt)(v27, *(volatile uint64_t *)&dword_109BF0)) != 0) )
  {
    *(volatile uint8_t *)a4 |= 8u;
    result = printf_wrapper(aSlopeTooSmall);
    v21 = 1.0;
    v24 = 2.0;
  }
  else
  {
    v24 = (float)(v21 * v21) + 1.0;
  }
  v25 = (float)-v22 / v21;
  if ( v25 > flt_109C04 )
  {
    v26 = -1;
  }
  else if ( v25 < 0.0 )
  {
    v26 = 0;
  }
  else
  {
    v26 = (unsigned int)(float)(v25 + 0.5);
  }
  *(volatile uint8_t *)(a4 + 1) = v26;
  v28 = *a2;
  v29 = a2[1];
  v30 = a2[2];
  v31 = *a3;
  v32 = a3[1];
  v33 = a3[2];
  *(volatile float *)(a4 + 12) = v22;
  *(volatile float *)(a4 + 8) = v21;
  *(volatile float *)(a4 + 4) = (float)((float)((float)((float)((float)((float)(v21 * v28) + v22) - v31)
                                             * (float)((float)((float)(v21 * v28) + v22) - v31))
                                     + (float)((float)((float)((float)(v21 * v29) + v22) - v32)
                                             * (float)((float)((float)(v21 * v29) + v22) - v32)))
                             + (float)((float)((float)((float)(v21 * v30) + v22) - v33)
                                     * (float)((float)((float)(v21 * v30) + v22) - v33)))
                     / v24;
  return result;
}


// invoke_handler_165fcc @ 0x109c0c
int invoke_handler_165fcc(int a1, volatile float *a2, int a3, int a4) {
  int v8; // r1
  int v9; // r2
  int v10; // r3
  int v11; // r1
  int v12; // r2
  int v13; // r3
  float v14; // r1
  float v15; // r0
  float v16; // r12
  float v17; // r4
  float v18; // r11
  int v19; // r8
  float v20; // r6
  volatile uint32_t *v21; // r6
  volatile float *v22; // r4
  volatile float *v23; // r7
  int v24; // t1
  float v25; // s16
  float v26; // s13
  float v27; // s15
  uint64_t v28; // r0
  uint64_t v29; // r8
  uint64_t v30; // r0
  uint64_t v31; // r8
  uint64_t v32; // r0
  uint64_t v33; // r0
  int v34; // r3
  int v35; // r7
  volatile uint32_t *v36; // r6
  volatile float *v37; // r4
  float v38; // s15
  volatile float *v39; // r12
  volatile uint32_t *v40; // r2
  volatile float *v41; // r3
  int v42; // r0
  int v43; // t1
  float v44; // s14
  float v45; // s17
  float v46; // s18
  float v47; // s19
  volatile float *v48; // r7
  int v49; // r8
  volatile float *v50; // r9
  int v51; // t1
  float v52; // s16
  volatile float *v53; // r5
  float v54; // s13
  struct __attribute__((packed)) { int v56; // [sp+0h] [bp-44h]
  int v57; // [sp+4h] [bp-40h]
  float a2a[3]; // [sp+8h] [bp-3Ch] BYREF
  float a3a[3]; // [sp+14h] [bp-30h] BYREF
  uint32_t v60[9]; // [sp+20h] [bp-24h] BYREF
  } _frame;
  v8 = ((volatile uint32_t *)(uintptr_t)off_109E30)[1];
  v9 = ((volatile uint32_t *)(uintptr_t)off_109E30)[2];
  v10 = ((volatile uint32_t *)(uintptr_t)off_109E30)[3];
  _frame.v60[0] = ((volatile uint32_t *)(uintptr_t)off_109E30)[0];
  _frame.v60[1] = v8;
  _frame.v60[2] = v9;
  _frame.v60[3] = v10;
  v11 = ((volatile uint32_t *)(uintptr_t)off_109E30)[5];
  v12 = ((volatile uint32_t *)(uintptr_t)off_109E30)[6];
  v13 = ((volatile uint32_t *)(uintptr_t)off_109E30)[7];
  _frame.v60[4] = ((volatile uint32_t *)(uintptr_t)off_109E30)[4];
  _frame.v60[5] = v11;
  _frame.v60[6] = v12;
  _frame.v60[7] = v13;
  v14 = a2[4];
  v15 = a2[34];
  v16 = a2[2];
  v17 = a2[36];
  _frame.a2a[1] = a2[3];
  v18 = 0.0;
  v19 = a1;
  _frame.a2a[2] = v14;
  _frame.a3a[0] = v15;
  v20 = a2[35];
  _frame.v57 = a1;
  _frame.a2a[0] = v16;
  a2[159] = 0.0;
  a2[160] = 0.0;
  _frame.v56 = a3;
  _frame.a3a[1] = v20;
  _frame.a3a[2] = v17;
  f32_compare(0, _frame.a2a, _frame.a3a, a4);
  if ( v19 > 0 )
  {
    v21 = _frame.v60;
    v22 = a2;
    v23 = &a2[v19];
    while ( ++v22 != v23 )
    {
      while ( 1 )
      {
        v24 = *((volatile uint8_t *)v21 + 1);
        v21 = (volatile uint32_t *)((volatile char *)v21 + 1);
        if ( v24 != 1 )
          break;
        v25 = *(volatile float *)(a4 + 8);
        v26 = v22[32];
        v27 = v25 * *v22++;
        v28 = ((uint64_t (*)())__aeabi_f2d)(COERCE_UNSIGNED_INT((float)(v27 - v26) + *(volatile float *)(a4 + 12)));
        v29 = ((uint64_t (*)())__aeabi_dmul)(v28, v28);
        v30 = ((uint64_t (*)())__aeabi_f2d)(COERCE_UNSIGNED_INT((float)(v25 * v25) + 1.0));
        v31 = ((uint64_t (*)())__aeabi_ddiv)(v29, v30);
        v32 = ((uint64_t (*)())__aeabi_f2d)(COERCE_UNSIGNED_INT(v18));
        v33 = __aeabi_dadd(v31, v32);
        v18 = COERCE_FLOAT(((int (*)(uint64_t))double_to_float)(v33));
        if ( v22 == v23 )
          goto LABEL_6;
      }
    }
  }
LABEL_6:
  if ( !_frame.v56 )
  {
    state_check_feature(1, aDpdBypassStatu);
    v34 = _frame.v57;
    if ( _frame.v57 > 0 )
      goto LABEL_8;
LABEL_20:
    v45 = flt_109E38;
    v46 = flt_109E38;
    v49 = _frame.v56;
    goto LABEL_18;
  }
  state_check_feature(1, aDbdCalAmpmTabl);
  v34 = _frame.v57;
  if ( _frame.v57 <= 0 )
    goto LABEL_20;
LABEL_8:
  v35 = 4 * v34 + 384;
  v36 = _frame.v60;
  v37 = a2 + 96;
  v38 = flt_109E38;
  v39 = (volatile float *)((volatile char *)a2 + v35);
  v40 = _frame.v60;
  v41 = a2 + 96;
  v42 = 0;
  while ( ++v41 != v39 )
  {
    while ( 1 )
    {
      v43 = *((volatile uint8_t *)v40 + 1);
      v40 = (volatile uint32_t *)((volatile char *)v40 + 1);
      if ( v43 != 1 )
        break;
      v44 = *v41++;
      v38 = v38 + v44;
      ++v42;
      if ( v41 == v39 )
        goto LABEL_12;
    }
  }
LABEL_12:
  v45 = (float)v42;
  v46 = flt_109E38;
  v47 = v38 / (float)v42;
  v48 = (volatile float *)((volatile char *)a2 + v35);
  v49 = _frame.v56;
  v50 = &a2[_frame.v56];
  while ( v48 != ++v37 )
  {
    while ( 1 )
    {
      v51 = *((volatile uint8_t *)v36 + 1);
      v36 = (volatile uint32_t *)((volatile char *)v36 + 1);
      if ( v51 != 1 )
        break;
      v52 = *v37 - v47;
      if ( (float)absolute_value((int)v52) > v50[159] )
        v50[159] = (float)absolute_value((int)v52);
      ++v37;
      v46 = v46 + (float)(v52 * v52);
      if ( v48 == v37 )
        goto LABEL_18;
    }
  }
LABEL_18:
  v53 = &a2[v49];
  v54 = flt_109E40;
  v53[128] = v18 / v45;
  v53[130] = v46 / v45;
  return state_check_feature(
           1,
           "am_var*1000000=%10d ph_var*1000000=%10d\n",
           (int)(float)((float)(v18 / v45) * v54),
           (int)(float)((float)(v46 / v45) * v54));
}


// mmio_set_bits @ 0x109e48
int mmio_set_bits( int a1, volatile int *a2, int a3, int a4, int a5, uint8_t a6, int a7, int a8, int a9, int a10, int a11) {
  volatile uint32_t *v11; // r4
  uint8_t v15; // r10
  volatile int *v16; // r5
  volatile int *v17; // r2
  volatile int *v18; // r3
  int v19; // r0
  volatile int *v20; // r4
  int v21; // t1
  int v22; // r6
  int v23; // t1
  int v24; // r1
  int v25; // t1
  int result; // r0
  volatile uint32_t *v27; // r3
  int v28; // r1
  volatile uint32_t *v29; // r2
  volatile uint32_t *v30; // r0
  volatile uint32_t *v31; // r1
  int v32; // r5
  volatile int *v33; // r3
  int v34; // t1
  uint8_t v35[20]; // [sp+18h] [bp-14h] BYREF

  v11 = (void *)(uintptr_t)(off_109F74);
  *(volatile uint32_t *)off_109F74 |= 0x400u;
  *v11 &= ~0x400u;
  v15 = a4;
  state_check_feature(1, "cal %x index\n", a1);
  if ( a5 )
  {
    bt_ccm_encrypt((int)a2, 1, 0x100000, 0x100000, 0, 1);
    return invoke_handler_165fcc(24, (volatile float *)a2, 1, (int)v35);
  }
  else
  {
    if ( a8 == 1 )
    {
      bt_ccm_encrypt((int)a2, 1, 0x100000, 0x100000, 0, 0);
      invoke_handler_165fcc(24, (volatile float *)a2, 0, (int)v35);
      v29 = (volatile uint32_t *)dword_109F7C;
      v30 = (volatile uint32_t *)dword_109F80;
      v31 = (volatile uint32_t *)dword_109F84;
      v32 = dword_109F7C + 128;
      v33 = a2;
      do
      {
        v34 = *v33++;
        *v29++ = v34;
        *v30++ = v33[31];
        *v31++ = v33[95];
      }
      while ( v29 != (volatile uint32_t *)v32 );
    }
    else
    {
      v16 = (volatile int *)dword_109F7C;
      v17 = (volatile int *)dword_109F80;
      v18 = (volatile int *)dword_109F84;
      v19 = dword_109F7C + 128;
      v20 = a2;
      do
      {
        v21 = *v16++;
        *v20++ = v21;
        v23 = *v17++;
        v22 = v23;
        v20[31] = v23;
        v25 = *v18++;
        v24 = v25;
        v20[95] = v25;
        v20[63] = v22;
      }
      while ( v16 != (volatile int *)v19 );
      bt_encrypt_wrap(a2, v24, a9, a10, (volatile uint64_t *)a11);
    }
    llm_pdu_handle(16, 32, (int)a2, a3, v15, 1, a6, a1, a7);
    result = (int)mac_tx_enable(a3);
    v27 = (void *)(uintptr_t)(off_109F88);
    v28 = dword_109F8C;
    *(volatile uint32_t *)off_109F88 &= ~0x200u;
    *v27 |= 0x200u;
    *v27 &= ~0x200u;
    a2[129] = v28;
    a2[131] = v28;
  }
  return result;
}


// dsp_filter_process @ 0x109f90
int dsp_filter_process( volatile uint32_t *a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) {
  volatile uint32_t *v11; // r10
  int v13; // r1
  int v14; // r2
  float v15; // s20
  int v17; // r7
  unsigned int v19; // r3
  int v20; // r11
  unsigned int v21; // r0
  volatile char *v22; // r7
  int v23; // r4
  float v24; // s16
  float v25; // s21
  float v26; // s22
  float v27; // s17
  int v28; // r8
  float v29; // s23
  float v30; // s16
  int v31; // s25
  unsigned int v32; // s15
  uint64_t v33; // r0
  int v34; // r3
  int v35; // cc
  int result; // r0
  volatile uint32_t *v37; // r3
  struct __attribute__((packed)) { int v38; // [sp+20h] [bp-20h]
  int v39; // [sp+24h] [bp-1Ch]
  char _pad2[4]; int v40; // [sp+2Ch] [bp-14h]
  int a1a; // [sp+30h] [bp-10h]
  volatile int *v42; // [sp+34h] [bp-Ch]
  volatile int *v43; // [sp+38h] [bp-8h]
  volatile unsigned int *v44; // [sp+3Ch] [bp-4h]
  uint32_t v45[3]; // [sp+40h] [bp+0h] BYREF
  int a2a[5]; // [sp+4Ch] [bp+Ch] BYREF
  char _pad9[492]; float v47; // [sp+24Ch] [bp+20Ch]
  float v48; // [sp+250h] [bp+210h]
  float v49; // [sp+254h] [bp+214h]
  float v50; // [sp+258h] [bp+218h]
  char v51; // [sp+25Ch] [bp+21Ch] BYREF
  char _pad14[95]; int v52; // [sp+2BCh] [bp+27Ch]
  char _pad15[12]; unsigned int v53; // [sp+2CCh] [bp+28Ch]
  uint8_t v54[1204]; // [sp+2D0h] [bp+290h] BYREF
  } _frame;
  v11 = (void *)(uintptr_t)(off_10A30C);
  v13 = ((volatile uint32_t *)(uintptr_t)off_10A2C0)[1];
  v14 = ((volatile uint32_t *)(uintptr_t)off_10A2C0)[2];
  _frame.v45[0] = ((volatile uint32_t *)(uintptr_t)off_10A2C0)[0];
  _frame.v45[1] = v13;
  _frame.v45[2] = v14;
  v15 = flt_10A2C4;
  _frame.v42 = (void *)(_frame.v45);
  *(volatile uint32_t *)(a5 + 4 * a4) = 1;
  _frame.v44 = (volatile unsigned int *)(a2 - 4);
  _frame.v40 = 1;
  _frame.v43 = (volatile int *)(a5 + 4 * a4);
  v17 = 0;
  while ( 2 )
  {
    v19 = _frame.v44[1];
    ++_frame.v44;
    v20 = (uint8_t)v17;
    if ( !v19 )
    {
      state_check_feature(1, "===========table[%d]===========\n", v17);
      state_check_feature(1, "table %d dont need cal.\n", v17);
      goto LABEL_28;
    }
    if ( !a4 && v17 == 1 )
    {
      state_check_feature(1, a24gTable1DontN);
      goto LABEL_29;
    }
    state_check_feature(1, "===========table[%d]===========\n", v17);
    v21 = *_frame.v44;
    _frame.v52 = 0;
    llc_connection_init(v21, (int)_frame.a2a, a4);
    state_check_feature(1, "table %d cal %d times.\n", v17, _frame.v52);
    _frame.v38 = *_frame.v42;
    if ( _frame.v52 <= 0 )
      goto LABEL_27;
    _frame.a1a = v17;
    _frame.v39 = 0;
    v22 = &_frame.v51;
    do
    {
      v23 = *((volatile uint32_t *)v22 + 16);
      while ( !*a1 )
        timer_set(1);
      state_check_feature(1, aStDpdCal);
      rf_init((int)_frame.a2a, (int)_frame.v54, v20, v23, a4, 0);
      *v11 &= ~0x8000u;
      *v11 &= ~0x2000u;
      mmio_set_bits(v23, _frame.a2a, (int)_frame.v54, v20, 0, a4, a6, a7, a9, a10, a11);
      *v11 |= 0x8000u;
      *v11 |= 0x2000u;
      state_check_feature(1, aDpdCalEnd);
      while ( !a1[1] )
        timer_set(1);
      v24 = flt_10A2DC;
      state_check_feature(1, aStDpdVerify);
      rf_init((int)_frame.a2a, (int)_frame.v54, v20, v23, a4, 1);
      *v11 &= ~0x8000u;
      *v11 &= ~0x2000u;
      mmio_set_bits(v23, _frame.a2a, (int)_frame.v54, v20, 1, a4, a6, 0, a9, a10, a11);
      *v11 |= 0x8000u;
      *v11 |= 0x2000u;
      state_check_feature(1, aDpdCalEnd);
      state_check_feature(1, aDefaultDpdCal);
      state_check_feature(1, "am*1000000:%6d  %d\n", (int)(float)(_frame.v47 * v24), (int)(float)(_frame.v48 * v24));
      state_check_feature(1, "ph*1000000:%6d  %d\n", (int)(float)(_frame.v49 * v24), (int)(float)(_frame.v50 * v24));
      v25 = _frame.v47 / _frame.v48;
      v26 = _frame.v49 / _frame.v50;
      if ( v23 == 11 )
      {
        v27 = 3.0;
        v29 = 3.0;
        v28 = 30000;
      }
      else if ( (unsigned int)(v23 - 12) <= 1 )
      {
        v29 = flt_10A594;
        v28 = 11000;
        v27 = 3.0;
      }
      else if ( v23 == 14 )
      {
        v29 = flt_10A598;
        v28 = 13000;
        v27 = 3.0;
      }
      else if ( v23 <= 7 )
      {
        v27 = v15;
        v29 = v15;
        v28 = 10010;
      }
      else
      {
        v27 = flt_10A2EC;
        v28 = 11000;
        v29 = flt_10A2EC;
      }
      v30 = flt_10A2F0;
      state_check_feature(1, "am_compare_thr * 10000 = %6d  ", v28);
      state_check_feature(1, "ph_compare_thr * 10000 = %6d\n", (int)(float)(v27 * v30));
      v31 = (int)(float)(v25 * v30);
      state_check_feature(1, "am_compare     * 10000 = %6d  ", v31);
      state_check_feature(1, "ph_compare     * 10000 = %6d\n", (int)(float)(v26 * v30));
      state_check_feature(1, "verify_ph_var_sum * 10000 = %6d\n", (int)(float)(_frame.v49 * v30));
      if ( v29 >= v25 )
      {
        v32 = _frame.v53;
        if ( *(volatile float *)&_frame.v53 < 2.0 )
          goto LABEL_19;
        *(volatile uint32_t *)v22 = 0;
        *((volatile uint32_t *)v22 + 8) = 0;
        state_check_feature(1, "am_compare_thr * 10000 = %6d  ", v28);
        state_check_feature(1, "ph_compare_thr * 10000 = %6d\n", (int)(float)(v27 * v30));
        state_check_feature(1, "am_compare     * 10000 = %6d  ", (int)(float)(v25 * v30));
        state_check_feature(1, "ph_compare     * 10000 = %6d\n", (int)(float)(v26 * v30));
        state_check_feature(1, "table[%d] dpd cal is not good, ana_index %x use default.\n", _frame.a1a, v23);
        if ( v23 <= 10 && _frame.a1a == 1 )
        {
          _frame.v40 = 0;
          ke_event_schedule_1("table 1 index %x dont use dpd\n", v23);
          *(volatile uint32_t *)v22 = 1;
          *((volatile uint32_t *)v22 + 8) = 1;
        }
      }
      else
      {
        if ( v27 < v26 )
        {
          v32 = _frame.v53;
LABEL_19:
          *(volatile uint32_t *)v22 = 1;
          *((volatile uint32_t *)v22 + 8) = 1;
if ( v23 <= 8 && v27 > v26 && (v33 = ((uint64_t (*)())__aeabi_f2d)(v32), ((int (*)())__aeabi_dcmpgt)(v33, *(volatile uint64_t *)&dword_10A2B8)) && _frame.a1a == 1 ) { state_check_feature(1, "am_compare_thr * 10000 = %6d  ", v28);
            state_check_feature(1, "ph_compare_thr * 10000 = %6d\n", (int)(float)(v27 * v30));
            state_check_feature(1, "am_compare     * 10000 = %6d  ", v31);
            state_check_feature(1, "ph_compare     * 10000 = %6d\n", (int)(float)(v26 * v30));
            state_check_feature(1, "dpd_ampm.degree_max[1]     * 10000 = %6d\n", (int)(float)(*(volatile float *)&_frame.v53 * flt_10A5B0));
            state_check_feature(1, "verify ph is larger, table 1 index %x dont use dpd\n", v23);
            _frame.v40 = 0;
          }
          else
          {
            state_check_feature(1, "table[%d] dpd cal success, ana_index %x can be used.\n", _frame.a1a, v23);
            _frame.v40 = 1;
          }
          goto LABEL_24;
        }
        v32 = _frame.v53;
        if ( *(volatile float *)&_frame.v53 < 2.0 )
          goto LABEL_19;
        *(volatile uint32_t *)v22 = 1;
        *((volatile uint32_t *)v22 + 8) = 0;
        state_check_feature(1, "table[%d] dpd cal success, ph deviation is small, ana_index %x can be used.\n", _frame.a1a, v23);
        if ( v23 <= 8 && _frame.a1a == 1 )
        {
          if ( *(volatile float *)&_frame.v53 > 2.0 )
          {
            state_check_feature(1, "am_compare_thr * 10000 = %6d  ", v28);
            state_check_feature(1, "ph_compare_thr * 10000 = %6d\n", (int)(float)(v27 * v30));
            state_check_feature(1, "am_compare     * 10000 = %6d  ", v31);
            state_check_feature(1, "ph_compare     * 10000 = %6d\n", (int)(float)(v26 * v30));
            state_check_feature(1, "dpd_ampm.degree_max[1]     * 10000 = %6d\n", (int)(float)(*(volatile float *)&_frame.v53 * v30));
            state_check_feature(1, "verify ph is larger, table 1 index %x dont use dpd\n", v23);
            _frame.v40 = 0;
            state_check_feature(1, "table 1 index %x dont use dpd\n", v23);
          }
          else
          {
            _frame.v40 = 1;
          }
        }
        else
        {
          _frame.v40 = 1;
        }
      }
LABEL_24:
      _frame.v38 &= *(volatile uint32_t *)v22;
      v34 = *_frame.v43 & _frame.v40;
      v35 = _frame.v52 <= ++_frame.v39;
      *_frame.v42 = _frame.v38;
      v22 += 4;
      *_frame.v43 = v34;
    }
    while ( !v35 );
    v17 = _frame.a1a;
LABEL_27:
    *_frame.v44 = *_frame.v44 & 0xFFFEFFFF | (_frame.v38 << 16);
LABEL_28:
    if ( v20 != 2 )
    {
LABEL_29:
      ++v17;
      ++_frame.v42;
      continue;
    }
    break;
  }
  while ( !a1[2] )
    timer_set(1);
  result = state_check_feature(1, aDpdUse);
  v37 = (void *)(uintptr_t)(off_10A5A0);
  *(volatile uint32_t *)off_10A5A0 &= ~0x200u;
  *v37 |= 0x200u;
  *v37 &= ~0x200u;
  return result;
}


// tx_packet_dispatch @ 0x10a5bc
int tx_packet_dispatch(int a1, unsigned int a2, volatile uint8_t *a3, volatile int *a4) {
  volatile uint8_t *v6; // r6
  volatile uint8_t *v7; // r9
  int i; // r8
  int v9; // r2
  int v10; // r0
  int v11; // r4
  char v12; // r0
  volatile float *v13; // r5
  int v14; // r4
  volatile float *v15; // r2
  int v16; // r3
  int v17; // r1
  int v18; // r0
  volatile uint8_t *v19; // r1
  int v20; // r2
  int v21; // r4
  float v23; // s12
  float v24; // s13
  float v25; // s14
  float v26; // s15
  int v27; // r3
  int v28; // r0
  int v29; // r3
  struct __attribute__((packed)) { float v30[3]; // [sp+0h] [bp-58h] BYREF
  float a2a[3]; // [sp+Ch] [bp-4Ch] BYREF
  uint8_t v32[4]; // [sp+18h] [bp-40h] BYREF
  uint8_t var3C[92]; // [sp+1Ch] [bp-3Ch] BYREF
  } _frame;
  if ( a2 > 9 && a1 != 3 )
  {
    v6 = a3 - 1;
    v7 = _frame.v32;
    for ( i = 0; i != 4; ++i )
    {
      v9 = 0;
      v10 = 0;
      do
      {
        if ( (uint8_t)i != (uint8_t)v9 )
        {
          if ( (uint8_t)v9 )
          {
            _frame.v30[v10] = (float)v6[v9];
            v11 = 4 * v10;
          }
          else
          {
            v11 = 4 * v10;
            _frame.v30[v10] = 128.0;
          }
          v10 = (uint8_t)(v10 + 1);
          *(volatile float *)&_frame.var3C[v11 - 16] = (float)a4[v9];
        }
        ++v9;
      }
      while ( v9 != 4 );
      *v7 = 0;
      v12 = float_compare(_frame.v30, _frame.a2a);
      *v7 = v12;
      if ( (v12 & 0xE) == 0 )
        f32_compare(a2, _frame.v30, _frame.a2a, (int)v7);
      v7 += 16;
    }
    v13 = (volatile float *)_frame.var3C;
    v14 = 0;
    v15 = (volatile float *)_frame.var3C;
    v16 = 0;
    v17 = 128;
    do
    {
      v18 = *((volatile uint8_t *)v15 - 4);
      if ( *((volatile uint8_t *)v15 - 4) )
      {
        if ( (v18 & 8) != 0 )
          goto LABEL_42;
        if ( v18 == 1 )
          v14 = 1;
      }
      else if ( v17 == 128 )
      {
        v17 = v16;
      }
      else if ( *v15 <= *(volatile float *)&_frame.var3C[16 * v17] )
      {
        v17 = v16;
      }
      v16 = (uint8_t)(v16 + 1);
      v15 += 4;
    }
    while ( v16 != 4 );
    if ( v14 )
    {
      if ( v17 != 128 )
      {
LABEL_21:
        v19 = &_frame.var3C[16 * v17 + 60];
        v20 = (uint8_t)*(v19 - 64);
        v21 = (uint8_t)*(v19 - 63);
        if ( !*(v19 - 64) )
          return v21;
        goto LABEL_22;
      }
      v29 = 0;
      do
      {
        if ( *((volatile uint8_t *)v13 - 4) == 1 )
        {
          if ( v17 == 128 )
          {
            v17 = v29;
          }
          else if ( *v13 <= *(volatile float *)&_frame.var3C[16 * v17] )
          {
            v17 = v29;
          }
        }
        v29 = (uint8_t)(v29 + 1);
        v13 += 4;
      }
      while ( v29 != 4 );
    }
    if ( v17 == 128 )
    {
LABEL_42:
      v21 = 32 * (9 - a2);
      printf_wrapper("gain %x : fit_failed!\r\n", a2);
      return v21;
    }
    goto LABEL_21;
  }
  v23 = (float)a3[1];
  v24 = (float)*a4;
  v25 = (float)a4[1];
  v26 = (float)a4[2];
  _frame.v30[1] = (float)*a3;
  _frame.v30[2] = v23;
  _frame.a2a[0] = v24;
  _frame.a2a[1] = v25;
  _frame.a2a[2] = v26;
  _frame.v30[0] = 128.0;
  _frame.v32[0] = 0;
  if ( a2 > 9 )
  {
    v28 = float_compare(_frame.v30, _frame.a2a);
    _frame.v32[0] = v28;
    if ( (v28 & 0xE) != 0 )
    {
      v20 = v28;
    }
    else
    {
      f32_compare(a2, _frame.v30, _frame.a2a, (int)_frame.v32);
      v27 = _frame.v32[0];
      v20 = _frame.v32[0];
      if ( (_frame.v32[0] & 0xE) == 0 )
        goto LABEL_26;
    }
    v21 = 32 * (9 - a2);
    printf_wrapper("gain %x : fit_status %d\r\n", a2, v20);
    return v21;
  }
  f32_compare(a2, _frame.v30, _frame.a2a, (int)_frame.v32);
  v20 = _frame.v32[0];
  v27 = _frame.v32[0];
  if ( (_frame.v32[0] & 0xE) != 0 )
  {
    v21 = 128;
    printf_wrapper("gain %x : fit_status %d\r\n", a2, _frame.v32[0]);
    return v21;
  }
LABEL_26:
  v21 = _frame.v32[1];
  if ( v27 )
  {
LABEL_22:
    printf_wrapper("gain %x : fit_status %d\r\n", a2, v20);
    return v21;
  }
  return v21;
}


// chip_common_init @ 0x10a800
int chip_common_init(unsigned int a1, unsigned int a2, int a3, unsigned int a4, uint8_t a5, char a6) {
  unsigned int v8; // s17
  int v9; // r3
  volatile uint32_t *v10; // r2
  volatile uint32_t *v11; // r5
  volatile uint32_t *v12; // r7
  volatile unsigned int *v13; // r3
  volatile unsigned int *v14; // r1
  volatile uint32_t *v15; // r6
  volatile unsigned int *v16; // r11
  volatile unsigned int *v17; // r0
  int v18; // s16
  volatile unsigned int *v19; // r10
  unsigned int v20; // r8
  int v21; // r6
  int v22; // r5
  int v23; // r4
  int v24; // zf
  unsigned int v25; // r4
  int v26; // r1
  int v27; // r6
  unsigned int v28; // r7
  int16_t v29; // r4
  int16_t v30; // r0
  unsigned int v31; // r2
  uint8_t v32; // r1
  unsigned int i; // r3
  unsigned int v34; // r4
  unsigned int v35; // r9
  volatile uint32_t *v36; // r1
  volatile unsigned int *v37; // r3
  volatile unsigned int *v38; // r1
  uint16_t v39; // r3
  volatile uint32_t *v40; // r3
  volatile unsigned int *v42; // r3
  struct __attribute__((packed)) { int v43; // [sp+24h] [bp-7C0h]
  int v44; // [sp+28h] [bp-7BCh]
  char _pad2[8]; int v45; // [sp+34h] [bp-7B0h]
  int v46; // [sp+38h] [bp-7ACh]
  char _pad4[8]; unsigned int a1a; // [sp+44h] [bp-7A0h]
  int v49; // [sp+48h] [bp-79Ch]
  char _pad6[14]; char a3a; // [sp+5Ah] [bp-78Ah] BYREF
  char v53; // [sp+5Bh] [bp-789h] BYREF
  char v54[4]; // [sp+5Ch] [bp-788h] BYREF
  int result; // [sp+60h] [bp-784h] BYREF
  unsigned int a2a; // [sp+64h] [bp-780h] BYREF
  int16_t v57[6]; // [sp+68h] [bp-77Ch] BYREF
  int16_t v58[952]; // [sp+74h] [bp-770h] BYREF
  } _frame;
  state_check_feature(
    0x2000,
    "page %x,sdm %x,freq %x,lock %x,rfen %x\n",
    (*(volatile uint32_t *)off_10AB34 >> 3) & 7,
    *(volatile uint32_t *)off_10AB00,
    *(volatile uint32_t *)off_10AB04,
    *(volatile uint32_t *)off_10AB08,
    *(volatile uint32_t *)off_10AB0C);
  v8 = ((a1 >> 1) & 1) + 3;
  if ( (a1 & 0xC) != 0 )
  {
    if ( ((a1 >> 2) & 3) == 1 )
      v9 = 5;
    else
      v9 = 10;
    _frame.a1a = v9;
  }
  else
  {
    _frame.a1a = 1;
  }
  v10 = (void *)(uintptr_t)(off_10AB14);
  v11 = (void *)(uintptr_t)(off_10AB18);
  v12 = (void *)(uintptr_t)(off_10AB1C);
  v13 = (volatile unsigned int *)off_10AB20;
  v14 = (volatile unsigned int *)off_10AB24;
  v15 = (void *)(uintptr_t)(off_10AB28);
  v16 = (volatile unsigned int *)off_10AB38;
  *(volatile uint32_t *)off_10AB14 &= ~4u;
  *v11 &= 0xFFFF0FFF;
  *v12 = 0;
  *v13 |= 0x80u;
  *v14 |= 0x80000000;
  *v10 |= 4u;
  *v15 = HIWORD(*v15) << 16;
  *(v12 - 6154) = *(v12 - 6154) & 0xCFFFFFFF | 0x10000000;
  v17 = (volatile unsigned int *)off_10AB2C;
  *v10 &= ~4u;
  *v14 &= ~0x80000000;
  *v13 &= ~0x80u;
  *v10 |= 4u;
  v15[6223] |= 2u;
  *v13 = *v13 & 0xFFFF8FFF | 0x4000;
  *v13 = *v13 & 0xF8FFFFFF | 0x6000000;
  *v13 = *v13 & 0xFFFFF8FF | 0x100;
  *v13 &= ~4u;
  *v13 |= 1u;
  *v13 |= 8u;
  *v14 = a3 | *v14 & 0x80000000;
  *v17 |= 0x2000000u;
  *v17 |= 0x10000u;
  _frame.v43 = 0;
  _frame.v49 = ((v10[2069] >> 3) & 7) << 6;
  v18 = 0;
  v19 = v17;
  _frame.v46 = -1;
  do
  {
    _frame.v45 = 0;
    do
    {
      if ( a4 <= a5 )
      {
        v20 = a4;
        do
        {
          *v16 = dword_10AB30 & (((uint16_t)_frame.v49 | (4 * v20) | 1) << 8) | *v16 & 0xFFFE00FF;
          *v16 |= 0x20000u;
          *v16 |= 0x40000u;
          timer_set(1);
          if ( _frame.v43 )
          {
            if ( _frame.v45 )
            {
              v21 = (uint16_t)v20;
            }
            else
            {
              mac_cmd_dispatch(v18, v20, &_frame.a3a, (volatile char *)&_frame.v58[6] + 3 * v20, (volatile int *)&_frame.v58[8 * v20 + 54]);
              v21 = (uint16_t)v20;
              mac_cmd_dispatch(v18, v20, &_frame.v53, (volatile char *)&_frame.v58[30] + 3 * v20, (volatile int *)&_frame.v58[8 * v20 + 182]);
            }
            v22 = *((volatile uint8_t *)&_frame.v58[6] + 3 * v20 + _frame.v46);
            v23 = *((volatile uint8_t *)&_frame.v58[30] + 3 * v20 + _frame.v46);
            *v19 = *v19 & 0xFE01FFFF | (v22 << 17);
            *v19 = *v19 & 0xFFFF00FF | (v22 << 8);
            udelay_50((void *)(&_frame.result), &_frame.a2a);
            if ( v22 != v23 )
            {
              *v19 = *v19 & 0xFE01FFFF | (v23 << 17);
              *v19 = *v19 & 0xFFFF00FF | (v23 << 8);
              udelay_50((void *)(_frame.v54), &_frame.a2a);
            }
          }
          else
          {
            *v19 = *v19 & 0xFE01FFFF | 0x1000000;
            *v19 = *v19 & 0xFFFF00FF | 0x8000;
            udelay_50((void *)(&_frame.result), &_frame.a2a);
            v21 = (uint16_t)v20;
          }
          u64_set_or_add((uint8_t)_frame.v45, _frame.result, (void *)(&_frame.v58[20 * v21 + 310]));
          u64_set_or_add((uint8_t)_frame.v45, _frame.a2a, (void *)(&_frame.v58[20 * v20 + 630]));
          v20 = (uint8_t)(v20 + 1);
        }
        while ( a5 >= v20 );
      }
      v24 = _frame.a1a == ++_frame.v45;
    }
    while ( !v24 );
    if ( a4 <= a5 )
    {
      v25 = a4;
      do
      {
        while ( 1 )
        {
          v27 = _frame.v43 + 4 * v25;
          if ( _frame.a1a != 1 )
            break;
          *(volatile uint32_t *)&_frame.v58[2 * v27 + 54] = *(volatile uint32_t *)&_frame.v58[20 * v25 + 310];
          *(volatile uint32_t *)&_frame.v58[2 * v27 + 182] = *(volatile uint32_t *)&_frame.v58[20 * v25 + 630];
          v25 = (uint8_t)(v25 + 1);
          if ( a5 < v25 )
            goto LABEL_28;
        }
        if ( v25 >= 6 )
          v26 = 100;
        else
          v26 = 50;
        _frame.v44 = v26;
        *(volatile uint32_t *)&_frame.v58[2 * v27 + 54] = sub_1093d4(_frame.a1a, v26, (volatile int *)&_frame.v58[20 * v25 + 310]);
        *(volatile uint32_t *)&_frame.v58[2 * v27 + 182] = sub_1093d4(_frame.a1a, _frame.v44, (volatile int *)&_frame.v58[20 * v25 + 630]);
        v25 = (uint8_t)(v25 + 1);
      }
      while ( a5 >= v25 );
    }
LABEL_28:
    ++_frame.v46;
    v18 = (uint8_t)++_frame.v43;
  }
  while ( v8 > (uint8_t)_frame.v43 );
  if ( a4 > a5 )
  {
    sub_1096d0((a1 >> 5) & 1, _frame.v57);
    sub_1096d0((a1 >> 5) & 1, _frame.v58);
  }
  else
  {
    v28 = a4;
    do
    {
      v29 = tx_packet_dispatch(v8, v28, (volatile uint8_t *)&_frame.v58[6] + 3 * v28, (volatile int *)&_frame.v58[8 * v28 + 54]);
      v30 = tx_packet_dispatch(v8, v28, (volatile uint8_t *)&_frame.v58[30] + 3 * v28, (volatile int *)&_frame.v58[8 * v28 + 182]);
      v31 = v28 - 10;
      if ( v28 > 9 )
        _frame.v57[v31] = v29;
      else
        v31 = a2;
      if ( v28 <= 9 )
        *(volatile uint16_t *)(v31 + 2 * (uint16_t)v28) = (uint8_t)v29 | (uint16_t)(v30 << 8);
      v32 = v28 + 1;
      if ( v28 > 9 )
        _frame.v58[v31] = v30;
      v28 = v32;
    }
    while ( a5 >= (unsigned int)v32 );
    sub_1096d0((a1 >> 5) & 1, _frame.v57);
    sub_1096d0((a1 >> 5) & 1, _frame.v58);
    for ( i = a4; ; i = (uint8_t)(i + 1) )
    {
      if ( i > 9 )
        *(volatile uint16_t *)(a2 + 2 * (uint16_t)i) = LOBYTE(_frame.v57[i - 10]) | (uint16_t)(_frame.v58[i - 10] << 8);
      if ( a5 == i )
        break;
    }
    v34 = a4;
    do
    {
      v35 = *(volatile uint16_t *)(a2 + 2 * v34);
      state_check_feature(
        0x2000,
        "fit-in-I %x %x: [%d,%d;%d,%d;%d,%d;%d,%d]\r\n",
        v34,
        (uint8_t)v35,
        128,
        *(volatile uint32_t *)&_frame.v58[8 * v34 + 54],
        *((volatile uint8_t *)&_frame.v58[6] + 3 * v34),
        *(volatile uint32_t *)&_frame.v58[8 * v34 + 56],
        *((volatile uint8_t *)&_frame.v58[6] + 3 * v34 + 1),
        *(volatile uint32_t *)&_frame.v58[8 * v34 + 58],
        *((volatile uint8_t *)&_frame.v58[7] + 3 * v34),
        *(volatile uint32_t *)&_frame.v58[8 * v34 + 60]);
      state_check_feature(
        0x2000,
        "fit-in-Q %x %x: [%d,%d;%d,%d;%d,%d;%d,%d]\r\n",
        v34,
        v35 >> 8,
        128,
        *(volatile uint32_t *)&_frame.v58[8 * v34 + 182],
        *((volatile uint8_t *)&_frame.v58[30] + 3 * v34),
        *(volatile uint32_t *)&_frame.v58[8 * v34 + 184],
        *((volatile uint8_t *)&_frame.v58[30] + 3 * v34 + 1),
        *(volatile uint32_t *)&_frame.v58[8 * v34 + 186],
        *((volatile uint8_t *)&_frame.v58[31] + 3 * v34),
        *(volatile uint32_t *)&_frame.v58[8 * v34 + 188]);
      v24 = a5 == v34;
      v34 = (uint8_t)(v34 + 1);
    }
    while ( !v24 );
  }
  v36 = (void *)(uintptr_t)(off_10AE54);
  v37 = (volatile unsigned int *)off_10AE58;
  *(volatile uint32_t *)off_10AE54 &= ~2u;
  *v37 |= 4u;
  *v37 = *v37 & 0xFFFF8FFF | 0x3000;
  *v37 = *v37 & 0xFFFFF8FF | 0x600;
  *v37 &= ~8u;
  *v37 &= ~1u;
  *(v36 - 6224) &= 0xCFFFFFFF;
  if ( a6 )
  {
    v38 = (volatile unsigned int *)off_10AE5C;
    v39 = *(volatile uint16_t *)(a2 + 2 * a4);
    *(volatile uint32_t *)off_10AE5C = *(volatile uint32_t *)off_10AE5C & 0xFE01FFFF | ((uint8_t)v39 << 17);
    *v38 = v39 & 0xFF00 | *v38 & 0xFFFF00FF;
  }
  else
  {
    v42 = (volatile unsigned int *)off_10AE5C;
    *(volatile uint32_t *)off_10AE5C &= ~0x2000000u;
    *v42 &= ~0x10000u;
    *v42 = *v42 & 0xFE01FFFF | 0x1000000;
    *v42 = *v42 & 0xFFFF00FF | 0x8000;
  }
  v40 = (void *)(uintptr_t)(off_10AE60);
  *(volatile uint32_t *)off_10AE60 &= 0xFFFE00FF;
  *v40 &= ~0x20000u;
  *v40 |= 0x40000u;
  return state_check_feature(0x2000, aWfDccalibEnd);
}


// sdio_core_setup @ 0x10ae68
int sdio_core_setup(int a1, volatile uint8_t *a2, int a3) {
  int v3; // r9
  int v4; // r10
  int v5; // r11
  int v7; // r1
  unsigned int v8; // r2
  int v9; // lr
  int v10; // r12
  int v11; // r0
  volatile int *v12; // r2
  int v13; // r4
  volatile unsigned int *v14; // r1
  volatile unsigned int *v15; // r6
  volatile int *v16; // r4
  unsigned int v17; // r3
  volatile uint32_t *v18; // r4
  volatile uint32_t *v19; // r9
  int v20; // r10
  unsigned int v21; // r4
  int v22; // r5
  int v23; // r4
  int v24; // r7
  int v25; // r9
  int v26; // r0
  volatile int *v27; // r10
  int v28; // r1
  int v29; // r12
  volatile unsigned int *v30; // r2
  volatile unsigned int *v31; // r8
  volatile int *v32; // r12
  int v33; // t1
  volatile uint32_t *v34; // r0
  int v36; // r8
  volatile unsigned int *v37; // r2
  volatile int *v38; // lr
  volatile unsigned int *v39; // r8
  int v40; // t1
  int v41; // r6
  volatile unsigned int *v42; // r1
  volatile int *v43; // r5
  volatile unsigned int *v44; // r6
  unsigned int v45; // r3
  int v46; // s16
  int i; // r8
  int v48; // r10
  int v49; // r7
  int v50; // r5
  int v51; // r6
  int v52; // lr
  int v53; // r10
  int v54; // r3
  volatile unsigned int *v55; // r1
  int v56; // r12
  int v57; // r5
  volatile unsigned int *v58; // r11
  unsigned int v59; // r2
  unsigned int v60; // t1
  int v61; // r6
  volatile uint32_t *v62; // r0
  int v63; // r3
  int v64; // r0
  int v65; // cc
  int v66; // r3
  int v67; // r0
  struct __attribute__((packed)) { unsigned int a5; // [sp+0h] [bp-1CCh]
  char _pad1[12]; int v69; // [sp+10h] [bp-1BCh]
  int v70; // [sp+14h] [bp-1B8h]
  volatile unsigned int *a2a; // [sp+18h] [bp-1B4h]
  volatile uint8_t *v72; // [sp+1Ch] [bp-1B0h]
  volatile int *v73; // [sp+20h] [bp-1ACh]
  int v74; // [sp+24h] [bp-1A8h]
  char _pad7[12]; int v77; // [sp+34h] [bp-198h]
  uint16_t a1a[2]; // [sp+38h] [bp-194h] BYREF
  int v79; // [sp+3Ch] [bp-190h]
  uint16_t v80; // [sp+40h] [bp-18Ch]
  char _pad11[2]; uint32_t v81[14]; // [sp+44h] [bp-188h] BYREF
  int v82; // [sp+7Ch] [bp-150h]
  char _pad13[8]; uint8_t v83[128]; // [sp+88h] [bp-144h] BYREF
  uint8_t v84[196]; // [sp+108h] [bp-C4h] BYREF
  } _frame;
  v3 = dword_10B1AC;
  v4 = dword_10B1B4;
  v5 = dword_10B1D8;
  ke_event_schedule_1(aMiscCalibLoftC);
  v7 = *(volatile uint32_t *)off_10B194;
  v8 = *(volatile uint32_t *)off_10B194 & 0xFFFFFFFE;
  *(volatile uint32_t *)_frame.a1a = 0;
  _frame.v79 = 0;
  _frame.v80 = 0;
  *(volatile uint32_t *)off_10B194 = v8;
  _frame.v74 = v7 & 1;
  set_radio_ctrl_bits(0);
  v9 = dword_10B1B0;
  v10 = dword_10B1B8;
  v11 = 0;
  v12 = (volatile int *)_frame.v84;
  do
  {
    if ( v11 )
    {
      if ( v11 != 1 )
      {
        v13 = v10;
        goto LABEL_5;
      }
      v13 = v4;
      v41 = v5;
    }
    else
    {
      v13 = v3;
      v41 = v9;
    }
    v42 = (volatile unsigned int *)(v41 + 4);
    v43 = (volatile int *)&_frame.v83[64 * v11];
    v44 = (volatile unsigned int *)(v41 + 516);
    do
    {
      v45 = *v42;
      *v42 &= 0xFFF1FFFF;
      v42 += 8;
      *v43++ = (v45 >> 17) & 7;
    }
    while ( v42 != v44 );
LABEL_5:
    v14 = (volatile unsigned int *)(v13 + 4);
    v15 = (volatile unsigned int *)(v13 + 516);
    v16 = v12;
    do
    {
      v17 = *v14;
      *v14 &= 0xFFF1FFFF;
      v14 += 8;
      *v16++ = (v17 >> 17) & 7;
    }
    while ( v15 != v14 );
    ++v11;
    v12 += 16;
  }
  while ( v11 != 3 );
  v18 = (void *)(uintptr_t)(off_10B198);
  set_radio_ctrl_bits2(0);
  state_check_feature(1, aTrigger);
  *v18 |= 0x400u;
  *v18 &= ~0x400u;
  ke_event_schedule_1(aLoftStart);
  state_check_feature(1, aLoftCal);
  v19 = v18;
  _frame.v69 = a3 + 56;
  do
  {
    v20 = *(volatile uint8_t *)(a3 + 5);
    v21 = *(volatile uint16_t *)(a3 + 2);
    *v19 |= 0x400u;
    *v19 &= ~0x400u;
    if ( v20 == 1 )
    {
      state_check_feature(1, "**************************loft  freq= [%d] **************************\n", v21);
      if ( v21 > 0x1388 )
      {
        _frame.v80 = (_frame.v80 & ~0xFFu) | ((uint8_t)(0) & 0xFFu);
        _frame.a1a[0] = (_frame.a1a[0] & ~0xFFu) | ((uint8_t)(1) & 0xFFu);
        _frame.a1a[1] = v21;
        _frame.v79 = (_frame.v79 & ~0xFFFFu) | ((uint16_t)(v21) & 0xFFFFu);
        _frame.v79 = (_frame.v79 & ~0xFFFF0000u) | (((uint16_t)(v21) & 0xFFFFu) << 16);
        gpio_init(_frame.a1a, 0);
        v67 = validate_value_range(v21);
        _frame.v73 = (void *)(&((volatile uint32_t *)(uintptr_t)off_10B280)[96 * v67]);
        _frame.a2a = (volatile unsigned int *)(a1 + 1264 * (uint8_t)(v67 + 1));
        v46 = (uint8_t)(v67 + 1);
        _frame.v72 = &a2[v46];
      }
      else
      {
        _frame.v79 = (_frame.v79 & ~0xFFFFu) | ((uint16_t)(v21) & 0xFFFFu);
        _frame.a1a[0] = (_frame.a1a[0] & ~0xFFu) | ((uint8_t)(0) & 0xFFu);
        _frame.v80 = (_frame.v80 & ~0xFFu) | ((uint8_t)(0) & 0xFFu);
        gpio_init(_frame.a1a, 0);
        _frame.v73 = (volatile int *)off_10B1CC;
        _frame.v72 = a2;
        v46 = 0;
        _frame.a2a = (volatile unsigned int *)a1;
        v20 = 0;
      }
      bt_rf_calibrate((int)(_frame.a2a + 292), _frame.a2a, 255, 0, 0, dword_10B1D0, 0);
      timer_set(10000);
      _frame.v77 = a3;
      *_frame.v72 = 1;
      _frame.v70 = v20;
      for ( i = 0; i != 3; ++i )
      {
        if ( !_frame.a2a[i] )
          state_check_feature(1, "table [%d] dont need change\n", i);
        if ( _frame.v70 == 1 )
        {
          if ( i )
          {
            if ( i == 1 )
              v48 = 1;
            else
              v48 = 2;
            if ( i == 1 )
              v49 = 8;
            else
              v49 = 9;
            if ( i == 1 )
              v50 = 64;
            else
              v50 = 96;
            if ( i == 1 )
              v51 = 32;
            else
              v51 = 64;
          }
          else
          {
            v48 = 0;
            v51 = 0;
            v49 = 9;
            v50 = 32;
          }
        }
        else
        {
          v48 = 2;
          v49 = 0;
          v50 = 96;
          v51 = 32;
        }
        _frame.a5 = (_frame.a2a[v48] >> 17) & 1;
        *_frame.v72 &= (_frame.a2a[v48] & 0x20000) != 0;
        state_check_feature(1, "ch[%d] loft_ok[%d]=%d\n", v46, i, _frame.a5);
        ke_task_create(_frame.a2a[v48], _frame.v81);
        if ( v51 < v50 )
        {
          v52 = _frame.v82;
          v53 = _frame.v81[10];
          v54 = (int)&_frame.v73[v50 - 1];
          v55 = (volatile unsigned int *)&_frame.v73[v51 - 1];
          v56 = _frame.v82 - 1;
          v57 = 0;
          v58 = (volatile unsigned int *)v54;
          do
          {
            v60 = v55[1];
            ++v55;
            v59 = v60;
            v61 = (v60 >> 8) & 0xF;
            if ( v49 <= v61 )
            {
              if ( v52 == 1 )
              {
                v57 = v53 == v61;
              }
              else if ( v56 > 0 )
              {
                v57 = 0;
                v62 = _frame.v81;
                v63 = 1;
                if ( v61 < v53 )
                {
LABEL_43:
                  v63 = v57 + 1;
                  if ( _frame.v70 != 1 )
                    v57 = 1;
                  goto LABEL_45;
                }
                while ( 1 )
                {
                  if ( v62[11] > v61 )
                    v57 = v63;
                  else
                    v57 += 2;
LABEL_45:
                  v64 = v63;
                  v65 = v56 <= v63;
                  v66 = v63 + 10;
                  if ( v65 )
                    break;
                  v57 = v64;
                  v65 = v61 < _frame.v81[v66];
                  v62 = &_frame.v81[v64];
                  v63 = v57 + 1;
                  if ( v65 )
                    goto LABEL_43;
                }
              }
              *v55 = v59 & 0xE7FFFFFF | (v57 << 27);
            }
          }
          while ( v58 != v55 );
        }
      }
      a3 = _frame.v77;
    }
    a3 += 8;
  }
  while ( _frame.v69 != a3 );
  v22 = dword_10B1AC;
  v23 = dword_10B1B0;
  v24 = dword_10B1B4;
  v25 = dword_10B1D8;
  ke_event_schedule_1(aLoftEnd);
  set_radio_ctrl_bits(0);
  v26 = dword_10B1B8;
  v27 = (volatile int *)_frame.v84;
  v28 = 0;
  while ( 2 )
  {
    if ( v28 )
    {
      if ( v28 != 1 )
      {
        v29 = v26;
        goto LABEL_15;
      }
      v29 = v24;
      v36 = v25;
    }
    else
    {
      v29 = v22;
      v36 = v23;
    }
    v37 = (volatile unsigned int *)(v36 + 4);
    v38 = (volatile int *)&_frame.v83[64 * v28];
    v39 = (volatile unsigned int *)(v36 + 484);
    do
    {
      v40 = *v38++;
      *v37 = *v37 & 0xFFF1FFFF | (v40 << 17);
      v37 += 8;
    }
    while ( v39 != v37 );
LABEL_15:
    v30 = (volatile unsigned int *)(v29 + 4);
    v31 = (volatile unsigned int *)(v29 + 484);
    v32 = v27;
    do
    {
      v33 = *v32++;
      *v30 = *v30 & 0xFFF1FFFF | (v33 << 17);
      v30 += 8;
    }
    while ( v31 != v30 );
    ++v28;
    v27 += 16;
    if ( v28 != 3 )
      continue;
    break;
  }
  set_radio_ctrl_bits2(0);
  v34 = (void *)(uintptr_t)(off_10B1BC);
  *(volatile uint32_t *)off_10B194 = *(volatile uint32_t *)off_10B194 & 0xFFFFFFFE | _frame.v74;
  state_check_feature(1, "tia_aux_gbit000=%d\n", (*v34 >> 21) & 7);
  return ke_event_schedule_1(aMiscLoftCalibS);
}


// phy_calibrate @ 0x10b288
int phy_calibrate(int a1, int a2, int a3, int a4, volatile uint16_t *a5, int a6, int a7) {
  int v7; // s26
  int v8; // r8
  int v9; // r1
  int v10; // r10
  int v11; // r9
  volatile int *v12; // r7
  int v13; // lr
  int v14; // r12
  int i; // r6
  int v16; // r0
  volatile unsigned int *v17; // r2
  volatile int *v18; // r4
  volatile unsigned int *v19; // r0
  unsigned int v20; // r3
  volatile uint32_t *v21; // r4
  float v22; // s18
  int v23; // r7
  volatile uint32_t *v24; // r3
  int v25; // r5
  int v26; // r4
  int v27; // r7
  int v28; // r9
  int v29; // r0
  volatile int *v30; // r10
  int v31; // r1
  int v32; // r12
  volatile unsigned int *v33; // r2
  volatile unsigned int *v34; // r8
  volatile int *v35; // r12
  int v36; // t1
  volatile uint32_t *v37; // r0
  int v39; // r8
  volatile unsigned int *v40; // r2
  volatile int *v41; // lr
  volatile unsigned int *v42; // r8
  int v43; // t1
  int v44; // r5
  volatile unsigned int *v45; // r2
  volatile int *v46; // r4
  volatile unsigned int *v47; // r5
  unsigned int v48; // r3
  unsigned int v49; // r4
  volatile int *v50; // r9
  int v51; // r11
  int v52; // s25
  volatile int *v53; // r12
  int v54; // r0
  int v55; // r1
  int v56; // r2
  int v57; // r3
  int v58; // r1
  int v59; // r2
  int v60; // r1
  int v61; // r11
  unsigned int v62; // r5
  volatile unsigned int *v63; // r11
  unsigned int v64; // t1
  int v65; // r6
  int v66; // r10
  int v67; // r4
  int v68; // r5
  unsigned int v69; // t1
  float v70; // s22
  int v71; // s19
  volatile float *v72; // r3
  int v73; // r4
  int v74; // r1
  int v75; // r8
  volatile int *v76; // r0
  int j; // r3
  unsigned int v78; // t1
  int v79; // r2
  volatile int *v80; // r6
  unsigned int v81; // r11
  int v82; // lr
  float v83; // s20
  int v84; // r12
  int v85; // r5
  int v86; // r9
  uint64_t v87; // kr00_8
  unsigned int v88; // r3
  volatile int *v89; // r8
  int v90; // r4
  int v91; // r11
  uint64_t v92; // r0
  uint64_t v93; // r2
  uint64_t v94; // r0
  unsigned int v95; // r0
  float v96; // r0
  uint64_t v97; // r0
  uint64_t v98; // r0
  int v99; // r4
  volatile float *v100; // r5
  float v101; // s15
  uint64_t v102; // r4
  int v103; // s27
  int v104; // s17
  int v105; // r7
  float v106; // s21
  float v107; // s23
  volatile float *v108; // r6
  int v109; // t1
  int v110; // r3
  float v111; // s24
  int v112; // r4
  float v113; // s15
  float v114; // s17
  int v115; // r3
  int v116; // r5
  int v117; // r6
  float v118; // s16
  volatile unsigned int *v119; // r7
  float v120; // s17
  float v121; // s14
  int v122; // zf
  uint16_t v123; // r0
  int v124; // r3
  volatile uint16_t *v125; // r6
  int v126; // t1
  int v127; // r3
  volatile float *v128; // r6
  int v129; // t1
  int v130; // r3
  volatile int *v131; // r4
  unsigned int v132; // r0
  volatile unsigned int *v133; // r4
  unsigned int v134; // t1
  int v135; // r2
  int v136; // r10
  int v137; // r3
  int v138; // r5
  unsigned int v139; // t1
  int v140; // r0
  int v141; // r2
  int v142; // r10
  int v143; // r4
  unsigned int v144; // r0
  struct __attribute__((packed)) { int a8; // [sp+Ch] [bp-588h]
  char _pad1[20]; union { int v146; // [sp+24h] [bp-570h]
  int v147; }; // [sp+24h] [bp-570h]
  int a4a; // [sp+28h] [bp-56Ch]
  int v149; // [sp+2Ch] [bp-568h]
  union { int v150; // [sp+30h] [bp-564h]
  int v151; }; // [sp+30h] [bp-564h]
  union { volatile uint32_t *v152; // [sp+34h] [bp-560h]
  int v153; }; // [sp+34h] [bp-560h]
  union { int v154; // [sp+38h] [bp-55Ch]
  int v155; }; // [sp+38h] [bp-55Ch]
  int v156; // [sp+3Ch] [bp-558h]
  int v157; // [sp+40h] [bp-554h]
  int v158; // [sp+44h] [bp-550h]
  int v159; // [sp+48h] [bp-54Ch]
  volatile int *v160; // [sp+4Ch] [bp-548h]
  volatile uint16_t *v161; // [sp+50h] [bp-544h]
  volatile uint8_t *v162; // [sp+54h] [bp-540h]
  int v163; // [sp+58h] [bp-53Ch]
  int v164; // [sp+5Ch] [bp-538h]
  char _pad16[4]; volatile int *v165; // [sp+64h] [bp-530h]
  unsigned int v166; // [sp+68h] [bp-52Ch]
  int v167; // [sp+6Ch] [bp-528h]
  union { volatile int *v168; // [sp+70h] [bp-524h]
  uint64_t v169; }; // [sp+70h] [bp-524h]
  char _pad20[4]; int v171; // [sp+7Ch] [bp-518h]
  char _pad21[8]; volatile uint32_t *v173; // [sp+88h] [bp-50Ch]
  char _pad22[8]; uint16_t a3a[2]; // [sp+94h] [bp-500h] BYREF
  uint16_t v176; // [sp+98h] [bp-4FCh]
  char _pad24[2]; uint32_t v177[6]; // [sp+9Ch] [bp-4F8h] BYREF
  int result[48]; // [sp+B4h] [bp-4E0h] BYREF
  uint8_t v179[192]; // [sp+174h] [bp-420h] BYREF
  uint16_t v180[48]; // [sp+234h] [bp-360h] BYREF
  float v181; // [sp+294h] [bp-300h]
  char _pad29[4]; uint8_t v182; // [sp+29Ch] [bp-2F8h]
  char _pad30[3]; uint64_t v183; // [sp+2A0h] [bp-2F4h]
  int v184; // [sp+2A8h] [bp-2ECh]
  uint64_t v185; // [sp+2ACh] [bp-2E8h]
  int v186; // [sp+2B4h] [bp-2E0h]
  int v187; // [sp+2B8h] [bp-2DCh]
  float v188; // [sp+2BCh] [bp-2D8h]
  char _pad36[8]; int v189; // [sp+2C8h] [bp-2CCh]
  int v190; // [sp+2CCh] [bp-2C8h]
  int v191; // [sp+2D0h] [bp-2C4h]
  int v192; // [sp+2D4h] [bp-2C0h]
  char _pad40[12]; char v193; // [sp+2E4h] [bp-2B0h] BYREF
  char _pad41[35]; float v194; // [sp+308h] [bp-28Ch] BYREF
  uint16_t v195[2]; // [sp+30Ch] [bp-288h] BYREF
  uint16_t v196; // [sp+310h] [bp-284h]
  char _pad44[622]; int v197; // [sp+580h] [bp-14h]
  int v198; // [sp+584h] [bp-10h]
  char _pad46[112]; int v199; // [sp+5F8h] [bp+64h]
  int v200; // [sp+5FCh] [bp+68h]
  int a11; // [sp+600h] [bp+6Ch]
  } _frame;
  ke_event_schedule_1(aMiscDpdCalibSi);
  v8 = dword_10B478;
  v9 = *(volatile uint32_t *)off_10B458;
  v10 = dword_10B490;
  v11 = dword_10B47C;
  *(volatile uint32_t *)off_10B458 &= ~1u;
  _frame.v171 = v9 & 1;
  v12 = (volatile int *)_frame.v179;
  set_radio_ctrl_bits(0);
  v13 = dword_10B474;
  v14 = dword_10B480;
  for ( i = 0; i != 3; ++i )
  {
    if ( i )
    {
      if ( i != 1 )
      {
        v16 = v14;
        goto LABEL_5;
      }
      v16 = v10;
      v44 = v11;
    }
    else
    {
      v16 = v8;
      v44 = v13;
    }
    v45 = (volatile unsigned int *)(v44 + 4);
    v46 = &_frame.result[16 * i + 16];
    v47 = (volatile unsigned int *)(v44 + 516);
    do
    {
      v48 = *v45;
      *v45 = *v45 & 0xFFF1FFFF | 0x20000;
      v45 += 8;
      *v46++ = (v48 >> 17) & 7;
    }
    while ( v45 != v47 );
LABEL_5:
    v17 = (volatile unsigned int *)(v16 + 4);
    v18 = v12;
    v19 = (volatile unsigned int *)(v16 + 516);
    do
    {
      v20 = *v17;
      *v17 = *v17 & 0xFFF1FFFF | 0x20000;
      v17 += 8;
      *v18++ = (v20 >> 17) & 7;
    }
    while ( v17 != v19 );
    v12 += 16;
  }
  v21 = (void *)(uintptr_t)(off_10B45C);
  v22 = flt_10B460;
  set_radio_ctrl_bits2(0);
  state_check_feature(1, aTrigger);
  *v21 |= 0x400u;
  *v21 &= ~0x400u;
  ke_event_schedule_1(aDpdStart);
  state_check_feature(1, aDpdCal);
  _frame.v161 = a5;
  _frame.v173 = v21;
  while ( 2 )
  {
    v23 = *((volatile uint8_t *)_frame.v161 + 4);
    if ( v23 != 1 )
      goto LABEL_10;
    v49 = *_frame.v161;
    state_check_feature(1, "*********************dpd  freq= [%d] *********************\n", v49);
    if ( v49 <= 0x1388 )
    {
      v50 = (volatile int *)off_10B79C;
      v51 = a2;
      _frame.v150 = 0;
      v52 = 0;
      _frame.v167 = 0;
      _frame.v146 = 0;
      v23 = 0;
      _frame.a4a = 0;
      _frame.v152 = _frame.v177;
      goto LABEL_29;
    }
    v140 = validate_value_range(v49);
    v141 = (int)off_10C14C;
    _frame.a4a = (uint8_t)(v140 + 1);
    v50 = (void *)(&((volatile uint32_t *)(uintptr_t)off_10C150)[96 * v140]);
    if ( (*((volatile uint8_t *)off_10C14C + 1) & 1) == 0 || (v141 = *(volatile char *)off_10C14C, v141 >= 0) )
    {
      v142 = dword_10C164;
      ke_event_schedule_1(aCapacitanceCal, off_10C150, v141, *((volatile uint8_t *)off_10C14C + 1) & 1);
      v143 = 0;
      v52 = _frame.a4a;
      while ( 1 )
      {
        *(volatile uint32_t *)_frame.v195 = 0;
        _frame.v196 = 0;
        v144 = v142 | (v143 << 12);
        if ( v143 == 1 )
        {
          _frame.v190 = 3;
          _frame.v195[0] = 2048;
          rf_calibrate(v144, (int)_frame.v180, _frame.v195, 0, 1, 1, 1, _frame.a4a);
        }
        else
        {
          _frame.v190 = 3;
          _frame.v195[0] = 2048;
          rf_calibrate(v144, (int)_frame.v180, _frame.v195, 0, 1, v143, 1, _frame.a4a);
          if ( v143 == 2 )
          {
            _frame.v167 = 1;
            v51 = a2 + 1264 * _frame.a4a;
            _frame.v150 = 3 * _frame.a4a;
            _frame.v146 = 3 * _frame.a4a;
            _frame.v152 = &_frame.v177[_frame.a4a];
            goto LABEL_29;
          }
        }
        ++v143;
      }
    }
    v23 = *((volatile uint8_t *)off_10C14C + 1) & 1;
    v52 = (uint8_t)(v140 + 1);
    v51 = a2 + 1264 * _frame.a4a;
    _frame.v150 = 3 * _frame.a4a;
    _frame.v146 = 3 * _frame.a4a;
    _frame.v152 = &_frame.v177[_frame.a4a];
    _frame.v167 = 1;
LABEL_29:
    v53 = (volatile int *)off_10B7A0;
    *_frame.v173 |= 0x400u;
    v54 = *v53;
    v55 = v53[1];
    v56 = v53[2];
    v57 = v53[3];
    v53 += 4;
    *_frame.v173 &= ~0x400u;
    _frame.v177[0] = v54;
    _frame.v177[1] = v55;
    _frame.v177[2] = v56;
    _frame.v177[3] = v57;
    v58 = v53[1];
    v59 = v51 + 16;
    _frame.v177[4] = *v53;
    _frame.v177[5] = v58;
    v60 = v51;
    v61 = v51 - 4;
    dsp_filter_process((volatile uint32_t *)a1, v60, v59, _frame.a4a, (int)_frame.v177, a6, a7, _frame.a8, _frame.v199, _frame.v200, _frame.a11);
    timer_set(0);
    v64 = *(volatile uint32_t *)(v61 + 4);
    v63 = (volatile unsigned int *)(v61 + 4);
    v62 = v64;
    v65 = 0;
    if ( !v64 )
      goto LABEL_36;
    while ( 1 )
    {
      if ( v23 == 1 )
      {
        if ( v65 )
        {
          if ( v65 == 1 )
            v66 = 64;
          else
            v66 = 96;
          if ( v65 == 1 )
            v67 = 32;
          else
            v67 = 64;
        }
        else
        {
          v66 = 32;
          v67 = 0;
        }
      }
      else
      {
        if ( v65 == 1 )
        {
          state_check_feature(1, a24gTable1DontN_0);
          *(volatile uint32_t *)off_10C15C |= 0x8000u;
          goto LABEL_35;
        }
        v66 = 64;
        v67 = 32;
      }
      v68 = HIWORD(v62) & 1;
      *(volatile uint8_t *)(a3 + _frame.v146 + v65) = v68;
      state_check_feature(1, "table [%d] dpd_ok=%d\n", v65, v68);
      llc_connection_init(*v63, (int)_frame.v195, v23);
      state_check_feature(1, "ana_pwr_max=%x\n", _frame.v197);
      state_check_feature(1, "ana_pwr_min=%x\n", _frame.v198);
      if ( v68 && v67 < v66 )
      {
        v131 = &v50[v67 - 1];
        v134 = v131[1];
        v133 = (volatile unsigned int *)(v131 + 1);
        v132 = v134;
        v135 = (v134 >> 8) & 0xF;
        v136 = (int)&v50[v66 - 1];
        v137 = v68;
        v138 = 15 - v135;
        if ( !v23 )
          goto LABEL_152;
        while ( 1 )
        {
          if ( v135 == 7 )
            v138 = 5;
LABEL_155:
          if ( _frame.v198 <= v135 && _frame.v197 >= v135 )
          {
            if ( v135 > 8 || *_frame.v152 || v65 != 1 )
            {
              *v133 = v132 & 0xFF3F7FFF | (v138 << 24);
            }
            else
            {
              *v133 = v132 | 0xC08000;
              _frame.v155 = v137;
              state_check_feature(1, "table 1 index %d bypass\n", v135);
              v137 = _frame.v155;
            }
          }
          if ( (volatile unsigned int *)v136 == v133 )
            break;
          v139 = v133[1];
          ++v133;
          v132 = v139;
          v135 = (v139 >> 8) & 0xF;
          v138 = 15 - v135;
          if ( !v23 )
          {
LABEL_152:
            if ( v135 == 4 )
            {
              v138 = v137;
            }
            else if ( v135 == 7 )
            {
              v138 = 0;
            }
            goto LABEL_155;
          }
        }
      }
      if ( v65 == 2 )
        break;
LABEL_35:
      while ( 1 )
      {
        v69 = v63[1];
        ++v63;
        v62 = v69;
        ++v65;
        if ( v69 )
          break;
LABEL_36:
        state_check_feature(1, "table [%d] dont need change\n", v65);
        if ( v65 == 2 )
          goto LABEL_37;
      }
    }
LABEL_37:
    _frame.v166 = dword_10B77C;
    ke_event_schedule_1(aPwrCalStart);
    v70 = flt_10B78C;
    _frame.v160 = (volatile int *)(dword_10B784 + 4 * v52);
    v71 = 0;
    _frame.v157 = 0;
    _frame.v162 = (volatile uint8_t *)(_frame.v150 + dword_10B788);
    _frame.v149 = 0;
    _frame.v165 = v50 + 16;
    while ( 2 )
    {
      state_check_feature(
        1,
        "/***************************************cal tx_gain_table=%d********************************/\n",
        _frame.v149);
      memset(_frame.result, 0, 0x40u);
      _frame.v194 = 1.0;
      _frame.v188 = v70;
      _frame.v187 = 8;
      _frame.v183 = 15;
      v72 = (volatile float *)&_frame.v193;
      do
        *v72++ = v70;
      while ( &_frame.v194 != v72 );
      if ( _frame.a4a )
      {
        _frame.v176 = 1792;
        _frame.a3a[1] = 2048;
        if ( _frame.v149 )
        {
          if ( _frame.v149 == 1 )
          {
            _frame.a3a[0] = 2048;
            v73 = 8;
            _frame.v190 = 4;
            _frame.v191 = 4;
            v74 = 12;
            _frame.v185 = 0x800000009LL;
            _frame.v186 = 12;
            _frame.v192 = 8;
            _frame.v163 = 4096;
          }
          else
          {
            v122 = (*(volatile uint8_t *)off_10BDCC & 0xC0) == 192;
            _frame.v190 = 6;
            _frame.v191 = 6;
            if ( v122 )
              v123 = 768;
            else
              v123 = 960;
            v74 = 12;
            _frame.v192 = 6;
            _frame.v185 = 0x900000009LL;
            _frame.a3a[0] = v123;
            _frame.v186 = 12;
            _frame.v163 = 0;
            v73 = 8;
          }
        }
        else
        {
          v74 = 14;
          _frame.v190 = 4;
          _frame.v191 = 4;
          v73 = 8;
          _frame.v185 = 0x90000000ELL;
          _frame.v186 = 14;
          _frame.a3a[0] = 896;
          _frame.v192 = 8;
          _frame.v163 = 0x2000;
        }
      }
      else
      {
        v73 = 8;
        _frame.v185 = 0x80000000BLL;
        v74 = 12;
        _frame.v186 = 12;
        if ( _frame.v149 )
        {
          *(volatile uint32_t *)_frame.a3a = dword_10B794;
          _frame.v176 = 1280;
          if ( _frame.v149 == 2 )
            *(volatile uint32_t *)_frame.a3a = 83887360;
          v73 = 7;
          v74 = 11;
          _frame.v185 = 0x90000000ALL;
          _frame.v186 = 11;
          _frame.v187 = 7;
          _frame.v190 = 2;
          _frame.v191 = 2;
          _frame.v192 = 4;
          _frame.v163 = 0;
        }
        else
        {
          _frame.v190 = 0;
          *(volatile uint32_t *)_frame.a3a = dword_10C13C;
          _frame.v176 = 2431;
          _frame.v192 = 8;
          _frame.v191 = 6;
          _frame.v163 = 4096;
        }
      }
      v75 = -100;
      v76 = _frame.v165 - 17;
      for ( j = 0; j != 32; ++j )
      {
        v78 = v76[1];
        ++v76;
        if ( (int)((v78 >> 8) & 0xF) < v73 )
        {
          v79 = j <= 15 ? j : j - 32;
          if ( v75 < v79 )
            v75 = v79;
        }
      }
      _frame.v154 = 255;
      _frame.v153 = 255;
      _frame.v156 = 255;
      _frame.v168 = v50;
      _frame.v158 = 0;
      _frame.v159 = 0;
      v80 = _frame.v165;
      v81 = _frame.v166;
      _frame.v151 = v75 + 1;
      v82 = v7;
      v83 = v70;
      v84 = 0;
      v85 = -16;
      _frame.v164 = v75;
      v86 = v75 + 1;
      v87 = 15;
      while ( 1 )
      {
        if ( v85 >= 0 )
        {
          v88 = *(v80 - 32);
          _frame.v147 = v85;
          v89 = v80 - 32;
          v90 = (v88 >> 8) & 0xF;
        }
        else
        {
          v88 = *v80;
          _frame.v147 = v85 + 32;
          v89 = v80;
          v90 = ((unsigned int)*v80 >> 8) & 0xF;
        }
        if ( SHIDWORD(v87) < v90 )
          _frame.v183 = (_frame.v183 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(v90) << 32);
        if ( (int)v87 > v90 )
          _frame.v183 = (_frame.v183 & ~0xFFFFFFFFull) | ((uint32_t)(v90) & 0xFFFFFFFFu);
        if ( v74 == v90 && !v84 )
        {
          if ( *_frame.v162 )
          {
            state_check_feature(1, "dig_pwr_ini[%d][%d]=%x ", _frame.v149, v52, *_frame.v160);
          }
          else
          {
            *_frame.v160 = (uint8_t)v88;
            *_frame.v162 = 1;
            state_check_feature(1, "ch[%d] table[%d] first_value=%x ", v52, _frame.v149, (uint8_t)v88);
          }
          v91 = *_frame.v160;
          v92 = __aeabi_i2d(*_frame.v160);
          v93 = (v93 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
          v93 = (v93 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_10BA08) << 32);
          v94 = ((uint64_t (*)())__aeabi_ddiv)(v92, v93);
          v95 = ((int (*)(uint64_t))double_to_float)(v94);
          v83 = COERCE_FLOAT(system_init_sequence(v95)) * 20.0;
          _frame.v156 = _frame.v147;
          v96 = COERCE_FLOAT(load_const_table(COERCE_INT((float)-v83 / 20.0)));
          v97 = ((uint64_t (*)())__aeabi_f2d)(COERCE_UNSIGNED_INT((float)v91 * v96));
          v98 = softfloat_float_op(v97);
          v82 = ((uint64_t (*)())__aeabi_d2lz)(v98);
          v81 = v82 | _frame.v163 | 0xFFC000;
          v84 = 1;
        }
        if ( (uint32_t)_frame.v185 == v90 && !_frame.v158 )
        {
          _frame.v153 = _frame.v147;
          _frame.v158 = 1;
        }
        if ( HIDWORD(_frame.v185) == v90 && !_frame.v159 )
        {
          _frame.v154 = _frame.v147;
          _frame.v159 = 1;
        }
        if ( v86 == v85 )
          *(volatile uint8_t *)off_10B798 = *v89;
        ++v85;
        ++v80;
        if ( v85 == 16 )
          break;
        v87 = _frame.v183;
        v74 = _frame.v186;
      }
      v50 = _frame.v168;
      _frame.v166 = v81;
      v7 = v82;
      state_check_feature(1, aAnaMaxIndexXAn, HIDWORD(_frame.v183), (uint32_t)_frame.v183, _frame.v164, *(volatile uint8_t *)off_10BA10);
      if ( _frame.v156 == 255 )
      {
        ke_event_schedule_1(aWarningNeedCha);
        ke_event_schedule_1("base_index=%d\n", 255);
        v7 = 100;
        v124 = _frame.v153;
        if ( _frame.v153 != 255 )
          goto LABEL_130;
        goto LABEL_167;
      }
      if ( _frame.v153 != 255 && _frame.v154 != 255 )
        goto LABEL_80;
      ke_event_schedule_1(aWarningNeedCha);
      v124 = _frame.v153;
      if ( _frame.v153 == 255 )
LABEL_167:
        ke_event_schedule_1("base_second_index=%d\n", v124);
LABEL_130:
      if ( _frame.v154 == 255 )
        ke_event_schedule_1("base_third_index=%d\n", 255);
LABEL_80:
      if ( _frame.v156 > 15 )
        _frame.v156 -= 32;
      if ( _frame.v153 > 15 )
        _frame.v153 -= 32;
      if ( _frame.v154 > 15 )
        _frame.v154 -= 32;
      state_check_feature(
        1,
        "base_index=%d ana_index=%x dig_pwr=%x pwr_stage_coin_index0=%x base_second_index=%2d pwr_stage_coin_index1=%x ba"
        "se_third_index=%2d\n",
        _frame.v156,
        _frame.v186,
        v7,
        (uint32_t)_frame.v185,
        _frame.v153,
        HIDWORD(_frame.v185),
        _frame.v154);
      v99 = _frame.v187;
      if ( _frame.v187 <= SHIDWORD(_frame.v183) )
      {
        v100 = (volatile float *)&_frame.v180[2 * _frame.v187 + 74];
        do
        {
          v101 = (float)(_frame.v186 - v99) * _frame.v194;
          *v100++ = v101;
          state_check_feature(1, "ana_index[%x] reduce_dig_i*100=%d \n", v99++, (int)(float)(v101 * v22));
        }
        while ( SHIDWORD(_frame.v183) >= v99 );
      }
      rf_calibrate(v81, (int)_frame.v180, _frame.a3a, 0, _frame.v167, _frame.v149, 0, v52);
      v102 = _frame.v185;
      v103 = (int16_t)_frame.v180[_frame.v186];
      v104 = (int16_t)_frame.v180[(uint32_t)_frame.v185 + 16];
      v105 = (int16_t)_frame.v180[HIDWORD(_frame.v185) + 32];
      if ( (int)_frame.v185 <= SHIDWORD(_frame.v183) )
      {
        v102 = (v102 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(&_frame.v180[_frame.v185 - 1]) << 32);
        v128 = (volatile float *)&_frame.result[_frame.v185];
        do
        {
          v129 = *(volatile uint16_t *)(HIDWORD(v102) + 2);
          v102 = (v102 & 0xFFFFFFFFull) | ((uint64_t)(uint32_t)(((uint32_t)(v102 >> 32) & 0xFFFFFFFFu) + (uint32_t)(2))) << 32;;
          util_compare_time(v129, v103, (int)_frame.v180);
          v130 = HIDWORD(_frame.v183);
          *v128++ = _frame.v181;
          v102 = (v102 & ~0xFFFFFFFFull) | ((uint32_t)(v102 + 1) & 0xFFFFFFFFu);
        }
        while ( v130 >= (int)v102 );
        v106 = (float)(_frame.v153 - _frame.v156) - *(volatile float *)&_frame.result[_frame.v185];
        state_check_feature(1, "stage_pwr_diff0*100= %d\n", (int)(float)(v106 * v22));
        temp_sensor_convert(v106, v7, (int)_frame.v180);
        state_check_feature(1, "base_index=%d dig_pwr=%x base_second_index=%d\n", _frame.v156, v7, _frame.v153);
        v102 = _frame.v185;
      }
      else
      {
        v106 = v70;
      }
      if ( SHIDWORD(v102) < (int)v102 )
      {
        v125 = &_frame.v180[HIDWORD(v102) + 16];
        v102 = (v102 & ~0xFFFFFFFFull) | ((uint32_t)(&_frame.result[HIDWORD(v102)]) & 0xFFFFFFFFu);
        do
        {
          v126 = *v125++;
          state_check_feature(1, "pwr_amp_back[1][%d]=%d ", HIDWORD(v102), v126);
          util_compare_time(v126, v104, (int)_frame.v180);
          v127 = HIDWORD(_frame.v185);
          *(volatile float *)v102 = _frame.v181;
          v102 = (v102 & ~0xFFFFFFFFull) | ((uint32_t)(v102 + 4) & 0xFFFFFFFFu);
          v107 = (float)(_frame.v154 - _frame.v153) - *(volatile float *)&_frame.result[v127];
          v102 = (v102 & 0xFFFFFFFFull) | ((uint64_t)(uint32_t)(((uint32_t)(v102 >> 32) & 0xFFFFFFFFu) + (uint32_t)(1))) << 32;;
          state_check_feature(1, "stage_pwr_diff1*100= %d\n", (int)(float)(v107 * v22));
        }
        while ( (int)_frame.v185 > SHIDWORD(v102) );
        v102 = (v102 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(HIDWORD(_frame.v185)) << 32);
      }
      else
      {
        v107 = v70;
      }
      v102 = (v102 & ~0xFFFFFFFFull) | ((uint32_t)(_frame.v187) & 0xFFFFFFFFu);
      if ( _frame.v187 < SHIDWORD(v102) )
      {
        v102 = (v102 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(&_frame.v180[_frame.v187 + 32]) << 32);
        v108 = (volatile float *)&_frame.result[_frame.v187];
        do
        {
          v109 = (int16_t)*(volatile uint16_t *)HIDWORD(v102);
          v102 = (v102 & 0xFFFFFFFFull) | ((uint64_t)(uint32_t)(((uint32_t)(v102 >> 32) & 0xFFFFFFFFu) + (uint32_t)(2))) << 32;;
          state_check_feature(1, "pwr_amp_back[2][%d]=%d ", (uint32_t)v102, v109);
          util_compare_time(v109, v105, (int)_frame.v180);
          v110 = HIDWORD(_frame.v185);
          *v108++ = _frame.v181;
          v102 = (v102 & ~0xFFFFFFFFull) | ((uint32_t)(v102 + 1) & 0xFFFFFFFFu);
        }
        while ( v110 > (int)v102 );
      }
      v111 = v70;
      v112 = 15;
      while ( 2 )
      {
        while ( 2 )
        {
          if ( v112 < 0 )
            v115 = _frame.v157 + 32;
          else
            v115 = _frame.v157;
          v116 = v115 + v112;
          v117 = ((unsigned int)v50[v115 + v112] >> 8) & 0xF;
          v118 = *(volatile float *)&_frame.result[v117];
          _frame.v184 = v117;
          v119 = (volatile unsigned int *)&v50[v115 + v112];
          if ( _frame.v164 < v112 )
          {
            if ( v117 > 9 )
              v113 = v70;
            else
              v113 = _frame.v188;
            if ( (int)_frame.v185 <= v117 )
            {
              v71 = v112 - _frame.v156;
              v120 = (float)((float)((float)((float)(v112 - _frame.v156) - v118) + v83) + v113) + *((volatile float *)&_frame.v189 + v117);
              state_check_feature(1, "tx_gain_map_idx=%d base_index=%d ", v112, _frame.v156);
              state_check_feature(
                1,
                "pwr_th*100=%-5d pwr_act*100=%-5d ",
                -100 * _frame.v156 + 100 * v112,
                (int)(float)(v118 * v22));
              temp_sensor_convert(v120, v7, (int)_frame.v180);
            }
            else
            {
              if ( SHIDWORD(_frame.v185) > v117 )
              {
                v71 = v112 - _frame.v154;
                v114 = (float)((float)((float)((float)((float)((float)(v112 - _frame.v154) - v118) + v107) + v106) + v83) + v113)
                     + *((volatile float *)&_frame.v189 + v117);
                state_check_feature(1, "tx_gain_map_idx=%d base_third_index=%d ", v112, _frame.v154);
                state_check_feature(
                  1,
                  "pwr_th*100=%-5d pwr_act*100=%-5d stage_pwr_diff0*100=%-2d stage_pwr_diff1*100=%-2d ",
                  -100 * _frame.v154 + 100 * v112,
                  (int)(float)(v118 * v22),
                  (int)(float)(v106 * v22),
                  (int)(float)(v107 * v22));
              }
              else
              {
                v71 = v112 - _frame.v153;
                v114 = (float)((float)((float)((float)((float)(v112 - _frame.v153) - v118) + v106) + v83) + v113)
                     + *((volatile float *)&_frame.v189 + v117);
                state_check_feature(1, "tx_gain_map_idx=%d base_second_index=%d ", v112, _frame.v153);
                state_check_feature(
                  1,
                  "pwr_th*100=%-5d pwr_act*100=%-5d stage_pwr_diff0*100=%-2d ",
                  -100 * _frame.v153 + 100 * v112,
                  (int)(float)(v118 * v22),
                  (int)(float)(v106 * v22));
              }
              temp_sensor_convert(v114, v7, (int)_frame.v180);
            }
            state_check_feature(1, "i=%2d ana_index=%x dig_pwr=%x \n", v116, v117, _frame.v182);
            if ( _frame.v151 == v112 )
            {
              state_check_feature(1, aMinDiffCal);
              util_compare_time(_frame.v182, *(volatile uint8_t *)off_10BDC8, (int)_frame.v180);
              v111 = _frame.v181;
            }
          }
          else
          {
            state_check_feature(1, "tx_gain_map_idx=%d ", v112);
            temp_sensor_convert(v111, LOBYTE(v50[v116]), (int)_frame.v180);
          }
          state_check_feature(1, "i=%2d ana_index=%x dig_pwr=%x \n", v116, v117, _frame.v182);
          *(volatile uint8_t *)v119 = _frame.v182;
          if ( _frame.a4a || _frame.v149 || v117 != 15 )
          {
LABEL_108:
            if ( --v112 == -17 )
              goto LABEL_120;
            continue;
          }
          break;
        }
        state_check_feature(1, aPwrReCal);
        rf_calibrate(*v119, (int)_frame.v180, _frame.a3a, 1, _frame.v167, 0, 0, 0);
        util_compare_time(_frame.v180[15], v103, (int)_frame.v180);
        v121 = _frame.v181;
        state_check_feature(1, "pwr_th*100=%-5d pwr_act*100=%-5d ", 100 * v71, (int)(float)(_frame.v181 * v22));
        _frame.v169 = ((uint64_t (*)())__aeabi_f2d)(COERCE_UNSIGNED_INT((float)v71 - v121));
if ( !((int (*)())__aeabi_dcmpgt)(_frame.v169, *(volatile uint64_t *)&dword_10BD90) && !((int (*)())__aeabi_dcmplt)(_frame.v169, *(volatile uint64_t *)&dword_10BD98) ) { state_check_feature(1, "pwr_diff*100=%d,dont need change\n", (int)(float)((float)((float)v71 - v121) * v22));
          goto LABEL_108;
        }
        temp_sensor_convert((float)v71 - v121, _frame.v182, (int)_frame.v180);
        --v112;
        state_check_feature(1, "i=%2d ana_index=%x dig_pwr=%x \n", v116, 15, _frame.v182);
        *(volatile uint8_t *)v119 = _frame.v182;
        if ( v112 != -17 )
          continue;
        break;
      }
LABEL_120:
      _frame.v157 += 32;
      _frame.v160 += 7;
      _frame.v165 += 32;
      v122 = _frame.v149++ == 2;
      ++_frame.v162;
      if ( !v122 )
        continue;
      break;
    }
    ke_event_schedule_1(aPwrCalEnd);
LABEL_10:
    _frame.v161 += 4;
    if ( _frame.v161 != a5 + 28 )
      continue;
    break;
  }
  v24 = (void *)(uintptr_t)(off_10B45C);
  v25 = dword_10B474;
  v26 = dword_10B478;
  v27 = dword_10B47C;
  v28 = dword_10B490;
  *(volatile uint32_t *)off_10B45C |= 0x400u;
  *v24 &= ~0x400u;
  ke_event_schedule_1(aDpdEnd);
  set_radio_ctrl_bits(0);
  v29 = dword_10B480;
  v30 = (volatile int *)_frame.v179;
  v31 = 0;
  while ( 2 )
  {
    if ( v31 )
    {
      if ( v31 != 1 )
      {
        v32 = v29;
        goto LABEL_15;
      }
      v39 = v27;
      v32 = v28;
    }
    else
    {
      v39 = v25;
      v32 = v26;
    }
    v40 = (volatile unsigned int *)(v39 + 4);
    v41 = &_frame.result[16 * v31 + 16];
    v42 = (volatile unsigned int *)(v39 + 484);
    do
    {
      v43 = *v41++;
      *v40 = *v40 & 0xFFF1FFFF | (v43 << 17);
      v40 += 8;
    }
    while ( v42 != v40 );
LABEL_15:
    v33 = (volatile unsigned int *)(v32 + 4);
    v34 = (volatile unsigned int *)(v32 + 484);
    v35 = v30;
    do
    {
      v36 = *v35++;
      *v33 = *v33 & 0xFFF1FFFF | (v36 << 17);
      v33 += 8;
    }
    while ( v34 != v33 );
    ++v31;
    v30 += 16;
    if ( v31 != 3 )
      continue;
    break;
  }
  set_radio_ctrl_bits2(0);
  v37 = (void *)(uintptr_t)(off_10B484);
  *(volatile uint32_t *)off_10B458 = *(volatile uint32_t *)off_10B458 & 0xFFFFFFFE | _frame.v171;
  state_check_feature(1, "tia_aux_gbit000=%d\n", (*v37 >> 21) & 7);
  return ke_event_schedule_1(aMiscDpdCalibSi_0);
}


// sdio_packet_parse @ 0x10c1b8
volatile unsigned int * sdio_packet_parse(volatile unsigned int *result, int a2, int a3, int a4) {
  unsigned int v4; // r6
  int v7; // r7
  int v8; // r10
  int v9; // r3
  int v10; // r3
  unsigned int v11; // r0
  int v12; // r0
  uint64_t v13; // r8
  double v14; // d8
  uint64_t v15; // r0
  uint64_t v16; // r2
  uint64_t v17; // r0
  uint64_t v18; // r0
  uint64_t v19; // r2
  uint64_t v20; // r0
  uint64_t v21; // r0
  uint64_t v22; // r2
  uint64_t v23; // r8
  uint64_t v24; // r0
  uint64_t v25; // r2
  uint64_t v26; // r0
  uint64_t v27; // r8
  int a5; // r6
  int v29; // r1
  int v30; // r2
  volatile int *v31; // r5
  int v32; // r0
  int v33; // r1
  int v34; // r2
  int v35; // r3
  int v36; // r0
  int v37; // r1
  int v38; // r2
  int v39; // r3
  int v40; // r1
  int v41; // r2
  int v42; // r3
  int v43; // r0
  uint32_t v44[16]; // [sp+24h] [bp-40h] BYREF

  v4 = *result;
  v7 = (uint8_t)*result >> 6;
  if ( !a3 )
  {
    if ( !a4 )
      return result;
    goto LABEL_3;
  }
  v8 = result[1];
  state_check_feature(0x2000, "cal_cfg:%x, alpha=%x\r\n", *result, v8);
  v9 = a2 - 2;
  do
  {
    *(volatile uint16_t *)(v9 + 2) = -32640;
    v9 += 2;
  }
  while ( a2 + 30 != v9 );
  *(volatile uint32_t *)(a2 + 32) = 0;
  *(volatile uint32_t *)(a2 + 36) = 0;
  v10 = a2 + 36;
  do
  {
    *(volatile uint32_t *)(v10 + 4) = 0;
    v10 += 4;
  }
  while ( a2 + 100 != v10 );
  while ( !*(volatile uint32_t *)off_10C40C )
    ;
  if ( v7 )
  {
    v11 = (*(volatile uint32_t *)off_10C410 >> 5) & 0x1F;
    if ( (*(volatile uint32_t *)off_10C410 & 0x400) != 0 )
      v11 *= 2;
    if ( (*(volatile uint32_t *)off_10C414 & 0x80000) != 0 && (*(volatile uint32_t *)off_10C414 & 0x40000) != 0 )
      v11 >>= 1;
    v12 = *(volatile uint8_t *)off_10C41C * v11;
    *(volatile uint32_t *)off_10C418 &= ~1u;
    if ( (uint8_t)v4 >> 7 )
    {
      v13 = *(volatile uint64_t *)&dword_10C3F8;
      v14 = dbl_10C3F0;
    }
    else
    {
      v13 = *(volatile uint64_t *)&dword_10C3E8;
      v14 = dbl_10C3E0;
    }
    v15 = __aeabi_i2d(v12);
    v16 = (v16 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_10C420) << 32);
    v16 = (v16 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
    v17 = ((uint64_t (*)())__aeabi_dmul)(v15, v16);
    v18 = ((uint64_t (*)())__aeabi_ddiv)(v13, v17);
    v19 = (v19 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_10C424) << 32);
    v19 = (v19 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
    v20 = ((uint64_t (*)())__aeabi_dmul)(v18, v19);
    v21 = softfloat_float_op(v20);
    v22 = (v22 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_10C420) << 32);
    v23 = v21;
    v22 = (v22 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
    v24 = ((uint64_t (*)())__aeabi_ddiv)(*(volatile uint64_t *)&v14, v22);
    v25 = softfloat_float_op(v24);
    v26 = v23;
    v27 = v25;
    *(volatile uint32_t *)off_10C440 = ((uint64_t (*)())__aeabi_d2ulz)(v26) & 0x7FFFFFFF;
    *(volatile uint32_t *)off_10C428 = dword_10C42C & (((uint64_t (*)())__aeabi_d2ulz)(v27) << 13) | *(volatile uint32_t *)off_10C428 & dword_10C430;
  }
  rf_pll_enable();
  chip_common_init((uint8_t)v4, a2, v8, (uint16_t)v4 >> 12, BYTE1(v4) & 0xF, 0);
  result = (volatile unsigned int *)mac_irq_disable();
  *(volatile uint32_t *)off_10C40C = 1;
  if ( a4 )
  {
LABEL_3:
    if ( ((*(volatile uint32_t *)off_10C400 & 0x8000000) == 0 || (*(volatile uint32_t *)off_10C404 & 0x400) != 0) && !v7 )
    {
      a5 = off_10C438;
      v29 = ((volatile uint32_t *)(uintptr_t)off_10C434)[1];
      v30 = ((volatile uint32_t *)(uintptr_t)off_10C434)[2];
      v31 = (void *)(&((volatile uint32_t *)(uintptr_t)off_10C434)[18]);
      v44[0] = ((volatile uint32_t *)(uintptr_t)off_10C434)[0];
      v44[1] = v29;
      v44[2] = v30;
      rf_pll_enable();
      v32 = *v31;
      v33 = v31[1];
      v34 = v31[2];
      v35 = v31[3];
      v31 += 4;
      v44[3] = v32;
      v44[4] = v33;
      v44[5] = v34;
      v44[6] = v35;
      v36 = *v31;
      v37 = v31[1];
      v38 = v31[2];
      v39 = v31[3];
      v31 += 4;
      v44[7] = v36;
      v44[8] = v37;
      v44[9] = v38;
      v44[10] = v39;
      v40 = v31[1];
      v41 = v31[2];
      v42 = v31[3];
      v44[11] = *v31;
      v44[12] = v40;
      v44[13] = v41;
      v44[14] = v42;
      *(volatile uint8_t *)(a5 + 4) = 0;
      v43 = off_10C43C;
      *(volatile uint8_t *)(a5 + 0xC) = 0;
      *(volatile uint8_t *)(a5 + 0x14) = 0;
      *(volatile uint8_t *)(a5 + 0x1C) = 0;
      *(volatile uint8_t *)(a5 + 0x24) = 0;
      *(volatile uint8_t *)(a5 + 0x2C) = 0;
      *(volatile uint8_t *)(a5 + 0x34) = 0;
      sdio_core_setup(v43, (volatile uint8_t *)(a2 + 125), a5);
      phy_calibrate((int)v44, off_10C43C, a2 + 104, a2 + 125, (volatile uint16_t *)a5, 6, 1);
      *(volatile uint8_t *)(a5 + 4) = 0;
      *(volatile uint8_t *)(a5 + 0xC) = 0;
      *(volatile uint8_t *)(a5 + 0x14) = 0;
      *(volatile uint8_t *)(a5 + 0x1C) = 0;
      *(volatile uint8_t *)(a5 + 0x24) = 0;
      *(volatile uint8_t *)(a5 + 0x2C) = 0;
      *(volatile uint8_t *)(a5 + 0x34) = 0;
      return (volatile unsigned int *)mac_irq_disable();
    }
  }
  return result;
}


// sdio_transfer_setup @ 0x10c444
int sdio_transfer_setup(int a1, int a2, int a3, int a4, uint8_t a5, uint8_t a6) {
  int result; // r0
  int v10; // r0

  format_log_message(a1, a2, a2, 0, 0, 0);
  result = (int)sdio_packet_parse((volatile unsigned int *)a3, a4, a5, a6);
  if ( a5 )
  {
    if ( a1 == 1 )
      v10 = 28;
    else
      v10 = 3;
    return radio_event_loop(v10, (volatile uint16_t *)a4);
  }
  return result;
}


// sdio_bus_reset @ 0x10c490
int sdio_bus_reset() {
  volatile int *v0; // r2
  volatile unsigned int *v1; // r1
  volatile uint32_t *v2; // r4
  int v3; // r0
  unsigned int v4; // r3
  unsigned int v5; // r5
  int result; // r0

  v0 = (volatile int *)off_10C540;
  *((volatile uint32_t *)off_10C53C + 64) = 6;
  v0[1] &= ~0x40000u;
  v0[1] |= 0x20000u;
  while ( (v0[12] & 0x44) != 4 )
    ;
  v1 = (volatile unsigned int *)off_10C54C;
  v2 = (void *)(uintptr_t)(off_10C53C);
  v3 = dword_10C550;
  v4 = (unsigned int)(((unsigned int)dword_10C548 * (uint64_t)*(volatile unsigned int *)off_10C544) >> 32) >> 18;
  v5 = v4 | 0x80140000;
  v4 |= 0x140000u;
  *(volatile uint32_t *)off_10C54C = v4;
  *v1 = v5;
  *v1 = v4;
  v0[1] |= 0x18802u;
  v2[81] = 8;
  *v0 = *v0 & 0x3BF | 0x40 | *v0 & v3;
  v2[14] |= 1u;
  v0[17] |= 0x88000000;
  v0[21] &= ~0x200000u;
  result = v3 & v0[21];
  v0[21] = v0[21] & 0x3FD | 2 | result;
  v0[21] &= ~0x800u;
  return result;
}



// sdio_irq_enable @ 0x10c554
int sdio_irq_enable() {
  volatile int *v0; // r2
  volatile int *v1; // r0
  volatile int *v2; // r1
  volatile uint32_t *v3; // r12
  volatile uint32_t *v4; // r4
  int v5; // r3
  volatile uint32_t *v6; // r7
  volatile uint32_t *v7; // r6
  volatile uint32_t *v8; // r5
  int v9; // r3
  int v10; // r3
  volatile uint32_t *v11; // r3

  v0 = (volatile int *)off_10C644;
  v1 = (volatile int *)off_10C648;
  v2 = (volatile int *)off_10C64C;
  v3 = (void *)(uintptr_t)(off_10C684);
  *(volatile uint32_t *)off_10C644 |= 0x3F000000u;
  v4 = (void *)(uintptr_t)(off_10C650);
  v5 = dword_10C654;
  *(volatile uint32_t *)off_10C650 = dword_10C654;
  *v1 = v5 + 1578562697;
  *v2 = dword_10C658;
  v6 = (void *)(uintptr_t)(off_10C65C);
  v7 = (void *)(uintptr_t)(off_10C660);
  v8 = (void *)(uintptr_t)(off_10C664);
  *v3 = 2423;
  *v6 = dword_10C668;
  *v7 = 37890;
  v4 += 131075;
  v9 = dword_10C66C;
  *v8 = dword_10C66C;
  v2 += 717332;
  v1 += 717334;
  v0 += 131615;
  *v4 = dword_10C670;
  *v2 = v9;
  *v1 = v9;
  *v0 = v9;
  v6[717338] = 2100;
  v10 = dword_10C674;
  v7[749881] = dword_10C674;
  v2 += 32546;
  v10 += 875888655;
  *v2 = v10;
  v0 += 32602;
  *(volatile uint32_t *)off_10C678 = v10 - 943588895;
  v1[32584] = 909522486;
  *v0 = 65280;
  v11 = (void *)(uintptr_t)(off_10C67C);
  v4[33032] = dword_10C680;
  v2[42] = 21333;
  *v11 = (int)(uintptr_t)((volatile char *)v0 + 1441354102);
  return 21333;
}



// bt_dispatch @ 0x10c688
int bt_dispatch() {
  sdio_bus_reset();
  return sdio_irq_enable();
}



// pmu_clock_config @ 0x10c698
volatile int *pmu_clock_config() {
  volatile unsigned int *v0; // r3
  volatile unsigned int *v1; // r2
  volatile int *result; // r0
  int v3; // r4

  v0 = (volatile unsigned int *)off_10C740;
  v1 = (volatile unsigned int *)off_10C744;
  result = (volatile int *)off_10C748;
  *(volatile uint32_t *)off_10C740 = *(volatile uint32_t *)off_10C740 & 0xFFFFFFFC | 2;
  v3 = dword_10C74C;
  *v0 = *v0 & 0xFFFFFFF3 | 8;
  *v0 = *v0 & 0xFFFFFCFF | 0x200;
  *v0 = *v0 & 0xFFFFF3FF | 0x800;
  *v0 = *v0 & 0xFFFFCFFF | 0x2000;
  *v1 = *v1 & 0xFCFFFFFF | 0x2000000;
  *v1 = *v1 & 0xF3FFFFFF | 0x8000000;
  *v1 = *v1 & 0xCFFFFFFF | 0x20000000;
  *v1 = *v1 & 0x3FFFFFFF | 0x80000000;
  *v0 |= 0x30000u;
  *v0 |= 0xC0000u;
  *v0 |= 0x300000u;
  *v0 |= 0xC00000u;
  *v0 |= 0x3000000u;
  *result = v3;
  return result;
}



// clear_context_182b48 @ 0x10c750
volatile int *clear_context_182b48() {
  int v0; // r4
  int v1; // zf
  uint8_t v2; // r1
  volatile int **v3; // r4

  v0 = *((volatile uint32_t *)off_10C7C4 + 23);
  memset((volatile int *)dword_10C7C8, 0, 0x28u);
  memset((volatile int *)dword_10C7CC, 0, 0x1E6Cu);
  if ( (*(volatile uint32_t *)off_10C7D0 & 8) != 0 )
  {
    while ( (*(volatile uint32_t *)off_10C7D0 & 0x10) == 0 )
      ;
    v3 = (volatile int **)off_10C7D4;
  }
  else
  {
    v2 = v0 & 3;
    v1 = (v0 & 3) == 0;
    v3 = (volatile int **)off_10C7D4;
    *(volatile uint32_t *)off_10C7D0 |= 8u;
    if ( v1 )
      memset(*v3, v2, 0x248u);
    *(volatile uint32_t *)off_10C7D0 |= 0x10u;
  }
  (*v3)[145] = *(volatile uint32_t *)off_10C7D8;
  return pmu_clock_config();
}



// pmu_wait_status @ 0x10c7dc
int pmu_wait_status() {
  int v0; // r4
  int result; // r0
  volatile int *v2; // r2
  volatile uint8_t *v3; // r3
  volatile uint32_t *v4; // r2

  v0 = *(volatile uint32_t *)off_10C810 & 0x1F00;
  if ( v0 )
  {
    result = set_system_flag_1(2048);
    v2 = (volatile int *)off_10C814;
    v3 = (void *)(uintptr_t)(off_10C81C);
    *(volatile uint32_t *)off_10C818 = v0;
    *v2 = v0;
    if ( *v3 )
    {
      v4 = (void *)(uintptr_t)(off_10C820);
      v3[1] = 1;
      *v4 |= 1u;
    }
  }
  return result;
}



// pmu_poll_delay @ 0x10c824
int pmu_poll_delay(char a1) {
  int v1; // r5
  volatile uint8_t *v2; // r11
  int v3; // r8
  volatile int *v4; // r7
  volatile uint32_t *v5; // r10
  unsigned int v6; // r1
  unsigned int v7; // r2
  unsigned int v8; // r4
  volatile int *v9; // r9
  volatile uint32_t *v10; // r0
  int v11; // r1
  volatile uint32_t *v12; // r3
  int v13; // r1
  int v14; // r2
  int v15; // r0
  volatile uint8_t *v16; // r1
  int result; // r0

  set_system_flag_2(2048);
  v1 = ((volatile uint32_t *)(uintptr_t)off_10C910)[0];
  if ( *(volatile uint32_t *)(((volatile uint32_t *)(uintptr_t)off_10C910)[0] + 572) )
  {
    v2 = (volatile uint8_t *)off_10C928;
    v3 = dword_10C92C;
    v4 = (volatile int *)off_10C914;
    v5 = (void *)(uintptr_t)(off_10C930);
    while ( 1 )
    {
      v6 = v2[1621];
      v7 = v2[1622];
      if ( v6 >= v7 )
        break;
      v8 = v2[1620]
         + 1
         - 81 * ((unsigned int)(((unsigned int)v3 * (uint64_t)((unsigned int)v2[1620] + 1)) >> 32) >> 6);
      v2[1621] = v6 + 1;
      v2[1620] = v8;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *v4 = 1;
      }
      v9 = (volatile int *)off_10C934;
      ++*(volatile uint32_t *)off_10C934;
      while ( !*v5 )
        ;
      v10 = list_pop_front(v1 + 572);
      v11 = *v9;
      *v5 = 1;
      v12 = v10;
      if ( v11 )
      {
        v13 = v11 - 1;
        v14 = *v4;
        *v9 = v13;
        if ( !v13 )
        {
          if ( v14 )
            __enable_irq();
        }
      }
      v15 = dword_10C91C;
      v16 = &v2[20 * v8];
      *((volatile uint32_t *)v16 + 1) = (int)(uintptr_t)((volatile char *)v12 + *(volatile uint32_t *)(uintptr_t)(off_10C918));
      check_abort_flag(v15, (void *)(v16));
      if ( !*(volatile uint32_t *)(v1 + 572) )
        goto LABEL_13;
    }
    printf_wrapper("rxused=%d, total=%d\r\n", v6, v7);
  }
LABEL_13:
  result = set_system_flag_1(256);
  *(volatile uint32_t *)off_10C920 = (1 << (a1 + 8)) & 0x1F00;
  return result;
}


// pmu_status_interrupt @ 0x10c938
int pmu_status_interrupt() {
  int v0; // r4
  int result; // r0
  volatile uint32_t *v2; // r2
  volatile uint8_t *v3; // r3
  volatile uint32_t *v4; // r2
  volatile uint32_t *v5; // r2
  volatile uint32_t *v6; // r2

  v0 = *(volatile uint32_t *)off_10C9F0;
  if ( (*(volatile uint32_t *)off_10C9F0 & 0x20) != 0 )
  {
    v6 = (void *)(uintptr_t)(off_10C9F8);
    *(volatile uint32_t *)off_10CA10 = 32;
    *v6 = 32;
    set_system_flag_1(0x80000);
  }
  result = v0 << 27;
  if ( (v0 & 0x10) != 0 )
  {
    v5 = (void *)(uintptr_t)(off_10C9F8);
    *(volatile uint32_t *)off_10CA10 = 16;
    *v5 = 16;
    result = set_system_flag_1(0x100000);
  }
  if ( (v0 & 2) != 0 )
  {
    result = set_system_flag_1(0x8000000);
    *(volatile uint32_t *)off_10CA10 = 2;
  }
  if ( (v0 & 0x40000000) != 0 )
  {
    result = check_radio_flag_1(1);
    *(volatile uint32_t *)off_10C9F8 = 0x40000000;
  }
  if ( v0 < 0 )
  {
    v2 = (void *)(uintptr_t)(off_10C9F8);
    *(volatile uint32_t *)off_10C9F4 = 0x80000000;
    *v2 = 0x80000000;
  }
  if ( (v0 & 0x20000000) == 0 )
  {
    v3 = (void *)(uintptr_t)(off_10C9FC);
    if ( !*(volatile uint8_t *)off_10C9FC || !*(volatile uint32_t *)off_10CA00 )
      return result;
LABEL_16:
    v4 = (void *)(uintptr_t)(off_10CA04);
    v3[1] = 1;
    *v4 |= 1u;
    return result;
  }
  v3 = (void *)(uintptr_t)(off_10C9FC);
  *(volatile uint32_t *)off_10C9F8 = 0x20000000;
  if ( *v3 )
    goto LABEL_16;
  if ( (*(volatile uint32_t *)off_10CA08 & dword_10CA0C) == 0x10000 )
    return log_and_check_hw();
  return result;
}



// pmu_isr_224 @ 0x10ca3c
int pmu_isr_224() {
  volatile uint32_t *v0; // r4
  int v1; // r0
  int v2; // r3
  int v4; // r3

  v0 = (void *)(uintptr_t)(off_10CA94);
  while ( !*(volatile uint32_t *)off_10CA94 )
    ;
  if ( *(volatile uint32_t *)(*(volatile uint32_t *)off_10CA98 + 548) )
  {
    v1 = (int)(uintptr_t)(list_pop_front(*(volatile uint32_t *)off_10CA98 + 548));
    v2 = **(volatile int16_t **)off_10CA9C;
    *v0 = 1;
    if ( v2 >= 0 || v1 )
      return v1 + 20;
  }
  else
  {
    v4 = **(volatile int16_t **)off_10CA9C;
    *(volatile uint32_t *)off_10CA94 = 1;
    if ( v4 >= 0 )
      return 20;
  }
  mmio_irq_clear(dword_10CAA4, dword_10CAA0, 1101);
  return 20;
}



// pmu_isr_214 @ 0x10caa8
int pmu_isr_214() {
  volatile uint32_t *v0; // r4
  int result; // r0

  v0 = (void *)(uintptr_t)(off_10CAD4);
  while ( !*(volatile uint32_t *)off_10CAD4 )
    ;
  result = *(volatile uint32_t *)(*(volatile uint32_t *)off_10CAD8 + 532);
  if ( result )
  {
    result = (int)(uintptr_t)(list_pop_front(*(volatile uint32_t *)off_10CAD8 + 532));
    *v0 = 1;
    if ( result )
      result += 4;
  }
  else
  {
    *(volatile uint32_t *)off_10CAD4 = 1;
  }
  return result;
}



// nullsub_6 @ 0x10cadc
int nullsub_6(void) {
  return 0;
}


// pmu_ctrl_write_8 @ 0x10cae0
void pmu_ctrl_write_8() {
  *(volatile uint32_t *)off_10CAE8 = 8;
}



// pmu_ctrl_write_256 @ 0x10caec
void pmu_ctrl_write_256() {
  *(volatile uint32_t *)off_10CAF8 = 256;
}



// pmu_ctrl_write_128 @ 0x10cafc
void pmu_ctrl_write_128() {
  *(volatile uint32_t *)off_10CB04 = 128;
}



// pkt_buf_alloc @ 0x10cb08
int pkt_buf_alloc(volatile uint16_t *a1) {
  volatile int16_t **v2; // r7
  int v3; // r0
  volatile int16_t *v4; // r6
  int v5; // r4
  int v6; // r2
  unsigned int v7; // r7
  volatile int *v8; // r3
  volatile int *v9; // r2
  int v10; // r1
  int v11; // t1
  volatile uint32_t *v12; // r1
  int16_t v13; // r3

  v2 = (volatile int16_t **)off_10CBC8;
  v3 = mem_alloc_align((uint16_t)a1[5] + 16);
  v4 = *v2;
  v5 = v3;
  if ( **v2 < 0 && !v3 )
  {
    mmio_irq_clear(dword_10CBE0, dword_10CBD8, 1358);
    v4 = *v2;
  }
  v6 = (uint16_t)a1[5];
  v7 = (uint16_t)a1[3];
  *(volatile uint16_t *)(v5 + 4) = a1[2];
  *(volatile uint16_t *)(v5 + 8) = 13;
  *(volatile uint16_t *)(v5 + 10) = v6;
  *(volatile uint16_t *)(v5 + 6) = v7;
  *(volatile uint32_t *)v5 = 0;
  v8 = (volatile int *)(a1 + 6);
  if ( v6 )
  {
    v9 = (volatile int *)((volatile char *)a1 + ((v6 - 1) & 0xFFFFFFFC) + 16);
    v10 = v5 + 8;
    do
    {
      v11 = *v8++;
      *(volatile uint32_t *)(v10 + 4) = v11;
      v10 += 4;
    }
    while ( v8 != v9 );
  }
  if ( *v4 < 0 )
  {
    if ( v7 > 0xE )
    {
      mmio_irq_clear(dword_10CBE8, dword_10CBE4, 183);
      mmio_irq_clear(dword_10CBDC, dword_10CBD8, 1375);
    }
    else if ( v7 > 0xC )
    {
      mmio_irq_clear(dword_10CBDC, dword_10CBD8, 1375);
    }
  }
  if ( **(volatile uint8_t **)off_10CBCC == 3 )
  {
    v12 = (void *)(uintptr_t)(off_10CBD4);
    v13 = *((volatile uint8_t *)off_10CBD0 + 21);
    *((volatile uint8_t *)off_10CBD0 + 21) = v13 + 1;
    a1[4] = v13;
    *v12 = 4;
  }
  return (int)(uintptr_t)(hci_evt_send(v5 + 12));
}



// pmu_isr_extra @ 0x10cbec
int pmu_isr_extra() {
  volatile uint32_t *v0; // r4
  volatile int *v1; // r7
  volatile uint32_t *v2; // r6
  int v3; // r0
  int result; // r0

  v0 = (void *)(uintptr_t)(off_10CC1C);
  if ( (*(volatile uint32_t *)off_10CC1C & 2) != 0 )
  {
    v1 = (volatile int *)off_10CC20;
    v2 = (void *)(uintptr_t)(off_10CC24);
    do
    {
      v3 = *v1;
      *v2 = 2;
      pkt_buf_alloc((volatile uint16_t *)(v3 + 4));
    }
    while ( (*v0 & 2) != 0 );
  }
  result = set_system_flag_2(0x8000000);
  *(volatile uint32_t *)off_10CC28 = 2;
  return result;
}



// host_event_process @ 0x10cc2c
volatile uint32_t * host_event_process(int a1) {
  volatile uint8_t **v1; // r7
  volatile uint8_t *v2; // r2
  int v3; // r3
  int v5; // r8
  int v6; // r6
  volatile uint32_t *v7; // r5
  volatile uint32_t *v8; // r9
  unsigned int v9; // r2
  int v10; // r3
  volatile uint32_t *v11; // r6
  volatile uint32_t *v12; // r3
  int v13; // r0
  int v14; // r1
  uint16_t v15; // lr
  volatile uint8_t *v16; // r6
  unsigned int v17; // r2
  uint16_t v18; // r12
  int v19; // r8
  volatile int *v20; // r3
  int v21; // r10
  int v22; // r3
  int v23; // r0
  char v24; // r2
  volatile int *v25; // r6
  int v26; // r0
  int v27; // r3
  int v28; // r2
  volatile uint32_t *v29; // r0
  uint16_t v30; // r2
  uint16_t v32; // r1
  uint16_t v33; // r2
  volatile uint8_t *v34; // r3
  volatile int *v35; // r6
  int v36; // r0
  int v37; // r3
  int v38; // r2
  volatile uint32_t *v39; // r5
  volatile uint32_t *v40; // r0
  int v41; // r3
  int v42; // r3
  volatile int *v43; // r5
  int v44; // r0
  int v45; // r2
  int v46; // r1
  int v47; // r0
  int v48; // [sp+0h] [bp-8h]
  int v49; // [sp+4h] [bp-4h]

  v1 = (volatile uint8_t **)off_10CEFC;
  v2 = *(volatile uint8_t **)off_10CEFC;
  v3 = **(volatile uint8_t **)off_10CEFC;
  if ( v3 != 3 )
  {
    v5 = 0;
    v6 = 0;
    goto LABEL_3;
  }
  v39 = (void *)(uintptr_t)(off_10CF04);
  while ( !*(volatile uint32_t *)off_10CF04 )
    ;
  if ( !*(volatile uint32_t *)(((volatile uint32_t *)(uintptr_t)off_10CF08)[0] + 516) )
  {
    v42 = **(volatile int16_t **)off_10CF00;
    *(volatile uint32_t *)off_10CF04 = 1;
    if ( v42 >= 0 )
    {
      v6 = 4;
      v5 = 4;
      goto LABEL_50;
    }
    goto LABEL_71;
  }
  v40 = list_pop_front(((volatile uint32_t *)(uintptr_t)off_10CF08)[0] + 516);
  v41 = **(volatile int16_t **)off_10CF00;
  *v39 = 1;
  if ( v41 < 0 )
  {
    if ( v40 )
    {
      v5 = (int)(v40 + 1);
      if ( v40 == (volatile uint32_t *)-4 )
      {
        mmio_irq_clear((int)aHostMsgBuf0, (int)aIpcEmbKmsgFwd, 1567);
        v6 = v5;
        v2 = *v1;
        goto LABEL_50;
      }
      goto LABEL_49;
    }
LABEL_71:
    v6 = 4;
    mmio_irq_clear((int)aHostmsgbuf0, (int)aIpcEmbHostmsgb, 973);
    v5 = 4;
    v2 = *v1;
    goto LABEL_50;
  }
  v5 = (int)(v40 + 1);
LABEL_49:
  v2 = *v1;
  v6 = v5;
LABEL_50:
  *(volatile uint32_t *)(v6 + 8) = dword_10CF28;
  v3 = *v2;
LABEL_3:
  if ( v3 == 1 )
  {
    if ( *(volatile uint16_t *)(a1 + 10) <= 0x6Cu )
      v7 = (void *)(uintptr_t)(critical_enter_6());
    else
      v7 = (volatile uint32_t *)(*(int ( **)(uint32_t))(*(volatile uint32_t *)(*(volatile uint32_t *)off_10CF24 + 8) + 16))(*(volatile uint32_t *)(*(volatile uint32_t *)off_10CF24 + 4));
    if ( !v7 )
      goto LABEL_59;
    v32 = *(volatile uint16_t *)(a1 + 6);
    v33 = *(volatile uint16_t *)(a1 + 8);
    v7[3] = dword_10CF28;
    v34 = *v1;
    *((volatile uint16_t *)v7 + 3) = v32;
    *((volatile uint16_t *)v7 + 4) = v33;
    v6 = (int)(v7 + 1);
    if ( *v34 != 2 )
      goto LABEL_5;
  }
  else
  {
    v7 = nullptr;
    if ( v3 != 2 )
    {
LABEL_5:
      v8 = nullptr;
      goto LABEL_6;
    }
  }
  if ( *(volatile uint16_t *)(a1 + 10) <= 0x6Cu )
    v7 = (void *)(uintptr_t)(int_disable_set_flag());
  else
    v7 = (volatile uint32_t *)(*(int ( **)(uint32_t))(*(volatile uint32_t *)(*(volatile uint32_t *)off_10CF24 + 8) + 16))(*(volatile uint32_t *)(*(volatile uint32_t *)off_10CF24 + 4));
  if ( !v7 )
  {
LABEL_59:
    printf_wrapper(
      "ipc_emb_kmsg_fwd: no buffer msgid=%x,srcid=%x,dstid=%x\r\n",
      *(volatile uint16_t *)(a1 + 4),
      *(volatile uint16_t *)(a1 + 8),
      *(volatile uint16_t *)(a1 + 6));
    return (void *)(uintptr_t)(jump_to_tx_entry((int)(uintptr_t)((volatile char *)a1)));
  }
  if ( !*((volatile uint32_t *)off_10CF10 + 2057) )
  {
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(volatile uint32_t *)off_10CFD8 = 1;
    }
    v43 = (volatile int *)off_10CFDC;
    ++*(volatile uint32_t *)off_10CFDC;
    v44 = ((int (*)())rf_calib_init)();
    if ( *v43 )
    {
      v45 = *v43 - 1;
      v46 = *(volatile uint32_t *)off_10CFD8;
      *v43 = v45;
      if ( !v45 )
      {
        if ( v46 )
          __enable_irq();
      }
    }
    v49 = v44;
    v48 = list_length((volatile uint32_t **)dword_10CFE0);
    v47 = list_length((volatile uint32_t **)dword_10CFE4);
    printf_wrapper("err!!! ipc msg no buffer for usb in %d, free %d, %d\r\n", v48, v47, v49);
    return (void *)(uintptr_t)(jump_to_tx_entry((int)(uintptr_t)((volatile char *)a1)));
  }
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_10CF18 = 1;
  }
  v35 = (volatile int *)off_10CF1C;
  v36 = dword_10CF2C;
  ++*(volatile uint32_t *)off_10CF1C;
  v8 = list_pop_front(v36);
  if ( *v35 )
  {
    v37 = *v35 - 1;
    v38 = *(volatile uint32_t *)off_10CF18;
    *v35 = v37;
    if ( !v37 )
    {
      if ( v38 )
        __enable_irq();
    }
  }
  *(volatile uint16_t *)v7 = *(volatile uint16_t *)(a1 + 10) + 12;
  *((volatile uint8_t *)v7 + 2) = 17;
  *((volatile uint8_t *)v7 + 3) = 0;
  v6 = (int)(v7 + 1);
LABEL_6:
  v9 = *(volatile uint16_t *)(a1 + 10);
  *(volatile uint16_t *)v6 = *(volatile uint16_t *)(a1 + 4);
  *(volatile uint16_t *)(v6 + 6) = v9;
  if ( v9 )
  {
    if ( **(volatile int16_t **)off_10CF00 < 0 && v9 > 0x400 )
    {
      mmio_irq_clear((int)aKmsgSrcParamLe, (int)aIpcEmbKmsgFwd, 1671);
      v9 = *(volatile uint16_t *)(a1 + 10);
    }
    memcpy((volatile char *)(v6 + 12), (volatile char *)(a1 + 12), v9);
    v10 = **v1;
    if ( v10 != 3 )
    {
LABEL_8:
      if ( v10 != 2 )
        goto LABEL_9;
LABEL_16:
      v13 = *(volatile uint16_t *)(a1 + 10);
      if ( (v13 & 3) != 0 )
      {
        v15 = (uint8_t)(4 - (v13 & 3));
        v14 = (uint8_t)(4 - (v13 & 3));
      }
      else
      {
        v14 = 0;
        v15 = 0;
      }
      v16 = (void *)(uintptr_t)(off_10CF10);
      v17 = *((volatile uint16_t *)off_10CF10 + 4122);
      if ( v17 > 0x186 )
      {
        v19 = 0;
        v17 = (v17 & ~0xFFFFu) | ((uint16_t)(0) & 0xFFFFu);
        v18 = 1;
      }
      else
      {
        v18 = v17 + 1;
        v19 = 8 * v17;
      }
      v20 = (volatile int *)off_10CF14;
      *((volatile uint16_t *)v8 + 6) = v17;
      v21 = *v20;
      v22 = v13 + 16;
      v23 = v21 + v19;
      *(volatile uint32_t *)(v23 + 4) = (int)(uintptr_t)(v7);
      *(volatile uint16_t *)(v21 + v19) = v15 + v22;
      *(volatile uint8_t *)(v23 + 3) = *(volatile uint8_t *)(v21 + v19 + 3) & 0x31 | 4;
      v24 = v16[3074];
      *((volatile uint16_t *)v16 + 4122) = v18;
      v16[3074] = v24 + 1;
      v8[1] = v21 + v19;
      v8[2] = v22 + v14;
      *((volatile uint8_t *)v8 + 14) = 1;
      *v8 = 0;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(volatile uint32_t *)off_10CF18 = 1;
      }
      v25 = (volatile int *)off_10CF1C;
      v26 = dword_10CF20;
      ++*(volatile uint32_t *)off_10CF1C;
      check_abort_flag(v26, v8);
      ((int (*)())rf_calib_init)();
      if ( *v25 )
      {
        v27 = *v25 - 1;
        v28 = *(volatile uint32_t *)off_10CF18;
        *v25 = v27;
        if ( !v27 )
        {
          if ( v28 )
            __enable_irq();
        }
      }
      if ( **v1 != 1 )
        return (void *)(uintptr_t)(jump_to_tx_entry((int)(uintptr_t)((volatile char *)a1)));
      goto LABEL_27;
    }
  }
  else
  {
    v10 = **v1;
    if ( v10 != 3 )
      goto LABEL_8;
  }
  v11 = (void *)(uintptr_t)(off_10CF04);
  while ( !*(volatile uint32_t *)off_10CF04 )
    ;
  check_abort_flag(((volatile uint32_t *)(uintptr_t)off_10CF08)[0] + 524, (volatile uint32_t *)(v5 - 4));
  v12 = (void *)(uintptr_t)(off_10CF0C);
  *v11 = 1;
  *v12 = 2;
  v10 = **v1;
  if ( v10 == 2 )
    goto LABEL_16;
LABEL_9:
  if ( v10 != 1 )
    return (void *)(uintptr_t)(jump_to_tx_entry((int)(uintptr_t)((volatile char *)a1)));
LABEL_27:
  v29 = (void *)(uintptr_t)(critical_enter_0());
  if ( !v29 )
  {
    printf_wrapper(aSendMsgCfgToHo);
    return (void *)(uintptr_t)(jump_to_tx_entry((int)(uintptr_t)((volatile char *)a1)));
  }
  *(volatile uint16_t *)v7 = *(volatile uint16_t *)(a1 + 10) + 12;
  *((volatile uint8_t *)v7 + 2) = 17;
  *((volatile uint8_t *)v7 + 3) = 0;
  v30 = *(volatile uint16_t *)(a1 + 10);
  v29[1] = 0;
  *v29 = (int)(uintptr_t)(v7);
  v29[2] = (uint16_t)(v30 + 16) | 0x80000000;
  ke_mutex_lock((int)v29);
  return (void *)(uintptr_t)(jump_to_tx_entry((int)(uintptr_t)((volatile char *)a1)));
}


// gpio_pad_config @ 0x10d000
int gpio_pad_config() {
  volatile uint32_t *v0; // r1
  volatile uint32_t *v1; // r4
  volatile uint32_t *v2; // r3

  v0 = (void *)(uintptr_t)(off_10D048);
  v1 = (void *)(uintptr_t)(off_10D04C);
  v2 = (void *)(uintptr_t)(off_10D050);
  *(volatile uint32_t *)off_10D04C = 13369344;
  *v0 = 13369344;
  *v2 &= 0xFFFFFFCF;
  *v2 &= 0xFFFFFF3F;
  *v2 &= 0xFFFFCFFF;
  *v2 &= 0xFFFF3FFF;
  *v1 = 0x8000000;
  *v0 = 0x8000000;
  *v2 &= 0xFF3FFFFF;
  return 0x8000000;
}



// hw_reg_write @ 0x10d054
int hw_reg_write(int a1) {
  int result; // r0
  volatile uint32_t *v3; // r3

  result = ke_event_schedule_1("chan notify: %x\r\n", a1);
  v3 = (void *)(uintptr_t)(off_10D078);
  *(volatile uint32_t *)off_10D074 = a1;
  *v3 = 0x1000000;
  return result;
}


// clock_enable @ 0x10d07c
void clock_enable() {
  *(volatile uint32_t *)off_10D088 = 0x2000000;
}



// clock_disable @ 0x10d08c
void clock_disable() {
  *(volatile uint32_t *)off_10D098 = 0x4000000;
}



// status_poll @ 0x10d15c
int status_poll() {
  int v0; // r4
  volatile char *v2; // r2
  volatile unsigned int v3; // r1
  unsigned int v4; // r1
  unsigned int v5; // r4
  int v6; // r3
  int v7; // r5

  if ( (*((volatile uint32_t *)off_10D1E0 + 75) & 0x80) == 0 )
    return 1;
  v0 = (*(volatile uint32_t *)off_10D1E4 >> 3) & 1;
  if ( (*(volatile uint32_t *)off_10D1E4 & 8) != 0 )
  {
    v0 = (*(volatile uint32_t *)off_10D1E4 >> 1) & 1;
    if ( (*(volatile uint32_t *)off_10D1E4 & 2) != 0 )
    {
      v2 = (volatile char *)off_10D1E4 + 5050236;
      *(volatile uint32_t *)off_10D1E8 = 0x200000;
      *((volatile uint32_t *)v2 + 1) |= 0x400000u;
      state_check_feature(2, aAsk);
      v3 = (*(volatile uint32_t *)0x40501010u);
      v4 = v3 + 2000;
      while ( 1 )
      {
        v5 = *(volatile uint32_t *)off_10D1F4;
        v6 = v4 - (*(volatile uint32_t *)0x40501010u);
        v7 = *(volatile uint32_t *)off_10D1F4 & 0x300000;
        if ( v6 < 0 )
          break;
        if ( v7 )
          goto LABEL_10;
      }
      ke_event_schedule_1(aAskto);
LABEL_10:
      *(volatile uint32_t *)off_10D1FC = v7;
      v0 = (v5 >> 20) & 1;
      state_check_feature(2, "a_e:%d\n", v0);
    }
  }
  return v0;
}


// power_mode_set @ 0x10d204
int power_mode_set(int result) {
  if ( result == 1 )
  {
    *(volatile uint32_t *)off_10D248 = 0x40000;
  }
  else if ( result == 2 )
  {
    *(volatile uint32_t *)off_10D248 = 0x80000;
  }
  else if ( **(volatile int16_t **)off_10D250 < 0 )
  {
    result = mmio_irq_clear(dword_10D258, dword_10D254, 2118);
  }
  *((volatile uint32_t *)off_10D24C + 1) |= 0x400000u;
  return result;
}



// clear_182b70_struct @ 0x10d25c
volatile int *clear_182b70_struct() {
  return memset((volatile int *)dword_10D268, 0, 0x38u);
}



