// sub_14273C @ 0x14273c, size 630 bytes
int __fastcall sub_14273C(__int64 a1, __int64 a2)
{
  int v2; // r4
  int v3; // r5
  bool v4; // zf
  int v5; // r4
  bool v6; // vf
  char v7; // cc
  int v8; // r5
  __int64 v9; // r2
  int v10; // r4
  char v11; // lr
  unsigned int v12; // r12
  __int64 v13; // r0
  bool v14; // nf
  char v15; // r5
  int v16; // r3
  _BOOL1 v17; // off
  _BOOL1 v18; // cf
  int v19; // off
  int v20; // r4
  bool v21; // zf
  unsigned int v22; // r3
  int v23; // r3
  bool v24; // cc
  int v25; // r2
  unsigned int v26; // r12
  int v27; // r4
  int v28; // r4
  char v29; // r4
  bool v30; // zf
  bool v31; // zf

  v2 = 2 * HIDWORD(a1);
  v3 = 2 * HIDWORD(a2);
  v4 = 2 * HIDWORD(a1) == 2 * HIDWORD(a2);
  if ( 2 * HIDWORD(a1) == 2 * HIDWORD(a2) )
    v4 = (unsigned int)a1 == (unsigned int)a2;
  if ( !v4 )
  {
    v4 = (v2 | (unsigned int)a1) == 0;
    if ( v2 | (unsigned int)a1 )
    {
      v4 = (v3 | (unsigned int)a2) == 0;
      if ( v3 | (unsigned int)a2 )
      {
        v4 = v2 >> 21 == -1;
        if ( v2 >> 21 != -1 )
          v4 = v3 >> 21 == -1;
      }
    }
  }
  if ( v4 )
  {
    v30 = v2 >> 21 == -1;
    if ( v2 >> 21 != -1 )
      v30 = v3 >> 21 == -1;
    if ( v30 )
    {
      if ( v2 >> 21 != -1 )
        return a2;
    }
    else
    {
      v31 = v2 == v3;
      if ( v2 == v3 )
        v31 = (unsigned int)a1 == (unsigned int)a2;
      if ( v31 )
      {
        if ( HIDWORD(a1) != HIDWORD(a2) )
        {
          LODWORD(a1) = 0;
          return a1;
        }
        if ( !((unsigned int)v2 >> 21) )
        {
          LODWORD(a1) = 2 * a1;
          return a1;
        }
        if ( (unsigned int)v2 < 0xFFC00000 )
          return a1;
        goto LABEL_69;
      }
      if ( !(v2 | (unsigned int)a1) )
        LODWORD(a1) = a2;
    }
  }
  else
  {
    v5 = (unsigned int)v2 >> 21;
    v6 = __OFSUB__((unsigned int)v3 >> 21, v5);
    v8 = ((unsigned int)v3 >> 21) - v5;
    v7 = (v8 < 0) ^ v6 | (v8 == 0);
    if ( v8 < 0 != v6 )
      v8 = -v8;
    if ( !v7 )
    {
      v5 += v8;
      v9 = a1 ^ a2;
      a1 ^= v9;
      a2 = a1 ^ v9;
    }
    if ( (unsigned int)v8 <= 0x36 )
    {
      v4 = a1 >= 0;
      HIDWORD(a1) = HIDWORD(a1) & 0xFFFFF | 0x100000;
      if ( !v4 )
      {
        v18 = (_DWORD)a1 == 0;
        LODWORD(a1) = -(int)a1;
        HIDWORD(a1) -= 2 * HIDWORD(a1) + !v18;
      }
      v4 = a2 >= 0;
      HIDWORD(a2) = HIDWORD(a2) & 0xFFFFF | 0x100000;
      if ( !v4 )
      {
        v18 = (_DWORD)a2 == 0;
        LODWORD(a2) = -(int)a2;
        HIDWORD(a2) -= 2 * HIDWORD(a2) + !v18;
      }
      if ( v5 == v8 )
      {
        HIDWORD(a2) ^= 0x100000u;
        if ( v5 )
        {
          --v8;
        }
        else
        {
          HIDWORD(a1) ^= 0x100000u;
          v5 = 1;
        }
      }
      v10 = v5 - 1;
      v11 = 32 - v8;
      if ( v8 > 32 )
      {
        v15 = v8 - 32;
        v12 = HIDWORD(a2) << (v11 + 32);
        if ( (_DWORD)a2 )
          v12 |= 2u;
        v16 = SHIDWORD(a2) >> v15;
        LODWORD(a1) = a1 + v16;
        HIDWORD(a1) += (v16 >> 31) + __CFSHR__(v16, 31);
        v14 = a1 < 0;
      }
      else
      {
        v12 = (_DWORD)a2 << v11;
        v13 = a1 + ((unsigned int)a2 >> v8);
        LODWORD(a2) = HIDWORD(a2) << v11;
        SHIDWORD(a2) >>= v8;
        a1 = v13 + a2;
        v14 = a1 < 0;
      }
      if ( v14 )
      {
        v18 = v12 == 0;
        v12 = -v12;
        v17 = v18;
        v18 = __CFSUB__(0, (_DWORD)a1, v18);
        LODWORD(a1) = -(a1 + !v17);
        HIDWORD(a1) = -(HIDWORD(a1) + !v18);
      }
      if ( HIDWORD(a1) >= 0x100000 )
      {
        if ( HIDWORD(a1) < 0x200000
          || (v18 = a1 & 1,
              LODWORD(a1) = a1 >> 1,
              v12 = (v12 >> 1) | (v18 << 31),
              (unsigned int)((v10 + 1) << 21) < 0xFFC00000) )
        {
LABEL_30:
          v18 = v12 >= 0x80000000;
          if ( v12 == 0x80000000 )
            v18 = a1 & 1;
          LODWORD(a1) = v18 + (_DWORD)a1;
          return a1;
        }
LABEL_69:
        LODWORD(a1) = 0;
        return a1;
      }
      v18 = __CFSHL__(v12, 1);
      v12 *= 2;
      v19 = v18 + (_DWORD)a1;
      v18 = __CFADD__(v18, (_DWORD)a1) | __CFADD__((_DWORD)a1, v19);
      LODWORD(a1) = a1 + v19;
      HIDWORD(a1) += v18 + HIDWORD(a1);
      v18 = v10 != 0;
      v20 = v10 - 1;
      if ( v18 && HIDWORD(a1) >= 0x100000 )
        goto LABEL_30;
      v21 = HIDWORD(a1) == 0;
      if ( !HIDWORD(a1) )
      {
        HIDWORD(a1) = a1;
        LODWORD(a1) = 0;
      }
      v22 = __clz(HIDWORD(a1));
      if ( v21 )
        v22 += 32;
      v23 = v22 - 11;
      v25 = v23 - 32;
      v24 = v23 <= 32;
      if ( v23 < 32 )
      {
        v24 = v25 <= -12;
        if ( v25 > -12 )
        {
          LODWORD(a1) = HIDWORD(a1) << v23;
          HIDWORD(a1) >>= 32 - v23;
LABEL_47:
          v7 = v20 < v23;
          v27 = v20 - v23;
          if ( v7 )
          {
            v28 = ~v27;
            v7 = v28 < 31;
            v29 = v28 - 31;
            if ( v7 )
              LODWORD(a1) = ((unsigned int)a1 >> (v29 + 32)) | (HIDWORD(a1) << -v29);
            else
              LODWORD(a1) = HIDWORD(a1) >> v29;
          }
          return a1;
        }
        LOBYTE(v25) = v23;
      }
      if ( v24 )
        LOBYTE(v12) = 32 - v25;
      HIDWORD(a1) <<= v25;
      v26 = (unsigned int)a1 >> v12;
      if ( v24 )
      {
        HIDWORD(a1) |= v26;
        LODWORD(a1) = (_DWORD)a1 << v25;
      }
      goto LABEL_47;
    }
  }
  return a1;
}

