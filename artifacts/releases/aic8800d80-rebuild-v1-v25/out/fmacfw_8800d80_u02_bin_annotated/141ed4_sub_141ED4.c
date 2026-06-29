// fwstruct annotate: 141ed4_sub_141ED4.c
// sub_141ED4 @ 0x141ed4, size 68 bytes
int __fastcall sub_141ED4(int a1)
{
  __int16 v1; // r3
  _BYTE *v3; // r1
  int result; // r0

  v1 = *(_WORD *)a1;
  if ( (*(_WORD *)a1 & 8) != 0 )
  {
    v3 = off_141F18;
    *(_WORD *)a1 = v1 | 0x40;
    if ( v3[1] )
    {
      if ( (v1 & 9) == 9 )
        sub_141E48(a1);
    }
  }
  result = sub_124E34(a1 + 52);
  if ( !*(_BYTE *)(a1 + 4) )
  {
    result = *(unsigned __int8 *)(a1 + 47);
    *((_BYTE *)off_141F18 + 2) &= ~(1 << result);
  }
  return result;
}

