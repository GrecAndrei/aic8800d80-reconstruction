// v23 annotated: sub_12F754 @ 0x12f754
// Original: 12f754_sub_12F754.c
// Primary struct: <unclustered>
//
// sub_12F754 @ 0x12f754, size 18 bytes
int sub_12F754()
{
  int result; // r0

  if ( **(_BYTE **)off_12F768 != 3 )
    return 1;
  result = *(_DWORD *)(*(_DWORD *)off_10CA30 + 548);
  *(_DWORD *)off_10CA34 = 32;
  if ( result )
    return 1;
  *(_DWORD *)off_10CA38 = 32;
  return result;
}

