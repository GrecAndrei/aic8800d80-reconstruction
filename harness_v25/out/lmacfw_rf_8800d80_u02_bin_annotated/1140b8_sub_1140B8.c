// fwstruct annotate: 1140b8_sub_1140B8.c
// sub_1140B8 @ 0x1140b8, size 54 bytes
int __fastcall sub_1140B8(int *a1)
{
  unsigned __int8 v2; // r0
  int v3; // r2
  int result; // r0
  int v5; // r3

  v2 = sub_113A44(0x10u);
  v3 = v2 >> 4;
  if ( (v2 & 0xF0) != 0 )
  {
    result = 0;
  }
  else
  {
    if ( !v2 )
    {
      *a1 = 0;
      return 2;
    }
    v3 = v2;
    result = 1;
  }
  if ( (v3 & 8) != 0 )
    v5 = v3 & 7;
  else
    v5 = -v3;
  if ( (v3 & 8) != 0 )
    ++v5;
  *a1 = v5;
  return result;
}

