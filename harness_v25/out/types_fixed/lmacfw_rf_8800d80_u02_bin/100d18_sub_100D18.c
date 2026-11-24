// sub_100D18 @ 0x100d18, size 208 bytes
unsigned int sub_100D18()
{
  unsigned int *v0; // r2
  unsigned int v1; // r1
  _BYTE *v2; // r5
  int v3; // r1
  unsigned int v4; // r3
  unsigned int *v5; // r3
  unsigned int *v6; // r4
  _DWORD *v7; // r2
  unsigned int result; // r0
  _DWORD *v9; // r3

  v0 = (unsigned int *)off_100DEC;
  v1 = *(_DWORD *)off_100DEC;
  v2 = off_100DF4;
  *(_DWORD *)off_100DF0 = (*((unsigned __int8 *)off_100DE8 + 1) << 10) & 0x1FC00 | *(_DWORD *)off_100DF0 & 0xFFFE03FF;
  v3 = (v1 >> 5) & 0x1F;
  v4 = *v0 & 0xFFFFFFE7;
  if ( (*v2 & 0xC0) == 0xC0 )
  {
    *v0 = v4 | 0x10;
    *v0 = *v0 & 0xFFFFFFF8 | 1;
  }
  else
  {
    *v0 = v4 | 8;
    *v0 |= 7u;
  }
  v5 = (unsigned int *)off_100DF0;
  v6 = (unsigned int *)off_100DEC;
  v7 = off_100DF8;
  *(_DWORD *)off_100DF0 &= ~0x80000u;
  result = *v5 & 0xFFFBFFFF;
  *v5 = result;
  *v6 = *v6 & 0xFFFFFC1F | 0x80;
  *v7 |= 2u;
  *v7 &= ~1u;
  if ( v3 != 4 )
  {
    v9 = off_100DFC;
    *(_DWORD *)off_100DFC |= 0x80u;
    *v9 &= ~0x40u;
    *v9 |= 0x40u;
    *v9 &= ~0x80u;
  }
  return result;
}

