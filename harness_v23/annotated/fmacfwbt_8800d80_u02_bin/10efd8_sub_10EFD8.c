// v23 annotated: sub_10EFD8 @ 0x10efd8
// Original: 10efd8_sub_10EFD8.c
// Primary struct: log_state (cluster 11, 4 funcs)
// Fields: enable=0x0, state=0x0, level=0x4, flag=0x7, count=0x8, tick=0xa, buf=0x14, status=0x16a
//
// sub_10EFD8 @ 0x10efd8, size 18 bytes
unsigned int sub_10EFD8()
{
  unsigned int result; // r0

  result = rf_power_set(0xC2u);
  *((_BYTE *)off_10EFEC + 7) = -62;
  return result;
}

