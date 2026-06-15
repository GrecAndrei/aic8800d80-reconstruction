// v23 annotated: sub_1029DC @ 0x1029dc
// Original: 1029dc_sub_1029DC.c
// Primary struct: <unclustered>
//
// sub_1029DC @ 0x1029dc, size 56 bytes
unsigned int __fastcall sub_1029DC(unsigned __int8 a1)
{
  unsigned int *v1; // r1
  unsigned int *v2; // r2
  unsigned __int8 v3; // r0
  unsigned int result; // r0

  v1 = (unsigned int *)off_102A14;
  v2 = (unsigned int *)off_102A18;
  *(_DWORD *)off_102A14 = *(_DWORD *)off_102A14 & 0xFFFFFF00 | a1;
  *v2 = *v2 & 0xFFFFFF00 | a1;
  v3 = a1 - 3;
  *v1 = *v1 & 0xFFF00FFF | (v3 << 12);
  result = *v2 & 0xFFF00FFF | (v3 << 12);
  *v2 = result;
  return result;
}

