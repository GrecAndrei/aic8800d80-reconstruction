// sub_115FF0 @ 0x115ff0, size 34 bytes
int  sub_115FF0(int a1, int a2, int a3)
{
  int v3; // r3

  v3 = dword_116014;
  **(uint32_t **)(a1 + 32) = a2;
  list_push_tail(v3 + 8 * a3);
  return irq_nesting_or(*(uint32_t *)(dword_116018 + 4 * a3));
}

