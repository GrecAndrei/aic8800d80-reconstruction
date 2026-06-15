// v23 annotated: sub_11CD68 @ 0x11cd68
// Original: 11cd68_sub_11CD68.c
// Primary struct: <unclustered>
//
// sub_11CD68 @ 0x11cd68, size 56 bytes
int sub_11CD68()
{
  int result; // r0

  if ( **(__int16 **)off_11CDA0 < 0 && *(_DWORD *)off_11CDA8 << 28 )
    return sub_121960(dword_11CDB0, dword_11CDAC, 105, *(_DWORD *)off_11CDA8);
  if ( (*(_DWORD *)off_11CDA4 & 0x80) != 0 )
  {
    *(_DWORD *)off_11CDA4 &= ~0x80u;
    return sub_11E5E0(0x2000000);
  }
  return result;
}

