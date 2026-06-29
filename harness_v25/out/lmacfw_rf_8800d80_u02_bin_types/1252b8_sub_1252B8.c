// sub_1252B8 @ 0x1252b8, size 184 bytes
int  sub_1252B8(int a1, unsigned __int8 **a2)
{
  int v4; // r0
  unsigned int v6; // r4
  int v7; // r0
  unsigned int v8; // r4
  int v9; // r5
  unsigned int v10; // r5
  int v11; // r6
  int v12; // r0
  unsigned int v13; // r1

  v4 = sub_121E3C(a2[1], nullptr, 0);
  if ( v4 == 1 )
  {
    if ( a1 > 3 )
    {
      v8 = sub_121E3C(a2[2], nullptr, 0);
      v9 = sub_121E3C(a2[3], nullptr, 0x10u);
      sub_11F504(dword_125378, v8, v9);
      sub_113AD0(v8, v9);
    }
  }
  else
  {
    if ( v4 != 2 )
      return -(v4 != 0);
    v6 = sub_121E3C(a2[2], nullptr, 0);
    if ( v6 <= 0x1F )
    {
      if ( a1 > 3 )
      {
        v10 = sub_121E3C(a2[3], nullptr, 0) + v6;
        if ( v10 >= 0x20 )
          v10 = 32;
        sub_11F504(dword_125370);
        if ( v6 < v10 )
        {
          v11 = dword_125374;
          do
          {
            v12 = sub_113A44(v6);
            v13 = v6++;
            sub_11F504(v11, v13, v12);
          }
          while ( v10 > v6 );
        }
      }
      else
      {
        sub_11F504(dword_125370);
        v7 = sub_113A44(v6);
        sub_11F504(dword_125374, v6, v7);
      }
    }
  }
  return 0;
}

