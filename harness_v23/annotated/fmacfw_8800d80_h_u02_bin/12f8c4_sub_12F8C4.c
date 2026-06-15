// v23 annotated: sub_12F8C4 @ 0x12f8c4
// Original: 12f8c4_sub_12F8C4.c
// Primary struct: <unclustered>
//
// sub_12F8C4 @ 0x12f8c4, size 32 bytes
int sub_12F8C4()
{
  _DWORD *v0; // r4
  int v1; // r6
  int v2; // r5

  v0 = (_DWORD *)dword_12F8E4;
  v1 = dword_12F8E8;
  v2 = dword_12F8E4 + 112;
  do
  {
    if ( v0[1] )
      sub_10DAE4(v1, *v0);
    v0 += 4;
  }
  while ( v0 != (_DWORD *)v2 );
  return 0;
}

