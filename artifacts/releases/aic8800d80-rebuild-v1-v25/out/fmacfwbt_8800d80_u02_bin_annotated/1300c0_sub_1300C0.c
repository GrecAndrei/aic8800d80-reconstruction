// fwstruct annotate: 1300c0_sub_1300C0.c
// sub_1300C0 @ 0x1300c0, size 104 bytes
int __fastcall sub_1300C0(int a1, int a2)
{
  int v4; // r0
  int v5; // r0
  unsigned int v7; // r4

  if ( a1 <= 1 || (v4 = sub_12FB74(*(unsigned __int8 **)(a2 + 4), nullptr, 0)) == 0 )
  {
    v5 = sub_12EC78();
    sub_12ECB0(dword_130128, v5);
    return 0;
  }
  if ( v4 == 1 )
  {
    if ( a1 == 2 )
    {
      sub_12ECB0(dword_130134);
    }
    else
    {
      v7 = sub_12FB74(*(unsigned __int8 **)(a2 + 8), nullptr, 0);
      if ( v7 > 5 )
      {
        sub_12ECB0(dword_130138, v7);
      }
      else
      {
        sub_12ECB0(dword_13012C, v7);
        sub_12EC60(v7);
      }
    }
    return 0;
  }
  sub_12ECB0(dword_130130);
  return 0;
}

