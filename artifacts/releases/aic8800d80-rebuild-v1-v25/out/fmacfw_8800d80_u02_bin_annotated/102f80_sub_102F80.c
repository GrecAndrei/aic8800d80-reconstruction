// fwstruct annotate: 102f80_sub_102F80.c
// sub_102F80 @ 0x102f80, size 534 bytes
int sub_102F80()
{
  _BYTE *v0; // r3
  _DWORD *v1; // r2
  _DWORD *v2; // r1
  unsigned int *v3; // r4
  unsigned int *v4; // r0
  unsigned int *v5; // r5
  _DWORD *v6; // r3
  unsigned __int8 *v7; // r6
  _DWORD *v8; // r1
  _DWORD *v9; // r3
  _DWORD *v10; // r4
  unsigned int *v11; // r2
  unsigned __int8 *v12; // r0
  _DWORD *v13; // r1
  int result; // r0
  unsigned int *v15; // r2
  _DWORD *v16; // r3
  _DWORD *v17; // r3
  _DWORD *v18; // r2
  unsigned int *v19; // r0
  _DWORD *v20; // r2

  if ( *((_BYTE *)off_103198 + 2) )
  {
    *(_DWORD *)off_1031E4 = *(_DWORD *)off_1031E4 & 0xFFFFF3FF | 0x800;
  }
  else
  {
    v0 = off_10319C;
    v1 = off_1031A0;
    *(_BYTE *)off_10319C = 80;
    v0[1] = 78;
    while ( !*v1 )
      ;
    v2 = off_1031A8;
    *(_DWORD *)off_1031A4 &= ~2u;
    if ( (*v2 & 1) == 0 )
    {
      sub_100E24(1);
      v20 = off_1031FC;
      *(_DWORD *)off_1031F8 = *(_DWORD *)off_1031F8 & 0xFFFFFFF0 | 4;
      *v20 |= 2u;
    }
    v3 = (unsigned int *)off_1031AC;
    v4 = (unsigned int *)off_1031B0;
    v5 = (unsigned int *)off_1031B4;
    v6 = off_1031B8;
    v7 = (unsigned __int8 *)off_1031BC;
    *(_DWORD *)off_1031A0 = 1;
    *v3 = *v3 & 0xFF0FFFFF | 0xC00000;
    *v3 = *v3 & 0xFFFFFF0F | 0x60;
    *v4 &= ~1u;
    *v5 = *v5 & 0xFFFFE0FF | 0x1000;
    *v6 |= 8u;
    *v6 &= 0xFFFFFFFC;
    *(unsigned int *)((char *)v3 + 0xFFFFFFB8) &= ~0x40000u;
    *v6 &= ~4u;
    v8 = off_1031C0;
    *v4 = *v4 & 0xFFFFF3FF | 0x800;
    *(unsigned int *)((char *)v5 + 0xFFFFFF94) &= 0xFFFF3FFF;
    *(v3 - 1996) = *(v3 - 1996) & 0xFFFFFF | 0x10000000;
    v4 -= 2045;
    *v8 = *v8 & 0xFFFC00FF | (*v7 << 8);
    v9 = off_1031C4;
    v5 -= 2072;
    *v4 |= 0x80000000;
    *v5 |= 0x1000u;
    *v8 &= ~0x40000u;
    *v4 &= ~0x40000000u;
    v10 = off_1031C8;
    *v9 &= ~2u;
    *v9 |= 1u;
    v8 += 2062;
    v5[2083] = 20058;
    *v8 = *v8 & 0x3FFFFFF | 0x7C000000;
    *v8 = *v8 & 0xFC07FFFF | 0x3E00000;
    if ( (*v10 & 0x20) != 0 )
    {
      v17 = off_1031EC;
      *((_BYTE *)off_1031CC + 1) = 1;
      v18 = off_1031F0;
      v19 = (unsigned int *)off_1031F4;
      *v17 &= 0xFFF0FFFF;
      *v17 &= 0xFF0FFFFF;
      *v18 &= ~0x8000u;
      *v19 = *v19 & 0xFFFFFC7F | 0x200;
    }
    else
    {
      *((_BYTE *)off_1031CC + 1) = 0;
    }
    v11 = (unsigned int *)off_1031D0;
    v12 = (unsigned __int8 *)off_1031D4;
    v13 = off_1031D8;
    *(_DWORD *)off_1031D0 = *(_DWORD *)off_1031D0 & 0x3FFFFFF | 0xA0000000;
    result = v12[362];
    *v11 = *v11 & 0xFC0FFFFF | 0x1800000;
    *v13 |= 0x10u;
    if ( result )
      *(v11 - 8824) = *(v11 - 8824) & 0xFFFFFFC0 | 0x2C;
    v15 = (unsigned int *)off_1031E0;
    *(_DWORD *)off_1031DC &= 0xFFFFFFC7;
    *v15 = *v15 & 0xFFFFFFFC | 2;
  }
  v16 = off_1031E8;
  *(_DWORD *)off_1031E8 |= 0xC000u;
  *v16 |= 0x30000u;
  return result;
}

