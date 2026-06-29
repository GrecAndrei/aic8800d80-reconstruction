// sub_10F180 @ 0x10f180, size 18 bytes
unsigned int sub_10F180()
{
  unsigned int result; // r0

  result = sub_102B80(0xC2u);
  *((uint8_t *)off_10F194 + 7) = -62;
  return result;
}

