// v23 annotated: sub_101A58 @ 0x101a58
// Original: 101a58_sub_101A58.c
// Primary struct: vif_set_state_req (cluster 3, 10 funcs)
// Fields: vif_idx=0x0, vif=0x0, flags=0x4, mac=0x8, mac_hi=0xa, bssid_lo=0xc, bssid_hi=0xe, op=0x18, state=0x1c
//
// sub_101A58 @ 0x101a58, size 10 bytes
// Doc: sub_1201A58 [util]: Auxiliary FMAC handler (reconstructed flow)
// sub_1201A58 [util]: Auxiliary FMAC handler (reconstructed flow)
int sub_101A58()
{
  return (*(_DWORD *)off_101A64 >> 30) & 1;
}

