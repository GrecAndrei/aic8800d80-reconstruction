// v23 annotated: sub_10DB90 @ 0x10db90
// Original: 10db90_sub_10DB90.c
// Primary struct: rf_subsys (cluster 9, 12 funcs)
// Fields: base=0x8, cfg=0xc
//
// sub_10DB90 @ 0x10db90, size 16 bytes
int __fastcall sub_10DB90(char a1)
{
  int result; // r0

  result = (1 << a1) | *((_DWORD *)off_10DBA0 + 2);
  *((_DWORD *)off_10DBA0 + 2) = result;
  return result;
}

