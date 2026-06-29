// sub_10E2E8 @ 0x10e2e8, size 252 bytes
int sub_10E2E8()
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

  v0 = off_10E408;
  sub_10DBF4(1);
  v0[1] = 1;
  while ( v0[7] != 1 )
    ;
  v0[7] = 1;
  v1 = sub_12752C(v0[4]);
  v2 = sub_127620(v1, HIDWORD(v1), dword_10E3E8, dword_10E3EC);
  v3 = sub_127874(v2, HIDWORD(v2), dword_10E3F0, dword_10E3F4);
  v4 = sub_1272B0(v3, HIDWORD(v3), dword_10E3E8, dword_10E3EC);
  v5 = ((int ( *)(int))sub_127BE4)(v4);
  sub_10DBF4(2);
  v6 = off_10E408;
  v0[1] = 1;
  while ( v6[7] != 1 )
    ;
  v6[7] = 1;
  v7 = v6[4];
  sub_10DBF4(3);
  v8 = sub_12752C(v7);
  v9 = sub_127620(v8, HIDWORD(v8), dword_10E3E8, dword_10E3EC);
  v10 = sub_127874(v9, HIDWORD(v9), dword_10E3F0, dword_10E3F4);
  v11 = sub_1272B0(v10, HIDWORD(v10), dword_10E3E8, dword_10E3EC);
  v12 = ((int ( *)(int))sub_127BE4)(v11);
  v13 = sub_127570(v12);
  v14 = sub_127874(v13, HIDWORD(v13), dword_10E3F8, dword_10E3FC);
  v15 = sub_127620(v14, HIDWORD(v14), 0, dword_10E40C);
  v16 = sub_127570(v5);
  v17 = sub_127874(v16, HIDWORD(v16), dword_10E3F8, dword_10E3FC);
  v18 = sub_127620(v17, HIDWORD(v17), 0, dword_10E410);
  v19 = sub_1272B4(v15, HIDWORD(v15), v18, HIDWORD(v18));
  v20 = sub_127620(v19, HIDWORD(v19), 0, dword_10E414);
  v21 = sub_127620(v20, HIDWORD(v20), dword_10E400, dword_10E404);
  v22 = sub_127874(v21, HIDWORD(v21), 0, dword_10E418);
  return (int)sub_127BE4(v22);
}

