// v23 annotated: sub_101950 @ 0x101950
// Original: 101950_sub_101950.c
// Primary struct: vif_set_state_req (cluster 5, 10 funcs)
// Fields: vif_idx=0x0, vif=0x0, flags=0x4, mac=0x8, mac_hi=0xa, bssid_lo=0xc, bssid_hi=0xe, op=0x18, state=0x1c
//
// sub_101950 @ 0x101950, size 10 bytes
int sub_101950()
{
  return (*(_DWORD *)off_10195C >> 21) & 1;
}

