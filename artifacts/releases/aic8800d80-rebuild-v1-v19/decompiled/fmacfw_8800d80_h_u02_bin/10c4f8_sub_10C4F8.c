// sub_10C4F8 @ 0x10c4f8, size 172 bytes
int sub_10C4F8()
{
  int *v0; // r2
  unsigned int *v1; // r1
  _DWORD *v2; // r4
  int v3; // r0
  unsigned int v4; // r3
  unsigned int v5; // r5
  int result; // r0

  v0 = (int *)off_10C5A8;
  *((_DWORD *)off_10C5A4 + 64) = 6;
  v0[1] &= ~0x40000u;
  v0[1] |= 0x20000u;
  while ( (v0[12] & 0x44) != 4 )
    ;
  v1 = (unsigned int *)off_10C5B4;
  v2 = off_10C5A4;
  v3 = dword_10C5B8;
  v4 = (unsigned int)(((unsigned int)dword_10C5B0 * (unsigned __int64)*(unsigned int *)off_10C5AC) >> 32) >> 18;
  v5 = v4 | 0x80140000;
  v4 |= 0x140000u;
  *(_DWORD *)off_10C5B4 = v4;
  *v1 = v5;
  *v1 = v4;
  v0[1] |= 0x18802u;
  v2[81] = 8;
  *v0 = *v0 & 0x3BF | 0x40 | *v0 & v3;
  v2[14] |= 1u;
  v0[17] |= 0x88000000;
  v0[21] &= ~0x200000u;
  result = v3 & v0[21];
  v0[21] = v0[21] & 0x3FD | 2 | result;
  v0[21] &= ~0x800u;
  return result;
}

