// fwstruct annotate: 11d3dc_sub_11D3DC.c
// sub_11D3DC @ 0x11d3dc, size 110 bytes
unsigned int sub_11D3DC()
{
  _DWORD *v0; // r2
  _DWORD *v1; // r0
  __int16 **v2; // r5
  int *v3; // r4
  int v4; // r3
  __int16 *v5; // r2
  unsigned int result; // r0
  _DWORD *v7; // r2

  v0 = off_11D44C;
  v1 = off_11D450;
  *(_DWORD *)off_11D44C &= ~1u;
  v2 = (__int16 **)off_11D454;
  v3 = (int *)off_11D458;
  v4 = dword_11D45C;
  *v0 &= ~2u;
  *v1 |= 0x700u;
  v5 = *v2;
  *v3 = v4;
  if ( *v5 < 0 && *(_DWORD *)off_11D464 << 28 )
  {
    sub_1219F4(dword_11D46C, dword_11D468, 472);
    v4 = *v3;
  }
  *(_DWORD *)off_11D460 = v4 | v3[1];
  result = sub_1174B8(1);
  v7 = off_11D450;
  *(_DWORD *)off_11D450 = *(_DWORD *)off_11D450 & 0xFFFE3FFF | 0x10000;
  *v7 |= 0x2000u;
  return result;
}

