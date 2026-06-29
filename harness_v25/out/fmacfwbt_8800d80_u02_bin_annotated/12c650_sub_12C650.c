// fwstruct annotate: 12c650_sub_12C650.c
// sub_12C650 @ 0x12c650, size 22 bytes
int sub_12C650()
{
  *(_DWORD *)(dword_12C668 + 4680) &= ~1u;
  return irq_nesting_or(1024);
}

