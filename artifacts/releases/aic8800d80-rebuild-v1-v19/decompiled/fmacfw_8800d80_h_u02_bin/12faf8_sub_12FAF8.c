// sub_12FAF8 @ 0x12faf8, size 144 bytes
int __fastcall sub_12FAF8(int a1, int a2)
{
  int v4; // r0
  unsigned __int16 v6; // r0
  int v7; // r0
  int v8; // r4

  v4 = sub_12F818(*(unsigned __int8 **)(a2 + 4), nullptr, 0xAu);
  if ( v4 )
  {
    if ( v4 == 1 )
    {
      if ( a1 <= 2 )
        goto LABEL_5;
      v6 = sub_12F818(*(unsigned __int8 **)(a2 + 8), nullptr, 0x10u);
      **(_WORD **)off_12FB8C = v6;
      sub_12E948(dword_12FB90, v6);
      return 0;
    }
    else if ( v4 == 2 )
    {
      if ( a1 <= 2 )
      {
LABEL_5:
        sub_12E948(dword_12FB88);
        return 0;
      }
      v8 = sub_12F818(*(unsigned __int8 **)(a2 + 8), nullptr, 0x10u);
      sub_12E948(dword_12FBA0, v8);
      sub_12E8EC(v8);
      return 0;
    }
    else
    {
      sub_12E948(dword_12FB9C, v4);
      return 0;
    }
  }
  else
  {
    sub_12E948(dword_12FB94, **(unsigned __int16 **)off_12FB8C);
    v7 = sub_12E904();
    sub_12E948(dword_12FB98, v7);
    return 0;
  }
}

