// sub_12FEA4 @ 0x12fea4, size 104 bytes
int __fastcall sub_12FEA4(int a1, int a2)
{
  int v4; // r0
  int v5; // r0
  unsigned int v7; // r4

  if ( a1 <= 1 || (v4 = sub_12F958(*(unsigned __int8 **)(a2 + 4), nullptr, 0)) == 0 )
  {
    v5 = sub_12EA50();
    msg_parse(dword_12FF0C, v5);
    return 0;
  }
  if ( v4 == 1 )
  {
    if ( a1 == 2 )
    {
      msg_parse(dword_12FF18);
    }
    else
    {
      v7 = sub_12F958(*(unsigned __int8 **)(a2 + 8), nullptr, 0);
      if ( v7 > 5 )
      {
        msg_parse(dword_12FF1C, v7);
      }
      else
      {
        msg_parse(dword_12FF10, v7);
        sub_12EA38(v7);
      }
    }
    return 0;
  }
  msg_parse(dword_12FF14);
  return 0;
}

