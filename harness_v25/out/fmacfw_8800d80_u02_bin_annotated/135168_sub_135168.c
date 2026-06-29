// fwstruct annotate: 135168_sub_135168.c
// sub_135168 @ 0x135168, size 462 bytes
void __fastcall sub_135168(
        int a1,
        char *a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13)
{
  _BYTE *v13; // r7
  int v14; // r5
  int v15; // r6
  int v16; // r11
  unsigned __int8 *v17; // r4
  int v20; // r10
  int v21; // r0
  int v22; // r1
  int v23; // r2
  int v24; // r3
  int v25; // r4
  int v26; // r5
  int v27; // r3
  _WORD *v28; // r12
  int v29; // r2
  __int16 v30; // r1
  int v31; // t1
  int v32; // lr
  __int16 v33; // r0
  int v34; // r1
  int v35; // r10
  int v36; // r11
  int v37; // r11
  _DWORD *v38; // r1
  int v39; // r5
  int v40; // r0
  unsigned int v41; // r0
  char *v42; // r1
  char *v43; // r0
  char *v44; // r2
  char v45; // t1
  unsigned int v46; // [sp+Ch] [bp-8h]

  v13 = off_135338;
  v14 = dword_13533C;
  v15 = *((_DWORD *)off_135338 + 4);
  v16 = *(unsigned __int8 *)(v15 + 61);
  v17 = (unsigned __int8 *)(dword_13533C + 1320 * v16);
  v20 = v17[116];
  feature_guard_check(256, dword_135344, dword_135340);
  if ( !v17[1224] )
  {
    v21 = v17[412];
    if ( v17[412] )
      v21 = 1;
    v25 = sub_118C44(v21, 512);
    if ( v25 )
      goto LABEL_5;
LABEL_10:
    sub_134E04(1, v22, v23, v24, a5, a6, a7, a8, a9, a10, a11, a12, a13);
    return;
  }
  v25 = sub_118C44(1, 512);
  if ( !v25 )
    goto LABEL_10;
LABEL_5:
  v26 = v14 + 1320 * v16;
  sub_12C4E8(v26, v25);
  v27 = *(_DWORD *)(v25 + 72);
  v28 = off_135360;
  v29 = dword_135348 + 696 * v20;
  v30 = *((_WORD *)off_135360 + 254);
  v31 = *(_DWORD *)(v29 + 38);
  v29 += 38;
  *(_DWORD *)(v27 + 112) = v31;
  *(_BYTE *)(v27 + 108) = -80;
  *(_WORD *)(v27 + 116) = *(_WORD *)(v29 + 4);
  *(_DWORD *)(v27 + 118) = *(_DWORD *)(v26 + 100);
  v32 = *(_DWORD *)v29;
  *(_WORD *)(v27 + 122) = *(_WORD *)(v26 + 104);
  ++v30;
  *(_WORD *)(v27 + 128) = *(_WORD *)(v29 + 4);
  *(_DWORD *)(v27 + 124) = v32;
  *(_BYTE *)(v27 + 109) = 0;
  *(_BYTE *)(v27 + 110) = 0;
  *(_BYTE *)(v27 + 111) = 0;
  v33 = 16 * v30;
  v28[254] = v30;
  LOBYTE(v30) = *(_BYTE *)(v26 + 107);
  *(_WORD *)(v27 + 130) = v33;
  *(_BYTE *)(v25 + 28) = v30;
  *(_BYTE *)(v25 + 29) = *(_BYTE *)(v26 + 116);
  *(_BYTE *)(v25 + 51) = 0;
  *(_BYTE *)(v25 + 53) = 0;
  v34 = *(unsigned __int8 *)(v15 + 59);
  v35 = v27 + 108;
  if ( v34 == 1 && a1 == 3 )
  {
    fmac_main_loop_0a0(v25, v27 + 108, 24);
    LOWORD(v34) = *(unsigned __int8 *)(v15 + 59);
    v36 = *(unsigned __int8 *)(v25 + 51) + 24;
  }
  else
  {
    v36 = 24;
  }
  v37 = v36 + sub_130804(v35 + v36, v34, a1, 0, a2);
  if ( *(_BYTE *)(v15 + 59) == 2 )
  {
    v41 = *(unsigned __int16 *)(v15 + 54);
    if ( 512 - v37 < v41 )
    {
      if ( **(__int16 **)off_135354 < 0 )
        sub_12F49C(dword_13535C, dword_135358, 1015);
    }
    else
    {
      v42 = (char *)(v15 + 64);
      if ( *(_WORD *)(v15 + 54) )
      {
        v43 = &v42[v41];
        do
        {
          v44 = v42 - 64;
          v45 = *v42++;
          v44[v35 + v37 - v15] = v45;
        }
        while ( v42 != v43 );
        v41 = *(unsigned __int16 *)(v15 + 54);
      }
      v37 += v41;
    }
  }
  v38 = *(_DWORD **)(v25 + 76);
  v39 = dword_135350;
  v40 = *(unsigned __int8 *)(v25 + 53) + v37;
  v46 = *(_DWORD *)(*(_DWORD *)off_13534C + 12);
  v38[8] = v38[7] - 1 + v40;
  v38[9] = v40 + 4;
  *(_DWORD *)(v25 + 88) = v39;
  *(_DWORD *)(v25 + 92) = v25;
  rf_param_get_status(v25, 5);
  v13[34] = 1;
  timer_set_relative(6154, 6, v46);
  sub_12CD34(6u, 5);
}

