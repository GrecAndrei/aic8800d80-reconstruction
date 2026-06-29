// sub_10F040 @ 0x10f040, size 18 bytes
unsigned int sub_10F040()
{
  unsigned int result; // r0

  result = sub_102AD0(0xC2u);
  *((uint8_t *)off_10F054 + 7) = -62;
  return result;
}

