// v23 annotated: sub_127A54 @ 0x127a54
// Original: 127a54_sub_127A54.c
// Primary struct: <unclustered>
//
// sub_127A54 @ 0x127a54, size 122 bytes
int __fastcall sub_127A54(unsigned int a1, unsigned int a2, unsigned int a3, int a4)
{
  bool v4; // zf
  bool v5; // zf
  bool v7; // cf
  bool v8; // zf
  int v9; // r0

  v4 = (int)(2 * a2) >> 21 == -1;
  if ( (int)(2 * a2) >> 21 != -1 )
    v4 = (2 * a4) >> 21 == -1;
  if ( v4 && ((int)(2 * a2) >> 21 == -1 && a1 | (a2 << 12) || (2 * a4) >> 21 == -1 && a3 | (a4 << 12)) )
    return 1;
  v5 = (a1 | (2 * a2)) == 0;
  if ( !(a1 | (2 * a2)) )
    v5 = (a3 | (2 * a4)) == 0;
  if ( !v5 )
    v5 = a2 == a4;
  if ( v5 && a1 == a3 )
    return 0;
  v7 = 0;
  v8 = a2 == a4;
  if ( ((a2 ^ a4) & 0x80000000) == 0 )
  {
    v7 = a2 >= a4;
    v8 = a2 == a4;
  }
  if ( v8 )
    v7 = a1 >= a3;
  if ( v7 )
    v9 = a4 >> 31;
  else
    v9 = ~(a4 >> 31);
  return v9 | 1;
}

