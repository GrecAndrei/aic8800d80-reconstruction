// sub_118B04 @ 0x118b04, size 38 bytes
int  sub_118B04(int a1, int a2)
{
  int v4; // r0
  int v5; // r1
  int v6; // r2
  int v7; // r4

  v4 = sub_12D190(dword_118B2C);
  v7 = v4;
  if ( v4 )
  {
    sub_118A78(v4, a1, a2);
    return v7;
  }
  else
  {
    sub_12E948(dword_118B30, v5, v6);
    return 0;
  }
}

