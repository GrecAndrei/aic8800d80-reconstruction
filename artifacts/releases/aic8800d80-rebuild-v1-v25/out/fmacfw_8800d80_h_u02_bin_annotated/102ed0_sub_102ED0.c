// fwstruct annotate: 102ed0_sub_102ED0.c
// sub_102ED0 @ 0x102ed0, size 576 bytes
int sub_102ED0()
{
  _BYTE *v0; // r3
  _DWORD *v1; // r2
  _DWORD *v2; // r1
  unsigned int *v3; // r2
  unsigned int *v4; // r0
  _DWORD *v5; // r5
  unsigned int *v6; // r4
  _DWORD *v7; // r6
  _DWORD *v8; // r3
  _DWORD *v9; // r0
  _DWORD *v10; // r2
  unsigned __int8 *v11; // r4
  _DWORD *v12; // r3
  _DWORD *v13; // r4
  unsigned int *v14; // r2
  unsigned __int8 *v15; // r0
  _DWORD *v16; // r1
  int result; // r0
  unsigned int *v18; // r2
  _DWORD *v19; // r3
  _DWORD *v20; // r3
  _DWORD *v21; // r2
  unsigned int *v22; // r0
  _DWORD *v23; // r2

  if ( *((_BYTE *)off_103110 + 2) )
  {
    *(_DWORD *)off_103168 = *(_DWORD *)off_103168 & 0xFFFFF3FF | 0x800;
  }
  else
  {
    v0 = off_103114;
    v1 = off_103118;
    *(_BYTE *)off_103114 = 80;
    v0[1] = 78;
    while ( !*v1 )
      ;
    v2 = off_103120;
    *(_DWORD *)off_10311C &= ~2u;
    if ( (*v2 & 1) == 0 )
    {
      sub_100E24(1);
      v23 = off_103128;
      *(_DWORD *)off_10317C = *(_DWORD *)off_10317C & 0xFFFFFFF0 | 4;
      *v23 |= 2u;
    }
    v3 = (unsigned int *)off_103124;
    v4 = (unsigned int *)off_103128;
    v5 = off_10312C;
    v6 = (unsigned int *)off_103130;
    v7 = off_103134;
    *(_DWORD *)off_103118 = 1;
    *v3 = *v3 & 0xC3FFFFFF | 0x30000000;
    *v4 = *v4 & 0xFE3FFFFF | 0x400000;
    *v5 |= 0x78000u;
    *v4 &= ~2u;
    v8 = off_103138;
    *v3 = *v3 & 0xFF0FFFFF | 0xC00000;
    *v3 = *v3 & 0xFFFFFF0F | 0x60;
    v9 = off_10313C;
    v5 -= 463846;
    *v6 &= ~1u;
    *v5 = *v5 & 0xFFFFE0FF | 0x1000;
    *v8 |= 8u;
    *v8 &= 0xFFFFFFFC;
    *v7 &= ~0x40000u;
    *v8 &= ~4u;
    v10 = off_103140;
    *v6 = *v6 & 0xFFFFF3FF | 0x800;
    v11 = (unsigned __int8 *)off_103144;
    v5 -= 1999;
    *v9 &= 0xFFFF3FFF;
    *v5 = *v5 & 0xFFFFFF | 0x10000000;
    v9 -= 2043;
    *v10 = *v10 & 0xFFFC00FF | (*v11 << 8);
    v12 = off_103148;
    v5 -= 73;
    *v9 |= 0x80000000;
    *v5 |= 0x1000u;
    *v10 &= ~0x40000u;
    *v9 &= ~0x40000000u;
    v13 = off_10314C;
    *v12 &= ~2u;
    *v12 |= 1u;
    v10 += 2062;
    v5[2083] = 20058;
    *v10 = *v10 & 0x3FFFFFF | 0x7C000000;
    *v10 = *v10 & 0xFC07FFFF | 0x3D00000;
    if ( (*v13 & 0x20) != 0 )
    {
      v20 = off_103170;
      *((_BYTE *)off_103150 + 1) = 1;
      v21 = off_103174;
      v22 = (unsigned int *)off_103178;
      *v20 &= 0xFFF0FFFF;
      *v20 &= 0xFF0FFFFF;
      *v21 &= ~0x8000u;
      *v22 = *v22 & 0xFFFFFC7F | 0x200;
    }
    else
    {
      *((_BYTE *)off_103150 + 1) = 0;
    }
    v14 = (unsigned int *)off_103154;
    v15 = (unsigned __int8 *)off_103158;
    v16 = off_10315C;
    *(_DWORD *)off_103154 = *(_DWORD *)off_103154 & 0x3FFFFFF | 0xA0000000;
    result = v15[362];
    *v14 = *v14 & 0xFC0FFFFF | 0x1800000;
    *v16 |= 0x10u;
    if ( result )
      *(v14 - 8824) = *(v14 - 8824) & 0xFFFFFFC0 | 0x2C;
    v18 = (unsigned int *)off_103164;
    *(_DWORD *)off_103160 &= 0xFFFFFFC7;
    *v18 = *v18 & 0xFFFFFFFC | 2;
  }
  v19 = off_10316C;
  *(_DWORD *)off_10316C |= 0xC000u;
  *v19 |= 0x30000u;
  return result;
}

