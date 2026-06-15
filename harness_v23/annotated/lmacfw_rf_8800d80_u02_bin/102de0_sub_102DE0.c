// v23 annotated: sub_102DE0 @ 0x102de0
// Original: 102de0_sub_102DE0.c
// Primary struct: <unclustered>
//
// sub_102DE0 @ 0x102de0, size 26 bytes
BOOL sub_102DE0()
{
  BOOL result; // r0

  result = (*(_DWORD *)off_102DFC >> 27) & 1;
  if ( (*(_DWORD *)off_102DFC & 0x8000000) != 0 )
    return (*(_DWORD *)off_102E00 & 0x400) == 0;
  return result;
}

