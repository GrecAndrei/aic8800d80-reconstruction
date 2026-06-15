// v23 annotated: sub_100D94 @ 0x100d94
// Original: 100d94_sub_100D94.c
// Primary struct: <unclustered>
//
// sub_100D94 @ 0x100d94, size 172 bytes
_DWORD *sub_100D94()
{
  unsigned int *v0; // r3
  _DWORD *v1; // r1
  unsigned int v2; // r4
  _DWORD *result; // r0
  _DWORD *v4; // r3

  v0 = (unsigned int *)off_100E44;
  v1 = off_100E48;
  v2 = *(_DWORD *)off_100E44;
  result = off_100E4C;
  *(_DWORD *)off_100E48 = (*((unsigned __int8 *)off_100E40 + 1) << 10) & 0x1FC00 | *(_DWORD *)off_100E48 & 0xFFFE03FF;
  *v0 = *v0 & 0xFFFFFFE7 | 8;
  *v0 |= 7u;
  *v1 &= ~0x80000u;
  *v1 &= ~0x40000u;
  *v0 = *v0 & 0xFFFFFC1F | 0x80;
  *result |= 2u;
  *result &= ~1u;
  if ( ((v2 >> 5) & 0x1F) != 4 )
  {
    v4 = off_100E50;
    *(_DWORD *)off_100E50 |= 0x80u;
    *v4 &= ~0x40u;
    *v4 |= 0x40u;
    *v4 &= ~0x80u;
  }
  return result;
}

