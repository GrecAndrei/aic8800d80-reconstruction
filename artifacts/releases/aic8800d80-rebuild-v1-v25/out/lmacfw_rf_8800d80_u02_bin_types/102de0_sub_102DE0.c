// sub_102DE0 @ 0x102de0, size 26 bytes
BOOL sub_102DE0()
{
  BOOL result; // r0

  result = (*(uint32_t *)off_102DFC >> 27) & 1;
  if ( (*(uint32_t *)off_102DFC & 0x8000000) != 0 )
    return (*(uint32_t *)off_102E00 & 0x400) == 0;
  return result;
}

