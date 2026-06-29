// sub_142B44 @ 0x142b44, size 412 bytes
int  sub_142B44(uint64_t a1, unsigned int a2, unsigned int a3)
{
  int v3; // r5
  unsigned int v4; // r12
  bool v5; // zf
  int v6; // r4
  int v7; // r4
  int v8; // r6
  int v9; // r1
  int v10; // r3
  bool v11; // zf
  int v12; // r3
  int v13; // r12
  unsigned int v14; // r5
  unsigned int v15; // lr
  unsigned int v16; // r2
  unsigned int v17; // lr
  unsigned uint64_t v18; // kr10_8
  unsigned int v19; // r5
  unsigned int v20; // r6
  int v21; // r4
  unsigned int v22; // off
  unsigned int v23; // lr
  bool v24; // cc
  bool v25; // cf
  int v26; // r4
  int v27; // r4
  int v28; // r4
  char v29; // r4
  char v30; // r4
  unsigned int v31; // r3
  char v32; // r4
  unsigned int v33; // r3
  int v34; // lr
  unsigned int v35; // r3

  v4 = 2047;
  v6 = (HIDWORD(a1) >> 20) & 0x7FF;
  v5 = v6 == 0;
  if ( v6 )
  {
    v3 = (a3 >> 20) & 0x7FF;
    v5 = v3 == 0;
  }
  if ( !v5 )
  {
    v5 = v6 == 0x7FF;
    if ( v6 != 0x7FF )
      v5 = v3 == 0x7FF;
  }
  if ( v5 )
    a1 = sub_142D20();
  v7 = v6 + v3;
  v8 = HIDWORD(a1) ^ a3;
  v9 = HIDWORD(a1) & ~(v4 << 21);
  v10 = a3 & ~(v4 << 21);
  v11 = ((unsigned int)a1 | (v9 << 12)) == 0;
  if ( (unsigned int)a1 | (v9 << 12) )
    v11 = (a2 | (v10 << 12)) == 0;
  HIDWORD(a1) = v9 | 0x100000;
  v12 = v10 | 0x100000;
  if ( v11 )
  {
    LODWORD(a1) = a1 | a2;
    HIDWORD(a1) = (v8 & 0x80000000 | HIDWORD(a1)) ^ v12;
    v24 = v7 <= (int)(v4 >> 1);
    v26 = v7 - (v4 >> 1);
    if ( !v24 && (int)v4 > v26 )
      return a1;
    HIDWORD(a1) |= 0x100000u;
    v23 = 0;
    v24 = v26 <= 1;
    v21 = v26 - 1;
  }
  else
  {
    v13 = a1 * a2;
    v14 = (HIDWORD(a1) * (unsigned uint64_t)a2 + (((unsigned int)a1 * (unsigned uint64_t)a2) >> 32)) >> 32;
    v15 = (a1 * (unsigned uint64_t)a2) >> 32;
    v16 = v8 & 0x80000000;
    v18 = (unsigned int)a1 * (unsigned uint64_t)(unsigned int)v12 + __PAIR64__(v14, v15);
    v17 = v18;
    v20 = (HIDWORD(a1) * (unsigned uint64_t)(unsigned int)v12 + HIDWORD(v18)) >> 32;
    v19 = HIDWORD(a1) * v12 + HIDWORD(v18);
    if ( v13 )
      v17 = v18 | 1;
    v21 = (__PAIR64__(v7 - 255, v20) - 0x30000000200LL) >> 32;
    if ( v20 < 0x200 )
    {
      v25 = __CFSHL__(v17, 1);
      v17 *= 2;
      v22 = v25 + v19;
      v25 = __CFADD__(v25, v19) | __CFADD__(v19, v22);
      v19 += v22;
      v20 += v25 + v20;
    }
    HIDWORD(a1) = v16 | (v20 << 11) | (v19 >> 21);
    LODWORD(a1) = (v19 << 11) | (v17 >> 21);
    v23 = v17 << 11;
    v24 = v21 <= 253;
    if ( (unsigned int)v21 > 0xFD )
      v24 = v21 - 253 <= 1792;
    if ( !v24 )
    {
      v25 = v23 >= 0x80000000;
      if ( v23 == 0x80000000 )
        v25 = a1 & 1;
      LODWORD(a1) = v25 + (uint32_t)a1;
      return a1;
    }
  }
  if ( !v24 )
    JUMPOUT(0x142D7C);
  if ( v21 > -54 )
  {
    v27 = -v21;
    v24 = v27 < 32;
    v28 = v27 - 32;
    if ( v24 )
    {
      v24 = v28 <= -12;
      v29 = v28 + 12;
      if ( v24 )
      {
        v30 = v29 + 20;
        v31 = (uint32_t)a1 << (32 - v30);
        LODWORD(a1) = (((unsigned int)a1 >> v30) | (HIDWORD(a1) << (32 - v30))) + (v31 >> 31);
        if ( !(v23 | (2 * v31)) )
          LODWORD(a1) = a1 & ~(v31 >> 31);
      }
      else
      {
        v32 = 12 - v29;
        v33 = (uint32_t)a1 << v32;
        LODWORD(a1) = (((unsigned int)a1 >> (32 - v32)) | (HIDWORD(a1) << v32)) + ((uint32_t)a1 << v32 >> 31);
        if ( !(v23 | (2 * v33)) )
          LODWORD(a1) = a1 & ~(v33 >> 31);
      }
    }
    else
    {
      v34 = v23 | ((uint32_t)a1 << (32 - v28));
      v35 = ((unsigned int)a1 >> v28) | (HIDWORD(a1) << (32 - v28));
      LODWORD(a1) = ((HIDWORD(a1) >> v28) & ~((HIDWORD(a1) & 0x80000000) >> v28)) + (v35 >> 31);
      if ( !(v34 | (2 * v35)) )
        LODWORD(a1) = a1 & ~(v35 >> 31);
    }
  }
  else
  {
    LODWORD(a1) = 0;
  }
  return a1;
}

