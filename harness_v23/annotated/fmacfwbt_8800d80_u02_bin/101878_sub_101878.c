// v23 annotated: sub_101878 @ 0x101878
// Original: 101878_sub_101878.c
// Primary struct: vif_set_state_req (cluster 3, 10 funcs)
// Fields: vif_idx=0x0, vif=0x0, flags=0x4, mac=0x8, mac_hi=0xa, bssid_lo=0xc, bssid_hi=0xe, op=0x18, state=0x1c
//
// sub_101878 @ 0x101878, size 10 bytes
int sub_101878()
{
  return (*(_DWORD *)off_101884 >> 21) & 1;
}

