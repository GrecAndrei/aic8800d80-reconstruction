// sub_12815C @ 0x12815c, size 300 bytes
int  sub_12815C(int result)
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

  v1 = off_128288;
  v2 = result;
  v3 = *(unsigned __int8 *)(result + 85);
  if ( *((unsigned __int8 *)off_128288 + 90) <= 1u )
  {
    result = v3 << 30;
    if ( (v3 & 2) != 0 )
    {
      LOBYTE(v3) = v3 & 0xFD;
      *(uint8_t *)(v2 + 85) = v3;
      v11 = *((uint8_t *)v1 + 91) - 1;
      *((uint8_t *)v1 + 91) = v11;
      if ( !v11 && (*((uint8_t *)v1 + 88) & 0x40) != 0 )
      {
        result = sub_127030(*((uint32_t *)v1 + 20));
        LOBYTE(v3) = *(uint8_t *)(v2 + 85);
      }
    }
    if ( (v3 & 4) != 0 )
    {
      LOBYTE(v3) = v3 & 0xFB;
      *(uint8_t *)(v2 + 85) = v3;
    }
    if ( (v3 & 0x20) != 0 )
      *(uint8_t *)(v2 + 85) = v3 & 0xDF;
  }
  else
  {
    if ( (v3 & 0x20) != 0 )
    {
      result = sub_1277B0(result);
      LOBYTE(v3) = *(uint8_t *)(v2 + 85);
      v5 = *(uint32_t *)(v2 + 36);
      v4 = v3 & 4;
      if ( (v3 & 4) == 0 )
      {
LABEL_4:
        if ( (v3 & 2) != 0 )
        {
          v6 = v3 & 0xFD;
          *(uint8_t *)(v2 + 85) = v6;
          v7 = *((uint8_t *)v1 + 91) - 1;
          *((uint8_t *)v1 + 91) = v7;
          if ( !v7 )
          {
            if ( (*((uint8_t *)v1 + 88) & 0x40) != 0 )
            {
              result = sub_127030(*((uint32_t *)v1 + 20));
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
            v9 = *(unsigned __int8 *)(v2 + 106);
            *(uint8_t *)(v2 + 85) = v6 & 0xF7;
            if ( v9 )
            {
              if ( v9 == 2 )
                v10 = *(unsigned __int16 *)(v2 + 222);
              else
                v10 = 102400;
              if ( v9 == 2 )
                v10 <<= 10;
            }
            else
            {
              v10 = *(uint32_t *)(dword_128290 + 696 * *(unsigned __int8 *)(v2 + 116) + 8);
            }
            v8 -= v10;
          }
          else
          {
            result = sub_126444(v2, v5, 0);
          }
          if ( v4 )
          {
            if ( !*((uint32_t *)v1 + 11) )
              return sub_1266E4(v2, *((uint32_t *)off_12828C + 4), *((uint32_t *)off_12828C + 4) - v8);
          }
        }
        return result;
      }
    }
    else
    {
      v4 = v3 & 4;
      v5 = *(uint32_t *)(result + 36);
      if ( (v3 & 4) == 0 )
        goto LABEL_4;
    }
    if ( (v3 & 1) == 0 )
    {
      result = sub_126444(v2, v5, 0);
      LOBYTE(v3) = *(uint8_t *)(v2 + 85);
    }
    *(uint8_t *)(v2 + 85) = v3 & 0xFB;
  }
  return result;
}

