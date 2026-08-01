// mac_dma_setup @ 0x135224, size 44 bytes
int mac_dma_setup()
{
  int v0; // r0

  v0 = check_feature_flag(256, dword_1353FC, dword_1353F8);
  return tx_complete_check(v0);
}

