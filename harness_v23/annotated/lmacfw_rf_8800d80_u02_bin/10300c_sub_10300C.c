// v23 annotated: sub_10300C @ 0x10300c
// Original: 10300c_sub_10300C.c
// Primary struct: <unclustered>
//
// sub_10300C @ 0x10300c, size 600 bytes
void sub_10300C()
{
  _BYTE *v0; // r3
  _DWORD *v1; // r2
  _DWORD *v2; // r1
  _BYTE *v3; // r3
  int v4; // r2
  unsigned int *v5; // r4
  unsigned int *v6; // r0
  _DWORD *v7; // r5
  _DWORD *v8; // r3
  _DWORD *v9; // r6
  _DWORD *v10; // r1
  unsigned __int8 *v11; // r0
  _DWORD *v12; // r3
  int *v13; // r0
  unsigned int v14; // r3
  int v15; // r3
  unsigned int *v16; // r2
  unsigned __int8 *v17; // r0
  _DWORD *v18; // r1
  int v19; // r0
  unsigned int *v20; // r2
  _DWORD *v21; // r3
  _DWORD *v22; // r3
  _DWORD *v23; // r2
  unsigned int *v24; // r0
  unsigned int *v25; // r1
  _DWORD *v26; // r0
  _DWORD *v27; // r2

  if ( *((_BYTE *)off_103264 + 2) )
  {
    *(_DWORD *)off_1032BC = *(_DWORD *)off_1032BC & 0xFFFFF3FF | 0x800;
  }
  else
  {
    v0 = off_103268;
    v1 = off_10326C;
    *(_BYTE *)off_103268 = 80;
    v0[1] = 78;
    while ( !*v1 )
      ;
    v2 = off_103274;
    *(_DWORD *)off_103270 &= ~2u;
    if ( (*v2 & 1) == 0 )
    {
      sub_100C3C(1);
      v27 = off_1032D0;
      *(_DWORD *)off_1032D8 = *(_DWORD *)off_1032D8 & 0xFFFFFFF0 | 4;
      *v27 |= 2u;
    }
    v3 = off_103278;
    *(_DWORD *)off_10326C = 1;
    v4 = *v3 & 0xC0;
    if ( v4 == 192 )
    {
      v25 = (unsigned int *)off_1032D0;
      v26 = off_1032D4;
      *(_DWORD *)off_10327C = *(_DWORD *)off_10327C & 0xC3FFFFFF | 0x30000000;
      *v25 = *v25 & 0xFE3FFFFF | 0x400000;
      *v26 |= 0x78000u;
      *v25 &= ~2u;
    }
    v5 = (unsigned int *)off_10327C;
    v6 = (unsigned int *)off_103280;
    v7 = off_103284;
    v8 = off_103288;
    v9 = off_10328C;
    *(_DWORD *)off_10327C = *(_DWORD *)off_10327C & 0xFF0FFFFF | 0xC00000;
    *v5 = *v5 & 0xFFFFFF0F | 0x60;
    *v6 &= ~1u;
    *v7 = *v7 & 0xFFFFE0FF | 0x1000;
    *v8 |= 8u;
    *v8 &= 0xFFFFFFFC;
    *(unsigned int *)((char *)v5 + 0xFFFFFFB8) &= ~0x40000u;
    *v8 &= ~4u;
    v10 = off_103290;
    *v6 = *v6 & 0xFFFFF3FF | 0x800;
    v11 = (unsigned __int8 *)off_103294;
    v7 -= 1999;
    *v9 &= 0xFFFF3FFF;
    v5 -= 2068;
    *v7 = *v7 & 0xFFFFFF | 0x10000000;
    *v5 = *v5 & 0xFFFC00FF | (*v11 << 8);
    v12 = off_103298;
    v7 -= 73;
    *v10 |= 0x80000000;
    *v7 |= 0x1000u;
    *v5 &= ~0x40000u;
    v13 = (int *)off_10329C;
    *v10 &= ~0x40000000u;
    *v12 &= ~2u;
    *v12 |= 1u;
    v7[2083] = 20058;
    *v13 = *v13 & 0x3FFFFFF | 0x7C000000;
    v14 = *v13 & 0xFC07FFFF;
    if ( v4 == 192 )
      v15 = v14 | 0x3D00000;
    else
      v15 = v14 | 0x3E00000;
    *v13 = v15;
    if ( (*(_DWORD *)off_1032A0 & 0x20) != 0 )
    {
      v22 = off_1032C4;
      v23 = off_1032C8;
      v24 = (unsigned int *)off_1032CC;
      *((_BYTE *)off_1032A4 + 1) = 1;
      *v22 &= 0xFFF0FFFF;
      *v22 &= 0xFF0FFFFF;
      *v23 &= ~0x8000u;
      *v24 = *v24 & 0xFFFFFC7F | 0x200;
    }
    else
    {
      *((_BYTE *)off_1032A4 + 1) = 0;
    }
    v16 = (unsigned int *)off_1032A8;
    v17 = (unsigned __int8 *)off_1032AC;
    v18 = off_1032B0;
    *(_DWORD *)off_1032A8 = *(_DWORD *)off_1032A8 & 0x3FFFFFF | 0xA0000000;
    v19 = v17[362];
    *v16 = *v16 & 0xFC0FFFFF | 0x1800000;
    *v18 |= 0x10u;
    if ( v19 )
      *(v16 - 8824) = *(v16 - 8824) & 0xFFFFFFC0 | 0x2C;
    v20 = (unsigned int *)off_1032B8;
    *(_DWORD *)off_1032B4 &= 0xFFFFFFC7;
    *v20 = *v20 & 0xFFFFFFFC | 2;
  }
  v21 = off_1032C0;
  *(_DWORD *)off_1032C0 |= 0xC000u;
  *v21 |= 0x30000u;
}

