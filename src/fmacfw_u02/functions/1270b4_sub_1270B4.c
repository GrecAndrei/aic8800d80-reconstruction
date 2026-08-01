// check_hw_state @ 0x1270b4, size 22 bytes
int check_hw_state()
{
  int v0; // r0
  int result; // r0

  v0 = shared_s16_worker();
  result = rf_mmio_read(v0);
  if ( !result )
    return ctrl_check_flags();
  return result;
}

