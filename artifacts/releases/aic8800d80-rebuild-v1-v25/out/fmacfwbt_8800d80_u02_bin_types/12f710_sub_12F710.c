// sub_12F710 @ 0x12f710, size 26 bytes
int *sub_12F710()
{
  QWORD *v0; // r4
  int *result; // r0

  v0 = off_12F72C;
  result = sub_100200((int *)off_12F72C, 0, 8u);
  *v0 = 0x2FFFFFFFFLL;
  return result;
}

