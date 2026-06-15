// v23 annotated: sub_11EA84 @ 0x11ea84
// Original: 11ea84_sub_11EA84.c
// Primary struct: <unclustered>
//
// sub_11EA84 @ 0x11ea84, size 44 bytes
int sub_11EA84()
{
  _DWORD *v0; // r2
  int result; // r0

  v0 = off_11EAB4;
  *(_DWORD *)off_11EAB0 = 0x10000;
  *v0 &= ~0x10000u;
  result = sub_12CFC4(0x80000);
  if ( *(_BYTE *)off_11EAB8 )
    return sub_122180(result);
  return result;
}

