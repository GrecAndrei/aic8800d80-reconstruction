// rf_get_tx_pwr @ 0x13cbec
uint64_t rf_get_tx_pwr(int a1, volatile uint16_t *a2, int a3, int a4, int a5) {
  volatile char *v9; // r6
  int v10; // r5
  volatile int16_t *v11; // r4
  signed int v12; // r5
  uint64_t v13; // kr00_8
  unsigned int v14; // r2
  unsigned int v15; // r6
  int v16; // lr
  int v17; // r7
  volatile char *v18; // r1
  int v19; // r9
  int v20; // t1
  unsigned int v21; // r12
  volatile int *v22; // r7
  volatile uint32_t *v23; // r8
  int v24; // r10
  int v25; // r6
  volatile int16_t *v26; // r2
  volatile uint64_t *v27; // r3
  int v28; // t1
  signed int v29; // r3
  int v30; // r3
  volatile uint64_t *v31; // r9
  volatile uint8_t *v32; // r3
  volatile uint8_t *v33; // r5
  int v34; // r4
  int v35; // r5
  volatile uint64_t *v36; // r3
  struct __attribute__((packed)) { uint32_t v37[3]; // [sp+4h] [bp-110h] BYREF
  int v38; // [sp+10h] [bp-104h] BYREF
  int v39; // [sp+14h] [bp-100h]
  int v40; // [sp+18h] [bp-FCh]
  uint64_t v41; // [sp+1Ch] [bp-F8h] BYREF
  int v42; // [sp+24h] [bp-F0h]
  int v43; // [sp+28h] [bp-ECh]
  uint64_t v44; // [sp+2Ch] [bp-E8h] BYREF
  int v45; // [sp+34h] [bp-E0h]
  int v46; // [sp+38h] [bp-DCh]
  uint64_t v47; // [sp+3Ch] [bp-D8h] BYREF
  int v48; // [sp+44h] [bp-D0h]
  int v49; // [sp+48h] [bp-CCh]
  int16_t v50; // [sp+4Ch] [bp-C8h] BYREF
  uint8_t v51[18]; // [sp+4Eh] [bp-C6h] BYREF
  uint64_t v52[18]; // [sp+60h] [bp-B4h] BYREF
  char v53; // [sp+F0h] [bp-24h] BYREF
  } _frame;
  if ( a3 <= 23 )
  {
    if ( **(volatile int16_t **)off_13CE64 < 0 )
      call_shared_handler(dword_13CE70, dword_13CE6C, 430);
    return 0;
  }
  _frame.v50 = *a2 & 0xC7FF;
  v9 = (volatile char *)a2 + a4;
  memcpy(_frame.v51, (void *)(a2 + 2), 18);
  v10 = a3 - a4;
  _frame.v38 = 20;
  _frame.v39 = v10;
  v11 = &_frame.v50;
  _frame.v37[0] = (int)(uintptr_t)(&_frame.v50);
  _frame.v37[1] = (int)(uintptr_t)(v9);
  if ( a5 )
  {
    _frame.v37[2] = a5;
    v12 = v10 + 38;
    _frame.v40 = 18;
  }
  else
  {
    _frame.v39 = v10 + 18;
    v12 = v10 + 38;
  }
  v13 = *(volatile uint64_t *)(a1 + 80);
  v14 = *(volatile uint32_t *)(a1 + 92);
  v15 = *(volatile uint32_t *)(a1 + 88);
  _frame.v52[0] = v13;
  _frame.v52[1] = __PAIR64__(v14, v15);
  v16 = dword_13CE74;
  v17 = dword_13CE68;
  v18 = (volatile char *)_frame.v52;
  v19 = 1;
  while ( 1 )
  {
    v21 = v13
        ^ (*(volatile uint8_t *)(v17 + BYTE1(v14)) ^ v19
         | (*(volatile uint8_t *)(v17 + (uint8_t)v14) << 24)
         | (*(volatile uint8_t *)(v17 + HIBYTE(v14)) << 16)
         | (*(volatile uint8_t *)(v17 + BYTE2(v14)) << 8));
    v15 ^= HIDWORD(v13) ^ v21;
    v14 ^= v15;
    *((volatile uint32_t *)v18 + 6) = v15;
    *((volatile uint32_t *)v18 + 7) = v14;
    *((volatile uint32_t *)v18 + 4) = v21;
    *((volatile uint32_t *)v18 + 5) = HIDWORD(v13) ^ v21;
    v13 = __PAIR64__(HIDWORD(v13) ^ v21, v21);
    if ( &_frame.v53 == v18 )
      break;
    v20 = *(volatile uint32_t *)(v16 + 4);
    v16 += 4;
    v19 = v20;
    v18 += 16;
  }
  memset((volatile int *)&_frame.v44, 0, 0x10u);
  memset((volatile int *)&_frame.v47, 0, 0x10u);
  if ( v12 > 16 )
  {
    v22 = &_frame.v38;
    v23 = _frame.v37;
    v24 = v12;
    v25 = 20;
    do
    {
      if ( v25 <= 16 )
      {
        v36 = &_frame.v41;
        do
        {
          *(volatile uint8_t *)v36 = *(volatile uint8_t *)v11;
          v36 = (volatile uint64_t *)((volatile char *)v36 + 1);
          if ( --v25 )
          {
            v11 = (volatile int16_t *)((volatile char *)v11 + 1);
          }
          else
          {
            v11 = (volatile int16_t *)v23[1];
            v25 = v22[1];
            ++v23;
            ++v22;
          }
        }
        while ( v36 != &_frame.v44 );
      }
      else
      {
        v26 = v11 + 8;
        v27 = &_frame.v41;
        do
        {
          v28 = *(volatile uint32_t *)v11;
          v11 += 2;
          *(volatile uint32_t *)v27 = v28;
          v27 = (volatile uint64_t *)((volatile char *)v27 + 4);
        }
        while ( v11 != v26 );
        v25 -= 16;
      }
      _frame.v44 ^= _frame.v41;
      _frame.v45 ^= _frame.v42;
      v24 -= 16;
      _frame.v46 ^= _frame.v43;
      bt_get_dev_info((void *)(_frame.v52), (void *)(&_frame.v44));
    }
    while ( v24 > 16 );
    v12 = v12 - 16 - ((v12 - 17) & 0xFFFFFFF0);
    bt_get_dev_info((void *)(_frame.v52), (void *)(&_frame.v47));
    rx_parse_pkt_header((volatile unsigned int *)&_frame.v47);
LABEL_18:
    v29 = 0;
    do
    {
      while ( 1 )
      {
        *((volatile uint8_t *)&_frame.v41 + v29) = *(volatile uint8_t *)v11;
        if ( !--v25 )
          break;
        ++v29;
        v11 = (volatile int16_t *)((volatile char *)v11 + 1);
        if ( v12 <= v29 )
          goto LABEL_22;
      }
      ++v29;
      v11 = (volatile int16_t *)v23[1];
      v25 = v22[1];
      ++v23;
      ++v22;
    }
    while ( v12 > v29 );
LABEL_22:
    v30 = v12 - 1;
    if ( v12 <= 0 )
      v30 = 0;
    v31 = (volatile uint64_t *)((volatile char *)&_frame.v41 + v30 + 1);
    goto LABEL_25;
  }
  bt_get_dev_info((void *)(_frame.v52), (void *)(&_frame.v47));
  rx_parse_pkt_header((volatile unsigned int *)&_frame.v47);
  v31 = &_frame.v41;
  if ( v12 > 0 )
  {
    v22 = &_frame.v38;
    v23 = _frame.v37;
    v25 = 20;
    goto LABEL_18;
  }
LABEL_25:
  if ( v12 != 16 )
  {
    *(volatile uint8_t *)v31 = 0x80;
    v32 = (volatile char *)v31 + 1;
    if ( v12 != 15 )
    {
      v33 = (volatile char *)v31 - v12 + 16;
      do
        *v32++ = 0;
      while ( v32 != v33 );
    }
    rx_parse_pkt_header((volatile unsigned int *)&_frame.v47);
  }
  _frame.v47 ^= _frame.v41;
  _frame.v44 ^= _frame.v47;
  v34 = _frame.v46 ^ _frame.v49 ^ _frame.v43;
  v35 = _frame.v45 ^ _frame.v48 ^ _frame.v42;
  _frame.v48 ^= _frame.v42;
  _frame.v45 = v35;
  _frame.v49 ^= _frame.v43;
  _frame.v46 = v34;
  bt_get_dev_info((void *)(_frame.v52), (void *)(&_frame.v44));
  return _frame.v44;
}



// ll_pdu_type_get @ 0x13ce78
unsigned int ll_pdu_type_get(int a1, unsigned int a2) {
  unsigned int v2; // r2
  int v3; // nf
  unsigned int v5; // r3
  unsigned int v6; // r4
  int v7; // cf
  unsigned int v8; // r3
  unsigned int v9; // r3
  int v10; // cc
  uint16_t v11; // r3

  if ( (a2 & 0x2000) != 0 )
  {
    v2 = a2 & 0xF;
    switch ( (a2 >> 11) & 7 )
    {
      case 4u:
        if ( *(volatile uint8_t *)(a1 + 176) > v2
          && (((int)*(volatile uint16_t *)(a1 + 170) >> (2 * ((a2 >> 4) & 7))) & 3u) + 7 > v2 )
        {
          a2 = a2 & 0xFFF0 | (uint16_t)(v2 + 1);
          if ( *(volatile uint8_t *)(a1 + 181) )
            a2 |= 0x200u;
        }
        return a2;
      case 5u:
        if ( *(volatile uint8_t *)(a1 + 176) > v2
          && 2 * (((int)*(volatile uint16_t *)(a1 + 170) >> (2 * ((a2 >> 4) & 7))) & 3u) + 7 > v2 )
        {
          v3 = ((v2 + 1) & 0x4000 | a2 & 0x4000) != 0;
          a2 = (uint16_t)((v2 + 1) | a2 & 0xFFF0);
          if ( v3 )
          {
            if ( v2 != 1 )
              goto LABEL_29;
            return a2 & 0xBFFF;
          }
        }
        return a2;
      case 7u:
        if ( (a2 & 0x180) != 0 )
        {
          if ( ((a2 >> 7) & 3) == 1 )
            return a2 & 0xFE7F;
        }
        else if ( (a2 & 0xE) == 0 )
        {
          v3 = ((v2 + 1) & 0x4000 | a2 & 0x4000) != 0;
          a2 = (uint16_t)((v2 + 1) | a2 & 0xFFF0);
          if ( v3 && (v2 == 1 || !*(volatile uint8_t *)(a1 + 195)) )
            return a2 & 0xBFFF;
          return a2;
        }
        v11 = a2 & 0xFFF0 | (v2 + 1) & 0xFFF0 | 5;
        a2 = v11;
        if ( (v11 & 0x4000) != 0 )
        {
LABEL_29:
          if ( *(volatile uint8_t *)(a1 + 195) <= v2 )
            return a2 & 0xBFFF;
        }
        break;
      default:
        return a2;
    }
  }
  else if ( ((a2 >> 11) & 6) != 0 )
  {
    v9 = a2 & 7;
    while ( 1 )
    {
      v10 = *(volatile uint8_t *)(a1 + 176) > v9;
      v9 = (uint8_t)(v9 + 1);
      if ( !v10 )
        break;
      if ( ((*(volatile uint8_t *)(((a2 >> 3) & 3) + a1 + 170) >> v9) & 1) != 0 )
      {
        a2 = a2 & 0xFFFFFFF8 | v9;
        if ( *(volatile uint8_t *)(a1 + 181) )
          return (uint16_t)a2 | 0x200;
        return a2;
      }
    }
  }
  else
  {
    v5 = a2 & 0x7F;
    if ( (a2 & 0x7C) != 0 )
    {
      v6 = *(volatile uint8_t *)(a1 + 178);
    }
    else
    {
      v6 = *(volatile uint8_t *)(a1 + 178);
      if ( v6 >= 3 )
        v6 = 3;
    }
    while ( 1 )
    {
      v7 = v5 >= v6;
      v5 = (uint8_t)(v5 + 1);
      if ( v7 )
        break;
      if ( ((*(volatile uint16_t *)(a1 + 174) >> v5) & 1) != 0 )
        return a2 & 0xFFFFFF80 | v5;
    }
    v8 = *(volatile uint8_t *)(a1 + 169);
    if ( v8 > 1 )
      return (uint16_t)((uint16_t)v8 << 11);
  }
  return a2;
}



