// v23 annotated: sub_101974 @ 0x101974
// Original: 101974_sub_101974.c
// Primary struct: vif_set_state_req (cluster 5, 10 funcs)
// Fields: vif_idx=0x0, vif=0x0, flags=0x4, mac=0x8, mac_hi=0xa, bssid_lo=0xc, bssid_hi=0xe, op=0x18, state=0x1c
//
// sub_101974 @ 0x101974, size 20 bytes
unsigned int __fastcall sub_101974(int a1)
{
  unsigned int result; // r0

  result = (8 * a1) & 8 | *(_DWORD *)off_101988 & 0xFFFFFFF7;
  *(_DWORD *)off_101988 = result;
  return result;
}

