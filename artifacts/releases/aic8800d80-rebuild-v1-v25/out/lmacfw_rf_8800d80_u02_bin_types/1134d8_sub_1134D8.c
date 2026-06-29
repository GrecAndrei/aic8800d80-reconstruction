// sub_1134D8 @ 0x1134d8, size 28 bytes
int  sub_1134D8(int a1)
{
  uint8_t *v1; // r2
  char v2; // r3

  sub_113374(a1);
  v1 = off_1134FC;
  v2 = *((uint8_t *)off_1134F4 + 352);
  *(uint8_t *)off_1134F8 = *((uint8_t *)off_1134F4 + 326);
  *v1 = v2;
  return 1;
}

