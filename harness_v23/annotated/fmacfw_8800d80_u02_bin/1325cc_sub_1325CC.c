// v23 annotated: sub_1325CC @ 0x1325cc
// Original: 1325cc_sub_1325CC.c
// Primary struct: group_29 (cluster 29)
//
// sub_1325CC @ 0x1325cc, size 40 bytes
int __fastcall sub_1325CC(int a1)
{
  int v1; // r2
  int result; // r0
  int v4; // r3
  char v5; // r1

  v1 = 14;
  result = 7;
  do
  {
    v4 = (a1 >> v1) & 3;
    v5 = result - 1;
    v1 -= 2;
    if ( v4 != 3 )
      break;
    result = (unsigned __int8)(result - 1);
  }
  while ( v5 );
  return result;
}

