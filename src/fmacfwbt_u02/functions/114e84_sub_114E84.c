// get_hw_info_bit9 @ 0x114e84, size 18 bytes
unsigned int get_hw_info_bit9()
{
  return ((unsigned int)MEMD(508)(1) >> 9) & 1;
}

