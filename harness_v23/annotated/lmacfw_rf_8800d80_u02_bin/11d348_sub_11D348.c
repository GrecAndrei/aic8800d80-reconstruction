// v23 annotated: sub_11D348 @ 0x11d348
// Original: 11d348_sub_11D348.c
// Primary struct: <unclustered>
//
// sub_11D348 @ 0x11d348, size 116 bytes
int *sub_11D348()
{
  _DWORD *v0; // r1
  _DWORD *v1; // r0
  _DWORD *v2; // r1
  _DWORD *v3; // r2
  int *result; // r0
  _DWORD *v5; // r6
  _DWORD *v6; // r4
  int v7; // r5

  v0 = off_11D3C0;
  v1 = off_11D3C4;
  *(_DWORD *)off_11D3BC &= ~0x80u;
  *v0 = 0;
  *v1 = 60;
  while ( *v0 << 28 )
    ;
  v2 = off_11D3C4;
  v3 = off_11D3C8;
  result = (int *)off_11D3CC;
  v5 = off_11D3D0;
  v6 = off_11D3D4;
  v7 = dword_11D3D8;
  *(_DWORD *)off_11D3C4 |= 0x10000u;
  *v3 &= 0xFFFFFF00;
  *v5 = -1;
  *result = v7;
  *v6 |= 0x80000000;
  result[4] |= 0x80000000;
  v2[8197] |= 0x80000000;
  *(v3 - 8208) |= 0x80u;
  return result;
}

