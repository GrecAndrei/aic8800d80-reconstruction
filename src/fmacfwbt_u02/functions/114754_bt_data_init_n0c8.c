// init_osal_objects @ 0x114754, size 52 bytes
// Doc: init_osal_objects [bt]: initialize BT data structures at 0x18254c/0x187ffc
// init_osal_objects [bt]: initialize BT data structures at 0x18254c/0x187ffc
int init_osal_objects()
{
  int v0; // r4
  int v1; // r5

  v0 = dword_114788;
  v1 = dword_114788 + 8;
  zero_struct(dword_114788);
  zero_struct(v1);
  check_abort_flag(v1);
  check_abort_flag(v1);
  return zero_struct(v0 + 16);
}

