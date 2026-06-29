// sub_14383C @ 0x14383c, size 46 bytes
int sub_14383C()
{
  unsigned uint64_t v0; // kr00_8

  v0 = *(QWORD *)(*(uint32_t *)off_14386C + 168) * __PAIR64__(dword_143870, dword_143874) + 1;
  *(QWORD *)(*(uint32_t *)off_14386C + 168) = v0;
  return HIDWORD(v0) & 0x7FFFFFFF;
}

