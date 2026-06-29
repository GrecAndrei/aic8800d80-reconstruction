// sub_12FD64 @ 0x12fd64, size 104 bytes
int  sub_12FD64(int a1, int a2)
{
  int v4; // r0
  int v5; // r0
  unsigned int v7; // r4

  if ( a1 <= 1 || (v4 = sub_12F818(*(unsigned __int8 **)(a2 + 4), nullptr, 0)) == 0 )
  {
    v5 = sub_12E910();
    sub_12E948(dword_12FDCC, v5);
    return 0;
  }
  if ( v4 == 1 )
  {
    if ( a1 == 2 )
    {
      sub_12E948(dword_12FDD8);
    }
    else
    {
      v7 = sub_12F818(*(unsigned __int8 **)(a2 + 8), nullptr, 0);
      if ( v7 > 5 )
      {
        sub_12E948(dword_12FDDC, v7);
      }
      else
      {
        sub_12E948(dword_12FDD0, v7);
        sub_12E8F8(v7);
      }
    }
    return 0;
  }
  sub_12E948(dword_12FDD4);
  return 0;
}

