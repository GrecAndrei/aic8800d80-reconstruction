// sub_122FA4 @ 0x122fa4, size 104 bytes
unsigned int  sub_122FA4(int a1, int a2)
{
  unsigned int v4; // r0
  unsigned int v5; // r4

  v4 = sub_113B30();
  v5 = v4;
  if ( a1 )
  {
    if ( a1 == 1 )
    {
      if ( v4 )
      {
        sub_11F504(dword_123010);
      }
      else
      {
        sub_11F504(dword_12301C, a2);
        sub_113B80(__ROR4__(a2, 16));
        sub_113B40();
      }
      return __ROR4__(sub_113B78(), 16);
    }
    else
    {
      sub_11F504(dword_123018);
      return 0;
    }
  }
  else
  {
    if ( v4 )
    {
      v5 = __ROR4__(sub_113B78(), 16);
      sub_11F504(dword_123014, v5);
    }
    else
    {
      sub_11F504(dword_12300C);
    }
    return v5;
  }
}

