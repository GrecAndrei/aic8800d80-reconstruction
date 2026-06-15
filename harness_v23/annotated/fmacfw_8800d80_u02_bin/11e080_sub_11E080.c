// v23 annotated: sub_11E080 @ 0x11e080
// Original: 11e080_sub_11E080.c
// Primary struct: <unclustered>
//
// sub_11E080 @ 0x11e080, size 44 bytes
unsigned int __fastcall sub_11E080(int a1)
{
  unsigned int *v1; // r1
  unsigned int result; // r0

  v1 = (unsigned int *)off_11E0B0;
  *(_DWORD *)off_11E0AC = (a1 << 10) & 0x400 | *(_DWORD *)off_11E0AC & 0xFFFFFBFF;
  result = (a1 << 19) & 0x80000 | *v1 & 0xFFF7FFFF;
  *v1 = result;
  return result;
}

