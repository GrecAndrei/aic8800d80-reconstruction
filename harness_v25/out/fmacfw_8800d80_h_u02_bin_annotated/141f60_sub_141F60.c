// fwstruct annotate: 141f60_sub_141F60.c
// sub_141F60 @ 0x141f60, size 38 bytes
int *sub_141F60()
{
  int *v0; // r4
  int *v1; // r5
  int *result; // r0

  v0 = (int *)dword_141F8C;
  sub_100200((int *)dword_141F88, 0, 3u);
  v1 = v0 + 144;
  do
  {
    result = sub_100200(v0, 0, 0x48u);
    v0[15] = (int)v0;
    v0 += 18;
  }
  while ( v0 != v1 );
  return result;
}

