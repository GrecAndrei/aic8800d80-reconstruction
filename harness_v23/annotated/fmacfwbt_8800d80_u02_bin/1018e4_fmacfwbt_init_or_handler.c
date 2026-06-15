// v23 annotated: fmacfwbt_init_or_handler @ 0x1018e4
// Original: 1018e4_fmacfwbt_init_or_handler.c
// Primary struct: vif_set_state_req (cluster 3, 10 funcs)
// Fields: vif_idx=0x0, vif=0x0, flags=0x4, mac=0x8, mac_hi=0xa, bssid_lo=0xc, bssid_hi=0xe, op=0x18, state=0x1c
//
// fmacfwbt_init_or_handler @ 0x1018e4, size 28 bytes
// Doc: fmacfwbt_init_or_handler [unknown]: FMAC BT firmware init/handler stub
// fmacfwbt_init_or_handler [unknown]: FMAC BT firmware init/handler stub
_DWORD *__fastcall fmacfwbt_init_or_handler(_DWORD *result, _DWORD *a2)
{
  _DWORD *v2; // r3

  v2 = off_101900;
  *(_DWORD *)off_101900 = *result;
  v2[1] = result[1];
  v2[2] = *a2;
  v2[3] = a2[1];
  v2[4] = a2[2];
  v2[5] = a2[3];
  return result;
}

