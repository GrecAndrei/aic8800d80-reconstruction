// fwstruct annotate: 12bd74_sub_12BD74.c
// sub_12BD74 @ 0x12bd74, size 126 bytes
int *sub_12BD74()
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

  v0 = off_12BDF8;
  v1 = off_12BDFC;
  *(_DWORD *)off_12BDF4 &= ~0x80u;
  *v0 = 0;
  *v1 = 60;
  while ( *v0 << 28 )
    ;
  v2 = off_12BDFC;
  v3 = off_12BE00;
  v4 = off_12BE04;
  v5 = (int *)off_12BE08;
  v6 = dword_12BE0C;
  *(_DWORD *)off_12BDFC |= 0x10000u;
  *v3 &= 0xFFFFFF00;
  *v4 = -1;
  *v5 = v6;
  v7 = off_12BE10;
  v8 = off_12BE14;
  v2[8200] |= 0x80000000;
  v9 = v7[1];
  v4[1] |= 0x80000000;
  result = v5 - 8201;
  *v8 |= 0x80000000;
  *result |= 0x80u;
  v7[1] = v9 & 0xFFFFFFFB;
  return result;
}

