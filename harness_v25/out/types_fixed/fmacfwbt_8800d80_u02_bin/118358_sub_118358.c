// sub_118358 @ 0x118358, size 44 bytes
int __fastcall sub_118358(int a1, int a2, int a3)
{
  int v3; // r3
  int v5; // r0
  int result; // r0

  v3 = *(_DWORD *)(a1 + 76);
  v5 = dword_118384;
  *(_DWORD *)(v3 + 4) = a2;
  result = list_push_tail(v5 + 8 * a3);
  if ( (*(_DWORD *)(a1 + 36) & 0x200000) == 0 )
    return irq_nesting_or(*(_DWORD *)(dword_118388 + 4 * a3));
  return result;
}

