// sub_13F370 @ 0x13f370, size 272 bytes
unsigned int  sub_13F370(int a1, int a2, int a3)
{
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
  v5 = *(unsigned __int16 *)(v4 + 8);
  if ( v5 <= 0x1998 )
    return 0;
  v6 = *(unsigned __int16 *)(v4 + 10);
  v8 = 4 * v3;
  v9 = (v6 >> 11) & 7;
  if ( (v6 & 0x2000) != 0 )
  {
    v10 = (v6 >> 11) & 6;
    v11 = v6 & 0xF;
    v12 = *(uint32_t *)(a1 + 148);
    v13 = (unsigned __int8)v10;
    if ( v10 )
      goto LABEL_4;
  }
  else
  {
    if ( ((v6 >> 11) & 6) != 0 )
    {
      v12 = *(uint32_t *)(a1 + 148);
      v14 = dword_13F480;
LABEL_6:
      v13 = v14 / HIWORD(v12);
      goto LABEL_7;
    }
    v12 = *(uint32_t *)(a1 + 148);
    v11 = v6 & 0x7F;
    v13 = 0;
  }
  if ( v11 > 3 )
  {
LABEL_4:
    v14 = dword_13F480;
    if ( v9 == 6 )
      v14 = dword_13F484;
    goto LABEL_6;
  }
LABEL_7:
  result = (dword_13F488 * (1000 * v5 / (sub_13E9E0(a1 + v8 + 4) + v13))) >> 16;
  if ( a3 )
  {
    if ( v5 <= 0x3332 )
    {
      return (uint64_t)(*(unsigned __int8 *)off_13F48C * (unsigned uint64_t)result) >> 7;
    }
    else if ( v5 > 0x4CCB )
    {
      if ( v5 <= 0x6665 )
      {
        return (uint64_t)(*((unsigned __int8 *)off_13F48C + 2) * (unsigned uint64_t)result) >> 7;
      }
      else if ( v5 >= 0x8000 )
      {
        if ( v5 > 0x9998 )
          v16 = *((unsigned __int8 *)off_13F48C + 5);
        else
          v16 = *((unsigned __int8 *)off_13F48C + 4);
        return (uint64_t)(v16 * (unsigned uint64_t)result) >> 7;
      }
      else
      {
        return (uint64_t)(*((unsigned __int8 *)off_13F48C + 3) * (unsigned uint64_t)result) >> 7;
      }
    }
    else
    {
      return (uint64_t)(*((unsigned __int8 *)off_13F48C + 1) * (unsigned uint64_t)result) >> 7;
    }
  }
  return result;
}

