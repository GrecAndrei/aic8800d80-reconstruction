// sub_141580 @ 0x141580, size 106 bytes
_DWORD *__fastcall sub_141580(int a1, int a2)
{
  int v2; // r4
  int v4; // r6
  _DWORD *result; // r0

  if ( a2 )
  {
    v2 = dword_1415EC;
    v4 = *(_DWORD *)(dword_1415EC + 6480);
    if ( sub_1403D0() )
    {
      if ( sub_12CD48(0xBu) == 3 )
        return (_DWORD *)sub_1414AC();
      else
        return sub_141344();
    }
    else
    {
      *(_BYTE *)(a1 + 98) = 1;
      sub_140400(a1, 0, 0, v2 + 136 * v4 + 6336);
      return (_DWORD *)sub_118B34(a1, 3);
    }
  }
  else
  {
    result = sub_12CBF4(0xBu, 0);
    *(_DWORD *)(dword_1415EC + 6480) = -1;
  }
  return result;
}

