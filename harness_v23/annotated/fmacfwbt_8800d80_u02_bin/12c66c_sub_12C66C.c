// v23 annotated: sub_12C66C @ 0x12c66c
// Original: 12c66c_sub_12C66C.c
// Primary struct: group_27 (cluster 27)
//
// sub_12C66C @ 0x12c66c, size 22 bytes
int sub_12C66C()
{
  *(_DWORD *)(dword_12C684 + 4808) &= ~1u;
  return irq_nesting_or(0x40000000);
}

