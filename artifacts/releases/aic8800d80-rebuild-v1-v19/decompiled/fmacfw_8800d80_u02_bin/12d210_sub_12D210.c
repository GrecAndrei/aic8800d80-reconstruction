// sub_12D210 @ 0x12d210, size 40 bytes
int sub_12D210()
{
  _DWORD *v0; // r0
  _DWORD *v1; // r3
  void *v2; // r1

  v0 = rx_queue_head_init();
  v1 = off_12D238;
  v2 = off_12D23C;
  *((_DWORD *)off_12D238 + 7) = v0;
  v1[3] = 0;
  v1[4] = 0;
  v1[1] = 0;
  v1[2] = 0;
  v1[5] = 0;
  v1[6] = 0;
  v1[9] = v2;
  return clear_flags(-1);
}

