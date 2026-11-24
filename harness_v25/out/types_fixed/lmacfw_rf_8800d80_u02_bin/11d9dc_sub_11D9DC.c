// sub_11D9DC @ 0x11d9dc, size 22 bytes
int sub_11D9DC()
{
  *(_DWORD *)(dword_11D9F4 + 4808) &= ~1u;
  return irq_nesting_or(0x40000000);
}

