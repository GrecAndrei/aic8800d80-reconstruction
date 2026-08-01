// get_hook_bits_3_5 @ 0x114b1c, size 18 bytes
// Doc: rf_state_check_n4c2 [rf]: Checks RF state and sets status word with next-state tag
// rf_state_check_n4c2 [rf]: Checks RF state and sets status word with next-state tag
unsigned int get_hook_bits_3_5()
{
  return ((unsigned int)MEMD(508)(17) >> 3) & 7;
}

