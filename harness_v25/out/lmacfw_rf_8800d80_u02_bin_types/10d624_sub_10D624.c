// sub_10D624 @ 0x10d624, size 20 bytes
void sub_10D624()
{
  *((uint32_t *)off_10D638 + 32) = 0x8000;
  __dsb(0xFu);
  __isb(0xFu);
}

