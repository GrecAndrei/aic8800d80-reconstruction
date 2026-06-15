// sub_13CE78 @ 0x13ce78, size 374 bytes
unsigned int __fastcall sub_13CE78(int a1, unsigned int a2)
{
  unsigned int v2; // r2
  bool v3; // nf
  unsigned int v5; // r3
  unsigned int v6; // r4
  bool v7; // cf
  unsigned int v8; // r3
  unsigned int v9; // r3
  bool v10; // cc
  unsigned __int16 v11; // r3

  if ( (a2 & 0x2000) != 0 )
  {
    v2 = a2 & 0xF;
    switch ( (a2 >> 11) & 7 )
    {
      case 4u:
        if ( *(unsigned __int8 *)(a1 + 176) > v2
          && (((int)*(unsigned __int16 *)(a1 + 170) >> (2 * ((a2 >> 4) & 7))) & 3u) + 7 > v2 )
        {
          a2 = a2 & 0xFFF0 | (unsigned __int16)(v2 + 1);
          if ( *(_BYTE *)(a1 + 181) )
            a2 |= 0x200u;
        }
        return a2;
      case 5u:
        if ( *(unsigned __int8 *)(a1 + 176) > v2
          && 2 * (((int)*(unsigned __int16 *)(a1 + 170) >> (2 * ((a2 >> 4) & 7))) & 3u) + 7 > v2 )
        {
          v3 = ((v2 + 1) & 0x4000 | a2 & 0x4000) != 0;
          a2 = (unsigned __int16)((v2 + 1) | a2 & 0xFFF0);
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
          a2 = (unsigned __int16)((v2 + 1) | a2 & 0xFFF0);
          if ( v3 && (v2 == 1 || !*(_BYTE *)(a1 + 195)) )
            return a2 & 0xBFFF;
          return a2;
        }
        v11 = a2 & 0xFFF0 | (v2 + 1) & 0xFFF0 | 5;
        a2 = v11;
        if ( (v11 & 0x4000) != 0 )
        {
LABEL_29:
          if ( *(unsigned __int8 *)(a1 + 195) <= v2 )
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
      v10 = *(unsigned __int8 *)(a1 + 176) > v9;
      v9 = (unsigned __int8)(v9 + 1);
      if ( !v10 )
        break;
      if ( ((*(unsigned __int8 *)(((a2 >> 3) & 3) + a1 + 170) >> v9) & 1) != 0 )
      {
        a2 = a2 & 0xFFFFFFF8 | v9;
        if ( *(_BYTE *)(a1 + 181) )
          return (unsigned __int16)a2 | 0x200;
        return a2;
      }
    }
  }
  else
  {
    v5 = a2 & 0x7F;
    if ( (a2 & 0x7C) != 0 )
    {
      v6 = *(unsigned __int8 *)(a1 + 178);
    }
    else
    {
      v6 = *(unsigned __int8 *)(a1 + 178);
      if ( v6 >= 3 )
        v6 = 3;
    }
    while ( 1 )
    {
      v7 = v5 >= v6;
      v5 = (unsigned __int8)(v5 + 1);
      if ( v7 )
        break;
      if ( ((*(unsigned __int16 *)(a1 + 174) >> v5) & 1) != 0 )
        return a2 & 0xFFFFFF80 | v5;
    }
    v8 = *(unsigned __int8 *)(a1 + 169);
    if ( v8 > 1 )
      return (unsigned __int16)((_WORD)v8 << 11);
  }
  return a2;
}

