// v23 annotated: sub_12D464 @ 0x12d464
// Original: 12d464_sub_12D464.c
// Primary struct: <unclustered>
//
// sub_12D464 @ 0x12d464, size 242 bytes
float __fastcall sub_12D464(unsigned int a1)
{
  unsigned int v1; // r3
  int v2; // s15
  int v3; // r0
  float v4; // s15
  float v6; // s15
  float v7; // s13
  float v8; // s14
  _BYTE vars0[3]; // [sp+4h] [bp+0h]

  v1 = *(_DWORD *)vars0 & 0x7FFFFF;
  v2 = *(_DWORD *)vars0 & 0x7FFFFF;
  v3 = (unsigned __int8)(a1 >> 23);
  if ( (*(_DWORD *)vars0 & 0x7FFFFFu) >= 0x100000 )
  {
    if ( v1 >= 0x200000 )
    {
      if ( v1 < 0x300000 )
      {
        v4 = (float)((float)v2 * flt_12D574) + flt_12D578;
      }
      else if ( v1 >= 0x400000 )
      {
        v6 = (float)(unsigned int)v2;
        if ( v1 < 0x500000 )
        {
          v4 = (float)(v6 * flt_12D584) + flt_12D588;
        }
        else if ( v1 >= 0x600000 )
        {
          if ( v1 >= 0x700000 )
            v7 = flt_12D590;
          else
            v7 = flt_12D58C;
          if ( v1 >= 0x700000 )
            v8 = flt_12D598;
          else
            v8 = flt_12D594;
          v4 = (float)(v6 * v7) + v8;
        }
        else
        {
          v4 = (float)(v6 * flt_12D57C) + flt_12D580;
        }
      }
      else
      {
        v4 = (float)((float)v2 * flt_12D56C) + flt_12D570;
      }
    }
    else
    {
      v4 = (float)((float)v2 * flt_12D564) + flt_12D568;
    }
  }
  else
  {
    v4 = (float)((float)v2 * flt_12D558) + flt_12D55C;
  }
  return (float)(v3 - 127) + (float)(v4 * flt_12D560);
}

