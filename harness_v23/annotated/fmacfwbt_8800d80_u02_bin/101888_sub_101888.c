// v23 annotated: sub_101888 @ 0x101888
// Original: 101888_sub_101888.c
// Primary struct: vif_set_state_req (cluster 3, 10 funcs)
// Fields: vif_idx=0x0, vif=0x0, flags=0x4, mac=0x8, mac_hi=0xa, bssid_lo=0xc, bssid_hi=0xe, op=0x18, state=0x1c
//
// sub_101888 @ 0x101888, size 14 bytes
// Doc: sub_1201888 [util]: Returns 1 if value equals 1, else 0
// sub_1201888 [util]: Returns 1 if value equals 1, else 0
BOOL sub_101888()
{
  return *(_DWORD *)off_101898 > 1u;
}

