// sub_12CADC @ 0x12cadc, size 32 bytes
int __fastcall sub_12CADC(int a1, int a2)
{
  int **v2; // r3

  v2 = *((int ***)off_12CAFC + 5);
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

