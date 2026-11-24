// bt_rf_mmio_init @ 0x108040, size 60 bytes
// Doc: bt_rf_mmio_init [bt]: Initializes RF MMIO register block from BT firmware context
// bt_rf_mmio_init [bt]: Initializes RF MMIO register block from BT firmware context
int bt_rf_mmio_init()
{
  unsigned int *v0; // r5
  unsigned int v1; // r4
  int v2; // r6
  int result; // r0
  _DWORD *v4; // r2

  v0 = (unsigned int *)off_108080;
  v1 = *(_DWORD *)off_108080;
  v2 = *(_DWORD *)off_10807C >> 20;
  result = feature_guard_sdio(1, dword_108084);
  v4 = off_10808C;
  *v0 = dword_108088 & (((HIWORD(v1) & 0xFFF) + v2) << 16) | *v0 & 0xF000FFFF;
  *v4 |= 0x800000u;
  return result;
}

