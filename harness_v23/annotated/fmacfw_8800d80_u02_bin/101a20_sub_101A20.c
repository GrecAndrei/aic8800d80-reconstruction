// v23 annotated: sub_101A20 @ 0x101a20
// Original: 101a20_sub_101A20.c
// Primary struct: vif_set_state_req (cluster 3, 10 funcs)
// Fields: vif_idx=0x0, vif=0x0, flags=0x4, mac=0x8, mac_hi=0xa, bssid_lo=0xc, bssid_hi=0xe, op=0x18, state=0x1c
//
// sub_101A20 @ 0x101a20, size 20 bytes
unsigned int __fastcall sub_101A20(int a1)
{
  unsigned int result; // r0

  result = (8 * a1) & 8 | *(_DWORD *)off_101A34 & 0xFFFFFFF7;
  *(_DWORD *)off_101A34 = result;
  return result;
}

