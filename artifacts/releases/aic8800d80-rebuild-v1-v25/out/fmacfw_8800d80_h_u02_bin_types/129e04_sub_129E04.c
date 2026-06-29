// sub_129E04 @ 0x129e04, size 26 bytes
int *sub_129E04()
{
  int *result; // r0
  uint8_t *v1; // r3

  result = sub_100200((int *)dword_129E20, 0, 1u);
  v1 = off_129E24;
  *((uint8_t *)off_129E24 + 113) = -1;
  v1[253] = -1;
  return result;
}

