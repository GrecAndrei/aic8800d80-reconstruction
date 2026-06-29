// fwstruct annotate: 10d5dc_sub_10D5DC.c
// sub_10D5DC @ 0x10d5dc, size 20 bytes
void sub_10D5DC()
{
  *((_DWORD *)off_10D5F0 + 32) = 0x8000;
  __dsb(0xFu);
  __isb(0xFu);
}

