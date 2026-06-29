// fwstruct annotate: 10f3b0_sub_10F3B0.c
// sub_10F3B0 @ 0x10f3b0, size 156 bytes
__int64 sub_10F3B0()
{
  _WORD *v0; // r5
  int *v1; // r4
  int *v2; // r5
  int *v3; // r6
  int v4; // r2
  __int64 result; // r0
  _DWORD *v6; // r3

  v0 = off_10F44C;
  v1 = (int *)dword_10F450;
  *((_WORD *)off_10F44C + 3080) = -16193;
  v0[1536] = -16193;
  *((_BYTE *)v0 + 6162) = 0;
  *((_DWORD *)v0 + 1541) = 0;
  *((_BYTE *)v0 + 6176) = 0;
  *((_BYTE *)v0 + 3074) = 0;
  *((_DWORD *)v0 + 769) = 0;
  sub_12D240(v0 + 1540);
  sub_12D240(v1 - 3);
  sub_12D240(v1 + 512);
  sub_12D240(v1 + 514);
  v0[4122] = 0;
  *((_BYTE *)v0 + 3074) = 0;
  *((_DWORD *)v0 + 769) = 0;
  sub_100200(v1, 0, 0x800u);
  v2 = v1 + 512;
  v3 = v1 + 512;
  do
  {
    v1 += 4;
    sub_12D248(v3);
  }
  while ( v1 != v2 );
  v4 = dword_10F454;
  result = (unsigned int)(dword_10F454 + 1152);
  do
  {
    v6 = (_DWORD *)(v4 - 36);
    do
      *v6++ = 0;
    while ( v6 != (_DWORD *)v4 );
    v4 = (int)(v6 + 9);
  }
  while ( v6 + 9 != (_DWORD *)result );
  return result;
}

