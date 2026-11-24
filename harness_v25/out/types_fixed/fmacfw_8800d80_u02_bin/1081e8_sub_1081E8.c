// sub_1081E8 @ 0x1081e8, size 60 bytes
int sub_1081E8()
{
  unsigned int *v0; // r5
  unsigned int v1; // r4
  int v2; // r6
  int result; // r0
  _DWORD *v4; // r2

  v0 = (unsigned int *)off_108228;
  v1 = *(_DWORD *)off_108228;
  v2 = *(_DWORD *)off_108224 >> 20;
  result = feature_guard_check(1, dword_10822C);
  v4 = off_108234;
  *v0 = dword_108230 & (((HIWORD(v1) & 0xFFF) + v2) << 16) | *v0 & 0xF000FFFF;
  *v4 |= 0x800000u;
  return result;
}

