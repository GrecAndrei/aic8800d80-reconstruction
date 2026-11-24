// sub_13F480 @ 0x13f480, size 204 bytes
BOOL __fastcall sub_13F480(unsigned __int8 *a1, unsigned int a2)
{
  unsigned int v2; // r3
  unsigned int v3; // r2
  unsigned int v4; // r4
  int v5; // r3
  int v7; // r5
  unsigned int v8; // r3

  v2 = *(_DWORD *)(a1 + 0x2a4);
  v3 = (a2 >> 11) & 7;
  v4 = a2 >> 11;
  if ( v2 >= v3 )
  {
    if ( v2 == 5 )
    {
      if ( ((a2 >> 11) & 5) != 5 && *(_DWORD *)(a1 + 0x2c4) > 3u )
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
          if ( (a2 & 0x400) != 0 || *(_DWORD *)(a1 + 0x2d8) != 1 )
            return sub_13D2F8((int)a1, a2) != 0;
          return v5;
        }
LABEL_27:
        if ( (a2 & 0x200) != 0 )
        {
          v5 = *(_DWORD *)(a1 + 0x2d4);
          if ( !*(_DWORD *)(a1 + 0x2d4) )
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
          if ( *(_DWORD *)(a1 + 0x2c4) > 3u )
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
  if ( *(_DWORD *)(a1 + 0x2cc) < ((a2 >> 7) & 3) )
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
    if ( *(_DWORD *)(a1 + 0x2d0) >= v8 )
      return sub_13D2F8((int)a1, a2) != 0;
    return 0;
  }
  return sub_13D2F8((int)a1, a2) != 0;
}

