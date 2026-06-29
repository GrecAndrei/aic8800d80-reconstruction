// sub_115820 @ 0x115820, size 108 bytes
int sub_115820()
{
  int *v0; // r4
  int v1; // r0
  int v2; // r0
  int result; // r0

  v0 = (int *)off_11588C;
  v1 = sub_11522C();
  v2 = nullsub_4(v1);
  sub_115FBC(v2);
  sub_11639C(0);
  sub_100200(v0, 0, 0x94u);
  sub_11E71C(v0 + 3);
  *v0 = 0;
  *((uint8_t *)v0 + 26) = 0;
  sub_11E71C(v0 + 10);
  v0[7] = 0;
  *((uint8_t *)v0 + 54) = 0;
  sub_11E71C(v0 + 17);
  v0[14] = 0;
  *((uint8_t *)v0 + 82) = 0;
  sub_11E71C(v0 + 24);
  v0[21] = 0;
  *((uint8_t *)v0 + 110) = 0;
  result = sub_11E71C(v0 + 31);
  v0[28] = 0;
  *((uint8_t *)v0 + 138) = 0;
  *((uint16_t *)v0 + 70) = 0;
  return result;
}

