// sub_129B58 @ 0x129b58, size 182 bytes
unsigned int  sub_129B58(int a1, int a2, unsigned int a3, unsigned int a4)
{
  unsigned int v4; // r6
  int v6; // r7
  unsigned int v7; // r5
  unsigned int v8; // r3
  unsigned int v9; // r5
  __int16 **v10; // r3
  uint32_t *v11; // r2
  unsigned int v12; // r3
  unsigned int result; // r0
  uint32_t *v14; // r1

  v4 = a3;
  v6 = dword_129C10 + 1320 * a2;
  if ( a4 < a3 )
  {
    v9 = 0;
  }
  else
  {
    if ( *(uint8_t *)(a1 + 19) == 1 )
      return 0;
    v7 = *(uint32_t *)(a1 + 28);
    v8 = (a4 - a3) / v7;
    v4 = a3 + v7 + v8 * v7;
    v9 = v8 + 1;
  }
  v10 = (__int16 **)off_129C14;
  *(uint32_t *)(a1 + 44) = v4;
  if ( **v10 < 0 && *(uint8_t *)(v6 + 106) )
    sub_12F32C(dword_129C24, dword_129C20, 98);
  v11 = off_129C1C;
  v12 = *(unsigned __int8 *)(a1 + 19);
  result = *((uint32_t *)off_129C1C + 4) - *(uint32_t *)off_129C18 - *(uint32_t *)(v6 + 132) + v4;
  if ( v12 == 255 )
  {
    if ( (int)(result - *((uint32_t *)off_129C1C + 4)) < 0 )
      goto LABEL_10;
    return result;
  }
  if ( v12 > v9 )
    LOBYTE(v12) = v12 - v9;
  else
    LOBYTE(v12) = 0;
  v12 = (unsigned __int8)v12;
  *(uint8_t *)(a1 + 19) = v12;
  if ( (int)(result - v11[4]) < 0 )
  {
LABEL_10:
    v14 = off_129C1C;
    while ( v12 )
    {
      while ( 1 )
      {
        result += *(uint32_t *)(a1 + 28);
        if ( v12 != 255 )
          break;
        if ( (int)(result - v14[4]) >= 0 )
          return result;
      }
      v12 = (unsigned __int8)(v12 - 1);
      *(uint8_t *)(a1 + 19) = v12;
      if ( (int)(result - v14[4]) >= 0 )
        goto LABEL_14;
    }
    return 0;
  }
LABEL_14:
  if ( !v12 )
    return 0;
  return result;
}

