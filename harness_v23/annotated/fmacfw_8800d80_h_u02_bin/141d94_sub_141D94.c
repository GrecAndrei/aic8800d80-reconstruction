// v23 annotated: sub_141D94 @ 0x141d94
// Original: 141d94_sub_141D94.c
// Primary struct: <unclustered>
//
// sub_141D94 @ 0x141d94, size 68 bytes
int __fastcall sub_141D94(int a1)
{
  __int16 v1; // r3
  _BYTE *v3; // r1
  int result; // r0

  v1 = *(_WORD *)a1;
  if ( (*(_WORD *)a1 & 8) != 0 )
  {
    v3 = off_141DD8;
    *(_WORD *)a1 = v1 | 0x40;
    if ( v3[1] )
    {
      if ( (v1 & 9) == 9 )
        sub_141D08(a1);
    }
  }
  result = sub_124CF4(a1 + 52);
  if ( !*(_BYTE *)(a1 + 4) )
  {
    result = *(unsigned __int8 *)(a1 + 47);
    *((_BYTE *)off_141DD8 + 2) &= ~(1 << result);
  }
  return result;
}

