// sub_113A7C @ 0x113a7c, size 28 bytes
int  sub_113A7C(int a1)
{
  uint8_t *v1; // r2
  char v2; // r3

  sub_113918(a1);
  v1 = off_113AA0;
  v2 = *((uint8_t *)off_113A98 + 352);
  *(uint8_t *)off_113A9C = *((uint8_t *)off_113A98 + 326);
  *v1 = v2;
  return 1;
}

