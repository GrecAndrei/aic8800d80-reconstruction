// read_mac_dual_addr @ 0x1019d4, size 14 bytes
// Doc: read_mac_dual_addr [mmio]: Read two 32-bit words from 0x40330000 and 0x4033003c into output pointers
// read_mac_dual_addr [mmio]: Read two 32-bit words from 0x40330000 and 0x4033003c into output pointers
uint32_t * read_mac_dual_addr(uint32_t *result, uint32_t *a2)
{
  uint32_t *v2; // r3

  v2 = off_1019E8;
  *result = *(uint32_t *)off_1019E4;
  *a2 = *v2;
  return result;
}

