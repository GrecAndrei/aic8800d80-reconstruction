// sub_10DF70 @ 0x10df70, size 252 bytes
int sub_10DF70()
{
  _DWORD *v0; // r5
  __int64 v1; // r0
  __int64 v2; // r0
  __int64 v3; // r0
  int v4; // r0
  int v5; // r6
  _DWORD *v6; // r2
  int v7; // r4
  __int64 v8; // r0
  __int64 v9; // r0
  __int64 v10; // r0
  int v11; // r0
  int v12; // r0
  __int64 v13; // r0
  __int64 v14; // r0
  __int64 v15; // r4
  __int64 v16; // r0
  __int64 v17; // r0
  __int64 v18; // r0
  __int64 v19; // r0
  __int64 v20; // r0
  __int64 v21; // r0
  int v22; // r0

  v0 = off_10E090;
  sub_10DDD8(1);
  v0[1] = 1;
  while ( v0[7] != 1 )
    ;
  v0[7] = 1;
  v1 = sub_142874(v0[4]);
  v2 = sub_142968(v1, HIDWORD(v1), dword_10E070, dword_10E074);
  v3 = sub_142BBC(v2, HIDWORD(v2), dword_10E078, dword_10E07C);
  v4 = sub_1425F8(v3, HIDWORD(v3), dword_10E070, dword_10E074);
  v5 = ((int (__fastcall *)(int))sub_142F2C)(v4);
  sub_10DDD8(2);
  v6 = off_10E090;
  v0[1] = 1;
  while ( v6[7] != 1 )
    ;
  v6[7] = 1;
  v7 = v6[4];
  sub_10DDD8(3);
  v8 = sub_142874(v7);
  v9 = sub_142968(v8, HIDWORD(v8), dword_10E070, dword_10E074);
  v10 = sub_142BBC(v9, HIDWORD(v9), dword_10E078, dword_10E07C);
  v11 = sub_1425F8(v10, HIDWORD(v10), dword_10E070, dword_10E074);
  v12 = ((int (__fastcall *)(int))sub_142F2C)(v11);
  v13 = sub_1428B8(v12);
  v14 = sub_142BBC(v13, HIDWORD(v13), dword_10E080, dword_10E084);
  v15 = sub_142968(v14, HIDWORD(v14), 0, dword_10E094);
  v16 = sub_1428B8(v5);
  v17 = sub_142BBC(v16, HIDWORD(v16), dword_10E080, dword_10E084);
  v18 = sub_142968(v17, HIDWORD(v17), 0, dword_10E098);
  v19 = sub_1425FC(v15, HIDWORD(v15), v18, HIDWORD(v18));
  v20 = sub_142968(v19, HIDWORD(v19), 0, dword_10E09C);
  v21 = sub_142968(v20, HIDWORD(v20), dword_10E088, dword_10E08C);
  v22 = sub_142BBC(v21, HIDWORD(v21), 0, dword_10E0A0);
  return (int)sub_142F2C(v22);
}

