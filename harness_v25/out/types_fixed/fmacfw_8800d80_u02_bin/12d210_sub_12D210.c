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
  *(_DWORD *)(v1 + 0xc) = 0;
  *(_DWORD *)(v1 + 0x10) = 0;
  *(_DWORD *)(v1 + 0x4) = 0;
  *(_DWORD *)(v1 + 0x8) = 0;
  *(_DWORD *)(v1 + 0x14) = 0;
  *(_DWORD *)(v1 + 0x18) = 0;
  *(_DWORD *)(v1 + 0x24) = v2;
  return clear_flags(-1);
}

