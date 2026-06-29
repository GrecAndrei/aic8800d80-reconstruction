// fwstruct annotate: 106bb4_sub_106BB4.c
// sub_106BB4 @ 0x106bb4, size 468 bytes
int *sub_106BB4()
{
  unsigned int *v0; // r4
  _DWORD *v1; // r6
  unsigned int *v2; // r5
  _DWORD *v3; // r2
  int v4; // r1
  int v5; // r4
  unsigned int *v6; // r3
  _DWORD *v7; // r1
  int *result; // r0
  int v9; // r2
  int *v10; // r1
  unsigned int *v11; // r3

  v0 = (unsigned int *)off_106D8C;
  *(_DWORD *)off_106D88 |= 0x2000000u;
  v1 = off_106D90;
  v2 = (unsigned int *)off_106D94;
  *v0 &= ~0x20000u;
  sub_100560(2);
  v3 = off_106D98;
  v4 = dword_106D9C;
  *v0 |= 0x10000u;
  *v0 |= 0x20000u;
  *v1 |= 0x80000000;
  *v3 = v4;
  *v0 |= 0x80000u;
  *v0 &= ~0x40000u;
  *v0 = *v0 & 0xFFFF0FFF | 0x6000;
  v5 = dword_106DA0;
  *v2 &= ~0x40u;
  v3 -= 129;
  *v2 &= ~0x80u;
  *v3 |= 0x10000000u;
  *v3 = *v3 & 0xFC000FFF | 0x666000;
  *v3 = *v3 & 0xFFFFF000 | 0xC0;
  sub_100560(10);
  v6 = (unsigned int *)off_106DA4;
  v7 = off_106DA8;
  result = (int *)off_106DAC;
  *(_DWORD *)off_106DA4 &= ~2u;
  *v7 |= 0x1000000u;
  v9 = dword_106DB0;
  *v6 = *v6 & 0x8FFFFFFF | 0x20000000;
  *v6 &= 0xF8FFFFFF;
  *v6 = *v6 & 0xFFFFFF8F | 0x40;
  v10 = (int *)off_106DB4;
  *v2 = *v2 & 0xFFF8FFFF | 0x20000;
  *v2 = *v2 & 0xFFFF8FFF | 0x2000;
  *v2 = *v2 & 0xFFFFF0FF | 0x600;
  *result = *result & v9 | 0x351D;
  *result = *result & v5 | 0xF9F0000;
  *v10 = *v10 & v9 | 0x375C;
  *v10 = *v10 & v5 | 0xF9D0000;
  result[2] = result[2] & v9 | 0x35BB;
  result[2] = result[2] & v5 | 0xF060000;
  v10[2] = v10[2] & v9 | 0x3719;
  v10[2] = v10[2] & v5 | 0xF020000;
  v11 = (unsigned int *)off_106DB8;
  result[4] = result[4] & v9 | 0x367A;
  result[4] = result[4] & v5 | 0xECA0000;
  *v11 = *v11 & 0xFFF0FFFF | 0x10000;
  *v11 = *v11 & 0xFFFF0FFF | 0x1000;
  *v11 = *v11 & 0xFFFFF0FF | 0x100;
  *v11 = *v11 & 0xFFFFFF0F | 0x10;
  *v11 = *v11 & 0xFFFFFFF0 | 1;
  *v1 &= ~0x4000u;
  return result;
}

