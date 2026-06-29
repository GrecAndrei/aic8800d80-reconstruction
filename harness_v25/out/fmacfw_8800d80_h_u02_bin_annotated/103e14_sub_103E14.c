// fwstruct annotate: 103e14_sub_103E14.c
// sub_103E14 @ 0x103e14, size 86 bytes
int sub_103E14()
{
  int v0; // r2
  int *v1; // r4
  int v2; // r0
  int v3; // r1
  int v4; // r2
  int *v5; // r3
  int v6; // r1
  _DWORD *v7; // r2
  int v8; // r0

  v0 = 777;
  v1 = (int *)off_103E70;
  *(_DWORD *)off_103E6C = 777;
  while ( *v1 < 0 )
    sub_100644(1);
  sub_12E948(dword_103E74, *(_DWORD *)off_103E70, v0);
  v2 = dword_103E78;
  *(_DWORD *)off_103E6C = 0;
  sub_12E948(v2, v3, v4);
  v5 = (int *)off_103E80;
  v6 = dword_103E84;
  v7 = off_103E88;
  *(_DWORD *)off_103E7C = 0;
  *v5 = v6;
  v8 = dword_103E8C;
  *v7 &= 0xFF00FFFF;
  return sub_12E948(v8, 0x4000, v7);
}

