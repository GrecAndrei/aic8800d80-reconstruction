// sub_125D18 @ 0x125d18, size 44 bytes
int  sub_125D18(int a1, int a2)
{
  unsigned __int8 v3; // r0

  if ( a1 > 1 )
  {
    v3 = parse_int(*(unsigned __int8 **)(a2 + 4), nullptr, 0xAu);
    sub_126258(0, 0, v3);
  }
  else
  {
    sub_126258(0, 0, 0);
  }
  return 0;
}

