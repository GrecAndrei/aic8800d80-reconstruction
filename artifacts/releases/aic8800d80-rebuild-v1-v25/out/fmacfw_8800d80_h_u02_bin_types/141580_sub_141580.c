// sub_141580 @ 0x141580, size 106 bytes
uint32_t * sub_141580(int a1, int a2)
{
  int v2; // r4
  int v4; // r6
  uint32_t *result; // r0

  if ( a2 )
  {
    v2 = dword_1415EC;
    v4 = *(uint32_t *)(dword_1415EC + 6480);
    if ( sub_1403D0() )
    {
      if ( sub_12CD48(0xBu) == 3 )
        return (uint32_t *)sub_1414AC();
      else
        return sub_141344();
    }
    else
    {
      *(uint8_t *)(a1 + 98) = 1;
      sub_140400(a1, 0, 0, v2 + 136 * v4 + 6336);
      return (uint32_t *)sub_118B34(a1, 3);
    }
  }
  else
  {
    result = sub_12CBF4(0xBu, 0);
    *(uint32_t *)(dword_1415EC + 6480) = -1;
  }
  return result;
}