// scan_process_list @ 0x13cff0
int scan_process_list(int result, volatile uint32_t *a2) {
  unsigned int v2; // r6
  int v3; // r7
  int v4; // r2
  char v5; // r12
  unsigned int v6; // r3
  unsigned int v7; // r4
  int v8; // r5
  unsigned int v9; // r3
  int16_t v10; // lr
  char v11; // lr
  int v12; // lr
  unsigned int v13; // r5
  unsigned int v14; // r3
  unsigned int v15; // r2
  unsigned int v16; // r4
  unsigned int v17; // r2
  int v18; // r4
  int v19; // r12
  unsigned int v20; // r2
  int v21; // r12
  unsigned int v22; // r2
  unsigned int v23; // r9
  int v24; // r8
  int v25; // r2
  int v26; // r4
  uint16_t v27; // r12
  unsigned int v28; // r3
  unsigned int v29; // r12
  unsigned int v30; // r2
  unsigned int v31; // r3
  int v32; // r4
  int v33; // r6
  unsigned int v34; // lr
  unsigned int v35; // r8
  int v36; // r4
  int v37; // r3
  unsigned int v38; // r6

  v2 = *(volatile uint16_t *)(result + 184);
  if ( !*(volatile uint16_t *)(result + 184) )
  {
    v10 = *(volatile uint16_t *)(result + 184);
    v3 = -1;
    goto LABEL_13;
  }
  v3 = v2 - 1;
  v4 = result;
  v5 = 0;
  while ( 1 )
  {
    v6 = *(volatile uint16_t *)(v4 + 10);
    v7 = v6 >> 11;
    if ( (v6 & 0x2000) != 0 )
    {
      v9 = v6 & 0xF;
      v8 = v7 & 6;
    }
    else
    {
      v8 = (v6 >> 11) & 6;
      if ( (v7 & 6) != 0 )
        v9 = v6 & 7;
      else
        v9 = v6 & 0x7F;
    }
    if ( !v8 && v9 <= 3 || !*(volatile uint8_t *)(v4 + 13) )
      goto LABEL_11;
    if ( *(volatile uint16_t *)(v4 + 8) > 0x1998u )
      break;
    v5 = 1;
LABEL_11:
    v4 += 12;
    if ( result + 12 + 12 * (uint16_t)(v2 - 1) == v4 )
    {
      v10 = (v10 & ~0xFFu) | ((uint8_t)(8 * v5) & 0xFFu);
      goto LABEL_13;
    }
  }
  v10 = (v10 & ~0xFFu) | ((uint8_t)(0) & 0xFFu);
LABEL_13:
  v11 = v10 | *(volatile uint8_t *)(result + 166) & 0xF7;
  *(volatile uint8_t *)(result + 166) = v11;
  v12 = v11 & 2;
  if ( !v12 && *a2 > a2[v2 - 1] && *(volatile uint8_t *)(result + 12 * v3 + 13) )
  {
    v13 = 0;
    v14 = 1;
  }
  else
  {
    v13 = (uint16_t)v3;
    v12 = (uint16_t)v3;
    v14 = 2;
  }
  *(volatile uint16_t *)(result + 136) = v13;
  v15 = *(volatile uint16_t *)(result + 12 * v12 + 10);
  v16 = v15 >> 11;
  if ( (v15 & 0x2000) != 0 )
  {
    v17 = v15 & 0xF;
    if ( (v16 & 6) != 0 )
      goto LABEL_19;
LABEL_54:
    if ( v17 > 3 )
      goto LABEL_19;
  }
  else
  {
    if ( (v16 & 6) == 0 )
    {
      v17 = v15 & 0x7F;
      goto LABEL_54;
    }
LABEL_19:
    if ( v3 > 0 )
    {
      v18 = (v18 & ~0xFFFFu) | ((uint16_t)(0) & 0xFFFFu);
      v19 = 0;
      do
      {
        v22 = *(volatile uint16_t *)(result + 12 * v19 + 10);
        v23 = v22 >> 11;
        v24 = (v22 >> 11) & 6;
        if ( (v22 & 0x2000) != 0 )
        {
          v20 = v22 & 0xF;
          v24 = v23 & 6;
        }
        else if ( (v23 & 6) != 0 )
        {
          v20 = v22 & 7;
        }
        else
        {
          v20 = v22 & 0x7F;
        }
        v18 = (uint16_t)(v18 + 1);
        if ( !v24 )
        {
          v21 = 3 * v19;
          if ( v20 <= 3 )
            *(volatile uint8_t *)(result + 4 * v21 + 14) = v24;
        }
        v19 = v18;
      }
      while ( v18 < v3 );
    }
    *(volatile uint8_t *)(result + 12 * v12 + 14) = 1;
  }
  *(volatile uint16_t *)(result + 138) = v13;
  if ( v14 >= v2 )
  {
LABEL_57:
    v30 = v13;
    v29 = v13;
  }
  else
  {
    v25 = result + 12 * (v2 - v14);
    while ( 1 )
    {
      v26 = *(volatile uint8_t *)(v25 + 14);
      v27 = v14 + 1;
      v25 -= 12;
      if ( v26 )
        break;
      v14 = (v14 & ~0xFFFFu) | ((uint16_t)(v14 + 1) & 0xFFFFu);
      if ( v27 == v2 )
        goto LABEL_57;
    }
    v29 = (v29 & ~0xFFFFu) | ((uint16_t)(v2 - v14) & 0xFFFFu);
    v28 = (uint16_t)(v14 + 1);
    v29 = (uint16_t)v29;
    *(volatile uint16_t *)(result + 138) = v29;
    if ( v2 <= v28 )
    {
LABEL_56:
      v30 = (uint16_t)v29;
    }
    else
    {
      v30 = v2 - v28;
      v31 = (v3 - v28) >> 16 << 16;
      v32 = result + 12 * v30;
      while ( 1 )
      {
        v33 = *(volatile uint8_t *)(v32 + 14);
        v32 -= 12;
        if ( v33 )
          break;
        if ( v31 == --v30 )
          goto LABEL_56;
      }
    }
  }
  v34 = a2[v30];
  v35 = *(volatile uint16_t *)(result + 12 * v30 + 8);
  if ( v29 )
  {
    v36 = result;
    v37 = 0;
    while ( 1 )
    {
      if ( !*(volatile uint8_t *)(v36 + 14) || (uint16_t)v37 == v13 )
        goto LABEL_47;
      v38 = *(volatile uint16_t *)(v36 + 8);
      if ( v38 > 0xF332 )
      {
        if ( a2[v37] >= v34 )
        {
          v35 = *(volatile uint16_t *)(v36 + 8);
          v34 = a2[v37];
          v30 = (v30 & ~0xFFFFu) | ((uint16_t)(v37) & 0xFFFFu);
        }
        goto LABEL_47;
      }
      if ( v38 < v35 )
      {
LABEL_47:
        ++v37;
        v36 += 12;
        if ( v29 <= (uint16_t)v37 )
          break;
      }
      else
      {
        v34 = a2[v37];
        v30 = (v30 & ~0xFFFFu) | ((uint16_t)(v37++) & 0xFFFFu);
        v35 = *(volatile uint16_t *)(v36 + 8);
        v36 += 12;
        if ( v29 <= (uint16_t)v37 )
          break;
      }
    }
  }
  *(volatile uint16_t *)(result + 140) = v30;
  *(volatile uint16_t *)(result + 142) = 0;
  return result;
}



// ll_pdu_dispatch @ 0x13d25c
int ll_pdu_dispatch(int a1, unsigned int a2) {
  int result; // r0
  int v3; // r2
  int v4; // r3
  int v5; // r1

  switch ( (a2 >> 11) & 7 )
  {
    case 0u:
    case 1u:
      return (*(volatile uint16_t *)(a1 + 174) >> (a2 & 0x7F)) & 1;
    case 2u:
    case 3u:
      return (*(volatile uint8_t *)(a1 + ((a2 >> 3) & 3) + 170) >> (a2 & 7)) & 1;
    case 4u:
      v3 = (a2 >> 4) & 7;
      v4 = a2 & 0xF;
      result = v4 <= (((int)*(volatile uint16_t *)(a1 + 170) >> (2 * v3)) & 3) + 7;
      v5 = (a2 >> 7) & 3;
      if ( v4 == 6 )
      {
        if ( v5 == 2 )
        {
          if ( v3 == 3 )
            return 0;
          if ( v3 == 6 )
            return 0;
        }
      }
      else if ( v4 == 9 )
      {
        if ( v5 )
        {
          if ( v5 == 2 )
          {
            if ( v3 == 5 )
              return 0;
          }
          else if ( v5 == 3 && v3 == 2 )
          {
            return 0;
          }
        }
        else if ( v3 != 2 && v3 != 5 )
        {
          return 0;
        }
      }
      return result;
    case 5u:
      return (uint8_t)(a2 & 0xF) <= 2 * (((int)*(volatile uint16_t *)(a1 + 170) >> (2 * ((a2 >> 4) & 7))) & 3)
                                          + 7;
    case 7u:
      result = (a2 >> 7) & 3;
      if ( (a2 & 0xF) <= 2 )
      {
        if ( (a2 & 0xF) == 0 )
          return ((a2 >> 7) & 2 | (a2 >> 4) & 7) == 0;
      }
      else if ( !result )
      {
        return result;
      }
      if ( result != 1 )
        return ((a2 >> 7) & 2 | (a2 >> 4) & 7) == 0;
      return 0;
    default:
      return 1;
  }
}



