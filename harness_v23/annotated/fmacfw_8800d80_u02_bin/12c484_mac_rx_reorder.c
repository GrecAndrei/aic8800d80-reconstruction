// v23 annotated: mac_rx_reorder @ 0x12c484
// Original: 12c484_mac_rx_reorder.c
// Primary struct: <unclustered>
//
// mac_rx_reorder @ 0x12c484, size 64 bytes
// Doc: message_dispatch_n_4e6 [ipc]: Dispatch message via MMIO with byte lane writes
// message_dispatch_n_4e6 [ipc]: Dispatch message via MMIO with byte lane writes
int __fastcall mac_rx_reorder(char a1)
{
  int result; // r0
  unsigned int *v2; // r2
  _BYTE v3[7]; // [sp+7h] [bp-Dh] BYREF
  unsigned __int8 v4; // [sp+Eh] [bp-6h] BYREF
  _BYTE v5[5]; // [sp+Fh] [bp-5h] BYREF

  v3[0] = a1;
  result = sub_101B00((int)v3, &v4, v5);
  v2 = (unsigned int *)off_12C4C4;
  *(_DWORD *)off_12C4C4 = *(_DWORD *)off_12C4C4 & 0xFFFF00FF | (v4 << 8);
  *v2 = *v2 & 0xFFFFFF00 | v5[0];
  return result;
}

