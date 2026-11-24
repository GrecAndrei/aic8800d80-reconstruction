// sub_100730 @ 0x100730, size 46 bytes
_DWORD *sub_100730()
{
  _DWORD *result; // r0
  int *v1; // r2

  result = off_100764;
  v1 = (int *)off_100768;
  *(_DWORD *)off_100760 |= 0x10000u;
  *result = 0;
  *v1 = *v1 & 0x1FFFFFFE | 0x20000001;
  return result;
}

