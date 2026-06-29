// sub_113AE0 @ 0x113ae0, size 28 bytes
int  sub_113AE0(int a1)
{
  uint8_t *v1; // r2
  char v2; // r3

  sub_11397C(a1);
  v1 = off_113B04;
  v2 = *((uint8_t *)off_113AFC + 352);
  *(uint8_t *)off_113B00 = *((uint8_t *)off_113AFC + 326);
  *v1 = v2;
  return 1;
}

