// sub_11B1A4 @ 0x11b1a4, size 256 bytes
int  sub_11B1A4(int result)
{
  uint8_t *v1; // r4
  int v2; // r5
  int v3; // r6
  int v4; // r7
  char v5; // r3
  int v6; // r9
  int v7; // r7
  int v8; // r8
  int v9; // r6
  int v10; // r10
  int v11; // r0
  int v12; // r3

  v1 = off_11B2AC;
  v2 = result;
  v3 = *((uint32_t *)off_11B2A4 + 4) + *(uint32_t *)(result + 20);
  if ( result != dword_11B2A8 || (*((uint8_t *)off_11B2AC + 88) & 4) != 0 )
  {
    if ( *((uint32_t *)off_11B2AC + 10) != result )
    {
      result = sub_101A20();
      v3 += 4000 + result;
    }
    v4 = (unsigned __int8)v1[91];
    v5 = v1[88];
    *((uint32_t *)v1 + 20) = v2;
    *((uint32_t *)v1 + 21) = v3;
    if ( v4 )
    {
      v1[88] = v5 | 0x40;
    }
    else
    {
      v1[88] = v5 & 0xBF;
      sub_11B044();
      result = sub_11AF78(v3, 0, 0);
      v6 = *((uint32_t *)v1 + 4);
      if ( v6 )
      {
        v7 = dword_11B2B4;
        v8 = dword_11B2C4;
        v9 = dword_11B2B0 - v3;
        do
        {
          v10 = *(uint32_t *)(v6 + 4);
          result = v10 - sub_101A20();
          if ( result + v9 >= 0 )
            break;
          v11 = v7 + 224 * *(unsigned __int8 *)(v6 + 8);
          v12 = 102400;
          if ( !*(uint8_t *)(v11 + 94) )
            v12 = *(uint32_t *)(v8 + 152 * *(unsigned __int8 *)(v11 + 102) + 8);
          result = sub_11AE24(v11, *(uint32_t *)(v6 + 4) + v12, 0);
          v6 = *((uint32_t *)v1 + 4);
        }
        while ( v6 );
      }
      if ( *((uint32_t *)v1 + 11) )
      {
        if ( **(__int16 **)off_11B2B8 < 0 && (v1[88] & 0xC) == 0 )
          return sub_1219C4(dword_11B2C0, dword_11B2BC, 1698);
      }
      else
      {
        return sub_11ADD0(v2);
      }
    }
  }
  else
  {
    *((uint8_t *)off_11B2AC + 88) &= ~0x40u;
  }
  return result;
}

