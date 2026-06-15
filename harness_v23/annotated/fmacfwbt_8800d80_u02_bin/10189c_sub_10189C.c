// v23 annotated: sub_10189C @ 0x10189c
// Original: 10189c_sub_10189C.c
// Primary struct: vif_set_state_req (cluster 3, 10 funcs)
// Fields: vif_idx=0x0, vif=0x0, flags=0x4, mac=0x8, mac_hi=0xa, bssid_lo=0xc, bssid_hi=0xe, op=0x18, state=0x1c
//
// sub_10189C @ 0x10189c, size 20 bytes
unsigned int __fastcall sub_10189C(int a1)
{
  unsigned int result; // r0

  result = (8 * a1) & 8 | *(_DWORD *)off_1018B0 & 0xFFFFFFF7;
  *(_DWORD *)off_1018B0 = result;
  return result;
}

