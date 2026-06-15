// sub_10BF28 @ 0x10bf28, size 546 bytes
_DWORD *__fastcall sub_10BF28(_DWORD *result, unsigned int a2, int a3, int a4)
{
  int v4; // r6
  int v7; // r7
  int v8; // r3
  int v9; // r10
  int v10; // r0
  unsigned int v11; // r3
  unsigned int v12; // r3
  int v13; // r1
  void *v14; // r2
  int v15; // r3
  unsigned int v16; // r0
  int v17; // r0
  __int64 v18; // r8
  double v19; // d8
  __int64 v20; // r0
  __int64 v21; // r0
  __int64 v22; // r0
  __int64 v23; // r0
  int v24; // r8
  __int64 v25; // r0
  int v26; // r2
  int v27; // r0
  int v28; // r8
  int v29; // r0
  int v30; // r1
  int v31; // r2
  int v32; // r3
  unsigned __int16 *v33; // r6
  int v34; // r1
  int v35; // r2
  int v36; // r5
  __int64 v37; // r0
  int v38; // r2
  int v39; // r3
  __int64 v40; // r0
  int v41; // r2
  int v42; // r3
  int v43; // r2
  int v44; // r3
  int v45; // r0
  int v46; // r1
  int v47; // r2
  int v48; // r3
  int v49; // [sp+0h] [bp-64h]
  int v50; // [sp+0h] [bp-64h]
  int v51; // [sp+0h] [bp-64h]
  int v52; // [sp+Ch] [bp-58h]
  int v53[3]; // [sp+24h] [bp-40h] BYREF
  __int64 v54; // [sp+30h] [bp-34h] BYREF
  int v55; // [sp+38h] [bp-2Ch]
  int v56; // [sp+3Ch] [bp-28h]
  __int64 v57; // [sp+40h] [bp-24h]
  int v58; // [sp+48h] [bp-1Ch]
  int v59; // [sp+4Ch] [bp-18h]
  int v60; // [sp+50h] [bp-14h]
  int v61; // [sp+54h] [bp-10h]
  int v62; // [sp+58h] [bp-Ch]
  int v63; // [sp+5Ch] [bp-8h]

  v4 = *result;
  v7 = (unsigned __int8)*result >> 6;
  if ( !a3 )
  {
    if ( !a4 )
      return result;
    goto LABEL_3;
  }
  v9 = result[1];
  v10 = sub_11F74C(0x2000, dword_10C178, *result, v9);
  v11 = a2 - 2;
  do
  {
    *(_WORD *)(v11 + 2) = -32640;
    v11 += 2;
  }
  while ( a2 + 30 != v11 );
  *(_DWORD *)(a2 + 32) = 0;
  *(_DWORD *)(a2 + 36) = 0;
  v12 = a2 + 36;
  v13 = a2 + 100;
  do
  {
    *(_DWORD *)(v12 + 4) = 0;
    v12 += 4;
  }
  while ( v13 != v12 );
  v14 = off_10C17C;
  do
    v15 = *(_DWORD *)off_10C17C;
  while ( !*(_DWORD *)off_10C17C );
  if ( v7 )
  {
    v16 = (*(_DWORD *)off_10C180 >> 5) & 0x1F;
    if ( (*(_DWORD *)off_10C180 & 0x400) != 0 )
      v16 *= 2;
    if ( (*(_DWORD *)off_10C184 & 0x80000) != 0 && (*(_DWORD *)off_10C184 & 0x40000) != 0 )
      v16 >>= 1;
    v17 = *(unsigned __int8 *)off_10C18C * v16;
    *(_DWORD *)off_10C188 &= ~1u;
    if ( (unsigned __int8)v4 >> 7 )
    {
      v18 = *(_QWORD *)&dword_10C168;
      v19 = dbl_10C160;
    }
    else
    {
      v18 = *(_QWORD *)&dword_10C158;
      v19 = dbl_10C150;
    }
    v20 = sub_12754C(v17);
    v21 = sub_127620(v20, HIDWORD(v20), 0, dword_10C190);
    v22 = sub_127874(v18, HIDWORD(v18), v21, HIDWORD(v21));
    v23 = sub_127620(v22, HIDWORD(v22), 0, dword_10C194);
    v24 = sub_127194(v23, HIDWORD(v23));
    v25 = sub_127874(LODWORD(v19), HIDWORD(v19), 0, dword_10C190);
    v26 = sub_127194(v25, HIDWORD(v25));
    v27 = v24;
    v28 = v26;
    *(_DWORD *)off_10C1B0 = sub_127BA4(v27) & 0x7FFFFFFF;
    v10 = sub_127BA4(v28);
    v14 = off_10C198;
    v13 = *(_DWORD *)off_10C198 & dword_10C1A0;
    v15 = dword_10C19C & (v10 << 13) | v13;
    *(_DWORD *)off_10C198 = v15;
  }
  sub_103540(v10, v13, (int)v14, v15, v49);
  v29 = sub_10A5B0((unsigned __int8)v4, a2, v9, (unsigned __int16)v4 >> 12, BYTE1(v4) & 0xF, 0);
  result = (_DWORD *)sub_1035E8(v29, v30, v31, v32, v50);
  *(_DWORD *)off_10C17C = 1;
  if ( a4 )
  {
LABEL_3:
    v8 = *(_DWORD *)off_10C170;
    if ( (*(_DWORD *)off_10C170 & 0x8000000) == 0
      || (v8 = *(_DWORD *)off_10C174 << 21, (*(_DWORD *)off_10C174 & 0x400) != 0) )
    {
      if ( !v7 )
      {
        v33 = (unsigned __int16 *)off_10C1A8;
        v34 = *(_DWORD *)(dword_10C1A4 + 4);
        v35 = *(_DWORD *)(dword_10C1A4 + 8);
        v36 = dword_10C1A4 + 72;
        v53[0] = *(_DWORD *)dword_10C1A4;
        v53[1] = v34;
        v53[2] = v35;
        sub_103540(v53[0], v34, v35, v8, v49);
        v37 = *(_QWORD *)v36;
        v38 = *(_DWORD *)(v36 + 8);
        v39 = *(_DWORD *)(v36 + 12);
        v36 += 16;
        v54 = v37;
        v55 = v38;
        v56 = v39;
        v40 = *(_QWORD *)v36;
        v41 = *(_DWORD *)(v36 + 8);
        v42 = *(_DWORD *)(v36 + 12);
        v36 += 16;
        v57 = v40;
        v58 = v41;
        v59 = v42;
        HIDWORD(v40) = *(_DWORD *)(v36 + 4);
        v43 = *(_DWORD *)(v36 + 8);
        v44 = *(_DWORD *)(v36 + 12);
        v60 = *(_DWORD *)v36;
        v61 = HIDWORD(v40);
        v62 = v43;
        v63 = v44;
        *((_BYTE *)v33 + 4) = 0;
        LODWORD(v40) = dword_10C1AC;
        *((_BYTE *)v33 + 12) = 0;
        *((_BYTE *)v33 + 20) = 0;
        *((_BYTE *)v33 + 28) = 0;
        *((_BYTE *)v33 + 36) = 0;
        *((_BYTE *)v33 + 44) = 0;
        *((_BYTE *)v33 + 52) = 0;
        sub_10AC18((unsigned int *)v40, (_BYTE *)(a2 + 125), (int)v33);
        v45 = sub_10B048(v53, dword_10C1AC, a2 + 104, a2 + 125, v33, 6, 1, v52, 0, 0, &v54);
        *((_BYTE *)v33 + 4) = 0;
        *((_BYTE *)v33 + 12) = 0;
        *((_BYTE *)v33 + 20) = 0;
        *((_BYTE *)v33 + 28) = 0;
        *((_BYTE *)v33 + 36) = 0;
        *((_BYTE *)v33 + 44) = 0;
        *((_BYTE *)v33 + 52) = 0;
        return (_DWORD *)sub_1035E8(v45, v46, v47, v48, v51);
      }
    }
  }
  return result;
}

