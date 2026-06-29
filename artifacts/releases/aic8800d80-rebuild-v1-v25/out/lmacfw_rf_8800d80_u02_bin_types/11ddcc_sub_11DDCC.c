// sub_11DDCC @ 0x11ddcc, size 32 bytes
// Doc: sub_121DDCC [unknown]: Load shared state pointer and read offset 0x14
// sub_121DDCC [unknown]: Load shared state pointer and read offset 0x14
int  sub_11DDCC(int a1, int a2)
{
  int **v2; // r3

  v2 = *((int ***)off_11DDEC + 5);
  if ( !v2 )
    return (int)v2;
  while ( *((unsigned __int16 *)v2 + 2) != a1 || *((unsigned __int16 *)v2 + 3) != a2 )
  {
    v2 = (int **)*v2;
    if ( !v2 )
      return (int)v2;
  }
  return 1;
}

