// rf_chip_ready_check @ 0x101a3c, size 14 bytes
// Doc: rf_chip_ready_check [rf]: Check RF chip ready flag at 0x40341424, return 1 if > 1
// rf_chip_ready_check [rf]: Check RF chip ready flag at 0x40341424, return 1 if > 1
BOOL rf_chip_ready_check()
{
  return *(_DWORD *)off_101A4C > 1u;
}

