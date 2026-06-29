// fwstruct annotate: 1324d0_sub_1324D0.c
// sub_1324D0 @ 0x1324d0, size 28 bytes
int __fastcall sub_1324D0(int a1)
{
  int v1; // r3
  bool v2; // zf
  int v3; // r1

  v1 = 0;
  while ( 1 )
  {
    v2 = ((a1 >> v1) & 1) == 0;
    v3 = (unsigned __int8)v1++;
    if ( !v2 )
      break;
    if ( v1 == 12 )
      return 12;
  }
  return v3;
}

