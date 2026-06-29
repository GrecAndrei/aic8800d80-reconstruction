// fwstruct annotate: 14397c_sub_14397C.c
// sub_14397C @ 0x14397c, size 46 bytes
int sub_14397C()
{
  unsigned __int64 v0; // kr00_8

  v0 = *(_QWORD *)(*(_DWORD *)off_1439AC + 168) * __PAIR64__(dword_1439B0, dword_1439B4) + 1;
  *(_QWORD *)(*(_DWORD *)off_1439AC + 168) = v0;
  return HIDWORD(v0) & 0x7FFFFFFF;
}

