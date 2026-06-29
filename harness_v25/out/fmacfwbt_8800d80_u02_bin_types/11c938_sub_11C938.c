// sub_11C938 @ 0x11c938, size 44 bytes
// Doc: sub_121C938 [ipc]: Look up and process IPC/queue slot by indexed offset
// sub_121C938 [ipc]: Look up and process IPC/queue slot by indexed offset
int  sub_11C938(int result, int a2)
{
  int v2; // r2
  int v3; // r3

  v2 = dword_11C964;
  v3 = dword_11C964 + 28 * a2;
  if ( *(uint32_t *)(v3 + 24) )
  {
    if ( *(uint8_t *)(v3 + 46) )
      *(uint32_t *)(v3 + 36) = result;
    *(uint8_t *)(v2 + 28 * a2 + 45) = 1;
  }
  return result;
}

