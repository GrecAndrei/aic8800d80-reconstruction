// v23 annotated: sub_12C444 @ 0x12c444
// Original: 12c444_sub_12C444.c
// Primary struct: <unclustered>
//
// sub_12C444 @ 0x12c444, size 22 bytes
int sub_12C444()
{
  *(_DWORD *)(dword_12C45C + 4808) &= ~1u;
  return irq_nesting_or_d104(0x40000000);
}

