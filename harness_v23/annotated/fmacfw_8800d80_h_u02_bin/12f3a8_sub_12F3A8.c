// v23 annotated: sub_12F3A8 @ 0x12f3a8
// Original: 12f3a8_sub_12F3A8.c
// Primary struct: ipc_shared_buf (cluster 13, 5 funcs)
// Fields: ptr=0x0, state=0x1f8
//
// sub_12F3A8 @ 0x12f3a8, size 26 bytes
int *sub_12F3A8()
{
  _QWORD *v0; // r4
  int *result; // r0

  v0 = off_12F3C4;
  result = sub_100200((int *)off_12F3C4, 0, 8u);
  *v0 = 0x2FFFFFFFFLL;
  return result;
}

