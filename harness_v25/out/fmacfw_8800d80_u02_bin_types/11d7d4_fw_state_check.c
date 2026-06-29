// fw_state_check @ 0x11d7d4, size 30 bytes
// Doc: fw_state_check [util]: Reads firmware state flag byte for status check
// fw_state_check [util]: Reads firmware state flag byte for status check
int fw_state_check()
{
  uint8_t *v0; // r4
  unsigned int *v1; // r2
  int v2; // r3
  int result; // r0

  v0 = off_11D7F4;
  if ( *((uint8_t *)off_11D7F4 + 10) )
    result = j_nullsub_6();
  v1 = (unsigned int *)off_11D7F8;
  v2 = *(uint32_t *)off_11D7F8;
  v0[10] = v0[11];
  *v1 = v2 & 0xFFFFFEFF;
  return result;
}

