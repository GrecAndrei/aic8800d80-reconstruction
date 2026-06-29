// sub_10EFD8 @ 0x10efd8, size 18 bytes
unsigned int sub_10EFD8()
{
  unsigned int result; // r0

  result = rf_power_set(0xC2u);
  *((uint8_t *)off_10EFEC + 7) = -62;
  return result;
}

