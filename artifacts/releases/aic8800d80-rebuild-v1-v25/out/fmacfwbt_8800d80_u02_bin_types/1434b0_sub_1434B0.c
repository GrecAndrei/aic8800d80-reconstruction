// sub_1434B0 @ 0x1434b0, size 48 bytes
int  sub_1434B0(uint64_t a1, int a2, int a3)
{
  if ( a3 || a2 )
  {
    LODWORD(a1) = sub_1434E0(a1);
  }
  else if ( a1 )
  {
    LODWORD(a1) = -1;
  }
  return a1;
}

