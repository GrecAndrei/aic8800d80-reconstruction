// sub_11C5D8 @ 0x11c5d8, size 748 bytes
int __fastcall sub_11C5D8(int a1, int a2)
{
  unsigned __int8 *v2; // r5
  int v3; // r11
  _DWORD *v4; // r7
  int v5; // r6
  int v7; // r10
  int v8; // r0
  int v9; // r9
  __int16 v10; // r3
  __int16 v11; // r3
  void *v12; // r1
  int v13; // r2
  int v14; // r3
  int v15; // r8
  int v16; // r7
  int result; // r0
  int v18; // r9
  int v19; // r3
  int v20; // r10
  int v21; // r11
  int v22; // r1
  __int64 v23; // kr00_8
  int v24; // r8
  char v25; // r3
  int *v26; // r3
  int *v27; // r2
  int v28; // r1
  int v29; // t1
  unsigned int v30; // r1
  int v31; // r2
  void *v32; // r1
  int v33; // r2
  unsigned int v34; // r2
  int v35; // r0
  int v36; // r2
  unsigned int v37; // r2
  int v38; // [sp+0h] [bp-Ch]
  int *v39; // [sp+4h] [bp-8h]

  v2 = (unsigned __int8 *)off_11C8C4;
  v3 = *(_DWORD *)(a1 + 68);
  v4 = *(_DWORD **)(a1 + 76);
  v5 = *((unsigned __int8 *)off_11C8C4 + 190);
  v7 = a2;
  if ( (a2 & 0x800000) != 0 )
  {
    v8 = sub_11EBFC(a1);
    v9 = 9;
    while ( 1 )
    {
      v10 = *(_WORD *)(v3 + 8);
      if ( (v10 & 0x20) != 0 )
        break;
      v8 = sub_11EBFC(v8);
      if ( !--v9 )
      {
        v11 = *(_WORD *)(v3 + 8);
        if ( (v11 & 0x60) != 0x20 )
        {
          if ( (v11 & 0x20) == 0 )
          {
            v15 = dword_11C8E0;
            v16 = 84 * v5;
            sub_12D2D0(84 * v5 + 28 + dword_11C8E0);
            sub_11A2D0(v3);
            *(_DWORD *)(a1 + 68) = 0;
            goto LABEL_18;
          }
LABEL_7:
          sub_11A2D0(v3);
          *(_DWORD *)(a1 + 68) = 0;
          v14 = v2[199];
          v15 = dword_11C8E0;
          v16 = 84 * v5;
          if ( v2[199] )
            goto LABEL_19;
LABEL_8:
          sub_11B490(v2[190], (int)v12, v13, v14);
          sub_12D2D0(v16 + 12 + v15);
          if ( *(_WORD *)(a1 + 4) )
            return sub_117F18(a1, v7, v5);
          return sub_118CE0();
        }
        v7 &= ~0x800000u;
        v4[18] &= ~0x800000u;
        if ( (v11 & 0x20) == 0 )
          goto LABEL_22;
LABEL_31:
        sub_11A2D0(v3);
        v15 = dword_11C8E0;
        *(_DWORD *)(a1 + 68) = 0;
        goto LABEL_12;
      }
    }
    if ( (v10 & 0x60) != 0x20 )
      goto LABEL_7;
    v7 &= ~0x800000u;
    v4[18] &= ~0x800000u;
    goto LABEL_31;
  }
  if ( (*(_WORD *)(v3 + 8) & 0x20) != 0 )
  {
    v15 = dword_11C8E0;
    sub_11A2D0(*(_DWORD *)(a1 + 68));
    *(_DWORD *)(a1 + 68) = 0;
  }
  else
  {
LABEL_22:
    v15 = dword_11C8E0;
    sub_12D2D0(84 * (__int16)v5 + 28 + dword_11C8E0);
    sub_11A2D0(v3);
    *(_DWORD *)(a1 + 68) = 0;
  }
LABEL_12:
  v18 = BYTE1(v7);
  if ( v2[199] )
  {
    v12 = off_11C8C8;
    v13 = HIBYTE(*(_DWORD *)off_11C8C8) & 7;
    v19 = v13 + 1;
    if ( v13 + 1 >= (unsigned int)v2[165] )
      v19 = v2[165];
    *(_DWORD *)off_11C8C8 = (v19 << 24) & 0x7000000 | *(_DWORD *)off_11C8C8 & 0xF8FFFFFF;
  }
  if ( BYTE1(v7) <= 4u )
  {
    v20 = *(_DWORD *)(a1 + 72);
    if ( v18 )
    {
      v21 = v20 + 44;
    }
    else
    {
      if ( *(_WORD *)(a1 + 4) )
      {
        v26 = *(int **)(a1 + 44);
        v21 = v20 + 44;
        v27 = v26;
        v28 = v20 + 40;
        do
        {
          v29 = *v27++;
          *(_DWORD *)(v28 + 4) = v29;
          v28 += 4;
        }
        while ( v26 + 16 != v27 );
        if ( (*(_WORD *)(a1 + 30) & 0x2000) != 0 )
        {
          v38 = *(_DWORD *)(dword_11C8D0 + 696 * *(unsigned __int8 *)(a1 + 29) + 340);
          if ( **(__int16 **)off_11C8CC < 0 && !*(_DWORD *)(dword_11C8D0 + 696 * *(unsigned __int8 *)(a1 + 29) + 340) )
          {
            v39 = v26;
            sub_12F46C(dword_11C8DC, dword_11C8D8, 475);
            v26 = v39;
          }
          v30 = *(_DWORD *)(v38 + 156);
          *(_DWORD *)(v20 + 68) = v26[5];
          v31 = *(_DWORD *)(v38 + 160);
          *(_DWORD *)(v20 + 84) = v26[9];
          *(_DWORD *)(v20 + 64) = v30;
          *(_DWORD *)(v20 + 80) = v31;
          if ( ((v30 >> 11) & 5) == 5 )
          {
            v34 = v31 & 0xFFFCFFFF;
            if ( (v30 & 0x600) == 0x400 )
              v35 = 0x20000;
            else
              v35 = 0x10000;
            v36 = v34 | v35;
            if ( *(_BYTE *)(v38 + 165) )
              v37 = v36 | 0x40000;
            else
              v37 = v36 & 0xFFFBFFFF;
            *(_DWORD *)(v20 + 80) = v37;
          }
          if ( (v26[15] & 4) == 0 )
            *(_DWORD *)(v20 + 48) &= 0xFFFFFE7F;
        }
      }
      else
      {
        v21 = v20 + 44;
      }
      sub_11C588((unsigned int *)a1);
    }
    v22 = *(_DWORD *)&v2[28 * v5 + 36];
    v23 = *(_QWORD *)(v20 + 96);
    v4[16] = v23;
    v4[18] = (v18 + 1) << 8;
    v4[11] = HIDWORD(v23);
    v4[12] = v21;
    result = (int)(v4 + 3);
    if ( v22 )
    {
      v4[4] = v22;
    }
    else
    {
      v32 = off_11C8D4;
      *(_DWORD *)(v15 + 84 * v5) = result;
      v33 = 84 * v5 + v15;
      if ( !*(_BYTE *)(*(_DWORD *)v32 + 1) )
      {
        *(_DWORD *)(v33 + 4) = 0;
        *(_DWORD *)(v33 + 8) = 0;
      }
    }
    v24 = v15 + 84 * v5;
    v25 = *(_BYTE *)(v24 + 80) + 1;
    *(_DWORD *)&v2[28 * v5 + 36] = result;
    *(_BYTE *)(v24 + 80) = v25;
  }
  else
  {
    v4[18] |= 0x10000u;
    v16 = 84 * v5;
LABEL_18:
    v14 = v2[199];
    if ( !v2[199] )
      goto LABEL_8;
LABEL_19:
    *(_DWORD *)off_11C8C8 = (v2[164] << 24) & 0x7000000 | *(_DWORD *)off_11C8C8 & 0xF8FFFFFF;
    sub_12D2D0(v16 + 12 + v15);
    if ( !*(_WORD *)(a1 + 4) )
      return sub_118CE0();
    return sub_117F18(a1, v7, v5);
  }
  return result;
}

