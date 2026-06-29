// sub_122198 @ 0x122198, size 144 bytes
int  sub_122198(int a1, int a2)
{
  int v4; // r0
  unsigned __int16 v6; // r0
  int v7; // r0
  int v8; // r4

  v4 = sub_121E3C(*(unsigned __int8 **)(a2 + 4), nullptr, 0xAu);
  if ( v4 )
  {
    if ( v4 == 1 )
    {
      if ( a1 <= 2 )
        goto LABEL_5;
      v6 = sub_121E3C(*(unsigned __int8 **)(a2 + 8), nullptr, 0x10u);
      **(uint16_t **)off_12222C = v6;
      sub_11F504(dword_122230, v6);
      return 0;
    }
    else if ( v4 == 2 )
    {
      if ( a1 <= 2 )
      {
LABEL_5:
        sub_11F504(dword_122228);
        return 0;
      }
      v8 = sub_121E3C(*(unsigned __int8 **)(a2 + 8), nullptr, 0x10u);
      sub_11F504(dword_122240, v8);
      sub_11F4A8(v8);
      return 0;
    }
    else
    {
      sub_11F504(dword_12223C, v4);
      return 0;
    }
  }
  else
  {
    sub_11F504(dword_122234, **(unsigned __int16 **)off_12222C);
    v7 = sub_11F4C0();
    sub_11F504(dword_122238, v7);
    return 0;
  }
}

