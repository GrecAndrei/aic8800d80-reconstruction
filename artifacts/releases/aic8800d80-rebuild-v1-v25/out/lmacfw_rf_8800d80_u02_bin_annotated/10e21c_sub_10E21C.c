// fwstruct annotate: 10e21c_sub_10E21C.c
// sub_10E21C @ 0x10e21c, size 170 bytes
float sub_10E21C()
{
  _DWORD *v0; // r3
  _DWORD *v1; // r1
  int v2; // r2
  int v3; // r5
  int v4; // r4

  v0 = off_10E2C8;
  v1 = off_10E2CC;
  v2 = dword_10E2D0;
  *(_DWORD *)off_10E2C8 = 0;
  v1[14] = 296;
  v3 = dword_10E2D4;
  v4 = dword_10E2D8;
  v0[2] = v0[2] & 0xF000FFFF | 0x2000000;
  v0[3] = v2 & v0[3] | 0xA06A000;
  v0[3] = v4 | v3 & v0[3];
  v0[2] = v0[2] & 0xEFFFFFF0 | 0xB;
  v0[3] = v0[3] & 0xFFFFF7FE | 1;
  v0[2] &= ~0x10000000u;
  v0[3] = v0[3] & 0xFFFFF7FE | 1;
  v0[1] = 1;
  while ( v0[7] != 1 )
    ;
  v0[7] = 1;
  return (float)((float)((float)(unsigned int)v0[4] / flt_10E2DC) - 1.0) * flt_10E2E0;
}

