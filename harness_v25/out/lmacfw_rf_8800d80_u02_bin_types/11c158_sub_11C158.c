// sub_11C158 @ 0x11c158, size 264 bytes
int  sub_11C158(int result)
{
  void *v1; // r5
  int v2; // r4
  int v3; // r3
  int v4; // r6
  int v5; // r7
  char v6; // r3
  char v7; // r2
  int v8; // r8
  int v9; // r2
  int v10; // r3
  char v11; // r2

  v1 = off_11C260;
  v2 = result;
  v3 = *(unsigned __int8 *)(result + 85);
  if ( *((unsigned __int8 *)off_11C260 + 90) <= 1u )
  {
    if ( (v3 & 2) != 0 )
    {
      v3 &= 0xFDu;
      *(uint8_t *)(result + 85) = v3;
      v11 = *((uint8_t *)v1 + 91) - 1;
      *((uint8_t *)v1 + 91) = v11;
      if ( !v11 && (*((uint8_t *)v1 + 88) & 0x40) != 0 )
      {
        sub_11B1A4(*((uint32_t *)v1 + 20));
        v3 = *(unsigned __int8 *)(v2 + 85);
      }
    }
    if ( (v3 & 4) != 0 )
    {
      v3 &= 0xFBu;
      *(uint8_t *)(v2 + 85) = v3;
    }
    result = v3 << 26;
    if ( (v3 & 0x20) != 0 )
      *(uint8_t *)(v2 + 85) = v3 & 0xDF;
  }
  else
  {
    v4 = v3 & 4;
    v5 = *(uint32_t *)(result + 36);
    if ( (v3 & 4) != 0 )
    {
      if ( (v3 & 1) == 0 )
      {
        result = sub_11AE24(result, *(uint32_t *)(result + 36), 0);
        LOBYTE(v3) = *(uint8_t *)(v2 + 85);
      }
      *(uint8_t *)(v2 + 85) = v3 & 0xFB;
    }
    else if ( (v3 & 2) != 0 )
    {
      v6 = v3 & 0xFD;
      *(uint8_t *)(result + 85) = v6;
      v7 = *((uint8_t *)v1 + 91) - 1;
      *((uint8_t *)v1 + 91) = v7;
      if ( !v7 )
      {
        if ( (*((uint8_t *)v1 + 88) & 0x40) != 0 )
        {
          result = sub_11B1A4(*((uint32_t *)v1 + 20));
          v6 = *(uint8_t *)(v2 + 85);
        }
        else
        {
          v4 = 1;
        }
      }
      v8 = *(uint32_t *)(v2 + 80);
      if ( (v6 & 8) != 0 )
      {
        v9 = *(unsigned __int8 *)(v2 + 94);
        *(uint8_t *)(v2 + 85) = v6 & 0xF7;
        if ( v9 )
          v10 = 102400;
        else
          v10 = *(uint32_t *)(dword_11C268 + 152 * *(unsigned __int8 *)(v2 + 102) + 8);
        v8 -= v10;
      }
      else
      {
        result = sub_11AE24(v2, v5, 0);
      }
      if ( v4 )
      {
        if ( !*((uint32_t *)v1 + 11) )
          return sub_11B088(v2, *((uint32_t *)off_11C264 + 4), *((uint32_t *)off_11C264 + 4) - v8);
      }
    }
  }
  return result;
}

