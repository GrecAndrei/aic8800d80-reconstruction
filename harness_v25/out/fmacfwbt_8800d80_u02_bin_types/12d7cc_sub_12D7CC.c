// sub_12D7CC @ 0x12d7cc, size 242 bytes
float  sub_12D7CC(unsigned int a1)
{
  unsigned int v1; // r3
  int v2; // s15
  int v3; // r0
  float v4; // s15
  float v6; // s15
  float v7; // s13
  float v8; // s14
  uint8_t vars0[3]; // [sp+4h] [bp+0h]

  v1 = *(uint32_t *)vars0 & 0x7FFFFF;
  v2 = *(uint32_t *)vars0 & 0x7FFFFF;
  v3 = (unsigned __int8)(a1 >> 23);
  if ( (*(uint32_t *)vars0 & 0x7FFFFFu) >= 0x100000 )
  {
    if ( v1 >= 0x200000 )
    {
      if ( v1 < 0x300000 )
      {
        v4 = (float)((float)v2 * flt_12D8DC) + flt_12D8E0;
      }
      else if ( v1 >= 0x400000 )
      {
        v6 = (float)(unsigned int)v2;
        if ( v1 < 0x500000 )
        {
          v4 = (float)(v6 * flt_12D8EC) + flt_12D8F0;
        }
        else if ( v1 >= 0x600000 )
        {
          if ( v1 >= 0x700000 )
            v7 = flt_12D8F8;
          else
            v7 = flt_12D8F4;
          if ( v1 >= 0x700000 )
            v8 = flt_12D900;
          else
            v8 = flt_12D8FC;
          v4 = (float)(v6 * v7) + v8;
        }
        else
        {
          v4 = (float)(v6 * flt_12D8E4) + flt_12D8E8;
        }
      }
      else
      {
        v4 = (float)((float)v2 * flt_12D8D4) + flt_12D8D8;
      }
    }
    else
    {
      v4 = (float)((float)v2 * flt_12D8CC) + flt_12D8D0;
    }
  }
  else
  {
    v4 = (float)((float)v2 * flt_12D8C0) + flt_12D8C4;
  }
  return (float)(v3 - 127) + (float)(v4 * flt_12D8C8);
}

