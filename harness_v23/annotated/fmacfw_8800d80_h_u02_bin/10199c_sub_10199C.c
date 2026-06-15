// v23 annotated: sub_10199C @ 0x10199c
// Original: 10199c_sub_10199C.c
// Primary struct: vif_set_state_req (cluster 5, 10 funcs)
// Fields: vif_idx=0x0, vif=0x0, flags=0x4, mac=0x8, mac_hi=0xa, bssid_lo=0xc, bssid_hi=0xe, op=0x18, state=0x1c
//
// sub_10199C @ 0x10199c, size 10 bytes
int sub_10199C()
{
  return (*(_DWORD *)off_1019A8 >> 28) & 1;
}

