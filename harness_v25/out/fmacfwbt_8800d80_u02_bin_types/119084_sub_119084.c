// sub_119084 @ 0x119084, size 38 bytes
// Doc: sub_1219084 [util]: Helper that loads a context struct via helper at 0x12d4f8 and returns object
// sub_1219084 [util]: Helper that loads a context struct via helper at 0x12d4f8 and returns object
int  sub_119084(int a1, int a2)
{
  int v4; // r0
  int v5; // r1
  int v6; // r2
  int v7; // r4

  v4 = sub_12D4F8(dword_1190AC);
  v7 = v4;
  if ( v4 )
  {
    sub_118FF8(v4, a1, a2);
    return v7;
  }
  else
  {
    sub_12ECB0(dword_1190B0, v5, v6);
    return 0;
  }
}

