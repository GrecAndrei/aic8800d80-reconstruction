// fwstruct annotate: 12b8bc_sub_12B8BC.c
// sub_12B8BC @ 0x12b8bc, size 502 bytes
int sub_12B8BC()
{
  _DWORD *v0; // r2
  unsigned int v1; // r0
  _DWORD *v2; // r3
  _DWORD *v3; // r2
  __int16 **v4; // r1
  char *v5; // r0
  int *v6; // r3
  _DWORD *v7; // r1
  int v8; // r2
  int *v9; // r4
  int v10; // r5
  _BYTE *v11; // r1
  int *v12; // r3
  _DWORD *v13; // r3
  _DWORD *v14; // r4
  unsigned int *v15; // r6
  _DWORD *v16; // r2
  _DWORD *v17; // r5
  int result; // r0
  _DWORD *v19; // r1
  _BYTE **v20; // r2
  _DWORD *v21; // r4
  _DWORD *v22; // r6
  int v23; // r0
  unsigned int *v24; // r5
  unsigned __int8 v25; // [sp+6h] [bp-2h] BYREF
  unsigned __int8 v26; // [sp+7h] [bp-1h] BYREF

  v0 = off_12BAB4;
  *(_DWORD *)off_12BAB4 = 1;
  while ( (unsigned __int8)*v0 )
    ;
  v1 = sub_1006CC();
  sub_12B5A0(v1);
  v2 = off_12BABC;
  *(_DWORD *)off_12BAB8 = dword_12BAC0;
  v3 = off_12BAC4;
  *v2 = 0x80000000;
  v4 = (__int16 **)off_12BAC8;
  *v3 &= ~0x800u;
  if ( **v4 < 0 && *(_DWORD *)off_12BACC < 0x2F000000u )
    sub_12F46C(dword_12BB18, dword_12BB14, 284);
  v5 = (char *)off_12BACC;
  v6 = (int *)off_12BAD0;
  v7 = off_12BAC4;
  v8 = dword_12BAD8;
  *(_DWORD *)off_12BACC = dword_12BAD4;
  *v6 = v8;
  v9 = (int *)off_12BADC;
  v10 = dword_12BAE0;
  *v7 |= 0x40007C0u;
  *v7 &= ~0x4000000u;
  v11 = off_12BAE4;
  v12 = v6 - 8199;
  *(_DWORD *)&v5[-132] |= 0x10000u;
  *v9 = v10;
  *v12 |= 0xFF000000;
  *v12 |= 0x800000u;
  *v12 = *v12 & 0xFF80FFFF | 0x100000;
  if ( !v11[2] )
    *v12 = (HIWORD(*v12) << 16) | 0x64;
  v13 = off_12BAE8;
  v14 = off_12BAC4;
  v15 = (unsigned int *)off_12BAF0;
  *(_DWORD *)off_12BAEC = 12288;
  *v13 = 0;
  sub_102B4C(&v26, &v25);
  v16 = off_12BAF8;
  *(_DWORD *)off_12BAF4 = (v26 << 8) | (v25 << 16) | v26;
  v17 = off_12BAFC;
  *v14 |= 0x1000u;
  *v14 |= 0x2000u;
  *v16 |= 0x80000u;
  *v16 &= ~0x80u;
  result = sub_101AD8();
  v19 = off_12BB00;
  *v15 = ((result + 1) << 26) & 0x1C000000 | *v15 & 0xE3FFFFFF;
  v20 = (_BYTE **)off_12BB04;
  *v14 |= 0x20u;
  *v17 &= ~1u;
  *v19 |= 2u;
  if ( **v20 == 1 )
    *(_DWORD *)off_12BB08 &= 0x80FFFFFF;
  v21 = off_12BAC4;
  v22 = off_12BB0C;
  *(_DWORD *)off_12BAC4 |= 0x2000000u;
  if ( (*v22 & 0x20000) != 0 )
  {
    result = sub_101A48();
    if ( result )
    {
      v23 = sub_101AC4();
      v24 = (unsigned int *)off_12BB1C;
      result = v23 << 8;
      *(_DWORD *)off_12BB1C = result & 0x700 | *(_DWORD *)off_12BB1C & 0xFFFFF8FF;
      *v24 = *v24 & 0xFFFFFF1F | 0x60;
      *v24 |= 4u;
      *v24 |= 1u;
      if ( (*v22 & 0x8000) != 0 )
      {
        result = sub_1019FC();
        if ( result )
        {
          *v21 |= 0x80000u;
          *v24 = *v24 & 0xF1FFFFFF | 0x4000000;
        }
      }
      if ( (*(_DWORD *)off_12BB0C & 0x20000) != 0 )
      {
        result = sub_101A58();
        if ( result )
          *(_DWORD *)off_12BB1C |= 2u;
      }
    }
  }
  *(_DWORD *)off_12BB10 |= 1u;
  return result;
}

