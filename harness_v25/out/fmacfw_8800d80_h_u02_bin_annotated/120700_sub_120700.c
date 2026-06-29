// fwstruct annotate: 120700_sub_120700.c
// sub_120700 @ 0x120700, size 898 bytes
int __fastcall sub_120700(int a1, int a2, int a3, int a4, int a5, int a6)
{
  unsigned int v8; // r9
  int v9; // r3
  unsigned int v10; // r7
  unsigned int v11; // r11
  int v12; // r10
  int v13; // r5
  char *v14; // r2
  int v15; // r8
  int *v16; // r0
  _DWORD *v17; // r2
  __int16 **v18; // r3
  int v19; // r5
  char *v20; // r1
  int *v21; // r0
  _DWORD *v22; // r1
  int v23; // r6
  int v24; // r5
  int v25; // r2
  unsigned __int64 v26; // kr08_8
  __int64 v27; // r0
  int v28; // r3
  unsigned __int64 v29; // r0
  unsigned int v30; // r2
  int v31; // r1
  _DWORD *v32; // r6
  int v33; // r5
  int v34; // r2
  int v35; // r3
  int result; // r0
  _BYTE *v37; // r3
  _DWORD *v38; // r2
  unsigned __int8 *v39; // r5
  int v40; // r1
  _BYTE *v41; // r1
  _DWORD *v42; // r2
  unsigned int v43; // [sp+8h] [bp-1Ch]
  int v44; // [sp+10h] [bp-14h]
  unsigned int v45; // [sp+14h] [bp-10h]
  int v47; // [sp+1Ch] [bp-8h]

  v8 = *(_DWORD *)(a3 + 32);
  v9 = *(unsigned __int16 *)(a1 + 32);
  v45 = *(_DWORD *)(a3 + 36);
  v10 = *(_DWORD *)(a1 + 24);
  v11 = *(_DWORD *)(a1 + 28);
  v12 = v9 << 10;
  if ( !*(_BYTE *)(a4 + 106) && (v13 = *(unsigned __int16 *)(a4 + 112), *(_WORD *)(a4 + 112)) )
  {
    sub_12ADC8(*(unsigned __int8 *)(a4 + 107), v9, (unsigned __int8)v13);
    v47 = v12 * v13;
  }
  else if ( a6 )
  {
    v13 = *(unsigned __int8 *)(a6 + 2);
    if ( !*(_BYTE *)(a6 + 2) )
    {
      v13 = *(unsigned __int8 *)(a6 + 3);
      sub_12ADC8(*(unsigned __int8 *)(a4 + 107), v9, v13);
    }
    v47 = v12 * v13;
  }
  else
  {
    v47 = v9 << 10;
    v13 = 1;
  }
  v44 = v13 * *(unsigned __int16 *)(a5 + 30);
  if ( *(unsigned __int8 *)(a3 + 40) << 28 )
  {
    v23 = 500;
    v24 = 0;
  }
  else
  {
    v14 = (char *)off_120A14;
    v15 = dword_120A64;
    v16 = (int *)off_120A18;
    *(_DWORD *)off_120A14 = *(_BYTE *)(dword_120A64 + (*(unsigned __int8 *)(a3 + 44) >> 4)) & 0x7F
                          | *(_DWORD *)off_120A14 & 0xFFFFFF80;
    v17 = v14 + 8;
    *v16 = a2 | (*(unsigned __int8 *)(a3 + 40) >> 7 << 20);
    *v17 = 0x80000000;
    __dsb(0xFu);
    while ( (*v17 & 0xC0000000) != 0x40000000 )
      ;
    v18 = (__int16 **)off_120A1C;
    if ( **(__int16 **)off_120A1C >= 0 || (*v17 & 0x40000000) != 0 )
    {
      v19 = (unsigned __int16)*(_DWORD *)off_120A20;
    }
    else
    {
      sub_12F2C8(dword_120A3C, dword_120A38, 430, off_120A1C);
      v19 = 500;
      v18 = (__int16 **)off_120A1C;
    }
    if ( !(*(unsigned __int8 *)(a3 + 40) << 28) )
    {
      v20 = (char *)off_120A14;
      v21 = (int *)off_120A18;
      *(_DWORD *)off_120A14 = *(_BYTE *)(v15 + (*(unsigned __int8 *)(a3 + 44) >> 4)) & 0x7F
                            | *(_DWORD *)off_120A14 & 0xFFFFFF80;
      v22 = v20 + 8;
      *v21 = (*(unsigned __int8 *)(a3 + 40) >> 7 << 20) | 0x18;
      *v22 = 0x80000000;
      __dsb(0xFu);
      while ( (*v22 & 0xC0000000) != 0x40000000 )
        ;
      if ( **v18 >= 0 || (*v22 & 0x40000000) != 0 )
      {
        v23 = (unsigned __int16)*(_DWORD *)off_120A20;
        v24 = v19 - v23;
        goto LABEL_15;
      }
      sub_12F2C8(dword_120A3C, dword_120A38, 430, 2 * *v22);
    }
    v24 = v19 - 500;
    v23 = 500;
  }
LABEL_15:
  v25 = *(unsigned __int8 *)(a4 + 106);
  v26 = __PAIR64__(v11, v10) - __PAIR64__(v45, v8) + (unsigned int)v24;
  *(_QWORD *)(a4 + 40) = v26;
  if ( !v25 )
  {
    *(_DWORD *)(a4 + 132) = v26;
    *(_DWORD *)(a4 + 136) = v44 + 400;
  }
  v27 = sub_1432D4(v10, v11, v12, v12 >> 31);
  v43 = v10 - v23;
  v28 = v27 * (v12 >> 31) + v12 * HIDWORD(v27);
  v29 = (unsigned int)v27 * (unsigned __int64)(unsigned int)v12;
  HIDWORD(v29) += v28;
  if ( v29 < __PAIR64__(v11, v10) - (unsigned int)v23 )
    v43 = v29;
  v30 = v43 + v47;
  if ( (*(_DWORD *)off_120A24 & 0x2000000) != 0 )
    v31 = dword_120A34 - v44 - v26 + v30;
  else
    v31 = v30 - v44 - 400;
  v32 = off_120A28;
  v33 = *((_DWORD *)off_120A28 + 4) - *(_DWORD *)off_120A2C + v31;
  if ( v33 - v32[4] - 4300 - sub_101944() < 0 )
    v33 += v12;
  if ( (*(_DWORD *)(a4 + 4) & 1) != 0 )
  {
    v35 = *(unsigned __int8 *)(a4 + 85);
    if ( (v35 & 2) != 0 && v33 - *((_DWORD *)off_120A28 + 4) - 10000 < 0 )
    {
      v33 += v12;
      sub_12E948(dword_120A60, v35 << 30, v34);
    }
  }
  result = v33 - *((_DWORD *)off_120A28 + 4) - 4300 - sub_101944();
  if ( result >= 0 && *(_DWORD *)(a4 + 36) != v33 )
  {
    v37 = off_120A30;
    if ( *((_DWORD *)off_120A30 + 8) != a4 || (v38 = off_120A24, *(_DWORD *)(a4 + 36) = v33, (*v38 & 0x2000000) != 0) )
    {
      sub_124BFC(a4 + 24, v33);
    }
    else
    {
      v39 = (unsigned __int8 *)off_120A44;
      v40 = (unsigned __int8)v37[36];
      *(_BYTE *)off_120A44 = BYTE2(*(_DWORD *)off_120A40);
      if ( !v40 )
      {
        v41 = *(_BYTE **)off_120A4C;
        v39[1] = *(_DWORD *)off_120A48;
        v37[36] = 1;
        if ( *v41 == 1 )
        {
          v42 = off_120A54;
          *(_DWORD *)off_120A50 = 1;
          *v42 |= 1u;
        }
        if ( *v39 >= (unsigned int)v39[1] )
          sub_12E948(dword_120A8C, *v39, v39[1]);
        if ( **(__int16 **)off_120A1C < 0 && *v39 >= (unsigned int)v39[1] )
          sub_12F32C(dword_120A5C, dword_120A58, 523);
      }
    }
    return sub_127FDC(a4);
  }
  return result;
}

