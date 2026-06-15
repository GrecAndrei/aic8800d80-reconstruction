// v23 annotated: sub_105388 @ 0x105388
// Original: 105388_sub_105388.c
// Primary struct: <unclustered>
//
// sub_105388 @ 0x105388, size 1618 bytes
int __fastcall sub_105388(
        int a1,
        int a2,
        float *a3,
        int a4,
        unsigned __int8 a5,
        char a6,
        unsigned __int8 a7,
        int a8,
        int a9)
{
  float *v11; // r4
  int v12; // r10
  int v13; // r9
  float *v14; // r5
  float v15; // s15
  float v16; // s16
  __int64 v17; // r6
  __int64 v18; // r0
  __int64 v19; // r0
  __int64 v20; // r0
  float v21; // s17
  float *v22; // r10
  float *v23; // r9
  int v24; // r5
  float *v25; // r4
  __int64 v26; // r6
  __int64 v27; // r0
  int v28; // r0
  float v29; // s13
  int v30; // r5
  float *v31; // r2
  float *v32; // r3
  float v33; // s15
  float v34; // s10
  float v35; // s11
  float v36; // s12
  float v37; // s18
  float *v38; // r7
  float *v39; // r6
  float v40; // s15
  float v41; // s16
  float *v42; // r9
  float v43; // s19
  float v44; // s17
  __int64 v45; // r0
  float v46; // s17
  float v47; // s19
  int v48; // r5
  int v49; // r10
  int v50; // r11
  float *v51; // r7
  float v52; // s18
  float v53; // s16
  __int64 v54; // r0
  float v55; // s15
  bool v56; // zf
  float v57; // r9
  float v58; // s16
  float *v59; // r5
  int *v60; // r6
  float *v61; // r8
  int *v62; // r7
  int v63; // r9
  float v64; // s13
  float v65; // s15
  int v66; // r1
  float v67; // s14
  int v68; // s13
  int v69; // s15
  int v70; // r11
  int v71; // r7
  int v72; // r5
  int v73; // r8
  int v74; // r10
  int v75; // r9
  int v76; // r1
  int v77; // r6
  int v78; // r3
  int v79; // r4
  int v80; // r5
  int v81; // r9
  int v82; // r7
  int v83; // r6
  int v84; // r11
  int *v85; // r0
  int v86; // r12
  int v87; // t1
  int v89; // r6
  int v90; // r4
  int v91; // r5
  _DWORD *v92; // r1
  int v93; // r2
  int v94; // r6
  int v95; // r1
  int *v96; // r4
  int v97; // t1
  _DWORD *v98; // r12
  int v99; // r2
  int v100; // r0
  int *v101; // r2
  int *v102; // r0
  int v103; // r1
  int v104; // t1
  int v105; // [sp+2Ch] [bp-180h]
  int v106; // [sp+30h] [bp-17Ch]
  int v107; // [sp+30h] [bp-17Ch]
  int v108; // [sp+30h] [bp-17Ch]
  float *v109; // [sp+34h] [bp-178h]
  float *v110; // [sp+34h] [bp-178h]
  int v111; // [sp+34h] [bp-178h]
  float *v112; // [sp+38h] [bp-174h]
  int v113; // [sp+38h] [bp-174h]
  int v114; // [sp+38h] [bp-174h]
  int v115; // [sp+3Ch] [bp-170h]
  int v116; // [sp+40h] [bp-16Ch]
  int v117; // [sp+44h] [bp-168h]
  int v118; // [sp+48h] [bp-164h]
  int v120; // [sp+5Ch] [bp-150h] BYREF
  int v121; // [sp+60h] [bp-14Ch]
  int v122; // [sp+64h] [bp-148h]
  float v123[16]; // [sp+68h] [bp-144h] BYREF
  float v124[16]; // [sp+A8h] [bp-104h] BYREF
  _BYTE v125[64]; // [sp+E8h] [bp-C4h] BYREF
  int v126; // [sp+128h] [bp-84h] BYREF
  int v127; // [sp+12Ch] [bp-80h]
  int v128; // [sp+130h] [bp-7Ch]
  int v129; // [sp+134h] [bp-78h]
  int v130; // [sp+138h] [bp-74h]
  int v131; // [sp+13Ch] [bp-70h]
  int v132; // [sp+140h] [bp-6Ch]
  int v133; // [sp+144h] [bp-68h]
  int v134; // [sp+148h] [bp-64h]
  int v135; // [sp+14Ch] [bp-60h]
  int v136; // [sp+150h] [bp-5Ch]
  int v137; // [sp+154h] [bp-58h]
  int v138; // [sp+158h] [bp-54h]
  int v139; // [sp+15Ch] [bp-50h]
  int v140; // [sp+160h] [bp-4Ch]
  int v141; // [sp+164h] [bp-48h]
  _DWORD v142[8]; // [sp+168h] [bp-44h] BYREF
  int v143; // [sp+188h] [bp-24h]
  int v144; // [sp+18Ch] [bp-20h]
  int v145; // [sp+190h] [bp-1Ch]
  int v146; // [sp+194h] [bp-18h]
  int v147; // [sp+198h] [bp-14h]
  int v148; // [sp+19Ch] [bp-10h]
  int v149; // [sp+1A0h] [bp-Ch]
  int v150; // [sp+1A4h] [bp-8h]
  _BYTE v151[4]; // [sp+1A8h] [bp-4h] BYREF

  v11 = a3;
  v106 = a9 - 1;
  if ( a2 > 1 )
  {
    v12 = dword_105670;
    v13 = (int)&a3[a2 + 32];
    v14 = a3 + 33;
    do
    {
      v15 = *v14++;
      v16 = *(v14 - 2);
      if ( v15 < v16 )
      {
        v17 = sub_1429F8(LODWORD(v15));
        v18 = sub_1429F8(LODWORD(v16));
        v19 = sub_142AA8(v18, HIDWORD(v18), dword_105668, dword_10566C);
        if ( sub_142F8C(v17, HIDWORD(v17), v19, HIDWORD(v19)) )
        {
          sub_12ECD0(1, v12);
          v16 = *(v14 - 2);
        }
        *(v14 - 1) = v16;
      }
    }
    while ( (float *)v13 != v14 );
  }
  if ( a1 > 0 )
  {
    v20 = sub_1429D4(a1);
    v21 = flt_105660;
    v112 = v11;
    v22 = v124;
    v23 = (float *)v125;
    v24 = 0;
    v25 = v123;
    v26 = v20;
    do
    {
      v27 = sub_1429D4(++v24);
      v28 = sub_142CFC(v27, HIDWORD(v27), v26, HIDWORD(v26));
      *(_DWORD *)v25++ = sub_14306C(v28);
      *v22++ = 1.0;
      *v23++ = v21;
    }
    while ( v24 != a1 );
    v11 = v112;
  }
  v29 = v123[v106];
  v30 = 0;
  v113 = a2 - 1;
  v122 = a2 - 1;
  sub_1052E8(a2, v29, &v120, (int)v11, 0);
  v31 = &v11[v121];
  v32 = &v11[v120];
  v33 = *v31;
  v34 = v31[32];
  v35 = v32[32] - v34;
  v36 = *v32 - *v31;
  v124[v106] = v29;
  v37 = (float)((float)((float)(v35 / v36) * (float)(v29 - v33)) + v34) / v29;
  if ( a1 <= 0 )
  {
    if ( a1 )
    {
      sub_12ECD0(1, dword_1059E4);
      goto LABEL_44;
    }
  }
  else
  {
    v38 = v124;
    v39 = v123;
    do
    {
      if ( v30 != v106 )
      {
        v41 = v37 * *v39;
        sub_1052E8(a2, v41, &v120, (int)v11, 1);
        if ( v120 )
        {
          v42 = &v11[v120];
          if ( v113 == v121
            || (v43 = v11[v121 + 32],
                v109 = &v11[v121],
                v44 = v42[32] - v43,
                v45 = sub_1429F8(LODWORD(v44)),
                sub_142F8C(v45, HIDWORD(v45), dword_105658, dword_10565C)) )
          {
            v40 = 1.0;
          }
          else
          {
            v40 = (float)((float)((float)(*v42 - *v109) * (float)(v41 - v43)) / v44) + *v109;
          }
        }
        else
        {
          v40 = (float)(v41 * *v11) / v11[32];
        }
        *v38 = v40;
      }
      ++v30;
      ++v38;
      ++v39;
    }
    while ( a1 != v30 );
  }
  v46 = flt_105660;
  v107 = a1;
  v47 = flt_105664;
  v48 = a9 - 1;
  v49 = -1;
  v50 = a9 - 1;
  while ( 1 )
  {
    v57 = v124[v48];
    sub_1052E8(a2, v57, &v120, (int)v11, 0);
    if ( v120 )
    {
      v110 = &v11[v121];
      v51 = &v11[v120];
      if ( v113 == v121 )
      {
        v55 = v11[v113 + 96];
      }
      else
      {
        v52 = *v110;
        v53 = *v51 - *v110;
        v54 = sub_1429F8(LODWORD(v53));
        if ( !sub_142FC8(v54, HIDWORD(v54), dword_105658, dword_10565C) )
          v53 = v47;
        v55 = (float)((float)((float)(v51[96] - v110[96]) / v53) * (float)(v57 - v52)) + v110[96];
      }
    }
    else
    {
      v55 = v11[v50 + 96];
    }
    v56 = v48 == v50;
    if ( v48 != v50 )
    {
      v55 = v46 - v55;
      *(float *)&v151[4 * v48 - 192] = v55;
    }
    v48 = v49 + 1;
    if ( v56 )
      v46 = v55;
    if ( v107 <= v48 )
      break;
    ++v49;
  }
  sub_12ECD0(1, dword_105924);
  if ( v107 > 0 )
  {
    v58 = flt_105928;
    v59 = v124;
    v60 = &v126;
    v61 = (float *)v125;
    v62 = v142;
    v63 = 0;
    do
    {
      v64 = *v61++;
      v65 = *v59++;
      v66 = dword_10592C;
      v67 = v64 / v58;
      ++v63;
      v68 = vcvts_n_s32_f32(v65, 0xAu);
      v69 = vcvts_n_s32_f32(v67, 9u);
      *v60++ = v68;
      if ( v68 >= 1024 )
        *(v60 - 1) = 1023;
      *v62++ = v69;
      if ( v69 < 0 )
        *(v62 - 1) = v69 + (v69 < 0 ? 0x400 : 0);
      sub_12ECD0(1, v66);
    }
    while ( v107 != v63 );
  }
LABEL_44:
  v70 = (v129 << 10) + (v128 << 20) + v130;
  v105 = (v132 << 10) + (v131 << 20) + v133;
  v108 = (v135 << 10) + (v134 << 20) + v136;
  v111 = (v138 << 10) + (v137 << 20) + v139;
  v115 = v142[1] + 1049600 * v142[0];
  v116 = (v142[3] << 10) + (v142[2] << 20) + v142[4];
  v117 = (v142[6] << 10) + (v142[5] << 20) + v142[7];
  v114 = (v141 << 10) + (v140 << 20);
  v71 = (v144 << 10) + (v143 << 20) + v145;
  v72 = 15 - a8;
  v73 = (v147 << 10) + (v146 << 20) + v148;
  v74 = (v150 << 10) + (v149 << 20);
  v75 = v127 + (v126 << 10);
  if ( !a7 )
  {
    if ( a8 == 4 )
    {
      v72 = 1;
    }
    else if ( a8 == 7 )
    {
      v72 = 0;
    }
LABEL_48:
    v76 = dword_105934;
    v77 = 48 * v72 + 1264 * a7 + dword_105930;
    v118 = v72 + 24;
    v78 = v72;
    v79 = a4 + 96 + 48 * v72;
    v80 = v127 + (v126 << 10);
    v81 = (v144 << 10) + (v143 << 20) + v145;
    v82 = v77;
    v83 = (v129 << 10) + (v128 << 20) + v130;
    v84 = v78;
    do
    {
      sub_12ECD0(1, v76);
      *(_DWORD *)(v79 - 40) = v105;
      *(_DWORD *)(v79 - 36) = v108;
      *(_DWORD *)(v79 - 32) = v111;
      *(_DWORD *)(v79 - 28) = v114;
      *(_DWORD *)(v79 - 24) = v115;
      *(_DWORD *)(v79 - 20) = v116;
      v76 = dword_105934;
      *(_DWORD *)(v79 - 48) = v80;
      *(_DWORD *)(v79 - 44) = v83;
      *(_DWORD *)(v79 - 16) = v117;
      *(_DWORD *)(v79 - 12) = v81;
      *(_DWORD *)(v79 - 8) = v73;
      *(_DWORD *)(v79 - 4) = v74;
      v85 = (int *)(v79 - 48);
      v86 = v82;
      do
      {
        v87 = *v85++;
        *(_DWORD *)(v86 + 4) = v87;
        v86 += 4;
      }
      while ( (int *)v79 != v85 );
      v84 += 8;
      v82 += 384;
      v79 += 384;
    }
    while ( v118 != v84 );
    return sub_12ECD0(1, dword_105938);
  }
  if ( a8 == 7 )
    v72 = 5;
  if ( !a6 )
    goto LABEL_48;
  if ( a5 == 2 )
  {
    v89 = dword_1059E0;
    sub_12ECD0(1, dword_1059DC);
    v98 = (_DWORD *)(a4 + 48 * v72);
    v98[14] = v105;
    v98[15] = v108;
    v98[16] = v111;
    v98[17] = v114;
    v98[18] = v115;
    v99 = 12 * v72 + 12;
    v98[19] = v116;
    v98[12] = v75;
    v98[13] = v70;
    v98[22] = v73;
    v98[23] = v74;
    v100 = 4 * v99 - 48;
    v90 = a4 + 96;
    v98[20] = v117;
    v98[21] = v71;
    v101 = (int *)(a4 + 4 * v99);
    v102 = (int *)(v100 + a4 + 96);
    v103 = 1264 * a7 + 48 * v72 + 12 + v89;
    do
    {
      v104 = *v101++;
      *(_DWORD *)(v103 + 4) = v104;
      v103 += 4;
    }
    while ( v102 != v101 );
  }
  else
  {
    v89 = dword_10593C;
    v90 = a4 + 96;
  }
  sub_12ECD0(1, dword_105934);
  v91 = 3 * (v72 + 8 * a5);
  v92 = (_DWORD *)(a4 + 16 * v91);
  v92[14] = v105;
  v92[15] = v108;
  v92[16] = v111;
  v92[17] = v114;
  v92[18] = v115;
  v92[19] = v116;
  v93 = 4 * v91 + 12;
  v92[12] = v75;
  v92[13] = v70;
  v92[20] = v117;
  v92[21] = v71;
  v92[22] = v73;
  v92[23] = v74;
  v94 = v89 + 1264 * a7 + 16 * v91 + 12;
  v95 = v90 + 4 * v93 - 48;
  v96 = (int *)(a4 + 4 * v93);
  do
  {
    v97 = *v96++;
    *(_DWORD *)(v94 + 4) = v97;
    v94 += 4;
  }
  while ( (int *)v95 != v96 );
  return sub_12ECD0(1, dword_105938);
}

