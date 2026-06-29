// fwstruct annotate: 102e9c_sub_102E9C.c
// sub_102E9C @ 0x102e9c, size 48 bytes
int sub_102E9C()
{
  __int64 v0; // kr00_8
  int v1; // r4

  v0 = *(_QWORD *)((char *)off_102ECC + 4);
  v1 = *(_DWORD *)off_102ECC;
  sub_102E08(0, 32, 0x10u, SHIDWORD(v0));
  sub_102E08(0, 48, 0x10u, v0);
  return sub_102E08(0, 64, 0x10u, v1);
}

