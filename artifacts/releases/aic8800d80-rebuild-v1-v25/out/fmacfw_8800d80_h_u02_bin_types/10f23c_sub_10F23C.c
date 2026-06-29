// sub_10F23C @ 0x10f23c, size 48 bytes
int sub_10F23C()
{
  uint8_t *v0; // r4
  char *v1; // r0

  v0 = off_10F26C;
  v1 = (char *)off_10F26C + 1624;
  *((uint16_t *)off_10F26C + 810) = 80;
  v0[1622] = 81;
  sub_12D100(v1);
  *((uint16_t *)v0 + 1216) = 39;
  v0[2434] = 40;
  return sub_12D100(v0 + 2436);
}

