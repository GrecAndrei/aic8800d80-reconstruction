// fwstruct annotate: 10cc54_sub_10CC54.c
// sub_10CC54 @ 0x10cc54, size 48 bytes
int sub_10CC54()
{
  _DWORD *v0; // r4
  int *v1; // r7
  _DWORD *v2; // r6
  int v3; // r0
  int result; // r0

  v0 = off_10CC84;
  if ( (*(_DWORD *)off_10CC84 & 2) != 0 )
  {
    v1 = (int *)off_10CC88;
    v2 = off_10CC8C;
    do
    {
      v3 = *v1;
      *v2 = 2;
      sub_10CB70((_WORD *)(v3 + 4));
    }
    while ( (*v0 & 2) != 0 );
  }
  result = sub_12D00C(0x8000000);
  *(_DWORD *)off_10CC90 = 2;
  return result;
}

