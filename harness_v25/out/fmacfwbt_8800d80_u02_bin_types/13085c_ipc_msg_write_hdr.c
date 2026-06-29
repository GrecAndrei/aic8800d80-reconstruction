// ipc_msg_write_hdr @ 0x13085c, size 120 bytes
// Doc: ipc_msg_write_hdr [ipc]: Write IPC message header fields
// ipc_msg_write_hdr [ipc]: Write IPC message header fields
int  ipc_msg_write_hdr(int *a1)
{
  char *v1; // r4
  __int16 v2; // r3
  int v3; // r2
  int v4; // r6
  char *v5; // r3
  char v6; // t1
  char *v7; // r2
  int v8; // r5
  uint8_t *v9; // r3
  uint8_t *v10; // r5
  char v11; // t1

  v1 = (char *)off_1308D4;
  v2 = *((uint16_t *)off_1308D4 + 6);
  *(uint8_t *)*a1 = 45;
  *(uint8_t *)(*a1 + 1) = 26;
  v3 = *a1;
  *(uint16_t *)(v3 + 2) = v2 & 0xFFE3 | 0xC;
  *(uint8_t *)(v3 + 4) = v1[14];
  v4 = *a1;
  v5 = v1 + 15;
  do
  {
    v6 = *v5++;
    *(uint8_t *)(v5 - v1 + v4 - 11) = v6;
  }
  while ( v5 != v1 + 31 );
  v7 = (char *)dword_1308D8;
  *(uint8_t *)(*a1 + 15) = 0;
  *(uint8_t *)(*a1 + 16) = 0;
  v8 = *a1;
  *(uint16_t *)(v8 + 21) = *((uint16_t *)v1 + 16);
  v9 = (uint8_t *)(v8 + 23);
  v10 = (uint8_t *)(v8 + 27);
  do
  {
    v11 = *v7++;
    *v9++ = v11;
  }
  while ( v9 != v10 );
  *(uint8_t *)(*a1 + 27) = v1[40];
  *a1 += 28;
  return 28;
}

