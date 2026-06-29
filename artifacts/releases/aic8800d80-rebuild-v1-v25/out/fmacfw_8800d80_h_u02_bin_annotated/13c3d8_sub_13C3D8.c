// fwstruct annotate: 13c3d8_sub_13C3D8.c
// sub_13C3D8 @ 0x13c3d8, size 374 bytes
unsigned int __fastcall sub_13C3D8(unsigned __int8 *a1, int a2, int a3, _BYTE *a4)
{
  int v4; // r6
  int v5; // r11
  int v6; // r9
  int v10; // r2
  int v11; // r3
  int v12; // r8
  int v13; // r7
  _BYTE *v15; // r0
  int v16; // lr
  int v17; // r12
  _BYTE *v18; // r1
  _BYTE *v19; // r0
  _BYTE *v20; // r1
  int v21; // t1
  int v22; // r9
  int v23; // r10
  int v24; // r0
  int v25; // r1
  bool v26; // zf
  int v27; // r11
  __int64 v28; // [sp+8h] [bp-Ch]

  v4 = a1[8];
  v5 = *(unsigned __int16 *)a1;
  v6 = *(unsigned __int8 *)(v4 + a2);
  if ( !sub_13C344(v5, v6) )
    return 0;
  v11 = a1[9];
  if ( v11 == 255 )
    goto LABEL_9;
  v12 = a1[10];
  if ( v12 == 255 )
    goto LABEL_9;
  v13 = v10;
  if ( !*(_DWORD *)(dword_13C550 + 1320 * v12 + 1200) )
    return 0;
  if ( (a1[48] & 8) == 0 )
  {
    if ( (*(_DWORD *)(dword_13C554 + 696 * v11 + 4) & 8) != 0 && (v5 & 0x4000) == 0 )
    {
      v27 = v5 & 0xFC;
      if ( (v27 == 192 || v27 == 160) && (unsigned int)(v6 - 6) <= 1 )
      {
        *a4 = 1;
        return 1;
      }
LABEL_9:
      *a4 = 0;
      return 1;
    }
    return 0;
  }
  if ( (v5 & 0xFC) != 0xD0 || (unsigned int)(v6 - 13) > 1 )
  {
    if ( *(_DWORD *)(dword_13C550 + 1320 * v12 + 1204) )
    {
      if ( v4 + 19 >= v10 )
        goto LABEL_9;
      v15 = sub_12DA60((_BYTE *)(v4 + a2 + 2), (unsigned __int16)(v10 - 2 - v4));
      if ( !v15 )
        goto LABEL_9;
      v16 = *((unsigned __int16 *)v15 + 1);
      if ( (unsigned int)(v16 - 4) > 1 )
        goto LABEL_9;
      v17 = 1320 * v12 + 120 * v16 + dword_13C550;
      if ( !*(_BYTE *)(v17 + 579) )
        goto LABEL_9;
      v28 = *((_DWORD *)v15 + 1) & 0xFFFFFFLL;
      if ( *(_QWORD *)(v17 + 480) >= (unsigned __int64)(*((_DWORD *)v15 + 1) & 0xFFFFFF) )
        goto LABEL_9;
      v18 = v15;
      v19 = v15 + 18;
      v21 = *(_DWORD *)(v18 + 10);
      v20 = v18 + 10;
      v22 = v21;
      v23 = *((_DWORD *)v20 + 1);
      *(_QWORD *)(v17 + 480) = v28;
      do
        *v20++ = 0;
      while ( v20 != v19 );
      v24 = sub_13CAAC(1320 * v12 + 480 + 120 * v16 + dword_13C550, a2, v13 - 18, v4, 0);
      v26 = v23 == v25;
      if ( v23 == v25 )
        v26 = v22 == v24;
      if ( !v26 )
        goto LABEL_9;
    }
    return 0;
  }
  return ((v5 ^ 0x4000u) >> 14) & 1;
}

