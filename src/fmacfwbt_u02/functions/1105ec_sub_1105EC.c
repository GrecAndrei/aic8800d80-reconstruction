// init_after_reset @ 0x1105ec, size 14 bytes
int init_after_reset()
{
  int v0; // r0

  v0 = rf_tx_start();
  setup_patch_data(v0);
  return 1;
}

