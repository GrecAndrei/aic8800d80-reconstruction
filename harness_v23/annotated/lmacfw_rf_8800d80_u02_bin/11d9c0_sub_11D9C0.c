// v23 annotated: sub_11D9C0 @ 0x11d9c0
// Original: 11d9c0_sub_11D9C0.c
// Primary struct: group_18 (cluster 18)
//
// sub_11D9C0 @ 0x11d9c0, size 22 bytes
int sub_11D9C0()
{
  *(_DWORD *)(dword_11D9D8 + 4680) &= ~1u;
  return irq_nesting_or(0x8000);
}

