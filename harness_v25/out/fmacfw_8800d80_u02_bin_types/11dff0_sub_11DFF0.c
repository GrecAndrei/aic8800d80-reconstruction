// sub_11DFF0 @ 0x11dff0, size 100 bytes
int sub_11DFF0()
{
  int *v0; // r2
  int v1; // r0
  uint32_t *v2; // r1
  uint32_t *v3; // r12
  uint64_t v4; // kr00_8
  uint32_t *v5; // r5
  uint32_t *v6; // r5
  int v7; // r1
  uint64_t v8; // kr08_8
  uint32_t *v9; // lr
  uint32_t *v10; // r7
  int *v12; // r4
  int v13; // r6
  int v14; // r3

  v0 = (int *)off_11E058;
  v1 = *(uint32_t *)off_11E054;
  v2 = off_11E05C;
  v3 = off_11E078;
  v4 = *(QWORD *)*(uint32_t *)off_11E054;
  v5 = off_11E060;
  *(uint32_t *)off_11E058 = v4;
  *v5 = v4;
  *v2 = HIDWORD(v4) + v4 - 4;
  v6 = off_11E068;
  v7 = *v0;
  *(uint32_t *)off_11E064 = *v0;
  *v6 = v7;
  v8 = *(QWORD *)(v1 + 8);
  v9 = off_11E07C;
  v10 = off_11E06C;
  v0[1] = HIDWORD(v4) + v4;
  v6[1] = v8;
  v12 = (int *)off_11E070;
  v0[2] = v4;
  v13 = dword_11E074;
  *v9 = HIDWORD(v8) + v8 - 4;
  *v3 = v8;
  *v10 = v8;
  v6[5] = v13;
  v14 = *v12;
  v0[4] = HIDWORD(v8) + v8;
  v0[3] = v8;
  v0[5] = v8;
  *v12 = v14 & 0x80000 | 0x78025;
  return HIDWORD(v8) + v8;
}

