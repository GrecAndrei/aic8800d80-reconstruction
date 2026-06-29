// sub_10DF08 @ 0x10df08, size 252 bytes
// Doc: sub_120DF08 [unknown]: Unknown firmware helper at 0x120df08
// sub_120DF08 [unknown]: Unknown firmware helper at 0x120df08
int sub_10DF08()
{
  uint32_t *v0; // r5
  uint64_t v1; // r0
  uint64_t v2; // r0
  uint64_t v3; // r0
  int v4; // r0
  int v5; // r6
  uint32_t *v6; // r2
  int v7; // r4
  uint64_t v8; // r0
  uint64_t v9; // r0
  uint64_t v10; // r0
  int v11; // r0
  int v12; // r0
  uint64_t v13; // r0
  uint64_t v14; // r0
  uint64_t v15; // r4
  uint64_t v16; // r0
  uint64_t v17; // r0
  uint64_t v18; // r0
  uint64_t v19; // r0
  uint64_t v20; // r0
  uint64_t v21; // r0
  int v22; // r0

  v0 = off_10E028;
  sub_10DD70(1);
  v0[1] = 1;
  while ( v0[7] != 1 )
    ;
  v0[7] = 1;
  v1 = sub_142A50(v0[4]);
  v2 = sub_142B44(v1, HIDWORD(v1), dword_10E008, dword_10E00C);
  v3 = sub_142D98(v2, HIDWORD(v2), dword_10E010, dword_10E014);
  v4 = sub_1427D4(v3, HIDWORD(v3), dword_10E008, dword_10E00C);
  v5 = ((int ( *)(int))sub_143108)(v4);
  sub_10DD70(2);
  v6 = off_10E028;
  v0[1] = 1;
  while ( v6[7] != 1 )
    ;
  v6[7] = 1;
  v7 = v6[4];
  sub_10DD70(3);
  v8 = sub_142A50(v7);
  v9 = sub_142B44(v8, HIDWORD(v8), dword_10E008, dword_10E00C);
  v10 = sub_142D98(v9, HIDWORD(v9), dword_10E010, dword_10E014);
  v11 = sub_1427D4(v10, HIDWORD(v10), dword_10E008, dword_10E00C);
  v12 = ((int ( *)(int))sub_143108)(v11);
  v13 = sub_142A94(v12);
  v14 = sub_142D98(v13, HIDWORD(v13), dword_10E018, dword_10E01C);
  v15 = sub_142B44(v14, HIDWORD(v14), 0, dword_10E02C);
  v16 = sub_142A94(v5);
  v17 = sub_142D98(v16, HIDWORD(v16), dword_10E018, dword_10E01C);
  v18 = sub_142B44(v17, HIDWORD(v17), 0, dword_10E030);
  v19 = sub_1427D8(v15, HIDWORD(v15), v18, HIDWORD(v18));
  v20 = sub_142B44(v19, HIDWORD(v19), 0, dword_10E034);
  v21 = sub_142B44(v20, HIDWORD(v20), dword_10E020, dword_10E024);
  v22 = sub_142D98(v21, HIDWORD(v21), 0, dword_10E038);
  return (int)sub_143108(v22);
}

