// v23 annotated: sub_130804 @ 0x130804
// Original: 130804_sub_130804.c
// Primary struct: <unclustered>
//
// sub_130804 @ 0x130804, size 52 bytes
// Doc: sub_1230804 [util]: Writes three 16-bit fields from r1/r2/r3 into a structure pointed by r0
// sub_1230804 [util]: Writes three 16-bit fields from r1/r2/r3 into a structure pointed by r0
int __fastcall sub_130804(int a1, __int16 a2, __int16 a3, __int16 a4, char *a5)
{
  char *v5; // r2
  _BYTE *v6; // r3
  char v7; // t1

  *(_WORD *)a1 = a2;
  *(_WORD *)(a1 + 2) = a3;
  *(_WORD *)(a1 + 4) = a4;
  if ( !a5 )
    return 6;
  *(_BYTE *)(a1 + 6) = 16;
  *(_BYTE *)(a1 + 7) = 0x80;
  v5 = a5;
  do
  {
    v6 = v5 + 8;
    v7 = *v5++;
    *(_BYTE *)(v6 - a5 + a1) = v7;
  }
  while ( v5 != a5 + 128 );
  return 136;
}

