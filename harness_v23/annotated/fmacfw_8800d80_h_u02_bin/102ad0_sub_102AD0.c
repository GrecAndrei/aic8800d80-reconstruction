// v23 annotated: sub_102AD0 @ 0x102ad0
// Original: 102ad0_sub_102AD0.c
// Primary struct: <unclustered>
//
// sub_102AD0 @ 0x102ad0, size 56 bytes
unsigned int __fastcall sub_102AD0(unsigned __int8 a1)
{
  unsigned int *v1; // r1
  unsigned int *v2; // r2
  unsigned __int8 v3; // r0
  unsigned int result; // r0

  v1 = (unsigned int *)off_102B08;
  v2 = (unsigned int *)off_102B0C;
  *(_DWORD *)off_102B08 = *(_DWORD *)off_102B08 & 0xFFFFFF00 | a1;
  *v2 = *v2 & 0xFFFFFF00 | a1;
  v3 = a1 - 3;
  *v1 = *v1 & 0xFFF00FFF | (v3 << 12);
  result = *v2 & 0xFFF00FFF | (v3 << 12);
  *v2 = result;
  return result;
}

