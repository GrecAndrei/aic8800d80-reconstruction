// get_hw_info_bit18 @ 0x1151ac, size 18 bytes
// Doc: get_hw_info_bit18 [patch]: Calls helper and extracts single bit (bit 18) from returned flag word
// get_hw_info_bit18 [patch]: Calls helper and extracts single bit (bit 18) from returned flag word
unsigned int get_hw_info_bit18()
{
  return ((unsigned int)MEMD(508)(15) >> 18) & 1;
}

