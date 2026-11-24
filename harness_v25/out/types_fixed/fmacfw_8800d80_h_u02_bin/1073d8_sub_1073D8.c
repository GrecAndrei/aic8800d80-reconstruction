// sub_1073D8 @ 0x1073d8, size 96 bytes
_DWORD *sub_1073D8()
{
  unsigned int *v0; // r2
  _DWORD *v1; // r3
  _DWORD *result; // r0

  v0 = (unsigned int *)off_107438;
  v1 = off_10743C;
  result = off_107440;
  *(_DWORD *)off_107438 = *(_DWORD *)off_107438 & 0xC0FFFFFF | 0x3000000;
  *v0 = *v0 & 0xFFC0FFFF | 0x30000;
  *v0 = *v0 & 0xFFFFC0FF | 0x300;
  *v0 = *v0 & 0xFFFFFFC0 | 3;
  *v1 &= 0xC0FFFFFF;
  *v1 &= 0xFFC0FFFF;
  *v1 &= 0xFFFFC0FF;
  *v1 &= 0xFFFFFFC0;
  *result &= 0xFFFFFFC0;
  return result;
}

