// fwstruct annotate: 1029f8_sub_1029F8.c
// sub_1029F8 @ 0x1029f8, size 56 bytes
unsigned int __fastcall sub_1029F8(unsigned __int8 a1)
{
  unsigned int *v1; // r1
  unsigned int *v2; // r2
  unsigned __int8 v3; // r0
  unsigned int result; // r0

  v1 = (unsigned int *)off_102A30;
  v2 = (unsigned int *)off_102A34;
  *(_DWORD *)off_102A30 = *(_DWORD *)off_102A30 & 0xFFFFFF00 | a1;
  *v2 = *v2 & 0xFFFFFF00 | a1;
  v3 = a1 - 3;
  *v1 = *v1 & 0xFFF00FFF | (v3 << 12);
  result = *v2 & 0xFFF00FFF | (v3 << 12);
  *v2 = result;
  return result;
}

