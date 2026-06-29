// fwstruct annotate: 102b80_sub_102B80.c
// sub_102B80 @ 0x102b80, size 56 bytes
unsigned int __fastcall sub_102B80(unsigned __int8 a1)
{
  unsigned int *v1; // r1
  unsigned int *v2; // r2
  unsigned __int8 v3; // r0
  unsigned int result; // r0

  v1 = (unsigned int *)off_102BB8;
  v2 = (unsigned int *)off_102BBC;
  *(_DWORD *)off_102BB8 = *(_DWORD *)off_102BB8 & 0xFFFFFF00 | a1;
  *v2 = *v2 & 0xFFFFFF00 | a1;
  v3 = a1 - 3;
  *v1 = *v1 & 0xFFF00FFF | (v3 << 12);
  result = *v2 & 0xFFF00FFF | (v3 << 12);
  *v2 = result;
  return result;
}

