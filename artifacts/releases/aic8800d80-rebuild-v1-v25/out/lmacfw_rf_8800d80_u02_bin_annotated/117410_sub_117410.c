// fwstruct annotate: 117410_sub_117410.c
// sub_117410 @ 0x117410, size 118 bytes
int sub_117410()
{
  int v0; // r3
  _DWORD *v1; // r2
  _DWORD *v2; // r12
  int *v3; // r5
  _DWORD *v4; // r4
  _DWORD *v5; // r8
  _DWORD *v6; // lr
  _DWORD *v7; // r7
  int v8; // r3
  _DWORD *v9; // r6
  _DWORD *v10; // r5
  int v11; // r3
  __int64 v12; // r0

  v0 = dword_117488;
  v1 = off_11748C;
  HIDWORD(v12) = dword_117490;
  v2 = off_1174AC;
  v3 = (int *)off_117494;
  v4 = off_117498;
  *(_DWORD *)off_11748C = dword_117488;
  LODWORD(v12) = v0 + 24832;
  *v3 = v0;
  *v4 = v0 + 24884;
  v5 = off_1174B0;
  v6 = off_1174B4;
  v1[2] = v0;
  v7 = off_11749C;
  v8 = *v1;
  v9 = off_1174A0;
  *v5 = *v1;
  *v6 = v8;
  *v2 = HIDWORD(v12);
  v10 = off_1174A4;
  *v7 = HIDWORD(v12) + 664;
  *v9 = HIDWORD(v12);
  v4[6] = HIDWORD(v12);
  v4 -= 0x2000;
  *v10 = dword_1174A8;
  v11 = *(_DWORD *)((char *)v4 + 0xFFFFFF40);
  v1[3] = HIDWORD(v12);
  v1[1] = v12 + 56;
  LODWORD(v12) = HIDWORD(v12) + 668;
  *((_QWORD *)v1 + 2) = v12;
  *(v4 - 48) = v11 & 0x80000 | 0x78025;
  return v12;
}

