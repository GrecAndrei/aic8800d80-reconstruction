// v23 annotated: sub_1018B4 @ 0x1018b4
// Original: 1018b4_sub_1018B4.c
// Primary struct: vif_set_state_req (cluster 3, 10 funcs)
// Fields: vif_idx=0x0, vif=0x0, flags=0x4, mac=0x8, mac_hi=0xa, bssid_lo=0xc, bssid_hi=0xe, op=0x18, state=0x1c
//
// sub_1018B4 @ 0x1018b4, size 10 bytes
int sub_1018B4()
{
  return (*(_DWORD *)off_1018C0 >> 26) & 1;
}

