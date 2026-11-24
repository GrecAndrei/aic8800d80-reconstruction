// sub_110100 @ 0x110100, size 122 bytes
// Doc: message_dispatch_n72 [ipc]: Dispatches incoming IPC messages by type id (switch on msg id 0xd)
// message_dispatch_n72 [ipc]: Dispatches incoming IPC messages by type id (switch on msg id 0xd)
int sub_110100()
{
  void *v0; // r4
  int v1; // r3
  _DWORD *v2; // r0
  __int16 v3; // r2
  __int16 v4; // r1
  __int64 v5; // kr00_8
  _WORD *(_DWORD *)(v7 + 0x8); // [sp+4h] [bp-14h] BYREF
  _WORD *(_DWORD *)(v8 + 0x20); // [sp+8h] [bp-10h] BYREF

  v0 = log_free_dispatch_n174;
  v1 = *(_DWORD *)log_free_dispatch_n174;
  v2 = log_free_dispatch_0184;
  v3 = *((_WORD *)log_free_dispatch_n178 + 153);
  v4 = *((_WORD *)log_free_dispatch_n178 + 154) - 4;
  *(_DWORD *)(v7 + 0x4) = *(_WORD *)(*(_DWORD *)log_free_dispatch_n174 + 2);
  *(_DWORD *)(v8 + 0x4) = *(_WORD *)(v1 + 4);
  *(_DWORD *)(v8 + 0x14) = *(_WORD *)(v1 + 6);
  *(_DWORD *)(v8 + 0x1c) = *(_WORD *)(v1 + 8);
  v5 = *(_QWORD *)(v1 + 20);
  *(_DWORD *)log_free_dispatch_0184 = v5;
  *(_DWORD *)(v2 + 0xc) = log_free_dispatch_n180;
  *(_DWORD *)(v2 + 0x4) = HIDWORD(v5);
  *((_BYTE *)v2 + 8) = 1;
  *(_DWORD *)(v8 + 0x8) = v4;
  *(_DWORD *)(v8 + 0x18) = v3 - 4;
  *(_DWORD *)(v7 + 0x0) = 12;
  *(_DWORD *)(v8 + 0x10) = 1596;
  *(_DWORD *)(v8 + 0x0) = 124;
  *(_DWORD *)(v8 + 0xc) = 0;
  sub_10F924(v2, (int)v7, 0x20u);
  return fmac_msg_post((int)v8, *(_DWORD *)(*(_DWORD *)v0 + 28), *(_DWORD *)(*(_DWORD *)v0 + 32));
}

