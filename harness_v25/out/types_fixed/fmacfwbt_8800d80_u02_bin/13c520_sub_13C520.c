// sub_13C520 @ 0x13c520, size 146 bytes
BOOL __fastcall sub_13C520(char a1, unsigned int a2)
{
  int v2; // r3

  if ( (a1 & 0xC) != 0 )
    return 0;
  v2 = a1 & 0xF0;
  if ( v2 == 192 )
    return 1;
  if ( v2 != 208 )
    return v2 == 160;
  if ( a2 <= 0x16 )
  {
    if ( a2 > 3 )
    {
      switch ( a2 )
      {
        case 4u:
        case 7u:
        case 0xBu:
        case 0xFu:
        case 0x16u:
          return 0;
        default:
          return 1;
      }
    }
    return 1;
  }
  return a2 != 127;
}

