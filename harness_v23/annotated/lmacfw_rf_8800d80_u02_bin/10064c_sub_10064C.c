// v23 annotated: sub_10064C @ 0x10064c
// Original: 10064c_sub_10064C.c
// Primary struct: <unclustered>
//
// sub_10064C @ 0x10064c, size 46 bytes
_DWORD *sub_10064C()
{
  _DWORD *result; // r0
  int *v1; // r2

  result = off_100680;
  v1 = (int *)off_100684;
  *(_DWORD *)off_10067C |= 0x10000u;
  *result = 0;
  *v1 = *v1 & 0x1FFFFFFE | 0x20000001;
  return result;
}

