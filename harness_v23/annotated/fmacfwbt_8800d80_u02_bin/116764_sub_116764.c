// v23 annotated: sub_116764 @ 0x116764
// Original: 116764_sub_116764.c
// Primary struct: <unclustered>
//
// sub_116764 @ 0x116764, size 846 bytes
int __fastcall sub_116764(int a1, int a2)
{
  int v2; // r3
  _DWORD *v3; // r5
  int v4; // r6
  int v5; // r7
  _DWORD *v7; // r8
  int v8; // r3
  int result; // r0
  __int16 **v10; // r7
  int v11; // r5
  _WORD *v12; // r3
  int v13; // r3
  int v14; // r2
  __int16 v15; // r12
  __int16 **v16; // r9
  int v17; // r3
  int v18; // r3
  char v19; // r2
  int v20; // r2
  __int16 v21; // r2
  int v22; // r3
  int v23; // r3
  int v24; // r3
  int v25; // r7
  unsigned int v26; // r2
  int v27; // r3
  int v28; // r2
  int v29; // r3
  int v30; // r2
  __int16 **v31; // r9
  int v32; // r7
  __int16 *v33; // r3
  int v34; // r3
  __int16 v35; // r12
  unsigned int v36; // r2
  int v37; // r2
  unsigned int v38; // r3
  _WORD *v40; // r0
  char v41; // r3
  __int64 v42; // kr00_8

  v2 = *(_DWORD *)(a1 + 36);
  v3 = *(_DWORD **)(a1 + 72);
  v4 = *(_DWORD *)(a1 + 76);
  v5 = v2 & 0x200000;
  v7 = v3 + 11;
  if ( (v2 & 0x200000) == 0 )
  {
    v15 = *(_WORD *)(a1 + 30);
    if ( (v15 & 8) != 0 )
    {
      v16 = (__int16 **)off_116A54;
      if ( **(__int16 **)off_116A54 >= 0 )
      {
        v17 = *(_DWORD *)(v4 + 28);
        if ( v17 )
        {
LABEL_15:
          *(_DWORD *)(v4 + 68) &= 0xFF87FFFF;
          v19 = *(_BYTE *)(v17 + 4);
          *(_DWORD *)(v4 + 48) = v7;
          if ( (v19 & 1) == 0 )
            v5 = 512;
          v20 = v15 & 1;
          *(_DWORD *)(v4 + 64) = v5;
          if ( (v15 & 1) == 0 )
            *(_DWORD *)(v4 + 72) = 0;
LABEL_19:
          if ( v20 )
          {
            a2 = *(_DWORD *)(v4 + 64) | 1;
            v21 = *(_WORD *)v17 | 0x800;
            *(_DWORD *)(v4 + 64) = a2;
            *(_WORD *)v17 = v21;
          }
          if ( (*((_BYTE *)off_116A58 + 361) & 1) != 0 )
          {
            v22 = *(unsigned __int8 *)(v17 + 4);
            a2 = v22 << 31;
            if ( (v22 & 1) == 0 )
            {
              v23 = *(_DWORD *)(a1 + 44);
              if ( v23 != dword_116A5C && v23 != dword_116A60 )
              {
                sub_11AC78(v3 + 16, v3 + 20);
                sub_11AC78(v3 + 17, v3 + 21);
                sub_11AC78(v3 + 18, v3 + 22);
                sub_11AC78(v3 + 19, v3 + 23);
              }
            }
          }
          v24 = v3[12];
          *(_DWORD *)(v4 + 44) = v3[25];
          v3[12] = v24 | 2;
          return sub_11C9C8(a1, a2);
        }
        v18 = *(_DWORD *)(v4 + 24);
LABEL_14:
        v17 = *(_DWORD *)(v18 + 8);
        goto LABEL_15;
      }
      if ( v3 )
      {
        v17 = *(_DWORD *)(v4 + 28);
        if ( v17 )
          goto LABEL_15;
      }
      else
      {
        sub_12F694(dword_116A74, dword_116A64, 518);
        v17 = *(_DWORD *)(v4 + 28);
        if ( v17 )
        {
          v15 = *(_WORD *)(a1 + 30);
          goto LABEL_15;
        }
        if ( **v16 >= 0 )
          goto LABEL_66;
      }
      v18 = *(_DWORD *)(v4 + 24);
      if ( v18 )
      {
LABEL_35:
        v15 = *(_WORD *)(a1 + 30);
        goto LABEL_14;
      }
      sub_12F694(dword_116A68, dword_116A64, 525);
LABEL_66:
      v18 = *(_DWORD *)(v4 + 24);
      goto LABEL_35;
    }
    sub_13AFD8();
    v30 = v3[24];
    *(_DWORD *)(v4 + 64) = v30;
    if ( !*(_BYTE *)(dword_116A6C + 1320 * *(unsigned __int8 *)(a1 + 28) + 106)
      && (*(_DWORD *)(dword_116A70 + 696 * *(unsigned __int8 *)(a1 + 29) + 4) & 0x20) != 0 )
    {
      v38 = *(_DWORD *)(*(_DWORD *)(a1 + 44) + 60);
      if ( !((*(_WORD *)(a1 + 30) & 0x2000) != 0 ? (v38 >> 4) & 1 : (v38 >> 3) & 1) )
      {
        v40 = *(_WORD **)(v4 + 28);
        if ( (*v40 & 0x8000) != 0 )
        {
          *v40 &= ~0x8000u;
          v41 = *(_BYTE *)(a1 + 50) - 4;
          *(_BYTE *)(a1 + 51) -= 4;
          *(_BYTE *)(a1 + 50) = v41;
          v42 = *(_QWORD *)(v4 + 32);
          *(_DWORD *)(v4 + 32) = v42 - 4;
          *(_DWORD *)(v4 + 36) = HIDWORD(v42) - 4;
        }
      }
    }
    v31 = (__int16 **)off_116A54;
    v32 = *(_DWORD *)(a1 + 76);
    v33 = *(__int16 **)off_116A54;
    *(_DWORD *)(v4 + 48) = v7;
    if ( *v33 >= 0 )
    {
      v17 = *(_DWORD *)(v32 + 28);
      if ( v17 )
      {
LABEL_46:
        v35 = *(_WORD *)(a1 + 30);
        v36 = v30 & 0xFFFFF9FF;
        *(_DWORD *)(v4 + 64) = v36;
        a2 = *(unsigned __int8 *)(v17 + 4);
        if ( (a2 & 1) == 0 )
          *(_DWORD *)(v4 + 64) = v36 | 0x200;
        v20 = v35 & 1;
        goto LABEL_19;
      }
      v34 = *(_DWORD *)(v32 + 24);
LABEL_45:
      v17 = *(_DWORD *)(v34 + 8);
      goto LABEL_46;
    }
    if ( *(_DWORD *)(a1 + 72) )
    {
      v17 = *(_DWORD *)(v32 + 28);
      if ( v17 )
        goto LABEL_46;
    }
    else
    {
      sub_12F694(dword_116ABC, dword_116AB4, 518);
      v17 = *(_DWORD *)(v32 + 28);
      if ( v17 )
      {
        v30 = *(_DWORD *)(v4 + 64);
        goto LABEL_46;
      }
      if ( **v31 >= 0 )
        goto LABEL_74;
    }
    v34 = *(_DWORD *)(v32 + 24);
    if ( v34 )
    {
LABEL_57:
      v30 = *(_DWORD *)(v4 + 64);
      goto LABEL_45;
    }
    sub_12F694(dword_116AB8, dword_116AB4, 525);
LABEL_74:
    v34 = *(_DWORD *)(v32 + 24);
    goto LABEL_57;
  }
  if ( (v2 & 0x380000) != 0x280000 )
  {
    v8 = *(unsigned __int16 *)(a1 + 30);
    result = v8 << 31;
    if ( (v8 & 1) == 0 )
      return result;
LABEL_4:
    v10 = (__int16 **)off_116A54;
    v11 = *(_DWORD *)(a1 + 76);
    if ( **(__int16 **)off_116A54 >= 0 )
    {
      v12 = *(_WORD **)(v11 + 28);
      if ( v12 )
      {
LABEL_8:
        v14 = *(_DWORD *)(v4 + 64) | 1;
        *v12 |= 0x800u;
        *(_DWORD *)(v4 + 64) = v14;
        return result;
      }
      goto LABEL_6;
    }
    if ( *(_DWORD *)(a1 + 72) )
    {
      v12 = *(_WORD **)(v11 + 28);
      if ( v12 )
        goto LABEL_8;
    }
    else
    {
      result = sub_12F694(dword_116A74, dword_116A64, 518);
      v12 = *(_WORD **)(v11 + 28);
      if ( v12 )
        goto LABEL_8;
      if ( **v10 >= 0 )
        goto LABEL_6;
    }
    v13 = *(_DWORD *)(v11 + 24);
    if ( v13 )
      goto LABEL_7;
    result = sub_12F694(dword_116A68, dword_116A64, 525);
LABEL_6:
    v13 = *(_DWORD *)(v11 + 24);
LABEL_7:
    v12 = *(_WORD **)(v13 + 8);
    goto LABEL_8;
  }
  v25 = *(_DWORD *)(a1 + 68);
  v26 = *(_DWORD *)(v25 + 4);
  *(_DWORD *)(v25 + 52) = v7;
  if ( ((v26 >> 11) & 5) == 5 )
  {
    if ( (v26 & 0x600) == 0x400 )
      v37 = 0x20000;
    else
      v37 = 0x10000;
    if ( (*(_BYTE *)(v25 + 344) & 0x20) != 0 )
      v3[20] = v3[20] & 0xFFFCFFFF | v37 | 0x40000;
    else
      v3[20] = v3[20] & 0xFFF8FFFF | v37 & 0xFFFBFFFF;
  }
  if ( *((_BYTE *)off_116A58 + 361) != 2 )
    sub_11AC78(v25 + 4, v3 + 20);
  v27 = v3[12];
  v28 = v3[24];
  v3[16] = *(_DWORD *)(v25 + 4);
  *(_DWORD *)(v25 + 48) = v3[25];
  *(_DWORD *)(v25 + 68) = v28 | 0x600;
  v3[12] = v27 | 2;
  sub_14380C(v25 + 272, v3 + 11, 52);
  v29 = *(unsigned __int16 *)(a1 + 30);
  result = v29 << 31;
  if ( (v29 & 1) != 0 )
    goto LABEL_4;
  return result;
}

