// sub_12B138 @ 0x12b138, size 46 bytes
int  sub_12B138(int a1)
{
  uint32_t *v1; // r6
  char *v2; // r4
  int result; // r0

  v1 = off_12B168;
  v2 = (char *)off_12B16C;
  v1[1] = sub_12DA20(off_12B16C, *(unsigned __int16 *)(*(uint32_t *)off_12B168 + 364));
  result = sub_12B064();
  *(uint32_t *)&v2[-8] = *(uint32_t *)&v2[-12] - 1 + *(unsigned __int16 *)(a1 + 364);
  *((uint32_t *)v2 - 1) = 0;
  return result;
}

