// v23 annotated: sub_101A38 @ 0x101a38
// Original: 101a38_sub_101A38.c
// Primary struct: vif_set_state_req (cluster 3, 10 funcs)
// Fields: vif_idx=0x0, vif=0x0, flags=0x4, mac=0x8, mac_hi=0xa, bssid_lo=0xc, bssid_hi=0xe, op=0x18, state=0x1c
//
// sub_101A38 @ 0x101a38, size 10 bytes
int sub_101A38()
{
  return (*(_DWORD *)off_101A44 >> 26) & 1;
}

