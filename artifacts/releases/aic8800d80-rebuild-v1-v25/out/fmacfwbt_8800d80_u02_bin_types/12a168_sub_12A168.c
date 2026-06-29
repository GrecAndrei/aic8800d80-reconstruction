// sub_12A168 @ 0x12a168, size 26 bytes
int *sub_12A168()
{
  int *result; // r0
  uint8_t *v1; // r3

  result = memset_thunk((int *)dword_12A184, 0, 1u);
  v1 = off_12A188;
  *((uint8_t *)off_12A188 + 113) = -1;
  v1[253] = -1;
  return result;
}

