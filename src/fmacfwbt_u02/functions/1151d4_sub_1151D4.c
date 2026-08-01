// get_hw_info_bit20 @ 0x1151d4, size 18 bytes
unsigned int get_hw_info_bit20()
{
  return ((unsigned int)MEMD(508)(15) >> 20) & 1;
}

