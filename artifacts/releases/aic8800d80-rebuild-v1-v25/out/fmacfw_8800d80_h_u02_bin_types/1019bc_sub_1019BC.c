// sub_1019BC @ 0x1019bc, size 28 bytes
uint32_t * sub_1019BC(uint32_t *result, uint32_t *a2)
{
  uint32_t *v2; // r3

  v2 = off_1019D8;
  *(uint32_t *)off_1019D8 = *result;
  v2[1] = result[1];
  v2[2] = *a2;
  v2[3] = a2[1];
  v2[4] = a2[2];
  v2[5] = a2[3];
  return result;
}

