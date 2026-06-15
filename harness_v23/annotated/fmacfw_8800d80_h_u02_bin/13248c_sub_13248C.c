// v23 annotated: sub_13248C @ 0x13248c
// Original: 13248c_sub_13248C.c
// Primary struct: <unclustered>
//
// sub_13248C @ 0x13248c, size 40 bytes
int __fastcall sub_13248C(int a1)
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

