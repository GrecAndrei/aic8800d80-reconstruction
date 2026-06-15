// v23 annotated: sub_1019D0 @ 0x1019d0
// Original: 1019d0_sub_1019D0.c
// Primary struct: vif_set_state_req (cluster 3, 10 funcs)
// Fields: vif_idx=0x0, vif=0x0, flags=0x4, mac=0x8, mac_hi=0xa, bssid_lo=0xc, bssid_hi=0xe, op=0x18, state=0x1c
//
// sub_1019D0 @ 0x1019d0, size 18 bytes
int __fastcall sub_1019D0(int a1, int a2, int a3)
{
  int result; // r0

  if ( *(_DWORD *)off_1019E4 << 28 )
    return msg_parse(dword_1019EC, dword_1019E8, a3);
  return result;
}

