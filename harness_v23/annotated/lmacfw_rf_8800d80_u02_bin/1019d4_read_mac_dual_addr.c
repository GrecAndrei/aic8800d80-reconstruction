// v23 annotated: read_mac_dual_addr @ 0x1019d4
// Original: 1019d4_read_mac_dual_addr.c
// Primary struct: <unclustered>
//
// read_mac_dual_addr @ 0x1019d4, size 14 bytes
// Doc: read_mac_dual_addr [mmio]: Read two 32-bit words from 0x40330000 and 0x4033003c into output pointers
// read_mac_dual_addr [mmio]: Read two 32-bit words from 0x40330000 and 0x4033003c into output pointers
_DWORD *__fastcall read_mac_dual_addr(_DWORD *result, _DWORD *a2)
{
  _DWORD *v2; // r3

  v2 = off_1019E8;
  *result = *(_DWORD *)off_1019E4;
  *a2 = *v2;
  return result;
}

