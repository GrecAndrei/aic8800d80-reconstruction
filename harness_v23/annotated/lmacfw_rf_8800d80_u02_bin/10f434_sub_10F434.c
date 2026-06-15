// v23 annotated: sub_10F434 @ 0x10f434
// Original: 10f434_sub_10F434.c
// Primary struct: log_state (cluster 19, 4 funcs)
// Fields: enable=0x0, state=0x0, level=0x4, flag=0x7, count=0x8, tick=0xa, buf=0x14, status=0x16a
//
// sub_10F434 @ 0x10f434, size 18 bytes
unsigned int sub_10F434()
{
  unsigned int result; // r0

  result = sub_1029DC(0xC2u);
  *((_BYTE *)off_10F448 + 7) = -62;
  return result;
}

