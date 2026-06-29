// rf_check_bit @ 0x10db30, size 20 bytes
// Doc: rf_check_bit [rf]: Tests a single bit in MMIO register and returns 1/0
// rf_check_bit [rf]: Tests a single bit in MMIO register and returns 1/0
BOOL  rf_check_bit(char a1)
{
  return ((1 << a1) & *(uint32_t *)off_10DB44) != 0;
}

