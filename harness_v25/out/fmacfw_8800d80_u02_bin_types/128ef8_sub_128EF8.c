// sub_128EF8 @ 0x128ef8, size 28 bytes
int sub_128EF8()
{
  uint32_t *v0; // r4
  int *v1; // r0
  int result; // r0

  v0 = off_128F14;
  v1 = sub_100200((int *)off_128F14, 0, 0x28u);
  result = sub_1420A0(v1);
  v0[4] = off_128F18;
  *((uint8_t *)v0 + 28) = 1;
  return result;
}

