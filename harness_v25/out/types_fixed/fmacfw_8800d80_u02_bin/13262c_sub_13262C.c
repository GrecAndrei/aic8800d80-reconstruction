// sub_13262C @ 0x13262c, size 42 bytes
int __fastcall sub_13262C(int a1)
{
  int v1; // r3
  int v2; // r2
  char v3; // r1

  if ( !a1 )
    return 12;
  v1 = 0;
  while ( 1 )
  {
    v2 = a1 >> (11 - v1) << 31;
    v3 = v1++;
    if ( v2 < 0 )
      break;
    if ( v1 == 12 )
      return 255;
  }
  return (unsigned __int8)(11 - v3);
}

