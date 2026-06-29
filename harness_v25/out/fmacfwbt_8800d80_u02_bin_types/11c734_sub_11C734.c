// sub_11C734 @ 0x11c734, size 24 bytes
void  sub_11C734(int a1)
{
  uint8_t *v1; // r4

  v1 = off_11C74C;
  *(uint8_t *)off_11C74C = 1;
  sub_11F03C(a1);
  *v1 = 0;
  sub_11BE18();
}

