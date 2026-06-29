// sub_11D9C0 @ 0x11d9c0, size 22 bytes
int sub_11D9C0()
{
  *(uint32_t *)(dword_11D9D8 + 4680) &= ~1u;
  return irq_nesting_or(0x8000);
}

