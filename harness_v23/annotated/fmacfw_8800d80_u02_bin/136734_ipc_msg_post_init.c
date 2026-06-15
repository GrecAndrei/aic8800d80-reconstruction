// v23 annotated: ipc_msg_post_init @ 0x136734
// Original: 136734_ipc_msg_post_init.c
// Primary struct: <unclustered>
//
// ipc_msg_post_init @ 0x136734, size 222 bytes
// Doc: ipc_msg_post_init [ipc]: Initialize and post IPC message (msg 0x1c01, len 4)
// ipc_msg_post_init [ipc]: Initialize and post IPC message (msg 0x1c01, len 4)
_DWORD *__fastcall ipc_msg_post_init(int a1)
{
  _DWORD *v1; // r8
  int v3; // r6
  _BYTE *v4; // r4
  char v5; // r3
  int v7; // r7
  int v8; // r0
  int v9; // r9
  __int16 v10; // r2
  int v11; // r3
  int v12; // r12
  int v13; // r1
  int v14; // r2
  int v15; // r3
  int v16; // r7
  char v17; // r3

  v1 = off_136818;
  v3 = *(_DWORD *)off_136818;
  v4 = (_BYTE *)sub_12C92C(7169, 13, 7, 4u);
  if ( a1 )
  {
    v5 = *(_BYTE *)(v3 + 51);
  }
  else
  {
    v7 = *(unsigned __int8 *)(v3 + 51);
    v8 = sub_12C92C(30, 0, 7, 4u);
    v9 = dword_136814 + 1320 * v7;
    *(_BYTE *)(v8 + 2) = 1;
    *(_BYTE *)(v8 + 3) = *(_BYTE *)(v9 + 107);
    sdio_buffer_prepare_n_4e8(v8);
    v10 = *(_WORD *)(v3 + 48);
    v11 = *(_DWORD *)(v9 + 72);
    *(_DWORD *)(v9 + 1208) = *(_DWORD *)(v3 + 44);
    *(_WORD *)(v9 + 236) = v10;
    *(_BYTE *)(v9 + 234) = 0;
    v4[2] = *(_BYTE *)(v11 + 24);
    v12 = dword_13681C;
    v4[3] = *(_BYTE *)(v3 + 51) + 32;
    v13 = *(_DWORD *)(v3 + 4);
    v14 = *(_DWORD *)(v3 + 8);
    v15 = *(_DWORD *)(v3 + 12);
    v16 = v12 + 696 * (v7 + 32);
    *(_DWORD *)(v16 + 192) = *(_DWORD *)v3;
    *(_DWORD *)(v16 + 196) = v13;
    *(_DWORD *)(v16 + 200) = v14;
    *(_BYTE *)(v16 + 52) = 2;
    *(_BYTE *)(v16 + 204) = v15;
    sub_13289C(v16);
    v17 = *(_BYTE *)(v16 + 350);
    *(_WORD *)(v16 + 38) = 1;
    *(_BYTE *)(v16 + 350) = v17 | 0x10;
    v5 = *(_BYTE *)(v3 + 51);
    *(_BYTE *)(v16 + 37) = 1;
    *(_BYTE *)(v16 + 35) = v5 + 32;
  }
  v4[1] = v5;
  *v4 = a1;
  sdio_buffer_prepare_n_4e8((int)v4);
  sub_12CA38(v3 - 12);
  *v1 = 0;
  return sub_12CD34(7u, 0);
}

