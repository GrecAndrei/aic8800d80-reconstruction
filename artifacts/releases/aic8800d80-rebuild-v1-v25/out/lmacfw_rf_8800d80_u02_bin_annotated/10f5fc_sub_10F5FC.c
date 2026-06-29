// fwstruct annotate: 10f5fc_sub_10F5FC.c
// sub_10F5FC @ 0x10f5fc, size 156 bytes
__int64 sub_10F5FC()
{
  _WORD *v0; // r5
  int *v1; // r4
  int *v2; // r5
  int *v3; // r6
  int v4; // r2
  __int64 result; // r0
  _DWORD *v6; // r3

  v0 = off_10F698;
  v1 = (int *)dword_10F69C;
  *((_WORD *)off_10F698 + 3080) = -16193;
  v0[1536] = -16193;
  *((_BYTE *)v0 + 6162) = 0;
  *((_DWORD *)v0 + 1541) = 0;
  *((_BYTE *)v0 + 6176) = 0;
  *((_BYTE *)v0 + 3074) = 0;
  *((_DWORD *)v0 + 769) = 0;
  sub_11E71C(v0 + 1540);
  sub_11E71C(v1 - 3);
  sub_11E71C(v1 + 512);
  sub_11E71C(v1 + 514);
  v0[4122] = 0;
  *((_BYTE *)v0 + 3074) = 0;
  *((_DWORD *)v0 + 769) = 0;
  sub_100200(v1, 0, 0x800u);
  v2 = v1 + 512;
  v3 = v1 + 512;
  do
  {
    v1 += 4;
    list_push_tail(v3);
  }
  while ( v1 != v2 );
  v4 = dword_10F6A0;
  result = (unsigned int)(dword_10F6A0 + 144);
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

