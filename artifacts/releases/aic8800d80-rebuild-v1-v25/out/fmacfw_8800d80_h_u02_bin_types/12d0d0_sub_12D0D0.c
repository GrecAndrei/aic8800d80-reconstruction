// sub_12D0D0 @ 0x12d0d0, size 40 bytes
int sub_12D0D0()
{
  uint32_t *v0; // r0
  uint32_t *v1; // r3
  void *v2; // r1

  v0 = sub_12C954();
  v1 = off_12D0F8;
  v2 = off_12D0FC;
  *((uint32_t *)off_12D0F8 + 7) = v0;
  v1[3] = 0;
  v1[4] = 0;
  v1[1] = 0;
  v1[2] = 0;
  v1[5] = 0;
  v1[6] = 0;
  v1[9] = v2;
  return sub_12D00C(-1);
}

