// sub_10D644 @ 0x10d644, size 20 bytes
void sub_10D644()
{
  *((uint32_t *)off_10D658 + 32) = 0x8000;
  __dsb(0xFu);
  __isb(0xFu);
}

