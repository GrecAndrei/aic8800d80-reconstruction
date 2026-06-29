// sub_113C98 @ 0x113c98, size 104 bytes
int  sub_113C98(unsigned int a1, int a2)
{
  int v4; // r4
  unsigned int v5; // r4

  v4 = sub_113A44(7u);
  if ( (unsigned __int16)sub_113A44(8u) | v4 )
  {
    v5 = sub_113A44(8u);
    if ( (HIWORD(v5) << 16) | sub_113A44(9u) )
    {
      return -1;
    }
    else
    {
      sub_113AD0(8u, a1 << 16);
      sub_113AD0(9u, HIWORD(a1) | (a2 << 16));
      return 0;
    }
  }
  else
  {
    sub_113AD0(7u, a1);
    sub_113AD0(8u, a2);
    return 1;
  }
}

