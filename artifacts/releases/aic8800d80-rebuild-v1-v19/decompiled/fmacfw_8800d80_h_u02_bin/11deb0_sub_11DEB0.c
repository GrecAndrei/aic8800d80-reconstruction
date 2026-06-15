// sub_11DEB0 @ 0x11deb0, size 100 bytes
int sub_11DEB0()
{
  int *v0; // r2
  int v1; // r0
  _DWORD *v2; // r1
  _DWORD *v3; // r12
  __int64 v4; // kr00_8
  _DWORD *v5; // r5
  _DWORD *v6; // r5
  int v7; // r1
  __int64 v8; // kr08_8
  _DWORD *v9; // lr
  _DWORD *v10; // r7
  int *v12; // r4
  int v13; // r6
  int v14; // r3

  v0 = (int *)off_11DF18;
  v1 = *(_DWORD *)off_11DF14;
  v2 = off_11DF1C;
  v3 = off_11DF38;
  v4 = *(_QWORD *)*(_DWORD *)off_11DF14;
  v5 = off_11DF20;
  *(_DWORD *)off_11DF18 = v4;
  *v5 = v4;
  *v2 = HIDWORD(v4) + v4 - 4;
  v6 = off_11DF28;
  v7 = *v0;
  *(_DWORD *)off_11DF24 = *v0;
  *v6 = v7;
  v8 = *(_QWORD *)(v1 + 8);
  v9 = off_11DF3C;
  v10 = off_11DF2C;
  v0[1] = HIDWORD(v4) + v4;
  v6[1] = v8;
  v12 = (int *)off_11DF30;
  v0[2] = v4;
  v13 = dword_11DF34;
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

