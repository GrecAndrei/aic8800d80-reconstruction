// mmio_copy_4words @ 0x101a68, size 28 bytes
// Doc: mmio_copy_4words [mmio]: Copy 4 words from src pair to MMIO 0x403308a8
// mmio_copy_4words [mmio]: Copy 4 words from src pair to MMIO 0x403308a8
uint32_t * mmio_copy_4words(uint32_t *result, uint32_t *a2)
{
  uint32_t *v2; // r3

  v2 = off_101A84;
  *(uint32_t *)off_101A84 = *result;
  v2[1] = result[1];
  v2[2] = *a2;
  v2[3] = a2[1];
  v2[4] = a2[2];
  v2[5] = a2[3];
  return result;
}

