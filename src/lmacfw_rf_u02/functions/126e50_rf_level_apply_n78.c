// jump_10de98 @ 0x126e50, size 4 bytes
// Doc: jump_10de98 [rf]: Apply RF TX power level setting
// jump_10de98 [rf]: Apply RF TX power level setting
// attributes: thunk
int jump_10de98()
{
  return sdio_core_reset_alt();
}

