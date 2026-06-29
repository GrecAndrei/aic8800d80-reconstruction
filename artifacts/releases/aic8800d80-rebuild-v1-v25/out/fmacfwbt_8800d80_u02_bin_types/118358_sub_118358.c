// sub_118358 @ 0x118358, size 44 bytes
int  sub_118358(int a1, int a2, int a3)
{
  int v3; // r3
  int v5; // r0
  int result; // r0

  v3 = *(uint32_t *)(a1 + 76);
  v5 = dword_118384;
  *(uint32_t *)(v3 + 4) = a2;
  result = list_push_tail(v5 + 8 * a3);
  if ( (*(uint32_t *)(a1 + 36) & 0x200000) == 0 )
    return irq_nesting_or(*(uint32_t *)(dword_118388 + 4 * a3));
  return result;
}

