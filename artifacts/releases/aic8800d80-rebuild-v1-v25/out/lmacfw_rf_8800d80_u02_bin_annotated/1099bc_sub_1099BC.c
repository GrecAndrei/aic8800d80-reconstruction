// fwstruct annotate: 1099bc_sub_1099BC.c
// sub_1099BC @ 0x1099bc, size 546 bytes
int __fastcall sub_1099BC(int a1, int a2, int a3, int a4)
{
  int v8; // r1
  int v9; // r2
  int v10; // r3
  int v11; // r1
  int v12; // r2
  int v13; // r3
  float v14; // r1
  float v15; // r0
  float v16; // r12
  float v17; // r4
  float v18; // r11
  int v19; // r8
  float v20; // r6
  int v21; // r2
  _DWORD *v22; // r6
  float *v23; // r4
  float *v24; // r7
  int v25; // t1
  float v26; // s16
  float v27; // s13
  float v28; // s15
  __int64 v29; // r0
  __int64 v30; // r8
  __int64 v31; // r0
  __int64 v32; // r8
  __int64 v33; // r0
  int v34; // r0
  int v35; // r3
  int v36; // r7
  _DWORD *v37; // r6
  float *v38; // r4
  float v39; // s15
  float *v40; // r12
  _DWORD *v41; // r2
  float *v42; // r3
  int v43; // r0
  int v44; // t1
  float v45; // s14
  float v46; // s17
  float v47; // s18
  float v48; // s19
  float *v49; // r7
  int v50; // r8
  int v51; // r9
  int v52; // t1
  float v53; // s16
  int v54; // r5
  int v55; // r1
  float v56; // s13
  int v58; // [sp+0h] [bp-44h]
  int v59; // [sp+4h] [bp-40h]
  float v60[3]; // [sp+8h] [bp-3Ch] BYREF
  float v61[3]; // [sp+14h] [bp-30h] BYREF
  _DWORD v62[9]; // [sp+20h] [bp-24h] BYREF

  v8 = *(_DWORD *)(dword_109BE0 + 4);
  v9 = *(_DWORD *)(dword_109BE0 + 8);
  v10 = *(_DWORD *)(dword_109BE0 + 12);
  v62[0] = *(_DWORD *)dword_109BE0;
  v62[1] = v8;
  v62[2] = v9;
  v62[3] = v10;
  v11 = *(_DWORD *)(dword_109BE0 + 20);
  v12 = *(_DWORD *)(dword_109BE0 + 24);
  v13 = *(_DWORD *)(dword_109BE0 + 28);
  v62[4] = *(_DWORD *)(dword_109BE0 + 16);
  v62[5] = v11;
  v62[6] = v12;
  v62[7] = v13;
  v14 = *(float *)(a2 + 16);
  v15 = *(float *)(a2 + 136);
  v16 = *(float *)(a2 + 8);
  v17 = *(float *)(a2 + 144);
  v60[1] = *(float *)(a2 + 12);
  v18 = 0.0;
  v19 = a1;
  v60[2] = v14;
  v61[0] = v15;
  v20 = *(float *)(a2 + 140);
  v59 = a1;
  v60[0] = v16;
  *(_DWORD *)(a2 + 636) = 0;
  *(_DWORD *)(a2 + 640) = 0;
  v58 = a3;
  v61[1] = v20;
  v61[2] = v17;
  sub_109738(0, v60, v61, a4);
  if ( v19 > 0 )
  {
    v22 = v62;
    v23 = (float *)a2;
    v24 = (float *)(a2 + 4 * v19);
    while ( ++v23 != v24 )
    {
      while ( 1 )
      {
        v25 = *((unsigned __int8 *)v22 + 1);
        v22 = (_DWORD *)((char *)v22 + 1);
        if ( v25 != 1 )
          break;
        v26 = *(float *)(a4 + 8);
        v27 = v23[32];
        v28 = v26 * *v23++;
        v29 = sub_127570((float)(v28 - v27) + *(float *)(a4 + 12));
        v30 = sub_127620(v29, HIDWORD(v29), v29, HIDWORD(v29));
        v31 = sub_127570((float)(v26 * v26) + 1.0);
        v32 = sub_127874(v30, HIDWORD(v30), v31, HIDWORD(v31));
        v33 = sub_127570(LODWORD(v18));
        v34 = sub_1272B4(v32, HIDWORD(v32), v33, HIDWORD(v33));
        v18 = COERCE_FLOAT(sub_127BE4(v34));
        if ( v23 == v24 )
          goto LABEL_6;
      }
    }
  }
LABEL_6:
  if ( !v58 )
  {
    sub_11F74C(1, dword_109BE4, v21, 0);
    v35 = v59;
    if ( v59 > 0 )
      goto LABEL_8;
LABEL_20:
    v46 = flt_109BE8;
    v47 = flt_109BE8;
    v50 = 4 * v58;
    goto LABEL_18;
  }
  sub_11F74C(1, dword_109BF4, v21, v58);
  v35 = v59;
  if ( v59 <= 0 )
    goto LABEL_20;
LABEL_8:
  v36 = 4 * v35 + 384;
  v37 = v62;
  v38 = (float *)(a2 + 384);
  v39 = flt_109BE8;
  v40 = (float *)(a2 + v36);
  v41 = v62;
  v42 = (float *)(a2 + 384);
  v43 = 0;
  while ( ++v42 != v40 )
  {
    while ( 1 )
    {
      v44 = *((unsigned __int8 *)v41 + 1);
      v41 = (_DWORD *)((char *)v41 + 1);
      if ( v44 != 1 )
        break;
      v45 = *v42++;
      v39 = v39 + v45;
      ++v43;
      if ( v42 == v40 )
        goto LABEL_12;
    }
  }
LABEL_12:
  v46 = (float)v43;
  v47 = flt_109BE8;
  v48 = v39 / (float)v43;
  v49 = (float *)(v36 + a2);
  v50 = 4 * v58;
  v51 = a2 + 4 * v58;
  while ( v49 != ++v38 )
  {
    while ( 1 )
    {
      v52 = *((unsigned __int8 *)v37 + 1);
      v37 = (_DWORD *)((char *)v37 + 1);
      if ( v52 != 1 )
        break;
      v53 = *v38 - v48;
      if ( (float)sub_128280((int)v53) > *(float *)(v51 + 636) )
        *(float *)(v51 + 636) = (float)sub_128280((int)v53);
      ++v38;
      v47 = v47 + (float)(v53 * v53);
      if ( v49 == v38 )
        goto LABEL_18;
    }
  }
LABEL_18:
  v54 = a2 + v50;
  v55 = dword_109BEC;
  v56 = flt_109BF0;
  *(float *)(v54 + 512) = v18 / v46;
  *(float *)(v54 + 520) = v47 / v46;
  return sub_11F74C(1, v55, (int)(float)((float)(v18 / v46) * v56), (int)(float)((float)(v47 / v46) * v56));
}

