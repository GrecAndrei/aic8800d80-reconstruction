// sub_11C968 @ 0x11c968, size 26 bytes
int  sub_11C968(int a1)
{
  uint32_t *v1; // r3
  int v2; // r1

  v1 = off_11C988;
  v2 = *((uint32_t *)off_11C984 + 4);
  *((uint32_t *)off_11C988 + 1) = dword_11C98C;
  v1[2] = a1;
  return timestamp_update_4f60(v1, v2 + 5000);
}

