// mmio_pair_read_n1800 @ 0x101800, size 14 bytes
// Doc: mmio_pair_read_n1800 [mmio]: Reads paired 32-bit MMIO regs from 0x40330000/0x4033003c into r0/r1
// mmio_pair_read_n1800 [mmio]: Reads paired 32-bit MMIO regs from 0x40330000/0x4033003c into r0/r1
uint32_t * mmio_pair_read_n1800(uint32_t *result, uint32_t *a2)
{
  uint32_t *v2; // r3

  v2 = off_101814;
  *result = *(uint32_t *)off_101810;
  *a2 = *v2;
  return result;
}

