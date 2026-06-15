// v23 annotated: sub_102F4C @ 0x102f4c
// Original: 102f4c_sub_102F4C.c
// Primary struct: group_21 (cluster 21)
//
// sub_102F4C @ 0x102f4c, size 48 bytes
int sub_102F4C()
{
  __int64 v0; // kr00_8
  int v1; // r4

  v0 = *(_QWORD *)((char *)off_102F7C + 4);
  v1 = *(_DWORD *)off_102F7C;
  sub_102EB8(0, 32, 0x10u, SHIDWORD(v0));
  sub_102EB8(0, 48, 0x10u, v0);
  return sub_102EB8(0, 64, 0x10u, v1);
}

