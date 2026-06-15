// v23 annotated: sub_12F4E8 @ 0x12f4e8
// Original: 12f4e8_sub_12F4E8.c
// Primary struct: ipc_shared_buf (cluster 10, 5 funcs)
// Fields: ptr=0x0, state=0x1f8
//
// sub_12F4E8 @ 0x12f4e8, size 26 bytes
int *sub_12F4E8()
{
  _QWORD *v0; // r4
  int *result; // r0

  v0 = off_12F504;
  result = sub_100200((int *)off_12F504, 0, 8u);
  *v0 = 0x2FFFFFFFFLL;
  return result;
}

