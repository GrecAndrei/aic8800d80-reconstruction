// crypto_hw_clear_regs @ 0x106f08, size 96 bytes
// Doc: crypto_hw_clear_regs [util]: Clear crypto engine HW control/status registers
// crypto_hw_clear_regs [util]: Clear crypto engine HW control/status registers
uint32_t *crypto_hw_clear_regs()
{
  unsigned int *v0; // r2
  uint32_t *v1; // r3
  uint32_t *result; // r0

  v0 = (unsigned int *)off_106F68;
  v1 = off_106F6C;
  result = off_106F70;
  *(uint32_t *)off_106F68 = *(uint32_t *)off_106F68 & 0xC0FFFFFF | 0x3000000;
  *v0 = *v0 & 0xFFC0FFFF | 0x30000;
  *v0 = *v0 & 0xFFFFC0FF | 0x300;
  *v0 = *v0 & 0xFFFFFFC0 | 3;
  *v1 &= 0xC0FFFFFF;
  *v1 &= 0xFFC0FFFF;
  *v1 &= 0xFFFFC0FF;
  *v1 &= 0xFFFFFFC0;
  *result &= 0xFFFFFFC0;
  return result;
}

