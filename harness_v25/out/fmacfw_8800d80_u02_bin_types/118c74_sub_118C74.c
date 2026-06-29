// sub_118C74 @ 0x118c74, size 94 bytes
int  sub_118C74(int a1, int a2)
{
  uint64_t v2; // kr00_8
  int v3; // r2
  int v6; // r12
  int v7; // r3
  char v8; // r2

  v2 = *(QWORD *)(a1 + 72);
  v3 = *(uint32_t *)(HIDWORD(v2) + 28);
  if ( **(__int16 **)off_118CD4 < 0 && (v3 & 1) != 0 )
  {
    sub_12F46C(dword_118CDC, dword_118CD8, 389);
    v3 = *(uint32_t *)(HIDWORD(v2) + 28);
  }
  v6 = *(uint32_t *)(HIDWORD(v2) + 44);
  *(uint32_t *)(HIDWORD(v2) + 68) &= 0xFF87FFFF;
  v7 = 0;
  *(QWORD *)(HIDWORD(v2) + 16) = 0;
  v8 = *(uint8_t *)(v3 + 4);
  *(uint32_t *)(HIDWORD(v2) + 72) = 0;
  if ( (v8 & 1) == 0 )
    v7 = 512;
  *(uint32_t *)(HIDWORD(v2) + 64) = v7;
  *(uint32_t *)(v2 + 96) = v7;
  *(uint32_t *)(v2 + 100) = v6;
  return sub_1176A0(a1, a2);
}

