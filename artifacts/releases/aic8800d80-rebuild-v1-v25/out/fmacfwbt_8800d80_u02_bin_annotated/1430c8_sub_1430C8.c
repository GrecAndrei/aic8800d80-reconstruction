// fwstruct annotate: 1430c8_sub_1430C8.c
// sub_1430C8 @ 0x1430c8, size 64 bytes
unsigned int __fastcall sub_1430C8(unsigned int a1, int a2)
{
  int v2; // r2
  bool v3; // cf
  int v4; // r2
  int v5; // r2

  v2 = 2 * a2;
  if ( __CFSHL__(a2, 1) )
    return 0;
  v3 = __CFADD__(v2, 0x200000);
  v4 = v2 + 0x200000;
  if ( !v3 )
  {
    if ( v4 < 0 )
    {
      v5 = -993 - (v4 >> 21);
      if ( v5 >= 0 )
        return ((a2 << 11) | 0x80000000 | (a1 >> 21)) >> v5;
      return -1;
    }
    return 0;
  }
  if ( !(a1 | (a2 << 12)) )
    return -1;
  return 0;
}

