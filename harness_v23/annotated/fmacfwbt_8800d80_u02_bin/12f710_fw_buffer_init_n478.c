// v23 annotated: fw_buffer_init_n478 @ 0x12f710
// Original: 12f710_fw_buffer_init_n478.c
// Primary struct: <unclustered>
//
// fw_buffer_init_n478 @ 0x12f710, size 26 bytes
// Doc: fw_buffer_init_n478 [util]: Initialize firmware buffer/memory region
// fw_buffer_init_n478 [util]: Initialize firmware buffer/memory region
int *fw_buffer_init_n478()
{
  _QWORD *v0; // r4
  int *result; // r0

  v0 = off_12F72C;
  result = memset_thunk((int *)off_12F72C, 0, 8u);
  *v0 = 0x2FFFFFFFFLL;
  return result;
}

