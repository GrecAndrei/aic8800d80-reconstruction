// v23 annotated: sub_1019AC @ 0x1019ac
// Original: 1019ac_sub_1019AC.c
// Primary struct: vif_set_state_req (cluster 5, 10 funcs)
// Fields: vif_idx=0x0, vif=0x0, flags=0x4, mac=0x8, mac_hi=0xa, bssid_lo=0xc, bssid_hi=0xe, op=0x18, state=0x1c
//
// sub_1019AC @ 0x1019ac, size 10 bytes
int sub_1019AC()
{
  return (*(_DWORD *)off_1019B8 >> 30) & 1;
}

