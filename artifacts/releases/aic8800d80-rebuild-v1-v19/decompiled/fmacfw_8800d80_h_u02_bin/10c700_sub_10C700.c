// sub_10C700 @ 0x10c700, size 166 bytes
int *sub_10C700()
{
  unsigned int *v0; // r3
  unsigned int *v1; // r2
  int *result; // r0
  int v3; // r4

  v0 = (unsigned int *)off_10C7A8;
  v1 = (unsigned int *)off_10C7AC;
  result = (int *)off_10C7B0;
  *(_DWORD *)off_10C7A8 = *(_DWORD *)off_10C7A8 & 0xFFFFFFFC | 2;
  v3 = dword_10C7B4;
  *v0 = *v0 & 0xFFFFFFF3 | 8;
  *v0 = *v0 & 0xFFFFFCFF | 0x200;
  *v0 = *v0 & 0xFFFFF3FF | 0x800;
  *v0 = *v0 & 0xFFFFCFFF | 0x2000;
  *v1 = *v1 & 0xFCFFFFFF | 0x2000000;
  *v1 = *v1 & 0xF3FFFFFF | 0x8000000;
  *v1 = *v1 & 0xCFFFFFFF | 0x20000000;
  *v1 = *v1 & 0x3FFFFFFF | 0x80000000;
  *v0 |= 0x30000u;
  *v0 |= 0xC0000u;
  *v0 |= 0x300000u;
  *v0 |= 0xC00000u;
  *v0 |= 0x3000000u;
  *result = v3;
  return result;
}

