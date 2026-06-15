// sub_11B0D0 @ 0x11b0d0, size 132 bytes
unsigned int *__fastcall sub_11B0D0(unsigned int *result, unsigned int a2, int a3)
{
  unsigned int v3; // r3
  int v4; // r4
  unsigned int v5; // r2
  int v6; // r3
  unsigned int v7; // r3

  v3 = *result;
  if ( ((*result >> 11) & 5) == 5 )
  {
    v4 = (v3 >> 7) & 3;
    if ( (a3 - 1)
       * (*(unsigned __int16 *)(dword_11B154
                              + 2 * (3 * ((*result >> 8) & 1) + 6 * (*result & 0x7F) + ((*result >> 9) & 3))) << ((*result & 0x80) != 0)) < a2 )
    {
      if ( (v3 & 0x1C000) != 0 )
      {
        v7 = v3 & 0xFFFE3FFF | 0x8000;
      }
      else
      {
        v5 = v3 & 0xE01FFFFF;
        if ( (*result & 0xF) <= 2 )
          v6 = 0x80000;
        else
          v6 = 0x100000;
        v7 = v6 | (v4 << 24) | v5 & 0xFFE03FFF | 0x4008000;
      }
      *result = v7;
    }
  }
  return result;
}

