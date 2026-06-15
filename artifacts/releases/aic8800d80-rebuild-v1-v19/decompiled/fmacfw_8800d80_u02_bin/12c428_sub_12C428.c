// sub_12C428 @ 0x12c428, size 22 bytes
int sub_12C428()
{
  *(_DWORD *)(dword_12C440 + 4680) &= ~1u;
  return irq_nesting_or_d104(1024);
}

