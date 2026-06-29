// fwstruct annotate: 12ba0c_sub_12BA0C.c
// sub_12BA0C @ 0x12ba0c, size 126 bytes
int *sub_12BA0C()
{
  _DWORD *v0; // r1
  _DWORD *v1; // r0
  _DWORD *v2; // r2
  _DWORD *v3; // r1
  _DWORD *v4; // r5
  int *v5; // r0
  int v6; // r4
  _DWORD *v7; // r1
  _DWORD *v8; // r4
  int v9; // r3
  int *result; // r0

  v0 = off_12BA90;
  v1 = off_12BA94;
  *(_DWORD *)off_12BA8C &= ~0x80u;
  *v0 = 0;
  *v1 = 60;
  while ( *v0 << 28 )
    ;
  v2 = off_12BA94;
  v3 = off_12BA98;
  v4 = off_12BA9C;
  v5 = (int *)off_12BAA0;
  v6 = dword_12BAA4;
  *(_DWORD *)off_12BA94 |= 0x10000u;
  *v3 &= 0xFFFFFF00;
  *v4 = -1;
  *v5 = v6;
  v7 = off_12BAA8;
  v8 = off_12BAAC;
  v2[8200] |= 0x80000000;
  v9 = v7[1];
  v4[1] |= 0x80000000;
  result = v5 - 8201;
  *v8 |= 0x80000000;
  *result |= 0x80u;
  v7[1] = v9 & 0xFFFFFFFB;
  return result;
}

