// v23 annotated: ipc_msg_size_compare @ 0x125dc8
// Original: 125dc8_ipc_msg_size_compare.c
// Primary struct: <unclustered>
//
// ipc_msg_size_compare @ 0x125dc8, size 70 bytes
// Doc: ipc_msg_size_compare [ipc]: Compare two IPC message field offsets after lookup
// ipc_msg_size_compare [ipc]: Compare two IPC message field offsets after lookup
BOOL __fastcall ipc_msg_size_compare(int a1, int a2)
{
  int v3; // r4
  int v4; // r0
  int v5; // r5
  int v6; // r6
  int v7; // r0

  v3 = *(_DWORD *)(a1 + 4);
  v4 = sub_1019F0();
  v5 = *(_DWORD *)(a2 + 4);
  v6 = v4;
  v7 = sub_1019F0();
  return v3 - v5 < 0 && v5 - 14000 - v3 - v6 < 0 || v5 - v3 < 0 && v3 - v5 - 14000 - v7 < 0 || v3 == v5;
}

