// sub_11C1B4 @ 0x11c1b4, size 24 bytes
void  sub_11C1B4(int a1)
{
  uint8_t *v1; // r4

  v1 = off_11C1CC;
  *(uint8_t *)off_11C1CC = 1;
  sub_11EABC(a1);
  *v1 = 0;
  sub_11B898();
}

