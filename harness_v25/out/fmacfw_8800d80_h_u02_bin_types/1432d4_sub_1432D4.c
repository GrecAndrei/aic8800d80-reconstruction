// sub_1432D4 @ 0x1432d4, size 48 bytes
int  sub_1432D4(uint64_t a1, int a2, int a3)
{
  if ( a3 || a2 )
  {
    LODWORD(a1) = sub_143304(a1);
  }
  else if ( a1 )
  {
    LODWORD(a1) = -1;
  }
  return a1;
}

