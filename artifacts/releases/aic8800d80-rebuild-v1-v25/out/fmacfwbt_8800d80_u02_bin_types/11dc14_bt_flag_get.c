// bt_flag_get @ 0x11dc14, size 30 bytes
// Doc: bt_flag_get [bt]: Reads byte flag from BT global state struct
// bt_flag_get [bt]: Reads byte flag from BT global state struct
int bt_flag_get()
{
  uint8_t *v0; // r4
  unsigned int *v1; // r2
  int v2; // r3
  int result; // r0

  v0 = off_11DC34;
  if ( *((uint8_t *)off_11DC34 + 10) )
    result = j_nullsub_6();
  v1 = (unsigned int *)off_11DC38;
  v2 = *(uint32_t *)off_11DC38;
  v0[10] = v0[11];
  *v1 = v2 & 0xFFFFFEFF;
  return result;
}

