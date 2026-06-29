// ipc_init_buf @ 0x12f4e8, size 26 bytes
// Doc: ipc_init_buf [ipc]: Initialize 8-byte buffer to zero at 0x18274c
// ipc_init_buf [ipc]: Initialize 8-byte buffer to zero at 0x18274c
int *ipc_init_buf()
{
  QWORD *v0; // r4
  int *result; // r0

  v0 = off_12F504;
  result = memset_thunk((int *)off_12F504, 0, 8u);
  *v0 = 0x2FFFFFFFFLL;
  return result;
}

