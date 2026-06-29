// fwstruct annotate: 11e430_init_global_table_121E430.c
// init_global_table_121E430 @ 0x11e430, size 100 bytes
// Doc: init_global_table_121E430 [util]: Loads shared globals and prepares a context struct
// init_global_table_121E430 [util]: Loads shared globals and prepares a context struct
int init_global_table_121E430()
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

  v0 = (int *)off_11E498;
  v1 = *(_DWORD *)off_11E494;
  v2 = off_11E49C;
  v3 = off_11E4B8;
  v4 = *(_QWORD *)*(_DWORD *)off_11E494;
  v5 = off_11E4A0;
  *(_DWORD *)off_11E498 = v4;
  *v5 = v4;
  *v2 = HIDWORD(v4) + v4 - 4;
  v6 = off_11E4A8;
  v7 = *v0;
  *(_DWORD *)off_11E4A4 = *v0;
  *v6 = v7;
  v8 = *(_QWORD *)(v1 + 8);
  v9 = off_11E4BC;
  v10 = off_11E4AC;
  v0[1] = HIDWORD(v4) + v4;
  v6[1] = v8;
  v12 = (int *)off_11E4B0;
  v0[2] = v4;
  v13 = dword_11E4B4;
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

