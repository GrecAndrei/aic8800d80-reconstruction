// fwstruct annotate: 141e38_ipc_msg_send_header.c
// ipc_msg_send_header @ 0x141e38, size 50 bytes
// Doc: ipc_msg_send_header [ipc]: Builds and sends IPC message header (id=0x3002, len=0xc) to target
// ipc_msg_send_header [ipc]: Builds and sends IPC message header (id=0x3002, len=0xc) to target
int __fastcall ipc_msg_send_header(char a1, int a2)
{
  int v4; // r0
  __int16 v5; // r2

  v4 = rf_bus_setup_n3a8(12290, 13, 12, 8u);
  v5 = *(_WORD *)(a2 + 8);
  *(_DWORD *)(v4 + 2) = *(_DWORD *)(a2 + 4);
  *(_WORD *)(v4 + 6) = v5;
  *(_BYTE *)(v4 + 1) = *(_BYTE *)(a2 + 46);
  *(_BYTE *)v4 = a1;
  return sub_12CBB4(v4);
}

