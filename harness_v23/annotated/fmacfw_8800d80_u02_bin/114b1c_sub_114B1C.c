// v23 annotated: sub_114B1C @ 0x114b1c
// Original: 114b1c_sub_114B1C.c
// Primary struct: <unclustered>
//
// sub_114B1C @ 0x114b1c, size 18 bytes
// Doc: rf_state_check_n4c2 [rf]: Checks RF state and sets status word with next-state tag
// rf_state_check_n4c2 [rf]: Checks RF state and sets status word with next-state tag
unsigned int sub_114B1C()
{
  return ((unsigned int)MEMORY[0x1FC](17) >> 3) & 7;
}

