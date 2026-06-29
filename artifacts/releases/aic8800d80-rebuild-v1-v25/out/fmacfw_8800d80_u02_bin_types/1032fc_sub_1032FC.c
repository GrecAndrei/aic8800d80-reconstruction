// sub_1032FC @ 0x1032fc, size 356 bytes
// Doc: sub_12032FC [mmio]: Initialize SoC MMIO register block (set bits, configure peripheral)
// sub_12032FC [mmio]: Initialize SoC MMIO register block (set bits, configure peripheral)
void __noreturn sub_1032FC()
{
  unsigned int *v0; // r6
  unsigned int *v1; // r5

  v0 = (unsigned int *)off_103460;
  v1 = (unsigned int *)off_103464;
  *(uint32_t *)off_103460 |= 0x10u;
  *v1 = *v1 & 0xFFFFC0FF | 0x300;
  *v0 &= ~0x200u;
  *v0 = *v0 & 0xFFFE03FF | 0x10000;
  *v1 |= 0x4000u;
  while ( 1 )
    ;
}

