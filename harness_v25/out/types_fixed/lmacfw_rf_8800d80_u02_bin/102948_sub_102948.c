// sub_102948 @ 0x102948, size 24 bytes
int sub_102948()
{
  int result; // r0

  result = mmio_set_bit_120090C(*((unsigned __int8 *)off_102960 + 36), *((unsigned __int16 *)off_102960 + 20));
  ++*(_BYTE *)off_102964;
  return result;
}

