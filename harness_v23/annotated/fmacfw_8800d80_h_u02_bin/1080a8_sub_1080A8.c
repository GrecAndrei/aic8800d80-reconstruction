// v23 annotated: sub_1080A8 @ 0x1080a8
// Original: 1080a8_sub_1080A8.c
// Primary struct: <unclustered>
//
// sub_1080A8 @ 0x1080a8, size 60 bytes
int sub_1080A8()
{
  unsigned int *v0; // r5
  unsigned int v1; // r4
  int v2; // r6
  int result; // r0
  _DWORD *v4; // r2

  v0 = (unsigned int *)off_1080E8;
  v1 = *(_DWORD *)off_1080E8;
  v2 = *(_DWORD *)off_1080E4 >> 20;
  result = sub_12EB90(1, dword_1080EC);
  v4 = off_1080F4;
  *v0 = dword_1080F0 & (((HIWORD(v1) & 0xFFF) + v2) << 16) | *v0 & 0xF000FFFF;
  *v4 |= 0x800000u;
  return result;
}

