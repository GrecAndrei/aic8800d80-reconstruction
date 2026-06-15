// v23 annotated: mmio_copy_4words @ 0x101a68
// Original: 101a68_mmio_copy_4words.c
// Primary struct: vif_set_state_req (cluster 3, 10 funcs)
// Fields: vif_idx=0x0, vif=0x0, flags=0x4, mac=0x8, mac_hi=0xa, bssid_lo=0xc, bssid_hi=0xe, op=0x18, state=0x1c
//
// mmio_copy_4words @ 0x101a68, size 28 bytes
// Doc: mmio_copy_4words [mmio]: Copy 4 words from src pair to MMIO 0x403308a8
// mmio_copy_4words [mmio]: Copy 4 words from src pair to MMIO 0x403308a8
_DWORD *__fastcall mmio_copy_4words(_DWORD *result, _DWORD *a2)
{
  _DWORD *v2; // r3

  v2 = off_101A84;
  *(_DWORD *)off_101A84 = *result;
  v2[1] = result[1];
  v2[2] = *a2;
  v2[3] = a2[1];
  v2[4] = a2[2];
  v2[5] = a2[3];
  return result;
}