// bt_state_handler @ 0x13d34c
unsigned int bt_state_handler(unsigned int result) {
  unsigned int v1; // r4
  int v2; // r1
  int16_t v3; // r3
  unsigned int v4; // r1
  int i; // r3
  int v6; // r2
  int v7; // r2
  int16_t v8; // r1
  int16_t v9; // r1
  unsigned int v10; // r2
  int v11; // r0
  int16_t v12; // r3

  switch ( *(volatile uint8_t *)(result + 169) )
  {
    case 0:
    case 1:
      v4 = *(volatile uint16_t *)(result + 174);
result = (result & ~0xFFFFu) | ((uint16_t)((((v4 >> 3) & 1) << (1 - *(volatile uint8_t *)(result + 182))) + ((((v4 >> 1) & 1) + ((v4 >> 2) & 1)) << (1 - *(volatile uint8_t *)(result + 182))) + (v4 & 1)) & 0xFFFFu);
      for ( i = 4; i != 12; ++i )
      {
        v6 = ((int)v4 >> i) & 1;
        result = (uint16_t)(result + v6);
      }
      goto LABEL_5;
    case 2:
    case 3:
      v1 = *(volatile uint8_t *)(result + 170);
      v2 = 8;
      v3 = 0;
      do
      {
        --v2;
        v3 += (v1 & 1)
            * (((*(volatile uint8_t *)(result + 179) + 1) << *(volatile uint8_t *)(result + 181))
             + *(volatile uint8_t *)(result + 180)
             * (uint16_t)((*(volatile uint8_t *)(result + 179) + 1) << *(volatile uint8_t *)(result + 181)));
        v1 >>= 1;
      }
      while ( v2 );
      result = (uint16_t)(((((*(volatile uint16_t *)(result + 174) >> 2) & 1)
                                  + ((*(volatile uint16_t *)(result + 174) >> 1) & 1)) << (1 - *(volatile uint8_t *)(result + 182)))
                                + (*(volatile uint16_t *)(result + 174) & 1)
                                + (((*(volatile uint16_t *)(result + 174) >> 3) & 1) << (1 - *(volatile uint8_t *)(result + 182)))
                                + v3);
      goto LABEL_5;
    case 4:
      v9 = *(volatile uint8_t *)(result + 180);
      v10 = (*(volatile uint16_t *)(result + 170) & 3) - 1;
      v11 = (*(volatile uint8_t *)(result + 179) + 1) << *(volatile uint8_t *)(result + 181);
      if ( v10 <= 1 )
        v12 = 9;
      else
        v12 = 8;
      result = (uint16_t)((v11 + v9 * v11) * v12);
      goto LABEL_5;
    case 5:
      v7 = *(volatile uint16_t *)(result + 170) & 3;
      if ( v7 == 1 )
      {
        v8 = 10;
      }
      else if ( v7 == 2 )
      {
        v8 = 12;
      }
      else
      {
        v8 = 8;
      }
      result = (uint16_t)(3
                                * (*(volatile uint8_t *)(result + 180)
                                 + 1
                                 + *(volatile uint8_t *)(result + 179) * (*(volatile uint8_t *)(result + 180) + 1))
                                * v8
                                + (*(volatile uint16_t *)(result + 174) & 1));
LABEL_5:
      if ( result >= 0xA )
        result = 10;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}



// bt_clr_flag @ 0x13d47c
int bt_clr_flag(int a1) {
  char v1; // r5
  unsigned int v2; // r3
  int result; // r0
  int v5; // r3
  unsigned int v6; // r2
  unsigned int v7; // r3
  int v8; // r2

  v1 = *(volatile uint8_t *)(a1 + 166);
  v2 = *(volatile uint8_t *)(a1 + 177);
  *(volatile uint8_t *)(a1 + 166) = v1 & 0xFB;
  if ( v2 > 0xB )
    goto LABEL_11;
  result = ((int)*(volatile uint16_t *)(a1 + 12 * *(volatile uint16_t *)(a1 + 136) + 10) >> 11) & 6;
  if ( !result )
    return result;
  result = ((int)*(volatile uint16_t *)(a1 + 12 * *(volatile uint16_t *)(a1 + 138) + 10) >> 11) & 6;
  if ( !result )
    return result;
  result = ((int)*(volatile uint16_t *)(a1 + 12 * *(volatile uint16_t *)(a1 + 140) + 10) >> 11) & 6;
  if ( !result )
    return result;
  result = v1 & 0x20;
  if ( (v1 & 0x20) != 0 )
  {
LABEL_11:
    *(volatile uint8_t *)(a1 + 166) = v1 & 0xFB | 4;
    return 1;
  }
  v5 = a1 + 12 * *(volatile uint16_t *)(a1 + 2 * (*(volatile uint8_t *)(a1 + 168) + 68));
  v6 = *(volatile uint16_t *)(v5 + 10);
  if ( (v6 & 0x2000) != 0 )
  {
    if ( (v6 & 0xF) > 2 )
      goto LABEL_9;
    v8 = (v6 >> 4) & 7;
  }
  else
  {
    if ( ((v6 >> 11) & 6) == 0 )
    {
      if ( (v6 & 0x7F) > 2 )
      {
LABEL_9:
        v7 = *(volatile uint16_t *)(v5 + 8);
        goto LABEL_10;
      }
      goto LABEL_16;
    }
    if ( (v6 & 7) > 2 )
      goto LABEL_9;
    v8 = (v6 >> 3) & 3;
  }
  if ( v8 )
    goto LABEL_9;
LABEL_16:
  v7 = *(volatile uint16_t *)(v5 + 8);
  if ( v7 > 0x1998 )
  {
LABEL_10:
    if ( v7 <= 0x28E )
      return result;
    goto LABEL_11;
  }
  return result;
}



// bt_cmd_handler_1 @ 0x13d54c
int bt_cmd_handler_1(int a1, unsigned int a2) {
  int v4; // r5
  int16_t v5; // r0
  int v6; // r2
  char v7; // r7
  unsigned int v8; // r5
  unsigned int v9; // r2
  int v10; // cc
  int result; // r0
  int v12; // r3
  uint8_t v13; // r5
  unsigned int v14; // r3
  int v15; // r1

  v4 = (a2 >> 11) & 7;
  if ( (a2 & 0x2000) != 0 )
  {
    v5 = scale_timer_value(a1);
    v6 = a2 & 0xF;
    switch ( v4 )
    {
      case 4:
        if ( (a2 & 0xF) == 0 )
          goto LABEL_13;
        result = (uint16_t)((v6 - 1) | a2 & 0xFFF0);
        if ( *(volatile uint8_t *)(a1 + 181) )
          return result | 0x200;
        return result;
      case 5:
        if ( (a2 & 0xF) == 0 )
          goto LABEL_13;
        v15 = v6 - 1;
        result = a2 & 0xFFF0 | (uint16_t)(v6 - 1);
        if ( (a2 & 0x4000) == 0 )
          return result;
        if ( v6 == 3 )
          return result & 0xBFFF;
        goto LABEL_21;
      case 7:
        if ( (a2 & 0xF) != 0 )
        {
          v15 = v6 - 1;
          result = a2 & 0xFFF0 | (uint16_t)(v6 - 1);
          if ( (a2 & 0x4000) != 0 )
          {
LABEL_21:
            if ( v15 > *(volatile uint8_t *)(a1 + 195) )
              return result & 0xBFFF;
          }
          return result;
        }
        if ( *(volatile uint8_t *)(a1 + 183) && (a2 & 0x180) == 0 )
          return dword_13D690 & a2 | 1;
        break;
      default:
        return a2;
    }
    return a2;
  }
  if ( ((a2 >> 11) & 6) == 0 )
  {
    v7 = a2;
    v8 = a2 & 0x7F;
    scale_timer_value(a1);
    if ( (v7 & 0x7C) != 0 )
    {
      v9 = *(volatile uint8_t *)(a1 + 177);
      if ( v9 < 4 )
        v9 = 4;
    }
    else
    {
      v9 = *(volatile uint8_t *)(a1 + 177);
    }
    while ( 1 )
    {
      v10 = v8 > v9;
      v8 = (uint8_t)(v8 - 1);
      if ( !v10 )
        break;
      if ( ((*(volatile uint16_t *)(a1 + 174) >> v8) & 1) != 0 )
      {
        result = a2 & 0xFFFFFF80 | v8;
        if ( !v8 )
          return (uint16_t)result | 0x400;
        return result;
      }
    }
    return a2;
  }
  v5 = scale_timer_value(a1);
  v12 = a2 & 7;
  while ( 1 )
  {
    v13 = v12 - 1;
    if ( !v12 )
      break;
    v12 = v13;
    if ( ((*(volatile uint8_t *)(((a2 >> 3) & 3) + a1 + 170) >> v13) & 1) != 0 )
    {
      result = a2 & 0xFFFFFFF8 | v13;
      if ( *(volatile uint8_t *)(a1 + 181) )
        return (uint16_t)result | 0x200;
      return result;
    }
  }
LABEL_13:
  v14 = *(volatile uint8_t *)(a1 + 178);
  if ( v14 > 3 )
    return a2;
  if ( *(volatile uint8_t *)(a1 + 178) )
    return (uint16_t)(v14 | (*(volatile uint8_t *)(a1 + 182) << 10)) | v5 & 0x400;
  else
    return 1024;
}



// rf_cal_channel_get @ 0x13d694
int rf_cal_channel_get(int a1) {
  int v2; // r0
  int v3; // r1
  int v4; // r2
  unsigned int v5; // r3
  int result; // r0
  int v7; // r5
  unsigned int v8; // r1
  int v9; // r1
  int v10; // r2
  int v11; // r1
  int v12; // r7
  int v13; // r12
  int v14; // r4
  unsigned int v15; // r1
  int v16; // r7
  signed int v17; // r12
  int v18; // r2
  int v19; // r5
  int16_t v20; // r1
  int16_t v21; // r5
  unsigned int v22; // r6
  int v23; // r6
  unsigned int v24; // r5
  unsigned int v25; // r7
  int v26; // r6
  int16_t v27; // lr
  int v28; // r2
  signed int v29; // r12
  unsigned int v30; // r9
  int16_t v31; // r12
  uint16_t v32; // r8
  int16_t v33; // r6
  int v34; // r6
  int v35; // r12
  unsigned int v36; // r1
  unsigned int v37; // r7
  unsigned int v38; // r4

  v2 = scale_timer_value(a1);
  v3 = *(volatile uint8_t *)(a1 + 169);
  v4 = *(volatile uint8_t *)(a1 + 179);
  v5 = v2;
  result = (uint16_t)((uint16_t)v3 << 11);
  if ( *(volatile uint8_t *)(a1 + 179) )
    v7 = (uint8_t)(v4 - 1);
  else
    v7 = *(volatile uint8_t *)(a1 + 179);
  switch ( *(volatile uint8_t *)(a1 + 169) )
  {
    case 0:
    case 1:
      v10 = (uint8_t)(*(volatile uint8_t *)(a1 + 177)
                            + (uint8_t)(v5 & 0x7F)
                            % (*(volatile uint8_t *)(a1 + 178) - *(volatile uint8_t *)(a1 + 177) + 1));
      if ( ((*(volatile uint16_t *)(a1 + 174) >> v10) & 1) == 0 )
        v10 = *(volatile uint8_t *)(a1 + 178);
      result |= v10;
      if ( !v10 )
        return (uint16_t)result | 0x400;
      if ( (uint8_t)(v10 - 1) <= 2u )
        return (uint16_t)result | v5 & 0x400 | (uint16_t)(*(volatile uint8_t *)(a1 + 182) << 10);
      return result;
    case 2:
    case 3:
      v8 = *(volatile uint8_t *)(a1 + 177);
      if ( v8 <= 3 && (v5 & 0x800) != 0 )
        goto LABEL_6;
      v34 = *(volatile uint8_t *)(a1 + 176);
      v35 = *(volatile uint8_t *)(a1 + 181);
      v36 = ((v5 >> 3) & 3) % ((unsigned int)*(volatile uint8_t *)(a1 + 180) + 1);
      v37 = *(volatile uint8_t *)(a1 + v36 + 170);
      v38 = (v5 & 7) % (v34 + 1);
      if ( ((v37 >> v38) & 1) != 0 )
        v34 = (uint8_t)v38;
      return (uint16_t)(result
                              | (8 * v36)
                              | ((((v5 >> 9) & 1) % (v35 + 1)) << 9)
                              | (((uint16_t)v7 + (uint16_t)((int)((v5 >> 7) & 3) % (v4 - v7 + 1))) << 7))
           | v34;
    case 4:
      v8 = *(volatile uint8_t *)(a1 + 177);
      if ( v8 > 3 || (v5 & 0x800) == 0 )
      {
        v11 = *(volatile uint8_t *)(a1 + 180);
        v12 = *(volatile uint16_t *)(a1 + 170);
        v13 = *(volatile uint8_t *)(a1 + 176);
        v14 = *(volatile uint8_t *)(a1 + 181);
        v15 = ((v5 >> 4) & 7) % (v11 + 1);
        v16 = ((v12 >> (2 * v15)) & 3) + 7;
        v17 = (v5 & 0xF) % (v13 + 1);
        v18 = v4 - v7;
        if ( v17 <= v16 )
        {
          v19 = (uint8_t)(v7 + (int)((v5 >> 7) & 3) % (v18 + 1));
          v16 = (uint8_t)v17;
          if ( v17 == 6 )
          {
            if ( v19 == 2 )
            {
              if ( v15 == 3 || v15 == 6 )
              {
                v20 = 16 * (uint8_t)(v15 - 1);
                v17 = (v17 & ~0xFFFFu) | ((uint16_t)(6) & 0xFFFFu);
                v21 = 256;
              }
              else
              {
                v20 = 16 * v15;
                v21 = 256;
              }
            }
            else
            {
              v20 = 16 * v15;
              v21 = (uint16_t)v19 << 7;
            }
            return (uint16_t)v17 | (uint16_t)(result | ((((v5 >> 9) & 1) % (v14 + 1)) << 9) | v21 | v20);
          }
        }
        else
        {
          v16 = (uint8_t)v16;
          v19 = (uint8_t)(v7 + (int)((v5 >> 7) & 3) % (v18 + 1));
        }
        if ( v16 == 9 )
        {
          if ( v19 )
          {
            if ( v19 == 2 )
            {
              if ( v15 == 5 )
              {
                v17 = (v17 & ~0xFFFFu) | ((uint16_t)(9) & 0xFFFFu);
                v20 = 64;
              }
              else
              {
                v20 = 16 * v15;
                v17 = (v17 & ~0xFFFFu) | ((uint16_t)(9) & 0xFFFFu);
              }
              v21 = 256;
            }
            else if ( v19 == 3 )
            {
              if ( v15 == 2 )
              {
                v17 = (v17 & ~0xFFFFu) | ((uint16_t)(9) & 0xFFFFu);
                v20 = 16;
              }
              else
              {
                v20 = 16 * v15;
                v17 = (v17 & ~0xFFFFu) | ((uint16_t)(9) & 0xFFFFu);
              }
              v21 = 384;
            }
            else
            {
              v20 = 16 * v15;
              v21 = (uint16_t)v19 << 7;
              v17 = (v17 & ~0xFFFFu) | ((uint16_t)(9) & 0xFFFFu);
            }
          }
          else
          {
            if ( v15 == 2 )
            {
              v17 = (v17 & ~0xFFFFu) | ((uint16_t)(9) & 0xFFFFu);
            }
            else if ( (uint8_t)v15 == 5 )
            {
              v17 = (v17 & ~0xFFFFu) | ((uint16_t)(9) & 0xFFFFu);
            }
            else
            {
              v17 = (v17 & ~0xFFFFu) | ((uint16_t)(8) & 0xFFFFu);
            }
            v20 = 16 * v15;
            v21 = 0;
          }
        }
        else
        {
          v20 = 16 * v15;
          v21 = (uint16_t)v19 << 7;
          v17 = (v17 & ~0xFFFFu) | ((uint16_t)(v16) & 0xFFFFu);
        }
        return (uint16_t)v17 | (uint16_t)(result | ((((v5 >> 9) & 1) % (v14 + 1)) << 9) | v21 | v20);
      }
LABEL_6:
      v9 = (uint8_t)(v8 + (uint8_t)(v5 & 0x7F) % (int)(*(volatile uint8_t *)(a1 + 178) - v8 + 1));
      if ( ((*(volatile uint16_t *)(a1 + 174) >> v9) & 1) == 0 )
        v9 = *(volatile uint8_t *)(a1 + 178);
      if ( !v9 )
        return 1024;
      return v5 & 0x400 | (uint16_t)(*(volatile uint8_t *)(a1 + 182) << 10) | (uint16_t)v9;
    case 5:
      v22 = *(volatile uint8_t *)(a1 + 177);
      if ( v22 > 3 || (v5 & 0x800) == 0 )
      {
        v24 = (uint8_t)(v7 + (int)((v5 >> 7) & 3) % (v4 - v7 + 1));
        v25 = ((v5 >> 4) & 7) % ((unsigned int)*(volatile uint8_t *)(a1 + 180) + 1);
        v26 = (v5 >> 9) & 3;
        if ( (v5 & 0xF) == 0xF )
        {
          if ( (uint8_t)v24 )
          {
            v27 = (uint8_t)v24 << 7;
          }
          else
          {
            if ( !v25 )
            {
              v24 = *(volatile uint8_t *)(a1 + 183);
              if ( *(volatile uint8_t *)(a1 + 183) )
              {
                v27 = 128;
                v31 = 14336;
                v3 = 7;
                v24 = 1;
              }
              else
              {
                v27 = *(volatile uint8_t *)(a1 + 183);
                v31 = 10240;
              }
              v30 = 0;
              v28 = (v28 & ~0xFFFFu) | ((uint16_t)(0) & 0xFFFFu);
              goto LABEL_40;
            }
            v27 = 0;
          }
        }
        else
        {
          v27 = (uint16_t)v24 << 7;
        }
        v28 = 2 * (((int)*(volatile uint16_t *)(a1 + 170) >> (2 * v25)) & 3) + 7;
        v29 = (v5 & 0xF) % ((unsigned int)*(volatile uint8_t *)(a1 + 176) + 1);
        if ( v29 > v28 )
        {
          v30 = (uint8_t)v28;
        }
        else
        {
          v30 = (uint8_t)v29;
          v28 = (v28 & ~0xFFFFu) | ((uint16_t)((v5 & 0xF) % ((unsigned int)*(volatile uint8_t *)(a1 + 176) + 1)) & 0xFFFFu);
        }
        v31 = 10240;
LABEL_40:
        v32 = *(volatile uint8_t *)(a1 + 194);
        if ( v26 == 3 )
          v33 = 1024;
        else
          v33 = (uint16_t)v26 << 9;
        if ( *(volatile uint8_t *)(a1 + 194) )
        {
          if ( v3 == 7 && v24 == 1
            || v30 != 2
            && *(volatile uint8_t *)(a1 + 195) >= v30
            && *(volatile uint8_t *)(a1 + 196) >= (unsigned int)(uint8_t)v25
            && *(volatile uint8_t *)(a1 + 197) >= v24 )
          {
            v32 = v5 & 0x4000;
          }
          else
          {
            v32 = 0;
          }
        }
        return v32 | (uint16_t)(v33 | v27 | v31 | v28 | result & 0xC7FF | (16 * v25));
      }
      v23 = (uint8_t)(v22 + (uint8_t)(v5 & 0x7F) % (int)(*(volatile uint8_t *)(a1 + 178) - v22 + 1));
      if ( ((*(volatile uint16_t *)(a1 + 174) >> v23) & 1) == 0 )
        v23 = *(volatile uint8_t *)(a1 + 178);
      if ( v23 )
        return v5 & 0x400 | (uint16_t)(*(volatile uint8_t *)(a1 + 182) << 10) | (uint16_t)v23;
      else
        return 1024;
    default:
      return result;
  }
}



// sub_13DA90 @ 0x13da90
int sub_13DA90(int a1, int a2) {
  unsigned int v2; // r4
  unsigned int v3; // r2
  int v5; // r8
  int result; // r0
  int v7; // r3
  unsigned int v8; // r10
  unsigned int v9; // r11
  unsigned int v10; // r9
  unsigned int v11; // r6
  unsigned int v12; // r4
  volatile uint16_t **v13; // r7
  int v14; // r1
  int v15; // r4
  volatile char *v16; // r0
  int v17; // r2
  int v18; // r3
  char v19; // [sp+0h] [bp-Ch]
  int v20; // [sp+4h] [bp-8h]
  int v21; // [sp+4h] [bp-8h]
  int v22; // [sp+4h] [bp-8h]
  int v23; // [sp+4h] [bp-8h]
  int v24; // [sp+4h] [bp-8h]
  int v25; // [sp+4h] [bp-8h]
  int v26; // [sp+4h] [bp-8h]

  v2 = *(volatile uint16_t *)(a1 + 12 * a2 + 10);
  v3 = v2 >> 11;
  v5 = (v2 >> 11) & 7;
  result = (v2 >> 11) & 4;
  v7 = (v2 >> 10) & 1;
  v8 = v2 >> 9;
  v9 = (v2 >> 9) & 1;
  v19 = v2 >> 7;
  v10 = (v2 >> 7) & 3;
  if ( result )
  {
    v11 = (v2 >> 4) & 7;
    v12 = v2 & 0xF;
LABEL_3:
    v13 = (volatile uint16_t **)off_13DDE4;
    v14 = **(volatile uint16_t **)off_13DDE4;
    switch ( *(volatile uint8_t *)(a1 + 169) )
    {
      case 0:
      case 1:
        goto LABEL_18;
      case 2:
      case 3:
        goto LABEL_15;
      case 4:
        goto LABEL_7;
      case 5:
        goto LABEL_32;
      default:
        goto LABEL_12;
    }
  }
  v11 = (v2 >> 11) & 6;
  if ( (v3 & 6) == 0 )
  {
    v12 = v2 & 0x7F;
    goto LABEL_3;
  }
  v13 = (volatile uint16_t **)off_13DDE4;
  v11 = (v2 >> 3) & 3;
  v14 = **(volatile uint16_t **)off_13DDE4;
  v12 = v2 & 7;
  switch ( *(volatile uint8_t *)(a1 + 169) )
  {
    case 0:
    case 1:
LABEL_18:
      if ( v14 >= 0 )
        goto LABEL_17;
      if ( (v3 & 6) == 0 )
        goto LABEL_20;
      v25 = v7;
      result = mmio_clear_register((int)aFormatModForma_5, (int)aRcCheckRateCon, 614);
      v7 = v25;
      goto LABEL_12;
    case 2:
    case 3:
LABEL_15:
      if ( *(volatile uint8_t *)(a1 + 177) > 3u )
      {
        if ( v14 >= 0 )
          goto LABEL_17;
        if ( (unsigned int)(v5 - 2) > 1 )
        {
          v21 = v7;
          result = mmio_clear_register((int)aFormatModForma_1, (int)aRcCheckRateCon, 626);
          v7 = v21;
          goto LABEL_12;
        }
LABEL_72:
        if ( !v7 || (result = mmio_clear_register((int)aPreType0, (int)aRcCheckRateCon, 692), **v13 < 0) )
        {
          if ( *(volatile uint8_t *)(a1 + 181) >= v9
            || (result = mmio_clear_register((int)aSgiRcSsShortGi, (int)aRcCheckRateCon, 693), **v13 < 0) )
          {
            if ( *(volatile uint8_t *)(a1 + 179) >= v10
              || (result = mmio_clear_register((int)aBwRcSsBwMax, (int)aRcCheckRateCon, 694), **v13 < 0) )
            {
              if ( *(volatile uint8_t *)(a1 + 180) >= v11
                || (result = mmio_clear_register((int)aNssRcSsNoSs, (int)aRcCheckRateCon, 695), **v13 < 0) )
              {
                if ( *(volatile uint8_t *)(a1 + 176) >= v12
                  || (result = mmio_clear_register((int)aMcsRcSsMcsMax, (int)aRcCheckRateCon, 696), **v13 < 0) )
                {
                  if ( ((*(volatile uint8_t *)(a1 + v11 + 170) >> v12) & 1) == 0 )
                  {
                    v16 = (void *)(aRcSsRateMapHtN);
                    v17 = 697;
                    return mmio_clear_register((int)v16, (int)aRcCheckRateCon, v17);
                  }
                }
              }
            }
          }
        }
      }
      else
      {
        if ( v14 >= 0 )
          goto LABEL_17;
        if ( result )
        {
          v24 = v7;
          result = mmio_clear_register((int)aFormatModForma_4, (int)aRcCheckRateCon, 622);
          v7 = v24;
          goto LABEL_12;
        }
LABEL_20:
        switch ( v5 )
        {
          case 0:
          case 1:
            goto LABEL_22;
          case 2:
          case 3:
            goto LABEL_72;
          case 4:
            goto LABEL_58;
          case 5:
            goto LABEL_42;
          case 7:
            goto LABEL_49;
          default:
            return result;
        }
      }
      return result;
    case 4:
LABEL_7:
      if ( *(volatile uint8_t *)(a1 + 177) > 3u )
      {
        if ( v14 >= 0 )
          goto LABEL_17;
        if ( v5 != 4 )
        {
          v23 = v7;
          result = mmio_clear_register((int)aFormatModForma_3, (int)aRcCheckRateCon, 640);
          v7 = v23;
          goto LABEL_12;
        }
      }
      else
      {
        if ( v14 >= 0 )
          goto LABEL_17;
        if ( v5 != 4 )
        {
          if ( !v5 )
            goto LABEL_37;
          v20 = v7;
          result = mmio_clear_register((int)aFormatModForma_0, (int)aRcCheckRateCon, 636);
          v7 = v20;
          goto LABEL_12;
        }
      }
LABEL_58:
      if ( v7 )
      {
        result = mmio_clear_register((int)aPreType0, (int)aRcCheckRateCon, 704);
        if ( **v13 >= 0 )
          return result;
      }
      if ( *(volatile uint8_t *)(a1 + 181) < v9 )
      {
        result = mmio_clear_register((int)aSgiRcSsShortGi, (int)aRcCheckRateCon, 705);
        if ( **v13 >= 0 )
          return result;
      }
      if ( *(volatile uint8_t *)(a1 + 179) < v10 )
      {
        result = mmio_clear_register((int)aBwRcSsBwMax, (int)aRcCheckRateCon, 706);
        if ( **v13 >= 0 )
          return result;
      }
      if ( *(volatile uint8_t *)(a1 + 180) < v11 )
      {
        result = mmio_clear_register((int)aNssRcSsNoSs, (int)aRcCheckRateCon, 707);
        if ( **v13 >= 0 )
          return result;
      }
      if ( *(volatile uint8_t *)(a1 + 176) < v12 )
      {
        result = mmio_clear_register((int)aMcsRcSsMcsMax, (int)aRcCheckRateCon, 708);
        if ( **v13 >= 0 )
          return result;
      }
      if ( (int)v12 > (((int)*(volatile uint16_t *)(a1 + 170) >> (2 * v11)) & 3) + 7 )
      {
        result = mmio_clear_register((int)aMcs7RcSsRateMa, (int)aRcCheckRateCon, 709);
        if ( **v13 >= 0 )
          return result;
      }
      if ( v12 == 6 )
      {
        if ( v10 == 2 && (v11 == 3 || v11 == 6) )
        {
          v16 = (void *)(aMcs6BwBw80mhzN);
          v17 = 710;
          return mmio_clear_register((int)v16, (int)aRcCheckRateCon, v17);
        }
        return result;
      }
      if ( v12 != 9 )
        return result;
      if ( !v10 )
      {
        if ( v11 != 2 && v11 != 5 )
        {
          v16 = (void *)(aMcs9BwBw20mhzN);
          v17 = 711;
          return mmio_clear_register((int)v16, (int)aRcCheckRateCon, v17);
        }
        return result;
      }
      if ( v10 == 2 )
      {
        if ( v11 != 5 )
          return result;
        v16 = (void *)(aMcs9BwBw80mhzN);
        v17 = 712;
        return mmio_clear_register((int)v16, (int)aRcCheckRateCon, v17);
      }
      if ( v10 == 3 && v11 == 2 )
      {
        v16 = (void *)(aMcs9BwBw160mhz);
        v17 = 713;
        return mmio_clear_register((int)v16, (int)aRcCheckRateCon, v17);
      }
      return result;
    case 5:
LABEL_32:
      if ( *(volatile uint8_t *)(a1 + 177) <= 3u )
      {
        if ( v14 < 0 )
        {
          if ( v5 != 5 )
          {
            if ( v5 != 7 )
            {
              if ( !v5 )
              {
LABEL_37:
                if ( v12 > 3 )
                  goto LABEL_25;
                if ( *(volatile uint8_t *)(a1 + 182) == 1 )
                {
LABEL_39:
                  if ( v7 )
                    goto LABEL_25;
                  result = mmio_clear_register((int)aPreType1, (int)aRcCheckRateCon, 674);
                  v14 = **v13;
                }
LABEL_24:
                if ( v14 >= 0 )
                  return result;
LABEL_25:
                if ( v9 )
                {
                  result = mmio_clear_register((int)aSgi0, (int)aRcCheckRateCon, 680);
                  if ( **v13 >= 0 )
                    return result;
                  if ( !v10 )
                  {
LABEL_27:
                    if ( !v11 )
                    {
LABEL_28:
                      if ( *(volatile uint8_t *)(a1 + 177) <= v12
                        || (result = mmio_clear_register((int)aMcsRcSsRIdxMin, (int)aRcCheckRateCon, 683), **v13 < 0) )
                      {
                        if ( *(volatile uint8_t *)(a1 + 178) >= v12
                          || (result = mmio_clear_register((int)aMcsRcSsRIdxMax, (int)aRcCheckRateCon, 684), **v13 < 0) )
                        {
                          v15 = *(volatile uint16_t *)(a1 + 174) >> v12;
                          result = v15 << 31;
                          if ( (v15 & 1) == 0 )
                          {
                            v16 = (void *)(aRcSsRateMapLCo);
                            v17 = 685;
                            return mmio_clear_register((int)v16, (int)aRcCheckRateCon, v17);
                          }
                        }
                      }
                      return result;
                    }
LABEL_132:
                    result = mmio_clear_register((int)aNss0_0, (int)aRcCheckRateCon, 682);
                    if ( **v13 >= 0 )
                      return result;
                    goto LABEL_28;
                  }
                }
                else if ( !v10 )
                {
                  goto LABEL_27;
                }
                result = mmio_clear_register((int)aBwBw20mhz, (int)aRcCheckRateCon, 681);
                if ( **v13 >= 0 )
                  return result;
                if ( !v11 )
                  goto LABEL_28;
                goto LABEL_132;
              }
              v26 = v7;
              result = mmio_clear_register((int)aFormatModForma_6, (int)aRcCheckRateCon, 651);
              v7 = v26;
LABEL_12:
              switch ( v5 )
              {
                case 0:
                case 1:
                  goto LABEL_21;
                case 2:
                case 3:
                  goto LABEL_71;
                case 4:
                  goto LABEL_13;
                case 5:
                  goto LABEL_41;
                case 7:
                  goto LABEL_48;
                default:
                  return result;
              }
              return result;
            }
            goto LABEL_50;
          }
          goto LABEL_42;
        }
LABEL_17:
        switch ( v5 )
        {
          case 0:
          case 1:
LABEL_21:
            v14 = **v13;
LABEL_22:
            if ( v12 > 3 || *(volatile uint8_t *)(a1 + 182) != 1 )
              goto LABEL_24;
            if ( v14 < 0 )
              goto LABEL_39;
            break;
          case 4:
LABEL_13:
            if ( **v13 < 0 )
              goto LABEL_58;
            break;
          case 5:
LABEL_41:
            if ( **v13 < 0 )
              goto LABEL_42;
            break;
          case 7:
LABEL_48:
            v14 = **v13;
LABEL_49:
            if ( v14 < 0 )
              goto LABEL_50;
            break;
          default:
            return result;
        }
        return result;
      }
      if ( v14 >= 0 )
        goto LABEL_17;
      v22 = v7;
      if ( v5 != 5 )
      {
        if ( v5 != 7 )
        {
          result = mmio_clear_register((int)aFormatModForma_2, (int)aRcCheckRateCon, 657);
          v7 = v22;
          goto LABEL_12;
        }
LABEL_50:
        if ( (v8 & 3) == 3 )
        {
          result = mmio_clear_register((int)aGi2, (int)aRcCheckRateCon, 732);
          if ( **v13 >= 0 )
            return result;
        }
        if ( (v19 & 2) != 0 )
        {
          result = mmio_clear_register((int)aBwBw40mhz, (int)aRcCheckRateCon, 733);
          if ( **v13 >= 0 )
            return result;
          if ( !v11 )
            goto LABEL_53;
        }
        else if ( !v11 )
        {
LABEL_53:
          if ( v10 )
            v18 = 0;
          else
            v18 = 2;
          if ( (int)v12 > v18 )
          {
            v16 = (void *)(aMcsBwBw20mhz20);
            v17 = 735;
            return mmio_clear_register((int)v16, (int)aRcCheckRateCon, v17);
          }
          return result;
        }
        result = mmio_clear_register((int)aNss0, (int)aRcCheckRateCon, 734);
        if ( **v13 >= 0 )
          return result;
        goto LABEL_53;
      }
LABEL_42:
      if ( (v8 & 3) != 3 || (result = mmio_clear_register((int)aGi2, (int)aRcCheckRateCon, 722), **v13 < 0) )
      {
        if ( *(volatile uint8_t *)(a1 + 179) >= v10
          || (result = mmio_clear_register((int)aBwRcSsBwMax, (int)aRcCheckRateCon, 723), **v13 < 0) )
        {
          if ( *(volatile uint8_t *)(a1 + 180) >= v11
            || (result = mmio_clear_register((int)aNssRcSsNoSs, (int)aRcCheckRateCon, 724), **v13 < 0) )
          {
            if ( *(volatile uint8_t *)(a1 + 176) >= v12
              || (result = mmio_clear_register((int)aMcsRcSsMcsMax, (int)aRcCheckRateCon, 725), **v13 < 0) )
            {
              if ( (int)v12 > 2 * (((int)*(volatile uint16_t *)(a1 + 170) >> (2 * v11)) & 3) + 7 )
              {
                v16 = (void *)(aMcs72RcSsRateM);
                v17 = 726;
                return mmio_clear_register((int)v16, (int)aRcCheckRateCon, v17);
              }
            }
          }
        }
      }
      return result;
    default:
LABEL_71:
      if ( **v13 < 0 )
        goto LABEL_72;
      return result;
  }
}


// process_entry_list @ 0x13e1d0
int process_entry_list(int result, int a2) {
  unsigned int v2; // r11
  int v4; // r9
  int v5; // r5
  int v6; // r7
  volatile uint32_t *v7; // r4
  unsigned int v8; // r6
  unsigned int v9; // r1
  int64_t v10; // r2
  unsigned int v11; // t1
  int64_t v12; // kr00_8
  uint8_t v13[52]; // [sp+4h] [bp-34h] BYREF

  if ( *(volatile uint16_t *)(result + 184) )
  {
    v2 = (uint16_t)(*(volatile uint16_t *)(result + 184) - 1);
    v4 = result + 16;
    if ( v2 > 1 )
    {
      do
      {
        v5 = 1;
        v6 = 1;
        v7 = (volatile uint32_t *)(a2 + 4);
        v8 = v4;
        v9 = 0;
        do
        {
          while ( 1 )
          {
            v10 = (v10 & ~0xFFFFFFFFull) | ((uint32_t)(*v7) & 0xFFFFFFFFu);
            v11 = v7[1];
            ++v7;
            v10 = (v10 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(v11) << 32);
            if ( (unsigned int)v10 > v11 || !v10 && !*(volatile uint8_t *)(v8 + 9) && *(volatile uint8_t *)(v8 + 21) == 1 )
              break;
            v6 = (uint16_t)++v5;
            v8 += 12;
            if ( (uint16_t)v5 >= v2 )
              goto LABEL_10;
          }
          memmove((unsigned int)v13, v8, 0xCu);
          memmove(v8, v8 + 12, 0xCu);
          result = memmove(v8 + 12, (unsigned int)v13, 0xCu);
          ++v5;
          v12 = *(volatile uint64_t *)(v7 - 1);
          v9 = v6;
          v6 = (uint16_t)v5;
          *(v7 - 1) = HIDWORD(v12);
          *v7 = v12;
          v8 += 12;
        }
        while ( (uint16_t)v5 < v2 );
LABEL_10:
        if ( !v9 )
          break;
        v2 = v9;
      }
      while ( v9 > 1 );
    }
  }
  return result;
}


// rx_desc_validate @ 0x13e270
volatile uint16_t * rx_desc_validate(volatile uint16_t *result) {
  unsigned int v1; // r3
  int v2; // r1
  unsigned int v3; // r2
  int v4; // r4
  int v5; // r3

  v1 = *result;
  if ( *result )
  {
    v2 = *((volatile uint8_t *)result + 9);
    v3 = result[1] << 16;
    *((volatile uint8_t *)result + 8) = 0;
    v4 = v3 / v1;
    if ( v2 )
    {
      result[2] = (3 * (unsigned int)result[2] + v4) >> 2;
    }
    else
    {
      if ( v3 >= v1 )
        v2 = (v2 & ~0xFFFFu) | ((uint16_t)(v4 - 1) & 0xFFFFu);
      result[2] = v2;
      *((volatile uint8_t *)result + 9) = 1;
    }
  }
  else
  {
    v5 = *((volatile uint8_t *)result + 8);
    if ( v5 != 255 )
      *((volatile uint8_t *)result + 8) = v5 + 1;
  }
  return result;
}



// state_table_dispatch @ 0x13e2c0
int state_table_dispatch(volatile uint8_t *a1) {
  int result; // r0
  unsigned int v2; // r3
  int v3; // r3

  switch ( a1[169] )
  {
    case 0u:
    case 1u:
      v2 = a1[177];
      if ( !a1[177] )
        goto LABEL_15;
      if ( v2 > 3 )
        result = a1[177];
      else
        result = (uint16_t)(v2 | (a1[182] << 10));
      break;
    case 2u:
    case 3u:
      if ( !a1[177] )
        goto LABEL_15;
      result = (uint16_t)(a1[169] << 11);
      break;
    case 4u:
      result = 0x2000;
      break;
    case 5u:
      if ( a1[177] )
      {
        v3 = a1[194];
        if ( a1[183] )
          result = 14976;
        else
          result = 10752;
        if ( v3 )
          result |= 0x4000u;
      }
      else
      {
LABEL_15:
        result = 1024;
      }
      break;
    default:
      result = 0;
      break;
  }
  return result;
}



// process_list_entries @ 0x13e328
int process_list_entries(int a1) {
  int v1; // r4
  int v3; // r8
  int v4; // r3
  int v5; // r9
  int result; // r0
  int v7; // r3
  uint16_t v8; // r7
  int v9; // r6
  int v10; // r3
  int v11; // r2
  int v12; // r1
  unsigned int v13; // r4
  int v14; // r3
  int v15; // r6
  int v16; // r10
  int16_t v17; // r10
  int v18; // r11
  int16_t v19; // r10
  int16_t v20; // r11
  int16_t v21; // r6
  int v22; // r3

  v1 = *(volatile uint16_t *)(a1 + 184);
  if ( *(volatile uint16_t *)(a1 + 184) )
  {
    v3 = v1 - 1;
    v4 = a1;
    do
    {
      *(volatile uint16_t *)(v4 + 10) = -1;
      *(volatile uint16_t *)(v4 + 4) = 0;
      *(volatile uint16_t *)(v4 + 6) = 0;
      *(volatile uint16_t *)(v4 + 8) = 0;
      *(volatile uint8_t *)(v4 + 12) = 0;
      *(volatile uint8_t *)(v4 + 13) = 0;
      *(volatile uint8_t *)(v4 + 14) = 1;
      v4 += 12;
    }
    while ( v4 != a1 + 12 + 12 * (uint16_t)(v1 - 1) );
    v5 = v1 - 1;
  }
  else
  {
    v5 = -1;
    v3 = -1;
  }
  result = state_table_dispatch((void *)(uintptr_t)(a1));
  v7 = *(volatile uint8_t *)(a1 + 169);
  *(volatile uint16_t *)(a1 + 10) = result;
  switch ( v7 )
  {
    case 0:
    case 1:
      v8 = ((uint16_t)v7 << 11) | (*(volatile uint8_t *)(a1 + 182) << 10) | *(volatile uint8_t *)(a1 + 178);
      break;
    case 2:
    case 3:
      result = *(volatile uint8_t *)(a1 + 181);
      v8 = ((uint16_t)v7 << 11)
         | ((uint16_t)result << 9)
         | (*(volatile uint8_t *)(a1 + 179) << 7)
         | (8 * *(volatile uint8_t *)(a1 + 180))
         | (uint8_t)(31 - __clz(*(volatile uint8_t *)(a1 + *(volatile uint8_t *)(a1 + 180) + 170)));
      break;
    case 4:
      v17 = *(volatile uint8_t *)(a1 + 180);
      v18 = ((int)*(volatile uint16_t *)(a1 + 170) >> (2 * v17)) & 3;
      v19 = 16 * v17;
      v20 = v18 + 7;
      v21 = (*(volatile uint8_t *)(a1 + 179) << 7) | (*(volatile uint8_t *)(a1 + 181) << 9);
      do
      {
        v8 = v19 | v20 | v21 | 0x2000;
        result = ll_pdu_dispatch(a1, v8);
        --v20;
      }
      while ( !result && (uint8_t)v20 != 6 );
      break;
    case 5:
      v14 = *(volatile uint8_t *)(a1 + 180);
      v15 = 2 * (((int)*(volatile uint16_t *)(a1 + 170) >> (2 * v14)) & 3) + 7;
      v16 = (16 * v14) | (*(volatile uint8_t *)(a1 + 179) << 7);
      do
      {
        v8 = v16 | v15 | 0x2800;
        result = ll_pdu_dispatch(a1, v16 | v15 | 0x2800);
        v15 = (uint16_t)(v15 - 1);
      }
      while ( !result && (uint8_t)v15 != 6 );
      break;
    default:
      v8 = 0;
      break;
  }
  v9 = 1;
  *(volatile uint16_t *)(a1 + 12 * v5 + 10) = v8;
  if ( v3 <= 1 )
  {
LABEL_26:
    if ( !v1 )
      return result;
  }
  else
  {
    do
    {
      while ( 1 )
      {
        result = rf_cal_channel_get(a1);
        v1 = *(volatile uint16_t *)(a1 + 184);
        if ( *(volatile uint16_t *)(a1 + 184) )
          break;
LABEL_25:
        v22 = a1 + 12 * v9;
        v9 = (uint16_t)(v9 + 1);
        *(volatile uint16_t *)(v22 + 10) = result;
        if ( v9 >= v1 - 1 )
          goto LABEL_26;
      }
      v10 = a1;
      v11 = 0;
      while ( 1 )
      {
        v12 = *(volatile uint16_t *)(v10 + 10);
        ++v11;
        v10 += 12;
        if ( v12 == result )
          break;
        if ( v11 == v1 )
          goto LABEL_25;
      }
    }
    while ( v9 < v1 - 1 );
  }
  v13 = 0;
  do
    result = sub_13DA90(a1, (uint16_t)v13++);
  while ( v13 < *(volatile uint16_t *)(a1 + 184) );
  return result;
}


// tx_flag_check_process @ 0x13e4e0
int tx_flag_check_process(int a1) {
  char v1; // r6
  int v2; // r5
  int v3; // r4
  unsigned int v4; // r0
  int v5; // r7
  int v6; // r3
  unsigned int v7; // r2
  uint16_t v8; // r0
  int v9; // r0
  int v10; // r3
  int v12; // r2
  int v13; // r3

  v1 = *(volatile uint8_t *)(a1 + 166);
  v2 = v1 & 0x10;
  v3 = a1;
  if ( (v1 & 0x10) != 0 )
  {
    v4 = *(volatile uint16_t *)(a1 + 184);
    if ( !v4 )
    {
      *(volatile uint16_t *)(v3 + 3070) = *(volatile uint16_t *)(v3 + 190);
      *(volatile uint16_t *)(v3 + 3068) = 0;
      *(volatile uint32_t *)(v3 + 136) = 16711935;
      *(volatile uint16_t *)(v3 + 140) = 255;
      goto LABEL_10;
    }
    v5 = *(volatile uint16_t *)(v3 + 190);
    v6 = 0;
    while ( 1 )
    {
      v7 = (uint8_t)(v6 + 1);
      if ( *(volatile uint16_t *)(v3 + 12 * v6 + 10) == v5 )
        break;
      v6 = (uint8_t)(v6 + 1);
      if ( v7 >= v4 )
      {
        if ( v7 == v4 )
        {
          v8 = v4 - 1;
          v13 = v3 + 12 * (uint8_t)v8;
          *(volatile uint16_t *)(v13 + 10) = v5;
          *(volatile uint16_t *)(v13 + 8) = 0;
          *(volatile uint16_t *)(v3 + 136) = (uint8_t)v8;
          *(volatile uint16_t *)(v3 + 138) = (uint8_t)v8;
          *(volatile uint16_t *)(v3 + 140) = (uint8_t)v8;
LABEL_8:
          v9 = v3 + 12 + 12 * v8;
          v10 = v3;
          do
          {
            *(volatile uint16_t *)(v10 + 4) = 0;
            *(volatile uint16_t *)(v10 + 6) = 0;
            v10 += 12;
          }
          while ( v9 != v10 );
LABEL_10:
          *(volatile uint8_t *)(v3 + 166) = v1 & 0xCF | 0x20;
          *(volatile uint8_t *)(v3 + 154) = 0;
          return 1;
        }
LABEL_7:
        *(volatile uint16_t *)(v3 + 136) = v7;
        *(volatile uint16_t *)(v3 + 138) = v7;
        *(volatile uint16_t *)(v3 + 140) = v7;
        v8 = v4 - 1;
        goto LABEL_8;
      }
    }
    v7 = (v7 & ~0xFFFFu) | ((uint16_t)(v6) & 0xFFFFu);
    goto LABEL_7;
  }
  rx_desc_validate((volatile uint16_t *)(a1 + 12 * *(volatile uint8_t *)(a1 + 136) + 4));
  if ( !*(volatile uint16_t *)(v3 + 184) )
    return v2;
  v12 = v3 + 12 + 12 * (uint16_t)(*(volatile uint16_t *)(v3 + 184) - 1);
  do
  {
    *(volatile uint16_t *)(v3 + 4) = 0;
    *(volatile uint16_t *)(v3 + 6) = 0;
    v3 += 12;
  }
  while ( v3 != v12 );
  return v1 & 0x10;
}



// ipc_dispatch_cmd @ 0x13e5d4
unsigned int ipc_dispatch_cmd(int a1, unsigned int a2, unsigned int a3, int a4, int a5) {
  unsigned int result; // r0
  int v8; // r1
  int v10; // lr
  int16_t v11; // r2
  int16_t v12; // r5
  int v13; // r2
  int v14; // r1
  volatile int16_t **v15; // r11
  int v16; // r9
  int v17; // r4
  int v18; // r1
  int v19; // r10
  volatile uint8_t *v20; // r12
  int v21; // t1
  int v22; // r5
  int v23; // r2
  int v24; // r3
  int v25; // r4
  int16_t v26; // r3
  int16_t v27; // r3
  int16_t v28; // r8
  int16_t v29; // r2
  volatile unsigned int *v30; // r3
  volatile uint8_t *v31; // r10
  unsigned int v32; // r2
  int v33; // r6
  int v34; // r5
  int v35; // r7
  unsigned int v36; // r4
  unsigned int v37; // r8
  int v38; // r2
  int v39; // t1
  unsigned int v40; // t1
  unsigned int v41; // r1
  int v42; // r2
  int v43; // r12
  int16_t v44; // r3
  volatile unsigned int *v45; // r3
  volatile uint8_t *v46; // r10
  unsigned int v47; // r2
  int v48; // r6
  int v49; // r5
  int v50; // r7
  unsigned int v51; // r4
  unsigned int v52; // r8
  int v53; // r2
  int v54; // t1
  unsigned int v55; // t1
  unsigned int v56; // r1
  int v57; // r2
  int v58; // r12
  int16_t v59; // r2
  volatile uint16_t *v60; // r3
  volatile int16_t *v61; // r4
  unsigned int v62; // r2
  unsigned int v63; // r1
  int16_t v64; // r2
  unsigned int v65; // r2
  int16_t v66; // r3
  int16_t v67; // r2
  int16_t v68; // r2
  struct __attribute__((packed)) { union { int v69; // [sp+0h] [bp-24h]
  volatile unsigned int *v70; // [sp+0h] [bp-24h]
  volatile unsigned int *v71; }; // [sp+0h] [bp-24h]
  char _pad1[4]; int v73; // [sp+8h] [bp-1Ch]
  int v74; // [sp+Ch] [bp-18h]
  char _pad3[4]; volatile unsigned int *v75; // [sp+14h] [bp-10h]
  char _pad4[4]; uint8_t v76[8]; // [sp+1Ch] [bp-8h] BYREF
  } _frame;
  result = *(volatile uint8_t *)(a1 + 29);
  *(volatile uint32_t *)_frame.v76 = -1;
  if ( result > 0x1F )
    return result;
  v8 = *(volatile uint32_t *)(a1 + 76);
  result = dword_13EA50 + 696 * result;
  v10 = *(volatile uint8_t *)(result + 34);
  v11 = *(volatile uint16_t *)(a1 + 30);
  v12 = v11 & 0xDFFF;
  _frame.v73 = *(volatile uint32_t *)(v8 + 72) & 0x400000;
  v13 = v11 & 0x2000;
  v14 = (*(volatile uint32_t *)(v8 + 64) & 0x2000) != 0 ? a4 : 1;
  _frame.v69 = v14;
  *(volatile uint16_t *)(a1 + 30) = v12;
  _frame.v74 = v13;
  if ( v10 == 255 )
    return result;
  v15 = (volatile int16_t **)off_13EA54;
  v16 = *(volatile uint32_t *)(result + 340);
  if ( **(volatile int16_t **)off_13EA54 < 0 )
  {
    if ( v16 )
    {
      if ( !a4 )
        goto LABEL_26;
      if ( a5 )
        goto LABEL_9;
    }
    else
    {
      mmio_clear_register(dword_13EADC, dword_13EAD8, 2470);
      if ( !a4 )
        goto LABEL_26;
      if ( **v15 >= 0 || a5 )
        goto LABEL_9;
    }
    mmio_clear_register(dword_13EA48, dword_13EA44, 2473);
    goto LABEL_9;
  }
  if ( !a4 )
  {
LABEL_26:
    v17 = *(volatile uint32_t *)(a1 + 72) + 44;
    goto LABEL_10;
  }
LABEL_9:
  v17 = a5 + 272;
LABEL_10:
  v18 = *(volatile uint16_t *)(v16 + 184);
  result = v17 + 20;
  _frame.v75 = (volatile unsigned int *)(v17 + 20);
  v19 = v17 + 36;
  v20 = _frame.v76;
  do
  {
    v21 = *(volatile uint32_t *)result;
    result += 4;
    v22 = v21 & 0x3FFF;
    if ( v18 )
    {
      v23 = v16 + 12 * v18;
      v24 = 0;
      while ( 1 )
      {
        v25 = *(volatile uint16_t *)(v23 - 2);
        v23 -= 12;
        if ( v25 == v22 )
          break;
        if ( ++v24 == v18 )
          goto LABEL_16;
      }
      *v20 = v18 - 1 - v24;
    }
LABEL_16:
    if ( _frame.v69 )
    {
      if ( ((*(volatile uint8_t *)(a1 + 54) >> 2) & 7) == *(volatile uint8_t *)(v16 + 167) )
      {
        v64 = *(volatile uint16_t *)(v16 + 146);
        result = (uint16_t)a2;
        *(volatile uint16_t *)(v16 + 144) += a2;
        *(volatile uint16_t *)(v16 + 146) = v64 + 1;
        if ( !_frame.v73 )
        {
          if ( _frame.v74 )
          {
LABEL_83:
            if ( _frame.v76[0] == 255 )
            {
LABEL_38:
              *(volatile uint8_t *)(v16 + 154) = 0;
              return result;
            }
            v60 = (volatile uint16_t *)(v16 + 12 * _frame.v76[0] + 4);
            *(volatile uint8_t *)(v16 + 154) = 0;
            goto LABEL_55;
          }
          if ( _frame.v76[0] == 255 )
            v60 = 0;
          else
            v60 = (volatile uint16_t *)(v16 + 12 * _frame.v76[0] + 4);
          v65 = *(volatile uint8_t *)(v16 + 168);
          if ( a2 >= 2 * a3 )
          {
            if ( *(volatile uint8_t *)(v16 + 168) )
            {
              *(volatile uint8_t *)(v16 + 168) = v65 - 1;
              if ( !v60 )
                return result;
              goto LABEL_55;
            }
          }
          else
          {
            if ( v65 <= 1 )
            {
              *(volatile uint8_t *)(v16 + 168) = v65 + 1;
              if ( !v60 )
                return result;
              goto LABEL_55;
            }
            if ( v65 == 2 )
            {
              *(volatile uint32_t *)v16 -= 75000;
              if ( !v60 )
                return result;
              goto LABEL_55;
            }
          }
          if ( !v60 )
            return result;
LABEL_55:
          v61 = *v15;
          v62 = (uint16_t)(result - a3 + v60[1]);
          v63 = (uint16_t)(*v60 + result);
          v60[1] = v62;
          *v60 = v63;
          if ( *v61 < 0 && v63 < v62 )
            return mmio_clear_register(dword_13EA4C, dword_13EA44, 2589);
          return result;
        }
      }
      else
      {
        if ( !_frame.v73 )
        {
          v59 = *(volatile uint16_t *)(v16 + 144);
          result = (uint16_t)a2;
          ++*(volatile uint16_t *)(v16 + 146);
          *(volatile uint16_t *)(v16 + 144) = v59 + a2;
          if ( !_frame.v74 )
          {
            if ( _frame.v76[0] == 255 )
              return result;
            v60 = (volatile uint16_t *)(v16 + 12 * _frame.v76[0] + 4);
            goto LABEL_55;
          }
          goto LABEL_83;
        }
        result = (uint16_t)a2;
        v66 = *(volatile uint16_t *)(v16 + 146) + 1;
        *(volatile uint16_t *)(v16 + 144) += a2;
        *(volatile uint16_t *)(v16 + 146) = v66;
      }
      v60 = (volatile uint16_t *)(v16 + 124);
      goto LABEL_55;
    }
    ++v20;
  }
  while ( v19 != result );
  if ( ((*(volatile uint8_t *)(a1 + 54) >> 2) & 7) != *(volatile uint8_t *)(v16 + 167) )
  {
    if ( _frame.v73 )
    {
      v26 = *(volatile uint16_t *)(v16 + 144) + 1;
      ++*(volatile uint16_t *)(v16 + 146);
      *(volatile uint16_t *)(v16 + 144) = v26;
      goto LABEL_21;
    }
    v44 = *(volatile uint16_t *)(v16 + 144) + 1;
    ++*(volatile uint16_t *)(v16 + 146);
    *(volatile uint16_t *)(v16 + 144) = v44;
LABEL_28:
    if ( _frame.v74 )
    {
      v31 = _frame.v76;
      v30 = _frame.v75;
      v32 = a3;
      v33 = dword_13EA44;
      v34 = dword_13EA4C;
      v35 = 0;
      v36 = a2;
      v37 = v32;
      while ( 1 )
      {
        if ( !v36 )
          goto LABEL_38;
        v39 = *v31++;
        v38 = v39;
        v40 = *v30++;
        v41 = v40 >> 29;
        if ( v38 != 255 )
        {
          v42 = 12 * v38;
          result = v42 + 4;
          v43 = v16 + v42 + 4;
          if ( v35 )
          {
            if ( v35 != 3 )
              goto LABEL_34;
            goto LABEL_74;
          }
          if ( v37 )
          {
            --v37;
            --v36;
            ++*(volatile uint16_t *)(v42 + v16 + 4);
LABEL_34:
            if ( v41 <= v37 )
              goto LABEL_35;
LABEL_74:
            v68 = *(volatile uint16_t *)(v43 + 2) + v36 - v37;
            v37 = 0;
            *(volatile uint16_t *)(v16 + result) += v36;
            v36 = 0;
            *(volatile uint16_t *)(v43 + 2) = v68;
          }
          else
          {
            if ( v41 )
              goto LABEL_74;
LABEL_35:
            *(volatile uint16_t *)(v16 + result) += v41;
            v36 -= v41;
            v37 -= v41;
          }
          if ( **v15 < 0 && *(volatile uint16_t *)(v16 + result) < (unsigned int)*(volatile uint16_t *)(v43 + 2) )
          {
            _frame.v70 = v30;
            result = mmio_clear_register(v34, v33, 2657);
            v30 = _frame.v70;
          }
          goto LABEL_37;
        }
        if ( v35 )
        {
          if ( v35 == 3 )
            goto LABEL_38;
        }
        else
        {
          if ( !v37 )
          {
            if ( v41 )
              goto LABEL_38;
            goto LABEL_78;
          }
          --v37;
          --v36;
        }
        if ( v41 > v37 )
          goto LABEL_38;
LABEL_78:
        v36 -= v41;
        v37 -= v41;
LABEL_37:
        if ( ++v35 == 4 )
          goto LABEL_38;
      }
    }
    v46 = _frame.v76;
    v45 = _frame.v75;
    v47 = a3;
    v48 = dword_13EA44;
    v49 = dword_13EA4C;
    v50 = 0;
    v51 = a2;
    v52 = v47;
    while ( 2 )
    {
      if ( !v51 )
        return result;
      v54 = *v46++;
      v53 = v54;
      v55 = *v45++;
      v56 = v55 >> 29;
      if ( v53 != 255 )
      {
        v57 = 12 * v53;
        result = v57 + 4;
        v58 = v16 + v57 + 4;
        if ( v50 )
        {
          if ( v50 != 3 )
            goto LABEL_45;
          goto LABEL_72;
        }
        if ( v52 )
        {
          --v52;
          --v51;
          ++*(volatile uint16_t *)(v57 + v16 + 4);
LABEL_45:
          if ( v56 <= v52 )
            goto LABEL_46;
LABEL_72:
          v67 = *(volatile uint16_t *)(v58 + 2) + v51 - v52;
          v52 = 0;
          *(volatile uint16_t *)(v16 + result) += v51;
          v51 = 0;
          *(volatile uint16_t *)(v58 + 2) = v67;
        }
        else
        {
          if ( v56 )
            goto LABEL_72;
LABEL_46:
          *(volatile uint16_t *)(v16 + result) += v56;
          v51 -= v56;
          v52 -= v56;
        }
        if ( **v15 < 0 && *(volatile uint16_t *)(v16 + result) < (unsigned int)*(volatile uint16_t *)(v58 + 2) )
        {
          _frame.v71 = v45;
          result = mmio_clear_register(v49, v48, 2704);
          v45 = _frame.v71;
        }
LABEL_48:
        if ( ++v50 == 4 )
          return result;
        continue;
      }
      break;
    }
    if ( v50 )
    {
      if ( v50 == 3 )
        return result;
      goto LABEL_81;
    }
    if ( v52 )
    {
      --v52;
      --v51;
LABEL_81:
      if ( v56 > v52 )
        return result;
    }
    else if ( v56 )
    {
      return result;
    }
    v51 -= v56;
    v52 -= v56;
    goto LABEL_48;
  }
  v29 = *(volatile uint16_t *)(v16 + 146);
  ++*(volatile uint16_t *)(v16 + 144);
  *(volatile uint16_t *)(v16 + 146) = v29 + 1;
  if ( !_frame.v73 )
    goto LABEL_28;
LABEL_21:
  v27 = a2 - a3 + *(volatile uint16_t *)(v16 + 126);
  v28 = a2 + *(volatile uint16_t *)(v16 + 124);
  *(volatile uint16_t *)(v16 + 126) = v27;
  *(volatile uint16_t *)(v16 + 124) = v28;
  return result;
}



// int_status_check @ 0x13eae0
unsigned int int_status_check(unsigned int result) {
  unsigned int v1; // r2

  v1 = *(volatile uint32_t *)(*(volatile uint32_t *)(result + 76) + 4);
  if ( (v1 & 0x810000) != 0 )
    return ipc_dispatch_cmd(result, BYTE1(v1) + 1, (HIWORD(v1) & 1) + BYTE1(v1), 0, 0);
  return result;
}



// ipc_dispatch_one @ 0x13eb0c
unsigned int ipc_dispatch_one(int a1, unsigned int a2, int a3, int a4) {
  return ipc_dispatch_cmd(a1, a2, a2 - a3, 1, a4);
}



// rx_header_parse @ 0x13eb20
unsigned int rx_header_parse(int a1) {
  unsigned int v1; // r3
  int v2; // r1
  int v3; // r4
  int v4; // r2
  unsigned int result; // r0
  unsigned int v6; // r0
  int v7; // r3
  unsigned int v8; // r0

  v1 = *(volatile uint16_t *)(a1 + 6);
  v2 = (v1 >> 11) & 7;
  if ( (v1 & 0x2000) != 0 )
  {
    v3 = v1 & 0xF;
    switch ( v2 )
    {
      case 5:
        v6 = *(volatile uint32_t *)(dword_13EC64 + 4 * (6 * (v1 & 0xF) + 3 * ((v1 >> 8) & 1) + ((v1 >> 9) & 3))) >> ((v1 & 0x80) != 0);
        v7 = (v1 >> 4) & 7;
        return v6 / (v7 + 1);
      case 6:
        v8 = *(volatile uint8_t *)(a1 + 8) & 7;
        if ( v8 > 2 )
          result = (*(volatile uint32_t *)(dword_13EC64
                              + 4
                              * (6 * (v1 & 0xF) + ((v8 - 3) & 0xFE) + ((uint8_t)(v8 - 3) >> 1) + ((v1 >> 9) & 3))) >> ((v8 - 3) & 1))
                 / (((v1 >> 4) & 7) + 1);
        else
          result = *(volatile uint32_t *)(*(volatile uint32_t *)(dword_13EC60 + 4 * v8) + 4 * (3 * (v1 & 0xF) + ((v1 >> 9) & 3)))
                 / (((v1 >> 4) & 7) + 1);
        break;
      case 7:
        if ( ((v1 >> 7) & 3) == 1 )
          result = *(volatile uint32_t *)(dword_13EC6C + 4 * ((v1 >> 9) & 3)) / (((v1 >> 4) & 7) + 1);
        else
          result = *(volatile uint32_t *)(dword_13EC64 + 4 * (6 * (v1 & 0xF) + ((v1 >> 9) & 3))) / (((v1 >> 4) & 7) + 1);
        break;
      default:
        goto LABEL_7;
    }
  }
  else if ( ((v1 >> 11) & 6) != 0 )
  {
    v3 = v1 & 7;
LABEL_7:
    v6 = *(volatile uint32_t *)(dword_13EC5C + 4 * ((v1 >> 9) & 1 | (2 * ((v1 >> 7) & 3)) | (8 * v3)));
    if ( v2 == 4 )
      v7 = (v1 >> 4) & 7;
    else
      v7 = (v1 >> 3) & 3;
    return v6 / (v7 + 1);
  }
  else
  {
    v4 = v1 & 0x7F;
    if ( (v1 & 0x7C) != 0 )
      return *(volatile uint32_t *)(dword_13EC68 + 4 * (v4 - 4));
    else
      return *(volatile uint32_t *)(dword_13EC58 + 4 * ((v1 >> 10) & 1 | (2 * v4)));
  }
  return result;
}



// ble_ll_conn_rx_pdu @ 0x13ec70
int ble_ll_conn_rx_pdu(int a1, int a2) {
  int v2; // r3
  unsigned int v3; // r2
  int v5; // r0
  int v6; // r5
  int v7; // r7
  int v8; // r7
  int v9; // r0
  unsigned int v10; // r9
  uint16_t v11; // r0
  signed int v12; // r3
  int v13; // r6
  int v14; // r7
  int v15; // r11
  unsigned int v16; // r5
  unsigned int v17; // r1
  int v18; // r0
  int v19; // r2
  unsigned int v20; // r12
  unsigned int v21; // r0
  unsigned int v22; // r3
  unsigned int v23; // r0
  unsigned int v24; // r12
  unsigned int v25; // r7
  unsigned int v26; // r10
  int v27; // r9
  unsigned int v28; // r6
  int v29; // r3
  int v30; // r0
  unsigned int v31; // r3
  unsigned int v32; // r6
  unsigned int v33; // r5
  int v34; // lr
  int v35; // r0
  int v36; // r0
  int v37; // r0
  int v38; // r3
  int v39; // r0
  int v40; // r11
  volatile uint8_t *v41; // r3
  int16_t v42; // r0
  unsigned int v43; // r3
  int v44; // r2
  struct __attribute__((packed)) { union { unsigned int v45; // [sp+0h] [bp-40h]
  int v46; }; // [sp+0h] [bp-40h]
  union { int v47; // [sp+4h] [bp-3Ch]
  int v48; // [sp+4h] [bp-3Ch]
  int v49; // [sp+4h] [bp-3Ch]
  int v50; }; // [sp+4h] [bp-3Ch]
  char _pad2[4]; int result; // [sp+Ch] [bp-34h] BYREF
  int16_t v52; // [sp+10h] [bp-30h]
  int16_t v53; // [sp+12h] [bp-2Eh]
  int16_t v54; // [sp+14h] [bp-2Ch]
  uint16_t v55; // [sp+16h] [bp-2Ah]
  uint16_t v56[20]; // [sp+18h] [bp-28h] BYREF
  } _frame;
  v2 = *(volatile uint8_t *)(a1 + 166);
  v3 = v2 << 26;
  if ( (v2 & 0x20) != 0 )
    return 0;
  v5 = *(volatile uint8_t *)(a1 + 154);
  if ( v5 )
    return 0;
  v6 = *(volatile uint16_t *)(a1 + 152);
  if ( *(volatile uint16_t *)(a1 + 152) )
  {
    *(volatile uint16_t *)(a1 + 152) = v6 - 1;
    return v5;
  }
  if ( (v2 & 0x40) == 0 )
  {
    v7 = *(volatile uint16_t *)(a1 + 136);
    goto LABEL_6;
  }
  v3 = *(volatile uint16_t *)(a1 + 184);
  if ( v3 <= 9 )
  {
    v7 = *(volatile uint16_t *)(a1 + 136);
    goto LABEL_31;
  }
  v25 = *(volatile uint8_t *)(a1 + 178);
  v26 = *(volatile uint8_t *)(a1 + 177);
  v27 = *(volatile uint16_t *)(a1 + 12 * *(volatile uint16_t *)(a1 + 138) + 10);
  v28 = *(volatile uint16_t *)(a1 + 12 * *(volatile uint16_t *)(a1 + 136) + 10);
  memset(&_frame.result, 0xFFu, 0xCu);
  v3 = v25 - v26;
  _frame.v46 = v25 - v26 + 1;
  while ( 2 )
  {
    v29 = (uint8_t)v6 - 1;
    switch ( (char)v6 )
    {
      case 1:
        if ( v26 <= 3 && (*(volatile uint8_t *)(a1 + 166) & 8) != 0 )
        {
          v42 = scale_timer_value();
          v43 = (uint8_t)((v42 & 0x7F) % _frame.v46 + v26);
          v44 = *(volatile uint16_t *)(a1 + 174) >> v43;
          a2 = v44 << 31;
          if ( (v44 & 1) != 0 )
          {
            if ( !((uint8_t)((v42 & 0x7F) % _frame.v46) + (uint8_t)v26) )
              v43 = v25;
          }
          else
          {
            v43 = v25;
          }
          v3 = v43 - 1;
          _frame.result = (_frame.result & ~0xFFFF0000u) | (((uint16_t)(v43) & 0xFFFFu) << 16);
          if ( v43 - 1 <= 2 )
          {
            a2 = *(volatile uint8_t *)(a1 + 182);
            v3 = v42 & 0x400 | (a2 << 10);
            _frame.result = (_frame.result & ~0xFFFF0000u) | (((uint16_t)(v43 | v3) & 0xFFFFu) << 16);
          }
        }
        else
        {
          v3 = (v28 >> 11) & 5;
          if ( v3 == 5 )
          {
            v38 = ((v28 >> 9) & 3) + 1;
            a2 = ((unsigned int)dword_13F0B8 * (uint64_t)(unsigned int)v38) >> 32;
            v3 = (a2 & 0xFFFFFFFE) + ((unsigned int)a2 >> 1);
            v28 = (v28 & ~0xFFFFu) | ((uint16_t)(v28 & 0xF9FF) & 0xFFFFu);
            _frame.result = (_frame.result & ~0xFFFF0000u) | (((uint16_t)(v28 | (((uint16_t)v38 - (uint16_t)v3) << 9)) & 0xFFFFu) << 16);
            v28 = (uint16_t)v28;
          }
          else if ( ((v28 >> 11) & 6) != 0 && *(volatile uint8_t *)(a1 + 181) == 1 )
          {
            _frame.result = (_frame.result & ~0xFFFF0000u) | (((uint16_t)(v28 ^ 0x200) & 0xFFFFu) << 16);
          }
        }
        goto LABEL_68;
      case 2:
        v37 = ((int (*)())ll_pdu_type_get)(a1, v28, v3, v29);
        a2 = v37;
        if ( v37 != v28 )
        {
          _frame.v50 = v37;
          if ( ll_pdu_dispatch(a1, v37) )
          {
            a2 = _frame.v50;
            _frame.v52 = _frame.v50;
          }
        }
        goto LABEL_68;
      case 3:
        v36 = ((int (*)())bt_cmd_handler_1)(a1, v28, v3, v29);
        a2 = v36;
        if ( v36 != v28 )
        {
          _frame.v49 = v36;
          if ( ll_pdu_dispatch(a1, v36) )
          {
            a2 = _frame.v49;
            _frame.v53 = _frame.v49;
          }
        }
        goto LABEL_68;
      case 4:
        v35 = ((int (*)())ll_pdu_type_get)(a1, v27, v3, v29);
        a2 = v35;
        if ( v27 != v35 )
        {
          _frame.v48 = v35;
          if ( ll_pdu_dispatch(a1, v35) )
          {
            a2 = _frame.v48;
            _frame.v54 = _frame.v48;
          }
        }
LABEL_68:
        if ( v25 <= 3 )
          goto LABEL_69;
        goto LABEL_71;
      case 5:
        v30 = ((int (*)())bt_cmd_handler_1)(a1, v27, v3, v29);
        a2 = v30;
        if ( v27 != v30 )
        {
          _frame.v47 = v30;
          if ( ll_pdu_dispatch(a1, v30) )
          {
            a2 = _frame.v47;
            _frame.v55 = _frame.v47;
          }
        }
        if ( v25 > 3 )
          goto LABEL_53;
        v3 = *((volatile uint16_t *)&_frame.result + v6);
        if ( v3 != 0xFFFF )
          goto LABEL_53;
        goto LABEL_84;
      default:
        _frame.result = (_frame.result & ~0xFFFFu) | ((uint16_t)(rf_cal_channel_get(a1)) & 0xFFFFu);
        if ( v25 <= 3 )
        {
LABEL_69:
          v3 = *((volatile uint16_t *)&_frame.result + v6);
          if ( v3 == 0xFFFF )
LABEL_84:
            *((volatile uint16_t *)&_frame.result + v6) = v25 | 0x400;
        }
        if ( (uint8_t)v6 != 5 )
        {
LABEL_71:
          ++v6;
          continue;
        }
LABEL_53:
        v31 = *(volatile uint16_t *)(a1 + 184);
        if ( v31 <= 1 )
        {
          v7 = *(volatile uint16_t *)(a1 + 136);
        }
        else
        {
          v32 = 0;
          v33 = 1;
          v7 = *(volatile uint16_t *)(a1 + 136);
          do
          {
            v3 = a1 + 12 * v33;
            a2 = *(volatile uint16_t *)(v3 + 8);
            if ( a2 < 0 && (a2 = *(volatile uint8_t *)(v3 + 12), (unsigned int)a2 <= 0xA)
              || v33 == v7
              || (a2 = *(volatile uint16_t *)(a1 + 138), a2 == v33)
              || (a2 = *(volatile uint16_t *)(a1 + 140), a2 == v33)
              || v32 > 5 )
            {
              v33 = (uint16_t)(v33 + 1);
            }
            else
            {
              a2 = (int)&_frame.v56[v32];
              v34 = *(volatile uint16_t *)(a2 - 12);
              if ( v34 != 0xFFFF )
              {
                if ( v31 )
                {
                  a2 = a1;
                  v39 = 0;
                  while ( 1 )
                  {
                    v40 = *(volatile uint16_t *)(a2 + 10);
                    ++v39;
                    a2 += 12;
                    if ( v40 == v34 )
                      break;
                    if ( v39 == v31 )
                      goto LABEL_92;
                  }
                }
                else
                {
LABEL_92:
                  v41 = (volatile uint8_t *)(a1 + 12 * v33);
                  *(volatile uint16_t *)(v3 + 10) = v34;
                  *(volatile uint16_t *)(v3 + 8) = 0;
                  v41[13] = 0;
                  *(volatile uint16_t *)(v3 + 4) = 0;
                  *(volatile uint16_t *)(v3 + 6) = 0;
                  v41[12] = 0;
                  v41[14] = 1;
                  sub_13DA90(a1, v33);
                  v33 = (uint16_t)(v33 + 1);
                  v7 = *(volatile uint16_t *)(a1 + 136);
                  v31 = *(volatile uint16_t *)(a1 + 184);
                }
              }
              ++v32;
            }
          }
          while ( v31 > v33 );
        }
        v2 = (v2 & ~0xFFu) | ((uint8_t)(*(volatile uint8_t *)(a1 + 166)) & 0xFFu);
LABEL_31:
        *(volatile uint8_t *)(a1 + 166) = v2 & 0xBF;
LABEL_6:
        v8 = 12 * v7;
        v9 = ((int (*)())rx_header_parse)(v8 + 4 + a1, a2, v3);
        v10 = *(volatile uint8_t *)(a1 + 169);
        _frame.v45 = v9;
        *(volatile uint16_t *)(a1 + 152) = 10 * *(volatile uint16_t *)(a1 + 150);
        v11 = scale_timer_value();
        v12 = *(volatile uint16_t *)(a1 + 184);
        v13 = (uint16_t)(v11 % *(volatile uint16_t *)(a1 + 184));
        if ( *(volatile uint16_t *)(a1 + 184) )
        {
          v14 = v8 + a1;
          v15 = 0;
          while ( 1 )
          {
            while ( 1 )
            {
              v16 = (v13 + v15) % (unsigned int)v12;
              v13 = (uint16_t)v16;
              if ( *(volatile uint16_t *)(a1 + 136) == (uint16_t)v16 )
                goto LABEL_26;
              v17 = a1 + 12 * v16;
              if ( *(volatile uint16_t *)(v17 + 8) > 0xF333u )
                goto LABEL_26;
              if ( v10 <= 1 )
                goto LABEL_24;
              v18 = *(volatile uint8_t *)(a1 + 166);
              v19 = v18 << 30;
              if ( (v18 & 2) != 0 )
                break;
              v21 = *(volatile uint16_t *)(a1 + 188);
              if ( !*(volatile uint16_t *)(a1 + 188) )
              {
                v19 = *(volatile uint16_t *)(a1 + 192);
                if ( !*(volatile uint16_t *)(a1 + 192) )
                  goto LABEL_19;
              }
              v20 = *(volatile uint16_t *)(v17 + 10);
              v17 = v20 >> 11;
              if ( ((v20 >> 11) & 6) != 0 )
                goto LABEL_15;
              if ( v12 <= ++v15 )
                return 0;
            }
            v20 = *(volatile uint16_t *)(v17 + 10);
            v17 = v20 >> 11;
            if ( ((v20 >> 11) & 6) != 0 )
              break;
LABEL_26:
            if ( v12 <= ++v15 )
              return 0;
          }
          v21 = *(volatile uint16_t *)(a1 + 188);
          if ( !*(volatile uint16_t *)(a1 + 188) && !*(volatile uint16_t *)(a1 + 192) )
            goto LABEL_19;
LABEL_15:
          v17 &= 7u;
          if ( v17 <= 3 )
          {
            if ( v17 <= 1 )
            {
              v22 = v20 & 0x7F;
              goto LABEL_18;
            }
            if ( (v20 & 0x10) != 0 )
              goto LABEL_19;
            v22 = v20 & 7;
LABEL_18:
            if ( mem_size_classify(v21) <= v22 )
              goto LABEL_19;
LABEL_25:
            v12 = *(volatile uint16_t *)(a1 + 184);
            goto LABEL_26;
          }
          if ( (((int)v20 >> 4) & 6) == 0 )
          {
            v22 = v20 & 0xF;
            goto LABEL_18;
          }
LABEL_19:
          v23 = ((int (*)())rx_header_parse)(12 * v16 + 4 + a1, v17, v19);
          if ( *(volatile uint8_t *)(a1 + 12 * v16 + 13) )
            v24 = 32;
          else
            v24 = *(volatile uint16_t *)(a1 + 150);
          if ( *(volatile uint16_t *)(v14 + 8) <= 0xF333u )
          {
            if ( _frame.v45 <= v23 )
              goto LABEL_24;
          }
          else if ( _frame.v45 <= v23 )
          {
LABEL_23:
            if ( *(volatile uint8_t *)(a1 + 12 * v16 + 12) >= v24 )
              goto LABEL_24;
            goto LABEL_25;
          }
          if ( !*(volatile uint8_t *)(a1 + 12 * v16 + 13) )
          {
LABEL_24:
            *(volatile uint8_t *)(a1 + 164) = v16;
            *(volatile uint8_t *)(a1 + 154) = 1;
            return 1;
          }
          goto LABEL_23;
        }
        return 0;
    }
  }
}


// ble_ll_conn_sm_get @ 0x13f0bc
int ble_ll_conn_sm_get(int a1) {
  volatile int16_t **v1; // r7
  int v2; // r6
  volatile int16_t *v3; // r8
  unsigned int v4; // r5
  unsigned int v6; // r0
  int v7; // r0
  uint32_t v9[10]; // [sp+0h] [bp-28h] BYREF

  v1 = (volatile int16_t **)off_13F164;
  v2 = dword_13F168;
  v3 = *(volatile int16_t **)off_13F164;
  v4 = *(volatile uint32_t *)(dword_13F168 + 696 * a1 + 340);
  if ( **(volatile int16_t **)off_13F164 < 0 && !v4 )
  {
    mmio_clear_register(dword_13F170, dword_13F16C, 3297);
    v3 = *v1;
  }
  v6 = bt_state_handler(v4);
  *(volatile uint16_t *)(v4 + 184) = v6;
  if ( *v3 < 0 )
  {
    if ( !v6 )
    {
      mmio_clear_register(dword_13F178, dword_13F16C, 3301);
      if ( **v1 >= 0 )
        goto LABEL_3;
      v6 = *(volatile uint16_t *)(v4 + 184);
    }
    if ( v6 > 0xA )
      mmio_clear_register(dword_13F174, dword_13F16C, 3302);
  }
LABEL_3:
  process_list_entries(v4);
  v7 = scan_process_list(v4, v9);
  bt_clr_flag(v7);
  *(volatile uint8_t *)(v2 + 696 * a1 + 350) |= 1u;
  return 696;
}



// ble_ll_conn_sm_get_by_handle @ 0x13f17c
int ble_ll_conn_sm_get_by_handle(int a1, unsigned int a2, unsigned int a3) {
  volatile int16_t **v3; // r8
  int v4; // r3
  int result; // r0
  volatile uint8_t *v7; // r4
  volatile int16_t *v10; // r3

  v3 = (volatile int16_t **)off_13F240;
  v4 = dword_13F22C + 696 * a1;
  result = **(volatile int16_t **)off_13F240;
  v7 = *(volatile uint8_t **)(v4 + 340);
  if ( result < 0 && !v7 )
    result = mmio_clear_register(dword_13F234, dword_13F230, 3326);
  if ( (uint8_t)v7[179] != a2 || (uint8_t)v7[180] != a3 )
  {
    v10 = *v3;
    v7[179] = a2;
    if ( *v10 < 0 && a2 > 3 )
    {
      result = mmio_clear_register(dword_13F23C, dword_13F230, 3332);
      v10 = *v3;
    }
    v7[180] = a3;
    if ( *v10 < 0 && a3 > 7 )
      result = mmio_clear_register(dword_13F238, dword_13F230, 3334);
    if ( (v7[166] & 0x20) != 0 )
      v7[166] |= 0x80u;
    else
      return ble_ll_conn_sm_get(a1);
  }
  return result;
}



// ble_ll_conn_sm_validate @ 0x13f244
int ble_ll_conn_sm_validate(int a1, int a2) {
  int result; // r0
  unsigned int v4; // r11
  char v6; // r3
  uint16_t v7; // r6
  unsigned int v8; // lr
  int v9; // r10
  unsigned int v10; // r5
  int v11; // r4
  unsigned int v12; // r0
  int v13; // r2
  unsigned int v14; // r3
  unsigned int v15; // r3
  int v16; // r2
  int v17; // r12
  unsigned int v18; // r3
  unsigned int v19; // r4
  uint32_t v20[11]; // [sp+0h] [bp-2Ch] BYREF

  result = dword_13F3AC;
  v4 = *(volatile uint32_t *)(dword_13F3AC + 696 * a1 + 340);
  if ( **(volatile int16_t **)off_13F3A8 < 0 && !v4 )
    result = mmio_clear_register(dword_13F3B4, dword_13F3B0, 3356);
  if ( *(volatile uint8_t *)(v4 + 182) == a2 )
    return result;
  *(volatile uint8_t *)(v4 + 182) = a2;
  if ( !a2 )
    return result;
  v6 = *(volatile uint8_t *)(v4 + 166);
  v7 = v6 & 0x20;
  if ( (v6 & 0x20) != 0 )
  {
    *(volatile uint8_t *)(v4 + 166) = v6 | 0x80;
    return result;
  }
  v8 = bt_state_handler(v4);
  *(volatile uint16_t *)(v4 + 184) = v8;
  if ( !v8 )
    goto LABEL_18;
  while ( 1 )
  {
    v9 = v7;
    v10 = v4 + 12 * v7;
    v11 = 2 * v7;
    v12 = *(volatile uint16_t *)(v10 + 10);
    v13 = (v12 >> 11) & 6;
    if ( (v12 & 0x2000) == 0 )
      break;
    v14 = v12 & 0xF;
    if ( !v13 )
      goto LABEL_10;
LABEL_21:
    ++v7;
    v19 = v4 + 4 * (v11 + v9);
    *(volatile uint8_t *)(v19 + 14) = 1;
    *(volatile uint16_t *)(v10 + 10) = v12;
    *(volatile uint16_t *)(v10 + 8) = 0;
    *(volatile uint8_t *)(v19 + 13) = 0;
    v20[v9] = 0;
    if ( v7 >= v8 )
      goto LABEL_18;
  }
  if ( ((v12 >> 11) & 6) != 0 )
    v14 = v12 & 7;
  else
    v14 = v12 & 0x7F;
  if ( v13 )
    goto LABEL_21;
LABEL_10:
  if ( v14 > 3 || (v12 & 0x400) != 0 )
    goto LABEL_21;
  v12 = (uint16_t)v12 | 0x400;
  if ( v8 )
  {
    do
    {
      v15 = v4;
      v16 = 0;
      while ( 1 )
      {
        v17 = *(volatile uint16_t *)(v15 + 10);
        ++v16;
        v15 += 12;
        if ( v17 == v12 )
          break;
        if ( v16 == v8 )
          goto LABEL_21;
      }
      v12 = rf_cal_channel_get(v4);
      v8 = *(volatile uint16_t *)(v4 + 184);
    }
    while ( *(volatile uint16_t *)(v4 + 184) );
  }
  v18 = v4 + 12 * v7;
  *(volatile uint8_t *)(v18 + 14) = 1;
  *(volatile uint16_t *)(v10 + 10) = v12;
  *(volatile uint16_t *)(v10 + 8) = v8;
  *(volatile uint8_t *)(v18 + 13) = v8;
  v20[v7] = v8;
LABEL_18:
  process_entry_list(v4, (int)v20);
  result = scan_process_list(v4, v20);
  *(volatile uint8_t *)(dword_13F3AC + 696 * a1 + 350) |= 1u;
  return result;
}



// ble_ll_conn_set_phy @ 0x13f3b8
int ble_ll_conn_set_phy(int result, unsigned int a2) {
  int v2; // r2
  volatile uint32_t *v3; // r4
  int v4; // r3

  if ( a2 > 3 )
    v2 = 0;
  else
    v2 = *(volatile uint16_t *)(result + 348) & 0x400;
  v3 = *(volatile uint32_t **)(result + 336);
  v4 = v2 | a2 | 0x20000000;
  v3[5] = v4;
  v3[6] = v4;
  v3[7] = v4;
  v3[8] = v4;
  return result;
}



// ble_ll_conn_ctrl_rx @ 0x13f3e4
BOOL ble_ll_conn_ctrl_rx(volatile uint8_t *a1, unsigned int a2) {
  unsigned int v2; // r3
  unsigned int v3; // r2
  unsigned int v4; // r4
  int v5; // r3
  int v7; // r5
  unsigned int v8; // r3

  v2 = a1[169];
  v3 = (a2 >> 11) & 7;
  v4 = a2 >> 11;
  if ( v2 >= v3 )
  {
    if ( v2 == 5 )
    {
      if ( ((a2 >> 11) & 5) != 5 && a1[177] > 3u )
        return 0;
    }
    else
    {
      if ( v2 == 4 )
      {
        if ( v3 != 4 )
          return 0;
        v7 = (a2 >> 11) & 6;
        if ( (v4 & 6) == 0 )
        {
LABEL_10:
          v5 = (a2 >> 10) & 1;
          if ( (a2 & 0x400) != 0 || a1[182] != 1 )
            return ll_pdu_dispatch((int)a1, a2) != 0;
          return v5;
        }
LABEL_27:
        if ( (a2 & 0x200) != 0 )
        {
          v5 = a1[181];
          if ( !a1[181] )
            return v5;
        }
        goto LABEL_18;
      }
      if ( v2 - 2 <= 1 )
      {
        v5 = (a2 >> 11) & 6;
        v7 = v5;
        if ( (v4 & 6) == 0 )
        {
          if ( a1[177] > 3u )
            return v5;
          goto LABEL_10;
        }
LABEL_26:
        if ( v3 > 4 )
          goto LABEL_18;
        goto LABEL_27;
      }
    }
    v7 = (a2 >> 11) & 6;
    if ( (v4 & 6) == 0 )
      goto LABEL_10;
    goto LABEL_26;
  }
  if ( v3 != 7 || v2 != 5 )
    return 0;
  v7 = (a2 >> 11) & 6;
  if ( (v4 & 6) == 0 )
    goto LABEL_10;
LABEL_18:
  if ( a1[179] < ((a2 >> 7) & 3) )
    return 0;
  if ( (v4 & 4) != 0 )
  {
    v8 = (a2 >> 4) & 7;
    goto LABEL_21;
  }
  if ( v7 )
  {
    v8 = (a2 >> 3) & 3;
LABEL_21:
    if ( a1[180] >= v8 )
      return ll_pdu_dispatch((int)a1, a2) != 0;
    return 0;
  }
  return ll_pdu_dispatch((int)a1, a2) != 0;
}



// ble_ll_sched_item_check @ 0x13f4b0
unsigned int ble_ll_sched_item_check(int a1, int a2, int a3) {
  int v3; // r1
  int v4; // r3
  unsigned int v5; // r6
  unsigned int v6; // r3
  int v8; // r1
  int v9; // r12
  int v10; // r7
  unsigned int v11; // r3
  unsigned int v12; // r2
  int v13; // r4
  unsigned int v14; // r4
  unsigned int result; // r0
  unsigned int v16; // r2

  v3 = 3 * a2;
  v4 = a1 + 4 * v3;
  v5 = *(volatile uint16_t *)(v4 + 8);
  if ( v5 <= 0x1998 )
    return 0;
  v6 = *(volatile uint16_t *)(v4 + 10);
  v8 = 4 * v3;
  v9 = (v6 >> 11) & 7;
  if ( (v6 & 0x2000) != 0 )
  {
    v10 = (v6 >> 11) & 6;
    v11 = v6 & 0xF;
    v12 = *(volatile uint32_t *)(a1 + 148);
    v13 = (uint8_t)v10;
    if ( v10 )
      goto LABEL_4;
  }
  else
  {
    if ( ((v6 >> 11) & 6) != 0 )
    {
      v12 = *(volatile uint32_t *)(a1 + 148);
      v14 = dword_13F5C0;
LABEL_6:
      v13 = v14 / HIWORD(v12);
      goto LABEL_7;
    }
    v12 = *(volatile uint32_t *)(a1 + 148);
    v11 = v6 & 0x7F;
    v13 = 0;
  }
  if ( v11 > 3 )
  {
LABEL_4:
    v14 = dword_13F5C0;
    if ( v9 == 6 )
      v14 = dword_13F5C4;
    goto LABEL_6;
  }
LABEL_7:
  result = (dword_13F5C8 * (1000 * v5 / (rx_header_parse(a1 + v8 + 4) + v13))) >> 16;
  if ( a3 )
  {
    if ( v5 <= 0x3332 )
    {
      return (uint64_t)(*(volatile uint8_t *)off_13F5CC * (uint64_t)result) >> 7;
    }
    else if ( v5 > 0x4CCB )
    {
      if ( v5 <= 0x6665 )
      {
        return (uint64_t)(*((volatile uint8_t *)off_13F5CC + 2) * (uint64_t)result) >> 7;
      }
      else if ( v5 >= 0x8000 )
      {
        if ( v5 > 0x9998 )
          v16 = *((volatile uint8_t *)off_13F5CC + 5);
        else
          v16 = *((volatile uint8_t *)off_13F5CC + 4);
        return (uint64_t)(v16 * (uint64_t)result) >> 7;
      }
      else
      {
        return (uint64_t)(*((volatile uint8_t *)off_13F5CC + 3) * (uint64_t)result) >> 7;
      }
    }
    else
    {
      return (uint64_t)(*((volatile uint8_t *)off_13F5CC + 1) * (uint64_t)result) >> 7;
    }
  }
  return result;
}



// ble_ll_conn_tx_pdu @ 0x13f5d0
int ble_ll_conn_tx_pdu(int a1, int a2) {
  volatile uint16_t *v2; // r5
  volatile uint16_t *v3; // r9
  volatile uint16_t *v5; // r2
  int v6; // r6
  volatile uint16_t *v7; // r7
  volatile uint16_t *v8; // r1
  int v9; // t1
  uint64_t v10; // r2
  int v11; // r1
  uint16_t v12; // r1
  int v13; // r3
  int v14; // r2
  volatile uint32_t *v15; // r1
  volatile uint32_t *v16; // r2
  int v17; // r3
  uint16_t v18; // r8
  int v19; // r11
  int v20; // r1
  unsigned int v21; // r0
  unsigned int v22; // r1
  int v23; // r3
  int v24; // r3
  int result; // r0
  int v26; // r3
  int v27; // t1
  int v28; // t1
  int v29; // r2
  struct __attribute__((packed)) { uint8_t v31[8]; // [sp+8h] [bp-34h] BYREF
  uint32_t v32[11]; // [sp+10h] [bp-2Ch] BYREF
  } _frame;
  v2 = (volatile uint16_t *)(a1 + 136);
  v3 = (volatile uint16_t *)_frame.v31;
  v5 = (volatile uint16_t *)(a1 + 136);
  v6 = a1;
  v7 = (volatile uint16_t *)(a1 + 144);
  v8 = (void *)(_frame.v31);
  do
  {
    v9 = *v5++;
    *v8++ = *(volatile uint16_t *)(a1 + 12 * v9 + 10);
  }
  while ( v5 != v7 );
  if ( *(volatile uint16_t *)(a1 + 146) )
  {
v10 = (v10 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(((unsigned int)((*(volatile uint16_t *)(a1 + 144) << 16) / *(volatile uint16_t *)(a1 + 146) + 3 * *(volatile uint32_t *)(a1 + 148)) >> 2) & 0x1FFFFFF) << 32);
    v10 = (v10 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
    *(volatile uint64_t *)(a1 + 144) = v10;
  }
  rx_desc_validate((volatile uint16_t *)(a1 + 124));
  v11 = *(volatile uint16_t *)(a1 + 184);
  if ( *(volatile uint16_t *)(a1 + 124) )
  {
    if ( !*(volatile uint16_t *)(a1 + 184) )
    {
LABEL_26:
      v29 = *(volatile uint16_t *)(a1 + 190);
      result = 0;
      *(volatile uint16_t *)(a1 + 124) = 0;
      *(volatile uint16_t *)(a1 + 126) = 0;
      if ( v29 != 0xFFFF )
        return tx_flag_check_process(a1);
      return result;
    }
    v12 = v11 - 1;
    v13 = a1;
    while ( 1 )
    {
      v14 = *(volatile uint16_t *)(v13 + 4);
      *(volatile uint8_t *)(v13 + 14) = 1;
      v13 += 12;
      if ( v14 )
        break;
      if ( v13 == a1 + 12 + 12 * v12 )
        goto LABEL_26;
    }
    *(volatile uint16_t *)(a1 + 124) = 0;
    *(volatile uint16_t *)(a1 + 126) = 0;
  }
  else
  {
    *(volatile uint16_t *)(a1 + 126) = 0;
    if ( !v11 )
    {
      if ( *(volatile uint16_t *)(a1 + 190) == 0xFFFF )
        goto LABEL_18;
LABEL_29:
      result = tx_flag_check_process(a1);
      goto LABEL_23;
    }
    v12 = v11 - 1;
  }
  v15 = &_frame.v32[v12 + 1];
  v16 = _frame.v32;
  v17 = a1;
  do
  {
    *v16++ = 0;
    *(volatile uint8_t *)(v17 + 14) = 1;
    v17 += 12;
  }
  while ( v16 != v15 );
  if ( *(volatile uint16_t *)(a1 + 190) != 0xFFFF )
    goto LABEL_29;
  v18 = 0;
  do
  {
    v19 = v18;
    rx_desc_validate((volatile uint16_t *)(a1 + 12 * v18 + 4));
    v20 = (uint8_t)v18++;
    v21 = ble_ll_sched_item_check(a1, v20, 1);
    v22 = *(volatile uint16_t *)(a1 + 184);
    _frame.v32[v19] = v21;
  }
  while ( v22 > v18 );
LABEL_18:
  process_entry_list(a1, (int)_frame.v32);
  scan_process_list(a1, _frame.v32);
  if ( !a2 )
  {
    v23 = *(volatile uint16_t *)(a1 + 184);
    *(volatile uint8_t *)(a1 + 166) |= 0x40u;
    if ( v23 )
    {
      v24 = a1 + 12 + 12 * (uint16_t)(v23 - 1);
      do
      {
        *(volatile uint16_t *)(v6 + 4) = a2;
        *(volatile uint16_t *)(v6 + 6) = a2;
        v6 += 12;
      }
      while ( v6 != v24 );
    }
  }
  result = 0;
LABEL_23:
  while ( 1 )
  {
    v27 = *v2++;
    v26 = v27;
    v28 = *v3++;
    if ( *(volatile uint16_t *)(a1 + 12 * v26 + 10) != v28 )
      break;
    if ( v2 == v7 )
      return result;
  }
  return 1;
}



