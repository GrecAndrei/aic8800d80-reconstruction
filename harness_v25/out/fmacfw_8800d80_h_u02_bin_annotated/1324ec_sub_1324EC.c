// fwstruct annotate: 1324ec_sub_1324EC.c
// sub_1324EC @ 0x1324ec, size 42 bytes
int __fastcall sub_1324EC(int a1)
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

