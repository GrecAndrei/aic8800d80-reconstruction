// bt_hci_cmd_build_n6ac @ 0x12c6ac, size 64 bytes
// Doc: message_dispatch_n_4d7 [ipc]: Handle a dispatched message, combining status fields and tail-calling the next handler.
// message_dispatch_n_4d7 [ipc]: Handle a dispatched message, combining status fields and tail-calling the next handler.
int __fastcall bt_hci_cmd_build_n6ac(char a1)
{
  int result; // r0
  unsigned int *v2; // r2
  _BYTE *(_DWORD *)(v3 + 0x1c); // [sp+7h] [bp-Dh] BYREF
  unsigned __int8 v4; // [sp+Eh] [bp-6h] BYREF
  _BYTE *(_DWORD *)(v5 + 0x14); // [sp+Fh] [bp-5h] BYREF

  *(_DWORD *)(v3 + 0x0) = a1;
  result = sub_10197C((int)v3, &v4, v5);
  v2 = (unsigned int *)message_dispatch_lookup_n_4c7;
  *(_DWORD *)message_dispatch_lookup_n_4c7 = *(_DWORD *)message_dispatch_lookup_n_4c7 & 0xFFFF00FF | (v4 << 8);
  *v2 = *v2 & 0xFFFFFF00 | *(_DWORD *)(v5 + 0x0);
  return result;
}

