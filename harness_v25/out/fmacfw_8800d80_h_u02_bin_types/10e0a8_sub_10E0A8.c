// sub_10E0A8 @ 0x10e0a8, size 130 bytes
int sub_10E0A8()
{
  uint32_t *v0; // r2
  uint64_t v1; // r0
  uint64_t v2; // r0
  uint64_t v3; // r0
  int v4; // r0
  float v5; // r0
  uint64_t v6; // r0
  uint64_t v7; // r0
  uint64_t v8; // r0
  uint64_t v9; // r0
  uint64_t v10; // r0
  int v11; // r0

  v0 = off_10E150;
  *((uint32_t *)off_10E150 + 1) = 1;
  while ( v0[7] != 1 )
    ;
  v0[7] = 1;
  v1 = sub_142874(v0[4]);
  v2 = sub_142968(v1, HIDWORD(v1), dword_10E130, dword_10E134);
  v3 = sub_142BBC(v2, HIDWORD(v2), dword_10E138, dword_10E13C);
  v4 = sub_1425F8(v3, HIDWORD(v3), dword_10E130, dword_10E134);
  v5 = sub_142F2C(v4);
  v6 = sub_1428B8(LODWORD(v5));
  v7 = sub_142BBC(v6, HIDWORD(v6), dword_10E140, dword_10E144);
  v8 = sub_142968(v7, HIDWORD(v7), 0, dword_10E154);
  v9 = sub_142968(v8, HIDWORD(v8), 0, dword_10E158);
  v10 = sub_142968(v9, HIDWORD(v9), dword_10E148, dword_10E14C);
  v11 = sub_142BBC(v10, HIDWORD(v10), 0, dword_10E15C);
  return (int)sub_142F2C(v11);
}

