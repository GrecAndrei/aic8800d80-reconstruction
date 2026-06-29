// sub_143A18 @ 0x143a18, size 46 bytes
int sub_143A18()
{
  unsigned uint64_t v0; // kr00_8

  v0 = *(QWORD *)(*(uint32_t *)off_143A48 + 168) * __PAIR64__(dword_143A4C, dword_143A50) + 1;
  *(QWORD *)(*(uint32_t *)off_143A48 + 168) = v0;
  return HIDWORD(v0) & 0x7FFFFFFF;
}

