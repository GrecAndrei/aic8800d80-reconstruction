// sub_10D784 @ 0x10d784, size 20 bytes
// Doc: sub_120D784 [util]: Trigger CPU interrupt via NVIC (writes 0x8000 to ICSR with DSB/ISB barriers)
// sub_120D784 [util]: Trigger CPU interrupt via NVIC (writes 0x8000 to ICSR with DSB/ISB barriers)
void sub_10D784()
{
  *((uint32_t *)off_10D798 + 32) = 0x8000;
  __dsb(0xFu);
  __isb(0xFu);
}

