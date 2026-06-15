// v23 annotated: sub_107370 @ 0x107370
// Original: 107370_sub_107370.c
// Primary struct: <unclustered>
//
// sub_107370 @ 0x107370, size 96 bytes
_DWORD *sub_107370()
{
  unsigned int *v0; // r2
  _DWORD *v1; // r3
  _DWORD *result; // r0

  v0 = (unsigned int *)off_1073D0;
  v1 = off_1073D4;
  result = off_1073D8;
  *(_DWORD *)off_1073D0 = *(_DWORD *)off_1073D0 & 0xC0FFFFFF | 0x3000000;
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

