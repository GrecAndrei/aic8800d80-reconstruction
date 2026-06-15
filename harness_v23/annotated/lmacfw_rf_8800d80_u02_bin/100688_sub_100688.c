// v23 annotated: sub_100688 @ 0x100688
// Original: 100688_sub_100688.c
// Primary struct: <unclustered>
//
// sub_100688 @ 0x100688, size 42 bytes
_DWORD *sub_100688()
{
  _DWORD *result; // r0
  unsigned int *v1; // r2

  result = off_1006B8;
  v1 = (unsigned int *)off_1006BC;
  *(_DWORD *)off_1006B4 &= ~0x10000u;
  *result = 1;
  *v1 = *v1 & 0x1FFFFFFE | 0xC0000000;
  return result;
}

