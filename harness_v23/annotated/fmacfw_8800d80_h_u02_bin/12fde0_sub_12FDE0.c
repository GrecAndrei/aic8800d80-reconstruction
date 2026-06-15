// v23 annotated: sub_12FDE0 @ 0x12fde0
// Original: 12fde0_sub_12FDE0.c
// Primary struct: <unclustered>
//
// sub_12FDE0 @ 0x12fde0, size 110 bytes
int __fastcall sub_12FDE0(int a1, int a2)
{
  unsigned int v4; // r0
  int v5; // r7
  unsigned int v6; // r6
  _DWORD *v7; // r4
  int v8; // r0

  if ( a1 == 1 )
  {
    sub_130260();
    return 0;
  }
  else
  {
    v4 = sub_12F818(*(unsigned __int8 **)(a2 + 4), nullptr, 0);
    v5 = v4;
    if ( v4 )
      v5 = 1;
    v6 = v4;
    if ( a1 > 2 )
    {
      v7 = off_12FE50;
      v4 = sub_12F818(*(unsigned __int8 **)(a2 + 8), nullptr, 0);
      if ( v4 > 0x7D0 )
        v7[91] = v4;
    }
    else
    {
      v7 = off_12FE50;
    }
    if ( *((unsigned __int8 *)v7 + 363) != v5 )
    {
      *((_BYTE *)v7 + 363) = v5;
      if ( v6 )
      {
        v8 = sub_1303B8(v4);
        sub_130474(v8);
      }
      else
      {
        sub_1304D8();
      }
    }
    sub_12E948(dword_12FE54, v5, v7[91]);
    return 0;
  }
}

