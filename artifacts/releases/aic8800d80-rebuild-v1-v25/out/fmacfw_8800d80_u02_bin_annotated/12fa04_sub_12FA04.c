// fwstruct annotate: 12fa04_sub_12FA04.c
// sub_12FA04 @ 0x12fa04, size 32 bytes
int sub_12FA04()
{
  _DWORD *v0; // r4
  int v1; // r6
  int v2; // r5

  v0 = (_DWORD *)dword_12FA24;
  v1 = dword_12FA28;
  v2 = dword_12FA24 + 112;
  do
  {
    if ( v0[1] )
      sub_10DC24(v1, *v0);
    v0 += 4;
  }
  while ( v0 != (_DWORD *)v2 );
  return 0;
}

