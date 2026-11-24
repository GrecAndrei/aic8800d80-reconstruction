// sub_1346E8 @ 0x1346e8, size 166 bytes
_DWORD *sub_1346E8()
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

  v0 = (char *)off_134790;
  v1 = off_134798;
  v2 = *((unsigned __int8 *)off_134790 + 12);
  v3 = *((int **)off_134798 + 4);
  v4 = sub_12C92C(4098, 4, 6, 0x178u);
  msg_parse(dword_134794);
  event_queue_push(6155, 6);
  v5 = *(_QWORD *)(v0 + 4);
  *(_DWORD *)(v0 + 0x38) = 0;
  *(_DWORD *)(v4 + 352) = *(_DWORD *)v5;
  LOWORD(v0) = *(_WORD *)(v5 + 4);
  *(_DWORD *)v4 = *(_DWORD *)HIDWORD(v5);
  v6 = *(_WORD *)(HIDWORD(v5) + 4);
  *(_BYTE *)(v4 + 367) = 1;
  v7 = *v3;
  v8 = *(_DWORD *)(v3 + 0x4);
  v9 = *((_QWORD *)v3 + 1);
  *(_WORD *)(v4 + 356) = (_WORD)v0;
  *(_WORD *)(v4 + 4) = v6;
  *(_DWORD *)(v4 + 252) = v7;
  *(_DWORD *)(v4 + 256) = v8;
  *(_QWORD *)(v4 + 260) = v9;
  v10 = *(_DWORD *)(v3 + 0x14);
  v11 = *((_QWORD *)v3 + 3);
  *(_DWORD *)(v4 + 268) = *(_DWORD *)(v3 + 0x10);
  *(_DWORD *)(v4 + 272) = v10;
  *(_QWORD *)(v4 + 276) = v11;
  *(_BYTE *)(v4 + 284) = *(_DWORD *)(v3 + 0x20);
  *(_BYTE *)(v4 + 368) = 1;
  *(_WORD *)(v4 + 364) = 0;
  *(_DWORD *)(v4 + 360) = 0;
  *(_BYTE *)(v4 + 366) = *((_BYTE *)v3 + 61);
  if ( v2 )
    *(_BYTE *)(v4 + 3) |= 1u;
  *(_DWORD *)(v1 + 0x80) = v2;
  sdio_buffer_prepare_n_4e8(v4);
  return sub_12CD34(6u, 2);
}

