// sub_10E0B8 @ 0x10e0b8, size 146 bytes
float sub_10E0B8()
{
  _DWORD *v0; // r4
  _DWORD *v1; // r2
  int v2; // r3
  int v3; // r0
  int v4; // r1
  unsigned int v5; // r4

  v0 = off_10E14C;
  v1 = off_10E150;
  v2 = dword_10E154;
  v3 = dword_10E158;
  v4 = dword_10E15C;
  *(_DWORD *)off_10E14C = 0;
  v1[14] = 296;
  v0[2] = v0[2] & 0xF000FFFF | 0x2000000;
  v0[3] = v2 & v0[3] | 0xA06A000;
  v0[3] = v4 | v3 & v0[3];
  sub_10DC78();
  v0[1] = 1;
  while ( v0[7] != 1 )
    ;
  v0[7] = 1;
  v5 = v0[4];
  sub_10EFB4(dword_10E160, 0, 15360);
  return (float)((float)((float)((float)v5 / flt_10E164) - 1.0) * flt_10E168) * flt_10E16C;
}

