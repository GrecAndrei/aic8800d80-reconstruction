// fwstruct annotate: 134904_sub_134904.c
// sub_134904 @ 0x134904, size 166 bytes
_DWORD *sub_134904()
{
  char *v0; // r5
  _BYTE *v1; // r8
  int v2; // r9
  int *v3; // r10
  int v4; // r4
  __int64 v5; // r2
  __int16 v6; // lr
  int v7; // r0
  int v8; // r1
  __int64 v9; // r2
  int v10; // r1
  __int64 v11; // r2

  v0 = (char *)off_1349AC;
  v1 = off_1349B4;
  v2 = *((unsigned __int8 *)off_1349AC + 12);
  v3 = *((int **)off_1349B4 + 4);
  v4 = sub_12CB54(4098, 4, 6, 0x178u);
  sub_12ECB0(dword_1349B0);
  sub_12C964(6155, 6);
  v5 = *(_QWORD *)(v0 + 4);
  v0[14] = 0;
  *(_DWORD *)(v4 + 352) = *(_DWORD *)v5;
  LOWORD(v0) = *(_WORD *)(v5 + 4);
  *(_DWORD *)v4 = *(_DWORD *)HIDWORD(v5);
  v6 = *(_WORD *)(HIDWORD(v5) + 4);
  *(_BYTE *)(v4 + 367) = 1;
  v7 = *v3;
  v8 = v3[1];
  v9 = *((_QWORD *)v3 + 1);
  *(_WORD *)(v4 + 356) = (_WORD)v0;
  *(_WORD *)(v4 + 4) = v6;
  *(_DWORD *)(v4 + 252) = v7;
  *(_DWORD *)(v4 + 256) = v8;
  *(_QWORD *)(v4 + 260) = v9;
  v10 = v3[5];
  v11 = *((_QWORD *)v3 + 3);
  *(_DWORD *)(v4 + 268) = v3[4];
  *(_DWORD *)(v4 + 272) = v10;
  *(_QWORD *)(v4 + 276) = v11;
  *(_BYTE *)(v4 + 284) = v3[8];
  *(_BYTE *)(v4 + 368) = 1;
  *(_WORD *)(v4 + 364) = 0;
  *(_DWORD *)(v4 + 360) = 0;
  *(_BYTE *)(v4 + 366) = *((_BYTE *)v3 + 61);
  if ( v2 )
    *(_BYTE *)(v4 + 3) |= 1u;
  v1[32] = v2;
  sub_12CBB4(v4);
  return sub_12CF5C(6u, 2);
}

