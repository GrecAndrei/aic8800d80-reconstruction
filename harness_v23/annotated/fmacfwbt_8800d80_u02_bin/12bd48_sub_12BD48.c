// v23 annotated: sub_12BD48 @ 0x12bd48
// Original: 12bd48_sub_12BD48.c
// Primary struct: group_20 (cluster 20)
//
// sub_12BD48 @ 0x12bd48, size 32 bytes
// Doc: sub_122BD48 [mmio]: Clear high bit in MMIO registers at 0x403280xx
// sub_122BD48 [mmio]: Clear high bit in MMIO registers at 0x403280xx
void *sub_12BD48()
{
  void *result; // r0
  _DWORD *v1; // r1
  _DWORD *v2; // r2

  result = off_12BD68;
  v1 = off_12BD6C;
  v2 = off_12BD70;
  *(_DWORD *)off_12BD68 &= ~0x80000000;
  *v1 &= ~0x80000000;
  *v2 &= ~0x80000000;
  return result;
}

