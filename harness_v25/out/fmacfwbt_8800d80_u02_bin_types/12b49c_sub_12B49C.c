// sub_12B49C @ 0x12b49c, size 46 bytes
int  sub_12B49C(int a1)
{
  uint32_t *v1; // r6
  char *v2; // r4
  int result; // r0

  v1 = off_12B4CC;
  v2 = (char *)off_12B4D0;
  v1[1] = sub_12DD88(off_12B4D0, *(unsigned __int16 *)(*(uint32_t *)off_12B4CC + 364));
  result = sub_12B3C8();
  *(uint32_t *)&v2[-8] = *(uint32_t *)&v2[-12] - 1 + *(unsigned __int16 *)(a1 + 364);
  *((uint32_t *)v2 - 1) = 0;
  return result;
}

