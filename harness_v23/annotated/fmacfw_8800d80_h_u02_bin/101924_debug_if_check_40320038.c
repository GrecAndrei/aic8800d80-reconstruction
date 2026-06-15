// v23 annotated: debug_if_check_40320038 @ 0x101924
// Original: 101924_debug_if_check_40320038.c
// Primary struct: vif_set_state_req (cluster 5, 10 funcs)
// Fields: vif_idx=0x0, vif=0x0, flags=0x4, mac=0x8, mac_hi=0xa, bssid_lo=0xc, bssid_hi=0xe, op=0x18, state=0x1c
//
// debug_if_check_40320038 @ 0x101924, size 18 bytes
// Doc: debug_if_check_40320038 [util]: Check debug interface status register at 0x40320038 and load status string
// debug_if_check_40320038 [util]: Check debug interface status register at 0x40320038 and load status string
int __fastcall debug_if_check_40320038(int a1, int a2, int a3)
{
  int result; // r0

  if ( *(_DWORD *)off_101938 << 28 )
    return msg_parse(dword_101940, dword_10193C, a3);
  return result;
}

