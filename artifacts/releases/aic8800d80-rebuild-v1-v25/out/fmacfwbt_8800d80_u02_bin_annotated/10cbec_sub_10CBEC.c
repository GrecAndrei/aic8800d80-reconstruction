// fwstruct annotate: 10cbec_sub_10CBEC.c
// sub_10CBEC @ 0x10cbec, size 48 bytes
int sub_10CBEC()
{
  _DWORD *v0; // r4
  int *v1; // r7
  _DWORD *v2; // r6
  int v3; // r0
  int result; // r0

  v0 = off_10CC1C;
  if ( (*(_DWORD *)off_10CC1C & 2) != 0 )
  {
    v1 = (int *)off_10CC20;
    v2 = off_10CC24;
    do
    {
      v3 = *v1;
      *v2 = 2;
      sub_10CB08((_WORD *)(v3 + 4));
    }
    while ( (*v0 & 2) != 0 );
  }
  result = sub_12D374(0x8000000);
  *(_DWORD *)off_10CC28 = 2;
  return result;
}

