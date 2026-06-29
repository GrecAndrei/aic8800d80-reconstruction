// sub_13CBEC @ 0x13cbec, size 630 bytes
uint64_t  sub_13CBEC(int a1, uint16_t *a2, int a3, int a4, int a5)
{
  char *v9; // r6
  int v10; // r5
  __int16 *v11; // r4
  signed int v12; // r5
  unsigned uint64_t v13; // kr00_8
  unsigned int v14; // r2
  unsigned int v15; // r6
  int v16; // lr
  int v17; // r7
  char *v18; // r1
  int v19; // r9
  int v20; // t1
  unsigned int v21; // r12
  int *v22; // r7
  uint32_t *v23; // r8
  int v24; // r10
  int v25; // r6
  __int16 *v26; // r2
  uint64_t *v27; // r3
  int v28; // t1
  signed int v29; // r3
  int v30; // r3
  uint64_t *v31; // r9
  uint8_t *v32; // r3
  uint8_t *v33; // r5
  int v34; // r4
  int v35; // r5
  uint64_t *v36; // r3
  uint32_t v37[3]; // [sp+4h] [bp-110h] BYREF
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
  __int16 v50; // [sp+4Ch] [bp-C8h] BYREF
  uint8_t v51[18]; // [sp+4Eh] [bp-C6h] BYREF
  QWORD v52[18]; // [sp+60h] [bp-B4h] BYREF
  char v53; // [sp+F0h] [bp-24h] BYREF

  if ( a3 <= 23 )
  {
    if ( **(__int16 **)off_13CE64 < 0 )
      sub_12F49C(dword_13CE70, dword_13CE6C, 430);
    return 0;
  }
  v50 = *a2 & 0xC7FF;
  v9 = (char *)a2 + a4;
  sub_143770(v51, a2 + 2, 18);
  v10 = a3 - a4;
  v38 = 20;
  v39 = v10;
  v11 = &v50;
  v37[0] = &v50;
  v37[1] = v9;
  if ( a5 )
  {
    v37[2] = a5;
    v12 = v10 + 38;
    v40 = 18;
  }
  else
  {
    v39 = v10 + 18;
    v12 = v10 + 38;
  }
  v13 = *(QWORD *)(a1 + 80);
  v14 = *(uint32_t *)(a1 + 92);
  v15 = *(uint32_t *)(a1 + 88);
  v52[0] = v13;
  v52[1] = __PAIR64__(v14, v15);
  v16 = dword_13CE74;
  v17 = dword_13CE68;
  v18 = (char *)v52;
  v19 = 1;
  while ( 1 )
  {
    v21 = v13
        ^ (*(unsigned __int8 *)(v17 + BYTE1(v14)) ^ v19
         | (*(unsigned __int8 *)(v17 + (unsigned __int8)v14) << 24)
         | (*(unsigned __int8 *)(v17 + HIBYTE(v14)) << 16)
         | (*(unsigned __int8 *)(v17 + BYTE2(v14)) << 8));
    v15 ^= HIDWORD(v13) ^ v21;
    v14 ^= v15;
    *((uint32_t *)v18 + 6) = v15;
    *((uint32_t *)v18 + 7) = v14;
    *((uint32_t *)v18 + 4) = v21;
    *((uint32_t *)v18 + 5) = HIDWORD(v13) ^ v21;
    v13 = __PAIR64__(HIDWORD(v13) ^ v21, v21);
    if ( &v53 == v18 )
      break;
    v20 = *(uint32_t *)(v16 + 4);
    v16 += 4;
    v19 = v20;
    v18 += 16;
  }
  memset_thunk((int *)&v44, 0, 0x10u);
  memset_thunk((int *)&v47, 0, 0x10u);
  if ( v12 > 16 )
  {
    v22 = &v38;
    v23 = v37;
    v24 = v12;
    v25 = 20;
    do
    {
      if ( v25 <= 16 )
      {
        v36 = &v41;
        do
        {
          *(uint8_t *)v36 = *(uint8_t *)v11;
          v36 = (uint64_t *)((char *)v36 + 1);
          if ( --v25 )
          {
            v11 = (__int16 *)((char *)v11 + 1);
          }
          else
          {
            v11 = (__int16 *)v23[1];
            v25 = v22[1];
            ++v23;
            ++v22;
          }
        }
        while ( v36 != &v44 );
      }
      else
      {
        v26 = v11 + 8;
        v27 = &v41;
        do
        {
          v28 = *(uint32_t *)v11;
          v11 += 2;
          *(uint32_t *)v27 = v28;
          v27 = (uint64_t *)((char *)v27 + 4);
        }
        while ( v11 != v26 );
        v25 -= 16;
      }
      v44 ^= v41;
      v45 ^= v42;
      v24 -= 16;
      v46 ^= v43;
      sub_13C7D4(v52, &v44);
    }
    while ( v24 > 16 );
    v12 = v12 - 16 - ((v12 - 17) & 0xFFFFFFF0);
    sub_13C7D4(v52, &v47);
    sub_13CB7C((unsigned int *)&v47);
LABEL_18:
    v29 = 0;
    do
    {
      while ( 1 )
      {
        *((uint8_t *)&v41 + v29) = *(uint8_t *)v11;
        if ( !--v25 )
          break;
        ++v29;
        v11 = (__int16 *)((char *)v11 + 1);
        if ( v12 <= v29 )
          goto LABEL_22;
      }
      ++v29;
      v11 = (__int16 *)v23[1];
      v25 = v22[1];
      ++v23;
      ++v22;
    }
    while ( v12 > v29 );
LABEL_22:
    v30 = v12 - 1;
    if ( v12 <= 0 )
      v30 = 0;
    v31 = (uint64_t *)((char *)&v41 + v30 + 1);
    goto LABEL_25;
  }
  sub_13C7D4(v52, &v47);
  sub_13CB7C((unsigned int *)&v47);
  v31 = &v41;
  if ( v12 > 0 )
  {
    v22 = &v38;
    v23 = v37;
    v25 = 20;
    goto LABEL_18;
  }
LABEL_25:
  if ( v12 != 16 )
  {
    *(uint8_t *)v31 = 0x80;
    v32 = (char *)v31 + 1;
    if ( v12 != 15 )
    {
      v33 = (char *)v31 - v12 + 16;
      do
        *v32++ = 0;
      while ( v32 != v33 );
    }
    sub_13CB7C((unsigned int *)&v47);
  }
  v47 ^= v41;
  v44 ^= v47;
  v34 = v46 ^ v49 ^ v43;
  v35 = v45 ^ v48 ^ v42;
  v48 ^= v42;
  v45 = v35;
  v49 ^= v43;
  v46 = v34;
  sub_13C7D4(v52, &v44);
  return v44;
}

