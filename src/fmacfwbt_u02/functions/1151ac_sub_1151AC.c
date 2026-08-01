// get_hw_info_bit18 @ 0x1151ac, size 18 bytes
unsigned int get_hw_info_bit18()
{
  return ((unsigned int)MEMD(508)(15) >> 18) & 1;
}

