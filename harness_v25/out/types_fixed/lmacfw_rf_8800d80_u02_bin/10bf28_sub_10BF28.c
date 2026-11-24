// sub_10BF28 @ 0x10bf28, size 546 bytes
int *__fastcall sub_10BF28(int *result, unsigned int a2, int a3, int a4)
{
  int v4; // r6
  int v7; // r7
  int v8; // r3
  int v9; // r10
  int v10; // r0
  int v11; // r3
  int v12; // r3
  int v13; // r1
  void *v14; // r2
  int v15; // r3
  unsigned int v16; // r0
  int v17; // r0
  __int64 v18; // r8
  double v19; // d8
  __int64 v20; // r0
  unsigned int v21; // r0
  unsigned int v22; // r1
  __int64 v23; // r0
  __int64 v24; // r0
  __int64 v25; // r8
  __int64 v26; // r0
  __int64 v27; // r2
  __int64 v28; // r0
  __int64 v29; // r8
  int v30; // r0
  int v31; // r1
  int v32; // r2
  int v33; // r3
  unsigned __int16 *v34; // r6
  int v35; // r1
  int v36; // r2
  int v37; // r5
  __int64 v38; // r0
  int v39; // r2
  int v40; // r3
  __int64 v41; // r0
  int v42; // r2
  int v43; // r3
  int v44; // r2
  int v45; // r3
  int v46; // r0
  int v47; // r1
  int v48; // r2
  int v49; // r3
  int v50; // [sp+0h] [bp-64h]
  int v51; // [sp+0h] [bp-64h]
  int v52; // [sp+0h] [bp-64h]
  int v53; // [sp+Ch] [bp-58h]
  int *(_DWORD *)(v54 + 0xc); // [sp+24h] [bp-40h] BYREF
  __int64 v55; // [sp+30h] [bp-34h] BYREF
  int v56; // [sp+38h] [bp-2Ch]
  int v57; // [sp+3Ch] [bp-28h]
  __int64 v58; // [sp+40h] [bp-24h]
  int v59; // [sp+48h] [bp-1Ch]
  int v60; // [sp+4Ch] [bp-18h]
  int v61; // [sp+50h] [bp-14h]
  int v62; // [sp+54h] [bp-10h]
  int v63; // [sp+58h] [bp-Ch]
  int v64; // [sp+5Ch] [bp-8h]

  v4 = *result;
  v7 = (unsigned __int8)*result >> 6;
  if ( !a3 )
  {
    if ( !a4 )
      return result;
    goto LABEL_3;
  }
  v9 = *(_DWORD *)(result + 0x4);
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
    LODWORD(v20) = sub_12754C(v17);
    v21 = sub_127620(v20, 0, dword_10C190);
    LODWORD(v23) = sub_127874(v18, HIDWORD(v18), v21, v22);
    LODWORD(v24) = sub_127620(v23, 0, dword_10C194);
    v25 = math_round(v24);
    LODWORD(v26) = sub_127874(LODWORD(v19), HIDWORD(v19), 0, dword_10C190);
    v27 = math_round(v26);
    v28 = v25;
    v29 = v27;
    *(_DWORD *)off_10C1B0 = sub_127BA4(v28, SHIDWORD(v28)) & 0x7FFFFFFF;
    v10 = sub_127BA4(v29, SHIDWORD(v29));
    v14 = off_10C198;
    v13 = *(_DWORD *)off_10C198 & dword_10C1A0;
    v15 = dword_10C19C & (v10 << 13) | v13;
    *(_DWORD *)off_10C198 = v15;
  }
  crypto_hw_power_up(v10, v13, (int)v14, v15, v50);
  v30 = sub_10A5B0((unsigned __int8)v4, a2, v9, (unsigned __int16)v4 >> 12, BYTE1(v4) & 0xF, 0);
  result = (int *)sub_1035E8(v30, v31, v32, v33, v51);
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
        v34 = (unsigned __int16 *)off_10C1A8;
        v35 = *(_DWORD *)(dword_10C1A4 + 4);
        v36 = *(_DWORD *)(dword_10C1A4 + 8);
        v37 = dword_10C1A4 + 72;
        *(_DWORD *)(v54 + 0x0) = *(_DWORD *)dword_10C1A4;
        *(_DWORD *)(v54 + 0x4) = v35;
        *(_DWORD *)(v54 + 0x8) = v36;
        crypto_hw_power_up(*(_DWORD *)(v54 + 0x0), v35, v36, v8, v50);
        v38 = *(_QWORD *)v37;
        v39 = *(_DWORD *)(v37 + 8);
        v40 = *(_DWORD *)(v37 + 12);
        v37 += 16;
        v55 = v38;
        v56 = v39;
        v57 = v40;
        v41 = *(_QWORD *)v37;
        v42 = *(_DWORD *)(v37 + 8);
        v43 = *(_DWORD *)(v37 + 12);
        v37 += 16;
        v58 = v41;
        v59 = v42;
        v60 = v43;
        HIDWORD(v41) = *(_DWORD *)(v37 + 4);
        v44 = *(_DWORD *)(v37 + 8);
        v45 = *(_DWORD *)(v37 + 12);
        v61 = *(_DWORD *)v37;
        v62 = HIDWORD(v41);
        v63 = v44;
        v64 = v45;
        *((_BYTE *)v34 + 4) = 0;
        LODWORD(v41) = dword_10C1AC;
        *((_BYTE *)v34 + 12) = 0;
        *((_BYTE *)v34 + 20) = 0;
        *((_BYTE *)v34 + 28) = 0;
        *((_BYTE *)v34 + 36) = 0;
        *((_BYTE *)v34 + 44) = 0;
        *((_BYTE *)v34 + 52) = 0;
        rf_rx_dc_calib((unsigned int *)v41, (_BYTE *)(a2 + 125), (int)v34);
        v46 = sub_10B048(v54, dword_10C1AC, a2 + 104, a2 + 125, v34, 6, 1, v53, 0, 0, &v55);
        *((_BYTE *)v34 + 4) = 0;
        *((_BYTE *)v34 + 12) = 0;
        *((_BYTE *)v34 + 20) = 0;
        *((_BYTE *)v34 + 28) = 0;
        *((_BYTE *)v34 + 36) = 0;
        *((_BYTE *)v34 + 44) = 0;
        *((_BYTE *)v34 + 52) = 0;
        return (int *)sub_1035E8(v46, v47, v48, v49, v52);
      }
    }
  }
  return result;
}
