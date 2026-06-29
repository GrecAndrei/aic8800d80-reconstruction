// fwstruct annotate: 12f3f8_sub_12F3F8.c
// sub_12F3F8 @ 0x12f3f8, size 18 bytes
int sub_12F3F8()
{
  int result; // r0

  if ( **(_BYTE **)off_12F40C != 3 )
    return 1;
  result = *(_DWORD *)(*(_DWORD *)off_10CA98 + 612);
  *(_DWORD *)off_10CA9C = 32;
  if ( result )
    return 1;
  *(_DWORD *)off_10CAA0 = 32;
  return result;
}

